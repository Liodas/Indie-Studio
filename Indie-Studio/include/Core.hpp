//
// client.hpp for Indie-Studio in /home/prost_m/Rendu/Semestre_4/Indie-Studio-socket/Socket-Studio/inc/
//
// Made by Matthias Prost
// Login   <matthias.prost@epitech.eu@epitech.eu>
//
// Started on  Sat May  6 13:22:30 2017 Matthias Prost
// Last update Sun May 14 19:08:50 2017 John Doe
//

#ifndef _CORE_HPP_
#define _CORE_HPP_


#include <mutex>
#include <thread>
#include <string>
#include <iostream>
#include <functional>
#include <condition_variable>

#include "sio_client.h"
#include "Application.hpp"

#ifdef WIN32
#define EM(__O__) std::cout<<__O__<<std::endl
#define HIGHLIGHT(__O__) std::cout<<__O__<<std::endl
#define HIGHLIGHT_N(__O__) std::cout<<__O__


#include <tchar.h>
#include <stdio.h>

#else
#define HIGHLIGHT_N(__O__) std::cout<<"\e[1;31m"<<__O__<<"\e[0m"
#define EM(__O__) std::cout<<"\e[1;30;1m"<<__O__<<"\e[0m"<<std::endl
#define HIGHLIGHT(__O__) std::cout<<"\e[1;31m"<<__O__<<"\e[0m"<<std::endl

class Core : public Application
{
  private:
    int                         _id;
    std::mutex                  _lock;
    std::condition_variable_any _cond;
    bool                        _connect_finish;
    sio::socket::ptr            _current_socket;
    sio::client                 _client;
    std::string                 _addr;

  public:
    Core(std::string const &addr, int const port, int const id);
    void  on_connected();
    ~Core();
    void  on_close(sio::client::close_reason const& reason);
    void  on_fail();
    void  events();
    void  connect();
    void  wait();
    void  consoleChat();

    void  emit(std::string const event, std::string const request);
    void  move(float fw, float x, float y, float z);

};

#endif

#endif /* _CORE_HPP_ */
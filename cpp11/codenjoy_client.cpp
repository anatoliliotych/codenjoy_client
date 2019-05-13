#include "lib/easywsclient/easywsclient.hpp"
//#include "easywsclient.cpp" // <-- include only if you don't want compile separately
#ifdef _WIN32
#pragma comment( lib, "ws2_32" )
#include <WinSock2.h>
#endif
#include <assert.h>
#include <stdio.h>
#include <string>
#include <memory>

std::string host = "localhost"; // specify correct host for Codenjoy server
std::string port = "8080"; // specify correct port for Codenjoy server
std::string gameurl = "/codenjoy-contest/ws?";
std::string username = "anatoliliotych"; // specify your username

// use this method to process message
std::string process_message(const std::string & message)
{
  printf(">>> %s\n", message.c_str());
  // add some logic to process message from Codenjoy server
  return "right=1";
}

int main()
{
    using easywsclient::WebSocket;
#ifdef _WIN32
    INT rc;
    WSADATA wsaData;

    rc = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (rc) {
        printf("WSAStartup Failed.\n");
        return 1;
    }
#endif
    std::unique_ptr<WebSocket> ws(WebSocket::from_url("ws://" + host + ":" + port + gameurl + "user=" + username));
    assert(ws);
    while (ws->getReadyState() != WebSocket::CLOSED) {
        WebSocket::pointer wsp = &*ws;
        ws->poll();
        ws->dispatch([wsp](const std::string & message) {
            wsp->send(process_message(message););
        });
    }
#ifdef _WIN32
    WSACleanup();
#endif
    return 0;
}

#pragma once
#pragma comment(lib, "Ws2_32.lib")
#include<WinSock2.h>
#include<iostream>
class Receiver_UDP
{
public:
	Receiver_UDP();
	~Receiver_UDP();
	char* Receive();
private:
	WSADATA m_wsa;
	SOCKET m_socket;
	struct sockaddr_in m_recv_addr;
	int m_error = 0;
	char m_broadcast = '1';
	char m_recv_buffer[50] = "";
	int m_buffer_length = 50;
};


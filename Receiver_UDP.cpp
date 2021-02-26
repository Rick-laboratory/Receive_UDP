#include "Receiver_UDP.h"
#define PORT 9009
Receiver_UDP::Receiver_UDP()
{
	m_error = WSAStartup(MAKEWORD(2, 2), &m_wsa);
	if (m_error != 0) {
		std::cout << "WSAStartup failed with error: " << m_error << "\n";
	}

	m_socket = socket(AF_INET, SOCK_DGRAM, 0);

	if (setsockopt(m_socket,
		SOL_SOCKET,
		SO_BROADCAST, &m_broadcast, sizeof(m_broadcast)) < 0) {
		std::cout << "Error in setting m_broadcast option\n";
		closesocket(m_socket);
	}

	m_recv_addr.sin_family = AF_INET;
	m_recv_addr.sin_port = htons(PORT);
	m_recv_addr.sin_addr.s_addr = INADDR_ANY;

	if (bind(m_socket,
		(sockaddr*)&m_recv_addr, sizeof(m_recv_addr)) < 0) {
		std::cout << "Error in binding" << WSAGetLastError();
		system("PAUSE");
		closesocket(m_socket);
	}
}

Receiver_UDP::~Receiver_UDP()
{
	closesocket(m_socket);
	WSACleanup();
}

char* Receiver_UDP::Receive()
{
	recv(m_socket, m_recv_buffer, m_buffer_length, 0);
	return m_recv_buffer;
}



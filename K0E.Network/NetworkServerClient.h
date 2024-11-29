#pragma once
#include "Macro.h"

struct NetworkServerClient
{
	string name;
	sf::IpAddress Ip;
	sf::UdpSocket* dataSocket;
	unsigned short port;
	sf::Packet rDataPacket;
	sf::Packet sDataPacket;
	bool done = true;

	sf::Vector2f pos{ 0,0 };
	size_t Scale = 2;

	NetworkServerClient(void);
	~NetworkServerClient(void);
};
#pragma once
#include "Macro.h"
#include "NetworkServer.h"
#include "NetworkClient.h"

class K0E_Network_Api Network
{
private:
	string Version = "";                                 // Game version
	sf::IpAddress ip = sf::IpAddress::getLocalAddress(); // Local IP

	NetworkServer Server;
	NetworkClient Client;

public:
	Network(string Version);
	void New(char Type, sf::Packet& packet);

	char Type = ' ';  // Server or Client ?
	void ServerUpdate(sf::Packet& packet);
	void ClientUpdate();
};
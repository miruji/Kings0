#include "Network.h"

Network::Network(string Version)
{
	this->Version = Version;
}

void Network::New(char Type, sf::Packet& packet)
{
	cout << "Network type: [" << Type << "]" << endl;
	if (tolower(Type) == 's')
	{
		Server.init();

		packet << "DATA";
		for (int i = 0; i < Server.clientsVec.size(); i++)
		{
			packet << Server.clientsVec[i].name << Server.clientsVec[i].pos.x << Server.clientsVec[i].pos.y << Server.clientsVec[i].Scale;
		}

		this->Type = tolower(Type);
	}
	else
	if (tolower(Type) == 'c')
	{
		this->Type = tolower(Type);
	}
}

void Network::ServerUpdate(sf::Packet& packet)
{
	if (Type == 's')
	{
	//
	Server.registerNewClients();
	Server.sendConnectedClientsRecords();

	if (Server.sendDataToAll(packet) == sf::Socket::Status::Done)
	{
		packet.clear();
		packet << "DATA";
		for (int i = 0; i < Server.clientsVec.size(); i++)
		{
			packet << Server.clientsVec[i].name << Server.clientsVec[i].pos.x << Server.clientsVec[i].pos.y << Server.clientsVec[i].Scale;
		}
	}

	unsigned int receivedClientIndex;
	if (Server.receiveData(receivedClientIndex) == sf::Socket::Status::Done)
	if (Server.clientsVec[receivedClientIndex].rDataPacket.getDataSize() > 0)
	{
		string s;
		if (Server.clientsVec[receivedClientIndex].rDataPacket >> s)
		{
			if (s == "DATA")
			{
				float x, y;
				size_t Scale;
				if (Server.clientsVec[receivedClientIndex].rDataPacket >> x)
				{
					Server.clientsVec[receivedClientIndex].pos.x = x;
				}
				if (Server.clientsVec[receivedClientIndex].rDataPacket >> y)
				{
					Server.clientsVec[receivedClientIndex].pos.y = y;
				}
				if (Server.clientsVec[receivedClientIndex].rDataPacket >> Scale)
				{
					Server.clientsVec[receivedClientIndex].Scale = Scale;
				}
				Server.clientsVec[receivedClientIndex].rDataPacket.clear();
			}
		}
	}
	//
	}
}

void Network::ClientUpdate()
{
	if (Type == 'c')
	{
	//

	//
	}
}
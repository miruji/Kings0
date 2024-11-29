#include "NetworkServer.h"

NetworkServer::NetworkServer(void)
{
	//listener.setBlocking(true);
}
NetworkServer::~NetworkServer(void)
{}

sf::Socket::Status NetworkServer::init()
{
	if (listener.listen(sf::Socket::AnyPort) == sf::Socket::Status::Done)
	{
		cout << "Port -" << listener.getLocalPort() << endl;
		return sf::Socket::Status();
	}
	else return sf::Socket::Status::Error;
}

sf::Socket::Status NetworkServer::registerNewClients()
{
	acceptIncomingConnection();
	receiveClientRegData();
	sendNewClientDataToAll();
	sendDedicatedDataPort();
	if (regStep == 5) { regStep = 0; return sf::Socket::Status::Done; }
	else return sf::Socket::Status::NotReady;
}

sf::Socket::Status NetworkServer::acceptIncomingConnection()
{
	if (regStep == 0)
	{
		if (listener.isBlocking()) listener.setBlocking(false);
		
		
		//cout << "Port -" << listener.getLocalPort() << endl;
		if (listener.accept(regSocket) == sf::Socket::Status::Done)
		{
			cout << "acceptIncomingConnection(): Accepted new connection\n";
			regStep = 1;
			return sf::Socket::Status::Done;
		}
		else return sf::Socket::Status::NotReady;

		return sf::Socket::Status::NotReady;
	}
}

sf::Socket::Status NetworkServer::receiveClientRegData()
{
	if (regStep == 1)
	{
		if (regSocket.isBlocking()) regSocket.setBlocking(false);

		if (regSocket.receive(packet) == sf::Socket::Status::Done)
		{
			if (packet.getDataSize() > 0)
			{
				string name;
				if (packet >> name)
				{
					NetworkServerClient newClient;
					clientsVec.push_back(newClient);
					clientsVec.back().name = name;
					clientsVec.back().Ip = regSocket.getRemoteAddress();
					clientsVec.back().dataSocket = new sf::UdpSocket;
					if (clientsVec.back().dataSocket->bind(sf::Socket::AnyPort) != sf::Socket::Status::Done)
						cout << "(!)receiveClientRegData(): Failed to bind port to the new client-dedicated data port\n";
				}
				else
				{
					cout << "(!)receiveClientRegData(): Failed to read client name from received packet\n";
					return sf::Socket::Status::Error;
				}

				sf::Uint16 port;
				if (packet >> port)
				{
					clientsVec.back().port = static_cast<unsigned short>(port);
				}
				else
				{
					cout << "(!)receiveClientRegData(): Failed to read client data sf::Socket port from received packet\n";
					return sf::Socket::Status::Error;
				}

				if (!packet.endOfPacket())
					cout << "(!)receiveClientRegData(): Client registration data received, but something left, data probably corrupted\n";
			}
			else
			{
				cout << "(!)receiveClientRegData(): Error, received packet is empty\n";
				return sf::Socket::Status::Error;
			}

			cout << "receiveClientRegData(): Client registration data received. New client: " << clientsVec.back().name << endl;
			regStep = 2;
			for (int i = 0; i < clientsVec.size() - 1; i++)
				clientsVec[i].done = false;
			packet.clear();
			return sf::Socket::Status::Done;
		}
		else return sf::Socket::Status::NotReady;
	}
}

sf::Socket::Status NetworkServer::sendNewClientDataToAll()
{
	if (regStep == 2)
	{
		if (clientsVec.size() > 1)
		{
			for (int i = 0; i < clientsVec.size() - 1; i++)
			{
				if (!clientsVec[i].done)
				{
					if (clientsVec[i].dataSocket->isBlocking()) clientsVec[i].dataSocket->setBlocking(false);
					sf::IpAddress tempIp = clientsVec[i].Ip;
					unsigned short tempPort = clientsVec[i].port;

					if (clientsVec[i].sDataPacket.getDataSize() == 0)
						clientsVec[i].sDataPacket << "NEW" << clientsVec.back().name;

					if (clientsVec[i].dataSocket->send(clientsVec[i].sDataPacket, tempIp, tempPort) == sf::Socket::Status::Done)
					{
						clientsVec[i].done = true;

						bool allIsDone = true;
						for (int k = 0; k < clientsVec.size() - 1; k++)
						{
							if (!clientsVec[k].done) allIsDone = false;
						}
						if (allIsDone)
						{
							for (int j = 0; j < clientsVec.size(); j++)
							{
								clientsVec[j].sDataPacket.clear();
								clientsVec[j].done = false;
							}
							regStep = 3;
							return sf::Socket::Status::Done;
						}
					}
				}
			}
			return sf::Socket::Status::NotReady;
		}
		else
		{
			regStep = 3;
			return sf::Socket::Status::Done;
		}
	}
}

sf::Socket::Status NetworkServer::sendDedicatedDataPort()
{
	if (regStep == 3)
	{
		if (regSocket.isBlocking()) regSocket.setBlocking(false);

		if (packet.getDataSize() == 0)
			packet << static_cast<sf::Uint16>(clientsVec.back().dataSocket->getLocalPort());

		if (regSocket.send(packet) == sf::Socket::Status::Done)
		{
			cout << "sendDedicatedDataPort(): Dedicated data port sent\n";
			regStep = 4;
			packet.clear();
			return sf::Socket::Status::Done;
		}
		else return sf::Socket::Status::NotReady;
	}
}

sf::Socket::Status NetworkServer::sendConnectedClientsRecords()
{
	if (regStep == 4)
	{
		if (regSocket.isBlocking()) regSocket.setBlocking(false);

		if (packet.getDataSize() == 0)
		{
			if (clientsVec.size() > 1)
			{
				for (int i = 0; i < clientsVec.size() - 1; i++)
					packet << clientsVec[i].name;
			}
			else packet << "FIRST";
		}

		if (regSocket.send(packet) == sf::Socket::Status::Done)
		{
			cout << "sendConnectedClientsRecords(): Connected clients records sent to new client\n";
			regStep = 5;
			regSocket.disconnect();
			return sf::Socket::Status::Done;
		}
		else return sf::Socket::Status::NotReady;
	}
}

sf::Socket::Status NetworkServer::receiveData(unsigned int& receivedClientIndex)
{
	for (int i = 0; i < clientsVec.size(); i++)
	{
		if (clientsVec[i].dataSocket->isBlocking()) clientsVec[i].dataSocket->setBlocking(false);
		sf::IpAddress tempIp = clientsVec[i].Ip;
		unsigned short tempPort = clientsVec[i].port;

		if (clientsVec[i].dataSocket->receive(clientsVec[i].rDataPacket, tempIp, tempPort) == sf::Socket::Status::Done)
		{
			receivedClientIndex = i;
			
			return sf::Socket::Status::Done;
		}
	}

	return sf::Socket::Status::NotReady;
}

sf::Socket::Status NetworkServer::sendDataToAll(sf::Packet dataPacket)
{
	if (sendingsRateTimer.getElapsedTime().asMilliseconds() > sendingsRate)
	{
		for (int i = 0; i < clientsVec.size(); i++)
		{
			if (!clientsVec[i].done)
			{
				if (clientsVec[i].dataSocket->isBlocking()) clientsVec[i].dataSocket->setBlocking(false);
				sf::IpAddress tempIp = clientsVec[i].Ip;
				unsigned short tempPort = clientsVec[i].port;

				if (clientsVec[i].sDataPacket.getDataSize() == 0) clientsVec[i].sDataPacket = dataPacket;

				if (clientsVec[i].dataSocket->send(clientsVec[i].sDataPacket, tempIp, tempPort) == sf::Socket::Status::Done)
				{
					clientsVec[i].done = true;
				}

				bool allIsDone = true;

				for (int j = 0; j < clientsVec.size(); j++)
				{
					if (clientsVec[j].done == false) allIsDone = false;
				}

				if (allIsDone)
				{
					for (int j = 0; j < clientsVec.size(); j++)
					{
						clientsVec[j].sDataPacket.clear();
						clientsVec[j].done = false;
					}
					sendingsRateTimer.restart();
					return sf::Socket::Status::Done;
				}
			}

		}
		return sf::Socket::Status::NotReady;

	}
	else return sf::Socket::Status::NotReady;
}
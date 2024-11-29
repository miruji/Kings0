#include "Unit.h"

bool Unit::SearchBackYourDomain(DomainMap* DomainMap1, MapBlock NextBlock)
{
	//
	size_t BasicTeam = Team + 2;
	if (DomainMap1->GetTeamMap()[NextBlock.Y/32-1][NextBlock.X/32-1] == BasicTeam ||
		DomainMap1->GetTeamMap()[NextBlock.Y/32-1][NextBlock.X/32] == BasicTeam ||
		DomainMap1->GetTeamMap()[NextBlock.Y/32-1][NextBlock.X/32+1] == BasicTeam ||
		DomainMap1->GetTeamMap()[NextBlock.Y/32][NextBlock.X/32-1] == BasicTeam ||
		DomainMap1->GetTeamMap()[NextBlock.Y/32][NextBlock.X/32+1] == BasicTeam ||
		DomainMap1->GetTeamMap()[NextBlock.Y/32+1][NextBlock.X/32-1] == BasicTeam ||
		DomainMap1->GetTeamMap()[NextBlock.Y/32+1][NextBlock.X/32] == BasicTeam ||
		DomainMap1->GetTeamMap()[NextBlock.Y/32+1][NextBlock.X/32+1] == BasicTeam)
		return true;
	else
		return false;
}

// Game: Search next block enemy 
bool Unit::SearchNextBlockEnemy(MapBlock NextBlock, DomainMap* DomainMap1, vector< int >& Status)
{
	//
	size_t Team = DomainMap1->GetTeamMap()[NextBlock.Y/32][NextBlock.X/32];
	//
	if (Team == this->Team+2 || Team == 0)
		return true;

	if (Status[Team-2] == 0 ||
		Status[Team-2] == 2)
		return true;
	else
		return false;
}

// Consturctor 
Unit::Unit(string Name, vector<Character*>& Characters)
{
	// Load image to sprite 
	BracketTexture.loadFromFile("Data\\Textures\\Game\\Bracket1.png");
	BasicTexture.loadFromFile("Data\\Textures\\Game\\Unit.png");

	// Load shadow texture 
	ShadowTexture.loadFromFile("Data\\Textures\\Game\\Shadow.png");
	// Load team shadow texture 
	TeamShadowTexture.loadFromFile("Data\\Textures\\Game\\TeamShadow.png");

	// Set font and player name
	Font.loadFromFile("Data\\Fonts\\Font.ttf");
	this->Name = Name;
}

// Update sprite 
void Unit::UpdateSprite(sf::IntRect Rect)
{
	//
	Sprite.setTextureRect( Rect );
}

// Set position 
void Unit::SetPosition(float X, float Y)
{
	// Set X & Y
	this->X = X; this->Y = Y;
}

// New domain 
void Unit::NewDomain(DomainMap* DomainMap1, /*vector<PreviewMap*>& PreviewMaps,*/ int& DiploPoints)
{
	//
	if (DiploPoints-5 < 0)
		return;

	if (DomainMap1->SearchTeamDomain(X, Y, Team)) //  nearby with player
	{
		//
		if (DomainMap1->GetTeamMap()[Y/32][X/32] == 0)
		{
			/*
			for (size_t i = 0; i < PreviewMaps.size(); i++)
			{
				if (PreviewMaps[i] != NULL)
					PreviewMaps[i]->GetTeamMap()[Y/32][X/32] = 0;
			}
			*/
			//
			DomainMap1->GetTeamMap()[Y/32][X/32] = Team+2;
		}
		//
		else
		{
			// TO:DO! ->> ухудшить отношения между двумя фракциями
		}
		//
		DiploPoints -= 5;
	}
}

// Set X & Y
void Unit::Move(float X, float Y, vector< vector<MapBlock> >& BlocksVector, vector< Settlement >& Settlements, DomainMap* DomainMap1, /*PreviewMap* PreviewMap1,*/ vector< Technology > Technologys, vector< int >& Status)
{
	//
	MapBlock NextBlock = BlocksVector[(this->Y+Y)/32][(this->X+X)/32];

	//if (PreviewMap1->GetTeamMap()[NextBlock.Y/32][NextBlock.X/32])
	if (NextBlock.Land || (!NextBlock.Land && (NextBlock.River || NextBlock.Lake)))
		{	}
	else
	{
		if (GetRandomNumber(0, 4))
			return;
	}

	if ((NextBlock.River || NextBlock.Lake) && GetRandomNumber(0, 4) == 0)
		return;

	if (NextBlock.Mountain && GetRandomNumber(0, 2) == 0)
		return;

	if (SearchBackYourDomain(DomainMap1, NextBlock))
	if (SearchNextBlockEnemy(NextBlock, DomainMap1, Status))
	if ((Technologys[1].Opened || NextBlock.Mountain == false) && ((Technologys[3].Opened && NextBlock.River == true) || (Technologys[2].Opened && Technologys[3].Opened) || (NextBlock.River == false && NextBlock.Land == true)) && (Technologys[0].Opened || NextBlock.Forest == false))
	{
		// to 
		this->X = this->X + X;
		this->Y = this->Y + Y;
		BlocksVector[(this->Y-Y)/32][(this->X-X)/32].Enemy = 0;
		BlocksVector[(this->Y)/32][(this->X)/32].Enemy = Team;
	}
}

// Progress 
void Unit::Progress(LandMap* LandMap1, vector< Settlement >& Settlements, CasteNation Nation, DomainMap* DomainMap1, /*PreviewMap* PreviewMap1, vector<PreviewMap*>& PreviewMaps,*/ vector< Technology > Technologys, vector< int >& Status, int& MovePoints, int& Wood, int& DiploPoints, int& Population, int& Food, int& Army, int& Cash, size_t& ResourcesLimit)
{
	//
	//cout << "Movement points: " << MovePoints << endl;
	while (MovePoints > 0)
	{
		//cout << "  > MovePoints: " << MovePoints;
		size_t R1 = GetRandomNumber(0, 5);
		if (R1 == 0 && GetRandomNumber(0, 1))
			R1 = GetRandomNumber(1, 5);
		if (R1 == 3 && GetRandomNumber(0, 4))
		{
			while (true)
			{
				R1 = GetRandomNumber(1, 5);
				if (R1 != 3)
					break;
			}
		}
		if (R1 != 4 && GetRandomNumber(0, 4) == 4)
			R1 = 4;

		//cout << "	" << R1 << endl;
		// Wait
		if (R1 == 0)
		{
			//cout << " : Wait" << endl;
		}
		// Walk
		else
		if (R1 == 1)
		{
			//cout << " : Walk" << endl;
			size_t R2 = GetRandomNumber(0, 3);
			//cout << "X: " << X << ", Y: " << Y << ", StartX: " << StartX << ", StartY: " << StartY << endl;
			if (R2 == 0)
				Move(0, -32, LandMap1->BlocksVector, Settlements, DomainMap1, /*PreviewMap1,*/ Technologys, Status);
			else
			if (R2 == 1)
				Move(0, 32, LandMap1->BlocksVector, Settlements, DomainMap1, /*PreviewMap1,*/ Technologys, Status);
			else
			if (R2 == 2)
				Move(-32, 0, LandMap1->BlocksVector, Settlements, DomainMap1, /*PreviewMap1,*/ Technologys, Status);
			else
			if (R2 == 3)
				Move(32, 0, LandMap1->BlocksVector, Settlements, DomainMap1, /*PreviewMap1,*/ Technologys, Status);
			else
			{
				//cout << "  > repeat;" << endl;
				Progress(LandMap1, Settlements, Nation,  DomainMap1, /*PreviewMap1, PreviewMaps,*/ Technologys, Status, MovePoints, Wood, DiploPoints, Population, Food, Army, Cash, ResourcesLimit);
			}
		}
		// Cut
		else
		if (R1 == 2)
		{
			//cout << " : Cut" << endl;
			if (LandMap1->BlocksVector[Y/32][X/32].Forest)
			if (!LandMap1->BlocksVector[Y/32][X/32].Settlement || (LandMap1->BlocksVector[Y/32][X/32].Settlement && GetRandomNumber(0, 1)))
			{
				//
				if (MovePoints-1 >= 0)
				{
					//
					MapBlock& MapBlock1 = LandMap1->BlocksVector[Y/32][X/32];
					if (MapBlock1.Wood > 0)
					{
						if (MovePoints > 0)
						{
							MovePoints--;

							LandMap1->ForestSize--;
							MapBlock1.Wood--;

							Wood++;
						}
					}
					// For block delete 
					if (MapBlock1.Wood == 0)
					{
						MapBlock1.Forest = false;
						MapBlock1.RectAddY = 0;
						MapBlock1.Update();
					}
				}
				else
				{
					//cout << "  > repeat;" << endl;
					Progress(LandMap1, Settlements, Nation, DomainMap1, /*PreviewMap1, PreviewMaps,*/ Technologys, Status, MovePoints, Wood, DiploPoints, Population, Food, Army, Cash, ResourcesLimit);
				}
			}
			else
			{
				//cout << "  > repeat;" << endl;
				Progress(LandMap1, Settlements, Nation, DomainMap1, /*PreviewMap1, PreviewMaps,*/ Technologys, Status, MovePoints, Wood, DiploPoints, Population, Food, Army, Cash, ResourcesLimit);
			}
		}
		// Build
		else
		if (R1 == 3)
		{
			//cout << " : Build" << endl;
			size_t R3 = GetRandomNumber(0, 7);
			if (GetRandomNumber(0, 4))
				Progress(LandMap1, Settlements, Nation, DomainMap1, /*PreviewMap1, PreviewMaps,*/ Technologys, Status, MovePoints, Wood, DiploPoints, Population, Food, Army, Cash, ResourcesLimit);
			else
			if (R3 != 0)
			{
			if (!LandMap1->BlocksVector[Y/32][X/32].Settlement && DomainMap1->GetTeamMap()[Y/32][X/32] == Team+2 && GetRandomNumber(0, 7) != 0)
			{
				size_t R2 = 0;
				size_t repeat_error = 0;
				string build_type = "";

				while (R2 == 0)
				{
					if (!LandMap1->BlocksVector[Y/32][X/32].Land && !LandMap1->BlocksVector[Y/32][X/32].River && GetRandomNumber(0, 1))
						R2 = 7;
					else
					if (LandMap1->BlocksVector[Y/32][X/32].Forest && GetRandomNumber(0, 1))
						R2 = 9;
					else
						R2 = GetRandomNumber(1, 9);

					if ((R2 == 2 || R2 == 3 || R2 == 4) && GetRandomNumber(0, 5))
					{
						while (true)
						{
							R2 = GetRandomNumber(1, 9);
							if (R2 != 2 && R2 != 3 && R2 != 4)
								break;
						}
					}
					//
					if (repeat_error >= 5)
					{
						repeat_error = 6;
						break;
					}
					//
					if (R2 == 1)
					{
						// Barn
						size_t Middle = (ResourcesLimit*75)/100;
						if (Cash >= Middle || Food >= Middle || Wood >= Middle)
						{
							if (LandMap1->BlocksVector[Y/32][X/32].Land || LandMap1->BlocksVector[Y/32][X/32].River)
							{
								if (Food-10 < 0 || Wood-10 < 0 || Population-5 < 0)
									R2 = 0;
								else
								{
									Food -= 10;
									Wood -= 10;
									Population -= 5;
									R2 = 0;
									build_type = "Barn";
								}
							}
							else
								R2 = 0;
						}
						else
							R2 = 0;
					}
					else
					if (R2 == 2)
					{
						// Wall
						if (ArmyBuildLimit <= 5)
						if (LandMap1->BlocksVector[Y/32][X/32].Land || LandMap1->BlocksVector[Y/32][X/32].River)
						{
							if (Food-20 < 0 || Wood-20 < 0)
								R2 = 0;
							else
							{
								//Food -= 20;
								//Wood -= 20;
								R2 = 0;
								build_type = "";

								ArmyBuildLimit++;
							}
						}
						else
							R2 = 0;
					}
					else
					if (R2 == 3)
					{
						// Tower
						if (ArmyBuildLimit <= 5)
						if (LandMap1->BlocksVector[Y/32][X/32].Land || LandMap1->BlocksVector[Y/32][X/32].River)
						{
							if (Food-20 < 0 || Wood-20 < 0 || Population-15 < 0)
								R2 = 0;
							else
							{
								Food -= 20;
								Wood -= 20;
								Population -= 15;
								build_type = "Tower";

								ArmyBuildLimit++;
							}
						}
						else
							R2 = 0;
					}
					else
					if (R2 == 4)
					{
						// Castle
						if (ArmyBuildLimit <= 5)
						if (LandMap1->BlocksVector[Y/32][X/32].Land || LandMap1->BlocksVector[Y/32][X/32].River)
						{
							if (Food-20 < 0 || Wood-20 < 0 || Population-25 < 0)
								R2 = 0;
							else
							{
								Food -= 20;
								Wood -= 20;
								Population -= 25;
								build_type = "Castle";

								ArmyBuildLimit++;
							}
						}
						else
							R2 = 0;
					}
					else
					if (R2 == 5)
					{
						// Field
						if (LandMap1->BlocksVector[Y/32][X/32].Land || LandMap1->BlocksVector[Y/32][X/32].River)
						{
							if (Nation == CasteNation::Sedentary || (Nation != CasteNation::Sedentary && GetRandomNumber(0, 7) == 0))
							{
								if (Food-10 < 0 || Wood-10 < 0 || Population-5 < 0)
									R2 = 0;
								else
								{
									Food -= 10;
									Wood -= 10;
									Population -= 5;
									build_type = "Field";
								}
							}
							else
								R2 = 0;
						}
						else
							R2 = 0;
					}
					else
					if (R2 == 6)
					{
						// Pasture
						if (LandMap1->BlocksVector[Y/32][X/32].Land || LandMap1->BlocksVector[Y/32][X/32].River)
						{
							if (Nation == CasteNation::Steppe || (Nation != CasteNation::Steppe && GetRandomNumber(0, 7) == 0))
							{
								if (Food-10 < 0 || Wood-10 < 0 || Population-5 < 0)
									R2 = 0;
								else
								{
									Food -= 10;
									Wood -= 10;
									Population -= 5;
									build_type = "Pasture";
								}
							}
							else
								R2 = 0;
						}
						else
							R2 = 0;
					}
					else
					if (R2 == 7)
					{
						// Fisheries
						if (!LandMap1->BlocksVector[Y/32][X/32].Land && !LandMap1->BlocksVector[Y/32][X/32].River)
						{
							if (Nation == CasteNation::Water || (Nation != CasteNation::Water && GetRandomNumber(0, 7) == 0))
							{
								if (Food-10 < 0 || Wood-10 < 0 || Population-5 < 0)
									R2 = 0;
								else
								{
									Food -= 10;
									Wood -= 10;
									Population -= 5;
									build_type = "Fisheries";
								}
							}
							else
								R2 = 0;
						}
						else
							R2 = 0;
					}
					else
					if (R2 == 8)
					{
						// Saburb
						if (LandMap1->BlocksVector[Y/32][X/32].Land || LandMap1->BlocksVector[Y/32][X/32].River)
						{
							if (Food-10 < 0 || Wood-10 < 0 || Population-5 < 0)
								R2 = 0;
							else
							{
								Food -= 10;
								Wood -= 10;
								Population -= 5;
								build_type = "Suburb";
							}
						}
						else
							R2 = 0;
					}
					else
					if (R2 == 9)
					{
						// Sawmill
						if ((LandMap1->BlocksVector[Y/32][X/32].Land || LandMap1->BlocksVector[Y/32][X/32].River) && LandMap1->BlocksVector[Y/32][X/32].Forest)
						{
							if (Food-10 < 0 || Wood-10 < 0 || Population-5 < 0)
								R2 = 0;
							else
							{
								Food -= 10;
								Wood -= 10;
								Population -= 5;
								build_type = "Sawmill";

								// Forest = Forest * 6 
								LandMap1->BlocksVector[size_t(Y/32)][size_t(X/32)].Wood = LandMap1->BlocksVector[size_t(Y/32)][size_t(X/32)].Wood*6;
							}
						}
						else
							R2 = 0;
					}
					else
						R2 = 0;
					if (R2 == 0)
					{
						build_type = "";
						repeat_error++;
					}
					//
					if (build_type != "")
					{
						LandMap1->BlocksVector[Y/32][X/32].Settlement = Settlements.size();
						Settlements.push_back(Settlement("", build_type, 1, Team, X, Y));
					}
				}
				if (repeat_error == 6)
				{
					//cout << "  > repeat;" << endl;
					Progress(LandMap1, Settlements, Nation, DomainMap1, /*PreviewMap1, PreviewMaps,*/ Technologys, Status, MovePoints, Wood, DiploPoints, Population, Food, Army, Cash, ResourcesLimit);
				}
			}
			else
			{
				//cout << "  > repeat;" << endl;
				Progress(LandMap1, Settlements, Nation, DomainMap1, /*PreviewMap1, PreviewMaps,*/ Technologys, Status, MovePoints, Wood, DiploPoints, Population, Food, Army, Cash, ResourcesLimit);
			}
			//
			}
			else
			{
			if (!LandMap1->BlocksVector[Y/32][X/32].Settlement && DomainMap1->GetTeamMap()[Y/32][X/32] == Team+2)
			{
				if (MovePoints-1 >= 0)
				{
					/*
					// Remove build
					SettlementTypes SettlementType = Settlements[LandMap1->BlocksVector[Y/32][X/32].Settlement].GetType();
					if (SettlementType != SettlementTypes::Settlement)
					{
						if (SettlementType == SettlementTypes::Wall)
						{
							Wood += 20;
							Food += 20;
						}
						else
						if (SettlementType == SettlementTypes::Tower)
						{
							Wood += 20;
							Army += Settlements[LandMap1->BlocksVector[Y/32][X/32].Settlement].Army;
							Food += 20;
						}
						else
						if (SettlementType == SettlementTypes::Castle)
						{
							Wood += 20;
							Army += Settlements[LandMap1->BlocksVector[Y/32][X/32].Settlement].Army;
							Food += 20;
						}
						else
						if (SettlementType == SettlementTypes::Barn ||
							SettlementType == SettlementTypes::Field ||
							SettlementType == SettlementTypes::Pasture ||
							SettlementType == SettlementTypes::Fisheries ||
							SettlementType == SettlementTypes::Suburb)
						{
							Wood += 10;
							Population += 5;
							Food += 10;
						}

						Settlements.erase(Settlements.begin()+ LandMap1->BlocksVector[Y/32][X/32].Settlement);
						LandMap1->BlocksVector[Y/32][X/32].Settlement = 0;
					}
					else
					*/
						Progress(LandMap1, Settlements, Nation, DomainMap1, /*PreviewMap1, PreviewMaps, */ Technologys, Status, MovePoints, Wood, DiploPoints, Population, Food, Army, Cash, ResourcesLimit);
				}
			}
			}
		}
		// Buy
		else
		if (R1 == 4)
		{
			//cout << " : Buy" << endl;
			if (LandMap1->BlocksVector[Y/32][X/32].Settlement && DomainMap1->GetTeamMap()[Y/32][X/32] == Team+2)
			{
				//
				Settlement& Settlement1 = Settlements[LandMap1->BlocksVector[Y/32][X/32].Settlement-1];
				if (Settlement1.GetType() == SettlementTypes::Settlement ||
					Settlement1.GetType() == SettlementTypes::Tower || 
					Settlement1.GetType() == SettlementTypes::Castle)
				{
					//
					size_t R2 = GetRandomNumber(0, 1);
					size_t R3 = 0;

					size_t repeat_error = 0;

					while (true)
					{
						if (repeat_error >= 10)
							break;

						if (Settlement1.GetType() == SettlementTypes::Castle ||
							Settlement1.GetType() == SettlementTypes::Tower ||
							Settlement1.GetType() == SettlementTypes::Wall ||
							Settlement1.GetType() == SettlementTypes::Settlement)
							{	}
						else
							break;

						if (Settlement1.GetItems().size() != 0 && Settlement1.GetItems().size()-2 != 0)
							R3 = GetRandomNumber(0, Settlement1.GetItems().size()-2);
						else
							break;

						if (R3 >= Settlement1.GetItems().size())
							break;

						// Buy
						if (R2)
						{
							size_t Cost = Settlement1.GetItems()[R3]->GetCash();
							size_t Size = Settlement1.GetItems()[R3]->GetSize();
							if(int(Cash-(Cost*Size)) >= 0)
							{
								ItemType Type = Settlement1.GetItems()[R3]->GetType();
								if ((Settlement1.GetType() == SettlementTypes::Castle || Settlement1.GetType() == SettlementTypes::Tower || Settlement1.GetType() == SettlementTypes::Wall) &&
									Type == ItemType::Army && GetRandomNumber(0, 5) == 0)
								{
									if (Population -= Settlement1.GetItems()[R3]->GetSize() >= 0)
									{
										Army += Size;
										Population -= Size;

										Cash -= Cost*Size;
										break;
									}
									else
										repeat_error++;
								}
								else
								if (Settlement1.GetType() == SettlementTypes::Settlement)
								{
									if (Type == ItemType::Food && GetRandomNumber(0, 5) == 0)
										Food += Size;
									else
									if (Type == ItemType::Wood)
										Wood += Size*2;

									Cash -= Cost*Size;
									break;
								}
								else
									repeat_error++;
								//
							}
							else
								repeat_error++;
						}
						// Sell
						else
						{
							ItemType Type = Settlement1.GetItems()[R3]->GetType();
							size_t Size = Settlement1.GetItems()[R3]->GetSize();
							if (Settlement1.GetType() == SettlementTypes::Settlement)
							{
								if (Type == ItemType::Wood && int(Wood-Size) >= 0)
									Wood -= Size;
								else
								if (Type == ItemType::Food && int(Food-Size) >= 0)
									Food -= Size;
								//
								Cash += Size * Settlement1.GetItems()[R3]->GetCash()*2;
								break;
							}
							else
							if ((Settlement1.GetType() == SettlementTypes::Castle || Settlement1.GetType() == SettlementTypes::Tower || Settlement1.GetType() == SettlementTypes::Wall) &&
								Type == ItemType::Army && int(Army-Size) >= 0)
							{
								Army -= Size;
								Population += Size;
								//
								Cash += Size * Settlement1.GetItems()[R3]->GetCash();
								break;
							}
							else
								repeat_error++;
						}
					}
				}
				else
				{
					//cout << "  > repeat;" << endl;
					Progress(LandMap1, Settlements, Nation, DomainMap1, /*PreviewMap1, PreviewMaps, */ Technologys, Status, MovePoints, Wood, DiploPoints, Population, Food, Army, Cash, ResourcesLimit);
				}
			}
			else
			{
				//cout << "  > repeat;" << endl;
				Progress(LandMap1, Settlements, Nation, DomainMap1, /*PreviewMap1, PreviewMaps, */ Technologys, Status, MovePoints, Wood, DiploPoints, Population, Food, Army, Cash, ResourcesLimit);
			}
		}
		// Domain
		else
		if (R1 == 5)
		{
			//cout << " : Domain" << endl;
			if (DomainMap1->GetTeamMap()[Y/32][X/32] != Team+2)
			{
				//cout << "Map: " << DomainMap1->GetTeamMap()[Y/32][X/32] << ", Team: " << (Team+2) << endl;
				NewDomain(DomainMap1, /*PreviewMaps,*/ DiploPoints);
			}
			else
			{
				//cout << "  > repeat;" << endl;
				Progress(LandMap1, Settlements, Nation, DomainMap1, /*PreviewMap1, PreviewMaps,*/ Technologys, Status, MovePoints, Wood, DiploPoints, Population, Food, Army, Cash, ResourcesLimit);
			}
		}
		//
		if (GetRandomNumber(0,1))
			MovePoints--;
		MovePoints--;
	}
	//
}

// Draw
void Unit::Draw(sf::RenderWindow& Render, bool& NamesDrawing, string Color, size_t Army)
{
	// If in settlement 
	if (SettlementType == SettlementTypes::Tower || SettlementType == SettlementTypes::Castle || SettlementType == SettlementTypes::Settlement)
		return;
	// Shadow 
		// Team shadow 
		/*
		Sprite.setTexture(TeamShadowTexture);

		if (Team == 0)
			Rect = sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(48, 48));
		else
		if (Team == 1)
			Rect = sf::IntRect(sf::Vector2i(0, 48), sf::Vector2i(48, 48));
		else
		if (Team == 2)
			Rect = sf::IntRect(sf::Vector2i(0, 96), sf::Vector2i(48, 48));
		else
		if (Team == 3)
			Rect = sf::IntRect(sf::Vector2i(0, 144), sf::Vector2i(48, 48));
		else
		if (Team == 4)
			Rect = sf::IntRect(sf::Vector2i(0, 192), sf::Vector2i(48, 48));
		else
		if (Team == 5)
			Rect = sf::IntRect(sf::Vector2i(0, 240), sf::Vector2i(48, 48));
		else
			Rect = sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(48, 48));

		Sprite.setTextureRect(Rect);

		Sprite.setPosition(sf::Vector2f(X-8, Y-8));
		Render.draw(Sprite);
		*/
		// Basic shadow 
		Sprite.setTexture(ShadowTexture);
		Sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(48, 48)));

		Sprite.setPosition(sf::Vector2f(X-8, Y-8));
		Render.draw(Sprite);

	// Basic 
	if (Opened == false)
		Sprite.setTextureRect(sf::IntRect(sf::Vector2i(32, 0), sf::Vector2i(32, 32)));
	else
		Sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)));

	Sprite.setPosition(sf::Vector2f(X, Y));

	Sprite.setTexture(BasicTexture);
	Sprite.setColor(StringToColor("255;255;255"));
	Render.draw(Sprite);

	// Bracket
	Sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	Sprite.setTexture(BracketTexture);
	Sprite.setColor(StringToColor(Color));
	Render.draw(Sprite);

	// Text 
	if (NamesDrawing == true)
	{
		//
		Name = '['+to_string(Army)+']';
		Text = sf::Text(Name, Font, this->FontSize);

		//
		Text.setStyle(sf::Text::Bold);
		Text.setOrigin(sf::Vector2f((-16)+(Text.getGlobalBounds().width/2), 0));
		Text.setPosition(X, Y+32);

		// Background text 
		sf::Vector2f PositionBuffer = Text.getPosition();

		Text.setFillColor(sf::Color(0, 0, 0, 255));
		Text.setPosition(PositionBuffer.x - 2, PositionBuffer.y); Render.draw(Text);
		Text.setPosition(PositionBuffer.x + 2, PositionBuffer.y); Render.draw(Text);
		Text.setPosition(PositionBuffer.x, PositionBuffer.y - 2); Render.draw(Text);
		Text.setPosition(PositionBuffer.x, PositionBuffer.y + 2); Render.draw(Text);
		Text.setPosition(PositionBuffer);

		// If team 
		Text.setFillColor(StringToColor(Color));

		Render.draw(Text);
	}
}
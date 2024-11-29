#include "LandMap.h"

// Constructor
LandMap::LandMap() 
{
	// Data path 
	string DataPath = "Data/Textures/Map/";

	// Load all textures to sprites
	// Unknown 
		if ( UnknownTexture.loadFromFile(DataPath+"Unknown.bmp") )
			UnknownSprite.setTexture(UnknownTexture);
	// Land 
		if ( LandTexture.loadFromFile(DataPath+"Land/Land.bmp") )
			LandSprite.setTexture(LandTexture);
		else
			LandSprite.setTexture(UnknownTexture);
	// Water 
		if ( WaterTexture.loadFromFile(DataPath+"Water/Water.bmp") )
			WaterSprite.setTexture(WaterTexture);
		else
			WaterSprite.setTexture(UnknownTexture);
	// Crag 
		if ( CragTexture.loadFromFile(DataPath+"Water/Crag.bmp") )
			CragSprite.setTexture(CragTexture);
		else
			CragSprite.setTexture(UnknownTexture);
	// River 
		// River main
		if ( RiverMainTexture.loadFromFile(DataPath+"River/RiverMain.bmp") )
			RiverMainSprite.setTexture(RiverMainTexture);
		else
			RiverMainSprite.setTexture(UnknownTexture);
		// River angles
		if ( RiverAnglesTexture.loadFromFile(DataPath+"River/RiverAngles.bmp") )
			RiverAnglesSprite.setTexture(RiverAnglesTexture);
		else
			RiverAnglesSprite.setTexture(UnknownTexture);
		// River ends
		if ( RiverEndsTexture.loadFromFile(DataPath+"River/RiverEnds.bmp") )
			RiverEndsSprite.setTexture(RiverEndsTexture);
		else
			RiverEndsSprite.setTexture(UnknownTexture);
	// Basic land 
		// Lake 
		if ( LakeTexture.loadFromFile(DataPath+"Land/Lake.bmp") )
			LakeSprite.setTexture(LakeTexture);
		else
			LakeSprite.setTexture(UnknownTexture);
		// Land water border 
		if ( LandWaterBorderTexture.loadFromFile(DataPath+"Land/LandWaterBorder.bmp") )
			LandWaterBorderSprite.setTexture(LandWaterBorderTexture);
		else
			LandWaterBorderSprite.setTexture(UnknownTexture);
		// Corner land 
		if ( CornerLandTexture.loadFromFile(DataPath+"Land/CornerLand.bmp") )
			CornerLandSprite.setTexture(CornerLandTexture);
		else
			CornerLandSprite.setTexture(UnknownTexture);
		// Double land water border 
		if ( DoubleLandWaterBorderTexture.loadFromFile(DataPath+"Land/DoubleLandWaterBorder.bmp") )
			DoubleLandWaterBorderSprite.setTexture(DoubleLandWaterBorderTexture);
		else
			DoubleLandWaterBorderSprite.setTexture(UnknownTexture);
		// Arc land 
		if ( ArcLandTexture.loadFromFile(DataPath+"Land/ArcLand.bmp") )
			ArcLandSprite.setTexture(ArcLandTexture);
		else
			ArcLandSprite.setTexture(UnknownTexture);
		// Island 
		if ( IslandTexture.loadFromFile(DataPath+"Land/Island.bmp") )
			IslandSprite.setTexture(IslandTexture);
		else
			IslandSprite.setTexture(UnknownTexture);
	// Angles land 
		// Angle
		if ( AngleTexture.loadFromFile(DataPath+"Angle/Angle.bmp") )
			AngleSprite.setTexture(AngleTexture);
		else
			AngleSprite.setTexture(UnknownTexture);
		// Double angle
		if ( DoubleAngleTexture.loadFromFile(DataPath+"Angle/DoubleAngle.bmp") )
			DoubleAngleSprite.setTexture(DoubleAngleTexture);
		else
			DoubleAngleSprite.setTexture(UnknownTexture);
		// Land water border double angle
		if ( LandWaterBorderDoubleAngleTexture.loadFromFile(DataPath+"Angle/LandWaterBorderDoubleAngle.bmp") )
			LandWaterBorderDoubleAngleSprite.setTexture(LandWaterBorderDoubleAngleTexture);
		else
			LandWaterBorderDoubleAngleSprite.setTexture(UnknownTexture);
		// Corner angle
		if ( CornerAngleTexture.loadFromFile(DataPath+"Angle/CornerAngle.bmp") )
			CornerAngleSprite.setTexture(CornerAngleTexture);
		else
			CornerAngleSprite.setTexture(UnknownTexture);
		// Cross angle
		if ( CrossAngleTexture.loadFromFile(DataPath+"Angle/CrossAngle.bmp") )
			CrossAngleSprite.setTexture(CrossAngleTexture);
		else
			CrossAngleSprite.setTexture(UnknownTexture);
		// Centr angle
		if ( CentrAngleTexture.loadFromFile(DataPath+"Angle/CentrAngle.bmp") )
			CentrAngleSprite.setTexture(CentrAngleTexture);
		else
			CentrAngleSprite.setTexture(UnknownTexture);
		// Third angle
		if ( ThirdAngleTexture.loadFromFile(DataPath+"Angle/ThirdAngle.bmp") )
			ThirdAngleSprite.setTexture(ThirdAngleTexture);
		else
			ThirdAngleSprite.setTexture(UnknownTexture);
		// Land water border angle
		if ( LandWaterBorderAngleTexture.loadFromFile(DataPath+"Angle/LandWaterBorderAngle.bmp") )
			LandWaterBorderAngleSprite.setTexture(LandWaterBorderAngleTexture);
		else
			LandWaterBorderAngleSprite.setTexture(UnknownTexture);
}

// Rendering map
void LandMap::Draw(sf::RenderWindow& Render, float CameraX, float CameraY, float CameraW, float CameraH, bool DrawingWarFog)
{

	//
	for (size_t i = 0; i < BlocksVector.size(); i++) 
	for (size_t j = 0; j < BlocksVector[i].size(); j++) 
	{
		// War Fog
		//if (BlocksVector[i][j].Settlement == false)
		if (BlocksVector[i][j].WarFog == false || DrawingWarFog == false)
		// Optimize
		if (BlocksVector[i][j].SettlementDrawing == true)
		if ((j >= size_t(CameraX/32) || CameraX <= 0) && (i >= size_t(CameraY/32) || CameraY <= 0) &&
			 j <= size_t((CameraX+CameraW)/32) && i <= size_t((CameraY+CameraH)/32))
		{
			// Select sprite type
			switch (BlocksVector[i][j].Type)
			{
				// Default 
				default:
					CurrentSprite = UnknownSprite;

				// Land blocks 
				case 0:
					CurrentSprite = LandSprite;
					break;

				// Water blocks 
					// Water 
					case 1:
						CurrentSprite = WaterSprite;
						break;

					// Crag  
					case 123:
						CurrentSprite = CragSprite;
						break;

				// Rivers blocks 
					// River main 
					case 3: case 4:
					case 36: case 37:
					case 38: case 39:
					case 40: case 41:
					case 42: case 43:
					case 44: case 45:
					case 46: case 47:
					case 48: case 49:
					case 50: case 51:
					case 83: case 84:
					case 85: case 86:
					case 21: case 22:
					case 23: case 24:
					case 25: case 26:
						CurrentSprite = RiverMainSprite;
						break;
					// River angles 
					case 28: case 29:
					case 30: case 31:
					case 32: case 33:
					case 34: case 35:
					case 5:  case 6:
					case 7:  case 8:
					case 70: case 71:
					case 72: case 73:
					case 66: case 67:
					case 68: case 69:
					case 88: case 89:
					case 90: case 91:
					case 9:  case 10:
					case 11: case 12:
					case 27:
						CurrentSprite = RiverAnglesSprite;
						break;
					// River ends 
					case 13: case 14:
					case 15: case 16:
					case 17: case 18:
					case 19: case 20:
					case 74: case 75:
					case 76: case 77:
					case 78: case 79:
					case 80: case 81:
						CurrentSprite = RiverEndsSprite;
					break;

				// Basic land 
					// Land water border 
					case 52: case 53:
					case 54: case 55:
						CurrentSprite = LandWaterBorderSprite;
					break;
					// Lake 
					case 82:
						CurrentSprite = LakeSprite;
					break;
					// Corner land 
					case 56: case 57:
					case 58: case 59:
						CurrentSprite = CornerLandSprite;
					break;
					// Double land water border 
					case 60: case 61:
						CurrentSprite = DoubleLandWaterBorderSprite;
					break;
					// Arc land 
					case 62: case 63:
					case 64: case 65:
						CurrentSprite = ArcLandSprite;
					break;
					// Island 
					case  87:
						CurrentSprite = IslandSprite;
					break;
				// Angles land 
					// Angle 
					case 92: case 93:
					case 94: case 95:
						CurrentSprite = AngleSprite;
					break;
					// Double angle 
					case 96: case  97:
					case 98: case  99:
						CurrentSprite = DoubleAngleSprite;
					break;
					// Land water border double angle 
					case 100: case 101:
					case 102: case 103:
						CurrentSprite = LandWaterBorderDoubleAngleSprite;
					break;
					// Corner angle 
					case 104: case 105:
					case 106: case 107:
						CurrentSprite = CornerAngleSprite;
					break;
					// Cross angle 
					case 108: case 109:
						CurrentSprite = CrossAngleSprite;
					break;
					// Centr angle
					case 110:
						CurrentSprite = CentrAngleSprite;
					break;
					// Third angle
					case 111: case 112:
					case 113: case 114:
						CurrentSprite = ThirdAngleSprite;
					break;
					// Land water border angle
					case 115: case 116:
					case 117: case 118:
					case 119: case 120:
					case 121: case 122:
						CurrentSprite = LandWaterBorderAngleSprite;
					break;
			}

			// Drawing
			CurrentSprite.setPosition(BlocksVector[i][j].X, BlocksVector[i][j].Y);
			if (CurrentSprite.getTexture() != UnknownSprite.getTexture())
				CurrentSprite.setTextureRect(BlocksVector[i][j].Rect);
			else
				CurrentSprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), BlocksVector[i][j].BlockSize));
			Render.draw(CurrentSprite);
		
		}
		//
	}
	//
}
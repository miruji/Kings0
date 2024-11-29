#include "MapBlock.h"

MapBlock::MapBlock(float X, float Y, float W, float H, size_t Type) 
{
	//
	this->X = X; this->Y = Y;
	this->Type = Type;
	this->BlockSize = sf::Vector2i(W,H);

	// Updating
	Update();
}
MapBlock::MapBlock() 
{
	//
}

// Updating
void MapBlock::Update() 
{
	// Set rect position of type 
	switch (Type)
	{
		// Default  
		default:
			Rect = sf::IntRect(sf::Vector2i(0, 0), BlockSize);
			break;

		// !!! Land.png
		case 0:
			Rect = sf::IntRect(sf::Vector2i(GetRandomNumber(0, 3)*32, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
			break;

		// !!! Water.png
		case 1:
			if (RectAddY != 0)
			{
				Type = 123;   // To Crag type 
				RectAddY = 0; // To Null for AddY 
				Update();     // Next -> Update 
			}
			else
				Rect = sf::IntRect(sf::Vector2i(GetRandomNumber(0, 15)*32, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
			break;

		case 123:
			Rect = sf::IntRect(sf::Vector2i(GetRandomNumber(0, 1)*32, GetRandomNumber(0, 5)*32), BlockSize);
			break;

		// !!! MainRiver.png
		// Main rivers
			// Up river - Centr - Down river
			case 3:
				Rect = sf::IntRect(sf::Vector2i(0, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Left river - Centr - Right river
			case 4:
				Rect = sf::IntRect(sf::Vector2i(32, GetRandomNumber(0, 1)*32), BlockSize);
				break;
		// Main rivers to LAND CONNECTED angle
			// Left river - Centr - Right angle (Down land connect)
			case 36:
				Rect = sf::IntRect(sf::Vector2i(64, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Right river - Centr - Left angle (Down land connect)
			case 37:
				Rect = sf::IntRect(sf::Vector2i(96, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			//	Up river - Centr - Down angle (Left land connect)
			case 38:
				Rect = sf::IntRect(sf::Vector2i(128, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Up river - Centr - Down angle (Right land connect)
			case 39:
				Rect = sf::IntRect(sf::Vector2i(160, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Down river - Centr - Up angle (Left land connect)
			case 40:
				Rect = sf::IntRect(sf::Vector2i(192, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Down river - Centr - Up angle (Right land connect)
			case 41:
				Rect = sf::IntRect(sf::Vector2i(224, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Left river - Centr - Right angle (Up land connect)
			case 42:
				Rect = sf::IntRect(sf::Vector2i(256, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Right river - Centr - Left angle (Up land connect)
			case 43:
				Rect = sf::IntRect(sf::Vector2i(288, GetRandomNumber(0, 1)*32), BlockSize);
				break;
		//  Main rivers RIVER to LAND CONNECTED angle
			// Left river - Centr - Right angle (Down land connect)
			case 44:
				Rect = sf::IntRect(sf::Vector2i(320, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Right river - Centr - Left angle (Down land connect)
			case 45:
				Rect = sf::IntRect(sf::Vector2i(352, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			//	Up river - Centr - Down angle (Left land connect)
			case 46:
				Rect = sf::IntRect(sf::Vector2i(384, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Up river - Centr - Down angle (Right land connect)
			case 47:
				Rect = sf::IntRect(sf::Vector2i(416, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Down river - Centr - Up angle (Left land connect)
			case 48:
				Rect = sf::IntRect(sf::Vector2i(448, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Down river - Centr - Up angle (Right land connect)
			case 49:
				Rect = sf::IntRect(sf::Vector2i(480, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Left river - Centr - Right angle (Up land connect)
			case 50:
				Rect = sf::IntRect(sf::Vector2i(512, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Right river - Centr - Left angle (Up land connect)
			case 51:
				Rect = sf::IntRect(sf::Vector2i(544, GetRandomNumber(0, 1)*32), BlockSize);
				break;
		//  Main rivers (other)
			// Up land - Down circle
			case 83:
				Rect = sf::IntRect(sf::Vector2i(576, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Up circle - Down land
			case 84:
				Rect = sf::IntRect(sf::Vector2i(608, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			//	Left land - Right cirle
			case 85:
				Rect = sf::IntRect(sf::Vector2i(640, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Left circle - Right land
			case 86:
				Rect = sf::IntRect(sf::Vector2i(672, GetRandomNumber(0, 1)*32), BlockSize);
				break;
		// Main blocks
			// Up - Centr - Down to river
			case 21:
				Rect = sf::IntRect(sf::Vector2i(704, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Left - Centr - Right river
			case 22:
				Rect = sf::IntRect(sf::Vector2i(736, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Down river - Centr - Up
			case 23:
				Rect = sf::IntRect(sf::Vector2i(768, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Right - Centr - Left
			case 24:
				Rect = sf::IntRect(sf::Vector2i(800, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Up - Centr - Down
			case 25:
				Rect = sf::IntRect(sf::Vector2i(832, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Left - Centr - Right
			case 26:
				Rect = sf::IntRect(sf::Vector2i(864, GetRandomNumber(0, 1)*32), BlockSize);
				break;

		// !!! RiverAngles.png
		// Angle rives (Angle land not) (first)
			// Left river - Centr - Down river
			case 28:
				Rect = sf::IntRect(sf::Vector2i(0, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Right river - Centr - Down river
			case 29:
				Rect = sf::IntRect(sf::Vector2i(32, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Left river - Centr - Up river
			case 30:
				Rect = sf::IntRect(sf::Vector2i(64, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Left river - Centr - Up river
			case 31:
				Rect = sf::IntRect(sf::Vector2i(96, GetRandomNumber(0, 1)*32), BlockSize);
				break;
		// Angle rives (Angle land not) (second)
			// Left river - Centr - Down river
			case 32:
				Rect = sf::IntRect(sf::Vector2i(128, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Right river - Centr - Down river
			case 33:
				Rect = sf::IntRect(sf::Vector2i(160, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Left river - Centr - Up river
			case 34:
				Rect = sf::IntRect(sf::Vector2i(192, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Left river - Centr - Up river
			case 35:
				Rect = sf::IntRect(sf::Vector2i(224, GetRandomNumber(0, 1)*32), BlockSize);
				break;
		// Angle rives
			// Left river - Centr - Down river
			case 5:
				Rect = sf::IntRect(sf::Vector2i(256, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Right river - Centr - Down river
			case 6:
				Rect = sf::IntRect(sf::Vector2i(288, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Left river - Centr - Up river
			case 7:
				Rect = sf::IntRect(sf::Vector2i(320, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Right river - Centr - Up river
			case 8:
				Rect = sf::IntRect(sf::Vector2i(352, GetRandomNumber(0, 1)*32), BlockSize);
				break;
		// Angle rives (Angle land) (third)
			// Left river - Centr - Down river
			case 66:
				Rect = sf::IntRect(sf::Vector2i(384, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Right river - Centr - Down river
			case 67:
				Rect = sf::IntRect(sf::Vector2i(416, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Left river - Centr - Up river
			case 68:
				Rect = sf::IntRect(sf::Vector2i(448, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Left river - Centr - Up river
			case 69:
				Rect = sf::IntRect(sf::Vector2i(480, GetRandomNumber(0, 1)*32), BlockSize);
				break;
		// Angle rives (Angle land not) (fourth)
			// Left river - Centr - Down river
			case 70:
				Rect = sf::IntRect(sf::Vector2i(512, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Right river - Centr - Down river
			case 71:
				Rect = sf::IntRect(sf::Vector2i(544, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Left river - Centr - Up river
			case 72:
				Rect = sf::IntRect(sf::Vector2i(576, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Left river - Centr - Up river
			case 73:
				Rect = sf::IntRect(sf::Vector2i(608, GetRandomNumber(0, 1)*32), BlockSize);
				break;
		// Angle rives (Angle land not) (fifth)
			// Left river - Centr - Down river
			case 88:
				Rect = sf::IntRect(sf::Vector2i(640, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Right river - Centr - Down river
			case 89:
				Rect = sf::IntRect(sf::Vector2i(672, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Left river - Centr - Up river
			case 90:
				Rect = sf::IntRect(sf::Vector2i(704, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Left river - Centr - Up river
			case 91:
				Rect = sf::IntRect(sf::Vector2i(736, GetRandomNumber(0, 1)*32), BlockSize);
				break;
		// Rivers connection
			// Left to Up river - Centr - Down river
			case 9:
				Rect = sf::IntRect(sf::Vector2i(768, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Right to Up river - Centr - Down river
			case 10:
				Rect = sf::IntRect(sf::Vector2i(800, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Up to Left river - Centr - Right river
			case 11:
				Rect = sf::IntRect(sf::Vector2i(832, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Down to Left river - Centr - Right river
			case 12:
				Rect = sf::IntRect(sf::Vector2i(864, GetRandomNumber(0, 1)*32), BlockSize);
				break;
		// Centr
		case 27:
			Rect = sf::IntRect(sf::Vector2i(896, GetRandomNumber(0, 1) * 32), BlockSize);
			break;

		// !!! RiverEnds.png
		// Rivers end 1
			// Down - Centr - End
			case 17:
				Rect = sf::IntRect(sf::Vector2i(0, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Up - Centr - End
			case 18:
				Rect = sf::IntRect(sf::Vector2i(32, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Left - Centr - End
			case 19:
				Rect = sf::IntRect(sf::Vector2i(64, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Right - Centr - End
			case 20:
				Rect = sf::IntRect(sf::Vector2i(96, GetRandomNumber(0, 1)*32), BlockSize);
				break;
		// Rivers end 2
			// Down river - Centr - End
			case 13:
				Rect = sf::IntRect(sf::Vector2i(128, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Up river - Centr - End
			case 14:
				Rect = sf::IntRect(sf::Vector2i(160, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Left river - Centr - End
			case 15:
				Rect = sf::IntRect(sf::Vector2i(192, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Right river - Centr - End
			case 16:
				Rect = sf::IntRect(sf::Vector2i(224, GetRandomNumber(0, 1)*32), BlockSize);
				break;
		// Rivers end 3
			// Down - Centr - End
			case 74:
				Rect = sf::IntRect(sf::Vector2i(256, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Up - Centr - End
			case 75:
				Rect = sf::IntRect(sf::Vector2i(288, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Left - Centr - End
			case 76:
				Rect = sf::IntRect(sf::Vector2i(320, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Right - Centr - End
			case 77:
				Rect = sf::IntRect(sf::Vector2i(352, GetRandomNumber(0, 1)*32), BlockSize);
				break;
		// Rivers end 4
			// Down - Centr - End
			case 78:
				Rect = sf::IntRect(sf::Vector2i(384, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Up - Centr - End
			case 79:
				Rect = sf::IntRect(sf::Vector2i(416, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Left - Centr - End
			case 80:
				Rect = sf::IntRect(sf::Vector2i(448, GetRandomNumber(0, 1)*32), BlockSize);
				break;
			// Right - Centr - End
			case 81:
				Rect = sf::IntRect(sf::Vector2i(480, GetRandomNumber(0, 1)*32), BlockSize);
				break;

		// !!! Lake.png
		case 82:
			Rect = sf::IntRect(sf::Vector2i(GetRandomNumber(0, 3) * 32, GetRandomNumber(0, 5) * 32), BlockSize);
			break;

		// !!! LandWaterBorder.png
			// Down land - Up water
			case 52:
				Rect = sf::IntRect(sf::Vector2i(0, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Up land - Down water
			case 53:
				Rect = sf::IntRect(sf::Vector2i(32, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Left land - Right water
			case 54:
				Rect = sf::IntRect(sf::Vector2i(64, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Right land - Left water
			case 55:
				Rect = sf::IntRect(sf::Vector2i(96, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;

		// !!! CornerLand.png
			// Left Up water
			case 56:
				Rect = sf::IntRect(sf::Vector2i(0, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Right Up water
			case 57:
				Rect = sf::IntRect(sf::Vector2i(32, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Left Down water
			case 58:
				Rect = sf::IntRect(sf::Vector2i(64, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Right Down water
			case 59:
				Rect = sf::IntRect(sf::Vector2i(96, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;

		// !!! DoubleLandWaterBorder.png
			// Left - Right
			case 60:
				Rect = sf::IntRect(sf::Vector2i(0, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Up - Down
			case 61:
				Rect = sf::IntRect(sf::Vector2i(32, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;

		// !!! ArcLand.png
			// Up arc
			case 62:
				Rect = sf::IntRect(sf::Vector2i(0, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Down arc
			case 63:
				Rect = sf::IntRect(sf::Vector2i(32, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Left arc
			case 64:
				Rect = sf::IntRect(sf::Vector2i(64, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Right arc
			case 65:
				Rect = sf::IntRect(sf::Vector2i(96, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;

		// !!! Island.png
		case 87:
			Rect = sf::IntRect(sf::Vector2i(GetRandomNumber(0, 3) * 32, RectAddY + GetRandomNumber(0, 2) * 32), BlockSize);
			break;

		// !!! Angle.png
			// Up left
			case 92:
				Rect = sf::IntRect(sf::Vector2i(0, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Up right
			case 93:
				Rect = sf::IntRect(sf::Vector2i(32, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Down left
			case 94:
				Rect = sf::IntRect(sf::Vector2i(64, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Down right
			case 95:
				Rect = sf::IntRect(sf::Vector2i(96, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;

		// !!! DoubleAngle.png
			// Up : left & right
			case 96:
				Rect = sf::IntRect(sf::Vector2i(0, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Down : left & right
			case 97:
				Rect = sf::IntRect(sf::Vector2i(32, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Left : up & down
			case 98:
				Rect = sf::IntRect(sf::Vector2i(64, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Right : up & down
			case 99:
				Rect = sf::IntRect(sf::Vector2i(96, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;

		// !!! LandWaterBorderDoubleAngle.png
			// Up : left & right
			case 100:
				Rect = sf::IntRect(sf::Vector2i(0, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Down : left & right
			case 101:
				Rect = sf::IntRect(sf::Vector2i(32, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Left : up & down
			case 102:
				Rect = sf::IntRect(sf::Vector2i(64, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Right : up & down
			case 103:
				Rect = sf::IntRect(sf::Vector2i(96, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;

		// !!! CornerAngle.png
			// Left Up water
			case 104:
				Rect = sf::IntRect(sf::Vector2i(0, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Right Up water
			case 105:
				Rect = sf::IntRect(sf::Vector2i(32, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Left Down water
			case 106:
				Rect = sf::IntRect(sf::Vector2i(64, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Right Down water
			case 107:
				Rect = sf::IntRect(sf::Vector2i(96, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;

		// !!! CrossAngle.png
			// Left down - Right up
			case 108:
				Rect = sf::IntRect(sf::Vector2i(0, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Left up - Right down
			case 109:
				Rect = sf::IntRect(sf::Vector2i(32, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;

		// !!! CentrAngle.png
		case 110:
			Rect = sf::IntRect(sf::Vector2i(0, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
			break;

		// !!! ThirdAngle.png
			// Left up
			case 111:
				Rect = sf::IntRect(sf::Vector2i(0, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Right up
			case 112:
				Rect = sf::IntRect(sf::Vector2i(32, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Right down
			case 113:
				Rect = sf::IntRect(sf::Vector2i(64, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Left down
			case 114:
				Rect = sf::IntRect(sf::Vector2i(96, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;

		// !!! LandWaterBorderAngle.png
			// Up water - right down angle
			case 115:
				Rect = sf::IntRect(sf::Vector2i(0, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Up water - left down angle
			case 116:
				Rect = sf::IntRect(sf::Vector2i(32, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Down water - right up angle
			case 117:
				Rect = sf::IntRect(sf::Vector2i(64, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Down water - left up angle
			case 118:
				Rect = sf::IntRect(sf::Vector2i(96, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Left water - right down angle
			case 119:
				Rect = sf::IntRect(sf::Vector2i(128, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Right water - left down angle
			case 120:
				Rect = sf::IntRect(sf::Vector2i(160, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Left water - right up angle
			case 121:
				Rect = sf::IntRect(sf::Vector2i(192, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
			// Right water - left up angle
			case 122:
				Rect = sf::IntRect(sf::Vector2i(224, RectAddY+GetRandomNumber(0, 2)*32), BlockSize);
				break;
		// TO:DO ->> NOT LAND-WATER BLOCKS ->> BAG
	}
	//
}
#pragma once
#include "raylib.h"

//arena settings
const float screenWidth = 1024.0f;
const float screenHeight = 768.0f;
const float auxFloat = 100.0f;
const float arenaMarkBoard = 100.0f;

//player settings
const float playerSpeed = 450.0f;
const float playerPosX = screenWidth / 2;
const float playerPosY = screenHeight /2;

//menu settings POS
//button size
const float buttonWidth = 60.0f;
const float buttonHeiht = 30.0f;
const int fontSize = 5;
//button center
const float buttonCenterX = buttonWidth / 2;
const float buttonCenterY = buttonHeiht / 2;
// 
//mainMenu settings
//button default pos
const float auxButtonPosX = screenWidth / 2;
const float auxButtonPosY_1 = (screenHeight / 5) * 2;
const float auxButtonPosY_2 = (screenHeight / 5) * 3;
const float auxButtonPosY_3 = (screenHeight / 5) * 4;
const float auxButtonPosY_4 = (screenHeight / 5) * 5;
//text main menu
const int playTextPosX = auxButtonPosX;
const int playTextPosY = auxButtonPosY_1;
const int creditsTextPosX = auxButtonPosX;
const int creditsTextPosY = auxButtonPosY_2;
const int exitTextPosX = auxButtonPosX;
const int exitTextPosY = auxButtonPosY_3;

//credits settings
const int auxCreditsTextPosX = screenWidth / 3;
const int creditsText1PosY = (screenHeight / 7) ;
const int creditsText2PosY = (screenHeight / 7) * 2;
const int creditsText3PosY = (screenHeight / 7) * 3;
const int creditsText4PosY = (screenHeight / 7) * 4;
const int creditsText5PosY = (screenHeight / 7) * 5;
const int creditsText6PosY = (screenHeight / 7) * 6;
const int creditsText7PosY = (screenHeight / 7) * 7;

//exit
//question text
const int auxExitTextPosX = screenWidth / 3;
const int exitText1PosY = (screenHeight / 7);
//button YES NO exit
const float auxExitButtonPosY = (screenHeight / 5) * 4;
const float auxExitButtonPosX_1 = (screenWidth / 5) * 2;
const float auxExitButtonPosX_2 = (screenWidth / 5) * 4;
//text YES NO exit
const int auxExitText2PosY = (screenHeight / 7) * 2;
const int exitText3PosX = auxExitButtonPosX_1;
const int exitText1PosX = auxExitButtonPosX_2;
#pragma once
#include "raylib.h"

//ARENA settings
const float screenWidth = 1024.0f;
const float screenHeight = 768.0f;
const float auxFloat = 100.0f;
const float arenaMarkBoard = 100.0f;

//PLAYER settings
const float playerSpeed = 450.0f;
const float playerPosX = screenWidth / 2;
const float playerPosY = screenHeight /2;

//MENU settings POS
//BUTTON SIZE
const float buttonWidth = 60.0f;
const float buttonHeiht = 30.0f;
const int fontSize = 5;
//BUTTON CENTER
const float buttonCenterX = buttonWidth / 2;
const float buttonCenterY = buttonHeiht / 2;

//MAINMENU settings---------------------------------
//PAUSE MENU settings------------------------------------------
//button default pos
const float auxButtonPosX = screenWidth / 2;
const float auxButtonPosY_1 = (screenHeight / 5) * 2;
const float auxButtonPosY_2 = (screenHeight / 5) * 3;
const float auxButtonPosY_3 = (screenHeight / 5) * 4;
const float auxButtonPosY_4 = (screenHeight / 5) * 5;
//text main menu
const int titleTextPosX = auxButtonPosX;
const int titleTextPosY = auxButtonPosY_1;
const int playTextPosX = auxButtonPosX;
const int playTextPosY = auxButtonPosY_2;
const int creditsTextButtonPosX = auxButtonPosX;
const int creditsTextButtonPosY = auxButtonPosY_3;
const int exitTextButtonPosX = auxButtonPosX;
const int exitTextButtonPosY = auxButtonPosY_4;

//CREDITS settings-----------------------------------
const int auxCreditsTextPosX = screenWidth / 3;
const int creditsText1PosY = (screenHeight / 7) ;
const int creditsText2PosY = (screenHeight / 7) * 2;
const int creditsText3PosY = (screenHeight / 7) * 3;
const int creditsText4PosY = (screenHeight / 7) * 4;
const int creditsText5PosY = (screenHeight / 7) * 5;
const int creditsText6PosY = (screenHeight / 7) * 6;

const int creditsText7PosY = (screenHeight / 7) * 7;
const int backButtonPosX = screenWidth / 5;
const int backButtonPosY = screenWidth / 5;

//EXIT-----------------------------------------------
//question text1
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

//WIN/LOSE SCREEN------------------------------------------
//TO MENU and RESTART button
//WIN LOSE title
const int auxWinLoseTextPosX = auxButtonPosX;
const int winLoseTextPosY = auxButtonPosY_1;
const int restartTextPosY = auxButtonPosY_2;
const int toMenuTextPosY = auxButtonPosY_3;

const float auxButtonPosX = screenWidth / 2;
const float restartButtonPosY_3 = (screenHeight / 5) * 4;
const float toMenuButtonPosY_4 = (screenHeight / 5) * 5;

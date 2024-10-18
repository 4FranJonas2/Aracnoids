#pragma once
#include "raylib.h"

//ARENA settings
const float screenWidth = 1024.0f;
const float screenHeight = 768.0f;
const float auxFloat = 100.0f;
const float arenaMarkBoard = 100.0f;

//PLAYER settings
const float playerSpeed = 450.0f;
const float playerPosX = screenWidth / 2.0f;
const float playerPosY = screenHeight / 2.0f;

//MENU settings POS
//BUTTON SIZE
const float buttonWidth = 60.0f;
const float buttonHeiht = 30.0f;
const int fontSize = 5;
//BUTTON CENTER
const float buttonCenterX = buttonWidth / 2.0f;
const float buttonCenterY = buttonHeiht / 2.0f;

//MAINMENU settings---------------------------------
//PAUSE MENU settings------------------------------------------
//button default pos
const float auxButtonPosX = static_cast<float>(screenWidth) / 2.0f;
const float auxButtonPosY_1 = ((screenHeight / 5.0f) * 2.0f);
const float auxButtonPosY_2 = ((screenHeight / 5.0f) * 3.0f);
const float auxButtonPosY_3 = ((screenHeight / 5.0f) * 4.0f);
const float auxButtonPosY_4 = ((screenHeight / 5.0f) * 5.0f);
//text main menu
const float titleTextPosX = auxButtonPosX;
const float titleTextPosY = auxButtonPosY_1;
const float playTextPosX = auxButtonPosX;
const float playTextPosY = auxButtonPosY_2;
const float creditsTextButtonPosX = auxButtonPosX;
const float creditsTextButtonPosY = auxButtonPosY_3;
const float exitTextButtonPosX = auxButtonPosX;
const float exitTextButtonPosY = auxButtonPosY_4;

//CREDITS settings-----------------------------------
const float auxCreditsTextPosX = screenWidth / 3;
const float creditsText1PosY = (screenHeight / 7);
const float creditsText2PosY = (screenHeight / 7) * 2;
const float creditsText3PosY = (screenHeight / 7) * 3;
const float creditsText4PosY = (screenHeight / 7) * 4;
const float creditsText5PosY = (screenHeight / 7) * 5;
const float creditsText6PosY = (screenHeight / 7) * 6;

const float creditsText7PosY = (screenHeight / 7) * 7;
const float backButtonPosX = screenWidth / 5;
const float backButtonPosY = screenWidth / 5;

//EXIT-----------------------------------------------
//question text1
const float auxExitTextPosX = screenWidth / 3;
const float exitText1PosY = (screenHeight / 7);
//button YES NO exit
const float auxExitButtonPosY = (screenHeight / 5) * 4;
const float auxExitButtonPosX_1 = (screenWidth / 5) * 2;
const float auxExitButtonPosX_2 = (screenWidth / 5) * 4;
//text YES NO exit
const float auxExitText2PosY = (screenHeight / 7) * 2;
const float exitText3PosX = auxExitButtonPosX_1;
const float exitText1PosX = auxExitButtonPosX_2;

//WIN/LOSE SCREEN------------------------------------------
//TO MENU and RESTART button
//WIN LOSE title
const float auxWinLoseTextPosX = auxButtonPosX;
const float winLoseTextPosY = auxButtonPosY_1;
const float restartTextPosY = auxButtonPosY_2;
const float toMenuTextPosY = auxButtonPosY_3;

const float restartButtonPosY_3 = (screenHeight / 5) * 4;
const float toMenuButtonPosY_4 = (screenHeight / 5) * 5;

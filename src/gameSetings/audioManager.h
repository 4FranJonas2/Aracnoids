#pragma once

#include "raylib.h"

#include "../utilities.h"

namespace aracnoids
{
	enum class MusicType
	{
		MENU =1,
		GAMPLAY
	};

	struct AudioManager
	{
		Music menuMusic;
		Music gameplayMusic;
		Sound clickSound;
		Sound overSound;
		Sound shootSound;
		Sound enemyDestroySound;
		Sound loseLifeSound;

		MusicType currentMusic;
	};

	void InitAudio(AudioManager& audio);
	void UpdateAudio(AudioManager& audio);
	void SwitchMusic(AudioManager& audio, MusicType newMusic);
	void PlaySFX( Sound& sfx);
	void UnloadAudio(AudioManager& audio);
}
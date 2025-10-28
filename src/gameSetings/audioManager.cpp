#include "audioManager.h"

namespace aracnoids
{
	void InitAudio(AudioManager& audio)
	{
		audio.menuMusic = LoadMusicStream("res/Audio/Nighttime-Escape_LoFi.mp3");
		audio.gameplayMusic = LoadMusicStream("res/Audio/Nighttime-Escape.mp3");

		audio.clickSound = LoadSound("res/Audio/ClickButton.wav");
		audio.overSound = LoadSound("res/Audio/OverButton.wav");
		audio.shootSound = LoadSound("res/Audio/Shoot4.wav");
		audio.enemyDestroySound = LoadSound("res/Audio/Boom3.wav");
		audio.loseLifeSound = LoadSound("res/Audio/Hit16.wav");

		audio.currentMusic = MusicType::MENU;
		PlayMusicStream(audio.menuMusic);
	}

	void UpdateAudio(AudioManager& audio)
	{
		UpdateMusicStream(audio.menuMusic);
		UpdateMusicStream(audio.gameplayMusic);
	}

	void SwitchMusic(AudioManager& audio, MusicType newMusic)
	{
		float timePlayed = 0.0f;

		if (audio.currentMusic == newMusic)
			return;

		if (audio.currentMusic == MusicType::MENU)
		{
			timePlayed = GetMusicTimePlayed(audio.menuMusic);
			PauseMusicStream(audio.menuMusic);
		}
		else
		{
			timePlayed = GetMusicTimePlayed(audio.gameplayMusic);
			PauseMusicStream(audio.gameplayMusic);
		}

		audio.currentMusic = newMusic;

		if (newMusic == MusicType::MENU)
		{
			SeekMusicStream(audio.menuMusic, timePlayed);
			PlayMusicStream(audio.menuMusic);
		}
		else
		{
			SeekMusicStream(audio.gameplayMusic, timePlayed);
			PlayMusicStream(audio.gameplayMusic);
		}
	}

	void PlaySFX(Sound& sfx)
	{
		PlaySound(sfx);
	}

	void UnloadAudio(AudioManager& audio)
	{
		UnloadMusicStream(audio.menuMusic);
		UnloadMusicStream(audio.gameplayMusic);
		UnloadSound(audio.clickSound);
		UnloadSound(audio.enemyDestroySound);
		UnloadSound(audio.loseLifeSound);
		UnloadSound(audio.overSound);
		UnloadSound(audio.shootSound);

		CloseAudioDevice();
	}
}
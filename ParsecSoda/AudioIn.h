#pragma once

#include <mmdeviceapi.h>
#include <Audioclient.h>
#include <mmsystem.h>
#include <string>
#include <vector>
#include <iostream>
#include <mutex>
#include <functiondiscoverykeys.h>
#include <initguid.h>
#include "Stringer.h"
#include "AudioTools.h"

typedef struct AudioInDevice
{
	WAVEINCAPS wave;
	UINT id;
	bool isEmpty = true;
	string name;
} AudioInDevice;

class AudioIn
{
public:
	bool init(AudioInDevice device);
	void captureAudio();
	const bool isReady() const;
	const std::vector<int16_t> popBuffer();
	const int popPreviewDecibel();
	const std::vector<AudioInDevice> listInputDevices() const;
	AudioInDevice selectInputDevice(const int index = 0);

	float volume = 1.0f;
	bool isEnabled = true;

	AudioInDevice currentDevice;

private:
	IMMDeviceEnumerator *pEnumerator = NULL;
	IMMDevice *pDevice = NULL;
	IAudioClient *pAudioClient = NULL;
	IAudioCaptureClient *pCaptureClient = NULL;

	bool _isReady = false;
	int _activeBuffer = 0;
	int _previewIndex = 0;

	mutex _mutex;
};


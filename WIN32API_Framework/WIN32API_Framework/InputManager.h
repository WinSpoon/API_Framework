#pragma once
#include "Include.h"

class InputManager
{
public:
	Single(InputManager)
		/*
private:
	static InputManager* Instance;

public:
	static InputManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new InputManager;
		return Instance;
	}
		*/
private:
	DWORD inputKey;
public:
	DWORD GetKey() { return inputKey; }

	void CheckKey();
private:
	InputManager();
public:
	~InputManager();
};


#pragma once

class State
{
public:
	virtual void Init() = 0;

	virtual void HandleInput() = 0;
	virtual void Update(float dt) = 0;
	//dt is delta time to factor in frame rate
	virtual void Draw(float dt) = 0;

	virtual void Pause() {}
	virtual void Resume() {}

};
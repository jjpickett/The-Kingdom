/// \file	State.h.
///
/// \brief	Declares the state class

#pragma once

/// \class	State
///
/// \brief	A state.
///
/// \author	Jordan Pickett
/// \date	11/30/2017

class State
{
public:

	/// \fn	virtual void State::Init() = 0;
	///
	/// \brief	Initializes this object
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017

	virtual void Init() = 0;

	/// \fn	virtual void State::HandleInput() = 0;
	///
	/// \brief	Handles the input
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017

	virtual void HandleInput() = 0;

	/// \fn	virtual void State::Update(float dt) = 0;
	///
	/// \brief	Updates the given dt
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param	dt	The dt.

	virtual void Update(float dt) = 0;

	/// \fn	virtual void State::Draw(float dt) = 0;
	///
	/// \brief	dt is delta time to factor in frame rate
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017
	///
	/// \param	dt	The dt.

	virtual void Draw(float dt) = 0;

	/// \fn	virtual void State::Pause()
	///
	/// \brief	Pauses this object
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017

	virtual void Pause() {}

	/// \fn	virtual void State::Resume()
	///
	/// \brief	Resumes this object
	///
	/// \author	Jordan Pickett
	/// \date	11/30/2017

	virtual void Resume() {}

};
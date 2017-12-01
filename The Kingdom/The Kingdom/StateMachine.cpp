/// \file	StateMachine.cpp.
///
/// \brief	Implements the state machine class

#include "StateMachine.h"
#include <iostream>
#include <exception>

/// \fn	void StateMachine::AddState(StateRef newState, bool isReplacing)
///
/// \brief	Adds a state to 'isReplacing'
///
/// \author	author Taylor Doud, Matthew Rose, Jordan Pickett, Nora White
/// \date	11/30/2017
///
/// \param	newState   	State of the new.
/// \param	isReplacing	True if this object is replacing.

void StateMachine::AddState(StateRef newState, bool isReplacing)
{
	this->_isAdding = true;
	this->_isReplacing = isReplacing;

	this->_newState = std::move(newState);
}

/// \fn	void StateMachine::RemoveState()
///
/// \brief	Removes the state
///
/// \author	author Taylor Doud, Matthew Rose, author Taylor Doud, Matthew Rose, Jordan Pickett, Nora White, Nora White
/// \date	11/30/2017

void StateMachine::RemoveState()
{
	this->_isRemoving = true;
}

/// \fn	void StateMachine::ProcessStateChanges()
///
/// \brief	Process the state changes
///
/// \author	author Taylor Doud, Matthew Rose, Jordan Pickett, Nora White
/// \date	11/30/2017

void StateMachine::ProcessStateChanges()
{
	if (this->_isRemoving && !this->_states.empty())
	{
		this->_states.pop();

		if (!this->_states.empty())
		{
			this->_states.top()->Resume();
		}

		this->_isRemoving = false;
	}

	if (this->_isAdding)
	{
		if (!this->_states.empty())
		{
			if (this->_isReplacing)
			{
				this->_states.pop();
			}
			else
			{
				this->_states.top()->Pause();
			}
		}
		this->_states.push(std::move(this->_newState));
		this->_states.top()->Init();
		this->_isAdding = false;
	}
}

/// \fn	StateRef &StateMachine::GetActiveState()
///
/// \brief	Gets active state
///
/// \author	author Taylor Doud, Matthew Rose, author Taylor Doud, Matthew Rose, Jordan Pickett, Nora White, Nora White
/// \date	11/30/2017
///
/// \return	The active state.

StateRef &StateMachine::GetActiveState()
{
	return this->_states.top();
}

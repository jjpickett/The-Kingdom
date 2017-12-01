//
// CS 2720: GeneralFailure
//
/// \author Taylor Doud, Matthew Rose, Jordan Pickett, Nora White
/// \date Nov 26, 2017
///
///
/// \brief Implements the state machine class
///

#pragma once

#include <memory>
#include <stack>

#include "State.h"

typedef std::unique_ptr<State> StateRef;

class StateMachine
{
public:
	StateMachine() {}
	~StateMachine() {}

    /// Adds a state to 'isReplacing'
    /// \param newState State of the new.
    /// \param isReplacing True if this object is replacing.
	void AddState(StateRef newState, bool isReplacing = true);
	
    /// Removes the state
    void RemoveState();

    /// Process the state changes.
	void ProcessStateChanges();

    /// Gets the current State.
	StateRef &GetActiveState();

private:
	std::stack<StateRef> _states;
	StateRef _newState;
	bool _isRemoving;
	bool _isAdding;
	bool _isReplacing;
};


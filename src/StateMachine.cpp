//
// Created by Max Yu on 9/20/20.
//

#include "StateMachine.h"
#include "IllegalGameStateException.h"

const bool transitionTable[6][6] = {
        // 0 -> 1
        {false, true, false, false, false, false},
        // 1 -> 2 | 3
        {false, false, true, true, false, false},
        // 2 -> 1
        {false, true, false, false, false, false},
        // 3 -> 4
        {false, false, false, false, true, false},
        // 4 -> 5 | 1
        {false, true, false, false, false, true},
        // 5 -> x
        {false, false, false, false, false, false},
};

StateMachine::StateMachine(int sectionCount) {
    StateMachine::sectionCount = sectionCount;
    currentSection = 0;
    currentState = Mode::NotStarted;
}

Mode StateMachine::GetGameMode() {
    return currentState;
}

int StateMachine::GetCurrentSection() const {
    return currentSection;
}

bool StateMachine::IsAtLastSection() const {
    return (currentSection == sectionCount - 1);
}

void StateMachine::StateTransition(Mode origin, Mode destination) {
    if (origin == currentState && transitionTable[origin][destination]) {
        currentState = destination;
    } else {
        throw IllegalGameStateException("Illegal game state transition");
    }
}

void StateMachine::StartGameplay() {
    StateTransition(NotStarted, MainGameplay);
}

void StateMachine::EnterComboMode() {
    StateTransition(MainGameplay, ComboMode);
}

void StateMachine::ExitComboMode() {
    StateTransition(ComboMode, MainGameplay);
}

void StateMachine::PrepareNewSection() {
    StateTransition(MainGameplay, Preparing);
}

void StateMachine::StartMiniGame() {
    StateTransition(Preparing, MiniGame);
}

void StateMachine::StartNextSection() {
    if (!IsAtLastSection()) {
        StateTransition(MiniGame, MainGameplay);
        currentSection++;
    } else {
        throw IllegalGameStateException("Cannot start next section when at last section");
    }
}

void StateMachine::FinishGame() {
    if (IsAtLastSection()) {
        StateTransition(MiniGame, Finished);
    } else {
        throw IllegalGameStateException("Cannot start finish game with remaining sections");
    }
}

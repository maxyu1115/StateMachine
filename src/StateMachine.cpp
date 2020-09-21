//
// Created by Max Yu on 9/20/20.
//

#include "StateMachine.h"

const bool transition_table[6][6] = {
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

StateMachine::StateMachine(int section_count) {
    StateMachine::section_count = section_count;
    current_section = 0;
    current_state = Mode::NotStarted;
}

Mode StateMachine::GetGameMode() {
    return current_state;
}

int StateMachine::GetCurrentSection() const {
    return current_section;
}

bool StateMachine::IsAtLastSection() const {
    return (current_section == section_count - 1);
}

void StateMachine::StateTransition(Mode origin, Mode destination) {
    if (origin == current_state && transition_table[origin][destination]) {
        current_state = destination;
    } else {
        throw "Illegal State!";
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
        current_section++;
    } else {
        throw "yikes";
    }
}

void StateMachine::FinishGame() {
    if (IsAtLastSection()) {
        StateTransition(MiniGame, Finished);
    } else {
        throw "yieks";
    }
}


//
//IllegalGameStateException::IllegalGameStateException(const char *) {
//
//}
//
//const char *IllegalGameStateException::getMsg() const {
//    return msg;
//}

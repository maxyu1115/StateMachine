#include <iostream>
#include "StateMachine.h"

void testNoErrors();
void testIllegalTransition();
void testSectionErrors();

int main() {
    std::cout << "Hello, World!" << std::endl;
    testNoErrors();
    testIllegalTransition();
    testSectionErrors();
    return 0;
}

void testNoErrors() {
    StateMachine stateMachine = StateMachine(2);
    stateMachine.StartGameplay();
    stateMachine.EnterComboMode();
    stateMachine.ExitComboMode();

    assert(stateMachine.GetCurrentSection() == 0);
    assert(stateMachine.GetGameMode() == Mode::MainGameplay);
    stateMachine.PrepareNewSection();
    stateMachine.StartMiniGame();
    stateMachine.StartNextSection();

    assert(stateMachine.IsAtLastSection() == true);
    stateMachine.PrepareNewSection();
    stateMachine.StartMiniGame();

    stateMachine.FinishGame();
}

void testIllegalTransition() {
    StateMachine stateMachine = StateMachine(2);
    stateMachine.StartGameplay();
    stateMachine.EnterComboMode();
    try {
        stateMachine.PrepareNewSection();
        exit(-1);
    } catch (std::exception& e) {
        std::cout << "Found expected error: " << e.what() << std::endl;
    }
}

void testSectionErrors() {
    StateMachine stateMachine = StateMachine(2);
    stateMachine.StartGameplay();
    stateMachine.EnterComboMode();
    stateMachine.ExitComboMode();

    stateMachine.PrepareNewSection();
    stateMachine.StartMiniGame();
    try {
        stateMachine.FinishGame();
        exit(-1);
    } catch (std::exception& e) {
        std::cout << "Found expected error: " << e.what() << std::endl;
    }
    stateMachine.StartNextSection();
    stateMachine.PrepareNewSection();
    stateMachine.StartMiniGame();
    try {
        stateMachine.StartNextSection();
        exit(-1);
    } catch (std::exception& e) {
        std::cout << "Found expected error: " << e.what() << std::endl;
    }
    stateMachine.FinishGame();
}

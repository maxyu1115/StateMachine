#include <iostream>
#include "StateMachine.h"
using namespace std;

void testNoErrors();

int main() {
    cout << "Hello, World!" << endl;
    testNoErrors();
    return 0;
}

void testNoErrors() {
    StateMachine state_machine = StateMachine(2);
    state_machine.StartGameplay();
    state_machine.EnterComboMode();
    state_machine.ExitComboMode();

    state_machine.PrepareNewSection();
    state_machine.StartMiniGame();
    state_machine.StartNextSection();

    assert(state_machine.IsAtLastSection() == true);
    state_machine.PrepareNewSection();
    state_machine.StartMiniGame();

    state_machine.FinishGame();
}

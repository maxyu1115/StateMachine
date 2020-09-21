//
// Created by Max Yu on 9/20/20.
//

#ifndef STATEMACHINE_STATEMACHINE_H
#define STATEMACHINE_STATEMACHINE_H


enum Mode {
    NotStarted = 0,
    MainGameplay = 1,
    ComboMode = 2,
    Preparing = 3,
    MiniGame = 4,
    Finished = 5
};

class StateMachine {
private:
    int section_count;
    int current_section;
    Mode current_state;
    // performs state transition and throws error if illegal
    void StateTransition(Mode, Mode);
public:
    explicit StateMachine(int);
    Mode GetGameMode();
    int GetCurrentSection() const;
    bool IsAtLastSection() const;
    // states 0 & 1
    void StartGameplay();
    // states 1 & 2
    void EnterComboMode();
    void ExitComboMode();
    // states 1, 3, 4
    void PrepareNewSection();
    void StartMiniGame();
    void StartNextSection();
    // states 4 & 5
    void FinishGame();
};

//class IllegalGameStateException {
//private:
//    const char* msg;
//public:
//    explicit IllegalGameStateException(const char*);
//
//    const char *getMsg() const;
//};

#endif //STATEMACHINE_STATEMACHINE_H

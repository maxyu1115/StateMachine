# StateMachine
Author: Max Yu, https://github.com/maxyu1115

This is a simple 6-state State Machine. State machines are the bread and butter of software development; everything from microwave ovens to NPCs in a triple-A title use them. 

Main features of this state machine:
 - Keeps track of current states
 - Uses a hardcoded transition table to determine what transitions are allowed, and illegal transitions will produce an IllegalGameStateException
 - Notion of sections, which also is a factor between states.

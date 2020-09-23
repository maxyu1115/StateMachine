#StateMachine
Author: Max Yu, https://github.com/maxyu1115

This is a simple 6-state StateMachine. Main features:
 - Keeps track of current states
 - Uses a hardcoded transition table to determine what transitions are allowed, and illegal transitions will produce an IllegalGameStateException
 - Notion of sections, which also is a factor between states.
#include "ActionBasket.h"

#pragma once
namespace ai
{
class Queue
{
public:
    Queue(void) {}
public:
    ~Queue(void) {}
public:
	void Push(ActionBasket *action);
	void Push(ActionBasket **actions);
	ActionNode* Pop();
    ActionBasket* Peek();
	int Size();
private:
	std::list<ActionBasket*> actions;
};
}
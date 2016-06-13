#include "../../pchdef.h"
#include "../playerbot.h"
#include "Action.h"
#include "Queue.h"

using namespace ai;


void Queue::Push(ActionBasket *action)
{
	if (action)
    {
        for (std::list<ActionBasket*>::iterator iter = actions.begin(); iter != actions.end(); iter++)
        {
            ActionBasket* basket = *iter;
            if (action->getAction()->getName() == basket->getAction()->getName())
            {
				if (basket->getRelevance() < action->getRelevance())
					basket->setRelevance(action->getRelevance());
                delete action;
                return;
            }
        }
		actions.push_back(action);
    }
}

void Queue::Push(ActionBasket **actions)
{
	if (actions)
	{
		for (int i=0; i<sizeof(actions)/sizeof(ActionBasket*); i++)
		{
			Push(actions[i]);
		}
	}
}

ActionNode* Queue::Pop()
{
	float max = -1;
	ActionBasket* selection = NULL;
	for (std::list<ActionBasket*>::iterator iter = actions.begin(); iter != actions.end(); iter++)
	{
		ActionBasket* basket = *iter;
		if (basket->getRelevance() > max)
		{
			max = basket->getRelevance();
			selection = basket;
		}
	}
	if (selection != NULL)
	{
		ActionNode* action = selection->getAction();
		actions.remove(selection);
		delete selection;
		return action;
	}
	return NULL;
}

ActionBasket* Queue::Peek()
{
    float max = -1;
    ActionBasket* selection = NULL;
    for (std::list<ActionBasket*>::iterator iter = actions.begin(); iter != actions.end(); iter++)
    {
        ActionBasket* basket = *iter;
        if (basket->getRelevance() > max)
        {
            max = basket->getRelevance();
            selection = basket;
        }
    }
    return selection;
}

int Queue::Size()
{
	return actions.size();
}

#include "../../pchdef.h"
#include "../playerbot.h"
#include "AiObjectContext.h"
#include "Action.h"

using namespace ai;

int NextAction::size(NextAction** actions)
{
    if (!actions)
        return 0;

    int size;
    for (size=0; size<10 && actions[size]; ) 
        size++;
    return size;
}

NextAction** NextAction::clone(NextAction** actions)
{
    if (!actions)
        return NULL;

    int size = NextAction::size(actions);

    NextAction** res = new NextAction*[size + 1];
    for (int i=0; i<size; i++)
        res[i] = new NextAction(*actions[i]);
    res[size] = NULL;
    return res;
}

NextAction** NextAction::merge(NextAction** left, NextAction** right)
{
    int leftSize = NextAction::size(left);
    int rightSize = NextAction::size(right);

    NextAction** res = new NextAction*[leftSize + rightSize + 1];
    for (int i=0; i<leftSize; i++)
        res[i] = new NextAction(*left[i]);
    for (int i=0; i<rightSize; i++)
        res[leftSize + i] = new NextAction(*right[i]);
    res[leftSize + rightSize] = NULL;

    NextAction::destroy(left);
    NextAction::destroy(right);

    return res;
}

NextAction** NextAction::array(uint8 nil, ...)
{
    va_list vl;
    va_start(vl, nil);
    
    int size = 0;
    NextAction* cur = NULL;
    do 
    {
        cur = va_arg(vl, NextAction*);
        size++;
    }
    while (cur);

    va_end(vl);

    NextAction** res = new NextAction*[size];
    va_start(vl, nil);
    for (int i=0; i<size; i++)
        res[i] = va_arg(vl, NextAction*);
    va_end(vl);

    return res;
}

void NextAction::destroy(NextAction** actions)
{
    if (!actions)
        return;

    for (int i=0; i<10 && actions[i]; i++)
        delete actions[i];
}

Value<Unit*>* Action::GetTargetValue()
{
    return context->GetValue<Unit*>(GetTargetName());
}

Unit* Action::GetTarget()
{
    return GetTargetValue()->Get();
}

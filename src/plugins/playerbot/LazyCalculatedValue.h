#pragma once

using namespace std;

namespace ai 
{
    template <class TValue, class TOwner>
    class LazyCalculatedValue
    {
    public:
        typedef TValue (TOwner::*Calculator)();

    public:
        LazyCalculatedValue(TOwner* owner, Calculator calculator) 
        {
            this->calculator = calculator;
            this->owner = owner;
            Reset();
        }

    public:
        TValue GetValue()
        {
            if (!calculated)
            {
                value = (owner->*calculator)();
                calculated = true;
            }
            return value;
        }
        void Reset() 
        {
            calculated = false;
        }

    protected:
        Calculator calculator;
        TOwner* owner;
        bool calculated;
        TValue value;
    };
};
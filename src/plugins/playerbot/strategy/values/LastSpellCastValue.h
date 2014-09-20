#pragma once
#include "../Value.h"

namespace ai
{
    class LastSpellCast 
    {
    public:
        LastSpellCast() : id(0),time(0) {}

    public:
        void Set(uint32 id, ObjectGuid target, time_t time)
        {
            this->id = id;
            this->target = target;
            this->time = time;
        }
        
        void Reset()
        {
            id = 0;
            target.Set(0);
            time = 0;
        }
    public:
        uint32 id;
        ObjectGuid target;
        time_t time;
    };
   
    class LastSpellCastValue : public ManualSetValue<LastSpellCast&>
	{
	public:
        LastSpellCastValue(PlayerbotAI* ai) : ManualSetValue<LastSpellCast&>(ai, data) {}

    private:
        LastSpellCast data;
    };
}

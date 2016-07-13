#pragma once
#include "../Value.h"

namespace ai
{
    class LastMovement
    {
    public:
        LastMovement() 
        {
            lastMoveToX = 0;
            lastMoveToY = 0;
            lastMoveToZ = 0;
            lastMoveToOri = 0;
            lastFollow = NULL;
        }

        LastMovement(LastMovement& other)
        {
            taxiNodes = other.taxiNodes;
            taxiMaster = other.taxiMaster;
            lastFollow = other.lastFollow;
            lastAreaTrigger = other.lastAreaTrigger;
            lastMoveToX = other.lastMoveToX;
            lastMoveToY = other.lastMoveToY;
            lastMoveToZ = other.lastMoveToZ;
            lastMoveToOri = other.lastMoveToOri;
        }
        
        void Set(Unit* lastFollow)
        {
            Set(0.0f, 0.0f, 0.0f, 0.0f);
            this->lastFollow = lastFollow;
        }

        void Set(float x, float y, float z, float ori)
        {
            lastMoveToX = x;
            lastMoveToY = y;
            lastMoveToZ = z;
            lastMoveToOri = ori;
            lastFollow = NULL;
        }

    public:
        vector<uint32> taxiNodes;
        ObjectGuid taxiMaster;
        Unit* lastFollow;
        uint32 lastAreaTrigger;
        float lastMoveToX, lastMoveToY, lastMoveToZ, lastMoveToOri;
    };

    class LastMovementValue : public ManualSetValue<LastMovement&>
	{
	public:
        LastMovementValue(PlayerbotAI* ai) : ManualSetValue<LastMovement&>(ai, data) {}

    private:
        LastMovement data;
    };
}

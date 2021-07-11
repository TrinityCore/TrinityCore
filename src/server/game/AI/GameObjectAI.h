#ifndef _HEADER_GAMEOBJECT_AI
#define _HEADER_GAMEOBJECT_AI

#include "Common.h"

class Unit;
class Creature;
class GameObject;
class ObjectGuid;

class GameObjectAI
{
    public:
        explicit GameObjectAI(GameObject* pGo): me(pGo) {}
        virtual ~GameObjectAI() {}

        virtual void UpdateAI(uint32 const /*uiDiff*/) {}
        virtual void SetData(uint32 /*id*/, uint32 /*value*/) {}
        virtual void InformGuid(ObjectGuid guid) {}
        virtual bool OnUse(Unit* /*user*/) { return false; }

        // Called if a temporary summoned of m_creature reach a move point
        virtual void SummonedMovementInform(Creature* /*summoned*/, uint32 /*motion_type*/, uint32 /*point_id*/) {}

    protected:
        GameObject* me;
};

#endif

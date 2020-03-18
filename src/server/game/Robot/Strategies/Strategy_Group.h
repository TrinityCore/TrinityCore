#ifndef ROBOT_STRATEGIES_PARTY_H
#define ROBOT_STRATEGIES_PARTY_H

#ifndef ASSEMBLE_TELEPORT_MIN_RANGE
# define ASSEMBLE_TELEPORT_MIN_RANGE 100
#endif

#ifndef DEFAULT_DPS_DELAY
# define DEFAULT_DPS_DELAY 500
#endif

#ifndef DEFAULT_AOE_DELAY
# define DEFAULT_AOE_DELAY 4000
#endif

#include "Script_Base.h"
#include "Player.h"

class Strategy_Group
{
public:
    Strategy_Group(Player* pmMe);
    bool GroupInCombat();
    virtual void Update(uint32 pmDiff);
    virtual bool DPS();
    virtual bool Tank();
    virtual bool Rest();
    virtual bool Heal();
    virtual bool Buff();
    virtual bool Follow();

public:
    Player* me;
    int32 combatTime;
    int32 sideDelay;
    int32 moveAssembleDelay;
    int32 teleportAssembleDelay;
    int32 aoeDelay;
    int32 dpsDelay;
    int32 restDelay;
    float followDistance;
    bool staying;
    bool holding;
    bool cure;

    Script_Base* sb;
};

enum SHADOW_LABYRINTH_NPC
{
    SHADOW_LABYRINTH_NPC_VOID_TRAVELER = 19226,
};

class Strategy_Group_Shadow_Labyrinth :public Strategy_Group
{
public:
    Strategy_Group_Shadow_Labyrinth(Player* pmMe) :Strategy_Group(pmMe)
    {
        ogVT = ObjectGuid::Empty;
    }

    bool DPS() override;

    ObjectGuid ogVT;
};
#endif

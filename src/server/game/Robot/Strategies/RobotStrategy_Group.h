#ifndef ROBOT_STRATEGY_GROUP_H
#define ROBOT_STRATEGY_GROUP_H

#include "RobotStrategy_Base.h"

enum CreatureEntry_RobotStrategy :uint32
{
    CreatureEntry_RobotStrategy_Gyth = 10339,
    CreatureEntry_RobotStrategy_Rend = 10429,
    CreatureEntry_RobotStrategy_Drakkisath = 10363,
    CreatureEntry_RobotStrategy_Doctor_Weavil = 15552,
    CreatureEntry_RobotStrategy_Group_Ysondre = 14887,
    CreatureEntry_RobotStrategy_Group_Lethon = 14888,
    CreatureEntry_RobotStrategy_Emeriss = 14889,
    CreatureEntry_RobotStrategy_Group_Taerar = 14890,
    CreatureEntry_RobotStrategy_Dream_Fog = 15224,
    CreatureEntry_RobotStrategy_Demented_Druid = 15260,
    CreatureEntry_RobotStrategy_Shade_of_Taerar = 15302,
    CreatureEntry_RobotStrategy_Spirit_Shade = 15261,
    CreatureEntry_RobotStrategy_Azuregos = 6109,
};

enum GroupRole :uint32
{
    GroupRole_DPS = 0,
    GroupRole_Tank = 1,
    GroupRole_Healer = 2,
};

class EngagePosition
{
public:
    EngagePosition()
    {
        engageAngle = 0.0f;
        engageDistance = 0.0f;
    }

public:
    float engageAngle;
    float engageDistance;
};

class RobotStrategy_Group :public RobotStrategy_Base
{
public:
    RobotStrategy_Group(Player* pmMe) :RobotStrategy_Base(pmMe)
    {
        InitialStrategy();
    }
    void Reset();
    void InitialStrategy();
    bool GroupInCombat();
    bool Lightwell();
    Player* GetPlayerByGroupRole(uint32 pmGroupRole);
    std::unordered_set<Player*> GetPlayerSetByGroupRoleSet(std::unordered_set<uint32> pmGroupRoleSet);
    std::unordered_set<ObjectGuid> GetPlayerGUIDSetByGroupRoleSet(std::unordered_set<uint32> pmGroupRoleSet);

    bool Update0(uint32 pmDiff);
    void Update(uint32 pmDiff) override;

    virtual bool Engage(Unit* pmTarget);
    virtual bool DPS();
    virtual Player* GetMainTank();
    virtual Player* GetSubTank();
    virtual bool Tank();
    virtual bool Tank(Unit* pmTarget);
    virtual bool Rest();
    virtual bool Heal();
    virtual bool Buff();
    virtual bool Follow();
    virtual bool Stay(std::string pmTargetGroupRole);
    virtual bool Hold(std::string pmTargetGroupRole);
    virtual bool Chasing();
    virtual std::string GetGroupRoleName();
    virtual void SetGroupRole(std::string pmRoleName);
    std::unordered_map<ObjectGuid, Unit*> GetAddsMap(uint32 pmBossEntry);
    std::unordered_map<ObjectGuid, Unit*> GetAttackerMap(uint32 pmAttackerEntry);
    std::unordered_map<ObjectGuid, Unit*> GetAttackerMap();
    Unit* GetAttacker(uint32 pmAttackerEntry);
    bool AngleInRange(float pmSourceAngle, float pmTargetAngle, float pmRange);
    Position GetNearPoint(Position pmSourcePosition, float pmDistance, float pmAbsoluteAngle);

public:
    int combatTime;
    int moveDelay;
    int teleportAssembleDelay;
    int aoeDelay;
    int dpsDelay;
    int engageDelay;
    int readyCheckDelay;
    float followDistance;
    bool staying;
    bool holding;
    bool following;
    bool cure;
    uint32 paladinAura;
    bool marked;
    Position markPos;
    Position basePos;

    uint32 actionType;
    int actionDelay;
};
#endif

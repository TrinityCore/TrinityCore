#ifndef ROBOT_STRATEGY_H
#define ROBOT_STRATEGY_H

#ifndef ANGLE_RANGE
# define ANGLE_RANGE M_PI / 16
#endif

#include "Script_Base.h"
#include "Player.h"

enum CreatureEntry_RobotStrategy :uint32
{
    CreatureEntry_RobotStrategy_Gyth = 10339,
    CreatureEntry_RobotStrategy_Rend = 10429,
    CreatureEntry_RobotStrategy_Drakkisath = 10363,
    CreatureEntry_RobotStrategy_Doctor_Weavil = 15552,
    CreatureEntry_RobotStrategy_Ysondre = 14887,
    CreatureEntry_RobotStrategy_Lethon = 14888,
    CreatureEntry_RobotStrategy_Emeriss = 14889,
    CreatureEntry_RobotStrategy_Taerar = 14890,
    CreatureEntry_RobotStrategy_Dream_Fog = 15224,
    CreatureEntry_RobotStrategy_Demented_Druid = 15260,
    CreatureEntry_RobotStrategy_Shade_of_Taerar = 15302,
    CreatureEntry_RobotStrategy_Spirit_Shade = 15261,
    CreatureEntry_RobotStrategy_Azuregos = 6109,
};

enum RobotStrategyType :uint32
{
    RobotStrategyType_All = 0,
    RobotStrategyType_Solo = 1,
    RobotStrategyType_Group = 2,
};

class RobotStrategy
{
public:
    RobotStrategy(Player* pmMe);
    virtual void Update(uint32 pmDiff);

public:
    Player* me;
    Script_Base* sb;
    Unit* engageTarget;

    int restDelay;
    int32 engageDelay;
    uint32 strategyType;
};

enum RobotSoloState :uint32
{
    RobotSoloState_None = 0,
    RobotSoloState_Wander,
    RobotSoloState_Battle,
    RobotSoloState_Rest,
    RobotSoloState_Wait,
    RobotSoloState_Stroll,
    RobotSoloState_Confuse,
};

class RobotStrategy_Solo :public RobotStrategy
{
public:
    RobotStrategy_Solo(Player* pmMe) :RobotStrategy(pmMe)
    {
        InitialStrategy();
    }
    void InitialStrategy();
    void Reset();
    void HandleChatCommand(Player* pmSender, std::string pmCMD);

    void Update(uint32 pmDiff) override;

    virtual bool Buff();
    virtual bool Rest();
    virtual bool PVP();
    virtual bool Battle();
    virtual bool Heal();
    virtual bool Wait();
    virtual bool Stroll();
    virtual bool Confuse();


public:
    uint32 soloState;
    int32 deathDelay;
    int32 soloDelay;
    int32 waitDelay;
    int32 strollDelay;
    int32 confuseDelay;
    int32 interestsDelay;
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

class RobotStrategy_Group :public RobotStrategy
{
public:
    RobotStrategy_Group(Player* pmMe) :RobotStrategy(pmMe)
    {
        InitialStrategy();
    }

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

enum GroupRole_Blackrock_Spire :uint32
{
    GroupRole_Blackrock_Spire_DPS = 0,
    GroupRole_Blackrock_Spire_Tank1 = 1,
    GroupRole_Blackrock_Spire_Tank2 = 2,
    GroupRole_Blackrock_Spire_Tank3 = 3,
    GroupRole_Blackrock_Spire_Healer1 = 4,
    GroupRole_Blackrock_Spire_Healer2 = 5,
};

enum ActionType_Blackrock_Spire :uint32
{
    ActionType_Blackrock_Spire_None = 0,
    ActionType_Blackrock_Spire_TankGythMove,
    ActionType_Blackrock_Spire_TankRendMove,
    ActionType_Blackrock_Spire_DPSGythMove,
    ActionType_Blackrock_Spire_TankDrakkisathMove1,
    ActionType_Blackrock_Spire_TankDrakkisathMove2,
    ActionType_Blackrock_Spire_TankDrakkisathAddsMove,
    ActionType_Blackrock_Spire_DPSDrakkisathMove,
};

class RobotStrategy_Group_Blackrock_Spire :public RobotStrategy_Group
{
public:
    RobotStrategy_Group_Blackrock_Spire(Player* pmMe) :RobotStrategy_Group(pmMe)
    {
        InitialStrategy();
    }

    void InitialStrategy();

    void Update(uint32 pmDiff) override;
    std::string GetGroupRoleName() override;
    void SetGroupRole(std::string pmRoleName) override;
    Player* GetMainTank() override;
    bool DPS() override;
    bool Engage(Unit* pmTarget);
    bool Heal() override;
    bool Tank() override;
    bool Tank(Unit* pmTarget) override;

    Position tankGythPos;
    Position tankRendPos;
    Position dpsGythPos;
    Position tankDrakkisathPos1;
    Position tankDrakkisathPos2;
    Position tankDrakkisathAddsPos;
    Position dpsDrakkisathPos;
};

class RobotStrategy_Group_Alcaz_Island :public RobotStrategy_Group
{
public:
    RobotStrategy_Group_Alcaz_Island(Player* pmMe) :RobotStrategy_Group(pmMe)
    {
        InitialStrategy();
    }

    bool DPS() override;
    bool Tank() override;
};

enum SHADOW_LABYRINTH_NPC
{
    SHADOW_LABYRINTH_NPC_VOID_TRAVELER = 19226,
};

class RobotStrategy_Group_Shadow_Labyrinth :public RobotStrategy_Group
{
public:
    RobotStrategy_Group_Shadow_Labyrinth(Player* pmMe) :RobotStrategy_Group(pmMe)
    {
        InitialStrategy();
    }
};

enum GroupRole_EmeraldDragon :uint32
{
    GroupRole_EmeraldDragon_Tank1 = 0,
    GroupRole_EmeraldDragon_Tank2 = 1,
    GroupRole_EmeraldDragon_Tank3 = 2,
    GroupRole_EmeraldDragon_Tank4 = 3,
    GroupRole_EmeraldDragon_Tank5 = 4,
    GroupRole_EmeraldDragon_Healer1 = 5,
    GroupRole_EmeraldDragon_Healer2 = 6,
    GroupRole_EmeraldDragon_Healer3 = 7,
    GroupRole_EmeraldDragon_Healer4 = 8,
    GroupRole_EmeraldDragon_Healer5 = 9,
    GroupRole_EmeraldDragon_Healer6 = 10,
    GroupRole_EmeraldDragon_Healer7 = 11,
    GroupRole_EmeraldDragon_Healer8 = 12,
    GroupRole_EmeraldDragon_DPS_Range = 13,
    GroupRole_EmeraldDragon_DPS_Melee = 14,
};

enum ActionType_EmeraldDragon :uint32
{
    ActionType_EmeraldDragon_None = 0,
    ActionType_EmeraldDragon_MarkMove,
};

class RobotStrategy_Group_EmeraldDragon :public RobotStrategy_Group
{
public:
    RobotStrategy_Group_EmeraldDragon(Player* pmMe) :RobotStrategy_Group(pmMe)
    {
        InitialStrategy();
    }

    void InitialStrategy();
    std::string GetGroupRoleName() override;
    void SetGroupRole(std::string pmRoleName) override;
    bool Follow() override;
    bool Stay(std::string pmTargetGroupRole) override;
    bool Hold(std::string pmTargetGroupRole) override;
    bool Engage(Unit* pmTarget) override;
    bool DPS() override;
    bool Tank() override;
    bool Tank(Unit* pmTarget) override;
    bool Heal() override;
    void Update(uint32 pmDiff) override;

    float engageAngle;
    float engageDistance;
    uint32 shadeCombatTime;
};

enum GroupRole_Azuregos :uint32
{
    GroupRole_Azuregos_Tank = 0,
    GroupRole_Azuregos_Healer1,
    GroupRole_Azuregos_Healer2,
    GroupRole_Azuregos_DPS,
};

enum ActionType_Azuregos :uint32
{
    ActionType_Azuregos_None = 0,
    ActionType_Azuregos_MarkMove,
};

class RobotStrategy_Group_Azuregos :public RobotStrategy_Group
{
public:
    RobotStrategy_Group_Azuregos(Player* pmMe) :RobotStrategy_Group(pmMe)
    {
        InitialStrategy();
    }

    void InitialStrategy();
    std::string GetGroupRoleName() override;
    void SetGroupRole(std::string pmRoleName) override;
    bool Follow() override;
    bool Stay(std::string pmTargetGroupRole) override;
    bool Hold(std::string pmTargetGroupRole) override;
    bool Engage(Unit* pmTarget) override;
    bool DPS() override;
    bool Tank() override;
    bool Tank(Unit* pmTarget) override;
    bool Heal() override;
    void Update(uint32 pmDiff) override;

    float engageAngle;
    float engageDistance;
};

class RobotStrategy_Group_Test :public RobotStrategy_Group
{
public:
    RobotStrategy_Group_Test(Player* pmMe) :RobotStrategy_Group(pmMe)
    {
        InitialStrategy();
    }

    void InitialStrategy();
    std::string GetGroupRoleName() override;
    void SetGroupRole(std::string pmRoleName) override;
    bool Follow() override;
    bool Stay(std::string pmTargetGroupRole) override;
    bool Hold(std::string pmTargetGroupRole) override;
    bool Engage(Unit* pmTarget) override;
    bool DPS() override;
    bool Tank() override;
    bool Tank(Unit* pmTarget) override;
    bool Heal() override;
    void Update(uint32 pmDiff) override;

    float engageAngle;
    float engageDistance;
    uint32 shadeCombatTime;
};
#endif

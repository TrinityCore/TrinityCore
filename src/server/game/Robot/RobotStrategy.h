#ifndef ROBOT_STRATEGY_H
#define ROBOT_STRATEGY_H

#include "Script_Base.h"
#include "Player.h"

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

    bool Update0(uint32 pmDiff);
    void Update(uint32 pmDiff) override;

    virtual bool Engage(Unit* pmTarget);
    virtual bool DPS();
    virtual Player* GetMainTank();
    virtual bool Tank();
    virtual bool Tank(Unit* pmTarget);
    virtual bool Rest();
    virtual bool Heal();
    virtual bool Buff();
    virtual bool Follow();
    virtual bool Chasing();
    virtual std::string GetGroupRoleName();
    virtual void SetGroupRole(std::string pmRoleName);
    std::unordered_map<ObjectGuid, Unit*> GetAddsMap(uint32 pmBossEntry);
    std::unordered_map<ObjectGuid, Unit*> GetAttackerMap();
    virtual std::unordered_map<uint32, Unit*> GetBossMap();

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
    bool marking;
    bool cure;
    uint32 paladinAura;
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

enum CreatureEntry_Blackrock_Spire :uint32
{
    CreatureEntry_Blackrock_Spire_Gyth = 10339,
    CreatureEntry_Blackrock_Spire_Rend = 10429,
    CreatureEntry_Blackrock_Spire_Drakkisath = 10363,
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
    std::unordered_map<uint32, Unit*> GetBossMap() override;
    Player* GetMainTank() override;
    bool DPS() override;
    bool Engage(Unit* pmTarget);
    bool Heal() override;
    bool Tank() override;
    bool Tank(Unit* pmTarget) override;

    uint32 actionType;
    int actionDelay;
    Position tankGythPos;
    Position tankRendPos;
    Position dpsGythPos;
    Position tankDrakkisathPos1;
    Position tankDrakkisathPos2;
    Position tankDrakkisathAddsPos;
    Position dpsDrakkisathPos;
};

enum CreatureEntry_Alcaz_Island :uint32
{
    CreatureEntry_Alcaz_Island_Doctor_Weavil = 15552,
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

enum CreatureEntry_World_Boss :uint32
{
    CreatureEntry_World_Boss_Ysondre = 14887,    
    CreatureEntry_World_Boss_Lethon = 14888,
    CreatureEntry_World_Boss_Emeriss = 14889,
    CreatureEntry_World_Boss_Taerar = 14890,
    CreatureEntry_World_Boss_Dream_Fog = 15224,
};

enum GroupRole_Ysondre :uint32
{
    GroupRole_Ysondre_Tank1 = 0,
    GroupRole_Ysondre_Tank2 = 1,    
    GroupRole_Ysondre_Healer1 = 2,
    GroupRole_Ysondre_Healer2 = 3,
    GroupRole_Ysondre_DPS_Range = 4,
    GroupRole_Ysondre_DPS_Melee = 5,
};

class RobotStrategy_Group_Ysondre :public RobotStrategy_Group
{
public:
    RobotStrategy_Group_Ysondre(Player* pmMe) :RobotStrategy_Group(pmMe)
    {
        InitialStrategy();
    }

    void InitialStrategy();
    std::string GetGroupRoleName() override;
    void SetGroupRole(std::string pmRoleName) override;
    std::unordered_map<uint32, Unit*> GetBossMap() override;
    Player* GetMainTank() override;
    bool DPS() override;
    bool Tank() override;
    bool Tank(Unit* pmTarget) override;
    bool Heal() override;
    void Update(uint32 pmDiff) override;

    bool positioned;
    Position engagePos;
};
#endif

#ifndef ROBOT_AI_H
#define ROBOT_AI_H

#ifndef AI_CHECK_DELAY
# define AI_CHECK_DELAY 100
#endif

#include "Script_Base.h"
#include "RobotStrategy_Base.h"

enum RobotCharacterType :uint32
{
    RobotCharacterType_DPS = 0,
    RobotCharacterType_TANK = 1,
    RobotCharacterType_HEALER = 2,
};

enum Strategy_Index :uint32
{
    Strategy_Index_Solo = 0,
    Strategy_Index_Group,
    Strategy_Index_Group_BlackrockSpire,
    Strategy_Index_Group_DoctorWeavil,
    Strategy_Index_Group_Lethon,
    Strategy_Index_Group_Ysondre,
    Strategy_Index_Group_Emeriss,
    Strategy_Index_Group_Taerar,
    Strategy_Index_Group_Azuregos,
    Strategy_Index_Group_MoltenCore,
    Strategy_Index_Group_Test,
};

class RobotAI
{
public:
    RobotAI(Player* pmMe);
    void Update(uint32 pmDiff);
    void Reset();

public:
    Player* me;
    Script_Base* sb;
    std::unordered_map<uint32, RobotStrategy_Base*> strategyMap;
    uint32 robotType;
    int checkDelay;
};
#endif

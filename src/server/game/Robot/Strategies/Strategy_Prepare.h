#ifndef ROBOT_STRATEGIES_PREPARE_H
#define ROBOT_STRATEGIES_PREPARE_H

#include "Script_Base.h"

enum RobotPrepareState :uint32
{
    RobotPrepareState_None = 0,
    RobotPrepareState_OffLine,
    RobotPrepareState_Enter,
    RobotPrepareState_CheckAccount,
    RobotPrepareState_CreateAccount,
    RobotPrepareState_CheckCharacter,
    RobotPrepareState_CreateCharacter,
    RobotPrepareState_CheckLogin,
    RobotPrepareState_DoLogin,
    RobotPrepareState_Online,
    RobotPrepareState_Exit,
    RobotPrepareState_CheckLogoff,
    RobotPrepareState_DoLogoff,
};

struct Strategy_Prepare
{
public:
    Strategy_Prepare()
    {

    }

    Strategy_Prepare(uint32 pmEntry);
    void Update();

public:
    uint32 realPrevTime;
    uint32 entry;
    uint32 account;
    uint32 character;    
    uint32 targetLevel;
    int checkDelay;    
    uint32 prepareState;

    Script_Base* sb;
};
#endif

#ifndef ROBOT_STRATEGIES_PREPARE_H
#define ROBOT_STRATEGIES_PREPARE_H

#include "Script_Base.h"

enum RobotPrepareState :uint32
{
    RobotPrepareState_None = 0,
    RobotPrepareState_OffLine,
    RobotPrepareState_CheckAccount,
    RobotPrepareState_CreateAccount,
    RobotPrepareState_CheckCharacter,
    RobotPrepareState_CreateCharacter,
    RobotPrepareState_CheckLogin,
    RobotPrepareState_DoLogin,
    RobotPrepareState_Online,
    RobotPrepareState_CheckLogoff,
    RobotPrepareState_DoLogoff,
};

class Strategy_Prepare
{
public:
    Strategy_Prepare();
    void Update();

public:
    uint32 realPrevTime;
    uint32 account;
    uint32 character;
    uint32 targetClass;
    uint32 targetRace;
    uint32 targetLevel;
    int checkDelay;
    int actionDelay;
    uint32 prepareState;

    Script_Base* s_base;
};
#endif

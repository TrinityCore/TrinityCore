#ifndef ROBOT_ENTITY_H
#define ROBOT_ENTITY_H

enum RobotEntityState :uint32
{
    RobotEntityState_None = 0,
    RobotEntityState_OffLine,
    RobotEntityState_Enter,
    RobotEntityState_CheckAccount,
    RobotEntityState_CreateAccount,
    RobotEntityState_CheckCharacter,
    RobotEntityState_CreateCharacter,    
    RobotEntityState_CheckLogin,
    RobotEntityState_DoLogin,
    RobotEntityState_Initialize,
    RobotEntityState_Online,
    RobotEntityState_Exit,
    RobotEntityState_CheckLogoff,
    RobotEntityState_DoLogoff,
};

class RobotEntity
{
public:
    RobotEntity(uint32 pmRobotID);
    void Update(uint32 pmDiff);

public:
    uint32 robot_id;
    uint32 account_id;
    uint32 character_id;
    uint32 target_level;
    uint32 robot_type;
    int checkDelay;
    uint32 entityState;
};
#endif

#include "RobotEntity.h"
#include "RobotManager.h"
#include "RobotAI_Solo.h"
#include "RobotAI_Group.h"
#include "Group.h"

RobotEntity::RobotEntity(uint32 pmRobotID)
{
    robot_id = pmRobotID;
    account_id = 0;
    character_id = 0;
    target_level = 0;
    checkDelay = 5 * TimeConstants::IN_MILLISECONDS;
    entityState = RobotEntityState::RobotEntityState_OffLine;
}

void RobotEntity::Update(uint32 pmDiff)
{
    checkDelay -= pmDiff;
    if (checkDelay < 0)
    {
        checkDelay = 5 * TimeConstants::IN_MILLISECONDS;
        switch (entityState)
        {
        case RobotEntityState::RobotEntityState_None:
        {
            checkDelay = urand(5 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS);
            break;
        }
        case RobotEntityState::RobotEntityState_OffLine:
        {
            checkDelay = urand(5 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS);
            break;
        }
        case RobotEntityState::RobotEntityState_Enter:
        {
            entityState = RobotEntityState::RobotEntityState_CheckAccount;
            sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot %d is ready to go online.", robot_id);
            break;
        }
        case RobotEntityState::RobotEntityState_CheckAccount:
        {
            if (account_id > 0)
            {
                if (sRobotManager->CheckRobotAccount(account_id))
                {
                    sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot account_id %d is ready.", account_id);
                    entityState = RobotEntityState::RobotEntityState_CheckCharacter;
                }
            }
            else
            {
                sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot account_id level-%d is not ready.", target_level);
                entityState = RobotEntityState::RobotEntityState_CreateAccount;
            }
            break;
        }
        case RobotEntityState::RobotEntityState_CreateAccount:
        {
            account_id = sRobotManager->CreateRobotAccount();
            if (account_id > 0)
            {
                std::ostringstream sqlStream;
                sqlStream << "update robot set account_id = " << account_id << " where robot_id = " << robot_id << ";";
                std::string sql = sqlStream.str();
                CharacterDatabase.DirectExecute(sql.c_str());
                entityState = RobotEntityState::RobotEntityState_CheckAccount;
            }
            else
            {
                entityState = RobotEntityState::RobotEntityState_None;
            }
            break;
        }
        case RobotEntityState::RobotEntityState_CheckCharacter:
        {
            character_id = sRobotManager->CheckAccountCharacter(account_id);
            if (character_id > 0)
            {
                sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot account_id %d character_id %d is ready.", account_id, character_id);
                entityState = RobotEntityState::RobotEntityState_DoLogin;
            }
            else
            {
                sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot account_id %d character_id is not ready.", account_id);
                entityState = RobotEntityState::RobotEntityState_CreateCharacter;
            }
            break;
        }
        case RobotEntityState::RobotEntityState_CreateCharacter:
        {
            character_id = sRobotManager->CreateRobotCharacter(account_id);
            if (character_id > 0)
            {
                std::ostringstream sqlStream;
                sqlStream << "update robot set character_id = " << character_id << " where robot_id = " << robot_id;
                std::string sql = sqlStream.str();
                CharacterDatabase.DirectExecute(sql.c_str());
                entityState = RobotEntityState::RobotEntityState_CheckCharacter;
            }
            else
            {
                entityState = RobotEntityState::RobotEntityState_None;
            }
            break;
        }
        case RobotEntityState::RobotEntityState_DoLogin:
        {
            sRobotManager->LoginRobot(account_id, character_id);
            checkDelay = 10 * TimeConstants::IN_MILLISECONDS;
            entityState = RobotEntityState::RobotEntityState_CheckLogin;
            break;
        }
        case RobotEntityState::RobotEntityState_CheckLogin:
        {
            Player* me = sRobotManager->CheckLogin(account_id, character_id);
            if (me)
            {
                account_id = account_id;
                character_id = character_id;
                RobotAI_Solo* raiSolo = new RobotAI_Solo(me);
                me->raiSolo = raiSolo;
                me->raiSolo->GetActiveStrategy()->sb->InitializeCharacter(target_level);
                RobotAI_Group* raiGroup = new RobotAI_Group(me);
                me->raiGroup = raiGroup;
                me->raiGroup->GetActiveStrategy()->sb->InitializeValues();
                me->groupRole = me->raiGroup->GetActiveStrategy()->sb->characterType;
                if (!me->IsAlive())
                {
                    me->ResurrectPlayer(1.0f);
                }
                me->raiSolo->GetActiveStrategy()->sb->Prepare();
                me->raiSolo->GetActiveStrategy()->sb->RandomTeleport();
                entityState = RobotEntityState::RobotEntityState_Online;
            }
            else
            {
                entityState = RobotEntityState::RobotEntityState_None;
            }
            break;
        }
        case RobotEntityState::RobotEntityState_Online:
        {
            checkDelay = urand(5 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS);
            ObjectGuid guid = ObjectGuid(HighGuid::Player, character_id);
            if (Player* me = ObjectAccessor::FindConnectedPlayer(guid))
            {
                if (Group* myGroup = me->GetGroup())
                {
                    if (Player* leader = ObjectAccessor::FindConnectedPlayer(myGroup->GetLeaderGUID()))
                    {
                        if (leader->GetSession()->isRobotSession)
                        {
                            me->RemoveFromGroup();
                            if (!me->IsAlive())
                            {
                                me->ResurrectPlayer(1.0f);
                            }
                            me->raiSolo->GetActiveStrategy()->sb->Prepare();
                            me->raiSolo->GetActiveStrategy()->sb->RandomTeleport();
                        }
                    }
                    else
                    {
                        me->RemoveFromGroup();
                        if (!me->IsAlive())
                        {
                            me->ResurrectPlayer(1.0f);
                        }
                        me->raiSolo->GetActiveStrategy()->sb->Prepare();
                        me->raiSolo->GetActiveStrategy()->sb->RandomTeleport();
                    }
                    if (me->raiGroup)
                    {
                        me->raiGroup->GetActiveStrategy()->sb->Prepare();
                    }
                }
                else
                {
                    if (me->raiSolo)
                    {
                        me->raiSolo->GetActiveStrategy()->sb->Prepare();
                    }
                }
            }
            break;
        }
        case RobotEntityState::RobotEntityState_Exit:
        {
            ObjectGuid guid = ObjectGuid(HighGuid::Player, character_id);
            if (Player* me = ObjectAccessor::FindConnectedPlayer(guid))
            {
                if (me->GetGroup())
                {
                    entityState = RobotEntityState::RobotEntityState_Online;
                    break;
                }
            }
            sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot %d is ready to go offline.", robot_id);
            entityState = RobotEntityState::RobotEntityState_DoLogoff;
            break;
        }
        case RobotEntityState::RobotEntityState_DoLogoff:
        {
            sRobotManager->LogoutRobot(character_id);
            entityState = RobotEntityState::RobotEntityState_CheckLogoff;
            break;
        }
        case RobotEntityState::RobotEntityState_CheckLogoff:
        {
            ObjectGuid guid = ObjectGuid(HighGuid::Player, character_id);
            if (Player* me = ObjectAccessor::FindConnectedPlayer(guid))
            {
                sLog->outMessage("lfm", LogLevel::LOG_LEVEL_ERROR, "Log out robot %s failed", me->GetName());
                entityState = RobotEntityState::RobotEntityState_None;
                break;
            }
            entityState = RobotEntityState::RobotEntityState_OffLine;
            break;
        }
        default:
        {
            checkDelay = urand(5 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS);
            break;
        }
        }
    }
}

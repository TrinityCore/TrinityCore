#include "Strategy_Prepare.h"
#include "RobotManager.h"
#include "Script_Warrior.h"
#include "Script_Hunter.h"
#include "Script_Shaman.h"
#include "Script_Paladin.h"
#include "Script_Warlock.h"
#include "Script_Priest.h"
#include "Script_Rogue.h"
#include "Script_Mage.h"
#include "Script_Druid.h"
#include "Strategy_Solo.h"
#include "Group.h"

Strategy_Prepare::Strategy_Prepare(uint32 pmEntry)
{
    realPrevTime = getMSTime();
    entry = pmEntry;
    account = 0;
    character = 0;
    checkDelay = 5 * TimeConstants::IN_MILLISECONDS;
    prepareState = RobotPrepareState::RobotPrepareState_OffLine;
    sb = new Script_Base();
}

void Strategy_Prepare::Update()
{
    uint32 realCurrTime = getMSTime();
    uint32 diff = getMSTimeDiff(realPrevTime, realCurrTime);
    realPrevTime = realCurrTime;

    checkDelay -= diff;
    if (checkDelay < 0)
    {
        checkDelay = 5 * TimeConstants::IN_MILLISECONDS;
        switch (prepareState)
        {
        case RobotPrepareState::RobotPrepareState_None:
        {
            break;
        }
        case RobotPrepareState::RobotPrepareState_OffLine:
        {
            break;
        }
        case RobotPrepareState::RobotPrepareState_Enter:
        {
            prepareState = RobotPrepareState::RobotPrepareState_CheckAccount;
            sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot %d is ready to go online.", entry);
            break;
        }
        case RobotPrepareState::RobotPrepareState_CheckAccount:
        {
            if (account > 0)
            {
                if (sRobotManager->CheckRobotAccount(account))
                {
                    sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot account %d is ready.", account);
                    prepareState = RobotPrepareState::RobotPrepareState_CheckCharacter;
                }
            }
            else
            {
                sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot account level-%d is not ready.", targetLevel);
                prepareState = RobotPrepareState::RobotPrepareState_CreateAccount;
            }
            break;
        }
        case RobotPrepareState::RobotPrepareState_CreateAccount:
        {
            account = sRobotManager->CreateRobotAccount();
            if (account > 0)
            {
                std::ostringstream sqlStream;
                sqlStream << "update robot set account_id = " << account << " where entry = " << entry << ";";
                std::string sql = sqlStream.str();
                CharacterDatabase.DirectExecute(sql.c_str());
                prepareState = RobotPrepareState::RobotPrepareState_CheckAccount;
            }
            else
            {
                prepareState = RobotPrepareState::RobotPrepareState_None;
            }
            break;
        }
        case RobotPrepareState::RobotPrepareState_CheckCharacter:
        {
            character = sRobotManager->CheckAccountCharacter(account);
            if (character > 0)
            {
                sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot account %d character %d is ready.", account, character);
                prepareState = RobotPrepareState::RobotPrepareState_DoLogin;
            }
            else
            {
                sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot account %d character is not ready.", account);
                prepareState = RobotPrepareState::RobotPrepareState_CreateCharacter;
            }
            break;
        }
        case RobotPrepareState::RobotPrepareState_CreateCharacter:
        {
            character = sRobotManager->CreateRobotCharacter(account);
            if (character > 0)
            {
                std::ostringstream sqlStream;
                sqlStream << "update robot set character_id = " << character << " where entry = " << entry;
                std::string sql = sqlStream.str();
                CharacterDatabase.DirectExecute(sql.c_str());
                prepareState = RobotPrepareState::RobotPrepareState_CheckCharacter;
            }
            else
            {
                prepareState = RobotPrepareState::RobotPrepareState_None;
            }
            break;
        }
        case RobotPrepareState::RobotPrepareState_DoLogin:
        {
            sRobotManager->LoginRobot(account, character);
            checkDelay = 10 * TimeConstants::IN_MILLISECONDS;
            prepareState = RobotPrepareState::RobotPrepareState_CheckLogin;
            break;
        }
        case RobotPrepareState::RobotPrepareState_CheckLogin:
        {
            Player* me = sRobotManager->CheckLogin(account, character);
            if (me)
            {
                if (me->GetGroup())
                {
                    me->UninviteFromGroup();
                }
                sb->account = account;
                sb->character = character;
                sb->InitializeCharacter(targetLevel);
                if (sRobotManager->soloStrategyMap.find(character) == sRobotManager->soloStrategyMap.end())
                {
                    Strategy_Solo ss(account, character);
                    sRobotManager->soloStrategyMap[character] = ss;
                }
                else
                {
                    sRobotManager->soloStrategyMap[character].account = account;
                    sRobotManager->soloStrategyMap[character].character = character;
                }
                sRobotManager->soloStrategyMap[character].soloState = RobotSoloState::RobotSoloState_Wander;
                prepareState = RobotPrepareState::RobotPrepareState_Online;
            }
            else
            {
                prepareState = RobotPrepareState::RobotPrepareState_None;
            }
            break;
        }
        case RobotPrepareState::RobotPrepareState_Online:
        {
            ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
            if (Player* me = ObjectAccessor::FindConnectedPlayer(guid))
            {
                sb->Prepare();
                if (Group* myGroup = me->GetGroup())
                {
                    if (Player* leader = ObjectAccessor::FindConnectedPlayer(myGroup->GetLeaderGUID()))
                    {
                        if (sRobotManager->IsRobot(leader->GetSession()->GetAccountId()))
                        {
                            me->UninviteFromGroup();
                        }
                    }
                    else
                    {
                        me->UninviteFromGroup();
                    }
                    break;
                }
            }
            checkDelay = urand(5 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS);
            break;
        }
        case RobotPrepareState::RobotPrepareState_Exit:
        {
            ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
            if (Player* me = ObjectAccessor::FindConnectedPlayer(guid))
            {
                if (me->GetGroup())
                {
                    prepareState = RobotPrepareState::RobotPrepareState_Online;
                    break;
                }
            }
            sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot %d is ready to go offline.", entry);
            prepareState = RobotPrepareState::RobotPrepareState_DoLogoff;
            break;
        }
        case RobotPrepareState::RobotPrepareState_DoLogoff:
        {
            sb->Logout();
            prepareState = RobotPrepareState::RobotPrepareState_CheckLogoff;
            break;
        }
        case RobotPrepareState::RobotPrepareState_CheckLogoff:
        {
            ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
            Player* me = ObjectAccessor::FindConnectedPlayer(guid);
            if (me)
            {
                sLog->outMessage("lfm", LogLevel::LOG_LEVEL_ERROR, "Log out robot %s failed", me->GetName());
                prepareState = RobotPrepareState::RobotPrepareState_None;
                break;
            }
            if (sRobotManager->soloStrategyMap.find(character) != sRobotManager->soloStrategyMap.end())
            {
                sRobotManager->soloStrategyMap[character].soloState = RobotSoloState::RobotSoloState_None;
            }
            prepareState = RobotPrepareState::RobotPrepareState_OffLine;
            break;
        }
        default:
        {
            break;
        }
        }
    }
}

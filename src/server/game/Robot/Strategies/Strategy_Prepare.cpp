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

Strategy_Prepare::Strategy_Prepare()
{
    realPrevTime = 0;
    account = 0;
    character = 0;
    checkDelay = 5 * TimeConstants::IN_MILLISECONDS;
    actionDelay = 0;
    prepareState = RobotPrepareState::RobotPrepareState_OffLine;
    s_base = new Script_Base();
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
            if (actionDelay > 0)
            {
                actionDelay -= diff;
                if (actionDelay <= 0)
                {
                    actionDelay = 0;
                    prepareState = RobotPrepareState::RobotPrepareState_CheckAccount;
                    sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot is ready to go online.");
                }
            }
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
                sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot account %d is not ready.", account);
                prepareState = RobotPrepareState::RobotPrepareState_CreateAccount;
            }
            break;
        }
        case RobotPrepareState::RobotPrepareState_CreateAccount:
        {
            account = sRobotManager->CreateRobotAccount();
            if (account > 0)
            {
                prepareState = RobotPrepareState::RobotPrepareState_CheckCharacter;
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
                sLog->outMessage("lfm", LogLevel::LOG_LEVEL_INFO, "Robot account %d character %d is not ready.", account, character);
                prepareState = RobotPrepareState::RobotPrepareState_CreateCharacter;
            }
            break;
        }
        case RobotPrepareState::RobotPrepareState_CreateCharacter:
        {
            character = sRobotManager->CreateRobotCharacter(account, targetClass, targetRace);
            if (character > 0)
            {
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
            prepareState = RobotPrepareState::RobotPrepareState_CheckLogin;
            break;
        }
        case RobotPrepareState::RobotPrepareState_CheckLogin:
        {
            checkDelay = 10 * TimeConstants::IN_MILLISECONDS;
            Player* me = sRobotManager->CheckLogin(account, character);
            if (me)
            {
                WorldSession* mySession = me->GetSession();
                s_base->InitializeCharacter(targetLevel);
                me->SetPvP(true);                
                actionDelay = 0;
                prepareState = RobotPrepareState::RobotPrepareState_Online;

                // todo : new strategy initialize
                if (me->GetGroup())
                {
                    me->UninviteFromGroup();
                }
                if (sRobotManager->soloStrategyMap.find(account) != sRobotManager->soloStrategyMap.end())
                {
                    delete sRobotManager->soloStrategyMap[account];
                    Strategy_Solo* ss = new Strategy_Solo(account, me->GetGUID().GetCounter());
                    sRobotManager->soloStrategyMap[account] = ss;
                    sRobotManager->soloStrategyMap[account]->Reset();
                }
            }
            else
            {
                prepareState = RobotPrepareState::RobotPrepareState_None;
            }
            break;
        }
        case RobotPrepareState::RobotPrepareState_Online:
        {
            checkDelay = 10 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS;
            break;
        }
        case RobotPrepareState::RobotPrepareState_DoLogoff:
        {
            s_base->Logout();
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
            //sRobotManager->robotAICache.erase(accountID);
            actionDelay = 0;
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

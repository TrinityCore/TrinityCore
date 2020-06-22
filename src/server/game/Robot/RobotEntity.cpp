#include "RobotEntity.h"
#include "RobotManager.h"
#include "RobotConfig.h"
#include "RobotAI.h"
#include "Group.h"

RobotEntity::RobotEntity(uint32 pmRobotID)
{
    robot_id = pmRobotID;
    account_id = 0;
    character_id = 0;
    target_level = 0;
    robot_type = 0;
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
            if (robot_type == RobotType::RobotType_World)
            {
                character_id = sRobotManager->CreateRobotCharacter(account_id);
            }
            else if (robot_type == RobotType::RobotType_Raid)
            {
                uint32  targetClass = Classes::CLASS_DRUID;
                while (true)
                {
                    targetClass = urand(Classes::CLASS_WARRIOR, Classes::CLASS_DRUID);
                    if (targetClass == Classes::CLASS_DRUID)
                    {
                        if (urand(0, 1) == 0)
                        {
                            continue;
                        }
                    }
                    else if (targetClass == Classes::CLASS_DEATH_KNIGHT || targetClass == Classes::CLASS_UNK)
                    {
                        targetClass = Classes::CLASS_PRIEST;
                    }
                    else if (targetClass == Classes::CLASS_WARRIOR || targetClass == Classes::CLASS_DEATH_KNIGHT || targetClass == Classes::CLASS_SHAMAN || targetClass == Classes::CLASS_UNK)
                    {
                        continue;
                    }
                    break;
                }
                uint32 raceIndex = urand(0, sRobotManager->availableRaces[targetClass].size() - 1);
                uint32 targetRace = sRobotManager->availableRaces[targetClass][raceIndex];
                character_id = sRobotManager->CreateRobotCharacter(account_id, targetClass, targetRace);
            }
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
            if (sRobotConfig->EnableAlliance == 0 || sRobotConfig->EnableHorde == 0)
            {
                uint32 characterRace = sRobotManager->GetCharacterRace(character_id);
                if (sRobotConfig->EnableAlliance == 0)
                {
                    if (characterRace == Races::RACE_HUMAN || characterRace == Races::RACE_DWARF || characterRace == Races::RACE_NIGHTELF || characterRace == Races::RACE_GNOME || characterRace == Races::RACE_DRAENEI)
                    {
                        checkDelay = 1 * TimeConstants::HOUR * TimeConstants::IN_MILLISECONDS;
                        entityState = RobotEntityState::RobotEntityState_None;
                        break;
                    }
                }
                if (sRobotConfig->EnableHorde == 0)
                {
                    if (characterRace == Races::RACE_ORC || characterRace == Races::RACE_UNDEAD_PLAYER || characterRace == Races::RACE_TAUREN || characterRace == Races::RACE_TROLL || characterRace == Races::RACE_BLOODELF)
                    {
                        checkDelay = 1 * TimeConstants::HOUR * TimeConstants::IN_MILLISECONDS;
                        entityState = RobotEntityState::RobotEntityState_None;
                        break;
                    }
                }
            }
            sRobotManager->LoginRobot(account_id, character_id);
            checkDelay = 10 * TimeConstants::IN_MILLISECONDS;
            entityState = RobotEntityState::RobotEntityState_CheckLogin;
            break;
        }
        case RobotEntityState::RobotEntityState_CheckLogin:
        {
            checkDelay = 5 * TimeConstants::IN_MILLISECONDS;
            Player* me = sRobotManager->CheckLogin(account_id, character_id);
            if (me)
            {
                account_id = account_id;
                character_id = character_id;
                me->rai->robotType = robot_type;
                entityState = RobotEntityState::RobotEntityState_Initialize;
            }
            else
            {
                entityState = RobotEntityState::RobotEntityState_None;
            }
            break;
        }
        case RobotEntityState::RobotEntityState_Initialize:
        {
            checkDelay = 5 * TimeConstants::IN_MILLISECONDS;
            ObjectGuid guid = ObjectGuid(HighGuid::Player, character_id);
            if (Player* me = ObjectAccessor::FindConnectedPlayer(guid))
            {
                if (sRobotManager->InitializeCharacter(me, target_level))
                {
                    entityState = RobotEntityState::RobotEntityState_DoLogoff;
                }
                else
                {
                    me->rai->sb->IdentifyCharacterSpells();
                    me->rai->sb->Reset();
                    entityState = RobotEntityState::RobotEntityState_Online;
                }
                me->groupRole = me->rai->sb->characterType;
            }
            else
            {
                entityState = RobotEntityState::RobotEntityState_None;
            }
            break;
        }
        case RobotEntityState::RobotEntityState_Online:
        {
            checkDelay = urand(10 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS, 20 * TimeConstants::MINUTE * TimeConstants::IN_MILLISECONDS);
            ObjectGuid guid = ObjectGuid(HighGuid::Player, character_id);
            if (Player* me = ObjectAccessor::FindConnectedPlayer(guid))
            {
                sRobotManager->PrepareRobot(me);
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

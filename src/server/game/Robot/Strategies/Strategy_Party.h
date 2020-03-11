#ifndef ROBOT_STRATEGIES_PARTY_H
#define ROBOT_STRATEGIES_PARTY_H

#ifndef DPS_DEFAULT_DELAY_PARTY
# define DPS_DEFAULT_DELAY_PARTY 500
#endif

#ifndef AOE_DEFAULT_DELAY_PARTY
# define AOE_DEFAULT_DELAY_PARTY 4000
#endif

#include "Script_Warrior.h"
#include "Script_Hunter.h"
#include "Script_Shaman.h"
#include "Script_Paladin.h"
#include "Script_Warlock.h"
#include "Script_Priest.h"
#include "Script_Rogue.h"
#include "Script_Mage.h"
#include "Script_Druid.h"
#include "Player.h"

enum PartyRole :uint32
{
    PartyRole_DPS = 0,
    PartyRole_Tank = 1,
    PartyRole_Healer = 2,
};

enum RobotPartyInstructionType :uint32
{
    RobotPartyInstructionType_None = 0,    
    RobotPartyInstructionType_Tank,
    RobotPartyInstructionType_Attack,    
    RobotPartyInstructionType_Engage,
};

struct PartyInstruction
{
public:
    PartyInstruction()
    {
        instructionType = RobotPartyInstructionType::RobotPartyInstructionType_None;
    }

    void Clear()
    {
        instructionType = RobotPartyInstructionType::RobotPartyInstructionType_None;
        targetOG.Clear();
    }

    uint32 instructionType;
    ObjectGuid targetOG;
};

struct PartyMember
{
public:
    PartyMember()
    {

    }

    PartyMember(uint32 pmCharacterID, bool pmIsRobot = true)
    {
        character = pmCharacterID;
        partyRole = 0;
        combatTime = 0;
        assembleDelay = 0;
        restDelay = 0;
        aoeDelay = AOE_DEFAULT_DELAY_PARTY;
        dpsDelay = DPS_DEFAULT_DELAY_PARTY;
        staying = false;
        holding = false;
        cure = true;
        followDistance = FOLLOW_NORMAL_DISTANCE;
        isRobot = pmIsRobot;
        ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
        Player* me = ObjectAccessor::FindConnectedPlayer(guid);
        if (me)
        {
            switch (me->GetClass())
            {
            case Classes::CLASS_WARRIOR:
            {
                sb = new Script_Warrior(character);
                followDistance = MELEE_MIN_DISTANCE;
                break;
            }
            case Classes::CLASS_HUNTER:
            {
                sb = new  Script_Hunter(character);
                break;
            }
            case Classes::CLASS_SHAMAN:
            {
                sb = new  Script_Shaman(character);
                break;
            }
            case Classes::CLASS_PALADIN:
            {
                sb = new  Script_Paladin(character);
                followDistance = MELEE_MIN_DISTANCE;
                break;
            }
            case Classes::CLASS_WARLOCK:
            {
                sb = new  Script_Warlock(character);
                break;
            }
            case Classes::CLASS_PRIEST:
            {
                sb = new  Script_Priest(character);
                break;
            }
            case Classes::CLASS_ROGUE:
            {
                sb = new  Script_Rogue(character);
                followDistance = MELEE_MIN_DISTANCE;
                break;
            }
            case Classes::CLASS_MAGE:
            {
                sb = new  Script_Mage(character);
                break;
            }
            case Classes::CLASS_DRUID:
            {
                sb = new  Script_Druid(character);
                break;
            }
            default:
            {
                sb = new  Script_Base();
                sb->account = me->GetSession()->GetAccountId();
                sb->character = character;
                break;
            }
            }
        }
        sb->InitializeValues();
        partyRole = sb->characterType;
    }

    uint32 character;
    // 0 dps, 1 tank, 2 healer
    uint32 partyRole;
    int32 combatTime;
    int32 assembleDelay;
    int32 aoeDelay;
    int32 dpsDelay;
    int32 restDelay;
    float followDistance;
    PartyInstruction instruction;
    bool staying;
    bool holding;
    bool cure;
    bool isRobot;

    Script_Base* sb;
};

struct Strategy_Party
{
public:
    Strategy_Party()
    {

    }

    Strategy_Party(uint32 pmID);
    void Update();
    bool PartyInCombat(Player* pmChecker);
    Unit* GetTankVictim(Player* pmChecker);
    Unit* GetPartyVictim(Player* pmChecker);
    bool Rest(Player* pmChecker);
    bool Heal(Player* pmChecker);
    bool Buff(Player* pmChecker);
    bool Follow(Player* pmChecker);
    void HandleChatCommand(Player* pmSender, std::string pmCMD, Player* pmReceiver = NULL);

public:
    uint32 realPrevTime;
    uint32 partyID;
    std::unordered_map<uint32, PartyMember> memberMap;
};
#endif

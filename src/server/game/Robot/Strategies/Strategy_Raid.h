#ifndef ROBOT_STRATEGIES_RAID_H
#define ROBOT_STRATEGIES_RAID_H

#ifndef DPS_DEFAULT_DELAY_RAID
# define DPS_DEFAULT_DELAY_RAID 4000
#endif


enum RaidRole :uint32
{
    RaidRole_DPS = 0,
    RaidRole_Tank = 1,
    RaidRole_Healer = 2,
};

enum RobotRaidInstructionType :uint32
{
    RobotRaidInstructionType_None = 0,
    RobotRaidInstructionType_Follow,
    RobotRaidInstructionType_Tank,
    RobotRaidInstructionType_Attack,
    RobotRaidInstructionType_Engage,
};

struct RaidInstruction
{
public:
    RaidInstruction()
    {
        instructionType = RobotRaidInstructionType::RobotRaidInstructionType_None;
    }

    void Clear()
    {
        instructionType = RobotRaidInstructionType::RobotRaidInstructionType_None;
        targetOG.Clear();
    }

    uint32 instructionType;
    ObjectGuid targetOG;
};

struct RaidMember
{
public:
    RaidMember(uint32 pmCharacterID, bool pmIsRobot = true)
    {
        character = pmCharacterID;
        raidRole = 0;
        assembleDelay = 0;
        restDelay = 0;
        dpsDelay = DPS_DEFAULT_DELAY_RAID;
        staying = false;
        holding = false;
        cure = true;
        isRobot = pmIsRobot;

        ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
        Player* me = ObjectAccessor::FindConnectedPlayer(guid);
        if (!me)
        {
            return;
        }
        switch (me->GetClass())
        {
        case Classes::CLASS_WARRIOR:
        {
            sb = new Script_Warrior(character);
            break;
        }
        case Classes::CLASS_HUNTER:
        {
            sb = new Script_Hunter(character);
            break;
        }
        case Classes::CLASS_SHAMAN:
        {
            sb = new Script_Shaman(character);
            break;
        }
        case Classes::CLASS_PALADIN:
        {
            sb = new Script_Paladin(character);
            break;
        }
        case Classes::CLASS_WARLOCK:
        {
            sb = new Script_Warlock(character);
            break;
        }
        case Classes::CLASS_PRIEST:
        {
            sb = new Script_Priest(character);
            break;
        }
        case Classes::CLASS_ROGUE:
        {
            sb = new Script_Rogue(character);
            break;
        }
        case Classes::CLASS_MAGE:
        {
            sb = new Script_Mage(character);
            break;
        }
        case Classes::CLASS_DRUID:
        {
            sb = new Script_Druid(character);
            break;
        }
        }
        sb->InitializeCharacter(me->GetLevel());
        raidRole = sb->characterType;
    }

    uint32 character;
    // 0 dps, 1 tank, 2 healer
    uint32 raidRole;

    int32 assembleDelay;
    int32 dpsDelay;
    int32 restDelay;
    float followDistance;

    RaidInstruction instruction;
    bool staying;
    bool holding;
    bool cure;
    bool isRobot;

    Script_Base* sb;
};


class Strategy_Raid
{
public:
    Strategy_Raid(uint32 pmID);
    void Update();
    bool RaidInCombat();

    void HandleChatCommand(Player* pmSender, std::string pmCMD);

public:
    uint32 realPrevTime;
    uint32 raidID;
    int32 raidCombatTime;
    std::unordered_map<uint32, RaidMember*> memberMap;
};
#endif

#ifndef ROBOT_STRATEGIES_PARTY_H
#define ROBOT_STRATEGIES_PARTY_H

#ifndef DPS_DEFAULT_DELAY
# define DPS_DEFAULT_DELAY 4000
#endif

enum PartyRole :uint32
{
    PartyRole_DPS = 0,
    PartyRole_Tank = 1,
    PartyRole_Healer = 2,
};

enum RobotPartyState :uint32
{
    RobotPartyState_None = 0,
    RobotPartyState_Idle,
    RobotPartyState_Battle,
    RobotPartyState_Rest,
};

struct PartyMember
{
public:
    PartyMember(uint32 pmCharacterID)
    {
        character = pmCharacterID;
        partyRole = 0;
        assembleDelay = 0;
        dpsDelay = DPS_DEFAULT_DELAY;
        partyCombatTime = 0;
        partyState = RobotPartyState::RobotPartyState_Idle;
        staying = false;
        holding = false;
        cure = true;

        ObjectGuid guid = ObjectGuid(HighGuid::Player, character);
        Player* me = ObjectAccessor::FindConnectedPlayer(guid);
        if (!me)
        {
            partyState = RobotPartyState::RobotPartyState_None;
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
    }

    uint32 character;
    // 0 dps, 1 tank, 2 healer
    uint32 partyRole;

    int32 assembleDelay;
    int32 dpsDelay;
    int32 partyCombatTime;

    uint32 partyState;
    bool staying;
    bool holding;
    bool cure;

    Script_Base* sb;
};

class Strategy_Party
{
public:
    Strategy_Party(uint32 pmID);    
    void Update();
    std::unordered_map<uint32, PartyMember*> GetPartyMapByRole(uint32 pmRole);
    bool Rest(bool pmForce = false);
    bool Buff();    
    bool Battle();
    bool DPS();
    bool DPS(Unit* pmTarget);
    bool Tank();
    bool Tank(Unit* pmTarget);
    bool Attack(Unit* pmTarget);
    bool Healer();
    bool Follow();
    bool Follow(float pmFollowDistance);
    bool Stay();

public:
    uint32 realPrevTime;
    uint32 partyID;        
    std::unordered_map<uint32, PartyMember*> memberMap;
};
#endif

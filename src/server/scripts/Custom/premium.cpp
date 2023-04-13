#include "Define.h"
#include "GossipDef.h"
#include "Item.h"
#include "Player.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "Configuration/Config.h"
#include "DatabaseEnv.h"
#include "Config.h"
#include "World.h"
#include "WorldSession.h"
#include "Chat.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "TemporarySummon.h"

enum Vendors
{
    NPC_VENDOR_A = 54,
    NPC_VENDOR_H = 3163,
    NPC_AUCTION_H = 9856,
    NPC_AUCTION_A = 8670
};

enum Trainers
{
    // Alliance
    DRUID_A = 5504,
    HUNTER_A = 5515,
    MAGE_A = 5497,
    PALADIN_A = 928,
    PRIEST_A = 376,
    ROGUE_A = 918,
    SHAMAN_A = 20407,
    WARLOCK_A = 461,
    WARRIOR_A = 5479,

    // Horde
    DRUID_H = 3033,
    HUNTER_H = 3406,
    MAGE_H = 5883,
    PALADIN_H = 23128,
    PRIEST_H = 3045,
    ROGUE_H = 3401,
    SHAMAN_H = 3344,
    WARLOCK_H = 3324,
    WARRIOR_H = 3354,

    DEATHKNIGHT_AH = 28472
};

enum Mounts
{
    HUMAN_MOUNT = 470,
    ORC_MOUNT = 6653,
    GNOME_MOUNT = 17454,
    NIGHTELF_MOUNT = 8394,
    DWARF_MOUNT = 6899,
    UNEAD_MOUNT = 17463,
    TAUREN_MOUNT = 64657,
    TROLL_MOUNT = 8395,
    BLOODELF_MOUNT = 35022,
    DRAENEI_MOUNT = 34406
};

class premium_account : public PlayerScript
{
public:
    premium_account() : PlayerScript("premium_account") { }

    bool OnUse(Player* player, Item* item, SpellCastTargets const& /*targets*/)
    {
        if (!sConfigMgr->GetBoolDefault("PremiumAccount", true))
            return false;

        QueryResult result = CharacterDatabase.PQuery("SELECT AccountId FROM premium WHERE active = 1 AND AccountId = %u", player->GetSession()->GetAccountId());

        if (!result)
            return false;

        if (player->IsInCombat())
            return false;

        float rangeCheck = 10.0f;
        if (player->FindNearestCreature(NPC_AUCTION_A, rangeCheck) ||
            player->FindNearestCreature(NPC_AUCTION_H, rangeCheck) ||
            player->FindNearestCreature(NPC_VENDOR_A, rangeCheck) ||
            player->FindNearestCreature(NPC_VENDOR_H, rangeCheck) ||
            player->FindNearestCreature(ROGUE_A, rangeCheck) ||
            player->FindNearestCreature(WARRIOR_A, rangeCheck) ||
            player->FindNearestCreature(HUNTER_A, rangeCheck) ||
            player->FindNearestCreature(PRIEST_A, rangeCheck) ||
            player->FindNearestCreature(PALADIN_A, rangeCheck) ||
            player->FindNearestCreature(DRUID_A, rangeCheck) ||
            player->FindNearestCreature(SHAMAN_A, rangeCheck) ||
            player->FindNearestCreature(MAGE_A, rangeCheck) ||
            player->FindNearestCreature(WARLOCK_A, rangeCheck) ||
            player->FindNearestCreature(HUNTER_H, rangeCheck) ||
            player->FindNearestCreature(WARRIOR_H, rangeCheck) ||
            player->FindNearestCreature(SHAMAN_H, rangeCheck) ||
            player->FindNearestCreature(PALADIN_H, rangeCheck) ||
            player->FindNearestCreature(ROGUE_H, rangeCheck) ||
            player->FindNearestCreature(WARLOCK_H, rangeCheck) ||
            player->FindNearestCreature(MAGE_H, rangeCheck) ||
            player->FindNearestCreature(PRIEST_H, rangeCheck) ||
            player->FindNearestCreature(DRUID_H, rangeCheck) ||
            player->FindNearestCreature(DEATHKNIGHT_AH, rangeCheck))
            return false;

        player->PlayerTalkClass->ClearMenus();

        if (sConfigMgr->GetBoolDefault("Morph", true))
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Morph", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Demorph", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
        }

        if (sConfigMgr->GetBoolDefault("Mount", true))
            AddGossipItemFor(player, GOSSIP_ICON_CHAT_16, "Mount", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);

        if (sConfigMgr->GetBoolDefault("Trainers", true))
            AddGossipItemFor(player, GOSSIP_ICON_TRAINER, GOSSIP_TEXT_TRAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);

        if (sConfigMgr->GetBoolDefault("PlayerInteraction", true))
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Player interactions", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);

        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, item->GetGUID());

        return false; // Cast the spell on use normally
    }

    //void OnGossipSelect(Player* player, Item* item, uint32 sender, uint32 action)   
    //{
    //    switch (action)
    //    {
    //    case GOSSIP_ACTION_INFO_DEF + 1: /*Morph*/
    //    {
    //        CloseGossipMenuFor(player);
    //        ApplyRandomMorph(player);
    //        break;
    //    }
    //    case GOSSIP_ACTION_INFO_DEF + 2: /*Demorph*/
    //    {
    //        player->DeMorph();
    //        CloseGossipMenuFor(player);
    //        break;
    //    }
    //    case GOSSIP_ACTION_INFO_DEF + 3: /*Show Bank*/
    //    {
    //        player->GetSession()->SendShowBank(player->GetGUID());
    //        break;
    //    }
    //    case GOSSIP_ACTION_INFO_DEF + 4: /*Mail Box*/
    //    {
    //        player->GetSession()->SendShowMailBox(player->GetGUID());
    //        break;
    //    }
    //    case GOSSIP_ACTION_INFO_DEF + 5: /*Vendor*/
    //    {
    //        uint32 vendorId = 0;
    //        std::string salute;
    //        if (player->GetTeamId() == TEAM_ALLIANCE)
    //        {
    //            vendorId = NPC_VENDOR_A;
    //            salute = "Greetings";
    //        }
    //        else {
    //            vendorId = NPC_VENDOR_H;
    //            salute = "Zug zug";
    //        }

    //        SummonTempNPC(player, vendorId, salute.c_str());
    //        CloseGossipMenuFor(player);
    //        break;
    //    }
    //    case GOSSIP_ACTION_INFO_DEF + 6: /*Mount*/
    //    {
    //        CloseGossipMenuFor(player);
    //        switch (player->getRace())
    //        {
    //        case RACE_HUMAN:         player->CastSpell(player, HUMAN_MOUNT); break;
    //        case RACE_ORC:           player->CastSpell(player, ORC_MOUNT); break;
    //        case RACE_GNOME:         player->CastSpell(player, GNOME_MOUNT); break;
    //        case RACE_NIGHTELF:      player->CastSpell(player, NIGHTELF_MOUNT); break;
    //        case RACE_DWARF:         player->CastSpell(player, DWARF_MOUNT); break;
    //        case RACE_DRAENEI:       player->CastSpell(player, DRAENEI_MOUNT); break;
    //        case RACE_UNDEAD_PLAYER: player->CastSpell(player, UNEAD_MOUNT); break;
    //        case RACE_TAUREN:        player->CastSpell(player, TAUREN_MOUNT); break;
    //        case RACE_TROLL:         player->CastSpell(player, TROLL_MOUNT); break;
    //        case RACE_BLOODELF:      player->CastSpell(player, BLOODELF_MOUNT); break;
    //        }
    //        break;
    //    }
    //    case GOSSIP_ACTION_INFO_DEF + 7: /*Auction House*/
    //    {
    //        uint32 auctionId = 0;
    //        std::string salute;
    //        if (player->GetTeamId() == TEAM_HORDE)
    //        {
    //            auctionId = NPC_AUCTION_H;
    //            salute = "I will go shortly, I need to get back to Orgrimmar";
    //        }
    //        else
    //        {
    //            auctionId = NPC_AUCTION_A;
    //            salute = "I will go shortly, I need to get back to Stormwind City";
    //        }

    //        SummonTempNPC(player, auctionId, salute.c_str());
    //        CloseGossipMenuFor(player);
    //        break;
    //    }
    //    case GOSSIP_ACTION_INFO_DEF + 8: /* Class Trainers*/
    //    {
    //        uint32 trainerId = 0;
    //        switch (player->getClass())
    //        {
    //        case CLASS_ROGUE:
    //            trainerId = player->GetTeamId() == TEAM_ALLIANCE ? ROGUE_A : ROGUE_H;
    //            break;
    //        case CLASS_WARRIOR:
    //            trainerId = player->GetTeamId() == TEAM_ALLIANCE ? WARRIOR_A : WARRIOR_H;
    //            break;
    //        case CLASS_PRIEST:
    //            trainerId = player->GetTeamId() == TEAM_ALLIANCE ? PRIEST_A : PRIEST_H;
    //            break;
    //        case CLASS_MAGE:
    //            trainerId = player->GetTeamId() == TEAM_ALLIANCE ? MAGE_A : MAGE_H;
    //            break;
    //        case CLASS_PALADIN:
    //            trainerId = player->GetTeamId() == TEAM_ALLIANCE ? PALADIN_A : PALADIN_H;
    //            break;
    //        case CLASS_HUNTER:
    //            trainerId = player->GetTeamId() == TEAM_ALLIANCE ? HUNTER_A : HUNTER_H;
    //            break;
    //        case CLASS_DRUID:
    //            trainerId = player->GetTeamId() == TEAM_ALLIANCE ? DRUID_A : DRUID_H;
    //            break;
    //        case CLASS_SHAMAN:
    //            trainerId = player->GetTeamId() == TEAM_ALLIANCE ? SHAMAN_A : SHAMAN_H;
    //            break;
    //        case CLASS_WARLOCK:
    //            trainerId = player->GetTeamId() == TEAM_ALLIANCE ? WARLOCK_A : WARLOCK_H;
    //            break;
    //        case CLASS_DEATH_KNIGHT:
    //            trainerId = DEATHKNIGHT_AH;
    //            break;
    //        }

    //        SummonTempNPC(player, trainerId);
    //        CloseGossipMenuFor(player);
    //        break;
    //    }
    //    case GOSSIP_ACTION_INFO_DEF + 9: /*Player Interactions*/
    //    {
    //        player->PlayerTalkClass->ClearMenus();

    //        if (sConfigMgr->GetBoolDefault("Vendor", true))
    //            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Vendor", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);

    //        if (sConfigMgr->GetBoolDefault("MailBox", true))
    //            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Mail Box", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);

    //        if (sConfigMgr->GetBoolDefault("Bank", true))
    //            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Show Bank", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);

    //        if (sConfigMgr->GetBoolDefault("Auction", true))
    //            AddGossipItemFor(player, GOSSIP_ICON_VENDOR, "Auction House", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);

    //        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, item->GetGUID());
    //        break;
    //    }
    //    }
    //}

    void ApplyRandomMorph(Player* player)
    {
        uint32 random = (urand(1, 26)); // Change this line when adding more morphs
        {
            switch (random)
            {
            case 1: player->SetDisplayId(10134); break;     // Troll Female                 'Orb of Deception'
            case 2: player->SetDisplayId(10135); break;     // Troll Male                   'Orb of Deception'
            case 3: player->SetDisplayId(10136); break;     // Tauren Male                  'Orb of Deception'
            case 4: player->SetDisplayId(10137); break;     // Human Male                   'Orb of Deception'
            case 5: player->SetDisplayId(10138); break;     // Human Female                 'Orb of Deception'
            case 6: player->SetDisplayId(10139); break;     // Orc Male                     'Orb of Deception'
            case 7: player->SetDisplayId(10140); break;     // Orc Female                   'Orb of Deception' 
            case 8: player->SetDisplayId(10141); break;     // Dwarf Male                   'Orb of Deception'
            case 9: player->SetDisplayId(10142); break;     // Dwarf Female                 'Orb of Deception' 
            case 10: player->SetDisplayId(10143); break;    // NightElf Male                'Orb of Deception'
            case 11: player->SetDisplayId(10144); break;    // NightElf Female              'Orb of Deception'
            case 12: player->SetDisplayId(10145); break;    // Undead Female                'Orb of Deception'
            case 13: player->SetDisplayId(10146); break;    // Undead Male                  'Orb of Deception'
            case 14: player->SetDisplayId(10147); break;    // Tauren Female                'Orb of Deception'
            case 15: player->SetDisplayId(10148); break;    // Gnome Male                   'Orb of Deception'
            case 16: player->SetDisplayId(10149); break;    // Gnome Female                 'Orb of Deception'
            case 17: player->SetDisplayId(4527); break;     // Thrall                       'Orgrimmar Boss'
            case 18: player->SetDisplayId(11657); break;    // Lady Sylvanas                'Undercity Boss'
            case 19: player->SetDisplayId(4307); break;     // Cairne Bloodhoof             'Thunderbluff Boss'
            case 20: player->SetDisplayId(17122); break;    // Lorthemar Theron            'Silvermoon City Boss'
            case 21: player->SetDisplayId(3597); break;     // King Magni Bronzebeard       'Ironforge Boss'
            case 22: player->SetDisplayId(5566); break;     // Highlord Bolvar Fordragon    'Stormwind Boss'
            case 23: player->SetDisplayId(7006); break;     // High Tinker Mekkatorque      'Gnomer Boss'
            case 24: player->SetDisplayId(7274); break;     // Tyrande Whisperwind          'Darnassus Boss'
            case 25: player->SetDisplayId(21976); break;    // Arthus Small                 'Arthus'
            case 26: player->SetDisplayId(24641); break;    // Arthus Ghost                 'Arthus Ghost'

            default:
                break;
            }
        }
    }

    void SummonTempNPC(Player* player, uint32 entry, const char* /*salute = 0*/)
    {
        if (!player || entry == 0)
            return;

        int npcDuration = sConfigMgr->GetIntDefault("Premium.NpcDuration", 60) * IN_MILLISECONDS;
        if (npcDuration <= 0) // Safeguard
            npcDuration = 60;

        TempSummon* npc = player->SummonCreature(entry, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, npcDuration,ObjectGuid::Empty);
        //npc->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        npc->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
        npc->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, player->GetFollowAngle());
        npc->SetFaction(player->GetFaction());

    }
};

void AddSC_premium_account()
{
    new premium_account();
}

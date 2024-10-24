#include "AccountMgr.h"
#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Common.h"
#include "Chat.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SharedDefines.h"
#include "World.h"
#include "WorldSession.h"
#include "DBCStores.h"
#include "SpellMgr.h"

class Trinitycore_Paymaster_announce : public PlayerScript
{
public:
    Trinitycore_Paymaster_announce() : PlayerScript("Trinitycore_Paymaster_announce") { }

    void OnLogin(Player* Player, bool /*firstLogin*/) override
    {
        if (sConfigMgr->GetBoolDefault("Paymaster.Announce.Enable", true))
        {
            ChatHandler(Player->GetSession()).SendSysMessage("This server is running the |cff4CFF00Trinitycore Paymaster NPC |rmodule.");
        }
    }
};

class npc_paymaster : public CreatureScript
{
public:

    npc_paymaster() : CreatureScript("npc_paymaster") { }

    struct npc_paymasterAI : public ScriptedAI
    {
        npc_paymasterAI(Creature* creature) : ScriptedAI(creature) { }

        bool OnGossipHello(Player* player) override
        {
            if (player->IsInCombat())
            {
                ClearGossipMenuFor(player);
                ChatHandler(player->GetSession()).PSendSysMessage("You are still in combat!");
            }
            else
            {
                const int32 addGold = sConfigMgr->GetIntDefault("Paymaster.AddGold", 5000);

                std::ostringstream goldMessage;
                goldMessage << "I want " << addGold << " gold";

                AddGossipItemFor(player, GOSSIP_ICON_MONEY_BAG, goldMessage.str(), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
                AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want to learn a Profession", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want to align with the Aldor", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want to align with the Scryer", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want Outland Reputations", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
                AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want to align with the Frenzyheart Tribe", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
                AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want to align with the Oracles", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
                AddGossipItemFor(player, GOSSIP_ICON_TRAINER, "I want Northrend Reputations", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
                SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
            }
            return true;
        }

        bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);

            //just canceling if they already have 2 primary professions
            if (action >= GOSSIP_ACTION_INFO_DEF + 20 && player->GetFreePrimaryProfessionPoints() == 0)
            {
                CloseGossipMenuFor(player);
                return false;
            }

            const int32 addGold = sConfigMgr->GetIntDefault("Paymaster.AddGold", 5000);

            switch (action)
            {
            case GOSSIP_ACTION_INFO_DEF:
                player->ModifyMoney(addGold*10000);
                break;
            case GOSSIP_ACTION_INFO_DEF + 1:
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Alchemy", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 22);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Blacksmithing", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 23);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Cooking", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 18);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Enchanting", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 24);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Engineering", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 25);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "First Aid", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 17);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Fishing", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 19);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Herbalism", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 26);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Inscription", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 21);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Jewelcrafting", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 20);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Leatherworking", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 27);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Mining", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 28);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Skinning", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 29);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Tailoring", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
                SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
                return true;
            case GOSSIP_ACTION_INFO_DEF + 2: // aldor
                player->SetReputation(932, 84000);
                break;
            case GOSSIP_ACTION_INFO_DEF + 3: // scryer
                player->SetReputation(934, 84000);
                break;
            case GOSSIP_ACTION_INFO_DEF + 4: // outland misc
                player->SetReputation(933, 84000); // consortium
                player->SetReputation(935, 84000); // shatar
                player->SetReputation(942, 84000); // cenarion
                player->SetReputation(967, 84000); // violet eye
                player->SetReputation(970, 84000); // sporegar
                player->SetReputation(989, 84000); // keepers of time
                player->SetReputation(990, 84000); // scale of sands
                player->SetReputation(1011, 84000); // lower city
                player->SetReputation(1012, 84000); // ashtounge
                player->SetReputation(1015, 84000); // netherwing
                player->SetReputation(1031, 84000); // Skyguard
                player->SetReputation(1038, 84000); // ogrila
                player->SetReputation(1077, 84000); // shattered sun
                if (player->GetFaction() == ALLIANCE)
                {
                    player->SetReputation(946, 84000); // honor hold
                    player->SetReputation(978, 84000); // kureni
                }
                else
                {
                    player->SetReputation(947, 84000); // thrallmar
                    player->SetReputation(941, 84000); // mag'har
                }
                break;
            case GOSSIP_ACTION_INFO_DEF + 5:
                player->SetReputation(1104, 84000); // frenzyheart tribe
                break;
            case GOSSIP_ACTION_INFO_DEF + 6:
                player->SetReputation(1105, 84000); // oracles
                break;
            case GOSSIP_ACTION_INFO_DEF + 7: // northrend misc
                player->SetReputation(1073, 84000); // kaluk
                player->SetReputation(1090, 84000); // kirin tor
                player->SetReputation(1091, 84000); // wyrmrest accord
                player->SetReputation(1098, 84000); // ebon blade
                player->SetReputation(1106, 84000); // argent crusade
                player->SetReputation(1119, 84000); // sons of hodir
                player->SetReputation(1156, 84000); // ashen verdict
                if (player->GetTeam() == ALLIANCE)
                {
                    player->SetReputation(1050, 86000); // valiance expedition
                    player->SetReputation(1068, 86000); // explorers league
                    player->SetReputation(1094, 86000); // silver covenant
                }
                else
                {
                    player->SetReputation(1064, 86000); // taunka
                    player->SetReputation(1067, 86000); // hand of vengeance
                    player->SetReputation(1085, 86000); // warsong offensive
                    player->SetReputation(1124, 86000); // sunreavers
                }
                break;
            case GOSSIP_ACTION_INFO_DEF + 17: // first aid
                player->LearnSpell(45542, true);
                player->SetSkill(129, 1, 450, 450);
                HandleLearnSkillRecipesHelper(player, 129);
                break;
            case GOSSIP_ACTION_INFO_DEF + 18: // cooking
                player->LearnSpell(51296, true);
                player->SetSkill(185, 1, 450, 450);
                HandleLearnSkillRecipesHelper(player, 185);
                break;
            case GOSSIP_ACTION_INFO_DEF + 19: // fishing
                player->LearnSpell(51294, true); // grandmaster
                player->LearnSpell(43308, true); // find fish
                player->SetSkill(356, 1, 450, 450);
                break;
            case GOSSIP_ACTION_INFO_DEF + 20: // jc
                player->LearnSpell(51311, true);
                player->SetSkill(755, 1, 450, 450);
                HandleLearnSkillRecipesHelper(player, 755);
                break;
            case GOSSIP_ACTION_INFO_DEF + 21: // inscription
                player->LearnSpell(45363, true);
                player->SetSkill(773, 1, 450, 450);
                HandleLearnSkillRecipesHelper(player, 773);
                break;
            case GOSSIP_ACTION_INFO_DEF + 22: // alchemy
                player->LearnSpell(51304, true);
                player->SetSkill(171, 1, 450, 450);
                HandleLearnSkillRecipesHelper(player, 171);
                break;
            case GOSSIP_ACTION_INFO_DEF + 23: // blacksmithing
                player->LearnSpell(51300, true);
                player->SetSkill(164, 1, 450, 450);
                HandleLearnSkillRecipesHelper(player, 164);
                break;
            case GOSSIP_ACTION_INFO_DEF + 24: // enchanting
                player->LearnSpell(51313, true);
                player->SetSkill(333, 1, 450, 450);
                HandleLearnSkillRecipesHelper(player, 333);
                break;
            case GOSSIP_ACTION_INFO_DEF + 25: // engineering
                player->LearnSpell(51306, true);
                player->SetSkill(202, 1, 450, 450);
                HandleLearnSkillRecipesHelper(player, 202);
                break;
            case GOSSIP_ACTION_INFO_DEF + 26: // herbalism
                player->LearnSpell(50300, true);
                player->SetSkill(182, 1, 450, 450);
                HandleLearnSkillRecipesHelper(player, 182);
                break;
            case GOSSIP_ACTION_INFO_DEF + 27: // leatherworking
                player->LearnSpell(51302, true);
                player->SetSkill(165, 1, 450, 450);
                HandleLearnSkillRecipesHelper(player, 165);
                break;
            case GOSSIP_ACTION_INFO_DEF + 28: // mining
                player->LearnSpell(50310, true);
                player->SetSkill(186, 1, 450, 450);
                HandleLearnSkillRecipesHelper(player, 186);
                break;
            case GOSSIP_ACTION_INFO_DEF + 29: // skinning
                player->LearnSpell(50305, true);
                player->SetSkill(393, 1, 450, 450);
                HandleLearnSkillRecipesHelper(player, 393);
                break;
            case GOSSIP_ACTION_INFO_DEF + 30: // tailoring
                player->LearnSpell(51309, true);
                player->SetSkill(197, 1, 450, 450);
                HandleLearnSkillRecipesHelper(player, 197);
                break;
            default:
                CloseGossipMenuFor(player);
                return false;
            }
            CloseGossipMenuFor(player);
            return true;
        }

        static void HandleLearnSkillRecipesHelper(Player* player, uint32 skillId)
        {
            uint32 classmask = player->GetClassMask();

            for (uint32 j = 0; j < sSkillLineAbilityStore.GetNumRows(); ++j)
            {
                SkillLineAbilityEntry const* skillLine = sSkillLineAbilityStore.LookupEntry(j);
                if (!skillLine)
                    continue;

                // wrong skill
                if (skillLine->SkillLine != skillId)
                    continue;

                // not high rank
                if (skillLine->SupercededBySpell)
                    continue;

                // skip racial skills
                if (skillLine->RaceMask != 0)
                    continue;

                // skip wrong class skills
                if (skillLine->ClassMask && (skillLine->ClassMask & classmask) == 0)
                    continue;

                SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(skillLine->Spell);
                if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo, player, false))
                    continue;

                player->LearnSpell(skillLine->Spell, false);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_paymasterAI(creature);
    }
};

void Add_paymaster_npc()
{
    new Trinitycore_Paymaster_announce();
    new npc_paymaster();
}

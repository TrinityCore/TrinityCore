//###################################################################################################################################################################
//Stitch Decembre 2020 - npc_innkeeper_new - version 1.0 , wow 9.0.2.36949 
// Remplace l'aubergiste bugué , donne une pierre de foyer
// UPDATE `creature_template` SET `ScriptName` = 'npc_innkeeper_new' WHERE `subname` LIKE '%innkeeper%';
//###################################################################################################################################################################


#include "ScriptMgr.h"
#include "GameEventMgr.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "WorldSession.h"

enum Spells
{
    SPELL_TRICK_OR_TREATED      = 24755,
    SPELL_TREAT                 = 24715
};

#define LOCALE_TRICK_OR_TREAT_0 "Trick or Treat!"
#define LOCALE_TRICK_OR_TREAT_2 "Des bonbons ou des blagues!"

#define LOCALE_INNKEEPER_0 "Make this inn your home."
#define LOCALE_INNKEEPER_2 "Faire de cette auberge votre foyer."

#define LOCALE_VENDOR_0 "Let me browse your goods."
#define LOCALE_VENDOR_2 "Laissez-moi jeter un oeil sur vos marchandises."

class npc_innkeeper_new : public CreatureScript
{
public:
    npc_innkeeper_new() : CreatureScript("npc_innkeeper_new") { }

    struct npc_innkeeper_newAI : public ScriptedAI
    {
        npc_innkeeper_newAI(Creature* creature) : ScriptedAI(creature) { }

        bool GossipHello(Player* player) override
        {
            if (IsHolidayActive(HOLIDAY_HALLOWS_END) && !player->HasAura(SPELL_TRICK_OR_TREATED))
            {
                char const* localizedEntry;
                switch (player->GetSession()->GetSessionDbcLocale())
                {
                    case LOCALE_frFR: localizedEntry = LOCALE_TRICK_OR_TREAT_2; break;
                    case LOCALE_enUS: default: localizedEntry = LOCALE_TRICK_OR_TREAT_0;
                }
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, localizedEntry, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            }

            if (me->IsQuestGiver())
                player->PrepareQuestMenu(me->GetGUID());

            if (me->IsVendor())
            {
                char const* localizedEntry;
                switch (player->GetSession()->GetSessionDbcLocale())
                {
                    case LOCALE_frFR: localizedEntry = LOCALE_VENDOR_2; break;
                    case LOCALE_enUS: default: localizedEntry = LOCALE_VENDOR_0;
                }
                AddGossipItemFor(player, GOSSIP_ICON_VENDOR, localizedEntry, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

            }

            if (me->IsInnkeeper())
            {
                char const* localizedEntry;
                switch (player->GetSession()->GetSessionDbcLocale())
                {
                    case LOCALE_frFR: localizedEntry = LOCALE_INNKEEPER_2; break;
                    case LOCALE_enUS: default: localizedEntry = LOCALE_INNKEEPER_0; 
                }
                AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, localizedEntry, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INN);
            }

            player->TalkedToCreature(me->GetEntry(), me->GetGUID());
            SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
            return true;
        }

        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
            ClearGossipMenuFor(player);
            if (action == GOSSIP_ACTION_INFO_DEF + 1 && IsHolidayActive(HOLIDAY_HALLOWS_END) && !player->HasAura(SPELL_TRICK_OR_TREATED))
            {
                player->CastSpell(player, SPELL_TRICK_OR_TREATED, true);

                if (urand(0, 1))
                    player->CastSpell(player, SPELL_TREAT, true);
                else
                {
                    uint32 trickspell = 0;
                    switch (urand(0, 13))
                    {
                        case 0: trickspell = 24753; break; // cannot cast, random 30sec
                        case 1: trickspell = 24713; break; // lepper gnome costume
                        case 2: trickspell = 24735; break; // male ghost costume
                        case 3: trickspell = 24736; break; // female ghostcostume
                        case 4: trickspell = 24710; break; // male ninja costume
                        case 5: trickspell = 24711; break; // female ninja costume
                        case 6: trickspell = 24708; break; // male pirate costume
                        case 7: trickspell = 24709; break; // female pirate costume
                        case 8: trickspell = 24723; break; // skeleton costume
                        case 9: trickspell = 24753; break; // Trick
                        case 10: trickspell = 24924; break; // Hallow's End Candy
                        case 11: trickspell = 24925; break; // Hallow's End Candy
                        case 12: trickspell = 24926; break; // Hallow's End Candy
                        case 13: trickspell = 24927; break; // Hallow's End Candy
                    }
                    player->CastSpell(player, trickspell, true);
                }
                CloseGossipMenuFor(player);
                return true;
            }

            CloseGossipMenuFor(player);

            switch (action)
            {
                case GOSSIP_ACTION_TRADE:
                {
                    player->GetSession()->SendListInventory(me->GetGUID());
                    me->HandleEmoteCommand(401);
                    break;
                }
                case GOSSIP_ACTION_INN:
                {
                    //player->SetBindPoint(me->GetGUID()); 

                    player->SetHomebind(player->GetWorldLocation(), player->GetAreaId());
                    player->SendBindPointUpdate();
                    player->AddItem(6948, 1);                   // Ajout Pierre de foyer
                    //player->LearnSpell(8690, true);           // Apprend Pierre de foyer
                    me->HandleEmoteCommand(4);
                    player->CastSpell(player, 14867, true);     // Pour visuel
                    break;
                }
            }
            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_innkeeper_newAI(creature);
    }
};

void AddSC_npc_innkeeper_new()
{
    new npc_innkeeper_new();
}

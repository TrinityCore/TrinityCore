//##############################################################################################
//Stitch Decembre 2020 - npc_changer - version 1.0 , wow 9.0.2.36949
// PNJ 15000142 : change race , faction , apparence 
//##############################################################################################

#include "ScriptMgr.h"
#include "GameEventMgr.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "WorldSession.h"

enum Spells
{
    SPELL_POUR_VISUEL       = 14867,
    EMOTE_1                 = 4,        // UNIQUE_ACCLAMATION / Contant
    EMOTE_2                 = 401,      // UNIQUE_DANCES SPECIAL
    EMOTE_3                 = 1,        // UNIQUE_PARLER(DNR)
    EMOTE_4                 = 6,        // UNIQUE_QUESTION
    EMOTE_5                 = 11,       // UNIQUE_RIRE
    EMOTE_6                 = 25,        // UNIQUE POINT(DNR)
    EMOTE_7                 = 66,        // BOUCLE SALUER
    EMOTE_8                 = 288       // Lire une carte

};

#define LOCALE_TEXTE_CHANGER_FACTION_0      "Change faction (With TP)"
#define LOCALE_TEXTE_CHANGER_RACE_0         "Change Race"
#define LOCALE_TEXTE_CHANGER_APPARENCE_0    "Change my Appearance"

#define LOCALE_TEXTE_CHANGER_FACTION_2      "Changer de Faction (Avec TP)"
#define LOCALE_TEXTE_CHANGER_RACE_2         "Changer de Race"
#define LOCALE_TEXTE_CHANGER_APPARENCE_2    "Changer mon Apparence"



class npc_changer : public CreatureScript
{
public:
    npc_changer() : CreatureScript("npc_changer") { }

    struct npc_changerAI : public ScriptedAI
    {
        npc_changerAI(Creature* creature) : ScriptedAI(creature) { }

        bool GossipHello(Player* player) override
        {
            TeamId team = player->GetTeamId();
            uint8 _race = player->getRace();
            if (_race == RACE_PANDAREN_NEUTRAL) return false;

            // GOSSIP_ICON_CHAT         GOSSIP_ICON_VENDOR      GOSSIP_ICON_TAXI        GOSSIP_ICON_TRAINER     GOSSIP_ICON_INTERACT_1   GOSSIP_ICON_INTERACT_2
            // GOSSIP_ICON_MONEY_BAG    GOSSIP_ICON_TALK        GOSSIP_ICON_TABARD      GOSSIP_ICON_BATTLE      GOSSIP_ICON_DOT

            // Changer de Faction (Avec TP) -------------------------------------------------------------------------------------
            char const* localizedEntry2;
            switch (player->GetSession()->GetSessionDbcLocale())
            {
            case LOCALE_frFR: localizedEntry2 = LOCALE_TEXTE_CHANGER_FACTION_2; break;
            case LOCALE_enUS: default: localizedEntry2 = LOCALE_TEXTE_CHANGER_FACTION_0;
            }
            AddGossipItemFor(player, GOSSIP_ICON_TABARD, localizedEntry2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

            // Changer de Race --------------------------------------------------------------------------------------------------
            char const* localizedEntry3;
            switch (player->GetSession()->GetSessionDbcLocale())
            {
            case LOCALE_frFR: localizedEntry3 = LOCALE_TEXTE_CHANGER_RACE_2; break;
            case LOCALE_enUS: default: localizedEntry3 = LOCALE_TEXTE_CHANGER_RACE_0;
            }
            AddGossipItemFor(player, GOSSIP_ICON_TABARD, localizedEntry3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

            // Changer mon Apparence --------------------------------------------------------------------------------------------
            char const* localizedEntry6;
            switch (player->GetSession()->GetSessionDbcLocale())
            {
            case LOCALE_frFR: localizedEntry6 = LOCALE_TEXTE_CHANGER_APPARENCE_2; break;
            case LOCALE_enUS: default: localizedEntry6 = LOCALE_TEXTE_CHANGER_APPARENCE_0;
            }
            AddGossipItemFor(player, GOSSIP_ICON_TABARD, localizedEntry6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

            //-------------------------------------------------------------------------------------------------------------------

            player->TalkedToCreature(me->GetEntry(), me->GetGUID());
            SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID());
            return true;
        }
 
        bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
        {
            uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
    
            CloseGossipMenuFor(player);

            switch (action)
            {
            case GOSSIP_ACTION_INFO_DEF:        // Changer de Faction (Avec TP) -------------------------------------------------------------------------------------
                player->CastSpell(player, SPELL_POUR_VISUEL, true);
                me->HandleEmoteCommand(EMOTE_2);
                player->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
                player->SaveToDB();
                player->GetSession()->LogoutPlayer(false);
                break;
            case GOSSIP_ACTION_INFO_DEF + 1:    // Changer de Race --------------------------------------------------------------------------------------------------
                player->CastSpell(player, SPELL_POUR_VISUEL, true);
                me->HandleEmoteCommand(EMOTE_4);
                player->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
                player->SaveToDB();
                player->GetSession()->LogoutPlayer(false);
                break;
 
            case GOSSIP_ACTION_INFO_DEF + 2:    // Changer mon Apparence --------------------------------------------------------------------------------------------
                player->CastSpell(player, SPELL_POUR_VISUEL, true);
                me->HandleEmoteCommand(EMOTE_5);
                player->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
                player->SaveToDB();
                player->GetSession()->LogoutPlayer(false);
                break;
            }
            return true;
        }


 
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_changerAI(creature);
    }
};

void AddSC_npc_changer()
{
    new npc_changer();
}

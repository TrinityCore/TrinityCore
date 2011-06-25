/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
SDName: Icecrown
SD%Complete: 100
SDComment: Quest support: 12807
SDCategory: Icecrown
EndScriptData */

/* ContentData
npc_arete
EndContentData */

#include "ScriptPCH.h"
#include "SpellAuraEffects.h"
#include "ScriptMgr.h"

/*######
## npc_arete
######*/

#define GOSSIP_ARETE_ITEM1 "Lord-Commander, I would hear your tale."
#define GOSSIP_ARETE_ITEM2 "<You nod slightly but do not complete the motion as the Lord-Commander narrows his eyes before he continues.>"
#define GOSSIP_ARETE_ITEM3 "I thought that they now called themselves the Scarlet Onslaught?"
#define GOSSIP_ARETE_ITEM4 "Where did the grand admiral go?"
#define GOSSIP_ARETE_ITEM5 "That's fine. When do I start?"
#define GOSSIP_ARETE_ITEM6 "Let's finish this!"
#define GOSSIP_ARETE_ITEM7 "That's quite a tale, Lord-Commander."

enum eArete
{
    GOSSIP_TEXTID_ARETE1        = 13525,
    GOSSIP_TEXTID_ARETE2        = 13526,
    GOSSIP_TEXTID_ARETE3        = 13527,
    GOSSIP_TEXTID_ARETE4        = 13528,
    GOSSIP_TEXTID_ARETE5        = 13529,
    GOSSIP_TEXTID_ARETE6        = 13530,
    GOSSIP_TEXTID_ARETE7        = 13531,

    QUEST_THE_STORY_THUS_FAR    = 12807
};

class npc_arete : public CreatureScript
{
public:
    npc_arete() : CreatureScript("npc_arete") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        if (pPlayer->GetQuestStatus(QUEST_THE_STORY_THUS_FAR) == QUEST_STATUS_INCOMPLETE)
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE1, pCreature->GetGUID());
            return true;
        }

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        switch(uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE2, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE3, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
                pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE4, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+4:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
                pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE5, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+5:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
                pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE6, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+6:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM7, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
                pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE7, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+7:
                pPlayer->CLOSE_GOSSIP_MENU();
                pPlayer->AreaExploredOrEventHappens(QUEST_THE_STORY_THUS_FAR);
                break;
        }

        return true;
    }
};

/*######
## npc_alorah_and_grimmin
######*/

enum ealorah_and_grimmin
{
    SPELL_CHAIN                     = 68341,
    NPC_FJOLA_LIGHTBANE             = 36065,
    NPC_EYDIS_DARKBANE              = 36066,
    NPC_PRIESTESS_ALORAH            = 36101,
    NPC_PRIEST_GRIMMIN              = 36102
};

class npc_alorah_and_grimmin : public CreatureScript
{
public:
    npc_alorah_and_grimmin() : CreatureScript("npc_alorah_and_grimmin") { }

    struct npc_alorah_and_grimminAI : public ScriptedAI
    {
        npc_alorah_and_grimminAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        bool uiCast;

        void Reset()
        {
            uiCast = false;
        }

        void UpdateAI(const uint32 /*uiDiff*/)
        {
            if (uiCast)
                return;
            uiCast = true;
            Creature* pTarget = NULL;

            switch(me->GetEntry())
            {
                case NPC_PRIESTESS_ALORAH:
                    pTarget = me->FindNearestCreature(NPC_EYDIS_DARKBANE, 10.0f);
                    break;
                case NPC_PRIEST_GRIMMIN:
                    pTarget = me->FindNearestCreature(NPC_FJOLA_LIGHTBANE, 10.0f);
                    break;
            }
            if (pTarget)
                DoCast(pTarget, SPELL_CHAIN);

            if (!UpdateVictim())
                return;
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_alorah_and_grimminAI(creature);
    }
};

/*######
## npc_guardian_pavilion
######*/

enum eGuardianPavilion
{
    SPELL_TRESPASSER_H                            = 63987,
    AREA_SUNREAVER_PAVILION                       = 4676,

    AREA_SILVER_COVENANT_PAVILION                 = 4677,
    SPELL_TRESPASSER_A                            = 63986,
};

class npc_guardian_pavilion : public CreatureScript
{
public:
    npc_guardian_pavilion() : CreatureScript("npc_guardian_pavilion") { }

    struct npc_guardian_pavilionAI : public Scripted_NoMovementAI
    {
        npc_guardian_pavilionAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature) {}

        void MoveInLineOfSight(Unit* pWho)
        {
            if (me->GetAreaId() != AREA_SUNREAVER_PAVILION && me->GetAreaId() != AREA_SILVER_COVENANT_PAVILION)
                return;

            if (!pWho || pWho->GetTypeId() != TYPEID_PLAYER || !me->IsHostileTo(pWho) || !me->isInBackInMap(pWho, 5.0f))
                return;

            if (pWho->HasAura(SPELL_TRESPASSER_H) || pWho->HasAura(SPELL_TRESPASSER_A))
                return;

            if (pWho->ToPlayer()->GetTeamId() == TEAM_ALLIANCE)
                pWho->CastSpell(pWho, SPELL_TRESPASSER_H, true);
            else
                pWho->CastSpell(pWho, SPELL_TRESPASSER_A, true);

        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_guardian_pavilionAI(creature);
    }
};

void AddSC_icecrown()
{
    new npc_arete;
    new npc_alorah_and_grimmin;
    new npc_guardian_pavilion;
}
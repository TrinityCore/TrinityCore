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
SDName: Undercity
SD%Complete: 95
SDComment: Quest support: 6628, 9180(post-event).
SDCategory: Undercity
EndScriptData */

/* ContentData
npc_lady_sylvanas_windrunner
npc_highborne_lamenter
npc_parqual_fintallas
EndContentData */

#include "ScriptPCH.h"

/*######
## npc_lady_sylvanas_windrunner
######*/

enum Sylvanas
{
    QUEST_JOURNEY_TO_UNDERCITY  = 9180,
    SAY_LAMENT_END              = -1000196,
    EMOTE_LAMENT_END            = -1000197,

    SOUND_CREDIT                = 10896,
    ENTRY_HIGHBORNE_LAMENTER    = 21628,
    ENTRY_HIGHBORNE_BUNNY       = 21641,

    SPELL_HIGHBORNE_AURA        = 37090,
    SPELL_SYLVANAS_CAST         = 36568,
    SPELL_RIBBON_OF_SOULS       = 34432,                   //the real one to use might be 37099
};

float HighborneLoc[4][3]=
{
    {1285.41f, 312.47f, 0.51f},
    {1286.96f, 310.40f, 1.00f},
    {1289.66f, 309.66f, 1.52f},
    {1292.51f, 310.50f, 1.99f},
};

#define HIGHBORNE_LOC_Y             -61.00f
#define HIGHBORNE_LOC_Y_NEW         -55.50f

class npc_lady_sylvanas_windrunner : public CreatureScript
{
public:
    npc_lady_sylvanas_windrunner() : CreatureScript("npc_lady_sylvanas_windrunner") { }

    bool OnQuestReward(Player* /*pPlayer*/, Creature* pCreature, const Quest *_Quest, uint32 /*slot*/)
    {
        if (_Quest->GetQuestId() == QUEST_JOURNEY_TO_UNDERCITY)
        {
            CAST_AI(npc_lady_sylvanas_windrunner::npc_lady_sylvanas_windrunnerAI, pCreature->AI())->LamentEvent = true;
            CAST_AI(npc_lady_sylvanas_windrunner::npc_lady_sylvanas_windrunnerAI, pCreature->AI())->DoPlaySoundToSet(pCreature, SOUND_CREDIT);
            pCreature->CastSpell(pCreature, SPELL_SYLVANAS_CAST, false);

            for (uint8 i = 0; i < 4; ++i)
                pCreature->SummonCreature(ENTRY_HIGHBORNE_LAMENTER, HighborneLoc[i][0], HighborneLoc[i][1], HIGHBORNE_LOC_Y, HighborneLoc[i][2], TEMPSUMMON_TIMED_DESPAWN, 160000);
        }

        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_lady_sylvanas_windrunnerAI (pCreature);
    }

    struct npc_lady_sylvanas_windrunnerAI : public ScriptedAI
    {
        npc_lady_sylvanas_windrunnerAI(Creature *c) : ScriptedAI(c) {}

        uint32 LamentEvent_Timer;
        bool LamentEvent;
        uint64 targetGUID;

        void Reset()
        {
            LamentEvent_Timer = 5000;
            LamentEvent = false;
            targetGUID = 0;
        }

        void EnterCombat(Unit * /*who*/) {}

        void JustSummoned(Creature *summoned)
        {
            if (summoned->GetEntry() == ENTRY_HIGHBORNE_BUNNY)
            {
                if (Unit *pTarget = Unit::GetUnit(*summoned,targetGUID))
                {
                    pTarget->SendMonsterMove(pTarget->GetPositionX(), pTarget->GetPositionY(), me->GetPositionZ()+15.0f,0);
                    pTarget->GetMap()->CreatureRelocation(me, pTarget->GetPositionX(), pTarget->GetPositionY(), me->GetPositionZ()+15.0f, 0.0f);
                    summoned->CastSpell(pTarget, SPELL_RIBBON_OF_SOULS, false);
                }

                summoned->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                targetGUID = summoned->GetGUID();
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (LamentEvent)
            {
                if (LamentEvent_Timer <= diff)
                {
                    DoSummon(ENTRY_HIGHBORNE_BUNNY, me, 10.0f, 3000, TEMPSUMMON_TIMED_DESPAWN);

                    LamentEvent_Timer = 2000;
                    if (!me->HasAura(SPELL_SYLVANAS_CAST))
                    {
                        DoScriptText(SAY_LAMENT_END, me);
                        DoScriptText(EMOTE_LAMENT_END, me);
                        LamentEvent = false;
                    }
                } else LamentEvent_Timer -= diff;
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

};


/*######
## npc_highborne_lamenter
######*/

class npc_highborne_lamenter : public CreatureScript
{
public:
    npc_highborne_lamenter() : CreatureScript("npc_highborne_lamenter") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_highborne_lamenterAI (pCreature);
    }

    struct npc_highborne_lamenterAI : public ScriptedAI
    {
        npc_highborne_lamenterAI(Creature *c) : ScriptedAI(c) {}

        uint32 EventMove_Timer;
        uint32 EventCast_Timer;
        bool EventMove;
        bool EventCast;

        void Reset()
        {
            EventMove_Timer = 10000;
            EventCast_Timer = 17500;
            EventMove = true;
            EventCast = true;
        }

        void EnterCombat(Unit * /*who*/) {}

        void UpdateAI(const uint32 diff)
        {
            if (EventMove)
            {
                if (EventMove_Timer <= diff)
                {
                    me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                    me->SendMonsterMoveWithSpeed(me->GetPositionX(),me->GetPositionY(),HIGHBORNE_LOC_Y_NEW,5000);
                    me->GetMap()->CreatureRelocation(me,me->GetPositionX(),me->GetPositionY(),HIGHBORNE_LOC_Y_NEW,me->GetOrientation());
                    EventMove = false;
                } else EventMove_Timer -= diff;
            }
            if (EventCast)
            {
                if (EventCast_Timer <= diff)
                {
                    DoCast(me, SPELL_HIGHBORNE_AURA);
                    EventCast = false;
                } else EventCast_Timer -= diff;
            }
        }
    };

};

/*######
## npc_parqual_fintallas
######*/

#define SPELL_MARK_OF_SHAME 6767

#define GOSSIP_HPF1 "Gul'dan"
#define GOSSIP_HPF2 "Kel'Thuzad"
#define GOSSIP_HPF3 "Ner'zhul"

class npc_parqual_fintallas : public CreatureScript
{
public:
    npc_parqual_fintallas() : CreatureScript("npc_parqual_fintallas") { }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            pCreature->CastSpell(pPlayer,SPELL_MARK_OF_SHAME,false);
        }
        if (uiAction == GOSSIP_ACTION_INFO_DEF+2)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->AreaExploredOrEventHappens(6628);
        }
        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        if (pPlayer->GetQuestStatus(6628) == QUEST_STATUS_INCOMPLETE && !pPlayer->HasAura(SPELL_MARK_OF_SHAME))
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HPF1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HPF2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HPF3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            pPlayer->SEND_GOSSIP_MENU(5822, pCreature->GetGUID());
        }
        else
            pPlayer->SEND_GOSSIP_MENU(5821, pCreature->GetGUID());

        return true;
    }

};


/*######
## AddSC
######*/

void AddSC_undercity()
{
    new npc_lady_sylvanas_windrunner();
    new npc_highborne_lamenter();
    new npc_parqual_fintallas();
}

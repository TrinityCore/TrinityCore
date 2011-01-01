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
SDName: Westfall
SD%Complete: 90
SDComment: Quest support: 155, 1651
SDCategory: Westfall
EndScriptData */

/* ContentData
npc_daphne_stilwell
npc_defias_traitor
EndContentData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"

/*######
## npc_daphne_stilwell
######*/

enum eEnums
{
    SAY_DS_START        = -1000293,
    SAY_DS_DOWN_1       = -1000294,
    SAY_DS_DOWN_2       = -1000295,
    SAY_DS_DOWN_3       = -1000296,
    SAY_DS_PROLOGUE     = -1000297,

    SPELL_SHOOT         = 6660,
    QUEST_TOME_VALOR    = 1651,
    NPC_DEFIAS_RAIDER   = 6180,
    EQUIP_ID_RIFLE      = 2511
};

class npc_daphne_stilwell : public CreatureScript
{
public:
    npc_daphne_stilwell() : CreatureScript("npc_daphne_stilwell") { }

    bool OnQuestAccept(Player* pPlayer, Creature* pCreature, const Quest* pQuest)
    {
        if (pQuest->GetQuestId() == QUEST_TOME_VALOR)
        {
            DoScriptText(SAY_DS_START, pCreature);

            if (npc_escortAI* pEscortAI = CAST_AI(npc_daphne_stilwell::npc_daphne_stilwellAI, pCreature->AI()))
                pEscortAI->Start(true, true, pPlayer->GetGUID());
        }

        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_daphne_stilwellAI(pCreature);
    }

    struct npc_daphne_stilwellAI : public npc_escortAI
    {
        npc_daphne_stilwellAI(Creature* pCreature) : npc_escortAI(pCreature) {}

        uint32 uiWPHolder;
        uint32 uiShootTimer;

        void Reset()
        {
            if (HasEscortState(STATE_ESCORT_ESCORTING))
            {
                switch(uiWPHolder)
                {
                    case 7: DoScriptText(SAY_DS_DOWN_1, me); break;
                    case 8: DoScriptText(SAY_DS_DOWN_2, me); break;
                    case 9: DoScriptText(SAY_DS_DOWN_3, me); break;
                }
            }
            else
                uiWPHolder = 0;

            uiShootTimer = 0;
        }

        void WaypointReached(uint32 uiPoint)
        {
            Player* pPlayer = GetPlayerForEscort();

            if (!pPlayer)
                return;

            uiWPHolder = uiPoint;

            switch(uiPoint)
            {
                case 4:
                    SetEquipmentSlots(false, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE, EQUIP_ID_RIFLE);
                    me->SetSheath(SHEATH_STATE_RANGED);
                    me->HandleEmoteCommand(EMOTE_STATE_USESTANDING_NOSHEATHE);
                    break;
                case 7:
                    me->SummonCreature(NPC_DEFIAS_RAIDER, -11450.836f, 1569.755f, 54.267f, 4.230f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    me->SummonCreature(NPC_DEFIAS_RAIDER, -11449.697f, 1569.124f, 54.421f, 4.206f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    me->SummonCreature(NPC_DEFIAS_RAIDER, -11448.237f, 1568.307f, 54.620f, 4.206f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    break;
                case 8:
                    me->SetSheath(SHEATH_STATE_RANGED);
                    me->SummonCreature(NPC_DEFIAS_RAIDER, -11450.836f, 1569.755f, 54.267f, 4.230f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    me->SummonCreature(NPC_DEFIAS_RAIDER, -11449.697f, 1569.124f, 54.421f, 4.206f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    me->SummonCreature(NPC_DEFIAS_RAIDER, -11448.237f, 1568.307f, 54.620f, 4.206f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    me->SummonCreature(NPC_DEFIAS_RAIDER, -11448.037f, 1570.213f, 54.961f, 4.283f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    break;
                case 9:
                    me->SetSheath(SHEATH_STATE_RANGED);
                    me->SummonCreature(NPC_DEFIAS_RAIDER, -11450.836f, 1569.755f, 54.267f, 4.230f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    me->SummonCreature(NPC_DEFIAS_RAIDER, -11449.697f, 1569.124f, 54.421f, 4.206f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    me->SummonCreature(NPC_DEFIAS_RAIDER, -11448.237f, 1568.307f, 54.620f, 4.206f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    me->SummonCreature(NPC_DEFIAS_RAIDER, -11448.037f, 1570.213f, 54.961f, 4.283f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    me->SummonCreature(NPC_DEFIAS_RAIDER, -11449.018f, 1570.738f, 54.828f, 4.220f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                    break;
                case 10:
                    SetRun(false);
                    break;
                case 11:
                    DoScriptText(SAY_DS_PROLOGUE, me);
                    break;
                case 13:
                    SetEquipmentSlots(true);
                    me->SetSheath(SHEATH_STATE_UNARMED);
                    me->HandleEmoteCommand(EMOTE_STATE_USESTANDING_NOSHEATHE);
                    break;
                case 17:
                    pPlayer->GroupEventHappens(QUEST_TOME_VALOR, me);
                    break;
            }
        }

        void AttackStart(Unit* pWho)
        {
            if (!pWho)
                return;

            if (me->Attack(pWho, false))
            {
                me->AddThreat(pWho, 0.0f);
                me->SetInCombatWith(pWho);
                pWho->SetInCombatWith(me);

                me->GetMotionMaster()->MoveChase(pWho, 30.0f);
            }
        }

        void JustSummoned(Creature* pSummoned)
        {
            pSummoned->AI()->AttackStart(me);
        }

        void Update(const uint32 diff)
        {
            npc_escortAI::UpdateAI(diff);

            if (!UpdateVictim())
                return;

            if (uiShootTimer <= diff)
            {
                uiShootTimer = 1500;

                if (!me->IsWithinDist(me->getVictim(), ATTACK_DISTANCE))
                    DoCast(me->getVictim(), SPELL_SHOOT);
            } else uiShootTimer -= diff;
        }
    };

};



/*######
## npc_defias_traitor
######*/

#define SAY_START                   -1000101
#define SAY_PROGRESS                -1000102
#define SAY_END                     -1000103
#define SAY_AGGRO_1                 -1000104
#define SAY_AGGRO_2                 -1000105

#define QUEST_DEFIAS_BROTHERHOOD    155

class npc_defias_traitor : public CreatureScript
{
public:
    npc_defias_traitor() : CreatureScript("npc_defias_traitor") { }

    bool OnQuestAccept(Player* pPlayer, Creature* pCreature, Quest const* quest)
    {
        if (quest->GetQuestId() == QUEST_DEFIAS_BROTHERHOOD)
        {
            if (npc_escortAI* pEscortAI = CAST_AI(npc_defias_traitor::npc_defias_traitorAI, pCreature->AI()))
                pEscortAI->Start(true, true, pPlayer->GetGUID());

            DoScriptText(SAY_START, pCreature, pPlayer);
        }

        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_defias_traitorAI(pCreature);
    }

    struct npc_defias_traitorAI : public npc_escortAI
    {
        npc_defias_traitorAI(Creature *c) : npc_escortAI(c) { Reset(); }

        void WaypointReached(uint32 i)
        {
            Player* pPlayer = GetPlayerForEscort();

            if (!pPlayer)
                return;

            switch (i)
            {
                case 35:
                    SetRun(false);
                    break;
                case 36:
                    DoScriptText(SAY_PROGRESS, me, pPlayer);
                    break;
                case 44:
                    DoScriptText(SAY_END, me, pPlayer);
                    {
                        if (pPlayer)
                            pPlayer->GroupEventHappens(QUEST_DEFIAS_BROTHERHOOD,me);
                    }
                    break;
            }
        }
        void EnterCombat(Unit* who)
        {
            DoScriptText(RAND(SAY_AGGRO_1,SAY_AGGRO_2), me, who);
        }

        void Reset() {}
    };

};



void AddSC_westfall()
{
    new npc_daphne_stilwell();
    new npc_defias_traitor();
}

/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "Player.h"

/*######
## npc_daphne_stilwell
######*/

enum DaphneStilwell
{
    // Yells
    SAY_DS_START        = 0,
    SAY_DS_DOWN_1       = 1,
    SAY_DS_DOWN_2       = 2,
    SAY_DS_DOWN_3       = 3,
    SAY_DS_PROLOGUE     = 4,

    // Spells
    SPELL_SHOOT         = 6660,

    // Quests
    QUEST_TOME_VALOR    = 1651,

    // Creatures
    NPC_DEFIAS_RAIDER   = 6180,

    // Equips
    EQUIP_ID_RIFLE      = 2511
};

class npc_daphne_stilwell : public CreatureScript
{
public:
    npc_daphne_stilwell() : CreatureScript("npc_daphne_stilwell") { }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest* quest) OVERRIDE
    {
        if (quest->GetQuestId() == QUEST_TOME_VALOR)
        {
            creature->AI()->Talk(SAY_DS_START);

            if (npc_escortAI* pEscortAI = CAST_AI(npc_daphne_stilwell::npc_daphne_stilwellAI, creature->AI()))
                pEscortAI->Start(true, true, player->GetGUID());
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_daphne_stilwellAI(creature);
    }

    struct npc_daphne_stilwellAI : public npc_escortAI
    {
        npc_daphne_stilwellAI(Creature* creature) : npc_escortAI(creature) {}

        uint32 uiWPHolder;
        uint32 uiShootTimer;

        void Reset() OVERRIDE
        {
            if (HasEscortState(STATE_ESCORT_ESCORTING))
            {
                switch (uiWPHolder)
                {
                    case 7:
                        Talk(SAY_DS_DOWN_1);
                        break;
                    case 8:
                        Talk(SAY_DS_DOWN_2);
                        break;
                    case 9:
                        Talk(SAY_DS_DOWN_3);
                        break;
                }
            }
            else
                uiWPHolder = 0;

            uiShootTimer = 0;
        }

        void WaypointReached(uint32 waypointId) OVERRIDE
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            uiWPHolder = waypointId;

            switch (waypointId)
            {
                case 4:
                    SetEquipmentSlots(false, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE, EQUIP_ID_RIFLE);
                    me->SetSheath(SHEATH_STATE_RANGED);
                    me->HandleEmoteCommand(EMOTE_STATE_USE_STANDING_NO_SHEATHE);
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
                    Talk(SAY_DS_PROLOGUE);
                    break;
                case 13:
                    SetEquipmentSlots(true);
                    me->SetSheath(SHEATH_STATE_UNARMED);
                    me->HandleEmoteCommand(EMOTE_STATE_USE_STANDING_NO_SHEATHE);
                    break;
                case 17:
                    player->GroupEventHappens(QUEST_TOME_VALOR, me);
                    break;
            }
        }

        void AttackStart(Unit* who) OVERRIDE
        {
            if (!who)
                return;

            if (me->Attack(who, false))
            {
                me->AddThreat(who, 0.0f);
                me->SetInCombatWith(who);
                who->SetInCombatWith(me);

                me->GetMotionMaster()->MoveChase(who, 30.0f);
            }
        }

        void JustSummoned(Creature* summoned) OVERRIDE
        {
            summoned->AI()->AttackStart(me);
        }

        void Update(const uint32 diff)
        {
            npc_escortAI::UpdateAI(diff);

            if (!UpdateVictim())
                return;

            if (uiShootTimer <= diff)
            {
                uiShootTimer = 1500;

                if (!me->IsWithinDist(me->GetVictim(), ATTACK_DISTANCE))
                    DoCastVictim(SPELL_SHOOT);
            } else uiShootTimer -= diff;
        }
    };
};

/*######
## npc_defias_traitor
######*/
enum DefiasSays
{
    SAY_START                   = 0,
    SAY_PROGRESS                = 1,
    SAY_END                     = 2,
    SAY_AGGRO                   = 3
};


#define QUEST_DEFIAS_BROTHERHOOD    155

class npc_defias_traitor : public CreatureScript
{
public:
    npc_defias_traitor() : CreatureScript("npc_defias_traitor") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) OVERRIDE
    {
        if (quest->GetQuestId() == QUEST_DEFIAS_BROTHERHOOD)
        {
            if (npc_escortAI* pEscortAI = CAST_AI(npc_defias_traitor::npc_defias_traitorAI, creature->AI()))
                pEscortAI->Start(true, true, player->GetGUID());

            creature->AI()->Talk(SAY_START, player->GetGUID());
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_defias_traitorAI(creature);
    }

    struct npc_defias_traitorAI : public npc_escortAI
    {
        npc_defias_traitorAI(Creature* creature) : npc_escortAI(creature) { Reset(); }

        void WaypointReached(uint32 waypointId) OVERRIDE
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 35:
                    SetRun(false);
                    break;
                case 36:
                    Talk(SAY_PROGRESS, player->GetGUID());
                    break;
                case 44:
                    Talk(SAY_END, player->GetGUID());
                    player->GroupEventHappens(QUEST_DEFIAS_BROTHERHOOD, me);
                    break;
            }
        }

        void EnterCombat(Unit* who) OVERRIDE
        {
            Talk(SAY_AGGRO, who->GetGUID());
        }

        void Reset() OVERRIDE {}
    };
};

void AddSC_westfall()
{
    new npc_daphne_stilwell();
    new npc_defias_traitor();
}

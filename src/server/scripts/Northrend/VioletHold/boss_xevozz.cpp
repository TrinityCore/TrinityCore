/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "violet_hold.h"
#include "Player.h"

enum Spells
{
    SPELL_ARCANE_BARRAGE_VOLLEY                 = 54202,
    SPELL_ARCANE_BUFFET                         = 54226,
    SPELL_SUMMON_ETHEREAL_SPHERE_1              = 54102,
    SPELL_SUMMON_ETHEREAL_SPHERE_2              = 54137,
    SPELL_SUMMON_ETHEREAL_SPHERE_3              = 54138,
    SPELL_ARCANE_BOLT                           = 13748
};

enum NPCs
{
    NPC_ETHEREAL_SPHERE                         = 29271,
    //NPC_ETHEREAL_SPHERE2                      = 32582, // heroic only?
};

enum CreatureSpells
{
    SPELL_ARCANE_POWER                          = 54160,
    SPELL_SUMMON_PLAYERS                        = 54164,
    SPELL_POWER_BALL_VISUAL                     = 54141
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_SLAY                                    = 1,
    SAY_DEATH                                   = 2,
    SAY_SPAWN                                   = 3,
    SAY_CHARGED                                 = 4,
    SAY_REPEAT_SUMMON                           = 5,
    SAY_SUMMON_ENERGY                           = 6
};

class boss_xevozz : public CreatureScript
{
public:
    boss_xevozz() : CreatureScript("boss_xevozz") { }

    struct boss_xevozzAI : public ScriptedAI
    {
        boss_xevozzAI(Creature* creature) : ScriptedAI(creature)
        {
            instance  = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 uiSummonEtherealSphere_Timer;
        uint32 uiArcaneBarrageVolley_Timer;
        uint32 uiArcaneBuffet_Timer;
        uint32 uiArcaneBolt;

        void Reset() OVERRIDE
        {
            if (instance->GetData(DATA_WAVE_COUNT) == 6)
                instance->SetBossState(DATA_1ST_BOSS_EVENT, NOT_STARTED);
            else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                instance->SetBossState(DATA_2ND_BOSS_EVENT, NOT_STARTED);

            uiSummonEtherealSphere_Timer = urand(10000, 12000);
            uiArcaneBarrageVolley_Timer = urand(20000, 22000);
            uiArcaneBolt = urand(2400, 3800);
            uiArcaneBuffet_Timer = uiSummonEtherealSphere_Timer + urand(5000, 6000);
            DespawnSphere();
        }

        void DespawnSphere()
        {
            std::list<Creature*> assistList;
            GetCreatureListWithEntryInGrid(assistList, me, NPC_ETHEREAL_SPHERE, 150.0f);

            if (assistList.empty())
                return;

            for (std::list<Creature*>::const_iterator iter = assistList.begin(); iter != assistList.end(); ++iter)
                if (Creature* pSphere = *iter)
                    pSphere->Kill(pSphere, false);
        }

        void JustSummoned(Creature* summoned) OVERRIDE
        {
            summoned->SetSpeed(MOVE_RUN, 0.5f);
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
            {
                summoned->AddThreat(target, 0.00f);
                summoned->AI()->AttackStart(target);
            }
        }

        void AttackStart(Unit* who) OVERRIDE
        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC) || me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            if (me->Attack(who, true))
            {
                me->AddThreat(who, 0.0f);
                me->SetInCombatWith(who);
                who->SetInCombatWith(me);
                DoStartMovement(who);
            }
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_AGGRO);
            if (GameObject* pDoor = ObjectAccessor::GetGameObject(*me, instance->GetData64(DATA_XEVOZZ_CELL)))
                if (pDoor->GetGoState() == GO_STATE_READY)
                {
                    EnterEvadeMode();
                    return;
                }
            if (instance->GetData(DATA_WAVE_COUNT) == 6)
                instance->SetBossState(DATA_1ST_BOSS_EVENT, IN_PROGRESS);
            else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                instance->SetBossState(DATA_2ND_BOSS_EVENT, IN_PROGRESS);
        }

        void MoveInLineOfSight(Unit* /*who*/) OVERRIDE {}

        void UpdateAI(uint32 diff) OVERRIDE
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiArcaneBarrageVolley_Timer <= diff)
            {
                DoCast(me, SPELL_ARCANE_BARRAGE_VOLLEY);
                uiArcaneBarrageVolley_Timer = urand(20000, 22000);
            }
            else uiArcaneBarrageVolley_Timer -= diff;

            if (uiArcaneBolt <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_ARCANE_BOLT);
                uiArcaneBolt = urand(2400, 3800);
            }
            else uiArcaneBolt -= diff;

            if (uiArcaneBuffet_Timer)
            {
                if (uiArcaneBuffet_Timer <= diff)
                {
                    DoCastVictim(SPELL_ARCANE_BUFFET);
                    uiArcaneBuffet_Timer = 0;
                }
                else uiArcaneBuffet_Timer -= diff;
            }

            if (uiSummonEtherealSphere_Timer <= diff)
            {
                Talk(SAY_SPAWN);
                DoCast(me, SPELL_SUMMON_ETHEREAL_SPHERE_1);
                if (IsHeroic()) // extra one for heroic
                    me->SummonCreature(NPC_ETHEREAL_SPHERE, me->GetPositionX()-5+rand()%10, me->GetPositionY()-5+rand()%10, me->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 40000);

                uiSummonEtherealSphere_Timer = urand(45000, 47000);
                uiArcaneBuffet_Timer = urand(5000, 6000);
            }
            else uiSummonEtherealSphere_Timer -= diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Talk(SAY_DEATH);

            DespawnSphere();

            if (instance->GetData(DATA_WAVE_COUNT) == 6)
            {
                instance->SetBossState(DATA_1ST_BOSS_EVENT, DONE);
                instance->SetData(DATA_WAVE_COUNT, 7);
            }
            else if (instance->GetData(DATA_WAVE_COUNT) == 12)
            {
                instance->SetBossState(DATA_2ND_BOSS_EVENT, NOT_STARTED);
                instance->SetData(DATA_WAVE_COUNT, 13);
            }
        }

        void KilledUnit(Unit* victim) OVERRIDE
        {
            if (victim->GetTypeId() != TYPEID_PLAYER)
                return;

            Talk(SAY_SLAY);
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_xevozzAI>(creature);
    }
};

class npc_ethereal_sphere : public CreatureScript
{
public:
    npc_ethereal_sphere() : CreatureScript("npc_ethereal_sphere") { }

    struct npc_ethereal_sphereAI : public ScriptedAI
    {
        npc_ethereal_sphereAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 uiSummonPlayers_Timer;
        uint32 uiRangeCheck_Timer;

        void Reset() OVERRIDE
        {
            uiSummonPlayers_Timer = urand(33000, 35000);
            uiRangeCheck_Timer = 1000;
            me->setFaction(45);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

            if (!me->HasAura(SPELL_POWER_BALL_VISUAL))
                DoCast(me, SPELL_POWER_BALL_VISUAL);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiRangeCheck_Timer <= diff)
            {
                if (Creature* pXevozz = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_XEVOZZ)))
                {
                    float fDistance = me->GetDistance2d(pXevozz);
                    if (fDistance <= 3.0f)
                        DoCast(pXevozz, SPELL_ARCANE_POWER);
                    else
                        DoCast(me, 35845); //Is it blizzlike?
                }
                uiRangeCheck_Timer = 1000;
            }
            else uiRangeCheck_Timer -= diff;

            if (uiSummonPlayers_Timer <= diff)
            {
                DoCast(me, SPELL_SUMMON_PLAYERS); // not working right

                Map* map = me->GetMap();
                if (map && map->IsDungeon())
                {
                    Map::PlayerList const &PlayerList = map->GetPlayers();

                    if (!PlayerList.isEmpty())
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            if (i->GetSource()->IsAlive())
                                DoTeleportPlayer(i->GetSource(), me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), i->GetSource()->GetOrientation());
                }

                uiSummonPlayers_Timer = urand(33000, 35000);
            }
            else uiSummonPlayers_Timer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<npc_ethereal_sphereAI>(creature);
    }
};

void AddSC_boss_xevozz()
{
    new boss_xevozz();
    new npc_ethereal_sphere();
}

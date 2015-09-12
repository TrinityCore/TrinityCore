/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include "SpellInfo.h"
#include "SpellScript.h"
#include "Player.h"
#include "violet_hold.h"

enum Spells
{
    SPELL_ARCANE_BARRAGE_VOLLEY                 = 54202,
    SPELL_ARCANE_BUFFET                         = 54226,
    SPELL_SUMMON_ETHEREAL_SPHERE_1              = 54102,
    SPELL_SUMMON_ETHEREAL_SPHERE_2              = 61337,
    SPELL_SUMMON_ETHEREAL_SPHERE_3              = 54138
};

enum NPCs
{
    NPC_ETHEREAL_SPHERE                         = 29271,
    NPC_ETHEREAL_SPHERE2                        = 32582
};

enum CreatureSpells
{
    SPELL_ARCANE_POWER                          = 54160,
    H_SPELL_ARCANE_POWER                        = 59474,
    SPELL_SUMMON_PLAYERS                        = 54164,
    SPELL_POWER_BALL_VISUAL                     = 54141,
    SPELL_POWER_BALL_DAMAGE_TRIGGER             = 54207
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

enum XevozzEvents
{
    EVENT_ARCANE_BARRAGE                        = 1,
    EVENT_ARCANE_BUFFET,
    EVENT_SUMMON_SPHERE,
    EVENT_SUMMON_SPHERE_2,
    EVENT_RANGE_CHECK,
    EVENT_SUMMON_PLAYERS,
    EVENT_DESPAWN_SPHERE
};

enum SphereActions
{
    ACTION_SUMMON                               = 1,
};

class boss_xevozz : public CreatureScript
{
public:
    boss_xevozz() : CreatureScript("boss_xevozz") { }

    struct boss_xevozzAI : public ScriptedAI
    {
        boss_xevozzAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() override
        {
            if (instance->GetData(DATA_WAVE_COUNT) == 6)
                instance->SetBossState(DATA_1ST_BOSS_EVENT, NOT_STARTED);
            else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                instance->SetBossState(DATA_2ND_BOSS_EVENT, NOT_STARTED);

            DespawnSphere();
            events.Reset();
        }

        void DespawnSphere()
        {
            std::list<Creature*> assistList;
            GetCreatureListWithEntryInGrid(assistList, me, NPC_ETHEREAL_SPHERE, 150.0f);
            GetCreatureListWithEntryInGrid(assistList, me, NPC_ETHEREAL_SPHERE2, 150.0f);

            if (assistList.empty())
                return;

            for (std::list<Creature*>::const_iterator iter = assistList.begin(); iter != assistList.end(); ++iter)
            {
                if (Creature* pSphere = *iter)
                    pSphere->Kill(pSphere, false);
            }
        }

        void JustSummoned(Creature* summoned) override
        {
            summoned->SetSpeed(MOVE_RUN, 0.5f);
            summoned->GetMotionMaster()->MoveFollow(me, 0.0f, 0.0f);
        }

        void AttackStart(Unit* who) override
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

        void EnterCombat(Unit* /*who*/) override
        {
            if (GameObject* door = instance->GetGameObject(DATA_XEVOZZ_CELL))
                if (door->GetGoState() == GO_STATE_READY)
                {
                    EnterEvadeMode();
                    return;
                }

            Talk(SAY_AGGRO);

            if (instance->GetData(DATA_WAVE_COUNT) == 6)
                instance->SetBossState(DATA_1ST_BOSS_EVENT, IN_PROGRESS);
            else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                instance->SetBossState(DATA_2ND_BOSS_EVENT, IN_PROGRESS);

            events.ScheduleEvent(EVENT_SUMMON_SPHERE, 5000);
            events.ScheduleEvent(EVENT_ARCANE_BARRAGE, urand(8000, 10000));
            events.ScheduleEvent(EVENT_ARCANE_BUFFET, urand(10000, 11000));
        }

        void JustDied(Unit* /*killer*/) override
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

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void SpellHit(Unit* who, const SpellInfo* spell) override
        {
            if (!who->ToCreature())
                return;

            if ((spell->Id == SPELL_ARCANE_POWER) || (spell->Id == H_SPELL_ARCANE_POWER))
                Talk(SAY_SUMMON_ENERGY);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case EVENT_ARCANE_BARRAGE:
                    DoCast(SPELL_ARCANE_BARRAGE_VOLLEY);
                    events.ScheduleEvent(EVENT_ARCANE_BARRAGE, urand(8000, 10000));
                    break;
                case EVENT_ARCANE_BUFFET:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_ARCANE_BUFFET);
                    events.ScheduleEvent(EVENT_ARCANE_BUFFET, urand(15000, 20000));
                    break;
                case EVENT_SUMMON_SPHERE:
                    Talk(SAY_REPEAT_SUMMON);
                    DoCast(SPELL_SUMMON_ETHEREAL_SPHERE_1);
                    if (IsHeroic())
                        events.ScheduleEvent(EVENT_SUMMON_SPHERE_2, 2500);
                    events.ScheduleEvent(EVENT_SUMMON_PLAYERS, urand(33000, 35000));
                    events.ScheduleEvent(EVENT_SUMMON_SPHERE, urand(45000, 47000));
                    break;
                case EVENT_SUMMON_SPHERE_2:
                    Talk(SAY_REPEAT_SUMMON);
                    DoCast(SPELL_SUMMON_ETHEREAL_SPHERE_2);
                    break;
                case EVENT_SUMMON_PLAYERS:
                {
                    Creature* sphere = me->FindNearestCreature(NPC_ETHEREAL_SPHERE, 150.0f);
                    if (!sphere)
                        sphere = me->FindNearestCreature(NPC_ETHEREAL_SPHERE2, 150.0f);
                    if (sphere)
                        sphere->GetAI()->DoAction(ACTION_SUMMON);
                    break;
                }
                default:
                    break;
            }

            DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* instance;
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
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
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            arcanePower = false;
        }

        void Reset() override
        {
            Initialize();
            events.Reset();
            DoCast(SPELL_POWER_BALL_VISUAL);
            DoCast(SPELL_POWER_BALL_DAMAGE_TRIGGER);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            me->setFaction(16);
            events.ScheduleEvent(EVENT_DESPAWN_SPHERE, 40000);
            events.ScheduleEvent(EVENT_RANGE_CHECK, 1000);
        }

        void DoAction(int32 action) override
        {
            if (action == ACTION_SUMMON)
                DoCast(SPELL_SUMMON_PLAYERS);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case EVENT_RANGE_CHECK:
                    if (Creature* xevozz = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_XEVOZZ)))
                    {
                        if (me->IsWithinDist(xevozz, 3.0f) && !arcanePower)
                        {
                            DoCast(SPELL_ARCANE_POWER);
                            arcanePower = true;
                            events.ScheduleEvent(EVENT_DESPAWN_SPHERE, 8000);
                        }
                    }
                    events.ScheduleEvent(EVENT_RANGE_CHECK, 1000);
                    break;
                case EVENT_DESPAWN_SPHERE:
                    me->DespawnOrUnsummon();
                    break;
            }
        }

    private:
        InstanceScript* instance;
        EventMap events;
        bool arcanePower;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_ethereal_sphereAI>(creature);
    }
};

class spell_xevozz_summon_players : public SpellScriptLoader
{
public:
    spell_xevozz_summon_players() : SpellScriptLoader("spell_xevozz_summon_players") { }

    class spell_xevozz_summon_players_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_xevozz_summon_players_SpellScript);

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            Unit* target = GetHitUnit();

            if (target)
            {
                Position pos = GetOriginalCaster()->GetPosition();

                target->NearTeleportTo(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation());
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_xevozz_summon_players_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_xevozz_summon_players_SpellScript();
    }
};

class spell_xevozz_summon_ethereal_sphere : public SpellScriptLoader
{
public:
    spell_xevozz_summon_ethereal_sphere() : SpellScriptLoader("spell_xevozz_summon_ethereal_sphere") { }

    class spell_xevozz_summon_ethereal_sphere_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_xevozz_summon_ethereal_sphere_SpellScript);

        void HandleScript(SpellDestination& target)
        {
            Unit* caster = GetOriginalCaster();
            Position pos;
            float distance = 0.0f;

            while (distance < 20.0f)
            {
                pos = caster->GetRandomNearPosition(60.0f);
                distance = caster->GetDistance(pos);
            }

            target.Relocate(pos);
        }

        void Register() override
        {
            OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_xevozz_summon_ethereal_sphere_SpellScript::HandleScript, EFFECT_0, TARGET_DEST_DB);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_xevozz_summon_ethereal_sphere_SpellScript();
    }
};

void AddSC_boss_xevozz()
{
    new boss_xevozz();
    new npc_ethereal_sphere();
    new spell_xevozz_summon_players();
    new spell_xevozz_summon_ethereal_sphere();
}

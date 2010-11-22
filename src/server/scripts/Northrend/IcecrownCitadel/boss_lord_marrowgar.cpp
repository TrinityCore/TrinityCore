/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "icecrown_citadel.h"
#include "MapManager.h"

enum eScriptTexts
{
    SAY_ENTER_ZONE              = 0,
    SAY_AGGRO                   = 1,
    SAY_BONE_STORM              = 2,
    SAY_BONESPIKE               = 3,
    SAY_KILL                    = 4,
    SAY_DEATH                   = 5,
    SAY_BERSERK                 = 6,
    EMOTE_BONE_STORM            = 7,
};

enum eSpells
{
    // Lord Marrowgar
    SPELL_BONE_SLICE            = 69055,
    SPELL_BONE_STORM            = 69076,
    SPELL_BONE_SPIKE_GRAVEYARD  = 69057,
    SPELL_COLDFLAME_NORMAL      = 69140,
    SPELL_COLDFLAME_BONE_STORM  = 72705,

    // Bone Spike
    SPELL_IMPALE                = 69062,
    SPELL_IMPALED               = 69065,

    // Coldflame
    SPELL_COLDFLAME_PASSIVE     = 69145,
};

enum eEvents
{
    EVENT_BONE_SPIKE_GRAVEYARD  = 1,
    EVENT_COLDFLAME             = 2,
    EVENT_BONE_STORM_BEGIN      = 3,
    EVENT_BONE_STORM_MOVE       = 4,
    EVENT_BONE_STORM_END        = 5,
    EVENT_ENABLE_BONE_SLICE     = 6,
    EVENT_ENRAGE                = 7,
    EVENT_WARN_BONE_STORM       = 8,

    EVENT_COLDFLAME_TRIGGER     = 9,
    EVENT_FAIL_BONED            = 10,

    EVENT_GROUP_SPECIAL         = 1,
};

enum eMovementPoints
{
    POINT_TARGET_BONESTORM_PLAYER   = 36612631,
    POINT_TARGET_COLDFLAME          = 36672631,
};

class boss_lord_marrowgar : public CreatureScript
{
    public:
        boss_lord_marrowgar() : CreatureScript("boss_lord_marrowgar") { }

        struct boss_lord_marrowgarAI : public BossAI
        {
            boss_lord_marrowgarAI(Creature* creature) : BossAI(creature, DATA_LORD_MARROWGAR)
            {
                introDone = false;
                boneStormDuration = RAID_MODE(20000, 30000, 20000, 30000);
                baseSpeed = creature->GetSpeedRate(MOVE_RUN);
                boneSlice = false;
                coldflameLastPos.Relocate(creature);
            }

            void InitializeAI()
            {
                if (!instance || static_cast<InstanceMap*>(me->GetMap())->GetScriptId() != GetScriptId(ICCScriptName))
                    me->IsAIEnabled = false;
                else if (!me->isDead())
                    Reset();
            }

            void Reset()
            {
                me->SetSpeed(MOVE_RUN, baseSpeed, true);
                me->RemoveAurasDueToSpell(SPELL_BONE_STORM);
                me->RemoveAurasDueToSpell(SPELL_BERSERK);
                events.Reset();
                events.ScheduleEvent(EVENT_ENABLE_BONE_SLICE, 10000);
                events.ScheduleEvent(EVENT_BONE_SPIKE_GRAVEYARD, urand(10000, 15000), EVENT_GROUP_SPECIAL);
                events.ScheduleEvent(EVENT_COLDFLAME, 5000, EVENT_GROUP_SPECIAL);
                events.ScheduleEvent(EVENT_WARN_BONE_STORM, urand(45000, 50000));
                events.ScheduleEvent(EVENT_ENRAGE, 600000);
                instance->SetBossState(DATA_LORD_MARROWGAR, NOT_STARTED);
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_AGGRO);

                instance->SetBossState(DATA_LORD_MARROWGAR, IN_PROGRESS);
            }

            void JustDied(Unit* /*killer*/)
            {
                Talk(SAY_DEATH);

                instance->SetBossState(DATA_LORD_MARROWGAR, DONE);
            }

            void JustReachedHome()
            {
                instance->SetBossState(DATA_LORD_MARROWGAR, FAIL);
                instance->SetData(DATA_BONED_ACHIEVEMENT, uint32(true));    // reset
            }

            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (!introDone && me->IsWithinDistInMap(who, 70.0f))
                {
                    Talk(SAY_ENTER_ZONE);
                    introDone = true;
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim() || !CheckInRoom())
                    return;

                events.Update(diff);

                if (me->hasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BONE_SPIKE_GRAVEYARD:
                            if (IsHeroic() || !me->HasAura(SPELL_BONE_STORM))
                                DoCast(me, SPELL_BONE_SPIKE_GRAVEYARD);
                            events.ScheduleEvent(EVENT_BONE_SPIKE_GRAVEYARD, urand(15000, 20000), EVENT_GROUP_SPECIAL);
                            break;
                        case EVENT_COLDFLAME:
                            coldflameLastPos.Relocate(me);
                            if (!me->HasAura(SPELL_BONE_STORM))
                                me->CastCustomSpell(SPELL_COLDFLAME_NORMAL, SPELLVALUE_MAX_TARGETS, 1, me);
                            else
                                DoCast(me, SPELL_COLDFLAME_BONE_STORM);
                            events.ScheduleEvent(EVENT_COLDFLAME, 5000, EVENT_GROUP_SPECIAL);
                            break;
                        case EVENT_WARN_BONE_STORM:
                            boneSlice = false;
                            Talk(EMOTE_BONE_STORM);
                            me->FinishSpell(CURRENT_MELEE_SPELL, false);
                            DoCast(me, SPELL_BONE_STORM);
                            events.DelayEvents(3000, EVENT_GROUP_SPECIAL);
                            events.ScheduleEvent(EVENT_BONE_STORM_BEGIN, 3050);
                            break;
                        case EVENT_BONE_STORM_BEGIN:
                            if (Aura* pStorm = me->GetAura(SPELL_BONE_STORM))
                                pStorm->SetDuration(int32(boneStormDuration));
                            me->SetSpeed(MOVE_RUN, baseSpeed*3.0f, true);
                            Talk(SAY_BONE_STORM);
                            events.ScheduleEvent(EVENT_BONE_STORM_END, boneStormDuration+1);
                            // no break here
                        case EVENT_BONE_STORM_MOVE:
                        {
                            events.ScheduleEvent(EVENT_BONE_STORM_MOVE, boneStormDuration/3);
                            Unit* unit = SelectUnit(SELECT_TARGET_RANDOM, 1);
                            if (!unit)
                                unit = SelectUnit(SELECT_TARGET_RANDOM, 0);
                            if (unit)
                                me->GetMotionMaster()->MovePoint(POINT_TARGET_BONESTORM_PLAYER, unit->GetPositionX(), unit->GetPositionY(), unit->GetPositionZ());
                            break;
                        }
                        case EVENT_BONE_STORM_END:
                            if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == POINT_MOTION_TYPE)
                                me->GetMotionMaster()->MovementExpired();
                            DoStartMovement(me->getVictim());
                            me->SetSpeed(MOVE_RUN, baseSpeed, true);
                            events.CancelEvent(EVENT_BONE_STORM_MOVE);
                            events.ScheduleEvent(EVENT_ENABLE_BONE_SLICE, 10000);
                            events.ScheduleEvent(EVENT_WARN_BONE_STORM, urand(70000, 75000));
                            break;
                        case EVENT_ENABLE_BONE_SLICE:
                            boneSlice = true;
                            break;
                        case EVENT_ENRAGE:
                            DoCast(me, SPELL_BERSERK, true);
                            Talk(SAY_BERSERK);
                            break;
                    }
                }

                // We should not melee attack when storming
                if (me->HasAura(SPELL_BONE_STORM))
                    return;

                // After 10 seconds since encounter start Bone Slice replaces melee attacks
                if (boneSlice && !me->GetCurrentSpell(CURRENT_MELEE_SPELL))
                    DoCastVictim(SPELL_BONE_SLICE);

                DoMeleeAttackIfReady();
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE || id != POINT_TARGET_BONESTORM_PLAYER)
                    return;

                // lock movement
                DoStartNoMovement(me->getVictim());
            }

            const Position* GetLastColdflamePosition() const
            {
                return &coldflameLastPos;
            }

        private:
            bool introDone;
            uint32 boneStormDuration;
            float baseSpeed;
            bool boneSlice;
            Position coldflameLastPos;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_lord_marrowgarAI(creature);
        }
};

typedef boss_lord_marrowgar::boss_lord_marrowgarAI MarrowgarAI;

class npc_coldflame : public CreatureScript
{
    public:
        npc_coldflame() : CreatureScript("npc_coldflame") { }

        struct npc_coldflameAI : public ScriptedAI
        {
            npc_coldflameAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void IsSummonedBy(Unit* owner)
            {
                if (owner->GetTypeId() != TYPEID_UNIT)
                    return;
                Creature* creOwner = owner->ToCreature();
                DoCast(me, SPELL_COLDFLAME_PASSIVE, true);
                float x, y, z;
                // random target case
                if (!owner->HasAura(SPELL_BONE_STORM))
                {
                    // select any unit but not the tank (by owners threatlist)
                    Unit* target = creOwner->AI()->SelectTarget(SELECT_TARGET_RANDOM, 1, 40.0f, true);
                    if (!target)
                        target = creOwner->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true); // or the tank if its solo
                    if (!target)
                    {
                        me->ForcedDespawn();
                        return;
                    }

                    target->GetPosition(x, y, z);
                    float scale = 70.0f / me->GetExactDist2d(x, y);
                    x = me->GetPositionX() + (x - me->GetPositionX()) * scale;
                    y = me->GetPositionY() + (y - me->GetPositionY()) * scale;
                }
                else
                {
                    me->GetPosition(x, y, z);
                    MarrowgarAI* marrowgarAI = CAST_AI(MarrowgarAI, creOwner->AI());
                    Position const* ownerPos = marrowgarAI->GetLastColdflamePosition();
                    float ang = me->GetAngle(ownerPos) - static_cast<float>(M_PI);
                    MapManager::NormalizeOrientation(ang);
                    x += 50.0f * cosf(ang);
                    y += 50.0f * sinf(ang);
                }
                me->GetMotionMaster()->MovePoint(POINT_TARGET_COLDFLAME, x, y, z);
                events.ScheduleEvent(EVENT_COLDFLAME_TRIGGER, 400);
            }

            void UpdateAI(const uint32 diff)
            {
                events.Update(diff);

                if (events.ExecuteEvent() == EVENT_COLDFLAME_TRIGGER)
                {
                    if (me->HasAura(SPELL_COLDFLAME_PASSIVE))
                        DoCast(SPELL_COLDFLAME_PASSIVE);
                    events.ScheduleEvent(EVENT_COLDFLAME_TRIGGER, 400);
                }
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE || id != POINT_TARGET_COLDFLAME)
                    return;

                // stop triggering but dont despawn
                me->RemoveAura(SPELL_COLDFLAME_PASSIVE);
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_coldflameAI(creature);
        }
};

class npc_bone_spike : public CreatureScript
{
    public:
        npc_bone_spike() : CreatureScript("npc_bone_spike") { }

        struct npc_bone_spikeAI : public Scripted_NoMovementAI
        {
            npc_bone_spikeAI(Creature* creature) : Scripted_NoMovementAI(creature), vehicle(creature->GetVehicleKit())
            {
                ASSERT(vehicle);
                trappedGUID = 0;
            }

            void Reset()
            {
                trappedGUID = 0;
            }

            void JustDied(Unit* /*killer*/)
            {
                events.Reset();
                if (Player* trapped = ObjectAccessor::GetPlayer(*me, trappedGUID))
                    trapped->RemoveAurasDueToSpell(SPELL_IMPALED);
                trappedGUID = 0;
            }

            void IsSummonedBy(Unit* summoner)
            {
                trappedGUID = summoner->GetGUID();
                summoner->EnterVehicle(vehicle, 0);
                DoCast(summoner, SPELL_IMPALED);
                events.ScheduleEvent(EVENT_FAIL_BONED, 8000);
            }

            void UpdateAI(const uint32 /*diff*/)
            {
                if (!trappedGUID)
                    return;

                if (events.ExecuteEvent() == EVENT_FAIL_BONED)
                    if (InstanceScript* instance = me->GetInstanceScript())
                        instance->SetData(DATA_BONED_ACHIEVEMENT, uint32(false));
            }

        private:
            uint64 trappedGUID;
            EventMap events;
            Vehicle* vehicle;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_bone_spikeAI(creature);
        }
};

class spell_marrowgar_coldflame : public SpellScriptLoader
{
    public:
        spell_marrowgar_coldflame() : SpellScriptLoader("spell_marrowgar_coldflame") { }

        class spell_marrowgar_coldflame_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_marrowgar_coldflame_SpellScript);

            void HandleScriptEffect(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                Unit* caster = GetCaster();
                uint8 count = 1;
                if (GetSpellInfo()->Id == 72705)
                    count = 4;

                for (uint8 i = 0; i < count; ++i)
                    caster->CastSpell(caster, GetEffectValue()+i, true);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_marrowgar_coldflame_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_marrowgar_coldflame_SpellScript();
        }
};

class spell_marrowgar_bone_spike_graveyard : public SpellScriptLoader
{
    public:
        spell_marrowgar_bone_spike_graveyard() : SpellScriptLoader("spell_marrowgar_bone_spike_graveyard") { }

        class spell_marrowgar_bone_spike_graveyard_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_marrowgar_bone_spike_graveyard_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (Creature* marrowgar = GetCaster()->ToCreature())
                {
                    CreatureAI* marrowgarAI = marrowgar->AI();
                    bool yell = false;
                    uint8 boneSpikeCount = GetCaster()->GetMap()->GetSpawnMode() & 1 ? 3 : 1;
                    for (uint8 i = 0; i < boneSpikeCount; ++i)
                    {
                        // select any unit but not the tank
                        Unit* target = marrowgarAI->SelectTarget(SELECT_TARGET_RANDOM, 1, 100.0f, true, -SPELL_IMPALED);
                        if (!target && !i)
                            target = marrowgarAI->SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, -SPELL_IMPALED);
                        if (!target)
                            break;
                        yell = true;
                        target->CastCustomSpell(SPELL_IMPALE, SPELLVALUE_BASE_POINT0, 0, target, true);
                    }

                    if (yell)
                        marrowgarAI->Talk(SAY_BONESPIKE);
                }
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_marrowgar_bone_spike_graveyard_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_marrowgar_bone_spike_graveyard_SpellScript();
        }
};

class spell_marrowgar_bone_storm : public SpellScriptLoader
{
    public:
        spell_marrowgar_bone_storm() : SpellScriptLoader("spell_marrowgar_bone_storm") { }

        class spell_marrowgar_bone_storm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_marrowgar_bone_storm_SpellScript);

            void RecalculateDamage(SpellEffIndex /*effIndex*/)
            {
                int32 dmg = GetHitDamage();
                float distance = GetHitUnit()->GetExactDist2d(GetCaster());
                if (distance < 5.0f)
                    return;

                float distVar = distance >= 20.0f ? 4 : (10.0f/3.0f);
                SetHitDamage(int32(dmg * distVar / distance));
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_marrowgar_bone_storm_SpellScript::RecalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_marrowgar_bone_storm_SpellScript();
        }
};

void AddSC_boss_lord_marrowgar()
{
    new boss_lord_marrowgar();
    new npc_coldflame();
    new npc_bone_spike();
    new spell_marrowgar_coldflame();
    new spell_marrowgar_bone_spike_graveyard();
    new spell_marrowgar_bone_storm();

    // has to be done or else players threat will be wiped for impaled player and he will absorb all damage
    if (VehicleSeatEntry* vehSeat = const_cast<VehicleSeatEntry*>(sVehicleSeatStore.LookupEntry(6206)))
        vehSeat->m_flags |= 0x400;
}

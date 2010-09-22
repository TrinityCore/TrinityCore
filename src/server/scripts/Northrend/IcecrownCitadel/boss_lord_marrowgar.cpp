/*
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "ScriptPCH.h"
#include "icecrown_citadel.h"
#include "MapManager.h"
#include "Spell.h"

enum eScriptTexts
{
    SAY_ENTER_ZONE              = -1631000,
    SAY_AGGRO                   = -1631001,
    SAY_BONE_STORM              = -1631002,
    SAY_BONESPIKE_1             = -1631003,
    SAY_BONESPIKE_2             = -1631004,
    SAY_BONESPIKE_3             = -1631005,
    SAY_KILL_1                  = -1631006,
    SAY_KILL_2                  = -1631007,
    SAY_DEATH                   = -1631008,
    SAY_BERSERK                 = -1631009,
    SAY_BONE_STORM_EMOTE        = -1631010
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
    EVENT_FAIL_BONED            = 10
};

enum eMovementPoints
{
    POINT_TARGET_BONESTORM_PLAYER   = 36612631, // entry+mapid
    POINT_TARGET_COLDFLAME          = 36672631
};

class boss_lord_marrowgar : public CreatureScript
{
    public:
        boss_lord_marrowgar() : CreatureScript("boss_lord_marrowgar") { }

        struct boss_lord_marrowgarAI : public BossAI
        {
            boss_lord_marrowgarAI(Creature *pCreature) : BossAI(pCreature, DATA_LORD_MARROWGAR)
            {
                ASSERT(instance);
                bIntroDone = false;
                uiBoneStormDuration = RAID_MODE(20000,30000,20000,30000);
                fBaseSpeed = pCreature->GetSpeedRate(MOVE_RUN);
                bBoneSlice = false;
                coldflameLastPos.Relocate(pCreature);
            }

            void Reset()
            {
                me->SetSpeed(MOVE_RUN, fBaseSpeed, true);
                me->RemoveAurasDueToSpell(SPELL_BONE_STORM);
                me->RemoveAurasDueToSpell(SPELL_BERSERK);
                events.Reset();
                events.ScheduleEvent(EVENT_ENABLE_BONE_SLICE, 10000);
                events.ScheduleEvent(EVENT_BONE_SPIKE_GRAVEYARD, urand(20000, 30000));
                events.ScheduleEvent(EVENT_COLDFLAME, urand(10000, 15000));
                events.ScheduleEvent(EVENT_WARN_BONE_STORM, urand(35000, 50000));
                events.ScheduleEvent(EVENT_ENRAGE, 600000);
                instance->SetBossState(DATA_LORD_MARROWGAR, NOT_STARTED);
            }

            void EnterCombat(Unit* /*who*/)
            {
                DoScriptText(SAY_AGGRO, me);

                instance->SetBossState(DATA_LORD_MARROWGAR, IN_PROGRESS);
            }

            void JustDied(Unit* /*killer*/)
            {
                DoScriptText(SAY_DEATH, me);

                instance->SetBossState(DATA_LORD_MARROWGAR, DONE);
            }

            void JustReachedHome()
            {
                instance->SetBossState(DATA_LORD_MARROWGAR, FAIL);
            }

            void KilledUnit(Unit *victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    DoScriptText(RAND(SAY_KILL_1, SAY_KILL_2), me);
            }

            void MoveInLineOfSight(Unit *who)
            {
                if (!bIntroDone && me->IsWithinDistInMap(who, 70.0f))
                {
                    DoScriptText(SAY_ENTER_ZONE, me);
                    bIntroDone = true;
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
                            events.ScheduleEvent(EVENT_BONE_SPIKE_GRAVEYARD, urand(25000, 35000));
                            break;
                        case EVENT_COLDFLAME:
                            coldflameLastPos.Relocate(me);
                            if (!me->HasAura(SPELL_BONE_STORM))
                                me->CastCustomSpell(SPELL_COLDFLAME_NORMAL, SPELLVALUE_MAX_TARGETS, 1, me);
                            else
                                DoCast(me, SPELL_COLDFLAME_BONE_STORM);
                            events.ScheduleEvent(EVENT_COLDFLAME, urand(10000, 15000));
                            break;
                        case EVENT_WARN_BONE_STORM:
                            bBoneSlice = false;
                            DoScriptText(SAY_BONE_STORM_EMOTE, me);
                            events.ScheduleEvent(EVENT_BONE_STORM_BEGIN, 3050);
                            me->FinishSpell(CURRENT_MELEE_SPELL, false);
                            DoCast(me, SPELL_BONE_STORM);
                            break;
                        case EVENT_BONE_STORM_BEGIN:
                            if (Aura* pStorm = me->GetAura(SPELL_BONE_STORM))
                                pStorm->SetDuration(int32(uiBoneStormDuration));
                            me->SetSpeed(MOVE_RUN, fBaseSpeed*3.0f, true);
                            DoScriptText(SAY_BONE_STORM, me);
                            events.ScheduleEvent(EVENT_BONE_STORM_END, uiBoneStormDuration+1);
                            // no break here
                        case EVENT_BONE_STORM_MOVE:
                        {
                            events.ScheduleEvent(EVENT_BONE_STORM_MOVE, uiBoneStormDuration/3);
                            Unit* pUnit = SelectUnit(SELECT_TARGET_RANDOM, 1);
                            if (!pUnit)
                                pUnit = SelectUnit(SELECT_TARGET_RANDOM, 0);
                            if (pUnit)
                                me->GetMotionMaster()->MovePoint(POINT_TARGET_BONESTORM_PLAYER, pUnit->GetPositionX(), pUnit->GetPositionY(), pUnit->GetPositionZ());
                            break;
                        }
                        case EVENT_BONE_STORM_END:
                            if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == POINT_MOTION_TYPE)
                                me->GetMotionMaster()->MovementExpired();
                            DoStartMovement(me->getVictim());
                            me->SetSpeed(MOVE_RUN, fBaseSpeed, true);
                            events.CancelEvent(EVENT_BONE_STORM_MOVE);
                            events.ScheduleEvent(EVENT_ENABLE_BONE_SLICE, 10000);
                            events.ScheduleEvent(EVENT_WARN_BONE_STORM, urand(35000, 50000));
                            break;
                        case EVENT_ENABLE_BONE_SLICE:
                            bBoneSlice = true;
                            break;
                        case EVENT_ENRAGE:
                            DoCast(me, SPELL_BERSERK, true);
                            DoScriptText(SAY_BERSERK, me);
                            break;
                    }
                }

                // We should not melee attack when storming
                if (me->HasAura(SPELL_BONE_STORM))
                    return;

                // After 10 seconds since encounter start Bone Slice replaces melee attacks
                if (bBoneSlice && !me->GetCurrentSpell(CURRENT_MELEE_SPELL))
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
            bool bIntroDone;
            uint32 uiBoneStormDuration;
            float fBaseSpeed;
            bool bBoneSlice;
            Position coldflameLastPos;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new boss_lord_marrowgarAI(pCreature);
        }
};

class npc_coldflame : public CreatureScript
{
    public:
        npc_coldflame() : CreatureScript("npc_coldflame") { }

        struct npc_coldflameAI : public ScriptedAI
        {
            npc_coldflameAI(Creature *pCreature) : ScriptedAI(pCreature)
            {
            }

            void IsSummonedBy(Unit* owner)
            {
                DoCast(me, SPELL_COLDFLAME_PASSIVE, true);
                float x, y, z;
                // random target case
                if (!owner->HasAura(SPELL_BONE_STORM) && owner->GetTypeId() == TYPEID_UNIT)
                {
                    Creature* creOwner = owner->ToCreature();
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
                    Position const* ownerPos = CAST_AI(boss_lord_marrowgar::boss_lord_marrowgarAI, owner->ToCreature()->AI())->GetLastColdflamePosition();
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

                while (uint32 eventId = events.ExecuteEvent())
                {
                    if (eventId == EVENT_COLDFLAME_TRIGGER)
                    {
                        if (me->HasAura(SPELL_COLDFLAME_PASSIVE))
                            DoCast(SPELL_COLDFLAME_PASSIVE);
                        events.ScheduleEvent(EVENT_COLDFLAME_TRIGGER, 400);
                    }
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

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_coldflameAI(pCreature);
        }
};

class npc_bone_spike : public CreatureScript
{
    public:
        npc_bone_spike() : CreatureScript("npc_bone_spike") { }

        struct npc_bone_spikeAI : public Scripted_NoMovementAI
        {
            npc_bone_spikeAI(Creature *pCreature) : Scripted_NoMovementAI(pCreature), vehicle(pCreature->GetVehicleKit())
            {
                ASSERT(vehicle);
                uiTrappedGUID = 0;
            }

            void Reset()
            {
                uiTrappedGUID = 0;
            }

            void JustDied(Unit * /*killer*/)
            {
                events.Reset();
                if (Unit* trapped = Unit::GetUnit((*me), uiTrappedGUID))
                    trapped->RemoveAurasDueToSpell(SPELL_IMPALED);
            }

            void KilledUnit(Unit * /*pVictim*/)
            {
                me->Kill(me);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!uiTrappedGUID)
                    return;

                events.Update(diff);
                Unit* trapped = Unit::GetUnit(*me, uiTrappedGUID);
                if ((trapped && trapped->isAlive() && !trapped->HasAura(SPELL_IMPALED)) || !trapped)
                    me->Kill(me);

                if (events.ExecuteEvent() == EVENT_FAIL_BONED)
                    if (InstanceScript* instance = me->GetInstanceScript())
                        instance->SetData(COMMAND_FAIL_BONED, 0);
            }

            void SetTrappedUnit(Unit* unit)
            {
                unit->EnterVehicle(vehicle, 0);
                uiTrappedGUID = unit->GetGUID();
            }

            void PassengerBoarded(Unit * who, int8 /*seatId*/, bool apply)
            {
                if (!apply)
                    return;

                me->AddAura(SPELL_IMPALED, who);
                events.ScheduleEvent(EVENT_FAIL_BONED, 8000);
            }

        private:
            uint64 uiTrappedGUID;
            EventMap events;
            Vehicle* vehicle;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_bone_spikeAI(pCreature);
        }
};

class spell_marrowgar_coldflame : public SpellScriptLoader
{
    public:
        spell_marrowgar_coldflame() : SpellScriptLoader("spell_marrowgar_coldflame") { }

        class spell_marrowgar_coldflame_SpellScript : public SpellScript
        {
            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
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

            bool Load()
            {
                if (GetCaster()->GetEntry() != NPC_LORD_MARROWGAR)
                    return false;
                return true;
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
            void HandleApplyAura(SpellEffIndex /*effIndex*/)
            {
                CreatureAI* marrowgarAI = GetCaster()->ToCreature()->AI();
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
                    //marrowgarAI->DoCast(*itr, SPELL_IMPALE);    // this is the proper spell but if we use it we dont have any way to assign a victim to it
                    Creature* pBone = GetCaster()->SummonCreature(NPC_BONE_SPIKE, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN);
                    CAST_AI(npc_bone_spike::npc_bone_spikeAI, pBone->AI())->SetTrappedUnit(target);
                }

                if (yell)
                    DoScriptText(RAND(SAY_BONESPIKE_1, SAY_BONESPIKE_2, SAY_BONESPIKE_3), GetCaster());
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_marrowgar_bone_spike_graveyard_SpellScript::HandleApplyAura, EFFECT_1, SPELL_EFFECT_APPLY_AURA);
            }

            bool Load()
            {
                if (GetCaster()->GetEntry() != NPC_LORD_MARROWGAR)
                    return false;
                return true;
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

            bool Load()
            {
                if (GetCaster()->GetEntry() != NPC_LORD_MARROWGAR)
                    return false;
                return true;
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

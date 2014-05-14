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

/* ScriptData
SDName: Assembly of Iron encounter
SD%Complete: 60%
SDComment: chain lightning won't cast, supercharge don't work (auras don't stack from different casters)
SDCategory: Ulduar - Ulduar
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "ulduar.h"

enum AssemblySpells
{
    // General
    SPELL_SUPERCHARGE                            = 61920,
    SPELL_BERSERK                                = 47008, // Hard enrage, don't know the correct ID.
    SPELL_KILL_CREDIT                            = 65195, // spell_dbc

    // Steelbreaker
    SPELL_HIGH_VOLTAGE                           = 61890,
    SPELL_FUSION_PUNCH                           = 61903,
    SPELL_STATIC_DISRUPTION                      = 44008,
    SPELL_OVERWHELMING_POWER                     = 64637,
    SPELL_ELECTRICAL_CHARGE                      = 61902,

    // Runemaster Molgeim
    SPELL_SHIELD_OF_RUNES                        = 62274,
    SPELL_SHIELD_OF_RUNES_BUFF                   = 62277,
    SPELL_SUMMON_RUNE_OF_POWER                   = 63513,
    SPELL_RUNE_OF_DEATH                          = 62269,
    SPELL_RUNE_OF_SUMMONING                      = 62273, // This is the spell that summons the rune
    SPELL_RUNE_OF_SUMMONING_SUMMON               = 62020, // Spell that summons

    // Stormcaller Brundir
    SPELL_CHAIN_LIGHTNING                        = 61879,
    SPELL_OVERLOAD                               = 61869,
    SPELL_LIGHTNING_WHIRL                        = 61915,
    SPELL_LIGHTNING_TENDRILS_10M                 = 61887,
    SPELL_LIGHTNING_TENDRILS_25M                 = 63486,
    SPELL_LIGHTNING_TENDRILS_VISUAL              = 61883,
    SPELL_STORMSHIELD                            = 64187
};

enum AssemblyEvents
{
    // General
    EVENT_BERSERK                                = 1,

    // Steelbreaker
    EVENT_FUSION_PUNCH                           = 2,
    EVENT_STATIC_DISRUPTION                      = 3,
    EVENT_OVERWHELMING_POWER                     = 4,

    // Molgeim
    EVENT_RUNE_OF_POWER                          = 5,
    EVENT_SHIELD_OF_RUNES                        = 6,
    EVENT_RUNE_OF_DEATH                          = 7,
    EVENT_RUNE_OF_SUMMONING                      = 8,
    EVENT_LIGHTNING_BLAST                        = 9,

    // Brundir
    EVENT_CHAIN_LIGHTNING                        = 10,
    EVENT_OVERLOAD                               = 11,
    EVENT_LIGHTNING_WHIRL                        = 12,
    EVENT_LIGHTNING_TENDRILS                     = 13,
    EVENT_FLIGHT                                 = 14,
    EVENT_ENDFLIGHT                              = 15,
    EVENT_GROUND                                 = 16,
    EVENT_LAND                                   = 17,
    EVENT_MOVE_POSITION                          = 18
};

enum AssemblyActions
{
    ACTION_SUPERCHARGE                           = 1,
    ACTION_ADD_CHARGE                            = 2
};

enum AssemblyYells
{
    SAY_STEELBREAKER_AGGRO                      = 0,
    SAY_STEELBREAKER_SLAY                       = 1,
    SAY_STEELBREAKER_POWER                      = 2,
    SAY_STEELBREAKER_DEATH                      = 3,
    SAY_STEELBREAKER_ENCOUNTER_DEFEATED         = 4,
    SAY_STEELBREAKER_BERSERK                    = 5,

    SAY_MOLGEIM_AGGRO                           = 0,
    SAY_MOLGEIM_SLAY                            = 1,
    SAY_MOLGEIM_RUNE_DEATH                      = 2,
    SAY_MOLGEIM_SUMMON                          = 3,
    SAY_MOLGEIM_DEATH                           = 4,
    SAY_MOLGEIM_ENCOUNTER_DEFEATED              = 5,
    SAY_MOLGEIM_BERSERK                         = 6,

    SAY_BRUNDIR_AGGRO                           = 0,
    SAY_BRUNDIR_SLAY                            = 1,
    SAY_BRUNDIR_SPECIAL                         = 2,
    SAY_BRUNDIR_FLIGHT                          = 3,
    SAY_BRUNDIR_DEATH                           = 4,
    SAY_BRUNDIR_ENCOUNTER_DEFEATED              = 5,
    SAY_BRUNDIR_BERSERK                         = 6,
    EMOTE_BRUNDIR_OVERLOAD                      = 7
};

enum Misc
{
    NPC_WORLD_TRIGGER                            = 22515,

    DATA_PHASE_3                                 = 1
};

#define FLOOR_Z                                  427.28f
#define FINAL_FLIGHT_Z                           435.0f

class boss_steelbreaker : public CreatureScript
{
    public:
        boss_steelbreaker() : CreatureScript("boss_steelbreaker") { }

        struct boss_steelbreakerAI : public BossAI
        {
            boss_steelbreakerAI(Creature* creature) : BossAI(creature, BOSS_ASSEMBLY_OF_IRON) { }

            uint32 phase;

            void Reset() override
            {
                _Reset();
                phase = 0;
                me->RemoveAllAuras();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                Talk(SAY_STEELBREAKER_AGGRO);
                DoCast(me, SPELL_HIGH_VOLTAGE);
                events.SetPhase(++phase);
                events.ScheduleEvent(EVENT_BERSERK, 900000);
                events.ScheduleEvent(EVENT_FUSION_PUNCH, 15000);
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_PHASE_3)
                    return (phase >= 3) ? 1 : 0;

                return 0;
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_SUPERCHARGE:
                        me->SetFullHealth();
                        me->AddAura(SPELL_SUPERCHARGE, me);
                        events.SetPhase(++phase);
                        events.RescheduleEvent(EVENT_FUSION_PUNCH, 15000);
                        if (phase >= 2)
                            events.RescheduleEvent(EVENT_STATIC_DISRUPTION, 30000);
                        if (phase >= 3)
                            events.RescheduleEvent(EVENT_OVERWHELMING_POWER, urand(2000, 5000));
                        break;
                    case ACTION_ADD_CHARGE:
                        DoCast(me, SPELL_ELECTRICAL_CHARGE, true);
                        break;
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();

                if (instance->GetBossState(BOSS_ASSEMBLY_OF_IRON) == DONE)
                {
                    DoCastAOE(SPELL_KILL_CREDIT, true);
                    Talk(SAY_STEELBREAKER_ENCOUNTER_DEFEATED);
                }
                else
                {
                    me->SetLootRecipient(NULL);
                    Talk(SAY_STEELBREAKER_DEATH);
                    //DoCastAOE(SPELL_SUPERCHARGE, true);

                    if (Creature* Brundir = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_BRUNDIR)))
                        if (Brundir->IsAlive())
                            Brundir->AI()->DoAction(ACTION_SUPERCHARGE);

                    if (Creature* Molgeim = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_MOLGEIM)))
                        if (Molgeim->IsAlive())
                            Molgeim->AI()->DoAction(ACTION_SUPERCHARGE);
                }
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_STEELBREAKER_SLAY);

                if (phase == 3)
                    DoCast(me, SPELL_ELECTRICAL_CHARGE);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BERSERK:
                            Talk(SAY_STEELBREAKER_BERSERK);
                            DoCast(SPELL_BERSERK);
                            events.CancelEvent(EVENT_BERSERK);
                            break;
                        case EVENT_FUSION_PUNCH:
                            if (me->IsWithinMeleeRange(me->GetVictim()))
                                DoCastVictim(SPELL_FUSION_PUNCH);
                            events.ScheduleEvent(EVENT_FUSION_PUNCH, urand(13000, 22000));
                            break;
                        case EVENT_STATIC_DISRUPTION:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_STATIC_DISRUPTION);
                            events.ScheduleEvent(EVENT_STATIC_DISRUPTION, urand(20000, 40000));
                            break;
                        case EVENT_OVERWHELMING_POWER:
                            Talk(SAY_STEELBREAKER_POWER);
                            DoCastVictim(SPELL_OVERWHELMING_POWER);
                            events.ScheduleEvent(EVENT_OVERWHELMING_POWER, RAID_MODE(60000, 35000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<boss_steelbreakerAI>(creature);
        }
};

class boss_runemaster_molgeim : public CreatureScript
{
    public:
        boss_runemaster_molgeim() : CreatureScript("boss_runemaster_molgeim") { }

        struct boss_runemaster_molgeimAI : public BossAI
        {
            boss_runemaster_molgeimAI(Creature* creature) : BossAI(creature, BOSS_ASSEMBLY_OF_IRON) { }

            uint32 phase;

            void Reset() override
            {
                _Reset();
                phase = 0;
                me->RemoveAllAuras();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                Talk(SAY_MOLGEIM_AGGRO);
                events.SetPhase(++phase);
                events.ScheduleEvent(EVENT_BERSERK, 900000);
                events.ScheduleEvent(EVENT_SHIELD_OF_RUNES, 30000);
                events.ScheduleEvent(EVENT_RUNE_OF_POWER, 20000);
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_PHASE_3)
                    return (phase >= 3) ? 1 : 0;

                return 0;
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_SUPERCHARGE:
                    {
                        me->SetFullHealth();
                        me->AddAura(SPELL_SUPERCHARGE, me);
                        events.SetPhase(++phase);
                        events.RescheduleEvent(EVENT_SHIELD_OF_RUNES, 27000);
                        events.RescheduleEvent(EVENT_RUNE_OF_POWER, 25000);
                        if (phase >= 2)
                            events.RescheduleEvent(EVENT_RUNE_OF_DEATH, 30000);
                        if (phase >= 3)
                            events.RescheduleEvent(EVENT_RUNE_OF_SUMMONING, urand(20000, 30000));
                        break;
                    }
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();

                if (instance->GetBossState(BOSS_ASSEMBLY_OF_IRON) == DONE)
                {
                    DoCastAOE(SPELL_KILL_CREDIT, true);
                    Talk(SAY_MOLGEIM_ENCOUNTER_DEFEATED);
                }
                else
                {
                    me->SetLootRecipient(NULL);
                    Talk(SAY_MOLGEIM_DEATH);
                    //DoCastAOE(SPELL_SUPERCHARGE, true);

                    if (Creature* Brundir = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_BRUNDIR)))
                        if (Brundir->IsAlive())
                            Brundir->AI()->DoAction(ACTION_SUPERCHARGE);

                    if (Creature* Steelbreaker = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_STEELBREAKER)))
                        if (Steelbreaker->IsAlive())
                            Steelbreaker->AI()->DoAction(ACTION_SUPERCHARGE);
                }
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_MOLGEIM_SLAY);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BERSERK:
                            Talk(SAY_MOLGEIM_BERSERK);
                            DoCast(SPELL_BERSERK);
                            events.CancelEvent(EVENT_BERSERK);
                            break;
                        case EVENT_RUNE_OF_POWER:
                        {
                            Unit* target = me;
                            switch (urand(0, 2))
                            {
                                case 1:
                                    if (Creature* Steelbreaker = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_STEELBREAKER)))
                                        if (Steelbreaker->IsAlive())
                                            target = Steelbreaker;
                                    break;
                                case 2:
                                    if (Creature* Brundir = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_STEELBREAKER)))
                                        if (Brundir->IsAlive())
                                            target = Brundir;
                                    break;
                                default:
                                    break;
                            }
                            DoCast(target, SPELL_SUMMON_RUNE_OF_POWER);
                            events.ScheduleEvent(EVENT_RUNE_OF_POWER, 60000);
                            break;
                        }
                        case EVENT_SHIELD_OF_RUNES:
                            DoCast(me, SPELL_SHIELD_OF_RUNES);
                            events.ScheduleEvent(EVENT_SHIELD_OF_RUNES, urand(27000, 34000));
                            break;
                        case EVENT_RUNE_OF_DEATH:
                            Talk(SAY_MOLGEIM_RUNE_DEATH);
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_RUNE_OF_DEATH);
                            events.ScheduleEvent(EVENT_RUNE_OF_DEATH, urand(30000, 40000));
                            break;
                        case EVENT_RUNE_OF_SUMMONING:
                            Talk(SAY_MOLGEIM_SUMMON);
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_RUNE_OF_SUMMONING);
                            events.ScheduleEvent(EVENT_RUNE_OF_SUMMONING, urand(30000, 45000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<boss_runemaster_molgeimAI>(creature);
        }
};

class boss_stormcaller_brundir : public CreatureScript
{
    public:
        boss_stormcaller_brundir() : CreatureScript("boss_stormcaller_brundir") { }

        struct boss_stormcaller_brundirAI : public BossAI
        {
            boss_stormcaller_brundirAI(Creature* creature) : BossAI(creature, BOSS_ASSEMBLY_OF_IRON) { }

            uint32 phase;

            void Reset() override
            {
                _Reset();
                phase = 0;
                me->RemoveAllAuras();
                me->SetDisableGravity(false);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, false);  // Should be interruptable unless overridden by spell (Overload)
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, false);       // Reset immumity, Brundir should be stunnable by default
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_PHASE_3)
                    return (phase >= 3) ? 1 : 0;

                return 0;
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                Talk(SAY_BRUNDIR_AGGRO);
                events.SetPhase(++phase);
                events.ScheduleEvent(EVENT_MOVE_POSITION, 1000);
                events.ScheduleEvent(EVENT_BERSERK, 900000);
                events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 4000);
                events.ScheduleEvent(EVENT_OVERLOAD, urand(60000, 120000));
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_SUPERCHARGE:
                    {
                        me->SetFullHealth();
                        me->AddAura(SPELL_SUPERCHARGE, me);
                        events.SetPhase(++phase);
                        events.RescheduleEvent(EVENT_CHAIN_LIGHTNING, urand(7000, 12000));
                        events.RescheduleEvent(EVENT_OVERLOAD, urand(40000, 50000));
                        if (phase >= 2)
                            events.RescheduleEvent(EVENT_LIGHTNING_WHIRL, urand(15000, 250000));
                        if (phase >= 3)
                        {
                            DoCast(me, SPELL_STORMSHIELD);
                            events.RescheduleEvent(EVENT_LIGHTNING_TENDRILS, urand(50000, 60000));
                            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true); // Apply immumity to stuns
                        }
                        break;
                    }
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();

                if (instance->GetBossState(BOSS_ASSEMBLY_OF_IRON) == DONE)
                {
                    DoCastAOE(SPELL_KILL_CREDIT, true);
                    Talk(SAY_BRUNDIR_ENCOUNTER_DEFEATED);
                }
                else
                {
                    me->SetLootRecipient(NULL);
                    Talk(SAY_BRUNDIR_DEATH);
                    //DoCastAOE(SPELL_SUPERCHARGE, true);

                    if (Creature* Molgeim = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_MOLGEIM)))
                        if (Molgeim->IsAlive())
                            Molgeim->AI()->DoAction(ACTION_SUPERCHARGE);

                    if (Creature* Steelbreaker = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_STEELBREAKER)))
                        if (Steelbreaker->IsAlive())
                            Steelbreaker->AI()->DoAction(ACTION_SUPERCHARGE);
                }

                // Prevent to have Brundir somewhere in the air when he die in Air phase
                if (me->GetPositionZ() > FLOOR_Z)
                    me->GetMotionMaster()->MoveFall();
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_BRUNDIR_SLAY);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BERSERK:
                            Talk(SAY_BRUNDIR_BERSERK);
                            DoCast(SPELL_BERSERK);
                            events.CancelEvent(EVENT_BERSERK);
                            break;
                        case EVENT_CHAIN_LIGHTNING:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_CHAIN_LIGHTNING);
                            events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, urand(7000, 10000));
                            break;
                        case EVENT_OVERLOAD:
                            Talk(EMOTE_BRUNDIR_OVERLOAD);
                            Talk(SAY_BRUNDIR_SPECIAL);
                            DoCast(SPELL_OVERLOAD);
                            events.ScheduleEvent(EVENT_OVERLOAD, urand(60000, 120000));
                            break;
                        case EVENT_LIGHTNING_WHIRL:
                            DoCast(SPELL_LIGHTNING_WHIRL);
                            events.ScheduleEvent(EVENT_LIGHTNING_WHIRL, urand(15000, 20000));
                            break;
                        case EVENT_LIGHTNING_TENDRILS:
                            Talk(SAY_BRUNDIR_FLIGHT);
                            DoCast(RAID_MODE(SPELL_LIGHTNING_TENDRILS_10M, SPELL_LIGHTNING_TENDRILS_25M));
                            DoCast(SPELL_LIGHTNING_TENDRILS_VISUAL);
                            me->AttackStop();
                            //me->SetLevitate(true);
                            me->GetMotionMaster()->Initialize();
                            me->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), FINAL_FLIGHT_Z);
                            events.DelayEvents(35000);
                            events.ScheduleEvent(EVENT_FLIGHT, 2500);
                            events.ScheduleEvent(EVENT_ENDFLIGHT, 32500);
                            events.ScheduleEvent(EVENT_LIGHTNING_TENDRILS, 90000);
                            break;
                        case EVENT_FLIGHT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                me->GetMotionMaster()->MovePoint(0, target->GetPositionX(), target->GetPositionY(), FINAL_FLIGHT_Z);
                            events.ScheduleEvent(EVENT_FLIGHT, 6000);
                            break;
                        case EVENT_ENDFLIGHT:
                            me->GetMotionMaster()->Initialize();
                            me->GetMotionMaster()->MovePoint(0, 1586.920166f, 119.848984f, FINAL_FLIGHT_Z);
                            events.CancelEvent(EVENT_FLIGHT);
                            events.CancelEvent(EVENT_ENDFLIGHT);
                            events.ScheduleEvent(EVENT_LAND, 4000);
                            break;
                        case EVENT_LAND:
                            me->GetMotionMaster()->Initialize();
                            me->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), FLOOR_Z);
                            events.CancelEvent(EVENT_LAND);
                            events.ScheduleEvent(EVENT_GROUND, 2500);
                            break;
                        case EVENT_GROUND:
                            //me->SetLevitate(false);
                            me->RemoveAurasDueToSpell(RAID_MODE(SPELL_LIGHTNING_TENDRILS_10M, SPELL_LIGHTNING_TENDRILS_25M));
                            me->RemoveAurasDueToSpell(SPELL_LIGHTNING_TENDRILS_VISUAL);
                            DoStartMovement(me->GetVictim());
                            events.CancelEvent(EVENT_GROUND);
                            me->getThreatManager().resetAllAggro();
                            break;
                        case EVENT_MOVE_POSITION:
                            if (me->IsWithinMeleeRange(me->GetVictim()))
                            {
                                float x = float(irand(-25, 25));
                                float y = float(irand(-25, 25));
                                me->GetMotionMaster()->MovePoint(0, me->GetPositionX() + x, me->GetPositionY() + y, FLOOR_Z);
                                // Prevention to go outside the room or into the walls
                                if (Creature* trigger = me->FindNearestCreature(NPC_WORLD_TRIGGER, 100.0f, true))
                                    if (me->GetDistance(trigger) >= 50.0f)
                                        me->GetMotionMaster()->MovePoint(0, trigger->GetPositionX(), trigger->GetPositionY(), FLOOR_Z);
                            }
                            events.ScheduleEvent(EVENT_MOVE_POSITION, urand(7500, 10000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<boss_stormcaller_brundirAI>(creature);
        }
};

class spell_shield_of_runes : public SpellScriptLoader
{
    public:
        spell_shield_of_runes() : SpellScriptLoader("spell_shield_of_runes") { }

        class spell_shield_of_runes_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_shield_of_runes_AuraScript)

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
                        caster->CastSpell(caster, SPELL_SHIELD_OF_RUNES_BUFF, false);
            }

            void Register() override
            {
                 AfterEffectRemove += AuraEffectRemoveFn(spell_shield_of_runes_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_shield_of_runes_AuraScript();
        }
};

class spell_assembly_meltdown : public SpellScriptLoader
{
    public:
        spell_assembly_meltdown() : SpellScriptLoader("spell_assembly_meltdown") { }

        class spell_assembly_meltdown_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_assembly_meltdown_SpellScript)

            void HandleInstaKill(SpellEffIndex /*effIndex*/)
            {
                if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                    if (Creature* Steelbreaker = ObjectAccessor::GetCreature(*GetCaster(), instance->GetData64(DATA_STEELBREAKER)))
                        Steelbreaker->AI()->DoAction(ACTION_ADD_CHARGE);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_assembly_meltdown_SpellScript::HandleInstaKill, EFFECT_1, SPELL_EFFECT_INSTAKILL);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_assembly_meltdown_SpellScript();
        }
};

class spell_assembly_rune_of_summoning : public SpellScriptLoader
{
    public:
        spell_assembly_rune_of_summoning() : SpellScriptLoader("spell_assembly_rune_of_summoning") { }

        class spell_assembly_rune_of_summoning_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_assembly_rune_of_summoning_AuraScript)

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_RUNE_OF_SUMMONING_SUMMON))
                    return false;
                return true;
            }

            void HandlePeriodic(AuraEffect const* aurEff)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_RUNE_OF_SUMMONING_SUMMON, true, NULL, aurEff, GetTarget()->IsSummon() ? GetTarget()->ToTempSummon()->GetSummonerGUID() : 0);
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (TempSummon* summ = GetTarget()->ToTempSummon())
                    summ->DespawnOrUnsummon(1);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_assembly_rune_of_summoning_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
                OnEffectRemove += AuraEffectRemoveFn(spell_assembly_rune_of_summoning_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_assembly_rune_of_summoning_AuraScript();
        }
};

class achievement_assembly_i_choose_you : public AchievementCriteriaScript
{
    public:
        achievement_assembly_i_choose_you() : AchievementCriteriaScript("achievement_assembly_i_choose_you") { }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            return target && target->GetAI()->GetData(DATA_PHASE_3);
        }
};

void AddSC_boss_assembly_of_iron()
{
    new boss_steelbreaker();
    new boss_runemaster_molgeim();
    new boss_stormcaller_brundir();
    new spell_shield_of_runes();
    new spell_assembly_meltdown();
    new spell_assembly_rune_of_summoning();
    new achievement_assembly_i_choose_you();
}

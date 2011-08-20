/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
SDComment: Runes need DB support, chain lightning won't cast, supercharge won't cast (target error?) - it worked before during debugging.
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
    SPELL_RUNE_OF_POWER                          = 61974,
    SPELL_RUNE_OF_DEATH                          = 62269,
    SPELL_RUNE_OF_SUMMONING                      = 62273, // This is the spell that summons the rune
    SPELL_RUNE_OF_SUMMONING_VIS                  = 62019, // Visual
    SPELL_RUNE_OF_SUMMONING_SUMMON               = 62020, // Spell that summons
    SPELL_LIGHTNING_ELEMENTAL_PASSIVE            = 62052,

    // Stormcaller Brundir
    SPELL_CHAIN_LIGHTNING                        = 61879,
    SPELL_OVERLOAD                               = 61869,
    SPELL_LIGHTNING_WHIRL                        = 61915,
    SPELL_LIGHTNING_TENDRILS                     = 61887,
    SPELL_LIGHTNING_TENDRILS_SELF_VISUAL         = 61883,
    SPELL_STORMSHIELD                            = 64187,
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
    EVENT_MOVE_POSITION                          = 18,
};

enum AssemblyActions
{
    ACTION_STEELBREAKER                          = 0,
    ACTION_MOLGEIM                               = 1,
    ACTION_BRUNDIR                               = 2,
    ACTION_ADD_CHARGE                            = 3,
};

enum AssemblyYells
{
    SAY_STEELBREAKER_AGGRO                      = -1603020,
    SAY_STEELBREAKER_SLAY_1                     = -1603021,
    SAY_STEELBREAKER_SLAY_2                     = -1603022,
    SAY_STEELBREAKER_POWER                      = -1603023,
    SAY_STEELBREAKER_DEATH_1                    = -1603024,
    SAY_STEELBREAKER_DEATH_2                    = -1603025,
    SAY_STEELBREAKER_BERSERK                    = -1603026,

    SAY_MOLGEIM_AGGRO                           = -1603030,
    SAY_MOLGEIM_SLAY_1                          = -1603031,
    SAY_MOLGEIM_SLAY_2                          = -1603032,
    SAY_MOLGEIM_RUNE_DEATH                      = -1603033,
    SAY_MOLGEIM_SUMMON                          = -1603034,
    SAY_MOLGEIM_DEATH_1                         = -1603035,
    SAY_MOLGEIM_DEATH_2                         = -1603036,
    SAY_MOLGEIM_BERSERK                         = -1603037,

    SAY_BRUNDIR_AGGRO                           = -1603040,
    SAY_BRUNDIR_SLAY_1                          = -1603041,
    SAY_BRUNDIR_SLAY_2                          = -1603042,
    SAY_BRUNDIR_SPECIAL                         = -1603043,
    SAY_BRUNDIR_FLIGHT                          = -1603044,
    SAY_BRUNDIR_DEATH_1                         = -1603045,
    SAY_BRUNDIR_DEATH_2                         = -1603046,
    SAY_BRUNDIR_BERSERK                         = -1603047,
};

enum AssemblyNPCs
{
    NPC_WORLD_TRIGGER                            = 22515,
};

#define EMOTE_OVERLOAD                           "Stormcaller Brundir begins to Overload!" // Move it to DB
#define FLOOR_Z                                  427.28f
#define FINAL_FLIGHT_Z                           435.0f

bool IsEncounterComplete(InstanceScript* instance, Creature* me)
{
    if (!instance || !me)
        return false;

    for (uint8 i = 0; i < 3; ++i)
    {
        uint64 guid = instance->GetData64(BOSS_STEELBREAKER + i);
        if (!guid)
            return false;

        if (Creature* boss = ObjectAccessor::GetCreature(*me, guid))
        {
            if (boss->isAlive())
                return false;
        }
        else
            return false;
    }

    return true;
}

void RespawnEncounter(InstanceScript* instance, Creature* me)
{
    for (uint8 i = 0; i < 3; ++i)
    {
        uint64 guid = instance->GetData64(BOSS_STEELBREAKER + i);
        if (!guid)
            continue;

        if (Creature* boss = ObjectAccessor::GetCreature(*me, guid))
        {
            if (!boss->isAlive())
            {
                boss->Respawn();
                boss->GetMotionMaster()->MoveTargetedHome();
            }
        }
    }
}

void StartEncounter(InstanceScript* instance, Creature* me, Unit* /*target*/)
{
    if (instance->GetBossState(BOSS_ASSEMBLY_OF_IRON) == IN_PROGRESS)
        return; // Prevent recursive calls

    instance->SetBossState(BOSS_ASSEMBLY_OF_IRON, IN_PROGRESS);

    for (uint8 i = 0; i < 3; ++i)
    {
        uint64 guid = instance->GetData64(BOSS_STEELBREAKER + i);
        if (!guid)
            continue;

        if (Creature* boss = ObjectAccessor::GetCreature(*me, guid))
            boss->SetInCombatWithZone();
    }
}

class boss_steelbreaker : public CreatureScript
{
    public:
        boss_steelbreaker() : CreatureScript("boss_steelbreaker") { }

        struct boss_steelbreakerAI : public BossAI
        {
            boss_steelbreakerAI(Creature* creature) : BossAI(creature, BOSS_ASSEMBLY_OF_IRON)
            {
                instance = me->GetInstanceScript();
            }

            InstanceScript* instance;
            uint32 phase;

            void Reset()
            {
                _Reset();
                phase = 0;
                me->ResetLootMode();
                me->RemoveAllAuras();
                RespawnEncounter(instance, me);
            }

            void EnterCombat(Unit* who)
            {
                StartEncounter(instance, me, who);
                DoScriptText(SAY_STEELBREAKER_AGGRO, me);
                DoZoneInCombat();
                DoCast(me, SPELL_HIGH_VOLTAGE);
                events.SetPhase(++phase);
                events.ScheduleEvent(EVENT_BERSERK, 900000);
                events.ScheduleEvent(EVENT_FUSION_PUNCH, 15000);
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_STEELBREAKER:
                        me->SetHealth(me->GetMaxHealth());
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

            void JustDied(Unit* /*who*/)
            {
                DoScriptText(RAND(SAY_STEELBREAKER_DEATH_1, SAY_STEELBREAKER_DEATH_2), me);
                if (IsEncounterComplete(instance, me))
                    instance->SetData(BOSS_ASSEMBLY_OF_IRON, DONE);
                else
                    me->SetLootRecipient(NULL);

                if (Creature* Brundir = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_BRUNDIR)))
                    if (Brundir->isAlive())
                        Brundir->AI()->DoAction(ACTION_BRUNDIR);

                if (Creature* Molgeim = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_MOLGEIM)))
                    if (Molgeim->isAlive())
                        Molgeim->AI()->DoAction(ACTION_MOLGEIM);
            }

            void KilledUnit(Unit* /*who*/)
            {
                DoScriptText(RAND(SAY_STEELBREAKER_SLAY_1, SAY_STEELBREAKER_SLAY_2), me);

                if (phase == 3)
                    DoCast(me, SPELL_ELECTRICAL_CHARGE);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BERSERK:
                            DoScriptText(SAY_STEELBREAKER_BERSERK, me);
                            DoCast(SPELL_BERSERK);
                            events.CancelEvent(EVENT_BERSERK);
                            break;
                        case EVENT_FUSION_PUNCH:
                            if (me->IsWithinMeleeRange(me->getVictim()))
                                DoCastVictim(SPELL_FUSION_PUNCH);
                            events.ScheduleEvent(EVENT_FUSION_PUNCH, urand(13000, 22000));
                            break;
                        case EVENT_STATIC_DISRUPTION:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_STATIC_DISRUPTION);
                            events.ScheduleEvent(EVENT_STATIC_DISRUPTION, urand(20000, 40000));
                            break;
                        case EVENT_OVERWHELMING_POWER:
                            DoScriptText(SAY_STEELBREAKER_POWER, me);
                            DoCastVictim(SPELL_OVERWHELMING_POWER);
                            events.ScheduleEvent(EVENT_OVERWHELMING_POWER, RAID_MODE(60000, 35000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
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
            boss_runemaster_molgeimAI(Creature* creature) : BossAI(creature, BOSS_ASSEMBLY_OF_IRON)
            {
                instance = me->GetInstanceScript();
            }

            InstanceScript* instance;
            uint32 phase;

            void Reset()
            {
                _Reset();
                phase = 0;
                me->ResetLootMode();
                me->RemoveAllAuras();
                RespawnEncounter(instance, me);
            }

            void EnterCombat(Unit* who)
            {
                StartEncounter(instance, me, who);
                DoScriptText(SAY_MOLGEIM_AGGRO, me);
                DoZoneInCombat();
                events.SetPhase(++phase);
                events.ScheduleEvent(EVENT_BERSERK, 900000);
                events.ScheduleEvent(EVENT_SHIELD_OF_RUNES, 30000);
                events.ScheduleEvent(EVENT_RUNE_OF_POWER, 20000);
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_MOLGEIM:
                        me->SetHealth(me->GetMaxHealth());
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

            void JustDied(Unit* /*who*/)
            {
                DoScriptText(RAND(SAY_MOLGEIM_DEATH_1, SAY_MOLGEIM_DEATH_2), me);
                if (IsEncounterComplete(instance, me))
                    instance->SetData(BOSS_ASSEMBLY_OF_IRON, DONE);
                else
                    me->SetLootRecipient(NULL);

                if (Creature* Brundir = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_BRUNDIR)))
                    if (Brundir->isAlive())
                        Brundir->AI()->DoAction(ACTION_BRUNDIR);

                if (Creature* Steelbreaker = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_STEELBREAKER)))
                    if (Steelbreaker->isAlive())
                        Steelbreaker->AI()->DoAction(ACTION_STEELBREAKER);
            }

            void KilledUnit(Unit* /*who*/)
            {
                DoScriptText(RAND(SAY_MOLGEIM_SLAY_1, SAY_MOLGEIM_SLAY_2), me);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BERSERK:
                            DoScriptText(SAY_MOLGEIM_BERSERK, me);
                            DoCast(SPELL_BERSERK);
                            events.CancelEvent(EVENT_BERSERK);
                            break;
                        case EVENT_RUNE_OF_POWER:
                        {
                            Unit* target = NULL;
                            switch (urand(0, 2))
                            {
                                case 0:
                                    target = me;
                                    break;
                                case 1:
                                    if (Creature* Steelbreaker = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_STEELBREAKER)))
                                        if (Steelbreaker->isAlive())
                                            target = Steelbreaker;
                                    break;
                                case 2:
                                    if (Creature* Brundir = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_STEELBREAKER)))
                                        if (Brundir->isAlive())
                                            target = Brundir;
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
                            DoScriptText(SAY_MOLGEIM_RUNE_DEATH, me);
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_RUNE_OF_DEATH);
                            events.ScheduleEvent(EVENT_RUNE_OF_DEATH, urand(30000, 40000));
                            break;
                        case EVENT_RUNE_OF_SUMMONING:
                            DoScriptText(SAY_MOLGEIM_SUMMON, me);
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_RUNE_OF_SUMMONING);
                            events.ScheduleEvent(EVENT_RUNE_OF_SUMMONING, urand(30000, 45000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetUlduarAI<boss_runemaster_molgeimAI>(creature);
        }
};

class mob_rune_of_power : public CreatureScript
{
    public:
        mob_rune_of_power() : CreatureScript("mob_rune_of_power") { }

        struct mob_rune_of_powerAI : public ScriptedAI
        {
            mob_rune_of_powerAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->setFaction(16); // Same faction as bosses
                DoCast(SPELL_RUNE_OF_POWER);

                me->DespawnOrUnsummon(60000);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_rune_of_powerAI(creature);
        }
};

class mob_lightning_elemental : public CreatureScript
{
    public:
        mob_lightning_elemental() : CreatureScript("mob_lightning_elemental") { }

        struct mob_lightning_elementalAI : public ScriptedAI
        {
            mob_lightning_elementalAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetInCombatWithZone();
                me->AddAura(SPELL_LIGHTNING_ELEMENTAL_PASSIVE, me);
            }

            // Nothing to do here, just let the creature chase players and procflags == 2 on the applied aura will trigger explosion
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_lightning_elementalAI(creature);
        }
};

class mob_rune_of_summoning : public CreatureScript
{
    public:
        mob_rune_of_summoning() : CreatureScript("mob_rune_of_summoning") { }

        struct mob_rune_of_summoningAI : public ScriptedAI
        {
            mob_rune_of_summoningAI(Creature* creature) : ScriptedAI(creature)
            {
                me->AddAura(SPELL_RUNE_OF_SUMMONING_VIS, me);
                summonCount = 0;
                summonTimer = 2000;
            }

            uint32 summonCount;
            uint32 summonTimer;

            void UpdateAI(uint32 const diff)
            {
                if (summonTimer <= diff)
                    SummonLightningElemental();
                else
                    summonTimer -= diff;
            }

            void SummonLightningElemental()
            {
                me->CastSpell(me, SPELL_RUNE_OF_SUMMONING_SUMMON, false);
                if (++summonCount == 10)                        // TODO: Find out if this amount is right
                    me->DespawnOrUnsummon();
                else
                    summonTimer = 2000;                         // TODO: Find out of timer is right
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_rune_of_summoningAI(creature);
        }
};

class boss_stormcaller_brundir : public CreatureScript
{
    public:
        boss_stormcaller_brundir() : CreatureScript("boss_stormcaller_brundir") { }

        struct boss_stormcaller_brundirAI : public BossAI
        {
            boss_stormcaller_brundirAI(Creature* creature) : BossAI(creature, BOSS_ASSEMBLY_OF_IRON)
            {
                instance = me->GetInstanceScript();
            }

            InstanceScript* instance;
            uint32 phase;

            void Reset()
            {
                _Reset();
                phase = 0;
                me->ResetLootMode();
                me->RemoveAllAuras();
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                RespawnEncounter(instance, me);
            }

            void EnterCombat(Unit* who)
            {
                StartEncounter(instance, me, who);
                DoScriptText(SAY_BRUNDIR_AGGRO, me);
                DoZoneInCombat();
                events.SetPhase(++phase);
                events.ScheduleEvent(EVENT_MOVE_POSITION, 1000);
                events.ScheduleEvent(EVENT_BERSERK, 900000);
                events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 4000);
                events.ScheduleEvent(EVENT_OVERLOAD, urand(60000, 120000));
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_BRUNDIR:
                        me->SetHealth(me->GetMaxHealth());
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
                        }
                    break;

                }
            }

            void JustDied(Unit* /*who*/)
            {
                DoScriptText(RAND(SAY_BRUNDIR_DEATH_1, SAY_BRUNDIR_DEATH_2), me);
                if (IsEncounterComplete(instance, me))
                    instance->SetData(BOSS_ASSEMBLY_OF_IRON, DONE);
                else
                    me->SetLootRecipient(NULL);

            if (Creature* Molgeim = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_MOLGEIM)))
                if (Molgeim->isAlive())
                    Molgeim->AI()->DoAction(ACTION_MOLGEIM);

            if (Creature* Steelbreaker = ObjectAccessor::GetCreature(*me, instance->GetData64(BOSS_STEELBREAKER)))
                if (Steelbreaker->isAlive())
                    Steelbreaker->AI()->DoAction(ACTION_STEELBREAKER);

                // Prevent to have Brundir somewhere in the air when he die in Air phase
                if (me->GetPositionZ() > FLOOR_Z)
                    me->GetMotionMaster()->MoveFall(FLOOR_Z);
            }

            void KilledUnit(Unit* /*who*/)
            {
                DoScriptText(RAND(SAY_BRUNDIR_SLAY_1, SAY_BRUNDIR_SLAY_2), me);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_BERSERK:
                            DoScriptText(SAY_BRUNDIR_BERSERK, me);
                            DoCast(SPELL_BERSERK);
                            events.CancelEvent(EVENT_BERSERK);
                            break;
                        case EVENT_CHAIN_LIGHTNING:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_CHAIN_LIGHTNING);
                            events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, urand(7000, 10000));
                            break;
                        case EVENT_OVERLOAD:
                            me->MonsterTextEmote(EMOTE_OVERLOAD, 0, true);
                            DoScriptText(SAY_BRUNDIR_SPECIAL, me);
                            DoCast(SPELL_OVERLOAD);
                            events.ScheduleEvent(EVENT_OVERLOAD, urand(60000, 120000));
                            break;
                        case EVENT_LIGHTNING_WHIRL:
                            DoCast(SPELL_LIGHTNING_WHIRL);
                            events.ScheduleEvent(EVENT_LIGHTNING_WHIRL, urand(15000, 20000));
                            break;
                        case EVENT_LIGHTNING_TENDRILS:
                            DoScriptText(SAY_BRUNDIR_FLIGHT, me);
                            DoCast(SPELL_LIGHTNING_TENDRILS);
                            me->AttackStop();
                            me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                            DoCast(SPELL_LIGHTNING_TENDRILS_SELF_VISUAL);
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
                            me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                            me->RemoveAurasDueToSpell(SPELL_LIGHTNING_TENDRILS);
                            me->RemoveAurasDueToSpell(SPELL_LIGHTNING_TENDRILS_SELF_VISUAL);
                            DoStartMovement(me->getVictim());
                            events.CancelEvent(EVENT_GROUND);
                            break;
                        case EVENT_MOVE_POSITION:
                            if (me->IsWithinMeleeRange(me->getVictim()))
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

        CreatureAI* GetAI(Creature* creature) const
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
            PrepareAuraScript(spell_shield_of_runes_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
                        caster->CastSpell(caster, SPELL_SHIELD_OF_RUNES_BUFF, false);
            }

            void Register()
            {
                 AfterEffectRemove += AuraEffectRemoveFn(spell_shield_of_runes_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
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
            PrepareSpellScript(spell_assembly_meltdown_SpellScript);

            void HandleInstaKill(SpellEffIndex /*effIndex*/)
            {
                if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                    if (Creature* Steelbreaker = ObjectAccessor::GetCreature(*GetCaster(), instance->GetData64(BOSS_STEELBREAKER)))
                        Steelbreaker->AI()->DoAction(ACTION_ADD_CHARGE);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_assembly_meltdown_SpellScript::HandleInstaKill, EFFECT_1, SPELL_EFFECT_INSTAKILL);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_assembly_meltdown_SpellScript();
        }
};

void AddSC_boss_assembly_of_iron()
{
    new boss_steelbreaker();
    new boss_runemaster_molgeim();
    new boss_stormcaller_brundir();
    new mob_lightning_elemental();
    new mob_rune_of_summoning();
    new mob_rune_of_power();
    new spell_shield_of_runes();
    new spell_assembly_meltdown();
}

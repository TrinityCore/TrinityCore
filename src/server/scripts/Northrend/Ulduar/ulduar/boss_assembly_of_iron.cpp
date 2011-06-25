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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "ulduar.h"

enum Spells
{
    // Any boss
    SPELL_SUPERCHARGE                   = 61920,
    SPELL_BERSERK                       = 47008, // Hard enrage, don't know the correct ID.
    SPELL_CREDIT_MARKER                 = 65195, // spell_dbc

    // Steelbreaker
    SPELL_HIGH_VOLTAGE                  = 61890,
    SPELL_HIGH_VOLTAGE_H                = 63498,
    SPELL_FUSION_PUNCH                  = 61903,
    SPELL_FUSION_PUNCH_H                = 63493,
    SPELL_STATIC_DISRUPTION             = 44008,
    SPELL_STATIC_DISRUPTION_H           = 63494,
    SPELL_OVERWHELMING_POWER_H          = 61888,
    SPELL_OVERWHELMING_POWER            = 64637,
    SPELL_ELECTRICAL_CHARGE             = 61902,

    // Runemaster Molgeim
    SPELL_SHIELD_OF_RUNES               = 62274,
    SPELL_SHIELD_OF_RUNES_BUFF          = 62277,
    SPELL_SHIELD_OF_RUNES_H             = 63489,
    SPELL_SHIELD_OF_RUNES_H_BUFF        = 63967,
    SPELL_SUMMON_RUNE_OF_POWER          = 63513,
    SPELL_RUNE_OF_POWER                 = 61974,
    SPELL_RUNE_OF_DEATH                 = 62269,
    SPELL_RUNE_OF_SUMMONING             = 62273, // This is the spell that summons the rune
    SPELL_RUNE_OF_SUMMONING_VIS         = 62019, // Visual
    SPELL_RUNE_OF_SUMMONING_SUMMON      = 62020, // Spell that summons
    SPELL_LIGHTNING_BLAST_10            = 62054,
    SPELL_LIGHTNING_BLAST_25            = 63491,

    // Stormcaller Brundir
    SPELL_CHAIN_LIGHTNING_N             = 61879,
    SPELL_CHAIN_LIGHTNING_H             = 63479,
    SPELL_OVERLOAD                      = 61869,
    SPELL_OVERLOAD_H                    = 63481,
    SPELL_LIGHTNING_WHIRL               = 61915,
    SPELL_LIGHTNING_WHIRL_H             = 63483,
    SPELL_LIGHTNING_TENDRILS            = 61887,
    SPELL_LIGHTNING_TENDRILS_H          = 63486,
    SPELL_STORMSHIELD                   = 64187
};

enum Events
{
    EVENT_UPDATEPHASE = 1,
    EVENT_ENRAGE,
    EVENT_PULSE,
    // Steelbreaker
    EVENT_FUSION_PUNCH,
    EVENT_STATIC_DISRUPTION,
    EVENT_OVERWHELMING_POWER,
    // Molgeim
    EVENT_RUNE_OF_POWER,
    EVENT_SHIELD_OF_RUNES,
    EVENT_RUNE_OF_DEATH,
    EVENT_RUNE_OF_SUMMONING,
    EVENT_LIGHTNING_BLAST,
    // Brundir
    EVENT_CHAIN_LIGHTNING,
    EVENT_OVERLOAD,
    EVENT_LIGHTNING_WHIRL,
    EVENT_LIGHTNING_TENDRILS_START,
    EVENT_LIGHTNING_TENDRILS_END,
    EVENT_THREAT_WIPE,
    EVENT_STORMSHIELD,
};

enum Yells
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

enum MovePoints
{
    POINT_FLY = 1,
    POINT_LAND,
    POINT_CHASE
};

bool IsEncounterComplete(InstanceScript* instance, Creature* me)
{
   if (!instance || !me)
        return false;

    for (uint8 i = 0; i < 3; ++i)
    {
        uint64 guid = instance->GetData64(DATA_STEELBREAKER + i);
        if (!guid)
            return false;

        if (Creature* boss = Unit::GetCreature(*me, guid))
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
        uint64 guid = instance->GetData64(DATA_STEELBREAKER + i);
        if (!guid)
            continue;

        if (Creature* boss = Unit::GetCreature(*me, guid))
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
    if (instance->GetBossState(TYPE_ASSEMBLY) == IN_PROGRESS)
        return;     // Prevent recursive calls

    instance->SetBossState(TYPE_ASSEMBLY, IN_PROGRESS);

    for (uint8 i = 0; i < 3; ++i)
    {
        uint64 guid = instance->GetData64(DATA_STEELBREAKER + i);
        if (!guid)
            continue;

        if (Creature* boss = Unit::GetCreature(*me, guid))
                boss->SetInCombatWithZone();
    }
}

bool UpdateSupercharge(Creature* target)
{
    if (Aura* supercharge = target->GetAura(SPELL_SUPERCHARGE))
    {
        supercharge->ModStackAmount(1);
        if (UnitAI* AI = target->GetAI())
        {
            AI->DoAction(EVENT_UPDATEPHASE);
            return true;
        }
    }

    return false;
}

class boss_steelbreaker : public CreatureScript
{
public:
    boss_steelbreaker() : CreatureScript("boss_steelbreaker") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_steelbreakerAI(creature);
    }

    struct boss_steelbreakerAI : public ScriptedAI
    {
        boss_steelbreakerAI(Creature* c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        void Reset()
        {
            events.Reset();
            phase = 0;
            me->RemoveAllAuras();
            me->RemoveLootMode(LOOT_MODE_DEFAULT);
            if (pInstance)
            {
                pInstance->SetBossState(TYPE_ASSEMBLY, NOT_STARTED);
                RespawnEncounter(pInstance, me);
            }
        }

        EventMap events;
        InstanceScript* pInstance;
        uint32 phase;

        void EnterCombat(Unit* who)
        {
            StartEncounter(pInstance, me, who);
            DoScriptText(SAY_STEELBREAKER_AGGRO, me);
            DoZoneInCombat();
            DoCast(me, RAID_MODE(SPELL_HIGH_VOLTAGE, SPELL_HIGH_VOLTAGE_H));
            events.ScheduleEvent(EVENT_ENRAGE, 900000);
            events.ScheduleEvent(EVENT_PULSE, 5000);
            events.ScheduleEvent(EVENT_FUSION_PUNCH, 15000);
            DoAction(EVENT_UPDATEPHASE);
        }

        void DoAction(int32 const action)
        {
            switch (action)
            {
                case EVENT_UPDATEPHASE:
                    events.SetPhase(++phase);
                    if (phase == 2)
                        events.ScheduleEvent(EVENT_STATIC_DISRUPTION, 30000);
                    if (phase == 3)
                    {
                        me->ResetLootMode();
                        events.ScheduleEvent(EVENT_OVERWHELMING_POWER, rand()%5000);
                    }
                break;
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32 &damage)
        {
            if (damage >= me->GetHealth())
            {
                bool has_supercharge = false;

                if (Creature* Brundir = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_BRUNDIR) : 0))
                {
                    if (Brundir->isAlive())
                    {
                        Brundir->SetFullHealth();
                        has_supercharge = UpdateSupercharge(Brundir);
                    }
                }

                if (Creature* Molgeim = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_MOLGEIM) : 0))
                {
                    if (Molgeim->isAlive())
                    {
                        Molgeim->SetFullHealth();
                        has_supercharge = UpdateSupercharge(Molgeim);
                    }
                }

                if (!has_supercharge)
                    DoCast(SPELL_SUPERCHARGE);
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(RAND(SAY_STEELBREAKER_DEATH_1, SAY_STEELBREAKER_DEATH_2), me);
            if (IsEncounterComplete(pInstance, me) && pInstance)
            {
                pInstance->SetBossState(TYPE_ASSEMBLY, DONE);
                pInstance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_CREDIT_MARKER);
            }
        }

        void KilledUnit(Unit* /*who*/)
        {
            DoScriptText(RAND(SAY_STEELBREAKER_SLAY_1, SAY_STEELBREAKER_SLAY_2), me);

            if (phase == 3)
                DoCast(me, SPELL_ELECTRICAL_CHARGE, true);
        }

        void SpellHit(Unit* /*from*/, const SpellEntry* spell)
        {
            if (spell->Id == SPELL_SUPERCHARGE)
                DoAction(EVENT_UPDATEPHASE);
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ENRAGE:
                        DoScriptText(SAY_STEELBREAKER_BERSERK, me);
                        DoCast(SPELL_BERSERK);
                        break;
                    case EVENT_PULSE:
                        if (me->getVictim() && me->getVictim()->ToPlayer())
                            DoAttackerGroupInCombat(me->getVictim()->ToPlayer());
                        events.ScheduleEvent(EVENT_PULSE, 5000);
                        break;
                    case EVENT_FUSION_PUNCH:
                        DoCastVictim(RAID_MODE(SPELL_FUSION_PUNCH, SPELL_FUSION_PUNCH_H));
                        events.ScheduleEvent(EVENT_FUSION_PUNCH, urand(13000, 22000));
                        break;
                    case EVENT_STATIC_DISRUPTION:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, RAID_MODE(SPELL_STATIC_DISRUPTION, SPELL_STATIC_DISRUPTION_H));
                        events.ScheduleEvent(EVENT_STATIC_DISRUPTION, urand(20000, 40000));
                        break;
                    case EVENT_OVERWHELMING_POWER:
                        DoScriptText(SAY_STEELBREAKER_POWER, me);
                        DoCastVictim(RAID_MODE(SPELL_OVERWHELMING_POWER, SPELL_OVERWHELMING_POWER_H));
                        events.ScheduleEvent(EVENT_OVERWHELMING_POWER, RAID_MODE(60000, 35000));
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

class spell_meltdown : public SpellScriptLoader
{
    public:
        spell_meltdown() : SpellScriptLoader("spell_meltdown") { }

        class spell_meltdown_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_meltdown_SpellScript);

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_ELECTRICAL_CHARGE))
                    return false;
                return true;
            }

            void TriggerElectricalCharge(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                    if (InstanceScript* instance = target->GetInstanceScript())
                        if (Creature* steelbreaker = ObjectAccessor::GetCreature(*target, instance->GetData64(DATA_STEELBREAKER)))
                            steelbreaker->CastSpell(steelbreaker, SPELL_ELECTRICAL_CHARGE, true);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_meltdown_SpellScript::TriggerElectricalCharge, EFFECT_1, SPELL_EFFECT_INSTAKILL);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_meltdown_SpellScript();
        }
};

class boss_runemaster_molgeim : public CreatureScript
{
    public:
        boss_runemaster_molgeim() : CreatureScript("boss_runemaster_molgeim") { }

        struct boss_runemaster_molgeimAI : public ScriptedAI
        {
            boss_runemaster_molgeimAI(Creature* c) : ScriptedAI(c), _summons(me)
            {
                _instance = c->GetInstanceScript();
            }

            void Reset()
            {
                if (_instance)
                {
                    _instance->SetBossState(TYPE_ASSEMBLY, NOT_STARTED);
                    RespawnEncounter(_instance, me);
                }

                _summons.DespawnAll();
                _events.Reset();
                _phase = 0;
                me->RemoveAllAuras();
                me->RemoveLootMode(LOOT_MODE_DEFAULT);
            }

            void EnterCombat(Unit* who)
            {
                StartEncounter(_instance, me, who);
                DoScriptText(SAY_MOLGEIM_AGGRO, me);
                DoZoneInCombat();
                _events.ScheduleEvent(EVENT_ENRAGE, 900000);
                _events.ScheduleEvent(EVENT_PULSE, 5000);
                _events.ScheduleEvent(EVENT_SHIELD_OF_RUNES, 27000);
                _events.ScheduleEvent(EVENT_RUNE_OF_POWER, 60000);
                DoAction(EVENT_UPDATEPHASE);
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case EVENT_UPDATEPHASE:
                        _events.SetPhase(++_phase);
                        if (_phase == 2)
                            _events.ScheduleEvent(EVENT_RUNE_OF_DEATH, 30000);
                        if (_phase == 3)
                        {
                            me->ResetLootMode();
                            _events.ScheduleEvent(EVENT_RUNE_OF_SUMMONING, urand(20000, 30000));
                        }
                    break;
                }
            }

            void DamageTaken(Unit* /*attacker*/, uint32 &damage)
            {
                if (damage >= me->GetHealth())
                {
                    bool has_supercharge = false;

                    if (Creature* Steelbreaker = Unit::GetCreature(*me, _instance ? _instance->GetData64(DATA_STEELBREAKER) : 0))
                    {
                        if (Steelbreaker->isAlive())
                        {
                            Steelbreaker->SetFullHealth();
                            has_supercharge = UpdateSupercharge(Steelbreaker);
                        }
                    }

                    if (Creature* Brundir = Unit::GetCreature((*me), _instance ? _instance->GetData64(DATA_BRUNDIR) : 0))
                    {
                        if (Brundir->isAlive())
                        {
                            Brundir->SetFullHealth();
                            has_supercharge = UpdateSupercharge(Brundir);
                        }
                    }

                    if (!has_supercharge)
                        DoCast(me, SPELL_SUPERCHARGE);
                }
            }

            void JustDied(Unit* /*killer*/)
            {
                DoScriptText(RAND(SAY_MOLGEIM_DEATH_1, SAY_MOLGEIM_DEATH_2), me);
                if (IsEncounterComplete(_instance, me) && _instance)
                {
                    _summons.DespawnAll();
                    _instance->SetBossState(TYPE_ASSEMBLY, DONE);
                    _instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_CREDIT_MARKER);
                }
            }

            void JustSummoned(Creature* summon)
            {
                _summons.Summon(summon);
            }

            void KilledUnit(Unit* /*who*/)
            {
                DoScriptText(RAND(SAY_MOLGEIM_SLAY_1, SAY_MOLGEIM_SLAY_2), me);
            }

            void SpellHit(Unit* /*from*/, const SpellEntry* spell)
            {
                if (spell->Id == SPELL_SUPERCHARGE)
                    DoAction(EVENT_UPDATEPHASE);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ENRAGE:
                            DoScriptText(SAY_MOLGEIM_BERSERK, me);
                            DoCast(SPELL_BERSERK);
                            break;
                        case EVENT_PULSE:
                            if (me->getVictim() && me->getVictim()->ToPlayer())
                                DoAttackerGroupInCombat(me->getVictim()->ToPlayer());
                            _events.ScheduleEvent(EVENT_PULSE, 5000);
                            break;
                        case EVENT_RUNE_OF_POWER: // Improve target selection; random alive friendly
                        {
                            Unit* target = DoSelectLowestHpFriendly(60);
                            if (!target || !target->isAlive())
                                target = me;
                            DoCast(target, SPELL_SUMMON_RUNE_OF_POWER);
                            _events.ScheduleEvent(EVENT_RUNE_OF_POWER, 60000);
                            break;
                        }
                        case EVENT_SHIELD_OF_RUNES:
                            DoCast(me, RAID_MODE(SPELL_SHIELD_OF_RUNES, SPELL_SHIELD_OF_RUNES_H));
                            _events.ScheduleEvent(EVENT_SHIELD_OF_RUNES, urand(27000, 34000));
                            break;
                        case EVENT_RUNE_OF_DEATH:
                            DoScriptText(SAY_MOLGEIM_RUNE_DEATH, me);
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, SPELL_RUNE_OF_DEATH);
                            _events.ScheduleEvent(EVENT_RUNE_OF_DEATH, urand(30000, 40000));
                            break;
                        case EVENT_RUNE_OF_SUMMONING:
                            DoScriptText(SAY_MOLGEIM_SUMMON, me);
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, SPELL_RUNE_OF_SUMMONING);
                            _events.ScheduleEvent(EVENT_RUNE_OF_SUMMONING, urand(35000, 45000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* _instance;
            SummonList _summons;
            EventMap _events;
            uint32 _phase;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_runemaster_molgeimAI(creature);
        }
};

class mob_rune_of_power : public CreatureScript
{
    public:
        mob_rune_of_power() : CreatureScript("mob_rune_of_power") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_rune_of_powerAI(creature);
        }

        struct mob_rune_of_powerAI : public ScriptedAI
        {
            mob_rune_of_powerAI(Creature* c) : ScriptedAI(c)
            {
                me->SetInCombatWithZone();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->setFaction(16); // Same faction as bosses
                DoCast(SPELL_RUNE_OF_POWER);
                me->DespawnOrUnsummon(60000);
            }
        };
};

class mob_lightning_elemental : public CreatureScript
{
    public:
        mob_lightning_elemental() : CreatureScript("mob_lightning_elemental") { }

        struct mob_lightning_elementalAI : public ScriptedAI
        {
            mob_lightning_elementalAI(Creature* c) : ScriptedAI(c)
            {
                _Casted = false;
                SetVictim();
            }

            void SetVictim()
            {
                me->SetInCombatWithZone();
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                {
                    me->AddThreat(target, 99999.9f);
                    AttackStart(target);
                }
            }

            void UpdateAI(uint32 const /*diff*/)
            {
                if (!UpdateVictim())
                    return;

                if (me->IsWithinMeleeRange(me->getVictim()) && !_Casted)
                {
                    me->CastSpell(me, RAID_MODE(SPELL_LIGHTNING_BLAST_10, SPELL_LIGHTNING_BLAST_25), true);
                    me->ForcedDespawn(500);
                    _Casted = true;
                }
            }

        private:
            bool _Casted;
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
            mob_rune_of_summoningAI(Creature* c) : ScriptedAI(c)
            {
                _summonCount = 0;
                _summonTimer = 5000;
                _instance = c->GetInstanceScript();
                me->AddAura(SPELL_RUNE_OF_SUMMONING_VIS, me);
            }

            void JustSummoned(Creature* summon)
            {
                if (Creature* Molgeim = Unit::GetCreature(*me, _instance ? _instance->GetData64(DATA_MOLGEIM) : 0))
                    Molgeim->AI()->JustSummoned(summon);
            }

            void SummonLightningElemental()
            {
                me->CastSpell(me, SPELL_RUNE_OF_SUMMONING_SUMMON, false);
                if (++_summonCount == 10)
                    me->DespawnOrUnsummon();
                else
                    _summonTimer = 2000;
            }

            void UpdateAI(uint32 const diff)
            {
                if (_summonTimer <= diff)
                    SummonLightningElemental();
                else
                    _summonTimer -= diff;
            }

        private:
            InstanceScript* _instance;
            uint32 _summonCount;
            uint32 _summonTimer;
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

        struct boss_stormcaller_brundirAI : public ScriptedAI
        {
            boss_stormcaller_brundirAI(Creature* c) : ScriptedAI(c)
            {
                _instance = c->GetInstanceScript();
            }

            void Reset()
            {
                if (_instance)
                {
                    _instance->SetBossState(TYPE_ASSEMBLY, NOT_STARTED);
                    RespawnEncounter(_instance, me);
                }

                _events.Reset();
                _phase = 0;
                _forceLand = false;
                me->RemoveAllAuras();
                me->RemoveLootMode(LOOT_MODE_DEFAULT);
                if (me->HasUnitMovementFlag(MOVEMENTFLAG_LEVITATING))
                {
                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                    me->SendMovementFlagUpdate();
                }
            }

            void EnterCombat(Unit* who)
            {
                StartEncounter(_instance, me, who);
                DoScriptText(SAY_BRUNDIR_AGGRO, me);
                DoZoneInCombat();
                _events.ScheduleEvent(EVENT_ENRAGE, 900000);
                _events.ScheduleEvent(EVENT_PULSE, 5000);
                _events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, urand(9000, 17000), 1);
                _events.ScheduleEvent(EVENT_OVERLOAD, urand(60000, 80000), 1);
                DoAction(EVENT_UPDATEPHASE);
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case EVENT_UPDATEPHASE:
                        _events.SetPhase(++_phase);
                        if (_phase == 2)
                            _events.ScheduleEvent(EVENT_LIGHTNING_WHIRL, urand(20000, 40000), 1);
                        if (_phase == 3)
                        {
                            me->ResetLootMode();
                            DoCast(me, SPELL_STORMSHIELD, true);
                            _events.ScheduleEvent(EVENT_LIGHTNING_TENDRILS_START, urand(40000, 80000));
                        }
                    break;

                }
            }

            void DamageTaken(Unit* /*attacker*/, uint32 &damage)
            {
                if (damage >= me->GetHealth())
                {
                    // do not die flying
                    if (me->HasUnitMovementFlag(MOVEMENTFLAG_LEVITATING))
                    {
                        damage = me->GetHealth() - 1;

                        if (!_forceLand)
                        {
                            me->GetMotionMaster()->MovePoint(POINT_LAND, me->GetPositionX(), me->GetPositionY(), 427.28f);
                            me->RemoveAurasDueToSpell(RAID_MODE(SPELL_LIGHTNING_TENDRILS, SPELL_LIGHTNING_TENDRILS_H));
                            _events.CancelEvent(EVENT_LIGHTNING_TENDRILS_END);
                            _events.CancelEvent(EVENT_THREAT_WIPE);
                            _forceLand = true;
                        }
                        return;
                    }

                    bool has_supercharge = false;

                    if (Creature* Steelbreaker = Unit::GetCreature(*me, _instance ? _instance->GetData64(DATA_STEELBREAKER) : 0))
                    {
                        if (Steelbreaker->isAlive())
                        {
                            Steelbreaker->SetFullHealth();
                            has_supercharge = UpdateSupercharge(Steelbreaker);
                        }
                    }

                    if (Creature* Molgeim = Unit::GetCreature(*me, _instance ? _instance->GetData64(DATA_MOLGEIM) : 0))
                    {
                        if (Molgeim->isAlive())
                        {
                            Molgeim->SetFullHealth();
                            has_supercharge = UpdateSupercharge(Molgeim);
                        }
                    }

                    if (!has_supercharge)
                        DoCast(SPELL_SUPERCHARGE);
                }
            }

            void JustDied(Unit* /*killer*/)
            {
                DoScriptText(RAND(SAY_BRUNDIR_DEATH_1, SAY_BRUNDIR_DEATH_2), me);
                if (IsEncounterComplete(_instance, me) && _instance)
                {
                    _instance->SetBossState(TYPE_ASSEMBLY, DONE);
                    _instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_CREDIT_MARKER);
                }
            }

            void KilledUnit(Unit* /*who*/)
            {
                DoScriptText(RAND(SAY_BRUNDIR_SLAY_1, SAY_BRUNDIR_SLAY_2), me);
            }

            void SpellHit(Unit* /*from*/, const SpellEntry *spell)
            {
                if (spell->Id == SPELL_SUPERCHARGE)
                    DoAction(EVENT_UPDATEPHASE);
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                switch (id)
                {
                    case POINT_FLY:
                    {
                        DoCast(RAID_MODE(SPELL_LIGHTNING_TENDRILS, SPELL_LIGHTNING_TENDRILS_H));
                        _events.ScheduleEvent(EVENT_LIGHTNING_TENDRILS_END, 30000);
                        _events.ScheduleEvent(EVENT_THREAT_WIPE, 0);
                        break;
                    }
                    case POINT_LAND:
                    {
                        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
                        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, false);
                        me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                        me->SendMovementFlagUpdate();
                        if (me->getVictim())
                            me->GetMotionMaster()->MoveChase(me->getVictim());
                        break;
                    }
                    case POINT_CHASE:
                    {
                        if (Unit* target = me->getVictim())
                            me->GetMotionMaster()->MovePoint(POINT_CHASE, target->GetPositionX(), target->GetPositionY(), 435.0f);
                        break;
                    }
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ENRAGE:
                            DoScriptText(SAY_BRUNDIR_BERSERK, me);
                            DoCast(SPELL_BERSERK);
                            break;
                        case EVENT_PULSE:
                            if (me->getVictim() && me->getVictim()->ToPlayer())
                                DoAttackerGroupInCombat(me->getVictim()->ToPlayer());
                            _events.ScheduleEvent(EVENT_PULSE, 5000);
                            break;
                        case EVENT_CHAIN_LIGHTNING:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                DoCast(target, RAID_MODE(SPELL_CHAIN_LIGHTNING_N, SPELL_CHAIN_LIGHTNING_H));
                            _events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, urand(3000, 5000), 1);
                            break;
                        case EVENT_OVERLOAD:
                            DoCast(RAID_MODE(SPELL_OVERLOAD, SPELL_OVERLOAD_H));
                            _events.ScheduleEvent(EVENT_OVERLOAD, urand(60000, 80000), 1);
                            break;
                        case EVENT_LIGHTNING_WHIRL:
                            DoCast(RAID_MODE(SPELL_LIGHTNING_WHIRL, SPELL_LIGHTNING_WHIRL_H));
                            _events.ScheduleEvent(EVENT_LIGHTNING_WHIRL, urand(20000, 40000), 1);
                            break;
                        case EVENT_THREAT_WIPE:
                            DoResetThreat();
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            {
                                me->AddThreat(target, 99999.9f);
                                me->GetMotionMaster()->MovePoint(POINT_CHASE, target->GetPositionX(), target->GetPositionY(), 435.0f);
                            }
                            _events.ScheduleEvent(EVENT_THREAT_WIPE, 5000);
                            break;
                        case EVENT_LIGHTNING_TENDRILS_START:
                            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
                            me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                            me->SendMovementFlagUpdate();
                            me->GetMotionMaster()->MovePoint(POINT_FLY, me->GetPositionX(), me->GetPositionY(), 435.0f);
                            _events.DelayEvents(35000, 1);
                            break;
                        case EVENT_LIGHTNING_TENDRILS_END:
                            me->GetMotionMaster()->MovePoint(POINT_LAND, me->GetPositionX(), me->GetPositionY(), 427.28f);
                            me->RemoveAurasDueToSpell(RAID_MODE(SPELL_LIGHTNING_TENDRILS, SPELL_LIGHTNING_TENDRILS_H));
                            _events.ScheduleEvent(EVENT_LIGHTNING_TENDRILS_START, urand(40000, 80000));
                            _events.CancelEvent(EVENT_THREAT_WIPE);
                            break;
                    }
                }

                if (!me->HasAura(RAID_MODE(SPELL_LIGHTNING_TENDRILS, SPELL_LIGHTNING_TENDRILS_H)))
                    DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* _instance;
            EventMap _events;
            uint32 _phase;
            bool _forceLand;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_stormcaller_brundirAI(creature);
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

void AddSC_boss_assembly_of_iron()
{
    new boss_steelbreaker();
    new spell_meltdown();
    new boss_runemaster_molgeim();
    new boss_stormcaller_brundir();
    new mob_lightning_elemental();
    new mob_rune_of_summoning();
    new mob_rune_of_power();
    new spell_shield_of_runes();
}

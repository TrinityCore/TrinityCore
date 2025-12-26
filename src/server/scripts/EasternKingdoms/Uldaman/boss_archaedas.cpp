/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

/*
 * Combat timers requires to be revisited
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "uldaman.h"

enum ArchaedasTexts
{
    SAY_AGGRO                          = 0,
    SAY_SUMMON_1                       = 1,
    SAY_SUMMON_2                       = 2,
    SAY_SLAY                           = 3,
    EMOTE_AWAKEN                       = 4
};

enum ArchaedasSpells
{
    // Archaedas - Intro
    SPELL_FREEZE_ANIM                  = 16245,
    SPELL_ARCHAEDAS_AWAKEN             = 10347,

    // Archaedas - Combat
    SPELL_GROUND_TREMOR                = 6524,
    SPELL_AWAKEN_DWARF                 = 10259,
    SPELL_AWAKEN_GUARDIANS             = 10252,
    SPELL_AWAKEN_WALKERS               = 10258,
    SPELL_DESTROY_EARTHEN_GUARDS       = 10604,

    // Minions - Shared
    SPELL_STONED                       = 10255,
    SPELL_STONE_DWARF_AWAKEN_VISUAL    = 10254,
    SPELL_EARTHEN_GUARDS_DESTROYED     = 10666,

    // Earthen Hallshaper
    SPELL_RECONSTRUCT                  = 10260,

    // Earthen Guardian
    SPELL_WHIRLWIND                    = 17207,

    // Vault Warder
    SPELL_TRAMPLE                      = 5568
};

enum ArchaedasEvents
{
    EVENT_INTRO_1                      = 1,
    EVENT_INTRO_2,
    EVENT_INTRO_3,
    EVENT_INTRO_4,

    EVENT_GROUND_TREMOR,
    EVENT_AWAKEN_DWARF,
    EVENT_AWAKEN_GUARDIANS,
    EVENT_AWAKEN_WALKERS
};

enum ArchaedasPhases : uint8
{
    PHASE_NONE                         = 0,
    PHASE_HEALTH_66,
    PHASE_HEALTH_33
};

enum ArchaedasMisc
{
    ACTION_ACTIVATE_VAULT_WARDERS      = 0,
    FACTION_TITAN_3                    = 470
};

// 2748 - Archaedas
struct boss_archaedas : public BossAI
{
    boss_archaedas(Creature* creature) : BossAI(creature, DATA_ARCHAEDAS), _phase(PHASE_NONE), _introStarted(false) { }

    void JustAppeared() override
    {
        me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
        me->SetImmuneToAll(true);
        DoCastSelf(SPELL_FREEZE_ANIM);
    }

    void Reset() override
    {
        _Reset();
        _phase = PHASE_NONE;
        _introStarted = false;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_GROUND_TREMOR, 20s, 30s);
        events.ScheduleEvent(EVENT_AWAKEN_DWARF, 10s);

        std::vector<Creature*> vaultWarders;
        GetCreatureListWithOptionsInGrid(vaultWarders, me, 100.0f, { .StringId = "VaultWarderOutside" });
        for (Creature* vaultWarder : vaultWarders)
            vaultWarder->AI()->DoAction(ACTION_ACTIVATE_VAULT_WARDERS);
    }

    void DamageTaken(Unit* /*killer*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (_phase < PHASE_HEALTH_66 && me->HealthBelowPctDamaged(66, damage))
        {
            _phase++;
            events.ScheduleEvent(EVENT_AWAKEN_GUARDIANS, 0s);
        }

        if (_phase < PHASE_HEALTH_33 && me->HealthBelowPctDamaged(33, damage))
        {
            _phase++;
            events.ScheduleEvent(EVENT_AWAKEN_WALKERS, 0s);
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_ARCHAEDAS_AWAKEN && me->IsAlive() && !_introStarted)
            events.ScheduleEvent(EVENT_INTRO_1, 0s);
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
        me->SetImmuneToAll(true);
        DoCastSelf(SPELL_FREEZE_ANIM);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        instance->SetBossState(DATA_ARCHAEDAS, FAIL);
        BossAI::EnterEvadeMode(why);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        DoCastSelf(SPELL_DESTROY_EARTHEN_GUARDS, true);
    }

    void UpdateOutOfCombatEvents(uint32 diff)
    {
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INTRO_1:
                    _introStarted = true;
                    DoCastSelf(SPELL_ARCHAEDAS_AWAKEN);
                    events.ScheduleEvent(EVENT_INTRO_2, 1500ms);
                    break;
                case EVENT_INTRO_2:
                    Talk(EMOTE_AWAKEN);
                    events.ScheduleEvent(EVENT_INTRO_3, 3500ms);
                    break;
                case EVENT_INTRO_3:
                    Talk(SAY_AGGRO);
                    me->RemoveAurasDueToSpell(SPELL_FREEZE_ANIM);
                    events.ScheduleEvent(EVENT_INTRO_4, 3s);
                    break;
                case EVENT_INTRO_4:
                    me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    me->SetImmuneToAll(false);
                    DoZoneInCombat();
                    break;
                default:
                    break;
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            UpdateOutOfCombatEvents(diff);
            return;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_GROUND_TREMOR:
                    DoCastSelf(SPELL_GROUND_TREMOR);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_AWAKEN_DWARF:
                    DoCastSelf(SPELL_AWAKEN_DWARF);
                    events.Repeat(10s);
                    break;
                case EVENT_AWAKEN_GUARDIANS:
                    Talk(SAY_SUMMON_1);
                    DoCastSelf(SPELL_AWAKEN_GUARDIANS);
                    break;
                case EVENT_AWAKEN_WALKERS:
                    Talk(SAY_SUMMON_2);
                    DoCastSelf(SPELL_AWAKEN_WALKERS);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    uint8 _phase;
    bool _introStarted;
};

// 7077 - Earthen Hallshaper
// 7309 - Earthen Custodian
struct npc_earthen_hallshaper_custodian : public ScriptedAI
{
    npc_earthen_hallshaper_custodian(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
        me->SetImmuneToAll(true);
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (me->GetEntry() == NPC_EARTHEN_HALLSHAPER)
        {
            _scheduler.Schedule(15s, 25s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_RECONSTRUCT);
                task.Repeat(30s, 45s);
            });
        }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_DESTROY_EARTHEN_GUARDS:
                DoCastSelf(SPELL_EARTHEN_GUARDS_DESTROYED, true);
                me->DespawnOrUnsummon();
                break;
            case SPELL_AWAKEN_DWARF:
                _scheduler.Schedule(3s, [this](TaskContext task)
                {
                    switch (task.GetRepeatCounter())
                    {
                        case 0:
                            DoCastSelf(SPELL_STONE_DWARF_AWAKEN_VISUAL);
                            task.Repeat(4s);
                            break;
                        case 1:
                            me->RemoveAurasDueToSpell(SPELL_STONED);
                            me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                            me->SetImmuneToAll(false);
                            DoZoneInCombat();
                            break;
                        default:
                            break;
                    }
                });
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (UpdateVictim())
            DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
};

// 7076 - Earthen Guardian
struct npc_earthen_guardian : public ScriptedAI
{
    npc_earthen_guardian(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
        me->SetImmuneToAll(true);
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(15s, 25s, [this](TaskContext task)
        {
            DoCastSelf(SPELL_WHIRLWIND);
            task.Repeat(15s, 25s);
        });
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_DESTROY_EARTHEN_GUARDS:
                DoCastSelf(SPELL_EARTHEN_GUARDS_DESTROYED, true);
                me->DespawnOrUnsummon();
                break;
            case SPELL_AWAKEN_GUARDIANS:
                _scheduler.Schedule(7s, [this](TaskContext task)
                {
                    switch (task.GetRepeatCounter())
                    {
                        case 0:
                            DoCastSelf(SPELL_STONE_DWARF_AWAKEN_VISUAL);
                            task.Repeat(4s);
                            break;
                        case 1:
                            me->RemoveAurasDueToSpell(SPELL_STONED);
                            me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                            me->SetImmuneToAll(false);
                            DoZoneInCombat();
                            break;
                        default:
                            break;
                    }
                });
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (UpdateVictim())
            DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
};

// 10120 - Vault Warder
struct npc_vault_warder : public ScriptedAI
{
    npc_vault_warder(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _scheduler.CancelAll();

        if (me->HasStringId("VaultWarderOutside"))
            return;

        me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
        me->SetImmuneToAll(true);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(10s, 15s, [this](TaskContext task)
        {
            DoCastSelf(SPELL_TRAMPLE);
            task.Repeat(10s, 15s);
        });
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_ACTIVATE_VAULT_WARDERS && me->IsAlive())
        {
            _scheduler.Schedule(5s, [this](TaskContext task)
            {
                switch (task.GetRepeatCounter())
                {
                    case 0:
                        DoCastSelf(SPELL_STONE_DWARF_AWAKEN_VISUAL);
                        task.Repeat(5s);
                        break;
                    case 1:
                        me->SetFaction(FACTION_TITAN_3);
                        me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                        me->SetImmuneToAll(false);
                        break;
                    default:
                        break;
                }
            });
        }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_DESTROY_EARTHEN_GUARDS:
                DoCastSelf(SPELL_EARTHEN_GUARDS_DESTROYED, true);
                me->DespawnOrUnsummon();
                break;
            case SPELL_AWAKEN_WALKERS:
                if (me->HasStringId("VaultWarderOutside"))
                    return;

                _scheduler.Schedule(2s, [this](TaskContext task)
                {
                    switch (task.GetRepeatCounter())
                    {
                        case 0:
                            DoCastSelf(SPELL_STONE_DWARF_AWAKEN_VISUAL);
                            task.Repeat(4s);
                            break;
                        case 1:
                            me->SetFaction(FACTION_TITAN);
                            me->RemoveAurasDueToSpell(SPELL_STONED);
                            me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                            me->SetImmuneToAll(false);
                            DoZoneInCombat();
                            break;
                        default:
                            break;
                    }
                });
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (UpdateVictim())
            DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
};

void AddSC_boss_archaedas()
{
    RegisterUldamanCreatureAI(boss_archaedas);
    RegisterUldamanCreatureAI(npc_earthen_hallshaper_custodian);
    RegisterUldamanCreatureAI(npc_earthen_guardian);
    RegisterUldamanCreatureAI(npc_vault_warder);
}

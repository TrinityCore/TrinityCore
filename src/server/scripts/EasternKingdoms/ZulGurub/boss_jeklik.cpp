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

#include "zulgurub.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "TemporarySummon.h"

enum Texts
{
    SAY_AGGRO               = 0,
    SAY_CALL_RIDERS         = 1,
    SAY_DEATH               = 2,
    EMOTE_SUMMON_BATS       = 3,
    EMOTE_GREAT_HEAL        = 4
};

enum Spells
{
    // Intro
    SPELL_GREEN_CHANNELING       = 13540,
    SPELL_BAT_FORM               = 23966,

    // Phase one
    SPELL_PIERCE_ARMOR           = 12097,
    SPELL_BLOOD_LEECH            = 22644,
    SPELL_CHARGE                 = 22911,
    SPELL_SONIC_BURST            = 23918,
    SPELL_SWOOP                  = 23919,
    SPELL_SUMMON_BATS            = 23974,

    // Phase two
    SPELL_CURSE_OF_BLOOD         = 16098,
    SPELL_PSYCHIC_SCREAM         = 22884,
    SPELL_SHADOW_WORD_PAIN       = 23952,
    SPELL_MIND_FLAY              = 23953,
    SPELL_GREAT_HEAL             = 23954,

    // Frenzied Bloodseeker Bat
    SPELL_ROOT_SELF              = 23973,   // They spawns with this aura

    // Gurubashi Bat Rider
    SPELL_LIQUID_FIRE_PERIODIC   = 23968,   // Periodically triggers 23969
    SPELL_LIQUID_FIRE_DAMAGE     = 23970,   // Assumedly used in script of 23969
    SPELL_SUMMON_LIQUID_FIRE     = 23971    // Assumedly used in script of 23970
};

enum Events
{
    EVENT_PIERCE_ARMOR      = 1,
    EVENT_BLOOD_LEECH,
    EVENT_CHARGE_JEKLIK,
    EVENT_SONIC_BURST,
    EVENT_SWOOP,
    EVENT_SUMMON_BATS,

    EVENT_CURSE_OF_BLOOD,
    EVENT_PSYCHIC_SCREAM,
    EVENT_SHADOW_WORD_PAIN,
    EVENT_MIND_FLAY,
    EVENT_GREAT_HEAL,
    EVENT_SPAWN_BAT_RIDER
};

enum Phase
{
    PHASE_ONE               = 1,
    PHASE_TWO               = 2
};

struct boss_jeklik : public BossAI
{
    boss_jeklik(Creature* creature) : BossAI(creature, DATA_JEKLIK), _calledRiders(false) { }

    void Reset() override
    {
        DoCastSelf(SPELL_GREEN_CHANNELING);
        _calledRiders = false;
        _Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        events.SetPhase(PHASE_ONE);

        /// @todo: Intro sequence with movement
        events.ScheduleEvent(EVENT_PIERCE_ARMOR, 10s, 20s, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_BLOOD_LEECH, 10s, 20s, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_CHARGE_JEKLIK, 10s, 25s, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_SONIC_BURST, 10s, 25s, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_SWOOP, 10s, 15s, 0, PHASE_ONE);
        events.ScheduleEvent(EVENT_SUMMON_BATS, 40s, 0, PHASE_ONE);

        me->SetDisableGravity(true);
        me->RemoveAurasDueToSpell(SPELL_GREEN_CHANNELING);
        DoCastSelf(SPELL_BAT_FORM, true);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (events.IsInPhase(PHASE_ONE) && !HealthAbovePct(50))
        {
            me->RemoveAurasDueToSpell(SPELL_BAT_FORM);
            me->SetDisableGravity(false);
            ResetThreatList();
            events.SetPhase(PHASE_TWO);
            events.ScheduleEvent(EVENT_CURSE_OF_BLOOD, 10s, 20s, 0, PHASE_TWO);
            events.ScheduleEvent(EVENT_PSYCHIC_SCREAM, 25s, 35s, 0, PHASE_TWO);
            events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 10s, 15s, 0, PHASE_TWO);
            events.ScheduleEvent(EVENT_MIND_FLAY, 10s, 30s, 0, PHASE_TWO);
            events.ScheduleEvent(EVENT_GREAT_HEAL, 25s, 0, PHASE_TWO);
        }

        if (!_calledRiders && !HealthAbovePct(35))
        {
            _calledRiders = true;
            Talk(SAY_CALL_RIDERS);
            //events.ScheduleEvent(EVENT_SPAWN_BAT_RIDER, 0s, 0, PHASE_TWO);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
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
                // Phase one
                case EVENT_PIERCE_ARMOR:
                    DoCastVictim(SPELL_PIERCE_ARMOR);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_BLOOD_LEECH:
                    DoCastVictim(SPELL_BLOOD_LEECH);
                    events.Repeat(10s, 20s);
                    break;
                case EVENT_CHARGE_JEKLIK:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.f, true))
                        DoCast(target, SPELL_CHARGE);
                    events.Repeat(15s, 30s);
                    break;
                case EVENT_SONIC_BURST:
                    DoCastSelf(SPELL_SONIC_BURST);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_SWOOP:
                    DoCastVictim(SPELL_SWOOP);
                    events.Repeat(15s, 20s);
                    break;
                case EVENT_SUMMON_BATS:
                    Talk(EMOTE_SUMMON_BATS);
                    DoCastSelf(SPELL_SUMMON_BATS);
                    events.Repeat(1min);
                    break;
                // Phase two
                case EVENT_CURSE_OF_BLOOD:
                    DoCastSelf(SPELL_CURSE_OF_BLOOD);
                    events.Repeat(25s, 30s);
                    break;
                case EVENT_PSYCHIC_SCREAM:
                    DoCastSelf(SPELL_PSYCHIC_SCREAM);
                    events.Repeat(35s, 45s);
                    break;
                case EVENT_SHADOW_WORD_PAIN:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.f, true))
                        DoCast(target, SPELL_SHADOW_WORD_PAIN);
                    events.Repeat(10s, 20s);
                    break;
                case EVENT_MIND_FLAY:
                    DoCastVictim(SPELL_MIND_FLAY);
                    events.Repeat(25s, 40s);
                    break;
                case EVENT_GREAT_HEAL:
                    Talk(EMOTE_GREAT_HEAL);
                    DoCastSelf(SPELL_GREAT_HEAL);
                    events.Repeat(25s);
                    break;
                /// @todo: One Gurubashi Bat Rider should be spawned at -12301.7 -1371.29 145.092 4.74729 or -12298 -1368.51 145.398 4.79965
                /// They're uninteractible, passive and simply flies on paths, throwing bombs. Despawns at path end
//              case EVENT_SPAWN_BAT_RIDER:
//                  events.Repeat(10s);
//                  break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    bool _calledRiders;
};

/// @todo: Intro sequence with movement
struct npc_frenzied_bloodseeker_bat : public ScriptedAI
{
    npc_frenzied_bloodseeker_bat(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        DoZoneInCombat();
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

void AddSC_boss_jeklik()
{
    RegisterZulGurubCreatureAI(boss_jeklik);
    RegisterZulGurubCreatureAI(npc_frenzied_bloodseeker_bat);
}

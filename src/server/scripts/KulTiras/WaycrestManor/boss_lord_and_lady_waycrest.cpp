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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Creature.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "waycrest_manor.h"

enum LordAndLadyWaycrestSpells
{
    // Lord Waycrest
    SPELL_WASTING_STRIKE             = 261438,
    SPELL_VIRULENT_PATHOGEN_SELECTOR = 261439,
    SPELL_VIRULENT_PATHOGEN_DAMAGE   = 261440,
    SPELL_PUTRID_VITALITY            = 261447,
    SPELL_LORD_WAYCREST_DUMMY_ABSORB = 273699,

    // Lady Waycrest
    SPELL_SOUL_ARMOR                 = 271590,
    SPELL_DISCORDANT_CADENZA         = 268306,
    SPELL_WRACKING_CHORD_SELECTOR    = 268278,
    SPELL_WRACKING_CHORD_DAMAGE      = 268271,
    SPELL_VITALITY_TRANSFER          = 261446,
};

enum LordAndLadyWaycrestTexts
{
    // Shared
    SAY_AGGRO               = 0,
    SAY_CLAIM_THE_IRIS      = 1,
    SAY_SLAY                = 3,
    SAY_DEATH               = 4,
    SAY_DIRE_RITUAL_ALERT   = 5,
    SAY_DIRE_RITUAL         = 6,

    // Sister Solena
    SAY_SOUL_MANIPULATION   = 2,

    // Sister Malady
    SAY_UNSTABLE_RUNIC_MARK = 2,

    // Sister Briar
    SAY_JAGGED_NETTLES      = 2
};

enum LordAndLadyWaycrestEvents
{
    // Lord Waycrest
    EVENT_BRAMBLE_BOLT          = 1,
    // Lady Waycrest
    
    
};

enum LordAndLadyWaycrestActions
{
    ACTION_CLAIM_THE_IRIS_INTRO  = 1,
    ACTION_CLAIM_THE_IRIS,
};

enum LordAndLadyWaycrestSummonGroups
{
    SUMMON_GROUP_TRIAD_FOCUSING_IRIS = 0
};

constexpr Position LordWaycrestCombatPosition = { -549.781f, -260.094f, 185.267f };

// 131527 - Lord Waycrest
struct boss_lord_waycrest : public BossAI
{
    boss_lord_waycrest(Creature* creature) : BossAI(creature, DATA_LORD_WAYCREST) { }

    void Reset() override
    {
        events.Reset();
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        if (Creature* ladyWaycrest = instance->GetCreature(DATA_LADY_WAYCREST))
            ladyWaycrest->AI()->EnterEvadeMode(why);

        instance->SetBossState(DATA_LORD_AND_LADY_WAYCREST, FAIL);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_VIRULENT_PATHOGEN_DAMAGE);

        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        /*if (me->HealthBelowPctDamaged(50, damage) && !_healthTriggered)
        {
        }*/
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        DoCastSelf(SPELL_LORD_WAYCREST_DUMMY_ABSORB);
        me->GetMotionMaster()->MoveJumpWithGravity(LordWaycrestCombatPosition, 20.0f, 15.1852f);

        instance->SetBossState(DATA_LORD_AND_LADY_WAYCREST, IN_PROGRESS);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        if (Creature* ladyWaycrest = instance->GetCreature(DATA_LADY_WAYCREST))
            ladyWaycrest->AI()->DoZoneInCombat();

        events.ScheduleEvent(EVENT_BRAMBLE_BOLT, 2000ms);
    }

    void JustDied(Unit* killer) override
    {
        if (Creature* ladyWaycrest = instance->GetCreature(DATA_LADY_WAYCREST))
        {
            if (ladyWaycrest->IsAlive())
                return;
            else
                instance->SetBossState(DATA_LORD_AND_LADY_WAYCREST, DONE);
        }

        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_VIRULENT_PATHOGEN_DAMAGE);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_BRAMBLE_BOLT:
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_BRAMBLE_BOLT);
                events.Repeat(2400ms);
                break;
            }
            case EVENT_BRAMBLE_BOLT_ENHANCED:
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_BRAMBLE_BOLT_ENHANCED);
                events.Repeat(7300ms);
                break;
            }
            case EVENT_JAGGED_NETTLES:
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_JAGGED_NETTLES);
                Talk(SAY_JAGGED_NETTLES);
                events.Repeat(14600ms);
                break;
            }
            case EVENT_AURA_OF_THORNS:
            {
                DoCastSelf(SPELL_AURA_OF_THORNS);
                break;
            }
            default:
                break;
        }
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
            ExecuteEvent(eventId);
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
};

void AddSC_boss_lord_and_lady_waycrest()
{
    RegisterWaycrestManorCreatureAI(boss_sister_briar);
    RegisterWaycrestManorCreatureAI(boss_sister_malady);
}

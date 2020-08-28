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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "blackrock_caverns.h"
#include "MotionMaster.h"
#include "InstanceScript.h"
#include "SpellScript.h"
#include "ObjectAccessor.h"

enum Sounds
{
    // Beauty
    SOUND_AGGRO = 18559,
    SOUND_DEATH = 18563
};

enum Spells
{
    // Beauty
    SPELL_TERRIFYING_ROAR           = 76028,
    SPELL_BERSERKER_CHARGE          = 76030,
    SPELL_MAGMA_SPIT                = 76031,
    SPELL_FLAMEBREAK                = 76032,
    SPELL_BERSERK                   = 82395,

    // Lucky, Spot and Buster
    SPELL_LAVA_DROOL                = 76628,
    SPELL_LITTLE_BIG_FLAME_BREATH   = 76665,

    // Player
    SPELL_MAGMA_SPIT_MISSILE_1      = 76058,
    SPELL_MAGMA_SPIT_MISSILE_2      = 76072,
    SPELL_MAGMA_SPIT_MISSILE_3      = 76074,
    SPELL_MAGMA_SPIT_MISSILE_4      = 76076
};

enum Events
{
    // Beauty
    EVENT_TERRIFYING_ROAR = 1,
    EVENT_BERSERKER_CHARGE,
    EVENT_MAGMA_SPIT,
    EVENT_FLAMEBREAK,

    // Lucky, Spot and Buster
    EVENT_LAVA_DROOL,
    EVENT_LITTLE_BIG_FLAME_BREATH
};

Position const LuckyPos     = { 116.337f, 567.625f, 76.4501f, 3.49996f  };
Position const SpotPos      = { 124.778f, 577.594f, 76.425f,  6.00992f  };
Position const BusterPos    = { 116.316f, 592.533f, 76.2866f, 4.00554f  };
Position const RuntyPos     = { 84.4645f, 612.958f, 76.8778f, 0.0431063f };

struct boss_beauty : public BossAI
{
    boss_beauty(Creature* creature) : BossAI(creature, DATA_BEAUTY) { }

    void Reset() override
    {
        _Reset();

        if (Creature* lucky = DoSummon(NPC_LUCKY, LuckyPos))
            lucky->GetMotionMaster()->MoveRandom(5.0f);

        if (Creature* spot = DoSummon(NPC_SPOT, SpotPos))
            spot->GetMotionMaster()->MoveRandom(5.0f);

        if (!IsHeroic())
            if (Creature* buster = DoSummon(NPC_BUSTER, BusterPos))
                buster->GetMotionMaster()->MoveRandom(5.0f);

        DoSummon(NPC_RUNTY, RuntyPos);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(EVENT_BERSERKER_CHARGE, 15s);
        events.ScheduleEvent(EVENT_FLAMEBREAK, 21s);
        events.ScheduleEvent(EVENT_TERRIFYING_ROAR, 36s);
        events.ScheduleEvent(EVENT_MAGMA_SPIT, 10s);
        DoPlaySoundToSet(me, SOUND_AGGRO);

        for (ObjectGuid guid : summons)
            if (Creature* puppy = ObjectAccessor::GetCreature(*me, guid))
                if (puppy->GetEntry() != NPC_RUNTY && !puppy->IsInCombat())
                    if (puppy->IsAIEnabled)
                        puppy->AI()->DoZoneInCombat();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MAGMA_SPIT);
        DoPlaySoundToSet(me, SOUND_DEATH);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MAGMA_SPIT);
        summons.DespawnAll();
        _EnterEvadeMode();
        _DespawnAtEvade();
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
                case EVENT_MAGMA_SPIT:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, true, -SPELL_MAGMA_SPIT))
                        DoCast(target, SPELL_MAGMA_SPIT);
                    events.Repeat(7s, 9s);
                    break;
                case EVENT_BERSERKER_CHARGE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_MAXDISTANCE, 0, 100.0f, true, true, 0))
                        DoCast(target, SPELL_BERSERKER_CHARGE);
                    events.Repeat(15s, 21s);
                    break;
                case EVENT_FLAMEBREAK:
                    DoCastAOE(SPELL_FLAMEBREAK);
                    events.Repeat(15s, 21s);
                    break;
                case EVENT_TERRIFYING_ROAR:
                    DoCastAOE(SPELL_TERRIFYING_ROAR);
                    events.Repeat(31s, 33s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_beauty_puppy : public ScriptedAI
{
    npc_beauty_puppy(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript())
    {
        Initialize();
    }

    void Initialize()
    {
        if (!IsHeroic())
            me->SetNoCallAssistance(true);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (IsHeroic())
            if (Creature* beauty = _instance->GetCreature(DATA_BEAUTY))
                beauty->AI()->DoZoneInCombat();

        _events.ScheduleEvent(EVENT_LAVA_DROOL, 5s + 500ms, 6s + 500ms);
        _events.ScheduleEvent(EVENT_LITTLE_BIG_FLAME_BREATH, 7s, 9s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_LAVA_DROOL:
                    DoCastSelf(SPELL_LAVA_DROOL);
                    _events.Repeat(12s, 13s);
                    break;
                case EVENT_LITTLE_BIG_FLAME_BREATH:
                    DoCastVictim(SPELL_LITTLE_BIG_FLAME_BREATH);
                    _events.Repeat(11s, 12s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    EventMap _events;
    InstanceScript* _instance;
};

class spell_beauty_magma_spit : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_MAGMA_SPIT_MISSILE_1,
                SPELL_MAGMA_SPIT_MISSILE_2,
                SPELL_MAGMA_SPIT_MISSILE_3,
                SPELL_MAGMA_SPIT_MISSILE_4
            });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_MAGMA_SPIT_MISSILE_1, true);
        target->CastSpell(target, SPELL_MAGMA_SPIT_MISSILE_2, true);
        target->CastSpell(target, SPELL_MAGMA_SPIT_MISSILE_3, true);
        target->CastSpell(target, SPELL_MAGMA_SPIT_MISSILE_4, true);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_beauty_magma_spit::AfterRemove, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_beauty()
{
    RegisterBlackrockCavernsCreatureAI(boss_beauty);
    RegisterBlackrockCavernsCreatureAI(npc_beauty_puppy);
    RegisterSpellScript(spell_beauty_magma_spit);
}

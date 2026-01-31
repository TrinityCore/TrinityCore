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
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "eye_of_azshara.h"

enum KingDeepbeardSpells
{
    SPELL_CALL_THE_SEAS         = 193051,
    SPELL_CALL_THE_SEAS_AT      = 193054,
    SPELL_CALL_THE_SEAS_DAMAGE  = 193055,
    SPELL_GASEOUS_BUBBLES       = 193018,
    SPELL_GASEOUS_EXPLOSION     = 193047,
    SPELL_GROUND_SLAM           = 193093,
    SPELL_GROUND_SLAM_MISSILE   = 193056,
    SPELL_QUAKE                 = 193152,
    SPELL_FRENZY                = 197550
};

enum KingDeepbeardEvents
{
    EVENT_ENERGIZE = 1,
    EVENT_CALL_THE_SEAS,
    EVENT_GASEOUS_BUBBLES,
    EVENT_GROUND_SLAM
};

enum KingDeepbeardTexts
{
    SAY_AGGRO                   = 0,
    SAY_GASEOUS_BUBBLES         = 1,
    SAY_QUAKE                   = 2,
    SAY_CALL_THE_SEAS_WARNING   = 3,
    SAY_CALL_THE_SEAS           = 4,
    SAY_FRENZY_WARNING          = 5,
    SAY_FRENZY                  = 6,
    SAY_DEATH                   = 7,
    SAY_SLAY                    = 8,
    SAY_WIPE                    = 9
};

enum KingDeepbeardMisc
{
    NPC_CALL_THE_SEAS           = 97844,
    NPC_QUAKE                   = 97916,
};

// 91797 - King Deepbeard
struct boss_king_deepbeard : public BossAI
{
    boss_king_deepbeard(Creature* creature) : BossAI(creature, DATA_KING_DEEPBEARD) { }

    void JustAppeared() override
    {
        me->SetPower(me->GetPowerType(), 30);
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        Talk(SAY_SLAY);
    }

    void RemoveQuakes()
    {
        std::list<Creature*> quakes;
        Trinity::AllCreaturesOfEntryInRange checker(me, NPC_QUAKE, 200.0f);
        Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(me, quakes, checker);
        Cell::VisitAllObjects(me, searcher, 200.0f);

        if (quakes.empty())
            return;

        for (Creature* quake : quakes)
            quake->DespawnOrUnsummon();
    }

    void RemoveCallTheSeas()
    {
        std::list<Creature*> callTheSeas;
        Trinity::AllCreaturesOfEntryInRange checker(me, NPC_CALL_THE_SEAS, 200.0f);
        Trinity::CreatureListSearcher<Trinity::AllCreaturesOfEntryInRange> searcher(me, callTheSeas, checker);
        Cell::VisitAllObjects(me, searcher, 200.0f);

        if (callTheSeas.empty())
            return;

        for (Creature* callTheSea : callTheSeas)
            callTheSea->RemoveAurasDueToSpell(SPELL_CALL_THE_SEAS_AT);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->SetBossState(DATA_KING_DEEPBEARD, DONE);
        Talk(SAY_DEATH);

        RemoveQuakes();
        RemoveCallTheSeas();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->SetBossState(DATA_KING_DEEPBEARD, FAIL);

        Talk(SAY_WIPE);

        RemoveQuakes();
        RemoveCallTheSeas();

        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        instance->SetBossState(DATA_KING_DEEPBEARD, IN_PROGRESS);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_ENERGIZE, 1s);
        events.ScheduleEvent(EVENT_CALL_THE_SEAS, 20500ms);
        events.ScheduleEvent(EVENT_GASEOUS_BUBBLES, 12800ms);
        events.ScheduleEvent(EVENT_GROUND_SLAM, 6s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->HealthBelowPctDamaged(30, damage) && !me->HasAura(SPELL_FRENZY))
        {
            Talk(SAY_FRENZY_WARNING);
            Talk(SAY_FRENZY);
            DoCastSelf(SPELL_FRENZY);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ENERGIZE:
                {
                    if (me->GetPower(me->GetPowerType()) == 100)
                    {
                        Talk(SAY_QUAKE);
                        DoCast(SPELL_QUAKE);
                        events.RescheduleEvent(EVENT_ENERGIZE, 1500ms);
                    }
                    else
                    {
                        me->SetPower(me->GetPowerType(), me->GetPower(me->GetPowerType()) + 5);
                        events.Repeat(1s);
                    }
                    break;
                }
                case EVENT_CALL_THE_SEAS:
                {
                    Talk(SAY_CALL_THE_SEAS_WARNING);
                    Talk(SAY_CALL_THE_SEAS);
                    DoCastSelf(SPELL_CALL_THE_SEAS);
                    events.Repeat(30400ms);
                    break;
                }
                case EVENT_GASEOUS_BUBBLES:
                {
                    Talk(SAY_GASEOUS_BUBBLES);
                    DoCastAOE(SPELL_GASEOUS_BUBBLES);
                    events.Repeat(32800ms, 35300ms);
                    break;
                }
                case EVENT_GROUND_SLAM:
                {
                    DoCastVictim(SPELL_GROUND_SLAM);
                    events.Repeat(21800ms);
                    break;
                }
                default:
                    break;
            }
        }
    }
};

// 193093 - Ground Slam
class spell_king_deepbeard_ground_slam : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_GROUND_SLAM_MISSILE });
    }

    void OnPrecast() override
    {
        GetCaster()->CastSpell(GetExplTargetUnit()->GetPosition(), SPELL_GROUND_SLAM_MISSILE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override { }
};

// 193018 - Gaseous Bubbles
class spell_king_deepbeard_gaseous_bubbles : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_GASEOUS_EXPLOSION });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_GASEOUS_EXPLOSION, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_king_deepbeard_gaseous_bubbles::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
    }
};

// 193054 - Call the Seas
// Id - 4968
struct at_king_deepbeard_call_the_seas : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        if (!unit->IsPlayer())
            return;

        caster->CastSpell(unit, SPELL_CALL_THE_SEAS_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        unit->RemoveAurasDueToSpell(SPELL_CALL_THE_SEAS_DAMAGE);
    }
};

void AddSC_boss_king_deepbeard()
{
    RegisterEyeOfAzsharaCreatureAI(boss_king_deepbeard);

    RegisterSpellScript(spell_king_deepbeard_ground_slam);
    RegisterSpellScript(spell_king_deepbeard_gaseous_bubbles);

    RegisterAreaTriggerAI(at_king_deepbeard_call_the_seas);
}

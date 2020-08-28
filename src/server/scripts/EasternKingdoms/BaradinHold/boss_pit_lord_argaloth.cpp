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
#include "baradin_hold.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "Map.h"
#include "MotionMaster.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

enum Texts
{
    SAY_ANNOUNCE_FEL_FIRESTORM = 0
};

enum Spells
{
    // Argaloth
    SPELL_FEL_FIRESTORM             = 88972,
    SPELL_FEL_FIRESTORM_TRIGGERED   = 88973,
    SPELL_BERSERK                   = 47008,
    SPELL_METEOR_SLASH_VISUAL       = 88949,

    // Fel Flames
    SPELL_FEL_FLAMES                = 88999
};

#define SPELL_METEOR_SLASH          RAID_MODE<uint32>(88942, 95172)
#define SPELL_CONSUMING_DARKNESS    RAID_MODE<uint32>(88954, 95173)

enum Events
{
    // Argaloth
    EVENT_METEOR_SLASH = 1,
    EVENT_CONSUMING_DARKNESS,
    EVENT_FEL_FIRESTORM,
    EVENT_END_FEL_FLAME_PHASE,
    EVENT_BERSERK,

    // Fel Flames
    EVENT_FEL_FLAMES
};

struct boss_pit_lord_argaloth : public BossAI
{
    boss_pit_lord_argaloth(Creature* creature) : BossAI(creature, DATA_ARGALOTH), _felFirestormCount(0) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(EVENT_METEOR_SLASH, 10s + 800ms);
        events.ScheduleEvent(EVENT_CONSUMING_DARKNESS, 6s);
        events.ScheduleEvent(EVENT_BERSERK, 5min);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        summons.DespawnAll();
        RemoveAuras();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        RemoveAuras();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(66, damage) && _felFirestormCount == 0)
        {
            events.Reset();
            events.ScheduleEvent(EVENT_FEL_FIRESTORM, 1ms);
            _felFirestormCount++;
        }
        else if (me->HealthBelowPctDamaged(33, damage) && _felFirestormCount == 1)
        {
            events.Reset();
            events.ScheduleEvent(EVENT_FEL_FIRESTORM, 1ms);
            _felFirestormCount++;
        }
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_FEL_FIRESTORM)
        {
            DoCastSelf(SPELL_FEL_FIRESTORM_TRIGGERED, true);
            events.ScheduleEvent(EVENT_END_FEL_FLAME_PHASE, 18s);
        }
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
        _felFlamesGUIDs.insert(summon->GetGUID());
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
                case EVENT_METEOR_SLASH:
                    DoCastSelf(SPELL_METEOR_SLASH_VISUAL);
                    DoCastAOE(SPELL_METEOR_SLASH);
                    events.Repeat(17s);
                    break;
                case EVENT_CONSUMING_DARKNESS:
                    DoCastAOE(SPELL_CONSUMING_DARKNESS);
                    events.Repeat(22s, 24s);
                    break;
                case EVENT_BERSERK:
                    DoCast(me, SPELL_BERSERK, true);
                    break;
                case EVENT_FEL_FIRESTORM:
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    Talk(SAY_ANNOUNCE_FEL_FIRESTORM);
                    DoCastAOE(SPELL_FEL_FIRESTORM);
                    break;
                case EVENT_END_FEL_FLAME_PHASE:
                    me->SetReactState(REACT_AGGRESSIVE);
                    if (Unit* victim = me->GetVictim())
                        AttackStart(victim);

                    for (ObjectGuid guid : _felFlamesGUIDs)
                    {
                        if (Creature* felFlame = ObjectAccessor::GetCreature(*me, guid))
                            felFlame->RemoveAllAuras();

                        _felFlamesGUIDs.erase(guid);
                    }

                    events.ScheduleEvent(EVENT_CONSUMING_DARKNESS, 6s);
                    events.ScheduleEvent(EVENT_METEOR_SLASH, 9s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    void RemoveAuras()
    {
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_CONSUMING_DARKNESS);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_METEOR_SLASH);
    }

    uint8 _felFirestormCount;
    GuidSet _felFlamesGUIDs;
};

struct npc_argaloth_fel_flames : public NullCreatureAI
{
    npc_argaloth_fel_flames(Creature* creature) : NullCreatureAI(creature) { }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        _events.ScheduleEvent(EVENT_FEL_FLAMES, 1s + 100ms);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_FEL_FLAMES:
                    DoCastSelf(SPELL_FEL_FLAMES);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

// 88954 / 95173 - Consuming Darkness
class spell_argaloth_consuming_darkness : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, GetCaster()->GetMap()->Is25ManRaid() ? 8 : 3);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_argaloth_consuming_darkness::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_argaloth_consuming_darkness_AuraScript : public AuraScript
{
    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (AuraEffect* aurEff = GetEffect(EFFECT_0))
        {
            int32 damage = aurEff->GetAmount() + CalculatePct(aurEff->GetAmount(), 10);
            aurEff->SetAmount(damage);
        }
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_argaloth_consuming_darkness_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 88942 / 95172 - Meteor Slash
class spell_argaloth_meteor_slash : public SpellScript
{
    bool Load() override
    {
        _targetCount = 0;
        return true;
    }

    void CountTargets(std::list<WorldObject*>& targets)
    {
        _targetCount = targets.size();
    }

    void SplitDamage()
    {
        if (!_targetCount)
            return;

        SetHitDamage(GetHitDamage() / _targetCount);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_argaloth_meteor_slash::CountTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_104);
        BeforeHit.Register(&spell_argaloth_meteor_slash::SplitDamage);
    }

private:
    uint32 _targetCount;
};

// 88987 / 95176 - Fel Firestorm
class spell_argaloth_fel_firestorm : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, GetCaster()->GetMap()->Is25ManRaid() ? 8 : 3);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_argaloth_fel_firestorm::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

void AddSC_boss_pit_lord_argaloth()
{
    RegisterBaradinHoldCreatureAI(boss_pit_lord_argaloth);
    RegisterBaradinHoldCreatureAI(npc_argaloth_fel_flames);
    RegisterSpellAndAuraScriptPair(spell_argaloth_consuming_darkness, spell_argaloth_consuming_darkness_AuraScript);
    RegisterSpellScript(spell_argaloth_meteor_slash);
    RegisterSpellScript(spell_argaloth_fel_firestorm);
}

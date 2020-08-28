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

#include "GridNotifiers.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "SpellScript.h"
#include "zulgurub.h"

enum Yells
{
    // High Priestess Kilnara
    SAY_AGGRO           = 0,
    SAY_WAVE_OF_AGONY   = 1,
    SAY_TRANSFROM_1     = 2,
    SAY_TRANSFROM_2     = 3,
    SAY_SLAY            = 4,
    SAY_DEATH           = 5
};

enum Spells
{
    // High Priestess Kilnara
    SPELL_CLEAR_ACHIEVEMENT_CREDITS = 98840,
    SPELL_KILNARA_HOVER_VISUAL_1    = 97459,
    SPELL_KILNARA_HOVER_VISUAL_2    = 97428,
    SPELL_SHADOW_BOLT               = 96516,
    SPELL_TEARS_OF_BLOOD            = 96438,
    SPELL_WAIL_OF_SORROW            = 96909,
    SPELL_LASH_OF_ANGUISH           = 96423,
    SPELL_WAVE_OF_AGONY             = 96457,
    SPELL_WAVE_OF_AGONY_TARGETING   = 98270,
    SPELL_WAVE_OF_AGONY_DUMMY_PING  = 96465,
    SPELL_WAVE_OF_AGONY_DAMAGE      = 96542,
    SPELL_CAVE_IN                   = 97380,
    SPELL_PRIMAL_BLESSING           = 96559,
    SPELL_PRIMAL_AWAKENING          = 96530,
    SPELL_RAGE_OF_THE_ANCIENTS      = 96896,
    SPELL_VENGEFUL_SMASH            = 96593,
    SPELL_CAMOUFLAGE                = 96594,
    SPELL_RAVAGE                    = 96592,
    SPELL_RAVAGE_CAMOUFLAGE         = 96700,

    // Pride of Bethekk
    SPELL_DARK_SLUMBER              = 96446,
    SPELL_GAPING_WOUND              = 97355
};

enum Events
{
    // High Priestess Kilnara
    EVENT_SHADOW_BOLT = 1,
    EVENT_TEARS_OF_BLOOD,
    EVENT_WAIL_OF_SORROW,
    EVENT_LASH_OF_ANGUISH,
    EVENT_WAVE_OF_AGONY,
    EVENT_MAKE_PANTHERS_ATTACKABLE,
    EVENT_TRANSFORM,
    EVENT_PRIMAL_BLESSING,
    EVENT_PRIMAL_AWAKENING,
    EVENT_REENGAGE_PLAYER,
    EVENT_VENGEFUL_SMASH,
    EVENT_RAVAGE,
    EVENT_CAMOUFLAGE,
    EVENT_PREPARE_RAVAGE,
    EVENT_RAVAGE_CAMOUFLAGE,

    // Pride of Bethekk
    EVENT_GAPING_WOUND
};

enum SummonGroups
{
    SUMMON_GROUP_PRIDE_OF_BETHEK = 0
};

struct boss_high_priestess_kilnara : public BossAI
{
    boss_high_priestess_kilnara(Creature* creature) : BossAI(creature, DATA_HIGH_PRIESTESS_KILNARA)
    {
        Initialize();
    }

    void Initialize()
    {
        _transformed = false;
    }

    void Reset() override
    {
        _Reset();
        Initialize();
        me->MakeInterruptable(false);
        me->SummonCreatureGroup(SUMMON_GROUP_PRIDE_OF_BETHEK);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        DoCastAOE(SPELL_CLEAR_ACHIEVEMENT_CREDITS);

        me->SetHover(false);
        me->SendSetPlayHoverAnim(false);
        me->RemoveAurasDueToSpell(SPELL_KILNARA_HOVER_VISUAL_1);
        me->RemoveAurasDueToSpell(SPELL_KILNARA_HOVER_VISUAL_2);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        events.ScheduleEvent(EVENT_SHADOW_BOLT, 1s + 500ms);
        events.ScheduleEvent(EVENT_MAKE_PANTHERS_ATTACKABLE, 1s + 700ms);
        events.ScheduleEvent(EVENT_TEARS_OF_BLOOD, 8s + 800ms);
        events.ScheduleEvent(EVENT_LASH_OF_ANGUISH, 17s);
        events.ScheduleEvent(EVENT_WAVE_OF_AGONY, 29s + 500ms);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        summons.DespawnAll();
        me->RemoveAllAuras();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _DespawnAtEvade();
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (!_transformed && me->HealthBelowPctDamaged(50, damage))
        {
            events.Reset();
            events.ScheduleEvent(EVENT_TRANSFORM, 1ms);
            _transformed = true;
        }
    }

    void OnSpellCastFinished(SpellInfo const* spell, SpellFinishReason reason) override
    {
        if (reason != SPELL_FINISHED_SUCCESSFUL_CAST)
            return;

        if (spell->Id == SPELL_CAMOUFLAGE)
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
        switch (summon->GetEntry())
        {
            case NPC_WAVE_OF_AGONY_1:
            {
                Talk(SAY_WAVE_OF_AGONY);
                float angle = me->GetAngle(summon);
                me->SetFacingToObject(summon);
                me->SetOrientation(angle); // Updating orientation before casting the following summon spell
                DoCast(summon, SPELL_WAVE_OF_AGONY);
                break;
            }
            case NPC_WAVE_OF_AGONY_2:
                summon->DespawnOrUnsummon(3s);
                break;
            case NPC_PRIDE_OF_BETHEKK:
                summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                summon->SetReactState(REACT_PASSIVE);
                break;
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
            switch (eventId)
            {
                case EVENT_SHADOW_BOLT:
                    DoCastVictim(SPELL_SHADOW_BOLT);
                    events.Repeat(2s, 2s + 500ms);
                    break;
                case EVENT_TEARS_OF_BLOOD:
                    me->StopMoving();
                    me->MakeInterruptable(true);
                    DoCastSelf(SPELL_TEARS_OF_BLOOD);
                    events.Repeat(21s, 24s);
                    break;
                case EVENT_LASH_OF_ANGUISH:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                        me->CastSpell(target, SPELL_LASH_OF_ANGUISH, TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_CAST_DIRECTLY));
                    events.Repeat(22s, 23s);
                    break;
                case EVENT_WAVE_OF_AGONY:
                    DoCastAOE(SPELL_WAVE_OF_AGONY_TARGETING);
                    events.DelayEvents(5s);
                    events.Repeat(42s + 500ms);
                    break;
                case EVENT_MAKE_PANTHERS_ATTACKABLE:
                    for (ObjectGuid guid : summons)
                        if (Creature* creature = ObjectAccessor::GetCreature(*me, guid))
                            if (creature->GetEntry() == NPC_PRIDE_OF_BETHEKK)
                                creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                    break;
                case EVENT_TRANSFORM:
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    DoCastAOE(SPELL_CAVE_IN);
                    Talk(SAY_TRANSFROM_1);
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_SPELL_CHANNEL_OMNI);
                    instance->SetData(DATA_CAST_CAVE_IN_VISUAL, DONE);
                    events.ScheduleEvent(EVENT_PRIMAL_BLESSING, 6s);
                    break;
                case EVENT_PRIMAL_BLESSING:
                    DoCastSelf(SPELL_PRIMAL_BLESSING);
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY_UNARMED);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISARMED);
                    events.ScheduleEvent(EVENT_PRIMAL_AWAKENING, 1s);
                    break;
                case EVENT_PRIMAL_AWAKENING:
                    DoCastAOE(SPELL_PRIMAL_AWAKENING);
                    DoCastSelf(SPELL_RAGE_OF_THE_ANCIENTS);
                    events.ScheduleEvent(EVENT_REENGAGE_PLAYER, 1s + 200ms);
                    break;
                case EVENT_REENGAGE_PLAYER:
                    Talk(SAY_TRANSFROM_2);
                    me->SetReactState(REACT_AGGRESSIVE);
                    if (Unit* victim = me->GetVictim())
                        AttackStart(victim);
                    events.ScheduleEvent(EVENT_VENGEFUL_SMASH, 7s + 200ms);
                    events.ScheduleEvent(EVENT_RAVAGE, 4s);
                    events.ScheduleEvent(EVENT_CAMOUFLAGE, 22s);
                    break;
                case EVENT_VENGEFUL_SMASH:
                    DoCastAOE(SPELL_VENGEFUL_SMASH);
                    events.Repeat(35s, 37s);
                    break;
                case EVENT_RAVAGE:
                    DoCastVictim(SPELL_RAVAGE);
                    events.Repeat(11s);
                    break;
                case EVENT_CAMOUFLAGE:
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    DoCastSelf(SPELL_CAMOUFLAGE);
                    events.DelayEvents(10s);
                    events.Repeat(36s + 500ms);
                    events.ScheduleEvent(EVENT_PREPARE_RAVAGE, 2s);
                    break;
                case EVENT_PREPARE_RAVAGE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        AttackStart(target);
                    events.ScheduleEvent(EVENT_RAVAGE_CAMOUFLAGE, 4s);
                    break;
                case EVENT_RAVAGE_CAMOUFLAGE:
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                    me->RemoveAurasDueToSpell(SPELL_CAMOUFLAGE);
                    if (Player* player = me->SelectNearestPlayer(10.0f))
                        DoCast(player, SPELL_RAVAGE_CAMOUFLAGE);
                    break;
                default:
                    break;
            }
        }

        if (_transformed)
            DoMeleeAttackIfReady();
    }
private:
    bool _transformed;
};

struct npc_kilnara_pride_of_bethekk : public ScriptedAI
{
    npc_kilnara_pride_of_bethekk(Creature* creature) : ScriptedAI(creature) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        me->SetReactState(REACT_AGGRESSIVE);
        me->RemoveAurasDueToSpell(SPELL_DARK_SLUMBER);
        _events.ScheduleEvent(EVENT_GAPING_WOUND, 8s, 10s);
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
                case EVENT_GAPING_WOUND:
                    DoCastAOE(SPELL_GAPING_WOUND);
                    _events.Repeat(8s, 10s);
                    break;
                default:
                    break;
            }
        }
        DoMeleeAttackIfReady();
    }
private:
    EventMap _events;
};

class spell_kilnara_tears_of_blood : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WAIL_OF_SORROW });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* creature = GetTarget()->ToCreature())
        {
            creature->MakeInterruptable(false);
            creature->CastSpell(creature, SPELL_WAIL_OF_SORROW);
        }
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_kilnara_tears_of_blood::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

class AttackerVictimCheck
{
    public:
        AttackerVictimCheck(Unit* _attacker) : attacker(_attacker)  { }

        bool operator()(WorldObject* object)
        {
            return (attacker->GetVictim() && attacker->GetVictim() == object->ToUnit());
        }
    private:
        Unit* attacker;
};

class spell_kilnara_wave_of_agony : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(AttackerVictimCheck(GetCaster()));

        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleHit(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_kilnara_wave_of_agony::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect.Register(&spell_kilnara_wave_of_agony::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_kilnara_wave_of_agony_dummy : public AuraScript
{
    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Unit* caster = GetCaster())
        {
            if (Unit* target = GetTarget())
            {
                caster->CastSpell(target, SPELL_WAVE_OF_AGONY_DAMAGE, true);
                caster->CastSpell(target, SPELL_WAVE_OF_AGONY_DUMMY_PING, true);
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_kilnara_wave_of_agony_dummy::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_kilnara_primal_awakening : public AuraScript
{
    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* creature = GetTarget()->ToCreature())
            if (creature->IsAIEnabled)
                creature->AI()->DoZoneInCombat();
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_kilnara_primal_awakening::AfterRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_kilnara_gaping_wound : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(Trinity::UnitAuraCheck(true, GetSpellInfo()->Effects[EFFECT_2].BasePoints));

        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_kilnara_gaping_wound::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

void AddSC_boss_high_priestess_kilnara()
{
    RegisterZulGurubCreatureAI(boss_high_priestess_kilnara);
    RegisterZulGurubCreatureAI(npc_kilnara_pride_of_bethekk);

    RegisterSpellScript(spell_kilnara_tears_of_blood);
    RegisterSpellScript(spell_kilnara_wave_of_agony);
    RegisterSpellScript(spell_kilnara_wave_of_agony_dummy);
    RegisterSpellScript(spell_kilnara_primal_awakening);
    RegisterSpellScript(spell_kilnara_gaping_wound);
}

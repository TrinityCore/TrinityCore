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
#include "zulgurub.h"
#include "GridNotifiers.h"
#include "MotionMaster.h"
#include "MoveSplineInit.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "Vehicle.h"

enum RollingBoulders
{
    SPELL_ROLLING_BOULDERS_PERIODIC_AURA    = 96837,
    SPELL_ROLLING_BOULDERS_SEARCH_EFFECT    = 96839,
    SPELL_ROLLING_BOULDERS_SUMMON_LEFT      = 96827,
    SPELL_ROLLING_BOULDERS_SUMMON_CENTER    = 96828,
    SPELL_ROLLING_BOULDERS_SUMMON_RIGHT     = 96829,
    SPELL_THUNDERCLAP                       = 15588,
    SPELL_KNOCK_AWAY                        = 97616,
    SPELL_EXPLODING_BOULDER                 = 96836,
    SPELL_EXPLODING_BOULDER_VISUAL          = 96831,
    SPELL_ROLLING_BOULDERS                  = 96833,

    NPC_BOULDER_LEFT                        = 52351,
    NPC_BOULDER_CENTER                      = 52354,
    NPC_BOULDER_RIGHT                       = 52353,

    EVENT_THUNDERCLAP                       = 1,
    EVENT_KNOCK_AWAY                        = 2,

    ACTION_ROLL_BOULDER                     = 0,
    SEAT_0                                  = 0
};

uint32 boulderCombinationFirst[] =
{
    SPELL_ROLLING_BOULDERS_SUMMON_RIGHT,
    SPELL_ROLLING_BOULDERS_SUMMON_CENTER,
    SPELL_ROLLING_BOULDERS_SUMMON_LEFT
};

uint32 boulderCombinationSecond[] =
{
    SPELL_ROLLING_BOULDERS_SUMMON_RIGHT,
    SPELL_ROLLING_BOULDERS_SUMMON_LEFT,
    SPELL_ROLLING_BOULDERS_SUMMON_CENTER
};

Position const BoulderMovePosLeft   = { -12128.5f,  -1809.7f,   81.73696f };
Position const BoulderMovePosCenter = { -12117.74f, -1818.293f, 80.22023f };
Position const BoulderMovePosRight  = { -12126.91f, -1827.861f, 81.26235f };

class ExplodingBoulderEvent : public BasicEvent
{
    public:
        ExplodingBoulderEvent(Creature* owner) :  _owner(owner) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->RemoveAurasDueToSpell(SPELL_EXPLODING_BOULDER_VISUAL);
            _owner->CastSpell(_owner, SPELL_EXPLODING_BOULDER);
            _owner->DespawnOrUnsummon(1s);
            if (Vehicle* vehicle = _owner->GetVehicleKit())
                if (Unit* passenger = vehicle->GetPassenger(SEAT_0))
                    if (Creature* creature = passenger->ToCreature())
                        creature->DespawnOrUnsummon(1s);
            return true;
        }
    private:
        Creature* _owner;
};

class RollingBouldersCastEvent : public BasicEvent
{
    public:
        RollingBouldersCastEvent(Creature* owner) :  _owner(owner) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->CastSpell(_owner, SPELL_ROLLING_BOULDERS);
            return true;
        }
    private:
        Creature* _owner;
};

struct npc_zulgurub_berserking_boulder_roller : public ScriptedAI
{
    npc_zulgurub_berserking_boulder_roller(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        me->SetReactState(REACT_PASSIVE);
        _useSecondCombination = false;
    }

    void Reset() override
    {
        Initialize();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_THUNDERCLAP, 2s);
        _events.ScheduleEvent(EVENT_KNOCK_AWAY, 6s, 7s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        _events.Reset();
        me->SetReactState(REACT_PASSIVE);
        me->GetMotionMaster()->MoveTargetedHome();
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_ROLLING_BOULDERS_SEARCH_EFFECT)
        {
            me->SetReactState(REACT_AGGRESSIVE);
            me->RemoveAurasDueToSpell(SPELL_ROLLING_BOULDERS_PERIODIC_AURA);
            AttackStart(target);
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_ROLL_BOULDER)
        {
            uint32 spellId = !_useSecondCombination ? boulderCombinationFirst[_boulderCount] : boulderCombinationSecond[_boulderCount];
            DoCastSelf(spellId, true);

            if (_boulderCount < 2)
                _boulderCount++;
            else
            {
                _boulderCount = 0;
                _useSecondCombination = !_useSecondCombination ? true : false;
            }
        }
    }

    void JustSummoned(Creature* summon) override
    {
        Position destination;
        switch (summon->GetEntry())
        {
            case NPC_BOULDER_LEFT:
                destination = BoulderMovePosLeft;
                break;
            case NPC_BOULDER_CENTER:
                destination = BoulderMovePosCenter;
                break;
            case NPC_BOULDER_RIGHT:
                destination = BoulderMovePosRight;
                break;
            default:
                break;
        }

        Movement::MoveSplineInit init(summon);
        init.MoveTo(destination.GetPositionX(), destination.GetPositionY(), destination.GetPositionZ());
        if (uint32 time = init.Launch())
            summon->m_Events.AddEventAtOffset(new ExplodingBoulderEvent(summon), Milliseconds(time));

        summon->m_Events.AddEventAtOffset(new RollingBouldersCastEvent(summon), 600ms);
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
                case EVENT_THUNDERCLAP:
                    DoCastAOE(SPELL_THUNDERCLAP);
                    _events.Repeat(15s, 16s);
                    break;
                case EVENT_KNOCK_AWAY:
                    DoCastVictim(SPELL_KNOCK_AWAY);
                    _events.Repeat(19s, 20s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    uint8 _boulderCount;
    bool _useSecondCombination;
};

class spell_zulgurub_rolling_boulders : public AuraScript
{
    void HandleTick(AuraEffect const* /*aurEff*/)
    {
        // Serverside spell. We just skip that part and do it directly via script
        PreventDefaultAction();
        if (Creature* creature = GetTarget()->ToCreature())
            if (creature->IsAIEnabled)
                creature->AI()->DoAction(ACTION_ROLL_BOULDER);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_zulgurub_rolling_boulders::HandleTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

enum VenomGuardDestroyer
{
    SPELL_BREATH_OF_HETHISS     = 96753,
    SPELL_POOL_OF_ACRID_TEARS   = 96754,
    SPELL_CAULDRON_NEUTRALIZER  = 97337,

    EVENT_BREATH_OF_HETHISS     = 1,
    EVENT_RESTORE_REACT_STATE,
    EVENT_POOL_OF_ACRID_TEARS,
    EVENT_CAULDRON_NEUTRALIZER,
};

struct npc_zulgurub_venomguard_destroyer : public ScriptedAI
{
    npc_zulgurub_venomguard_destroyer(Creature* creature) : ScriptedAI(creature), _summons(me) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_BREATH_OF_HETHISS, 4s, 5s);
        _events.ScheduleEvent(EVENT_POOL_OF_ACRID_TEARS, 9s, 10s);
        _events.ScheduleEvent(EVENT_CAULDRON_NEUTRALIZER, 10s, 11s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        _events.Reset();
        _summons.DespawnAll();
        me->GetMotionMaster()->MoveTargetedHome();
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void JustDied(Unit* /*who*/) override
    {
        _summons.DespawnAll();
        _events.Reset();
    }

    void JustSummoned(Creature* summon) override
    {
        _summons.Summon(summon);
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
                case EVENT_BREATH_OF_HETHISS:
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->StopMoving();
                    DoCastSelf(SPELL_BREATH_OF_HETHISS);
                    _events.ScheduleEvent(EVENT_RESTORE_REACT_STATE, 4s + 500ms);
                    _events.Repeat(14s, 15s);
                    break;
                case EVENT_RESTORE_REACT_STATE:
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case EVENT_POOL_OF_ACRID_TEARS:
                    if (Unit* target = SelectTarget(SELECT_TARGET_MAXDISTANCE, 0, 50.0f, true))
                        DoCast(target, SPELL_POOL_OF_ACRID_TEARS);
                    _events.Repeat(13s, 14s);
                    break;
                case EVENT_CAULDRON_NEUTRALIZER:
                    DoCastAOE(SPELL_CAULDRON_NEUTRALIZER);
                    _events.Repeat(24s, 25s);
                    break;
                default:
                    break;
            }
        }
        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    SummonList _summons;
};

enum TikiLordMuLoa
{
    SPELL_TIKI_TORCH                = 96822,
    SPELL_TIKI_LORD_VISUAL_MU_LOA_1 = 96798,
    SPELL_TIKI_LORD_VISUAL_MU_LOA_2 = 97147,
    SPELL_TIKI_LORD_VISUAL_MU_LOA_3 = 97148,
    EVENT_TIKI_TORCH                = 1
};

struct npc_zulgurub_tiki_lord_mu_loa : public ScriptedAI
{
    npc_zulgurub_tiki_lord_mu_loa(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_TIKI_TORCH, 1ms);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        _events.Reset();
        me->ReleaseSpellFocus(nullptr, false);
        me->GetMotionMaster()->MoveTargetedHome();
    }

    void JustDied(Unit* /*who*/) override
    {
        _events.Reset();
        me->RemoveAurasDueToSpell(SPELL_TIKI_LORD_VISUAL_MU_LOA_1);
        DoCastSelf(SPELL_TIKI_LORD_VISUAL_MU_LOA_3, true);
        DoCastSelf(SPELL_TIKI_LORD_VISUAL_MU_LOA_2, true);
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
                case EVENT_TIKI_TORCH:
                    me->StopMoving();
                    DoCastVictim(SPELL_TIKI_TORCH);
                    _events.Repeat(10s);
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
};

enum TikiLordZimVae
{
    SPELL_TIKI_LORD_VISUAL_ZIM_WAE_1    = 96851,
    SPELL_TIKI_LORD_VISUAL_ZIM_WAE_2    = 97236,
    SPELL_TIKI_LORD_VISUAL_ZIM_WAE_3    = 97237,
    SPELL_BONE_VOLLEY                   = 96871,
    EVENT_BONE_VOLLEY                   = 1
};

struct npc_zulgurub_tiki_lord_zim_wae : public ScriptedAI
{
    npc_zulgurub_tiki_lord_zim_wae(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_BONE_VOLLEY, 1ms);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        _events.Reset();
        me->GetMotionMaster()->MoveTargetedHome();
    }

    void JustDied(Unit* /*who*/) override
    {
        _events.Reset();
        me->RemoveAurasDueToSpell(SPELL_TIKI_LORD_VISUAL_ZIM_WAE_1);
        DoCastSelf(SPELL_TIKI_LORD_VISUAL_ZIM_WAE_3, true);
        DoCastSelf(SPELL_TIKI_LORD_VISUAL_ZIM_WAE_2, true);
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
                case EVENT_BONE_VOLLEY:
                    DoCastAOE(SPELL_BONE_VOLLEY);
                    _events.Repeat(2s + 500ms);
                    break;
                default:
                    break;
            }
        }
    }
private:
    EventMap _events;
};

enum SigilShatter
{
    SPELL_SIGIL_OF_FLAME = 98006,
    SPELL_SIGIL_OF_FROST = 98015,
    SPELL_SIGIL_OF_DEATH = 98018
};

class spell_zulgurub_sigil_shatter : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_SIGIL_OF_FLAME,
                SPELL_SIGIL_OF_FROST,
                SPELL_SIGIL_OF_DEATH
            });
    }

    void FilterSigilOfFlameTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        uint32 spellId = sSpellMgr->GetSpellIdForDifficulty(SPELL_SIGIL_OF_FLAME, GetCaster());

        targets.remove_if(Trinity::UnitAuraCheck(true, spellId));
    }

    void FilterSigilOfFrostTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        uint32 spellId = sSpellMgr->GetSpellIdForDifficulty(SPELL_SIGIL_OF_FROST, GetCaster());

        targets.remove_if(Trinity::UnitAuraCheck(true, spellId));
    }

    void FilterSigilOfDeathTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        uint32 spellId = sSpellMgr->GetSpellIdForDifficulty(SPELL_SIGIL_OF_DEATH, GetCaster());

        targets.remove_if(Trinity::UnitAuraCheck(true, spellId));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_zulgurub_sigil_shatter::FilterSigilOfFlameTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect.Register(&spell_zulgurub_sigil_shatter::FilterSigilOfFrostTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect.Register(&spell_zulgurub_sigil_shatter::FilterSigilOfDeathTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

enum AncientGuardian
{
    SPELL_ANCIENT_GUARDIAN_HEAL = 97980
};

class spell_zulgurub_ancient_guardian : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ANCIENT_GUARDIAN_HEAL });
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
    {
        amount = -1;
    }

    void Absorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
    {
        Unit* target = GetTarget();
        if (dmgInfo.GetDamage() >= target->GetHealth())
        {
            absorbAmount = dmgInfo.GetDamage();
            int32 health = target->CountPctFromMaxHealth(50) - absorbAmount;
            target->CastSpell(target, SPELL_ANCIENT_GUARDIAN_HEAL,  CastSpellExtraArgs(aurEff).AddSpellBP0(health));
            Remove();
        }
    }

    void Register() override
    {
        DoEffectCalcAmount.Register(&spell_zulgurub_ancient_guardian::CalculateAmount, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb.Register(&spell_zulgurub_ancient_guardian::Absorb, EFFECT_1);
    }
};

enum GurubashiBerserker
{
    SAY_WHISPER_PURSUIT_PLAYER  = 0,
    SAY_ANNOUNCE_PURSUIT_PLAYER = 1,

    SPELL_PURSUIT               = 96342,
    SPELL_THUNDERCLAP_BERSERKER = 96340,
    SPELL_KNOCK_AWAY_BERSERKER  = 96341,

    //EVENT_THUNDERCLAP           = 1,
    //EVENT_KNOCK_AWAY            = 2,
    EVENT_PURSUIT               = 3,
};

struct npc_zulgurub_gurubashi_berserker: public ScriptedAI
{
    npc_zulgurub_gurubashi_berserker(Creature* creature) : ScriptedAI(creature) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_PURSUIT, 1s + 200ms);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _events.Reset();
        me->GetMotionMaster()->MoveTargetedHome();
    }

    void SpellHitTarget(Unit* victim, const SpellInfo* spellInfo) override
    {
        if (!victim)
            return;

        if (spellInfo->Id == SPELL_PURSUIT)
        {
            me->GetThreatManager().ResetAllThreat();
            AddThreat(victim, spellInfo->Effects[EFFECT_1].BasePoints);
            Talk(SAY_WHISPER_PURSUIT_PLAYER, victim);
            Talk(SAY_ANNOUNCE_PURSUIT_PLAYER, victim);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_PURSUIT:
                    me->SetReactState(REACT_AGGRESSIVE);
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true))
                        DoCast(target, SPELL_PURSUIT);

                    _events.ScheduleEvent(EVENT_THUNDERCLAP, 7s);
                    _events.ScheduleEvent(EVENT_KNOCK_AWAY, 6s);
                    _events.Repeat(14s);
                    break;
                case EVENT_THUNDERCLAP:
                    DoCastAOE(SPELL_THUNDERCLAP_BERSERKER);
                    break;
                case EVENT_KNOCK_AWAY:
                    DoCastVictim(SPELL_KNOCK_AWAY_BERSERKER);
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

enum ToadExplode
{
    SPELL_TOAD_EXPLODE = 24063
};

class spell_zulgurub_toad_explode : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TOAD_EXPLODE });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_TOAD_EXPLODE, true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_zulgurub_toad_explode::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_zulgurub()
{
    RegisterZulGurubCreatureAI(npc_zulgurub_berserking_boulder_roller);
    RegisterZulGurubCreatureAI(npc_zulgurub_venomguard_destroyer);
    RegisterZulGurubCreatureAI(npc_zulgurub_tiki_lord_mu_loa);
    RegisterZulGurubCreatureAI(npc_zulgurub_tiki_lord_zim_wae);
    RegisterZulGurubCreatureAI(npc_zulgurub_gurubashi_berserker);
    RegisterSpellScript(spell_zulgurub_rolling_boulders);
    RegisterSpellScript(spell_zulgurub_sigil_shatter);
    RegisterSpellScript(spell_zulgurub_ancient_guardian);
    RegisterSpellScript(spell_zulgurub_toad_explode);
}

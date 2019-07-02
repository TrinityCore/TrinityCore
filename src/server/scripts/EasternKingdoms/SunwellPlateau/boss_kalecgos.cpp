/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "sunwell_plateau.h"
#include "TemporarySummon.h"
#include "WorldSession.h"

enum Yells
{
    SAY_SATH_AGGRO        = 0,
    SAY_SATH_SLAY         = 1,
    SAY_SATH_DEATH        = 2,
    SAY_SATH_SPELL1       = 3,
    SAY_SATH_SPELL2       = 4,

    SAY_EVIL_AGGRO        = 0,
    SAY_EVIL_SLAY         = 1,
    SAY_OUTRO_1           = 2,
    SAY_OUTRO_2           = 3,
    EMOTE_ENRAGE          = 4,
    SAY_ARCANE_BUFFET     = 6,

    SAY_GOOD_NEAR_DEATH_0 = 0,
    SAY_GOOD_NEAR_DEATH_1 = 1,
    SAY_GOOD_NEAR_DEATH_2 = 2,
    SAY_GOOD_DEATH        = 3
};

enum Spells
{
    SPELL_SPECTRAL_BLAST          = 44869,
    SPELL_ARCANE_BUFFET           = 45018,
    SPELL_FROST_BREATH            = 44799,
    SPELL_TAIL_LASH               = 45122,
    SPELL_WILD_MAGIC_1            = 45001,
    SPELL_WILD_MAGIC_2            = 45002,
    SPELL_WILD_MAGIC_3            = 45004,
    SPELL_WILD_MAGIC_4            = 45006,
    SPELL_WILD_MAGIC_5            = 45010,
    SPELL_WILD_MAGIC_6            = 44978,
    SPELL_BANISH                  = 44836,
    SPELL_ENRAGE                  = 44807,
    SPELL_DEMONIC_VISUAL          = 44800,
    SPELL_CORRUPTION_STRIKE       = 45029,
    SPELL_AGONY_CURSE             = 45032,
    SPELL_SHADOW_BOLT             = 45031,
    SPELL_TAP_CHECK               = 46732,
    SPELL_TAP_CHECK_DAMAGE        = 46733,
    SPELL_AGONY_CURSE_VISUAL_1    = 45083,
    SPELL_AGONY_CURSE_VISUAL_2    = 45084,
    SPELL_AGONY_CURSE_VISUAL_3    = 45085,
    SPELL_AGONY_CURSE_ALLY        = 45034,
    SPELL_HEROIC_STRIKE           = 45026,
    SPELL_REVITALIZE              = 45027,
    SPELL_SPECTRAL_BLAST_EFFECT   = 44866,
    SPELL_SPECTRAL_BLAST_VISUAL   = 46648,
    SPELL_SPECTRAL_REALM_TRIGGER  = 44811,
    SPELL_SPECTRAL_REALM_TELEPORT = 46019,
    SPELL_SPECTRAL_REALM_AURA     = 46021,
    SPELL_SPECTRAL_REALM_2        = 44845,
    SPELL_SPECTRAL_REALM_REACTION = 44852,
    SPELL_SPECTRAL_EXHAUSTION     = 44867,
    SPELL_TELEPORT_BACK           = 46020
};

enum KalecgosEvents
{
    EVENT_ARCANE_BUFFET = 1,
    EVENT_FROST_BREATH,
    EVENT_WILD_MAGIC,
    EVENT_TAIL_LASH,
    EVENT_SPECTRAL_BLAST,
    EVENT_CHECK_TIMER,
    EVENT_OUTRO_START,
    EVENT_OUTRO_1,
    EVENT_OUTRO_2,
    EVENT_OUTRO_3,
    EVENT_REVITALIZE,
    EVENT_HEROIC_STRIKE,
    EVENT_SHADOWBOLT,
    EVENT_AGONY_CURSE,
    EVENT_CORRUPTION_STRIKE
};

enum SWPActions
{
    ACTION_START_OUTRO = 1,
    ACTION_ENRAGE
};

enum KalecSayPhases
{
    PHASE_SAY_ONE = 1,
    PHASE_SAY_TWO,
    PHASE_SAY_THREE,
    PHASE_SAY_FOUR,
    PHASE_OUTRO
};

enum KalecgosPoints
{
    POINT_OUTRO_1 = 0,
    POINT_OUTRO_2
};

Position const KalecgosSummonPos = { 1709.094f, 927.5035f, -74.28364f, 2.932153f };
Position const FlyPos[2] =
{
    { 1704.18f,  927.999f,  57.888f   },
    { 1614.355f, 846.9694f, 119.0971f }
};

uint32 const WildMagicSpells[6] =
{
    SPELL_WILD_MAGIC_1,
    SPELL_WILD_MAGIC_2,
    SPELL_WILD_MAGIC_3,
    SPELL_WILD_MAGIC_4,
    SPELL_WILD_MAGIC_5,
    SPELL_WILD_MAGIC_6
};

struct boss_kalecgos : public BossAI
{
    boss_kalecgos(Creature* creature) : BossAI(creature, DATA_KALECGOS), _isEnraged(false), _isBanished(false) { }

    void Reset() override
    {
        _isEnraged = false;
        _isBanished = false;
        _Reset();
        events.ScheduleEvent(EVENT_ARCANE_BUFFET, 8s);
        events.ScheduleEvent(EVENT_FROST_BREATH, 15s);
        events.ScheduleEvent(EVENT_WILD_MAGIC, 10s);
        events.ScheduleEvent(EVENT_TAIL_LASH, 25s);
        events.ScheduleEvent(EVENT_SPECTRAL_BLAST, 20s, 25s);
        events.ScheduleEvent(EVENT_CHECK_TIMER, 1s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        if (events.IsInPhase(PHASE_OUTRO))
            return;

        _EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SPECTRAL_REALM_AURA, true, true);
        summons.DespawnAll();
        DespawnPortals();

        if (Creature* sathrovar = instance->GetCreature(DATA_SATHROVARR))
            _DespawnAtEvade(Seconds(10), sathrovar);

        _DespawnAtEvade(Seconds(10));
    }

    void DespawnPortals()
    {
        std::vector<GameObject*> portals;
        me->GetGameObjectListWithEntryInGrid(portals, GO_SPECTRAL_RIFT);
        for (GameObject* portal : portals)
            portal->Delete();
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_OUTRO:
                events.ScheduleEvent(EVENT_OUTRO_START, 1s);
                break;
            case ACTION_ENRAGE:
                _isEnraged = true;
                Talk(EMOTE_ENRAGE);
                DoCastSelf(SPELL_ENRAGE, true);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* who, uint32 &damage) override
    {
        if (damage >= me->GetHealth() && (!who || who->GetGUID() != me->GetGUID()))
            damage = 0;
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        Talk(SAY_EVIL_AGGRO);
        _JustEngagedWith();

        if (Creature* kalecgosHuman = me->SummonCreature(NPC_KALECGOS_HUMAN, KalecgosSummonPos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1000))
            if (Creature* sathrovar = instance->GetCreature(DATA_SATHROVARR))
            {
                sathrovar->SetInCombatWith(kalecgosHuman);
                kalecgosHuman->SetInCombatWith(sathrovar);
            }
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER && roll_chance_i(50))
            Talk(SAY_EVIL_SLAY);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        switch (id)
        {
            case POINT_OUTRO_1:
                Talk(SAY_OUTRO_1);
                events.ScheduleEvent(EVENT_OUTRO_3, Seconds(9));
                break;
            case POINT_OUTRO_2:
                me->SetVisible(false);
                DespawnPortals();
                me->KillSelf();
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && !events.IsInPhase(PHASE_OUTRO))
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ARCANE_BUFFET:
                    if (roll_chance_i(20))
                        Talk(SAY_ARCANE_BUFFET);
                    DoCastAOE(SPELL_ARCANE_BUFFET);
                    events.Repeat(Seconds(8));
                    break;
                case EVENT_FROST_BREATH:
                    DoCastAOE(SPELL_FROST_BREATH);
                    events.Repeat(Seconds(15));
                    break;
                case EVENT_TAIL_LASH:
                    DoCastAOE(SPELL_TAIL_LASH);
                    events.Repeat(Seconds(15));
                    break;
                case EVENT_WILD_MAGIC:
                    DoCastAOE(WildMagicSpells[urand(0, 5)], true);
                    events.Repeat(Seconds(20));
                    break;
                case EVENT_SPECTRAL_BLAST:
                    DoCastAOE(SPELL_SPECTRAL_BLAST, true);
                    events.Repeat(Seconds(20), Seconds(25));
                    break;
                case EVENT_CHECK_TIMER:
                    if (!_isEnraged && HealthBelowPct(10))
                        DoAction(ACTION_ENRAGE);

                    if (HealthBelowPct(1))
                    {
                        if (Creature* sathrovarr = instance->GetCreature(DATA_SATHROVARR))
                        {
                            if (sathrovarr->HasAura(SPELL_BANISH))
                            {
                                sathrovarr->CastSpell(sathrovarr, SPELL_TAP_CHECK, true);
                                break;
                            }
                        }
                        if (_isBanished)
                            break;

                        _isBanished = true;
                        DoCastSelf(SPELL_BANISH, true);
                        events.Reset();
                    }
                    events.Repeat(Seconds(1));
                    break;
                case EVENT_OUTRO_START:
                    events.Reset();
                    events.SetPhase(PHASE_OUTRO);
                    me->SetRegenerateHealth(false);
                    me->SetReactState(REACT_PASSIVE);
                    me->InterruptNonMeleeSpells(true);
                    me->RemoveAllAttackers();
                    me->AttackStop();
                    me->SetFaction(FACTION_FRIENDLY);
                    me->RemoveAllAuras();
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    events.ScheduleEvent(EVENT_OUTRO_1, Seconds(3));
                    break;
                case EVENT_OUTRO_1:
                    me->SetDisableGravity(true);
                    me->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
                    events.ScheduleEvent(EVENT_OUTRO_2, Seconds(3));
                    break;
                case EVENT_OUTRO_2:
                    me->GetMotionMaster()->MovePoint(POINT_OUTRO_1, FlyPos[0]);
                    break;
                case EVENT_OUTRO_3:
                    Talk(SAY_OUTRO_2);
                    me->GetMotionMaster()->MovePoint(POINT_OUTRO_2, FlyPos[1], false);
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
    bool _isEnraged;
    bool _isBanished;
};

struct boss_kalecgos_human : public ScriptedAI
{
    boss_kalecgos_human(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _events.Reset();
        _events.SetPhase(PHASE_SAY_ONE);

        if (Creature* sath = _instance->GetCreature(DATA_SATHROVARR))
            _sathGUID = sath->GetGUID();

        _events.ScheduleEvent(EVENT_REVITALIZE, 5s);
        _events.ScheduleEvent(EVENT_HEROIC_STRIKE, 3s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_GOOD_DEATH);
    }

    void DamageTaken(Unit* who, uint32 &damage) override
    {
        if (!who || who->GetGUID() != _sathGUID)
            damage = 0;

        if (HealthBelowPct(75) && _events.IsInPhase(PHASE_SAY_ONE))
        {
            Talk(SAY_GOOD_NEAR_DEATH_0);
            _events.SetPhase(PHASE_SAY_TWO);
        }
        else if (HealthBelowPct(50) && _events.IsInPhase(PHASE_SAY_TWO))
        {
            _events.SetPhase(PHASE_SAY_THREE);
            Talk(SAY_GOOD_NEAR_DEATH_1);
        }
        else if (HealthBelowPct(10) && _events.IsInPhase(PHASE_SAY_THREE))
        {
            _events.SetPhase(PHASE_SAY_FOUR);
            Talk(SAY_GOOD_NEAR_DEATH_2);
        }
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
                case EVENT_REVITALIZE:
                    DoCastSelf(SPELL_REVITALIZE);
                    _events.Repeat(Seconds(5));
                    break;
                case EVENT_HEROIC_STRIKE:
                    DoCastVictim(SPELL_HEROIC_STRIKE);
                    _events.Repeat(Seconds(2));
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
    InstanceScript* _instance;
    EventMap _events;
    ObjectGuid _sathGUID;
};

class CurseAgonySelector : NonTankTargetSelector
{
public:
    CurseAgonySelector(Unit* source) : NonTankTargetSelector(source, true) { }

    bool operator()(WorldObject* target) const
    {
        if (Unit* unitTarget = target->ToUnit())
            return !NonTankTargetSelector::operator()(unitTarget)
            && !unitTarget->HasAura(SPELL_AGONY_CURSE)
            && !unitTarget->HasAura(SPELL_AGONY_CURSE_ALLY)
            && unitTarget->HasAura(SPELL_SPECTRAL_REALM_AURA);
        return false;
    }
};

struct boss_sathrovarr : public BossAI
{
    boss_sathrovarr(Creature* creature) : BossAI(creature, DATA_KALECGOS), _isEnraged(false), _isBanished(false) { }

    void Reset() override
    {
        _isEnraged = false;
        _isBanished = false;
        _Reset();
        events.ScheduleEvent(EVENT_SHADOWBOLT, 7s, 10s);
        events.ScheduleEvent(EVENT_AGONY_CURSE, 20s);
        events.ScheduleEvent(EVENT_CORRUPTION_STRIKE, 13s);
        events.ScheduleEvent(EVENT_CHECK_TIMER, 1s);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
        Talk(SAY_SATH_AGGRO);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        if (Creature* kalecgos = instance->GetCreature(DATA_KALECGOS_DRAGON))
            kalecgos->AI()->EnterEvadeMode(why);
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_TAP_CHECK_DAMAGE)
        {
            DoCastSelf(SPELL_TELEPORT_BACK, true);
            Unit::Kill(caster, me);
        }
    }

    void DamageTaken(Unit* who, uint32 &damage) override
    {
        if (damage >= me->GetHealth() && (!who || who->GetGUID() != me->GetGUID()))
            damage = 0;
    }

    void KilledUnit(Unit* target) override
    {
        if (target->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SATH_SLAY);
        else if (Creature* kalecgosHuman = instance->GetCreature(DATA_KALECGOS_HUMAN))
        {
            if (kalecgosHuman->GetGUID() == target->GetGUID())
                EnterEvadeMode(EVADE_REASON_OTHER);
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_SATH_DEATH);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SPECTRAL_REALM_AURA, true, true);
        if (Creature* kalecgos = instance->GetCreature(DATA_KALECGOS_DRAGON))
            kalecgos->AI()->DoAction(ACTION_START_OUTRO);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_SHADOWBOLT:
                if (roll_chance_i(20))
                    Talk(SAY_SATH_SPELL1);
                DoCastAOE(SPELL_SHADOW_BOLT);
                events.Repeat(Seconds(7), Seconds(10));
                break;
            case EVENT_AGONY_CURSE:
            {
                CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                args.AddSpellMod(SPELLVALUE_MAX_TARGETS, 1);
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, CurseAgonySelector(me)))
                    DoCast(target, SPELL_AGONY_CURSE, args);
                else
                    DoCastVictim(SPELL_AGONY_CURSE, args);
                events.Repeat(Seconds(20));
                break;
            }
            case EVENT_CORRUPTION_STRIKE:
                if (roll_chance_i(20))
                    Talk(SAY_SATH_SPELL2);
                DoCastVictim(SPELL_CORRUPTION_STRIKE);
                events.Repeat(Seconds(13));
                break;
            case EVENT_CHECK_TIMER:
            {
                if (HealthBelowPct(10) && !_isEnraged)
                {
                    _isEnraged = true;
                    if (Creature* kalecgos = instance->GetCreature(DATA_KALECGOS_DRAGON))
                        kalecgos->AI()->DoAction(ACTION_ENRAGE);
                }

                if (HealthBelowPct(1))
                {
                    if (Creature* kalecgos = instance->GetCreature(DATA_KALECGOS_DRAGON))
                    {
                        if (kalecgos->HasAura(SPELL_BANISH))
                        {
                            DoCastSelf(SPELL_TAP_CHECK, true);
                            break;
                        }
                    }
                    if (_isBanished)
                        break;

                    _isBanished = true;
                    DoCastSelf(SPELL_BANISH, true);
                }
                events.Repeat(Seconds(1));
                break;
            }
            default:
                break;
        }
    }

private:
    bool _isEnraged;
    bool _isBanished;
};

class go_kalecgos_spectral_rift : public GameObjectScript
{
    public:
        go_kalecgos_spectral_rift() : GameObjectScript("go_kalecgos_spectral_rift") { }

        struct go_kalecgos_spectral_riftAI : public GameObjectAI
        {
            go_kalecgos_spectral_riftAI(GameObject* go) : GameObjectAI(go) { }

            bool GossipHello(Player* player) override
            {
                if (!player->HasAura(SPELL_SPECTRAL_EXHAUSTION))
                    player->CastSpell(player, SPELL_SPECTRAL_REALM_TRIGGER, true);
                return true;
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return GetSunwellPlateauAI<go_kalecgos_spectral_riftAI>(go);
        }
};

// 46732 - Tap Check
class spell_kalecgos_tap_check : public SpellScript
{
    PrepareSpellScript(spell_kalecgos_tap_check);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->Effects[EFFECT_0].CalcValue()) });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetCaster(), (uint32)GetSpellInfo()->Effects[EFFECT_0].CalcValue(), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kalecgos_tap_check::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class SpectralBlastSelector : NonTankTargetSelector
{
    public:
        SpectralBlastSelector(Unit* source) : NonTankTargetSelector(source, true) { }

        bool operator()(WorldObject* target) const
        {
            if (Unit* unitTarget = target->ToUnit())
                return !NonTankTargetSelector::operator()(unitTarget)
                && !unitTarget->HasAura(SPELL_SPECTRAL_EXHAUSTION)
                && !unitTarget->HasAura(SPELL_SPECTRAL_REALM_AURA);
            return false;
        }
};

// 44869 - Spectral Blast
class spell_kalecgos_spectral_blast : public SpellScript
{
    PrepareSpellScript(spell_kalecgos_spectral_blast);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SPECTRAL_BLAST_EFFECT,
            SPELL_SPECTRAL_BLAST_VISUAL,
            SPELL_SPECTRAL_REALM_TRIGGER
        });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(SpectralBlastSelector(GetCaster()));
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        target->CastSpell(target, SPELL_SPECTRAL_BLAST_EFFECT, true);
        caster->CastSpell(target, SPELL_SPECTRAL_BLAST_VISUAL, true);
        caster->CastSpell(target, SPELL_SPECTRAL_REALM_TRIGGER, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_kalecgos_spectral_blast::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_kalecgos_spectral_blast::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 44811 - Spectral Realm
class spell_kalecgos_spectral_realm_trigger : public SpellScript
{
    PrepareSpellScript(spell_kalecgos_spectral_realm_trigger);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SPECTRAL_REALM_TELEPORT,
            SPELL_SPECTRAL_REALM_AURA,
            SPELL_SPECTRAL_REALM_2,
            SPELL_SPECTRAL_REALM_REACTION
        });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        target->CastSpell(target, SPELL_SPECTRAL_REALM_TELEPORT, true);
        target->CastSpell(target, SPELL_SPECTRAL_REALM_AURA, true);
        target->CastSpell(target, SPELL_SPECTRAL_REALM_2, true);
        target->CastSpell(target, SPELL_SPECTRAL_REALM_REACTION, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kalecgos_spectral_realm_trigger::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 46021 - Spectral Realm
class spell_kalecgos_spectral_realm_aura : public AuraScript
{
    PrepareAuraScript(spell_kalecgos_spectral_realm_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SPECTRAL_REALM_REACTION,
            SPELL_TELEPORT_BACK,
            SPELL_SPECTRAL_EXHAUSTION
        });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->RemoveAurasDueToSpell(SPELL_SPECTRAL_REALM_REACTION);
        target->CastSpell(target, SPELL_TELEPORT_BACK, true);
        target->CastSpell(target, SPELL_SPECTRAL_EXHAUSTION, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_kalecgos_spectral_realm_aura::OnRemove, EFFECT_0, SPELL_AURA_MOD_INVISIBILITY_DETECT, AURA_EFFECT_HANDLE_REAL);
    }
};

// 45032, 45034 - Curse of Boundless Agony
class spell_kalecgos_curse_of_boundless_agony : public AuraScript
{
    PrepareAuraScript(spell_kalecgos_curse_of_boundless_agony);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_AGONY_CURSE_VISUAL_1,
            SPELL_AGONY_CURSE_VISUAL_2,
            SPELL_AGONY_CURSE_VISUAL_3,
            SPELL_AGONY_CURSE_ALLY
        });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (InstanceScript* instance = GetTarget()->GetInstanceScript())
            if (instance->GetBossState(DATA_KALECGOS) == IN_PROGRESS)
                return;

        Remove(AURA_REMOVE_BY_CANCEL);
    }

    void OnPeriodic(AuraEffect const* aurEff)
    {
        if (aurEff->GetTickNumber() <= 5)
            GetTarget()->CastSpell(GetTarget(), SPELL_AGONY_CURSE_VISUAL_1, true);
        else if (aurEff->GetTickNumber() <= 10)
            GetTarget()->CastSpell(GetTarget(), SPELL_AGONY_CURSE_VISUAL_2, true);
        else
            GetTarget()->CastSpell(GetTarget(), SPELL_AGONY_CURSE_VISUAL_3, true);
    }

    void HandleEffectPeriodicUpdate(AuraEffect* aurEff)
    {
        if (aurEff->GetTickNumber() > 1 && aurEff->GetTickNumber() % 5 == 1)
            aurEff->SetAmount(aurEff->GetAmount() * 2);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_CANCEL)
            return;

        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
        args.AddSpellMod(SPELLVALUE_MAX_TARGETS, 1);
        GetTarget()->CastSpell(GetTarget(), SPELL_AGONY_CURSE_ALLY, args);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_kalecgos_curse_of_boundless_agony::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_kalecgos_curse_of_boundless_agony::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_kalecgos_curse_of_boundless_agony::HandleEffectPeriodicUpdate, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        AfterEffectRemove += AuraEffectRemoveFn(spell_kalecgos_curse_of_boundless_agony::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_kalecgos()
{
    RegisterSunwellPlateauCreatureAI(boss_kalecgos);
    RegisterSunwellPlateauCreatureAI(boss_sathrovarr);
    RegisterSunwellPlateauCreatureAI(boss_kalecgos_human);
    new go_kalecgos_spectral_rift();
    RegisterSpellScript(spell_kalecgos_tap_check);
    RegisterSpellScript(spell_kalecgos_spectral_blast);
    RegisterSpellScript(spell_kalecgos_spectral_realm_trigger);
    RegisterAuraScript(spell_kalecgos_spectral_realm_aura);
    RegisterAuraScript(spell_kalecgos_curse_of_boundless_agony);
}

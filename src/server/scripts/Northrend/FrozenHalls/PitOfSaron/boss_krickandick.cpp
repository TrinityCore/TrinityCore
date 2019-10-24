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

#include "pit_of_saron.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Vehicle.h"

enum Spells
{
    SPELL_MIGHTY_KICK              = 69021, // ick's spell
    SPELL_SHADOW_BOLT              = 69028, // krick's spell
    SPELL_TOXIC_WASTE              = 69024, // krick's spell
    SPELL_EXPLOSIVE_BARRAGE_KRICK  = 69012, // special spell 1
    SPELL_EXPLOSIVE_BARRAGE_ICK    = 69263, // special spell 1
    SPELL_POISON_NOVA              = 68989, // special spell 2
    SPELL_PURSUIT                  = 68987, // special spell 3

    SPELL_EXPLOSIVE_BARRAGE_SUMMON = 69015,
    SPELL_EXPLODING_ORB            = 69017, // visual on exploding orb
    SPELL_AUTO_GROW                = 69020, // grow effect on exploding orb
    SPELL_HASTY_GROW               = 44851, // need to check growing stacks
    SPELL_EXPLOSIVE_BARRAGE_DAMAGE = 69019, // damage done by orb while exploding

    SPELL_STRANGULATING            = 69413, // krick's selfcast in intro
    SPELL_SUICIDE                  = 7,
    SPELL_KRICK_KILL_CREDIT        = 71308,
    SPELL_NECROMANTIC_POWER        = 69753
};

enum Yells
{
    // Krick
    SAY_KRICK_AGGRO       = 0,
    SAY_KRICK_SLAY        = 1,
    SAY_KRICK_BARRAGE_1   = 2,
    SAY_KRICK_BARRAGE_2   = 3,
    SAY_KRICK_POISON_NOVA = 4,
    SAY_KRICK_CHASE       = 5,
    SAY_KRICK_OUTRO_1     = 6,
    SAY_KRICK_OUTRO_3     = 7,
    SAY_KRICK_OUTRO_5     = 8,
    SAY_KRICK_OUTRO_8     = 9,

    // Ick
    SAY_ICK_POISON_NOVA   = 0,
    SAY_ICK_CHASE_1       = 1,

    // OUTRO
    SAY_JAYNA_OUTRO_2     = 0,
    SAY_JAYNA_OUTRO_4     = 1,
    SAY_JAYNA_OUTRO_10    = 2,
    SAY_SYLVANAS_OUTRO_2  = 0,
    SAY_SYLVANAS_OUTRO_4  = 1,
    SAY_SYLVANAS_OUTRO_10 = 2,
    SAY_TYRANNUS_OUTRO_7  = 1,
    SAY_TYRANNUS_OUTRO_9  = 2
};

enum Events
{
    EVENT_MIGHTY_KICK = 1,
    EVENT_SHADOW_BOLT,
    EVENT_TOXIC_WASTE,
    EVENT_SPECIAL, // special spell selection (one of event EVENT_PURSUIT, EVENT_POISON_NOVA or EVENT_EXPLOSIVE_BARRAGE)
    EVENT_PURSUIT,
    EVENT_POISON_NOVA,
    EVENT_EXPLOSIVE_BARRAGE,

    // Krick OUTRO
    EVENT_OUTRO_1,
    EVENT_OUTRO_2,
    EVENT_OUTRO_3,
    EVENT_OUTRO_4,
    EVENT_OUTRO_5,
    EVENT_OUTRO_6,
    EVENT_OUTRO_7,
    EVENT_OUTRO_8,
    EVENT_OUTRO_9,
    EVENT_OUTRO_10,
    EVENT_OUTRO_11,
    EVENT_OUTRO_12,
    EVENT_OUTRO_13,
    EVENT_OUTRO_END
};

enum KrickPhase
{
    PHASE_COMBAT = 1,
    PHASE_OUTRO = 2
};

enum Actions
{
    ACTION_OUTRO = 1,
    ACTION_STORE_OLD_TARGET,
    ACTION_RESET_THREAT
};

enum Points
{
    POINT_KRICK_INTRO = 364770,
    POINT_KRICK_DEATH = 364771
};

static Position const outroPos[8] =
{
    { 828.9342f, 118.6247f, 509.5190f, 0.0000000f },  // Krick's Outro Position
    { 841.0100f, 196.2450f, 573.9640f, 0.2046099f },  // Scourgelord Tyrannus Outro Position (Tele to...)
    { 777.2274f, 119.5521f, 510.0363f, 6.0562930f },  // Sylvanas / Jaine Outro Spawn Position (NPC_SYLVANAS_PART1)
    { 823.3984f, 114.4907f, 509.4899f, 0.0000000f },  // Sylvanas / Jaine Outro Move Position (1)
    { 835.5887f, 139.4345f, 530.9526f, 0.0000000f },  // Tyrannus fly down Position (not sniffed)
    { 828.9342f, 118.6247f, 514.5190f, 0.0000000f },  // Krick's Choke Position
    { 828.9342f, 118.6247f, 509.4958f, 0.0000000f },  // Kirck's Death Position
    { 914.4820f, 143.1602f, 633.3624f, 0.0000000f }   // Tyrannus fly up (not sniffed)
};

struct boss_ick : public BossAI
{
    boss_ick(Creature* creature) : BossAI(creature, DATA_ICK)
    {
        _oldTargetThreat = 0.0f;
    }

    void Reset() override
    {
        _Reset();

        _oldTargetGUID.Clear();
        _oldTargetThreat = 0.0f;
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();

        if (Creature* krick = GetKrick())
            krick->AI()->Talk(SAY_KRICK_AGGRO);

        events.ScheduleEvent(EVENT_MIGHTY_KICK, 20s);
        events.ScheduleEvent(EVENT_TOXIC_WASTE, 5s);
        events.ScheduleEvent(EVENT_SHADOW_BOLT, 10s);
        events.ScheduleEvent(EVENT_SPECIAL, 30s, 35s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();

        if (Vehicle* _vehicle = me->GetVehicleKit())
            _vehicle->RemoveAllPassengers();

        if (Creature* krick = GetKrick())
        {
            ForceCombatStop(krick, false);
            if (krick->AI())
                krick->AI()->DoAction(ACTION_OUTRO);
        }
    }

    void DoAction(int32 actionId) override
    {
        switch (actionId)
        {
            case ACTION_STORE_OLD_TARGET:
                if (Unit* victim = me->GetVictim())
                {
                    _oldTargetGUID = victim->GetGUID();
                    _oldTargetThreat = GetThreat(victim);
                }
                break;
            case ACTION_RESET_THREAT:
                me->GetThreatManager().ClearFixate();

                if (Unit* current = me->GetVictim())
                    ResetThreat(current);

                if (Unit* oldTarget = ObjectAccessor::GetUnit(*me, _oldTargetGUID))
                {
                    AddThreat(oldTarget, _oldTargetThreat);
                    _oldTargetGUID.Clear();
                    _oldTargetThreat = 0.0f;
                }
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
                case EVENT_TOXIC_WASTE:
                    if (Creature* krick = GetKrick())
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.f, true))
                            krick->CastSpell(target, SPELL_TOXIC_WASTE);
                    }
                    events.ScheduleEvent(EVENT_TOXIC_WASTE, 7s, 10s);
                    break;
                case EVENT_SHADOW_BOLT:
                    if (Creature* krick = GetKrick())
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.f, true))
                            krick->CastSpell(target, SPELL_SHADOW_BOLT);
                    }
                    events.ScheduleEvent(EVENT_SHADOW_BOLT, 15s);
                    return;
                case EVENT_MIGHTY_KICK:
                    DoCastVictim(SPELL_MIGHTY_KICK);
                    events.ScheduleEvent(EVENT_MIGHTY_KICK, 25s);
                    return;
                case EVENT_SPECIAL:
                    // Select one of these three special events
                    events.ScheduleEvent(RAND(EVENT_EXPLOSIVE_BARRAGE, EVENT_POISON_NOVA, EVENT_PURSUIT), 1s);
                    events.ScheduleEvent(EVENT_SPECIAL, 23s, 28s);
                    break;
                case EVENT_EXPLOSIVE_BARRAGE:
                    if (Creature* krick = GetKrick())
                    {
                        krick->AI()->Talk(SAY_KRICK_BARRAGE_1);
                        krick->AI()->Talk(SAY_KRICK_BARRAGE_2);
                        krick->CastSpell(krick, SPELL_EXPLOSIVE_BARRAGE_KRICK, true);
                        DoCastAOE(SPELL_EXPLOSIVE_BARRAGE_ICK);
                    }
                    events.DelayEvents(20s);
                    break;
                case EVENT_POISON_NOVA:
                    if (Creature* krick = GetKrick())
                        krick->AI()->Talk(SAY_KRICK_POISON_NOVA);

                    Talk(SAY_ICK_POISON_NOVA);
                    DoCastAOE(SPELL_POISON_NOVA);
                    break;
                case EVENT_PURSUIT:
                    if (Creature* krick = GetKrick())
                        krick->AI()->Talk(SAY_KRICK_CHASE);
                    DoCastSelf(SPELL_PURSUIT, { SPELLVALUE_MAX_TARGETS, 1 });
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
    Creature* GetKrick()
    {
        return ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_KRICK));
    }

    float _oldTargetThreat;
    ObjectGuid _oldTargetGUID;
};

struct boss_krick : public ScriptedAI
{
    boss_krick(Creature* creature) : ScriptedAI(creature), _instanceScript(creature->GetInstanceScript()), _summons(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        _phase = PHASE_COMBAT;
        _outroNpcGUID.Clear();
        _tyrannusGUID.Clear();
    }

    void Reset() override
    {
        _events.Reset();
        Initialize();

        me->SetReactState(REACT_PASSIVE);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() != TYPEID_PLAYER)
            return;

        Talk(SAY_KRICK_SLAY);
    }

    void JustSummoned(Creature* summon) override
    {
        _summons.Summon(summon);
        if (summon->GetEntry() == NPC_EXPLODING_ORB)
        {
            summon->CastSpell(summon, SPELL_EXPLODING_ORB, true);
            summon->CastSpell(summon, SPELL_AUTO_GROW, true);
        }
    }

    void DoAction(int32 actionId) override
    {
        if (actionId == ACTION_OUTRO)
        {
            if (Creature* tyrannusPtr = ObjectAccessor::GetCreature(*me, _instanceScript->GetGuidData(DATA_TYRANNUS_EVENT)))
                tyrannusPtr->NearTeleportTo(outroPos[1].GetPositionX(), outroPos[1].GetPositionY(), outroPos[1].GetPositionZ(), outroPos[1].GetOrientation());
            else if (TempSummon* newTyrannus = me->SummonCreature(NPC_TYRANNUS_EVENTS, outroPos[1], TEMPSUMMON_MANUAL_DESPAWN))
            {
                newTyrannus->SetCanFly(true);
                newTyrannus->SetFacingToObject(me);
            }

            me->GetMotionMaster()->MovePoint(POINT_KRICK_INTRO, outroPos[0].GetPositionX(), outroPos[0].GetPositionY(), outroPos[0].GetPositionZ());
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE || id != POINT_KRICK_INTRO)
            return;

        Talk(SAY_KRICK_OUTRO_1);
        _phase = PHASE_OUTRO;
        _events.Reset();
        _events.ScheduleEvent(EVENT_OUTRO_1, 1s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (_phase != PHASE_OUTRO)
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_OUTRO_1:
                {
                    if (Creature* temp = ObjectAccessor::GetCreature(*me, _instanceScript->GetGuidData(DATA_JAINA_SYLVANAS_1)))
                        temp->DespawnOrUnsummon();

                    Creature* jainaOrSylvanas = nullptr;
                    if (_instanceScript->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        jainaOrSylvanas = me->SummonCreature(NPC_JAINA_PART1, outroPos[2], TEMPSUMMON_MANUAL_DESPAWN);
                    else
                        jainaOrSylvanas = me->SummonCreature(NPC_SYLVANAS_PART1, outroPos[2], TEMPSUMMON_MANUAL_DESPAWN);

                    if (jainaOrSylvanas)
                    {
                        jainaOrSylvanas->GetMotionMaster()->MovePoint(0, outroPos[3]);
                        _outroNpcGUID = jainaOrSylvanas->GetGUID();
                    }
                    _events.ScheduleEvent(EVENT_OUTRO_2, 6000);
                    break;
                }
                case EVENT_OUTRO_2:
                    if (Creature* jainaOrSylvanas = ObjectAccessor::GetCreature(*me, _outroNpcGUID))
                    {
                        jainaOrSylvanas->SetFacingToObject(me);
                        me->SetFacingToObject(jainaOrSylvanas);
                        if (_instanceScript->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            jainaOrSylvanas->AI()->Talk(SAY_JAYNA_OUTRO_2);
                        else
                            jainaOrSylvanas->AI()->Talk(SAY_SYLVANAS_OUTRO_2);
                    }
                    _events.ScheduleEvent(EVENT_OUTRO_3, 5000);
                    break;
                case EVENT_OUTRO_3:
                    Talk(SAY_KRICK_OUTRO_3);
                    _events.ScheduleEvent(EVENT_OUTRO_4, 18000);
                    break;
                case EVENT_OUTRO_4:
                    if (Creature* jainaOrSylvanas = ObjectAccessor::GetCreature(*me, _outroNpcGUID))
                    {
                        if (_instanceScript->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            jainaOrSylvanas->AI()->Talk(SAY_JAYNA_OUTRO_4);
                        else
                            jainaOrSylvanas->AI()->Talk(SAY_SYLVANAS_OUTRO_4);
                    }
                    _events.ScheduleEvent(EVENT_OUTRO_5, 5000);
                    break;
                case EVENT_OUTRO_5:
                    Talk(SAY_KRICK_OUTRO_5);
                    _events.ScheduleEvent(EVENT_OUTRO_6, 1000);
                    break;
                case EVENT_OUTRO_6:
                    if (Creature* tyrannus = ObjectAccessor::GetCreature(*me, _instanceScript->GetGuidData(DATA_TYRANNUS_EVENT)))
                    {
                        tyrannus->SetSpeedRate(MOVE_FLIGHT, 3.5f);
                        tyrannus->GetMotionMaster()->MovePoint(1, outroPos[4]);
                        _tyrannusGUID = tyrannus->GetGUID();
                    }
                    _events.ScheduleEvent(EVENT_OUTRO_7, 5000);
                    break;
                case EVENT_OUTRO_7:
                    if (Creature* tyrannus = ObjectAccessor::GetCreature(*me, _tyrannusGUID))
                        tyrannus->AI()->Talk(SAY_TYRANNUS_OUTRO_7);
                    _events.ScheduleEvent(EVENT_OUTRO_8, 5000);
                    break;
                case EVENT_OUTRO_8:
                    //! HACK: Creature's can't have MOVEMENTFLAG_FLYING
                    me->AddUnitMovementFlag(MOVEMENTFLAG_FLYING);
                    me->GetMotionMaster()->MovePoint(0, outroPos[5]);
                    DoCast(me, SPELL_STRANGULATING);
                    _events.ScheduleEvent(EVENT_OUTRO_9, 2000);
                    break;
                case EVENT_OUTRO_9:
                    Talk(SAY_KRICK_OUTRO_8);
                    /// @todo Tyrannus starts killing Krick.
                    // there shall be some visual spell effect
                    if (Creature* tyrannus = ObjectAccessor::GetCreature(*me, _tyrannusGUID))
                        tyrannus->CastSpell(me, SPELL_NECROMANTIC_POWER, true);  //not sure if it's the right spell :/
                    _events.ScheduleEvent(EVENT_OUTRO_10, 1000);
                    break;
                case EVENT_OUTRO_10:
                    //! HACK: Creature's can't have MOVEMENTFLAG_FLYING
                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_FLYING);
                    me->AddUnitMovementFlag(MOVEMENTFLAG_FALLING_FAR);
                    me->GetMotionMaster()->MovePoint(0, outroPos[6]);
                    _events.ScheduleEvent(EVENT_OUTRO_11, 2000);
                    break;
                case EVENT_OUTRO_11:
                    DoCast(me, SPELL_KRICK_KILL_CREDIT); // don't really know if we need it
                    me->SetStandState(UNIT_STAND_STATE_DEAD);
                    me->SetHealth(0);
                    _events.ScheduleEvent(EVENT_OUTRO_12, 3000);
                    break;
                case EVENT_OUTRO_12:
                    if (Creature* tyrannus = ObjectAccessor::GetCreature(*me, _tyrannusGUID))
                        tyrannus->AI()->Talk(SAY_TYRANNUS_OUTRO_9);
                    _events.ScheduleEvent(EVENT_OUTRO_13, 2000);
                    break;
                case EVENT_OUTRO_13:
                    if (Creature* jainaOrSylvanas = ObjectAccessor::GetCreature(*me, _outroNpcGUID))
                    {
                        if (_instanceScript->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            jainaOrSylvanas->AI()->Talk(SAY_JAYNA_OUTRO_10);
                        else
                            jainaOrSylvanas->AI()->Talk(SAY_SYLVANAS_OUTRO_10);
                    }
                    // End of OUTRO. for now...
                    _events.ScheduleEvent(EVENT_OUTRO_END, 3s);
                    if (Creature* tyrannus = ObjectAccessor::GetCreature(*me, _tyrannusGUID))
                        tyrannus->GetMotionMaster()->MovePoint(0, outroPos[7]);
                    break;
                case EVENT_OUTRO_END:
                    if (Creature* tyrannus = ObjectAccessor::GetCreature(*me, _tyrannusGUID))
                        tyrannus->DespawnOrUnsummon();

                    me->DisappearAndDie();
                    break;
                default:
                    break;
            }
        }
    }

private:
    Creature* GetIck()
    {
        return ObjectAccessor::GetCreature(*me, _instanceScript->GetGuidData(DATA_ICK));
    }

    InstanceScript* _instanceScript;
    SummonList _summons;
    EventMap _events;

    KrickPhase _phase;
    ObjectGuid _outroNpcGUID;
    ObjectGuid _tyrannusGUID;
};

class spell_krick_explosive_barrage : public AuraScript
{
    PrepareAuraScript(spell_krick_explosive_barrage);

    void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        Unit* caster = GetCaster();
        if (!caster || caster->GetTypeId() != TYPEID_UNIT)
            return;

        Map::PlayerList const& players = caster->GetMap()->GetPlayers();
        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
        {
            if (Player* player = itr->GetSource())
                if (player->IsWithinDist(caster, 60.0f)) // don't know correct range
                    caster->CastSpell(player, SPELL_EXPLOSIVE_BARRAGE_SUMMON, true);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_krick_explosive_barrage::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_ick_explosive_barrage : public AuraScript
{
    PrepareAuraScript(spell_ick_explosive_barrage);

    void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster || caster->GetTypeId() != TYPEID_UNIT)
            return;

        caster->GetMotionMaster()->MoveIdle();
        caster->GetMotionMaster()->Clear(MOTION_PRIORITY_NORMAL);
    }

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster || caster->GetTypeId() != TYPEID_UNIT)
            return;

        if (Unit* victim = caster->GetVictim())
            caster->GetMotionMaster()->MoveChase(victim);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_ick_explosive_barrage::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_ick_explosive_barrage::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_exploding_orb_hasty_grow : public AuraScript
{
    PrepareAuraScript(spell_exploding_orb_hasty_grow);

    void OnStackChange(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetStackAmount() == 15)
        {
            Unit* target = GetTarget(); // store target because aura gets removed
            target->CastSpell(target, SPELL_EXPLOSIVE_BARRAGE_DAMAGE, false);
            target->RemoveAurasDueToSpell(SPELL_HASTY_GROW);
            target->RemoveAurasDueToSpell(SPELL_AUTO_GROW);
            target->RemoveAurasDueToSpell(SPELL_EXPLODING_ORB);
            if (Creature* creature = target->ToCreature())
                creature->DespawnOrUnsummon();
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_exploding_orb_hasty_grow::OnStackChange, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAPPLY);
    }
};

class spell_krick_pursuit : public SpellScript
{
    PrepareSpellScript(spell_krick_pursuit);

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        if (Creature* ick = GetCaster()->ToCreature())
        {
            ick->AI()->Talk(SAY_ICK_CHASE_1, target);
            ick->AddAura(GetSpellInfo()->Id, target);
            ick->AI()->DoAction(ACTION_STORE_OLD_TARGET);
            ick->GetThreatManager().AddThreat(target, float(GetEffectValue()), GetSpellInfo(), true, true);
            ick->GetThreatManager().FixateTarget(target);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_krick_pursuit::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_krick_pursuit_AuraScript : public AuraScript
{
    PrepareAuraScript(spell_krick_pursuit_AuraScript);

    void HandleExtraEffect(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster || caster->GetTypeId() != TYPEID_UNIT)
            return;

        caster->GetAI()->DoAction(ACTION_RESET_THREAT);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_krick_pursuit_AuraScript::HandleExtraEffect, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_krick_pursuit_confusion : public AuraScript
{
    PrepareAuraScript(spell_krick_pursuit_confusion);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
        GetTarget()->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
        GetTarget()->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, false);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_krick_pursuit_confusion::OnApply, EFFECT_2, SPELL_AURA_LINKED, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_krick_pursuit_confusion::OnRemove, EFFECT_2, SPELL_AURA_LINKED, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_ick()
{
    RegisterPitOfSaronCreatureAI(boss_ick);
    RegisterPitOfSaronCreatureAI(boss_krick);
    RegisterAuraScript(spell_krick_explosive_barrage);
    RegisterAuraScript(spell_ick_explosive_barrage);
    RegisterAuraScript(spell_exploding_orb_hasty_grow);
    RegisterSpellAndAuraScriptPair(spell_krick_pursuit, spell_krick_pursuit_AuraScript);
    RegisterAuraScript(spell_krick_pursuit_confusion);
}

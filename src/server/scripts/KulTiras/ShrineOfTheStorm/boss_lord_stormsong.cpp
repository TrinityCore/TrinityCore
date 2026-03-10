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
#include "Conversation.h"
#include "ConversationAI.h"
#include "Creature.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Vehicle.h"
#include "shrine_of_the_storm.h"

enum LordStormsongSpells
{
    SPELL_ANCIENT_MINDBENDER          = 269131,
    SPELL_CONVERSATION                = 274622,
    SPELL_CONVERSATION_ALLIANCE_INTRO = 274640,
    SPELL_CONVERSATION_ALLIANCE_OUTRO = 274674,
    SPELL_CONVERSATION_HORDE_INTRO    = 274641,
    SPELL_CONVERSATION_HORDE_OUTRO    = 274675,
    SPELL_DARK_BINDING                = 274646,
    SPELL_DISCIPLE_OF_THE_VOL_ZITH    = 269289,
    SPELL_ENERGIZE                    = 269396, // Serverside
    SPELL_EXPLOSIVE_VOID              = 269104,
    SPELL_FIXATE                      = 269103,
    SPELL_MIND_REND                   = 268896,
    SPELL_RELEASE_VOID                = 274711,
    SPELL_RIDE_VEHICLE                = 46598,
    SPELL_SURRENDER_TO_THE_VOID       = 269242,
    SPELL_VOID_BOLT                   = 268347,
    SPELL_WAKEN_THE_VOID_AREATRIGGER  = 269094,
    SPELL_WAKEN_THE_VOID_SUMMON       = 269095,
    SPELL_WAKEN_THE_VOID_AREA         = 269097
};

enum LordStormsongEvents
{
    EVENT_VOID_BOLT = 1,
    EVENT_MIND_REND,
    EVENT_WAKEN_THE_VOID,
    EVENT_CHECK_POWER,

    EVENT_OUTRO
};

enum LordStormsongTexts
{
    SAY_MINDBENDER_WARNING = 0
};

enum LordStormsongActions
{
    ACTION_START_INTRO = 1,
    ACTION_START_OUTRO
};

enum LordStormsongMisc
{
    DISPLAY_POWERID             = 425,

    NPC_QUEEN_AZSHARA           = 139963,
    NPC_ANCIENT_MINDBENDER      = 137051,
    NPC_WATER_STALKER           = 82347,

    CONVO_ACTOR_BROTHER_PIKE    = 65078,
    CONVO_ACTOR_REXXAR          = 65085,

    PATH_INTRO                  = 13997000,
    PATH_OUTRO                  = 13997001,

    WAYPOINT_BOSS_INTRO         = 11,
    WAYPOINT_BOSS_OUTRO         = 2
};

constexpr Position IntroPosition = { 3608.3933f, -1379.824f, 160.573f, 4.370550f };

// 134060 - Lord Stormsong
struct boss_lord_stormsong : public BossAI
{
    boss_lord_stormsong(Creature* creature) : BossAI(creature, DATA_LORD_STORMSONG) { }

    void JustAppeared() override
    {
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 55); // Energy bar is bugged on retail, but its working fine
        me->SetOverrideDisplayPowerId(DISPLAY_POWERID); // No aura handle

        if (instance->GetData(DATA_LORD_STORMSONG_INTRO) == DONE)
            me->SetImmuneToPC(false);
    }

    void DespawnMindbenders()
    {
        std::list<Creature*> mindbenders;
        me->GetCreatureListWithOptionsInGrid(mindbenders, 200.0f, { .CreatureId = NPC_ANCIENT_MINDBENDER });
        for (Creature* mindbender : mindbenders)
            mindbender->DespawnOrUnsummon();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->SetBossState(DATA_LORD_STORMSONG, FAIL);

        _EnterEvadeMode();
        _DespawnAtEvade();

        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ANCIENT_MINDBENDER);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DISCIPLE_OF_THE_VOL_ZITH);
        DespawnMindbenders();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        instance->SetBossState(DATA_LORD_STORMSONG, IN_PROGRESS);

        DoCastSelf(SPELL_ENERGIZE);

        events.ScheduleEvent(EVENT_VOID_BOLT, 8500ms);
        events.ScheduleEvent(EVENT_WAKEN_THE_VOID, 13500ms);
        events.ScheduleEvent(EVENT_CHECK_POWER, 500ms);

        if (IsHeroicOrHigher())
            events.ScheduleEvent(EVENT_MIND_REND, 16s);
    }

    void DoAction(int32 actionId) override
    {
        switch (actionId)
        {
            case ACTION_START_INTRO:
            {
                DoCastSelf(SPELL_CONVERSATION);
                me->SetEmoteState(EMOTE_ONESHOT_NONE);
                me->GetMap()->SummonCreature(instance->instance->GetTeamInInstance() == HORDE ? NPC_LORD_STORMSONG_REXXAR : NPC_LORD_STORMSONG_BROTHER_PIKE, IntroPosition);

                scheduler.Schedule(11s, [this](TaskContext task)
                {
                    me->SetFacingTo(1.047197f);
                    me->SetOrientation(me->GetOrientation());
                    Creature* azshara = me->FindNearestCreature(NPC_QUEEN_AZSHARA, 50.0f);
                    if (!azshara)
                        return;

                    azshara->DespawnOrUnsummon();

                    task.Schedule(16s, [this](TaskContext task)
                    {
                        DoCastSelf(SPELL_DARK_BINDING);

                        task.Schedule(6s, [this](TaskContext)
                        {
                            me->SetImmuneToPC(false);
                            me->SetEmoteState(EMOTE_STATE_READY1H);
                            instance->SetData(DATA_LORD_STORMSONG_INTRO, DONE);
                        });
                    });
                });
                break;
            }
            default:
                break;
        }
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        if (!target->IsPlayer())
            return;

        if (spellInfo->Id == SPELL_ANCIENT_MINDBENDER)
            Talk(SAY_MINDBENDER_WARNING, target);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->SetBossState(DATA_LORD_STORMSONG, DONE);

        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ANCIENT_MINDBENDER);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DISCIPLE_OF_THE_VOL_ZITH);

        DespawnMindbenders();

        Creature* pikeOrRexxar = me->GetInstanceScript()->GetCreature(instance->instance->GetTeamInInstance() == HORDE ? DATA_LORD_STORMSONG_REXXAR : DATA_LORD_STORMSONG_BROTHER_PIKE);
        if (!pikeOrRexxar)
            return;

        pikeOrRexxar->AI()->DoAction(ACTION_START_OUTRO);
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_VOID_BOLT:
                {
                    DoCastVictim(SPELL_VOID_BOLT);
                    events.Repeat(8500ms);
                    break;
                }
                case EVENT_MIND_REND:
                {
                    DoCastSelf(SPELL_MIND_REND);
                    events.Repeat(10500ms);
                    break;
                }
                case EVENT_WAKEN_THE_VOID:
                {
                    DoCastSelf(SPELL_WAKEN_THE_VOID_AREA);
                    events.Repeat(43500ms);
                    break;
                }
                case EVENT_CHECK_POWER:
                {
                    if (me->GetPower(POWER_ENERGY) >= 100)
                    {
                         DoCast(SPELL_ANCIENT_MINDBENDER);
                         events.RescheduleEvent(EVENT_CHECK_POWER, 2s);
                    }
                    events.Repeat(500ms);
                    break;
                }
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
};

// 137051 - Ancient Mindbender
struct boss_lord_stormsong_ancient_mindbender : public ScriptedAI
{
    boss_lord_stormsong_ancient_mindbender(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        TempSummon* tempSummon = me->ToTempSummon();
        if (!tempSummon)
            return;

        tempSummon->CastSpell(tempSummon->GetSummoner(), SPELL_RIDE_VEHICLE, TRIGGERED_FULL_MASK);
    }
};

// 139971 - Rexxar
// 139970 - Brother Pike
template<uint32 ConvoIntroSpellId, uint32 ConvoOutroSpellId>
struct boss_lord_stormsong_intro_npc : public ScriptedAI
{
    boss_lord_stormsong_intro_npc(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->GetMotionMaster()->MovePath(PATH_INTRO, false);
    }

    void WaypointReached(uint32 waypointId, uint32 pathId) override
    {
        if (pathId == PATH_INTRO)
        {
            if (waypointId == WAYPOINT_BOSS_INTRO)
                DoCastSelf(ConvoIntroSpellId);
        }
        else if (pathId == PATH_OUTRO)
        {
            if (waypointId == WAYPOINT_BOSS_OUTRO)
                DoCastSelf(ConvoOutroSpellId);
        }
    }

    void DoAction(int32 action) override
    {
        if (action != ACTION_START_OUTRO)
            return;

        Creature* stalker = me->FindNearestCreature(NPC_WATER_STALKER, 100.0f);
        if (!stalker)
            return;

        stalker->CastSpell(stalker, SPELL_RELEASE_VOID, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);

        _events.ScheduleEvent(EVENT_OUTRO, 2s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        switch (_events.ExecuteEvent())
        {
            case EVENT_OUTRO:
            {
                me->RemoveAurasDueToSpell(SPELL_DARK_BINDING);
                me->GetMotionMaster()->MovePath(PATH_OUTRO, false);
                break;
            }
            default:
                break;
        }
    }

private:
    EventMap _events;
};

// 269396 - Lord Stormsong Gain Energy (SERVERSIDE)
class spell_lord_stormsong_energize : public AuraScript
{
    static constexpr std::array<uint8, 2> LordStormsongEnergizeCycle = { 2, 3 };

    void PeriodicTick(AuraEffect const* aurEff) const
    {
        uint8 cycleIdx = aurEff->GetTickNumber() % LordStormsongEnergizeCycle.size();
        GetTarget()->ModifyPower(POWER_ENERGY, LordStormsongEnergizeCycle[cycleIdx]);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_lord_stormsong_energize::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 269021 - Waken the Void
class spell_lord_stormsong_waken_the_void_missile : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WAKEN_THE_VOID_AREATRIGGER, SPELL_FIXATE });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        Unit* caster = GetCaster();
        caster->CastSpell(GetHitUnit(), SPELL_WAKEN_THE_VOID_AREATRIGGER, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        caster->CastSpell(caster, SPELL_FIXATE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_lord_stormsong_waken_the_void_missile::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 269103 - Fixate
class spell_lord_stormsong_fixate : public SpellScript
{
    void HandleFixate(SpellEffIndex /*effIndex*/) const
    {
        Creature* caster = GetCaster()->ToCreature();
        if (!caster)
            return;

        caster->GetMotionMaster()->MoveFollow(GetHitUnit(), 0.0f);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_lord_stormsong_fixate::HandleFixate, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

class spell_lord_stormsong_fixate_aura : public AuraScript
{
    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        Creature* caster = GetCaster()->ToCreature();
        if (!caster)
            return;

        caster->DespawnOrUnsummon();
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_lord_stormsong_fixate_aura::AfterRemove, EFFECT_0, SPELL_AURA_MOD_FIXATE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 269131 - Ancient Mindbender
class spell_lord_stormsong_ancient_mindbender : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SURRENDER_TO_THE_VOID });
    }

    void HandleHit(SpellEffIndex /*effIndex*/) const
    {
        Unit* target = GetHitUnit();
        target->SummonCreature(NPC_ANCIENT_MINDBENDER, target->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
        target->CastSpell(target, SPELL_SURRENDER_TO_THE_VOID, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_lord_stormsong_ancient_mindbender::HandleHit, EFFECT_11, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_lord_stormsong_ancient_mindbender_aura : public AuraScript
{
    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        Vehicle* playerVehicle = GetTarget()->GetVehicleKit();
        if (!playerVehicle)
            return;

        Unit* ancientMindbender = playerVehicle->GetPassenger(0);
        if (!ancientMindbender)
            return;

        Creature* mindbender = ancientMindbender->ToCreature();
        if (!mindbender)
            return;

        mindbender->DespawnOrUnsummon();
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_lord_stormsong_ancient_mindbender_aura::OnRemove, EFFECT_2, SPELL_AURA_SET_VEHICLE_ID, AURA_EFFECT_HANDLE_REAL);
    }
};

// 269242 - Surrender to the Void
class spell_lord_stormsong_surrender_to_the_void : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ static_cast<uint32>(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void HandleDummy(SpellEffIndex /* effIndex */) const
    {
        GetHitUnit()->m_Events.AddEvent([hitUnit = GetHitUnit(), casterGUID = GetCaster()->GetGUID(), spellId = GetEffectValue()]()
        {
            if (Unit* caster = ObjectAccessor::GetUnit(*hitUnit, casterGUID))
                hitUnit->CastSpell(caster, uint32(spellId), TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        }, 0ms);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_lord_stormsong_surrender_to_the_void::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 269289 - Disciple of the Vol'zith
class spell_lord_stormsong_disciple_of_the_vol_zith : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ static_cast<uint32>(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/) const
    {
        Unit* target = GetTarget();
        target->CastSpell(target, GetEffectInfo(EFFECT_0).CalcValue(), TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_lord_stormsong_disciple_of_the_vol_zith::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 274711 - Release Void
class spell_lord_stormsong_release_void : public AuraScript
{
    void OnRemove(AuraEffect const* /*auraEffect*/, AuraEffectHandleModes /*mode*/) const
    {
        if (Creature* creatureCaster = GetCaster()->ToCreature())
            creatureCaster->DespawnOrUnsummon();
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_lord_stormsong_release_void::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 274710 - Release Void
class spell_lord_stormsong_release_void_missile : public SpellScript
{
    void ModDestHeight(SpellDestination& dest) const
    {
        Position const offset = { 0.0f, 0.0f, 20.0f, 0.0f };
        dest.RelocateOffset(offset);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_lord_stormsong_release_void_missile::ModDestHeight, EFFECT_1, TARGET_DEST_DEST_RANDOM);
    }
};

// 269094 - Waken the Void
struct at_lord_stormsong_waken_the_void : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(unit, SPELL_EXPLOSIVE_VOID, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        unit->RemoveAurasDueToSpell(SPELL_FIXATE);
        at->Remove();
    }
};

// Id - XXX
struct at_lord_stormsong_intro : AreaTriggerAI
{
    at_lord_stormsong_intro(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player || player->IsGameMaster())
            return;

        InstanceScript* instance = at->GetInstanceScript();
        if (!instance)
            return;

        if (Creature* lordStormsong = instance->GetCreature(DATA_LORD_STORMSONG))
            lordStormsong->AI()->DoAction(ACTION_START_INTRO);

        at->Remove();
    }
};

// 274640 - Conversation
// 274674 - Conversation
class conversation_lord_stormsong_brother_pike_intro_outro : public ConversationAI
{
public:
    conversation_lord_stormsong_brother_pike_intro_outro(Conversation* conversation) : ConversationAI(conversation) { }

    void OnCreate(Unit* creator) override
    {
        conversation->AddActor(CONVO_ACTOR_BROTHER_PIKE, 0, creator->GetGUID());
    }
};

// 274641 - Conversation
class conversation_lord_stormsong_rexxar_intro : public ConversationAI
{
public:
    conversation_lord_stormsong_rexxar_intro(Conversation* conversation) : ConversationAI(conversation) { }

    void OnCreate(Unit* creator) override
    {
        conversation->AddActor(CONVO_ACTOR_REXXAR, 1, creator->GetGUID());
    }
};

// 274675 - Conversation
class conversation_lord_stormsong_rexxar_outro : public ConversationAI
{
public:
    conversation_lord_stormsong_rexxar_outro(Conversation* conversation) : ConversationAI(conversation) { }

    void OnCreate(Unit* creator) override
    {
        conversation->AddActor(CONVO_ACTOR_REXXAR, 0, creator->GetGUID());
    }
};

void AddSC_boss_lord_stormsong()
{
    RegisterShrineOfTheStormCreatureAI(boss_lord_stormsong);
    RegisterShrineOfTheStormCreatureAI(boss_lord_stormsong_ancient_mindbender);
    new GenericCreatureScript<boss_lord_stormsong_intro_npc<SPELL_CONVERSATION_HORDE_INTRO, SPELL_CONVERSATION_HORDE_OUTRO>>("boss_lord_stormsong_rexxar");
    new GenericCreatureScript<boss_lord_stormsong_intro_npc<SPELL_CONVERSATION_ALLIANCE_INTRO, SPELL_CONVERSATION_ALLIANCE_OUTRO>>("boss_lord_stormsong_brother_pike");

    RegisterSpellScript(spell_lord_stormsong_energize);
    RegisterSpellScript(spell_lord_stormsong_waken_the_void_missile);
    RegisterSpellAndAuraScriptPair(spell_lord_stormsong_fixate, spell_lord_stormsong_fixate_aura);
    RegisterSpellAndAuraScriptPair(spell_lord_stormsong_ancient_mindbender, spell_lord_stormsong_ancient_mindbender_aura);
    RegisterSpellScript(spell_lord_stormsong_surrender_to_the_void);
    RegisterSpellScript(spell_lord_stormsong_disciple_of_the_vol_zith);
    RegisterSpellScript(spell_lord_stormsong_release_void);
    RegisterSpellScript(spell_lord_stormsong_release_void_missile);

    RegisterAreaTriggerAI(at_lord_stormsong_waken_the_void);

    RegisterAreaTriggerAI(at_lord_stormsong_intro);

    RegisterConversationAI(conversation_lord_stormsong_brother_pike_intro_outro);
    RegisterConversationAI(conversation_lord_stormsong_rexxar_intro);
    RegisterConversationAI(conversation_lord_stormsong_rexxar_outro);
}

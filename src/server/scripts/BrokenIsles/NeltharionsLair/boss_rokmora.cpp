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
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "PathGenerator.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "neltharions_lair.h"

enum RokmoraSpells
{
    // Intro Spells
    SPELL_JUMP_TO_GROUND_COSMETIC        = 184483,
    SPELL_BOSS_INTRO_CONVERSATION        = 209374,
    SPELL_BOSS_INTRO_EMERGE              = 209394,
    SPELL_UPDATE_INTERACTIONS            = 134730,
    SPELL_ULAROGG_COSMETIC               = 209390,

    // Combat
    SPELL_CHOKING_DUST_DAMAGE            = 192800,
    SPELL_CRYSTALLINE_GROUND             = 198024,
    SPELL_CRYSTALLINE_GROUND_AREATRIGGER = 216470,
    SPELL_CRYSTALLINE_GROUND_DAMAGE      = 198028,
    SPELL_CRYSTALLINE_GROUND_PERIODIC    = 215898,
    SPELL_CRYSTALLINE_GROUND_VISUAL      = 216488,
    // SPELL_CRYSTALLINE_GROUND_UNK      = 470381 unknown purpose
    SPELL_GAIN_ENERGY                    = 193245,
    SPELL_RAZOR_SHARDS                   = 188169,
    SPELL_RAZOR_SHARDS_VISUAL            = 188207,
    SPELL_RAZOR_SHARDS_VISUAL_2          = 197920,
    SPELL_RUPTURING_SKITTER              = 215929,
    SPELL_SHATTER                        = 188114,
    SPELL_SHATTER_KILL_SKITTERS          = 200247,

    SPELL_ROKMORA_COMBAT_CONVO_1         = 198122,  // Rok shatter!
    SPELL_ROKMORA_COMBAT_CONVO_2         = 198125,  // Rok stronger! (unused?)
    SPELL_ROKMORA_COMBAT_CONVO_3         = 198135,  // Tiny piddle, big puddle.
    SPELL_ROKMORA_COMBAT_CONVO_4         = 198136   // Nothing beat Rok!
};

enum RokmoraEvents
{
    EVENT_SHATTER = 1,
    EVENT_RAZOR_SHARDS,
    EVENT_CRYSTALLINE_GROUND,
    EVENT_CHECK_ENERGY,

    EVENT_ROKMORA_INTRO_MOVE
};

enum RokmoraTexts
{
    SAY_AGGRO                      = 0,
    SAY_CRYSTALLINE_GROUND_WARNING = 1,
    SAY_RAZOR_SHARDS_WARNING       = 2,
    SAY_DIED                       = 3
};

enum RokmoraConversation
{
    POINT_NAVAROGG_JUMP         = 0,
    POINT_NAVAROGG_INTRO        = 1,
    CONVO_ACTOR_NAVARROGG       = 52530,
    CONVO_ULAROGG_INTRO_LINE_03 = 3992,

    CONVO_ACTOR_ID_ULAROGG      = 0,
    CONVO_ACTOR_ID_NAVARROGG    = 1,

    PATH_ULAROGG                = 10530000,
    PATH_NAVARROGG              = 10070000,

    WAYPOINT_DESPAWN            = 7
};

enum RokmoraMisc
{
    NPC_NAVARROGG      = 100700,
    NPC_ULAROGG        = 105300,
    NPC_SKITTER        = 97720
};

constexpr Position NavarroggIntroPosition = { 2959.8716f, 1390.5312f, 53.52835f, 2.721162f };
constexpr Position NavarroggIntroPosition2 = { 2917.3196f, 1402.2882f, -2.405084f };
constexpr Position NavarroggJumpIntroPosition = { 2930.9895f, 1395.7848f, -2.641485f, 2.721162f };

// 91003 - Rokmora
struct boss_rokmora : public BossAI
{
    boss_rokmora(Creature* creature) : BossAI(creature, DATA_ROKMORA) { }

    void JustAppeared() override
    {
        if (instance->GetData(DATA_ROKMORA_INTRO_STATE) == DONE)
            me->SetImmuneToPC(false);
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _JustDied();
        Talk(SAY_DIED);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetEntry() == NPC_SKITTER)
        {
            uint32 spellId = RAND(SPELL_ROKMORA_COMBAT_CONVO_3, SPELL_ROKMORA_COMBAT_CONVO_4);
            DoCastSelf(spellId);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        summons.DespawnAll();
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        DoCastSelf(SPELL_GAIN_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100); // power is set to 0 in Creature::UpdateMaxPower

        events.ScheduleEvent(EVENT_RAZOR_SHARDS, 29100ms);
        events.ScheduleEvent(EVENT_CHECK_ENERGY, 500ms);

        if (IsHeroicOrHigher()) // Casted once
            events.ScheduleEvent(EVENT_CRYSTALLINE_GROUND, 3400ms);
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
                case EVENT_RAZOR_SHARDS:
                {
                    Talk(SAY_RAZOR_SHARDS_WARNING);
                    DoCastVictim(SPELL_RAZOR_SHARDS);
                    events.Repeat(29200ms);
                    break;
                }
                case EVENT_CRYSTALLINE_GROUND:
                {
                    Talk(SAY_CRYSTALLINE_GROUND_WARNING);
                    DoCastSelf(SPELL_CRYSTALLINE_GROUND);
                    break;
                }
                case EVENT_CHECK_ENERGY:
                {
                    if (me->GetPower(POWER_ENERGY) >= 100)
                    {
                        DoCastSelf(SPELL_ROKMORA_COMBAT_CONVO_1);
                        DoCastSelf(SPELL_SHATTER);
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

// 215898 - Crystalline Ground
class spell_rokmora_crystalline_ground_periodic : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CRYSTALLINE_GROUND_DAMAGE, SPELL_CRYSTALLINE_GROUND_VISUAL });
    }

    void HandleEffectPeriodic(AuraEffect const* aurEff) const
    {
        if (Unit* caster = GetCaster())
        {
            Unit* target = GetTarget();

            target->CastSpell(target, SPELL_CRYSTALLINE_GROUND_VISUAL, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);

            if (target->isMoving())
                caster->CastSpell(target, SPELL_CRYSTALLINE_GROUND_DAMAGE, CastSpellExtraArgsInit{
                    .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                    .TriggeringAura = aurEff
                });
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_rokmora_crystalline_ground_periodic::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 188114 - Shatter
class spell_rokmora_shatter : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CRYSTALLINE_GROUND_AREATRIGGER, SPELL_SHATTER_KILL_SKITTERS });
    }

    void HandleShatter() const
    {
        Unit* caster = GetCaster();
        CastSpellExtraArgs args;
        args.TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR;
        caster->CastSpell(caster, SPELL_SHATTER_KILL_SKITTERS, args);

        if (caster->GetMap()->IsHeroicOrHigher())
            caster->CastSpell(caster->GetPosition(), SPELL_CRYSTALLINE_GROUND_AREATRIGGER, args);

        caster->SetPower(POWER_ENERGY, 0);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_rokmora_shatter::HandleShatter);
    }
};

// 188169 - Razor Shards
class spell_rokmora_razor_shards : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_RAZOR_SHARDS_VISUAL, SPELL_RAZOR_SHARDS_VISUAL_2 });
    }

    Position GetRandomRazorShardPosition(Unit* caster) const
    {
        Position pos(*caster);
        float randomAngle = frand(float(M_PI) / -7.0f, float(M_PI) / 7.0f);
        float randomDist = frand(2.0f, 40.0f);

        float angleToOrigin = caster->GetAbsoluteAngle(_targetOrigin);
        caster->MovePosition(pos, randomDist, randomAngle - caster->GetOrientation() + angleToOrigin);
        return pos;
    }

    void OnPrecast() override
    {
        Unit* target = GetExplTargetUnit();
        _targetOrigin = target->GetPosition();
    }

    void HandleCast() const
    {
        Unit* caster = GetCaster();

        for (uint8 i = 0; i < 20; ++i)
        {
            caster->CastSpell(GetRandomRazorShardPosition(caster), SPELL_RAZOR_SHARDS_VISUAL, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringSpell = GetSpell()
            });
        }

        for (uint8 i = 0; i < 7; ++i)
            caster->CastSpell(GetRandomRazorShardPosition(caster), SPELL_RAZOR_SHARDS_VISUAL_2, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_rokmora_razor_shards::HandleCast);
    }

private:
    Position _targetOrigin;
};

// 192799 - Choking Dust
// ID - 4953
struct at_rokmora_choking_dust : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(unit, SPELL_CHOKING_DUST_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        unit->RemoveAurasDueToSpell(SPELL_CHOKING_DUST_DAMAGE);
    }
};

// 198024 - Crystalline Ground and 216470 - Crystalline Ground
// ID - 7415
struct at_rokmora_crystalline_ground : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->CastSpell(unit, SPELL_CRYSTALLINE_GROUND_PERIODIC, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        unit->RemoveAurasDueToSpell(SPELL_CRYSTALLINE_GROUND_PERIODIC);
    }
};

// Id - XXX
struct at_rokmora_intro : AreaTriggerAI
{
    at_rokmora_intro(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player || player->IsGameMaster())
            return;

        if (TempSummon* navarrogg = unit->SummonCreature(NPC_NAVARROGG, NavarroggIntroPosition))
            navarrogg->SetScriptStringId("RokmoraIntro");

        at->Remove();
    }
};

// 100700 - Navarrogg
struct npc_rokmora_navarrogg_intro : public ScriptedAI
{
    npc_rokmora_navarrogg_intro(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        if (me->HasStringId("RokmoraIntro"))
            TriggerRokmoraIntro();
    }

    void WaypointReached(uint32 waypointId, uint32 pathId) override
    {
        if (pathId == PATH_NAVARROGG && waypointId == WAYPOINT_DESPAWN)
            me->DespawnOrUnsummon(1s);
    }

    void TriggerRokmoraIntro()
    {
        Seconds delay = 1s;

        _scheduler.Schedule(delay, [this](TaskContext)
        {
            DoCastSelf(SPELL_JUMP_TO_GROUND_COSMETIC);
            me->GetMotionMaster()->MoveJump(POINT_NAVAROGG_JUMP, NavarroggJumpIntroPosition, 50.0f, 50.0f);
        });

        delay += 2s;

        _scheduler.Schedule(delay, [this](TaskContext)
        {
            me->RemoveAurasDueToSpell(SPELL_JUMP_TO_GROUND_COSMETIC);
        });

        delay += 1s;

        _scheduler.Schedule(delay, [this](TaskContext)
        {
            if (Creature* ularogg = me->FindNearestCreature(NPC_ULAROGG, 50.0f))
            {
                ularogg->InterruptSpell(CURRENT_CHANNELED_SPELL);
                ularogg->SetFacingTo(5.480333f);
            }

            InstanceScript* instance = me->GetInstanceScript();
            if (!instance)
                return;

            Creature* rokmora = instance->GetCreature(DATA_ROKMORA);
            if (!rokmora)
                return;

            rokmora->AI()->DoCastSelf(SPELL_BOSS_INTRO_EMERGE);

            me->GetMotionMaster()->MovePoint(POINT_NAVAROGG_INTRO, NavarroggIntroPosition2);
        });

        delay += 1s;

        _scheduler.Schedule(delay, [this](TaskContext)
        {
            if (Creature* ularogg = me->FindNearestCreature(NPC_ULAROGG, 50.0f))
                ularogg->CastSpell(ularogg->GetPosition(), SPELL_BOSS_INTRO_CONVERSATION);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 209374 - Boss 01 Intro Convo
// Id - 1885
class conversation_rokmora_intro : public ConversationAI
{
public:
    using ConversationAI::ConversationAI;

    void OnCreate(Unit* creator) override
    {
        Creature* navarrogg = creator->FindNearestCreatureWithOptions(50.0f, { .CreatureId = NPC_NAVARROGG, .StringId = "RokmoraIntro" });
        if (!navarrogg)
            return;

        conversation->AddActor(CONVO_ACTOR_NAVARROGG, CONVO_ACTOR_ID_NAVARROGG, navarrogg->GetGUID());
    }

    void OnStart() override
    {
        if (Milliseconds const* ularoggMoveStartTime = conversation->GetLineStartTime(DEFAULT_LOCALE, CONVO_ULAROGG_INTRO_LINE_03))
            _events.ScheduleEvent(EVENT_ROKMORA_INTRO_MOVE, *ularoggMoveStartTime + 3s);
    }

    void OnUpdate(uint32 diff) override
    {
        _events.Update(diff);

        switch (_events.ExecuteEvent())
        {
            case EVENT_ROKMORA_INTRO_MOVE:
            {
                Creature* ularogg = conversation->GetActorCreature(CONVO_ACTOR_ID_ULAROGG);
                Creature* navarrogg = conversation->GetActorCreature(CONVO_ACTOR_ID_NAVARROGG);
                if (!ularogg || !navarrogg)
                    break;

                ularogg->GetMotionMaster()->MovePath(PATH_ULAROGG, false);
                navarrogg->GetMotionMaster()->MovePath(PATH_NAVARROGG, false);
                break;
            }
            default:
                break;
        }
    }

private:
    EventMap _events;
};

// 209394 - Boss 01 Intro Emerge
class spell_rokmora_emerge : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_UPDATE_INTERACTIONS });
    }

    void HandleShatter() const
    {
        Unit* caster = GetCaster();
        InstanceScript* instance = caster->GetInstanceScript();
        if (!instance)
            return;

        caster->CastSpell(caster, SPELL_UPDATE_INTERACTIONS, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);

        instance->SetData(DATA_ROKMORA_INTRO_STATE, DONE);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_rokmora_emerge::HandleShatter);
    }
};

class spell_rokmora_emerge_aura : public AuraScript
{
    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        GetCaster()->AddUnitState(UNIT_STATE_ROOT);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        GetCaster()->ClearUnitState(UNIT_STATE_ROOT);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_rokmora_emerge_aura::OnApply, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_rokmora_emerge_aura::OnRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

// 134730 - Update Interactions
class spell_rokmora_update_interactions : public SpellScript
{
    void HandleScript(SpellEffIndex /*effIndex*/) const
    {
        Creature* caster = GetCaster()->ToCreature();
        if (!caster)
            return;

        caster->SetImmuneToPC(false);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_rokmora_update_interactions::HandleScript, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

void AddSC_boss_rokmora()
{
    RegisterNeltharionsLairCreatureAI(boss_rokmora);

    RegisterSpellScript(spell_rokmora_crystalline_ground_periodic);
    RegisterSpellScript(spell_rokmora_shatter);
    RegisterSpellScript(spell_rokmora_razor_shards);

    RegisterAreaTriggerAI(at_rokmora_choking_dust);
    RegisterAreaTriggerAI(at_rokmora_crystalline_ground);

    // Intro
    RegisterAreaTriggerAI(at_rokmora_intro);
    RegisterNeltharionsLairCreatureAI(npc_rokmora_navarrogg_intro);
    RegisterConversationAI(conversation_rokmora_intro);
    RegisterSpellAndAuraScriptPair(spell_rokmora_emerge, spell_rokmora_emerge_aura);
    RegisterSpellScript(spell_rokmora_update_interactions);
}

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

#include "grim_batol.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "Spell.h"
#include "Map.h"

enum Spells
{
    // Erudax
    SPELL_BINDING_SHADOWS                       = 79466,
    SPELL_SHADOW_GALE_TRIGGER                   = 75656,
    SPELL_SHADOW_GALE                           = 75664,
    SPELL_SUMMON_FACELESS_CORRUPTOR             = 75704,
    SPELL_SHIELD_OF_NIGHTMARES                  = 75809,

    // Shadow Gale Controller
    SPELL_SUMMON_SHADOW_GALE_STALKER            = 75655,

    // Shadow Gale Stalker
    SPELL_SHADOW_GALE_TRIGGER_RUN_SPEED_TRIGGER = 75675,

    // Faceless Corruptor
    SPELL_TWILIGHT_CORRUPTION                   = 75520,
    SPELL_UMBRAL_MENDING                        = 75763,
    SPELL_SIPHON_ESSENCE                        = 75755,

    // Alexstrasza's Egg
    SPELL_SUMMON_TWILIGHT_EGG                   = 91056,
    SPELL_SUMMON_TWILIGHT_HATCHLING             = 91058
};

#define SPELL_ENFEEBLING_BLOW RAID_MODE<uint32>(75789, 91091)

enum Texts
{
    SAY_AGGRO                           = 0,
    SAY_ANNOUNCE_SHADOW_GALE            = 1,
    SAY_SHADOW_GALE                     = 2,
    SAY_FACELESS_CORRUPTORS             = 3,
    SAY_ANNOUNCE_GUARDIANS              = 4,
    SAY_ANNOUNCE_SHIELD_OF_NIGHTMARES   = 5,
    SAY_SLAY                            = 6,
    SAY_DEATH                           = 7
};

enum Events
{
    // Erudax
    EVENT_BINDING_SHADOWS = 1,
    EVENT_ENFEEBLING_BLOW,
    EVENT_SHADOW_GALE,
    EVENT_CAST_SHADOW_GALE,
    EVENT_SUMMON_FACELESS_CORRUPTOR,
    EVENT_SHIELD_OF_NIGHTMARES,

    // Faceless Corruptor
    EVENT_SEND_ENCOUNTER_FRAME,
    EVENT_TWILIGHT_CORRUPTION,
    EVENT_UMBRAL_MENDING,
    EVENT_ATTACK_PLAYER,
    EVENT_SIPHON_ESSENCE
};

enum Actions
{
    ACTION_FINISH_CORRUPTION    = 0,
    ACTION_DESPAWN              = 1,
    ACTION_FAIL_ACHIEVEMENT     = 0
};

enum Data
{
    DATA_ACHIEVEMT_ENLIGIBLE = 1
};

Position const facelessCorruptorPositions1[] =
{
    { -656.2604f, -833.0052f, 234.1771f },
    { -701.7274f, -833.2674f, 232.4126f },
    { -729.4792f, -865.7899f, 232.5132f },
};

Position const facelessCorruptorPositions2[] =
{
    { -660.3993f, -824.5052f, 233.6518f },
    { -699.3420f, -818.5434f, 232.4729f },
    { -728.7292f, -791.1129f, 232.4201f }
};

static constexpr uint32 const CyclicPathPoints = 10;
Position const TwilightHatchingCyclicPath[CyclicPathPoints] =
{
    { 0.f,          0.f,            0.f         },
    { -763.168f,    -826.411f,      253.845f    },
    { -767.03644f,  -845.07465f,    259.70566f  },
    { -742.458f,    -862.333f,      248.956f    },
    { -714.226f,    -853.693f,      251.872f    },
    { -706.016f,    -835.816f,      254.206f    },
    { -705.422f,    -815.714f,      251.15f     },
    { -718.08f,     -792.307f,      249.345f    },
    { -738.84894f,  -792.05554f,    259.70566f  },
    { -763.168f,    -826.411f,      253.845f    }
};

enum Points
{
    POINT_PATH_1,
    POINT_PATH_2,
    POINT_PATH_3
};

enum ModelIds
{
    MODEL_ID_INVISIBLE = 11686
};

struct boss_erudax : public BossAI
{
    boss_erudax(Creature* creature) : BossAI(creature, DATA_ERUDAX), _achievementEnligible(true) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        events.ScheduleEvent(EVENT_BINDING_SHADOWS, 10s + 500ms);
        events.ScheduleEvent(EVENT_ENFEEBLING_BLOW, 19s);
        events.ScheduleEvent(EVENT_SHADOW_GALE, 26s);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->IsPlayer())
            Talk(SAY_SLAY);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        DespawnFacelessCorruptors();
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        DespawnFacelessCorruptors();
        summons.DespawnAll();
    }


    void DoAction(int32 action) override
    {
        if (action == ACTION_FAIL_ACHIEVEMENT)
            _achievementEnligible = false;
    }

    void JustSummoned(Creature* summon) override
    {
        summons.RemoveNotExisting(); // keeping the summon container clean
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
            case NPC_SHADOW_GALE_STALKER:
                _shadowGaleStalkerGUID = summon->GetGUID();
                events.ScheduleEvent(EVENT_CAST_SHADOW_GALE, 1ms); // Cast the Shadow gale on the next update tick so update_object had a chance to spawn in the trigger clientside
                break;
            case NPC_TWILIGHT_HATCHLING:
                summon->GetMotionMaster()->MoveCyclicPath(TwilightHatchingCyclicPath, CyclicPathPoints, false, true, 14.f);
                break;
            default:
                break;
        }
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_ACHIEVEMT_ENLIGIBLE)
            return _achievementEnligible;

        return 0;
    }

    void OnSpellCastFinished(SpellInfo const* spell, SpellFinishReason reason) override
    {
        if (spell->Id == SPELL_ENFEEBLING_BLOW && reason == SPELL_FINISHED_SUCCESSFUL_CAST)
            events.CancelEvent(EVENT_ENFEEBLING_BLOW); // Enfeebling blow has been casted successfully so no need to repeat it for this cycle
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
                case EVENT_BINDING_SHADOWS:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.f, true))
                        DoCast(target, SPELL_BINDING_SHADOWS);
                    events.Repeat(23s);
                    break;
                case EVENT_ENFEEBLING_BLOW:
                    events.Repeat(10s); // repeat the blow after 10 seconds if the cast has not been successful
                    DoCastVictim(SPELL_ENFEEBLING_BLOW);
                    break;
                case EVENT_SHADOW_GALE:
                    DoCastSelf(SPELL_SHADOW_GALE_TRIGGER);
                    events.ScheduleEvent(EVENT_SUMMON_FACELESS_CORRUPTOR, 18s);
                    events.RescheduleEvent(EVENT_BINDING_SHADOWS, 20s, 22s);
                    events.RescheduleEvent(EVENT_ENFEEBLING_BLOW, 21s);
                    events.Repeat(55s);
                    break;
                case EVENT_CAST_SHADOW_GALE:
                    Talk(SAY_SHADOW_GALE);
                    Talk(SAY_ANNOUNCE_SHADOW_GALE);
                    if (Creature* stalker = ObjectAccessor::GetCreature(*me, _shadowGaleStalkerGUID))
                    {
                        stalker->CastSpell(stalker, SPELL_SHADOW_GALE_TRIGGER_RUN_SPEED_TRIGGER);
                        DoCast(stalker, SPELL_SHADOW_GALE);
                    }
                    break;
                case EVENT_SUMMON_FACELESS_CORRUPTOR:
                    Talk(SAY_FACELESS_CORRUPTORS);
                    Talk(SAY_ANNOUNCE_GUARDIANS);
                    DoCastSelf(SPELL_SUMMON_FACELESS_CORRUPTOR);
                    if (IsHeroic())
                        events.ScheduleEvent(EVENT_SHIELD_OF_NIGHTMARES, 19s);
                    break;
                case EVENT_SHIELD_OF_NIGHTMARES:
                    for (ObjectGuid guid : summons)
                    {
                        if (guid.GetEntry() != NPC_FACELESS_CORRUPTOR_1 && guid.GetEntry() != NPC_FACELESS_CORRUPTOR_2)
                            continue;

                        if (Creature* corruptor = ObjectAccessor::GetCreature(*me, guid))
                        {
                            if (corruptor->IsAlive())
                            {
                                Talk(SAY_ANNOUNCE_SHIELD_OF_NIGHTMARES, corruptor);
                                DoCastAOE(SPELL_SHIELD_OF_NIGHTMARES);
                                break;
                            }
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        DoMeleeAttackIfReady();
    }
private:
    void DespawnFacelessCorruptors()
    {
        EntryCheckPredicate pred1(NPC_FACELESS_CORRUPTOR_1);
        EntryCheckPredicate pred2(NPC_FACELESS_CORRUPTOR_2);
        summons.DoAction(ACTION_DESPAWN, pred1);
        summons.DoAction(ACTION_DESPAWN, pred2);
    }

    bool _achievementEnligible;
    ObjectGuid _shadowGaleStalkerGUID;
};

struct npc_erudax_faceless_corruptor : public ScriptedAI
{
    npc_erudax_faceless_corruptor(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript())
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetCorpseDelay(5);
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        me->MakeInterruptable(false);
        if (me->GetEntry() == NPC_FACELESS_CORRUPTOR_1)
            me->GetMotionMaster()->MovePoint(POINT_PATH_1, facelessCorruptorPositions1[0], true);
        else
            me->GetMotionMaster()->MovePoint(POINT_PATH_1, facelessCorruptorPositions2[0], true);
        _events.ScheduleEvent(EVENT_SEND_ENCOUNTER_FRAME, 7s + 500ms);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        me->DespawnOrUnsummon();
    }

    void MovementInform(uint32 type, uint32 point) override
    {
        if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
            return;

        switch (point)
        {
            case POINT_PATH_1:
                if (me->GetEntry() == NPC_FACELESS_CORRUPTOR_1)
                    me->GetMotionMaster()->MovePoint(POINT_PATH_2, facelessCorruptorPositions1[1]);
                else
                    me->GetMotionMaster()->MovePoint(POINT_PATH_2, facelessCorruptorPositions2[1]);
                break;
            case POINT_PATH_2:
                if (me->GetEntry() == NPC_FACELESS_CORRUPTOR_1)
                    me->GetMotionMaster()->MovePoint(POINT_PATH_3, facelessCorruptorPositions1[2]);
                else
                    me->GetMotionMaster()->MovePoint(POINT_PATH_3, facelessCorruptorPositions2[2]);
                break;
            case POINT_PATH_3:
                _events.ScheduleEvent(EVENT_TWILIGHT_CORRUPTION, 1s);
                break;
            default:
                break;
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_FINISH_CORRUPTION:
                _events.ScheduleEvent(EVENT_UMBRAL_MENDING, 400ms);
                break;
            case ACTION_DESPAWN:
                _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->DespawnOrUnsummon();
                break;
            default:
                break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SEND_ENCOUNTER_FRAME:
                    _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
                    break;
                case EVENT_TWILIGHT_CORRUPTION:
                    if (Creature* erudax = _instance->GetCreature(DATA_ERUDAX))
                        erudax->AI()->DoAction(ACTION_FAIL_ACHIEVEMENT);
                    DoCastAOE(SPELL_TWILIGHT_CORRUPTION);
                    break;
                case EVENT_UMBRAL_MENDING:
                    me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, false);
                    me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_INTERRUPT_CAST, false);
                    DoCastAOE(SPELL_UMBRAL_MENDING);
                    _events.ScheduleEvent(EVENT_ATTACK_PLAYER, 3s);
                    _events.ScheduleEvent(EVENT_SIPHON_ESSENCE, 55s);
                    break;
                case EVENT_ATTACK_PLAYER:
                    me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, true);
                    me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_INTERRUPT_CAST, true);
                    me->SetReactState(REACT_AGGRESSIVE);
                    if (Player* player = me->SelectNearestPlayer(100.0f))
                        me->EngageWithTarget(player);
                    break;
                case EVENT_SIPHON_ESSENCE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                        DoCast(target, SPELL_SIPHON_ESSENCE);
                    _events.Repeat(11s);
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

class spell_erudax_shadow_gale_trigger : public SpellScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_SHADOW_GALE_STALKER });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SUMMON_SHADOW_GALE_STALKER, true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_erudax_shadow_gale_trigger::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_erudax_shadow_gale : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (Unit* channelTarget = ObjectAccessor::GetUnit(*caster, caster->GetChannelObjectGuid()))
        {
            targets.remove_if([channelTarget](WorldObject const* target)
            {
                return target->GetExactDist2d(channelTarget) <= 5.f;
            });
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_erudax_shadow_gale::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect.Register(&spell_erudax_shadow_gale::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_erudax_shadow_gale_aura : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if([this](WorldObject const* target)
        {
            return target->GetExactDist2d(GetCaster()) <= 5.f;
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_erudax_shadow_gale_aura::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_erudax_twilight_corruption : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster(), true));

        if (targets.size() > 1)
            targets.resize(1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_erudax_twilight_corruption::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

class spell_erudax_twilight_corruption_AuraScript : public AuraScript
{
    void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        if (Unit* target = GetOwner()->ToUnit())
        {
            if (uint32 spellId = sSpellMgr->GetSpellIdForDifficulty(GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, target))
            {
                if (SpellInfo const* spell = sSpellMgr->GetSpellInfo(spellId))
                {
                    int32 damage = CalculatePct(target->GetMaxHealth(), spell->Effects[EFFECT_0].BasePoints);
                    target->CastSpell(target, spellId, CastSpellExtraArgs(true).AddSpellBP0(damage));
                }
            }
        }
    }

    void OnAuraRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode().HasFlag(AuraRemoveFlags::ByDeath))
        {
            if (Unit* caster = GetCaster())
                if (Creature* creature = caster->ToCreature())
                    if (creature->IsAIEnabled)
                        creature->AI()->DoAction(ACTION_FINISH_CORRUPTION);

            if (Unit* owner = GetOwner()->ToUnit())
            {
                owner->CastSpell(owner, SPELL_SUMMON_TWILIGHT_EGG, true);
                owner->CastSpell(owner, SPELL_SUMMON_TWILIGHT_HATCHLING, true);
                owner->SetDisplayId(MODEL_ID_INVISIBLE);
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_erudax_twilight_corruption_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        OnEffectRemove.Register(&spell_erudax_twilight_corruption_AuraScript::OnAuraRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

class achievement_dont_need_to_break_eggs : public AchievementCriteriaScript
{
    public:
        achievement_dont_need_to_break_eggs() : AchievementCriteriaScript("achievement_dont_need_to_break_eggs") { }

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (!target)
                return false;

            if (target->GetMap()->IsHeroic())
                return target->GetAI()->GetData(DATA_ACHIEVEMT_ENLIGIBLE);

            return false;
        }
};

void AddSC_boss_erudax()
{
    RegisterGrimBatolCreatureAI(boss_erudax);
    RegisterGrimBatolCreatureAI(npc_erudax_faceless_corruptor);
    RegisterSpellScript(spell_erudax_shadow_gale_trigger);
    RegisterSpellScript(spell_erudax_shadow_gale);
    RegisterSpellScript(spell_erudax_shadow_gale_aura);
    RegisterSpellAndAuraScriptPair(spell_erudax_twilight_corruption, spell_erudax_twilight_corruption_AuraScript);
    new achievement_dont_need_to_break_eggs();
}

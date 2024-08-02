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
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SharedDefines.h"
#include "TemporarySummon.h"
#include "kings_rest.h"

enum GoldenSerpentSpells
{
    SPELL_SPIT_GOLD                     = 265773,
    SPELL_SERPENTINE_GUST               = 265781,
    SPELL_TAIL_TRASH                    = 265910,
    SPELL_LUCRES_CALL                   = 265923,
    SPELL_MOLTEN_GOLD_DAMAGE            = 265914,
    SPELL_MOLTEN_GOLD_AURA              = 265915,
    SPELL_LUSTER                        = 265991,
    SPELL_BREAK_PLAYER_TARGETTING       = 140562,
    SPELL_GOLDEN_SERPENT_EMERGE_STATE   = 271598
};

enum GoldenSerpentEvents
{
    EVENT_SPIT_GOLD         = 1,
    EVENT_SERPENTINE_GUST,
    EVENT_TAIL_TRASH,
    EVENT_LUCRES_CALL
};

enum GoldenSerpentTexts
{
    SAY_ANNOUNCE_ABSORB_ANIMATED_GOLD   = 0
};

enum GoldenSerpentActions
{
    ACTION_ANNOUNCE_ABSORB_ANIMATED_GOLD    = 1
};

enum GoldenSerpentNPCs
{
    NPC_ANIMATED_GOLD   = 135406
};

enum GoldenSerpentMisc
{
    DISPLAY_INVISIBLE   = 11686
};

enum GoldenSerpentPaths
{
    PATH_GOLDEN_SERPENT_SUBMERGE     = 13532200,
    PATH_GOLDEN_SERPENT_FLYING       = 13532201,
    PATH_GOLDEN_SERPENT_LANDING      = 13532202,
};

constexpr Position GoldenSerpentRespawnPos = { -1058.8403f, 2615.1667f, 810.1519f, 5.113396f };

// 135322 - The Golden Serpent
struct boss_the_golden_serpent : public BossAI
{
    boss_the_golden_serpent(Creature* creature) : BossAI(creature, DATA_GOLDEN_SERPENT), _announcedLuster(false) { }

    void JustAppeared() override
    {
        if (instance->GetBossState(DATA_GOLDEN_SERPENT) == NOT_STARTED)
        {
            me->SetDisableGravity(true, true);
            me->SetAnimTier(AnimTier::Fly, true);
            me->SetPlayHoverAnim(true);
            me->SetFaction(FACTION_FRIENDLY);
            me->SetUnitFlag(UnitFlags(UNIT_FLAG_UNINTERACTIBLE));
            DoCast(SPELL_GOLDEN_SERPENT_EMERGE_STATE);
            me->GetMotionMaster()->MovePath(PATH_GOLDEN_SERPENT_SUBMERGE, false);
        }
    }

    void InitializeAI() override
    {
        if (instance->GetBossState(DATA_GOLDEN_SERPENT) != NOT_STARTED)
            me->Relocate(GoldenSerpentRespawnPos);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        summons.DespawnAll();
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void Reset() override
    {
        _announcedLuster = false;
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        events.ScheduleEvent(EVENT_SPIT_GOLD, 9s);
        events.ScheduleEvent(EVENT_SERPENTINE_GUST, 12s + 500ms);
        events.ScheduleEvent(EVENT_TAIL_TRASH, 15s + 500ms);
        events.ScheduleEvent(EVENT_LUCRES_CALL, 40s);
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId == PATH_GOLDEN_SERPENT_SUBMERGE)
        {
            me->RemoveAurasDueToSpell(SPELL_GOLDEN_SERPENT_EMERGE_STATE);
            me->GetMotionMaster()->MovePath(PATH_GOLDEN_SERPENT_FLYING, false);
        }
        else if (pathId == PATH_GOLDEN_SERPENT_FLYING)
            me->GetMotionMaster()->MovePath(PATH_GOLDEN_SERPENT_LANDING, false);
        else if (pathId == PATH_GOLDEN_SERPENT_LANDING)
        {
            me->SetAnimTier(AnimTier::Ground, true);
            me->SetPlayHoverAnim(false);
            me->SetFaction(FACTION_MONSTER_2);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_UNINTERACTIBLE));
            me->SetDisableGravity(false);
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_ANNOUNCE_ABSORB_ANIMATED_GOLD)
        {
            if (!_announcedLuster)
            {
                Talk(SAY_ANNOUNCE_ABSORB_ANIMATED_GOLD);
                _announcedLuster = true;
            }
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

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SPIT_GOLD:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 300.0f, true))
                        DoCast(target, SPELL_SPIT_GOLD);
                    events.ScheduleEvent(EVENT_SPIT_GOLD, 11s);
                    break;
                case EVENT_SERPENTINE_GUST:
                    DoCastSelf(SPELL_SERPENTINE_GUST);
                    events.ScheduleEvent(EVENT_SERPENTINE_GUST, 21s + 500ms);
                    break;
                case EVENT_TAIL_TRASH:
                    DoCastVictim(SPELL_TAIL_TRASH);
                    events.ScheduleEvent(EVENT_TAIL_TRASH, 17s);
                    break;
                case EVENT_LUCRES_CALL:
                    DoCastSelf(SPELL_LUCRES_CALL);
                    _announcedLuster = false;
                    events.ScheduleEvent(EVENT_LUCRES_CALL, 41s + 500ms);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
private:
    bool _announcedLuster;
};

// 135406 - Animated Gold
struct npc_animated_gold : public ScriptedAI
{
    npc_animated_gold(Creature* creature) : ScriptedAI(creature), _isMoltenGoldCast(false) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_BREAK_PLAYER_TARGETTING);
        me->SetReactState(REACT_PASSIVE);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_LUCRES_CALL)
        {
            _scheduler.Schedule(3s, [this](TaskContext)
            {
                if (!me->HasAura(SPELL_MOLTEN_GOLD_AURA))
                {
                    Creature* goldenSerpent = me->GetInstanceScript()->GetCreature(DATA_GOLDEN_SERPENT);
                    if (!goldenSerpent)
                        return;

                    me->GetMotionMaster()->Clear();
                    me->SetWalk(true);
                    me->GetMotionMaster()->MoveFollow(goldenSerpent, 2.0f, {}, {}, true);
                    _isMoltenGoldCast = false;
                }
            });
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->GetHealth() <= damage)
        {
            damage = me->GetHealth() - 1;

            if (!_isMoltenGoldCast)
            {
                me->CastSpell(nullptr, SPELL_MOLTEN_GOLD_AURA, false);
                me->GetMotionMaster()->Clear();
                me->StopMoving();
                _isMoltenGoldCast = true;
            }
        }
    }

    void MovementInform(uint32 type, uint32 /*pointId*/) override
    {
        if (type == FOLLOW_MOTION_TYPE)
        {
            Creature* goldenSerpent = me->GetInstanceScript()->GetCreature(DATA_GOLDEN_SERPENT);
            if (!goldenSerpent)
                return;

            if (!goldenSerpent->IsAIEnabled())
                return;

            me->DespawnOrUnsummon(4s);
            me->GetMotionMaster()->Clear();
            me->StopMoving();
            me->CastSpell(nullptr, SPELL_LUSTER, true);
            goldenSerpent->AI()->DoAction(ACTION_ANNOUNCE_ABSORB_ANIMATED_GOLD);
            me->SetDisplayId(DISPLAY_INVISIBLE);
            me->SetUnitFlag(UnitFlags(UNIT_FLAG_UNINTERACTIBLE));
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
    bool _isMoltenGoldCast;
};

// 17570 - Molten Gold - Areatrigger
struct at_kings_rest_molten_gold : AreaTriggerAI
{
    at_kings_rest_molten_gold(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->CastSpell(nullptr, SPELL_MOLTEN_GOLD_DAMAGE , false);
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_MOLTEN_GOLD_DAMAGE);
    }
};

// 265773 - Spit Gold
class spell_kings_rest_spit_gold : public AuraScript
{
    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEATH && GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        if (Unit* caster = GetCaster())
            caster->SummonCreature(NPC_ANIMATED_GOLD, GetTarget()->GetPosition());
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_kings_rest_spit_gold::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 265915 - Molten Gold
class spell_kings_rest_molten_gold : public AuraScript
{
    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->SetUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE));
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE));
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectRemoveFn(spell_kings_rest_molten_gold::OnApply, EFFECT_1, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_kings_rest_molten_gold::OnRemove, EFFECT_1, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_golden_serpent()
{
    // Creature
    RegisterKingsRestCreatureAI(boss_the_golden_serpent);
    RegisterKingsRestCreatureAI(npc_animated_gold);

    // Areatrigger
    RegisterAreaTriggerAI(at_kings_rest_molten_gold);

    // Spells
    RegisterSpellScript(spell_kings_rest_spit_gold);
    RegisterSpellScript(spell_kings_rest_molten_gold);
}

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
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "zulaman.h"

enum Texts
{
    // Jan'alai
    SAY_INTRO                   = 0,
    SAY_AGGRO                   = 1,
    SAY_EMOTE_FRENZY            = 2,
    SAY_FIRE_BOMB               = 3,
    SAY_HATCH_ALL_EGGS          = 4,
    SAY_SUMMON_AMANI_HATCHER    = 5,
    SAY_SLAY                    = 6,
    SAY_DEATH                   = 7
};

enum Spells
{
    // Jan'alai
    SPELL_FLAME_BREATH                  = 43140,
    SPELL_FLAME_BREATH_AREA_EFFECT      = 97497,
    SPELL_FRENZY                        = 44779,
    SPELL_TELEPORT_TO_CENTER            = 43098,
    SPELL_SUMMON_ALL_PLAYERS            = 43096,
    SPELL_FIRE_BOMB                     = 42621,
    SPELL_FIRE_BOMB_SUMMON_5YD          = 42622,
    SPELL_FIRE_BOMB_SUMMON_10YD         = 42623,
    SPELL_FIRE_BOMB_SUMMON_15YD         = 42624,
    SPELL_FIRE_BOMB_SUMMON_20YD         = 42625,
    SPELL_FIRE_BOMB_SUMMON_25YD         = 42626,
    SPELL_FIRE_BOMB_SUMMON_30YD         = 42627,
    SPELL_FIRE_BOMB_DUMMY_MISSILE       = 42628,
    SPELL_HATCH_ALL_EGGS                = 43144,
    SPELL_SUMMON_AMANISHI_HATCHER_1     = 43962,
    SPELL_SUMMON_AMANISHI_HATCHER_2     = 45340,

    // Fire Bomb (Zul'Aman)
    SPELL_FIRE_BOMB_VISUAL              = 42629,
    SPELL_FIRE_BOMB_AOE_DUMMY           = 42631,
    SPELL_FIRE_BOMB_DAMAGE              = 42630,

    // Amani'shi Hatcher
    SPELL_HATCH_EGGS                    = 42471,

    // Dragonhawk Egg
    SPELL_SUMMON_DRAGONHAWK_HATCHLING   = 42493,

    // Amani Dragonhawk Hatchling
    SPELL_FLAME_BUFFET                  = 43299,

    // World Trigger (Not Immune PC)
    SPELL_FIRE_WALL                     = 43113
};

enum Events
{
    // Jan'alai
    EVENT_FLAME_BREATH = 1,
    EVENT_TELEPORT_TO_CENTER,
    EVENT_SUMMON_ALL_PLAYERS,
    EVENT_FIRE_BOMB,
    EVENT_DETONATE_FIRE_BOMBS,
    EVENT_SUMMON_AMANISHI_HATCHER,

    // Amani'shi Hatcher
    EVENT_MOVE_TO_EGGS,
    EVENT_HATCH_EGGS,

    // Amani Dragonhawk Hatchling
    EVENT_FLAME_BUFFET
};

enum MovePoints
{
    // Amani'shi Hatcher
    POINT_DRAGONHAWK_EGGS_1 = 1,
    POINT_DRAGONHAWK_EGGS_2
};

enum Misc
{
    SUMMON_GROUP_DRAGONHAWK_EGGS = 0
};

static constexpr uint8 MaxAmanishPathPoints = 2;
std::array<Position const, MaxAmanishPathPoints> AmanishiHatcherPath1 =
{
    Position(-55.058918f, 1147.5951f, 18.705215f),
    Position(-35.54627f,  1104.8754f, 18.712082f)
};

std::array<Position const, MaxAmanishPathPoints> AmanishiHatcherPath2 =
{
    Position(-55.04731f,  1153.5928f, 18.705194f),
    Position(-34.785084f, 1192.8384f, 18.71136f)
};

Position const FireWallReferencePos = { -34.719f, 1149.689f };

struct boss_janalai : public BossAI
{
    boss_janalai(Creature* creature) : BossAI(creature, DATA_JANALAI), _frenzied(false), _hatchedAllEggs(false) { }

    void JustAppeared() override
    {
        me->SummonCreatureGroup(SUMMON_GROUP_DRAGONHAWK_EGGS);
    }

    void JustEngagedWith(Unit* who) override
    {
        _JustEngagedWith(who);
        Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        events.ScheduleEvent(EVENT_FLAME_BREATH, 7s);
        events.ScheduleEvent(EVENT_SUMMON_AMANISHI_HATCHER, 12s);
        events.ScheduleEvent(EVENT_TELEPORT_TO_CENTER, 55s);
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
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->IsPlayer())
            Talk(SAY_SLAY);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HasUnitState(UNIT_STATE_CASTING) || damage >= me->GetHealth())
            return;

        if (!_frenzied && me->HealthBelowPctDamaged(20, damage))
        {
            _frenzied = true;
            DoCastSelf(SPELL_FRENZY, true);
            Talk(SAY_EMOTE_FRENZY);
        }

        if (!_hatchedAllEggs && me->HealthBelowPctDamaged(35, damage))
        {
            _hatchedAllEggs = true;
            DoCastAOE(SPELL_HATCH_ALL_EGGS, true);
            Talk(SAY_HATCH_ALL_EGGS);
        }
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
            case NPC_FIRE_BOMB_ZULAMAN:
                DoCast(summon, SPELL_FIRE_BOMB_DUMMY_MISSILE);
                break;
            case NPC_AMANISHI_HATCHER_1:
            case NPC_AMANISHI_HATCHER_2:
            case NPC_AMANI_DRAGONHAWK_HATCHLING:
                summon->SetCorpseDelay(4); // 4s ToDo: validate
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
                case EVENT_FLAME_BREATH:
                    // Flame Breath targets non-tank targets only.
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.f, true, false))
                    {
                        me->SetFacingToObject(target);
                        DoCast(target, SPELL_FLAME_BREATH);
                    }
                    events.Repeat(8s);
                    break;
                case EVENT_TELEPORT_TO_CENTER:
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    Talk(SAY_FIRE_BOMB);
                    DoCastSelf(SPELL_TELEPORT_TO_CENTER);
                    events.ScheduleEvent(EVENT_SUMMON_ALL_PLAYERS, 1s);
                    events.ScheduleEvent(EVENT_FIRE_BOMB, 2s + 500ms);
                    events.RescheduleEvent(EVENT_FLAME_BREATH, 16s);
                    events.Repeat(30s);
                    break;
                case EVENT_SUMMON_ALL_PLAYERS:
                    DoCastAOE(SPELL_SUMMON_ALL_PLAYERS);
                    break;
                case EVENT_FIRE_BOMB:
                {
                    DoCastSelf(SPELL_FIRE_BOMB);
                    me->SetReactState(REACT_AGGRESSIVE);
                    events.ScheduleEvent(EVENT_DETONATE_FIRE_BOMBS, 10s);

                    std::vector<Creature*> triggerList;
                    me->GetCreatureListWithEntryInGrid(triggerList, NPC_WORLD_TRIGGER_NOT_IMMUNE_PC, 30.f);
                    for (Creature* trigger : triggerList)
                        if (FireWallReferencePos.GetExactDist2d(trigger) > 10.f)
                            trigger->CastSpell(trigger, SPELL_FIRE_WALL);
                    break;
                }
                case EVENT_DETONATE_FIRE_BOMBS:
                    for (SummonList::iterator itr = summons.begin(); itr != summons.end();)
                    {
                        if (itr->GetEntry() != NPC_FIRE_BOMB_ZULAMAN)
                        {
                            ++itr;
                            continue;
                        }

                        if (Creature* bomb = ObjectAccessor::GetCreature(*me, *itr))
                        {
                            bomb->CastSpell(bomb, SPELL_FIRE_BOMB_AOE_DUMMY);
                            bomb->CastSpell(bomb, SPELL_FIRE_BOMB_DAMAGE);
                            bomb->RemoveAllAuras();
                            bomb->DespawnOrUnsummon(4s);
                            itr = summons.erase(itr);
                        }
                        else
                            ++itr;
                    }
                    break;
                case EVENT_SUMMON_AMANISHI_HATCHER:
                    if (!_hatchedAllEggs && (!summons.HasEntry(NPC_AMANISHI_HATCHER_1) || !summons.HasEntry(NPC_AMANISHI_HATCHER_2)))
                    {
                        Talk(SAY_SUMMON_AMANI_HATCHER);
                        DoCastAOE(SPELL_SUMMON_AMANISHI_HATCHER_1);
                        DoCastAOE(SPELL_SUMMON_AMANISHI_HATCHER_2);
                        events.Repeat(60s);
                    }
                    else if (!_hatchedAllEggs)
                        events.Repeat(30s);
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
    bool _frenzied;
    bool _hatchedAllEggs;
};

struct npc_janalai_amanishi_hatcher : public PassiveAI
{
    npc_janalai_amanishi_hatcher(Creature* creature) : PassiveAI(creature) { }

    void JustAppeared() override
    {
        if (me->GetEntry() == NPC_AMANISHI_HATCHER_1)
            me->GetMotionMaster()->MovePoint(POINT_DRAGONHAWK_EGGS_1, AmanishiHatcherPath1[0]);
        else
            me->GetMotionMaster()->MovePoint(POINT_DRAGONHAWK_EGGS_1, AmanishiHatcherPath2[0]);
    }

    void MovementInform(uint32 motionType, uint32 pointId) override
    {
        if (motionType != POINT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_DRAGONHAWK_EGGS_1:
                _events.ScheduleEvent(EVENT_MOVE_TO_EGGS, 1s + 500ms);
                break;
            case POINT_DRAGONHAWK_EGGS_2:
                _events.ScheduleEvent(EVENT_HATCH_EGGS, 1ms);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MOVE_TO_EGGS:
                {
                    Creature* egg = me->FindNearestCreature(NPC_DRAGONHAWK_EGG, 100.f);
                    if (me->GetEntry() == NPC_AMANISHI_HATCHER_1)
                    {
                        if (!egg || (egg && egg->GetExactDist2d(AmanishiHatcherPath1[1]) < egg->GetExactDist2d(AmanishiHatcherPath2[1])))
                            me->GetMotionMaster()->MovePoint(POINT_DRAGONHAWK_EGGS_2, AmanishiHatcherPath1[1]);
                        else if (egg)
                            me->GetMotionMaster()->MovePoint(POINT_DRAGONHAWK_EGGS_2, AmanishiHatcherPath2[1]);
                    }
                    else
                    {
                        if (!egg || (egg && egg->GetExactDist2d(AmanishiHatcherPath2[1]) < egg->GetExactDist2d(AmanishiHatcherPath1[1])))
                            me->GetMotionMaster()->MovePoint(POINT_DRAGONHAWK_EGGS_2, AmanishiHatcherPath2[1]);
                        else if (egg)
                            me->GetMotionMaster()->MovePoint(POINT_DRAGONHAWK_EGGS_2, AmanishiHatcherPath1[1]);
                    }
                    break;
                }
                case EVENT_HATCH_EGGS:
                    DoCastAOE(SPELL_HATCH_EGGS);
                    _events.Repeat(5s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

struct npc_janalai_amani_dragonhawk_hatchling : public ScriptedAI
{
    npc_janalai_amani_dragonhawk_hatchling(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        DoZoneInCombat();
        _events.ScheduleEvent(EVENT_FLAME_BUFFET, 6s);
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
                case EVENT_FLAME_BUFFET:
                    DoCastVictim(SPELL_FLAME_BUFFET);
                    _events.Repeat(6s);
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

class spell_janalai_flame_breath : public SpellScript
{
    void ModifyDestination(SpellDestination& dest)
    {
        float x = 0.f, y = 0.f, z = 0.f, o = 0.f;
        GetCaster()->GetPosition(x, y, z, o);
        x += std::cos(o) * 30.f;
        y += std::sin(o) * 30.f;
        dest.Relocate({ x, y, z });

        // We have our destination now, no need to keep our object target anymore.
        GetSpell()->m_targets.RemoveObjectTarget();
    }

    void Register()
    {
        OnDestinationTargetSelect.Register(&spell_janalai_flame_breath::ModifyDestination, EFFECT_0, TARGET_DEST_TARGET_ENEMY);
    }
};

static constexpr uint8 MAX_FLAME_BREATH_AREAS = 9;

class spell_janalai_flame_breath_AuraScript : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FLAME_BREATH_AREA_EFFECT });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Position const casterPosition = GetTarget()->GetPosition();

        // Initialize target destinations for the upcoming ticks
        for (uint8 i = 0; i < _castDestinations.size(); ++i)
        {
            _castDestinations[i] = casterPosition;
            _castDestinations[i].m_positionX += std::cos(casterPosition.GetOrientation()) * (4.f * i);
            _castDestinations[i].m_positionY += std::sin(casterPosition.GetOrientation()) * (4.f * i);
        }
    }

    void HandlePeriodicTick(AuraEffect const* aurEff)
    {
        uint32 tickNumber = aurEff->GetTickNumber();
        if (tickNumber > _castDestinations.size())
            return;

        float x = 0.f, y = 0.f, z = 0.f;
        _castDestinations[tickNumber - 1].GetPosition(x, y, z);
        GetTarget()->CastSpell({ x, y, z }, SPELL_FLAME_BREATH_AREA_EFFECT);
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_janalai_flame_breath_AuraScript::AfterApply, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic.Register(&spell_janalai_flame_breath_AuraScript::HandlePeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }

private:
    std::array<Position, MAX_FLAME_BREATH_AREAS> _castDestinations;
};

class spell_janalai_fire_bomb : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_FIRE_BOMB_SUMMON_5YD,
                SPELL_FIRE_BOMB_SUMMON_10YD,
                SPELL_FIRE_BOMB_SUMMON_15YD,
                SPELL_FIRE_BOMB_SUMMON_20YD,
                SPELL_FIRE_BOMB_SUMMON_25YD,
                SPELL_FIRE_BOMB_SUMMON_30YD
            });
    }

    void HandlePeriodicTick(AuraEffect const* aurEff)
    {
        Unit* target = GetTarget();
        uint32 const tick = aurEff->GetTickNumber();

        if (tick < 5)
            target->CastSpell(target, SPELL_FIRE_BOMB_SUMMON_5YD);
        else if (tick < 10)
            target->CastSpell(target, SPELL_FIRE_BOMB_SUMMON_10YD);
        else if (tick < 20)
            target->CastSpell(target, SPELL_FIRE_BOMB_SUMMON_15YD);
        else if (tick < 30)
            target->CastSpell(target, SPELL_FIRE_BOMB_SUMMON_20YD);
        else if (tick < 40)
            target->CastSpell(target, SPELL_FIRE_BOMB_SUMMON_25YD);
        else if (tick < 50)
            target->CastSpell(target, SPELL_FIRE_BOMB_SUMMON_30YD);
        else
            Remove();
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_janalai_fire_bomb::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class spell_janalai_firebomb_dummy : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FIRE_BOMB_VISUAL });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_FIRE_BOMB_VISUAL);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_janalai_firebomb_dummy::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_janalai_hatch_all_eggs : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_DRAGONHAWK_HATCHLING });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        if (Creature* creature = GetHitCreature())
            creature->CastSpell(creature, SPELL_SUMMON_DRAGONHAWK_HATCHLING);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_janalai_hatch_all_eggs::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class spell_janalai_hatch_eggs : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_DRAGONHAWK_HATCHLING });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster()));

        if (targets.size() > 3)
            targets.resize(3);
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        if (Creature* creature = GetHitCreature())
            creature->CastSpell(creature, SPELL_SUMMON_DRAGONHAWK_HATCHLING);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_janalai_hatch_eggs::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget.Register(&spell_janalai_hatch_eggs::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_janalai()
{
    RegisterZulAamanCreatureAI(boss_janalai);
    RegisterZulAamanCreatureAI(npc_janalai_amanishi_hatcher);
    RegisterZulAamanCreatureAI(npc_janalai_amani_dragonhawk_hatchling);
    RegisterSpellAndAuraScriptPair(spell_janalai_flame_breath, spell_janalai_flame_breath_AuraScript);
    RegisterSpellScript(spell_janalai_fire_bomb);
    RegisterSpellScript(spell_janalai_firebomb_dummy);
    RegisterSpellScript(spell_janalai_hatch_all_eggs);
    RegisterSpellScript(spell_janalai_hatch_eggs);
}

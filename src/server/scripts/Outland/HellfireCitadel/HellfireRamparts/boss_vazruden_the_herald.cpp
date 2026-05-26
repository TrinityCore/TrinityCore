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

/*
 * Purpose of SPELL_LOGIC_TIMER is unknown
 * Combat timers requires to be revisited, especially Fireball (victim and random)
 * Not sure if Cone of Fire Script Effect uses same spell in heroic difficulty
 * Liquid fire should be disturbed by Activate Object action, however currently object can't disturb itself.
   But even if we force any creature to disturb object, triggered spell will hit player not always and always as miss.
   Currently we force creature to cast spell, that is a hack
 * Vazruden doesn't cast Revenge spell. Maybe required AURA_STATE_DEFENSE is not applied?
 * SPELL_BELLOWING_ROAR_H gets interrupted instantly, probably because of No Move Flags Update extra flag
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "hellfire_ramparts.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum VazrudenTexts
{
    // Vazruden the Herald
    SAY_INTRO                     = 0,

    // Vazruden
    SAY_TAUNT                     = 0,
    SAY_AGGRO                     = 1,
    SAY_SLAY                      = 2,
    SAY_DEATH                     = 3,

    // Nazan
    EMOTE_DESCEND                 = 0
};

enum VazrudenSpells
{
    // Vazruden the Herald / Nazan - Intro
    SPELL_SUMMON_VAZRUDEN         = 30717,

    // Vazruden the Herald / Nazan - Flying Phase
    SPELL_FLY_NORTH               = 30696,
    SPELL_FLY_WEST                = 30698,
    SPELL_FLY_EAST                = 30699,
    SPELL_LOGIC_TIMER             = 30694,
    SPELL_FACE_HIGHEST_THREAT     = 30700,
    SPELL_DRAGON_HOVER            = 18430,

    // Vazruden the Herald / Nazan - Flying Phase - Combat
    SPELL_FIREBALL_VICTIM         = 30691,
    SPELL_FIREBALL_VICTIM_H       = 32491,
    SPELL_FIREBALL_RANDOM         = 33793,
    SPELL_FIREBALL_RANDOM_H       = 33794,

    // Vazruden the Herald / Nazan - Descending
    SPELL_HATE_TO_ZERO            = 20538,

    // Vazruden the Herald / Nazan - Ground Phase - Combat
    SPELL_FIREBALL_GROUND         = 34653,
    SPELL_FIREBALL_GROUND_H       = 36920,
    SPELL_CONE_OF_FIRE            = 30926,
    SPELL_CONE_OF_FIRE_H          = 36921,
    SPELL_BELLOWING_ROAR_H        = 39427,

    // Vazruden
    SPELL_DEFENSIVE_STATE         = 5301,
    SPELL_REVENGE                 = 19130,
    SPELL_REVENGE_H               = 40392,
    SPELL_CALL_NAZAN              = 30693,

    // Scripts
    SPELL_SUMMON_LIQUID_FIRE      = 31706,
    SPELL_SUMMON_LIQUID_FIRE_H    = 30928,
    SPELL_SUMMON_LIQUID_FIRE_CONE = 23971
};

enum VazrudenEvents
{
    // Vazruden the Herald / Nazan - Special: Intro
    EVENT_INTRO_1                 = 1,
    EVENT_INTRO_2,

    // Vazruden the Herald / Nazan - Special: Descend
    EVENT_DESCEND_1,
    EVENT_DESCEND_2,
    EVENT_DESCEND_3,
    EVENT_DESCEND_4,

    // Vazruden the Herald / Nazan - Fly
    EVENT_FLY_TO_LOC,

    // Vazruden the Herald / Nazan - Flying Phase - Combat
    EVENT_FIREBALL_VICTIM,
    EVENT_FIREBALL_RANDOM,

    // Vazruden the Herald / Nazan - Ground Phase - Combat
    EVENT_FIREBALL_GROUND,
    EVENT_CONE_OF_FIRE,
    EVENT_BELLOWING_ROAR,

    // Vazruden
    EVENT_SAY_AGGRO,
    EVENT_REVENGE,
    EVENT_CALL_NAZAN
};

enum VazrudenPoints
{
    POINT_CENTER                  = 0,
    POINT_FLY_NORTH               = 1,
    POINT_FLY_WEST                = 2,
    POINT_FLY_EAST                = 3,
    POINT_DESCEND                 = 4,
    POINT_FALL                    = 5
};

enum VazrudenMisc
{
    ACTION_START_DESCENDING       = 0,
    ACTION_OTHER_IS_DEAD          = 1
};

static Position const CenterPos   = { -1410.5204f, 1740.5852f, 89.05998f, 0.0f };
static Position const FlyWestPos  = { -1423.4910f, 1710.4010f, 103.7056f, 0.0f };
static Position const FlyEastPos  = { -1375.3560f, 1744.6040f, 99.14612f, 0.0f };
static Position const FlyNorthPos = { -1444.9900f, 1752.9600f, 98.20342f, 0.0f };
static Position const DescendPos  = { -1429.1720f, 1749.1290f, 84.34760f, 0.0f };

// 17307 - Vazruden the Herald
struct boss_vazruden_the_herald : public BossAI
{
    boss_vazruden_the_herald(Creature* creature) : BossAI(creature, DATA_VAZRUDEN_THE_HERALD)
    {
        Initialize();
    }

    void Initialize()
    {
        _lastFlyToSpell = SPELL_FLY_WEST;
        _isEncounterStarted = false;
        _isPerformingIntro = true;
        _startedDescending = false;
        _isOtherDead = false;
        _isUnkillable = true;
    }

    void JustAppeared() override
    {
        me->SetDisableGravity(true);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        DoAction(ACTION_START_ENCOUNTER);

        events.ScheduleEvent(EVENT_FIREBALL_VICTIM, 0s);
        events.ScheduleEvent(EVENT_FIREBALL_RANDOM, 10s, 15s);
        events.ScheduleEvent(EVENT_FLY_TO_LOC, 20s, 30s);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_ENCOUNTER:
                if (!_isEncounterStarted)
                {
                    _isEncounterStarted = true;
                    _specialEvents.ScheduleEvent(EVENT_INTRO_1, 0s);
                }
                break;
            case ACTION_START_DESCENDING:
                if (!_startedDescending)
                {
                    _startedDescending = true;
                    _specialEvents.ScheduleEvent(EVENT_DESCEND_1, 0s);
                }
                break;
            case ACTION_OTHER_IS_DEAD:
                _isOtherDead = true;
                break;
            default:
                break;
        }
    }

    // Do not despawn Vazruden
    void JustSummoned(Creature* /*summon*/) override { }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth() && _isUnkillable)
            damage = me->GetHealth() - 1;

        if (!_isPerformingIntro && !_startedDescending && me->HealthBelowPctDamaged(30, damage))
        {
            _startedDescending = true;
            _specialEvents.ScheduleEvent(EVENT_DESCEND_1, 0s);
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
            return;

        switch (id)
        {
            case POINT_CENTER:
                _specialEvents.ScheduleEvent(EVENT_INTRO_2, 1s);
                break;
            case POINT_FLY_NORTH:
            case POINT_FLY_WEST:
            case POINT_FLY_EAST:
                DoCastSelf(SPELL_FACE_HIGHEST_THREAT);
                DoCastSelf(SPELL_DRAGON_HOVER);
                me->SetReactState(REACT_AGGRESSIVE);
                break;
            case POINT_DESCEND:
                _specialEvents.ScheduleEvent(EVENT_DESCEND_2, 0s);
                break;
            case POINT_FALL:
                _specialEvents.ScheduleEvent(EVENT_DESCEND_3, 0s);
                break;
            default:
                break;
        }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_FLY_NORTH:
                me->GetMotionMaster()->MovePoint(POINT_FLY_NORTH, FlyNorthPos);
                break;
            case SPELL_FLY_WEST:
                me->GetMotionMaster()->MovePoint(POINT_FLY_WEST, FlyWestPos);
                break;
            case SPELL_FLY_EAST:
                me->GetMotionMaster()->MovePoint(POINT_FLY_EAST, FlyEastPos);
                break;
            case SPELL_FACE_HIGHEST_THREAT:
                if (Unit* target = SelectTarget(SelectTargetMethod::MaxThreat))
                    me->SetFacingTo(me->GetAbsoluteAngle(target));
                break;
            default:
                break;
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->DespawnOrUnsummon();

        instance->SetBossState(DATA_VAZRUDEN_THE_HERALD, FAIL);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (_isOtherDead)
            _JustDied();

        if (Creature* vazruden = instance->GetCreature(DATA_VAZRUDEN))
            vazruden->AI()->DoAction(ACTION_OTHER_IS_DEAD);
    }

    void UpdateSpecialEvents(uint32 diff)
    {
        _specialEvents.Update(diff);

        while (uint32 eventId = _specialEvents.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INTRO_1:
                    Talk(SAY_INTRO);
                    me->SetReactState(REACT_PASSIVE);
                    me->GetMotionMaster()->MoveIdle();
                    me->GetMotionMaster()->MovePoint(POINT_CENTER, CenterPos);
                    break;
                case EVENT_INTRO_2:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_LAND);
                    me->SetDisableGravity(false);
                    me->UpdateEntry(NPC_NAZAN);
                    me->SetReactState(REACT_PASSIVE);
                    DoCastSelf(SPELL_SUMMON_VAZRUDEN);
                    me->SetDisableGravity(true);
                    DoCastSelf(SPELL_FLY_WEST);
                    DoCastSelf(SPELL_LOGIC_TIMER);
                    DoZoneInCombat();
                    _isPerformingIntro = false;
                    break;

                case EVENT_DESCEND_1:
                    Talk(EMOTE_DESCEND);
                    me->SetReactState(REACT_PASSIVE);
                    me->RemoveAurasDueToSpell(SPELL_DRAGON_HOVER);
                    me->GetMotionMaster()->MoveIdle();
                    me->GetMotionMaster()->MovePoint(POINT_DESCEND, DescendPos);
                    me->InterruptNonMeleeSpells(false);
                    events.Reset();
                    break;
                case EVENT_DESCEND_2:
                    me->GetMotionMaster()->MoveFall(POINT_FALL);
                    break;
                case EVENT_DESCEND_3:
                    me->SetDisableGravity(false);
                    DoCastSelf(SPELL_HATE_TO_ZERO);
                    _specialEvents.ScheduleEvent(EVENT_DESCEND_4, 2s);
                    break;
                case EVENT_DESCEND_4:
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoCastSelf(SPELL_LOGIC_TIMER);

                    _isUnkillable = false;

                    events.ScheduleEvent(EVENT_FIREBALL_GROUND, 0s, 5s);
                    events.ScheduleEvent(EVENT_CONE_OF_FIRE, 0s, 10s);
                    if (IsHeroic())
                        events.ScheduleEvent(EVENT_BELLOWING_ROAR, 2s);
                    break;
                default:
                    break;
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateSpecialEvents(diff);

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                // Fly
                case EVENT_FLY_TO_LOC:
                {
                    me->RemoveAurasDueToSpell(SPELL_DRAGON_HOVER);
                    me->SetReactState(REACT_PASSIVE);

                    std::vector<uint32> availableFlyToSpells = { SPELL_FLY_NORTH, SPELL_FLY_WEST, SPELL_FLY_EAST };

                    std::erase(availableFlyToSpells, _lastFlyToSpell);

                    uint32 selectedSpell = Trinity::Containers::SelectRandomContainerElement(availableFlyToSpells);

                    _lastFlyToSpell = selectedSpell;

                    DoCastSelf(selectedSpell);
                    events.Repeat(20s, 30s);
                    break;
                }

                // Flying Phase
                case EVENT_FIREBALL_VICTIM:
                    if (me->GetReactState() != REACT_PASSIVE)
                        DoCastVictim(DUNGEON_MODE(SPELL_FIREBALL_VICTIM, SPELL_FIREBALL_VICTIM_H));
                    events.Repeat(3200ms);
                    break;
                case EVENT_FIREBALL_RANDOM:
                    if (me->GetReactState() != REACT_PASSIVE)
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                            DoCast(target, DUNGEON_MODE(SPELL_FIREBALL_RANDOM, SPELL_FIREBALL_RANDOM_H));
                    events.Repeat(10s, 15s);
                    break;

                // Ground Phase
                case EVENT_FIREBALL_GROUND:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, DUNGEON_MODE(SPELL_FIREBALL_GROUND, SPELL_FIREBALL_GROUND_H));
                    events.Repeat(5s, 15s);
                    break;
                case EVENT_CONE_OF_FIRE:
                    DoCastVictim(DUNGEON_MODE(SPELL_CONE_OF_FIRE, SPELL_CONE_OF_FIRE_H));
                    events.Repeat(10s, 15s);
                    break;
                case EVENT_BELLOWING_ROAR:
                    DoCastSelf(SPELL_BELLOWING_ROAR_H);
                    events.Repeat(40s, 50s);
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
    EventMap _specialEvents;
    uint32 _lastFlyToSpell;
    bool _isEncounterStarted;
    bool _isPerformingIntro;
    bool _startedDescending;
    bool _isOtherDead;
    bool _isUnkillable;
};

// 17537 - Vazruden
struct boss_vazruden : public BossAI
{
    boss_vazruden(Creature* creature) : BossAI(creature, DATA_VAZRUDEN_THE_HERALD), _isOtherDead(false), _hasCalledNazan(false) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_DEFENSIVE_STATE);
        DoZoneInCombat();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_SAY_AGGRO, 5s);
        events.ScheduleEvent(EVENT_REVENGE, 5s, 10s);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_hasCalledNazan && me->HealthBelowPctDamaged(40, damage))
        {
            _hasCalledNazan = true;
            events.ScheduleEvent(EVENT_CALL_NAZAN, 0s);
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_OTHER_IS_DEAD)
            _isOtherDead = true;
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        Talk(SAY_TAUNT);
        me->DespawnOrUnsummon();

        instance->SetBossState(DATA_VAZRUDEN_THE_HERALD, FAIL);
    }

    void KilledUnit(Unit* /*who*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (_isOtherDead)
            _JustDied();

        Talk(SAY_DEATH);

        DoCastSelf(SPELL_CALL_NAZAN);

        if (Creature* vazruden = instance->GetCreature(DATA_VAZRUDEN_THE_HERALD))
            vazruden->AI()->DoAction(ACTION_OTHER_IS_DEAD);
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
                case EVENT_SAY_AGGRO:
                    Talk(SAY_AGGRO);
                    break;
                case EVENT_REVENGE:
                    DoCastVictim(DUNGEON_MODE(SPELL_REVENGE, SPELL_REVENGE_H));
                    events.Repeat(5s, 10s);
                    break;
                case EVENT_CALL_NAZAN:
                    DoCastSelf(SPELL_CALL_NAZAN);
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
    bool _isOtherDead;
    bool _hasCalledNazan;
};

// 180125, 181890, 182533 - Liquid Fire
struct go_vazruden_liquid_fire : public GameObjectAI
{
    using GameObjectAI::GameObjectAI;

    void Reset() override
    {
        _scheduler.Schedule(0s, [this](TaskContext task)
        {
            if (Creature* creature = me->SummonCreature(21252, me->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 1s))
                creature->CastSpell(creature, me->GetGOInfo()->trap.spellId);
            task.Repeat(2s);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 30693 - Call Nazan
class spell_vazruden_call_nazan : public SpellScript
{
    PrepareSpellScript(spell_vazruden_call_nazan);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Creature* creature = GetHitCreature())
            creature->AI()->DoAction(ACTION_START_DESCENDING);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_vazruden_call_nazan::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 30691, 32491 - Fireball
// 33793, 33794 - Fireball
// 34653, 36920 - Fireball
class spell_vazruden_fireball : public SpellScript
{
    PrepareSpellScript(spell_vazruden_fireball);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_LIQUID_FIRE, SPELL_SUMMON_LIQUID_FIRE_H });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), GetHitUnit()->GetMap()->IsHeroic() ? SPELL_SUMMON_LIQUID_FIRE_H : SPELL_SUMMON_LIQUID_FIRE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_vazruden_fireball::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 30926, 36921 - Cone of Fire
class spell_vazruden_cone_of_fire : public SpellScript
{
    PrepareSpellScript(spell_vazruden_cone_of_fire);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_LIQUID_FIRE_CONE });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SUMMON_LIQUID_FIRE_CONE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_vazruden_cone_of_fire::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 30717 - Summon Vazruden
class spell_vazruden_summon_vazruden : public SpellScript
{
    PrepareSpellScript(spell_vazruden_summon_vazruden);

    void SetDest(SpellDestination& dest)
    {
        Unit* caster = GetCaster();
        dest._position.m_positionZ = caster->GetMapHeight(caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ());
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_vazruden_summon_vazruden::SetDest, EFFECT_0, TARGET_DEST_CASTER_SUMMON);
    }
};

void AddSC_boss_vazruden_the_herald()
{
    RegisterHellfireRampartsCreatureAI(boss_vazruden_the_herald);
    RegisterHellfireRampartsCreatureAI(boss_vazruden);
    RegisterHellfireRampartsGameObjectAI(go_vazruden_liquid_fire);
    RegisterSpellScript(spell_vazruden_call_nazan);
    RegisterSpellScript(spell_vazruden_fireball);
    RegisterSpellScript(spell_vazruden_cone_of_fire);
    RegisterSpellScript(spell_vazruden_summon_vazruden);
}

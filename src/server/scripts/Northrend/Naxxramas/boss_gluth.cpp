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
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "naxxramas.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"

enum Texts
{
    EMOTE_SPOTS_ONE                     = 0,
    EMOTE_DECIMATE                      = 1,
    EMOTE_ENRAGE                        = 2,
    EMOTE_DEVOURS_ALL                   = 3,
    EMOTE_BERSERKER                     = 4
};

enum Spells
{
    // Gluth
    SPELL_MORTAL_WOUND                  = 54378, // spell effect dummy unused. what its supposed to do is unkown.
    SPELL_ENRAGE                        = 28371, // 54427 in 25 man.
    SPELL_DECIMATE                      = 28374, // 54426 in 25 man. Effect0 is handled by SpellScript (see below) and 2 rows in conditions table. Effect2 is handled by SpellScript (see below).
    SPELL_DECIMATE_DMG                  = 28375,
    SPELL_BERSERK                       = 26662,
    SPELL_ZOMBIE_CHOW_SEARCH_SINGLE     = 28239, // Insta kill spell. Single target. See spell script below.
    SPELL_ZOMBIE_CHOW_SEARCH_MULTI      = 28404, // Insta kill spell. Affect all zombies 10 yards around Gluth's center. See one row conditions table + spell script below.

    // Zombies
    SPELL_INFECTED_WOUND                = 29307  // Used by the zombies on self.
};

Position const PosSummon[3] =
{
    { 3270.132f, -3169.948f, 297.5891f, 5.88176f },
    { 3307.298f, -3183.449f, 297.5891f, 5.742133f },
    { 3255.708f, -3135.677f, 297.5891f, 1.867502f }
};

enum Events
{
    EVENT_WOUND                         = 1,
    EVENT_ENRAGE,
    EVENT_DECIMATE,
    EVENT_BERSERK,
    EVENT_SUMMON,
    EVENT_SEARCH_ZOMBIE_SINGLE,
    EVENT_KILL_ZOMBIE_SINGLE,
    EVENT_SEARCH_ZOMBIE_MULTI
};

enum States
{
    STATE_GLUTH_NORMAL                  = 1,
    STATE_GLUTH_EATING                  = 2,

    STATE_ZOMBIE_NORMAL                 = 1,
    STATE_ZOMBIE_DECIMATED              = 2,
    STATE_ZOMBIE_TOBE_EATEN             = 3
};

enum SummonGroups
{
    SUMMON_GROUP_CHOW_10MAN = 1,
    SUMMON_GROUP_CHOW_25MAN = 2
};

enum Misc
{
    EVENT_GLUTH_ZOMBIE_BEHAVIOR         = 10495, // unused. event handled by spell_gluth_decimate_SpellScript::HandleEvent
    DATA_ZOMBIE_STATE                   = 1,
    ACTION_DECIMATE_EVENT               = 2,
};

struct boss_gluth : public BossAI
{

    boss_gluth(Creature* creature) : BossAI(creature, BOSS_GLUTH), state(STATE_GLUTH_NORMAL) {}

    void Reset() override
    {
        _Reset();
        zombieToBeEatenGUID.Clear();
        state = STATE_GLUTH_NORMAL;
        me->SetReactState(REACT_AGGRESSIVE);
        me->SetSpeed(UnitMoveType::MOVE_RUN, 12.0f);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_WOUND, 10s);
        events.ScheduleEvent(EVENT_ENRAGE, randtime(Seconds(16), Seconds(22)));
        events.ScheduleEvent(EVENT_DECIMATE, randtime(Minutes(1)+Seconds(50), Minutes(2)));
        events.ScheduleEvent(EVENT_BERSERK, 8min);
        events.ScheduleEvent(EVENT_SUMMON, 15s);
        events.ScheduleEvent(EVENT_SEARCH_ZOMBIE_SINGLE, 12s);
    }

    void SummonedCreatureDies(Creature* summoned, Unit* /* who */) override
    {
        summons.Despawn(summoned); // needed or else dead zombies not despawned yet will still be in the list
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() || !CheckInRoom())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_WOUND:
                    if (state == STATE_GLUTH_EATING)
                    {
                        events.Repeat(Seconds(3));
                        break;
                    }

                    DoCastVictim(SPELL_MORTAL_WOUND);
                    events.Repeat(Seconds(10));
                    break;
                case EVENT_ENRAGE:
                    if (state == STATE_GLUTH_EATING)
                    {
                        events.Repeat(Seconds(5));
                        break;
                    }

                    Talk(EMOTE_ENRAGE);
                    DoCast(me, SPELL_ENRAGE);
                    events.Repeat(randtime(Seconds(16), Seconds(22)));
                    break;
                case EVENT_DECIMATE:
                    if (state == STATE_GLUTH_EATING)
                    {
                        events.Repeat(Seconds(4));
                        break;
                    }

                    Talk(EMOTE_DECIMATE);
                    DoCastAOE(SPELL_DECIMATE);
                    for (int i = 1; i <= 20; i++)
                        events.ScheduleEvent(EVENT_SEARCH_ZOMBIE_MULTI, Seconds(3*i));
                    events.ScheduleEvent(EVENT_DECIMATE, randtime(Minutes(1)+Seconds(50), Minutes(2)));
                    break;
                case EVENT_BERSERK:
                    Talk(EMOTE_BERSERKER);
                    DoCast(me, SPELL_BERSERK);
                    events.Repeat(Minutes(5)); //refresh the hard enrage buff
                    break;
                case EVENT_SUMMON:
                    if (Is25ManRaid()) // one wave each 10s. one wave=1 zombie in 10man and 2 zombies in 25man.
                        me->SummonCreatureGroup(SUMMON_GROUP_CHOW_25MAN);
                    else
                        me->SummonCreatureGroup(SUMMON_GROUP_CHOW_10MAN);
                    events.Repeat(Seconds(10));
                    break;
                case EVENT_SEARCH_ZOMBIE_SINGLE:
                {
                    Creature* zombie = nullptr;
                    for (SummonList::const_iterator itr = summons.begin(); !zombie && itr != summons.end(); ++itr)
                    {
                        zombie = ObjectAccessor::GetCreature(*me, *itr);
                        if (!zombie || !zombie->IsAlive() || !zombie->IsWithinDistInMap(me, 10.0))
                            zombie = nullptr;
                    }

                    if (zombie)
                    {
                        zombieToBeEatenGUID = zombie->GetGUID(); // save for later use

                        // the soon-to-be-eaten zombie should stop moving and stop attacking
                        zombie->AI()->SetData(DATA_ZOMBIE_STATE, STATE_ZOMBIE_TOBE_EATEN);

                        // gluth should stop AAs on his primary target and turn toward the zombie (2 yards away). He then pauses for a few seconds.
                        me->SetSpeed(MOVE_RUN, 36.0f);

                        me->SetReactState(ReactStates::REACT_PASSIVE);
                        me->AttackStop();

                        Talk(EMOTE_SPOTS_ONE);

                        //me->SetTarget(ObjectGuid::Empty);

                        me->GetMotionMaster()->MoveCloserAndStop(1, zombie, 2.0f);

                        state = STATE_GLUTH_EATING;
                    }

                    events.Repeat(RAID_MODE(Seconds(7), Seconds(5)));
                    break;
                }
                case EVENT_KILL_ZOMBIE_SINGLE:
                {
                    Creature* zombieToBeEaten = ObjectAccessor::GetCreature(*me, zombieToBeEatenGUID);
                    if (zombieToBeEaten && zombieToBeEaten->IsAlive() && zombieToBeEaten->IsWithinDistInMap(me, 10.0))
                        DoCast(zombieToBeEaten, SPELL_ZOMBIE_CHOW_SEARCH_SINGLE); // do the killing + healing in done inside by spell script see below.

                    zombieToBeEatenGUID = ObjectGuid::Empty;
                    state = STATE_GLUTH_NORMAL;
                    me->SetSpeed(UnitMoveType::MOVE_RUN, 12.0f);

                    // and then return on primary target
                    me->SetReactState(REACT_AGGRESSIVE);

                    break;
                }
                case EVENT_SEARCH_ZOMBIE_MULTI:
                {
                    if (state == STATE_GLUTH_EATING) // skip and simply wait for the next occurence
                        break;

                    Creature* zombie = nullptr;
                    for (SummonList::const_iterator itr = summons.begin(); !zombie && itr != summons.end(); ++itr)
                    {
                        zombie = ObjectAccessor::GetCreature(*me, *itr);
                        if (zombie && zombie->IsAlive() && zombie->GetExactDist2d(me) > 18.0)
                            zombie = nullptr;
                    }

                    if (zombie) // cast the aoe spell only if at least one zombie is found nearby
                    {
                        Talk(EMOTE_DEVOURS_ALL);
                        DoCastAOE(SPELL_ZOMBIE_CHOW_SEARCH_MULTI);
                    }
                    break;
                }
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        if (id == 1){
            me->GetMotionMaster()->MoveIdle();
            events.ScheduleEvent(EVENT_KILL_ZOMBIE_SINGLE, 1s);
        }

    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_DECIMATE_EVENT:
                for (ObjectGuid zombieGuid : summons)
                {
                    Creature* zombie = ObjectAccessor::GetCreature(*me, zombieGuid);
                    if (zombie && zombie->IsAlive())
                        zombie->AI()->SetData(DATA_ZOMBIE_STATE, STATE_ZOMBIE_DECIMATED);
                }
                break;
        }
    }

private:
    ObjectGuid zombieToBeEatenGUID;
    uint8 state;
};

// 28374, 54426 - Decimate
class spell_gluth_decimate : public SpellScript
{
    // handles the damaging effect of the decimate spell.
    void HandleScriptEffect(SpellEffIndex /* index */)
    {
        if (Unit *unit = GetHitUnit())
        {
            int32 damage = int32(unit->GetHealth()) - int32(unit->CountPctFromMaxHealth(5));
            if (damage > 0)
            {
                CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                args.AddSpellBP0(damage);
                GetCaster()->CastSpell(unit, SPELL_DECIMATE_DMG, args);
            }
        }
    }

    // handles the change of zombies behavior after the decimate spell
    void HandleEvent(SpellEffIndex /* index */)
    {
        GetCaster()->GetAI()->DoAction(ACTION_DECIMATE_EVENT);
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DECIMATE_DMG });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gluth_decimate::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        OnEffectHit += SpellEffectFn(spell_gluth_decimate::HandleEvent, EFFECT_2, SPELL_EFFECT_SEND_EVENT);
    }

    bool Load() override
    {
        return GetCaster() && GetCaster()->GetEntry() == NPC_GLUTH;
    }
};

// 28239, 28404 - Zombie Chow Search (single target and aoe zombie-kill spell) to heal Gluth on each target hit
class spell_gluth_zombiechow_search : public SpellScript
{
    void HealForEachTargetHit()
    {
        GetCaster()->ModifyHealth(int32(GetCaster()->CountPctFromMaxHealth(5)));
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_gluth_zombiechow_search::HealForEachTargetHit);
    }

    bool Load() override
    {
        return GetCaster() && GetCaster()->GetEntry() == NPC_GLUTH;
    }
};

// creature 16360 (10man) / 30303 (25man)
struct npc_zombie_chow : public ScriptedAI
{
    npc_zombie_chow(Creature* creature) : ScriptedAI(creature)
    {
        GluthGUID = creature->GetInstanceScript()->GetGuidData(DATA_GLUTH);

        DoCast(me, SPELL_INFECTED_WOUND);
        timer = 0;
        state = STATE_ZOMBIE_NORMAL;
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (state == STATE_ZOMBIE_DECIMATED)
        {
            timer += diff;
            if (Creature* gluth = ObjectAccessor::GetCreature(*me, GluthGUID))
            {
                // Putting this in the UpdateAI loop fixes an issue where death gripping a decimated zombie would make the zombie stand still until the rest of the fight.
                // Also fix the issue where if one or more zombie is rooted when decimates hits (and MovePoint() is called), the zombie teleport to the boss. pretty weird behavior.
                if (timer > 1600 && me->GetExactDist2d(gluth) > 10.0f && me->CanFreeMove()) // it takes about 1600 ms for the animation to cycle. This way, the animation looks relatively smooth.
                {
                    me->GetMotionMaster()->MovePoint(0, gluth->GetPosition()); // isn't dynamic. So, to take into account Gluth's movement, it must be called periodicly.
                    timer = 0;
                }

                if (me->GetExactDist2d(gluth) <= 10.0f)
                    me->StopMoving();
            }
        }
    }

    void SetData(uint32 id, uint32 value) override
    {
        if (id == DATA_ZOMBIE_STATE) // change of state
        {
            state = value;
            if (value == STATE_ZOMBIE_DECIMATED)
            {
                me->SetReactState(ReactStates::REACT_PASSIVE);
                me->AttackStop();
                me->SetCanMelee(false);
                me->SetTarget(ObjectGuid::Empty);
                // at this point, the zombie should be non attacking and non moving.

                me->SetWalk(true); // it doesnt seem to work with MoveFollow() (but it does work with MovePoint()).

                timer = 1000;
            }
            else if (value == STATE_ZOMBIE_TOBE_EATEN)
            {
                // forced to stand still
                me->GetMotionMaster()->Clear();
                me->StopMoving();

                // and loose aggro behavior
                me->SetReactState(ReactStates::REACT_PASSIVE);
                me->AttackStop();
                me->SetCanMelee(false);
                me->SetTarget(ObjectGuid::Empty);

                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true); // not sure if this is blizz-like but this is very convenient
            }
        }
    }

    uint32 GetData(uint32 index) const override
    {
        if (index == DATA_ZOMBIE_STATE)
            return state;
        return 0;
    }

private:
    uint32 timer;
    uint8 state;
    ObjectGuid GluthGUID;
};

void AddSC_boss_gluth()
{
    RegisterNaxxramasCreatureAI(boss_gluth);
    RegisterSpellScript(spell_gluth_decimate);
    RegisterSpellScript(spell_gluth_zombiechow_search);
    RegisterNaxxramasCreatureAI(npc_zombie_chow);
}

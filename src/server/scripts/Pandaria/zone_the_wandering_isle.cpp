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

#include "CellImpl.h"
#include "Containers.h"
#include "CreatureAI.h"
#include "CreatureAIImpl.h" // for RAND()
#include "GridNotifiersImpl.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "TaskScheduler.h"

enum TraineeMisc
{
    SAY_FINISH_FIGHT                    = 0,

    SPELL_BLACKOUT_KICK                 = 109080,

    QUEST_29524_KILLCREDIT              = 54586,

    POINT_DESPAWN                       = 0,

    NPC_HUOJIN_TRAINEE_MALE             = 54586,
    NPC_HUOJIN_TRAINEE_FEMALE           = 65470,
    NPC_TUSHUI_TRAINEE_MALE             = 54587,
    NPC_TUSHUI_TRAINEE_FEMALE           = 65471,
};

Position const TraineeEndpoints[] = {
    { 1465.3872f, 3283.8604f, 137.69096f },
    { 1431.401f, 3264.001f, 136.02579f },
    { 1397.2067f, 3276.5618f, 133.84508f },
    { 1441.566f, 3232.8013f, 135.01802f },
    { 1403.632f, 3229.1094f, 132.14877f },
    { 1347.1927f, 3286.5842f, 131.94803f },
    { 1365.1865f, 3338.9502f, 128.57233f },
    { 1349.6024f, 3315.0574f, 130.97443f },
    { 1335.4618f, 3344.019f, 130.42047f },
    { 1360.1198f, 3378.02f, 127.34183f },
    { 1435.8524f, 3355.6423f, 173.77744f },
    { 1432.7031f, 3385.1572f, 184.4187f },
    { 1452.6094f, 3373.3315f, 187.0402f },
    { 1426.7778f, 3364.7517f, 184.39569f },
    { 1450.3646f, 3361.264f, 184.42484f },
};

Emote constexpr TraineeEmotes[5] =
{
    EMOTE_ONESHOT_MONKOFFENSE_ATTACKUNARMED,
    EMOTE_ONESHOT_MONKOFFENSE_SPECIALUNARMED,
    EMOTE_ONESHOT_MONKOFFENSE_PARRYUNARMED,
    EMOTE_ONESHOT_PALMSTRIKE,
    EMOTE_ONESHOT_MONKOFFENSE_ATTACKUNARMEDOFF,
};

// 54586 - Huojin Trainee
// 65470 - Huojin Trainee
// 54587 - Tushui Trainee
// 65471 - Tushui Trainee
struct npc_tushui_huojin_trainee : public ScriptedAI
{
    npc_tushui_huojin_trainee(Creature* creature) : ScriptedAI(creature), _defeated(false) { }

    Emote PlayRandomEmote() const
    {
        Emote emote = Trinity::Containers::SelectRandomContainerElement(TraineeEmotes);
        me->HandleEmoteCommand(emote);
        return emote;
    }

    void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->HealthBelowPctDamaged(20, damage))
        {
            damage = 0;
            if (_defeated)
                return;

            _defeated = true;
            if (attacker)
            {
                if (Player* player = attacker->ToPlayer())
                    player->KilledMonsterCredit(QUEST_29524_KILLCREDIT);
            }

            me->SetEmoteState(EMOTE_ONESHOT_NONE);
            me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
            me->CombatStop();

            _scheduler.Schedule(Seconds(1), [this](TaskContext /*task*/)
            {
                Talk(SAY_FINISH_FIGHT);
            });

            _scheduler.Schedule(Seconds(3), [this](TaskContext /*task*/)
            {
                Position currentPosition;
                float currentDist = 1000.0f;
                for (Position const& pos : TraineeEndpoints)
                {
                    float dist = pos.GetExactDist(me);
                    if (dist >= currentDist)
                        continue;

                    currentPosition = pos;
                    currentDist = dist;
                }
                me->GetMotionMaster()->MovePoint(POINT_DESPAWN, currentPosition);
            });
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id != POINT_DESPAWN)
            return;

        me->DespawnOrUnsummon();
    }

    void JustEngagedWith(Unit* /*attacker*/) override
    {
        _scheduler.Schedule(Seconds(4), [this](TaskContext task)
        {
            if (me->GetVictim())
                DoCastVictim(SPELL_BLACKOUT_KICK);

            task.Repeat(Seconds(8));
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        if (!_defeated)
            ScriptedAI::EnterEvadeMode(why);
    }

protected:
    TaskScheduler _scheduler;
    bool _defeated;
};

enum HuojinTraineeMisc
{
    ACTION_PARTNER_ENTERED_COMBAT = 1,
};

class HuojinTraineePartnerSearch
{
public:
    HuojinTraineePartnerSearch(Creature* partner) : _partner(partner), _minDist(10.0f) { }

    bool operator()(Creature const* target)
    {
        if (target->GetEntry() != NPC_HUOJIN_TRAINEE_MALE && target->GetEntry() != NPC_HUOJIN_TRAINEE_FEMALE)
            return false;
        if (target == _partner)
            return false;
        if (target->IsInCombat())
            return false;
        if (target->IsInEvadeMode())
            return false;
        if (target->isDead())
            return false;

        float dist = target->GetDistance(_partner);
        if (dist >= _minDist)
            return false;

        _minDist = dist;
        return true;
    }

private:
    Unit* _partner;
    float _minDist;
};

// 54586 - Huojin Trainee
// 65470 - Huojin Trainee
struct npc_huojin_trainee : public npc_tushui_huojin_trainee
{
    npc_huojin_trainee(Creature* creature) : npc_tushui_huojin_trainee(creature) { }

    void JustEngagedWith(Unit* attacker) override
    {
        _scheduler.CancelAll();
        npc_tushui_huojin_trainee::JustEngagedWith(attacker);

        Creature* partner = ObjectAccessor::GetCreature(*me, _partnerGuid);
        if (!partner)
            return;

        if (partner->AI())
            partner->AI()->DoAction(ACTION_PARTNER_ENTERED_COMBAT);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_PARTNER_ENTERED_COMBAT)
        {
            _scheduler.CancelAll();

            me->SetEmoteState(EMOTE_ONESHOT_NONE);
            _scheduler.Schedule(Seconds(1), [this](TaskContext /*task*/ )
            {
                me->HandleEmoteCommand(EMOTE_ONESHOT_BOW);
            });
        }
    }

    void BeginSparring(ObjectGuid guid)
    {
        _partnerGuid = guid;
        me->SetEmoteState(EMOTE_ONESHOT_NONE);
        me->HandleEmoteCommand(EMOTE_ONESHOT_BOW);

        _scheduler.Schedule(Seconds(1), [this](TaskContext /*task*/)
        {
            me->SetEmoteState(EMOTE_STATE_MONKOFFENSE_READYUNARMED);
        });

        _scheduler.Schedule(Seconds(4), [this](TaskContext task)
        {
            PlayRandomEmote();
            task.Repeat(Seconds(4));
        });
    }

    Creature* GetNewPartner() const
    {
        Creature* partner = nullptr;
        HuojinTraineePartnerSearch check(me);
        Trinity::CreatureLastSearcher<HuojinTraineePartnerSearch> searcher(me, partner, check);
        Cell::VisitGridObjects(me, searcher, 10.0f);
        return partner;
    }

    void BeginSparringDelayed(ObjectGuid partnerGuid)
    {
        _partnerGuid = partnerGuid;
        _scheduler.Schedule(Seconds(1), [this, partnerGuid](TaskContext /*task*/)
        {
            BeginSparring(partnerGuid);
        });
    }

    void InitiateSparring()
    {
        Creature* partner = GetNewPartner();

        if (!partner)
            return;

        BeginSparring(partner->GetGUID());
        if (Creature* partner = ObjectAccessor::GetCreature(*me, _partnerGuid))
        {
            if (npc_huojin_trainee* ai = CAST_AI(npc_huojin_trainee, partner->GetAI()))
                ai->BeginSparringDelayed(me->GetGUID());
        }
    }

    void JustReachedHome() override
    {
        InitiateSparring();
    }

    void JustAppeared() override
    {
        // partner is already assigned, sparring start is delayed
        if (!ObjectAccessor::GetCreature(*me, _partnerGuid))
            InitiateSparring();
    }
private:
    ObjectGuid _partnerGuid;
};

class TushuiTraineeSearch
{
public:
    TushuiTraineeSearch(Creature* leader, float maxDist) : _leader(leader), _maxDist(maxDist) { }

    bool operator()(Creature const* target) const
    {
        if (target->GetEntry() != NPC_TUSHUI_TRAINEE_MALE && target->GetEntry() != NPC_TUSHUI_TRAINEE_FEMALE)
            return false;
        if (target->IsInCombat())
            return false;
        if (target->IsInEvadeMode())
            return false;
        if (target->GetDistance(_leader) >= _maxDist)
            return false;
        if (target->isDead())
            return false;

        return true;
    }

private:
    Creature* _leader;
    float _maxDist;
};

void HandleEmoteNearbyTushuiTrainees(Creature* leader, Emote emote)
{
    std::list<Creature*> traineeList;
    TushuiTraineeSearch check(leader, 10.0f);
    Trinity::CreatureListSearcher<TushuiTraineeSearch> searcher(leader, traineeList, check);
    Cell::VisitGridObjects(leader, searcher, 10.0f);

    for (Creature* trainee : traineeList)
        trainee->HandleEmoteCommand(emote);
}

// 54587 - Tushui Trainee
// 65471 - Tushui Trainee
struct npc_tushui_leading_trainee : public npc_tushui_huojin_trainee
{
    npc_tushui_leading_trainee(Creature* creature) : npc_tushui_huojin_trainee(creature) { }

    void ScheduleEmoteExecution()
    {
        _scheduler.Schedule(Seconds(1), [this](TaskContext task)
        {
            Emote emote = PlayRandomEmote();
            HandleEmoteNearbyTushuiTrainees(me, emote);
            task.Repeat(Seconds(6));
        });
    }

    void JustReachedHome() override
    {
        ScheduleEmoteExecution();
    }

    void JustAppeared() override
    {
        ScheduleEmoteExecution();
    }

    void JustEngagedWith(Unit* attacker) override
    {
        _scheduler.CancelAll();
        npc_tushui_huojin_trainee::JustEngagedWith(attacker);
    }
};

// 61411 - Instructor Zhi
struct npc_instructor_zhi : public ScriptedAI
{
    npc_instructor_zhi(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        _scheduler.Schedule(Seconds(6), [this](TaskContext task)
        {
            Emote emote = Trinity::Containers::SelectRandomContainerElement(TraineeEmotes);
            me->HandleEmoteCommand(emote);

            task.Schedule(Seconds(1), [this, emote](TaskContext /*task*/)
            {
                HandleEmoteNearbyTushuiTrainees(me, emote);
            });
            task.Repeat(Seconds(6));
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

enum JaominRoMisc
{
    // Spells
    SPELL_CSA_AREATRIGGER_DUMMY      = 88811,
    SPELL_HAWK_DIVING_TO_EARTH       = 108955,
    SPELL_HAWK_DIVING_TO_EARTH_DMG   = 108935,
    SPELL_BABY_ELEPHANT_TAKES_A_BATH = 108938,
    SPELL_FORCE_SUMMONER_TO_RIDE     = 108583,
    SPELL_EJECT_ALL_PASSENGERS       = 50630,
    SPELL_DIZZY                      = 108959,
    SPELL_RIDE_DRAKE                 = 108582,
    SPELL_SERVERSIDE_KILL_CREDIT     = 109837,
    SPELL_FULL_HEALTH                = 17683,

    // Texts
    SAY_INTRO                        = 0,
    SAY_DEFEATED                     = 1,

    // Movement
    POINT_RANDOM_DEST                = 0,

    // Events
    EVENT_RANDOM_SPELL               = 1,
    EVENT_MOVE,
    EVENT_HEAL,
    EVENT_MOVE_HOME
};

// 54611 - Jaomin Ro
struct npc_jaomin_ro : public ScriptedAI
{
    using ScriptedAI::ScriptedAI;

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_RANDOM_SPELL, 4s, 6s);
    }

    void JustReachedHome() override
    {
        me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE_2);
        me->InitializeReactState();
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_CSA_AREATRIGGER_DUMMY && target->GetTypeId() == TYPEID_PLAYER && !me->IsInCombat())
        {
            Talk(SAY_INTRO, target);
            me->SetOrientation(1.67690026f);
            me->SetStandState(UNIT_STAND_STATE_STAND);
            me->SetEmoteState(EMOTE_STATE_READY_UNARMED);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING) || me->HasUnitState(UNIT_STATE_STUNNED) || me->HasAura(SPELL_RIDE_DRAKE))
            return;

        switch (_events.ExecuteEvent())
        {
            case EVENT_RANDOM_SPELL:
            {
                uint32 spellId = RAND(SPELL_BABY_ELEPHANT_TAKES_A_BATH, SPELL_HAWK_DIVING_TO_EARTH);
                DoCast(spellId);
                _events.ScheduleEvent(EVENT_RANDOM_SPELL, 4s, 6s);
                break;
            }
            case EVENT_HEAL:
            {
                DoCastSelf(SPELL_FULL_HEALTH);
                me->SetUninteractible(false);
                break;
            }
            case EVENT_MOVE_HOME:
            {
                EnterEvadeMode();
                break;
            }
            default:
                break;
        }
    }

    void OnHealthDepleted(Unit* attacker, bool /*isKill*/) override
    {
        me->SetReactState(REACT_PASSIVE);
        me->AttackStop();
        me->RemoveAllAuras();
        me->InterruptNonMeleeSpells(true);
        _events.Reset();
        me->SetUninteractible(true);
        me->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE_2);
        me->SetEmoteState(EMOTE_ONESHOT_NONE);
        DoCast(SPELL_SERVERSIDE_KILL_CREDIT);
        Talk(SAY_DEFEATED, attacker);

        _events.ScheduleEvent(EVENT_HEAL, 5s);
        _events.ScheduleEvent(EVENT_MOVE_HOME, 6s);
    }

private:
    EventMap _events;
};

// 57750 - Jaomin Ro (Hawk)
struct npc_jaomin_ro_hawk : public ScriptedAI
{
    using ScriptedAI::ScriptedAI;

    void JustAppeared() override
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetSpeedRate(MOVE_RUN, 2.5f);
    }

    void IsSummonedBy(WorldObject* summonerWO) override
    {
        Unit* summoner = summonerWO->ToUnit();
        if (!summoner)
            return;
        Unit* victim = summoner->GetVictim();
        if (!victim)
            return;

        DoCast(SPELL_FORCE_SUMMONER_TO_RIDE);
        _scheduler.Schedule(1s, [this, orientation = me->GetAbsoluteAngle(victim) - me->GetOrientation()](TaskContext /*context*/)
        {
            me->GetMotionMaster()->MovePoint(POINT_RANDOM_DEST, me->GetFirstCollisionPosition(40.0f, orientation));
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_HAWK_DIVING_TO_EARTH_DMG && target->GetTypeId() == TYPEID_PLAYER)
        {
            DoCast(SPELL_EJECT_ALL_PASSENGERS);
            me->DespawnOrUnsummon();
        }
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_RANDOM_DEST:
            {
                DoCast(SPELL_EJECT_ALL_PASSENGERS);
                me->DespawnOrUnsummon();
                break;
            }
            default:
                break;
        }
    }

private:
    TaskScheduler _scheduler;
};

// 108583 - Force Summoner to Ride Vehicle
class spell_force_summoner_to_ride_vehicle : public SpellScript
{
    void HandleScript(SpellEffIndex /*effIndex*/) const
    {
        GetHitUnit()->CastSpell(GetCaster(), GetEffectValue(), TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_force_summoner_to_ride_vehicle::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 108582 - Ride Drake
class spell_ride_drake : public AuraScript
{
    void OnRemoveVehicle(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_DIZZY, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_ride_drake::OnRemoveVehicle, EFFECT_0, SPELL_AURA_CONTROL_VEHICLE, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_zone_the_wandering_isle()
{
    RegisterCreatureAI(npc_tushui_huojin_trainee);
    RegisterCreatureAI(npc_huojin_trainee);
    RegisterCreatureAI(npc_tushui_leading_trainee);
    RegisterCreatureAI(npc_instructor_zhi);
    RegisterCreatureAI(npc_jaomin_ro);
    RegisterCreatureAI(npc_jaomin_ro_hawk);
    RegisterSpellScript(spell_force_summoner_to_ride_vehicle);
    RegisterSpellScript(spell_ride_drake);
}

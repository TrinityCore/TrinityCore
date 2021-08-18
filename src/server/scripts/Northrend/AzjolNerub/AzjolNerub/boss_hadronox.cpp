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
#include "azjol_nerub.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum Events
{
    // Hadronox
    EVENT_LEECH_POISON = 1,
    EVENT_ACID_CLOUD,
    EVENT_WEB_GRAB,
    EVENT_PIERCE_ARMOR,
    EVENT_PLAYER_CHECK,

    // Anub'ar Crusher
    EVENT_SMASH,

    // Anub'ar foes - Shared
    EVENT_TAUNT,

    // Anub'ar Champion
    EVENT_REND,
    EVENT_PUMMEL,

    // Anub'ar Crypt Guard
    EVENT_CRUSHING_WEBS,
    EVENT_INFECTED_WOUND,

    // Anub'ar Necromancer
    EVENT_SHADOW_BOLT,
    EVENT_ANIMATE_BONES
};

enum Spells
{
    // Hadronox
    SPELL_WEB_FRONT_DOORS                   = 53177,
    SPELL_WEB_SIDE_DOORS                    = 53185,
    SPELL_LEECH_POISON                      = 53030,
    SPELL_LEECH_POISON_HEAL                 = 53800,
    SPELL_ACID_CLOUD                        = 53400,
    SPELL_WEB_GRAB                          = 57731,
    SPELL_PIERCE_ARMOR                      = 53418,

    // Anub'ar opponent summoning spells
    SPELL_SUMMON_CHAMPION_PERIODIC          = 53035,
    SPELL_SUMMON_CRYPT_FIEND_PERIODIC       = 53037,
    SPELL_SUMMON_NECROMANCER_PERIODIC       = 53036,
    SPELL_SUMMON_CHAMPION_TOP               = 53064,
    SPELL_SUMMON_CRYPT_FIEND_TOP            = 53065,
    SPELL_SUMMON_NECROMANCER_TOP            = 53066,
    SPELL_SUMMON_CHAMPION_BOTTOM            = 53090,
    SPELL_SUMMON_CRYPT_FIEND_BOTTOM         = 53091,
    SPELL_SUMMON_NECROMANCER_BOTTOM         = 53092,

    // Anub'ar Crusher
    SPELL_SMASH                             = 53318,
    SPELL_FRENZY                            = 53801,

    // Anub'ar foes - Shared
    SPELL_TAUNT                             = 53798,

    // Anub'ar Champion
    SPELL_REND                              = 59343,
    SPELL_PUMMEL                            = 59344,

    // Anub'ar Crypt Guard
    SPELL_CRUSHING_WEBS                     = 59347,
    SPELL_INFECTED_WOUND                    = 59348,

    // Anub'ar Necromancer
    SPELL_SHADOW_BOLT                       = 53333,
    SPELL_ANIMATE_BONES_1                   = 53334,
    SPELL_ANIMATE_BONES_2                   = 53336,
};

enum SummonGroups : uint32
{
    SUMMON_GROUP_CRUSHER_1      = 1,
    SUMMON_GROUP_CRUSHER_2      = 2,
    SUMMON_GROUP_CRUSHER_3      = 3
};

enum Actions
{
    ACTION_HADRONOX_MOVE = 1,
    ACTION_CRUSHER_ENGAGED,
    ACTION_PACK_WALK
};

enum Data
{
    DATA_CRUSHER_PACK_ID = 1,
    DATA_HADRONOX_ENTERED_COMBAT,
    DATA_HADRONOX_WEBBED_DOORS
};

enum Creatures
{
    NPC_CRUSHER             = 28922,
    NPC_WORLDTRIGGER_LARGE  = 23472
};

enum Talk
{
    CRUSHER_SAY_AGGRO = 1,
    CRUSHER_EMOTE_FRENZY = 2,
    HADRONOX_EMOTE_MOVE = 1
};

// Movement IDs used by the permanently spawning Anub'ar opponents - they are done in sequence, as one finishes, the next one starts
enum Movements
{
    MOVE_NONE = 0,
    MOVE_OUTSIDE,
    MOVE_DOWNSTAIRS,
    MOVE_DOWNSTAIRS_2,
    MOVE_HADRONOX,       // this one might have us take a detour to avoid pathfinding "through" the floor...
    MOVE_HADRONOX_REAL   // while this one will always make us movechase
};

static const uint8 NUM_STEPS = 4;
static const Position hadronoxStep[NUM_STEPS] =
{
    { 515.5848f, 544.2007f, 673.6272f },
    { 562.191f , 514.068f , 696.4448f },
    { 610.3828f, 518.6407f, 695.9385f },
    { 530.42f  , 560.003f,  733.0308f }
};

struct boss_hadronox : public BossAI
{
    boss_hadronox(Creature* creature) : BossAI(creature, DATA_HADRONOX), _enteredCombat(false), _doorsWebbed(false), _lastPlayerCombatState(false), _step(0) { }

    bool IsInCombatWithPlayer() const
    {
        for (auto const& pair : me->GetCombatManager().GetPvECombatRefs())
            if (pair.second->GetOther(me)->IsControlledByPlayer())
                return true;
        return false;
    }

    void SetStep(uint8 step)
    {
        if (_lastPlayerCombatState)
            return;

        _step = step;
        me->SetReactState(REACT_PASSIVE);
        me->SetHomePosition(hadronoxStep[step]);
        me->GetMotionMaster()->Clear();
        me->AttackStop();
        me->GetMotionMaster()->MovePoint(0, hadronoxStep[step]);
    }

    void SummonCrusherPack(SummonGroups group)
    {
        std::list<TempSummon*> summoned;
        me->SummonCreatureGroup(group, &summoned);
        for (TempSummon* summon : summoned)
        {
            summon->AI()->SetData(DATA_CRUSHER_PACK_ID, group);
            summon->AI()->DoAction(ACTION_PACK_WALK);
        }
    }

    void MovementInform(uint32 type, uint32 /*id*/) override
    {
        if (type != POINT_MOTION_TYPE)
            return;
        me->SetReactState(REACT_AGGRESSIVE);
        if (_step < NUM_STEPS-1)
            return;
        DoCastAOE(SPELL_WEB_FRONT_DOORS);
        DoCastAOE(SPELL_WEB_SIDE_DOORS);
        _doorsWebbed = true;
        DoZoneInCombat();
    }

    uint32 GetData(uint32 data) const override
    {
        if (data == DATA_HADRONOX_ENTERED_COMBAT)
            return _enteredCombat ? 1 : 0;
        if (data == DATA_HADRONOX_WEBBED_DOORS)
            return _doorsWebbed ? 1 : 0;
        return 0;
    }

    bool CanAIAttack(Unit const* target) const override
    {
        // Prevent Hadronox from going too far from her current home position
        if (!target->IsControlledByPlayer() && target->GetDistance(me->GetHomePosition()) > 70.0f)
            return false;
        return BossAI::CanAIAttack(target);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_LEECH_POISON, randtime(Seconds(5), Seconds(7)));
        events.ScheduleEvent(EVENT_ACID_CLOUD, randtime(Seconds(7), Seconds(13)));
        events.ScheduleEvent(EVENT_WEB_GRAB, randtime(Seconds(13), Seconds(19)));
        events.ScheduleEvent(EVENT_PIERCE_ARMOR, randtime(Seconds(4), Seconds(7)));
        events.ScheduleEvent(EVENT_PLAYER_CHECK, 1s);
        me->setActive(true);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_CRUSHER_ENGAGED:
                if (_enteredCombat)
                    break;
                instance->SetBossState(DATA_HADRONOX, IN_PROGRESS);
                _enteredCombat = true;
                SummonCrusherPack(SUMMON_GROUP_CRUSHER_2);
                SummonCrusherPack(SUMMON_GROUP_CRUSHER_3);
                break;
            case ACTION_HADRONOX_MOVE:
                if (_step < NUM_STEPS-1)
                {
                    SetStep(_step + 1);
                    Talk(HADRONOX_EMOTE_MOVE);
                }
                break;
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        std::list<Creature*> triggers;
        me->GetCreatureListWithEntryInGrid(triggers, NPC_WORLDTRIGGER_LARGE);
        for (Creature* trigger : triggers)
            if (trigger->HasAura(SPELL_SUMMON_CHAMPION_PERIODIC) || trigger->HasAura(SPELL_WEB_FRONT_DOORS) || trigger->HasAura(SPELL_WEB_SIDE_DOORS))
                _DespawnAtEvade(25s, trigger);
        _DespawnAtEvade(25s);
        summons.DespawnAll();
        for (ObjectGuid gNerubian : _anubar)
            if (Creature* nerubian = ObjectAccessor::GetCreature(*me, gNerubian))
                nerubian->DespawnOrUnsummon();
    }

    void SetGUID(ObjectGuid const& guid, int32 /*id*/) override
    {
        _anubar.push_back(guid);
    }

    void InitializeAI() override
    {
        BossAI::InitializeAI();
        me->SetReactState(REACT_AGGRESSIVE);
        me->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 9.0f);
        me->SetFloatValue(UNIT_FIELD_COMBATREACH, 9.0f);
        _enteredCombat = false;
        _doorsWebbed = false;
        _lastPlayerCombatState = false;
        SetStep(0);
    }

    void JustAppeared() override
    {
        BossAI::JustAppeared();
        SetCombatMovement(true);
        SummonCrusherPack(SUMMON_GROUP_CRUSHER_1);
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
                case EVENT_LEECH_POISON:
                    DoCastAOE(SPELL_LEECH_POISON);
                    events.Repeat(randtime(Seconds(7), Seconds(9)));
                    break;
                case EVENT_ACID_CLOUD:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f))
                        DoCast(target, SPELL_ACID_CLOUD);
                    events.Repeat(randtime(Seconds(16), Seconds(23)));
                    break;
                case EVENT_WEB_GRAB:
                    DoCastAOE(SPELL_WEB_GRAB);
                    events.Repeat(randtime(Seconds(20), Seconds(25)));
                    break;
                case EVENT_PIERCE_ARMOR:
                    DoCastVictim(SPELL_PIERCE_ARMOR);
                    events.Repeat(randtime(Seconds(10), Seconds(15)));
                    break;
                case EVENT_PLAYER_CHECK:
                    if (IsInCombatWithPlayer() != _lastPlayerCombatState)
                    {
                        _lastPlayerCombatState = !_lastPlayerCombatState;
                        if (_lastPlayerCombatState) // we are now in combat with players
                        {
                            if (!instance->CheckRequiredBosses(DATA_HADRONOX))
                            {
                                EnterEvadeMode(EVADE_REASON_SEQUENCE_BREAK);
                                return;
                            }
                            // cancel current point movement if engaged by players
                            if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == POINT_MOTION_TYPE)
                            {
                                me->GetMotionMaster()->Clear();
                                SetCombatMovement(true);
                                AttackStart(me->GetVictim());
                            }
                        }
                        else // we are no longer in combat with players - reset the encounter
                            EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
                    }
                    events.Repeat(Seconds(1));
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

    // Safeguard to prevent Hadronox dying to NPCs
    void DamageTaken(Unit* who, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if ((!who || !who->IsControlledByPlayer()) && me->HealthBelowPct(70))
        {
            if (me->HealthBelowPctDamaged(5, damage))
                damage = 0;
            else
                damage *= (me->GetHealthPct()-5.0f)/ 65.0f;
        }
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
        // Do not enter combat with zone
    }

    private:
        bool _enteredCombat; // has a player entered combat with the first crusher pack? (talk and spawn two more packs)
        bool _doorsWebbed;   // obvious - have we reached the top and webbed the doors shut? (trigger for hadronox denied achievement)
        bool _lastPlayerCombatState; // was there a player in our threat list the last time we checked (we check every second)
        uint8 _step;
        std::list<ObjectGuid> _anubar;
};

struct npc_hadronox_crusherPackAI : public ScriptedAI
{
    npc_hadronox_crusherPackAI(Creature* creature, Position const* positions) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _positions(positions), _myPack(SummonGroups(0)), _doFacing(false) { }

    void DoAction(int32 action) override
    {
        if (action == ACTION_PACK_WALK)
        {
            switch (_myPack)
            {
                case SUMMON_GROUP_CRUSHER_1:
                case SUMMON_GROUP_CRUSHER_2:
                case SUMMON_GROUP_CRUSHER_3:
                    me->GetMotionMaster()->MovePoint(ACTION_PACK_WALK, _positions[_myPack - SUMMON_GROUP_CRUSHER_1]);
                    break;
                default:
                    break;
            }
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE && id == ACTION_PACK_WALK)
            _doFacing = true;
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        if (Creature* hadronox = _instance->GetCreature(DATA_HADRONOX))
            hadronox->AI()->EnterEvadeMode(EVADE_REASON_OTHER);
    }

    uint32 GetData(uint32 data) const override
    {
        if (data == DATA_CRUSHER_PACK_ID)
            return _myPack;
        return 0;
    }

    void SetData(uint32 data, uint32 value) override
    {
        if (data == DATA_CRUSHER_PACK_ID)
        {
            _myPack = SummonGroups(value);
            me->SetReactState(_myPack ? REACT_PASSIVE : REACT_AGGRESSIVE);
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        if (me->HasReactState(REACT_PASSIVE))
        {
            std::list<Creature*> others;
            me->GetCreatureListWithEntryInGrid(others, 0, 40.0f);
            for (Creature* other : others)
                if (other->AI()->GetData(DATA_CRUSHER_PACK_ID) == _myPack)
                {
                    other->SetReactState(REACT_AGGRESSIVE);
                    other->AI()->AttackStart(who);
                }
        }
        _JustEngagedWith();
        ScriptedAI::JustEngagedWith(who);
    }

    virtual void _JustEngagedWith() = 0;
    virtual void DoEvent(uint32 /*eventId*/) = 0;

    void MoveInLineOfSight(Unit* who) override
    {
        if (!me->HasReactState(REACT_PASSIVE))
        {
            ScriptedAI::MoveInLineOfSight(who);
            return;
        }

        if (me->CanStartAttack(who, false) && me->IsWithinDistInMap(who, me->GetAttackDistance(who) + me->m_CombatDistance))
            JustEngagedWith(who);
    }

    void UpdateAI(uint32 diff) override
    {
        if (_doFacing)
        {
            _doFacing = false;
            me->SetFacingTo(_positions[_myPack - SUMMON_GROUP_CRUSHER_1].GetOrientation());
        }

        if (!UpdateVictim())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
            DoEvent(eventId);

        DoMeleeAttackIfReady();
    }

    protected:
        InstanceScript* const _instance;
        EventMap _events;
        Position const* const _positions;
        SummonGroups _myPack;
        bool _doFacing;

};

static const Position crusherWaypoints[] =
{
    { 529.6913f, 547.1257f, 731.9155f, 4.799650f },
    { 517.51f  , 561.439f , 734.0306f, 4.520403f },
    { 543.414f , 551.728f , 732.0522f, 3.996804f }
};
struct npc_anub_ar_crusher : public npc_hadronox_crusherPackAI
{
    npc_anub_ar_crusher(Creature* creature) : npc_hadronox_crusherPackAI(creature, crusherWaypoints), _hadFrenzy(false) { }

    void _JustEngagedWith() override
    {
        _events.ScheduleEvent(EVENT_SMASH, randtime(Seconds(8), Seconds(12)));

        if (_myPack != SUMMON_GROUP_CRUSHER_1)
            return;

        if (Creature* hadronox = _instance->GetCreature(DATA_HADRONOX))
        {
            if (hadronox->AI()->GetData(DATA_HADRONOX_ENTERED_COMBAT))
                return;
            hadronox->AI()->DoAction(ACTION_CRUSHER_ENGAGED);
        }

        Talk(CRUSHER_SAY_AGGRO);
    }

    void DamageTaken(Unit* /*source*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (_hadFrenzy || !me->HealthBelowPctDamaged(25, damage))
            return;
        _hadFrenzy = true;
        Talk(CRUSHER_EMOTE_FRENZY);
        DoCastSelf(SPELL_FRENZY);
    }

    void DoEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_SMASH:
                DoCastVictim(SPELL_SMASH);
                _events.Repeat(randtime(Seconds(13), Seconds(21)));
                break;
        }
    }

    void JustDied(Unit* killer) override
    {
        if (Creature* hadronox = _instance->GetCreature(DATA_HADRONOX))
            hadronox->AI()->DoAction(ACTION_HADRONOX_MOVE);
        ScriptedAI::JustDied(killer);
    }

    private:
        bool _hadFrenzy;
};

static const Position championWaypoints[] =
{
    { 539.2076f, 549.7539f, 732.8668f, 4.55531f  },
    { 527.3098f, 559.5197f, 732.9407f, 4.742493f },
    { }
};
struct npc_anub_ar_crusher_champion : public npc_hadronox_crusherPackAI
{
    npc_anub_ar_crusher_champion(Creature* creature) : npc_hadronox_crusherPackAI(creature, championWaypoints) { }

    void DoEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_REND:
                DoCastVictim(SPELL_REND);
                _events.Repeat(randtime(Seconds(12), Seconds(16)));
                break;
            case EVENT_PUMMEL:
                DoCastVictim(SPELL_PUMMEL);
                _events.Repeat(randtime(Seconds(12), Seconds(17)));
                break;
        }
    }

    void _JustEngagedWith() override
    {
        _events.ScheduleEvent(EVENT_REND, randtime(Seconds(4), Seconds(8)));
        _events.ScheduleEvent(EVENT_PUMMEL, randtime(Seconds(15), Seconds(19)));
    }
};

static const Position cryptFiendWaypoints[] =
{
    { 520.3911f, 548.7895f, 732.0118f, 5.0091f   },
    { },
    { 550.9611f, 545.1674f, 731.9031f, 3.996804f }
};
struct npc_anub_ar_crusher_crypt_fiend : public npc_hadronox_crusherPackAI
{
    npc_anub_ar_crusher_crypt_fiend(Creature* creature) : npc_hadronox_crusherPackAI(creature, cryptFiendWaypoints) { }

    void DoEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_CRUSHING_WEBS:
                DoCastVictim(SPELL_CRUSHING_WEBS);
                _events.Repeat(randtime(Seconds(12), Seconds(16)));
                break;
            case EVENT_INFECTED_WOUND:
                DoCastVictim(SPELL_INFECTED_WOUND);
                _events.Repeat(randtime(Seconds(16), Seconds(25)));
                break;
        }
    }

    void _JustEngagedWith() override
    {
        _events.ScheduleEvent(EVENT_CRUSHING_WEBS, randtime(Seconds(4), Seconds(8)));
        _events.ScheduleEvent(EVENT_INFECTED_WOUND, randtime(Seconds(15), Seconds(19)));
    }
};

static const Position necromancerWaypoints[] =
{
    { },
    { 507.6937f, 563.3471f, 734.8986f, 4.520403f },
    { 535.1049f, 552.8961f, 732.8441f, 3.996804f },
};
struct npc_anub_ar_crusher_necromancer : public npc_hadronox_crusherPackAI
{
    npc_anub_ar_crusher_necromancer(Creature* creature) : npc_hadronox_crusherPackAI(creature, necromancerWaypoints) { }

    void DoEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_SHADOW_BOLT:
                DoCastVictim(SPELL_SHADOW_BOLT);
                _events.Repeat(randtime(Seconds(2), Seconds(5)));
                break;
            case EVENT_ANIMATE_BONES:
                DoCastVictim(urand(0, 1) ? SPELL_ANIMATE_BONES_2 : SPELL_ANIMATE_BONES_1);
                _events.Repeat(randtime(Seconds(35), Seconds(50)));
                break;
        }
    }

    void _JustEngagedWith() override
    {
        _events.ScheduleEvent(EVENT_SHADOW_BOLT, randtime(Seconds(2), Seconds(4)));
        _events.ScheduleEvent(EVENT_ANIMATE_BONES, randtime(Seconds(37), Seconds(45)));
    }
};

static const uint8 NUM_SPAWNS = 3;
static const Position initialMoves[NUM_SPAWNS] =
{
    { 485.314606f, 611.418640f, 771.428406f },
    { 575.760437f, 611.516418f, 771.427368f },
    { 588.930725f, 598.233276f, 739.142151f }
};
static const Position downstairsMoves[NUM_SPAWNS] =
{
    { 513.574341f, 587.022156f, 736.229065f },
    { 537.920410f, 580.436157f, 732.796692f },
    { 601.289246f, 583.259644f, 725.443054f },
};
static const Position downstairsMoves2[NUM_SPAWNS] =
{
    { 571.498718f, 576.978333f, 727.582947f },
    { 571.498718f, 576.978333f, 727.582947f },
    { }
};
struct npc_hadronox_foeAI : public ScriptedAI
{
    npc_hadronox_foeAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _nextMovement(MOVE_OUTSIDE), _mySpawn(0) { }

    void InitializeAI() override
    {
        ScriptedAI::InitializeAI();
        if (Creature* hadronox = _instance->GetCreature(DATA_HADRONOX))
            hadronox->AI()->SetGUID(me->GetGUID());
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE)
            _nextMovement = Movements(id+1);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->DespawnOrUnsummon();
    }

    virtual void DoEvent(uint32 /*eventId*/) = 0;

    void UpdateAI(uint32 diff) override
    {
        if (_nextMovement)
        {
            switch (_nextMovement)
            {
                case MOVE_OUTSIDE:
                {
                    float dist = HUGE_VALF;
                    for (uint8 spawn = 0; spawn < NUM_SPAWNS; ++spawn)
                    {
                        float thisDist = initialMoves[spawn].GetExactDistSq(me);
                        if (thisDist < dist)
                        {
                            _mySpawn = spawn;
                            dist = thisDist;
                        }
                    }
                    me->GetMotionMaster()->MovePoint(MOVE_OUTSIDE, initialMoves[_mySpawn], false); // do not pathfind here, we have to pass through a "wall" of webbing
                    break;
                }
                case MOVE_DOWNSTAIRS:
                    me->GetMotionMaster()->MovePoint(MOVE_DOWNSTAIRS, downstairsMoves[_mySpawn]);
                    break;
                case MOVE_DOWNSTAIRS_2:
                    if (downstairsMoves2[_mySpawn].GetPositionX() > 0.0f) // might be unset for this spawn - if yes, skip
                    {
                        me->GetMotionMaster()->MovePoint(MOVE_DOWNSTAIRS_2, downstairsMoves2[_mySpawn]);
                        break;
                    }
                    [[fallthrough]];
                case MOVE_HADRONOX:
                case MOVE_HADRONOX_REAL:
                {
                    static const float zCutoff = 702.0f;
                    Creature* hadronox = _instance->GetCreature(DATA_HADRONOX);
                    if (hadronox && hadronox->IsAlive())
                    {
                        if (_nextMovement != MOVE_HADRONOX_REAL)
                            if (hadronox->GetPositionZ() < zCutoff)
                            {
                                me->GetMotionMaster()->MovePoint(MOVE_HADRONOX, hadronoxStep[2]);
                                break;
                            }
                        AttackStart(hadronox);
                    }
                    break;
                }
                default:
                    break;
            }
            _nextMovement = MOVE_NONE;
        }

        if (!UpdateVictim())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
            DoEvent(eventId);

        DoMeleeAttackIfReady();
    }

    protected:
        EventMap _events;
        InstanceScript* const _instance;

    private:
        Movements _nextMovement;
        uint8 _mySpawn;
};

struct npc_anub_ar_champion : public npc_hadronox_foeAI
{
    npc_anub_ar_champion(Creature* creature) : npc_hadronox_foeAI(creature) { }

    void DoEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_REND:
                DoCastVictim(SPELL_REND);
                _events.Repeat(randtime(Seconds(12), Seconds(16)));
                break;
            case EVENT_PUMMEL:
                DoCastVictim(SPELL_PUMMEL);
                _events.Repeat(randtime(Seconds(12), Seconds(17)));
                break;
            case EVENT_TAUNT:
                DoCastVictim(SPELL_TAUNT);
                _events.Repeat(randtime(Seconds(15), Seconds(50)));
                break;
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_REND, randtime(Seconds(4), Seconds(8)));
        _events.ScheduleEvent(EVENT_PUMMEL, randtime(Seconds(15), Seconds(19)));
        _events.ScheduleEvent(EVENT_TAUNT, randtime(Seconds(15), Seconds(50)));
    }
};

struct npc_anub_ar_crypt_fiend : public npc_hadronox_foeAI
{
    npc_anub_ar_crypt_fiend(Creature* creature) : npc_hadronox_foeAI(creature) { }

    void DoEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_CRUSHING_WEBS:
                DoCastVictim(SPELL_CRUSHING_WEBS);
                _events.Repeat(randtime(Seconds(12), Seconds(16)));
                break;
            case EVENT_INFECTED_WOUND:
                DoCastVictim(SPELL_INFECTED_WOUND);
                _events.Repeat(randtime(Seconds(16), Seconds(25)));
                break;
            case EVENT_TAUNT:
                DoCastVictim(SPELL_TAUNT);
                _events.Repeat(randtime(Seconds(15), Seconds(50)));
                break;
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_CRUSHING_WEBS, randtime(Seconds(4), Seconds(8)));
        _events.ScheduleEvent(EVENT_INFECTED_WOUND, randtime(Seconds(15), Seconds(19)));
        _events.ScheduleEvent(EVENT_TAUNT, randtime(Seconds(15), Seconds(50)));
    }
};

struct npc_anub_ar_necromancer : public npc_hadronox_foeAI
{
    npc_anub_ar_necromancer(Creature* creature) : npc_hadronox_foeAI(creature) { }

    void DoEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_SHADOW_BOLT:
                DoCastVictim(SPELL_SHADOW_BOLT);
                _events.Repeat(randtime(Seconds(2), Seconds(5)));
                break;
            case EVENT_ANIMATE_BONES:
                DoCastVictim(urand(0,1) ? SPELL_ANIMATE_BONES_2 : SPELL_ANIMATE_BONES_1);
                _events.Repeat(randtime(Seconds(35), Seconds(50)));
                break;
            case EVENT_TAUNT:
                DoCastVictim(SPELL_TAUNT);
                _events.Repeat(randtime(Seconds(15), Seconds(50)));
                break;
        }
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_SHADOW_BOLT, randtime(Seconds(2), Seconds(4)));
        _events.ScheduleEvent(EVENT_ANIMATE_BONES, randtime(Seconds(37), Seconds(45)));
        _events.ScheduleEvent(EVENT_TAUNT, randtime(Seconds(15), Seconds(50)));
    }
};

class spell_hadronox_periodic_summon_template_AuraScript : public AuraScript
{
    public:
        spell_hadronox_periodic_summon_template_AuraScript(uint32 topSpellId, uint32 bottomSpellId) : AuraScript(), _topSpellId(topSpellId), _bottomSpellId(bottomSpellId) { }
        PrepareAuraScript(spell_hadronox_periodic_summon_template_AuraScript);

    private:
        bool Validate(SpellInfo const* /*spell*/) override
        {
            return ValidateSpellInfo({ _topSpellId, _bottomSpellId });
        }

        void HandleApply(AuraEffect const* /*eff*/, AuraEffectHandleModes /*mode*/)
        {
            if (AuraEffect* effect = GetAura()->GetEffect(EFFECT_0))
                effect->SetPeriodicTimer(urandms(2, 17));
        }

        void HandlePeriodic(AuraEffect const* /*eff*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;
            InstanceScript* instance = caster->GetInstanceScript();
            if (!instance)
                return;
            if (!instance->instance->HavePlayers())
                return;
            if (instance->GetBossState(DATA_HADRONOX) == DONE)
                GetAura()->Remove();
            else
            {
                if (caster->GetPositionZ() >= 750.0f)
                    caster->CastSpell(caster, _topSpellId, true);
                else
                    caster->CastSpell(caster, _bottomSpellId, true);
            }
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_hadronox_periodic_summon_template_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_hadronox_periodic_summon_template_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }

        uint32 _topSpellId;
        uint32 _bottomSpellId;
};

// 53035 - Summon Anub'ar Champion Periodic
class spell_hadronox_periodic_summon_champion : public SpellScriptLoader
{
    public:
        spell_hadronox_periodic_summon_champion() : SpellScriptLoader("spell_hadronox_periodic_summon_champion") { }

        class spell_hadronox_periodic_summon_champion_AuraScript : public spell_hadronox_periodic_summon_template_AuraScript
        {
            public:
                spell_hadronox_periodic_summon_champion_AuraScript() : spell_hadronox_periodic_summon_template_AuraScript(SPELL_SUMMON_CHAMPION_TOP, SPELL_SUMMON_CHAMPION_BOTTOM) { }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hadronox_periodic_summon_champion_AuraScript();
        }
};

// 53037 - Summon Anub'ar Crypt Fiend Periodic
class spell_hadronox_periodic_summon_crypt_fiend : public SpellScriptLoader
{
    public:
        spell_hadronox_periodic_summon_crypt_fiend() : SpellScriptLoader("spell_hadronox_periodic_summon_crypt_fiend") { }

        class spell_hadronox_periodic_summon_crypt_fiend_AuraScript : public spell_hadronox_periodic_summon_template_AuraScript
        {
            public:
                spell_hadronox_periodic_summon_crypt_fiend_AuraScript() : spell_hadronox_periodic_summon_template_AuraScript(SPELL_SUMMON_CRYPT_FIEND_TOP, SPELL_SUMMON_CRYPT_FIEND_BOTTOM) { }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hadronox_periodic_summon_crypt_fiend_AuraScript();
        }
};

// 53036 - Summon Anub'ar Necromancer Periodic
class spell_hadronox_periodic_summon_necromancer : public SpellScriptLoader
{
    public:
        spell_hadronox_periodic_summon_necromancer() : SpellScriptLoader("spell_hadronox_periodic_summon_necromancer") { }

        class spell_hadronox_periodic_summon_necromancer_AuraScript : public spell_hadronox_periodic_summon_template_AuraScript
        {
            public:
                spell_hadronox_periodic_summon_necromancer_AuraScript() : spell_hadronox_periodic_summon_template_AuraScript(SPELL_SUMMON_NECROMANCER_TOP, SPELL_SUMMON_NECROMANCER_BOTTOM) { }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hadronox_periodic_summon_necromancer_AuraScript();
        }
};

// 53030, 59417 - Leech Poison
class spell_hadronox_leeching_poison : public AuraScript
{
    PrepareAuraScript(spell_hadronox_leeching_poison);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_LEECH_POISON_HEAL });
    }

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEATH)
            return;

        if (GetTarget()->IsGuardian())
            return;

        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_LEECH_POISON_HEAL, true);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_hadronox_leeching_poison::HandleEffectRemove, EFFECT_0, SPELL_AURA_PERIODIC_LEECH, AURA_EFFECT_HANDLE_REAL);
    }
};

// 53177 - Web Front Doors
// 53185 - Web Side Door
class spell_hadronox_web_doors : public SpellScript
{
    PrepareSpellScript(spell_hadronox_web_doors);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_CHAMPION_PERIODIC, SPELL_SUMMON_CRYPT_FIEND_PERIODIC, SPELL_SUMMON_NECROMANCER_PERIODIC });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
        {
            target->RemoveAurasDueToSpell(SPELL_SUMMON_CHAMPION_PERIODIC);
            target->RemoveAurasDueToSpell(SPELL_SUMMON_CRYPT_FIEND_PERIODIC);
            target->RemoveAurasDueToSpell(SPELL_SUMMON_NECROMANCER_PERIODIC);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_hadronox_web_doors::HandleDummy, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

class achievement_hadronox_denied : public AchievementCriteriaScript
{
    public:
        achievement_hadronox_denied() : AchievementCriteriaScript("achievement_hadronox_denied") { }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* cTarget = target->ToCreature())
                if (!cTarget->AI()->GetData(DATA_HADRONOX_WEBBED_DOORS))
                    return true;

            return false;
        }
};

void AddSC_boss_hadronox()
{
    RegisterAzjolNerubCreatureAI(boss_hadronox);

    RegisterAzjolNerubCreatureAI(npc_anub_ar_crusher);
    RegisterAzjolNerubCreatureAI(npc_anub_ar_crusher_champion);
    RegisterAzjolNerubCreatureAI(npc_anub_ar_crusher_crypt_fiend);
    RegisterAzjolNerubCreatureAI(npc_anub_ar_crusher_necromancer);

    RegisterAzjolNerubCreatureAI(npc_anub_ar_champion);
    RegisterAzjolNerubCreatureAI(npc_anub_ar_crypt_fiend);
    RegisterAzjolNerubCreatureAI(npc_anub_ar_necromancer);

    new spell_hadronox_periodic_summon_champion();
    new spell_hadronox_periodic_summon_crypt_fiend();
    new spell_hadronox_periodic_summon_necromancer();

    RegisterSpellScript(spell_hadronox_leeching_poison);
    RegisterSpellScript(spell_hadronox_web_doors);

    new achievement_hadronox_denied();
}

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

#include "naxxramas.h"
#include "CommonHelpers.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "PlayerAI.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum Texts
{
    SAY_AGGRO                                              = 7,
    SAY_SLAY                                               = 8,
    SAY_DEATH                                              = 9,
    SAY_CHAINS                                             = 10,
    SAY_REQUEST_AID                                        = 12, //start of phase 3
    EMOTE_PHASE_TWO                                        = 13,
    SAY_SUMMON_MINIONS                                     = 14, //start of phase 1
    SAY_SPECIAL                                            = 15,

    // The Lich King
    SAY_ANSWER_REQUEST                                     = 3,

    // Guardian of Icecrown
    EMOTE_GUARDIAN_FLEE                                    = 0,
    EMOTE_GUARDIAN_APPEAR                                  = 1
};

enum Events
{
    // phase one
    EVENT_SKELETON = 1,
    EVENT_BANSHEE,
    EVENT_ABOMINATION,
    EVENT_DESPAWN_MINIONS,
    EVENT_PHASE_TWO,

    // phase two
    EVENT_FROSTBOLT_VOLLEY,
    EVENT_SHADOW_FISSURE,
    EVENT_DETONATE_MANA,
    EVENT_FROST_BLAST,
    EVENT_CHAINS,

    // phase three transition
    EVENT_TRANSITION_REPLY,
    EVENT_TRANSITION_SUMMON,
};

enum Actions
{
    ACTION_BEGIN_ENCOUNTER,
    ACTION_JUST_SUMMONED,
    ACTION_ABOMINATION_DIED,
    ACTION_KELTHUZAD_DIED
};

enum KTData
{
    DATA_MINION_POCKET_ID,
    DATA_ABOMINATION_DEATH_COUNT
};

enum Spells
{
    // Kel'thuzad - Phase one
    SPELL_VISUAL_CHANNEL                    = 29423,  // channeled throughout phase one

    // Kel'thuzad - Phase two
    SPELL_FROSTBOLT_SINGLE                  = 28478,
    SPELL_FROSTBOLT_VOLLEY                  = 28479,
    SPELL_SHADOW_FISSURE                    = 27810,
    SPELL_DETONATE_MANA                     = 27819,
    SPELL_MANA_DETONATION_DAMAGE            = 27820,
    SPELL_FROST_BLAST                       = 27808,
    SPELL_FROST_BLAST_DMG                   = 29879,
    SPELL_CHAINS                            = 28410,
    SPELL_CHAINS_DUMMY                      = 28408, // this holds the category cooldown - the main chains spell can't have one as it is cast multiple times

    SPELL_BERSERK                           = 28498,

    // Unstoppable Abomination
    SPELL_MORTAL_WOUND                      = 28467,

    // Guardian of Icecrown
    SPELL_BLOOD_TAP                         = 28470,

    // Shadow Fissure
    SPELL_VOID_BLAST                        = 27812
};

static const uint8 nGuardianSpawns = 4;
static const uint8 nMinionGroups = 7;
enum SummonGroups
{
    SUMMON_GROUP_GUARDIAN_FIRST             = 01 /*..04 */,
    SUMMON_GROUP_MINION_FIRST               = 05 /*..11 */
};
static const std::initializer_list<NAXData64> portalList = { DATA_KELTHUZAD_PORTAL01, DATA_KELTHUZAD_PORTAL02, DATA_KELTHUZAD_PORTAL03, DATA_KELTHUZAD_PORTAL04 };

enum Phases
{
    PHASE_ONE   = 1,
    PHASE_TWO   = 2 // "phase three" is not actually a phase in events, as timers from phase two carry over
};

enum Movements
{
    MOVEMENT_MINION_RANDOM = 1,
};

enum Creatures
{
    NPC_SKELETON1                                           = 16427, // Soldiers of the Frozen Wastes
    NPC_SKELETON2                                           = 23561,
    NPC_ABOMINATION1                                        = 16428, // Unstoppable Abominations
    NPC_ABOMINATION2                                        = 23562,
    NPC_BANSHEE1                                            = 16429, // Soul Weavers
    NPC_BANSHEE2                                            = 23563,
    NPC_GUARDIAN                                            = 16441  // Guardians of Icecrown
};

static const uint8 nMinionSpawnPoints = 7;
static const Position minionSpawnPoints[nMinionSpawnPoints] = {
    { 3768.40f, -5072.00f, 143.65f }, // summon group  5
    { 3729.30f, -5044.10f, 143.65f }, // summon group  6
    { 3683.00f, -5054.05f, 143.65f }, // summon group  7
    { 3654.15f, -5093.48f, 143.65f }, // summon group  8
    { 3664.55f, -5140.50f, 143.65f }, // summon group  9
    { 3704.00f, -5170.00f, 143.65f }, // summon group 10
    { 3751.95f, -5158.90f, 143.65f }  // summon group 11
};
static inline Position const& GetRandomMinionSpawnPoint()
{
    return minionSpawnPoints[urand(0, nMinionSpawnPoints - 1)];
}

// uniformly distribute on the circle
static Position GetRandomPositionOnCircle(Position const& center, float radius)
{
    double angle = rand_norm() * 2.0 * M_PI;
    double relDistance = rand_norm() + rand_norm();
    if (relDistance > 1)
        relDistance = 1 - relDistance;
    return Position(center.GetPositionX() + std::sin(angle)*relDistance*radius, center.GetPositionY() + std::cos(angle)*relDistance*radius, center.GetPositionZ());
}

class KelThuzadCharmedPlayerAI : public SimpleCharmedPlayerAI
{
    public:
        KelThuzadCharmedPlayerAI(Player* player) : SimpleCharmedPlayerAI(player) { }

        struct CharmedPlayerTargetSelectPred
        {
            bool operator()(Unit const* target) const
            {
                Player const* pTarget = target->ToPlayer();
                if (!pTarget)
                    return false;
                if (pTarget->HasAura(SPELL_CHAINS))
                    return false;
                if (pTarget->HasBreakableByDamageCrowdControlAura())
                    return false;
                // We _really_ dislike healers. So we hit them in the face. Repeatedly. Exclusively.
                return Trinity::Helpers::Entity::IsPlayerHealer(pTarget);
            }
        };

        Unit* SelectAttackTarget() const override
        {
            if (Creature* charmer = GetCharmer())
            {
                if (Unit* target = charmer->AI()->SelectTarget(SelectTargetMethod::Random, 0, CharmedPlayerTargetSelectPred()))
                    return target;
                if (Unit* target = charmer->AI()->SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true, true, -SPELL_CHAINS))
                    return target;
            }
            return nullptr;
        }
};

struct ManaUserTargetSelector
{
    bool operator()(Unit const* target) const
    {
        return target->GetTypeId() == TYPEID_PLAYER && target->GetPowerType() == POWER_MANA;
    }
};

struct boss_kelthuzad : public BossAI
{
    public:
        boss_kelthuzad(Creature* creature) : BossAI(creature, BOSS_KELTHUZAD), _skeletonCount(0), _bansheeCount(0), _abominationCount(0), _abominationDeathCount(0), _frostboltCooldown(0), _phaseThree(false), _guardianCount(0)
        {
            for (uint8 i = 0; i < nGuardianSpawns; ++i)
                _guardianGroups[i] = SUMMON_GROUP_GUARDIAN_FIRST + i;
        }

        void Reset() override
        {
            if (!me->IsAlive())
                return;
            _Reset();
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
            me->SetImmuneToPC(true);
            _skeletonCount = 0;
            _bansheeCount = 0;
            _abominationCount = 0;
            _abominationDeathCount = 0;
            _phaseThree = false;
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            if (!me->IsAlive())
                return;

            for (NAXData64 portalData : portalList)
                if (GameObject* portal = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(portalData)))
                    portal->SetGoState(GO_STATE_READY);

            Reset();
            _DespawnAtEvade();
        }

        void JustSummoned (Creature* summon) override
        { // prevent DoZoneInCombat
            summons.Summon(summon);
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) override
        {
            SummonList::iterator it = summons.begin();
            while (it != summons.end())
                if (Creature* cSummon = ObjectAccessor::GetCreature(*me, *it))
                {
                    if (cSummon->IsAlive() && cSummon->GetEntry() == NPC_GUARDIAN)
                    {
                        cSummon->AI()->DoAction(ACTION_KELTHUZAD_DIED);
                        it = summons.erase(it); // prevent them from being despawned by _JustDied
                    }
                    else
                        ++it;
                }

            _JustDied();
            Talk(SAY_DEATH);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
        {
            if (events.IsInPhase(PHASE_ONE))
                damage = 0;
        }

        void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
        {
            if (spellInfo->Id == SPELL_CHAINS_DUMMY)
            {
                Talk(SAY_CHAINS);
                std::list<Unit*> targets;
                SelectTargetList(targets, 3, SelectTargetMethod::Random, 0, 0.0f, true, false);
                for (Unit* target : targets)
                    DoCast(target, SPELL_CHAINS);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (_frostboltCooldown < diff)
                _frostboltCooldown = 0;
            else
                _frostboltCooldown -= diff;

            if (!events.IsInPhase(PHASE_ONE) && me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (!_phaseThree && HealthBelowPct(45))
            {
                _phaseThree = true;
                _guardianCount = 0;
                Talk(SAY_REQUEST_AID);
                events.ScheduleEvent(EVENT_TRANSITION_REPLY, Seconds(4), 0, PHASE_TWO);
                events.ScheduleEvent(EVENT_TRANSITION_SUMMON, randtime(Seconds(7), Seconds(9)), 0, PHASE_TWO);
                events.ScheduleEvent(EVENT_TRANSITION_SUMMON, randtime(Seconds(13), Seconds(15)), 0, PHASE_TWO);
                if (Is25ManRaid())
                {
                    events.ScheduleEvent(EVENT_TRANSITION_SUMMON, randtime(Seconds(19), Seconds(21)), 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_TRANSITION_SUMMON, randtime(Seconds(25), Seconds(27)), 0, PHASE_TWO);
                }
            }

            while (uint32 eventId = events.ExecuteEvent())
            {
                if (_frostboltCooldown <= 4 * IN_MILLISECONDS) // stop casting bolts for 4 seconds after doing another action
                    _frostboltCooldown = 4 * IN_MILLISECONDS;
                switch (eventId)
                {
                    case EVENT_SKELETON:
                    {
                        ++_skeletonCount;
                        if (_skeletonCount == 1) // the first skeleton is actually one of the pre-existing ones - I'm not sure why, but that's what the sniffs say
                        {
                            std::list<Creature*> skeletons;
                            me->GetCreatureListWithEntryInGrid(skeletons, NPC_SKELETON2, 200.0f);
                            if (skeletons.empty())
                            { // prevent UB
                                EnterEvadeMode(EVADE_REASON_OTHER);
                                return;
                            }
                            std::list<Creature*>::iterator it = skeletons.begin();
                            std::advance(it, urand(0, skeletons.size() - 1));
                            (*it)->SetReactState(REACT_AGGRESSIVE);
                            (*it)->AI()->DoZoneInCombat(); // will select a player on our threat list as we are the summoner
                        }
                        else
                        {
                            // retail uses server-side spell 28421 for this
                            Creature* summon = me->SummonCreature(NPC_SKELETON1, GetRandomMinionSpawnPoint(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 2s);
                            summon->AI()->DoZoneInCombat();
                        }

                        uint8 nextTime = 0;
                        if (_skeletonCount < 10)
                            nextTime = 5;
                        else if (_skeletonCount < 19)
                            nextTime = 4;
                        else if (_skeletonCount < 31)
                            nextTime = 3;
                        else if (_skeletonCount == 31)
                            nextTime = 4;
                        else if (_skeletonCount < 72)
                            nextTime = 2;

                        if (nextTime)
                            events.ScheduleEvent(EVENT_SKELETON, Seconds(nextTime), 0, PHASE_ONE);
                        break;
                    }

                    case EVENT_BANSHEE:
                    {
                        ++_bansheeCount;
                        // retail uses server-side spell 28423 for this
                        Creature* summon = me->SummonCreature(NPC_BANSHEE1, GetRandomMinionSpawnPoint(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 2s);
                        summon->AI()->DoZoneInCombat();

                        uint8 nextTime = 0;
                        if (_bansheeCount < 3)
                            nextTime = 30;
                        else if (_bansheeCount < 7)
                            nextTime = 20;
                        else if (_bansheeCount < 9)
                            nextTime = 15;

                        if (nextTime)
                            events.ScheduleEvent(EVENT_BANSHEE, Seconds(nextTime), 0, PHASE_ONE);
                        break;
                    }

                    case EVENT_ABOMINATION:
                    {
                        ++_abominationCount;
                        // retail uses server-side spell 28422 for this
                        Creature* summon = me->SummonCreature(NPC_ABOMINATION1, GetRandomMinionSpawnPoint(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 2s);
                        summon->AI()->DoZoneInCombat();

                        uint8 nextTime = 0;
                        if (_abominationCount < 3)
                            nextTime = 30;
                        else if (_abominationCount < 7)
                            nextTime = 20;
                        else if (_abominationCount < 9)
                            nextTime = 15;

                        if (nextTime)
                            events.ScheduleEvent(EVENT_ABOMINATION, Seconds(nextTime), 0, PHASE_ONE);
                        break;
                    }

                    case EVENT_DESPAWN_MINIONS:
                    {
                        // we need a temp vector, as we can't modify summons while iterating (this would cause UB)
                        std::vector<Creature*> toDespawn;
                        toDespawn.reserve(summons.size());
                        for (ObjectGuid sGuid : summons)
                            if (Creature* summon = ObjectAccessor::GetCreature(*me, sGuid))
                                if (!summon->IsInCombat())
                                    toDespawn.push_back(summon);
                        for (Creature* summon : toDespawn)
                            summon->DespawnOrUnsummon();
                        Talk(SAY_AGGRO);
                        break;
                    }

                    case EVENT_PHASE_TWO:
                        me->CastStop();
                        events.SetPhase(PHASE_TWO);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNINTERACTIBLE);
                        me->SetImmuneToPC(false);
                        ResetThreatList();
                        me->SetReactState(REACT_AGGRESSIVE);
                        Talk(EMOTE_PHASE_TWO);

                        _frostboltCooldown = 2 * IN_MILLISECONDS;
                        events.ScheduleEvent(EVENT_FROSTBOLT_VOLLEY, randtime(Seconds(24), Seconds(28)), 0, PHASE_TWO);
                        events.ScheduleEvent(EVENT_SHADOW_FISSURE, randtime(Seconds(6), Seconds(10)), 0, PHASE_TWO);
                        events.ScheduleEvent(EVENT_DETONATE_MANA, randtime(Seconds(27), Seconds(33)), 0, PHASE_TWO);
                        events.ScheduleEvent(EVENT_FROST_BLAST, randtime(Seconds(25), Seconds(45)), 0, PHASE_TWO);
                        if (Is25ManRaid())
                            events.ScheduleEvent(EVENT_CHAINS, randtime(Seconds(60), Seconds(80)), 0, PHASE_TWO);
                        break;

                    case EVENT_FROSTBOLT_VOLLEY:
                        DoCastAOE(SPELL_FROSTBOLT_VOLLEY);
                        events.Repeat(randtime(Seconds(16), Seconds(18)));
                        break;

                    case EVENT_SHADOW_FISSURE:
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                            DoCast(target, SPELL_SHADOW_FISSURE);
                        events.Repeat(randtime(Seconds(14), Seconds(17)));
                        break;

                    case EVENT_DETONATE_MANA:
                    {
                        ManaUserTargetSelector pred;
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, pred))
                            DoCast(target, SPELL_DETONATE_MANA);
                        events.Repeat(randtime(Seconds(30), Seconds(40)));
                        break;
                    }

                    case EVENT_FROST_BLAST:
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 0.0f, true))
                            DoCast(target, SPELL_FROST_BLAST);
                        events.Repeat(randtime(Seconds(25), Seconds(45)));
                        break;

                    case EVENT_CHAINS:
                    {
                        DoCastAOE(SPELL_CHAINS_DUMMY);
                        events.Repeat(Minutes(1) + randtime(Seconds(0), Seconds(20)));
                        break;
                    }

                    case EVENT_TRANSITION_REPLY:
                        if (Creature* lichKing = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_LICH_KING)))
                            lichKing->AI()->Talk(SAY_ANSWER_REQUEST);
                        for (NAXData64 portalData : portalList)
                            if (GameObject* portal = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(portalData)))
                                portal->SetGoState(GO_STATE_ACTIVE);
                        break;

                    case EVENT_TRANSITION_SUMMON:
                    {
                        uint8 selected = urand(_guardianCount, nGuardianSpawns - 1);
                        if (selected != _guardianCount)
                            std::swap(_guardianGroups[selected], _guardianGroups[_guardianCount]);

                        std::list<TempSummon*> summoned;
                        // server-side spell 28454 is used on retail - no point replicating this in spell_dbc
                        me->SummonCreatureGroup(_guardianGroups[_guardianCount++], &summoned);
                        for (TempSummon* guardian : summoned)
                            guardian->AI()->DoAction(ACTION_JUST_SUMMONED);
                        break;
                    }
                }

                if (!events.IsInPhase(PHASE_ONE) && me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }

            if (!_frostboltCooldown)
            {
                DoCastVictim(SPELL_FROSTBOLT_SINGLE);
                _frostboltCooldown = 3 * IN_MILLISECONDS;
            }
            else
                DoMeleeAttackIfReady();
        }

        uint32 GetData(uint32 data) const override
        {
            if (data == DATA_ABOMINATION_DEATH_COUNT)
                return _abominationDeathCount;
            return 0;
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_BEGIN_ENCOUNTER:
                    if (instance->GetBossState(BOSS_KELTHUZAD) != NOT_STARTED)
                        return;
                    me->SetImmuneToPC(false);
                    instance->SetBossState(BOSS_KELTHUZAD, IN_PROGRESS);
                    events.SetPhase(PHASE_ONE);
                    DoZoneInCombat();
                    DoCastAOE(SPELL_VISUAL_CHANNEL);
                    Talk(SAY_SUMMON_MINIONS);

                    for (uint8 group = SUMMON_GROUP_MINION_FIRST; group < SUMMON_GROUP_MINION_FIRST + nMinionGroups; ++group)
                    {
                        std::list<TempSummon*> summoned;
                        me->SummonCreatureGroup(group, &summoned);
                        for (TempSummon* summon : summoned)
                        {
                            summon->SetReactState(REACT_PASSIVE);
                            summon->AI()->SetData(DATA_MINION_POCKET_ID, group);
                        }
                    }

                    events.ScheduleEvent(EVENT_SKELETON, Seconds(5), 0, PHASE_ONE);
                    events.ScheduleEvent(EVENT_BANSHEE, Seconds(30), 0, PHASE_ONE);
                    events.ScheduleEvent(EVENT_ABOMINATION, Seconds(30), 0, PHASE_ONE);
                    events.ScheduleEvent(EVENT_DESPAWN_MINIONS, Minutes(3) + Seconds(33), 0, PHASE_ONE);
                    events.ScheduleEvent(EVENT_PHASE_TWO, Minutes(3) + Seconds(48), 0, PHASE_ONE);
                    break;

                case ACTION_ABOMINATION_DIED:
                    ++_abominationDeathCount;
                    break;

                default:
                    break;
            }
        }

        PlayerAI* GetAIForCharmedPlayer(Player* player) override
        {
            return new KelThuzadCharmedPlayerAI(player);
        }

    private:
        uint8 _skeletonCount;
        uint8 _bansheeCount;
        uint8 _abominationCount;
        uint8 _abominationDeathCount;
        uint32 _frostboltCooldown;
        bool _phaseThree;
        uint32 _guardianCount;
        std::array<uint32, nGuardianSpawns> _guardianGroups;
};

static const float MINION_AGGRO_DISTANCE = 20.0f;
// @hack the entire _movementTimer logic only exists because RandomMovementGenerator gets really confused due to the unique map geography of KT's room (it's placed on top of a copy of Winterspring).
// As of the time of writing, RMG sometimes selects positions on the "floor" below the room, causing Abominations to path wildly through the room.
// This custom movement code prevents this by simply ignoring z coord calculation (the floor of the minion coves is flat anyway).
// Dev from the future that is reading this, if RMG has been fixed on the current core revision, please get rid of this hack. Thank you!
struct npc_kelthuzad_minionAI : public ScriptedAI
{
    public:
        npc_kelthuzad_minionAI(Creature* creature) : ScriptedAI(creature), instance(creature->GetInstanceScript()), pocketId(0), _movementTimer(urandms(4,12)), _home(me->GetPosition()) { }

        void Reset() override
        {
        }

        void EnterEvadeMode(EvadeReason why) override
        {
            ScriptedAI::EnterEvadeMode(why);
            if (Creature* kelThuzad = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_KELTHUZAD)))
                kelThuzad->AI()->EnterEvadeMode(EVADE_REASON_OTHER);
        }

        void JustEngagedWith(Unit* who) override
        {
            _movementTimer = 0; // once it's zero, it'll never get checked again
            if (!me->HasReactState(REACT_PASSIVE))
            {
                DoZoneInCombat();
                return;
            }

            if (!pocketId)
                return;

            std::list<Creature*> others;
            me->GetCreatureListWithEntryInGrid(others, me->GetEntry(), 80.0f);
            for (Creature* other : others)
                if (other->AI()->GetData(DATA_MINION_POCKET_ID) == pocketId)
                {
                    other->SetReactState(REACT_AGGRESSIVE);
                    other->AI()->AttackStart(who);
                }
            me->SetReactState(REACT_AGGRESSIVE);
            AttackStart(who);
            ScriptedAI::JustEngagedWith(who);
        }

        void AttackStart(Unit* who) override
        {
            ScriptedAI::AttackStart(who);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!me->HasReactState(REACT_PASSIVE))
            {
                ScriptedAI::MoveInLineOfSight(who);
                return;
            }

            if (me->CanStartAttack(who, false) && me->GetDistance2d(who) <= MINION_AGGRO_DISTANCE)
                JustEngagedWith(who);
        }

        void SetData(uint32 data, uint32 value) override
        {
            if (data == DATA_MINION_POCKET_ID)
                pocketId = value;
        }

        uint32 GetData(uint32 data) const override
        {
            if (data == DATA_MINION_POCKET_ID)
                return pocketId;
            return 0;
        }

        void MovementInform(uint32 /*type*/, uint32 id) override
        {
            if (id == MOVEMENT_MINION_RANDOM)
                _movementTimer = urandms(2, 10) + urandms(2, 10);
        }

        void UpdateRandomMovement(uint32 diff)
        {
            if (!_movementTimer)
                return;

            if (_movementTimer <= diff)
            {
                _movementTimer = 0;
                me->GetMotionMaster()->MovePoint(MOVEMENT_MINION_RANDOM, GetRandomPositionOnCircle(_home, 3.0f));
            }
            else
                _movementTimer -= diff;
        }

    protected:
        InstanceScript* const instance;
        uint32 pocketId;

    private:
        uint32 _movementTimer;
        Position const _home;
};

struct npc_kelthuzad_skeleton : public npc_kelthuzad_minionAI
{
    npc_kelthuzad_skeleton(Creature* creature) : npc_kelthuzad_minionAI(creature) { }

    void UpdateAI(uint32 diff) override
    {
        UpdateRandomMovement(diff);

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

struct npc_kelthuzad_banshee : public npc_kelthuzad_minionAI
{
    npc_kelthuzad_banshee(Creature* creature) : npc_kelthuzad_minionAI(creature) { }

    void UpdateAI(uint32 diff) override
    {
        UpdateRandomMovement(diff);

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

struct npc_kelthuzad_abomination : public npc_kelthuzad_minionAI
{
    npc_kelthuzad_abomination(Creature* creature) : npc_kelthuzad_minionAI(creature), _woundTimer(urandms(10, 20)) { }

    void UpdateAI(uint32 diff) override
    {
        UpdateRandomMovement(diff);

        if (!UpdateVictim())
            return;

        if (_woundTimer <= diff)
        {
            _woundTimer = urandms(14, 18);
            DoCastVictim(SPELL_MORTAL_WOUND);
        }
        else
            _woundTimer -= diff;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* killer) override
    {
        if (Creature* kelThuzad = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_KELTHUZAD)))
            kelThuzad->AI()->DoAction(ACTION_ABOMINATION_DIED);
        npc_kelthuzad_minionAI::JustDied(killer);
    }

    uint32 _woundTimer;
};

struct npc_kelthuzad_guardian : public ScriptedAI
{
    public:
        npc_kelthuzad_guardian(Creature* creature) : ScriptedAI(creature), instance(creature->GetInstanceScript()), _visibilityTimer(0), _bloodTapTimer(0) { }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_JUST_SUMMONED:
                    me->SetVisible(false);
                    me->SetHomePosition(me->GetPosition());
                    DoZoneInCombat();
                    me->SetCombatPulseDelay(5);
                    _visibilityTimer =  2 * IN_MILLISECONDS;
                    _bloodTapTimer   = 25 * IN_MILLISECONDS;
                    break;
                case ACTION_KELTHUZAD_DIED:
                    Talk(EMOTE_GUARDIAN_FLEE);
                    me->SetReactState(REACT_PASSIVE);
                    me->RemoveAllAuras();
                    me->CombatStop();
                    me->StopMoving();
                    me->SetImmuneToPC(true);
                    me->DespawnOrUnsummon(30s); // just in case anything interrupts the movement
                    me->GetMotionMaster()->MoveTargetedHome();
                    break;
                default:
                    break;
            }
        }

        void EnterEvadeMode(EvadeReason why) override
        {
            if (Creature* kelthuzad = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_KELTHUZAD)))
                kelthuzad->AI()->EnterEvadeMode();
            ScriptedAI::EnterEvadeMode(why);
        }

        void JustReachedHome() override
        {
            me->DespawnOrUnsummon();
        }

        void Reset() override
        {
            me->SetCombatPulseDelay(0);
            ScriptedAI::Reset();
        }

        void UpdateAI(uint32 diff) override
        {
            if (_visibilityTimer)
            {
                if (diff > _visibilityTimer)
                    _visibilityTimer -= diff;
                else
                {
                    me->SetVisible(true);
                    Talk(EMOTE_GUARDIAN_APPEAR);
                    _visibilityTimer = 0;
                }
            }

            if (!UpdateVictim())
                return;

            if (_bloodTapTimer <= diff)
            {
                DoCastVictim(SPELL_BLOOD_TAP);
                _bloodTapTimer = urandms(18, 26);
            }
            else
                _bloodTapTimer -= diff;

            DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* const instance;
        uint32 _visibilityTimer;
        uint32 _bloodTapTimer;
};

struct npc_kelthuzad_shadow_fissure : public ScriptedAI
{
    npc_kelthuzad_shadow_fissure(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        _scheduler.Schedule(5s, [this](TaskContext /*task*/)
        {
            DoCastSelf(SPELL_VOID_BLAST);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 28410 - Chains of Kel'Thuzad
class spell_kelthuzad_chains : public AuraScript
{
    PrepareAuraScript(spell_kelthuzad_chains);

    void HandleApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
    {
        aurEff->HandleAuraModScale(GetTargetApplication(), mode, true);
    }

    void HandleRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
    {
        aurEff->HandleAuraModScale(GetTargetApplication(), mode, false);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_kelthuzad_chains::HandleApply, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectApplyFn(spell_kelthuzad_chains::HandleRemove, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 27819 - Detonate Mana
class spell_kelthuzad_detonate_mana : public AuraScript
{
    PrepareAuraScript(spell_kelthuzad_detonate_mana);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_MANA_DETONATION_DAMAGE });
    }

    void HandleScript(AuraEffect const* aurEff)
    {
        PreventDefaultAction();

        Unit* target = GetTarget();
        if (int32 mana = int32(target->GetMaxPower(POWER_MANA) / 10))
        {
            mana = target->ModifyPower(POWER_MANA, -mana);
            CastSpellExtraArgs args(aurEff);
            args.AddSpellBP0(-mana * 10);
            target->CastSpell(target, SPELL_MANA_DETONATION_DAMAGE, args);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_kelthuzad_detonate_mana::HandleScript, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 27808 - Frost Blast
class spell_kelthuzad_frost_blast : public AuraScript
{
    PrepareAuraScript(spell_kelthuzad_frost_blast);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FROST_BLAST_DMG });
    }

    void PeriodicTick(AuraEffect const* aurEff)
    {
        PreventDefaultAction();

        // Stuns the target, dealing 26% of the target's maximum health in Frost damage every second for 4 sec.
        if (Unit* caster = GetCaster())
        {
            CastSpellExtraArgs args(aurEff);
            args.AddSpellBP0(GetTarget()->CountPctFromMaxHealth(26));
            caster->CastSpell(GetTarget(), SPELL_FROST_BLAST_DMG, args);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_kelthuzad_frost_blast::PeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class at_kelthuzad_center : public AreaTriggerScript
{
public:
    at_kelthuzad_center() : AreaTriggerScript("at_kelthuzad_center") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*at*/) override
    {
        InstanceScript* instance = player->GetInstanceScript();
        if (!instance || instance->GetBossState(BOSS_KELTHUZAD) != NOT_STARTED)
            return true;

        if (player->IsGameMaster())
            return true;

        Creature* kelThuzad = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_KELTHUZAD));
        if (!kelThuzad)
            return true;

        kelThuzad->AI()->DoAction(ACTION_BEGIN_ENCOUNTER);

        return true;
    }
};

class achievement_just_cant_get_enough : public AchievementCriteriaScript
{
   public:
        achievement_just_cant_get_enough() : AchievementCriteriaScript("achievement_just_cant_get_enough") { }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (InstanceScript* instance = target->GetInstanceScript())
                if (Creature* kelThuzad = ObjectAccessor::GetCreature(*target, instance->GetGuidData(DATA_KELTHUZAD)))
                    if (kelThuzad->AI()->GetData(DATA_ABOMINATION_DEATH_COUNT) >= 18)
                        return true;

            return false;
        }
};

void AddSC_boss_kelthuzad()
{
    RegisterNaxxramasCreatureAI(boss_kelthuzad);
    RegisterNaxxramasCreatureAI(npc_kelthuzad_skeleton);
    RegisterNaxxramasCreatureAI(npc_kelthuzad_banshee);
    RegisterNaxxramasCreatureAI(npc_kelthuzad_abomination);
    RegisterNaxxramasCreatureAI(npc_kelthuzad_guardian);
    RegisterNaxxramasCreatureAI(npc_kelthuzad_shadow_fissure);
    RegisterSpellScript(spell_kelthuzad_chains);
    RegisterSpellScript(spell_kelthuzad_detonate_mana);
    RegisterSpellScript(spell_kelthuzad_frost_blast);
    new at_kelthuzad_center();
    new achievement_just_cant_get_enough();
}

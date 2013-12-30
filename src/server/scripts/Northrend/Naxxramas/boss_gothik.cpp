/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "SpellScript.h"
#include "GridNotifiers.h"
#include "CombatAI.h"
#include "naxxramas.h"

enum Yells
{
    SAY_SPEECH                  = 0,
    SAY_KILL                    = 1,
    SAY_DEATH                   = 2,
    SAY_TELEPORT                = 3
};

//Gothik
enum Spells
{
    SPELL_HARVEST_SOUL          = 28679,
    SPELL_SHADOW_BOLT           = 29317,
    H_SPELL_SHADOW_BOLT         = 56405,
    SPELL_INFORM_LIVE_TRAINEE   = 27892,
    SPELL_INFORM_LIVE_KNIGHT    = 27928,
    SPELL_INFORM_LIVE_RIDER     = 27935,
    SPELL_INFORM_DEAD_TRAINEE   = 27915,
    SPELL_INFORM_DEAD_KNIGHT    = 27931,
    SPELL_INFORM_DEAD_RIDER     = 27937,

    SPELL_SHADOW_MARK           = 27825
};

enum Creatures
{
    NPC_LIVE_TRAINEE    = 16124,
    NPC_LIVE_KNIGHT     = 16125,
    NPC_LIVE_RIDER      = 16126,
    NPC_DEAD_TRAINEE    = 16127,
    NPC_DEAD_KNIGHT     = 16148,
    NPC_DEAD_RIDER      = 16150,
    NPC_DEAD_HORSE      = 16149
};

struct Waves { uint32 entry, time, mode; };
// wave setups are not the same in heroic and normal difficulty,
// mode is 0 only normal, 1 both and 2 only heroic
// but this is handled in DoGothikSummon function
const Waves waves[] =
{
    {NPC_LIVE_TRAINEE, 20000, 1},
    {NPC_LIVE_TRAINEE, 20000, 1},
    {NPC_LIVE_TRAINEE, 10000, 1},
    {NPC_LIVE_KNIGHT, 10000, 1},
    {NPC_LIVE_TRAINEE, 15000, 1},
    {NPC_LIVE_KNIGHT, 5000, 1},
    {NPC_LIVE_TRAINEE, 20000, 1},
    {NPC_LIVE_TRAINEE, 0, 1},
    {NPC_LIVE_KNIGHT, 10000, 1},
    {NPC_LIVE_TRAINEE, 10000, 2},
    {NPC_LIVE_RIDER, 10000, 0},
    {NPC_LIVE_RIDER, 5000, 2},
    {NPC_LIVE_TRAINEE, 5000, 0},
    {NPC_LIVE_TRAINEE, 15000, 2},
    {NPC_LIVE_KNIGHT, 15000, 0},
    {NPC_LIVE_TRAINEE, 0, 0},
    {NPC_LIVE_RIDER, 10000, 1},
    {NPC_LIVE_KNIGHT, 10000, 1},
    {NPC_LIVE_TRAINEE, 10000, 0},
    {NPC_LIVE_RIDER, 10000, 2},
    {NPC_LIVE_TRAINEE, 0, 2},
    {NPC_LIVE_RIDER, 5000, 1},
    {NPC_LIVE_TRAINEE, 0, 2},
    {NPC_LIVE_KNIGHT, 5000, 1},
    {NPC_LIVE_RIDER, 0, 2},
    {NPC_LIVE_TRAINEE, 20000, 1},
    {NPC_LIVE_RIDER, 0, 1},
    {NPC_LIVE_KNIGHT, 0, 1},
    {NPC_LIVE_TRAINEE, 25000, 2},
    {NPC_LIVE_TRAINEE, 15000, 0},
    {NPC_LIVE_TRAINEE, 25000, 0},
    {0, 0, 1},
};

#define POS_Y_GATE  -3360.78f
#define POS_Y_WEST  -3285.0f
#define POS_Y_EAST  -3434.0f
#define POS_X_NORTH  2750.49f
#define POS_X_SOUTH  2633.84f

#define IN_LIVE_SIDE(who) (who->GetPositionY() < POS_Y_GATE)

enum Events
{
    EVENT_NONE,
    EVENT_SUMMON,
    EVENT_HARVEST,
    EVENT_BOLT,
    EVENT_TELEPORT
};
enum Pos
{
   POS_LIVE = 6,
   POS_DEAD = 5
};

const Position PosSummonLive[POS_LIVE] =
{
    {2669.7f, -3428.76f, 268.56f, 1.6f},
    {2692.1f, -3428.76f, 268.56f, 1.6f},
    {2714.4f, -3428.76f, 268.56f, 1.6f},
    {2669.7f, -3431.67f, 268.56f, 1.6f},
    {2692.1f, -3431.67f, 268.56f, 1.6f},
    {2714.4f, -3431.67f, 268.56f, 1.6f},
};

const Position PosSummonDead[POS_DEAD] =
{
    {2725.1f, -3310.0f, 268.85f, 3.4f},
    {2699.3f, -3322.8f, 268.60f, 3.3f},
    {2733.1f, -3348.5f, 268.84f, 3.1f},
    {2682.8f, -3304.2f, 268.85f, 3.9f},
    {2664.8f, -3340.7f, 268.23f, 3.7f},
};

float const PosGroundLiveSide[4] = {2691.2f, -3387.0f, 267.68f, 1.52f};
float const PosGroundDeadSide[4] = {2693.5f, -3334.6f, 267.68f, 4.67f};
float const PosPlatform[4] = {2640.5f, -3360.6f, 285.26f, 0.0f};

// Predicate function to check that the r   efzr unit is NOT on the same side as the source.
struct NotOnSameSide : public std::unary_function<Unit*, bool>
{
    NotOnSameSide(Unit* source) : _onLiveSide(IN_LIVE_SIDE(source)) { }

    bool operator() (Unit const* target)
    {
        return (_onLiveSide != IN_LIVE_SIDE(target));
    }

    private:
        bool _onLiveSide;
};

class boss_gothik : public CreatureScript
{
    public:
        boss_gothik() : CreatureScript("boss_gothik") { }

        struct boss_gothikAI : public BossAI
        {
            boss_gothikAI(Creature* creature) : BossAI(creature, BOSS_GOTHIK) { }

            uint32 waveCount;
            typedef std::vector<Creature*> TriggerVct;
            TriggerVct liveTrigger, deadTrigger;
            bool mergedSides;
            bool phaseTwo;
            bool thirtyPercentReached;

            std::vector<uint64> LiveTriggerGUID;
            std::vector<uint64> DeadTriggerGUID;

            void Reset() OVERRIDE
            {
                LiveTriggerGUID.clear();
                DeadTriggerGUID.clear();

                me->SetReactState(REACT_PASSIVE);
                instance->SetData(DATA_GOTHIK_GATE, GO_STATE_ACTIVE);
                _Reset();
                mergedSides = false;
                phaseTwo = false;
                thirtyPercentReached = false;
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                for (uint32 i = 0; i < POS_LIVE; ++i)
                    if (Creature* trigger = DoSummon(WORLD_TRIGGER, PosSummonLive[i]))
                        LiveTriggerGUID.push_back(trigger->GetGUID());
                for (uint32 i = 0; i < POS_DEAD; ++i)
                    if (Creature* trigger = DoSummon(WORLD_TRIGGER, PosSummonDead[i]))
                        DeadTriggerGUID.push_back(trigger->GetGUID());

                if (LiveTriggerGUID.size() < POS_LIVE || DeadTriggerGUID.size() < POS_DEAD)
                {
                    TC_LOG_ERROR("scripts", "Script Gothik: cannot summon triggers!");
                    EnterEvadeMode();
                    return;
                }

                _EnterCombat();
                waveCount = 0;
                events.ScheduleEvent(EVENT_SUMMON, 30000);
                DoTeleportTo(PosPlatform);
                Talk(SAY_SPEECH);
                instance->SetData(DATA_GOTHIK_GATE, GO_STATE_READY);
            }

            void JustSummoned(Creature* summon) OVERRIDE
            {
                if (summon->GetEntry() == WORLD_TRIGGER)
                    summon->setActive(true);
                else if (!mergedSides)
                {
                    summon->AI()->DoAction(me->HasReactState(REACT_PASSIVE) ? 1 : 0);
                    summon->AI()->EnterEvadeMode();
                }
                else
                {
                    summon->AI()->DoAction(0);
                    summon->AI()->DoZoneInCombat();
                }
                summons.Summon(summon);
            }

            void SummonedCreatureDespawn(Creature* summon) OVERRIDE
            {
                summons.Despawn(summon);
            }

            void KilledUnit(Unit* /*victim*/) OVERRIDE
            {
                if (!(rand()%5))
                    Talk(SAY_KILL);
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                LiveTriggerGUID.clear();
                DeadTriggerGUID.clear();
                _JustDied();
                Talk(SAY_DEATH);
                instance->SetData(DATA_GOTHIK_GATE, GO_STATE_ACTIVE);
            }

            void DoGothikSummon(uint32 entry)
            {
                if (GetDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL)
                {
                    switch (entry)
                    {
                        case NPC_LIVE_TRAINEE:
                        {
                            if (Creature* liveTrigger = Unit::GetCreature(*me, LiveTriggerGUID[0]))
                                DoSummon(NPC_LIVE_TRAINEE, liveTrigger, 1);
                            if (Creature* liveTrigger1 = Unit::GetCreature(*me, LiveTriggerGUID[1]))
                                DoSummon(NPC_LIVE_TRAINEE, liveTrigger1, 1);
                            if (Creature* liveTrigger2 = Unit::GetCreature(*me, LiveTriggerGUID[2]))
                                DoSummon(NPC_LIVE_TRAINEE, liveTrigger2, 1);
                            break;
                        }
                        case NPC_LIVE_KNIGHT:
                        {
                            if (Creature* liveTrigger3 = Unit::GetCreature(*me, LiveTriggerGUID[3]))
                                DoSummon(NPC_LIVE_KNIGHT, liveTrigger3, 1);
                            if (Creature* liveTrigger5 = Unit::GetCreature(*me, LiveTriggerGUID[5]))
                                DoSummon(NPC_LIVE_KNIGHT, liveTrigger5, 1);
                            break;
                        }
                        case NPC_LIVE_RIDER:
                        {
                            if (Creature* liveTrigger4 = Unit::GetCreature(*me, LiveTriggerGUID[4]))
                                DoSummon(NPC_LIVE_RIDER, liveTrigger4, 1);
                            break;
                        }
                    }
                }
                else
                {
                    switch (entry)
                    {
                        case NPC_LIVE_TRAINEE:
                        {
                            if (Creature* liveTrigger = Unit::GetCreature(*me, LiveTriggerGUID[4]))
                                DoSummon(NPC_LIVE_TRAINEE, liveTrigger, 1);
                            if (Creature* liveTrigger2 = Unit::GetCreature(*me, LiveTriggerGUID[4]))
                                DoSummon(NPC_LIVE_TRAINEE, liveTrigger2, 1);
                            break;
                        }
                        case NPC_LIVE_KNIGHT:
                        {
                            if (Creature* liveTrigger5 = Unit::GetCreature(*me, LiveTriggerGUID[4]))
                                DoSummon(NPC_LIVE_KNIGHT, liveTrigger5, 1);
                            break;
                        }
                        case NPC_LIVE_RIDER:
                        {
                            if (Creature* liveTrigger4 = Unit::GetCreature(*me, LiveTriggerGUID[4]))
                                DoSummon(NPC_LIVE_RIDER, liveTrigger4, 1);
                            break;
                        }
                    }
                }
            }

            bool CheckGroupSplitted()
            {
                Map* map = me->GetMap();
                if (map && map->IsDungeon())
                {
                    Map::PlayerList const &PlayerList = map->GetPlayers();
                    if (!PlayerList.isEmpty())
                    {
                        bool checklife = false;
                        bool checkdead = false;
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        {
                            if (i->GetSource() && i->GetSource()->IsAlive() &&
                                i->GetSource()->GetPositionX() <= POS_X_NORTH &&
                                i->GetSource()->GetPositionX() >= POS_X_SOUTH &&
                                i->GetSource()->GetPositionY() <= POS_Y_GATE &&
                                i->GetSource()->GetPositionY() >= POS_Y_EAST)
                            {
                                checklife = true;
                            }
                            else if (i->GetSource() && i->GetSource()->IsAlive() &&
                                i->GetSource()->GetPositionX() <= POS_X_NORTH &&
                                i->GetSource()->GetPositionX() >= POS_X_SOUTH &&
                                i->GetSource()->GetPositionY() >= POS_Y_GATE &&
                                i->GetSource()->GetPositionY() <= POS_Y_WEST)
                            {
                                checkdead = true;
                            }

                            if (checklife && checkdead)
                                return true;
                        }
                    }
                }

                return false;
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell) OVERRIDE
            {
                uint32 spellId = 0;
                switch (spell->Id)
                {
                    case SPELL_INFORM_LIVE_TRAINEE: spellId = SPELL_INFORM_DEAD_TRAINEE;    break;
                    case SPELL_INFORM_LIVE_KNIGHT:  spellId = SPELL_INFORM_DEAD_KNIGHT;     break;
                    case SPELL_INFORM_LIVE_RIDER:   spellId = SPELL_INFORM_DEAD_RIDER;      break;
                }
                if (spellId && me->IsInCombat())
                {
                    me->HandleEmoteCommand(EMOTE_ONESHOT_SPELL_CAST);
                    if (Creature* pRandomDeadTrigger = Unit::GetCreature(*me, DeadTriggerGUID[rand() % POS_DEAD]))
                        me->CastSpell(pRandomDeadTrigger, spellId, true);
                }
            }

            void DamageTaken(Unit* /*who*/, uint32& damage) OVERRIDE
            {
                if (!phaseTwo)
                    damage = 0;
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell) OVERRIDE
            {
                if (!me->IsInCombat())
                    return;

                switch (spell->Id)
                {
                    case SPELL_INFORM_DEAD_TRAINEE:
                        DoSummon(NPC_DEAD_TRAINEE, target, 0);
                        break;
                    case SPELL_INFORM_DEAD_KNIGHT:
                        DoSummon(NPC_DEAD_KNIGHT, target, 0);
                        break;
                    case SPELL_INFORM_DEAD_RIDER:
                        DoSummon(NPC_DEAD_RIDER, target, 1.0f);
                        DoSummon(NPC_DEAD_HORSE, target, 1.0f);
                        break;
                }
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!UpdateVictim() || !CheckInRoom())
                    return;

                events.Update(diff);

                if (!thirtyPercentReached && HealthBelowPct(30) && phaseTwo)
                {
                    thirtyPercentReached = true;
                    instance->SetData(DATA_GOTHIK_GATE, GO_STATE_ACTIVE);
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUMMON:
                            if (waves[waveCount].entry)
                            {
                                if ((waves[waveCount].mode == 2) && (GetDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL))
                                   DoGothikSummon(waves[waveCount].entry);
                                else if ((waves[waveCount].mode == 0) && (GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL))
                                    DoGothikSummon(waves[waveCount].entry);
                                else if (waves[waveCount].mode == 1)
                                    DoGothikSummon(waves[waveCount].entry);

                                // if group is not splitted, open gate and merge both sides at ~ 2 minutes (wave 11)
                                if (waveCount == 11)
                                {
                                    if (!CheckGroupSplitted())
                                    {
                                        instance->SetData(DATA_GOTHIK_GATE, GO_STATE_ACTIVE);
                                        DummyEntryCheckPredicate pred;
                                        summons.DoAction(0, pred);  //! Magic numbers fail
                                        summons.DoZoneInCombat();
                                        mergedSides = true;
                                    }
                                }

                                if (waves[waveCount].mode == 1)
                                    events.ScheduleEvent(EVENT_SUMMON, waves[waveCount].time);
                                else if ((waves[waveCount].mode == 2) && (GetDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL))
                                    events.ScheduleEvent(EVENT_SUMMON, waves[waveCount].time);
                                else if ((waves[waveCount].mode == 0) && (GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL))
                                    events.ScheduleEvent(EVENT_SUMMON, waves[waveCount].time);
                                else
                                    events.ScheduleEvent(EVENT_SUMMON, 0);

                                ++waveCount;
                            }
                            else
                            {
                                phaseTwo = true;
                                Talk(SAY_TELEPORT);
                                DoTeleportTo(PosGroundLiveSide);
                                me->SetReactState(REACT_AGGRESSIVE);
                                DummyEntryCheckPredicate pred;
                                summons.DoAction(0, pred);  //! Magic numbers fail
                                summons.DoZoneInCombat();
                                events.ScheduleEvent(EVENT_BOLT, 1000);
                                events.ScheduleEvent(EVENT_HARVEST, urand(3000, 15000));
                                events.ScheduleEvent(EVENT_TELEPORT, 20000);
                            }
                            break;
                        case EVENT_BOLT:
                            DoCastVictim(RAID_MODE(SPELL_SHADOW_BOLT, H_SPELL_SHADOW_BOLT));
                            events.ScheduleEvent(EVENT_BOLT, 1000);
                            break;
                        case EVENT_HARVEST:
                            DoCastVictim(SPELL_HARVEST_SOUL, true);
                            events.ScheduleEvent(EVENT_HARVEST, urand(20000, 25000));
                            break;
                        case EVENT_TELEPORT:
                            if (!thirtyPercentReached)
                            {
                                me->AttackStop();
                                if (IN_LIVE_SIDE(me))
                                    DoTeleportTo(PosGroundDeadSide);
                                else
                                    DoTeleportTo(PosGroundLiveSide);

                                me->getThreatManager().resetAggro(NotOnSameSide(me));
                                if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0))
                                {
                                    me->getThreatManager().addThreat(target, 100.0f);
                                    AttackStart(target);
                                }

                                events.ScheduleEvent(EVENT_TELEPORT, 20000);
                            }
                            break;
                    }
                }

                if (!phaseTwo)
                    DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<boss_gothikAI>(creature);
        }
};

class npc_gothik_minion : public CreatureScript
{
    public:
        npc_gothik_minion() : CreatureScript("npc_gothik_minion") { }

        struct npc_gothik_minionAI : public CombatAI
        {
            npc_gothik_minionAI(Creature* creature) : CombatAI(creature)
            {
                liveSide = IN_LIVE_SIDE(me);
                gateClose = false;
            }

            bool liveSide;
            bool gateClose;

            bool isOnSameSide(Unit const* who) const
            {
                return (liveSide == IN_LIVE_SIDE(who));
            }

            void DoAction(int32 param) OVERRIDE
            {
                gateClose = param;
            }

            void DamageTaken(Unit* attacker, uint32 &damage) OVERRIDE
            {
                if (gateClose && !isOnSameSide(attacker))
                    damage = 0;
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                if (me->IsSummon())
                    if (Unit* owner = me->ToTempSummon()->GetSummoner())
                        CombatAI::JustDied(owner);
            }

            void EnterEvadeMode() OVERRIDE
            {
                if (!gateClose)
                {
                    CombatAI::EnterEvadeMode();
                    return;
                }

                if (!_EnterEvadeMode())
                    return;

                Map* map = me->GetMap();
                if (map->IsDungeon())
                {
                    Map::PlayerList const &PlayerList = map->GetPlayers();
                    if (!PlayerList.isEmpty())
                    {
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        {
                            if (i->GetSource() && i->GetSource()->IsAlive() && isOnSameSide(i->GetSource()))
                            {
                                AttackStart(i->GetSource());
                                return;
                            }
                        }
                    }
                }

                me->GetMotionMaster()->MoveIdle();
                Reset();
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (gateClose && (!isOnSameSide(me) || (me->GetVictim() && !isOnSameSide(me->GetVictim()))))
                {
                    EnterEvadeMode();
                    return;
                }

                CombatAI::UpdateAI(diff);
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new npc_gothik_minionAI(creature);
        }
};

class spell_gothik_shadow_bolt_volley : public SpellScriptLoader
{
    public:
        spell_gothik_shadow_bolt_volley() : SpellScriptLoader("spell_gothik_shadow_bolt_volley") { }

        class spell_gothik_shadow_bolt_volley_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_gothik_shadow_bolt_volley_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(Trinity::UnitAuraCheck(false, SPELL_SHADOW_MARK));
            }

            void Register() OVERRIDE
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_gothik_shadow_bolt_volley_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_gothik_shadow_bolt_volley_SpellScript();
        }
};

void AddSC_boss_gothik()
{
    new boss_gothik();
    new npc_gothik_minion();
    new spell_gothik_shadow_bolt_volley();
}

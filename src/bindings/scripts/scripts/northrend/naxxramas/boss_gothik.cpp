/* Copyright (C) 2008 - 2009 Trinity <http://www.trinitycore.org/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "precompiled.h"
#include "naxxramas.h"
#include "spellId.h"

enum Yells
{
    SAY_SPEECH                  = -1533040,
    SAY_KILL                    = -1533041,
    SAY_DEATH                   = -1533042,
    SAY_TELEPORT                = -1533043
};
//Gothik
enum Spells
{
    SPELL_HARVEST_SOUL          = SPELL_HARVEST_SOUL_28679,
    SPELL_SHADOW_BOLT           = SPELL_SHADOW_BOLT_29317,
    H_SPELL_SHADOW_BOLT         = SPELL_SHADOW_BOLT_56405,
    SPELL_INFORM_LIVE_TRAINEE   = SPELL_TO_ANCHOR_1_27892,
    SPELL_INFORM_LIVE_KNIGHT    = SPELL_TO_ANCHOR_1_27928,
    SPELL_INFORM_LIVE_RIDER     = SPELL_TO_ANCHOR_1_27935,
    SPELL_INFORM_DEAD_TRAINEE   = SPELL_ANCHOR_TO_SKULLS_27915,
    SPELL_INFORM_DEAD_KNIGHT    = SPELL_ANCHOR_TO_SKULLS_27931,
    SPELL_INFORM_DEAD_RIDER     = SPELL_ANCHOR_TO_SKULLS_27937
};
enum Creatures
{
    MOB_LIVE_TRAINEE    = 16124,
    MOB_LIVE_KNIGHT     = 16125,
    MOB_LIVE_RIDER      = 16126,
    MOB_DEAD_TRAINEE    = 16127,
    MOB_DEAD_KNIGHT     = 16148,
    MOB_DEAD_RIDER      = 16150,
    MOB_DEAD_HORSE      = 16149
};

struct Waves { uint32 entry, time; };
// wave setups are the same in heroic and normal difficulty, only count of mobs is different, 
// but this is handled in DoGothikSummon function
const Waves waves[] =
{
    {MOB_LIVE_TRAINEE, 20000},
    {MOB_LIVE_TRAINEE, 20000},
    {MOB_LIVE_TRAINEE, 10000},
    {MOB_LIVE_KNIGHT, 10000},
    {MOB_LIVE_TRAINEE, 15000},
    {MOB_LIVE_KNIGHT, 5000},
    {MOB_LIVE_TRAINEE, 20000},
    {MOB_LIVE_TRAINEE, 0},
    {MOB_LIVE_KNIGHT, 10000},
    {MOB_LIVE_RIDER, 10000},
    {MOB_LIVE_TRAINEE, 5000},
    {MOB_LIVE_KNIGHT, 15000},
    {MOB_LIVE_RIDER, 0},
    {MOB_LIVE_TRAINEE, 10000},
    {MOB_LIVE_KNIGHT, 10000},
    {MOB_LIVE_TRAINEE, 10000},
    {MOB_LIVE_RIDER, 5000},
    {MOB_LIVE_KNIGHT, 5000},
    {MOB_LIVE_TRAINEE, 20000},
    {MOB_LIVE_RIDER, 0},
    {MOB_LIVE_KNIGHT, 0},
    {MOB_LIVE_TRAINEE, 20000},
    {MOB_LIVE_TRAINEE, 25000},
    {0, 0},
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
    {2669.7, -3428.76, 268.56, 1.6},
    {2692.1, -3428.76, 268.56, 1.6},
    {2714.4, -3428.76, 268.56, 1.6},
    {2669.7, -3431.67, 268.56, 1.6},
    {2692.1, -3431.67, 268.56, 1.6},
    {2714.4, -3431.67, 268.56, 1.6},
};

const Position PosSummonDead[POS_DEAD] =
{
    {2725.1, -3310.0, 268.85, 3.4},
    {2699.3, -3322.8, 268.60, 3.3},
    {2733.1, -3348.5, 268.84, 3.1},
    {2682.8, -3304.2, 268.85, 3.9},
    {2664.8, -3340.7, 268.23, 3.7},
};

const float PosGroundLiveSide[4] = {2691.2, -3387.0, 267.68, 1.52};
const float PosGroundDeadSide[4] = {2693.5, -3334.6, 267.68, 4.67};
const float PosPlatform[4] = {2640.5, -3360.6, 285.26, 0};

// Predicate function to check that the r   efzr unit is NOT on the same side as the source.
struct NotOnSameSide : public std::unary_function<Unit *, bool> {
    bool m_inLiveSide;
    NotOnSameSide(Unit *pSource) : m_inLiveSide(IN_LIVE_SIDE(pSource)) {}
    bool operator() (const Unit *pTarget) {
      return (m_inLiveSide != IN_LIVE_SIDE(pTarget));
    }
};

struct TRINITY_DLL_DECL boss_gothikAI : public BossAI
{
    boss_gothikAI(Creature *c) : BossAI(c, BOSS_GOTHIK) {}

    uint32 waveCount;
    typedef std::vector<Creature*> TriggerVct;
    TriggerVct liveTrigger, deadTrigger;
    bool mergedSides;
    bool phaseTwo;
    bool thirtyPercentReached;

    void Reset()
    {
        liveTrigger.clear();
        deadTrigger.clear();
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_DISABLE_MOVE);
        me->SetReactState(REACT_PASSIVE);
        if (instance)
            instance->SetData(DATA_GOTHIK_GATE, GO_STATE_ACTIVE);
        _Reset();
        mergedSides = false;
        phaseTwo = false;
        thirtyPercentReached = false;
    }

    void EnterCombat(Unit *who)
    {
        for (uint32 i = 0; i < POS_LIVE; ++i)
            if (Creature *trigger = DoSummon(WORLD_TRIGGER, PosSummonLive[i]))
                liveTrigger.push_back(trigger);
        for (uint32 i = 0; i < POS_DEAD; ++i)
            if (Creature *trigger = DoSummon(WORLD_TRIGGER, PosSummonDead[i]))
                deadTrigger.push_back(trigger);

        if (liveTrigger.size() < POS_LIVE || deadTrigger.size() < POS_DEAD)
        {
            error_log("Script Gothik: cannot summon triggers!");
            EnterEvadeMode();
            return;
        }

        _EnterCombat();
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE|UNIT_FLAG_DISABLE_MOVE);
        waveCount = 0;
        events.ScheduleEvent(EVENT_SUMMON, 30000);
        DoTeleportTo(PosPlatform);
        DoScriptText(SAY_SPEECH, me);
        if (instance)
            instance->SetData(DATA_GOTHIK_GATE, GO_STATE_READY);
    }

    void JustSummoned(Creature *summon)
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

    void SummonedCreatureDespawn(Creature *summon)
    {
        summons.Despawn(summon);
    }

    void KilledUnit(Unit* victim)
    {
        if (!(rand()%5))
            DoScriptText(SAY_KILL, me);
    }

    void JustDied(Unit* Killer)
    {
        liveTrigger.clear();
        deadTrigger.clear();
        _JustDied();
        DoScriptText(SAY_DEATH, me);
        if (instance)
            instance->SetData(DATA_GOTHIK_GATE, GO_STATE_ACTIVE);
    }

    void DoGothikSummon(uint32 entry)
    {
        if (getDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL)
        {
            switch(entry)
            {
                case MOB_LIVE_TRAINEE:
                    DoSummon(MOB_LIVE_TRAINEE, liveTrigger[0], 1);
                    DoSummon(MOB_LIVE_TRAINEE, liveTrigger[1], 1);
                    DoSummon(MOB_LIVE_TRAINEE, liveTrigger[2], 1);
                    break;
                case MOB_LIVE_KNIGHT:
                    DoSummon(MOB_LIVE_KNIGHT, liveTrigger[3], 1);
                    DoSummon(MOB_LIVE_KNIGHT, liveTrigger[5], 1);
                    break;
                case MOB_LIVE_RIDER:
                    DoSummon(MOB_LIVE_RIDER, liveTrigger[4], 1);
                    break;
            }
        }
        else
        {
            switch(entry)
            {
                case MOB_LIVE_TRAINEE:
                    DoSummon(MOB_LIVE_TRAINEE, liveTrigger[0], 1);
                    DoSummon(MOB_LIVE_TRAINEE, liveTrigger[1], 1);
                    break;
                case MOB_LIVE_KNIGHT:
                    DoSummon(MOB_LIVE_KNIGHT, liveTrigger[5], 1);
                    break;
                case MOB_LIVE_RIDER:
                    DoSummon(MOB_LIVE_RIDER, liveTrigger[4], 1);
                    break;
            }
        }
    }

    bool CheckGroupSplitted()
    {
        bool checklife = false;
        bool checkdead = false;

        Map* pMap = me->GetMap();
        if (pMap && pMap->IsDungeon())
        {
            Map::PlayerList const &PlayerList = pMap->GetPlayers();
            if (!PlayerList.isEmpty())
            {
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                {
                    if (i->getSource() && i->getSource()->isAlive() &&
                        i->getSource()->GetPositionX() <= POS_X_NORTH &&
                        i->getSource()->GetPositionX() >= POS_X_SOUTH &&
                        i->getSource()->GetPositionY() <= POS_Y_GATE &&
                        i->getSource()->GetPositionY() >= POS_Y_EAST)
                    {
                        checklife = true;
                    }
                    else if (i->getSource() && i->getSource()->isAlive() &&
                        i->getSource()->GetPositionX() <= POS_X_NORTH &&
                        i->getSource()->GetPositionX() >= POS_X_SOUTH &&
                        i->getSource()->GetPositionY() >= POS_Y_GATE &&
                        i->getSource()->GetPositionY() <= POS_Y_WEST)
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

    void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        uint32 spellId = 0;
        switch(spell->Id)
        {
            case SPELL_INFORM_LIVE_TRAINEE: spellId = SPELL_INFORM_DEAD_TRAINEE;    break;
            case SPELL_INFORM_LIVE_KNIGHT:  spellId = SPELL_INFORM_DEAD_KNIGHT;     break;
            case SPELL_INFORM_LIVE_RIDER:   spellId = SPELL_INFORM_DEAD_RIDER;      break;
        }
        if (spellId && me->isInCombat())
        {
            me->HandleEmoteCommand(EMOTE_ONESHOT_SPELLCAST);
            me->CastSpell(deadTrigger[rand()%POS_DEAD], spellId, true);
        }
    }

    void SpellHitTarget(Unit *pTarget, const SpellEntry *spell)
    {
        if (!me->isInCombat())
            return;

        switch(spell->Id)
        {
            case SPELL_INFORM_DEAD_TRAINEE: 
                DoSummon(MOB_DEAD_TRAINEE, pTarget, 0);  
                break;
            case SPELL_INFORM_DEAD_KNIGHT:  
                DoSummon(MOB_DEAD_KNIGHT, pTarget, 0);   
                break;
            case SPELL_INFORM_DEAD_RIDER:   
                DoSummon(MOB_DEAD_RIDER, pTarget, 1.0f);
                DoSummon(MOB_DEAD_HORSE, pTarget, 1.0f); 
                break;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateCombatState() || !CheckInRoom())
            return;

        events.Update(diff);

        if (!thirtyPercentReached && HealthBelowPct(30) && phaseTwo)
        {
            thirtyPercentReached = true;
            if (instance)
                instance->SetData(DATA_GOTHIK_GATE, GO_STATE_ACTIVE);
        }

        if (me->hasUnitState(UNIT_STAT_CASTING))
            return;

        while(uint32 eventId = events.ExecuteEvent())
        {
            switch(eventId)
            {
                case EVENT_SUMMON:
                    if (waves[waveCount].entry)
                    {
                        DoGothikSummon(waves[waveCount].entry);

                        // if group is not splitted, open gate and merge both sides at ~ 2 minutes (wave 11)
                        if (waveCount == 11)
                        {
                            if (!CheckGroupSplitted())
                            {
                                if (instance)
                                    instance->SetData(DATA_GOTHIK_GATE, GO_STATE_ACTIVE);
                                summons.DoAction(0, 0);
                                summons.DoZoneInCombat();
                                mergedSides = true;
                            }
                        }

                        ++waveCount;
                        events.ScheduleEvent(EVENT_SUMMON, waves[waveCount].time);
                    }
                    else
                    {
                        phaseTwo = true;
                        DoScriptText(SAY_TELEPORT, me);
                        DoTeleportTo(PosGroundLiveSide);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                        summons.DoAction(0, 0);
                        summons.DoZoneInCombat();
                        events.ScheduleEvent(EVENT_BOLT, 1000);
                        events.ScheduleEvent(EVENT_HARVEST, urand(3000,15000));
                        events.ScheduleEvent(EVENT_TELEPORT, 20000);
                    }
                    break;
                case EVENT_BOLT:
                    DoCast(me->getVictim(), RAID_MODE(SPELL_SHADOW_BOLT, H_SPELL_SHADOW_BOLT));
                    events.ScheduleEvent(EVENT_BOLT, 1000);
                    break;
                case EVENT_HARVEST:
                    DoCast(me->getVictim(), SPELL_HARVEST_SOUL, true);
                    events.ScheduleEvent(EVENT_HARVEST, urand(20000,25000));
                    break;
                case EVENT_TELEPORT:
                    if (!thirtyPercentReached)
                    {
                        m_creature->AttackStop();
                        if (IN_LIVE_SIDE(m_creature))
                        {
                            DoTeleportTo(PosGroundDeadSide);
                        }
                        else
                        {
                            DoTeleportTo(PosGroundLiveSide);
                        }

                        m_creature->getThreatManager().resetAggro(NotOnSameSide(m_creature));
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_NEAREST, 0))
                        {
                            m_creature->getThreatManager().addThreat(pTarget, 100.0f);
                            AttackStart(pTarget);
                        }

                        events.ScheduleEvent(EVENT_TELEPORT, 20000);
                    }
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct TRINITY_DLL_DECL mob_gothik_minionAI : public CombatAI
{
    mob_gothik_minionAI(Creature *c) : CombatAI(c)
    {
        liveSide = IN_LIVE_SIDE(me);
    }

    bool liveSide;
    bool gateClose;

    bool isOnSameSide(const Unit *pWho) 
    {
        return (liveSide == IN_LIVE_SIDE(pWho));
    }

    void DoAction(const int32 param)
    {
        gateClose = param;
    }

    void DamageTaken(Unit *attacker, uint32 &damage)
    {
        if (gateClose && !isOnSameSide(attacker))
            damage = 0;
    }

    void JustDied(Unit *killer)
    {
        if (me->isSummon())
        {
            if (Unit *owner = CAST_SUM(me)->GetSummoner())
                CombatAI::JustDied(owner);
        }
    }

    void EnterEvadeMode()
    {
        if (!gateClose)
        {
            CombatAI::EnterEvadeMode();
            return;
        }

        if (!_EnterEvadeMode())
            return;

        Map* pMap = me->GetMap();
        if (pMap->IsDungeon())
        {
            Map::PlayerList const &PlayerList = pMap->GetPlayers();
            if (!PlayerList.isEmpty())
            {
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                {
                    if (i->getSource() && i->getSource()->isAlive() && isOnSameSide(i->getSource()))
                    {
                        AttackStart(i->getSource());
                        return;
                    }
                }
            }
        }

        me->GetMotionMaster()->MoveIdle();
        Reset();
    }

    void UpdateAI(const uint32 diff)
    {
        if (gateClose && (!isOnSameSide(me) || me->getVictim() && !isOnSameSide(me->getVictim())))
        {
            EnterEvadeMode();
            return;
        }

        CombatAI::UpdateAI(diff);
    }
};

CreatureAI* GetAI_boss_gothik(Creature* pCreature)
{
    return new boss_gothikAI (pCreature);
}

CreatureAI* GetAI_mob_gothik_minion(Creature* pCreature)
{
    return new mob_gothik_minionAI (pCreature);
}

void AddSC_boss_gothik()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_gothik";
    newscript->GetAI = &GetAI_boss_gothik;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_gothik_minion";
    newscript->GetAI = &GetAI_mob_gothik_minion;
    newscript->RegisterSelf();
}

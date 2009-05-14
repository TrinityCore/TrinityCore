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
#include "def_naxxramas.h"

#define SAY_SPEECH                  -1533040
#define SAY_KILL                    -1533041
#define SAY_DEATH                   -1533042
#define SAY_TELEPORT                -1533043

//Gothik
#define SPELL_HARVEST_SOUL          28679
#define SPELL_SHADOW_BOLT           HEROIC(29317,56405)

#define SPELL_INFORM_LIVE_TRAINEE   27892
#define SPELL_INFORM_LIVE_KNIGHT    27928
#define SPELL_INFORM_LIVE_RIDER     27935
#define SPELL_INFORM_DEAD_TRAINEE   27915
#define SPELL_INFORM_DEAD_KNIGHT    27931
#define SPELL_INFORM_DEAD_RIDER     27937

#define MOB_LIVE_TRAINEE    16124
#define MOB_LIVE_KNIGHT     16125
#define MOB_LIVE_RIDER      16126
#define MOB_DEAD_TRAINEE    16127
#define MOB_DEAD_KNIGHT     16148
#define MOB_DEAD_RIDER      16150
#define MOB_DEAD_HORSE      16149

const struct Waves { uint32 entry, number, time; }
waves[] =
{
    {MOB_LIVE_TRAINEE, 2, 20000},
    {MOB_LIVE_TRAINEE, 2, 20000},
    {MOB_LIVE_TRAINEE, 2, 10000},
    {MOB_LIVE_KNIGHT,  1, 10000},
    {MOB_LIVE_TRAINEE, 2, 15000},
    {MOB_LIVE_KNIGHT,  1, 10000},
    {MOB_LIVE_TRAINEE, 2, 15000},
    {MOB_LIVE_TRAINEE, 2, 0},
    {MOB_LIVE_KNIGHT,  1, 10000},
    {MOB_LIVE_RIDER,   1, 10000},
    {MOB_LIVE_TRAINEE, 2, 5000},
    {MOB_LIVE_KNIGHT,  1, 15000},
    {MOB_LIVE_TRAINEE, 2, 0},
    {MOB_LIVE_RIDER,   1, 10000},
    {MOB_LIVE_KNIGHT,  2, 10000},
    {MOB_LIVE_TRAINEE, 2, 10000},
    {MOB_LIVE_RIDER,   1, 5000},
    {MOB_LIVE_KNIGHT,  1, 5000},
    {MOB_LIVE_TRAINEE, 2, 20000},
    {MOB_LIVE_TRAINEE, 2, 0},
    {MOB_LIVE_KNIGHT,  1, 0},
    {MOB_LIVE_RIDER,   1, 15000},
    {MOB_LIVE_TRAINEE, 2, 29000},
    {0, 0, 0},
};

#define POS_Y_GATE  -3360.78f

enum Events
{
    EVENT_SUMMON = 1,
    EVENT_HARVEST,
    EVENT_BOLT,
};

#define POS_LIVE 3
#define POS_DEAD 5

const float PosSummonLive[POS_LIVE][4] =
{
    {2669.7, -3430.9, 268.56, 1.6},
    {2692.0, -3430.9, 268.56, 1.6},
    {2714.1, -3430.9, 268.56, 1.6},
};

const float PosSummonDead[POS_DEAD][4] =
{
    {2725.1, -3310.0, 268.85, 3.4},
    {2699.3, -3322.8, 268.60, 3.3},
    {2733.1, -3348.5, 268.84, 3.1},
    {2682.8, -3304.2, 268.85, 3.9},
    {2664.8, -3340.7, 268.23, 3.7},
};

const float PosGround[4] = {2691.2, -3362.7, 267.68, 1.7};
const float PosPlatform[4] = {2640.5, -3360.6, 285.26, 0};

struct TRINITY_DLL_DECL boss_gothikAI : public BossAI
{
    boss_gothikAI(Creature *c) : BossAI(c, BOSS_GOTHIK) {}

    uint32 waveCount;
    std::vector<Creature*> liveTrigger;
    std::vector<Creature*> deadTrigger;

    void Reset()
    {
        liveTrigger.clear();
        deadTrigger.clear();
        me->setActive(false);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
        me->SetReactState(REACT_PASSIVE);
        _Reset();
    }

    void EnterCombat(Unit *who)
    {
        for(uint32 i = 0; i < POS_LIVE; ++i)
            if(Creature *trigger = DoSummon(WORLD_TRIGGER, PosSummonLive[i]))
                liveTrigger.push_back(trigger);
        for(uint32 i = 0; i < POS_DEAD; ++i)
            if(Creature *trigger = DoSummon(WORLD_TRIGGER, PosSummonDead[i]))
                deadTrigger.push_back(trigger);

        if(liveTrigger.size() < POS_LIVE || deadTrigger.size() < POS_DEAD)
        {
            error_log("Script Gothik: cannot summon triggers!");
            EnterEvadeMode();
            return;
        }

        _EnterCombat();
        me->setActive(true);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
        waveCount = 0;
        events.ScheduleEvent(EVENT_SUMMON, 30000);
        DoTeleportTo(PosPlatform);
        DoScriptText(SAY_SPEECH, me);
        if(instance)
            instance->SetData(DATA_GOTHIK_GATE, 1);
    }

    void JustSummoned(Creature *summon)
    {
        if(summon->GetEntry() == WORLD_TRIGGER)
            summon->setActive(true);
        else
        {
            summon->AI()->DoAction(me->HasReactState(REACT_PASSIVE) ? 1 : 0);
            summon->AI()->EnterEvadeMode();
        }
        summons.Summon(summon);
    }

    void KilledUnit(Unit* victim)
    {
        if(!(rand()%5))
            DoScriptText(SAY_KILL, me);
    }

    void JustDied(Unit* Killer)
    {
        _JustDied();
        DoScriptText(SAY_DEATH, me);
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
        if(spellId && me->isInCombat())
        {
            me->HandleEmoteCommand(EMOTE_ONESHOT_SPELLCAST);
            me->CastSpell(deadTrigger[rand()%POS_DEAD], spellId, true);
        }
    }

    void SpellHitTarget(Unit *target, const SpellEntry *spell)
    {
        if(!me->isInCombat())
            return;

        switch(spell->Id)
        {
            case SPELL_INFORM_DEAD_TRAINEE: DoSummon(MOB_DEAD_TRAINEE, target, 0);  break;
            case SPELL_INFORM_DEAD_KNIGHT:  DoSummon(MOB_DEAD_KNIGHT, target, 0);   break;
            case SPELL_INFORM_DEAD_RIDER:   DoSummon(MOB_DEAD_RIDER, target, 1.0f);
                DoSummon(MOB_DEAD_HORSE, target, 1.0f); break;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if(!me->isInCombat())
            return;

        if(me->getThreatManager().isThreatListEmpty())
        {
            EnterEvadeMode();
            return;
        }

        if(me->HasReactState(REACT_AGGRESSIVE) && !UpdateVictim())
            return;

        events.Update(diff);

        if(me->hasUnitState(UNIT_STAT_CASTING))
            return;

        while(uint32 eventId = events.ExecuteEvent())
        {
            switch(eventId)
            {
                case EVENT_SUMMON:
                    if(waves[waveCount].entry)
                    {
                        for(uint32 i = 0; i < waves[waveCount].number; ++i)
                            DoSummon(waves[waveCount].entry, liveTrigger[rand()%POS_LIVE], 1.0f);
                        events.ScheduleEvent(EVENT_SUMMON, waves[waveCount].time);
                        ++waveCount;
                    }
                    else
                    {
                        DoScriptText(SAY_TELEPORT, me);
                        DoTeleportTo(PosGround);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_ATTACKABLE_2);
                        if(instance)
                            instance->SetData(DATA_GOTHIK_GATE, 0);
                        summons.DoAction(0, 0);
                        summons.DoZoneInCombat();
                        events.ScheduleEvent(EVENT_BOLT, 1000);
                        events.ScheduleEvent(EVENT_HARVEST, 15000);
                    }
                    break;
                case EVENT_BOLT:
                    DoCast(me->getVictim(), SPELL_SHADOW_BOLT);
                    events.ScheduleEvent(EVENT_BOLT, 1000);
                    return;
                case EVENT_HARVEST:
                    DoCast(me->getVictim(), SPELL_HARVEST_SOUL);
                    events.ScheduleEvent(EVENT_HARVEST, 15000);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct TRINITY_DLL_DECL mob_gothik_minionAI : public SpellAI
{
    mob_gothik_minionAI(Creature *c) : SpellAI(c)
    {
        liveSide = me->GetPositionY() < POS_Y_GATE;
    }

    bool liveSide;
    bool gateClose;

#define SIDE_CHECK(who) (liveSide == (who->GetPositionY() < POS_Y_GATE))

    void DoAction(const int32 param)
    {
        gateClose = param;
    }

    void DamageTaken(Unit *attacker, uint32 &damage)
    {
        if(gateClose && !SIDE_CHECK(attacker))
            damage = 0;
    }

    void JustDied(Unit *killer)
    {
        if(me->isSummon())
        {
            if(Unit *owner = ((TempSummon*)me)->GetSummoner())
                SpellAI::JustDied(owner);
        }
    }

    void EnterEvadeMode()
    {
        if(!gateClose)
        {
            SpellAI::EnterEvadeMode();
            return;
        }

        if(!_EnterEvadeMode())
            return;

        Map *map = me->GetMap();
        if(map->IsDungeon())
        {
            Map::PlayerList const &PlayerList = map->GetPlayers();
            for(Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            {
                if(i->getSource()->isAlive() && SIDE_CHECK(i->getSource()))
                {
                    AttackStart(i->getSource());
                    return;
                }
            }
        }

        me->GetMotionMaster()->MoveIdle();
        Reset();
    }

    void UpdateAI(const uint32 diff)
    {
        if(gateClose && (!SIDE_CHECK(me) || me->getVictim() && !SIDE_CHECK(me->getVictim())))
        {
            EnterEvadeMode();
            return;
        }

        SpellAI::UpdateAI(diff);
    }
};

CreatureAI* GetAI_boss_gothik(Creature *_Creature)
{
    return new boss_gothikAI (_Creature);
}

CreatureAI* GetAI_mob_gothik_minion(Creature *_Creature)
{
    return new mob_gothik_minionAI (_Creature);
}

void AddSC_boss_gothik()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_gothik";
    newscript->GetAI = &GetAI_boss_gothik;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_gothik_minion";
    newscript->GetAI = &GetAI_mob_gothik_minion;
    newscript->RegisterSelf();
}

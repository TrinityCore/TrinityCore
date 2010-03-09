/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/ >
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

/* ScriptData
SDName: Boss_Supremus
SD%Complete: 95
SDComment: Need to implement molten punch
SDCategory: Black Temple
EndScriptData */

#include "ScriptedPch.h"
#include "black_temple.h"

#define EMOTE_NEW_TARGET            -1564010
#define EMOTE_PUNCH_GROUND          -1564011                //DoScriptText(EMOTE_PUNCH_GROUND, m_creature);
#define EMOTE_GROUND_CRACK          -1564012

//Spells
#define SPELL_MOLTEN_PUNCH          40126
#define SPELL_HATEFUL_STRIKE        41926
#define SPELL_MOLTEN_FLAME          40980
#define SPELL_VOLCANIC_ERUPTION     40117
#define SPELL_VOLCANIC_SUMMON       40276
#define SPELL_BERSERK               45078

#define CREATURE_VOLCANO            23085
#define CREATURE_STALKER            23095

#define PHASE_STRIKE    1
#define PHASE_CHASE     2

#define EVENT_BERSERK           1
#define EVENT_SWITCH_PHASE      2
#define EVENT_FLAME             3
#define EVENT_VOLCANO           4
#define EVENT_SWITCH_TARGET     5
#define EVENT_HATEFUL_STRIKE    6

#define GCD_CAST    1

struct molten_flameAI : public NullCreatureAI
{
    molten_flameAI(Creature *c) : NullCreatureAI(c) {}

    void InitializeAI()
    {
        float x, y, z;
        me->GetNearPoint(me, x, y, z, 1, 100, M_PI*2*rand_norm());
        me->GetMotionMaster()->MovePoint(0, x, y, z);
        me->SetVisibility(VISIBILITY_OFF);
        me->CastSpell(me,SPELL_MOLTEN_FLAME,true);
    }
};

struct boss_supremusAI : public ScriptedAI
{
    boss_supremusAI(Creature *c) : ScriptedAI(c), summons(m_creature)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;
    EventMap events;
    SummonList summons;
    uint32 phase;

    void Reset()
    {
        if (pInstance)
        {
            if (m_creature->isAlive())
            {
                pInstance->SetData(DATA_SUPREMUSEVENT, NOT_STARTED);
                //ToggleDoors(true);
            }
            //else ToggleDoors(false);
        }

        phase = 0;

        events.Reset();
        summons.DespawnAll();
    }

    void EnterCombat(Unit *who)
    {
        if (pInstance)
            pInstance->SetData(DATA_SUPREMUSEVENT, IN_PROGRESS);

        ChangePhase();
        events.ScheduleEvent(EVENT_BERSERK, 900000, GCD_CAST);
        events.ScheduleEvent(EVENT_FLAME, 20000, GCD_CAST);
    }

    void ChangePhase()
    {
        if (!phase || phase == PHASE_CHASE)
        {
            phase = PHASE_STRIKE;
            summons.DoAction(EVENT_VOLCANO, 0);
            events.ScheduleEvent(EVENT_HATEFUL_STRIKE, 5000, GCD_CAST, PHASE_STRIKE);
            m_creature->SetSpeed(MOVE_RUN, 1.2f);
            m_creature->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
            m_creature->ApplySpellImmune(0, IMMUNITY_EFFECT,SPELL_EFFECT_ATTACK_ME, false);
        }
        else
        {
            phase = PHASE_CHASE;
            events.ScheduleEvent(EVENT_VOLCANO, 5000, GCD_CAST, PHASE_CHASE);
            events.ScheduleEvent(EVENT_SWITCH_TARGET, 10000, 0, PHASE_CHASE);
            m_creature->SetSpeed(MOVE_RUN, 0.9f);
            m_creature->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
            m_creature->ApplySpellImmune(0, IMMUNITY_EFFECT,SPELL_EFFECT_ATTACK_ME, true);
        }
        DoResetThreat();
        DoZoneInCombat();
        events.SetPhase(phase);
        events.ScheduleEvent(EVENT_SWITCH_PHASE, 60000, GCD_CAST);
    }

    void JustDied(Unit *killer)
    {
        if (pInstance)
        {
            pInstance->SetData(DATA_SUPREMUSEVENT, DONE);
            pInstance->HandleGameObject(pInstance->GetData64(DATA_GAMEOBJECT_SUPREMUS_DOORS), true);
        }
        summons.DespawnAll();
    }

    void JustSummoned(Creature *summon) {summons.Summon(summon);}
    void SummonedCreatureDespawn(Creature *summon) {summons.Despawn(summon);}

    Unit* CalculateHatefulStrikeTarget()
    {
        uint32 health = 0;
        Unit *pTarget = NULL;

        std::list<HostileReference*>& m_threatlist = m_creature->getThreatManager().getThreatList();
        std::list<HostileReference*>::iterator i = m_threatlist.begin();
        for (i = m_threatlist.begin(); i!= m_threatlist.end(); ++i)
        {
            Unit* pUnit = Unit::GetUnit((*m_creature), (*i)->getUnitGuid());
            if (pUnit && m_creature->IsWithinMeleeRange(pUnit))
            {
                if (pUnit->GetHealth() > health)
                {
                    health = pUnit->GetHealth();
                    pTarget = pUnit;
                }
            }
        }

        return pTarget;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        while(uint32 eventId = events.ExecuteEvent())
        {
            switch(eventId)
            {
                case EVENT_BERSERK:
                    DoCast(m_creature, SPELL_BERSERK, true);
                    break;
                case EVENT_FLAME:
                    DoCast(m_creature, SPELL_MOLTEN_PUNCH);
                    events.DelayEvents(1500, GCD_CAST);
                    events.ScheduleEvent(EVENT_FLAME, 20000, GCD_CAST);
                    break;
                case EVENT_HATEFUL_STRIKE:
                    if (Unit *pTarget = CalculateHatefulStrikeTarget())
                        DoCast(pTarget, SPELL_HATEFUL_STRIKE);
                    events.DelayEvents(1000, GCD_CAST);
                    events.ScheduleEvent(EVENT_HATEFUL_STRIKE, 5000, GCD_CAST, PHASE_STRIKE);
                    break;
                case EVENT_SWITCH_TARGET:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true))
                    {
                        DoResetThreat();
                        m_creature->AddThreat(pTarget, 5000000.0f);
                        DoScriptText(EMOTE_NEW_TARGET, m_creature);
                    }
                    events.ScheduleEvent(EVENT_SWITCH_TARGET, 10000, 0, PHASE_CHASE);
                    break;
                case EVENT_VOLCANO:
                {
                    Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 999, true);
                    if (!pTarget) pTarget = m_creature->getVictim();
                    if (pTarget)
                    {
                        //DoCast(pTarget, SPELL_VOLCANIC_SUMMON);//movement bugged
                        m_creature->SummonCreature(CREATURE_VOLCANO,pTarget->GetPositionX(),pTarget->GetPositionY(),pTarget->GetPositionZ(),0,TEMPSUMMON_TIMED_DESPAWN,30000);
                        DoScriptText(EMOTE_GROUND_CRACK, m_creature);
                        events.DelayEvents(1500, GCD_CAST);
                    }
                    events.ScheduleEvent(EVENT_VOLCANO, 10000, GCD_CAST, PHASE_CHASE);
                    return;
                }
                case EVENT_SWITCH_PHASE:
                    ChangePhase();
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_volcanoAI : public Scripted_NoMovementAI
{
    npc_volcanoAI(Creature *c) : Scripted_NoMovementAI(c) {}

    void Reset()
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        //DoCast(m_creature, SPELL_VOLCANIC_ERUPTION);
        me->SetReactState(REACT_PASSIVE);
        wait = 3000;
    }
    uint32 wait;

    void EnterCombat(Unit *who) {}

    void MoveInLineOfSight(Unit *who) {}

    void DoAction(const uint32 info)
    {
        m_creature->RemoveAura(SPELL_VOLCANIC_ERUPTION);
    }

    void UpdateAI(const uint32 diff)
    {
        if (wait<=diff)//wait 3secs before casting
        {
            DoCast(m_creature, SPELL_VOLCANIC_ERUPTION);
            wait = 60000;
        }
        else wait -= diff;
    }

};

CreatureAI* GetAI_boss_supremus(Creature* pCreature)
{
    return new boss_supremusAI (pCreature);
}

CreatureAI* GetAI_molten_flame(Creature* pCreature)
{
    return new molten_flameAI (pCreature);
}

CreatureAI* GetAI_npc_volcano(Creature* pCreature)
{
    return new npc_volcanoAI (pCreature);
}

void AddSC_boss_supremus()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_supremus";
    newscript->GetAI = &GetAI_boss_supremus;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "molten_flame";
    newscript->GetAI = &GetAI_molten_flame;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_volcano";
    newscript->GetAI = &GetAI_npc_volcano;
    newscript->RegisterSelf();
}


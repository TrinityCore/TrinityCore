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
SDComment: Need to implement doors.
SDCategory: Black Temple
EndScriptData */

#include "precompiled.h"
#include "def_black_temple.h"

//Spells
#define SPELL_MOLTEN_PUNCH          40126
#define SPELL_HURTFUL_STRIKE        41926
#define SPELL_MOLTEN_FLAME          40253
#define SPELL_VOLCANIC_ERUPTION     40117
#define SPELL_VOLCANIC_SUMMON       40276
#define SPELL_BERSERK               45078

#define CREATURE_VOLCANO            23085
#define CREATURE_STALKER            23095

struct TRINITY_DLL_DECL molten_flameAI : public ScriptedAI
{
    molten_flameAI(Creature *c) : ScriptedAI(c)
    {
        FlameTimer = 0;
        float x, y, z;
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->GetNearPoint(m_creature, x, y, z, 1, 50, M_PI*2*rand_norm());
        m_creature->GetMotionMaster()->MovePoint(0, x, y, z);
    }

    uint32 FlameTimer;

    void Reset() {}
    void Aggro(Unit *who) {}
    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit *who) {}
    void UpdateAI(const uint32 diff)
    {
        if(FlameTimer < diff)
        {
            m_creature->CastSpell(m_creature, SPELL_MOLTEN_FLAME, true);
            FlameTimer = 1000;
        }else FlameTimer -= diff;
    }
};

struct TRINITY_DLL_DECL npc_volcanoAI : public ScriptedAI
{
    npc_volcanoAI(Creature *c) : ScriptedAI(c)
    {
        m_creature->CastSpell(m_creature, SPELL_VOLCANIC_ERUPTION, false);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    }

    void Reset() {}
    void Aggro(Unit *who) {}
    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}
    void UpdateAI(const uint32 diff) {}
};

struct TRINITY_DLL_DECL boss_supremusAI : public ScriptedAI
{
    boss_supremusAI(Creature *c) : ScriptedAI(c), summons(m_creature)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    ScriptedInstance* pInstance;

    uint32 SummonFlameTimer;
    uint32 SwitchTargetTimer;
    uint32 PhaseSwitchTimer;
    uint32 SummonVolcanoTimer;
    uint32 HurtfulStrikeTimer;
    uint32 BerserkTimer;

    bool Phase1;

    SummonList summons;

    void Reset()
    {
        if(pInstance)
        {
            if(m_creature->isAlive())
            {
                pInstance->SetData(DATA_SUPREMUSEVENT, NOT_STARTED);
                ToggleDoors(true);
            }
            else ToggleDoors(false);
        }

        HurtfulStrikeTimer = 5000;
        SummonFlameTimer = 20000;
        SwitchTargetTimer = 90000;
        PhaseSwitchTimer = 60000;
        SummonVolcanoTimer = 5000;
        BerserkTimer = 900000;                              // 15 minute enrage

        Phase1 = true;
        summons.DespawnAll();
    }

    void Aggro(Unit *who)
    {
        DoZoneInCombat();

        if(pInstance)
            pInstance->SetData(DATA_SUPREMUSEVENT, IN_PROGRESS);
    }

    void ToggleDoors(bool close)
    {
        if(GameObject* Doors = GameObject::GetGameObject(*m_creature, pInstance->GetData64(DATA_GAMEOBJECT_SUPREMUS_DOORS)))
        {
            if(close) Doors->SetGoState(1);                 // Closed
            else Doors->SetGoState(0);                      // Open
        }
    }

    void JustDied(Unit *killer)
    {
        if(pInstance)
        {
            pInstance->SetData(DATA_SUPREMUSEVENT, DONE);
            ToggleDoors(false);
        }
        summons.DespawnAll();
    }

    void JustSummoned(Creature *summon) {summons.Summon(summon);}
    void SummonedCreatureDespawn(Creature *summon) {summons.Despawn(summon);}

    Unit* CalculateHurtfulStrikeTarget()
    {
        uint32 health = 0;
        Unit* target = NULL;

        std::list<HostilReference*>& m_threatlist = m_creature->getThreatManager().getThreatList();
        std::list<HostilReference*>::iterator i = m_threatlist.begin();
        for (i = m_threatlist.begin(); i!= m_threatlist.end();++i)
        {
            Unit* pUnit = Unit::GetUnit((*m_creature), (*i)->getUnitGuid());
            if(pUnit && m_creature->IsWithinCombatDist(pUnit, ATTACK_DISTANCE))
            {
                if(pUnit->GetHealth() > health)
                {
                    health = pUnit->GetHealth();
                    target = pUnit;
                }
            }
        }

        return target;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if(!m_creature->HasAura(SPELL_BERSERK, 0))
            if(BerserkTimer < diff)
                DoCast(m_creature, SPELL_BERSERK);
            else BerserkTimer -= diff;

        if(SummonFlameTimer < diff)
        {
            DoCast(m_creature, SPELL_MOLTEN_PUNCH);
            SummonFlameTimer = 20000;
        }else SummonFlameTimer -= diff;

        if(Phase1)
        {
            if(HurtfulStrikeTimer < diff)
            {
                if(Unit* target = CalculateHurtfulStrikeTarget())
                {
                    DoCast(target, SPELL_HURTFUL_STRIKE);
                    HurtfulStrikeTimer = 5000;
                }
            }else HurtfulStrikeTimer -= diff;
        }

        if(!Phase1)
        {
            if(SwitchTargetTimer < diff)
            {
                if(Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 1, 100, true))
                {
                    DoResetThreat();
                    m_creature->AddThreat(target, 5000000.0f);
                    DoTextEmote("acquires a new target!", NULL);
                    SwitchTargetTimer = 10000;
                }
            }else SwitchTargetTimer -= diff;

            if(SummonVolcanoTimer < diff)
            {
                if(Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0, 999, true))
                {
                    DoCast(target, SPELL_VOLCANIC_SUMMON);
                    DoTextEmote("roars and the ground begins to crack open!", NULL);
                    SummonVolcanoTimer = 10000;
                }
            }else SummonVolcanoTimer -= diff;
        }

        if(PhaseSwitchTimer < diff)
        {
            if(!Phase1)
            {
                Phase1 = true;
                DoResetThreat();
                PhaseSwitchTimer = 60000;
                m_creature->SetSpeed(MOVE_RUN, 1.2f);
                DoZoneInCombat();
            }
            else
            {
                Phase1 = false;
                DoResetThreat();
                SwitchTargetTimer = 10000;
                SummonVolcanoTimer = 2000;
                PhaseSwitchTimer = 60000;
                m_creature->SetSpeed(MOVE_RUN, 0.9f);
                DoZoneInCombat();
            }
        }else PhaseSwitchTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_supremus(Creature *_Creature)
{
    return new boss_supremusAI (_Creature);
}

CreatureAI* GetAI_molten_flame(Creature *_Creature)
{
    return new molten_flameAI (_Creature);
}

CreatureAI* GetAI_npc_volcano(Creature *_Creature)
{
    return new npc_volcanoAI (_Creature);
}

void AddSC_boss_supremus()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_supremus";
    newscript->GetAI = GetAI_boss_supremus;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="molten_flame";
    newscript->GetAI = GetAI_molten_flame;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="npc_volcano";
    newscript->GetAI = GetAI_npc_volcano;
    m_scripts[nrscripts++] = newscript;
}

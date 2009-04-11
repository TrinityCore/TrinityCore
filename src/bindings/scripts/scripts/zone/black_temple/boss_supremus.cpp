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

#include "precompiled.h"
#include "def_black_temple.h"

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

struct TRINITY_DLL_DECL molten_flameAI : public NullCreatureAI
{
    molten_flameAI(Creature *c) : NullCreatureAI(c)
    {
        float x, y, z;
        me->GetNearPoint(me, x, y, z, 1, 50, M_PI*2*rand_norm());
        me->GetMotionMaster()->MovePoint(0, x, y, z);
    }
};

struct TRINITY_DLL_DECL boss_supremusAI : public ScriptedAI
{
    boss_supremusAI(Creature *c) : ScriptedAI(c), summons(m_creature)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
    }

    ScriptedInstance* pInstance;

    uint32 SummonFlameTimer;
    uint32 SwitchTargetTimer;
    uint32 PhaseSwitchTimer;
    uint32 SummonVolcanoTimer;
    uint32 HatefulStrikeTimer;
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
                //ToggleDoors(true);
            }
            //else ToggleDoors(false);
        }

        HatefulStrikeTimer = 5000;
        SummonFlameTimer = 20000;
        SwitchTargetTimer = 90000;
        PhaseSwitchTimer = 60000;
        SummonVolcanoTimer = 5000;
        BerserkTimer = 900000;                              // 15 minute enrage

        Phase1 = true;
        summons.DespawnAll();

        m_creature->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
        m_creature->ApplySpellImmune(0, IMMUNITY_EFFECT,SPELL_EFFECT_ATTACK_ME, false);
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

    Unit* CalculateHatefulStrikeTarget()
    {
        uint32 health = 0;
        Unit* target = NULL;

        std::list<HostilReference*>& m_threatlist = m_creature->getThreatManager().getThreatList();
        std::list<HostilReference*>::iterator i = m_threatlist.begin();
        for (i = m_threatlist.begin(); i!= m_threatlist.end();++i)
        {
            Unit* pUnit = Unit::GetUnit((*m_creature), (*i)->getUnitGuid());
            if(pUnit && m_creature->IsWithinMeleeRange(pUnit))
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
        if (!UpdateVictim())
            return;

        if(!m_creature->HasAura(SPELL_BERSERK))
        {
            if(BerserkTimer < diff)
                DoCast(m_creature, SPELL_BERSERK);
            else BerserkTimer -= diff;
        }

        if(SummonFlameTimer < diff)
        {
            DoCast(m_creature, SPELL_MOLTEN_PUNCH);
            SummonFlameTimer = 20000;
        }else SummonFlameTimer -= diff;

        if(Phase1)
        {
            if(HatefulStrikeTimer < diff)
            {
                if(Unit* target = CalculateHatefulStrikeTarget())
                {
                    DoCast(target, SPELL_HATEFUL_STRIKE);
                    HatefulStrikeTimer = 5000;
                }
            }else HatefulStrikeTimer -= diff;
        }

        if(!Phase1)
        {
            if(SwitchTargetTimer < diff)
            {
                if(Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 1, 100, true))
                {
                    DoResetThreat();
                    m_creature->AddThreat(target, 5000000.0f);
                    DoScriptText(EMOTE_NEW_TARGET, m_creature);
                    SwitchTargetTimer = 10000;
                }
            }else SwitchTargetTimer -= diff;

            if(SummonVolcanoTimer < diff)
            {
                if(Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0, 999, true))
                {
                    if(!target)
                        target = m_creature->getVictim();

                    DoCast(target, SPELL_VOLCANIC_SUMMON);
                    DoScriptText(EMOTE_GROUND_CRACK, m_creature);
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
                m_creature->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, false);
                m_creature->ApplySpellImmune(0, IMMUNITY_EFFECT,SPELL_EFFECT_ATTACK_ME, false);
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
                m_creature->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                m_creature->ApplySpellImmune(0, IMMUNITY_EFFECT,SPELL_EFFECT_ATTACK_ME, true);
            }
        }else PhaseSwitchTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct TRINITY_DLL_DECL npc_volcanoAI : public ScriptedAI
{
    npc_volcanoAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
    }

    ScriptedInstance *pInstance;

    uint32 CheckTimer;
    bool Eruption;

    void Reset()
    {
        CheckTimer = 1500;
        Eruption = false;

        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    }

    void Aggro(Unit *who) {}

    void MoveInLineOfSight(Unit *who)
    {
        return; // paralyze the npc
    }

    void UpdateAI(const uint32 diff)
    {
        if(CheckTimer < diff)
        {
            uint64 SupremusGUID = pInstance->GetData64(DATA_SUPREMUS);
            Creature* Supremus = (Unit::GetCreature((*m_creature), SupremusGUID));
            if(!Eruption && !((boss_supremusAI*)Supremus->AI())->Phase1)
            {
                Eruption = true;
                DoCast(m_creature, SPELL_VOLCANIC_ERUPTION);
            }
            else if(Eruption && ((boss_supremusAI*)Supremus->AI())->Phase1)
            {
                m_creature->RemoveAura(SPELL_VOLCANIC_ERUPTION);
            }
            CheckTimer = 1500;
        }else CheckTimer -= diff;
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
    newscript->GetAI = &GetAI_boss_supremus;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="molten_flame";
    newscript->GetAI = &GetAI_molten_flame;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_volcano";
    newscript->GetAI = &GetAI_npc_volcano;
    newscript->RegisterSelf();
}


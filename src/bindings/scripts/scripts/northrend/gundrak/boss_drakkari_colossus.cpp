/*
 * Copyright (C) 2009 Trinity <http://www.trinitycore.org/>
 *
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

/* Script Data Start
SDName: Boss Drakkari Colossus
SDAuthor: Manuel
SD%Complete: 95 %
SDComment: The event with the Living Mojos is not implemented, just is done that when one of the mojos around the boss take damage will make the boss enter in combat!
SDCategory:
Script Data End */

#include "precompiled.h"
#include "gundrak.h"

enum Spells
{
    SPELL_EMERGE        = 54850,
    SPELL_EMERGE_2      = 54851,

    SPELL_MIGHTY_BLOW   = 54719,

    SPELL_MERGE         = 54878,
    SPELL_SURGE         = 54801,

    SPELL_FREEZE_ANIM   = 16245,

    SPELL_MOJO_PUDDLE   = 55627,
    H_SPELL_MOJO_PUDDLE = 58994,

    SPELL_MOJO_WAVE     = 55626,
    H_SPELL_MOJO_WAVE   = 58993
};

enum Entries
{
    DRAKKARI_COLOSSUS   = 29307,
};

struct TRINITY_DLL_DECL boss_drakkari_colossusAI : public ScriptedAI
{
    boss_drakkari_colossusAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    bool Summoned;

    uint32 Summon_Timer;
    uint32 MightyBlowTimer;

    void Reset()
    {
        if (pInstance)
            pInstance->SetData(DATA_DRAKKARI_COLOSSUS_EVENT, NOT_STARTED);

        if(!m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE))
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);

        m_creature->clearUnitState(UNIT_STAT_STUNNED);
        m_creature->SetReactState(REACT_PASSIVE);

        Summoned = false;

        MightyBlowTimer = 10000;
    }

    void EnterCombat(Unit* who)
    {
        if (pInstance)
            pInstance->SetData(DATA_DRAKKARI_COLOSSUS_EVENT, IN_PROGRESS);
    }

    void PrepareToSummonElemental()
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->addUnitState(UNIT_STAT_STUNNED);
        m_creature->CastSpell(m_creature,SPELL_EMERGE,false);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (Summoned == false && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 50 && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() > 6)
        {
            PrepareToSummonElemental();
            m_creature->CastSpell(m_creature->getVictim(), SPELL_EMERGE_2, true);
            Summoned = true;
        }

        if (Summoned == true && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 5)
        {
            m_creature->RemoveAllAuras();
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            m_creature->addUnitState(UNIT_STAT_STUNNED);
            m_creature->RemoveAllAuras();

            Summoned = false;
        }

        if (MightyBlowTimer < diff)
        {
            if (!m_creature->hasUnitState(UNIT_STAT_STUNNED))
            {
                m_creature->CastSpell(m_creature->getVictim(),SPELL_MIGHTY_BLOW,true);
            }

            MightyBlowTimer = 10000;
        } else MightyBlowTimer -= diff;

        if (!m_creature->hasUnitState(UNIT_STAT_STUNNED))
            DoMeleeAttackIfReady();
    }

    void JustDied(Unit* killer)
    {
        if (pInstance)
            pInstance->SetData(DATA_DRAKKARI_COLOSSUS_EVENT, DONE);
    }

    void JustSummoned(Creature* summoned)
    {
        summoned->AI()->AttackStart(m_creature->getVictim());
    }
};

struct TRINITY_DLL_DECL boss_drakkari_elementalAI : public ScriptedAI
{
    boss_drakkari_elementalAI(Creature *c) : ScriptedAI(c)
    {
        Colossus = c->FindNearestCreature(DRAKKARI_COLOSSUS, 30.0f, true);
    }

    Creature* Colossus;

    uint32 SurgeTimer;

    bool PreparationDone;
    bool GoToColossus;
    bool Checked;

    void Reset()
    {
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->clearUnitState(UNIT_STAT_STUNNED);

        SurgeTimer = 7000;

        GoToColossus = false;
        PreparationDone = false;
        Checked = false;
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if(!UpdateVictim())
            return;

        if(GoToColossus == false && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 50)
        {
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            m_creature->CastSpell(Colossus ,SPELL_MERGE,true);

            GoToColossus = true;
            PreparationDone = true;
        }

        if(GoToColossus == true && PreparationDone == true)
        {
            m_creature->addUnitState(UNIT_STAT_STUNNED);
            m_creature->SetVisibility(VISIBILITY_OFF);
            m_creature->CastSpell(Colossus ,SPELL_MERGE,true);

            PreparationDone = false;

            Colossus->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            Colossus->clearUnitState(UNIT_STAT_STUNNED);
        }

        if (SurgeTimer < diff)
        {
            if(m_creature->GetVisibility() == VISIBILITY_ON)
            {
                Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0);
                m_creature->CastSpell(target,SPELL_SURGE,false);
            }

            SurgeTimer = 7000;
        } else SurgeTimer -= diff;

        if(Checked == false && Colossus->GetHealth()*100 / Colossus->GetMaxHealth() <= 5)
        {
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            m_creature->clearUnitState(UNIT_STAT_STUNNED);
            m_creature->SetVisibility(VISIBILITY_ON);
            Checked = true;
        }

        //prevent do melee if is invisible
        if(m_creature->GetVisibility() == VISIBILITY_ON)
            DoMeleeAttackIfReady();
    }

    void JustDied(Unit* killer)
    {
        Colossus->Kill(Colossus);
        Colossus->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
    }
};

struct TRINITY_DLL_DECL npc_living_mojoAI : public ScriptedAI
{
    npc_living_mojoAI(Creature *c) : ScriptedAI(c)
    {
        HeroicMode = c->GetMap()->IsHeroic();
    }

    bool HeroicMode;

    uint32 MojoWaveTimer;
    uint32 MojoPuddleTimer;

    void Reset()
    {
        //Check if the npc is near of Drakkari Colossus.
        if (m_creature->IsInRange3d(1672.959,743.487,143.337,0.0f,17.0f))
            m_creature->SetReactState(REACT_PASSIVE);
        else
        {
            m_creature->SetReactState(REACT_AGGRESSIVE);
            MojoWaveTimer = 2000;
            MojoPuddleTimer = 7000;
        }
    }

    void DamageTaken(Unit* pDone_by, uint32& uiDamage)
    {
        if (m_creature->HasReactState(REACT_PASSIVE))
        {
            if (Creature* Colossus = m_creature->FindNearestCreature(DRAKKARI_COLOSSUS, 30.0f, true))
            {
                Colossus->RemoveAura(SPELL_FREEZE_ANIM);
                Colossus->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                Colossus->SetReactState(REACT_AGGRESSIVE);
                Colossus->AI()->AttackStart(pDone_by);
                EnterEvadeMode();
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (MojoWaveTimer < diff)
        {
            DoCast(m_creature->getVictim(), HEROIC(SPELL_MOJO_WAVE, H_SPELL_MOJO_WAVE));
            MojoWaveTimer = 15000;
        } else MojoWaveTimer -= diff;

        if (MojoPuddleTimer < diff)
        {
            DoCast(m_creature->getVictim(), HEROIC(SPELL_MOJO_PUDDLE, H_SPELL_MOJO_PUDDLE));
            MojoPuddleTimer = 18000;
        } else MojoPuddleTimer -= diff;

        DoMeleeAttackIfReady();
    }

};

CreatureAI* GetAI_boss_drakkari_colossus(Creature* pCreature)
{
    return new boss_drakkari_colossusAI (pCreature);
}

CreatureAI* GetAI_boss_drakkari_elemental(Creature* pCreature)
{
    return new boss_drakkari_elementalAI (pCreature);
}

CreatureAI* GetAI_npc_living_mojo(Creature* pCreature)
{
    return new npc_living_mojoAI (pCreature);
}

void AddSC_boss_drakkari_colossus()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_drakkari_colossus";
    newscript->GetAI = &GetAI_boss_drakkari_colossus;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_drakkari_elemental";
    newscript->GetAI = &GetAI_boss_drakkari_elemental;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_living_mojo";
    newscript->GetAI = &GetAI_npc_living_mojo;
    newscript->RegisterSelf();
}

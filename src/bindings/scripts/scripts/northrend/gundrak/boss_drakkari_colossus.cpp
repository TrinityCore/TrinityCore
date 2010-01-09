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

    SPELL_MIGHTY_BLOW   = 54719,

    SPELL_MERGE         = 54878,
    SPELL_SURGE         = 54801,

    SPELL_FREEZE_ANIM   = 16245,

    SPELL_MOJO_PUDDLE   = 55627,
    H_SPELL_MOJO_PUDDLE = 58994,

    SPELL_MOJO_WAVE     = 55626,
    H_SPELL_MOJO_WAVE   = 58993
};

struct TRINITY_DLL_DECL boss_drakkari_colossusAI : public ScriptedAI
{
    boss_drakkari_colossusAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    bool bHealth;
    bool bHealth1;

    uint32 MightyBlowTimer;

    void Reset()
    {
        if (pInstance)
            pInstance->SetData(DATA_DRAKKARI_COLOSSUS_EVENT, NOT_STARTED);
        if(!m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE))
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        m_creature->clearUnitState(UNIT_STAT_STUNNED | UNIT_STAT_ROOT);
        m_creature->SetReactState(REACT_PASSIVE);
        MightyBlowTimer = 10000;
        bHealth = false;
        bHealth1 = false;
    }

    void EnterCombat(Unit* who)
    {
        if (pInstance)
            pInstance->SetData(DATA_DRAKKARI_COLOSSUS_EVENT, IN_PROGRESS);
    }

    void CreatureState(Creature* pWho, bool bRestore = false)
    {
        if (!pWho)
            return;

        if (bRestore)
        {
            pWho->clearUnitState(UNIT_STAT_STUNNED | UNIT_STAT_ROOT);
            pWho->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            if (pWho == m_creature)
                m_creature->RemoveAura(SPELL_FREEZE_ANIM);
        }else
        {
            pWho->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            pWho->addUnitState(UNIT_STAT_STUNNED | UNIT_STAT_ROOT);
            if (pWho == m_creature)
                DoCast(m_creature,SPELL_FREEZE_ANIM);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (!bHealth && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 50 &&  m_creature->GetHealth()*100 / m_creature->GetMaxHealth() >= 6)
        {
            CreatureState(m_creature, false);
            DoCast(m_creature,SPELL_FREEZE_ANIM);
            DoCast(m_creature,SPELL_EMERGE);
            bHealth = true;
        }

        if (!bHealth1 && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 5)
        {
            DoCast(m_creature,SPELL_EMERGE);
            CreatureState(m_creature, false);
            bHealth1 = true;
            m_creature->RemoveAllAuras();
        }

        if (MightyBlowTimer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_MIGHTY_BLOW, true);
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

    void JustSummoned(Creature* pSummon)
    {
        if (m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 5)
            pSummon->DealDamage(pSummon, pSummon->GetHealth() * 0.5 , NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
        pSummon->AI()->AttackStart(m_creature->getVictim());
    }
};

struct TRINITY_DLL_DECL boss_drakkari_elementalAI : public ScriptedAI
{
    boss_drakkari_elementalAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();
        if(pInstance)
        {
            if (pCreature->GetMap()->IsDungeon())
                pColossus = CAST_CRE(pCreature->GetUnit(*pCreature, pInstance->GetData64(DATA_DRAKKARI_COLOSSUS)));
        }
    }

    Creature* pColossus;

    ScriptedInstance* pInstance;

    uint32 uiSurgeTimer;

    bool bGoToColossus;

    void Reset()
    {
        if (pColossus)
            CAST_AI(boss_drakkari_colossusAI, pColossus->AI())->CreatureState(m_creature, true);
        uiSurgeTimer = 7000;
        bGoToColossus = false;
    }

    void EnterEvadeMode()
    {
        m_creature->RemoveFromWorld();
    }

    void MovementInform(uint32 uiType, uint32 uiId)
    {
        if (uiType != POINT_MOTION_TYPE)
            return;
        CAST_AI(boss_drakkari_colossusAI, pColossus->AI())->CreatureState(pColossus, true);
        CAST_AI(boss_drakkari_colossusAI, pColossus->AI())->bHealth1 = false;
        m_creature->RemoveFromWorld();
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if(!UpdateVictim())
            return;

        if(!bGoToColossus && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 50 && pColossus->GetHealth()*100 / pColossus->GetMaxHealth() >= 6)
        {
            m_creature->InterruptNonMeleeSpells(true);
            if (pColossus)
                DoCast(pColossus, SPELL_MERGE);
            bGoToColossus = true;
        }

        if (uiSurgeTimer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_SURGE);
            uiSurgeTimer = 7000;
        } else uiSurgeTimer -= diff;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* killer)
    {
        if (!pColossus)
            return;
        pColossus->Kill(pColossus);
    }
};

struct TRINITY_DLL_DECL npc_living_mojoAI : public ScriptedAI
{
    npc_living_mojoAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        HeroicMode = pCreature->GetMap()->IsHeroic();
        pInstance = pCreature->GetInstanceData();
    }

    Creature* pColossus;

    ScriptedInstance* pInstance;

    bool HeroicMode;

    uint32 uiMojoWaveTimer;
    uint32 uiMojoPuddleTimer;

    void Reset()
    {
        uiMojoWaveTimer = 2000;
        uiMojoPuddleTimer = 7000;
    }

    void EnterCombat(Unit* who)
    {
        if (pInstance)
            pColossus = m_creature->GetCreature(*m_creature, pInstance->GetData64(DATA_DRAKKARI_COLOSSUS));

        //Check if the npc is near of Drakkari Colossus.
        if (pColossus && pColossus->isAlive() && m_creature->IsInRange3d(pColossus->GetHomePosition().GetPositionX(),pColossus->GetHomePosition().GetPositionY(),pColossus->GetHomePosition().GetPositionZ(),0.0f,17.0f))
            m_creature->SetReactState(REACT_PASSIVE);
        else
            m_creature->SetReactState(REACT_AGGRESSIVE);
    }

    void DamageTaken(Unit* pDone_by, uint32& uiDamage)
    {
        if (m_creature->HasReactState(REACT_PASSIVE))
        {
            if (pColossus && pColossus->isAlive() && !pColossus->isInCombat())
            {
                pColossus->RemoveAura(SPELL_FREEZE_ANIM);
                pColossus->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                pColossus->SetReactState(REACT_AGGRESSIVE);
                if (pDone_by && pDone_by->isAlive())
                    pColossus->AI()->AttackStart(pDone_by);
                EnterEvadeMode();
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (uiMojoWaveTimer <= diff)
        {
            DoCast(m_creature->getVictim(), HEROIC(SPELL_MOJO_WAVE, H_SPELL_MOJO_WAVE));
            uiMojoWaveTimer = 15000;
        } else uiMojoWaveTimer -= diff;

        if (uiMojoPuddleTimer <= diff)
        {
            DoCast(m_creature->getVictim(), HEROIC(SPELL_MOJO_PUDDLE, H_SPELL_MOJO_PUDDLE));
            uiMojoPuddleTimer = 18000;
        } else uiMojoPuddleTimer -= diff;

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
    Script* newscript;

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

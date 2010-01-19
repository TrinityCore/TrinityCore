/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Boss_Broggok
SD%Complete: 70
SDComment: pre-event not made
SDCategory: Hellfire Citadel, Blood Furnace
EndScriptData */

#include "ScriptedPch.h"
#include "blood_furnace.h"

enum eEnums
{
    SAY_AGGRO               = -1542008,

    SPELL_SLIME_SPRAY       = 30913,
    SPELL_POISON_CLOUD      = 30916,
    SPELL_POISON_BOLT       = 30917,

    SPELL_POISON            = 30914
};

struct TRINITY_DLL_DECL boss_broggokAI : public ScriptedAI
{
    boss_broggokAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    uint32 AcidSpray_Timer;
    uint32 PoisonSpawn_Timer;
    uint32 PoisonBolt_Timer;

    void Reset()
    {
        AcidSpray_Timer = 10000;
        PoisonSpawn_Timer = 5000;
        PoisonBolt_Timer = 7000;
        if (pInstance)
        {
            pInstance->SetData(TYPE_BROGGOK_EVENT, NOT_STARTED);
            pInstance->HandleGameObject(pInstance->GetData64(DATA_DOOR4), true);
        }
    }

    void EnterCombat(Unit *who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        if (pInstance)
        {
            pInstance->SetData(TYPE_BROGGOK_EVENT, IN_PROGRESS);
            pInstance->HandleGameObject(pInstance->GetData64(DATA_DOOR4), false);
        }
    }

    void JustSummoned(Creature *summoned)
    {
        summoned->setFaction(16);
        summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        summoned->CastSpell(summoned,SPELL_POISON,false,0,0,m_creature->GetGUID());
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (AcidSpray_Timer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_SLIME_SPRAY);
            AcidSpray_Timer = 4000+rand()%8000;
        } else AcidSpray_Timer -=diff;

        if (PoisonBolt_Timer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_POISON_BOLT);
            PoisonBolt_Timer = 4000+rand()%8000;
        } else PoisonBolt_Timer -=diff;

        if (PoisonSpawn_Timer <= diff)
        {
            DoCast(m_creature, SPELL_POISON_CLOUD);
            PoisonSpawn_Timer = 20000;
        } else PoisonSpawn_Timer -=diff;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* who)
    {
        if (pInstance)
        {
            pInstance->HandleGameObject(pInstance->GetData64(DATA_DOOR4), true);
            pInstance->HandleGameObject(pInstance->GetData64(DATA_DOOR5), true);
            pInstance->SetData(TYPE_BROGGOK_EVENT, DONE);
        }
    }

};

CreatureAI* GetAI_boss_broggok(Creature* pCreature)
{
    return new boss_broggokAI (pCreature);
}

void AddSC_boss_broggok()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_broggok";
    newscript->GetAI = &GetAI_boss_broggok;
    newscript->RegisterSelf();
}

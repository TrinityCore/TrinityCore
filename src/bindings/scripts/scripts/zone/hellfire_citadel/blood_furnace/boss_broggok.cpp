/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SD%Complete: 100
SDComment:
SDCategory: Hellfire Citadel, Blood Furnace
EndScriptData */

#include "precompiled.h"

#define SPELL_SLIME_SPRAY       30913
#define SPELL_POISON_CLOUD      30916
#define SPELL_POISON_BOLT       30917

#define SPELL_POISON            30914

#define SAY_AGGRO "Come intruders...."

struct MANGOS_DLL_DECL boss_broggokAI : public ScriptedAI
{
    boss_broggokAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 AcidSpray_Timer;
    uint32 PoisonSpawn_Timer;
    uint32 PoisonBolt_Timer;

    void Reset()
    {
        AcidSpray_Timer = 10000;
        PoisonSpawn_Timer = 5000;
        PoisonBolt_Timer = 7000;
    }

    void Aggro(Unit *who)
    {
        DoYell(SAY_AGGRO, LANG_UNIVERSAL, NULL);
    }

    void UpdateAI(const uint32 diff)
    {

        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if(AcidSpray_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_SLIME_SPRAY);
            AcidSpray_Timer = 4000+rand()%8000;
        }else AcidSpray_Timer -=diff;

        if(PoisonBolt_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_POISON_BOLT);
            PoisonBolt_Timer = 4000+rand()%8000;
        }else PoisonBolt_Timer -=diff;

        if(PoisonSpawn_Timer < diff)
        {
            DoCast(m_creature,SPELL_POISON_CLOUD);
            PoisonSpawn_Timer = 20000;
        }else PoisonSpawn_Timer -=diff;

        DoMeleeAttackIfReady();
    }
};

struct MANGOS_DLL_DECL mob_broggok_poisoncloudAI : public ScriptedAI
{
    mob_broggok_poisoncloudAI(Creature *c) : ScriptedAI(c) {Reset();}

    bool Start;

    void Reset()
    {
        Start = false;
    }

    void Aggro(Unit* who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        if(!Start)
        {
            m_creature->SetUInt32Value(UNIT_NPC_FLAGS,0);
            m_creature->setFaction(45);
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            Start = true;
            DoCast(m_creature,SPELL_POISON);
        }
    }
};

CreatureAI* GetAI_boss_broggokAI(Creature *_Creature)
{
    return new boss_broggokAI (_Creature);
}

CreatureAI* GetAI_mob_broggok_poisoncloudAI(Creature *_Creature)
{
    return new mob_broggok_poisoncloudAI (_Creature);
}

void AddSC_boss_broggok()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_broggok";
    newscript->GetAI = GetAI_boss_broggokAI;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mob_broggok_poisoncloud";
    newscript->GetAI = GetAI_mob_broggok_poisoncloudAI;
    m_scripts[nrscripts++] = newscript;
}

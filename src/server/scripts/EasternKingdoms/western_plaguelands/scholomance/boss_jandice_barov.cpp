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
SDName: Boss_jandicebarov
SD%Complete: 100
SDComment:
SDCategory: Scholomance
EndScriptData */

#include "scriptPCH.h"

enum
{
    SPELL_CURSEOFBLOOD = 16098,
    SPELL_BANISH = 8994,
    SPELL_ILLUSION = 17773,
    SPELL_DROP_JOURNAL = 26096,
    SPELL_PHASING = 16122
};

#define SPELL_CURSEOFBLOOD          16098
#define SPELL_CLEAVE                15584

struct boss_jandicebarovAI : public ScriptedAI
{
    boss_jandicebarovAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 CurseOfBlood_Timer;
    uint32 Illusion_Timer;
    uint32 damageTaken;
    //uint32 Illusioncounter;
    std::vector<uint64> IllusionGUIDS;

    uint32 Invisible_Timer;
    bool Invisible;
    bool checkForDamage;

    void Reset() override
    {
        CurseOfBlood_Timer = 10000;
        Illusion_Timer = 15000;
        Invisible_Timer = 3000;                             //Too much too low?
        Invisible = false;
        damageTaken = 0;
        checkForDamage = false;
    }

    void SummonIllusions(Unit* victim)
    {
        if (Creature* summoned = DoSpawnCreature(11439, 10.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 60000))
            if (summoned->AI())
            {
                summoned->AI()->AttackStart(victim);
                IllusionGUIDS.push_back(summoned->GetGUID());
            }
    }

    void UnsummonIllusions()
    {
        // Despawn des adds (illusions)
        std::vector<uint64>::iterator itr;
        for (itr = IllusionGUIDS.begin(); itr != IllusionGUIDS.end(); ++itr)
        {
            if (Creature* illusion = m_creature->GetMap()->GetCreature(*itr))
                illusion->AddObjectToRemoveList();
            else
                sLog.outString("Cannot find creature %u", *itr);
        }
        IllusionGUIDS.clear(); 
    }

    void JustDied(Unit *pKiller) override
    {
        UnsummonIllusions();
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->SetVisibility(VISIBILITY_ON);

        if (sWorld.GetWowPatch() > WOW_PATCH_108 && sWorld.getConfig(CONFIG_BOOL_ACCURATE_PVE_EVENTS))
        {
            DoCastSpellIfCan(m_creature, SPELL_DROP_JOURNAL, CF_TRIGGERED);
        }
    }

    void DamageTaken(Unit* /*pDealer*/, uint32& uiDamage) override
    {
        if (checkForDamage)
        {
            damageTaken += uiDamage;
            if (damageTaken > 500)
            {
                UnsummonIllusions();
                checkForDamage = false;
                damageTaken = 0;
            }
        }
    }

    void UpdateAI(uint32 const diff) override
    {
        if (Invisible && Invisible_Timer < diff)
        {
            //Become visible again
            m_creature->SetFactionTemplateId(14);
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            m_creature->SetVisibility(VISIBILITY_ON);
            Invisible = false;
            damageTaken = 0;
            checkForDamage = true;
        }
        else if (Invisible)
        {
            Invisible_Timer -= diff;
            //Do nothing while invisible
            return;
        }

        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //CurseOfBlood_Timer
        if (CurseOfBlood_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CURSEOFBLOOD);
            CurseOfBlood_Timer = 30000;
        }
        else
            CurseOfBlood_Timer -= diff;

        //Illusion_Timer
        if (!Invisible && Illusion_Timer < diff)
        {
            //Inturrupt any spell casting
            m_creature->InterruptNonMeleeSpells(false);
            m_creature->SetFactionTemplateId(35);
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            m_creature->GetThreatManager().modifyThreatPercent(m_creature->GetVictim(), -99);
            m_creature->SetVisibility(VISIBILITY_OFF);

            damageTaken = 0;
            Invisible = true;
            Invisible_Timer = 3000;

            //25 seconds until we should cast this agian
            Illusion_Timer = 25000;

            //Summon 10 Illusions attacking random gamers
            Unit* target = nullptr;
            for (int i = 0; i < 10; ++i)
            {
                target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
                SummonIllusions(target);
            }
        }
        else
            Illusion_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

// Illusion of Jandice Barov Script

struct mob_illusionofjandicebarovAI : public ScriptedAI
{
    mob_illusionofjandicebarovAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 Cleave_Timer;

    void Reset() override
    {
        Cleave_Timer = urand(2000, 8000);
        m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, true);
    }

    void UpdateAI(uint32 const diff) override
    {
        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //Cleave_Timer
        if (Cleave_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CLEAVE) == CAST_OK)
                Cleave_Timer = urand(5000, 15000);
        }
        else
            Cleave_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_jandicebarov(Creature* pCreature)
{
    return new boss_jandicebarovAI(pCreature);
}

CreatureAI* GetAI_mob_illusionofjandicebarov(Creature* pCreature)
{
    return new mob_illusionofjandicebarovAI(pCreature);
}

void AddSC_boss_jandicebarov()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_jandice_barov";
    newscript->GetAI = &GetAI_boss_jandicebarov;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_illusionofjandicebarov";
    newscript->GetAI = &GetAI_mob_illusionofjandicebarov;
    newscript->RegisterSelf();
}

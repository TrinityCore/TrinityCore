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
SDName: Boss_Gahz'ranka
SD%Complete: 85
SDComment: Massive Geyser with knockback not working. Spell buggy.
SDCategory: Zul'Gurub
EndScriptData */

#include "scriptPCH.h"
#include "zulgurub.h"

enum
{
    // Datas :

    // Gahz'ranka's spells
    // -------------------

    // Frost Breath - Slow attack and movement speed, drains mana.
    SPELL_FROSTBREATH            = 16099,

    // Massive Geyser - Tosses everyone into the air for 500 damage, then subsequent fall damage. Temporary aggro wipe.
    SPELL_MASSIVEGEYSER          = 22421, //Not working. Cause its a summon...

    // Slam - Inflicts normal damage plus 250 to nearby enemies and knocks them back.
    SPELL_SLAM                   = 24326
};

struct boss_gahzrankaAI : public ScriptedAI
{
    boss_gahzrankaAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
        CheckSpawnStatus();
    }

    ScriptedInstance* m_pInstance;

    uint32 Frostbreath_Timer;
    uint32 MassiveGeyser_Timer;
    uint32 Slam_Timer;

    void Reset() override
    {
        Frostbreath_Timer = 8000;
        MassiveGeyser_Timer = 25000;
        Slam_Timer = 17000;

        if (m_pInstance && m_pInstance->GetData(TYPE_GAHZRANKA) != DONE)
            m_pInstance->SetData(TYPE_GAHZRANKA, NOT_STARTED);
    }
    void Aggro(Unit *who) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_GAHZRANKA, IN_PROGRESS);
    }
    void JustDied(Unit* Killer) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_GAHZRANKA, DONE);
    }

    void JustRespawned() override
    {
        CheckSpawnStatus();
    }

   void CheckSpawnStatus()
   {
        if (!m_pInstance)
            return;

        if (m_pInstance->GetData(TYPE_GAHZRANKA) != IN_PROGRESS)
        {
            m_creature->DisappearAndDie();
            m_creature->SetRespawnTime(259200);
        }
        else
        {
            m_creature->GetMotionMaster()->MovePoint(0, -11709.3476f, -1749.965f, 8.733f, 0, 0, 5.3478f);
            m_creature->SetHomePosition(-11688.95f, -1777.21f, 12.593f, 5.81f);
        }
    }

    void MovementInform(uint32 uiType, uint32 uiPointId) override
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        if (uiPointId == 0) // move to the Beach
            m_creature->GetMotionMaster()->MovePoint(1, -11688.95f, -1777.21f, 12.593f, 0, 0, 5.81f);
    } 

    void UpdateAI(uint32 const diff) override
    {
        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //Frostbreath_Timer
        if (Frostbreath_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_FROSTBREATH) == CAST_OK)
                Frostbreath_Timer = urand(8000, 20000);
        }
        else Frostbreath_Timer -= diff;

        //MassiveGeyser_Timer
        if (MassiveGeyser_Timer < diff)
        {
            if (Unit* target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            {
                if (DoCastSpellIfCan(target, SPELL_MASSIVEGEYSER) == CAST_OK)
                {
                    MassiveGeyser_Timer = urand(16000, 24000);
                    DoResetThreat();
                }
            }
        }
        else MassiveGeyser_Timer -= diff;

        //Slam_Timer
        if (Slam_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SLAM) == CAST_OK)
                Slam_Timer = urand(12000, 20000);
        }
        else Slam_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_gahzranka(Creature* pCreature)
{
    return new boss_gahzrankaAI(pCreature);
}

void AddSC_boss_gahzranka()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_gahzranka";
    newscript->GetAI = &GetAI_boss_gahzranka;
    newscript->RegisterSelf();
}

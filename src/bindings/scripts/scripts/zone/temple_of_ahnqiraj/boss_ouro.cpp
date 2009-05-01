/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Ouro
SD%Complete: 85
SDComment: No model for submerging. Currently just invisible.
SDCategory: Temple of Ahn'Qiraj
EndScriptData */

#include "precompiled.h"
#include "def_temple_of_ahnqiraj.h"

#define SPELL_SWEEP             26103
#define SPELL_SANDBLAST         26102
#define SPELL_GROUND_RUPTURE    26100
#define SPELL_BIRTH             26262                       //The Birth Animation

#define SPELL_DIRTMOUND_PASSIVE 26092

struct TRINITY_DLL_DECL boss_ouroAI : public ScriptedAI
{
    boss_ouroAI(Creature *c) : ScriptedAI(c) {}

    uint32 Sweep_Timer;
    uint32 SandBlast_Timer;
    uint32 Submerge_Timer;
    uint32 Back_Timer;
    uint32 ChangeTarget_Timer;
    uint32 Spawn_Timer;

    bool Enrage;
    bool Submerged;
    bool InCombat;

    void Reset()
    {
        Sweep_Timer = 5000 + rand()%5000;
        SandBlast_Timer = 20000 + rand()%15000;
        Submerge_Timer = 90000 + rand()%60000;
        Back_Timer = 30000 + rand()%15000;
        ChangeTarget_Timer = 5000 + rand()%3000;
        Spawn_Timer = 10000 + rand()%10000;

        Enrage = false;
        Submerged = false;
    }

    void EnterCombat(Unit *who)
    {
        DoCast(m_creature->getVictim(), SPELL_BIRTH);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        //Sweep_Timer
        if (!Submerged && Sweep_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_SWEEP);
            Sweep_Timer = 15000 + rand()%15000;
        }else Sweep_Timer -= diff;

        //SandBlast_Timer
        if (!Submerged && SandBlast_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_SANDBLAST);
            SandBlast_Timer = 20000 + rand()%15000;
        }else SandBlast_Timer -= diff;

        //Submerge_Timer
        if (!Submerged && Submerge_Timer < diff)
        {
            //Cast
            m_creature->HandleEmoteCommand(EMOTE_ONESHOT_SUBMERGE);
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            m_creature->setFaction(35);
            DoCast(m_creature, SPELL_DIRTMOUND_PASSIVE);

            Submerged = true;
            Back_Timer = 30000 + rand()%15000;
        }else Submerge_Timer -= diff;

        //ChangeTarget_Timer
        if (Submerged && ChangeTarget_Timer < diff)
        {
            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM,0);

            if(target)
                DoTeleportTo(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());

            ChangeTarget_Timer = 10000 + rand()%10000;
        }else ChangeTarget_Timer -= diff;

        //Back_Timer
        if (Submerged && Back_Timer < diff)
        {
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            m_creature->setFaction(14);

            DoCast(m_creature->getVictim(), SPELL_GROUND_RUPTURE);

            Submerged = false;
            Submerge_Timer = 60000 + rand()%60000;
        }else Back_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_ouro(Creature *_Creature)
{
    return new boss_ouroAI (_Creature);
}

void AddSC_boss_ouro()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_ouro";
    newscript->GetAI = &GetAI_boss_ouro;
    newscript->RegisterSelf();
}


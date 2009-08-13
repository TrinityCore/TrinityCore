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
SDName: Boss_Noxxion
SD%Complete: 100
SDComment:
SDCategory: Maraudon
EndScriptData */

#include "precompiled.h"

#define SPELL_TOXICVOLLEY           21687
#define SPELL_UPPERCUT              22916

struct TRINITY_DLL_DECL boss_noxxionAI : public ScriptedAI
{
    boss_noxxionAI(Creature *c) : ScriptedAI(c) {}

    uint32 ToxicVolley_Timer;
    uint32 Uppercut_Timer;
    uint32 Adds_Timer;
    uint32 Invisible_Timer;
    bool Invisible;
    int Rand;
    int RandX;
    int RandY;
    Creature* Summoned;

    void Reset()
    {
        ToxicVolley_Timer = 7000;
        Uppercut_Timer = 16000;
        Adds_Timer = 19000;
        Invisible_Timer = 15000;                            //Too much too low?
        Invisible = false;
    }

    void EnterCombat(Unit *who)
    {
    }

    void SummonAdds(Unit* victim)
    {
        Rand = rand()%8;
        switch (rand()%2)
        {
            case 0: RandX = 0 - Rand; break;
            case 1: RandX = 0 + Rand; break;
        }
        Rand = 0;
        Rand = rand()%8;
        switch (rand()%2)
        {
            case 0: RandY = 0 - Rand; break;
            case 1: RandY = 0 + Rand; break;
        }
        Rand = 0;
        Summoned = DoSpawnCreature(13456, RandX, RandY, 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 90000);
        if (Summoned)
            (Summoned->AI())->AttackStart(victim);
    }

    void UpdateAI(const uint32 diff)
    {
        if (Invisible && Invisible_Timer < diff)
        {
            //Become visible again
            m_creature->setFaction(14);
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            //Noxxion model
            m_creature->SetDisplayId(11172);
            Invisible = false;
            //m_creature->m_canMove = true;
        } else if (Invisible)
        {
            Invisible_Timer -= diff;
            //Do nothing while invisible
            return;
        }

        //Return since we have no target
        if (!UpdateVictim())
            return;

        //ToxicVolley_Timer
        if (ToxicVolley_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_TOXICVOLLEY);
            ToxicVolley_Timer = 9000;
        }else ToxicVolley_Timer -= diff;

        //Uppercut_Timer
        if (Uppercut_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_UPPERCUT);
            Uppercut_Timer = 12000;
        }else Uppercut_Timer -= diff;

        //Adds_Timer
        if (!Invisible && Adds_Timer < diff)
        {
            //Inturrupt any spell casting
            //m_creature->m_canMove = true;
            m_creature->InterruptNonMeleeSpells(false);
            m_creature->setFaction(35);
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            // Invisible Model
            m_creature->SetDisplayId(11686);
            SummonAdds(m_creature->getVictim());
            SummonAdds(m_creature->getVictim());
            SummonAdds(m_creature->getVictim());
            SummonAdds(m_creature->getVictim());
            SummonAdds(m_creature->getVictim());
            Invisible = true;
            Invisible_Timer = 15000;

            Adds_Timer = 40000;
        }else Adds_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_noxxion(Creature *_Creature)
{
    return new boss_noxxionAI (_Creature);
}

void AddSC_boss_noxxion()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_noxxion";
    newscript->GetAI = &GetAI_boss_noxxion;
    newscript->RegisterSelf();
}


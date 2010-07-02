/* Copyright (C) 2008 - 2010 Trinity <http://www.trinitycore.org/>
 * Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Majordomo_Executus
SD%Complete: 30
SDComment: Correct spawning and Event NYI
SDCategory: Molten Core
EndScriptData */

#include "ScriptPCH.h"

#define SAY_AGGRO           -1409003
#define SAY_SPAWN           -1409004
#define SAY_SLAY            -1409005
#define SAY_SPECIAL         -1409006
#define SAY_DEFEAT          -1409007

#define SAY_SUMMON_MAJ      -1409008
#define SAY_ARRIVAL1_RAG    -1409009
#define SAY_ARRIVAL2_MAJ    -1409010
#define SAY_ARRIVAL3_RAG    -1409011
#define SAY_ARRIVAL5_RAG    -1409012

#define SPAWN_RAG_X         838.51
#define SPAWN_RAG_Y         -829.84
#define SPAWN_RAG_Z         -232.00
#define SPAWN_RAG_O         1.70

#define SPELL_MAGIC_REFLECTION      20619
#define SPELL_DAMAGE_REFLECTION     21075

#define SPELL_BLASTWAVE             20229
#define SPELL_AEGIS                 20620                   //This is self casted whenever we are below 50%
#define SPELL_TELEPORT              20618
#define SPELL_SUMMON_RAGNAROS       19774

#define ENTRY_FLAMEWALKER_HEALER    11663
#define ENTRY_FLAMEWALKER_ELITE     11664

struct boss_majordomoAI : public ScriptedAI
{
    boss_majordomoAI(Creature *c) : ScriptedAI(c) {}

    uint32 MagicReflection_Timer;
    uint32 DamageReflection_Timer;
    uint32 Blastwave_Timer;

    void Reset()
    {
        MagicReflection_Timer =  30000;                     //Damage reflection first so we alternate
        DamageReflection_Timer = 15000;
        Blastwave_Timer = 10000;
    }

    void KilledUnit(Unit* /*victim*/)
    {
        if (rand()%5)
            return;

        DoScriptText(SAY_SLAY, me);
    }

    void EnterCombat(Unit * /*who*/)
    {
        DoScriptText(SAY_AGGRO, me);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //Cast Ageis if less than 50% hp
        if (me->GetHealth()*100 / me->GetMaxHealth() < 50)
        {
            DoCast(me, SPELL_AEGIS);
        }

        //MagicReflection_Timer
        //        if (MagicReflection_Timer <= diff)
        //        {
        //            DoCast(me, SPELL_MAGICREFLECTION);

        //60 seconds until we should cast this agian
        //            MagicReflection_Timer = 30000;
        //        } else MagicReflection_Timer -= diff;

        //DamageReflection_Timer
        //        if (DamageReflection_Timer <= diff)
        //        {
        //            DoCast(me, SPELL_DAMAGEREFLECTION);

        //60 seconds until we should cast this agian
        //            DamageReflection_Timer = 30000;
        //        } else DamageReflection_Timer -= diff;

        //Blastwave_Timer
        if (Blastwave_Timer <= diff)
        {
            DoCast(me->getVictim(), SPELL_BLASTWAVE);
            Blastwave_Timer = 10000;
        } else Blastwave_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_majordomo(Creature* pCreature)
{
    return new boss_majordomoAI (pCreature);
}

void AddSC_boss_majordomo()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_majordomo";
    newscript->GetAI = &GetAI_boss_majordomo;
    newscript->RegisterSelf();
}


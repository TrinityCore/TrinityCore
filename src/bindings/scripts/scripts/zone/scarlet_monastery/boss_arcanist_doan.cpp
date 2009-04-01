/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Arcanist_Doan
SD%Complete: 100
SDComment:
SDCategory: Scarlet Monastery
EndScriptData */

#include "precompiled.h"

#define SPELL_POLYMORPH                 12826
#define SPELL_AOESILENCE                8988
#define SPELL_ARCANEEXPLOSION3          8438
#define SPELL_ARCANEEXPLOSION4          8439
#define SPELL_FIREAOE                   9435
#define SPELL_BLINK                     1953
#define SPELL_FIREBALL                  21162
#define SPELL_MANASHIELD4               10191
#define SPELL_ARCANEBUBBLE              9438

#define SAY_AGGRO                       "You will not defile these mysteries!"
#define SAY_SPECIALAE                   "Burn in righteous fire!"

#define SOUND_AGGRO                     5842
#define SOUND_SPECIALAE                 5843

struct TRINITY_DLL_DECL boss_arcanist_doanAI : public ScriptedAI
{
    boss_arcanist_doanAI(Creature *c) : ScriptedAI(c) {}

    uint32 FullAOE_Timer;
    uint32 Polymorph_Timer;
    uint32 Yell_Timer;
    uint32 ArcaneBubble_Timer;
    uint32 AoESilence_Timer;
    uint32 ArcaneExplosion3_Timer;
    uint32 ArcaneExplosion4_Timer;
    uint32 Blink_Timer;
    uint32 Fireball_Timer;
    uint32 ManaShield4_Timer;

    void Reset()
    {
        FullAOE_Timer = 5000;
        Polymorph_Timer = 1;
        Yell_Timer = 2000;
        ArcaneBubble_Timer = 3000;
        AoESilence_Timer = 20000;
        ArcaneExplosion3_Timer = 10000;
        ArcaneExplosion4_Timer = 10000;
        Blink_Timer = 40000;
        Fireball_Timer = 6000;
        ManaShield4_Timer = 70000;
    }

    void Aggro(Unit *who)
    {
        DoYell(SAY_AGGRO,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature,SOUND_AGGRO);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //If we are <50% hp cast Arcane Bubble and start casting SPECIAL FIRE AOE
        if (m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 50 && !m_creature->IsNonMeleeSpellCasted(false))
        {
            if (Polymorph_Timer < diff)
            {
                Unit* target = NULL;

                target = SelectUnit(SELECT_TARGET_RANDOM,0);
                if (target)DoCast(target,SPELL_POLYMORPH);
                Polymorph_Timer = 40000;
            }else Polymorph_Timer -= diff;

            if (Yell_Timer < diff)
            {
                DoYell(SAY_SPECIALAE,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature,SOUND_SPECIALAE);
                Yell_Timer = 40000;
            }else Yell_Timer -= diff;

            if (ArcaneBubble_Timer < diff)
            {
                DoCast(m_creature,SPELL_ARCANEBUBBLE);
                ArcaneBubble_Timer = 40000;
            }else ArcaneBubble_Timer -= diff;

            if (FullAOE_Timer < diff)
            {
                DoCast(m_creature->getVictim(),SPELL_FIREAOE);
                FullAOE_Timer = 40000;
            }else FullAOE_Timer -= diff;
        }

        //AoESilence_Timer
        if (AoESilence_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_AOESILENCE);
            AoESilence_Timer = 30000;
        }else AoESilence_Timer -= diff;

        //ArcaneExplosion3_Timer
        if (ArcaneExplosion3_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_ARCANEEXPLOSION3);
            ArcaneExplosion3_Timer = 8000;
        }else ArcaneExplosion3_Timer -= diff;

        //ArcaneExplosion4_Timer
        if (ArcaneExplosion4_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_ARCANEEXPLOSION4);
            ArcaneExplosion4_Timer = 10000;
        }else ArcaneExplosion4_Timer -= diff;

        //Blink_Timer
        if (Blink_Timer < diff)
        {
            DoCast(m_creature,SPELL_BLINK);
            Blink_Timer = 30000;
        }else Blink_Timer -= diff;

        //Fireball_Timer
        if (Fireball_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_FIREBALL);
            Fireball_Timer = 12000;
        }else Fireball_Timer -= diff;

        //ManaShiled4_Timer
        if (ManaShield4_Timer < diff)
        {
            DoCast(m_creature,SPELL_MANASHIELD4);
            ManaShield4_Timer = 70000;
        }else ManaShield4_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_arcanist_doan(Creature *_Creature)
{
    return new boss_arcanist_doanAI (_Creature);
}

void AddSC_boss_arcanist_doan()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_arcanist_doan";
    newscript->GetAI = &GetAI_boss_arcanist_doan;
    newscript->RegisterSelf();
}


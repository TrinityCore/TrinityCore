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
SDName: Boss_Scarlet_Commander_Mograine
SD%Complete: 100
SDComment: Missing revive
SDCategory: Scarlet Monastery
EndScriptData */

#include "precompiled.h"

#define SPELL_DIVINESHIELD2         1020
#define SPELL_CRUSADERSTRIKE5       35395
#define SPELL_HAMMEROFJUSTICE3      5589
#define SPELL_HOLYLIGHT6            3472
#define SPELL_CONSECRATION3         20922
#define SPELL_BLESSINGOFWISDOM      1044
#define SPELL_RETRIBUTIONAURA3      10299
#define SPELL_BLESSINGOFPROTECTION3 10278
#define SPELL_FLASHHEAL6            10916

#define SAY_AGGRO                   "Infidels! They must be purified!"
#define SAY_RES                     "At your side, milady!"
#define SAY_DEATH                   "Unworthy!"

#define SOUND_AGGRO                 5835
#define SOUND_RES                   5837
#define SOUND_DEATH                 5836

struct TRINITY_DLL_DECL boss_scarlet_commander_mograineAI : public ScriptedAI
{
    boss_scarlet_commander_mograineAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 Heal_Timer;
    uint32 DivineShield2_Timer;
    uint32 CrusaderStrike5_Timer;
    uint32 HammerOfJustice3_Timer;
    uint32 Consecration3_Timer;
    uint32 BlessingOfWisdom_Timer;
    uint32 BlessingOfProtection3_Timer;

    void Reset()
    {
        Heal_Timer = 80000;
        DivineShield2_Timer = 60000;
        CrusaderStrike5_Timer = 20000;
        HammerOfJustice3_Timer = 80000;
        Consecration3_Timer = 30000;
        BlessingOfWisdom_Timer = 45000;
        BlessingOfProtection3_Timer = 45000;
    }

    void Aggro(Unit *who)
    {
        DoYell(SAY_AGGRO,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature,SOUND_AGGRO);
        DoCast(m_creature,SPELL_RETRIBUTIONAURA3);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        //If we are <50% hp cast Arcane Bubble and start casting SPECIAL Arcane Explosion
        if ( m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 50 && !m_creature->IsNonMeleeSpellCasted(false))
        {
            //heal_Timer
            if (Heal_Timer < diff)
            {
                //Switch between 2 different charge methods
                switch (rand()%2)
                {
                    case 0:
                        DoCast(m_creature,SPELL_HOLYLIGHT6);
                        break;
                    case 1:
                        DoCast(m_creature,SPELL_FLASHHEAL6);
                        break;
                }
                return;

                //60 seconds until we should cast this agian
                Heal_Timer = 60000;
            }else Heal_Timer -= diff;
        }

        //DivineShield2_Timer
        if (DivineShield2_Timer < diff)
        {
            DoCast(m_creature,SPELL_DIVINESHIELD2);
            DivineShield2_Timer = 60000;
        }else DivineShield2_Timer -= diff;

        //CrusaderStrike5_Timer
        if (CrusaderStrike5_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_CRUSADERSTRIKE5);
            CrusaderStrike5_Timer = 20000;
        }else CrusaderStrike5_Timer -= diff;

        //HammerOfJustice3_Timer
        if (HammerOfJustice3_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_HAMMEROFJUSTICE3);
            HammerOfJustice3_Timer = 30000;
        }else HammerOfJustice3_Timer -= diff;

        //Consecration3_Timer
        if (Consecration3_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_CONSECRATION3);
            Consecration3_Timer = 20000;
        }else Consecration3_Timer -= diff;

        //BlessingOfWisdom_Timer
        if (BlessingOfWisdom_Timer < diff)
        {
            DoCast(m_creature,SPELL_BLESSINGOFWISDOM);
            BlessingOfWisdom_Timer = 45000;
        }else BlessingOfWisdom_Timer -= diff;

        //BlessingOfProtection3_Timer
        if (BlessingOfProtection3_Timer < diff)
        {
            DoCast(m_creature,SPELL_BLESSINGOFPROTECTION3);
            BlessingOfProtection3_Timer = 50000;
        }else BlessingOfProtection3_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_scarlet_commander_mograine(Creature *_Creature)
{
    return new boss_scarlet_commander_mograineAI (_Creature);
}

void AddSC_boss_scarlet_commander_mograine()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_scarlet_commander_mograine";
    newscript->GetAI = GetAI_boss_scarlet_commander_mograine;
    m_scripts[nrscripts++] = newscript;
}

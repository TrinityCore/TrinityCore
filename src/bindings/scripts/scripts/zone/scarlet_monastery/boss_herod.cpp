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
SDName: Boss_Herod
SD%Complete: 90
SDComment: Missing adds spawn at death
SDCategory: Scarlet Monastery
EndScriptData */

#include "precompiled.h"

#define SPELL_RUSHINGCHARGE         32021
#define SPELL_RUSHINGCHARGE1        6268

#define SPELL_CLEAVE                11608
#define SPELL_WHIRLWIND             8989
#define SPELL_SUNDERARMOR           16145
#define SPELL_REND                  21949
#define SPELL_THUNDERCLAP           15588
#define SPELL_SLAM                  11430
#define SPELL_BERSERKERSTANCE       2458
#define SPELL_ENRAGE                28747
#define SPELL_FIREBALL11            10151
#define SPELL_CONEOFCOLD5           10161

#define SAY_AGGRO                   "Ah, I have been waiting for a real challenge!"
#define SAY_WHIRLWIND               "Blades of Light!"
#define SAY_ENRAGE                  "Light, give me strength!"
#define SAY_DEATH                   "Hah, is that all?"

#define SOUND_AGGRO                 5830
#define SOUND_WHIRLWIND             5832
#define SOUND_ENRAGE                5833
#define SOUND_DEATH                 5831

struct TRINITY_DLL_DECL boss_herodAI : public ScriptedAI
{
    boss_herodAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 Yell_Timer;
    uint32 Enrage_Timer;
    uint32 Cleave_Timer;
    uint32 Whirlwind_Timer;
    uint32 SunderArmor_Timer;
    uint32 Rend_Timer;
    uint32 ThunderClap_Timer;
    uint32 Slam_Timer;
    uint32 Fireball11_Timer;
    uint32 ConeOfCold5_Timer;

    void Reset()
    {
        Yell_Timer = 58000;
        Whirlwind_Timer = 60000;
        Enrage_Timer = 0;
        Cleave_Timer = 15000;
        SunderArmor_Timer = 40000;
        Rend_Timer = 25000;
        ThunderClap_Timer = 25000;
        Slam_Timer = 20000;
        Fireball11_Timer = 30000;
        ConeOfCold5_Timer = 40000;
    }

    void Aggro(Unit *who)
    {
        DoYell(SAY_AGGRO,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature,SOUND_AGGRO);

        //Activate Berserker Stance
        DoCast(m_creature,SPELL_BERSERKERSTANCE);

        //Switch between 2 different charge methods
        switch (rand()%2)
        {
            case 0:
                DoCast(m_creature,SPELL_RUSHINGCHARGE);
                break;
            case 1:
                DoCast(m_creature,SPELL_RUSHINGCHARGE1);
                break;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        //If we are <10% hp goes Enraged
        if ( m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 10 && !m_creature->IsNonMeleeSpellCasted(false) && Enrage_Timer < diff)
        {
            DoYell(SAY_ENRAGE,LANG_UNIVERSAL,NULL);
            DoPlaySoundToSet(m_creature,SOUND_ENRAGE);

            DoCast(m_creature,SPELL_ENRAGE);

            //Shouldn't cast this agian
            Enrage_Timer = diff;
        }

        //Cleave_Timer
        if (Cleave_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_CLEAVE);
            Cleave_Timer = 15000;
        }else Cleave_Timer -= diff;

        //Yelling and Whirlwind casting
        if (Yell_Timer < diff)
        {
            //Say Whirlwind monologe
            DoYell(SAY_WHIRLWIND,LANG_UNIVERSAL,NULL);
            DoPlaySoundToSet(m_creature,SOUND_WHIRLWIND);

            Yell_Timer = 30000;
        }else Yell_Timer -= diff;

        if (Whirlwind_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_WHIRLWIND);
            Whirlwind_Timer = 30000;
        }else Whirlwind_Timer -= diff;

        //SunderArmor_Timer
        if (SunderArmor_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_SUNDERARMOR);
            SunderArmor_Timer = 40000;
        }else SunderArmor_Timer -= diff;

        //Rend_Timer
        if (Rend_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_REND);
            Rend_Timer = 25000;
        }else Rend_Timer -= diff;

        //ThunderClap_Timer
        if (ThunderClap_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_THUNDERCLAP);
            ThunderClap_Timer = 20000;
        }else ThunderClap_Timer -= diff;

        //Slam_Timer
        if (Slam_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_SLAM);
            Slam_Timer = 20000;
        }else Slam_Timer -= diff;

        //Fireball11_Timer
        if (Fireball11_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_FIREBALL11);
            Fireball11_Timer = 30000;
        }else Fireball11_Timer -= diff;

        //ConeOfCold5_Timer
        if (ConeOfCold5_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_CONEOFCOLD5);
            ConeOfCold5_Timer = 40000;
        }else ConeOfCold5_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_herod(Creature *_Creature)
{
    return new boss_herodAI (_Creature);
}

void AddSC_boss_herod()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_herod";
    newscript->GetAI = GetAI_boss_herod;
    m_scripts[nrscripts++] = newscript;
}

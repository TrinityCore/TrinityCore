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
SDName: Boss_High_Inquistor_Whitmane
SD%Complete: 50
SDComment: Missing connection with commander mograine
SDCategory: Scarlet Monastery
EndScriptData */

#include "precompiled.h"

#define SPELL_DEEPSLEEP                 9256
#define SPELL_SCARLETRESURRECTION       9232

#define SPELL_CRUSADERSTRIKE            17281
#define SPELL_HAMMEROFJUSTICE           13005
#define SPELL_HOLYSMITE6                9481
#define SPELL_HOLYFIRE5                 15265
#define SPELL_MINDBLAST6                8106

#define SPELL_POWERWORDSHIELD           6065

#define SPELL_RENEW                     6078
#define SPELL_FLASHHEAL6                10916

#define SAY_AGGRO                       "There is no escape for you. The Crusade shall destroy all who carry the Scourge's taint."
#define SAY_SPAWN                       "What, Mograine has fallen? You shall pay for this treachery! "
#define SAY_RES                         "Arise, my champion!"
#define SAY_DEATH                       "The Light has spoken!"

//#define SOUND_AGGRO
#define SOUND_RES                       5840
#define SOUND_SPAWN                     5838
#define SOUND_DEATH                     5839

struct TRINITY_DLL_DECL boss_high_inquisitor_whitemaneAI : public ScriptedAI
{
    boss_high_inquisitor_whitemaneAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 Healing_Timer;
    uint32 Renew_Timer;
    uint32 PowerWordShield_Timer;
    uint32 CrusaderStrike_Timer;
    uint32 HammerOfJustice_Timer;
    uint32 HolySmite6_Timer;
    uint32 HolyFire5_Timer;
    uint32 MindBlast6_Timer;

    void Reset()
    {
        Healing_Timer = 0;
        Renew_Timer= 0;
        PowerWordShield_Timer = 2000;
        CrusaderStrike_Timer = 12000;
        HammerOfJustice_Timer = 18000;
        HolySmite6_Timer = 10000;
        HolyFire5_Timer = 20000;
        MindBlast6_Timer = 6000;
    }

    void Aggro(Unit *who)
    {
        DoYell(SAY_AGGRO,LANG_UNIVERSAL,NULL);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        /*
        //This is going to be a routine to make the resurrection event...
        if (m_creature->isAlive && m_creature->isAlive)
        {
        m_creature->Relocate(1163.113370,1398.856812,32.527786,3.171014);

        DoYell(SAY_SPAWN,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature,SOUND_SPAWN);
        DoCast(m_creature->getVictim(),SPELL_DEEPSLEEP);
        DoCast(m-creature->GetGUID(51117),SPELL_SCARLETRESURRECTION)
        }
        */

        //If we are <75% hp cast healing spells at self and Mograine
        if ( m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 75 )
        {
            if (Healing_Timer < diff)
            {
                DoCast(m_creature,SPELL_FLASHHEAL6);
                return;

                //22-32 seconds until we should cast this agian
                Healing_Timer = 22000 + rand()%10000;
            }else Healing_Timer -= diff;
        }

        if ( m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 30)
        {
            if (Renew_Timer < diff)
            {
                DoCast(m_creature,SPELL_RENEW);
                Renew_Timer = 30000;
            }else Renew_Timer -= diff;
        }

        //PowerWordShield_Timer
        if (PowerWordShield_Timer < diff)
        {
            DoCast(m_creature,SPELL_POWERWORDSHIELD);
            PowerWordShield_Timer = 25000;
        }else PowerWordShield_Timer -= diff;

        //CrusaderStrike_Timer
        if (CrusaderStrike_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_CRUSADERSTRIKE);
            CrusaderStrike_Timer = 15000;
        }else CrusaderStrike_Timer -= diff;

        //HammerOfJustice_Timer
        if (HammerOfJustice_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_HAMMEROFJUSTICE);
            HammerOfJustice_Timer = 12000;
        }else HammerOfJustice_Timer -= diff;

        //HolySmite6_Timer
        if (HolySmite6_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_HOLYSMITE6);
            HolySmite6_Timer = 10000;
        }else HolySmite6_Timer -= diff;

        //HolyFire5_Timer
        if (HolyFire5_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_HOLYFIRE5);
            HolyFire5_Timer = 15000;
        }else HolyFire5_Timer -= diff;

        //MindBlast6_Timer
        if (MindBlast6_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_MINDBLAST6);
            MindBlast6_Timer = 8000;
        }else MindBlast6_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_high_inquisitor_whitemane(Creature *_Creature)
{
    return new boss_high_inquisitor_whitemaneAI (_Creature);
}

void AddSC_boss_high_inquisitor_whitemane()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_high_inquisitor_whitemane";
    newscript->GetAI = GetAI_boss_high_inquisitor_whitemane;
    m_scripts[nrscripts++] = newscript;
}

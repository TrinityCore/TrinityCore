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
SDName: Boss_Mograine_And_Whitemane
SD%Complete: 75
SDComment: Event not implemented
SDCategory: Scarlet Monastery
EndScriptData */

#include "precompiled.h"
#include "def_scarlet_monastery.h"

#define SAY_MO_AGGRO                -1189005
#define SAY_MO_KILL                 -1189006
#define SAY_MO_RESSURECTED          -1189007

#define SAY_WH_INTRO                -1189008
#define SAY_WH_KILL                 -1189009
#define SAY_WH_RESSURECT            -1189010

#define SPELL_DIVINESHIELD2         1020
#define SPELL_CRUSADERSTRIKE5       35395
#define SPELL_HAMMEROFJUSTICE3      5589
#define SPELL_HOLYLIGHT6            3472
#define SPELL_CONSECRATION3         20922
#define SPELL_BLESSINGOFWISDOM      1044
#define SPELL_RETRIBUTIONAURA3      10299
#define SPELL_BLESSINGOFPROTECTION3 10278
#define SPELL_FLASHHEAL6            10916

struct TRINITY_DLL_DECL boss_scarlet_commander_mograineAI : public ScriptedAI
{
    boss_scarlet_commander_mograineAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = m_creature->GetInstanceData();
    }

    ScriptedInstance* pInstance;

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

    void EnterCombat(Unit *who)
    {
        DoScriptText(SAY_MO_AGGRO, m_creature);
        DoCast(m_creature,SPELL_RETRIBUTIONAURA3);
    }

    void KilledUnit(Unit *victim)
    {
        DoScriptText(SAY_MO_KILL, m_creature);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //If we are <50% hp cast Arcane Bubble and start casting SPECIAL Arcane Explosion
        if (m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 50 && !m_creature->IsNonMeleeSpellCasted(false))
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

struct TRINITY_DLL_DECL boss_high_inquisitor_whitemaneAI : public ScriptedAI
{
    boss_high_inquisitor_whitemaneAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = m_creature->GetInstanceData();
    }

    ScriptedInstance* pInstance;

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

    void EnterCombat(Unit *who)
    {
        DoScriptText(SAY_WH_INTRO, m_creature);
    }

    void KilledUnit(Unit *victim)
    {
        DoScriptText(SAY_WH_KILL, m_creature);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        /*
        //This is going to be a routine to make the resurrection event...
        if (m_creature->isAlive && m_creature->isAlive)
        {
        m_creature->Relocate(1163.113370,1398.856812,32.527786,3.171014);

        DoScriptText(SAY_WH_RESSURECT, m_creature);

        DoCast(m_creature->getVictim(),SPELL_DEEPSLEEP);
        DoCast(m-creature->GetGUID(51117),SPELL_SCARLETRESURRECTION)
        }
        */

        //If we are <75% hp cast healing spells at self and Mograine
        if (m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 75 )
        {
            if (Healing_Timer < diff)
            {
                DoCast(m_creature,SPELL_FLASHHEAL6);
                return;

                //22-32 seconds until we should cast this agian
                Healing_Timer = 22000 + rand()%10000;
            }else Healing_Timer -= diff;
        }

        if (m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 30)
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

CreatureAI* GetAI_boss_scarlet_commander_mograine(Creature *_Creature)
{
    return new boss_scarlet_commander_mograineAI (_Creature);
}

CreatureAI* GetAI_boss_high_inquisitor_whitemane(Creature *_Creature)
{
    return new boss_high_inquisitor_whitemaneAI (_Creature);
}

void AddSC_boss_mograine_and_whitemane()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_scarlet_commander_mograine";
    newscript->GetAI = &GetAI_boss_scarlet_commander_mograine;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_high_inquisitor_whitemane";
    newscript->GetAI = &GetAI_boss_high_inquisitor_whitemane;
    newscript->RegisterSelf();
}


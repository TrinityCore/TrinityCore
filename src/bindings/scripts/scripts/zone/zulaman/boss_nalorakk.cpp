/* Copyright (C) 2006,2007 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Nalorakk
SD%Complete: 80
SDComment: Todo: Trash Waves
SDCategory: Zul'Aman
EndScriptData */

#include "precompiled.h"

//TODO: Trash Waves

//Unimplemented SoundIDs
/*
#define SOUND_NALORAKK_WAVE1    12066
#define SOUND_NALORAKK_WAVE2    12067
#define SOUND_NALORAKK_WAVE3    12068
#define SOUND_NALORAKK_WAVE4    12069

#define SOUND_NALORAKK_EVENT1   12078
#define SOUND_NALORAKK_EVENT2   12079
*/

//General defines
#define YELL_AGGRO              "You be dead soon enough!"
#define SOUND_YELL_AGGRO        12070
#define YELL_KILL_ONE           "Mua-ha-ha! Now whatchoo got to say?"
#define SOUND_YELL_KILL_ONE     12075
#define YELL_KILL_TWO           "Da Amani gonna rule again!"
#define SOUND_YELL_KILL_TWO     12076
#define YELL_DEATH              "I... be waitin' on da udda side...."
#define SOUND_YELL_DEATH        12077
                                                            //Never seen this being used, so just guessing from what I hear.
#define YELL_BERSERK            "You had your chance, now it be too late!"
#define SOUND_YELL_BERSERK      12074

#define SPELL_BERSERK           45078                       //unsure, this increases damage, size and speed

//Defines for Troll form
#define SPELL_BRUTALSWIPE       42384
//#define SPELL_MANGLE            42389 This doesn't seem to apply the mangle debuff after all
#define SPELL_MANGLEEFFECT      44955
#define SPELL_SURGE             42402
#define SPELL_BEARFORM          42377

#define YELL_SURGE              "I bring da pain!"
#define SOUND_YELL_SURGE        12071

#define YELL_SHIFTEDTOTROLL     "Make way for Nalorakk!"
#define SOUND_YELL_TOTROLL      12073

//Defines for Bear form
#define SPELL_LACERATINGSLASH   42395
#define SPELL_RENDFLESH         42397
#define SPELL_DEAFENINGROAR     42398

#define YELL_SHIFTEDTOBEAR      "You call on da beast, you gonna get more dan you bargain for!"
#define SOUND_YELL_TOBEAR       12072

struct TRINITY_DLL_DECL boss_nalorakkAI : public ScriptedAI
{
    boss_nalorakkAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 ChangeForm_Timer;
    uint32 BrutalSwipe_Timer;
    uint32 Mangle_Timer;
    uint32 Surge_Timer;
    uint32 LaceratingSlash_Timer;
    uint32 RendFlesh_Timer;
    uint32 DeafeningRoar_Timer;
    uint32 ShapeShiftCheck_Timer;
    uint32 Berserk_Timer;
    bool inBearForm;
    bool Berserking;
    bool ChangedToBear;
    bool ChangedToTroll;

    void Reset()
    {
        ChangeForm_Timer = 45000;
        BrutalSwipe_Timer = 12000;
        Mangle_Timer = 15000;
        Surge_Timer = 20000;
        LaceratingSlash_Timer = 6000;
        RendFlesh_Timer = 6000;
        DeafeningRoar_Timer = 20000;
        ShapeShiftCheck_Timer = 40000;
        Berserk_Timer = 600000;
        inBearForm = false;
        Berserking = false;
        ChangedToBear = false;
        ChangedToTroll = true;
    }

    void Aggro(Unit *who)
    {
        DoYell(YELL_AGGRO, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature, SOUND_YELL_AGGRO);
    }

    void KilledUnit(Unit* victim)
    {
        switch(rand()%2)
        {
            case 0:
                DoYell(YELL_KILL_ONE, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_YELL_KILL_ONE);
                break;
            case 1:
                DoYell(YELL_KILL_TWO, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_YELL_KILL_TWO);
                break;
        }
    }

    void JustDied(Unit* Killer)
    {
        DoYell(YELL_DEATH,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature, SOUND_YELL_DEATH);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //Berserking
        if ((Berserk_Timer < diff) && (!Berserking))
        {
            DoCast(m_creature, SPELL_BERSERK);
            DoYell(YELL_BERSERK, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SOUND_YELL_BERSERK);
            Berserking = true;
        }else Berserk_Timer -= diff;

        //Don't check if we're shapeshifted every UpdateAI
        if (ShapeShiftCheck_Timer < diff)
        {
            //This will return true if we have bearform aura
            inBearForm = m_creature->HasAura(SPELL_BEARFORM, 0);
            ShapeShiftCheck_Timer = 1000;
        }else ShapeShiftCheck_Timer -= diff;

        //Spells for Troll Form (only to be casted if we NOT have bear phase aura)
        if (!inBearForm)
        {
            //We just changed to troll form!
            if (!ChangedToTroll)
            {
                DoYell(YELL_SHIFTEDTOTROLL, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_YELL_TOTROLL);
                ChangedToTroll = true;
                ChangedToBear = false;
                //Reset spell timers
                LaceratingSlash_Timer = 6000 + rand()%19000;
                RendFlesh_Timer = 6000 + rand()%19000;
                DeafeningRoar_Timer = 15000 + rand()%10000;
                ShapeShiftCheck_Timer = 40000;
            }

            //Brutal Swipe (some sources may say otherwise, but I've never seen this in Bear form)
            if (BrutalSwipe_Timer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_BRUTALSWIPE);
                BrutalSwipe_Timer = 7000 + rand()%13000;
            }else BrutalSwipe_Timer -= diff;

            //Mangle
            if (Mangle_Timer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_MANGLEEFFECT);
                Mangle_Timer = 3000 + rand()%17000;
            }else Mangle_Timer -= diff;

            //Surge
            if (Surge_Timer < diff)
            {
                //select a random unit other than the main tank
                Unit *target = SelectUnit(SELECT_TARGET_RANDOM, 1);

                //if there aren't other units, cast on the tank
                if(!target)
                    target = m_creature->getVictim();

                DoCast(target, SPELL_SURGE);

                DoYell(YELL_SURGE, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_YELL_SURGE);

                Surge_Timer = 15000 + rand()%17500;
            }else Surge_Timer -= diff;

            //Change to Bear Form if we're in Troll Form for 45sec
            if (ChangeForm_Timer < diff)
            {
                DoCast(m_creature, SPELL_BEARFORM);
                //And 30sec (bear form) + 45sec (troll form) before we should cast this again
                ChangeForm_Timer = 75000;
            }else ChangeForm_Timer -= diff;
        }
        //Spells for Bear Form (only to be casted if we have bear phase aura)
        else
        {
            //We just changed to bear form!
            if (!ChangedToBear)
            {
                DoYell(YELL_SHIFTEDTOBEAR, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_YELL_TOBEAR);
                ChangedToBear = true;
                ChangedToTroll = false;
                //Reset spell timers
                Surge_Timer = 15000 + rand()%17500;
                BrutalSwipe_Timer = 7000 + rand()%13000;
                Mangle_Timer = 3000 + rand()%17000;
                ShapeShiftCheck_Timer = 25000;
            }

            //Lacerating Slash
            if (LaceratingSlash_Timer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_LACERATINGSLASH);
                LaceratingSlash_Timer = 6000 + rand()%19000;
            }else LaceratingSlash_Timer -= diff;

            //Rend Flesh
            if (RendFlesh_Timer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_RENDFLESH);
                RendFlesh_Timer = 6000 + rand()%19000;
            }else RendFlesh_Timer -= diff;

            //Deafening Roar
            if (DeafeningRoar_Timer < diff)
            {
                DoCast(m_creature->getVictim(), SPELL_DEAFENINGROAR);
                DeafeningRoar_Timer = 15000 + rand()%10000;
            }else DeafeningRoar_Timer -= diff;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_nalorakk(Creature *_Creature)
{
    return new boss_nalorakkAI (_Creature);
}

void AddSC_boss_nalorakk()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_nalorakk";
    newscript->GetAI = GetAI_boss_nalorakk;
    m_scripts[nrscripts++] = newscript;
}

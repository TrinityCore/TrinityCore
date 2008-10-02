/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Nefarian
SD%Complete: 100
SDComment: Some issues with class calls effecting more than one class
SDCategory: Blackwing Lair
EndScriptData */

#include "precompiled.h"

#define SAY_AGGRO               "Well done, my minions. The mortals' courage begins to wane! Now, let's see how they contend with the true Lord of Blackrock Spire!"
#define SAY_DEATH               "This cannot be! I am the Master here! You mortals are nothing to my kind! DO YOU HEAR? NOTHING!"
#define SAY_RAISE_SKELETONS     "Impossible! Rise my minions! Serve your master once more!"
#define SAY_SHADOWFLAME         "Burn, you wretches! Burn!"
#define SAY_SLAY                "Worthless $N! Your friends will join you soon enough!"
#define SAY_XHEALTH             "Enough! Now you vermin shall feel the force of my birthright, the fury of the earth itself."
#define SAY_GAMESBEGIN          "Let the games begin!"
#define SAY_START               "<unknown>"

#define SOUND_AGGRO             8288
#define SOUND_DEATH             8292
#define SOUND_RAISE_SKELETONS   8291
#define SOUND_SHADOWFLAME       8290
#define SOUND_SLAY              8293
#define SOUND_XHEALTH           8289
#define SOUND_GAMESBEGIN        8279
#define SOUND_START             8280

#define SPELL_SHADOWFLAME_INITIAL   22972
#define SPELL_SHADOWFLAME           22539
#define SPELL_BELLOWINGROAR         22686
#define SPELL_VEILOFSHADOW          7068
#define SPELL_CLEAVE                20691
#define SPELL_TAILLASH              23364
#define SPELL_BONECONTRUST          23363                   //23362, 23361

#define SPELL_MAGE                  23410                   //wild magic
#define SPELL_WARRIOR               23397                   //beserk
#define SPELL_DRUID                 23398                   // cat form
#define SPELL_PRIEST                23401                   // corrupted healing
#define SPELL_PALADIN               23418                   //syphon blessing
#define SPELL_SHAMAN                23425                   //totems
#define SPELL_WARLOCK               23427                   //infernals
#define SPELL_HUNTER                23436                   //bow broke
#define SPELL_ROGUE                 23414                   //Paralise

#define SAY_MAGE        "Mages too? You should be more careful when you play with magic..."
#define SAY_WARRIOR     "Warriors, I know you can hit harder than that! Let's see it!"
#define SAY_DRUID       "Druids and your silly shapeshifting. Let's see it in action!"
#define SAY_PRIEST      "Priests! If you're going to keep healing like that, we might as well make it a little more interesting!"
#define SAY_PALADIN     "Paladins, I've heard you have many lives. Show me."
#define SAY_SHAMAN      "Shamans, show me what your totems can do!"
#define SAY_WARLOCK     "Warlocks, you shouldn't be playing with magic you don't understand. See what happens?"
#define SAY_HUNTER      "Hunters and your annoying pea-shooters!"
#define SAY_ROGUE       "Rogues? Stop hiding and face me!"

struct MANGOS_DLL_DECL boss_nefarianAI : public ScriptedAI
{
    boss_nefarianAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 ShadowFlame_Timer;
    uint32 BellowingRoar_Timer;
    uint32 VeilOfShadow_Timer;
    uint32 Cleave_Timer;
    uint32 TailLash_Timer;
    uint32 ClassCall_Timer;
    bool Phase3;

    void Reset()
    {
        ShadowFlame_Timer = 12000;                          //These times are probably wrong
        BellowingRoar_Timer = 30000;
        VeilOfShadow_Timer = 15000;
        Cleave_Timer = 7000;
        TailLash_Timer = 10000;
        ClassCall_Timer = 35000;                            //35-40 seconds
        Phase3 = false;

        m_creature->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
        m_creature->ApplySpellImmune(1, IMMUNITY_EFFECT,SPELL_EFFECT_ATTACK_ME, true);
    }

    void KilledUnit(Unit* Victim)
    {
        if (rand()%5)
            return;

        DoYell(SAY_SLAY,LANG_UNIVERSAL,Victim);
        DoPlaySoundToSet(m_creature, SOUND_SLAY);
    }

    void JustDied(Unit* Killer)
    {
        DoYell(SAY_DEATH,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature, SOUND_DEATH);
    }

    void Aggro(Unit *who)
    {
        switch (rand()%3)
        {
            case 0:
                DoYell(SAY_XHEALTH,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature,SOUND_XHEALTH);
                break;
            case 1:
                DoYell(SAY_AGGRO,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature,SOUND_AGGRO);
                break;
            case 2:
                DoYell(SAY_SHADOWFLAME,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature,SOUND_SHADOWFLAME);
                break;
        }

        DoCast(who,SPELL_SHADOWFLAME_INITIAL);
        DoZoneInCombat();
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //ShadowFlame_Timer
        if (ShadowFlame_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_SHADOWFLAME);
            ShadowFlame_Timer = 12000;
        }else ShadowFlame_Timer -= diff;

        //BellowingRoar_Timer
        if (BellowingRoar_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_BELLOWINGROAR);
            BellowingRoar_Timer = 30000;
        }else BellowingRoar_Timer -= diff;

        //VeilOfShadow_Timer
        if (VeilOfShadow_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_VEILOFSHADOW);
            VeilOfShadow_Timer = 15000;
        }else VeilOfShadow_Timer -= diff;

        //Cleave_Timer
        if (Cleave_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_CLEAVE);
            Cleave_Timer = 7000;
        }else Cleave_Timer -= diff;

        //TailLash_Timer
        if (TailLash_Timer < diff)
        {
            //Cast NYI since we need a better check for behind target
            //DoCast(m_creature->getVictim(),SPELL_TAILLASH);

            TailLash_Timer = 10000;
        }else TailLash_Timer -= diff;

        //ClassCall_Timer
        if (ClassCall_Timer < diff)
        {
            //Cast a random class call
            //On official it is based on what classes are currently on the hostil list
            //but we can't do that yet so just randomly call one

            switch (rand()%9)
            {
                case 0:
                    DoYell(SAY_MAGE,LANG_UNIVERSAL,NULL);
                    DoCast(m_creature,SPELL_MAGE);
                    break;
                case 1:
                    DoYell(SAY_WARRIOR,LANG_UNIVERSAL,NULL);
                    DoCast(m_creature,SPELL_WARRIOR);
                    break;
                case 2:
                    DoYell(SAY_DRUID,LANG_UNIVERSAL,NULL);
                    DoCast(m_creature,SPELL_DRUID);
                    break;
                case 3:
                    DoYell(SAY_PRIEST,LANG_UNIVERSAL,NULL);
                    DoCast(m_creature,SPELL_PRIEST);
                    break;
                case 4:
                    DoYell(SAY_PALADIN,LANG_UNIVERSAL,NULL);
                    DoCast(m_creature,SPELL_PALADIN);
                    break;
                case 5:
                    DoYell(SAY_SHAMAN,LANG_UNIVERSAL,NULL);
                    DoCast(m_creature,SPELL_SHAMAN);
                    break;
                case 6:
                    DoYell(SAY_WARLOCK,LANG_UNIVERSAL,NULL);
                    DoCast(m_creature,SPELL_WARLOCK);
                    break;
                case 7:
                    DoYell(SAY_HUNTER,LANG_UNIVERSAL,NULL);
                    DoCast(m_creature,SPELL_HUNTER);
                    break;
                case 8:
                    DoYell(SAY_ROGUE,LANG_UNIVERSAL,NULL);
                    DoCast(m_creature,SPELL_ROGUE);
                    break;
            }

            ClassCall_Timer = 35000 + (rand() % 5000);
        }else ClassCall_Timer -= diff;

        //Phase3 begins when we are below X health
        if (!Phase3 && (m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 20)
        {
            Phase3 = true;
            DoYell(SAY_RAISE_SKELETONS,LANG_UNIVERSAL,NULL);
            DoPlaySoundToSet(m_creature,SOUND_RAISE_SKELETONS);
        }

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_nefarian(Creature *_Creature)
{
    return new boss_nefarianAI (_Creature);
}

void AddSC_boss_nefarian()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_nefarian";
    newscript->GetAI = GetAI_boss_nefarian;
    m_scripts[nrscripts++] = newscript;
}

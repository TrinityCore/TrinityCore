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
SDName: Boss_Thane_Korthazz
SD%Complete: 100
SDComment:
SDCategory: Naxxramas
EndScriptData */

#include "precompiled.h"

//All horsemen
#define SPELL_SHIELDWALL           29061
#define SPELL_BESERK               26662

// thane korthazz
#define SPELL_MARK_OF_KORTHAZZ     28832
#define SPELL_METEOR               26558                    // m_creature->getVictim() auto-area spell but with a core problem

#define SAY_AGGRO                  "Come out and fight, ye wee ninny!"
#define SAY_TAUNT1                 "To arms, ye roustabouts! We've got company!"
#define SAY_TAUNT2                 "I heard about enough of yer sniveling. Shut yer fly trap 'afore I shut it for ye!"
#define SAY_TAUNT3                 "I'm gonna enjoy killin' these slack-jawed daffodils!"
#define SAY_SLAY                   "Next time, bring more friends!"
#define SAY_SPECIAl                "I like my meat extra crispy!"
#define SAY_DEATH                  "What a bloody waste this is!"

#define SOUND_AGGRO                8899
#define SOUND_TAUNT1               8903
#define SOUND_TAUNT2               8904
#define SOUND_TAUNT3               8905
#define SOUND_SLAY                 8901
#define SOUND_SPECIAL              8902
#define SOUND_DEATH                8900

#define SPIRIT_OF_KORTHAZZ         16778

struct MANGOS_DLL_DECL boss_thane_korthazzAI : public ScriptedAI
{
    boss_thane_korthazzAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 Mark_Timer;
    uint32 Meteor_Timer;
    bool ShieldWall1;
    bool ShieldWall2;

    void Reset()
    {
        Mark_Timer = 20000;                                 // First Horsemen Mark is applied at 20 sec.
        Meteor_Timer = 30000;                               // wrong
        ShieldWall1 = true;
        ShieldWall2 = true;
    }

    void InitialYell()
    {
        if(!InCombat)
        {
            DoYell(SAY_AGGRO,LANG_UNIVERSAL,NULL);
            DoPlaySoundToSet(m_creature,SOUND_AGGRO);
        }
    }

    void KilledUnit()
    {
        DoYell(SAY_SLAY,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature,SOUND_SLAY);
    }

    void JustDied(Unit* Killer)
    {
        DoYell(SAY_DEATH,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature, SOUND_DEATH);
    }

    void Aggro(Unit *who)
    {
        InitialYell();
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        // Mark of Korthazz
        if(Mark_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_MARK_OF_KORTHAZZ);
            Mark_Timer = 12000;
        }else Mark_Timer -= diff;

        // Shield Wall - All 4 horsemen will shield wall at 50% hp and 20% hp for 20 seconds
        if(ShieldWall1 && (m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 50)
        {
            if(ShieldWall1)
            {
                DoCast(m_creature,SPELL_SHIELDWALL);
                ShieldWall1 = false;
            }
        }
        if(ShieldWall2 && (m_creature->GetHealth()*100 / m_creature->GetMaxHealth()) < 20)
        {
            if(ShieldWall2)
            {
                DoCast(m_creature,SPELL_SHIELDWALL);
                ShieldWall2 = false;
            }
        }

        // Meteor
        if(Meteor_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_METEOR);
            Meteor_Timer = 20000;                           // wrong
        }else Meteor_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_thane_korthazz(Creature *_Creature)
{
    return new boss_thane_korthazzAI (_Creature);
}

void AddSC_boss_thane_korthazz()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_thane_korthazz";
    newscript->GetAI = GetAI_boss_thane_korthazz;
    m_scripts[nrscripts++] = newscript;
}

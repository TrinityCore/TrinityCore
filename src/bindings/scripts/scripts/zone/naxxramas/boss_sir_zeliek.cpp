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
SDName: Boss_Sir_Zeliek
SD%Complete: 100
SDComment:
SDCategory: Naxxramas
EndScriptData */

#include "precompiled.h"

//All horsemen
#define SPELL_SHIELDWALL           29061
#define SPELL_BESERK               26662

// sir zeliek
#define SPELL_MARK_OF_ZELIEK       28835
#define SPELL_HOLY_WRATH           28883

#define SAY_AGGRO                 "Flee, before it's too late!"
#define SAY_TAUNT1                "Invaders, cease this foolish venture at once! Turn away while you still can!"
#define SAY_TAUNT2                "Perhaps they will come to their senses, and run away as fast as they can!"
#define SAY_TAUNT3                "Do not continue! Turn back while there's still time!"
#define SAY_SPECIAL               "I- I have no choice but to obey!"
#define SAY_SLAY                  "Forgive me!"
#define SAY_DEATH                 "It is... as it should be."

#define SOUND_AGGRO               8913
#define SOUND_TAUNT1              8917
#define SOUND_TAUNT2              8918
#define SOUND_TAUNT3              8919
#define SOUND_SPECIAl             8916
#define SOUND_SLAY                8915
#define SOUND_DEATH               8914

struct MANGOS_DLL_DECL boss_sir_zeliekAI : public ScriptedAI
{
    boss_sir_zeliekAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 Mark_Timer;
    uint32 HolyWrath_Timer;
    bool ShieldWall1;
    bool ShieldWall2;

    void Reset()
    {
        Mark_Timer = 20000;                                 // First Horsemen Mark is applied at 20 sec.
        HolyWrath_Timer = 12000;                            // right
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
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        // Mark of Zeliek
        if(Mark_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_MARK_OF_ZELIEK);
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

        // Holy Wrath
        if(HolyWrath_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_HOLY_WRATH);
            HolyWrath_Timer = 12000;
        }else HolyWrath_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_sir_zeliek(Creature *_Creature)
{
    return new boss_sir_zeliekAI (_Creature);
}

void AddSC_boss_sir_zeliek()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_sir_zeliek";
    newscript->GetAI = GetAI_boss_sir_zeliek;
    m_scripts[nrscripts++] = newscript;
}

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
SDName: Boss_Lady_Blaumeux
SD%Complete: 100
SDComment:
SDCategory: Naxxramas
EndScriptData */

#include "precompiled.h"

//All horsemen
#define SPELL_SHIELDWALL           29061
#define SPELL_BESERK               26662

// lady blaumeux
#define SPELL_MARK_OF_BLAUMEUX     28833
#define SPELL_VOIDZONE             28863

#define SAY_AGGRO                 "Defend youself!"
#define SAY_TAUNT1                "Come, Zeliek, do not drive them out. Not before we've had our fun."
#define SAY_TAUNT2                "I do hope they stay alive long enough for me to... introduce myself."
#define SAY_TAUNT3                "The first kill goes to me! Anyone care to wager?"
#define SAY_SPECIAL               "Your life is mine!"
#define SAY_SLAY                  "Who's next?"
#define SAY_DEATH                 "Tou... che!"

#define SOUND_AGGRO               8892
#define SOUND_TAUNT1              8896
#define SOUND_TAUNT2              8897
#define SOUND_TAUNT3              8898
#define SOUND_SPECIAL             8895
#define SOUND_SLAY                8894
#define SOUND_DEATH               8893

#define SPIRIT_OF_BLAUMEUX        16776

struct TRINITY_DLL_DECL boss_lady_blaumeuxAI : public ScriptedAI
{
    boss_lady_blaumeuxAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 Mark_Timer;
    uint32 VoidZone_Timer;
    bool ShieldWall1;
    bool ShieldWall2;

    void Reset()
    {
        Mark_Timer = 20000;                                 // First Horsemen Mark is applied at 20 sec.
        VoidZone_Timer = 12000;                             // right
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
        DoPlaySoundToSet(m_creature,SOUND_DEATH);
    }

    void Aggro(Unit *who)
    {
        InitialYell();
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        // Mark of Blaumeux
        if(Mark_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_MARK_OF_BLAUMEUX);
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

        // Void Zone
        if(VoidZone_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_VOIDZONE);
            VoidZone_Timer = 12000;
        }else VoidZone_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_lady_blaumeux(Creature *_Creature)
{
    return new boss_lady_blaumeuxAI (_Creature);
}

void AddSC_boss_lady_blaumeux()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_lady_blaumeux";
    newscript->GetAI = GetAI_boss_lady_blaumeux;
    m_scripts[nrscripts++] = newscript;
}

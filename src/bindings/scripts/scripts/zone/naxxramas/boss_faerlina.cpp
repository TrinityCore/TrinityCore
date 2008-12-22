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
SDName: Boss_Faerlina
SD%Complete: 50
SDComment: Without Mindcontrol boss cannot be defeated
SDCategory: Naxxramas
EndScriptData */

#include "precompiled.h"

#define SAY_GREET           "Your old lives, your mortal desires, mean nothing. You are acolytes of the master now, and you will serve the cause without question! The greatest glory is to die in the master's service!"
#define SAY_AGGRO1          "Slay them in the master's name!"
#define SAY_AGGRO2          "You cannot hide from me!"
#define SAY_AGGRO3          "Kneel before me, worm!"
#define SAY_AGGRO4          "Run while you still can!"
#define SAY_SLAY1           "You have failed!"
#define SAY_SLAY2           "Pathetic wretch!"
#define SAY_DEATH           "The master... will avenge me!"
#define SAY_RANDOM_AGGRO    "???"

#define SOUND_GREET         8799
#define SOUND_AGGRO1        8794
#define SOUND_AGGRO2        8795
#define SOUND_AGGRO3        8796
#define SOUND_AGGRO4        8797
#define SOUND_SLAY1         8800
#define SOUND_SLAY2         8801
#define SOUND_DEATH         8798
#define SOUND_RANDOM_AGGRO  8955

#define SPELL_POSIONBOLT_VOLLEY     28796
#define SPELL_RAINOFFIRE            28794                   //Not sure if targeted AoEs work if casted directly upon a player
#define SPELL_ENRAGE                26527

struct TRINITY_DLL_DECL boss_faerlinaAI : public ScriptedAI
{
    boss_faerlinaAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 PoisonBoltVolley_Timer;
    uint32 RainOfFire_Timer;
    uint32 Enrage_Timer;
    bool HasTaunted;

    void Reset()
    {
        PoisonBoltVolley_Timer = 8000;
        RainOfFire_Timer = 16000;
        Enrage_Timer = 60000;
        HasTaunted = false;
    }

    void Aggro(Unit *who)
    {
        switch (rand()%4)
        {
            case 0:
                DoYell(SAY_AGGRO1,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature,SOUND_AGGRO1);
                break;
            case 1:
                DoYell(SAY_AGGRO2,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature,SOUND_AGGRO2);
                break;
            case 2:
                DoYell(SAY_AGGRO3,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature,SOUND_AGGRO3);
                break;
            case 3:
                DoYell(SAY_AGGRO4,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature,SOUND_AGGRO4);
                break;
        }
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (!m_creature->getVictim() && who->isTargetableForAttack() && who->isInAccessiblePlaceFor(m_creature) && m_creature->IsHostileTo(who))
        {
            if (!m_creature->canFly() && m_creature->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE)
                return;

            float attackRadius = m_creature->GetAttackDistance(who);
            if (m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->IsWithinLOSInMap(who))
            {
                //Say our dialog on initial aggro
                if (!InCombat)
                {
                    switch (rand()%4)
                    {
                        case 0:
                            DoYell(SAY_AGGRO1,LANG_UNIVERSAL,NULL);
                            DoPlaySoundToSet(m_creature,SOUND_AGGRO1);
                            break;
                        case 1:
                            DoYell(SAY_AGGRO2,LANG_UNIVERSAL,NULL);
                            DoPlaySoundToSet(m_creature,SOUND_AGGRO2);
                            break;
                        case 2:
                            DoYell(SAY_AGGRO3,LANG_UNIVERSAL,NULL);
                            DoPlaySoundToSet(m_creature,SOUND_AGGRO3);
                            break;
                        case 3:
                            DoYell(SAY_AGGRO4,LANG_UNIVERSAL,NULL);
                            DoPlaySoundToSet(m_creature,SOUND_AGGRO4);
                            break;
                    }
                }

                //who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);
                AttackStart(who);
            }
            else if (!HasTaunted && m_creature->IsWithinDistInMap(who, 60.0f))
            {
                DoYell(SAY_GREET, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature,SOUND_GREET);
                HasTaunted = true;
            }
        }
    }

    void KilledUnit(Unit* victim)
    {
        switch (rand()%2)
        {
            case 0:
                DoYell(SAY_SLAY1,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature,SOUND_SLAY1);
                break;
            case 1:
                DoYell(SAY_SLAY2,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature,SOUND_SLAY2);
                break;
        }
    }

    void JustDied(Unit* Killer)
    {
        DoYell(SAY_DEATH,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature,SOUND_DEATH);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        //PoisonBoltVolley_Timer
        if (PoisonBoltVolley_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_POSIONBOLT_VOLLEY);
            PoisonBoltVolley_Timer = 11000;
        }else PoisonBoltVolley_Timer -= diff;

        //RainOfFire_Timer
        if (RainOfFire_Timer < diff)
        {
            Unit* target = NULL;
            target = SelectUnit(SELECT_TARGET_RANDOM,0);
            if (target) DoCast(target,SPELL_RAINOFFIRE);

            RainOfFire_Timer = 16000;
        }else RainOfFire_Timer -= diff;

        //Enrage_Timer
        if (Enrage_Timer < diff)
        {
            DoCast(m_creature,SPELL_ENRAGE);
            Enrage_Timer = 61000;
        }else Enrage_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_faerlina(Creature *_Creature)
{
    return new boss_faerlinaAI (_Creature);
}

void AddSC_boss_faerlina()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_faerlina";
    newscript->GetAI = &GetAI_boss_faerlina;
    newscript->RegisterSelf();
}

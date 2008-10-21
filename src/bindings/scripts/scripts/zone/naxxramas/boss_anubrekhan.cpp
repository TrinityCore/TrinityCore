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
SDName: Boss_Anubrekhan
SD%Complete: 100
SDComment:
SDCategory: Naxxramas
EndScriptData */

#include "precompiled.h"

#define SAY_AGGRO1  "Just a little taste..."
#define SAY_AGGRO2  "There is no way out."
#define SAY_AGGRO3  "Yes, Run! It makes the blood pump faster!"
#define SAY_GREET   "Ahh... welcome to my parlor"
#define SAY_TAUNT1  "I hear little hearts beating. Yesss... beating faster now. Soon the beating will stop."
#define SAY_TAUNT2  "Where to go? What to do? So many choices that all end in pain, end in death."
#define SAY_TAUNT3  "Which one shall I eat first? So difficult to choose... the all smell so delicious."
#define SAY_TAUNT4  "Closer now... tasty morsels. I've been too long without food. Without blood to drink."
#define SAY_SLAY    "Shh... it will all be over soon."

#define SOUND_AGGRO1  8785
#define SOUND_AGGRO2  8786
#define SOUND_AGGRO3  8787
#define SOUND_GREET   8788
#define SOUND_TAUNT1  8790
#define SOUND_TAUNT2  8791
#define SOUND_TAUNT3  8792
#define SOUND_TAUNT4  8793
#define SOUND_SLAY    8789

#define SPELL_IMPALE        28783                           //May be wrong spell id. Causes more dmg than I expect
#define SPELL_LOCUSTSWARM   28785                           //This is a self buff that triggers the dmg debuff
#define SPELL_SUMMONGUARD   29508                           //Summons 1 crypt guard at targeted location

#define SPELL_SELF_SPAWN_5  29105                           //This spawns 5 corpse scarabs ontop of us (most likely the player casts this on death)
#define SPELL_SELF_SPAWN_10 28864                           //This is used by the crypt guards when they die

struct TRINITY_DLL_DECL boss_anubrekhanAI : public ScriptedAI
{
    boss_anubrekhanAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 Impale_Timer;
    uint32 LocustSwarm_Timer;
    uint32 Summon_Timer;
    bool HasTaunted;

    void Reset()
    {
        Impale_Timer = 15000;                               //15 seconds
        LocustSwarm_Timer = 80000 + (rand()%40000);         //Random time between 80 seconds and 2 minutes for initial cast
        Summon_Timer = LocustSwarm_Timer + 45000;           //45 seconds after initial locust swarm
    }

    void KilledUnit(Unit* Victim)
    {
        //Force the player to spawn corpse scarabs via spell
        Victim->CastSpell(Victim, SPELL_SELF_SPAWN_5, true);

        if (rand()%5)
            return;

        DoYell(SAY_SLAY, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature, SOUND_SLAY);
    }

    void Aggro(Unit *who)
    {
        switch(rand()%3)
        {
            case 0:
                DoYell(SAY_AGGRO1, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_AGGRO1);
                break;
            case 1:
                DoYell(SAY_AGGRO2, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_AGGRO2);
                break;
            case 2:
                DoYell(SAY_AGGRO3, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_AGGRO3);
                break;
        }
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (!m_creature->getVictim() && who->isTargetableForAttack() && who->isInAccessablePlaceFor(m_creature) && m_creature->IsHostileTo(who))
        {
            if (!m_creature->canFly() && m_creature->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE)
                return;

            float attackRadius = m_creature->GetAttackDistance(who);
            if (m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->IsWithinLOSInMap(who))
            {
                if(who->HasStealthAura())
                    who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

                //Begin melee attack if we are within range
                DoStartAttackAndMovement(who);

                if (!InCombat)
                {
                    switch(rand()%3)
                    {
                        case 0:
                            DoYell(SAY_AGGRO1, LANG_UNIVERSAL, NULL);
                            DoPlaySoundToSet(m_creature, SOUND_AGGRO1);
                            break;
                        case 1:
                            DoYell(SAY_AGGRO2, LANG_UNIVERSAL, NULL);
                            DoPlaySoundToSet(m_creature, SOUND_AGGRO2);
                            break;
                        case 2:
                            DoYell(SAY_AGGRO3, LANG_UNIVERSAL, NULL);
                            DoPlaySoundToSet(m_creature, SOUND_AGGRO3);
                            break;
                    }
                }
            }
            else if (!HasTaunted && m_creature->IsWithinDistInMap(who, 60.0f))
            {
                switch(rand()%5)
                {
                    case 0:
                        DoYell(SAY_TAUNT1, LANG_UNIVERSAL, NULL);
                        DoPlaySoundToSet(m_creature, SOUND_TAUNT1);
                        break;
                    case 1:
                        DoYell(SAY_TAUNT2, LANG_UNIVERSAL, NULL);
                        DoPlaySoundToSet(m_creature, SOUND_TAUNT2);
                        break;
                    case 2:
                        DoYell(SAY_TAUNT3, LANG_UNIVERSAL, NULL);
                        DoPlaySoundToSet(m_creature, SOUND_TAUNT3);
                        break;
                    case 3:
                        DoYell(SAY_TAUNT4, LANG_UNIVERSAL, NULL);
                        DoPlaySoundToSet(m_creature, SOUND_TAUNT4);
                        break;
                    case 4:
                        DoYell(SAY_GREET, LANG_UNIVERSAL, NULL);
                        DoPlaySoundToSet(m_creature, SOUND_GREET);
                        break;
                }
                HasTaunted = true;
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        //Impale_Timer
        if (Impale_Timer < diff)
        {
            //Cast Impale on a random target
            //Do NOT cast it when we are afflicted by locust swarm
            if (!m_creature->HasAura(SPELL_LOCUSTSWARM,1))
            {
                Unit* target = NULL;

                target = SelectUnit(SELECT_TARGET_RANDOM,0);
                if (target)DoCast(target,SPELL_IMPALE);
            }

            Impale_Timer = 15000;
        }else Impale_Timer -= diff;

        //LocustSwarm_Timer
        if (LocustSwarm_Timer < diff)
        {
            DoCast(m_creature, SPELL_LOCUSTSWARM);
            LocustSwarm_Timer = 90000;
        }else LocustSwarm_Timer -= diff;

        //Summon_Timer
        if (Summon_Timer < diff)
        {
            DoCast(m_creature, SPELL_SUMMONGUARD);
            Summon_Timer = 45000;
        }else Summon_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_anubrekhan(Creature *_Creature)
{
    return new boss_anubrekhanAI (_Creature);
}

void AddSC_boss_anubrekhan()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_anubrekhan";
    newscript->GetAI = GetAI_boss_anubrekhan;
    m_scripts[nrscripts++] = newscript;
}

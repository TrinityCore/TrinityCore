/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* Script Data Start
SDName: Boss malygos
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

#include "ScriptPCH.h"

//Spells
#define SPELL_ARCANE_BREATH_N                        56272
#define SPELL_ARCANE_BREATH_H                        60072
#define SPELL_ARCANE_PULSE                           57432
#define SPELL_ARCANE_STORM_1                         57459
#define SPELL_ARCANE_STORM_2                         61693
#define SPELL_ARCANE_STORM_3                         61694
#define SPELL_STATIC_FIELD                           57430
#define SPELL_SURGE_OF_POWER_1                       56505
#define SPELL_SURGE_OF_POWER_2                       57407
#define SPELL_SURGE_OF_POWER_3                       60936
#define SPELL_VORTEX                                 56105

//Dragon "mounts" spells in Phase3
//they use Rugelike energy
#define SPELL_DMOUNT_FLAME_SPIKE                     56091 //maybe not accurate
#define SPELL_DMOUNT_ENGULF_IN_FLAMES                61621
#define SPELL_DMOUNT_REVIVIFY                        57090
#define SPELL_DMOUNT_LIFE_BURST                      57143
#define SPELL_DMOUNT_FLAME_SHIELD                    57108
//#define SPELL_DMOUNT_UNKNOWN                      XYZ //Increases your drake's flight speed by 500%.

//not in db
//Yell
//-->Other
#define SAY_ANTI_MAGIC_SHELL                       -1616000
#define SAY_BREATH_ATTACK                          -1616001
#define SAY_HIGH_DAMAGE_MODE                       -1616002
#define SAY_MAGIC_BLAST                            -1616003
//--> Generic Spells
#define SAY_GENERIC_SPELL_1                        -1616004
#define SAY_GENERIC_SPELL_2                        -1616005
#define SAY_GENERIC_SPELL_3                        -1616006
#define SAY_DEATH                                  -1616007
//--> Prefight
#define SAY_PREFIGHT_1                             -1616008
#define SAY_PREFIGHT_2                             -1616009
#define SAY_PREFIGHT_3                             -1616010
#define SAY_PREFIGHT_4                             -1616011
#define SAY_PREFIGHT_5                             -1616012
//--> Phase1
#define SAY_PHASE1_AGGRO                           -1616013
#define SAY_PHASE1_END                             -1616014
#define SAY_PHASE1_SLAY_1                          -1616015
#define SAY_PHASE1_SLAY_2                          -1616016
#define SAY_PHASE1_SLAY_3                          -1616017

//--> Phase2 at 50% HP,

/*Malygos himself is not targetable during this phase, it will end when the adds he spawns are all killed. However, he does continue to play a part in the encounter.
During this phase he drops anti-magic zones onto the ground the raid MUST stand inside of, it reduces magical damage taken by 50%. They shrink over time, so it's important that your raid moves to each new one he drops.
Throughout the phase, he will deep breath doing ~4k damage per second, unless you are standing inside of the anti-magic zone.
The way the fight works during this phase is there are NPCs riding around on disks in the room. There are two types of mobs, Lords and Scions.
The Lords will move down onto the group, and need to be tanked (They will one-shot a non-tank). After they die, they drop a disk that a raid member can mount onto, which allows them to fly, to attack the Scions that do not come down to the ground.
It is recommended to let melee take the first disks, then ranged. As those mobs die, they also drop disks, which allows the rest of your dps to get onto them.
The Scions will continually cast Arcane Blast on random targets on the floor, which is mitigated by the anti-magic zones. While mounted on a disk, you will not take damage.
After all of the NPCs riding on the disks die, the players on the disks need to dismount as Phase 3 is about to begin.*/

//not in db
#define SAY_PHASE2_AGGRO                           -1616018
#define SAY_PHASE2_END                             -1616019
#define SAY_PHASE2_SLAY_1                          -1616020
#define SAY_PHASE2_SLAY_2                          -1616021
#define SAY_PHASE2_SLAY_3                          -1616022
//--> Phase3 Malygos destroys the floor, encounter continues on dragon "mounts"
#define SAY_PHASE3_INTRO                           -1616023
#define SAY_PHASE3_AGGRO                           -1616024
#define SAY_PHASE3_SLAY_1                          -1616025
#define SAY_PHASE3_SLAY_2                          -1616026
#define SAY_PHASE3_SLAY_3                          -1616027
#define SAY_PHASE3_BIG_ATTACK                      -1616028

enum
{
    ACHIEV_TIMED_START_EVENT                      = 20387,
};

class boss_malygos : public CreatureScript
{
public:
    boss_malygos() : CreatureScript("boss_malygos") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_malygosAI (pCreature);
    }

    struct boss_malygosAI : public ScriptedAI
    {
        boss_malygosAI(Creature *c) : ScriptedAI(c)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript *instance;

        uint32 phase;
        uint32 enrage;

        void Reset()
        {
            phase = 1;
            enrage = 615000;    //Source Deadly Boss Mod

            if (instance)
                instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (phase == 1)
            {
                DoScriptText(SAY_PHASE1_AGGRO, me);
                if (instance)
                    instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
            }

            if (phase == 2)
                DoScriptText(SAY_PHASE1_AGGRO, me);
            if (phase == 3)
                DoScriptText(SAY_PHASE1_AGGRO, me);
        }

        void UpdateAI(const uint32 /*diff*/)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (phase == 1 && HealthBelowPct(50)) {
                phase = 2;
                //spawn adds
                //set malygos unatackable untill all adds spawned dead
                //start phase3
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);
        }

        void KilledUnit(Unit * victim)
        {
            if (victim == me)
                return;

            if (phase == 1)
                DoScriptText(RAND(SAY_PHASE1_SLAY_1,SAY_PHASE1_SLAY_2,SAY_PHASE1_SLAY_3), me);
            if (phase == 2)
                DoScriptText(RAND(SAY_PHASE2_SLAY_1,SAY_PHASE2_SLAY_2,SAY_PHASE2_SLAY_3), me);
            if (phase == 3)
                DoScriptText(RAND(SAY_PHASE3_SLAY_1,SAY_PHASE3_SLAY_2,SAY_PHASE3_SLAY_3), me);
        }
    };

};

void AddSC_boss_malygos()
{
    new boss_malygos();
}

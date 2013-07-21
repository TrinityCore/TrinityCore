/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss salramm
SDAuthor: Tartalo
SD%Complete: 80
SDComment: TODO: Intro
SDCategory:
Script Data End */

#include "ScriptPCH.h"
#include "culling_of_stratholme.h"

enum Spells
{
    SPELL_CURSE_OF_TWISTED_FLESH                = 58845,
    SPELL_EXPLODE_GHOUL                         = 52480,
    H_SPELL_EXPLODE_GHOUL                       = 58825,
    SPELL_SHADOW_BOLT                           = 57725,
    H_SPELL_SHADOW_BOLT                         = 58828,
    SPELL_STEAL_FLESH                           = 52708,
    SPELL_SUMMON_GHOULS                         = 52451
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_SPAWN                                   = 1,
    SAY_SLAY_1                                  = 2,
    SAY_SLAY_2                                  = 2,
    SAY_SLAY_3                                  = 2,
    SAY_DEATH                                   = 3,
    SAY_EXPLODE_GHOUL_1                         = 4,
    SAY_EXPLODE_GHOUL_2                         = 4,
    SAY_STEAL_FLESH_1                           = 5,
    SAY_STEAL_FLESH_2                           = 5,
    SAY_STEAL_FLESH_3                           = 5,
    SAY_SUMMON_GHOULS_1                         = 6,
    SAY_SUMMON_GHOULS_2                         = 6
};

class boss_salramm : public CreatureScript
{
public:
    boss_salramm() : CreatureScript("boss_salramm") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_salrammAI (creature);
    }

    struct boss_salrammAI : public ScriptedAI
    {
        boss_salrammAI(Creature* c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
            if (instance)
                Talk(SAY_SPAWN);
        }

        uint32 uiCurseFleshTimer;
        uint32 uiExplodeGhoulTimer;
        uint32 uiShadowBoltTimer;
        uint32 uiStealFleshTimer;
        uint32 uiSummonGhoulsTimer;
        uint32 uiRespawnZombiesTimer;
        bool bTransformed;

        InstanceScript* instance;

        void Reset()
        {
             uiCurseFleshTimer = 30000; 
             uiExplodeGhoulTimer = 25000; 
             uiShadowBoltTimer = 8000; 
             uiStealFleshTimer = 12345;
             uiSummonGhoulsTimer = 19000; 
             uiRespawnZombiesTimer = 200000;
             bTransformed = false;

             if (instance)
                 instance->SetData(DATA_SALRAMM_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);

            if (instance)
                 instance->SetData(DATA_SALRAMM_EVENT, IN_PROGRESS);
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //Curse of twisted flesh timer
            if (uiCurseFleshTimer <= diff)
            {
                DoCast(me->GetVictim(), SPELL_CURSE_OF_TWISTED_FLESH);
                uiCurseFleshTimer = 37000;
            } else uiCurseFleshTimer -= diff;

            //Shadow bolt timer
            if (uiShadowBoltTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_SHADOW_BOLT);
                uiShadowBoltTimer = 8000;
            } else uiShadowBoltTimer -= diff;

            //Steal Flesh timer
            if (uiStealFleshTimer <= diff)
            {
                Talk(SAY_STEAL_FLESH_1);
                if (Unit* random_pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(random_pTarget, SPELL_STEAL_FLESH);
                uiStealFleshTimer = 10000;
            } 
			else uiStealFleshTimer -= diff; 

            //Summon ghouls timer
            if (uiSummonGhoulsTimer <= diff)
            {
                Talk(SAY_SUMMON_GHOULS_1);
                if (Unit* random_pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(random_pTarget, SPELL_SUMMON_GHOULS);
                uiSummonGhoulsTimer = 10000;
            } 
			else uiSummonGhoulsTimer -= diff;
			
            // Respawn risen zombies at town
            if(!bTransformed)
                if (uiRespawnZombiesTimer <= diff)
                {
                    instance->SetData(DATA_TRANSFORM_CITIZENS, SPECIAL);
                    bTransformed = true;
                }
                else uiRespawnZombiesTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);

            if (instance)
                instance->SetData(DATA_SALRAMM_EVENT, DONE);
        }

        void KilledUnit(Unit* victim)
        {
            if (victim == me)
                return;

            Talk(SAY_SLAY_1);
        }
    };

};

void AddSC_boss_salramm()
{
    new boss_salramm();
}

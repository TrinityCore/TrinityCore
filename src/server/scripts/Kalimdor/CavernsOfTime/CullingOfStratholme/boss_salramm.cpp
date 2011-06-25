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
    H_SPELL_SHADOW_BOLT                         = 58827,
    SPELL_STEAL_FLESH                           = 52708,
    SPELL_STEAL_FLESH_VICTIM                    = 52711,
    SPELL_STEAL_FLESH_SELF                      = 52712,
    SPELL_SUMMON_GHOULS                         = 52451
};

enum Entry
{
    NPC_GHOUL_MINION                            = 27733
};

enum Yells
{
    SAY_AGGRO                                   = -1595032,
    SAY_SPAWN                                   = -1595033,
    SAY_SLAY_1                                  = -1595034,
    SAY_SLAY_2                                  = -1595035,
    SAY_SLAY_3                                  = -1595036,
    SAY_DEATH                                   = -1595037,
    SAY_EXPLODE_GHOUL_1                         = -1595038,
    SAY_EXPLODE_GHOUL_2                         = -1595039,
    SAY_STEAL_FLESH_1                           = -1595040,
    SAY_STEAL_FLESH_2                           = -1595041,
    SAY_STEAL_FLESH_3                           = -1595042,
    SAY_SUMMON_GHOULS_1                         = -1595043,
    SAY_SUMMON_GHOULS_2                         = -1595044
};

class boss_salramm : public CreatureScript
{
public:
    boss_salramm() : CreatureScript("boss_salramm") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_salrammAI (pCreature);
    }

    struct boss_salrammAI : public ScriptedAI
    {
        boss_salrammAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
            if (pInstance)
                DoScriptText(SAY_SPAWN,me);
        }

        uint32 uiCurseFleshTimer;
        uint32 uiExplodeGhoulTimer;
        uint32 uiShadowBoltTimer;
        uint32 uiStealFleshTimer;
        uint32 uiSummonGhoulsTimer;

        InstanceScript* pInstance;

        void Reset()
        {
             uiCurseFleshTimer = 10000;
             uiExplodeGhoulTimer = 50000;
             uiShadowBoltTimer = urand(8000, 12000);
             uiStealFleshTimer = 15000;
             uiSummonGhoulsTimer = urand(15000, 20000);

             if (pInstance)
                 pInstance->SetData(DATA_SALRAMM_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);

            if (pInstance)
                 pInstance->SetData(DATA_SALRAMM_EVENT, IN_PROGRESS);
        }

        void SpellHitTarget(Unit* pTarget, const SpellEntry* spell) 
        {
            if (spell->Id == SPELL_STEAL_FLESH)
            {
                DoCast(pTarget, SPELL_STEAL_FLESH_VICTIM, true);
                DoCast(me, SPELL_STEAL_FLESH_SELF, true);
            }
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            //Curse of twisted flesh timer
            if(IsHeroic())
                if (uiCurseFleshTimer <= diff)
                {
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true))
                        DoCast(pTarget, SPELL_CURSE_OF_TWISTED_FLESH);
                    uiCurseFleshTimer = 25000;
                } else uiCurseFleshTimer -= diff;

            //Shadow bolt timer
            if (uiShadowBoltTimer <= diff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(pTarget, SPELL_SHADOW_BOLT);
                uiShadowBoltTimer = urand(8000,12000);
            } else uiShadowBoltTimer -= diff;

            //Steal Flesh timer
            if (uiStealFleshTimer <= diff)
            {
                DoScriptText(RAND(SAY_STEAL_FLESH_1,SAY_STEAL_FLESH_2,SAY_STEAL_FLESH_3), me);
                if (Unit* random_pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(random_pTarget, SPELL_STEAL_FLESH);
                uiStealFleshTimer = 10000;
            } else uiStealFleshTimer -= diff;

            //Summon ghouls timer
            if (uiSummonGhoulsTimer <= diff)
            {
                 DoScriptText(RAND(SAY_SUMMON_GHOULS_1,SAY_SUMMON_GHOULS_2), me);
                if (Unit* random_pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
	
                     DoCast(random_pTarget, SPELL_SUMMON_GHOULS);
                uiSummonGhoulsTimer = 10000;

            } else uiSummonGhoulsTimer -= diff;

            if (uiExplodeGhoulTimer <= diff)
            {
                DoScriptText(RAND(SAY_EXPLODE_GHOUL_1, SAY_EXPLODE_GHOUL_2), me);
                DoCast(DUNGEON_MODE(SPELL_EXPLODE_GHOUL, H_SPELL_EXPLODE_GHOUL));
                uiExplodeGhoulTimer = urand(6000, 8000);
            } else uiExplodeGhoulTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);

            if (pInstance)
                pInstance->SetData(DATA_SALRAMM_EVENT, DONE);
        }

        void JustSummoned(Creature* summon)
        {
            summon->SetCorpseDelay(0);  //instant despawn corpse (needed?)
        }

        void KilledUnit(Unit* victim)
        {
            if (victim == me)
                return;

            DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2, SAY_SLAY_3), me);
        }
    };

};

void AddSC_boss_salramm()
{
    new boss_salramm();
}

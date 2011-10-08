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

#include "ScriptPCH.h"
#include "violet_hold.h"

enum Spells
{
    SPELL_ARCANE_VACUUM                         = 58694,
    SPELL_BLIZZARD                              = 58693,
    H_SPELL_BLIZZARD                            = 59369,
    SPELL_MANA_DESTRUCTION                      = 59374,
    SPELL_TAIL_SWEEP                            = 58690,
    H_SPELL_TAIL_SWEEP                          = 59283,
    SPELL_UNCONTROLLABLE_ENERGY                 = 58688,
    H_SPELL_UNCONTROLLABLE_ENERGY               = 59281,
    SPELL_TRANSFORM                             = 58668
};

enum Yells
{
    SAY_AGGRO                                   = -1608000,
    SAY_SLAY_1                                  = -1608001,
    SAY_SLAY_2                                  = -1608002,
    SAY_SLAY_3                                  = -1608003,
    SAY_DEATH                                   = -1608004,
    SAY_SPAWN                                   = -1608005,
    SAY_DISRUPTION                              = -1608006,
    SAY_BREATH_ATTACK                           = -1608007,
    SAY_SPECIAL_ATTACK_1                        = -1608008,
    SAY_SPECIAL_ATTACK_2                        = -1608009
};

class boss_cyanigosa : public CreatureScript
{
public:
    boss_cyanigosa() : CreatureScript("boss_cyanigosa") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_cyanigosaAI (creature);
    }

    struct boss_cyanigosaAI : public ScriptedAI
    {
        boss_cyanigosaAI(Creature* c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
        }

        uint32 uiArcaneVacuumTimer;
        uint32 uiBlizzardTimer;
        uint32 uiManaDestructionTimer;
        uint32 uiTailSweepTimer;
        uint32 uiUncontrollableEnergyTimer;

        InstanceScript* instance;

        void Reset()
        {
            uiArcaneVacuumTimer = 10000;
            uiBlizzardTimer = 15000;
            uiManaDestructionTimer = 30000;
            uiTailSweepTimer = 20000;
            uiUncontrollableEnergyTimer = 25000;
            if (instance)
                instance->SetData(DATA_CYANIGOSA_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);

            if (instance)
                instance->SetData(DATA_CYANIGOSA_EVENT, IN_PROGRESS);
        }

        void MoveInLineOfSight(Unit* /*who*/) {}

        void UpdateAI(const uint32 diff)
        {
            if (instance && instance->GetData(DATA_REMOVE_NPC) == 1)
            {
                me->DespawnOrUnsummon();
                instance->SetData(DATA_REMOVE_NPC, 0);
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiArcaneVacuumTimer <= diff)
            {
                DoCast(SPELL_ARCANE_VACUUM);
                uiArcaneVacuumTimer = 10000;
            } else uiArcaneVacuumTimer -= diff;

            if (uiBlizzardTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_BLIZZARD);
                uiBlizzardTimer = 15000;
            } else uiBlizzardTimer -= diff;

            if (uiTailSweepTimer <= diff)
            {
                DoCast(SPELL_TAIL_SWEEP);
                uiTailSweepTimer = 20000;
            } else uiTailSweepTimer -= diff;

            if (uiUncontrollableEnergyTimer <= diff)
            {
                DoCastVictim(SPELL_UNCONTROLLABLE_ENERGY);
                uiUncontrollableEnergyTimer = 25000;
            } else uiUncontrollableEnergyTimer -= diff;

            if (IsHeroic())
            {
                if (uiManaDestructionTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        DoCast(target, SPELL_MANA_DESTRUCTION);
                    uiManaDestructionTimer = 30000;
                } else uiManaDestructionTimer -= diff;
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);

            if (instance)
                instance->SetData(DATA_CYANIGOSA_EVENT, DONE);
        }

        void KilledUnit(Unit* victim)
        {
            if (victim == me)
                return;
            DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2, SAY_SLAY_3), me);
        }
    };

};

class achievement_defenseless : public AchievementCriteriaScript
{
    public:
        achievement_defenseless() : AchievementCriteriaScript("achievement_defenseless")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target)
        {
            if(!target)
                return false;

            InstanceScript* instance = target->GetInstanceScript();
            if (!instance)
                return false;

            if (!instance->GetData(DATA_DEFENSELESS))
                return false;

            return true;
        }
};

void AddSC_boss_cyanigosa()
{
    new boss_cyanigosa();
    new achievement_defenseless();
}

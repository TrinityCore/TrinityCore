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
SDName: Boss meathook
SDAuthor: Tartalo
SD%Complete: 100
SDComment: It may need timer adjustment
SDCategory:
Script Data End */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "culling_of_stratholme.h"

enum Spells
{
    SPELL_CONSTRICTING_CHAINS                   = 52696, //Encases the targets in chains, dealing 1800 Physical damage every 1 sec. and stunning the target for 5 sec.
    H_SPELL_CONSTRICTING_CHAINS                 = 58823,
    SPELL_DISEASE_EXPULSION                     = 52666, //Meathook belches out a cloud of disease, dealing 1710 to 1890 Nature damage and interrupting the spell casting of nearby enemy targets for 4 sec.
    H_SPELL_DISEASE_EXPULSION                   = 58824,
    SPELL_FRENZY                                = 58841 //Increases the caster's Physical damage by 10% for 30 sec.
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_SLAY                                    = 1,
    SAY_SPAWN                                   = 2,
    SAY_DEATH                                   = 3
};

class boss_meathook : public CreatureScript
{
public:
    boss_meathook() : CreatureScript("boss_meathook") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_meathookAI>(creature);
    }

    struct boss_meathookAI : public ScriptedAI
    {
        boss_meathookAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            if (instance)
                Talk(SAY_SPAWN);
        }

        uint32 uiChainTimer;
        uint32 uiDiseaseTimer;
        uint32 uiFrenzyTimer;

        InstanceScript* instance;

        void Reset() OVERRIDE
        {
            uiChainTimer = urand(12000, 17000);   //seen on video 13, 17, 15, 12, 16
            uiDiseaseTimer = urand(2000, 4000);   //approx 3s
            uiFrenzyTimer = urand(21000, 26000);  //made it up

            if (instance)
                instance->SetData(DATA_MEATHOOK_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_AGGRO);

            if (instance)
                instance->SetData(DATA_MEATHOOK_EVENT, IN_PROGRESS);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiDiseaseTimer <= diff)
            {
                DoCastAOE(SPELL_DISEASE_EXPULSION);
                uiDiseaseTimer = urand(1500, 4000);
            } else uiDiseaseTimer -= diff;

            if (uiFrenzyTimer <= diff)
            {
                DoCast(me, SPELL_FRENZY);
                uiFrenzyTimer = urand(21000, 26000);
            } else uiFrenzyTimer -= diff;

            if (uiChainTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_CONSTRICTING_CHAINS); //anyone but the tank
                uiChainTimer = urand(2000, 4000);
            } else uiChainTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Talk(SAY_DEATH);

            if (instance)
                instance->SetData(DATA_MEATHOOK_EVENT, DONE);
        }

        void KilledUnit(Unit* victim) OVERRIDE
        {
            if (victim->GetTypeId() != TYPEID_PLAYER)
                return;

            Talk(SAY_SLAY);
        }
    };

};

void AddSC_boss_meathook()
{
    new boss_meathook();
}

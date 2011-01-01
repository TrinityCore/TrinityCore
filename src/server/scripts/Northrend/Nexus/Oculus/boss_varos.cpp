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
#include "oculus.h"

enum Spells
{
    SPELL_ENERGIZE_CORES                          = 50785, //Damage 5938 to 6562, effec2 Triggers 54069, effect3 Triggers 56251
    SPELL_ENERGIZE_CORES_TRIGGER_1                = 54069,
    SPELL_ENERGIZE_CORES_TRIGGER_2                = 56251,
    SPELL_ENERGIZE_CORES_2                        = 59372, //Damage 9025 to 9975, effect2 Triggers 54069, effect 56251
    SPELL_CALL_AZURE_RING_CAPTAIN                 = 51002, //Effect    Send Event (12229)
    SPELL_CALL_AZURE_RING_CAPTAIN_2               = 51006, //Effect    Send Event (10665)
    SPELL_CALL_AZURE_RING_CAPTAIN_3               = 51007, //Effect    Send Event (18454)
    SPELL_CALL_AZURE_RING_CAPTAIN_4               = 51008, //Effect    Send Event (18455)
    SPELL_CALL_AMPLIFY_MAGIC                      = 51054,
    SPELL_CALL_AMPLIFY_MAGIC_2                    = 59371
};
//not in db
enum Yells
{
    SAY_AGGRO                                     = -1578022,
    SAY_KILL_1                                    = -1578023,
    SAY_KILL_2                                    = -1578024,
    SAY_DEATH                                     = -1578025,
    SAY_STRIKE_1                                  = -1578026,
    SAY_STRIKE_2                                  = -1578027,
    SAY_STRIKE_3                                  = -1578028,
    SAY_SPAWN                                     = -1578029
};

class boss_varos : public CreatureScript
{
public:
    boss_varos() : CreatureScript("boss_varos") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_varosAI (pCreature);
    }

    struct boss_varosAI : public ScriptedAI
    {
        boss_varosAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;

        void Reset()
        {
            if (pInstance)
                pInstance->SetData(DATA_VAROS_EVENT, NOT_STARTED);
        }
        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);

            if (pInstance)
                pInstance->SetData(DATA_VAROS_EVENT, IN_PROGRESS);
        }
        void AttackStart(Unit* /*who*/) {}
        void MoveInLineOfSight(Unit* /*who*/) {}
        void UpdateAI(const uint32 /*diff*/)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);

            if (pInstance)
                pInstance->SetData(DATA_VAROS_EVENT, DONE);
        }
        void KilledUnit(Unit * victim)
        {
            if (victim == me)
                return;
            DoScriptText(RAND(SAY_KILL_1,SAY_KILL_2), me);
        }
    };

};


void AddSC_boss_varos()
{
    new boss_varos();
}

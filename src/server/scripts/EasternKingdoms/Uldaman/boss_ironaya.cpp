/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

/* ScriptData
SDName: Boss_Ironaya
SD%Complete: 100
SDComment:
SDCategory: Uldaman
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "uldaman.h"

enum Ironaya
{
    SPELL_ARCINGSMASH           = 8374,
    SPELL_KNOCKAWAY             = 10101,
    SPELL_WSTOMP                = 11876
};

class boss_ironaya : public CreatureScript
{
    public:

        boss_ironaya()
            : CreatureScript("boss_ironaya")
        {
        }

        struct boss_ironayaAI : public ScriptedAI
        {
            boss_ironayaAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                uiArcingTimer = 3000;
                bHasCastKnockaway = false;
                bHasCastWstomp = false;
            }

            uint32 uiArcingTimer;
            bool bHasCastWstomp;
            bool bHasCastKnockaway;

            void Reset() override
            {
                Initialize();
            }

            void EnterCombat(Unit* /*who*/) override { }

            void UpdateAI(uint32 uiDiff) override
            {
                //Return since we have no target
                if (!UpdateVictim())
                    return;

                //If we are <50% hp do knockaway ONCE
                if (!bHasCastKnockaway && HealthBelowPct(50) && me->GetVictim())
                {
                    DoCastVictim(SPELL_KNOCKAWAY, true);
                    me->GetThreatManager().ResetThreat(me->EnsureVictim());

                    //Shouldn't cast this agian
                    bHasCastKnockaway = true;
                }

                //uiArcingTimer
                if (uiArcingTimer <= uiDiff)
                {
                    DoCast(me, SPELL_ARCINGSMASH);
                    uiArcingTimer = 13000;
                } else uiArcingTimer -= uiDiff;

                if (!bHasCastWstomp && HealthBelowPct(25))
                {
                    DoCast(me, SPELL_WSTOMP);
                    bHasCastWstomp = true;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUldamanAI<boss_ironayaAI>(creature);
        }
};

//This is the actual function called only once durring InitScripts()
//It must define all handled functions that are to be run in this script
void AddSC_boss_ironaya()
{
    new boss_ironaya();
}

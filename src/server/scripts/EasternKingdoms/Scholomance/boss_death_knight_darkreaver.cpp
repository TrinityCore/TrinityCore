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
 SDName: Boss_Death_knight_darkreaver
 SD%Complete: 100
 SDComment:
 SDCategory: Scholomance
 EndScriptData */

#include "ScriptMgr.h"
#include "scholomance.h"
#include "ScriptedCreature.h"

class boss_death_knight_darkreaver : public CreatureScript
{
public:
    boss_death_knight_darkreaver() : CreatureScript("boss_death_knight_darkreaver") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetScholomanceAI<boss_death_knight_darkreaverAI>(creature);
    }

    struct spell_event
    {
    public:
        spell_event()
        {
            spellID = 0;
            onself = false;
            castRepeatMin = 3000;
            castRepeatMax = 5000;
            activeDelay = urand(3000, 8000);
        }

        uint32 spellID;
        bool onself;
        uint32 castRepeatMin;
        uint32 castRepeatMax;
        int activeDelay;
    };

    struct boss_death_knight_darkreaverAI : public ScriptedAI
    {
        boss_death_knight_darkreaverAI(Creature* creature) : ScriptedAI(creature)
        {
            seMap.clear();
            spell_event se1;
            se1.spellID = 17393;
            se1.castRepeatMin = 10000;
            se1.castRepeatMax = 12000;
            seMap[seMap.size()] = se1;
            spell_event se2;
            se2.spellID = 15284;
            se2.castRepeatMin = 5000;
            se2.castRepeatMax = 8000;
            seMap[seMap.size()] = se2;
            spell_event se3;
            se3.spellID = 22644;
            se3.castRepeatMin = 8000;
            se3.castRepeatMax = 10000;
            seMap[seMap.size()] = se3;
            Reset();
        }

        void Reset() override
        {
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage) override
        {
            if (me->GetHealth() <= damage)
            {
                DoCast(me, SCHOLOMANCE_SPELL::SPELL_SUMMON_DARKREAVER_FALLEN_CHARGER, true);   //Summon Darkreaver's Fallen Charger
            }
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            Talk(SCHOLOMANCE_LINE_DEATH_KNIGHT_DARKREAVER::LINE_DEATH_KNIGHT_DARKREAVER_0);
        }

        void UpdateAI(uint32 diff) override
        {
            if (me->IsNonMeleeSpellCast(false))
            {
                return;
            }
            if (UpdateVictim())
            {
                for (std::unordered_map<uint32, spell_event>::iterator seIT = seMap.begin(); seIT != seMap.end(); seIT++)
                {
                    if (seIT->second.activeDelay > 0)
                    {
                        seIT->second.activeDelay -= diff;
                    }
                    if (seIT->second.activeDelay <= 0)
                    {
                        if (Unit* target = me->GetVictim())
                        {
                            if (me->CastSpell(target, seIT->second.spellID) == SpellCastResult::SPELL_CAST_OK)
                            {
                                seIT->second.activeDelay = urand(seIT->second.castRepeatMin, seIT->second.castRepeatMax);
                                return;
                            }
                        }
                    }
                }
                DoMeleeAttackIfReady();
            }
        }

        std::unordered_map<uint32, spell_event> seMap;
    };

};

void AddSC_boss_death_knight_darkreaver()
{
    new boss_death_knight_darkreaver();
}

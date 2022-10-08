/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "temple_of_sethraliss.h"

enum Spells
{
    SPELL_LOOSE_SPARKS = 268598,
    SPELL_LOOSE_SPARKS_DMG = 267483,
};

enum MiscData
{
    AT_SPELL_MISC_ID = 13248
};

 // npc 136108
 // misc 13248
struct npc_loose_spark : public ScriptedAI
{
    npc_loose_spark(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        Position const spawnPosition = me->GetPosition();
        float circularAddition = float(M_PI) / 2;
        for (int32 i = 0; i < 4; ++i)
        {
            float angle = -circularAddition + i*circularAddition;
            // Clockwise
            for (int32 j = 0; j < 3; ++j)
            {
                float radius = 10.0f - j * 4;
                AreaTrigger::CreateAreaTrigger(AT_SPELL_MISC_ID, me, SPELL_LOOSE_SPARKS, spawnPosition, -1, radius, angle, 12000, true, false);
            }
            // Counterclockwise
            for (int32 j = 0; j < 2; ++j)
            {
                float radius = 8.0f - j * 4;
                AreaTrigger::CreateAreaTrigger(AT_SPELL_MISC_ID, me, SPELL_LOOSE_SPARKS, spawnPosition, -1, radius, angle, 12000, true, true);
            }
        }
    }

    void UpdateAI(uint32 /*diff*/) override { }
};

// 17715
class at_loose_sparks : public AreaTriggerEntityScript
{
public:
    at_loose_sparks() : AreaTriggerEntityScript("at_loose_sparks") { }

    struct at_loose_sparksAI : AreaTriggerAI
    {
        at_loose_sparksAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* unit) override
        {
            if (unit && unit->GetTypeId() == TYPEID_PLAYER)
                if (Unit* caster = at->GetCaster())
                    caster->CastSpell(unit, SPELL_LOOSE_SPARKS_DMG, true);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_loose_sparksAI(areatrigger);
    }
};

void AddSC_temple_of_sethraliss()
{
    RegisterCreatureAI(npc_loose_spark);
    new at_loose_sparks();
}

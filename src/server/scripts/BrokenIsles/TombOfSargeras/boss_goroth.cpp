/*
* Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "tomb_of_sargeras.h"

enum Spells
{
    SPELL_BURNING_ARMOR         = 231363,
    SPELL_BURNING_ERUPTION      = 231395, // Casted at SPELL_BURNING_ARMOR end
    SPELL_CRASHING_COMET        = 232249,

    // Shattering Star
    SPELL_SHATTERING_STAR       = 233272,
    SPELL_SHATTERING_STAR_AT    = 233279,
    SPELL_SHATTERING_STAR_DAMAGE= 233281,


    SPELL_SHATTERING_NOVA       = 233272, // SPELL_SHATTERING_STAR damages ?

    SPELL_INFERNAL_BURNING      = 233062,
};

struct boss_goroth : public BossAI
{
    boss_goroth(Creature* creature) : BossAI(creature, DATA_GOROTH) { }

    void EnterCombat(Unit* /*attacker*/) override
    {
        events.ScheduleEvent(SPELL_BURNING_ARMOR, 15s);
        events.ScheduleEvent(SPELL_CRASHING_COMET, 15s);
        events.ScheduleEvent(SPELL_SHATTERING_STAR, 15s);
        events.ScheduleEvent(SPELL_INFERNAL_BURNING, 15s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case SPELL_BURNING_ARMOR:
            {
                DoCast(SPELL_BURNING_ARMOR);
                events.Repeat(15s);
                break;
            }
            case SPELL_CRASHING_COMET:
            {
                DoCast(SPELL_CRASHING_COMET);
                events.Repeat(15s);
                break;
            }
            case SPELL_SHATTERING_STAR:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 2))
                    DoCast(target, SPELL_SHATTERING_STAR);

                events.Repeat(15s);
                break;
            }
            case SPELL_INFERNAL_BURNING:
            {
                DoCast(SPELL_INFERNAL_BURNING);
                events.Repeat(15s);
                break;
            }
            default:
                break;
        }
    }
};

void AddSC_boss_goroth()
{
    RegisterCreatureAI(boss_goroth);
}

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

#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "Unit.h"

namespace Scripts::EasternKingdoms::Vashjir::Mobus
{
namespace Spells
{
    static constexpr uint32 SpellAlgae = 93491;
    static constexpr uint32 SpellRam = 93492;
    static constexpr uint32 SpellWake = 93494;
}
namespace Events
{
    static constexpr uint32 EventAlgae = 1;
    static constexpr uint32 EventRam = 2;
    static constexpr uint32 EventWake = 3;
}

// 50009 - Mobus
struct worldboss_mobus : public WorldBossAI
{
    using WorldBossAI::WorldBossAI;

    void JustEngagedWith(Unit* who) override
    {
        WorldBossAI::JustEngagedWith(who);

        events.ScheduleEvent(Events::EventAlgae, 7s);
        events.ScheduleEvent(Events::EventRam, 12s);
        events.ScheduleEvent(Events::EventWake, 30s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case Events::EventAlgae:
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 80.0f, true))
                        DoCast(target, Spells::SpellAlgae);
                    events.ScheduleEvent(Events::EventAlgae, 12s);
                    break;
                }
                case Events::EventRam:
                {
                    DoCastVictim(Spells::SpellRam);
                    events.ScheduleEvent(Events::EventRam, 40s);
                    break;
                }
                case Events::EventWake:
                {
                    DoCast(Spells::SpellWake);
                    events.ScheduleEvent(Events::EventWake, 50s);
                    break;
                }
                default:
                    break;
            }
        }
    }
};
}

void AddSC_worldboss_mobus()
{
    using namespace Scripts::EasternKingdoms::Vashjir::Mobus;

    // Creature
    RegisterCreatureAI(worldboss_mobus);
}

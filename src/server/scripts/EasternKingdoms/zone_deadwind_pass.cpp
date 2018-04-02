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

#include "ScriptMgr.h"
#include "Player.h"
#include "SpellMgr.h"

enum
{
    QUEST_BLINK_OF_AN_EYE   = 44663,
    SPELL_DALARAN_TELEPORT  = 228326,
};

// Zone 41
class zone_deadwind_pass : public ZoneScript
{
public:
    zone_deadwind_pass() : ZoneScript("zone_deadwind_pass") { }

    void OnPlayerEnter(Player* player) override
    {
        player->GetScheduler().Schedule(Milliseconds(500), 41, [](TaskContext context)
        {
            if (Player* contextPlayer = GetContextPlayer())
                if (contextPlayer->GetQuestStatus(QUEST_BLINK_OF_AN_EYE) == QUEST_STATUS_INCOMPLETE && contextPlayer->GetPositionZ() < 700.0f)
                    if (SpellTargetPosition const* targetPosition = sSpellMgr->GetSpellTargetPosition(SPELL_DALARAN_TELEPORT, EFFECT_0))
                        contextPlayer->NearTeleportTo(targetPosition->target_X, targetPosition->target_Y, targetPosition->target_Z, targetPosition->target_Orientation);

            context.Repeat();
        });
    }

    void OnPlayerExit(Player* player) override
    {
        player->GetScheduler().CancelGroup(41);
    }
};

void AddSC_deadwind_pass()
{
    new zone_deadwind_pass();
}

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
    ZONE_MACARE             = 8701,
    AREA_MACAREE_VINDICAAR  = 8915
};

// Zone 8701
class zone_argus_macaree : public ZoneScript
{
public:
    zone_argus_macaree() : ZoneScript("zone_argus_macaree") { }

    void OnPlayerEnter(Player* player) override
    {
        player->GetScheduler().Schedule(Milliseconds(2s), ZONE_MACARE, [](TaskContext context)
        {
            if (Player* player = GetContextPlayer())
                if (player->GetAreaId() == AREA_MACAREE_VINDICAAR)
                    if (player->GetPositionZ() <= 0.0f)
                        player->NearTeleportTo(4600.83f, 9831.83f, 70.0f, 0.213662f);

            context.Repeat();
        });
    }

    void OnPlayerExit(Player* player) override
    {
        player->GetScheduler().CancelGroup(ZONE_MACARE);
    }
};

void AddSC_zone_argus_macaree()
{
    new zone_argus_macaree();
}

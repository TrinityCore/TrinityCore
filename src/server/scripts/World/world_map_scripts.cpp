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

#include "ScriptMgr.h"
#include "EventMap.h"
#include "Map.h"
#include "Player.h"
#include "SpellMgr.h"
#include "Transport.h"
#include "Unit.h"
#include "Weather.h"
#include "ObjectMgr.h"
#include "SpellInfo.h"

enum Gilneas
{
    MAP_GILNEAS             = 654,
    ZONE_ID_GILNEAS         = 4714,
    ZONE_ID_GILNEAS_CITY    = 4755,

    EVENT_CAST_CATACLYSM    = 1,

    SPELL_CATACLYSM_1       = 68953,
    SPELL_CATACLYSM_2       = 80134,
    SPELL_CATACLYSM_3       = 80133
};

uint32 cataclysmSpells[] =
{
    SPELL_CATACLYSM_1,
    SPELL_CATACLYSM_2,
    SPELL_CATACLYSM_3
};

class world_map_gilneas: public WorldMapScript
{
    public:
        world_map_gilneas() : WorldMapScript("world_map_gilneas", MAP_GILNEAS) { }

        void OnCreate(Map* map) override
        {
            map->SetZoneWeather(ZONE_ID_GILNEAS, WEATHER_STATE_RAIN_DRIZZLE, 0.3f);
            map->SetZoneWeather(ZONE_ID_GILNEAS_CITY, WEATHER_STATE_FINE, 1.0f);
            _events.ScheduleEvent(EVENT_CAST_CATACLYSM, 1ms);
        }

        void OnUpdate(Map* map, uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CAST_CATACLYSM:
                    {
                        Map::PlayerList const& players = map->GetPlayers();

                        for (auto const& i : players)
                        {
                            if (Player* player = i.GetSource())
                            {
                                for (uint8 i = 0; i < 3; i++)
                                {
                                    if (SpellInfo const* spell = sSpellMgr->GetSpellInfo(cataclysmSpells[i]))
                                        if (player->HasAura(spell->TargetAuraSpell))
                                            player->CastSpell(player, cataclysmSpells[i]);
                                }
                            }
                        }
                        _events.Repeat(1min, 2min);
                        break;
                    }
                    default:
                        break;
                }
            }
        }

    private:
        EventMap _events;
};

void AddSC_world_map_scripts()
{
    new world_map_gilneas();
}

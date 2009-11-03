/*
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "OutdoorPvPNR.h"
#include "Player.h"

OutdoorPvPNR::OutdoorPvPNR()
{
    m_TypeId = OUTDOOR_PVP_NR;
}

bool OutdoorPvPNR::SetupOutdoorPvP()
{
    RegisterZone(4395);
    return true;
}

void OutdoorPvPNR::HandlePlayerEnterZone(Player * plr, uint32 zone)
{
    if (!plr->HasAura(SPELL_NOFLYZONE) && !plr->HasAura(SPELL_PARACHUTE) &&
        (plr->HasAuraType(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED) || plr->HasAuraType(SPELL_AURA_FLY)))
    {
        plr->CastSpell(plr, SPELL_NOFLYZONE, true);
        ChatHandler(plr).PSendSysMessage(LANG_ZONE_NOFLYZONE);
        plr->GetSession()->SendNotification(LANG_ZONE_NOFLYZONE);
    }
    OutdoorPvP::HandlePlayerEnterZone(plr, zone);
}

void OutdoorPvPNR::HandlePlayerLeaveZone(Player *plr, uint32 zone)
{
    plr->RemoveAura(SPELL_NOFLYZONE);
    OutdoorPvP::HandlePlayerLeaveZone(plr, zone);
}


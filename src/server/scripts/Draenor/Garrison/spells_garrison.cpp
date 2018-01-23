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
#include "Spell.h"
#include "SpellScript.h"
#include "WodGarrison.h"

// 171253 - Garrison hearthstone
class spell_garrison_hearthstone : public SpellScript
{
    PrepareSpellScript(spell_garrison_hearthstone);

    void SetDest(SpellDestination& dest)
    {
        if (Player* caster = GetCaster()->ToPlayer())
        {
            if (Garrison* garr = caster->GetGarrison(GARRISON_TYPE_GARRISON))
            {
                if (GarrSiteLevelEntry const* siteLevel = garr->GetSiteLevel())
                {
                    // Adjust effect summon position
                    Position const garrPos = GarrisonHearthstoneCoordinates[caster->GetTeamId()][siteLevel->Level];
                    dest.Relocate(WorldLocation(siteLevel->MapID, garrPos));
                }
            }
        }
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_garrison_hearthstone::SetDest, EFFECT_0, TARGET_DEST_DB);
    }
};

void AddSC_spells_garrison()
{
    new spell_garrison_hearthstone();
}

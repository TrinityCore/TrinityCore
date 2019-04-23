/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "ScriptedCreature.h"
#include "Player.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "Object.h"

enum NPCIDS
{
    creature_portal_bunny           = 39834,
    creature_burning_exile          = 39829,
    creature_thundering_windfury    = 39831,
    creature_glacial_exile          = 39830,
    creature_rumbling_betrayer      = 43737,
    creature_chogall                = 43932,
    creature_glak                   = 39607,
    creature_moltar                 = 43838,
    creature_braz                   = 43864,
    creature_durk                   = 43865,
    creature_orhan                  = 43931,
    creature_raider                 = 39608,
    creature_plante_stalker         = 39832,
    creature_globe_of_azeroth       = 39809,
};

Position const burningexilepos =        { -3758.23f, 1091.86f, 201.763f, 0.0f };
Position const thunderingwindfurypos =  { -3728.23f, 1121.86f, 176.763f, 4.71239f };
Position const glacialexilepos =        { -3698.23f, 1086.86f, 175.763f, 2.96706f };
Position const rumblingbetrayerpos =    { -3733.23f, 1061.86f, 191.763f, 1.39627f };

Position const chogallpos =             { -3670.53f, 1117.04f, 159.107f, 3.56047f };
Position const glakpos =                { -3667.23f, 1093.19f, 160.347f, 3.05433f };
Position const Moltarpos =              { -3688.79f, 1131.94f, 160.646f, 4.03171f };
Position const brazpos =                { -3668.99f, 1077.40f, 160.646f, 2.89725f };
Position const durkpos =                { -3702.71f, 1138.56f, 160.646f, 4.36332f };

Position const plante_stalker_pos =     { -3728.23f, 1091.86f, 166.763f, 0.0f };
Position const globe_of_azeroth_pos =   { -3728.24f, 1091.96f, 166.595f, 0.0f };

Position const orhanpos =               { -3668.61f, 1093.13f, 159.808f, 3.10669f };

Position const raider1pos =             { -3670.85f, 1077.79f, 160.646f, 2.67035f };
Position const raider2pos =             { -3689.59f, 1130.63f, 160.646f, 4.57276f };
Position const raider3pos =             { -3703.53f, 1135.72f, 160.646f, 4.53786f };
Position const raider4pos =             { -3678.45f, 1065.12f, 160.646f, 2.35619f };

class spell_seal_dream : public SpellScript
{
    PrepareSpellScript(spell_seal_dream);

    void HandleAfterCast()
    {
        if (Creature* portal = GetCaster()->FindNearestCreature(creature_portal_bunny, 5))
            GetCaster()->ToPlayer()->KilledMonsterCredit(creature_portal_bunny);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_seal_dream::HandleAfterCast);
    }
};

void AddSC_feralas()
{
    RegisterSpellScript(spell_seal_dream);
}

/*
 * Copyright 2023 AzgathCore
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
#include "GameObject.h"
#include "AreaTrigger.h"
#include "Log.h"
#include "auchindoun.h"


enum eKaatharSpells
{
    SpellHallowedGround = 154526,
    SpellHallowedGroundsTriggerMissile = 155646,
    SpellConsecratedLight = 153006,
    SpellConsecratedLightDamage = 156746,
    SpellHolyShieldThrow = 153002,
    SpellHolyShieldLos = 153028,
    SpellHolyShieldLosSpells = 153452,
    SpellHolyShieldAreatrigger = 153478,
    SpellHolyShieldOffHandDisarm = 174205,
    SpellHolyShieldTwoHandDisarm = 174206,
    SpellHolyShieldKnockBack = 153481,
    SpellHolyShieldDamageFromKnockBack = 153480,
    SpellHolyShieldAreaTrigger = 153478,
    SpellSanctifiedStrikeDummy = 152954,
    SpellSanctifiedGroundTickDamage = 161457,
    SpellSanctifiedGroundAura = 153430,
    SpellSanctifiedGroundDamageTick = 161457,
    SpellSanctifiedStrikeAreaTrigger = 165064,
    SpellSanctifiedStrikeAreaTrigger2 = 163559,
    SpellSancitfiedStrikeAreaTrigger3 = 165055,
    SpellSanctifiedStrikeAreaTrigger4 = 165065,
    SpellFate = 157465
};

enum eKaatharEvents
{
    EventHallowedGround = 1,
    EventHolyShield,
    EventConsecratedLight,
    EventSanctifiedStrike,
    EventHolyShieldReturn,
    EventFate,
    EventCheckPlayer,
    EventDecreaseSize
};

enum eKaatharActions
{
    ActionActivateBoss = 1,
    ActionFateHallowedGround,
    ActionDespawnCreatures
};

enum eKaatharTalks
{
    VigilantKaatherIntro = 0,   ///< None Live p_Who Assault The Holy Auchenai. (46436)
    VigilantKaatherAgro = 1,   ///< I Will Strike You Down. (46434)
    VigilantKaatherSpell1 = 20,   ///< Bathe In The Glory Of The Light! (46438)
    VigilantKaatherSpell2 = 21,   ///< The Light Guide My Hand! (46439)
    VigilantKaatherKill = 22,   ///< Light Guide You. (46434)
    VigilantKaatherDeath = 3    ///< Auchindoun...Is...Doomed...(46435)
};

enum eKaatharCreatures
{
    TriggerHallowedGround = 537324,
    TriggerHolyShield = 76071,
    TriggerFissureSummoner = 543536
};

Position const g_KaatharNewHomePosition = { 1911.47f, 3152.13f, 30.972f, 1.166194f };

enum Events
{
    // PostKaathar
    EVENT_POST_KAATHAR_1 = 2000,
    EVENT_POST_KAATHAR_2,
    EVENT_POST_KAATHAR_3,
    EVENT_NYAMI_ESCAPE_1,
    EVENT_NYAMI_ESCAPE_2,
    EVENT_NYAMI_ESCAPE_3,
    EVENT_NYAMI_ESCAPE_4,
    EVENT_NYAMI_ESCAPE_5,
    EVENT_NYAMI_ESCAPE_6,
    EVENT_NYAMI_ESCAPE_7,
    EVENT_NYAMI_ESCAPE_8,
    EVENT_NYAMI_ESCAPE_9,
    EVENT_KAATHAR_DESPAWN_CREATURES,
};

enum Phases
{
    PHASE_NORMAL,
    PHASE_INTRO
};

void AddSC_boss_kaathar()
{
   
}

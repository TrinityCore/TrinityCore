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

#include "SpellScript.h"
#include "SpellMgr.h"
#include "SpellAuraEffects.h"
#include "iron_docks.hpp"

enum eTalks
{
    /// Noxx
    TalkNoxxIntro       = 50,   ///< Is there killing to be done? Let me have 'em! (46128)
    TalkNoxxSlay        = 3,    ///< Tick.. tick.. tick.. BOOM! (46129)
    TalkNoxxDeath       = 4,    ///< I'm hit... (46127)
    TalkNoxxSpell01     = 1,    ///< Now you ain't so tall no more! (46130)
    TalkNoxxSpell02     = 2,    ///< You better step back. I'm calling in the bomb squad! (46131)
    TalkNoxxSpell03     = 5,    ///< Time is money friend, and it looks like you out of both! (46132)
    TalkMakoggIntro     = 60,   ///<  Hah! (45800)
    TalkMakoggDeath     = 61,   ///<  This.. is.. far, from over.. (45799)
    TalkMakoggSpell01   = 62,   ///<  You will burn! (45801)
    TalkKoramar07       = 29,   ///< That was an insignificant loss... let them exhaust themselves playing against our weak.. against those who're unworthy of serving in Black Hands army. That's all what Orc understand(46906)
    TalkZoggosh06       = 15   ///< Sir.. half of our army has been taken out. Don't you think we should.. (44053)
};

enum eCreatures
{
    CreatureLavaSweep           = 95353,
    CreatureOgreTrap            = 88758,
    CreatureBombsquad           = 80875
};

enum eActions
{
    ActionMakoggWinCheck = 1
};

enum eMovementInformeds
{
    MovementInformFlamingSlash = 1
};

uint32 g_Entries[3] = { eIronDocksCreatures::CreatureMakogg, eIronDocksCreatures::CreatureDuguru, eIronDocksCreatures::CreatureNox };

Position const g_Position[3] =
{
    { 6508.250f, -1127.709f, 4.958000f, 2.062029f },
    { 6512.830f, -1129.689f, 4.958000f, 2.022608f },
    { 6504.740f, -1131.180f, 4.958000f, 2.120224f }
};

void AddSC_boss_grimrail()
{
    
}

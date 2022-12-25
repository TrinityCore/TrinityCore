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
#include "tol_dagor.h"

enum Spells {
    SPELL_ARBLAST = 256199,
    SPELL_ARI = 256198,
    SPELL_CROSSIGNITION = 256083,
    SPELL_CROSSIGNITION_VISUAL = 256057,
    //for the player
    SPELL_DEADEYE = 256038,
    //Cast
    SPELL_DEADEYE_CAST = 256039,
    //Damage
    SPELL_DEADEYE_BULLET = 256044,
    SPELL_EXPLOSIVE_BURST = 256105,
    SPELL_EXPLOSIVE_BURST_DAMAGE = 256128,
    SPELL_MASSIVE_BLAST = 263345,
};

enum Events : uint32
{
    EVENT_MUNITION = 1,
    EVENT_CROSSIGNITION = 2,
    EVENT_DEADEYE = 3,
    EVENT_EXPLOSIVE_BURST = 4,
    EVENT_MASSIVE_BLAST = 5
};

void AddSC_boss_overseer_korgus()
{
    
}

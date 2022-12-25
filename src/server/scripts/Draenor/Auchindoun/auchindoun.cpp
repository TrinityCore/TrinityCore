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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "GameObject.h"
#include "auchindoun.h"

enum eEmotes
{
    EMOTE_HELLO_NYAMI = 3,
};

Position const g_PositionKaatharCrystalPosition = { 1909.75f, 3188.70f, 66.786f, 5.401960f };

enum eventTuulaniIntro
{
    EVENT_TUULANI_INTRO_1 = 3000,
    EVENT_TUULANI_INTRO_2,
    EVENT_TUULANI_INTRO_3,
    EVENT_TUULANI_INTRO_4,
    EVENT_TUULANI_INTRO_5,
    EVENT_TUULANI_INTRO_6,
    EVENT_TUULANI_INTRO_7,
    EVENT_TUULANI_INTRO_8,
    EVENT_TUULANI_INTRO_9,
    EVENT_TUULANI_INTRO_10,
    EVENT_TUULANI_INTRO_11,
    EVENT_TUULANI_INTRO_12,
    EVENT_TUULANI_INTRO_13,
    EVENT_TUULANI_INTRO_14,
    EVENT_TUULANI_INTRO_15,
    EVENT_TUULANI_INTRO_16,
    EVENT_TUULANI_INTRO_17,
    EVENT_TUULANI_INTRO_18,
    EVENT_TUULANI_INTRO_19,
};

void AddSC_auchindoun()
{
    
}

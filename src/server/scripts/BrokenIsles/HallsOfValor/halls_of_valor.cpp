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
#include "halls_of_valor.h"

enum hallsOfValorSpells
{
    SPELL_SEVER = 199652,
    SPELL_UNRULY_YELL = 199726,
    SPELL_CALL_ANCESTOR = 200969,
    SPELL_WICKED_DAGGER = 199674,
};

enum hallsOfValorEvents
{
    EVENT_SEVER,
    EVENT_UNRULY_YELL,
    EVENT_CALL_ANCESTOR,
    EVENT_WICKED_DAGGER,
};

enum hallsOfValorTalk
{
    SAY_ENTER_COMBAT = 0,
    SAY_JUST_DIED = 1,
};

void AddSC_halls_of_valor()
{
  
}

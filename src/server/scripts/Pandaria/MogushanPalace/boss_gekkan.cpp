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
#include "ScriptedCreature.h"
#include "mogu_shan_palace.h"

#define TYPE_GET_ENTOURAGE 14

enum eSpells
{
    SPELL_RECKLESS_INSPIRATION = 118988,
    SPELL_SHANK = 118963,
    SPELL_IRON_PROTECTOR = 118958,
    SPELL_CLEANSING_FLAME = 118940,
    SPELL_FIRE_BOLT = 118936,
    SPELL_HEX_OF_LETHARGY = 118903,
    SPELL_DARK_BOLT = 118917
};

enum eActions
{
    ACTION_ENTOURAGE_DIED
};

enum eEvents
{
    EVENT_RECKLESS_INSPIRATION
};

enum eTalks
{
    TALK_INTRO,
    TALK_KILLING,
    TALK_SPELL,
    TALK_AGGRO,
    TALK_DEATH
};

void AddSC_boss_gekkan()
{
   
}

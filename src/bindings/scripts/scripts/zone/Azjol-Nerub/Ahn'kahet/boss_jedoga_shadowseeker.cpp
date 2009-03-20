/*
 * Copyright (C) 2009 Trinity <http://www.trinitycore.org/>
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

/* ScriptData
SDName: boss_jedoga_shadowseeker
SD%Complete: 0
SDComment: Placeholder
SDCategory: Ahn'kahet
EndScriptData */

#include "precompiled.h"
#include "def_ahnkahet.h"

#define SPELL_CYCLONE_STRIKE                    56855
#define H_SPELL_CYCLONE_STRIKE                  60030//kein unterschied zu 56855 auﬂer das 60030 1,5sec cast ist
#define SPELL_LIGHTNING_BOLT                    56891
#define H_SPELL_LIGHTNING_BOLT                  60032
#define SPELL_THUNDERSHOCK                      56926//AOE works
#define H_SPELL_THUNDERSHOCK                    60029//AOE works

#define SPELL_GIFT_OF_THE_HERALD                56219//triggert if sucessfull sacreficed

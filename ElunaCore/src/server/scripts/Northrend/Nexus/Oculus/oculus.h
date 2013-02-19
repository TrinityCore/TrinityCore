/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DEF_OCULUS_H
#define DEF_OCULUS_H

enum Data
{
    DATA_DRAKOS_EVENT,
    DATA_VAROS_EVENT,
    DATA_UROM_EVENT,
    DATA_EREGOS_EVENT,
    DATA_UROM_PLATAFORM
};

enum Data64
{
    DATA_DRAKOS,
    DATA_VAROS,
    DATA_UROM,
    DATA_EREGOS
};

enum Bosses_NPCs
{
    NPC_DRAKOS                  = 27654,
    NPC_VAROS                   = 27447,
    NPC_UROM                    = 27655,
    NPC_EREGOS                  = 27656,

    NPC_AZURE_RING_GUARDIAN         = 28236,
    NPC_CENTRIFUGE_CONSTRUCT        = 27641,
    NPC_RUBY_DRAKE_VEHICLE          = 27756,
    NPC_EMERALD_DRAKE_VEHICLE       = 27692,
    NPC_AMBER_DRAKE_VEHICLE         = 27755,
    NPC_VERDISA                     = 27657,
    NPC_BELGARISTRASZ               = 27658,
    NPC_ETERNOS                     = 27659,
    NPC_GREATER_WHELP               = 28276
};

enum GameObjects
{
    GO_DRAGON_CAGE_DOOR                           = 193995,
    GO_EREGOS_CACHE_N                             = 191349,
    GO_EREGOS_CACHE_H                             = 193603
};

enum SpellEvents
{
    EVENT_CALL_DRAGON = 12229
};

enum CreatureActions
{
    ACTION_CALL_DRAGON_EVENT = 1
};

enum OculusWorldStates
{
    WORLD_STATE_CENTRIFUGE_CONSTRUCT_SHOW   = 3524,
    WORLD_STATE_CENTRIFUGE_CONSTRUCT_AMOUNT = 3486
};

enum OculusSpells
{
    SPELL_CENTRIFUGE_SHIELD = 50053,
    SPELL_DEATH_SPELL       = 50415
};
#endif

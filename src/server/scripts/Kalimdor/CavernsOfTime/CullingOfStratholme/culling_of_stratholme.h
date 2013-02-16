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

#ifndef _CULLING_OF_STRATHOLME_H_
#define _CULLING_OF_STRATHOLME_H_

enum Data
{
    DATA_CRATE_EVENT,
    DATA_CRATE_COUNT,
    DATA_INITIAL_RP_EVENT,
    DATA_MEATHOOK_EVENT,
    DATA_SALRAMM_EVENT,
    DATA_EPOCH_EVENT,
    DATA_MAL_GANIS_EVENT,
    DATA_INFINITE_CORRUPTOR_EVENT,
    DATA_ARTHAS_EVENT
};

enum Data64
{
    DATA_ARTHAS,
    DATA_MEATHOOK,
    DATA_SALRAMM_THE_FLESHCRAFTER,
    DATA_CHRONO_LORD_EPOCH,
    DATA_MAL_GANIS,
    DATA_INFINITE_CORRUPTOR,
    DATA_BOOKSHELF,
    DATA_MAL_GANIS_INNER_GATE,
    DATA_MAL_GANIS_OUTER_GATE,
    DATA_EXIT_GATE,
    DATA_MAL_GANIS_CHEST
};

enum Creatures
{
    NPC_MEATHOOK                   = 26529,
    NPC_SALRAMM_THE_FLESHCRAFTER   = 26530,
    NPC_CHRONO_LORD_EPOCH          = 26532,
    NPC_MAL_GANIS                  = 26533,
    NPC_INFINITE_CORRUPTOR         = 32273,
    NPC_ARTHAS                     = 26499,
    NPC_JAINA                      = 26497,
    NPC_UTHER                      = 26528,
    NPC_CHROMIE_START              = 26527,
    NPC_CHROMIE_MIDDLE             = 27915,
    NPC_TOTALLY_GENERIC_BUNNY      = 28960
};

enum GameObjects
{
    GO_BOOKSHELF_GATE              = 188686,
    GO_MAL_GANIS_INNER_GATE        = 187711,
    GO_MAL_GANIS_OUTER_GATE        = 187723,
    GO_EXIT_GATE                   = 191788,
    GO_MALGANIS_CHEST_N            = 190663,
    GO_MALGANIS_CHEST_H            = 193597,
    GO_CRATE_HIGHLIGHTER           = 190117,
    GO_SUSPICIOUS_CRATE            = 190094,
    GO_PLAGUED_CRATE               = 190095
};

enum WorldStatesCoS
{
    WORLDSTATE_SHOW_CRATES         = 3479,
    WORLDSTATE_CRATES_REVEALED     = 3480,
    WORLDSTATE_WAVE_COUNT          = 3504,
    WORLDSTATE_TIME_GUARDIAN       = 3931,
    WORLDSTATE_TIME_GUARDIAN_SHOW  = 3932
};

enum Achievements
{
    ACHIEVEMENT_THE_CULLING_OF_STRATHOLME =  479, //(Reg Version)Kill Meathook, Salramm the Fleshcrafter, Chrono-Lord Epoch and Mal'Ganis
    ACHIEVEMENT_CULLING_OF_STRATHOLME     = 1817, //(Heroic Only)Kill the Infinite Corruptor
    ACHIEVEMENT_ZOMBIEFEST                = 1872  //(Heroic Only)Kill 100 Risen Zombies in 60 seconds
};

#endif

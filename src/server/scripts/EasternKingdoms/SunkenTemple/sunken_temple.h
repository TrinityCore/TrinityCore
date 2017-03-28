/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DEF_SUNKEN_TEMPLE_H
#define DEF_SUNKEN_TEMPLE_H

#define DataHeader "ST"

enum STEvents
{
    TROLLBOSS1_DEATH  = 1,
    TROLLBOSS2_DEATH  = 2,
    TROLLBOSS3_DEATH  = 3,
    TROLLBOSS4_DEATH  = 4,
    TROLLBOSS5_DEATH  = 5,
    TROLLBOSS6_DEATH  = 6,
    JAMMALAN_DEATH    = 7,
    MORPHAZ_DEATH     = 8,
    HAZZAS_DEATH      = 9,
    ERANIKUS_DEATH    = 10,
    ATALALARION_DEATH = 11, //optional

    EVENT_STATE       = 1
};

#endif

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

#ifndef DEF_RAZORFEN_KRAUL_H
#define DEF_RAZORFEN_KRAUL_H

#include "CreatureAIImpl.h"

#define RFKScriptName "instance_razorfen_kraul"
#define DataHeader "RFK"

#define EVENT_WARD_KEEPER 1

template <class AI, class T>
inline AI* GetRazorfenKraulAI(T* obj)
{
    return GetInstanceAI<AI>(obj, RFKScriptName);
}

#endif

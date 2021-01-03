/*
 * This file is part of tswow (https://github.com/tswow/).
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 * 
 * This program is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once

#define EVENT_TYPE(name,...) typedef void (*name##Type)(__VA_ARGS__);
#define EVENT(name,...) TSEvent<name##Type> name;
#define EVENT_HANDLE(category,name) void name(category##name##Type cb) { Add(this->events->category##name.Add(cb)); }
#define MAP_EVENT_HANDLE(category,name) void name(uint32 id, category##name##Type cb) { Add(this->eventMap->Get(id)->category##name.Add(cb));}
#define FIRE(name,...) {for(size_t i=0;i< GetTSEvents()->name.GetSize(); ++i) GetTSEvents()->name.Get(i)(__VA_ARGS__);}
#define FIRE_RETURN(name,retType,retVal,...) {retType rv = retVal; for(size_t i=0;i< GetTSEvents()->name.GetSize(); ++i) GetTSEvents()->name.Get(i)(__VA_ARGS__,TSMutable<retType>(&rv)); return retVal;}
#define FIRE_MAP(obj,name,...) FIRE(name,__VA_ARGS__); {if(obj) for(size_t i=0;i< obj->name.GetSize(); ++i) obj->name.Get(i)(__VA_ARGS__);}

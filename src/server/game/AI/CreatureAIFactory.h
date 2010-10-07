/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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
#ifndef TRINITY_CREATUREAIFACTORY_H
#define TRINITY_CREATUREAIFACTORY_H

//#include "Policies/Singleton.h"
#include "ObjectRegistry.h"
#include "FactoryHolder.h"

struct SelectableAI : public FactoryHolder<CreatureAI>, public Permissible<Creature>
{
    SelectableAI(const char *id) : FactoryHolder<CreatureAI>(id) {}
};

template<class REAL_AI>
struct CreatureAIFactory : public SelectableAI
{
    CreatureAIFactory(const char *name) : SelectableAI(name) {}

    CreatureAI* Create(void *) const;

    int Permit(const Creature *c) const { return REAL_AI::Permissible(c); }
};

template<class REAL_AI>
inline CreatureAI*
CreatureAIFactory<REAL_AI>::Create(void *data) const
{
    Creature* creature = reinterpret_cast<Creature *>(data);
    return (new REAL_AI(creature));
}

typedef FactoryHolder<CreatureAI> CreatureAICreator;
typedef FactoryHolder<CreatureAI>::FactoryHolderRegistry CreatureAIRegistry;
typedef FactoryHolder<CreatureAI>::FactoryHolderRepository CreatureAIRepository;
#endif

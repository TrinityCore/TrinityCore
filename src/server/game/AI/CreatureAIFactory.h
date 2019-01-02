/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "ObjectRegistry.h"
#include "SelectableAI.h"

class Creature;
class CreatureAI;

template <class REAL_AI, bool is_db_allowed = true>
struct CreatureAIFactory : public SelectableAI<Creature, CreatureAI, is_db_allowed>
{
    CreatureAIFactory(std::string const& name) : SelectableAI<Creature, CreatureAI, is_db_allowed>(name) { }

    inline CreatureAI* Create(Creature* c) const override
    {
        return new REAL_AI(c);
    }

    int32 Permit(Creature const* c) const override
    {
        return REAL_AI::Permissible(c);
    }
};

typedef SelectableAI<Creature, CreatureAI>::FactoryHolderRegistry CreatureAIRegistry;

#define sCreatureAIRegistry CreatureAIRegistry::instance()

#endif

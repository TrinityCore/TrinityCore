/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef AIWORLD_AGENTTYPECATALOG_H
#define AIWORLD_AGENTTYPECATALOG_H

#include "AgentType.h"
#include "Define.h"
#include <unordered_map>

// AgentType identity fix (AIWorld_Current_Roadmap.md, Etapa 3): loads
// world.ai_agent_type_entry_defaults once at AIWorldMgr::Initialize() into
// an in-memory CreatureEntry -> AgentType map - the same shape and
// lifecycle as WorldFactionCatalog (Faction/WorldFactionCatalog.h), and the
// direct replacement for the old npcflag-only DeriveCreatureAgentType()
// heuristic (Reconciliation/AgentTypeProvenance.h, retired): a hard-coded
// C++ heuristic could only ever detect the vendor npcflag bit, never tell a
// Guard from a Combatant from a Civilian. That table is itself generated
// from data/elwynn/census/template_classification.csv's own
// primary_category column (see tools/elwynn/build_agent_type_defaults.py)
// - this class never reads the CSV directly, only the world DB table it
// was used to populate.
//
// Read-only after Load(): AIWorldMgr::BuildReconciliationPlan()'s own
// caller (RunSpawnReconciliation()) is the only thing that calls Resolve(),
// once per eligible CreatureSpawnIdentity - never a per-spawn world DB
// query.
class TC_GAME_API AgentTypeCatalog
{
    public:
        // Replaces any previously loaded content. Startup-only, synchronous
        // (CONNECTION_SYNCH) - the same pattern WorldFactionCatalog::Load()
        // already uses, never called from the world update loop.
        void Load();

        // A CreatureEntry absent from the table - never classified by the
        // Elwynn census, or explicitly outside its scope - resolves to
        // AgentType::Unclassified. Fail-closed: this never guesses a role
        // for an entry it has no explicit data for, the same discipline
        // DeriveCreatureAgentType() itself used to apply and
        // WorldFactionCatalog::Resolve() still does for WorldFactionId.
        AgentType Resolve(uint32 creatureEntry) const;

    private:
        std::unordered_map<uint32, AgentType> _entryToAgentType;
};

#endif // AIWORLD_AGENTTYPECATALOG_H

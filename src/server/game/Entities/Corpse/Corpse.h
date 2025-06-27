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

#ifndef TRINITYCORE_CORPSE_H
#define TRINITYCORE_CORPSE_H

#include "Object.h"
#include "GridObject.h"
#include "DatabaseEnvFwd.h"
#include "GridDefines.h"
#include "Loot.h"

enum CorpseType
{
    CORPSE_BONES             = 0,
    CORPSE_RESURRECTABLE_PVE = 1,
    CORPSE_RESURRECTABLE_PVP = 2
};
#define MAX_CORPSE_TYPE        3

// Value equal client resurrection dialog show radius.
#define CORPSE_RECLAIM_RADIUS 39

enum CorpseFlags
{
    CORPSE_FLAG_NONE        = 0x00,
    CORPSE_FLAG_BONES       = 0x01,
    CORPSE_FLAG_UNK1        = 0x02,
    CORPSE_FLAG_UNK2        = 0x04,
    CORPSE_FLAG_HIDE_HELM   = 0x08,
    CORPSE_FLAG_HIDE_CLOAK  = 0x10,
    CORPSE_FLAG_LOOTABLE    = 0x20
};

class TC_GAME_API Corpse : public WorldObject, public GridObject<Corpse>
{
    public:
        explicit Corpse(CorpseType type = CORPSE_BONES);
        ~Corpse();

        void AddToWorld() override;
        void RemoveFromWorld() override;

        bool Create(ObjectGuid::LowType guidlow);
        bool Create(ObjectGuid::LowType guidlow, Player* owner);

        void SaveToDB();
        bool LoadCorpseFromDB(ObjectGuid::LowType guid, Field* fields);

        void DeleteFromDB(CharacterDatabaseTransaction trans);
        static void DeleteFromDB(ObjectGuid const& ownerGuid, CharacterDatabaseTransaction trans);

        ObjectGuid GetOwnerGUID() const override { return GetGuidValue(CORPSE_FIELD_OWNER); }
        uint32 GetFaction() const override;

        time_t const& GetGhostTime() const { return m_time; }
        void ResetGhostTime();
        CorpseType GetType() const { return m_type; }

        CellCoord const& GetCellCoord() const { return _cellCoord; }
        void SetCellCoord(CellCoord const& cellCoord) { _cellCoord = cellCoord; }

        Loot loot;                                          // remove insignia ONLY at BG
        Player* lootRecipient;

        bool IsExpired(time_t t) const;

    private:
        CorpseType m_type;
        time_t m_time;
        CellCoord _cellCoord;
};
#endif

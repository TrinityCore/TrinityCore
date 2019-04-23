/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#ifndef _ARCHAEOLOGY_MGR_H
#define _ARCHAEOLOGY_MGR_H

#include "DBCEnums.h"
#include "DB2Stores.h"
#include "Player.h"

class Player;

class ArchaeologyMgr
{
    private:
        ArchaeologyMgr();
        ~ArchaeologyMgr();

    public:

    static ArchaeologyMgr* instance()
    {
        static ArchaeologyMgr instance;
        return &instance;
    }

    struct ResearchDigsitesEntry
    {
        uint16 id;
        uint16 mapId;
        uint8 minLevel;
        uint16 minSkillLevel;
        uint16 currencyId;
        uint16 QuestPoitBlobId;
    };

    public:
        void LoadDigsites();
        void InitBranch(Player* player, uint32 currencyId);
        void ChangeDigsite(Player* player, uint8 memId);
        void AddDigsitesToMap(Player* player, uint32 mapId);
        bool IsActiveBranch(Player* player, uint32 currencyId);
        void GenerateRandomPosition(Player* player, uint8 count);
        int GetCurrencyId(uint16 digsiteId);
        int GetArtifactSkillReqLevel(uint32 spellId);

    private:
        typedef std::unordered_map<uint16, ResearchDigsitesEntry> DigsitesMap;
        DigsitesMap mResearchDigsitesMap;
};

#define sArchaeologyMgr ArchaeologyMgr::instance()

#endif

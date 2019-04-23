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

#ifndef _ARCHAEOLOGY_PLAYER_MGR_H
#define _ARCHAEOLOGY_PLAYER_MGR_H

class Player;

struct Digsite
{
    uint8     memId;       // Posicion en memoria
    uint16    digsiteId;   // Id del digsite
    float     x;           // Coordenada X
    float     y;           // Coordenada Y
    uint8     digCount;    // Contador de exploraciones
};

struct ArchaeologyArtifactCost
{
    uint32 kcount;
    uint32 kentry;
    uint32 fcount;
    uint32 fentry;
};

typedef std::unordered_map<uint32, Digsite> DigsiteMap;

struct ArchaeologyHistory
{
    uint32 time;
    uint32 count;
};

typedef std::unordered_map<uint32, ArchaeologyHistory> ArchaeologyHistoryMap;

class ArchaeologyPlayerMgr
{
public:
    ArchaeologyPlayerMgr(Player* player);

    Player* GetPlayer() { return m_player; }

    void LoadArchaeologyDigSites(PreparedQueryResult result);
    void LoadArchaeologyBranchs(PreparedQueryResult result);
    void LoadArchaeologyHistory(PreparedQueryResult result);
    void SaveArchaeologyDigSites(SQLTransaction& trans);
    void SaveArchaeologyBranchs(SQLTransaction& trans);
    void SaveArchaeologyHistory(SQLTransaction& trans);

    ArchaeologyHistoryMap& GetHistory() { return m_ArchaeologyHistoryMap; }

    Digsite GetDigsitePosition(uint8 memId);
    void SetDigsitePosition(uint8 memId, float x, float y, uint8 digCount);
    void SetDigsiteId(uint8 memId, uint16 digsiteId);
    std::vector<std::pair<int32, int32>> DigsitePolygon;
    int GetDigsite(int32 x, int32 y);
    bool IsCurrentArtifactSpell(int32 spellId);
    void CompleteArtifact(uint32 spellId);
    bool IsFirstProjectComplete(uint32 artifactId);
    ArchaeologyArtifactCost* _artifactCost;

private:
    Player* m_player;
    DigsiteMap m_DigsiteMap;
    ArchaeologyHistoryMap m_ArchaeologyHistoryMap;
};

#endif

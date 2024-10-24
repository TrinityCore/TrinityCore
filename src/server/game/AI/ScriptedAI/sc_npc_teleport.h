/*
 * Copyright (C) 20??-2008 Wilibald09
 * Copyright (C) 2011-2015 ArkCORE <http://www.arkania.net/>
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef SC_NPC_TELEPORT_H
#define SC_NPC_TELEPORT_H
#include "DatabaseEnvFwd.h"
#include <vector>

namespace nsNpcTel
{
    // Different types of permissions
    enum Flag
    {
        FLAG_TEAM       = 0,
        FLAG_GUILD      = 1,
        FLAG_GMLEVEL    = 2,
        FLAG_ISGM       = 3,
        FLAG_ACCOUNT    = 4,
        FLAG_LEVEL      = 5,
        FLAG_ITEM       = 6,
        FLAG_QUEST      = 7,
        FLAG_GENDER     = 8,
        FLAG_RACE       = 9,
        FLAG_CLASS      = 10,
        FLAG_REPUTATION = 11,
        FLAG_PLAYER     = 12,
        MAX_FLAG,
    };

    // Different parameters of FLAG_TEAM
    enum
    {
        TEAM_ALL        = 0,
        TEAM_ALLIANCE   = 1,
        TEAM_HORDE      = 2,
        MAX_FLAG_TEAM,
    };

    // Structure representing the destinations
    struct Dest
    {
        std::string m_icon;
        std::string m_size;
        std::string m_colour;
        std::string m_name[9];
        float       m_X, m_Y, m_Z, m_orient;
        uint16      m_map;
        uint8       m_level;
        uint32      m_cost;
    };

    struct CatValue
    {
        uint32 catid;
        nsNpcTel::Flag flag;
        uint64 data0;
        uint32 data1;
    };

    struct CatName
    {
        std::string icon;
        std::string size;
        std::string colour;
        std::string name[9];
    };

    // Class representing the categories of destinations
    class TC_GAME_API CatDest
    {
    public:

        typedef std::vector<Dest> VDest;
        typedef VDest::size_type  VDest_t;

        CatDest(const CatValue cat, const CatName catname);

        void   AddDest(const Dest &item)       { m_TabDest.push_back(item); }
        Dest   GetDest(const uint32 &id) const { return m_TabDest[id]; }
        uint32 GetCatID(void)             const { return m_catvalue.catid; }
        uint32 size(void)             const { return m_TabDest.size(); }

        std::string GetName(const uint8 loc /* = 0 */, const bool IsGM = false)    const;
        bool IsAllowedToTeleport(Player * const player) const;

        static uint32 CountOfCategoryAllowedBy(Player * const player);

    private:

        CatValue m_catvalue;
        CatName m_catname;
        VDest       m_TabDest;
    };

    // Class page for current player
    class TC_GAME_API Page
    {
      protected:

        // Class instance for current player
        class TC_GAME_API Instance
        {
          public:

            Instance(Player * const player, const uint32 &PageId = 0)
                : m_player(player), m_PageId(PageId) {}

            Instance & operator =  (const uint32 &id);
            Instance & operator ++ (void);
            Instance   operator ++ (int32);
            Instance & operator -- (void);
            Instance   operator -- (int32);

            uint32   GetPageId(void) const { return m_PageId; }
            Player * GetPlayer(void) const { return m_player; }

          private:

            Player *m_player;
            uint32  m_PageId;
        };

      public:

        typedef std::vector<Instance> VInst;
        typedef VInst::size_type      VInst_t;

        Page(void) { m_TabInstance.clear(); }

        Instance &   operator () (Player * const player);
        uint32 operator [] (Player * const player) const;

      private:

        VInst m_TabInstance;
    };

    typedef std::vector <CatDest> VCatDest;
    typedef VCatDest::size_type   VCatDest_t;

    // Verification of data integrity
    bool IsValidData(const CatValue cat);

    extern TC_GAME_API VCatDest TabCatDest;
}

// Loading contents of database
void TC_GAME_API LoadNpcTele(void);

//extern WorldDatabaseWorkerPool WorldDatabase;

#endif

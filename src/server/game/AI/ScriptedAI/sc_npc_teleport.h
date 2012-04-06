/**
 *
 * @File : sc_npc_teleport.h
 *
 * @Authors : Wilibald09
 *
 * @Date : 19/08/2008
 *
 * @Version : 1.2
 *
 **/


#ifndef SC_NPC_TELEPORT_H
#define SC_NPC_TELEPORT_H

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
        std::string m_name;
        float       m_X, m_Y, m_Z, m_orient;
        uint16      m_map;
        uint8       m_level;
        uint32      m_cost;
    };

    // Class representing the categories of destinations
    class CatDest
    {
      public:

        typedef std::vector<Dest> VDest;
        typedef VDest::size_type  VDest_t;

        CatDest(const uint32 &id, const std::string &name,
                const Flag &flag, const uint64 &data0, const uint32 &data1);

        void   AddDest  (const Dest &item)       { m_TabDest.push_back(item); }
        Dest   GetDest  (const uint32 &id) const { return m_TabDest[id]; }
        uint32 GetCatID (void)             const { return m_id; }
        uint32 size     (void)             const { return m_TabDest.size(); }

        std::string GetName(const bool IsGM = false)    const;
        bool IsAllowedToTeleport(Player * const player) const;

        static uint32 CountOfCategoryAllowedBy(Player * const player);

      private:

        uint32      m_id;
        std::string m_name;
        Flag        m_flag;
        uint64      m_data0;
        uint32      m_data1;
        VDest       m_TabDest;
    };

    // Class page for current player
    class Page
    {
      protected:

        // Class instance for current player
        class Instance
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
    bool IsValidData(const uint32 &cat,   const Flag &flag,
                     const uint64 &data0, const uint32 &data1);

    extern VCatDest TabCatDest;
}

// Loading contents of database
void LoadNpcTele(void);

extern WorldDatabaseWorkerPool WorldDatabase;

#endif

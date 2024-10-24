#ifndef BOTWANDERFUL_H_
#define BOTWANDERFUL_H_

#include "Position.h"

#include <functional>
#include <list>
#include <shared_mutex>
#include <mutex>
#include <unordered_map>

/*
NpcBot System by Trickerer (onlysuffering@gmail.com)
Original patch from: LordPsyan https://bitbucket.org/lordpsyan/trinitycore-patches/src/3b8b9072280e/Individual/11185-BOTS-NPCBots.patch
*/

class Creature;

enum class BotWPFlags : uint32
{
    BOTWP_FLAG_NONE                     = 0x00000000,
    BOTWP_FLAG_SPAWN                    = 0x00000001, // wandering bots can spawn at this WP location
    BOTWP_FLAG_ALLIANCE_ONLY            = 0x00000002, // only alliance bots can move here, SPAWN+A = only alliance bots can spawn at this WP location
    BOTWP_FLAG_HORDE_ONLY               = 0x00000004, // only horde bots can move here, SPAWN+H = only horde bots can spawn at this WP location
    BOTWP_FLAG_CAN_BACKTRACK_FROM       = 0x00000008, // can move back to WPs links even if other links exist
    BOTWP_FLAG_MOVEMENT_IGNORES_FACTION = 0x00000010, // ignore faction flags when trying to select this WP as move point
    BOTWP_FLAG_MOVEMENT_IGNORES_PATHING = 0x00000020, // do not generate path between 2 WPs having this flag
    BOTWP_FLAG_BG_FLAG_DELIVER_TARGET   = 0x00000040, // <BG only> flag carrier destination marker
    BOTWP_FLAG_BG_FLAG_PICKUP_TARGET    = 0x00000080, // <BG only> flag pick/activate up marker
    BOTWP_FLAG_BG_BOSS_ROOM             = 0x00000100, // <BG only> boss room to attack as group / defend
    BOTWP_FLAG_BG_MISC_OBJECTIVE_1      = 0x00000200, // <BG only> misc objective 1 (AV = mine)
    BOTWP_FLAG_END                      = 0x00000400,

    BOTWP_FLAG_ALLIANCE_OR_HORDE_ONLY   = BOTWP_FLAG_ALLIANCE_ONLY | BOTWP_FLAG_HORDE_ONLY,
    BOTWP_FLAG_ALLIANCE_BOSS_ROOM       = BOTWP_FLAG_ALLIANCE_ONLY | BOTWP_FLAG_BG_BOSS_ROOM,
    BOTWP_FLAG_HORDE_BOSS_ROOM          = BOTWP_FLAG_HORDE_ONLY | BOTWP_FLAG_BG_BOSS_ROOM
};

class WanderNode : public Position
{
    using node_ltype = std::list<WanderNode*>;
    using node_ltype_c = std::list<WanderNode const*>;
    using node_mtype = std::unordered_map<uint32, node_ltype>;

    using node_proc_ftype = std::function<void(WanderNode*)>;
    using node_proc_ftype_c = std::function<void(WanderNode const*)>;
    using node_check_ftype_c = std::function<bool(WanderNode const*)>;

    using mutex_type = std::recursive_mutex;
    using lock_type = std::unique_lock<mutex_type>;

    static node_ltype ALL_WPS;
    static node_mtype ALL_WPS_PER_MAP;
    static node_mtype ALL_WPS_PER_ZONE;
    static node_mtype ALL_WPS_PER_AREA;

    template<class T, typename = void>
    struct is_container : std::false_type {};
    template<class T>
    struct is_container<T, std::void_t<decltype(std::declval<typename T::const_iterator>()), decltype(std::declval<T>().size())>> : std::true_type {};
    template<class T>
    static constexpr bool is_container_v = is_container<T>::value;

public:
    static uint32 nextWPId;

    static mutex_type* GetLock();

    static bool IsWP(Creature const* creature);
    static WanderNode* FindInAllWPs(uint32 wpId);
    static WanderNode* FindInAllWPs(Creature const* creature);
    static WanderNode* FindInMapWPs(uint32 mapId, Creature const* creature);
    static WanderNode* FindInMapWPs(uint32 mapId, uint32 wpId);
    static WanderNode* FindInMapWPs(uint32 mapId, node_check_ftype_c const& pred);
    static WanderNode* FindInZoneWPs(uint32 zoneId, node_check_ftype_c const& pred);
    static WanderNode* FindInAreaWPs(uint32 areaId, node_check_ftype_c const& pred);

    template<typename Container, typename Func>
    static void DoForContainerWPs(Container const& c, Func&& func) {
        static_assert(WanderNode::is_container_v<Container>);
        static_assert(std::is_same_v<std::decay_t<std::remove_pointer_t<typename Container::value_type>>, WanderNode>);
        static_assert(std::is_convertible_v<Func, node_proc_ftype>);
        //lock_type lock(*GetLock());
        for (auto* wp : c)
            func(wp);
    }

    static void DoForAllWPs(node_proc_ftype&& func);
    static void DoForAllMapWPs(uint32 mapId, node_proc_ftype_c&& func);
    static void DoForAllZoneWPs(uint32 zoneId, node_proc_ftype_c&& func);
    static void DoForAllAreaWPs(uint32 areaId, node_proc_ftype_c&& func);
    static size_t GetAllWPsCount();
    static size_t GetMapWPsCount(uint32 mapId);
    static size_t GetWPMapsCount();

    WanderNode(uint32 wpId, uint32 mapId, float x, float y, float z, float o, uint32 zoneId, uint32 areaId, std::string const& name);
    ~WanderNode();

    static void RemoveAllWPs();
    static void RemoveWP(WanderNode* wp);

    //utils
    WanderNode::node_ltype_c GetShortestPathLinks(WanderNode const* target, WanderNode::node_ltype_c const& base_links) const;

    //base
    void SetCreature(Creature* creature);
    Creature* GetCreature() const;

    std::string FormatLinks() const;

    void Link(WanderNode* wp, bool oneway = false) {
        if (!HasLink(wp)) {
            _links.push_back(wp);
            if (!oneway)
                wp->Link(this);
        }
    }
    void UnLink(WanderNode* wp) {
        if (HasLink(wp)) {
            _links.remove(wp);
            wp->UnLink(this);
        }
    }
    bool HasLink(WanderNode const* wp) const {
        return std::find(_links.cbegin(), _links.cend(), wp) != _links.cend();
    }
    auto GetLinks() const -> typename std::add_const_t<WanderNode::node_ltype>& {
        return _links;
    }

    void SetLevels(std::pair<uint8, uint8> levels) {
        std::tie(_minLevel, _maxLevel) = levels;
    }
    inline void SetLevels(uint8 minLevel, uint8 maxLevel) {
        SetLevels(std::pair{ minLevel, maxLevel });
    }

    void SetFlags(BotWPFlags flags);
    void RemoveFlags(BotWPFlags flags);
    bool HasFlag(BotWPFlags flags) const;

    void SetName(std::string const& name) { _name = name; }

    std::string ToString() const;

    uint32 GetWPId() const { return _wpId; }
    uint32 GetMapId() const { return _mapId; }
    uint32 GetZoneId() const { return _zoneId; }
    uint32 GetAreaId() const { return _areaId; }
    std::string const& GetName() const { return _name; }
    std::pair<uint8, uint8> GetLevels() const { return { _minLevel, _maxLevel }; }
    uint32 GetFlags() const { return _flags; }

private:
    const uint32 _wpId;
    const uint32 _mapId;
    const uint32 _zoneId;
    const uint32 _areaId;
    /*const*/ std::string _name;
    uint8 _minLevel;
    uint8 _maxLevel;
    uint32 _flags;

    node_ltype _links;

    Creature* _creature;
};

#endif //BOTWANDERFUL_H_

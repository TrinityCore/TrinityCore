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

#ifndef TRINITY_GRIDNOTIFIERS_H
#define TRINITY_GRIDNOTIFIERS_H

#include "Creature.h"
#include "Corpse.h"
#include "CreatureAI.h"
#include "DynamicObject.h"
#include "GameObject.h"
#include "Group.h"
#include "Player.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "UnitAI.h"
#include "UpdateData.h"

namespace Trinity
{
    template<typename ObjectType>
    struct GridMapTypeMaskForType : std::integral_constant<GridMapTypeMask, GridMapTypeMask(0)> { };

    template<> struct GridMapTypeMaskForType<Corpse> : std::integral_constant<GridMapTypeMask, GRID_MAP_TYPE_MASK_CORPSE> { };
    template<> struct GridMapTypeMaskForType<Creature> : std::integral_constant<GridMapTypeMask, GRID_MAP_TYPE_MASK_CREATURE> { };
    template<> struct GridMapTypeMaskForType<DynamicObject> : std::integral_constant<GridMapTypeMask, GRID_MAP_TYPE_MASK_DYNAMICOBJECT> { };
    template<> struct GridMapTypeMaskForType<GameObject> : std::integral_constant<GridMapTypeMask, GRID_MAP_TYPE_MASK_GAMEOBJECT> { };
    template<> struct GridMapTypeMaskForType<Player> : std::integral_constant<GridMapTypeMask, GRID_MAP_TYPE_MASK_PLAYER> { };

    struct TC_GAME_API VisibleNotifier
    {
        Player &i_player;
        UpdateData i_data;
        std::set<Unit*> i_visibleNow;
        GuidUnorderedSet vis_guids;

        VisibleNotifier(Player &player) : i_player(player), vis_guids(player.m_clientGUIDs) { }
        template<class T> void Visit(GridRefManager<T> &m);
        void SendToSelf(void);
    };

    struct VisibleChangesNotifier
    {
        WorldObject &i_object;

        explicit VisibleChangesNotifier(WorldObject &object) : i_object(object) { }
        template<class T> void Visit(GridRefManager<T> &) { }
        void Visit(PlayerMapType &);
        void Visit(CreatureMapType &);
        void Visit(DynamicObjectMapType &);
    };

    struct TC_GAME_API PlayerRelocationNotifier : public VisibleNotifier
    {
        PlayerRelocationNotifier(Player &player) : VisibleNotifier(player) { }

        template<class T> void Visit(GridRefManager<T> &m) { VisibleNotifier::Visit(m); }
        void Visit(CreatureMapType &);
        void Visit(PlayerMapType &);
    };

    struct TC_GAME_API CreatureRelocationNotifier
    {
        Creature &i_creature;
        CreatureRelocationNotifier(Creature &c) : i_creature(c) { }
        template<class T> void Visit(GridRefManager<T> &) { }
        void Visit(CreatureMapType &);
        void Visit(PlayerMapType &);
    };

    struct TC_GAME_API DelayedUnitRelocation
    {
        Map &i_map;
        Cell &cell;
        CellCoord &p;
        const float i_radius;
        DelayedUnitRelocation(Cell &c, CellCoord &pair, Map &map, float radius) :
            i_map(map), cell(c), p(pair), i_radius(radius) { }
        template<class T> void Visit(GridRefManager<T> &) { }
        void Visit(CreatureMapType &);
        void Visit(PlayerMapType   &);
    };

    struct TC_GAME_API AIRelocationNotifier
    {
        Unit &i_unit;
        bool isCreature;
        explicit AIRelocationNotifier(Unit &unit) : i_unit(unit), isCreature(unit.GetTypeId() == TYPEID_UNIT)  { }
        template<class T> void Visit(GridRefManager<T> &) { }
        void Visit(CreatureMapType &);
    };

    struct GridUpdater
    {
        GridType &i_grid;
        uint32 i_timeDiff;
        GridUpdater(GridType &grid, uint32 diff) : i_grid(grid), i_timeDiff(diff) { }

        template<class T> void updateObjects(GridRefManager<T> &m)
        {
            for (typename GridRefManager<T>::iterator iter = m.begin(); iter != m.end(); ++iter)
                iter->GetSource()->Update(i_timeDiff);
        }

        void Visit(PlayerMapType &m) { updateObjects<Player>(m); }
        void Visit(CreatureMapType &m){ updateObjects<Creature>(m); }
        void Visit(GameObjectMapType &m) { updateObjects<GameObject>(m); }
        void Visit(DynamicObjectMapType &m) { updateObjects<DynamicObject>(m); }
        void Visit(CorpseMapType &m) { updateObjects<Corpse>(m); }
    };

    struct TC_GAME_API MessageDistDeliverer
    {
        WorldObject const* i_source;
        WorldPacket const* i_message;
        uint32 i_phaseMask;
        float i_distSq;
        uint32 team;
        Player const* skipped_receiver;
        bool required3dDist;
        MessageDistDeliverer(WorldObject const* src, WorldPacket const* msg, float dist, bool own_team_only = false, Player const* skipped = nullptr, bool req3dDist = false)
            : i_source(src), i_message(msg), i_phaseMask(src->GetPhaseMask()), i_distSq(dist * dist)
            , team(0)
            , skipped_receiver(skipped)
            , required3dDist(req3dDist)
        {
            if (own_team_only)
                if (Player const* player = src->ToPlayer())
                    team = player->GetTeam();
        }

        void Visit(PlayerMapType &m);
        void Visit(CreatureMapType &m);
        void Visit(DynamicObjectMapType &m);
        template<class SKIP> void Visit(GridRefManager<SKIP> &) { }

        void SendPacket(Player* player)
        {
            // never send packet to self
            if (player == i_source || (team && player->GetTeam() != team) || skipped_receiver == player)
                return;

            if (!player->HaveAtClient(i_source))
                return;

            player->SendDirectMessage(i_message);
        }
    };

    struct TC_GAME_API MessageDistDelivererToHostile
    {
        Unit* i_source;
        WorldPacket const* i_message;
        uint32 i_phaseMask;
        float i_distSq;

        MessageDistDelivererToHostile(Unit* src, WorldPacket const* msg, float dist)
            : i_source(src), i_message(msg), i_phaseMask(src->GetPhaseMask()), i_distSq(dist * dist)
        {
        }

        void Visit(PlayerMapType &m);
        void Visit(CreatureMapType &m);
        void Visit(DynamicObjectMapType &m);
        template<class SKIP> void Visit(GridRefManager<SKIP> &) { }

        void SendPacket(Player* player)
        {
            // never send packet to self
            if (player == i_source || !player->HaveAtClient(i_source) || player->IsFriendlyTo(i_source))
                return;

            player->SendDirectMessage(i_message);
        }
    };

    struct ObjectUpdater
    {
        uint32 i_timeDiff;
        explicit ObjectUpdater(const uint32 diff) : i_timeDiff(diff) { }
        template<class T> void Visit(GridRefManager<T> &m);
        void Visit(PlayerMapType &) { }
        void Visit(CorpseMapType &) { }
    };

    // SEARCHERS & LIST SEARCHERS & WORKERS

    // WorldObject searchers & workers
    enum class WorldObjectSearcherContinuation
    {
        Continue,
        Return
    };

    template<typename Type>
    class SearcherFirstObjectResult
    {
        Type& result;

    protected:
        explicit SearcherFirstObjectResult(Type& ref_) : result(ref_) { }

        WorldObjectSearcherContinuation ShouldContinue() const
        {
            return result ? WorldObjectSearcherContinuation::Return : WorldObjectSearcherContinuation::Continue;
        }

        void Insert(Type object)
        {
            result = object;
        }
    };

    template<typename Type>
    class SearcherLastObjectResult
    {
        Type& result;

    protected:
        explicit SearcherLastObjectResult(Type& ref_) : result(ref_) { }

        WorldObjectSearcherContinuation ShouldContinue() const
        {
            return WorldObjectSearcherContinuation::Continue;
        }

        void Insert(Type object)
        {
            result = object;
        }
    };

    // Generic base class to insert elements into arbitrary containers using push_back
    template<typename Type>
    class SearcherContainerResult
    {
        using InserterType = void(*)(void*, Type&&);

        void* ref;
        InserterType inserter;

    protected:
        template<typename T>
        explicit SearcherContainerResult(T& ref_) : ref(&ref_)
        {
            inserter = [](void* containerRaw, Type&& object)
            {
                T* container = reinterpret_cast<T*>(containerRaw);
                container->insert(container->end(), std::move(object));
            };
        }

        WorldObjectSearcherContinuation ShouldContinue() const
        {
            return WorldObjectSearcherContinuation::Continue;
        }

        void Insert(Type object)
        {
            inserter(ref, std::move(object));
        }
    };

    template<class Check, class Result>
    struct WorldObjectSearcherBase : Result
    {
        uint32 i_mapTypeMask;
        uint32 i_phaseMask;
        Check& i_check;

        template<typename Container>
        WorldObjectSearcherBase(uint32 phaseMask, Container& result, Check& check, uint32 mapTypeMask = GRID_MAP_TYPE_MASK_ALL)
            : Result(result), i_mapTypeMask(mapTypeMask), i_phaseMask(phaseMask), i_check(check) { }

        template<class T>
        void Visit(GridRefManager<T>&);
    };

    template<class Check>
    struct WorldObjectSearcher : WorldObjectSearcherBase<Check, SearcherFirstObjectResult<WorldObject*>>
    {
        WorldObjectSearcher(WorldObject const* searcher, WorldObject*& result, Check& check, uint32 mapTypeMask = GRID_MAP_TYPE_MASK_ALL)
            : WorldObjectSearcherBase<Check, SearcherFirstObjectResult<WorldObject*>>(searcher->GetPhaseMask(), result, check, mapTypeMask) { }
    };

    template<class Check>
    struct WorldObjectLastSearcher : WorldObjectSearcherBase<Check, SearcherLastObjectResult<WorldObject*>>
    {
        WorldObjectLastSearcher(WorldObject const* searcher, WorldObject*& result, Check& check, uint32 mapTypeMask = GRID_MAP_TYPE_MASK_ALL)
            : WorldObjectSearcherBase<Check, SearcherLastObjectResult<WorldObject*>>(searcher->GetPhaseMask(), result, check, mapTypeMask) { }
    };

    template<class Check>
    struct WorldObjectListSearcher : WorldObjectSearcherBase<Check, SearcherContainerResult<WorldObject*>>
    {
        template<typename Container>
        WorldObjectListSearcher(WorldObject const* searcher, Container& container, Check& check, uint32 mapTypeMask = GRID_MAP_TYPE_MASK_ALL)
            : WorldObjectSearcherBase<Check, SearcherContainerResult<WorldObject*>>(searcher->GetPhaseMask(), container, check, mapTypeMask) { }
    };

    template<class Do>
    struct WorldObjectWorker
    {
        uint32 i_mapTypeMask;
        uint32 i_phaseMask;
        Do const& i_do;

        WorldObjectWorker(WorldObject const* searcher, Do const& _do, uint32 mapTypeMask = GRID_MAP_TYPE_MASK_ALL)
            : i_mapTypeMask(mapTypeMask), i_phaseMask(searcher->GetPhaseMask()), i_do(_do) { }

        template<class T>
        void Visit(GridRefManager<T>& m)
        {
            if (!(i_mapTypeMask & GridMapTypeMaskForType<T>::value))
                return;
            for (auto itr = m.begin(); itr != m.end(); ++itr)
                if (itr->GetSource()->InSamePhase(i_phaseMask))
                    i_do(itr->GetSource());
        }
    };

    // Gameobject searchers

    template<class Check, class Result>
    struct GameObjectSearcherBase : Result
    {
        uint32 i_phaseMask;
        Check &i_check;

        template<typename Container>
        GameObjectSearcherBase(uint32 phaseMask, Container& result, Check& check)
            : Result(result), i_phaseMask(phaseMask), i_check(check) { }

        void Visit(GameObjectMapType& m);

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }
    };

    template<class Check>
    struct GameObjectSearcher : GameObjectSearcherBase<Check, SearcherFirstObjectResult<GameObject*>>
    {
        GameObjectSearcher(WorldObject const* searcher, GameObject*& result, Check& check)
            : GameObjectSearcherBase<Check, SearcherFirstObjectResult<GameObject*>>(searcher->GetPhaseMask(), result, check) { }
    };

    // Last accepted by Check GO if any (Check can change requirements at each call)
    template<class Check>
    struct GameObjectLastSearcher : GameObjectSearcherBase<Check, SearcherLastObjectResult<GameObject*>>
    {
        GameObjectLastSearcher(WorldObject const* searcher, GameObject*& result, Check& check)
            : GameObjectSearcherBase<Check, SearcherLastObjectResult<GameObject*>>(searcher->GetPhaseMask(), result, check) { }
    };

    template<class Check>
    struct GameObjectListSearcher : GameObjectSearcherBase<Check, SearcherContainerResult<GameObject*>>
    {
        template<typename Container>
        GameObjectListSearcher(WorldObject const* searcher, Container& container, Check& check)
            : GameObjectSearcherBase<Check, SearcherContainerResult<GameObject*>>(searcher->GetPhaseMask(), container, check) { }
    };

    template<class Functor>
    struct GameObjectWorker
    {
        GameObjectWorker(WorldObject const* searcher, Functor& func)
            : _func(func), _phaseMask(searcher->GetPhaseMask()) { }

        void Visit(GameObjectMapType& m)
        {
            for (GameObjectMapType::iterator itr = m.begin(); itr != m.end(); ++itr)
                if (itr->GetSource()->InSamePhase(_phaseMask))
                    _func(itr->GetSource());
        }

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }

    private:
        Functor& _func;
        uint32 _phaseMask;
    };

    // Unit searchers

    template<class Check, class Result>
    struct UnitSearcherBase : Result
    {
        uint32 i_phaseMask;
        Check& i_check;

        template<typename Container>
        UnitSearcherBase(uint32 phaseMask, Container& result, Check& check)
            : Result(result), i_phaseMask(phaseMask), i_check(check) { }

        void Visit(CreatureMapType& m) { VisitImpl(m); }
        void Visit(PlayerMapType& m) { VisitImpl(m); }

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED>&) { }

    private:
        template<class T> void VisitImpl(GridRefManager<T>& m);
    };

    // First accepted by Check Unit if any
    template<class Check>
    struct UnitSearcher : UnitSearcherBase<Check, SearcherFirstObjectResult<Unit*>>
    {
        UnitSearcher(WorldObject const* searcher, Unit*& result, Check& check)
            : UnitSearcherBase<Check, SearcherFirstObjectResult<Unit*>>(searcher->GetPhaseMask(), result, check) { }
    };

    // Last accepted by Check Unit if any (Check can change requirements at each call)
    template<class Check>
    struct UnitLastSearcher : UnitSearcherBase<Check, SearcherLastObjectResult<Unit*>>
    {
        UnitLastSearcher(WorldObject const* searcher, Unit*& result, Check& check)
            : UnitSearcherBase<Check, SearcherLastObjectResult<Unit*>>(searcher->GetPhaseMask(), result, check) { }
    };

    // All accepted by Check units if any
    template<class Check>
    struct UnitListSearcher : UnitSearcherBase<Check, SearcherContainerResult<Unit*>>
    {
        template<typename Container>
        UnitListSearcher(WorldObject const* searcher, Container& container, Check& check)
            : UnitSearcherBase<Check, SearcherContainerResult<Unit*>>(searcher->GetPhaseMask(), container, check) { }
    };

    // Creature searchers

    template<class Check, class Result>
    struct CreatureSearcherBase : Result
    {
        uint32 i_phaseMask;
        Check& i_check;

        template<typename Container>
        CreatureSearcherBase(uint32 phaseMask, Container& result, Check& check)
            : Result(result), i_phaseMask(phaseMask), i_check(check) { }

        void Visit(CreatureMapType& m);

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }
    };

    template<class Check>
    struct CreatureSearcher : CreatureSearcherBase<Check, SearcherFirstObjectResult<Creature*>>
    {
        CreatureSearcher(WorldObject const* searcher, Creature*& result, Check& check)
            : CreatureSearcherBase<Check, SearcherFirstObjectResult<Creature*>>(searcher->GetPhaseMask(), result, check) { }
    };

    // Last accepted by Check Creature if any (Check can change requirements at each call)
    template<class Check>
    struct CreatureLastSearcher : CreatureSearcherBase<Check, SearcherLastObjectResult<Creature*>>
    {
        CreatureLastSearcher(WorldObject const* searcher, Creature*& result, Check& check)
            : CreatureSearcherBase<Check, SearcherLastObjectResult<Creature*>>(searcher->GetPhaseMask(), result, check) { }
    };

    template<class Check>
    struct CreatureListSearcher : CreatureSearcherBase<Check, SearcherContainerResult<Creature*>>
    {
        template<typename Container>
        CreatureListSearcher(WorldObject const* searcher, Container& container, Check & check)
            : CreatureSearcherBase<Check, SearcherContainerResult<Creature*>>(searcher->GetPhaseMask(), container, check) { }
    };

    template<class Do>
    struct CreatureWorker
    {
        uint32 i_phaseMask;
        Do& i_do;

        CreatureWorker(WorldObject const* searcher, Do& _do)
            : i_phaseMask(searcher->GetPhaseMask()), i_do(_do) { }

        void Visit(CreatureMapType &m)
        {
            for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
                if (itr->GetSource()->InSamePhase(i_phaseMask))
                    i_do(itr->GetSource());
        }

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }
    };

    // Player searchers

    template<class Check, class Result>
    struct PlayerSearcherBase : Result
    {
        uint32 i_phaseMask;
        Check& i_check;

        template<typename Container>
        PlayerSearcherBase(uint32 phaseMask, Container& result, Check& check)
            : Result(result), i_phaseMask(phaseMask), i_check(check) { }

        void Visit(PlayerMapType& m);

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }
    };

    template<class Check>
    struct PlayerSearcher : PlayerSearcherBase<Check, SearcherFirstObjectResult<Player*>>
    {
        PlayerSearcher(WorldObject const* searcher, Player*& result, Check& check)
            : PlayerSearcherBase<Check, SearcherFirstObjectResult<Player*>>(searcher->GetPhaseMask(), result, check) { }
    };

    template<class Check>
    struct PlayerLastSearcher : PlayerSearcherBase<Check, SearcherLastObjectResult<Player*>>
    {
        PlayerLastSearcher(WorldObject const* searcher, Player*& result, Check& check)
            : PlayerSearcherBase<Check, SearcherLastObjectResult<Player*>>(searcher->GetPhaseMask(), result, check) { }
    };

    template<class Check>
    struct PlayerListSearcher : PlayerSearcherBase<Check, SearcherContainerResult<Player*>>
    {
        template<typename Container>
        PlayerListSearcher(WorldObject const* searcher, Container& container, Check& check)
            : PlayerSearcherBase<Check, SearcherContainerResult<Player*>>(searcher->GetPhaseMask(), container, check) { }

        template<typename Container>
        PlayerListSearcher(uint32 phaseMask, Container& container, Check& check)
            : PlayerSearcherBase<Check, SearcherContainerResult<Player*>>(phaseMask, container, check) { }
    };

    template<class Do>
    struct PlayerWorker
    {
        uint32 i_phaseMask;
        Do& i_do;

        PlayerWorker(WorldObject const* searcher, Do& _do)
            : i_phaseMask(searcher->GetPhaseMask()), i_do(_do) { }

        void Visit(PlayerMapType &m)
        {
            for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
                if (itr->GetSource()->InSamePhase(i_phaseMask))
                    i_do(itr->GetSource());
        }

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }
    };

    template<class Do>
    struct PlayerDistWorker
    {
        WorldObject const* i_searcher;
        float i_dist;
        Do& i_do;

        PlayerDistWorker(WorldObject const* searcher, float _dist, Do& _do)
            : i_searcher(searcher), i_dist(_dist), i_do(_do) { }

        void Visit(PlayerMapType &m)
        {
            for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
                if (itr->GetSource()->InSamePhase(i_searcher) && itr->GetSource()->IsWithinDist(i_searcher, i_dist))
                    i_do(itr->GetSource());
        }

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }
    };

    // CHECKS && DO classes

    // CHECK modifiers
    class InRangeCheckCustomizer
    {
    public:
        explicit InRangeCheckCustomizer(WorldObject const& obj, float range) : i_obj(obj), i_range(range) { }

        bool Test(WorldObject const* o) const
        {
            return i_obj.IsWithinDist(o, i_range);
        }

        void Update(WorldObject const* /*o*/) { }

    private:
        WorldObject const& i_obj;
        float i_range;
    };

    class NearestCheckCustomizer
    {
    public:
        explicit NearestCheckCustomizer(WorldObject const& obj, float range) : i_obj(obj), i_range(range) { }

        bool Test(WorldObject const* o) const
        {
            return i_obj.IsWithinDistInMap(o, i_range);
        }

        void Update(WorldObject const* o)
        {
            i_range = i_obj.GetDistance(o);
        }

    private:
        WorldObject const& i_obj;
        float i_range;
    };

    // WorldObject check classes

    class TC_GAME_API AnyDeadUnitObjectInRangeCheck
    {
        public:
            AnyDeadUnitObjectInRangeCheck(WorldObject* searchObj, float range) : i_searchObj(searchObj), i_range(range) { }
            bool operator()(Player* u);
            bool operator()(Corpse* u);
            bool operator()(Creature* u);
            template<class NOT_INTERESTED> bool operator()(NOT_INTERESTED*) { return false; }
        protected:
            WorldObject const* const i_searchObj;
            float i_range;
    };

    class TC_GAME_API AnyDeadUnitSpellTargetInRangeCheck : public AnyDeadUnitObjectInRangeCheck, public WorldObjectSpellTargetCheck
    {
        public:
            AnyDeadUnitSpellTargetInRangeCheck(WorldObject* searchObj, float range, SpellInfo const* spellInfo, SpellTargetCheckTypes check)
                : AnyDeadUnitObjectInRangeCheck(searchObj, range), WorldObjectSpellTargetCheck(searchObj, searchObj, spellInfo, check, nullptr)
            { }
            bool operator()(Player* u);
            bool operator()(Corpse* u);
            bool operator()(Creature* u);
            template<class NOT_INTERESTED> bool operator()(NOT_INTERESTED*) { return false; }
    };

    // WorldObject do classes

    class RespawnDo
    {
        public:
            RespawnDo() { }
            void operator()(Creature* u) const { u->Respawn(); }
            void operator()(GameObject* u) const { u->Respawn(); }
            void operator()(WorldObject*) const { }
            void operator()(Corpse*) const { }
    };

    // GameObject checks

    class GameObjectFocusCheck
    {
        public:
            GameObjectFocusCheck(WorldObject const* caster, uint32 focusId) : _caster(caster), _focusId(focusId) { }

            bool operator()(GameObject* go) const
            {
                if (go->GetGOInfo()->type != GAMEOBJECT_TYPE_SPELL_FOCUS)
                    return false;

                if (go->GetGOInfo()->spellFocus.focusId != _focusId)
                    return false;

                if (!go->isSpawned())
                    return false;

                float const dist = go->GetGOInfo()->spellFocus.dist;
                return go->IsWithinDistInMap(_caster, dist);
            }

        private:
            WorldObject const* _caster;
            uint32 _focusId;
    };

    // Find the nearest Fishing hole and return true only if source object is in range of hole
    class NearestGameObjectFishingHole
    {
        public:
            NearestGameObjectFishingHole(WorldObject const& obj, float range) : i_obj(obj), i_range(range) { }

            bool operator()(GameObject* go)
            {
                if (go->GetGOInfo()->type == GAMEOBJECT_TYPE_FISHINGHOLE && go->isSpawned() && i_obj.IsWithinDistInMap(go, i_range) && i_obj.IsWithinDistInMap(go, (float)go->GetGOInfo()->fishinghole.radius))
                {
                    i_range = i_obj.GetDistance(go);
                    return true;
                }
                return false;
            }

        private:
            WorldObject const& i_obj;
            float i_range;

            // prevent clone
            NearestGameObjectFishingHole(NearestGameObjectFishingHole const&) = delete;
    };

    class NearestGameObjectCheck
    {
        public:
            NearestGameObjectCheck(WorldObject const& obj) : i_obj(obj), i_range(999.f) { }

            bool operator()(GameObject* go)
            {
                if (i_obj.IsWithinDistInMap(go, i_range))
                {
                    i_range = i_obj.GetDistance(go);        // use found GO range as new range limit for next check
                    return true;
                }
                return false;
            }

        private:
            WorldObject const& i_obj;
            float i_range;

            // prevent clone this object
            NearestGameObjectCheck(NearestGameObjectCheck const&) = delete;
    };

    // Success at unit in range, range update for next check (this can be use with GameobjectLastSearcher to find nearest GO)
    class NearestGameObjectEntryInObjectRangeCheck
    {
        public:
            NearestGameObjectEntryInObjectRangeCheck(WorldObject const& obj, uint32 entry, float range, bool spawnedOnly = true) : i_obj(obj), i_entry(entry), i_range(range), i_spawnedOnly(spawnedOnly) { }

            bool operator()(GameObject* go)
            {
                if ((!i_spawnedOnly || go->isSpawned()) && go->GetEntry() == i_entry && go->GetGUID() != i_obj.GetGUID() && i_obj.IsWithinDistInMap(go, i_range))
                {
                    i_range = i_obj.GetDistance(go);        // use found GO range as new range limit for next check
                    return true;
                }
                return false;
            }

        private:
            WorldObject const& i_obj;
            uint32 i_entry;
            float  i_range;
            bool   i_spawnedOnly;

            // prevent clone this object
            NearestGameObjectEntryInObjectRangeCheck(NearestGameObjectEntryInObjectRangeCheck const&) = delete;
    };

    // Success at unit in range, range update for next check (this can be use with GameobjectLastSearcher to find nearest unspawned GO)
    class NearestUnspawnedGameObjectEntryInObjectRangeCheck
    {
    public:
        NearestUnspawnedGameObjectEntryInObjectRangeCheck(WorldObject const& obj, uint32 entry, float range) : i_obj(obj), i_entry(entry), i_range(range) { }

        bool operator()(GameObject* go)
        {
            if (!go->isSpawned() && go->GetEntry() == i_entry && go->GetGUID() != i_obj.GetGUID() && i_obj.IsWithinDistInMap(go, i_range))
            {
                i_range = i_obj.GetDistance(go);        // use found GO range as new range limit for next check
                return true;
            }
            return false;
        }

    private:
        WorldObject const& i_obj;
        uint32 i_entry;
        float  i_range;

        // prevent clone this object
        NearestUnspawnedGameObjectEntryInObjectRangeCheck(NearestUnspawnedGameObjectEntryInObjectRangeCheck const&) = delete;
    };

    // Success at unit in range, range update for next check (this can be use with GameobjectLastSearcher to find nearest GO with a certain type)
    class NearestGameObjectTypeInObjectRangeCheck
    {
        public:
            NearestGameObjectTypeInObjectRangeCheck(WorldObject const& obj, GameobjectTypes type, float range) : i_obj(obj), i_type(type), i_range(range) { }

            bool operator()(GameObject* go)
            {
                if (go->GetGoType() == i_type && i_obj.IsWithinDistInMap(go, i_range))
                {
                    i_range = i_obj.GetDistance(go);        // use found GO range as new range limit for next check
                    return true;
                }
                return false;
            }

        private:
            WorldObject const& i_obj;
            GameobjectTypes i_type;
            float i_range;

            // prevent clone this object
            NearestGameObjectTypeInObjectRangeCheck(NearestGameObjectTypeInObjectRangeCheck const&) = delete;
    };

    // Unit checks

    class MostHPMissingInRange
    {
        public:
            MostHPMissingInRange(Unit const* obj, float range, uint32 hp) : i_obj(obj), i_range(range), i_hp(hp) { }

            bool operator()(Unit* u)
            {
                if (u->IsAlive() && u->IsInCombat() && !i_obj->IsHostileTo(u) && i_obj->IsWithinDistInMap(u, i_range) && u->GetMaxHealth() - u->GetHealth() > i_hp)
                {
                    i_hp = u->GetMaxHealth() - u->GetHealth();
                    return true;
                }
                return false;
            }

        private:
            Unit const* i_obj;
            float i_range;
            uint32 i_hp;
    };

    class MostHPPercentMissingInRange
    {
    public:
        MostHPPercentMissingInRange(Unit const* obj, float range, uint32 minHpPct, uint32 maxHpPct) : i_obj(obj), i_range(range), i_minHpPct(minHpPct), i_maxHpPct(maxHpPct), i_hpPct(101.f) { }

        bool operator()(Unit* u)
        {
            if (u->IsAlive() && u->IsInCombat() && !i_obj->IsHostileTo(u) && i_obj->IsWithinDistInMap(u, i_range) && i_minHpPct <= u->GetHealthPct() && u->GetHealthPct() <= i_maxHpPct && u->GetHealthPct() < i_hpPct)
            {
                i_hpPct = u->GetHealthPct();
                return true;
            }
            return false;
        }

    private:
        Unit const* i_obj;
        float i_range;
        float i_minHpPct, i_maxHpPct, i_hpPct;
    };

    class FriendlyBelowHpPctEntryInRange
    {
        public:
            FriendlyBelowHpPctEntryInRange(Unit const* obj, uint32 entry, float range, uint8 pct, bool excludeSelf) : i_obj(obj), i_entry(entry), i_range(range), i_pct(pct), i_excludeSelf(excludeSelf) { }

            bool operator()(Unit* u)
            {
                if (i_excludeSelf && i_obj->GetGUID() == u->GetGUID())
                    return false;
                if (u->GetEntry() == i_entry && u->IsAlive() && u->IsInCombat() && !i_obj->IsHostileTo(u) && i_obj->IsWithinDistInMap(u, i_range) && u->HealthBelowPct(i_pct))
                    return true;
                return false;
            }

        private:
            Unit const* i_obj;
            uint32 i_entry;
            float i_range;
            uint8 i_pct;
            bool i_excludeSelf;
    };

    class MostHPMissingGroupInRange
    {
        public:
            MostHPMissingGroupInRange(Unit const* obj, float range, uint32 hp) : i_obj(obj), i_range(range), i_hp(hp) { }

            bool operator()(Unit* u)
            {
                if (i_obj == u)
                    return false;

                Player* player = nullptr;
                if (u->GetTypeId() == TYPEID_PLAYER)
                    player = u->ToPlayer();
                else if (u->IsPet() && u->GetOwner())
                    player = u->GetOwner()->ToPlayer();

                if (!player)
                    return false;

                Group* group = player->GetGroup();
                if (!group || !group->IsMember(i_obj->IsPet() ? i_obj->GetOwnerGUID() : i_obj->GetGUID()))
                    return false;

                if (u->IsAlive() && !i_obj->IsHostileTo(u) && i_obj->IsWithinDistInMap(u, i_range) && u->GetMaxHealth() - u->GetHealth() > i_hp)
                {
                    i_hp = u->GetMaxHealth() - u->GetHealth();
                    return true;
                }

                return false;
            }

        private:
            Unit const* i_obj;
            float i_range;
            uint32 i_hp;
    };

    class FriendlyCCedInRange
    {
        public:
            FriendlyCCedInRange(Unit const* obj, float range) : i_obj(obj), i_range(range) { }

            bool operator()(Unit* u) const
            {
                if (u->IsAlive() && u->IsInCombat() && !i_obj->IsHostileTo(u) && i_obj->IsWithinDistInMap(u, i_range) &&
                    (u->IsFeared() || u->IsCharmed() || u->IsRooted() || u->HasUnitState(UNIT_STATE_STUNNED) || u->HasUnitState(UNIT_STATE_CONFUSED)))
                {
                    return true;
                }
                return false;
            }

        private:
            Unit const* i_obj;
            float i_range;
    };

    class FriendlyMissingBuffInRange
    {
        public:
            FriendlyMissingBuffInRange(Unit const* obj, float range, uint32 spellid) : i_obj(obj), i_range(range), i_spell(spellid) { }

            bool operator()(Unit* u) const
            {
                if (u->IsAlive() && u->IsInCombat() && !i_obj->IsHostileTo(u) && i_obj->IsWithinDistInMap(u, i_range) && !u->HasAura(i_spell))
                    return true;

                return false;
            }

        private:
            Unit const* i_obj;
            float i_range;
            uint32 i_spell;
    };

    class AnyUnfriendlyUnitInObjectRangeCheck
    {
        public:
            AnyUnfriendlyUnitInObjectRangeCheck(WorldObject const* obj, Unit const* funit, float range) : i_obj(obj), i_funit(funit), i_range(range) { }

            bool operator()(Unit* u) const
            {
                if (u->IsAlive() && i_obj->IsWithinDistInMap(u, i_range) && !i_funit->IsFriendlyTo(u))
                    return true;

                return false;
            }

        private:
            WorldObject const* i_obj;
            Unit const* i_funit;
            float i_range;
    };

    class NearestAttackableNoTotemUnitInObjectRangeCheck
    {
        public:
            NearestAttackableNoTotemUnitInObjectRangeCheck(WorldObject const* obj, float range) : i_obj(obj), i_range(range) { }

            bool operator()(Unit* u)
            {
                if (!u->IsAlive())
                    return false;

                if (u->GetCreatureType() == CREATURE_TYPE_NON_COMBAT_PET)
                    return false;

                if (u->GetTypeId() == TYPEID_UNIT && u->ToCreature()->IsTotem())
                    return false;

                if (!u->isTargetableForAttack(false))
                    return false;

                if (!i_obj->IsWithinDistInMap(u, i_range) || !i_obj->IsValidAttackTarget(u))
                    return false;

                i_range = i_obj->GetDistance(*u);
                return true;
            }

        private:
            WorldObject const* i_obj;
            float i_range;
    };

    class AnyFriendlyUnitInObjectRangeCheck
    {
        public:
            AnyFriendlyUnitInObjectRangeCheck(WorldObject const* obj, Unit const* funit, float range, bool playerOnly = false, bool incOwnRadius = true, bool incTargetRadius = true)
                : i_obj(obj), i_funit(funit), i_range(range), i_playerOnly(playerOnly), i_incOwnRadius(incOwnRadius), i_incTargetRadius(incTargetRadius) { }

            bool operator()(Unit* u) const
            {
                if (!u->IsAlive())
                    return false;

                float searchRadius = i_range;
                if (i_incOwnRadius)
                    searchRadius += i_obj->GetCombatReach();
                if (i_incTargetRadius)
                    searchRadius += u->GetCombatReach();

                if (!u->IsInMap(i_obj) || !u->InSamePhase(i_obj) || !u->IsWithinDoubleVerticalCylinder(i_obj, searchRadius, searchRadius))
                    return false;

                if (!i_funit->IsFriendlyTo(u))
                    return false;

                return !i_playerOnly || u->GetTypeId() == TYPEID_PLAYER;
            }

        private:
            WorldObject const* i_obj;
            Unit const* i_funit;
            float i_range;
            bool i_playerOnly;
            bool i_incOwnRadius;
            bool i_incTargetRadius;
    };

    class AnyGroupedUnitInObjectRangeCheck
    {
        public:
            AnyGroupedUnitInObjectRangeCheck(WorldObject const* obj, Unit const* funit, float range, bool raid, bool playerOnly = false, bool incOwnRadius = true, bool incTargetRadius = true)
                : _source(obj), _refUnit(funit), _range(range), _raid(raid), _playerOnly(playerOnly), i_incOwnRadius(incOwnRadius), i_incTargetRadius(incTargetRadius) { }

            bool operator()(Unit* u) const
            {
                if (_playerOnly && u->GetTypeId() != TYPEID_PLAYER)
                    return false;

                if (_raid)
                {
                    if (!_refUnit->IsInRaidWith(u))
                        return false;
                }
                else if (!_refUnit->IsInPartyWith(u))
                    return false;

                if (_refUnit->IsHostileTo(u))
                    return false;

                if (!u->IsAlive())
                    return false;

                float searchRadius = _range;
                if (i_incOwnRadius)
                    searchRadius += _source->GetCombatReach();
                if (i_incTargetRadius)
                    searchRadius += u->GetCombatReach();

                return u->IsInMap(_source) && u->InSamePhase(_source) && u->IsWithinDoubleVerticalCylinder(_source, searchRadius, searchRadius);
            }

        private:
            WorldObject const* _source;
            Unit const* _refUnit;
            float _range;
            bool _raid;
            bool _playerOnly;
            bool i_incOwnRadius;
            bool i_incTargetRadius;
    };

    class AnyUnitInObjectRangeCheck
    {
        public:
            AnyUnitInObjectRangeCheck(WorldObject const* obj, float range) : i_obj(obj), i_range(range) { }

            bool operator()(Unit* u) const
            {
                if (u->IsAlive() && i_obj->IsWithinDistInMap(u, i_range))
                    return true;

                return false;
            }

        private:
            WorldObject const* i_obj;
            float i_range;
    };

    // Success at unit in range, range update for next check (this can be use with UnitLastSearcher to find nearest unit)
    class NearestAttackableUnitInObjectRangeCheck
    {
        public:
            NearestAttackableUnitInObjectRangeCheck(WorldObject const* obj, Unit const* funit, float range) : i_obj(obj), i_funit(funit), i_range(range) { }

            bool operator()(Unit* u)
            {
                if (u->isTargetableForAttack() && i_obj->IsWithinDistInMap(u, i_range) &&
                    (i_funit->IsInCombatWith(u) || i_funit->IsHostileTo(u)) && i_obj->CanSeeOrDetect(u))
                {
                    i_range = i_obj->GetDistance(u);        // use found unit range as new range limit for next check
                    return true;
                }

                return false;
            }

        private:
            WorldObject const* i_obj;
            Unit const* i_funit;
            float i_range;

            // prevent clone this object
            NearestAttackableUnitInObjectRangeCheck(NearestAttackableUnitInObjectRangeCheck const&) = delete;
    };

    class AnyAoETargetUnitInObjectRangeCheck
    {
        public:
            AnyAoETargetUnitInObjectRangeCheck(WorldObject const* obj, Unit const* funit, float range, SpellInfo const* spellInfo = nullptr, bool incOwnRadius = true, bool incTargetRadius = true)
                : i_obj(obj), i_funit(funit), _spellInfo(spellInfo), i_range(range), i_incOwnRadius(incOwnRadius), i_incTargetRadius(incTargetRadius)
            {
            }

            bool operator()(Unit* u) const
            {
                // Check contains checks for: live, uninteractible, non-attackable flags, flight check and GM check, ignore totems
                if (u->GetTypeId() == TYPEID_UNIT && u->IsTotem())
                    return false;

                if (_spellInfo && _spellInfo->HasAttribute(SPELL_ATTR3_ONLY_TARGET_PLAYERS) && u->GetTypeId() != TYPEID_PLAYER)
                    return false;

                if (!i_funit->IsValidAttackTarget(u, _spellInfo))
                    return false;

                float searchRadius = i_range;
                if (i_incOwnRadius)
                    searchRadius += i_obj->GetCombatReach();
                if (i_incTargetRadius)
                    searchRadius += u->GetCombatReach();

                return u->IsInMap(i_obj) && u->InSamePhase(i_obj) && u->IsWithinDoubleVerticalCylinder(i_obj, searchRadius, searchRadius);
            }

        private:
            WorldObject const* i_obj;
            Unit const* i_funit;
            SpellInfo const* _spellInfo;
            float i_range;
            bool i_incOwnRadius;
            bool i_incTargetRadius;
    };

    // do attack at call of help to friendly crearture
    class CallOfHelpCreatureInRangeDo
    {
        public:
            CallOfHelpCreatureInRangeDo(Unit* funit, Unit* enemy, float range)
                : i_funit(funit), i_enemy(enemy), i_range(range) { }

            void operator()(Creature* u) const
            {
                if (u == i_funit)
                    return;

                if (!u->CanAssistTo(i_funit, i_enemy, false))
                    return;

                // too far
                // Don't use combat reach distance, range must be an absolute value, otherwise the chain aggro range will be too big
                if (!u->IsWithinDistInMap(i_funit, i_range, true, false, false))
                    return;

                // only if see assisted creature's enemy
                if (!u->IsWithinLOSInMap(i_enemy))
                    return;

                u->EngageWithTarget(i_enemy);
            }
        private:
            Unit* const i_funit;
            Unit* const i_enemy;
            float i_range;
    };

    // Creature checks

    class NearestHostileUnitCheck
    {
        public:
            explicit NearestHostileUnitCheck(Creature const* creature, float dist = 0.f, bool playerOnly = false) : me(creature), i_playerOnly(playerOnly)
            {
                m_range = (dist == 0.f ? 9999.f : dist);
            }

            bool operator()(Unit* u)
            {
                if (!me->IsWithinDistInMap(u, m_range))
                    return false;

                if (!me->IsValidAttackTarget(u))
                    return false;

                if (i_playerOnly && u->GetTypeId() != TYPEID_PLAYER)
                    return false;

                m_range = me->GetDistance(u);   // use found unit range as new range limit for next check
                return true;
            }

        private:
            Creature const* me;
            float m_range;
            bool i_playerOnly;
            NearestHostileUnitCheck(NearestHostileUnitCheck const&) = delete;
    };

    class NearestHostileUnitInAttackDistanceCheck
    {
        public:
            explicit NearestHostileUnitInAttackDistanceCheck(Creature const* creature, float dist = 0.f) : me(creature)
            {
                m_range = (dist == 0.f ? 9999.f : dist);
                m_force = (dist == 0.f ? false : true);
            }

            bool operator()(Unit* u)
            {
                if (!me->IsWithinDistInMap(u, m_range))
                    return false;

                if (!me->CanSeeOrDetect(u))
                    return false;

                if (m_force)
                {
                    if (!me->IsValidAttackTarget(u))
                        return false;
                }
                else if (!me->CanStartAttack(u, false))
                    return false;

                m_range = me->GetDistance(u);   // use found unit range as new range limit for next check
                return true;
            }

        private:
            Creature const* me;
            float m_range;
            bool m_force;
            NearestHostileUnitInAttackDistanceCheck(NearestHostileUnitInAttackDistanceCheck const&) = delete;
    };

    class NearestHostileUnitInAggroRangeCheck
    {
        public:
            explicit NearestHostileUnitInAggroRangeCheck(Creature const* creature, bool useLOS = false, bool ignoreCivilians = false) : _me(creature), _useLOS(useLOS), _ignoreCivilians(ignoreCivilians) { }

            bool operator()(Unit* u) const
            {
                if (!u->IsHostileTo(_me))
                    return false;

                if (!u->IsWithinDistInMap(_me, _me->GetAggroRange(u)))
                    return false;

                if (!_me->IsValidAttackTarget(u))
                    return false;

                if (_useLOS && !u->IsWithinLOSInMap(_me))
                    return false;

                // pets in aggressive do not attack civilians
                if (_ignoreCivilians)
                    if (Creature* c = u->ToCreature())
                        if (c->IsCivilian())
                            return false;

                return true;
            }

        private:
            Creature const* _me;
            bool _useLOS;
            bool _ignoreCivilians;
            NearestHostileUnitInAggroRangeCheck(NearestHostileUnitInAggroRangeCheck const&) = delete;
    };

    class AnyAssistCreatureInRangeCheck
    {
        public:
            AnyAssistCreatureInRangeCheck(Unit* funit, Unit* enemy, float range)
                : i_funit(funit), i_enemy(enemy), i_range(range) { }

            bool operator()(Creature* u) const
            {
                if (u == i_funit)
                    return false;

                if (!u->CanAssistTo(i_funit, i_enemy))
                    return false;

                // too far
                // Don't use combat reach distance, range must be an absolute value, otherwise the chain aggro range will be too big
                if (!i_funit->IsWithinDistInMap(u, i_range, true, false, false))
                    return false;

                // only if see assisted creature
                if (!i_funit->IsWithinLOSInMap(u))
                    return false;

                return true;
            }

        private:
            Unit* const i_funit;
            Unit* const i_enemy;
            float i_range;
    };

    class NearestAssistCreatureInCreatureRangeCheck
    {
        public:
            NearestAssistCreatureInCreatureRangeCheck(Creature* obj, Unit* enemy, float range)
                : i_obj(obj), i_enemy(enemy), i_range(range) { }

            bool operator()(Creature* u)
            {
                if (u == i_obj)
                    return false;
                if (!u->CanAssistTo(i_obj, i_enemy))
                    return false;

                // Don't use combat reach distance, range must be an absolute value, otherwise the chain aggro range will be too big
                if (!i_obj->IsWithinDistInMap(u, i_range, true, false, false))
                    return false;

                if (!i_obj->IsWithinLOSInMap(u))
                    return false;

                i_range = i_obj->GetDistance(u);            // use found unit range as new range limit for next check
                return true;
            }

        private:
            Creature* const i_obj;
            Unit* const i_enemy;
            float i_range;

            // prevent clone this object
            NearestAssistCreatureInCreatureRangeCheck(NearestAssistCreatureInCreatureRangeCheck const&) = delete;
    };

    // Success at unit in range, range update for next check (this can be use with CreatureLastSearcher to find nearest creature)
    class NearestCreatureEntryWithLiveStateInObjectRangeCheck
    {
        public:
            NearestCreatureEntryWithLiveStateInObjectRangeCheck(WorldObject const& obj, uint32 entry, bool alive, float range)
                : i_obj(obj), i_entry(entry), i_alive(alive), i_range(range) { }

            bool operator()(Creature* u)
            {
                if (u->getDeathState() != DEAD
                    && u->GetEntry() == i_entry
                    && u->IsAlive() == i_alive
                    && u->GetGUID() != i_obj.GetGUID()
                    && i_obj.IsWithinDistInMap(u, i_range)
                    && u->CheckPrivateObjectOwnerVisibility(&i_obj))
                {
                    i_range = i_obj.GetDistance(u);         // use found unit range as new range limit for next check
                    return true;
                }
                return false;
            }

        private:
            WorldObject const& i_obj;
            uint32 i_entry;
            bool   i_alive;
            float  i_range;

            // prevent clone this object
            NearestCreatureEntryWithLiveStateInObjectRangeCheck(NearestCreatureEntryWithLiveStateInObjectRangeCheck const&) = delete;
    };

    template <typename Customizer = InRangeCheckCustomizer>
    class CreatureWithOptionsInObjectRangeCheck
    {
        public:
            CreatureWithOptionsInObjectRangeCheck(WorldObject const& obj, Customizer& customizer, FindCreatureOptions const& args)
                : i_obj(obj), i_args(args), i_customizer(customizer) { }

            bool operator()(Creature const* u) const
            {
                if (u->getDeathState() == DEAD) // Despawned
                    return false;

                if (u->GetGUID() == i_obj.GetGUID())
                    return false;

                if (!i_customizer.Test(u))
                    return false;

                if (i_args.CreatureId && u->GetEntry() != i_args.CreatureId)
                    return false;

                if (i_args.StringId && !u->HasStringId(*i_args.StringId))
                    return false;

                if (i_args.IsAlive.has_value() && u->IsAlive() != i_args.IsAlive)
                    return false;

                if (i_args.IsSummon.has_value() && u->IsSummon() != i_args.IsSummon)
                    return false;

                if (i_args.IsInCombat.has_value() && u->IsInCombat() != i_args.IsInCombat)
                    return false;

                if ((i_args.OwnerGuid && u->GetOwnerGUID() != i_args.OwnerGuid)
                    || (i_args.CharmerGuid && u->GetCharmerGUID() != i_args.CharmerGuid)
                    || (i_args.CreatorGuid && u->GetCreatorGUID() != i_args.CreatorGuid)
                    || (i_args.PrivateObjectOwnerGuid && u->GetPrivateObjectOwner() != i_args.PrivateObjectOwnerGuid))
                    return false;

                if (i_args.IgnorePrivateObjects && u->IsPrivateObject())
                    return false;

                if (i_args.IgnoreNotOwnedPrivateObjects && !u->CheckPrivateObjectOwnerVisibility(&i_obj))
                    return false;

                if (i_args.AuraSpellId && !u->HasAura(*i_args.AuraSpellId))
                    return false;

                i_customizer.Update(u);
                return true;
            }

        private:
            WorldObject const& i_obj;
            FindCreatureOptions const& i_args;
            Customizer& i_customizer;
    };

    template <typename Customizer = InRangeCheckCustomizer>
    class GameObjectWithOptionsInObjectRangeCheck
    {
    public:
        GameObjectWithOptionsInObjectRangeCheck(WorldObject const& obj, Customizer& customizer, FindGameObjectOptions const& args)
            : i_obj(obj), i_args(args), i_customizer(customizer) { }

        bool operator()(GameObject const* go) const
        {
            if (i_args.IsSpawned.has_value() && i_args.IsSpawned != go->isSpawned()) // Despawned
                return false;

            if (go->GetGUID() == i_obj.GetGUID())
                return false;

            if (!i_customizer.Test(go))
                return false;

            if (i_args.GameObjectId && go->GetEntry() != i_args.GameObjectId)
                return false;

            if (i_args.StringId && !go->HasStringId(*i_args.StringId))
                return false;

            if (i_args.IsSummon.has_value() && (go->GetSpawnId() == 0) != i_args.IsSummon)
                return false;

            if ((i_args.OwnerGuid && go->GetOwnerGUID() != i_args.OwnerGuid)
                || (i_args.PrivateObjectOwnerGuid && go->GetPrivateObjectOwner() != i_args.PrivateObjectOwnerGuid))
                return false;

            if (i_args.IgnorePrivateObjects && go->IsPrivateObject())
                return false;

            if (i_args.IgnoreNotOwnedPrivateObjects && !go->CheckPrivateObjectOwnerVisibility(&i_obj))
                return false;

            if (i_args.GameObjectType && go->GetGoType() != i_args.GameObjectType)
                return false;

            i_customizer.Update(go);
            return true;
        }

    private:
        WorldObject const& i_obj;
        FindGameObjectOptions const& i_args;
        Customizer& i_customizer;
    };

    class AnyPlayerInObjectRangeCheck
    {
        public:
            AnyPlayerInObjectRangeCheck(WorldObject const* obj, float range, bool reqAlive = true) : _obj(obj), _range(range), _reqAlive(reqAlive) { }

            bool operator()(Player* u) const
            {
                if (_reqAlive && !u->IsAlive())
                    return false;

                if (!_obj->IsWithinDistInMap(u, _range))
                    return false;

                return true;
            }

        private:
            WorldObject const* _obj;
            float _range;
            bool _reqAlive;
    };

    class AnyPlayerInPositionRangeCheck
    {
    public:
        AnyPlayerInPositionRangeCheck(Position const* pos, float range, bool reqAlive = true) : _pos(pos), _range(range), _reqAlive(reqAlive) { }
        bool operator()(Player* u)
        {
            if (_reqAlive && !u->IsAlive())
                return false;

            if (!u->IsWithinDist3d(_pos, _range))
                return false;

            return true;
        }

    private:
        Position const* _pos;
        float _range;
        bool _reqAlive;
    };

    class NearestPlayerInObjectRangeCheck
    {
        public:
            NearestPlayerInObjectRangeCheck(WorldObject const* obj, float range) : i_obj(obj), i_range(range) { }

            bool operator()(Player* u)
            {
                if (u->IsAlive() && i_obj->IsWithinDistInMap(u, i_range))
                {
                    i_range = i_obj->GetDistance(u);
                    return true;
                }

                return false;
            }
        private:
            WorldObject const* i_obj;
            float i_range;

            NearestPlayerInObjectRangeCheck(NearestPlayerInObjectRangeCheck const&) = delete;
    };

    class AllFriendlyCreaturesInGrid
    {
        public:
            AllFriendlyCreaturesInGrid(Unit const* obj) : unit(obj) { }

            bool operator()(Unit* u) const
            {
                if (u->IsAlive() && u->IsVisible() && u->IsFriendlyTo(unit))
                    return true;

                return false;
            }

        private:
            Unit const* unit;
    };

    class AllGameObjectsWithEntryInRange
    {
        public:
            AllGameObjectsWithEntryInRange(WorldObject const* object, uint32 entry, float maxRange) : m_pObject(object), m_uiEntry(entry), m_fRange(maxRange) { }

            bool operator()(GameObject* go) const
            {
                if ((!m_uiEntry || go->GetEntry() == m_uiEntry) && m_pObject->IsWithinDist(go, m_fRange, false))
                    return true;

                return false;
            }

        private:
            WorldObject const* m_pObject;
            uint32 m_uiEntry;
            float m_fRange;
    };

    class AllCreaturesOfEntryInRange
    {
        public:
            AllCreaturesOfEntryInRange(WorldObject const* object, uint32 entry, float maxRange = 0.0f) : m_pObject(object), m_uiEntry(entry), m_fRange(maxRange) { }

            bool operator()(Unit* unit) const
            {
                if (m_uiEntry)
                {
                    if (unit->GetEntry() != m_uiEntry)
                        return false;
                }

                if (m_fRange)
                {
                    if (m_fRange > 0.0f && !m_pObject->IsWithinDist(unit, m_fRange, false))
                        return false;
                    if (m_fRange < 0.0f && m_pObject->IsWithinDist(unit, m_fRange, false))
                        return false;
                }

                return true;
            }

        private:
            WorldObject const* m_pObject;
            uint32 m_uiEntry;
            float m_fRange;
    };

    class PlayerAtMinimumRangeAway
    {
        public:
            PlayerAtMinimumRangeAway(Unit const* unit, float fMinRange) : unit(unit), fRange(fMinRange) { }

            bool operator()(Player* player) const
            {
                //No threat list check, must be done explicit if expected to be in combat with creature
                if (!player->IsGameMaster() && player->IsAlive() && !unit->IsWithinDist(player, fRange, false))
                    return true;

                return false;
            }

        private:
            Unit const* unit;
            float fRange;
    };

    class GameObjectInRangeCheck
    {
        public:
            GameObjectInRangeCheck(float _x, float _y, float _z, float _range, uint32 _entry = 0) :
              x(_x), y(_y), z(_z), range(_range), entry(_entry) { }

            bool operator()(GameObject* go) const
            {
                if (!entry || (go->GetGOInfo() && go->GetGOInfo()->entry == entry))
                    return go->IsInRange(x, y, z, range);
                else return false;
            }

        private:
            float x, y, z, range;
            uint32 entry;
    };

    class AllWorldObjectsInRange
    {
        public:
            AllWorldObjectsInRange(WorldObject const* object, float maxRange) : m_pObject(object), m_fRange(maxRange) { }

            bool operator()(WorldObject* go) const
            {
                return m_pObject->IsWithinDist(go, m_fRange, false) && m_pObject->InSamePhase(go);
            }

        private:
            WorldObject const* m_pObject;
            float m_fRange;
    };

    class ObjectTypeIdCheck
    {
        public:
            ObjectTypeIdCheck(TypeID typeId, bool equals) : _typeId(typeId), _equals(equals) { }

            bool operator()(WorldObject* object) const
            {
                return (object->GetTypeId() == _typeId) == _equals;
            }

        private:
            TypeID _typeId;
            bool _equals;
    };

    class ObjectGUIDCheck
    {
        public:
            ObjectGUIDCheck(ObjectGuid GUID) : _GUID(GUID) { }

            bool operator()(WorldObject* object) const
            {
                return object->GetGUID() == _GUID;
            }

        private:
            ObjectGuid _GUID;
    };

    class UnitAuraCheck
    {
        public:
            UnitAuraCheck(bool present, uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty) : _present(present), _spellId(spellId), _casterGUID(casterGUID) { }

            bool operator()(Unit* unit) const
            {
                return unit->HasAura(_spellId, _casterGUID) == _present;
            }

            bool operator()(WorldObject* object) const
            {
                return object->ToUnit() && object->ToUnit()->HasAura(_spellId, _casterGUID) == _present;
            }

        private:
            bool _present;
            uint32 _spellId;
            ObjectGuid _casterGUID;
    };

    // Player checks and do

    // Prepare using Builder localized packets with caching and send to player
    template<class Builder>
    class LocalizedPacketDo
    {
        public:
            explicit LocalizedPacketDo(Builder& builder) : i_builder(builder) { }

            ~LocalizedPacketDo()
            {
                for (size_t i = 0; i < i_data_cache.size(); ++i)
                    delete i_data_cache[i];
            }

            void operator()(Player* p);

        private:
            Builder& i_builder;
            std::vector<WorldPacket*> i_data_cache;         // 0 = default, i => i-1 locale index
    };

    // Prepare using Builder localized packets with caching and send to player
    template<class Builder>
    class LocalizedPacketListDo
    {
        public:
            typedef std::vector<WorldPacket*> WorldPacketList;
            explicit LocalizedPacketListDo(Builder& builder) : i_builder(builder) { }

            ~LocalizedPacketListDo()
            {
                for (size_t i = 0; i < i_data_cache.size(); ++i)
                    for (size_t j = 0; j < i_data_cache[i].size(); ++j)
                        delete i_data_cache[i][j];
            }
            void operator()(Player* p);

        private:
            Builder& i_builder;
            std::vector<WorldPacketList> i_data_cache;
                                                            // 0 = default, i => i-1 locale index
    };
}
#endif

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

#include "AreaTrigger.h"
#include "Creature.h"
#include "Corpse.h"
#include "Conversation.h"
#include "DynamicObject.h"
#include "GameObject.h"
#include "Packet.h"
#include "Player.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "UnitAI.h"
#include "UpdateData.h"

namespace Trinity
{
    struct TC_GAME_API VisibleNotifier
    {
        Player &i_player;
        UpdateData i_data;
        std::set<Unit*> i_visibleNow;
        GuidUnorderedSet vis_guids;

        VisibleNotifier(Player &player) : i_player(player), i_data(player.GetMapId()), vis_guids(player.m_clientGUIDs) { }
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
        void Visit(AreaTriggerMapType &m) { updateObjects<AreaTrigger>(m); }
        void Visit(ConversationMapType &m) { updateObjects<Conversation>(m); }
    };

    struct TC_GAME_API MessageDistDeliverer
    {
        WorldObject const* i_source;
        WorldPacket const* i_message;
        float i_distSq;
        uint32 team;
        Player const* skipped_receiver;
        MessageDistDeliverer(WorldObject const* src, WorldPacket const* msg, float dist, bool own_team_only = false, Player const* skipped = nullptr)
            : i_source(src), i_message(msg), i_distSq(dist * dist)
            , team(0)
            , skipped_receiver(skipped)
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
        float i_distSq;

        MessageDistDelivererToHostile(Unit* src, WorldPacket const* msg, float dist)
            : i_source(src), i_message(msg), i_distSq(dist * dist)
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

    // Generic base class to insert elements into arbitrary containers using push_back
    template<typename Type>
    class ContainerInserter {
        using InserterType = void(*)(void*, Type&&);

        void* ref;
        InserterType inserter;

        // MSVC workaround
        template<typename T>
        static void InserterOf(void* ref, Type&& type)
        {
            static_cast<T*>(ref)->push_back(std::move(type));
        }

    protected:
        template<typename T>
        ContainerInserter(T& ref_) : ref(&ref_), inserter(&InserterOf<T>) { }

        void Insert(Type type)
        {
            inserter(ref, std::move(type));
        }
    };

    template<class Check>
    struct WorldObjectSearcher
    {
        WorldObject const* _searcher;
        WorldObject*& i_object;
        Check &i_check;
        uint32 i_mapTypeMask;

        WorldObjectSearcher(WorldObject const* searcher, WorldObject* & result, Check& check, uint32 mapTypeMask = GRID_MAP_TYPE_MASK_ALL)
            : _searcher(searcher), i_object(result), i_check(check), i_mapTypeMask(mapTypeMask) { }

        void Visit(GameObjectMapType &m);
        void Visit(PlayerMapType &m);
        void Visit(CreatureMapType &m);
        void Visit(CorpseMapType &m);
        void Visit(DynamicObjectMapType &m);
        void Visit(AreaTriggerMapType &m);
        void Visit(ConversationMapType &m);

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }
    };

    template<class Check>
    struct WorldObjectLastSearcher
    {
        WorldObject const* _searcher;
        WorldObject* &i_object;
        Check &i_check;
        uint32 i_mapTypeMask;

        WorldObjectLastSearcher(WorldObject const* searcher, WorldObject* & result, Check& check, uint32 mapTypeMask = GRID_MAP_TYPE_MASK_ALL)
            : _searcher(searcher), i_object(result), i_check(check), i_mapTypeMask(mapTypeMask) { }

        void Visit(GameObjectMapType &m);
        void Visit(PlayerMapType &m);
        void Visit(CreatureMapType &m);
        void Visit(CorpseMapType &m);
        void Visit(DynamicObjectMapType &m);
        void Visit(AreaTriggerMapType &m);
        void Visit(ConversationMapType &m);

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }
    };

    template<class Check>
    struct WorldObjectListSearcher : ContainerInserter<WorldObject*>
    {
        uint32 i_mapTypeMask;
        WorldObject const* _searcher;
        Check& i_check;

        template<typename Container>
        WorldObjectListSearcher(WorldObject const* searcher, Container& container, Check & check, uint32 mapTypeMask = GRID_MAP_TYPE_MASK_ALL)
            : ContainerInserter<WorldObject*>(container),
              i_mapTypeMask(mapTypeMask), _searcher(searcher), i_check(check) { }

        void Visit(PlayerMapType &m);
        void Visit(CreatureMapType &m);
        void Visit(CorpseMapType &m);
        void Visit(GameObjectMapType &m);
        void Visit(DynamicObjectMapType &m);
        void Visit(AreaTriggerMapType &m);
        void Visit(ConversationMapType &m);

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }
    };

    template<class Do>
    struct WorldObjectWorker
    {
        uint32 i_mapTypeMask;
        WorldObject const* _searcher;
        Do const& i_do;

        WorldObjectWorker(WorldObject const* searcher, Do const& _do, uint32 mapTypeMask = GRID_MAP_TYPE_MASK_ALL)
            : i_mapTypeMask(mapTypeMask), _searcher(searcher), i_do(_do) { }

        void Visit(GameObjectMapType &m)
        {
            if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_GAMEOBJECT))
                return;
            for (GameObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
                if (itr->GetSource()->IsInPhase(_searcher))
                    i_do(itr->GetSource());
        }

        void Visit(PlayerMapType &m)
        {
            if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_PLAYER))
                return;
            for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
                if (itr->GetSource()->IsInPhase(_searcher))
                    i_do(itr->GetSource());
        }
        void Visit(CreatureMapType &m)
        {
            if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_CREATURE))
                return;
            for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
                if (itr->GetSource()->IsInPhase(_searcher))
                    i_do(itr->GetSource());
        }

        void Visit(CorpseMapType &m)
        {
            if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_CORPSE))
                return;
            for (CorpseMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
                if (itr->GetSource()->IsInPhase(_searcher))
                    i_do(itr->GetSource());
        }

        void Visit(DynamicObjectMapType &m)
        {
            if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_DYNAMICOBJECT))
                return;
            for (DynamicObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
                if (itr->GetSource()->IsInPhase(_searcher))
                    i_do(itr->GetSource());
        }

        void Visit(AreaTriggerMapType &m)
        {
            if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_AREATRIGGER))
                return;
            for (AreaTriggerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
                if (itr->GetSource()->IsInPhase(_searcher))
                    i_do(itr->GetSource());
        }

        void Visit(ConversationMapType &m)
        {
            if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_CONVERSATION))
                return;
            for (ConversationMapType::iterator itr = m.begin(); itr != m.end(); ++itr)
                if (itr->GetSource()->IsInPhase(_searcher))
                    i_do(itr->GetSource());
        }

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }
    };

    // Gameobject searchers

    template<class Check>
    struct GameObjectSearcher
    {
        WorldObject const* _searcher;
        GameObject* &i_object;
        Check &i_check;

        GameObjectSearcher(WorldObject const* searcher, GameObject* & result, Check& check)
            : _searcher(searcher), i_object(result), i_check(check) { }

        void Visit(GameObjectMapType &m);

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }
    };

    // Last accepted by Check GO if any (Check can change requirements at each call)
    template<class Check>
    struct GameObjectLastSearcher
    {
        WorldObject const* _searcher;
        GameObject* &i_object;
        Check& i_check;

        GameObjectLastSearcher(WorldObject const* searcher, GameObject* & result, Check& check)
            : _searcher(searcher), i_object(result), i_check(check) { }

        void Visit(GameObjectMapType &m);

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }
    };

    template<class Check>
    struct GameObjectListSearcher : ContainerInserter<GameObject*>
    {
        WorldObject const* _searcher;
        Check& i_check;

        template<typename Container>
        GameObjectListSearcher(WorldObject const* searcher, Container& container, Check & check)
            : ContainerInserter<GameObject*>(container),
              _searcher(searcher), i_check(check) { }

        void Visit(GameObjectMapType &m);

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }
    };

    template<class Functor>
    struct GameObjectWorker
    {
        GameObjectWorker(WorldObject const* searcher, Functor& func)
            : _func(func), _searcher(searcher) { }

        void Visit(GameObjectMapType& m)
        {
            for (GameObjectMapType::iterator itr = m.begin(); itr != m.end(); ++itr)
                if (itr->GetSource()->IsInPhase(_searcher))
                    _func(itr->GetSource());
        }

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }

    private:
        Functor& _func;
        WorldObject const* _searcher;
    };

    // Unit searchers

    // First accepted by Check Unit if any
    template<class Check>
    struct UnitSearcher
    {
        WorldObject const* _searcher;
        Unit* &i_object;
        Check & i_check;

        UnitSearcher(WorldObject const* searcher, Unit* & result, Check & check)
            : _searcher(searcher), i_object(result), i_check(check) { }

        void Visit(CreatureMapType &m);
        void Visit(PlayerMapType &m);

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }
    };

    // Last accepted by Check Unit if any (Check can change requirements at each call)
    template<class Check>
    struct UnitLastSearcher
    {
        WorldObject const* _searcher;
        Unit* &i_object;
        Check & i_check;

        UnitLastSearcher(WorldObject const* searcher, Unit* & result, Check & check)
            : _searcher(searcher), i_object(result), i_check(check) { }

        void Visit(CreatureMapType &m);
        void Visit(PlayerMapType &m);

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }
    };

    // All accepted by Check units if any
    template<class Check>
    struct UnitListSearcher : ContainerInserter<Unit*>
    {
        WorldObject const* _searcher;
        Check& i_check;

        template<typename Container>
        UnitListSearcher(WorldObject const* searcher, Container& container, Check& check)
            : ContainerInserter<Unit*>(container),
              _searcher(searcher), i_check(check) { }

        void Visit(PlayerMapType &m);
        void Visit(CreatureMapType &m);

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }
    };

    // Creature searchers

    template<class Check>
    struct CreatureSearcher
    {
        WorldObject const* _searcher;
        Creature* &i_object;
        Check & i_check;

        CreatureSearcher(WorldObject const* searcher, Creature* & result, Check & check)
            : _searcher(searcher), i_object(result), i_check(check) { }

        void Visit(CreatureMapType &m);

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }
    };

    // Last accepted by Check Creature if any (Check can change requirements at each call)
    template<class Check>
    struct CreatureLastSearcher
    {
        WorldObject const* _searcher;
        Creature* &i_object;
        Check & i_check;

        CreatureLastSearcher(WorldObject const* searcher, Creature* & result, Check & check)
            : _searcher(searcher), i_object(result), i_check(check) { }

        void Visit(CreatureMapType &m);

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }
    };

    template<class Check>
    struct CreatureListSearcher : ContainerInserter<Creature*>
    {
        WorldObject const* _searcher;
        Check& i_check;

        template<typename Container>
        CreatureListSearcher(WorldObject const* searcher, Container& container, Check & check)
            : ContainerInserter<Creature*>(container),
              _searcher(searcher), i_check(check) { }

        void Visit(CreatureMapType &m);

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }
    };

    template<class Do>
    struct CreatureWorker
    {
        WorldObject const* _searcher;
        Do& i_do;

        CreatureWorker(WorldObject const* searcher, Do& _do)
            : _searcher(searcher), i_do(_do) { }

        void Visit(CreatureMapType &m)
        {
            for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
                if (itr->GetSource()->IsInPhase(_searcher))
                    i_do(itr->GetSource());
        }

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }
    };

    // Player searchers

    template<class Check>
    struct PlayerSearcher
    {
        WorldObject const* _searcher;
        Player* &i_object;
        Check & i_check;

        PlayerSearcher(WorldObject const* searcher, Player* & result, Check & check)
            : _searcher(searcher), i_object(result), i_check(check) { }

        void Visit(PlayerMapType &m);

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }
    };

    template<class Check>
    struct PlayerListSearcher : ContainerInserter<Player*>
    {
        WorldObject const* _searcher;
        Check& i_check;

        template<typename Container>
        PlayerListSearcher(WorldObject const* searcher, Container& container, Check & check)
            : ContainerInserter<Player*>(container),
              _searcher(searcher), i_check(check) { }

        void Visit(PlayerMapType &m);

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }
    };

    template<class Check>
    struct PlayerLastSearcher
    {
        WorldObject const* _searcher;
        Player* &i_object;
        Check& i_check;

        PlayerLastSearcher(WorldObject const* searcher, Player*& result, Check& check) : _searcher(searcher), i_object(result), i_check(check)
        {
        }

        void Visit(PlayerMapType& m);

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }
    };

    template<class Do>
    struct PlayerWorker
    {
        WorldObject const* _searcher;
        Do& i_do;

        PlayerWorker(WorldObject const* searcher, Do& _do)
            : _searcher(searcher), i_do(_do) { }

        void Visit(PlayerMapType &m)
        {
            for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
                if (itr->GetSource()->IsInPhase(_searcher))
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
                if (itr->GetSource()->IsInPhase(i_searcher) && itr->GetSource()->IsWithinDist(i_searcher, i_dist))
                    i_do(itr->GetSource());
        }

        template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }
    };

    // CHECKS && DO classes

    // WorldObject check classes

    class TC_GAME_API AnyDeadUnitObjectInRangeCheck
    {
        public:
            AnyDeadUnitObjectInRangeCheck(Unit* searchObj, float range) : i_searchObj(searchObj), i_range(range) { }
            bool operator()(Player* u);
            bool operator()(Corpse* u);
            bool operator()(Creature* u);
            template<class NOT_INTERESTED> bool operator()(NOT_INTERESTED*) { return false; }
        protected:
            Unit const* const i_searchObj;
            float i_range;
    };

    class TC_GAME_API AnyDeadUnitSpellTargetInRangeCheck : public AnyDeadUnitObjectInRangeCheck
    {
        public:
            AnyDeadUnitSpellTargetInRangeCheck(Unit* searchObj, float range, SpellInfo const* spellInfo, SpellTargetCheckTypes check, SpellTargetObjectTypes objectType)
                : AnyDeadUnitObjectInRangeCheck(searchObj, range), i_spellInfo(spellInfo), i_check(searchObj, searchObj, spellInfo, check, nullptr, objectType)
            { }
            bool operator()(Player* u);
            bool operator()(Corpse* u);
            bool operator()(Creature* u);
            template<class NOT_INTERESTED> bool operator()(NOT_INTERESTED*) { return false; }
        protected:
            SpellInfo const* i_spellInfo;
            WorldObjectSpellTargetCheck i_check;
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
            GameObjectFocusCheck(Unit const* unit, uint32 focusId) : i_unit(unit), i_focusId(focusId) { }

            bool operator()(GameObject* go) const
            {
                if (go->GetGOInfo()->GetSpellFocusType() != i_focusId)
                    return false;

                if (!go->isSpawned())
                    return false;

                float dist = go->GetGOInfo()->GetSpellFocusRadius() / 2.f;

                return go->IsWithinDistInMap(i_unit, dist);
            }

        private:
            Unit const* i_unit;
            uint32 i_focusId;
    };

    // Find the nearest Fishing hole and return true only if source object is in range of hole
    class NearestGameObjectFishingHole
    {
        public:
            NearestGameObjectFishingHole(WorldObject const& obj, float range) : i_obj(obj), i_range(range) { }

            bool operator()(GameObject* go)
            {
                if (go->GetGOInfo()->type == GAMEOBJECT_TYPE_FISHINGHOLE && go->isSpawned() && i_obj.IsWithinDistInMap(go, i_range) && i_obj.IsWithinDistInMap(go, (float)go->GetGOInfo()->fishingHole.radius))
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
            NearestGameObjectEntryInObjectRangeCheck(WorldObject const& obj, uint32 entry, float range) : i_obj(obj), i_entry(entry), i_range(range) { }

            bool operator()(GameObject* go)
            {
                if (go->GetEntry() == i_entry && i_obj.IsWithinDistInMap(go, i_range))
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
            NearestGameObjectEntryInObjectRangeCheck(NearestGameObjectEntryInObjectRangeCheck const&) = delete;
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
            float  i_range;

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
            uint64 i_hp;
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

    class FriendlyCCedInRange
    {
        public:
            FriendlyCCedInRange(Unit const* obj, float range) : i_obj(obj), i_range(range) { }

            bool operator()(Unit* u) const
            {
                if (u->IsAlive() && u->IsInCombat() && !i_obj->IsHostileTo(u) && i_obj->IsWithinDistInMap(u, i_range) &&
                    (u->isFeared() || u->IsCharmed() || u->isFrozen() || u->HasUnitState(UNIT_STATE_STUNNED) || u->HasUnitState(UNIT_STATE_CONFUSED)))
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
            NearestAttackableNoTotemUnitInObjectRangeCheck(WorldObject const* obj, Unit const* funit, float range) : i_obj(obj), i_funit(funit), i_range(range) { }

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

                if (!i_obj->IsWithinDistInMap(u, i_range) || !i_funit->_IsValidAttackTarget(u, nullptr, i_obj))
                    return false;

                i_range = i_obj->GetDistance(*u);
                return true;
            }

        private:
            WorldObject const* i_obj;
            Unit const* i_funit;
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

                if (!u->IsInMap(i_obj) || !u->IsInPhase(i_obj) || !u->IsWithinDoubleVerticalCylinder(i_obj, searchRadius, searchRadius))
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

                return u->IsInMap(_source) && u->IsInPhase(_source) && u->IsWithinDoubleVerticalCylinder(_source, searchRadius, searchRadius);
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
            AnyUnitInObjectRangeCheck(WorldObject const* obj, float range, bool check3D = true) : i_obj(obj), i_range(range), i_check3D(check3D) { }

            bool operator()(Unit* u) const
            {
                if (u->IsAlive() && i_obj->IsWithinDistInMap(u, i_range, i_check3D))
                    return true;

                return false;
            }

        private:
            WorldObject const* i_obj;
            float i_range;
            bool i_check3D;
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
                if (!_spellInfo)
                    if (DynamicObject const* dynObj = i_obj->ToDynObject())
                        _spellInfo = dynObj->GetSpellInfo();
            }

            bool operator()(Unit* u) const
            {
                // Check contains checks for: live, non-selectable, non-attackable flags, flight check and GM check, ignore totems
                if (u->GetTypeId() == TYPEID_UNIT && u->IsTotem())
                    return false;

                if (_spellInfo && _spellInfo->HasAttribute(SPELL_ATTR3_ONLY_TARGET_PLAYERS) && u->GetTypeId() != TYPEID_PLAYER)
                    return false;

                if (!i_funit->_IsValidAttackTarget(u, _spellInfo, i_obj->GetTypeId() == TYPEID_DYNAMICOBJECT ? i_obj : nullptr))
                    return false;

                float searchRadius = i_range;
                if (i_incOwnRadius)
                    searchRadius += i_obj->GetCombatReach();
                if (i_incTargetRadius)
                    searchRadius += u->GetCombatReach();

                return u->IsInMap(i_obj) && u->IsInPhase(i_obj) && u->IsWithinDoubleVerticalCylinder(i_obj, searchRadius, searchRadius);
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
                if (!u->IsWithinDistInMap(i_funit, i_range))
                    return;

                // only if see assisted creature's enemy
                if (!u->IsWithinLOSInMap(i_enemy))
                    return;

                if (u->GetAI() && u->IsAIEnabled)
                    u->GetAI()->AttackStart(i_enemy);
            }
        private:
            Unit* const i_funit;
            Unit* const i_enemy;
            float i_range;
    };

    struct AnyDeadUnitCheck
    {
        bool operator()(Unit* u) const
        {
            return !u->IsAlive();
        }
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
            explicit NearestHostileUnitInAggroRangeCheck(Creature const* creature, bool useLOS = false) : _me(creature), _useLOS(useLOS) { }

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

                return true;
            }

        private:
            Creature const* _me;
            bool _useLOS;
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
                if (!i_funit->IsWithinDistInMap(u, i_range))
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

                if (!i_obj->IsWithinDistInMap(u, i_range))
                    return false;

                if (!i_obj->IsWithinLOSInMap(u))
                    return false;

                i_range = i_obj->GetDistance(u);            // use found unit range as new range limit for next check
                return true;
            }

        private:
            Creature* const i_obj;
            Unit* const i_enemy;
            float  i_range;

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
                if (u->getDeathState() != DEAD && u->GetEntry() == i_entry && u->IsAlive() == i_alive && i_obj.IsWithinDistInMap(u, i_range))
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
            AllCreaturesOfEntryInRange(WorldObject const* object, uint32 entry, float maxRange) : m_pObject(object), m_uiEntry(entry), m_fRange(maxRange) { }

            bool operator()(Unit* unit) const
            {
                if ((!m_uiEntry || unit->GetEntry() == m_uiEntry) && m_pObject->IsWithinDist(unit, m_fRange, false))
                    return true;

                return false;
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
                return m_pObject->IsWithinDist(go, m_fRange, false) && m_pObject->IsInPhase(go);
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

    class HeightDifferenceCheck
    {
    public:
        HeightDifferenceCheck(WorldObject* go, float diff, bool reverse)
            : _baseObject(go), _difference(diff), _reverse(reverse)
        {
        }

        bool operator()(WorldObject* unit) const
        {
            return (unit->GetPositionZ() - _baseObject->GetPositionZ() > _difference) != _reverse;
        }

    private:
        WorldObject* _baseObject;
        float _difference;
        bool _reverse;
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
            std::vector<WorldPackets::Packet*> i_data_cache;         // 0 = default, i => i-1 locale index
    };

    // Prepare using Builder localized packets with caching and send to player
    template<class Builder>
    class LocalizedPacketListDo
    {
        public:
            typedef std::vector<WorldPackets::Packet*> WorldPacketList;
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

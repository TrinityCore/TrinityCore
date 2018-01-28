/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "GameObject.h"
#include "ArtifactPackets.h"
#include "Battleground.h"
#include "CellImpl.h"
#include "CreatureAISelector.h"
#include "DatabaseEnv.h"
#include "GameObjectAI.h"
#include "GameObjectModel.h"
#include "GameObjectPackets.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "GroupMgr.h"
#include "Item.h"
#include "Log.h"
#include "LootMgr.h"
#include "MiscPackets.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "OutdoorPvPMgr.h"
#include "PhasingHandler.h"
#include "PoolMgr.h"
#include "ScriptMgr.h"
#include "SpellMgr.h"
#include "Transport.h"
#include "UpdateFieldFlags.h"
#include "World.h"
#include <G3D/Quat.h>

bool QuaternionData::isUnit() const
{
    return fabs(x * x + y * y + z * z + w * w - 1.0f) < 1e-5;
}

QuaternionData QuaternionData::fromEulerAnglesZYX(float Z, float Y, float X)
{
    G3D::Quat quat(G3D::Matrix3::fromEulerAnglesZYX(Z, Y, X));
    return QuaternionData(quat.x, quat.y, quat.z, quat.w);
}

GameObject::GameObject() : WorldObject(false), MapObject(),
    m_model(nullptr), m_goValue(), m_AI(nullptr), _animKitId(0), _worldEffectID(0)
{
    m_objectType |= TYPEMASK_GAMEOBJECT;
    m_objectTypeId = TYPEID_GAMEOBJECT;

    m_updateFlag = (UPDATEFLAG_STATIONARY_POSITION | UPDATEFLAG_ROTATION);

    m_valuesCount = GAMEOBJECT_END;
    _dynamicValuesCount = GAMEOBJECT_DYNAMIC_END;
    m_respawnTime = 0;
    m_respawnDelayTime = 300;
    m_lootState = GO_NOT_READY;
    m_spawnedByDefault = true;
    m_usetimes = 0;
    m_spellId = 0;
    m_cooldownTime = 0;
    m_prevGoState = GO_STATE_ACTIVE;
    m_goInfo = nullptr;
    m_goData = nullptr;
    m_packedRotation = 0;
    m_goTemplateAddon = nullptr;

    m_spawnId = UI64LIT(0);

    m_groupLootTimer = 0;

    ResetLootMode(); // restore default loot mode
    m_stationaryPosition.Relocate(0.0f, 0.0f, 0.0f, 0.0f);
}

GameObject::~GameObject()
{
    delete m_AI;
    delete m_model;
    if (m_goInfo && m_goInfo->type == GAMEOBJECT_TYPE_TRANSPORT)
        delete m_goValue.Transport.StopFrames;
    //if (m_uint32Values)                                      // field array can be not exist if GameOBject not loaded
    //    CleanupsBeforeDelete();
}

void GameObject::AIM_Destroy()
{
    delete m_AI;
    m_AI = nullptr;
}

bool GameObject::AIM_Initialize()
{
    AIM_Destroy();

    m_AI = FactorySelector::SelectGameObjectAI(this);

    if (!m_AI)
        return false;

    m_AI->InitializeAI();
    return true;
}

std::string GameObject::GetAIName() const
{
    if (GameObjectTemplate const* got = sObjectMgr->GetGameObjectTemplate(GetEntry()))
        return got->AIName;

    return "";
}

void GameObject::CleanupsBeforeDelete(bool finalCleanup)
{
    WorldObject::CleanupsBeforeDelete(finalCleanup);

    if (m_uint32Values)                                      // field array can be not exist if GameOBject not loaded
        RemoveFromOwner();
}

void GameObject::RemoveFromOwner()
{
    ObjectGuid ownerGUID = GetOwnerGUID();
    if (!ownerGUID)
        return;

    if (Unit* owner = ObjectAccessor::GetUnit(*this, ownerGUID))
    {
        owner->RemoveGameObject(this, false);
        ASSERT(!GetOwnerGUID());
        return;
    }

    // This happens when a mage portal is despawned after the caster changes map (for example using the portal)
    TC_LOG_DEBUG("misc", "Removed GameObject (%s SpellId: %u LinkedGO: %u) that just lost any reference to the owner (%s) GO list",
        GetGUID().ToString().c_str(), m_spellId, GetGOInfo()->GetLinkedGameObjectEntry(), ownerGUID.ToString().c_str());
    SetOwnerGUID(ObjectGuid::Empty);
}

void GameObject::AddToWorld()
{
    ///- Register the gameobject for guid lookup
    if (!IsInWorld())
    {
        if (m_zoneScript)
            m_zoneScript->OnGameObjectCreate(this);

        GetMap()->GetObjectsStore().Insert<GameObject>(GetGUID(), this);
        if (m_spawnId)
            GetMap()->GetGameObjectBySpawnIdStore().insert(std::make_pair(m_spawnId, this));

        // The state can be changed after GameObject::Create but before GameObject::AddToWorld
        bool toggledState = GetGoType() == GAMEOBJECT_TYPE_CHEST ? getLootState() == GO_READY : (GetGoState() == GO_STATE_READY || IsTransport());
        if (m_model)
        {
            if (Transport* trans = ToTransport())
                trans->SetDelayedAddModelToMap();
            else
                GetMap()->InsertGameObjectModel(*m_model);
        }

        EnableCollision(toggledState);
        WorldObject::AddToWorld();
    }
}

void GameObject::RemoveFromWorld()
{
    ///- Remove the gameobject from the accessor
    if (IsInWorld())
    {
        if (m_zoneScript)
            m_zoneScript->OnGameObjectRemove(this);

        RemoveFromOwner();
        if (m_model)
            if (GetMap()->ContainsGameObjectModel(*m_model))
                GetMap()->RemoveGameObjectModel(*m_model);

        WorldObject::RemoveFromWorld();

        if (m_spawnId)
            Trinity::Containers::MultimapErasePair(GetMap()->GetGameObjectBySpawnIdStore(), m_spawnId, this);
        GetMap()->GetObjectsStore().Remove<GameObject>(GetGUID());
    }
}

bool GameObject::Create(uint32 entry, Map* map, Position const& pos, QuaternionData const& rotation, uint32 animProgress, GOState goState, uint32 artKit)
{
    ASSERT(map);
    SetMap(map);

    Relocate(pos);
    m_stationaryPosition.Relocate(pos);
    if (!IsPositionValid())
    {
        TC_LOG_ERROR("misc", "Gameobject (Spawn id: " UI64FMTD " Entry: %u) not created. Suggested coordinates isn't valid (X: %f Y: %f)", GetSpawnId(), entry, pos.GetPositionX(), pos.GetPositionY());
        return false;
    }

    SetZoneScript();
    if (m_zoneScript)
    {
        entry = m_zoneScript->GetGameObjectEntry(m_spawnId, entry);
        if (!entry)
            return false;
    }

    GameObjectTemplate const* goInfo = sObjectMgr->GetGameObjectTemplate(entry);
    if (!goInfo)
    {
        TC_LOG_ERROR("sql.sql", "Gameobject (Spawn id: " UI64FMTD " Entry: %u) not created: non-existing entry in `gameobject_template`. Map: %u (X: %f Y: %f Z: %f)", GetSpawnId(), entry, map->GetId(), pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());
        return false;
    }

    if (goInfo->type == GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT)
    {
        TC_LOG_ERROR("sql.sql", "Gameobject (Spawn id: " UI64FMTD " Entry: %u) not created: gameobject type GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT cannot be manually created.", GetSpawnId(), entry);
        return false;
    }

    ObjectGuid guid;
    if (goInfo->type != GAMEOBJECT_TYPE_TRANSPORT)
        guid = ObjectGuid::Create<HighGuid::GameObject>(map->GetId(), goInfo->entry, map->GenerateLowGuid<HighGuid::GameObject>());
    else
    {
        guid = ObjectGuid::Create<HighGuid::Transport>(map->GenerateLowGuid<HighGuid::Transport>());
        m_updateFlag |= UPDATEFLAG_TRANSPORT;
    }

    Object::_Create(guid);

    m_goInfo = goInfo;
    m_goTemplateAddon = sObjectMgr->GetGameObjectTemplateAddon(entry);

    if (goInfo->type >= MAX_GAMEOBJECT_TYPE)
    {
        TC_LOG_ERROR("sql.sql", "Gameobject (%s Spawn id: " UI64FMTD " Entry: %u) not created: non-existing GO type '%u' in `gameobject_template`. It will crash client if created.", guid.ToString().c_str(), GetSpawnId(), entry, goInfo->type);
        return false;
    }

    SetWorldRotation(rotation.x, rotation.y, rotation.z, rotation.w);
    GameObjectAddon const* gameObjectAddon = sObjectMgr->GetGameObjectAddon(GetSpawnId());

    // For most of gameobjects is (0, 0, 0, 1) quaternion, there are only some transports with not standard rotation
    QuaternionData parentRotation;
    if (gameObjectAddon)
        parentRotation = gameObjectAddon->ParentRotation;

    SetParentRotation(parentRotation);

    SetObjectScale(goInfo->size);

    if (m_goTemplateAddon)
    {
        SetUInt32Value(GAMEOBJECT_FACTION, m_goTemplateAddon->faction);
        SetUInt32Value(GAMEOBJECT_FLAGS, m_goTemplateAddon->flags);

        if (m_goTemplateAddon->WorldEffectID)
        {
            m_updateFlag |= UPDATEFLAG_GAMEOBJECT;
            SetWorldEffectID(m_goTemplateAddon->WorldEffectID);
        }
    }

    SetEntry(goInfo->entry);

    // set name for logs usage, doesn't affect anything ingame
    SetName(goInfo->name);

    SetDisplayId(goInfo->displayId);

    m_model = CreateModel();
    // GAMEOBJECT_BYTES_1, index at 0, 1, 2 and 3
    SetGoType(GameobjectTypes(goInfo->type));
    m_prevGoState = goState;
    SetGoState(goState);
    SetGoArtKit(artKit);

    switch (goInfo->type)
    {
        case GAMEOBJECT_TYPE_FISHINGHOLE:
            SetGoAnimProgress(animProgress);
            m_goValue.FishingHole.MaxOpens = urand(GetGOInfo()->fishingHole.minRestock, GetGOInfo()->fishingHole.maxRestock);
            break;
        case GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING:
            // TODO: Get the values somehow, no longer in gameobject_template
            m_goValue.Building.Health = 20000/*goinfo->destructibleBuilding.intactNumHits + goinfo->destructibleBuilding.damagedNumHits*/;
            m_goValue.Building.MaxHealth = m_goValue.Building.Health;
            SetGoAnimProgress(255);
            SetUInt32Value(GAMEOBJECT_PARENTROTATION, m_goInfo->destructibleBuilding.DestructibleModelRec);
            break;
        case GAMEOBJECT_TYPE_TRANSPORT:
        {
            m_goValue.Transport.AnimationInfo = sTransportMgr->GetTransportAnimInfo(goInfo->entry);
            m_goValue.Transport.PathProgress = getMSTime();
            if (m_goValue.Transport.AnimationInfo)
                m_goValue.Transport.PathProgress -= m_goValue.Transport.PathProgress % GetTransportPeriod();    // align to period
            m_goValue.Transport.CurrentSeg = 0;
            m_goValue.Transport.StateUpdateTimer = 0;
            m_goValue.Transport.StopFrames = new std::vector<uint32>();
            if (goInfo->transport.Timeto2ndfloor > 0)
                m_goValue.Transport.StopFrames->push_back(goInfo->transport.Timeto2ndfloor);
            if (goInfo->transport.Timeto3rdfloor > 0)
                m_goValue.Transport.StopFrames->push_back(goInfo->transport.Timeto3rdfloor);
            if (goInfo->transport.Timeto4thfloor > 0)
                m_goValue.Transport.StopFrames->push_back(goInfo->transport.Timeto4thfloor);
            if (goInfo->transport.Timeto5thfloor > 0)
                m_goValue.Transport.StopFrames->push_back(goInfo->transport.Timeto5thfloor);
            if (goInfo->transport.Timeto6thfloor > 0)
                m_goValue.Transport.StopFrames->push_back(goInfo->transport.Timeto6thfloor);
            if (goInfo->transport.Timeto7thfloor > 0)
                m_goValue.Transport.StopFrames->push_back(goInfo->transport.Timeto7thfloor);
            if (goInfo->transport.Timeto8thfloor > 0)
                m_goValue.Transport.StopFrames->push_back(goInfo->transport.Timeto8thfloor);
            if (goInfo->transport.Timeto9thfloor > 0)
                m_goValue.Transport.StopFrames->push_back(goInfo->transport.Timeto9thfloor);
            if (goInfo->transport.Timeto10thfloor > 0)
                m_goValue.Transport.StopFrames->push_back(goInfo->transport.Timeto10thfloor);
            if (goInfo->transport.startOpen)
                SetTransportState(GO_STATE_TRANSPORT_STOPPED, goInfo->transport.startOpen - 1);
            else
                SetTransportState(GO_STATE_TRANSPORT_ACTIVE);

            SetGoAnimProgress(animProgress);
            break;
        }
        case GAMEOBJECT_TYPE_FISHINGNODE:
            SetUInt32Value(GAMEOBJECT_LEVEL, 1);
            SetGoAnimProgress(255);
            break;
        case GAMEOBJECT_TYPE_TRAP:
            if (GetGOInfo()->trap.stealthed)
            {
                m_stealth.AddFlag(STEALTH_TRAP);
                m_stealth.AddValue(STEALTH_TRAP, 70);
            }

            if (GetGOInfo()->trap.stealthAffected)
            {
                m_invisibility.AddFlag(INVISIBILITY_TRAP);
                m_invisibility.AddValue(INVISIBILITY_TRAP, 300);
            }
            break;
        default:
            SetGoAnimProgress(animProgress);
            break;
    }

    if (gameObjectAddon && gameObjectAddon->InvisibilityValue)
    {
        m_invisibility.AddFlag(gameObjectAddon->invisibilityType);
        m_invisibility.AddValue(gameObjectAddon->invisibilityType, gameObjectAddon->InvisibilityValue);
    }

    if (gameObjectAddon && gameObjectAddon->WorldEffectID)
    {
        m_updateFlag |= UPDATEFLAG_GAMEOBJECT;
        SetWorldEffectID(gameObjectAddon->WorldEffectID);
    }

    LastUsedScriptID = GetGOInfo()->ScriptId;
    AIM_Initialize();

    // Initialize loot duplicate count depending on raid difficulty
    if (map->Is25ManRaid())
        loot.maxDuplicates = 3;

    if (uint32 linkedEntry = GetGOInfo()->GetLinkedGameObjectEntry())
    {
        if (GameObject* linkedGo = GameObject::CreateGameObject(linkedEntry, map, pos, rotation, 255, GO_STATE_READY))
        {
            SetLinkedTrap(linkedGo);
            if (!map->AddToMap(linkedGo))
                delete linkedGo;
        }
    }

    return true;
}

GameObject* GameObject::CreateGameObject(uint32 entry, Map* map, Position const& pos, QuaternionData const& rotation, uint32 animProgress, GOState goState, uint32 artKit /*= 0*/)
{
    GameObjectTemplate const* goInfo = sObjectMgr->GetGameObjectTemplate(entry);
    if (!goInfo)
        return nullptr;

    GameObject* go = new GameObject();
    if (!go->Create(entry, map, pos, rotation, animProgress, goState, artKit))
    {
        delete go;
        return nullptr;
    }

    return go;
}

GameObject* GameObject::CreateGameObjectFromDB(ObjectGuid::LowType spawnId, Map* map, bool addToMap /*= true*/)
{
    GameObject* go = new GameObject();
    if (!go->LoadGameObjectFromDB(spawnId, map, addToMap))
    {
        delete go;
        return nullptr;
    }

    return go;
}

void GameObject::Update(uint32 diff)
{
    if (AI())
        AI()->UpdateAI(diff);
    else if (!AIM_Initialize())
        TC_LOG_ERROR("misc", "Could not initialize GameObjectAI");

    switch (m_lootState)
    {
        case GO_NOT_READY:
        {
            switch (GetGoType())
            {
                case GAMEOBJECT_TYPE_TRAP:
                {
                    // Arming Time for GAMEOBJECT_TYPE_TRAP (6)
                    GameObjectTemplate const* goInfo = GetGOInfo();
                    // Bombs
                    if (goInfo->trap.charges == 2)
                        // Hardcoded tooltip value
                        m_cooldownTime = time(NULL) + 10;
                    else if (Unit* owner = GetOwner())
                        if (owner->IsInCombat())
                            m_cooldownTime = time(NULL) + goInfo->trap.startDelay;

                    SetLootState(GO_READY);
                    break;
                }
                case GAMEOBJECT_TYPE_TRANSPORT:
                {
                    if (!m_goValue.Transport.AnimationInfo)
                        break;

                    if (GetGoState() == GO_STATE_TRANSPORT_ACTIVE)
                    {
                        m_goValue.Transport.PathProgress += diff;
                        /* TODO: Fix movement in unloaded grid - currently GO will just disappear
                        uint32 timer = m_goValue.Transport.PathProgress % GetTransportPeriod();
                        TransportAnimationEntry const* node = m_goValue.Transport.AnimationInfo->GetAnimNode(timer);
                        if (node && m_goValue.Transport.CurrentSeg != node->TimeSeg)
                        {
                            m_goValue.Transport.CurrentSeg = node->TimeSeg;

                            G3D::Quat rotation;
                            if (TransportRotationEntry const* rot = m_goValue.Transport.AnimationInfo->GetAnimRotation(timer))
                                rotation = G3D::Quat(rot->X, rot->Y, rot->Z, rot->W);

                            G3D::Vector3 pos = rotation.toRotationMatrix()
                                             * G3D::Matrix3::fromEulerAnglesZYX(GetOrientation(), 0.0f, 0.0f)
                                             * G3D::Vector3(node->X, node->Y, node->Z);

                            pos += G3D::Vector3(GetStationaryX(), GetStationaryY(), GetStationaryZ());

                            G3D::Vector3 src(GetPositionX(), GetPositionY(), GetPositionZ());

                            TC_LOG_DEBUG("misc", "Src: %s Dest: %s", src.toString().c_str(), pos.toString().c_str());

                            GetMap()->GameObjectRelocation(this, pos.x, pos.y, pos.z, GetOrientation());
                        }
                        */

                        if (!m_goValue.Transport.StopFrames->empty())
                        {
                            uint32 visualStateBefore = (m_goValue.Transport.StateUpdateTimer / 20000) & 1;
                            m_goValue.Transport.StateUpdateTimer += diff;
                            uint32 visualStateAfter = (m_goValue.Transport.StateUpdateTimer / 20000) & 1;
                            if (visualStateBefore != visualStateAfter)
                            {
                                ForceValuesUpdateAtIndex(GAMEOBJECT_LEVEL);
                                ForceValuesUpdateAtIndex(GAMEOBJECT_BYTES_1);
                            }
                        }
                    }
                    break;
                }
                case GAMEOBJECT_TYPE_FISHINGNODE:
                {
                    // fishing code (bobber ready)
                    if (time(NULL) > m_respawnTime - FISHING_BOBBER_READY_TIME)
                    {
                        // splash bobber (bobber ready now)
                        Unit* caster = GetOwner();
                        if (caster && caster->GetTypeId() == TYPEID_PLAYER)
                        {
                            SetGoState(GO_STATE_ACTIVE);
                            SetUInt32Value(GAMEOBJECT_FLAGS, GO_FLAG_NODESPAWN);

                            UpdateData udata(caster->GetMapId());
                            WorldPacket packet;
                            BuildValuesUpdateBlockForPlayer(&udata, caster->ToPlayer());
                            udata.BuildPacket(&packet);
                            caster->ToPlayer()->SendDirectMessage(&packet);

                            SendCustomAnim(GetGoAnimProgress());
                        }

                        m_lootState = GO_READY;                 // can be successfully open with some chance
                    }
                    return;
                }
                default:
                    m_lootState = GO_READY;                         // for other GOis same switched without delay to GO_READY
                    break;
            }
            // NO BREAK for switch (m_lootState)
        }
        case GO_READY:
        {
            if (m_respawnTime > 0)                          // timer on
            {
                time_t now = time(NULL);
                if (m_respawnTime <= now)            // timer expired
                {
                    ObjectGuid dbtableHighGuid = ObjectGuid::Create<HighGuid::GameObject>(GetMapId(), GetEntry(), m_spawnId);
                    time_t linkedRespawntime = GetMap()->GetLinkedRespawnTime(dbtableHighGuid);
                    if (linkedRespawntime)             // Can't respawn, the master is dead
                    {
                        ObjectGuid targetGuid = sObjectMgr->GetLinkedRespawnGuid(dbtableHighGuid);
                        if (targetGuid == dbtableHighGuid) // if linking self, never respawn (check delayed to next day)
                            SetRespawnTime(DAY);
                        else
                            m_respawnTime = (now > linkedRespawntime ? now : linkedRespawntime) + urand(5, MINUTE); // else copy time from master and add a little
                        SaveRespawnTime(); // also save to DB immediately
                        return;
                    }

                    m_respawnTime = 0;
                    m_SkillupList.clear();
                    m_usetimes = 0;

                    // If nearby linked trap exists, respawn it
                    if (GameObject* linkedTrap = GetLinkedTrap())
                        linkedTrap->SetLootState(GO_READY);

                    switch (GetGoType())
                    {
                        case GAMEOBJECT_TYPE_FISHINGNODE:   //  can't fish now
                        {
                            Unit* caster = GetOwner();
                            if (caster && caster->GetTypeId() == TYPEID_PLAYER)
                            {
                                caster->ToPlayer()->RemoveGameObject(this, false);
                                caster->ToPlayer()->SendDirectMessage(WorldPackets::GameObject::FishEscaped().Write());
                            }
                            // can be delete
                            m_lootState = GO_JUST_DEACTIVATED;
                            return;
                        }
                        case GAMEOBJECT_TYPE_DOOR:
                        case GAMEOBJECT_TYPE_BUTTON:
                            // We need to open doors if they are closed (add there another condition if this code breaks some usage, but it need to be here for battlegrounds)
                            if (GetGoState() != GO_STATE_READY)
                                ResetDoorOrButton();
                            break;
                        case GAMEOBJECT_TYPE_FISHINGHOLE:
                            // Initialize a new max fish count on respawn
                            m_goValue.FishingHole.MaxOpens = urand(GetGOInfo()->fishingHole.minRestock, GetGOInfo()->fishingHole.maxRestock);
                            break;
                        default:
                            break;
                    }

                    // Despawn timer
                    if (!m_spawnedByDefault)
                    {
                        // Can be despawned or destroyed
                        SetLootState(GO_JUST_DEACTIVATED);
                        return;
                    }

                    // Respawn timer
                    uint32 poolid = GetSpawnId() ? sPoolMgr->IsPartOfAPool<GameObject>(GetSpawnId()) : 0;
                    if (poolid)
                        sPoolMgr->UpdatePool<GameObject>(poolid, GetSpawnId());
                    else
                        GetMap()->AddToMap(this);
                }
            }

            if (isSpawned())
            {
                GameObjectTemplate const* goInfo = GetGOInfo();
                if (goInfo->type == GAMEOBJECT_TYPE_TRAP)
                {
                    if (m_cooldownTime >= time(NULL))
                        break;

                    // Type 2 (bomb) does not need to be triggered by a unit and despawns after casting its spell.
                    if (goInfo->trap.charges == 2)
                    {
                        SetLootState(GO_ACTIVATED);
                        break;
                    }

                    // Type 0 despawns after being triggered, type 1 does not.
                    /// @todo This is activation radius. Casting radius must be selected from spell data.
                    float radius;
                    if (!goInfo->trap.radius)
                    {
                        // Battleground traps: data2 == 0 && data5 == 3
                        if (goInfo->trap.cooldown != 3)
                            break;

                        radius = 3.f;
                    }
                    else
                        radius = goInfo->trap.radius / 2.f;

                    // Pointer to appropriate target if found any
                    Unit* target = nullptr;

                    /// @todo this hack with search required until GO casting not implemented
                    if (Unit* owner = GetOwner())
                    {
                        // Hunter trap: Search units which are unfriendly to the trap's owner
                        Trinity::NearestAttackableNoTotemUnitInObjectRangeCheck checker(this, owner, radius);
                        Trinity::UnitLastSearcher<Trinity::NearestAttackableNoTotemUnitInObjectRangeCheck> searcher(this, target, checker);
                        Cell::VisitAllObjects(this, searcher, radius);
                    }
                    else
                    {
                        // Environmental trap: Any player
                        Player* player = nullptr;
                        Trinity::AnyPlayerInObjectRangeCheck checker(this, radius);
                        Trinity::PlayerSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(this, player, checker);
                        Cell::VisitWorldObjects(this, searcher, radius);
                        target = player;
                    }

                    if (target)
                        SetLootState(GO_ACTIVATED, target);

                }
                else if (uint32 max_charges = goInfo->GetCharges())
                {
                    if (m_usetimes >= max_charges)
                    {
                        m_usetimes = 0;
                        SetLootState(GO_JUST_DEACTIVATED);      // can be despawned or destroyed
                    }
                }
            }

            break;
        }
        case GO_ACTIVATED:
        {
            switch (GetGoType())
            {
                case GAMEOBJECT_TYPE_DOOR:
                case GAMEOBJECT_TYPE_BUTTON:
                    if (m_cooldownTime && (m_cooldownTime < time(NULL)))
                        ResetDoorOrButton();
                    break;
                case GAMEOBJECT_TYPE_GOOBER:
                    if (m_cooldownTime < time(NULL))
                    {
                        RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);

                        SetLootState(GO_JUST_DEACTIVATED);
                        m_cooldownTime = 0;
                    }
                    break;
                case GAMEOBJECT_TYPE_CHEST:
                    if (m_groupLootTimer)
                    {
                        if (m_groupLootTimer <= diff)
                        {
                            if (Group* group = sGroupMgr->GetGroupByGUID(lootingGroupLowGUID))
                                group->EndRoll(&loot);

                            m_groupLootTimer = 0;
                            lootingGroupLowGUID.Clear();
                        }
                        else
                            m_groupLootTimer -= diff;
                    }
                    break;
                case GAMEOBJECT_TYPE_TRAP:
                {
                    GameObjectTemplate const* goInfo = GetGOInfo();
                    if (goInfo->trap.charges == 2 && goInfo->trap.spell)
                    {
                        /// @todo nullptr target won't work for target type 1
                        CastSpell(nullptr, goInfo->trap.spell);
                        SetLootState(GO_JUST_DEACTIVATED);
                    }
                    else if (Unit* target = ObjectAccessor::GetUnit(*this, m_lootStateUnitGUID))
                    {
                        // Some traps do not have a spell but should be triggered
                        if (goInfo->trap.spell)
                            CastSpell(target, goInfo->trap.spell);

                        // Template value or 4 seconds
                        m_cooldownTime = time(NULL) + (goInfo->trap.cooldown ? goInfo->trap.cooldown : uint32(4));

                        if (goInfo->trap.charges == 1)
                            SetLootState(GO_JUST_DEACTIVATED);
                        else if (!goInfo->trap.charges)
                            SetLootState(GO_READY);

                        // Battleground gameobjects have data2 == 0 && data5 == 3
                        if (!goInfo->trap.radius && goInfo->trap.cooldown == 3)
                            if (Player* player = target->ToPlayer())
                                if (Battleground* bg = player->GetBattleground())
                                    bg->HandleTriggerBuff(GetGUID());
                    }
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case GO_JUST_DEACTIVATED:
        {
            // If nearby linked trap exists, despawn it
            if (GameObject* linkedTrap = GetLinkedTrap())
                linkedTrap->SetLootState(GO_JUST_DEACTIVATED);

            //if Gameobject should cast spell, then this, but some GOs (type = 10) should be destroyed
            if (GetGoType() == GAMEOBJECT_TYPE_GOOBER)
            {
                uint32 spellId = GetGOInfo()->goober.spell;

                if (spellId)
                {
                    for (GuidSet::const_iterator it = m_unique_users.begin(); it != m_unique_users.end(); ++it)
                        // m_unique_users can contain only player GUIDs
                        if (Player* owner = ObjectAccessor::GetPlayer(*this, *it))
                            owner->CastSpell(owner, spellId, false);

                    m_unique_users.clear();
                    m_usetimes = 0;
                }

                SetGoState(GO_STATE_READY);

                //any return here in case battleground traps
                if (GameObjectTemplateAddon const* addon = GetTemplateAddon())
                    if (addon->flags & GO_FLAG_NODESPAWN)
                        return;
            }

            loot.clear();

            //! If this is summoned by a spell with ie. SPELL_EFFECT_SUMMON_OBJECT_WILD, with or without owner, we check respawn criteria based on spell
            //! The GetOwnerGUID() check is mostly for compatibility with hacky scripts - 99% of the time summoning should be done trough spells.
            if (GetSpellId() || !GetOwnerGUID().IsEmpty())
            {
                SetRespawnTime(0);
                Delete();
                return;
            }

            SetLootState(GO_READY);

            //burning flags in some battlegrounds, if you find better condition, just add it
            if (GetGOInfo()->IsDespawnAtAction() || GetGoAnimProgress() > 0)
            {
                SendGameObjectDespawn();
                //reset flags
                if (GameObjectTemplateAddon const* addon = GetTemplateAddon())
                    SetUInt32Value(GAMEOBJECT_FLAGS, addon->flags);
            }

            if (!m_respawnDelayTime)
                return;

            if (!m_spawnedByDefault)
            {
                m_respawnTime = 0;
                UpdateObjectVisibility();
                return;
            }

            m_respawnTime = time(NULL) + m_respawnDelayTime;

            // if option not set then object will be saved at grid unload
            if (sWorld->getBoolConfig(CONFIG_SAVE_RESPAWN_TIME_IMMEDIATELY))
                SaveRespawnTime();

            UpdateObjectVisibility();

            break;
        }
    }
    sScriptMgr->OnGameObjectUpdate(this, diff);
}

void GameObject::Refresh()
{
    // Do not refresh despawned GO from spellcast (GO's from spellcast are destroyed after despawn)
    if (m_respawnTime > 0 && m_spawnedByDefault)
        return;

    if (isSpawned())
        GetMap()->AddToMap(this);
}

void GameObject::AddUniqueUse(Player* player)
{
    AddUse();
    m_unique_users.insert(player->GetGUID());
}

void GameObject::Delete()
{
    SetLootState(GO_NOT_READY);
    RemoveFromOwner();

    SendGameObjectDespawn();

    SetGoState(GO_STATE_READY);

    if (GameObjectTemplateAddon const* addon = GetTemplateAddon())
        SetUInt32Value(GAMEOBJECT_FLAGS, addon->flags);

    uint32 poolid = GetSpawnId() ? sPoolMgr->IsPartOfAPool<GameObject>(GetSpawnId()) : 0;
    if (poolid)
        sPoolMgr->UpdatePool<GameObject>(poolid, GetSpawnId());
    else
        AddObjectToRemoveList();
}

void GameObject::SendGameObjectDespawn()
{
    WorldPackets::GameObject::GameObjectDespawn packet;
    packet.ObjectGUID = GetGUID();
    SendMessageToSet(packet.Write(), true);
}

void GameObject::getFishLoot(Loot* fishloot, Player* loot_owner)
{
    fishloot->clear();

    uint32 zone, subzone;
    uint32 defaultzone = 1;
    GetZoneAndAreaId(zone, subzone);

    // if subzone loot exist use it
    fishloot->FillLoot(subzone, LootTemplates_Fishing, loot_owner, true, true);
    if (fishloot->empty())  //use this becase if zone or subzone has set LOOT_MODE_JUNK_FISH,Even if no normal drop, fishloot->FillLoot return true. it wrong.
    {
        //subzone no result,use zone loot
        fishloot->FillLoot(zone, LootTemplates_Fishing, loot_owner, true, true);
        //use zone 1 as default, somewhere fishing got nothing,becase subzone and zone not set, like Off the coast of Storm Peaks.
        if (fishloot->empty())
            fishloot->FillLoot(defaultzone, LootTemplates_Fishing, loot_owner, true, true);
    }
}

void GameObject::getFishLootJunk(Loot* fishloot, Player* loot_owner)
{
    fishloot->clear();

    uint32 zone, subzone;
    uint32 defaultzone = 1;
    GetZoneAndAreaId(zone, subzone);

    // if subzone loot exist use it
    fishloot->FillLoot(subzone, LootTemplates_Fishing, loot_owner, true, true, LOOT_MODE_JUNK_FISH);
    if (fishloot->empty())  //use this becase if zone or subzone has normal mask drop, then fishloot->FillLoot return true.
    {
        //use zone loot
        fishloot->FillLoot(zone, LootTemplates_Fishing, loot_owner, true, true, LOOT_MODE_JUNK_FISH);
        if (fishloot->empty())
            //use zone 1 as default
            fishloot->FillLoot(defaultzone, LootTemplates_Fishing, loot_owner, true, true, LOOT_MODE_JUNK_FISH);
    }
}

void GameObject::SaveToDB()
{
    // this should only be used when the gameobject has already been loaded
    // preferably after adding to map, because mapid may not be valid otherwise
    GameObjectData const* data = sObjectMgr->GetGOData(m_spawnId);
    if (!data)
    {
        TC_LOG_ERROR("misc", "GameObject::SaveToDB failed, cannot get gameobject data!");
        return;
    }

    SaveToDB(GetMapId(), data->spawnMask);
}

void GameObject::SaveToDB(uint32 mapid, uint64 spawnMask)
{
    const GameObjectTemplate* goI = GetGOInfo();

    if (!goI)
        return;

    if (!m_spawnId)
        m_spawnId = sObjectMgr->GenerateGameObjectSpawnId();

    // update in loaded data (changing data only in this place)
    GameObjectData& data = sObjectMgr->NewGOData(m_spawnId);

    // data->guid = guid must not be updated at save
    data.id = GetEntry();
    data.mapid = mapid;
    data.posX = GetPositionX();
    data.posY = GetPositionY();
    data.posZ = GetPositionZ();
    data.orientation = GetOrientation();
    data.rotation = m_worldRotation;
    data.spawntimesecs = m_spawnedByDefault ? m_respawnDelayTime : -(int32)m_respawnDelayTime;
    data.animprogress = GetGoAnimProgress();
    data.go_state = GetGoState();
    data.spawnMask = spawnMask;
    data.artKit = GetGoArtKit();

    data.phaseId = GetDBPhase() > 0 ? GetDBPhase() : data.phaseId;
    data.phaseGroup = GetDBPhase() < 0 ? -GetDBPhase() : data.phaseGroup;

    // Update in DB
    SQLTransaction trans = WorldDatabase.BeginTransaction();

    uint8 index = 0;

    PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_GAMEOBJECT);
    stmt->setUInt64(0, m_spawnId);
    trans->Append(stmt);

    stmt = WorldDatabase.GetPreparedStatement(WORLD_INS_GAMEOBJECT);
    stmt->setUInt64(index++, m_spawnId);
    stmt->setUInt32(index++, GetEntry());
    stmt->setUInt16(index++, uint16(mapid));
    stmt->setUInt64(index++, spawnMask);
    stmt->setUInt32(index++, data.phaseId);
    stmt->setUInt32(index++, data.phaseGroup);
    stmt->setFloat(index++, GetPositionX());
    stmt->setFloat(index++, GetPositionY());
    stmt->setFloat(index++, GetPositionZ());
    stmt->setFloat(index++, GetOrientation());
    stmt->setFloat(index++, m_worldRotation.x);
    stmt->setFloat(index++, m_worldRotation.y);
    stmt->setFloat(index++, m_worldRotation.z);
    stmt->setFloat(index++, m_worldRotation.w);
    stmt->setInt32(index++, int32(m_respawnDelayTime));
    stmt->setUInt8(index++, GetGoAnimProgress());
    stmt->setUInt8(index++, uint8(GetGoState()));
    trans->Append(stmt);

    WorldDatabase.CommitTransaction(trans);
}

bool GameObject::LoadGameObjectFromDB(ObjectGuid::LowType spawnId, Map* map, bool addToMap)
{
    GameObjectData const* data = sObjectMgr->GetGOData(spawnId);
    if (!data)
    {
        TC_LOG_ERROR("sql.sql", "Gameobject (GUID: " UI64FMTD ") not found in table `gameobject`, can't load. ", spawnId);
        return false;
    }

    uint32 entry = data->id;
    //uint32 map_id = data->mapid;                          // already used before call
    Position pos(data->posX, data->posY, data->posZ, data->orientation);

    uint32 animprogress = data->animprogress;
    GOState go_state = data->go_state;
    uint32 artKit = data->artKit;

    m_spawnId = spawnId;
    if (!Create(entry, map, pos, data->rotation, animprogress, go_state, artKit))
        return false;

    PhasingHandler::InitDbPhaseShift(GetPhaseShift(), data->phaseUseFlags, data->phaseId, data->phaseGroup);
    PhasingHandler::InitDbVisibleMapId(GetPhaseShift(), data->terrainSwapMap);

    if (data->spawntimesecs >= 0)
    {
        m_spawnedByDefault = true;

        if (!GetGOInfo()->GetDespawnPossibility() && !GetGOInfo()->IsDespawnAtAction())
        {
            SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NODESPAWN);
            m_respawnDelayTime = 0;
            m_respawnTime = 0;
        }
        else
        {
            m_respawnDelayTime = data->spawntimesecs;
            m_respawnTime = GetMap()->GetGORespawnTime(m_spawnId);

            // ready to respawn
            if (m_respawnTime && m_respawnTime <= time(nullptr))
            {
                m_respawnTime = 0;
                GetMap()->RemoveGORespawnTime(m_spawnId);
            }
        }
    }
    else
    {
        m_spawnedByDefault = false;
        m_respawnDelayTime = -data->spawntimesecs;
        m_respawnTime = 0;
    }

    m_goData = data;

    if (addToMap && !GetMap()->AddToMap(this))
        return false;

    return true;
}

void GameObject::DeleteFromDB()
{
    GetMap()->RemoveGORespawnTime(m_spawnId);
    sObjectMgr->DeleteGOData(m_spawnId);

    PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_GAMEOBJECT);

    stmt->setUInt64(0, m_spawnId);

    WorldDatabase.Execute(stmt);

    stmt = WorldDatabase.GetPreparedStatement(WORLD_DEL_EVENT_GAMEOBJECT);

    stmt->setUInt64(0, m_spawnId);

    WorldDatabase.Execute(stmt);
}

/*********************************************************/
/***                    QUEST SYSTEM                   ***/
/*********************************************************/
bool GameObject::hasQuest(uint32 quest_id) const
{
    QuestRelationBounds qr = sObjectMgr->GetGOQuestRelationBounds(GetEntry());
    for (QuestRelations::const_iterator itr = qr.first; itr != qr.second; ++itr)
    {
        if (itr->second == quest_id)
            return true;
    }
    return false;
}

bool GameObject::hasInvolvedQuest(uint32 quest_id) const
{
    QuestRelationBounds qir = sObjectMgr->GetGOQuestInvolvedRelationBounds(GetEntry());
    for (QuestRelations::const_iterator itr = qir.first; itr != qir.second; ++itr)
    {
        if (itr->second == quest_id)
            return true;
    }
    return false;
}

bool GameObject::IsTransport() const
{
    // If something is marked as a transport, don't transmit an out of range packet for it.
    GameObjectTemplate const* gInfo = GetGOInfo();
    if (!gInfo)
        return false;

    return gInfo->type == GAMEOBJECT_TYPE_TRANSPORT || gInfo->type == GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT;
}

// is Dynamic transport = non-stop Transport
bool GameObject::IsDynTransport() const
{
    // If something is marked as a transport, don't transmit an out of range packet for it.
    GameObjectTemplate const* gInfo = GetGOInfo();
    if (!gInfo)
        return false;

    return gInfo->type == GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT || (gInfo->type == GAMEOBJECT_TYPE_TRANSPORT && m_goValue.Transport.StopFrames->empty());
}

bool GameObject::IsDestructibleBuilding() const
{
    GameObjectTemplate const* gInfo = GetGOInfo();
    if (!gInfo)
        return false;

    return gInfo->type == GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING;
}

Unit* GameObject::GetOwner() const
{
    return ObjectAccessor::GetUnit(*this, GetOwnerGUID());
}

void GameObject::SaveRespawnTime()
{
    if (m_goData && m_goData->dbData && m_respawnTime > time(NULL) && m_spawnedByDefault)
        GetMap()->SaveGORespawnTime(m_spawnId, m_respawnTime);
}

bool GameObject::IsNeverVisibleFor(WorldObject const* seer) const
{
    if (WorldObject::IsNeverVisibleFor(seer))
        return true;

    if (GetGoType() == GAMEOBJECT_TYPE_SPELL_FOCUS && GetGOInfo()->spellFocus.serverOnly == 1)
        return true;

    if (!GetUInt32Value(GAMEOBJECT_DISPLAYID))
        return true;

    return false;
}

bool GameObject::IsAlwaysVisibleFor(WorldObject const* seer) const
{
    if (WorldObject::IsAlwaysVisibleFor(seer))
        return true;

    if (IsTransport() || IsDestructibleBuilding())
        return true;

    if (!seer)
        return false;

    // Always seen by owner and friendly units
    if (!GetOwnerGUID().IsEmpty())
    {
        if (seer->GetGUID() == GetOwnerGUID())
            return true;

        Unit* owner = GetOwner();
        if (Unit const* unitSeer = seer->ToUnit())
            if (owner && owner->IsFriendlyTo(unitSeer))
                return true;
    }

    return false;
}

bool GameObject::IsInvisibleDueToDespawn() const
{
    if (WorldObject::IsInvisibleDueToDespawn())
        return true;

    // Despawned
    if (!isSpawned())
        return true;

    return false;
}

uint8 GameObject::GetLevelForTarget(WorldObject const* target) const
{
    if (Unit* owner = GetOwner())
        return owner->GetLevelForTarget(target);

    return 1;
}

void GameObject::Respawn()
{
    if (m_spawnedByDefault && m_respawnTime > 0)
    {
        m_respawnTime = time(NULL);
        GetMap()->RemoveGORespawnTime(m_spawnId);
    }
}

bool GameObject::ActivateToQuest(Player* target) const
{
    if (target->HasQuestForGO(GetEntry()))
        return true;

    if (!sObjectMgr->IsGameObjectForQuests(GetEntry()))
        return false;

    switch (GetGoType())
    {
        case GAMEOBJECT_TYPE_QUESTGIVER:
        {
            GameObject* go = const_cast<GameObject*>(this);
            QuestGiverStatus questStatus = target->GetQuestDialogStatus(go);
            if (questStatus > DIALOG_STATUS_UNAVAILABLE)
                return true;
            break;
        }
        case GAMEOBJECT_TYPE_CHEST:
        {
            // scan GO chest with loot including quest items
            if (LootTemplates_Gameobject.HaveQuestLootForPlayer(GetGOInfo()->GetLootId(), target))
            {
                if (Battleground const* bg = target->GetBattleground())
                    return bg->CanActivateGO(GetEntry(), target->GetTeam());
                return true;
            }
            break;
        }
        case GAMEOBJECT_TYPE_GENERIC:
        {
            if (target->GetQuestStatus(GetGOInfo()->generic.questID) == QUEST_STATUS_INCOMPLETE)
                return true;
            break;
        }
        case GAMEOBJECT_TYPE_GOOBER:
        {
            if (target->GetQuestStatus(GetGOInfo()->goober.questID) == QUEST_STATUS_INCOMPLETE)
                return true;
            break;
        }
        default:
            break;
    }

    return false;
}

void GameObject::TriggeringLinkedGameObject(uint32 trapEntry, Unit* target)
{
    GameObjectTemplate const* trapInfo = sObjectMgr->GetGameObjectTemplate(trapEntry);
    if (!trapInfo || trapInfo->type != GAMEOBJECT_TYPE_TRAP)
        return;

    SpellInfo const* trapSpell = sSpellMgr->GetSpellInfo(trapInfo->trap.spell);
    if (!trapSpell)                                          // checked at load already
        return;

    if (GameObject* trapGO = GetLinkedTrap())
        trapGO->CastSpell(target, trapSpell->Id);
}

GameObject* GameObject::LookupFishingHoleAround(float range)
{
    GameObject* ok = nullptr;
    Trinity::NearestGameObjectFishingHole u_check(*this, range);
    Trinity::GameObjectSearcher<Trinity::NearestGameObjectFishingHole> checker(this, ok, u_check);
    Cell::VisitGridObjects(this, checker, range);
    return ok;
}

void GameObject::ResetDoorOrButton()
{
    if (m_lootState == GO_READY || m_lootState == GO_JUST_DEACTIVATED)
        return;

    RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
    SetGoState(m_prevGoState);

    SetLootState(GO_JUST_DEACTIVATED);
    m_cooldownTime = 0;
}

void GameObject::UseDoorOrButton(uint32 time_to_restore, bool alternative /* = false */, Unit* user /*=nullptr*/)
{
    if (m_lootState != GO_READY)
        return;

    if (!time_to_restore)
        time_to_restore = GetGOInfo()->GetAutoCloseTime();

    SwitchDoorOrButton(true, alternative);
    SetLootState(GO_ACTIVATED, user);

    m_cooldownTime = time_to_restore ? (time(NULL) + time_to_restore) : 0;
}

void GameObject::SetGoArtKit(uint8 kit)
{
    SetByteValue(GAMEOBJECT_BYTES_1, 2, kit);
    GameObjectData* data = const_cast<GameObjectData*>(sObjectMgr->GetGOData(m_spawnId));
    if (data)
        data->artKit = kit;
}

void GameObject::SetGoArtKit(uint8 artkit, GameObject* go, ObjectGuid::LowType lowguid)
{
    const GameObjectData* data = nullptr;
    if (go)
    {
        go->SetGoArtKit(artkit);
        data = go->GetGOData();
    }
    else if (lowguid)
        data = sObjectMgr->GetGOData(lowguid);

    if (data)
        const_cast<GameObjectData*>(data)->artKit = artkit;
}

void GameObject::SwitchDoorOrButton(bool activate, bool alternative /* = false */)
{
    if (activate)
        SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
    else
        RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);

    if (GetGoState() == GO_STATE_READY)                      //if closed -> open
        SetGoState(alternative ? GO_STATE_ACTIVE_ALTERNATIVE : GO_STATE_ACTIVE);
    else                                                    //if open -> close
        SetGoState(GO_STATE_READY);
}

void GameObject::Use(Unit* user)
{
    // by default spell caster is user
    Unit* spellCaster = user;
    uint32 spellId = 0;
    bool triggered = false;

    if (Player* playerUser = user->ToPlayer())
    {
        if (sScriptMgr->OnGossipHello(playerUser, this))
            return;

        if (AI()->GossipHello(playerUser, true))
            return;
    }

    // If cooldown data present in template
    if (uint32 cooldown = GetGOInfo()->GetCooldown())
    {
        if (m_cooldownTime > sWorld->GetGameTime())
            return;

        m_cooldownTime = sWorld->GetGameTime() + cooldown;
    }

    switch (GetGoType())
    {
        case GAMEOBJECT_TYPE_DOOR:                          //0
        case GAMEOBJECT_TYPE_BUTTON:                        //1
            //doors/buttons never really despawn, only reset to default state/flags
            UseDoorOrButton(0, false, user);
            return;
        case GAMEOBJECT_TYPE_QUESTGIVER:                    //2
        {
            if (user->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = user->ToPlayer();

            player->PrepareGossipMenu(this, GetGOInfo()->questgiver.gossipID, true);
            player->SendPreparedGossip(this);
            return;
        }
        case GAMEOBJECT_TYPE_TRAP:                          //6
        {
            GameObjectTemplate const* goInfo = GetGOInfo();
            if (goInfo->trap.spell)
                CastSpell(user, goInfo->trap.spell);

            m_cooldownTime = time(NULL) + (goInfo->trap.cooldown ? goInfo->trap.cooldown :  uint32(4));   // template or 4 seconds

            if (goInfo->trap.charges == 1)         // Deactivate after trigger
                SetLootState(GO_JUST_DEACTIVATED);

            return;
        }
        //Sitting: Wooden bench, chairs enzz
        case GAMEOBJECT_TYPE_CHAIR:                         //7
        {
            GameObjectTemplate const* info = GetGOInfo();
            if (!info)
                return;

            if (user->GetTypeId() != TYPEID_PLAYER)
                return;

            if (ChairListSlots.empty())        // this is called once at first chair use to make list of available slots
            {
                if (info->chair.chairslots > 0)     // sometimes chairs in DB have error in fields and we dont know number of slots
                    for (uint32 i = 0; i < info->chair.chairslots; ++i)
                        ChairListSlots[i].Clear(); // Last user of current slot set to 0 (none sit here yet)
                else
                    ChairListSlots[0].Clear();     // error in DB, make one default slot
            }

            Player* player = user->ToPlayer();

            // a chair may have n slots. we have to calculate their positions and teleport the player to the nearest one

            float lowestDist = DEFAULT_VISIBILITY_DISTANCE;

            uint32 nearest_slot = 0;
            float x_lowest = GetPositionX();
            float y_lowest = GetPositionY();

            // the object orientation + 1/2 pi
            // every slot will be on that straight line
            float orthogonalOrientation = GetOrientation() + float(M_PI) * 0.5f;
            // find nearest slot
            bool found_free_slot = false;
            for (ChairSlotAndUser::iterator itr = ChairListSlots.begin(); itr != ChairListSlots.end(); ++itr)
            {
                // the distance between this slot and the center of the go - imagine a 1D space
                float relativeDistance = (info->size*itr->first) - (info->size*(info->chair.chairslots - 1) / 2.0f);

                float x_i = GetPositionX() + relativeDistance * std::cos(orthogonalOrientation);
                float y_i = GetPositionY() + relativeDistance * std::sin(orthogonalOrientation);

                if (!itr->second.IsEmpty())
                {
                    if (Player* ChairUser = ObjectAccessor::FindPlayer(itr->second))
                    {
                        if (ChairUser->IsSitState() && ChairUser->GetStandState() != UNIT_STAND_STATE_SIT && ChairUser->GetExactDist2d(x_i, y_i) < 0.1f)
                            continue;        // This seat is already occupied by ChairUser. NOTE: Not sure if the ChairUser->GetStandState() != UNIT_STAND_STATE_SIT check is required.
                        else
                            itr->second.Clear(); // This seat is unoccupied.
                    }
                    else
                        itr->second.Clear();     // The seat may of had an occupant, but they're offline.
                }

                found_free_slot = true;

                // calculate the distance between the player and this slot
                float thisDistance = player->GetDistance2d(x_i, y_i);

                if (thisDistance <= lowestDist)
                {
                    nearest_slot = itr->first;
                    lowestDist = thisDistance;
                    x_lowest = x_i;
                    y_lowest = y_i;
                }
            }

            if (found_free_slot)
            {
                ChairSlotAndUser::iterator itr = ChairListSlots.find(nearest_slot);
                if (itr != ChairListSlots.end())
                {
                    itr->second = player->GetGUID(); //this slot in now used by player
                    player->TeleportTo(GetMapId(), x_lowest, y_lowest, GetPositionZ(), GetOrientation(), TELE_TO_NOT_LEAVE_TRANSPORT | TELE_TO_NOT_LEAVE_COMBAT | TELE_TO_NOT_UNSUMMON_PET);
                    player->SetStandState(UnitStandStateType(UNIT_STAND_STATE_SIT_LOW_CHAIR + info->chair.chairheight));
                    return;
                }
            }

            return;
        }
        //big gun, its a spell/aura
        case GAMEOBJECT_TYPE_GOOBER:                        //10
        {
            GameObjectTemplate const* info = GetGOInfo();

            if (Player* player = user->ToPlayer())
            {
                if (info->goober.pageID)                    // show page...
                {
                    WorldPackets::GameObject::PageText data;
                    data.GameObjectGUID = GetGUID();
                    player->SendDirectMessage(data.Write());
                }
                else if (info->goober.gossipID)
                {
                    player->PrepareGossipMenu(this, info->goober.gossipID);
                    player->SendPreparedGossip(this);
                }

                if (info->goober.eventID)
                {
                    TC_LOG_DEBUG("maps.script", "Goober ScriptStart id %u for GO entry %u (GUID " UI64FMTD ").", info->goober.eventID, GetEntry(), GetSpawnId());
                    GetMap()->ScriptsStart(sEventScripts, info->goober.eventID, player, this);
                    EventInform(info->goober.eventID, user);
                }

                // possible quest objective for active quests
                if (info->goober.questID && sObjectMgr->GetQuestTemplate(info->goober.questID))
                {
                    //Quest require to be active for GO using
                    if (player->GetQuestStatus(info->goober.questID) != QUEST_STATUS_INCOMPLETE)
                        break;
                }

                if (Group* group = player->GetGroup())
                {
                    for (GroupReference const* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
                        if (Player* member = itr->GetSource())
                            if (member->IsAtGroupRewardDistance(this))
                                member->KillCreditGO(info->entry, GetGUID());
                }
                else
                    player->KillCreditGO(info->entry, GetGUID());
            }

            if (uint32 trapEntry = info->goober.linkedTrap)
                TriggeringLinkedGameObject(trapEntry, user);

            SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
            SetLootState(GO_ACTIVATED, user);

            // this appear to be ok, however others exist in addition to this that should have custom (ex: 190510, 188692, 187389)
            if (info->goober.customAnim)
                SendCustomAnim(GetGoAnimProgress());
            else
                SetGoState(GO_STATE_ACTIVE);

            m_cooldownTime = time(NULL) + info->GetAutoCloseTime();

            // cast this spell later if provided
            spellId = info->goober.spell;
            spellCaster = nullptr;

            break;
        }
        case GAMEOBJECT_TYPE_CAMERA:                        //13
        {
            GameObjectTemplate const* info = GetGOInfo();
            if (!info)
                return;

            if (user->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = user->ToPlayer();

            if (info->camera.camera)
                player->SendCinematicStart(info->camera.camera);

            if (info->camera.eventID)
            {
                GetMap()->ScriptsStart(sEventScripts, info->camera.eventID, player, this);
                EventInform(info->camera.eventID, user);
            }

            return;
        }
        //fishing bobber
        case GAMEOBJECT_TYPE_FISHINGNODE:                   //17
        {
            Player* player = user->ToPlayer();
            if (!player)
                return;

            if (player->GetGUID() != GetOwnerGUID())
                return;

            switch (getLootState())
            {
                case GO_READY:                              // ready for loot
                {
                    uint32 zone, subzone;
                    GetZoneAndAreaId(zone, subzone);

                    int32 zone_skill = sObjectMgr->GetFishingBaseSkillLevel(subzone);
                    if (!zone_skill)
                        zone_skill = sObjectMgr->GetFishingBaseSkillLevel(zone);

                    //provide error, no fishable zone or area should be 0
                    if (!zone_skill)
                        TC_LOG_ERROR("sql.sql", "Fishable areaId %u are not properly defined in `skill_fishing_base_level`.", subzone);

                    int32 skill = player->GetSkillValue(SKILL_FISHING);

                    int32 chance;
                    if (skill < zone_skill)
                    {
                        chance = int32(pow((double)skill/zone_skill, 2) * 100);
                        if (chance < 1)
                            chance = 1;
                    }
                    else
                        chance = 100;

                    int32 roll = irand(1, 100);

                    TC_LOG_DEBUG("misc", "Fishing check (skill: %i zone min skill: %i chance %i roll: %i", skill, zone_skill, chance, roll);

                    player->UpdateFishingSkill();

                    /// @todo find reasonable value for fishing hole search
                    GameObject* fishingPool = LookupFishingHoleAround(20.0f + CONTACT_DISTANCE);

                    // If fishing skill is high enough, or if fishing on a pool, send correct loot.
                    // Fishing pools have no skill requirement as of patch 3.3.0 (undocumented change).
                    if (chance >= roll || fishingPool)
                    {
                        /// @todo I do not understand this hack. Need some explanation.
                        // prevent removing GO at spell cancel
                        RemoveFromOwner();
                        SetOwnerGUID(player->GetGUID());
                        SetSpellId(0); // prevent removing unintended auras at Unit::RemoveGameObject

                        if (fishingPool)
                        {
                            fishingPool->Use(player);
                            SetLootState(GO_JUST_DEACTIVATED);
                        }
                        else
                            player->SendLoot(GetGUID(), LOOT_FISHING);
                    }
                    else // If fishing skill is too low, send junk loot.
                        player->SendLoot(GetGUID(), LOOT_FISHING_JUNK);
                    break;
                }
                case GO_JUST_DEACTIVATED:                   // nothing to do, will be deleted at next update
                    break;
                default:
                {
                    SetLootState(GO_JUST_DEACTIVATED);
                    player->SendDirectMessage(WorldPackets::GameObject::FishNotHooked().Write());
                    break;
                }
            }

            player->FinishSpell(CURRENT_CHANNELED_SPELL);
            return;
        }

        case GAMEOBJECT_TYPE_RITUAL:              //18
        {
            if (user->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = user->ToPlayer();

            Unit* owner = GetOwner();

            GameObjectTemplate const* info = GetGOInfo();

            Player* m_ritualOwner = nullptr;
            if (!m_ritualOwnerGUID.IsEmpty())
                m_ritualOwner = ObjectAccessor::FindPlayer(m_ritualOwnerGUID);

            // ritual owner is set for GO's without owner (not summoned)
            if (!m_ritualOwner && !owner)
            {
                m_ritualOwnerGUID = player->GetGUID();
                m_ritualOwner = player;
            }

            if (owner)
            {
                if (owner->GetTypeId() != TYPEID_PLAYER)
                    return;

                // accept only use by player from same group as owner, excluding owner itself (unique use already added in spell effect)
                if (player == owner->ToPlayer() || (info->ritual.castersGrouped && !player->IsInSameRaidWith(owner->ToPlayer())))
                    return;

                // expect owner to already be channeling, so if not...
                if (!owner->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
                    return;

                // in case summoning ritual caster is GO creator
                spellCaster = owner;
            }
            else
            {
                if (player != m_ritualOwner && (info->ritual.castersGrouped && !player->IsInSameRaidWith(m_ritualOwner)))
                    return;

                spellCaster = player;
            }

            AddUniqueUse(player);

            if (info->ritual.animSpell)
            {
                player->CastSpell(player, info->ritual.animSpell, true);

                // for this case, summoningRitual.spellId is always triggered
                triggered = true;
            }

            // full amount unique participants including original summoner
            if (GetUniqueUseCount() == info->ritual.casters)
            {
                if (m_ritualOwner)
                    spellCaster = m_ritualOwner;

                spellId = info->ritual.spell;

                if (spellId == 62330)                       // GO store nonexistent spell, replace by expected
                {
                    // spell have reagent and mana cost but it not expected use its
                    // it triggered spell in fact cast at currently channeled GO
                    spellId = 61993;
                    triggered = true;
                }

                // Cast casterTargetSpell at a random GO user
                // on the current DB there is only one gameobject that uses this (Ritual of Doom)
                // and its required target number is 1 (outter for loop will run once)
                if (info->ritual.casterTargetSpell && info->ritual.casterTargetSpell != 1) // No idea why this field is a bool in some cases
                    for (uint32 i = 0; i < info->ritual.casterTargetSpellTargets; i++)
                        // m_unique_users can contain only player GUIDs
                        if (Player* target = ObjectAccessor::GetPlayer(*this, Trinity::Containers::SelectRandomContainerElement(m_unique_users)))
                            spellCaster->CastSpell(target, info->ritual.casterTargetSpell, true);

                // finish owners spell
                if (owner)
                    owner->FinishSpell(CURRENT_CHANNELED_SPELL);

                // can be deleted now, if
                if (!info->ritual.ritualPersistent)
                    SetLootState(GO_JUST_DEACTIVATED);
                else
                {
                    // reset ritual for this GO
                    m_ritualOwnerGUID.Clear();
                    m_unique_users.clear();
                    m_usetimes = 0;
                }
            }
            else
                return;

            // go to end function to spell casting
            break;
        }
        case GAMEOBJECT_TYPE_SPELLCASTER:                   //22
        {
            GameObjectTemplate const* info = GetGOInfo();
            if (!info)
                return;

            if (info->spellCaster.partyOnly)
            {
                Unit* caster = GetOwner();
                if (!caster || caster->GetTypeId() != TYPEID_PLAYER)
                    return;

                if (user->GetTypeId() != TYPEID_PLAYER || !user->ToPlayer()->IsInSameRaidWith(caster->ToPlayer()))
                    return;
            }

            user->RemoveAurasByType(SPELL_AURA_MOUNTED);
            spellId = info->spellCaster.spell;

            AddUse();
            break;
        }
        case GAMEOBJECT_TYPE_MEETINGSTONE:                  //23
        {
            GameObjectTemplate const* info = GetGOInfo();

            if (user->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = user->ToPlayer();

            Player* targetPlayer = ObjectAccessor::FindPlayer(player->GetTarget());

            // accept only use by player from same raid as caster, except caster itself
            if (!targetPlayer || targetPlayer == player || !targetPlayer->IsInSameRaidWith(player))
                return;

            //required lvl checks!
            uint8 level = player->getLevel();
            if (level < info->meetingStone.minLevel)
                return;
            level = targetPlayer->getLevel();
            if (level < info->meetingStone.minLevel)
                return;

            if (info->entry == 194097)
                spellId = 61994;                            // Ritual of Summoning
            else
                spellId = 59782;                            // Summoning Stone Effect

            break;
        }

        case GAMEOBJECT_TYPE_FLAGSTAND:                     // 24
        {
            if (user->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = user->ToPlayer();

            if (player->CanUseBattlegroundObject(this))
            {
                // in battleground check
                Battleground* bg = player->GetBattleground();
                if (!bg)
                    return;

                if (player->GetVehicle())
                    return;

                player->RemoveAurasByType(SPELL_AURA_MOD_STEALTH);
                player->RemoveAurasByType(SPELL_AURA_MOD_INVISIBILITY);
                // BG flag click
                // AB:
                // 15001
                // 15002
                // 15003
                // 15004
                // 15005
                bg->EventPlayerClickedOnFlag(player, this);
                return;                                     //we don;t need to delete flag ... it is despawned!
            }
            break;
        }

        case GAMEOBJECT_TYPE_FISHINGHOLE:                   // 25
        {
            if (user->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = user->ToPlayer();

            player->SendLoot(GetGUID(), LOOT_FISHINGHOLE);
            player->UpdateCriteria(CRITERIA_TYPE_FISH_IN_GAMEOBJECT, GetGOInfo()->entry);
            return;
        }

        case GAMEOBJECT_TYPE_FLAGDROP:                      // 26
        {
            if (user->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = user->ToPlayer();

            if (player->CanUseBattlegroundObject(this))
            {
                // in battleground check
                Battleground* bg = player->GetBattleground();
                if (!bg)
                    return;

                if (player->GetVehicle())
                    return;

                player->RemoveAurasByType(SPELL_AURA_MOD_STEALTH);
                player->RemoveAurasByType(SPELL_AURA_MOD_INVISIBILITY);
                // BG flag dropped
                // WS:
                // 179785 - Silverwing Flag
                // 179786 - Warsong Flag
                // EotS:
                // 184142 - Netherstorm Flag
                GameObjectTemplate const* info = GetGOInfo();
                if (info)
                {
                    switch (info->entry)
                    {
                        case 179785:                        // Silverwing Flag
                        case 179786:                        // Warsong Flag
                            if (bg->GetTypeID(true) == BATTLEGROUND_WS)
                                bg->EventPlayerClickedOnFlag(player, this);
                            break;
                        case 184142:                        // Netherstorm Flag
                            if (bg->GetTypeID(true) == BATTLEGROUND_EY)
                                bg->EventPlayerClickedOnFlag(player, this);
                            break;
                    }
                }
                //this cause to call return, all flags must be deleted here!!
                spellId = 0;
                Delete();
            }
            break;
        }
        case GAMEOBJECT_TYPE_BARBER_CHAIR:                  //32
        {
            GameObjectTemplate const* info = GetGOInfo();
            if (!info)
                return;

            if (user->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = user->ToPlayer();

            WorldPackets::Misc::EnableBarberShop packet;
            player->SendDirectMessage(packet.Write());

            // fallback, will always work
            player->TeleportTo(GetMapId(), GetPositionX(), GetPositionY(), GetPositionZ(), GetOrientation(), TELE_TO_NOT_LEAVE_TRANSPORT | TELE_TO_NOT_LEAVE_COMBAT | TELE_TO_NOT_UNSUMMON_PET);

            player->SetStandState(UnitStandStateType(UNIT_STAND_STATE_SIT_LOW_CHAIR + info->barberChair.chairheight), info->barberChair.SitAnimKit);
            return;
        }
        case GAMEOBJECT_TYPE_ARTIFACT_FORGE:
        {
            GameObjectTemplate const* info = GetGOInfo();
            if (!info)
                return;

            if (user->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = user->ToPlayer();
            if (PlayerConditionEntry const* playerCondition = sPlayerConditionStore.LookupEntry(info->artifactForge.conditionID1))
                if (!sConditionMgr->IsPlayerMeetingCondition(player, playerCondition))
                    return;

            Aura const* artifactAura = player->GetAura(ARTIFACTS_ALL_WEAPONS_GENERAL_WEAPON_EQUIPPED_PASSIVE);
            Item const* item = artifactAura ? player->GetItemByGuid(artifactAura->GetCastItemGUID()) : nullptr;
            if (!item)
            {
                player->SendDirectMessage(WorldPackets::Misc::DisplayGameError(GameError::ERR_MUST_EQUIP_ARTIFACT).Write());
                return;
            }

            WorldPackets::Artifact::ArtifactForgeOpened artifactForgeOpened;
            artifactForgeOpened.ArtifactGUID = item->GetGUID();
            artifactForgeOpened.ForgeGUID = GetGUID();
            player->SendDirectMessage(artifactForgeOpened.Write());
            return;
        }
        case GAMEOBJECT_TYPE_UI_LINK:
        {
            Player* player = user->ToPlayer();
            if (!player)
                return;

            WorldPackets::GameObject::GameObjectUIAction gameObjectUIAction;
            gameObjectUIAction.ObjectGUID = GetGUID();
            gameObjectUIAction.UILink = GetGOInfo()->UILink.UILinkType;
            player->SendDirectMessage(gameObjectUIAction.Write());
            return;
        }
        default:
            if (GetGoType() >= MAX_GAMEOBJECT_TYPE)
                TC_LOG_ERROR("misc", "GameObject::Use(): unit (type: %u, %s, name: %s) tries to use object (%s, name: %s) of unknown type (%u)",
                    user->GetTypeId(), user->GetGUID().ToString().c_str(), user->GetName().c_str(), GetGUID().ToString().c_str(), GetGOInfo()->name.c_str(), GetGoType());
            break;
    }

    if (!spellId)
        return;

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
    if (!spellInfo)
    {
        if (user->GetTypeId() != TYPEID_PLAYER || !sOutdoorPvPMgr->HandleCustomSpell(user->ToPlayer(), spellId, this))
            TC_LOG_ERROR("misc", "WORLD: unknown spell id %u at use action for gameobject (Entry: %u GoType: %u)", spellId, GetEntry(), GetGoType());
        else
            TC_LOG_DEBUG("outdoorpvp", "WORLD: %u non-dbc spell was handled by OutdoorPvP", spellId);
        return;
    }

    if (Player* player = user->ToPlayer())
        sOutdoorPvPMgr->HandleCustomSpell(player, spellId, this);

    if (spellCaster)
        spellCaster->CastSpell(user, spellInfo, triggered);
    else
        CastSpell(user, spellId);
}

void GameObject::CastSpell(Unit* target, uint32 spellId, bool triggered /* = true*/)
{
    CastSpell(target, spellId, triggered ? TRIGGERED_FULL_MASK : TRIGGERED_NONE);
}

void GameObject::CastSpell(Unit* target, uint32 spellId, TriggerCastFlags triggered)
{
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
    if (!spellInfo)
        return;

    bool self = false;
    for (SpellEffectInfo const* effect : spellInfo->GetEffectsForDifficulty(GetMap()->GetDifficultyID()))
    {
        if (effect && effect->TargetA.GetTarget() == TARGET_UNIT_CASTER)
        {
            self = true;
            break;
        }
    }

    if (self)
    {
        if (target)
            target->CastSpell(target, spellInfo, triggered);
        return;
    }

    //summon world trigger
    Creature* trigger = SummonTrigger(GetPositionX(), GetPositionY(), GetPositionZ(), 0, spellInfo->CalcCastTime() + 100);
    if (!trigger)
        return;

    // remove immunity flags, to allow spell to target anything
    trigger->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC);

    if (Unit* owner = GetOwner())
    {
        trigger->setFaction(owner->getFaction());
        if (owner->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE))
            trigger->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE);
        // copy pvp state flags from owner
        trigger->SetByteValue(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PVP_FLAG, owner->GetByteValue(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PVP_FLAG));
        // needed for GO casts for proper target validation checks
        trigger->SetOwnerGUID(owner->GetGUID());
        trigger->CastSpell(target ? target : trigger, spellInfo, triggered, nullptr, nullptr, owner->GetGUID());
    }
    else
    {
        trigger->setFaction(spellInfo->IsPositive() ? 35 : 14);
        // Set owner guid for target if no owner available - needed by trigger auras
        // - trigger gets despawned and there's no caster avalible (see AuraEffect::TriggerSpell())
        trigger->CastSpell(target ? target : trigger, spellInfo, triggered, nullptr, nullptr, target ? target->GetGUID() : ObjectGuid::Empty);
    }
}

void GameObject::SendCustomAnim(uint32 anim)
{
    WorldPackets::GameObject::GameObjectCustomAnim customAnim;
    customAnim.ObjectGUID = GetGUID();
    customAnim.CustomAnim = anim;
    SendMessageToSet(customAnim.Write(), true);
}

bool GameObject::IsInRange(float x, float y, float z, float radius) const
{
    GameObjectDisplayInfoEntry const* info = sGameObjectDisplayInfoStore.LookupEntry(m_goInfo->displayId);
    if (!info)
        return IsWithinDist3d(x, y, z, radius);

    float sinA = std::sin(GetOrientation());
    float cosA = std::cos(GetOrientation());
    float dx = x - GetPositionX();
    float dy = y - GetPositionY();
    float dz = z - GetPositionZ();
    float dist = std::sqrt(dx*dx + dy*dy);
    //! Check if the distance between the 2 objects is 0, can happen if both objects are on the same position.
    //! The code below this check wont crash if dist is 0 because 0/0 in float operations is valid, and returns infinite
    if (G3D::fuzzyEq(dist, 0.0f))
        return true;

    float sinB = dx / dist;
    float cosB = dy / dist;
    dx = dist * (cosA * cosB + sinA * sinB);
    dy = dist * (cosA * sinB - sinA * cosB);
    return dx < info->GeoBoxMax.X + radius && dx > info->GeoBoxMin.X - radius
        && dy < info->GeoBoxMax.Y + radius && dy > info->GeoBoxMin.Y - radius
        && dz < info->GeoBoxMax.Z + radius && dz > info->GeoBoxMin.Z - radius;
}

void GameObject::EventInform(uint32 eventId, WorldObject* invoker /*= nullptr*/)
{
    if (!eventId)
        return;

    if (AI())
        AI()->EventInform(eventId);

    if (GetZoneScript())
        GetZoneScript()->ProcessEvent(this, eventId);

    if (BattlegroundMap* bgMap = GetMap()->ToBattlegroundMap())
        if (bgMap->GetBG())
            bgMap->GetBG()->ProcessEvent(this, eventId, invoker);
}

uint32 GameObject::GetScriptId() const
{
    if (GameObjectData const* gameObjectData = GetGOData())
        return gameObjectData->ScriptId;

    return GetGOInfo()->ScriptId;
}

// overwrite WorldObject function for proper name localization
std::string const & GameObject::GetNameForLocaleIdx(LocaleConstant loc_idx) const
{
    if (loc_idx != DEFAULT_LOCALE)
    {
        uint8 uloc_idx = uint8(loc_idx);
        if (GameObjectLocale const* cl = sObjectMgr->GetGameObjectLocale(GetEntry()))
            if (cl->Name.size() > uloc_idx && !cl->Name[uloc_idx].empty())
                return cl->Name[uloc_idx];
    }

    return GetName();
}

void GameObject::UpdatePackedRotation()
{
    static const int32 PACK_YZ = 1 << 20;
    static const int32 PACK_X = PACK_YZ << 1;

    static const int32 PACK_YZ_MASK = (PACK_YZ << 1) - 1;
    static const int32 PACK_X_MASK = (PACK_X << 1) - 1;

    int8 w_sign = (m_worldRotation.w >= 0.f ? 1 : -1);
    int64 x = int32(m_worldRotation.x * PACK_X)  * w_sign & PACK_X_MASK;
    int64 y = int32(m_worldRotation.y * PACK_YZ) * w_sign & PACK_YZ_MASK;
    int64 z = int32(m_worldRotation.z * PACK_YZ) * w_sign & PACK_YZ_MASK;
    m_packedRotation = z | (y << 21) | (x << 42);
}

void GameObject::SetWorldRotation(float qx, float qy, float qz, float qw)
{
    G3D::Quat rotation(qx, qy, qz, qw);
    rotation.unitize();
    m_worldRotation.x = rotation.x;
    m_worldRotation.y = rotation.y;
    m_worldRotation.z = rotation.z;
    m_worldRotation.w = rotation.w;
    UpdatePackedRotation();
}

void GameObject::SetParentRotation(QuaternionData const& rotation)
{
    SetFloatValue(GAMEOBJECT_PARENTROTATION + 0, rotation.x);
    SetFloatValue(GAMEOBJECT_PARENTROTATION + 1, rotation.y);
    SetFloatValue(GAMEOBJECT_PARENTROTATION + 2, rotation.z);
    SetFloatValue(GAMEOBJECT_PARENTROTATION + 3, rotation.w);
}

void GameObject::SetWorldRotationAngles(float z_rot, float y_rot, float x_rot)
{
    G3D::Quat quat(G3D::Matrix3::fromEulerAnglesZYX(z_rot, y_rot, x_rot));
    SetWorldRotation(quat.x, quat.y, quat.z, quat.w);
}

void GameObject::ModifyHealth(int32 change, Unit* attackerOrHealer /*= nullptr*/, uint32 spellId /*= 0*/)
{
    if (!m_goValue.Building.MaxHealth || !change)
        return;

    // prevent double destructions of the same object
    if (change < 0 && !m_goValue.Building.Health)
        return;

    if (int32(m_goValue.Building.Health) + change <= 0)
        m_goValue.Building.Health = 0;
    else if (int32(m_goValue.Building.Health) + change >= int32(m_goValue.Building.MaxHealth))
        m_goValue.Building.Health = m_goValue.Building.MaxHealth;
    else
        m_goValue.Building.Health += change;

    // Set the health bar, value = 255 * healthPct;
    SetGoAnimProgress(m_goValue.Building.Health * 255 / m_goValue.Building.MaxHealth);

    Player* player = attackerOrHealer ? attackerOrHealer->GetCharmerOrOwnerPlayerOrPlayerItself() : nullptr;

    // dealing damage, send packet
    if (player)
    {
        WorldPackets::GameObject::DestructibleBuildingDamage packet;
        packet.Caster = attackerOrHealer->GetGUID(); // todo: this can be a GameObject
        packet.Target = GetGUID();
        packet.Damage = -change;
        packet.Owner = player->GetGUID();
        packet.SpellID = spellId;
        player->SendDirectMessage(packet.Write());
    }

    GameObjectDestructibleState newState = GetDestructibleState();

    if (!m_goValue.Building.Health)
        newState = GO_DESTRUCTIBLE_DESTROYED;
    else if (m_goValue.Building.Health <= 10000/*GetGOInfo()->destructibleBuilding.damagedNumHits*/) // TODO: Get health somewhere
        newState = GO_DESTRUCTIBLE_DAMAGED;
    else if (m_goValue.Building.Health == m_goValue.Building.MaxHealth)
        newState = GO_DESTRUCTIBLE_INTACT;

    if (newState == GetDestructibleState())
        return;

    /// @todo: pass attackerOrHealer instead of player
    SetDestructibleState(newState, player, false);
}

void GameObject::SetDestructibleState(GameObjectDestructibleState state, Player* eventInvoker /*= nullptr*/, bool setHealth /*= false*/)
{
    // the user calling this must know he is already operating on destructible gameobject
    ASSERT(GetGoType() == GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING);

    switch (state)
    {
        case GO_DESTRUCTIBLE_INTACT:
            RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED | GO_FLAG_DESTROYED);
            SetDisplayId(m_goInfo->displayId);
            if (setHealth)
            {
                m_goValue.Building.Health = m_goValue.Building.MaxHealth;
                SetGoAnimProgress(255);
            }
            EnableCollision(true);
            break;
        case GO_DESTRUCTIBLE_DAMAGED:
        {
            EventInform(m_goInfo->destructibleBuilding.DamagedEvent, eventInvoker);
            sScriptMgr->OnGameObjectDamaged(this, eventInvoker);

            RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED);
            SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED);

            uint32 modelId = m_goInfo->displayId;
            if (DestructibleModelDataEntry const* modelData = sDestructibleModelDataStore.LookupEntry(m_goInfo->destructibleBuilding.DestructibleModelRec))
                if (modelData->State0Wmo)
                    modelId = modelData->State0Wmo;
            SetDisplayId(modelId);

            if (setHealth)
            {
                m_goValue.Building.Health = 10000/*m_goInfo->destructibleBuilding.damagedNumHits*/;
                uint32 maxHealth = m_goValue.Building.MaxHealth;
                // in this case current health is 0 anyway so just prevent crashing here
                if (!maxHealth)
                    maxHealth = 1;
                SetGoAnimProgress(m_goValue.Building.Health * 255 / maxHealth);
            }
            break;
        }
        case GO_DESTRUCTIBLE_DESTROYED:
        {
            sScriptMgr->OnGameObjectDestroyed(this, eventInvoker);
            EventInform(m_goInfo->destructibleBuilding.DestroyedEvent, eventInvoker);
            if (eventInvoker)
                if (Battleground* bg = eventInvoker->GetBattleground())
                    bg->DestroyGate(eventInvoker, this);

            RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED);
            SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED);

            uint32 modelId = m_goInfo->displayId;
            if (DestructibleModelDataEntry const* modelData = sDestructibleModelDataStore.LookupEntry(m_goInfo->destructibleBuilding.DestructibleModelRec))
                if (modelData->State1Wmo)
                    modelId = modelData->State1Wmo;
            SetDisplayId(modelId);

            if (setHealth)
            {
                m_goValue.Building.Health = 0;
                SetGoAnimProgress(0);
            }
            EnableCollision(false);
            break;
        }
        case GO_DESTRUCTIBLE_REBUILDING:
        {
            EventInform(m_goInfo->destructibleBuilding.RebuildingEvent, eventInvoker);
            RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED | GO_FLAG_DESTROYED);

            uint32 modelId = m_goInfo->displayId;
            if (DestructibleModelDataEntry const* modelData = sDestructibleModelDataStore.LookupEntry(m_goInfo->destructibleBuilding.DestructibleModelRec))
                if (modelData->State2Wmo)
                    modelId = modelData->State2Wmo;
            SetDisplayId(modelId);

            // restores to full health
            if (setHealth)
            {
                m_goValue.Building.Health = m_goValue.Building.MaxHealth;
                SetGoAnimProgress(255);
            }
            EnableCollision(true);
            break;
        }
    }
}

void GameObject::SetLootState(LootState state, Unit* unit)
{
    m_lootState = state;
    if (unit)
        m_lootStateUnitGUID = unit->GetGUID();
    else
        m_lootStateUnitGUID.Clear();

    AI()->OnStateChanged(state, unit);
    sScriptMgr->OnGameObjectLootStateChanged(this, state, unit);

    if (GetGoType() == GAMEOBJECT_TYPE_DOOR) // only set collision for doors on SetGoState
        return;

    if (m_model)
    {
        bool collision = false;
        // Use the current go state
        if ((GetGoState() != GO_STATE_READY && (state == GO_ACTIVATED || state == GO_JUST_DEACTIVATED)) || state == GO_READY)
            collision = !collision;

        EnableCollision(collision);
    }
}

void GameObject::SetGoState(GOState state)
{
    SetByteValue(GAMEOBJECT_BYTES_1, 0, state);
    sScriptMgr->OnGameObjectStateChanged(this, state);
    if (m_model && !IsTransport())
    {
        if (!IsInWorld())
            return;

        // startOpen determines whether we are going to add or remove the LoS on activation
        bool collision = false;
        if (state == GO_STATE_READY)
            collision = !collision;

        EnableCollision(collision);
    }
}

uint32 GameObject::GetTransportPeriod() const
{
    ASSERT(GetGOInfo()->type == GAMEOBJECT_TYPE_TRANSPORT);
    if (m_goValue.Transport.AnimationInfo)
        return m_goValue.Transport.AnimationInfo->TotalTime;

    return 0;
}

void GameObject::SetTransportState(GOState state, uint32 stopFrame /*= 0*/)
{
    if (GetGoState() == state)
        return;

    ASSERT(GetGOInfo()->type == GAMEOBJECT_TYPE_TRANSPORT);
    ASSERT(state >= GO_STATE_TRANSPORT_ACTIVE);
    if (state == GO_STATE_TRANSPORT_ACTIVE)
    {
        m_goValue.Transport.StateUpdateTimer = 0;
        m_goValue.Transport.PathProgress = getMSTime();
        if (GetGoState() >= GO_STATE_TRANSPORT_STOPPED)
            m_goValue.Transport.PathProgress += m_goValue.Transport.StopFrames->at(GetGoState() - GO_STATE_TRANSPORT_STOPPED);
        SetGoState(GO_STATE_TRANSPORT_ACTIVE);
    }
    else
    {
        ASSERT(state < GOState(GO_STATE_TRANSPORT_STOPPED + MAX_GO_STATE_TRANSPORT_STOP_FRAMES));
        ASSERT(stopFrame < m_goValue.Transport.StopFrames->size());
        m_goValue.Transport.PathProgress = getMSTime() + m_goValue.Transport.StopFrames->at(stopFrame);
        SetGoState(GOState(GO_STATE_TRANSPORT_STOPPED + stopFrame));
    }
}

void GameObject::SetDisplayId(uint32 displayid)
{
    SetUInt32Value(GAMEOBJECT_DISPLAYID, displayid);
    UpdateModel();
}

void GameObject::EnableCollision(bool enable)
{
    if (!m_model)
        return;

    /*if (enable && !GetMap()->ContainsGameObjectModel(*m_model))
        GetMap()->InsertGameObjectModel(*m_model);*/

    m_model->enableCollision(enable);
}

void GameObject::UpdateModel()
{
    if (!IsInWorld())
        return;
    if (m_model)
        if (GetMap()->ContainsGameObjectModel(*m_model))
            GetMap()->RemoveGameObjectModel(*m_model);
    delete m_model;
    m_model = CreateModel();
    if (m_model)
        GetMap()->InsertGameObjectModel(*m_model);
}

Player* GameObject::GetLootRecipient() const
{
    if (!m_lootRecipient)
        return nullptr;
    return ObjectAccessor::FindConnectedPlayer(m_lootRecipient);
}

Group* GameObject::GetLootRecipientGroup() const
{
    if (!m_lootRecipientGroup)
        return nullptr;
    return sGroupMgr->GetGroupByGUID(m_lootRecipientGroup);
}

void GameObject::SetLootRecipient(Unit* unit, Group* group)
{
    // set the player whose group should receive the right
    // to loot the creature after it dies
    // should be set to nullptr after the loot disappears

    if (!unit)
    {
        m_lootRecipient.Clear();
        m_lootRecipientGroup = group ? group->GetGUID() : ObjectGuid::Empty;
        return;
    }

    if (unit->GetTypeId() != TYPEID_PLAYER && !unit->IsVehicle())
        return;

    Player* player = unit->GetCharmerOrOwnerPlayerOrPlayerItself();
    if (!player)                                             // normal creature, no player involved
        return;

    m_lootRecipient = player->GetGUID();

    // either get the group from the passed parameter or from unit's one
    if (group)
        m_lootRecipientGroup = group->GetGUID();
    else if (Group* unitGroup = player->GetGroup())
        m_lootRecipientGroup = unitGroup->GetGUID();
}

bool GameObject::IsLootAllowedFor(Player const* player) const
{
    if (!m_lootRecipient && !m_lootRecipientGroup)
        return true;

    if (player->GetGUID() == m_lootRecipient)
        return true;

    Group const* playerGroup = player->GetGroup();
    if (!playerGroup || playerGroup != GetLootRecipientGroup()) // if we dont have a group we arent the recipient
        return false;                                           // if go doesnt have group bound it means it was solo killed by someone else

    return true;
}

GameObject* GameObject::GetLinkedTrap()
{
    return ObjectAccessor::GetGameObject(*this, m_linkedTrap);
}

void GameObject::BuildValuesUpdate(uint8 updateType, ByteBuffer* data, Player* target) const
{
    if (!target)
        return;

    bool isStoppableTransport = GetGoType() == GAMEOBJECT_TYPE_TRANSPORT && !m_goValue.Transport.StopFrames->empty();
    bool forcedFlags = GetGoType() == GAMEOBJECT_TYPE_CHEST && GetGOInfo()->chest.usegrouplootrules && HasLootRecipient();
    bool targetIsGM = target->IsGameMaster();

    std::size_t blockCount = UpdateMask::GetBlockCount(m_valuesCount);

    uint32* flags = GameObjectUpdateFieldFlags;
    uint32 visibleFlag = UF_FLAG_PUBLIC;
    if (GetOwnerGUID() == target->GetGUID())
        visibleFlag |= UF_FLAG_OWNER;

    *data << uint8(blockCount);
    std::size_t maskPos = data->wpos();
    data->resize(data->size() + blockCount * sizeof(UpdateMask::BlockType));

    for (uint16 index = 0; index < m_valuesCount; ++index)
    {
        if (_fieldNotifyFlags & flags[index] ||
            ((updateType == UPDATETYPE_VALUES ? _changesMask[index] : m_uint32Values[index]) && (flags[index] & visibleFlag)) ||
            (index == GAMEOBJECT_FLAGS && forcedFlags))
        {
            UpdateMask::SetUpdateBit(data->contents() + maskPos, index);

            if (index == OBJECT_DYNAMIC_FLAGS)
            {
                uint16 dynFlags = 0;
                int16 pathProgress = -1;
                switch (GetGoType())
                {
                    case GAMEOBJECT_TYPE_QUESTGIVER:
                        if (ActivateToQuest(target))
                            dynFlags |= GO_DYNFLAG_LO_ACTIVATE;
                        break;
                    case GAMEOBJECT_TYPE_CHEST:
                    case GAMEOBJECT_TYPE_GOOBER:
                        if (ActivateToQuest(target))
                            dynFlags |= GO_DYNFLAG_LO_ACTIVATE | GO_DYNFLAG_LO_SPARKLE;
                        else if (targetIsGM)
                            dynFlags |= GO_DYNFLAG_LO_ACTIVATE;
                        break;
                    case GAMEOBJECT_TYPE_GENERIC:
                        if (ActivateToQuest(target))
                            dynFlags |= GO_DYNFLAG_LO_SPARKLE;
                        break;
                    case GAMEOBJECT_TYPE_TRANSPORT:
                    case GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT:
                    {
                        if (uint32 transportPeriod = GetTransportPeriod())
                        {
                            float timer = float(m_goValue.Transport.PathProgress % transportPeriod);
                            pathProgress = int16(timer / float(transportPeriod) * 65535.0f);
                        }
                        break;
                    }
                    default:
                        break;
                }

                *data << uint16(dynFlags);
                *data << int16(pathProgress);
            }
            else if (index == GAMEOBJECT_FLAGS)
            {
                uint32 goFlags = m_uint32Values[GAMEOBJECT_FLAGS];
                if (GetGoType() == GAMEOBJECT_TYPE_CHEST)
                    if (GetGOInfo()->chest.usegrouplootrules && !IsLootAllowedFor(target))
                        goFlags |= GO_FLAG_LOCKED | GO_FLAG_NOT_SELECTABLE;

                *data << goFlags;
            }
            else if (index == GAMEOBJECT_LEVEL)
            {
                if (isStoppableTransport)
                    *data << uint32(m_goValue.Transport.PathProgress);
                else
                    *data << m_uint32Values[index];
            }
            else if (index == GAMEOBJECT_BYTES_1)
            {
                uint32 bytes1 = m_uint32Values[index];
                if (isStoppableTransport && GetGoState() == GO_STATE_TRANSPORT_ACTIVE)
                {
                    if ((m_goValue.Transport.StateUpdateTimer / 20000) & 1)
                    {
                        bytes1 &= 0xFFFFFF00;
                        bytes1 |= GO_STATE_TRANSPORT_STOPPED;
                    }
                }

                *data << bytes1;
            }
            else
                *data << m_uint32Values[index];                // other cases
        }
    }
}

void GameObject::GetRespawnPosition(float &x, float &y, float &z, float* ori /* = nullptr*/) const
{
    if (m_spawnId)
    {
        if (GameObjectData const* data = sObjectMgr->GetGOData(GetSpawnId()))
        {
            x = data->posX;
            y = data->posY;
            z = data->posZ;
            if (ori)
                *ori = data->orientation;
            return;
        }
    }

    x = GetPositionX();
    y = GetPositionY();
    z = GetPositionZ();
    if (ori)
        *ori = GetOrientation();
}

float GameObject::GetInteractionDistance() const
{
    switch (GetGoType())
    {
        /// @todo find out how the client calculates the maximal usage distance to spellless working
        // gameobjects like guildbanks and mailboxes - 10.0 is a just an abitrary choosen number
        case GAMEOBJECT_TYPE_GUILD_BANK:
        case GAMEOBJECT_TYPE_MAILBOX:
            return 10.0f;
        case GAMEOBJECT_TYPE_FISHINGHOLE:
        case GAMEOBJECT_TYPE_FISHINGNODE:
            return 20.0f + CONTACT_DISTANCE; // max spell range
        default:
            return INTERACTION_DISTANCE;
    }
}

void GameObject::UpdateModelPosition()
{
    if (!m_model)
        return;

    if (GetMap()->ContainsGameObjectModel(*m_model))
    {
        GetMap()->RemoveGameObjectModel(*m_model);
        m_model->UpdatePosition();
        GetMap()->InsertGameObjectModel(*m_model);
    }
}

void GameObject::SetAnimKitId(uint16 animKitId, bool oneshot)
{
    if (_animKitId == animKitId)
        return;

    if (animKitId && !sAnimKitStore.LookupEntry(animKitId))
        return;

    if (!oneshot)
        _animKitId = animKitId;
    else
        _animKitId = 0;

    WorldPackets::GameObject::GameObjectActivateAnimKit activateAnimKit;
    activateAnimKit.ObjectGUID = GetGUID();
    activateAnimKit.AnimKitID = animKitId;
    activateAnimKit.Maintain = !oneshot;
    SendMessageToSet(activateAnimKit.Write(), true);
}

class GameObjectModelOwnerImpl : public GameObjectModelOwnerBase
{
public:
    explicit GameObjectModelOwnerImpl(GameObject const* owner) : _owner(owner) { }
    virtual ~GameObjectModelOwnerImpl() = default;

    virtual bool IsSpawned() const override { return _owner->isSpawned(); }
    virtual uint32 GetDisplayId() const override { return _owner->GetDisplayId(); }
    virtual bool IsInPhase(PhaseShift const& phaseShift) const override { return _owner->GetPhaseShift().CanSee(phaseShift); }
    virtual G3D::Vector3 GetPosition() const override { return G3D::Vector3(_owner->GetPositionX(), _owner->GetPositionY(), _owner->GetPositionZ()); }
    virtual float GetOrientation() const override { return _owner->GetOrientation(); }
    virtual float GetScale() const override { return _owner->GetObjectScale(); }
    virtual void DebugVisualizeCorner(G3D::Vector3 const& corner) const override { _owner->SummonCreature(1, corner.x, corner.y, corner.z, 0, TEMPSUMMON_MANUAL_DESPAWN); }

private:
    GameObject const* _owner;
};

GameObjectModel* GameObject::CreateModel()
{
    return GameObjectModel::Create(Trinity::make_unique<GameObjectModelOwnerImpl>(this), sWorld->GetDataPath());
}

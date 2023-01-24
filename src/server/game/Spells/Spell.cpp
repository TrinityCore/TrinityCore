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

#include "Spell.h"
#include "Battlefield.h"
#include "BattlefieldMgr.h"
#include "Battleground.h"
#include "CellImpl.h"
#include "Common.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "DB2Stores.h"
#include "DisableMgr.h"
#include "DynamicObject.h"
#include "G3DPosition.hpp"
#include "GameClient.h"
#include "GameObjectAI.h"
#include "GameTime.h"
#include "GridNotifiersImpl.h"
#include "Guild.h"
#include "InstanceScript.h"
#include "Item.h"
#include "Log.h"
#include "LootMgr.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "PathGenerator.h"
#include "Pet.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SharedDefines.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellPackets.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "TradeData.h"
#include "Unit.h"
#include "UpdateData.h"
#include "UpdateMask.h"
#include "Util.h"
#include "Vehicle.h"
#include "VMapFactory.h"
#include "VMapManager2.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"

extern SpellEffectHandlerFn SpellEffectHandlers[TOTAL_SPELL_EFFECTS];

SpellDestination::SpellDestination()
{
    _position.Relocate(0, 0, 0, 0);
    _transportGUID.Clear();
    _transportOffset.Relocate(0, 0, 0, 0);
}

SpellDestination::SpellDestination(float x, float y, float z, float orientation, uint32 mapId)
{
    _position.Relocate(x, y, z, orientation);
    _transportGUID.Clear();
    _position.m_mapId = mapId;
    _transportOffset.Relocate(0, 0, 0, 0);
}

SpellDestination::SpellDestination(Position const& pos)
{
    _position.Relocate(pos);
    _transportGUID.Clear();
    _transportOffset.Relocate(0, 0, 0, 0);
}

SpellDestination::SpellDestination(WorldObject const& wObj)
{
    _transportGUID = wObj.GetTransGUID();
    _transportOffset.Relocate(wObj.GetTransOffsetX(), wObj.GetTransOffsetY(), wObj.GetTransOffsetZ(), wObj.GetTransOffsetO());
    _position.Relocate(wObj);
}

void SpellDestination::Relocate(Position const& pos)
{
    if (_transportGUID)
    {
        Position offset;
        _position.GetPositionOffsetTo(pos, offset);
        _transportOffset.RelocateOffset(offset);
    }
    _position.Relocate(pos);
}

void SpellDestination::RelocateOffset(Position const& offset)
{
    if (_transportGUID)
        _transportOffset.RelocateOffset(offset);

    _position.RelocateOffset(offset);
}

SpellCastTargets::SpellCastTargets() : m_targetMask(0), m_objectTarget(nullptr), m_itemTarget(nullptr),
    m_itemTargetEntry(0),  m_elevation(0.f), m_speed(0.f)
{
}

SpellCastTargets::SpellCastTargets(Unit* caster, WorldPackets::Spells::SpellCastRequest const& spellCastRequest) :
    m_targetMask(spellCastRequest.Target.Flags), m_objectTarget(nullptr), m_itemTarget(nullptr),
    m_itemTargetEntry(0), m_elevation(0.0f), m_speed(0.0f)
{
    if (spellCastRequest.Target.Unit)
        m_objectTargetGUID = *spellCastRequest.Target.Unit;

    if (spellCastRequest.Target.Item)
        m_itemTargetGUID = *spellCastRequest.Target.Item;

    if (spellCastRequest.Target.Name)
        m_strTarget = *spellCastRequest.Target.Name;

    if (spellCastRequest.Target.SrcLocation)
    {
        m_src._transportGUID = spellCastRequest.Target.SrcLocation->Transport;
        Position* pos;
        if (!m_src._transportGUID.IsEmpty())
            pos = &m_src._transportOffset;
        else
            pos = &m_src._position;

        pos->Relocate(spellCastRequest.Target.SrcLocation->Location);
    }

    if (spellCastRequest.Target.DstLocation)
    {
        m_dst._transportGUID = spellCastRequest.Target.DstLocation->Transport;
        Position* pos;
        if (!m_dst._transportGUID.IsEmpty())
            pos = &m_dst._transportOffset;
        else
            pos = &m_dst._position;

        pos->Relocate(spellCastRequest.Target.DstLocation->Location);
    }

    SetElevation(spellCastRequest.MissileTrajectory.Pitch);
    SetSpeed(spellCastRequest.MissileTrajectory.Speed);

    Update(caster);
}

SpellCastTargets::~SpellCastTargets() { }

void SpellCastTargets::Read(ByteBuffer& data, Unit* caster)
{
    data >> m_targetMask;

    if (m_targetMask == TARGET_FLAG_NONE)
        return;

    if (m_targetMask & (TARGET_FLAG_UNIT | TARGET_FLAG_UNIT_MINIPET | TARGET_FLAG_GAMEOBJECT | TARGET_FLAG_CORPSE_ENEMY | TARGET_FLAG_CORPSE_ALLY))
        data >> m_objectTargetGUID.ReadAsPacked();

    if (m_targetMask & (TARGET_FLAG_ITEM | TARGET_FLAG_TRADE_ITEM))
        data >> m_itemTargetGUID.ReadAsPacked();

    if (m_targetMask & TARGET_FLAG_SOURCE_LOCATION)
    {
        data >> m_src._transportGUID.ReadAsPacked();
        if (m_src._transportGUID)
            data >> m_src._transportOffset.PositionXYZStream();
        else
            data >> m_src._position.PositionXYZStream();
    }
    else
    {
        m_src._transportGUID = caster->GetTransGUID();
        if (m_src._transportGUID)
            m_src._transportOffset.Relocate(caster->GetTransOffsetX(), caster->GetTransOffsetY(), caster->GetTransOffsetZ(), caster->GetTransOffsetO());
        else
            m_src._position.Relocate(caster);
    }

    if (m_targetMask & TARGET_FLAG_DEST_LOCATION)
    {
        data >> m_dst._transportGUID.ReadAsPacked();
        if (m_dst._transportGUID)
            data >> m_dst._transportOffset.PositionXYZStream();
        else
            data >> m_dst._position.PositionXYZStream();
    }
    else
    {
        m_dst._transportGUID = caster->GetTransGUID();
        if (m_dst._transportGUID)
            m_dst._transportOffset.Relocate(caster->GetTransOffsetX(), caster->GetTransOffsetY(), caster->GetTransOffsetZ(), caster->GetTransOffsetO());
        else
            m_dst._position.Relocate(caster);
    }

    if (m_targetMask & TARGET_FLAG_STRING)
        data >> m_strTarget;

    Update(caster);
}

void SpellCastTargets::Write(WorldPackets::Spells::SpellTargetData& data)
{
    data.Flags = m_targetMask;

    if (m_targetMask & (TARGET_FLAG_UNIT | TARGET_FLAG_CORPSE_ALLY | TARGET_FLAG_GAMEOBJECT | TARGET_FLAG_CORPSE_ENEMY | TARGET_FLAG_UNIT_MINIPET))
        data.Unit = m_objectTargetGUID;

    if (m_targetMask & (TARGET_FLAG_ITEM | TARGET_FLAG_TRADE_ITEM) && m_itemTarget)
        data.Item = m_itemTarget->GetGUID();

    if (m_targetMask & TARGET_FLAG_SOURCE_LOCATION)
    {
        data.SrcLocation.emplace();
        data.SrcLocation->Transport = m_src._transportGUID; // relative position guid here - transport for example
        if (!m_src._transportGUID.IsEmpty())
            data.SrcLocation->Location = m_src._transportOffset;
        else
            data.SrcLocation->Location = m_src._position;
    }

    if (m_targetMask & TARGET_FLAG_DEST_LOCATION)
    {
        data.DstLocation.emplace();
        data.DstLocation->Transport = m_dst._transportGUID; // relative position guid here - transport for example
        if (!m_dst._transportGUID.IsEmpty())
            data.DstLocation->Location = m_dst._transportOffset;
        else
            data.DstLocation->Location = m_dst._position;
    }

    if (m_targetMask & TARGET_FLAG_STRING)
        data.Name = m_strTarget;
}

ObjectGuid SpellCastTargets::GetOrigUnitTargetGUID() const
{
    switch (m_origObjectTargetGUID.GetHigh())
    {
        case HighGuid::Player:
        case HighGuid::Vehicle:
        case HighGuid::Unit:
        case HighGuid::Pet:
            return m_origObjectTargetGUID;
        default:
            return ObjectGuid();
    }
}

void SpellCastTargets::SetOrigUnitTarget(Unit* target)
{
    if (!target)
        return;

    m_origObjectTargetGUID = target->GetGUID();
}

ObjectGuid SpellCastTargets::GetUnitTargetGUID() const
{
    if (m_objectTargetGUID.IsUnit())
        return m_objectTargetGUID;

    return ObjectGuid::Empty;
}

Unit* SpellCastTargets::GetUnitTarget() const
{
    if (m_objectTarget)
        return m_objectTarget->ToUnit();

    return nullptr;
}

void SpellCastTargets::SetUnitTarget(Unit* target)
{
    if (!target)
        return;

    m_objectTarget = target;
    m_objectTargetGUID = target->GetGUID();
    m_targetMask |= TARGET_FLAG_UNIT;
}

ObjectGuid SpellCastTargets::GetGOTargetGUID() const
{
    if (m_objectTargetGUID.IsAnyTypeGameObject())
        return m_objectTargetGUID;

    return ObjectGuid::Empty;
}

GameObject* SpellCastTargets::GetGOTarget() const
{
    if (m_objectTarget)
        return m_objectTarget->ToGameObject();

    return nullptr;
}

void SpellCastTargets::SetGOTarget(GameObject* target)
{
    if (!target)
        return;

    m_objectTarget = target;
    m_objectTargetGUID = target->GetGUID();
    m_targetMask |= TARGET_FLAG_GAMEOBJECT;
}

ObjectGuid SpellCastTargets::GetCorpseTargetGUID() const
{
    if (m_objectTargetGUID.IsCorpse())
        return m_objectTargetGUID;

    return ObjectGuid::Empty;
}

Corpse* SpellCastTargets::GetCorpseTarget() const
{
    if (m_objectTarget)
        return m_objectTarget->ToCorpse();

    return nullptr;
}

WorldObject* SpellCastTargets::GetObjectTarget() const
{
    return m_objectTarget;
}

ObjectGuid SpellCastTargets::GetObjectTargetGUID() const
{
    return m_objectTargetGUID;
}

void SpellCastTargets::RemoveObjectTarget()
{
    m_objectTarget = nullptr;
    m_objectTargetGUID.Clear();
    m_targetMask &= ~(TARGET_FLAG_UNIT_MASK | TARGET_FLAG_CORPSE_MASK | TARGET_FLAG_GAMEOBJECT_MASK);
}

void SpellCastTargets::SetItemTarget(Item* item)
{
    if (!item)
        return;

    m_itemTarget = item;
    m_itemTargetGUID = item->GetGUID();
    m_itemTargetEntry = item->GetEntry();
    m_targetMask |= TARGET_FLAG_ITEM;
}

void SpellCastTargets::SetTradeItemTarget(Player* caster)
{
    m_itemTargetGUID.Set(uint64(TRADE_SLOT_NONTRADED));
    m_itemTargetEntry = 0;
    m_targetMask |= TARGET_FLAG_TRADE_ITEM;

    Update(caster);
}

void SpellCastTargets::UpdateTradeSlotItem()
{
    if (m_itemTarget && (m_targetMask & TARGET_FLAG_TRADE_ITEM))
    {
        m_itemTargetGUID = m_itemTarget->GetGUID();
        m_itemTargetEntry = m_itemTarget->GetEntry();
    }
}

SpellDestination const* SpellCastTargets::GetSrc() const
{
    return &m_src;
}

Position const* SpellCastTargets::GetSrcPos() const
{
    return &m_src._position;
}

void SpellCastTargets::SetSrc(float x, float y, float z)
{
    m_src = SpellDestination(x, y, z);
    m_targetMask |= TARGET_FLAG_SOURCE_LOCATION;
}

void SpellCastTargets::SetSrc(Position const& pos)
{
    m_src = SpellDestination(pos);
    m_targetMask |= TARGET_FLAG_SOURCE_LOCATION;
}

void SpellCastTargets::SetSrc(WorldObject const& wObj)
{
    m_src = SpellDestination(wObj);
    m_targetMask |= TARGET_FLAG_SOURCE_LOCATION;
}

void SpellCastTargets::ModSrc(Position const& pos)
{
    ASSERT(m_targetMask & TARGET_FLAG_SOURCE_LOCATION);
    m_src.Relocate(pos);
}

void SpellCastTargets::RemoveSrc()
{
    m_targetMask &= ~(TARGET_FLAG_SOURCE_LOCATION);
}

SpellDestination const* SpellCastTargets::GetDst() const
{
    return &m_dst;
}

WorldLocation const* SpellCastTargets::GetDstPos() const
{
    return &m_dst._position;
}

void SpellCastTargets::SetDst(float x, float y, float z, float orientation, uint32 mapId)
{
    m_dst = SpellDestination(x, y, z, orientation, mapId);
    m_targetMask |= TARGET_FLAG_DEST_LOCATION;
}

void SpellCastTargets::SetDst(Position const& pos)
{
    m_dst = SpellDestination(pos);
    m_targetMask |= TARGET_FLAG_DEST_LOCATION;
}

void SpellCastTargets::SetDst(WorldObject const& wObj)
{
    m_dst = SpellDestination(wObj);
    m_targetMask |= TARGET_FLAG_DEST_LOCATION;
}

void SpellCastTargets::SetDst(SpellDestination const& spellDest)
{
    m_dst = spellDest;
    m_targetMask |= TARGET_FLAG_DEST_LOCATION;
}

void SpellCastTargets::SetDst(SpellCastTargets const& spellTargets)
{
    m_dst = spellTargets.m_dst;
    m_targetMask |= TARGET_FLAG_DEST_LOCATION;
}

void SpellCastTargets::ModDst(Position const& pos)
{
    ASSERT(m_targetMask & TARGET_FLAG_DEST_LOCATION);
    m_dst.Relocate(pos);
}

void SpellCastTargets::ModDst(SpellDestination const& spellDest)
{
    ASSERT(m_targetMask & TARGET_FLAG_DEST_LOCATION);
    m_dst = spellDest;
}

void SpellCastTargets::RemoveDst()
{
    m_targetMask &= ~(TARGET_FLAG_DEST_LOCATION);
}

bool SpellCastTargets::HasSrc() const
{
    return (GetTargetMask() & TARGET_FLAG_SOURCE_LOCATION) != 0;
}

bool SpellCastTargets::HasDst() const
{
    return (GetTargetMask() & TARGET_FLAG_DEST_LOCATION) != 0;
}

void SpellCastTargets::Update(WorldObject* caster)
{
    m_objectTarget = (m_objectTargetGUID == caster->GetGUID()) ? caster : ObjectAccessor::GetWorldObject(*caster, m_objectTargetGUID);

    m_itemTarget = nullptr;
    if (caster->GetTypeId() == TYPEID_PLAYER)
    {
        Player* player = caster->ToPlayer();
        if (m_targetMask & TARGET_FLAG_ITEM)
            m_itemTarget = player->GetItemByGuid(m_itemTargetGUID);
        else if (m_targetMask & TARGET_FLAG_TRADE_ITEM)
            if (m_itemTargetGUID.GetRawValue() == TRADE_SLOT_NONTRADED) // here it is not guid but slot. Also prevents hacking slots
                if (TradeData* pTrade = player->GetTradeData())
                    m_itemTarget = pTrade->GetTraderData()->GetItem(TRADE_SLOT_NONTRADED);

        if (m_itemTarget)
            m_itemTargetEntry = m_itemTarget->GetEntry();
    }

    // update positions by transport move
    if (HasSrc() && m_src._transportGUID)
    {
        if (WorldObject* transport = ObjectAccessor::GetWorldObject(*caster, m_src._transportGUID))
        {
            m_src._position.Relocate(transport);
            m_src._position.RelocateOffset(m_src._transportOffset);
        }
    }

    if (HasDst() && m_dst._transportGUID)
    {
        if (WorldObject* transport = ObjectAccessor::GetWorldObject(*caster, m_dst._transportGUID))
        {
            m_dst._position.Relocate(transport);
            m_dst._position.RelocateOffset(m_dst._transportOffset);
        }
    }
}

SpellValue::SpellValue(SpellInfo const* proto)
{
    for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        EffectBasePoints[i] = proto->Effects[i].BasePoints;
    MaxAffectedTargets = proto->MaxAffectedTargets;
    RadiusMod = 1.0f;
    AuraStackAmount = 1;
    CriticalChance = 0.f;
}

class TC_GAME_API SpellEvent : public BasicEvent
{
public:
    SpellEvent(Spell* spell);
    ~SpellEvent();

    bool Execute(uint64 e_time, uint32 p_time) override;
    void Abort(uint64 e_time) override;
    bool IsDeletable() const override;
    Spell const* GetSpell() const { return m_Spell; }

protected:
    Spell* m_Spell;
};

Spell::Spell(WorldObject* caster, SpellInfo const* info, TriggerCastFlags triggerFlags, ObjectGuid originalCasterGUID) :
m_spellInfo(sSpellMgr->GetSpellForDifficultyFromSpell(info, caster)),
m_caster((info->HasAttribute(SPELL_ATTR6_ORIGINATE_FROM_CONTROLLER) && caster->GetCharmerOrOwner()) ? caster->GetCharmerOrOwner() : caster)
, m_spellValue(new SpellValue(m_spellInfo)), _spellEvent(nullptr)
{
    m_customError = SPELL_CUSTOM_ERROR_NONE;
    m_selfContainer = nullptr;
    m_referencedFromCurrentSpell = false;
    m_executedCurrently = false;
    m_needComboPoints = m_spellInfo->NeedsComboPoints();
    m_comboPointGain = 0;
    m_delayStart = 0;
    m_delayAtDamageCount = 0;
    m_castFlagsEx = 0;

    m_applyMultiplierMask = 0;
    m_auraScaleMask = 0;
    memset(m_damageMultipliers, 0, sizeof(m_damageMultipliers));

    // Get data for type of attack
    switch (m_spellInfo->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_MELEE:
            if (m_spellInfo->HasAttribute(SPELL_ATTR3_REQUIRES_OFF_HAND_WEAPON))
                m_attackType = OFF_ATTACK;
            else
                m_attackType = BASE_ATTACK;
            break;
        case SPELL_DAMAGE_CLASS_RANGED:
            m_attackType = m_spellInfo->IsRangedWeaponSpell() ? RANGED_ATTACK : BASE_ATTACK;
            break;
        default:
                                                            // Wands
            if (m_spellInfo->HasAttribute(SPELL_ATTR2_AUTO_REPEAT))
                m_attackType = RANGED_ATTACK;
            else
                m_attackType = BASE_ATTACK;
            break;
    }

    m_spellSchoolMask = info->GetSchoolMask();           // Can be override for some spell (wand shoot for example)

    if (Player const* playerCaster = m_caster->ToPlayer())
    {
        // wand case
        if (m_attackType == RANGED_ATTACK)
            if ((playerCaster->getClassMask() & CLASSMASK_WAND_USERS) != 0)
                if (Item* pItem = playerCaster->GetWeaponForAttack(RANGED_ATTACK))
                    m_spellSchoolMask = SpellSchoolMask(1 << pItem->GetTemplate()->GetDamageType());
    }

    if (originalCasterGUID)
        m_originalCasterGUID = originalCasterGUID;
    else
        m_originalCasterGUID = m_caster->GetGUID();

    if (m_originalCasterGUID == m_caster->GetGUID())
        m_originalCaster = m_caster->ToUnit();
    else
    {
        m_originalCaster = ObjectAccessor::GetUnit(*m_caster, m_originalCasterGUID);
        if (m_originalCaster && !m_originalCaster->IsInWorld())
            m_originalCaster = nullptr;
    }

    m_spellState = SPELL_STATE_NULL;
    _triggeredCastFlags = triggerFlags;

    if (info->HasAttribute(SPELL_ATTR2_DO_NOT_REPORT_SPELL_FAILURE))
        _triggeredCastFlags = TriggerCastFlags(uint32(_triggeredCastFlags) | TRIGGERED_DONT_REPORT_CAST_ERROR);

    if (info->HasAttribute(SPELL_ATTR4_ALLOW_CAST_WHILE_CASTING))
        _triggeredCastFlags = TriggerCastFlags(uint32(_triggeredCastFlags) | TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_CAST_DIRECTLY);

    m_CastItem = nullptr;
    m_castItemGUID.Clear();
    m_castItemEntry = 0;

    unitTarget = nullptr;
    itemTarget = nullptr;
    gameObjTarget = nullptr;
    corpseTarget = nullptr;
    destTarget = nullptr;
    damage = 0;
    targetMissInfo = SPELL_MISS_NONE;
    effectHandleMode = SPELL_EFFECT_HANDLE_LAUNCH;
    m_damage = 0;
    m_healing = 0;
    m_procAttacker = PROC_FLAG_NONE;
    m_procVictim = PROC_FLAG_NONE;
    m_hitMask = 0;
    focusObject = nullptr;
    m_cast_count = 0;
    m_glyphIndex = 0;
    m_triggeredByAuraSpell  = nullptr;
    unitCaster = nullptr;
    _spellAura = nullptr;
    _dynObjAura = nullptr;

    //Auto Shot & Shoot (wand)
    m_autoRepeat = m_spellInfo->IsAutoRepeatRangedSpell();

    m_runesState = 0;
    m_powerCost = 0;                                        // setup to correct value in Spell::prepare, must not be used before.
    m_casttime = 0;                                         // setup to correct value in Spell::prepare, must not be used before.
    m_timer = 0;                                            // will set to castime in prepare
    m_channeledDuration = 0;                                // will be setup in Spell::handle_immediate
    m_immediateHandled = false;

    m_channelTargetEffectMask = 0;

    // Determine if spell can be reflected back to the caster
    // Patch 1.2 notes: Spell Reflection no longer reflects abilities
    m_canReflect = caster->IsUnit() && m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MAGIC && !m_spellInfo->HasAttribute(SPELL_ATTR0_IS_ABILITY)
        && !m_spellInfo->HasAttribute(SPELL_ATTR1_NO_REFLECTION) && !m_spellInfo->HasAttribute(SPELL_ATTR0_NO_IMMUNITIES)
        && !m_spellInfo->IsPassive();

    CleanupTargetList();
    memset(m_effectExecuteData, 0, MAX_SPELL_EFFECTS * sizeof(ByteBuffer*));

    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        m_destTargets[i] = SpellDestination(*m_caster);
}

Spell::~Spell()
{
    // unload scripts
    for (auto itr = m_loadedScripts.begin(); itr != m_loadedScripts.end(); ++itr)
    {
        (*itr)->_Unload();
        delete (*itr);
    }

    if (m_referencedFromCurrentSpell && m_selfContainer && *m_selfContainer == this)
    {
        // Clean the reference to avoid later crash.
        // If this error is repeating, we may have to add an ASSERT to better track down how we get into this case.
        TC_LOG_ERROR("spells", "SPELL: deleting spell for spell ID %u. However, spell still referenced.", m_spellInfo->Id);
        *m_selfContainer = nullptr;
    }

    if (m_caster && m_caster->GetTypeId() == TYPEID_PLAYER)
        ASSERT(m_caster->ToPlayer()->m_spellModTakingSpell != this);

    delete m_spellValue;

    // missing cleanup somewhere, mem leaks so let's crash
    AssertEffectExecuteData();
}

void Spell::InitExplicitTargets(SpellCastTargets const& targets)
{
    m_targets = targets;
    m_targets.SetOrigUnitTarget(m_targets.GetUnitTarget());
    // this function tries to correct spell explicit targets for spell
    // client doesn't send explicit targets correctly sometimes - we need to fix such spells serverside
    // this also makes sure that we correctly send explicit targets to client (removes redundant data)
    uint32 neededTargets = m_spellInfo->GetExplicitTargetMask();

    if (WorldObject* target = m_targets.GetObjectTarget())
    {
        // check if object target is valid with needed target flags
        // for unit case allow corpse target mask because player with not released corpse is a unit target
        if ((target->ToUnit() && !(neededTargets & (TARGET_FLAG_UNIT_MASK | TARGET_FLAG_CORPSE_MASK)))
            || (target->ToGameObject() && !(neededTargets & TARGET_FLAG_GAMEOBJECT_MASK))
            || (target->ToCorpse() && !(neededTargets & TARGET_FLAG_CORPSE_MASK)))
            m_targets.RemoveObjectTarget();
    }
    else
    {
        // try to select correct unit target if not provided by client or by serverside cast
        if (neededTargets & (TARGET_FLAG_UNIT_MASK))
        {
            Unit* unit = nullptr;
            // try to use player selection as a target
            if (Player* playerCaster = m_caster->ToPlayer())
            {
                // selection has to be found and to be valid target for the spell
                if (Unit* selectedUnit = ObjectAccessor::GetUnit(*m_caster, playerCaster->GetTarget()))
                    if (m_spellInfo->CheckExplicitTarget(m_caster, selectedUnit) == SPELL_CAST_OK)
                        unit = selectedUnit;
            }
            // try to use attacked unit as a target
            else if ((m_caster->GetTypeId() == TYPEID_UNIT) && neededTargets & (TARGET_FLAG_UNIT_ENEMY | TARGET_FLAG_UNIT))
                unit = m_caster->ToUnit()->GetVictim();

            // didn't find anything - let's use self as target
            if (!unit && neededTargets & (TARGET_FLAG_UNIT_RAID | TARGET_FLAG_UNIT_PARTY | TARGET_FLAG_UNIT_ALLY))
                unit = m_caster->ToUnit();

            m_targets.SetUnitTarget(unit);
        }
    }

    // check if spell needs dst target
    if (neededTargets & TARGET_FLAG_DEST_LOCATION)
    {
        // and target isn't set
        if (!m_targets.HasDst())
        {
            // try to use unit target if provided
            if (WorldObject* target = targets.GetObjectTarget())
                m_targets.SetDst(*target);
            // or use self if not available
            else
                m_targets.SetDst(*m_caster);
        }
    }
    else
        m_targets.RemoveDst();

    if (neededTargets & TARGET_FLAG_SOURCE_LOCATION)
    {
        if (!targets.HasSrc())
            m_targets.SetSrc(*m_caster);
    }
    else
        m_targets.RemoveSrc();
}

void Spell::SelectExplicitTargets()
{
    // here go all explicit target changes made to explicit targets after spell prepare phase is finished
    if (Unit* target = m_targets.GetUnitTarget())
    {
        // check for explicit target redirection, for Grounding Totem for example
        if ((m_spellInfo->GetExplicitTargetMask() & TARGET_FLAG_UNIT_ENEMY) ||
            ((m_spellInfo->GetExplicitTargetMask() & TARGET_FLAG_UNIT) && !m_caster->IsFriendlyTo(target)))
        {
            Unit* redirect = nullptr;
            switch (m_spellInfo->DmgClass)
            {
                case SPELL_DAMAGE_CLASS_MAGIC:
                    redirect = m_caster->GetMagicHitRedirectTarget(target, m_spellInfo);
                    break;
                case SPELL_DAMAGE_CLASS_MELEE:
                case SPELL_DAMAGE_CLASS_RANGED:
                    // should gameobjects cast damagetype melee/ranged spells this needs to be changed
                    redirect = ASSERT_NOTNULL(m_caster->ToUnit())->GetMeleeHitRedirectTarget(target, m_spellInfo);
                    break;
                default:
                    break;
            }
            if (redirect && (redirect != target))
                m_targets.SetUnitTarget(redirect);
        }
    }
}

void Spell::SelectSpellTargets()
{
    // select targets for cast phase
    SelectExplicitTargets();

    uint32 processedAreaEffectsMask = 0;
    for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        // not call for empty effect.
        // Also some spells use not used effect targets for store targets for dummy effect in triggered spells
        if (!m_spellInfo->Effects[i].IsEffect())
            continue;

        // set expected type of implicit targets to be sent to client
        uint32 implicitTargetMask = GetTargetFlagMask(m_spellInfo->Effects[i].TargetA.GetObjectType()) | GetTargetFlagMask(m_spellInfo->Effects[i].TargetB.GetObjectType());
        if (implicitTargetMask & TARGET_FLAG_UNIT)
            m_targets.SetTargetFlag(TARGET_FLAG_UNIT);
        if (implicitTargetMask & (TARGET_FLAG_GAMEOBJECT | TARGET_FLAG_GAMEOBJECT_ITEM))
            m_targets.SetTargetFlag(TARGET_FLAG_GAMEOBJECT);

        SelectEffectImplicitTargets(SpellEffIndex(i), m_spellInfo->Effects[i].TargetA, processedAreaEffectsMask);
        SelectEffectImplicitTargets(SpellEffIndex(i), m_spellInfo->Effects[i].TargetB, processedAreaEffectsMask);

        // Select targets of effect based on effect type
        // those are used when no valid target could be added for spell effect based on spell target type
        // some spell effects use explicit target as a default target added to target map (like SPELL_EFFECT_LEARN_SPELL)
        // some spell effects add target to target map only when target type specified (like SPELL_EFFECT_WEAPON)
        // some spell effects don't add anything to target map (confirmed with sniffs) (like SPELL_EFFECT_DESTROY_ALL_TOTEMS)
        SelectEffectTypeImplicitTargets(i);

        if (m_targets.HasDst())
            AddDestTarget(*m_targets.GetDst(), i);

        if (m_spellInfo->Effects[i].TargetA.GetObjectType() == TARGET_OBJECT_TYPE_UNIT
            || m_spellInfo->Effects[i].TargetA.GetObjectType() == TARGET_OBJECT_TYPE_UNIT_AND_DEST
            || m_spellInfo->Effects[i].TargetB.GetObjectType() == TARGET_OBJECT_TYPE_UNIT
            || m_spellInfo->Effects[i].TargetB.GetObjectType() == TARGET_OBJECT_TYPE_UNIT_AND_DEST)
        {
            if (m_spellInfo->HasAttribute(SPELL_ATTR1_REQUIRE_ALL_TARGETS))
            {
                bool noTargetFound = std::none_of(m_UniqueTargetInfo.begin(), m_UniqueTargetInfo.end(), [effectMask = 1u << i](TargetInfo const& target)
                {
                    return target.EffectMask & effectMask;
                });

                if (noTargetFound)
                {
                    SendCastResult(SPELL_FAILED_BAD_IMPLICIT_TARGETS);
                    finish(false);
                    return;
                }
            }
            if (m_spellInfo->HasAttribute(SPELL_ATTR2_FAIL_ON_ALL_TARGETS_IMMUNE))
            {
                bool anyNonImmuneTargetFound = std::any_of(m_UniqueTargetInfo.begin(), m_UniqueTargetInfo.end(), [effectMask = 1u << i](TargetInfo const& target)
                {
                    return target.EffectMask & effectMask && target.MissCondition != SPELL_MISS_IMMUNE && target.MissCondition != SPELL_MISS_IMMUNE2;
                });

                if (!anyNonImmuneTargetFound)
                {
                    SendCastResult(SPELL_FAILED_IMMUNE);
                    finish(false);
                    return;
                }
            }
        }

        if (m_spellInfo->IsChanneled())
        {
            // maybe do this for all spells?
            if (!focusObject && m_UniqueTargetInfo.empty() && m_UniqueGOTargetInfo.empty() && m_UniqueItemInfo.empty() && !m_targets.HasDst())
            {
                SendCastResult(SPELL_FAILED_BAD_IMPLICIT_TARGETS);
                finish(false);
                return;
            }

            uint8 mask = (1 << i);
            for (auto ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
            {
                if (ihit->EffectMask & mask)
                {
                    m_channelTargetEffectMask |= mask;
                    break;
                }
            }
        }
        else if (m_auraScaleMask)
        {
            bool checkLvl = !m_UniqueTargetInfo.empty();
            m_UniqueTargetInfo.erase(std::remove_if(std::begin(m_UniqueTargetInfo), std::end(m_UniqueTargetInfo), [&](TargetInfo const& targetInfo) -> bool
            {
                // remove targets which did not pass min level check
                if (m_auraScaleMask && targetInfo.EffectMask == m_auraScaleMask)
                {
                    // Do not check for selfcast
                    if (!targetInfo.ScaleAura && targetInfo.TargetGUID != m_caster->GetGUID())
                        return true;
                }

                return false;
            }), std::end(m_UniqueTargetInfo));

            if (checkLvl && m_UniqueTargetInfo.empty())
            {
                SendCastResult(SPELL_FAILED_LOWLEVEL);
                finish(false);
            }
        }
    }

    if (uint64 dstDelay = CalculateDelayMomentForDst())
        m_delayMoment = dstDelay;
}

uint64 Spell::CalculateDelayMomentForDst() const
{
    if (m_targets.HasDst())
    {
        if (m_targets.HasTraj())
        {
            float speed = m_targets.GetSpeedXY();
            if (speed > 0.0f)
                return uint64(std::floor(m_targets.GetDist2d() / speed * 1000.0f));
        }
        else if (m_spellInfo->Speed > 0.0f)
        {
            float dist = m_caster->GetExactDist(*m_targets.GetDstPos());
            if (!m_spellInfo->HasAttribute(SPELL_ATTR9_SPECIAL_DELAY_CALCULATION))
                return uint64(std::floor(dist / m_spellInfo->Speed * 1000.0f));
            else
                return uint64(m_spellInfo->Speed * 1000.0f);
        }
    }

    return 0;
}

void Spell::RecalculateDelayMomentForDst()
{
    m_delayMoment = CalculateDelayMomentForDst();
    m_caster->m_Events.ModifyEventTime(_spellEvent, GetDelayStart() + m_delayMoment);
}

void Spell::SelectEffectImplicitTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType, uint32& processedEffectMask)
{
    if (!targetType.GetTarget())
        return;

    uint32 effectMask = 1 << effIndex;
    // set the same target list for all effects
    // some spells appear to need this, however this requires more research
    switch (targetType.GetSelectionCategory())
    {
        case TARGET_SELECT_CATEGORY_NEARBY:
        case TARGET_SELECT_CATEGORY_CONE:
        case TARGET_SELECT_CATEGORY_AREA:
            // targets for effect already selected
            if (effectMask & processedEffectMask)
                return;
            // choose which targets we can select at once
            for (uint32 j = effIndex + 1; j < MAX_SPELL_EFFECTS; ++j)
            {
                SpellEffectInfo const* effects = GetSpellInfo()->Effects;
                if (effects[j].IsEffect() &&
                    effects[effIndex].TargetA.GetTarget() == effects[j].TargetA.GetTarget() &&
                    effects[effIndex].TargetB.GetTarget() == effects[j].TargetB.GetTarget() &&
                    effects[effIndex].ImplicitTargetConditions == effects[j].ImplicitTargetConditions &&
                    effects[effIndex].CalcRadius(m_caster) == effects[j].CalcRadius(m_caster) &&
                    CheckScriptEffectImplicitTargets(effIndex, j))
                {
                    effectMask |= 1 << j;
                }
            }
            processedEffectMask |= effectMask;
            break;
        default:
            break;
    }

    switch (targetType.GetSelectionCategory())
    {
        case TARGET_SELECT_CATEGORY_CHANNEL:
            SelectImplicitChannelTargets(effIndex, targetType);
            break;
        case TARGET_SELECT_CATEGORY_NEARBY:
            SelectImplicitNearbyTargets(effIndex, targetType, effectMask);
            break;
        case TARGET_SELECT_CATEGORY_CONE:
            SelectImplicitConeTargets(effIndex, targetType, effectMask);
            break;
        case TARGET_SELECT_CATEGORY_AREA:
            SelectImplicitAreaTargets(effIndex, targetType, effectMask);
            break;
        case TARGET_SELECT_CATEGORY_TRAJ:
            // just in case there is no dest, explanation in SelectImplicitDestDestTargets
            CheckDst();

            SelectImplicitTrajTargets(effIndex, targetType);
            break;
        case TARGET_SELECT_CATEGORY_DEFAULT:
            switch (targetType.GetObjectType())
            {
                case TARGET_OBJECT_TYPE_SRC:
                    switch (targetType.GetReferenceType())
                    {
                        case TARGET_REFERENCE_TYPE_CASTER:
                            m_targets.SetSrc(*m_caster);
                            break;
                        default:
                            ASSERT(false && "Spell::SelectEffectImplicitTargets: received not implemented select target reference type for TARGET_TYPE_OBJECT_SRC");
                            break;
                    }
                    break;
                case TARGET_OBJECT_TYPE_DEST:
                     switch (targetType.GetReferenceType())
                     {
                         case TARGET_REFERENCE_TYPE_CASTER:
                             SelectImplicitCasterDestTargets(effIndex, targetType);
                             break;
                         case TARGET_REFERENCE_TYPE_TARGET:
                             SelectImplicitTargetDestTargets(effIndex, targetType);
                             break;
                         case TARGET_REFERENCE_TYPE_DEST:
                             SelectImplicitDestDestTargets(effIndex, targetType);
                             break;
                         default:
                             ASSERT(false && "Spell::SelectEffectImplicitTargets: received not implemented select target reference type for TARGET_TYPE_OBJECT_DEST");
                             break;
                     }
                     break;
                default:
                    switch (targetType.GetReferenceType())
                    {
                        case TARGET_REFERENCE_TYPE_CASTER:
                            SelectImplicitCasterObjectTargets(effIndex, targetType);
                            break;
                        case TARGET_REFERENCE_TYPE_TARGET:
                            SelectImplicitTargetObjectTargets(effIndex, targetType);
                            break;
                        default:
                            ASSERT(false && "Spell::SelectEffectImplicitTargets: received not implemented select target reference type for TARGET_TYPE_OBJECT");
                            break;
                    }
                    break;
            }
            break;
        case TARGET_SELECT_CATEGORY_NYI:
            TC_LOG_DEBUG("spells", "SPELL: target type %u, found in spellID %u, effect %u is not implemented yet!", m_spellInfo->Id, effIndex, targetType.GetTarget());
            break;
        default:
            ASSERT(false && "Spell::SelectEffectImplicitTargets: received not implemented select target category");
            break;
    }
}

void Spell::SelectImplicitChannelTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType)
{
    if (targetType.GetReferenceType() != TARGET_REFERENCE_TYPE_CASTER)
    {
        ASSERT(false && "Spell::SelectImplicitChannelTargets: received not implemented target reference type");
        return;
    }

    Spell* channeledSpell = m_originalCaster->GetCurrentSpell(CURRENT_CHANNELED_SPELL);
    if (!channeledSpell)
    {
        TC_LOG_DEBUG("spells", "Spell::SelectImplicitChannelTargets: cannot find channel spell for spell ID %u, effect %u", m_spellInfo->Id, effIndex);
        return;
    }
    switch (targetType.GetTarget())
    {
        case TARGET_UNIT_CHANNEL_TARGET:
        {
            WorldObject* target = ObjectAccessor::GetUnit(*m_caster, m_originalCaster->GetChannelObjectGuid());
            CallScriptObjectTargetSelectHandlers(target, effIndex, targetType);
            // unit target may be no longer avalible - teleported out of map for example
            if (target && target->ToUnit())
                AddUnitTarget(target->ToUnit(), 1 << effIndex);
            else
                TC_LOG_DEBUG("spells", "SPELL: cannot find channel spell target for spell ID %u, effect %u", m_spellInfo->Id, effIndex);
            break;
        }
        case TARGET_DEST_CHANNEL_TARGET:
            if (channeledSpell->m_targets.HasDst())
                m_targets.SetDst(channeledSpell->m_targets);
            else if (WorldObject* target = ObjectAccessor::GetWorldObject(*m_caster, m_originalCaster->GetChannelObjectGuid()))
            {
                CallScriptObjectTargetSelectHandlers(target, effIndex, targetType);
                if (target)
                {
                    SpellDestination dest(*target);
                    CallScriptDestinationTargetSelectHandlers(dest, effIndex, targetType);
                    m_targets.SetDst(dest);
                }
            }
            else
                TC_LOG_DEBUG("spells", "SPELL: cannot find channel spell destination for spell ID %u, effect %u", m_spellInfo->Id, effIndex);
            break;
        case TARGET_DEST_CHANNEL_CASTER:
        {
            SpellDestination dest(*channeledSpell->GetCaster());
            CallScriptDestinationTargetSelectHandlers(dest, effIndex, targetType);
            m_targets.SetDst(dest);
            break;
        }
        default:
            ASSERT(false && "Spell::SelectImplicitChannelTargets: received not implemented target type");
            break;
    }
}

void Spell::SelectImplicitNearbyTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType, uint32 effMask)
{
    if (targetType.GetReferenceType() != TARGET_REFERENCE_TYPE_CASTER)
    {
        ASSERT(false && "Spell::SelectImplicitNearbyTargets: received not implemented target reference type");
        return;
    }

    float range = 0.0f;
    switch (targetType.GetCheckType())
    {
        case TARGET_CHECK_ENEMY:
            range = m_spellInfo->GetMaxRange(false, m_caster, this);
            break;
        case TARGET_CHECK_ALLY:
        case TARGET_CHECK_PARTY:
        case TARGET_CHECK_RAID:
        case TARGET_CHECK_RAID_CLASS:
            range = m_spellInfo->GetMaxRange(true, m_caster, this);
            break;
        case TARGET_CHECK_ENTRY:
        case TARGET_CHECK_DEFAULT:
            range = m_spellInfo->GetMaxRange(IsPositive(), m_caster, this);
            break;
        default:
            ASSERT(false && "Spell::SelectImplicitNearbyTargets: received not implemented selection check type");
            break;
    }

    ConditionContainer* condList = m_spellInfo->Effects[effIndex].ImplicitTargetConditions;

    // handle emergency case - try to use other provided targets if no conditions provided
    if (targetType.GetCheckType() == TARGET_CHECK_ENTRY && (!condList || condList->empty()))
    {
        TC_LOG_DEBUG("spells", "Spell::SelectImplicitNearbyTargets: no conditions entry for target with TARGET_CHECK_ENTRY of spell ID %u, effect %u - selecting default targets", m_spellInfo->Id, effIndex);
        switch (targetType.GetObjectType())
        {
            case TARGET_OBJECT_TYPE_GOBJ:
                if (m_spellInfo->RequiresSpellFocus)
                {
                    if (focusObject)
                        AddGOTarget(focusObject, effMask);
                    else
                    {
                        SendCastResult(SPELL_FAILED_BAD_IMPLICIT_TARGETS);
                        finish(false);
                    }
                    return;
                }
                break;
            case TARGET_OBJECT_TYPE_DEST:
                if (m_spellInfo->RequiresSpellFocus)
                {
                    if (focusObject)
                    {
                        SpellDestination dest(*focusObject);
                        CallScriptDestinationTargetSelectHandlers(dest, effIndex, targetType);
                        m_targets.SetDst(dest);
                    }
                    else
                    {
                        SendCastResult(SPELL_FAILED_BAD_IMPLICIT_TARGETS);
                        finish(false);
                    }
                    return;
                }
                break;
            default:
                break;
        }
    }

    WorldObject* target = SearchNearbyTarget(range, targetType.GetObjectType(), targetType.GetCheckType(), condList);
    if (!target)
    {
        TC_LOG_DEBUG("spells", "Spell::SelectImplicitNearbyTargets: cannot find nearby target for spell ID %u, effect %u", m_spellInfo->Id, effIndex);
        SendCastResult(SPELL_FAILED_BAD_IMPLICIT_TARGETS);
        finish(false);
        return;
    }

    CallScriptObjectTargetSelectHandlers(target, effIndex, targetType);
    if (!target)
    {
        TC_LOG_DEBUG("spells", "Spell::SelectImplicitNearbyTargets: OnObjectTargetSelect script hook for spell Id %u set nullptr target, effect %u", m_spellInfo->Id, effIndex);
        SendCastResult(SPELL_FAILED_BAD_IMPLICIT_TARGETS);
        finish(false);
        return;
    }

    switch (targetType.GetObjectType())
    {
        case TARGET_OBJECT_TYPE_UNIT:
            if (Unit* unit = target->ToUnit())
                AddUnitTarget(unit, effMask, true, false);
            else
            {
                TC_LOG_DEBUG("spells", "Spell::SelectImplicitNearbyTargets: OnObjectTargetSelect script hook for spell Id %u set object of wrong type, expected unit, got %s, effect %u", m_spellInfo->Id, target->GetGUID().GetTypeName(), effMask);
                SendCastResult(SPELL_FAILED_BAD_IMPLICIT_TARGETS);
                finish(false);
                return;
            }
            break;
        case TARGET_OBJECT_TYPE_GOBJ:
            if (GameObject* gobjTarget = target->ToGameObject())
                AddGOTarget(gobjTarget, effMask);
            else
            {
                TC_LOG_DEBUG("spells", "Spell::SelectImplicitNearbyTargets: OnObjectTargetSelect script hook for spell Id %u set object of wrong type, expected gameobject, got %s, effect %u", m_spellInfo->Id, target->GetGUID().GetTypeName(), effMask);
                SendCastResult(SPELL_FAILED_BAD_IMPLICIT_TARGETS);
                finish(false);
                return;
            }
            break;
        case TARGET_OBJECT_TYPE_CORPSE:
            if (Corpse* corpse = target->ToCorpse())
                AddCorpseTarget(corpse, effMask);
            else
            {
                TC_LOG_DEBUG("spells", "Spell::SelectImplicitNearbyTargets: OnObjectTargetSelect script hook for spell Id %u set object of wrong type, expected corpse, got %s, effect %u", m_spellInfo->Id, target->GetGUID().GetTypeName(), effMask);
                SendCastResult(SPELL_FAILED_BAD_IMPLICIT_TARGETS);
                finish(false);
                return;
            }
            break;
        case TARGET_OBJECT_TYPE_DEST:
        {
            SpellDestination dest(*target);
            CallScriptDestinationTargetSelectHandlers(dest, effIndex, targetType);
            m_targets.SetDst(dest);
            break;
        }
        default:
            ASSERT(false && "Spell::SelectImplicitNearbyTargets: received not implemented target object type");
            break;
    }

    SelectImplicitChainTargets(effIndex, targetType, target, effMask);
}

void Spell::SelectImplicitConeTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType, uint32 effMask)
{
    Position coneSrc(*m_caster);
    float coneAngle = m_spellInfo->ConeAngle;
    switch (targetType.GetReferenceType())
    {
        case TARGET_REFERENCE_TYPE_CASTER:
            break;
        case TARGET_REFERENCE_TYPE_DEST:
            if (m_caster->GetExactDist2d(m_targets.GetDstPos()) > 0.1f)
                coneSrc.SetOrientation(m_caster->GetAngle(m_targets.GetDstPos()));
            break;
        default:
            break;
    }

    switch (targetType.GetTarget())
    {
        case TARGET_UNIT_CONE_180_DEG_ENEMY:
            if (coneAngle == 0.0f)
                coneAngle = 180.0f;
            break;
        default:
            break;
    }

    std::list<WorldObject*> targets;
    SpellTargetObjectTypes objectType = targetType.GetObjectType();
    SpellTargetCheckTypes selectionType = targetType.GetCheckType();
    ConditionContainer* condList = m_spellInfo->Effects[effIndex].ImplicitTargetConditions;

    float radius = m_spellInfo->Effects[effIndex].CalcRadius(m_caster);
    // Workaround for some spells that don't have RadiusEntry set in dbc (but SpellRange instead)
    if (G3D::fuzzyEq(radius, 0.f))
        radius = m_spellInfo->GetMaxRange(m_spellInfo->IsPositiveEffect(effIndex), m_caster, this);

    radius *= m_spellValue->RadiusMod;

    if (uint32 containerTypeMask = GetSearcherTypeMask(objectType, condList))
    {
        Trinity::WorldObjectSpellConeTargetCheck check(coneSrc, DegToRad(coneAngle), radius, m_caster, m_spellInfo, selectionType, condList);
        Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellConeTargetCheck> searcher(m_caster, targets, check, containerTypeMask);
        SearchTargets<Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellConeTargetCheck> >(searcher, containerTypeMask, m_caster, m_caster, radius);

        CallScriptObjectAreaTargetSelectHandlers(targets, effIndex, targetType);

        if (!targets.empty())
        {
            // Other special target selection goes here
            if (uint32 maxTargets = m_spellValue->MaxAffectedTargets)
                Trinity::Containers::RandomResize(targets, maxTargets);

            for (WorldObject* itr : targets)
            {
                if (Unit* unit = itr->ToUnit())
                    AddUnitTarget(unit, effMask, false);
                else if (GameObject* gObjTarget = itr->ToGameObject())
                    AddGOTarget(gObjTarget, effMask);
                else if (Corpse* corpse = itr->ToCorpse())
                    AddCorpseTarget(corpse, effMask);
            }
        }
    }
}

void Spell::SelectImplicitAreaTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType, uint32 effMask)
{
    WorldObject* referer = nullptr;
    switch (targetType.GetReferenceType())
    {
        case TARGET_REFERENCE_TYPE_SRC:
        case TARGET_REFERENCE_TYPE_DEST:
        case TARGET_REFERENCE_TYPE_CASTER:
            referer = m_caster;
            break;
        case TARGET_REFERENCE_TYPE_TARGET:
            referer = m_targets.GetUnitTarget();
            break;
        case TARGET_REFERENCE_TYPE_LAST:
        {
            // find last added target for this effect
            for (auto ihit = m_UniqueTargetInfo.rbegin(); ihit != m_UniqueTargetInfo.rend(); ++ihit)
            {
                if (ihit->EffectMask & (1 << effIndex))
                {
                    referer = ObjectAccessor::GetUnit(*m_caster, ihit->TargetGUID);
                    break;
                }
            }
            break;
        }
        default:
            ASSERT(false && "Spell::SelectImplicitAreaTargets: received not implemented target reference type");
            return;
    }

    if (!referer)
        return;

    Position const* center = nullptr;
    switch (targetType.GetReferenceType())
    {
        case TARGET_REFERENCE_TYPE_SRC:
            center = m_targets.GetSrcPos();
            break;
        case TARGET_REFERENCE_TYPE_DEST:
            center = m_targets.GetDstPos();
            break;
        case TARGET_REFERENCE_TYPE_CASTER:
        case TARGET_REFERENCE_TYPE_TARGET:
        case TARGET_REFERENCE_TYPE_LAST:
            center = referer;
            break;
         default:
             ASSERT(false && "Spell::SelectImplicitAreaTargets: received not implemented target reference type");
             return;
    }

    float radius = m_spellInfo->Effects[effIndex].CalcRadius(m_caster);

    // Workaround for some spells that don't have RadiusEntry set in dbc (but SpellRange instead)
    if (G3D::fuzzyEq(radius, 0.f))
        radius = m_spellInfo->GetMaxRange(m_spellInfo->IsPositiveEffect(effIndex), m_caster, this);

    radius *= m_spellValue->RadiusMod;

    std::list<WorldObject*> targets;
    switch (targetType.GetTarget())
    {
        case TARGET_UNIT_CASTER_AND_PASSENGERS:
            targets.push_back(m_caster);
            if (Unit* unit = m_caster->ToUnit())
                if (Vehicle const* vehicleKit = unit->GetVehicleKit())
                    for (int8 seat = 0; seat < MAX_VEHICLE_SEATS; ++seat)
                        if (Unit* passenger = vehicleKit->GetPassenger(seat))
                            targets.push_back(passenger);
            break;
        case TARGET_UNIT_TARGET_ALLY_OR_RAID:
            if (Unit* targetedUnit = m_targets.GetUnitTarget())
            {
                if (!m_caster->IsUnit() || !m_caster->ToUnit()->IsInRaidWith(targetedUnit))
                    targets.push_back(m_targets.GetUnitTarget());
                else
                    SearchAreaTargets(targets, radius, targetedUnit, referer, targetType.GetObjectType(), targetType.GetCheckType(), m_spellInfo->Effects[effIndex].ImplicitTargetConditions);
            }
            break;
        case TARGET_UNIT_CASTER_AND_SUMMONS:
            targets.push_back(m_caster);
            SearchAreaTargets(targets, radius, center, referer, targetType.GetObjectType(), targetType.GetCheckType(), m_spellInfo->Effects[effIndex].ImplicitTargetConditions);
            break;
        default:
            SearchAreaTargets(targets, radius, center, referer, targetType.GetObjectType(), targetType.GetCheckType(), m_spellInfo->Effects[effIndex].ImplicitTargetConditions);
            break;
    }

    CallScriptObjectAreaTargetSelectHandlers(targets, effIndex, targetType);

    if (!targets.empty())
    {
        // Other special target selection goes here
        if (uint32 maxTargets = m_spellValue->MaxAffectedTargets)
            Trinity::Containers::RandomResize(targets, maxTargets);

        for (WorldObject* itr : targets)
        {
            if (Unit* unit = itr->ToUnit())
                AddUnitTarget(unit, effMask, false, true, center);
            else if (GameObject* gObjTarget = itr->ToGameObject())
                AddGOTarget(gObjTarget, effMask);
            else if (Corpse* corpse = itr->ToCorpse())
                AddCorpseTarget(corpse, effMask);
        }
    }
}

void Spell::SelectImplicitCasterDestTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType)
{
    SpellDestination dest(*m_caster);

    switch (targetType.GetTarget())
    {
        case TARGET_DEST_CASTER:
            break;
        case TARGET_DEST_HOME:
            if (Player* playerCaster = m_caster->ToPlayer())
                dest = SpellDestination(playerCaster->m_homebindX, playerCaster->m_homebindY, playerCaster->m_homebindZ, playerCaster->GetOrientation(), playerCaster->m_homebindMapId);
            break;
        case TARGET_DEST_DB:
            if (SpellTargetPosition const* st = sSpellMgr->GetSpellTargetPosition(m_spellInfo->Id, effIndex))
            {
                /// @todo fix this check
                if (m_spellInfo->HasEffect(SPELL_EFFECT_TELEPORT_UNITS) || m_spellInfo->HasEffect(SPELL_EFFECT_BIND))
                    dest = SpellDestination(st->target_X, st->target_Y, st->target_Z, st->target_Orientation, (int32)st->target_mapId);
                else if (st->target_mapId == m_caster->GetMapId())
                    dest = SpellDestination(st->target_X, st->target_Y, st->target_Z, st->target_Orientation);
            }
            else
            {
                TC_LOG_DEBUG("spells", "SPELL: unknown target coordinates for spell ID %u", m_spellInfo->Id);
                if (WorldObject* target = m_targets.GetObjectTarget())
                    dest = SpellDestination(*target);
            }
            break;
        case TARGET_DEST_CASTER_FISHING:
        {
            float minDist = m_spellInfo->GetMinRange(true);
            float maxDist = m_spellInfo->GetMaxRange(true);
            float dist = frand(minDist, maxDist);
            float x, y, z;
            float angle = float(rand_norm()) * static_cast<float>(M_PI * 35.0f / 180.0f) - static_cast<float>(M_PI * 17.5f / 180.0f);
            m_caster->GetClosePoint(x, y, z, DEFAULT_PLAYER_BOUNDING_RADIUS, dist, angle);

            float ground = m_caster->GetMapHeight(x, y, z);
            float liquidLevel = VMAP_INVALID_HEIGHT_VALUE;
            LiquidData liquidData;
            if (m_caster->GetMap()->GetLiquidStatus(m_caster->GetPhaseShift(), x, y, z, map_liquidHeaderTypeFlags::AllLiquids, &liquidData, m_caster->GetCollisionHeight()))
                liquidLevel = liquidData.level;

            if (liquidLevel <= ground) // When there is no liquid Map::GetWaterOrGroundLevel returns ground level
            {
                SendCastResult(SPELL_FAILED_NOT_HERE);
                SendChannelUpdate(0);
                finish(false);
                return;
            }

            if (ground + 0.75 > liquidLevel)
            {
                SendCastResult(SPELL_FAILED_TOO_SHALLOW);
                SendChannelUpdate(0);
                finish(false);
                return;
            }

            dest = SpellDestination(x, y, liquidLevel, m_caster->GetOrientation());
            break;
        }
        case TARGET_DEST_CASTER_FRONT_LEAP:
        {
            Unit* unitCaster = m_caster->ToUnit();
            if (!unitCaster)
                break;

            float dist = m_spellInfo->Effects[effIndex].CalcRadius(unitCaster);
            float angle = targetType.CalcDirectionAngle();

            Position pos = dest._position;
            unitCaster->MovePositionToFirstCollision(pos, dist, angle);
            dest.Relocate(pos);
            break;
        }
        case TARGET_DEST_CASTER_GROUND:
        case TARGET_DEST_CASTER_GROUND_2:
            dest._position.m_positionZ = m_caster->GetMapWaterOrGroundLevel(dest._position.GetPositionX(), dest._position.GetPositionY(), dest._position.GetPositionZ());
            break;
        default:
        {
            float dist = m_spellInfo->Effects[effIndex].CalcRadius(m_caster);
            float angle = targetType.CalcDirectionAngle();
            float objSize = m_caster->GetCombatReach();

            switch (targetType.GetTarget())
            {
                case TARGET_DEST_CASTER_SUMMON:
                    dist = DEFAULT_FOLLOW_DISTANCE;
                    break;
                case TARGET_DEST_CASTER_RANDOM:
                    if (dist > objSize)
                        dist = objSize + (dist - objSize) * float(rand_norm());
                    break;
                case TARGET_DEST_CASTER_FRONT_LEFT:
                case TARGET_DEST_CASTER_BACK_LEFT:
                case TARGET_DEST_CASTER_FRONT_RIGHT:
                case TARGET_DEST_CASTER_BACK_RIGHT:
                {
                    static float const DefaultTotemDistance = 3.0f;
                    if (!m_spellInfo->Effects[effIndex].HasRadius())
                        dist = DefaultTotemDistance;
                    break;
                }
                default:
                    break;
            }

            if (dist < objSize)
                dist = objSize;

            Position pos = dest._position;
            m_caster->MovePositionToFirstCollision(pos, dist, angle);

            dest.Relocate(pos);
            break;
        }
    }

    CallScriptDestinationTargetSelectHandlers(dest, effIndex, targetType);
    m_targets.SetDst(dest);
}

void Spell::SelectImplicitTargetDestTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType)
{
    ASSERT(m_targets.GetObjectTarget() && "Spell::SelectImplicitTargetDestTargets - no explicit object target available!");
    WorldObject* target = m_targets.GetObjectTarget();

    SpellDestination dest(*target);

    switch (targetType.GetTarget())
    {
        case TARGET_DEST_TARGET_ENEMY:
        case TARGET_DEST_TARGET_ANY:
            break;
        default:
        {
            float angle = targetType.CalcDirectionAngle();
            float dist = m_spellInfo->Effects[effIndex].CalcRadius(nullptr);
            if (targetType.GetTarget() == TARGET_DEST_TARGET_RANDOM)
                dist *= float(rand_norm());

            Position pos = dest._position;
            target->MovePositionToFirstCollision(pos, dist, angle);

            dest.Relocate(pos);
            break;
        }
    }

    CallScriptDestinationTargetSelectHandlers(dest, effIndex, targetType);
    m_targets.SetDst(dest);
}

void Spell::SelectImplicitDestDestTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType)
{
    // set destination to caster if no dest provided
    // can only happen if previous destination target could not be set for some reason
    // (not found nearby target, or channel target for example
    // maybe we should abort the spell in such case?
    CheckDst();

    SpellDestination dest(*m_targets.GetDst());

    switch (targetType.GetTarget())
    {
        case TARGET_DEST_DYNOBJ_ENEMY:
        case TARGET_DEST_DYNOBJ_ALLY:
        case TARGET_DEST_DYNOBJ_NONE:
        case TARGET_DEST_DEST:
            break;
        default:
        {
            float angle = targetType.CalcDirectionAngle();
            float dist = m_spellInfo->Effects[effIndex].CalcRadius(m_caster);
            if (targetType.GetTarget() == TARGET_DEST_DEST_RANDOM)
                dist *= float(rand_norm());

            Position pos = dest._position;
            m_caster->MovePositionToFirstCollision(pos, dist, angle);

            dest.Relocate(pos);
            break;
        }
    }

    CallScriptDestinationTargetSelectHandlers(dest, effIndex, targetType);
    m_targets.ModDst(dest);
}

void Spell::SelectImplicitCasterObjectTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType)
{
    WorldObject* target = nullptr;
    bool checkIfValid = true;

    switch (targetType.GetTarget())
    {
        case TARGET_UNIT_CASTER:
            target = m_caster;
            checkIfValid = false;
            break;
        case TARGET_UNIT_MASTER:
            target = m_caster->GetCharmerOrOwner();
            break;
        case TARGET_UNIT_PET:
            if (Unit* unitCaster = m_caster->ToUnit())
                target = unitCaster->GetGuardianPet();
            break;
        case TARGET_UNIT_SUMMONER:
            if (Unit* unitCaster = m_caster->ToUnit())
                if (unitCaster->IsSummon())
                    target = unitCaster->ToTempSummon()->GetSummoner();
            break;
        case TARGET_UNIT_VEHICLE:
            if (Unit* unitCaster = m_caster->ToUnit())
                target = unitCaster->GetVehicleBase();
            break;
        case TARGET_UNIT_PASSENGER_0:
        case TARGET_UNIT_PASSENGER_1:
        case TARGET_UNIT_PASSENGER_2:
        case TARGET_UNIT_PASSENGER_3:
        case TARGET_UNIT_PASSENGER_4:
        case TARGET_UNIT_PASSENGER_5:
        case TARGET_UNIT_PASSENGER_6:
        case TARGET_UNIT_PASSENGER_7:
            if (Creature* vehicleBase = m_caster->ToCreature())
                if (vehicleBase->IsVehicle())
                    target = vehicleBase->GetVehicleKit()->GetPassenger(targetType.GetTarget() - TARGET_UNIT_PASSENGER_0);
            break;
        case TARGET_UNIT_TARGET_TAP_LIST:
            if (Creature* creatureCaster = m_caster->ToCreature())
                target = creatureCaster->GetLootRecipient();
            break;
        default:
            break;
    }

    CallScriptObjectTargetSelectHandlers(target, effIndex, targetType);

    if (target)
    {
        if (Unit* unit = target->ToUnit())
            AddUnitTarget(unit, 1 << effIndex, checkIfValid);
        else if (GameObject* go = target->ToGameObject())
            AddGOTarget(go, 1 << effIndex);
    }
}

void Spell::SelectImplicitTargetObjectTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType)
{
    ASSERT((m_targets.GetObjectTarget() || m_targets.GetItemTarget()) && "Spell::SelectImplicitTargetObjectTargets - no explicit object or item target available!");

    WorldObject* target = m_targets.GetObjectTarget();

    CallScriptObjectTargetSelectHandlers(target, effIndex, targetType);

    if (target)
    {
        if (Unit* unit = target->ToUnit())
            AddUnitTarget(unit, 1 << effIndex, true, false);
        else if (GameObject* gobj = target->ToGameObject())
            AddGOTarget(gobj, 1 << effIndex);
        else if (Corpse* corpse = target->ToCorpse())
            AddCorpseTarget(corpse, 1 << effIndex);

        SelectImplicitChainTargets(effIndex, targetType, target, 1 << effIndex);
    }
    // Script hook can remove object target and we would wrongly land here
    else if (Item* item = m_targets.GetItemTarget())
        AddItemTarget(item, 1 << effIndex);
}

void Spell::SelectImplicitChainTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType, WorldObject* target, uint32 effMask)
{
    uint32 maxTargets = m_spellInfo->Effects[effIndex].ChainTarget;
    if (Player* modOwner = m_caster->GetSpellModOwner())
        modOwner->ApplySpellMod(m_spellInfo->Id, SpellModOp::ChainTargets, maxTargets, this);

    if (maxTargets > 1)
    {
        // mark damage multipliers as used
        for (uint32 k = effIndex; k < MAX_SPELL_EFFECTS; ++k)
            if (effMask & (1 << k))
                m_damageMultipliers[k] = 1.0f;
        m_applyMultiplierMask |= effMask;

        std::list<WorldObject*> targets;
        SearchChainTargets(targets, maxTargets - 1, target, targetType.GetObjectType(), targetType.GetCheckType()
            , m_spellInfo->Effects[effIndex], targetType.GetTarget() == TARGET_UNIT_TARGET_CHAINHEAL_ALLY);

        // Chain primary target is added earlier
        CallScriptObjectAreaTargetSelectHandlers(targets, effIndex, targetType);

        Position const* losPosition = m_spellInfo->HasAttribute(SPELL_ATTR2_CHAIN_FROM_CASTER) ? m_caster : target;

        for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
        {
            if (Unit* unit = (*itr)->ToUnit())
                AddUnitTarget(unit, effMask, false, true, losPosition);

            if (!m_spellInfo->HasAttribute(SPELL_ATTR2_CHAIN_FROM_CASTER))
                losPosition = *itr;
        }

    }
}

float tangent(float x)
{
    x = std::tan(x);
    //if (x < std::numeric_limits<float>::max() && x > -std::numeric_limits<float>::max()) return x;
    //if (x >= std::numeric_limits<float>::max()) return std::numeric_limits<float>::max();
    //if (x <= -std::numeric_limits<float>::max()) return -std::numeric_limits<float>::max();
    if (x < 100000.0f && x > -100000.0f) return x;
    if (x >= 100000.0f) return 100000.0f;
    if (x <= 100000.0f) return -100000.0f;
    return 0.0f;
}

void Spell::SelectImplicitTrajTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType)
{
    if (!m_targets.HasTraj())
        return;

    float dist2d = m_targets.GetDist2d();
    if (!dist2d)
        return;

    Position srcPos = *m_targets.GetSrcPos();
    srcPos.SetOrientation(m_caster->GetOrientation());
    float srcToDestDelta = m_targets.GetDstPos()->m_positionZ - srcPos.m_positionZ;

    std::list<WorldObject*> targets;
    Trinity::WorldObjectSpellTrajTargetCheck check(dist2d, &srcPos, m_caster, m_spellInfo, targetType.GetCheckType(), m_spellInfo->Effects[effIndex].ImplicitTargetConditions);
    Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellTrajTargetCheck> searcher(m_caster, targets, check, GRID_MAP_TYPE_MASK_ALL);
    SearchTargets<Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellTrajTargetCheck> > (searcher, GRID_MAP_TYPE_MASK_ALL, m_caster, &srcPos, dist2d);
    if (targets.empty())
        return;

    targets.sort(Trinity::ObjectDistanceOrderPred(m_caster));

    float b = tangent(m_targets.GetElevation());
    float a = (srcToDestDelta - dist2d * b) / (dist2d * dist2d);
    if (a > -0.0001f)
        a = 0.f;

    // We should check if triggered spell has greater range (which is true in many cases, and initial spell has too short max range)
    // limit max range to 300 yards, sometimes triggered spells can have 50000yds
    float bestDist = m_spellInfo->GetMaxRange(false);
    if (SpellInfo const* triggerSpellInfo = sSpellMgr->GetSpellInfo(m_spellInfo->Effects[effIndex].TriggerSpell))
        bestDist = std::min(std::max(bestDist, triggerSpellInfo->GetMaxRange(false)), std::min(dist2d, 300.0f));

    // GameObjects don't cast traj
    Unit* unitCaster = ASSERT_NOTNULL(m_caster->ToUnit());
    for (auto itr = targets.begin(); itr != targets.end(); ++itr)
    {
        if (m_spellInfo->CheckTarget(unitCaster, *itr, true) != SPELL_CAST_OK)
            continue;

        if (Unit* unit = (*itr)->ToUnit())
        {
            if (unitCaster == *itr || unitCaster->IsOnVehicle(unit) || unit->GetVehicle())
                continue;

            if (Creature* creatureTarget = unit->ToCreature())
            {
                if (!(creatureTarget->GetCreatureTemplate()->type_flags & CREATURE_TYPE_FLAG_CAN_COLLIDE_WITH_MISSILES))
                    continue;
            }
        }

        float const size = std::max((*itr)->GetCombatReach(), 1.0f);
        float const objDist2d = srcPos.GetExactDist2d(*itr);
        float const dz = (*itr)->GetPositionZ() - srcPos.m_positionZ;

        float const horizontalDistToTraj = std::fabs(objDist2d * std::sin(srcPos.GetRelativeAngle(*itr)));
        float const sizeFactor = std::cos((horizontalDistToTraj / size) * (M_PI / 2.0f));
        float const distToHitPoint = std::max(objDist2d * std::cos(srcPos.GetRelativeAngle(*itr)) - size * sizeFactor, 0.0f);
        float const height = distToHitPoint * (a * distToHitPoint + b);

        if (fabs(dz - height) > size + b / 2.0f + TRAJECTORY_MISSILE_SIZE)
            continue;

        if (distToHitPoint < bestDist)
        {
            bestDist = distToHitPoint;
            break;
        }
    }

    if (dist2d > bestDist)
    {
        float x = m_targets.GetSrcPos()->m_positionX + std::cos(unitCaster->GetOrientation()) * bestDist;
        float y = m_targets.GetSrcPos()->m_positionY + std::sin(unitCaster->GetOrientation()) * bestDist;
        float z = m_targets.GetSrcPos()->m_positionZ + bestDist * (a * bestDist + b);

        SpellDestination dest(x, y, z, unitCaster->GetOrientation());
        CallScriptDestinationTargetSelectHandlers(dest, effIndex, targetType);
        m_targets.ModDst(dest);
    }
}

void Spell::SelectEffectTypeImplicitTargets(uint8 effIndex)
{
    // special case for SPELL_EFFECT_SUMMON_RAF_FRIEND and SPELL_EFFECT_SUMMON_PLAYER, queue them on map for later execution
    switch (m_spellInfo->Effects[effIndex].Effect)
    {
        case SPELL_EFFECT_SUMMON_RAF_FRIEND:
        case SPELL_EFFECT_SUMMON_PLAYER:
            if (m_caster->GetTypeId() == TYPEID_PLAYER && m_caster->ToPlayer()->GetTarget())
            {
                WorldObject* target = ObjectAccessor::FindPlayer(m_caster->ToPlayer()->GetTarget());
                CallScriptObjectTargetSelectHandlers(target, SpellEffIndex(effIndex), SpellImplicitTargetInfo());

                // scripts may modify the target - recheck
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                {
                    // target is not stored in target map for those spells
                    // since we're completely skipping AddUnitTarget logic, we need to check immunity manually
                    // eg. aura 21546 makes target immune to summons
                    Player* player = target->ToPlayer();
                    if (player->IsImmunedToSpellEffect(m_spellInfo, effIndex, nullptr))
                        return;

                    target->GetMap()->AddFarSpellCallback(std::bind([](Map* map, Spell* spell, uint8 effIndex, ObjectGuid const& targetGuid)
                    {
                        Player* player = ObjectAccessor::GetPlayer(map, targetGuid);
                        if (!player)
                            return;

                        // check immunity again in case it changed during update
                        if (player->IsImmunedToSpellEffect(spell->GetSpellInfo(), effIndex, nullptr))
                            return;

                        spell->HandleEffects(player, nullptr, nullptr, nullptr, effIndex, SPELL_EFFECT_HANDLE_HIT_TARGET);
                    }, std::placeholders::_1, this, effIndex, target->GetGUID()));
                }
            }
            return;
        default:
            break;
    }

    if (!m_spellInfo->Effects[effIndex].GetImplicitTargetType())
        return;

    uint32 targetMask = m_spellInfo->Effects[effIndex].GetMissingTargetMask();

    if (!targetMask)
        return;

    WorldObject* target = nullptr;

    switch (m_spellInfo->Effects[effIndex].GetImplicitTargetType())
    {
        // add explicit object target or self to the target map
        case EFFECT_IMPLICIT_TARGET_EXPLICIT:
            // player which not released his spirit is Unit, but target flag for it is TARGET_FLAG_CORPSE_MASK
            if (targetMask & (TARGET_FLAG_UNIT_MASK | TARGET_FLAG_CORPSE_MASK))
            {
                if (Unit* unit = m_targets.GetUnitTarget())
                    target = unit;
                else if (targetMask & TARGET_FLAG_CORPSE_MASK)
                {
                    if (Corpse* corpse = m_targets.GetCorpseTarget())
                        target = corpse;
                }
                else //if (targetMask & TARGET_FLAG_UNIT_MASK)
                    target = m_caster;
            }
            if (targetMask & TARGET_FLAG_ITEM_MASK)
            {
                if (Item* item = m_targets.GetItemTarget())
                    AddItemTarget(item, 1 << effIndex);
                return;
            }
            if (targetMask & TARGET_FLAG_GAMEOBJECT_MASK)
                target = m_targets.GetGOTarget();
            break;
        // add self to the target map
        case EFFECT_IMPLICIT_TARGET_CASTER:
            if (targetMask & TARGET_FLAG_UNIT_MASK)
                target = m_caster;
            break;
        default:
            break;
    }

    CallScriptObjectTargetSelectHandlers(target, SpellEffIndex(effIndex), SpellImplicitTargetInfo());

    if (target)
    {
        if (target->ToUnit())
            AddUnitTarget(target->ToUnit(), 1 << effIndex, false);
        else if (target->ToGameObject())
            AddGOTarget(target->ToGameObject(), 1 << effIndex);
        else if (target->ToCorpse())
            AddCorpseTarget(target->ToCorpse(), 1 << effIndex);
    }
}

uint32 Spell::GetSearcherTypeMask(SpellTargetObjectTypes objType, ConditionContainer* condList)
{
    // this function selects which containers need to be searched for spell target
    uint32 retMask = GRID_MAP_TYPE_MASK_ALL;

    // filter searchers based on searched object type
    switch (objType)
    {
        case TARGET_OBJECT_TYPE_UNIT:
        case TARGET_OBJECT_TYPE_UNIT_AND_DEST:
            retMask &= GRID_MAP_TYPE_MASK_PLAYER | GRID_MAP_TYPE_MASK_CREATURE;
            break;
        case TARGET_OBJECT_TYPE_CORPSE:
        case TARGET_OBJECT_TYPE_CORPSE_ENEMY:
        case TARGET_OBJECT_TYPE_CORPSE_ALLY:
            retMask &= GRID_MAP_TYPE_MASK_PLAYER | GRID_MAP_TYPE_MASK_CORPSE | GRID_MAP_TYPE_MASK_CREATURE;
            break;
        case TARGET_OBJECT_TYPE_GOBJ:
        case TARGET_OBJECT_TYPE_GOBJ_ITEM:
            retMask &= GRID_MAP_TYPE_MASK_GAMEOBJECT;
            break;
        default:
            break;
    }

    if (m_spellInfo->HasAttribute(SPELL_ATTR3_ONLY_ON_PLAYER))
        retMask &= GRID_MAP_TYPE_MASK_CORPSE | GRID_MAP_TYPE_MASK_PLAYER;
    if (m_spellInfo->HasAttribute(SPELL_ATTR3_ONLY_ON_GHOSTS))
        retMask &= GRID_MAP_TYPE_MASK_PLAYER;
    if (m_spellInfo->HasAttribute(SPELL_ATTR5_NOT_ON_PLAYER))
        retMask &= ~GRID_MAP_TYPE_MASK_PLAYER;

    if (condList)
        retMask &= sConditionMgr->GetSearcherTypeMaskForConditionList(*condList);
    return retMask;
}

template<class SEARCHER>
void Spell::SearchTargets(SEARCHER& searcher, uint32 containerMask, WorldObject* referer, Position const* pos, float radius)
{
    if (!containerMask)
        return;

    // search world and grid for possible targets
    bool searchInGrid = (containerMask & (GRID_MAP_TYPE_MASK_CREATURE | GRID_MAP_TYPE_MASK_GAMEOBJECT)) != 0;
    bool searchInWorld = (containerMask & (GRID_MAP_TYPE_MASK_CREATURE | GRID_MAP_TYPE_MASK_PLAYER | GRID_MAP_TYPE_MASK_CORPSE)) != 0;
    if (searchInGrid || searchInWorld)
    {
        float x, y;
        x = pos->GetPositionX();
        y = pos->GetPositionY();

        Map* map = referer->GetMap();

        if (searchInWorld)
            Cell::VisitWorldObjects(x, y, map, searcher, radius);

        if (searchInGrid)
            Cell::VisitGridObjects(x, y, map, searcher, radius);
    }
}

WorldObject* Spell::SearchNearbyTarget(float range, SpellTargetObjectTypes objectType, SpellTargetCheckTypes selectionType, ConditionContainer* condList)
{
    WorldObject* target = nullptr;
    uint32 containerTypeMask = GetSearcherTypeMask(objectType, condList);
    if (!containerTypeMask)
        return nullptr;
    Trinity::WorldObjectSpellNearbyTargetCheck check(range, m_caster, m_spellInfo, selectionType, condList);
    Trinity::WorldObjectLastSearcher<Trinity::WorldObjectSpellNearbyTargetCheck> searcher(m_caster, target, check, containerTypeMask);
    SearchTargets<Trinity::WorldObjectLastSearcher<Trinity::WorldObjectSpellNearbyTargetCheck> > (searcher, containerTypeMask, m_caster, m_caster, range);
    return target;
}

void Spell::SearchAreaTargets(std::list<WorldObject*>& targets, float range, Position const* position, WorldObject* referer, SpellTargetObjectTypes objectType, SpellTargetCheckTypes selectionType, ConditionContainer* condList)
{
    uint32 containerTypeMask = GetSearcherTypeMask(objectType, condList);
    if (!containerTypeMask)
        return;
    Trinity::WorldObjectSpellAreaTargetCheck check(range, position, m_caster, referer, m_spellInfo, selectionType, condList);
    Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellAreaTargetCheck> searcher(m_caster, targets, check, containerTypeMask);
    SearchTargets<Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellAreaTargetCheck> > (searcher, containerTypeMask, m_caster, position, range);
}

void Spell::SearchChainTargets(std::list<WorldObject*>& targets, uint32 chainTargets, WorldObject* target, SpellTargetObjectTypes objectType, SpellTargetCheckTypes selectType, SpellEffectInfo const& spellEffectInfo, bool isChainHeal)
{
    // max dist for jump target selection
    float jumpRadius = 0.0f;
    switch (m_spellInfo->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_RANGED:
            // 7.5y for multi shot
            jumpRadius = 7.5f;
            break;
        case SPELL_DAMAGE_CLASS_MELEE:
            // 5y for swipe, cleave and similar
            jumpRadius = 5.0f;
            break;
        case SPELL_DAMAGE_CLASS_NONE:
        case SPELL_DAMAGE_CLASS_MAGIC:
            // 12.5y for chain heal spell since 3.2 patch
            if (isChainHeal)
                jumpRadius = 12.5f;
            // 10y as default for magic chain spells
            else
                jumpRadius = 10.0f;
            break;
    }

    // max dist which spell can reach
    float searchRadius = [&]()
    {
        if (m_spellInfo->HasAttribute(SPELL_ATTR2_CHAIN_FROM_CASTER))
            return GetMinMaxRange(false).second;

        return jumpRadius * chainTargets;
    }();

    WorldObject* chainSource = m_spellInfo->HasAttribute(SPELL_ATTR2_CHAIN_FROM_CASTER) ? m_caster : target;
    std::list<WorldObject*> tempTargets;
    SearchAreaTargets(tempTargets, searchRadius, chainSource, m_caster, objectType, selectType, spellEffectInfo.ImplicitTargetConditions);
    tempTargets.remove(target);

    // remove targets which are always invalid for chain spells
    // for some spells allow only chain targets in front of caster (swipe for example)
    if (m_spellInfo->HasAttribute(SPELL_ATTR5_MELEE_CHAIN_TARGETING))
    {
        tempTargets.remove_if([&](WorldObject* object)
        {
            return !m_caster->HasInArc(static_cast<float>(M_PI), object);
        });
    }

    while (chainTargets)
    {
        // try to get unit for next chain jump
        std::list<WorldObject*>::iterator foundItr = tempTargets.end();
        // get unit with highest hp deficit in dist
        if (isChainHeal)
        {
            uint32 maxHPDeficit = 0;
            for (std::list<WorldObject*>::iterator itr = tempTargets.begin(); itr != tempTargets.end(); ++itr)
            {
                if (Unit* unit = (*itr)->ToUnit())
                {
                    uint32 deficit = unit->GetMaxHealth() - unit->GetHealth();
                    if ((deficit > maxHPDeficit || foundItr == tempTargets.end()) && chainSource->IsWithinDist(unit, jumpRadius) && chainSource->IsWithinLOSInMap(unit, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
                    {
                        foundItr = itr;
                        maxHPDeficit = deficit;
                    }
                }
            }
        }
        // get closest object
        else
        {
            for (std::list<WorldObject*>::iterator itr = tempTargets.begin(); itr != tempTargets.end(); ++itr)
            {
                if (foundItr == tempTargets.end())
                {
                    if (chainSource->IsWithinDist(*itr, jumpRadius) && chainSource->IsWithinLOSInMap(*itr, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
                        foundItr = itr;
                }
                else if (chainSource->GetDistanceOrder(*itr, *foundItr) && chainSource->IsWithinLOSInMap(*itr, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
                    foundItr = itr;
            }
        }
        // not found any valid target - chain ends
        if (foundItr == tempTargets.end())
            break;

        if (!m_spellInfo->HasAttribute(SPELL_ATTR2_CHAIN_FROM_CASTER))
            chainSource = *foundItr;

        targets.push_back(*foundItr);
        tempTargets.erase(foundItr);
        --chainTargets;
    }
}

GameObject* Spell::SearchSpellFocus()
{
    GameObject* focus = nullptr;
    Trinity::GameObjectFocusCheck check(m_caster, m_spellInfo->RequiresSpellFocus);
    Trinity::GameObjectSearcher<Trinity::GameObjectFocusCheck> searcher(m_caster, focus, check);
    SearchTargets(searcher, GRID_MAP_TYPE_MASK_GAMEOBJECT, m_caster, m_caster, m_caster->GetVisibilityRange());
    return focus;
}

void Spell::prepareDataForTriggerSystem()
{
    //==========================================================================================
    // Now fill data for trigger system, need know:
    // Create base triggers flags for Attacker and Victim (m_procAttacker, m_procVictim and m_hitMask)
    //==========================================================================================

    m_procVictim = m_procAttacker = PROC_FLAG_NONE;
    // Get data for type of attack and fill base info for trigger
    switch (m_spellInfo->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_MELEE:
            m_procAttacker = PROC_FLAG_DEAL_MELEE_ABILITY;
            if (m_attackType == OFF_ATTACK)
                m_procAttacker |= PROC_FLAG_OFF_HAND_WEAPON_SWING;
            else
                m_procAttacker |= PROC_FLAG_MAIN_HAND_WEAPON_SWING;
            m_procVictim   = PROC_FLAG_TAKE_MELEE_ABILITY;
            break;
        case SPELL_DAMAGE_CLASS_RANGED:
            // Auto attack
            if (m_spellInfo->HasAttribute(SPELL_ATTR2_AUTO_REPEAT))
            {
                m_procAttacker = PROC_FLAG_DEAL_RANGED_ATTACK;
                m_procVictim   = PROC_FLAG_TAKE_RANGED_ATTACK;
            }
            else // Ranged spell attack
            {
                m_procAttacker = PROC_FLAG_DEAL_RANGED_ABILITY;
                m_procVictim   = PROC_FLAG_TAKE_RANGED_ABILITY;
            }
            break;
        default:
            if (m_spellInfo->EquippedItemClass == ITEM_CLASS_WEAPON &&
                m_spellInfo->EquippedItemSubClassMask & (1 << ITEM_SUBCLASS_WEAPON_WAND)
                && m_spellInfo->HasAttribute(SPELL_ATTR2_AUTO_REPEAT)) // Wands auto attack
            {
                m_procAttacker = PROC_FLAG_DEAL_RANGED_ATTACK;
                m_procVictim   = PROC_FLAG_TAKE_RANGED_ATTACK;
            }
            // For other spells trigger procflags are set in Spell::TargetInfo::DoDamageAndTriggers
            // Because spell positivity is dependant on target
    }

    // Hunter trap spells - activation proc for Lock and Load, Entrapment and Misdirection
    if (m_spellInfo->SpellFamilyName == SPELLFAMILY_HUNTER &&
        (m_spellInfo->SpellFamilyFlags[0] & 0x18 ||         // Freezing and Frost Trap, Freezing Arrow
        m_spellInfo->Id == 57879 ||                     // Snake Trap - done this way to avoid double proc
        m_spellInfo->SpellFamilyFlags[2] & 0x00024000)) // Explosive and Immolation Trap
    {
        m_procAttacker |= PROC_FLAG_TRAP_ACTIVATION;

        // also fill up other flags (TargetInfo::DoDamageAndTriggers only fills up flag if both are not set)
        m_procAttacker |= PROC_FLAG_DEAL_HARMFUL_SPELL;
        m_procVictim |= PROC_FLAG_TAKE_HARMFUL_SPELL;
    }
}

void Spell::CleanupTargetList()
{
    m_UniqueTargetInfo.clear();
    m_UniqueGOTargetInfo.clear();
    m_UniqueItemInfo.clear();
    m_UniqueCorpseTargetInfo.clear();
    m_delayMoment = 0;
}

class ProcReflectDelayed : public BasicEvent
{
    public:
        ProcReflectDelayed(Unit* owner, ObjectGuid casterGuid) : _victim(owner), _casterGuid(casterGuid) { }

        bool Execute(uint64 /*e_time*/, uint32 /*p_time*/) override
        {
            Unit* caster = ObjectAccessor::GetUnit(*_victim, _casterGuid);
            if (!caster)
                return true;

            uint32 const typeMaskActor = PROC_FLAG_NONE;
            uint32 const typeMaskActionTarget = PROC_FLAG_TAKE_HARMFUL_SPELL | PROC_FLAG_TAKE_HARMFUL_ABILITY;
            uint32 const spellTypeMask = PROC_SPELL_TYPE_DAMAGE | PROC_SPELL_TYPE_NO_DMG_HEAL;
            uint32 const spellPhaseMask = PROC_SPELL_PHASE_NONE;
            uint32 const hitMask = PROC_HIT_REFLECT;

            Unit::ProcSkillsAndAuras(caster, _victim, typeMaskActor, typeMaskActionTarget, spellTypeMask, spellPhaseMask, hitMask, nullptr, nullptr, nullptr);
            return true;
        }

    private:
        Unit* _victim;
        ObjectGuid _casterGuid;
};

void Spell::AddUnitTarget(Unit* target, uint32 effectMask, bool checkIfValid /*= true*/, bool implicit /*= true*/, Position const* losPosition /*= nullptr*/)
{
    for (uint32 effIndex = 0; effIndex < MAX_SPELL_EFFECTS; ++effIndex)
        if (!m_spellInfo->Effects[effIndex].IsEffect() || !CheckEffectTarget(target, effIndex, losPosition))
            effectMask &= ~(1 << effIndex);

    // no effects left
    if (!effectMask)
        return;

    if (checkIfValid)
        if (m_spellInfo->CheckTarget(m_caster, target, implicit) != SPELL_CAST_OK) // skip stealth checks for AOE
            return;

    // Check for effect immune skip if immuned
    for (uint32 effIndex = 0; effIndex < MAX_SPELL_EFFECTS; ++effIndex)
        if (target->IsImmunedToSpellEffect(m_spellInfo, effIndex, m_caster))
            effectMask &= ~(1 << effIndex);

    ObjectGuid targetGUID = target->GetGUID();

    // Lookup target in already in list
    auto ihit = std::find_if(std::begin(m_UniqueTargetInfo), std::end(m_UniqueTargetInfo), [targetGUID](TargetInfo const& target) { return target.TargetGUID == targetGUID; });
    if (ihit != std::end(m_UniqueTargetInfo)) // Found in list
    {
        // Immune effects removed from mask
        ihit->EffectMask |= effectMask;
        ihit->ScaleAura = false;
        if (m_auraScaleMask && ihit->EffectMask == m_auraScaleMask && m_caster != target)
        {
            SpellInfo const* auraSpell = m_spellInfo->GetFirstRankSpell();
            if (uint32(target->getLevel() + 10) >= auraSpell->SpellLevel)
                ihit->ScaleAura = true;
        }
        return;
    }

    // This is new target calculate data for him

    // Get spell hit result on target
    TargetInfo targetInfo;
    targetInfo.TargetGUID = targetGUID;                         // Store target GUID
    targetInfo.EffectMask = effectMask;                         // Store all effects not immune
    targetInfo.IsAlive = target->IsAlive();
    targetInfo.Damage = 0;
    targetInfo.Healing = 0;
    targetInfo.IsCrit = false;
    targetInfo.ScaleAura = false;
    if (m_auraScaleMask && targetInfo.EffectMask == m_auraScaleMask && m_caster != target)
    {
        SpellInfo const* auraSpell = m_spellInfo->GetFirstRankSpell();
        if (uint32(target->getLevel() + 10) >= auraSpell->SpellLevel)
            targetInfo.ScaleAura = true;
    }

    // Calculate hit result
    WorldObject* caster = m_originalCaster ? m_originalCaster : m_caster;
    targetInfo.MissCondition = caster->SpellHitResult(target, m_spellInfo, m_canReflect && !(IsPositive() && m_caster->IsFriendlyTo(target)));

    // Spell have speed - need calculate incoming time
    // Incoming time is zero for self casts. At least I think so.
    if (m_caster != target)
    {
        float hitDelay = 0.f;
        WorldObject const* missileSource = m_caster;
        if (m_spellInfo->HasAttribute(SPELL_ATTR4_BOUNCY_CHAIN_MISSILES))
        {
            auto previousTargetItr = std::find_if(m_UniqueTargetInfo.rbegin(), m_UniqueTargetInfo.rend(), [effectMask](TargetInfo const& target)
            {
                return (target.EffectMask & effectMask) != 0;
            });
            if (previousTargetItr != std::rend(m_UniqueTargetInfo))
            {
                hitDelay = 0.0f; // this is not the first target in chain, LaunchDelay was already included

                if (WorldObject* previousTarget = ObjectAccessor::GetWorldObject(*m_caster, previousTargetItr->TargetGUID))
                    missileSource = previousTarget;

                targetInfo.TimeDelay += previousTargetItr->TimeDelay;
            }
        }

        if (m_spellInfo->HasAttribute(SPELL_ATTR9_SPECIAL_DELAY_CALCULATION))
            hitDelay += m_spellInfo->Speed;
        else if (m_spellInfo->Speed > 0.0f)
        {
            // calculate spell incoming interval
            /// @todo this is a hack
            float dist = std::max(missileSource->GetDistance(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ()), 5.0f);
            hitDelay += dist / m_spellInfo->Speed;
        }

        targetInfo.TimeDelay += uint64(std::floor(hitDelay * 1000.0f));
    }
    else
        targetInfo.TimeDelay = 0ULL;

    // If target reflect spell back to caster
    if (targetInfo.MissCondition == SPELL_MISS_REFLECT)
    {
        // Calculate reflected spell result on caster (shouldn't be able to reflect gameobject spells)
        Unit* unitCaster = ASSERT_NOTNULL(m_caster->ToUnit());
        targetInfo.ReflectResult = unitCaster->SpellHitResult(unitCaster, m_spellInfo, false); // can't reflect twice

        // Proc spell reflect aura when missile hits the original target
        target->m_Events.AddEvent(new ProcReflectDelayed(target, m_originalCasterGUID), target->m_Events.CalculateTime(targetInfo.TimeDelay));

        // Increase time interval for reflected spells by 1.5
        targetInfo.TimeDelay += targetInfo.TimeDelay >> 1;
    }
    else
        targetInfo.ReflectResult = SPELL_MISS_NONE;

    // Calculate minimum incoming time
    if (targetInfo.TimeDelay && (!m_delayMoment || m_delayMoment > targetInfo.TimeDelay))
        m_delayMoment = targetInfo.TimeDelay;

    // Add target to list
    m_UniqueTargetInfo.emplace_back(std::move(targetInfo));
}

void Spell::AddGOTarget(GameObject* go, uint32 effectMask)
{
    for (uint32 effIndex = 0; effIndex < MAX_SPELL_EFFECTS; ++effIndex)
    {
        if (!m_spellInfo->Effects[effIndex].IsEffect())
            effectMask &= ~(1 << effIndex);
        else
        {
            switch (m_spellInfo->Effects[effIndex].Effect)
            {
                case SPELL_EFFECT_GAMEOBJECT_DAMAGE:
                case SPELL_EFFECT_GAMEOBJECT_REPAIR:
                case SPELL_EFFECT_GAMEOBJECT_SET_DESTRUCTION_STATE:
                    if (go->GetGoType() != GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING)
                        effectMask &= ~(1 << effIndex);
                    break;
                default:
                    break;
            }
        }
    }

    if (!effectMask)
        return;

    ObjectGuid targetGUID = go->GetGUID();

    // Lookup target in already in list
    auto ihit = std::find_if(std::begin(m_UniqueGOTargetInfo), std::end(m_UniqueGOTargetInfo), [targetGUID](GOTargetInfo const& target) { return target.TargetGUID == targetGUID; });
    if (ihit != std::end(m_UniqueGOTargetInfo)) // Found in list
    {
        // Add only effect mask
        ihit->EffectMask |= effectMask;
        return;
    }

    // This is new target calculate data for him

    GOTargetInfo target;
    target.TargetGUID = targetGUID;
    target.EffectMask = effectMask;

    // Spell have speed - need calculate incoming time
    if (m_spellInfo->Speed > 0.0f)
    {
        // calculate spell incoming interval
        float dist = m_caster->GetDistance(go->GetPositionX(), go->GetPositionY(), go->GetPositionZ());
        if (dist < 5.0f)
            dist = 5.0f;

        if (!m_spellInfo->HasAttribute(SPELL_ATTR9_SPECIAL_DELAY_CALCULATION))
            target.TimeDelay = uint64(floor(dist / m_spellInfo->Speed * 1000.0f));
        else
            target.TimeDelay = uint64(float(m_spellInfo->Speed * 1000.0f));

        if (!m_delayMoment || m_delayMoment > target.TimeDelay)
            m_delayMoment = target.TimeDelay;
    }
    else
        target.TimeDelay = 0LL;

    // Add target to list
    m_UniqueGOTargetInfo.emplace_back(std::move(target));
}

void Spell::AddItemTarget(Item* item, uint32 effectMask)
{
    for (uint32 effIndex = 0; effIndex < MAX_SPELL_EFFECTS; ++effIndex)
        if (!m_spellInfo->Effects[effIndex].IsEffect())
            effectMask &= ~(1 << effIndex);

    // no effects left
    if (!effectMask)
        return;

    // Lookup target in already in list
    auto ihit = std::find_if(std::begin(m_UniqueItemInfo), std::end(m_UniqueItemInfo), [item](ItemTargetInfo const& target) { return target.TargetItem == item; });
    if (ihit != std::end(m_UniqueItemInfo)) // Found in list
    {
        // Add only effect mask
        ihit->EffectMask |= effectMask;
        return;
    }

    // This is new target add data

    ItemTargetInfo target;
    target.TargetItem = item;
    target.EffectMask = effectMask;

    m_UniqueItemInfo.emplace_back(std::move(target));
}

void Spell::AddCorpseTarget(Corpse* corpse, uint32 effectMask)
{
    for (uint32 effIndex = 0; effIndex < MAX_SPELL_EFFECTS; ++effIndex)
        if (!m_spellInfo->Effects[effIndex].IsEffect())
            effectMask &= ~(1 << effIndex);

    if (!effectMask)
        return;

    ObjectGuid targetGUID = corpse->GetGUID();

    // Lookup target in already in list
    auto ihit = std::find_if(std::begin(m_UniqueCorpseTargetInfo), std::end(m_UniqueCorpseTargetInfo), [targetGUID](CorpseTargetInfo const& target) { return target.TargetGUID == targetGUID; });
    if (ihit != std::end(m_UniqueCorpseTargetInfo)) // Found in list
    {
        // Add only effect mask
        ihit->EffectMask |= effectMask;
        return;
    }

    // This is new target calculate data for him

    CorpseTargetInfo target;
    target.TargetGUID = targetGUID;
    target.EffectMask = effectMask;

    // Spell have speed - need calculate incoming time
    if (m_spellInfo->Speed > 0.0f)
    {
        // calculate spell incoming interval
        float dist = m_caster->GetDistance(corpse->GetPositionX(), corpse->GetPositionY(), corpse->GetPositionZ());
        if (dist < 5.0f)
            dist = 5.0f;

        if (!m_spellInfo->HasAttribute(SPELL_ATTR9_SPECIAL_DELAY_CALCULATION))
            target.TimeDelay = uint64(floor(dist / m_spellInfo->Speed * 1000.0f));
        else
            target.TimeDelay = uint64(float(m_spellInfo->Speed * 1000.0f));

        if (!m_delayMoment || m_delayMoment > target.TimeDelay)
            m_delayMoment = target.TimeDelay;
    }
    else
        target.TimeDelay = 0LL;

    // Add target to list
    m_UniqueCorpseTargetInfo.emplace_back(std::move(target));
}

void Spell::AddDestTarget(SpellDestination const& dest, uint32 effIndex)
{
    m_destTargets[effIndex] = dest;
}

void Spell::TargetInfo::PreprocessTarget(Spell* spell)
{
    Unit* unit = spell->m_caster->GetGUID() == TargetGUID ? spell->m_caster->ToUnit() : ObjectAccessor::GetUnit(*spell->m_caster, TargetGUID);
    if (!unit)
        return;

    // Need init unitTarget by default unit (can changed in code on reflect)
    spell->unitTarget = unit;

    // Reset damage/healing counter
    spell->m_damage = Damage;
    spell->m_healing = Healing;

    _spellHitTarget = nullptr;

    if (MissCondition == SPELL_MISS_NONE || (MissCondition == SPELL_MISS_BLOCK && !spell->GetSpellInfo()->HasAttribute(SPELL_ATTR3_COMPLETELY_BLOCKED)))
        _spellHitTarget = unit;
    else if (MissCondition == SPELL_MISS_REFLECT && ReflectResult == SPELL_MISS_NONE)
        _spellHitTarget = spell->m_caster->ToUnit();

    if (spell->m_originalCaster && MissCondition != SPELL_MISS_EVADE && !spell->m_originalCaster->IsFriendlyTo(unit) && (!spell->m_spellInfo->IsPositive() || spell->m_spellInfo->HasEffect(SPELL_EFFECT_DISPEL)) && (spell->m_spellInfo->CausesInitialThreat() || unit->IsEngaged()))
        unit->SetInCombatWith(spell->m_originalCaster);

    // if target is flagged for pvp also flag caster if a player
    // but respect current pvp rules (buffing/healing npcs flagged for pvp only flags you if they are in combat)
    _enablePVP = (MissCondition == SPELL_MISS_NONE || spell->m_spellInfo->HasAttribute(SPELL_ATTR3_PVP_ENABLING))
        && unit->IsPvP() && (unit->IsInCombat() || unit->IsCharmedOwnedByPlayerOrPlayer()) && spell->m_caster->GetTypeId() == TYPEID_PLAYER; // need to check PvP state before spell effects, but act on it afterwards

    if (_spellHitTarget)
    {
        SpellMissInfo missInfo = spell->PreprocessSpellHit(_spellHitTarget, ScaleAura, *this);
        if (missInfo != SPELL_MISS_NONE)
        {
            if (missInfo != SPELL_MISS_MISS)
                spell->m_caster->SendSpellMiss(unit, spell->m_spellInfo->Id, missInfo);
            spell->m_damage = 0;
            spell->m_healing = 0;
            _spellHitTarget = nullptr;
        }
    }

    spell->CallScriptOnHitHandlers();

    // scripts can modify damage/healing for current target, save them
    Damage = spell->m_damage;
    Healing = spell->m_healing;
}

void Spell::TargetInfo::DoTargetSpellHit(Spell* spell, uint8 effIndex)
{
    Unit* unit = spell->m_caster->GetGUID() == TargetGUID ? spell->m_caster->ToUnit() : ObjectAccessor::GetUnit(*spell->m_caster, TargetGUID);
    if (!unit)
        return;

    // Need init unitTarget by default unit (can changed in code on reflect)
    // Or on missInfo != SPELL_MISS_NONE unitTarget undefined (but need in trigger subsystem)
    spell->unitTarget = unit;
    spell->targetMissInfo = MissCondition;

    // Reset damage/healing counter
    spell->m_damage = Damage;
    spell->m_healing = Healing;

    if (unit->IsAlive() != IsAlive)
        return;

    if (spell->getState() == SPELL_STATE_DELAYED && !spell->IsPositive() && (GameTime::GetGameTimeMS() - TimeDelay) <= unit->m_lastSanctuaryTime)
        return;                                             // No missinfo in that case

    if (_spellHitTarget)
        spell->DoSpellEffectHit(_spellHitTarget, effIndex, *this);

    // scripts can modify damage/healing for current target, save them
    Damage = spell->m_damage;
    Healing = spell->m_healing;
}

void Spell::TargetInfo::DoDamageAndTriggers(Spell* spell)
{
    Unit* unit = spell->m_caster->GetGUID() == TargetGUID ? spell->m_caster->ToUnit() : ObjectAccessor::GetUnit(*spell->m_caster, TargetGUID);
    if (!unit)
        return;

    // other targets executed before this one changed pointer
    spell->unitTarget = unit;
    if (_spellHitTarget)
        spell->unitTarget = _spellHitTarget;

    // Reset damage/healing counter
    spell->m_damage = Damage;
    spell->m_healing = Healing;

    // Get original caster (if exist) and calculate damage/healing from him data
    // Skip if m_originalCaster not available
    Unit* caster = spell->m_originalCaster ? spell->m_originalCaster : spell->m_caster->ToUnit();
    if (caster)
    {
        // Fill base trigger info
        uint32 procAttacker = spell->m_procAttacker;
        uint32 procVictim = spell->m_procVictim;
        uint32 procSpellType = PROC_SPELL_TYPE_NONE;
        uint32 hitMask = PROC_HIT_NONE;

        // Spells with this flag cannot trigger if effect is cast on self
        bool const canEffectTrigger = (!spell->m_spellInfo->HasAttribute(SPELL_ATTR3_SUPPRESS_CASTER_PROCS) || !spell->m_spellInfo->HasAttribute(SPELL_ATTR3_SUPPRESS_TARGET_PROCS))
            && spell->unitTarget->CanProc();

        // Trigger info was not filled in Spell::prepareDataForTriggerSystem - we do it now
        if (canEffectTrigger && !procAttacker && !procVictim)
        {
            bool positive = true;
            if (spell->m_damage > 0)
                positive = false;
            else if (!spell->m_healing)
            {
                for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                {
                    // in case of immunity, check all effects to choose correct procFlags, as none has technically hit
                    if (EffectMask && !(EffectMask & (1 << i)))
                        continue;

                    if (!spell->m_spellInfo->IsPositiveEffect(i))
                    {
                        positive = false;
                        break;
                    }
                }
            }

            switch (spell->m_spellInfo->DmgClass)
            {
                case SPELL_DAMAGE_CLASS_NONE:
                case SPELL_DAMAGE_CLASS_MAGIC:
                    if (spell->m_spellInfo->HasAttribute(SPELL_ATTR3_TREAT_AS_PERIODIC))
                    {
                        procAttacker |= PROC_FLAG_DEAL_PERIODIC;
                        procVictim |= PROC_FLAG_TAKE_PERIODIC;
                    }
                    else if (spell->m_spellInfo->HasAttribute(SPELL_ATTR0_IS_ABILITY))
                    {
                        if (positive)
                        {
                            procAttacker |= PROC_FLAG_DEAL_HELPFUL_ABILITY;
                            procVictim |= PROC_FLAG_TAKE_HELPFUL_ABILITY;
                        }
                        else
                        {
                            procAttacker |= PROC_FLAG_DEAL_HARMFUL_ABILITY;
                            procVictim |= PROC_FLAG_TAKE_HARMFUL_ABILITY;
                        }
                    }
                    else
                    {
                        if (positive)
                        {
                            procAttacker |= PROC_FLAG_DEAL_HELPFUL_SPELL;
                            procVictim |= PROC_FLAG_TAKE_HELPFUL_SPELL;
                        }
                        else
                        {
                            procAttacker |= PROC_FLAG_DEAL_HARMFUL_SPELL;
                            procVictim |= PROC_FLAG_TAKE_HARMFUL_SPELL;
                        }
                    }
                    break;
            }
        }

        // All calculated do it!
        // Do healing
        bool hasHealing = false;
        std::unique_ptr<DamageInfo> spellDamageInfo;
        std::unique_ptr<HealInfo> healInfo;
        if (spell->m_healing > 0)
        {
            hasHealing = true;
            uint32 addhealth = spell->m_healing;
            if (IsCrit)
            {
                hitMask |= PROC_HIT_CRITICAL;
                addhealth = Unit::SpellCriticalHealingBonus(caster, addhealth);
            }
            else
                hitMask |= PROC_HIT_NORMAL;

            healInfo = std::make_unique<HealInfo>(caster, spell->unitTarget, addhealth, spell->m_spellInfo, spell->m_spellInfo->GetSchoolMask());
            caster->HealBySpell(*healInfo, IsCrit);
            spell->unitTarget->GetThreatManager().ForwardThreatForAssistingMe(caster, float(healInfo->GetEffectiveHeal()) * 0.5f, spell->m_spellInfo);
            spell->m_healing = healInfo->GetEffectiveHeal();

            procSpellType |= PROC_SPELL_TYPE_HEAL;
        }

        // Do damage
        bool hasDamage = false;
        if (spell->m_damage > 0)
        {
            hasDamage = true;
            // Fill base damage struct (unitTarget - is real spell target)
            SpellNonMeleeDamage damageInfo(caster, spell->unitTarget, spell->m_spellInfo->Id, spell->m_spellSchoolMask);
            // Check damage immunity
            if (spell->unitTarget->IsImmunedToDamage(spell->m_spellInfo))
            {
                hitMask = PROC_HIT_IMMUNE;
                spell->m_damage = 0;

                // no packet found in sniffs
            }
            else
            {
                caster->CalculateSpellDamageTaken(&damageInfo, spell->m_damage, spell->m_spellInfo, spell->m_attackType, IsCrit, MissCondition == SPELL_MISS_BLOCK);
                Unit::DealDamageMods(damageInfo.target, damageInfo.damage, &damageInfo.absorb);

                if (Creature* target = damageInfo.target->ToCreature())
                    if (caster->IsCreature() && !caster->IsCharmedOwnedByPlayerOrPlayer())
                        if (target->GetNoNpcDamageBelowPctHealthValue() != 0.0f)
                            if (target->GetHealthPct() <= target->GetNoNpcDamageBelowPctHealthValue())
                                damageInfo.damage = 0;            // Send log damage message to client

                caster->SendSpellNonMeleeDamageLog(&damageInfo);

                hitMask |= createProcHitMask(&damageInfo, MissCondition);
                procVictim |= PROC_FLAG_TAKE_ANY_DAMAGE;

                spell->m_damage = damageInfo.damage;
                caster->DealSpellDamage(&damageInfo, true);
            }

            // Do triggers for unit
            if (canEffectTrigger)
            {
                spellDamageInfo = std::make_unique<DamageInfo>(damageInfo, SPELL_DIRECT_DAMAGE, spell->m_attackType, hitMask);
                procSpellType |= PROC_SPELL_TYPE_DAMAGE;
            }
        }

        // Passive spell hits/misses or active spells only misses (only triggers)
        if (!hasHealing && !hasDamage)
        {
            // Fill base damage struct (unitTarget - is real spell target)
            SpellNonMeleeDamage damageInfo(caster, spell->unitTarget, spell->m_spellInfo->Id, spell->m_spellSchoolMask);
            hitMask |= createProcHitMask(&damageInfo, MissCondition);
            // Do triggers for unit
            if (canEffectTrigger)
            {
                spellDamageInfo = std::make_unique<DamageInfo>(damageInfo, NODAMAGE, spell->m_attackType, hitMask);
                procSpellType |= PROC_SPELL_TYPE_NO_DMG_HEAL;
            }

            // Failed Pickpocket, reveal rogue
            if (MissCondition == SPELL_MISS_RESIST && spell->m_spellInfo->HasAttribute(SPELL_ATTR1_FAILURE_BREAKS_STEALTH) && spell->unitTarget->GetTypeId() == TYPEID_UNIT)
            {
                Unit* unitCaster = ASSERT_NOTNULL(spell->m_caster->ToUnit());
                unitCaster->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Interacting);
                spell->unitTarget->ToCreature()->EngageWithTarget(unitCaster);
            }
        }

        // Do triggers for unit
        if (canEffectTrigger)
        {
            if (spell->m_spellInfo->HasAttribute(SPELL_ATTR3_SUPPRESS_CASTER_PROCS))
                procAttacker = PROC_FLAG_NONE;

            if (spell->m_spellInfo->HasAttribute(SPELL_ATTR3_SUPPRESS_TARGET_PROCS))
                procVictim = PROC_FLAG_NONE;

            Unit::ProcSkillsAndAuras(caster, spell->unitTarget, procAttacker, procVictim, procSpellType, PROC_SPELL_PHASE_HIT, hitMask, spell, spellDamageInfo.get(), healInfo.get());

            // item spells (spell hit of non-damage spell may also activate items, for example seal of corruption hidden hit)
            if (caster->GetTypeId() == TYPEID_PLAYER && (procSpellType & (PROC_SPELL_TYPE_DAMAGE | PROC_SPELL_TYPE_NO_DMG_HEAL)))
            {
                if (spell->m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MELEE || spell->m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_RANGED)
                    if (!spell->m_spellInfo->HasAttribute(SPELL_ATTR0_CANCELS_AUTO_ATTACK_COMBAT) && !spell->m_spellInfo->HasAttribute(SPELL_ATTR4_SUPPRESS_WEAPON_PROCS))
                        caster->ToPlayer()->CastItemCombatSpell(*spellDamageInfo);
            }
        }

        // set hitmask for finish procs
        spell->m_hitMask |= hitMask;

        // Do not take combo points on dodge and miss
        if (MissCondition != SPELL_MISS_NONE && spell->m_needComboPoints && spell->m_targets.GetUnitTargetGUID() == TargetGUID)
            spell->m_needComboPoints = false;

        // _spellHitTarget can be null if spell is missed in DoSpellHitOnUnit
        if (MissCondition != SPELL_MISS_EVADE && _spellHitTarget && !spell->m_caster->IsFriendlyTo(unit) && (!spell->IsPositive() || spell->m_spellInfo->HasEffect(SPELL_EFFECT_DISPEL)))
        {
            if (Unit* unitCaster = spell->m_caster->ToUnit())
            {
                if (!unitCaster->IsCreature() || !unitCaster->ToCreature()->IsTrigger())
                {
                    unitCaster->AtTargetAttacked(unit, spell->m_spellInfo->CausesInitialThreat() && !unitCaster->IsIgnoringCombat());

                    if (spell->m_spellInfo->HasAttribute(SPELL_ATTR6_TAPS_IMMEDIATELY))
                        if (Creature* targetCreature = unit->ToCreature())
                            if (!targetCreature->hasLootRecipient() && unitCaster->IsPlayer())
                                targetCreature->SetLootRecipient(unitCaster);
                }
            }

            if (!spell->m_spellInfo->HasAttribute(SPELL_ATTR3_DO_NOT_TRIGGER_TARGET_STAND) && !unit->IsStandState())
                unit->SetStandState(UNIT_STAND_STATE_STAND);
        }

        // Check for SPELL_ATTR7_INTERRUPT_ONLY_NONPLAYER
        if (MissCondition == SPELL_MISS_NONE && spell->m_spellInfo->HasAttribute(SPELL_ATTR7_INTERRUPT_ONLY_NONPLAYER) && unit->GetTypeId() != TYPEID_PLAYER)
            caster->CastSpell(unit, SPELL_INTERRUPT_NONPLAYER, true);
    }

    if (_spellHitTarget)
    {
        //AI functions
        if (_spellHitTarget->GetTypeId() == TYPEID_UNIT)
            if (_spellHitTarget->ToCreature()->IsAIEnabled())
                _spellHitTarget->ToCreature()->AI()->SpellHit(spell->m_caster, spell->m_spellInfo);

        if (spell->m_caster->GetTypeId() == TYPEID_UNIT && spell->m_caster->ToCreature()->IsAIEnabled())
            spell->m_caster->ToCreature()->AI()->SpellHitTarget(_spellHitTarget, spell->m_spellInfo);
        else if (spell->m_caster->GetTypeId() == TYPEID_GAMEOBJECT && spell->m_caster->ToGameObject()->AI())
            spell->m_caster->ToGameObject()->AI()->SpellHitTarget(_spellHitTarget, spell->m_spellInfo);

        if (HitAura)
        {
            if (AuraApplication* aurApp = HitAura->GetApplicationOfTarget(_spellHitTarget->GetGUID()))
            {
                // only apply unapplied effects (for reapply case)
                uint8 effMask = EffectMask & aurApp->GetEffectsToApply();
                for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                    if ((effMask & (1 << i)) && aurApp->HasEffect(i))
                        effMask &= ~(1 << i);

                if (effMask)
                    _spellHitTarget->_ApplyAura(aurApp, effMask);
            }
        }

        // Needs to be called after dealing damage/healing to not remove breaking on damage auras
        spell->DoTriggersOnSpellHit(_spellHitTarget);
    }

    if (_enablePVP)
        spell->m_caster->ToPlayer()->UpdatePvP(true);

    spell->_spellAura = HitAura;
    spell->CallScriptAfterHitHandlers();
    spell->_spellAura = nullptr;
}

void Spell::GOTargetInfo::DoTargetSpellHit(Spell* spell, uint8 effIndex)
{
    GameObject* go = spell->m_caster->GetGUID() == TargetGUID ? spell->m_caster->ToGameObject() : ObjectAccessor::GetGameObject(*spell->m_caster, TargetGUID);
    if (!go)
        return;

    spell->CallScriptBeforeHitHandlers();

    spell->HandleEffects(nullptr, nullptr, go, nullptr, effIndex, SPELL_EFFECT_HANDLE_HIT_TARGET);

    // AI functions
    if (go->AI())
        go->AI()->SpellHit(spell->m_caster, spell->m_spellInfo);

    if (spell->m_caster->GetTypeId() == TYPEID_UNIT && spell->m_caster->ToCreature()->IsAIEnabled())
        spell->m_caster->ToCreature()->AI()->SpellHitTarget(go, spell->m_spellInfo);
    else if (spell->m_caster->GetTypeId() == TYPEID_GAMEOBJECT && spell->m_caster->ToGameObject()->AI())
        spell->m_caster->ToGameObject()->AI()->SpellHitTarget(go, spell->m_spellInfo);

    spell->CallScriptOnHitHandlers();
    spell->CallScriptAfterHitHandlers();
}

void Spell::ItemTargetInfo::DoTargetSpellHit(Spell* spell, uint8 effIndex)
{
    spell->CallScriptBeforeHitHandlers();

    spell->HandleEffects(nullptr, TargetItem, nullptr, nullptr, effIndex, SPELL_EFFECT_HANDLE_HIT_TARGET);

    spell->CallScriptOnHitHandlers();
    spell->CallScriptAfterHitHandlers();
}

void Spell::CorpseTargetInfo::DoTargetSpellHit(Spell* spell, uint8 effIndex)
{
    Corpse* corpse = ObjectAccessor::GetCorpse(*spell->m_caster, TargetGUID);
    if (!corpse)
        return;

    spell->CallScriptBeforeHitHandlers();

    spell->HandleEffects(nullptr, nullptr, nullptr, corpse, effIndex, SPELL_EFFECT_HANDLE_HIT_TARGET);

    spell->CallScriptOnHitHandlers();
    spell->CallScriptAfterHitHandlers();
}

SpellMissInfo Spell::PreprocessSpellHit(Unit* unit, bool scaleAura, TargetInfo& hitInfo)
{
    if (!unit)
        return SPELL_MISS_EVADE;

    // Target may have begun evading between launch and hit phases - re-check now
    if (Creature* creatureTarget = unit->ToCreature())
        if (creatureTarget->IsEvadingAttacks())
            return SPELL_MISS_EVADE;

    // For delayed spells immunity may be applied between missile launch and hit - check immunity for that case
    if (m_spellInfo->Speed && unit->IsImmunedToSpell(m_spellInfo, m_caster))
        return SPELL_MISS_IMMUNE;

    CallScriptBeforeHitHandlers();

    if (Player* player = unit->ToPlayer())
    {
        player->StartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_SPELL_TARGET, m_spellInfo->Id);
        player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, m_spellInfo->Id, 0, 0, m_caster);
        player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2, m_spellInfo->Id);
    }

    if (Player* player = m_caster->ToPlayer())
    {
        player->StartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_SPELL_CASTER, m_spellInfo->Id);
        player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL2, m_spellInfo->Id, 0, 0, unit);
    }

    if (m_caster != unit)
    {
        // Recheck  UNIT_FLAG_NON_ATTACKABLE for delayed spells
        if (m_spellInfo->Speed > 0.0f && unit->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE) && unit->GetCharmerOrOwnerGUID() != m_caster->GetGUID())
            return SPELL_MISS_EVADE;

        if (m_caster->IsValidAttackTarget(unit, m_spellInfo))
            unit->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::HostileActionReceived);
        else if (m_caster->IsFriendlyTo(unit))
        {
            // for delayed spells ignore negative spells (after duel end) for friendly targets
            if (m_spellInfo->Speed > 0.0f && unit->GetTypeId() == TYPEID_PLAYER && !IsPositive() && !m_caster->IsValidAssistTarget(unit, m_spellInfo))
                return SPELL_MISS_EVADE;

            // assisting case, healing and resurrection
            if (unit->HasUnitState(UNIT_STATE_ATTACK_PLAYER))
            {
                if (Player* playerOwner = m_caster->GetCharmerOrOwnerPlayerOrPlayerItself())
                {
                    playerOwner->SetContestedPvP();
                    playerOwner->UpdatePvP(true);
                }
            }

            if (m_originalCaster && unit->IsInCombat() && m_spellInfo->CausesInitialThreat())
            {
                if (m_originalCaster->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED)) // only do explicit combat forwarding for PvP enabled units
                    m_originalCaster->GetCombatManager().InheritCombatStatesFrom(unit);    // for creature v creature combat, the threat forward does it for us
                unit->GetThreatManager().ForwardThreatForAssistingMe(m_originalCaster, 0.0f, nullptr, true);
            }
        }
    }

    // original caster for auras
    WorldObject* origCaster = m_caster;
    if (m_originalCaster)
        origCaster = m_originalCaster;

    // check immunity due to diminishing returns
    if (Aura::BuildEffectMaskForOwner(m_spellInfo, MAX_EFFECT_MASK, unit))
    {
        // Select rank for aura with level requirements only in specific cases
        // Unit has to be target only of aura effect, both caster and target have to be players, target has to be other than unit target
        hitInfo.AuraSpellInfo = m_spellInfo;
        if (scaleAura)
        {
            if (SpellInfo const* actualSpellInfo = m_spellInfo->GetAuraRankForLevel(unitTarget->getLevel()))
                hitInfo.AuraSpellInfo = actualSpellInfo;

            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            {
                hitInfo.AuraBasePoints[i] = hitInfo.AuraSpellInfo->Effects[i].BasePoints;
                if (m_spellInfo->Effects[i].Effect != hitInfo.AuraSpellInfo->Effects[i].Effect)
                {
                    hitInfo.AuraSpellInfo = m_spellInfo;
                    break;
                }
            }
        }

        // Get Data Needed for Diminishing Returns, some effects may have multiple auras, so this must be done on spell hit, not aura add
        bool triggered = (m_triggeredByAuraSpell != nullptr);
        hitInfo.DRGroup = m_spellInfo->GetDiminishingReturnsGroupForSpell(triggered);

        DiminishingLevels diminishLevel = DIMINISHING_LEVEL_1;
        if (hitInfo.DRGroup)
        {
            diminishLevel = unit->GetDiminishing(hitInfo.DRGroup);
            DiminishingReturnsType type = m_spellInfo->GetDiminishingReturnsGroupType(triggered);
            // Increase Diminishing on unit, current informations for actually casts will use values above
            if (type == DRTYPE_ALL || (type == DRTYPE_PLAYER && unit->IsAffectedByDiminishingReturns()))
                unit->IncrDiminishing(m_spellInfo, triggered);
        }

        // Now Reduce spell duration using data received at spell hit
        // check whatever effects we're going to apply, diminishing returns only apply to negative aura effects
        hitInfo.Positive = true;
        if (origCaster == unit || !origCaster->IsFriendlyTo(unit))
        {
            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            {
                // mod duration only for effects applying aura!
                if (hitInfo.EffectMask & (1 << i) &&
                    hitInfo.AuraSpellInfo->Effects[i].IsUnitOwnedAuraEffect() &&
                    !hitInfo.AuraSpellInfo->IsPositiveEffect(i))
                {
                    hitInfo.Positive = false;
                    break;
                }
            }
        }

        hitInfo.AuraDuration = Aura::CalcMaxDuration(hitInfo.AuraSpellInfo, origCaster);

        // unit is immune to aura if it was diminished to 0 duration
        if (!hitInfo.Positive && !unit->ApplyDiminishingToDuration(hitInfo.AuraSpellInfo, triggered, hitInfo.AuraDuration, origCaster, diminishLevel))
            if (std::all_of(std::begin(hitInfo.AuraSpellInfo->Effects), std::end(hitInfo.AuraSpellInfo->Effects), [](SpellEffectInfo const& effInfo) { return !effInfo.IsEffect() || effInfo.Effect == SPELL_EFFECT_APPLY_AURA; }))
                return SPELL_MISS_IMMUNE;
    }

    return SPELL_MISS_NONE;
}

void Spell::DoSpellEffectHit(Unit* unit, uint8 effIndex, TargetInfo& hitInfo)
{
    if (uint8 aura_effmask = Aura::BuildEffectMaskForOwner(m_spellInfo, 1 << effIndex, unit))
    {
        WorldObject* caster = m_caster;
        if (m_originalCaster)
            caster = m_originalCaster;

        if (caster)
        {
            bool refresh = false;

            if (!hitInfo.HitAura)
            {
                bool const resetPeriodicTimer = [&]()
                {
                    // HoTs and DoTs don't reset their periodic timer and roll ther duration over
                    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                        if (m_spellInfo->Effects[i].IsEffect() && (m_spellInfo->Effects[i].ApplyAuraName == SPELL_AURA_PERIODIC_DAMAGE
                            || m_spellInfo->Effects[i].ApplyAuraName == SPELL_AURA_PERIODIC_HEAL))
                            return false;

                    if (m_spellInfo->StackAmount < 2)
                        return !(_triggeredCastFlags & TRIGGERED_DONT_RESET_PERIODIC_TIMER);

                    return true;
                }();
                uint8 const allAuraEffectMask = Aura::BuildEffectMaskForOwner(hitInfo.AuraSpellInfo, MAX_EFFECT_MASK, unit);
                int32 const* bp = hitInfo.AuraBasePoints;
                if (hitInfo.AuraSpellInfo == m_spellInfo)
                    bp = m_spellValue->EffectBasePoints;

                AuraCreateInfo createInfo(hitInfo.AuraSpellInfo, allAuraEffectMask, unit);
                createInfo
                    .SetCasterGUID(caster->GetGUID())
                    .SetBaseAmount(bp)
                    .SetCastItemGUID(m_CastItem ? m_CastItem->GetGUID() : ObjectGuid::Empty)
                    .SetPeriodicReset(resetPeriodicTimer)
                    .SetOwnerEffectMask(aura_effmask)
                    .IsRefresh = &refresh;

                if (Aura* aura = Aura::TryRefreshStackOrCreate(createInfo, false))
                {
                    hitInfo.HitAura = aura->ToUnitAura();

                    // Set aura stack amount to desired value
                    if (m_spellValue->AuraStackAmount > 1)
                    {
                        if (!refresh)
                            hitInfo.HitAura->SetStackAmount(m_spellValue->AuraStackAmount);
                        else
                            hitInfo.HitAura->ModStackAmount(m_spellValue->AuraStackAmount);
                    }

                    hitInfo.HitAura->SetDiminishGroup(hitInfo.DRGroup);

                    if (!m_spellValue->Duration.has_value())
                    {
                        hitInfo.AuraDuration = caster->ModSpellDuration(hitInfo.AuraSpellInfo, unit, hitInfo.AuraDuration, hitInfo.Positive, hitInfo.HitAura->GetEffectMask());
                        if (hitInfo.AuraDuration > 0)
                        {
                            if (m_spellInfo->HasAttribute(SPELL_ATTR5_SPELL_HASTE_AFFECTS_PERIODIC) || m_spellInfo->HasAttribute(SPELL_ATTR8_HASTE_AFFECTS_DURATION))
                            {
                                int32 origDuration = hitInfo.AuraDuration;
                                hitInfo.AuraDuration = 0;

                                int32 period = 0;
                                for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                                    if (AuraEffect const* aurEff = hitInfo.HitAura->GetEffect(effIndex))
                                        if (int32 effectPeriod = aurEff->GetPeriod())
                                            period = effectPeriod;

                                if (period != 0)
                                    hitInfo.AuraDuration = std::clamp(origDuration / period * period, 1, origDuration);

                                // if there is no periodic effect
                                if (!hitInfo.AuraDuration)
                                    hitInfo.AuraDuration = origDuration;
                            }
                            // Apply rolled over duration if there is any
                            hitInfo.AuraDuration += hitInfo.HitAura->GetRolledOverDuration();
                        }
                    }
                    else
                        hitInfo.AuraDuration = *m_spellValue->Duration;

                    if (hitInfo.AuraDuration != hitInfo.HitAura->GetMaxDuration())
                    {
                        hitInfo.HitAura->SetMaxDuration(hitInfo.AuraDuration);
                        hitInfo.HitAura->SetDuration(hitInfo.AuraDuration);
                    }

                    if (refresh)
                        hitInfo.HitAura->AddStaticApplication(unit, aura_effmask);
                }
            }
            else
                hitInfo.HitAura->AddStaticApplication(unit, aura_effmask);
        }
    }

    _spellAura = hitInfo.HitAura;
    HandleEffects(unit, nullptr, nullptr, nullptr, effIndex, SPELL_EFFECT_HANDLE_HIT_TARGET);
    _spellAura = nullptr;
}

void Spell::DoTriggersOnSpellHit(Unit* unit)
{
    // handle SPELL_AURA_ADD_TARGET_TRIGGER auras
    // this is executed after spell proc spells on target hit
    // spells are triggered for each hit spell target
    // info confirmed with retail sniffs of permafrost and shadow weaving
    if (!m_hitTriggerSpells.empty())
    {
        int32 _duration = 0;
        for (auto i = m_hitTriggerSpells.begin(); i != m_hitTriggerSpells.end(); ++i)
        {
            if (CanExecuteTriggersOnHit(unit, i->triggeredByAura) && roll_chance_i(i->chance))
            {
                m_caster->CastSpell(unit, i->triggeredSpell->Id, true);
                TC_LOG_DEBUG("spells", "Spell %d triggered spell %d by SPELL_AURA_ADD_TARGET_TRIGGER aura", m_spellInfo->Id, i->triggeredSpell->Id);

                // SPELL_AURA_ADD_TARGET_TRIGGER auras shouldn't trigger auras without duration
                // set duration of current aura to the triggered spell
                if (i->triggeredSpell->GetDuration() == -1)
                {
                    if (Aura* triggeredAur = unit->GetAura(i->triggeredSpell->Id, m_caster->GetGUID()))
                    {
                        // get duration from aura-only once
                        if (!_duration)
                        {
                            Aura* aur = unit->GetAura(m_spellInfo->Id, m_caster->GetGUID());
                            _duration = aur ? aur->GetDuration() : -1;
                        }
                        triggeredAur->SetDuration(_duration);
                    }
                }
            }
        }
    }

    // trigger linked auras remove/apply
    /// @todo remove/cleanup this, as this table is not documented and people are doing stupid things with it
    if (std::vector<int32> const* spellTriggered = sSpellMgr->GetSpellLinked(m_spellInfo->Id + SPELL_LINK_HIT))
    {
        for (std::vector<int32>::const_iterator i = spellTriggered->begin(); i != spellTriggered->end(); ++i)
        {
            if (*i < 0)
                unit->RemoveAurasDueToSpell(-(*i));
            else
                unit->CastSpell(unit, *i, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                .SetOriginalCaster(m_caster->GetGUID())
                .SetTriggeringSpell(this));
        }
    }
}

bool Spell::UpdateChanneledTargetList()
{
    // Not need check return true
    if (m_channelTargetEffectMask == 0)
        return true;

    uint8 channelTargetEffectMask = m_channelTargetEffectMask;
    uint8 channelAuraMask = 0;
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        if (m_spellInfo->Effects[i].Effect == SPELL_EFFECT_APPLY_AURA || m_spellInfo->Effects[i].Effect == SPELL_EFFECT_APPLY_AURA_2)
            channelAuraMask |= 1 << i;

    channelAuraMask &= channelTargetEffectMask;

    float range = 0;
    if (channelAuraMask)
    {
        range = m_spellInfo->GetMaxRange(IsPositive());
        if (Player* modOwner = m_caster->GetSpellModOwner())
            modOwner->ApplySpellMod(m_spellInfo->Id, SpellModOp::Range, range, this);

        // add little tolerance level
        range += std::min(MAX_SPELL_RANGE_TOLERANCE, range*0.1f); // 10% but no more than MAX_SPELL_RANGE_TOLERANCE
    }

    for (TargetInfo& targetInfo : m_UniqueTargetInfo)
    {
        if (targetInfo.MissCondition == SPELL_MISS_NONE && (channelTargetEffectMask & targetInfo.EffectMask))
        {
            Unit* unit = m_caster->GetGUID() == targetInfo.TargetGUID ? m_caster->ToUnit() : ObjectAccessor::GetUnit(*m_caster, targetInfo.TargetGUID);
            if (!unit)
                continue;

            if (IsValidDeadOrAliveTarget(unit))
            {
                if (channelAuraMask & targetInfo.EffectMask)
                {
                    if (AuraApplication * aurApp = unit->GetAuraApplication(m_spellInfo->Id, m_originalCasterGUID))
                    {
                        if (m_caster != unit && !m_caster->IsWithinDistInMap(unit, range))
                        {
                            targetInfo.EffectMask &= ~aurApp->GetEffectMask();
                            unit->RemoveAura(aurApp);
                            continue;
                        }
                    }
                    else // aura is dispelled
                        continue;
                }

                channelTargetEffectMask &= ~targetInfo.EffectMask;   // remove from need alive mask effect that have alive target
            }
        }
    }

    // is all effects from m_needAliveTargetMask have alive targets
    return channelTargetEffectMask == 0;
}

SpellCastResult Spell::prepare(SpellCastTargets const& targets, AuraEffect const* triggeredByAura)
{
    if (m_CastItem)
    {
        m_castItemGUID = m_CastItem->GetGUID();
        m_castItemEntry = m_CastItem->GetEntry();
    }
    else
    {
        m_castItemGUID.Clear();
        m_castItemEntry = 0;
    }

    InitExplicitTargets(targets);

    // Fill aura scaling information
    if (Unit* unitCaster = m_caster->ToUnit())
    {
        if (unitCaster->IsControlledByPlayer() && !m_spellInfo->IsPassive() && m_spellInfo->SpellLevel && !m_spellInfo->IsChanneled() && !(_triggeredCastFlags & TRIGGERED_IGNORE_AURA_SCALING))
        {
            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            {
                if (m_spellInfo->Effects[i].Effect == SPELL_EFFECT_APPLY_AURA || m_spellInfo->Effects[i].Effect == SPELL_EFFECT_APPLY_AURA_2)
                {
                    // Change aura with ranks only if basepoints are taken from spellInfo and aura is positive
                    if (m_spellInfo->IsPositiveEffect(i))
                    {
                        m_auraScaleMask |= (1 << i);
                        if (m_spellValue->EffectBasePoints[i] != m_spellInfo->Effects[i].BasePoints)
                        {
                            m_auraScaleMask = 0;
                            break;
                        }
                    }
                }
            }
        }
    }

    m_spellState = SPELL_STATE_PREPARING;

    if (triggeredByAura)
        m_triggeredByAuraSpell  = triggeredByAura->GetSpellInfo();

    // create and add update event for this spell
    _spellEvent = new SpellEvent(this);
    m_caster->m_Events.AddEvent(_spellEvent, m_caster->m_Events.CalculateTime(1));

    // check disables
    if (DisableMgr::IsDisabledFor(DISABLE_TYPE_SPELL, m_spellInfo->Id, m_caster))
    {
        SendCastResult(SPELL_FAILED_SPELL_UNAVAILABLE);
        finish(false);
        return SPELL_FAILED_SPELL_UNAVAILABLE;
    }

    // Prevent casting at cast another spell (ServerSide check)
    if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CAST_IN_PROGRESS) && m_caster->ToUnit() && m_caster->ToUnit()->IsNonMeleeSpellCast(false, true, true, m_spellInfo->Id == 75) && m_cast_count)
    {
        SendCastResult(SPELL_FAILED_SPELL_IN_PROGRESS);
        finish(false);
        return SPELL_FAILED_SPELL_IN_PROGRESS;
    }

    LoadScripts();

    // Fill cost data (do not use power for item casts)
    m_powerCost = m_CastItem ? 0 : m_spellInfo->CalcPowerCost(m_caster, m_spellSchoolMask, this);

    // Set combo point requirement
    if ((_triggeredCastFlags & TRIGGERED_IGNORE_COMBO_POINTS) || m_CastItem)
        m_needComboPoints = false;

    MountResult mountResult = MountResult::Ok;
    uint32 param1 = 0, param2 = 0;
    SpellCastResult result = CheckCast(true, &param1, &param2, &mountResult);
    // target is checked in too many locations and with different results to handle each of them
    // handle just the general SPELL_FAILED_BAD_TARGETS result which is the default result for most DBC target checks
    if (_triggeredCastFlags & TRIGGERED_IGNORE_TARGET_CHECK && result == SPELL_FAILED_BAD_TARGETS)
        result = SPELL_CAST_OK;
    if (result != SPELL_CAST_OK)
    {
        // Periodic auras should be interrupted when aura triggers a spell which can't be cast
        // for example bladestorm aura should be removed on disarm as of patch 3.3.5
        // channeled periodic spells should be affected by this (arcane missiles, penance, etc)
        // a possible alternative sollution for those would be validating aura target on unit state change
        if (triggeredByAura && triggeredByAura->IsPeriodic() && !triggeredByAura->GetBase()->IsPassive())
        {
            SendChannelUpdate(0);
            triggeredByAura->GetBase()->SetDuration(0);
        }

        // Send mount result
        if (mountResult != MountResult::Ok)
            SendMountResult(mountResult);

        if (param1 || param2)
            SendCastResult(result, &param1, &param2);
        else
            SendCastResult(result);

        // queue autorepeat spells for future repeating
        if (GetCurrentContainer() == CURRENT_AUTOREPEAT_SPELL && m_caster->IsUnit())
            m_caster->ToUnit()->SetCurrentCastSpell(this);

        finish(false);
        return result;
    }

    // Prepare data for triggers
    prepareDataForTriggerSystem();

    if (Player* player = m_caster->ToPlayer())
    {
        if (!player->GetCommandStatus(CHEAT_CASTTIME))
        {
            // calculate cast time (calculated after first CheckCast check to prevent charge counting for first CheckCast fail)
            m_casttime = m_spellInfo->CalcCastTime(player->getLevel(), this);
        }
        else
            m_casttime = 0; // Set cast time to 0 if .cheat casttime is enabled.
    }
    else
        m_casttime = m_spellInfo->CalcCastTime(m_caster->IsUnit() ? m_caster->ToUnit()->getLevel() : 0, this);

    if (m_caster->IsPlayer() && m_caster->ToUnit()->isMoving())
    {
        result = CheckMovement();
        if (result != SPELL_CAST_OK)
        {
            SendCastResult(result);
            finish(false);
            return result;
        }
    }

    // Creatures focus their target when possible
    if (m_casttime > 0 && m_caster->IsCreature()
        && !m_spellInfo->IsNextMeleeSwingSpell()
        && !IsAutoRepeat()
        && !m_caster->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_POSSESSED)
        && !(_triggeredCastFlags & TRIGGERED_IGNORE_SET_FACING)
        && !m_spellInfo->HasAttribute(SPELL_ATTR5_ALLOW_ACTIONS_DURING_CHANNEL))
    {
        WorldObject const* focusTarget = m_caster;
        if (m_spellInfo->NeedsExplicitUnitTarget())
            focusTarget = m_targets.GetObjectTarget();

        m_caster->ToCreature()->SetSpellFocus(this, focusTarget);
    }

    // set timer base at cast time
    ReSetTimer();

    TC_LOG_DEBUG("spells", "Spell::prepare: spell id %u source %u caster %d customCastFlags %u mask %u", m_spellInfo->Id, m_caster->GetEntry(), m_originalCaster ? m_originalCaster->GetEntry() : -1, _triggeredCastFlags, m_targets.GetTargetMask());

    //Containers for channeled spells have to be set
    /// @todoApply this to all cast spells if needed
    // Why check duration? 29350: channelled triggers channelled
    if ((_triggeredCastFlags & TRIGGERED_CAST_DIRECTLY) && (!m_spellInfo->IsChanneled() || !m_spellInfo->GetMaxDuration()))
        cast(true);
    else
    {
        if (Unit* unitCaster = m_caster->ToUnit())
        {
            // stealth must be removed at cast starting (at show channel bar)
            // skip triggered spell (item equip spell casting and other not explicit character casts/item uses)
            if (!(_triggeredCastFlags & TRIGGERED_IGNORE_AURA_INTERRUPT_FLAGS) && !m_spellInfo->HasAttribute(SPELL_ATTR2_NOT_AN_ACTION))
                unitCaster->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Action, m_spellInfo);

            unitCaster->SetCurrentCastSpell(this);
        }
        SendSpellStart();

        if (!(_triggeredCastFlags & TRIGGERED_IGNORE_GCD))
            TriggerGlobalCooldown();

        CallScriptOnSpellStartHandlers();

        // commented out !m_spellInfo->StartRecoveryTime, it forces instant spells with global cooldown to be processed in spell::update
        // as a result a spell that passed CheckCast and should be processed instantly may suffer from this delayed process
        // the easiest bug to observe is LoS check in AddUnitTarget, even if spell passed the CheckCast LoS check the situation can change in spell::update
        // because target could be relocated in the meantime, making the spell fly to the air (no targets can be registered, so no effects processed, nothing in combat log)
        if (!m_casttime && /*!m_spellInfo->StartRecoveryTime && */ GetCurrentContainer() == CURRENT_GENERIC_SPELL)
            cast(true);
    }

    return SPELL_CAST_OK;
}

void Spell::cancel()
{
    if (m_spellState == SPELL_STATE_FINISHED)
        return;

    uint32 oldState = m_spellState;
    m_spellState = SPELL_STATE_FINISHED;

    m_autoRepeat = false;
    switch (oldState)
    {
        case SPELL_STATE_PREPARING:
            CancelGlobalCooldown();
            [[fallthrough]];
        case SPELL_STATE_DELAYED:
            SendInterrupted(0);
            SendCastResult(SPELL_FAILED_INTERRUPTED);
            break;
        case SPELL_STATE_CASTING:
            for (TargetInfo const& targetInfo : m_UniqueTargetInfo)
                if (targetInfo.MissCondition == SPELL_MISS_NONE)
                    if (Unit* unit = m_caster->GetGUID() == targetInfo.TargetGUID ? m_caster->ToUnit() : ObjectAccessor::GetUnit(*m_caster, targetInfo.TargetGUID))
                        unit->RemoveOwnedAura(m_spellInfo->Id, m_originalCasterGUID, 0, AuraRemoveFlags::ByCancel);

            SendChannelUpdate(0);
            SendInterrupted(0);
            SendCastResult(SPELL_FAILED_INTERRUPTED);
            m_appliedMods.clear();
            break;
        default:
            break;
    }

    SetReferencedFromCurrent(false);
    if (m_selfContainer && *m_selfContainer == this)
        *m_selfContainer = nullptr;

    // originalcaster handles gameobjects/dynobjects for gob caster
    if (m_originalCaster)
    {
        m_originalCaster->RemoveDynObject(m_spellInfo->Id);
        if (m_spellInfo->IsChanneled()) // if not channeled then the object for the current cast wasn't summoned yet
            m_originalCaster->RemoveGameObject(m_spellInfo->Id, true);
    }

    //set state back so finish will be processed
    m_spellState = oldState;

    finish(false);
}

void Spell::cast(bool skipCheck)
{
    Player* modOwner = m_caster->GetSpellModOwner();
    Spell* lastSpellMod = nullptr;
    if (modOwner)
    {
        lastSpellMod = modOwner->m_spellModTakingSpell;
        if (lastSpellMod)
            modOwner->SetSpellModTakingSpell(lastSpellMod, false);
    }

    _cast(skipCheck);

    if (lastSpellMod)
        modOwner->SetSpellModTakingSpell(lastSpellMod, true);
}

void Spell::_cast(bool skipCheck)
{
    // update pointers base at GUIDs to prevent access to non-existed already object
    if (!UpdatePointers())
    {
        // cancel the spell if UpdatePointers() returned false, something wrong happened there
        cancel();
        return;
    }

    // cancel at lost explicit target during cast
    if (m_targets.GetObjectTargetGUID() && !m_targets.GetObjectTarget())
    {
        cancel();
        return;
    }

    if (Player* playerCaster = m_caster->ToPlayer())
    {
        // now that we've done the basic check, now run the scripts
        // should be done before the spell is actually executed
        sScriptMgr->OnPlayerSpellCast(playerCaster, this, skipCheck);

        // As of 3.0.2 pets begin attacking their owner's target immediately
        // Let any pets know we've attacked something. Check DmgClass for harmful spells only
        // This prevents spells such as Hunter's Mark from triggering pet attack
        if (this->GetSpellInfo()->DmgClass != SPELL_DAMAGE_CLASS_NONE)
            if (Unit* unitTarget = m_targets.GetUnitTarget())
                for (Unit* controlled : playerCaster->m_Controlled)
                    if (Creature* cControlled = controlled->ToCreature())
                        if (CreatureAI* controlledAI = cControlled->AI())
                            controlledAI->OwnerAttacked(unitTarget);
    }

    SetExecutedCurrently(true);

    // Should this be done for original caster?
    Player* modOwner = m_caster->GetSpellModOwner();
    if (modOwner)
    {
        // Set spell which will drop charges for triggered cast spells
        // if not successfully cast, will be remove in finish(false)
        modOwner->SetSpellModTakingSpell(this, true);
    }

    CallScriptBeforeCastHandlers();

    // skip check if done already (for instant cast spells for example)
    if (!skipCheck)
    {
        auto cleanupSpell = [this, modOwner](SpellCastResult res, uint32* p1 = nullptr, uint32* p2 = nullptr)
        {
            SendCastResult(res, p1, p2);
            SendInterrupted(0);

            if (modOwner)
                modOwner->SetSpellModTakingSpell(this, false);

            finish(false);
            SetExecutedCurrently(false);
        };

        uint32 param1 = 0, param2 = 0;
        SpellCastResult castResult = CheckCast(false, &param1, &param2);
        if (castResult != SPELL_CAST_OK)
        {
            cleanupSpell(castResult, &param1, &param2);
            return;
        }

        // additional check after cast bar completes (must not be in CheckCast)
        // if trade not complete then remember it in trade data
        if (m_targets.GetTargetMask() & TARGET_FLAG_TRADE_ITEM)
        {
            if (modOwner)
            {
                if (TradeData* my_trade = modOwner->GetTradeData())
                {
                    if (!my_trade->IsInAcceptProcess())
                    {
                        // Spell will be cast after completing the trade. Silently ignore at this place
                        my_trade->SetSpell(m_spellInfo->Id, m_CastItem);
                        cleanupSpell(SPELL_FAILED_DONT_REPORT);
                        return;
                    }
                }
            }
        }

        // check diminishing returns (again, only after finish cast bar, tested on retail)
        if (Unit* target = m_targets.GetUnitTarget())
        {
            uint8 aura_effmask = 0;
            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                if (m_spellInfo->Effects[i].IsUnitOwnedAuraEffect())
                    aura_effmask |= 1 << i;

            if (aura_effmask)
            {
                bool const triggered = m_triggeredByAuraSpell != nullptr;
                if (m_spellInfo->GetDiminishingReturnsGroupForSpell(triggered))
                {
                    DiminishingReturnsType type = m_spellInfo->GetDiminishingReturnsGroupType(triggered);
                    if (type == DRTYPE_ALL || (type == DRTYPE_PLAYER && target->IsAffectedByDiminishingReturns()))
                    {
                        if (Unit* caster = m_originalCaster ? m_originalCaster : m_caster->ToUnit())
                        {
                            if (target->HasStrongerAuraWithDR(m_spellInfo, caster, triggered))
                            {
                                cleanupSpell(SPELL_FAILED_AURA_BOUNCED);
                                return;
                            }
                        }
                    }
                }
            }
        }
    }

    SelectSpellTargets();

    // Spell may be finished after target map check
    if (m_spellState == SPELL_STATE_FINISHED)
    {
        SendInterrupted(0);

        if (modOwner)
            modOwner->SetSpellModTakingSpell(this, false);

        finish(false);
        SetExecutedCurrently(false);
        return;
    }

    if (Unit* unitCaster = m_caster->ToUnit())
        if (m_spellInfo->HasAttribute(SPELL_ATTR1_DISMISS_PET_FIRST))
            if (Creature* pet = ObjectAccessor::GetCreature(*m_caster, unitCaster->GetPetGUID()))
                pet->DespawnOrUnsummon();

    PrepareTriggersExecutedOnHit();

    CallScriptOnCastHandlers();

    // traded items have trade slot instead of guid in m_itemTargetGUID
    // set to real guid to be sent later to the client
    m_targets.UpdateTradeSlotItem();

    if (Player* player = m_caster->ToPlayer())
    {
        if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CAST_ITEM) && m_CastItem)
        {
            player->StartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_ITEM, m_CastItem->GetEntry());
            player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_USE_ITEM, m_CastItem->GetEntry());
        }

        player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL, m_spellInfo->Id);
    }

    if (!(_triggeredCastFlags & TRIGGERED_IGNORE_POWER_AND_REAGENT_COST))
    {
        // Powers have to be taken before SendSpellGo
        TakePower();
        TakeReagents();                                         // we must remove reagents before HandleEffects to allow place crafted item in same slot
    }
    else if (Item* targetItem = m_targets.GetItemTarget())
    {
        /// Not own traded item (in trader trade slot) req. reagents including triggered spell case
        if (targetItem->GetOwnerGUID() != m_caster->GetGUID())
            TakeReagents();
    }

    if (!m_spellInfo->IsChanneled())
        if (Creature* creatureCaster = m_caster->ToCreature())
            creatureCaster->ReleaseSpellFocus(this);

    // CAST SPELL
    SendSpellCooldown();

    HandleLaunchPhase();

    // we must send smsg_spell_go packet before m_castItem delete in TakeCastItem()...
    SendSpellGo();

    // Okay, everything is prepared. Now we need to distinguish between immediate and evented delayed spells
    if ((m_spellInfo->Speed > 0.0f && !m_spellInfo->IsChanneled()) || m_spellInfo->HasAttribute(SPELL_ATTR4_NO_HARMFUL_THREAT))
    {
        // Remove used for cast item if need (it can be already nullptr after TakeReagents call
        // in case delayed spell remove item at cast delay start
        TakeCastItem();

        // Okay, maps created, now prepare flags
        m_immediateHandled = false;
        m_spellState = SPELL_STATE_DELAYED;
        SetDelayStart(0);

        if (Unit* unitCaster = m_caster->ToUnit())
            if (unitCaster->HasUnitState(UNIT_STATE_CASTING) && !unitCaster->IsNonMeleeSpellCast(false, false, true))
                unitCaster->ClearUnitState(UNIT_STATE_CASTING);
    }
    else
    {
        // Immediate spell, no big deal
        handle_immediate();
    }

    CallScriptAfterCastHandlers();

    if (std::vector<int32> const* spell_triggered = sSpellMgr->GetSpellLinked(m_spellInfo->Id))
    {
        for (int32 id : *spell_triggered)
        {
            if (id < 0)
            {
                if (Unit* unitCaster = m_caster->ToUnit())
                    unitCaster->RemoveAurasDueToSpell(-id);
            }
            else
                m_caster->CastSpell(m_targets.GetUnitTarget() ? m_targets.GetUnitTarget() : m_caster, id, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                .SetTriggeringSpell(this));
        }
    }

    if (modOwner)
    {
        modOwner->SetSpellModTakingSpell(this, false);

        //Clear spell cooldowns after every spell is cast if .cheat cooldown is enabled.
        if (m_originalCaster && modOwner->GetCommandStatus(CHEAT_COOLDOWN))
            m_originalCaster->GetSpellHistory()->ResetCooldown(m_spellInfo->Id, true);
    }

    SetExecutedCurrently(false);

    if (!m_originalCaster)
        return;

    // Handle procs on cast
    uint32 procAttacker = m_procAttacker;
    if (!procAttacker)
    {
        if (m_spellInfo->HasAttribute(SPELL_ATTR3_TREAT_AS_PERIODIC))
            procAttacker |= PROC_FLAG_DEAL_PERIODIC;
        else if (m_spellInfo->HasAttribute(SPELL_ATTR0_IS_ABILITY))
        {
            if (IsPositive())
                procAttacker |= PROC_FLAG_DEAL_HELPFUL_ABILITY;
            else
                procAttacker |= PROC_FLAG_DEAL_HARMFUL_ABILITY;
        }
        else
        {
            if (IsPositive())
                procAttacker |= PROC_FLAG_DEAL_HELPFUL_SPELL;
            else
                procAttacker |= PROC_FLAG_DEAL_HARMFUL_SPELL;
        }
    }

    uint32 hitMask = m_hitMask;
    if (!(hitMask & PROC_HIT_CRITICAL))
        hitMask |= PROC_HIT_NORMAL;

    if (!(_triggeredCastFlags & TRIGGERED_IGNORE_AURA_INTERRUPT_FLAGS) && !m_spellInfo->HasAttribute(SPELL_ATTR2_NOT_AN_ACTION))
        m_originalCaster->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::ActionDelayed, m_spellInfo);

    if (!m_spellInfo->HasAttribute(SPELL_ATTR3_SUPPRESS_CASTER_PROCS))
        Unit::ProcSkillsAndAuras(m_originalCaster, nullptr, procAttacker, PROC_FLAG_NONE, PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_CAST, hitMask, this, nullptr, nullptr);

    // Call CreatureAI hook OnSuccessfulSpellCast
    if (Creature* caster = m_originalCaster->ToCreature())
        if (CreatureAI* casterAI = caster->AI())
            casterAI->OnSpellCastFinished(GetSpellInfo(), SPELL_FINISHED_SUCCESSFUL_CAST);
}

template <class Container>
void Spell::DoProcessTargetContainer(Container& targetContainer)
{
    for (TargetInfoBase& target : targetContainer)
        target.PreprocessTarget(this);

    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        for (TargetInfoBase& target : targetContainer)
            if (target.EffectMask & (1 << i))
                target.DoTargetSpellHit(this, i);

    for (TargetInfoBase& target : targetContainer)
        target.DoDamageAndTriggers(this);
}

void Spell::handle_immediate()
{
    // start channeling if applicable
    if (m_spellInfo->IsChanneled())
    {
        int32 duration = Aura::CalcMaxDuration(m_spellInfo, m_caster);
        if (duration > 0 || m_spellValue->Duration)
        {
            if (m_spellValue->Duration)
                duration = *m_spellValue->Duration;

            m_channeledDuration = duration;
            SendChannelStart(duration);
        }
        else if (duration == -1)
            SendChannelStart(duration);

        if (duration != 0)
        {
            m_spellState = SPELL_STATE_CASTING;
            // GameObjects shouldn't cast channeled spells
            ASSERT_NOTNULL(m_caster->ToUnit())->AddInterruptMask(m_spellInfo->ChannelInterruptFlags, m_spellInfo->ChannelInterruptFlags2);
        }
    }

    PrepareTargetProcessing();

    // process immediate effects (items, ground, etc.) also initialize some variables
    _handle_immediate_phase();

    // consider spell hit for some spells without target, so they may proc on finish phase correctly
    if (m_UniqueTargetInfo.empty())
        m_hitMask = PROC_HIT_NORMAL;
    else
        DoProcessTargetContainer(m_UniqueTargetInfo);

    DoProcessTargetContainer(m_UniqueGOTargetInfo);
    DoProcessTargetContainer(m_UniqueCorpseTargetInfo);

    FinishTargetProcessing();

    // spell is finished, perform some last features of the spell here
    _handle_finish_phase();

    // Remove used for cast item if need (it can be already nullptr after TakeReagents call
    TakeCastItem();

    if (m_spellState != SPELL_STATE_CASTING)
        finish(true);                                       // successfully finish spell cast (not last in case autorepeat or channel spell)
}

uint64 Spell::handle_delayed(uint64 t_offset)
{
    if (!UpdatePointers())
    {
        // finish the spell if UpdatePointers() returned false, something wrong happened there
        finish(false);
        return 0;
    }

    Player* modOwner = m_caster->GetSpellModOwner();
    if (modOwner)
        modOwner->SetSpellModTakingSpell(this, true);

    uint64 next_time = 0;

    PrepareTargetProcessing();

    if (!m_immediateHandled)
    {
        _handle_immediate_phase();
        m_immediateHandled = true;
    }

    bool single_missile = (m_targets.HasDst());

    // now recheck units targeting correctness (need before any effects apply to prevent adding immunity at first effect not allow apply second spell effect and similar cases)
    {
        std::vector<TargetInfo> delayedTargets;
        m_UniqueTargetInfo.erase(std::remove_if(m_UniqueTargetInfo.begin(), m_UniqueTargetInfo.end(), [&](TargetInfo& target) -> bool
        {
            if (single_missile || target.TimeDelay <= t_offset)
            {
                target.TimeDelay = t_offset;
                delayedTargets.emplace_back(std::move(target));
                return true;
            }
            else if (next_time == 0 || target.TimeDelay < next_time)
                next_time = target.TimeDelay;

            return false;
        }), m_UniqueTargetInfo.end());

        DoProcessTargetContainer(delayedTargets);
    }

    // now recheck gameobject targeting correctness
    {
        std::vector<GOTargetInfo> delayedGOTargets;
        m_UniqueGOTargetInfo.erase(std::remove_if(m_UniqueGOTargetInfo.begin(), m_UniqueGOTargetInfo.end(), [&](GOTargetInfo& goTarget) -> bool
        {
            if (single_missile || goTarget.TimeDelay <= t_offset)
            {
                goTarget.TimeDelay = t_offset;
                delayedGOTargets.emplace_back(std::move(goTarget));
                return true;
            }
            else if (next_time == 0 || goTarget.TimeDelay < next_time)
                next_time = goTarget.TimeDelay;

            return false;
        }), m_UniqueGOTargetInfo.end());

        DoProcessTargetContainer(delayedGOTargets);
    }

    // now recheck corpse targeting correctness
    {
        std::vector<CorpseTargetInfo> delayedCorpseTargets;
        auto itr = std::remove_if(std::begin(m_UniqueCorpseTargetInfo), std::end(m_UniqueCorpseTargetInfo), [&](CorpseTargetInfo& goTarget) -> bool
        {
            if (single_missile || goTarget.TimeDelay <= t_offset)
            {
                goTarget.TimeDelay = t_offset;
                return true;
            }
            else if (next_time == 0 || goTarget.TimeDelay < next_time)
                next_time = goTarget.TimeDelay;

            return false;
        });

        delayedCorpseTargets.insert(delayedCorpseTargets.end(), std::make_move_iterator(itr), std::make_move_iterator(m_UniqueCorpseTargetInfo.end()));
        m_UniqueCorpseTargetInfo.erase(itr, m_UniqueCorpseTargetInfo.end());

        DoProcessTargetContainer(delayedCorpseTargets);
    }

    FinishTargetProcessing();

    if (modOwner)
        modOwner->SetSpellModTakingSpell(this, false);

    // All targets passed - need finish phase
    if (next_time == 0)
    {
        // spell is finished, perform some last features of the spell here
        _handle_finish_phase();

        finish(true);                                       // successfully finish spell cast

        // return zero, spell is finished now
        return 0;
    }
    else
    {
        // spell is unfinished, return next execution time
        return next_time;
    }
}

void Spell::_handle_immediate_phase()
{
    // handle some immediate features of the spell here
    HandleThreatSpells();

    // handle effects with SPELL_EFFECT_HANDLE_HIT mode
    for (uint32 j = 0; j < MAX_SPELL_EFFECTS; ++j)
    {
        // don't do anything for empty effect
        if (!m_spellInfo->Effects[j].IsEffect())
            continue;

        // call effect handlers to handle destination hit
        HandleEffects(nullptr, nullptr, nullptr, nullptr, j, SPELL_EFFECT_HANDLE_HIT);
    }

    // process items
    DoProcessTargetContainer(m_UniqueItemInfo);
}

void Spell::_handle_finish_phase()
{
    if (Unit* unitCaster = m_caster->ToUnit())
    {
        if (unitCaster->IsMovedByClient())
        {
            Player* mover = unitCaster->GetGameClientMovingMe()->GetBasePlayer();
            // Take for real after all targets are processed
            if (m_needComboPoints)
                mover->ClearComboPoints();

            // Real add combo points from effects
            if (m_comboPointGain)
                mover->GainSpellComboPoints(m_comboPointGain);

            if (m_spellInfo->PowerType == POWER_HOLY_POWER && mover->getClass() == CLASS_PALADIN)
                HandleHolyPower(mover);
        }

        if (unitCaster->m_extraAttacks && m_spellInfo->HasEffect(SPELL_EFFECT_ADD_EXTRA_ATTACKS))
        {
            if (Unit* victim = ObjectAccessor::GetUnit(*m_caster, m_targets.GetOrigUnitTargetGUID()))
                unitCaster->HandleProcExtraAttackFor(victim);
            else
                unitCaster->m_extraAttacks = 0;
        }
    }

    // Handle procs on finish
    if (!m_originalCaster)
        return;

    uint32 procAttacker = m_procAttacker;
    if (!procAttacker)
    {
        if (m_spellInfo->HasAttribute(SPELL_ATTR3_TREAT_AS_PERIODIC))
            procAttacker |= PROC_FLAG_DEAL_PERIODIC;
        else if (m_spellInfo->HasAttribute(SPELL_ATTR0_IS_ABILITY))
        {
            if (IsPositive())
                procAttacker |= PROC_FLAG_DEAL_HELPFUL_ABILITY;
            else
                procAttacker |= PROC_FLAG_DEAL_HARMFUL_ABILITY;
        }
        else
        {
            if (IsPositive())
                procAttacker |= PROC_FLAG_DEAL_HELPFUL_SPELL;
            else
                procAttacker |= PROC_FLAG_DEAL_HARMFUL_SPELL;
        }
    }

    if (!m_spellInfo->HasAttribute(SPELL_ATTR3_SUPPRESS_CASTER_PROCS))
        Unit::ProcSkillsAndAuras(m_originalCaster, nullptr, procAttacker, PROC_FLAG_NONE, PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_FINISH, m_hitMask, this, nullptr, nullptr);
}

void Spell::SendSpellCooldown()
{
    if (!m_caster->IsUnit())
        return;

    if (m_CastItem)
        m_caster->ToUnit()->GetSpellHistory()->HandleCooldowns(m_spellInfo, m_CastItem, this);
    else
        m_caster->ToUnit()->GetSpellHistory()->HandleCooldowns(m_spellInfo, m_castItemEntry, this);

    if (IsAutoRepeat())
        m_caster->ToUnit()->resetAttackTimer(RANGED_ATTACK);
}

void Spell::update(uint32 difftime)
{
    // update pointers based at it's GUIDs
    if (!UpdatePointers())
    {
        // cancel the spell if UpdatePointers() returned false, something wrong happened there
        cancel();
        return;
    }

    if (m_targets.GetUnitTargetGUID() && !m_targets.GetUnitTarget())
    {
        TC_LOG_DEBUG("spells", "Spell %u is cancelled due to removal of target.", m_spellInfo->Id);
        cancel();
        return;
    }

    // check if the player caster has moved before the spell finished
    // with the exception of spells affected with SPELL_AURA_CAST_WHILE_WALKING effect
    if (m_timer != 0 && m_caster->IsPlayer() && m_caster->ToUnit()->isMoving() && CheckMovement() != SPELL_CAST_OK)
    {
        // if charmed by creature, trust the AI not to cheat and allow the cast to proceed
        // @todo this is a hack, "creature" movesplines don't differentiate turning/moving right now
        // however, checking what type of movement the spline is for every single spline would be really expensive
        if (!m_caster->ToUnit()->GetCharmerGUID().IsCreature())
            cancel();
    }

    switch (m_spellState)
    {
        case SPELL_STATE_PREPARING:
        {
            if (m_timer > 0)
            {
                if (difftime >= (uint32)m_timer)
                    m_timer = 0;
                else
                    m_timer -= difftime;
            }

            if (m_timer == 0 && !m_spellInfo->IsNextMeleeSwingSpell())
                // don't CheckCast for instant spells - done in spell::prepare, skip duplicate checks, needed for range checks for example
                cast(!m_casttime);
            break;
        }
        case SPELL_STATE_CASTING:
        {
            if (m_timer)
            {
                // check if there are alive targets left
                if (!UpdateChanneledTargetList())
                {
                    TC_LOG_DEBUG("spells", "Channeled spell %d is removed due to lack of targets", m_spellInfo->Id);
                    m_timer = 0;

                    // Also remove applied auras
                    for (TargetInfo const& target : m_UniqueTargetInfo)
                        if (Unit* unit = m_caster->GetGUID() == target.TargetGUID ? m_caster->ToUnit() : ObjectAccessor::GetUnit(*m_caster, target.TargetGUID))
                            unit->RemoveOwnedAura(m_spellInfo->Id, m_originalCasterGUID, 0, AuraRemoveFlags::ByCancel);
                }

                if (m_timer > 0)
                {
                    if (difftime >= (uint32)m_timer)
                        m_timer = 0;
                    else
                        m_timer -= difftime;
                }
            }

            if (m_timer == 0)
            {
                SendChannelUpdate(0);
                finish();

                // We call the hook here instead of in Spell::finish because we only want to call it for completed channeling. Everything else is handled by interrupts
                if (Creature* creatureCaster = m_caster->ToCreature())
                    if (CreatureAI* casterAI = creatureCaster->AI())
                        casterAI->OnSpellCastFinished(m_spellInfo, SPELL_FINISHED_CHANNELING_COMPLETE);
            }
            break;
        }
        default:
            break;
    }
}

void Spell::finish(bool ok)
{
    if (m_spellState == SPELL_STATE_FINISHED)
        return;
    m_spellState = SPELL_STATE_FINISHED;

    if (!m_caster)
        return;

    Unit* unitCaster = m_caster->ToUnit();
    if (!unitCaster)
        return;

    // successful cast of the initial autorepeat spell is moved to idle state so that it is not deleted as long as autorepeat is active
    if (IsAutoRepeat() && unitCaster->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL) == this)
        m_spellState = SPELL_STATE_IDLE;

    if (m_spellInfo->IsChanneled())
        unitCaster->UpdateInterruptMask();

    if (unitCaster->HasUnitState(UNIT_STATE_CASTING) && !unitCaster->IsNonMeleeSpellCast(false, false, true))
        unitCaster->ClearUnitState(UNIT_STATE_CASTING);

    // Unsummon summon as possessed creatures on spell cancel
    if (m_spellInfo->IsChanneled() && unitCaster->GetTypeId() == TYPEID_PLAYER)
    {
        if (Unit* charm = unitCaster->GetCharmed())
            if (charm->GetTypeId() == TYPEID_UNIT
                && charm->ToCreature()->HasUnitTypeMask(UNIT_MASK_PUPPET)
                && charm->GetUInt32Value(UNIT_CREATED_BY_SPELL) == m_spellInfo->Id)
                ((Puppet*)charm)->UnSummon();
    }

    if (Creature* creatureCaster = unitCaster->ToCreature())
        creatureCaster->ReleaseSpellFocus(this);

    if (!ok)
        return;

    if (unitCaster->GetTypeId() == TYPEID_UNIT && unitCaster->IsSummon())
    {
        // Unsummon statue
        uint32 spell = unitCaster->GetUInt32Value(UNIT_CREATED_BY_SPELL);
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spell);
        if (spellInfo && spellInfo->SpellIconID == 2056)
        {
            TC_LOG_DEBUG("spells", "Statue %d is unsummoned in spell %d finish", m_caster->GetGUID().GetCounter(), m_spellInfo->Id);
            // Avoid infinite loops with setDeathState(JUST_DIED) being called over and over
            // It might make sense to do this check in Unit::setDeathState() and all overloaded functions
            if (unitCaster->getDeathState() != JUST_DIED)
                unitCaster->setDeathState(JUST_DIED);
            return;
        }
    }

    if (IsAutoActionResetSpell())
    {
        bool found = false;
        Unit::AuraEffectList const& vIgnoreReset = unitCaster->GetAuraEffectsByType(SPELL_AURA_IGNORE_MELEE_RESET);
        for (Unit::AuraEffectList::const_iterator i = vIgnoreReset.begin(); i != vIgnoreReset.end(); ++i)
        {
            if ((*i)->IsAffectingSpell(m_spellInfo))
            {
                found = true;
                break;
            }
        }

        if (!found && !m_spellInfo->HasAttribute(SPELL_ATTR2_DO_NOT_RESET_COMBAT_TIMERS))
        {
            unitCaster->resetAttackTimer(BASE_ATTACK);
            if (unitCaster->haveOffhandWeapon())
                unitCaster->resetAttackTimer(OFF_ATTACK);
            unitCaster->resetAttackTimer(RANGED_ATTACK);
        }
    }

    // potions disabled by client, send event "not in combat" if need
    if (unitCaster->GetTypeId() == TYPEID_PLAYER)
    {
        if (!m_triggeredByAuraSpell)
            unitCaster->ToPlayer()->UpdatePotionCooldown(this);
    }

    // Stop Attack for some spells
    if (m_spellInfo->HasAttribute(SPELL_ATTR0_CANCELS_AUTO_ATTACK_COMBAT))
        unitCaster->AttackStop();
}

void Spell::WriteCastResultInfo(WorldPacket& data, Player* caster, SpellInfo const* spellInfo, uint8 castCount, SpellCastResult result, SpellCustomErrors customError, uint32* param1 /*= nullptr*/, uint32* param2 /*= nullptr*/)
{
    data << uint8(castCount);
    data << uint32(spellInfo->Id);
    data << uint8(result);                                  // problem
    switch (result)
    {
        case SPELL_FAILED_NOT_READY:
            data << uint32(0);                              // unknown (value 1 update cooldowns on client flag)
            break;
        case SPELL_FAILED_REQUIRES_SPELL_FOCUS:
            if (param1)
                data << uint32(*param1);
            else
                data << uint32(spellInfo->RequiresSpellFocus);  // SpellFocusObject.dbc id
            break;
        case SPELL_FAILED_REQUIRES_AREA:                    // AreaTable.dbc id
            if (param1)
                data << uint32(*param1);
            else
            {
                // hardcode areas limitation case
                switch (spellInfo->Id)
                {
                    case 41617:                                 // Cenarion Mana Salve
                    case 41619:                                 // Cenarion Healing Salve
                        data << uint32(3905);
                        break;
                    case 41618:                                 // Bottled Nethergon Energy
                    case 41620:                                 // Bottled Nethergon Vapor
                        data << uint32(3842);
                        break;
                    case 45373:                                 // Bloodberry Elixir
                        data << uint32(4075);
                        break;
                    default:                                    // default case (don't must be)
                        data << uint32(0);
                        break;
                }
            }
            break;
        case SPELL_FAILED_TOTEMS:
            if (param1)
            {
                data << uint32(*param1);
                if (param2)
                    data << uint32(*param2);
            }
            else
            {
                if (spellInfo->Totem[0])
                    data << uint32(spellInfo->Totem[0]);
                if (spellInfo->Totem[1])
                    data << uint32(spellInfo->Totem[1]);
            }
            break;
        case SPELL_FAILED_TOTEM_CATEGORY:
            if (param1)
            {
                data << uint32(*param1);
                if (param2)
                    data << uint32(*param2);
            }
            else
            {
                if (spellInfo->TotemCategory[0])
                    data << uint32(spellInfo->TotemCategory[0]);
                if (spellInfo->TotemCategory[1])
                    data << uint32(spellInfo->TotemCategory[1]);
            }
            break;
        case SPELL_FAILED_EQUIPPED_ITEM_CLASS:
        case SPELL_FAILED_EQUIPPED_ITEM_CLASS_MAINHAND:
        case SPELL_FAILED_EQUIPPED_ITEM_CLASS_OFFHAND:
            if (param1 && param2)
            {
                data << uint32(*param1);
                data << uint32(*param2);
            }
            else
            {
                data << uint32(spellInfo->EquippedItemClass);
                data << uint32(spellInfo->EquippedItemSubClassMask);
            }
            break;
        case SPELL_FAILED_TOO_MANY_OF_ITEM:
        {
            if (param1)
                data << uint32(*param1);
            else
            {
                uint32 item = 0;
                for (uint8 effIndex = 0; effIndex < MAX_SPELL_EFFECTS && !item; ++effIndex)
                    if (uint32 itemType = spellInfo->Effects[effIndex].ItemType)
                        item = itemType;

                ItemTemplate const* proto = sObjectMgr->GetItemTemplate(item);
                if (proto && proto->GetItemLimitCategory())
                    data << uint32(proto->GetItemLimitCategory());
            }
            break;
        }
        case SPELL_FAILED_PREVENTED_BY_MECHANIC:
            data << uint32(spellInfo->GetAllEffectsMechanicMask());  // SpellMechanic.dbc id
            break;
        case SPELL_FAILED_NEED_EXOTIC_AMMO:
            data << uint32(spellInfo->EquippedItemSubClassMask); // seems correct...
            break;
        case SPELL_FAILED_NEED_MORE_ITEMS:
            data << uint32(0);                              // Item id
            data << uint32(0);                              // Item count?
            break;
        case SPELL_FAILED_MIN_SKILL:
            data << uint32(0);                              // SkillLine.dbc id
            data << uint32(0);                              // required skill value
            break;
        case SPELL_FAILED_FISHING_TOO_LOW:
            data << uint32(0);                              // required fishing skill
            break;
        case SPELL_FAILED_CUSTOM_ERROR:
            data << uint32(customError);
            break;
        case SPELL_FAILED_SILENCED:
            data << uint32(0);                              // Unknown
            break;
        case SPELL_FAILED_REAGENTS:
        {
            if (param1)
                data << uint32(*param1);
            else
            {
                uint32 missingItem = 0;
                for (uint32 i = 0; i < MAX_SPELL_REAGENTS; i++)
                {
                    if (spellInfo->Reagent[i] <= 0)
                        continue;

                    uint32 itemid = spellInfo->Reagent[i];
                    uint32 itemcount = spellInfo->ReagentCount[i];

                    if (!caster->HasItemCount(itemid, itemcount))
                    {
                        missingItem = itemid;
                        break;
                    }
                }

                data << uint32(missingItem);  // first missing item
            }
            break;
        }
        // TODO: SPELL_FAILED_NOT_STANDING
        default:
            break;
    }
}

void Spell::SendCastResult(Player* caster, SpellInfo const* spellInfo, uint8 castCount, SpellCastResult result, SpellCustomErrors customError /*= SPELL_CUSTOM_ERROR_NONE*/, uint32* param1 /*= nullptr*/, uint32* param2 /*= nullptr*/)
{
    if (result == SPELL_CAST_OK)
        return;

    WorldPacket data(SMSG_CAST_FAILED, 1 + 4 + 1);
    WriteCastResultInfo(data, caster, spellInfo, castCount, result, customError, param1, param2);

    caster->SendDirectMessage(&data);
}

void Spell::SendCastResult(SpellCastResult result, uint32* param1 /*= nullptr*/, uint32* param2 /*= nullptr*/) const
{
    if (result == SPELL_CAST_OK)
        return;

    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    if (m_caster->ToPlayer()->IsLoading())  // don't send cast results at loading time
        return;

    SendCastResult(m_caster->ToPlayer(), m_spellInfo, m_cast_count, result, m_customError, param1, param2);
}

void Spell::SendPetCastResult(SpellCastResult result)
{
    if (result == SPELL_CAST_OK)
        return;

    Unit* owner = m_caster->GetCharmerOrOwner();
    if (!owner)
        return;

    Player* player = owner->ToPlayer();
    if (!player)
        return;

    WorldPacket data(SMSG_PET_CAST_FAILED, 1 + 4 + 1);
    WriteCastResultInfo(data, player, m_spellInfo, m_cast_count, result, m_customError);

    player->SendDirectMessage(&data);
}


void Spell::SendMountResult(MountResult result)
{
    if (result == MountResult::Ok)
        return;

    if (!m_caster->IsPlayer())
        return;

    Player* caster = m_caster->ToPlayer();
    if (caster->IsLoading())  // don't send mount results at loading time
        return;

    WorldPackets::Spells::MountResult packet;
    packet.Result = AsUnderlyingType(result);
    caster->SendDirectMessage(packet.Write());
}

void Spell::SendSpellStart()
{
    if (!IsNeedSendToClient())
        return;

    //TC_LOG_DEBUG("spells", "Sending SMSG_SPELL_START id=%u", m_spellInfo->Id);

    uint32 castFlags = CAST_FLAG_HAS_TRAJECTORY;
    uint32 schoolImmunityMask = 0;
    uint32 mechanicImmunityMask = 0;

    if (Unit* unitCaster = m_caster->ToUnit())
    {
        schoolImmunityMask = m_casttime != 0 ? unitCaster->GetSchoolImmunityMask() : 0;
        mechanicImmunityMask = m_casttime != 0 ? m_spellInfo->GetMechanicImmunityMask(unitCaster) : 0;
    }

    if (schoolImmunityMask || mechanicImmunityMask)
        castFlags |= CAST_FLAG_IMMUNITY;

    if (((IsTriggered() && !m_spellInfo->IsAutoRepeatRangedSpell()) || m_triggeredByAuraSpell) && !m_cast_count)
        castFlags |= CAST_FLAG_PENDING;

    if (m_spellInfo->HasAttribute(SPELL_ATTR0_USES_RANGED_SLOT))
        castFlags |= CAST_FLAG_PROJECTILE;

    if ((m_caster->GetTypeId() == TYPEID_PLAYER ||
        (m_caster->GetTypeId() == TYPEID_UNIT && m_caster->ToCreature()->IsPet()))
         && m_spellInfo->PowerType != POWER_HEALTH)
        castFlags |= CAST_FLAG_POWER_LEFT_SELF;

    if (m_spellInfo->RuneCostID && m_spellInfo->PowerType == POWER_RUNE)
        castFlags |= CAST_FLAG_NO_GCD; // not needed, but Blizzard sends it

    if (m_spellInfo->HasAttribute(SPELL_ATTR8_HEAL_PREDICTION))
        if (m_casttime || m_spellInfo->HasAura(SPELL_AURA_PERIODIC_HEAL))
            castFlags |= CAST_FLAG_HEAL_PREDICTION;

    WorldPackets::Spells::SpellStart packet;
    WorldPackets::Spells::SpellCastData& castData = packet.Cast;

    if (m_CastItem)
        castData.CasterGUID = m_CastItem->GetGUID();
    else
        castData.CasterGUID = m_caster->GetGUID();

    castData.CasterUnit = m_caster->GetGUID();
    castData.CastID = m_cast_count;
    castData.SpellID = m_spellInfo->Id;
    castData.CastFlags = castFlags;
    castData.CastFlagsEx = m_castFlagsEx;
    castData.CastTime = m_casttime;

    m_targets.Write(castData.Target);

    if (castFlags & CAST_FLAG_POWER_LEFT_SELF)
        castData.RemainingPower = ASSERT_NOTNULL(m_caster->ToUnit())->GetPower(Powers(m_spellInfo->PowerType));

    if (castFlags & CAST_FLAG_RUNE_LIST)                   // rune cooldowns list
    {
        castData.RemainingRunes.emplace();

        //TODO: There is a crash caused by a spell with CAST_FLAG_RUNE_LIST casted by a creature
        //The creature is the mover of a player, so HandleCastSpellOpcode uses it as the caster
        if (Player* player = m_caster->ToPlayer())
        {
            castData.RemainingRunes->Start = m_runesState; // runes state before
            castData.RemainingRunes->Count = player->GetRunesState(); // runes state after
            for (uint8 i = 0; i < MAX_RUNES; ++i)
            {
                // float casts ensure the division is performed on floats as we need float result
                float baseCd = float(uint32(RUNE_BASE_COOLDOWN));
                castData.RemainingRunes->Cooldowns.push_back((baseCd - float(player->GetRuneCooldown(i))) / baseCd * 255); // rune cooldown passed
            }
        }
        else
        {
            castData.RemainingRunes->Start = 0;
            castData.RemainingRunes->Count = 0;
            for (uint8 i = 0; i < MAX_RUNES; ++i)
                castData.RemainingRunes->Cooldowns.push_back(0);
        }
    }


    if (castFlags & CAST_FLAG_PROJECTILE)
    {
        castData.Ammo.emplace();
        UpdateSpellCastDataAmmo(*castData.Ammo);
    }

    if (castFlags & CAST_FLAG_IMMUNITY)
    {
        castData.Immunities.emplace();
        castData.Immunities->School = schoolImmunityMask;
        castData.Immunities->Value = mechanicImmunityMask;
    }

    if (castFlags & CAST_FLAG_HEAL_PREDICTION)
        UpdateSpellHealPrediction(castData.Predict.emplace());

    m_caster->SendMessageToSet(packet.Write(), true);
}

void Spell::SendSpellGo()
{
    // not send invisible spell casting
    if (!IsNeedSendToClient())
        return;

    //TC_LOG_DEBUG("spells", "Sending SMSG_SPELL_GO id=%u", m_spellInfo->Id);

    uint32 castFlags = CAST_FLAG_UNKNOWN_9;


    if (Unit* unitCaster = m_caster->ToUnit())
    {
        uint32 schoolImmunityMask = m_casttime != 0 ? unitCaster->GetSchoolImmunityMask() : 0;
        uint32 mechanicImmunityMask = m_casttime != 0 ? m_spellInfo->GetMechanicImmunityMask(unitCaster) : 0;
        if (schoolImmunityMask || mechanicImmunityMask)
            castFlags |= CAST_FLAG_IMMUNITY;
    }

    // triggered spells with spell visual != 0
    if (((IsTriggered() && !m_spellInfo->IsAutoRepeatRangedSpell()) || m_triggeredByAuraSpell) && !m_cast_count)
        castFlags |= CAST_FLAG_PENDING;

    if (m_spellInfo->HasAttribute(SPELL_ATTR0_USES_RANGED_SLOT))
        castFlags |= CAST_FLAG_PROJECTILE;                        // arrows/bullets visual

    if ((m_caster->GetTypeId() == TYPEID_PLAYER ||
        (m_caster->GetTypeId() == TYPEID_UNIT && m_caster->ToCreature()->IsPet()))
        && m_spellInfo->PowerType != POWER_HEALTH)
        castFlags |= CAST_FLAG_POWER_LEFT_SELF;

    if ((m_caster->GetTypeId() == TYPEID_PLAYER)
        && (m_caster->ToPlayer()->getClass() == CLASS_DEATH_KNIGHT)
        && m_spellInfo->RuneCostID
        && m_spellInfo->PowerType == POWER_RUNE
        && !(_triggeredCastFlags & TRIGGERED_IGNORE_POWER_AND_REAGENT_COST))
    {
        castFlags |= CAST_FLAG_NO_GCD;                       // not needed, but Blizzard sends it
        castFlags |= CAST_FLAG_RUNE_LIST;                    // rune cooldowns list
    }

    if (m_spellInfo->HasEffect(SPELL_EFFECT_ACTIVATE_RUNE))
        castFlags |= CAST_FLAG_RUNE_LIST;                    // rune cooldowns list

    if (m_targets.HasTraj())
        castFlags |= CAST_FLAG_ADJUST_MISSILE;

    if (!m_spellInfo->StartRecoveryTime)
        castFlags |= CAST_FLAG_NO_GCD;

    WorldPackets::Spells::SpellGo packet;
    WorldPackets::Spells::SpellCastData& castData = packet.Cast;

    if (m_CastItem)
        castData.CasterGUID = m_CastItem->GetGUID();
    else
        castData.CasterGUID = m_caster->GetGUID();

    castData.CasterUnit = m_caster->GetGUID();
    castData.CastID = m_cast_count;
    castData.SpellID = m_spellInfo->Id;
    castData.CastFlags = castFlags;
    castData.CastFlagsEx = m_castFlagsEx;
    castData.CastTime = GameTime::GetGameTimeMS();

    castData.HitInfo.emplace();
    UpdateSpellCastDataTargets(*castData.HitInfo);
    m_targets.Write(castData.Target);

    if (castFlags & CAST_FLAG_PROJECTILE)
    {
        castData.Ammo.emplace();
        UpdateSpellCastDataAmmo(*castData.Ammo);
    }

    if (castFlags & CAST_FLAG_POWER_LEFT_SELF)
        castData.RemainingPower = ASSERT_NOTNULL(m_caster->ToUnit())->GetPower((Powers)m_spellInfo->PowerType);

    if (castFlags & CAST_FLAG_RUNE_LIST)                   // rune cooldowns list
    {
        castData.RemainingRunes.emplace();

        /// @todo There is a crash caused by a spell with CAST_FLAG_RUNE_LIST cast by a creature
        //The creature is the mover of a player, so HandleCastSpellOpcode uses it as the caster
        if (Player* player = m_caster->ToPlayer())
        {
            castData.RemainingRunes->Start = m_runesState; // runes state before
            castData.RemainingRunes->Count = player->GetRunesState(); // runes state after
            for (uint8 i = 0; i < MAX_RUNES; ++i)
            {
                // float casts ensure the division is performed on floats as we need float result
                float baseCd = float(uint32(RUNE_BASE_COOLDOWN));
                castData.RemainingRunes->Cooldowns.push_back((baseCd - float(player->GetRuneCooldown(i))) / baseCd * 255); // rune cooldown passed
            }
        }
        else
        {
            castData.RemainingRunes->Start = 0;
            castData.RemainingRunes->Count = 0;
            for (uint8 i = 0; i < MAX_RUNES; ++i)
                castData.RemainingRunes->Cooldowns.push_back(0);
        }
    }

    if (castFlags & CAST_FLAG_ADJUST_MISSILE)
    {
        castData.MissileTrajectory.emplace();
        castData.MissileTrajectory->TravelTime = m_delayMoment;
        castData.MissileTrajectory->Pitch = m_targets.GetElevation();
    }

    if (castFlags & CAST_FLAG_VISUAL_CHAIN)
    {
        castData.ProjectileVisuals.emplace();
        /*
        castData.ProjectileVisuals->Id[0] = 0;
        castData.ProjectileVisuals->Id[1] = 0;
        */
    }

    if (castData.Target.Flags & TARGET_FLAG_DEST_LOCATION)
        castData.DestLocSpellCastIndex = 0;

    /*
    if (castData.Target.Flags & TARGET_FLAG_EXTRA_TARGETS)
    {
         data << uint32(0); // Extra targets count
        for (uint8 i = 0; i < count; ++i)
        {
            data << float(0);   // Target Position X
            data << float(0);   // Target Position Y
            data << float(0);   // Target Position Z
            data << uint64(0);  // Target Guid
        }
    }
    */

    m_caster->SendMessageToSet(packet.Write(), true);
}

/// Writes miss and hit targets for a SMSG_SPELL_GO packet
void Spell::UpdateSpellCastDataTargets(WorldPackets::Spells::SpellHitInfo& data)
{
    // This function also fill data for channeled spells:
    // m_needAliveTargetMask req for stop channeling if one target die
    for (TargetInfo& targetInfo : m_UniqueTargetInfo)
    {
        if (targetInfo.EffectMask == 0) // No effect apply - all immune add state
            // possibly SPELL_MISS_IMMUNE2 for this??
            targetInfo.MissCondition = SPELL_MISS_IMMUNE2;

        if (targetInfo.MissCondition == SPELL_MISS_NONE || (targetInfo.MissCondition == SPELL_MISS_BLOCK && !m_spellInfo->HasAttribute(SPELL_ATTR3_COMPLETELY_BLOCKED))) // hits
        {
            data.HitTargets.push_back(targetInfo.TargetGUID);
            m_channelTargetEffectMask |= targetInfo.EffectMask;
        }
        else
        {
            // Don't consider blocked ranged attacks as miss
            if (targetInfo.MissCondition == SPELL_MISS_BLOCK && !m_spellInfo->HasAttribute(SPELL_ATTR3_COMPLETELY_BLOCKED))
                continue;

            data.MissStatus.emplace_back(targetInfo.TargetGUID, targetInfo.MissCondition, targetInfo.ReflectResult);
        }
    }

    for (GOTargetInfo const& targetInfo : m_UniqueGOTargetInfo)
        data.HitTargets.push_back(targetInfo.TargetGUID); // Always hits

    for (CorpseTargetInfo const& targetInfo : m_UniqueCorpseTargetInfo)
        data.HitTargets.push_back(targetInfo.TargetGUID); // Always hits

    // Reset m_needAliveTargetMask for non channeled spell
    if (!m_spellInfo->IsChanneled())
        m_channelTargetEffectMask = 0;
}

void Spell::UpdateSpellCastDataAmmo(WorldPackets::Spells::SpellAmmo& ammo)
{
    uint32 ammoInventoryType = 0;
    uint32 ammoDisplayID = 0;

    if (Player const* playerCaster = m_caster->ToPlayer())
    {
        Item* pItem = m_caster->ToPlayer()->GetWeaponForAttack(RANGED_ATTACK);
        if (pItem)
        {
            ammoInventoryType = pItem->GetTemplate()->GetInventoryType();
            if (ammoInventoryType == INVTYPE_THROWN)
                ammoDisplayID = pItem->GetTemplate()->GetDisplayID();
            else if (playerCaster->HasAura(46699))      // Requires No Ammo
            {
                ammoDisplayID = 5996;                   // normal arrow
                ammoInventoryType = INVTYPE_AMMO;
            }
        }
    }
    else if (Unit const* unitCaster = m_caster->ToUnit())
    {
        for (uint8 i = BASE_ATTACK; i < MAX_ATTACK; ++i)
        {
            if (uint32 item_id = unitCaster->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + i))
            {
                if (ItemEntry const* itemEntry = sItemStore.LookupEntry(item_id))
                {
                    if (itemEntry->ClassID == ITEM_CLASS_WEAPON)
                    {
                        switch (itemEntry->SubclassID)
                        {
                            case ITEM_SUBCLASS_WEAPON_THROWN:
                                ammoDisplayID = itemEntry->DisplayInfoID;
                                ammoInventoryType = itemEntry->InventoryType;
                                break;
                            case ITEM_SUBCLASS_WEAPON_BOW:
                            case ITEM_SUBCLASS_WEAPON_CROSSBOW:
                                ammoDisplayID = 5996;       // is this need fixing?
                                ammoInventoryType = INVTYPE_AMMO;
                                break;
                            case ITEM_SUBCLASS_WEAPON_GUN:
                                ammoDisplayID = 5998;       // is this need fixing?
                                ammoInventoryType = INVTYPE_AMMO;
                                break;
                        }

                        if (ammoDisplayID)
                            break;
                    }
                }
            }
        }
    }

    ammo.DisplayID = ammoDisplayID;
    ammo.InventoryType = ammoInventoryType;
}

void Spell::UpdateSpellHealPrediction(WorldPackets::Spells::SpellHealPrediction& predict)
{
    Unit* target = m_targets.GetUnitTarget() ? m_targets.GetUnitTarget() : m_caster->ToUnit();
    if (!target)
        return;

    predict.Type = 0;

    /*
    * @todo: implement
    if (AuraEffect const* beaconOfLightEffect = m_caster->GetDummyAuraEffect(SPELLFAMILY_PALADIN, 3032, EFFECT_0))
    {
        if (beaconOfLightEffect->GetCasterGUID() == m_caster->GetGUID())
        {
            predict.Type = 2;
            predict.BeaconGUID = beaconOfLightEffect->GetBase()->GetUnitOwner()->GetGUID();
        }
    }
    */

    if (Unit* unitCaster = m_caster->ToUnit())
    {
        for (uint8 effIndex = 0; effIndex < MAX_SPELL_EFFECTS; ++effIndex)
        {
            SpellEffectInfo const& effect = m_spellInfo->Effects[effIndex];
            if (!effect.IsEffect())
                continue;

            switch (effect.Effect)
            {
                case SPELL_EFFECT_HEAL:
                case SPELL_EFFECT_HEAL_PCT:
                    predict.Points += unitCaster->SpellHealingBonusDone(target, m_spellInfo, effect.CalcValue(unitCaster, nullptr, target), HEAL, effIndex);
                    break;
                case SPELL_EFFECT_APPLY_AURA:
                {
                    switch (effect.ApplyAuraName)
                    {
                        case SPELL_AURA_PERIODIC_HEAL:
                            predict.Points += unitCaster->SpellHealingBonusDone(target, m_spellInfo, effect.CalcValue(unitCaster, nullptr, target), HEAL, effIndex) * m_spellInfo->GetMaxTicks();
                            break;
                        case SPELL_AURA_PERIODIC_TRIGGER_SPELL:
                            if (SpellInfo const* spell = sSpellMgr->GetSpellInfo(effect.TriggerSpell))
                                for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                                    if (spell->Effects[i].Effect == SPELL_EFFECT_HEAL || spell->Effects[i].Effect == SPELL_EFFECT_HEAL_PCT)
                                        predict.Points += unitCaster->SpellHealingBonusDone(target, spell, spell->Effects[i].CalcValue(unitCaster, nullptr, target), HEAL, i) * m_spellInfo->GetMaxTicks();
                            break;
                        default:
                            break;
                    }
                    break;
                }
                default:
                    break;
            }
        }
    }
}

void Spell::SendLogExecute()
{
    WorldPacket data(SMSG_SPELLLOGEXECUTE, (8+4+4+4+4+8));

    data << m_caster->GetPackGUID();

    data << uint32(m_spellInfo->Id);

    uint8 effCount = 0;
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        if (m_effectExecuteData[i])
            ++effCount;
    }

    if (!effCount)
        return;

    data << uint32(effCount);
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        if (!m_effectExecuteData[i])
            continue;

        data << uint32(m_spellInfo->Effects[i].Effect);             // spell effect

        data.append(*m_effectExecuteData[i]);

        delete m_effectExecuteData[i];
        m_effectExecuteData[i] = nullptr;
    }
    m_caster->SendMessageToSet(&data, true);
}

void Spell::ExecuteLogEffectTakeTargetPower(uint8 effIndex, Unit* target, uint32 powerType, uint32 powerTaken, float gainMultiplier)
{
    InitEffectExecuteData(effIndex);
    *m_effectExecuteData[effIndex] << target->GetPackGUID();
    *m_effectExecuteData[effIndex] << uint32(powerTaken);
    *m_effectExecuteData[effIndex] << uint32(powerType);
    *m_effectExecuteData[effIndex] << float(gainMultiplier);
}

void Spell::ExecuteLogEffectExtraAttacks(uint8 effIndex, Unit* victim, uint32 attCount)
{
    InitEffectExecuteData(effIndex);
    *m_effectExecuteData[effIndex] << victim->GetPackGUID();
    *m_effectExecuteData[effIndex] << uint32(attCount);
}

void Spell::ExecuteLogEffectInterruptCast(uint8 /*effIndex*/, Unit* victim, uint32 spellId)
{
    ObjectGuid casterGuid = m_caster->GetGUID();
    ObjectGuid targetGuid = victim->GetGUID();

    WorldPacket data(SMSG_SPELLINTERRUPTLOG, 8 + 8 + 4 + 4);
    data.WriteBit(targetGuid[4]);
    data.WriteBit(casterGuid[5]);
    data.WriteBit(casterGuid[6]);
    data.WriteBit(casterGuid[1]);
    data.WriteBit(casterGuid[3]);
    data.WriteBit(casterGuid[0]);
    data.WriteBit(targetGuid[3]);
    data.WriteBit(targetGuid[5]);
    data.WriteBit(targetGuid[1]);
    data.WriteBit(casterGuid[4]);
    data.WriteBit(casterGuid[7]);
    data.WriteBit(targetGuid[7]);
    data.WriteBit(targetGuid[6]);
    data.WriteBit(targetGuid[2]);
    data.WriteBit(casterGuid[2]);
    data.WriteBit(targetGuid[0]);

    data.WriteByteSeq(casterGuid[7]);
    data.WriteByteSeq(casterGuid[6]);
    data.WriteByteSeq(casterGuid[3]);
    data.WriteByteSeq(casterGuid[2]);
    data.WriteByteSeq(targetGuid[3]);
    data.WriteByteSeq(targetGuid[6]);
    data.WriteByteSeq(targetGuid[2]);
    data.WriteByteSeq(targetGuid[4]);
    data.WriteByteSeq(targetGuid[7]);
    data.WriteByteSeq(targetGuid[0]);
    data.WriteByteSeq(casterGuid[4]);
    data << uint32(m_spellInfo->Id);
    data.WriteByteSeq(targetGuid[1]);
    data.WriteByteSeq(casterGuid[0]);
    data.WriteByteSeq(casterGuid[5]);
    data.WriteByteSeq(casterGuid[1]);
    data << uint32(spellId);
    data.WriteByteSeq(targetGuid[5]);

    m_caster->SendMessageToSet(&data, true);
}

void Spell::ExecuteLogEffectDurabilityDamage(uint8 effIndex, Unit* victim, int32 itemId, int32 slot)
{
    InitEffectExecuteData(effIndex);
    *m_effectExecuteData[effIndex] << victim->GetPackGUID();
    *m_effectExecuteData[effIndex] << int32(itemId);
    *m_effectExecuteData[effIndex] << int32(slot);
}

void Spell::ExecuteLogEffectOpenLock(uint8 effIndex, Object* obj)
{
    InitEffectExecuteData(effIndex);
    *m_effectExecuteData[effIndex] << obj->GetPackGUID();
}

void Spell::ExecuteLogEffectCreateItem(uint8 effIndex, uint32 entry)
{
    InitEffectExecuteData(effIndex);
    *m_effectExecuteData[effIndex] << uint32(entry);
}

void Spell::ExecuteLogEffectDestroyItem(uint8 effIndex, uint32 entry)
{
    InitEffectExecuteData(effIndex);
    *m_effectExecuteData[effIndex] << uint32(entry);
}

void Spell::ExecuteLogEffectSummonObject(uint8 effIndex, WorldObject* obj)
{
    InitEffectExecuteData(effIndex);
    *m_effectExecuteData[effIndex] << obj->GetPackGUID();
}

void Spell::ExecuteLogEffectUnsummonObject(uint8 effIndex, WorldObject* obj)
{
    InitEffectExecuteData(effIndex);
    *m_effectExecuteData[effIndex] << obj->GetPackGUID();
}

void Spell::ExecuteLogEffectResurrect(uint8 effIndex, Unit* target)
{
    InitEffectExecuteData(effIndex);
    *m_effectExecuteData[effIndex] << target->GetPackGUID();
}

void Spell::SendInterrupted(uint8 result)
{
    WorldPackets::Spells::SpellFailure spellFailure;
    spellFailure.CasterUnit = m_caster->GetGUID();
    spellFailure.CastID = m_cast_count;
    spellFailure.SpellID = m_spellInfo->Id;
    spellFailure.Reason = result;
    m_caster->SendMessageToSet(spellFailure.Write(), true);

    WorldPackets::Spells::SpellFailedOther spellFailedOther;
    spellFailedOther.CasterUnit = m_caster->GetGUID();
    spellFailedOther.CastID = m_cast_count;
    spellFailedOther.SpellID = m_spellInfo->Id;
    spellFailedOther.Reason = result;
    m_caster->SendMessageToSet(spellFailedOther.Write(), true);
}

void Spell::SendChannelUpdate(uint32 time)
{
    // GameObjects don't channel
    Unit* unitCaster = m_caster->ToUnit();
    if (!unitCaster)
        return;

    if (time == 0)
    {
        unitCaster->SetChannelObjectGuid(ObjectGuid::Empty);
        unitCaster->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);
    }

    WorldPacket data(MSG_CHANNEL_UPDATE, 8+4);
    data << unitCaster->GetPackGUID();
    data << uint32(time);

    m_caster->SendMessageToSet(&data, true);
}

void Spell::SendChannelStart(uint32 duration)
{
    // GameObjects don't channel
    Unit* unitCaster = m_caster->ToUnit();
    if (!unitCaster)
        return;

    WorldPackets::Spells::ChannelStart packet;
    packet.CasterGUID = m_caster->GetGUID();
    packet.SpellID = m_spellInfo->Id;
    packet.ChannelDuration = duration;

    uint32 castFlags = CAST_FLAG_HAS_TRAJECTORY;
    uint32 schoolImmunityMask = unitCaster->GetSchoolImmunityMask();
    uint32 mechanicImmunityMask = m_spellInfo->GetMechanicImmunityMask(unitCaster);

    if (schoolImmunityMask || mechanicImmunityMask)
        castFlags |= CAST_FLAG_IMMUNITY;

    if (castFlags & CAST_FLAG_IMMUNITY)
    {
        packet.InterruptImmunities.emplace();
        packet.InterruptImmunities->SchoolImmunities = schoolImmunityMask; // CastSchoolImmunities
        packet.InterruptImmunities->Immunities = mechanicImmunityMask; // CastImmunities
    }

        m_timer = duration;

    if (!m_targets.HasDst())
    {
        uint32 channelAuraMask = 0;
        uint32 explicitTargetEffectMask = 0xFFFFFFFF;
        // if there is an explicit target, only add channel objects from effects that also hit it
        if (!m_targets.GetUnitTargetGUID().IsEmpty())
        {
            auto explicitTargetItr = std::find_if(m_UniqueTargetInfo.begin(), m_UniqueTargetInfo.end(), [&](TargetInfo const& target)
            {
                return target.TargetGUID == m_targets.GetUnitTargetGUID();
            });
            if (explicitTargetItr != m_UniqueTargetInfo.end())
                explicitTargetEffectMask = explicitTargetItr->EffectMask;
        }

        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        {
            SpellEffectInfo const& spellEffectInfo = m_spellInfo->Effects[i];
            if (spellEffectInfo.IsEffect(SPELL_EFFECT_APPLY_AURA) && (explicitTargetEffectMask & (1u << i)))
                channelAuraMask |= 1 << i;
        }

        for (TargetInfo const& target : m_UniqueTargetInfo)
        {
            if (!(target.EffectMask & channelAuraMask))
                continue;

            SpellAttr1 requiredAttribute = target.TargetGUID != unitCaster->GetGUID() ? SPELL_ATTR1_IS_CHANNELLED : SPELL_ATTR1_IS_SELF_CHANNELLED;
            if (!m_spellInfo->HasAttribute(requiredAttribute))
                continue;

            unitCaster->SetChannelObjectGuid(target.TargetGUID);
        }

        for (GOTargetInfo const& target : m_UniqueGOTargetInfo)
            if (target.EffectMask & channelAuraMask)
                unitCaster->SetChannelObjectGuid(target.TargetGUID);
    }
    else if (m_spellInfo->HasAttribute(SPELL_ATTR1_IS_SELF_CHANNELLED))
        unitCaster->SetChannelObjectGuid(unitCaster->GetGUID());


    if (m_spellInfo->HasAttribute(SPELL_ATTR8_HEAL_PREDICTION))
    {
        castFlags |= CAST_FLAG_HEAL_PREDICTION;

        WorldPackets::Spells::SpellHealPrediction predict;
        UpdateSpellHealPrediction(predict);
        packet.HealPrediction.emplace(unitCaster->GetChannelObjectGuid(), predict);
    }

    m_caster->SendMessageToSet(packet.Write(), true);
    m_caster->SetUInt32Value(UNIT_CHANNEL_SPELL, m_spellInfo->Id);

    if (Creature* creatureCaster = m_caster->ToCreature())
        if (!creatureCaster->HasSpellFocus(this))
            creatureCaster->SetSpellFocus(this, nullptr);
}

void Spell::SendResurrectRequest(Player* target)
{
    // Get creature name for resurrection. Player names are being received via ResurrectOffererGUID and send a nul-terminator only.
    std::string sentName;
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        sentName = m_caster->GetNameForLocaleIdx(target->GetSession()->GetSessionDbLocaleIndex());

    WorldPackets::Spells::ResurrectRequest resurrectRequest;
    resurrectRequest.ResurrectOffererGUID =  m_caster->GetGUID();
    resurrectRequest.Name = sentName;
    resurrectRequest.Sickness = m_caster->IsUnit() && m_caster->ToUnit()->IsSpiritHealer(); // "you'll be afflicted with resurrection sickness"
    resurrectRequest.UseTimer = !m_spellInfo->HasAttribute(SPELL_ATTR3_NO_RES_TIMER);
    resurrectRequest.SpellID = m_spellInfo->Id;
    target->SendDirectMessage(resurrectRequest.Write());
}

void Spell::TakeCastItem()
{
    if (!m_CastItem)
        return;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return;

    // not remove cast item at triggered spell (equipping, weapon damage, etc)
    if (_triggeredCastFlags & TRIGGERED_IGNORE_CAST_ITEM)
        return;

    ItemTemplate const* proto = m_CastItem->GetTemplate();

    if (!proto)
    {
        // This code is to avoid a crash
        // I'm not sure, if this is really an error, but I guess every item needs a prototype
        TC_LOG_ERROR("spells", "Cast item has no item prototype %s", m_CastItem->GetGUID().ToString().c_str());
        return;
    }

    bool expendable = false;
    bool withoutCharges = false;

    for (uint8 i = 0; i < proto->Effects.size(); ++i)
    {
        // item has limited charges
        if (proto->Effects[i].Charges)
        {
            if (proto->Effects[i].Charges < 0)
                expendable = true;

            int32 charges = m_CastItem->GetSpellCharges(i);

            // item has charges left
            if (charges)
            {
                (charges > 0) ? --charges : ++charges;  // abs(charges) less at 1 after use
                if (proto->GetMaxStackSize() == 1)
                    m_CastItem->SetSpellCharges(i, charges);
                m_CastItem->SetState(ITEM_CHANGED, player);
            }

            // all charges used
            withoutCharges = (charges == 0);
        }
    }

    if (expendable && withoutCharges)
    {
        uint32 count = 1;
        m_caster->ToPlayer()->DestroyItemCount(m_CastItem, count, true);

        // prevent crash at access to deleted m_targets.GetItemTarget
        if (m_CastItem == m_targets.GetItemTarget())
            m_targets.SetItemTarget(nullptr);

        m_CastItem = nullptr;
        m_castItemGUID.Clear();
        m_castItemEntry = 0;
    }
}

void Spell::TakePower()
{
    // GameObjects don't use power
    Unit* unitCaster = m_caster->ToUnit();
    if (!unitCaster)
        return;

    if (m_CastItem || m_triggeredByAuraSpell)
        return;

    //Don't take power if the spell is cast while .cheat power is enabled.
    if (unitCaster->GetTypeId() == TYPEID_PLAYER)
    {
        if (unitCaster->ToPlayer()->GetCommandStatus(CHEAT_POWER))
            return;
    }

    Powers powerType = Powers(m_spellInfo->PowerType);
    bool hit = true;
    if (unitCaster->GetTypeId() == TYPEID_PLAYER && m_spellInfo->HasAttribute(SPELL_ATTR1_DISCOUNT_POWER_ON_MISS))
    {
        if (ObjectGuid targetGUID = m_targets.GetUnitTargetGUID())
        {
            auto ihit = std::find_if(std::begin(m_UniqueTargetInfo), std::end(m_UniqueTargetInfo), [&](TargetInfo const& targetInfo)
            {
                return targetInfo.TargetGUID == targetGUID && targetInfo.MissCondition != SPELL_MISS_NONE;
            });
            if (ihit != std::end(m_UniqueTargetInfo))
            {
                hit = false;
                //lower spell cost on fail (by talent aura)
                if (Player* modOwner = unitCaster->GetSpellModOwner())
                    modOwner->ApplySpellMod(m_spellInfo->Id, SpellModOp::PowerCostOnMiss, m_powerCost);
            }
        }
    }

    if (powerType == POWER_RUNE && m_caster->IsPlayer())
    {
        SpellMissInfo hitResult = SPELL_MISS_NONE;
        if (ObjectGuid targetGUID = m_targets.GetUnitTargetGUID())
        {
            auto itr = std::find_if(m_UniqueTargetInfo.begin(), m_UniqueTargetInfo.end(), [&targetGUID](Spell::TargetInfo const& targetInfo)
            {
                return targetInfo.TargetGUID == targetGUID;
            });
            if (itr != m_UniqueTargetInfo.end())
                hitResult = itr->MissCondition;
        }

        TakeRunePower(hitResult);
        return;
    }

    if (!m_powerCost)
        return;

    // health as power used
    if (powerType == POWER_HEALTH)
    {
        unitCaster->ModifyHealth(-(int32)m_powerCost);
        return;
    }

    if (powerType >= MAX_POWERS)
    {
        TC_LOG_ERROR("spells", "Spell::TakePower: Unknown power type '%d'", powerType);
        return;
    }

    unitCaster->ModifyPower(powerType, -m_powerCost);
}

SpellCastResult Spell::CheckRuneCost(uint32 runeCostID) const
{
    if (m_spellInfo->PowerType != POWER_RUNE || !runeCostID)
        return SPELL_CAST_OK;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return SPELL_CAST_OK;

    if (player->getClass() != CLASS_DEATH_KNIGHT)
        return SPELL_CAST_OK;

    SpellRuneCostEntry const* src = sSpellRuneCostStore.LookupEntry(runeCostID);
    if (!src)
        return SPELL_CAST_OK;

    if (src->NoRuneCost())
        return SPELL_CAST_OK;

    int32 runeCost[NUM_RUNE_TYPES];                         // blood, frost, unholy, death

    for (uint32 i = 0; i < RUNE_DEATH; ++i)
    {
        runeCost[i] = src->RuneCost[i];
        if (Player* modOwner = m_caster->GetSpellModOwner())
            modOwner->ApplySpellMod(m_spellInfo->Id, SpellModOp::PowerCost0, runeCost[i], const_cast<Spell*>(this));
    }

    runeCost[RUNE_DEATH] = MAX_RUNES;                       // calculated later

    for (uint32 i = 0; i < MAX_RUNES; ++i)
    {
        RuneType rune = player->GetCurrentRune(i);
        if ((player->GetRuneCooldown(i) == 0) && (runeCost[rune] > 0))
            runeCost[rune]--;
    }

    for (uint32 i = 0; i < RUNE_DEATH; ++i)
        if (runeCost[i] > 0)
            runeCost[RUNE_DEATH] += runeCost[i];

    if (runeCost[RUNE_DEATH] > MAX_RUNES)
        return SPELL_FAILED_NO_POWER;                       // not sure if result code is correct

    return SPELL_CAST_OK;
}

void Spell::TakeRunePower(SpellMissInfo hitInfo)
{
    if (!m_caster->IsPlayer() || m_caster->ToPlayer()->getClass() != CLASS_DEATH_KNIGHT)
        return;

    SpellRuneCostEntry const* runeCostData = sSpellRuneCostStore.LookupEntry(m_spellInfo->RuneCostID);
    if (!runeCostData || (runeCostData->NoRuneCost() && runeCostData->NoRunicPowerGain()))
        return;

    Player* player = m_caster->ToPlayer();
    m_runesState = player->GetRunesState();                 // store previous state
    player->ClearLastUsedRuneMask();

    std::array<int32, NUM_RUNE_TYPES> runeCost = { };        // blood, frost, unholy, death

    // Apply rune cost modifiers
    for (uint8 i = 0; i < RUNE_DEATH; ++i)
    {
        runeCost[i] = runeCostData->RuneCost[i];
        if (Player* modOwner = m_caster->GetSpellModOwner())
            modOwner->ApplySpellMod(m_spellInfo->Id, SpellModOp::PowerCost0, runeCost[i], const_cast<Spell*>(this));
    }

    bool consumeRunes = false;
    for (uint8 i = 0; i < RUNE_DEATH; ++i)
        if (runeCost[i] != 0)
            consumeRunes = true;

    // If the spell does not require any rune because of power cost spell mods, the Death Knight wont gain any Runic Power (Freezing Fog for example)
    if (!consumeRunes && !runeCostData->NoRuneCost())
        return;

    consumeRunes = hitInfo == SPELL_MISS_NONE || hitInfo == SPELL_MISS_MISS;
    // Death Strike is special - it consumes runes on dodge and parry as well, because the healing component still goes through.
    // There is no flag to control this and it's probably tied to how Blizzard applies spell effects and auras, which we KNOW we do wrong.
    if (m_spellInfo->Id == 49998)
        consumeRunes |= hitInfo == SPELL_MISS_DODGE || hitInfo == SPELL_MISS_PARRY;

    // Let's say we use a skill that requires a Frost rune. This is the order:
    // - Frost rune
    // - Death rune, originally a Frost rune
    // - Death rune, any kind
    runeCost[RUNE_DEATH] = 0;                               // calculated later

    for (uint32 i = 0; i < MAX_RUNES; ++i)
    {
        RuneType rune = player->GetCurrentRune(i);
        if (!player->GetRuneCooldown(i) && runeCost[rune] > 0)
        {
            player->SetRuneCooldown(i, consumeRunes ? uint32(RUNE_BASE_COOLDOWN) : uint32(RUNE_MISS_COOLDOWN));
            player->SetLastUsedRune(rune);
            player->SetLastUsedRuneIndex(i);
            --runeCost[rune];
        }
    }

    // Find a Death rune where the base rune matches the one we need
    runeCost[RUNE_DEATH] = runeCost[RUNE_BLOOD] + runeCost[RUNE_UNHOLY] + runeCost[RUNE_FROST];

    if (runeCost[RUNE_DEATH] > 0)
    {
        for (uint8 i = 0; i < MAX_RUNES; ++i)
        {
            RuneType rune = player->GetCurrentRune(i);
            if (!player->GetRuneCooldown(i) && rune == RUNE_DEATH)
            {
                player->SetRuneCooldown(i, consumeRunes ? uint32(RUNE_BASE_COOLDOWN) : uint32(RUNE_MISS_COOLDOWN));
                player->SetLastUsedRune(rune);
                player->SetLastUsedRuneIndex(i);
                runeCost[rune]--;

                // keep Death Rune type if missed
                if (consumeRunes)
                    player->RestoreBaseRune(i);

                if (runeCost[RUNE_DEATH] == 0)
                    break;
            }
        }
    }

    // If the spell has consumed runes, runic power will be generated
    if (consumeRunes)
    {
        if (int32 runicPowerGain = runeCostData->RunicPower * sWorld->getRate(RATE_POWER_RUNICPOWER_INCOME))
        {
            Unit::AuraEffectList const& bonusPct = player->GetAuraEffectsByType(SPELL_AURA_MOD_RUNE_REGEN_SPEED);
            for (auto i = bonusPct.begin(); i != bonusPct.end(); ++i)
            {
                // Improved Frost Presence
                if ((*i)->GetId() == 63621)
                {
                    // Apply bonus when in Unholy or Blood Presence
                    if (player->HasAura(48265) || player->HasAura(48263))
                        AddPct(runicPowerGain, (*i)->GetAmount());
                    continue;
                }
                else
                    AddPct(runicPowerGain, (*i)->GetAmount());
            }

            // Apply runic power gain modifiers
            if (Player* modOwner = m_caster->GetSpellModOwner())
                modOwner->ApplySpellMod(m_spellInfo->Id, SpellModOp::PowerCost0, runicPowerGain, const_cast<Spell*>(this));

            player->ModifyPower(POWER_RUNIC_POWER, std::max(0, runicPowerGain));
        }
    }
}

void Spell::TakeReagents()
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    ItemTemplate const* castItemTemplate = m_CastItem ? m_CastItem->GetTemplate() : nullptr;

    // do not take reagents for these item casts
    if (castItemTemplate && castItemTemplate->GetFlags() & ITEM_FLAG_NO_REAGENT_COST)
        return;

    Player* p_caster = m_caster->ToPlayer();
    if (p_caster->CanNoReagentCast(m_spellInfo))
        return;

    for (uint32 x = 0; x < MAX_SPELL_REAGENTS; ++x)
    {
        if (m_spellInfo->Reagent[x] <= 0)
            continue;

        uint32 itemid = m_spellInfo->Reagent[x];
        uint32 itemcount = m_spellInfo->ReagentCount[x];

        // if CastItem is also spell reagent
        if (castItemTemplate && castItemTemplate->GetId() == itemid)
        {
            for (uint8 s = 0; s < castItemTemplate->Effects.size(); ++s)
            {
                // CastItem will be used up and does not count as reagent
                int32 charges = m_CastItem->GetSpellCharges(s);
                if (castItemTemplate->Effects[s].Charges < 0 && abs(charges) < 2)
                {
                    ++itemcount;
                    break;
                }
            }

            m_CastItem = nullptr;
            m_castItemGUID.Clear();
            m_castItemEntry = 0;
        }

        // if GetItemTarget is also spell reagent
        if (m_targets.GetItemTargetEntry() == itemid)
            m_targets.SetItemTarget(nullptr);

        p_caster->DestroyItemCount(itemid, itemcount, true);
    }
}

void Spell::HandleThreatSpells()
{
    // wild GameObject spells don't cause threat
    Unit* unitCaster = (m_originalCaster ? m_originalCaster : m_caster->ToUnit());
    if (!unitCaster)
        return;

    if (m_UniqueTargetInfo.empty())
        return;

    if (!m_spellInfo->CausesInitialThreat())
        return;

    float threat = 0.0f;
    if (SpellThreatEntry const* threatEntry = sSpellMgr->GetSpellThreatEntry(m_spellInfo->Id))
    {
        if (threatEntry->apPctMod != 0.0f)
            threat += threatEntry->apPctMod * unitCaster->GetTotalAttackPowerValue(BASE_ATTACK);

        threat += threatEntry->flatMod;
    }
    else if (!m_spellInfo->HasAttribute(SPELL_ATTR0_CU_NO_INITIAL_THREAT))
        threat += m_spellInfo->SpellLevel;

    // past this point only multiplicative effects occur
    if (threat == 0.0f)
        return;

    // since 2.0.1 threat from positive effects also is distributed among all targets, so the overall caused threat is at most the defined bonus
    threat /= m_UniqueTargetInfo.size();

    for (auto ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
    {
        float threatToAdd = threat;
        if (ihit->MissCondition != SPELL_MISS_NONE)
            threatToAdd = 0.0f;

        Unit* target = ObjectAccessor::GetUnit(*unitCaster, ihit->TargetGUID);
        if (!target)
            continue;

        // positive spells distribute threat among all units that are in combat with target, like healing
        if (IsPositive())
            target->GetThreatManager().ForwardThreatForAssistingMe(unitCaster, threatToAdd, m_spellInfo);
        // for negative spells threat gets distributed among affected targets
        else
        {
            if (!target->CanHaveThreatList())
                continue;

            target->GetThreatManager().AddThreat(unitCaster, threatToAdd, m_spellInfo, true);
        }
    }
    TC_LOG_DEBUG("spells", "Spell %u, added an additional %f threat for %s %u target(s)", m_spellInfo->Id, threat, IsPositive() ? "assisting" : "harming", uint32(m_UniqueTargetInfo.size()));
}

void Spell::HandleHolyPower(Player* caster)
{
    if (!caster)
        return;

    bool hit = true;
    Player* modOwner = caster->GetSpellModOwner();

    m_powerCost = caster->GetPower(POWER_HOLY_POWER); // Always use all the holy power we have

    if (!m_powerCost || !modOwner)
        return;

    if (ObjectGuid targetGUID = m_targets.GetUnitTargetGUID())
    {
        auto ihit = std::find_if(std::begin(m_UniqueTargetInfo), std::end(m_UniqueTargetInfo), [&](TargetInfo const& targetInfo) { return targetInfo.TargetGUID == targetGUID && targetInfo.MissCondition != SPELL_MISS_NONE && targetInfo.MissCondition != SPELL_MISS_MISS; });
        if (ihit != std::end(m_UniqueTargetInfo))
            hit = false;
    }

    // The spell did hit the target, apply aura cost mods if there are any.
    if (hit)
    {
        modOwner->ApplySpellMod(m_spellInfo->Id, SpellModOp::PowerCost0, m_powerCost, this);
        caster->ModifyPower(POWER_HOLY_POWER, -m_powerCost);
    }
}

void Spell::HandleEffects(Unit* pUnitTarget, Item* pItemTarget, GameObject* pGoTarget, Corpse* pCorpseTarget, uint32 i, SpellEffectHandleMode mode)
{
    effectHandleMode = mode;
    unitTarget = pUnitTarget;
    itemTarget = pItemTarget;
    gameObjTarget = pGoTarget;
    corpseTarget = pCorpseTarget;
    destTarget = &m_destTargets[i]._position;
    unitCaster = m_originalCaster ? m_originalCaster : m_caster->ToUnit();

    uint8 effect = m_spellInfo->Effects[i].Effect;

    TC_LOG_DEBUG("spells", "Spell: %u Effect : %u", m_spellInfo->Id, effect);

    damage = CalculateDamage(i, unitTarget);

    SpellEffIndex effIndex = static_cast<SpellEffIndex>(i);
    bool preventDefault = CallScriptEffectHandlers(effIndex, mode);

    if (!preventDefault)
        (this->*SpellEffectHandlers[effect])(effIndex);
}

/*static*/ Spell const* Spell::ExtractSpellFromEvent(BasicEvent* event)
{
    if (SpellEvent* spellEvent = dynamic_cast<SpellEvent*>(event))
        return spellEvent->GetSpell();

    return nullptr;
}

SpellCastResult Spell::CheckCast(bool strict, uint32* param1 /*= nullptr*/, uint32* param2 /*= nullptr*/, MountResult* mountResult /*= nullptr*/)
{
    // check death state
    if (m_caster->ToUnit() && !m_caster->ToUnit()->IsAlive() && !m_spellInfo->IsPassive() && !(m_spellInfo->HasAttribute(SPELL_ATTR0_ALLOW_CAST_WHILE_DEAD) || (IsTriggered() && !m_triggeredByAuraSpell)))
        return SPELL_FAILED_CASTER_DEAD;

    // Prevent cheating in case the player has an immunity effect and tries to interact with a non-allowed gameobject. The error message is handled by the client so we don't report anything here
    if (m_caster->ToPlayer() && m_targets.GetGOTarget())
    {
        if (m_targets.GetGOTarget()->GetGOInfo()->CannotBeUsedUnderImmunity() && m_caster->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE))
            return SPELL_FAILED_DONT_REPORT;
    }

    // check cooldowns to prevent cheating
    if (!m_spellInfo->IsPassive())
    {
        if (Player const* playerCaster = m_caster->ToPlayer())
        {
            //can cast triggered (by aura only?) spells while have this flag
            if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CASTER_AURASTATE))
            {
                // These two auras check SpellFamilyName defined by dbc class data instead of current spell SpellFamilyName
                if (playerCaster->HasAuraType(SPELL_AURA_DISABLE_CASTING_EXCEPT_ABILITIES)
                    && !m_spellInfo->HasAttribute(SPELL_ATTR0_USES_RANGED_SLOT)
                    && !m_spellInfo->HasEffect(SPELL_EFFECT_ATTACK)
                    && !playerCaster->HasAuraTypeWithFamilyFlags(SPELL_AURA_DISABLE_CASTING_EXCEPT_ABILITIES, sChrClassesStore.AssertEntry(playerCaster->getClass())->SpellClassSet, m_spellInfo->SpellFamilyFlags))
                    return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

                if (playerCaster->HasAuraType(SPELL_AURA_DISABLE_ATTACKING_EXCEPT_ABILITIES))
                {
                    if (!playerCaster->HasAuraTypeWithFamilyFlags(SPELL_AURA_DISABLE_ATTACKING_EXCEPT_ABILITIES, sChrClassesStore.AssertEntry(playerCaster->getClass())->SpellClassSet, m_spellInfo->SpellFamilyFlags))
                    {
                        if (m_spellInfo->HasAttribute(SPELL_ATTR0_USES_RANGED_SLOT)
                            || m_spellInfo->IsNextMeleeSwingSpell()
                            || m_spellInfo->HasAttribute(SPELL_ATTR1_INITIATES_COMBAT_ENABLES_AUTO_ATTACK)
                            || m_spellInfo->HasAttribute(SPELL_ATTR2_INITIATE_COMBAT_POST_CAST_ENABLES_AUTO_ATTACK)
                            || m_spellInfo->HasEffect(SPELL_EFFECT_ATTACK)
                            || m_spellInfo->HasEffect(SPELL_EFFECT_NORMALIZED_WEAPON_DMG)
                            || m_spellInfo->HasEffect(SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL)
                            || m_spellInfo->HasEffect(SPELL_EFFECT_WEAPON_PERCENT_DAMAGE)
                            || m_spellInfo->HasEffect(SPELL_EFFECT_WEAPON_DAMAGE))
                            return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;
                    }
                }
            }

            // check if we are using a potion in combat for the 2nd+ time. Cooldown is added only after caster gets out of combat
            if (!IsIgnoringCooldowns() && playerCaster->GetLastPotionId() && m_CastItem && (m_CastItem->IsPotion() || m_spellInfo->IsCooldownStartedOnEvent()))
                return SPELL_FAILED_NOT_READY;
        }

        if (!IsIgnoringCooldowns() && m_caster->ToUnit())
        {
            if (!m_caster->ToUnit()->GetSpellHistory()->IsReady(m_spellInfo, m_castItemEntry))
            {
                if (m_triggeredByAuraSpell)
                    return SPELL_FAILED_DONT_REPORT;
                else
                    return SPELL_FAILED_NOT_READY;
            }

            if ((IsAutoRepeat() || m_spellInfo->SpellCategoriesId == 76) && !m_caster->ToUnit()->isAttackReady(RANGED_ATTACK))
                return SPELL_FAILED_DONT_REPORT;
        }
    }

    if (m_spellInfo->HasAttribute(SPELL_ATTR7_IS_CHEAT_SPELL) && m_caster->ToUnit() && !m_caster->ToUnit()->HasFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_ALLOW_CHEAT_SPELLS))
    {
        m_customError = SPELL_CUSTOM_ERROR_GM_ONLY;
        return SPELL_FAILED_CUSTOM_ERROR;
    }

    // Check global cooldown
    if (strict && !(_triggeredCastFlags & TRIGGERED_IGNORE_GCD) && HasGlobalCooldown())
        return !m_spellInfo->HasAttribute(SPELL_ATTR0_COOLDOWN_ON_EVENT) ? SPELL_FAILED_NOT_READY : SPELL_FAILED_DONT_REPORT;

    // only triggered spells can be processed an ended battleground
    if (!IsTriggered() && m_caster->GetTypeId() == TYPEID_PLAYER)
        if (Battleground* bg = m_caster->ToPlayer()->GetBattleground())
            if (bg->GetStatus() == STATUS_WAIT_LEAVE)
                return SPELL_FAILED_DONT_REPORT;

    if (m_caster->GetTypeId() == TYPEID_PLAYER && VMAP::VMapFactory::createOrGetVMapManager()->isLineOfSightCalcEnabled())
    {
        if (m_spellInfo->HasAttribute(SPELL_ATTR0_ONLY_OUTDOORS) &&
            !m_caster->IsOutdoors())
            return SPELL_FAILED_ONLY_OUTDOORS;

        if (m_spellInfo->HasAttribute(SPELL_ATTR0_ONLY_INDOORS) &&
            !m_caster->IsOutdoors())
            return SPELL_FAILED_ONLY_INDOORS;
    }

    if (m_spellInfo->HasAttribute(SPELL_ATTR8_BATTLE_RESURRECTION) && m_caster->GetMap()->IsRaid())
        if (InstanceScript* instance = m_caster->GetInstanceScript())
            if (instance->IsEncounterInProgress())
                if (!instance->GetCombatResurrectionCharges())
                    return SPELL_FAILED_IN_COMBAT_RES_LIMIT_REACHED;

    if (Unit* unitCaster = m_caster->ToUnit())
    {
        if (m_spellInfo->HasAttribute(SPELL_ATTR5_NOT_AVAILABLE_WHILE_CHARMED) && unitCaster->IsCharmed())
            return SPELL_FAILED_CHARMED;

        // only check at first call, Stealth auras are already removed at second call
        // for now, ignore triggered spells
        if (strict && !(_triggeredCastFlags & TRIGGERED_IGNORE_SHAPESHIFT))
        {
            bool checkForm = true;
            // Ignore form req aura
            Unit::AuraEffectList const& ignore = unitCaster->GetAuraEffectsByType(SPELL_AURA_MOD_IGNORE_SHAPESHIFT);
            for (AuraEffect const* aurEff : ignore)
            {
                if (!aurEff->IsAffectingSpell(m_spellInfo))
                    continue;

                checkForm = false;
                break;
            }

            if (checkForm)
            {
                // Cannot be used in this stance/form
                SpellCastResult shapeError = m_spellInfo->CheckShapeshift(unitCaster->GetShapeshiftForm());
                if (shapeError != SPELL_CAST_OK)
                    return shapeError;

                if (m_spellInfo->HasAttribute(SPELL_ATTR0_ONLY_STEALTHED) && !(unitCaster->HasStealthAura()))
                    return SPELL_FAILED_ONLY_STEALTHED;
            }
        }

        if (!(_triggeredCastFlags & TRIGGERED_IGNORE_BLOCKED_SPELL_FAMILY))
            for (AuraEffect const* blocked : unitCaster->GetAuraEffectsByType(SPELL_AURA_BLOCK_SPELL_FAMILY))
                if (!blocked->GetMiscValue() || uint32(blocked->GetMiscValue()) == m_spellInfo->SpellFamilyName)
                    return SPELL_FAILED_SPELL_UNAVAILABLE;

        bool reqCombat = true;
        Unit::AuraEffectList const& stateAuras = unitCaster->GetAuraEffectsByType(SPELL_AURA_ABILITY_IGNORE_AURASTATE);
        for (Unit::AuraEffectList::const_iterator j = stateAuras.begin(); j != stateAuras.end(); ++j)
        {
            if ((*j)->IsAffectingSpell(m_spellInfo))
            {
                m_needComboPoints = false;
                if ((*j)->GetMiscValue() == 1)
                {
                    reqCombat = false;
                    break;
                }
            }
        }

        // caster state requirements
        // not for triggered spells (needed by execute)
        if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CASTER_AURASTATE))
        {
            if (m_spellInfo->CasterAuraState && !unitCaster->HasAuraState(AuraStateType(m_spellInfo->CasterAuraState), m_spellInfo, unitCaster))
                return SPELL_FAILED_CASTER_AURASTATE;
            if (m_spellInfo->CasterAuraStateNot && unitCaster->HasAuraState(AuraStateType(m_spellInfo->CasterAuraStateNot), m_spellInfo, unitCaster))
                return SPELL_FAILED_CASTER_AURASTATE;

            // Note: spell 62473 requres casterAuraSpell = triggering spell
            if (m_spellInfo->CasterAuraSpell && !unitCaster->HasAura(sSpellMgr->GetSpellIdForDifficulty(m_spellInfo->CasterAuraSpell, unitCaster)))
                return SPELL_FAILED_CASTER_AURASTATE;
            if (m_spellInfo->ExcludeCasterAuraSpell && unitCaster->HasAura(sSpellMgr->GetSpellIdForDifficulty(m_spellInfo->ExcludeCasterAuraSpell, unitCaster)))
                return SPELL_FAILED_CASTER_AURASTATE;

            if (reqCombat && unitCaster->IsInCombat() && !m_spellInfo->CanBeUsedInCombat())
                return SPELL_FAILED_AFFECTING_COMBAT;
        }

        // Check vehicle flags
        if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE))
        {
            SpellCastResult vehicleCheck = m_spellInfo->CheckVehicle(unitCaster);
            if (vehicleCheck != SPELL_CAST_OK)
                return vehicleCheck;
        }
    }

    // check spell cast conditions from database
    {
        ConditionSourceInfo condInfo = ConditionSourceInfo(m_caster, m_targets.GetObjectTarget());
        if (!sConditionMgr->IsObjectMeetingNotGroupedConditions(CONDITION_SOURCE_TYPE_SPELL, m_spellInfo->Id, condInfo))
        {
            // mLastFailedCondition can be nullptr if there was an error processing the condition in Condition::Meets (i.e. wrong data for ConditionTarget or others)
            if (condInfo.mLastFailedCondition && condInfo.mLastFailedCondition->ErrorType)
            {
                if (condInfo.mLastFailedCondition->ErrorType == SPELL_FAILED_CUSTOM_ERROR)
                    m_customError = SpellCustomErrors(condInfo.mLastFailedCondition->ErrorTextId);
                return SpellCastResult(condInfo.mLastFailedCondition->ErrorType);
            }

            if (_triggeredCastFlags & TRIGGERED_DONT_REPORT_CAST_ERROR)
                return SPELL_FAILED_DONT_REPORT;

            if (!condInfo.mLastFailedCondition || !condInfo.mLastFailedCondition->ConditionTarget)
                return SPELL_FAILED_CASTER_AURASTATE;
            return SPELL_FAILED_BAD_TARGETS;
        }
    }

    // Don't check explicit target for passive spells (workaround) (check should be skipped only for learn case)
    // those spells may have incorrect target entries or not filled at all (for example 15332)
    // such spells when learned are not targeting anyone using targeting system, they should apply directly to caster instead
    // also, such casts shouldn't be sent to client
    if (!(m_spellInfo->IsPassive() && (!m_targets.GetUnitTarget() || m_targets.GetUnitTarget() == m_caster)))
    {
        // Check explicit target for m_originalCaster - todo: get rid of such workarounds
        WorldObject* caster = m_caster;
        // in case of gameobjects like traps, we need the gameobject itself to check target validity
        // otherwise, if originalCaster is far away and cannot detect the target, the trap would not hit the target
        if (m_originalCaster && !caster->ToGameObject())
            caster = m_originalCaster;

        SpellCastResult castResult = m_spellInfo->CheckExplicitTarget(caster, m_targets.GetObjectTarget(), m_targets.GetItemTarget());
        if (castResult != SPELL_CAST_OK)
            return castResult;
    }

    if (Unit* target = m_targets.GetUnitTarget())
    {
        SpellCastResult castResult = m_spellInfo->CheckTarget(m_caster, target, m_caster->GetTypeId() == TYPEID_GAMEOBJECT); // skip stealth checks for GO casts
        if (castResult != SPELL_CAST_OK)
            return castResult;

        if (target != m_caster)
        {
            // Must be behind the target
            if (m_spellInfo->HasAttribute(SPELL_ATTR0_CU_REQ_CASTER_BEHIND_TARGET) && target->HasInArc(static_cast<float>(M_PI), m_caster))
                return SPELL_FAILED_NOT_BEHIND;

            // Target must be facing you
            if (m_spellInfo->HasAttribute(SPELL_ATTR0_CU_REQ_TARGET_FACING_CASTER) && !target->HasInArc(static_cast<float>(M_PI), m_caster))
                return SPELL_FAILED_NOT_INFRONT;

            // Ignore LOS for gameobjects casts
            if (m_caster->GetTypeId() != TYPEID_GAMEOBJECT)
            {
                WorldObject* losTarget = m_caster;
                if (IsTriggered() && m_triggeredByAuraSpell)
                    if (DynamicObject* dynObj = m_caster->ToUnit()->GetDynObject(m_triggeredByAuraSpell->Id))
                        losTarget = dynObj;

                if (!m_spellInfo->HasAttribute(SPELL_ATTR2_IGNORE_LINE_OF_SIGHT) && !DisableMgr::IsDisabledFor(DISABLE_TYPE_SPELL, m_spellInfo->Id, nullptr, SPELL_DISABLE_LOS) && !target->IsWithinLOSInMap(losTarget, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
                    return SPELL_FAILED_LINE_OF_SIGHT;
            }
        }
    }

    // Check for line of sight for spells with dest
    if (m_targets.HasDst())
    {
        float x, y, z;
        m_targets.GetDstPos()->GetPosition(x, y, z);

        if (!m_spellInfo->HasAttribute(SPELL_ATTR2_IGNORE_LINE_OF_SIGHT) && !DisableMgr::IsDisabledFor(DISABLE_TYPE_SPELL, m_spellInfo->Id, nullptr, SPELL_DISABLE_LOS) && !m_caster->IsWithinLOS(x, y, z, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
            return SPELL_FAILED_LINE_OF_SIGHT;
    }

    // check pet presence
    if (Unit* unitCaster = m_caster->ToUnit())
    {
        if (m_spellInfo->HasAttribute(SPELL_ATTR2_NO_ACTIVE_PETS))
            if (!unitCaster->GetPetGUID().IsEmpty())
                return SPELL_FAILED_ALREADY_HAVE_PET;

        for (uint8 j = 0; j < MAX_SPELL_EFFECTS; ++j)
        {
            if (m_spellInfo->Effects[j].TargetA.GetTarget() == TARGET_UNIT_PET)
            {
                if (!unitCaster->GetGuardianPet())
                {
                    if (m_triggeredByAuraSpell)              // not report pet not existence for triggered spells
                        return SPELL_FAILED_DONT_REPORT;
                    else
                        return SPELL_FAILED_NO_PET;
                }
                break;
            }
        }
    }

    // Spell cast only in battleground
    if (m_spellInfo->HasAttribute(SPELL_ATTR3_ONLY_BATTLEGROUNDS))
        if (!m_caster->GetMap()->IsBattleground())
            return SPELL_FAILED_ONLY_BATTLEGROUNDS;

    // do not allow spells to be cast in arenas or rated battlegrounds
    if (Player* player = m_caster->ToPlayer())
        if (player->InArena()/* || player->InRatedBattleGround() NYI*/)
        {
            SpellCastResult castResult = CheckArenaAndRatedBattlegroundCastRules();
            if (castResult != SPELL_CAST_OK)
                return castResult;
        }

    // zone check
    if (m_caster->GetTypeId() != TYPEID_PLAYER || !m_caster->ToPlayer()->IsGameMaster())
    {
        uint32 zone, area;
        m_caster->GetZoneAndAreaId(zone, area);

        SpellCastResult locRes = m_spellInfo->CheckLocation(m_caster->GetMapId(), zone, area, m_caster->ToPlayer());
        if (locRes != SPELL_CAST_OK)
            return locRes;
    }

    // not let players cast spells at mount (and let do it to creatures)
    if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE))
    {
        if (m_caster->GetTypeId() == TYPEID_PLAYER && m_caster->ToPlayer()->IsMounted() && !m_spellInfo->IsPassive() && !m_spellInfo->HasAttribute(SPELL_ATTR0_ALLOW_WHILE_MOUNTED))
        {
            if (m_caster->ToPlayer()->IsInFlight())
                return SPELL_FAILED_NOT_ON_TAXI;
            else
                return SPELL_FAILED_NOT_MOUNTED;
        }
    }

    // check spell focus object
    if (m_spellInfo->RequiresSpellFocus)
    {
        focusObject = SearchSpellFocus();
        if (!focusObject)
            return SPELL_FAILED_REQUIRES_SPELL_FOCUS;
    }

    SpellCastResult castResult = SPELL_CAST_OK;

    // always (except passive spells) check items (only player related checks)
    if (!m_spellInfo->IsPassive())
    {
        castResult = CheckItems(param1, param2);
        if (castResult != SPELL_CAST_OK)
            return castResult;
    }

    // Triggered spells also have range check
    /// @todo determine if there is some flag to enable/disable the check
    castResult = CheckRange(strict);
    if (castResult != SPELL_CAST_OK)
        return castResult;

    if (!(_triggeredCastFlags & TRIGGERED_IGNORE_POWER_AND_REAGENT_COST))
    {
        castResult = CheckPower();
        if (castResult != SPELL_CAST_OK)
            return castResult;
    }

    if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CASTER_AURAS))
    {
        castResult = CheckCasterAuras(param1);
        if (castResult != SPELL_CAST_OK)
            return castResult;
    }

    // script hook
    castResult = CallScriptCheckCastHandlers();
    if (castResult != SPELL_CAST_OK)
        return castResult;

    uint8 approximateAuraEffectMask = 0;
    uint8 nonAuraEffectMask = 0;
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        // for effects of spells that have only one target
        switch (m_spellInfo->Effects[i].Effect)
        {
            case SPELL_EFFECT_DUMMY:
            {
                if (m_spellInfo->Id == 19938)          // Awaken Peon
                {
                    Unit* unit = m_targets.GetUnitTarget();
                    if (!unit || !unit->HasAura(17743))
                        return SPELL_FAILED_BAD_TARGETS;
                }
                else if (m_spellInfo->Id == 31789)          // Righteous Defense
                {
                    if (m_caster->GetTypeId() != TYPEID_PLAYER)
                        return SPELL_FAILED_DONT_REPORT;

                    Unit* target = m_targets.GetUnitTarget();
                    if (!target || !target->IsFriendlyTo(m_caster) || target->getAttackers().empty())
                        return SPELL_FAILED_BAD_TARGETS;

                }
                break;
            }
            case SPELL_EFFECT_LEARN_SPELL:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_BAD_TARGETS;

                if (m_spellInfo->Effects[i].TargetA.GetTarget() != TARGET_UNIT_PET)
                    break;

                Pet* pet = m_caster->ToPlayer()->GetPet();

                if (!pet)
                    return SPELL_FAILED_NO_PET;

                SpellInfo const* learn_spellproto = sSpellMgr->GetSpellInfo(m_spellInfo->Effects[i].TriggerSpell);

                if (!learn_spellproto)
                    return SPELL_FAILED_NOT_KNOWN;

                if (m_spellInfo->SpellLevel > pet->getLevel())
                    return SPELL_FAILED_LOWLEVEL;

                break;
            }
            case SPELL_EFFECT_UNLOCK_GUILD_VAULT_TAB:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_BAD_TARGETS;
                if (Guild* guild = m_caster->ToPlayer()->GetGuild())
                    if (guild->GetLeaderGUID() != m_caster->ToPlayer()->GetGUID())
                        return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;
                break;
            }
            case SPELL_EFFECT_LEARN_PET_SPELL:
            {
                // check target only for unit target case
                if (Unit* unit = m_targets.GetUnitTarget())
                {
                    if (m_caster->GetTypeId() != TYPEID_PLAYER)
                        return SPELL_FAILED_BAD_TARGETS;

                    Pet* pet = unit->ToPet();
                    if (!pet || pet->GetOwner() != m_caster)
                        return SPELL_FAILED_BAD_TARGETS;

                    SpellInfo const* learn_spellproto = sSpellMgr->GetSpellInfo(m_spellInfo->Effects[i].TriggerSpell);

                    if (!learn_spellproto)
                        return SPELL_FAILED_NOT_KNOWN;

                    if (m_spellInfo->SpellLevel > pet->getLevel())
                        return SPELL_FAILED_LOWLEVEL;
                }
                break;
            }
            case SPELL_EFFECT_APPLY_GLYPH:
            {
                uint32 glyphId = m_spellInfo->Effects[i].MiscValue;
                if (GlyphPropertiesEntry const* gp = sGlyphPropertiesStore.LookupEntry(glyphId))
                    if (m_caster->ToPlayer()->HasAura(gp->SpellID))
                        return SPELL_FAILED_UNIQUE_GLYPH;
                break;
            }
            case SPELL_EFFECT_FEED_PET:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_BAD_TARGETS;

                Item* foodItem = m_targets.GetItemTarget();
                if (!foodItem)
                    return SPELL_FAILED_BAD_TARGETS;

                Pet* pet = m_caster->ToPlayer()->GetPet();

                if (!pet)
                    return SPELL_FAILED_NO_PET;

                if (!pet->HaveInDiet(foodItem->GetTemplate()))
                    return SPELL_FAILED_WRONG_PET_FOOD;

                if (!pet->GetCurrentFoodBenefitLevel(foodItem->GetTemplate()->GetBaseItemLevel()))
                    return SPELL_FAILED_FOOD_LOWLEVEL;

                if (m_caster->ToPlayer()->IsInCombat() || pet->IsInCombat())
                    return SPELL_FAILED_AFFECTING_COMBAT;

                break;
            }
            case SPELL_EFFECT_POWER_BURN:
            case SPELL_EFFECT_POWER_DRAIN:
            {
                // Can be area effect, Check only for players and not check if target - caster (spell can have multiply drain/burn effects)
                if (m_caster->GetTypeId() == TYPEID_PLAYER)
                    if (Unit* target = m_targets.GetUnitTarget())
                        if (target != m_caster && target->GetPowerType() != Powers(m_spellInfo->Effects[i].MiscValue))
                            return SPELL_FAILED_BAD_TARGETS;
                break;
            }
            case SPELL_EFFECT_CHARGE:
            {
                Unit* unitCaster = m_caster->ToUnit();
                if (!unitCaster)
                    return SPELL_FAILED_BAD_TARGETS;

                if (m_spellInfo->SpellFamilyName == SPELLFAMILY_WARRIOR)
                {
                    // Warbringer - can't be handled in proc system - should be done before checkcast root check and charge effect process
                    if (strict && unitCaster->IsScriptOverriden(m_spellInfo, 6953))
                        unitCaster->RemoveMovementImpairingAuras(true);
                }

                if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CASTER_AURAS) && unitCaster->HasUnitState(UNIT_STATE_ROOT))
                    return SPELL_FAILED_ROOTED;

                if (GetSpellInfo()->NeedsExplicitUnitTarget())
                {
                    Unit* target = m_targets.GetUnitTarget();
                    if (!target)
                        return SPELL_FAILED_DONT_REPORT;

                    // first we must check to see if the target is in LoS. A path can usually be built but LoS matters for charge spells
                    if (!target->IsWithinLOSInMap(unitCaster)) //Do full LoS/Path check. Don't exclude m2
                        return SPELL_FAILED_LINE_OF_SIGHT;

                    float objSize = target->GetCombatReach();
                    float range = m_spellInfo->GetMaxRange(true, unitCaster, this) * 1.5f + objSize; // can't be overly strict

                    m_preGeneratedPath = Trinity::make_unique<PathGenerator>(unitCaster);
                    m_preGeneratedPath->SetPathLengthLimit(range);

                    // first try with raycast, if it fails fall back to normal path
                    bool result = m_preGeneratedPath->CalculatePath(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), false);
                    if (m_preGeneratedPath->GetPathType() & PATHFIND_SHORT)
                        return SPELL_FAILED_NOPATH;
                    else if (!result || m_preGeneratedPath->GetPathType() & (PATHFIND_NOPATH | PATHFIND_INCOMPLETE))
                        return SPELL_FAILED_NOPATH;
                    else if (m_preGeneratedPath->IsInvalidDestinationZ(target)) // Check position z, if not in a straight line
                        return SPELL_FAILED_NOPATH;

                    m_preGeneratedPath->ShortenPathUntilDist(PositionToVector3(target), objSize); // move back
                }
                break;
            }
            case SPELL_EFFECT_SKINNING:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER || !m_targets.GetUnitTarget() || m_targets.GetUnitTarget()->GetTypeId() != TYPEID_UNIT)
                    return SPELL_FAILED_BAD_TARGETS;

                if (!(m_targets.GetUnitTarget()->GetUInt32Value(UNIT_FIELD_FLAGS) & UNIT_FLAG_SKINNABLE))
                    return SPELL_FAILED_TARGET_UNSKINNABLE;

                Creature* creature = m_targets.GetUnitTarget()->ToCreature();
                if (!creature->IsCritter() && !creature->loot.isLooted())
                    return SPELL_FAILED_TARGET_NOT_LOOTED;

                uint32 skill = creature->GetCreatureTemplate()->GetRequiredLootSkill();

                int32 skillValue = m_caster->ToPlayer()->GetSkillValue(skill);
                int32 TargetLevel = m_targets.GetUnitTarget()->getLevel();
                int32 ReqValue = (skillValue < 100 ? (TargetLevel-10) * 10 : TargetLevel * 5);
                if (ReqValue > skillValue)
                    return SPELL_FAILED_LOW_CASTLEVEL;

                break;
            }
            case SPELL_EFFECT_OPEN_LOCK:
            {
                if (m_spellInfo->Effects[i].TargetA.GetTarget() != TARGET_GAMEOBJECT_TARGET &&
                    m_spellInfo->Effects[i].TargetA.GetTarget() != TARGET_GAMEOBJECT_ITEM_TARGET)
                    break;

                if (m_caster->GetTypeId() != TYPEID_PLAYER  // only players can open locks, gather etc.
                    // we need a go target in case of TARGET_GAMEOBJECT_TARGET
                    || (m_spellInfo->Effects[i].TargetA.GetTarget() == TARGET_GAMEOBJECT_TARGET && !m_targets.GetGOTarget()))
                    return SPELL_FAILED_BAD_TARGETS;

                Item* pTempItem = nullptr;
                if (m_targets.GetTargetMask() & TARGET_FLAG_TRADE_ITEM)
                {
                    if (TradeData* pTrade = m_caster->ToPlayer()->GetTradeData())
                        pTempItem = pTrade->GetTraderData()->GetItem(TradeSlots(m_targets.GetItemTargetGUID().GetRawValue()));  // at this point item target guid contains the trade slot
                }
                else if (m_targets.GetTargetMask() & TARGET_FLAG_ITEM)
                    pTempItem = m_caster->ToPlayer()->GetItemByGuid(m_targets.GetItemTargetGUID());

                // we need a go target, or an openable item target in case of TARGET_GAMEOBJECT_ITEM_TARGET
                if (m_spellInfo->Effects[i].TargetA.GetTarget() == TARGET_GAMEOBJECT_ITEM_TARGET &&
                    !m_targets.GetGOTarget() &&
                    (!pTempItem || !pTempItem->GetTemplate()->GetLockID() || !pTempItem->IsLocked()))
                    return SPELL_FAILED_BAD_TARGETS;

                if (m_spellInfo->Id != 1842 || (m_targets.GetGOTarget() &&
                    m_targets.GetGOTarget()->GetGOInfo()->type != GAMEOBJECT_TYPE_TRAP))
                    if (m_caster->ToPlayer()->InBattleground() && // In Battleground players can use only flags and banners
                        !m_caster->ToPlayer()->CanUseBattlegroundObject(m_targets.GetGOTarget()))
                        return SPELL_FAILED_TRY_AGAIN;

                // get the lock entry
                uint32 lockId = 0;
                if (GameObject* go = m_targets.GetGOTarget())
                {
                    lockId = go->GetGOInfo()->GetLockId();
                    if (!lockId)
                        return SPELL_FAILED_BAD_TARGETS;
                }
                else if (Item* itm = m_targets.GetItemTarget())
                    lockId = itm->GetTemplate()->GetLockID();

                SkillType skillId = SKILL_NONE;
                int32 reqSkillValue = 0;
                int32 skillValue = 0;

                // check lock compatibility
                SpellCastResult res = CanOpenLock(i, lockId, skillId, reqSkillValue, skillValue);
                if (res != SPELL_CAST_OK)
                    return res;

                // chance for fail at LockPicking attempt
                // second check prevent fail at rechecks
                if (skillId != SKILL_NONE && (!m_selfContainer || ((*m_selfContainer) != this)))
                {
                    bool canFailAtMax = skillId == SKILL_LOCKPICKING;

                    // chance for failure in orange lockpick
                    if ((canFailAtMax && skillValue < sWorld->GetConfigMaxSkillValue()) && reqSkillValue > irand(skillValue - 25, skillValue + 37))
                        return SPELL_FAILED_TRY_AGAIN;
                }
                break;
            }
            case SPELL_EFFECT_RESURRECT_PET:
            {
                Unit* unitCaster = m_caster->ToUnit();
                if (!unitCaster)
                    return SPELL_FAILED_BAD_TARGETS;

                Creature* pet = unitCaster->GetGuardianPet();
                if (pet && pet->IsAlive())
                    return SPELL_FAILED_ALREADY_HAVE_SUMMON;

                break;
            }
            // This is generic summon effect
            case SPELL_EFFECT_SUMMON:
            {
                Unit* unitCaster = m_caster->ToUnit();
                if (!unitCaster)
                    break;

                SummonPropertiesEntry const* SummonProperties = sSummonPropertiesStore.LookupEntry(m_spellInfo->Effects[i].MiscValueB);
                if (!SummonProperties)
                    break;
                switch (SummonProperties->Control)
                {
                    case SUMMON_CATEGORY_PET:
                        if (!m_spellInfo->HasAttribute(SPELL_ATTR1_DISMISS_PET_FIRST) && unitCaster->GetPetGUID())
                            return SPELL_FAILED_ALREADY_HAVE_SUMMON;
                        [[fallthrough]]; //  check both GetPetGUID() and GetCharmGUID for SUMMON_CATEGORY_PET*/
                    case SUMMON_CATEGORY_PUPPET:
                        if (unitCaster->GetCharmedGUID())
                            return SPELL_FAILED_ALREADY_HAVE_CHARM;
                        break;
                }
                break;
            }
            case SPELL_EFFECT_CREATE_TAMED_PET:
            {
                if (m_targets.GetUnitTarget())
                {
                    if (m_targets.GetUnitTarget()->GetTypeId() != TYPEID_PLAYER)
                        return SPELL_FAILED_BAD_TARGETS;
                    if (!m_spellInfo->HasAttribute(SPELL_ATTR1_DISMISS_PET_FIRST) && m_targets.GetUnitTarget()->GetPetGUID())
                        return SPELL_FAILED_ALREADY_HAVE_SUMMON;
                }
                break;
            }
            case SPELL_EFFECT_SUMMON_PET:
            {
                Unit* unitCaster = m_caster->ToUnit();
                if (!unitCaster)
                    return SPELL_FAILED_BAD_TARGETS;

                if (unitCaster->GetPetGUID())                  //let warlock do a replacement summon
                {
                    if (unitCaster->GetTypeId() == TYPEID_PLAYER)
                    {
                        if (strict)                         //starting cast, trigger pet stun (cast by pet so it doesn't attack player)
                            if (Pet* pet = unitCaster->ToPlayer()->GetPet())
                                pet->CastSpell(pet, 32752, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                                .SetOriginalCaster(pet->GetGUID())
                                .SetTriggeringSpell(this));
                    }
                    else if (!m_spellInfo->HasAttribute(SPELL_ATTR1_DISMISS_PET_FIRST))
                        return SPELL_FAILED_ALREADY_HAVE_SUMMON;
                }

                if (unitCaster->GetCharmedGUID())
                    return SPELL_FAILED_ALREADY_HAVE_CHARM;
                break;
            }
            case SPELL_EFFECT_SUMMON_PLAYER:
            {
                // Single target summoning case
                if (m_targets.GetOrigUnitTargetGUID().IsEmpty())
                {
                    if (!m_caster->ToPlayer()->GetTarget())
                        return SPELL_FAILED_BAD_TARGETS;

                    Player* target = ObjectAccessor::FindPlayer(m_caster->ToPlayer()->GetTarget());
                    if (!target || m_caster->ToPlayer() == target || (!target->IsInSameRaidWith(m_caster->ToPlayer()) && m_spellInfo->Id != 48955)) // refer-a-friend spell
                        return SPELL_FAILED_BAD_TARGETS;

                    if (target->HasSummonPending())
                        return SPELL_FAILED_SUMMON_PENDING;

                    // check if our map is dungeon
                    MapEntry const* map = sMapStore.LookupEntry(m_caster->GetMapId());
                    if (map->IsDungeon())
                    {
                        uint32 mapId = m_caster->GetMap()->GetId();
                        Difficulty difficulty = m_caster->GetMap()->GetDifficulty();
                        if (map->IsRaid())
                            if (InstancePlayerBind* targetBind = target->GetBoundInstance(mapId, difficulty))
                                if (InstancePlayerBind* casterBind = m_caster->ToPlayer()->GetBoundInstance(mapId, difficulty))
                                    if (targetBind->perm && targetBind->save != casterBind->save)
                                        return SPELL_FAILED_TARGET_LOCKED_TO_RAID_INSTANCE;

                        if (!target->Satisfy(sObjectMgr->GetAccessRequirement(mapId, difficulty), mapId))
                            return SPELL_FAILED_BAD_TARGETS;
                    }
                }
                break;
            }
            // RETURN HERE
            case SPELL_EFFECT_SUMMON_RAF_FRIEND:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_BAD_TARGETS;

                Player* playerCaster = m_caster->ToPlayer();
                if (!playerCaster->GetTarget())
                    return SPELL_FAILED_BAD_TARGETS;

                Player* target = playerCaster->GetSelectedPlayer();

                if (!target ||
                    !(target->GetSession()->GetRecruiterId() == playerCaster->GetSession()->GetAccountId() || target->GetSession()->GetAccountId() == playerCaster->GetSession()->GetRecruiterId()))
                    return SPELL_FAILED_BAD_TARGETS;

                break;
            }
            case SPELL_EFFECT_LEAP:
            case SPELL_EFFECT_TELEPORT_UNITS_FACE_CASTER:
            {
                //Do not allow to cast it before BG starts.
                if (m_caster->GetTypeId() == TYPEID_PLAYER)
                    if (Battleground const* bg = m_caster->ToPlayer()->GetBattleground())
                        if (bg->GetStatus() != STATUS_IN_PROGRESS)
                            return SPELL_FAILED_TRY_AGAIN;
                break;
            }
            case SPELL_EFFECT_STEAL_BENEFICIAL_BUFF:
            {
                if (m_targets.GetUnitTarget() == m_caster)
                    return SPELL_FAILED_BAD_TARGETS;
                break;
            }
            case SPELL_EFFECT_LEAP_BACK:
            {
                Unit* unitCaster = m_caster->ToUnit();
                if (!unitCaster)
                    return SPELL_FAILED_BAD_TARGETS;

                if (unitCaster->HasUnitState(UNIT_STATE_ROOT))
                {
                    if (m_caster->GetTypeId() == TYPEID_PLAYER)
                        return SPELL_FAILED_ROOTED;
                    else
                        return SPELL_FAILED_DONT_REPORT;
                }
                break;
            }
            case SPELL_EFFECT_TALENT_SPEC_SELECT:
            {
                Player* player = m_caster->ToPlayer();
                if (!player)
                    return SPELL_FAILED_TARGET_NOT_PLAYER;

                // can't change during already started arena/battleground
                if (Battleground const* bg = player->ToPlayer()->GetBattleground())
                    if (bg->GetStatus() == STATUS_IN_PROGRESS)
                        return SPELL_FAILED_NOT_IN_BATTLEGROUND;
                break;
            }
            default:
                break;
        }

        if (m_spellInfo->Effects[i].IsAura())
            approximateAuraEffectMask |= 1 << i;
        else if (m_spellInfo->Effects[i].IsEffect())
            nonAuraEffectMask |= 1 << i;
    }

    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        switch (m_spellInfo->Effects[i].ApplyAuraName)
        {
            case SPELL_AURA_MOD_POSSESS:
            case SPELL_AURA_MOD_CHARM:
            case SPELL_AURA_AOE_CHARM:
            {
                Unit* unitCaster = (m_originalCaster ? m_originalCaster : m_caster->ToUnit());
                if (!unitCaster)
                    return SPELL_FAILED_BAD_TARGETS;

                if (unitCaster->GetCharmerGUID())
                    return SPELL_FAILED_CHARMED;

                if (m_spellInfo->Effects[i].ApplyAuraName == SPELL_AURA_MOD_CHARM
                    || m_spellInfo->Effects[i].ApplyAuraName == SPELL_AURA_MOD_POSSESS)
                {
                    if (!m_spellInfo->HasAttribute(SPELL_ATTR1_DISMISS_PET_FIRST) && unitCaster->GetPetGUID())
                        return SPELL_FAILED_ALREADY_HAVE_SUMMON;

                    if (unitCaster->GetCharmedGUID())
                        return SPELL_FAILED_ALREADY_HAVE_CHARM;
                }

                if (Unit* target = m_targets.GetUnitTarget())
                {
                    if (target->GetTypeId() == TYPEID_UNIT && target->IsVehicle())
                        return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

                    if (target->IsMounted())
                        return SPELL_FAILED_CANT_BE_CHARMED;

                    if (target->GetCharmerGUID())
                        return SPELL_FAILED_CHARMED;

                    if (target->GetOwner() && target->GetOwner()->GetTypeId() == TYPEID_PLAYER)
                        return SPELL_FAILED_TARGET_IS_PLAYER_CONTROLLED;

                    int32 value = CalculateDamage(i, target);
                    if (value && int32(target->getLevel()) > value)
                        return SPELL_FAILED_HIGHLEVEL;
                }

                break;
            }
            case SPELL_AURA_MOUNTED:
            {
                Unit* unitCaster = m_caster->ToUnit();
                if (!unitCaster)
                    return SPELL_FAILED_BAD_TARGETS;

                if (unitCaster->IsInWater() && m_spellInfo->HasAura(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED))
                    return SPELL_FAILED_ONLY_ABOVEWATER;

                if (unitCaster->IsInDisallowedMountForm())
                {
                    if (mountResult)
                    {
                        *mountResult = MountResult::Shapeshifted;
                        return SPELL_FAILED_DONT_REPORT;
                    }
                    else
                        return SPELL_FAILED_NOT_SHAPESHIFT;
                }

                break;
            }
            case SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS:
            {
                if (!m_targets.GetUnitTarget())
                    return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

                // can be cast at non-friendly unit or own pet/charm
                if (m_caster->IsFriendlyTo(m_targets.GetUnitTarget()))
                    return SPELL_FAILED_TARGET_FRIENDLY;

                break;
            }
            case SPELL_AURA_FLY:
            case SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED:
            {
                // not allow cast fly spells if not have req. skills  (all spells is self target)
                // allow always ghost flight spells
                if (m_originalCaster && m_originalCaster->GetTypeId() == TYPEID_PLAYER && m_originalCaster->IsAlive())
                {
                    Battlefield* Bf = sBattlefieldMgr->GetBattlefieldToZoneId(m_originalCaster->GetMap(), m_originalCaster->GetZoneId());
                    if (AreaTableEntry const* area = sAreaTableStore.LookupEntry(m_originalCaster->GetAreaId()))
                        if (area->Flags & AREA_FLAG_NO_FLY_ZONE  || (Bf && !Bf->CanFlyIn()))
                            return (_triggeredCastFlags & TRIGGERED_DONT_REPORT_CAST_ERROR) ? SPELL_FAILED_DONT_REPORT : SPELL_FAILED_NOT_HERE;
                }
                break;
            }
            case SPELL_AURA_PERIODIC_MANA_LEECH:
            {
                if (m_spellInfo->Effects[i].IsTargetingArea())
                    break;

                //if (!m_targets.GetUnitTarget())
                //    return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

                if (m_caster->GetTypeId() != TYPEID_PLAYER || m_CastItem)
                    break;

                if (m_targets.GetUnitTarget() && m_targets.GetUnitTarget()->GetPowerType() != POWER_MANA)
                    return SPELL_FAILED_BAD_TARGETS;
                else if (!m_targets.GetUnitTarget() && m_caster->ToPlayer()->GetPowerType() != POWER_MANA)
                    return SPELL_FAILED_BAD_TARGETS;

                break;
            }
            default:
                break;
        }

        // check if target already has the same type, but more powerful aura
        if (!m_spellInfo->HasAttribute(SPELL_ATTR4_AURA_NEVER_BOUNCES)
            && (!nonAuraEffectMask || m_spellInfo->HasAttribute(SPELL_ATTR4_AURA_BOUNCE_FAILS_SPELL))
            && (approximateAuraEffectMask & (1 << i))
            && !m_spellInfo->IsTargetingArea())
            if (Unit* target = m_targets.GetUnitTarget())
                if (!target->IsHighestExclusiveAuraEffect(m_spellInfo, AuraType(m_spellInfo->Effects[i].ApplyAuraName),
                    m_spellInfo->Effects[i].CalcValue(m_caster, &m_spellValue->EffectBasePoints[i]), approximateAuraEffectMask, false))
                    return SPELL_FAILED_AURA_BOUNCED;
    }

    // check trade slot case (last, for allow catch any another cast problems)
    if (m_targets.GetTargetMask() & TARGET_FLAG_TRADE_ITEM)
    {
        if (m_CastItem)
            return SPELL_FAILED_ITEM_ENCHANT_TRADE_WINDOW;

        if (m_spellInfo->HasAttribute(SPELL_ATTR2_ENCHANT_OWN_ITEM_ONLY))
            return SPELL_FAILED_ITEM_ENCHANT_TRADE_WINDOW;

        if (m_caster->GetTypeId() != TYPEID_PLAYER)
            return SPELL_FAILED_NOT_TRADING;

        TradeData* my_trade = m_caster->ToPlayer()->GetTradeData();

        if (!my_trade)
            return SPELL_FAILED_NOT_TRADING;

        // Item target guid contains trade slot until m_targets.UpdateTradeSlotItem() is called
        TradeSlots slot = TradeSlots(m_targets.GetItemTargetGUID().GetRawValue());
        if (slot != TRADE_SLOT_NONTRADED)
            return SPELL_FAILED_BAD_TARGETS;

        if (!IsTriggered())
            if (my_trade->GetSpell())
                return SPELL_FAILED_ITEM_ALREADY_ENCHANTED;
    }

    // check if caster has at least 1 combo point for spells that require combo points
    if (m_needComboPoints)
        if (Player* plrCaster = m_caster->ToPlayer())
            if (!plrCaster->GetComboPoints())
                return SPELL_FAILED_NO_COMBO_POINTS;

    // all ok
    return SPELL_CAST_OK;
}

SpellCastResult Spell::CheckPetCast(Unit* target)
{
    Unit* unitCaster = m_caster->ToUnit();
    if (unitCaster && unitCaster->HasUnitState(UNIT_STATE_CASTING) && !(_triggeredCastFlags & TRIGGERED_IGNORE_CAST_IN_PROGRESS)) //prevent spellcast interruption by another spellcast
        return SPELL_FAILED_SPELL_IN_PROGRESS;

    // dead owner (pets still alive when owners ressed?)
    if (Unit* owner = m_caster->GetCharmerOrOwner())
        if (!owner->IsAlive())
            return SPELL_FAILED_CASTER_DEAD;

    if (!target && m_targets.GetUnitTarget())
        target = m_targets.GetUnitTarget();

    if (m_spellInfo->NeedsExplicitUnitTarget())
    {
        if (!target)
            return SPELL_FAILED_BAD_IMPLICIT_TARGETS;
        m_targets.SetUnitTarget(target);
    }

    // check power requirement
    // this would be zero until ::prepare normally, we set it here (it gets reset in ::prepare)
    m_powerCost = m_spellInfo->CalcPowerCost(unitCaster, m_spellSchoolMask);
    SpellCastResult failReason = CheckPower();
    if (failReason != SPELL_CAST_OK)
        return failReason;

    // check cooldown
    if (Creature* creatureCaster = m_caster->ToCreature())
        if (!creatureCaster->GetSpellHistory()->IsReady(m_spellInfo))
            return SPELL_FAILED_NOT_READY;

    // Check if spell is affected by GCD
    if (m_spellInfo->StartRecoveryCategory > 0)
        if (unitCaster && unitCaster->GetCharmInfo() && unitCaster->GetSpellHistory()->HasGlobalCooldown(m_spellInfo))
            return SPELL_FAILED_NOT_READY;

    return CheckCast(true);
}

SpellCastResult Spell::CheckCasterAuras(uint32* param1) const
{
    Unit* unitCaster = (m_originalCaster ? m_originalCaster : m_caster->ToUnit());
    if (!unitCaster)
        return SPELL_CAST_OK;

    // these attributes only show the spell as usable on the client when it has related aura applied
    // still they need to be checked against certain mechanics

    // SPELL_ATTR5_USABLE_WHILE_STUNNED by default only MECHANIC_STUN (ie no sleep, knockout, freeze, etc.)
    bool usableWhileStunned = m_spellInfo->HasAttribute(SPELL_ATTR5_ALLOW_WHILE_STUNNED);

    // SPELL_ATTR5_USABLE_WHILE_FEARED by default only fear (ie no horror)
    bool usableWhileFeared = m_spellInfo->HasAttribute(SPELL_ATTR5_ALLOW_WHILE_FLEEING);

    // SPELL_ATTR5_USABLE_WHILE_CONFUSED by default only disorient (ie no polymorph)
    bool usableWhileConfused = m_spellInfo->HasAttribute(SPELL_ATTR5_ALLOW_WHILE_CONFUSED);

    // Check whether the cast should be prevented by any state you might have.
    SpellCastResult result = SPELL_CAST_OK;

    // Get unit state
    uint32 const unitflag = unitCaster->GetUInt32Value(UNIT_FIELD_FLAGS);

    // this check should only be done when player does cast directly
    // (ie not when it's called from a script) Breaks for example PlayerAI when charmed
    /*
    if (unitCaster->GetCharmerGUID())
    {
        if (Unit* charmer = unitCaster->GetCharmer())
            if (charmer->GetUnitBeingMoved() != unitCaster && !CheckSpellCancelsCharm(param1))
                result = SPELL_FAILED_CHARMED;
    }
    */

    // spell has attribute usable while having a cc state, check if caster has allowed mechanic auras, another mechanic types must prevent cast spell
    auto mechanicCheck = [&](AuraType type) -> SpellCastResult
    {
        bool foundNotMechanic = false;
        Unit::AuraEffectList const& auras = unitCaster->GetAuraEffectsByType(type);
        for (AuraEffect const* aurEff : auras)
        {
            uint32 const mechanicMask = aurEff->GetSpellInfo()->GetAllEffectsMechanicMask();
            if (mechanicMask && !(mechanicMask & GetSpellInfo()->GetAllowedMechanicMask()))
            {
                foundNotMechanic = true;

                // fill up aura mechanic info to send client proper error message
                if (param1)
                {
                    *param1 = aurEff->GetSpellInfo()->Effects[aurEff->GetEffIndex()].Mechanic;
                    if (!*param1)
                        *param1 = aurEff->GetSpellInfo()->Mechanic;
                }

                break;
            }
        }

        if (foundNotMechanic)
        {
            switch (type)
            {
                case SPELL_AURA_MOD_STUN:
                    return SPELL_FAILED_STUNNED;
                case SPELL_AURA_MOD_FEAR:
                    return SPELL_FAILED_FLEEING;
                case SPELL_AURA_MOD_CONFUSE:
                    return SPELL_FAILED_CONFUSED;
                default:
                    ABORT();
                    return SPELL_FAILED_NOT_KNOWN;
            }
        }

        return SPELL_CAST_OK;
    };

    if (unitflag & UNIT_FLAG_STUNNED)
    {
        if (usableWhileStunned)
        {
            SpellCastResult mechanicResult = mechanicCheck(SPELL_AURA_MOD_STUN);
            if (mechanicResult != SPELL_CAST_OK)
                result = mechanicResult;
        }
        else if (!CheckSpellCancelsStun(param1))
            result = SPELL_FAILED_STUNNED;
        else if ((m_spellInfo->Mechanic & MECHANIC_IMMUNE_SHIELD) && m_caster->ToUnit() && m_caster->ToUnit()->HasAuraWithMechanic(1 << MECHANIC_BANISH))
            result = SPELL_FAILED_STUNNED;
    }
    else if (unitflag & UNIT_FLAG_SILENCED && m_spellInfo->PreventionType == SPELL_PREVENTION_TYPE_SILENCE && !CheckSpellCancelsSilence(param1))
        result = SPELL_FAILED_SILENCED;
    else if (unitflag & UNIT_FLAG_PACIFIED && m_spellInfo->PreventionType == SPELL_PREVENTION_TYPE_PACIFY && !CheckSpellCancelsPacify(param1))
        result = SPELL_FAILED_PACIFIED;
    else if (unitflag & UNIT_FLAG_FLEEING)
    {
        if (usableWhileFeared)
        {
            SpellCastResult mechanicResult = mechanicCheck(SPELL_AURA_MOD_FEAR);
            if (mechanicResult != SPELL_CAST_OK)
                result = mechanicResult;
        }
        else if (!CheckSpellCancelsFear(param1))
            result = SPELL_FAILED_FLEEING;
    }
    else if (unitflag & UNIT_FLAG_CONFUSED)
    {
        if (usableWhileConfused)
        {
            SpellCastResult mechanicResult = mechanicCheck(SPELL_AURA_MOD_CONFUSE);
            if (mechanicResult != SPELL_CAST_OK)
                result = mechanicResult;
        }
        else if (!CheckSpellCancelsConfuse(param1))
            result = SPELL_FAILED_CONFUSED;
    }

    // Attr must make flag drop spell totally immune from all effects
    if (result != SPELL_CAST_OK)
        return (param1 && *param1) ? SPELL_FAILED_PREVENTED_BY_MECHANIC : result;

    return SPELL_CAST_OK;
}

bool Spell::CheckSpellCancelsAuraEffect(AuraType auraType, uint32* param1) const
{
    Unit* unitCaster = (m_originalCaster ? m_originalCaster : m_caster->ToUnit());
    if (!unitCaster)
        return false;


    // Checking auras is needed now, because you are prevented by some state but the spell grants immunity.
    Unit::AuraEffectList const& auraEffects = unitCaster->GetAuraEffectsByType(auraType);
    if (auraEffects.empty())
        return true;

    for (AuraEffect const* aurEff : auraEffects)
    {
        SpellInfo const* auraInfo = aurEff->GetSpellInfo();
        if (m_spellInfo->SpellCancelsAuraEffect(auraInfo, aurEff->GetEffIndex()))
            continue;

        if (param1)
        {
            *param1 = auraInfo->Effects[aurEff->GetEffIndex()].Mechanic;
            if (!*param1)
                *param1 = auraInfo->Mechanic;
        }

        return false;
    }

    return true;
}

bool Spell::CheckSpellCancelsCharm(uint32* param1) const
{
    return CheckSpellCancelsAuraEffect(SPELL_AURA_MOD_CHARM, param1) &&
        CheckSpellCancelsAuraEffect(SPELL_AURA_AOE_CHARM, param1) &&
        CheckSpellCancelsAuraEffect(SPELL_AURA_MOD_POSSESS, param1);
}

bool Spell::CheckSpellCancelsStun(uint32* param1) const
{
    return CheckSpellCancelsAuraEffect(SPELL_AURA_MOD_STUN, param1) &&
        CheckSpellCancelsAuraEffect(SPELL_AURA_STRANGULATE, param1);
}

bool Spell::CheckSpellCancelsSilence(uint32* param1) const
{
    return CheckSpellCancelsAuraEffect(SPELL_AURA_MOD_SILENCE, param1) &&
        CheckSpellCancelsAuraEffect(SPELL_AURA_MOD_PACIFY_SILENCE, param1);
}

bool Spell::CheckSpellCancelsPacify(uint32* param1) const
{
    return CheckSpellCancelsAuraEffect(SPELL_AURA_MOD_PACIFY, param1) &&
        CheckSpellCancelsAuraEffect(SPELL_AURA_MOD_PACIFY_SILENCE, param1);
}

bool Spell::CheckSpellCancelsFear(uint32* param1) const
{
    return CheckSpellCancelsAuraEffect(SPELL_AURA_MOD_FEAR, param1);
}

bool Spell::CheckSpellCancelsConfuse(uint32* param1) const
{
    return CheckSpellCancelsAuraEffect(SPELL_AURA_MOD_CONFUSE, param1);
}

SpellCastResult Spell::CheckArenaAndRatedBattlegroundCastRules() const
{
    bool isRatedBattleground = false; // NYI
    bool isArena = !isRatedBattleground;

    // check USABLE attributes
    // USABLE takes precedence over NOT_USABLE
    if (isRatedBattleground && m_spellInfo->HasAttribute(SPELL_ATTR9_USABLE_IN_RATED_BATTLEGROUNDS))
        return SPELL_CAST_OK;

    if (isArena && m_spellInfo->HasAttribute(SPELL_ATTR4_IGNORE_DEFAULT_ARENA_RESTRICTIONS))
        return SPELL_CAST_OK;

    // check NOT_USABLE attributes
    if (m_spellInfo->HasAttribute(SPELL_ATTR4_NOT_IN_ARENA_OR_RATED_BATTLEGROUND))
        return isArena ? SPELL_FAILED_NOT_IN_ARENA : SPELL_FAILED_NOT_IN_RATED_BATTLEGROUND;

    if (isArena && m_spellInfo->HasAttribute(SPELL_ATTR9_NOT_USABLE_IN_ARENA))
        return SPELL_FAILED_NOT_IN_ARENA;

    // check cooldowns
    uint32 spellCooldown = m_spellInfo->GetRecoveryTime();
    if (isArena && spellCooldown > 10 * MINUTE * IN_MILLISECONDS) // not sure if still needed
        return SPELL_FAILED_NOT_IN_ARENA;

    if (isRatedBattleground && spellCooldown > 15 * MINUTE * IN_MILLISECONDS)
        return SPELL_FAILED_NOT_IN_RATED_BATTLEGROUND;

    return SPELL_CAST_OK;
}

SpellCastResult Spell::CheckMovement() const
{
    if (IsTriggered())
        return SPELL_CAST_OK;

    if (Unit* unitCaster = m_caster->ToUnit())
    {
        if (!unitCaster->HasAuraTypeWithAffectMask(SPELL_AURA_CAST_WHILE_WALKING, m_spellInfo))
        {
            if (getState() == SPELL_STATE_PREPARING)
            {
                if (m_casttime > 0)
                    if (m_spellInfo->InterruptFlags.HasFlag(SpellInterruptFlags::Movement))
                        return SPELL_FAILED_MOVING;
            }
            else if (getState() == SPELL_STATE_CASTING)
                if (!m_spellInfo->IsMoveAllowedChannel())
                    return SPELL_FAILED_MOVING;
        }
    }

    return SPELL_CAST_OK;
}

int32 Spell::CalculateDamage(uint8 effIndex, Unit const* target) const
{
    return m_caster->CalculateSpellDamage(target, m_spellInfo, effIndex, &m_spellValue->EffectBasePoints[effIndex]);
}

bool Spell::CanAutoCast(Unit* target)
{
    if (!target)
        return (CheckPetCast(target) == SPELL_CAST_OK);
    ObjectGuid targetguid = target->GetGUID();

    // check if target already has the same or a more powerful aura
    for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        if (!GetSpellInfo()->Effects[i].IsAura())
            continue;

        AuraType const& auraType = AuraType(GetSpellInfo()->Effects[i].ApplyAuraName);
        Unit::AuraEffectList const& auras = target->GetAuraEffectsByType(auraType);
        for (Unit::AuraEffectList::const_iterator auraIt = auras.begin(); auraIt != auras.end(); ++auraIt)
        {
            if (GetSpellInfo()->Id == (*auraIt)->GetSpellInfo()->Id)
                return false;

            switch (sSpellMgr->CheckSpellGroupStackRules(GetSpellInfo(), (*auraIt)->GetSpellInfo()))
            {
                case SPELL_GROUP_STACK_RULE_EXCLUSIVE:
                    return false;
                case SPELL_GROUP_STACK_RULE_EXCLUSIVE_FROM_SAME_CASTER:
                    if (GetCaster() == (*auraIt)->GetCaster())
                        return false;
                    break;
                case SPELL_GROUP_STACK_RULE_EXCLUSIVE_SAME_EFFECT: // this one has further checks, but i don't think they're necessary for autocast logic
                case SPELL_GROUP_STACK_RULE_EXCLUSIVE_HIGHEST:
                    if (abs(GetSpellInfo()->Effects[i].BasePoints) <= abs((*auraIt)->GetAmount()))
                        return false;
                    break;
                case SPELL_GROUP_STACK_RULE_DEFAULT:
                default:
                    break;
            }
        }
    }

    SpellCastResult result = CheckPetCast(target);
    if (result == SPELL_CAST_OK || result == SPELL_FAILED_UNIT_NOT_INFRONT)
    {
        // do not check targets for ground-targeted spells (we target them on top of the intended target anyway)
        if (GetSpellInfo()->ExplicitTargetMask & TARGET_FLAG_DEST_LOCATION)
            return true;
        SelectSpellTargets();
        //check if among target units, our WANTED target is as well (->only self cast spells return false)
        for (auto ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
            if (ihit->TargetGUID == targetguid)
                return true;
    }
    // either the cast failed or the intended target wouldn't be hit
    return false;
}

void Spell::CheckSrc()
{
    if (!m_targets.HasSrc())
        m_targets.SetSrc(*m_caster);
}

void Spell::CheckDst()
{
    if (!m_targets.HasDst())
        m_targets.SetDst(*m_caster);
}

SpellCastResult Spell::CheckRange(bool strict) const
{
    // Don't check for instant cast spells
    if (!strict && m_casttime == 0)
        return SPELL_CAST_OK;

    float minRange, maxRange;
    std::tie(minRange, maxRange) = GetMinMaxRange(strict);

    // dont check max_range to strictly after cast
    if (m_spellInfo->RangeEntry && m_spellInfo->RangeEntry->Flags != SPELL_RANGE_MELEE && !strict)
        maxRange += std::min(MAX_SPELL_RANGE_TOLERANCE, maxRange*0.1f); // 10% but no more than MAX_SPELL_RANGE_TOLERANCE

    // get square values for sqr distance checks
    minRange *= minRange;
    maxRange *= maxRange;

    Unit* target = m_targets.GetUnitTarget();
    if (target && target != m_caster)
    {
        if (m_caster->GetExactDistSq(target) > maxRange)
            return SPELL_FAILED_OUT_OF_RANGE;

        if (minRange > 0.0f && m_caster->GetExactDistSq(target) < minRange && !target->HasFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_IGNORE_SPELL_MIN_RANGE_RESTRICTIONS))
            return SPELL_FAILED_TOO_CLOSE;

        if (m_caster->GetTypeId() == TYPEID_PLAYER &&
            (((m_spellInfo->FacingCasterFlags & SPELL_FACING_FLAG_INFRONT) && !m_caster->HasInArc(static_cast<float>(M_PI), target))
                && !m_caster->ToPlayer()->IsWithinBoundaryRadius(target)))
            return SPELL_FAILED_UNIT_NOT_INFRONT;
    }

    if (GameObject* goTarget = m_targets.GetGOTarget())
    {
        if (!goTarget->IsAtInteractDistance(m_caster->ToPlayer(), m_spellInfo))
            return SPELL_FAILED_OUT_OF_RANGE;
    }

    if (m_targets.HasDst() && !m_targets.HasTraj())
    {
        if (m_caster->GetExactDistSq(m_targets.GetDstPos()) > maxRange)
            return SPELL_FAILED_OUT_OF_RANGE;
        if (minRange > 0.0f && m_caster->GetExactDistSq(m_targets.GetDstPos()) < minRange)
            return SPELL_FAILED_TOO_CLOSE;
    }

    return SPELL_CAST_OK;
}

std::pair<float, float> Spell::GetMinMaxRange(bool strict) const
{
    float rangeMod = 0.0f;
    float minRange = 0.0f;
    float maxRange = 0.0f;

    if (strict && m_spellInfo->IsNextMeleeSwingSpell())
        return { 0.0f, 100.0f };

    Unit* unitCaster = m_caster->ToUnit();
    if (m_spellInfo->RangeEntry)
    {
        Unit* target = m_targets.GetUnitTarget();
        if (m_spellInfo->RangeEntry->Flags & SPELL_RANGE_MELEE)
        {
            // when the target is not a unit, take the caster's combat reach as the target's combat reach.
            if (unitCaster)
                rangeMod = unitCaster->GetMeleeRange(target ? target : unitCaster);
        }
        else
        {
            float meleeRange = 0.0f;
            if (m_spellInfo->RangeEntry->Flags & SPELL_RANGE_RANGED)
            {
                // when the target is not a unit, take the caster's combat reach as the target's combat reach.
                if (unitCaster)
                    meleeRange = unitCaster->GetMeleeRange(target ? target : unitCaster);
            }

            minRange = m_caster->GetSpellMinRangeForTarget(target, m_spellInfo) + meleeRange;
            maxRange = m_caster->GetSpellMaxRangeForTarget(target, m_spellInfo);

            if (target || m_targets.GetCorpseTarget())
            {
                rangeMod = m_caster->GetCombatReach() + (target ? target->GetCombatReach() : m_caster->GetCombatReach());

                if (minRange > 0.0f && !(m_spellInfo->RangeEntry->Flags & SPELL_RANGE_RANGED))
                    minRange += rangeMod;
            }
        }

        if (target && unitCaster && unitCaster->isMoving() && target->isMoving() && !unitCaster->IsWalking() && !target->IsWalking() &&
            ((m_spellInfo->RangeEntry->Flags & SPELL_RANGE_MELEE) || target->GetTypeId() == TYPEID_PLAYER))
            rangeMod += 8.0f / 3.0f;
    }

    if (m_spellInfo->HasAttribute(SPELL_ATTR0_USES_RANGED_SLOT) && m_caster->GetTypeId() == TYPEID_PLAYER)
        if (Item* ranged = m_caster->ToPlayer()->GetWeaponForAttack(RANGED_ATTACK, true))
            maxRange *= ranged->GetTemplate()->GetRangedModRange() * 0.01f;

    if (Player* modOwner = m_caster->GetSpellModOwner())
        modOwner->ApplySpellMod(m_spellInfo->Id, SpellModOp::Range, maxRange, const_cast<Spell*>(this));

    maxRange += rangeMod;

    return { minRange, maxRange };
}

SpellCastResult Spell::CheckPower() const
{
    Unit* unitCaster = m_caster->ToUnit();
    if (!unitCaster)
        return SPELL_CAST_OK;

    // item cast not used power
    if (m_CastItem)
        return SPELL_CAST_OK;

    // health as power used - need check health amount
    if (m_spellInfo->PowerType == POWER_HEALTH)
    {
        if (int64(unitCaster->GetHealth()) <= m_powerCost)
            return SPELL_FAILED_CASTER_AURASTATE;
        return SPELL_CAST_OK;
    }
    // Check valid power type
    if (m_spellInfo->PowerType >= MAX_POWERS)
    {
        TC_LOG_ERROR("spells", "Spell::CheckPower: Unknown power type '%d'", m_spellInfo->PowerType);
        return SPELL_FAILED_UNKNOWN;
    }

    //check rune cost only if a spell has PowerType == POWER_RUNES
    if (m_spellInfo->PowerType == POWER_RUNE)
    {
        SpellCastResult failReason = CheckRuneCost(m_spellInfo->RuneCostID);
        if (failReason != SPELL_CAST_OK)
            return failReason;
    }

    // Check power amount
    Powers powerType = Powers(m_spellInfo->PowerType);
    if (int32(unitCaster->GetPower(powerType)) < m_powerCost)
        return SPELL_FAILED_NO_POWER;
    else
        return SPELL_CAST_OK;
}

SpellCastResult Spell::CheckItems(uint32* param1 /*= nullptr*/, uint32* param2 /*= nullptr*/) const
{
    // We expect a cast item but we don't have one. Fail cast right away
    if (!m_CastItem && !m_castItemGUID.IsEmpty())
        return SPELL_FAILED_ITEM_NOT_READY;

    Player* player = m_caster->ToPlayer();
    if (m_CastItem)
    {
        // Casting spells from an item always requires a player using it.
        if (!player)
            return SPELL_FAILED_ITEM_NOT_READY;

        if (!player->HasItemCount(m_CastItem->GetEntry()))
            return SPELL_FAILED_ITEM_NOT_READY;

        ItemTemplate const* proto = m_CastItem->GetTemplate();
        if (!proto)
            return SPELL_FAILED_ITEM_NOT_READY;

        for (uint8 i = 0; i < proto->Effects.size(); ++i)
            if (proto->Effects[i].Charges)
                if (m_CastItem->GetSpellCharges(i) == 0)
                    return SPELL_FAILED_NO_CHARGES_REMAIN;

        // Consumable cast item checks
        if (proto->GetClass() == ITEM_CLASS_CONSUMABLE && m_targets.GetUnitTarget())
        {
            // Such items should only fail if there is no suitable effect at all - see Rejuvenation Potions for example
            SpellCastResult failReason = SPELL_CAST_OK;
            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            {
                // Skip check, pet not required like checks, and for TARGET_UNIT_PET m_targets.GetUnitTarget() is not the real target but the caster
                if (m_spellInfo->Effects[i].TargetA.GetTarget() == TARGET_UNIT_PET)
                    continue;

                if (m_spellInfo->Effects[i].Effect == SPELL_EFFECT_HEAL)
                {
                    if (m_targets.GetUnitTarget()->IsFullHealth())
                    {
                        failReason = SPELL_FAILED_ALREADY_AT_FULL_HEALTH;
                        continue;
                    }
                    else
                    {
                        failReason = SPELL_CAST_OK;
                        break;
                    }
                }

                // Mana Potion, Rage Potion, Thistle Tea(Rogue), ...
                if (m_spellInfo->Effects[i].Effect == SPELL_EFFECT_ENERGIZE)
                {
                    if (m_spellInfo->Effects[i].MiscValue < 0 || m_spellInfo->Effects[i].MiscValue >= int8(MAX_POWERS))
                    {
                        failReason = SPELL_FAILED_ALREADY_AT_FULL_POWER;
                        continue;
                    }

                    Powers power = Powers(m_spellInfo->Effects[i].MiscValue);
                    if (m_targets.GetUnitTarget()->GetPower(power) == m_targets.GetUnitTarget()->GetMaxPower(power))
                    {
                        failReason = SPELL_FAILED_ALREADY_AT_FULL_POWER;
                        continue;
                    }
                    else
                    {
                        failReason = SPELL_CAST_OK;
                        break;
                    }
                }
            }
            if (failReason != SPELL_CAST_OK)
                return failReason;
        }
    }

    // Check target item
    if (m_targets.GetItemTargetGUID())
    {
        Item* item = m_targets.GetItemTarget();
        if (!item || item->GetGUID() != m_targets.GetItemTargetGUID())
            return SPELL_FAILED_ITEM_GONE;

        if (!item->IsFitToSpellRequirements(m_spellInfo))
            return SPELL_FAILED_EQUIPPED_ITEM_CLASS;
    }
    else if (player)
    {
        // Check item requirements
        if (!(_triggeredCastFlags & TRIGGERED_IGNORE_EQUIPPED_ITEM_REQUIREMENT))
            if (!player->HasItemFitToSpellRequirements(m_spellInfo))
                return SPELL_FAILED_EQUIPPED_ITEM_CLASS;
    }

    // Check reagent requirements
    bool needReagentCheck = [&]()
    {
        if (m_CastItem && m_CastItem->GetTemplate()->GetFlags() & ITEM_FLAG_NO_REAGENT_COST)
            return false;

        if (!(_triggeredCastFlags & TRIGGERED_IGNORE_POWER_AND_REAGENT_COST) || (player && !player->CanNoReagentCast(m_spellInfo)))
            return false;

        return true;
    }();

    // Enchanting other players items always requires a reagent check so we do not skip its checks
    if (!needReagentCheck)
        if (Item* targetItem = m_targets.GetItemTarget())
            if (player && targetItem->GetOwnerGUID() != player->GetGUID())
                needReagentCheck = true;

    if (needReagentCheck)
    {
        for (uint32 i = 0; i < MAX_SPELL_REAGENTS; ++i)
        {
            // No reagent required, check the next entry
            if (m_spellInfo->Reagent[i] <= 0)
                continue;

            uint32 requiredItemId = m_spellInfo->Reagent[i];
            uint32 requiredItemQuantity = m_spellInfo->ReagentCount[i];

            // if CastItem is also spell reagent
            if (m_CastItem && m_CastItem->GetEntry() == requiredItemId)
            {
                ItemTemplate const* proto = m_CastItem->GetTemplate();
                if (!proto)
                    return SPELL_FAILED_ITEM_NOT_READY;

                for (uint8 s = 0; s < proto->Effects.size(); ++s)
                {
                    // CastItem will be used up and does not count as reagent
                    int32 charges = m_CastItem->GetSpellCharges(s);
                    if (proto->Effects[s].Charges < 0 && abs(charges) < 2)
                    {
                        ++requiredItemQuantity;
                        break;
                    }
                }
            }

            if (!player || !player->HasItemCount(requiredItemId, requiredItemQuantity))
            {
                if (param1)
                    *param1 = requiredItemId;
                return SPELL_FAILED_REAGENTS;
            }
        }
    }

    // special checks for spell effects
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        switch (m_spellInfo->Effects[i].Effect)
        {
            case SPELL_EFFECT_CREATE_ITEM:
            case SPELL_EFFECT_CREATE_ITEM_2:
            {
                // m_targets.GetUnitTarget() means explicit cast, otherwise we dont check for possible equip error
                Player* playerTarget = m_targets.GetUnitTarget() ? m_targets.GetUnitTarget()->ToPlayer() : player;
                if (!playerTarget)
                    return SPELL_FAILED_BAD_TARGETS;

                if (!IsTriggered())
                {
                    // SPELL_EFFECT_CREATE_ITEM_2 differs from SPELL_EFFECT_CREATE_ITEM in that it picks the random item to create from a pool of potential items,
                    // so we need to make sure there is at least one free space in the player's inventory
                    if (m_spellInfo->Effects[i].Effect == SPELL_EFFECT_CREATE_ITEM_2)
                        if (playerTarget->GetFreeInventorySpace() == 0)
                        {
                            if (player)
                                player->SendEquipError(EQUIP_ERR_INV_FULL, nullptr, nullptr, m_spellInfo->Effects[i].ItemType);
                            return SPELL_FAILED_DONT_REPORT;
                        }

                    if (m_spellInfo->Effects[i].ItemType)
                    {
                        ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(m_spellInfo->Effects[i].ItemType);
                        if (!itemTemplate)
                            return SPELL_FAILED_ITEM_NOT_FOUND;

                        uint32 createCount = std::clamp<uint32>(m_spellInfo->Effects[i].CalcValue(), 1u, itemTemplate->GetMaxStackSize());
                        ItemPosCountVec dest;
                        InventoryResult msg = playerTarget->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, m_spellInfo->Effects[i].ItemType, createCount);
                        if (msg != EQUIP_ERR_OK)
                        {
                            /// @todo Needs review
                            if (!itemTemplate->GetItemLimitCategory())
                            {
                                if (player)
                                    player->SendEquipError(msg, nullptr, nullptr, m_spellInfo->Effects[i].ItemType);
                                return SPELL_FAILED_DONT_REPORT;
                            }
                            else
                            {
                                // Conjure Food/Water/Refreshment spells
                                if (m_spellInfo->SpellFamilyName != SPELLFAMILY_MAGE || (!(m_spellInfo->SpellFamilyFlags[0] & 0x40000000)))
                                    return SPELL_FAILED_TOO_MANY_OF_ITEM;
                                else if (!(playerTarget->HasItemCount(m_spellInfo->Effects[i].ItemType)))
                                {
                                    if (player)
                                        player->SendEquipError(msg, nullptr, nullptr, m_spellInfo->Effects[i].ItemType);
                                    return SPELL_FAILED_DONT_REPORT;
                                }
                                else
                                    if (player)
                                        player->CastSpell(player, m_spellInfo->Effects[EFFECT_1].CalcValue(), CastSpellExtraArgs().SetTriggeringSpell(this));        // move this to anywhere
                                return SPELL_FAILED_DONT_REPORT;
                            }
                        }
                    }
                }
                break;
            }
            default:
                break;
        }
    }

    // From this point forward, we will only check player based requirements so we end this procedure here for creature and gameobject casts.
    if (!player)
        return SPELL_CAST_OK;

    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        switch (m_spellInfo->Effects[i].Effect)
        {
            case SPELL_EFFECT_ENCHANT_ITEM:
                if (m_spellInfo->Effects[i].ItemType && m_targets.GetItemTarget()
                    && (m_targets.GetItemTarget()->IsVellum()))
                {
                    // cannot enchant vellum for other player
                    if (m_targets.GetItemTarget()->GetOwner() != player)
                        return SPELL_FAILED_NOT_TRADEABLE;
                    // do not allow to enchant vellum from scroll made by vellum-prevent exploit
                    if (m_CastItem && m_CastItem->GetTemplate()->GetFlags() & ITEM_FLAG_NO_REAGENT_COST)
                        return SPELL_FAILED_TOTEM_CATEGORY;
                    ItemPosCountVec dest;
                    InventoryResult msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, m_spellInfo->Effects[i].ItemType, 1);
                    if (msg != EQUIP_ERR_OK)
                    {
                        player->SendEquipError(msg, nullptr, nullptr, m_spellInfo->Effects[i].ItemType);
                        return SPELL_FAILED_DONT_REPORT;
                    }
                }
                [[fallthrough]];
            case SPELL_EFFECT_ENCHANT_ITEM_PRISMATIC:
            {
                Item* targetItem = m_targets.GetItemTarget();
                if (!targetItem)
                    return SPELL_FAILED_ITEM_NOT_FOUND;

                // required level has to be checked also! Exploit fix
                if (targetItem->GetTemplate()->GetBaseItemLevel() < m_spellInfo->BaseLevel)
                    return SPELL_FAILED_LOWLEVEL;

                bool isItemUsable = false;
                ItemTemplate const* proto = targetItem->GetTemplate();
                for (uint8 e = 0; e < proto->Effects.size(); ++e)
                {
                    if (proto->Effects[e].SpellID && (
                        proto->Effects[e].Trigger == ITEM_SPELLTRIGGER_ON_USE ||
                        proto->Effects[e].Trigger == ITEM_SPELLTRIGGER_ON_NO_DELAY_USE))
                    {
                        isItemUsable = true;
                        break;
                    }
                }

                SpellItemEnchantmentEntry const* enchantEntry = sSpellItemEnchantmentStore.LookupEntry(m_spellInfo->Effects[i].MiscValue);
                // do not allow adding usable enchantments to items that have use effect already
                if (enchantEntry)
                {
                    for (uint8 s = 0; s < MAX_ITEM_ENCHANTMENT_EFFECTS; ++s)
                    {
                        switch (enchantEntry->Effect[s])
                        {
                            case ITEM_ENCHANTMENT_TYPE_USE_SPELL:
                                if (isItemUsable)
                                    return SPELL_FAILED_ON_USE_ENCHANT;
                                break;
                            case ITEM_ENCHANTMENT_TYPE_PRISMATIC_SOCKET:
                            {
                                uint32 numSockets = 0;
                                for (uint32 socket = 0; socket < MAX_ITEM_PROTO_SOCKETS; ++socket)
                                    if (targetItem->GetTemplate()->GetSocketColor(socket))
                                        ++numSockets;

                                if (numSockets == MAX_ITEM_PROTO_SOCKETS || targetItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT))
                                    return SPELL_FAILED_MAX_SOCKETS;
                                break;
                            }
                        }
                    }
                }

                // Not allow enchant in trade slot for some enchant type
                if (targetItem->GetOwner() != player)
                {
                    if (!enchantEntry)
                        return SPELL_FAILED_ERROR;
                    if (enchantEntry->GetFlags().HasFlag(SpellItemEnchantmentFlags::Soulbound))
                        return SPELL_FAILED_NOT_TRADEABLE;
                }
                break;
            }
            case SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY:
            {
                Item* item = m_targets.GetItemTarget();
                if (!item)
                    return SPELL_FAILED_ITEM_NOT_FOUND;
                // Not allow enchant in trade slot for some enchant type
                if (item->GetOwner() != player)
                {
                    uint32 enchant_id = m_spellInfo->Effects[i].MiscValue;
                    SpellItemEnchantmentEntry const* enchantEntry = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
                    if (!enchantEntry)
                        return SPELL_FAILED_ERROR;
                    if (enchantEntry->GetFlags().HasFlag(SpellItemEnchantmentFlags::Soulbound))
                        return SPELL_FAILED_NOT_TRADEABLE;
                }

                // Apply item level restriction if the enchanting spell has max level restrition set
                if (m_CastItem && m_spellInfo->MaxLevel > 0)
                {
                    if (int32(item->GetTemplate()->GetBaseItemLevel()) < m_CastItem->GetTemplate()->GetRequiredLevel())
                        return SPELL_FAILED_LOWLEVEL;
                    if (item->GetTemplate()->GetBaseItemLevel() > m_spellInfo->MaxLevel)
                        return SPELL_FAILED_HIGHLEVEL;
                }
                break;
            }
            case SPELL_EFFECT_ENCHANT_HELD_ITEM:
                // check item existence in effect code (not output errors at offhand hold item effect to main hand for example
                break;
            case SPELL_EFFECT_DISENCHANT:
            {
                if (!m_targets.GetItemTarget())
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;

                // prevent disenchanting in trade slot
                if (m_targets.GetItemTarget()->GetOwnerGUID() != player->GetGUID())
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;

                ItemTemplate const* itemProto = m_targets.GetItemTarget()->GetTemplate();
                if (!itemProto)
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;

                uint32 item_quality = itemProto->GetQuality();
                // 2.0.x addon: Check player enchanting level against the item disenchanting requirements
                uint32 item_disenchantskilllevel = itemProto->RequiredDisenchantSkill;
                if (item_disenchantskilllevel == uint32(-1))
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;
                if (item_disenchantskilllevel > player->GetSkillValue(SKILL_ENCHANTING))
                    return SPELL_FAILED_LOW_CASTLEVEL;
                if (item_quality > 4 || item_quality < 2)
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;
                if (itemProto->GetClass() != ITEM_CLASS_WEAPON && itemProto->GetClass() != ITEM_CLASS_ARMOR)
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;
                if (!itemProto->DisenchantID)
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;
                break;
            }
            case SPELL_EFFECT_PROSPECTING:
            {
                Item* item = m_targets.GetItemTarget();
                if (!item)
                    return SPELL_FAILED_CANT_BE_PROSPECTED;
                //ensure item is a prospectable ore
                if (!(item->GetTemplate()->GetFlags() & ITEM_FLAG_IS_PROSPECTABLE))
                    return SPELL_FAILED_CANT_BE_PROSPECTED;
                //prevent prospecting in trade slot
                if (item->GetOwnerGUID() != player->GetGUID())
                    return SPELL_FAILED_CANT_BE_PROSPECTED;
                //Check for enough skill in jewelcrafting
                uint32 item_prospectingskilllevel = item->GetTemplate()->GetRequiredSkillRank();
                if (item_prospectingskilllevel > player->GetSkillValue(SKILL_JEWELCRAFTING))
                    return SPELL_FAILED_LOW_CASTLEVEL;
                //make sure the player has the required ores in inventory
                if (item->GetCount() < 5)
                {
                    if (param1 && param2)
                    {
                        *param1 = item->GetEntry();
                        *param2 = 5;
                    }
                    return SPELL_FAILED_NEED_MORE_ITEMS;
                }

                if (!LootTemplates_Prospecting.HaveLootFor(m_targets.GetItemTargetEntry()))
                    return SPELL_FAILED_CANT_BE_PROSPECTED;

                break;
            }
            case SPELL_EFFECT_MILLING:
            {
                Item* item = m_targets.GetItemTarget();
                if (!item)
                    return SPELL_FAILED_CANT_BE_MILLED;
                //ensure item is a millable herb
                if (!(item->GetTemplate()->GetFlags() & ITEM_FLAG_IS_MILLABLE))
                    return SPELL_FAILED_CANT_BE_MILLED;
                //prevent milling in trade slot
                if (item->GetOwnerGUID() != player->GetGUID())
                    return SPELL_FAILED_CANT_BE_MILLED;
                //Check for enough skill in inscription
                uint32 item_millingskilllevel = item->GetTemplate()->GetRequiredSkillRank();
                if (item_millingskilllevel > player->GetSkillValue(SKILL_INSCRIPTION))
                    return SPELL_FAILED_LOW_CASTLEVEL;
                //make sure the player has the required herbs in inventory
                if (item->GetCount() < 5)
                {
                    if (param1 && param2)
                    {
                        *param1 = item->GetEntry();
                        *param2 = 5;
                    }
                    return SPELL_FAILED_NEED_MORE_ITEMS;
                }

                if (!LootTemplates_Milling.HaveLootFor(m_targets.GetItemTargetEntry()))
                    return SPELL_FAILED_CANT_BE_MILLED;

                break;
            }
            case SPELL_EFFECT_WEAPON_DAMAGE:
            case SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL:
            {
                if (m_attackType != RANGED_ATTACK)
                    break;

                Item* item = player->GetWeaponForAttack(m_attackType);
                if (!item || item->IsBroken())
                    return SPELL_FAILED_EQUIPPED_ITEM;

                switch (item->GetTemplate()->GetSubClass())
                {
                    case ITEM_SUBCLASS_WEAPON_THROWN:
                    case ITEM_SUBCLASS_WEAPON_GUN:
                    case ITEM_SUBCLASS_WEAPON_BOW:
                    case ITEM_SUBCLASS_WEAPON_CROSSBOW:
                    case ITEM_SUBCLASS_WEAPON_WAND:
                        break;
                    default:
                        break;
                }
                break;
            }
            case SPELL_EFFECT_CREATE_MANA_GEM:
            {
                 uint32 item_id = m_spellInfo->Effects[i].ItemType;
                 ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(item_id);

                 if (!pProto)
                     return SPELL_FAILED_ITEM_AT_MAX_CHARGES;

                 if (Item* pitem = player->GetItemByEntry(item_id))
                 {
                     for (uint8 x = 0; x < pProto->Effects.size(); ++x)
                         if (pProto->Effects[x].Charges != 0 && pitem->GetSpellCharges(x) == pProto->Effects[x].Charges)
                             return SPELL_FAILED_ITEM_AT_MAX_CHARGES;
                 }
                 break;
            }
            default:
                break;
        }
    }

    // check weapon presence in slots for main/offhand weapons
    if (!(_triggeredCastFlags & TRIGGERED_IGNORE_EQUIPPED_ITEM_REQUIREMENT) && m_spellInfo->EquippedItemClass >=0)
    {
        // main hand weapon required
        if (m_spellInfo->HasAttribute(SPELL_ATTR3_REQUIRES_MAIN_HAND_WEAPON))
        {
            Item* item = player->GetWeaponForAttack(BASE_ATTACK);

            // skip spell if no weapon in slot or broken
            if (!item || item->IsBroken())
                return (_triggeredCastFlags & TRIGGERED_DONT_REPORT_CAST_ERROR) ? SPELL_FAILED_DONT_REPORT : SPELL_FAILED_EQUIPPED_ITEM_CLASS;

            // skip spell if weapon not fit to triggered spell
            if (!item->IsFitToSpellRequirements(m_spellInfo))
                return (_triggeredCastFlags & TRIGGERED_DONT_REPORT_CAST_ERROR) ? SPELL_FAILED_DONT_REPORT : SPELL_FAILED_EQUIPPED_ITEM_CLASS;
        }

        // offhand hand weapon required
        if (m_spellInfo->HasAttribute(SPELL_ATTR3_REQUIRES_OFF_HAND_WEAPON))
        {
            Item* item = m_caster->ToPlayer()->GetWeaponForAttack(OFF_ATTACK);

            // skip spell if no weapon in slot or broken
            if (!item || item->IsBroken())
                return (_triggeredCastFlags & TRIGGERED_DONT_REPORT_CAST_ERROR) ? SPELL_FAILED_DONT_REPORT : SPELL_FAILED_EQUIPPED_ITEM_CLASS;

            // skip spell if weapon not fit to triggered spell
            if (!item->IsFitToSpellRequirements(m_spellInfo))
                return (_triggeredCastFlags & TRIGGERED_DONT_REPORT_CAST_ERROR) ? SPELL_FAILED_DONT_REPORT : SPELL_FAILED_EQUIPPED_ITEM_CLASS;
        }
    }

    return SPELL_CAST_OK;
}

void Spell::Delayed() // only called in DealDamage()
{
    Unit* unitCaster = m_caster->ToUnit();
    if (!unitCaster)
        return;

    if (IsDelayableNoMore())                                 // Spells may only be delayed twice
        return;

    //check pushback reduce
    int32 delaytime = 500;                                  // spellcasting delay is normally 500ms

    int32 delayReduce = 100;                                // must be initialized to 100 for percent modifiers
    if (Player* player = unitCaster->GetSpellModOwner())
        player->ApplySpellMod(m_spellInfo->Id, SpellModOp::ResistPushback, delayReduce, this);
    delayReduce += unitCaster->GetTotalAuraModifier(SPELL_AURA_REDUCE_PUSHBACK) - 100;
    if (delayReduce >= 100)
        return;

    AddPct(delaytime, -delayReduce);

    if (m_timer + delaytime > m_casttime)
    {
        delaytime = m_casttime - m_timer;
        m_timer = m_casttime;
    }
    else
        m_timer += delaytime;

    WorldPackets::Spells::SpellDelayed spellDelayed;
    spellDelayed.Caster = unitCaster->GetGUID();
    spellDelayed.ActualDelay = delaytime;

    unitCaster->SendMessageToSet(spellDelayed.Write(), true);
}

void Spell::DelayedChannel()
{
    Player* playerCaster = m_caster->ToPlayer();
    if (!playerCaster)
        return;

    if (m_spellState != SPELL_STATE_CASTING)
        return;

    if (IsDelayableNoMore())                                    // Spells may only be delayed twice
        return;

    //check pushback reduce
    // should be affected by modifiers, not take the dbc duration.
    int32 duration = ((m_channeledDuration > 0) ? m_channeledDuration : m_spellInfo->GetDuration());

    int32 delaytime = CalculatePct(duration, 25); // channeling delay is normally 25% of its time per hit
    int32 delayReduce = 100;                                    // must be initialized to 100 for percent modifiers
    if (Player* player = playerCaster->GetSpellModOwner())
        player->ApplySpellMod(m_spellInfo->Id, SpellModOp::ResistPushback, delayReduce, this);
    delayReduce += playerCaster->GetTotalAuraModifier(SPELL_AURA_REDUCE_PUSHBACK) - 100;
    if (delayReduce >= 100)
        return;

    AddPct(delaytime, -delayReduce);

    if (m_timer <= delaytime)
    {
        delaytime = m_timer;
        m_timer = 0;
    }
    else
        m_timer -= delaytime;

    for (TargetInfo const& targetInfo : m_UniqueTargetInfo)
        if (targetInfo.MissCondition == SPELL_MISS_NONE)
            if (Unit* unit = (playerCaster->GetGUID() == targetInfo.TargetGUID) ? playerCaster : ObjectAccessor::GetUnit(*playerCaster, targetInfo.TargetGUID))
                unit->DelayOwnedAuras(m_spellInfo->Id, m_originalCasterGUID, delaytime);

    // partially interrupt persistent area auras
    if (DynamicObject* dynObj = unitCaster->GetDynObject(m_spellInfo->Id))
        dynObj->Delay(delaytime);

    SendChannelUpdate(m_timer);
}

bool Spell::UpdatePointers()
{
    if (m_originalCasterGUID == m_caster->GetGUID())
        m_originalCaster = m_caster->ToUnit();
    else
    {
        m_originalCaster = ObjectAccessor::GetUnit(*m_caster, m_originalCasterGUID);
        if (m_originalCaster && !m_originalCaster->IsInWorld())
            m_originalCaster = nullptr;
    }

    if (m_castItemGUID && m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        m_CastItem = m_caster->ToPlayer()->GetItemByGuid(m_castItemGUID);
        // cast item not found, somehow the item is no longer where we expected
        if (!m_CastItem)
            return false;

        // check if the item is really the same, in case it has been wrapped for example
        if (m_castItemEntry != m_CastItem->GetEntry())
            return false;
    }

    m_targets.Update(m_caster);

    // further actions done only for dest targets
    if (!m_targets.HasDst())
        return true;

    // cache last transport
    WorldObject* transport = nullptr;

    // update effect destinations (in case of moved transport dest target)
    for (uint8 effIndex = 0; effIndex < MAX_SPELL_EFFECTS; ++effIndex)
    {
        SpellDestination& dest = m_destTargets[effIndex];
        if (!dest._transportGUID)
            continue;

        if (!transport || transport->GetGUID() != dest._transportGUID)
            transport = ObjectAccessor::GetWorldObject(*m_caster, dest._transportGUID);

        if (transport)
        {
            dest._position.Relocate(transport);
            dest._position.RelocateOffset(dest._transportOffset);
        }
    }

    return true;
}

CurrentSpellTypes Spell::GetCurrentContainer() const
{
    if (m_spellInfo->IsNextMeleeSwingSpell())
        return CURRENT_MELEE_SPELL;
    else if (IsAutoRepeat())
        return CURRENT_AUTOREPEAT_SPELL;
    else if (m_spellInfo->IsChanneled())
        return CURRENT_CHANNELED_SPELL;

    return CURRENT_GENERIC_SPELL;
}

bool Spell::CheckEffectTarget(Unit const* target, uint32 eff, Position const* losPosition) const
{
    switch (m_spellInfo->Effects[eff].ApplyAuraName)
    {
        case SPELL_AURA_MOD_POSSESS:
        case SPELL_AURA_MOD_CHARM:
        case SPELL_AURA_AOE_CHARM:
            if (target->GetVehicleKit() && target->GetVehicleKit()->IsControllableVehicle())
                return false;
            if (target->IsMounted())
                return false;
            if (target->GetCharmerGUID())
                return false;
            if (int32 value = CalculateDamage(eff, target))
                if ((int32)target->getLevel() > value)
                    return false;
            break;
        default:
            break;
    }

    // check for ignore LOS on the effect itself
    if (m_spellInfo->HasAttribute(SPELL_ATTR2_IGNORE_LINE_OF_SIGHT) || DisableMgr::IsDisabledFor(DISABLE_TYPE_SPELL, m_spellInfo->Id, nullptr, SPELL_DISABLE_LOS))
        return true;

    // check if gameobject ignores LOS
    if (GameObject const* gobCaster = m_caster->ToGameObject())
        if (gobCaster->GetGOInfo()->IsIgnoringLOSChecks())
            return true;

    // if spell is triggered, need to check for LOS disable on the aura triggering it and inherit that behaviour
    if (!m_spellInfo->HasAttribute(SPELL_ATTR5_ALWAYS_LINE_OF_SIGHT) && IsTriggered() && m_triggeredByAuraSpell && (m_triggeredByAuraSpell->HasAttribute(SPELL_ATTR2_IGNORE_LINE_OF_SIGHT) || DisableMgr::IsDisabledFor(DISABLE_TYPE_SPELL, m_triggeredByAuraSpell->Id, nullptr, SPELL_DISABLE_LOS)))
        return true;

    /// @todo shit below shouldn't be here, but it's temporary
    //Check targets for LOS visibility (except spells without range limitations)
    switch (m_spellInfo->Effects[eff].Effect)
    {
        case SPELL_EFFECT_RESURRECT_NEW:
            // player far away, maybe his corpse near?
            if (target != m_caster && !target->IsWithinLOSInMap(m_caster))
            {
                if (!m_targets.GetCorpseTargetGUID())
                    return false;

                Corpse* corpse = ObjectAccessor::GetCorpse(*m_caster, m_targets.GetCorpseTargetGUID());
                if (!corpse)
                    return false;

                if (target->GetGUID() != corpse->GetOwnerGUID())
                    return false;

                if (!corpse->IsWithinLOSInMap(m_caster))
                    return false;
            }

            // all ok by some way or another, skip normal check
            break;
        case SPELL_EFFECT_SKIN_PLAYER_CORPSE:
        {
            if (!m_targets.GetCorpseTargetGUID())
            {
                if (target->IsWithinLOSInMap(m_caster, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2) && target->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE))
                    return true;

                return false;
            }

            Corpse* corpse = ObjectAccessor::GetCorpse(*m_caster, m_targets.GetCorpseTargetGUID());
            if (!corpse)
                return false;

            if (target->GetGUID() != corpse->GetOwnerGUID())
                return false;

            if (!corpse->HasFlag(CORPSE_FIELD_FLAGS, CORPSE_FLAG_LOOTABLE))
                return false;

            if (!corpse->IsWithinLOSInMap(m_caster, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
                return false;

            break;
        }
        default:                                            // normal case
        {
            if (!losPosition || m_spellInfo->HasAttribute(SPELL_ATTR5_ALWAYS_AOE_LINE_OF_SIGHT))
            {
                // Get GO cast coordinates if original caster -> GO
                WorldObject* caster = nullptr;
                if (m_originalCasterGUID.IsGameObject())
                    caster = m_caster->GetMap()->GetGameObject(m_originalCasterGUID);
                if (!caster)
                    caster = m_caster;
                if (target != m_caster && !target->IsWithinLOSInMap(caster, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
                    return false;
            }

            if (losPosition)
                if (!target->IsWithinLOS(losPosition->GetPositionX(), losPosition->GetPositionY(), losPosition->GetPositionZ(), LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
                    return false;
            break;
        }
    }

    return true;
}

bool Spell::IsTriggered() const
{
    return (_triggeredCastFlags & TRIGGERED_FULL_MASK) != 0;
}

bool Spell::IsIgnoringCooldowns() const
{
    return (_triggeredCastFlags & TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD) != 0;
}

bool Spell::IsFocusDisabled() const
{
    return (_triggeredCastFlags & TRIGGERED_IGNORE_SET_FACING) != 0;
}

bool Spell::IsProcDisabled() const
{
    return (_triggeredCastFlags & TRIGGERED_DISALLOW_PROC_EVENTS) != 0;
}

bool Spell::IsChannelActive() const
{
    return m_caster->IsUnit() && m_caster->GetUInt32Value(UNIT_CHANNEL_SPELL) != 0;
}

bool Spell::IsAutoActionResetSpell() const
{
    if (IsTriggered())
        return false;

    if (!m_casttime && m_spellInfo->HasAttribute(SPELL_ATTR6_DOESNT_RESET_SWING_TIMER_IF_INSTANT))
        return false;

    switch (m_spellInfo->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_NONE:
        case SPELL_DAMAGE_CLASS_RANGED:
            // Spells with no or ranged damage class always reset swing timers
            return true;
        case SPELL_DAMAGE_CLASS_MAGIC:
        case SPELL_DAMAGE_CLASS_MELEE:
            // Spells with damage class magic or melee reset swing timers when any interrupt flag is given
            return m_spellInfo->InterruptFlags.HasAnyFlag();
    }

    return true;
}

bool Spell::IsPositive() const
{
    return m_spellInfo->IsPositive() && (!m_triggeredByAuraSpell || m_triggeredByAuraSpell->IsPositive());
}

bool Spell::IsNeedSendToClient() const
{
    return m_spellInfo->SpellVisual[0] || m_spellInfo->SpellVisual[1] || m_spellInfo->IsChanneled() ||
        m_spellInfo->HasAttribute(SPELL_ATTR8_AURA_SEND_AMOUNT) || m_spellInfo->Speed > 0.0f || (!m_triggeredByAuraSpell && !IsTriggered());
}

SpellEvent::SpellEvent(Spell* spell) : BasicEvent()
{
    m_Spell = spell;
}

SpellEvent::~SpellEvent()
{
    if (m_Spell->getState() != SPELL_STATE_FINISHED)
        m_Spell->cancel();

    if (m_Spell->IsDeletable())
    {
        delete m_Spell;
    }
    else
    {
        TC_LOG_ERROR("spells", "~SpellEvent: %s %u tried to delete non-deletable spell %u. Was not deleted, causes memory leak.",
            (m_Spell->GetCaster()->GetTypeId() == TYPEID_PLAYER ? "Player" : "Creature"), m_Spell->GetCaster()->GetGUID().GetCounter(), m_Spell->m_spellInfo->Id);
        ABORT();
    }
}

bool SpellEvent::Execute(uint64 e_time, uint32 p_time)
{
    // update spell if it is not finished
    if (m_Spell->getState() != SPELL_STATE_FINISHED)
        m_Spell->update(p_time);

    // check spell state to process
    switch (m_Spell->getState())
    {
        case SPELL_STATE_FINISHED:
        {
            // spell was finished, check deletable state
            if (m_Spell->IsDeletable())
            {
                // check, if we do have unfinished triggered spells
                return true;                                // spell is deletable, finish event
            }
            // event will be re-added automatically at the end of routine)
            break;
        }
        case SPELL_STATE_DELAYED:
        {
            // first, check, if we have just started
            if (m_Spell->GetDelayStart() != 0)
            {
                // no, we aren't, do the typical update
                // check, if we have channeled spell on our hands
                /*
                if (m_Spell->m_spellInfo->IsChanneled())
                {
                    // evented channeled spell is processed separately, cast once after delay, and not destroyed till finish
                    // check, if we have casting anything else except this channeled spell and autorepeat
                    if (m_Spell->GetCaster()->IsNonMeleeSpellCast(false, true, true))
                    {
                        // another non-melee non-delayed spell is cast now, abort
                        m_Spell->cancel();
                    }
                    else
                    {
                        // Set last not triggered spell for apply spellmods
                        ((Player*)m_Spell->GetCaster())->SetSpellModTakingSpell(m_Spell, true);
                        // do the action (pass spell to channeling state)
                        m_Spell->handle_immediate();

                        // And remove after effect handling
                        ((Player*)m_Spell->GetCaster())->SetSpellModTakingSpell(m_Spell, false);
                    }
                    // event will be re-added automatically at the end of routine)
                }
                else
                */
                {
                    // run the spell handler and think about what we can do next
                    uint64 t_offset = e_time - m_Spell->GetDelayStart();
                    uint64 n_offset = m_Spell->handle_delayed(t_offset);
                    if (n_offset)
                    {
                        // re-add us to the queue
                        m_Spell->GetCaster()->m_Events.AddEvent(this, m_Spell->GetDelayStart() + n_offset, false);
                        return false;                       // event not complete
                    }
                    // event complete
                    // finish update event will be re-added automatically at the end of routine)
                }
            }
            else
            {
                // delaying had just started, record the moment
                m_Spell->SetDelayStart(e_time);
                // re-plan the event for the delay moment
                m_Spell->GetCaster()->m_Events.AddEvent(this, e_time + m_Spell->GetDelayMoment(), false);
                return false;                               // event not complete
            }
            break;
        }
        default:
        {
            // all other states
            // event will be re-added automatically at the end of routine)
            break;
        }
    }

    // spell processing not complete, plan event on the next update interval
    m_Spell->GetCaster()->m_Events.AddEvent(this, e_time + 1, false);
    return false;                                           // event not complete
}

void SpellEvent::Abort(uint64 /*e_time*/)
{
    // oops, the spell we try to do is aborted
    if (m_Spell->getState() != SPELL_STATE_FINISHED)
        m_Spell->cancel();
}

bool SpellEvent::IsDeletable() const
{
    return m_Spell->IsDeletable();
}

bool Spell::IsValidDeadOrAliveTarget(Unit const* target) const
{
    if (target->IsAlive())
        return !m_spellInfo->IsRequiringDeadTarget();
    if (m_spellInfo->IsAllowingDeadTarget())
        return true;
    return false;
}

void Spell::HandleLaunchPhase()
{
    // handle effects with SPELL_EFFECT_HANDLE_LAUNCH mode
    for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        // don't do anything for empty effect
        if (!m_spellInfo->Effects[i].IsEffect())
            continue;

        HandleEffects(nullptr, nullptr, nullptr, nullptr, i, SPELL_EFFECT_HANDLE_LAUNCH);
    }

    PrepareTargetProcessing();

    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        float multiplier = 1.0f;
        if (m_applyMultiplierMask & (1 << i))
            multiplier = m_spellInfo->Effects[i].CalcDamageMultiplier(m_originalCaster, this);

        for (TargetInfo& target : m_UniqueTargetInfo)
        {
            uint32 mask = target.EffectMask;
            if (!(mask & (1 << i)))
                continue;

            DoEffectOnLaunchTarget(target, multiplier, i);
        }
    }
    FinishTargetProcessing();
}

void Spell::DoEffectOnLaunchTarget(TargetInfo& targetInfo, float multiplier, uint8 effIndex)
{
    Unit* unit = nullptr;
    // In case spell hit target, do all effect on that target
    if (targetInfo.MissCondition == SPELL_MISS_NONE || (targetInfo.MissCondition == SPELL_MISS_BLOCK && !m_spellInfo->HasAttribute(SPELL_ATTR3_COMPLETELY_BLOCKED)))
        unit = m_caster->GetGUID() == targetInfo.TargetGUID ? m_caster->ToUnit() : ObjectAccessor::GetUnit(*m_caster, targetInfo.TargetGUID);
    // In case spell reflect from target, do all effect on caster (if hit)
    else if (targetInfo.MissCondition == SPELL_MISS_REFLECT && targetInfo.ReflectResult == SPELL_MISS_NONE)
        unit = m_caster->ToUnit();

    if (!unit)
        return;

    // This will only cause combat - the target will engage once the projectile hits (in DoAllEffectOnTarget)
    bool triggerCombat = [&]()
    {
        // Basic checks
        if (!m_originalCaster || targetInfo.MissCondition != SPELL_MISS_EVADE
            || m_originalCaster->IsFriendlyTo(unit) // caster must not be friendly with the target
            || m_originalCaster->IsIgnoringCombat() // the caster must not be ignoring combat
            || (m_originalCaster->IsCreature() && m_originalCaster->ToCreature()->IsTrigger())) // the caster must not be a trigger npc. They have aggro spells and AI for that.
            return false;

        // SpellInfo checks
        if (m_spellInfo->IsPositive() && !m_spellInfo->HasEffect(SPELL_EFFECT_DISPEL))
            return false;

        return (m_spellInfo->CausesInitialThreat() || unit->IsEngaged());
    }();

    if (triggerCombat)
        m_originalCaster->SetInCombatWith(unit);

    m_damage = 0;
    m_healing = 0;

    HandleEffects(unit, nullptr, nullptr, nullptr, effIndex, SPELL_EFFECT_HANDLE_LAUNCH_TARGET);

    if (m_originalCaster&& m_damage > 0)
    {
        if (m_spellInfo->Effects[effIndex].IsTargetingArea() || m_spellInfo->Effects[effIndex].IsAreaAuraEffect() || m_spellInfo->Effects[effIndex].IsEffect(SPELL_EFFECT_PERSISTENT_AREA_AURA) || m_spellInfo->HasAttribute(SPELL_ATTR5_TREAT_AS_AREA_EFFECT))
        {
            m_damage = unit->CalculateAOEAvoidance(m_damage, m_spellInfo->SchoolMask, m_originalCaster->GetGUID());

            if (m_originalCaster->GetTypeId() == TYPEID_PLAYER)
            {
                // cap damage of player AOE
                uint32 targetAmount = m_UniqueTargetInfo.size();
                if (targetAmount > 10)
                    m_damage = m_damage * 10 / targetAmount;
            }
        }
    }

    if (m_applyMultiplierMask & (1 << effIndex))
    {
        m_damage = int32(m_damage * m_damageMultipliers[effIndex]);
        m_healing = int32(m_healing * m_damageMultipliers[effIndex]);

        m_damageMultipliers[effIndex] *= multiplier;
    }

    targetInfo.Damage += m_damage;
    targetInfo.Healing += m_healing;

    float critChance = m_spellValue->CriticalChance;
    if (m_originalCaster)
    {
        if (!critChance)
            critChance = m_originalCaster->SpellCritChanceDone(m_spellInfo, m_spellSchoolMask, m_attackType);
        critChance = unit->SpellCritChanceTaken(m_originalCaster, m_spellInfo, m_spellSchoolMask, critChance, m_attackType);
    }

    targetInfo.IsCrit = roll_chance_f(critChance);
}

SpellCastResult Spell::CanOpenLock(uint32 effIndex, uint32 lockId, SkillType& skillId, int32& reqSkillValue, int32& skillValue)
{
    if (!lockId)                                             // possible case for GO and maybe for items.
        return SPELL_CAST_OK;

    Unit const* unitCaster = m_caster->ToUnit();
    if (!unitCaster)
        return SPELL_FAILED_BAD_TARGETS;

    // Get LockInfo
    LockEntry const* lockInfo = sLockStore.LookupEntry(lockId);

    if (!lockInfo)
        return SPELL_FAILED_BAD_TARGETS;

    bool reqKey = false;                                    // some locks not have reqs

    for (int j = 0; j < MAX_LOCK_CASE; ++j)
    {
        switch (lockInfo->Type[j])
        {
            // check key item (many fit cases can be)
            case LOCK_KEY_ITEM:
                if (lockInfo->Index[j] && m_CastItem && m_CastItem->GetEntry() == lockInfo->Index[j])
                    return SPELL_CAST_OK;
                reqKey = true;
                break;
                // check key skill (only single first fit case can be)
            case LOCK_KEY_SKILL:
            {
                reqKey = true;

                // wrong locktype, skip
                if (uint32(m_spellInfo->Effects[effIndex].MiscValue) != lockInfo->Index[j])
                    continue;

                skillId = SkillByLockType(LockType(lockInfo->Index[j]));

                if (skillId != SKILL_NONE)
                {
                    reqSkillValue = lockInfo->Skill[j];

                    // castitem check: rogue using skeleton keys. the skill values should not be added in this case.
                    skillValue = m_CastItem || unitCaster->GetTypeId() != TYPEID_PLAYER ?
                        0 : unitCaster->ToPlayer()->GetSkillValue(skillId);

                    // Pickpocketing is based on Playerlevels
                    if (m_spellInfo->Id == 1804 && skillId == SKILL_LOCKPICKING)
                        skillValue = 5 * unitCaster->getLevel();

                    // skill bonus provided by casting spell (mostly item spells)
                    // add the effect base points modifier from the spell cast (cheat lock / skeleton key etc.)
                    if (m_spellInfo->Effects[effIndex].TargetA.GetTarget() == TARGET_GAMEOBJECT_ITEM_TARGET || m_spellInfo->Effects[effIndex].TargetB.GetTarget() == TARGET_GAMEOBJECT_ITEM_TARGET)
                        skillValue += m_spellInfo->Effects[effIndex].CalcValue();

                    if (skillValue < reqSkillValue)
                        return SPELL_FAILED_LOW_CASTLEVEL;
                }
                return SPELL_CAST_OK;
            }
            case LOCK_KEY_SPELL:
                if (m_spellInfo->Id == lockInfo->Index[j])
                    return SPELL_CAST_OK;
                reqKey = true;
                break;
        }
    }

    if (reqKey)
        return SPELL_FAILED_BAD_TARGETS;

    return SPELL_CAST_OK;
}

void Spell::SetSpellValue(SpellValueMod mod, int32 value)
{
    switch (mod)
    {
        case SPELLVALUE_BASE_POINT0:
            m_spellValue->EffectBasePoints[0] = m_spellInfo->Effects[EFFECT_0].CalcBaseValue(value);
            break;
        case SPELLVALUE_BASE_POINT1:
            m_spellValue->EffectBasePoints[1] = m_spellInfo->Effects[EFFECT_1].CalcBaseValue(value);
            break;
        case SPELLVALUE_BASE_POINT2:
            m_spellValue->EffectBasePoints[2] = m_spellInfo->Effects[EFFECT_2].CalcBaseValue(value);
            break;
        case SPELLVALUE_RADIUS_MOD:
            m_spellValue->RadiusMod = (float)value / 10000;
            break;
        case SPELLVALUE_MAX_TARGETS:
            m_spellValue->MaxAffectedTargets = (uint32)value;
            break;
        case SPELLVALUE_AURA_STACK:
            m_spellValue->AuraStackAmount = uint8(value);
            break;
        case SPELLVALUE_DURATION:
            m_spellValue->Duration = value;
            break;
        default:
            break;
    }
}

void Spell::PrepareTargetProcessing()
{
    AssertEffectExecuteData();
}

void Spell::FinishTargetProcessing()
{
    SendLogExecute();
}

void Spell::InitEffectExecuteData(uint8 effIndex)
{
    ASSERT(effIndex < MAX_SPELL_EFFECTS);
    if (!m_effectExecuteData[effIndex])
    {
        m_effectExecuteData[effIndex] = new ByteBuffer(0x20);
        // first dword - target counter
        *m_effectExecuteData[effIndex] << uint32(1);
    }
    else
    {
        // increase target counter by one
        uint32 count = (*m_effectExecuteData[effIndex]).read<uint32>(0);
        (*m_effectExecuteData[effIndex]).put<uint32>(0, ++count);
    }
}

void Spell::AssertEffectExecuteData() const
{
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        ASSERT(!m_effectExecuteData[i]);
}

void Spell::LoadScripts()
{
    sScriptMgr->CreateSpellScripts(m_spellInfo->Id, m_loadedScripts, this);
    for (auto itr = m_loadedScripts.begin(); itr != m_loadedScripts.end(); ++itr)
    {
        TC_LOG_DEBUG("spells", "Spell::LoadScripts: Script `%s` for spell `%u` is loaded now", (*itr)->_GetScriptName()->c_str(), m_spellInfo->Id);
        (*itr)->Register();
    }
}

void Spell::CallScriptBeforeCastHandlers()
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_BEFORE_CAST);
        auto hookItrEnd = (*scritr)->BeforeCast.end(), hookItr = (*scritr)->BeforeCast.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
            (*hookItr).Call();

        (*scritr)->_FinishScriptCall();
    }
}

void Spell::CallScriptOnCastHandlers()
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_ON_CAST);
        auto hookItrEnd = (*scritr)->OnCast.end(), hookItr = (*scritr)->OnCast.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
            (*hookItr).Call();

        (*scritr)->_FinishScriptCall();
    }
}

void Spell::CallScriptAfterCastHandlers()
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_AFTER_CAST);
        auto hookItrEnd = (*scritr)->AfterCast.end(), hookItr = (*scritr)->AfterCast.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
            (*hookItr).Call();

        (*scritr)->_FinishScriptCall();
    }
}

SpellCastResult Spell::CallScriptCheckCastHandlers()
{
    SpellCastResult retVal = SPELL_CAST_OK;
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_CHECK_CAST);
        auto hookItrEnd = (*scritr)->OnCheckCast.end(), hookItr = (*scritr)->OnCheckCast.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
        {
            SpellCastResult tempResult = (*hookItr).Call();
            if (retVal == SPELL_CAST_OK)
                retVal = tempResult;
        }

        (*scritr)->_FinishScriptCall();
    }
    return retVal;
}

void Spell::CallScriptOnSpellStartHandlers()
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_ON_SPELL_START);
        auto hookItrEnd = (*scritr)->OnSpellStart.end(), hookItr = (*scritr)->OnSpellStart.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
            (*hookItr).Call();

        (*scritr)->_FinishScriptCall();
    }
}

bool Spell::CallScriptEffectHandlers(SpellEffIndex effIndex, SpellEffectHandleMode mode)
{
    // execute script effect handler hooks and check if effects was prevented
    bool preventDefault = false;
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_InitHit();

        HookList<SpellScript::EffectNameHook>::iterator effItr, effEndItr;
        SpellScriptHookType hookType;
        switch (mode)
        {
            case SPELL_EFFECT_HANDLE_LAUNCH:
                effItr = (*scritr)->OnEffectLaunch.begin();
                effEndItr = (*scritr)->OnEffectLaunch.end();
                hookType = SPELL_SCRIPT_HOOK_EFFECT_LAUNCH;
                break;
            case SPELL_EFFECT_HANDLE_LAUNCH_TARGET:
                effItr = (*scritr)->OnEffectLaunchTarget.begin();
                effEndItr = (*scritr)->OnEffectLaunchTarget.end();
                hookType = SPELL_SCRIPT_HOOK_EFFECT_LAUNCH_TARGET;
                break;
            case SPELL_EFFECT_HANDLE_HIT:
                effItr = (*scritr)->OnEffectHit.begin();
                effEndItr = (*scritr)->OnEffectHit.end();
                hookType = SPELL_SCRIPT_HOOK_EFFECT_HIT;
                break;
            case SPELL_EFFECT_HANDLE_HIT_TARGET:
                effItr = (*scritr)->OnEffectHitTarget.begin();
                effEndItr = (*scritr)->OnEffectHitTarget.end();
                hookType = SPELL_SCRIPT_HOOK_EFFECT_HIT_TARGET;
                break;
            default:
                ABORT();
                return false;
        }
        (*scritr)->_PrepareScriptCall(hookType);
        for (; effItr != effEndItr; ++effItr)
            // effect execution can be prevented
            if (!(*scritr)->_IsEffectPrevented(effIndex) && (*effItr).Filter(m_spellInfo, effIndex))
                (*effItr).Call(effIndex);

        if (!preventDefault)
            preventDefault = (*scritr)->_IsDefaultEffectPrevented(effIndex);

        (*scritr)->_FinishScriptCall();
    }
    return preventDefault;
}

void Spell::CallScriptSuccessfulDispel(SpellEffIndex effIndex)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_EFFECT_SUCCESSFUL_DISPEL);
        auto hookItrEnd = (*scritr)->OnEffectSuccessfulDispel.end(), hookItr = (*scritr)->OnEffectSuccessfulDispel.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
            hookItr->Call(effIndex);

        (*scritr)->_FinishScriptCall();
    }
}

void Spell::CallScriptBeforeHitHandlers()
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_InitHit();

        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_BEFORE_HIT);
        auto hookItrEnd = (*scritr)->BeforeHit.end(), hookItr = (*scritr)->BeforeHit.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
            (*hookItr).Call();

        (*scritr)->_FinishScriptCall();
    }
}

void Spell::CallScriptOnHitHandlers()
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_HIT);
        auto hookItrEnd = (*scritr)->OnHit.end(), hookItr = (*scritr)->OnHit.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
            (*hookItr).Call();

        (*scritr)->_FinishScriptCall();
    }
}

void Spell::CallScriptAfterHitHandlers()
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_AFTER_HIT);
        auto hookItrEnd = (*scritr)->AfterHit.end(), hookItr = (*scritr)->AfterHit.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
            (*hookItr).Call();

        (*scritr)->_FinishScriptCall();
    }
}

void Spell::CallScriptObjectAreaTargetSelectHandlers(std::list<WorldObject*>& targets, SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_OBJECT_AREA_TARGET_SELECT);
        auto hookItrEnd = (*scritr)->OnObjectAreaTargetSelect.end(), hookItr = (*scritr)->OnObjectAreaTargetSelect.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
            if (hookItr->Filter(m_spellInfo, effIndex) && targetType.GetTarget() == hookItr->GetTarget())
                hookItr->Call(targets);

        (*scritr)->_FinishScriptCall();
    }
}

void Spell::CallScriptObjectTargetSelectHandlers(WorldObject*& target, SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_OBJECT_TARGET_SELECT);
        auto hookItrEnd = (*scritr)->OnObjectTargetSelect.end(), hookItr = (*scritr)->OnObjectTargetSelect.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
            if (hookItr->Filter(m_spellInfo, effIndex) && targetType.GetTarget() == hookItr->GetTarget())
                hookItr->Call(target);

        (*scritr)->_FinishScriptCall();
    }
}

void Spell::CallScriptDestinationTargetSelectHandlers(SpellDestination& target, SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_DESTINATION_TARGET_SELECT);
        auto hookItrEnd = (*scritr)->OnDestinationTargetSelect.end(), hookItr = (*scritr)->OnDestinationTargetSelect.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
            if (hookItr->Filter(m_spellInfo, effIndex) && targetType.GetTarget() == hookItr->GetTarget())
                hookItr->Call(target);

        (*scritr)->_FinishScriptCall();
    }
}

bool Spell::CheckScriptEffectImplicitTargets(uint32 effIndex, uint32 effIndexToCheck)
{
    // Skip if there are not any script
    if (m_loadedScripts.empty())
        return true;

    for (auto itr = m_loadedScripts.begin(); itr != m_loadedScripts.end(); ++itr)
    {
        auto targetSelectHookEnd = (*itr)->OnObjectTargetSelect.end(), targetSelectHookItr = (*itr)->OnObjectTargetSelect.begin();
        for (; targetSelectHookItr != targetSelectHookEnd; ++targetSelectHookItr)
            if (((*targetSelectHookItr).Filter(m_spellInfo, SpellEffIndex(effIndex)) && !(*targetSelectHookItr).Filter(m_spellInfo, SpellEffIndex(effIndexToCheck))) ||
                (!(*targetSelectHookItr).Filter(m_spellInfo, SpellEffIndex(effIndex)) && (*targetSelectHookItr).Filter(m_spellInfo, SpellEffIndex(effIndexToCheck))))
                return false;

        auto areaTargetSelectHookEnd = (*itr)->OnObjectAreaTargetSelect.end(), areaTargetSelectHookItr = (*itr)->OnObjectAreaTargetSelect.begin();
        for (; areaTargetSelectHookItr != areaTargetSelectHookEnd; ++areaTargetSelectHookItr)
            if (((*areaTargetSelectHookItr).Filter(m_spellInfo, SpellEffIndex(effIndex)) && !(*areaTargetSelectHookItr).Filter(m_spellInfo, SpellEffIndex(effIndexToCheck))) ||
                (!(*areaTargetSelectHookItr).Filter(m_spellInfo, SpellEffIndex(effIndex)) && (*areaTargetSelectHookItr).Filter(m_spellInfo, SpellEffIndex(effIndexToCheck))))
                return false;
    }
    return true;
}

bool Spell::CanExecuteTriggersOnHit(Unit* unit, SpellInfo const* triggeredByAura) const
{
    bool onlyOnTarget = (triggeredByAura && (triggeredByAura->HasAttribute(SPELL_ATTR4_CLASS_TRIGGER_ONLY_ON_TARGET)));
    if (!onlyOnTarget)
        return true;

    // If triggeredByAura has SPELL_ATTR4_CLASS_TRIGGER_ONLY_ON_TARGET then it can only proc on either noncaster units...
    if (unit != m_caster)
        return true;

    // ... or caster if it is the only target
    if (m_UniqueTargetInfo.size() == 1)
        return true;

    return false;
}

void Spell::PrepareTriggersExecutedOnHit()
{
    Unit* unitCaster = m_caster->ToUnit();
    if (!unitCaster)
        return;

    // handle SPELL_AURA_ADD_TARGET_TRIGGER auras:
    // save auras which were present on spell caster on cast, to prevent triggered auras from affecting caster
    // and to correctly calculate proc chance when combopoints are present
    Unit::AuraEffectList const& targetTriggers = unitCaster->GetAuraEffectsByType(SPELL_AURA_ADD_TARGET_TRIGGER);
    for (AuraEffect const* aurEff : targetTriggers)
    {
        if (!aurEff->IsAffectingSpell(m_spellInfo))
            continue;

        SpellInfo const* auraSpellInfo = aurEff->GetSpellInfo();
        uint32 auraSpellIdx = aurEff->GetEffIndex();
        if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(auraSpellInfo->Effects[auraSpellIdx].TriggerSpell))
        {
            // calculate the chance using spell base amount, because aura amount is not updated on combo-points change
            // this possibly needs fixing
            int32 auraBaseAmount = aurEff->GetBaseAmount();
            // proc chance is stored in effect amount
            int32 chance = unitCaster->CalculateSpellDamage(nullptr, auraSpellInfo, auraSpellIdx, &auraBaseAmount);
            chance *= aurEff->GetBase()->GetStackAmount();

            // build trigger and add to the list
            m_hitTriggerSpells.emplace_back(spellInfo, auraSpellInfo, chance);
        }
    }
}

// Global cooldowns management
enum GCDLimits
{
    MIN_GCD = 1000,
    MAX_GCD = 1500
};

bool CanHaveGlobalCooldown(WorldObject const* caster)
{
    // Only players or controlled units have global cooldown
    if (caster->GetTypeId() != TYPEID_PLAYER && (caster->GetTypeId() != TYPEID_UNIT || !const_cast<WorldObject*>(caster)->ToCreature()->GetCharmInfo()))
        return false;

    return true;
}

bool Spell::HasGlobalCooldown() const
{
    if (!CanHaveGlobalCooldown(m_caster))
        return false;

    return m_caster->ToUnit()->GetSpellHistory()->HasGlobalCooldown(m_spellInfo);
}

void Spell::TriggerGlobalCooldown()
{
    if (!CanHaveGlobalCooldown(m_caster))
        return;

    if (!m_spellInfo->StartRecoveryCategory)
        return;

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
        if (m_caster->ToPlayer()->GetCommandStatus(CHEAT_COOLDOWN))
            return;

    // Global cooldown can't leave range 1..1.5 secs
    int32 gcd = m_spellInfo->StartRecoveryTime;

    // gcd modifier auras are applied only to own spells and only players have such mods
    if (Player* modOwner = m_caster->GetSpellModOwner())
        modOwner->ApplySpellMod(m_spellInfo->Id, SpellModOp::StartCooldown, gcd, this);

    // Apply haste rating
    if (m_spellInfo->StartRecoveryCategory == 133 && m_spellInfo->StartRecoveryTime == 1500 &&
        m_spellInfo->DmgClass != SPELL_DAMAGE_CLASS_MELEE && m_spellInfo->DmgClass != SPELL_DAMAGE_CLASS_RANGED &&
        !m_spellInfo->HasAttribute(SPELL_ATTR0_USES_RANGED_SLOT) && !m_spellInfo->HasAttribute(SPELL_ATTR0_IS_ABILITY))
    {
        gcd = int32(float(gcd) * m_caster->ToUnit()->GetFloatValue(UNIT_MOD_CAST_SPEED));
        RoundToInterval<int32>(gcd, MIN_GCD, MAX_GCD);
    }

    if (gcd)
        m_caster->ToUnit()->GetSpellHistory()->AddGlobalCooldown(m_spellInfo, gcd);
}

void Spell::CancelGlobalCooldown()
{
    if (!CanHaveGlobalCooldown(m_caster))
        return;

    if (!m_spellInfo->StartRecoveryTime)
        return;

    // Cancel global cooldown when interrupting current cast
    if (m_caster->ToUnit()->GetCurrentSpell(CURRENT_GENERIC_SPELL) != this)
        return;

    m_caster->ToUnit()->GetSpellHistory()->CancelGlobalCooldown(m_spellInfo);
}

namespace Trinity
{

WorldObjectSpellTargetCheck::WorldObjectSpellTargetCheck(WorldObject* caster, WorldObject* referer, SpellInfo const* spellInfo,
            SpellTargetCheckTypes selectionType, ConditionContainer const* condList) : _caster(caster), _referer(referer), _spellInfo(spellInfo),
    _targetSelectionType(selectionType), _condList(condList)
{
    if (condList)
        _condSrcInfo = std::make_unique<ConditionSourceInfo>(nullptr, caster);
    else
        _condSrcInfo = nullptr;
}

WorldObjectSpellTargetCheck::~WorldObjectSpellTargetCheck()
{
}

bool WorldObjectSpellTargetCheck::operator()(WorldObject* target) const
{
    if (_spellInfo->CheckTarget(_caster, target, true) != SPELL_CAST_OK)
        return false;
    Unit* unitTarget = target->ToUnit();
    if (Corpse* corpse = target->ToCorpse())
    {
        // use owner for party/assistance checks
        if (Player* owner = ObjectAccessor::FindPlayer(corpse->GetOwnerGUID()))
            unitTarget = owner;
        else
            return false;
    }

    Unit* refUnit = _referer->ToUnit();
    if (unitTarget)
    {
        // do only faction checks here
        switch (_targetSelectionType)
        {
            case TARGET_CHECK_ENEMY:
                if (unitTarget->IsTotem())
                    return false;
                if (!target->IsCorpse() && !_caster->IsValidAttackTarget(unitTarget, _spellInfo))
                    return false;
                break;
            case TARGET_CHECK_ALLY:
                if (unitTarget->IsTotem())
                    return false;
                if (!target->IsCorpse() && !_caster->IsValidAssistTarget(unitTarget, _spellInfo))
                    return false;
                break;
            case TARGET_CHECK_PARTY:
                if (!refUnit)
                    return false;
                if (unitTarget->IsTotem())
                    return false;
                if (!target->IsCorpse() && !_caster->IsValidAssistTarget(unitTarget, _spellInfo))
                    return false;
                if (!refUnit->IsInPartyWith(unitTarget))
                    return false;
                break;
            case TARGET_CHECK_RAID_CLASS:
                if (!refUnit)
                    return false;
                if (refUnit->getClass() != unitTarget->getClass())
                    return false;
                [[fallthrough]];
            case TARGET_CHECK_RAID:
                if (!refUnit)
                    return false;
                if (unitTarget->IsTotem())
                    return false;
                if (!target->IsCorpse() && !_caster->IsValidAssistTarget(unitTarget, _spellInfo))
                    return false;
                if (!refUnit->IsInRaidWith(unitTarget))
                    return false;
                break;
            case TARGET_CHECK_SUMMONED:
                if (!unitTarget->IsSummon())
                    return false;
                if (unitTarget->ToTempSummon()->GetSummonerGUID() != _caster->GetGUID())
                    return false;
                break;
            case TARGET_CHECK_THREAT:
                if (!_referer->IsUnit() || _referer->ToUnit()->GetThreatManager().GetThreat(unitTarget, true) <= 0.0f)
                    return false;
                break;
            case TARGET_CHECK_TAP:
                if (_referer->GetTypeId() != TYPEID_UNIT || unitTarget->GetTypeId() != TYPEID_PLAYER)
                    return false;
                if (!_referer->ToCreature()->isTappedBy(unitTarget->ToPlayer()))
                    return false;
                break;
            default:
                break;
        }
    }

    if (!_condSrcInfo)
        return true;
    _condSrcInfo->mConditionTargets[0] = target;
    return sConditionMgr->IsObjectMeetToConditions(*_condSrcInfo, *_condList);
}

WorldObjectSpellNearbyTargetCheck::WorldObjectSpellNearbyTargetCheck(float range, WorldObject* caster, SpellInfo const* spellInfo,
    SpellTargetCheckTypes selectionType, ConditionContainer const* condList)
    : WorldObjectSpellTargetCheck(caster, caster, spellInfo, selectionType, condList), _range(range), _position(caster) { }

bool WorldObjectSpellNearbyTargetCheck::operator()(WorldObject* target)
{
    float dist = target->GetDistance(*_position);
    if (dist < _range && WorldObjectSpellTargetCheck::operator ()(target))
    {
        _range = dist;
        return true;
    }
    return false;
}

WorldObjectSpellAreaTargetCheck::WorldObjectSpellAreaTargetCheck(float range, Position const* position, WorldObject* caster,
    WorldObject* referer, SpellInfo const* spellInfo, SpellTargetCheckTypes selectionType, ConditionContainer const* condList)
    : WorldObjectSpellTargetCheck(caster, referer, spellInfo, selectionType, condList), _range(range), _position(position) { }

bool WorldObjectSpellAreaTargetCheck::operator()(WorldObject* target)
{
    if (target->ToGameObject())
    {
        // isInRange including the dimension of the GO
        bool isInRange = target->ToGameObject()->IsInRange(_position->GetPositionX(), _position->GetPositionY(), _position->GetPositionZ(), _range);
        if (!isInRange)
            return false;
    }
    else if (target->ToUnit())
    {
        float hitboxSum = (_caster->IsUnit() && _spellInfo->HasAttribute(SPELL_ATTR5_TREAT_AS_AREA_EFFECT) && _spellInfo->SpellFamilyName != SPELLFAMILY_GENERIC) ? target->ToUnit()->GetMeleeRange(_caster->ToUnit()) : 0.f;
        bool isInsideCylinder = target->IsWithinDist2d(_position, _range + hitboxSum) && std::abs(target->GetPositionZ() - _position->GetPositionZ()) <= (_range + hitboxSum);
        if (!isInsideCylinder)
            return false;
    }

    return WorldObjectSpellTargetCheck::operator ()(target);
}

WorldObjectSpellConeTargetCheck::WorldObjectSpellConeTargetCheck(Position const& coneSrc, float coneAngle, float range, WorldObject* caster,
    SpellInfo const* spellInfo, SpellTargetCheckTypes selectionType, ConditionContainer const* condList)
    : WorldObjectSpellAreaTargetCheck(range, caster, caster, caster, spellInfo, selectionType, condList), _coneSrc(coneSrc), _coneAngle(coneAngle) { }

bool WorldObjectSpellConeTargetCheck::operator()(WorldObject* target)
{
    if (_spellInfo->HasAttribute(SPELL_ATTR0_CU_CONE_BACK))
    {
        if (_coneSrc.HasInArc(-std::abs(_coneAngle), target))
            return false;
    }
    else if (_spellInfo->HasAttribute(SPELL_ATTR0_CU_CONE_LINE))
    {
        if (!_coneSrc.HasInLine(target, _caster->GetCombatReach(), 0.f))
            return false;
    }
    else
    {
        if (!_caster->IsUnit() || !_caster->ToUnit()->IsWithinBoundaryRadius(target->ToUnit()))
            // ConeAngle > 0 -> select targets in front
            // ConeAngle < 0 -> select targets in back
            if (_coneSrc.HasInArc(_coneAngle, target) != G3D::fuzzyGe(_coneAngle, 0.f))
                return false;
    }
    return WorldObjectSpellAreaTargetCheck::operator ()(target);
}

WorldObjectSpellTrajTargetCheck::WorldObjectSpellTrajTargetCheck(float range, Position const* position, WorldObject* caster, SpellInfo const* spellInfo, SpellTargetCheckTypes selectionType, ConditionContainer const* condList)
    : WorldObjectSpellTargetCheck(caster, caster, spellInfo, selectionType, condList), _range(range), _position(position) { }

bool WorldObjectSpellTrajTargetCheck::operator()(WorldObject* target)
{
    // return all targets on missile trajectory (0 - size of a missile)
    if (!_caster->HasInLine(target, target->GetCombatReach(), TRAJECTORY_MISSILE_SIZE))
        return false;

    if (target->GetExactDist2d(_position) > _range)
        return false;

    return WorldObjectSpellTargetCheck::operator ()(target);
}

} //namespace Trinity

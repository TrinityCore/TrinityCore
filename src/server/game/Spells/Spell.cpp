/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "Common.h"
#include "DatabaseEnv.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Opcodes.h"
#include "Log.h"
#include "UpdateMask.h"
#include "World.h"
#include "ObjectMgr.h"
#include "SpellMgr.h"
#include "Player.h"
#include "Pet.h"
#include "Unit.h"
#include "Totem.h"
#include "Spell.h"
#include "DynamicObject.h"
#include "Group.h"
#include "UpdateData.h"
#include "MapManager.h"
#include "ObjectAccessor.h"
#include "CellImpl.h"
#include "SharedDefines.h"
#include "LootMgr.h"
#include "VMapFactory.h"
#include "Battleground.h"
#include "Util.h"
#include "TemporarySummon.h"
#include "Vehicle.h"
#include "SpellAuraEffects.h"
#include "ScriptMgr.h"
#include "ConditionMgr.h"
#include "DisableMgr.h"
#include "SpellScript.h"
#include "InstanceScript.h"
#include "SpellInfo.h"

extern pEffect SpellEffects[TOTAL_SPELL_EFFECTS];

SpellCastTargets::SpellCastTargets() : m_elevation(0), m_speed(0)
{
    m_objectTarget = NULL;
    m_itemTarget = NULL;

    m_objectTargetGUID   = 0;
    m_itemTargetGUID   = 0;
    m_itemTargetEntry  = 0;

    m_srcTransGUID = 0;
    m_srcTransOffset.Relocate(0, 0, 0, 0);
    m_srcPos.Relocate(0, 0, 0, 0);
    m_dstTransGUID = 0;
    m_dstTransOffset.Relocate(0, 0, 0, 0);
    m_dstPos.Relocate(0, 0, 0, 0);
    m_strTarget = "";
    m_targetMask = 0;
}

SpellCastTargets::~SpellCastTargets()
{
}

void SpellCastTargets::Read(ByteBuffer& data, Unit* caster)
{
    data >> m_targetMask;

    if (m_targetMask == TARGET_FLAG_NONE)
        return;

    if (m_targetMask & (TARGET_FLAG_UNIT | TARGET_FLAG_UNIT_MINIPET | TARGET_FLAG_GAMEOBJECT | TARGET_FLAG_CORPSE_ENEMY | TARGET_FLAG_CORPSE_ALLY))
        data.readPackGUID(m_objectTargetGUID);

    if (m_targetMask & (TARGET_FLAG_ITEM | TARGET_FLAG_TRADE_ITEM))
        data.readPackGUID(m_itemTargetGUID);

    if (m_targetMask & TARGET_FLAG_SOURCE_LOCATION)
    {
        data.readPackGUID(m_srcTransGUID);
        if (m_srcTransGUID)
            data >> m_srcTransOffset.PositionXYZStream();
        else
            data >> m_srcPos.PositionXYZStream();
    }
    else
    {
        m_srcTransGUID = caster->GetTransGUID();
        if (m_srcTransGUID)
            m_srcTransOffset.Relocate(caster->GetTransOffsetX(), caster->GetTransOffsetY(), caster->GetTransOffsetZ(), caster->GetTransOffsetO());
        else
            m_srcPos.Relocate(caster);
    }

    if (m_targetMask & TARGET_FLAG_DEST_LOCATION)
    {
        data.readPackGUID(m_dstTransGUID);
        if (m_dstTransGUID)
            data >> m_dstTransOffset.PositionXYZStream();
        else
            data >> m_dstPos.PositionXYZStream();
    }
    else
    {
        m_dstTransGUID = caster->GetTransGUID();
        if (m_dstTransGUID)
            m_dstTransOffset.Relocate(caster->GetTransOffsetX(), caster->GetTransOffsetY(), caster->GetTransOffsetZ(), caster->GetTransOffsetO());
        else
            m_dstPos.Relocate(caster);
    }

    if (m_targetMask & TARGET_FLAG_STRING)
        data >> m_strTarget;

    Update(caster);
}

void SpellCastTargets::Write(ByteBuffer& data)
{
    data << uint32(m_targetMask);

    if (m_targetMask & (TARGET_FLAG_UNIT | TARGET_FLAG_CORPSE_ALLY | TARGET_FLAG_GAMEOBJECT | TARGET_FLAG_CORPSE_ENEMY | TARGET_FLAG_UNIT_MINIPET))
        data.appendPackGUID(m_objectTargetGUID);

    if (m_targetMask & (TARGET_FLAG_ITEM | TARGET_FLAG_TRADE_ITEM))
    {
        if (m_itemTarget)
            data.append(m_itemTarget->GetPackGUID());
        else
            data << uint8(0);
    }

    if (m_targetMask & TARGET_FLAG_SOURCE_LOCATION)
    {
        data.appendPackGUID(m_srcTransGUID); // relative position guid here - transport for example
        if (m_srcTransGUID)
            data << m_srcTransOffset.PositionXYZStream();
        else
            data << m_srcPos.PositionXYZStream();
    }

    if (m_targetMask & TARGET_FLAG_DEST_LOCATION)
    {
        data.appendPackGUID(m_dstTransGUID); // relative position guid here - transport for example
        if (m_dstTransGUID)
            data << m_dstTransOffset.PositionXYZStream();
        else
            data << m_dstPos.PositionXYZStream();
    }

    if (m_targetMask & TARGET_FLAG_STRING)
        data << m_strTarget;
}

uint64 SpellCastTargets::GetUnitTargetGUID() const
{
    switch (GUID_HIPART(m_objectTargetGUID))
    {
        case HIGHGUID_PLAYER:
        case HIGHGUID_VEHICLE:
        case HIGHGUID_UNIT:
        case HIGHGUID_PET:
            return m_objectTargetGUID;
        default:
            return 0LL;
    }
}

Unit* SpellCastTargets::GetUnitTarget() const
{
    if (m_objectTarget)
        return m_objectTarget->ToUnit();
    return NULL;
}

void SpellCastTargets::SetUnitTarget(Unit* target)
{
    if (!target)
        return;

    m_objectTarget = target;
    m_objectTargetGUID = target->GetGUID();
    m_targetMask |= TARGET_FLAG_UNIT;
}

uint64 SpellCastTargets::GetGOTargetGUID() const
{
    switch (GUID_HIPART(m_objectTargetGUID))
    {
        case HIGHGUID_TRANSPORT:
        case HIGHGUID_MO_TRANSPORT:
        case HIGHGUID_GAMEOBJECT:
            return m_objectTargetGUID;
        default:
            return 0LL;
    }
}

GameObject* SpellCastTargets::GetGOTarget() const
{
    if (m_objectTarget)
        return m_objectTarget->ToGameObject();
    return NULL;
}


void SpellCastTargets::SetGOTarget(GameObject* target)
{
    if (!target)
        return;

    m_objectTarget = target;
    m_objectTargetGUID = target->GetGUID();
    m_targetMask |= TARGET_FLAG_GAMEOBJECT;
}

uint64 SpellCastTargets::GetCorpseTargetGUID() const
{
    switch (GUID_HIPART(m_objectTargetGUID))
    {
        case HIGHGUID_CORPSE:
            return m_objectTargetGUID;
        default:
            return 0LL;
    }
}

Corpse* SpellCastTargets::GetCorpseTarget() const
{
    if (m_objectTarget)
        return m_objectTarget->ToCorpse();
    return NULL;
}

WorldObject* SpellCastTargets::GetObjectTarget() const
{
    return m_objectTarget;
}

uint64 SpellCastTargets::GetObjectTargetGUID() const
{
    return m_objectTargetGUID;
}

void SpellCastTargets::RemoveObjectTarget()
{
    m_objectTarget = NULL;
    m_objectTargetGUID = 0LL;
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
    m_itemTargetGUID = uint64(TRADE_SLOT_NONTRADED);
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

Position const* SpellCastTargets::GetSrc() const
{
    return &m_srcPos;
}

void SpellCastTargets::SetSrc(float x, float y, float z)
{
    m_srcPos.Relocate(x, y, z);
    m_srcTransGUID = 0;
    m_targetMask |= TARGET_FLAG_SOURCE_LOCATION;
}

void SpellCastTargets::SetSrc(Position const& pos)
{
    m_srcPos.Relocate(pos);
    m_srcTransGUID = 0;
    m_targetMask |= TARGET_FLAG_SOURCE_LOCATION;
}

void SpellCastTargets::SetSrc(WorldObject const& wObj)
{
    uint64 guid = wObj.GetTransGUID();
    m_srcTransGUID = guid;
    m_srcTransOffset.Relocate(wObj.GetTransOffsetX(), wObj.GetTransOffsetY(), wObj.GetTransOffsetZ(), wObj.GetTransOffsetO());
    m_srcPos.Relocate(wObj);
    m_targetMask |= TARGET_FLAG_SOURCE_LOCATION;
}

void SpellCastTargets::ModSrc(Position const& pos)
{
    ASSERT(m_targetMask & TARGET_FLAG_SOURCE_LOCATION);

    if (m_srcTransGUID)
    {
        Position offset;
        m_srcPos.GetPositionOffsetTo(pos, offset);
        m_srcTransOffset.RelocateOffset(offset);
    }
    m_srcPos.Relocate(pos);
}

void SpellCastTargets::RemoveSrc()
{
    m_targetMask &= ~(TARGET_FLAG_SOURCE_LOCATION);
}

WorldLocation const* SpellCastTargets::GetDst() const
{
    return &m_dstPos;
}

void SpellCastTargets::SetDst(float x, float y, float z, float orientation, uint32 mapId)
{
    m_dstPos.Relocate(x, y, z, orientation);
    m_dstTransGUID = 0;
    m_targetMask |= TARGET_FLAG_DEST_LOCATION;
    if (mapId != MAPID_INVALID)
        m_dstPos.m_mapId = mapId;
}

void SpellCastTargets::SetDst(Position const& pos)
{
    m_dstPos.Relocate(pos);
    m_dstTransGUID = 0;
    m_targetMask |= TARGET_FLAG_DEST_LOCATION;
}

void SpellCastTargets::SetDst(WorldObject const& wObj)
{
    uint64 guid = wObj.GetTransGUID();
    m_dstTransGUID = guid;
    m_dstTransOffset.Relocate(wObj.GetTransOffsetX(), wObj.GetTransOffsetY(), wObj.GetTransOffsetZ(), wObj.GetTransOffsetO());
    m_dstPos.Relocate(wObj);
    m_targetMask |= TARGET_FLAG_DEST_LOCATION;
}

void SpellCastTargets::SetDst(SpellCastTargets const& spellTargets)
{
    m_dstTransGUID = spellTargets.m_dstTransGUID;
    m_dstTransOffset.Relocate(spellTargets.m_dstTransOffset);
    m_dstPos.Relocate(spellTargets.m_dstPos);
    m_targetMask |= TARGET_FLAG_DEST_LOCATION;
}

void SpellCastTargets::ModDst(Position const& pos)
{
    ASSERT(m_targetMask & TARGET_FLAG_DEST_LOCATION);

    if (m_dstTransGUID)
    {
        Position offset;
        m_dstPos.GetPositionOffsetTo(pos, offset);
        m_dstTransOffset.RelocateOffset(offset);
    }
    m_dstPos.Relocate(pos);
}

void SpellCastTargets::RemoveDst()
{
    m_targetMask &= ~(TARGET_FLAG_DEST_LOCATION);
}

void SpellCastTargets::Update(Unit* caster)
{
    m_objectTarget = m_objectTargetGUID ? ((m_objectTargetGUID == caster->GetGUID()) ? caster : ObjectAccessor::GetWorldObject(*caster, m_objectTargetGUID)) : NULL;

    m_itemTarget = NULL;
    if (caster->GetTypeId() == TYPEID_PLAYER)
    {
        Player* player = caster->ToPlayer();
        if (m_targetMask & TARGET_FLAG_ITEM)
            m_itemTarget = player->GetItemByGuid(m_itemTargetGUID);
        else if (m_targetMask & TARGET_FLAG_TRADE_ITEM)
            if (m_itemTargetGUID == TRADE_SLOT_NONTRADED) // here it is not guid but slot. Also prevents hacking slots
                if (TradeData* pTrade = player->GetTradeData())
                    m_itemTarget = pTrade->GetTraderData()->GetItem(TRADE_SLOT_NONTRADED);

        if (m_itemTarget)
            m_itemTargetEntry = m_itemTarget->GetEntry();
    }

    // update positions by transport move
    if (HasSrc() && m_srcTransGUID)
    {
        if (WorldObject* transport = ObjectAccessor::GetWorldObject(*caster, m_srcTransGUID))
        {
            m_srcPos.Relocate(transport);
            m_srcPos.RelocateOffset(m_srcTransOffset);
        }
    }

    if (HasDst() && m_dstTransGUID)
    {
        if (WorldObject* transport = ObjectAccessor::GetWorldObject(*caster, m_dstTransGUID))
        {
            m_dstPos.Relocate(transport);
            m_dstPos.RelocateOffset(m_dstTransOffset);
        }
    }
}

void SpellCastTargets::OutDebug() const
{
    if (!m_targetMask)
        sLog->outString("No targets");

    sLog->outString("target mask: %u", m_targetMask);
    if (m_targetMask & (TARGET_FLAG_UNIT_MASK | TARGET_FLAG_CORPSE_MASK | TARGET_FLAG_GAMEOBJECT_MASK))
        sLog->outString("Object target: " UI64FMTD, m_objectTargetGUID);
    if (m_targetMask & TARGET_FLAG_ITEM)
        sLog->outString("Item target: " UI64FMTD, m_itemTargetGUID);
    if (m_targetMask & TARGET_FLAG_TRADE_ITEM)
        sLog->outString("Trade item target: " UI64FMTD, m_itemTargetGUID);
    if (m_targetMask & TARGET_FLAG_SOURCE_LOCATION)
        sLog->outString("Source location: transport guid:" UI64FMTD " trans offset: %s position: %s", m_srcTransGUID, m_srcTransOffset.ToString().c_str(), m_srcPos.ToString().c_str());
    if (m_targetMask & TARGET_FLAG_DEST_LOCATION)
        sLog->outString("Destination location: transport guid:" UI64FMTD " trans offset: %s position: %s", m_dstTransGUID, m_dstTransOffset.ToString().c_str(), m_dstPos.ToString().c_str());
    if (m_targetMask & TARGET_FLAG_STRING)
        sLog->outString("String: %s", m_strTarget.c_str());
    sLog->outString("speed: %f", m_speed);
    sLog->outString("elevation: %f", m_elevation);
}

SpellValue::SpellValue(SpellInfo const* proto)
{
    for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        EffectBasePoints[i] = proto->Effects[i].BasePoints;
    MaxAffectedTargets = proto->MaxAffectedTargets;
    RadiusMod = 1.0f;
    AuraStackAmount = 1;
}

Spell::Spell(Unit* caster, SpellInfo const* info, TriggerCastFlags triggerFlags, uint64 originalCasterGUID, bool skipCheck) :
m_spellInfo(sSpellMgr->GetSpellForDifficultyFromSpell(info, caster)),
m_caster((info->AttributesEx6 & SPELL_ATTR6_CAST_BY_CHARMER && caster->GetCharmerOrOwner()) ? caster->GetCharmerOrOwner() : caster)
, m_spellValue(new SpellValue(m_spellInfo))
{
    m_customError = SPELL_CUSTOM_ERROR_NONE;
    m_skipCheck = skipCheck;
    m_selfContainer = NULL;
    m_referencedFromCurrentSpell = false;
    m_executedCurrently = false;
    m_needComboPoints = m_spellInfo->NeedsComboPoints();
    m_comboPointGain = 0;
    m_delayStart = 0;
    m_delayAtDamageCount = 0;

    m_applyMultiplierMask = 0;
    m_effectMask = 0;
    m_auraScaleMask = 0;

    // Get data for type of attack
    switch (m_spellInfo->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_MELEE:
            if (m_spellInfo->AttributesEx3 & SPELL_ATTR3_REQ_OFFHAND)
                m_attackType = OFF_ATTACK;
            else
                m_attackType = BASE_ATTACK;
            break;
        case SPELL_DAMAGE_CLASS_RANGED:
            m_attackType = m_spellInfo->IsRangedWeaponSpell() ? RANGED_ATTACK : BASE_ATTACK;
            break;
        default:
                                                            // Wands
            if (m_spellInfo->AttributesEx2 & SPELL_ATTR2_AUTOREPEAT_FLAG)
                m_attackType = RANGED_ATTACK;
            else
                m_attackType = BASE_ATTACK;
            break;
    }

    m_spellSchoolMask = info->GetSchoolMask();           // Can be override for some spell (wand shoot for example)

    if (m_attackType == RANGED_ATTACK)
        // wand case
        if ((m_caster->getClassMask() & CLASSMASK_WAND_USERS) != 0 && m_caster->GetTypeId() == TYPEID_PLAYER)
            if (Item* pItem = m_caster->ToPlayer()->GetWeaponForAttack(RANGED_ATTACK))
                m_spellSchoolMask = SpellSchoolMask(1 << pItem->GetTemplate()->Damage[0].DamageType);

    if (originalCasterGUID)
        m_originalCasterGUID = originalCasterGUID;
    else
        m_originalCasterGUID = m_caster->GetGUID();

    if (m_originalCasterGUID == m_caster->GetGUID())
        m_originalCaster = m_caster;
    else
    {
        m_originalCaster = ObjectAccessor::GetUnit(*m_caster, m_originalCasterGUID);
        if (m_originalCaster && !m_originalCaster->IsInWorld())
            m_originalCaster = NULL;
    }

    m_spellState = SPELL_STATE_NULL;
    _triggeredCastFlags = triggerFlags;
    if (info->AttributesEx4 & SPELL_ATTR4_TRIGGERED)
        _triggeredCastFlags = TRIGGERED_FULL_MASK;

    m_CastItem = NULL;
    m_castItemGUID = 0;

    unitTarget = NULL;
    itemTarget = NULL;
    gameObjTarget = NULL;
    focusObject = NULL;
    m_cast_count = 0;
    m_glyphIndex = 0;
    m_preCastSpell = 0;
    m_triggeredByAuraSpell  = NULL;
    m_spellAura = NULL;

    //Auto Shot & Shoot (wand)
    m_autoRepeat = m_spellInfo->IsAutoRepeatRangedSpell();

    m_runesState = 0;
    m_powerCost = 0;                                        // setup to correct value in Spell::prepare, must not be used before.
    m_casttime = 0;                                         // setup to correct value in Spell::prepare, must not be used before.
    m_timer = 0;                                            // will set to castime in prepare

    m_channelTargetEffectMask = 0;

    // Determine if spell can be reflected back to the caster
    // Patch 1.2 notes: Spell Reflection no longer reflects abilities
    m_canReflect = m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MAGIC && !(m_spellInfo->Attributes & SPELL_ATTR0_ABILITY)
        && !(m_spellInfo->AttributesEx & SPELL_ATTR1_CANT_BE_REFLECTED) && !(m_spellInfo->Attributes & SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY)
        && !m_spellInfo->IsPassive() && !m_spellInfo->IsPositive();

    CleanupTargetList();
    CleanupEffectExecuteData();
}

Spell::~Spell()
{
    // unload scripts
    while(!m_loadedScripts.empty())
    {
        std::list<SpellScript*>::iterator itr = m_loadedScripts.begin();
        (*itr)->_Unload();
        delete (*itr);
        m_loadedScripts.erase(itr);
    }

    if (m_referencedFromCurrentSpell && m_selfContainer && *m_selfContainer == this)
    {
        // Clean the reference to avoid later crash.
        // If this error is repeating, we may have to add an ASSERT to better track down how we get into this case.
        sLog->outError("SPELL: deleting spell for spell ID %u. However, spell still referenced.", m_spellInfo->Id);
        *m_selfContainer = NULL;
    }

    if (m_caster && m_caster->GetTypeId() == TYPEID_PLAYER)
        ASSERT(m_caster->ToPlayer()->m_spellModTakingSpell != this);
    delete m_spellValue;

    CheckEffectExecuteData();
}

template<typename T>
WorldObject* Spell::FindCorpseUsing()
{
    // non-standard target selection
    float max_range = m_spellInfo->GetMaxRange(false);

    CellPair p(Trinity::ComputeCellPair(m_caster->GetPositionX(), m_caster->GetPositionY()));
    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();

    WorldObject* result = NULL;

    T u_check(m_caster, max_range);
    Trinity::WorldObjectSearcher<T> searcher(m_caster, result, u_check);

    TypeContainerVisitor<Trinity::WorldObjectSearcher<T>, GridTypeMapContainer > grid_searcher(searcher);
    cell.Visit(p, grid_searcher, *m_caster->GetMap(), *m_caster, max_range);

    if (!result)
    {
        TypeContainerVisitor<Trinity::WorldObjectSearcher<T>, WorldTypeMapContainer > world_searcher(searcher);
        cell.Visit(p, world_searcher, *m_caster->GetMap(), *m_caster, max_range);
    }

    return result;
}

void Spell::InitExplicitTargets(SpellCastTargets const& targets)
{
    m_targets = targets;
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
            Unit* target = NULL;
            // try to use player selection as a target
            if (Player* playerCaster = m_caster->ToPlayer())
            {
                // selection has to be found and to be valid target for the spell
                if (Unit* selectedUnit = ObjectAccessor::GetUnit(*m_caster, playerCaster->GetSelection()))
                    if (m_spellInfo->CheckExplicitTarget(m_caster, selectedUnit) == SPELL_CAST_OK)
                        target = selectedUnit;
            }
            // try to use attacked unit as a target
            else if ((m_caster->GetTypeId() == TYPEID_UNIT) && neededTargets & (TARGET_FLAG_UNIT_ENEMY | TARGET_FLAG_UNIT))
                target = m_caster->getVictim();
            // didn't find anything - let's use self as target
            if (!target && neededTargets & (TARGET_FLAG_UNIT_RAID | TARGET_FLAG_UNIT_PARTY | TARGET_FLAG_UNIT_ALLY))
                target = m_caster;

            m_targets.SetUnitTarget(target);
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

void Spell::SelectSpellTargets()
{
    uint32 processedTargets = 0;
    for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        // not call for empty effect.
        // Also some spells use not used effect targets for store targets for dummy effect in triggered spells
        if (!m_spellInfo->Effects[i].IsEffect())
            continue;

        if (processedTargets & (1 << i))
            continue;

        // set expected type of implicit targets to be sent to client
        uint32 implicitTargetMask = GetTargetFlagMask(m_spellInfo->Effects[i].TargetA.GetObjectType()) | GetTargetFlagMask(m_spellInfo->Effects[i].TargetB.GetObjectType());
        if (implicitTargetMask & TARGET_FLAG_UNIT)
            m_targets.SetTargetFlag(TARGET_FLAG_UNIT);
        if (implicitTargetMask & (TARGET_FLAG_GAMEOBJECT | TARGET_FLAG_GAMEOBJECT_ITEM))
            m_targets.SetTargetFlag(TARGET_FLAG_GAMEOBJECT);

        uint32 targetA = m_spellInfo->Effects[i].TargetA.GetTarget();
        uint32 targetB = m_spellInfo->Effects[i].TargetB.GetTarget();

        if (targetA)
            processedTargets |= SelectEffectTargets(i, m_spellInfo->Effects[i].TargetA);
        if (targetB)
            processedTargets |= SelectEffectTargets(i, m_spellInfo->Effects[i].TargetB);

        // Select targets of effect based on effect type
        // those are used when no valid target could be added for spell effect based on spell target type
        // some spell effects use explicit target as a default target added to target map (like SPELL_EFFECT_LEARN_SPELL)
        // some spell effects add target to target map only when target type specified (like SPELL_EFFECT_WEAPON)
        // some spell effects don't add anything to target map (confirmed with sniffs) (like SPELL_EFFECT_DESTROY_ALL_TOTEMS)
        SelectEffectTypeImplicitTargets(i);

        if (m_spellInfo->IsChanneled())
        {
            uint8 mask = (1 << i);
            for (std::list<TargetInfo>::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
            {
                if (ihit->effectMask & mask)
                {
                    m_channelTargetEffectMask |= mask;
                    break;
                }
            }
        }
        else if (m_auraScaleMask)
        {
            bool checkLvl = !m_UniqueTargetInfo.empty();
            for (std::list<TargetInfo>::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end();)
            {
                // remove targets which did not pass min level check
                if (m_auraScaleMask && ihit->effectMask == m_auraScaleMask)
                {
                    // Do not check for selfcast
                    if (!ihit->scaleAura && ihit->targetGUID != m_caster->GetGUID())
                    {
                         m_UniqueTargetInfo.erase(ihit++);
                         continue;
                    }
                }
                ++ihit;
            }
            if (checkLvl && m_UniqueTargetInfo.empty())
            {
                SendCastResult(SPELL_FAILED_LOWLEVEL);
                finish(false);
            }
        }
    }

    if (m_targets.HasDst())
    {
        if (m_targets.HasTraj())
        {
            float speed = m_targets.GetSpeedXY();
            if (speed > 0.0f)
                m_delayMoment = (uint64)floor(m_targets.GetDist2d() / speed * 1000.0f);
        }
        else if (m_spellInfo->Speed > 0.0f)
        {
            float dist = m_caster->GetDistance(*m_targets.GetDst());
            m_delayMoment = (uint64) floor(dist / m_spellInfo->Speed * 1000.0f);
        }
    }
}

void Spell::SelectEffectTypeImplicitTargets(uint8 effIndex)
{
    // special case for SPELL_EFFECT_SUMMON_RAF_FRIEND and SPELL_EFFECT_SUMMON_PLAYER
    // TODO: this is a workaround - target shouldn't be stored in target map for those spells
    switch (m_spellInfo->Effects[effIndex].Effect)
    {
        case SPELL_EFFECT_SUMMON_RAF_FRIEND:
        case SPELL_EFFECT_SUMMON_PLAYER:
            if (m_caster->GetTypeId() == TYPEID_PLAYER && m_caster->ToPlayer()->GetSelection())
            {
                Player* target = ObjectAccessor::FindPlayer(m_caster->ToPlayer()->GetSelection());
                if (target)
                    AddUnitTarget(target, 1 << effIndex, false);
            }
            return;
        default:
            break;
    }

    // select spell implicit targets based on effect type
    if (!m_spellInfo->Effects[effIndex].GetImplicitTargetType())
        return;

    uint32 targetMask = m_spellInfo->Effects[effIndex].GetMissingTargetMask();

    if (!targetMask)
        return;

    switch (m_spellInfo->Effects[effIndex].GetImplicitTargetType())
    {
        // add explicit object target or self to the target map 
        case EFFECT_IMPLICIT_TARGET_EXPLICIT:
            // player which not released his spirit is Unit, but target flag for it is TARGET_FLAG_CORPSE_MASK
            if (targetMask & (TARGET_FLAG_UNIT_MASK | TARGET_FLAG_CORPSE_MASK))
            {
                if (Unit* unitTarget = m_targets.GetUnitTarget())
                    AddUnitTarget(unitTarget, 1 << effIndex, false);
                else if (targetMask & TARGET_FLAG_CORPSE_MASK)
                {
                    if (Corpse* corpseTarget = m_targets.GetCorpseTarget())
                    {
                        // TODO: this is a workaround - corpses should be added to spell target map too, but we can't do that so we add owner instead
                        if (Player* owner = ObjectAccessor::FindPlayer(corpseTarget->GetOwnerGUID()))
                            AddUnitTarget(owner, 1 << effIndex, false);
                    }
                }
                else //if (targetMask & TARGET_FLAG_UNIT_MASK)
                {
                    AddUnitTarget(m_caster, 1 << effIndex, false);
                }
            }
            if (targetMask & TARGET_FLAG_ITEM_MASK)
            {
                if (Item* itemTarget = m_targets.GetItemTarget())
                    AddItemTarget(itemTarget, 1 << effIndex);
            }
            if (targetMask & TARGET_FLAG_GAMEOBJECT_MASK)
            {
                if (GameObject* gObjTarget = m_targets.GetGOTarget())
                    AddGOTarget(gObjTarget, 1 << effIndex);
            }
            break;
        // add self to the target map 
        case EFFECT_IMPLICIT_TARGET_CASTER:
            if (targetMask & TARGET_FLAG_UNIT_MASK)
                AddUnitTarget(m_caster, 1 << effIndex, false);
            break;
        // for EFFECT_LEARN_PET_SPELL - maybe should add unitTarget's pet instead of caster's?
        case EFFECT_IMPLICIT_TARGET_PET:
            if (targetMask & TARGET_FLAG_UNIT_MASK)
                if (Guardian* pet = m_caster->GetGuardianPet())
                    AddUnitTarget(pet, 1 << effIndex, false);
            break;
    }
}

void Spell::prepareDataForTriggerSystem(AuraEffect const* /*triggeredByAura*/)
{
    //==========================================================================================
    // Now fill data for trigger system, need know:
    // can spell trigger another or not (m_canTrigger)
    // Create base triggers flags for Attacker and Victim (m_procAttacker, m_procVictim and m_procEx)
    //==========================================================================================

    m_procVictim = m_procAttacker = 0;
    // Get data for type of attack and fill base info for trigger
    switch (m_spellInfo->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_MELEE:
            m_procAttacker = PROC_FLAG_DONE_SPELL_MELEE_DMG_CLASS;
            if (m_attackType == OFF_ATTACK)
                m_procAttacker |= PROC_FLAG_DONE_OFFHAND_ATTACK;
            else
                m_procAttacker |= PROC_FLAG_DONE_MAINHAND_ATTACK;
            m_procVictim   = PROC_FLAG_TAKEN_SPELL_MELEE_DMG_CLASS;
            break;
        case SPELL_DAMAGE_CLASS_RANGED:
            // Auto attack
            if (m_spellInfo->AttributesEx2 & SPELL_ATTR2_AUTOREPEAT_FLAG)
            {
                m_procAttacker = PROC_FLAG_DONE_RANGED_AUTO_ATTACK;
                m_procVictim   = PROC_FLAG_TAKEN_RANGED_AUTO_ATTACK;
            }
            else // Ranged spell attack
            {
                m_procAttacker = PROC_FLAG_DONE_SPELL_RANGED_DMG_CLASS;
                m_procVictim   = PROC_FLAG_TAKEN_SPELL_RANGED_DMG_CLASS;
            }
            break;
        default:
            if (m_spellInfo->EquippedItemClass == ITEM_CLASS_WEAPON &&
                m_spellInfo->EquippedItemSubClassMask & (1<<ITEM_SUBCLASS_WEAPON_WAND)
                && m_spellInfo->AttributesEx2 & SPELL_ATTR2_AUTOREPEAT_FLAG) // Wands auto attack
            {
                m_procAttacker = PROC_FLAG_DONE_RANGED_AUTO_ATTACK;
                m_procVictim   = PROC_FLAG_TAKEN_RANGED_AUTO_ATTACK;
            }
            // For other spells trigger procflags are set in Spell::DoAllEffectOnTarget
            // Because spell positivity is dependant on target
    }
    m_procEx = PROC_EX_NONE;

    // Hunter trap spells - activation proc for Lock and Load, Entrapment and Misdirection
    if (m_spellInfo->SpellFamilyName == SPELLFAMILY_HUNTER &&
        (m_spellInfo->SpellFamilyFlags[0] & 0x18 ||     // Freezing and Frost Trap, Freezing Arrow
        m_spellInfo->Id == 57879 ||                     // Snake Trap - done this way to avoid double proc
        m_spellInfo->SpellFamilyFlags[2] & 0x00024000)) // Explosive and Immolation Trap

        m_procAttacker |= PROC_FLAG_DONE_TRAP_ACTIVATION;

    /* Effects which are result of aura proc from triggered spell cannot proc
        to prevent chain proc of these spells */

    // Hellfire Effect - trigger as DOT
    if (m_spellInfo->SpellFamilyName == SPELLFAMILY_WARLOCK && m_spellInfo->SpellFamilyFlags[0] & 0x00000040)
    {
        m_procAttacker = PROC_FLAG_DONE_PERIODIC;
        m_procVictim   = PROC_FLAG_TAKEN_PERIODIC;
    }

    // Ranged autorepeat attack is set as triggered spell - ignore it
    if (!(m_procAttacker & PROC_FLAG_DONE_RANGED_AUTO_ATTACK))
    {
        if (_triggeredCastFlags & TRIGGERED_DISALLOW_PROC_EVENTS &&
            (m_spellInfo->AttributesEx2 & SPELL_ATTR2_TRIGGERED_CAN_TRIGGER_PROC ||
            m_spellInfo->AttributesEx3 & SPELL_ATTR3_TRIGGERED_CAN_TRIGGER_PROC_2))
            m_procEx |= PROC_EX_INTERNAL_CANT_PROC;
        else if (_triggeredCastFlags & TRIGGERED_DISALLOW_PROC_EVENTS)
            m_procEx |= PROC_EX_INTERNAL_TRIGGERED;
    }
    // Totem casts require spellfamilymask defined in spell_proc_event to proc
    if (m_originalCaster && m_caster != m_originalCaster && m_caster->GetTypeId() == TYPEID_UNIT && m_caster->ToCreature()->isTotem() && m_caster->IsControlledByPlayer())
        m_procEx |= PROC_EX_INTERNAL_REQ_FAMILY;
}

void Spell::CleanupTargetList()
{
    m_UniqueTargetInfo.clear();
    m_UniqueGOTargetInfo.clear();
    m_UniqueItemInfo.clear();
    m_delayMoment = 0;
}

void Spell::AddUnitTarget(Unit* target, uint32 effectMask, bool checkIfValid /*= true*/)
{
    for (uint32 effIndex = 0; effIndex < MAX_SPELL_EFFECTS; ++effIndex)
        if (!m_spellInfo->Effects[effIndex].IsEffect() || !CheckEffectTarget(target, effIndex))
            effectMask &= ~(1 << effIndex);

    // no effects left
    if (!effectMask)
        return;

    if (checkIfValid)
        if (m_spellInfo->CheckTarget(m_caster, target, true) != SPELL_CAST_OK)
            return;

    // Check for effect immune skip if immuned
    for (uint32 effIndex = 0; effIndex < MAX_SPELL_EFFECTS; ++effIndex)
        if (target->IsImmunedToSpellEffect(m_spellInfo, effIndex))
            effectMask &= ~(1 << effIndex);

    uint64 targetGUID = target->GetGUID();

    // Lookup target in already in list
    for (std::list<TargetInfo>::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
    {
        if (targetGUID == ihit->targetGUID)             // Found in list
        {
            ihit->effectMask |= effectMask;             // Immune effects removed from mask
            ihit->scaleAura = false;
            if (m_auraScaleMask && ihit->effectMask == m_auraScaleMask && m_caster != target)
            {
                SpellInfo const* auraSpell = sSpellMgr->GetSpellInfo(sSpellMgr->GetFirstSpellInChain(m_spellInfo->Id));
                if (uint32(target->getLevel() + 10) >= auraSpell->SpellLevel)
                    ihit->scaleAura = true;
            }
            return;
        }
    }

    // This is new target calculate data for him

    // Get spell hit result on target
    TargetInfo targetInfo;
    targetInfo.targetGUID = targetGUID;                         // Store target GUID
    targetInfo.effectMask = effectMask;                         // Store all effects not immune
    targetInfo.processed  = false;                              // Effects not apply on target
    targetInfo.alive      = target->isAlive();
    targetInfo.damage     = 0;
    targetInfo.crit       = false;
    targetInfo.scaleAura  = false;
    if (m_auraScaleMask && targetInfo.effectMask == m_auraScaleMask && m_caster != target)
    {
        SpellInfo const* auraSpell = sSpellMgr->GetSpellInfo(sSpellMgr->GetFirstSpellInChain(m_spellInfo->Id));
        if (uint32(target->getLevel() + 10) >= auraSpell->SpellLevel)
            targetInfo.scaleAura = true;
    }

    // Calculate hit result
    if (m_originalCaster)
    {
        targetInfo.missCondition = m_originalCaster->SpellHitResult(target, m_spellInfo, m_canReflect);
        if (m_skipCheck && targetInfo.missCondition != SPELL_MISS_IMMUNE)
            targetInfo.missCondition = SPELL_MISS_NONE;
    }
    else
        targetInfo.missCondition = SPELL_MISS_EVADE; //SPELL_MISS_NONE;

    // Spell have speed - need calculate incoming time
    // Incoming time is zero for self casts. At least I think so.
    if (m_spellInfo->Speed > 0.0f && m_caster != target)
    {
        // calculate spell incoming interval
        // TODO: this is a hack
        float dist = m_caster->GetDistance(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());

        if (dist < 5.0f)
            dist = 5.0f;
        targetInfo.timeDelay = (uint64) floor(dist / m_spellInfo->Speed * 1000.0f);

        // Calculate minimum incoming time
        if (m_delayMoment == 0 || m_delayMoment > targetInfo.timeDelay)
            m_delayMoment = targetInfo.timeDelay;
    }
    else
        targetInfo.timeDelay = 0LL;

    // If target reflect spell back to caster
    if (targetInfo.missCondition == SPELL_MISS_REFLECT)
    {
        // Calculate reflected spell result on caster
        targetInfo.reflectResult =  m_caster->SpellHitResult(m_caster, m_spellInfo, m_canReflect);

        if (targetInfo.reflectResult == SPELL_MISS_REFLECT)     // Impossible reflect again, so simply deflect spell
            targetInfo.reflectResult = SPELL_MISS_PARRY;

        // Increase time interval for reflected spells by 1.5
        targetInfo.timeDelay += targetInfo.timeDelay >> 1;
    }
    else
        targetInfo.reflectResult = SPELL_MISS_NONE;

    // Add target to list
    m_UniqueTargetInfo.push_back(targetInfo);
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

    uint64 targetGUID = go->GetGUID();

    // Lookup target in already in list
    for (std::list<GOTargetInfo>::iterator ihit = m_UniqueGOTargetInfo.begin(); ihit != m_UniqueGOTargetInfo.end(); ++ihit)
    {
        if (targetGUID == ihit->targetGUID)                 // Found in list
        {
            ihit->effectMask |= effectMask;                 // Add only effect mask
            return;
        }
    }

    // This is new target calculate data for him

    GOTargetInfo target;
    target.targetGUID = targetGUID;
    target.effectMask = effectMask;
    target.processed  = false;                              // Effects not apply on target

    // Spell have speed - need calculate incoming time
    if (m_spellInfo->Speed > 0.0f)
    {
        // calculate spell incoming interval
        float dist = m_caster->GetDistance(go->GetPositionX(), go->GetPositionY(), go->GetPositionZ());
        if (dist < 5.0f)
            dist = 5.0f;
        target.timeDelay = uint64(floor(dist / m_spellInfo->Speed * 1000.0f));
        if (m_delayMoment == 0 || m_delayMoment > target.timeDelay)
            m_delayMoment = target.timeDelay;
    }
    else
        target.timeDelay = 0LL;

    // Add target to list
    m_UniqueGOTargetInfo.push_back(target);
}

void Spell::AddGOTarget(uint64 goGUID, uint32 effectMask)
{
    if (GameObject* go = m_caster->GetMap()->GetGameObject(goGUID))
        AddGOTarget(go, effectMask);
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
    for (std::list<ItemTargetInfo>::iterator ihit = m_UniqueItemInfo.begin(); ihit != m_UniqueItemInfo.end(); ++ihit)
    {
        if (item == ihit->item)                            // Found in list
        {
            ihit->effectMask |= effectMask;                 // Add only effect mask
            return;
        }
    }

    // This is new target add data

    ItemTargetInfo target;
    target.item       = item;
    target.effectMask = effectMask;

    m_UniqueItemInfo.push_back(target);
}

void Spell::DoAllEffectOnTarget(TargetInfo* target)
{
    if (!target || target->processed)
        return;

    target->processed = true;                               // Target checked in apply effects procedure

    // Get mask of effects for target
    uint8 mask = target->effectMask;

    Unit* unit = m_caster->GetGUID() == target->targetGUID ? m_caster : ObjectAccessor::GetUnit(*m_caster, target->targetGUID);
    if (!unit)
    {
        uint8 farMask = 0;
        // create far target mask
        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            if (m_spellInfo->Effects[i].IsFarUnitTargetEffect())
                if ((1 << i) & mask)
                    farMask |= (1 << i);

        if (!farMask)
            return;
        // find unit in world
        unit = ObjectAccessor::FindUnit(target->targetGUID);
        if (!unit)
            return;

        // do far effects on the unit
        // can't use default call because of threading, do stuff as fast as possible
        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            if (farMask & (1 << i))
                HandleEffects(unit, NULL, NULL, i);
        return;
    }

    if (unit->isAlive() != target->alive)
        return;

    if (getState() == SPELL_STATE_DELAYED && !m_spellInfo->IsPositive() && (getMSTime() - target->timeDelay) <= unit->m_lastSanctuaryTime)
        return;                                             // No missinfo in that case

    // Get original caster (if exist) and calculate damage/healing from him data
    Unit* caster = m_originalCaster ? m_originalCaster : m_caster;

    // Skip if m_originalCaster not avaiable
    if (!caster)
        return;

    SpellMissInfo missInfo = target->missCondition;

    // Need init unitTarget by default unit (can changed in code on reflect)
    // Or on missInfo != SPELL_MISS_NONE unitTarget undefined (but need in trigger subsystem)
    unitTarget = unit;

    // Reset damage/healing counter
    m_damage = target->damage;
    m_healing = -target->damage;

    // Fill base trigger info
    uint32 procAttacker = m_procAttacker;
    uint32 procVictim   = m_procVictim;
    uint32 procEx = m_procEx;

    m_spellAura = NULL; // Set aura to null for every target-make sure that pointer is not used for unit without aura applied

                            //Spells with this flag cannot trigger if effect is casted on self
                            // Slice and Dice, relentless strikes, eviscerate
    bool canEffectTrigger = !(m_spellInfo->AttributesEx3 & SPELL_ATTR3_CANT_TRIGGER_PROC) && unitTarget->CanProc() && CanExecuteTriggersOnHit(mask);
    Unit* spellHitTarget = NULL;

    if (missInfo == SPELL_MISS_NONE)                          // In case spell hit target, do all effect on that target
        spellHitTarget = unit;
    else if (missInfo == SPELL_MISS_REFLECT)                // In case spell reflect from target, do all effect on caster (if hit)
    {
        if (target->reflectResult == SPELL_MISS_NONE)       // If reflected spell hit caster -> do all effect on him
        {
            spellHitTarget = m_caster;
            if (m_caster->GetTypeId() == TYPEID_UNIT)
                m_caster->ToCreature()->LowerPlayerDamageReq(target->damage);
        }
    }

    if (spellHitTarget)
    {
        SpellMissInfo missInfo = DoSpellHitOnUnit(spellHitTarget, mask, target->scaleAura);
        if (missInfo != SPELL_MISS_NONE)
        {
            if (missInfo != SPELL_MISS_MISS)
                m_caster->SendSpellMiss(unit, m_spellInfo->Id, missInfo);
            m_damage = 0;
            spellHitTarget = NULL;
        }
    }

    // Do not take combo points on dodge and miss
    if (missInfo != SPELL_MISS_NONE && m_needComboPoints &&
            m_targets.GetUnitTargetGUID() == target->targetGUID)
    {
        m_needComboPoints = false;
        // Restore spell mods for a miss/dodge/parry Cold Blood
        // TODO: check how broad this rule should be
        if (m_caster->GetTypeId() == TYPEID_PLAYER && (missInfo == SPELL_MISS_MISS ||
                missInfo == SPELL_MISS_DODGE || missInfo == SPELL_MISS_PARRY))
            m_caster->ToPlayer()->RestoreSpellMods(this, 14177);
    }

    // Trigger info was not filled in spell::preparedatafortriggersystem - we do it now
    if (canEffectTrigger && !procAttacker && !procVictim)
    {
        bool positive = true;
        if (m_damage > 0)
            positive = false;
        else if (!m_healing)
        {
            for (uint8 i = 0; i< MAX_SPELL_EFFECTS; ++i)
                // If at least one effect negative spell is negative hit
                if (mask & (1<<i) && !m_spellInfo->IsPositiveEffect(i))
                {
                    positive = false;
                    break;
                }
        }
        switch (m_spellInfo->DmgClass)
        {
            case SPELL_DAMAGE_CLASS_MAGIC:
                if (positive)
                {
                    procAttacker |= PROC_FLAG_DONE_SPELL_MAGIC_DMG_CLASS_POS;
                    procVictim   |= PROC_FLAG_TAKEN_SPELL_MAGIC_DMG_CLASS_POS;
                }
                else
                {
                    procAttacker |= PROC_FLAG_DONE_SPELL_MAGIC_DMG_CLASS_NEG;
                    procVictim   |= PROC_FLAG_TAKEN_SPELL_MAGIC_DMG_CLASS_NEG;
                }
            break;
            case SPELL_DAMAGE_CLASS_NONE:
                if (positive)
                {
                    procAttacker |= PROC_FLAG_DONE_SPELL_NONE_DMG_CLASS_POS;
                    procVictim   |= PROC_FLAG_TAKEN_SPELL_NONE_DMG_CLASS_POS;
                }
                else
                {
                    procAttacker |= PROC_FLAG_DONE_SPELL_NONE_DMG_CLASS_NEG;
                    procVictim   |= PROC_FLAG_TAKEN_SPELL_NONE_DMG_CLASS_NEG;
                }
            break;
        }
    }
    CallScriptOnHitHandlers();

    // All calculated do it!
    // Do healing and triggers
    if (m_healing > 0)
    {
        bool crit = caster->isSpellCrit(unitTarget, m_spellInfo, m_spellSchoolMask);
        uint32 addhealth = m_healing;
        if (crit)
        {
            procEx |= PROC_EX_CRITICAL_HIT;
            addhealth = caster->SpellCriticalHealingBonus(m_spellInfo, addhealth, NULL);
        }
        else
            procEx |= PROC_EX_NORMAL_HIT;

        // Do triggers for unit (reflect triggers passed on hit phase for correct drop charge)
        if (canEffectTrigger && missInfo != SPELL_MISS_REFLECT)
            caster->ProcDamageAndSpell(unitTarget, procAttacker, procVictim, procEx, addhealth, m_attackType, m_spellInfo, m_triggeredByAuraSpell);

        int32 gain = caster->HealBySpell(unitTarget, m_spellInfo, addhealth, crit);
        unitTarget->getHostileRefManager().threatAssist(caster, float(gain) * 0.5f, m_spellInfo);
        m_healing = gain;
    }
    // Do damage and triggers
    else if (m_damage > 0)
    {
        // Fill base damage struct (unitTarget - is real spell target)
        SpellNonMeleeDamage damageInfo(caster, unitTarget, m_spellInfo->Id, m_spellSchoolMask);

        // Add bonuses and fill damageInfo struct
        caster->CalculateSpellDamageTaken(&damageInfo, m_damage, m_spellInfo, m_attackType,  target->crit);
        caster->DealDamageMods(damageInfo.target, damageInfo.damage, &damageInfo.absorb);

        // Send log damage message to client
        caster->SendSpellNonMeleeDamageLog(&damageInfo);

        procEx |= createProcExtendMask(&damageInfo, missInfo);
        procVictim |= PROC_FLAG_TAKEN_DAMAGE;

        // Do triggers for unit (reflect triggers passed on hit phase for correct drop charge)
        if (canEffectTrigger && missInfo != SPELL_MISS_REFLECT)
        {
            caster->ProcDamageAndSpell(unitTarget, procAttacker, procVictim, procEx, damageInfo.damage, m_attackType, m_spellInfo, m_triggeredByAuraSpell);
            if (caster->GetTypeId() == TYPEID_PLAYER && (m_spellInfo->Attributes & SPELL_ATTR0_STOP_ATTACK_TARGET) == 0 &&
               (m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MELEE || m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_RANGED))
                caster->ToPlayer()->CastItemCombatSpell(unitTarget, m_attackType, procVictim, procEx);
        }

        caster->DealSpellDamage(&damageInfo, true);

        // Haunt
        if (m_spellInfo->SpellFamilyName == SPELLFAMILY_WARLOCK && m_spellInfo->SpellFamilyFlags[1] & 0x40000 && m_spellAura && m_spellAura->GetEffect(1))
        {
            AuraEffect* aurEff = m_spellAura->GetEffect(1);
            aurEff->SetAmount(CalculatePctU(aurEff->GetAmount(), damageInfo.damage));
        }
        m_damage = damageInfo.damage;
    }
    // Passive spell hits/misses or active spells only misses (only triggers)
    else
    {
        // Fill base damage struct (unitTarget - is real spell target)
        SpellNonMeleeDamage damageInfo(caster, unitTarget, m_spellInfo->Id, m_spellSchoolMask);
        procEx |= createProcExtendMask(&damageInfo, missInfo);
        // Do triggers for unit (reflect triggers passed on hit phase for correct drop charge)
        if (canEffectTrigger && missInfo != SPELL_MISS_REFLECT)
            caster->ProcDamageAndSpell(unit, procAttacker, procVictim, procEx, 0, m_attackType, m_spellInfo, m_triggeredByAuraSpell);

        // Failed Pickpocket, reveal rogue
        if (missInfo == SPELL_MISS_RESIST && m_spellInfo->AttributesCu & SPELL_ATTR0_CU_PICKPOCKET && unitTarget->GetTypeId() == TYPEID_UNIT)
        {
            m_caster->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TALK);
            if (unitTarget->ToCreature()->IsAIEnabled)
                unitTarget->ToCreature()->AI()->AttackStart(m_caster);
        }
    }

    if (missInfo != SPELL_MISS_EVADE && m_caster && !m_caster->IsFriendlyTo(unit) && !m_spellInfo->IsPositive())
    {
        m_caster->CombatStart(unit, !(m_spellInfo->AttributesEx3 & SPELL_ATTR3_NO_INITIAL_AGGRO));

        if (m_spellInfo->AttributesCu & SPELL_ATTR0_CU_AURA_CC)
            if (!unit->IsStandState())
                unit->SetStandState(UNIT_STAND_STATE_STAND);
    }

    if (spellHitTarget)
    {
        //AI functions
        if (spellHitTarget->GetTypeId() == TYPEID_UNIT)
        {
            if (spellHitTarget->ToCreature()->IsAIEnabled)
                spellHitTarget->ToCreature()->AI()->SpellHit(m_caster, m_spellInfo);

            // cast at creature (or GO) quest objectives update at successful cast finished (+channel finished)
            // ignore pets or autorepeat/melee casts for speed (not exist quest for spells (hm...)
            if (m_originalCaster && m_originalCaster->IsControlledByPlayer() && !spellHitTarget->ToCreature()->isPet() && !IsAutoRepeat() && !IsNextMeleeSwingSpell() && !IsChannelActive())
                if (Player* p = m_originalCaster->GetCharmerOrOwnerPlayerOrPlayerItself())
                    p->CastedCreatureOrGO(spellHitTarget->GetEntry(), spellHitTarget->GetGUID(), m_spellInfo->Id);
        }

        if (m_caster->GetTypeId() == TYPEID_UNIT && m_caster->ToCreature()->IsAIEnabled)
            m_caster->ToCreature()->AI()->SpellHitTarget(spellHitTarget, m_spellInfo);

        // Needs to be called after dealing damage/healing to not remove breaking on damage auras
        DoTriggersOnSpellHit(spellHitTarget, mask);

        // if target is fallged for pvp also flag caster if a player
        if (unit->IsPvP() && m_caster->GetTypeId() == TYPEID_PLAYER)
            m_caster->ToPlayer()->UpdatePvP(true);

        CallScriptAfterHitHandlers();
    }
}

SpellMissInfo Spell::DoSpellHitOnUnit(Unit* unit, const uint32 effectMask, bool scaleAura)
{
    if (!unit || !effectMask)
        return SPELL_MISS_EVADE;

    // Recheck immune (only for delayed spells)
    if (m_spellInfo->Speed && (unit->IsImmunedToDamage(m_spellInfo) || unit->IsImmunedToSpell(m_spellInfo)))
        return SPELL_MISS_IMMUNE;

    PrepareScriptHitHandlers();
    CallScriptBeforeHitHandlers();

    if (unit->GetTypeId() == TYPEID_PLAYER)
    {
        unit->ToPlayer()->GetAchievementMgr().StartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_SPELL_TARGET, m_spellInfo->Id);
        unit->ToPlayer()->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, m_spellInfo->Id, 0, m_caster);
        unit->ToPlayer()->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2, m_spellInfo->Id);
    }

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        m_caster->ToPlayer()->GetAchievementMgr().StartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_SPELL_CASTER, m_spellInfo->Id);
        m_caster->ToPlayer()->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL2, m_spellInfo->Id, 0, unit);
    }

    if (m_caster != unit)
    {
        // Recheck  UNIT_FLAG_NON_ATTACKABLE for delayed spells
        if (m_spellInfo->Speed > 0.0f && unit->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE) && unit->GetCharmerOrOwnerGUID() != m_caster->GetGUID())
            return SPELL_MISS_EVADE;

        if (m_caster->IsValidAttackTarget(unit))
        {
            unit->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_HITBYSPELL);
            //TODO: This is a hack. But we do not know what types of stealth should be interrupted by CC
            if ((m_spellInfo->AttributesCu & SPELL_ATTR0_CU_AURA_CC) && unit->IsControlledByPlayer())
                unit->RemoveAurasByType(SPELL_AURA_MOD_STEALTH);
        }
        else if (m_caster->IsFriendlyTo(unit))
        {
            // for delayed spells ignore negative spells (after duel end) for friendly targets
            // TODO: this cause soul transfer bugged
            if (m_spellInfo->Speed > 0.0f && unit->GetTypeId() == TYPEID_PLAYER && !m_spellInfo->IsPositive())
                return SPELL_MISS_EVADE;

            // assisting case, healing and resurrection
            if (unit->HasUnitState(UNIT_STAT_ATTACK_PLAYER))
            {
                m_caster->SetContestedPvP();
                if (m_caster->GetTypeId() == TYPEID_PLAYER)
                    m_caster->ToPlayer()->UpdatePvP(true);
            }
            if (unit->isInCombat() && !(m_spellInfo->AttributesEx3 & SPELL_ATTR3_NO_INITIAL_AGGRO))
            {
                m_caster->SetInCombatState(unit->GetCombatTimer() > 0, unit);
                unit->getHostileRefManager().threatAssist(m_caster, 0.0f);
            }
        }
    }

    // Get Data Needed for Diminishing Returns, some effects may have multiple auras, so this must be done on spell hit, not aura add
    m_diminishGroup = GetDiminishingReturnsGroupForSpell(m_spellInfo, m_triggeredByAuraSpell);
    if (m_diminishGroup)
    {
        m_diminishLevel = unit->GetDiminishing(m_diminishGroup);
        DiminishingReturnsType type = GetDiminishingReturnsGroupType(m_diminishGroup);
        // Increase Diminishing on unit, current informations for actually casts will use values above
        if ((type == DRTYPE_PLAYER && unit->GetCharmerOrOwnerPlayerOrPlayerItself()) || type == DRTYPE_ALL)
            unit->IncrDiminishing(m_diminishGroup);
    }

    uint8 aura_effmask = 0;
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        if (effectMask & (1 << i) && m_spellInfo->Effects[i].IsUnitOwnedAuraEffect())
            aura_effmask |= 1 << i;

    if (aura_effmask)
    {
        // Select rank for aura with level requirements only in specific cases
        // Unit has to be target only of aura effect, both caster and target have to be players, target has to be other than unit target
        SpellInfo const* aurSpellInfo = m_spellInfo;
        int32 basePoints[3];
        if (scaleAura)
        {
            aurSpellInfo = m_spellInfo->GetAuraRankForLevel(unitTarget->getLevel());
            ASSERT(aurSpellInfo);
            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            {
                basePoints[i] = aurSpellInfo->Effects[i].BasePoints;
                if (m_spellInfo->Effects[i].Effect != aurSpellInfo->Effects[i].Effect)
                {
                    aurSpellInfo = m_spellInfo;
                    break;
                }
            }
        }

        if (m_originalCaster)
        {
            bool refresh = false;
            m_spellAura = Aura::TryRefreshStackOrCreate(aurSpellInfo, effectMask, unit,
                m_originalCaster, (aurSpellInfo == m_spellInfo)? &m_spellValue->EffectBasePoints[0] : &basePoints[0], m_CastItem, 0, &refresh);
            if (m_spellAura)
            {
                // Set aura stack amount to desired value
                if (m_spellValue->AuraStackAmount > 1)
                {
                    if (!refresh)
                        m_spellAura->SetStackAmount(m_spellValue->AuraStackAmount);
                    else
                        m_spellAura->ModStackAmount(m_spellValue->AuraStackAmount);
                }

                // Now Reduce spell duration using data received at spell hit
                int32 duration = m_spellAura->GetMaxDuration();
                int32 limitduration = GetDiminishingReturnsLimitDuration(m_diminishGroup, aurSpellInfo);
                float diminishMod = unit->ApplyDiminishingToDuration(m_diminishGroup, duration, m_originalCaster, m_diminishLevel, limitduration);

                // unit is immune to aura if it was diminished to 0 duration
                if (diminishMod == 0.0f)
                {
                    m_spellAura->Remove();
                    bool found = false;
                    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                        if (effectMask & (1 << i) && m_spellInfo->Effects[i].Effect != SPELL_EFFECT_APPLY_AURA)
                            found = true;
                    if (!found)
                        return SPELL_MISS_IMMUNE;
                }
                else
                {
                    ((UnitAura*)m_spellAura)->SetDiminishGroup(m_diminishGroup);

                    bool positive = m_spellAura->GetSpellInfo()->IsPositive();
                    if (AuraApplication* aurApp = m_spellAura->GetApplicationOfTarget(m_originalCaster->GetGUID()))
                        positive = aurApp->IsPositive();

                    duration = m_originalCaster->ModSpellDuration(aurSpellInfo, unit, duration, positive);

                    // Haste modifies duration of channeled spells
                    if (m_spellInfo->IsChanneled())
                    {
                        if (m_spellInfo->AttributesEx5 & SPELL_ATTR5_HASTE_AFFECT_DURATION)
                            m_originalCaster->ModSpellCastTime(aurSpellInfo, duration, this);
                    }
                    // and duration of auras affected by SPELL_AURA_PERIODIC_HASTE
                    else if (m_originalCaster->HasAuraTypeWithAffectMask(SPELL_AURA_PERIODIC_HASTE, aurSpellInfo) || m_spellInfo->AttributesEx5 & SPELL_ATTR5_HASTE_AFFECT_DURATION)
                        duration = int32(duration * m_originalCaster->GetFloatValue(UNIT_MOD_CAST_SPEED));

                    if (duration != m_spellAura->GetMaxDuration())
                    {
                        m_spellAura->SetMaxDuration(duration);
                        m_spellAura->SetDuration(duration);
                    }
                    m_spellAura->_RegisterForTargets();
                }
            }
        }
    }

    for (uint32 effectNumber = 0; effectNumber < MAX_SPELL_EFFECTS; ++effectNumber)
        if (effectMask & (1 << effectNumber))
            HandleEffects(unit, NULL, NULL, effectNumber);

    return SPELL_MISS_NONE;
}

void Spell::DoTriggersOnSpellHit(Unit* unit, uint8 effMask)
{
    // Apply additional spell effects to target
    // TODO: move this code to scripts
    if (m_preCastSpell)
    {
        // Paladin immunity shields
        if (m_preCastSpell == 61988)
        {
            // Cast Forbearance
            m_caster->CastSpell(unit, 25771, true);
            // Cast Avenging Wrath Marker
            unit->CastSpell(unit, 61987, true);
        }

        // Avenging Wrath
        if (m_preCastSpell == 61987)
            // Cast the serverside immunity shield marker
            m_caster->CastSpell(unit, 61988, true);

        if (sSpellMgr->GetSpellInfo(m_preCastSpell))
            // Blizz seems to just apply aura without bothering to cast
            m_caster->AddAura(m_preCastSpell, unit);
    }

    // handle SPELL_AURA_ADD_TARGET_TRIGGER auras
    // this is executed after spell proc spells on target hit
    // spells are triggered for each hit spell target
    // info confirmed with retail sniffs of permafrost and shadow weaving
    if (!m_hitTriggerSpells.empty() && CanExecuteTriggersOnHit(effMask))
    {
        int _duration = 0;
        for (HitTriggerSpells::const_iterator i = m_hitTriggerSpells.begin(); i != m_hitTriggerSpells.end(); ++i)
        {
            if (roll_chance_i(i->second))
            {
                m_caster->CastSpell(unit, i->first, true);
                sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "Spell %d triggered spell %d by SPELL_AURA_ADD_TARGET_TRIGGER aura", m_spellInfo->Id, i->first->Id);

                // SPELL_AURA_ADD_TARGET_TRIGGER auras shouldn't trigger auras without duration
                // set duration of current aura to the triggered spell
                if (i->first->GetDuration() == -1)
                {
                    if (Aura* triggeredAur = unit->GetAura(i->first->Id, m_caster->GetGUID()))
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
    // TODO: remove/cleanup this, as this table is not documented and people are doing stupid things with it
    if (std::vector<int32> const* spellTriggered = sSpellMgr->GetSpellLinked(m_spellInfo->Id + SPELL_LINK_HIT))
        for (std::vector<int32>::const_iterator i = spellTriggered->begin(); i != spellTriggered->end(); ++i)
            if (*i < 0)
                unit->RemoveAurasDueToSpell(-(*i));
            else
                unit->CastSpell(unit, *i, true, 0, 0, m_caster->GetGUID());
}

void Spell::DoAllEffectOnTarget(GOTargetInfo* target)
{
    if (target->processed)                                  // Check target
        return;
    target->processed = true;                               // Target checked in apply effects procedure

    uint32 effectMask = target->effectMask;
    if (!effectMask)
        return;

    GameObject* go = m_caster->GetMap()->GetGameObject(target->targetGUID);
    if (!go)
        return;

    PrepareScriptHitHandlers();
    CallScriptBeforeHitHandlers();

    for (uint32 effectNumber = 0; effectNumber < MAX_SPELL_EFFECTS; ++effectNumber)
        if (effectMask & (1 << effectNumber))
            HandleEffects(NULL, NULL, go, effectNumber);

    CallScriptOnHitHandlers();

    // cast at creature (or GO) quest objectives update at successful cast finished (+channel finished)
    // ignore autorepeat/melee casts for speed (not exist quest for spells (hm...)
    if (m_originalCaster && m_originalCaster->IsControlledByPlayer() && !IsAutoRepeat() && !IsNextMeleeSwingSpell() && !IsChannelActive())
        if (Player* p = m_originalCaster->GetCharmerOrOwnerPlayerOrPlayerItself())
            p->CastedCreatureOrGO(go->GetEntry(), go->GetGUID(), m_spellInfo->Id);
    CallScriptAfterHitHandlers();
}

void Spell::DoAllEffectOnTarget(ItemTargetInfo* target)
{
    uint32 effectMask = target->effectMask;
    if (!target->item || !effectMask)
        return;

    PrepareScriptHitHandlers();
    CallScriptBeforeHitHandlers();

    for (uint32 effectNumber = 0; effectNumber < MAX_SPELL_EFFECTS; ++effectNumber)
        if (effectMask & (1 << effectNumber))
            HandleEffects(NULL, target->item, NULL, effectNumber);

    CallScriptOnHitHandlers();

    CallScriptAfterHitHandlers();
}

bool Spell::UpdateChanneledTargetList()
{
    // Not need check return true
    if (m_channelTargetEffectMask == 0)
        return true;

    uint8 channelTargetEffectMask = m_channelTargetEffectMask;
    uint8 channelAuraMask = 0;
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        if (m_spellInfo->Effects[i].Effect == SPELL_EFFECT_APPLY_AURA)
            channelAuraMask |= 1<<i;

    channelAuraMask &= channelTargetEffectMask;

    float range = 0;
    if (channelAuraMask)
    {
        range = m_spellInfo->GetMaxRange(m_spellInfo->IsPositive());
        if (Player* modOwner = m_caster->GetSpellModOwner())
            modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RANGE, range, this);
    }

    for (std::list<TargetInfo>::iterator ihit= m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
    {
        if (ihit->missCondition == SPELL_MISS_NONE && (channelTargetEffectMask & ihit->effectMask))
        {
            Unit* unit = m_caster->GetGUID() == ihit->targetGUID ? m_caster : ObjectAccessor::GetUnit(*m_caster, ihit->targetGUID);

            if (!unit)
                continue;

            if (IsValidDeadOrAliveTarget(unit))
            {
                if (channelAuraMask & ihit->effectMask)
                {
                    if (AuraApplication * aurApp = unit->GetAuraApplication(m_spellInfo->Id, m_originalCasterGUID))
                    {
                        if (m_caster != unit && !m_caster->IsWithinDistInMap(unit, range))
                        {
                            ihit->effectMask &= ~aurApp->GetEffectMask();
                            unit->RemoveAura(aurApp);
                            continue;
                        }
                    }
                    else // aura is dispelled
                        continue;
                }

                channelTargetEffectMask &= ~ihit->effectMask;   // remove from need alive mask effect that have alive target
            }
        }
    }

    // is all effects from m_needAliveTargetMask have alive targets
    return channelTargetEffectMask == 0;
}

// Helper for Chain Healing
// Spell target first
// Raidmates then descending by injury suffered (MaxHealth - Health)
// Other players/mobs then descending by injury suffered (MaxHealth - Health)
struct ChainHealingOrder : public std::binary_function<const Unit*, const Unit*, bool>
{
    const Unit* MainTarget;
    ChainHealingOrder(Unit const* Target) : MainTarget(Target) {};
    // functor for operator ">"
    bool operator()(Unit const* _Left, Unit const* _Right) const
    {
        return (ChainHealingHash(_Left) < ChainHealingHash(_Right));
    }

    int32 ChainHealingHash(Unit const* Target) const
    {
        if (Target->GetTypeId() == TYPEID_PLAYER && MainTarget->GetTypeId() == TYPEID_PLAYER && Target->ToPlayer()->IsInSameRaidWith(MainTarget->ToPlayer()))
        {
            if (Target->IsFullHealth())
                return 40000;
            else
                return 20000 - Target->GetMaxHealth() + Target->GetHealth();
        }
        else
            return 40000 - Target->GetMaxHealth() + Target->GetHealth();
    }
};

void Spell::SearchChainTarget(std::list<Unit*> &TagUnitMap, float max_range, uint32 num, SpellTargets TargetType)
{
    Unit* cur = m_targets.GetUnitTarget();
    if (!cur)
        return;

    //FIXME: This very like horrible hack and wrong for most spells
    if (m_spellInfo->DmgClass != SPELL_DAMAGE_CLASS_MELEE)
        max_range += num * CHAIN_SPELL_JUMP_RADIUS;

    std::list<Unit*> tempUnitMap;
    if (TargetType == SPELL_TARGETS_CHAINHEAL)
    {
        SearchAreaTarget(tempUnitMap, max_range, PUSH_CHAIN, SPELL_TARGETS_ALLY);
        tempUnitMap.sort(ChainHealingOrder(m_caster));
    }
    else
        SearchAreaTarget(tempUnitMap, max_range, PUSH_CHAIN, TargetType);
    tempUnitMap.remove(cur);

    while (num)
    {
        TagUnitMap.push_back(cur);
        --num;

        if (tempUnitMap.empty())
            break;

        std::list<Unit*>::iterator next;

        if (TargetType == SPELL_TARGETS_CHAINHEAL)
        {
            next = tempUnitMap.begin();
            while (cur->GetDistance(*next) > CHAIN_SPELL_JUMP_RADIUS || !cur->IsWithinLOSInMap(*next))
            {
                ++next;
                if (next == tempUnitMap.end())
                    return;
            }
        }
        else
        {
            tempUnitMap.sort(Trinity::ObjectDistanceOrderPred(cur));
            next = tempUnitMap.begin();

            if (cur->GetDistance(*next) > CHAIN_SPELL_JUMP_RADIUS)      // Don't search beyond the max jump radius
                break;

            // Check if (*next) is a valid chain target. If not, don't add to TagUnitMap, and repeat loop.
            // If you want to add any conditions to exclude a target from TagUnitMap, add condition in this while() loop.
            while ((m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MELEE
                && !m_caster->isInFrontInMap(*next, max_range))
                || !m_caster->canSeeOrDetect(*next)
                || !cur->IsWithinLOSInMap(*next)
                || ((GetSpellInfo()->AttributesEx6 & SPELL_ATTR6_CANT_TARGET_CROWD_CONTROLLED) && !(*next)->CanFreeMove()))
            {
                ++next;
                if (next == tempUnitMap.end() || cur->GetDistance(*next) > CHAIN_SPELL_JUMP_RADIUS) // Don't search beyond the max jump radius
                    return;
            }
        }

        cur = *next;
        tempUnitMap.erase(next);
    }
}

void Spell::SearchAreaTarget(std::list<Unit*> &TagUnitMap, float radius, SpellNotifyPushType type, SpellTargets TargetType, uint32 entry)
{
    if (TargetType == SPELL_TARGETS_GO)
        return;

    Position const* pos;
    switch (type)
    {
        case PUSH_DST_CENTER:
            CheckDst();
            pos = m_targets.GetDst();
            break;
        case PUSH_SRC_CENTER:
            CheckSrc();
            pos = m_targets.GetSrc();
            break;
        case PUSH_CHAIN:
        {
            Unit* target = m_targets.GetUnitTarget();
            if (!target)
            {
                sLog->outError("SPELL: cannot find unit target for spell ID %u\n", m_spellInfo->Id);
                return;
            }
            pos = target;
            break;
        }
        default:
            pos = m_caster;
            break;
    }

    Trinity::SpellNotifierCreatureAndPlayer notifier(m_caster, TagUnitMap, radius, type, TargetType, pos, entry, m_spellInfo);
    if ((m_spellInfo->AttributesEx3 & SPELL_ATTR3_ONLY_TARGET_PLAYERS) || (TargetType == SPELL_TARGETS_ENTRY && !entry))
        m_caster->GetMap()->VisitWorld(pos->m_positionX, pos->m_positionY, radius, notifier);
    else
        m_caster->GetMap()->VisitAll(pos->m_positionX, pos->m_positionY, radius, notifier);
}

void Spell::SearchGOAreaTarget(std::list<GameObject*> &TagGOMap, float radius, SpellNotifyPushType type, SpellTargets TargetType, uint32 entry)
{
    if (TargetType != SPELL_TARGETS_GO)
        return;

    Position const* pos;
    switch (type)
    {
        case PUSH_DST_CENTER:
            CheckDst();
            pos = m_targets.GetDst();
            break;
        case PUSH_SRC_CENTER:
            CheckSrc();
            pos = m_targets.GetSrc();
            break;
        default:
            pos = m_caster;
            break;
    }

    Trinity::GameObjectInRangeCheck check(pos->m_positionX, pos->m_positionY, pos->m_positionZ, radius, entry);
    Trinity::GameObjectListSearcher<Trinity::GameObjectInRangeCheck> searcher(m_caster, TagGOMap, check);
    m_caster->GetMap()->VisitGrid(pos->m_positionX, pos->m_positionY, radius, searcher);
}

WorldObject* Spell::SearchNearbyTarget(float range, SpellTargets TargetType, SpellEffIndex effIndex)
{
    switch (TargetType)
    {
        case SPELL_TARGETS_ENTRY:
        {
            ConditionList conditions = sConditionMgr->GetConditionsForNotGroupedEntry(CONDITION_SOURCE_TYPE_SPELL_SCRIPT_TARGET, m_spellInfo->Id);
            if (conditions.empty())
            {
                sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "Spell (ID: %u) (caster Entry: %u) does not have record in `conditions` for spell script target (ConditionSourceType 13)", m_spellInfo->Id, m_caster->GetEntry());
                if (m_spellInfo->IsPositive())
                    return SearchNearbyTarget(range, SPELL_TARGETS_ALLY, effIndex);
                else
                    return SearchNearbyTarget(range, SPELL_TARGETS_ENEMY, effIndex);
            }

            Creature* creatureScriptTarget = NULL;
            GameObject* goScriptTarget = NULL;

            for (ConditionList::const_iterator i_spellST = conditions.begin(); i_spellST != conditions.end(); ++i_spellST)
            {
                if ((*i_spellST)->mConditionType != CONDITION_SPELL_SCRIPT_TARGET)
                    continue;
                if ((*i_spellST)->mConditionValue3 && !((*i_spellST)->mConditionValue3 & (1 << uint32(effIndex))))
                    continue;
                switch ((*i_spellST)->mConditionValue1)
                {
                    case SPELL_TARGET_TYPE_CONTROLLED:
                        for (Unit::ControlList::iterator itr = m_caster->m_Controlled.begin(); itr != m_caster->m_Controlled.end(); ++itr)
                            if ((*itr)->GetEntry() == (*i_spellST)->mConditionValue2 && (*itr)->IsWithinDistInMap(m_caster, range))
                            {
                                goScriptTarget = NULL;
                                creatureScriptTarget = (*itr)->ToCreature();
                                range = m_caster->GetDistance(creatureScriptTarget);
                            }
                        break;
                    case SPELL_TARGET_TYPE_GAMEOBJECT:
                        if ((*i_spellST)->mConditionValue2)
                        {
                            if (GameObject* go = m_caster->FindNearestGameObject((*i_spellST)->mConditionValue2, range))
                            {
                                // remember found target and range, next attempt will find more near target with another entry
                                goScriptTarget = go;
                                creatureScriptTarget = NULL;
                                range = m_caster->GetDistance(goScriptTarget);
                            }
                        }
                        else if (focusObject)          //Focus Object
                        {
                            float frange = m_caster->GetDistance(focusObject);
                            if (range >= frange)
                            {
                                creatureScriptTarget = NULL;
                                goScriptTarget = focusObject;
                                range = frange;
                            }
                        }
                        break;
                    case SPELL_TARGET_TYPE_CREATURE:
                        if (m_targets.GetUnitTarget() && m_targets.GetUnitTarget()->GetEntry() == (*i_spellST)->mConditionValue2)
                            return m_targets.GetUnitTarget();
                    case SPELL_TARGET_TYPE_DEAD:
                    default:
                        if (Creature* cre = m_caster->FindNearestCreature((*i_spellST)->mConditionValue2, range, (*i_spellST)->mConditionValue1 != SPELL_TARGET_TYPE_DEAD))
                        {
                            creatureScriptTarget = cre;
                            goScriptTarget = NULL;
                            range = m_caster->GetDistance(creatureScriptTarget);
                        }
                        break;
                }
            }

            if (creatureScriptTarget)
                return creatureScriptTarget;
            else
                return goScriptTarget;
        }
        default:
        case SPELL_TARGETS_ENEMY:
        {
            Unit* target = NULL;
            Trinity::AnyUnfriendlyUnitInObjectRangeCheck u_check(m_caster, m_caster, range);
            Trinity::UnitLastSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(m_caster, target, u_check);
            m_caster->VisitNearbyObject(range, searcher);
            return target;
        }
        case SPELL_TARGETS_ALLY:
        {
            Unit* target = NULL;
            Trinity::AnyFriendlyUnitInObjectRangeCheck u_check(m_caster, m_caster, range);
            Trinity::UnitLastSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(m_caster, target, u_check);
            m_caster->VisitNearbyObject(range, searcher);
            return target;
        }
    }
}

uint32 Spell::SelectEffectTargets(uint32 i, SpellImplicitTargetInfo const& cur)
{
    SpellNotifyPushType pushType = PUSH_NONE;
    Player* modOwner = NULL;
    if (m_originalCaster)
        modOwner = m_originalCaster->GetSpellModOwner();

    uint32 effectMask = 1 << i;
    // ENTRY targets may have different selection lists, skip those for now until we can compare lists easily and quickly
    if (GetSpellInfo()->Effects[i].TargetA.GetSelectionCheckType() != TARGET_SELECT_CHECK_ENTRY &&
        GetSpellInfo()->Effects[i].TargetB.GetSelectionCheckType() != TARGET_SELECT_CHECK_ENTRY)
        for (uint32 j = i + 1; j < MAX_SPELL_EFFECTS; ++j)
            if (GetSpellInfo()->Effects[i].TargetA.GetTarget() == GetSpellInfo()->Effects[j].TargetA.GetTarget() &&
                GetSpellInfo()->Effects[i].TargetB.GetTarget() == GetSpellInfo()->Effects[j].TargetB.GetTarget() &&
                GetSpellInfo()->Effects[i].CalcRadius(m_caster) == GetSpellInfo()->Effects[j].CalcRadius(m_caster))
                effectMask |= 1 << j;

    switch (cur.GetType())
    {
        case TARGET_TYPE_UNIT_CASTER:
        {
            switch (cur.GetTarget())
            {
                case TARGET_UNIT_CASTER:
                    AddUnitTarget(m_caster, effectMask, false);
                    break;
                case TARGET_DEST_CASTER_FISHING:
                {
                    float min_dis = m_spellInfo->GetMinRange(true);
                    float max_dis = m_spellInfo->GetMaxRange(true);
                    float dis = (float)rand_norm() * (max_dis - min_dis) + min_dis;
                    float x, y, z, angle;
                    angle = (float)rand_norm() * static_cast<float>(M_PI * 70.0f / 180.0f) - static_cast<float>(M_PI * 35.0f / 180.0f);
                    m_caster->GetClosePoint(x, y, z, DEFAULT_WORLD_OBJECT_SIZE, dis, angle);
                    m_targets.SetDst(x, y, z, m_caster->GetOrientation());
                    break;
                }
                case TARGET_UNIT_MASTER:
                    if (Unit* owner = m_caster->GetCharmerOrOwner())
                        AddUnitTarget(owner, effectMask);
                    break;
                case TARGET_UNIT_PET:
                    if (Guardian* pet = m_caster->GetGuardianPet())
                        AddUnitTarget(pet, effectMask);
                    break;
                case TARGET_UNIT_SUMMONER:
                    if (m_caster->isSummon())
                        if (Unit* unit = m_caster->ToTempSummon()->GetSummoner())
                            AddUnitTarget(unit, effectMask);
                    break;
                case TARGET_UNIT_CASTER_AREA_PARTY:
                case TARGET_UNIT_CASTER_AREA_RAID:
                    pushType = PUSH_CASTER_CENTER;
                    break;
                case TARGET_UNIT_VEHICLE:
                    if (Unit* vehicle = m_caster->GetVehicleBase())
                        AddUnitTarget(vehicle, effectMask);
                    break;
                case TARGET_UNIT_PASSENGER_0:
                case TARGET_UNIT_PASSENGER_1:
                case TARGET_UNIT_PASSENGER_2:
                case TARGET_UNIT_PASSENGER_3:
                case TARGET_UNIT_PASSENGER_4:
                case TARGET_UNIT_PASSENGER_5:
                case TARGET_UNIT_PASSENGER_6:
                case TARGET_UNIT_PASSENGER_7:
                    if (m_caster->GetTypeId() == TYPEID_UNIT && m_caster->ToCreature()->IsVehicle())
                        if (Unit* unit = m_caster->GetVehicleKit()->GetPassenger(cur.GetTarget() - TARGET_UNIT_PASSENGER_0))
                            AddUnitTarget(unit, effectMask);
                    break;
                default:
                    break;
            }
            break;
        }

        case TARGET_TYPE_UNIT_TARGET:
        {
            Unit* target = m_targets.GetUnitTarget();
            if (!target)
            {
                sLog->outError("SPELL: no unit target for spell ID %u", m_spellInfo->Id);
                break;
            }

            switch (cur.GetTarget())
            {
                case TARGET_UNIT_TARGET_ENEMY:
                    if (Unit* magnet = m_caster->SelectMagnetTarget(target, m_spellInfo))
                        if (magnet != target)
                            m_targets.SetUnitTarget(magnet);
                    pushType = PUSH_CHAIN;
                    break;
                case TARGET_UNIT_TARGET_ANY:
                    if (!m_spellInfo->IsPositive())
                        if (Unit* magnet = m_caster->SelectMagnetTarget(target, m_spellInfo))
                            if (magnet != target)
                                m_targets.SetUnitTarget(magnet);
                    pushType = PUSH_CHAIN;
                    break;
                case TARGET_UNIT_TARGET_CHAINHEAL_ALLY:
                    pushType = PUSH_CHAIN;
                    break;
                case TARGET_UNIT_TARGET_ALLY:
                    AddUnitTarget(target, effectMask, false);
                    break;
                case TARGET_UNIT_TARGET_RAID:
                case TARGET_UNIT_TARGET_PARTY:
                case TARGET_UNIT_TARGET_MINIPET:
                    AddUnitTarget(target, effectMask, false);
                    break;
                case TARGET_UNIT_TARGET_PASSENGER:
                    AddUnitTarget(target, effectMask, false);
                    break;
                case TARGET_UNIT_LASTTARGET_AREA_PARTY:
                case TARGET_UNIT_TARGET_AREA_RAID_CLASS:
                    pushType = PUSH_CASTER_CENTER; // not real
                    break;
                default:
                    break;
            }
            break;
        }

        case TARGET_TYPE_UNIT_NEARBY:
        {
            WorldObject* target = NULL;
            float range;

            switch (cur.GetTarget())
            {
                case TARGET_UNIT_NEARBY_ENEMY:
                    range = m_spellInfo->GetMaxRange(false);
                    if (modOwner) modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RANGE, range, this);
                    target = SearchNearbyTarget(range, SPELL_TARGETS_ENEMY, SpellEffIndex(i));
                    break;
                case TARGET_UNIT_NEARBY_ALLY:
                case TARGET_UNIT_NEARBY_PARTY: // TODO: fix party/raid targets
                case TARGET_UNIT_NEARBY_RAID:
                    range = m_spellInfo->GetMaxRange(true);
                    if (modOwner) modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RANGE, range, this);
                    target = SearchNearbyTarget(range, SPELL_TARGETS_ALLY, SpellEffIndex(i));
                    break;
                case TARGET_UNIT_NEARBY_ENTRY:
                case TARGET_GAMEOBJECT_NEARBY_ENTRY:
                    range = m_spellInfo->GetMaxRange(m_spellInfo->IsPositive());
                    if (modOwner) modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RANGE, range, this);
                    target = SearchNearbyTarget(range, SPELL_TARGETS_ENTRY, SpellEffIndex(i));
                    break;
                default:
                    break;
            }

            if (!target)
                return 0;
            else if (target->GetTypeId() == TYPEID_GAMEOBJECT)
                AddGOTarget((GameObject*)target, effectMask);
            else
            {
                pushType = PUSH_CHAIN;

                if (m_targets.GetUnitTarget() != target)
                    m_targets.SetUnitTarget((Unit*)target);
            }

            break;
        }

        case TARGET_TYPE_AREA_SRC:
            pushType = PUSH_SRC_CENTER;
            break;

        case TARGET_TYPE_AREA_DST:
            pushType = PUSH_DST_CENTER;
            break;

        case TARGET_TYPE_AREA_CONE:
            if (m_spellInfo->AttributesCu & SPELL_ATTR0_CU_CONE_BACK)
                pushType = PUSH_IN_BACK;
            else if (m_spellInfo->AttributesCu & SPELL_ATTR0_CU_CONE_LINE)
                pushType = PUSH_IN_LINE;
            else
                pushType = PUSH_IN_FRONT;
            break;

        case TARGET_TYPE_DEST_CASTER: //4+8+2
        {
            if (cur.GetTarget() == TARGET_SRC_CASTER)
            {
                m_targets.SetSrc(*m_caster);
                break;
            }
            else if (cur.GetTarget() == TARGET_DEST_CASTER)
            {
                m_targets.SetDst(*m_caster);
                break;
            }

            float angle, dist;

            float objSize = m_caster->GetObjectSize();
            if (cur.GetTarget() == TARGET_DEST_CASTER_SUMMON)
                dist = 0.0f;
            else
                dist = m_spellInfo->Effects[i].CalcRadius(m_caster);
            if (modOwner) modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RADIUS, dist, this);
            if (dist < objSize)
                dist = objSize;
            else if (cur.GetTarget() == TARGET_DEST_CASTER_RANDOM)
                dist = objSize + (dist - objSize) * (float)rand_norm();

            switch (cur.GetTarget())
            {
                case TARGET_DEST_CASTER_FRONT_LEFT: angle = static_cast<float>(-M_PI/4);                   break;
                case TARGET_DEST_CASTER_BACK_LEFT:  angle = static_cast<float>(-3*M_PI/4);                 break;
                case TARGET_DEST_CASTER_BACK_RIGHT: angle = static_cast<float>(3*M_PI/4);                  break;
                case TARGET_DEST_CASTER_FRONT_RIGHT:angle = static_cast<float>(M_PI/4);                    break;
                case TARGET_DEST_CASTER_SUMMON:
                case TARGET_DEST_CASTER_FRONT_LEAP:
                case TARGET_DEST_CASTER_FRONT:      angle = 0.0f;                                          break;
                case TARGET_DEST_CASTER_BACK:       angle = static_cast<float>(M_PI);                      break;
                case TARGET_DEST_CASTER_RIGHT:      angle = static_cast<float>(-M_PI/2);                   break;
                case TARGET_DEST_CASTER_LEFT:       angle = static_cast<float>(M_PI/2);                    break;
                default:                            angle = (float)rand_norm()*static_cast<float>(2*M_PI); break;
            }

            Position pos;
            if (cur.GetTarget() == TARGET_DEST_CASTER_FRONT_LEAP)
                m_caster->GetFirstCollisionPosition(pos, dist, angle);
            else
                m_caster->GetNearPosition(pos, dist, angle);
            m_targets.SetDst(*m_caster);
            m_targets.ModDst(pos);
            break;
        }

        case TARGET_TYPE_DEST_TARGET: //2+8+2
        {
            Unit* target = m_targets.GetUnitTarget();
            if (!target)
            {
                sLog->outError("SPELL: no unit target for spell ID %u", m_spellInfo->Id);
                break;
            }

            if (cur.GetTarget() == TARGET_DEST_TARGET_ENEMY || cur.GetTarget() == TARGET_DEST_TARGET_ANY)
            {
                m_targets.SetDst(*target);
                break;
            }

            float angle, dist;

            float objSize = target->GetObjectSize();
            dist = m_spellInfo->Effects[i].CalcRadius(m_caster);
            if (dist < objSize)
                dist = objSize;
            else if (cur.GetTarget() == TARGET_DEST_TARGET_RANDOM)
                dist = objSize + (dist - objSize) * (float)rand_norm();

            switch (cur.GetTarget())
            {
                case TARGET_DEST_TARGET_FRONT:      angle = 0.0f;                                          break;
                case TARGET_DEST_TARGET_BACK:       angle = static_cast<float>(M_PI);                      break;
                case TARGET_DEST_TARGET_RIGHT:      angle = static_cast<float>(M_PI/2);                    break;
                case TARGET_DEST_TARGET_LEFT:       angle = static_cast<float>(-M_PI/2);                   break;
                case TARGET_DEST_TARGET_FRONT_LEFT: angle = static_cast<float>(-M_PI/4);                   break;
                case TARGET_DEST_TARGET_BACK_LEFT:  angle = static_cast<float>(-3*M_PI/4);                 break;
                case TARGET_DEST_TARGET_BACK_RIGHT: angle = static_cast<float>(3*M_PI/4);                  break;
                case TARGET_DEST_TARGET_FRONT_RIGHT:angle = static_cast<float>(M_PI/4);                    break;
                default:                            angle = (float)rand_norm()*static_cast<float>(2*M_PI); break;
            }

            Position pos;
            target->GetNearPosition(pos, dist, angle);
            m_targets.SetDst(*target);
            m_targets.ModDst(pos);
            break;
        }

        case TARGET_TYPE_DEST_DEST: //5+8+1
        {
            if (!m_targets.HasDst())
            {
                sLog->outError("SPELL: no destination for spell ID %u", m_spellInfo->Id);
                break;
            }

            float angle;
            switch (cur.GetTarget())
            {
                case TARGET_DEST_DYNOBJ_ENEMY:
                case TARGET_DEST_DYNOBJ_ALLY:
                case TARGET_DEST_DYNOBJ_NONE:
                case TARGET_DEST_DEST:
                    return effectMask;
                case TARGET_DEST_TRAJ:
                    SelectTrajTargets();
                    return effectMask;
                case TARGET_DEST_DEST_FRONT:      angle = 0.0f;                                          break;
                case TARGET_DEST_DEST_BACK:       angle = static_cast<float>(M_PI);                      break;
                case TARGET_DEST_DEST_RIGHT:      angle = static_cast<float>(M_PI/2);                    break;
                case TARGET_DEST_DEST_LEFT:       angle = static_cast<float>(-M_PI/2);                   break;
                case TARGET_DEST_DEST_FRONT_LEFT: angle = static_cast<float>(-M_PI/4);                   break;
                case TARGET_DEST_DEST_BACK_LEFT:  angle = static_cast<float>(-3*M_PI/4);                 break;
                case TARGET_DEST_DEST_BACK_RIGHT: angle = static_cast<float>(3*M_PI/4);                  break;
                case TARGET_DEST_DEST_FRONT_RIGHT:angle = static_cast<float>(M_PI/4);                    break;
                default:                          angle = (float)rand_norm()*static_cast<float>(2*M_PI); break;
            }

            float dist = m_spellInfo->Effects[i].CalcRadius(m_caster);
            if (cur.GetTarget() == TARGET_DEST_DEST_RANDOM || cur.GetTarget() == TARGET_DEST_DEST_RADIUS)
                dist *= (float)rand_norm();

            // must has dst, no need to set flag
            Position pos = *m_targets.GetDst();
            m_caster->MovePosition(pos, dist, angle);
            m_targets.ModDst(pos);
            break;
        }

        case TARGET_TYPE_DEST_SPECIAL:
        {
            switch (cur.GetTarget())
            {
                case TARGET_DEST_DB:
                    if (SpellTargetPosition const* st = sSpellMgr->GetSpellTargetPosition(m_spellInfo->Id))
                    {
                        //TODO: fix this check
                        if (m_spellInfo->Effects[0].Effect == SPELL_EFFECT_TELEPORT_UNITS || m_spellInfo->Effects[1].Effect == SPELL_EFFECT_TELEPORT_UNITS || m_spellInfo->Effects[2].Effect == SPELL_EFFECT_TELEPORT_UNITS)
                            m_targets.SetDst(st->target_X, st->target_Y, st->target_Z, st->target_Orientation, (int32)st->target_mapId);
                        else if (st->target_mapId == m_caster->GetMapId())
                            m_targets.SetDst(st->target_X, st->target_Y, st->target_Z, st->target_Orientation);
                    }
                    else
                    {
                        sLog->outError("SPELL: unknown target coordinates for spell ID %u", m_spellInfo->Id);
                        Unit* target = NULL;
                        if (uint64 guid = m_caster->GetUInt64Value(UNIT_FIELD_TARGET))
                            target = ObjectAccessor::GetUnit(*m_caster, guid);
                        m_targets.SetDst(target ? *target : *m_caster);
                    }
                    break;
                case TARGET_DEST_HOME:
                    if (m_caster->GetTypeId() == TYPEID_PLAYER)
                        m_targets.SetDst(m_caster->ToPlayer()->m_homebindX, m_caster->ToPlayer()->m_homebindY, m_caster->ToPlayer()->m_homebindZ, m_caster->ToPlayer()->GetOrientation(), m_caster->ToPlayer()->m_homebindMapId);
                    break;
                case TARGET_DEST_NEARBY_ENTRY:
                {
                    float range = m_spellInfo->GetMaxRange(m_spellInfo->IsPositive());
                    if (modOwner) modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RANGE, range, this);

                    if (WorldObject* target = SearchNearbyTarget(range, SPELL_TARGETS_ENTRY, SpellEffIndex(i)))
                        m_targets.SetDst(*target);
                    break;
                }
                default:
                    break;
            }
            break;
        }

        case TARGET_TYPE_CHANNEL:
        {
            if (!m_originalCaster || !m_originalCaster->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
            {
                sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "SPELL: no current channeled spell for spell ID %u - spell triggering this spell was interrupted.", m_spellInfo->Id);
                break;
            }

            switch (cur.GetTarget())
            {
                case TARGET_UNIT_CHANNEL_TARGET:
                    // unit target may be no longer avalible - teleported out of map for example
                    if (Unit* target = Unit::GetUnit(*m_caster, m_originalCaster->GetCurrentSpell(CURRENT_CHANNELED_SPELL)->m_targets.GetUnitTargetGUID()))
                        AddUnitTarget(target, effectMask);
                    else
                        sLog->outError("SPELL: cannot find channel spell target for spell ID %u", m_spellInfo->Id);
                    break;
                case TARGET_DEST_CHANNEL_TARGET:
                    if (m_originalCaster->GetCurrentSpell(CURRENT_CHANNELED_SPELL)->m_targets.HasDst())
                        m_targets.SetDst(m_originalCaster->GetCurrentSpell(CURRENT_CHANNELED_SPELL)->m_targets);
                    else if (Unit* target = Unit::GetUnit(*m_caster, m_originalCaster->GetCurrentSpell(CURRENT_CHANNELED_SPELL)->m_targets.GetUnitTargetGUID()))
                        m_targets.SetDst(*target);
                    else
                        sLog->outError("SPELL: cannot find channel spell destination for spell ID %u", m_spellInfo->Id);
                    break;
                case TARGET_DEST_CHANNEL_CASTER:
                    m_targets.SetDst(*m_originalCaster->GetCurrentSpell(CURRENT_CHANNELED_SPELL)->GetCaster());
                    break;
                default:
                    break;
            }
            break;
        }

        default:
        {
            switch (cur.GetTarget())
            {
                case TARGET_GAMEOBJECT_TARGET:
                    if (m_targets.GetGOTarget())
                        AddGOTarget(m_targets.GetGOTarget(), effectMask);
                    break;
                case TARGET_GAMEOBJECT_ITEM_TARGET:
                    if (m_targets.GetGOTargetGUID())
                        AddGOTarget(m_targets.GetGOTarget(), effectMask);
                    else if (m_targets.GetItemTarget())
                        AddItemTarget(m_targets.GetItemTarget(), effectMask);
                    break;
                default:
                    sLog->outError("SPELL (caster[type: %u; guidlow: %u], spell: %u): unhandled spell target (%u)",
                        m_caster->GetTypeId(), m_caster->GetGUIDLow(), m_spellInfo->Id, cur.GetTarget());
                    break;
            }
            break;
        }
    }

    if (pushType == PUSH_CHAIN) // Chain
    {
        Unit* target = m_targets.GetUnitTarget();
        if (!target)
        {
            sLog->outError("SPELL: no chain unit target for spell ID %u", m_spellInfo->Id);
            return 0;
        }

        //Chain: 2, 6, 22, 25, 45, 77
        uint32 maxTargets = m_spellInfo->Effects[i].ChainTarget;
        if (modOwner)
            modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_JUMP_TARGETS, maxTargets, this);

        if (maxTargets > 1)
        {
            //otherwise, this multiplier is used for something else
            for (uint32 k = i; k < MAX_SPELL_EFFECTS; ++k)
                if (effectMask & (1 << k))
                    m_damageMultipliers[k] = 1.0f;
            m_applyMultiplierMask |= effectMask;

            float range;
            std::list<Unit*> unitList;

            switch (cur.GetTarget())
            {
                case TARGET_UNIT_NEARBY_ENEMY:
                case TARGET_UNIT_TARGET_ENEMY:
                case TARGET_UNIT_NEARBY_ENTRY: // fix me
                    range = m_spellInfo->GetMaxRange(false);
                    if (modOwner) modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RANGE, range, this);
                    SearchChainTarget(unitList, range, maxTargets, SPELL_TARGETS_ENEMY);
                    break;
                case TARGET_UNIT_TARGET_CHAINHEAL_ALLY:
                case TARGET_UNIT_NEARBY_ALLY:  // fix me
                case TARGET_UNIT_NEARBY_PARTY:
                case TARGET_UNIT_NEARBY_RAID:
                    range = m_spellInfo->GetMaxRange(true);
                    if (modOwner) modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RANGE, range, this);
                    SearchChainTarget(unitList, range, maxTargets, SPELL_TARGETS_CHAINHEAL);
                    break;
                default:
                    break;
            }

            CallScriptAfterUnitTargetSelectHandlers(unitList, SpellEffIndex(i));

            for (std::list<Unit*>::iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
                AddUnitTarget(*itr, effectMask, false);
        }
        else
            AddUnitTarget(target, effectMask, false);
    }
    else if (pushType)
    {
        float radius;
        SpellTargets targetType;
        switch (cur.GetTarget())
        {
            case TARGET_UNIT_SRC_AREA_ENEMY:
            case TARGET_UNIT_DEST_AREA_ENEMY:
            case TARGET_UNIT_CONE_ENEMY_24:
            case TARGET_UNIT_CONE_ENEMY_54:
            case TARGET_UNIT_CONE_ENEMY_104:
                radius = m_spellInfo->Effects[i].CalcRadius();
                targetType = SPELL_TARGETS_ENEMY;
                break;
            case TARGET_UNIT_SRC_AREA_ALLY:
            case TARGET_UNIT_DEST_AREA_ALLY:
            case TARGET_UNIT_CONE_ALLY:
                radius = m_spellInfo->Effects[i].CalcRadius();
                targetType = SPELL_TARGETS_ALLY;
                break;
            case TARGET_UNIT_DEST_AREA_ENTRY:
            case TARGET_UNIT_SRC_AREA_ENTRY:
            case TARGET_UNIT_CONE_ENTRY: // fix me
                radius = m_spellInfo->Effects[i].CalcRadius();
                targetType = SPELL_TARGETS_ENTRY;
                break;
            case TARGET_GAMEOBJECT_SRC_AREA:
            case TARGET_GAMEOBJECT_DEST_AREA:
            case TARGET_GAMEOBJECT_CONE:
                radius = m_spellInfo->Effects[i].CalcRadius();
                targetType = SPELL_TARGETS_GO;
                break;
            default:
                radius = m_spellInfo->Effects[i].CalcRadius();
                targetType = SPELL_TARGETS_NONE;
                break;
        }

        if (modOwner)
            modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RADIUS, radius, this);
        radius *= m_spellValue->RadiusMod;

        std::list<Unit*> unitList;
        std::list<GameObject*> gobjectList;
        switch (targetType)
        {
            case SPELL_TARGETS_ENTRY:
            {
                ConditionList conditions = sConditionMgr->GetConditionsForNotGroupedEntry(CONDITION_SOURCE_TYPE_SPELL_SCRIPT_TARGET, m_spellInfo->Id);
                if (!conditions.empty())
                {
                    for (ConditionList::const_iterator i_spellST = conditions.begin(); i_spellST != conditions.end(); ++i_spellST)
                    {
                        if ((*i_spellST)->mConditionType != CONDITION_SPELL_SCRIPT_TARGET)
                            continue;
                        if ((*i_spellST)->mConditionValue3 && !((*i_spellST)->mConditionValue3 & effectMask))
                            continue;
                        if ((*i_spellST)->mConditionValue1 == SPELL_TARGET_TYPE_CREATURE)
                            SearchAreaTarget(unitList, radius, pushType, SPELL_TARGETS_ENTRY, (*i_spellST)->mConditionValue2);
                        else if ((*i_spellST)->mConditionValue1 == SPELL_TARGET_TYPE_CONTROLLED)
                        {
                            for (Unit::ControlList::iterator itr = m_caster->m_Controlled.begin(); itr != m_caster->m_Controlled.end(); ++itr)
                                if ((*itr)->GetEntry() == (*i_spellST)->mConditionValue2 &&
                                    (*itr)->IsInMap(m_caster)) // For 60243 and 52173 need skip radius check or use range (no radius entry for effect)
                                    unitList.push_back(*itr);
                        }
                    }
                }
                else
                {
                    // Custom entries
                    // TODO: move these to sql
                    switch (m_spellInfo->Id)
                    {
                        case 46584: // Raise Dead
                        {
                            if (WorldObject* result = FindCorpseUsing<Trinity::RaiseDeadObjectCheck> ())
                            {
                                switch (result->GetTypeId())
                                {
                                    case TYPEID_UNIT:
                                        m_targets.SetDst(*result);
                                        break;
                                    default:
                                        break;
                                }
                            }
                            break;
                        }
                        // Corpse Explosion
                        case 49158:
                        case 51325:
                        case 51326:
                        case 51327:
                        case 51328:
                            // Search for ghoul if our ghoul or dead body not valid unit target
                            if (!(m_targets.GetUnitTarget() && ((m_targets.GetUnitTarget()->GetEntry() == 26125 && m_targets.GetUnitTarget()->GetOwnerGUID() == m_caster->GetGUID())
                                || (m_targets.GetUnitTarget()->getDeathState() == CORPSE
                                    && m_targets.GetUnitTarget()->GetTypeId() == TYPEID_UNIT
                                    && !(m_targets.GetUnitTarget()->GetCreatureTypeMask() & CREATURE_TYPEMASK_MECHANICAL_OR_ELEMENTAL)
                                    && m_targets.GetUnitTarget()->GetDisplayId() == m_targets.GetUnitTarget()->GetNativeDisplayId()))))
                            {
                                CleanupTargetList();

                                WorldObject* result = FindCorpseUsing <Trinity::ExplodeCorpseObjectCheck> ();

                                if (result)
                                {
                                    switch (result->GetTypeId())
                                    {
                                        case TYPEID_UNIT:
                                        case TYPEID_PLAYER:
                                            m_targets.SetUnitTarget((Unit*)result);
                                            break;
                                        default:
                                            break;
                                    }
                                }
                                else
                                {
                                    if (m_caster->GetTypeId() == TYPEID_PLAYER)
                                        m_caster->ToPlayer()->RemoveSpellCooldown(m_spellInfo->Id, true);
                                    SendCastResult(SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW);
                                    finish(false);
                                }
                            }
                            break;

                        default:
                            sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "Spell (ID: %u) (caster Entry: %u) does not have type CONDITION_SOURCE_TYPE_SPELL_SCRIPT_TARGET record in `conditions` table.", m_spellInfo->Id, m_caster->GetEntry());

                            if (m_spellInfo->Effects[i].Effect == SPELL_EFFECT_TELEPORT_UNITS)
                                SearchAreaTarget(unitList, radius, pushType, SPELL_TARGETS_ENTRY, 0);
                            else if (m_spellInfo->IsPositiveEffect(i))
                                SearchAreaTarget(unitList, radius, pushType, SPELL_TARGETS_ALLY);
                            else
                                SearchAreaTarget(unitList, radius, pushType, SPELL_TARGETS_ENEMY);
                    }
                }
                break;
            }
            case SPELL_TARGETS_GO:
            {
                ConditionList conditions = sConditionMgr->GetConditionsForNotGroupedEntry(CONDITION_SOURCE_TYPE_SPELL_SCRIPT_TARGET, m_spellInfo->Id);
                if (!conditions.empty())
                {
                    for (ConditionList::const_iterator i_spellST = conditions.begin(); i_spellST != conditions.end(); ++i_spellST)
                    {
                        if ((*i_spellST)->mConditionType != CONDITION_SPELL_SCRIPT_TARGET)
                            continue;
                        if ((*i_spellST)->mConditionValue3 && !((*i_spellST)->mConditionValue3 & effectMask))
                            continue;
                        if ((*i_spellST)->mConditionValue1 == SPELL_TARGET_TYPE_GAMEOBJECT)
                            SearchGOAreaTarget(gobjectList, radius, pushType, SPELL_TARGETS_GO, (*i_spellST)->mConditionValue2);
                    }
                }
                else
                {
                    if (m_spellInfo->Effects[i].Effect == SPELL_EFFECT_ACTIVATE_OBJECT)
                        sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "Spell (ID: %u) (caster Entry: %u) with SPELL_EFFECT_ACTIVATE_OBJECT does not have type CONDITION_SOURCE_TYPE_SPELL_SCRIPT_TARGET record in `conditions` table.", m_spellInfo->Id, m_caster->GetEntry());
                    SearchGOAreaTarget(gobjectList, radius, pushType, SPELL_TARGETS_GO);
                }
                break;
            }
            case SPELL_TARGETS_ALLY:
            case SPELL_TARGETS_ENEMY:
            case SPELL_TARGETS_CHAINHEAL:
            case SPELL_TARGETS_ANY:
                SearchAreaTarget(unitList, radius, pushType, targetType);
                break;
            default:
                switch (cur.GetTarget())
                {
                    case TARGET_UNIT_SRC_AREA_PARTY:
                    case TARGET_UNIT_DEST_AREA_PARTY:
                        m_caster->GetPartyMemberInDist(unitList, radius); //fix me
                        break;
                    case TARGET_UNIT_LASTTARGET_AREA_PARTY:
                        m_targets.GetUnitTarget()->GetPartyMemberInDist(unitList, radius);
                        break;
                    case TARGET_UNIT_CASTER_AREA_PARTY:
                        m_caster->GetPartyMemberInDist(unitList, radius);
                        break;
                    case TARGET_UNIT_CASTER_AREA_RAID:
                        m_caster->GetRaidMember(unitList, radius);
                        break;
                    case TARGET_UNIT_TARGET_AREA_RAID_CLASS:
                    {
                        Player* targetPlayer = m_targets.GetUnitTarget() && m_targets.GetUnitTarget()->GetTypeId() == TYPEID_PLAYER
                            ? (Player*)m_targets.GetUnitTarget() : NULL;

                        Group* pGroup = targetPlayer ? targetPlayer->GetGroup() : NULL;
                        if (pGroup)
                        {
                            for (GroupReference* itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
                            {
                                Player* Target = itr->getSource();

                                // IsHostileTo check duel and controlled by enemy
                                if (Target && targetPlayer->IsWithinDistInMap(Target, radius) && targetPlayer->getClass() == Target->getClass() && !m_caster->IsHostileTo(Target))
                                    AddUnitTarget(Target, effectMask);
                            }
                        }
                        else if (m_targets.GetUnitTarget())
                            AddUnitTarget(m_targets.GetUnitTarget(), effectMask);
                        break;
                    }
                    default:
                        break;
                }
                break;
            }

        if (!unitList.empty())
        {
            // Special target selection for smart heals and energizes
            uint32 maxSize = 0;
            int32 power = -1;
            switch (m_spellInfo->SpellFamilyName)
            {
                case SPELLFAMILY_GENERIC:
                    switch (m_spellInfo->Id)
                    {
                        case 52759: // Ancestral Awakening
                        case 71610: // Echoes of Light (Althor's Abacus normal version)
                        case 71641: // Echoes of Light (Althor's Abacus heroic version)
                            maxSize = 1;
                            power = POWER_HEALTH;
                            break;
                        case 54968: // Glyph of Holy Light
                            maxSize = m_spellInfo->MaxAffectedTargets;
                            power = POWER_HEALTH;
                            break;
                        case 57669: // Replenishment
                            // In arenas Replenishment may only affect the caster
                            if (m_caster->GetTypeId() == TYPEID_PLAYER && m_caster->ToPlayer()->InArena())
                            {
                                unitList.clear();
                                unitList.push_back(m_caster);
                                break;
                            }
                            maxSize = 10;
                            power = POWER_MANA;
                            break;
                        default:
                            break;
                    }
                    break;
                case SPELLFAMILY_PRIEST:
                    if (m_spellInfo->SpellFamilyFlags[0] == 0x10000000) // Circle of Healing
                    {
                        maxSize = m_caster->HasAura(55675) ? 6 : 5; // Glyph of Circle of Healing
                        power = POWER_HEALTH;
                    }
                    else if (m_spellInfo->Id == 64844) // Divine Hymn
                    {
                        maxSize = 3;
                        power = POWER_HEALTH;
                    }
                    else if (m_spellInfo->Id == 64904) // Hymn of Hope
                    {
                        maxSize = 3;
                        power = POWER_MANA;
                    }
                    else
                        break;

                    // Remove targets outside caster's raid
                    for (std::list<Unit*>::iterator itr = unitList.begin() ; itr != unitList.end();)
                    {
                        if (!(*itr)->IsInRaidWith(m_caster))
                            itr = unitList.erase(itr);
                        else
                            ++itr;
                    }
                    break;
                case SPELLFAMILY_DRUID:
                    if (m_spellInfo->SpellFamilyFlags[1] == 0x04000000) // Wild Growth
                    {
                        maxSize = m_caster->HasAura(62970) ? 6 : 5; // Glyph of Wild Growth
                        power = POWER_HEALTH;
                    }
                    else if (m_spellInfo->SpellFamilyFlags[2] == 0x0100) // Starfall
                    {
                        // Remove targets not in LoS or in stealth
                        for (std::list<Unit*>::iterator itr = unitList.begin() ; itr != unitList.end();)
                        {
                            if ((*itr)->HasStealthAura() || (*itr)->HasInvisibilityAura() || !(*itr)->IsWithinLOSInMap(m_caster))
                                itr = unitList.erase(itr);
                            else
                                ++itr;
                        }
                        break;
                    }
                    else
                        break;

                    // Remove targets outside caster's raid
                    for (std::list<Unit*>::iterator itr = unitList.begin() ; itr != unitList.end();)
                        if (!(*itr)->IsInRaidWith(m_caster))
                            itr = unitList.erase(itr);
                        else
                            ++itr;
                    break;
                default:
                    break;
            }

            if (maxSize && power != -1)
            {
                if (Powers(power) == POWER_HEALTH)
                {
                    if (unitList.size() > maxSize)
                    {
                        unitList.sort(Trinity::HealthPctOrderPred());
                        unitList.resize(maxSize);
                    }
                }
                else
                {
                    for (std::list<Unit*>::iterator itr = unitList.begin() ; itr != unitList.end();)
                        if ((*itr)->getPowerType() != (Powers)power)
                            itr = unitList.erase(itr);
                        else
                            ++itr;

                    if (unitList.size() > maxSize)
                    {
                        unitList.sort(Trinity::PowerPctOrderPred((Powers)power));
                        unitList.resize(maxSize);
                    }
                }
            }

            // Other special target selection goes here
            if (uint32 maxTargets = m_spellValue->MaxAffectedTargets)
            {
                Unit::AuraEffectList const& Auras = m_caster->GetAuraEffectsByType(SPELL_AURA_MOD_MAX_AFFECTED_TARGETS);
                for (Unit::AuraEffectList::const_iterator j = Auras.begin(); j != Auras.end(); ++j)
                    if ((*j)->IsAffectedOnSpell(m_spellInfo))
                        maxTargets += (*j)->GetAmount();

                if (m_spellInfo->Id == 5246) //Intimidating Shout
                    unitList.remove(m_targets.GetUnitTarget());
                Trinity::RandomResizeList(unitList, maxTargets);
            }

            CallScriptAfterUnitTargetSelectHandlers(unitList, SpellEffIndex(i));

            for (std::list<Unit*>::iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
                AddUnitTarget(*itr, effectMask, false);
        }

        if (!gobjectList.empty())
        {
            if (uint32 maxTargets = m_spellValue->MaxAffectedTargets)
            {
                Unit::AuraEffectList const& Auras = m_caster->GetAuraEffectsByType(SPELL_AURA_MOD_MAX_AFFECTED_TARGETS);
                for (Unit::AuraEffectList::const_iterator j = Auras.begin(); j != Auras.end(); ++j)
                    if ((*j)->IsAffectedOnSpell(m_spellInfo))
                        maxTargets += (*j)->GetAmount();

                Trinity::RandomResizeList(gobjectList, maxTargets);
            }
            for (std::list<GameObject*>::iterator itr = gobjectList.begin(); itr != gobjectList.end(); ++itr)
                AddGOTarget(*itr, effectMask);
        }
    }

    return effectMask;
}

void Spell::prepare(SpellCastTargets const* targets, AuraEffect const* triggeredByAura)
{
    if (m_CastItem)
        m_castItemGUID = m_CastItem->GetGUID();
    else
        m_castItemGUID = 0;

    InitExplicitTargets(*targets);

    if (Player* plrCaster = m_caster->GetCharmerOrOwnerPlayerOrPlayerItself())
    {
        //check for special spell conditions
        ConditionList conditions = sConditionMgr->GetConditionsForNotGroupedEntry(CONDITION_SOURCE_TYPE_SPELL, m_spellInfo->Id);
        if (!conditions.empty())
            if (!sConditionMgr->IsPlayerMeetToConditions(plrCaster, conditions))
            {
                //SendCastResult(SPELL_FAILED_DONT_REPORT);
                SendCastResult(plrCaster, m_spellInfo, m_cast_count, SPELL_FAILED_DONT_REPORT);
                finish(false);
                return;
            }
    }

    // Fill aura scaling information
    if (m_caster->IsControlledByPlayer() && !m_spellInfo->IsPassive() && m_spellInfo->SpellLevel && !m_spellInfo->IsChanneled() && !(_triggeredCastFlags & TRIGGERED_IGNORE_AURA_SCALING))
    {
        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        {
            if (m_spellInfo->Effects[i].Effect == SPELL_EFFECT_APPLY_AURA)
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

    m_spellState = SPELL_STATE_PREPARING;

    if (triggeredByAura)
        m_triggeredByAuraSpell  = triggeredByAura->GetSpellInfo();

    // create and add update event for this spell
    SpellEvent* Event = new SpellEvent(this);
    m_caster->m_Events.AddEvent(Event, m_caster->m_Events.CalculateTime(1));

    //Prevent casting at cast another spell (ServerSide check)
    if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CAST_IN_PROGRESS) && m_caster->IsNonMeleeSpellCasted(false, true, true) && m_cast_count)
    {
        SendCastResult(SPELL_FAILED_SPELL_IN_PROGRESS);
        finish(false);
        return;
    }

    if (DisableMgr::IsDisabledFor(DISABLE_TYPE_SPELL, m_spellInfo->Id, m_caster))
    {
        SendCastResult(SPELL_FAILED_SPELL_UNAVAILABLE);
        finish(false);
        return;
    }
    LoadScripts();

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
        m_caster->ToPlayer()->SetSpellModTakingSpell(this, true);
    // Fill cost data (not use power for item casts
    m_powerCost = m_CastItem ? 0 : m_spellInfo->CalcPowerCost(m_caster, m_spellSchoolMask);
    if (m_caster->GetTypeId() == TYPEID_PLAYER)
        m_caster->ToPlayer()->SetSpellModTakingSpell(this, false);

    // Set combo point requirement
    if ((_triggeredCastFlags & TRIGGERED_IGNORE_COMBO_POINTS) || m_CastItem || !m_caster->m_movedPlayer)
        m_needComboPoints = false;

    SpellCastResult result = CheckCast(true);
    if (result != SPELL_CAST_OK && !IsAutoRepeat())          //always cast autorepeat dummy for triggering
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

        SendCastResult(result);

        finish(false);
        return;
    }

    // Prepare data for triggers
    prepareDataForTriggerSystem(triggeredByAura);

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
        m_caster->ToPlayer()->SetSpellModTakingSpell(this, true);
    // calculate cast time (calculated after first CheckCast check to prevent charge counting for first CheckCast fail)
    m_casttime = m_spellInfo->CalcCastTime(m_caster, this);
    if (m_caster->GetTypeId() == TYPEID_PLAYER)
        m_caster->ToPlayer()->SetSpellModTakingSpell(this, false);

    // don't allow channeled spells / spells with cast time to be casted while moving
    // (even if they are interrupted on moving, spells with almost immediate effect get to have their effect processed before movement interrupter kicks in)
    if ((m_spellInfo->IsChanneled() || m_casttime) && m_caster->GetTypeId() == TYPEID_PLAYER && m_caster->isMoving() && m_spellInfo->InterruptFlags & SPELL_INTERRUPT_FLAG_MOVEMENT)
    {
        SendCastResult(SPELL_FAILED_MOVING);
        finish(false);
        return;
    }

    // set timer base at cast time
    ReSetTimer();

    sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "Spell::prepare: spell id %u source %u caster %d customCastFlags %u mask %u", m_spellInfo->Id, m_caster->GetEntry(), m_originalCaster ? m_originalCaster->GetEntry() : -1, _triggeredCastFlags, m_targets.GetTargetMask());

    //Containers for channeled spells have to be set
    //TODO:Apply this to all casted spells if needed
    // Why check duration? 29350: channelled triggers channelled
    if ((_triggeredCastFlags & TRIGGERED_CAST_DIRECTLY) && (!m_spellInfo->IsChanneled() || !m_spellInfo->GetMaxDuration()))
        cast(true);
    else
    {
        // stealth must be removed at cast starting (at show channel bar)
        // skip triggered spell (item equip spell casting and other not explicit character casts/item uses)
        if (!(_triggeredCastFlags & TRIGGERED_IGNORE_AURA_INTERRUPT_FLAGS) && m_spellInfo->IsBreakingStealth())
        {
            m_caster->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_CAST);
            for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                if (m_spellInfo->Effects[i].GetUsedTargetObjectType() == TARGET_OBJECT_TYPE_UNIT)
                {
                    m_caster->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_SPELL_ATTACK);
                    break;
                }
        }

        m_caster->SetCurrentCastedSpell(this);
        SendSpellStart();

        // set target for proper facing
        if (m_casttime && !(_triggeredCastFlags & TRIGGERED_IGNORE_SET_FACING))
            if (uint64 target = m_targets.GetUnitTargetGUID())
                if (m_caster->GetGUID() != target && m_caster->GetTypeId() == TYPEID_UNIT)
                    m_caster->FocusTarget(this, target);

        if (!(_triggeredCastFlags & TRIGGERED_IGNORE_GCD))
            TriggerGlobalCooldown();

        //item: first cast may destroy item and second cast causes crash
        if (!m_casttime && !m_spellInfo->StartRecoveryTime && !m_castItemGUID && GetCurrentContainer() == CURRENT_GENERIC_SPELL)
            cast(true);
    }
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
            if (m_caster->GetTypeId() == TYPEID_PLAYER)
                m_caster->ToPlayer()->RestoreSpellMods(this);
        case SPELL_STATE_DELAYED:
            SendInterrupted(0);
            SendCastResult(SPELL_FAILED_INTERRUPTED);
            break;

        case SPELL_STATE_CASTING:
            for (std::list<TargetInfo>::const_iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
                if ((*ihit).missCondition == SPELL_MISS_NONE)
                    if (Unit* unit = m_caster->GetGUID() == ihit->targetGUID ? m_caster : ObjectAccessor::GetUnit(*m_caster, ihit->targetGUID))
                        unit->RemoveOwnedAura(m_spellInfo->Id, m_originalCasterGUID, 0, AURA_REMOVE_BY_CANCEL);

            SendChannelUpdate(0);
            SendInterrupted(0);
            SendCastResult(SPELL_FAILED_INTERRUPTED);

            // spell is canceled-take mods and clear list
            if (m_caster->GetTypeId() == TYPEID_PLAYER)
                m_caster->ToPlayer()->RemoveSpellMods(this);

            m_appliedMods.clear();
            break;

        default:
            break;
    }

    SetReferencedFromCurrent(false);
    if (m_selfContainer && *m_selfContainer == this)
        *m_selfContainer = NULL;

    m_caster->RemoveDynObject(m_spellInfo->Id);
    m_caster->RemoveGameObject(m_spellInfo->Id, true);

    //set state back so finish will be processed
    m_spellState = oldState;

    finish(false);
}

void Spell::cast(bool skipCheck)
{
    // update pointers base at GUIDs to prevent access to non-existed already object
    UpdatePointers();

    // cancel at lost explicit target during cast
    if (m_targets.GetObjectTargetGUID() && !m_targets.GetObjectTarget())
    {
        cancel();
        return;
    }

    // now that we've done the basic check, now run the scripts
    // should be done before the spell is actually executed
    if (Player* playerCaster = m_caster->ToPlayer())
        sScriptMgr->OnPlayerSpellCast(playerCaster, this, skipCheck);

    SetExecutedCurrently(true);

    if (m_caster->GetTypeId() != TYPEID_PLAYER && m_targets.GetUnitTarget() && m_targets.GetUnitTarget() != m_caster)
        m_caster->SetInFront(m_targets.GetUnitTarget());

    // Should this be done for original caster?
    if (m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        // Set spell which will drop charges for triggered cast spells
        // if not successfully casted, will be remove in finish(false)
        m_caster->ToPlayer()->SetSpellModTakingSpell(this, true);
    }

    // skip check if done already (for instant cast spells for example)
    if (!skipCheck)
    {
        SpellCastResult castResult = CheckCast(false);
        if (castResult != SPELL_CAST_OK)
        {
            SendCastResult(castResult);
            SendInterrupted(0);
            //restore spell mods
            if (m_caster->GetTypeId() == TYPEID_PLAYER)
            {
                m_caster->ToPlayer()->RestoreSpellMods(this);
                // cleanup after mod system
                // triggered spell pointer can be not removed in some cases
                m_caster->ToPlayer()->SetSpellModTakingSpell(this, false);
            }
            finish(false);
            SetExecutedCurrently(false);
            return;
        }

        // additional check after cast bar completes (must not be in CheckCast)
        // if trade not complete then remember it in trade data
        if (m_targets.GetTargetMask() & TARGET_FLAG_TRADE_ITEM)
        {
            if (m_caster->GetTypeId() == TYPEID_PLAYER)
            {
                if (TradeData* my_trade = m_caster->ToPlayer()->GetTradeData())
                {
                    if (!my_trade->IsInAcceptProcess())
                    {
                        // Spell will be casted at completing the trade. Silently ignore at this place
                        my_trade->SetSpell(m_spellInfo->Id, m_CastItem);
                        SendCastResult(SPELL_FAILED_DONT_REPORT);
                        SendInterrupted(0);
                        m_caster->ToPlayer()->RestoreSpellMods(this);
                        // cleanup after mod system
                        // triggered spell pointer can be not removed in some cases
                        m_caster->ToPlayer()->SetSpellModTakingSpell(this, false);
                        finish(false);
                        SetExecutedCurrently(false);
                        return;
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
        //restore spell mods
        if (m_caster->GetTypeId() == TYPEID_PLAYER)
        {
            m_caster->ToPlayer()->RestoreSpellMods(this);
            // cleanup after mod system
            // triggered spell pointer can be not removed in some cases
            m_caster->ToPlayer()->SetSpellModTakingSpell(this, false);
        }
        finish(false);
        SetExecutedCurrently(false);
        return;
    }

    PrepareTriggersExecutedOnHit();

    // traded items have trade slot instead of guid in m_itemTargetGUID
    // set to real guid to be sent later to the client
    m_targets.UpdateTradeSlotItem();

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CAST_ITEM) && m_CastItem)
        {
            m_caster->ToPlayer()->GetAchievementMgr().StartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_ITEM, m_CastItem->GetEntry());
            m_caster->ToPlayer()->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_USE_ITEM, m_CastItem->GetEntry());
        }

        m_caster->ToPlayer()->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL, m_spellInfo->Id);
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

    if (m_spellInfo->AttributesCu & SPELL_ATTR0_CU_DIRECT_DAMAGE)
        CalculateDamageDoneForAllTargets();

    // CAST SPELL
    SendSpellCooldown();

    PrepareScriptHitHandlers();

    for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        switch (m_spellInfo->Effects[i].Effect)
        {
            case SPELL_EFFECT_CHARGE:
            case SPELL_EFFECT_CHARGE_DEST:
            case SPELL_EFFECT_JUMP:
            case SPELL_EFFECT_JUMP_DEST:
            case SPELL_EFFECT_LEAP_BACK:
            case SPELL_EFFECT_ACTIVATE_RUNE:
                HandleEffects(NULL, NULL, NULL, i);
                m_effectMask |= (1<<i);
                break;
        }
    }

    // we must send smsg_spell_go packet before m_castItem delete in TakeCastItem()...
    SendSpellGo();

    // Okay, everything is prepared. Now we need to distinguish between immediate and evented delayed spells
    if ((m_spellInfo->Speed > 0.0f && !m_spellInfo->IsChanneled()) || m_spellInfo->Id == 14157)
    {
        // Remove used for cast item if need (it can be already NULL after TakeReagents call
        // in case delayed spell remove item at cast delay start
        TakeCastItem();

        // Okay, maps created, now prepare flags
        m_immediateHandled = false;
        m_spellState = SPELL_STATE_DELAYED;
        SetDelayStart(0);

        if (m_caster->HasUnitState(UNIT_STAT_CASTING) && !m_caster->IsNonMeleeSpellCasted(false, false, true))
            m_caster->ClearUnitState(UNIT_STAT_CASTING);
    }
    else
    {
        // Immediate spell, no big deal
        handle_immediate();
    }

    if (const std::vector<int32> *spell_triggered = sSpellMgr->GetSpellLinked(m_spellInfo->Id))
    {
        for (std::vector<int32>::const_iterator i = spell_triggered->begin(); i != spell_triggered->end(); ++i)
            if (*i < 0)
                m_caster->RemoveAurasDueToSpell(-(*i));
            else
                m_caster->CastSpell(m_targets.GetUnitTarget() ? m_targets.GetUnitTarget() : m_caster, *i, true);
    }

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
        m_caster->ToPlayer()->SetSpellModTakingSpell(this, false);

    SetExecutedCurrently(false);
}

void Spell::handle_immediate()
{
    // start channeling if applicable
    if (m_spellInfo->IsChanneled())
    {
        int32 duration = m_spellInfo->GetDuration();
        if (duration)
        {
            // First mod_duration then haste - see Missile Barrage
            // Apply duration mod
            if (Player* modOwner = m_caster->GetSpellModOwner())
                modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_DURATION, duration);
            // Apply haste mods
            if (m_spellInfo->AttributesEx5 & SPELL_ATTR5_HASTE_AFFECT_DURATION)
                m_caster->ModSpellCastTime(m_spellInfo, duration, this);

            m_spellState = SPELL_STATE_CASTING;
            m_caster->AddInterruptMask(m_spellInfo->ChannelInterruptFlags);
            SendChannelStart(duration);
        }
    }

    PrepareTargetProcessing();

    // process immediate effects (items, ground, etc.) also initialize some variables
    _handle_immediate_phase();

    for (std::list<TargetInfo>::iterator ihit= m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
        DoAllEffectOnTarget(&(*ihit));

    for (std::list<GOTargetInfo>::iterator ihit= m_UniqueGOTargetInfo.begin(); ihit != m_UniqueGOTargetInfo.end(); ++ihit)
        DoAllEffectOnTarget(&(*ihit));

    FinishTargetProcessing();

    // spell is finished, perform some last features of the spell here
    _handle_finish_phase();

    // Remove used for cast item if need (it can be already NULL after TakeReagents call
    TakeCastItem();

    // handle ammo consumption for Hunter's volley spell
    if (m_spellInfo->IsRangedWeaponSpell() && m_spellInfo->IsChanneled())
        TakeAmmo();


    if (m_spellState != SPELL_STATE_CASTING)
        finish(true);                                       // successfully finish spell cast (not last in case autorepeat or channel spell)
}

uint64 Spell::handle_delayed(uint64 t_offset)
{
    UpdatePointers();

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
        m_caster->ToPlayer()->SetSpellModTakingSpell(this, true);

    uint64 next_time = 0;

    PrepareTargetProcessing();

    if (!m_immediateHandled)
    {
        _handle_immediate_phase();
        m_immediateHandled = true;
    }

    bool single_missile = (m_targets.HasDst());

    // now recheck units targeting correctness (need before any effects apply to prevent adding immunity at first effect not allow apply second spell effect and similar cases)
    for (std::list<TargetInfo>::iterator ihit= m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
    {
        if (ihit->processed == false)
        {
            if (single_missile || ihit->timeDelay <= t_offset)
            {
                ihit->timeDelay = t_offset;
                DoAllEffectOnTarget(&(*ihit));
            }
            else if (next_time == 0 || ihit->timeDelay < next_time)
                next_time = ihit->timeDelay;
        }
    }

    // now recheck gameobject targeting correctness
    for (std::list<GOTargetInfo>::iterator ighit= m_UniqueGOTargetInfo.begin(); ighit != m_UniqueGOTargetInfo.end(); ++ighit)
    {
        if (ighit->processed == false)
        {
            if (single_missile || ighit->timeDelay <= t_offset)
                DoAllEffectOnTarget(&(*ighit));
            else if (next_time == 0 || ighit->timeDelay < next_time)
                next_time = ighit->timeDelay;
        }
    }

    FinishTargetProcessing();

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
        m_caster->ToPlayer()->SetSpellModTakingSpell(this, false);

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
    m_spellAura = NULL;
    // handle some immediate features of the spell here
    HandleThreatSpells();

    PrepareScriptHitHandlers();

    for (uint32 j = 0; j < MAX_SPELL_EFFECTS; ++j)
    {
        if (m_spellInfo->Effects[j].Effect == 0)
            continue;

        // apply Send Event effect to ground in case empty target lists
        if (m_spellInfo->Effects[j].Effect == SPELL_EFFECT_SEND_EVENT && !HaveTargetsForEffect(j))
        {
            HandleEffects(NULL, NULL, NULL, j);
            continue;
        }
    }

    // initialize Diminishing Returns Data
    m_diminishLevel = DIMINISHING_LEVEL_1;
    m_diminishGroup = DIMINISHING_NONE;

    // process items
    for (std::list<ItemTargetInfo>::iterator ihit= m_UniqueItemInfo.begin(); ihit != m_UniqueItemInfo.end(); ++ihit)
        DoAllEffectOnTarget(&(*ihit));

    if (!m_originalCaster)
        return;
    uint8 oldEffMask = m_effectMask;
    // process ground
    for (uint32 j = 0; j < MAX_SPELL_EFFECTS; ++j)
    {
        if (!m_spellInfo->Effects[j].IsEffect())
            continue;

        if (m_spellInfo->Effects[j].GetUsedTargetObjectType() == TARGET_OBJECT_TYPE_DEST)
        {
            if (!m_targets.HasDst()) // FIXME: this will ignore dest set in effect
                m_targets.SetDst(*m_caster);
            HandleEffects(m_originalCaster, NULL, NULL, j);
            m_effectMask |= (1<<j);
        }
        else if (m_spellInfo->Effects[j].GetUsedTargetObjectType() && !m_spellInfo->Effects[j].GetImplicitTargetType())
        {
            HandleEffects(m_originalCaster, NULL, NULL, j);
            m_effectMask |= (1<<j);
        }
    }
    if (oldEffMask != m_effectMask && m_UniqueTargetInfo.empty())
    {
        uint32 procAttacker = m_procAttacker;
        if (!procAttacker)
        {
            bool positive = true;
            for (uint8 i = 0; i< MAX_SPELL_EFFECTS; ++i)
                // If at least one effect negative spell is negative hit
                if (m_effectMask & (1<<i) && !m_spellInfo->IsPositiveEffect(i))
                {
                    positive = false;
                    break;
                }
            switch (m_spellInfo->DmgClass)
            {
                case SPELL_DAMAGE_CLASS_MAGIC:
                    if (positive)
                        procAttacker |= PROC_FLAG_DONE_SPELL_MAGIC_DMG_CLASS_POS;
                    else
                        procAttacker |= PROC_FLAG_DONE_SPELL_MAGIC_DMG_CLASS_NEG;
                break;
                case SPELL_DAMAGE_CLASS_NONE:
                    if (positive)
                        procAttacker |= PROC_FLAG_DONE_SPELL_NONE_DMG_CLASS_POS;
                    else
                        procAttacker |= PROC_FLAG_DONE_SPELL_NONE_DMG_CLASS_NEG;
                break;
            }
        }
        // Proc damage for spells which have only dest targets (2484 should proc 51486 for example)
        m_originalCaster->ProcDamageAndSpell(0, procAttacker, 0, m_procEx | PROC_EX_NORMAL_HIT, 0, BASE_ATTACK, m_spellInfo, m_triggeredByAuraSpell);
    }
}

void Spell::_handle_finish_phase()
{
    if (m_caster->m_movedPlayer)
    {
        // Take for real after all targets are processed
        if (m_needComboPoints)
            m_caster->m_movedPlayer->ClearComboPoints();

        // Real add combo points from effects
        if (m_comboPointGain)
            m_caster->m_movedPlayer->GainSpellComboPoints(m_comboPointGain);
    }
    // TODO: trigger proc phase finish here
}

void Spell::SendSpellCooldown()
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* _player = (Player*)m_caster;

    // mana/health/etc potions, disabled by client (until combat out as declarate)
    if (m_CastItem && m_CastItem->IsPotion())
    {
        // need in some way provided data for Spell::finish SendCooldownEvent
        _player->SetLastPotionId(m_CastItem->GetEntry());
        return;
    }

    // have infinity cooldown but set at aura apply                  // do not set cooldown for triggered spells (needed by reincarnation)
    if (m_spellInfo->Attributes & (SPELL_ATTR0_DISABLED_WHILE_ACTIVE | SPELL_ATTR0_PASSIVE) || (_triggeredCastFlags & TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD))
        return;

    _player->AddSpellAndCategoryCooldowns(m_spellInfo, m_CastItem ? m_CastItem->GetEntry() : 0, this);
}

void Spell::update(uint32 difftime)
{
    // update pointers based at it's GUIDs
    UpdatePointers();

    if (m_targets.GetUnitTargetGUID() && !m_targets.GetUnitTarget())
    {
        sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "Spell %u is cancelled due to removal of target.", m_spellInfo->Id);
        cancel();
        return;
    }

    // check if the player caster has moved before the spell finished
    if ((m_caster->GetTypeId() == TYPEID_PLAYER && m_timer != 0) &&
        m_caster->isMoving() && (m_spellInfo->InterruptFlags & SPELL_INTERRUPT_FLAG_MOVEMENT) &&
        (m_spellInfo->Effects[0].Effect != SPELL_EFFECT_STUCK || !m_caster->HasUnitMovementFlag(MOVEMENTFLAG_FALLING)))
    {
        // don't cancel for melee, autorepeat, triggered and instant spells
        if (!IsNextMeleeSwingSpell() && !IsAutoRepeat() && !IsTriggered())
            cancel();
    }

    switch (m_spellState)
    {
        case SPELL_STATE_PREPARING:
        {
            if (m_timer)
            {
                if (difftime >= m_timer)
                    m_timer = 0;
                else
                    m_timer -= difftime;
            }

            if (m_timer == 0 && !IsNextMeleeSwingSpell() && !IsAutoRepeat())
                // don't CheckCast for instant spells - done in spell::prepare, skip duplicate checks, needed for range checks for example
                cast(!m_casttime);
        } break;
        case SPELL_STATE_CASTING:
        {
            if (m_timer > 0)
            {
                // check if there are alive targets left
                if (!UpdateChanneledTargetList())
                {
                    sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "Channeled spell %d is removed due to lack of targets", m_spellInfo->Id);
                    SendChannelUpdate(0);
                    finish();
                }

                if (difftime >= m_timer)
                    m_timer = 0;
                else
                    m_timer -= difftime;
            }

            if (m_timer == 0)
            {
                SendChannelUpdate(0);

                // channeled spell processed independently for quest targeting
                // cast at creature (or GO) quest objectives update at successful cast channel finished
                // ignore autorepeat/melee casts for speed (not exist quest for spells (hm...)
                if (!IsAutoRepeat() && !IsNextMeleeSwingSpell())
                {
                    if (Player* p = m_caster->GetCharmerOrOwnerPlayerOrPlayerItself())
                    {
                        for (std::list<TargetInfo>::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
                        {
                            TargetInfo* target = &*ihit;
                            if (!IS_CRE_OR_VEH_GUID(target->targetGUID))
                                continue;

                            Unit* unit = m_caster->GetGUID() == target->targetGUID ? m_caster : ObjectAccessor::GetUnit(*m_caster, target->targetGUID);
                            if (unit == NULL)
                                continue;

                            p->CastedCreatureOrGO(unit->GetEntry(), unit->GetGUID(), m_spellInfo->Id);
                        }

                        for (std::list<GOTargetInfo>::iterator ihit = m_UniqueGOTargetInfo.begin(); ihit != m_UniqueGOTargetInfo.end(); ++ihit)
                        {
                            GOTargetInfo* target = &*ihit;

                            GameObject* go = m_caster->GetMap()->GetGameObject(target->targetGUID);
                            if (!go)
                                continue;

                            p->CastedCreatureOrGO(go->GetEntry(), go->GetGUID(), m_spellInfo->Id);
                        }
                    }
                }

                finish();
            }
        } break;
        default:
        {
        }break;
    }
}

void Spell::finish(bool ok)
{
    if (!m_caster)
        return;

    if (m_spellState == SPELL_STATE_FINISHED)
        return;
    m_spellState = SPELL_STATE_FINISHED;

    if (m_spellInfo->IsChanneled())
        m_caster->UpdateInterruptMask();

    if (m_caster->HasUnitState(UNIT_STAT_CASTING) && !m_caster->IsNonMeleeSpellCasted(false, false, true))
        m_caster->ClearUnitState(UNIT_STAT_CASTING);

    // Unsummon summon as possessed creatures on spell cancel
    if (m_spellInfo->IsChanneled() && m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        if (Unit* charm = m_caster->GetCharm())
            if (charm->GetTypeId() == TYPEID_UNIT
                && charm->ToCreature()->HasUnitTypeMask(UNIT_MASK_PUPPET)
                && charm->GetUInt32Value(UNIT_CREATED_BY_SPELL) == m_spellInfo->Id)
                ((Puppet*)charm)->UnSummon();
    }

    if (m_caster->GetTypeId() == TYPEID_UNIT)
        m_caster->ReleaseFocus(this);

    if (!ok)
        return;

    if (m_caster->GetTypeId() == TYPEID_UNIT && m_caster->ToCreature()->isSummon())
    {
        // Unsummon statue
        uint32 spell = m_caster->GetUInt32Value(UNIT_CREATED_BY_SPELL);
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spell);
        if (spellInfo && spellInfo->SpellIconID == 2056)
        {
            sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "Statue %d is unsummoned in spell %d finish", m_caster->GetGUIDLow(), m_spellInfo->Id);
            m_caster->setDeathState(JUST_DIED);
            return;
        }
    }

    if (IsAutoActionResetSpell())
    {
        bool found = false;
        Unit::AuraEffectList const& vIgnoreReset = m_caster->GetAuraEffectsByType(SPELL_AURA_IGNORE_MELEE_RESET);
        for (Unit::AuraEffectList::const_iterator i = vIgnoreReset.begin(); i != vIgnoreReset.end(); ++i)
        {
            if ((*i)->IsAffectedOnSpell(m_spellInfo))
            {
                found = true;
                break;
            }
        }
        if (!found && !(m_spellInfo->AttributesEx2 & SPELL_ATTR2_NOT_RESET_AUTO_ACTIONS))
        {
            m_caster->resetAttackTimer(BASE_ATTACK);
            if (m_caster->haveOffhandWeapon())
                m_caster->resetAttackTimer(OFF_ATTACK);
            m_caster->resetAttackTimer(RANGED_ATTACK);
        }
    }

    // potions disabled by client, send event "not in combat" if need
    if (m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        if (!m_triggeredByAuraSpell)
            m_caster->ToPlayer()->UpdatePotionCooldown(this);

        // triggered spell pointer can be not set in some cases
        // this is needed for proper apply of triggered spell mods
        m_caster->ToPlayer()->SetSpellModTakingSpell(this, true);

        // Take mods after trigger spell (needed for 14177 to affect 48664)
        // mods are taken only on succesfull cast and independantly from targets of the spell
        m_caster->ToPlayer()->RemoveSpellMods(this);
        m_caster->ToPlayer()->SetSpellModTakingSpell(this, false);
    }

    // Stop Attack for some spells
    if (m_spellInfo->Attributes & SPELL_ATTR0_STOP_ATTACK_TARGET)
        m_caster->AttackStop();
}

void Spell::SendCastResult(SpellCastResult result)
{
    if (result == SPELL_CAST_OK)
        return;

    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    if (m_caster->ToPlayer()->GetSession()->PlayerLoading())  // don't send cast results at loading time
        return;

    SendCastResult(m_caster->ToPlayer(), m_spellInfo, m_cast_count, result, m_customError);
}

void Spell::SendCastResult(Player* caster, SpellInfo const* spellInfo, uint8 cast_count, SpellCastResult result, SpellCustomErrors customError /*= SPELL_CUSTOM_ERROR_NONE*/)
{
    if (result == SPELL_CAST_OK)
        return;

    WorldPacket data(SMSG_CAST_FAILED, (4+1+1));
    data << uint8(cast_count);                              // single cast or multi 2.3 (0/1)
    data << uint32(spellInfo->Id);
    data << uint8(result);                                  // problem
    switch (result)
    {
        case SPELL_FAILED_REQUIRES_SPELL_FOCUS:
            data << uint32(spellInfo->RequiresSpellFocus);
            break;
        case SPELL_FAILED_REQUIRES_AREA:
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
            break;
        case SPELL_FAILED_TOTEMS:
            if (spellInfo->Totem[0])
                data << uint32(spellInfo->Totem[0]);
            if (spellInfo->Totem[1])
                data << uint32(spellInfo->Totem[1]);
            break;
        case SPELL_FAILED_TOTEM_CATEGORY:
            if (spellInfo->TotemCategory[0])
                data << uint32(spellInfo->TotemCategory[0]);
            if (spellInfo->TotemCategory[1])
                data << uint32(spellInfo->TotemCategory[1]);
            break;
        case SPELL_FAILED_EQUIPPED_ITEM_CLASS:
            data << uint32(spellInfo->EquippedItemClass);
            data << uint32(spellInfo->EquippedItemSubClassMask);
            //data << uint32(spellInfo->EquippedItemInventoryTypeMask);
            break;
        case SPELL_FAILED_TOO_MANY_OF_ITEM:
        {
             uint32 item = 0;
             for (int8 x = 0;x < 3; x++)
                 if (spellInfo->Effects[x].ItemType)
                     item = spellInfo->Effects[x].ItemType;
             ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(item);
             if (pProto && pProto->ItemLimitCategory)
                 data << uint32(pProto->ItemLimitCategory);
             break;
        }
        case SPELL_FAILED_CUSTOM_ERROR:
            data << uint32(customError);
            break;
        default:
            break;
    }
    caster->GetSession()->SendPacket(&data);
}

void Spell::SendSpellStart()
{
    if (!IsNeedSendToClient())
        return;

    //sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "Sending SMSG_SPELL_START id=%u", m_spellInfo->Id);

    uint32 castFlags = CAST_FLAG_UNKNOWN_2;

    if ((IsTriggered() && !m_spellInfo->IsAutoRepeatRangedSpell()) || m_triggeredByAuraSpell)
        castFlags |= CAST_FLAG_PENDING;

    if (m_spellInfo->Attributes & SPELL_ATTR0_REQ_AMMO)
        castFlags |= CAST_FLAG_AMMO;
    if ((m_caster->GetTypeId() == TYPEID_PLAYER ||
        (m_caster->GetTypeId() == TYPEID_UNIT && m_caster->ToCreature()->isPet()))
         && m_spellInfo->PowerType != POWER_HEALTH)
        castFlags |= CAST_FLAG_POWER_LEFT_SELF;

    if (m_spellInfo->RuneCostID && m_spellInfo->PowerType == POWER_RUNE)
        castFlags |= CAST_FLAG_UNKNOWN_19;

    WorldPacket data(SMSG_SPELL_START, (8+8+4+4+2));
    if (m_CastItem)
        data.append(m_CastItem->GetPackGUID());
    else
        data.append(m_caster->GetPackGUID());

    data.append(m_caster->GetPackGUID());
    data << uint8(m_cast_count);                            // pending spell cast?
    data << uint32(m_spellInfo->Id);                        // spellId
    data << uint32(castFlags);                              // cast flags
    data << uint32(m_timer);                                // delay?

    m_targets.Write(data);

    if (castFlags & CAST_FLAG_POWER_LEFT_SELF)
        data << uint32(m_caster->GetPower((Powers)m_spellInfo->PowerType));

    if (castFlags & CAST_FLAG_AMMO)
        WriteAmmoToPacket(&data);

    if (castFlags & CAST_FLAG_UNKNOWN_23)
    {
        data << uint32(0);
        data << uint32(0);
    }

    m_caster->SendMessageToSet(&data, true);
}

void Spell::SendSpellGo()
{
    // not send invisible spell casting
    if (!IsNeedSendToClient())
        return;

    //sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "Sending SMSG_SPELL_GO id=%u", m_spellInfo->Id);

    uint32 castFlags = CAST_FLAG_UNKNOWN_9;

    // triggered spells with spell visual != 0
    if ((IsTriggered() && !m_spellInfo->IsAutoRepeatRangedSpell()) || m_triggeredByAuraSpell)
        castFlags |= CAST_FLAG_PENDING;

    if (m_spellInfo->Attributes & SPELL_ATTR0_REQ_AMMO)
        castFlags |= CAST_FLAG_AMMO;                        // arrows/bullets visual
    if ((m_caster->GetTypeId() == TYPEID_PLAYER ||
        (m_caster->GetTypeId() == TYPEID_UNIT && m_caster->ToCreature()->isPet()))
        && m_spellInfo->PowerType != POWER_HEALTH)
        castFlags |= CAST_FLAG_POWER_LEFT_SELF; // should only be sent to self, but the current messaging doesn't make that possible

    if ((m_caster->GetTypeId() == TYPEID_PLAYER)
        && (m_caster->getClass() == CLASS_DEATH_KNIGHT)
        && m_spellInfo->RuneCostID
        && m_spellInfo->PowerType == POWER_RUNE)
    {
        castFlags |= CAST_FLAG_UNKNOWN_19;                   // same as in SMSG_SPELL_START
        castFlags |= CAST_FLAG_RUNE_LIST;                    // rune cooldowns list
        castFlags |= CAST_FLAG_UNKNOWN_9;                    // ??
    }

    if (m_spellInfo->HasEffect(SPELL_EFFECT_ACTIVATE_RUNE))
    {
        castFlags |= CAST_FLAG_RUNE_LIST;                    // rune cooldowns list
        castFlags |= CAST_FLAG_UNKNOWN_19;                   // same as in SMSG_SPELL_START
    }

    WorldPacket data(SMSG_SPELL_GO, 50);                    // guess size

    if (m_CastItem)
        data.append(m_CastItem->GetPackGUID());
    else
        data.append(m_caster->GetPackGUID());

    data.append(m_caster->GetPackGUID());
    data << uint8(m_cast_count);                            // pending spell cast?
    data << uint32(m_spellInfo->Id);                        // spellId
    data << uint32(castFlags);                              // cast flags
    data << uint32(getMSTime());                            // timestamp

    WriteSpellGoTargets(&data);

    m_targets.Write(data);

    if (castFlags & CAST_FLAG_POWER_LEFT_SELF)
        data << uint32(m_caster->GetPower((Powers)m_spellInfo->PowerType));

    if (castFlags & CAST_FLAG_RUNE_LIST)                   // rune cooldowns list
    {
        Player* player = m_caster->ToPlayer();
        uint8 runeMaskInitial = m_runesState;
        uint8 runeMaskAfterCast = player->GetRunesState();
        data << uint8(runeMaskInitial);                     // runes state before
        data << uint8(runeMaskAfterCast);                   // runes state after
        for (uint8 i = 0; i < MAX_RUNES; ++i)
        {
            uint8 mask = (1 << i);
            if (mask & runeMaskInitial && !(mask & runeMaskAfterCast))  // usable before andon cooldown now...
            {
                // float casts ensure the division is performed on floats as we need float result
                float baseCd = float(player->GetRuneBaseCooldown(i));
                data << uint8((baseCd - float(player->GetRuneCooldown(i))) / baseCd * 255); // rune cooldown passed
            }
        }
    }

    if (castFlags & CAST_FLAG_UNKNOWN_18)                   // unknown wotlk
    {
        data << float(0);
        data << uint32(0);
    }

    if (castFlags & CAST_FLAG_AMMO)
        WriteAmmoToPacket(&data);

    if (castFlags & CAST_FLAG_UNKNOWN_20)                   // unknown wotlk
    {
        data << uint32(0);
        data << uint32(0);
    }

    if (m_targets.GetTargetMask() & TARGET_FLAG_DEST_LOCATION)
    {
        data << uint8(0);
    }

    m_caster->SendMessageToSet(&data, true);
}

void Spell::WriteAmmoToPacket(WorldPacket* data)
{
    uint32 ammoInventoryType = 0;
    uint32 ammoDisplayID = 0;

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        Item* pItem = m_caster->ToPlayer()->GetWeaponForAttack(RANGED_ATTACK);
        if (pItem)
        {
            ammoInventoryType = pItem->GetTemplate()->InventoryType;
            if (ammoInventoryType == INVTYPE_THROWN)
                ammoDisplayID = pItem->GetTemplate()->DisplayInfoID;
            else
            {
                uint32 ammoID = m_caster->ToPlayer()->GetUInt32Value(PLAYER_AMMO_ID);
                if (ammoID)
                {
                    ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(ammoID);
                    if (pProto)
                    {
                        ammoDisplayID = pProto->DisplayInfoID;
                        ammoInventoryType = pProto->InventoryType;
                    }
                }
                else if (m_caster->HasAura(46699))      // Requires No Ammo
                {
                    ammoDisplayID = 5996;                   // normal arrow
                    ammoInventoryType = INVTYPE_AMMO;
                }
            }
        }
    }
    else
    {
        for (uint8 i = 0; i < 3; ++i)
        {
            if (uint32 item_id = m_caster->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + i))
            {
                if (ItemEntry const* itemEntry = sItemStore.LookupEntry(item_id))
                {
                    if (itemEntry->Class == ITEM_CLASS_WEAPON)
                    {
                        switch (itemEntry->SubClass)
                        {
                            case ITEM_SUBCLASS_WEAPON_THROWN:
                                ammoDisplayID = itemEntry->DisplayId;
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

    *data << uint32(ammoDisplayID);
    *data << uint32(ammoInventoryType);
}

void Spell::WriteSpellGoTargets(WorldPacket* data)
{
    // This function also fill data for channeled spells:
    // m_needAliveTargetMask req for stop channelig if one target die
    uint32 hit  = m_UniqueGOTargetInfo.size(); // Always hits on GO
    uint32 miss = 0;
    for (std::list<TargetInfo>::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
    {
        if ((*ihit).effectMask == 0)                  // No effect apply - all immuned add state
        {
            // possibly SPELL_MISS_IMMUNE2 for this??
            ihit->missCondition = SPELL_MISS_IMMUNE2;
            ++miss;
        }
        else if ((*ihit).missCondition == SPELL_MISS_NONE)
            ++hit;
        else
            ++miss;
    }

    *data << (uint8)hit;
    for (std::list<TargetInfo>::const_iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
    {
        if ((*ihit).missCondition == SPELL_MISS_NONE)       // Add only hits
        {
            *data << uint64(ihit->targetGUID);
            m_channelTargetEffectMask |=ihit->effectMask;
        }
    }

    for (std::list<GOTargetInfo>::const_iterator ighit = m_UniqueGOTargetInfo.begin(); ighit != m_UniqueGOTargetInfo.end(); ++ighit)
        *data << uint64(ighit->targetGUID);                 // Always hits

    *data << (uint8)miss;
    for (std::list<TargetInfo>::const_iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
    {
        if (ihit->missCondition != SPELL_MISS_NONE)        // Add only miss
        {
            *data << uint64(ihit->targetGUID);
            *data << uint8(ihit->missCondition);
            if (ihit->missCondition == SPELL_MISS_REFLECT)
                *data << uint8(ihit->reflectResult);
        }
    }
    // Reset m_needAliveTargetMask for non channeled spell
    if (!m_spellInfo->IsChanneled())
        m_channelTargetEffectMask = 0;
}

void Spell::SendLogExecute()
{
    WorldPacket data(SMSG_SPELLLOGEXECUTE, (8+4+4+4+4+8));

    data.append(m_caster->GetPackGUID());

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
        m_effectExecuteData[i] = NULL;
    }
    m_caster->SendMessageToSet(&data, true);
}

void Spell::ExecuteLogEffectTakeTargetPower(uint8 effIndex, Unit* target, uint32 powerType, uint32 powerTaken, float gainMultiplier)
{
    InitEffectExecuteData(effIndex);
    m_effectExecuteData[effIndex]->append(target->GetPackGUID());
    *m_effectExecuteData[effIndex] << uint32(powerTaken);
    *m_effectExecuteData[effIndex] << uint32(powerType);
    *m_effectExecuteData[effIndex] << float(gainMultiplier);
}

void Spell::ExecuteLogEffectExtraAttacks(uint8 effIndex, Unit* victim, uint32 attCount)
{
    InitEffectExecuteData(effIndex);
    m_effectExecuteData[effIndex]->append(victim->GetPackGUID());
    *m_effectExecuteData[effIndex] << uint32(attCount);
}

void Spell::ExecuteLogEffectInterruptCast(uint8 effIndex, Unit* victim, uint32 spellId)
{
    InitEffectExecuteData(effIndex);
    m_effectExecuteData[effIndex]->append(victim->GetPackGUID());
    *m_effectExecuteData[effIndex] << uint32(spellId);
}

void Spell::ExecuteLogEffectDurabilityDamage(uint8 effIndex, Unit* victim, uint32 /*itemslot*/, uint32 damage)
{
    InitEffectExecuteData(effIndex);
    m_effectExecuteData[effIndex]->append(victim->GetPackGUID());
    *m_effectExecuteData[effIndex] << uint32(m_spellInfo->Id);
    *m_effectExecuteData[effIndex] << uint32(damage);
}

void Spell::ExecuteLogEffectOpenLock(uint8 effIndex, Object* obj)
{
    InitEffectExecuteData(effIndex);
    m_effectExecuteData[effIndex]->append(obj->GetPackGUID());
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
    m_effectExecuteData[effIndex]->append(obj->GetPackGUID());
}

void Spell::ExecuteLogEffectUnsummonObject(uint8 effIndex, WorldObject* obj)
{
    InitEffectExecuteData(effIndex);
    m_effectExecuteData[effIndex]->append(obj->GetPackGUID());
}

void Spell::ExecuteLogEffectResurrect(uint8 effIndex, Unit* target)
{
    InitEffectExecuteData(effIndex);
    m_effectExecuteData[effIndex]->append(target->GetPackGUID());
}

void Spell::SendInterrupted(uint8 result)
{
    WorldPacket data(SMSG_SPELL_FAILURE, (8+4+1));
    data.append(m_caster->GetPackGUID());
    data << uint8(m_cast_count);
    data << uint32(m_spellInfo->Id);
    data << uint8(result);
    m_caster->SendMessageToSet(&data, true);

    data.Initialize(SMSG_SPELL_FAILED_OTHER, (8+4));
    data.append(m_caster->GetPackGUID());
    data << uint8(m_cast_count);
    data << uint32(m_spellInfo->Id);
    data << uint8(result);
    m_caster->SendMessageToSet(&data, true);
}

void Spell::SendChannelUpdate(uint32 time)
{
    if (time == 0)
    {
        m_caster->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
        m_caster->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);
    }

    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    WorldPacket data(MSG_CHANNEL_UPDATE, 8+4);
    data.append(m_caster->GetPackGUID());
    data << uint32(time);

    m_caster->SendMessageToSet(&data, true);
}

void Spell::SendChannelStart(uint32 duration)
{
    uint64 channelTarget = m_targets.GetObjectTargetGUID();

    WorldPacket data(MSG_CHANNEL_START, (8+4+4));
    data.append(m_caster->GetPackGUID());
    data << uint32(m_spellInfo->Id);
    data << uint32(duration);

    m_caster->SendMessageToSet(&data, true);

    m_timer = duration;
    if (channelTarget)
        m_caster->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, channelTarget);

    m_caster->SetUInt32Value(UNIT_CHANNEL_SPELL, m_spellInfo->Id);
}

void Spell::SendResurrectRequest(Player* target)
{
    // get ressurector name for creature resurrections, otherwise packet will be not accepted
    // for player resurrections the name is looked up by guid
    char const* resurrectorName = m_caster->GetTypeId() == TYPEID_PLAYER ? "" : m_caster->GetNameForLocaleIdx(target->GetSession()->GetSessionDbLocaleIndex());

    WorldPacket data(SMSG_RESURRECT_REQUEST, (8+4+strlen(resurrectorName)+1+1+1+4));
    data << uint64(m_caster->GetGUID()); // resurrector guid
    data << uint32(strlen(resurrectorName) + 1);

    data << resurrectorName;
    data << uint8(0); // null terminator

    data << uint8(m_caster->GetTypeId() == TYPEID_PLAYER ? 0 : 1); // "you'll be afflicted with resurrection sickness"
    // override delay sent with SMSG_CORPSE_RECLAIM_DELAY, set instant resurrection for spells with this attribute
    if (m_spellInfo->AttributesEx3 & SPELL_ATTR3_IGNORE_RESURRECTION_TIMER)
        data << uint32(0);
    target->GetSession()->SendPacket(&data);
}

void Spell::TakeCastItem()
{
    if (!m_CastItem || m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    // not remove cast item at triggered spell (equipping, weapon damage, etc)
    if (_triggeredCastFlags & TRIGGERED_IGNORE_CAST_ITEM)
        return;

    ItemTemplate const* proto = m_CastItem->GetTemplate();

    if (!proto)
    {
        // This code is to avoid a crash
        // I'm not sure, if this is really an error, but I guess every item needs a prototype
        sLog->outError("Cast item has no item prototype highId=%d, lowId=%d", m_CastItem->GetGUIDHigh(), m_CastItem->GetGUIDLow());
        return;
    }

    bool expendable = false;
    bool withoutCharges = false;

    for (int i = 0; i < MAX_ITEM_PROTO_SPELLS; ++i)
    {
        if (proto->Spells[i].SpellId)
        {
            // item has limited charges
            if (proto->Spells[i].SpellCharges)
            {
                if (proto->Spells[i].SpellCharges < 0)
                    expendable = true;

                int32 charges = m_CastItem->GetSpellCharges(i);

                // item has charges left
                if (charges)
                {
                    (charges > 0) ? --charges : ++charges;  // abs(charges) less at 1 after use
                    if (proto->Stackable == 1)
                        m_CastItem->SetSpellCharges(i, charges);
                    m_CastItem->SetState(ITEM_CHANGED, (Player*)m_caster);
                }

                // all charges used
                withoutCharges = (charges == 0);
            }
        }
    }

    if (expendable && withoutCharges)
    {
        uint32 count = 1;
        m_caster->ToPlayer()->DestroyItemCount(m_CastItem, count, true);

        // prevent crash at access to deleted m_targets.GetItemTarget
        if (m_CastItem == m_targets.GetItemTarget())
            m_targets.SetItemTarget(NULL);

        m_CastItem = NULL;
    }
}

void Spell::TakePower()
{
    if (m_CastItem || m_triggeredByAuraSpell)
        return;

    Powers powerType = Powers(m_spellInfo->PowerType);
    bool hit = true;
    if (m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        if (powerType == POWER_RAGE || powerType == POWER_ENERGY || powerType == POWER_RUNE)
            if (uint64 targetGUID = m_targets.GetUnitTargetGUID())
                for (std::list<TargetInfo>::iterator ihit= m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
                    if (ihit->targetGUID == targetGUID)
                    {
                        if (ihit->missCondition != SPELL_MISS_NONE && ihit->missCondition != SPELL_MISS_MISS/* && ihit->targetGUID != m_caster->GetGUID()*/)
                            hit = false;
                        if (ihit->missCondition != SPELL_MISS_NONE)
                        {
                            //lower spell cost on fail (by talent aura)
                            if (Player* modOwner = m_caster->ToPlayer()->GetSpellModOwner())
                                modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_SPELL_COST_REFUND_ON_FAIL, m_powerCost);
                        }
                        break;
                    }
    }

    if (powerType == POWER_RUNE)
    {
        TakeRunePower(hit);
        return;
    }

    if (!m_powerCost)
        return;

    // health as power used
    if (powerType == POWER_HEALTH)
    {
        m_caster->ModifyHealth(-(int32)m_powerCost);
        return;
    }

    if (powerType >= MAX_POWERS)
    {
        sLog->outError("Spell::TakePower: Unknown power type '%d'", powerType);
        return;
    }

    if (hit)
        m_caster->ModifyPower(powerType, -m_powerCost);
    else
        m_caster->ModifyPower(powerType, -irand(0, m_powerCost/4));

    // Set the five second timer
    if (powerType == POWER_MANA && m_powerCost > 0)
        m_caster->SetLastManaUse(getMSTime());
}

void Spell::TakeAmmo()
{
    if (m_attackType == RANGED_ATTACK && m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        Item* pItem = m_caster->ToPlayer()->GetWeaponForAttack(RANGED_ATTACK);

        // wands don't have ammo
        if (!pItem  || pItem->IsBroken() || pItem->GetTemplate()->SubClass == ITEM_SUBCLASS_WEAPON_WAND)
            return;

        if (pItem->GetTemplate()->InventoryType == INVTYPE_THROWN)
        {
            if (pItem->GetMaxStackCount() == 1)
            {
                // decrease durability for non-stackable throw weapon
                m_caster->ToPlayer()->DurabilityPointLossForEquipSlot(EQUIPMENT_SLOT_RANGED);
            }
            else
            {
                // decrease items amount for stackable throw weapon
                uint32 count = 1;
                m_caster->ToPlayer()->DestroyItemCount(pItem, count, true);
            }
        }
        else if (uint32 ammo = m_caster->ToPlayer()->GetUInt32Value(PLAYER_AMMO_ID))
            m_caster->ToPlayer()->DestroyItemCount(ammo, 1, true);
    }
}

SpellCastResult Spell::CheckRuneCost(uint32 runeCostID)
{
    if (m_spellInfo->PowerType != POWER_RUNE || !runeCostID)
        return SPELL_CAST_OK;

    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return SPELL_CAST_OK;

    Player* plr = (Player*)m_caster;

    if (plr->getClass() != CLASS_DEATH_KNIGHT)
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
            modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_COST, runeCost[i], this);
    }

    runeCost[RUNE_DEATH] = MAX_RUNES;                       // calculated later

    for (uint32 i = 0; i < MAX_RUNES; ++i)
    {
        RuneType rune = plr->GetCurrentRune(i);
        if ((plr->GetRuneCooldown(i) == 0) && (runeCost[rune] > 0))
            runeCost[rune]--;
    }

    for (uint32 i = 0; i < RUNE_DEATH; ++i)
        if (runeCost[i] > 0)
            runeCost[RUNE_DEATH] += runeCost[i];

    if (runeCost[RUNE_DEATH] > MAX_RUNES)
        return SPELL_FAILED_NO_POWER;                       // not sure if result code is correct

    return SPELL_CAST_OK;
}

void Spell::TakeRunePower(bool didHit)
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER || m_caster->getClass() != CLASS_DEATH_KNIGHT)
        return;

    SpellRuneCostEntry const* runeCostData = sSpellRuneCostStore.LookupEntry(m_spellInfo->RuneCostID);
    if (!runeCostData || (runeCostData->NoRuneCost() && runeCostData->NoRunicPowerGain()))
        return;

    Player* player = m_caster->ToPlayer();
    m_runesState = player->GetRunesState();                 // store previous state

    int32 runeCost[NUM_RUNE_TYPES];                         // blood, frost, unholy, death

    for (uint32 i = 0; i < RUNE_DEATH; ++i)
    {
        runeCost[i] = runeCostData->RuneCost[i];
        if (Player* modOwner = m_caster->GetSpellModOwner())
            modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_COST, runeCost[i], this);
    }

    runeCost[RUNE_DEATH] = 0;                               // calculated later

    for (uint32 i = 0; i < MAX_RUNES; ++i)
    {
        RuneType rune = player->GetCurrentRune(i);
        if (!player->GetRuneCooldown(i) && runeCost[rune] > 0)
        {
            player->SetRuneCooldown(i, didHit ? player->GetRuneBaseCooldown(i) : uint32(RUNE_MISS_COOLDOWN));
            player->SetLastUsedRune(rune);
            runeCost[rune]--;
        }
    }

    runeCost[RUNE_DEATH] = runeCost[RUNE_BLOOD] + runeCost[RUNE_UNHOLY] + runeCost[RUNE_FROST];

    if (runeCost[RUNE_DEATH] > 0)
    {
        for (uint32 i = 0; i < MAX_RUNES; ++i)
        {
            RuneType rune = player->GetCurrentRune(i);
            if (!player->GetRuneCooldown(i) && rune == RUNE_DEATH)
            {
                player->SetRuneCooldown(i, didHit ? player->GetRuneBaseCooldown(i) : uint32(RUNE_MISS_COOLDOWN));
                player->SetLastUsedRune(rune);
                runeCost[rune]--;

                // keep Death Rune type if missed
                if (didHit)
                    player->RestoreBaseRune(i);

                if (runeCost[RUNE_DEATH] == 0)
                    break;
            }
        }
    }

    // you can gain some runic power when use runes
    if (didHit)
        if (int32 rp = int32(runeCostData->runePowerGain * sWorld->getRate(RATE_POWER_RUNICPOWER_INCOME)))
            player->ModifyPower(POWER_RUNIC_POWER, int32(rp));
}

void Spell::TakeReagents()
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    ItemTemplate const* castItemTemplate = m_CastItem
            ? m_CastItem->GetTemplate()
            : NULL;

    // do not take reagents for these item casts
    if (castItemTemplate && castItemTemplate->Flags & ITEM_PROTO_FLAG_TRIGGERED_CAST)
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
        if (castItemTemplate && castItemTemplate->ItemId == itemid)
        {
            for (int s = 0; s < MAX_ITEM_PROTO_SPELLS; ++s)
            {
                // CastItem will be used up and does not count as reagent
                int32 charges = m_CastItem->GetSpellCharges(s);
                if (castItemTemplate->Spells[s].SpellCharges < 0 && abs(charges) < 2)
                {
                    ++itemcount;
                    break;
                }
            }

            m_CastItem = NULL;
        }

        // if GetItemTarget is also spell reagent
        if (m_targets.GetItemTargetEntry() == itemid)
            m_targets.SetItemTarget(NULL);

        p_caster->DestroyItemCount(itemid, itemcount, true);
    }
}

void Spell::HandleThreatSpells()
{
    if (m_UniqueTargetInfo.empty())
        return;

    if ((m_spellInfo->AttributesEx  & SPELL_ATTR1_NO_THREAT) ||
        (m_spellInfo->AttributesEx3 & SPELL_ATTR3_NO_INITIAL_AGGRO))
        return;

    float threat = 0.0f;
    if (SpellThreatEntry const* threatEntry = sSpellMgr->GetSpellThreatEntry(m_spellInfo->Id))
    {
        if (threatEntry->apPctMod != 0.0f)
            threat += threatEntry->apPctMod * m_caster->GetTotalAttackPowerValue(BASE_ATTACK);

        threat += threatEntry->flatMod;
    }
    else if ((m_spellInfo->AttributesCu & SPELL_ATTR0_CU_NO_INITIAL_THREAT) == 0)
        threat += m_spellInfo->SpellLevel;

    // past this point only multiplicative effects occur
    if (threat == 0.0f)
        return;

    // since 2.0.1 threat from positive effects also is distributed among all targets, so the overall caused threat is at most the defined bonus
    threat /= m_UniqueTargetInfo.size();

    for (std::list<TargetInfo>::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
    {
        if (ihit->missCondition != SPELL_MISS_NONE)
            continue;

        Unit* target = ObjectAccessor::GetUnit(*m_caster, ihit->targetGUID);
        if (!target)
            continue;

        // positive spells distribute threat among all units that are in combat with target, like healing
        if (m_spellInfo->_IsPositiveSpell())
            target->getHostileRefManager().threatAssist(m_caster, threat, m_spellInfo);
        // for negative spells threat gets distributed among affected targets
        else
        {
            if (!target->CanHaveThreatList())
                continue;

            target->AddThreat(m_caster, threat, m_spellInfo->GetSchoolMask(), m_spellInfo);
        }
    }
    sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "Spell %u, added an additional %f threat for %s %u target(s)", m_spellInfo->Id, threat, m_spellInfo->_IsPositiveSpell() ? "assisting" : "harming", uint32(m_UniqueTargetInfo.size()));
}

void Spell::HandleEffects(Unit* pUnitTarget, Item* pItemTarget, GameObject* pGOTarget, uint32 i)
{
    //effect has been handled, skip it
    if (m_effectMask & (1<<i))
        return;

    unitTarget = pUnitTarget;
    itemTarget = pItemTarget;
    gameObjTarget = pGOTarget;

    uint8 eff = m_spellInfo->Effects[i].Effect;

    sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "Spell: %u Effect : %u", m_spellInfo->Id, eff);

    //we do not need DamageMultiplier here.
    damage = CalculateDamage(i, NULL);

    bool preventDefault = CallScriptEffectHandlers((SpellEffIndex)i);

    if (!preventDefault && eff < TOTAL_SPELL_EFFECTS)
    {
        (this->*SpellEffects[eff])((SpellEffIndex)i);
    }
}

SpellCastResult Spell::CheckCast(bool strict)
{
    // check death state
    if (!m_caster->isAlive() && !(m_spellInfo->Attributes & SPELL_ATTR0_PASSIVE) && !((m_spellInfo->Attributes & SPELL_ATTR0_CASTABLE_WHILE_DEAD) || (IsTriggered() && !m_triggeredByAuraSpell)))
        return SPELL_FAILED_CASTER_DEAD;

    // check cooldowns to prevent cheating
    if (m_caster->GetTypeId() == TYPEID_PLAYER && !(m_spellInfo->Attributes & SPELL_ATTR0_PASSIVE))
    {
        //can cast triggered (by aura only?) spells while have this flag
        if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CASTER_AURASTATE) && m_caster->ToPlayer()->HasFlag(PLAYER_FLAGS, PLAYER_ALLOW_ONLY_ABILITY))
            return SPELL_FAILED_SPELL_IN_PROGRESS;

        if (m_caster->ToPlayer()->HasSpellCooldown(m_spellInfo->Id))
        {
            if (m_triggeredByAuraSpell)
                return SPELL_FAILED_DONT_REPORT;
            else
                return SPELL_FAILED_NOT_READY;
        }
    }

    if (m_spellInfo->AttributesEx7 & SPELL_ATTR7_IS_CHEAT_SPELL && !m_caster->HasFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_ALLOW_CHEAT_SPELLS))
        return SPELL_FAILED_SPELL_UNAVAILABLE;

    // Check global cooldown
    if (strict && !(_triggeredCastFlags & TRIGGERED_IGNORE_GCD) && HasGlobalCooldown())
        return SPELL_FAILED_NOT_READY;

    // only triggered spells can be processed an ended battleground
    if (!IsTriggered() && m_caster->GetTypeId() == TYPEID_PLAYER)
        if (Battleground* bg = m_caster->ToPlayer()->GetBattleground())
            if (bg->GetStatus() == STATUS_WAIT_LEAVE)
                return SPELL_FAILED_DONT_REPORT;

    if (m_caster->GetTypeId() == TYPEID_PLAYER && VMAP::VMapFactory::createOrGetVMapManager()->isLineOfSightCalcEnabled())
    {
        if (m_spellInfo->Attributes & SPELL_ATTR0_OUTDOORS_ONLY &&
                !m_caster->GetMap()->IsOutdoors(m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ()))
            return SPELL_FAILED_ONLY_OUTDOORS;

        if (m_spellInfo->Attributes & SPELL_ATTR0_INDOORS_ONLY &&
                m_caster->GetMap()->IsOutdoors(m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ()))
            return SPELL_FAILED_ONLY_INDOORS;
    }

    // only check at first call, Stealth auras are already removed at second call
    // for now, ignore triggered spells
    if (strict && !(_triggeredCastFlags & TRIGGERED_IGNORE_SHAPESHIFT))
    {
        bool checkForm = true;
        // Ignore form req aura
        Unit::AuraEffectList const& ignore = m_caster->GetAuraEffectsByType(SPELL_AURA_MOD_IGNORE_SHAPESHIFT);
        for (Unit::AuraEffectList::const_iterator i = ignore.begin(); i != ignore.end(); ++i)
        {
            if (!(*i)->IsAffectedOnSpell(m_spellInfo))
                continue;
            checkForm = false;
            break;
        }
        if (checkForm)
        {
            // Cannot be used in this stance/form
            SpellCastResult shapeError = m_spellInfo->CheckShapeshift(m_caster->GetShapeshiftForm());
            if (shapeError != SPELL_CAST_OK)
                return shapeError;

            if ((m_spellInfo->Attributes & SPELL_ATTR0_ONLY_STEALTHED) && !(m_caster->HasStealthAura()))
                return SPELL_FAILED_ONLY_STEALTHED;
        }
    }

    bool reqCombat=true;
    Unit::AuraEffectList const& stateAuras = m_caster->GetAuraEffectsByType(SPELL_AURA_ABILITY_IGNORE_AURASTATE);
    for (Unit::AuraEffectList::const_iterator j = stateAuras.begin(); j != stateAuras.end(); ++j)
    {
        if ((*j)->IsAffectedOnSpell(m_spellInfo))
        {
            m_needComboPoints = false;
            if ((*j)->GetMiscValue() == 1)
            {
                reqCombat=false;
                break;
            }
        }
    }

    // caster state requirements
    // not for triggered spells (needed by execute)
    if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CASTER_AURASTATE))
    {
        if (m_spellInfo->CasterAuraState && !m_caster->HasAuraState(AuraStateType(m_spellInfo->CasterAuraState), m_spellInfo, m_caster))
            return SPELL_FAILED_CASTER_AURASTATE;
        if (m_spellInfo->CasterAuraStateNot && m_caster->HasAuraState(AuraStateType(m_spellInfo->CasterAuraStateNot), m_spellInfo, m_caster))
            return SPELL_FAILED_CASTER_AURASTATE;

        // Note: spell 62473 requres casterAuraSpell = triggering spell
        if (m_spellInfo->CasterAuraSpell && !m_caster->HasAura(sSpellMgr->GetSpellIdForDifficulty(m_spellInfo->CasterAuraSpell, m_caster)))
            return SPELL_FAILED_CASTER_AURASTATE;
        if (m_spellInfo->ExcludeCasterAuraSpell && m_caster->HasAura(sSpellMgr->GetSpellIdForDifficulty(m_spellInfo->ExcludeCasterAuraSpell, m_caster)))
            return SPELL_FAILED_CASTER_AURASTATE;

        if (reqCombat && m_caster->isInCombat() && !m_spellInfo->CanBeUsedInCombat())
            return SPELL_FAILED_AFFECTING_COMBAT;
    }

    // cancel autorepeat spells if cast start when moving
    // (not wand currently autorepeat cast delayed to moving stop anyway in spell update code)
    if (m_caster->GetTypeId() == TYPEID_PLAYER && m_caster->ToPlayer()->isMoving())
    {
        // skip stuck spell to allow use it in falling case and apply spell limitations at movement
        if ((!m_caster->HasUnitMovementFlag(MOVEMENTFLAG_FALLING) || m_spellInfo->Effects[0].Effect != SPELL_EFFECT_STUCK) &&
            (IsAutoRepeat() || (m_spellInfo->AuraInterruptFlags & AURA_INTERRUPT_FLAG_NOT_SEATED) != 0))
            return SPELL_FAILED_MOVING;
    }


    Vehicle* vehicle = m_caster->GetVehicle();
    if (vehicle && !(_triggeredCastFlags & TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE))
    {
        uint16 checkMask = 0;
        for (uint8 effIndex = EFFECT_0; effIndex < MAX_SPELL_EFFECTS; ++effIndex)
        {
            SpellEffectInfo const* effInfo = &m_spellInfo->Effects[effIndex];
            if (effInfo->ApplyAuraName == SPELL_AURA_MOD_SHAPESHIFT)
            {
                SpellShapeshiftEntry const* shapeShiftEntry = sSpellShapeshiftStore.LookupEntry(effInfo->MiscValue);
                if (shapeShiftEntry && (shapeShiftEntry->flags1 & 1) == 0)  // unk flag
                    checkMask |= VEHICLE_SEAT_FLAG_UNCONTROLLED;
                break;
            }
        }

        if (m_spellInfo->HasAura(SPELL_AURA_MOUNTED))
            checkMask |= VEHICLE_SEAT_FLAG_CAN_CAST_MOUNT_SPELL;

        if (!checkMask)
            checkMask = VEHICLE_SEAT_FLAG_CAN_ATTACK;

        VehicleSeatEntry const* vehicleSeat = vehicle->GetSeatForPassenger(m_caster);
        if (!(m_spellInfo->AttributesEx6 & SPELL_ATTR6_CASTABLE_WHILE_ON_VEHICLE) && !(m_spellInfo->Attributes & SPELL_ATTR0_CASTABLE_WHILE_MOUNTED)
            && (vehicleSeat->m_flags & checkMask) != checkMask)
            return SPELL_FAILED_DONT_REPORT;
    }

    // Don't check explicit target for passive spells (workaround) (check should be skipped only for learn case)
    // those spells may have incorrect target entries or not filled at all (for example 15332)
    // such spells when learned are not targeting anyone using targeting system, they should apply directly to caster instead
    // also, such casts shouldn't be sent to client
    if (!((m_spellInfo->Attributes & SPELL_ATTR0_PASSIVE) && (!m_targets.GetUnitTarget() || m_targets.GetUnitTarget() == m_caster)))
    {
        // Check explicit target for m_originalCaster - todo: get rid of such workarounds
        SpellCastResult castResult = m_spellInfo->CheckExplicitTarget(m_originalCaster ? m_originalCaster : m_caster, m_targets.GetObjectTarget(), m_targets.GetItemTarget());
        if (castResult != SPELL_CAST_OK)
            return castResult;
    }

    if (Unit* target = m_targets.GetUnitTarget())
    {
        SpellCastResult castResult = m_spellInfo->CheckTarget(m_caster, target, false);
        if (castResult != SPELL_CAST_OK)
            return castResult;

        if (target != m_caster)
        {
            // Must be behind the target
            if ((m_spellInfo->AttributesCu & SPELL_ATTR0_CU_REQ_CASTER_BEHIND_TARGET) && target->HasInArc(static_cast<float>(M_PI), m_caster))
                return SPELL_FAILED_NOT_BEHIND;

            // Target must be facing you
            if ((m_spellInfo->AttributesCu & SPELL_ATTR0_CU_REQ_TARGET_FACING_CASTER) && !target->HasInArc(static_cast<float>(M_PI), m_caster))
                return SPELL_FAILED_NOT_INFRONT;

            if (!(m_spellInfo->AttributesEx2 & SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS) && VMAP::VMapFactory::checkSpellForLoS(m_spellInfo->Id) && !m_caster->IsWithinLOSInMap(target))
                return SPELL_FAILED_LINE_OF_SIGHT;
        }
        else
        {
            if (m_caster->GetTypeId() == TYPEID_PLAYER) // Target - is player caster
            {
                // Lay on Hands - cannot be self-cast on paladin with Forbearance or after using Avenging Wrath
                if (m_spellInfo->SpellFamilyName == SPELLFAMILY_PALADIN && m_spellInfo->SpellFamilyFlags[0] & 0x0008000)
                    if (target->HasAura(61988)) // Immunity shield marker
                        return SPELL_FAILED_TARGET_AURASTATE;
            }
        }
    }

    // check pet presence
    for (int j = 0; j < MAX_SPELL_EFFECTS; ++j)
    {
        if (m_spellInfo->Effects[j].TargetA.GetTarget() == TARGET_UNIT_PET)
        {
            if (!m_caster->GetGuardianPet())
            {
                if (m_triggeredByAuraSpell)              // not report pet not existence for triggered spells
                    return SPELL_FAILED_DONT_REPORT;
                else
                    return SPELL_FAILED_NO_PET;
            }
            break;
        }
    }

    // Spell casted only on battleground
    if ((m_spellInfo->AttributesEx3 & SPELL_ATTR3_BATTLEGROUND) &&  m_caster->GetTypeId() == TYPEID_PLAYER)
        if (!m_caster->ToPlayer()->InBattleground())
            return SPELL_FAILED_ONLY_BATTLEGROUNDS;

    // do not allow spells to be cast in arenas
    // - with greater than 10 min CD without SPELL_ATTR4_USABLE_IN_ARENA flag
    // - with SPELL_ATTR4_NOT_USABLE_IN_ARENA flag
    if ((m_spellInfo->AttributesEx4 & SPELL_ATTR4_NOT_USABLE_IN_ARENA) ||
        (m_spellInfo->GetRecoveryTime() > 10 * MINUTE * IN_MILLISECONDS && !(m_spellInfo->AttributesEx4 & SPELL_ATTR4_USABLE_IN_ARENA)))
        if (MapEntry const* mapEntry = sMapStore.LookupEntry(m_caster->GetMapId()))
            if (mapEntry->IsBattleArena())
                return SPELL_FAILED_NOT_IN_ARENA;

    // zone check
    if (m_caster->GetTypeId() == TYPEID_UNIT || !m_caster->ToPlayer()->isGameMaster())
    {
        uint32 zone, area;
        m_caster->GetZoneAndAreaId(zone, area);

        SpellCastResult locRes= m_spellInfo->CheckLocation(m_caster->GetMapId(), zone, area,
            m_caster->GetTypeId() == TYPEID_PLAYER ? m_caster->ToPlayer() : NULL);
        if (locRes != SPELL_CAST_OK)
            return locRes;
    }

    // not let players cast spells at mount (and let do it to creatures)
    if (m_caster->IsMounted() && m_caster->GetTypeId() == TYPEID_PLAYER && !(_triggeredCastFlags & TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE) &&
        !m_spellInfo->IsPassive() && !(m_spellInfo->Attributes & SPELL_ATTR0_CASTABLE_WHILE_MOUNTED))
    {
        if (m_caster->isInFlight())
            return SPELL_FAILED_NOT_ON_TAXI;
        else
            return SPELL_FAILED_NOT_MOUNTED;
    }

    SpellCastResult castResult = SPELL_CAST_OK;

    // always (except passive spells) check items (focus object can be required for any type casts)
    if (!m_spellInfo->IsPassive())
    {
        castResult = CheckItems();
        if (castResult != SPELL_CAST_OK)
            return castResult;
    }

    // Triggered spells also have range check
    // TODO: determine if there is some flag to enable/disable the check
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
        castResult = CheckCasterAuras();
        if (castResult != SPELL_CAST_OK)
            return castResult;
    }

    // script hook
    castResult = CallScriptCheckCastHandlers();
    if (castResult != SPELL_CAST_OK)
        return castResult;

    for (int i = 0; i < MAX_SPELL_EFFECTS; i++)
    {
        // for effects of spells that have only one target
        switch (m_spellInfo->Effects[i].Effect)
        {
            case SPELL_EFFECT_DUMMY:
            {
                if (m_spellInfo->Id == 51582)          // Rocket Boots Engaged
                {
                    if (m_caster->IsInWater())
                        return SPELL_FAILED_ONLY_ABOVEWATER;
                }
                else if (m_spellInfo->SpellIconID == 156)    // Holy Shock
                {
                    // spell different for friends and enemies
                    // hurt version required facing
                    if (m_targets.GetUnitTarget() && !m_caster->IsFriendlyTo(m_targets.GetUnitTarget()) && !m_caster->HasInArc(static_cast<float>(M_PI), m_targets.GetUnitTarget()))
                        return SPELL_FAILED_UNIT_NOT_INFRONT;
                }
                else if (m_spellInfo->SpellFamilyName == SPELLFAMILY_DEATHKNIGHT && m_spellInfo->SpellFamilyFlags[0] == 0x2000) // Death Coil (DeathKnight)
                {
                    Unit* target = m_targets.GetUnitTarget();
                    if (!target || (target->IsFriendlyTo(m_caster) && target->GetCreatureType() != CREATURE_TYPE_UNDEAD))
                        return SPELL_FAILED_BAD_TARGETS;
                }
                else if (m_spellInfo->Id == 19938)          // Awaken Peon
                {
                    Unit* unit = m_targets.GetUnitTarget();
                    if (!unit || !unit->HasAura(17743))
                        return SPELL_FAILED_BAD_TARGETS;
                }
                else if (m_spellInfo->Id == 52264)          // Deliver Stolen Horse
                {
                    if (!m_caster->FindNearestCreature(28653, 5))
                        return SPELL_FAILED_OUT_OF_RANGE;
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
            case SPELL_EFFECT_LEARN_PET_SPELL:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_BAD_TARGETS;

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
            case SPELL_EFFECT_APPLY_GLYPH:
            {
                uint32 glyphId = m_spellInfo->Effects[i].MiscValue;
                if (GlyphPropertiesEntry const* gp = sGlyphPropertiesStore.LookupEntry(glyphId))
                    if (m_caster->HasAura(gp->SpellId))
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

                if (!pet->GetCurrentFoodBenefitLevel(foodItem->GetTemplate()->ItemLevel))
                    return SPELL_FAILED_FOOD_LOWLEVEL;

                if (m_caster->isInCombat() || pet->isInCombat())
                    return SPELL_FAILED_AFFECTING_COMBAT;

                break;
            }
            case SPELL_EFFECT_POWER_BURN:
            case SPELL_EFFECT_POWER_DRAIN:
            {
                // Can be area effect, Check only for players and not check if target - caster (spell can have multiply drain/burn effects)
                if (m_caster->GetTypeId() == TYPEID_PLAYER)
                    if (Unit* target = m_targets.GetUnitTarget())
                        if (target != m_caster && target->getPowerType() != Powers(m_spellInfo->Effects[i].MiscValue))
                            return SPELL_FAILED_BAD_TARGETS;
                break;
            }
            case SPELL_EFFECT_CHARGE:
            {
                if (m_spellInfo->SpellFamilyName == SPELLFAMILY_WARRIOR)
                {
                    // Warbringer - can't be handled in proc system - should be done before checkcast root check and charge effect process
                    if (strict && m_caster->IsScriptOverriden(m_spellInfo, 6953))
                        m_caster->RemoveMovementImpairingAuras();
                }
                if (m_caster->HasUnitState(UNIT_STAT_ROOT))
                    return SPELL_FAILED_ROOTED;
                break;
            }
            case SPELL_EFFECT_SKINNING:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER || !m_targets.GetUnitTarget() || m_targets.GetUnitTarget()->GetTypeId() != TYPEID_UNIT)
                    return SPELL_FAILED_BAD_TARGETS;

                if (!(m_targets.GetUnitTarget()->GetUInt32Value(UNIT_FIELD_FLAGS) & UNIT_FLAG_SKINNABLE))
                    return SPELL_FAILED_TARGET_UNSKINNABLE;

                Creature* creature = m_targets.GetUnitTarget()->ToCreature();
                if (creature->GetCreatureType() != CREATURE_TYPE_CRITTER && !creature->loot.isLooted())
                    return SPELL_FAILED_TARGET_NOT_LOOTED;

                uint32 skill = creature->GetCreatureInfo()->GetRequiredLootSkill();

                int32 skillValue = m_caster->ToPlayer()->GetSkillValue(skill);
                int32 TargetLevel = m_targets.GetUnitTarget()->getLevel();
                int32 ReqValue = (skillValue < 100 ? (TargetLevel-10) * 10 : TargetLevel * 5);
                if (ReqValue > skillValue)
                    return SPELL_FAILED_LOW_CASTLEVEL;

                // chance for fail at orange skinning attempt
                if ((m_selfContainer && (*m_selfContainer) == this) &&
                    skillValue < sWorld->GetConfigMaxSkillValue() &&
                    (ReqValue < 0 ? 0 : ReqValue) > irand(skillValue - 25, skillValue + 37))
                    return SPELL_FAILED_TRY_AGAIN;

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

                Item* pTempItem = NULL;
                if (m_targets.GetTargetMask() & TARGET_FLAG_TRADE_ITEM)
                {
                    if (TradeData* pTrade = m_caster->ToPlayer()->GetTradeData())
                        pTempItem = pTrade->GetTraderData()->GetItem(TradeSlots(m_targets.GetItemTargetGUID()));
                }
                else if (m_targets.GetTargetMask() & TARGET_FLAG_ITEM)
                    pTempItem = m_caster->ToPlayer()->GetItemByGuid(m_targets.GetItemTargetGUID());

                // we need a go target, or an openable item target in case of TARGET_GAMEOBJECT_ITEM_TARGET
                if (m_spellInfo->Effects[i].TargetA.GetTarget() == TARGET_GAMEOBJECT_ITEM_TARGET &&
                    !m_targets.GetGOTarget() &&
                    (!pTempItem || !pTempItem->GetTemplate()->LockID || !pTempItem->IsLocked()))
                    return SPELL_FAILED_BAD_TARGETS;

                if (m_spellInfo->Id != 1842 || (m_targets.GetGOTarget() &&
                    m_targets.GetGOTarget()->GetGOInfo()->type != GAMEOBJECT_TYPE_TRAP))
                    if (m_caster->ToPlayer()->InBattleground() && // In Battleground players can use only flags and banners
                        !m_caster->ToPlayer()->CanUseBattlegroundObject())
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
                    lockId = itm->GetTemplate()->LockID;

                SkillType skillId = SKILL_NONE;
                int32 reqSkillValue = 0;
                int32 skillValue = 0;

                // check lock compatibility
                SpellCastResult res = CanOpenLock(i, lockId, skillId, reqSkillValue, skillValue);
                if (res != SPELL_CAST_OK)
                    return res;

                // chance for fail at orange mining/herb/LockPicking gathering attempt
                // second check prevent fail at rechecks
                if (skillId != SKILL_NONE && (!m_selfContainer || ((*m_selfContainer) != this)))
                {
                    bool canFailAtMax = skillId != SKILL_HERBALISM && skillId != SKILL_MINING;

                    // chance for failure in orange gather / lockpick (gathering skill can't fail at maxskill)
                    if ((canFailAtMax || skillValue < sWorld->GetConfigMaxSkillValue()) && reqSkillValue > irand(skillValue - 25, skillValue + 37))
                        return SPELL_FAILED_TRY_AGAIN;
                }
                break;
            }
            case SPELL_EFFECT_SUMMON_DEAD_PET:
            {
                Creature* pet = m_caster->GetGuardianPet();
                if (!pet)
                    return SPELL_FAILED_NO_PET;

                if (pet->isAlive())
                    return SPELL_FAILED_ALREADY_HAVE_SUMMON;

                break;
            }
            // This is generic summon effect
            case SPELL_EFFECT_SUMMON:
            {
                SummonPropertiesEntry const* SummonProperties = sSummonPropertiesStore.LookupEntry(m_spellInfo->Effects[i].MiscValueB);
                if (!SummonProperties)
                    break;
                switch (SummonProperties->Category)
                {
                    case SUMMON_CATEGORY_PET:
                        if (m_caster->GetPetGUID())
                            return SPELL_FAILED_ALREADY_HAVE_SUMMON;
                    case SUMMON_CATEGORY_PUPPET:
                        if (m_caster->GetCharmGUID())
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
                    if (m_targets.GetUnitTarget()->GetPetGUID())
                        return SPELL_FAILED_ALREADY_HAVE_SUMMON;
                }
                break;
            }
            case SPELL_EFFECT_SUMMON_PET:
            {
                if (m_caster->GetPetGUID())                  //let warlock do a replacement summon
                {
                    if (m_caster->GetTypeId() == TYPEID_PLAYER && m_caster->getClass() == CLASS_WARLOCK)
                    {
                        if (strict)                         //starting cast, trigger pet stun (cast by pet so it doesn't attack player)
                            if (Pet* pet = m_caster->ToPlayer()->GetPet())
                                pet->CastSpell(pet, 32752, true, NULL, NULL, pet->GetGUID());
                    }
                    else
                        return SPELL_FAILED_ALREADY_HAVE_SUMMON;
                }

                if (m_caster->GetCharmGUID())
                    return SPELL_FAILED_ALREADY_HAVE_CHARM;

                break;
            }
            case SPELL_EFFECT_SUMMON_PLAYER:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_BAD_TARGETS;
                if (!m_caster->ToPlayer()->GetSelection())
                    return SPELL_FAILED_BAD_TARGETS;

                Player* target = ObjectAccessor::FindPlayer(m_caster->ToPlayer()->GetSelection());
                if (!target || m_caster->ToPlayer() == target || (!target->IsInSameRaidWith(m_caster->ToPlayer()) && m_spellInfo->Id != 48955)) // refer-a-friend spell
                    return SPELL_FAILED_BAD_TARGETS;

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

                    InstanceTemplate const* instance = sObjectMgr->GetInstanceTemplate(mapId);
                    if (!instance)
                        return SPELL_FAILED_TARGET_NOT_IN_INSTANCE;
                    if (!target->Satisfy(sObjectMgr->GetAccessRequirement(mapId, difficulty), mapId))
                        return SPELL_FAILED_BAD_TARGETS;
                }
                break;
            }
            // RETURN HERE
            case SPELL_EFFECT_SUMMON_RAF_FRIEND:
            {
                if(m_caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_BAD_TARGETS;

                Player* playerCaster = m_caster->ToPlayer();
                    //
                if(!(playerCaster->GetSelection()))
                    return SPELL_FAILED_BAD_TARGETS;

                Player* target = ObjectAccessor::FindPlayer(playerCaster->GetSelection());

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
                // Spell 781 (Disengage) requires player to be in combat
                if (m_caster->GetTypeId() == TYPEID_PLAYER && m_spellInfo->Id == 781 && !m_caster->isInCombat())
                    return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

                Unit* target = m_targets.GetUnitTarget();
                if (m_caster == target && m_caster->HasUnitState(UNIT_STAT_ROOT))
                {
                    if (m_caster->GetTypeId() == TYPEID_PLAYER)
                        return SPELL_FAILED_ROOTED;
                    else
                        return SPELL_FAILED_DONT_REPORT;
                }
                break;
            }
            case SPELL_EFFECT_TALENT_SPEC_SELECT:
                // can't change during already started arena/battleground
                if (m_caster->GetTypeId() == TYPEID_PLAYER)
                    if (Battleground const* bg = m_caster->ToPlayer()->GetBattleground())
                        if (bg->GetStatus() == STATUS_IN_PROGRESS)
                            return SPELL_FAILED_NOT_IN_BATTLEGROUND;
                break;
            default:
                break;
        }
    }

    for (int i = 0; i < MAX_SPELL_EFFECTS; i++)
    {
        switch (m_spellInfo->Effects[i].ApplyAuraName)
        {
            case SPELL_AURA_DUMMY:
            {
                //custom check
                switch (m_spellInfo->Id)
                {
                    // Tag Murloc
                    case 30877:
                    {
                        Unit* target = m_targets.GetUnitTarget();
                        if (!target || target->GetEntry() != 17326)
                            return SPELL_FAILED_BAD_TARGETS;
                        break;
                    }
                    case 61336:
                        if (m_caster->GetTypeId() != TYPEID_PLAYER || !m_caster->ToPlayer()->IsInFeralForm())
                            return SPELL_FAILED_ONLY_SHAPESHIFT;
                        break;
                    case 1515:
                    {
                        if (m_caster->GetTypeId() != TYPEID_PLAYER)
                            return SPELL_FAILED_BAD_TARGETS;

                        if (!m_targets.GetUnitTarget() || m_targets.GetUnitTarget()->GetTypeId() == TYPEID_PLAYER)
                            return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

                        Creature* target = m_targets.GetUnitTarget()->ToCreature();

                        if (target->getLevel() > m_caster->getLevel())
                            return SPELL_FAILED_HIGHLEVEL;

                        // use SMSG_PET_TAME_FAILURE?
                        if (!target->GetCreatureInfo()->isTameable (m_caster->ToPlayer()->CanTameExoticPets()))
                            return SPELL_FAILED_BAD_TARGETS;

                        if (m_caster->GetPetGUID())
                            return SPELL_FAILED_ALREADY_HAVE_SUMMON;

                        if (m_caster->GetCharmGUID())
                            return SPELL_FAILED_ALREADY_HAVE_CHARM;

                        break;
                    }
                    case 44795: // Parachute
                    {
                        float x, y, z;
                        m_caster->GetPosition(x, y, z);
                        float ground_Z = m_caster->GetMap()->GetHeight(x, y, z);
                        if (fabs(ground_Z - z) < 0.1f)
                            return SPELL_FAILED_DONT_REPORT;
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case SPELL_AURA_MOD_POSSESS_PET:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_NO_PET;

                Pet* pet = m_caster->ToPlayer()->GetPet();
                if (!pet)
                    return SPELL_FAILED_NO_PET;

                if (pet->GetCharmerGUID())
                    return SPELL_FAILED_CHARMED;
                break;
            }
            case SPELL_AURA_MOD_POSSESS:
            case SPELL_AURA_MOD_CHARM:
            case SPELL_AURA_AOE_CHARM:
            {
                if (m_caster->GetCharmerGUID())
                    return SPELL_FAILED_CHARMED;

                if (m_spellInfo->Effects[i].ApplyAuraName == SPELL_AURA_MOD_CHARM
                    || m_spellInfo->Effects[i].ApplyAuraName == SPELL_AURA_MOD_POSSESS)
                {
                    if (m_caster->GetPetGUID())
                        return SPELL_FAILED_ALREADY_HAVE_SUMMON;

                    if (m_caster->GetCharmGUID())
                        return SPELL_FAILED_ALREADY_HAVE_CHARM;
                }

                if (Unit* target = m_targets.GetUnitTarget())
                {
                    if (target->GetTypeId() == TYPEID_UNIT && target->ToCreature()->IsVehicle())
                        return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

                    if (target->IsMounted())
                        return SPELL_FAILED_CANT_BE_CHARMED;

                    if (target->GetCharmerGUID())
                        return SPELL_FAILED_CHARMED;

                    int32 damage = CalculateDamage(i, target);
                    if (damage && int32(target->getLevel()) > damage)
                        return SPELL_FAILED_HIGHLEVEL;
                }

                break;
            }
            case SPELL_AURA_MOUNTED:
            {
                if (m_caster->IsInWater())
                    return SPELL_FAILED_ONLY_ABOVEWATER;

                // Ignore map check if spell have AreaId. AreaId already checked and this prevent special mount spells
                bool allowMount = !m_caster->GetMap()->IsDungeon() || m_caster->GetMap()->IsBattlegroundOrArena();
                InstanceTemplate const* it = sObjectMgr->GetInstanceTemplate(m_caster->GetMapId());
                if (it)
                    allowMount = it->AllowMount;
                if (m_caster->GetTypeId() == TYPEID_PLAYER && !allowMount && !m_spellInfo->AreaGroupId)
                    return SPELL_FAILED_NO_MOUNTS_ALLOWED;

                if (m_caster->IsInDisallowedMountForm())
                    return SPELL_FAILED_NOT_SHAPESHIFT;

                break;
            }
            case SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS:
            {
                if (!m_targets.GetUnitTarget())
                    return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

                // can be casted at non-friendly unit or own pet/charm
                if (m_caster->IsFriendlyTo(m_targets.GetUnitTarget()))
                    return SPELL_FAILED_TARGET_FRIENDLY;

                break;
            }
            case SPELL_AURA_FLY:
            case SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED:
            {
                // not allow cast fly spells if not have req. skills  (all spells is self target)
                // allow always ghost flight spells
                if (m_originalCaster && m_originalCaster->GetTypeId() == TYPEID_PLAYER && m_originalCaster->isAlive())
                {
                    if (AreaTableEntry const* pArea = GetAreaEntryByAreaID(m_originalCaster->GetAreaId()))
                        if (pArea->flags & AREA_FLAG_NO_FLY_ZONE)
                            return (_triggeredCastFlags & TRIGGERED_DONT_REPORT_CAST_ERROR) ? SPELL_FAILED_DONT_REPORT : SPELL_FAILED_NOT_HERE;
                }
                break;
            }
            case SPELL_AURA_PERIODIC_MANA_LEECH:
            {
                if (!m_targets.GetUnitTarget())
                    return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

                if (m_caster->GetTypeId() != TYPEID_PLAYER || m_CastItem)
                    break;

                if (m_targets.GetUnitTarget()->getPowerType() != POWER_MANA)
                    return SPELL_FAILED_BAD_TARGETS;

                break;
            }
            default:
                break;
        }
    }

    // check trade slot case (last, for allow catch any another cast problems)
    if (m_targets.GetTargetMask() & TARGET_FLAG_TRADE_ITEM)
    {
        if (m_CastItem)
            return SPELL_FAILED_ITEM_ENCHANT_TRADE_WINDOW;

        if (m_caster->GetTypeId() != TYPEID_PLAYER)
            return SPELL_FAILED_NOT_TRADING;

        TradeData* my_trade = m_caster->ToPlayer()->GetTradeData();

        if (!my_trade)
            return SPELL_FAILED_NOT_TRADING;

        TradeSlots slot = TradeSlots(m_targets.GetItemTargetGUID());
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
    if (m_caster->HasUnitState(UNIT_STAT_CASTING) && !(_triggeredCastFlags & TRIGGERED_IGNORE_CAST_IN_PROGRESS))              //prevent spellcast interruption by another spellcast
        return SPELL_FAILED_SPELL_IN_PROGRESS;

    // dead owner (pets still alive when owners ressed?)
    if (Unit* owner = m_caster->GetCharmerOrOwner())
        if (!owner->isAlive())
            return SPELL_FAILED_CASTER_DEAD;

    if (!target && m_targets.GetUnitTarget())
        target = m_targets.GetUnitTarget();

    for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        if (m_spellInfo->Effects[i].TargetA.GetType() == TARGET_TYPE_UNIT_TARGET
            || m_spellInfo->Effects[i].TargetA.GetType() == TARGET_TYPE_DEST_TARGET)
        {
            if (!target)
                return SPELL_FAILED_BAD_IMPLICIT_TARGETS;
            m_targets.SetUnitTarget(target);
            break;
        }
    }

    // cooldown
    if (Creature const* creatureCaster = m_caster->ToCreature())
        if (creatureCaster->HasSpellCooldown(m_spellInfo->Id))
            return SPELL_FAILED_NOT_READY;

    return CheckCast(true);
}

SpellCastResult Spell::CheckCasterAuras() const
{
    // spells totally immuned to caster auras (wsg flag drop, give marks etc)
    if (m_spellInfo->AttributesEx6 & SPELL_ATTR6_IGNORE_CASTER_AURAS)
        return SPELL_CAST_OK;

    uint8 school_immune = 0;
    uint32 mechanic_immune = 0;
    uint32 dispel_immune = 0;

    // Check if the spell grants school or mechanic immunity.
    // We use bitmasks so the loop is done only once and not on every aura check below.
    if (m_spellInfo->AttributesEx & SPELL_ATTR1_DISPEL_AURAS_ON_IMMUNITY)
    {
        for (int i = 0; i < MAX_SPELL_EFFECTS; ++i)
        {
            if (m_spellInfo->Effects[i].ApplyAuraName == SPELL_AURA_SCHOOL_IMMUNITY)
                school_immune |= uint32(m_spellInfo->Effects[i].MiscValue);
            else if (m_spellInfo->Effects[i].ApplyAuraName == SPELL_AURA_MECHANIC_IMMUNITY)
                mechanic_immune |= 1 << uint32(m_spellInfo->Effects[i].MiscValue);
            else if (m_spellInfo->Effects[i].ApplyAuraName == SPELL_AURA_DISPEL_IMMUNITY)
                dispel_immune |= SpellInfo::GetDispelMask(DispelType(m_spellInfo->Effects[i].MiscValue));
        }
        // immune movement impairment and loss of control
        if (m_spellInfo->Id == 42292 || m_spellInfo->Id == 59752)
            mechanic_immune = IMMUNE_TO_MOVEMENT_IMPAIRMENT_AND_LOSS_CONTROL_MASK;
    }

    bool usableInStun = m_spellInfo->AttributesEx5 & SPELL_ATTR5_USABLE_WHILE_STUNNED;

    // Glyph of Pain Suppression
    // there is no other way to handle it
    if (m_spellInfo->Id == 33206 && !m_caster->HasAura(63248))
        usableInStun = false;

    // Check whether the cast should be prevented by any state you might have.
    SpellCastResult prevented_reason = SPELL_CAST_OK;
    // Have to check if there is a stun aura. Otherwise will have problems with ghost aura apply while logging out
    uint32 unitflag = m_caster->GetUInt32Value(UNIT_FIELD_FLAGS);     // Get unit state
    if (unitflag & UNIT_FLAG_STUNNED)
    {
        // spell is usable while stunned, check if caster has only mechanic stun auras, another stun types must prevent cast spell
        if (usableInStun)
        {
            bool foundNotStun = false;
            Unit::AuraEffectList const& stunAuras = m_caster->GetAuraEffectsByType(SPELL_AURA_MOD_STUN);
            for (Unit::AuraEffectList::const_iterator i = stunAuras.begin(); i != stunAuras.end(); ++i)
            {
                if (!((*i)->GetSpellInfo()->GetAllEffectsMechanicMask() & (1<<MECHANIC_STUN)))
                {
                    foundNotStun = true;
                    break;
                }
            }
            if (foundNotStun)
                prevented_reason = SPELL_FAILED_STUNNED;
        }
        else
            prevented_reason = SPELL_FAILED_STUNNED;
    }
    else if (unitflag & UNIT_FLAG_CONFUSED && !(m_spellInfo->AttributesEx5 & SPELL_ATTR5_USABLE_WHILE_CONFUSED))
        prevented_reason = SPELL_FAILED_CONFUSED;
    else if (unitflag & UNIT_FLAG_FLEEING && !(m_spellInfo->AttributesEx5 & SPELL_ATTR5_USABLE_WHILE_FEARED))
        prevented_reason = SPELL_FAILED_FLEEING;
    else if (unitflag & UNIT_FLAG_SILENCED && m_spellInfo->PreventionType == SPELL_PREVENTION_TYPE_SILENCE)
        prevented_reason = SPELL_FAILED_SILENCED;
    else if (unitflag & UNIT_FLAG_PACIFIED && m_spellInfo->PreventionType == SPELL_PREVENTION_TYPE_PACIFY)
        prevented_reason = SPELL_FAILED_PACIFIED;

    // Attr must make flag drop spell totally immune from all effects
    if (prevented_reason != SPELL_CAST_OK)
    {
        if (school_immune || mechanic_immune || dispel_immune)
        {
            //Checking auras is needed now, because you are prevented by some state but the spell grants immunity.
            Unit::AuraApplicationMap const& auras = m_caster->GetAppliedAuras();
            for (Unit::AuraApplicationMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
            {
                Aura const* aura = itr->second->GetBase();
                SpellInfo const* auraInfo = aura->GetSpellInfo();
                if (auraInfo->GetAllEffectsMechanicMask() & mechanic_immune)
                    continue;
                if (auraInfo->GetSchoolMask() & school_immune)
                    continue;
                if (auraInfo->GetDispelMask() & dispel_immune)
                    continue;

                //Make a second check for spell failed so the right SPELL_FAILED message is returned.
                //That is needed when your casting is prevented by multiple states and you are only immune to some of them.
                for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                {
                    if (AuraEffect* part = aura->GetEffect(i))
                    {
                        switch (part->GetAuraType())
                        {
                            case SPELL_AURA_MOD_STUN:
                                if (!usableInStun || !(auraInfo->GetAllEffectsMechanicMask() & (1<<MECHANIC_STUN)))
                                    return SPELL_FAILED_STUNNED;
                                break;
                            case SPELL_AURA_MOD_CONFUSE:
                                if (!(m_spellInfo->AttributesEx5 & SPELL_ATTR5_USABLE_WHILE_CONFUSED))
                                    return SPELL_FAILED_CONFUSED;
                                break;
                            case SPELL_AURA_MOD_FEAR:
                                if (!(m_spellInfo->AttributesEx5 & SPELL_ATTR5_USABLE_WHILE_FEARED))
                                    return SPELL_FAILED_FLEEING;
                                break;
                            case SPELL_AURA_MOD_SILENCE:
                            case SPELL_AURA_MOD_PACIFY:
                            case SPELL_AURA_MOD_PACIFY_SILENCE:
                                if (m_spellInfo->PreventionType == SPELL_PREVENTION_TYPE_PACIFY)
                                    return SPELL_FAILED_PACIFIED;
                                else if (m_spellInfo->PreventionType == SPELL_PREVENTION_TYPE_SILENCE)
                                    return SPELL_FAILED_SILENCED;
                                break;
                            default: break;
                        }
                    }
                }
            }
        }
        // You are prevented from casting and the spell casted does not grant immunity. Return a failed error.
        else
            return prevented_reason;
    }
    return SPELL_CAST_OK;
}

bool Spell::CanAutoCast(Unit* target)
{
    uint64 targetguid = target->GetGUID();

    for (uint32 j = 0; j < MAX_SPELL_EFFECTS; ++j)
    {
        if (m_spellInfo->Effects[j].Effect == SPELL_EFFECT_APPLY_AURA)
        {
            if (m_spellInfo->StackAmount <= 1)
            {
                if (target->HasAuraEffect(m_spellInfo->Id, j))
                    return false;
            }
            else
            {
                if (AuraEffect* aureff = target->GetAuraEffect(m_spellInfo->Id, j))
                    if (aureff->GetBase()->GetStackAmount() >= m_spellInfo->StackAmount)
                        return false;
            }
        }
        else if (m_spellInfo->Effects[j].IsAreaAuraEffect())
        {
            if (target->HasAuraEffect(m_spellInfo->Id, j))
                return false;
        }
    }

    SpellCastResult result = CheckPetCast(target);

    if (result == SPELL_CAST_OK || result == SPELL_FAILED_UNIT_NOT_INFRONT)
    {
        SelectSpellTargets();
        //check if among target units, our WANTED target is as well (->only self cast spells return false)
        for (std::list<TargetInfo>::iterator ihit= m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
            if (ihit->targetGUID == targetguid)
                return true;
    }
    return false;                                           //target invalid
}

SpellCastResult Spell::CheckRange(bool strict)
{
    // Don't check for instant cast spells
    if (!strict && m_casttime == 0)
        return SPELL_CAST_OK;

    uint32 range_type = m_spellInfo->RangeEntry ? m_spellInfo->RangeEntry->type : 0;

    Unit* target = m_targets.GetUnitTarget();
    float max_range = m_caster->GetSpellMaxRangeForTarget(target, m_spellInfo);
    float min_range = m_caster->GetSpellMinRangeForTarget(target, m_spellInfo);

    if (Player* modOwner = m_caster->GetSpellModOwner())
        modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RANGE, max_range, this);

    if (target && target != m_caster)
    {
        if (range_type == SPELL_RANGE_MELEE)
        {
            // Because of lag, we can not check too strictly here.
            if (!m_caster->IsWithinMeleeRange(target, max_range))
                return !(_triggeredCastFlags & TRIGGERED_DONT_REPORT_CAST_ERROR) ? SPELL_FAILED_OUT_OF_RANGE : SPELL_FAILED_DONT_REPORT;
        }
        else if (!m_caster->IsWithinCombatRange(target, max_range))
            return !(_triggeredCastFlags & TRIGGERED_DONT_REPORT_CAST_ERROR) ? SPELL_FAILED_OUT_OF_RANGE : SPELL_FAILED_DONT_REPORT; //0x5A;

        if (range_type == SPELL_RANGE_RANGED)
        {
            if (m_caster->IsWithinMeleeRange(target))
                return !(_triggeredCastFlags & TRIGGERED_DONT_REPORT_CAST_ERROR) ? SPELL_FAILED_TOO_CLOSE : SPELL_FAILED_DONT_REPORT;
        }
        else if (min_range && m_caster->IsWithinCombatRange(target, min_range)) // skip this check if min_range = 0
            return !(_triggeredCastFlags & TRIGGERED_DONT_REPORT_CAST_ERROR) ? SPELL_FAILED_TOO_CLOSE : SPELL_FAILED_DONT_REPORT;

        if (m_caster->GetTypeId() == TYPEID_PLAYER &&
            (m_spellInfo->FacingCasterFlags & SPELL_FACING_FLAG_INFRONT) && !m_caster->HasInArc(static_cast<float>(M_PI), target))
            return !(_triggeredCastFlags & TRIGGERED_DONT_REPORT_CAST_ERROR) ? SPELL_FAILED_UNIT_NOT_INFRONT : SPELL_FAILED_DONT_REPORT;
    }

    if (m_targets.HasDst() && !m_targets.HasTraj())
    {
        if (!m_caster->IsWithinDist3d(m_targets.GetDst(), max_range))
            return SPELL_FAILED_OUT_OF_RANGE;
        if (min_range && m_caster->IsWithinDist3d(m_targets.GetDst(), min_range))
            return SPELL_FAILED_TOO_CLOSE;
    }

    return SPELL_CAST_OK;
}

SpellCastResult Spell::CheckPower()
{
    // item cast not used power
    if (m_CastItem)
        return SPELL_CAST_OK;

    // health as power used - need check health amount
    if (m_spellInfo->PowerType == POWER_HEALTH)
    {
        if (int32(m_caster->GetHealth()) <= m_powerCost)
            return SPELL_FAILED_CASTER_AURASTATE;
        return SPELL_CAST_OK;
    }
    // Check valid power type
    if (m_spellInfo->PowerType >= MAX_POWERS)
    {
        sLog->outError("Spell::CheckPower: Unknown power type '%d'", m_spellInfo->PowerType);
        return SPELL_FAILED_UNKNOWN;
    }

    //check rune cost only if a spell has PowerType == POWER_RUNE
    if (m_spellInfo->PowerType == POWER_RUNE)
    {
        SpellCastResult failReason = CheckRuneCost(m_spellInfo->RuneCostID);
        if (failReason != SPELL_CAST_OK)
            return failReason;
    }

    // Check power amount
    Powers powerType = Powers(m_spellInfo->PowerType);
    if (int32(m_caster->GetPower(powerType)) < m_powerCost)
        return SPELL_FAILED_NO_POWER;
    else
        return SPELL_CAST_OK;
}

SpellCastResult Spell::CheckItems()
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return SPELL_CAST_OK;

    Player* p_caster = (Player*)m_caster;

    if (!m_CastItem)
    {
        if (m_castItemGUID)
            return SPELL_FAILED_ITEM_NOT_READY;
    }
    else
    {
        uint32 itemid = m_CastItem->GetEntry();
        if (!p_caster->HasItemCount(itemid, 1))
            return SPELL_FAILED_ITEM_NOT_READY;

        ItemTemplate const* proto = m_CastItem->GetTemplate();
        if (!proto)
            return SPELL_FAILED_ITEM_NOT_READY;

        for (int i = 0; i < MAX_ITEM_SPELLS; ++i)
            if (proto->Spells[i].SpellCharges)
                if (m_CastItem->GetSpellCharges(i) == 0)
                    return SPELL_FAILED_NO_CHARGES_REMAIN;

        // consumable cast item checks
        if (proto->Class == ITEM_CLASS_CONSUMABLE && m_targets.GetUnitTarget())
        {
            // such items should only fail if there is no suitable effect at all - see Rejuvenation Potions for example
            SpellCastResult failReason = SPELL_CAST_OK;
            for (int i = 0; i < MAX_SPELL_EFFECTS; i++)
            {
                    // skip check, pet not required like checks, and for TARGET_UNIT_PET m_targets.GetUnitTarget() is not the real target but the caster
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

    // check target item
    if (m_targets.GetItemTargetGUID())
    {
        if (m_caster->GetTypeId() != TYPEID_PLAYER)
            return SPELL_FAILED_BAD_TARGETS;

        if (!m_targets.GetItemTarget())
            return SPELL_FAILED_ITEM_GONE;

        if (!m_targets.GetItemTarget()->IsFitToSpellRequirements(m_spellInfo))
            return SPELL_FAILED_EQUIPPED_ITEM_CLASS;
    }
    // if not item target then required item must be equipped
    else
    {
        if (m_caster->GetTypeId() == TYPEID_PLAYER && !m_caster->ToPlayer()->HasItemFitToSpellRequirements(m_spellInfo))
            return SPELL_FAILED_EQUIPPED_ITEM_CLASS;
    }

    // check spell focus object
    if (m_spellInfo->RequiresSpellFocus)
    {
        CellPair p(Trinity::ComputeCellPair(m_caster->GetPositionX(), m_caster->GetPositionY()));
        Cell cell(p);
        cell.data.Part.reserved = ALL_DISTRICT;

        GameObject* ok = NULL;
        Trinity::GameObjectFocusCheck go_check(m_caster, m_spellInfo->RequiresSpellFocus);
        Trinity::GameObjectSearcher<Trinity::GameObjectFocusCheck> checker(m_caster, ok, go_check);

        TypeContainerVisitor<Trinity::GameObjectSearcher<Trinity::GameObjectFocusCheck>, GridTypeMapContainer > object_checker(checker);
        Map& map = *m_caster->GetMap();
        cell.Visit(p, object_checker, map, *m_caster, m_caster->GetVisibilityRange());

        if (!ok)
            return SPELL_FAILED_REQUIRES_SPELL_FOCUS;

        focusObject = ok;                                   // game object found in range
    }

    // do not take reagents for these item casts
    if (!(m_CastItem && m_CastItem->GetTemplate()->Flags & ITEM_PROTO_FLAG_TRIGGERED_CAST))
    {
        bool checkReagents = !(_triggeredCastFlags & TRIGGERED_IGNORE_POWER_AND_REAGENT_COST) && !p_caster->CanNoReagentCast(m_spellInfo);
        // Not own traded item (in trader trade slot) requires reagents even if triggered spell
        if (!checkReagents)
            if (Item* targetItem = m_targets.GetItemTarget())
                if (targetItem->GetOwnerGUID() != m_caster->GetGUID())
                    checkReagents = true;

        // check reagents (ignore triggered spells with reagents processed by original spell) and special reagent ignore case.
        if (checkReagents)
        {
            for (uint32 i = 0; i < MAX_SPELL_REAGENTS; i++)
            {
                if (m_spellInfo->Reagent[i] <= 0)
                    continue;

                uint32 itemid    = m_spellInfo->Reagent[i];
                uint32 itemcount = m_spellInfo->ReagentCount[i];

                // if CastItem is also spell reagent
                if (m_CastItem && m_CastItem->GetEntry() == itemid)
                {
                    ItemTemplate const* proto = m_CastItem->GetTemplate();
                    if (!proto)
                        return SPELL_FAILED_ITEM_NOT_READY;
                    for (int s=0; s < MAX_ITEM_PROTO_SPELLS; ++s)
                    {
                        // CastItem will be used up and does not count as reagent
                        int32 charges = m_CastItem->GetSpellCharges(s);
                        if (proto->Spells[s].SpellCharges < 0 && abs(charges) < 2)
                        {
                            ++itemcount;
                            break;
                        }
                    }
                }
                if (!p_caster->HasItemCount(itemid, itemcount))
                    return SPELL_FAILED_ITEM_NOT_READY;         //0x54
            }
        }

        // check totem-item requirements (items presence in inventory)
        uint32 totems = 2;
        for (int i = 0; i < 2 ; ++i)
        {
            if (m_spellInfo->Totem[i] != 0)
            {
                if (p_caster->HasItemCount(m_spellInfo->Totem[i], 1))
                {
                    totems -= 1;
                    continue;
                }
            }else
            totems -= 1;
        }
        if (totems != 0)
            return SPELL_FAILED_TOTEMS;                         //0x7C

        // Check items for TotemCategory  (items presence in inventory)
        uint32 TotemCategory = 2;
        for (int i= 0; i < 2; ++i)
        {
            if (m_spellInfo->TotemCategory[i] != 0)
            {
                if (p_caster->HasItemTotemCategory(m_spellInfo->TotemCategory[i]))
                {
                    TotemCategory -= 1;
                    continue;
                }
            }
            else
                TotemCategory -= 1;
        }
        if (TotemCategory != 0)
            return SPELL_FAILED_TOTEM_CATEGORY;                 //0x7B
    }

    // special checks for spell effects
    for (int i = 0; i < MAX_SPELL_EFFECTS; i++)
    {
        switch (m_spellInfo->Effects[i].Effect)
        {
            case SPELL_EFFECT_CREATE_ITEM:
            case SPELL_EFFECT_CREATE_ITEM_2:
            {
                if (!IsTriggered() && m_spellInfo->Effects[i].ItemType)
                {
                    ItemPosCountVec dest;
                    InventoryResult msg = p_caster->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, m_spellInfo->Effects[i].ItemType, 1);
                    if (msg != EQUIP_ERR_OK)
                    {
                        ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(m_spellInfo->Effects[i].ItemType);
                        // TODO: Needs review
                        if (pProto && !(pProto->ItemLimitCategory))
                        {
                            p_caster->SendEquipError(msg, NULL, NULL, m_spellInfo->Effects[i].ItemType);
                            return SPELL_FAILED_DONT_REPORT;
                        }
                        else
                        {
                            if (!(m_spellInfo->SpellFamilyName == SPELLFAMILY_MAGE && (m_spellInfo->SpellFamilyFlags[0] & 0x40000000)))
                                return SPELL_FAILED_TOO_MANY_OF_ITEM;
                            else if (!(p_caster->HasItemCount(m_spellInfo->Effects[i].ItemType, 1)))
                                return SPELL_FAILED_TOO_MANY_OF_ITEM;
                            else
                                p_caster->CastSpell(m_caster, m_spellInfo->Effects[EFFECT_1].CalcValue(), false);        // move this to anywhere
                            return SPELL_FAILED_DONT_REPORT;
                        }
                    }
                }
                break;
            }
            case SPELL_EFFECT_ENCHANT_ITEM:
                if (m_spellInfo->Effects[i].ItemType && m_targets.GetItemTarget()
                    && (m_targets.GetItemTarget()->IsWeaponVellum() || m_targets.GetItemTarget()->IsArmorVellum()))
                {
                    // cannot enchant vellum for other player
                    if (m_targets.GetItemTarget()->GetOwner() != m_caster)
                        return SPELL_FAILED_NOT_TRADEABLE;
                    // do not allow to enchant vellum from scroll made by vellum-prevent exploit
                    if (m_CastItem && m_CastItem->GetTemplate()->Flags & ITEM_PROTO_FLAG_TRIGGERED_CAST)
                        return SPELL_FAILED_TOTEM_CATEGORY;
                    ItemPosCountVec dest;
                    InventoryResult msg = p_caster->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, m_spellInfo->Effects[i].ItemType, 1);
                    if (msg != EQUIP_ERR_OK)
                    {
                        p_caster->SendEquipError(msg, NULL, NULL, m_spellInfo->Effects[i].ItemType);
                        return SPELL_FAILED_DONT_REPORT;
                    }
                }
            case SPELL_EFFECT_ENCHANT_ITEM_PRISMATIC:
            {
                Item* targetItem = m_targets.GetItemTarget();
                if (!targetItem)
                    return SPELL_FAILED_ITEM_NOT_FOUND;

                if (targetItem->GetTemplate()->ItemLevel < m_spellInfo->BaseLevel)
                    return SPELL_FAILED_LOWLEVEL;

                bool isItemUsable = false;
                for (uint8 e = 0; e < MAX_ITEM_PROTO_SPELLS; ++e)
                {
                    ItemTemplate const* proto = targetItem->GetTemplate();
                    if (proto->Spells[e].SpellId && (
                        proto->Spells[e].SpellTrigger == ITEM_SPELLTRIGGER_ON_USE ||
                        proto->Spells[e].SpellTrigger == ITEM_SPELLTRIGGER_ON_NO_DELAY_USE))
                    {
                        isItemUsable = true;
                        break;
                    }
                }

                SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(m_spellInfo->Effects[i].MiscValue);
                // do not allow adding usable enchantments to items that have use effect already
                if (pEnchant && isItemUsable)
                    for (uint8 s = 0; s < MAX_ITEM_ENCHANTMENT_EFFECTS; ++s)
                        if (pEnchant->type[s] == ITEM_ENCHANTMENT_TYPE_USE_SPELL)
                            return SPELL_FAILED_ON_USE_ENCHANT;

                // Not allow enchant in trade slot for some enchant type
                if (targetItem->GetOwner() != m_caster)
                {
                    if (!pEnchant)
                        return SPELL_FAILED_ERROR;
                    if (pEnchant->slot & ENCHANTMENT_CAN_SOULBOUND)
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
                if (item->GetOwner() != m_caster)
                {
                    uint32 enchant_id = m_spellInfo->Effects[i].MiscValue;
                    SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
                    if (!pEnchant)
                        return SPELL_FAILED_ERROR;
                    if (pEnchant->slot & ENCHANTMENT_CAN_SOULBOUND)
                        return SPELL_FAILED_NOT_TRADEABLE;
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
                if (m_targets.GetItemTarget()->GetOwnerGUID() != m_caster->GetGUID())
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;

                ItemTemplate const* itemProto = m_targets.GetItemTarget()->GetTemplate();
                if (!itemProto)
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;

                uint32 item_quality = itemProto->Quality;
                // 2.0.x addon: Check player enchanting level against the item disenchanting requirements
                uint32 item_disenchantskilllevel = itemProto->RequiredDisenchantSkill;
                if (item_disenchantskilllevel == uint32(-1))
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;
                if (item_disenchantskilllevel > p_caster->GetSkillValue(SKILL_ENCHANTING))
                    return SPELL_FAILED_LOW_CASTLEVEL;
                if (item_quality > 4 || item_quality < 2)
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;
                if (itemProto->Class != ITEM_CLASS_WEAPON && itemProto->Class != ITEM_CLASS_ARMOR)
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;
                if (!itemProto->DisenchantID)
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;
                break;
            }
            case SPELL_EFFECT_PROSPECTING:
            {
                if (!m_targets.GetItemTarget())
                    return SPELL_FAILED_CANT_BE_PROSPECTED;
                //ensure item is a prospectable ore
                if (!(m_targets.GetItemTarget()->GetTemplate()->Flags & ITEM_PROTO_FLAG_PROSPECTABLE))
                    return SPELL_FAILED_CANT_BE_PROSPECTED;
                //prevent prospecting in trade slot
                if (m_targets.GetItemTarget()->GetOwnerGUID() != m_caster->GetGUID())
                    return SPELL_FAILED_CANT_BE_PROSPECTED;
                //Check for enough skill in jewelcrafting
                uint32 item_prospectingskilllevel = m_targets.GetItemTarget()->GetTemplate()->RequiredSkillRank;
                if (item_prospectingskilllevel >p_caster->GetSkillValue(SKILL_JEWELCRAFTING))
                    return SPELL_FAILED_LOW_CASTLEVEL;
                //make sure the player has the required ores in inventory
                if (m_targets.GetItemTarget()->GetCount() < 5)
                    return SPELL_FAILED_NEED_MORE_ITEMS;

                if (!LootTemplates_Prospecting.HaveLootFor(m_targets.GetItemTargetEntry()))
                    return SPELL_FAILED_CANT_BE_PROSPECTED;

                break;
            }
            case SPELL_EFFECT_MILLING:
            {
                if (!m_targets.GetItemTarget())
                    return SPELL_FAILED_CANT_BE_MILLED;
                //ensure item is a millable herb
                if (!(m_targets.GetItemTarget()->GetTemplate()->Flags & ITEM_PROTO_FLAG_MILLABLE))
                    return SPELL_FAILED_CANT_BE_MILLED;
                //prevent milling in trade slot
                if (m_targets.GetItemTarget()->GetOwnerGUID() != m_caster->GetGUID())
                    return SPELL_FAILED_CANT_BE_MILLED;
                //Check for enough skill in inscription
                uint32 item_millingskilllevel = m_targets.GetItemTarget()->GetTemplate()->RequiredSkillRank;
                if (item_millingskilllevel >p_caster->GetSkillValue(SKILL_INSCRIPTION))
                    return SPELL_FAILED_LOW_CASTLEVEL;
                //make sure the player has the required herbs in inventory
                if (m_targets.GetItemTarget()->GetCount() < 5)
                    return SPELL_FAILED_NEED_MORE_ITEMS;

                if (!LootTemplates_Milling.HaveLootFor(m_targets.GetItemTargetEntry()))
                    return SPELL_FAILED_CANT_BE_MILLED;

                break;
            }
            case SPELL_EFFECT_WEAPON_DAMAGE:
            case SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER) return SPELL_FAILED_TARGET_NOT_PLAYER;
                if (m_attackType != RANGED_ATTACK)
                    break;
                Item* pItem = m_caster->ToPlayer()->GetWeaponForAttack(m_attackType);
                if (!pItem || pItem->IsBroken())
                    return SPELL_FAILED_EQUIPPED_ITEM;

                switch (pItem->GetTemplate()->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_THROWN:
                    {
                        uint32 ammo = pItem->GetEntry();
                        if (!m_caster->ToPlayer()->HasItemCount(ammo, 1))
                            return SPELL_FAILED_NO_AMMO;
                    };  break;
                    case ITEM_SUBCLASS_WEAPON_GUN:
                    case ITEM_SUBCLASS_WEAPON_BOW:
                    case ITEM_SUBCLASS_WEAPON_CROSSBOW:
                    {
                        uint32 ammo = m_caster->ToPlayer()->GetUInt32Value(PLAYER_AMMO_ID);
                        if (!ammo)
                        {
                            // Requires No Ammo
                            if (m_caster->HasAura(46699))
                                break;                      // skip other checks

                            return SPELL_FAILED_NO_AMMO;
                        }

                        ItemTemplate const* ammoProto = sObjectMgr->GetItemTemplate(ammo);
                        if (!ammoProto)
                            return SPELL_FAILED_NO_AMMO;

                        if (ammoProto->Class != ITEM_CLASS_PROJECTILE)
                            return SPELL_FAILED_NO_AMMO;

                        // check ammo ws. weapon compatibility
                        switch (pItem->GetTemplate()->SubClass)
                        {
                            case ITEM_SUBCLASS_WEAPON_BOW:
                            case ITEM_SUBCLASS_WEAPON_CROSSBOW:
                                if (ammoProto->SubClass != ITEM_SUBCLASS_ARROW)
                                    return SPELL_FAILED_NO_AMMO;
                                break;
                            case ITEM_SUBCLASS_WEAPON_GUN:
                                if (ammoProto->SubClass != ITEM_SUBCLASS_BULLET)
                                    return SPELL_FAILED_NO_AMMO;
                                break;
                            default:
                                return SPELL_FAILED_NO_AMMO;
                        }

                        if (!m_caster->ToPlayer()->HasItemCount(ammo, 1))
                        {
                            m_caster->ToPlayer()->SetUInt32Value(PLAYER_AMMO_ID, 0);
                            return SPELL_FAILED_NO_AMMO;
                        }
                    };  break;
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

                 if (Item* pitem = p_caster->GetItemByEntry(item_id))
                 {
                     for (int x = 0; x < MAX_ITEM_PROTO_SPELLS; ++x)
                         if (pProto->Spells[x].SpellCharges != 0 && pitem->GetSpellCharges(x) == pProto->Spells[x].SpellCharges)
                             return SPELL_FAILED_ITEM_AT_MAX_CHARGES;
                 }
                 break;
            }
            default:
                break;
        }
    }

    // check weapon presence in slots for main/offhand weapons
    if (m_spellInfo->EquippedItemClass >=0)
    {
        // main hand weapon required
        if (m_spellInfo->AttributesEx3 & SPELL_ATTR3_MAIN_HAND)
        {
            Item* item = m_caster->ToPlayer()->GetWeaponForAttack(BASE_ATTACK);

            // skip spell if no weapon in slot or broken
            if (!item || item->IsBroken())
                return (_triggeredCastFlags & TRIGGERED_DONT_REPORT_CAST_ERROR) ? SPELL_FAILED_DONT_REPORT : SPELL_FAILED_EQUIPPED_ITEM_CLASS;

            // skip spell if weapon not fit to triggered spell
            if (!item->IsFitToSpellRequirements(m_spellInfo))
                return (_triggeredCastFlags & TRIGGERED_DONT_REPORT_CAST_ERROR) ? SPELL_FAILED_DONT_REPORT : SPELL_FAILED_EQUIPPED_ITEM_CLASS;
        }

        // offhand hand weapon required
        if (m_spellInfo->AttributesEx3 & SPELL_ATTR3_REQ_OFFHAND)
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
    if (!m_caster)// || m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    //if (m_spellState == SPELL_STATE_DELAYED)
    //    return;                                             // spell is active and can't be time-backed

    if (isDelayableNoMore())                                 // Spells may only be delayed twice
        return;

    // spells not loosing casting time (slam, dynamites, bombs..)
    //if (!(m_spellInfo->InterruptFlags & SPELL_INTERRUPT_FLAG_DAMAGE))
    //    return;

    //check pushback reduce
    int32 delaytime = 500;                                  // spellcasting delay is normally 500ms
    int32 delayReduce = 100;                                // must be initialized to 100 for percent modifiers
    m_caster->ToPlayer()->ApplySpellMod(m_spellInfo->Id, SPELLMOD_NOT_LOSE_CASTING_TIME, delayReduce, this);
    delayReduce += m_caster->GetTotalAuraModifier(SPELL_AURA_REDUCE_PUSHBACK) - 100;
    if (delayReduce >= 100)
        return;

    AddPctN(delaytime, -delayReduce);

    if (int32(m_timer) + delaytime > m_casttime)
    {
        delaytime = m_casttime - m_timer;
        m_timer = m_casttime;
    }
    else
        m_timer += delaytime;

    sLog->outDetail("Spell %u partially interrupted for (%d) ms at damage", m_spellInfo->Id, delaytime);

    WorldPacket data(SMSG_SPELL_DELAYED, 8+4);
    data.append(m_caster->GetPackGUID());
    data << uint32(delaytime);

    m_caster->SendMessageToSet(&data, true);
}

void Spell::DelayedChannel()
{
    if (!m_caster || m_caster->GetTypeId() != TYPEID_PLAYER || getState() != SPELL_STATE_CASTING)
        return;

    if (isDelayableNoMore())                                    // Spells may only be delayed twice
        return;

    //check pushback reduce
    int32 delaytime = CalculatePctN(m_spellInfo->GetDuration(), 25); // channeling delay is normally 25% of its time per hit
    int32 delayReduce = 100;                                    // must be initialized to 100 for percent modifiers
    m_caster->ToPlayer()->ApplySpellMod(m_spellInfo->Id, SPELLMOD_NOT_LOSE_CASTING_TIME, delayReduce, this);
    delayReduce += m_caster->GetTotalAuraModifier(SPELL_AURA_REDUCE_PUSHBACK) - 100;
    if (delayReduce >= 100)
        return;

    AddPctN(delaytime, -delayReduce);

    if (int32(m_timer) <= delaytime)
    {
        delaytime = m_timer;
        m_timer = 0;
    }
    else
        m_timer -= delaytime;

    sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "Spell %u partially interrupted for %i ms, new duration: %u ms", m_spellInfo->Id, delaytime, m_timer);

    for (std::list<TargetInfo>::const_iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
        if ((*ihit).missCondition == SPELL_MISS_NONE)
            if (Unit* unit = (m_caster->GetGUID() == ihit->targetGUID) ? m_caster : ObjectAccessor::GetUnit(*m_caster, ihit->targetGUID))
                unit->DelayOwnedAuras(m_spellInfo->Id, m_originalCasterGUID, delaytime);

    // partially interrupt persistent area auras
    if (DynamicObject* dynObj = m_caster->GetDynObject(m_spellInfo->Id))
        dynObj->Delay(delaytime);

    SendChannelUpdate(m_timer);
}

void Spell::UpdatePointers()
{
    if (m_originalCasterGUID == m_caster->GetGUID())
        m_originalCaster = m_caster;
    else
    {
        m_originalCaster = ObjectAccessor::GetUnit(*m_caster, m_originalCasterGUID);
        if (m_originalCaster && !m_originalCaster->IsInWorld())
            m_originalCaster = NULL;
    }

    if (m_castItemGUID && m_caster->GetTypeId() == TYPEID_PLAYER)
        m_CastItem = m_caster->ToPlayer()->GetItemByGuid(m_castItemGUID);

    m_targets.Update(m_caster);
}

CurrentSpellTypes Spell::GetCurrentContainer() const
{
    if (IsNextMeleeSwingSpell())
        return(CURRENT_MELEE_SPELL);
    else if (IsAutoRepeat())
        return(CURRENT_AUTOREPEAT_SPELL);
    else if (m_spellInfo->IsChanneled())
        return(CURRENT_CHANNELED_SPELL);
    else
        return(CURRENT_GENERIC_SPELL);
}

bool Spell::CheckEffectTarget(Unit const* target, uint32 eff) const
{
    switch (m_spellInfo->Effects[eff].ApplyAuraName)
    {
        case SPELL_AURA_MOD_POSSESS:
        case SPELL_AURA_MOD_CHARM:
        case SPELL_AURA_MOD_POSSESS_PET:
        case SPELL_AURA_AOE_CHARM:
            if (target->GetTypeId() == TYPEID_UNIT && target->IsVehicle())
                return false;
            if (target->IsMounted())
                return false;
            if (target->GetCharmerGUID())
                return false;
            if (int32 damage = CalculateDamage(eff, target))
                if ((int32)target->getLevel() > damage)
                    return false;
            break;
        default:
            break;
    }

    if (IsTriggered() || m_spellInfo->AttributesEx2 & SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS)
        return true;

    // todo: shit below shouldn't be here, but it's temporary
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
        default:                                            // normal case
            // Get GO cast coordinates if original caster -> GO
            WorldObject* caster = NULL;
            if (IS_GAMEOBJECT_GUID(m_originalCasterGUID))
                caster = m_caster->GetMap()->GetGameObject(m_originalCasterGUID);
            if (!caster)
                caster = m_caster;
            if (target != m_caster && !target->IsWithinLOSInMap(caster))
                return false;
            break;
    }

    return true;
}

bool Spell::IsNextMeleeSwingSpell() const
{
    return m_spellInfo->Attributes & SPELL_ATTR0_ON_NEXT_SWING;
}

bool Spell::IsAutoActionResetSpell() const
{
    return !IsTriggered() && (m_spellInfo->InterruptFlags & SPELL_INTERRUPT_FLAG_AUTOATTACK);
}

bool Spell::IsNeedSendToClient() const
{
    return m_spellInfo->SpellVisual[0] || m_spellInfo->SpellVisual[1] || m_spellInfo->IsChanneled() ||
        m_spellInfo->Speed > 0.0f || (!m_triggeredByAuraSpell && !IsTriggered());
}

bool Spell::HaveTargetsForEffect(uint8 effect) const
{
    for (std::list<TargetInfo>::const_iterator itr = m_UniqueTargetInfo.begin(); itr != m_UniqueTargetInfo.end(); ++itr)
        if (itr->effectMask & (1 << effect))
            return true;

    for (std::list<GOTargetInfo>::const_iterator itr = m_UniqueGOTargetInfo.begin(); itr != m_UniqueGOTargetInfo.end(); ++itr)
        if (itr->effectMask & (1 << effect))
            return true;

    for (std::list<ItemTargetInfo>::const_iterator itr = m_UniqueItemInfo.begin(); itr != m_UniqueItemInfo.end(); ++itr)
        if (itr->effectMask & (1 << effect))
            return true;

    return false;
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
        sLog->outError("~SpellEvent: %s %u tried to delete non-deletable spell %u. Was not deleted, causes memory leak.",
            (m_Spell->GetCaster()->GetTypeId() == TYPEID_PLAYER ? "Player" : "Creature"), m_Spell->GetCaster()->GetGUIDLow(), m_Spell->m_spellInfo->Id);
        ASSERT(false);
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
        } break;

        case SPELL_STATE_DELAYED:
        {
            // first, check, if we have just started
            if (m_Spell->GetDelayStart() != 0)
            {
                // no, we aren't, do the typical update
                // check, if we have channeled spell on our hands
                /*
                if (IsChanneledSpell(m_Spell->m_spellInfo))
                {
                    // evented channeled spell is processed separately, casted once after delay, and not destroyed till finish
                    // check, if we have casting anything else except this channeled spell and autorepeat
                    if (m_Spell->GetCaster()->IsNonMeleeSpellCasted(false, true, true))
                    {
                        // another non-melee non-delayed spell is casted now, abort
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
        } break;

        default:
        {
            // all other states
            // event will be re-added automatically at the end of routine)
        } break;
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
    if (target->isAlive())
        return !m_spellInfo->IsRequiringDeadTarget();
    if (m_spellInfo->IsAllowingDeadTarget())
        return true;
    return false;
}

void Spell::CalculateDamageDoneForAllTargets()
{
    float multiplier[MAX_SPELL_EFFECTS];
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        if (m_applyMultiplierMask & (1 << i))
            multiplier[i] = m_spellInfo->Effects[i].CalcDamageMultiplier(m_originalCaster, this);

    bool usesAmmo = true;
    Unit::AuraEffectList const& Auras = m_caster->GetAuraEffectsByType(SPELL_AURA_ABILITY_CONSUME_NO_AMMO);
    for (Unit::AuraEffectList::const_iterator j = Auras.begin(); j != Auras.end(); ++j)
    {
        if ((*j)->IsAffectedOnSpell(m_spellInfo))
            usesAmmo=false;
    }

    for (std::list<TargetInfo>::iterator ihit= m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
    {
        TargetInfo &target = *ihit;

        uint32 mask = target.effectMask;
        if (!mask)
            continue;

        Unit* unit = m_caster->GetGUID() == target.targetGUID ? m_caster : ObjectAccessor::GetUnit(*m_caster, target.targetGUID);
        if (!unit) // || !unit->isAlive()) do we need to check alive here?
            continue;

        // do not consume ammo anymore for Hunter's volley spell
        if (IsTriggered() && m_spellInfo->SpellFamilyName == SPELLFAMILY_HUNTER && m_spellInfo->IsAOE())
            usesAmmo = false;

        if (usesAmmo)
        {
            bool ammoTaken = false;
            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; i++)
            {
                if (!(mask & 1<<i))
                    continue;
                switch (m_spellInfo->Effects[i].Effect)
                {
                    case SPELL_EFFECT_SCHOOL_DAMAGE:
                    case SPELL_EFFECT_WEAPON_DAMAGE:
                    case SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL:
                    case SPELL_EFFECT_NORMALIZED_WEAPON_DMG:
                    case SPELL_EFFECT_WEAPON_PERCENT_DAMAGE:
                    ammoTaken=true;
                    TakeAmmo();
                }
                if (ammoTaken)
                    break;
            }
        }

        if (target.missCondition == SPELL_MISS_NONE)                          // In case spell hit target, do all effect on that target
        {
            target.damage += CalculateDamageDone(unit, mask, multiplier);
            target.crit = m_caster->isSpellCrit(unit, m_spellInfo, m_spellSchoolMask, m_attackType);
        }
        else if (target.missCondition == SPELL_MISS_REFLECT)                // In case spell reflect from target, do all effect on caster (if hit)
        {
            if (target.reflectResult == SPELL_MISS_NONE)       // If reflected spell hit caster -> do all effect on him
            {
                target.damage += CalculateDamageDone(m_caster, mask, multiplier);
                target.crit = m_caster->isSpellCrit(m_caster, m_spellInfo, m_spellSchoolMask, m_attackType);
            }
        }
    }
}

int32 Spell::CalculateDamageDone(Unit* unit, const uint32 effectMask, float * multiplier)
{
    int32 damageDone = 0;
    unitTarget = unit;
    for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
    {
        if (effectMask & (1<<i))
        {
            m_damage = 0;
            damage = CalculateDamage(i, NULL);

            switch (m_spellInfo->Effects[i].Effect)
            {
                case SPELL_EFFECT_SCHOOL_DAMAGE:
                    SpellDamageSchoolDmg((SpellEffIndex)i);
                    break;
                case SPELL_EFFECT_WEAPON_DAMAGE:
                case SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL:
                case SPELL_EFFECT_NORMALIZED_WEAPON_DMG:
                case SPELL_EFFECT_WEAPON_PERCENT_DAMAGE:
                    SpellDamageWeaponDmg((SpellEffIndex)i);
                    break;
                case SPELL_EFFECT_HEAL:
                    SpellDamageHeal((SpellEffIndex)i);
                    break;
            }

            if (m_damage > 0)
            {
                if (m_spellInfo->Effects[i].IsArea())
                {
                    m_damage = int32(float(m_damage) * unit->GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_AOE_DAMAGE_AVOIDANCE, m_spellInfo->SchoolMask));
                    if (m_caster->GetTypeId() == TYPEID_UNIT)
                        m_damage = int32(float(m_damage) * unit->GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_CREATURE_AOE_DAMAGE_AVOIDANCE, m_spellInfo->SchoolMask));

                    if (m_caster->GetTypeId() == TYPEID_PLAYER)
                    {
                        uint32 targetAmount = m_UniqueTargetInfo.size();
                        if (targetAmount > 10)
                            m_damage = m_damage * 10/targetAmount;
                    }
                }
            }

            if (m_applyMultiplierMask & (1 << i))
            {
                m_damage = int32(m_damage * m_damageMultipliers[i]);
                m_damageMultipliers[i] *= multiplier[i];
            }

            damageDone += m_damage;
        }
    }

    return damageDone;
}

SpellCastResult Spell::CanOpenLock(uint32 effIndex, uint32 lockId, SkillType& skillId, int32& reqSkillValue, int32& skillValue)
{
    if (!lockId)                                             // possible case for GO and maybe for items.
        return SPELL_CAST_OK;

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
                    skillValue = m_CastItem || m_caster->GetTypeId()!= TYPEID_PLAYER ?
                        0 : m_caster->ToPlayer()->GetSkillValue(skillId);

                    // skill bonus provided by casting spell (mostly item spells)
                    // add the damage modifier from the spell casted (cheat lock / skeleton key etc.)
                    if (m_spellInfo->Effects[effIndex].TargetA.GetTarget() == TARGET_GAMEOBJECT_ITEM_TARGET || m_spellInfo->Effects[effIndex].TargetB.GetTarget() == TARGET_GAMEOBJECT_ITEM_TARGET)
                        skillValue += uint32(CalculateDamage(effIndex, NULL));

                    if (skillValue < reqSkillValue)
                        return SPELL_FAILED_LOW_CASTLEVEL;
                }

                return SPELL_CAST_OK;
            }
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
    }
}

float tangent(float x)
{
    x = tan(x);
    //if (x < std::numeric_limits<float>::max() && x > -std::numeric_limits<float>::max()) return x;
    //if (x >= std::numeric_limits<float>::max()) return std::numeric_limits<float>::max();
    //if (x <= -std::numeric_limits<float>::max()) return -std::numeric_limits<float>::max();
    if (x < 100000.0f && x > -100000.0f) return x;
    if (x >= 100000.0f) return 100000.0f;
    if (x <= 100000.0f) return -100000.0f;
    return 0.0f;
}

#define DEBUG_TRAJ(a) //a

void Spell::SelectTrajTargets()
{
    if (!m_targets.HasTraj())
        return;

    float dist2d = m_targets.GetDist2d();
    if (!dist2d)
        return;

    float dz = m_targets.GetDst()->m_positionZ - m_targets.GetSrc()->m_positionZ;

    UnitList unitList;
    SearchAreaTarget(unitList, dist2d, PUSH_IN_THIN_LINE, SPELL_TARGETS_ANY);
    if (unitList.empty())
        return;

    unitList.sort(Trinity::ObjectDistanceOrderPred(m_caster));

    float b = tangent(m_targets.GetElevation());
    float a = (dz - dist2d * b) / (dist2d * dist2d);
    if (a > -0.0001f) a = 0;
    DEBUG_TRAJ(sLog->outError("Spell::SelectTrajTargets: a %f b %f", a, b);)

    float bestDist = m_spellInfo->GetMaxRange(false);

    UnitList::const_iterator itr = unitList.begin();
    for (; itr != unitList.end(); ++itr)
    {
        if (m_caster == *itr || m_caster->IsOnVehicle(*itr) || (*itr)->GetVehicle())//(*itr)->IsOnVehicle(m_caster))
            continue;

        const float size = std::max((*itr)->GetObjectSize() * 0.7f, 1.0f); // 1/sqrt(3)
        // TODO: all calculation should be based on src instead of m_caster
        const float objDist2d = m_targets.GetSrc()->GetExactDist2d(*itr) * cos(m_targets.GetSrc()->GetRelativeAngle(*itr));
        const float dz = (*itr)->GetPositionZ() - m_targets.GetSrc()->m_positionZ;

        DEBUG_TRAJ(sLog->outError("Spell::SelectTrajTargets: check %u, dist between %f %f, height between %f %f.", (*itr)->GetEntry(), objDist2d - size, objDist2d + size, dz - size, dz + size);)

        float dist = objDist2d - size;
        float height = dist * (a * dist + b);
        DEBUG_TRAJ(sLog->outError("Spell::SelectTrajTargets: dist %f, height %f.", dist, height);)
        if (dist < bestDist && height < dz + size && height > dz - size)
        {
            bestDist = dist > 0 ? dist : 0;
            break;
        }

#define CHECK_DIST {\
    DEBUG_TRAJ(sLog->outError("Spell::SelectTrajTargets: dist %f, height %f.", dist, height);)\
    if (dist > bestDist) continue;\
    if (dist < objDist2d + size && dist > objDist2d - size) { bestDist = dist; break; }\
        }

        if (!a)
        {
            height = dz - size;
            dist = height / b;
            CHECK_DIST;

            height = dz + size;
            dist = height / b;
            CHECK_DIST;

            continue;
        }

        height = dz - size;
        float sqrt1 = b * b + 4 * a * height;
        if (sqrt1 > 0)
        {
            sqrt1 = sqrt(sqrt1);
            dist = (sqrt1 - b) / (2 * a);
            CHECK_DIST;
        }

        height = dz + size;
        float sqrt2 = b * b + 4 * a * height;
        if (sqrt2 > 0)
        {
            sqrt2 = sqrt(sqrt2);
            dist = (sqrt2 - b) / (2 * a);
            CHECK_DIST;

            dist = (-sqrt2 - b) / (2 * a);
            CHECK_DIST;
        }

        if (sqrt1 > 0)
        {
            dist = (-sqrt1 - b) / (2 * a);
            CHECK_DIST;
        }
    }

    if (m_targets.GetSrc()->GetExactDist2d(m_targets.GetDst()) > bestDist)
    {
        float x = m_targets.GetSrc()->m_positionX + cos(m_caster->GetOrientation()) * bestDist;
        float y = m_targets.GetSrc()->m_positionY + sin(m_caster->GetOrientation()) * bestDist;
        float z = m_targets.GetSrc()->m_positionZ + bestDist * (a * bestDist + b);

        if (itr != unitList.end())
        {
            float distSq = (*itr)->GetExactDistSq(x, y, z);
            float sizeSq = (*itr)->GetObjectSize();
            sizeSq *= sizeSq;
            DEBUG_TRAJ(sLog->outError("Initial %f %f %f %f %f", x, y, z, distSq, sizeSq);)
            if (distSq > sizeSq)
            {
                float factor = 1 - sqrt(sizeSq / distSq);
                x += factor * ((*itr)->GetPositionX() - x);
                y += factor * ((*itr)->GetPositionY() - y);
                z += factor * ((*itr)->GetPositionZ() - z);

                distSq = (*itr)->GetExactDistSq(x, y, z);
                DEBUG_TRAJ(sLog->outError("Initial %f %f %f %f %f", x, y, z, distSq, sizeSq);)
            }
        }

        Position trajDst;
        trajDst.Relocate(x, y, z, m_caster->GetOrientation());
        m_targets.ModDst(trajDst);
    }
}

void Spell::PrepareTargetProcessing()
{
    CheckEffectExecuteData();
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

void Spell::CleanupEffectExecuteData()
{
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        m_effectExecuteData[i] = NULL;
}

void Spell::CheckEffectExecuteData()
{
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        ASSERT(!m_effectExecuteData[i]);
}

void Spell::LoadScripts()
{
    sLog->outDebug(LOG_FILTER_SPELLS_AURAS, "Spell::LoadScripts");
    sScriptMgr->CreateSpellScripts(m_spellInfo->Id, m_loadedScripts);
    for (std::list<SpellScript*>::iterator itr = m_loadedScripts.begin(); itr != m_loadedScripts.end() ;)
    {
        if (!(*itr)->_Load(this))
        {
            std::list<SpellScript*>::iterator bitr = itr;
            ++itr;
            m_loadedScripts.erase(bitr);
            continue;
        }
        (*itr)->Register();
        ++itr;
    }
}

void Spell::PrepareScriptHitHandlers()
{
    for (std::list<SpellScript*>::iterator scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end() ; ++scritr)
        (*scritr)->_InitHit();
}

SpellCastResult Spell::CallScriptCheckCastHandlers()
{
    SpellCastResult retVal = SPELL_CAST_OK;
    for (std::list<SpellScript*>::iterator scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end() ; ++scritr)
    {
        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_CHECK_CAST);
        std::list<SpellScript::CheckCastHandler>::iterator hookItrEnd = (*scritr)->OnCheckCast.end(), hookItr = (*scritr)->OnCheckCast.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
        {
            SpellCastResult tempResult = (*hookItr).Call(*scritr);
            if (retVal == SPELL_CAST_OK)
                retVal = tempResult;
        }

        (*scritr)->_FinishScriptCall();
    }
    return retVal;
}

bool Spell::CallScriptEffectHandlers(SpellEffIndex effIndex)
{
    // execute script effect handler hooks and check if effects was prevented
    bool preventDefault = false;
    for (std::list<SpellScript*>::iterator scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end() ; ++scritr)
    {
        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_EFFECT);
        std::list<SpellScript::EffectHandler>::iterator effEndItr = (*scritr)->OnEffect.end(), effItr = (*scritr)->OnEffect.begin();
        for (; effItr != effEndItr ; ++effItr)
            // effect execution can be prevented
            if (!(*scritr)->_IsEffectPrevented(effIndex) && (*effItr).IsEffectAffected(m_spellInfo, effIndex))
                (*effItr).Call(*scritr, effIndex);

        if (!preventDefault)
            preventDefault = (*scritr)->_IsDefaultEffectPrevented(effIndex);

        (*scritr)->_FinishScriptCall();
    }
    return preventDefault;
}

void Spell::CallScriptBeforeHitHandlers()
{
    for (std::list<SpellScript*>::iterator scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end() ; ++scritr)
    {
        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_BEFORE_HIT);
        std::list<SpellScript::HitHandler>::iterator hookItrEnd = (*scritr)->BeforeHit.end(), hookItr = (*scritr)->BeforeHit.begin();
        for (; hookItr != hookItrEnd ; ++hookItr)
            (*hookItr).Call(*scritr);

        (*scritr)->_FinishScriptCall();
    }
}

void Spell::CallScriptOnHitHandlers()
{
    for (std::list<SpellScript*>::iterator scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end() ; ++scritr)
    {
        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_HIT);
        std::list<SpellScript::HitHandler>::iterator hookItrEnd = (*scritr)->OnHit.end(), hookItr = (*scritr)->OnHit.begin();
        for (; hookItr != hookItrEnd ; ++hookItr)
            (*hookItr).Call(*scritr);

        (*scritr)->_FinishScriptCall();
    }
}

void Spell::CallScriptAfterHitHandlers()
{
    for (std::list<SpellScript*>::iterator scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end() ; ++scritr)
    {
        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_AFTER_HIT);
        std::list<SpellScript::HitHandler>::iterator hookItrEnd = (*scritr)->AfterHit.end(), hookItr = (*scritr)->AfterHit.begin();
        for (; hookItr != hookItrEnd ; ++hookItr)
            (*hookItr).Call(*scritr);

        (*scritr)->_FinishScriptCall();
    }
}

void Spell::CallScriptAfterUnitTargetSelectHandlers(std::list<Unit*>& unitTargets, SpellEffIndex effIndex)
{
    for (std::list<SpellScript*>::iterator scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end() ; ++scritr)
    {
        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_UNIT_TARGET_SELECT);
        std::list<SpellScript::UnitTargetHandler>::iterator hookItrEnd = (*scritr)->OnUnitTargetSelect.end(), hookItr = (*scritr)->OnUnitTargetSelect.begin();
        for (; hookItr != hookItrEnd ; ++hookItr)
            if ((*hookItr).IsEffectAffected(m_spellInfo, effIndex))
                (*hookItr).Call(*scritr, unitTargets);

        (*scritr)->_FinishScriptCall();
    }
}

bool Spell::CanExecuteTriggersOnHit(uint8 effMask) const
{
    // check which effects can trigger proc
    // don't allow to proc for dummy-only spell target hits
    // prevents triggering/procing effects twice from spells like Eviscerate
    for (uint8 i = 0;effMask && i < MAX_SPELL_EFFECTS; ++i)
    {
        if (m_spellInfo->Effects[i].Effect == SPELL_EFFECT_DUMMY)
            effMask &= ~(1<<i);
    }
    return effMask;
}

void Spell::PrepareTriggersExecutedOnHit()
{
    // todo: move this to scripts
    if (m_spellInfo->SpellFamilyName)
    {
        SpellInfo const* excludeCasterSpellInfo = sSpellMgr->GetSpellInfo(m_spellInfo->ExcludeCasterAuraSpell);
        if (excludeCasterSpellInfo && !excludeCasterSpellInfo->IsPositive())
            m_preCastSpell = m_spellInfo->ExcludeCasterAuraSpell;
        SpellInfo const* excludeTargetSpellInfo = sSpellMgr->GetSpellInfo(m_spellInfo->ExcludeTargetAuraSpell);
        if (excludeTargetSpellInfo && !excludeTargetSpellInfo->IsPositive())
            m_preCastSpell = m_spellInfo->ExcludeTargetAuraSpell;
    }

    // todo: move this to scripts
    switch (m_spellInfo->SpellFamilyName)
    {
        case SPELLFAMILY_GENERIC:
        {
            if (m_spellInfo->Mechanic == MECHANIC_BANDAGE) // Bandages
                m_preCastSpell = 11196;  // Recently Bandaged
            break;
        }
        case SPELLFAMILY_MAGE:
        {
             // Permafrost
             if (m_spellInfo->SpellFamilyFlags[1] & 0x00001000 ||  m_spellInfo->SpellFamilyFlags[0] & 0x00100220)
                 m_preCastSpell = 68391;
             break;
        }
    }

    // handle SPELL_AURA_ADD_TARGET_TRIGGER auras:
    // save auras which were present on spell caster on cast, to prevent triggered auras from affecting caster
    // and to correctly calculate proc chance when combopoints are present
    Unit::AuraEffectList const& targetTriggers = m_caster->GetAuraEffectsByType(SPELL_AURA_ADD_TARGET_TRIGGER);
    for (Unit::AuraEffectList::const_iterator i = targetTriggers.begin(); i != targetTriggers.end(); ++i)
    {
        if (!(*i)->IsAffectedOnSpell(m_spellInfo))
            continue;
        SpellInfo const* auraSpellInfo = (*i)->GetSpellInfo();
        uint32 auraSpellIdx = (*i)->GetEffIndex();
        if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(auraSpellInfo->Effects[auraSpellIdx].TriggerSpell))
        {
            // calculate the chance using spell base amount, because aura amount is not updated on combo-points change
            // this possibly needs fixing
            int32 auraBaseAmount = (*i)->GetBaseAmount();
            int32 chance = m_caster->CalculateSpellDamage(NULL, auraSpellInfo, auraSpellIdx, &auraBaseAmount);
            // proc chance is stored in effect amount
            m_hitTriggerSpells.push_back(std::make_pair(spellInfo, chance * (*i)->GetBase()->GetStackAmount()));
        }
    }
}

// Global cooldowns management
enum GCDLimits
{
    MIN_GCD = 1000,
    MAX_GCD = 1500
};

bool Spell::HasGlobalCooldown() const
{
    // Only player or controlled units have global cooldown
    if (m_caster->GetCharmInfo())
        return m_caster->GetCharmInfo()->GetGlobalCooldownMgr().HasGlobalCooldown(m_spellInfo);
    else if (m_caster->GetTypeId() == TYPEID_PLAYER)
        return m_caster->ToPlayer()->GetGlobalCooldownMgr().HasGlobalCooldown(m_spellInfo);
    else
        return false;
}

void Spell::TriggerGlobalCooldown()
{
    int32 gcd = m_spellInfo->StartRecoveryTime;
    if (!gcd)
        return;

    // Global cooldown can't leave range 1..1.5 secs
    // There are some spells (mostly not casted directly by player) that have < 1 sec and > 1.5 sec global cooldowns
    // but as tests show are not affected by any spell mods.
    if (m_spellInfo->StartRecoveryTime >= MIN_GCD && m_spellInfo->StartRecoveryTime <= MAX_GCD)
    {
        // gcd modifier auras are applied only to own spells and only players have such mods
        if (m_caster->GetTypeId() == TYPEID_PLAYER)
            m_caster->ToPlayer()->ApplySpellMod(m_spellInfo->Id, SPELLMOD_GLOBAL_COOLDOWN, gcd, this);

        // Apply haste rating
        gcd = int32(float(gcd) * m_caster->GetFloatValue(UNIT_MOD_CAST_SPEED));
        if (gcd < MIN_GCD)
            gcd = MIN_GCD;
        else if (gcd > MAX_GCD)
            gcd = MAX_GCD;
    }

    // Only players or controlled units have global cooldown
    if (m_caster->GetCharmInfo())
        m_caster->GetCharmInfo()->GetGlobalCooldownMgr().AddGlobalCooldown(m_spellInfo, gcd);
    else if (m_caster->GetTypeId() == TYPEID_PLAYER)
        m_caster->ToPlayer()->GetGlobalCooldownMgr().AddGlobalCooldown(m_spellInfo, gcd);
}

void Spell::CancelGlobalCooldown()
{
    if (!m_spellInfo->StartRecoveryTime)
        return;

    // Cancel global cooldown when interrupting current cast
    if (m_caster->GetCurrentSpell(CURRENT_GENERIC_SPELL) != this)
        return;

    // Only players or controlled units have global cooldown
    if (m_caster->GetCharmInfo())
        m_caster->GetCharmInfo()->GetGlobalCooldownMgr().CancelGlobalCooldown(m_spellInfo);
    else if (m_caster->GetTypeId() == TYPEID_PLAYER)
        m_caster->ToPlayer()->GetGlobalCooldownMgr().CancelGlobalCooldown(m_spellInfo);
}

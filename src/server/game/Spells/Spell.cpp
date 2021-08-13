/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Spell.h"
#include "AzeriteEmpoweredItem.h"
#include "Battlefield.h"
#include "BattlefieldMgr.h"
#include "Battleground.h"
#include "BattlePetMgr.h"
#include "CellImpl.h"
#include "CombatLogPackets.h"
#include "Common.h"
#include "ConditionMgr.h"
#include "Containers.h"
#include "CreatureAI.h"
#include "DB2Stores.h"
#include "DatabaseEnv.h"
#include "DisableMgr.h"
#include "DynamicObject.h"
#include "G3DPosition.hpp"
#include "GameObjectAI.h"
#include "GridNotifiersImpl.h"
#include "Guild.h"
#include "InstanceLockMgr.h"
#include "InstanceScript.h"
#include "Item.h"
#include "Log.h"
#include "Loot.h"
#include "LootMgr.h"
#include "ObjectAccessor.h"
#include "Opcodes.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "World.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"
#include "ObjectMgr.h"
#include "SpellMgr.h"
#include "Player.h"
#include "Pet.h"
#include "DynamicObject.h"
#include "Group.h"
#include "MapManager.h"
#include "ObjectAccessor.h"
#include "SharedDefines.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "SpellPackets.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "TradeData.h"
#include "TraitPackets.h"
#include "Util.h"
#include "LootMgr.h"
#include "VMapFactory.h"
#include "Vehicle.h"
#include "VMapManager2.h"
#include "World.h"
#include "WorldSession.h"
#include <numeric>
#include <sstream>
#include "BattleGround.h"
#include "Util.h"
#include "PathFinder.h"
#include "CharacterDatabaseCache.h"
#include "ZoneScript.h"

extern NonDefaultConstructible<SpellEffectHandlerFn> SpellEffectHandlers[TOTAL_SPELL_EFFECTS];
using namespace Spells;

#define SPELL_CHANNEL_UPDATE_INTERVAL (1 * IN_MILLISECONDS)

extern pEffect SpellEffects[TOTAL_SPELL_EFFECTS];

bool IsQuestTameSpell(uint32 spellId)
{
    SpellEntry const* spellproto = sSpellMgr.GetSpellEntry(spellId);
    if (!spellproto)
        return false;

SpellDestination::SpellDestination(WorldLocation const& loc)
{
    _position.WorldRelocate(loc);
    _transportGUID.Clear();
    _transportOffset.Relocate(0, 0, 0, 0);
}

SpellDestination::SpellDestination(WorldObject const& wObj)
{
    _transportGUID = wObj.GetTransGUID();
    _transportOffset.Relocate(wObj.GetTransOffsetX(), wObj.GetTransOffsetY(), wObj.GetTransOffsetZ(), wObj.GetTransOffsetO());
    _position.Relocate(wObj);
    return spellproto->Effect[EFFECT_INDEX_0] == SPELL_EFFECT_THREAT
           && spellproto->Effect[EFFECT_INDEX_1] == SPELL_EFFECT_APPLY_AURA && spellproto->EffectApplyAuraName[EFFECT_INDEX_1] == SPELL_AURA_DUMMY;
}

SpellCastTargets::SpellCastTargets()
{
    m_unitTarget = nullptr;
    m_itemTarget = nullptr;
    m_GOTarget   = nullptr;

    m_itemTargetEntry  = 0;

    m_srcX = m_srcY = m_srcZ = m_destX = m_destY = m_destZ = 0.0f;
    m_targetMask = 0;
}

SpellCastTargets::~SpellCastTargets()
{
}

void SpellCastTargets::setUnitTarget(Unit* target)
{
    if (spellCastRequest.Target.SrcLocation)
    {
        m_src._transportGUID = spellCastRequest.Target.SrcLocation->Transport;
        Position* pos;
        if (!m_src._transportGUID.IsEmpty())
            pos = &m_src._transportOffset;
        else
            pos = &m_src._position;

        pos->Relocate(spellCastRequest.Target.SrcLocation->Location);
        if (spellCastRequest.Target.Orientation)
            pos->SetOrientation(*spellCastRequest.Target.Orientation);
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
        if (spellCastRequest.Target.Orientation)
            pos->SetOrientation(*spellCastRequest.Target.Orientation);
    }

    SetPitch(spellCastRequest.MissileTrajectory.Pitch);
    SetSpeed(spellCastRequest.MissileTrajectory.Speed);

    Update(caster);
}

SpellCastTargets::~SpellCastTargets() { }

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
    if (!target)
        return;

    m_destX = target->GetPositionX();
    m_destY = target->GetPositionY();
    m_destZ = target->GetPositionZ();
    m_unitTarget = target;
    m_unitTargetGUID = target->GetObjectGuid();
    m_targetMask |= TARGET_FLAG_UNIT;
}

void SpellCastTargets::setDestination(float x, float y, float z)
{
    m_destX = x;
    m_destY = y;
    m_destZ = z;
    m_targetMask |= TARGET_FLAG_DEST_LOCATION;
}

void SpellCastTargets::setSource(float x, float y, float z)
{
    m_srcX = x;
    m_srcY = y;
    m_srcZ = z;
    m_targetMask |= TARGET_FLAG_SOURCE_LOCATION;
}

void SpellCastTargets::setGOTarget(GameObject* target)
{
    m_GOTarget = target;
    m_GOTargetGUID = target->GetObjectGuid();
    //    m_targetMask |= TARGET_FLAG_OBJECT;
}

void SpellCastTargets::setItemTarget(Item* item)
{
    if (!item)
        return;

    m_itemTarget = item;
    m_itemTargetGUID = item->GetObjectGuid();
    m_itemTargetEntry = item->GetEntry();
    m_targetMask |= TARGET_FLAG_ITEM;
}

void SpellCastTargets::setTradeItemTarget(Player* caster)
{
    m_itemTargetGUID = ObjectGuid(uint64(TRADE_SLOT_NONTRADED));
    m_itemTargetEntry = 0;
    m_targetMask |= TARGET_FLAG_TRADE_ITEM;

    Update(caster);
}

void SpellCastTargets::setCorpseTarget(Corpse* corpse)
{
    m_CorpseTargetGUID = corpse->GetObjectGuid();
}

void SpellCastTargets::Update(SpellCaster* pCaster)
{
    m_GOTarget   = m_GOTargetGUID ? pCaster->GetMap()->GetGameObject(m_GOTargetGUID) : nullptr;
    m_unitTarget = m_unitTargetGUID ?
                   (m_unitTargetGUID == pCaster->GetObjectGuid() ? pCaster->ToUnit() : ObjectAccessor::GetUnit(*pCaster, m_unitTargetGUID)) :
                   nullptr;

    m_itemTarget = nullptr;
    if (Player* pPlayer = pCaster->ToPlayer())
    {
        if (m_targetMask & TARGET_FLAG_ITEM)
            m_itemTarget = pPlayer->GetItemByGuid(m_itemTargetGUID);
        else if (m_targetMask & TARGET_FLAG_TRADE_ITEM)
        {
            if (TradeData* pTrade = pPlayer->GetTradeData())
                if (m_itemTargetGUID.GetRawValue() < TRADE_SLOT_COUNT)
                    m_itemTarget = pTrade->GetTraderData()->GetItem(TradeSlots(m_itemTargetGUID.GetRawValue()));
        }

        if (m_itemTarget)
            m_itemTargetEntry = m_itemTarget->GetEntry();
    }
}

void SpellCastTargets::read(ByteBuffer& data, Unit* caster)
{
    data >> m_targetMask;

    if (m_targetMask == TARGET_FLAG_SELF)
    {
        m_destX = caster->GetPositionX();
        m_destY = caster->GetPositionY();
        m_destZ = caster->GetPositionZ();
        m_unitTarget = caster;
        m_unitTargetGUID = caster->GetObjectGuid();
        return;
    }

    // TARGET_FLAG_UNK2 is used for non-combat pets, maybe other?
    if (m_targetMask & (TARGET_FLAG_UNIT | TARGET_FLAG_UNK2))
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
        data >> m_unitTargetGUID.ReadAsPacked();
#else
        data >> m_unitTargetGUID;
#endif

    if (m_targetMask & (TARGET_FLAG_OBJECT | TARGET_FLAG_OBJECT_UNK))
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
        data >> m_GOTargetGUID.ReadAsPacked();
#else
        data >> m_GOTargetGUID;
#endif

    if ((m_targetMask & (TARGET_FLAG_ITEM | TARGET_FLAG_TRADE_ITEM)) && caster->IsPlayer())
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
        data >> m_itemTargetGUID.ReadAsPacked();
#else
        data >> m_itemTargetGUID;
#endif

    if (m_targetMask & TARGET_FLAG_SOURCE_LOCATION)
    {
        data >> m_srcX >> m_srcY >> m_srcZ;
        if (!MaNGOS::IsValidMapCoord(m_srcX, m_srcY, m_srcZ))
            throw ByteBufferException(false, data.rpos(), 0, data.size());
    }

    if (m_targetMask & TARGET_FLAG_DEST_LOCATION)
    {
        data >> m_destX >> m_destY >> m_destZ;
        if (!MaNGOS::IsValidMapCoord(m_destX, m_destY, m_destZ))
            throw ByteBufferException(false, data.rpos(), 0, data.size());
    }

    if (m_targetMask & TARGET_FLAG_STRING)
        data >> m_strTarget;

    if (m_targetMask & (TARGET_FLAG_CORPSE | TARGET_FLAG_PVP_CORPSE))
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
        data >> m_CorpseTargetGUID.ReadAsPacked();
#else
        data >> m_CorpseTargetGUID;
#endif

    // find real units/GOs
    Update(caster);
}

void SpellCastTargets::write(ByteBuffer& data) const
{
    data << uint16(m_targetMask);

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
    if (m_targetMask & (TARGET_FLAG_UNIT | TARGET_FLAG_PVP_CORPSE | TARGET_FLAG_OBJECT | TARGET_FLAG_CORPSE | TARGET_FLAG_UNK2))
    {
        if (m_targetMask & TARGET_FLAG_UNIT)
        {
            if (m_unitTarget)
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
                data << m_unitTarget->GetPackGUID();
#else
                data << m_unitTarget->GetGUID();
#endif
            else
                data << uint8(0);
        }
        else if (m_targetMask & (TARGET_FLAG_OBJECT | TARGET_FLAG_OBJECT_UNK))
        {
            if (m_GOTarget)
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
                data << m_GOTarget->GetPackGUID();
#else
                data << m_GOTarget->GetGUID();
#endif
            else
                data << uint8(0);
        }
        else if (m_targetMask & (TARGET_FLAG_CORPSE | TARGET_FLAG_PVP_CORPSE))
            data << m_CorpseTargetGUID.WriteAsPacked();
        else
            data << uint8(0);
    }

    m_itemTarget = nullptr;
    if (caster->GetTypeId() == TYPEID_PLAYER)
    {
        Player* player = caster->ToPlayer();
        if (m_targetMask & TARGET_FLAG_ITEM)
            m_itemTarget = player->GetItemByGuid(m_itemTargetGUID);
        else if (m_targetMask & TARGET_FLAG_TRADE_ITEM)
        {
            if (m_itemTargetGUID == ObjectGuid::TradeItem)
                if (TradeData* pTrade = player->GetTradeData())
                    m_itemTarget = pTrade->GetTraderData()->GetItem(TRADE_SLOT_NONTRADED);
        }

    if (m_targetMask & (TARGET_FLAG_ITEM | TARGET_FLAG_TRADE_ITEM))
    {
        if (m_itemTarget)
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
            data << m_itemTarget->GetPackGUID();
#else
            data << m_itemTarget->GetGUID();
#endif
        else
            data << uint8(0);
    }

    // update positions by transport move
    if (HasSrc() && !m_src._transportGUID.IsEmpty())
    {
        if (WorldObject* transport = ObjectAccessor::GetWorldObject(*caster, m_src._transportGUID))
        {
            m_src._position.Relocate(transport);
            m_src._position.RelocateOffset(m_src._transportOffset);
        }
    }

    if (HasDst() && !m_dst._transportGUID.IsEmpty())
    {
        if (WorldObject* transport = ObjectAccessor::GetWorldObject(*caster, m_dst._transportGUID))
        {
            m_dst._position.Relocate(transport);
            m_dst._position.RelocateOffset(m_dst._transportOffset);
        }
    }
}

SpellValue::SpellValue(SpellInfo const* proto, WorldObject const* caster)
{
    memset(EffectBasePoints, 0, sizeof(EffectBasePoints));
    for (SpellEffectInfo const& spellEffectInfo : proto->GetEffects())
        EffectBasePoints[spellEffectInfo.EffectIndex] = spellEffectInfo.CalcBaseValue(caster, nullptr, 0, -1);
    if (m_targetMask & TARGET_FLAG_SOURCE_LOCATION)
        data << m_srcX << m_srcY << m_srcZ;

    if (m_targetMask & TARGET_FLAG_DEST_LOCATION)
        data << m_destX << m_destY << m_destZ;

    if (m_targetMask & TARGET_FLAG_STRING)
        data << m_strTarget;
}

Spell::Spell(Unit* caster, SpellEntry const* info, bool triggered, ObjectGuid originalCasterGUID, SpellEntry const* triggeredBy, Unit* victim, SpellEntry const* triggeredByParent):
    m_spellInfo(info), m_triggeredBySpellInfo(triggeredBy), m_triggeredByParentSpellInfo(triggeredByParent), m_caster(caster), m_casterUnit(caster), m_IsTriggeredSpell(triggered)
{
    MANGOS_ASSERT(caster != nullptr && info != nullptr);
    MANGOS_ASSERT(info == sSpellMgr.GetSpellEntry(info->Id) && "`info` must be pointer to a sSpellMgr element");

    CustomBasePointsMask = 0;
    MaxAffectedTargets = proto->MaxAffectedTargets;
    RadiusMod = 1.0f;
    AuraStackAmount = 1;
    CriticalChance = 0.0f;
    DurationMul = 1;
}
    // Get data for type of attack
    m_attackType = m_spellInfo->GetWeaponAttackType();
    m_spellSchoolMask = info->GetSpellSchoolMask();           // Can be override for some spell (wand shoot for example)

class TC_GAME_API SpellEvent : public BasicEvent
{
public:
    SpellEvent(Spell* spell);
    ~SpellEvent();
    // wand case
    if (m_attackType == RANGED_ATTACK)
        if (!!(caster->GetClassMask() & CLASSMASK_WAND_USERS) && caster->IsPlayer())
            m_spellSchoolMask = GetSchoolMask(caster->GetWeaponDamageSchool(RANGED_ATTACK));

    m_originalCasterGUID = originalCasterGUID ? originalCasterGUID : caster->GetObjectGuid();
    UpdateOriginalCasterPointer();

    for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
        m_currentBasePoints[i] = m_spellInfo->CalculateSimpleValue(SpellEffectIndex(i));

Spell::Spell(WorldObject* caster, SpellInfo const* info, TriggerCastFlags triggerFlags, ObjectGuid originalCasterGUID /*= ObjectGuid::Empty*/,
    ObjectGuid originalCastId /*= ObjectGuid::Empty*/) :
m_spellInfo(info), m_caster((info->HasAttribute(SPELL_ATTR6_ORIGINATE_FROM_CONTROLLER) && caster->GetCharmerOrOwner()) ? caster->GetCharmerOrOwner() : caster),
m_spellValue(new SpellValue(m_spellInfo, caster)), _spellEvent(nullptr)
{
    m_customError = SPELL_CUSTOM_ERROR_NONE;
    m_fromClient = false;
    m_selfContainer = nullptr;
    m_referencedFromCurrentSpell = false;
    m_executedCurrently = false;
    m_needComboPoints = m_spellInfo->NeedsComboPoints();
    m_comboPointGain = 0;
    m_delayStart = 0;
    m_delayAtDamageCount = 0;
    m_TriggerSpells.clear();
    m_preCastSpells.clear();

    //Auto Shot & Shoot
    m_autoRepeat = m_spellInfo->IsAutoRepeatRangedSpell();
    m_channeled = info->IsChanneledSpell();

    // determine reflection
    m_canReflect = victim ? m_spellInfo->IsReflectableSpell(caster, victim) : m_spellInfo->IsReflectableSpell();

    // Must initialize to an element in the list or bad things happen,
    // begin changes so use end
    m_channeledUpdateIterator = m_channeledHolders.end();

    if (Player const* playerCaster = m_caster->ToPlayer())
    {
        // wand case
        if (m_attackType == RANGED_ATTACK)
            if ((playerCaster->GetClassMask() & CLASSMASK_WAND_USERS) != 0)
                if (Item* pItem = playerCaster->GetWeaponForAttack(RANGED_ATTACK))
                    m_spellSchoolMask = SpellSchoolMask(1 << pItem->GetTemplate()->GetDamageType());
    }
    CleanupTargetList();
}

    if (Player const* modOwner = caster->GetSpellModOwner())
        modOwner->ApplySpellMod(info, SpellModOp::Doses, m_spellValue->AuraStackAmount, this);

    if (!originalCasterGUID.IsEmpty())
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
Spell::Spell(GameObject* caster, SpellEntry const* info, bool triggered, ObjectGuid originalCasterGUID, SpellEntry const* triggeredBy, Unit* victim, SpellEntry const* triggeredByParent):
    m_spellInfo(info), m_triggeredBySpellInfo(triggeredBy), m_triggeredByParentSpellInfo(triggeredByParent), m_caster(caster), m_casterGo(caster), m_IsTriggeredSpell(triggered)
{
    MANGOS_ASSERT(caster != nullptr && info != nullptr);
    MANGOS_ASSERT(info == sSpellMgr.GetSpellEntry(info->Id) && "`info` must be pointer to a sSpellMgr element");

    m_spellState = SPELL_STATE_NULL;
    _triggeredCastFlags = triggerFlags;
    // Get data for type of attack
    m_attackType = m_spellInfo->GetWeaponAttackType();
    m_spellSchoolMask = info->GetSpellSchoolMask();           // Can be override for some spell (wand shoot for example)

    if (info->HasAttribute(SPELL_ATTR2_DO_NOT_REPORT_SPELL_FAILURE))
        _triggeredCastFlags = TriggerCastFlags(uint32(_triggeredCastFlags) | TRIGGERED_DONT_REPORT_CAST_ERROR);

    if (info->HasAttribute(SPELL_ATTR4_ALLOW_CAST_WHILE_CASTING))
        _triggeredCastFlags = TriggerCastFlags(uint32(_triggeredCastFlags) | TRIGGERED_IGNORE_CAST_IN_PROGRESS);

    m_CastItem = nullptr;
    m_castItemGUID.Clear();
    m_castItemEntry = 0;
    m_castItemLevel = -1;
    m_castFlagsEx = 0;
    m_originalCasterGUID = originalCasterGUID ? originalCasterGUID : caster->GetObjectGuid();
    UpdateOriginalCasterPointer();

    if (IsIgnoringCooldowns())
        m_castFlagsEx |= CAST_FLAG_EX_IGNORE_COOLDOWN;

    unitTarget = nullptr;
    itemTarget = nullptr;
    gameObjTarget = nullptr;
    m_corpseTarget = nullptr;
    destTarget = nullptr;
    damage = 0;
    targetMissInfo = SPELL_MISS_NONE;
    variance = 0.0f;
    effectHandleMode = SPELL_EFFECT_HANDLE_LAUNCH;
    effectInfo = nullptr;
    m_damage = 0;
    m_healing = 0;
    m_hitMask = PROC_HIT_NONE;
    focusObject = nullptr;
    m_castId = ObjectGuid::Create<HighGuid::Cast>(SPELL_CAST_SOURCE_NORMAL, m_caster->GetMapId(), m_spellInfo->Id, m_caster->GetMap()->GenerateLowGuid<HighGuid::Cast>());
    m_originalCastId = originalCastId;
    memset(m_misc.Raw.Data, 0, sizeof(m_misc.Raw.Data));
    m_SpellVisual.SpellXSpellVisualID = caster->GetCastSpellXSpellVisualId(m_spellInfo);
    m_triggeredByAuraSpell  = nullptr;
    _spellAura = nullptr;
    _dynObjAura = nullptr;
    for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
        m_currentBasePoints[i] = m_spellInfo->CalculateSimpleValue(SpellEffectIndex(i));

    m_TriggerSpells.clear();
    m_preCastSpells.clear();

    //Auto Shot & Shoot
    m_autoRepeat = m_spellInfo->IsAutoRepeatRangedSpell();
    m_channeled = info->IsChanneledSpell();

    // determine reflection
    m_canReflect = victim ? m_spellInfo->IsReflectableSpell(caster, victim) : m_spellInfo->IsReflectableSpell();

    // Must initialize to an element in the list or bad things happen,
    // begin changes so use end
    m_channeledUpdateIterator = m_channeledHolders.end();

    // Determine if spell can be reflected back to the caster
    // Patch 1.2 notes: Spell Reflection no longer reflects abilities
    m_canReflect = caster->IsUnit() && m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MAGIC && !m_spellInfo->HasAttribute(SPELL_ATTR0_IS_ABILITY)
        && !m_spellInfo->HasAttribute(SPELL_ATTR1_NO_REFLECTION) && !m_spellInfo->HasAttribute(SPELL_ATTR0_NO_IMMUNITIES)
        && !m_spellInfo->IsPassive();

    CleanupTargetList();
}

Spell::~Spell()
{
    m_destroyed = true;
}

    if (m_referencedFromCurrentSpell && m_selfContainer && *m_selfContainer == this)
    {
        // Clean the reference to avoid later crash.
        // If this error is repeating, we may have to add an ASSERT to better track down how we get into this case.
        TC_LOG_ERROR("spells", "SPELL: deleting spell for spell ID {}. However, spell still referenced.", m_spellInfo->Id);
        *m_selfContainer = nullptr;
    }
template<typename T>
WorldObject* Spell::FindCorpseUsing()
{
    if (!m_casterUnit)
        return nullptr;

    // non-standard target selection
    SpellRangeEntry const* srange = sSpellRangeStore.LookupEntry(m_spellInfo->rangeIndex);
    float max_range = GetSpellMaxRange(srange);

    WorldObject* result = nullptr;

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
    T u_check(m_casterUnit, max_range);
    MaNGOS::WorldObjectSearcher<T> searcher(result, u_check);

    Cell::VisitGridObjects(m_casterUnit, searcher, max_range);

    if (!result)
        Cell::VisitWorldObjects(m_casterUnit, searcher, max_range);

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
    return result;
}

void Spell::FillTargetMap()
{
    // TODO: ADD the correct target FILLS!!!!!!

    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
    for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
    {
        // not call for empty effect.
        // Also some spells use not used effect targets for store targets for dummy effect in triggered spells
        if (!spellEffectInfo.IsEffect())
        if (m_spellInfo->Effect[i] == SPELL_EFFECT_NONE)
            continue;

        // set expected type of implicit targets to be sent to client
        uint32 implicitTargetMask = GetTargetFlagMask(spellEffectInfo.TargetA.GetObjectType()) | GetTargetFlagMask(spellEffectInfo.TargetB.GetObjectType());
        if (implicitTargetMask & TARGET_FLAG_UNIT)
            m_targets.SetTargetFlag(TARGET_FLAG_UNIT);
        if (implicitTargetMask & (TARGET_FLAG_GAMEOBJECT | TARGET_FLAG_GAMEOBJECT_ITEM))
            m_targets.SetTargetFlag(TARGET_FLAG_GAMEOBJECT);

        SelectEffectImplicitTargets(spellEffectInfo, spellEffectInfo.TargetA, processedAreaEffectsMask);
        SelectEffectImplicitTargets(spellEffectInfo, spellEffectInfo.TargetB, processedAreaEffectsMask);
        // targets for TARGET_LOCATION_SCRIPT_NEAR_CASTER (A) and TARGET_UNIT_SCRIPT_NEAR_CASTER
        // for TARGET_GAMEOBJECT_SCRIPT_NEAR_CASTER (A) all is checked in Spell::CheckCast and in Spell::CheckItem
        // filled in Spell::CheckCast call
        if (m_spellInfo->EffectImplicitTargetA[i] == TARGET_LOCATION_SCRIPT_NEAR_CASTER ||
                m_spellInfo->EffectImplicitTargetA[i] == TARGET_UNIT_SCRIPT_NEAR_CASTER ||
                m_spellInfo->EffectImplicitTargetA[i] == TARGET_GAMEOBJECT_SCRIPT_NEAR_CASTER ||
                (m_spellInfo->EffectImplicitTargetB[i] == TARGET_UNIT_SCRIPT_NEAR_CASTER && m_spellInfo->EffectImplicitTargetA[i] != TARGET_UNIT_CASTER))
            continue;

        // Select targets of effect based on effect type
        // those are used when no valid target could be added for spell effect based on spell target type
        // some spell effects use explicit target as a default target added to target map (like SPELL_EFFECT_LEARN_SPELL)
        // some spell effects add target to target map only when target type specified (like SPELL_EFFECT_WEAPON)
        // some spell effects don't add anything to target map (confirmed with sniffs) (like SPELL_EFFECT_DESTROY_ALL_TOTEMS)
        SelectEffectTypeImplicitTargets(spellEffectInfo);
        // TODO: find a way so this is not needed?
        // for area auras always add caster as target (needed for totems for example)
        if (m_casterUnit && IsAreaAuraEffect(m_spellInfo->Effect[i]))
            AddUnitTarget(m_casterUnit, SpellEffectIndex(i));

        if (m_targets.HasDst())
            AddDestTarget(*m_targets.GetDst(), spellEffectInfo.EffectIndex);
#if SUPPORTED_CLIENT_BUILD <= CLIENT_BUILD_1_11_2
        // Pre 1.12 most of the quest complete spells don't have correct target set.
        if (m_casterUnit && m_spellInfo->Effect[i] == SPELL_EFFECT_QUEST_COMPLETE)
            AddUnitTarget(m_casterUnit, SpellEffectIndex(i));
#endif

        if (spellEffectInfo.TargetA.GetObjectType() == TARGET_OBJECT_TYPE_UNIT
            || spellEffectInfo.TargetA.GetObjectType() == TARGET_OBJECT_TYPE_UNIT_AND_DEST
            || spellEffectInfo.TargetB.GetObjectType() == TARGET_OBJECT_TYPE_UNIT
            || spellEffectInfo.TargetB.GetObjectType() == TARGET_OBJECT_TYPE_UNIT_AND_DEST)
        {
            if (m_spellInfo->HasAttribute(SPELL_ATTR1_REQUIRE_ALL_TARGETS))
            {
                bool noTargetFound = std::none_of(m_UniqueTargetInfo.begin(), m_UniqueTargetInfo.end(), [effectMask = 1u << spellEffectInfo.EffectIndex](TargetInfo const& target)
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
                bool anyNonImmuneTargetFound = std::any_of(m_UniqueTargetInfo.begin(), m_UniqueTargetInfo.end(), [effectMask = 1u << spellEffectInfo.EffectIndex](TargetInfo const& target)
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

            uint32 mask = (1 << spellEffectInfo.EffectIndex);
            for (auto ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
            {
                if (ihit->EffectMask & mask)
                {
                    m_channelTargetEffectMask |= mask;
                    break;
                }
            }
        }
    }
        // If same target already filled, use it
        // Example: AoE fear has effects speedup and modfear, with maxtargets = 1
        // We dont want to apply speedup to the first, fear to the second.
        if (m_spellInfo->MaxAffectedTargets > 1)
        {
            bool targetsCopied = false;
            for (int j = 0; j < i; ++j)
            {
                // Check if same target, but handle i.e. AreaAuras different
                if (m_spellInfo->EffectImplicitTargetA[i] == m_spellInfo->EffectImplicitTargetA[j] &&
                        m_spellInfo->EffectImplicitTargetB[i] == m_spellInfo->EffectImplicitTargetB[j] &&
                        m_spellInfo->Effect[j] != SPELL_EFFECT_NONE &&
                        !IsAreaAuraEffect(m_spellInfo->Effect[i]) &&
                        !IsAreaAuraEffect(m_spellInfo->Effect[j]))
                {
                    targetsCopied = true;
                    // Copy targets from effect j to effect i
                    for (TargetList::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
                        if (ihit->effectMask & (1 << j))
                        {
                            if (Unit* unit = m_caster->GetMap()->GetUnit(ihit->targetGUID))
                                AddUnitTarget(unit, SpellEffectIndex(i)); // Will not invalidate the iterator, since it updates the current Target.
                            else // Failed. Better do the computation once again.
                            {
                                for (ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
                                    ihit->effectMask &= ~(1 << i);
                                targetsCopied = false;
                                break;
                            }
                        }
                    break;
                }
            }
            if (targetsCopied)
                continue;
        }

        UnitList tmpUnitMap;

        // TargetA/TargetB dependent from each other, we not switch to full support this dependences
        // but need it support in some know cases
        switch (m_spellInfo->EffectImplicitTargetA[i])
        {
            // We should not subtract caster size from dist calculation (fixes execution time desync with animation on client, eg. Malleable Goo cast by PP)
            float dist = m_caster->GetExactDist(*m_targets.GetDstPos());
            return uint64(std::floor((dist / m_spellInfo->Speed + launchDelay) * 1000.0f));
        }

        return uint64(std::floor(launchDelay * 1000.0f));
    }

    return 0;
}

void Spell::RecalculateDelayMomentForDst()
{
    m_delayMoment = CalculateDelayMomentForDst(0.0f);
    m_caster->m_Events.ModifyEventTime(_spellEvent, Milliseconds(GetDelayStart() + m_delayMoment));
}

void Spell::SelectEffectImplicitTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, uint32& processedEffectMask)
{
    if (!targetType.GetTarget())
        return;

    uint32 effectMask = 1 << spellEffectInfo.EffectIndex;
    // set the same target list for all effects
    // some spells appear to need this, however this requires more research
    switch (targetType.GetSelectionCategory())
    {
        case TARGET_SELECT_CATEGORY_NEARBY:
        case TARGET_SELECT_CATEGORY_CONE:
        case TARGET_SELECT_CATEGORY_AREA:
        case TARGET_SELECT_CATEGORY_LINE:
        {
            // targets for effect already selected
            if (effectMask & processedEffectMask)
                return;
            std::vector<SpellEffectInfo> const& effects = GetSpellInfo()->GetEffects();
            // choose which targets we can select at once
            for (uint32 j = spellEffectInfo.EffectIndex + 1; j < effects.size(); ++j)
            {
                if (effects[j].IsEffect() &&
                    spellEffectInfo.TargetA.GetTarget() == effects[j].TargetA.GetTarget() &&
                    spellEffectInfo.TargetB.GetTarget() == effects[j].TargetB.GetTarget() &&
                    spellEffectInfo.ImplicitTargetConditions == effects[j].ImplicitTargetConditions &&
                    spellEffectInfo.CalcRadius(m_caster) == effects[j].CalcRadius(m_caster) &&
                    CheckScriptEffectImplicitTargets(spellEffectInfo.EffectIndex, j))
                {
                    effectMask |= 1 << j;
                }
            }
            processedEffectMask |= effectMask;
            break;
        }
        default:
            break;
    }

    switch (targetType.GetSelectionCategory())
    {
        case TARGET_SELECT_CATEGORY_CHANNEL:
            SelectImplicitChannelTargets(spellEffectInfo, targetType);
            break;
        case TARGET_SELECT_CATEGORY_NEARBY:
            SelectImplicitNearbyTargets(spellEffectInfo, targetType, effectMask);
            break;
        case TARGET_SELECT_CATEGORY_CONE:
            SelectImplicitConeTargets(spellEffectInfo, targetType, effectMask);
            break;
        case TARGET_SELECT_CATEGORY_AREA:
            SelectImplicitAreaTargets(spellEffectInfo, targetType, effectMask);
            break;
        case TARGET_SELECT_CATEGORY_TRAJ:
            // just in case there is no dest, explanation in SelectImplicitDestDestTargets
            CheckDst();

            SelectImplicitTrajTargets(spellEffectInfo, targetType);
            break;
        case TARGET_SELECT_CATEGORY_LINE:
            SelectImplicitLineTargets(spellEffectInfo, targetType, effectMask);
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
                            ABORT_MSG("Spell::SelectEffectImplicitTargets: received not implemented select target reference type for TARGET_TYPE_OBJECT_SRC");
                            break;
                    }
                    break;
                case TARGET_OBJECT_TYPE_DEST:
                     switch (targetType.GetReferenceType())
                     {
                         case TARGET_REFERENCE_TYPE_CASTER:
                             SelectImplicitCasterDestTargets(spellEffectInfo, targetType);
                             break;
                         case TARGET_REFERENCE_TYPE_TARGET:
                             SelectImplicitTargetDestTargets(spellEffectInfo, targetType);
                             break;
                         case TARGET_REFERENCE_TYPE_DEST:
                             SelectImplicitDestDestTargets(spellEffectInfo, targetType);
                             break;
                         default:
                             ABORT_MSG("Spell::SelectEffectImplicitTargets: received not implemented select target reference type for TARGET_TYPE_OBJECT_DEST");
                             break;
                     }
                     break;
                default:
                    switch (targetType.GetReferenceType())
                    {
                        case TARGET_REFERENCE_TYPE_CASTER:
                            SelectImplicitCasterObjectTargets(spellEffectInfo, targetType);
                            break;
                        case TARGET_REFERENCE_TYPE_TARGET:
                            SelectImplicitTargetObjectTargets(spellEffectInfo, targetType);
                            break;
                        default:
                            ABORT_MSG("Spell::SelectEffectImplicitTargets: received not implemented select target reference type for TARGET_TYPE_OBJECT");
                            break;
                    }
                    break;
            }
            break;
        case TARGET_SELECT_CATEGORY_NYI:
            TC_LOG_DEBUG("spells", "SPELL: target type {}, found in spellID {}, effect {} is not implemented yet!", m_spellInfo->Id, uint32(spellEffectInfo.EffectIndex), targetType.GetTarget());
            break;
        default:
            ABORT_MSG("Spell::SelectEffectImplicitTargets: received not implemented select target category");
            break;
    }
}

void Spell::SelectImplicitChannelTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType)
{
    if (targetType.GetReferenceType() != TARGET_REFERENCE_TYPE_CASTER)
    {
        ABORT_MSG("Spell::SelectImplicitChannelTargets: received not implemented target reference type");
        return;
    }

    Spell* channeledSpell = m_originalCaster->GetCurrentSpell(CURRENT_CHANNELED_SPELL);
    if (!channeledSpell)
    {
        TC_LOG_DEBUG("spells", "Spell::SelectImplicitChannelTargets: cannot find channel spell for spell ID {}, effect {}", m_spellInfo->Id, uint32(spellEffectInfo.EffectIndex));
        return;
    }
    switch (targetType.GetTarget())
    {
        case TARGET_UNIT_CHANNEL_TARGET:
        {
            for (ObjectGuid const& channelTarget : m_originalCaster->m_unitData->ChannelObjects)
            {
                WorldObject* target = ObjectAccessor::GetUnit(*m_caster, channelTarget);
                CallScriptObjectTargetSelectHandlers(target, spellEffectInfo.EffectIndex, targetType);
                // unit target may be no longer avalible - teleported out of map for example
                Unit* unitTarget = target ? target->ToUnit() : nullptr;
                if (unitTarget)
                    AddUnitTarget(unitTarget, 1 << spellEffectInfo.EffectIndex);
                else
                    TC_LOG_DEBUG("spells", "SPELL: cannot find channel spell target for spell ID {}, effect {}", m_spellInfo->Id, uint32(spellEffectInfo.EffectIndex));
            }
            break;
            case TARGET_NONE:
                switch (m_spellInfo->EffectImplicitTargetB[i])
                {
                    case TARGET_NONE:
                        SetTargetMap(SpellEffectIndex(i), TARGET_LOCATION_CASTER_DEST, tmpUnitMap);
                        break;
                    default:
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetB[i], tmpUnitMap);
                        break;
                }
                break;
            case TARGET_UNIT_CASTER:
                switch (m_spellInfo->EffectImplicitTargetB[i])
                {
                    case TARGET_NONE:
                        // Arcane Missiles have strange targeting for auras
                        if (m_spellInfo->IsFitToFamily<SPELLFAMILY_MAGE, CF_MAGE_ARCANE_MISSILES_CHANNEL>())
                        {
                            if (Unit* pUnitTarget = m_caster->SelectMagnetTarget(m_targets.getUnitTarget(), this, SpellEffectIndex(i)))
                            {
                                if (m_caster->IsValidAttackTarget(pUnitTarget))
                                    tmpUnitMap.push_back(pUnitTarget);
                            }
                        }
                        else
                            SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetA[i], tmpUnitMap);
                        break;
                    case TARGET_LOCATION_CASTER_DEST:
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetA[i], tmpUnitMap);
                        break;
                    case TARGET_ENUM_UNITS_SCRIPT_AOE_AT_SRC_LOC:         // use B case that not dependent from from A in fact
                        if ((m_targets.m_targetMask & TARGET_FLAG_DEST_LOCATION) == 0)
                            m_targets.setDestination(m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ());
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetB[i], tmpUnitMap);
                        break;
                    default:
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetA[i], tmpUnitMap);
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetB[i], tmpUnitMap);
                        break;
                }
                break;
            case TARGET_LOCATION_CASTER_DEST:
                switch (m_spellInfo->EffectImplicitTargetB[i])
                {
                    case 0:
                    case TARGET_LOCATION_CASTER_DEST:
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetA[i], tmpUnitMap);
                        break;
                    // dest point setup required
                    case TARGET_ENUM_UNITS_SCRIPT_AOE_AT_SRC_LOC:
                    case TARGET_ENUM_UNITS_SCRIPT_AOE_AT_DEST_LOC:
                    case TARGET_ENUM_UNITS_ENEMY_AOE_AT_SRC_LOC:
                    case TARGET_ENUM_UNITS_ENEMY_AOE_AT_DEST_LOC:
                    case TARGET_ENUM_UNITS_ENEMY_AOE_AT_DYNOBJ_LOC:
                    case TARGET_ENUM_UNITS_FRIEND_AOE_AT_DEST_LOC:
                        // triggered spells get dest point from default target set, ignore it
                        if (!(m_targets.m_targetMask & TARGET_FLAG_DEST_LOCATION) || m_IsTriggeredSpell)
                            if (SpellCaster* castObject = GetCastingObject())
                                m_targets.setDestination(castObject->GetPositionX(), castObject->GetPositionY(), castObject->GetPositionZ());
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetB[i], tmpUnitMap);
                        break;
                    // target pre-selection required
                    case TARGET_LOCATION_CASTER_HOME_BIND:
                    case TARGET_LOCATION_DATABASE:
                    case TARGET_LOCATION_CASTER_SRC:
                    case TARGET_LOCATION_SCRIPT_NEAR_CASTER:
                    case TARGET_LOCATION_CASTER_TARGET_POSITION:
                    case TARGET_LOCATION_UNIT_POSITION:
                        // need some target for processing
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetA[i], tmpUnitMap);
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetB[i], tmpUnitMap);
                        break;
                    default:
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetB[i], tmpUnitMap);
                        break;
                }
                break;
            case TARGET_LOCATION_CASTER_SRC:
                switch (m_spellInfo->EffectImplicitTargetB[i])
                {
                    case TARGET_ENUM_UNITS_ENEMY_AOE_AT_SRC_LOC:
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetA[i], tmpUnitMap);
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetB[i], tmpUnitMap);
                        switch (m_spellInfo->Id)
                        {
                            case 5246:
                                // Exception: Intimidating Shout
                                // The AoE fear does not apply to spell main target (that is stunned by another aura)
                                for (UnitList::iterator itr = tmpUnitMap.begin(); itr != tmpUnitMap.end();)
                                {
                                    if (*itr == m_targets.getUnitTarget())
                                        itr = tmpUnitMap.erase(itr);
                                    else
                                        ++itr;
                                }
                                break;
                            case 25676:                                         // Drain Mana
                            case 25754:
                            case 26457:
                            case 26559:
                                // Avoid targeting players with no mana
                                for (UnitList::iterator itr = tmpUnitMap.begin(); itr != tmpUnitMap.end();)
                                {
                                    if ((*itr)->GetPowerType() != POWER_MANA || (*itr)->GetPowerPercent(POWER_MANA) < 1.0f)
                                        itr = tmpUnitMap.erase(itr);
                                    else
                                        ++itr;
                                }
                                break;
                            case 27831:
                                // Shadow Bolt volley which should only target players with the Shadow Mark debuff
                                for (UnitList::iterator itr = tmpUnitMap.begin(); itr != tmpUnitMap.end();)
                                {
                                    if (!(*itr)->HasAura(27825)) // Shadow Mark
                                        itr = tmpUnitMap.erase(itr);
                                    else
                                        ++itr;
                                }
                                break;
                            case 29484:
                                // Maexxna Web Spray should not hit players under Web Wrap or Petrification
                                for (UnitList::iterator itr = tmpUnitMap.begin(); itr != tmpUnitMap.end();)
                                {
                                    if ((*itr)->HasAura(17624) || (*itr)->HasAura(28622))
                                        itr = tmpUnitMap.erase(itr);
                                    else
                                        ++itr;
                                }
                                break;
                        }
                        break;
                    case TARGET_LOCATION_UNIT_MINION_POSITION:
                    case TARGET_LOCATION_CASTER_FRONT_RIGHT:
                    case TARGET_LOCATION_CASTER_BACK_RIGHT:
                    case TARGET_LOCATION_CASTER_BACK_LEFT:
                    case TARGET_LOCATION_CASTER_FRONT_LEFT:
                    case TARGET_LOCATION_CASTER_FRONT:
                    case TARGET_LOCATION_CASTER_BACK:
                    case TARGET_LOCATION_CASTER_LEFT:
                    case TARGET_LOCATION_CASTER_RIGHT:
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetB[i], tmpUnitMap);
                        break;
                    case 0:
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetA[i], tmpUnitMap);
                        if (m_casterUnit)
                            tmpUnitMap.push_back(m_casterUnit);
                        else if (m_casterGo)
                            AddGOTarget(m_casterGo, SpellEffectIndex(i));
                        break;
                    default:
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetA[i], tmpUnitMap);
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetB[i], tmpUnitMap);
                        break;
                }
                break;
            case TARGET_LOCATION_DATABASE:
                switch (m_spellInfo->EffectImplicitTargetB[i])
                {
                    case 0:
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetA[i], tmpUnitMap);

                        // need some target for processing
                        SetTargetMap(SpellEffectIndex(i), TARGET_LOCATION_CASTER_DEST, tmpUnitMap);
                        break;
                    case TARGET_ENUM_UNITS_SCRIPT_AOE_AT_SRC_LOC:         // All 17/7 pairs used for dest teleportation, A processed in effect code
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetB[i], tmpUnitMap);
                        break;
                    default:
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetA[i], tmpUnitMap);
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetB[i], tmpUnitMap);
                        break;
                }
                break;
            case TARGET_LOCATION_UNIT_POSITION:
                switch (m_spellInfo->EffectImplicitTargetB[i])
                {
                    case 0:
                    case TARGET_LOCATION_CASTER_DEST:
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetA[i], tmpUnitMap);
                        if (Unit* currentTarget = m_targets.getUnitTarget())
                            tmpUnitMap.push_back(currentTarget);
                        break;
                    default:
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetA[i], tmpUnitMap);
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetB[i], tmpUnitMap);
                        break;
                }
                break;
            case TARGET_ENUM_UNITS_ENEMY_AOE_AT_SRC_LOC:
                if ((m_targets.m_targetMask & TARGET_FLAG_SOURCE_LOCATION) && !(m_targets.m_targetMask & TARGET_FLAG_DEST_LOCATION))
                    m_targets.setDestination(m_targets.m_srcX, m_targets.m_srcY, m_targets.m_srcZ);
                SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetA[i], tmpUnitMap);
                break;
            default:
                switch (m_spellInfo->EffectImplicitTargetB[i])
                {
                    case TARGET_NONE:
                    case TARGET_LOCATION_CASTER_DEST:
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetA[i], tmpUnitMap);
                        break;
                    case TARGET_LOCATION_SCRIPT_NEAR_CASTER:         // B case filled in CheckCast but we need fill unit list base at A case
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetA[i], tmpUnitMap);
                        break;
                    default:
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetA[i], tmpUnitMap);
                        SetTargetMap(SpellEffectIndex(i), m_spellInfo->EffectImplicitTargetB[i], tmpUnitMap);
                        break;
                }
                break;
        }
        case TARGET_DEST_CHANNEL_TARGET:
            if (channeledSpell->m_targets.HasDst())
                m_targets.SetDst(channeledSpell->m_targets);
            else
            {
                auto const& channelObjects = m_originalCaster->m_unitData->ChannelObjects;
                WorldObject* target = !channelObjects.empty() ? ObjectAccessor::GetWorldObject(*m_caster, *channelObjects.begin()) : nullptr;
                if (target)
                {
                    CallScriptObjectTargetSelectHandlers(target, spellEffectInfo.EffectIndex, targetType);
                    if (target)
                    {
                        SpellDestination dest(*target);
                        if (m_spellInfo->HasAttribute(SPELL_ATTR4_USE_FACING_FROM_SPELL))
                            dest._position.SetOrientation(spellEffectInfo.PositionFacing);

                        CallScriptDestinationTargetSelectHandlers(dest, spellEffectInfo.EffectIndex, targetType);
                        m_targets.SetDst(dest);
                    }
                }
                else
                    TC_LOG_DEBUG("spells", "SPELL: cannot find channel spell destination for spell ID {}, effect {}", m_spellInfo->Id, uint32(spellEffectInfo.EffectIndex));
            }
            break;
        case TARGET_DEST_CHANNEL_CASTER:
        {
            SpellDestination dest(*channeledSpell->GetCaster());
            if (m_spellInfo->HasAttribute(SPELL_ATTR4_USE_FACING_FROM_SPELL))
                dest._position.SetOrientation(spellEffectInfo.PositionFacing);

            CallScriptDestinationTargetSelectHandlers(dest, spellEffectInfo.EffectIndex, targetType);
            m_targets.SetDst(dest);
            break;

        for (UnitList::iterator itr = tmpUnitMap.begin(); itr != tmpUnitMap.end();)
        {
            if (!CheckTarget(*itr, SpellEffectIndex(i)))
            {
                itr = tmpUnitMap.erase(itr);
                continue;
            }
            else
                ++itr;
        }
        default:
            ABORT_MSG("Spell::SelectImplicitChannelTargets: received not implemented target type");
            break;

        for (const auto iunit : tmpUnitMap)
            AddUnitTarget(iunit, SpellEffectIndex(i));
    }
}

void Spell::SelectImplicitNearbyTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, uint32 effMask)
{
    if (targetType.GetReferenceType() != TARGET_REFERENCE_TYPE_CASTER)
    {
        ABORT_MSG("Spell::SelectImplicitNearbyTargets: received not implemented target reference type");
        return;
    }
void Spell::prepareDataForTriggerSystem()
{
    //==========================================================================================
    // Now fill data for trigger system, need know:
    // an spell trigger another or not ( m_canTrigger )
    // Create base triggers flags for Attacker and Victim (m_procAttacker and  m_procVictim)
    //==========================================================================================
    // Fill flag can spell trigger or not
    // TODO: possible exist spell attribute for this
    m_canTrigger = false;
    m_procAttacker = PROC_FLAG_NONE;
    m_procVictim = PROC_FLAG_NONE;

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
            ABORT_MSG("Spell::SelectImplicitNearbyTargets: received not implemented selection check type");
            break;
    }
    if (m_spellInfo->AttributesEx3 & SPELL_ATTR_EX3_CANT_TRIGGER_PROC)
        m_canTrigger = false;         // Explicitly not allowed to trigger
    else if (m_CastItem)
        m_canTrigger = false;         // Do not trigger from item cast spell
    else if (m_originalCasterGUID.IsGameObject())   // Do not trigger anything if the spell is casted by using a game object (eg. Lightwell)
        m_canTrigger = false;
    else if (!m_IsTriggeredSpell)
        m_canTrigger = true;          // Normal cast - can trigger
    else if (!m_triggeredByAuraSpell)
        m_canTrigger = true;          // Triggered from SPELL_EFFECT_TRIGGER_SPELL - can trigger
    else if (m_spellInfo->HasAttribute(SPELL_ATTR_EX2_TRIGGERED_CAN_TRIGGER_PROC) || m_spellInfo->HasAttribute(SPELL_ATTR_EX3_TRIGGERED_CAN_TRIGGER_SPECIAL))
        m_canTrigger = true;          // Spells with these special attributes can trigger even if triggeredByAuraSpell

    if (!m_canTrigger)                // Exceptions (some periodic triggers)
    {
        switch (m_spellInfo->SpellFamilyName)
        {
            case SPELLFAMILY_MAGE:
                // Arcane Missiles / Blizzard triggers need do it
                if (m_spellInfo->IsFitToFamilyMask(uint64(0x0000000000200080)))
                    m_canTrigger = true;
                break;
            case SPELLFAMILY_WARLOCK:
                // For Hellfire Effect / Rain of Fire triggers need do it
                if (m_spellInfo->IsFitToFamilyMask<CF_WARLOCK_RAIN_OF_FIRE, CF_WARLOCK_HELLFIRE>())
                    m_canTrigger = true;
                break;
            case SPELLFAMILY_HUNTER:
                // Hunter Explosive Trap Effect/Immolation Trap Effect/Frost Trap Aura Effect
                if (m_spellInfo->IsFitToFamilyMask<CF_HUNTER_FIRE_TRAP_EFFECTS, CF_HUNTER_FROST_TRAP_AURA>())
                    m_canTrigger = true;
                break;
            case SPELLFAMILY_PALADIN:
                // Seal of Command (example Vengeance proc) | SPELLFAMILY_PALADIN override in spell_mod
                if (m_spellInfo->Id == 20424)
                    m_canTrigger = true;
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
                // Seal of Righteousness
                else if (!m_spellInfo->SpellFamilyFlags && m_spellInfo->SpellIconID == 25)
                    m_canTrigger = true;
#endif
                // Holy Shock
                else if (m_spellInfo->IsFitToFamilyMask<CF_PALADIN_HOLY_SHOCK>())
                    m_canTrigger = true;
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
                // Eye for an Eye triggered spell
                else if (m_spellInfo->Id == 25997)
                    m_canTrigger = true;
#endif
                break;
            case SPELLFAMILY_PRIEST:
                // Touch of Weakness / Devouring Plague
                if (m_spellInfo->IsFitToFamilyMask<CF_PRIEST_TOUCH_OF_WEAKNESS, CF_PRIEST_DEVOURING_PLAGUE>())
                    m_canTrigger = true;
                break;
            default:
                break;
        }
    }

    ConditionContainer* condList = spellEffectInfo.ImplicitTargetConditions;

    // handle emergency case - try to use other provided targets if no conditions provided
    if (targetType.GetCheckType() == TARGET_CHECK_ENTRY && (!condList || condList->empty()))
    {
        TC_LOG_DEBUG("spells", "Spell::SelectImplicitNearbyTargets: no conditions entry for target with TARGET_CHECK_ENTRY of spell ID {}, effect {} - selecting default targets", m_spellInfo->Id, uint32(spellEffectInfo.EffectIndex));
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
                        if (m_spellInfo->HasAttribute(SPELL_ATTR4_USE_FACING_FROM_SPELL))
                            dest._position.SetOrientation(spellEffectInfo.PositionFacing);

                        CallScriptDestinationTargetSelectHandlers(dest, spellEffectInfo.EffectIndex, targetType);
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
    // Get data for type of attack and fill base info for trigger
    switch (m_spellInfo->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_MELEE:
            m_procAttacker = PROC_FLAG_SUCCESSFUL_MELEE_SPELL_HIT;
            if (m_attackType == OFF_ATTACK)
                m_procAttacker |= PROC_FLAG_SUCCESSFUL_OFFHAND_HIT;
            m_procVictim   = PROC_FLAG_TAKEN_MELEE_SPELL_HIT;
            if (m_spellInfo->IsNextMeleeSwingSpell())
            {
                m_procAttacker |= PROC_FLAG_SUCCESSFUL_MELEE_HIT;
                m_procVictim |= PROC_FLAG_TAKEN_MELEE_HIT;
            }
            break;
        case SPELL_DAMAGE_CLASS_RANGED:
            // Auto attack
            if (m_spellInfo->AttributesEx2 & SPELL_ATTR_EX2_AUTOREPEAT_FLAG)
            {
                m_procAttacker = PROC_FLAG_SUCCESSFUL_RANGED_HIT;
                m_procVictim   = PROC_FLAG_TAKEN_RANGED_HIT;
            }
            else // Ranged spell attack
            {
                // If blind or Expose Weakness, don't add proc flags for typical ranged abilities
                // proc none
                if (m_spellInfo->Id == 2094 || m_spellInfo->Id == 23577) {
                    m_procAttacker = PROC_FLAG_NONE;
                    m_procVictim = PROC_FLAG_NONE;
                }
                else {
                    m_procAttacker = PROC_FLAG_SUCCESSFUL_RANGED_SPELL_HIT;
                    m_procVictim   = PROC_FLAG_TAKEN_RANGED_SPELL_HIT;
                }

                if (m_spellInfo->IsAreaOfEffectSpell())
                    m_procAttacker |= PROC_FLAG_SUCCESSFUL_AOE;
            }
            break;
        default:
        {
            bool aoe = m_spellInfo->IsAreaOfEffectSpell();
            bool positive = m_spellInfo->IsPositiveSpell();
            // Some spells should be categorized as AoE
            // Hellfire regularly triggers an AoE spell.
            if (m_spellInfo->IsFitToFamily<SPELLFAMILY_WARLOCK, CF_WARLOCK_HELLFIRE>() && m_spellInfo->SpellIconID == 937)
                aoe = true;

    WorldObject* target = SearchNearbyTarget(range, targetType.GetObjectType(), targetType.GetCheckType(), condList);
    if (!target)
    {
        TC_LOG_DEBUG("spells", "Spell::SelectImplicitNearbyTargets: cannot find nearby target for spell ID {}, effect {}", m_spellInfo->Id, uint32(spellEffectInfo.EffectIndex));
        SendCastResult(SPELL_FAILED_BAD_IMPLICIT_TARGETS);
        finish(false);
        return;
    }

    CallScriptObjectTargetSelectHandlers(target, spellEffectInfo.EffectIndex, targetType);
    if (!target)
    {
        TC_LOG_DEBUG("spells", "Spell::SelectImplicitNearbyTargets: OnObjectTargetSelect script hook for spell Id {} set NULL target, effect {}", m_spellInfo->Id, uint32(spellEffectInfo.EffectIndex));
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
                TC_LOG_DEBUG("spells", "Spell::SelectImplicitNearbyTargets: OnObjectTargetSelect script hook for spell Id {} set object of wrong type, expected unit, got {}, effect {}", m_spellInfo->Id, target->GetGUID().GetTypeName(), effMask);
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
                TC_LOG_DEBUG("spells", "Spell::SelectImplicitNearbyTargets: OnObjectTargetSelect script hook for spell Id {} set object of wrong type, expected gameobject, got {}, effect {}", m_spellInfo->Id, target->GetGUID().GetTypeName(), effMask);
                SendCastResult(SPELL_FAILED_BAD_IMPLICIT_TARGETS);
                finish(false);
                return;
            }
            break;
        case TARGET_OBJECT_TYPE_CORPSE:
            if (Corpse* corpseTarget = target->ToCorpse())
                AddCorpseTarget(corpseTarget, effMask);
            else
            {
                TC_LOG_DEBUG("spells", "Spell::SelectImplicitNearbyTargets: OnObjectTargetSelect script hook for spell Id {} set object of wrong type, expected corpse, got {}, effect {}", m_spellInfo->Id, target->GetGUID().GetTypeName(), effMask);
                SendCastResult(SPELL_FAILED_BAD_IMPLICIT_TARGETS);
                finish(false);
                return;
            }
            break;
        case TARGET_OBJECT_TYPE_DEST:
        {
            SpellDestination dest(*target);
            if (m_spellInfo->HasAttribute(SPELL_ATTR4_USE_FACING_FROM_SPELL))
                dest._position.SetOrientation(spellEffectInfo.PositionFacing);

            CallScriptDestinationTargetSelectHandlers(dest, spellEffectInfo.EffectIndex, targetType);
            m_targets.SetDst(dest);
            break;
        }
        default:
            ABORT_MSG("Spell::SelectImplicitNearbyTargets: received not implemented target object type");
            break;
    }

    SelectImplicitChainTargets(spellEffectInfo, targetType, target, effMask);
}

void Spell::SelectImplicitConeTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, uint32 effMask)
{
    Position coneSrc(*m_caster);
    float coneAngle = m_spellInfo->ConeAngle;
    switch (targetType.GetReferenceType())
    {
        case TARGET_REFERENCE_TYPE_CASTER:
            break;
        case TARGET_REFERENCE_TYPE_DEST:
            if (m_caster->GetExactDist2d(m_targets.GetDstPos()) > 0.1f)
                coneSrc.SetOrientation(m_caster->GetAbsoluteAngle(m_targets.GetDstPos()));
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
    ConditionContainer* condList = spellEffectInfo.ImplicitTargetConditions;
    float radius = spellEffectInfo.CalcRadius(m_caster) * m_spellValue->RadiusMod;

    if (uint32 containerTypeMask = GetSearcherTypeMask(objectType, condList))
    {
        float extraSearchRadius = radius > 0.0f ? EXTRA_CELL_SEARCH_RADIUS : 0.0f;
        Trinity::WorldObjectSpellConeTargetCheck check(coneSrc, DegToRad(coneAngle), m_spellInfo->Width ? m_spellInfo->Width : m_caster->GetCombatReach(), radius, m_caster, m_spellInfo, selectionType, condList, objectType);
        Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellConeTargetCheck> searcher(m_caster, targets, check, containerTypeMask);
        SearchTargets<Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellConeTargetCheck> >(searcher, containerTypeMask, m_caster, m_caster, radius + extraSearchRadius);
            // Check for positive spell. 'Positive' spells include various things such as buffs, but
            // they shouldn't proc with PROC_FLAG_SUCCESSFUL_POSITIVE_SPELL. Note that some spells
            // with SPELL_EFFECT_DISPEL are negative, such as Purge.
            if (positive)
            {
                if (m_spellInfo->IsHealSpell())
                {
                    m_procAttacker = PROC_FLAG_SUCCESSFUL_POSITIVE_SPELL;
                    m_procVictim = PROC_FLAG_TAKEN_POSITIVE_SPELL;
                }
                else
                {
                    m_procAttacker = PROC_FLAG_SUCCESSFUL_NONE_POSITIVE_SPELL;
                    m_procVictim = PROC_FLAG_TAKEN_NONE_POSITIVE_SPELL;
                }

                if (m_spellInfo->IsDispel())
                    m_procAttacker |= PROC_FLAG_SUCCESSFUL_CURE_SPELL_CAST;

                if (aoe)
                    m_procAttacker |= PROC_FLAG_SUCCESSFUL_AOE;

                if (m_spellInfo->IsSpellAppliesPeriodicAura())
                {
                    m_procAttacker |= PROC_FLAG_SUCCESSFUL_PERIODIC_SPELL_HIT;
                    m_procVictim |= PROC_FLAG_TAKEN_PERIODIC_SPELL_HIT;
                }

                // Always proc with PROC_FLAG_SUCCESSFUL_SPELL_CAST if not AoE or triggered spell
                if (!aoe && !IsTriggered())
                {
                    m_procAttacker |= PROC_FLAG_SUCCESSFUL_SPELL_CAST;
                    if (m_powerCost > 0 && m_spellInfo->powerType == POWER_MANA)
                        m_procAttacker |= PROC_FLAG_SUCCESSFUL_MANA_SPELL_CAST;
                }
            }
            // Wands auto attack
            else if (m_spellInfo->AttributesEx2 & SPELL_ATTR_EX2_AUTOREPEAT_FLAG)
            {
                m_procAttacker = PROC_FLAG_SUCCESSFUL_RANGED_HIT;
                m_procVictim   = PROC_FLAG_TAKEN_RANGED_HIT;
            }
            else                                           // Negative spell
            {
                if (m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MAGIC)
                {
                    m_procAttacker = PROC_FLAG_SUCCESSFUL_NEGATIVE_SPELL_HIT;
                    m_procVictim = PROC_FLAG_TAKEN_NEGATIVE_SPELL_HIT;
                }
                else
                {
                    m_procAttacker = PROC_FLAG_SUCCESSFUL_NONE_SPELL_HIT;
                    m_procVictim = PROC_FLAG_TAKEN_NONE_SPELL_HIT;
                }

        CallScriptObjectAreaTargetSelectHandlers(targets, spellEffectInfo.EffectIndex, targetType);
                if (aoe)
                    m_procAttacker |= PROC_FLAG_SUCCESSFUL_AOE;

                if (m_spellInfo->IsSpellAppliesPeriodicAura())
                {
                    m_procAttacker |= PROC_FLAG_SUCCESSFUL_PERIODIC_SPELL_HIT;
                    m_procVictim |= PROC_FLAG_TAKEN_PERIODIC_SPELL_HIT;
                }

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
                if (!aoe && !IsTriggered())
                {
                    m_procAttacker |= PROC_FLAG_SUCCESSFUL_SPELL_CAST;
                    if (m_powerCost > 0 && m_spellInfo->powerType == POWER_MANA)
                        m_procAttacker |= PROC_FLAG_SUCCESSFUL_MANA_SPELL_CAST;
                }
            }
            break;
        }
    }

void Spell::SelectImplicitAreaTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, uint32 effMask)
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
            referer = m_caster;

            // find last added target for this effect
            for (auto ihit = m_UniqueTargetInfo.rbegin(); ihit != m_UniqueTargetInfo.rend(); ++ihit)
            {
                if (ihit->EffectMask & (1 << spellEffectInfo.EffectIndex))
                {
                    referer = ObjectAccessor::GetUnit(*m_caster, ihit->TargetGUID);
                    break;
                }
            }
            break;
        }
        default:
            ABORT_MSG("Spell::SelectImplicitAreaTargets: received not implemented target reference type");
            return;
    }
    // some negative spells have positive effects to another or same targets
    // avoid triggering negative hit for only positive targets
    m_negativeEffectMask = 0x0;
    for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
    {
        if (!m_spellInfo->IsPositiveEffect(SpellEffectIndex(i)))
            m_negativeEffectMask |= (1 << i);

        // Self damage is a positive effect but should still trigger negative proc flags
        if (m_spellInfo->Effect[i] == SPELL_EFFECT_SCHOOL_DAMAGE && m_spellInfo->EffectImplicitTargetA[i] == TARGET_UNIT_CASTER)
            m_negativeEffectMask |= (1 << i);
    }

}

void Spell::CleanupTargetList()
{
    /*
        m_UniqueTargetInfo.clear();
        m_UniqueGOTargetInfo.clear();
    */
    for (auto& itr : m_UniqueTargetInfo)
        itr.deleted = true;

    for (auto& itr : m_UniqueGOTargetInfo)
        itr.deleted = true;

    m_UniqueItemInfo.clear();
    m_delayMoment = 0;
}

uint32 Spell::GetSpellBatchingEffectDelay(SpellCaster const* pTarget) const
{
    // This tries to recreate the feeling of spell effect execution being done in batches,
    // by syncing the delay of effects to the world timer so they happen simultaneously.
    return ((sWorld.getConfig(CONFIG_UINT32_SPELL_EFFECT_DELAY) && pTarget != m_casterUnit) ?
           (sWorld.getConfig(CONFIG_UINT32_SPELL_EFFECT_DELAY) - (WorldTimer::getMSTime() % sWorld.getConfig(CONFIG_UINT32_SPELL_EFFECT_DELAY))) : 0);
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
             ABORT_MSG("Spell::SelectImplicitAreaTargets: received not implemented target reference type");
             return;
    }
void Spell::AddUnitTarget(Unit* pTarget, SpellEffectIndex effIndex)
{
    if (m_spellInfo->Effect[effIndex] == 0)
        return;

    float radius = spellEffectInfo.CalcRadius(m_caster) * m_spellValue->RadiusMod;
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
                    SearchAreaTargets(targets, radius, targetedUnit, referer, targetType.GetObjectType(), targetType.GetCheckType(), spellEffectInfo.ImplicitTargetConditions);
            }
            break;
        case TARGET_UNIT_CASTER_AND_SUMMONS:
            targets.push_back(m_caster);
            SearchAreaTargets(targets, radius, center, referer, targetType.GetObjectType(), targetType.GetCheckType(), spellEffectInfo.ImplicitTargetConditions);
            break;
        default:
            SearchAreaTargets(targets, radius, center, referer, targetType.GetObjectType(), targetType.GetCheckType(), spellEffectInfo.ImplicitTargetConditions);
            break;
    }
    if ((m_spellInfo->AttributesEx & SPELL_ATTR_EX_CANT_TARGET_SELF) && (m_spellInfo->EffectImplicitTargetA[effIndex] != TARGET_UNIT_CASTER) && (m_spellInfo->EffectImplicitTargetB[effIndex] != TARGET_UNIT_CASTER) && (pTarget->GetObjectGuid() == m_originalCasterGUID))
        return;

    // Check for effect immune skip if immuned
    bool immuned = pTarget->IsImmuneToSpellEffect(m_spellInfo, effIndex, pTarget == m_caster);

    ObjectGuid targetGUID = pTarget->GetObjectGuid();

    // Lookup target in already in list
    for (auto& ihit : m_UniqueTargetInfo)
    {
        if (ihit.deleted)
            continue;

        if (targetGUID == ihit.targetGUID)                 // Found in list
        {
            if (!immuned)
                ihit.effectMask |= 1 << effIndex;          // Add only effect mask if not immuned
            return;
        }
    }

    if (targetType.GetObjectType() == TARGET_OBJECT_TYPE_UNIT_AND_DEST)
    {
        SpellDestination dest(*referer);
        if (m_spellInfo->HasAttribute(SPELL_ATTR4_USE_FACING_FROM_SPELL))
            dest._position.SetOrientation(spellEffectInfo.PositionFacing);

        CallScriptDestinationTargetSelectHandlers(dest, spellEffectInfo.EffectIndex, targetType);

        m_targets.ModDst(dest);
    }
    // This is new target calculate data for him

    CallScriptObjectAreaTargetSelectHandlers(targets, spellEffectInfo.EffectIndex, targetType);
    // Get spell hit result on target
    TargetInfo targetInfo;
    targetInfo.targetGUID = targetGUID;                         // Store target GUID
    targetInfo.effectMask = immuned ? 0 : 1 << effIndex;        // Store index of effect if not immuned
    targetInfo.processed  = false;                              // Effects not apply on target
    targetInfo.deleted = false;
    targetInfo.HitInfo = 0x0;
    targetInfo.damage = 0;

    if (targetType.GetTarget() == TARGET_UNIT_SRC_AREA_FURTHEST_ENEMY)
        targets.sort(Trinity::ObjectDistanceOrderPred(referer, false));
    // Calculate hit result
    targetInfo.missCondition = m_caster->SpellHitResult(pTarget, m_spellInfo, effIndex, m_canReflect, this);

    // spell fly from visual cast object
    SpellCaster* affectiveObject = GetAffectiveCasterObject();

    // Spell have speed - need calculate incoming time
    if (m_spellInfo->speed > 0.0f && affectiveObject && pTarget != affectiveObject)
    {
        // Other special target selection goes here
        if (uint32 maxTargets = m_spellValue->MaxAffectedTargets)
        {
            if (targetType.GetTarget() != TARGET_UNIT_SRC_AREA_FURTHEST_ENEMY)
                Trinity::Containers::RandomResize(targets, maxTargets);
            else if (targets.size() > maxTargets)
                targets.resize(maxTargets);
        }
        // calculate spell incoming interval
        float dist = affectiveObject->GetDistance3dToCenter(pTarget);
        if (dist < 5.0f)
            dist = 5.0f;
        targetInfo.timeDelay = (uint64) floor(dist / m_spellInfo->speed * 1000.0f);

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
        // Calculate minimum incoming time
        if (m_delayMoment == 0 || m_delayMoment > targetInfo.timeDelay)
            m_delayMoment = targetInfo.timeDelay;
    }
    else if (m_delayed)
        m_delayMoment = targetInfo.timeDelay = GetSpellBatchingEffectDelay(pTarget);
    else
        targetInfo.timeDelay = uint64(0);

    // If target reflect spell back to caster
    if (targetInfo.missCondition == SPELL_MISS_REFLECT)
    {
        // Calculate reflected spell result on caster
        targetInfo.reflectResult = m_casterUnit ? m_casterUnit->SpellHitResult(m_casterUnit, m_spellInfo, effIndex, m_canReflect, this) : SPELL_MISS_IMMUNE;

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

void Spell::AddUnitTarget(ObjectGuid unitGuid, SpellEffectIndex effIndex)
{
    if (Unit* unit = m_caster->GetObjectGuid() == unitGuid ? m_casterUnit : ObjectAccessor::GetUnit(*m_caster, unitGuid))
        AddUnitTarget(unit, effIndex);
}

void Spell::SelectImplicitCasterDestTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType)
void Spell::CheckAtDelay(TargetInfo* pInf)
{
    Unit* pTarget = m_caster->GetObjectGuid() == pInf->targetGUID ? m_casterUnit : ObjectAccessor::GetUnit(*m_caster, pInf->targetGUID);
    if (!pTarget)
        return;

    for (int i = 0; i < 3; ++i)
    {
        case TARGET_DEST_CASTER:
            break;
        case TARGET_DEST_HOME:
            if (Player* playerCaster = m_caster->ToPlayer())
                dest = SpellDestination(playerCaster->m_homebind);
            break;
        case TARGET_DEST_DB:
            if (SpellTargetPosition const* st = sSpellMgr->GetSpellTargetPosition(m_spellInfo->Id, spellEffectInfo.EffectIndex))
            {
                /// @todo fix this check
                if (m_spellInfo->HasEffect(SPELL_EFFECT_TELEPORT_UNITS) || m_spellInfo->HasEffect(SPELL_EFFECT_TELEPORT_WITH_SPELL_VISUAL_KIT_LOADING_SCREEN) || m_spellInfo->HasEffect(SPELL_EFFECT_BIND))
                    dest = SpellDestination(st->target_X, st->target_Y, st->target_Z, st->target_Orientation, (int32)st->target_mapId);
                else if (st->target_mapId == m_caster->GetMapId())
                    dest = SpellDestination(st->target_X, st->target_Y, st->target_Z, st->target_Orientation);
            }
            else
            {
                TC_LOG_DEBUG("spells", "SPELL: unknown target coordinates for spell ID {}", m_spellInfo->Id);
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
        uint32 effMask = 1 << i;
        if (pInf->effectMask & effMask)
        {
            if (pTarget->IsImmuneToSpellEffect(m_spellInfo, SpellEffectIndex(i), pTarget == m_caster))
                pInf->effectMask &= ~effMask;
        }
    }

    if (pTarget != m_caster &&
       ((!m_spellInfo->IsPositiveSpell(m_caster, pTarget) &&
         pTarget->IsImmuneToDamage(m_spellInfo->GetSpellSchoolMask(), m_spellInfo)) ||
         pTarget->IsImmuneToSpell(m_spellInfo, pTarget == m_caster)))
        pInf->missCondition = SPELL_MISS_IMMUNE;

    if (pTarget->IsCreature() && ((Creature*)pTarget)->IsInEvadeMode())
        pInf->missCondition = SPELL_MISS_EVADE;
}

void Spell::AddGOTarget(GameObject* pTarget, SpellEffectIndex effIndex)
{
    if (m_spellInfo->Effect[effIndex] == 0)
        return;

            float ground = m_caster->GetMapHeight(x, y, z);
            float liquidLevel = VMAP_INVALID_HEIGHT_VALUE;
            LiquidData liquidData;
            if (m_caster->GetMap()->GetLiquidStatus(m_caster->GetPhaseShift(), x, y, z, map_liquidHeaderTypeFlags::AllLiquids, &liquidData, m_caster->GetCollisionHeight()))
                liquidLevel = liquidData.level;
    ObjectGuid targetGUID = pTarget->GetObjectGuid();

    // Lookup target in already in list
    for (auto& ihit : m_UniqueGOTargetInfo)
    {
        if (ihit.deleted)
            continue;

        if (targetGUID == ihit.targetGUID)                 // Found in list
        {
            ihit.effectMask |= (1 << effIndex);            // Add only effect mask
            return;
        }
    }

    // This is new target calculate data for him

    GOTargetInfo targetInfo;
    targetInfo.targetGUID = targetGUID;
    targetInfo.effectMask = (1 << effIndex);
    targetInfo.processed  = false;                              // Effects not apply on target
    targetInfo.deleted    = false;

    // spell fly from visual cast object
    SpellCaster* affectiveObject = GetAffectiveCasterObject();

    // Spell have speed - need calculate incoming time
    if (m_spellInfo->speed > 0.0f && affectiveObject && pTarget != affectiveObject)
    {
        // calculate spell incoming interval
        float dist = affectiveObject->GetDistance3dToCenter(pTarget);
        if (dist < 5.0f)
            dist = 5.0f;
        targetInfo.timeDelay = (uint64) floor(dist / m_spellInfo->speed * 1000.0f);
        if (m_delayMoment == 0 || m_delayMoment > targetInfo.timeDelay)
            m_delayMoment = targetInfo.timeDelay;
    }
    else if (m_delayed)
        m_delayMoment = targetInfo.timeDelay = GetSpellBatchingEffectDelay(pTarget);
    else
        targetInfo.timeDelay = uint64(0);

            dest = SpellDestination(x, y, liquidLevel, m_caster->GetOrientation());
            break;
        }
        case TARGET_DEST_CASTER_FRONT_LEAP:
        case TARGET_DEST_CASTER_MOVEMENT_DIRECTION:
        {
            Unit* unitCaster = m_caster->ToUnit();
            if (!unitCaster)
                break;

            float dist = spellEffectInfo.CalcRadius(unitCaster);
            float angle = targetType.CalcDirectionAngle();
            if (targetType.GetTarget() == TARGET_DEST_CASTER_MOVEMENT_DIRECTION)
            {
                angle = [&]()
                {
                    switch (m_caster->m_movementInfo.GetMovementFlags() & (MOVEMENTFLAG_FORWARD | MOVEMENTFLAG_BACKWARD | MOVEMENTFLAG_STRAFE_LEFT | MOVEMENTFLAG_STRAFE_RIGHT))
                    {
                        case MOVEMENTFLAG_NONE:
                        case MOVEMENTFLAG_FORWARD:
                        case MOVEMENTFLAG_FORWARD | MOVEMENTFLAG_BACKWARD:
                        case MOVEMENTFLAG_STRAFE_LEFT | MOVEMENTFLAG_STRAFE_RIGHT:
                        case MOVEMENTFLAG_FORWARD | MOVEMENTFLAG_STRAFE_LEFT | MOVEMENTFLAG_STRAFE_RIGHT:
                        case MOVEMENTFLAG_FORWARD | MOVEMENTFLAG_BACKWARD | MOVEMENTFLAG_STRAFE_LEFT | MOVEMENTFLAG_STRAFE_RIGHT:
                            return 0.0f;
                        case MOVEMENTFLAG_BACKWARD:
                        case MOVEMENTFLAG_BACKWARD | MOVEMENTFLAG_STRAFE_LEFT | MOVEMENTFLAG_STRAFE_RIGHT:
                            return static_cast<float>(M_PI);
                        case MOVEMENTFLAG_STRAFE_LEFT:
                        case MOVEMENTFLAG_FORWARD | MOVEMENTFLAG_BACKWARD | MOVEMENTFLAG_STRAFE_LEFT:
                            return static_cast<float>(M_PI / 2);
                        case MOVEMENTFLAG_FORWARD | MOVEMENTFLAG_STRAFE_LEFT:
                            return static_cast<float>(M_PI / 4);
                        case MOVEMENTFLAG_BACKWARD | MOVEMENTFLAG_STRAFE_LEFT:
                            return static_cast<float>(3 * M_PI / 4);
                        case MOVEMENTFLAG_STRAFE_RIGHT:
                        case MOVEMENTFLAG_FORWARD | MOVEMENTFLAG_BACKWARD |  MOVEMENTFLAG_STRAFE_RIGHT:
                            return static_cast<float>(-M_PI / 2);
                        case MOVEMENTFLAG_FORWARD | MOVEMENTFLAG_STRAFE_RIGHT:
                            return static_cast<float>(-M_PI / 4);
                        case MOVEMENTFLAG_BACKWARD | MOVEMENTFLAG_STRAFE_RIGHT:
                            return static_cast<float>(-3 * M_PI / 4);
                        default:
                            return 0.0f;
                    }
                }();
            }

            Position pos = dest._position;

            unitCaster->MovePositionToFirstCollision(pos, dist, angle);
            dest.Relocate(pos);
            break;
        }
        case TARGET_DEST_CASTER_GROUND:
        case TARGET_DEST_CASTER_GROUND_2:
            dest._position.m_positionZ = m_caster->GetMapWaterOrGroundLevel(dest._position.GetPositionX(), dest._position.GetPositionY(), dest._position.GetPositionZ());
            break;
        case TARGET_DEST_SUMMONER:
            if (Unit const* unitCaster = m_caster->ToUnit())
                if (TempSummon const* casterSummon = unitCaster->ToTempSummon())
                    if (WorldObject const* summoner = casterSummon->GetSummoner())
                        dest = SpellDestination(*summoner);
            break;
        default:
        {
            float dist = spellEffectInfo.CalcRadius(m_caster);
            float angle = targetType.CalcDirectionAngle();
            float objSize = m_caster->GetCombatReach();
    // Add target to list
    m_UniqueGOTargetInfo.push_back(targetInfo);
}

void Spell::AddGOTarget(ObjectGuid goGuid, SpellEffectIndex effIndex)
{
    if (GameObject* go = m_caster->GetMap()->GetGameObject(goGuid))
        AddGOTarget(go, effIndex);
}

void Spell::AddItemTarget(Item* pitem, SpellEffectIndex effIndex)
{
    if (m_spellInfo->Effect[effIndex] == 0)
        return;

            switch (targetType.GetTarget())
            {
                case TARGET_DEST_CASTER_SUMMON:
                    dist = PET_FOLLOW_DIST;
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
                    if (!spellEffectInfo.HasRadius() && !spellEffectInfo.HasMaxRadius())
                        dist = DefaultTotemDistance;
                    break;
                }
                default:
                    break;
            }
    // Lookup target in already in list
    for (auto& ihit : m_UniqueItemInfo)
    {
        if (pitem == ihit.item)                            // Found in list
        {
            ihit.effectMask |= (1 << effIndex);            // Add only effect mask
            return;
        }
    }

            if (dist < objSize)
                dist = objSize;
    // This is new target add data

            Position pos = dest._position;
            m_caster->MovePositionToFirstCollision(pos, dist, angle);
    ItemTargetInfo target;
    target.item       = pitem;
    target.effectMask = (1 << effIndex);
    target.deleted    = false;

            dest.Relocate(pos);
            break;
    m_UniqueItemInfo.push_back(target);
}

void Spell::DoAllEffectOnTarget(TargetInfo *target)
{
    ASSERT(target);

    // Arrive pour des sorts comme 11567, 20569, 10626
    if (target->processed)
        return;

    ASSERT(m_caster);

    target->processed = true;                               // Target checked in apply effects procedure

    // Get mask of effects for target
    uint32 mask = target->effectMask;

    Unit* unit = m_caster->GetObjectGuid() == target->targetGUID ? m_casterUnit : ObjectAccessor::GetUnit(*m_caster, target->targetGUID);
    if (!unit)
        return;

    if (getState() == SPELL_STATE_DELAYED && (WorldTimer::getMSTime() - target->timeDelay) <= unit->m_lastSanctuaryTime && !m_spellInfo->IsPositiveSpell())
        return;

    // Get original caster (if exist) and calculate damage/healing from him data
    SpellCaster* pRealCaster = GetAffectiveCasterObject();
    SpellCaster* pCaster = pRealCaster ? pRealCaster : m_caster;
    Unit* pUnitCaster = pCaster->ToUnit();
    Unit* pRealUnitCaster = ToUnit(pRealCaster);

    SpellMissInfo missInfo = target->missCondition;
    // Need init unitTarget by default unit (can changed in code on reflect)
    // Or on missInfo!=SPELL_MISS_NONE unitTarget undefined (but need in trigger subsystem)
    unitTarget = unit;
    m_spellAuraHolder = nullptr;

    // Reset damage/healing counter
    ResetEffectDamageAndHeal();

    // Fill base trigger info. If this is hitting multiple targets, attacker procs should
    // only apply on the first target aside from some special cases.
    uint32 procAttacker = m_procAttacker;
    uint32 procVictim   = m_procVictim;
    uint32 procEx       = PROC_EX_NONE;
    
    // Drop some attacker proc flags if this is a secondary target. Do not need to change
    // the victim proc flags.
    if (m_targetNum > 1) {
        // If this is a melee spell hit, strip the flag and apply a spell hit flag instead.
        // This is required to proc things like Deep Wounds on the victim when hitting 
        // multiple targets, but not proc additional melee-only beneficial auras on the 
        // attacker like Sweeping Strikes. Leave the victim proc flags responding to a melee
        // spell.
        if (procAttacker & PROC_FLAG_SUCCESSFUL_MELEE_SPELL_HIT) {
            procAttacker &= ~(PROC_FLAG_SUCCESSFUL_MELEE_SPELL_HIT);
            procAttacker |= PROC_FLAG_SUCCESSFUL_NEGATIVE_SPELL_HIT;
        }
        else if (procAttacker & (PROC_FLAG_SUCCESSFUL_SPELL_CAST | PROC_FLAG_SUCCESSFUL_MANA_SPELL_CAST)) {
            // Secondary target on a successful spell cast. Remove these flags so we're not
            // proccing beneficial auras multiple times. Also remove negative spell hit for
            // chain lightning + clearcasting. Leave positive effects
            // eg. Chain heal/lightning & Zandalarian Hero Charm
            procAttacker &= ~(PROC_FLAG_SUCCESSFUL_SPELL_CAST | PROC_FLAG_SUCCESSFUL_MANA_SPELL_CAST | 
                              PROC_FLAG_SUCCESSFUL_NEGATIVE_SPELL_HIT);
        }
        else if (procAttacker & (PROC_FLAG_SUCCESSFUL_AOE | PROC_FLAG_SUCCESSFUL_NEGATIVE_SPELL_HIT)) {
            // Do not allow secondary hits for negative aoe spells (such as Arcane Explosion) 
            // to proc beneficial abilities such as Clearcasting. Positive aoe spells can
            // still trigger, as in the case of prayer of healing and inspiration...
            procAttacker &= ~(PROC_FLAG_SUCCESSFUL_AOE | PROC_FLAG_SUCCESSFUL_NEGATIVE_SPELL_HIT);
        }
    }

    if (m_spellInfo->HasAttribute(SPELL_ATTR4_USE_FACING_FROM_SPELL))
        dest._position.SetOrientation(spellEffectInfo.PositionFacing);

    CallScriptDestinationTargetSelectHandlers(dest, spellEffectInfo.EffectIndex, targetType);
    m_targets.SetDst(dest);
}
    // drop proc flags in case target not affected negative effects in negative spell
    // for example caster bonus or animation,
    // except miss case where will assigned PROC_EX_* flags later
    if (((procAttacker | procVictim) & NEGATIVE_TRIGGER_MASK) &&
            !(target->effectMask & m_negativeEffectMask) && (missInfo == SPELL_MISS_NONE || missInfo == SPELL_MISS_REFLECT))
    {
        procAttacker = procAttacker & PROC_FLAG_SUCCESSFUL_SPELL_CAST;
        procVictim   = PROC_FLAG_NONE;
    }

void Spell::SelectImplicitTargetDestTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType)
{
    ASSERT(m_targets.GetObjectTarget() && "Spell::SelectImplicitTargetDestTargets - no explicit object target available!");
    WorldObject* target = m_targets.GetObjectTarget();
    if (m_delayed)
    {
        // mark effects that were already handled in Spell::HandleDelayedSpellLaunch on spell launch as processed
        for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
            if (m_spellInfo->IsEffectHandledOnDelayedSpellLaunch(SpellEffectIndex(i)))
                mask &= ~(1 << i);

        // maybe used in effects that are handled on hit
        m_damage += target->damage;
    }

    if (missInfo == SPELL_MISS_NONE)                        // In case spell hit target, do all effect on that target
        DoSpellHitOnUnit(unit, mask);
    if (missInfo == SPELL_MISS_REFLECT && target->reflectResult == SPELL_MISS_NONE)
    {
        if (m_casterUnit)
        {
            float angle = targetType.CalcDirectionAngle();
            float dist = spellEffectInfo.CalcRadius(nullptr);
            if (targetType.GetTarget() == TARGET_DEST_TARGET_RANDOM)
                dist *= float(rand_norm());
            isReflected = true;
            DoSpellHitOnUnit(m_casterUnit, mask);
            unitTarget = m_casterUnit;
        }
    }
    else                                                    // in 1.12.1 we need explicit miss info
    {
        if (missInfo == SPELL_MISS_MISS || missInfo == SPELL_MISS_RESIST)
        {
            if (pRealUnitCaster && pRealUnitCaster != unit)
            {
                if (!m_spellInfo->IsPositiveSpell() && (m_caster->IsVisibleForOrDetect(unit, unit, false) || m_spellInfo->HasAttribute(SPELL_ATTR_EX_IS_PICKPOCKET)))
                {
                    bool combat = (m_spellInfo->Id != 3600) && !m_spellInfo->HasAttribute(SPELL_ATTR_EX3_NO_INITIAL_AGGRO);

            Position pos = dest._position;
            target->MovePositionToFirstCollision(pos, dist, angle);
                    // Pickpocket can cause back attack if failed
                    if (m_spellInfo->HasAttribute(SPELL_ATTR_EX_IS_PICKPOCKET))
                    {
                        pRealUnitCaster->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);
                        combat = true;
                    }

            dest.Relocate(pos);
            break;
        }
    }

    if (m_spellInfo->HasAttribute(SPELL_ATTR4_USE_FACING_FROM_SPELL))
        dest._position.SetOrientation(spellEffectInfo.PositionFacing);

    CallScriptDestinationTargetSelectHandlers(dest, spellEffectInfo.EffectIndex, targetType);
    m_targets.SetDst(dest);
}
                    if (combat)
                    {
                        if (!m_spellInfo->HasAura(SPELL_AURA_MOD_POSSESS))
                        {
                            if (!unit->IsInCombat())
                                unit->AttackedBy(pRealUnitCaster);

                            unit->AddThreat(pRealUnitCaster);
                            unit->SetInCombatWithAggressor(pRealUnitCaster);
                        }
                        
                        pRealUnitCaster->SetInCombatWithVictim(unit);
                    }
                    else if (m_spellInfo->HasAttribute(SPELL_ATTR_EX3_OUT_OF_COMBAT_ATTACK))
                    {
                        unit->SetOutOfCombatWithAggressor(pRealUnitCaster);
                        pRealUnitCaster->SetOutOfCombatWithVictim(unit);
                    }
                }
            }
        }
    }

void Spell::SelectImplicitDestDestTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType)
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
        case TARGET_DEST_DEST_GROUND:
            dest._position.m_positionZ = m_caster->GetMapHeight(dest._position.GetPositionX(), dest._position.GetPositionY(), dest._position.GetPositionZ());
            break;
        default:
        {
            float angle = targetType.CalcDirectionAngle();
            float dist = spellEffectInfo.CalcRadius(m_caster);
            if (targetType.GetTarget() == TARGET_DEST_DEST_RANDOM)
                dist *= float(rand_norm());

            Position pos = dest._position;
            m_caster->MovePositionToFirstCollision(pos, dist, angle);

            dest.Relocate(pos);
            break;
    if (pRealUnitCaster)
    {
        if (m_spellInfo->AttributesEx & SPELL_ATTR_EX_REFUND_POWER)
        {
            // Restauration d'energie sur miss/dodge des sorts rapportant un CP.
            // Source : http://roguecrap.blogspot.co.uk/2006/03/energy-regeneration-oddities.html, + verifiable en video
            // Source for Parry: https://youtu.be/aDXXr3ad3is?t=3m07s
            if ((missInfo == SPELL_MISS_MISS || missInfo == SPELL_MISS_DODGE || missInfo == SPELL_MISS_PARRY) && m_spellInfo->powerType == POWER_ENERGY)
            {
                int32 regen = lroundf(m_powerCost * 0.82f);
                pRealUnitCaster->ModifyPower(POWER_ENERGY, regen);
            }
            // Warriors and Druids are refunded 80% of the rage cost on dodge/parry
            // http://blue.mmo-champion.com/topic/69365-18-02-05-kalgans-response-to-warriors/
            // https://youtu.be/YzPlictRoK8?t=1m45s
            else if ((missInfo == SPELL_MISS_PARRY || missInfo == SPELL_MISS_DODGE) && m_spellInfo->powerType == POWER_RAGE)
            {
                int32 regen = lroundf(m_powerCost * 0.82f);
                pRealUnitCaster->ModifyPower(POWER_RAGE, regen);
            }
        }
    }

    if (m_spellInfo->HasAttribute(SPELL_ATTR4_USE_FACING_FROM_SPELL))
        dest._position.SetOrientation(spellEffectInfo.PositionFacing);

    CallScriptDestinationTargetSelectHandlers(dest, spellEffectInfo.EffectIndex, targetType);
    m_targets.ModDst(dest);
}
    // All calculated do it!
    // Do healing and triggers
    if (m_healing)
    {
        bool crit = pRealCaster && pRealCaster->IsSpellCrit(unitTarget, m_spellInfo, m_spellSchoolMask, BASE_ATTACK, this);
        uint32 addhealth = ditheru(m_healing);
        if (crit)
        {
            procEx |= PROC_EX_CRITICAL_HIT;
            addhealth = ditheru(pCaster->SpellCriticalHealingBonus(m_spellInfo, m_healing, nullptr));

void Spell::SelectImplicitCasterObjectTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType)
{
    WorldObject* target = nullptr;
    bool checkIfValid = true;
#if SUPPORTED_CLIENT_BUILD <= CLIENT_BUILD_1_9_4
            // If healing crits, we need to update the execute log data.
            for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
            {
                if (m_executeLogInfo[i].empty())
                    continue;

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
                    target = unitCaster->ToTempSummon()->GetSummonerUnit();
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
                if (!creatureCaster->GetTapList().empty())
                    target = ObjectAccessor::GetWorldObject(*creatureCaster, Trinity::Containers::SelectRandomContainerElement(creatureCaster->GetTapList()));
            break;
        case TARGET_UNIT_OWN_CRITTER:
            if (Unit const* unitCaster = m_caster->ToUnit())
                target = ObjectAccessor::GetCreatureOrPetOrVehicle(*m_caster, unitCaster->GetCritterGUID());
            break;
        default:
            break;
    }

    CallScriptObjectTargetSelectHandlers(target, spellEffectInfo.EffectIndex, targetType);

    if (target)
    {
        if (Unit* unit = target->ToUnit())
            AddUnitTarget(unit, 1 << spellEffectInfo.EffectIndex, checkIfValid);
        else if (GameObject* go = target->ToGameObject())
            AddGOTarget(go, 1 << spellEffectInfo.EffectIndex);
        else if (Corpse* corpse = target->ToCorpse())
            AddCorpseTarget(corpse, 1 << spellEffectInfo.EffectIndex);
    }
}
                for (uint32 j = 0; j < m_executeLogInfo[i].size(); ++j)
                {
                    switch (m_spellInfo->Effect[i])
                    {
                        case SPELL_EFFECT_HEAL:
                        case SPELL_EFFECT_HEAL_MAX_HEALTH:
                        {
                            m_executeLogInfo[i][j].heal.amount = addhealth;
                            m_executeLogInfo[i][j].heal.critical = 1;
                            break;
                        }
                    }
                }
            }
#endif
        }
        else
            procEx |= PROC_EX_NORMAL_HIT;

void Spell::SelectImplicitTargetObjectTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType)
{
    ASSERT((m_targets.GetObjectTarget() || m_targets.GetItemTarget()) && "Spell::SelectImplicitTargetObjectTargets - no explicit object or item target available!");
        // Do triggers for unit (reflect triggers passed on hit phase for correct drop charge)
        if (m_canTrigger)
        {
            // Some spell expected send main spell info to triggered system
            SpellEntry const* spellInfo = m_spellInfo;
            switch (m_spellInfo->Id)
            {
                //case 19968:                                 // Holy Light triggered heal
                case 19993:                                 // Flash of Light triggered heal
                {
                    // stored in unused spell effect basepoints in main spell code
                    uint32 spellid = m_currentBasePoints[EFFECT_INDEX_1];
                    spellInfo = sSpellMgr.GetSpellEntry(spellid);
                    procAttacker |= (PROC_FLAG_SUCCESSFUL_SPELL_CAST | PROC_FLAG_SUCCESSFUL_MANA_SPELL_CAST);
                }
            }

            pCaster->ProcDamageAndSpell(ProcSystemArguments(unitTarget, pRealCaster ? procAttacker : PROC_FLAG_NONE, procVictim, procEx, addhealth, m_attackType, spellInfo, this));
        }

    CallScriptObjectTargetSelectHandlers(target, spellEffectInfo.EffectIndex, targetType);
        int32 gain = pCaster->DealHeal(unitTarget, addhealth, m_spellInfo, crit);

    if (target)
    {
        if (Unit* unit = target->ToUnit())
            AddUnitTarget(unit, 1 << spellEffectInfo.EffectIndex, true, false);
        else if (GameObject* gobj = target->ToGameObject())
            AddGOTarget(gobj, 1 << spellEffectInfo.EffectIndex);
        else if (Corpse* corpse = target->ToCorpse())
            AddCorpseTarget(corpse, 1 << spellEffectInfo.EffectIndex);
        float classThreatModifier = pUnitCaster && pUnitCaster->GetClass() == CLASS_PALADIN ? 0.25f : 0.5f;

        SelectImplicitChainTargets(spellEffectInfo, targetType, target, 1 << spellEffectInfo.EffectIndex);
        if (pRealUnitCaster)
            unitTarget->GetHostileRefManager().threatAssist(pRealUnitCaster, float(gain) * classThreatModifier * sSpellMgr.GetSpellThreatMultiplier(m_spellInfo), m_spellInfo);
    }
    // Script hook can remove object target and we would wrongly land here
    else if (Item* item = m_targets.GetItemTarget())
        AddItemTarget(item, 1 << spellEffectInfo.EffectIndex);
}

void Spell::SelectImplicitChainTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, WorldObject* target, uint32 effMask)
{
    int32 maxTargets = spellEffectInfo.ChainTargets;
    if (Player* modOwner = m_caster->GetSpellModOwner())
        modOwner->ApplySpellMod(m_spellInfo, SpellModOp::ChainTargets, maxTargets, this);
    // Do damage and triggers
    else if (m_damage && unitTarget->IsAlive())
    {
        // Fill base damage struct (unitTarget - is real spell target)
        SpellNonMeleeDamage damageInfo(pCaster, unitTarget, m_spellInfo->Id, GetFirstSchoolInMask(m_spellSchoolMask));
        damageInfo.spell = this;

        // World of Warcraft Client Patch 1.11.0 (2006-06-20)
        // - Fear: The calculations to determine if Fear effects should break due 
        //   to receiving damage have been changed.The old calculation used the
        //   base damage of the ability.The new calculation uses the final amount
        //   of damage dealt, after all modifiers.
#if SUPPORTED_CLIENT_BUILD <= CLIENT_BUILD_1_10_2
        // Has to be called from here instead of Unit::DealDamage to calculate with base damage.
        if ((damage > 0) && unitTarget && !(m_caster->IsCreature() && static_cast<Creature*>(m_caster)->IsWorldBoss()))
            unitTarget->RemoveFearEffectsByDamageTaken(damage, m_spellInfo->Id, SPELL_DIRECT_DAMAGE);
#endif

    if (maxTargets > 1)
    {
        // mark damage multipliers as used
        for (size_t k = spellEffectInfo.EffectIndex; k < m_spellInfo->GetEffects().size(); ++k)
            if (effMask & (1 << k))
                m_damageMultipliers[k] = 1.0f;
        m_applyMultiplierMask |= effMask;
        if (m_delayed)
        {
            damageInfo.damage = m_damage;
            damageInfo.HitInfo = target->HitInfo;
        }
        // Add bonuses and fill damageInfo struct
        else
        {
            // we need index of damage dealing effect for CalculateSpellDamage to use right bonus coefficient
            SpellEffectIndex damageEffectIndex = EFFECT_INDEX_0;

        std::list<WorldObject*> targets;
        SearchChainTargets(targets, maxTargets - 1, target, targetType.GetObjectType(), targetType.GetCheckType()
            , spellEffectInfo, targetType.GetTarget() == TARGET_UNIT_TARGET_CHAINHEAL_ALLY);

        // Chain primary target is added earlier
        CallScriptObjectAreaTargetSelectHandlers(targets, spellEffectInfo.EffectIndex, targetType);

        Position const* losPosition = m_spellInfo->HasAttribute(SPELL_ATTR2_CHAIN_FROM_CASTER) ? m_caster : target;

        for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
        {
            if (Unit* unit = (*itr)->ToUnit())
                AddUnitTarget(unit, effMask, false, true, losPosition);

            if (!m_spellInfo->HasAttribute(SPELL_ATTR2_CHAIN_FROM_CASTER) && !spellEffectInfo.EffectAttributes.HasFlag(SpellEffectAttributes::ChainFromInitialTarget))
                losPosition = *itr;
        }
    }
}
            for (uint8 effectNumber = 0; effectNumber < MAX_EFFECT_INDEX; ++effectNumber)
            {
                if ((mask & (1 << effectNumber)) &&
                    IsDirectDamageWithBonusEffect(m_spellInfo->Effect[effectNumber]))
                {
                    damageEffectIndex = SpellEffectIndex(effectNumber);
                    break;
                }
            }

            pCaster->CalculateSpellDamage(&damageInfo, m_damage, m_spellInfo, damageEffectIndex, m_attackType, this);
        }

void Spell::SelectImplicitTrajTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType)
{
    if (!m_targets.HasTraj())
        return;

    float dist2d = m_targets.GetDist2d();
    if (!dist2d)
        return;
        unitTarget->CalculateAbsorbResistBlock(pCaster, &damageInfo, m_spellInfo, BASE_ATTACK, this);
        m_absorbed = damageInfo.absorb;

    Position srcPos = *m_targets.GetSrcPos();
    srcPos.SetOrientation(m_caster->GetOrientation());
    float srcToDestDelta = m_targets.GetDstPos()->m_positionZ - srcPos.m_positionZ;

    std::list<WorldObject*> targets;
    Trinity::WorldObjectSpellTrajTargetCheck check(dist2d, &srcPos, m_caster, m_spellInfo, targetType.GetCheckType(), spellEffectInfo.ImplicitTargetConditions, TARGET_OBJECT_TYPE_NONE);
    Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellTrajTargetCheck> searcher(m_caster, targets, check, GRID_MAP_TYPE_MASK_ALL);
    SearchTargets<Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellTrajTargetCheck> > (searcher, GRID_MAP_TYPE_MASK_ALL, m_caster, &srcPos, dist2d);
    if (targets.empty())
        return;
        pCaster->DealDamageMods(damageInfo.target, damageInfo.damage, &damageInfo.absorb);
        
        // terribly ugly hack for Gluth Decimate to not be affected by any damage modifiers.
        // SPELL_ATTR_EX3_UNK29 is probably meant to make the spell ignore any damage modifiers,
        // but until implemented, this is the best we can do.
        if (m_spellInfo->Id == 28375)
        {
            damageInfo.damage = m_damage;
        }

        // Send log damage message to client
        pCaster->SendSpellNonMeleeDamageLog(&damageInfo);

    float b = tangent(m_targets.GetPitch());
    float a = (srcToDestDelta - dist2d * b) / (dist2d * dist2d);
    if (a > -0.0001f)
        a = 0.f;
        procEx = createProcExtendMask(&damageInfo, missInfo);
        procVictim |= PROC_FLAG_TAKEN_ANY_DAMAGE;

    // We should check if triggered spell has greater range (which is true in many cases, and initial spell has too short max range)
    // limit max range to 300 yards, sometimes triggered spells can have 50000yds
    float bestDist = m_spellInfo->GetMaxRange(false);
    if (SpellInfo const* triggerSpellInfo = sSpellMgr->GetSpellInfo(spellEffectInfo.TriggerSpell, GetCastDifficulty()))
        bestDist = std::min(std::max(bestDist, triggerSpellInfo->GetMaxRange(false)), std::min(dist2d, 300.0f));

    // GameObjects don't cast traj
    Unit* unitCaster = ASSERT_NOTNULL(m_caster->ToUnit());
    for (auto itr = targets.begin(); itr != targets.end(); ++itr)
    {
        if (m_spellInfo->CheckTarget(unitCaster, *itr, true) != SPELL_CAST_OK)
            continue;
        // (HACK) trigger Vengeance on weapon crits for Paladins
        // item procs should probably trigger for all classes, e.g. Judgement of Wisdom, but many issues to test for first. Paladin exclusive for now.
        if (m_CastItem && m_casterUnit && m_casterUnit->GetClass() == CLASS_PALADIN && (procEx & PROC_EX_CRITICAL_HIT) && !(m_spellInfo->AttributesEx3 & SPELL_ATTR_EX3_CANT_TRIGGER_PROC))
            m_canTrigger = true;
        // JoR and JoC: Paladin melee spells trigger melee procs instead of magic
        if ((m_spellInfo->IsFitToFamilyMask<CF_PALADIN_JUDGEMENT_OF_RIGHTEOUSNESS>() && m_spellInfo->SpellIconID == 25) || 
            (m_spellInfo->SpellFamilyName == SPELLFAMILY_PALADIN && m_spellInfo->SpellIconID == 561 && m_spellInfo->SpellVisual == 0))
        {
            procAttacker = PROC_FLAG_SUCCESSFUL_MELEE_SPELL_HIT;
            procVictim = PROC_FLAG_TAKEN_MELEE_SPELL_HIT | PROC_FLAG_TAKEN_ANY_DAMAGE;
        }
        // Do triggers for unit (reflect triggers passed on hit phase for correct drop charge)
        if (m_canTrigger)
            pCaster->ProcDamageAndSpell(ProcSystemArguments(unitTarget, pRealCaster ? procAttacker : PROC_FLAG_NONE, procVictim, procEx, damageInfo.damage, m_attackType, m_spellInfo, this));
        
        if (m_caster->IsPlayer())
        {
            // trigger weapon enchants for weapon based spells; exclude spells that stop attack, because may break CC
            if (m_spellInfo->EquippedItemClass == ITEM_CLASS_WEAPON && !(m_spellInfo->Attributes & SPELL_ATTR_STOP_ATTACK_TARGET))
                ((Player*)m_caster)->CastItemCombatSpell(unitTarget, m_attackType);

            // trigger mainhand weapon procs for shield attacks (Shield Bash, Shield Slam) NOTE: vanilla only mechanic, patched out in 2.0.1
            else if (m_spellInfo->EquippedItemClass == ITEM_CLASS_ARMOR && m_spellInfo->EquippedItemSubClassMask & (1 << ITEM_SUBCLASS_ARMOR_SHIELD)
                && (m_spellInfo->SpellIconID == 280 || m_spellInfo->SpellIconID == 413))
                ((Player*)m_caster)->CastItemCombatSpell(unitTarget, BASE_ATTACK);

        if (Unit* unit = (*itr)->ToUnit())
        {
            if (unitCaster == *itr || unitCaster->IsOnVehicle(unit) || unit->GetVehicle())
                continue;
            // Bloodthirt triggers main hand despite not requiring weapon
            // Execute damage component triggers main hand
            else if ((m_spellInfo->SpellIconID == 38 && m_spellInfo->SpellVisual == 372) || //bloodthirst
                    m_spellInfo->Id == 20647) //execute (damage dealing component does not require weapon)
            {
                 ((Player*)m_caster)->CastItemCombatSpell(unitTarget, BASE_ATTACK);
            }

            // special Paladin cases - trigger weapon procs despite not having EquippedItemClass
            else if (m_spellInfo->SpellFamilyName == SPELLFAMILY_PALADIN)
            {
                if (!(creatureTarget->GetCreatureTemplate()->type_flags & CREATURE_TYPE_FLAG_COLLIDE_WITH_MISSILES))
                    continue;
                // Seal of Command
                if (m_spellInfo->Id == 20424)
                    ((Player*)m_caster)->CastItemCombatSpell(unitTarget, BASE_ATTACK);
                // Judgement of Command
                else if (m_spellInfo->SpellIconID == 561)
                    ((Player*)m_caster)->CastItemCombatSpell(unitTarget, BASE_ATTACK);
                // Judgement of Righteousness
                else if (m_spellInfo->IsFitToFamilyMask<CF_PALADIN_JUDGEMENT_OF_RIGHTEOUSNESS>() && m_spellInfo->SpellIconID == 25)
                    ((Player*)m_caster)->CastItemCombatSpell(unitTarget, BASE_ATTACK);
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
        pCaster->DealSpellDamage(&damageInfo, true);

        // Courroux Naturel a 20% de chance de faire proc WF.
        if (m_spellInfo->Id == 17364 && pCaster->IsPlayer())
        {
            Player* pPlayer = pCaster->ToPlayer();
            Item *item = pPlayer->GetWeaponForAttack(BASE_ATTACK, true, true);
            if (item)
            {
                uint32 enchant_id = item->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT);
                SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
                if (pEnchant && roll_chance_f(20.0f))
                    if (SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(pEnchant->spellid[0]))
                        if (spellInfo->IsFitToFamily<SPELLFAMILY_SHAMAN, CF_SHAMAN_WINDFURY_WEAPON>())
                            pPlayer->CastSpell(unitTarget, pEnchant->spellid[0], true, item);
            }
        }
    }
    else if (m_canTrigger && (procAttacker || procVictim))
    {
        // TODO: Allow all procs, and explicitly deny some rather than denying all and
        // explicitly allowing some
        bool foundDamageOrHealAura = false;
        // m_spellAuraHolder is null for non-stacking periodic effects that are already
        // on the target - they simply refresh. However, they should still proc on
        // cast!
        if (m_spellInfo->IsSpellAppliesAura(target->effectMask))
        {
            for (int i = 0; i < MAX_EFFECT_INDEX && !foundDamageOrHealAura; ++i)
            {
                switch (m_spellInfo->EffectApplyAuraName[i])
                {
                    case SPELL_AURA_PERIODIC_DAMAGE:
                    case SPELL_AURA_PERIODIC_DAMAGE_PERCENT:
                    case SPELL_AURA_PERIODIC_LEECH:
                    case SPELL_AURA_PERIODIC_HEALTH_FUNNEL:
                    case SPELL_AURA_PERIODIC_HEAL:
                    case SPELL_AURA_OBS_MOD_HEALTH:
                    case SPELL_AURA_POWER_BURN_MANA:
                    case SPELL_AURA_SCHOOL_ABSORB:
                        foundDamageOrHealAura = true;
                        break;
                }
            }
        }
        // Sunder Armor triggers weapon proc as well as normal procs despite dealing no damage
        if (m_caster->IsPlayer() && m_spellInfo->IsFitToFamily<SPELLFAMILY_WARRIOR, CF_WARRIOR_SUNDER_ARMOR>() && missInfo == SPELL_MISS_NONE)
            ((Player*)m_caster)->CastItemCombatSpell(unitTarget, BASE_ATTACK);

        // Fill base damage struct (unitTarget - is real spell target)
        SpellNonMeleeDamage damageInfo(pCaster, unitTarget, m_spellInfo->Id, GetFirstSchoolInMask(m_spellSchoolMask));
        procEx = createProcExtendMask(&damageInfo, missInfo);
        // Do triggers for unit (reflect triggers passed on hit phase for correct drop charge)
        uint32 dmg = 0;
        // Sometime we need to manually set dmg != 0 (arcane projectile triggers a spell that deals damage)
        // Cant check SpellFamilyFlags & 0x40800 because some spells have strange SpellFamilyFlags=0x7FFFFFFF (sheep, ...)
        if (m_spellInfo->SpellFamilyName == SPELLFAMILY_MAGE && m_spellInfo->SpellFamilyFlags == 0x40800)
            dmg = 1;

        // Proc periodic casts now, so initial cast procs are triggered
        if (foundDamageOrHealAura)
            dmg = 1;

    if (dist2d > bestDist)
    {
        float x = m_targets.GetSrcPos()->m_positionX + std::cos(unitCaster->GetOrientation()) * bestDist;
        float y = m_targets.GetSrcPos()->m_positionY + std::sin(unitCaster->GetOrientation()) * bestDist;
        float z = m_targets.GetSrcPos()->m_positionZ + bestDist * (a * bestDist + b);
        // Proc for dispels (or "cures")
        if (m_spellInfo->IsDispel())
        {
            dmg = 1;
            // Override proc flags for offensive dispel
            if (pCaster->IsHostileTo(unitTarget))
            {
                procAttacker &= ~(PROC_FLAG_SUCCESSFUL_NONE_POSITIVE_SPELL | PROC_FLAG_SUCCESSFUL_CURE_SPELL_CAST);
                procAttacker |= PROC_FLAG_SUCCESSFUL_NEGATIVE_SPELL_HIT;

        SpellDestination dest(x, y, z, unitCaster->GetOrientation());
        if (m_spellInfo->HasAttribute(SPELL_ATTR4_USE_FACING_FROM_SPELL))
            dest._position.SetOrientation(spellEffectInfo.PositionFacing);

        CallScriptDestinationTargetSelectHandlers(dest, spellEffectInfo.EffectIndex, targetType);
        m_targets.ModDst(dest);
    }
}
                procVictim &= ~PROC_FLAG_TAKEN_NONE_POSITIVE_SPELL;
                procVictim |= PROC_FLAG_TAKEN_NEGATIVE_SPELL_HIT;
            }
        }

        pCaster->ProcDamageAndSpell(ProcSystemArguments(unitTarget, pRealCaster ? procAttacker : PROC_FLAG_NONE, procVictim, procEx, dmg, m_attackType, m_spellInfo, this));
    }

void Spell::SelectImplicitLineTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, uint32 effMask)
{
    std::list<WorldObject*> targets;
    SpellTargetObjectTypes objectType = targetType.GetObjectType();
    SpellTargetCheckTypes selectionType = targetType.GetCheckType();
    Position const* dst = nullptr;
    switch (targetType.GetReferenceType())
    {
        case TARGET_REFERENCE_TYPE_SRC:
            dst = m_targets.GetSrcPos();
            break;
        case TARGET_REFERENCE_TYPE_DEST:
            dst = m_targets.GetDstPos();
            break;
        case TARGET_REFERENCE_TYPE_CASTER:
            dst = m_caster;
            break;
        case TARGET_REFERENCE_TYPE_TARGET:
            dst = m_targets.GetUnitTarget();
            break;
        default:
            ABORT_MSG("Spell::SelectImplicitLineTargets: received not implemented target reference type");
            return;
    }

    ConditionContainer* condList = spellEffectInfo.ImplicitTargetConditions;
    float radius = spellEffectInfo.CalcRadius(m_caster) * m_spellValue->RadiusMod;

    if (uint32 containerTypeMask = GetSearcherTypeMask(objectType, condList))
    {
        Trinity::WorldObjectSpellLineTargetCheck check(m_caster, dst, m_spellInfo->Width ? m_spellInfo->Width : m_caster->GetCombatReach(), radius, m_caster, m_spellInfo, selectionType, condList, objectType);
        Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellLineTargetCheck> searcher(m_caster, targets, check, containerTypeMask);
        SearchTargets<Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellLineTargetCheck>>(searcher, containerTypeMask, m_caster, m_caster, radius);

        CallScriptObjectAreaTargetSelectHandlers(targets, spellEffectInfo.EffectIndex, targetType);

        if (!targets.empty())
        {
            // Other special target selection goes here
            if (uint32 maxTargets = m_spellValue->MaxAffectedTargets)
            {
                if (maxTargets < targets.size())
                {
                    targets.sort(Trinity::ObjectDistanceOrderPred(m_caster));
                    targets.resize(maxTargets);
                }
            }

            for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
            {
                if (Unit* unit = (*itr)->ToUnit())
                    AddUnitTarget(unit, effMask, false);
                else if (GameObject* gObjTarget = (*itr)->ToGameObject())
                    AddGOTarget(gObjTarget, effMask);
                else if (Corpse* corpse = (*itr)->ToCorpse())
                    AddCorpseTarget(corpse, 1 << spellEffectInfo.EffectIndex);
            }
        }
    }
}

void Spell::SelectEffectTypeImplicitTargets(SpellEffectInfo const& spellEffectInfo)
{
    // special case for SPELL_EFFECT_SUMMON_RAF_FRIEND and SPELL_EFFECT_SUMMON_PLAYER, queue them on map for later execution
    switch (spellEffectInfo.Effect)
    {
        case SPELL_EFFECT_SUMMON_RAF_FRIEND:
        case SPELL_EFFECT_SUMMON_PLAYER:
            if (m_caster->GetTypeId() == TYPEID_PLAYER && !m_caster->ToPlayer()->GetTarget().IsEmpty())
            {
                WorldObject* target = ObjectAccessor::FindPlayer(m_caster->ToPlayer()->GetTarget());
                CallScriptObjectTargetSelectHandlers(target, spellEffectInfo.EffectIndex, SpellImplicitTargetInfo());
    if (missInfo != SPELL_MISS_NONE)
        return;

    // Call scripted function for AI if this spell is casted upon a creature
    if (unit->IsCreature())
    {
        // cast at creature (or GO) quest objectives update at successful cast finished (+channel finished)
        // ignore pets or autorepeat/melee casts for speed (not exist quest for spells (hm... )
        if (pRealUnitCaster && !((Creature*)unit)->IsPet() && !IsAutoRepeat() && !m_spellInfo->IsNextMeleeSwingSpell() && !IsChannelActive())
            if (Player* p = pRealUnitCaster->GetCharmerOrOwnerPlayerOrPlayerItself())
                p->RewardPlayerAndGroupAtCast(unit, m_spellInfo->Id);

                // scripts may modify the target - recheck
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                {
                    // target is not stored in target map for those spells
                    // since we're completely skipping AddUnitTarget logic, we need to check immunity manually
                    // eg. aura 21546 makes target immune to summons
                    Player* player = target->ToPlayer();
                    if (player->IsImmunedToSpellEffect(m_spellInfo, spellEffectInfo, nullptr))
                        return;
        if (m_casterUnit)
        {
            if (((Creature*)unit)->AI())
                ((Creature*)unit)->AI()->SpellHit(m_casterUnit, m_spellInfo);

                    target->GetMap()->AddFarSpellCallback([spell = this, &spellEffectInfo, targetGuid = target->GetGUID()](Map* map)
                    {
                        Player* player = ObjectAccessor::GetPlayer(map, targetGuid);
                        if (!player)
                            return;

                        // check immunity again in case it changed during update
                        if (player->IsImmunedToSpellEffect(spell->GetSpellInfo(), spellEffectInfo, nullptr))
                            return;

                        spell->HandleEffects(player, nullptr, nullptr, nullptr, spellEffectInfo, SPELL_EFFECT_HANDLE_HIT_TARGET);
                    });
                }
            }
            return;
        default:
            break;
            if (ZoneScript* pZoneScript = unit->GetZoneScript())
                pZoneScript->OnCreatureSpellHit(m_casterUnit, unit->ToCreature(), m_spellInfo);
        }
    }

    // select spell implicit targets based on effect type
    if (!spellEffectInfo.GetImplicitTargetType())
        return;

    uint32 targetMask = spellEffectInfo.GetMissingTargetMask();

    if (!targetMask)
        return;

    WorldObject* target = nullptr;

    switch (spellEffectInfo.GetImplicitTargetType())
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
                    if (Corpse* corpseTarget = m_targets.GetCorpseTarget())
                        target = corpseTarget;
                }
                else //if (targetMask & TARGET_FLAG_UNIT_MASK)
                    target = m_caster;
            }
            if (targetMask & TARGET_FLAG_ITEM_MASK)
            {
                if (Item* item = m_targets.GetItemTarget())
                    AddItemTarget(item, 1 << spellEffectInfo.EffectIndex);
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
    
    // World of Warcraft Client Patch 1.8.0 (2005-10-11)
    // - Pets no longer break off attacks when their target is affected by Warlock Fear.
#if SUPPORTED_CLIENT_BUILD <= CLIENT_BUILD_1_7_1
    if (((m_spellInfo->AuraInterruptFlags & AURA_INTERRUPT_FLAG_DAMAGE) || m_spellInfo->HasAura(SPELL_AURA_MOD_FEAR)) &&
#else
    if ((m_spellInfo->AuraInterruptFlags & AURA_INTERRUPT_FLAG_DAMAGE) &&
#endif
        m_casterUnit && unit->HasAuraPetShouldAvoidBreaking(m_casterUnit))
    {
        // Tell any pets to stop attacking the target on application of breakable crowd control spells
        Unit::AttackerSet attackers = unit->GetAttackers();
        for (const auto attacker : attackers)
        {
            if (attacker->IsPet())
                attacker->AttackStop();
        }
    }

    // Call scripted function for AI if this spell is casted by a creature
    if (m_caster->IsCreature() && ((Creature*)m_caster)->AI())
        ((Creature*)m_caster)->AI()->SpellHitTarget(unit, m_spellInfo);
}

void Spell::DoSpellHitOnUnit(Unit* unit, uint32 effectMask)
{
    if (!unit)
        return;

    CallScriptObjectTargetSelectHandlers(target, spellEffectInfo.EffectIndex, SpellImplicitTargetInfo());
    SpellCaster* pRealCaster = GetAffectiveCasterObject();
    Unit* pRealUnitCaster = GetAffectiveCaster();

    if (!effectMask)
    {
        if (target->ToUnit())
            AddUnitTarget(target->ToUnit(), 1 << spellEffectInfo.EffectIndex, false);
        else if (target->ToGameObject())
            AddGOTarget(target->ToGameObject(), 1 << spellEffectInfo.EffectIndex);
        else if (target->ToCorpse())
            AddCorpseTarget(target->ToCorpse(), 1 << spellEffectInfo.EffectIndex);
    }
}
        if (pRealUnitCaster && !unit->IsInCombat())
            unit->AttackedBy(pRealUnitCaster);
        return;
    }

    // Check mechanic resistance for each effect
    for (uint8 eff = 0; eff < MAX_EFFECT_INDEX; ++eff)
        if (unit->IsEffectResist(m_spellInfo, eff))
        {
            effectMask &= ~(1 << eff);
            if (!effectMask)
                return;
        }

    // Recheck immune (only for delayed spells)
    if (m_caster != unit && m_spellInfo->speed && (
                unit->IsImmuneToDamage(m_spellInfo->GetSpellSchoolMask(), m_spellInfo) ||
                unit->IsImmuneToSpell(m_spellInfo, unit == pRealUnitCaster)))
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
        if (pRealCaster)
            pRealCaster->SendSpellMiss(unit, m_spellInfo->Id, SPELL_MISS_IMMUNE);

        ResetEffectDamageAndHeal();
        return;
    }

template<class SEARCHER>
void Spell::SearchTargets(SEARCHER& searcher, uint32 containerMask, WorldObject* referer, Position const* pos, float radius)
{
    if (!containerMask)
        return;
    if (pRealCaster && pRealCaster != unit)
    {
        // Recheck  UNIT_FLAG_NON_ATTACKABLE for delayed spells
        if (unit->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE) &&
            unit->GetCharmerOrOwnerGuid() != m_caster->GetObjectGuid())
        {
            pRealCaster->SendSpellMiss(unit, m_spellInfo->Id, SPELL_MISS_EVADE);
            ResetEffectDamageAndHeal();
            return;
        }

        if (!pRealCaster->IsFriendlyTo(unit))
        {
            if (m_damage) // Example: stealth.
                unit->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_HITBYSPELL);

            // not break stealth by cast targeting
            if (!(m_spellInfo->AttributesEx & SPELL_ATTR_EX_NOT_BREAK_STEALTH))
            {
                unit->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);
                unit->RemoveNonPassiveSpellsCausingAura(SPELL_AURA_MOD_INVISIBILITY);
            }

void Spell::SearchAreaTargets(std::list<WorldObject*>& targets, float range, Position const* position, WorldObject* referer, SpellTargetObjectTypes objectType, SpellTargetCheckTypes selectionType, ConditionContainer* condList)
{
    uint32 containerTypeMask = GetSearcherTypeMask(objectType, condList);
    if (!containerTypeMask)
        return;

    float extraSearchRadius = range > 0.0f ? EXTRA_CELL_SEARCH_RADIUS : 0.0f;
    Trinity::WorldObjectSpellAreaTargetCheck check(range, position, m_caster, referer, m_spellInfo, selectionType, condList, objectType);
    Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellAreaTargetCheck> searcher(m_caster, targets, check, containerTypeMask);
    SearchTargets<Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellAreaTargetCheck> > (searcher, containerTypeMask, m_caster, position, range + extraSearchRadius);
}
            // for delayed spells ignore not visible explicit target
            if (m_delayed && unit == m_targets.getUnitTarget() &&
                    !unit->IsVisibleForOrDetect(m_caster, m_caster, false))
            {
                pRealCaster->SendSpellMiss(unit, m_spellInfo->Id, SPELL_MISS_EVADE);
                ResetEffectDamageAndHeal();
                return;
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
            // can cause back attack (if detected), stealth removed at Spell::cast if spell break it
            if ((!m_spellInfo->IsPositiveSpell() || m_spellInfo->HasEffect(SPELL_EFFECT_DISPEL)) &&
                    !m_spellInfo->IsFitToFamily<SPELLFAMILY_ROGUE, CF_ROGUE_SAP>() && // Sap handled somewhere else. Without this, sap will remove stealth if the rogue is visible.
                    (m_spellInfo->Id == 6358 || // Exception to fix succubus seduction.
                     m_caster->IsVisibleForOrDetect(unit, unit, false)))
            {
                if (!m_spellInfo->HasAttribute(SPELL_ATTR_EX3_NO_INITIAL_AGGRO) && !IsTriggeredByAura())
                {
                    // use speedup check to avoid re-remove after above lines
                    if (m_spellInfo->AttributesEx & SPELL_ATTR_EX_NOT_BREAK_STEALTH)
                    {
                        unit->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);
                        unit->RemoveNonPassiveSpellsCausingAura(SPELL_AURA_MOD_INVISIBILITY);
                    }

    if (Player* modOwner = m_caster->GetSpellModOwner())
        modOwner->ApplySpellMod(m_spellInfo, SpellModOp::ChainJumpDistance, jumpRadius, this);

    // max dist which spell can reach
    float searchRadius = [&]()
    {
        if (m_spellInfo->HasAttribute(SPELL_ATTR2_CHAIN_FROM_CASTER))
            return GetMinMaxRange(false).second;

        if (spellEffectInfo.EffectAttributes.HasFlag(SpellEffectAttributes::ChainFromInitialTarget))
            return jumpRadius;
                    // caster can be detected but have stealth aura
                    if (m_casterUnit)
                    {
                        m_casterUnit->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);
                        m_casterUnit->RemoveNonPassiveSpellsCausingAura(SPELL_AURA_MOD_INVISIBILITY);
                    }

        return jumpRadius * chainTargets;
    }();
                    if (pRealUnitCaster)
                    {
                        if (!m_spellInfo->HasAura(SPELL_AURA_MOD_POSSESS))
                        {
                            if (!unit->IsInCombat())
                                unit->AttackedBy(pRealUnitCaster);

    WorldObject* chainSource = m_spellInfo->HasAttribute(SPELL_ATTR2_CHAIN_FROM_CASTER) ? m_caster : target;
    std::list<WorldObject*> tempTargets;
    SearchAreaTargets(tempTargets, searchRadius, chainSource, m_caster, objectType, selectType, spellEffectInfo.ImplicitTargetConditions);
    tempTargets.remove(target);
                            unit->AddThreat(pRealUnitCaster);
                            unit->SetInCombatWithAggressor(pRealUnitCaster);
                        }

    // remove targets which are always invalid for chain spells
    // for some spells allow only chain targets in front of caster (swipe for example)
    if (m_spellInfo->HasAttribute(SPELL_ATTR5_MELEE_CHAIN_TARGETING))
    {
        tempTargets.remove_if([&](WorldObject* object)
        {
            return !m_caster->HasInArc(static_cast<float>(M_PI), object);
        });
    }
                        pRealUnitCaster->SetInCombatWithVictim(unit);
                    }
                }
                else if (m_spellInfo->HasAttribute(SPELL_ATTR_EX3_OUT_OF_COMBAT_ATTACK) && pRealUnitCaster)
                {
                    unit->SetOutOfCombatWithAggressor(pRealUnitCaster);
                    pRealUnitCaster->SetOutOfCombatWithVictim(unit);
                }
            }
            else if (pRealUnitCaster)
            {
                // make sure caster is flagged in pvp case
                pRealUnitCaster->SetOutOfCombatWithVictim(unit);
            }
        }
        else
        {
            // for delayed spells ignore negative spells (after duel end) for friendly targets
            if (m_delayed && !m_spellInfo->IsPositiveSpell())
            {
                pRealCaster->SendSpellMiss(unit, m_spellInfo->Id, SPELL_MISS_EVADE);
                ResetEffectDamageAndHeal();
                return;
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

        if (!m_spellInfo->HasAttribute(SPELL_ATTR2_CHAIN_FROM_CASTER) && !spellEffectInfo.EffectAttributes.HasFlag(SpellEffectAttributes::ChainFromInitialTarget))
            chainSource = *foundItr;

        targets.push_back(*foundItr);
        tempTargets.erase(foundItr);
        --chainTargets;
    }
}
            // World of Warcraft Client Patch (2004-11-07)
            // - Healing and buffing NPCs will not flag you for PvP unless those 
            //   NPCs are in combat.
            if (pRealUnitCaster)
            {
                if (unit->IsInCombat())
                {
                    if (!(m_spellInfo->AttributesEx3 & SPELL_ATTR_EX3_NO_INITIAL_AGGRO))
                    {
                        pRealUnitCaster->SetInCombatWithAssisted(unit);
                        unit->GetHostileRefManager().threatAssist(pRealUnitCaster, 0.0f, m_spellInfo);
                    }
                }
                else if (unit->IsPvP() && unit->IsPlayer())
                {
                    if (Player* pPlayer = pRealUnitCaster->GetCharmerOrOwnerPlayerOrPlayerItself())
                        pPlayer->UpdatePvP(true);
                }
            }
            
        }
    }

    // Get Data Needed for Diminishing Returns, some effects may have multiple auras, so this must be done on spell hit, not aura add
    m_diminishGroup = m_spellInfo->GetDiminishingReturnsGroup(m_triggeredByAuraSpell);
    m_diminishLevel = unit->GetDiminishing(m_diminishGroup);

    if (pRealUnitCaster)
        DEBUG_UNIT(pRealUnitCaster, DEBUG_DR, "[%u] Groupe DR : %u. Niveau : %u.", m_spellInfo->Id, m_diminishGroup, m_diminishLevel);

    // Increase Diminishing on unit, current informations for actually casts will use values above
    if ((GetDiminishingReturnsGroupType(m_diminishGroup) == DRTYPE_PLAYER && unit->IsPlayer()) ||
            GetDiminishingReturnsGroupType(m_diminishGroup) == DRTYPE_ALL)
        unit->IncrDiminishing(m_diminishGroup);

    // Apply additional spell effects to target
    CastPreCastSpells(unit);

    if (m_spellInfo->IsSpellAppliesAura(effectMask))
    {
        m_spellAuraHolder = CreateSpellAuraHolder(m_spellInfo, unit, pRealUnitCaster ? pRealUnitCaster : unit, m_caster, m_CastItem);
        m_spellAuraHolder->SetTriggered(IsTriggered());
        m_spellAuraHolder->setDiminishGroup(m_diminishGroup);
        m_spellAuraHolder->setDiminishLevel(m_diminishLevel);
    }
    else
        m_spellAuraHolder = nullptr;

    for (int effectNumber = 0; effectNumber < MAX_EFFECT_INDEX; ++effectNumber)
    {
        if (effectMask & (1 << effectNumber))
        {
            HandleEffects(unit, nullptr, nullptr, SpellEffectIndex(effectNumber), m_damageMultipliers[effectNumber]);
            if (m_applyMultiplierMask & (1 << effectNumber))
            {
                // Get multiplier
                float multiplier = m_spellInfo->DmgMultiplier[effectNumber];
                // Apply multiplier mods
                if (pRealUnitCaster)
                    if (Player* modOwner = pRealUnitCaster->GetSpellModOwner())
                        modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_EFFECT_PAST_FIRST, multiplier, this);
                m_damageMultipliers[effectNumber] *= multiplier;
            }
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
    // now apply all created auras
    if (m_spellAuraHolder)
    {
        // normally shouldn't happen
        if (!m_spellAuraHolder->IsEmptyHolder())
        {
            int32 duration = m_spellAuraHolder->GetAuraMaxDuration();
            int32 originalDuration = duration;

            if (duration > 0)
            {
                unit->ApplyDiminishingToDuration(m_diminishGroup, duration, m_caster, m_diminishLevel, isReflected);

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
                // Fully diminished
                if (duration == 0)
                {
                    delete m_spellAuraHolder;
                    m_spellAuraHolder = nullptr;

                    // Need to interrupt pet channeling spells or else they get stuck
                    if (m_caster && m_caster->IsControlledByPlayer() && m_channeled)
                    {
                        Spell* channeled = m_caster->GetCurrentSpell(CURRENT_CHANNELED_SPELL);
                        if (channeled && channeled->m_spellInfo->Id == m_spellInfo->Id && channeled->m_targets.getUnitTarget() == unit)
                            m_caster->InterruptSpell(CURRENT_CHANNELED_SPELL);
                    }
                    return;
                }
            }

            if (duration != originalDuration)
            {
                m_spellAuraHolder->SetAuraMaxDuration(duration);
                m_spellAuraHolder->SetAuraDuration(duration);
            }

            if (!unit->AddSpellAuraHolder(m_spellAuraHolder))
                m_spellAuraHolder = nullptr;
        }
        else
        {
            delete m_spellAuraHolder;
            m_spellAuraHolder = nullptr;
        }

        // Aura applied successfully. If it's a channeled spell keep track of the holder so
        // we can update it on spell update. Units do not update holders on themselves if
        // they are from a channeled spell
        if (m_channeled && m_spellAuraHolder)
        {
            AddChanneledAuraHolder(m_spellAuraHolder);
        }
    }
}

void Spell::DoAllEffectOnTarget(GOTargetInfo *target)
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

            ProcFlags const typeMaskActor = PROC_FLAG_NONE;
            ProcFlags const typeMaskActionTarget = PROC_FLAG_TAKE_HARMFUL_SPELL | PROC_FLAG_TAKE_HARMFUL_ABILITY;
            ProcFlagsSpellType const spellTypeMask = PROC_SPELL_TYPE_DAMAGE | PROC_SPELL_TYPE_NO_DMG_HEAL;
            ProcFlagsSpellPhase const spellPhaseMask = PROC_SPELL_PHASE_NONE;
            ProcFlagsHit const hitMask = PROC_HIT_REFLECT;
    for (int effectNumber = 0; effectNumber < MAX_EFFECT_INDEX; ++effectNumber)
        if (effectMask & (1 << effectNumber))
            HandleEffects(nullptr, nullptr, go, SpellEffectIndex(effectNumber));

            Unit::ProcSkillsAndAuras(caster, _victim, typeMaskActor, typeMaskActionTarget, spellTypeMask, spellPhaseMask, hitMask, nullptr, nullptr, nullptr);
            return true;
        }
    // cast at creature (or GO) quest objectives update at successful cast finished (+channel finished)
    // ignore autorepeat/melee casts for speed (not exist quest for spells (hm... )
    if (!IsAutoRepeat() && !m_spellInfo->IsNextMeleeSwingSpell() && !IsChannelActive() && m_casterUnit)
    {
        if (Player* p = m_casterUnit->GetCharmerOrOwnerPlayerOrPlayerItself())
            p->RewardPlayerAndGroupAtCast(go, m_spellInfo->Id);
    }
}

void Spell::DoAllEffectOnTarget(ItemTargetInfo *target)
{
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
        if (!spellEffectInfo.IsEffect() || !CheckEffectTarget(target, spellEffectInfo, losPosition))
            effectMask &= ~(1 << spellEffectInfo.EffectIndex);
    uint32 effectMask = target->effectMask;
    if (!target->item || !effectMask)
        return;

    for (int effectNumber = 0; effectNumber < MAX_EFFECT_INDEX; ++effectNumber)
        if (effectMask & (1 << effectNumber))
            HandleEffects(nullptr, target->item, nullptr, SpellEffectIndex(effectNumber));
}

void Spell::HandleDelayedSpellLaunch(TargetInfo *target)
{
    // Get mask of effects for target
    uint32 mask = target->effectMask;

    if (checkIfValid)
        if (m_spellInfo->CheckTarget(m_caster, target, implicit) != SPELL_CAST_OK) // skip stealth checks for AOE
            return;
    Unit* unit = m_caster->GetObjectGuid() == target->targetGUID ? m_casterUnit : ObjectAccessor::GetUnit(*m_caster, target->targetGUID);
    if (!unit)
        return;

    // Check for effect immune skip if immuned
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
        if (target->IsImmunedToSpellEffect(m_spellInfo, spellEffectInfo, m_caster))
            effectMask &= ~(1 << spellEffectInfo.EffectIndex);
    // Get original caster (if exist) and calculate damage/healing from him data
    SpellCaster* pRealCaster = GetAffectiveCasterObject();
    SpellCaster* pCaster = pRealCaster ? pRealCaster : m_caster;

    SpellMissInfo missInfo = target->missCondition;
    // Need init unitTarget by default unit (can changed in code on reflect)
    // Or on missInfo!=SPELL_MISS_NONE unitTarget undefined (but need in trigger subsystem)
    unitTarget = unit;

    // Lookup target in already in list
    auto ihit = std::find_if(std::begin(m_UniqueTargetInfo), std::end(m_UniqueTargetInfo), [targetGUID](TargetInfo const& target) { return target.TargetGUID == targetGUID; });
    if (ihit != std::end(m_UniqueTargetInfo)) // Found in list
    {
        // Immune effects removed from mask
        ihit->EffectMask |= effectMask;
        return;
    }
    // Reset damage/healing counter
    ResetEffectDamageAndHeal();

    // Fill base damage struct (unitTarget - is real spell target)
    SpellNonMeleeDamage damageInfo(pCaster, unitTarget, m_spellInfo->Id, GetFirstSchoolInMask(m_spellSchoolMask));

    // Get spell hit result on target
    TargetInfo targetInfo;
    targetInfo.TargetGUID = targetGUID;                         // Store target GUID
    targetInfo.EffectMask = effectMask;                         // Store all effects not immune
    targetInfo.IsAlive    = target->IsAlive();
    targetInfo.Damage     = 0;
    targetInfo.Healing    = 0;
    targetInfo.IsCrit     = false;
    if (unit && !pCaster->IsFriendlyTo(unit))
        unit->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_HITBYSPELL);
    if (missInfo == SPELL_MISS_NONE || (missInfo == SPELL_MISS_REFLECT && target->reflectResult == SPELL_MISS_NONE))
    {
        // we need index of damage dealing effect for CalculateSpellDamage to use right bonus coefficient
        SpellEffectIndex damageEffectIndex = EFFECT_INDEX_0;

    // Calculate hit result
    WorldObject* caster = m_originalCaster ? m_originalCaster : m_caster;
    targetInfo.MissCondition = caster->SpellHitResult(target, m_spellInfo, m_canReflect && !(IsPositive() && m_caster->IsFriendlyTo(target)));
        for (uint8 effectNumber = 0; effectNumber < MAX_EFFECT_INDEX; ++effectNumber)
        {
            if (mask & (1 << effectNumber))
            {
                if (IsDirectDamageWithBonusEffect(m_spellInfo->Effect[effectNumber]))
                    damageEffectIndex = SpellEffectIndex(effectNumber);

    // Spell have speed - need calculate incoming time
    // Incoming time is zero for self casts. At least I think so.
    if (m_caster != target)
    {
        float hitDelay = m_spellInfo->LaunchDelay;
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
                if (m_spellInfo->IsEffectHandledOnDelayedSpellLaunch(SpellEffectIndex(effectNumber)))
                {
                    HandleEffects(unit, nullptr, nullptr, SpellEffectIndex(effectNumber), m_damageMultipliers[effectNumber]);
                    if (m_applyMultiplierMask & (1 << effectNumber))
                    {
                        // Get multiplier
                        float multiplier = m_spellInfo->DmgMultiplier[effectNumber];
                        // Apply multiplier mods
                        if (Unit* pRealUnitCaster = ToUnit(pRealCaster))
                            if (Player* modOwner = pRealUnitCaster->GetSpellModOwner())
                                modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_EFFECT_PAST_FIRST, multiplier, this);
                        m_damageMultipliers[effectNumber] *= multiplier;
                    }
                }
            }
        }

        targetInfo.TimeDelay += uint64(std::floor(hitDelay * 1000.0f));
        if (m_damage > 0)
            pCaster->CalculateSpellDamage(&damageInfo, m_damage, m_spellInfo, damageEffectIndex, m_attackType, this);
    }
    else
        targetInfo.TimeDelay = 0ULL;

    // If target reflect spell back to caster
    if (targetInfo.MissCondition == SPELL_MISS_REFLECT)
    {
        // Calculate reflected spell result on caster (shouldn't be able to reflect gameobject spells)
        Unit* unitCaster = ASSERT_NOTNULL(m_caster->ToUnit());
        targetInfo.ReflectResult = unitCaster->SpellHitResult(unitCaster, m_spellInfo, false); // can't reflect twice
    target->damage = damageInfo.damage;
    target->HitInfo = damageInfo.HitInfo;
}

void Spell::InitializeDamageMultipliers()
{
    for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
    {
        if (m_spellInfo->Effect[i] == 0)
            continue;

        // Proc spell reflect aura when missile hits the original target
        target->m_Events.AddEvent(new ProcReflectDelayed(target, m_originalCasterGUID), target->m_Events.CalculateTime(Milliseconds(targetInfo.TimeDelay)));
        uint32 EffectChainTarget = m_spellInfo->EffectChainTarget[i];
        if (Unit* realCaster = GetAffectiveCaster())
            if (Player* modOwner = realCaster->GetSpellModOwner())
                modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_JUMP_TARGETS, EffectChainTarget, this);

        // Increase time interval for reflected spells by 1.5
        targetInfo.TimeDelay += targetInfo.TimeDelay >> 1;
        m_damageMultipliers[i] = 1.0f;
        if ((m_spellInfo->EffectImplicitTargetA[i] == TARGET_UNIT_ENEMY || m_spellInfo->EffectImplicitTargetA[i] == TARGET_UNIT_FRIEND_CHAIN_HEAL) &&
                (EffectChainTarget > 1))
            m_applyMultiplierMask |= (1 << i);
    }
    else
        targetInfo.ReflectResult = SPELL_MISS_NONE;
}

    // Calculate minimum incoming time
    if (targetInfo.TimeDelay && (!m_delayMoment || m_delayMoment > targetInfo.TimeDelay))
        m_delayMoment = targetInfo.TimeDelay;
// <Daemon>: Changing the operation of this function
// Indicates whether the cast should stop or not
// For this, we look if there are any targets.

    // Add target to list
    m_UniqueTargetInfo.emplace_back(std::move(targetInfo));
}
bool Spell::HasValidUnitPresentInTargetList()
{
    uint8 foundMask = 0;
    uint8 needTargetsMask = 0;
    for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
        if (m_spellInfo->Effect[i] == SPELL_EFFECT_APPLY_AURA && m_spellInfo->EffectApplyAuraName[i])
            if (m_spellInfo->EffectImplicitTargetA[i] != TARGET_UNIT_CASTER)
                needTargetsMask |= 1 << i;

    // This channel does not need a target: it launches on the caster
    // It does not stop unless it dies of course.
    if (!needTargetsMask)
    {
        if (!m_casterUnit)
            return false;

        return m_spellInfo->CanTargetAliveState(m_casterUnit->IsAlive());
    }

void Spell::AddGOTarget(GameObject* go, uint32 effectMask)
{
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
        if (!spellEffectInfo.IsEffect() || !CheckEffectTarget(go, spellEffectInfo))
            effectMask &= ~(1 << spellEffectInfo.EffectIndex);
    for (const auto& ihit : m_UniqueTargetInfo)
    {
        if (ihit.deleted)
            continue;
        if (ihit.missCondition != SPELL_MISS_NONE)
            continue;

        Unit* unit = m_caster->GetObjectGuid() == ihit.targetGUID ? m_casterUnit : ObjectAccessor::GetUnit(*m_caster, ihit.targetGUID);

        if (unit && m_spellInfo->CanTargetAliveState(unit->IsAlive()))
            foundMask |= ihit.effectMask;
    }

    return (foundMask & needTargetsMask);
}

    // Lookup target in already in list
    auto ihit = std::find_if(std::begin(m_UniqueGOTargetInfo), std::end(m_UniqueGOTargetInfo), [targetGUID](GOTargetInfo const& target) { return target.TargetGUID == targetGUID; });
    if (ihit != std::end(m_UniqueGOTargetInfo)) // Found in list
    {
        // Add only effect mask
        ihit->EffectMask |= effectMask;
        return;
    }
// Helper for Chain Healing
// Spell target first
// Raidmates then descending by injury suffered (MaxHealth - Health)
// Other players/mobs then descending by injury suffered (MaxHealth - Health)
struct ChainHealingOrder
{
    Unit const* MainTarget;
    ChainHealingOrder(Unit const* Target) : MainTarget(Target) {};
    // functor for operator ">"
    bool operator()(Unit const* _Left, Unit const* _Right) const
    {
        return (ChainHealingHash(_Left) < ChainHealingHash(_Right));
    }
    int32 ChainHealingHash(Unit const* Target) const
    {
        if (Target == MainTarget)
            return 0;
        else if (Target->IsPlayer() && MainTarget->IsPlayer() &&
                 ((Player const*)Target)->IsInSameRaidWith((Player const*)MainTarget))
        {
            if (Target->GetHealth() == Target->GetMaxHealth())
                return 40000;
            else
                return 20000 - Target->GetMaxHealth() + Target->GetHealth();
        }
        else
            return 40000 - Target->GetMaxHealth() + Target->GetHealth();
    }
};

class ChainHealingFullHealth
{
public:
    Unit const* MainTarget;
    ChainHealingFullHealth(Unit const* Target) : MainTarget(Target) {};

    GOTargetInfo target;
    target.TargetGUID = targetGUID;
    target.EffectMask = effectMask;
    bool operator()(Unit const* Target) const
    {
        return (Target != MainTarget && Target->GetHealth() == Target->GetMaxHealth());
    }
};

// Helper for targets nearest to the spell target
// The spell target is always first unless there is a target at _completely_ the same position (unbelievable case)
struct TargetDistanceOrderNear
{
    WorldObject const* MainTarget;
    TargetDistanceOrderNear(WorldObject const* Target) : MainTarget(Target) {};
    // functor for operator ">"
    bool operator()(WorldObject const* _Left, WorldObject const* _Right) const
    {
        return MainTarget->GetDistanceOrder(_Left, _Right);
    }
};

        target.TimeDelay = uint64(std::floor(hitDelay * 1000.0f));
    }
void Spell::SetTargetMap(SpellEffectIndex effIndex, uint32 targetMode, UnitList& targetUnitMap)
{
    float radius;
    if (m_spellInfo->EffectRadiusIndex[effIndex])
        radius = GetSpellRadius(sSpellRadiusStore.LookupEntry(m_spellInfo->EffectRadiusIndex[effIndex]));
    else
        target.TimeDelay = 0ULL;
        radius = GetSpellMaxRange(sSpellRangeStore.LookupEntry(m_spellInfo->rangeIndex));

    // Calculate minimum incoming time
    if (target.TimeDelay && (!m_delayMoment || m_delayMoment > target.TimeDelay))
        m_delayMoment = target.TimeDelay;
    uint32 EffectChainTarget = m_spellInfo->EffectChainTarget[effIndex];

    // Add target to list
    m_UniqueGOTargetInfo.emplace_back(std::move(target));
}
    if (Unit* realCaster = GetAffectiveCaster())
    {
        if (Player* modOwner = realCaster->GetSpellModOwner())
        {
            modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RADIUS, radius, this);
            modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_JUMP_TARGETS, EffectChainTarget, this);
        }
    }

void Spell::AddItemTarget(Item* item, uint32 effectMask)
{
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
        if (!spellEffectInfo.IsEffect() || !CheckEffectTarget(item, spellEffectInfo))
            effectMask &= ~(1 << spellEffectInfo.EffectIndex);

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
    // Add spell leeway to caster centered AoE when moving or jumping
    switch (targetMode)
    {
        case TARGET_ENUM_UNITS_ENEMY_AOE_AT_SRC_LOC:
        case TARGET_ENUM_UNITS_PARTY_WITHIN_CASTER_RANGE:
        case TARGET_ENUM_UNITS_ENEMY_IN_CONE_24:
            radius += m_caster->GetLeewayBonusRadius();
            break;
        default:
            break;
    }

    // This is new target add data
    uint32 unMaxTargets = m_spellInfo->MaxAffectedTargets;

    ItemTargetInfo target;
    target.TargetItem = item;
    target.EffectMask = effectMask;

    m_UniqueItemInfo.emplace_back(std::move(target));
}

void Spell::AddCorpseTarget(Corpse* corpse, uint32 effectMask)
{
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
        if (!spellEffectInfo.IsEffect())
            effectMask &= ~(1 << spellEffectInfo.EffectIndex);

    // no effects left
    if (!effectMask)
        return;

    ObjectGuid targetGUID = corpse->GetGUID();

    // Lookup target in already in list
    auto ihit = std::find_if(std::begin(m_UniqueCorpseTargetInfo), std::end(m_UniqueCorpseTargetInfo), [targetGUID](CorpseTargetInfo const& target) { return target.TargetGUID == targetGUID; });
    if (ihit != std::end(m_UniqueCorpseTargetInfo)) // Found in list
    // custom target amount cases
    switch (m_spellInfo->SpellFamilyName)
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
    if (m_caster != corpse)
    {
        float hitDelay = m_spellInfo->LaunchDelay;
        if (m_spellInfo->HasAttribute(SPELL_ATTR9_SPECIAL_DELAY_CALCULATION))
            hitDelay += m_spellInfo->Speed;
        else if (m_spellInfo->Speed > 0.0f)
        {
            // calculate spell incoming interval
            float dist = std::max(m_caster->GetDistance(corpse->GetPositionX(), corpse->GetPositionY(), corpse->GetPositionZ()), 5.0f);
            hitDelay += dist / m_spellInfo->Speed;
        }

        target.TimeDelay = uint64(std::floor(hitDelay * 1000.0f));
    }
    else
        target.TimeDelay = 0LL;

    // Calculate minimum incoming time
    if (target.TimeDelay && (!m_delayMoment || m_delayMoment > target.TimeDelay))
        m_delayMoment = target.TimeDelay;

    // Add target to list
    m_UniqueCorpseTargetInfo.emplace_back(std::move(target));
}
        case SPELLFAMILY_GENERIC:
        {
            switch (m_spellInfo->Id)
            {
                case 802:                                   // Mutate Bug (AQ40, Emperor Vek'nilash)
                case 804:                                   // Explode Bug (AQ40, Emperor Vek'lor)
                case 23138:                                 // Gate of Shazzrah (MC, Shazzrah)
                case 24781:                                 // Dream Fog (Emerald Dragons)
                //case 28560:                                 // Summon Blizzard (Naxx, Sapphiron)
                    unMaxTargets = 1;
                    break;
                case 25676:                                 // Drain Mana
                case 25754:
                    unMaxTargets = 6;
                    break;
                case 26457:                                 // Drain Mana
                case 26559:
                    unMaxTargets = 12;
                    break;
                case 10258:                                 // Awaken Vault Warder (Uldaman)
                    unMaxTargets = 2;
                    break;
                case 28542:                                 // Life Drain (Naxx, Sapphiron)
                    unMaxTargets = urand(7, 10);
                    break;
                case 28796:                                 // Poison Bolt Volley (Naxx, Faerlina)
                    unMaxTargets = 10;
                    break;
            }
            break;
        }
        default:
            break;
    }

void Spell::AddDestTarget(SpellDestination const& dest, uint32 effIndex)
{
    m_destTargets[effIndex] = dest;
}

int64 Spell::GetUnitTargetCountForEffect(SpellEffIndex effect) const
{
    return std::count_if(m_UniqueTargetInfo.begin(), m_UniqueTargetInfo.end(), [effect](TargetInfo const& targetInfo)
    {
        return targetInfo.MissCondition == SPELL_MISS_NONE && targetInfo.EffectMask & (1 << effect);
    });
}

int64 Spell::GetGameObjectTargetCountForEffect(SpellEffIndex effect) const
{
    return std::count_if(m_UniqueGOTargetInfo.begin(), m_UniqueGOTargetInfo.end(), [effect](GOTargetInfo const& targetInfo)
    {
        return targetInfo.EffectMask & (1 << effect);
    });
}

int64 Spell::GetItemTargetCountForEffect(SpellEffIndex effect) const
{
    return std::count_if(m_UniqueItemInfo.begin(), m_UniqueItemInfo.end(), [effect](ItemTargetInfo const& targetInfo)
    {
        return targetInfo.EffectMask & (1 << effect);
    });
}
    // custom radius cases
    switch (m_spellInfo->SpellFamilyName)
    {
        case SPELLFAMILY_GENERIC:
        {
            switch (m_spellInfo->Id)
            {
                case 28241:                                 // Poison (Naxxramas, Grobbulus Cloud)
                {
                    // Spell states 30yd radius, which you would think is the max radius once its all grown,
                    // however, the visual of the spell goes no further than ~20yd, so lets stop it there.
                    // It will instantly get a 2(?) yd radius, and grow to 20 from there
                    if (m_casterUnit)
                    {
                        if (SpellAuraHolder* auraHolder = m_casterUnit->GetSpellAuraHolder(28158))
                        {
                            int const maxDur = auraHolder->GetAuraMaxDuration();
                            int const currTick = maxDur - auraHolder->GetAuraDuration();
                            radius = 18.0f / maxDur*currTick + 2;
                            //radius = 0.5f * (60000 - auraHolder->GetAuraDuration()) * 0.001f;
                        }
                    }
                    
                    break;
                }
                case 29310:                                 // Mana Burn (Heigan, naxxramas)
                    // Without a bigger raidus its possible to tank heigan in one corner of the platform, and have ranged stay in the other corner
                    radius = 28.0f;
                    break;
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }

    bool SelectClosestTargets = false;

    // custom selection cases
    switch (m_spellInfo->SpellFamilyName)
    {
        case SPELLFAMILY_GENERIC:
        {
            switch (m_spellInfo->Id)
            {
                case 26052:                                 // Poison Bolt Volley (AQ40, Princess Huhuran)
                case 29213:                                 // Curse of the Plaguebringer (Naxxramas, Noth the Plaguebringer)
                    SelectClosestTargets = true;
                    break;
            }
            break;
        }
        case SPELLFAMILY_HUNTER:
        {
            switch (m_spellInfo->Id)
            {
                case 26180:                                 // Wyvern Sting (AQ40, Princess Huhuran)
                    SelectClosestTargets = true;
                    break;
            }
            break;
        }
        default:
            break;
    }

int64 Spell::GetCorpseTargetCountForEffect(SpellEffIndex effect) const
{
    return std::count_if(m_UniqueCorpseTargetInfo.begin(), m_UniqueCorpseTargetInfo.end(), [effect](CorpseTargetInfo const& targetInfo)
    {
        return targetInfo.EffectMask & (1 << effect);
    });
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
    switch (targetMode)
    {
        case TARGET_UNIT_CASTER:
            if (m_casterUnit)
                targetUnitMap.push_back(m_casterUnit);
            else if (m_casterGo)
                AddGOTarget(m_casterGo, effIndex);
            break;
        case TARGET_UNIT_ENEMY_NEAR_CASTER:
        {
            m_targets.m_targetMask = 0;
            unMaxTargets = EffectChainTarget;
            float max_range = radius + unMaxTargets * CHAIN_SPELL_JUMP_RADIUS;

    if (spell->m_originalCaster && MissCondition != SPELL_MISS_EVADE && !spell->m_originalCaster->IsFriendlyTo(unit) && (!spell->m_spellInfo->IsPositive() || spell->m_spellInfo->HasEffect(SPELL_EFFECT_DISPEL)) && (spell->m_spellInfo->HasInitialAggro() || unit->IsEngaged()))
        unit->SetInCombatWith(spell->m_originalCaster);
            UnitList tempTargetUnitMap;

    // if target is flagged for pvp also flag caster if a player
    // but respect current pvp rules (buffing/healing npcs flagged for pvp only flags you if they are in combat)
    _enablePVP = (MissCondition == SPELL_MISS_NONE || spell->m_spellInfo->HasAttribute(SPELL_ATTR3_PVP_ENABLING))
        && unit->IsPvP() && (unit->IsInCombat() || unit->IsCharmedOwnedByPlayerOrPlayer()) && spell->m_caster->GetTypeId() == TYPEID_PLAYER; // need to check PvP state before spell effects, but act on it afterwards

    if (_spellHitTarget)
    {
        SpellMissInfo missInfo = spell->PreprocessSpellHit(_spellHitTarget, *this);
        if (missInfo != SPELL_MISS_NONE)
        {
            if (missInfo != SPELL_MISS_MISS)
                spell->m_caster->SendSpellMiss(unit, spell->m_spellInfo->Id, missInfo);
            spell->m_damage = 0;
            spell->m_healing = 0;
            _spellHitTarget = nullptr;
        }
    }
            {
                MaNGOS::AnyAoETargetUnitInObjectRangeCheck u_check(m_caster, m_originalCaster, max_range);
                MaNGOS::UnitListSearcher<MaNGOS::AnyAoETargetUnitInObjectRangeCheck> searcher(tempTargetUnitMap, u_check);
                Cell::VisitAllObjects(m_caster, searcher, max_range);
            }

    spell->CallScriptOnHitHandlers();
            if (tempTargetUnitMap.empty())
                break;

    // scripts can modify damage/healing for current target, save them
    Damage = spell->m_damage;
    Healing = spell->m_healing;
}
            tempTargetUnitMap.sort(TargetDistanceOrderNear(m_caster));

void Spell::TargetInfo::DoTargetSpellHit(Spell* spell, SpellEffectInfo const& spellEffectInfo)
{
    Unit* unit = spell->m_caster->GetGUID() == TargetGUID ? spell->m_caster->ToUnit() : ObjectAccessor::GetUnit(*spell->m_caster, TargetGUID);
    if (!unit)
        return;
            //Now to get us a random target that's in the initial range of the spell
            uint32 t = 0;
            auto itr = tempTargetUnitMap.begin();
            while (itr != tempTargetUnitMap.end() && (*itr)->IsWithinDist(m_caster, radius))
                ++t, ++itr;

            if (!t)
                break;

            itr = tempTargetUnitMap.begin();
            std::advance(itr, rand() % t);
            Unit* pUnitTarget = *itr;
            targetUnitMap.push_back(pUnitTarget);

    // Need init unitTarget by default unit (can changed in code on reflect)
    // Or on missInfo != SPELL_MISS_NONE unitTarget undefined (but need in trigger subsystem)
    spell->unitTarget = unit;
    spell->targetMissInfo = MissCondition;
            tempTargetUnitMap.erase(itr);

            tempTargetUnitMap.sort(TargetDistanceOrderNear(pUnitTarget));

    // Reset damage/healing counter
    spell->m_damage = Damage;
    spell->m_healing = Healing;
            t = unMaxTargets - 1;
            Unit* prev = pUnitTarget;
            auto next = tempTargetUnitMap.begin();

    if (unit->IsAlive() != IsAlive)
        return;
            while (t && next != tempTargetUnitMap.end())
            {
                if (!prev->IsWithinDist(*next, CHAIN_SPELL_JUMP_RADIUS))
                    break;

    if (spell->getState() == SPELL_STATE_DELAYED && !spell->IsPositive() && (GameTime::GetGameTimeMS() - TimeDelay) <= unit->m_lastSanctuaryTime)
        return;                                             // No missinfo in that case
                if (!(m_spellInfo->AttributesEx2 & SPELL_ATTR_EX2_IGNORE_LOS) && !prev->IsWithinLOSInMap(*next))
                {
                    ++next;
                    continue;
                }

    if (_spellHitTarget)
        spell->DoSpellEffectHit(_spellHitTarget, spellEffectInfo, *this);
                prev = *next;
                targetUnitMap.push_back(prev);
                tempTargetUnitMap.erase(next);
                tempTargetUnitMap.sort(TargetDistanceOrderNear(prev));
                next = tempTargetUnitMap.begin();

    // scripts can modify damage/healing for current target, save them
    Damage = spell->m_damage;
    Healing = spell->m_healing;
}
                --t;
            }
            break;
        }
        case TARGET_UNIT_FRIEND_NEAR_CASTER:
        {
            m_targets.m_targetMask = 0;
            unMaxTargets = EffectChainTarget;
            float max_range = radius + unMaxTargets * CHAIN_SPELL_JUMP_RADIUS;
            UnitList tempTargetUnitMap;
            {
                MaNGOS::AnyFriendlyUnitInObjectRangeCheck u_check(m_caster, max_range);
                MaNGOS::UnitListSearcher<MaNGOS::AnyFriendlyUnitInObjectRangeCheck> searcher(tempTargetUnitMap, u_check);
                Cell::VisitAllObjects(m_caster, searcher, max_range);
            }

void Spell::TargetInfo::DoDamageAndTriggers(Spell* spell)
{
    Unit* unit = spell->m_caster->GetGUID() == TargetGUID ? spell->m_caster->ToUnit() : ObjectAccessor::GetUnit(*spell->m_caster, TargetGUID);
    if (!unit)
        return;
            if (tempTargetUnitMap.empty())
                break;

            tempTargetUnitMap.sort(TargetDistanceOrderNear(m_caster));

            //Now to get us a random target that's in the initial range of the spell
            uint32 t = 0;
            auto itr = tempTargetUnitMap.begin();
            while (itr != tempTargetUnitMap.end() && (*itr)->IsWithinDist(m_caster, radius))
                ++t, ++itr;

    // other targets executed before this one changed pointer
    spell->unitTarget = unit;
    if (_spellHitTarget)
        spell->unitTarget = _spellHitTarget;
            if (!t)
                break;

    // Reset damage/healing counter
    spell->m_damage = Damage;
    spell->m_healing = Healing;

    // Get original caster (if exist) and calculate damage/healing from him data
    // Skip if m_originalCaster not available
    Unit* caster = spell->m_originalCaster ? spell->m_originalCaster : spell->m_caster->ToUnit();
    if (caster)
    {
        // Fill base trigger info
        ProcFlagsInit procAttacker = spell->m_procAttacker;
        ProcFlagsInit procVictim = spell->m_procVictim;
        ProcFlagsSpellType procSpellType = PROC_SPELL_TYPE_NONE;
        ProcFlagsHit hitMask = PROC_HIT_NONE;
            itr = tempTargetUnitMap.begin();
            std::advance(itr, rand() % t);
            Unit* pUnitTarget = *itr;
            targetUnitMap.push_back(pUnitTarget);

        // Spells with this flag cannot trigger if effect is cast on self
        bool const canEffectTrigger = (!spell->m_spellInfo->HasAttribute(SPELL_ATTR3_SUPPRESS_CASTER_PROCS) || !spell->m_spellInfo->HasAttribute(SPELL_ATTR3_SUPPRESS_TARGET_PROCS))
            && spell->unitTarget->CanProc();
            tempTargetUnitMap.erase(itr);

        // Trigger info was not filled in Spell::prepareDataForTriggerSystem - we do it now
        if (canEffectTrigger && !procAttacker && !procVictim)
        {
            bool positive = true;
            if (spell->m_damage > 0)
                positive = false;
            else if (!spell->m_healing)
            {
                for (uint8 i = 0; i < spell->m_spellInfo->GetEffects().size(); ++i)
                {
                    // in case of immunity, check all effects to choose correct procFlags, as none has technically hit
                    if (EffectMask && !(EffectMask & (1 << i)))
                        continue;
            tempTargetUnitMap.sort(TargetDistanceOrderNear(pUnitTarget));

                    if (!spell->m_spellInfo->IsPositiveEffect(i))
                    {
                        positive = false;
                        break;
                    }
                }
            }
            t = unMaxTargets - 1;
            Unit* prev = pUnitTarget;
            auto next = tempTargetUnitMap.begin();

            while (t && next != tempTargetUnitMap.end())
            {
                if (!prev->IsWithinDist(*next, CHAIN_SPELL_JUMP_RADIUS))
                    break;

                if (!(m_spellInfo->AttributesEx2 & SPELL_ATTR_EX2_IGNORE_LOS) && !prev->IsWithinLOSInMap(*next))
                {
                    ++next;
                    continue;
                }
                prev = *next;
                targetUnitMap.push_back(prev);
                tempTargetUnitMap.erase(next);
                tempTargetUnitMap.sort(TargetDistanceOrderNear(prev));
                next = tempTargetUnitMap.begin();
                --t;
            }
            break;
        }

            switch (spell->m_spellInfo->DmgClass)
            {
                case SPELL_DAMAGE_CLASS_NONE:
                case SPELL_DAMAGE_CLASS_MAGIC:
                    if (spell->m_spellInfo->HasAttribute(SPELL_ATTR3_TREAT_AS_PERIODIC))
                    {
                        if (positive)
                        {
                            procAttacker |= PROC_FLAG_DEAL_HELPFUL_PERIODIC;
                            procVictim |= PROC_FLAG_TAKE_HELPFUL_PERIODIC;
                        }
                        else
                        {
                            procAttacker |= PROC_FLAG_DEAL_HARMFUL_PERIODIC;
                            procVictim |= PROC_FLAG_TAKE_HARMFUL_PERIODIC;
                        }
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
        case TARGET_UNIT_CASTER_PET:
        {
            Pet* tmpUnit = m_casterUnit ? m_casterUnit->GetPet() : nullptr;
            if (!tmpUnit) break;
            targetUnitMap.push_back(tmpUnit);
            break;
        }
        case TARGET_UNIT_ENEMY:
        {
            if (EffectChainTarget <= 1)
            {
                if (Unit* pUnitTarget = m_caster->SelectMagnetTarget(m_targets.getUnitTarget(), this, effIndex))
                {
                    m_targets.setUnitTarget(pUnitTarget);
                    targetUnitMap.push_back(pUnitTarget);
                }
            }
            else
            {
                Unit* pUnitTarget = m_targets.getUnitTarget();
                if (Unit* redirectTarget = m_caster->SelectMagnetTarget(m_targets.getUnitTarget(), this, effIndex))
                {
                    if (redirectTarget != pUnitTarget)
                    {
                        m_targets.setUnitTarget(redirectTarget);
                        targetUnitMap.push_back(redirectTarget);
                        break;
                    }
                }
                SpellCaster* originalCaster = GetAffectiveCasterObject();
                if (!pUnitTarget || !originalCaster)
                    break;

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
                addhealth = Unit::SpellCriticalHealingBonus(caster, spell->m_spellInfo, addhealth, nullptr);
            }
            else
                hitMask |= PROC_HIT_NORMAL;
                unMaxTargets = EffectChainTarget;

                float max_range;
                if (m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MELEE)
                    max_range = radius;
                else
                    //FIXME: This very like horrible hack and wrong for most spells
                    max_range = radius + unMaxTargets * CHAIN_SPELL_JUMP_RADIUS;

            healInfo = std::make_unique<HealInfo>(caster, spell->unitTarget, addhealth, spell->m_spellInfo, spell->m_spellInfo->GetSchoolMask());
            caster->HealBySpell(*healInfo, IsCrit);
            spell->unitTarget->GetThreatManager().ForwardThreatForAssistingMe(caster, float(healInfo->GetEffectiveHeal()) * 0.5f, spell->m_spellInfo);
            spell->m_healing = healInfo->GetEffectiveHeal();
                UnitList tempTargetUnitMap;

            procSpellType |= PROC_SPELL_TYPE_HEAL;
        }

        // Do damage
        bool hasDamage = false;
        if (spell->m_damage > 0)
        {
            hasDamage = true;
            // Fill base damage struct (unitTarget - is real spell target)
            SpellNonMeleeDamage damageInfo(caster, spell->unitTarget, spell->m_spellInfo, spell->m_SpellVisual, spell->m_spellSchoolMask, spell->m_castId);
            // Check damage immunity
            if (spell->unitTarget->IsImmunedToDamage(spell->m_spellInfo))
            {
                hitMask = PROC_HIT_IMMUNE;
                spell->m_damage = 0;
                // World of Warcraft Client Patch 1.11.0 (2006-06-20)
                // - Chain targeted spells and abilities (e.g. Multi-shot, Cleave, Chain 
                //   Lightning) will no longer land if target cannot be seen by the caster
                //   due to stealth or invisibility.
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_10_2
                MaNGOS::AnyAoEVisibleTargetUnitInObjectRangeCheck u_check(pUnitTarget, originalCaster, max_range);
                MaNGOS::UnitListSearcher<MaNGOS::AnyAoEVisibleTargetUnitInObjectRangeCheck> searcher(tempTargetUnitMap, u_check);
#else
                MaNGOS::AnyAoETargetUnitInObjectRangeCheck u_check(pUnitTarget, originalCaster, max_range);
                MaNGOS::UnitListSearcher<MaNGOS::AnyAoETargetUnitInObjectRangeCheck> searcher(tempTargetUnitMap, u_check);
#endif
                Cell::VisitAllObjects(m_caster, searcher, max_range);

                tempTargetUnitMap.sort(TargetDistanceOrderNear(pUnitTarget));

                // no packet found in sniffs
            }
            else
            {
                caster->SetLastDamagedTargetGuid(spell->unitTarget->GetGUID());

                // Add bonuses and fill damageInfo struct
                caster->CalculateSpellDamageTaken(&damageInfo, spell->m_damage, spell->m_spellInfo, spell->m_attackType, IsCrit, MissCondition == SPELL_MISS_BLOCK, spell);
                Unit::DealDamageMods(damageInfo.attacker, damageInfo.target, damageInfo.damage, &damageInfo.absorb);
                if (tempTargetUnitMap.empty())
                    break;

                hitMask |= createProcHitMask(&damageInfo, MissCondition);
                procVictim |= PROC_FLAG_TAKE_ANY_DAMAGE;
                if (*tempTargetUnitMap.begin() == pUnitTarget)
                    tempTargetUnitMap.erase(tempTargetUnitMap.begin());

                spell->m_damage = damageInfo.damage;
                targetUnitMap.push_back(pUnitTarget);
                uint32 t = unMaxTargets - 1;
                Unit* prev = pUnitTarget;
                auto next = tempTargetUnitMap.begin();

                caster->DealSpellDamage(&damageInfo, true);
                while (t && next != tempTargetUnitMap.end())
                {
                    if (!prev->IsWithinDist(*next, CHAIN_SPELL_JUMP_RADIUS))
                        break;

                // Send log damage message to client
                caster->SendSpellNonMeleeDamageLog(&damageInfo);
            }
                    if (!(m_spellInfo->AttributesEx2 & SPELL_ATTR_EX2_IGNORE_LOS) && !prev->IsWithinLOSInMap(*next))
                    {
                        ++next;
                        continue;
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
            SpellNonMeleeDamage damageInfo(caster, spell->unitTarget, spell->m_spellInfo, spell->m_SpellVisual, spell->m_spellSchoolMask);
            hitMask |= createProcHitMask(&damageInfo, MissCondition);
            // Do triggers for unit
            if (canEffectTrigger)
            {
                spellDamageInfo = std::make_unique<DamageInfo>(damageInfo, NODAMAGE, spell->m_attackType, hitMask);
                procSpellType |= PROC_SPELL_TYPE_NO_DMG_HEAL;
            }
                    if ((m_spellInfo->AttributesEx3 & SPELL_ATTR_EX3_TARGET_ONLY_PLAYER) && ((*next)->GetTypeId() != TYPEID_PLAYER))
                    {
                        ++next;
                        continue;
                    }

                    prev = *next;
                    targetUnitMap.push_back(prev);
                    tempTargetUnitMap.erase(next);
                    tempTargetUnitMap.sort(TargetDistanceOrderNear(prev));
                    next = tempTargetUnitMap.begin();

                    --t;
                }
            }
            break;
        }
        case TARGET_ENUM_UNITS_ENEMY_AOE_AT_SRC_LOC:
        {
            FillAreaTargets(targetUnitMap, radius, PUSH_DEST_CENTER, SPELL_TARGETS_AOE_DAMAGE);
            float minDist = -1;

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
            switch (m_spellInfo->Id)
            {
                // Shadow Storm
                case 14297:
                case 26546:
                case 26555:
                    minDist = 20.0f;
                    break;
            }
#endif

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
                procAttacker = ProcFlagsInit(PROC_FLAG_NONE, PROC_FLAG_2_NONE);

            if (spell->m_spellInfo->HasAttribute(SPELL_ATTR3_SUPPRESS_TARGET_PROCS))
                procVictim = ProcFlagsInit(PROC_FLAG_NONE, PROC_FLAG_2_NONE);

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
                unitCaster->AtTargetAttacked(unit, spell->m_spellInfo->HasInitialAggro());

                if (spell->m_spellInfo->HasAttribute(SPELL_ATTR6_TAPS_IMMEDIATELY))
                    if (Creature* targetCreature = unit->ToCreature())
                        if (unitCaster->IsPlayer())
                            targetCreature->SetTappedBy(unitCaster);
            }

            if (!spell->m_spellInfo->HasAttribute(SPELL_ATTR3_DO_NOT_TRIGGER_TARGET_STAND) && !unit->IsStandState())
                unit->SetStandState(UNIT_STAND_STATE_STAND);
        }
            if (minDist > 0)
            {
                for (UnitList::iterator itr = targetUnitMap.begin(), next; itr != targetUnitMap.end(); itr = next)
                {
                    next = itr;
                    ++next;
                    if (!*itr)
                        continue;
                    if ((*itr)->IsWithinDist(m_caster, minDist))
                        targetUnitMap.erase(itr);
                }
            }
            if (SelectClosestTargets && unMaxTargets && targetUnitMap.size() > unMaxTargets)
            {
                targetUnitMap.sort(TargetDistanceOrderNear(m_caster));
                UnitList::iterator itr = targetUnitMap.begin();
                advance(itr, unMaxTargets);
                targetUnitMap.erase(itr, targetUnitMap.end());
            }
            break;
        }
        case TARGET_ENUM_UNITS_SCRIPT_AOE_AT_SRC_LOC:
        {
            UnitList tempTargetUnitMap;
            SpellScriptTargetBounds bounds = sSpellMgr.GetSpellScriptTargetBounds(m_spellInfo->Id);

        // Check for SPELL_ATTR7_INTERRUPT_ONLY_NONPLAYER
        if (MissCondition == SPELL_MISS_NONE && spell->m_spellInfo->HasAttribute(SPELL_ATTR7_INTERRUPT_ONLY_NONPLAYER) && unit->GetTypeId() != TYPEID_PLAYER)
            caster->CastSpell(unit, SPELL_INTERRUPT_NONPLAYER, spell);
    }
            // fill real target list if no spell script target defined
            FillAreaTargets(bounds.first != bounds.second ? tempTargetUnitMap : targetUnitMap,
                            radius, PUSH_DEST_CENTER, SPELL_TARGETS_ALL);

    if (_spellHitTarget)
    {
        //AI functions
        if (Creature* cHitTarget = _spellHitTarget->ToCreature())
            if (CreatureAI* hitTargetAI = cHitTarget->AI())
                hitTargetAI->SpellHit(spell->m_caster, spell->m_spellInfo);
            if (!tempTargetUnitMap.empty())
            {
                for (const auto iter : tempTargetUnitMap)
                {
                    if (iter->GetTypeId() != TYPEID_UNIT)
                        continue;

        if (spell->m_caster->GetTypeId() == TYPEID_UNIT && spell->m_caster->ToCreature()->IsAIEnabled())
            spell->m_caster->ToCreature()->AI()->SpellHitTarget(_spellHitTarget, spell->m_spellInfo);
        else if (spell->m_caster->GetTypeId() == TYPEID_GAMEOBJECT && spell->m_caster->ToGameObject()->AI())
            spell->m_caster->ToGameObject()->AI()->SpellHitTarget(_spellHitTarget, spell->m_spellInfo);
                    for (SpellScriptTarget::const_iterator i_spellST = bounds.first; i_spellST != bounds.second; ++i_spellST)
                    {
                        if (i_spellST->second.CanNotHitWithSpellEffect(effIndex))
                            continue;

        if (HitAura)
        {
            if (AuraApplication* aurApp = HitAura->GetApplicationOfTarget(_spellHitTarget->GetGUID()))
            {
                // only apply unapplied effects (for reapply case)
                uint32 effMask = EffectMask & aurApp->GetEffectsToApply();
                for (uint8 i = 0; i < spell->m_spellInfo->GetEffects().size(); ++i)
                    if ((effMask & (1 << i)) && aurApp->HasEffect(i))
                        effMask &= ~(1 << i);

                if (effMask)
                    _spellHitTarget->_ApplyAura(aurApp, effMask);
            }
        }

        // Needs to be called after dealing damage/healing to not remove breaking on damage auras
        spell->DoTriggersOnSpellHit(_spellHitTarget);
    }
                        // only creature entries supported for this target type
                        if (i_spellST->second.type == SPELL_TARGET_TYPE_GAMEOBJECT)
                            continue;

    if (_enablePVP)
        spell->m_caster->ToPlayer()->UpdatePvP(true);
                        if (iter->GetEntry() == i_spellST->second.targetEntry)
                        {
                            if (i_spellST->second.type == SPELL_TARGET_TYPE_DEAD && ((Creature*)iter)->IsCorpse())
                                targetUnitMap.push_back(iter);
                            else if (i_spellST->second.type == SPELL_TARGET_TYPE_CREATURE && iter->IsAlive())
                                targetUnitMap.push_back(iter);

    spell->_spellAura = HitAura;
    spell->CallScriptAfterHitHandlers();
    spell->_spellAura = nullptr;
}

void Spell::GOTargetInfo::DoTargetSpellHit(Spell* spell, SpellEffectInfo const& spellEffectInfo)
{
    GameObject* go = spell->m_caster->GetGUID() == TargetGUID ? spell->m_caster->ToGameObject() : ObjectAccessor::GetGameObject(*spell->m_caster, TargetGUID);
    if (!go)
        return;

    spell->CallScriptBeforeHitHandlers(SPELL_MISS_NONE);

    spell->HandleEffects(nullptr, nullptr, go, nullptr, spellEffectInfo, SPELL_EFFECT_HANDLE_HIT_TARGET);

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
                            break;
                        }
                    }
                }
            }

void Spell::ItemTargetInfo::DoTargetSpellHit(Spell* spell, SpellEffectInfo const& spellEffectInfo)
{
    spell->CallScriptBeforeHitHandlers(SPELL_MISS_NONE);

    spell->HandleEffects(nullptr, TargetItem, nullptr, nullptr, spellEffectInfo, SPELL_EFFECT_HANDLE_HIT_TARGET);

    spell->CallScriptOnHitHandlers();
    spell->CallScriptAfterHitHandlers();
}

void Spell::CorpseTargetInfo::DoTargetSpellHit(Spell* spell, SpellEffectInfo const& spellEffectInfo)
{
    Corpse* corpse = ObjectAccessor::GetCorpse(*spell->m_caster, TargetGUID);
    if (!corpse)
        return;

    spell->CallScriptBeforeHitHandlers(SPELL_MISS_NONE);

    spell->HandleEffects(nullptr, nullptr, nullptr, corpse, spellEffectInfo, SPELL_EFFECT_HANDLE_HIT_TARGET);

    spell->CallScriptOnHitHandlers();
    spell->CallScriptAfterHitHandlers();
}

SpellMissInfo Spell::PreprocessSpellHit(Unit* unit, TargetInfo& hitInfo)
{
    if (!unit)
        return SPELL_MISS_EVADE;

    // Target may have begun evading between launch and hit phases - re-check now
    if (Creature* creatureTarget = unit->ToCreature())
        if (creatureTarget->IsEvadingAttacks())
            return SPELL_MISS_EVADE;

    // For delayed spells immunity may be applied between missile launch and hit - check immunity for that case
    if (m_spellInfo->HasHitDelay() && unit->IsImmunedToSpell(m_spellInfo, m_caster))
        return SPELL_MISS_IMMUNE;

    CallScriptBeforeHitHandlers(hitInfo.MissCondition);
            // exclude caster
            if (m_casterUnit)
                targetUnitMap.remove(m_casterUnit);
            break;
        }
        case TARGET_ENUM_UNITS_SCRIPT_AOE_AT_DEST_LOC:
        {
            if (m_spellInfo->Effect[effIndex] == SPELL_EFFECT_PERSISTENT_AREA_AURA)
                break;
            else if (m_spellInfo->Effect[effIndex] == SPELL_EFFECT_SUMMON || m_spellInfo->Effect[effIndex] == SPELL_EFFECT_SUMMON_WILD || m_spellInfo->Effect[effIndex] == SPELL_EFFECT_SUMMON_OBJECT_WILD)
            {
                if (m_casterUnit)
                    targetUnitMap.push_back(m_casterUnit);
                break;
            }

    if (Player* player = unit->ToPlayer())
    {
        player->StartCriteriaTimer(CriteriaStartEvent::BeSpellTarget, m_spellInfo->Id);
        player->UpdateCriteria(CriteriaType::BeSpellTarget, m_spellInfo->Id, 0, 0, m_caster);
        player->UpdateCriteria(CriteriaType::GainAura, m_spellInfo->Id);
    }
            UnitList tempTargetUnitMap;
            SpellScriptTargetBounds bounds = sSpellMgr.GetSpellScriptTargetBounds(m_spellInfo->Id);
            // fill real target list if no spell script target defined
            FillAreaTargets(bounds.first != bounds.second ? tempTargetUnitMap : targetUnitMap, radius, PUSH_DEST_CENTER, SPELL_TARGETS_ALL);

            if (!tempTargetUnitMap.empty())
            {
                for (const auto iter : tempTargetUnitMap)
                {
                    if (iter->GetTypeId() != TYPEID_UNIT)
                        continue;

    if (Player* player = m_caster->ToPlayer())
    {
        player->StartCriteriaTimer(CriteriaStartEvent::CastSpell, m_spellInfo->Id);
        player->UpdateCriteria(CriteriaType::LandTargetedSpellOnTarget, m_spellInfo->Id, 0, 0, unit);
    }
                    for (SpellScriptTarget::const_iterator i_spellST = bounds.first; i_spellST != bounds.second; ++i_spellST)
                    {
                        if (i_spellST->second.CanNotHitWithSpellEffect(effIndex))
                            continue;

                        // only creature entries supported for this target type
                        if (i_spellST->second.type == SPELL_TARGET_TYPE_GAMEOBJECT)
                            continue;

        if (m_caster->IsValidAttackTarget(unit, m_spellInfo))
            unit->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::HostileActionReceived);
        else if (m_caster->IsFriendlyTo(unit))
        {
            // for delayed spells ignore negative spells (after duel end) for friendly targets
            if (m_spellInfo->HasHitDelay() && unit->GetTypeId() == TYPEID_PLAYER && !IsPositive() && !m_caster->IsValidAssistTarget(unit, m_spellInfo))
                return SPELL_MISS_EVADE;
                        if (iter->GetEntry() == i_spellST->second.targetEntry)
                        {
                            if (i_spellST->second.type == SPELL_TARGET_TYPE_DEAD && ((Creature*)iter)->IsCorpse())
                                targetUnitMap.push_back(iter);
                            else if (i_spellST->second.type == SPELL_TARGET_TYPE_CREATURE && iter->IsAlive())
                                targetUnitMap.push_back(iter);

                            break;
                        }
                    }
                }
            }

            if (m_originalCaster && unit->IsInCombat() && m_spellInfo->HasInitialAggro())
            {
                if (m_originalCaster->HasUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED))               // only do explicit combat forwarding for PvP enabled units
                    m_originalCaster->GetCombatManager().InheritCombatStatesFrom(unit);    // for creature v creature combat, the threat forward does it for us
                unit->GetThreatManager().ForwardThreatForAssistingMe(m_originalCaster, 0.0f, nullptr, true);
            }
        }
    }
            else
            {
                // remove not targetable units if spell has no script targets
                for (UnitList::iterator itr = targetUnitMap.begin(); itr != targetUnitMap.end();)
                {
                    if (!(*itr)->IsTargetable(true, m_caster->IsCharmerOrOwnerPlayerOrPlayerItself(), true, false) || !m_spellInfo->CanTargetAliveState((*itr)->IsAlive()))
                        targetUnitMap.erase(itr++);
                    else
                        ++itr;
                }
            }
            break;
        }
        case TARGET_ENUM_GAMEOBJECTS_SCRIPT_AOE_AT_SRC_LOC:
        case TARGET_ENUM_GAMEOBJECTS_SCRIPT_AOE_AT_DEST_LOC:
        {
            float x, y, z;
            if (targetMode == TARGET_ENUM_GAMEOBJECTS_SCRIPT_AOE_AT_SRC_LOC)
                m_targets.getSource(x, y, z);
            else
                m_targets.getDestination(x, y, z);

            if (x == 0.0f && y == 0.0f && z == 0.0f)
                sLog.outError("Coordinates were not set properly for spell %u with target type %u!", m_spellInfo->Id, targetMode);

            // It may be possible to fill targets for some spell effects
            // automatically (SPELL_EFFECT_WMO_REPAIR(88) for example) but
            // for some/most spells we clearly need/want to limit with spell_target_script

            // Some spells untested, for affected GO type 33. May need further adjustments for spells related.

            SpellScriptTargetBounds bounds = sSpellMgr.GetSpellScriptTargetBounds(m_spellInfo->Id);

            std::list<GameObject*> tempTargetGOList;

    // original caster for auras
    WorldObject* origCaster = m_caster;
    if (m_originalCaster)
        origCaster = m_originalCaster;

    // check immunity due to diminishing returns
    if (Aura::BuildEffectMaskForOwner(m_spellInfo, MAX_EFFECT_MASK, unit))
    {
        for (SpellEffectInfo const& auraSpellEffect : m_spellInfo->GetEffects())
            hitInfo.AuraBasePoints[auraSpellEffect.EffectIndex] = (m_spellValue->CustomBasePointsMask & (1 << auraSpellEffect.EffectIndex))
            ? m_spellValue->EffectBasePoints[auraSpellEffect.EffectIndex]
            : auraSpellEffect.CalcBaseValue(m_originalCaster, unit, m_castItemEntry, m_castItemLevel);
            for (SpellScriptTarget::const_iterator i_spellST = bounds.first; i_spellST != bounds.second; ++i_spellST)
            {
                if (i_spellST->second.CanNotHitWithSpellEffect(effIndex))
                    continue;

        // Get Data Needed for Diminishing Returns, some effects may have multiple auras, so this must be done on spell hit, not aura add
        hitInfo.DRGroup = m_spellInfo->GetDiminishingReturnsGroupForSpell();
                if (i_spellST->second.type == SPELL_TARGET_TYPE_GAMEOBJECT)
                {
                    // search all GO's with entry, within range of m_destN
                    MaNGOS::GameObjectEntryInPosRangeCheck go_check(*m_caster, i_spellST->second.targetEntry, x, y, z, radius);
                    MaNGOS::GameObjectListSearcher<MaNGOS::GameObjectEntryInPosRangeCheck> checker(tempTargetGOList, go_check);
                    Cell::VisitGridObjects(m_caster, checker, radius);
                }
            }

        DiminishingLevels diminishLevel = DIMINISHING_LEVEL_1;
        if (hitInfo.DRGroup)
        {
            diminishLevel = unit->GetDiminishing(hitInfo.DRGroup);
            DiminishingReturnsType type = m_spellInfo->GetDiminishingReturnsGroupType();
            // Increase Diminishing on unit, current informations for actually casts will use values above
            if (type == DRTYPE_ALL || (type == DRTYPE_PLAYER && unit->IsAffectedByDiminishingReturns()))
                unit->IncrDiminishing(m_spellInfo);
        }
            if (!tempTargetGOList.empty())
            {
                for (const auto& iter : tempTargetGOList)
                    AddGOTarget(iter, effIndex);
            }

        // Now Reduce spell duration using data received at spell hit
        // check whatever effects we're going to apply, diminishing returns only apply to negative aura effects
        hitInfo.Positive = true;
        if (origCaster == unit || !origCaster->IsFriendlyTo(unit))
        {
            for (SpellEffectInfo const& auraSpellEffect : m_spellInfo->GetEffects())
            {
                // mod duration only for effects applying aura!
                if (hitInfo.EffectMask & (1 << auraSpellEffect.EffectIndex) &&
                    auraSpellEffect.IsUnitOwnedAuraEffect() &&
                    !m_spellInfo->IsPositiveEffect(auraSpellEffect.EffectIndex))
                {
                    hitInfo.Positive = false;
                    break;
                }
            }
        }
            break;
        }
        case TARGET_ENUM_UNITS_ENEMY_AOE_AT_DEST_LOC:
        {
            // targets the ground, not the units in the area
            switch (m_spellInfo->Effect[effIndex])
            {
                case SPELL_EFFECT_PERSISTENT_AREA_AURA:
                    break;
                case SPELL_EFFECT_SUMMON:
                    if (m_casterUnit)
                        targetUnitMap.push_back(m_casterUnit);
                    break;
                default:
                    FillAreaTargets(targetUnitMap, radius, PUSH_DEST_CENTER, SPELL_TARGETS_AOE_DAMAGE);
                    break;
            }
            break;
        }
        case TARGET_LOCATION_UNIT_POSITION:
        {
            if (Unit* currentTarget = m_targets.getUnitTarget())
                m_targets.setDestination(currentTarget->GetPositionX(), currentTarget->GetPositionY(), currentTarget->GetPositionZ());
            break;
        }
        case TARGET_ENUM_UNITS_PARTY_WITHIN_CASTER_RANGE:
        case TARGET_ENUM_UNITS_PARTY_AOE_AT_DEST_LOC:
        case TARGET_ENUM_UNITS_PARTY_AOE_AT_SRC_LOC:
            if (m_casterUnit)
                FillRaidOrPartyTargets(targetUnitMap, m_casterUnit, radius, false, true, true);
            break;
        case TARGET_ENUM_UNITS_RAID_WITHIN_CASTER_RANGE:
            if (m_casterUnit)
                FillRaidOrPartyTargets(targetUnitMap, m_casterUnit, radius, true, true, false);
            break;
        case TARGET_UNIT_FRIEND:
        case TARGET_UNIT_RAID:
            if (m_targets.getUnitTarget())
                targetUnitMap.push_back(m_targets.getUnitTarget());
            break;
        case TARGET_LOCATION_CASTER_SRC:
        {
            // Check original caster is GO - set its coordinates as src cast
            if (SpellCaster* caster = GetCastingObject())
                m_targets.setSource(caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ());
            break;
        }
        case TARGET_ENUM_UNITS_ENEMY_WITHIN_CASTER_RANGE:
            FillAreaTargets(targetUnitMap, radius, PUSH_SELF_CENTER, SPELL_TARGETS_HOSTILE);
            break;
        case TARGET_ENUM_UNITS_FRIEND_AOE_AT_SRC_LOC:
            // selected friendly units (for casting objects) around casting object
            FillAreaTargets(targetUnitMap, radius, PUSH_SELF_CENTER, SPELL_TARGETS_FRIENDLY, GetCastingObject());
            break;
        case TARGET_ENUM_UNITS_FRIEND_AOE_AT_DEST_LOC:
            FillAreaTargets(targetUnitMap, radius, PUSH_DEST_CENTER, SPELL_TARGETS_FRIENDLY);
            break;
        // TARGET_UNIT_PARTY means that the spells can only be casted on a party member and not on the caster (some seals, fire shield from imp, etc..)
        case TARGET_UNIT_PARTY:
        {
            Unit* target = m_targets.getUnitTarget();
            // Those spells apparently can't be casted on the caster.
            if (target && target != m_caster)
            {
                // Can only be casted on group's members or its pets
                Group  *pGroup = nullptr;

                Unit* owner = m_casterUnit ? m_casterUnit->GetCharmerOrOwner() : nullptr;
                Unit* targetOwner = target->GetCharmerOrOwner();
                if (owner)
                {
                    if (owner->IsPlayer())
                    {
                        if (target == owner)
                        {
                            targetUnitMap.push_back(target);
                            break;
                        }
                        pGroup = ((Player*)owner)->GetGroup();
                    }
                }
                else if (m_caster->IsPlayer())
                {
                    if (targetOwner == m_caster && target->IsCreature() && ((Creature*)target)->IsPet())
                    {
                        targetUnitMap.push_back(target);
                        break;
                    }
                    pGroup = ((Player*)m_caster)->GetGroup();
                }

        hitInfo.AuraDuration = Aura::CalcMaxDuration(m_spellInfo, origCaster);

        // unit is immune to aura if it was diminished to 0 duration
        if (!hitInfo.Positive && !unit->ApplyDiminishingToDuration(m_spellInfo, hitInfo.AuraDuration, origCaster, diminishLevel))
            if (std::all_of(std::begin(m_spellInfo->GetEffects()), std::end(m_spellInfo->GetEffects()), [](SpellEffectInfo const& effInfo) { return !effInfo.IsEffect() || effInfo.Effect == SPELL_EFFECT_APPLY_AURA; }))
                return SPELL_MISS_IMMUNE;
    }

    return SPELL_MISS_NONE;
}

void Spell::DoSpellEffectHit(Unit* unit, SpellEffectInfo const& spellEffectInfo, TargetInfo& hitInfo)
{
    if (uint32 aura_effmask = Aura::BuildEffectMaskForOwner(m_spellInfo, 1 << spellEffectInfo.EffectIndex, unit))
    {
        WorldObject* caster = m_caster;
        if (m_originalCaster)
            caster = m_originalCaster;

        if (caster)
        {
            bool refresh = false;

            if (!hitInfo.HitAura)
            {
                bool const resetPeriodicTimer = (m_spellInfo->StackAmount < 2) && !(_triggeredCastFlags & TRIGGERED_DONT_RESET_PERIODIC_TIMER);
                uint32 const allAuraEffectMask = Aura::BuildEffectMaskForOwner(m_spellInfo, MAX_EFFECT_MASK, unit);

                AuraCreateInfo createInfo(m_castId, m_spellInfo, GetCastDifficulty(), allAuraEffectMask, unit);
                createInfo
                    .SetCasterGUID(caster->GetGUID())
                    .SetBaseAmount(&hitInfo.AuraBasePoints[0])
                    .SetCastItem(m_castItemGUID, m_castItemEntry, m_castItemLevel)
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

                    if (!m_spellValue->Duration)
                    {
                        hitInfo.AuraDuration = caster->ModSpellDuration(m_spellInfo, unit, hitInfo.AuraDuration, hitInfo.Positive, hitInfo.HitAura->GetEffectMask());
                if (pGroup)
                {
                    // Our target can also be a player's pet who's grouped with us or our pet. But can't be controlled player
                    if (targetOwner)
                    {
                        if (targetOwner->IsPlayer() &&
                                target->IsCreature() && (((Creature*)target)->IsPet()) &&
                                target->GetOwnerGuid() == targetOwner->GetObjectGuid() &&
                                pGroup->IsMember(((Player*)targetOwner)->GetObjectGuid()))
                            targetUnitMap.push_back(target);
                    }
                    // 1Our target can be a player who is on our group
                    else if (target->IsPlayer() && pGroup->IsMember(((Player*)target)->GetObjectGuid()))
                        targetUnitMap.push_back(target);
                }
            }
            break;
        }
        case TARGET_GAMEOBJECT:
            if (m_targets.getGOTarget())
                AddGOTarget(m_targets.getGOTarget(), effIndex);
            break;
        case TARGET_ENUM_UNITS_ENEMY_IN_CONE_24:
        {
            SpellNotifyPushType pushType = PUSH_IN_FRONT;
            switch (m_spellInfo->SpellVisual)            // Some spell require a different target fill
            {
                case 3879:
                    pushType = PUSH_IN_BACK;
                    break;
                case 7441:
                    pushType = PUSH_IN_FRONT_15;
                    break;
                case 7619: // anub impale
                    pushType = PUSH_IN_FRONT_15;
                    break;
            }
            FillAreaTargets(targetUnitMap, radius, pushType, SPELL_TARGETS_AOE_DAMAGE);
            break;
        }
        case TARGET_ENUM_UNITS_ENEMY_IN_CONE_54:
        {
            switch (m_spellInfo->Id)
            {
            case 24820:
            case 24821:
            case 24822:
            case 24823:
            case 24835:
            case 24836:
            case 24837:
            case 24838:
            {
                UnitList tempTargetUnitMap;
                FillAreaTargets(tempTargetUnitMap, radius, PUSH_SELF_CENTER, SPELL_TARGETS_AOE_DAMAGE);

                        if (hitInfo.AuraDuration > 0)
                        {
                            hitInfo.AuraDuration *= m_spellValue->DurationMul;
                for (const auto itr : tempTargetUnitMap)
                {
                    float angle;
                    float arc;

                            // Haste modifies duration of channeled spells
                            if (m_spellInfo->IsChanneled())
                                caster->ModSpellDurationTime(m_spellInfo, hitInfo.AuraDuration, this);
                            else if (m_spellInfo->HasAttribute(SPELL_ATTR8_HASTE_AFFECTS_DURATION))
                            {
                                int32 origDuration = hitInfo.AuraDuration;
                                hitInfo.AuraDuration = 0;
                                for (AuraEffect const* auraEff : hitInfo.HitAura->GetAuraEffects())
                                    if (auraEff)
                                        if (int32 period = auraEff->GetPeriod())  // period is hastened by UNIT_MOD_CAST_SPEED
                                            hitInfo.AuraDuration = std::max(std::max(origDuration / period, 1) * period, hitInfo.AuraDuration);
                    switch (m_spellInfo->Id)
                    {
                        case 24820:
                            angle = 0.0f * M_PI_F / 4.0f;
                            arc = 2.0f * M_PI_F / 3.0f;
                            break;
                        case 24821:
                            angle = 1.0f * M_PI_F / 4.0f;
                            arc = 2.0f * M_PI_F / 3.0f;
                            break;
                        case 24822:
                            angle = 2.0f * M_PI_F / 4.0f;
                            arc = 2.0f * M_PI_F / 3.0f;
                            break;
                        case 24823:
                            angle = 3.0f * M_PI_F / 4.0f;
                            arc = 2.0f * M_PI_F / 3.0f;
                            break;
                        case 24835:
                            angle = -4.0f * M_PI_F / 4.0f;
                            arc = 2.0f * M_PI_F / 3.0f;
                            break;
                        case 24836:
                            angle = -3.0f * M_PI_F / 4.0f;
                            arc = 2.0f * M_PI_F / 3.0f;
                            break;
                        case 24837:
                            angle = -2.0f * M_PI_F / 4.0f;
                            arc = 2.0f * M_PI_F / 3.0f;
                            break;
                        case 24838:
                            angle = -1.0f * M_PI_F / 4.0f;
                            arc = 2.0f * M_PI_F / 3.0f;
                            break;
                        default:
                            angle = 0.0f;
                            arc = M_PI_F / 2.0f;
                            break;
                    }

                                // if there is no periodic effect
                                if (!hitInfo.AuraDuration)
                                    hitInfo.AuraDuration = int32(origDuration * m_originalCaster->m_unitData->ModCastingSpeed);
                            }
                        }
                    }
                    else
                        hitInfo.AuraDuration = *m_spellValue->Duration;
                    if (m_caster->HasInArc(itr, arc, angle))
                        targetUnitMap.push_back(itr);                
                }

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
                break;
            }                
            default:
                FillAreaTargets(targetUnitMap, radius, PUSH_IN_FRONT_90, SPELL_TARGETS_AOE_DAMAGE);
                break;
            }

            break;
        }            
        case TARGET_ENUM_UNITS_SCRIPT_IN_CONE_60:
        {
            SpellTargets targetB = SPELL_TARGETS_AOE_DAMAGE;

            if (m_spellInfo->Effect[effIndex] == SPELL_EFFECT_SCRIPT_EFFECT)
                targetB = SPELL_TARGETS_ALL;

    _spellAura = hitInfo.HitAura;
    HandleEffects(unit, nullptr, nullptr, nullptr, spellEffectInfo, SPELL_EFFECT_HANDLE_HIT_TARGET);
    _spellAura = nullptr;
}
            UnitList tempTargetUnitMap;
            SpellScriptTargetBounds bounds = sSpellMgr.GetSpellScriptTargetBounds(m_spellInfo->Id);

            // fill real target list if no spell script target defined
            FillAreaTargets(bounds.first != bounds.second ? tempTargetUnitMap : targetUnitMap,
                radius, PUSH_IN_FRONT_15, bounds.first != bounds.second ? SPELL_TARGETS_ALL : targetB);

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
                m_caster->CastSpell(unit, i->triggeredSpell->Id, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                    .SetTriggeringSpell(this)
                    .SetCastDifficulty(i->triggeredSpell->Difficulty));
                TC_LOG_DEBUG("spells", "Spell {} triggered spell {} by SPELL_AURA_ADD_TARGET_TRIGGER aura", m_spellInfo->Id, i->triggeredSpell->Id);
            if (!tempTargetUnitMap.empty())
            {
                for (const auto& iter : tempTargetUnitMap)
                {
                    if (iter->GetTypeId() != TYPEID_UNIT)
                        continue;

                    if (iter == GetCaster())
                        continue;

                    for (auto i_spellST = bounds.first; i_spellST != bounds.second; ++i_spellST)
                    {
                        // only creature entries supported for this target type
                        if (i_spellST->second.type == SPELL_TARGET_TYPE_GAMEOBJECT)
                            continue;

                        if (iter->GetEntry() == i_spellST->second.targetEntry)
                        {
                            if (i_spellST->second.type == SPELL_TARGET_TYPE_DEAD && ((Creature*)iter)->IsCorpse())
                            {
                                targetUnitMap.push_back(iter);
                            }
                            else if (i_spellST->second.type == SPELL_TARGET_TYPE_CREATURE && iter->IsAlive())
                            {
                                targetUnitMap.push_back(iter);
                            }
                            break;
                        }
                    }
                }
            }
            break;
        }
        case TARGET_UNIT:
        {
            Unit* target = m_targets.getUnitTarget();
            // This target should be checked depending on the effect
            // (check for PvP ON/OFF, ...)
            if (target)
                targetUnitMap.push_back(target);
            break;
        }
        case TARGET_LOCKED:
            if (m_targets.getGOTargetGuid())
                AddGOTarget(m_targets.getGOTarget(), effIndex);
            else if (m_targets.getItemTarget())
                AddItemTarget(m_targets.getItemTarget(), effIndex);
            break;
        case TARGET_UNIT_CASTER_MASTER:
            if (Unit* owner = m_casterUnit ? m_casterUnit->GetCharmerOrOwner() : nullptr)
                targetUnitMap.push_back(owner);
            break;
        case TARGET_ENUM_UNITS_ENEMY_AOE_AT_DYNOBJ_LOC:
            // targets the ground, not the units in the area
            if (m_spellInfo->Effect[effIndex] != SPELL_EFFECT_PERSISTENT_AREA_AURA)
                FillAreaTargets(targetUnitMap, radius, PUSH_DEST_CENTER, SPELL_TARGETS_AOE_DAMAGE);
            break;
        case TARGET_UNIT_FRIEND_AND_PARTY:
        {
            Unit* owner = m_casterUnit ? m_casterUnit->GetCharmerOrOwner() : nullptr;
            Player* pTarget = nullptr;

    // trigger linked auras remove/apply
    /// @todo remove/cleanup this, as this table is not documented and people are doing stupid things with it
    if (std::vector<int32> const* spellTriggered = sSpellMgr->GetSpellLinked(SPELL_LINK_HIT, m_spellInfo->Id))
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
            if (owner)
            {
                if (m_casterUnit)
                    targetUnitMap.push_back(m_casterUnit);
                if (owner->IsPlayer())
                    pTarget = (Player*)owner;
            }
            else if (m_caster->IsPlayer())
            {
                if (Unit* target = m_targets.getUnitTarget())
                {
                    if (target->GetTypeId() != TYPEID_PLAYER)
                    {
                        if (((Creature*)target)->IsPet())
                        {
                            Unit* targetOwner = target->GetOwner();
                            if (targetOwner->IsPlayer())
                                pTarget = (Player*)targetOwner;
                        }
                    }
                    else
                        pTarget = (Player*)target;
                }
            }

            Group* pGroup = pTarget ? pTarget->GetGroup() : nullptr;

            if (pGroup)
            {
                uint8 subgroup = pTarget->GetSubGroup();

                for (GroupReference* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
                {
                    Player* target = itr->getSource();

                    // IsHostileTo check duel and controlled by enemy
                    if (target && target->GetSubGroup() == subgroup && target->GetLevel() + 10 >= m_spellInfo->spellLevel && !m_caster->IsHostileTo(target))
                    {
                        if (pTarget->IsWithinDistInMap(target, radius))
                            targetUnitMap.push_back(target);

                        if (Pet* pet = target->GetPet())
                            if (pTarget->IsWithinDistInMap(pet, radius))
                                targetUnitMap.push_back(pet);
                    }
                }
            }
            else if (owner)
            {
                if (m_caster->IsWithinDistInMap(owner, radius))
                    targetUnitMap.push_back(owner);
            }
            else if (pTarget)
            {
                targetUnitMap.push_back(pTarget);

                if (Pet* pet = pTarget->GetPet())
                    if (m_caster->IsWithinDistInMap(pet, radius))
                        targetUnitMap.push_back(pet);
            }
            break;
        }
        case TARGET_UNIT_SCRIPT_NEAR_CASTER:
        {
            if (m_targets.getUnitTarget())
                targetUnitMap.push_back(m_targets.getUnitTarget());
            if (m_targets.getItemTarget())
                AddItemTarget(m_targets.getItemTarget(), effIndex);
            break;
        }
        case TARGET_LOCATION_CASTER_FISHING_SPOT:
            if (m_casterUnit)
                targetUnitMap.push_back(m_casterUnit);
            break;
        case TARGET_UNIT_FRIEND_CHAIN_HEAL:
        {
            Unit* pUnitTarget = m_targets.getUnitTarget();
            if (!pUnitTarget)
                break;

            if (EffectChainTarget <= 1)
                targetUnitMap.push_back(pUnitTarget);
            else
            {
                unMaxTargets = EffectChainTarget;
                float max_range = radius + unMaxTargets * CHAIN_SPELL_JUMP_RADIUS;

                UnitList tempTargetUnitMap;

                FillAreaTargets(tempTargetUnitMap, max_range, PUSH_SELF_CENTER, SPELL_TARGETS_FRIENDLY);

                if (m_casterUnit && m_casterUnit != pUnitTarget && std::find(tempTargetUnitMap.begin(), tempTargetUnitMap.end(), m_casterUnit) == tempTargetUnitMap.end())
                    tempTargetUnitMap.push_front(m_casterUnit);

    uint32 channelTargetEffectMask = m_channelTargetEffectMask;
    uint32 channelAuraMask = 0;
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
        if (spellEffectInfo.IsEffect(SPELL_EFFECT_APPLY_AURA))
            channelAuraMask |= 1 << spellEffectInfo.EffectIndex;
                tempTargetUnitMap.sort(TargetDistanceOrderNear(pUnitTarget));

                if (tempTargetUnitMap.empty())
                    break;

                if (*tempTargetUnitMap.begin() == pUnitTarget)
                    tempTargetUnitMap.erase(tempTargetUnitMap.begin());

                targetUnitMap.push_back(pUnitTarget);
                uint32 t = unMaxTargets - 1;
                Unit* prev = pUnitTarget;
                auto next = tempTargetUnitMap.begin();

    for (TargetInfo& targetInfo : m_UniqueTargetInfo)
    {
        if (targetInfo.MissCondition == SPELL_MISS_NONE && (channelTargetEffectMask & targetInfo.EffectMask))
        {
            Unit* unit = m_caster->GetGUID() == targetInfo.TargetGUID ? m_caster->ToUnit() : ObjectAccessor::GetUnit(*m_caster, targetInfo.TargetGUID);
            if (!unit)
            {
                if (Unit* unitCaster =m_caster->ToUnit())
                    unitCaster->RemoveChannelObject(targetInfo.TargetGUID);
                continue;
            }
                while (t && next != tempTargetUnitMap.end())
                {
                    if (!prev->IsWithinDist(*next, CHAIN_SPELL_JUMP_RADIUS))
                        break;

                    if (!(m_spellInfo->AttributesEx2 & SPELL_ATTR_EX2_IGNORE_LOS) && !prev->IsWithinLOSInMap(*next))
                    {
                        ++next;
                        continue;
                    }

            if (IsValidDeadOrAliveTarget(unit))
            {
                if (channelAuraMask & targetInfo.EffectMask)
                {
                    if (AuraApplication* aurApp = unit->GetAuraApplication(m_spellInfo->Id, m_originalCasterGUID))
                    {
                        if (m_caster != unit && !m_caster->IsWithinDistInMap(unit, range))
                        {
                            targetInfo.EffectMask &= ~aurApp->GetEffectMask();
                            unit->RemoveAura(aurApp);
                            if (Unit* unitCaster = m_caster->ToUnit())
                                unitCaster->RemoveChannelObject(targetInfo.TargetGUID);
                            continue;
                        }
                    }
                    else // aura is dispelled
                    {
                        if (Unit* unitCaster = m_caster->ToUnit())
                            unitCaster->RemoveChannelObject(targetInfo.TargetGUID);
                        continue;
                    }
                }
                    if ((*next)->GetHealth() == (*next)->GetMaxHealth())
                    {
                        next = tempTargetUnitMap.erase(next);
                        continue;
                    }

                    prev = *next;
                    targetUnitMap.push_back(prev);
                    tempTargetUnitMap.erase(next);
                    tempTargetUnitMap.sort(TargetDistanceOrderNear(prev));
                    next = tempTargetUnitMap.begin();

                    --t;
                }
            }
            break;
        }
        case TARGET_LOCATION_CASTER_TARGET_POSITION:
        {
            Unit* currentTarget = m_targets.getUnitTarget();
            if (currentTarget)
            {
                targetUnitMap.push_back(currentTarget);
                if (m_spellInfo->Id == 28863)        // Void Zone creature often end up below ground
                    m_targets.setDestination(currentTarget->GetPositionX(), currentTarget->GetPositionY(), currentTarget->GetPositionZ()+0.3f);
                else if (m_spellInfo->Id != 18392)   // Onyxia's Fireball - without a destination the spell uses its original spell visuals
                    m_targets.setDestination(currentTarget->GetPositionX(), currentTarget->GetPositionY(), currentTarget->GetPositionZ());
            }
            break;
        }
        case TARGET_UNIT_RAID_AND_CLASS:
        {
            Player* targetPlayer = m_targets.getUnitTarget() && m_targets.getUnitTarget()->IsPlayer()
                                   ? (Player*)m_targets.getUnitTarget() : nullptr;

            Group* pGroup = targetPlayer ? targetPlayer->GetGroup() : nullptr;
            if (pGroup)
            {
                for (GroupReference* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
                {
                    Player* Target = itr->getSource();

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

        if (Player* owner = m_CastItem->GetOwner())
            m_castItemLevel = int32(m_CastItem->GetItemLevel(owner));
        else if (m_CastItem->GetOwnerGUID() == m_caster->GetGUID())
            m_castItemLevel = int32(m_CastItem->GetItemLevel(m_caster->ToPlayer()));
        else
        {
            SendCastResult(SPELL_FAILED_EQUIPPED_ITEM);
            finish(false);
            return SPELL_FAILED_EQUIPPED_ITEM;
        }
    }

    InitExplicitTargets(targets);
                    // IsHostileTo check duel and controlled by enemy
                    if (Target && targetPlayer->IsWithinDistInMap(Target, radius) &&
                            targetPlayer->GetClass() == Target->GetClass() &&
                            !m_caster->IsHostileTo(Target))
                        targetUnitMap.push_back(Target);
                }
            }
            else if (m_targets.getUnitTarget())
                targetUnitMap.push_back(m_targets.getUnitTarget());
            break;
        }
        case TARGET_LOCATION_DATABASE:
        {
            SpellTargetPosition const* st = sSpellMgr.GetSpellTargetPosition(m_spellInfo->Id);
            if (st)
            {
                // teleportspells are handled in another way
                if (m_spellInfo->Effect[effIndex] == SPELL_EFFECT_TELEPORT_UNITS)
                    break;
                if (st->mapId == m_caster->GetMapId())
                    m_targets.setDestination(st->x, st->y, st->z);
                else
                    sLog.outError("SPELL: wrong map (%u instead %u) target coordinates for spell ID %u", st->mapId, m_caster->GetMapId(), m_spellInfo->Id);
            }
            else
                sLog.outError("SPELL: unknown target coordinates for spell ID %u", m_spellInfo->Id);
            break;
        }
        case TARGET_LOCATION_UNIT_MINION_POSITION: // unknown how pet summon is different - maybe some formation support?
        case TARGET_LOCATION_CASTER_FRONT_RIGHT:
        case TARGET_LOCATION_CASTER_BACK_RIGHT:
        case TARGET_LOCATION_CASTER_BACK_LEFT:
        case TARGET_LOCATION_CASTER_FRONT_LEFT:
        case TARGET_LOCATION_CASTER_FRONT:
        case TARGET_LOCATION_CASTER_BACK:
        case TARGET_LOCATION_CASTER_LEFT:
        case TARGET_LOCATION_CASTER_RIGHT:
        {     
            if (targetMode == TARGET_LOCATION_UNIT_MINION_POSITION && m_spellInfo->Effect[effIndex] == SPELL_EFFECT_DUEL)
                break;
        
            if (!(m_targets.m_targetMask & TARGET_FLAG_DEST_LOCATION))
            {
                // General override, we don't want to use max spell range here.
                // Note: 0.0 radius is also for index 36. It is possible that 36 must be defined as
                // "at the base of", in difference to 0 which appear to be "directly in front of".
                // TODO: some summoned will make caster be half inside summoned object. Need to fix
                // that in the below code (nearpoint vs closepoint, etc).
                if (m_spellInfo->EffectRadiusIndex[effIndex] == 0)
                    radius = 0.0f;

                float angle = m_caster->GetOrientation();
                switch (targetMode)
                {
                    case TARGET_LOCATION_UNIT_MINION_POSITION:
                    case TARGET_LOCATION_CASTER_FRONT_LEFT:  angle += M_PI_F * 0.25f; break;
                    case TARGET_LOCATION_CASTER_BACK_LEFT:   angle += M_PI_F * 0.75f; break;
                    case TARGET_LOCATION_CASTER_BACK_RIGHT:  angle += M_PI_F * 1.25f; break;
                    case TARGET_LOCATION_CASTER_FRONT_RIGHT: angle += M_PI_F * 1.75f; break;
                    case TARGET_LOCATION_CASTER_FRONT:                                break;
                    case TARGET_LOCATION_CASTER_BACK:        angle += M_PI_F;         break;
                    case TARGET_LOCATION_CASTER_LEFT:        angle += M_PI_F / 2;     break;
                    case TARGET_LOCATION_CASTER_RIGHT:       angle -= M_PI_F / 2;     break;
                }

    // create and add update event for this spell
    _spellEvent = new SpellEvent(this);
    m_caster->m_Events.AddEvent(_spellEvent, m_caster->m_Events.CalculateTime(1ms));
                float x, y, z;
                m_caster->GetNearPoint(m_caster, x, y, z, 0.0f, radius, angle);

    // check disables
    if (DisableMgr::IsDisabledFor(DISABLE_TYPE_SPELL, m_spellInfo->Id, m_caster))
    {
        SendCastResult(SPELL_FAILED_SPELL_UNAVAILABLE);
        finish(false);
        return SPELL_FAILED_SPELL_UNAVAILABLE;
    }
                // Hacky fix in case we are inside a cave, because GetNearPoint will update Z to above the cave.
                // Example case: trap for gobject 178325, spell 21078
                if ((m_caster->GetDistance(x, y, z) > radius * 2) &&
                    !m_caster->IsWithinLOS(x, y, z, false))
                {
                    m_caster->GetPosition(x, y, z);
                    m_caster->GetNearPoint2D(x, y, radius, angle);
                }

    // Prevent casting at cast another spell (ServerSide check)
    if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CAST_IN_PROGRESS) && m_caster->ToUnit() && m_caster->ToUnit()->IsNonMeleeSpellCast(false, true, true, m_spellInfo->Id == 75) && !m_castId.IsEmpty())
    {
        SendCastResult(SPELL_FAILED_SPELL_IN_PROGRESS);
        finish(false);
        return SPELL_FAILED_SPELL_IN_PROGRESS;
    }

    LoadScripts();
                // For some reason all the creature Blink spells use this target type instead of the player one.
                // Prevent them from teleporting to places that they can't normally walk to like under the map.
                if (m_spellInfo->Effect[effIndex] == SPELL_EFFECT_LEAP)
                    if (!m_caster->GetMap()->GetWalkHitPosition(m_caster->GetTransport(), x, y, z, x, y, z, NAV_GROUND | NAV_WATER, 1.0f, false) || (abs(m_caster->GetPositionZ() - z) > 5.0f))
                        m_caster->GetPosition(x, y, z);

                m_targets.setDestination(x, y, z);
            }                

            if (m_casterUnit && targetUnitMap.empty())
                targetUnitMap.push_back(m_casterUnit);
            else if (m_casterGo)
                AddGOTarget(m_casterGo, effIndex);
            break;
        }
        case TARGET_LOCATION_CASTER_DEST:
        {
            // add here custom effects that need default target.
            // FOR EVERY TARGET TYPE THERE IS A DIFFERENT FILL!!
            switch (m_spellInfo->Effect[effIndex])
            {
                case SPELL_EFFECT_DUMMY:
                {
                    switch (m_spellInfo->Id)
                    {
                        case 20577:                         // Cannibalize
                        {
                            WorldObject* result = FindCorpseUsing<MaNGOS::CannibalizeObjectCheck> ();

    // Set combo point requirement
    if ((_triggeredCastFlags & TRIGGERED_IGNORE_COMBO_POINTS) || m_CastItem)
        m_needComboPoints = false;

    int32 param1 = 0, param2 = 0;
    SpellCastResult result = CheckCast(true, &param1, &param2);
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

    m_casttime = CallScriptCalcCastTimeHandlers(m_spellInfo->CalcCastTime(this));

    if (m_caster->IsUnit() && m_caster->ToUnit()->isMoving())
    {
        result = CheckMovement();
        if (result != SPELL_CAST_OK)
        {
            SendCastResult(result);
            finish(false);
            return result;
        }
    }
                            if (result)
                            {
                                switch (result->GetTypeId())
                                {
                                    case TYPEID_UNIT:
                                    case TYPEID_PLAYER:
                                        targetUnitMap.push_back((Unit*)result);
                                        break;
                                    case TYPEID_CORPSE:
                                        m_targets.setCorpseTarget((Corpse*)result);
                                        break;
                                }
                            }
                            else
                            {
                                // clear cooldown at fail
                                if (m_caster->IsPlayer())
                                    m_caster->RemoveSpellCooldown(*m_spellInfo, true);
                                SendCastResult(SPELL_FAILED_NO_EDIBLE_CORPSES);
                                finish(false);
                            }
                            break;
                        }
                        default:
                            if (m_targets.getUnitTarget())
                                targetUnitMap.push_back(m_targets.getUnitTarget());
                            break;
                    }
                    // Add AoE target-mask to self, if no target-dest provided already
                    if ((m_targets.m_targetMask & TARGET_FLAG_DEST_LOCATION) == 0)
                        m_targets.setDestination(m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ());
                    break;
                }
                case SPELL_EFFECT_BIND:
                case SPELL_EFFECT_PARRY:
                case SPELL_EFFECT_BLOCK:
                case SPELL_EFFECT_CREATE_ITEM:
                case SPELL_EFFECT_TRIGGER_SPELL:
                case SPELL_EFFECT_TRIGGER_MISSILE:
                case SPELL_EFFECT_LEARN_SPELL:
                case SPELL_EFFECT_SKILL_STEP:
                case SPELL_EFFECT_PROFICIENCY:
                case SPELL_EFFECT_SUMMON_POSSESSED:
                case SPELL_EFFECT_SUMMON_OBJECT_WILD:
                case SPELL_EFFECT_SELF_RESURRECT:
                case SPELL_EFFECT_REPUTATION:
                case SPELL_EFFECT_ADD_HONOR:
                case SPELL_EFFECT_SEND_TAXI:
                    if (m_targets.getUnitTarget())
                        targetUnitMap.push_back(m_targets.getUnitTarget());
                    // Triggered spells have additional spell targets - cast them even if no explicit unit target is given (required for spell 50516 for example)
                    else if (m_spellInfo->Effect[effIndex] == SPELL_EFFECT_TRIGGER_SPELL && m_casterUnit)
                        targetUnitMap.push_back(m_casterUnit);
                    break;
                case SPELL_EFFECT_CREATE_HOUSE:
                    if (m_casterUnit)
                        targetUnitMap.push_back(m_casterUnit);
                    break;
                case SPELL_EFFECT_SUMMON_PLAYER:
                    if (m_targets.getUnitTarget())
                        targetUnitMap.push_back(m_targets.getUnitTarget());
                    break;
                case SPELL_EFFECT_RESURRECT:
                case SPELL_EFFECT_RESURRECT_NEW:
                    if (m_targets.getUnitTarget())
                        targetUnitMap.push_back(m_targets.getUnitTarget());
                    if (m_targets.getCorpseTargetGuid())
                    {
                        if (Corpse* corpse = m_caster->GetMap()->GetCorpse(m_targets.getCorpseTargetGuid()))
                            if (Player* owner = ObjectAccessor::FindPlayer(corpse->GetOwnerGuid()))
                                targetUnitMap.push_back(owner);
                    }
                    break;
                case SPELL_EFFECT_SUMMON:
                    /*[-ZERO]  if (m_spellInfo->EffectMiscValueB[effIndex] == SUMMON_TYPE_POSESSED ||
                          m_spellInfo->EffectMiscValueB[effIndex] == SUMMON_TYPE_POSESSED2)
                      {
                          if (m_targets.getUnitTarget())
                              targetUnitMap.push_back(m_targets.getUnitTarget());
                      }
                      else */
                    if (m_casterUnit)
                        targetUnitMap.push_back(m_casterUnit);
                    break;
                case SPELL_EFFECT_TRANS_DOOR:
                {
                    if (m_spellInfo->rangeIndex != SPELL_RANGE_IDX_SELF_ONLY)
                    {
                        float tmp_x, tmp_y, tmp_z;
                        m_caster->GetRandomPoint(m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ(), 5.0f, tmp_x, tmp_y, tmp_z);
                        m_targets.setDestination(tmp_x, tmp_y, tmp_z);
                    }
                    if (m_casterUnit)
                        targetUnitMap.push_back(m_casterUnit);
                    break;
                }
                case SPELL_EFFECT_SUMMON_WILD:
                {
                    if (!m_originalCasterGUID.IsEmpty() && m_originalCasterGUID.IsGameObject())
                    {
                        if (GameObject* pSummoner = m_caster->GetMap()->GetGameObject(m_originalCasterGUID))
                            m_targets.setDestination(pSummoner->GetPositionX(), pSummoner->GetPositionY(), pSummoner->GetPositionZ());
                    }

    // Creatures focus their target when possible
    if (m_casttime && m_caster->IsCreature() && !m_spellInfo->IsNextMeleeSwingSpell() && !IsAutoRepeat() && !m_caster->ToUnit()->HasUnitFlag(UNIT_FLAG_POSSESSED))
    {
        // Channeled spells and some triggered spells do not focus a cast target. They face their target later on via channel object guid and via spell attribute or not at all
        bool const focusTarget = !m_spellInfo->IsChanneled() && !(_triggeredCastFlags & TRIGGERED_IGNORE_SET_FACING);
        if (focusTarget && m_targets.GetObjectTarget() && m_caster != m_targets.GetObjectTarget())
            m_caster->ToCreature()->SetSpellFocus(this, m_targets.GetObjectTarget());
        else
            m_caster->ToCreature()->SetSpellFocus(this, nullptr);
    }

    CallScriptOnPrecastHandler();

    // set timer base at cast time
    ReSetTimer();

    TC_LOG_DEBUG("spells", "Spell::prepare: spell id {} source {} caster {} customCastFlags {} mask {}", m_spellInfo->Id, m_caster->GetEntry(), m_originalCaster ? m_originalCaster->GetEntry() : -1, _triggeredCastFlags, m_targets.GetTargetMask());

    if (m_spellInfo->HasAttribute(SPELL_ATTR12_START_COOLDOWN_ON_CAST_START))
        SendSpellCooldown();

    //Containers for channeled spells have to be set
    /// @todoApply this to all cast spells if needed
    // Why check duration? 29350: channelled triggers channelled
    if ((_triggeredCastFlags & TRIGGERED_CAST_DIRECTLY) && (!m_spellInfo->IsChanneled() || !m_spellInfo->GetMaxDuration()))
        cast(true);
    else
    {
        // commented out !m_spellInfo->StartRecoveryTime, it forces instant spells with global cooldown to be processed in spell::update
        // as a result a spell that passed CheckCast and should be processed instantly may suffer from this delayed process
        // the easiest bug to observe is LoS check in AddUnitTarget, even if spell passed the CheckCast LoS check the situation can change in spell::update
        // because target could be relocated in the meantime, making the spell fly to the air (no targets can be registered, so no effects processed, nothing in combat log)
        bool willCastDirectly = !m_casttime && /*!m_spellInfo->StartRecoveryTime && */ GetCurrentContainer() == CURRENT_GENERIC_SPELL;
                    if (m_casterUnit)
                        targetUnitMap.push_back(m_casterUnit);
                    else if (m_casterGo)
                        AddGOTarget(m_casterGo, effIndex);
                    break;
                }
                case SPELL_EFFECT_SUMMON_DEMON:
                {
                    if (m_casterUnit)
                        targetUnitMap.push_back(m_casterUnit);
                    else if (m_casterGo)
                        AddGOTarget(m_casterGo, effIndex);
                    break;
                }
                case SPELL_EFFECT_SUMMON_CHANGE_ITEM:
                case SPELL_EFFECT_SUMMON_GUARDIAN:
                case SPELL_EFFECT_ADD_FARSIGHT:
                case SPELL_EFFECT_STUCK:
                case SPELL_EFFECT_DESTROY_ALL_TOTEMS:
                case SPELL_EFFECT_SKILL:
                    if (m_casterUnit)
                        targetUnitMap.push_back(m_casterUnit);
                    break;
                case SPELL_EFFECT_PERSISTENT_AREA_AURA:
                    if (Unit* currentTarget = m_targets.getUnitTarget())
                        m_targets.setDestination(currentTarget->GetPositionX(), currentTarget->GetPositionY(), currentTarget->GetPositionZ());
                    break;
                case SPELL_EFFECT_LEARN_PET_SPELL:
                    if (Pet* pet = m_casterUnit ? m_casterUnit->GetPet() : nullptr)
                        targetUnitMap.push_back(pet);
                    break;
                case SPELL_EFFECT_ENCHANT_ITEM:
                case SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY:
                case SPELL_EFFECT_DISENCHANT:
                case SPELL_EFFECT_FEED_PET:
                    if (m_targets.getItemTarget())
                        AddItemTarget(m_targets.getItemTarget(), effIndex);
                    break;
                case SPELL_EFFECT_APPLY_AURA:
                    switch (m_spellInfo->EffectApplyAuraName[effIndex])
                    {
                        case SPELL_AURA_ADD_FLAT_MODIFIER:  // some spell mods auras have 0 target modes instead expected TARGET_UNIT_CASTER(1) (and present for other ranks for same spell for example)
                        case SPELL_AURA_ADD_PCT_MODIFIER:
                            if (m_casterUnit)
                                targetUnitMap.push_back(m_casterUnit);
                            break;
                        default:                            // apply to target in other case
                            if (m_targets.getUnitTarget())
                                targetUnitMap.push_back(m_targets.getUnitTarget());
                            break;
                    }
                    break;
                case SPELL_EFFECT_APPLY_AREA_AURA_PARTY:
                    // AreaAura
                    if (m_spellInfo->Attributes == 0x9050000 || m_spellInfo->Attributes == 0x10000)
                        SetTargetMap(effIndex, TARGET_UNIT_FRIEND_AND_PARTY, targetUnitMap);
                    break;
                case SPELL_EFFECT_SKIN_PLAYER_CORPSE:
                    if (m_targets.getUnitTarget())
                        targetUnitMap.push_back(m_targets.getUnitTarget());
                    break;
                case SPELL_EFFECT_TELEPORT_UNITS_FACE_CASTER:
                    if (!(m_targets.m_targetMask & TARGET_FLAG_DEST_LOCATION))
                        m_targets.setDestination(m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ());
                    break;
                default:
                    break;
            }
            break;
        }
        case TARGET_LOCATION_CASTER_FRONT_LEAP:
        {
            Unit* pUnitTarget = m_targets.getUnitTarget();
            
            if (!pUnitTarget)
                break;
            
            float dis = GetSpellRadius(sSpellRadiusStore.LookupEntry(m_spellInfo->EffectRadiusIndex[effIndex]));
            float x, y, z;
            float srcX, srcY, srcZ;
            float zSearchDist = 20.0f; // Falling case
            float ground = 0.0f;
            pUnitTarget->GetSafePosition(x, y, z);
            pUnitTarget->GetSafePosition(srcX, srcY, srcZ);
            float waterLevel = pUnitTarget->GetTerrain()->GetWaterLevel(x, y, z, &ground);
            x += dis * cos(pUnitTarget->GetOrientation());
            y += dis * sin(pUnitTarget->GetOrientation());
            // Underwater blink case
            if (waterLevel != VMAP_INVALID_HEIGHT_VALUE && waterLevel > ground)
            {
                if (z < ground)
                    z = ground;
                // If blinking up to the surface, limit z position (do not teleport out of water)
                if (z > waterLevel && (z - srcZ) > 1.0f)
                {
                    float t = (waterLevel - srcZ) / (z - srcZ);
                    x = (x - srcX) * t + srcX;
                    y = (y - srcY) * t + srcY;
                    z = waterLevel;
                }
                pUnitTarget->GetMap()->GetLosHitPosition(srcX, srcY, srcZ, x, y, z, -0.5f);
                ground = pUnitTarget->GetMap()->GetHeight(x, y, z);
                if (ground < z)
                {
                    m_targets.setDestination(x, y, z);
                    break;
                }
                // If we are leaving water, rather use pathfinding, but increase z-range position research.
                zSearchDist = 20.0f;
            }
            if (!pUnitTarget->GetMap()->GetWalkHitPosition(pUnitTarget->GetTransport(), srcX, srcY, srcZ, x, y, z, NAV_GROUND | NAV_WATER, zSearchDist, false))
            {
                x = srcX;
                y = srcY;
                z = srcZ;
            }
             
            m_targets.setDestination(x, y, z);
        }
        default:
            //sLog.outError("SPELL: Unknown implicit target (%u) for spell ID %u", targetMode, m_spellInfo->Id);
            break;
    }

    if (unMaxTargets && targetUnitMap.size() > unMaxTargets)
    {
        // make sure one unit is always removed per iteration
        uint32 removed_utarget = 0;
        for (UnitList::iterator itr = targetUnitMap.begin(), next; itr != targetUnitMap.end(); itr = next)
        {
            next = itr;
            ++next;
            if (!*itr) continue;
            if ((*itr) == m_targets.getUnitTarget())
            {
                targetUnitMap.erase(itr);
                removed_utarget = 1;
                //        break;
            }
        }
        // remove random units from the map
        while (targetUnitMap.size() > unMaxTargets - removed_utarget)
        {
            uint32 poz = urand(0, targetUnitMap.size() - 1);
            for (auto itr = targetUnitMap.begin(); itr != targetUnitMap.end(); ++itr, --poz)
            {
                if (!*itr) continue;

                if (!poz)
                {
                    targetUnitMap.erase(itr);
                    break;
                }
            }
        }
        // the player's target will always be added to the map
        if (removed_utarget && m_targets.getUnitTarget())
            targetUnitMap.push_back(m_targets.getUnitTarget());
    }
}

bool IsAcceptableAutorepeatError(SpellCastResult result)
{
    switch (result)
    {
        case SPELL_FAILED_MOVING:   // Let's toggle auto attack while moving
        case SPELL_CAST_OK:
            return true;
    }
    return false;
}

void Spell::UpdateCastStartPosition()
{
    if (m_caster->GetTransport())
    {
        m_castPosition.x = m_caster->GetTransOffsetX();
        m_castPosition.y = m_caster->GetTransOffsetY();
        m_castPosition.z = m_caster->GetTransOffsetZ();
        m_castPosition.o = m_caster->GetTransOffsetO();
    }
    else
    {
        m_castPosition.x = m_caster->GetPositionX();
        m_castPosition.y = m_caster->GetPositionY();
        m_castPosition.z = m_caster->GetPositionZ();
        m_castPosition.o = m_caster->GetOrientation();
    }
}

SpellCastResult Spell::prepare(SpellCastTargets targets, Aura* triggeredByAura, uint32 chance)
{
    m_targets = std::move(targets);
    return prepare(triggeredByAura, chance);
}

SpellCastResult Spell::prepare(Aura* triggeredByAura, uint32 chance)
{
    m_spellState = SPELL_STATE_PREPARING;
    m_delayed = m_spellInfo->speed > 0.0f 
        || (!m_IsTriggeredSpell && m_caster->IsPlayer() && m_spellInfo->IsSpellWithDelayableEffects());

    UpdateCastStartPosition();

    if (triggeredByAura)
    {
        m_triggeredByAuraSpell = triggeredByAura->GetSpellProto();
        m_triggeredByAuraBasePoints = triggeredByAura->GetBasePoints();
    }

    try
    {
        // create and add update event for this spell
        SpellEvent* Event = new SpellEvent(this);
        m_caster->m_Events.AddEvent(Event, m_caster->m_Events.CalculateTime(1));

        //Prevent casting at cast another spell (ServerSide check)
        if (!m_IsTriggeredSpell && m_caster->IsNonMeleeSpellCasted(false, true, true))
        {
            if (!m_originalCasterGUID.IsGameObject())
            {
                SendCastResult(SPELL_FAILED_SPELL_IN_PROGRESS);
                finish(false);
                return SPELL_FAILED_SPELL_IN_PROGRESS;
            }
        }
        if (sObjectMgr.IsSpellDisabled(m_spellInfo->Id))
        {
            SendCastResult(SPELL_FAILED_SPELL_UNAVAILABLE);
            finish(false);
            return SPELL_FAILED_SPELL_UNAVAILABLE;
        }

        // Fill cost data
        m_powerCost = CalculatePowerCost(m_spellInfo, m_casterUnit, this, m_CastItem);

        if (Player* pPlayer = m_caster->ToPlayer())
            if (pPlayer->HasCheatOption(PLAYER_CHEAT_NO_POWER))
                m_powerCost = 0;

        if (!IsChannelingVisual())
        {
            SpellCastResult result = CheckCast(true);
            Unit* pTarget = m_targets.getUnitTarget();
            if (result != SPELL_CAST_OK || (IsAutoRepeat() && m_caster == pTarget))
            {
                if (!IsAutoRepeat() || !IsAcceptableAutorepeatError(result))
                {
                    DEBUG_FILTER_LOG(LOG_FILTER_SPELL_CAST, "Spell %u failed for reason 0x%x (target %u)", m_spellInfo->Id, result, pTarget ? pTarget->GetGUIDLow() : 0);
                    if (triggeredByAura && !triggeredByAura->GetHolder()->IsPassive())
                    {
                        SendChannelUpdate(0, true);
                        triggeredByAura->GetHolder()->SetAuraDuration(0);
                    }

                    SendCastResult(result);
                    //SendInterrupted(0);
                    finish(false);
                    return result;
                }
            }
        }

        // Roll chance to cast from script (must be after cast checks, this is why its here)
        if (chance)
        {
            if (!roll_chance_u(chance))
            {
                finish(false);
                return SPELL_FAILED_TRY_AGAIN;
            } 
        }

        // Prepare data for triggers
        prepareDataForTriggerSystem();

        // calculate cast time (calculated after first CheckCast check to prevent charge counting for first CheckCast fail)
        m_casttime = m_spellInfo->GetCastTime(this);

        if (Player* pPlayerCaster = m_caster->ToPlayer())
            if (pPlayerCaster->HasCheatOption(PLAYER_CHEAT_NO_CAST_TIME))
                m_casttime = 0;

        m_duration = m_spellInfo->CalculateDuration(m_caster);

        // set timer base at cast time
        ReSetTimer();

        // If timer = 0, it's an instant cast spell and will be casted on the next tick.
        // Cast completion will remove all any stealth/invis auras
        if (m_timer)
        {
            // World of Warcraft Client Patch 1.10.0 (2006-03-28)
            // - Stealth and Invisibility effects will now be canceled at the
            //   beginning of an action(spellcast, ability use etc...), rather than
            //   at the completion of the action.
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
            RemoveStealthAuras();
#endif
            
            // If using a game object we need to remove any remaining invis auras. Should only
            // ever be Gnomish Cloaking Device, since it's a special case and not removed on
            // opcode receive
            if (m_caster->IsPlayer() && m_targets.getGOTarget())
                m_casterUnit->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_ON_CAST_SPELL);
        }

        if (Unit* unitCaster = m_caster->ToUnit())
        {
            // stealth must be removed at cast starting (at show channel bar)
            // skip triggered spell (item equip spell casting and other not explicit character casts/item uses)
            if (!(_triggeredCastFlags & TRIGGERED_IGNORE_AURA_INTERRUPT_FLAGS) && !m_spellInfo->HasAttribute(SPELL_ATTR2_NOT_AN_ACTION))
                unitCaster->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Action, m_spellInfo);
        OnSpellLaunch();

            // Do not register as current spell when requested to ignore cast in progress
            // We don't want to interrupt that other spell with cast time
            if (!willCastDirectly || !(_triggeredCastFlags & TRIGGERED_IGNORE_CAST_IN_PROGRESS))
                unitCaster->SetCurrentCastSpell(this);
        }
        SendSpellStart();
        bool channeled = m_channeled;

        // [Nostalrius] Stop pets casting channeled spells ! (succubus seduce ...)
        if (m_timer && channeled)
            if (m_caster->IsPet())
                m_casterUnit->StopMoving();

        // Call CreatureAI hook OnSpellStart
        if (Creature* caster = m_caster->ToCreature())
            if (caster->IsAIEnabled())
                caster->AI()->OnSpellStart(GetSpellInfo());

        if (willCastDirectly)
        // This is used so that creatures face the target on which they are casting
        if (m_setCreatureTarget = (m_caster->IsCreature() && (channeled || (!m_IsTriggeredSpell && m_timer)) && m_targets.getUnitTarget() && IsExplicitlySelectedUnitTarget(m_spellInfo->EffectImplicitTargetA[0]) && static_cast<Creature*>(m_caster)->CanHaveTarget()))
            static_cast<Creature*>(m_caster)->SetCastingTarget(m_targets.getUnitTarget());

        // add non-triggered (with cast time and without)
        if (!m_IsTriggeredSpell || channeled)
            m_caster->SetCurrentCastedSpell(this);

        if (!m_IsTriggeredSpell)
        {
            // will show cast bar
            SendSpellStart();
            // add gcd server side (client side is handled by client itself)
            if (!m_caster->IsPlayer() || !static_cast<Player*>(m_caster)->HasCheatOption(PLAYER_CHEAT_NO_COOLDOWN))
                m_caster->AddGCD(*m_spellInfo);
            // Cast on self -> execute NOW
            //if (!m_timer && m_caster->IsPlayer() && !m_targets.m_targetMask && !IsAreaOfEffectSpell(m_spellInfo))
            //    cast(true);
        }
        // execute triggered without cast time explicitly in call point
        else if ((m_timer == 0) &&
            // Prevent scenario where pet has a periodic aura that
            // triggers another spell to deal damage to owner,
            // causing owner to die and pet gets despawned, leading to
            // deletion of auras on pet and crash when stack unwinds.
            // An example of this is spell 3584 Volatile Infection.
            !(triggeredByAura && m_spellInfo->IsDirectDamageSpell() && m_caster->IsCreature()))
            cast(true);

        // else triggered with cast time will execute at next tick or later
        // without adding to cast type slot
        // will not show cast bar but will show effects at casting time etc
    }

    return SPELL_CAST_OK;
}
    catch (std::runtime_error &e)
    {
        sLog.outInfo("[Spell/Crash] 'prepare()' [%u:%s:%u:{%f:%f:%f}]", m_spellInfo->Id, m_caster->GetName(), m_caster->GetGUIDLow(), m_castPosition.x, m_castPosition.y, m_castPosition.z);
        sLog.outInfo(e.what());
        finish(false);
        return SPELL_FAILED_UNKNOWN;
    }

    return SPELL_CAST_OK;
}

void Spell::cancel()
{
    if (m_spellState == SPELL_STATE_FINISHED)
        return;

    // channeled spells don't display interrupted message even if they are interrupted, possible other cases with no "Interrupted" message
    bool sendInterrupt = !(m_channeled && m_spellState != SPELL_STATE_PREPARING);

    m_autoRepeat = false;
    switch (m_spellState)
    {
        case SPELL_STATE_PREPARING:
            CancelGlobalCooldown();
            [[fallthrough]];
            m_caster->ResetGCD(m_spellInfo);
            if (m_caster->IsPlayer())
                m_caster->ToPlayer()->RestoreSpellMods(this);
        //(no break)
        case SPELL_STATE_DELAYED:
        {
            SendInterrupted(0);
            if (sendInterrupt && !GetDelayStart())
                SendCastResult(SPELL_FAILED_INTERRUPTED);
        }
        break;

        case SPELL_STATE_CASTING:
            for (TargetInfo const& targetInfo : m_UniqueTargetInfo)
                if (targetInfo.MissCondition == SPELL_MISS_NONE)
                    if (Unit* unit = m_caster->GetGUID() == targetInfo.TargetGUID ? m_caster->ToUnit() : ObjectAccessor::GetUnit(*m_caster, targetInfo.TargetGUID))
                        unit->RemoveOwnedAura(m_spellInfo->Id, m_originalCasterGUID, 0, AURA_REMOVE_BY_CANCEL);
        {
            for (const auto& ihit : m_UniqueTargetInfo)
            {
                if (ihit.deleted)
                    continue;
                if (ihit.missCondition == SPELL_MISS_NONE)
                {
                    Unit* unit = m_caster->GetObjectGuid() == ihit.targetGUID ? m_casterUnit : ObjectAccessor::GetUnit(*m_caster, ihit.targetGUID);
                    if (unit && unit->IsAlive())
                        unit->RemoveAurasByCasterSpell(m_spellInfo->Id, m_caster->GetObjectGuid());
                }
            }

            SendChannelUpdate(0, true);
            SendInterrupted(0);

            if (m_caster->IsPlayer())
            {
                // spell is canceled-take mods and clear list
                m_caster->ToPlayer()->RemoveSpellMods(this);

                // summoning rituals, if a user has cancelled inform the go
                // Don't use m_targets.getGOTarget(), as it may be a dangling pointer since we don't
                // update the target pointers here (only want to check a single target pointer). We
                // can use it as a speed-up to see if this spell had a GO target at some point though
                if (m_targets.getGOTarget())
                {
                    if (GameObject* go = m_caster->GetMap()->GetGameObject(m_targets.getGOTargetGuid()))
                    {
                        if (go->GetGoType() == GAMEOBJECT_TYPE_SUMMONING_RITUAL &&
                            go->getLootState() != GO_JUST_DEACTIVATED &&
                            go->HasUniqueUser(m_caster->ToPlayer()))
                        {
                            go->RemoveUniqueUse(m_caster->ToPlayer());
                        }
                    }
                }
            }

            if (sendInterrupt)
                SendCastResult(SPELL_FAILED_INTERRUPTED);
        }
        break;

        default:
        {
        } break;
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
    finish(false);
    m_caster->RemoveDynObject(m_spellInfo->Id);
    if (m_casterUnit)
        m_casterUnit->RemoveGameObject(m_spellInfo->Id, true);
}

void Spell::cast(bool skipCheck)
{
    if (m_spellInfo->Id <= 0 || m_spellInfo->Id > MAX_SPELL_ID)
        return;

    SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(m_spellInfo->Id);
    if (!spellInfo)
        return;

    SetExecutedCurrently(true);

    if (!m_caster->CheckAndIncreaseCastCounter())
    {
        if (m_triggeredByAuraSpell)
            sLog.outError("Spell %u triggered by aura spell %u too deep in cast chain for cast. Cast not allowed for prevent overflow stack crash.", m_spellInfo->Id, m_triggeredByAuraSpell->Id);
        else
            sLog.outError("Spell %u too deep in cast chain for cast. Cast not allowed for prevent overflow stack crash.", m_spellInfo->Id);

        SendInterrupted(2);
        SendCastResult(SPELL_FAILED_ERROR);
        finish(false);
        SetExecutedCurrently(false);
        return;
    }

    // update pointers base at GUIDs to prevent access to already nonexistent object
    UpdatePointers();

    // cancel at lost main target unit
    if (!m_targets.getUnitTarget() && m_targets.getUnitTargetGuid() && m_targets.getUnitTargetGuid() != m_caster->GetObjectGuid())
    {
        SendInterrupted(2);
        cancel();
        m_caster->DecreaseCastCounter();
        SetExecutedCurrently(false);
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
        if (GetSpellInfo()->DmgClass != SPELL_DAMAGE_CLASS_NONE)
            if (Unit* target = m_targets.GetUnitTarget())
                for (Unit* controlled : playerCaster->m_Controlled)
                    if (Creature* cControlled = controlled->ToCreature())
                        if (CreatureAI* controlledAI = cControlled->AI())
                            controlledAI->OwnerAttacked(target);
    }

    SetExecutedCurrently(true);

    // Should this be done for original caster?
    Player* modOwner = m_caster->GetSpellModOwner();
    if (modOwner)
    {
        // Set spell which will drop charges for triggered cast spells
        // if not successfully cast, will be remove in finish(false)
        modOwner->SetSpellModTakingSpell(this, true);
    if (m_casterUnit)
    {
        // Ivina <Nostalrius> : Added the case when caster is charmed and not controlled.
        if ((!m_caster->IsPlayer()) || ((m_casterUnit->GetCharmerGuid()) && (!m_casterUnit->HasUnitState(UNIT_STAT_POSSESSED))))
        {
            if (m_targets.getUnitTarget() && m_targets.getUnitTarget() != m_caster)
                m_casterUnit->SetInFront(m_targets.getUnitTarget());
        }
    }

    SpellCastResult castResult = SPELL_CAST_OK;
    if (!skipCheck && !IsChannelingVisual())
    {
        auto cleanupSpell = [this, modOwner](SpellCastResult res, int32* p1 = nullptr, int32* p2 = nullptr)
        // Nostalrius - compute power cost once again at cast finished
        // (in case of mana reduction buff proc while casting)
        m_powerCost = CalculatePowerCost(m_spellInfo, m_casterUnit, this, m_CastItem);
        castResult = CheckPower();
        if (castResult != SPELL_CAST_OK)
        {
            SendInterrupted(2);
            SendCastResult(castResult);
            //restore spell mods
            if (m_caster->IsPlayer())
                m_caster->ToPlayer()->RestoreSpellMods(this);
            finish(false);
            m_caster->DecreaseCastCounter();
            SetExecutedCurrently(false);
            return;
        }

        int32 param1 = 0, param2 = 0;
        SpellCastResult castResult = CheckCast(false, &param1, &param2);
        // triggered cast called from Spell::prepare where it was already checked
        castResult = CheckCast(false);
        if (castResult != SPELL_CAST_OK)
        {
            SendInterrupted(2);
            SendCastResult(castResult);
            finish(false);
            m_caster->DecreaseCastCounter();
            SetExecutedCurrently(false);
            //restore spell mods
            if (m_caster->IsPlayer())
                m_caster->ToPlayer()->RestoreSpellMods(this);
            return;
        }
    }

    // different triggred (for caster) and precast (casted before apply effect to target) cases
    switch (m_spellInfo->SpellFamilyName)
    {
        case SPELLFAMILY_GENERIC:
        {
            // Bandages
            if (m_spellInfo->Mechanic == MECHANIC_BANDAGE)
                AddPrecastSpell(11196);                     // Recently Bandaged

            // Divine Shield, Divine Protection (Blessing of Protection in paladin switch case)
            else if (m_spellInfo->Mechanic == MECHANIC_INVULNERABILITY)
                AddPrecastSpell(25771);                     // Forbearance

            switch (m_spellInfo->Id)
            {
                case 26374: // Elune's Candle
                {
                    static uint32 const OmenSpells[] = { 26622, 26623, 26624, 26625, 26649 };

                    uint32 spell = 26636;

                    Unit* target = m_targets.getUnitTarget();

                    if (target && target->ToUnit())
                    {
                        if (target->GetEntry() == 15467)
                            spell = OmenSpells[urand(0, 4)];

                        if (target->GetEntry() == 15466)
                            spell = 26624;
                    }

                    m_caster->CastSpell(target, spell, true);
                }
                break;
            }

            break;
        }
        case SPELLFAMILY_WARRIOR:
            break;
        case SPELLFAMILY_PRIEST:
        {
            uint32 aura_effmask = 0;
            for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
                if (spellEffectInfo.IsUnitOwnedAuraEffect())
                    aura_effmask |= 1 << spellEffectInfo.EffectIndex;
            // Power Word: Shield
            // Nostalrius : Ivina : removed 27779 from cases = priest T0/T0.5 shield proc.
            if (m_spellInfo->IsFitToFamily<SPELLFAMILY_PRIEST, CF_PRIEST_POWER_WORD_SHIELD>() && (m_spellInfo->Id != 27779))
                AddPrecastSpell(6788);                      // Weakened Soul

            if (aura_effmask)
            {
                if (m_spellInfo->GetDiminishingReturnsGroupForSpell())
                {
                    DiminishingReturnsType type = m_spellInfo->GetDiminishingReturnsGroupType();
                    if (type == DRTYPE_ALL || (type == DRTYPE_PLAYER && target->IsAffectedByDiminishingReturns()))
                    {
                        if (Unit* caster = m_originalCaster ? m_originalCaster : m_caster->ToUnit())
                        {
                            if (target->HasStrongerAuraWithDR(m_spellInfo, caster))
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
    // The spell focusing is making sure that we have a valid cast target guid when we need it so only check for a guid value here.
    if (Creature* creatureCaster = m_caster->ToCreature())
        if (!creatureCaster->GetTarget().IsEmpty() && !creatureCaster->HasUnitFlag(UNIT_FLAG_POSSESSED))
            if (WorldObject const* target = ObjectAccessor::GetUnit(*creatureCaster, creatureCaster->GetTarget()))
                creatureCaster->SetInFront(target);
            switch (m_spellInfo->Id)
            {
                case 15237:
                    AddTriggeredSpell(23455);
                    break;// Holy Nova, rank 1
                case 15430:
                    AddTriggeredSpell(23458);
                    break;// Holy Nova, rank 2
                case 15431:
                    AddTriggeredSpell(23459);
                    break;// Holy Nova, rank 3
                case 27799:
                    AddTriggeredSpell(27803);
                    break;// Holy Nova, rank 4
                case 27800:
                    AddTriggeredSpell(27804);
                    break;// Holy Nova, rank 5
                case 27801:
                    AddTriggeredSpell(27805);
                    break;// Holy Nova, rank 6
                default:
                    break;
            }
            break;
        }
        case SPELLFAMILY_PALADIN:
        {
            // Blessing of Protection (Divine Shield, Divine Protection in generic switch case)
            if (m_spellInfo->Mechanic == MECHANIC_INVULNERABILITY && m_spellInfo->Id != 25771)
                AddPrecastSpell(25771);                     // Forbearance
            break;
        }
        default:
            break;
    }

    SelectSpellTargets();
    // traded items have trade slot instead of guid in m_itemTargetGUID
    // set to real guid to be sent later to the client
    m_targets.updateTradeSlotItem();

    FillTargetMap();
    if (m_channeled)
        HandleAddTargetTriggerAuras();

    if (m_spellState == SPELL_STATE_FINISHED)                // stop cast if spell marked as finish somewhere in FillTargetMap
    {
        m_caster->DecreaseCastCounter();
        SetExecutedCurrently(false);
        if (m_caster->IsPlayer())
            m_caster->ToPlayer()->RestoreSpellMods(this);
        return;
    }

    if (Unit* unitCaster = m_caster->ToUnit())
        if (m_spellInfo->HasAttribute(SPELL_ATTR1_DISMISS_PET_FIRST))
            if (Creature* pet = ObjectAccessor::GetCreature(*m_caster, unitCaster->GetPetGUID()))
                pet->DespawnOrUnsummon();
    // CAST SPELL
    SendSpellCooldown();

    // Remove any remaining invis auras on cast completion, should only be gnomish cloaking device
    if (!m_IsTriggeredSpell  && !m_spellInfo->HasAttribute(SPELL_ATTR_EX_NOT_BREAK_STEALTH) && m_casterUnit)
        m_casterUnit->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_ON_CAST_SPELL);

    TakePower();
    TakeReagents();                                         // we must remove reagents before HandleEffects to allow place crafted item in same slot
    TakeAmmo();

    SendCastResult(castResult);
    InitializeDamageMultipliers();

    if (Player* player = m_caster->ToPlayer())
    {
        if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CAST_ITEM) && m_CastItem)
        {
            player->StartCriteriaTimer(CriteriaStartEvent::UseItem, m_CastItem->GetEntry());
            player->UpdateCriteria(CriteriaType::UseItem, m_CastItem->GetEntry());
        }

        player->UpdateCriteria(CriteriaType::CastSpell, m_spellInfo->Id);
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
    // AoE case. Trigger spells for caster now.
    if (m_procAttacker & PROC_FLAG_SUCCESSFUL_AOE && m_canTrigger)
    {
        uint32 procAttacker = 0;
        // Blizzard case. Should trigger at launch for clearcast.
        if (m_spellInfo->IsFitToFamily<SPELLFAMILY_MAGE, CF_MAGE_BLIZZARD>())
            procAttacker = m_procAttacker;
        else
            procAttacker = (m_procAttacker & PROC_FLAG_ON_TRAP_ACTIVATION);
        uint32 procAttackerFlags = procAttacker;
        if (!IsTriggered())
        {
            procAttackerFlags |= (PROC_FLAG_SUCCESSFUL_SPELL_CAST | PROC_FLAG_SUCCESSFUL_AOE);
            if (m_powerCost > 0 && m_spellInfo->powerType == POWER_MANA)
                procAttackerFlags |= PROC_FLAG_SUCCESSFUL_MANA_SPELL_CAST;
        }
        m_caster->ProcDamageAndSpell(ProcSystemArguments(nullptr, procAttackerFlags, PROC_FLAG_NONE, PROC_EX_NORMAL_HIT, 1, m_attackType, m_spellInfo, this));
    }

    // CAST SPELL
    if (!m_spellInfo->HasAttribute(SPELL_ATTR12_START_COOLDOWN_ON_CAST_START))
        SendSpellCooldown();

    if (!m_spellInfo->LaunchDelay)
    // Shaman totems. Trigger spell cast procs, but not others
    if (m_spellInfo->IsTotemSummonSpell() && m_canTrigger && m_casterUnit)
    {
        uint32 procAttackerFlags = PROC_FLAG_SUCCESSFUL_SPELL_CAST | PROC_FLAG_SUCCESSFUL_MANA_SPELL_CAST;
        m_casterUnit->ProcDamageAndSpell(ProcSystemArguments(m_casterUnit, procAttackerFlags, PROC_FLAG_NONE, PROC_EX_NORMAL_HIT, 1, m_attackType, m_spellInfo, this));
    }

    // Okay, everything is prepared. Now we need to distinguish between immediate and evented delayed spells
    if ((m_spellInfo->HasHitDelay() && !m_spellInfo->IsChanneled()) || m_spellInfo->HasAttribute(SPELL_ATTR4_NO_HARMFUL_THREAT))
    if (m_delayed)
    {
        SendSpellGo();                                          // we must send smsg_spell_go packet before m_castItem delete in TakeCastItem()...
        // Remove used for cast item if need (it can be already nullptr after TakeReagents call
        // in case delayed spell remove item at cast delay start
        TakeCastItem();

        // fill initial spell damage from caster for delayed casted spells
        for (auto& ihit : m_UniqueTargetInfo)
            HandleDelayedSpellLaunch(&ihit);

        // Okay, maps created, now prepare flags
        m_immediateHandled = false;
        m_spellState = SPELL_STATE_DELAYED;
        SetDelayStart(0);
    }
    else
    {
        // Immediate spell, no big deal
        handle_immediate();
    }

    CallScriptAfterCastHandlers();

    if (std::vector<int32> const* spell_triggered = sSpellMgr->GetSpellLinked(SPELL_LINK_CAST, m_spellInfo->Id))
    {
        for (int32 id : *spell_triggered)
        try
        {
            handle_immediate();
        }
        catch (std::runtime_error &e)
        {
            if (id < 0)
            {
                if (Unit* unitCaster = m_caster->ToUnit())
                    unitCaster->RemoveAurasDueToSpell(-id);
            }
            else
                m_caster->CastSpell(m_targets.GetUnitTarget() ? m_targets.GetUnitTarget() : m_caster, id, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                    .SetTriggeringSpell(this));
            sLog.outInfo("[Spell/Crash] 'handle_immediate()' [%u:%s:%u:%u]", m_spellInfo->Id, m_caster->GetName(), m_caster->GetGUIDLow(), m_caster->GetMapId());
            sLog.outInfo(e.what());
            SetExecutedCurrently(false);
            return;
    {
        modOwner->SetSpellModTakingSpell(this, false);

        //Clear spell cooldowns after every spell is cast if .cheat cooldown is enabled.
        if (m_originalCaster && modOwner->GetCommandStatus(CHEAT_COOLDOWN))
        {
            m_originalCaster->GetSpellHistory()->ResetCooldown(m_spellInfo->Id, true);
        }
    }

    if (modOwner)
    {
        modOwner->SetSpellModTakingSpell(this, false);

        //Clear spell cooldowns after every spell is cast if .cheat cooldown is enabled.
        if (m_originalCaster && modOwner->GetCommandStatus(CHEAT_COOLDOWN))
        {
            m_originalCaster->GetSpellHistory()->ResetCooldown(m_spellInfo->Id, true);
            m_originalCaster->GetSpellHistory()->RestoreCharge(m_spellInfo->ChargeCategoryId);
        }
    if (m_casterUnit && IsMeleeAttackResetSpell() && !(m_spellInfo->AttributesEx2 & SPELL_ATTR_EX2_NOT_RESET_AUTO_ACTIONS))
    {
        m_casterUnit->ResetAttackTimer(BASE_ATTACK);
        if (m_casterUnit->HaveOffhandWeapon())
    if (!procAttacker)
    {
        if (m_spellInfo->HasAttribute(SPELL_ATTR3_TREAT_AS_PERIODIC))
        {
            m_casterUnit->ResetAttackTimer(OFF_ATTACK);
    }

    m_caster->DecreaseCastCounter();
    SetExecutedCurrently(false);
}

template <class Container>
void Spell::DoProcessTargetContainer(Container& targetContainer)
{
    for (TargetInfoBase& target : targetContainer)
        target.PreprocessTarget(this);

    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
        for (TargetInfoBase& target : targetContainer)
            if (target.EffectMask & (1 << spellEffectInfo.EffectIndex))
                target.DoTargetSpellHit(this, spellEffectInfo);

    for (TargetInfoBase& target : targetContainer)
        target.DoDamageAndTriggers(this);
}

void Spell::handle_immediate()
{
    // start channeling if applicable
    if (m_spellInfo->IsChanneled())
    {
        int32 duration = m_spellInfo->GetDuration();
        if (duration > 0 || m_spellValue->Duration)
        {
            if (!m_spellValue->Duration)
            {
                // First mod_duration then haste - see Missile Barrage
                // Apply duration mod
                if (Player* modOwner = m_caster->GetSpellModOwner())
                    modOwner->ApplySpellMod(m_spellInfo, SpellModOp::Duration, duration);

                duration *= m_spellValue->DurationMul;

                // Apply haste mods
                m_caster->ModSpellDurationTime(m_spellInfo, duration, this);
            }
            else
                duration = *m_spellValue->Duration;
    bool sendGoBefore = true;
    if (m_spellInfo->HasEffect(SPELL_EFFECT_INSTAKILL) || m_spellInfo->HasEffect(SPELL_EFFECT_SPAWN))
        sendGoBefore = false;
    if (sendGoBefore)
        SendSpellGo();
    // process immediate effects (items, ground, etc.) also initialize some variables
    _handle_immediate_phase();

}

template <class Container>
void Spell::DoProcessTargetContainer(Container& targetContainer)
{
    for (TargetInfoBase& target : targetContainer)
        target.PreprocessTarget(this);

    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
        for (TargetInfoBase& target : targetContainer)
            if (target.EffectMask & (1 << spellEffectInfo.EffectIndex))
                target.DoTargetSpellHit(this, spellEffectInfo);

    for (TargetInfoBase& target : targetContainer)
        target.DoDamageAndTriggers(this);
}

void Spell::handle_immediate()
{
    // start channeling if applicable
    if (m_spellInfo->IsChanneled())
    {
        int32 duration = m_spellInfo->GetDuration();
        if (duration > 0 || m_spellValue->Duration)
        {
            if (!m_spellValue->Duration)
            {
                // First mod_duration then haste - see Missile Barrage
                // Apply duration mod
                if (Player* modOwner = m_caster->GetSpellModOwner())
                    modOwner->ApplySpellMod(m_spellInfo, SpellModOp::Duration, duration);

                duration *= m_spellValue->DurationMul;

                // Apply haste mods
                m_caster->ModSpellDurationTime(m_spellInfo, duration, this);
            }
            else
                duration = *m_spellValue->Duration;

            m_channeledDuration = duration;
            SendChannelStart(duration);
        }
        else if (duration == -1)
            SendChannelStart(duration);

        if (duration != 0)
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
    // start channeling if applicable (after _handle_immediate_phase for get persistent effect dynamic object for channel target
    if (m_channeled && m_duration)
    {
        m_spellState = SPELL_STATE_CASTING;
        SendChannelStart(m_duration);
        if (m_caster->IsPlayer())
            m_caster->ToPlayer()->RemoveSpellMods(this);
    }

    m_targetNum = 0;
    for (auto ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
    {
        if (m_destroyed || ihit == m_UniqueTargetInfo.end() || m_UniqueTargetInfo.empty())
            break;

        if (ihit->deleted)
            continue;

    // consider spell hit for some spells without target, so they may proc on finish phase correctly
    if (m_UniqueTargetInfo.empty())
        m_hitMask = PROC_HIT_NORMAL;
    else
        DoProcessTargetContainer(m_UniqueTargetInfo);
        ++m_targetNum;
        DoAllEffectOnTarget(&(*ihit));

        // a channeled spell could be interrupted already because the aura on target
        // was diminished to duration=0 see Spell::DoSpellHitOnUnit
        if (m_spellInfo->IsChanneledSpell() && m_spellState != SPELL_STATE_CASTING)
            return;
    }

    DoProcessTargetContainer(m_UniqueGOTargetInfo);
    for (auto ihit = m_UniqueGOTargetInfo.begin(); ihit != m_UniqueGOTargetInfo.end(); ++ihit)
    {
        if (m_destroyed || ihit == m_UniqueGOTargetInfo.end() || m_UniqueGOTargetInfo.empty())
            break;

    DoProcessTargetContainer(m_UniqueCorpseTargetInfo);

    FinishTargetProcessing();
        if (ihit->deleted)
            continue;

        DoAllEffectOnTarget(&(*ihit));
    }
    // Effets sur le corps.
    if (m_targets.getCorpseTargetGuid())
        if (corpseTarget = m_caster->GetMap()->GetCorpse(m_targets.getCorpseTargetGuid()))
            for (int i = 0; i < 3; ++i)
                HandleEffects(nullptr, nullptr, nullptr, SpellEffectIndex(i));
    // spell is finished, perform some last features of the spell here
    _handle_finish_phase();

    // Nostalrius: Send spell_go once effects are done (fix visual bug with EFFECT_INSTAKILL for example: 11504)
    if (!sendGoBefore)
        SendSpellGo();                                          // we must send smsg_spell_go packet before m_castItem delete in TakeCastItem()...
    // Remove used for cast item if need (it can be already nullptr after TakeReagents call
    TakeCastItem();

    if (m_spellState != SPELL_STATE_CASTING)
        finish(true);                                       // successfully finish spell cast (not last in case autorepeat or channel spell)
}

uint64 Spell::handle_delayed(uint64 t_offset)
{
    uint64 next_time = 0;

    if (!m_launchHandled)
    {
        uint64 launchMoment = uint64(std::floor(m_spellInfo->LaunchDelay * 1000.0f));
        if (launchMoment > t_offset)
            return launchMoment;

        HandleLaunchPhase();
        m_launchHandled = true;
        if (m_delayMoment > t_offset)
        {
            if (single_missile)
                return m_delayMoment;

            next_time = m_delayMoment;
            if ((m_UniqueTargetInfo.size() > 2 || (m_UniqueTargetInfo.size() == 1 && m_UniqueTargetInfo.front().TargetGUID == m_caster->GetGUID())) || !m_UniqueGOTargetInfo.empty())
            {
                t_offset = 0; // if LaunchDelay was present then the only target that has timeDelay = 0 is m_caster - and that is the only target we want to process now
            }
        }
    }

    if (single_missile && !t_offset)
        return m_delayMoment;

    Player* modOwner = m_caster->GetSpellModOwner();
    if (modOwner)
        modOwner->SetSpellModTakingSpell(this, true);

    PrepareTargetProcessing();

    if (!m_immediateHandled && t_offset)
    if (!m_immediateHandled)
    {
        _handle_immediate_phase();
        m_immediateHandled = true;
    }

    m_targetNum = 0;
    // now recheck units targeting correctness (need before any effects apply to prevent adding immunity at first effect not allow apply second spell effect and similar cases)
    for (auto& ihit : m_UniqueTargetInfo)
    {
        std::vector<TargetInfo> delayedTargets;
        m_UniqueTargetInfo.erase(std::remove_if(m_UniqueTargetInfo.begin(), m_UniqueTargetInfo.end(), [&](TargetInfo& target) -> bool
        if (!ihit.processed)
        {
            if (single_missile || target.TimeDelay <= t_offset)
            if (ihit.timeDelay <= t_offset)
            {
                target.TimeDelay = t_offset;
                delayedTargets.emplace_back(std::move(target));
                return true;
                ++m_targetNum;
                CheckAtDelay(&ihit);
                DoAllEffectOnTarget(&ihit);
            }
            else if (next_time == 0 || target.TimeDelay < next_time)
                next_time = target.TimeDelay;

            return false;
        }), m_UniqueTargetInfo.end());

        DoProcessTargetContainer(delayedTargets);
    }
            else if (next_time == 0 || ihit.timeDelay < next_time)
                next_time = ihit.timeDelay;
        }
    }

    // now recheck gameobject targeting correctness
    for (auto& ighit : m_UniqueGOTargetInfo)
    {
        std::vector<GOTargetInfo> delayedGOTargets;
        m_UniqueGOTargetInfo.erase(std::remove_if(m_UniqueGOTargetInfo.begin(), m_UniqueGOTargetInfo.end(), [&](GOTargetInfo& goTarget) -> bool
        if (!ighit.processed)
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
            if (ighit.timeDelay <= t_offset)
                DoAllEffectOnTarget(&ighit);
            else if (next_time == 0 || ighit.timeDelay < next_time)
                next_time = ighit.timeDelay;
        }
    }
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
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
    {
        // don't do anything for empty effect
        if (!spellEffectInfo.IsEffect())
    m_needSpellLog = IsNeedSendToClient();
    for (uint8 j = 0; j < MAX_EFFECT_INDEX; ++j)
    {
        if (m_spellInfo->Effect[j] == 0)
            continue;

        // apply Send Event effect to ground in case empty target lists
        if (m_spellInfo->Effect[j] == SPELL_EFFECT_SEND_EVENT && !HaveTargetsForEffect(SpellEffectIndex(j)))
        {
            HandleEffects(nullptr, nullptr, nullptr, SpellEffectIndex(j));
            continue;
        }

        // call effect handlers to handle destination hit
        HandleEffects(nullptr, nullptr, nullptr, nullptr, spellEffectInfo, SPELL_EFFECT_HANDLE_HIT);
        // Don't do spell log, if is school damage spell
        if (m_spellInfo->Effect[j] == SPELL_EFFECT_SCHOOL_DAMAGE || m_spellInfo->Effect[j] == 0)
            m_needSpellLog = false;
    }

    // initialize Diminishing Returns Data
    m_diminishLevel = DIMINISHING_LEVEL_1;
    m_diminishGroup = DIMINISHING_NONE;

    // process items
    DoProcessTargetContainer(m_UniqueItemInfo);
    for (auto& ihit : m_UniqueItemInfo)
        DoAllEffectOnTarget(&ihit);

    // process ground
    for (uint8 j = 0; j < MAX_EFFECT_INDEX; ++j)
    {
        // persistent area auras target only the ground
        if (m_spellInfo->Effect[j] == SPELL_EFFECT_PERSISTENT_AREA_AURA)
            HandleEffects(nullptr, nullptr, nullptr, SpellEffectIndex(j));
    }
}

void Spell::_handle_finish_phase()
{
    if (Unit* unitCaster = m_caster->ToUnit())
    {
        // Take for real after all targets are processed
        if (m_needComboPoints)
            unitCaster->ClearComboPoints();

        // Real add combo points from effects
        if (m_comboPointGain)
            unitCaster->AddComboPoints(m_comboPointGain);
    // spell log
    if (m_needSpellLog)
        SendLogExecute();
}

        if (m_spellInfo->HasEffect(SPELL_EFFECT_ADD_EXTRA_ATTACKS))
            unitCaster->SetLastExtraAttackSpell(m_spellInfo->Id);
    }
void Spell::SendSpellCooldown()
{
    // (SPELL_ATTR_DISABLED_WHILE_ACTIVE) have infinity cooldown, (SPELL_ATTR_PASSIVE) passive cooldown at triggering
    if (m_spellInfo->HasAttribute(SPELL_ATTR_PASSIVE))
        return;

    if (Player* pPlayer = m_caster->ToPlayer())
        if (pPlayer->HasCheatOption(PLAYER_CHEAT_NO_COOLDOWN))
            return;

    ProcFlagsInit procAttacker = m_procAttacker;
    if (!procAttacker)
    {
        if (m_spellInfo->HasAttribute(SPELL_ATTR3_TREAT_AS_PERIODIC))
        {
            if (IsPositive())
                procAttacker |= PROC_FLAG_DEAL_HELPFUL_PERIODIC;
            else
                procAttacker |= PROC_FLAG_DEAL_HARMFUL_PERIODIC;
        }
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
    m_caster->AddCooldown(*m_spellInfo, m_CastItem ? m_CastItem->GetProto() : nullptr, m_spellInfo->HasAttribute(SPELL_ATTR_DISABLED_WHILE_ACTIVE));
}

void Spell::update(uint32 difftime)
{
    // update pointers based at it's GUIDs
    UpdatePointers();

    if (!m_spellInfo->HasAttribute(SPELL_ATTR3_SUPPRESS_CASTER_PROCS))
        Unit::ProcSkillsAndAuras(m_originalCaster, nullptr, procAttacker, PROC_FLAG_NONE, PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_FINISH, m_hitMask, this, nullptr, nullptr);
}
    if (m_targets.getUnitTargetGuid() && !m_targets.getUnitTarget())
    {
        cancel();
        return;
    }

void Spell::SendSpellCooldown()
{
    if (!m_caster->IsUnit())
        return;

    if (m_CastItem)
        m_caster->ToUnit()->GetSpellHistory()->HandleCooldowns(m_spellInfo, m_CastItem, this);
    // check if the player caster has moved before the spell finished
    float nowPosX, nowPosY, nowPosZ, nowO;
    if (m_caster->GetTransport())
    {
        nowPosX = m_caster->GetTransOffsetX();
        nowPosY = m_caster->GetTransOffsetY();
        nowPosZ = m_caster->GetTransOffsetZ();
        nowO = m_caster->GetTransOffsetO();
    }
    else
        m_caster->ToUnit()->GetSpellHistory()->HandleCooldowns(m_spellInfo, m_castItemEntry, this);

    if (IsAutoRepeat())
        m_caster->ToUnit()->resetAttackTimer(RANGED_ATTACK);
}
    {
        nowPosX = m_caster->GetPositionX();
        nowPosY = m_caster->GetPositionY();
        nowPosZ = m_caster->GetPositionZ();
        nowO = m_caster->GetOrientation();
    }
    if ((m_caster->IsPlayer() && m_timer != 0) &&
            (fabs(m_castPosition.x - nowPosX) > 0.5f || fabs(m_castPosition.y - nowPosY) > 0.5f || fabs(m_castPosition.z - nowPosZ) > 0.5f) &&
            (m_spellInfo->Effect[EFFECT_INDEX_0] != SPELL_EFFECT_STUCK || !((Player*)m_caster)->m_movementInfo.HasMovementFlag(MOVEFLAG_FALLINGFAR)) &&
            ((m_spellInfo->Id != 24322) && (m_spellInfo->Id != 24323)))
    {
        // always cancel for channeled spells
        if (m_spellState == SPELL_STATE_CASTING)
        {
            bool bInterrupt = true;

void Spell::update(uint32 difftime)
{
    // update pointers based at it's GUIDs
    if (!UpdatePointers())
    {
        // cancel the spell if UpdatePointers() returned false, something wrong happened there
        cancel();
        return;
    }

    if (!m_targets.GetUnitTargetGUID().IsEmpty() && !m_targets.GetUnitTarget())
    {
        TC_LOG_DEBUG("spells", "Spell {} is cancelled due to removal of target.", m_spellInfo->Id);
        cancel();
        return;
            if (m_casterUnit)
            {
                // except if its a self root, since player could have moved a bit before root ack (ravager proc)
                for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
                {
                    if ((m_spellInfo->Effect[i] == SPELL_EFFECT_APPLY_AURA) &&
                        ((m_spellInfo->EffectApplyAuraName[i] == SPELL_AURA_MOD_ROOT) || (m_spellInfo->EffectApplyAuraName[i] == SPELL_AURA_MOD_STUN)) &&
                        (m_spellInfo->EffectImplicitTargetA[i] == TARGET_UNIT_CASTER))
                    {
                        bInterrupt = !(m_casterUnit->IsRooted() || m_casterUnit->HasPendingMovementChange(ROOT));
                        break;
                    }
                }
            }

            if (bInterrupt)
                cancel();
        }
        // don't cancel for melee, autorepeat, triggered and instant spells
        else if (!m_spellInfo->IsNextMeleeSwingSpell() && !IsAutoRepeat() && !m_IsTriggeredSpell && (m_spellInfo->InterruptFlags & SPELL_INTERRUPT_FLAG_MOVEMENT))
            cancel();
    }

    // check if the player caster has moved before the spell finished
    // with the exception of spells affected with SPELL_AURA_CAST_WHILE_WALKING effect
    if (m_timer != 0 && m_caster->IsUnit() && m_caster->ToUnit()->isMoving() && CheckMovement() != SPELL_CAST_OK)
    // summoning ritual
    if (GameObject* pGo = m_targets.getGOTarget())
    {
        // if charmed by creature, trust the AI not to cheat and allow the cast to proceed
        // @todo this is a hack, "creature" movesplines don't differentiate turning/moving right now
        // however, checking what type of movement the spline is for every single spline would be really expensive
        if (!m_caster->ToUnit()->GetCharmerGUID().IsCreature())
            cancel();
    }
        if (GameObjectInfo const* pInfo = pGo->GetGOInfo())
            // triggered spell
            if (pGo->GetGoType() == GAMEOBJECT_TYPE_SUMMONING_RITUAL &&
                m_spellInfo->Id == pInfo->summoningRitual.spellId &&
                // too many helpers cancelled
                (pGo->GetUniqueUseCount() < pInfo->summoningRitual.reqParticipants ||
                // the warlock cancelled
                (!pInfo->summoningRitual.ritualPersistent && !pGo->GetOwner())))
            {
                cancel();
                pGo->SetGoState(GO_STATE_READY);
                if (!pInfo->summoningRitual.ritualPersistent)
                    pGo->Delete();
            }
    }
    // visual spell and deleted ritual object
    else if (IsChannelingVisual())
        cancel();

    switch (m_spellState)
    {
        case SPELL_STATE_PREPARING:
        {
            if (m_timer)
            {
                // check for incapacitating states
                if (m_casterUnit && m_casterUnit->IsPlayer())
                {
                    uint32 interruptStates = (UNIT_STAT_FEIGN_DEATH | UNIT_STAT_CONFUSED | UNIT_STAT_FLEEING);
                    if (m_spellInfo->InterruptFlags & SPELL_INTERRUPT_FLAG_STUN)
                        interruptStates |= UNIT_STAT_STUNNED;
                    if (m_casterUnit->HasUnitState(interruptStates))
                        cancel();
                }

                if (difftime >= m_timer)
                    m_timer = 0;
                else
                    m_timer -= difftime;
            }

            if (m_timer == 0 && !m_spellInfo->IsNextMeleeSwingSpell())
                // don't CheckCast for instant spells - done in spell::prepare, skip duplicate checks, needed for range checks for example
                cast(!m_casttime);
            break;
        }
            if (m_timer == 0 && !m_spellInfo->IsNextMeleeSwingSpell() && !IsAutoRepeat())
            {
                RemoveStealthAuras();
                cast();

                // For channeled spells with a cast time, cast start position is set when channeling begins.
                if (m_channeled)
                    UpdateCastStartPosition();
            }
        }
        break;
        case SPELL_STATE_CASTING:
        {
            if (m_timer)
            {
                // check if there are alive targets left
                if (!UpdateChanneledTargetList())
                {
                    TC_LOG_DEBUG("spells", "Channeled spell {} is removed due to lack of targets", m_spellInfo->Id);
                    m_timer = 0;

                    // Also remove applied auras
                    for (TargetInfo const& target : m_UniqueTargetInfo)
                        if (Unit* unit = m_caster->GetGUID() == target.TargetGUID ? m_caster->ToUnit() : ObjectAccessor::GetUnit(*m_caster, target.TargetGUID))
                            unit->RemoveOwnedAura(m_spellInfo->Id, m_originalCasterGUID, 0, AURA_REMOVE_BY_CANCEL);
                }
            if (m_timer > 0)
            {
                if (m_caster->IsPlayer() || m_caster->IsPet())
                {
                    // check for incapacitating player states
                    if (m_casterUnit->HasUnitState(UNIT_STAT_CAN_NOT_REACT))
                    {
                        if (m_casterUnit->HasUnitState(UNIT_STAT_FEIGN_DEATH) ||
                           (m_casterUnit->HasUnitState(UNIT_STAT_STUNNED) && !(m_channeled && m_spellInfo->HasAura(SPELL_AURA_MOD_STUN))) ||
                           (m_casterUnit->HasUnitState(UNIT_STAT_CONFUSED) && !(m_channeled && m_spellInfo->HasAura(SPELL_AURA_MOD_CONFUSE))) ||
                           (m_casterUnit->HasUnitState(UNIT_STAT_FLEEING) && !(m_channeled && m_spellInfo->HasAura(SPELL_AURA_MOD_FEAR))))
                            cancel();
                    }
                }

                if (m_caster->IsPlayer() && (m_spellInfo->Id != 24322) && (m_spellInfo->Id != 24323))
                {
                    // check if player has jumped before the channeling finished
                    if (((Player*)m_caster)->m_movementInfo.HasMovementFlag(MOVEFLAG_JUMPING))
                        cancel();

                    // check if player has turned if flag is set
                    if (m_spellInfo->ChannelInterruptFlags & CHANNEL_FLAG_TURNING_CANCELS && m_castPosition.o != nowO)
                        cancel();
                }

            if (m_timer == 0)
            {
                SendChannelUpdate(0);
                finish();

                // We call the hook here instead of in Spell::finish because we only want to call it for completed channeling. Everything else is handled by interrupts
                if (Creature* creatureCaster = m_caster->ToCreature())
                    if (creatureCaster->IsAIEnabled())
                        creatureCaster->AI()->OnChannelFinished(m_spellInfo);
            }
            break;
        }
        default:
            break;
    }
}
                // check if there are alive targets left
                if (!HasValidUnitPresentInTargetList())
                {
                    SendChannelUpdate(0);
                    finish();
                }

void Spell::finish(bool ok)
{
    if (m_spellState == SPELL_STATE_FINISHED)
        return;
    m_spellState = SPELL_STATE_FINISHED;

    if (!m_caster)
        return;
                // Must update target holder since the target will not update it. Used to keep it in sync
                // If the cast is interrupted mid-iteration (i.e. unit dies), break
                // Note that we cannot ensure that only 1 aura holder is removed from the list at a time
                // during iteration, since some creature scripts force all summoned adds to despawn on
                // death, which means that multiple units will have their auras removed at once. So
                // we maintain an iter that points to the next holder and increment it on removals
                m_channeledUpdateIterator = m_channeledHolders.begin();
                SpellAuraHolderList::iterator curr;
                while (m_channeledUpdateIterator != m_channeledHolders.end())
                {
                    // Store current and increment, since m_channeledUpdateIterator
                    // may be changed externally but we still need a way to step in
                    // this loop
                    curr = m_channeledUpdateIterator;
                    ++m_channeledUpdateIterator;

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
                && charm->m_unitData->CreatedBySpell == int32(m_spellInfo->Id))
                ((Puppet*)charm)->UnSummon();
    }
                    SpellAuraHolder* holder = *curr;
                    // Holder deleted before updating, but not removed from list. Clear usage
                    // and remove
                    if (holder->IsDeleted())
                    {
                        Unit* target = m_targets.getUnitTarget();
                        sLog.outError("[Spell] - Channeled update still maintains ref to deleted holder, caster: %s. Target: %s",
                            m_caster->GetGuidStr().c_str(), 
                            target ? target->GetGuidStr().c_str() : "");

                        // TODO: Is this a leak if we don't delete it here? Unit probably removed from world
                        holder->SetInUse(false);
                        m_channeledHolders.erase(curr);
                        continue;
                    }

    if (Creature* creatureCaster = unitCaster->ToCreature())
        creatureCaster->ReleaseSpellFocus(this);
                    holder->UpdateHolder(difftime);

    if (!m_spellInfo->HasAttribute(SPELL_ATTR3_SUPPRESS_CASTER_PROCS))
        Unit::ProcSkillsAndAuras(unitCaster, nullptr, PROC_FLAG_CAST_ENDED, PROC_FLAG_NONE, PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_NONE, PROC_HIT_NONE, this, nullptr, nullptr);

    if (!ok)
    {
        // on failure (or manual cancel) send TraitConfigCommitFailed to revert talent UI saved config selection
        if (m_caster->IsPlayer() && m_spellInfo->HasEffect(SPELL_EFFECT_CHANGE_ACTIVE_COMBAT_TRAIT_CONFIG))
            if (WorldPackets::Traits::TraitConfig const* traitConfig = std::any_cast<WorldPackets::Traits::TraitConfig>(&m_customArg))
                m_caster->ToPlayer()->SendDirectMessage(WorldPackets::Traits::TraitConfigCommitFailed(traitConfig->ID).Write());

        return;
    }
                    // Spell cast was interrupted on holder update. Unit likely died, targetted buff was
                    // dispelled, or unit ran out of range. Return since we cleaned up in
                    // SendChannelUpdate(0) on cancel. Similarly, if AoE and unit died the holder
                    // was already removed.
                    if (m_spellState == SPELL_STATE_FINISHED)
                        return;

    if (unitCaster->GetTypeId() == TYPEID_UNIT && unitCaster->IsSummon())
    {
        // Unsummon statue
        uint32 spell = unitCaster->m_unitData->CreatedBySpell;
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spell, GetCastDifficulty());
        if (spellInfo && spellInfo->IconFileDataId == 134230)
        {
            TC_LOG_DEBUG("spells", "Statue {} is unsummoned in spell {} finish", unitCaster->GetGUID().ToString(), m_spellInfo->Id);
            // Avoid infinite loops with setDeathState(JUST_DIED) being called over and over
            // It might make sense to do this check in Unit::setDeathState() and all overloaded functions
            if (unitCaster->getDeathState() != JUST_DIED)
                unitCaster->setDeathState(JUST_DIED);
            return;
        }
    }
                    // We can handle typical remove modes here
                    AuraRemoveMode remove = holder->GetRemoveMode();
                    if ((holder->GetAuraDuration() == 0 && !holder->IsDeleted()) ||
                            (holder->IsDeleted() && (remove == AURA_REMOVE_BY_RANGE || remove == AURA_REMOVE_BY_GROUP)))
                    {
                        holder->SetInUse(false);
                        m_channeledHolders.erase(curr);
                    }
                }

    if (IsAutoActionResetSpell())
    {
        if (!m_spellInfo->HasAttribute(SPELL_ATTR2_DO_NOT_RESET_COMBAT_TIMERS))
        {
            unitCaster->resetAttackTimer(BASE_ATTACK);
            if (unitCaster->haveOffhandWeapon())
                unitCaster->resetAttackTimer(OFF_ATTACK);
            unitCaster->resetAttackTimer(RANGED_ATTACK);
        }
    }
                if (difftime >= m_timer)
                    m_timer = 0;
                else
                    m_timer -= difftime;
            }

    // potions disabled by client, send event "not in combat" if need
    if (unitCaster->GetTypeId() == TYPEID_PLAYER)
    {
        if (!m_triggeredByAuraSpell)
            unitCaster->ToPlayer()->UpdatePotionCooldown(this);
    }
            if (m_timer == 0)
            {
                SendChannelUpdate(0);

    // Stop Attack for some spells
    if (m_spellInfo->HasAttribute(SPELL_ATTR0_CANCELS_AUTO_ATTACK_COMBAT))
        unitCaster->AttackStop();
}

template<class T>
inline void FillSpellCastFailedArgs(T& packet, ObjectGuid castId, SpellInfo const* spellInfo, SpellCastResult result, SpellCustomErrors customError, int32* param1 /*= nullptr*/, int32* param2 /*= nullptr*/, Player* caster)
{
    packet.CastID = castId;
    packet.SpellID = spellInfo->Id;
    packet.Reason = result;

    switch (result)
    {
        case SPELL_FAILED_NOT_READY:
            if (param1)
                packet.FailedArg1 = *param1;
            else
                packet.FailedArg1 = 0;                              // unknown (value 1 update cooldowns on client flag)
            break;
        case SPELL_FAILED_REQUIRES_SPELL_FOCUS:
            if (param1)
                packet.FailedArg1 = *param1;
            else
                packet.FailedArg1 = spellInfo->RequiresSpellFocus;  // SpellFocusObject.dbc id
            break;
        case SPELL_FAILED_REQUIRES_AREA:                            // AreaTable.dbc id
            if (param1)
                packet.FailedArg1 = *param1;
            else
            {
                // hardcode areas limitation case
                switch (spellInfo->Id)
                {
                    case 41617:                                     // Cenarion Mana Salve
                    case 41619:                                     // Cenarion Healing Salve
                        packet.FailedArg1 = 3905;
                        break;
                    case 41618:                                     // Bottled Nethergon Energy
                    case 41620:                                     // Bottled Nethergon Vapor
                        packet.FailedArg1 = 3842;
                        break;
                    case 45373:                                     // Bloodberry Elixir
                        packet.FailedArg1 = 4075;
                        break;
                    default:                                        // default case (don't must be)
                        packet.FailedArg1 = 0;
                        break;
                }
            }
            break;
        case SPELL_FAILED_TOTEMS:
            if (param1)
            {
                packet.FailedArg1 = *param1;
                if (param2)
                    packet.FailedArg2 = *param2;
            }
            else
            {
                if (spellInfo->Totem[0])
                    packet.FailedArg1 = spellInfo->Totem[0];
                if (spellInfo->Totem[1])
                    packet.FailedArg2 = spellInfo->Totem[1];
            }
            break;
        case SPELL_FAILED_TOTEM_CATEGORY:
            if (param1)
            {
                packet.FailedArg1 = *param1;
                if (param2)
                    packet.FailedArg2 = *param2;
            }
            else
            {
                if (spellInfo->TotemCategory[0])
                    packet.FailedArg1 = spellInfo->TotemCategory[0];
                if (spellInfo->TotemCategory[1])
                    packet.FailedArg2 = spellInfo->TotemCategory[1];
                // channeled spell processed independently for quest targeting
                // cast at creature (or GO) quest objectives update at successful cast channel finished
                // ignore autorepeat/melee casts for speed (not exist quest for spells (hm... )
                if (!IsAutoRepeat() && !m_spellInfo->IsNextMeleeSwingSpell())
                {
                    if (Player* p = m_casterUnit ? m_casterUnit->GetCharmerOrOwnerPlayerOrPlayerItself() : nullptr)
                    {
                        for (const auto& ihit : m_UniqueTargetInfo)
                        {
                            if (ihit.deleted)
                                continue;

                            TargetInfo const& target = ihit;
                            if (!target.targetGUID.IsCreature())
                                continue;

                            Unit* unit = m_caster->GetObjectGuid() == target.targetGUID ? m_casterUnit : ObjectAccessor::GetUnit(*m_caster, target.targetGUID);
                            if (unit == nullptr)
                                continue;

                            p->RewardPlayerAndGroupAtCast(unit, m_spellInfo->Id);
                        }

                        for (const auto& ihit : m_UniqueGOTargetInfo)
                        {
                            if (ihit.deleted)
                                continue;

                            GOTargetInfo const& target = ihit;

                            GameObject* go = m_caster->GetMap()->GetGameObject(target.targetGUID);
                            if (!go)
                                continue;

                            p->RewardPlayerAndGroupAtCast(go, m_spellInfo->Id);
                        }
                    }
                }

                finish();
            }
        }
        break;
        default:
        {
            if (param1)
                packet.FailedArg1 = *param1;
            else
            {
                uint32 item = 0;
                for (SpellEffectInfo const& spellEffectInfo : spellInfo->GetEffects())
                {
                    if (uint32 itemType = spellEffectInfo.ItemType)
                    {
                        item = itemType;
                        break;
                    }
                }

                ItemTemplate const* proto = sObjectMgr->GetItemTemplate(item);
                if (proto && proto->GetItemLimitCategory())
                    packet.FailedArg1 = proto->GetItemLimitCategory();
            }
            break;
        }
        case SPELL_FAILED_PREVENTED_BY_MECHANIC:
            if (param1)
                packet.FailedArg1 = *param1;
            else
                packet.FailedArg1 = spellInfo->GetAllEffectsMechanicMask();  // SpellMechanic.dbc id
            break;
        case SPELL_FAILED_NEED_EXOTIC_AMMO:
            if (param1)
                packet.FailedArg1 = *param1;
            else
                packet.FailedArg1 = spellInfo->EquippedItemSubClassMask; // seems correct...
            break;
        case SPELL_FAILED_NEED_MORE_ITEMS:
            if (param1 && param2)
            {
                packet.FailedArg1 = *param1;
                packet.FailedArg2 = *param2;
            }
            else
            {
                packet.FailedArg1 = 0;                              // Item id
                packet.FailedArg2 = 0;                              // Item count?
            }
            break;
        case SPELL_FAILED_MIN_SKILL:
            if (param1 && param2)
            {
                packet.FailedArg1 = *param1;
                packet.FailedArg2 = *param2;
            }
            else
            {
                packet.FailedArg1 = 0;                              // SkillLine.dbc id
                packet.FailedArg2 = 0;                              // required skill value
            }
            break;
        case SPELL_FAILED_FISHING_TOO_LOW:
            if (param1)
                packet.FailedArg1 = *param1;
            else
                packet.FailedArg1 = 0;                              // required fishing skill
            break;
        case SPELL_FAILED_CUSTOM_ERROR:
            packet.FailedArg1 = customError;
            break;
        case SPELL_FAILED_SILENCED:
            if (param1)
                packet.FailedArg1 = *param1;
            else
                packet.FailedArg1 = 0;                              // Unknown
            break;
        case SPELL_FAILED_REAGENTS:
        {
            if (param1)
                packet.FailedArg1 = *param1;
            else
            {
                for (uint32 i = 0; i < MAX_SPELL_REAGENTS; i++)
                {
                    if (spellInfo->Reagent[i] <= 0)
                        continue;

                    uint32 itemid = spellInfo->Reagent[i];
                    uint32 itemcount = spellInfo->ReagentCount[i];

                    if (!caster->HasItemCount(itemid, itemcount))
                    {
                        packet.FailedArg1 = itemid;  // first missing item
                        break;
                    }
                }
            }

            if (param2)
                packet.FailedArg2 = *param2;
            else if (!param1)
            {
                for (SpellReagentsCurrencyEntry const* reagentsCurrency : spellInfo->ReagentsCurrency)
                {
                    if (!caster->HasCurrency(reagentsCurrency->CurrencyTypesID, reagentsCurrency->CurrencyCount))
                    {
                        packet.FailedArg1 = -1;
                        packet.FailedArg2 = reagentsCurrency->CurrencyTypesID;
                        break;
                    }
                }
            }

            break;
        }
        case SPELL_FAILED_CANT_UNTALENT:
        {
            ASSERT(param1);
            packet.FailedArg1 = *param1;
            break;
        }
        // TODO: SPELL_FAILED_NOT_STANDING
        default:
            break;
    }
}
        } break;
    }
}

void Spell::HandleAddTargetTriggerAuras()
{
    if (!m_casterUnit)
        return;

    // handle SPELL_AURA_ADD_TARGET_TRIGGER auras
    auto const& targetTriggers = m_casterUnit->GetAurasByType(SPELL_AURA_ADD_TARGET_TRIGGER);
    for (const auto targetTrigger : targetTriggers)
    {
        if (!targetTrigger->isAffectedOnSpell(m_spellInfo))
            continue;
        for (const auto& ihit : m_UniqueTargetInfo)
        {
            if (ihit.deleted)
                continue;
            Unit* target = nullptr;
            if (ihit.missCondition == SPELL_MISS_NONE)
                target = m_casterUnit->GetObjectGuid() == ihit.targetGUID ? m_casterUnit : ObjectAccessor::GetUnit(*m_casterUnit, ihit.targetGUID);
            else if (ihit.missCondition == SPELL_MISS_REFLECT && ihit.reflectResult == SPELL_MISS_NONE)
                target = m_casterUnit;
            if (!target)
                continue;
            if (target && target->IsAlive())
            {
                SpellEntry const* auraSpellInfo = targetTrigger->GetSpellProto();
                SpellEffectIndex auraSpellIdx = targetTrigger->GetEffIndex();
                // Calculate chance at that moment (can be depend for example from combo points)
                int32 auraBasePoints = targetTrigger->GetBasePoints();
                int32 chance = m_casterUnit->CalculateSpellEffectValue(target, auraSpellInfo, auraSpellIdx, &auraBasePoints);
                if ((m_casterUnit->IsPlayer() && m_casterUnit->ToPlayer()->HasCheatOption(PLAYER_CHEAT_ALWAYS_PROC)) || roll_chance_i(chance))
                    m_casterUnit->CastSpell(target, auraSpellInfo->EffectTriggerSpell[auraSpellIdx], true, nullptr, targetTrigger);
            }
        }
    }
}

void Spell::SendCastResult(SpellCastResult result, int32* param1 /*= nullptr*/, int32* param2 /*= nullptr*/) const
void Spell::finish(bool ok)
{
    m_successCast = ok;

    if (!m_caster)
        return;

    if (m_spellState == SPELL_STATE_FINISHED)
        return;

    m_spellState = SPELL_STATE_FINISHED;

    // Clear the creature's casting target so it faces victim
    if (m_setCreatureTarget)
        static_cast<Creature*>(m_caster)->ClearCastingTarget();

void Spell::SendPetCastResult(SpellCastResult result, int32* param1 /*= nullptr*/, int32* param2 /*= nullptr*/) const
{
    if (result == SPELL_CAST_OK)
        return;
    if (Player* pPlayer = m_caster->ToPlayer())
    {
        if (!ok && pPlayer->GetClass() == CLASS_WARLOCK)
        {
            // Fix a client problem with ritual of doom, by itself it disables
            // the spell during cast and then the spell stays disabled
            // Ignore the spell when it's triggered (ritual helper)
            if (m_spellInfo->Id == 18540 && !m_IsTriggeredSpell
                && pPlayer->IsSpellReady(m_spellInfo->Id))
                pPlayer->ToPlayer()->SendClearCooldown(18540, pPlayer);
        }

        if (ok && pPlayer->HasCheatOption(PLAYER_CHEAT_NO_COOLDOWN))
            pPlayer->SendClearCooldown(m_spellInfo->Id, pPlayer);
    }

void Spell::SendCastResult(Player* caster, SpellInfo const* spellInfo, SpellCastVisual spellVisual, ObjectGuid cast_count, SpellCastResult result, SpellCustomErrors customError /*= SPELL_CUSTOM_ERROR_NONE*/, int32* param1 /*= nullptr*/, int32* param2 /*= nullptr*/)
{
    if (result == SPELL_CAST_OK)
        return;

    WorldPackets::Spells::CastFailed packet;
    packet.Visual = spellVisual;
    FillSpellCastFailedArgs(packet, cast_count, spellInfo, result, customError, param1, param2, caster);
    caster->SendDirectMessage(packet.Write());
}
    // Restore pet movement after spell (succubus after seduce)
    if (CharmInfo* ci = m_casterUnit ? m_casterUnit->GetCharmInfo() : nullptr)
    {
        ci->SetIsAtStay(false);
        ci->SetIsCommandFollow(false);
        ci->SetIsFollowing(false);
        ci->SetIsReturning(false);
    }

    // other code related only to successfully finished spells
    if (!ok)
    {
        m_caster->ResetGCD(m_spellInfo);
        if (m_caster->IsPlayer())
            m_caster->ToPlayer()->RestoreSpellMods(this);
        return;
    }

    if (!m_channeled)
        HandleAddTargetTriggerAuras();

    /*if (IsRangedAttackResetSpell())
        m_caster->ResetAttackTimer(RANGED_ATTACK);*/

    // Clear combo at finish state
    if (m_caster->IsPlayer() && m_spellInfo->NeedsComboPoints())
    {
        // Not drop combopoints if negative spell and if any miss on enemy exist
        bool needDrop = true;
        if (!m_spellInfo->IsPositiveSpell())
        {
            for (const auto& ihit : m_UniqueTargetInfo)
            {
                if (ihit.deleted)
                    continue;

                if (ihit.missCondition != SPELL_MISS_NONE && ihit.targetGUID != m_caster->GetObjectGuid())
                {
                    needDrop = false;
                    break;
                }
            }
        }
        if (needDrop)
            ((Player*)m_caster)->ClearComboPoints();
    }

    TC_LOG_DEBUG("spells", "Sending SMSG_SPELL_START id={}", m_spellInfo->Id);
    // call triggered spell only at successful cast (after clear combo points -> for add some if need)
    if (!m_TriggerSpells.empty())
        CastTriggerSpells();

    uint32 castFlags = CAST_FLAG_HAS_TRAJECTORY;
    uint32 schoolImmunityMask = 0;
    uint32 mechanicImmunityMask = 0;
    if (Unit* unitCaster = m_caster->ToUnit())
    {
        schoolImmunityMask = m_timer!= 0 ? unitCaster->GetSchoolImmunityMask() : 0;
        mechanicImmunityMask = m_timer != 0 ? m_spellInfo->GetMechanicImmunityMask(unitCaster) : 0;
    }

    if (schoolImmunityMask || mechanicImmunityMask)
        castFlags |= CAST_FLAG_IMMUNITY;

    if (((IsTriggered() && !m_spellInfo->IsAutoRepeatRangedSpell()) || m_triggeredByAuraSpell) && !m_fromClient)
        castFlags |= CAST_FLAG_PENDING;

    if (m_spellInfo->HasAttribute(SPELL_ATTR0_USES_RANGED_SLOT) || m_spellInfo->HasAttribute(SPELL_ATTR10_USES_RANGED_SLOT_COSMETIC_ONLY) || m_spellInfo->HasAttribute(SPELL_ATTR0_CU_NEEDS_AMMO_DATA))
        castFlags |= CAST_FLAG_PROJECTILE;

    if ((m_caster->GetTypeId() == TYPEID_PLAYER ||
        (m_caster->GetTypeId() == TYPEID_UNIT && m_caster->ToCreature()->IsPet()))
        && std::find_if(m_powerCost.begin(), m_powerCost.end(), [](SpellPowerCost const& cost) { return cost.Power != POWER_HEALTH; }) != m_powerCost.end())
        castFlags |= CAST_FLAG_POWER_LEFT_SELF;

    if (HasPowerTypeCost(POWER_RUNES))
        castFlags |= CAST_FLAG_NO_GCD; // not needed, but Blizzard sends it

    WorldPackets::Spells::SpellStart packet;
    WorldPackets::Spells::SpellCastData& castData = packet.Cast;

    if (m_CastItem)
        castData.CasterGUID = m_CastItem->GetGUID();
    else
        castData.CasterGUID = m_caster->GetGUID();

    castData.CasterUnit = m_caster->GetGUID();
    castData.CastID = m_castId;
    castData.OriginalCastID = m_originalCastId;
    castData.SpellID = m_spellInfo->Id;
    castData.Visual = m_SpellVisual;
    castData.CastFlags = castFlags;
    castData.CastFlagsEx = m_castFlagsEx;
    castData.CastTime = m_casttime;

    m_targets.Write(castData.Target);

    if (castFlags & CAST_FLAG_POWER_LEFT_SELF)
    // Gnomish Death Ray
    if (m_spellInfo->Id == 13278)
    {
        if (Unit* const pTarget = m_targets.getUnitTarget())
        {
            WorldPackets::Spells::SpellPowerData powerData;
            powerData.Type = cost.Power;
            powerData.Cost = ASSERT_NOTNULL(m_caster->ToUnit())->GetPower(cost.Power);
            castData.RemainingPower.push_back(powerData);
            SpellEntry const* DRLaunchEntry = sSpellMgr.GetSpellEntry(13279);
            float DRdamage = m_caster->CalculateSpellEffectValue(pTarget, DRLaunchEntry, EFFECT_INDEX_0, m_currentBasePoints, nullptr);
            m_caster->CastCustomSpell(pTarget, 13279, dither(DRdamage), {}, {}, true, m_CastItem);
        }
    }

    if (m_caster->IsPlayer())
    {
        castData.RemainingRunes.emplace();
        m_caster->ToPlayer()->RemoveSpellMods(this);

        // summoning ritual triggered spell successfull hit
        if (GameObject* pGo = m_targets.getGOTarget())
            if (pGo->GetGoType() == GAMEOBJECT_TYPE_SUMMONING_RITUAL)
                if (m_spellInfo->Id == pGo->GetGOInfo()->summoningRitual.spellId)
                    pGo->FinishRitual();
    }

    if (m_casterUnit)
    {
        // Stop Attack for some spells
        if (m_spellInfo->Attributes & SPELL_ATTR_STOP_ATTACK_TARGET)
        {
            m_casterUnit->AttackStop();
            m_casterUnit->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
        }
        else if ((m_spellInfo->AttributesEx & SPELL_ATTR_EX_MELEE_COMBAT_START))
        {
            // Pets should initiate melee combat on spell with this flag. (Growl)
            if (Pet* pPet = m_casterUnit->ToPet())
                if (pPet->AI() && pPet->GetCharmInfo())
                    if (Unit* const pTarget = m_targets.getUnitTarget())
                    {
                        pPet->GetCharmInfo()->SetIsCommandAttack(true);
                        pPet->AI()->AttackStart(pTarget);
                    }
        }
    }
    
}

void Spell::SendCastResult(SpellCastResult result)
{
    if (!m_caster->IsPlayer())
        return;

    TC_LOG_DEBUG("spells", "Sending SMSG_SPELL_GO id={}", m_spellInfo->Id);
    if (((Player*)m_caster)->GetSession()->PlayerLoading()) // don't send cast results at loading time
        return;

    if (result == SPELL_CAST_OK && m_IsTriggeredSpell)
        return;

    SendCastResult((Player*)m_caster, m_originalSpellInfo ? m_originalSpellInfo : m_spellInfo, result);
}

    if (m_spellInfo->HasAttribute(SPELL_ATTR0_USES_RANGED_SLOT) || m_spellInfo->HasAttribute(SPELL_ATTR10_USES_RANGED_SLOT_COSMETIC_ONLY) || m_spellInfo->HasAttribute(SPELL_ATTR0_CU_NEEDS_AMMO_DATA))
        castFlags |= CAST_FLAG_PROJECTILE; // arrows/bullets visual
void Spell::SendCastResult(Player* caster, SpellEntry const* spellInfo, SpellCastResult result)
{
    WorldPacket data(SMSG_CAST_RESULT, (4 + 1 + 1));
    data << uint32(spellInfo->Id);

    if ((m_caster->GetTypeId() == TYPEID_PLAYER ||
        (m_caster->GetTypeId() == TYPEID_UNIT && m_caster->ToCreature()->IsPet()))
        && std::find_if(m_powerCost.begin(), m_powerCost.end(), [](SpellPowerCost const& cost) { return cost.Power != POWER_HEALTH; }) != m_powerCost.end())
        castFlags |= CAST_FLAG_POWER_LEFT_SELF;

    if ((m_caster->GetTypeId() == TYPEID_PLAYER)
        && (m_caster->ToPlayer()->GetClass() == CLASS_DEATH_KNIGHT)
        && HasPowerTypeCost(POWER_RUNES)
        && !(_triggeredCastFlags & TRIGGERED_IGNORE_POWER_AND_REAGENT_COST))
    if (result != SPELL_CAST_OK)
    {
        castFlags |= CAST_FLAG_NO_GCD; // not needed, but Blizzard sends it
        castFlags |= CAST_FLAG_RUNE_LIST; // rune cooldowns list
    }
        data << uint8(2); // status = fail
        data << uint8(spellInfo->IsPassiveSpell() ? SPELL_FAILED_DONT_REPORT : result);                                  // problem
        switch (result)
        {
            case SPELL_FAILED_REQUIRES_SPELL_FOCUS:
                data << uint32(spellInfo->RequiresSpellFocus);
                break;
            case SPELL_FAILED_REQUIRES_AREA:
                data << uint32(sSpellMgr.GetRequiredAreaForSpell(spellInfo->Id));
                break;
            case SPELL_FAILED_EQUIPPED_ITEM_CLASS:
                data << uint32(spellInfo->EquippedItemClass);
                data << uint32(spellInfo->EquippedItemSubClassMask);
                data << uint32(spellInfo->EquippedItemInventoryTypeMask);
                break;
            default:
                break;
        }
    }
    else
        data << uint8(0);

    caster->GetSession()->SendPacket(&data);
}

void Spell::SendSpellStart()
{
    if (!IsNeedSendToClient())
        return;

    WorldPackets::Spells::SpellGo packet;
    WorldPackets::Spells::SpellCastData& castData = packet.Cast;
    DEBUG_FILTER_LOG(LOG_FILTER_SPELL_CAST, "Sending SMSG_SPELL_START id=%u", m_spellInfo->Id);

    uint32 castFlags = CAST_FLAG_UNKNOWN2;
    if (m_spellInfo->IsRangedSpell())
        castFlags |= CAST_FLAG_AMMO;

    // Youfie <Nostalrius> : Sandtrap : dans le combatlog il n'y a plus de debuff avant l'apparition du Sand trap
    // Seul truc pas Blizz-like : c'est le joueur qui caste le sort, et pas Kurinaxx ; faudra fix dans le script de Kurinaxx quand le core sera debug pour le supporter
    if (m_spellInfo->Id == 25648)
        castFlags = CAST_FLAG_HIDDEN_COMBATLOG;

    WorldPacket data(SMSG_SPELL_START, (8 + 8 + 4 + 2 + 4));
    if (m_CastItem)
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
        data << m_CastItem->GetPackGUID();
    else
        data << m_caster->GetPackGUID();

    data << m_caster->GetPackGUID();
#else
        data << m_CastItem->GetGUID();
    else
        data << m_caster->GetGUID();

    data << m_caster->GetGUID();
#endif
    data << uint32(m_spellInfo->Id);                        // spellId
    data << uint16(castFlags);                              // cast flags
    data << uint32(m_timer);                                // delay?

    data << m_targets;

    if (castFlags & CAST_FLAG_POWER_LEFT_SELF)
    {
        for (SpellPowerCost const& cost : m_powerCost)
        {
            WorldPackets::Spells::SpellPowerData powerData;
            powerData.Type = cost.Power;
            powerData.Cost = ASSERT_NOTNULL(m_caster->ToUnit())->GetPower(cost.Power);
            castData.RemainingPower.push_back(powerData);
        }
    }
    if (castFlags & CAST_FLAG_AMMO)                         // projectile info
        WriteAmmoToPacket(&data);

    m_caster->SendObjectMessageToSet(&data, true);
}

    if (castFlags & CAST_FLAG_RUNE_LIST) // rune cooldowns list
    {
        castData.RemainingRunes.emplace();
void Spell::SendSpellGo()
{
    // not send invisible spell casting
    if (!IsNeedSendToClient())
        return;

        Player* player = ASSERT_NOTNULL(m_caster->ToPlayer());
        castData.RemainingRunes->Start = m_runesState; // runes state before
        castData.RemainingRunes->Count = player->GetRunesState(); // runes state after
        for (uint8 i = 0; i < player->GetMaxPower(POWER_RUNES); ++i)
        {
            // float casts ensure the division is performed on floats as we need float result
            float baseCd = float(player->GetRuneBaseCooldown());
            castData.RemainingRunes->Cooldowns.push_back((baseCd - float(player->GetRuneCooldown(i))) / baseCd * 255); // rune cooldown passed
        }
    }
    uint32 castFlags = CAST_FLAG_UNKNOWN9;
    if (m_spellInfo->IsRangedSpell())
        castFlags |= CAST_FLAG_AMMO;                        // arrows/bullets visual

    WorldPacket data(SMSG_SPELL_GO, 53);                    // guess size

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    if (m_CastItem)
        data << m_CastItem->GetPackGUID();
    else
        data << m_caster->GetPackGUID();
#else
    if (m_CastItem)
        data << m_CastItem->GetGUID();
    else
        data << m_caster->GetGUID();
#endif

    m_caster->SendCombatLogMessage(&packet);
}

/// Writes miss and hit targets for a SMSG_SPELL_GO packet
void Spell::UpdateSpellCastDataTargets(WorldPackets::Spells::SpellCastData& data)
{
    // This function also fill data for channeled spells:
    // m_needAliveTargetMask req for stop channeling if one target die
    for (TargetInfo& targetInfo : m_UniqueTargetInfo)
    {
        if (targetInfo.EffectMask == 0) // No effect apply - all immune add state
            // possibly SPELL_MISS_IMMUNE2 for this??
            targetInfo.MissCondition = SPELL_MISS_IMMUNE2;
    // (HACK) Don't display cast animation for Flametongue Weapon proc
    // TODO - figure out the rule for why some procs should or should not have cast animations
    // e.g. rogue poison proc should have animation
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    if (m_spellInfo->Id == 10444)
        data << PackedGuid();
     else
        data << m_caster->GetPackGUID();
#else
    if (m_spellInfo->Id == 10444)
        data << uint64();
    else
        data << m_caster->GetGUID();
#endif
    data << uint32(m_spellInfo->Id);                        // spellId
    data << uint16(castFlags);                              // cast flags

        if (targetInfo.MissCondition == SPELL_MISS_NONE || (targetInfo.MissCondition == SPELL_MISS_BLOCK && !m_spellInfo->HasAttribute(SPELL_ATTR3_COMPLETELY_BLOCKED))) // Add only hits and partial blocked
        {
            data.HitTargets.push_back(targetInfo.TargetGUID);
            data.HitStatus.emplace_back(SPELL_MISS_NONE);
    WriteSpellGoTargets(&data);

            m_channelTargetEffectMask |= targetInfo.EffectMask;
        }
        else // misses
        {
            data.MissTargets.push_back(targetInfo.TargetGUID);
            data.MissStatus.emplace_back(targetInfo.MissCondition, targetInfo.ReflectResult);
        }
    }
    data << m_targets;

    for (GOTargetInfo const& targetInfo : m_UniqueGOTargetInfo)
        data.HitTargets.push_back(targetInfo.TargetGUID); // Always hits
    if (castFlags & CAST_FLAG_AMMO)                         // projectile info
        WriteAmmoToPacket(&data);

    for (CorpseTargetInfo const& targetInfo : m_UniqueCorpseTargetInfo)
        data.HitTargets.push_back(targetInfo.TargetGUID); // Always hits

    // Reset m_needAliveTargetMask for non channeled spell
    if (!m_spellInfo->IsChanneled())
        m_channelTargetEffectMask = 0;
    m_caster->SendObjectMessageToSet(&data, true);
}

void Spell::WriteAmmoToPacket(WorldPacket* data)
{
    uint32 ammoInventoryType = 0;
    uint32 ammoDisplayID = 0;

    if (Player const* playerCaster = m_caster->ToPlayer())
    if (m_caster->IsPlayer())
    {
        Item* pItem = playerCaster->GetWeaponForAttack(RANGED_ATTACK);
        Item *pItem = ((Player*)m_caster)->GetWeaponForAttack(RANGED_ATTACK);
        if (pItem)
        {
            ammoInventoryType = pItem->GetProto()->InventoryType;
            if (ammoInventoryType == INVTYPE_THROWN)
                ammoDisplayID = pItem->GetDisplayId(playerCaster);
            else if (playerCaster->HasAura(46699))      // Requires No Ammo
            {
                ammoDisplayID = 5996;                   // normal arrow
                ammoInventoryType = INVTYPE_AMMO;
                ammoDisplayID = pItem->GetProto()->DisplayInfoID;
            else
            {
                uint32 ammoID = ((Player*)m_caster)->GetUInt32Value(PLAYER_AMMO_ID);
                if (ammoID)
                {
                    ItemPrototype const* pProto = ObjectMgr::GetItemPrototype(ammoID);
                    if (pProto)
                    {
                        ammoDisplayID = pProto->DisplayInfoID;
                        ammoInventoryType = pProto->InventoryType;
                    }
                }
            }
        }
    }
    else if (Unit const* unitCaster = m_caster->ToUnit())
    {
        uint32 nonRangedAmmoDisplayID = 0;
        uint32 nonRangedAmmoInventoryType = 0;
        for (uint8 i = BASE_ATTACK; i < MAX_ATTACK; ++i)
        {
            if (uint32 item_id = unitCaster->GetVirtualItemId(i))
            {
                if (ItemEntry const* itemEntry = sItemStore.LookupEntry(item_id))
                {
                    if (itemEntry->ClassID == ITEM_CLASS_WEAPON)
                    {
                        switch (itemEntry->SubclassID)
                        {
                            case ITEM_SUBCLASS_WEAPON_THROWN:
                                ammoDisplayID = sDB2Manager.GetItemDisplayId(item_id, unitCaster->GetVirtualItemAppearanceMod(i));
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
                            default:
                                nonRangedAmmoDisplayID = sDB2Manager.GetItemDisplayId(item_id, unitCaster->GetVirtualItemAppearanceMod(i));
                                nonRangedAmmoInventoryType = itemEntry->InventoryType;
                                break;
                        }
        for (uint8 i = 0; i < MAX_VIRTUAL_ITEM_SLOT; ++i)
        {
            // see Creature::SetVirtualItem for structure data
            if (uint32 item_class = m_caster->GetByteValue(UNIT_VIRTUAL_ITEM_INFO + (i * 2) + 0, VIRTUAL_ITEM_INFO_0_OFFSET_CLASS))
            {
                if (item_class == ITEM_CLASS_WEAPON)
                {
                    switch (m_caster->GetByteValue(UNIT_VIRTUAL_ITEM_INFO + (i * 2) + 0, VIRTUAL_ITEM_INFO_0_OFFSET_SUBCLASS))
                    {
                        case ITEM_SUBCLASS_WEAPON_THROWN:
                            if (m_casterUnit)
                            {
                                ammoDisplayID = m_casterUnit->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_DISPLAY + i);
                                ammoInventoryType = m_casterUnit->GetByteValue(UNIT_VIRTUAL_ITEM_INFO + (i * 2) + 0, VIRTUAL_ITEM_INFO_0_OFFSET_INVENTORYTYPE);
                            }
                            break;
                        case ITEM_SUBCLASS_WEAPON_BOW:
                        case ITEM_SUBCLASS_WEAPON_CROSSBOW:
                            ammoDisplayID = 5996;           // is this need fixing?
                            ammoInventoryType = INVTYPE_AMMO;
                            break;
                        case ITEM_SUBCLASS_WEAPON_GUN:
                            ammoDisplayID = 5998;           // is this need fixing?
                            ammoInventoryType = INVTYPE_AMMO;
                            break;
                    }

                        if (ammoDisplayID)
                            break;
                    }
                }
            }
        }

        if (!ammoDisplayID && !ammoInventoryType)
        {
            ammoDisplayID = nonRangedAmmoDisplayID;
            ammoInventoryType = nonRangedAmmoInventoryType;
        }
    }
                    if (ammoDisplayID)
                        break;
                }
            }
        }
    }

    *data << uint32(ammoDisplayID);
    *data << uint32(ammoInventoryType);
}

void Spell::SendSpellExecuteLog()
{
    if (_executeLogEffects.empty())
        return;

    WorldPackets::CombatLog::SpellExecuteLog spellExecuteLog;
    spellExecuteLog.Caster = m_caster->GetGUID();
    spellExecuteLog.SpellID = m_spellInfo->Id;
    spellExecuteLog.Effects = &_executeLogEffects;
    spellExecuteLog.LogData.Initialize(this);
void Spell::WriteSpellGoTargets(WorldPacket* data)
{
    // This function also fill data for channeled spells:
    // m_needAliveTargetMask req for stop channelig if one target die
    for (auto& ihit : m_UniqueTargetInfo)
    {
        if (ihit.effectMask == 0)                  // No effect apply - all immuned add state
            // possibly SPELL_MISS_IMMUNE2 for this??
            ihit.missCondition = SPELL_MISS_IMMUNE2;
    }

    uint32 hit = 0;
    size_t hitPos = data->wpos();
    *data << (uint8)0; // placeholder

    m_caster->SendCombatLogMessage(&spellExecuteLog);
}

SpellLogEffect& Spell::GetExecuteLogEffect(SpellEffectName effect)
{
    auto itr = std::find_if(_executeLogEffects.begin(), _executeLogEffects.end(), [effect](SpellLogEffect& log)
    {
        return log.Effect == effect;
    });
    if (itr != _executeLogEffects.end())
        return *itr;

    _executeLogEffects.emplace_back();
    _executeLogEffects.back().Effect = effect;
    return _executeLogEffects.back();
}
    for (auto& ihit : m_UniqueTargetInfo)
    {
        if (ihit.missCondition == SPELL_MISS_NONE)
        {
            *data << ihit.targetGUID;                          // in 1.12.1 expected all targets
            m_needAliveTargetMask |= ihit.effectMask;
            ++hit;
        }
    }

    for (const auto& ighit : m_UniqueGOTargetInfo)
    {
        *data << ighit.targetGUID;                         // Always hits
        ++hit;
    }

    uint32 miss = 0;
    size_t missPos = data->wpos();
    *data << (uint8)0; // placeholder
    for (const auto& ihit : m_UniqueTargetInfo)
    {
        if (ihit.missCondition != SPELL_MISS_NONE)        // Add only miss
        {
            *data << (ihit.targetGUID);
            *data << uint8(ihit.missCondition);
            if (ihit.missCondition == SPELL_MISS_REFLECT)
                *data << uint8(ihit.reflectResult);
            ++miss;
        }
    }
    // Reset m_needAliveTargetMask for non channeled spell
    if (!m_channeled)
        m_needAliveTargetMask = 0;

void Spell::ExecuteLogEffectTakeTargetPower(SpellEffectName effect, Unit* target, uint32 powerType, uint32 points, float amplitude)
    data->put<uint8>(hitPos, (uint8)hit);
    data->put<uint8>(missPos, (uint8)miss);
}

void Spell::SendLogExecute()
{
    WorldPacket data(SMSG_SPELLLOGEXECUTE, (8 + 4 + 4 + 4 + 4 + 8));

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    data << m_caster->GetPackGUID();
#else
    data << m_caster->GetGUID();
#endif

    data << uint32(m_spellInfo->Id);

    uint32 effectCount = 0;

    GetExecuteLogEffectTargets(effect, &SpellLogEffect::PowerDrainTargets).push_back(spellLogEffectPowerDrainParams);
}
    for (const auto& i : m_executeLogInfo)
    {
        if (!i.empty())
            effectCount++;
    }

void Spell::ExecuteLogEffectExtraAttacks(SpellEffectName effect, Unit* victim, uint32 numAttacks)
{
    SpellLogEffectExtraAttacksParams spellLogEffectExtraAttacksParams;
    spellLogEffectExtraAttacksParams.Victim = victim->GetGUID();
    spellLogEffectExtraAttacksParams.NumAttacks = numAttacks;
    if (!effectCount)
        return;

    GetExecuteLogEffectTargets(effect, &SpellLogEffect::ExtraAttacksTargets).push_back(spellLogEffectExtraAttacksParams);
}
    data << uint32(effectCount);

void Spell::SendSpellInterruptLog(Unit* victim, uint32 spellId)
{
    WorldPackets::CombatLog::SpellInterruptLog data;
    data.Caster = m_caster->GetGUID();
    data.Victim = victim->GetGUID();
    data.InterruptedSpellID = m_spellInfo->Id;
    data.SpellID = spellId;
    for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
    {
        if (m_executeLogInfo[i].empty())
            continue;

        data << uint32(m_spellInfo->Effect[i]);
        data << uint32(m_executeLogInfo[i].size());

void Spell::ExecuteLogEffectDurabilityDamage(SpellEffectName effect, Unit* victim, int32 itemId, int32 amount)
{
    SpellLogEffectDurabilityDamageParams spellLogEffectDurabilityDamageParams;
    spellLogEffectDurabilityDamageParams.Victim = victim->GetGUID();
    spellLogEffectDurabilityDamageParams.ItemID = itemId;
    spellLogEffectDurabilityDamageParams.Amount = amount;
        for (uint32 j = 0; j < m_executeLogInfo[i].size(); ++j)
        {
            ExecuteLogInfo info = m_executeLogInfo[i][j];
            switch (m_spellInfo->Effect[i])
            {
                case SPELL_EFFECT_POWER_DRAIN:
                    data << info.targetGuid;
                    data << info.powerDrain.amount;
                    data << info.powerDrain.power;
                    data << info.powerDrain.multiplier;
                    break;
                case SPELL_EFFECT_HEAL:
                case SPELL_EFFECT_HEAL_MAX_HEALTH:
                    data << info.targetGuid;
                    data << info.heal.amount;
                    data << info.heal.critical;
                    break;
                case SPELL_EFFECT_ENERGIZE:
                    data << info.targetGuid;
                    data << info.energize.amount;
                    data << info.energize.powerType;
                    break;
                case SPELL_EFFECT_ADD_EXTRA_ATTACKS:
                    data << info.targetGuid;
                    data << info.extraAttacks.count;
                    break;
                case SPELL_EFFECT_CREATE_ITEM:
                    data << info.createItem.itemEntry;
                    break;
                case SPELL_EFFECT_INTERRUPT_CAST:
                    data << info.targetGuid;
                    data << info.interruptCast.spellId;
                    break;
                case SPELL_EFFECT_FEED_PET:
                    data << info.feedPet.itemEntry;
                    break;
                case SPELL_EFFECT_DURABILITY_DAMAGE:
                    data << info.targetGuid;
                    data << info.durabilityDamage.itemEntry;
                    data << info.durabilityDamage.unk;
                    break;
                case SPELL_EFFECT_INSTAKILL:
                case SPELL_EFFECT_RESURRECT:
                case SPELL_EFFECT_DISPEL:
                case SPELL_EFFECT_THREAT:
                case SPELL_EFFECT_DISTRACT:
                case SPELL_EFFECT_SANCTUARY:
                case SPELL_EFFECT_THREAT_ALL:
                case SPELL_EFFECT_DISPEL_MECHANIC:
                case SPELL_EFFECT_RESURRECT_NEW:
                case SPELL_EFFECT_ATTACK_ME:
                case SPELL_EFFECT_SKIN_PLAYER_CORPSE:
                case SPELL_EFFECT_MODIFY_THREAT_PERCENT:
                case SPELL_EFFECT_126:
                case SPELL_EFFECT_OPEN_LOCK:
                case SPELL_EFFECT_OPEN_LOCK_ITEM:
                case SPELL_EFFECT_DISMISS_PET:
                case SPELL_EFFECT_TRANS_DOOR:
                case SPELL_EFFECT_SUMMON:
                case SPELL_EFFECT_SUMMON_PET:
                case SPELL_EFFECT_SUMMON_WILD:
                case SPELL_EFFECT_SUMMON_GUARDIAN:
                case SPELL_EFFECT_SUMMON_TOTEM_SLOT1:
                case SPELL_EFFECT_SUMMON_TOTEM_SLOT2:
                case SPELL_EFFECT_SUMMON_TOTEM_SLOT3:
                case SPELL_EFFECT_SUMMON_TOTEM_SLOT4:
                case SPELL_EFFECT_SUMMON_POSSESSED:
                case SPELL_EFFECT_SUMMON_TOTEM:
                case SPELL_EFFECT_SUMMON_CRITTER:
                case SPELL_EFFECT_SUMMON_OBJECT_WILD:
                case SPELL_EFFECT_SUMMON_OBJECT_SLOT1:
                case SPELL_EFFECT_SUMMON_OBJECT_SLOT2:
                case SPELL_EFFECT_SUMMON_OBJECT_SLOT3:
                case SPELL_EFFECT_SUMMON_OBJECT_SLOT4:
                case SPELL_EFFECT_SUMMON_DEMON:
                    data << info.targetGuid;
                     break;
                 default:
                     return;
            }
        }
    }

    GetExecuteLogEffectTargets(effect, &SpellLogEffect::DurabilityDamageTargets).push_back(spellLogEffectDurabilityDamageParams);
    m_caster->SendMessageToSet(&data, true);
}

void Spell::ExecuteLogEffectOpenLock(SpellEffectName effect, Object* obj)
void Spell::SendInterrupted(uint8 result)
{
    SpellLogEffectGenericVictimParams spellLogEffectGenericVictimParams;
    spellLogEffectGenericVictimParams.Victim = obj->GetGUID();

    GetExecuteLogEffectTargets(effect, &SpellLogEffect::GenericVictimTargets).push_back(spellLogEffectGenericVictimParams);
    // Nostalrius : fix animation de cast a l'interruption d'un sort
    // Ce premier paquet ne sert apparement a rien ...
    // Ce second paquet informe les joueurs aux alentours que le sort a ete interrompu.
    WorldPacket data(SMSG_SPELL_FAILED_OTHER, (8 + 4));
    data << m_caster->GetObjectGuid(); // Pareil que pour SMSG_SPELL_FAILURE
    data << m_spellInfo->Id;
    m_caster->SendObjectMessageToSet(&data, true);
}

void Spell::ExecuteLogEffectCreateItem(SpellEffectName effect, uint32 entry)
void Spell::SendChannelUpdate(uint32 time, bool interrupted)
{
    SpellLogEffectTradeSkillItemParams spellLogEffectTradeSkillItemParams;
    spellLogEffectTradeSkillItemParams.ItemID = entry;

    GetExecuteLogEffectTargets(effect, &SpellLogEffect::TradeSkillTargets).push_back(spellLogEffectTradeSkillItemParams);
}
    if (!m_channeled || m_spellState == SPELL_STATE_FINISHED)
        return;

void Spell::ExecuteLogEffectDestroyItem(SpellEffectName effect, uint32 entry)
{
    SpellLogEffectFeedPetParams spellLogEffectFeedPetParams;
    spellLogEffectFeedPetParams.ItemID = entry;
    if (!time)
    {
        // Reset farsight for some possessing auras of possessed summoned (as they might work with different aura types)
        if (m_spellInfo->Attributes & SPELL_ATTR_EX_FARSIGHT && m_caster->IsPlayer() && m_casterUnit->GetCharmGuid()
                && !m_spellInfo->HasAura(SPELL_AURA_MOD_POSSESS) && !m_spellInfo->HasAura(SPELL_AURA_MOD_POSSESS_PET))
        {
            Player* player = (Player*)m_caster;
            // These Auras are applied to self, so get the possessed first
            Unit* possessed = player->GetCharm();

    GetExecuteLogEffectTargets(effect, &SpellLogEffect::FeedPetTargets).push_back(spellLogEffectFeedPetParams);
}
            player->SetCharm(nullptr);
            if (possessed)
                player->SetClientControl(possessed, 0);
            player->SetMover(nullptr);
            player->GetCamera().ResetView();
            player->RemovePetActionBar();

void Spell::ExecuteLogEffectSummonObject(SpellEffectName effect, WorldObject* obj)
{
    SpellLogEffectGenericVictimParams spellLogEffectGenericVictimParams;
    spellLogEffectGenericVictimParams.Victim = obj->GetGUID();
            if (possessed)
            {
                possessed->ClearUnitState(UNIT_STAT_POSSESSED);
                possessed->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_POSSESSED);
                possessed->SetCharmerGuid(ObjectGuid());
                // TODO - Requires more specials for target?

    GetExecuteLogEffectTargets(effect, &SpellLogEffect::GenericVictimTargets).push_back(spellLogEffectGenericVictimParams);
}
                // Some possessed might want to despawn?
                if (possessed->GetUInt32Value(UNIT_CREATED_BY_SPELL) == m_spellInfo->Id && possessed->IsCreature())
                    ((Creature*)possessed)->ForcedDespawn();
            }
        }

void Spell::ExecuteLogEffectUnsummonObject(SpellEffectName effect, WorldObject* obj)
{
    SpellLogEffectGenericVictimParams spellLogEffectGenericVictimParams;
    spellLogEffectGenericVictimParams.Victim = obj->GetGUID();
        // Free channeled holders now so they can be safely removed, no handling for
        // external removal. Nothing else should be modifying this list during this iteration
        SpellAuraHolderList::iterator iter = m_channeledHolders.begin();
        while (iter != m_channeledHolders.end())
        {
            SpellAuraHolder* holder = *iter;
            holder->SetInUse(false);
            // Remove any left over auras on all targets at channel end if they
            // have not already been marked as deleted. Cleans up non-expired
            // aoe targets
            if (!holder->IsDeleted())
            {
                if (Unit* unit = holder->GetTarget())
                    unit->RemoveSpellAuraHolder(holder, AURA_REMOVE_BY_CHANNEL);
            }

    GetExecuteLogEffectTargets(effect, &SpellLogEffect::GenericVictimTargets).push_back(spellLogEffectGenericVictimParams);
}
            iter = m_channeledHolders.erase(iter);
        }

void Spell::ExecuteLogEffectResurrect(SpellEffectName effect, Unit* target)
{
    SpellLogEffectGenericVictimParams spellLogEffectGenericVictimParams;
    spellLogEffectGenericVictimParams.Victim = target->GetGUID();
        m_channeledUpdateIterator = m_channeledHolders.end();

    GetExecuteLogEffectTargets(effect, &SpellLogEffect::GenericVictimTargets).push_back(spellLogEffectGenericVictimParams);
}
        // Remove single target auras on caster now if they expired
        if (m_casterUnit)
            m_casterUnit->RemoveAurasByCasterSpell(m_spellInfo->Id, m_casterUnit->GetObjectGuid(), AURA_REMOVE_BY_CHANNEL);

        ObjectGuid target_guid = m_casterUnit ? m_casterUnit->GetChannelObjectGuid() : ObjectGuid();
        if (target_guid != m_caster->GetObjectGuid() && target_guid.IsUnit())
        {
            if (Unit* target = ObjectAccessor::GetUnit(*m_caster, target_guid))
            {
                // Remove single target auras on target now if they expired
                target->RemoveAurasByCasterSpell(m_spellInfo->Id, m_caster->GetObjectGuid(), AURA_REMOVE_BY_CHANNEL);
            }
        }

        // Remove dynamic objects if they are still alive. Persistent channel objects
        // live until the cast has finished. Technically don't need to explicitly remove
        // but no harm
        m_caster->RemoveDynObject(m_spellInfo->Id);
        if (m_casterUnit)
            m_casterUnit->RemoveGameObject(m_spellInfo->Id, true);
    }
    // Only modify/send values if we are the current channeled spell !
    if (m_caster->GetCurrentSpell(CURRENT_CHANNELED_SPELL) && m_caster->GetCurrentSpell(CURRENT_CHANNELED_SPELL) != this)
        return;

    if (!m_casterUnit)
        return;

void Spell::SendChannelUpdate(uint32 time)
{
    // GameObjects don't channel
    Unit* unitCaster = m_caster->ToUnit();
    if (!unitCaster)
        return;

    if (time == 0)
    if (!time)
    {
        // Reset of channel values has to be done after a few delay.
        // Else, we have some visual bugs (arcane projectile, last tick)
        ChannelResetEvent* event = new ChannelResetEvent(m_casterUnit);
        m_casterUnit->m_Events.AddEventAtOffset(event, (interrupted ? 1 : 1000));
    }
    else if (Player* pPlayer = m_casterUnit->ToPlayer())
    {
        unitCaster->ClearChannelObjects();
        unitCaster->SetChannelSpellId(0);
        unitCaster->SetChannelVisual({});
        WorldPacket data(MSG_CHANNEL_UPDATE, 4);
        data << uint32(time);
        pPlayer->SendDirectMessage(&data);
    }
}

void Spell::SendChannelStart(uint32 duration)
{
    // GameObjects don't channel
    Unit* unitCaster = m_caster->ToUnit();
    if (!unitCaster)
        return;

    WorldPackets::Spells::SpellChannelStart spellChannelStart;
    spellChannelStart.CasterGUID = unitCaster->GetGUID();
    spellChannelStart.SpellID = m_spellInfo->Id;
    spellChannelStart.Visual = m_SpellVisual;
    spellChannelStart.ChannelDuration = duration;
    unitCaster->SendMessageToSet(spellChannelStart.Write(), true);
    WorldObject* target = nullptr;

    uint32 schoolImmunityMask = unitCaster->GetSchoolImmunityMask();
    uint32 mechanicImmunityMask = unitCaster->GetMechanicImmunityMask();
    // select dynobject created by first effect if any
    if (m_spellInfo->Effect[EFFECT_INDEX_0] == SPELL_EFFECT_PERSISTENT_AREA_AURA)
        target = m_caster->GetDynObject(m_spellInfo->Id, EFFECT_INDEX_0);
    // select first not resisted target from target list for _0_ effect
    else if (!m_UniqueTargetInfo.empty())
    {
        for (const auto& itr : m_UniqueTargetInfo)
        {
            if (itr.deleted)
                continue;

    if (schoolImmunityMask || mechanicImmunityMask)
    {
        spellChannelStart.InterruptImmunities.emplace();
        spellChannelStart.InterruptImmunities->SchoolImmunities = schoolImmunityMask;
        spellChannelStart.InterruptImmunities->Immunities = mechanicImmunityMask;
            if ((itr.effectMask & (1 << EFFECT_INDEX_0)) && itr.reflectResult == SPELL_MISS_NONE &&
                    itr.targetGUID != m_caster->GetObjectGuid())
            {
                target = ObjectAccessor::GetUnit(*m_caster, itr.targetGUID);
                break;
            }
        }
    }
    else if (!m_UniqueGOTargetInfo.empty())
    {
        for (const auto& itr : m_UniqueGOTargetInfo)
        {

        for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
            if (spellEffectInfo.IsEffect(SPELL_EFFECT_APPLY_AURA) && (explicitTargetEffectMask & (1u << spellEffectInfo.EffectIndex)))
                channelAuraMask |= 1 << spellEffectInfo.EffectIndex;

            if (itr.deleted)
                continue;

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
            if (itr.effectMask & (1 << EFFECT_INDEX_0))
            {
                target = m_caster->GetMap()->GetGameObject(itr.targetGUID);
                break;
            }
        }
    }

        for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
            if (spellEffectInfo.IsEffect(SPELL_EFFECT_APPLY_AURA) && (explicitTargetEffectMask & (1u << spellEffectInfo.EffectIndex)))
                channelAuraMask |= 1 << spellEffectInfo.EffectIndex;

        for (TargetInfo const& target : m_UniqueTargetInfo)
        {
            if (!(target.EffectMask & channelAuraMask))
                continue;
    if (m_caster->IsPlayer())
    {
        WorldPacket data(MSG_CHANNEL_START, (4 + 4));
        data << uint32(m_spellInfo->Id);
        data << uint32(duration);
        ((Player*)m_caster)->SendDirectMessage(&data);
    }

            SpellAttr1 requiredAttribute = target.TargetGUID != unitCaster->GetGUID() ? SPELL_ATTR1_IS_CHANNELLED : SPELL_ATTR1_IS_SELF_CHANNELLED;
            if (!m_spellInfo->HasAttribute(requiredAttribute))
                continue;

            unitCaster->AddChannelObject(target.TargetGUID);
        }

        for (GOTargetInfo const& target : m_UniqueGOTargetInfo)
            if (target.EffectMask & channelAuraMask)
                unitCaster->AddChannelObject(target.TargetGUID);
    }
    else if (m_spellInfo->HasAttribute(SPELL_ATTR1_IS_SELF_CHANNELLED))
        unitCaster->AddChannelObject(unitCaster->GetGUID());

    if (Creature* creatureCaster = unitCaster->ToCreature())
        if (unitCaster->m_unitData->ChannelObjects.size() == 1 && unitCaster->m_unitData->ChannelObjects[0].IsUnit())
            if (!creatureCaster->HasSpellFocus(this))
                creatureCaster->SetSpellFocus(this, ObjectAccessor::GetWorldObject(*creatureCaster, unitCaster->m_unitData->ChannelObjects[0]));

    unitCaster->SetChannelSpellId(m_spellInfo->Id);
    unitCaster->SetChannelVisual(m_SpellVisual);
    m_timer = duration;
    if (m_casterUnit)
    {
        if (target)
            m_casterUnit->SetChannelObjectGuid(target->GetObjectGuid());
        m_casterUnit->SetUInt32Value(UNIT_CHANNEL_SPELL, m_spellInfo->Id);
    }
}

void Spell::SendResurrectRequest(Player* target)
{
    // get resurrector name for creature resurrections, otherwise packet will be not accepted
    // for player resurrections the name is looked up by guid
    std::string sentName;
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        sentName = m_caster->GetNameForLocaleIdx(target->GetSession()->GetSessionDbLocaleIndex());
    // Both players and NPCs can resurrect using spells - have a look at creature 28487 for example
    // However, the packet structure differs slightly

    char const* sentName = m_caster->IsPlayer() ? "" : m_caster->GetNameForLocaleIdx(target->GetSession()->GetSessionDbLocaleIndex());

    WorldPacket data(SMSG_RESURRECT_REQUEST, (8 + 4 + strlen(sentName) + 1 + 1 + 1));
    data << m_caster->GetObjectGuid();
    data << uint32(strlen(sentName) + 1);

    WorldPackets::Spells::ResurrectRequest resurrectRequest;
    resurrectRequest.ResurrectOffererGUID =  m_caster->GetGUID();
    resurrectRequest.ResurrectOffererVirtualRealmAddress = GetVirtualRealmAddress();
    resurrectRequest.Name = sentName;
    resurrectRequest.Sickness = m_caster->IsUnit() && m_caster->ToUnit()->IsSpiritHealer(); // "you'll be afflicted with resurrection sickness"
    resurrectRequest.UseTimer = !m_spellInfo->HasAttribute(SPELL_ATTR3_NO_RES_TIMER);
    if (Pet* pet = target->GetPet())
        if (CharmInfo* charmInfo = pet->GetCharmInfo())
            resurrectRequest.PetNumber = charmInfo->GetPetNumber();
    data << sentName;
    data << uint8(0);

    data << uint8(m_caster->IsPlayer() ? 0 : 1);
    target->GetSession()->SendPacket(&data);
}

void Spell::TakeCastItem()
{
    if (!m_CastItem || !m_caster->IsPlayer())
        return;

    // not remove cast item at triggered spell (equipping, weapon damage, etc)
    if (m_IsTriggeredSpell && !(m_targets.m_targetMask & TARGET_FLAG_TRADE_ITEM))
        return;

    ItemPrototype const* proto = m_CastItem->GetProto();

    if (!proto)
    {
        // This code is to avoid a crash
        // I'm not sure, if this is really an error, but I guess every item needs a prototype
        TC_LOG_ERROR("spells", "Cast item has no item prototype {}", m_CastItem->GetGUID().ToString());
        sLog.outError("Cast item (%s) has no item prototype", m_CastItem->GetGuidStr().c_str());
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
                    if (proto->Stackable < 2)
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
        Item* castItem = m_CastItem;
        // prevent crash at access to deleted m_targets.getItemTarget
        ClearCastItem();
        // Destroying the item involved in a spell interrupts the spell. So delete the item once we cleared the spell cast item.
        ((Player*)m_caster)->DestroyItemCount(castItem, count, true);
    }
}

void Spell::TakePower()
{
    // GameObjects don't use power
    Unit* unitCaster = m_caster->ToUnit();
    if (!unitCaster)
        return;

    if (m_CastItem || m_triggeredByAuraSpell)
    if (m_CastItem || m_triggeredByAuraSpell || IsChannelingVisual() || !m_casterUnit)
        return;

    //Don't take power if the spell is cast while .cheat power is enabled.
    if (unitCaster->GetTypeId() == TYPEID_PLAYER)
    {
        if (unitCaster->ToPlayer()->GetCommandStatus(CHEAT_POWER))
    if (Player* pPlayer = m_casterUnit->ToPlayer())
        if (pPlayer->HasCheatOption(PLAYER_CHEAT_NO_POWER))
            return;

        // health as power used
        if (powerType == POWER_HEALTH)
        {
            unitCaster->ModifyHealth(-cost.Amount);
            continue;
        }

        if (powerType >= MAX_POWERS)
        {
            TC_LOG_ERROR("spells", "Spell::TakePower: Unknown power type '{}'", powerType);
            continue;
        }

        unitCaster->ModifyPower(powerType, -cost.Amount);
    }
}

SpellCastResult Spell::CheckRuneCost() const
{
    int32 runeCost = std::accumulate(m_powerCost.begin(), m_powerCost.end(), 0, [](int32 totalCost, SpellPowerCost const& cost)
    // health as power used
    if (m_spellInfo->powerType == POWER_HEALTH)
    {
        return totalCost + (cost.Power == POWER_RUNES ? cost.Amount : 0);
    });

    if (!runeCost)
        return SPELL_CAST_OK;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return SPELL_CAST_OK;

    if (player->GetClass() != CLASS_DEATH_KNIGHT)
        return SPELL_CAST_OK;

    int32 readyRunes = 0;
    for (int32 i = 0; i < player->GetMaxPower(POWER_RUNES); ++i)
        if (player->GetRuneCooldown(i) == 0)
            ++readyRunes;

    if (readyRunes < runeCost)
        return SPELL_FAILED_NO_POWER;                       // not sure if result code is correct

    return SPELL_CAST_OK;
}
        unitCaster->ModifyPower(powerType, -cost.Amount);
    }
}

SpellCastResult Spell::CheckRuneCost() const
{
    int32 runeCost = std::accumulate(m_powerCost.begin(), m_powerCost.end(), 0, [](int32 totalCost, SpellPowerCost const& cost)
    {
        return totalCost + (cost.Power == POWER_RUNES ? cost.Amount : 0);
    });

    if (!runeCost)
        return SPELL_CAST_OK;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return SPELL_CAST_OK;

    if (player->GetClass() != CLASS_DEATH_KNIGHT)
        return SPELL_CAST_OK;

    int32 readyRunes = 0;
    for (int32 i = 0; i < player->GetMaxPower(POWER_RUNES); ++i)
        if (player->GetRuneCooldown(i) == 0)
            ++readyRunes;

    if (readyRunes < runeCost)
        return SPELL_FAILED_NO_POWER;                       // not sure if result code is correct

    return SPELL_CAST_OK;
}

void Spell::TakeRunePower(bool didHit)
        m_casterUnit->ModifyHealth(-(int32)m_powerCost);
        return;
    }

void Spell::TakeRunePower(bool didHit)
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER || m_caster->ToPlayer()->GetClass() != CLASS_DEATH_KNIGHT)
    if (m_spellInfo->powerType >= MAX_POWERS)
    {
        sLog.outError("Spell::TakePower: Unknown power type '%d'", m_spellInfo->powerType);
        return;
    }

    Powers powerType = Powers(m_spellInfo->powerType);

    m_casterUnit->ModifyPower(powerType, -(int32)m_powerCost);

    // Set the five second timer
    if (powerType == POWER_MANA && m_powerCost > 0)
        m_casterUnit->SetLastManaUse(m_spellInfo->Id);
}

void Spell::TakeReagents()
{
    if (!m_caster->IsPlayer())
        return;

    // do not take reagents for these item casts
    if (m_CastItem && m_CastItem->GetTemplate()->HasFlag(ITEM_FLAG_NO_REAGENT_COST))
    if (IgnoreItemRequirements())                           // reagents used in triggered spell removed by original spell or don't must be removed.
        return;

    Player* p_caster = (Player*)m_caster;

    for (uint32 x = 0; x < MAX_SPELL_REAGENTS; ++x)
    {
        if (m_spellInfo->Reagent[x] <= 0)
            continue;

        uint32 itemid = m_spellInfo->Reagent[x];
        uint32 itemcount = m_spellInfo->ReagentCount[x];

        // if CastItem is also spell reagent
        if (m_CastItem)
        {
            ItemPrototype const* proto = m_CastItem->GetProto();
            if (proto && proto->ItemId == itemid)
            {
                for (int s = 0; s < MAX_ITEM_PROTO_SPELLS; ++s)
                {
                    // CastItem will be used up and does not count as reagent
                    int32 charges = m_CastItem->GetSpellCharges(s);
                    if (proto->Spells[s].SpellCharges < 0 && abs(charges) < 2 && itemcount > 1)
                    {
                        ++itemcount;
                        break;
                    }
                }

                m_CastItem = nullptr;
            }
        }

        // if getItemTarget is also spell reagent
        if (m_targets.getItemTargetEntry() == itemid)
            m_targets.setItemTarget(nullptr);

        p_caster->DestroyItemCount(itemid, itemcount, true);
    }

    for (SpellReagentsCurrencyEntry const* reagentsCurrency : m_spellInfo->ReagentsCurrency)
        p_caster->RemoveCurrency(reagentsCurrency->CurrencyTypesID, reagentsCurrency->CurrencyCount, CurrencyDestroyReason::Spell);
}

void Spell::TakeAmmo()
{
    // wild GameObject spells don't cause threat
    Unit* unitCaster = (m_originalCaster ? m_originalCaster : m_caster->ToUnit());
    if (!unitCaster)
        return;

    if (m_UniqueTargetInfo.empty())
    Player* pCaster = m_caster->ToPlayer();
    if (!pCaster)
        return;

    // Some ranged attacks dont take any ammo
    switch (m_spellInfo->Id)
    {
        case 2094:  // Blind
        case 13099: // Net-o-Matic
        case 13119: // Net-o-Matic
        case 23577: // Expose Weakness
            return;
    }
            
    if (m_attackType == RANGED_ATTACK)
    {
        if (threatEntry->apPctMod != 0.0f)
            threat += threatEntry->apPctMod * unitCaster->GetTotalAttackPowerValue(BASE_ATTACK);
        Item *pItem = pCaster->GetWeaponForAttack(RANGED_ATTACK, true, false);

        // wands don't have ammo
        if (!pItem || pItem->GetProto()->SubClass == ITEM_SUBCLASS_WEAPON_WAND)
            return;

        if (pItem->GetProto()->InventoryType == INVTYPE_THROWN)
        {
            if (pItem->GetMaxStackCount() == 1)
            {
                // decrease durability for non-stackable throw weapon
                pCaster->DurabilityPointLossForEquipSlot(EQUIPMENT_SLOT_RANGED);
            }
            else
            {
                // decrease items amount for stackable throw weapon
                uint32 count = 1;
                pCaster->DestroyItemCount(pItem, count, true);
            }
        }
        else if (uint32 ammo = pCaster->GetUInt32Value(PLAYER_AMMO_ID))
            pCaster->DestroyItemCount(ammo, 1, true);
    }
}

void Spell::HandleThreatSpells()
{
    if (!m_casterUnit)
        return;

    if (m_UniqueTargetInfo.empty())
        return;

    for (auto ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
    SpellThreatEntry const* threatEntry = sSpellMgr.GetSpellThreatEntry(m_spellInfo->Id);

    if (!threatEntry || (!threatEntry->threat && threatEntry->ap_bonus == 0.0f))
        return;

    float threat = threatEntry->threat;
    if (threatEntry->ap_bonus != 0.0f)
        threat += threatEntry->ap_bonus * m_casterUnit->GetTotalAttackPowerValue(m_spellInfo->GetWeaponAttackType());

    bool positive = true;
    uint8 effectMask = 0;
    for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
        if (m_spellInfo->Effect[i])
            effectMask |= (1 << i);

    if (m_negativeEffectMask & effectMask)
    {
        float threatToAdd = threat;
        if (ihit->MissCondition != SPELL_MISS_NONE)
            threatToAdd = 0.0f;
        // can only handle spells with clearly defined positive/negative effect, check at spell_threat loading probably not perfect
        // so abort when only some effects are negative.
        if ((m_negativeEffectMask & effectMask) != effectMask)
        {
            DEBUG_FILTER_LOG(LOG_FILTER_SPELL_CAST, "Spell %u, rank %u, is not clearly positive or negative, ignoring bonus threat", m_spellInfo->Id, sSpellMgr.GetSpellRank(m_spellInfo->Id));
            return;
        }
        positive = false;
    }

        Unit* target = ObjectAccessor::GetUnit(*unitCaster, ihit->TargetGUID);
    for (const auto& ihit : m_UniqueTargetInfo)
    {
        if (ihit.missCondition != SPELL_MISS_NONE)
            continue;

        Unit* target = m_casterUnit->GetObjectGuid() == ihit.targetGUID ? m_casterUnit : ObjectAccessor::GetUnit(*m_casterUnit, ihit.targetGUID);
        if (!target)
            continue;

        // positive spells distribute threat among all units that are in combat with target, like healing
        if (IsPositive())
            target->GetThreatManager().ForwardThreatForAssistingMe(unitCaster, threatToAdd, m_spellInfo);
        if (positive)
            target->GetHostileRefManager().threatAssist(m_casterUnit /*pRealCaster ??*/, threat, m_spellInfo);
        // for negative spells threat gets distributed among affected targets
        else
        {
            if (!target->CanHaveThreatList())
                continue;

            target->GetThreatManager().AddThreat(unitCaster, threatToAdd, m_spellInfo, true);
            target->AddThreat(m_casterUnit, threat, false, m_spellInfo->GetSpellSchoolMask(), m_spellInfo);
        }
    }
    TC_LOG_DEBUG("spells", "Spell {}, added an additional {} threat for {} {} target(s)", m_spellInfo->Id, threat, IsPositive() ? "assisting" : "harming", uint32(m_UniqueTargetInfo.size()));

    DEBUG_FILTER_LOG(LOG_FILTER_SPELL_CAST, "Spell %u added an additional %f threat for %s %u target(s)", m_spellInfo->Id, threat, positive ? "assisting" : "harming", uint32(m_UniqueTargetInfo.size()));
}

void Spell::HandleEffects(Unit* pUnitTarget, Item* pItemTarget, GameObject* pGoTarget, Corpse* pCorpseTarget, SpellEffectInfo const& spellEffectInfo, SpellEffectHandleMode mode)
void Spell::HandleEffects(Unit* pUnitTarget, Item *pItemTarget, GameObject* pGOTarget, SpellEffectIndex i, float DamageMultiplier)
{
    // a summoning ritual visual has no effect
    if (IsChannelingVisual())
        return;

    unitTarget = pUnitTarget;
    itemTarget = pItemTarget;
    gameObjTarget = pGoTarget;
    m_corpseTarget = pCorpseTarget;
    destTarget = &m_destTargets[spellEffectInfo.EffectIndex]._position;
    effectInfo = &spellEffectInfo;
    gameObjTarget = pGOTarget;

    damage = CalculateDamage(spellEffectInfo, unitTarget, &variance);
    uint8 eff = m_spellInfo->Effect[i];

    damage = CalculateDamage(i, unitTarget) * DamageMultiplier;

    DEBUG_FILTER_LOG(LOG_FILTER_SPELL_CAST, "Spell %u Effect%d : %u Targets: %s, %s, %s",
                     m_spellInfo->Id, i, eff,
                     unitTarget ? unitTarget->GetGuidStr().c_str() : "-",
                     itemTarget ? itemTarget->GetGuidStr().c_str() : "-",
                     gameObjTarget ? gameObjTarget->GetGuidStr().c_str() : "-");

    if (eff < TOTAL_SPELL_EFFECTS)
        (*this.*SpellEffects[eff])(i);
    else
        sLog.outError("WORLD: Spell %u has effect %d at index %u > TOTAL_SPELL_EFFECTS",
            m_spellInfo->Id, eff, i);
}

void Spell::AddTriggeredSpell(uint32 spellId)
{
    SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(spellId);

    if (!spellInfo)
    {
        sLog.outError("Spell::AddTriggeredSpell: unknown spell id %u used as triggred spell for spell %u)", spellId, m_spellInfo->Id);
        return;
    }

    bool preventDefault = CallScriptEffectHandlers(spellEffectInfo.EffectIndex, mode);
    m_TriggerSpells.push_back(spellInfo);
}

    if (!preventDefault)
        (this->*SpellEffectHandlers[spellEffectInfo.Effect].Value)();
}
void Spell::AddPrecastSpell(uint32 spellId)
{
    SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(spellId);

    if (!spellInfo)
    {
        sLog.outError("Spell::AddPrecastSpell: unknown spell id %u used as pre-cast spell for spell %u)", spellId, m_spellInfo->Id);
        return;
    }

    m_preCastSpells.push_back(spellInfo);
}

void Spell::CastTriggerSpells()
{
    for (const auto spellInfo : m_TriggerSpells)
    {
        Spell* spell = m_casterUnit ? new Spell(m_casterUnit, spellInfo, true, m_originalCasterGUID) : new Spell(m_casterGo, spellInfo, true, m_originalCasterGUID);
        spell->prepare(m_targets);                         // use original spell original targets
    }
}

void Spell::CastPreCastSpells(Unit* target)
{
    for (const auto spellInfo : m_preCastSpells)
        m_caster->CastSpell(target, spellInfo, true, m_CastItem);
}

void Spell::AddChanneledAuraHolder(SpellAuraHolder* holder)
{
    if (!holder || !holder->IsChanneled())
        return;

    // Set and hold in use until clean up to prevent any delete calls destroying
    // the object before we can handle it
    holder->SetInUse(true);
    m_channeledHolders.push_back(holder);
}

SpellCastResult Spell::CheckCast(bool strict, int32* param1 /*= nullptr*/, int32* param2 /*= nullptr*/)
// Occurs when an aura should be removed from handling due to deletion or expiration
void Spell::RemoveChanneledAuraHolder(SpellAuraHolder* holder, AuraRemoveMode mode)
{
    // check death state
    if (m_caster->ToUnit() && !m_caster->ToUnit()->IsAlive() && !m_spellInfo->IsPassive() && !(m_spellInfo->HasAttribute(SPELL_ATTR0_ALLOW_CAST_WHILE_DEAD) || (IsTriggered() && !m_triggeredByAuraSpell)))
        return SPELL_FAILED_CASTER_DEAD;
    // AURA_REMOVE_BY_CHANNEL comes from here, don't want to double erase
    // AURA_REMOVE_BY_RANGE and AURA_REMOVE_BY_GROUP are handled in Spell::update
    if (!holder || mode == AURA_REMOVE_BY_CHANNEL || mode == AURA_REMOVE_BY_GROUP || mode == AURA_REMOVE_BY_RANGE)
        return;

    // Prevent cheating in case the player has an immunity effect and tries to interact with a non-allowed gameobject. The error message is handled by the client so we don't report anything here
    if (m_caster->ToPlayer() && m_targets.GetGOTarget())
    {
        if (m_targets.GetGOTarget()->GetGOInfo()->GetNoDamageImmune() && m_caster->ToUnit()->HasUnitFlag(UNIT_FLAG_IMMUNE))
            return SPELL_FAILED_DONT_REPORT;
    }

    // check cooldowns to prevent cheating
    if (!m_spellInfo->IsPassive())
    SpellAuraHolderList::iterator iter = std::find(m_channeledHolders.begin(), m_channeledHolders.end(), holder);
    if (iter != m_channeledHolders.end())
    {
        if (Player const* playerCaster = m_caster->ToPlayer())
        {
            //can cast triggered (by aura only?) spells while have this flag
            if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CASTER_AURASTATE))
            {
                // These two auras check SpellFamilyName defined by db2 class data instead of current spell SpellFamilyName
                if (playerCaster->HasAuraType(SPELL_AURA_DISABLE_CASTING_EXCEPT_ABILITIES)
                    && !m_spellInfo->HasAttribute(SPELL_ATTR0_USES_RANGED_SLOT)
                    && !m_spellInfo->HasEffect(SPELL_EFFECT_ATTACK)
                    && !m_spellInfo->HasAttribute(SPELL_ATTR12_IGNORE_CASTING_DISABLED)
                    && !playerCaster->HasAuraTypeWithFamilyFlags(SPELL_AURA_DISABLE_CASTING_EXCEPT_ABILITIES, sChrClassesStore.AssertEntry(playerCaster->GetClass())->SpellClassSet, m_spellInfo->SpellFamilyFlags))
                        return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;
        (*iter)->SetInUse(false);

                if (playerCaster->HasAuraType(SPELL_AURA_DISABLE_ATTACKING_EXCEPT_ABILITIES))
                {
                    if (!playerCaster->HasAuraTypeWithFamilyFlags(SPELL_AURA_DISABLE_ATTACKING_EXCEPT_ABILITIES, sChrClassesStore.AssertEntry(playerCaster->GetClass())->SpellClassSet, m_spellInfo->SpellFamilyFlags))
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
        // If removing the aura currently being updated, increment the
        // update iter. If this is the last element, the update iterator
        // will be set to end() and Spell::Update will finish. If not,
        // it will seemlessly handle the case of multiple auras being
        // removed in a single update.
        // Micro opt - update iter in removal rather than increment
        if (iter == m_channeledUpdateIterator)
            m_channeledUpdateIterator = m_channeledHolders.erase(iter);
        else
            m_channeledHolders.erase(iter);
    }
}

            // check if we are using a potion in combat for the 2nd+ time. Cooldown is added only after caster gets out of combat
            if (!IsIgnoringCooldowns() && playerCaster->GetLastPotionId() && m_CastItem && (m_CastItem->IsPotion() || m_spellInfo->IsCooldownStartedOnEvent()))
                return SPELL_FAILED_NOT_READY;
        }
SpellCastResult Spell::CheckCast(bool strict)
{
    if (m_caster->IsPlayer() && m_caster->ToPlayer()->HasCheatOption(PLAYER_CHEAT_NO_CHECK_CAST))
        return SPELL_CAST_OK;

    // Prevent casting while sitting unless the spell allows it
    if (!m_IsTriggeredSpell && m_casterUnit && !m_casterUnit->IsStandingUp() && !(m_spellInfo->Attributes & SPELL_ATTR_CASTABLE_WHILE_SITTING))
        return SPELL_FAILED_NOT_STANDING;

    // check cooldowns to prevent cheating (ignore passive spells, that client side visual only)
    if (!m_IsTriggeredSpell && m_caster->IsPlayer() && !m_spellInfo->HasAttribute(SPELL_ATTR_PASSIVE)
        && !m_spellInfo->IsAutoRepeatRangedSpell() // auto shot managed by attack timer
        && !m_caster->IsSpellReady(*m_spellInfo, m_CastItem ? m_CastItem->GetProto() : nullptr))
    {
        return (m_triggeredByAuraSpell || m_spellInfo->Attributes & SPELL_ATTR_DISABLED_WHILE_ACTIVE) ? SPELL_FAILED_DONT_REPORT : SPELL_FAILED_NOT_READY;
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

            if ((IsAutoRepeat() || m_spellInfo->CategoryId == 76) && !m_caster->ToUnit()->isAttackReady(RANGED_ATTACK))
                return SPELL_FAILED_DONT_REPORT;
        }
    }
    // check death state to prevent cheating ("deathbug")
    if (m_casterUnit && !m_casterUnit->IsAlive() && !(m_spellInfo->Attributes & SPELL_ATTR_PASSIVE) && !((m_spellInfo->Attributes & SPELL_ATTR_CASTABLE_WHILE_DEAD) || (m_IsTriggeredSpell && !m_triggeredByAuraSpell)))
    {
        if (m_triggeredByAuraSpell)
            return SPELL_FAILED_DONT_REPORT;
        else
            return SPELL_FAILED_CASTER_DEAD;
    }

    if (m_spellInfo->HasAttribute(SPELL_ATTR7_IS_CHEAT_SPELL) && m_caster->IsUnit() && !m_caster->ToUnit()->HasUnitFlag2(UNIT_FLAG2_ALLOW_CHEAT_SPELLS))
    // check global cooldown
    if (!m_IsTriggeredSpell)
    {
        m_customError = SPELL_CUSTOM_ERROR_GM_ONLY;
        return SPELL_FAILED_CUSTOM_ERROR;
    }

    // Check global cooldown
    if (strict && !(_triggeredCastFlags & TRIGGERED_IGNORE_GCD) && HasGlobalCooldown())
        return !m_spellInfo->HasAttribute(SPELL_ATTR0_COOLDOWN_ON_EVENT) ? SPELL_FAILED_NOT_READY : SPELL_FAILED_DONT_REPORT;
        // Activated spells will get stuck if we return SPELL_FAILED_NOT_READY during GCD
        if (strict && m_caster->HasGCD(m_spellInfo))
            return m_spellInfo->HasAttribute(SPELL_ATTR_DISABLED_WHILE_ACTIVE) ? SPELL_FAILED_DONT_REPORT : SPELL_FAILED_NOT_READY;

        // only allow triggered spells if at an ended battleground
        if (m_caster->IsPlayer())
            if (BattleGround* bg = ((Player*)m_caster)->GetBattleGround())
                if (bg->GetStatus() == STATUS_WAIT_LEAVE)
                    return SPELL_FAILED_DONT_REPORT;

    if (m_caster->GetTypeId() == TYPEID_PLAYER && VMAP::VMapFactory::createOrGetVMapManager()->isLineOfSightCalcEnabled())
    {
        if (m_spellInfo->HasAttribute(SPELL_ATTR0_ONLY_OUTDOORS) &&
            !m_caster->IsOutdoors())
            return SPELL_FAILED_ONLY_OUTDOORS;

        if (m_spellInfo->HasAttribute(SPELL_ATTR0_ONLY_INDOORS) &&
            m_caster->IsOutdoors())
            return SPELL_FAILED_ONLY_INDOORS;
    }
        if (strict && m_casterUnit)
        {
            if (m_casterUnit && m_casterUnit->IsInCombat() && m_spellInfo->IsNonCombatSpell())
                return SPELL_FAILED_AFFECTING_COMBAT;

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
            // only check at first call, Stealth auras are already removed at second call
            // for now, ignore triggered spells
            //if (strict)
            //{
            // Cannot be used in this stance/form
            SpellCastResult shapeError = m_spellInfo->GetErrorAtShapeshiftedCast(m_casterUnit->GetShapeshiftForm());
            if (shapeError != SPELL_CAST_OK)
                return shapeError;

                if (m_spellInfo->HasAttribute(SPELL_ATTR0_ONLY_STEALTHED) && !(unitCaster->HasStealthAura()))
                    return SPELL_FAILED_ONLY_STEALTHED;
            }
        }
            if ((m_spellInfo->Attributes & SPELL_ATTR_ONLY_STEALTHED) && !(m_casterUnit->HasStealthAura()))
                return SPELL_FAILED_ONLY_STEALTHED;
        }
    }

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
    if (m_caster->IsPlayer() && !((Player*)m_caster)->IsGameMaster() &&
            sWorld.getConfig(CONFIG_BOOL_VMAP_INDOOR_CHECK) &&
            VMAP::VMapFactory::createOrGetVMapManager()->isLineOfSightCalcEnabled())
    {
        if (m_spellInfo->Attributes & SPELL_ATTR_OUTDOORS_ONLY &&
                !m_caster->GetTerrain()->IsOutdoors(m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ()))
            return SPELL_FAILED_ONLY_OUTDOORS;

        if (m_spellInfo->Attributes & SPELL_ATTR_INDOORS_ONLY &&
                m_caster->GetTerrain()->IsOutdoors(m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ()))
            return SPELL_FAILED_ONLY_INDOORS;
    }

        // caster state requirements
        // not for triggered spells (needed by execute)
        if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CASTER_AURASTATE))
        {
            if (m_spellInfo->CasterAuraState && !unitCaster->HasAuraState(AuraStateType(m_spellInfo->CasterAuraState), m_spellInfo, unitCaster))
                return SPELL_FAILED_CASTER_AURASTATE;
            if (m_spellInfo->ExcludeCasterAuraState && unitCaster->HasAuraState(AuraStateType(m_spellInfo->ExcludeCasterAuraState), m_spellInfo, unitCaster))
                return SPELL_FAILED_CASTER_AURASTATE;

            // Note: spell 62473 requres casterAuraSpell = triggering spell
            if (m_spellInfo->CasterAuraSpell && !unitCaster->HasAura(m_spellInfo->CasterAuraSpell))
                return SPELL_FAILED_CASTER_AURASTATE;
            if (m_spellInfo->ExcludeCasterAuraSpell && unitCaster->HasAura(m_spellInfo->ExcludeCasterAuraSpell))
                return SPELL_FAILED_CASTER_AURASTATE;
    // caster state requirements
    if (m_spellInfo->CasterAuraState && m_casterUnit && !m_casterUnit->HasAuraState(AuraState(m_spellInfo->CasterAuraState)))
        return SPELL_FAILED_CASTER_AURASTATE;

            if (m_spellInfo->CasterAuraType && !unitCaster->HasAuraType(m_spellInfo->CasterAuraType))
                return SPELL_FAILED_CASTER_AURASTATE;
            if (m_spellInfo->ExcludeCasterAuraType && unitCaster->HasAuraType(m_spellInfo->ExcludeCasterAuraType))
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
    if (m_caster->IsPlayer())
    {
        // Autorepeat spells, if cast start when moving, are delayed until moving stop in spell update code.
        if (m_caster->IsMoving())
        {
            // skip stuck spell to allow use it in falling case and apply spell limitations at movement
            if ((!m_caster->m_movementInfo.HasMovementFlag(MOVEFLAG_FALLINGFAR) || m_spellInfo->Effect[EFFECT_INDEX_0] != SPELL_EFFECT_STUCK) &&
                    (IsAutoRepeat() || m_spellInfo->AuraInterruptFlags & AURA_INTERRUPT_FLAG_NOT_SEATED))
                return SPELL_FAILED_MOVING;
        }

        if (!m_IsTriggeredSpell && m_spellInfo->NeedsComboPoints() && Spells::IsExplicitlySelectedUnitTarget(m_spellInfo->EffectImplicitTargetA[0]) &&
           (!m_targets.getUnitTarget() || m_targets.getUnitTarget()->GetObjectGuid() != ((Player*)m_caster)->GetComboTargetGuid()))
            // warrior not have real combo-points at client side but use this way for mark allow Overpower use
            return m_casterUnit->GetClass() == CLASS_WARRIOR ? SPELL_FAILED_BAD_TARGETS : SPELL_FAILED_NO_COMBO_POINTS;

        switch (m_spellInfo->Id)
        {
            // Mongoose Bite
            case 1495:
            case 14269:
            case 14270:
            case 14271:
                if (m_targets.getUnitTargetGuid() != m_casterUnit->GetReactiveTarget(REACTIVE_DEFENSE))
                    return SPELL_FAILED_BAD_TARGETS;
                break;
            // Counterattack
            case 19306:
            case 20909:
            case 20910:
                if (m_targets.getUnitTargetGuid() != m_casterUnit->GetReactiveTarget(REACTIVE_HUNTER_PARRY))
                    return SPELL_FAILED_BAD_TARGETS;
                break;
            // Reindeer Transformation only castable while mounted
            case 25860:
                if (!m_casterUnit->HasAuraType(SPELL_AURA_MOUNTED))
                    return SPELL_FAILED_ONLY_MOUNTED;
                break;
            case 25720: // Place Loot / Quest 8606 Decoy!
            {
                if (Player* pPlayer = ToPlayer(GetAffectiveCaster()))
                    if (!pPlayer->HasAura(25688)) // Narain's Turban
                        return SPELL_FAILED_TARGET_AURASTATE;
                break;
            }
        }

        // Loatheb Corrupted Mind spell failed
        if (!m_IsCastByItem && !m_IsTriggeredSpell)
        {
            Unit::AuraList const& auraClassScripts = m_casterUnit->GetAurasByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
            for (const auto auraClassScript : auraClassScripts)
            {
                if (auraClassScript->GetModifier()->m_miscvalue == 4327)
                {
                    if ((m_spellInfo->SpellFamilyName == SPELLFAMILY_DRUID ||
                         m_spellInfo->SpellFamilyName == SPELLFAMILY_PRIEST ||
                         m_spellInfo->SpellFamilyName == SPELLFAMILY_SHAMAN ||
                         m_spellInfo->SpellFamilyName == SPELLFAMILY_PALADIN) &&
                        (m_spellInfo->IsHealSpell() ||
                         m_spellInfo->IsDispel() || // don't really care if the target is non-friendly, there's nothing to purge on Loatheb
                         m_spellInfo->IsFitToFamily<SPELLFAMILY_PRIEST, CF_PRIEST_HOLY_NOVA1>() || // prevent holy nova cast (casted spell is damage part, heal is triggered)
                         m_spellInfo->IsFitToFamily<SPELLFAMILY_PRIEST, CF_PRIEST_POWER_WORD_SHIELD>())) // prevent PW:Shield cast
                    {
                        return SPELL_FAILED_FIZZLE;
                    }
                }
            }
        }
    }

    if (Unit* target = m_targets.getUnitTarget())
    {
        // Check explicit target for m_originalCaster - todo: get rid of such workarounds
        WorldObject* caster = m_caster;
        // in case of gameobjects like traps, we need the gameobject itself to check target validity
        // otherwise, if originalCaster is far away and cannot detect the target, the trap would not hit the target
        if (m_originalCaster && !caster->ToGameObject())
            caster = m_originalCaster;
        // A more powerful spell is already active
        if (m_spellInfo->IsSpellAppliesAura() && !m_spellInfo->IsAreaOfEffectSpell() && m_spellInfo->IsPositiveSpell() && target->HasMorePowerfulSpellActive(m_spellInfo))
            return SPELL_FAILED_AURA_BOUNCED;

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_10_2
        // Swiftmend
        if (m_spellInfo->Id == 18562)                       // future versions have special aura state for this
        {
            if (!target->GetAura(SPELL_AURA_PERIODIC_HEAL, SPELLFAMILY_DRUID, UI64LIT(0x50)))
                return SPELL_FAILED_TARGET_AURASTATE;
        }
#endif
        if (!m_IsTriggeredSpell && m_spellInfo->IsDeathOnlySpell() && target->IsAlive())
            return SPELL_FAILED_TARGET_NOT_DEAD;

    if (Unit* target = m_targets.GetUnitTarget())
    {
        SpellCastResult castResult = m_spellInfo->CheckTarget(m_caster, target, m_caster->GetTypeId() == TYPEID_GAMEOBJECT); // skip stealth checks for GO casts
        if (castResult != SPELL_CAST_OK)
            return castResult;
        // Check spell min target level
        if ((m_spellInfo->MinTargetLevel > 0) && (int32(target->GetLevel()) < m_spellInfo->MinTargetLevel))
            return SPELL_FAILED_LOWLEVEL;

        // Check spell max target level
        if ((m_spellInfo->MaxTargetLevel > 0) && (int32(target->GetLevel()) > m_spellInfo->MaxTargetLevel))
            return SPELL_FAILED_HIGHLEVEL;

#if SUPPORTED_CLIENT_BUILD <= CLIENT_BUILD_1_11_2
        // World of Warcraft Client Patch 1.12.0 (2006-08-22)
        // - Pickpocket can now be used on targets that are in combat, as long as the rogue remains stealthed.
        if ((m_spellInfo->AttributesEx & SPELL_ATTR_EX_IS_PICKPOCKET) && target->IsInCombat())
            return SPELL_FAILED_TARGET_IN_COMBAT;
#endif

        bool non_caster_target = target != m_caster && !m_spellInfo->IsSpellWithCasterSourceTargetsOnly();

        if (non_caster_target)
        {
            // Not allow casting on flying player unless its a ritual of summoning
            if (target->IsTaxiFlying() && m_spellInfo->Id != 7720)
                return SPELL_FAILED_BAD_TARGETS;

            if (!m_IsTriggeredSpell)
            {
                if (!(m_spellInfo->AttributesEx2 & SPELL_ATTR_EX2_IGNORE_LOS) && !m_caster->IsWithinLOSInMap(target))
                    return SPELL_FAILED_LINE_OF_SIGHT;

                // check if target is in combat
                if (strict && non_caster_target && (m_spellInfo->AttributesEx & SPELL_ATTR_EX_NOT_IN_COMBAT_TARGET) && target->IsInCombat())
                    return SPELL_FAILED_TARGET_AFFECTING_COMBAT;

        // If it's not a melee spell, check if vision is obscured by SPELL_AURA_INTERFERE_TARGETTING
        if (m_spellInfo->DmgClass != SPELL_DAMAGE_CLASS_MELEE)
        {
            if (Unit const* unitCaster = m_caster->ToUnit())
            {
                for (AuraEffect const* auraEff : unitCaster->GetAuraEffectsByType(SPELL_AURA_INTERFERE_TARGETTING))
                    if (!unitCaster->IsFriendlyTo(auraEff->GetCaster()) && !target->HasAura(auraEff->GetId(), auraEff->GetCasterGUID()))
                        return SPELL_FAILED_VISION_OBSCURED;
                // auto selection spell rank implemented in WorldSession::HandleCastSpellOpcode
                // this case can be triggered if rank not found (too low-level target for first rank)
                if (m_caster->IsPlayer() && !m_CastItem)
                {
                    // spell expected to be auto-downranking in cast handle, so must be same
                    if (m_spellInfo != sSpellMgr.SelectAuraRankForLevel(m_spellInfo, target->GetLevel()))
                        return SPELL_FAILED_LOWLEVEL;
                }

                for (AuraEffect const* auraEff : target->GetAuraEffectsByType(SPELL_AURA_INTERFERE_TARGETTING))
                    if (!unitCaster->IsFriendlyTo(auraEff->GetCaster()) && (!target->HasAura(auraEff->GetId(), auraEff->GetCasterGUID()) || !unitCaster->HasAura(auraEff->GetId(), auraEff->GetCasterGUID())))
                        return SPELL_FAILED_VISION_OBSCURED;
            }
        }
                if (m_spellInfo->HasAttribute(SPELL_ATTR_EX2_CANT_TARGET_TAPPED))
                {
                    // Mob tapped by another player or group.
                    if (Player* pCaster = m_caster->ToPlayer())
                        if (Creature* pCreature = target->ToCreature())
                            if (pCreature->GetLootGroupRecipientId() || pCreature->GetLootRecipientGuid())
                                if (!pCreature->IsTappedBy(pCaster))
                                    return SPELL_FAILED_CANT_CAST_ON_TAPPED;
                }

                if (strict && m_spellInfo->AttributesEx3 & SPELL_ATTR_EX3_TARGET_ONLY_PLAYER && target->GetTypeId() != TYPEID_PLAYER && !m_spellInfo->IsAreaOfEffectSpell())
                    return SPELL_FAILED_BAD_TARGETS;
            }
            // Can't help a friend in duel   |  sorry, not enough time to figure out why this is necessary
            if (m_spellInfo->IsPositiveSpell() && m_spellInfo->Id != 28697)
            {
                Player* casterOwner = m_casterUnit ? m_casterUnit->GetCharmerOrOwnerPlayerOrPlayerItself() : nullptr;
                Player* targetOwner = target->GetCharmerOrOwnerPlayerOrPlayerItself();

            // Target must be facing you
            if ((m_spellInfo->HasAttribute(SPELL_ATTR0_CU_REQ_TARGET_FACING_CASTER)) && !target->HasInArc(static_cast<float>(M_PI), m_caster))
                return SPELL_FAILED_NOT_INFRONT;

            // Ignore LOS for gameobjects casts
            if (m_caster->GetTypeId() != TYPEID_GAMEOBJECT)
            {
                WorldObject* losTarget = m_caster;
                if (IsTriggered() && m_triggeredByAuraSpell)
                    if (DynamicObject* dynObj = m_caster->ToUnit()->GetDynObject(m_triggeredByAuraSpell->Id))
                        losTarget = dynObj;
                if (m_spellInfo->Id == 7266 && targetOwner && targetOwner->duel && casterOwner && !casterOwner->IsInDuelWith(targetOwner))
                {
                    return SPELL_FAILED_TARGET_DUELING;
                }

                if (!m_spellInfo->HasAttribute(SPELL_ATTR2_IGNORE_LINE_OF_SIGHT) && !DisableMgr::IsDisabledFor(DISABLE_TYPE_SPELL, m_spellInfo->Id, nullptr, SPELL_DISABLE_LOS) && !target->IsWithinLOSInMap(losTarget, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
                    return SPELL_FAILED_LINE_OF_SIGHT;
                if (targetOwner && casterOwner != targetOwner && targetOwner->duel && targetOwner->duel->startTime && casterOwner && !casterOwner->IsInDuelWith(targetOwner))
                    return SPELL_FAILED_TARGET_DUELING;
            }
        }
        else if (m_caster == target)
        {
            if (m_caster->IsPlayer() && m_caster->IsInWorld())
            {
                // Additional check for some spells
                // If 0 spell effect empty - client not send target data (need use selection)
                // TODO: check it on next client version
                if (m_targets.m_targetMask == TARGET_FLAG_SELF &&
                        m_spellInfo->EffectImplicitTargetA[EFFECT_INDEX_1] == TARGET_UNIT_ENEMY)
                {
                    target = m_caster->GetMap()->GetUnit(((Player*)m_caster)->GetSelectionGuid());
                    if (!target)
                        return SPELL_FAILED_BAD_TARGETS;

        if (!m_spellInfo->HasAttribute(SPELL_ATTR2_IGNORE_LINE_OF_SIGHT) && !DisableMgr::IsDisabledFor(DISABLE_TYPE_SPELL, m_spellInfo->Id, nullptr, SPELL_DISABLE_LOS) && !m_caster->IsWithinLOS(x, y, z, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
            return SPELL_FAILED_LINE_OF_SIGHT;
    }
                    m_targets.setUnitTarget(target);
                }
            }
            // Some special spells with non-caster only mode
            // Fire Shield
            if (m_spellInfo->SpellFamilyName == SPELLFAMILY_WARLOCK &&
                    m_spellInfo->SpellIconID == 16)
                return SPELL_FAILED_BAD_TARGETS;
            // Arcane Missiles
            if (m_caster == target &&
                    m_spellInfo->SpellFamilyName == SPELLFAMILY_MAGE &&
                    m_spellInfo->SpellFamilyFlags == 0x40800)
                return SPELL_FAILED_BAD_TARGETS;
        }

    // check pet presence
    if (Unit* unitCaster = m_caster->ToUnit())
    {
        if (m_spellInfo->HasAttribute(SPELL_ATTR2_NO_ACTIVE_PETS))
            if (!unitCaster->GetPetGUID().IsEmpty())
                return SPELL_FAILED_ALREADY_HAVE_PET;

        for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
        {
            if (spellEffectInfo.TargetA.GetTarget() == TARGET_UNIT_PET)
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
        // check pet presents
        for (uint32 j : m_spellInfo->EffectImplicitTargetA)
        {
            if (j == TARGET_UNIT_CASTER_PET)
            {
                Pet* pet = m_casterUnit ? m_casterUnit->GetPet() : nullptr;
                if (!pet)
                {
                    if (m_triggeredByAuraSpell)              // not report pet not existence for triggered spells
                        return SPELL_FAILED_DONT_REPORT;
                    else
                        return SPELL_FAILED_NO_PET;
                }
                else if (!pet->IsAlive())
                {
                    if (m_triggeredByAuraSpell)
                        return SPELL_FAILED_DONT_REPORT;
                    else
                        return SPELL_FAILED_TARGETS_DEAD;
                }
                else if (!(m_spellInfo->AttributesEx2 & SPELL_ATTR_EX2_IGNORE_LOS) && !pet->IsWithinLOSInMap(m_caster))
                    return SPELL_FAILED_LINE_OF_SIGHT;
                break;
            }
        }

        // check creature type
        // ignore self casts (including area casts when caster selected as target)
        if (non_caster_target)
        {
            if (!CheckTargetCreatureType(target))
            {
                if (target->IsPlayer())
                    return SPELL_FAILED_TARGET_IS_PLAYER;
                else
                    return SPELL_FAILED_BAD_TARGETS;
            }

            // simple cases
            bool explicit_target_mode = false;
            bool target_hostile = false;
            bool target_hostile_checked = false;
            bool target_friendly_checked = false;
            for (uint32 k : m_spellInfo->EffectImplicitTargetA)
            {
                if (IsExplicitPositiveTarget(k))
                {
                    if (!target_hostile_checked)
                    {
                        target_hostile_checked = true;
                        target_hostile = m_caster->IsHostileTo(target);
                    }

                    if (target_hostile)
                        return SPELL_FAILED_BAD_TARGETS;

                    explicit_target_mode = true;
                }
                else if (IsExplicitNegativeTarget(k))
                {
                    if (!target_friendly_checked)
                    {
                        target_friendly_checked = true;
                        if (!m_caster->IsValidAttackTarget(target, false))
                            return SPELL_FAILED_BAD_TARGETS;
                    }
                    explicit_target_mode = true;
                }
            }
            // TODO: this check can be applied and for player to prevent cheating when IsPositiveSpell will return always correct result.
            // check target for pet/charmed casts (not self targeted), self targeted cast used for area effects and etc
            // Nostalrius : pas de status positif / negatif pour les sorts de dispel (marche en offensif comme defensif)
            if (!explicit_target_mode && m_caster->IsCreature() && m_casterUnit->GetCharmerOrOwnerGuid() && !m_spellInfo->HasEffect(SPELL_EFFECT_DISPEL))
            {
                // check correctness positive/negative cast target (pet cast real check and cheating check)
                if (m_spellInfo->IsPositiveSpell())
                {
                    if (!target_hostile_checked)
                        target_hostile = m_caster->IsHostileTo(target);

                    if (target_hostile)
                        return SPELL_FAILED_BAD_TARGETS;
                }
                else
                {
                    if (!target_friendly_checked && m_caster->IsFriendlyTo(target))
                        return SPELL_FAILED_BAD_TARGETS;
                }
            }
        }

    // Spell cast only in battleground
    if (m_spellInfo->HasAttribute(SPELL_ATTR3_ONLY_BATTLEGROUNDS))
        if (!m_caster->GetMap()->IsBattleground())
            return SPELL_FAILED_ONLY_BATTLEGROUNDS;
        if (m_spellInfo->IsPositiveSpell(m_caster, target))
            if (target->IsImmuneToSpell(m_spellInfo, target == m_caster))
                return SPELL_FAILED_TARGET_AURASTATE;

        //Must be behind the target.
        if (m_spellInfo->IsFromBehindOnlySpell() && m_casterUnit && !m_casterUnit->IsBehindTarget(target, strict))
        {
            SendInterrupted(2);
            return SPELL_FAILED_NOT_BEHIND;
        }

        //Target must be facing you.
        if ((m_spellInfo->Attributes == 0x150010) && !target->HasInArc(m_caster))
        {
            SendInterrupted(2);
            return SPELL_FAILED_NOT_INFRONT;
        }
    }
    else if (GameObject* goTarget = m_targets.getGOTarget())
    {
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_7_1
        // Prevent cheating in case the player has an immunity effect and tries to interact with a non-allowed gameobject.
        if (goTarget->GetGOInfo()->CannotBeUsedUnderImmunity() && m_casterUnit && m_casterUnit->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE))
            return SPELL_FAILED_DAMAGE_IMMUNE;
#endif

    // zone check
    if (m_caster->GetTypeId() != TYPEID_PLAYER || !m_caster->ToPlayer()->IsGameMaster())
    {
        uint32 zone, area;
        m_caster->GetZoneAndAreaId(zone, area);
        // Require LOS to loot chests
        // For example, check LoS when opening a gobj (spell 6477).
        // Prevents abuse with object id 165554 for example.
        if (goTarget->GetGoType() == GAMEOBJECT_TYPE_CHEST)
        {
            if (!m_IsTriggeredSpell && !(m_spellInfo->AttributesEx2 & SPELL_ATTR_EX2_IGNORE_LOS)
              && !goTarget->GetGOInfo()->chest.minSuccessOpens                // don't check for gathering nodes, too many are halfway in walls
              && !goTarget->HasFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND)  // don't check for quest items
              && !(goTarget->GetEntry() == 160845)                            // exemption for Dark Coffer
              && !m_caster->IsWithinLOSInMap(goTarget, false))
                return SPELL_FAILED_LINE_OF_SIGHT;
        }
    }
    else if (m_targets.IsEmpty())
    {
        // check LOS for ground targeted AOE spells like Blizzard, Flamestrike ...
        if (m_caster->IsPlayer() && m_targets.m_targetMask & TARGET_FLAG_DEST_LOCATION)
        {
            if (m_targets.m_destX && m_targets.m_destY && m_targets.m_destZ)
            {
                if (!m_caster->IsWithinLOS(m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ))
                    return SPELL_FAILED_LINE_OF_SIGHT;
            }
        }
    }

    if (m_casterUnit)
    {
        // zone check
        SpellCastResult locRes = sSpellMgr.GetSpellAllowedInLocationError(m_spellInfo, m_casterUnit, m_casterUnit->GetCharmerOrOwnerPlayerOrPlayerItself());
        if (locRes != SPELL_CAST_OK)
            return locRes;

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
        // not let players cast spells at mount (and let do it to creatures)
        if (m_casterUnit->IsMounted() && m_casterUnit->IsPlayer() && !m_IsTriggeredSpell &&
            !m_spellInfo->IsPassiveSpell() && !(m_spellInfo->Attributes & SPELL_ATTR_CASTABLE_WHILE_MOUNTED))
        {
            if (m_casterUnit->IsTaxiFlying())
                return SPELL_FAILED_NOT_ON_TAXI;
            else if (m_casterUnit->IsPlayer())
            {
                m_casterUnit->Unmount();
                m_casterUnit->RemoveSpellsCausingAura(SPELL_AURA_MOUNTED);
            }
            else
                return SPELL_FAILED_NOT_MOUNTED;
        }
    }

    // always (except passive spells) check items (focus object can be required for any type casts)
    if (!m_spellInfo->IsPassiveSpell())
    {
        SpellCastResult castResult = CheckItems();
        if (castResult != SPELL_CAST_OK)
            return castResult;
    }

    // Database based targets from spell_target_script
    if (m_UniqueTargetInfo.empty())                         // skip second CheckCast apply (for delayed spells for example)
    {
        for (uint8 j = 0; j < MAX_EFFECT_INDEX; ++j)
        {
            if (m_spellInfo->EffectImplicitTargetA[j] == TARGET_UNIT_SCRIPT_NEAR_CASTER ||
                    (m_spellInfo->EffectImplicitTargetB[j] == TARGET_UNIT_SCRIPT_NEAR_CASTER && m_spellInfo->EffectImplicitTargetA[j] != TARGET_UNIT_CASTER) ||
                    m_spellInfo->EffectImplicitTargetA[j] == TARGET_LOCATION_SCRIPT_NEAR_CASTER ||
                    m_spellInfo->EffectImplicitTargetB[j] == TARGET_LOCATION_SCRIPT_NEAR_CASTER ||
                    m_spellInfo->EffectImplicitTargetA[j] == TARGET_GAMEOBJECT_SCRIPT_NEAR_CASTER)
            {

                SpellScriptTargetBounds bounds = sSpellMgr.GetSpellScriptTargetBounds(m_spellInfo->Id);

                if (bounds.first == bounds.second)
                {
                    if (m_spellInfo->EffectImplicitTargetA[j] == TARGET_UNIT_SCRIPT_NEAR_CASTER || m_spellInfo->EffectImplicitTargetB[j] == TARGET_UNIT_SCRIPT_NEAR_CASTER)
                        sLog.outErrorDb("Spell entry %u, effect %i has EffectImplicitTargetA/EffectImplicitTargetB = TARGET_UNIT_SCRIPT_NEAR_CASTER, but creature are not defined in `spell_script_target`", m_spellInfo->Id, j);

                    if (m_spellInfo->EffectImplicitTargetA[j] == TARGET_LOCATION_SCRIPT_NEAR_CASTER || m_spellInfo->EffectImplicitTargetB[j] == TARGET_LOCATION_SCRIPT_NEAR_CASTER)
                        sLog.outErrorDb("Spell entry %u, effect %i has EffectImplicitTargetA/EffectImplicitTargetB = TARGET_LOCATION_SCRIPT_NEAR_CASTER, but gameobject or creature are not defined in `spell_script_target`", m_spellInfo->Id, j);

                    if (m_spellInfo->EffectImplicitTargetA[j] == TARGET_GAMEOBJECT_SCRIPT_NEAR_CASTER)
                        sLog.outErrorDb("Spell entry %u, effect %i has EffectImplicitTargetA/EffectImplicitTargetB = TARGET_GAMEOBJECT_SCRIPT_NEAR_CASTER, but gameobject are not defined in `spell_script_target`", m_spellInfo->Id, j);
                }

                SpellRangeEntry const* srange = sSpellRangeStore.LookupEntry(m_spellInfo->rangeIndex);
                float range = GetSpellMaxRange(srange);

                Creature* targetExplicit = nullptr;            // used for cases where a target is provided (by script for example)
                Creature* creatureScriptTarget = nullptr;
                GameObject* goScriptTarget = nullptr;

                for (auto i_spellST = bounds.first; i_spellST != bounds.second; ++i_spellST)
                {
                    if (i_spellST->second.CanNotHitWithSpellEffect(SpellEffectIndex(j)))
                        continue;

                    switch (i_spellST->second.type)
                    {
                        case SPELL_TARGET_TYPE_GAMEOBJECT:
                        {
                            GameObject* p_GameObject = nullptr;

                            if (i_spellST->second.targetEntry)
                            {
                                MaNGOS::NearestGameObjectEntryFitConditionInObjectRangeCheck go_check(*m_caster, i_spellST->second.targetEntry, range, i_spellST->second.conditionId);
                                MaNGOS::GameObjectLastSearcher<MaNGOS::NearestGameObjectEntryFitConditionInObjectRangeCheck> checker(p_GameObject, go_check);
                                Cell::VisitGridObjects(m_caster, checker, range);

                                if (p_GameObject)
                                {
                                    // remember found target and range, next attempt will find more near target with another entry
                                    creatureScriptTarget = nullptr;
                                    goScriptTarget = p_GameObject;
                                    range = go_check.GetLastRange();
                                }
                            }
                            else if (focusObject)           // Focus Object
                            {
                                float frange = m_caster->GetDistance(focusObject);
                                if (range >= frange)
                                {
                                    creatureScriptTarget = nullptr;
                                    goScriptTarget = focusObject;
                                    range = frange;
                                }
                            }
                            break;
                        }
                        case SPELL_TARGET_TYPE_CREATURE:
                        case SPELL_TARGET_TYPE_DEAD:
                        default:
                        {
                            Creature* p_Creature = nullptr;

    // check spell focus object
    if (m_spellInfo->RequiresSpellFocus)
    {
        if (!m_caster->IsUnit() || !m_caster->ToUnit()->HasAuraTypeWithMiscvalue(SPELL_AURA_PROVIDE_SPELL_FOCUS, m_spellInfo->RequiresSpellFocus))
        {
            focusObject = SearchSpellFocus();
            if (!focusObject)
                return SPELL_FAILED_REQUIRES_SPELL_FOCUS;
        }
    }
                            // check if explicit target is provided and check it up against database valid target entry/state
                            if (Unit* pTarget = m_targets.getUnitTarget())
                            {
                                if (pTarget->IsCreature() && pTarget->GetEntry() == i_spellST->second.targetEntry)
                                {
                                    if (i_spellST->second.type == SPELL_TARGET_TYPE_DEAD && ((Creature*)pTarget)->IsCorpse())
                                    {
                                        // always use spellMaxRange, in case GetLastRange returned different in a previous pass
                                        if (pTarget->IsWithinDistInMap(m_caster, GetSpellMaxRange(srange)))
                                            targetExplicit = (Creature*)pTarget;
                                    }
                                    else if (i_spellST->second.type == SPELL_TARGET_TYPE_CREATURE && pTarget->IsAlive())
                                    {
                                        // always use spellMaxRange, in case GetLastRange returned different in a previous pass
                                        if (pTarget->IsWithinDistInMap(m_caster, GetSpellMaxRange(srange)))
                                            targetExplicit = (Creature*)pTarget;
                                    }
                                }
                            }

                            // no target provided or it was not valid, so use closest in range
                            if (!targetExplicit)
                            {
                                MaNGOS::NearestCreatureEntryFitConditionInObjectRangeCheck u_check(*m_caster, i_spellST->second.targetEntry, i_spellST->second.type != SPELL_TARGET_TYPE_DEAD, range, i_spellST->second.conditionId);
                                MaNGOS::CreatureLastSearcher<MaNGOS::NearestCreatureEntryFitConditionInObjectRangeCheck> searcher(p_Creature, u_check);

                                // Visit all, need to find also Pet* objects
                                Cell::VisitAllObjects(m_caster, searcher, range);

                                range = u_check.GetLastRange();
                            }

                            // always prefer provided target if it's valid
                            if (targetExplicit)
                                creatureScriptTarget = targetExplicit;
                            else if (p_Creature)
                                creatureScriptTarget = p_Creature;

                            if (creatureScriptTarget)
                                goScriptTarget = nullptr;

                            break;
                        }
                    }
                }

                if (creatureScriptTarget)
                {
                    // store coordinates for TARGET_LOCATION_SCRIPT_NEAR_CASTER
                    if (m_spellInfo->EffectImplicitTargetA[j] == TARGET_LOCATION_SCRIPT_NEAR_CASTER ||
                            m_spellInfo->EffectImplicitTargetB[j] == TARGET_LOCATION_SCRIPT_NEAR_CASTER)
                    {
                        m_targets.setDestination(creatureScriptTarget->GetPositionX(), creatureScriptTarget->GetPositionY(), creatureScriptTarget->GetPositionZ());

                        if (m_spellInfo->EffectImplicitTargetA[j] == TARGET_LOCATION_SCRIPT_NEAR_CASTER && m_spellInfo->Effect[j] != SPELL_EFFECT_PERSISTENT_AREA_AURA)
                            AddUnitTarget(creatureScriptTarget, SpellEffectIndex(j));
                    }
                    // store explicit target for TARGET_UNIT_SCRIPT_NEAR_CASTER
                    else
                    {
                        if (m_spellInfo->EffectImplicitTargetA[j] == TARGET_UNIT_SCRIPT_NEAR_CASTER ||
                                m_spellInfo->EffectImplicitTargetB[j] == TARGET_UNIT_SCRIPT_NEAR_CASTER)
                        {
                            // not sure if every TARGET_UNIT_SCRIPT_NEAR_CASTER requires the same, but this one definetely is checked wrong
                            if (m_spellInfo->Id == 16053 && creatureScriptTarget->GetHealthPercent() < 11)
                                m_targets.setUnitTarget(creatureScriptTarget);

                            AddUnitTarget(creatureScriptTarget, SpellEffectIndex(j));                            
                        }
                    }
                }
                else if (goScriptTarget)
                {
                    // store coordinates for TARGET_LOCATION_SCRIPT_NEAR_CASTER
                    if (m_spellInfo->EffectImplicitTargetA[j] == TARGET_LOCATION_SCRIPT_NEAR_CASTER ||
                            m_spellInfo->EffectImplicitTargetB[j] == TARGET_LOCATION_SCRIPT_NEAR_CASTER)
                    {
                        m_targets.setDestination(goScriptTarget->GetPositionX(), goScriptTarget->GetPositionY(), goScriptTarget->GetPositionZ());

                        if (m_spellInfo->EffectImplicitTargetA[j] == TARGET_LOCATION_SCRIPT_NEAR_CASTER && m_spellInfo->Effect[j] != SPELL_EFFECT_PERSISTENT_AREA_AURA)
                            AddGOTarget(goScriptTarget, SpellEffectIndex(j));
                    }
                    // store explicit target for TARGET_GAMEOBJECT_SCRIPT_NEAR_CASTER
                    else
                    {
                        if (m_spellInfo->EffectImplicitTargetA[j] == TARGET_GAMEOBJECT_SCRIPT_NEAR_CASTER ||
                                m_spellInfo->EffectImplicitTargetB[j] == TARGET_GAMEOBJECT_SCRIPT_NEAR_CASTER)
                            AddGOTarget(goScriptTarget, SpellEffectIndex(j));
                    }
                }
                //Missing DB Entry or targets for this spellEffect.
                else
                {
                    /* For TARGET_GAMEOBJECT_SCRIPT_NEAR_CASTER makes DB targets optional not required for now
                     * TODO: Makes more research for this target type
                     */
                    if (m_spellInfo->EffectImplicitTargetA[j] != TARGET_GAMEOBJECT_SCRIPT_NEAR_CASTER)
                    {
                        // not report target not existence for triggered spells
                        if (m_triggeredByAuraSpell || m_IsTriggeredSpell)
                            return SPELL_FAILED_DONT_REPORT;
                        else
                            return SPELL_FAILED_BAD_TARGETS;
                    }
                }
            }
        }
    }

    if (!m_IsTriggeredSpell)
    {
        if (!m_triggeredByAuraSpell)
        {
            SpellCastResult castResult = CheckRange(strict);
            if (castResult != SPELL_CAST_OK)
                return castResult;
            if (Player* playerCaster = m_caster->ToPlayer())
                if (BattleGround* bg = playerCaster->GetBattleGround())
                {
                    castResult = bg->CheckSpellCast(playerCaster, m_spellInfo);
                    if (castResult != SPELL_CAST_OK)
                        return castResult;
                }
        }

        if (m_casterUnit)
        {
            SpellCastResult castResult = CheckPower();
            if (castResult != SPELL_CAST_OK)
                return castResult;

            // triggered spell not affected by stun/etc
            castResult = CheckCasterAuras();
            if (castResult != SPELL_CAST_OK)
                return castResult;

    uint32 approximateAuraEffectMask = 0;
    uint32 nonAuraEffectMask = 0;
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
    {
            if (m_casterUnit->HasUnitState(UNIT_STAT_POSSESSED))
            {
                if (m_spellInfo->Category == 21) // Enrage
                    return SPELL_FAILED_NOT_READY;
            }
        }
    }

    // All spells that require target to be below 20% have this.
    if (m_spellInfo->TargetAuraState == AURA_STATE_HEALTHLESS_20_PERCENT)
    {
        if (!m_targets.getUnitTarget())
            return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

        if (!m_targets.getUnitTarget()->HasAuraState(AURA_STATE_HEALTHLESS_20_PERCENT))
            return SPELL_FAILED_BAD_TARGETS;
    }   

    for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
    {
        // for effects of spells that have only one target
        switch (spellEffectInfo.Effect)
        switch (m_spellInfo->Effect[i])
        {
            case SPELL_EFFECT_DUMMY:
            {
                if (m_spellInfo->SpellIconID == 156) // Holy Shock
                {
                    // spell different for friends and enemies
                    // hart version required facing
                    if (m_targets.getUnitTarget() &&
                       !m_caster->IsFriendlyTo(m_targets.getUnitTarget()) &&
                       (m_caster->GetDistance2dToCenter(m_targets.getUnitTarget()) > NO_FACING_CHECKS_DISTANCE) &&
                       !m_caster->HasInArc(m_targets.getUnitTarget()))
                        return SPELL_FAILED_UNIT_NOT_INFRONT;
                }
                else if (m_spellInfo->Id == 13278) // Gnomish Death Ray
                {
                    if (!m_targets.getUnitTarget() || m_caster->IsFriendlyTo(m_targets.getUnitTarget()))
                        return SPELL_FAILED_BAD_TARGETS;
                }
                else if (m_spellInfo->Id == 18153) // Kodo Kombobulator
                {
                    if (m_casterUnit && m_casterUnit->HasAura(18172))
                        return SPELL_FAILED_ITEM_NOT_READY;
                }
                else if (m_spellInfo->IsFitToFamilyMask<CF_WARLOCK_LIFE_TAP>() && m_casterUnit)
                {
                    float cost = m_currentBasePoints[EFFECT_INDEX_0];

                    if (Player* modOwner = m_casterUnit->GetSpellModOwner())
                        modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_COST, cost, this);

                    float dmg = m_casterUnit->SpellDamageBonusDone(m_casterUnit, m_spellInfo, SpellEffectIndex(i), uint32(cost > 0 ? cost : 0), SPELL_DIRECT_DAMAGE);
                    dmg = m_casterUnit->SpellDamageBonusTaken(m_casterUnit, m_spellInfo, SpellEffectIndex(i), dmg, SPELL_DIRECT_DAMAGE);

                    // use cail as dithering might round up later.
                    if (int32(m_casterUnit->GetHealth()) <= std::ceil(dmg))
                        return SPELL_FAILED_FIZZLE;
                }
                break;
            }
            case SPELL_EFFECT_SCHOOL_DAMAGE:
            {
                if (spellEffectInfo.TargetA.GetTarget() != TARGET_UNIT_PET)
                    break;
                // Conflagrate
                if (m_spellInfo->IsFitToFamily<SPELLFAMILY_WARLOCK, CF_WARLOCK_CONFLAGRATE>())
                {
                    if (!m_targets.getUnitTarget())
                        return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

                    // for caster applied auras only
                    bool found = false;
                    auto const& mPeriodic = m_targets.getUnitTarget()->GetAurasByType(SPELL_AURA_PERIODIC_DAMAGE);
                    for (const auto i : mPeriodic)
                    {
                        // Immolate
                        if (i->GetSpellProto()->IsFitToFamily<SPELLFAMILY_WARLOCK, CF_WARLOCK_IMMOLATE>() &&
                            i->GetCasterGuid() == m_caster->GetObjectGuid())
                        {
                            found = true;
                            break;
                        }
                    }

                Pet* pet = m_caster->ToPlayer()->GetPet();
                if (!pet)
                    return SPELL_FAILED_NO_PET;
                    if (!found)
                        return SPELL_FAILED_TARGET_AURASTATE;
                }
                break;
            }
            case SPELL_EFFECT_TAMECREATURE:
            {
                // Spell can be triggered, we need to check original caster prior to caster
                Unit* caster = GetAffectiveCaster();
                if (!caster || caster->GetTypeId() != TYPEID_PLAYER ||
                        !m_targets.getUnitTarget() ||
                        m_targets.getUnitTarget()->IsPlayer())
                    return SPELL_FAILED_BAD_TARGETS;

                Player* plrCaster = (Player*)caster;

                SpellInfo const* learn_spellproto = sSpellMgr->GetSpellInfo(spellEffectInfo.TriggerSpell, DIFFICULTY_NONE);
                if (!learn_spellproto)
                    return SPELL_FAILED_NOT_KNOWN;
                bool gmmode = m_triggeredBySpellInfo == nullptr;

                if (plrCaster->GetClass() != CLASS_HUNTER && !gmmode)
                {
                    plrCaster->SendPetTameFailure(PETTAME_UNITSCANTTAME);
                    return SPELL_FAILED_DONT_REPORT;
                }

                if (m_spellInfo->SpellLevel > pet->GetLevel())
                    return SPELL_FAILED_LOWLEVEL;
                Creature* target = (Creature*)m_targets.getUnitTarget();

                if (target->IsPet() || target->IsCharmed())
                {
                    plrCaster->SendPetTameFailure(PETTAME_CREATUREALREADYOWNED);
                    return SPELL_FAILED_DONT_REPORT;
                }

                if (target->GetLevel() > plrCaster->GetLevel() && !gmmode)
                {
                    plrCaster->SendPetTameFailure(PETTAME_TOOHIGHLEVEL);
                    return SPELL_FAILED_DONT_REPORT;
                }

                if (!target->GetCreatureInfo()->isTameable())
                {
                    plrCaster->SendPetTameFailure(PETTAME_NOTTAMEABLE);
                    return SPELL_FAILED_DONT_REPORT;
                }

                if (plrCaster->GetPetGuid() || plrCaster->GetCharmGuid() ||
                   (!plrCaster->IsBot() &&
                    sCharacterDatabaseCache.GetCharacterPetByOwner(plrCaster->GetGUIDLow())))
                {
                    plrCaster->SendPetTameFailure(PETTAME_ANOTHERSUMMONACTIVE);
                    return SPELL_FAILED_DONT_REPORT;
                }

                break;
            }
            case SPELL_EFFECT_LEARN_SPELL:
            {
                if (m_spellInfo->EffectImplicitTargetA[i] != TARGET_UNIT_CASTER_PET)
                    break;

                    SpellInfo const* learn_spellproto = sSpellMgr->GetSpellInfo(spellEffectInfo.TriggerSpell, DIFFICULTY_NONE);
                Pet* pet = m_casterUnit ? m_casterUnit->GetPet() : nullptr;

                if (!pet)
                    return SPELL_FAILED_NO_PET;

                SpellEntry const* learn_spellproto = sSpellMgr.GetSpellEntry(m_spellInfo->EffectTriggerSpell[i]);

                if (!learn_spellproto)
                    return SPELL_FAILED_NOT_KNOWN;

                    if (m_spellInfo->SpellLevel > pet->GetLevel())
                        return SPELL_FAILED_LOWLEVEL;
                }
                if (!pet->CanTakeMoreActiveSpells(learn_spellproto->Id))
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_6_1
                    return SPELL_FAILED_TOO_MANY_SKILLS;
#else
                    return SPELL_FAILED_FIZZLE;
#endif

                if (m_spellInfo->spellLevel > pet->GetLevel())
                    return SPELL_FAILED_LOWLEVEL;

                if (!pet->HasTPForSpell(learn_spellproto->Id))
                    return SPELL_FAILED_TRAINING_POINTS;

                break;
            }
            case SPELL_EFFECT_LEARN_PET_SPELL:
            {
                Pet* pet = m_casterUnit ? m_casterUnit->GetPet() : nullptr;

                if (!pet)
                    return SPELL_FAILED_NO_PET;

                if (uint32 glyphId = spellEffectInfo.MiscValue)
                {
                    GlyphPropertiesEntry const* glyphProperties = sGlyphPropertiesStore.LookupEntry(glyphId);
                    if (!glyphProperties)
                        return SPELL_FAILED_INVALID_GLYPH;
                SpellEntry const* learn_spellproto = sSpellMgr.GetSpellEntry(m_spellInfo->EffectTriggerSpell[i]);

                if (!learn_spellproto)
                    return SPELL_FAILED_NOT_KNOWN;

                if (!pet->CanTakeMoreActiveSpells(learn_spellproto->Id))
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_6_1
                    return SPELL_FAILED_TOO_MANY_SKILLS;
#else
                    return SPELL_FAILED_FIZZLE;
#endif

                if (m_spellInfo->spellLevel > pet->GetLevel())
                    return SPELL_FAILED_LOWLEVEL;

                if (!pet->HasTPForSpell(learn_spellproto->Id))
                    return SPELL_FAILED_TRAINING_POINTS;

                break;
            }
            case SPELL_EFFECT_FEED_PET:
            {
                if (!m_caster->IsPlayer())
                    return SPELL_FAILED_BAD_TARGETS;

                Item* foodItem = m_targets.getItemTarget();
                if (!foodItem)
                    return SPELL_FAILED_BAD_TARGETS;

                Pet* pet = m_caster->ToPlayer()->GetPet();
                Pet* pet = m_casterUnit->GetPet();

                if (!pet)
                    return SPELL_FAILED_NO_PET;

                if (!pet->HaveInDiet(foodItem->GetProto()))
                    return SPELL_FAILED_WRONG_PET_FOOD;

                if (foodItem->GetTemplate()->GetBaseItemLevel() + 30 <= pet->GetLevel())
                   return SPELL_FAILED_FOOD_LOWLEVEL;
                if (!pet->GetCurrentFoodBenefitLevel(foodItem->GetProto()->ItemLevel))
                    return SPELL_FAILED_FOOD_LOWLEVEL;

                if (m_caster->ToPlayer()->IsInCombat() || pet->IsInCombat())
                if (pet->IsInCombat())
                    return SPELL_FAILED_AFFECTING_COMBAT;

                break;
            }
            case SPELL_EFFECT_POWER_BURN:
            case SPELL_EFFECT_POWER_DRAIN:
            {
                // Can be area effect, Check only for players and not check if target - caster (spell can have multiply drain/burn effects)
                if (m_caster->IsPlayer())
                    if (Unit* target = m_targets.getUnitTarget())
                        if (target != m_caster && int32(target->GetPowerType()) != m_spellInfo->EffectMiscValue[i])
                            return SPELL_FAILED_BAD_TARGETS;
                break;
            }
            case SPELL_EFFECT_CHARGE:
            {
                Unit* unitCaster = m_caster->ToUnit();
                if (!unitCaster)
                    return SPELL_FAILED_BAD_TARGETS;

                if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CASTER_AURAS) && unitCaster->HasUnitState(UNIT_STATE_ROOT))
                if (!m_casterUnit)
                    return SPELL_FAILED_DONT_REPORT;

                if (m_casterUnit->HasUnitState(UNIT_STAT_ROOT | UNIT_STAT_PENDING_ROOT))
                    return SPELL_FAILED_ROOTED;

                // No path available?
                if (strict)
                {
                    SpellRangeEntry const* spellRange = sSpellRangeStore.LookupEntry(m_spellInfo->rangeIndex);
                    Unit* unitTarget = m_targets.getUnitTarget();
                    if (unitTarget && spellRange && spellRange->maxRange > 0.0f)
                    {
                        float x, y, z;
                        unitTarget->GetPosition(x, y, z);

                    // first we must check to see if the target is in LoS. A path can usually be built but LoS matters for charge spells
                    if (!target->IsWithinLOSInMap(unitCaster)) //Do full LoS/Path check. Don't exclude m2
                        return SPELL_FAILED_LINE_OF_SIGHT;
                        if (!m_casterUnit->IsInWater())
                        {
                            float posX, posY, posZ;
                            m_casterUnit->GetPosition(posX, posY, posZ);
                            float ground_Z = m_casterUnit->GetMap()->GetHeight(posX, posY, posZ, true);
                            float z_diff = fabs(ground_Z - posZ);

                    float objSize = target->GetCombatReach();
                    float range = m_spellInfo->GetMaxRange(true, unitCaster, this) * 1.5f + objSize; // can't be overly strict
                            PathInfo path(m_casterUnit);
                            path.SetTransport(m_casterUnit->GetTransport());
                            path.calculate(x, y, z);

                    m_preGeneratedPath = std::make_unique<PathGenerator>(unitCaster);
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
                            // On est sur terre, le chemin doit etre valide.
                            if (z_diff < 1.6f && (path.getPathType() & (PATHFIND_INCOMPLETE | PATHFIND_NOPATH)))
                                return SPELL_FAILED_NOPATH;
                            // Dans tous les cas, on interdit un chemin trop long.
                            if (path.Length() > ((spellRange->maxRange + 1.0f) * 1.5f))
                                return SPELL_FAILED_NOPATH;
                        }
                    }
                }
                break;
            }
            case SPELL_EFFECT_SKINNING:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER || !m_targets.GetUnitTarget() || m_targets.GetUnitTarget()->GetTypeId() != TYPEID_UNIT)
                    return SPELL_FAILED_BAD_TARGETS;    //技能失败:错误的目标
                if (!m_caster->IsPlayer() || !m_targets.getUnitTarget() || m_targets.getUnitTarget()->GetTypeId() != TYPEID_UNIT)
                    return SPELL_FAILED_BAD_TARGETS;

                if (!m_targets.GetUnitTarget()->HasUnitFlag(UNIT_FLAG_SKINNABLE))
                    return SPELL_FAILED_TARGET_UNSKINNABLE; //技能失败:目标无法剥皮
                if (!m_targets.getUnitTarget()->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE))
                    return SPELL_FAILED_TARGET_UNSKINNABLE;

                Creature* creature = m_targets.GetUnitTarget()->ToCreature();
                Loot* loot = creature->GetLootForPlayer(m_caster->ToPlayer());
                if (loot && (!loot->isLooted() || loot->loot_type == LOOT_SKINNING))
                    return SPELL_FAILED_TARGET_NOT_LOOTED;  //技能失败:目标未掉落
                Creature* creature = (Creature*)m_targets.getUnitTarget();
                if (!creature->IsSkinnableBy(m_caster->ToPlayer()))
                    return SPELL_FAILED_TARGET_NOT_LOOTED;

                // If the player isn't in loot range, the skins are lost forever.
                // This only happens on large mobs with disjointed models (i.e. Devilsaurs).
                if (!creature->IsWithinDistInMap(m_caster, INTERACTION_DISTANCE))
                    return SPELL_FAILED_OUT_OF_RANGE;

                int32 skillValue = m_caster->ToPlayer()->GetSkillValue(skill);
                int32 TargetLevel = m_targets.GetUnitTarget()->GetLevelForTarget(m_caster);
                int32 ReqValue = (skillValue < 100 ? (TargetLevel-10) * 10 : TargetLevel * 5);
                /*if (ReqValue > skillValue)
                    return SPELL_FAILED_LOW_CASTLEVEL;*/  //技能失败:技能等级低
                //此处注释,希望能让剥皮不提示等级过高(现在剥皮不需要等级了<10.0,更早版本都已开启>)
                int32 skillValue = ((Player*)m_caster)->GetSkillValue(SKILL_SKINNING);
                int32 TargetLevel = m_targets.getUnitTarget()->GetLevel();
                int32 ReqValue = (skillValue < 100 ? (TargetLevel - 10) * 10 : TargetLevel * 5);
                if (ReqValue > skillValue)
                    return SPELL_FAILED_LOW_CASTLEVEL;

                if (creature->GetCreatureType() != CREATURE_TYPE_CRITTER && (creature->lootForSkin || !creature->loot.isLooted()))
                {
                    /*
                    if (creature->GetEntry() == 10184) // Onyxia, Y U NO SKIN ?
                    {
                        sLog.nostalrius("[OnyxiaSkin] Instance %u Player %s", m_caster->GetInstanceId(), m_caster->GetName());
                        sLog.nostalrius("[OnyxiaSkin] Remaining gold: %u. creature->lootForSkin:%u", creature->loot.gold, creature->lootForSkin);
                        for (LootItemList::const_iterator it = creature->loot.items.begin(); it != creature->loot.items.end(); ++it)
                            sLog.nostalrius("[OnyxiaSkin] Remaining item: %u [Cond%u:Looted%u:Blocked%u:RollWinner%u]", it->itemid, it->conditionId, it->is_looted, it->is_blocked, it->lootOwner.GetCounter());
                    }
                    else
                    */
                    return SPELL_FAILED_TARGET_NOT_LOOTED;
                }

                // chance for fail at orange skinning attempt
                if ((m_selfContainer && (*m_selfContainer) == this) &&
                        skillValue < sWorld.GetConfigMaxSkillValue() &&
                        (ReqValue < 0 ? 0 : ReqValue) > irand(skillValue - 25, skillValue + 37))
                    return SPELL_FAILED_TRY_AGAIN;
                break;
            }
            case SPELL_EFFECT_OPEN_LOCK_ITEM:
            case SPELL_EFFECT_OPEN_LOCK:
            {
                if (spellEffectInfo.TargetA.GetTarget() != TARGET_GAMEOBJECT_TARGET &&
                    spellEffectInfo.TargetA.GetTarget() != TARGET_GAMEOBJECT_ITEM_TARGET)
                    break;
                if (!m_caster->IsPlayer())  // only players can open locks, gather etc.
                    return SPELL_FAILED_BAD_TARGETS;

                if (m_caster->GetTypeId() != TYPEID_PLAYER  // only players can open locks, gather etc.
                    // we need a go target in case of TARGET_GAMEOBJECT_TARGET
                    || (spellEffectInfo.TargetA.GetTarget() == TARGET_GAMEOBJECT_TARGET && !m_targets.GetGOTarget()))
                    return SPELL_FAILED_BAD_TARGETS;
                // we need a go target in case of TARGET_GAMEOBJECT (for other targets acceptable GO and items)
                if (m_spellInfo->EffectImplicitTargetA[i] == TARGET_GAMEOBJECT)
                {
                    if (!m_targets.getGOTarget())
                        return SPELL_FAILED_BAD_TARGETS;
                }

                // get the lock entry
                uint32 lockId = 0;
                if (GameObject* go = m_targets.getGOTarget())
                {
                    // In BattleGround players can use only flags and banners
                    if (((Player*)m_caster)->InBattleGround())
                    {
                        if (go->GetGoState() != GO_STATE_READY)
                            return SPELL_FAILED_BAD_TARGETS;
                        if (!((Player*)m_caster)->CanUseBattleGroundObject())
                            return SPELL_FAILED_TRY_AGAIN;
                    }

                // we need a go target, or an openable item target in case of TARGET_GAMEOBJECT_ITEM_TARGET
                if (spellEffectInfo.TargetA.GetTarget() == TARGET_GAMEOBJECT_ITEM_TARGET &&
                    !m_targets.GetGOTarget() &&
                    (!pTempItem || !pTempItem->GetTemplate()->GetLockID() || !pTempItem->IsLocked()))
                    return SPELL_FAILED_BAD_TARGETS;
                    lockId = go->GetGOInfo()->GetLockId();
                    if (!lockId)
                        return SPELL_FAILED_ALREADY_OPEN;

                    if (!go->IsUseRequirementMet())
                        return SPELL_FAILED_TRY_AGAIN;

                    // check if its in use only when cast is finished (called from spell::cast() with strict = false)
                    if (!strict && go->GetGoType() == GAMEOBJECT_TYPE_CHEST && go->loot.HasPlayersLooting())
                        return SPELL_FAILED_CHEST_IN_USE;

                    if (!strict && go->HasFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE))
                        return SPELL_FAILED_CHEST_IN_USE;

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_7_1
                    // Prevent looting chests while totally immune
                    if (go->GetGOInfo()->CannotBeUsedUnderImmunity() && m_caster->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE))
                        return SPELL_FAILED_DAMAGE_IMMUNE;
#endif
                }
                else if (Item* item = m_targets.getItemTarget())
                {
                    lockId = go->GetGOInfo()->GetLockId();
                    if (!lockId)
                        return SPELL_FAILED_BAD_TARGETS;

                    if (go->GetGOInfo()->GetNotInCombat() && m_caster->ToUnit()->IsInCombat())
                        return SPELL_FAILED_AFFECTING_COMBAT;
                }
                else if (Item* itm = m_targets.GetItemTarget())
                    lockId = itm->GetTemplate()->GetLockID();
                    // not own (trade?)
                    Player* itemOwner = item->GetOwner();
                    Player* itemTrader = itemOwner->GetTrader();

                    if (itemOwner != m_caster && itemTrader != m_caster)
                        return SPELL_FAILED_ITEM_GONE;

                    lockId = item->GetProto()->LockID;

                    // if already unlocked
                    if (!lockId || item->HasFlag(ITEM_FIELD_FLAGS, ITEM_DYNFLAG_UNLOCKED))
                        return SPELL_FAILED_ALREADY_OPEN;
                }
                else
                    return SPELL_FAILED_BAD_TARGETS;

                SkillType skillId = SKILL_NONE;
                int32 reqSkillValue = 0;
                int32 skillValue = 0;

                // check lock compatibility
                SpellCastResult res = CanOpenLock(spellEffectInfo, lockId, skillId, reqSkillValue, skillValue);
                SpellCastResult res = CanOpenLock(SpellEffectIndex(i), lockId, skillId, reqSkillValue, skillValue);
                if (res != SPELL_CAST_OK)
                {
                    DEBUG_FILTER_LOG(LOG_FILTER_SPELL_CAST, "CanOpenLock fail : erreur %x0x. (Lock%u/Skill%u)", res, lockId, skillId);
                    return res;
                break;
            }
            case SPELL_EFFECT_RESURRECT_PET:
            {
                Player* playerCaster = m_caster->ToPlayer();
                if (!playerCaster || !playerCaster->GetPetStable())
                    return SPELL_FAILED_BAD_TARGETS;

                Pet* pet = playerCaster->GetPet();
                if (pet && pet->IsAlive())
                    return SPELL_FAILED_ALREADY_HAVE_SUMMON;
                }

                // chance for fail at orange mining/herb/LockPicking gathering attempt
                // second check prevent fail at rechecks
                if ((skillId == SKILL_HERBALISM || skillId == SKILL_MINING || skillId == SKILL_LOCKPICKING) 
                    && (m_selfContainer && (*m_selfContainer) == this))
                {
                    bool canFailAtMax = skillId != SKILL_HERBALISM && skillId != SKILL_MINING;

                PetStable const* petStable = playerCaster->GetPetStable();
                auto deadPetItr = std::find_if(petStable->ActivePets.begin(), petStable->ActivePets.end(), [](Optional<PetStable::PetInfo> const& petInfo)
                {
                    return petInfo && !petInfo->Health;
                });

                if (deadPetItr == petStable->ActivePets.end())
                    return SPELL_FAILED_BAD_TARGETS;

                    // chance for failure in orange gather / lockpick (gathering skill can't fail at maxskill)
                    if ((canFailAtMax || skillValue < sWorld.GetConfigMaxSkillValue()) && reqSkillValue > irand(skillValue - 25, skillValue + 37))
                        return SPELL_FAILED_TRY_AGAIN;
                }
                break;
            }
            // This is generic summon effect
            case SPELL_EFFECT_SUMMON:
            {
                Unit* unitCaster = m_caster->ToUnit();
                if (!unitCaster)
                    break;

                SummonPropertiesEntry const* SummonProperties = sSummonPropertiesStore.LookupEntry(spellEffectInfo.MiscValueB);
                if (!SummonProperties)
                    break;

                switch (SummonProperties->Control)
            case SPELL_EFFECT_ACTIVATE_OBJECT:
            {
                if (m_spellInfo->Id == 15958) // Collect Rookery Egg
                { 
                    if (!m_UniqueGOTargetInfo.empty())
                    {
                        ObjectGuid eggGuid = m_UniqueGOTargetInfo.back().targetGUID;
                        if (GameObject* pRookeryEgg = m_caster->GetMap()->GetGameObject(eggGuid))
                        {
                            if (pRookeryEgg->GetGoState() != GO_STATE_ACTIVE_ALTERNATIVE)
                                return SPELL_FAILED_BAD_TARGETS;
                        }
                        else
                            return SPELL_FAILED_BAD_IMPLICIT_TARGETS;
                    }
                    else
                        return SPELL_FAILED_BAD_IMPLICIT_TARGETS;
                }
                else if (m_spellInfo->Id == 16447) // Spawn Challenge to Urok
                {
                    if (m_UniqueGOTargetInfo.empty())
                        return SPELL_FAILED_BAD_IMPLICIT_TARGETS;
                }
                else if (m_spellInfo->Id == 24973) // Clean Up Stink Bomb
                {
                    case SUMMON_CATEGORY_PET:
                        if (!m_spellInfo->HasAttribute(SPELL_ATTR1_DISMISS_PET_FIRST) && !unitCaster->GetPetGUID().IsEmpty())
                            return SPELL_FAILED_ALREADY_HAVE_SUMMON;
                        [[fallthrough]]; // check both GetPetGUID() and GetCharmGUID for SUMMON_CATEGORY_PET
                    case SUMMON_CATEGORY_PUPPET:
                        if (!unitCaster->GetCharmedGUID().IsEmpty())
                            return SPELL_FAILED_ALREADY_HAVE_CHARM;
                        break;
                    if (m_UniqueGOTargetInfo.empty())
                        return SPELL_FAILED_BAD_IMPLICIT_TARGETS;
                }
                break;
            }
            case SPELL_EFFECT_CREATE_TAMED_PET:
            {
                if (m_targets.GetUnitTarget())
                {
                    if (m_targets.GetUnitTarget()->GetTypeId() != TYPEID_PLAYER)
                        return SPELL_FAILED_BAD_TARGETS;
                    if (!m_spellInfo->HasAttribute(SPELL_ATTR1_DISMISS_PET_FIRST) && !m_targets.GetUnitTarget()->GetPetGUID().IsEmpty())
                        return SPELL_FAILED_ALREADY_HAVE_SUMMON;
                }
            case SPELL_EFFECT_SUMMON_DEAD_PET:
            {
                Creature* pet = m_casterUnit ? m_casterUnit->GetPet() : nullptr;
                if (!pet)
                    return SPELL_FAILED_NO_PET;

                if (pet->IsAlive())
                    return SPELL_FAILED_ALREADY_HAVE_SUMMON;

                break;
            }
            // Don't make this check for SPELL_EFFECT_SUMMON_CRITTER, SPELL_EFFECT_SUMMON_WILD or SPELL_EFFECT_SUMMON_GUARDIAN.
            // These won't show up in m_caster->GetPetGUID()
            case SPELL_EFFECT_SUMMON:
            case SPELL_EFFECT_SUMMON_PHANTASM:
            case SPELL_EFFECT_SUMMON_DEMON:
                if (m_casterUnit && m_casterUnit->GetPetGuid())
                    return SPELL_FAILED_ALREADY_HAVE_SUMMON;
            // no break
            case SPELL_EFFECT_SUMMON_POSSESSED:
                if (m_casterUnit && m_casterUnit->GetCharmGuid())
                    return SPELL_FAILED_ALREADY_HAVE_CHARM;
                break;
            case SPELL_EFFECT_SUMMON_PET:
            {
                Unit* unitCaster = m_caster->ToUnit();
                if (!unitCaster)
                    return SPELL_FAILED_BAD_TARGETS;

                if (!unitCaster->GetPetGUID().IsEmpty())       //let warlock do a replacement summon
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
                // In Vanilla old pets were unsummoned as soon as you began summoning a new one.
                if (m_casterUnit && !m_casterUnit->UnsummonOldPetBeforeNewSummon(m_spellInfo->EffectMiscValue[i]))
                    return SPELL_FAILED_ALREADY_HAVE_SUMMON;

                if (!unitCaster->GetCharmedGUID().IsEmpty())
                if (m_casterUnit && m_casterUnit->GetCharmGuid())
                    return SPELL_FAILED_ALREADY_HAVE_CHARM;

                Player* playerCaster = unitCaster->ToPlayer();
                if (playerCaster && playerCaster->GetPetStable())
                {
                    Optional<PetSaveMode> petSlot;
                    if (!spellEffectInfo.MiscValue)
                    {
                        petSlot = PetSaveMode(spellEffectInfo.CalcValue());

                        // No pet can be summoned if any pet is dead
                        for (Optional<PetStable::PetInfo> const& activePet : playerCaster->GetPetStable()->ActivePets)
                        {
                            if (activePet && !activePet->Health)
                            {
                                playerCaster->SendTameFailure(PetTameResult::Dead);
                                return SPELL_FAILED_DONT_REPORT;
                            }
                        }
                    }

                    std::pair<PetStable::PetInfo const*, PetSaveMode> info = Pet::GetLoadPetInfo(*playerCaster->GetPetStable(), spellEffectInfo.MiscValue, 0, petSlot);
                    if (info.first)
                    {
                        if (info.first->Type == HUNTER_PET)
                        {
                            CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(info.first->CreatureId);
                            if (!creatureInfo || !creatureInfo->IsTameable(playerCaster->CanTameExoticPets()))
                            {
                                // if problem in exotic pet
                                if (creatureInfo && creatureInfo->IsTameable(true))
                                    playerCaster->SendTameFailure(PetTameResult::CantControlExotic);
                                else
                                    playerCaster->SendTameFailure(PetTameResult::NoPetAvailable);

                                return SPELL_FAILED_DONT_REPORT;
                            }
                        }
                    }
                    else if (!spellEffectInfo.MiscValue) // when miscvalue is present it is allowed to create new pets
                    {
                        playerCaster->SendTameFailure(PetTameResult::NoPetAvailable);
                        return SPELL_FAILED_DONT_REPORT;
                    }
                }


                break;
            }
            case SPELL_EFFECT_DISMISS_PET:
            {
                Player* playerCaster = m_caster->ToPlayer();
                if (!playerCaster)
                    return SPELL_FAILED_BAD_TARGETS;

                Pet* pet = playerCaster->GetPet();
                if (!pet)
                    return SPELL_FAILED_NO_PET;

                if (!pet->IsAlive())
                    return SPELL_FAILED_TARGETS_DEAD;

                break;
            }
            case SPELL_EFFECT_SUMMON_PLAYER:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_BAD_TARGETS;

                if (!m_caster->ToPlayer()->GetTarget())
                    return SPELL_FAILED_BAD_TARGETS;
            case SPELL_EFFECT_TRANS_DOOR:
            {
                if (!m_casterUnit)
                    return SPELL_FAILED_BAD_TARGETS;

                if (m_casterUnit->GetClass() == CLASS_WARLOCK &&  m_spellInfo->Id == 698)
                {
                    if (!m_caster->IsPlayer())
                        return SPELL_FAILED_BAD_TARGETS;
                    if (!((Player*)m_caster)->GetSelectionGuid())
                        return SPELL_FAILED_BAD_TARGETS;

                    Player* target = sObjectMgr.GetPlayer(((Player*)m_caster)->GetSelectionGuid());
                    if (!target || ((Player*)m_caster) == target || !target->IsInSameRaidWith((Player*)m_caster))
                        return SPELL_FAILED_BAD_TARGETS;

                    if (target->IsInCombat())
                        return SPELL_FAILED_TARGET_IN_COMBAT;

                // check if our map is dungeon
                if (InstanceMap const* map = m_caster->GetMap()->ToInstanceMap())
                {
                    uint32 mapId = map->GetId();
                    Difficulty difficulty = map->GetDifficultyID();
                    if (InstanceLock const* mapLock = map->GetInstanceLock())
                        if (sInstanceLockMgr.CanJoinInstanceLock(target->GetGUID(), { mapId, difficulty }, mapLock) != TRANSFER_ABORT_NONE)
                            return SPELL_FAILED_TARGET_LOCKED_TO_RAID_INSTANCE;

                    if (!target->Satisfy(sObjectMgr->GetAccessRequirement(mapId, difficulty), mapId))
                        return SPELL_FAILED_BAD_TARGETS;
                    // check if our map is dungeon
                    MapEntry const* mapEntry = sMapStorage.LookupEntry<MapEntry>(m_caster->GetMapId());
                    if (mapEntry && mapEntry->IsDungeon())
                    {
                        if (m_caster->GetMap() != target->GetMap())
                            return SPELL_FAILED_TARGET_NOT_IN_INSTANCE;
                    }
                    else if (m_caster->ToPlayer()->InBattleGround())
                        return SPELL_FAILED_NOT_HERE;
                }
                break;
            }
            case SPELL_EFFECT_SUMMON_PLAYER:
            {
                if (!m_caster->IsPlayer())
                    return SPELL_FAILED_BAD_TARGETS;

                Player* playerCaster = m_caster->ToPlayer();
                if (!playerCaster->GetTarget())
                if (!m_targets.getUnitTarget())
                    return SPELL_FAILED_BAD_TARGETS;
                if (!m_targets.getUnitTarget()->IsPlayer())
                    return SPELL_FAILED_BAD_TARGETS;

                Player* target = playerCaster->GetSelectedPlayer();
                if (!target ||
                    !(target->GetSession()->GetRecruiterId() == playerCaster->GetSession()->GetAccountId() || target->GetSession()->GetAccountId() == playerCaster->GetSession()->GetRecruiterId()))
                Player* target = (Player*)m_targets.getUnitTarget();
                if (!target || ((Player*)m_caster) == target || !target->IsInSameRaidWith((Player*)m_caster))
                    return SPELL_FAILED_BAD_TARGETS;

                // check if our map is dungeon
                MapEntry const* mapEntry = sMapStorage.LookupEntry<MapEntry>(m_caster->GetMapId());
                if (mapEntry && mapEntry->IsDungeon())
                {
                    if (m_caster->GetMap() != target->GetMap())
                        return SPELL_FAILED_TARGET_NOT_IN_INSTANCE;
                }
                else if (m_caster->ToPlayer()->InBattleGround())
                    return SPELL_FAILED_NOT_HERE;
                break;
            }
            case SPELL_EFFECT_LEAP:
            case SPELL_EFFECT_TELEPORT_UNITS_FACE_CASTER:
            {
                //Do not allow to cast it before BG starts.
                if (m_caster->GetTypeId() == TYPEID_PLAYER)
                    if (Battleground const* bg = m_caster->ToPlayer()->GetBattleground())
                // not allow use this effect at battleground until battleground start (Nostalrius: Blizzlike)
                if (m_caster->IsPlayer())
                    if (BattleGround const* bg = ((Player*)m_caster)->GetBattleGround())
                        if (bg->GetStatus() != STATUS_IN_PROGRESS)
                            return SPELL_FAILED_TRY_AGAIN;
                // Blizzlike: no blink on transport (client does not handle it)
                if (m_caster->GetTransport())
                    return SPELL_FAILED_NOT_ON_TRANSPORT;
                break;
            }
            case SPELL_EFFECT_DUEL:
            {
                Unit* target = m_targets.getUnitTarget();
                if (target && target->GetTransport() != m_caster->GetTransport())
                    return SPELL_FAILED_NOT_ON_TRANSPORT;
                break;
            }
            case SPELL_EFFECT_SCRIPT_EFFECT:
            {
                Unit* unitCaster = m_caster->ToUnit();
                if (!unitCaster)
                    return SPELL_FAILED_BAD_TARGETS;

                if (unitCaster->HasUnitState(UNIT_STATE_ROOT))
                {
                    if (unitCaster->GetTypeId() == TYPEID_PLAYER)
                        return SPELL_FAILED_ROOTED;
                    else
                        return SPELL_FAILED_DONT_REPORT;
                if (unitCaster->HasUnitState(UNIT_STATE_ROOT))
                    return SPELL_FAILED_ROOTED;
                break;
            }
            case SPELL_EFFECT_TALENT_SPEC_SELECT:
            {
                ChrSpecializationEntry const* spec = sChrSpecializationStore.LookupEntry(m_misc.SpecializationId);
                Player* player = m_caster->ToPlayer();
                if (!player)
                    return SPELL_FAILED_TARGET_NOT_PLAYER;
                if (!m_casterUnit)
                    break;

                // Black Qiraji Battle Tank
                if (m_spellInfo->Id == 26656)
                {
                    if (m_casterUnit->IsMounted())
                    {
                        m_casterUnit->RemoveSpellsCausingAura(SPELL_AURA_MOUNTED);
                        return SPELL_FAILED_DONT_REPORT;
                    }

                if (!spec || (spec->ClassID != player->GetClass() && !spec->IsPetSpecialization()))
                    return SPELL_FAILED_NO_SPEC;
                    if (m_casterUnit->IsInWater() && (!m_casterUnit->IsPlayer() || static_cast<Player*>(m_casterUnit)->IsInHighLiquid()))
                        return SPELL_FAILED_ONLY_ABOVEWATER;

                    if (Player* pPlayer = m_casterUnit->ToPlayer())
                    {
                        if (pPlayer->GetTransport())
                            return SPELL_FAILED_NO_MOUNTS_ALLOWED;

                        if (m_casterUnit->GetMapId() != 531 && !sMapStorage.LookupEntry<MapEntry>(m_casterUnit->GetMapId())->IsMountAllowed() && !m_IsTriggeredSpell)
                            return SPELL_FAILED_NO_MOUNTS_ALLOWED;
                    }

                // can't change during already started arena/battleground
                if (Battleground const* bg = player->GetBattleground())
                    if (bg->GetStatus() == STATUS_IN_PROGRESS)
                        return SPELL_FAILED_NOT_IN_BATTLEGROUND;
                break;
            }
            case SPELL_EFFECT_REMOVE_TALENT:
            {
                Player* playerCaster = m_caster->ToPlayer();
                if (!playerCaster)
                    return SPELL_FAILED_BAD_TARGETS;

                TalentEntry const* talent = sTalentStore.LookupEntry(m_misc.TalentId);
                if (!talent)
                    return SPELL_FAILED_DONT_REPORT;

                if (playerCaster->GetSpellHistory()->HasCooldown(talent->SpellID))
                {
                    if (param1)
                        *param1 = talent->SpellID;
                    return SPELL_FAILED_CANT_UNTALENT;
                }
                    if (m_casterUnit->GetAreaId() == 35)
                        return SPELL_FAILED_NO_MOUNTS_ALLOWED;

                    if (m_casterUnit->IsInDisallowedMountForm())
                        return SPELL_FAILED_NOT_SHAPESHIFT;

                    if (m_casterUnit->GetMapId() == 531)
                        break;
                }
            }
            default:
                break;
            }
            case SPELL_EFFECT_GIVE_ARTIFACT_POWER:
            case SPELL_EFFECT_GIVE_ARTIFACT_POWER_NO_BONUS:
            {
                Player* playerCaster = m_caster->ToPlayer();
                if (!playerCaster)
                    return SPELL_FAILED_BAD_TARGETS;

                Aura* artifactAura = playerCaster->GetAura(ARTIFACTS_ALL_WEAPONS_GENERAL_WEAPON_EQUIPPED_PASSIVE);
                if (!artifactAura)
                    return SPELL_FAILED_NO_ARTIFACT_EQUIPPED;

                Item* artifact = playerCaster->GetItemByGuid(artifactAura->GetCastItemGUID());
                if (!artifact)
                    return SPELL_FAILED_NO_ARTIFACT_EQUIPPED;

                if (spellEffectInfo.Effect == SPELL_EFFECT_GIVE_ARTIFACT_POWER)
                {
                    ArtifactEntry const* artifactEntry = sArtifactStore.LookupEntry(artifact->GetTemplate()->GetArtifactID());
                    if (!artifactEntry || artifactEntry->ArtifactCategoryID != spellEffectInfo.MiscValue)
                        return SPELL_FAILED_WRONG_ARTIFACT_EQUIPPED;
                }
                break;
            }
            case SPELL_EFFECT_CHANGE_BATTLEPET_QUALITY:
            case SPELL_EFFECT_GRANT_BATTLEPET_LEVEL:
            case SPELL_EFFECT_GRANT_BATTLEPET_EXPERIENCE:
            {
                Player* playerCaster = m_caster->ToPlayer();
                if (!playerCaster || !m_targets.GetUnitTarget() || !m_targets.GetUnitTarget()->IsCreature())
                    return SPELL_FAILED_BAD_TARGETS;

                BattlePets::BattlePetMgr* battlePetMgr = playerCaster->GetSession()->GetBattlePetMgr();
                if (!battlePetMgr->HasJournalLock())
                    return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

                Creature* creature = m_targets.GetUnitTarget()->ToCreature();
                if (creature)
                {
                    if (playerCaster->GetSummonedBattlePetGUID().IsEmpty() || creature->GetBattlePetCompanionGUID().IsEmpty())
                        return SPELL_FAILED_NO_PET;

                    if (playerCaster->GetSummonedBattlePetGUID() != creature->GetBattlePetCompanionGUID())
                        return SPELL_FAILED_BAD_TARGETS;

                    if (BattlePets::BattlePet* battlePet = battlePetMgr->GetPet(creature->GetBattlePetCompanionGUID()))
                    {
                        if (BattlePetSpeciesEntry const* battlePetSpecies = sBattlePetSpeciesStore.LookupEntry(battlePet->PacketInfo.Species))
                        {
                            if (uint32 battlePetType = spellEffectInfo.MiscValue)
                                if (!(battlePetType & (1 << battlePetSpecies->PetTypeEnum)))
                                    return SPELL_FAILED_WRONG_BATTLE_PET_TYPE;

                            if (spellEffectInfo.Effect == SPELL_EFFECT_CHANGE_BATTLEPET_QUALITY)
                            {
                                auto qualityItr = std::lower_bound(sBattlePetBreedQualityStore.begin(), sBattlePetBreedQualityStore.end(), spellEffectInfo.BasePoints, [](BattlePetBreedQualityEntry const* a1, int32 selector)
                                {
                                    return a1->MaxQualityRoll < selector;
                                });

                                BattlePets::BattlePetBreedQuality quality = BattlePets::BattlePetBreedQuality::Poor;
                                if (qualityItr != sBattlePetBreedQualityStore.end())
                                    quality = BattlePets::BattlePetBreedQuality(qualityItr->QualityEnum);

                                if (battlePet->PacketInfo.Quality >= AsUnderlyingType(quality))
                                    return SPELL_FAILED_CANT_UPGRADE_BATTLE_PET;
                            }

                            if (spellEffectInfo.Effect == SPELL_EFFECT_GRANT_BATTLEPET_LEVEL || spellEffectInfo.Effect == SPELL_EFFECT_GRANT_BATTLEPET_EXPERIENCE)
                                if (battlePet->PacketInfo.Level >= BattlePets::MAX_BATTLE_PET_LEVEL)
                                    return GRANT_PET_LEVEL_FAIL;

                            if (battlePetSpecies->GetFlags().HasFlag(BattlePetSpeciesFlags::CantBattle))
                                return SPELL_FAILED_BAD_TARGETS;
                        }
                    }
                }
                break;
            }
            default:
                break;
        }

        if (spellEffectInfo.IsAura())
            approximateAuraEffectMask |= 1 << spellEffectInfo.EffectIndex;
        else if (spellEffectInfo.IsEffect())
            nonAuraEffectMask |= 1 << spellEffectInfo.EffectIndex;
    }
        }
    }

    if (m_spellInfo->IsNonPeriodicDispel() && !m_IsTriggeredSpell) // Buff Abolir le poison non concerne par exemple (Debuff a chaque tic)
    {
        uint32 dispelMask     = 0;
        bool bFoundOneDispell = false;
        // Compute Dispel Mask
        for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
        {
            if (m_spellInfo->Effect[i] != SPELL_EFFECT_DISPEL)
                continue;

            // Create dispel mask by dispel type
            uint32 dispel_type = m_spellInfo->EffectMiscValue[i];
            dispelMask |= GetDispellMask(DispelType(dispel_type));
        }
        Unit* unit_target = m_targets.getUnitTarget();
        bool friendly_dispel = unit_target && unit_target->IsFriendlyTo(m_caster);

        if (unit_target &&
                // Check immune for offensive dispel
                (!unit_target->IsImmuneToSchoolMask(m_spellInfo->GetSpellSchoolMask()) ||
                 friendly_dispel))
        {
            if (!friendly_dispel && !m_caster->IsValidAttackTarget(unit_target))
                return SPELL_FAILED_BAD_TARGETS;

            auto const& auras = unit_target->GetSpellAuraHolderMap();
            for (const auto& aura : auras)
            {
                SpellAuraHolder* holder = aura.second;
                if ((1 << holder->GetSpellProto()->Dispel) & dispelMask)
                {
                    if (holder->GetSpellProto()->Dispel == DISPEL_MAGIC ||
                        holder->GetSpellProto()->Dispel == DISPEL_POISON)
                    {
                        bool positive = holder->IsPositive();
                        // do not remove positive auras if friendly target
                        // do not remove negative auras if non-friendly target
                        // when removing charm auras ignore hostile reaction from the charm
                        if (!friendly_dispel && !positive && holder->GetSpellProto()->IsCharmSpell())
                            if (CharmInfo *charm = unit_target->GetCharmInfo())
                                if (FactionTemplateEntry const* ft = charm->GetOriginalFactionTemplate())
                                    if (charm->GetOriginalFactionTemplate()->IsFriendlyTo(*m_caster->getFactionTemplateEntry()))
                                        bFoundOneDispell = true;
                        if (positive == friendly_dispel)
                            continue;
                    }
                    if (holder->GetSpellProto()->Dispel == DISPEL_POISON)
                    {
                        switch (m_spellInfo->Id)
                        {
                            case 7932:       // Anti-Venom
                                if (holder->GetSpellProto()->spellLevel > 25)
                                    return SPELL_FAILED_HIGHLEVEL;
                                break;
                            case 7933:      // Strong Anti-Venom
                                if (holder->GetSpellProto()->spellLevel > 35)
                                    return SPELL_FAILED_HIGHLEVEL;
                                break;
                            case 23786:     // Powerful Anti-Venom
                                if (holder->GetSpellProto()->spellLevel > 60)
                                    return SPELL_FAILED_HIGHLEVEL;
                                break;
                        }
                    }
                    bFoundOneDispell = true;
                    break;
                }
            }
        }
        // World of Warcraft Client Patch 1.10.0 (2006-03-28)
        //  - All spells / abilities that remove existing effects(e.g.Dispel Magic,
        //    Cleanse, Remove Curse etc...) will now verify that there is an effect
        //    that can be removed before casting.
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
        if (!bFoundOneDispell)
        {
            return SPELL_FAILED_NOTHING_TO_DISPEL;
        }
#endif
    }

    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
    for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
    {
        switch (spellEffectInfo.ApplyAuraName)
        switch (m_spellInfo->EffectApplyAuraName[i])
        {
            case SPELL_AURA_MOD_POSSESS:
            {
                if (!m_caster->IsPlayer())
                    return SPELL_FAILED_BAD_TARGETS;

                if (m_targets.getUnitTarget() == m_casterUnit)
                    return SPELL_FAILED_BAD_TARGETS;

                if (!pet->GetCharmerGUID().IsEmpty())
                    return SPELL_FAILED_ALREADY_HAVE_CHARM;
                if (m_casterUnit->GetPetGuid())
                    return SPELL_FAILED_ALREADY_HAVE_SUMMON;

                if (m_casterUnit->GetCharmGuid())
                    return SPELL_FAILED_ALREADY_HAVE_CHARM;

                if (m_casterUnit->GetCharmerGuid())
#if SUPPORTED_CLIENT_BUILD >= CLIENT_BUILD_1_11_2
                    return SPELL_FAILED_CHARMED;
#else
                    return SPELL_FAILED_FIZZLE;
#endif

                if (!m_targets.getUnitTarget())
                    return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

                if (m_targets.getUnitTarget()->GetCharmerGuid())
#if SUPPORTED_CLIENT_BUILD >= CLIENT_BUILD_1_11_2
                    return SPELL_FAILED_CHARMED;
#else
                    return SPELL_FAILED_FIZZLE;
#endif

                if (m_spellInfo->Id != 530) // Spell for ".possess" command.
                    if (int32(m_targets.getUnitTarget()->GetLevel()) > CalculateDamage(SpellEffectIndex(i), m_targets.getUnitTarget()))
                        return SPELL_FAILED_HIGHLEVEL;

                break;
            }
            case SPELL_AURA_MOD_CHARM:
            {
                Unit* unitCaster = (m_originalCaster ? m_originalCaster : m_caster->ToUnit());
                if (!unitCaster)
                    return SPELL_FAILED_BAD_TARGETS;

                if (!unitCaster->GetCharmerGUID().IsEmpty())
                    return SPELL_FAILED_CHARMED;
                if (!m_casterUnit)
                    return SPELL_FAILED_BAD_TARGETS;

                if (spellEffectInfo.ApplyAuraName == SPELL_AURA_MOD_CHARM
                    || spellEffectInfo.ApplyAuraName == SPELL_AURA_MOD_POSSESS)
                {
                    if (!m_spellInfo->HasAttribute(SPELL_ATTR1_DISMISS_PET_FIRST) && !unitCaster->GetPetGUID().IsEmpty())
                        return SPELL_FAILED_ALREADY_HAVE_SUMMON;
                if (m_targets.getUnitTarget() == m_casterUnit)
                    return SPELL_FAILED_BAD_TARGETS;

                if (m_casterUnit->GetPetGuid())
                    return SPELL_FAILED_ALREADY_HAVE_SUMMON;

                    if (!unitCaster->GetCharmedGUID().IsEmpty())
                        return SPELL_FAILED_ALREADY_HAVE_CHARM;
                }
                if (m_casterUnit->GetCharmGuid())
                    return SPELL_FAILED_ALREADY_HAVE_CHARM;

                if (m_casterUnit->GetCharmerGuid())
#if SUPPORTED_CLIENT_BUILD >= CLIENT_BUILD_1_11_2
                    return SPELL_FAILED_CHARMED;
#else
                    return SPELL_FAILED_FIZZLE;
#endif

                if (!m_targets.getUnitTarget())
                    return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

                    if (target->IsMounted())
                        return SPELL_FAILED_CANT_BE_CHARMED;

                    if (!target->GetCharmerGUID().IsEmpty())
                        return SPELL_FAILED_ALREADY_HAVE_CHARM;
                if (m_targets.getUnitTarget()->GetCharmerGuid())
#if SUPPORTED_CLIENT_BUILD >= CLIENT_BUILD_1_11_2
                    return SPELL_FAILED_CHARMED;
#else
                    return SPELL_FAILED_FIZZLE;
#endif

                    if (target->GetOwner() && target->GetOwner()->GetTypeId() == TYPEID_PLAYER)
                        return SPELL_FAILED_TARGET_IS_PLAYER_CONTROLLED;

                    int32 value = CalculateDamage(spellEffectInfo, target);
                    if (value && int32(target->GetLevelForTarget(m_caster)) > value)
                        return SPELL_FAILED_HIGHLEVEL;
                }
                if (int32(m_targets.getUnitTarget()->GetLevel()) > CalculateDamage(SpellEffectIndex(i), m_targets.getUnitTarget()))
                    return SPELL_FAILED_HIGHLEVEL;

                break;
            }
            case SPELL_AURA_MOD_POSSESS_PET:
            {
                if (!m_caster->IsPlayer())
                    return SPELL_FAILED_BAD_TARGETS;

                if (m_casterUnit->GetCharmGuid())
                    return SPELL_FAILED_ALREADY_HAVE_CHARM;

                if (m_casterUnit->GetCharmerGuid())
#if SUPPORTED_CLIENT_BUILD >= CLIENT_BUILD_1_11_2
                    return SPELL_FAILED_CHARMED;
#else
                    return SPELL_FAILED_FIZZLE;
#endif

                Pet* pet = m_casterUnit->GetPet();
                if (!pet)
                    return SPELL_FAILED_NO_PET;

                if (pet->GetCharmerGuid())
#if SUPPORTED_CLIENT_BUILD >= CLIENT_BUILD_1_11_2
                    return SPELL_FAILED_CHARMED;
#else
                    return SPELL_FAILED_FIZZLE;
#endif

                break;
            }
            case SPELL_AURA_MOUNTED:
            {
                Unit* unitCaster = m_caster->ToUnit();
                if (!unitCaster)
                    return SPELL_FAILED_BAD_TARGETS;

                if (unitCaster->IsInWater() && m_spellInfo->HasAura(SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED))
                if (!m_casterUnit)
                    return SPELL_FAILED_BAD_TARGETS;

                if (m_casterUnit->IsInWater() && (!m_casterUnit->IsPlayer() || static_cast<Player*>(m_casterUnit)->IsInHighLiquid()))
                    return SPELL_FAILED_ONLY_ABOVEWATER;

                if (unitCaster->IsInDisallowedMountForm())
                if (m_casterUnit->IsPlayer() && static_cast<Player*>(m_casterUnit)->GetTransport())
                    return SPELL_FAILED_NO_MOUNTS_ALLOWED;

                /// Specific case for Temple of Ahn'Qiraj mounts as they are usable only in AQ40 and are the only mounts allowed here
                /// TBC and above handle this by using m_spellInfo->AreaId
                bool isAQ40Mount = false;

                switch (m_spellInfo->Id)
                {
                    SendMountResult(MountResult::Shapeshifted); // mount result gets sent before the cast result
                    return SPELL_FAILED_DONT_REPORT;
                }
                    case 25863:    // spell used by the Black Qiraji Crystal script when mounting inside AQ40
                    case 25953:    // spells of the 4 regular AQ40 mounts
                    case 26054:
                    case 26055:
                    case 26056:
                        if (m_casterUnit->GetMapId() == 531)
                        {
                            isAQ40Mount = true;
                            break;
                        }
                        else
                            return SPELL_FAILED_NOT_HERE;
                    default:
                        if ((m_casterUnit->GetMapId() == 531 && m_casterUnit->GetTerrain()->IsOutdoors(m_casterUnit->GetPositionX(), m_casterUnit->GetPositionY(), m_casterUnit->GetPositionZ())))
                            isAQ40Mount = true;
                        break;
                }

                // Ignore map check if spell have AreaId. AreaId already checked and this prevent special mount spells
                if (!isAQ40Mount && m_casterUnit->IsPlayer() && !sMapStorage.LookupEntry<MapEntry>(m_casterUnit->GetMapId())->IsMountAllowed() && !m_IsTriggeredSpell) //[-ZERO] && !m_spellInfo->AreaId)
                    return SPELL_FAILED_NO_MOUNTS_ALLOWED;

                if (m_casterUnit->GetAreaId() == 35)
                    return SPELL_FAILED_NO_MOUNTS_ALLOWED;

                if (m_casterUnit->IsInDisallowedMountForm())
                    return SPELL_FAILED_NOT_SHAPESHIFT;

                break;
            }
            case SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS:
            {
                if (!m_targets.getUnitTarget())
                    return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

                // can be casted at non-friendly unit or own pet/charm
                if (m_caster->IsFriendlyTo(m_targets.getUnitTarget()))
                    return SPELL_FAILED_TARGET_FRIENDLY;
                break;
            }
            case SPELL_AURA_PERIODIC_MANA_LEECH:
            {
                if (spellEffectInfo.IsTargetingArea())
                    break;

                if (!m_targets.GetUnitTarget())
                if (!m_targets.getUnitTarget() && 
                        !IsAreaEffectTarget(SpellTarget(m_spellInfo->EffectImplicitTargetA[i])) &&
                        !IsAreaEffectTarget(SpellTarget(m_spellInfo->EffectImplicitTargetB[i])))
                    return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

                if (!m_caster->IsPlayer() || m_CastItem)
                    break;

                if (m_targets.getUnitTarget()->GetPowerType() != POWER_MANA)
                    return SPELL_FAILED_BAD_TARGETS;
                break;
            }
            case SPELL_AURA_MOD_SHAPESHIFT:
            {
                if (m_casterUnit && m_casterUnit->HasAura(23397)) // Ustaag <Nostalrius> : Nefarian Warrior Class Call
                    return SPELL_FAILED_NOT_SHAPESHIFT;
                break;
            }
            case SPELL_AURA_MOD_STALKED:
            {
                if (!m_targets.getUnitTarget())
                    return SPELL_FAILED_BAD_IMPLICIT_TARGETS;
                // Example: Hunter's mark #1130
                if (m_spellInfo->EffectImplicitTargetA[i] == TARGET_UNIT &&
                    !m_caster->IsValidAttackTarget(m_targets.getUnitTarget()) &&
                    !m_spellInfo->IsFitToFamily<SPELLFAMILY_PRIEST, CF_PRIEST_MIND_VISION>())   // exception for mind vision
                    return SPELL_FAILED_BAD_TARGETS;
                break;
            }
            case SPELL_AURA_WATER_WALK:
            {
                if (Unit* pTarget = m_targets.getUnitTarget())
                {
                    // Player is not allowed to cast water walk on shapeshifted / mounted target
                    if (pTarget->IsShapeShifted() || pTarget->IsMounted())
                        return SPELL_FAILED_BAD_TARGETS;
                }
                break;
            }
            default:
                break;
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

        }

        // check if target already has the same type, but more powerful aura
        if (!m_spellInfo->HasAttribute(SPELL_ATTR4_AURA_NEVER_BOUNCES)
            && (!nonAuraEffectMask || m_spellInfo->HasAttribute(SPELL_ATTR4_AURA_BOUNCE_FAILS_SPELL))
            && (approximateAuraEffectMask & (1 << spellEffectInfo.EffectIndex))
            && !m_spellInfo->IsTargetingArea())
            if (Unit* target = m_targets.GetUnitTarget())
                if (!target->IsHighestExclusiveAuraEffect(m_spellInfo, spellEffectInfo.ApplyAuraName,
                    spellEffectInfo.CalcValue(m_caster, &m_spellValue->EffectBasePoints[spellEffectInfo.EffectIndex], nullptr, nullptr, m_castItemEntry, m_castItemLevel),
                    approximateAuraEffectMask, false))
                    return SPELL_FAILED_AURA_BOUNCED;
    }

    // check trade slot case (last, for allow catch any another cast problems)
    if (m_targets.m_targetMask & TARGET_FLAG_TRADE_ITEM)
    {
        if (m_CastItem)
            return SPELL_FAILED_ITEM_ENCHANT_TRADE_WINDOW;

        if (m_spellInfo->HasAttribute(SPELL_ATTR2_ENCHANT_OWN_ITEM_ONLY))
            return SPELL_FAILED_ITEM_ENCHANT_TRADE_WINDOW;

        if (m_caster->GetTypeId() != TYPEID_PLAYER)
        if (!m_caster->IsPlayer())
            return SPELL_FAILED_NOT_TRADING;

        TradeData* my_trade = m_caster->ToPlayer()->GetTradeData();
        Player* pCaster = ((Player*)m_caster);
        TradeData* my_trade = pCaster->GetTradeData();

        if (!my_trade)
            return SPELL_FAILED_NOT_TRADING;

        TradeSlots slot = TradeSlots(m_targets.getItemTargetGuid().GetRawValue());
        if (slot != TRADE_SLOT_NONTRADED)
            return SPELL_FAILED_ITEM_NOT_READY;

        // if trade not complete then remember it in trade data
        if (!my_trade->IsInAcceptProcess())
        {
            // Spell will be casted at completing the trade. Silently ignore at this place
            my_trade->SetSpell(m_spellInfo->Id, m_CastItem);
            return SPELL_FAILED_DONT_REPORT;
        }
    }

    // all ok
    return SPELL_CAST_OK;
}

SpellCastResult Spell::CheckPetCast(Unit* target)
{
    Unit* unitCaster = m_caster->ToUnit();
    if (unitCaster && unitCaster->HasUnitState(UNIT_STATE_CASTING) && !(_triggeredCastFlags & TRIGGERED_IGNORE_CAST_IN_PROGRESS))              //prevent spellcast interruption by another spellcast
    if (!m_casterUnit->IsAlive())
        return SPELL_FAILED_CASTER_DEAD;

    //prevent spellcast interruption by another spellcast
    if (m_casterUnit->IsNonMeleeSpellCasted(false))
        return SPELL_FAILED_SPELL_IN_PROGRESS;

    if (m_casterUnit->IsInCombat() && m_spellInfo->IsNonCombatSpell())
        return SPELL_FAILED_AFFECTING_COMBAT;

    if (m_casterUnit->IsCreature() && (((Creature*)m_casterUnit)->IsPet() || m_casterUnit->IsCharmed()))
    {
        //dead owner (pets still alive when owners ressed?)
        if (m_casterUnit->GetCharmerOrOwner() && !m_casterUnit->GetCharmerOrOwner()->IsAlive())
            return SPELL_FAILED_CASTER_DEAD;

        if (!target && m_targets.getUnitTarget())
            target = m_targets.getUnitTarget();

        bool need = false;
        for (uint32 i : m_spellInfo->EffectImplicitTargetA)
        {
            if (i == TARGET_UNIT_ENEMY ||
                    i == TARGET_UNIT_FRIEND ||
                    i == TARGET_UNIT_RAID ||
                    i == TARGET_UNIT ||
                    i == TARGET_UNIT_PARTY ||
                    i == TARGET_LOCATION_CASTER_TARGET_POSITION)
            {
                need = true;
                if (!target)
                    return SPELL_FAILED_BAD_IMPLICIT_TARGETS;
                break;
            }
        }
        if (need)
            m_targets.setUnitTarget(target);

        Unit* _target = m_targets.getUnitTarget();

    // Check if spell is affected by GCD
    if (m_spellInfo->StartRecoveryCategory > 0)
        if (unitCaster && unitCaster->GetCharmInfo() && unitCaster->GetSpellHistory()->HasGlobalCooldown(m_spellInfo))
        if (_target)                                         //for target dead/target not valid
        {
            if (!_target->IsTargetable(true, m_casterUnit->IsCharmerOrOwnerPlayerOrPlayerItself()))
                return SPELL_FAILED_BAD_TARGETS;            // guessed error

            // SPELL_EFFECT_DISPEL -> Positive or negative depending on the target
            if (m_spellInfo->IsPositiveSpell() && !m_spellInfo->HasEffect(SPELL_EFFECT_DISPEL))
            {
                if (m_casterUnit->IsHostileTo(_target))
                    return SPELL_FAILED_BAD_TARGETS;
            }
            else
            {
                bool checkValidAttackTarget = true;
                for (uint32 j : m_spellInfo->EffectImplicitTargetA)
                {
                    if (j == TARGET_UNIT ||
                        j == TARGET_ENUM_UNITS_ENEMY_IN_CONE_24 ||
                        j == TARGET_LOCATION_CASTER_SRC)
                        checkValidAttackTarget = false;
                }
                if (checkValidAttackTarget && !m_casterUnit->IsValidAttackTarget(_target))
                    return SPELL_FAILED_BAD_TARGETS;
            }
        }
        // cooldown
        if (!m_caster->IsSpellReady(*m_spellInfo))
            return SPELL_FAILED_NOT_READY;
    }

    return CheckCast(true);
}

SpellCastResult Spell::CheckCasterAuras(int32* param1) const
SpellCastResult Spell::CheckCasterAuras() const
{
    Unit* unitCaster = (m_originalCaster ? m_originalCaster : m_caster->ToUnit());
    if (!unitCaster)
    if (!m_casterUnit)
        return SPELL_CAST_OK;

    // Flag drop spells totally immuned to caster auras
    // FIXME: find more nice check for all totally immuned spells
    // AttributesEx3 & 0x10000000?
    if (m_spellInfo->Id == 23336 ||                         // Alliance Flag Drop
            m_spellInfo->Id == 23334)                           // Horde Flag Drop
        return SPELL_CAST_OK;

    // SPELL_ATTR5_USABLE_WHILE_STUNNED by default only MECHANIC_STUN (ie no sleep, knockout, freeze, etc.)
    bool usableWhileStunned = m_spellInfo->HasAttribute(SPELL_ATTR5_ALLOW_WHILE_STUNNED);
    uint8 school_immune = 0;
    uint32 mechanic_immune = 0;
    uint32 dispel_immune = 0;

    // SPELL_ATTR5_USABLE_WHILE_FEARED by default only fear (ie no horror)
    bool usableWhileFeared = m_spellInfo->HasAttribute(SPELL_ATTR5_ALLOW_WHILE_FLEEING);
    // Check if the spell grants school or mechanic immunity.
    // We use bitmasks so the loop is done only once and not on every aura check below.
    if (m_spellInfo->AttributesEx & SPELL_ATTR_EX_DISPEL_AURAS_ON_IMMUNITY)
    {
        for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
        {
            if (m_spellInfo->EffectApplyAuraName[i] == SPELL_AURA_SCHOOL_IMMUNITY)
                school_immune |= uint32(m_spellInfo->EffectMiscValue[i]);
            else if (m_spellInfo->EffectApplyAuraName[i] == SPELL_AURA_MECHANIC_IMMUNITY)
                mechanic_immune |= 1 << uint32(m_spellInfo->EffectMiscValue[i] - 1);
            else if (m_spellInfo->EffectApplyAuraName[i] == SPELL_AURA_MECHANIC_IMMUNITY_MASK)
                mechanic_immune |= uint32(m_spellInfo->EffectMiscValue[i]);
            else if (m_spellInfo->EffectApplyAuraName[i] == SPELL_AURA_DISPEL_IMMUNITY)
                dispel_immune |= GetDispellMask(DispelType(m_spellInfo->EffectMiscValue[i]));
        }
    }

    // Check whether the cast should be prevented by any state you might have.
    SpellCastResult prevented_reason = SPELL_CAST_OK;
    // Have to check if there is a stun aura. Otherwise will have problems with ghost aura apply while logging out
    uint32 unitflag = m_casterUnit->GetUInt32Value(UNIT_FIELD_FLAGS);     // Get unit state
    if ((unitflag & UNIT_FLAG_STUNNED) && !(mechanic_immune & (1 << (MECHANIC_STUN - 1u))) && 
        (!m_casttime || (m_spellInfo->InterruptFlags & SPELL_INTERRUPT_FLAG_STUN)))
        prevented_reason = SPELL_FAILED_STUNNED;
    else if ((unitflag & UNIT_FLAG_CONFUSED) && !(mechanic_immune & CONFUSED_MECHANIC_MASK))
        prevented_reason = SPELL_FAILED_CONFUSED;
    else if ((unitflag & UNIT_FLAG_FLEEING) && !(mechanic_immune & (1 << (MECHANIC_FEAR - 1u))))
        prevented_reason = SPELL_FAILED_FLEEING;
    else if (m_spellInfo->PreventionType == SPELL_PREVENTION_TYPE_SILENCE &&
            ((unitflag & UNIT_FLAG_SILENCED) ||
                m_casterUnit->CheckLockout(m_spellInfo->GetSpellSchoolMask()))) // Nostalrius : fix counterspell for mobs.
        prevented_reason = SPELL_FAILED_SILENCED;
    else if ((unitflag & UNIT_FLAG_PACIFIED) && m_spellInfo->PreventionType == SPELL_PREVENTION_TYPE_PACIFY)
        prevented_reason = SPELL_FAILED_PACIFIED;

    // Get unit state
    uint32 const unitflag = unitCaster->m_unitData->Flags;

    // this check should only be done when player does cast directly
    // (ie not when it's called from a script) Breaks for example PlayerAI when charmed
    /*
    if (!unitCaster->GetCharmerGUID().IsEmpty())
    // Attr must make flag drop spell totally immune from all effects
    if (prevented_reason != SPELL_CAST_OK)
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
            uint64 const mechanicMask = aurEff->GetSpellInfo()->GetAllEffectsMechanicMask();
            if (mechanicMask && !(mechanicMask & GetSpellInfo()->GetAllowedMechanicMask()))
            {
                foundNotMechanic = true;
        if (school_immune || mechanic_immune || dispel_immune)
        {
            {
                case SPELL_AURA_MOD_STUN:
                case SPELL_AURA_MOD_STUN_DISABLE_GRAVITY:
            //Checking auras is needed now, because you are prevented by some state but the spell grants immunity.
            auto const& auras = m_casterUnit->GetSpellAuraHolderMap();
            for (const auto& itr : auras)
            {
                SpellAuraHolder* holder = itr.second;
                SpellEntry const* pEntry = holder->GetSpellProto();

                if ((pEntry->GetSpellSchoolMask() & school_immune) && !(pEntry->AttributesEx & SPELL_ATTR_EX_UNAFFECTED_BY_SCHOOL_IMMUNE))
                    continue;
                if ((1 << (pEntry->Dispel)) & dispel_immune)
                    continue;

                for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
                {
                    *param1 = aurEff->GetSpellEffectInfo().Mechanic;
                    if (!*param1)
                        *param1 = aurEff->GetSpellInfo()->Mechanic;
                }
                    Aura* aura = holder->GetAuraByEffectIndex(SpellEffectIndex(i));
                    if (!aura)
                        continue;

                break;
            }
        }

        if (foundNotMechanic)
        {
            switch (type)
            {
                case SPELL_AURA_MOD_STUN:
                case SPELL_AURA_MOD_STUN_DISABLE_GRAVITY:
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
            else
            {
                mechanicResult = mechanicCheck(SPELL_AURA_MOD_STUN_DISABLE_GRAVITY);
                if (mechanicResult != SPELL_CAST_OK)
                    result = mechanicResult;
            }
        }
        else if (!CheckSpellCancelsStun(param1))
            result = SPELL_FAILED_STUNNED;
        else if ((m_spellInfo->Mechanic & MECHANIC_IMMUNE_SHIELD) && m_caster->ToUnit() && m_caster->ToUnit()->HasAuraWithMechanic(1 << MECHANIC_BANISH))
            result = SPELL_FAILED_STUNNED;
    }
    else if (unitflag & UNIT_FLAG_SILENCED && m_spellInfo->PreventionType & SPELL_PREVENTION_TYPE_SILENCE && !CheckSpellCancelsSilence(param1))
        result = SPELL_FAILED_SILENCED;
    else if (unitflag & UNIT_FLAG_PACIFIED && m_spellInfo->PreventionType & SPELL_PREVENTION_TYPE_PACIFY && !CheckSpellCancelsPacify(param1))
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
    else if (unitCaster->HasUnitFlag2(UNIT_FLAG2_NO_ACTIONS) && m_spellInfo->PreventionType & SPELL_PREVENTION_TYPE_NO_ACTIONS && !CheckSpellCancelsNoActions(param1))
        result = SPELL_FAILED_NO_ACTIONS;
                    if (pEntry->GetSpellMechanicMask(1 << i) & mechanic_immune)
                        continue;
                    // Make a second check for spell failed so the right SPELL_FAILED message is returned.
                    // That is needed when your casting is prevented by multiple states and you are only immune to some of them.
                    switch (aura->GetModifier()->m_auraname)
                    {
                        
                        case SPELL_AURA_MOD_STUN:
                            if (!(mechanic_immune & (1 << (MECHANIC_STUN - 1u))))
                                return SPELL_FAILED_STUNNED;
                            break;
                        case SPELL_AURA_MOD_CONFUSE:
                            if (!(mechanic_immune & CONFUSED_MECHANIC_MASK))
                                return SPELL_FAILED_CONFUSED;
                            break;
                        case SPELL_AURA_MOD_FEAR:
                            if (!(mechanic_immune & (1 << (MECHANIC_FEAR - 1u))))
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
                        default:
                            break;
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
    if (!m_casterUnit)
        return false;

    ObjectGuid targetguid = target->GetObjectGuid();

    // Nostalrius - par exemple roder ne doit pas se declencher si on envoie le pet attaquer.
    // Sinon le pet revient a cause de cet attribut :
    if (m_spellInfo->Attributes & SPELL_ATTR_STOP_ATTACK_TARGET && m_casterUnit->GetVictim())
        return false;

bool Spell::CheckSpellCancelsAuraEffect(AuraType auraType, int32* param1) const
{
    Unit* unitCaster = (m_originalCaster ? m_originalCaster : m_caster->ToUnit());
    if (!unitCaster)
        return false;

    // Checking auras is needed now, because you are prevented by some state but the spell grants immunity.
    Unit::AuraEffectList const& auraEffects = unitCaster->GetAuraEffectsByType(auraType);
    if (auraEffects.empty())
        return true;
    // 2947 - Fire Shield, rank 1 enUS
    // When set to auto-cast, the Imp will cast this on any party members within 30 yds if they receive a melee attack.
    if (m_spellInfo->IsFitToFamily<SPELLFAMILY_WARLOCK, CF_WARLOCK_IMP_BUFFS>() && m_spellInfo->SpellVisual == 289)
        if (!target->GetAttackerForHelper())
            return false;

    if (!m_spellInfo->HasEffect(SPELL_EFFECT_SCHOOL_DAMAGE))
    {
        for (uint8 j = 0; j < MAX_EFFECT_INDEX; ++j)
        {
            *param1 = aurEff->GetSpellEffectInfo().Mechanic;
            if (!*param1)
                *param1 = aurEff->GetSpellInfo()->Mechanic;
        }

        return false;
    }

    return true;
}

bool Spell::CheckSpellCancelsCharm(int32* param1) const
{
    return CheckSpellCancelsAuraEffect(SPELL_AURA_MOD_CHARM, param1) &&
        CheckSpellCancelsAuraEffect(SPELL_AURA_AOE_CHARM, param1) &&
        CheckSpellCancelsAuraEffect(SPELL_AURA_MOD_POSSESS, param1);
}

bool Spell::CheckSpellCancelsStun(int32* param1) const
{
    return CheckSpellCancelsAuraEffect(SPELL_AURA_MOD_STUN, param1) &&
        CheckSpellCancelsAuraEffect(SPELL_AURA_MOD_STUN_DISABLE_GRAVITY, param1);
}

bool Spell::CheckSpellCancelsSilence(int32* param1) const
{
    return CheckSpellCancelsAuraEffect(SPELL_AURA_MOD_SILENCE, param1) &&
        CheckSpellCancelsAuraEffect(SPELL_AURA_MOD_PACIFY_SILENCE, param1);
}
            if (m_spellInfo->Effect[j] == SPELL_EFFECT_APPLY_AURA)
            {
                if (m_spellInfo->StackAmount <= 1)
                {
                    if (target->HasAura(m_spellInfo->Id, SpellEffectIndex(j)))
                        return false;
                }
            }
            else if (IsAreaAuraEffect(m_spellInfo->Effect[j]))
            {
                if (target->HasAura(m_spellInfo->Id, SpellEffectIndex(j)))
                    return false;
            }
        }
    }

bool Spell::CheckSpellCancelsPacify(int32* param1) const
{
    return CheckSpellCancelsAuraEffect(SPELL_AURA_MOD_PACIFY, param1) &&
        CheckSpellCancelsAuraEffect(SPELL_AURA_MOD_PACIFY_SILENCE, param1);
}
    // Dont waste mana to heal someone already full life.
    if (m_spellInfo->IsHealSpell() && target->GetMaxHealth() == target->GetHealth())
        return false;
    SpellCastResult result = CheckPetCast(target);

bool Spell::CheckSpellCancelsFear(int32* param1) const
{
    return CheckSpellCancelsAuraEffect(SPELL_AURA_MOD_FEAR, param1);
}

bool Spell::CheckSpellCancelsConfuse(int32* param1) const
{
    return CheckSpellCancelsAuraEffect(SPELL_AURA_MOD_CONFUSE, param1);
    if (result == SPELL_CAST_OK || result == SPELL_FAILED_UNIT_NOT_INFRONT)
    {
        FillTargetMap();
        //check if among target units, our WANTED target is as well (->only self cast spells return false)
        for (const auto& ihit : m_UniqueTargetInfo)
            if (!ihit.deleted && ihit.targetGUID == targetguid)
                return true;
    }
    return false;                                           //target invalid
}

bool Spell::CheckSpellCancelsNoActions(int32* param1) const
SpellCastResult Spell::CheckRange(bool strict)
{
    Unit* target = m_targets.getUnitTarget();
    // Pour 'TARGET_UNIT_CASTER_PET', 'getUnitTarget' renvoit le caster >.<
    for (uint32 i : m_spellInfo->EffectImplicitTargetA)
        if (i == TARGET_UNIT_CASTER_PET)
            if (m_casterUnit)
                if (Pet* pPet = m_casterUnit->GetPet())
                    target = pPet;

SpellCastResult Spell::CheckArenaAndRatedBattlegroundCastRules()
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
        if (!unitCaster->CanCastSpellWhileMoving(m_spellInfo))
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

int32 Spell::CalculateDamage(SpellEffectInfo const& spellEffectInfo, Unit const* target, float* var /*= nullptr*/) const
{
    bool needRecalculateBasePoints = !(m_spellValue->CustomBasePointsMask & (1 << spellEffectInfo.EffectIndex));
    return m_caster->CalculateSpellDamage(target, spellEffectInfo, needRecalculateBasePoints ? nullptr : &m_spellValue->EffectBasePoints[spellEffectInfo.EffectIndex], var, m_castItemEntry, m_castItemLevel);
}

bool Spell::CanAutoCast(Unit* target)
{
    if (!target)
        return (CheckPetCast(target) == SPELL_CAST_OK);

    ObjectGuid targetguid = target->GetGUID();
    // special range cases
    switch (m_spellInfo->rangeIndex)
    {
        // self cast doesn't need range checking -- also for Starshards fix
        case SPELL_RANGE_IDX_SELF_ONLY:
            return SPELL_CAST_OK;
        // combat range spells are treated differently
        case SPELL_RANGE_IDX_COMBAT:
        {
            if (target)
            {
                if (target == m_caster || m_spellInfo->IsNextMeleeSwingSpell())
                    return SPELL_CAST_OK;

    // check if target already has the same or a more powerful aura
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
    {
        if (!spellEffectInfo.IsAura())
            continue;
                // Requires target forward for these spells
                if ((m_caster->GetDistance2dToCenter(target) > NO_FACING_CHECKS_DISTANCE) &&
                    !m_caster->HasInArc(target))
                    return SPELL_FAILED_UNIT_NOT_INFRONT;

                float range_mod = 1.0f;

        AuraType const& auraType = spellEffectInfo.ApplyAuraName;
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
                    if (abs(spellEffectInfo.BasePoints) <= abs((*auraIt)->GetAmount()))
                        return false;
                    break;
                case SPELL_GROUP_STACK_RULE_DEFAULT:
                default:
                    break;
            }
        }
    }
                if (m_casterUnit)
                {
                    if (Player* modOwner = m_casterUnit->GetSpellModOwner())
                    {
                        float base = ATTACK_DISTANCE;
                        range_mod += modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RANGE, base, this);
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
                // with additional 5 dist for non stricted case (some melee spells have delay in apply
                return m_caster->CanReachWithMeleeSpellAttack(target, range_mod) ? SPELL_CAST_OK : SPELL_FAILED_OUT_OF_RANGE;
            }
            break;                                          // let continue in generic way for no target
        }
    }

    // Add up to ~5 yds "give" for non strict (landing) check and leeway bonus if both units are moving
    float const range_mod = (strict ? (m_caster->IsPlayer() ? 1.25f : 0.0f) : (m_caster->IsPlayer() ? 6.25f : 2.25f)) + m_caster->GetLeewayBonusRange(target, true);

    SpellRangeEntry const* srange = sSpellRangeStore.LookupEntry(m_spellInfo->rangeIndex);
    float max_range = GetSpellMaxRange(srange);
    float min_range = GetSpellMinRange(srange);

    if (m_casterUnit)
    {
        if (Player* modOwner = m_casterUnit->GetSpellModOwner())
            modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RANGE, max_range, this);
    }

    max_range += range_mod;

    GameObject* go = m_targets.getGOTarget(); // Check range for gobjects (lock picking)
    if (go && m_caster->IsPlayer())
    {
        if (!go->IsAtInteractDistance(dynamic_cast<Player*>(m_caster), max_range)) // only player casts these
            return SPELL_FAILED_OUT_OF_RANGE;
    }

    if (target && target != m_caster)
    {
        float const dist = m_caster->GetCombatDistance(target);

        if (dist > max_range)
            return SPELL_FAILED_OUT_OF_RANGE;

        if (m_caster->GetTypeId() == TYPEID_PLAYER &&
            (((m_spellInfo->FacingCasterFlags & SPELL_FACING_FLAG_INFRONT) && !m_caster->HasInArc(static_cast<float>(M_PI), target))
                && !m_caster->ToPlayer()->IsWithinBoundaryRadius(target)))
        if (min_range && dist < min_range)
            return SPELL_FAILED_TOO_CLOSE;
        if (m_caster->IsPlayer() &&
           (m_spellInfo->Custom & SPELL_CUSTOM_FACE_TARGET) &&
           (m_caster->GetDistance2dToCenter(target) > NO_FACING_CHECKS_DISTANCE) &&
           !m_caster->HasInArc(target))
            return SPELL_FAILED_UNIT_NOT_INFRONT;
    }

    if (GameObject* goTarget = m_targets.GetGOTarget())
    {
        if (!goTarget->IsAtInteractDistance(m_caster->ToPlayer(), m_spellInfo))
            return SPELL_FAILED_OUT_OF_RANGE;
    }

    if (m_targets.HasDst() && !m_targets.HasTraj())
    // TODO verify that such spells really use bounding radius
    if (m_targets.m_targetMask == TARGET_FLAG_DEST_LOCATION && m_targets.m_destX != 0 && m_targets.m_destY != 0 && m_targets.m_destZ != 0)
    {
        if (!m_caster->IsWithinDist3d(m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ, max_range))
            return SPELL_FAILED_OUT_OF_RANGE;
        if (min_range && m_caster->IsWithinDist3d(m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ, min_range))
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
uint32 Spell::CalculatePowerCost(SpellEntry const* spellInfo, Unit* caster, Spell* spell, Item* castItem)
{
    if (!caster)
        return 0;

    // item cast not used power
    if (castItem)
        return 0;

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
    // Spell drain all exist power on cast (Only paladin lay of Hands)
    if (spellInfo->AttributesEx & SPELL_ATTR_EX_DRAIN_ALL_POWER)
    {
        // If power type - health drain all
        if (spellInfo->powerType == POWER_HEALTH)
            return caster->GetHealth();
        // Else drain all power
        if (spellInfo->powerType < MAX_POWERS)
            return caster->GetPower(Powers(spellInfo->powerType));
        sLog.outError("Spell::CalculateManaCost: Unknown power type '%d' in spell %d", spellInfo->powerType, spellInfo->Id);
        return 0;
    }

    // Base powerCost
    int32 powerCost = spellInfo->manaCost;
    // PCT cost from total amount
    if (spellInfo->ManaCostPercentage)
    {
        switch (spellInfo->powerType)
        {
            // health as power used
            case POWER_HEALTH:
                powerCost += spellInfo->ManaCostPercentage * caster->GetCreateHealth() / 100;
                break;
            case POWER_MANA:
                powerCost += spellInfo->ManaCostPercentage * caster->GetCreateMana() / 100;
                break;
            case POWER_RAGE:
            case POWER_FOCUS:
            case POWER_ENERGY:
            case POWER_HAPPINESS:
                powerCost += spellInfo->ManaCostPercentage * caster->GetMaxPower(Powers(spellInfo->powerType)) / 100;
                break;
            default:
                sLog.outError("Spell::CalculateManaCost: Unknown power type '%d' in spell %d", spellInfo->powerType, spellInfo->Id);
                return 0;
        }
    }

    if (m_spellInfo->HasAttribute(SPELL_ATTR0_USES_RANGED_SLOT) && m_caster->GetTypeId() == TYPEID_PLAYER)
        if (Item* ranged = m_caster->ToPlayer()->GetWeaponForAttack(RANGED_ATTACK, true))
            maxRange *= ranged->GetTemplate()->GetRangedModRange() * 0.01f;

    if (Player* modOwner = m_caster->GetSpellModOwner())
        modOwner->ApplySpellMod(m_spellInfo, SpellModOp::Range, maxRange, const_cast<Spell*>(this));
    SpellSchools school = GetFirstSchoolInMask(spell ? spell->m_spellSchoolMask : spellInfo->GetSpellSchoolMask());
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_6_1
    // Flat mod from caster auras by spell school
    powerCost += caster->GetInt32Value(UNIT_FIELD_POWER_COST_MODIFIER + school);
#endif
    // Shiv - costs 20 + weaponSpeed*10 energy (apply only to non-triggered spell with energy cost)
    if (spellInfo->AttributesEx4 & SPELL_ATTR_EX4_SPELL_VS_EXTEND_COST)
        powerCost += caster->GetAttackTime(OFF_ATTACK) / 100;
    // Apply cost mod by spell
    if (spell)
        if (Player* modOwner = caster->GetSpellModOwner())
            modOwner->ApplySpellMod(spellInfo->Id, SPELLMOD_COST, powerCost, spell);

    if (spellInfo->Attributes & SPELL_ATTR_LEVEL_DAMAGE_CALCULATION)
        powerCost = int32(powerCost / (1.117f * spellInfo->spellLevel / caster->GetLevel() - 0.1327f));

    return { minRange, maxRange };
    // PCT mod from user auras by school
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_6_1
    powerCost = int32(powerCost * (1.0f + caster->GetFloatValue(UNIT_FIELD_POWER_COST_MULTIPLIER + school)));
#endif
    if (powerCost < 0)
        powerCost = 0;
    return powerCost;
}

SpellCastResult Spell::CheckPower() const
{
    Unit* unitCaster = m_caster->ToUnit();
    if (!unitCaster)
        return SPELL_CAST_OK;

    // item cast not used power
    if (m_CastItem || m_IsTriggeredSpell || !m_casterUnit)
        return SPELL_CAST_OK;

    for (SpellPowerCost const& cost : m_powerCost)
    {
        // health as power used - need check health amount
            SpellCastResult failReason = CheckRuneCost();
            if (failReason != SPELL_CAST_OK)
                return failReason;
        }
        if (cost.Power == POWER_HEALTH)
        {
            if (int64(unitCaster->GetHealth()) <= cost.Amount)
                return SPELL_FAILED_CASTER_AURASTATE;
            continue;
        }
        // Check valid power type
        if (cost.Power >= MAX_POWERS)
        {
            TC_LOG_ERROR("spells", "Spell::CheckPower: Unknown power type '{}'", cost.Power);
            return SPELL_FAILED_UNKNOWN;
        }
    // health as power used - need check health amount
    if (m_spellInfo->powerType == POWER_HEALTH)
    {
        if (m_casterUnit->GetHealth() <= m_powerCost)
            return SPELL_FAILED_CASTER_AURASTATE;
        return SPELL_CAST_OK;
    }

    // Check valid power type
    if (m_spellInfo->powerType >= MAX_POWERS)
    {
        sLog.outError("Spell::CheckMana: Unknown power type '%d'", m_spellInfo->powerType);
        return SPELL_FAILED_DONT_REPORT;
    }

    // Allow creatures to cast spells that require a power type they don't have.
    if (m_casterUnit->IsCreature() && !m_casterUnit->IsPet() &&
       ((m_spellInfo->powerType == POWER_MANA && !m_casterUnit->GetCreateMana()) || // creature without mana (unit class warrior)
       (m_spellInfo->powerType != POWER_MANA))) // power that normal creatures can't have 
        return SPELL_CAST_OK;

        // Check power amount
        if (int32(unitCaster->GetPower(cost.Power)) < cost.Amount)
            return SPELL_FAILED_NO_POWER;
    }
    // Check power amount
    Powers powerType = Powers(m_spellInfo->powerType);
    if (m_casterUnit->GetPower(powerType) < m_powerCost)
        return SPELL_FAILED_NO_POWER;

    return SPELL_CAST_OK;
}

SpellCastResult Spell::CheckItems(int32* param1 /*= nullptr*/, int32* param2 /*= nullptr*/) const
{
    Player* player = m_caster->ToPlayer();
    if (!player)
        return SPELL_CAST_OK;
bool Spell::IgnoreItemRequirements() const
{
    if (m_IsTriggeredSpell)
    {
        /// Not own traded item (in trader trade slot) req. reagents including triggered spell case
        if (Item* targetItem = m_targets.getItemTarget())
            if (targetItem->GetOwnerGuid() != m_caster->GetObjectGuid())
                return false;

        /// Some triggered spells have same reagents that have master spell
        /// expected in test: master spell have reagents in first slot then triggered don't must use own
        return !(m_triggeredBySpellInfo && !m_triggeredBySpellInfo->Reagent[0]);
    }

    return false;
}

SpellCastResult Spell::CheckItems()
{
    // Check creature casts again here, even though they are checked in CreatureAI
    // Need to do this for some melee attacks which are channeled, and then triggered
    // eg. 13736
    if (Creature* creature = m_caster->ToCreature())
    {
        // If the unit is disarmed and the skill requires a weapon, it cannot be cast
        if (creature->HasWeapon() && !creature->CanUseEquippedWeapon(BASE_ATTACK))
        {
            for (uint32 i : m_spellInfo->Effect)
            {
                if (i == SPELL_EFFECT_WEAPON_DAMAGE || i == SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL)
                    return SPELL_FAILED_EQUIPPED_ITEM;
            }
        }
    }

    if (!m_caster->IsPlayer())
        return SPELL_CAST_OK;

    Player* p_caster = (Player*)m_caster;

    // cast item checks
    if (m_CastItem)
    {
        if (m_CastItem->IsInTrade())
            return SPELL_FAILED_ITEM_GONE;

        uint32 itemid = m_CastItem->GetEntry();
        if (!p_caster->HasItemCount(itemid, 1))
            return SPELL_FAILED_ITEM_NOT_READY;

        ItemPrototype const* proto = m_CastItem->GetProto();
        if (!proto)
            return SPELL_FAILED_ITEM_NOT_READY;

        for (int i = 0; i < 5; ++i)
            if (proto->Spells[i].SpellCharges)
                if (m_CastItem->GetSpellCharges(i) == 0)
                    return SPELL_FAILED_NO_CHARGES_REMAIN;

        // World of Warcraft Client Patch 1.11.0 (2006-06-20)
        // - Rejuvenation Potions: Any type of potion or consumable that grants 
        //   mana and healing will no longer be consumable unless either your
        //   health or your mana are below maximum.
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_10_2
        // consumable cast item checks
        if (proto->Class == ITEM_CLASS_CONSUMABLE && m_targets.getUnitTarget())
        {
            // such items should only fail if there is no suitable effect at all - see Rejuvenation Potions for example
            SpellCastResult failReason = SPELL_CAST_OK;
            for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
            for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
            {
                // skip check, pet not required like checks, and for TARGET_UNIT_PET m_targets.GetUnitTarget() is not the real target but the caster
                if (spellEffectInfo.TargetA.GetTarget() == TARGET_UNIT_PET)
                // skip check, pet not required like checks, and for TARGET_UNIT_CASTER_PET m_targets.getUnitTarget() is not the real target but the caster
                if (m_spellInfo->EffectImplicitTargetA[i] == TARGET_UNIT_CASTER_PET)
                    continue;

                if (spellEffectInfo.IsEffect(SPELL_EFFECT_HEAL))
                if (m_spellInfo->Effect[i] == SPELL_EFFECT_HEAL)
                {
                    if (m_targets.getUnitTarget()->GetHealth() == m_targets.getUnitTarget()->GetMaxHealth())
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
                if (spellEffectInfo.IsEffect(SPELL_EFFECT_ENERGIZE))
                if (m_spellInfo->Effect[i] == SPELL_EFFECT_ENERGIZE)
                {
                    if (spellEffectInfo.MiscValue < 0 || spellEffectInfo.MiscValue >= int8(MAX_POWERS))
                    if (m_spellInfo->EffectMiscValue[i] < 0 || m_spellInfo->EffectMiscValue[i] >= MAX_POWERS)
                    {
                        failReason = SPELL_FAILED_ALREADY_AT_FULL_POWER;
                        continue;
                    }

                    Powers power = Powers(spellEffectInfo.MiscValue);
                    if (m_targets.GetUnitTarget()->GetPower(power) == m_targets.GetUnitTarget()->GetMaxPower(power))
                    Powers power = Powers(m_spellInfo->EffectMiscValue[i]);
                    if (m_targets.getUnitTarget()->GetPower(power) == m_targets.getUnitTarget()->GetMaxPower(power))
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
#endif
    }

    // check target item (for triggered case not report error)
    if (m_targets.getItemTargetGuid())
    {
        if (!m_caster->IsPlayer())
            return m_IsTriggeredSpell && !(m_targets.m_targetMask & TARGET_FLAG_TRADE_ITEM)
                   ? SPELL_FAILED_DONT_REPORT : SPELL_FAILED_BAD_TARGETS;

        if (!m_targets.getItemTarget())
            return m_IsTriggeredSpell  && !(m_targets.m_targetMask & TARGET_FLAG_TRADE_ITEM)
                   ? SPELL_FAILED_DONT_REPORT : SPELL_FAILED_ITEM_GONE;

        if (!m_targets.getItemTarget()->IsFitToSpellRequirements(m_spellInfo))
            return m_IsTriggeredSpell  && !(m_targets.m_targetMask & TARGET_FLAG_TRADE_ITEM)
                   ? SPELL_FAILED_DONT_REPORT : SPELL_FAILED_EQUIPPED_ITEM_CLASS;
    }
    // if not item target then required item must be equipped (for triggered case not report error)
    else if (Player* pPlayer = m_caster->ToPlayer())
    {
        Item const* ignore = nullptr;
        if (m_attackType == BASE_ATTACK)
            ignore = pPlayer->GetWeaponForAttack(OFF_ATTACK);
        else if (m_attackType == OFF_ATTACK)
            ignore = pPlayer->GetWeaponForAttack(BASE_ATTACK);

        if (!pPlayer->HasItemFitToSpellReqirements(m_spellInfo, ignore))
        {
            return m_IsTriggeredSpell ? SPELL_FAILED_DONT_REPORT : SPELL_FAILED_EQUIPPED_ITEM_CLASS;
        }
    }

    // do not take reagents for these item casts
    if (!(m_CastItem && m_CastItem->GetTemplate()->HasFlag(ITEM_FLAG_NO_REAGENT_COST)))
    // check spell focus object
    if (m_spellInfo->RequiresSpellFocus)
    {
        bool checkReagents = !(_triggeredCastFlags & TRIGGERED_IGNORE_POWER_AND_REAGENT_COST) && !player->CanNoReagentCast(m_spellInfo);
        // Not own traded item (in trader trade slot) requires reagents even if triggered spell
        if (!checkReagents)
            if (Item* targetItem = m_targets.GetItemTarget())
                if (targetItem->GetOwnerGUID() != player->GetGUID())
                    checkReagents = true;
        float const MAX_GAMEOBJECT_FOCUS_DISTANCE = 10.0f; // Max in DB is actually 7
        GameObject* ok = nullptr;
        MaNGOS::GameObjectFocusCheck go_check(m_caster, m_spellInfo->RequiresSpellFocus);
        MaNGOS::GameObjectSearcher<MaNGOS::GameObjectFocusCheck> checker(ok, go_check);
        Cell::VisitGridObjects(m_caster, checker, MAX_GAMEOBJECT_FOCUS_DISTANCE);

        if (!ok)
            return SPELL_FAILED_REQUIRES_SPELL_FOCUS;

        focusObject = ok;                                   // game object found in range
    }

    // check reagents (ignore triggered spells with reagents processed by original spell) and special reagent ignore case.
    if (!IgnoreItemRequirements())
    {
        for (uint32 i = 0; i < MAX_SPELL_REAGENTS; ++i)
        {
            if (m_spellInfo->Reagent[i] <= 0)
                continue;

            uint32 itemid    = m_spellInfo->Reagent[i];
            uint32 itemcount = m_spellInfo->ReagentCount[i];

            // if CastItem is also spell reagent
            if (m_CastItem && m_CastItem->GetEntry() == itemid)
            {
                ItemPrototype const* proto = m_CastItem->GetProto();
                if (!proto)
                    return SPELL_FAILED_ITEM_NOT_READY;
                for (int s = 0; s < MAX_ITEM_PROTO_SPELLS; ++s)
                {
                    // CastItem will be used up and does not count as reagent
                    int32 charges = m_CastItem->GetSpellCharges(s);
                    if (proto->Spells[s].SpellCharges < 0 && abs(charges) < 2 && itemcount > 1)
                    {
                        ++itemcount;
                        break;
                    }
                }
            }

            for (SpellReagentsCurrencyEntry const* reagentsCurrency : m_spellInfo->ReagentsCurrency)
            {
                if (!player->HasCurrency(reagentsCurrency->CurrencyTypesID, reagentsCurrency->CurrencyCount))
                {
                    if (param1)
                        *param1 = -1;

                    if (param2)
                        *param2 = reagentsCurrency->CurrencyTypesID;

                    return SPELL_FAILED_REAGENTS;
                }
            }

            if (!p_caster->HasItemCount(itemid, itemcount))
                return SPELL_FAILED_ITEM_NOT_READY;
        }

        // check totem-item requirements (items presence in inventory)
        uint32 totems = MAX_SPELL_TOTEMS;
        for (uint32 i : m_spellInfo->Totem)
        {
            if (i != 0)
            {
                if (p_caster->HasItemCount(i, 1))
                {
                    totems -= 1;
                    continue;
                }
            }
            else
                totems -= 1;
        }

        if (totems != 0)
            return SPELL_FAILED_ITEM_GONE;                      //[-ZERO] not sure of it
    }

    switch (m_spellInfo->Id)
    {
        case  6201:                                 // Healthstone creating spells
        case  6202:
        case  5699:
        case 11729:
        case 11730:
        {
            if (!p_caster)
                break;
            uint32 rank = 0;
            uint32 itemtype;
            Unit::AuraList const& mDummyAuras = p_caster->GetAurasByType(SPELL_AURA_DUMMY);
            for (const auto aura : mDummyAuras)
            {
                if (aura->GetId() == 18692)
                {
                    rank = 1;
                    break;
                }
                else if (aura->GetId() == 18693)
                {
                    rank = 2;
                    break;
                }
            }

    // special checks for spell effects
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
    {
        switch (spellEffectInfo.Effect)
        {
            case SPELL_EFFECT_CREATE_ITEM:
            case SPELL_EFFECT_CREATE_LOOT:
            {
                // m_targets.GetUnitTarget() means explicit cast, otherwise we dont check for possible equip error
                Unit* target = m_targets.GetUnitTarget() ? m_targets.GetUnitTarget() : player;
                if (target->GetTypeId() == TYPEID_PLAYER && !IsTriggered())
                {
                    // SPELL_EFFECT_CREATE_ITEM_2 differs from SPELL_EFFECT_CREATE_ITEM in that it picks the random item to create from a pool of potential items,
                    // so we need to make sure there is at least one free space in the player's inventory
                    if (spellEffectInfo.Effect == SPELL_EFFECT_CREATE_LOOT)
                        if (target->ToPlayer()->GetFreeInventorySpace() == 0)
                        {
                            player->SendEquipError(EQUIP_ERR_INV_FULL, nullptr, nullptr, spellEffectInfo.ItemType);
                            return SPELL_FAILED_DONT_REPORT;
                        }

                    if (spellEffectInfo.ItemType)
                    {
                        ItemTemplate const* itemTemplate = sObjectMgr->GetItemTemplate(spellEffectInfo.ItemType);
                        if (!itemTemplate)
                            return SPELL_FAILED_ITEM_NOT_FOUND;

                        uint32 createCount = std::clamp<uint32>(spellEffectInfo.CalcValue(), 1u, itemTemplate->GetMaxStackSize());
                        ItemPosCountVec dest;
                        InventoryResult msg = target->ToPlayer()->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, spellEffectInfo.ItemType, createCount);
                        if (msg != EQUIP_ERR_OK)
                        {
                            /// @todo Needs review
                            if (!itemTemplate->GetItemLimitCategory())
                            {
                                player->SendEquipError(msg, nullptr, nullptr, spellEffectInfo.ItemType);
                                return SPELL_FAILED_DONT_REPORT;
                            }
                            else
                            {
                                // Conjure Food/Water/Refreshment spells
                                if (m_spellInfo->SpellFamilyName != SPELLFAMILY_MAGE || (!(m_spellInfo->SpellFamilyFlags[0] & 0x40000000)))
                                    return SPELL_FAILED_TOO_MANY_OF_ITEM;
                                else if (!(target->ToPlayer()->HasItemCount(spellEffectInfo.ItemType)))
                                {
                                    player->SendEquipError(msg, nullptr, nullptr, spellEffectInfo.ItemType);
                                    return SPELL_FAILED_DONT_REPORT;
                                }
                                else if (m_spellInfo->GetEffects().size() > EFFECT_1)
                                    player->CastSpell(player, m_spellInfo->GetEffect(EFFECT_1).CalcValue(), CastSpellExtraArgs()
                                        .SetTriggeringSpell(this));        // move this to anywhere
                                return SPELL_FAILED_DONT_REPORT;
                            }
                        }
                    }
                }
                break;
            }
            case SPELL_EFFECT_ENCHANT_ITEM:
                if (spellEffectInfo.ItemType && m_targets.GetItemTarget()
                    && (m_targets.GetItemTarget()->IsVellum()))
                {
                    // cannot enchant vellum for other player
                    if (m_targets.GetItemTarget()->GetOwner() != player)
                        return SPELL_FAILED_NOT_TRADEABLE;
                    // do not allow to enchant vellum from scroll made by vellum-prevent exploit
                    if (m_CastItem && m_CastItem->GetTemplate()->HasFlag(ITEM_FLAG_NO_REAGENT_COST))
                        return SPELL_FAILED_TOTEM_CATEGORY;
                    ItemPosCountVec dest;
                    InventoryResult msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, spellEffectInfo.ItemType, 1);
                    if (msg != EQUIP_ERR_OK)
                    {
                        player->SendEquipError(msg, nullptr, nullptr, spellEffectInfo.ItemType);
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
                if (targetItem->GetItemLevel(targetItem->GetOwner()) < m_spellInfo->BaseLevel || (targetItem->GetRequiredLevel() && uint32(targetItem->GetRequiredLevel()) < m_spellInfo->BaseLevel))
                    return SPELL_FAILED_LOWLEVEL;
            static uint32 const itypes[5][3] =
            {
                { 5512, 19004, 19005},              // Minor Healthstone
                { 5511, 19006, 19007},              // Lesser Healthstone
                { 5509, 19008, 19009},              // Healthstone
                { 5510, 19010, 19011},              // Greater Healthstone
                { 9421, 19012, 19013},              // Major Healthstone
            };

            switch (m_spellInfo->Id)
            {
                case  6201:
                    itemtype = itypes[0][rank];
                    break; // Minor Healthstone
                case  6202:
                    itemtype = itypes[1][rank];
                    break; // Lesser Healthstone
                case  5699:
                    itemtype = itypes[2][rank];
                    break; // Healthstone
                case 11729:
                    itemtype = itypes[3][rank];
                    break; // Greater Healthstone
                case 11730:
                    itemtype = itypes[4][rank];
                    break; // Major Healthstone
            }

            ItemPosCountVec dest;
            InventoryResult msg = p_caster->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemtype, 1);
            if (msg != EQUIP_ERR_OK)
            {
                p_caster->SendEquipError(msg, nullptr, nullptr, itemtype);
                return SPELL_FAILED_DONT_REPORT;
            }
        }
    }
    for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
    {
        switch (m_spellInfo->Effect[i])
        {
            case SPELL_EFFECT_CREATE_ITEM:
            {
                if (!m_IsTriggeredSpell && i == EFFECT_INDEX_0)
                {
                    if (Unit* target = m_targets.getUnitTarget())
                    {
                        if (!target->IsPlayer())
                            return SPELL_FAILED_BAD_TARGETS;

                        uint32 count = std::max(1, dither(CalculateDamage(SpellEffectIndex(i), target)));
                        ItemPosCountVec dest;
                        uint32 no_space = 0;
                        InventoryResult msg = static_cast<Player*>(target)->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, m_spellInfo->EffectItemType[i], count, &no_space);
                        if (msg != EQUIP_ERR_OK)
                        {
                            static_cast<Player*>(target)->SendEquipError(msg, nullptr, nullptr, m_spellInfo->EffectItemType[i]);
                            return SPELL_FAILED_DONT_REPORT;
                        }
                    }
                }

                bool isItemUsable = false;
                for (ItemEffectEntry const* itemEffect : targetItem->GetEffects())
                {
                    if (itemEffect->SpellID && itemEffect->TriggerType == ITEM_SPELLTRIGGER_ON_USE)
                    {
                        isItemUsable = true;
                        break;
                    }
                }

                SpellItemEnchantmentEntry const* enchantEntry = sSpellItemEnchantmentStore.LookupEntry(spellEffectInfo.MiscValue);
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
                                    if (targetItem->GetSocketColor(socket))
                                        ++numSockets;

                                if (numSockets == MAX_ITEM_PROTO_SOCKETS || targetItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT))
                                    return SPELL_FAILED_MAX_SOCKETS;
                                break;
                            }
                        }
                    }
                }
                break;
            }
            case SPELL_EFFECT_ENCHANT_ITEM:
            {
                Item* targetItem = m_targets.getItemTarget();
                if (!targetItem)
                    return SPELL_FAILED_ITEM_GONE;

                if (targetItem->GetProto()->ItemLevel < m_spellInfo->baseLevel)
                    return SPELL_FAILED_LOWLEVEL;
                // Not allow enchant in trade slot for some enchant type
                if (targetItem->GetOwner() != player)
                {
                    uint32 enchant_id = m_spellInfo->EffectMiscValue[i];
                    SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
                    if (!pEnchant)
                        return SPELL_FAILED_ERROR;
                    if (enchantEntry->GetFlags().HasFlag(SpellItemEnchantmentFlags::Soulbound))
                    if (pEnchant->slot & ENCHANTMENT_CAN_SOULBOUND)
                        return SPELL_FAILED_NOT_TRADEABLE;
                }
                break;
            }
            case SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY:
            {
                Item *item = m_targets.getItemTarget();
                if (!item)
                    return SPELL_FAILED_ITEM_GONE;
                // Not allow enchant in trade slot for some enchant type
                if (item->GetOwner() != player)
                {
                    uint32 enchant_id = spellEffectInfo.MiscValue;
                    SpellItemEnchantmentEntry const* enchantEntry = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
                    if (!enchantEntry)
                    uint32 enchant_id = m_spellInfo->EffectMiscValue[i];
                    SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
                    if (!pEnchant)
                        return SPELL_FAILED_ERROR;
                    if (enchantEntry->GetFlags().HasFlag(SpellItemEnchantmentFlags::Soulbound))
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
                Item const* item = m_targets.GetItemTarget();
                if (!item)
                    return SPELL_FAILED_CANT_BE_SALVAGED;
                if (!m_targets.getItemTarget() || m_targets.getItemTarget()->HasGeneratedLoot())
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;

                // prevent disenchanting in trade slot
                if (item->GetOwnerGUID() != player->GetGUID())
                    return SPELL_FAILED_CANT_BE_SALVAGED;
                if (m_targets.getItemTarget()->GetOwnerGuid() != m_caster->GetObjectGuid())
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;

                ItemPrototype const* itemProto = m_targets.getItemTarget()->GetProto();
                if (!itemProto)
                    return SPELL_FAILED_CANT_BE_SALVAGED;

                ItemDisenchantLootEntry const* itemDisenchantLoot = item->GetDisenchantLoot(m_caster->ToPlayer());
                if (!itemDisenchantLoot)
                    return SPELL_FAILED_CANT_BE_SALVAGED;
                if (itemDisenchantLoot->SkillRequired > player->GetSkillValue(SKILL_ENCHANTING))
                    return SPELL_FAILED_CANT_BE_SALVAGED_SKILL;
                break;
            }
            case SPELL_EFFECT_PROSPECTING:
            {
                Item* item = m_targets.GetItemTarget();
                if (!item)
                    return SPELL_FAILED_CANT_BE_PROSPECTED;
                //ensure item is a prospectable ore
                if (!item->GetTemplate()->HasFlag(ITEM_FLAG_IS_PROSPECTABLE))
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
                // must have disenchant loot (other static req. checked at item prototype loading)
                if (!itemProto->DisenchantID || (itemProto->Flags & ITEM_FLAG_NO_DISENCHANT))
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;

                break;
            }
            case SPELL_EFFECT_WEAPON_DAMAGE:
            case SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL:
            {
                if (!m_caster->IsPlayer()) return SPELL_FAILED_TARGET_NOT_PLAYER;
                if (m_attackType != RANGED_ATTACK)
                    break;

                Item* item = player->GetWeaponForAttack(m_attackType);
                if (!item || item->IsBroken())
                Item *pItem = ((Player*)m_caster)->GetWeaponForAttack(m_attackType, true, false);
                if (!pItem)
                    return SPELL_FAILED_EQUIPPED_ITEM;

                switch (item->GetTemplate()->GetSubClass())
                switch (pItem->GetProto()->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_THROWN:
                    {
                        uint32 const ammo = item->GetEntry();
                        if (!player->HasItemCount(ammo))
                        uint32 ammo = pItem->GetEntry();
                        if (!((Player*)m_caster)->HasItemCount(ammo, 1))
                            return SPELL_FAILED_NO_AMMO;
                    };
                    break;
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
            case SPELL_EFFECT_RECHARGE_ITEM:
            {
                 uint32 itemId = spellEffectInfo.ItemType;
                    {
                        uint32 ammo = ((Player*)m_caster)->GetUInt32Value(PLAYER_AMMO_ID);
                        if (!ammo)
                            return SPELL_FAILED_NO_AMMO;

                        ItemPrototype const* ammoProto = ObjectMgr::GetItemPrototype(ammo);
                        if (!ammoProto)
                            return SPELL_FAILED_NO_AMMO;

                            return SPELL_FAILED_NO_AMMO;
                        break;
                    }
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
            case SPELL_EFFECT_RECHARGE_ITEM:
            {
                 uint32 itemId = spellEffectInfo.ItemType;

                 ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemId);
                 if (!proto)
                     return SPELL_FAILED_ITEM_AT_MAX_CHARGES;

                 if (Item* item = player->GetItemByEntry(itemId))
                     for (ItemEffectEntry const* itemEffect : item->GetEffects())
                         if (itemEffect->LegacySlotIndex <= item->m_itemData->SpellCharges.size()
                             && itemEffect->Charges != 0
                             && item->GetSpellCharges(itemEffect->LegacySlotIndex) == itemEffect->Charges)
                             return SPELL_FAILED_ITEM_AT_MAX_CHARGES;
                 break;
            }
            case SPELL_EFFECT_RESPEC_AZERITE_EMPOWERED_ITEM:
            {
                        if (ammoProto->Class != ITEM_CLASS_PROJECTILE)
                            return SPELL_FAILED_NO_AMMO;

                if (item->GetOwnerGUID() != m_caster->GetGUID())
                    return SPELL_FAILED_DONT_REPORT;

                AzeriteEmpoweredItem const* azeriteEmpoweredItem = item->ToAzeriteEmpoweredItem();
                if (!azeriteEmpoweredItem)
                    return SPELL_FAILED_AZERITE_EMPOWERED_ONLY;

                bool hasSelections = false;
                for (int32 tier = 0; tier < MAX_AZERITE_EMPOWERED_TIER; ++tier)
                {
                    if (azeriteEmpoweredItem->GetSelectedAzeritePower(tier))
                    {
                        hasSelections = true;
                        break;
                    }
                }
                        // check ammo ws. weapon compatibility
                        switch (pItem->GetProto()->SubClass)
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

                if (!hasSelections)
                    return SPELL_FAILED_AZERITE_EMPOWERED_NO_CHOICES_TO_UNDO;

                if (!m_caster->ToPlayer()->HasEnoughMoney(azeriteEmpoweredItem->GetRespecCost()))
                    return SPELL_FAILED_DONT_REPORT;

                break;
            }
            default:
                break;
        }
    }

    // check weapon presence in slots for main/offhand weapons
    if (!(_triggeredCastFlags & TRIGGERED_IGNORE_EQUIPPED_ITEM_REQUIREMENT) && m_spellInfo->EquippedItemClass >= 0)
    {
        auto weaponCheck = [&](WeaponAttackType attackType) -> SpellCastResult
        {
            Item const* item = player->GetWeaponForAttack(attackType);

            // skip spell if no weapon in slot or broken
            if (!item || item->IsBroken())
                return SPELL_FAILED_EQUIPPED_ITEM_CLASS;

            // skip spell if weapon not fit to triggered spell
            if (!item->IsFitToSpellRequirements(m_spellInfo))
                return SPELL_FAILED_EQUIPPED_ITEM_CLASS;

            return SPELL_CAST_OK;
        };

        if (m_spellInfo->HasAttribute(SPELL_ATTR3_REQUIRES_MAIN_HAND_WEAPON))
        {
            SpellCastResult mainHandResult = weaponCheck(BASE_ATTACK);
            if (mainHandResult != SPELL_CAST_OK)
                return mainHandResult;
                        if (!((Player*)m_caster)->HasItemCount(ammo, 1))
                            return SPELL_FAILED_NO_AMMO;
                    };
                    break;
                    case ITEM_SUBCLASS_WEAPON_WAND:
                        break;
                    default:
                        break;
                }
                break;
            }
            default:
                break;
        }

        if (m_spellInfo->HasAttribute(SPELL_ATTR3_REQUIRES_OFF_HAND_WEAPON))
        {
            SpellCastResult offHandResult = weaponCheck(OFF_ATTACK);
            if (offHandResult != SPELL_CAST_OK)
                return offHandResult;
        }
    }
    }

    return SPELL_CAST_OK;
}

void Spell::Delayed()
{
    Unit* unitCaster = m_caster->ToUnit();
    if (!unitCaster)
    if (!m_caster || !m_caster->IsPlayer())
        return;

    if (IsDelayableNoMore())                                 // Spells may only be delayed twice
    if (m_spellState == SPELL_STATE_DELAYED)
        return;                                             // spell is active and can't be time-backed

    // spells not loosing casting time ( slam, dynamites, bombs.. )
    if (!(m_spellInfo->InterruptFlags & SPELL_INTERRUPT_FLAG_DAMAGE_PUSHBACK))
        return;

    //check pushback reduce
    int32 delaytime = 500;                                  // spellcasting delay is normally 500ms

    int32 delayReduce = 100;                                // must be initialized to 100 for percent modifiers
    if (Player* player = unitCaster->GetSpellModOwner())
        player->ApplySpellMod(m_spellInfo, SpellModOp::ResistPushback, delayReduce, this);
    delayReduce += unitCaster->GetTotalAuraModifier(SPELL_AURA_REDUCE_PUSHBACK) - 100;
    if (delayReduce >= 100)
    //check resist chance
    int32 resistChance = 100;                               //must be initialized to 100 for percent modifiers
    ((Player*)m_caster)->ApplySpellMod(m_spellInfo->Id, SPELLMOD_NOT_LOSE_CASTING_TIME, resistChance, this);
    resistChance += m_casterUnit->GetTotalAuraModifier(SPELL_AURA_RESIST_PUSHBACK) - 100;
    if (roll_chance_i(resistChance))
        return;

    int32 delaytime = GetNextDelayAtDamageMsTime();

    if (int32(m_timer) + delaytime > m_casttime)
    {
        delaytime = m_casttime - m_timer;
        m_timer = m_casttime;
    }
    else
        m_timer += delaytime;

    WorldPackets::Spells::SpellDelayed spellDelayed;
    spellDelayed.Caster = unitCaster->GetGUID();
    spellDelayed.ActualDelay = delaytime;
    DETAIL_FILTER_LOG(LOG_FILTER_SPELL_CAST, "Spell %u partially interrupted for (%d) ms at damage", m_spellInfo->Id, delaytime);

    WorldPacket data(SMSG_SPELL_DELAYED, 8 + 4);
    data << ObjectGuid(m_caster->GetObjectGuid());
    data << uint32(delaytime);

    unitCaster->SendMessageToSet(spellDelayed.Write(), true);
    if (m_caster->IsPlayer())
        ((Player*)m_caster)->SendDirectMessage(&data);
}

void Spell::DelayedChannel()
{
    Unit* unitCaster = m_caster->ToUnit();
    if (!unitCaster)
        return;

    if (m_spellState != SPELL_STATE_CASTING)
    if (!m_caster || !m_caster->IsPlayer() || getState() != SPELL_STATE_CASTING)
        return;

    if (IsDelayableNoMore())                                    // Spells may only be delayed twice
    //check resist chance
    int32 resistChance = 100;                               //must be initialized to 100 for percent modifiers
    ((Player*)m_caster)->ApplySpellMod(m_spellInfo->Id, SPELLMOD_NOT_LOSE_CASTING_TIME, resistChance, this);
    resistChance += m_casterUnit->GetTotalAuraModifier(SPELL_AURA_RESIST_PUSHBACK) - 100;
    if (roll_chance_i(resistChance))
        return;

    int32 delaytime = GetNextDelayAtDamageMsTime();

    int32 delaytime = CalculatePct(duration, 25); // channeling delay is normally 25% of its time per hit

    int32 delayReduce = 100;                                    // must be initialized to 100 for percent modifiers
    if (Player* player = unitCaster->GetSpellModOwner())
        player->ApplySpellMod(m_spellInfo, SpellModOp::ResistPushback, delayReduce, this);
    delayReduce += unitCaster->GetTotalAuraModifier(SPELL_AURA_REDUCE_PUSHBACK) - 100;
    if (delayReduce >= 100)
        return;

    AddPct(delaytime, -delayReduce);

    if (m_timer <= delaytime)
    if (int32(m_timer) < delaytime)
    {
        delaytime = m_timer;
        m_timer = 0;
    }
    else
        m_timer -= delaytime;

    for (TargetInfo const& targetInfo : m_UniqueTargetInfo)
        if (targetInfo.MissCondition == SPELL_MISS_NONE)
            if (Unit* unit = (unitCaster->GetGUID() == targetInfo.TargetGUID) ? unitCaster : ObjectAccessor::GetUnit(*unitCaster, targetInfo.TargetGUID))
                unit->DelayOwnedAuras(m_spellInfo->Id, m_originalCasterGUID, delaytime);
    DEBUG_FILTER_LOG(LOG_FILTER_SPELL_CAST, "Spell %u partially interrupted for %i ms, new duration: %u ms", m_spellInfo->Id, delaytime, m_timer);

    for (const auto& ihit : m_UniqueTargetInfo)
    {
        if (ihit.deleted)
            continue;

    // partially interrupt persistent area auras
    if (DynamicObject* dynObj = unitCaster->GetDynObject(m_spellInfo->Id))
        dynObj->Delay(delaytime);
        if (ihit.missCondition == SPELL_MISS_NONE)
        {
            if (Unit* unit = m_caster->GetObjectGuid() == ihit.targetGUID ? m_casterUnit : ObjectAccessor::GetUnit(*m_caster, ihit.targetGUID))
                unit->DelaySpellAuraHolder(m_spellInfo->Id, delaytime, m_caster->GetObjectGuid());
        }
    }

    for (uint8 j = 0; j < MAX_EFFECT_INDEX; ++j)
    {
        // partially interrupt persistent area auras
        if (DynamicObject* dynObj = m_caster->GetDynObject(m_spellInfo->Id, SpellEffectIndex(j)))
            dynObj->Delay(delaytime);
    }

    if (m_timer == 0)
        m_caster->InterruptSpell(CURRENT_CHANNELED_SPELL);
    else
        SendChannelUpdate(m_timer);
}

void Spell::UpdateOriginalCasterPointer()
{
    return GetPowerTypeCostAmount(power).has_value();
}

Optional<int32> Spell::GetPowerTypeCostAmount(Powers power) const
{
    auto itr = std::find_if(m_powerCost.cbegin(), m_powerCost.cend(), [power](SpellPowerCost const& cost)
    if (m_originalCasterGUID == m_caster->GetObjectGuid())
        m_originalCaster = m_casterUnit;
    else if (m_originalCasterGUID.IsGameObject())
    {
        return cost.Power == power;
    });

    if (itr == m_powerCost.cend())
        return { };

    return itr->Amount;
}

bool Spell::UpdatePointers()
{
    if (m_originalCasterGUID == m_caster->GetGUID())
        m_originalCaster = m_caster->ToUnit();
        GameObject* go = m_caster->IsInWorld() ? m_caster->GetMap()->GetGameObject(m_originalCasterGUID) : nullptr;
        m_originalCaster = go ? go->GetOwner() : nullptr;
    }
    else
    {
        Unit* unit = ObjectAccessor::GetUnit(*m_caster, m_originalCasterGUID);
        m_originalCaster = unit && unit->IsInWorld() ? unit : nullptr;
    }
}

void Spell::UpdatePointers()
{
    UpdateOriginalCasterPointer();

    m_targets.Update(m_caster);
}

bool Spell::CheckTargetCreatureType(Unit* target) const
{
    if (target->HasAura(8179)) // Totem de glebe absorbe tout (pour dispel le buff quand il absorbe un sort)
        return true;

    uint32 spellCreatureTargetMask = m_spellInfo->TargetCreatureType;

    // update effect destinations (in case of moved transport dest target)
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
    // Curse of Doom : not find another way to fix spell target check :/
    if (m_spellInfo->Id == 603)                             // in 1.12 "Curse of doom" have only 1 rank.
    {
        SpellDestination& dest = m_destTargets[spellEffectInfo.EffectIndex];
        if (!dest._transportGUID)
            continue;
        // not allow cast at player
        if (target->GetCharmerOrOwnerPlayerOrPlayerItself())
            return false;

        spellCreatureTargetMask = 0x7FF;
    }

    // Dismiss Pet and Taming Lesson skipped
    if (m_spellInfo->Id == 2641 || m_spellInfo->Id == 23356)
        spellCreatureTargetMask =  0;

    if (spellCreatureTargetMask)
    {
        uint32 TargetCreatureType = target->GetCreatureTypeMask();

        return !TargetCreatureType || (spellCreatureTargetMask & TargetCreatureType);
    }
    return true;
}

CurrentSpellTypes Spell::GetCurrentContainer() const
{
    if (m_spellInfo->IsNextMeleeSwingSpell())
        return (CURRENT_MELEE_SPELL);
    else if (IsAutoRepeat())
        return (CURRENT_AUTOREPEAT_SPELL);
    else if (m_channeled)
        return (CURRENT_CHANNELED_SPELL);
    else
        return (CURRENT_GENERIC_SPELL);
}

bool Spell::CheckTarget(Unit* target, SpellEffectIndex eff)
{
    return m_caster->GetMap()->GetDifficultyID();
}

bool Spell::CheckEffectTarget(Unit const* target, SpellEffectInfo const& spellEffectInfo, Position const* losPosition) const
{
    switch (spellEffectInfo.ApplyAuraName)
    {
        case SPELL_AURA_MOD_POSSESS:
        case SPELL_AURA_MOD_CHARM:
        case SPELL_AURA_MOD_POSSESS_PET:
        case SPELL_AURA_AOE_CHARM:
            if (target->GetVehicleKit() && target->GetVehicleKit()->IsControllableVehicle())
    if (m_casterUnit && target != m_casterUnit && m_spellInfo->IsPositiveSpell())
    {
        // prevent buffing low level players with group wide buffs
        if (m_casterUnit->IsPlayer() && !m_CastItem && !m_IsTriggeredSpell && target != m_targets.getUnitTarget())
        {
            if (m_spellInfo != sSpellMgr.SelectAuraRankForLevel(m_spellInfo, target->GetLevel()))
                return false;
            if (target->IsMounted())
                return false;
            if (!target->GetCharmerGUID().IsEmpty())
                return false;
            if (int32 value = CalculateDamage(spellEffectInfo, target))
                if ((int32)target->GetLevelForTarget(m_caster) > value)
                    return false;
            break;
        default:
            break;
    }
        }

    // check for ignore LOS on the effect itself
    if (m_spellInfo->HasAttribute(SPELL_ATTR2_IGNORE_LINE_OF_SIGHT) || DisableMgr::IsDisabledFor(DISABLE_TYPE_SPELL, m_spellInfo->Id, nullptr, SPELL_DISABLE_LOS))
        return true;

    // check if gameobject ignores LOS
    if (GameObject const* gobCaster = m_caster->ToGameObject())
        if (!gobCaster->GetGOInfo()->GetRequireLOS())
            return true;

    // if spell is triggered, need to check for LOS disable on the aura triggering it and inherit that behaviour
    if (!m_spellInfo->HasAttribute(SPELL_ATTR5_ALWAYS_LINE_OF_SIGHT) && IsTriggered() && m_triggeredByAuraSpell && (m_triggeredByAuraSpell->HasAttribute(SPELL_ATTR2_IGNORE_LINE_OF_SIGHT) || DisableMgr::IsDisabledFor(DISABLE_TYPE_SPELL, m_triggeredByAuraSpell->Id, nullptr, SPELL_DISABLE_LOS)))
        return true;

    /// @todo shit below shouldn't be here, but it's temporary
    //Check targets for LOS visibility
    switch (spellEffectInfo.Effect)
    {
        case SPELL_EFFECT_SKIN_PLAYER_CORPSE:
        {
            if (!m_targets.GetCorpseTargetGUID())
            {
                if (target->IsWithinLOSInMap(m_caster, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2) && target->HasUnitFlag(UNIT_FLAG_SKINNABLE))
                    return true;

                return false;
            }

            Corpse* corpse = ObjectAccessor::GetCorpse(*m_caster, m_targets.GetCorpseTargetGUID());
            if (!corpse)
                return false;

            if (target->GetGUID() != corpse->GetOwnerGUID())
                return false;

            if (!corpse->HasDynamicFlag(CORPSE_DYNFLAG_LOOTABLE))
                return false;

            if (!corpse->IsWithinLOSInMap(m_caster, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
                return false;

            break;
        }
        default:
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
        }
    }
        Player* casterOwner = m_casterUnit->GetCharmerOrOwnerPlayerOrPlayerItself();
        Player* targetOwner = target->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (targetOwner && casterOwner != targetOwner && targetOwner->duel && casterOwner && !casterOwner->IsInDuelWith(targetOwner))
            return false;
    }
    // Check targets for creature type mask and remove not appropriate (skip explicit self target case, maybe need other explicit targets)
    if (m_spellInfo->EffectImplicitTargetA[eff] != TARGET_UNIT_CASTER)
    {
        if (!CheckTargetCreatureType(target))
            return false;
    }

    return true;
}

bool Spell::CheckEffectTarget(GameObject const* target, SpellEffectInfo const& spellEffectInfo) const
{
    switch (spellEffectInfo.Effect)
    {
        case SPELL_EFFECT_GAMEOBJECT_DAMAGE:
        case SPELL_EFFECT_GAMEOBJECT_REPAIR:
        case SPELL_EFFECT_GAMEOBJECT_SET_DESTRUCTION_STATE:
            if (target->GetGoType() != GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING)
                return false;
            break;
        default:
            break;
    // Check targets for not_selectable unit flag and remove
    // A player can cast spells on his pet (or other controlled unit) though in any state
    if (target != m_caster && target->GetCharmerOrOwnerGuid() != m_caster->GetObjectGuid())
    {
        // any unattackable target skipped
        if (target->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            return false;

        // unselectable targets skipped in all cases except TARGET_UNIT_SCRIPT_NEAR_CASTER targeting
        // in case TARGET_UNIT_SCRIPT_NEAR_CASTER target selected by server always and can't be cheated
        if ((!m_IsTriggeredSpell || target != m_targets.getUnitTarget()) &&
                target->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE) &&
                m_spellInfo->EffectImplicitTargetA[eff] != TARGET_UNIT_SCRIPT_NEAR_CASTER &&
                m_spellInfo->EffectImplicitTargetB[eff] != TARGET_UNIT_SCRIPT_NEAR_CASTER &&
                m_spellInfo->EffectImplicitTargetA[eff] != TARGET_ENUM_UNITS_SCRIPT_AOE_AT_SRC_LOC &&
                m_spellInfo->EffectImplicitTargetB[eff] != TARGET_ENUM_UNITS_SCRIPT_AOE_AT_SRC_LOC &&
                m_spellInfo->EffectImplicitTargetA[eff] != TARGET_ENUM_UNITS_SCRIPT_AOE_AT_DEST_LOC &&
                m_spellInfo->EffectImplicitTargetB[eff] != TARGET_ENUM_UNITS_SCRIPT_AOE_AT_DEST_LOC &&
                m_spellInfo->EffectImplicitTargetA[eff] != TARGET_ENUM_UNITS_SCRIPT_IN_CONE_60 &&
                m_spellInfo->EffectImplicitTargetB[eff] != TARGET_ENUM_UNITS_SCRIPT_IN_CONE_60)
            return false;
    }

    return true;
}

bool Spell::CheckEffectTarget(Item const* /*target*/, SpellEffectInfo const& /*spellEffectInfo*/) const
{
    return true;
}
    // Check player targets and remove if in GM mode or GM invisibility (for not self casting case)
    if (target != m_caster && target->IsPlayer())
    {
        if (((Player*)target)->GetVisibility() == VISIBILITY_OFF)
            return false;

        if (((Player*)target)->IsGameMaster() && !m_spellInfo->IsPositiveSpell())
            return false;
    }

    // Check targets for LOS visibility (except spells without range limitations )
    switch (m_spellInfo->Effect[eff])
    {
        case SPELL_EFFECT_SUMMON_PLAYER:                    // from anywhere
            break;
        case SPELL_EFFECT_DUMMY:
            if (m_spellInfo->Id != 20577)                   // Cannibalize
                break;
        // no break. Cannibalize checks corpse target LOS.
        // fall through
        case SPELL_EFFECT_RESURRECT:
        case SPELL_EFFECT_RESURRECT_NEW:
            // player far away, maybe his corpse near?
            if (target != m_caster && !(m_spellInfo->AttributesEx2 & SPELL_ATTR_EX2_IGNORE_LOS) && !target->IsWithinLOSInMap(m_caster))
            {
                if (!m_targets.getCorpseTargetGuid())
                    return false;

bool Spell::IsFocusDisabled() const
{
    return ((_triggeredCastFlags & TRIGGERED_IGNORE_SET_FACING) || (m_spellInfo->IsChanneled() && !m_spellInfo->HasAttribute(SPELL_ATTR1_TRACK_TARGET_IN_CHANNEL)));
}

bool Spell::IsProcDisabled() const
{
    return (_triggeredCastFlags & TRIGGERED_DISALLOW_PROC_EVENTS) != 0;
}
                Corpse* corpse = m_caster->GetMap()->GetCorpse(m_targets.getCorpseTargetGuid());
                if (!corpse)
                    return false;

bool Spell::IsChannelActive() const
{
    return m_caster->IsUnit() && m_caster->ToUnit()->GetChannelSpellId() != 0;
}
                if (target->GetObjectGuid() != corpse->GetOwnerGuid())
                    return false;

                if (!(m_spellInfo->AttributesEx2 & SPELL_ATTR_EX2_IGNORE_LOS) && !corpse->IsWithinLOSInMap(m_caster))
                    return false;
            }

    if (!m_casttime && m_spellInfo->HasAttribute(SPELL_ATTR6_DOESNT_RESET_SWING_TIMER_IF_INSTANT))
        return false;
            // all ok by some way or another, skip normal check
            break;
        default:                                            // normal case
            // Get GO cast coordinates if original caster -> GO
            if (target != m_caster && !IsIgnoreLosTarget(m_spellInfo->EffectImplicitTargetA[eff]))
                if (SpellCaster* caster = GetCastingObject())
                    if (!(m_spellInfo->AttributesEx2 & SPELL_ATTR_EX2_IGNORE_LOS) && !target->IsWithinLOSInMap(caster))
                        return false;
            break;
    }

    return !(target->GetTypeId() != TYPEID_PLAYER && m_spellInfo->AttributesEx3 & SPELL_ATTR_EX3_TARGET_ONLY_PLAYER
            && m_spellInfo->EffectImplicitTargetA[eff] != TARGET_UNIT_SCRIPT_NEAR_CASTER && m_spellInfo->EffectImplicitTargetA[eff] != TARGET_UNIT_CASTER);
}

bool Spell::IsNeedSendToClient() const
{
    return !IsChannelingVisual() && m_caster->IsInWorld() && (m_spellInfo->SpellVisual != 0 || m_channeled ||
           m_spellInfo->speed > 0.0f || (!m_triggeredByAuraSpell && !m_IsTriggeredSpell));
}

bool Spell::IsTriggeredSpellWithRedundentData() const
{
    return m_triggeredByAuraSpell || m_triggeredBySpellInfo ||
           // possible not need after above check?
           (m_IsTriggeredSpell && (m_spellInfo->manaCost || m_spellInfo->ManaCostPercentage));
}

Unit* Spell::GetUnitCasterForEffectHandlers() const
bool Spell::HaveTargetsForEffect(SpellEffectIndex effect) const
{
    return m_originalCaster ? m_originalCaster : m_caster->ToUnit();
    for (const auto& itr : m_UniqueTargetInfo)
        if (!itr.deleted && itr.effectMask & (1 << effect))
            return true;

    for (const auto& itr : m_UniqueGOTargetInfo)
        if (!itr.deleted && itr.effectMask & (1 << effect))
            return true;

    for (const auto& itr : m_UniqueItemInfo)
        if (!itr.deleted && itr.effectMask & (1 << effect))
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
        TC_LOG_ERROR("spells", "~SpellEvent: {} {} tried to delete non-deletable spell {}. Was not deleted, causes memory leak.",
            (m_Spell->GetCaster()->GetTypeId() == TYPEID_PLAYER ? "Player" : "Creature"), m_Spell->GetCaster()->GetGUID().ToString(), m_Spell->m_spellInfo->Id);
        ABORT();
    }
}
    m_Spell->Delete();
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
        }
        break;

        case SPELL_STATE_CASTING:
        {
            // this spell is in channeled state, process it on the next update
            // event will be re-added automatically at the end of routine)
        } break;

        case SPELL_STATE_DELAYED:
        {
            // first, check, if we have just started
            if (m_Spell->GetDelayStart() != 0)
            {
                // no, we aren't, do the typical update
                // check, if we have channeled spell on our hands
                if (m_Spell->m_spellInfo->IsChanneledSpell())
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
                        // do the action (pass spell to channeling state)
                        try
                        {
                            m_Spell->SetExecutedCurrently(true);
                            m_Spell->handle_immediate();
                            m_Spell->SetExecutedCurrently(false);
                        }
                        catch (std::runtime_error &e)
                        {
                            sLog.outInfo("[Spell/Crash] 'handle_immediate()' [%u:%s]", m_Spell->m_spellInfo->Id, m_Spell->GetCaster()->GetName());
                            sLog.outInfo(e.what());
                            m_Spell->SetExecutedCurrently(false);
                            return false;
                        }
                    }
                    // event will be re-added automatically at the end of routine)
                }
                else
                {
                    // run the spell handler and think about what we can do next
                    uint64 t_offset = e_time - m_Spell->GetDelayStart();
                    uint64 n_offset = m_Spell->handle_delayed(t_offset);
                    if (n_offset)
                    {
                        // re-add us to the queue
                        m_Spell->GetCaster()->m_Events.AddEvent(this, Milliseconds(m_Spell->GetDelayStart() + n_offset), false);
                        return false;                       // event not complete
                    }
                    // event complete
                    // finish update event will be re-added automatically at the end of routine)
                }
            }
                    try
                    {
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
                    catch (std::runtime_error &e)
                    {
                        sLog.outInfo("[Spell/Crash] 'handle_immediate()' [%u:%s]", m_Spell->m_spellInfo->Id, m_Spell->GetCaster()->GetName());
                        sLog.outInfo(e.what());
                        return false;
                    }
                }
            }
            else
            {
                // delaying had just started, record the moment
                m_Spell->SetDelayStart(e_time);
                // re-plan the event for the delay moment
                m_Spell->GetCaster()->m_Events.AddEvent(this, Milliseconds(e_time + n_offset), false);
                return false;                               // event not complete
            }
        }
        break;

        default:
        {
            // all other states
            // event will be re-added automatically at the end of routine)
        } break;
    }

    // spell processing not complete, plan event on the next update interval
    m_Spell->GetCaster()->m_Events.AddEvent(this, Milliseconds(e_time + 1), false);
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

SpellCastResult Spell::CanOpenLock(SpellEffectIndex effIndex, uint32 lockId, SkillType& skillId, int32& reqSkillValue, int32& skillValue)
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
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
    {
        // don't do anything for empty effect
        if (!spellEffectInfo.IsEffect())
            continue;

        HandleEffects(nullptr, nullptr, nullptr, nullptr, spellEffectInfo, SPELL_EFFECT_HANDLE_LAUNCH);
    }

    PrepareTargetProcessing();

    for (TargetInfo& target : m_UniqueTargetInfo)
        PreprocessSpellLaunch(target);

    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
    {
        float multiplier = 1.0f;
        if (m_applyMultiplierMask & (1 << spellEffectInfo.EffectIndex))
            multiplier = spellEffectInfo.CalcDamageMultiplier(m_originalCaster, this);

        for (TargetInfo& target : m_UniqueTargetInfo)
        {
            uint32 mask = target.EffectMask;
            if (!(mask & (1 << spellEffectInfo.EffectIndex)))
                continue;

            DoEffectOnLaunchTarget(target, multiplier, spellEffectInfo);
        }
    }

    FinishTargetProcessing();
}

void Spell::PreprocessSpellLaunch(TargetInfo& targetInfo)
{
    Unit* targetUnit = m_caster->GetGUID() == targetInfo.TargetGUID ? m_caster->ToUnit() : ObjectAccessor::GetUnit(*m_caster, targetInfo.TargetGUID);
    if (!targetUnit)
        return;

    // This will only cause combat - the target will engage once the projectile hits (in Spell::TargetInfo::PreprocessTarget)
    if (m_originalCaster && targetInfo.MissCondition != SPELL_MISS_EVADE && !m_originalCaster->IsFriendlyTo(targetUnit) && (!m_spellInfo->IsPositive() || m_spellInfo->HasEffect(SPELL_EFFECT_DISPEL)) && (m_spellInfo->HasInitialAggro() || targetUnit->IsEngaged()))
        m_originalCaster->SetInCombatWith(targetUnit, true);

    Unit* unit = nullptr;
    // In case spell hit target, do all effect on that target
    if (targetInfo.MissCondition == SPELL_MISS_NONE)
        unit = targetUnit;
    // In case spell reflect from target, do all effect on caster (if hit)
    else if (targetInfo.MissCondition == SPELL_MISS_REFLECT && targetInfo.ReflectResult == SPELL_MISS_NONE)
        unit = m_caster->ToUnit();

    if (!unit)
        return;

    float critChance = m_spellValue->CriticalChance;
    if (m_originalCaster)
    {
        if (!critChance)
            critChance = m_originalCaster->SpellCritChanceDone(this, nullptr, m_spellSchoolMask, m_attackType);
        critChance = unit->SpellCritChanceTaken(m_originalCaster, this, nullptr, m_spellSchoolMask, critChance, m_attackType);
    }

    targetInfo.IsCrit = roll_chance_f(critChance);
}

void Spell::DoEffectOnLaunchTarget(TargetInfo& targetInfo, float multiplier, SpellEffectInfo const& spellEffectInfo)
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

    m_damage = 0;
    m_healing = 0;

    HandleEffects(unit, nullptr, nullptr, nullptr, spellEffectInfo, SPELL_EFFECT_HANDLE_LAUNCH_TARGET);

    if (m_originalCaster && m_damage > 0)
    {
        if (spellEffectInfo.IsTargetingArea() || spellEffectInfo.IsAreaAuraEffect() || spellEffectInfo.IsEffect(SPELL_EFFECT_PERSISTENT_AREA_AURA) || m_spellInfo->HasAttribute(SPELL_ATTR5_TREAT_AS_AREA_EFFECT))
        {
            m_damage = unit->CalculateAOEAvoidance(m_damage, m_spellInfo->SchoolMask, m_originalCaster->GetGUID());

            if (m_originalCaster->GetTypeId() == TYPEID_PLAYER)
            {
                // cap damage of player AOE
                int64 targetAmount = GetUnitTargetCountForEffect(spellEffectInfo.EffectIndex);
                if (targetAmount > 20)
                    m_damage = m_damage * 20 / targetAmount;
            }
        }
    }

    if (m_applyMultiplierMask & (1 << spellEffectInfo.EffectIndex))
    {
        m_damage = int32(m_damage * m_damageMultipliers[spellEffectInfo.EffectIndex]);
        m_healing = int32(m_healing * m_damageMultipliers[spellEffectInfo.EffectIndex]);

        m_damageMultipliers[spellEffectInfo.EffectIndex] *= multiplier;
    }

    targetInfo.Damage += m_damage;
    targetInfo.Healing += m_healing;
}

SpellCastResult Spell::CanOpenLock(SpellEffectInfo const& effect, uint32 lockId, SkillType& skillId, int32& reqSkillValue, int32& skillValue)
{
    if (!lockId)                                             // possible case for GO and maybe for items.
    if (!lockId)                                            // possible case for GO and maybe for items.
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
    for (int j = 0; j < 8; ++j)
    {
        switch (lockInfo->Type[j])
        {
            // check key item (many fit cases can be)
            case LOCK_KEY_ITEM:
                if (lockInfo->Index[j] && m_CastItem && m_CastItem->GetEntry() == lockInfo->Index[j])
                    return SPELL_CAST_OK;
                break;
            // check key skill (only single first fit case can be)
            case LOCK_KEY_SKILL:
            {
                // wrong locktype, skip
                if (effect.MiscValue != lockInfo->Index[j])
                if (uint32(m_spellInfo->EffectMiscValue[effIndex]) != lockInfo->Index[j])
                    continue;

                skillId = SkillByLockType(LockType(lockInfo->Index[j]));

                if ((skillId != SKILL_NONE) || (LockType(lockInfo->Index[j]) == LOCKTYPE_BLASTING))    // Ustaag <Nostalrius> : ajout pour prise en compte des charges de Seaforium (item ingenieur)
                {
                    // skill bonus provided by casting spell (mostly item spells)
                    // add the damage modifier from the spell casted (cheat lock / skeleton key etc.) (use m_currentBasePoints, CalculateDamage returns wrong value)
                    uint32 spellSkillBonus = uint32(m_currentBasePoints[effIndex]);
                    reqSkillValue = lockInfo->Skill[j];

                    // castitem check: rogue using skeleton keys. the skill values should not be added in this case.
                    skillValue = 0;
                    if (!m_CastItem && unitCaster->GetTypeId() == TYPEID_PLAYER)
                        skillValue = unitCaster->ToPlayer()->GetSkillValue(skillId);
                    else if (lockInfo->Index[j] == LOCKTYPE_LOCKPICKING)
                        skillValue = unitCaster->GetLevel() * 5;
                    skillValue = m_CastItem || !m_caster->IsPlayer() ?
                                 0 : ((Player*)m_caster)->GetSkillValue(skillId);

                    // skill bonus provided by casting spell (mostly item spells)
                    // add the effect base points modifier from the spell cast (cheat lock / skeleton key etc.)
                    if (effect.TargetA.GetTarget() == TARGET_GAMEOBJECT_ITEM_TARGET || effect.TargetB.GetTarget() == TARGET_GAMEOBJECT_ITEM_TARGET)
                        skillValue += effect.CalcValue();
                    skillValue += spellSkillBonus;

                    if (skillValue < reqSkillValue)
                        return SPELL_FAILED_LOW_CASTLEVEL;
                }

                return SPELL_CAST_OK;
            }
            case LOCK_KEY_SPELL:
                if (m_spellInfo->Id == uint32(lockInfo->Index[j]))
                    return SPELL_CAST_OK;
                reqKey = true;
                break;
        }
    }

    // No requirement met = locked.
    // Rq: Lock 85 = no requirement at all = always locked
    return SPELL_FAILED_BAD_TARGETS;
}

class SpellNotifierCreatureAndPlayer
{
public:
    Spell::UnitList *i_data;
    Spell &i_spell;
    SpellNotifyPushType i_push_type;
    float i_radius;
    SpellTargets i_TargetType;
    SpellCaster* i_originalCaster;
    SpellCaster* i_castingObject;
    bool i_playerControlled;
    float i_centerX;
    float i_centerY;

    float GetCenterX() const
    {
        case SPELLVALUE_RADIUS_MOD:
            m_spellValue->RadiusMod = (float)value / 10000;
            break;
        case SPELLVALUE_MAX_TARGETS:
            m_spellValue->MaxAffectedTargets = (uint32)value;
            break;
        case SPELLVALUE_AURA_STACK:
            m_spellValue->AuraStackAmount = uint8(value);
            break;
        case SPELLVALUE_CRIT_CHANCE:
            m_spellValue->CriticalChance = value / 100.0f; // @todo ugly /100 remove when basepoints are double
            break;
        case SPELLVALUE_DURATION_PCT:
            m_spellValue->DurationMul = float(value) / 100.0f;
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
}
        return i_centerX;
    }
    float GetCenterY() const
    {
        return i_centerY;
    }

    SpellNotifierCreatureAndPlayer(Spell &spell, Spell::UnitList &data, float radius, SpellNotifyPushType type,
                                   SpellTargets TargetType = SPELL_TARGETS_NOT_FRIENDLY, SpellCaster* originalCaster = nullptr)
        : i_data(&data), i_spell(spell), i_push_type(type), i_radius(radius), i_TargetType(TargetType),
          i_originalCaster(originalCaster), i_castingObject(i_spell.GetCastingObject())
    {
        if (!i_originalCaster)
            i_originalCaster = i_spell.GetAffectiveCasterObject();
        i_playerControlled = i_originalCaster  ? i_originalCaster->IsControlledByPlayer() : false;

void Spell::LoadScripts()
{
    sScriptMgr->CreateSpellScripts(m_spellInfo->Id, m_loadedScripts, this);
    for (auto itr = m_loadedScripts.begin(); itr != m_loadedScripts.end(); ++itr)
    {
        TC_LOG_DEBUG("spells", "Spell::LoadScripts: Script `{}` for spell `{}` is loaded now", (*itr)->_GetScriptName()->c_str(), m_spellInfo->Id);
        (*itr)->Register();
    }
}

void Spell::CallScriptOnPrecastHandler()
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_ON_PRECAST);
        (*scritr)->OnPrecast();
        (*scritr)->_FinishScriptCall();
    }
}

void Spell::CallScriptBeforeCastHandlers()
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_BEFORE_CAST);
        auto hookItrEnd = (*scritr)->BeforeCast.end(), hookItr = (*scritr)->BeforeCast.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
            (*hookItr).Call(*scritr);

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
            (*hookItr).Call(*scritr);

        (*scritr)->_FinishScriptCall();
    }
}
        switch (i_push_type)
        {
            case PUSH_IN_FRONT:
            case PUSH_IN_FRONT_90:
            case PUSH_IN_FRONT_15:
            case PUSH_IN_BACK:
            case PUSH_SELF_CENTER:
                if (i_castingObject)
                {
                    i_centerX = i_castingObject->GetPositionX();
                    i_centerY = i_castingObject->GetPositionY();
                }
                break;
            case PUSH_DEST_CENTER:
                i_centerX = i_spell.m_targets.m_destX;
                i_centerY = i_spell.m_targets.m_destY;
                break;
            case PUSH_TARGET_CENTER:
                if (Unit* target = i_spell.m_targets.getUnitTarget())
                {
                    i_centerX = target->GetPositionX();
                    i_centerY = target->GetPositionY();
                }
                break;
            default:
                sLog.outError("SpellNotifierCreatureAndPlayer: unsupported PUSH_* case %u.", i_push_type);
        }
    }

    template<class T>
    void Visit(GridRefManager<T>& m)
    {
        MANGOS_ASSERT(i_data);

        if (!i_originalCaster || !i_castingObject)
            return;

        for (typename GridRefManager<T>::iterator itr = m.begin(); itr != m.end(); ++itr)
        {
            // The template is only defined for Player and Creature maps. If it is extended
            // in the future, we should swap to WorldObject. Furthermore, we will have to
            // ensure all the checks are not using invalid casts.
            Unit* unit = itr->getSource();

            // there are still more spells which can be casted on dead, but
            // they are no AOE and don't have such a nice SPELL_ATTR flag
            if (!unit->IsInMap(i_originalCaster))
                continue;

int32 Spell::CallScriptCalcCastTimeHandlers(int32 castTime)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_CALC_CAST_TIME);
        castTime = (*scritr)->CalcCastTime(castTime);
        (*scritr)->_FinishScriptCall();
    }
    return castTime;
}
            if (i_TargetType != SPELL_TARGETS_ALL)
            {
                bool const forAttack = i_TargetType == SPELL_TARGETS_HOSTILE || i_TargetType == SPELL_TARGETS_NOT_FRIENDLY || i_TargetType == SPELL_TARGETS_AOE_DAMAGE;
                if (!unit->IsTargetable(forAttack, i_playerControlled, true, false) || !i_spell.m_spellInfo->CanTargetAliveState(unit->IsAlive()))
                    continue;
            }

bool Spell::CallScriptEffectHandlers(SpellEffIndex effIndex, SpellEffectHandleMode mode)
{
    // execute script effect handler hooks and check if effects was prevented
    bool preventDefault = false;
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_InitHit();

        HookList<SpellScript::EffectHandler>::iterator effItr, effEndItr;
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
            if (!(*scritr)->_IsEffectPrevented(effIndex) && (*effItr).IsEffectAffected(m_spellInfo, effIndex))
                (*effItr).Call(*scritr, effIndex);
            switch (i_TargetType)
            {
                case SPELL_TARGETS_HOSTILE:
                    if (!i_originalCaster->IsHostileTo(unit))
                        continue;
                    break;
                case SPELL_TARGETS_NOT_FRIENDLY:
                    if (i_originalCaster->IsFriendlyTo(unit))
                        continue;
                    break;
                case SPELL_TARGETS_NOT_HOSTILE:
                    if (i_originalCaster->IsHostileTo(unit))
                        continue;
                    break;
                case SPELL_TARGETS_FRIENDLY:
                    if (!i_originalCaster->IsFriendlyTo(unit))
                        continue;
                    break;
                case SPELL_TARGETS_AOE_DAMAGE:
                {
                    if (unit->IsCreature() && static_cast<Creature*>(unit)->IsImmuneToAoe())
                        continue;

                    if (i_originalCaster->IsFriendlyTo(unit))
                        continue;

                    Unit* casterUnit = i_originalCaster->ToUnit();
                    if (!casterUnit && i_originalCaster->ToGameObject())
                        casterUnit = i_originalCaster->ToGameObject()->GetOwner();

                    if (casterUnit)
                    {
                        if (!casterUnit->IsValidAttackTarget(unit))
                            continue;

        (*scritr)->_FinishScriptCall();
    }
}

void Spell::CallScriptBeforeHitHandlers(SpellMissInfo missInfo)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_InitHit();
        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_BEFORE_HIT);
        auto hookItrEnd = (*scritr)->BeforeHit.end(), hookItr = (*scritr)->BeforeHit.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
            (*hookItr).Call(*scritr, missInfo);

        (*scritr)->_FinishScriptCall();
    }
}
                        // Negative AoE from non flagged players cannot target other players
                        if (Player* attackedPlayer = unit->GetCharmerOrOwnerPlayerOrPlayerItself())
                            if (Player* casterPlayer = casterUnit->ToPlayer())
                                if (!casterPlayer->IsPvP() && !(casterPlayer->IsFFAPvP() && attackedPlayer->IsFFAPvP()) && !casterPlayer->IsInDuelWith(attackedPlayer))
                                    continue;
                    }
                    else if (GameObject* gobj = i_originalCaster->ToGameObject())
                    {
                        if (gobj->IsFriendlyTo(unit))
                            continue;
                    }
                }
                break;
                case SPELL_TARGETS_ALL:
                    break;
                default:
                    continue;
            }

            // we don't need to check InMap here, it's already done some lines above
            switch (i_push_type)
            {
                case PUSH_IN_FRONT:
                    if (i_castingObject->isInFront(unit, i_radius, 2 * M_PI_F / 3))
                        i_data->push_back(unit);
                    break;
                case PUSH_IN_FRONT_90:
                    if (i_castingObject->isInFront(unit, i_radius, M_PI_F / 2))
                        i_data->push_back(unit);
                    break;
                case PUSH_IN_FRONT_15:
                    if (i_castingObject->isInFront(unit, i_radius, M_PI_F / 12))
                        i_data->push_back(unit);
                    break;
                case PUSH_IN_BACK: // 75
                    if (i_castingObject->isInBack(unit, i_radius, 5 * M_PI_F / 12))
                        i_data->push_back(unit);
                    break;
                case PUSH_SELF_CENTER:
                    if (i_castingObject->IsWithinDist(unit, i_radius))
                        i_data->push_back(unit);
                    break;
                case PUSH_DEST_CENTER:
                    if (itr->getSource()->IsWithinDist3d(i_spell.m_targets.m_destX, i_spell.m_targets.m_destY, i_spell.m_targets.m_destZ, i_radius))
                        i_data->push_back(unit);
                    break;
                case PUSH_TARGET_CENTER:
                    if (i_spell.m_targets.getUnitTarget() && i_spell.m_targets.getUnitTarget()->IsWithinDist(unit, i_radius))
                        i_data->push_back(unit);
                    break;
            }
        }
    }

#ifdef _MSC_VER
    template<> void Visit(CorpseMapType&) {}
    template<> void Visit(GameObjectMapType&) {}
    template<> void Visit(DynamicObjectMapType&) {}
    template<> void Visit(CameraMapType&) {}
#endif
};

#ifndef _MSC_VER
template<> inline void SpellNotifierCreatureAndPlayer::Visit(CorpseMapType&) {}
template<> inline void SpellNotifierCreatureAndPlayer::Visit(GameObjectMapType&) {}
template<> inline void SpellNotifierCreatureAndPlayer::Visit(DynamicObjectMapType&) {}
template<> inline void SpellNotifierCreatureAndPlayer::Visit(CameraMapType&) {}
#endif

/**
 * Fill target list by units around (x,y) points at radius distance

void Spell::CallScriptCalcCritChanceHandlers(Unit const* victim, float& critChance)
{
    for (SpellScript* loadedScript : m_loadedScripts)
    {
        loadedScript->_PrepareScriptCall(SPELL_SCRIPT_HOOK_CALC_CRIT_CHANCE);
        for (SpellScript::OnCalcCritChanceHandler const& hook : loadedScript->OnCalcCritChance)
            hook.Call(loadedScript, victim, critChance);

        loadedScript->_FinishScriptCall();
    }
 * @param targetUnitMap        Reference to target list that filled by function
 * @param x                    X coordinates of center point for target search
 * @param y                    Y coordinates of center point for target search
 * @param radius               Radius around (x,y) for target search
 * @param pushType             Additional rules for target area selection (in front, angle, etc)
 * @param spellTargets         Additional rules for target selection base at hostile/friendly state to original spell caster
 * @param originalCaster       If provided set alternative original caster, if =nullptr then used Spell::GetAffectiveObject() return
 */
void Spell::FillAreaTargets(UnitList &targetUnitMap, float radius, SpellNotifyPushType pushType, SpellTargets spellTargets, SpellCaster* originalCaster /*=nullptr*/)
{
    SpellNotifierCreatureAndPlayer notifier(*this, targetUnitMap, radius, pushType, spellTargets, originalCaster);
    Cell::VisitAllObjects(notifier.GetCenterX(), notifier.GetCenterY(), m_caster->GetMap(), notifier, radius);
}

void Spell::FillRaidOrPartyTargets(UnitList &TagUnitMap, Unit* target, float radius, bool raid, bool withPets, bool withcaster) const
{
    Player* pTarget = target->GetCharmerOrOwnerPlayerOrPlayerItself();
    Group* pGroup = pTarget ? pTarget->GetGroup() : nullptr;

    if (pGroup)
    {
        uint8 subgroup = pTarget->GetSubGroup();

        for (GroupReference* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player* target = itr->getSource();

            // IsHostileTo check duel and controlled by enemy
            if (target && (raid || subgroup == target->GetSubGroup())
                    && target->GetLevel() + 10 >= m_spellInfo->spellLevel
                    && !m_caster->IsHostileTo(target))
            {
                if ((target == m_caster && withcaster) ||
                        (target != m_caster && m_caster->IsWithinDistInMap(target, radius)))
                    TagUnitMap.push_back(target);

                if (withPets)
                    if (Pet* pet = target->GetPet())
                        if ((pet == m_caster && withcaster) ||
                                (pet != m_caster && m_caster->IsWithinDistInMap(pet, radius)))
                            TagUnitMap.push_back(pet);
            }
        }
    }
    else
    {
        Unit* ownerOrSelf = pTarget ? pTarget : target->GetCharmerOrOwnerOrSelf();
        if ((ownerOrSelf == m_caster && withcaster) ||
                (ownerOrSelf != m_caster && m_caster->IsWithinDistInMap(ownerOrSelf, radius)))
            TagUnitMap.push_back(ownerOrSelf);

        if (withPets)
            if (Pet* pet = ownerOrSelf->GetPet())
                if ((pet == m_caster && withcaster) ||
                        (pet != m_caster && m_caster->IsWithinDistInMap(pet, radius)))
                    TagUnitMap.push_back(pet);
    }
}

SpellCaster* Spell::GetAffectiveCasterObject() const
{
    if (!m_originalCasterGUID)
        return m_caster;

    if (m_originalCasterGUID.IsGameObject() && m_caster->IsInWorld())
        return m_caster->GetMap()->GetGameObject(m_originalCasterGUID);
    return m_originalCaster;
}

bool Spell::CanExecuteTriggersOnHit(Unit* unit, SpellInfo const* triggeredByAura /*= nullptr*/) const
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
SpellCaster* Spell::GetCastingObject() const
{
    if (m_originalCasterGUID.IsGameObject())
        return m_caster->IsInWorld() ? m_caster->GetMap()->GetGameObject(m_originalCasterGUID) : nullptr;
    return m_caster;
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

        if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(aurEff->GetSpellEffectInfo().TriggerSpell, GetCastDifficulty()))
        {
            // calculate the chance using spell base amount, because aura amount is not updated on combo-points change
            // this possibly needs fixing
            int32 auraBaseAmount = aurEff->GetBaseAmount();
            // proc chance is stored in effect amount
            int32 chance = unitCaster->CalculateSpellDamage(nullptr, aurEff->GetSpellEffectInfo(), &auraBaseAmount);
            chance *= aurEff->GetBase()->GetStackAmount();
void Spell::ClearCastItem()
{
    if (m_CastItem == m_targets.getItemTarget())
        m_targets.setItemTarget(nullptr);

    m_CastItem = nullptr;
}

// Global cooldowns management
bool CanHaveGlobalCooldown(WorldObject const* caster)
void Spell::ResetEffectDamageAndHeal()
{
    // Only players or controlled units have global cooldown
    if (caster->GetTypeId() != TYPEID_PLAYER && (caster->GetTypeId() != TYPEID_UNIT || !const_cast<WorldObject*>(caster)->ToCreature()->GetCharmInfo()))
        return false;

    return true;
}
    m_damage = 0;
    m_healing = 0;
    m_absorbed = 0;
}

void Spell::SetClientStarted(bool bisClientStarted)
{
    if (!CanHaveGlobalCooldown(m_caster))
        return false;

    return m_caster->ToUnit()->GetSpellHistory()->HasGlobalCooldown(m_spellInfo);
    m_isClientStarted = bisClientStarted;
}

void Spell::OnSpellLaunch()
{
    if (!CanHaveGlobalCooldown(m_caster))
        return;

    Milliseconds gcd(m_spellInfo->StartRecoveryTime);
    if (gcd == 0ms || !m_spellInfo->StartRecoveryCategory)
        return;

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
        if (m_caster->ToPlayer()->GetCommandStatus(CHEAT_COOLDOWN))
            return;
    if (!m_caster || !m_caster->IsInWorld())
        return;

    constexpr Milliseconds MinGCD = 750ms;
    constexpr Milliseconds MaxGCD = 1500ms;

    // Global cooldown can't leave range 1..1.5 secs
    // There are some spells (mostly not cast directly by player) that have < 1 sec and > 1.5 sec global cooldowns
    // but as tests show are not affected by any spell mods.
    if (gcd >= MinGCD && gcd <= MaxGCD)
    {
        // gcd modifier auras are applied only to own spells and only players have such mods
        if (Player* modOwner = m_caster->GetSpellModOwner())
        {
            int32 intGcd = gcd.count();
            modOwner->ApplySpellMod(m_spellInfo, SpellModOp::StartCooldown, intGcd, this);
            gcd = Milliseconds(intGcd);
        }

        bool isMeleeOrRangedSpell = m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MELEE ||
            m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_RANGED ||
            m_spellInfo->HasAttribute(SPELL_ATTR0_USES_RANGED_SLOT) ||
            m_spellInfo->HasAttribute(SPELL_ATTR0_IS_ABILITY);

        // Apply haste rating
        if (gcd > MinGCD && ((m_spellInfo->StartRecoveryCategory == 133 && !isMeleeOrRangedSpell)))
        {
            gcd = Milliseconds(int64(gcd.count() * m_caster->ToUnit()->m_unitData->ModSpellHaste));
            RoundToInterval(gcd, MinGCD, MaxGCD);
        }

        if (gcd > MinGCD && m_caster->ToUnit()->HasAuraTypeWithAffectMask(SPELL_AURA_MOD_GLOBAL_COOLDOWN_BY_HASTE_REGEN, m_spellInfo))
        {
            gcd = Milliseconds(int64(gcd.count() * m_caster->ToUnit()->m_unitData->ModHasteRegen));
            RoundToInterval(gcd, MinGCD, MaxGCD);
    // Make sure the player is sending a valid GO target and lock ID. SPELL_EFFECT_OPEN_LOCK
    // can succeed with a lockId of 0
    if (m_spellInfo->Id == 21651)
    {
        if (GameObject* go = m_targets.getGOTarget())
        {
            LockEntry const* lockInfo = sLockStore.LookupEntry(go->GetGOInfo()->GetLockId());
            if (lockInfo && lockInfo->Index[1] == LOCKTYPE_SLOW_OPEN)
            {
                Spell* visual = m_casterUnit ? new Spell(m_casterUnit, sSpellMgr.GetSpellEntry(24390), true) : new Spell(m_casterGo, sSpellMgr.GetSpellEntry(24390), true);
                visual->prepare();
            }
        }
    }

    m_caster->ToUnit()->GetSpellHistory()->AddGlobalCooldown(m_spellInfo, gcd);
}
    unitTarget = m_targets.getUnitTarget();

void Spell::CancelGlobalCooldown()
{
    if (!CanHaveGlobalCooldown(m_caster))
        return;

    if (!m_spellInfo->StartRecoveryTime)
    // Charge handled here instead of in effect handler
    if (!unitTarget || !unitTarget->IsInWorld())
        return;

    // Cancel global cooldown when interrupting current cast
    if (m_caster->ToUnit()->GetCurrentSpell(CURRENT_GENERIC_SPELL) != this)
    bool isCharge = false;
    for (uint32 i : m_spellInfo->Effect)
        if (i == SPELL_EFFECT_CHARGE)
            isCharge = true;
    if (!isCharge)
        return;

    m_caster->ToUnit()->GetSpellHistory()->CancelGlobalCooldown(m_spellInfo);
}

std::string Spell::GetDebugInfo() const
{
    std::stringstream sstr;
    sstr << std::boolalpha
        << "Id: " << GetSpellInfo()->Id << " Name: '" << (*GetSpellInfo()->SpellName)[sWorld->GetDefaultDbcLocale()] << "' OriginalCaster: " << m_originalCasterGUID.ToString()
        << " State: " << getState();
    return sstr.str();
}

void Spell::CallScriptOnResistAbsorbCalculateHandlers(DamageInfo const& damageInfo, uint32& resistAmount, int32& absorbAmount)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_ON_RESIST_ABSORB_CALCULATION);
        auto hookItrEnd = (*scritr)->OnCalculateResistAbsorb.end(), hookItr = (*scritr)->OnCalculateResistAbsorb.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
            hookItr->Call(*scritr, damageInfo, resistAmount, absorbAmount);
    if (!m_casterUnit)
        return;

        (*scritr)->_FinishScriptCall();
    }
}

namespace Trinity
{

WorldObjectSpellTargetCheck::WorldObjectSpellTargetCheck(WorldObject* caster, WorldObject* referer, SpellInfo const* spellInfo,
            SpellTargetCheckTypes selectionType, ConditionContainer const* condList, SpellTargetObjectTypes objectType) : _caster(caster), _referer(referer), _spellInfo(spellInfo),
    _targetSelectionType(selectionType), _condSrcInfo(nullptr), _condList(condList), _objectType(objectType)
{
    if (condList)
        _condSrcInfo = std::make_unique<ConditionSourceInfo>(nullptr, caster);
}

WorldObjectSpellTargetCheck::~WorldObjectSpellTargetCheck()
{
    // Delay attack, otherwise player makes instant attack after cast
    if (m_casterUnit->IsPlayer())
    {
        m_casterUnit->SetAttackTimer(BASE_ATTACK, m_casterUnit->GetAttackTimer(BASE_ATTACK) + 200 + 40 * m_casterUnit->GetDistance(unitTarget));
        m_casterUnit->SetAttackTimer(OFF_ATTACK, m_casterUnit->GetAttackTimer(OFF_ATTACK)  + 200 + 40 * m_casterUnit->GetDistance(unitTarget));
    }
    
    bool triggerAutoAttack = unitTarget != m_casterUnit && !m_spellInfo->IsPositiveSpell() && !(m_spellInfo->Attributes & SPELL_ATTR_STOP_ATTACK_TARGET);
    m_casterUnit->GetMotionMaster()->MoveCharge(unitTarget, GetSpellBatchingEffectDelay(unitTarget), triggerAutoAttack);
}

bool WorldObjectSpellTargetCheck::operator()(WorldObject* target) const
{
    if (_spellInfo->CheckTarget(_caster, target, true) != SPELL_CAST_OK)
        return false;

    Unit* unitTarget = target->ToUnit();
    if (Corpse* corpseTarget = target->ToCorpse())
    {
        // use owner for party/assistance checks
        if (Player* owner = ObjectAccessor::FindPlayer(corpseTarget->GetOwnerGUID()))
            unitTarget = owner;
        else
            return false;
    }
bool Spell::HasModifierApplied(SpellModifier* mod)
{
    for (const auto itr : m_appliedMods)
        if (itr == mod)
            return true;
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
                // TODO: restore IsValidAttackTarget for corpses using corpse owner (faction, etc)
                if (!target->IsCorpse() && !_caster->IsValidAttackTarget(unitTarget, _spellInfo))
                    return false;
                break;
            case TARGET_CHECK_ALLY:
                if (unitTarget->IsTotem())
                    return false;
                // TODO: restore IsValidAttackTarget for corpses using corpse owner (faction, etc)
                if (!target->IsCorpse() && !_caster->IsValidAssistTarget(unitTarget, _spellInfo))
                    return false;
                break;
            case TARGET_CHECK_PARTY:
                if (!refUnit)
                    return false;
                if (unitTarget->IsTotem())
                    return false;
                // TODO: restore IsValidAttackTarget for corpses using corpse owner (faction, etc)
                if (!target->IsCorpse() && !_caster->IsValidAssistTarget(unitTarget, _spellInfo))
                    return false;
                if (!refUnit->IsInPartyWith(unitTarget))
                    return false;
                break;
            case TARGET_CHECK_RAID_CLASS:
                if (!refUnit)
                    return false;
                if (refUnit->GetClass() != unitTarget->GetClass())
                    return false;
                [[fallthrough]];
            case TARGET_CHECK_RAID:
                if (!refUnit)
                    return false;
                if (unitTarget->IsTotem())
                    return false;
                // TODO: restore IsValidAttackTarget for corpses using corpse owner (faction, etc)
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
void Spell::RemoveStealthAuras()
{
    if (!m_casterUnit)
        return;

        switch (_objectType)
        {
            case TARGET_OBJECT_TYPE_CORPSE:
            case TARGET_OBJECT_TYPE_CORPSE_ALLY:
            case TARGET_OBJECT_TYPE_CORPSE_ENEMY:
                if (unitTarget->IsAlive())
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
    SpellTargetCheckTypes selectionType, ConditionContainer const* condList, SpellTargetObjectTypes objectType)
    : WorldObjectSpellTargetCheck(caster, caster, spellInfo, selectionType, condList, objectType), _range(range), _position(caster) { }
    // stealth must be removed at cast starting (at show channel bar)
    // skip triggered spell (item equip spell casting and other not explicit character casts/item uses)
    if (!m_IsTriggeredSpell && !(m_spellInfo->AttributesEx & SPELL_ATTR_EX_NOT_BREAK_STEALTH) && m_casterUnit->IsPlayer()
            && m_spellInfo->SpellIconID != 250 // Camouflage fufu
            && m_spellInfo->SpellIconID != 103 // Roder ou Camouflage elfe de la nuit
            && m_spellInfo->SpellIconID != 252 // Disparition
       )
    {
        bool doUnaura = m_casterUnit->HasAuraType(SPELL_AURA_MOD_STEALTH);

        if (doUnaura && m_casterUnit->IsPlayer()
                && m_spellInfo->SpellIconID == 249  // Assommer
           )
        {
            // Gestion de assommer ameliore
            if (m_casterUnit->HasAura(14076))  // Rang 1
                doUnaura = (urand(0, 99) > 30);
            else if (m_casterUnit->HasAura(14094))  // Rang 2
                doUnaura = (urand(0, 99) > 60);
            else if (m_casterUnit->HasAura(14095))  // Rang 3
                doUnaura = (urand(0, 99) > 90);
        }
        if (doUnaura)
            m_casterUnit->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);
    }
    if (!m_IsTriggeredSpell)
        m_casterUnit->RemoveSpellsCausingAura(SPELL_AURA_FEIGN_DEATH);
}

WorldObjectSpellAreaTargetCheck::WorldObjectSpellAreaTargetCheck(float range, Position const* position, WorldObject* caster,
    WorldObject* referer, SpellInfo const* spellInfo, SpellTargetCheckTypes selectionType, ConditionContainer const* condList, SpellTargetObjectTypes objectType)
    : WorldObjectSpellTargetCheck(caster, referer, spellInfo, selectionType, condList, objectType), _range(range), _position(position) { }

bool WorldObjectSpellAreaTargetCheck::operator()(WorldObject* target) const
{
    if (target->ToGameObject())
    {
        // isInRange including the dimension of the GO
        bool isInRange = target->ToGameObject()->IsInRange(_position->GetPositionX(), _position->GetPositionY(), _position->GetPositionZ(), _range);
        if (!isInRange)
            return false;
    }
void Spell::Delete() const
{
    if (IsDeletable())
        delete this;
    else
        sLog.outInfo("[CRASH] Deleting in-use spell. SpellID=%u", m_spellInfo->Id);
}

WorldObjectSpellConeTargetCheck::WorldObjectSpellConeTargetCheck(Position const& coneSrc, float coneAngle, float lineWidth, float range, WorldObject* caster,
    SpellInfo const* spellInfo, SpellTargetCheckTypes selectionType, ConditionContainer const* condList, SpellTargetObjectTypes objectType)
    : WorldObjectSpellAreaTargetCheck(range, caster, caster, caster, spellInfo, selectionType, condList, objectType), _coneSrc(coneSrc), _coneAngle(coneAngle), _lineWidth(lineWidth) { }

bool WorldObjectSpellConeTargetCheck::operator()(WorldObject* target) const
{
    if (_spellInfo->HasAttribute(SPELL_ATTR0_CU_CONE_BACK))
    {
        if (_coneSrc.HasInArc(-std::abs(_coneAngle), target))
            return false;
    }
    else if (_spellInfo->HasAttribute(SPELL_ATTR0_CU_CONE_LINE))
    {
        if (!_coneSrc.HasInLine(target, target->GetCombatReach(), _lineWidth))
            return false;
    }
    else
bool ChannelResetEvent::Execute(uint64 e_time, uint32)
{
    Abort(e_time);
    return true;
}

void ChannelResetEvent::Abort(uint64 e_time)
{
    Spell* currSpell = caster->GetCurrentSpell(CURRENT_CHANNELED_SPELL);
    if (!currSpell || currSpell->getState() == SPELL_STATE_FINISHED)
    {
        if (!_caster->IsUnit() || !_caster->ToUnit()->IsWithinBoundaryRadius(target->ToUnit()))
            // ConeAngle > 0 -> select targets in front
            // ConeAngle < 0 -> select targets in back
            if (_coneSrc.HasInArc(_coneAngle, target) != G3D::fuzzyGe(_coneAngle, 0.f))
                return false;
    }
    return WorldObjectSpellAreaTargetCheck::operator ()(target);
}

WorldObjectSpellTrajTargetCheck::WorldObjectSpellTrajTargetCheck(float range, Position const* position, WorldObject* caster, SpellInfo const* spellInfo, SpellTargetCheckTypes selectionType, ConditionContainer const* condList, SpellTargetObjectTypes objectType)
    : WorldObjectSpellTargetCheck(caster, caster, spellInfo, selectionType, condList, objectType), _range(range), _position(position) { }

bool WorldObjectSpellTrajTargetCheck::operator()(WorldObject* target) const
{
    // return all targets on missile trajectory (0 - size of a missile)
    if (!_caster->HasInLine(target, target->GetCombatReach(), TRAJECTORY_MISSILE_SIZE))
        return false;

    if (target->GetExactDist2d(_position) > _range)
        return false;

    return WorldObjectSpellTargetCheck::operator ()(target);
}

WorldObjectSpellLineTargetCheck::WorldObjectSpellLineTargetCheck(Position const* srcPosition, Position const* dstPosition, float lineWidth, float range, WorldObject* caster,
    SpellInfo const* spellInfo, SpellTargetCheckTypes selectionType, ConditionContainer const* condList, SpellTargetObjectTypes objectType)
    : WorldObjectSpellAreaTargetCheck(range, caster, caster, caster, spellInfo, selectionType, condList, objectType), _position(*srcPosition), _lineWidth(lineWidth)
{
    if (dstPosition && *srcPosition != *dstPosition)
        _position.SetOrientation(srcPosition->GetAbsoluteAngle(dstPosition));
}

bool WorldObjectSpellLineTargetCheck::operator()(WorldObject* target) const
{
    if (!_position.HasInLine(target, target->GetCombatReach(), _lineWidth))
        return false;

    return WorldObjectSpellTargetCheck::operator ()(target);
}

void SelectRandomInjuredTargets(std::list<WorldObject*>& targets, size_t maxTargets, bool prioritizePlayers)
{
    if (targets.size() <= maxTargets)
        return;

    std::vector<WorldObject*> tempTargets(targets.begin(), targets.end());

    auto begin = tempTargets.begin();
    auto end = tempTargets.end();

    if (prioritizePlayers)
    {
        auto playersEnd = std::stable_partition(begin, end, [](WorldObject const* target)
        {
            return target->IsPlayer();
        });

        size_t playerCount = std::distance(begin, playersEnd);
        if (playerCount < maxTargets)
        {
            // not enough players, add nonplayer targets
            // prioritize injured nonplayers over full health nonplayers
            auto injuredNonPlayersEnd = std::stable_partition(playersEnd, end, [](WorldObject const* target)
            {
                return target->IsUnit() && !target->ToUnit()->IsFullHealth();
            });

            size_t injuredNonPlayersCount = std::distance(playersEnd, injuredNonPlayersEnd);
            if (playerCount + injuredNonPlayersCount < maxTargets)
            {
                // not enough players + injured nonplayers
                // fill remainder with random full health nonplayers
                Containers::RandomShuffle(injuredNonPlayersEnd, end);
            }
            else if (playerCount + injuredNonPlayersCount > maxTargets)
            {
                // randomize injured nonplayers order
                // final list will contain all players + random injured nonplayers
                Containers::RandomShuffle(playersEnd, injuredNonPlayersEnd);
            }

            targets.assign(tempTargets.begin(), tempTargets.begin() + maxTargets);
            return;
        }

        // We have more players than we requested, proceed checking injured targets
        end = playersEnd;
    }

    auto injuredUnitsEnd = std::stable_partition(begin, end, [](WorldObject const* target)
    {
        return target->IsUnit() && !target->ToUnit()->IsFullHealth();
    });

    size_t injuredUnitsCount = std::distance(begin, injuredUnitsEnd);
    if (injuredUnitsCount < maxTargets)
    {
        // not enough injured units
        // fill remainder with full health units
        Containers::RandomShuffle(injuredUnitsEnd, end);
    }
    else if (injuredUnitsCount > maxTargets)
    {
        // select random injured units
        Containers::RandomShuffle(begin, injuredUnitsEnd);
    }

    targets.assign(tempTargets.begin(), tempTargets.begin() + maxTargets);
}
} //namespace Trinity

CastSpellTargetArg::CastSpellTargetArg(WorldObject* target)
{
    if (target)
    {
        if (Unit* unitTarget = target->ToUnit())
        {
            Targets.emplace();
            Targets->SetUnitTarget(unitTarget);
        }
        else if (GameObject* goTarget = target->ToGameObject())
        {
            Targets.emplace();
            Targets->SetGOTarget(goTarget);
        }
        // error when targeting anything other than units and gameobjects
    }
    else
        Targets.emplace(); // nullptr is allowed
}

CastSpellExtraArgs& CastSpellExtraArgs::SetTriggeringSpell(Spell const* triggeringSpell)
{
    TriggeringSpell = triggeringSpell;
    if (triggeringSpell)
    {
        OriginalCastItemLevel = triggeringSpell->m_castItemLevel;
        OriginalCastId = triggeringSpell->m_castId;
    }
    return *this;
}

CastSpellExtraArgs& CastSpellExtraArgs::SetTriggeringAura(AuraEffect const* triggeringAura)
{
    TriggeringAura = triggeringAura;
    if (triggeringAura)
        OriginalCastId = triggeringAura->GetBase()->GetCastId();

    return *this;
}

SpellCastVisual::operator UF::SpellCastVisual() const
{
    UF::SpellCastVisual visual;
    visual.SpellXSpellVisualID = SpellXSpellVisualID;
    visual.ScriptVisualID = ScriptVisualID;
    return visual;
}

SpellCastVisual::operator WorldPackets::Spells::SpellCastVisual() const
{
    return { int32(SpellXSpellVisualID), int32(ScriptVisualID) };
        caster->SetChannelObjectGuid(ObjectGuid());
        caster->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);
        if (caster->IsPlayer())
        {
            WorldPacket data(MSG_CHANNEL_UPDATE, 4);
            data << uint32(0);
            ((Player*)caster)->SendDirectMessage(&data);
        }
    }
}
    {
        CreateItem(184501),     //-- 184501
    }

CreateDestination(
    "Shadowlands Dungeons",                 -- No localization
    {
        CreateChallengeSpell(354462),   //-- Hero's Path: Necrotic Wake
        CreateChallengeSpell(354363),  // -- Hero's Path: Plaguefall
        CreateChallengeSpell(354464),  // -- Hero's Path: Mists of Tirna Scithe
        CreateChallengeSpell(354465),  // -- Hero's Path: Halls of Atonement
        CreateChallengeSpell(354466),  // -- Hero's Path: Spires  of Ascension
        CreateChallengeSpell(354467),   //-- Hero's Path: Theater of Pain
        CreateChallengeSpell(354468),   //-- Hero's Path: De Other Side
        CreateChallengeSpell(354469),   //-- Hero's Path: Sanguine Depths
    })

CreateDestination(
    LocZone("Stormwind City","Orgrimmar", 111),
    {

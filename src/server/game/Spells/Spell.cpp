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

#include "Spell.h"
#include "Battlefield.h"
#include "BattlefieldMgr.h"
#include "Battleground.h"
#include "CellImpl.h"
#include "CombatLogPackets.h"
#include "Common.h"
#include "ConditionMgr.h"
#include "DB2Stores.h"
#include "DatabaseEnv.h"
#include "DisableMgr.h"
#include "DynamicObject.h"
#include "GridNotifiersImpl.h"
#include "Guild.h"
#include "InstanceScript.h"
#include "Item.h"
#include "Log.h"
#include "LootMgr.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
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
#include "Util.h"
#include "VMapFactory.h"
#include "Vehicle.h"
#include "World.h"
#include "WorldSession.h"
#include <numeric>

extern pEffect SpellEffects[TOTAL_SPELL_EFFECTS];

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
    if (!_transportGUID.IsEmpty())
    {
        Position offset;
        _position.GetPositionOffsetTo(pos, offset);
        _transportOffset.RelocateOffset(offset);
    }
    _position.Relocate(pos);
}

void SpellDestination::RelocateOffset(Position const& offset)
{
    if (!_transportGUID.IsEmpty())
        _transportOffset.RelocateOffset(offset);

    _position.RelocateOffset(offset);
}

SpellCastTargets::SpellCastTargets() : m_targetMask(0), m_objectTarget(nullptr), m_itemTarget(nullptr),
    m_itemTargetEntry(0), m_pitch(0.0f), m_speed(0.0f)
{
}

SpellCastTargets::SpellCastTargets(Unit* caster, WorldPackets::Spells::SpellCastRequest const& spellCastRequest) :
    m_targetMask(spellCastRequest.Target.Flags), m_objectTarget(nullptr), m_itemTarget(nullptr),
    m_objectTargetGUID(spellCastRequest.Target.Unit), m_itemTargetGUID(spellCastRequest.Target.Item),
    m_itemTargetEntry(0), m_pitch(0.0f), m_speed(0.0f), m_strTarget(spellCastRequest.Target.Name)
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
        data.SrcLocation = boost::in_place();
        data.SrcLocation->Transport = m_src._transportGUID; // relative position guid here - transport for example
        if (!m_src._transportGUID.IsEmpty())
            data.SrcLocation->Location = m_src._transportOffset;
        else
            data.SrcLocation->Location = m_src._position;
    }

    if (m_targetMask & TARGET_FLAG_DEST_LOCATION)
    {
        data.DstLocation = boost::in_place();
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
        case HighGuid::Creature:
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

    return NULL;
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
    m_objectTarget = NULL;
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
    m_itemTargetGUID = ObjectGuid::TradeItem;
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

void SpellCastTargets::Update(Unit* caster)
{
    m_objectTarget = !m_objectTargetGUID.IsEmpty() ? ((m_objectTargetGUID == caster->GetGUID()) ? caster : ObjectAccessor::GetWorldObject(*caster, m_objectTargetGUID)) : NULL;

    m_itemTarget = NULL;
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

        if (m_itemTarget)
            m_itemTargetEntry = m_itemTarget->GetEntry();
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

void SpellCastTargets::OutDebug() const
{
    if (!m_targetMask)
        TC_LOG_DEBUG("spells", "No targets");

    TC_LOG_DEBUG("spells", "target mask: %u", m_targetMask);
    if (m_targetMask & (TARGET_FLAG_UNIT_MASK | TARGET_FLAG_CORPSE_MASK | TARGET_FLAG_GAMEOBJECT_MASK))
        TC_LOG_DEBUG("spells", "Object target: %s", m_objectTargetGUID.ToString().c_str());
    if (m_targetMask & TARGET_FLAG_ITEM)
        TC_LOG_DEBUG("spells", "Item target: %s", m_itemTargetGUID.ToString().c_str());
    if (m_targetMask & TARGET_FLAG_TRADE_ITEM)
        TC_LOG_DEBUG("spells", "Trade item target: %s", m_itemTargetGUID.ToString().c_str());
    if (m_targetMask & TARGET_FLAG_SOURCE_LOCATION)
        TC_LOG_DEBUG("spells", "Source location: transport guid:%s trans offset: %s position: %s", m_src._transportGUID.ToString().c_str(), m_src._transportOffset.ToString().c_str(), m_src._position.ToString().c_str());
    if (m_targetMask & TARGET_FLAG_DEST_LOCATION)
        TC_LOG_DEBUG("spells", "Destination location: transport guid:%s trans offset: %s position: %s", m_dst._transportGUID.ToString().c_str(), m_dst._transportOffset.ToString().c_str(), m_dst._position.ToString().c_str());
    if (m_targetMask & TARGET_FLAG_STRING)
        TC_LOG_DEBUG("spells", "String: %s", m_strTarget.c_str());
    TC_LOG_DEBUG("spells", "speed: %f", m_speed);
    TC_LOG_DEBUG("spells", "pitch: %f", m_pitch);
}

SpellValue::SpellValue(Difficulty diff, SpellInfo const* proto)
{
    // todo 6.x
    SpellEffectInfoVector effects = proto->GetEffectsForDifficulty(diff);
    ASSERT(effects.size() <= MAX_SPELL_EFFECTS);
    memset(EffectBasePoints, 0, sizeof(EffectBasePoints));
    for (SpellEffectInfo const* effect : effects)
        if (effect)
            EffectBasePoints[effect->EffectIndex] = effect->BasePoints;

    MaxAffectedTargets = proto->MaxAffectedTargets;
    RadiusMod = 1.0f;
    AuraStackAmount = 1;
}

class TC_GAME_API SpellEvent : public BasicEvent
{
public:
    SpellEvent(Spell* spell);
    virtual ~SpellEvent();

    virtual bool Execute(uint64 e_time, uint32 p_time) override;
    virtual void Abort(uint64 e_time) override;
    virtual bool IsDeletable() const override;
protected:
    Spell* m_Spell;
};

Spell::Spell(Unit* caster, SpellInfo const* info, TriggerCastFlags triggerFlags, ObjectGuid originalCasterGUID, bool skipCheck) :
m_spellInfo(info), m_caster((info->HasAttribute(SPELL_ATTR6_CAST_BY_CHARMER) && caster->GetCharmerOrOwner()) ? caster->GetCharmerOrOwner() : caster),
m_spellValue(new SpellValue(caster->GetMap()->GetDifficultyID(), m_spellInfo))
{
    _effects = info->GetEffectsForDifficulty(caster->GetMap()->GetDifficultyID());

    m_customError = SPELL_CUSTOM_ERROR_NONE;
    m_skipCheck = skipCheck;
    m_fromClient = false;
    m_selfContainer = NULL;
    m_referencedFromCurrentSpell = false;
    m_executedCurrently = false;
    m_needComboPoints = m_spellInfo->NeedsComboPoints();
    m_comboPointGain = 0;
    m_delayStart = 0;
    m_delayAtDamageCount = 0;

    m_applyMultiplierMask = 0;
    m_auraScaleMask = 0;
    memset(m_damageMultipliers, 0, sizeof(m_damageMultipliers));

    // Get data for type of attack
    m_attackType = info->GetAttackType();

    m_spellSchoolMask = info->GetSchoolMask();           // Can be override for some spell (wand shoot for example)

    if (m_attackType == RANGED_ATTACK)
        // wand case
        if ((m_caster->getClassMask() & CLASSMASK_WAND_USERS) != 0 && m_caster->GetTypeId() == TYPEID_PLAYER)
            if (Item* pItem = m_caster->ToPlayer()->GetWeaponForAttack(RANGED_ATTACK))
                m_spellSchoolMask = SpellSchoolMask(1 << pItem->GetTemplate()->GetDamageType());

    if (!originalCasterGUID.IsEmpty())
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
    if (info->HasAttribute(SPELL_ATTR4_CAN_CAST_WHILE_CASTING))
        _triggeredCastFlags = TriggerCastFlags(uint32(_triggeredCastFlags) | TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_CAST_DIRECTLY);

    m_CastItem = NULL;
    m_castItemGUID.Clear();
    m_castItemEntry = 0;
    m_castItemLevel = -1;
    m_castFlagsEx = 0;

    unitTarget = NULL;
    itemTarget = NULL;
    gameObjTarget = NULL;
    destTarget = NULL;
    damage = 0;
    targetMissInfo = SPELL_MISS_NONE;
    variance = 0.0f;
    effectHandleMode = SPELL_EFFECT_HANDLE_LAUNCH;
    effectInfo = nullptr;
    m_damage = 0;
    m_healing = 0;
    m_procAttacker = 0;
    m_procVictim = 0;
    m_hitMask = 0;
    focusObject = NULL;
    m_castId = ObjectGuid::Create<HighGuid::Cast>(SPELL_CAST_SOURCE_NORMAL, m_caster->GetMapId(), m_spellInfo->Id, m_caster->GetMap()->GenerateLowGuid<HighGuid::Cast>());
    memset(m_misc.Raw.Data, 0, sizeof(m_misc.Raw.Data));
    m_SpellVisual = caster->GetCastSpellXSpellVisualId(m_spellInfo);
    m_triggeredByAuraSpell  = NULL;
    m_spellAura = NULL;

    //Auto Shot & Shoot (wand)
    m_autoRepeat = m_spellInfo->IsAutoRepeatRangedSpell();

    m_runesState = 0;
    m_casttime = 0;                                         // setup to correct value in Spell::prepare, must not be used before.
    m_timer = 0;                                            // will set to castime in prepare
    m_channeledDuration = 0;                                // will be setup in Spell::handle_immediate
    m_immediateHandled = false;

    m_channelTargetEffectMask = 0;

    // Determine if spell can be reflected back to the caster
    // Patch 1.2 notes: Spell Reflection no longer reflects abilities
    m_canReflect = m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MAGIC && !m_spellInfo->HasAttribute(SPELL_ATTR0_ABILITY)
        && !m_spellInfo->HasAttribute(SPELL_ATTR1_CANT_BE_REFLECTED) && !m_spellInfo->HasAttribute(SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY)
        && !m_spellInfo->IsPassive();

    CleanupTargetList();

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
        *m_selfContainer = NULL;
    }

    if (m_caster && m_caster->GetTypeId() == TYPEID_PLAYER)
        ASSERT(m_caster->ToPlayer()->m_spellModTakingSpell != this);

    delete m_spellValue;
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
            Unit* unit = NULL;
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
                unit = m_caster->GetVictim();

            // didn't find anything - let's use self as target
            if (!unit && neededTargets & (TARGET_FLAG_UNIT_RAID | TARGET_FLAG_UNIT_PARTY | TARGET_FLAG_UNIT_ALLY))
                unit = m_caster;

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
        if (m_spellInfo->GetExplicitTargetMask() & TARGET_FLAG_UNIT_ENEMY
            || (m_spellInfo->GetExplicitTargetMask() & TARGET_FLAG_UNIT && !m_caster->IsFriendlyTo(target)))
        {
            Unit* redirect;
            switch (m_spellInfo->DmgClass)
            {
                case SPELL_DAMAGE_CLASS_MAGIC:
                    redirect = m_caster->GetMagicHitRedirectTarget(target, m_spellInfo);
                    break;
                case SPELL_DAMAGE_CLASS_MELEE:
                case SPELL_DAMAGE_CLASS_RANGED:
                    redirect = m_caster->GetMeleeHitRedirectTarget(target, m_spellInfo);
                    break;
                default:
                    redirect = NULL;
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

    for (SpellEffectInfo const* effect : GetEffects())
    {
        if (!effect)
            continue;

        // not call for empty effect.
        // Also some spells use not used effect targets for store targets for dummy effect in triggered spells
        if (!effect->IsEffect())
            continue;

        // set expected type of implicit targets to be sent to client
        uint32 implicitTargetMask = GetTargetFlagMask(effect->TargetA.GetObjectType()) | GetTargetFlagMask(effect->TargetB.GetObjectType());
        if (implicitTargetMask & TARGET_FLAG_UNIT)
            m_targets.SetTargetFlag(TARGET_FLAG_UNIT);
        if (implicitTargetMask & (TARGET_FLAG_GAMEOBJECT | TARGET_FLAG_GAMEOBJECT_ITEM))
            m_targets.SetTargetFlag(TARGET_FLAG_GAMEOBJECT);

        SelectEffectImplicitTargets(SpellEffIndex(effect->EffectIndex), effect->TargetA, processedAreaEffectsMask);
        SelectEffectImplicitTargets(SpellEffIndex(effect->EffectIndex), effect->TargetB, processedAreaEffectsMask);

        // Select targets of effect based on effect type
        // those are used when no valid target could be added for spell effect based on spell target type
        // some spell effects use explicit target as a default target added to target map (like SPELL_EFFECT_LEARN_SPELL)
        // some spell effects add target to target map only when target type specified (like SPELL_EFFECT_WEAPON)
        // some spell effects don't add anything to target map (confirmed with sniffs) (like SPELL_EFFECT_DESTROY_ALL_TOTEMS)
        SelectEffectTypeImplicitTargets(effect->EffectIndex);

        if (m_targets.HasDst())
            AddDestTarget(*m_targets.GetDst(), effect->EffectIndex);

        if (m_spellInfo->IsChanneled())
        {
            uint32 mask = (1 << effect->EffectIndex);
            for (std::vector<TargetInfo>::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
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
            for (std::vector<TargetInfo>::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end();)
            {
                // remove targets which did not pass min level check
                if (m_auraScaleMask && ihit->effectMask == m_auraScaleMask)
                {
                    // Do not check for selfcast
                    if (!ihit->scaleAura && ihit->targetGUID != m_caster->GetGUID())
                    {
                        ihit = m_UniqueTargetInfo.erase(ihit);
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
                m_delayMoment = uint64(std::floor(m_targets.GetDist2d() / speed * 1000.0f));
        }
        else if (m_spellInfo->Speed > 0.0f)
        {
            float dist = m_caster->GetDistance(*m_targets.GetDstPos());
            if (!m_spellInfo->HasAttribute(SPELL_ATTR9_SPECIAL_DELAY_CALCULATION))
                m_delayMoment = uint64(std::floor(dist / m_spellInfo->Speed * 1000.0f));
            else
                m_delayMoment = uint64(m_spellInfo->Speed * 1000.0f);
        }
    }
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
            if (SpellEffectInfo const* _effect = GetEffect(effIndex))
            {
                // choose which targets we can select at once
                for (SpellEffectInfo const* effect : GetEffects())
                {
                    //for (uint32 j = effIndex + 1; j < MAX_SPELL_EFFECTS; ++j)
                    if (!effect || effect->EffectIndex <= uint32(effIndex))
                        continue;
                    if (effect->IsEffect() &&
                        _effect->TargetA.GetTarget() == effect->TargetA.GetTarget() &&
                        _effect->TargetB.GetTarget() == effect->TargetB.GetTarget() &&
                        _effect->ImplicitTargetConditions == effect->ImplicitTargetConditions &&
                        _effect->CalcRadius(m_caster) == effect->CalcRadius(m_caster) &&
                        CheckScriptEffectImplicitTargets(effIndex, effect->EffectIndex))
                    {
                        effectMask |= 1 << effect->EffectIndex;
                    }
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
            for (ObjectGuid const& channelTarget : m_originalCaster->GetChannelObjects())
            {
                WorldObject* target = ObjectAccessor::GetUnit(*m_caster, channelTarget);
                CallScriptObjectTargetSelectHandlers(target, effIndex, targetType);
                // unit target may be no longer avalible - teleported out of map for example
                Unit* unitTarget = target ? target->ToUnit() : nullptr;
                if (unitTarget)
                    AddUnitTarget(unitTarget, 1 << effIndex);
                else
                    TC_LOG_DEBUG("spells", "SPELL: cannot find channel spell target for spell ID %u, effect %u", m_spellInfo->Id, effIndex);
            }
            break;
        }
        case TARGET_DEST_CHANNEL_TARGET:
            if (channeledSpell->m_targets.HasDst())
                m_targets.SetDst(channeledSpell->m_targets);
            else
            {
                DynamicFieldStructuredView<ObjectGuid> channelObjects = m_originalCaster->GetChannelObjects();
                WorldObject* target = channelObjects.size() > 0 ? ObjectAccessor::GetWorldObject(*m_caster, *channelObjects.begin()) : nullptr;
                if (target)
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
            }
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

    SpellEffectInfo const* effect = GetEffect(effIndex);
    if (!effect)
        return;

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
            range = m_spellInfo->GetMaxRange(m_spellInfo->IsPositive(), m_caster, this);
            break;
        default:
            ASSERT(false && "Spell::SelectImplicitNearbyTargets: received not implemented selection check type");
            break;
    }

    ConditionContainer* condList = effect->ImplicitTargetConditions;

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
        TC_LOG_DEBUG("spells", "Spell::SelectImplicitNearbyTargets: OnObjectTargetSelect script hook for spell Id %u set NULL target, effect %u", m_spellInfo->Id, effIndex);
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
    if (targetType.GetReferenceType() != TARGET_REFERENCE_TYPE_CASTER)
    {
        ASSERT(false && "Spell::SelectImplicitConeTargets: received not implemented target reference type");
        return;
    }
    std::list<WorldObject*> targets;
    SpellTargetObjectTypes objectType = targetType.GetObjectType();
    SpellTargetCheckTypes selectionType = targetType.GetCheckType();
    SpellEffectInfo const* effect = GetEffect(effIndex);
    if (!effect)
        return;

    ConditionContainer* condList = effect->ImplicitTargetConditions;
    float radius = effect->CalcRadius(m_caster) * m_spellValue->RadiusMod;

    if (uint32 containerTypeMask = GetSearcherTypeMask(objectType, condList))
    {
        Trinity::WorldObjectSpellConeTargetCheck check(DegToRad(m_spellInfo->ConeAngle), radius, m_caster, m_spellInfo, selectionType, condList);
        Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellConeTargetCheck> searcher(m_caster, targets, check, containerTypeMask);
        SearchTargets<Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellConeTargetCheck> >(searcher, containerTypeMask, m_caster, m_caster, radius);

        CallScriptObjectAreaTargetSelectHandlers(targets, effIndex, targetType);

        if (!targets.empty())
        {
            // Other special target selection goes here
            if (uint32 maxTargets = m_spellValue->MaxAffectedTargets)
                Trinity::Containers::RandomResize(targets, maxTargets);

            for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
            {
                if (Unit* unit = (*itr)->ToUnit())
                    AddUnitTarget(unit, effMask, false);
                else if (GameObject* gObjTarget = (*itr)->ToGameObject())
                    AddGOTarget(gObjTarget, effMask);
            }
        }
    }
}

void Spell::SelectImplicitAreaTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType, uint32 effMask)
{
    Unit* referer = NULL;
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
            for (std::vector<TargetInfo>::reverse_iterator ihit = m_UniqueTargetInfo.rbegin(); ihit != m_UniqueTargetInfo.rend(); ++ihit)
            {
                if (ihit->effectMask & (1 << effIndex))
                {
                    referer = ObjectAccessor::GetUnit(*m_caster, ihit->targetGUID);
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

    Position const* center = NULL;
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

    std::list<WorldObject*> targets;
    SpellEffectInfo const* effect = GetEffect(effIndex);
    if (!effect)
        return;
    float radius = effect->CalcRadius(m_caster) * m_spellValue->RadiusMod;
    SearchAreaTargets(targets, radius, center, referer, targetType.GetObjectType(), targetType.GetCheckType(), effect->ImplicitTargetConditions);

    CallScriptObjectAreaTargetSelectHandlers(targets, effIndex, targetType);

    if (!targets.empty())
    {
        // Other special target selection goes here
        if (uint32 maxTargets = m_spellValue->MaxAffectedTargets)
            Trinity::Containers::RandomResize(targets, maxTargets);

        for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
        {
            if (Unit* unit = (*itr)->ToUnit())
                AddUnitTarget(unit, effMask, false, true, center);
            else if (GameObject* gObjTarget = (*itr)->ToGameObject())
                AddGOTarget(gObjTarget, effMask);
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
                if (HasEffect(SPELL_EFFECT_TELEPORT_UNITS) || HasEffect(SPELL_EFFECT_BIND))
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
            m_caster->GetClosePoint(x, y, z, DEFAULT_WORLD_OBJECT_SIZE, dist, angle);

            float ground = m_caster->GetMap()->GetHeight(m_caster->GetPhaseShift(), x, y, z, true, 50.0f);
            float liquidLevel = VMAP_INVALID_HEIGHT_VALUE;
            LiquidData liquidData;
            if (m_caster->GetMap()->getLiquidStatus(m_caster->GetPhaseShift(), x, y, z, MAP_ALL_LIQUIDS, &liquidData))
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
        default:
        {
            if (SpellEffectInfo const* effect = GetEffect(effIndex))
            {
                float dist = effect->CalcRadius(m_caster);
                float angle = targetType.CalcDirectionAngle();
                float objSize = m_caster->GetObjectSize();

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
                        if (!effect->HasRadius() && !effect->HasMaxRadius())
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
            }
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
            if (SpellEffectInfo const* effect = GetEffect(effIndex))
            {
                float angle = targetType.CalcDirectionAngle();
                float objSize = target->GetObjectSize();
                float dist = effect->CalcRadius(m_caster);
                if (dist < objSize)
                    dist = objSize;
                else if (targetType.GetTarget() == TARGET_DEST_TARGET_RANDOM)
                    dist = objSize + (dist - objSize) * float(rand_norm());

                Position pos = dest._position;
                target->MovePositionToFirstCollision(pos, dist, angle);

                dest.Relocate(pos);
            }
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
            return;
        case TARGET_DEST_TRAJ:
            SelectImplicitTrajTargets(effIndex);
            return;
        default:
        {
            if (SpellEffectInfo const* effect = GetEffect(effIndex))
            {
                float angle = targetType.CalcDirectionAngle();
                float dist = effect->CalcRadius(m_caster);
                if (targetType.GetTarget() == TARGET_DEST_DEST_RANDOM)
                    dist *= float(rand_norm());

                Position pos = dest._position;
                m_caster->MovePositionToFirstCollision(pos, dist, angle);

                dest.Relocate(pos);
            }
            break;
        }
    }

    CallScriptDestinationTargetSelectHandlers(dest, effIndex, targetType);
    m_targets.ModDst(dest);
}

void Spell::SelectImplicitCasterObjectTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType)
{
    WorldObject* target = NULL;
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
            target = m_caster->GetGuardianPet();
            break;
        case TARGET_UNIT_SUMMONER:
            if (m_caster->IsSummon())
                target = m_caster->ToTempSummon()->GetSummoner();
            break;
        case TARGET_UNIT_VEHICLE:
            target = m_caster->GetVehicleBase();
            break;
        case TARGET_UNIT_PASSENGER_0:
        case TARGET_UNIT_PASSENGER_1:
        case TARGET_UNIT_PASSENGER_2:
        case TARGET_UNIT_PASSENGER_3:
        case TARGET_UNIT_PASSENGER_4:
        case TARGET_UNIT_PASSENGER_5:
        case TARGET_UNIT_PASSENGER_6:
        case TARGET_UNIT_PASSENGER_7:
            if (m_caster->GetTypeId() == TYPEID_UNIT && m_caster->IsVehicle())
                target = m_caster->GetVehicleKit()->GetPassenger(targetType.GetTarget() - TARGET_UNIT_PASSENGER_0);
            break;
        default:
            break;
    }

    CallScriptObjectTargetSelectHandlers(target, effIndex, targetType);

    if (target && target->ToUnit())
        AddUnitTarget(target->ToUnit(), 1 << effIndex, checkIfValid);
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

        SelectImplicitChainTargets(effIndex, targetType, target, 1 << effIndex);
    }
    // Script hook can remove object target and we would wrongly land here
    else if (Item* item = m_targets.GetItemTarget())
        AddItemTarget(item, 1 << effIndex);
}

void Spell::SelectImplicitChainTargets(SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType, WorldObject* target, uint32 effMask)
{
    SpellEffectInfo const* effect = GetEffect(effIndex);
    if (!effect)
        return;

    uint32 maxTargets = effect->ChainTargets;
    if (Player* modOwner = m_caster->GetSpellModOwner())
        modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_JUMP_TARGETS, maxTargets, this);

    if (maxTargets > 1)
    {
        // mark damage multipliers as used
        for (SpellEffectInfo const* eff : GetEffects())
            if (eff && (effMask & (1 << eff->EffectIndex)))
                m_damageMultipliers[eff->EffectIndex] = 1.0f;
        m_applyMultiplierMask |= effMask;

        std::list<WorldObject*> targets;
        SearchChainTargets(targets, maxTargets - 1, target, targetType.GetObjectType(), targetType.GetCheckType()
            , effect->ImplicitTargetConditions, targetType.GetTarget() == TARGET_UNIT_TARGET_CHAINHEAL_ALLY);

        // Chain primary target is added earlier
        CallScriptObjectAreaTargetSelectHandlers(targets, effIndex, targetType);

        for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
            if (Unit* unit = (*itr)->ToUnit())
                AddUnitTarget(unit, effMask, false);
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

#define DEBUG_TRAJ(a) //a

void Spell::SelectImplicitTrajTargets(SpellEffIndex effIndex)
{
    if (!m_targets.HasTraj())
        return;

    float dist2d = m_targets.GetDist2d();
    if (!dist2d)
        return;

    float srcToDestDelta = m_targets.GetDstPos()->m_positionZ - m_targets.GetSrcPos()->m_positionZ;

    std::list<WorldObject*> targets;
    Trinity::WorldObjectSpellTrajTargetCheck check(dist2d, m_targets.GetSrcPos(), m_caster, m_spellInfo);
    Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellTrajTargetCheck> searcher(m_caster, targets, check, GRID_MAP_TYPE_MASK_ALL);
    SearchTargets<Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellTrajTargetCheck> > (searcher, GRID_MAP_TYPE_MASK_ALL, m_caster, m_targets.GetSrcPos(), dist2d);
    if (targets.empty())
        return;

    targets.sort(Trinity::ObjectDistanceOrderPred(m_caster));

    float b = tangent(m_targets.GetPitch());
    float a = (srcToDestDelta - dist2d * b) / (dist2d * dist2d);
    if (a > -0.0001f)
        a = 0;
    DEBUG_TRAJ(TC_LOG_ERROR("spells", "Spell::SelectTrajTargets: a %f b %f", a, b);)

    float bestDist = m_spellInfo->GetMaxRange(false);

    std::list<WorldObject*>::const_iterator itr = targets.begin();
    for (; itr != targets.end(); ++itr)
    {
        if (!m_caster->HasInLine(*itr, 5.0f))
            continue;

        if (m_spellInfo->CheckTarget(m_caster, *itr, true) != SPELL_CAST_OK)
            continue;

        if (Unit* unit = (*itr)->ToUnit())
        {
            if (m_caster == *itr || m_caster->IsOnVehicle(unit) || unit->GetVehicle())
                continue;

            if (Creature* creatureTarget = unit->ToCreature())
            {
                if (!(creatureTarget->GetCreatureTemplate()->type_flags & CREATURE_TYPE_FLAG_CAN_COLLIDE_WITH_MISSILES))
                    continue;
            }
        }

        const float size = std::max((*itr)->GetObjectSize() * 0.7f, 1.0f); // 1/sqrt(3)
        /// @todo all calculation should be based on src instead of m_caster
        const float objDist2d = m_targets.GetSrcPos()->GetExactDist2d(*itr) * std::cos(m_targets.GetSrcPos()->GetRelativeAngle(*itr));
        const float dz = (*itr)->GetPositionZ() - m_targets.GetSrcPos()->m_positionZ;

        DEBUG_TRAJ(TC_LOG_ERROR("spells", "Spell::SelectTrajTargets: check %u, dist between %f %f, height between %f %f.", (*itr)->GetEntry(), objDist2d - size, objDist2d + size, dz - size, dz + size);)

        float dist = objDist2d - size;
        float height = dist * (a * dist + b);
        DEBUG_TRAJ(TC_LOG_ERROR("spells", "Spell::SelectTrajTargets: dist %f, height %f.", dist, height);)
        if (dist < bestDist && height < dz + size && height > dz - size)
        {
            bestDist = dist > 0 ? dist : 0;
            break;
        }

#define CHECK_DIST {\
            DEBUG_TRAJ(TC_LOG_ERROR("spells", "Spell::SelectTrajTargets: dist %f, height %f.", dist, height);)\
            if (dist > bestDist)\
                continue;\
            if (dist < objDist2d + size && dist > objDist2d - size)\
            {\
                bestDist = dist;\
                break;\
            }\
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
            sqrt1 = std::sqrt(sqrt1);
            dist = (sqrt1 - b) / (2 * a);
            CHECK_DIST;
        }

        height = dz + size;
        float sqrt2 = b * b + 4 * a * height;
        if (sqrt2 > 0)
        {
            sqrt2 = std::sqrt(sqrt2);
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

    if (m_targets.GetSrcPos()->GetExactDist2d(m_targets.GetDstPos()) > bestDist)
    {
        float x = m_targets.GetSrcPos()->m_positionX + std::cos(m_caster->GetOrientation()) * bestDist;
        float y = m_targets.GetSrcPos()->m_positionY + std::sin(m_caster->GetOrientation()) * bestDist;
        float z = m_targets.GetSrcPos()->m_positionZ + bestDist * (a * bestDist + b);

        if (itr != targets.end())
        {
            float distSq = (*itr)->GetExactDistSq(x, y, z);
            float sizeSq = (*itr)->GetObjectSize();
            sizeSq *= sizeSq;
            DEBUG_TRAJ(TC_LOG_ERROR("spells", "Initial %f %f %f %f %f", x, y, z, distSq, sizeSq);)
            if (distSq > sizeSq)
            {
                float factor = 1 - std::sqrt(sizeSq / distSq);
                x += factor * ((*itr)->GetPositionX() - x);
                y += factor * ((*itr)->GetPositionY() - y);
                z += factor * ((*itr)->GetPositionZ() - z);

                distSq = (*itr)->GetExactDistSq(x, y, z);
                DEBUG_TRAJ(TC_LOG_ERROR("spells", "Initial %f %f %f %f %f", x, y, z, distSq, sizeSq);)
            }
        }

        Position trajDst;
        trajDst.Relocate(x, y, z, m_caster->GetOrientation());
        SpellDestination dest(*m_targets.GetDst());
        dest.Relocate(trajDst);

        CallScriptDestinationTargetSelectHandlers(dest, effIndex, SpellImplicitTargetInfo(TARGET_DEST_TRAJ));
        m_targets.ModDst(dest);
    }

    if (Vehicle* veh = m_caster->GetVehicleKit())
        veh->SetLastShootPos(*m_targets.GetDstPos());
}

void Spell::SelectEffectTypeImplicitTargets(uint32 effIndex)
{
    // special case for SPELL_EFFECT_SUMMON_RAF_FRIEND and SPELL_EFFECT_SUMMON_PLAYER
    /// @todo this is a workaround - target shouldn't be stored in target map for those spells
    SpellEffectInfo const* effect = GetEffect(effIndex);
    if (!effect)
        return;
    switch (effect->Effect)
    {
        case SPELL_EFFECT_SUMMON_RAF_FRIEND:
        case SPELL_EFFECT_SUMMON_PLAYER:
            if (m_caster->GetTypeId() == TYPEID_PLAYER && !m_caster->GetTarget().IsEmpty())
            {
                WorldObject* target = ObjectAccessor::FindPlayer(m_caster->GetTarget());

                CallScriptObjectTargetSelectHandlers(target, SpellEffIndex(effIndex), SpellImplicitTargetInfo());

                if (target && target->ToPlayer())
                    AddUnitTarget(target->ToUnit(), 1 << effIndex, false);
            }
            return;
        default:
            break;
    }

    // select spell implicit targets based on effect type
    if (!effect->GetImplicitTargetType())
        return;

    uint32 targetMask = effect->GetMissingTargetMask();

    if (!targetMask)
        return;

    WorldObject* target = NULL;

    switch (effect->GetImplicitTargetType())
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
                    {
                        /// @todo this is a workaround - corpses should be added to spell target map too, but we can't do that so we add owner instead
                        if (Player* owner = ObjectAccessor::FindPlayer(corpseTarget->GetOwnerGUID()))
                            target = owner;
                    }
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
    if (!m_spellInfo->HasAttribute(SPELL_ATTR2_CAN_TARGET_DEAD))
        retMask &= ~GRID_MAP_TYPE_MASK_CORPSE;
    if (m_spellInfo->HasAttribute(SPELL_ATTR3_ONLY_TARGET_PLAYERS))
        retMask &= GRID_MAP_TYPE_MASK_CORPSE | GRID_MAP_TYPE_MASK_PLAYER;
    if (m_spellInfo->HasAttribute(SPELL_ATTR3_ONLY_TARGET_GHOSTS))
        retMask &= GRID_MAP_TYPE_MASK_PLAYER;

    if (condList)
        retMask &= sConditionMgr->GetSearcherTypeMaskForConditionList(*condList);
    return retMask;
}

template<class SEARCHER>
void Spell::SearchTargets(SEARCHER& searcher, uint32 containerMask, Unit* referer, Position const* pos, float radius)
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

        CellCoord p(Trinity::ComputeCellCoord(x, y));
        Cell cell(p);
        cell.SetNoCreate();

        Map* map = referer->GetMap();

        if (searchInWorld)
            Cell::VisitWorldObjects(x, y, map, searcher, radius);

        if (searchInGrid)
            Cell::VisitGridObjects(x, y, map, searcher, radius);
    }
}

WorldObject* Spell::SearchNearbyTarget(float range, SpellTargetObjectTypes objectType, SpellTargetCheckTypes selectionType, ConditionContainer* condList)
{
    WorldObject* target = NULL;
    uint32 containerTypeMask = GetSearcherTypeMask(objectType, condList);
    if (!containerTypeMask)
        return NULL;
    Trinity::WorldObjectSpellNearbyTargetCheck check(range, m_caster, m_spellInfo, selectionType, condList);
    Trinity::WorldObjectLastSearcher<Trinity::WorldObjectSpellNearbyTargetCheck> searcher(m_caster, target, check, containerTypeMask);
    SearchTargets<Trinity::WorldObjectLastSearcher<Trinity::WorldObjectSpellNearbyTargetCheck> > (searcher, containerTypeMask, m_caster, m_caster, range);
    return target;
}

void Spell::SearchAreaTargets(std::list<WorldObject*>& targets, float range, Position const* position, Unit* referer, SpellTargetObjectTypes objectType, SpellTargetCheckTypes selectionType, ConditionContainer* condList)
{
    uint32 containerTypeMask = GetSearcherTypeMask(objectType, condList);
    if (!containerTypeMask)
        return;
    Trinity::WorldObjectSpellAreaTargetCheck check(range, position, m_caster, referer, m_spellInfo, selectionType, condList);
    Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellAreaTargetCheck> searcher(m_caster, targets, check, containerTypeMask);
    SearchTargets<Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellAreaTargetCheck> > (searcher, containerTypeMask, m_caster, position, range);
}

void Spell::SearchChainTargets(std::list<WorldObject*>& targets, uint32 chainTargets, WorldObject* target, SpellTargetObjectTypes objectType, SpellTargetCheckTypes selectType, ConditionContainer* condList, bool isChainHeal)
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

    if (Player* modOwner = m_caster->GetSpellModOwner())
        modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_JUMP_DISTANCE, jumpRadius, this);

    // chain lightning/heal spells and similar - allow to jump at larger distance and go out of los
    bool isBouncingFar = (m_spellInfo->HasAttribute(SPELL_ATTR4_AREA_TARGET_CHAIN)
        || m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_NONE
        || m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MAGIC);

    // max dist which spell can reach
    float searchRadius = jumpRadius;
    if (isBouncingFar)
        searchRadius *= chainTargets;

    std::list<WorldObject*> tempTargets;
    SearchAreaTargets(tempTargets, searchRadius, target, m_caster, objectType, selectType, condList);
    tempTargets.remove(target);

    // remove targets which are always invalid for chain spells
    // for some spells allow only chain targets in front of caster (swipe for example)
    if (!isBouncingFar)
    {
        for (std::list<WorldObject*>::iterator itr = tempTargets.begin(); itr != tempTargets.end();)
        {
            std::list<WorldObject*>::iterator checkItr = itr++;
            if (!m_caster->HasInArc(static_cast<float>(M_PI), *checkItr))
                tempTargets.erase(checkItr);
        }
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
                    if ((deficit > maxHPDeficit || foundItr == tempTargets.end()) && target->IsWithinDist(unit, jumpRadius) && target->IsWithinLOSInMap(unit))
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
                    if ((!isBouncingFar || target->IsWithinDist(*itr, jumpRadius)) && target->IsWithinLOSInMap(*itr))
                        foundItr = itr;
                }
                else if (target->GetDistanceOrder(*itr, *foundItr) && target->IsWithinLOSInMap(*itr))
                    foundItr = itr;
            }
        }
        // not found any valid target - chain ends
        if (foundItr == tempTargets.end())
            break;
        target = *foundItr;
        tempTargets.erase(foundItr);
        targets.push_back(target);
        --chainTargets;
    }
}

GameObject* Spell::SearchSpellFocus()
{
    GameObject* focus = NULL;
    Trinity::GameObjectFocusCheck check(m_caster, m_spellInfo->RequiresSpellFocus);
    Trinity::GameObjectSearcher<Trinity::GameObjectFocusCheck> searcher(m_caster, focus, check);
    SearchTargets<Trinity::GameObjectSearcher<Trinity::GameObjectFocusCheck> > (searcher, GRID_MAP_TYPE_MASK_GAMEOBJECT, m_caster, m_caster, m_caster->GetVisibilityRange());
    return focus;
}

void Spell::prepareDataForTriggerSystem()
{
    //==========================================================================================
    // Now fill data for trigger system, need know:
    // Create base triggers flags for Attacker and Victim (m_procAttacker, m_procVictim and m_hitMask)
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
            if (m_spellInfo->HasAttribute(SPELL_ATTR2_AUTOREPEAT_FLAG))
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
                m_spellInfo->EquippedItemSubClassMask & (1 << ITEM_SUBCLASS_WEAPON_WAND)
                && m_spellInfo->HasAttribute(SPELL_ATTR2_AUTOREPEAT_FLAG)) // Wands auto attack
            {
                m_procAttacker = PROC_FLAG_DONE_RANGED_AUTO_ATTACK;
                m_procVictim   = PROC_FLAG_TAKEN_RANGED_AUTO_ATTACK;
            }
            // For other spells trigger procflags are set in Spell::DoAllEffectOnTarget
            // Because spell positivity is dependant on target
    }
    m_hitMask = PROC_HIT_NONE;

    // Hunter trap spells - activation proc for Lock and Load, Entrapment and Misdirection
    if (m_spellInfo->SpellFamilyName == SPELLFAMILY_HUNTER &&
        (m_spellInfo->SpellFamilyFlags[0] & 0x18 ||         // Freezing and Frost Trap, Freezing Arrow
            m_spellInfo->Id == 57879 ||                     // Snake Trap - done this way to avoid double proc
            m_spellInfo->SpellFamilyFlags[2] & 0x00024000)) // Explosive and Immolation Trap
    {
        m_procAttacker |= PROC_FLAG_DONE_TRAP_ACTIVATION;

        // also fill up other flags (DoAllEffectOnTarget only fills up flag if both are not set)
        m_procAttacker |= PROC_FLAG_DONE_SPELL_MAGIC_DMG_CLASS_NEG;
        m_procVictim |= PROC_FLAG_TAKEN_SPELL_MAGIC_DMG_CLASS_NEG;
    }

    // Hellfire Effect - trigger as DOT
    if (m_spellInfo->SpellFamilyName == SPELLFAMILY_WARLOCK && m_spellInfo->SpellFamilyFlags[0] & 0x00000040)
    {
        m_procAttacker = PROC_FLAG_DONE_PERIODIC;
        m_procVictim   = PROC_FLAG_TAKEN_PERIODIC;
    }
}

void Spell::CleanupTargetList()
{
    m_UniqueTargetInfo.clear();
    m_UniqueGOTargetInfo.clear();
    m_UniqueItemInfo.clear();
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
            uint32 const typeMaskActionTarget = PROC_FLAG_TAKEN_SPELL_MAGIC_DMG_CLASS_NEG | PROC_FLAG_TAKEN_SPELL_NONE_DMG_CLASS_NEG;
            uint32 const spellTypeMask = PROC_SPELL_TYPE_DAMAGE | PROC_SPELL_TYPE_NO_DMG_HEAL;
            uint32 const spellPhaseMask = PROC_SPELL_PHASE_NONE;
            uint32 const hitMask = PROC_HIT_REFLECT;

            caster->ProcSkillsAndAuras(_victim, typeMaskActor, typeMaskActionTarget, spellTypeMask, spellPhaseMask, hitMask, nullptr, nullptr, nullptr);
            return true;
        }

    private:
        Unit* _victim;
        ObjectGuid _casterGuid;
};

void Spell::AddUnitTarget(Unit* target, uint32 effectMask, bool checkIfValid /*= true*/, bool implicit /*= true*/, Position const* losPosition /*= nullptr*/)
{
    uint32 validEffectMask = 0;
    for (SpellEffectInfo const* effect : GetEffects())
        if (effect && (effectMask & (1 << effect->EffectIndex)) != 0 && CheckEffectTarget(target, effect, losPosition))
            validEffectMask |= 1 << effect->EffectIndex;

    effectMask &= validEffectMask;

    // no effects left
    if (!effectMask)
        return;

    if (checkIfValid)
        if (m_spellInfo->CheckTarget(m_caster, target, implicit || m_caster->GetEntry() == WORLD_TRIGGER) != SPELL_CAST_OK) // skip stealth checks for GO casts
            return;

    // Check for effect immune skip if immuned
    for (SpellEffectInfo const* effect : GetEffects())
        if (effect && target->IsImmunedToSpellEffect(m_spellInfo, effect->EffectIndex, m_caster))
            effectMask &= ~(1 << effect->EffectIndex);

    ObjectGuid targetGUID = target->GetGUID();

    // Lookup target in already in list
    for (std::vector<TargetInfo>::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
    {
        if (targetGUID == ihit->targetGUID)             // Found in list
        {
            ihit->effectMask |= effectMask;             // Immune effects removed from mask
            ihit->scaleAura = false;
            if (m_auraScaleMask && ihit->effectMask == m_auraScaleMask && m_caster != target)
            {
                SpellInfo const* auraSpell = m_spellInfo->GetFirstRankSpell();
                if (uint32(target->GetLevelForTarget(m_caster) + 10) >= auraSpell->SpellLevel)
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
    targetInfo.alive      = target->IsAlive();
    targetInfo.damage     = 0;
    targetInfo.crit       = false;
    targetInfo.scaleAura  = false;
    if (m_auraScaleMask && targetInfo.effectMask == m_auraScaleMask && m_caster != target)
    {
        SpellInfo const* auraSpell = m_spellInfo->GetFirstRankSpell();
        if (uint32(target->GetLevelForTarget(m_caster) + 10) >= auraSpell->SpellLevel)
            targetInfo.scaleAura = true;
    }

    // Calculate hit result
    if (m_originalCaster)
    {
        targetInfo.missCondition = m_originalCaster->SpellHitResult(target, m_spellInfo, m_canReflect && !(m_spellInfo->IsPositive() && m_caster->IsFriendlyTo(target)));
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
        /// @todo this is a hack
        float dist = m_caster->GetDistance(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());

        if (dist < 5.0f)
            dist = 5.0f;

        if (!m_spellInfo->HasAttribute(SPELL_ATTR9_SPECIAL_DELAY_CALCULATION))
            targetInfo.timeDelay = uint64(std::floor(dist / m_spellInfo->Speed * 1000.0f));
        else
            targetInfo.timeDelay = uint64(m_spellInfo->Speed * 1000.0f);
    }
    else
        targetInfo.timeDelay = 0ULL;

    // If target reflect spell back to caster
    if (targetInfo.missCondition == SPELL_MISS_REFLECT)
    {
        // Calculate reflected spell result on caster
        targetInfo.reflectResult = m_caster->SpellHitResult(m_caster, m_spellInfo, false); // can't reflect twice

        // Proc spell reflect aura when missile hits the original target
        target->m_Events.AddEvent(new ProcReflectDelayed(target, m_originalCasterGUID), target->m_Events.CalculateTime(targetInfo.timeDelay));

        // Increase time interval for reflected spells by 1.5
        targetInfo.timeDelay += targetInfo.timeDelay >> 1;
    }
    else
        targetInfo.reflectResult = SPELL_MISS_NONE;

    // Calculate minimum incoming time
    if (targetInfo.timeDelay && (!m_delayMoment || m_delayMoment > targetInfo.timeDelay))
        m_delayMoment = targetInfo.timeDelay;

    // Add target to list
    m_UniqueTargetInfo.push_back(targetInfo);
}

void Spell::AddGOTarget(GameObject* go, uint32 effectMask)
{
    uint32 validEffectMask = 0;
    for (SpellEffectInfo const* effect : GetEffects())
        if (effect && (effectMask & (1 << effect->EffectIndex)) != 0 && CheckEffectTarget(go, effect))
            validEffectMask |= 1 << effect->EffectIndex;

    effectMask &= validEffectMask;

    // no effects left
    if (!effectMask)
        return;

    ObjectGuid targetGUID = go->GetGUID();

    // Lookup target in already in list
    for (std::vector<GOTargetInfo>::iterator ihit = m_UniqueGOTargetInfo.begin(); ihit != m_UniqueGOTargetInfo.end(); ++ihit)
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

        if (!m_spellInfo->HasAttribute(SPELL_ATTR9_SPECIAL_DELAY_CALCULATION))
            target.timeDelay = uint64(floor(dist / m_spellInfo->Speed * 1000.0f));
        else
            target.timeDelay = uint64(m_spellInfo->Speed * 1000.0f);

        if (!m_delayMoment || m_delayMoment > target.timeDelay)
            m_delayMoment = target.timeDelay;
    }
    else
        target.timeDelay = 0LL;

    // Add target to list
    m_UniqueGOTargetInfo.push_back(target);
}

void Spell::AddItemTarget(Item* item, uint32 effectMask)
{
    uint32 validEffectMask = 0;
    for (SpellEffectInfo const* effect : GetEffects())
        if (effect && (effectMask & (1 << effect->EffectIndex)) != 0 && CheckEffectTarget(item, effect))
            validEffectMask |= 1 << effect->EffectIndex;

    effectMask &= validEffectMask;

    // no effects left
    if (!effectMask)
        return;

    // Lookup target in already in list
    for (std::vector<ItemTargetInfo>::iterator ihit = m_UniqueItemInfo.begin(); ihit != m_UniqueItemInfo.end(); ++ihit)
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

void Spell::AddDestTarget(SpellDestination const& dest, uint32 effIndex)
{
    m_destTargets[effIndex] = dest;
}

void Spell::DoAllEffectOnTarget(TargetInfo* target)
{
    if (!target || target->processed)
        return;

    target->processed = true;                               // Target checked in apply effects procedure

    // Get mask of effects for target
    uint32 mask = target->effectMask;

    Unit* unit = m_caster->GetGUID() == target->targetGUID ? m_caster : ObjectAccessor::GetUnit(*m_caster, target->targetGUID);
    if (!unit && target->targetGUID.IsPlayer()) // only players may be targeted across maps
    {
        uint32 farMask = 0;
        // create far target mask
        for (SpellEffectInfo const* effect : GetEffects())
            if (effect && effect->IsFarUnitTargetEffect())
                if ((1 << effect->EffectIndex) & mask)
                    farMask |= (1 << effect->EffectIndex);

        if (!farMask)
            return;

        // find unit in world
        unit = ObjectAccessor::FindPlayer(target->targetGUID);
        if (!unit)
            return;

        // do far effects on the unit
        // can't use default call because of threading, do stuff as fast as possible
        for (SpellEffectInfo const* effect : GetEffects())
            if (effect && (farMask & (1 << effect->EffectIndex)))
                HandleEffects(unit, NULL, NULL, effect->EffectIndex, SPELL_EFFECT_HANDLE_HIT_TARGET);
        return;
    }

    if (!unit)
        return;

    if (unit->IsAlive() != target->alive)
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
    targetMissInfo = missInfo;

    // Reset damage/healing counter
    m_damage = target->damage;
    m_healing = -target->damage;

    // Fill base trigger info
    uint32 procAttacker = m_procAttacker;
    uint32 procVictim   = m_procVictim;
    uint32 hitMask = PROC_HIT_NONE;

    m_spellAura = nullptr; // Set aura to null for every target-make sure that pointer is not used for unit without aura applied

                            // Spells with this flag cannot trigger if effect is cast on self
    bool const canEffectTrigger = !m_spellInfo->HasAttribute(SPELL_ATTR3_CANT_TRIGGER_PROC) && unitTarget->CanProc() && (CanExecuteTriggersOnHit(mask) || missInfo == SPELL_MISS_IMMUNE || missInfo == SPELL_MISS_IMMUNE2);
    Unit* spellHitTarget = nullptr;

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

    PrepareScriptHitHandlers();
    CallScriptBeforeHitHandlers(missInfo);

    bool enablePvP = false; // need to check PvP state before spell effects, but act on it afterwards

    if (spellHitTarget)
    {
        // if target is flagged for pvp also flag caster if a player
        if (unit->IsPvP() && m_caster->GetTypeId() == TYPEID_PLAYER)
            enablePvP = true; // Decide on PvP flagging now, but act on it later.

        SpellMissInfo missInfo2 = DoSpellHitOnUnit(spellHitTarget, mask, target->scaleAura);

        if (missInfo2 != SPELL_MISS_NONE)
        {
            if (missInfo2 != SPELL_MISS_MISS)
                m_caster->SendSpellMiss(unit, m_spellInfo->Id, missInfo2);
            m_damage = 0;
            spellHitTarget = nullptr;
        }
    }

    // Do not take combo points on dodge and miss
    if (missInfo != SPELL_MISS_NONE && m_needComboPoints && m_targets.GetUnitTargetGUID() == target->targetGUID)
        m_needComboPoints = false;

    // Trigger info was not filled in Spell::prepareDataForTriggerSystem - we do it now
    if (canEffectTrigger && !procAttacker && !procVictim)
    {
        bool positive = true;
        if (m_damage > 0)
            positive = false;
        else if (!m_healing)
        {
            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            {
                if (!(target->effectMask & (1 << i)))
                    continue;

                if (!m_spellInfo->IsPositiveEffect(i))
                {
                    positive = false;
                    break;
                }
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
        bool crit = target->crit;
        uint32 addhealth = m_healing;
        if (crit)
        {
            hitMask |= PROC_HIT_CRITICAL;
            addhealth = caster->SpellCriticalHealingBonus(m_spellInfo, addhealth, nullptr);
        }
        else
            hitMask |= PROC_HIT_NORMAL;

        HealInfo healInfo(caster, unitTarget, addhealth, m_spellInfo, m_spellInfo->GetSchoolMask());
        caster->HealBySpell(healInfo, crit);
        unitTarget->getHostileRefManager().threatAssist(caster, float(healInfo.GetEffectiveHeal()) * 0.5f, m_spellInfo);
        m_healing = healInfo.GetEffectiveHeal();

        // Do triggers for unit
        if (canEffectTrigger)
            caster->ProcSkillsAndAuras(unitTarget, procAttacker, procVictim, PROC_SPELL_TYPE_HEAL, PROC_SPELL_PHASE_HIT, hitMask, this, nullptr, &healInfo);
    }
    // Do damage and triggers
    else if (m_damage > 0)
    {
        // Fill base damage struct (unitTarget - is real spell target)
        SpellNonMeleeDamage damageInfo(caster, unitTarget, m_spellInfo->Id, m_SpellVisual, m_spellSchoolMask, m_castId);

        // Check damage immunity
        if (unitTarget->IsImmunedToDamage(m_spellInfo))
        {
            hitMask = PROC_HIT_IMMUNE;
            m_damage = 0;

            // no packet found in sniffs
        }
        else
        {
            // Add bonuses and fill damageInfo struct
            caster->CalculateSpellDamageTaken(&damageInfo, m_damage, m_spellInfo, m_attackType, target->crit);
            caster->DealDamageMods(damageInfo.target, damageInfo.damage, &damageInfo.absorb);

            hitMask |= createProcHitMask(&damageInfo, missInfo);
            procVictim |= PROC_FLAG_TAKEN_DAMAGE;

            m_damage = damageInfo.damage;

            caster->DealSpellDamage(&damageInfo, true);

            // Send log damage message to client
            caster->SendSpellNonMeleeDamageLog(&damageInfo);
        }

        // Do triggers for unit
        if (canEffectTrigger)
        {
            DamageInfo spellDamageInfo(damageInfo, SPELL_DIRECT_DAMAGE, m_attackType, hitMask);
            caster->ProcSkillsAndAuras(unitTarget, procAttacker, procVictim, PROC_SPELL_TYPE_DAMAGE, PROC_SPELL_PHASE_HIT, hitMask, this, &spellDamageInfo, nullptr);

            if (caster->GetTypeId() == TYPEID_PLAYER && !m_spellInfo->HasAttribute(SPELL_ATTR0_STOP_ATTACK_TARGET) &&
               (m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MELEE || m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_RANGED))
                caster->ToPlayer()->CastItemCombatSpell(spellDamageInfo);
        }
    }
    // Passive spell hits/misses or active spells only misses (only triggers)
    else
    {
        // Fill base damage struct (unitTarget - is real spell target)
        SpellNonMeleeDamage damageInfo(caster, unitTarget, m_spellInfo->Id, m_SpellVisual, m_spellSchoolMask);
        hitMask |= createProcHitMask(&damageInfo, missInfo);
        // Do triggers for unit
        if (canEffectTrigger)
        {
            DamageInfo spellNoDamageInfo(damageInfo, NODAMAGE, m_attackType, hitMask);
            caster->ProcSkillsAndAuras(unitTarget, procAttacker, procVictim, PROC_SPELL_TYPE_NO_DMG_HEAL, PROC_SPELL_PHASE_HIT, hitMask, this, &spellNoDamageInfo, nullptr);

            if (caster->GetTypeId() == TYPEID_PLAYER && !m_spellInfo->HasAttribute(SPELL_ATTR0_STOP_ATTACK_TARGET) &&
                (m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MELEE || m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_RANGED))
                caster->ToPlayer()->CastItemCombatSpell(spellNoDamageInfo);
        }

        // Failed Pickpocket, reveal rogue
        if (missInfo == SPELL_MISS_RESIST && m_spellInfo->HasAttribute(SPELL_ATTR0_CU_PICKPOCKET) && unitTarget->GetTypeId() == TYPEID_UNIT)
        {
            m_caster->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TALK);
            if (unitTarget->ToCreature()->IsAIEnabled)
                unitTarget->ToCreature()->AI()->AttackStart(m_caster);
        }
    }

    // set hitmask for finish procs
    m_hitMask |= hitMask;

    // spellHitTarget can be null if spell is missed in DoSpellHitOnUnit
    if (missInfo != SPELL_MISS_EVADE && spellHitTarget && !m_caster->IsFriendlyTo(unit) && (!m_spellInfo->IsPositive() || m_spellInfo->HasEffect(SPELL_EFFECT_DISPEL)))
    {
        m_caster->CombatStart(unit, m_spellInfo->HasInitialAggro());

        if (!unit->IsStandState())
            unit->SetStandState(UNIT_STAND_STATE_STAND);
    }

    // Check for SPELL_ATTR7_INTERRUPT_ONLY_NONPLAYER
    if (missInfo == SPELL_MISS_NONE && m_spellInfo->HasAttribute(SPELL_ATTR7_INTERRUPT_ONLY_NONPLAYER) && unit->GetTypeId() != TYPEID_PLAYER)
        caster->CastSpell(unit, SPELL_INTERRUPT_NONPLAYER, true);

    if (spellHitTarget)
    {
        //AI functions
        if (spellHitTarget->GetTypeId() == TYPEID_UNIT)
            if (spellHitTarget->ToCreature()->IsAIEnabled)
                spellHitTarget->ToCreature()->AI()->SpellHit(m_caster, m_spellInfo);

        if (m_caster->GetTypeId() == TYPEID_UNIT && m_caster->ToCreature()->IsAIEnabled)
            m_caster->ToCreature()->AI()->SpellHitTarget(spellHitTarget, m_spellInfo);

        // Needs to be called after dealing damage/healing to not remove breaking on damage auras
        DoTriggersOnSpellHit(spellHitTarget, mask);

        if (enablePvP)
            m_caster->ToPlayer()->UpdatePvP(true);

        CallScriptAfterHitHandlers();
    }
}

SpellMissInfo Spell::DoSpellHitOnUnit(Unit* unit, uint32 effectMask, bool scaleAura)
{
    if (!unit || !effectMask)
        return SPELL_MISS_EVADE;

    // For delayed spells immunity may be applied between missile launch and hit - check immunity for that case
    if (m_spellInfo->Speed && unit->IsImmunedToSpell(m_spellInfo, m_caster))
        return SPELL_MISS_IMMUNE;

    // disable effects to which unit is immune
    SpellMissInfo returnVal = SPELL_MISS_IMMUNE;
    for (SpellEffectInfo const* effect : GetEffects())
        if (effect && (effectMask & (1 << effect->EffectIndex)))
            if (unit->IsImmunedToSpellEffect(m_spellInfo, effect->EffectIndex, m_caster))
                effectMask &= ~(1 << effect->EffectIndex);

    if (!effectMask)
        return returnVal;

    if (Player* player = unit->ToPlayer())
    {
        player->StartCriteriaTimer(CRITERIA_TIMED_TYPE_SPELL_TARGET, m_spellInfo->Id);
        player->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, m_spellInfo->Id, 0, 0, m_caster);
        player->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET2, m_spellInfo->Id);
    }

    if (Player* player = m_caster->ToPlayer())
    {
        player->StartCriteriaTimer(CRITERIA_TIMED_TYPE_SPELL_CASTER, m_spellInfo->Id);
        player->UpdateCriteria(CRITERIA_TYPE_CAST_SPELL2, m_spellInfo->Id, 0, 0, unit);
    }

    if (m_caster != unit)
    {
        // Recheck  UNIT_FLAG_NON_ATTACKABLE for delayed spells
        if (m_spellInfo->Speed > 0.0f && unit->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE) && unit->GetCharmerOrOwnerGUID() != m_caster->GetGUID())
            return SPELL_MISS_EVADE;

        if (m_caster->_IsValidAttackTarget(unit, m_spellInfo))
            unit->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_HITBYSPELL);
        else if (m_caster->IsFriendlyTo(unit))
        {
            // for delayed spells ignore negative spells (after duel end) for friendly targets
            /// @todo this cause soul transfer bugged
            // 63881 - Malady of the Mind jump spell (Yogg-Saron)
            if (m_spellInfo->Speed > 0.0f && unit->GetTypeId() == TYPEID_PLAYER && !m_spellInfo->IsPositive() && m_spellInfo->Id != 63881)
                return SPELL_MISS_EVADE;

            // assisting case, healing and resurrection
            if (unit->HasUnitState(UNIT_STATE_ATTACK_PLAYER))
            {
                m_caster->SetContestedPvP();
                if (m_caster->GetTypeId() == TYPEID_PLAYER)
                    m_caster->ToPlayer()->UpdatePvP(true);
            }
            if (unit->IsInCombat() && m_spellInfo->HasInitialAggro())
            {
                m_caster->SetInCombatState(unit->GetCombatTimer() > 0, unit);
                unit->getHostileRefManager().threatAssist(m_caster, 0.0f);
            }
        }
    }

    uint32 aura_effmask = 0;
    for (SpellEffectInfo const* effect : GetEffects())
        if (effect && (effectMask & (1 << effect->EffectIndex) && effect->IsUnitOwnedAuraEffect()))
            aura_effmask |= 1 << effect->EffectIndex;

    // Get Data Needed for Diminishing Returns, some effects may have multiple auras, so this must be done on spell hit, not aura add
    DiminishingGroup const diminishGroup = m_spellInfo->GetDiminishingReturnsGroupForSpell();

    DiminishingLevels diminishLevel = DIMINISHING_LEVEL_1;
    if (diminishGroup && aura_effmask)
    {
        diminishLevel = unit->GetDiminishing(diminishGroup);
        DiminishingReturnsType type = m_spellInfo->GetDiminishingReturnsGroupType();
        // Increase Diminishing on unit, current informations for actually casts will use values above
        if ((type == DRTYPE_PLAYER &&
            (unit->GetCharmerOrOwnerPlayerOrPlayerItself() || (unit->GetTypeId() == TYPEID_UNIT && unit->ToCreature()->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_ALL_DIMINISH))) ||
            type == DRTYPE_ALL)
            unit->IncrDiminishing(m_spellInfo);
    }

    if (aura_effmask)
    {
        // Select rank for aura with level requirements only in specific cases
        // Unit has to be target only of aura effect, both caster and target have to be players, target has to be other than unit target
        SpellInfo const* aurSpellInfo = m_spellInfo;
        int32 basePoints[MAX_SPELL_EFFECTS];
        if (scaleAura)
        {
            aurSpellInfo = m_spellInfo->GetAuraRankForLevel(unitTarget->getLevel());
            ASSERT(aurSpellInfo);
            for (SpellEffectInfo const* effect : aurSpellInfo->GetEffectsForDifficulty(0))
            {
                basePoints[effect->EffectIndex] = effect->BasePoints;
                if (SpellEffectInfo const* myEffect = GetEffect(effect->EffectIndex))
                {
                    if (myEffect->Effect != effect->Effect)
                    {
                        aurSpellInfo = m_spellInfo;
                        break;
                    }
                }
            }
        }

        if (m_originalCaster)
        {
            bool refresh = false;
            bool const resetPeriodicTimer = !(_triggeredCastFlags & TRIGGERED_DONT_RESET_PERIODIC_TIMER);
            m_spellAura = Aura::TryRefreshStackOrCreate(aurSpellInfo, m_castId, effectMask, unit,
                m_originalCaster, (aurSpellInfo == m_spellInfo) ? m_spellValue->EffectBasePoints : basePoints,
                m_CastItem, ObjectGuid::Empty, &refresh, resetPeriodicTimer, ObjectGuid::Empty, m_castItemLevel);
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
                float diminishMod = unit->ApplyDiminishingToDuration(aurSpellInfo, duration, m_originalCaster, diminishLevel);

                // unit is immune to aura if it was diminished to 0 duration
                if (diminishMod == 0.0f)
                {
                    m_spellAura->Remove();
                    bool found = false;
                    for (SpellEffectInfo const* effect : GetEffects())
                        if (effect && (effectMask & (1 << effect->EffectIndex) && effect->Effect != SPELL_EFFECT_APPLY_AURA))
                            found = true;
                    if (!found)
                        return SPELL_MISS_IMMUNE;
                }
                else
                {
                    ((UnitAura*)m_spellAura)->SetDiminishGroup(diminishGroup);

                    bool positive = m_spellAura->GetSpellInfo()->IsPositive();
                    if (AuraApplication* aurApp = m_spellAura->GetApplicationOfTarget(m_originalCaster->GetGUID()))
                        positive = aurApp->IsPositive();

                    duration = m_originalCaster->ModSpellDuration(aurSpellInfo, unit, duration, positive, effectMask);

                    if (duration > 0)
                    {
                        // Haste modifies duration of channeled spells
                        if (m_spellInfo->IsChanneled())
                            m_originalCaster->ModSpellDurationTime(aurSpellInfo, duration, this);
                        else if (m_spellInfo->HasAttribute(SPELL_ATTR5_HASTE_AFFECT_DURATION))
                        {
                            int32 origDuration = duration;
                            duration = 0;
                            for (SpellEffectInfo const* effect : GetEffects())
                                if (effect)
                                    if (AuraEffect const* eff = m_spellAura->GetEffect(effect->EffectIndex))
                                        if (int32 period = eff->GetPeriod())  // period is hastened by UNIT_MOD_CAST_SPEED
                                            duration = std::max(std::max(origDuration / period, 1) * period, duration);

                            // if there is no periodic effect
                            if (!duration)
                                duration = int32(origDuration * m_originalCaster->GetFloatValue(UNIT_MOD_CAST_SPEED));
                        }
                    }

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

    for (SpellEffectInfo const* effect : GetEffects())
        if (effect && (effectMask & (1 << effect->EffectIndex)))
            HandleEffects(unit, NULL, NULL, effect->EffectIndex, SPELL_EFFECT_HANDLE_HIT_TARGET);

    return SPELL_MISS_NONE;
}

void Spell::DoTriggersOnSpellHit(Unit* unit, uint32 effMask)
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
            if (CanExecuteTriggersOnHit(effMask, i->triggeredByAura) && roll_chance_i(i->chance))
            {
                m_caster->CastSpell(unit, i->triggeredSpell, TRIGGERED_FULL_MASK);
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
                unit->CastSpell(unit, *i, true, nullptr, nullptr, m_caster->GetGUID());
        }
    }
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
    CallScriptBeforeHitHandlers(SPELL_MISS_NONE);

    for (SpellEffectInfo const* effect : GetEffects())
        if (effect && (effectMask & (1 << effect->EffectIndex)))
            HandleEffects(NULL, NULL, go, effect->EffectIndex, SPELL_EFFECT_HANDLE_HIT_TARGET);

    CallScriptOnHitHandlers();
    CallScriptAfterHitHandlers();
}

void Spell::DoAllEffectOnTarget(ItemTargetInfo* target)
{
    uint32 effectMask = target->effectMask;
    if (!target->item || !effectMask)
        return;

    PrepareScriptHitHandlers();
    CallScriptBeforeHitHandlers(SPELL_MISS_NONE);

    for (SpellEffectInfo const* effect : GetEffects())
        if (effect && (effectMask & (1 << effect->EffectIndex)))
            HandleEffects(NULL, target->item, NULL, effect->EffectIndex, SPELL_EFFECT_HANDLE_HIT_TARGET);

    CallScriptOnHitHandlers();

    CallScriptAfterHitHandlers();
}

bool Spell::UpdateChanneledTargetList()
{
    // Not need check return true
    if (m_channelTargetEffectMask == 0)
        return true;

    uint32 channelTargetEffectMask = m_channelTargetEffectMask;
    uint32 channelAuraMask = 0;
    for (SpellEffectInfo const* effect : GetEffects())
        if (effect && effect->Effect == SPELL_EFFECT_APPLY_AURA)
            channelAuraMask |= 1 << effect->EffectIndex;

    channelAuraMask &= channelTargetEffectMask;

    float range = 0;
    if (channelAuraMask)
    {
        range = m_spellInfo->GetMaxRange(m_spellInfo->IsPositive());
        if (Player* modOwner = m_caster->GetSpellModOwner())
            modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RANGE, range, this);
    }

    for (std::vector<TargetInfo>::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
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

void Spell::prepare(SpellCastTargets const* targets, AuraEffect const* triggeredByAura)
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
            return;
        }
    }

    InitExplicitTargets(*targets);

    // Fill aura scaling information
    if (m_caster->IsControlledByPlayer() && !m_spellInfo->IsPassive() && m_spellInfo->SpellLevel && !m_spellInfo->IsChanneled() && !(_triggeredCastFlags & TRIGGERED_IGNORE_AURA_SCALING))
    {
        for (SpellEffectInfo const* effect : GetEffects())
        {
            if (effect && effect->Effect == SPELL_EFFECT_APPLY_AURA)
            {
                // Change aura with ranks only if basepoints are taken from spellInfo and aura is positive
                if (m_spellInfo->IsPositiveEffect(effect->EffectIndex))
                {
                    m_auraScaleMask |= (1 << effect->EffectIndex);
                    if (m_spellValue->EffectBasePoints[effect->EffectIndex] != effect->BasePoints)
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
    {
        m_triggeredByAuraSpell = triggeredByAura->GetSpellInfo();
        m_castItemLevel = triggeredByAura->GetBase()->GetCastItemLevel();
    }

    // create and add update event for this spell
    SpellEvent* Event = new SpellEvent(this);
    m_caster->m_Events.AddEvent(Event, m_caster->m_Events.CalculateTime(1));

    //Prevent casting at cast another spell (ServerSide check)
    if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CAST_IN_PROGRESS) && m_caster->IsNonMeleeSpellCast(false, true, true) && !m_castId.IsEmpty())
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
    // Fill cost data (do not use power for item casts)
    if (!m_CastItem)
        m_powerCost = m_spellInfo->CalcPowerCost(m_caster, m_spellSchoolMask);
    if (m_caster->GetTypeId() == TYPEID_PLAYER)
        m_caster->ToPlayer()->SetSpellModTakingSpell(this, false);

    // Set combo point requirement
    if ((_triggeredCastFlags & TRIGGERED_IGNORE_COMBO_POINTS) || m_CastItem || !m_caster->m_playerMovingMe)
        m_needComboPoints = false;

    uint32 param1 = 0, param2 = 0;
    SpellCastResult result = CheckCast(true, &param1, &param2);
    // target is checked in too many locations and with different results to handle each of them
    // handle just the general SPELL_FAILED_BAD_TARGETS result which is the default result for most DBC target checks
    if (_triggeredCastFlags & TRIGGERED_IGNORE_TARGET_CHECK && result == SPELL_FAILED_BAD_TARGETS)
        result = SPELL_CAST_OK;
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

        // cleanup after mod system
        // triggered spell pointer can be not removed in some cases
        if (m_caster->GetTypeId() == TYPEID_PLAYER)
            m_caster->ToPlayer()->SetSpellModTakingSpell(this, false);

        if (param1 || param2)
            SendCastResult(result, &param1, &param2);
        else
            SendCastResult(result);

        finish(false);
        return;
    }

    // Prepare data for triggers
    prepareDataForTriggerSystem();

    if (Player* player = m_caster->ToPlayer())
    {
        if (!player->GetCommandStatus(CHEAT_CASTTIME))
        {
            player->SetSpellModTakingSpell(this, true);
            // calculate cast time (calculated after first CheckCast check to prevent charge counting for first CheckCast fail)
            m_casttime = m_spellInfo->CalcCastTime(player->getLevel(), this);
            player->SetSpellModTakingSpell(this, false);
        }
        else
            m_casttime = 0; // Set cast time to 0 if .cheat casttime is enabled.
    }
    else
        m_casttime = m_spellInfo->CalcCastTime(m_caster->getLevel(), this);

    if (m_caster->GetTypeId() == TYPEID_UNIT && !m_caster->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED)) // _UNIT actually means creature. for some reason.
        if (!(m_spellInfo->IsNextMeleeSwingSpell() || IsAutoRepeat() || (_triggeredCastFlags & TRIGGERED_IGNORE_SET_FACING)))
        {
            if (m_targets.GetObjectTarget() && m_caster != m_targets.GetObjectTarget())
                m_caster->ToCreature()->FocusTarget(this, m_targets.GetObjectTarget());
            else if (m_spellInfo->HasAttribute(SPELL_ATTR5_DONT_TURN_DURING_CAST))
                m_caster->ToCreature()->FocusTarget(this, nullptr);
        }

    // don't allow channeled spells / spells with cast time to be cast while moving
    // exception are only channeled spells that have no casttime and SPELL_ATTR5_CAN_CHANNEL_WHEN_MOVING
    // (even if they are interrupted on moving, spells with almost immediate effect get to have their effect processed before movement interrupter kicks in)
    // don't cancel spells which are affected by a SPELL_AURA_CAST_WHILE_WALKING effect
    if (((m_spellInfo->IsChanneled() || m_casttime) && m_caster->GetTypeId() == TYPEID_PLAYER && !(m_caster->IsCharmed() && m_caster->GetCharmerGUID().IsCreature()) && m_caster->isMoving() &&
        m_spellInfo->InterruptFlags & SPELL_INTERRUPT_FLAG_MOVEMENT) && !m_caster->HasAuraTypeWithAffectMask(SPELL_AURA_CAST_WHILE_WALKING, m_spellInfo))
    {
        // 1. Has casttime, 2. Or doesn't have flag to allow movement during channel
        if (m_casttime || !m_spellInfo->IsMoveAllowedChannel())
        {
            SendCastResult(SPELL_FAILED_MOVING);
            finish(false);
            return;
        }
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
        // stealth must be removed at cast starting (at show channel bar)
        // skip triggered spell (item equip spell casting and other not explicit character casts/item uses)
        if (!(_triggeredCastFlags & TRIGGERED_IGNORE_AURA_INTERRUPT_FLAGS) && m_spellInfo->IsBreakingStealth())
        {
            m_caster->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_CAST);
            for (SpellEffectInfo const* effect : GetEffects())
                if (effect && effect->GetUsedTargetObjectType() == TARGET_OBJECT_TYPE_UNIT)
                {
                    m_caster->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_SPELL_ATTACK);
                    break;
                }
        }

        m_caster->SetCurrentCastSpell(this);
        SendSpellStart();

        if (!(_triggeredCastFlags & TRIGGERED_IGNORE_GCD))
            TriggerGlobalCooldown();

        //item: first cast may destroy item and second cast causes crash
        // commented out !m_spellInfo->StartRecoveryTime, it forces instant spells with global cooldown to be processed in spell::update
        // as a result a spell that passed CheckCast and should be processed instantly may suffer from this delayed process
        // the easiest bug to observe is LoS check in AddUnitTarget, even if spell passed the CheckCast LoS check the situation can change in spell::update
        // because target could be relocated in the meantime, making the spell fly to the air (no targets can be registered, so no effects processed, nothing in combat log)
        if (!m_casttime && /*!m_spellInfo->StartRecoveryTime && */!m_castItemGUID && GetCurrentContainer() == CURRENT_GENERIC_SPELL)
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
            // no break
        case SPELL_STATE_DELAYED:
            SendInterrupted(0);
            SendCastResult(SPELL_FAILED_INTERRUPTED);
            break;

        case SPELL_STATE_CASTING:
            for (std::vector<TargetInfo>::const_iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
                if ((*ihit).missCondition == SPELL_MISS_NONE)
                    if (Unit* unit = m_caster->GetGUID() == ihit->targetGUID ? m_caster : ObjectAccessor::GetUnit(*m_caster, ihit->targetGUID))
                        unit->RemoveOwnedAura(m_spellInfo->Id, m_originalCasterGUID, 0, AURA_REMOVE_BY_CANCEL);

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
        *m_selfContainer = NULL;

    m_caster->RemoveDynObject(m_spellInfo->Id);
    if (m_spellInfo->IsChanneled()) // if not channeled then the object for the current cast wasn't summoned yet
        m_caster->RemoveGameObject(m_spellInfo->Id, true);

    //set state back so finish will be processed
    m_spellState = oldState;

    finish(false);
}

void Spell::cast(bool skipCheck)
{
    // update pointers base at GUIDs to prevent access to non-existed already object
    if (!UpdatePointers())
    {
        // cancel the spell if UpdatePointers() returned false, something wrong happened there
        cancel();
        return;
    }

    // cancel at lost explicit target during cast
    if (!m_targets.GetObjectTargetGUID().IsEmpty() && !m_targets.GetObjectTarget())
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
            if (Pet* playerPet = playerCaster->GetPet())
                if (playerPet->IsAlive() && playerPet->isControlled() && (m_targets.GetTargetMask() & TARGET_FLAG_UNIT))
                    playerPet->AI()->OwnerAttacked(m_targets.GetUnitTarget());
    }

    SetExecutedCurrently(true);

    if (!(_triggeredCastFlags & TRIGGERED_IGNORE_SET_FACING))
        if (m_caster->GetTypeId() == TYPEID_UNIT && m_targets.GetObjectTarget() && m_caster != m_targets.GetObjectTarget())
            m_caster->SetInFront(m_targets.GetObjectTarget());

    // Should this be done for original caster?
    if (m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        // Set spell which will drop charges for triggered cast spells
        // if not successfully cast, will be remove in finish(false)
        m_caster->ToPlayer()->SetSpellModTakingSpell(this, true);
    }

    CallScriptBeforeCastHandlers();

    // skip check if done already (for instant cast spells for example)
    if (!skipCheck)
    {
        uint32 param1 = 0, param2 = 0;
        SpellCastResult castResult = CheckCast(false, &param1, &param2);
        if (castResult != SPELL_CAST_OK)
        {
            SendCastResult(castResult, &param1, &param2);
            SendInterrupted(0);

            // cleanup after mod system
            // triggered spell pointer can be not removed in some cases
            if (m_caster->GetTypeId() == TYPEID_PLAYER)
                m_caster->ToPlayer()->SetSpellModTakingSpell(this, false);

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
                        // Spell will be cast after completing the trade. Silently ignore at this place
                        my_trade->SetSpell(m_spellInfo->Id, m_CastItem);
                        SendCastResult(SPELL_FAILED_DONT_REPORT);
                        SendInterrupted(0);

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

    // if the spell allows the creature to turn while casting, then adjust server-side orientation to face the target now
    // client-side orientation is handled by the client itself, as the cast target is targeted due to Creature::FocusTarget
    if (m_caster->GetTypeId() == TYPEID_UNIT && !m_caster->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED))
        if (!m_spellInfo->HasAttribute(SPELL_ATTR5_DONT_TURN_DURING_CAST))
            if (WorldObject* objTarget = m_targets.GetObjectTarget())
                m_caster->SetInFront(objTarget);

    SelectSpellTargets();

    // Spell may be finished after target map check
    if (m_spellState == SPELL_STATE_FINISHED)
    {
        SendInterrupted(0);

        // cleanup after mod system
        // triggered spell pointer can be not removed in some cases
        if (m_caster->GetTypeId() == TYPEID_PLAYER)
            m_caster->ToPlayer()->SetSpellModTakingSpell(this, false);

        finish(false);
        SetExecutedCurrently(false);
        return;
    }

    if (m_spellInfo->HasAttribute(SPELL_ATTR1_DISMISS_PET))
        if (Creature* pet = ObjectAccessor::GetCreature(*m_caster, m_caster->GetPetGUID()))
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
            player->StartCriteriaTimer(CRITERIA_TIMED_TYPE_ITEM, m_CastItem->GetEntry());
            player->UpdateCriteria(CRITERIA_TYPE_USE_ITEM, m_CastItem->GetEntry());
        }

        player->UpdateCriteria(CRITERIA_TYPE_CAST_SPELL, m_spellInfo->Id);
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

    // CAST SPELL
    SendSpellCooldown();

    PrepareScriptHitHandlers();

    HandleLaunchPhase();

    // we must send smsg_spell_go packet before m_castItem delete in TakeCastItem()...
    SendSpellGo();

    // Okay, everything is prepared. Now we need to distinguish between immediate and evented delayed spells
    if ((m_spellInfo->Speed > 0.0f && !m_spellInfo->IsChanneled()) || m_spellInfo->HasAttribute(SPELL_ATTR4_UNK4))
    {
        // Remove used for cast item if need (it can be already NULL after TakeReagents call
        // in case delayed spell remove item at cast delay start
        TakeCastItem();

        // Okay, maps created, now prepare flags
        m_immediateHandled = false;
        m_spellState = SPELL_STATE_DELAYED;
        SetDelayStart(0);

        if (m_caster->HasUnitState(UNIT_STATE_CASTING) && !m_caster->IsNonMeleeSpellCast(false, false, true))
            m_caster->ClearUnitState(UNIT_STATE_CASTING);
    }
    else
    {
        // Immediate spell, no big deal
        handle_immediate();
    }

    CallScriptAfterCastHandlers();

    if (const std::vector<int32> *spell_triggered = sSpellMgr->GetSpellLinked(m_spellInfo->Id))
    {
        for (std::vector<int32>::const_iterator i = spell_triggered->begin(); i != spell_triggered->end(); ++i)
            if (*i < 0)
                m_caster->RemoveAurasDueToSpell(-(*i));
            else
                m_caster->CastSpell(m_targets.GetUnitTarget() ? m_targets.GetUnitTarget() : m_caster, *i, true);
    }

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        m_caster->ToPlayer()->SetSpellModTakingSpell(this, false);

        //Clear spell cooldowns after every spell is cast if .cheat cooldown is enabled.
        if (m_caster->ToPlayer()->GetCommandStatus(CHEAT_COOLDOWN))
        {
            m_caster->GetSpellHistory()->ResetCooldown(m_spellInfo->Id, true);
            m_caster->GetSpellHistory()->RestoreCharge(m_spellInfo->ChargeCategoryId);
        }
    }

    SetExecutedCurrently(false);

    if (Creature* creatureCaster = m_caster->ToCreature())
        creatureCaster->ReleaseFocus(this);

    if (!m_originalCaster)
        return;

    // Handle procs on cast
    uint32 procAttacker = m_procAttacker;
    if (!procAttacker)
    {
        if (m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MAGIC)
            procAttacker = m_spellInfo->IsPositive() ? PROC_FLAG_DONE_SPELL_MAGIC_DMG_CLASS_POS : PROC_FLAG_DONE_SPELL_MAGIC_DMG_CLASS_NEG;
        else
            procAttacker = m_spellInfo->IsPositive() ? PROC_FLAG_DONE_SPELL_NONE_DMG_CLASS_POS : PROC_FLAG_DONE_SPELL_NONE_DMG_CLASS_NEG;
    }

    uint32 hitMask = m_hitMask;
    if (!(hitMask & PROC_HIT_CRITICAL))
        hitMask |= PROC_HIT_NORMAL;

    m_originalCaster->ProcSkillsAndAuras(nullptr, procAttacker, PROC_FLAG_NONE, PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_CAST, hitMask, this, nullptr, nullptr);

    // Call CreatureAI hook OnSuccessfulSpellCast
    if (Creature* caster = m_originalCaster->ToCreature())
        if (caster->IsAIEnabled)
            caster->AI()->OnSuccessfulSpellCast(GetSpellInfo());
}

void Spell::handle_immediate()
{
    // start channeling if applicable
    if (m_spellInfo->IsChanneled())
    {
        int32 duration = m_spellInfo->GetDuration();
        if (duration > 0)
        {
            // First mod_duration then haste - see Missile Barrage
            // Apply duration mod
            if (Player* modOwner = m_caster->GetSpellModOwner())
                modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_DURATION, duration);

            // Apply haste mods
            m_caster->ModSpellDurationTime(m_spellInfo, duration, this);

            m_spellState = SPELL_STATE_CASTING;
            m_caster->AddInterruptMask(m_spellInfo->ChannelInterruptFlags);
            m_channeledDuration = duration;
            SendChannelStart(duration);
        }
        else if (duration == -1)
        {
            m_spellState = SPELL_STATE_CASTING;
            m_caster->AddInterruptMask(m_spellInfo->ChannelInterruptFlags);
            SendChannelStart(duration);
        }
    }

    PrepareTargetProcessing();

    // process immediate effects (items, ground, etc.) also initialize some variables
    _handle_immediate_phase();

    for (std::vector<TargetInfo>::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
        DoAllEffectOnTarget(&(*ihit));

    for (std::vector<GOTargetInfo>::iterator ihit = m_UniqueGOTargetInfo.begin(); ihit != m_UniqueGOTargetInfo.end(); ++ihit)
        DoAllEffectOnTarget(&(*ihit));

    FinishTargetProcessing();

    // spell is finished, perform some last features of the spell here
    _handle_finish_phase();

    // Remove used for cast item if need (it can be already NULL after TakeReagents call
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
    for (std::vector<TargetInfo>::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
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
    for (std::vector<GOTargetInfo>::iterator ighit = m_UniqueGOTargetInfo.begin(); ighit != m_UniqueGOTargetInfo.end(); ++ighit)
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

    // handle effects with SPELL_EFFECT_HANDLE_HIT mode
    for (SpellEffectInfo const* effect : GetEffects())
    {
        // don't do anything for empty effect
        if (!effect || !effect->IsEffect())
            continue;

        // call effect handlers to handle destination hit
        HandleEffects(NULL, NULL, NULL, effect->EffectIndex, SPELL_EFFECT_HANDLE_HIT);
    }

    // process items
    for (std::vector<ItemTargetInfo>::iterator ihit = m_UniqueItemInfo.begin(); ihit != m_UniqueItemInfo.end(); ++ihit)
        DoAllEffectOnTarget(&(*ihit));
}

void Spell::_handle_finish_phase()
{
    if (m_caster->m_playerMovingMe)
    {
        // Take for real after all targets are processed
        if (m_needComboPoints)
            m_caster->m_playerMovingMe->ClearComboPoints();

        // Real add combo points from effects
        if (m_comboPointGain)
            m_caster->m_playerMovingMe->GainSpellComboPoints(m_comboPointGain);
    }

    if (m_caster->m_extraAttacks && HasEffect(SPELL_EFFECT_ADD_EXTRA_ATTACKS))
    {
        if (Unit* victim = ObjectAccessor::GetUnit(*m_caster, m_targets.GetOrigUnitTargetGUID()))
            m_caster->HandleProcExtraAttackFor(victim);
        else
            m_caster->m_extraAttacks = 0;
    }

    // Handle procs on finish
    if (!m_originalCaster)
        return;

    uint32 procAttacker = m_procAttacker;
    if (!procAttacker)
    {
        if (m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MAGIC)
            procAttacker = m_spellInfo->IsPositive() ? PROC_FLAG_DONE_SPELL_MAGIC_DMG_CLASS_POS : PROC_FLAG_DONE_SPELL_MAGIC_DMG_CLASS_NEG;
        else
            procAttacker = m_spellInfo->IsPositive() ? PROC_FLAG_DONE_SPELL_NONE_DMG_CLASS_POS : PROC_FLAG_DONE_SPELL_NONE_DMG_CLASS_NEG;
    }

    m_originalCaster->ProcSkillsAndAuras(nullptr, procAttacker, PROC_FLAG_NONE, PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_FINISH, m_hitMask, this, nullptr, nullptr);
}

void Spell::SendSpellCooldown()
{
    if (m_CastItem)
        m_caster->GetSpellHistory()->HandleCooldowns(m_spellInfo, m_CastItem, this);
    else
        m_caster->GetSpellHistory()->HandleCooldowns(m_spellInfo, m_castItemEntry, this);
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

    if (!m_targets.GetUnitTargetGUID().IsEmpty() && !m_targets.GetUnitTarget())
    {
        TC_LOG_DEBUG("spells", "Spell %u is cancelled due to removal of target.", m_spellInfo->Id);
        cancel();
        return;
    }

    // check if the player caster has moved before the spell finished
    // with the exception of spells affected with SPELL_AURA_CAST_WHILE_WALKING effect
    SpellEffectInfo const* effect = GetEffect(EFFECT_0);
    if ((m_caster->GetTypeId() == TYPEID_PLAYER && m_timer != 0) &&
        m_caster->isMoving() && (m_spellInfo->InterruptFlags & SPELL_INTERRUPT_FLAG_MOVEMENT) &&
        ((effect && effect->Effect != SPELL_EFFECT_STUCK) || !m_caster->HasUnitMovementFlag(MOVEMENTFLAG_FALLING_FAR)) &&
        !m_caster->HasAuraTypeWithAffectMask(SPELL_AURA_CAST_WHILE_WALKING, m_spellInfo))
    {
        // don't cancel for melee, autorepeat, triggered and instant spells
        if (!m_spellInfo->IsNextMeleeSwingSpell() && !IsAutoRepeat() && !IsTriggered() && !(IsChannelActive() && m_spellInfo->IsMoveAllowedChannel()))
        {
            // if charmed by creature, trust the AI not to cheat and allow the cast to proceed
            // @todo this is a hack, "creature" movesplines don't differentiate turning/moving right now
            // however, checking what type of movement the spline is for every single spline would be really expensive
            if (!m_caster->GetCharmerGUID().IsCreature())
                cancel();
        }
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

            if (m_timer == 0 && !m_spellInfo->IsNextMeleeSwingSpell() && !IsAutoRepeat())
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
                        if (Unit* unit = m_caster->GetGUID() == target.targetGUID ? m_caster : ObjectAccessor::GetUnit(*m_caster, target.targetGUID))
                            unit->RemoveOwnedAura(m_spellInfo->Id, m_originalCasterGUID, 0, AURA_REMOVE_BY_CANCEL);
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
            }
            break;
        }
        default:
            break;
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

    if (m_caster->HasUnitState(UNIT_STATE_CASTING) && !m_caster->IsNonMeleeSpellCast(false, false, true))
        m_caster->ClearUnitState(UNIT_STATE_CASTING);

    // Unsummon summon as possessed creatures on spell cancel
    if (m_spellInfo->IsChanneled() && m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        if (Unit* charm = m_caster->GetCharm())
            if (charm->GetTypeId() == TYPEID_UNIT
                && charm->ToCreature()->HasUnitTypeMask(UNIT_MASK_PUPPET)
                && charm->GetUInt32Value(UNIT_CREATED_BY_SPELL) == m_spellInfo->Id)
                ((Puppet*)charm)->UnSummon();
    }

    if (Creature* creatureCaster = m_caster->ToCreature())
        creatureCaster->ReleaseFocus(this);

    if (!ok)
        return;

    if (m_caster->GetTypeId() == TYPEID_UNIT && m_caster->IsSummon())
    {
        // Unsummon statue
        uint32 spell = m_caster->GetUInt32Value(UNIT_CREATED_BY_SPELL);
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spell);
        if (spellInfo && spellInfo->IconFileDataId == 134230)
        {
            TC_LOG_DEBUG("spells", "Statue %s is unsummoned in spell %d finish", m_caster->GetGUID().ToString().c_str(), m_spellInfo->Id);
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
            if ((*i)->IsAffectingSpell(m_spellInfo))
            {
                found = true;
                break;
            }
        }

        if (!found && !m_spellInfo->HasAttribute(SPELL_ATTR2_NOT_RESET_AUTO_ACTIONS))
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
    }

    // Stop Attack for some spells
    if (m_spellInfo->HasAttribute(SPELL_ATTR0_STOP_ATTACK_TARGET))
        m_caster->AttackStop();
}

template<class T>
inline void FillSpellCastFailedArgs(T& packet, ObjectGuid castId, SpellInfo const* spellInfo, SpellCastResult result, SpellCustomErrors customError, uint32* param1 /*= nullptr*/, uint32* param2 /*= nullptr*/, Player* caster)
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
            }
            break;
        case SPELL_FAILED_EQUIPPED_ITEM_CLASS:
        case SPELL_FAILED_EQUIPPED_ITEM_CLASS_MAINHAND:
        case SPELL_FAILED_EQUIPPED_ITEM_CLASS_OFFHAND:
            if (param1 && param2)
            {
                packet.FailedArg1 = *param1;
                packet.FailedArg2 = *param2;
            }
            else
            {
                packet.FailedArg1 = spellInfo->EquippedItemClass;
                packet.FailedArg2 = spellInfo->EquippedItemSubClassMask;
            }
            break;
        case SPELL_FAILED_TOO_MANY_OF_ITEM:
        {
            if (param1)
                packet.FailedArg1 = *param1;
            else
            {
                uint32 item = 0;
                for (SpellEffectInfo const* effect : spellInfo->GetEffectsForDifficulty(caster->GetMap()->GetDifficultyID()))
                    if (effect->ItemType)
                        item = effect->ItemType;
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
                packet.FailedArg1 = missingItem;  // first missing item
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

void Spell::SendCastResult(SpellCastResult result, uint32* param1 /*= nullptr*/, uint32* param2 /*= nullptr*/) const
{
    if (result == SPELL_CAST_OK)
        return;

    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    if (m_caster->ToPlayer()->IsLoading())  // don't send cast results at loading time
        return;

    if (_triggeredCastFlags & TRIGGERED_DONT_REPORT_CAST_ERROR)
        result = SPELL_FAILED_DONT_REPORT;

    WorldPackets::Spells::CastFailed castFailed;
    castFailed.SpellXSpellVisualID = m_SpellVisual;
    FillSpellCastFailedArgs(castFailed, m_castId, m_spellInfo, result, m_customError, param1, param2, m_caster->ToPlayer());
    m_caster->ToPlayer()->SendDirectMessage(castFailed.Write());
}

void Spell::SendPetCastResult(SpellCastResult result, uint32* param1 /*= nullptr*/, uint32* param2 /*= nullptr*/) const
{
    if (result == SPELL_CAST_OK)
        return;

    Unit* owner = m_caster->GetCharmerOrOwner();
    if (!owner || owner->GetTypeId() != TYPEID_PLAYER)
        return;

    if (_triggeredCastFlags & TRIGGERED_DONT_REPORT_CAST_ERROR)
        result = SPELL_FAILED_DONT_REPORT;

    WorldPackets::Spells::PetCastFailed petCastFailed;
    FillSpellCastFailedArgs(petCastFailed, m_castId, m_spellInfo, result, SPELL_CUSTOM_ERROR_NONE, param1, param2, owner->ToPlayer());
    owner->ToPlayer()->SendDirectMessage(petCastFailed.Write());
}

void Spell::SendCastResult(Player* caster, SpellInfo const* spellInfo, uint32 spellVisual, ObjectGuid cast_count, SpellCastResult result, SpellCustomErrors customError /*= SPELL_CUSTOM_ERROR_NONE*/, uint32* param1 /*= nullptr*/, uint32* param2 /*= nullptr*/)
{
    if (result == SPELL_CAST_OK)
        return;

    WorldPackets::Spells::CastFailed packet;
    packet.SpellXSpellVisualID = spellVisual;
    FillSpellCastFailedArgs(packet, cast_count, spellInfo, result, customError, param1, param2, caster);
    caster->GetSession()->SendPacket(packet.Write());
}

void Spell::SendSpellStart()
{
    if (!IsNeedSendToClient())
        return;

    TC_LOG_DEBUG("spells", "Sending SMSG_SPELL_START id=%u", m_spellInfo->Id);

    uint32 castFlags = CAST_FLAG_HAS_TRAJECTORY;
    uint32 schoolImmunityMask = m_caster->GetSchoolImmunityMask();
    uint32 mechanicImmunityMask = m_caster->GetMechanicImmunityMask();
    if (schoolImmunityMask || mechanicImmunityMask)
        castFlags |= CAST_FLAG_IMMUNITY;

    if (((IsTriggered() && !m_spellInfo->IsAutoRepeatRangedSpell()) || m_triggeredByAuraSpell) && !m_fromClient)
        castFlags |= CAST_FLAG_PENDING;

    if (m_spellInfo->HasAttribute(SPELL_ATTR0_REQ_AMMO) || m_spellInfo->HasAttribute(SPELL_ATTR0_CU_NEEDS_AMMO_DATA))
        castFlags |= CAST_FLAG_PROJECTILE;

    if ((m_caster->GetTypeId() == TYPEID_PLAYER ||
        (m_caster->GetTypeId() == TYPEID_UNIT && m_caster->IsPet()))
        && std::find_if(m_powerCost.begin(), m_powerCost.end(), [](SpellPowerCost const& cost) { return cost.Power != POWER_HEALTH; }) != m_powerCost.end())
        castFlags |= CAST_FLAG_POWER_LEFT_SELF;

    if (std::find_if(m_powerCost.begin(), m_powerCost.end(), [](SpellPowerCost const& cost) { return cost.Power == POWER_RUNES; }) != m_powerCost.end())
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
    castData.SpellXSpellVisualID = m_SpellVisual;
    castData.CastFlags = castFlags;
    castData.CastFlagsEx = m_castFlagsEx;
    castData.CastTime = m_casttime;

    m_targets.Write(castData.Target);

    if (castFlags & CAST_FLAG_POWER_LEFT_SELF)
    {
        for (SpellPowerCost const& cost : m_powerCost)
        {
            WorldPackets::Spells::SpellPowerData powerData;
            powerData.Type = cost.Power;
            powerData.Cost = m_caster->GetPower(cost.Power);
            castData.RemainingPower.push_back(powerData);
        }
    }

    if (castFlags & CAST_FLAG_RUNE_LIST) // rune cooldowns list
    {
        castData.RemainingRunes = boost::in_place();

        //TODO: There is a crash caused by a spell with CAST_FLAG_RUNE_LIST casted by a creature
        //The creature is the mover of a player, so HandleCastSpellOpcode uses it as the caster
        if (Player* player = m_caster->ToPlayer())
        {
            castData.RemainingRunes->Start = m_runesState; // runes state before
            castData.RemainingRunes->Count = player->GetRunesState(); // runes state after
            for (uint8 i = 0; i < player->GetMaxPower(POWER_RUNES); ++i)
            {
                // float casts ensure the division is performed on floats as we need float result
                float baseCd = float(player->GetRuneBaseCooldown());
                castData.RemainingRunes->Cooldowns.push_back((baseCd - float(player->GetRuneCooldown(i))) / baseCd * 255); // rune cooldown passed
            }
        }
        else
        {
            castData.RemainingRunes->Start = 0;
            castData.RemainingRunes->Count = 0;
            for (uint8 i = 0; i < player->GetMaxPower(POWER_RUNES); ++i)
                castData.RemainingRunes->Cooldowns.push_back(0);
        }
    }

    if (castFlags & CAST_FLAG_PROJECTILE)
        UpdateSpellCastDataAmmo(castData.Ammo);

    if (castFlags & CAST_FLAG_IMMUNITY)
    {
        castData.Immunities.School = schoolImmunityMask;
        castData.Immunities.Value = mechanicImmunityMask;
    }

    /** @todo implement heal prediction packet data
    if (castFlags & CAST_FLAG_HEAL_PREDICTION)
    {
        castData.Predict.BeconGUID = ??
        castData.Predict.Points = 0;
        castData.Predict.Type = 0;
    }**/

    m_caster->SendMessageToSet(packet.Write(), true);
}

void Spell::SendSpellGo()
{
    // not send invisible spell casting
    if (!IsNeedSendToClient())
        return;

    TC_LOG_DEBUG("spells", "Sending SMSG_SPELL_GO id=%u", m_spellInfo->Id);

    uint32 castFlags = CAST_FLAG_UNKNOWN_9;

    // triggered spells with spell visual != 0
    if (((IsTriggered() && !m_spellInfo->IsAutoRepeatRangedSpell()) || m_triggeredByAuraSpell) && !m_fromClient)
        castFlags |= CAST_FLAG_PENDING;

    if (m_spellInfo->HasAttribute(SPELL_ATTR0_REQ_AMMO) || m_spellInfo->HasAttribute(SPELL_ATTR0_CU_NEEDS_AMMO_DATA))
        castFlags |= CAST_FLAG_PROJECTILE;                        // arrows/bullets visual

    if ((m_caster->GetTypeId() == TYPEID_PLAYER ||
        (m_caster->GetTypeId() == TYPEID_UNIT && m_caster->IsPet()))
        && std::find_if(m_powerCost.begin(), m_powerCost.end(), [](SpellPowerCost const& cost) { return cost.Power != POWER_HEALTH; }) != m_powerCost.end())
        castFlags |= CAST_FLAG_POWER_LEFT_SELF; // should only be sent to self, but the current messaging doesn't make that possible

    if ((m_caster->GetTypeId() == TYPEID_PLAYER)
        && (m_caster->getClass() == CLASS_DEATH_KNIGHT)
        && std::find_if(m_powerCost.begin(), m_powerCost.end(), [](SpellPowerCost const& cost) { return cost.Power == POWER_RUNES; }) != m_powerCost.end()
        && !(_triggeredCastFlags & TRIGGERED_IGNORE_POWER_AND_REAGENT_COST))
    {
        castFlags |= CAST_FLAG_NO_GCD;                       // not needed, but Blizzard sends it
        castFlags |= CAST_FLAG_RUNE_LIST;                    // rune cooldowns list
    }

    if (HasEffect(SPELL_EFFECT_ACTIVATE_RUNE))
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
    castData.CastID = m_castId;
    castData.OriginalCastID = m_originalCastId;
    castData.SpellID = m_spellInfo->Id;
    castData.SpellXSpellVisualID = m_SpellVisual;
    castData.CastFlags = castFlags;
    castData.CastFlagsEx = m_castFlagsEx;
    castData.CastTime = getMSTime();

    UpdateSpellCastDataTargets(castData);

    m_targets.Write(castData.Target);

    if (castFlags & CAST_FLAG_POWER_LEFT_SELF)
    {
        for (SpellPowerCost const& cost : m_powerCost)
        {
            WorldPackets::Spells::SpellPowerData powerData;
            powerData.Type = cost.Power;
            powerData.Cost = m_caster->GetPower(cost.Power);
            castData.RemainingPower.push_back(powerData);
        }
    }

    if (castFlags & CAST_FLAG_RUNE_LIST) // rune cooldowns list
    {
        castData.RemainingRunes = boost::in_place();

        //TODO: There is a crash caused by a spell with CAST_FLAG_RUNE_LIST casted by a creature
        //The creature is the mover of a player, so HandleCastSpellOpcode uses it as the caster
        if (Player* player = m_caster->ToPlayer())
        {
            castData.RemainingRunes->Start = m_runesState; // runes state before
            castData.RemainingRunes->Count = player->GetRunesState(); // runes state after
            for (uint8 i = 0; i < player->GetMaxPower(POWER_RUNES); ++i)
            {
                // float casts ensure the division is performed on floats as we need float result
                float baseCd = float(player->GetRuneBaseCooldown());
                castData.RemainingRunes->Cooldowns.push_back((baseCd - float(player->GetRuneCooldown(i))) / baseCd * 255); // rune cooldown passed
            }
        }
        else
        {
            castData.RemainingRunes->Start = 0;
            castData.RemainingRunes->Count = 0;
            for (uint8 i = 0; i < player->GetMaxPower(POWER_RUNES); ++i)
                castData.RemainingRunes->Cooldowns.push_back(0);
        }
    }

    if (castFlags & CAST_FLAG_ADJUST_MISSILE)
    {
        castData.MissileTrajectory.TravelTime = m_delayMoment;
        castData.MissileTrajectory.Pitch = m_targets.GetPitch();
    }

    packet.LogData.Initialize(this);

    m_caster->SendCombatLogMessage(&packet);
}

/// Writes miss and hit targets for a SMSG_SPELL_GO packet
void Spell::UpdateSpellCastDataTargets(WorldPackets::Spells::SpellCastData& data)
{
    // This function also fill data for channeled spells:
    // m_needAliveTargetMask req for stop channeling if one target die
    for (TargetInfo& targetInfo : m_UniqueTargetInfo)
    {
        if (targetInfo.effectMask == 0) // No effect apply - all immune add state
            // possibly SPELL_MISS_IMMUNE2 for this??
            targetInfo.missCondition = SPELL_MISS_IMMUNE2;

        if (targetInfo.missCondition == SPELL_MISS_NONE) // hits
        {
            data.HitTargets.push_back(targetInfo.targetGUID);

            m_channelTargetEffectMask |= targetInfo.effectMask;
        }
        else // misses
        {
            data.MissTargets.push_back(targetInfo.targetGUID);

            WorldPackets::Spells::SpellMissStatus missStatus;
            missStatus.Reason = targetInfo.missCondition;
            if (targetInfo.missCondition == SPELL_MISS_REFLECT)
                missStatus.ReflectStatus = targetInfo.reflectResult;

            data.MissStatus.push_back(missStatus);
        }
    }

    for (GOTargetInfo const& targetInfo : m_UniqueGOTargetInfo)
        data.HitTargets.push_back(targetInfo.targetGUID); // Always hits

    // Reset m_needAliveTargetMask for non channeled spell
    if (!m_spellInfo->IsChanneled())
        m_channelTargetEffectMask = 0;
}

void Spell::UpdateSpellCastDataAmmo(WorldPackets::Spells::SpellAmmo& ammo)
{
    uint32 ammoInventoryType = 0;
    uint32 ammoDisplayID = 0;

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        Item* pItem = m_caster->ToPlayer()->GetWeaponForAttack(RANGED_ATTACK);
        if (pItem)
        {
            ammoInventoryType = pItem->GetTemplate()->GetInventoryType();
            if (ammoInventoryType == INVTYPE_THROWN)
                ammoDisplayID = pItem->GetDisplayId(m_caster->ToPlayer());
            else if (m_caster->HasAura(46699))      // Requires No Ammo
            {
                ammoDisplayID = 5996;                   // normal arrow
                ammoInventoryType = INVTYPE_AMMO;
            }
        }
    }
    else
    {
        for (uint8 i = 0; i < 3; ++i)
        {
            if (uint32 item_id = m_caster->GetVirtualItemId(i))
            {
                if (ItemEntry const* itemEntry = sItemStore.LookupEntry(item_id))
                {
                    if (itemEntry->ClassID == ITEM_CLASS_WEAPON)
                    {
                        switch (itemEntry->SubclassID)
                        {
                            case ITEM_SUBCLASS_WEAPON_THROWN:
                                ammoDisplayID = sDB2Manager.GetItemDisplayId(item_id, m_caster->GetVirtualItemAppearanceMod(i));
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

void Spell::SendSpellExecuteLog()
{
    WorldPackets::CombatLog::SpellExecuteLog spellExecuteLog;
    spellExecuteLog.Caster = m_caster->GetGUID();
    spellExecuteLog.SpellID = m_spellInfo->Id;

    for (SpellEffectInfo const* effect : GetEffects())
    {
        if (!effect)
            continue;

        if (_powerDrainTargets[effect->EffectIndex].empty() && _extraAttacksTargets[effect->EffectIndex].empty() &&
            _durabilityDamageTargets[effect->EffectIndex].empty() && _genericVictimTargets[effect->EffectIndex].empty() &&
            _tradeSkillTargets[effect->EffectIndex].empty() && _feedPetTargets[effect->EffectIndex].empty())
            continue;

        spellExecuteLog.Effects.emplace_back();

        WorldPackets::CombatLog::SpellExecuteLog::SpellLogEffect& spellLogEffect = spellExecuteLog.Effects.back();
        spellLogEffect.Effect = effect->Effect;
        spellLogEffect.PowerDrainTargets = std::move(_powerDrainTargets[effect->EffectIndex]);
        spellLogEffect.ExtraAttacksTargets = std::move(_extraAttacksTargets[effect->EffectIndex]);
        spellLogEffect.DurabilityDamageTargets = std::move(_durabilityDamageTargets[effect->EffectIndex]);
        spellLogEffect.GenericVictimTargets = std::move(_genericVictimTargets[effect->EffectIndex]);
        spellLogEffect.TradeSkillTargets = std::move(_tradeSkillTargets[effect->EffectIndex]);
        spellLogEffect.FeedPetTargets = std::move(_feedPetTargets[effect->EffectIndex]);
    }

    if (!spellExecuteLog.Effects.empty())
        m_caster->SendCombatLogMessage(&spellExecuteLog);
}

void Spell::ExecuteLogEffectTakeTargetPower(uint8 effIndex, Unit* target, uint32 powerType, uint32 points, float amplitude)
{
    SpellLogEffectPowerDrainParams spellLogEffectPowerDrainParams;

    spellLogEffectPowerDrainParams.Victim = target->GetGUID();
    spellLogEffectPowerDrainParams.Points = points;
    spellLogEffectPowerDrainParams.PowerType = powerType;
    spellLogEffectPowerDrainParams.Amplitude = amplitude;

    _powerDrainTargets[effIndex].push_back(spellLogEffectPowerDrainParams);
}

void Spell::ExecuteLogEffectExtraAttacks(uint8 effIndex, Unit* victim, uint32 numAttacks)
{
    SpellLogEffectExtraAttacksParams spellLogEffectExtraAttacksParams;
    spellLogEffectExtraAttacksParams.Victim = victim->GetGUID();
    spellLogEffectExtraAttacksParams.NumAttacks = numAttacks;

    _extraAttacksTargets[effIndex].push_back(spellLogEffectExtraAttacksParams);
}

void Spell::ExecuteLogEffectInterruptCast(uint8 /*effIndex*/, Unit* victim, uint32 spellId)
{
    WorldPackets::CombatLog::SpellInterruptLog data;
    data.Caster = m_caster->GetGUID();
    data.Victim = victim->GetGUID();
    data.InterruptedSpellID = m_spellInfo->Id;
    data.SpellID = spellId;

    m_caster->SendMessageToSet(data.Write(), true);
}

void Spell::ExecuteLogEffectDurabilityDamage(uint8 effIndex, Unit* victim, int32 itemId, int32 amount)
{
    SpellLogEffectDurabilityDamageParams spellLogEffectDurabilityDamageParams;
    spellLogEffectDurabilityDamageParams.Victim = victim->GetGUID();
    spellLogEffectDurabilityDamageParams.ItemID = itemId;
    spellLogEffectDurabilityDamageParams.Amount = amount;

    _durabilityDamageTargets[effIndex].push_back(spellLogEffectDurabilityDamageParams);
}

void Spell::ExecuteLogEffectOpenLock(uint8 effIndex, Object* obj)
{
    SpellLogEffectGenericVictimParams spellLogEffectGenericVictimParams;
    spellLogEffectGenericVictimParams.Victim = obj->GetGUID();

    _genericVictimTargets[effIndex].push_back(spellLogEffectGenericVictimParams);
}

void Spell::ExecuteLogEffectCreateItem(uint8 effIndex, uint32 entry)
{
    SpellLogEffectTradeSkillItemParams spellLogEffectTradeSkillItemParams;
    spellLogEffectTradeSkillItemParams.ItemID = entry;

    _tradeSkillTargets[effIndex].push_back(spellLogEffectTradeSkillItemParams);
}

void Spell::ExecuteLogEffectDestroyItem(uint8 effIndex, uint32 entry)
{
    SpellLogEffectFeedPetParams spellLogEffectFeedPetParams;
    spellLogEffectFeedPetParams.ItemID = entry;

    _feedPetTargets[effIndex].push_back(spellLogEffectFeedPetParams);
}

void Spell::ExecuteLogEffectSummonObject(uint8 effIndex, WorldObject* obj)
{
    SpellLogEffectGenericVictimParams spellLogEffectGenericVictimParams;
    spellLogEffectGenericVictimParams.Victim = obj->GetGUID();

    _genericVictimTargets[effIndex].push_back(spellLogEffectGenericVictimParams);
}

void Spell::ExecuteLogEffectUnsummonObject(uint8 effIndex, WorldObject* obj)
{
    SpellLogEffectGenericVictimParams spellLogEffectGenericVictimParams;
    spellLogEffectGenericVictimParams.Victim = obj->GetGUID();

    _genericVictimTargets[effIndex].push_back(spellLogEffectGenericVictimParams);
}

void Spell::ExecuteLogEffectResurrect(uint8 effect, Unit* target)
{
    SpellLogEffectGenericVictimParams spellLogEffectGenericVictimParams;
    spellLogEffectGenericVictimParams.Victim = target->GetGUID();

    _genericVictimTargets[effect].push_back(spellLogEffectGenericVictimParams);
}

void Spell::SendInterrupted(uint8 result)
{
    WorldPackets::Spells::SpellFailure failurePacket;
    failurePacket.CasterUnit = m_caster->GetGUID();
    failurePacket.CastID = m_castId;
    failurePacket.SpellID = m_spellInfo->Id;
    failurePacket.SpellXSpellVisualID = m_SpellVisual;
    failurePacket.Reason = result;
    m_caster->SendMessageToSet(failurePacket.Write(), true);

    WorldPackets::Spells::SpellFailedOther failedPacket;
    failedPacket.CasterUnit = m_caster->GetGUID();
    failedPacket.CastID = m_castId;
    failedPacket.SpellID = m_spellInfo->Id;
    failedPacket.Reason = result;
    m_caster->SendMessageToSet(failedPacket.Write(), true);
}

void Spell::SendChannelUpdate(uint32 time)
{
    if (time == 0)
    {
        m_caster->ClearDynamicValue(UNIT_DYNAMIC_FIELD_CHANNEL_OBJECTS);
        m_caster->SetChannelSpellId(0);
        m_caster->SetChannelSpellXSpellVisualId(0);
    }

    WorldPackets::Spells::SpellChannelUpdate spellChannelUpdate;
    spellChannelUpdate.CasterGUID = m_caster->GetGUID();
    spellChannelUpdate.TimeRemaining = time;
    m_caster->SendMessageToSet(spellChannelUpdate.Write(), true);
}

void Spell::SendChannelStart(uint32 duration)
{
    WorldPackets::Spells::SpellChannelStart spellChannelStart;
    spellChannelStart.CasterGUID = m_caster->GetGUID();
    spellChannelStart.SpellID = m_spellInfo->Id;
    spellChannelStart.SpellXSpellVisualID = m_SpellVisual;
    spellChannelStart.ChannelDuration = duration;
    m_caster->SendMessageToSet(spellChannelStart.Write(), true);

    uint32 schoolImmunityMask = m_caster->GetSchoolImmunityMask();
    uint32 mechanicImmunityMask = m_caster->GetMechanicImmunityMask();

    if (schoolImmunityMask || mechanicImmunityMask)
    {
        spellChannelStart.InterruptImmunities = boost::in_place();
        spellChannelStart.InterruptImmunities->SchoolImmunities = schoolImmunityMask;
        spellChannelStart.InterruptImmunities->Immunities = mechanicImmunityMask;
    }

    m_timer = duration;
    for (TargetInfo const& target : m_UniqueTargetInfo)
        m_caster->AddChannelObject(target.targetGUID);

    for (GOTargetInfo const& target : m_UniqueGOTargetInfo)
        m_caster->AddChannelObject(target.targetGUID);

    m_caster->SetChannelSpellId(m_spellInfo->Id);
    m_caster->SetChannelSpellXSpellVisualId(m_SpellVisual);
}

void Spell::SendResurrectRequest(Player* target)
{
    // get resurrector name for creature resurrections, otherwise packet will be not accepted
    // for player resurrections the name is looked up by guid
    std::string const sentName(m_caster->GetTypeId() == TYPEID_PLAYER
        ? "" : m_caster->GetNameForLocaleIdx(target->GetSession()->GetSessionDbLocaleIndex()));

    WorldPackets::Spells::ResurrectRequest resurrectRequest;
    resurrectRequest.ResurrectOffererGUID =  m_caster->GetGUID();
    resurrectRequest.ResurrectOffererVirtualRealmAddress = GetVirtualRealmAddress();

    if (Pet* pet = target->GetPet())
    {
        if (CharmInfo* charmInfo = pet->GetCharmInfo())
            resurrectRequest.PetNumber = charmInfo->GetPetNumber();
    }

    resurrectRequest.SpellID = m_spellInfo->Id;

    //packet.ReadBit("UseTimer"); /// @todo: 6.x Has to be implemented
    resurrectRequest.Sickness = m_caster->GetTypeId() != TYPEID_PLAYER; // "you'll be afflicted with resurrection sickness"

    resurrectRequest.Name = sentName;

    target->GetSession()->SendPacket(resurrectRequest.Write());
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

    for (uint8 i = 0; i < proto->Effects.size() && i < 5; ++i)
    {
        // item has limited charges
        if (proto->Effects[i]->Charges)
        {
            if (proto->Effects[i]->Charges < 0)
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
            m_targets.SetItemTarget(NULL);

        m_CastItem = NULL;
        m_castItemGUID.Clear();
        m_castItemEntry = 0;
    }
}

void Spell::TakePower()
{
    if (m_CastItem || m_triggeredByAuraSpell)
        return;

    //Don't take power if the spell is cast while .cheat power is enabled.
    if (m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        if (m_caster->ToPlayer()->GetCommandStatus(CHEAT_POWER))
            return;
    }

    for (SpellPowerCost& cost : m_powerCost)
    {
        Powers powerType = Powers(cost.Power);
        bool hit = true;
        if (m_caster->GetTypeId() == TYPEID_PLAYER)
        {
            if (powerType == POWER_RAGE || powerType == POWER_ENERGY || powerType == POWER_RUNES)
            {
                ObjectGuid targetGUID = m_targets.GetUnitTargetGUID();
                if (!targetGUID.IsEmpty())
                {
                    for (std::vector<TargetInfo>::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
                    {
                        if (ihit->targetGUID == targetGUID)
                        {
                            if (ihit->missCondition != SPELL_MISS_NONE)
                            {
                                hit = false;
                                //lower spell cost on fail (by talent aura)
                                if (Player* modOwner = m_caster->ToPlayer()->GetSpellModOwner())
                                    modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_SPELL_COST_REFUND_ON_FAIL, cost.Amount);
                            }
                            break;
                        }
                    }
                }
            }
        }

        if (powerType == POWER_RUNES)
        {
            TakeRunePower(hit);
            continue;
        }

        if (!cost.Amount)
            continue;

        // health as power used
        if (powerType == POWER_HEALTH)
        {
            m_caster->ModifyHealth(-cost.Amount);
            continue;
        }

        if (powerType >= MAX_POWERS)
        {
            TC_LOG_ERROR("spells", "Spell::TakePower: Unknown power type '%d'", powerType);
            continue;
        }

        if (hit)
            m_caster->ModifyPower(powerType, -cost.Amount);
        else
            m_caster->ModifyPower(powerType, -irand(0, cost.Amount / 4));
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

    if (player->getClass() != CLASS_DEATH_KNIGHT)
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
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER || m_caster->getClass() != CLASS_DEATH_KNIGHT)
        return;

    Player* player = m_caster->ToPlayer();
    m_runesState = player->GetRunesState();                 // store previous state

    int32 runeCost = std::accumulate(m_powerCost.begin(), m_powerCost.end(), 0, [](int32 totalCost, SpellPowerCost const& cost)
    {
        return totalCost + (cost.Power == POWER_RUNES ? cost.Amount : 0);
    });

    for (int32 i = 0; i < player->GetMaxPower(POWER_RUNES); ++i)
    {
        if (!player->GetRuneCooldown(i) && runeCost > 0)
        {
            player->SetRuneCooldown(i, didHit ? player->GetRuneBaseCooldown() : uint32(RUNE_MISS_COOLDOWN));
            --runeCost;
        }
    }
}

void Spell::TakeReagents()
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    ItemTemplate const* castItemTemplate = m_CastItem ? m_CastItem->GetTemplate() : NULL;

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
            for (uint8 s = 0; s < castItemTemplate->Effects.size() && s < 5; ++s)
            {
                // CastItem will be used up and does not count as reagent
                int32 charges = m_CastItem->GetSpellCharges(s);
                if (castItemTemplate->Effects[s]->Charges < 0 && abs(charges) < 2)
                {
                    ++itemcount;
                    break;
                }
            }

            m_CastItem = NULL;
            m_castItemGUID.Clear();
            m_castItemEntry = 0;
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

    if (!m_spellInfo->HasInitialAggro())
        return;

    float threat = 0.0f;
    if (SpellThreatEntry const* threatEntry = sSpellMgr->GetSpellThreatEntry(m_spellInfo->Id))
    {
        if (threatEntry->apPctMod != 0.0f)
            threat += threatEntry->apPctMod * m_caster->GetTotalAttackPowerValue(BASE_ATTACK);

        threat += threatEntry->flatMod;
    }
    else if (!m_spellInfo->HasAttribute(SPELL_ATTR0_CU_NO_INITIAL_THREAT))
        threat += m_spellInfo->SpellLevel;

    // past this point only multiplicative effects occur
    if (threat == 0.0f)
        return;

    // since 2.0.1 threat from positive effects also is distributed among all targets, so the overall caused threat is at most the defined bonus
    threat /= m_UniqueTargetInfo.size();

    for (std::vector<TargetInfo>::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
    {
        float threatToAdd = threat;
        if (ihit->missCondition != SPELL_MISS_NONE)
            threatToAdd = 0.0f;

        Unit* target = ObjectAccessor::GetUnit(*m_caster, ihit->targetGUID);
        if (!target)
            continue;

        // positive spells distribute threat among all units that are in combat with target, like healing
        if (m_spellInfo->IsPositive())
            target->getHostileRefManager().threatAssist(m_caster, threatToAdd, m_spellInfo);
        // for negative spells threat gets distributed among affected targets
        else
        {
            if (!target->CanHaveThreatList())
                continue;

            target->AddThreat(m_caster, threatToAdd, m_spellInfo->GetSchoolMask(), m_spellInfo);
        }
    }
    TC_LOG_DEBUG("spells", "Spell %u, added an additional %f threat for %s %u target(s)", m_spellInfo->Id, threat, m_spellInfo->IsPositive() ? "assisting" : "harming", uint32(m_UniqueTargetInfo.size()));
}

void Spell::HandleEffects(Unit* pUnitTarget, Item* pItemTarget, GameObject* pGOTarget, uint32 i, SpellEffectHandleMode mode)
{
    effectHandleMode = mode;
    unitTarget = pUnitTarget;
    itemTarget = pItemTarget;
    gameObjTarget = pGOTarget;
    destTarget = &m_destTargets[i]._position;

    effectInfo = GetEffect(i);
    if (!effectInfo)
    {
        TC_LOG_ERROR("spells", "Spell: %u HandleEffects at EffectIndex: %u missing effect", m_spellInfo->Id, i);
        return;
    }
    uint32 eff = effectInfo->Effect;

    TC_LOG_DEBUG("spells", "Spell: %u Effect: %u", m_spellInfo->Id, eff);

    damage = CalculateDamage(i, unitTarget, &variance);

    bool preventDefault = CallScriptEffectHandlers((SpellEffIndex)i, mode);

    if (!preventDefault && eff < TOTAL_SPELL_EFFECTS)
    {
        (this->*SpellEffects[eff])((SpellEffIndex)i);
    }
}

SpellCastResult Spell::CheckCast(bool strict, uint32* param1 /*= nullptr*/, uint32* param2 /*= nullptr*/)
{
    // check death state
    if (!m_caster->IsAlive() && !m_spellInfo->IsPassive() && !(m_spellInfo->HasAttribute(SPELL_ATTR0_CASTABLE_WHILE_DEAD) || (IsTriggered() && !m_triggeredByAuraSpell)))
        return SPELL_FAILED_CASTER_DEAD;

    // check cooldowns to prevent cheating
    if (!m_spellInfo->IsPassive())
    {
        if (m_caster->GetTypeId() == TYPEID_PLAYER)
        {
            //can cast triggered (by aura only?) spells while have this flag
            if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CASTER_AURASTATE) && m_caster->ToPlayer()->HasFlag(PLAYER_FLAGS, PLAYER_ALLOW_ONLY_ABILITY))
                return SPELL_FAILED_SPELL_IN_PROGRESS;

            // check if we are using a potion in combat for the 2nd+ time. Cooldown is added only after caster gets out of combat
            if (m_caster->ToPlayer()->GetLastPotionId() && m_CastItem && (m_CastItem->IsPotion() || m_spellInfo->IsCooldownStartedOnEvent()))
                return SPELL_FAILED_NOT_READY;
        }

        if (!m_caster->GetSpellHistory()->IsReady(m_spellInfo, m_castItemEntry, IsIgnoringCooldowns()))
        {
            if (m_triggeredByAuraSpell)
                return SPELL_FAILED_DONT_REPORT;
            else
                return SPELL_FAILED_NOT_READY;
        }
    }

    if (m_spellInfo->HasAttribute(SPELL_ATTR7_IS_CHEAT_SPELL) && !m_caster->HasFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_ALLOW_CHEAT_SPELLS))
    {
        m_customError = SPELL_CUSTOM_ERROR_GM_ONLY;
        return SPELL_FAILED_CUSTOM_ERROR;
    }

    // Check global cooldown
    if (strict && !(_triggeredCastFlags & TRIGGERED_IGNORE_GCD) && HasGlobalCooldown())
        return !m_spellInfo->HasAttribute(SPELL_ATTR0_DISABLED_WHILE_ACTIVE) ? SPELL_FAILED_NOT_READY : SPELL_FAILED_DONT_REPORT;

    // only triggered spells can be processed an ended battleground
    if (!IsTriggered() && m_caster->GetTypeId() == TYPEID_PLAYER)
        if (Battleground* bg = m_caster->ToPlayer()->GetBattleground())
            if (bg->GetStatus() == STATUS_WAIT_LEAVE)
                return SPELL_FAILED_DONT_REPORT;

    if (m_caster->GetTypeId() == TYPEID_PLAYER && VMAP::VMapFactory::createOrGetVMapManager()->isLineOfSightCalcEnabled())
    {
        if (m_spellInfo->HasAttribute(SPELL_ATTR0_OUTDOORS_ONLY) &&
                !m_caster->GetMap()->IsOutdoors(m_caster->GetPhaseShift(), m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ()))
            return SPELL_FAILED_ONLY_OUTDOORS;

        if (m_spellInfo->HasAttribute(SPELL_ATTR0_INDOORS_ONLY) &&
                m_caster->GetMap()->IsOutdoors(m_caster->GetPhaseShift(), m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ()))
            return SPELL_FAILED_ONLY_INDOORS;
    }

    // only check at first call, Stealth auras are already removed at second call
    // for now, ignore triggered spells
    if (strict && !(_triggeredCastFlags & TRIGGERED_IGNORE_SHAPESHIFT))
    {
        bool checkForm = true;
        // Ignore form req aura
        Unit::AuraEffectList const& ignore = m_caster->GetAuraEffectsByType(SPELL_AURA_MOD_IGNORE_SHAPESHIFT);
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
            SpellCastResult shapeError = m_spellInfo->CheckShapeshift(m_caster->GetShapeshiftForm());
            if (shapeError != SPELL_CAST_OK)
                return shapeError;

            if ((m_spellInfo->HasAttribute(SPELL_ATTR0_ONLY_STEALTHED)) && !(m_caster->HasStealthAura()))
                return SPELL_FAILED_ONLY_STEALTHED;
        }
    }

    if (m_caster->HasAuraTypeWithMiscvalue(SPELL_AURA_BLOCK_SPELL_FAMILY, m_spellInfo->SpellFamilyName))
        return SPELL_FAILED_SPELL_UNAVAILABLE;

    bool reqCombat = true;
    Unit::AuraEffectList const& stateAuras = m_caster->GetAuraEffectsByType(SPELL_AURA_ABILITY_IGNORE_AURASTATE);
    for (Unit::AuraEffectList::const_iterator j = stateAuras.begin(); j != stateAuras.end(); ++j)
    {
        if ((*j)->IsAffectingSpell(m_spellInfo))
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
        if (m_spellInfo->ExcludeCasterAuraState && m_caster->HasAuraState(AuraStateType(m_spellInfo->ExcludeCasterAuraState), m_spellInfo, m_caster))
            return SPELL_FAILED_CASTER_AURASTATE;

        // Note: spell 62473 requres casterAuraSpell = triggering spell
        if (m_spellInfo->CasterAuraSpell && !m_caster->HasAura(m_spellInfo->CasterAuraSpell))
            return SPELL_FAILED_CASTER_AURASTATE;
        if (m_spellInfo->ExcludeCasterAuraSpell && m_caster->HasAura(m_spellInfo->ExcludeCasterAuraSpell))
            return SPELL_FAILED_CASTER_AURASTATE;

        if (reqCombat && m_caster->IsInCombat() && !m_spellInfo->CanBeUsedInCombat())
            return SPELL_FAILED_AFFECTING_COMBAT;
    }

    // cancel autorepeat spells if cast start when moving
    // (not wand currently autorepeat cast delayed to moving stop anyway in spell update code)
    // Do not cancel spells which are affected by a SPELL_AURA_CAST_WHILE_WALKING effect
    if (m_caster->GetTypeId() == TYPEID_PLAYER && m_caster->ToPlayer()->isMoving() && (!m_caster->IsCharmed() || !m_caster->GetCharmerGUID().IsCreature()) && !m_caster->HasAuraTypeWithAffectMask(SPELL_AURA_CAST_WHILE_WALKING, m_spellInfo))
    {
        // skip stuck spell to allow use it in falling case and apply spell limitations at movement
        SpellEffectInfo const* effect = GetEffect(EFFECT_0);
        if ((!m_caster->HasUnitMovementFlag(MOVEMENTFLAG_FALLING_FAR) || (effect && effect->Effect != SPELL_EFFECT_STUCK)) &&
            (IsAutoRepeat() || m_spellInfo->HasAuraInterruptFlag(AURA_INTERRUPT_FLAG_NOT_SEATED)))
            return SPELL_FAILED_MOVING;
    }

    // Check vehicle flags
    if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE))
    {
        SpellCastResult vehicleCheck = m_spellInfo->CheckVehicle(m_caster);
        if (vehicleCheck != SPELL_CAST_OK)
            return vehicleCheck;
    }

    // check spell cast conditions from database
    {
        ConditionSourceInfo condInfo = ConditionSourceInfo(m_caster, m_targets.GetObjectTarget());
        if (!sConditionMgr->IsObjectMeetingNotGroupedConditions(CONDITION_SOURCE_TYPE_SPELL, m_spellInfo->Id, condInfo))
        {
            // mLastFailedCondition can be NULL if there was an error processing the condition in Condition::Meets (i.e. wrong data for ConditionTarget or others)
            if (condInfo.mLastFailedCondition && condInfo.mLastFailedCondition->ErrorType)
            {
                if (condInfo.mLastFailedCondition->ErrorType == SPELL_FAILED_CUSTOM_ERROR)
                    m_customError = SpellCustomErrors(condInfo.mLastFailedCondition->ErrorTextId);
                return SpellCastResult(condInfo.mLastFailedCondition->ErrorType);
            }

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
        Unit* caster = m_caster;
        if (m_originalCaster && m_caster->GetEntry() != WORLD_TRIGGER) // Do a simplified check for gameobject casts
            caster = m_originalCaster;

        SpellCastResult castResult = m_spellInfo->CheckExplicitTarget(caster, m_targets.GetObjectTarget(), m_targets.GetItemTarget());
        if (castResult != SPELL_CAST_OK)
            return castResult;
    }

    if (Unit* target = m_targets.GetUnitTarget())
    {
        SpellCastResult castResult = m_spellInfo->CheckTarget(m_caster, target, m_caster->GetEntry() == WORLD_TRIGGER); // skip stealth checks for GO casts
        if (castResult != SPELL_CAST_OK)
            return castResult;

        // If it's not a melee spell, check if vision is obscured by SPELL_AURA_INTERFERE_TARGETTING
        if (m_spellInfo->DmgClass != SPELL_DAMAGE_CLASS_MELEE)
        {
            for (auto const& itr : m_caster->GetAuraEffectsByType(SPELL_AURA_INTERFERE_TARGETTING))
                if (!m_caster->IsFriendlyTo(itr->GetCaster()) && !target->HasAura(itr->GetId(), itr->GetCasterGUID()))
                    return SPELL_FAILED_VISION_OBSCURED;

            for (auto const& itr : target->GetAuraEffectsByType(SPELL_AURA_INTERFERE_TARGETTING))
                if (!m_caster->IsFriendlyTo(itr->GetCaster()) && (!target->HasAura(itr->GetId(), itr->GetCasterGUID()) || !m_caster->HasAura(itr->GetId(), itr->GetCasterGUID())))
                    return SPELL_FAILED_VISION_OBSCURED;
        }

        if (target != m_caster)
        {
            // Must be behind the target
            if ((m_spellInfo->HasAttribute(SPELL_ATTR0_CU_REQ_CASTER_BEHIND_TARGET)) && target->HasInArc(static_cast<float>(M_PI), m_caster))
                return SPELL_FAILED_NOT_BEHIND;

            // Target must be facing you
            if ((m_spellInfo->HasAttribute(SPELL_ATTR0_CU_REQ_TARGET_FACING_CASTER)) && !target->HasInArc(static_cast<float>(M_PI), m_caster))
                return SPELL_FAILED_NOT_INFRONT;

            if (m_caster->GetEntry() != WORLD_TRIGGER) // Ignore LOS for gameobjects casts (wrongly cast by a trigger)
            {
                WorldObject* losTarget = m_caster;
                if (IsTriggered() && m_triggeredByAuraSpell)
                    if (DynamicObject* dynObj = m_caster->GetDynObject(m_triggeredByAuraSpell->Id))
                        losTarget = dynObj;

                if (!m_spellInfo->HasAttribute(SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS) && !DisableMgr::IsDisabledFor(DISABLE_TYPE_SPELL, m_spellInfo->Id, NULL, SPELL_DISABLE_LOS) && !target->IsWithinLOSInMap(losTarget))
                    return SPELL_FAILED_LINE_OF_SIGHT;
            }
        }
    }

    // Check for line of sight for spells with dest
    if (m_targets.HasDst())
    {
        float x, y, z;
        m_targets.GetDstPos()->GetPosition(x, y, z);

        if (!m_spellInfo->HasAttribute(SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS) && !DisableMgr::IsDisabledFor(DISABLE_TYPE_SPELL, m_spellInfo->Id, NULL, SPELL_DISABLE_LOS) && !m_caster->IsWithinLOS(x, y, z))
            return SPELL_FAILED_LINE_OF_SIGHT;
    }

    // check pet presence
    for (SpellEffectInfo const* effect : GetEffects())
    {
        if (effect && effect->TargetA.GetTarget() == TARGET_UNIT_PET)
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

    // Spell cast only in battleground
    if ((m_spellInfo->HasAttribute(SPELL_ATTR3_BATTLEGROUND)) &&  m_caster->GetTypeId() == TYPEID_PLAYER)
        if (!m_caster->ToPlayer()->InBattleground())
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
    if (m_caster->GetTypeId() == TYPEID_UNIT || !m_caster->ToPlayer()->IsGameMaster())
    {
        uint32 zone, area;
        m_caster->GetZoneAndAreaId(zone, area);

        SpellCastResult locRes = m_spellInfo->CheckLocation(m_caster->GetMapId(), zone, area, m_caster->ToPlayer());
        if (locRes != SPELL_CAST_OK)
            return locRes;
    }

    // not let players cast spells at mount (and let do it to creatures)
    if (m_caster->IsMounted() && m_caster->GetTypeId() == TYPEID_PLAYER && !(_triggeredCastFlags & TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE) &&
        !m_spellInfo->IsPassive() && !m_spellInfo->HasAttribute(SPELL_ATTR0_CASTABLE_WHILE_MOUNTED))
    {
        if (m_caster->IsInFlight())
            return SPELL_FAILED_NOT_ON_TAXI;
        else
            return SPELL_FAILED_NOT_MOUNTED;
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

    for (SpellEffectInfo const* effect : GetEffects())
    {
        if (!effect)
            continue;
        // for effects of spells that have only one target
        switch (effect->Effect)
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

                if (effect->TargetA.GetTarget() != TARGET_UNIT_PET)
                    break;

                Pet* pet = m_caster->ToPlayer()->GetPet();

                if (!pet)
                    return SPELL_FAILED_NO_PET;

                SpellInfo const* learn_spellproto = sSpellMgr->GetSpellInfo(effect->TriggerSpell);

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

                    SpellInfo const* learn_spellproto = sSpellMgr->GetSpellInfo(effect->TriggerSpell);

                    if (!learn_spellproto)
                        return SPELL_FAILED_NOT_KNOWN;

                    if (m_spellInfo->SpellLevel > pet->getLevel())
                        return SPELL_FAILED_LOWLEVEL;
                }
                break;
            }
            case SPELL_EFFECT_APPLY_GLYPH:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_GLYPH_NO_SPEC;

                Player* caster = m_caster->ToPlayer();
                if (!caster->HasSpell(m_misc.SpellId))
                    return SPELL_FAILED_NOT_KNOWN;

                if (uint32 glyphId = effect->MiscValue)
                {
                    GlyphPropertiesEntry const* glyphProperties = sGlyphPropertiesStore.LookupEntry(glyphId);
                    if (!glyphProperties)
                        return SPELL_FAILED_INVALID_GLYPH;

                    std::vector<uint32> const* glyphBindableSpells = sDB2Manager.GetGlyphBindableSpells(glyphId);
                    if (!glyphBindableSpells)
                        return SPELL_FAILED_INVALID_GLYPH;

                    if (std::find(glyphBindableSpells->begin(), glyphBindableSpells->end(), m_misc.SpellId) == glyphBindableSpells->end())
                        return SPELL_FAILED_INVALID_GLYPH;

                    if (std::vector<uint32> const* glyphRequiredSpecs = sDB2Manager.GetGlyphRequiredSpecs(glyphId))
                    {
                        if (!caster->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID))
                            return SPELL_FAILED_GLYPH_NO_SPEC;

                        if (std::find(glyphRequiredSpecs->begin(), glyphRequiredSpecs->end(), caster->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID)) == glyphRequiredSpecs->end())
                            return SPELL_FAILED_GLYPH_INVALID_SPEC;
                    }

                    uint32 replacedGlyph = 0;
                    for (uint32 activeGlyphId : caster->GetGlyphs(caster->GetActiveTalentGroup()))
                    {
                        if (std::vector<uint32> const* activeGlyphBindableSpells = sDB2Manager.GetGlyphBindableSpells(activeGlyphId))
                        {
                            if (std::find(activeGlyphBindableSpells->begin(), activeGlyphBindableSpells->end(), m_misc.SpellId) != activeGlyphBindableSpells->end())
                            {
                                replacedGlyph = activeGlyphId;
                                break;
                            }
                        }
                    }

                    for (uint32 activeGlyphId : caster->GetGlyphs(caster->GetActiveTalentGroup()))
                    {
                        if (activeGlyphId == replacedGlyph)
                            continue;

                        if (activeGlyphId == glyphId)
                            return SPELL_FAILED_UNIQUE_GLYPH;

                        if (sGlyphPropertiesStore.AssertEntry(activeGlyphId)->GlyphExclusiveCategoryID == glyphProperties->GlyphExclusiveCategoryID)
                            return SPELL_FAILED_GLYPH_EXCLUSIVE_CATEGORY;
                    }
                }
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

                if (m_caster->IsInCombat() || pet->IsInCombat())
                    return SPELL_FAILED_AFFECTING_COMBAT;

                break;
            }
            case SPELL_EFFECT_POWER_BURN:
            case SPELL_EFFECT_POWER_DRAIN:
            {
                // Can be area effect, Check only for players and not check if target - caster (spell can have multiply drain/burn effects)
                if (m_caster->GetTypeId() == TYPEID_PLAYER)
                    if (Unit* target = m_targets.GetUnitTarget())
                        if (target != m_caster && target->GetPowerType() != Powers(effect->MiscValue))
                            return SPELL_FAILED_BAD_TARGETS;
                break;
            }
            case SPELL_EFFECT_CHARGE:
            {
                if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CASTER_AURAS) && m_caster->HasUnitState(UNIT_STATE_ROOT))
                    return SPELL_FAILED_ROOTED;

                if (GetSpellInfo()->NeedsExplicitUnitTarget())
                {
                    Unit* target = m_targets.GetUnitTarget();
                    if (!target)
                        return SPELL_FAILED_DONT_REPORT;

                    float objSize = target->GetObjectSize();
                    float range = m_spellInfo->GetMaxRange(true, m_caster, this) * 1.5f + objSize; // can't be overly strict

                    m_preGeneratedPath = Trinity::make_unique<PathGenerator>(m_caster);
                    m_preGeneratedPath->SetPathLengthLimit(range);
                    // first try with raycast, if it fails fall back to normal path
                    float targetObjectSize = std::min(target->GetObjectSize(), 4.0f);
                    bool result = m_preGeneratedPath->CalculatePath(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ() + targetObjectSize, false, true);
                    if (m_preGeneratedPath->GetPathType() & PATHFIND_SHORT)
                        return SPELL_FAILED_OUT_OF_RANGE;
                    else if (!result || m_preGeneratedPath->GetPathType() & (PATHFIND_NOPATH | PATHFIND_INCOMPLETE))
                    {
                        result = m_preGeneratedPath->CalculatePath(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ() + targetObjectSize, false, false);
                        if (m_preGeneratedPath->GetPathType() & PATHFIND_SHORT)
                            return SPELL_FAILED_OUT_OF_RANGE;
                        else if (!result || m_preGeneratedPath->GetPathType() & (PATHFIND_NOPATH | PATHFIND_INCOMPLETE))
                            return SPELL_FAILED_NOPATH;
                        else if (m_preGeneratedPath->IsInvalidDestinationZ(target)) // Check position z, if not in a straight line
                            return SPELL_FAILED_NOPATH;
                    }
                    else if (m_preGeneratedPath->IsInvalidDestinationZ(target)) // Check position z, if in a straight line
                            return SPELL_FAILED_NOPATH;

                    m_preGeneratedPath->ReducePathLenghtByDist(objSize); // move back
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
                int32 TargetLevel = m_targets.GetUnitTarget()->GetLevelForTarget(m_caster);
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
                if (effect->TargetA.GetTarget() != TARGET_GAMEOBJECT_TARGET &&
                    effect->TargetA.GetTarget() != TARGET_GAMEOBJECT_ITEM_TARGET)
                    break;

                if (m_caster->GetTypeId() != TYPEID_PLAYER  // only players can open locks, gather etc.
                    // we need a go target in case of TARGET_GAMEOBJECT_TARGET
                    || (effect->TargetA.GetTarget() == TARGET_GAMEOBJECT_TARGET && !m_targets.GetGOTarget()))
                    return SPELL_FAILED_BAD_TARGETS;

                Item* pTempItem = NULL;
                if (m_targets.GetTargetMask() & TARGET_FLAG_TRADE_ITEM)
                {
                    if (TradeData* pTrade = m_caster->ToPlayer()->GetTradeData())
                        pTempItem = pTrade->GetTraderData()->GetItem(TradeSlots(m_targets.GetItemTargetGUID().GetRawValue().at(0)));  // at this point item target guid contains the trade slot
                }
                else if (m_targets.GetTargetMask() & TARGET_FLAG_ITEM)
                    pTempItem = m_caster->ToPlayer()->GetItemByGuid(m_targets.GetItemTargetGUID());

                // we need a go target, or an openable item target in case of TARGET_GAMEOBJECT_ITEM_TARGET
                if (effect->TargetA.GetTarget() == TARGET_GAMEOBJECT_ITEM_TARGET &&
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
                SpellCastResult res = CanOpenLock(effect->EffectIndex, lockId, skillId, reqSkillValue, skillValue);
                if (res != SPELL_CAST_OK)
                    return res;
                break;
            }
            case SPELL_EFFECT_RESURRECT_PET:
            {
                Creature* pet = m_caster->GetGuardianPet();

                if (pet && pet->IsAlive())
                    return SPELL_FAILED_ALREADY_HAVE_SUMMON;

                break;
            }
            // This is generic summon effect
            case SPELL_EFFECT_SUMMON:
            {
                SummonPropertiesEntry const* SummonProperties = sSummonPropertiesStore.LookupEntry(effect->MiscValueB);
                if (!SummonProperties)
                    break;
                switch (SummonProperties->Control)
                {
                    case SUMMON_CATEGORY_PET:
                        if (!m_spellInfo->HasAttribute(SPELL_ATTR1_DISMISS_PET) && !m_caster->GetPetGUID().IsEmpty())
                            return SPELL_FAILED_ALREADY_HAVE_SUMMON;
                    // intentional missing break, check both GetPetGUID() and GetCharmGUID for SUMMON_CATEGORY_PET
                    case SUMMON_CATEGORY_PUPPET:
                        if (!m_caster->GetCharmGUID().IsEmpty())
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
                    if (!m_spellInfo->HasAttribute(SPELL_ATTR1_DISMISS_PET) && !m_targets.GetUnitTarget()->GetPetGUID().IsEmpty())
                        return SPELL_FAILED_ALREADY_HAVE_SUMMON;
                }
                break;
            }
            case SPELL_EFFECT_SUMMON_PET:
            {
                if (!m_caster->GetPetGUID().IsEmpty())                  //let warlock do a replacement summon
                {
                    if (m_caster->GetTypeId() == TYPEID_PLAYER)
                    {
                        if (strict)                         //starting cast, trigger pet stun (cast by pet so it doesn't attack player)
                            if (Pet* pet = m_caster->ToPlayer()->GetPet())
                                pet->CastSpell(pet, 32752, true, NULL, NULL, pet->GetGUID());
                    }
                    else if (!m_spellInfo->HasAttribute(SPELL_ATTR1_DISMISS_PET))
                        return SPELL_FAILED_ALREADY_HAVE_SUMMON;
                }

                if (!m_caster->GetCharmGUID().IsEmpty())
                    return SPELL_FAILED_ALREADY_HAVE_CHARM;
                break;
            }
            case SPELL_EFFECT_SUMMON_PLAYER:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_BAD_TARGETS;
                if (!m_caster->GetTarget())
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
                    Difficulty difficulty = m_caster->GetMap()->GetDifficultyID();
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
                if (m_caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_BAD_TARGETS;

                Player* playerCaster = m_caster->ToPlayer();
                    //
                if (!(playerCaster->GetTarget()))
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
                if (m_caster->HasUnitState(UNIT_STATE_ROOT))
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
                ChrSpecializationEntry const* spec = sChrSpecializationStore.LookupEntry(m_misc.SpecializationId);
                Player* player = m_caster->ToPlayer();
                if (!player)
                    return SPELL_FAILED_TARGET_NOT_PLAYER;

                if (!spec || (spec->ClassID != m_caster->getClass() && !spec->IsPetSpecialization()))
                    return SPELL_FAILED_NO_SPEC;

                if (spec->IsPetSpecialization())
                {
                    Pet* pet = player->GetPet();
                    if (!pet || pet->getPetType() != HUNTER_PET || !pet->GetCharmInfo())
                        return SPELL_FAILED_NO_PET;
                }

                // can't change during already started arena/battleground
                if (Battleground const* bg = player->GetBattleground())
                    if (bg->GetStatus() == STATUS_IN_PROGRESS)
                        return SPELL_FAILED_NOT_IN_BATTLEGROUND;
                break;
            }
            case SPELL_EFFECT_REMOVE_TALENT:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_BAD_TARGETS;
                TalentEntry const* talent = sTalentStore.LookupEntry(m_misc.TalentId);
                if (!talent)
                    return SPELL_FAILED_DONT_REPORT;
                if (m_caster->GetSpellHistory()->HasCooldown(talent->SpellID))
                {
                    if (param1)
                        *param1 = talent->SpellID;
                    return SPELL_FAILED_CANT_UNTALENT;
                }
                break;
            }
            case SPELL_EFFECT_GIVE_ARTIFACT_POWER:
            case SPELL_EFFECT_GIVE_ARTIFACT_POWER_NO_BONUS:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_BAD_TARGETS;
                Aura* artifactAura = m_caster->GetAura(ARTIFACTS_ALL_WEAPONS_GENERAL_WEAPON_EQUIPPED_PASSIVE);
                if (!artifactAura)
                    return SPELL_FAILED_NO_ARTIFACT_EQUIPPED;
                Item* artifact = m_caster->ToPlayer()->GetItemByGuid(artifactAura->GetCastItemGUID());
                if (!artifact)
                    return SPELL_FAILED_NO_ARTIFACT_EQUIPPED;
                if (effect->Effect == SPELL_EFFECT_GIVE_ARTIFACT_POWER)
                {
                    ArtifactEntry const* artifactEntry = sArtifactStore.LookupEntry(artifact->GetTemplate()->GetArtifactID());
                    if (!artifactEntry || artifactEntry->ArtifactCategoryID != effect->MiscValue)
                        return SPELL_FAILED_WRONG_ARTIFACT_EQUIPPED;
                }
                break;
            }
            default:
                break;
        }
    }

    for (SpellEffectInfo const* effect : GetEffects())
    {
        if (!effect)
            continue;
        switch (effect->ApplyAuraName)
        {
            case SPELL_AURA_MOD_POSSESS_PET:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_NO_PET;

                Pet* pet = m_caster->ToPlayer()->GetPet();
                if (!pet)
                    return SPELL_FAILED_NO_PET;

                if (!pet->GetCharmerGUID().IsEmpty())
                    return SPELL_FAILED_CHARMED;
                break;
            }
            case SPELL_AURA_MOD_POSSESS:
            case SPELL_AURA_MOD_CHARM:
            case SPELL_AURA_AOE_CHARM:
            {
                if (!m_caster->GetCharmerGUID().IsEmpty())
                    return SPELL_FAILED_CHARMED;

                if (effect->ApplyAuraName == SPELL_AURA_MOD_CHARM
                    || effect->ApplyAuraName == SPELL_AURA_MOD_POSSESS)
                {
                    if (!m_spellInfo->HasAttribute(SPELL_ATTR1_DISMISS_PET) && !m_caster->GetPetGUID().IsEmpty())
                        return SPELL_FAILED_ALREADY_HAVE_SUMMON;

                    if (!m_caster->GetCharmGUID().IsEmpty())
                        return SPELL_FAILED_ALREADY_HAVE_CHARM;
                }

                if (Unit* target = m_targets.GetUnitTarget())
                {
                    if (target->GetTypeId() == TYPEID_UNIT && target->IsVehicle())
                        return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

                    if (target->IsMounted())
                        return SPELL_FAILED_CANT_BE_CHARMED;

                    if (!target->GetCharmerGUID().IsEmpty())
                        return SPELL_FAILED_CHARMED;

                    if (target->GetOwner() && target->GetOwner()->GetTypeId() == TYPEID_PLAYER)
                        return SPELL_FAILED_TARGET_IS_PLAYER_CONTROLLED;

                    int32 value = CalculateDamage(effect->EffectIndex, target);
                    if (value && int32(target->GetLevelForTarget(m_caster)) > value)
                        return SPELL_FAILED_HIGHLEVEL;
                }

                break;
            }
            case SPELL_AURA_MOUNTED:
            {
                if (m_caster->IsInWater() && m_spellInfo->HasAura(m_caster->GetMap()->GetDifficultyID(), SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED))
                    return SPELL_FAILED_ONLY_ABOVEWATER;

                // Ignore map check if spell have AreaId. AreaId already checked and this prevent special mount spells
                bool allowMount = !m_caster->GetMap()->IsDungeon() || m_caster->GetMap()->IsBattlegroundOrArena();
                InstanceTemplate const* it = sObjectMgr->GetInstanceTemplate(m_caster->GetMapId());
                if (it)
                    allowMount = it->AllowMount;
                if (m_caster->GetTypeId() == TYPEID_PLAYER && !allowMount && !m_spellInfo->RequiredAreasID)
                    return SPELL_FAILED_NO_MOUNTS_ALLOWED;

                if (m_caster->IsInDisallowedMountForm())
                    return SPELL_FAILED_NOT_SHAPESHIFT;

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
                    Battlefield* Bf = sBattlefieldMgr->GetBattlefieldToZoneId(m_originalCaster->GetZoneId());
                    if (AreaTableEntry const* area = sAreaTableStore.LookupEntry(m_originalCaster->GetAreaId()))
                        if (area->Flags[0] & AREA_FLAG_NO_FLY_ZONE  || (Bf && !Bf->CanFlyIn()))
                            return SPELL_FAILED_NOT_HERE;
                }
                break;
            }
            case SPELL_AURA_PERIODIC_MANA_LEECH:
            {
                if (effect->IsTargetingArea())
                    break;

                if (!m_targets.GetUnitTarget())
                    return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

                if (m_caster->GetTypeId() != TYPEID_PLAYER || m_CastItem)
                    break;

                if (m_targets.GetUnitTarget()->GetPowerType() != POWER_MANA)
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

        if (m_targets.GetItemTargetGUID() != ObjectGuid::TradeItem)
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
    if (m_caster->HasUnitState(UNIT_STATE_CASTING) && !(_triggeredCastFlags & TRIGGERED_IGNORE_CAST_IN_PROGRESS))              //prevent spellcast interruption by another spellcast
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

    // check cooldown
    if (Creature* creatureCaster = m_caster->ToCreature())
        if (!creatureCaster->GetSpellHistory()->IsReady(m_spellInfo))
            return SPELL_FAILED_NOT_READY;

    // Check if spell is affected by GCD
    if (m_spellInfo->StartRecoveryCategory > 0)
        if (m_caster->GetCharmInfo() && m_caster->GetSpellHistory()->HasGlobalCooldown(m_spellInfo))
            return SPELL_FAILED_NOT_READY;

    return CheckCast(true);
}

SpellCastResult Spell::CheckCasterAuras(uint32* param1) const
{
    // spells totally immuned to caster auras (wsg flag drop, give marks etc)
    if (m_spellInfo->HasAttribute(SPELL_ATTR6_IGNORE_CASTER_AURAS))
        return SPELL_CAST_OK;

    bool usableWhileStunned = m_spellInfo->HasAttribute(SPELL_ATTR5_USABLE_WHILE_STUNNED);
    bool usableWhileFeared = m_spellInfo->HasAttribute(SPELL_ATTR5_USABLE_WHILE_FEARED);
    bool usableWhileConfused = m_spellInfo->HasAttribute(SPELL_ATTR5_USABLE_WHILE_CONFUSED);

    // Check whether the cast should be prevented by any state you might have.
    SpellCastResult result = SPELL_CAST_OK;

    // Get unit state
    uint32 const unitflag = m_caster->GetUInt32Value(UNIT_FIELD_FLAGS);

    // this check should only be done when player does cast directly
    // (ie not when it's called from a script) Breaks for example PlayerAI when charmed
    /*
    if (!m_caster->GetCharmerGUID().IsEmpty())
    {
        if (Unit* charmer = m_caster->GetCharmer())
            if (charmer->GetUnitBeingMoved() != m_caster && !CheckSpellCancelsCharm(param1))
                result = SPELL_FAILED_CHARMED;
    }
    */

    if (unitflag & UNIT_FLAG_STUNNED)
    {
        // spell is usable while stunned, check if caster has allowed stun auras, another stun types must prevent cast spell
        if (usableWhileStunned)
        {
            static uint32 const allowedStunMask =
                1 << MECHANIC_STUN
                | 1 << MECHANIC_SLEEP;

            bool foundNotStun = false;
            Unit::AuraEffectList const& stunAuras = m_caster->GetAuraEffectsByType(SPELL_AURA_MOD_STUN);
            for (AuraEffect const* stunEff : stunAuras)
            {
                uint32 const stunMechanicMask = stunEff->GetSpellInfo()->GetAllEffectsMechanicMask();
                if (stunMechanicMask && !(stunMechanicMask & allowedStunMask))
                {
                    foundNotStun = true;

                    // fill up aura mechanic info to send client proper error message
                    if (param1)
                    {
                        *param1 = stunEff->GetSpellInfo()->GetEffect(stunEff->GetEffIndex())->Mechanic;
                        if (!*param1)
                            *param1 = stunEff->GetSpellInfo()->Mechanic;
                    }
                    break;
                }
            }

            if (foundNotStun)
                result = SPELL_FAILED_STUNNED;
        }
        // Not usable while stunned, however spell might provide some immunity that allows to cast it anyway
        else if (!CheckSpellCancelsStun(param1))
            result = SPELL_FAILED_STUNNED;
    }
    else if (unitflag & UNIT_FLAG_SILENCED && m_spellInfo->PreventionType & SPELL_PREVENTION_TYPE_SILENCE && !CheckSpellCancelsSilence(param1))
        result = SPELL_FAILED_SILENCED;
    else if (unitflag & UNIT_FLAG_PACIFIED && m_spellInfo->PreventionType & SPELL_PREVENTION_TYPE_PACIFY && !CheckSpellCancelsPacify(param1))
        result = SPELL_FAILED_PACIFIED;
    else if (unitflag & UNIT_FLAG_FLEEING && !usableWhileFeared && !CheckSpellCancelsFear(param1))
        result = SPELL_FAILED_FLEEING;
    else if (unitflag & UNIT_FLAG_CONFUSED && !usableWhileConfused && !CheckSpellCancelsConfuse(param1))
        result = SPELL_FAILED_CONFUSED;
    else if (m_caster->HasFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_NO_ACTIONS) && m_spellInfo->PreventionType & SPELL_PREVENTION_TYPE_NO_ACTIONS)
        result = SPELL_FAILED_NO_ACTIONS;

    // Attr must make flag drop spell totally immune from all effects
    if (result != SPELL_CAST_OK)
        return (param1 && *param1) ? SPELL_FAILED_PREVENTED_BY_MECHANIC : result;

    return SPELL_CAST_OK;
}

bool Spell::CheckSpellCancelsAuraEffect(AuraType auraType, uint32* param1) const
{
    // Checking auras is needed now, because you are prevented by some state but the spell grants immunity.
    Unit::AuraEffectList const& auraEffects = m_caster->GetAuraEffectsByType(auraType);
    if (auraEffects.empty())
        return true;

    for (AuraEffect const* aurEff : auraEffects)
    {
        if (m_spellInfo->SpellCancelsAuraEffect(aurEff))
            continue;

        if (param1)
        {
            *param1 = aurEff->GetSpellEffectInfo()->Mechanic;
            if (!*param1)
                *param1 = aurEff->GetSpellInfo()->Mechanic;
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

SpellCastResult Spell::CheckArenaAndRatedBattlegroundCastRules()
{
    bool isRatedBattleground = false; // NYI
    bool isArena = !isRatedBattleground;

    // check USABLE attributes
    // USABLE takes precedence over NOT_USABLE
    if (isRatedBattleground && m_spellInfo->HasAttribute(SPELL_ATTR9_USABLE_IN_RATED_BATTLEGROUNDS))
        return SPELL_CAST_OK;

    if (isArena && m_spellInfo->HasAttribute(SPELL_ATTR4_USABLE_IN_ARENA))
        return SPELL_CAST_OK;

    // check NOT_USABLE attributes
    if (m_spellInfo->HasAttribute(SPELL_ATTR4_NOT_USABLE_IN_ARENA_OR_RATED_BG))
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

int32 Spell::CalculateDamage(uint8 i, Unit const* target, float* var /*= nullptr*/) const
{
    return m_caster->CalculateSpellDamage(target, m_spellInfo, i, &m_spellValue->EffectBasePoints[i], var, m_castItemLevel);
}

bool Spell::CanAutoCast(Unit* target)
{
    if (!target)
        return (CheckPetCast(target) == SPELL_CAST_OK);

    ObjectGuid targetguid = target->GetGUID();

    // check if target already has the same or a more powerful aura
    for (SpellEffectInfo const* effect : GetEffects())
    {
        if (!effect)
            continue;

        if (!effect->IsAura())
            continue;

        AuraType const& auraType = AuraType(effect->ApplyAuraName);
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
                    if (abs(effect->BasePoints) <= abs((*auraIt)->GetAmount()))
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
        for (std::vector<TargetInfo>::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
            if (ihit->targetGUID == targetguid)
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

    // get square values for sqr distance checks
    minRange *= minRange;
    maxRange *= maxRange;

    Unit* target = m_targets.GetUnitTarget();
    if (target && target != m_caster)
    {
        if (m_caster->GetExactDistSq(target) > maxRange)
            return SPELL_FAILED_OUT_OF_RANGE;

        if (minRange > 0.0f && m_caster->GetExactDistSq(target) < minRange)
            return SPELL_FAILED_OUT_OF_RANGE;

        if (m_caster->GetTypeId() == TYPEID_PLAYER &&
            (((m_spellInfo->FacingCasterFlags & SPELL_FACING_FLAG_INFRONT) && !m_caster->HasInArc(static_cast<float>(M_PI), target))
                && !m_caster->IsWithinBoundaryRadius(target)))
            return SPELL_FAILED_UNIT_NOT_INFRONT;
    }

    if (m_targets.HasDst() && !m_targets.HasTraj())
    {
        if (m_caster->GetExactDistSq(m_targets.GetDstPos()) > maxRange)
            return SPELL_FAILED_OUT_OF_RANGE;
        if (minRange > 0.0f && m_caster->GetExactDistSq(m_targets.GetDstPos()) < minRange)
            return SPELL_FAILED_OUT_OF_RANGE;
    }

    return SPELL_CAST_OK;
}

std::pair<float, float> Spell::GetMinMaxRange(bool strict) const
{
    float rangeMod = 0.0f;
    float minRange = 0.0f;
    float maxRange = 0.0f;
    if (strict && m_spellInfo->IsNextMeleeSwingSpell())
    {
        maxRange = 100.0f;
        return std::pair<float, float>(minRange, maxRange);
    }

    if (m_spellInfo->RangeEntry)
    {
        Unit* target = m_targets.GetUnitTarget();
        if (m_spellInfo->RangeEntry->Flags & SPELL_RANGE_MELEE)
        {
            rangeMod = m_caster->GetMeleeRange(target ? target : m_caster); // when the target is not a unit, take the caster's combat reach as the target's combat reach.
        }
        else
        {
            float meleeRange = 0.0f;
            if (m_spellInfo->RangeEntry->Flags & SPELL_RANGE_RANGED)
                meleeRange = m_caster->GetMeleeRange(target ? target : m_caster); // when the target is not a unit, take the caster's combat reach as the target's combat reach.

            minRange = m_caster->GetSpellMinRangeForTarget(target, m_spellInfo) + meleeRange;
            maxRange = m_caster->GetSpellMaxRangeForTarget(target, m_spellInfo);

            if (target || m_targets.GetCorpseTarget())
            {
                rangeMod = m_caster->GetCombatReach() + (target ? target->GetCombatReach() : m_caster->GetCombatReach());

                if (minRange > 0.0f && !(m_spellInfo->RangeEntry->Flags & SPELL_RANGE_RANGED))
                    minRange += rangeMod;
            }
        }

        if (target && m_caster->isMoving() && target->isMoving() && !m_caster->IsWalking() && !target->IsWalking() &&
            (m_spellInfo->RangeEntry->Flags & SPELL_RANGE_MELEE || target->GetTypeId() == TYPEID_PLAYER))
            rangeMod += 8.0f / 3.0f;
    }

    if (m_spellInfo->HasAttribute(SPELL_ATTR0_REQ_AMMO) && m_caster->GetTypeId() == TYPEID_PLAYER)
        if (Item* ranged = m_caster->ToPlayer()->GetWeaponForAttack(RANGED_ATTACK, true))
            maxRange *= ranged->GetTemplate()->GetRangedModRange() * 0.01f;

    if (Player* modOwner = m_caster->GetSpellModOwner())
        modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RANGE, maxRange, const_cast<Spell*>(this));

    maxRange += rangeMod;

    return std::pair<float, float>(minRange, maxRange);
}

SpellCastResult Spell::CheckPower() const
{
    // item cast not used power
    if (m_CastItem)
        return SPELL_CAST_OK;

    for (SpellPowerCost const& cost : m_powerCost)
    {
        // health as power used - need check health amount
        if (cost.Power == POWER_HEALTH)
        {
            if (int32(m_caster->GetHealth()) <= cost.Amount)
                return SPELL_FAILED_CASTER_AURASTATE;
            continue;
        }
        // Check valid power type
        if (cost.Power >= MAX_POWERS)
        {
            TC_LOG_ERROR("spells", "Spell::CheckPower: Unknown power type '%d'", cost.Power);
            return SPELL_FAILED_UNKNOWN;
        }

        //check rune cost only if a spell has PowerType == POWER_RUNES
        if (cost.Power == POWER_RUNES)
        {
            SpellCastResult failReason = CheckRuneCost();
            if (failReason != SPELL_CAST_OK)
                return failReason;
        }

        // Check power amount
        if (int32(m_caster->GetPower(cost.Power)) < cost.Amount)
            return SPELL_FAILED_NO_POWER;
    }

    return SPELL_CAST_OK;
}

SpellCastResult Spell::CheckItems(uint32* param1 /*= nullptr*/, uint32* param2 /*= nullptr*/) const
{
    Player* player = m_caster->ToPlayer();
    if (!player)
        return SPELL_CAST_OK;

    if (m_spellInfo->HasAttribute(SPELL_ATTR2_IGNORE_ITEM_CHECK))
        return SPELL_CAST_OK;

    if (!m_CastItem)
    {
        if (!m_castItemGUID.IsEmpty())
            return SPELL_FAILED_ITEM_NOT_READY;
    }
    else
    {
        uint32 itemid = m_CastItem->GetEntry();
        if (!player->HasItemCount(itemid))
            return SPELL_FAILED_ITEM_NOT_READY;

        ItemTemplate const* proto = m_CastItem->GetTemplate();
        if (!proto)
            return SPELL_FAILED_ITEM_NOT_READY;

        for (uint8 i = 0; i < proto->Effects.size() && i < 5; ++i)
            if (proto->Effects[i]->Charges)
                if (m_CastItem->GetSpellCharges(i) == 0)
                    return SPELL_FAILED_NO_CHARGES_REMAIN;

        // consumable cast item checks
        if (proto->GetClass() == ITEM_CLASS_CONSUMABLE && m_targets.GetUnitTarget())
        {
            // such items should only fail if there is no suitable effect at all - see Rejuvenation Potions for example
            SpellCastResult failReason = SPELL_CAST_OK;
            for (SpellEffectInfo const* effect : GetEffects())
            {
                // skip check, pet not required like checks, and for TARGET_UNIT_PET m_targets.GetUnitTarget() is not the real target but the caster
                if (!effect || effect->TargetA.GetTarget() == TARGET_UNIT_PET)
                    continue;

                if (effect->Effect == SPELL_EFFECT_HEAL)
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
                if (effect->Effect == SPELL_EFFECT_ENERGIZE)
                {
                    if (effect->MiscValue < 0 || effect->MiscValue >= int8(MAX_POWERS))
                    {
                        failReason = SPELL_FAILED_ALREADY_AT_FULL_POWER;
                        continue;
                    }

                    Powers power = Powers(effect->MiscValue);
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
    if (!m_targets.GetItemTargetGUID().IsEmpty())
    {
        Item* item = m_targets.GetItemTarget();
        if (!item)
            return SPELL_FAILED_ITEM_GONE;

        if (!item->IsFitToSpellRequirements(m_spellInfo))
            return SPELL_FAILED_EQUIPPED_ITEM_CLASS;
    }
    // if not item target then required item must be equipped
    else
    {
        if (!(_triggeredCastFlags & TRIGGERED_IGNORE_EQUIPPED_ITEM_REQUIREMENT))
            if (!player->HasItemFitToSpellRequirements(m_spellInfo))
                return SPELL_FAILED_EQUIPPED_ITEM_CLASS;
    }

    // do not take reagents for these item casts
    if (!(m_CastItem && m_CastItem->GetTemplate()->GetFlags() & ITEM_FLAG_NO_REAGENT_COST))
    {
        bool checkReagents = !(_triggeredCastFlags & TRIGGERED_IGNORE_POWER_AND_REAGENT_COST) && !player->CanNoReagentCast(m_spellInfo);
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
                    for (uint8 s = 0; s < proto->Effects.size() && s < 5; ++s)
                    {
                        // CastItem will be used up and does not count as reagent
                        int32 charges = m_CastItem->GetSpellCharges(s);
                        if (proto->Effects[s]->Charges < 0 && abs(charges) < 2)
                        {
                            ++itemcount;
                            break;
                        }
                    }
                }
                if (!player->HasItemCount(itemid, itemcount))
                {
                    if (param1)
                        *param1 = itemid;
                    return SPELL_FAILED_REAGENTS;
                }
            }
        }

        // check totem-item requirements (items presence in inventory)
        uint32 totems = 2;
        for (uint8 i = 0; i < 2; ++i)
        {
            if (m_spellInfo->Totem[i] != 0)
            {
                if (player->HasItemCount(m_spellInfo->Totem[i]))
                {
                    totems -= 1;
                    continue;
                }
            }
            else
                totems -= 1;
        }

        if (totems != 0)
            return SPELL_FAILED_TOTEMS;

        // Check items for TotemCategory (items presence in inventory)
        uint32 totemCategory = 2;
        for (uint8 i = 0; i < 2; ++i)
        {
            if (m_spellInfo->TotemCategory[i] != 0)
            {
                if (player->HasItemTotemCategory(m_spellInfo->TotemCategory[i]))
                {
                    totemCategory -= 1;
                    continue;
                }
            }
            else
                totemCategory -= 1;
        }

        if (totemCategory != 0)
            return SPELL_FAILED_TOTEM_CATEGORY;
    }

    // special checks for spell effects
    for (SpellEffectInfo const* effect : GetEffects())
    {
        if (!effect)
            continue;

        switch (effect->Effect)
        {
            case SPELL_EFFECT_CREATE_ITEM:
            case SPELL_EFFECT_CREATE_LOOT:
            {
                if (!IsTriggered() && effect->ItemType)
                {
                    ItemPosCountVec dest;
                    InventoryResult msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, effect->ItemType, 1);
                    if (msg != EQUIP_ERR_OK)
                    {
                        ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(effect->ItemType);
                        /// @todo Needs review
                        if (pProto && !(pProto->GetItemLimitCategory()))
                        {
                            player->SendEquipError(msg, NULL, NULL, effect->ItemType);
                            return SPELL_FAILED_DONT_REPORT;
                        }
                        else
                        {
                            if (!(m_spellInfo->SpellFamilyName == SPELLFAMILY_MAGE && (m_spellInfo->SpellFamilyFlags[0] & 0x40000000)))
                                return SPELL_FAILED_TOO_MANY_OF_ITEM;
                            else if (!(player->HasItemCount(effect->ItemType)))
                                return SPELL_FAILED_TOO_MANY_OF_ITEM;
                            else if (SpellEffectInfo const* efi = GetEffect(EFFECT_1))
                                player->CastSpell(m_caster, efi->CalcValue(), false);        // move this to anywhere
                            return SPELL_FAILED_DONT_REPORT;
                        }
                    }
                }
                break;
            }
            case SPELL_EFFECT_ENCHANT_ITEM:
                if (effect->ItemType && m_targets.GetItemTarget()
                    && (m_targets.GetItemTarget()->IsVellum()))
                {
                    // cannot enchant vellum for other player
                    if (m_targets.GetItemTarget()->GetOwner() != m_caster)
                        return SPELL_FAILED_NOT_TRADEABLE;
                    // do not allow to enchant vellum from scroll made by vellum-prevent exploit
                    if (m_CastItem && m_CastItem->GetTemplate()->GetFlags() & ITEM_FLAG_NO_REAGENT_COST)
                        return SPELL_FAILED_TOTEM_CATEGORY;
                    ItemPosCountVec dest;
                    InventoryResult msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, effect->ItemType, 1);
                    if (msg != EQUIP_ERR_OK)
                    {
                        player->SendEquipError(msg, NULL, NULL, effect->ItemType);
                        return SPELL_FAILED_DONT_REPORT;
                    }
                }
                // no break
            case SPELL_EFFECT_ENCHANT_ITEM_PRISMATIC:
            {
                Item* targetItem = m_targets.GetItemTarget();
                if (!targetItem)
                    return SPELL_FAILED_ITEM_NOT_FOUND;

                if (targetItem->GetTemplate()->GetBaseItemLevel() < m_spellInfo->BaseLevel)
                    return SPELL_FAILED_LOWLEVEL;

                bool isItemUsable = false;
                ItemTemplate const* proto = targetItem->GetTemplate();
                for (uint8 e = 0; e < proto->Effects.size(); ++e)
                {
                    if (proto->Effects[e]->SpellID && proto->Effects[e]->TriggerType == ITEM_SPELLTRIGGER_ON_USE)
                    {
                        isItemUsable = true;
                        break;
                    }
                }

                SpellItemEnchantmentEntry const* enchantEntry = sSpellItemEnchantmentStore.LookupEntry(effect->MiscValue);
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

                // Not allow enchant in trade slot for some enchant type
                if (targetItem->GetOwner() != m_caster)
                {
                    if (!enchantEntry)
                        return SPELL_FAILED_ERROR;
                    if (enchantEntry->Flags & ENCHANTMENT_CAN_SOULBOUND)
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
                    uint32 enchant_id = effect->MiscValue;
                    SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
                    if (!pEnchant)
                        return SPELL_FAILED_ERROR;
                    if (pEnchant->Flags & ENCHANTMENT_CAN_SOULBOUND)
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
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;

                // prevent disenchanting in trade slot
                if (item->GetOwnerGUID() != m_caster->GetGUID())
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;

                ItemTemplate const* itemProto = item->GetTemplate();
                if (!itemProto)
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;

                ItemDisenchantLootEntry const* itemDisenchantLoot = item->GetDisenchantLoot(m_caster->ToPlayer());
                if (!itemDisenchantLoot)
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;
                if (itemDisenchantLoot->SkillRequired > player->GetSkillValue(SKILL_ENCHANTING))
                    return SPELL_FAILED_LOW_CASTLEVEL;
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
                if (item->GetOwnerGUID() != m_caster->GetGUID())
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
                if (item->GetOwnerGUID() != m_caster->GetGUID())
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

                Item* pItem = player->GetWeaponForAttack(m_attackType);
                if (!pItem || pItem->IsBroken())
                    return SPELL_FAILED_EQUIPPED_ITEM;

                switch (pItem->GetTemplate()->GetSubClass())
                {
                    case ITEM_SUBCLASS_WEAPON_THROWN:
                    {
                        uint32 ammo = pItem->GetEntry();
                        if (!player->HasItemCount(ammo))
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
                 uint32 itemId = effect->ItemType;

                 ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemId);
                 if (!proto)
                     return SPELL_FAILED_ITEM_AT_MAX_CHARGES;

                 if (Item* item = player->GetItemByEntry(itemId))
                 {
                     for (uint8 x = 0; x < proto->Effects.size() && x < 5; ++x)
                         if (proto->Effects[x]->Charges != 0 && item->GetSpellCharges(x) == proto->Effects[x]->Charges)
                             return SPELL_FAILED_ITEM_AT_MAX_CHARGES;
                 }
                 break;
            }
            default:
                break;
        }
    }

    // check weapon presence in slots for main/offhand weapons
    if (!(_triggeredCastFlags & TRIGGERED_IGNORE_EQUIPPED_ITEM_REQUIREMENT) && m_spellInfo->EquippedItemClass >= 0)
    {
        auto weaponCheck = [this](WeaponAttackType attackType) -> SpellCastResult
        {
            Item const* item = m_caster->ToPlayer()->GetWeaponForAttack(attackType);

            // skip spell if no weapon in slot or broken
            if (!item || item->IsBroken())
                return SPELL_FAILED_EQUIPPED_ITEM_CLASS;

            // skip spell if weapon not fit to triggered spell
            if (!item->IsFitToSpellRequirements(m_spellInfo))
                return SPELL_FAILED_EQUIPPED_ITEM_CLASS;

            return SPELL_CAST_OK;
        };

        if (m_spellInfo->HasAttribute(SPELL_ATTR3_MAIN_HAND))
        {
            SpellCastResult mainHandResult = weaponCheck(BASE_ATTACK);
            if (mainHandResult != SPELL_CAST_OK)
                return mainHandResult;
        }

        if (m_spellInfo->HasAttribute(SPELL_ATTR3_REQ_OFFHAND))
        {
            SpellCastResult offHandResult = weaponCheck(OFF_ATTACK);
            if (offHandResult != SPELL_CAST_OK)
                return offHandResult;
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

    AddPct(delaytime, -delayReduce);

    if (m_timer + delaytime > m_casttime)
    {
        delaytime = m_casttime - m_timer;
        m_timer = m_casttime;
    }
    else
        m_timer += delaytime;

    TC_LOG_DEBUG("spells", "Spell %u partially interrupted for (%d) ms at damage", m_spellInfo->Id, delaytime);

    WorldPackets::Spells::SpellDelayed spellDelayed;
    spellDelayed.Caster = m_caster->GetGUID();
    spellDelayed.ActualDelay = delaytime;

    m_caster->SendMessageToSet(spellDelayed.Write(), true);
}

void Spell::DelayedChannel()
{
    if (!m_caster || m_caster->GetTypeId() != TYPEID_PLAYER || getState() != SPELL_STATE_CASTING)
        return;

    if (isDelayableNoMore())                                    // Spells may only be delayed twice
        return;

    //check pushback reduce
    // should be affected by modifiers, not take the dbc duration.
    int32 duration = ((m_channeledDuration > 0) ? m_channeledDuration : m_spellInfo->GetDuration());

    int32 delaytime = CalculatePct(duration, 25); // channeling delay is normally 25% of its time per hit
    int32 delayReduce = 100;                                    // must be initialized to 100 for percent modifiers
    m_caster->ToPlayer()->ApplySpellMod(m_spellInfo->Id, SPELLMOD_NOT_LOSE_CASTING_TIME, delayReduce, this);
    delayReduce += m_caster->GetTotalAuraModifier(SPELL_AURA_REDUCE_PUSHBACK) - 100;
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

    TC_LOG_DEBUG("spells", "Spell %u partially interrupted for %i ms, new duration: %u ms", m_spellInfo->Id, delaytime, m_timer);

    for (std::vector<TargetInfo>::const_iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
        if ((*ihit).missCondition == SPELL_MISS_NONE)
            if (Unit* unit = (m_caster->GetGUID() == ihit->targetGUID) ? m_caster : ObjectAccessor::GetUnit(*m_caster, ihit->targetGUID))
                unit->DelayOwnedAuras(m_spellInfo->Id, m_originalCasterGUID, delaytime);

    // partially interrupt persistent area auras
    if (DynamicObject* dynObj = m_caster->GetDynObject(m_spellInfo->Id))
        dynObj->Delay(delaytime);

    SendChannelUpdate(m_timer);
}

bool Spell::UpdatePointers()
{
    if (m_originalCasterGUID == m_caster->GetGUID())
        m_originalCaster = m_caster;
    else
    {
        m_originalCaster = ObjectAccessor::GetUnit(*m_caster, m_originalCasterGUID);
        if (m_originalCaster && !m_originalCaster->IsInWorld())
            m_originalCaster = NULL;
    }

    if (!m_castItemGUID.IsEmpty() && m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        m_CastItem = m_caster->ToPlayer()->GetItemByGuid(m_castItemGUID);
        m_castItemLevel = -1;
        // cast item not found, somehow the item is no longer where we expected
        if (!m_CastItem)
            return false;

        // check if the item is really the same, in case it has been wrapped for example
        if (m_castItemEntry != m_CastItem->GetEntry())
            return false;

        m_castItemLevel = int32(m_CastItem->GetItemLevel(m_caster->ToPlayer()));
    }

    m_targets.Update(m_caster);

    // further actions done only for dest targets
    if (!m_targets.HasDst())
        return true;

    // cache last transport
    WorldObject* transport = NULL;

    // update effect destinations (in case of moved transport dest target)
    for (SpellEffectInfo const* effect : GetEffects())
    {
        if (!effect)
            continue;

        SpellDestination& dest = m_destTargets[effect->EffectIndex];
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

bool Spell::CheckEffectTarget(Unit const* target, SpellEffectInfo const* effect, Position const* losPosition) const
{
    if (!effect->IsEffect())
        return false;

    switch (effect->ApplyAuraName)
    {
        case SPELL_AURA_MOD_POSSESS:
        case SPELL_AURA_MOD_CHARM:
        case SPELL_AURA_MOD_POSSESS_PET:
        case SPELL_AURA_AOE_CHARM:
            if (target->GetTypeId() == TYPEID_UNIT && target->IsVehicle())
                return false;
            if (target->IsMounted())
                return false;
            if (!target->GetCharmerGUID().IsEmpty())
                return false;
            if (int32 value = CalculateDamage(effect->EffectIndex, target))
                if ((int32)target->GetLevelForTarget(m_caster) > value)
                    return false;
            break;
        default:
            break;
    }

    // check for ignore LOS on the effect itself
    if (m_spellInfo->HasAttribute(SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS) || DisableMgr::IsDisabledFor(DISABLE_TYPE_SPELL, m_spellInfo->Id, NULL, SPELL_DISABLE_LOS))
        return true;

    // if spell is triggered, need to check for LOS disable on the aura triggering it and inherit that behaviour
    if (IsTriggered() && m_triggeredByAuraSpell && (m_triggeredByAuraSpell->HasAttribute(SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS) || DisableMgr::IsDisabledFor(DISABLE_TYPE_SPELL, m_triggeredByAuraSpell->Id, NULL, SPELL_DISABLE_LOS)))
        return true;

    /// @todo shit below shouldn't be here, but it's temporary
    //Check targets for LOS visibility
    if (losPosition)
        return target->IsWithinLOS(losPosition->GetPositionX(), losPosition->GetPositionY(), losPosition->GetPositionZ());
    else
    {
        // Get GO cast coordinates if original caster -> GO
        WorldObject* caster = NULL;
        if (m_originalCasterGUID.IsGameObject())
            caster = m_caster->GetMap()->GetGameObject(m_originalCasterGUID);
        if (!caster)
            caster = m_caster;
        if (target != m_caster && !target->IsWithinLOSInMap(caster))
            return false;
    }

    return true;
}

bool Spell::CheckEffectTarget(GameObject const* target, SpellEffectInfo const* effect) const
{
    if (!effect->IsEffect())
        return false;

    switch (effect->Effect)
    {
        case SPELL_EFFECT_GAMEOBJECT_DAMAGE:
        case SPELL_EFFECT_GAMEOBJECT_REPAIR:
        case SPELL_EFFECT_GAMEOBJECT_SET_DESTRUCTION_STATE:
            if (target->GetGoType() != GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING)
                return false;
            break;
        default:
            break;
    }

    return true;
}

bool Spell::CheckEffectTarget(Item const* /*target*/, SpellEffectInfo const* effect) const
{
    if (!effect->IsEffect())
        return false;

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

bool Spell::IsProcDisabled() const
{
    return (_triggeredCastFlags & TRIGGERED_DISALLOW_PROC_EVENTS) != 0;
}

bool Spell::IsChannelActive() const
{
    return m_caster->GetChannelSpellId() != 0;
}

bool Spell::IsAutoActionResetSpell() const
{
    /// @todo changed SPELL_INTERRUPT_FLAG_AUTOATTACK -> SPELL_INTERRUPT_FLAG_INTERRUPT to fix compile - is this check correct at all?
    if (IsTriggered() || !(m_spellInfo->InterruptFlags & SPELL_INTERRUPT_FLAG_INTERRUPT))
        return false;

    if (!m_casttime && m_spellInfo->HasAttribute(SPELL_ATTR6_NOT_RESET_SWING_IF_INSTANT))
        return false;

    return true;
}

bool Spell::IsNeedSendToClient() const
{
    return m_SpellVisual || m_spellInfo->IsChanneled() ||
        (m_spellInfo->HasAttribute(SPELL_ATTR8_AURA_SEND_AMOUNT)) || m_spellInfo->Speed > 0.0f || (!m_triggeredByAuraSpell && !IsTriggered());
}

bool Spell::HaveTargetsForEffect(uint8 effect) const
{
    for (std::vector<TargetInfo>::const_iterator itr = m_UniqueTargetInfo.begin(); itr != m_UniqueTargetInfo.end(); ++itr)
        if (itr->effectMask & (1 << effect))
            return true;

    for (std::vector<GOTargetInfo>::const_iterator itr = m_UniqueGOTargetInfo.begin(); itr != m_UniqueGOTargetInfo.end(); ++itr)
        if (itr->effectMask & (1 << effect))
            return true;

    for (std::vector<ItemTargetInfo>::const_iterator itr = m_UniqueItemInfo.begin(); itr != m_UniqueItemInfo.end(); ++itr)
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
        TC_LOG_ERROR("spells", "~SpellEvent: %s %s tried to delete non-deletable spell %u. Was not deleted, causes memory leak.",
            (m_Spell->GetCaster()->GetTypeId() == TYPEID_PLAYER ? "Player" : "Creature"), m_Spell->GetCaster()->GetGUID().ToString().c_str(), m_Spell->m_spellInfo->Id);
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
                // handle effects on caster if the spell has travel time but also affects the caster in some way
                if (!m_Spell->m_targets.HasDst())
                {
                    uint64 n_offset = m_Spell->handle_delayed(0);
                    ASSERT(n_offset == m_Spell->GetDelayMoment());
                }
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
    for (SpellEffectInfo const* effect : GetEffects())
    {
        // don't do anything for empty effect
        if (!effect || !effect->IsEffect())
            continue;

        HandleEffects(NULL, NULL, NULL, effect->EffectIndex, SPELL_EFFECT_HANDLE_LAUNCH);
    }

    float multiplier[MAX_SPELL_EFFECTS];
    for (SpellEffectInfo const* effect : GetEffects())
        if (effect && (m_applyMultiplierMask & (1 << effect->EffectIndex)))
            multiplier[effect->EffectIndex] = effect->CalcDamageMultiplier(m_originalCaster, this);

    PrepareTargetProcessing();

    for (auto ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
    {
        TargetInfo& target = *ihit;

        uint32 mask = target.effectMask;
        if (!mask)
            continue;

        DoAllEffectOnLaunchTarget(target, multiplier);
    }

    FinishTargetProcessing();
}

void Spell::DoAllEffectOnLaunchTarget(TargetInfo& targetInfo, float* multiplier)
{
    Unit* unit = NULL;
    // In case spell hit target, do all effect on that target
    if (targetInfo.missCondition == SPELL_MISS_NONE)
        unit = m_caster->GetGUID() == targetInfo.targetGUID ? m_caster : ObjectAccessor::GetUnit(*m_caster, targetInfo.targetGUID);
    // In case spell reflect from target, do all effect on caster (if hit)
    else if (targetInfo.missCondition == SPELL_MISS_REFLECT && targetInfo.reflectResult == SPELL_MISS_NONE)
        unit = m_caster;
    if (!unit)
        return;

    for (SpellEffectInfo const* effect : GetEffects())
    {
        if (effect && (targetInfo.effectMask & (1<<effect->EffectIndex)))
        {
            m_damage = 0;
            m_healing = 0;

            HandleEffects(unit, NULL, NULL, effect->EffectIndex, SPELL_EFFECT_HANDLE_LAUNCH_TARGET);

            if (m_damage > 0)
            {
                if (effect->IsTargetingArea() || effect->IsAreaAuraEffect() || effect->IsEffect(SPELL_EFFECT_PERSISTENT_AREA_AURA))
                {
                    m_damage = int32(float(m_damage) * unit->GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_AOE_DAMAGE_AVOIDANCE, m_spellInfo->SchoolMask));
                    if (m_caster->GetTypeId() != TYPEID_PLAYER)
                        m_damage = int32(float(m_damage) * unit->GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_CREATURE_AOE_DAMAGE_AVOIDANCE, m_spellInfo->SchoolMask));

                    if (m_caster->GetTypeId() == TYPEID_PLAYER)
                    {
                        uint32 targetAmount = m_UniqueTargetInfo.size();
                        if (targetAmount > 10)
                            m_damage = m_damage * 10/targetAmount;
                    }
                }
            }

            if (m_applyMultiplierMask & (1 << effect->EffectIndex))
            {
                m_damage = int32(m_damage * m_damageMultipliers[effect->EffectIndex]);
                m_damageMultipliers[effect->EffectIndex] *= multiplier[effect->EffectIndex];
            }
            targetInfo.damage += m_damage;
        }
    }

    if (Player* modOwner = m_caster->GetSpellModOwner())
        modOwner->SetSpellModTakingSpell(this, true);

    targetInfo.crit = m_caster->IsSpellCrit(unit, m_spellInfo, m_spellSchoolMask, m_attackType);

    if (Player* modOwner = m_caster->GetSpellModOwner())
        modOwner->SetSpellModTakingSpell(this, false);
}

SpellCastResult Spell::CanOpenLock(uint32 effIndex, uint32 lockId, SkillType& skillId, int32& reqSkillValue, int32& skillValue)
{
    if (!lockId)                                             // possible case for GO and maybe for items.
        return SPELL_CAST_OK;

    // Get LockInfo
    LockEntry const* lockInfo = sLockStore.LookupEntry(lockId);

    if (!lockInfo)
        return SPELL_FAILED_BAD_TARGETS;

    SpellEffectInfo const* effect = GetEffect(effIndex);
    if (!effect)
        return SPELL_FAILED_BAD_TARGETS; // no idea about correct error

    bool reqKey = false;                                    // some locks not have reqs

    for (int j = 0; j < MAX_LOCK_CASE; ++j)
    {
        switch (lockInfo->Type[j])
        {
            // check key item (many fit cases can be)
            case LOCK_KEY_ITEM:
                if (lockInfo->Index[j] && m_CastItem && int32(m_CastItem->GetEntry()) == lockInfo->Index[j])
                    return SPELL_CAST_OK;
                reqKey = true;
                break;
                // check key skill (only single first fit case can be)
            case LOCK_KEY_SKILL:
            {
                reqKey = true;

                // wrong locktype, skip
                if (effect->MiscValue != lockInfo->Index[j])
                    continue;

                skillId = SkillByLockType(LockType(lockInfo->Index[j]));

                if (skillId != SKILL_NONE || lockInfo->Index[j] == LOCKTYPE_PICKLOCK)
                {
                    reqSkillValue = lockInfo->Skill[j];

                    // castitem check: rogue using skeleton keys. the skill values should not be added in this case.
                    skillValue = 0;
                    if (!m_CastItem && m_caster->GetTypeId() == TYPEID_PLAYER)
                        skillValue = m_caster->ToPlayer()->GetSkillValue(skillId);
                    else if (lockInfo->Index[j] == LOCKTYPE_PICKLOCK)
                        skillValue = m_caster->getLevel() * 5;

                    // skill bonus provided by casting spell (mostly item spells)
                    // add the effect base points modifier from the spell cast (cheat lock / skeleton key etc.)
                    if (effect->TargetA.GetTarget() == TARGET_GAMEOBJECT_ITEM_TARGET || effect->TargetB.GetTarget() == TARGET_GAMEOBJECT_ITEM_TARGET)
                        skillValue += effect->CalcValue();

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
    if (mod < SPELLVALUE_BASE_POINT_END)
    {
        if (SpellEffectInfo const* effect = GetEffect(mod))
            m_spellValue->EffectBasePoints[mod] = effect->CalcBaseValue(value);
        return;
    }

    switch (mod)
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
        default:
            break;
    }
}

void Spell::PrepareTargetProcessing()
{
}

void Spell::FinishTargetProcessing()
{
    SendSpellExecuteLog();
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

void Spell::CallScriptAfterCastHandlers()
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_AFTER_CAST);
        auto hookItrEnd = (*scritr)->AfterCast.end(), hookItr = (*scritr)->AfterCast.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
            (*hookItr).Call(*scritr);

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
            SpellCastResult tempResult = (*hookItr).Call(*scritr);
            if (retVal == SPELL_CAST_OK)
                retVal = tempResult;
        }

        (*scritr)->_FinishScriptCall();
    }
    return retVal;
}

void Spell::PrepareScriptHitHandlers()
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
        (*scritr)->_InitHit();
}

bool Spell::CallScriptEffectHandlers(SpellEffIndex effIndex, SpellEffectHandleMode mode)
{
    // execute script effect handler hooks and check if effects was prevented
    bool preventDefault = false;
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
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
            hookItr->Call(*scritr, effIndex);

        (*scritr)->_FinishScriptCall();
    }
}

void Spell::CallScriptBeforeHitHandlers(SpellMissInfo missInfo)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_BEFORE_HIT);
        auto hookItrEnd = (*scritr)->BeforeHit.end(), hookItr = (*scritr)->BeforeHit.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
            (*hookItr).Call(*scritr, missInfo);

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
            (*hookItr).Call(*scritr);

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
            (*hookItr).Call(*scritr);

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
            if (hookItr->IsEffectAffected(m_spellInfo, effIndex) && targetType.GetTarget() == hookItr->GetTarget())
                hookItr->Call(*scritr, targets);

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
            if (hookItr->IsEffectAffected(m_spellInfo, effIndex) && targetType.GetTarget() == hookItr->GetTarget())
                hookItr->Call(*scritr, target);

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
            if (hookItr->IsEffectAffected(m_spellInfo, effIndex) && targetType.GetTarget() == hookItr->GetTarget())
                hookItr->Call(*scritr, target);

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
            if (((*targetSelectHookItr).IsEffectAffected(m_spellInfo, effIndex) && !(*targetSelectHookItr).IsEffectAffected(m_spellInfo, effIndexToCheck)) ||
                (!(*targetSelectHookItr).IsEffectAffected(m_spellInfo, effIndex) && (*targetSelectHookItr).IsEffectAffected(m_spellInfo, effIndexToCheck)))
                return false;

        auto areaTargetSelectHookEnd = (*itr)->OnObjectAreaTargetSelect.end(), areaTargetSelectHookItr = (*itr)->OnObjectAreaTargetSelect.begin();
        for (; areaTargetSelectHookItr != areaTargetSelectHookEnd; ++areaTargetSelectHookItr)
            if (((*areaTargetSelectHookItr).IsEffectAffected(m_spellInfo, effIndex) && !(*areaTargetSelectHookItr).IsEffectAffected(m_spellInfo, effIndexToCheck)) ||
                (!(*areaTargetSelectHookItr).IsEffectAffected(m_spellInfo, effIndex) && (*areaTargetSelectHookItr).IsEffectAffected(m_spellInfo, effIndexToCheck)))
                return false;
    }
    return true;
}

bool Spell::CanExecuteTriggersOnHit(uint32 effMask, SpellInfo const* triggeredByAura /*= nullptr*/) const
{
    bool only_on_caster = (triggeredByAura && (triggeredByAura->HasAttribute(SPELL_ATTR4_PROC_ONLY_ON_CASTER)));
    // If triggeredByAura has SPELL_ATTR4_PROC_ONLY_ON_CASTER then it can only proc on a cast spell with TARGET_UNIT_CASTER
    for (SpellEffectInfo const* effect : GetEffects())
    {
        if (effect && ((effMask & (1 << effect->EffectIndex)) && (!only_on_caster || (effect->TargetA.GetTarget() == TARGET_UNIT_CASTER))))
            return true;
    }
    return false;
}

void Spell::PrepareTriggersExecutedOnHit()
{
    // handle SPELL_AURA_ADD_TARGET_TRIGGER auras:
    // save auras which were present on spell caster on cast, to prevent triggered auras from affecting caster
    // and to correctly calculate proc chance when combopoints are present
    Unit::AuraEffectList const& targetTriggers = m_caster->GetAuraEffectsByType(SPELL_AURA_ADD_TARGET_TRIGGER);
    for (AuraEffect const* aurEff : targetTriggers)
    {
        if (!aurEff->IsAffectingSpell(m_spellInfo))
            continue;

        if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(aurEff->GetSpellEffectInfo()->TriggerSpell))
        {
            // calculate the chance using spell base amount, because aura amount is not updated on combo-points change
            // this possibly needs fixing
            int32 auraBaseAmount = aurEff->GetBaseAmount();
            // proc chance is stored in effect amount
            int32 chance = m_caster->CalculateSpellDamage(nullptr, aurEff->GetSpellInfo(), aurEff->GetEffIndex(), &auraBaseAmount);
            chance *= aurEff->GetBase()->GetStackAmount();

            // build trigger and add to the list
            m_hitTriggerSpells.emplace_back(spellInfo, aurEff->GetSpellInfo(), chance);
        }
    }
}

// Global cooldowns management
enum GCDLimits
{
    MIN_GCD = 750,
    MAX_GCD = 1500
};

bool Spell::HasGlobalCooldown() const
{
    // Only players or controlled units have global cooldown
    if (m_caster->GetTypeId() != TYPEID_PLAYER && !m_caster->GetCharmInfo())
        return false;

    return m_caster->GetSpellHistory()->HasGlobalCooldown(m_spellInfo);
}

void Spell::TriggerGlobalCooldown()
{
    int32 gcd = m_spellInfo->StartRecoveryTime;
    if (!gcd || !m_spellInfo->StartRecoveryCategory)
        return;

    // Only players or controlled units have global cooldown
    if (m_caster->GetTypeId() != TYPEID_PLAYER && !m_caster->GetCharmInfo())
        return;

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
        if (m_caster->ToPlayer()->GetCommandStatus(CHEAT_COOLDOWN))
            return;

    // Global cooldown can't leave range 1..1.5 secs
    // There are some spells (mostly not cast directly by player) that have < 1 sec and > 1.5 sec global cooldowns
    // but as tests show are not affected by any spell mods.
    if (m_spellInfo->StartRecoveryTime >= MIN_GCD && m_spellInfo->StartRecoveryTime <= MAX_GCD)
    {
        // gcd modifier auras are applied only to own spells and only players have such mods
        if (Player* modOwner = m_caster->GetSpellModOwner())
            modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_GLOBAL_COOLDOWN, gcd, this);

        bool isMeleeOrRangedSpell = m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MELEE ||
            m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_RANGED ||
            m_spellInfo->HasAttribute(SPELL_ATTR0_REQ_AMMO) ||
            m_spellInfo->HasAttribute(SPELL_ATTR0_ABILITY);

        // Apply haste rating
        if (gcd > MIN_GCD && ((m_spellInfo->StartRecoveryCategory == 133 && !isMeleeOrRangedSpell) || m_caster->HasAuraTypeWithAffectMask(SPELL_AURA_MOD_GLOBAL_COOLDOWN_BY_HASTE, m_spellInfo)))
        {
            gcd = int32(float(gcd) * m_caster->GetFloatValue(UNIT_MOD_CAST_HASTE));
            RoundToInterval<int32>(gcd, MIN_GCD, MAX_GCD);
        }

        if (gcd > MIN_GCD && m_caster->HasAuraTypeWithAffectMask(SPELL_AURA_MOD_GLOBAL_COOLDOWN_BY_HASTE_REGEN, m_spellInfo))
        {
            gcd = int32(float(gcd) * m_caster->GetFloatValue(UNIT_FIELD_MOD_HASTE_REGEN));
            RoundToInterval<int32>(gcd, MIN_GCD, MAX_GCD);
        }
    }

    m_caster->GetSpellHistory()->AddGlobalCooldown(m_spellInfo, gcd);
}

void Spell::CancelGlobalCooldown()
{
    if (!m_spellInfo->StartRecoveryTime)
        return;

    // Cancel global cooldown when interrupting current cast
    if (m_caster->GetCurrentSpell(CURRENT_GENERIC_SPELL) != this)
        return;

    // Only players or controlled units have global cooldown
    if (m_caster->GetTypeId() != TYPEID_PLAYER && !m_caster->GetCharmInfo())
        return;

    m_caster->GetSpellHistory()->CancelGlobalCooldown(m_spellInfo);
}

bool Spell::HasEffect(SpellEffectName effect) const
{
    for (SpellEffectInfo const* eff : GetEffects())
    {
        if (eff && eff->IsEffect(effect))
            return true;
    }
    return false;
}

namespace Trinity
{

WorldObjectSpellTargetCheck::WorldObjectSpellTargetCheck(Unit* caster, Unit* referer, SpellInfo const* spellInfo,
            SpellTargetCheckTypes selectionType, ConditionContainer* condList) : _caster(caster), _referer(referer), _spellInfo(spellInfo),
    _targetSelectionType(selectionType), _condList(condList)
{
    if (condList)
        _condSrcInfo = new ConditionSourceInfo(NULL, caster);
    else
        _condSrcInfo = NULL;
}

WorldObjectSpellTargetCheck::~WorldObjectSpellTargetCheck()
{
    delete _condSrcInfo;
}

bool WorldObjectSpellTargetCheck::operator()(WorldObject* target)
{
    if (_spellInfo->CheckTarget(_caster, target, true) != SPELL_CAST_OK)
        return false;
    Unit* unitTarget = target->ToUnit();
    if (Corpse* corpseTarget = target->ToCorpse())
    {
        // use ofter for party/assistance checks
        if (Player* owner = ObjectAccessor::FindPlayer(corpseTarget->GetOwnerGUID()))
            unitTarget = owner;
        else
            return false;
    }
    if (unitTarget)
    {
        switch (_targetSelectionType)
        {
            case TARGET_CHECK_ENEMY:
                if (unitTarget->IsTotem())
                    return false;
                if (!_caster->_IsValidAttackTarget(unitTarget, _spellInfo))
                    return false;
                break;
            case TARGET_CHECK_ALLY:
                if (unitTarget->IsTotem())
                    return false;
                if (!_caster->_IsValidAssistTarget(unitTarget, _spellInfo))
                    return false;
                break;
            case TARGET_CHECK_PARTY:
                if (unitTarget->IsTotem())
                    return false;
                if (!_caster->_IsValidAssistTarget(unitTarget, _spellInfo))
                    return false;
                if (!_referer->IsInPartyWith(unitTarget))
                    return false;
                break;
            case TARGET_CHECK_RAID_CLASS:
                if (_referer->getClass() != unitTarget->getClass())
                    return false;
                // nobreak;
            case TARGET_CHECK_RAID:
                if (unitTarget->IsTotem())
                    return false;
                if (!_caster->_IsValidAssistTarget(unitTarget, _spellInfo))
                    return false;
                if (!_referer->IsInRaidWith(unitTarget))
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

WorldObjectSpellNearbyTargetCheck::WorldObjectSpellNearbyTargetCheck(float range, Unit* caster, SpellInfo const* spellInfo,
    SpellTargetCheckTypes selectionType, ConditionContainer* condList)
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

WorldObjectSpellAreaTargetCheck::WorldObjectSpellAreaTargetCheck(float range, Position const* position, Unit* caster,
    Unit* referer, SpellInfo const* spellInfo, SpellTargetCheckTypes selectionType, ConditionContainer* condList)
    : WorldObjectSpellTargetCheck(caster, referer, spellInfo, selectionType, condList), _range(range), _position(position) { }

bool WorldObjectSpellAreaTargetCheck::operator()(WorldObject* target)
{
    if (!target->IsWithinDist3d(_position, _range) && !(target->ToGameObject() && target->ToGameObject()->IsInRange(_position->GetPositionX(), _position->GetPositionY(), _position->GetPositionZ(), _range)))
        return false;
    return WorldObjectSpellTargetCheck::operator ()(target);
}

WorldObjectSpellConeTargetCheck::WorldObjectSpellConeTargetCheck(float coneAngle, float range, Unit* caster,
    SpellInfo const* spellInfo, SpellTargetCheckTypes selectionType, ConditionContainer* condList)
    : WorldObjectSpellAreaTargetCheck(range, caster, caster, caster, spellInfo, selectionType, condList), _coneAngle(coneAngle) { }

bool WorldObjectSpellConeTargetCheck::operator()(WorldObject* target)
{
    if (_spellInfo->HasAttribute(SPELL_ATTR0_CU_CONE_BACK))
    {
        if (!_caster->isInBack(target, _coneAngle))
            return false;
    }
    else if (_spellInfo->HasAttribute(SPELL_ATTR0_CU_CONE_LINE))
    {
        if (!_caster->HasInLine(target, _caster->GetObjectSize() + target->GetObjectSize()))
            return false;
    }
    else
    {
        if (!_caster->IsWithinBoundaryRadius(target->ToUnit()))
            // ConeAngle > 0 -> select targets in front
            // ConeAngle < 0 -> select targets in back
            if (_caster->HasInArc(_coneAngle, target) != G3D::fuzzyGe(_coneAngle, 0.f))
                return false;
    }
    return WorldObjectSpellAreaTargetCheck::operator ()(target);
}

WorldObjectSpellTrajTargetCheck::WorldObjectSpellTrajTargetCheck(float range, Position const* position, Unit* caster, SpellInfo const* spellInfo)
    : WorldObjectSpellAreaTargetCheck(range, position, caster, caster, spellInfo, TARGET_CHECK_DEFAULT, NULL) { }

bool WorldObjectSpellTrajTargetCheck::operator()(WorldObject* target)
{
    // return all targets on missile trajectory (0 - size of a missile)
    if (!_caster->HasInLine(target, target->GetObjectSize()))
        return false;
    return WorldObjectSpellAreaTargetCheck::operator ()(target);
}

} //namespace Trinity

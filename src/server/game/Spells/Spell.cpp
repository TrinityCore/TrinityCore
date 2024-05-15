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
#include "ConditionMgr.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "DisableMgr.h"
#include "DynamicObject.h"
#include "G3DPosition.hpp"
#include "GameObjectAI.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "GameTime.h"
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
#include "UniqueTrackablePtr.h"
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

SpellCastTargets::SpellCastTargets() : m_elevation(0), m_speed(0), m_strTarget()
{
    m_objectTarget = nullptr;
    m_itemTarget = nullptr;

    m_itemTargetEntry  = 0;

    m_targetMask = 0;
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

    if (m_targetMask & (TARGET_FLAG_ITEM | TARGET_FLAG_TRADE_ITEM))
    {
        data.Item.emplace();
        if (m_itemTarget)
            data.Item = m_itemTarget->GetGUID();
    }

    if (m_targetMask & TARGET_FLAG_SOURCE_LOCATION)
    {
        data.SrcLocation.emplace();
        data.SrcLocation->Transport = m_src._transportGUID;
        if (!m_src._transportGUID.IsEmpty())
            data.SrcLocation->Location = m_src._transportOffset;
        else
            data.SrcLocation->Location = m_src._position;
    }

    if (m_targetMask & TARGET_FLAG_DEST_LOCATION)
    {
        data.DstLocation.emplace();
        data.DstLocation->Transport = m_dst._transportGUID;
        if (m_dst._transportGUID)
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
    for (SpellEffectInfo const& spellEffectInfo : proto->GetEffects())
        EffectBasePoints[spellEffectInfo.EffectIndex] = spellEffectInfo.BasePoints;
    MaxAffectedTargets = proto->MaxAffectedTargets;
    RadiusMod = 1.0f;
    AuraStackAmount = 1;
    CriticalChance = 0.0f;
}

class TC_GAME_API SpellEvent : public BasicEvent
{
public:
    explicit SpellEvent(Spell* spell);
    ~SpellEvent();

    bool Execute(uint64 e_time, uint32 p_time) override;
    void Abort(uint64 e_time) override;
    bool IsDeletable() const override;
    Spell const* GetSpell() const { return m_Spell.get(); }
    Trinity::unique_weak_ptr<Spell> GetSpellWeakPtr() const { return m_Spell; }

    std::string GetDebugInfo() const { return m_Spell->GetDebugInfo(); }

protected:
    Trinity::unique_trackable_ptr<Spell> m_Spell;
};

Spell::Spell(WorldObject* caster, SpellInfo const* info, TriggerCastFlags triggerFlags, ObjectGuid originalCasterGUID) :
m_spellInfo(sSpellMgr->GetSpellForDifficultyFromSpell(info, caster)),
m_caster((info->HasAttribute(SPELL_ATTR6_CAST_BY_CHARMER) && caster->GetCharmerOrOwner()) ? caster->GetCharmerOrOwner() : caster)
, m_spellValue(new SpellValue(m_spellInfo)), _spellEvent(nullptr)
{
    m_customError = SPELL_CUSTOM_ERROR_NONE;
    m_fromClient = false;
    m_selfContainer = nullptr;
    m_referencedFromCurrentSpell = false;
    m_executedCurrently = false;
    m_needComboPoints = m_spellInfo->NeedsComboPoints();
    m_comboTarget = nullptr;
    m_comboPointGain = 0;
    m_delayStart = 0;
    m_delayAtDamageCount = 0;

    m_applyMultiplierMask = 0;
    m_auraScaleMask = 0;
    memset(m_damageMultipliers, 0, sizeof(m_damageMultipliers));

    // Get data for type of attack
    m_attackType = info->GetAttackType();

    m_spellSchoolMask = info->GetSchoolMask();           // Can be override for some spell (wand shoot for example)

    if (Player const* playerCaster = m_caster->ToPlayer())
    {
        // wand case
        if (m_attackType == RANGED_ATTACK)
            if ((playerCaster->GetClassMask() & CLASSMASK_WAND_USERS) != 0)
                if (Item* pItem = playerCaster->GetWeaponForAttack(RANGED_ATTACK))
                    m_spellSchoolMask = SpellSchoolMask(1 << pItem->GetTemplate()->Damage[0].DamageType);
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
    if (info->HasAttribute(SPELL_ATTR4_CAN_CAST_WHILE_CASTING))
        _triggeredCastFlags = TriggerCastFlags(uint32(_triggeredCastFlags) | TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_CAST_DIRECTLY);

    m_CastItem = nullptr;
    m_castItemGUID.Clear();
    m_castItemEntry = 0;

    unitTarget = nullptr;
    itemTarget = nullptr;
    gameObjTarget = nullptr;
    m_corpseTarget = nullptr;
    destTarget = nullptr;
    damage = 0;
    targetMissInfo = SPELL_MISS_NONE;
    effectHandleMode = SPELL_EFFECT_HANDLE_LAUNCH;
    effectInfo = nullptr;
    m_damage = 0;
    m_healing = 0;
    m_procAttacker = 0;
    m_procVictim = 0;
    m_hitMask = 0;
    focusObject = nullptr;
    m_cast_count = 0;
    m_glyphIndex = 0;
    m_triggeredByAuraSpell  = nullptr;
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
    m_canReflect = caster->IsUnit()
        && m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MAGIC && !m_spellInfo->HasAttribute(SPELL_ATTR0_ABILITY)
        && !m_spellInfo->HasAttribute(SPELL_ATTR1_CANT_BE_REFLECTED) && !m_spellInfo->HasAttribute(SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY)
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
        TC_LOG_ERROR("spells", "SPELL: deleting spell for spell ID {}. However, spell still referenced.", m_spellInfo->Id);
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
                unit = m_caster->ToCreature()->GetVictim();

            // didn't find anything - let's use self as target
            if (!unit && (neededTargets & (TARGET_FLAG_UNIT_ENEMY | TARGET_FLAG_UNIT_DEAD | TARGET_FLAG_UNIT_MINIPET | TARGET_FLAG_UNIT_PASSENGER)) == 0)
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

    uint32 processedEffectsMaskForSpell = 0;
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
    {
        // not call for empty effect.
        // Also some spells use not used effect targets for store targets for dummy effect in triggered spells
        if (!spellEffectInfo.IsEffect())
            continue;

        // set expected type of implicit targets to be sent to client
        uint32 implicitTargetMask = GetTargetFlagMask(spellEffectInfo.TargetA.GetObjectType()) | GetTargetFlagMask(spellEffectInfo.TargetB.GetObjectType());
        if (implicitTargetMask & TARGET_FLAG_UNIT)
            m_targets.SetTargetFlag(TARGET_FLAG_UNIT);
        if (implicitTargetMask & (TARGET_FLAG_GAMEOBJECT | TARGET_FLAG_GAMEOBJECT_ITEM))
            m_targets.SetTargetFlag(TARGET_FLAG_GAMEOBJECT);

        uint32 implicitTargetEffectMaskToSelect = [&]
        {
            uint32 effectMask = 1u << spellEffectInfo.EffectIndex;
            // set the same target list for all effects
            // some spells appear to need this, however this requires more research
            std::array<SpellEffectInfo, MAX_SPELL_EFFECTS> const& effects = GetSpellInfo()->GetEffects();
            // choose which targets we can select at once
            for (uint32 j = spellEffectInfo.EffectIndex + 1; j < effects.size(); ++j)
            {
                if (effects[j].IsEffect() &&
                    spellEffectInfo.TargetA.GetTarget() == effects[j].TargetA.GetTarget() &&
                    spellEffectInfo.TargetB.GetTarget() == effects[j].TargetB.GetTarget() &&
                    spellEffectInfo.ImplicitTargetConditions == effects[j].ImplicitTargetConditions &&
                    CheckScriptEffectImplicitTargets(spellEffectInfo.EffectIndex, j))
                {
                    auto shouldCheckRadius = [](SpellImplicitTargetInfo const& targetInfo)
                    {
                        switch (targetInfo.GetSelectionCategory())
                        {
                            case TARGET_SELECT_CATEGORY_NEARBY:
                            case TARGET_SELECT_CATEGORY_CONE:
                            case TARGET_SELECT_CATEGORY_AREA:
                                return true;
                            default:
                                break;
                        }
                        return false;
                    };

                    if (shouldCheckRadius(spellEffectInfo.TargetA) || shouldCheckRadius(spellEffectInfo.TargetB))
                        if (spellEffectInfo.CalcRadius(m_caster) != effects[j].CalcRadius(m_caster))
                            continue;

                    effectMask |= 1 << j;
                }
            }

            return effectMask;
        }();

        implicitTargetEffectMaskToSelect &= ~processedEffectsMaskForSpell;
        if (implicitTargetEffectMaskToSelect)
        {
            SelectEffectImplicitTargets(spellEffectInfo, spellEffectInfo.TargetA, implicitTargetEffectMaskToSelect);
            SelectEffectImplicitTargets(spellEffectInfo, spellEffectInfo.TargetB, implicitTargetEffectMaskToSelect);
            processedEffectsMaskForSpell |= implicitTargetEffectMaskToSelect;
        }

        // Select targets of effect based on effect type
        // those are used when no valid target could be added for spell effect based on spell target type
        // some spell effects use explicit target as a default target added to target map (like SPELL_EFFECT_LEARN_SPELL)
        // some spell effects add target to target map only when target type specified (like SPELL_EFFECT_WEAPON)
        // some spell effects don't add anything to target map (confirmed with sniffs) (like SPELL_EFFECT_DESTROY_ALL_TOTEMS)
        SelectEffectTypeImplicitTargets(spellEffectInfo);

        if (m_targets.HasDst())
            AddDestTarget(*m_targets.GetDst(), spellEffectInfo.EffectIndex);

        if (implicitTargetEffectMaskToSelect
            && (spellEffectInfo.TargetA.GetObjectType() == TARGET_OBJECT_TYPE_UNIT
                || spellEffectInfo.TargetA.GetObjectType() == TARGET_OBJECT_TYPE_UNIT_AND_DEST
                || spellEffectInfo.TargetB.GetObjectType() == TARGET_OBJECT_TYPE_UNIT
                || spellEffectInfo.TargetB.GetObjectType() == TARGET_OBJECT_TYPE_UNIT_AND_DEST))
        {
            if (m_spellInfo->HasAttribute(SPELL_ATTR1_REQUIRE_ALL_TARGETS))
            {
                bool noTargetFound = std::ranges::none_of(m_UniqueTargetInfo, [implicitTargetEffectMaskToSelect](TargetInfo const& target)
                {
                    return target.EffectMask & implicitTargetEffectMaskToSelect;
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
                bool anyNonImmuneTargetFound = std::ranges::any_of(m_UniqueTargetInfo, [implicitTargetEffectMaskToSelect](TargetInfo const& target)
                {
                    return target.EffectMask & implicitTargetEffectMaskToSelect && target.MissCondition != SPELL_MISS_IMMUNE && target.MissCondition != SPELL_MISS_IMMUNE2;
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

            uint8 mask = (1 << spellEffectInfo.EffectIndex);
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
                return (uint64)floor(m_targets.GetDist2d() / speed * 1000.0f);
        }
        else if (m_spellInfo->Speed > 0.0f)
        {
            // We should not subtract caster size from dist calculation (fixes execution time desync with animation on client, eg. Malleable Goo cast by PP)
            float dist = m_caster->GetExactDist(*m_targets.GetDstPos());
            return (uint64)std::floor(dist / m_spellInfo->Speed * 1000.0f);
        }
    }

    return 0;
}

void Spell::RecalculateDelayMomentForDst()
{
    m_delayMoment = CalculateDelayMomentForDst();
    m_caster->m_Events.ModifyEventTime(_spellEvent, Milliseconds(GetDelayStart() + m_delayMoment));
}

void Spell::SelectEffectImplicitTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, uint32 effectMask)
{
    if (!targetType.GetTarget())
        return;

    switch (targetType.GetSelectionCategory())
    {
        case TARGET_SELECT_CATEGORY_CHANNEL:
            SelectImplicitChannelTargets(spellEffectInfo, targetType, effectMask);
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
                            SelectImplicitCasterObjectTargets(spellEffectInfo, targetType, effectMask);
                            break;
                        case TARGET_REFERENCE_TYPE_TARGET:
                            SelectImplicitTargetObjectTargets(spellEffectInfo, targetType, effectMask);
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

void Spell::SelectImplicitChannelTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, uint32 effMask)
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
            WorldObject* target = ObjectAccessor::GetUnit(*m_caster, m_originalCaster->GetChannelObjectGuid());
            CallScriptObjectTargetSelectHandlers(target, spellEffectInfo.EffectIndex, targetType);
            // unit target may be no longer avalible - teleported out of map for example
            if (target && target->ToUnit())
                AddUnitTarget(target->ToUnit(), effMask);
            else
                TC_LOG_DEBUG("spells", "SPELL: cannot find channel spell target for spell ID {}, effect {}", m_spellInfo->Id, uint32(spellEffectInfo.EffectIndex));
            break;
        }
        case TARGET_DEST_CHANNEL_TARGET:
            if (channeledSpell->m_targets.HasDst())
                m_targets.SetDst(channeledSpell->m_targets);
            else if (WorldObject* target = ObjectAccessor::GetWorldObject(*m_caster, m_originalCaster->GetChannelObjectGuid()))
            {
                CallScriptObjectTargetSelectHandlers(target, spellEffectInfo.EffectIndex, targetType);
                if (target)
                {
                    SpellDestination dest(*target);
                    CallScriptDestinationTargetSelectHandlers(dest, spellEffectInfo.EffectIndex, targetType);
                    m_targets.SetDst(dest);
                }
            }
            else
                TC_LOG_DEBUG("spells", "SPELL: cannot find channel spell destination for spell ID {}, effect {}", m_spellInfo->Id, uint32(spellEffectInfo.EffectIndex));
            break;
        case TARGET_DEST_CHANNEL_CASTER:
        {
            SpellDestination dest(*channeledSpell->GetCaster());
            CallScriptDestinationTargetSelectHandlers(dest, spellEffectInfo.EffectIndex, targetType);
            m_targets.SetDst(dest);
            break;
        }
        default:
            ABORT_MSG("Spell::SelectImplicitChannelTargets: received not implemented target type");
            break;
    }
}

void Spell::SelectImplicitNearbyTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, uint32 effMask)
{
    if (targetType.GetReferenceType() != TARGET_REFERENCE_TYPE_CASTER)
    {
        ABORT_MSG("Spell::SelectImplicitNearbyTargets: received not implemented target reference type");
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
            ABORT_MSG("Spell::SelectImplicitNearbyTargets: received not implemented selection check type");
            break;
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
    if (targetType.GetReferenceType() != TARGET_REFERENCE_TYPE_CASTER)
    {
        ABORT_MSG("Spell::SelectImplicitConeTargets: received not implemented target reference type");
        return;
    }
    std::list<WorldObject*> targets;
    SpellTargetObjectTypes objectType = targetType.GetObjectType();
    SpellTargetCheckTypes selectionType = targetType.GetCheckType();
    ConditionContainer* condList = spellEffectInfo.ImplicitTargetConditions;
    float coneAngle = float(M_PI) / 2.f;

    float radius = spellEffectInfo.CalcRadius(m_caster);
    // Workaround for some spells that don't have RadiusEntry set in dbc (but SpellRange instead)
    if (G3D::fuzzyEq(radius, 0.f))
        radius = m_spellInfo->GetMaxRange(m_spellInfo->IsPositiveEffect(spellEffectInfo.EffectIndex), m_caster, this);

    radius *= m_spellValue->RadiusMod;

    if (uint32 containerTypeMask = GetSearcherTypeMask(objectType, condList))
    {
        float extraSearchRadius = radius > 0.0f ? EXTRA_CELL_SEARCH_RADIUS : 0.0f;
        Trinity::WorldObjectSpellConeTargetCheck check(coneAngle, radius, m_caster, m_spellInfo, selectionType, condList);
        Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellConeTargetCheck> searcher(m_caster, targets, check, containerTypeMask);
        SearchTargets<Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellConeTargetCheck> >(searcher, containerTypeMask, m_caster, m_caster, radius + extraSearchRadius);

        CallScriptObjectAreaTargetSelectHandlers(targets, spellEffectInfo.EffectIndex, targetType);

        if (!targets.empty())
        {
            // Other special target selection goes here
            if (uint32 maxTargets = m_spellValue->MaxAffectedTargets)
            {
                if (Unit* unitCaster = m_caster->ToUnit())
                    maxTargets += unitCaster->GetTotalAuraModifierByAffectMask(SPELL_AURA_MOD_MAX_AFFECTED_TARGETS, m_spellInfo);
                Trinity::Containers::RandomResize(targets, maxTargets);
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
    std::list<WorldObject*> targets;
    float radius = spellEffectInfo.CalcRadius(m_caster);
    // Workaround for some spells that don't have RadiusEntry set in dbc (but SpellRange instead)
    if (G3D::fuzzyEq(radius, 0.f))
        radius = m_spellInfo->GetMaxRange(m_spellInfo->IsPositiveEffect(spellEffectInfo.EffectIndex), m_caster, this);

    radius *= m_spellValue->RadiusMod;

    SearchAreaTargets(targets, radius, center, referer, targetType.GetObjectType(), targetType.GetCheckType(), spellEffectInfo.ImplicitTargetConditions);

    CallScriptObjectAreaTargetSelectHandlers(targets, spellEffectInfo.EffectIndex, targetType);

    if (!targets.empty())
    {
        // Other special target selection goes here
        if (uint32 maxTargets = m_spellValue->MaxAffectedTargets)
        {
            if (Unit* unitCaster = m_caster->ToUnit())
                maxTargets += unitCaster->GetTotalAuraModifierByAffectMask(SPELL_AURA_MOD_MAX_AFFECTED_TARGETS, m_spellInfo);
            Trinity::Containers::RandomResize(targets, maxTargets);
        }

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

void Spell::SelectImplicitCasterDestTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType)
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
            if (SpellTargetPosition const* st = sSpellMgr->GetSpellTargetPosition(m_spellInfo->Id, spellEffectInfo.EffectIndex))
            {
                /// @todo fix this check
                if (m_spellInfo->HasEffect(SPELL_EFFECT_TELEPORT_UNITS) || m_spellInfo->HasEffect(SPELL_EFFECT_BIND))
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

            float ground = m_caster->GetMapHeight(x, y, z);
            float liquidLevel = VMAP_INVALID_HEIGHT_VALUE;
            LiquidData liquidData;
            if (m_caster->GetMap()->GetLiquidStatus(m_caster->GetPhaseMask(), x, y, z, MAP_ALL_LIQUIDS, &liquidData, m_caster->GetCollisionHeight()))
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

            float dist = spellEffectInfo.CalcRadius(unitCaster);
            float angle = targetType.CalcDirectionAngle();

            Position pos = dest._position;

            unitCaster->MovePositionToFirstCollision(pos, dist, angle);
            dest.Relocate(pos);
            break;
        }
        default:
        {
            float dist = spellEffectInfo.CalcRadius(m_caster);
            float angle = targetType.CalcDirectionAngle();
            float objSize = m_caster->GetCombatReach();

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
                    if (!spellEffectInfo.HasRadius())
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

    CallScriptDestinationTargetSelectHandlers(dest, spellEffectInfo.EffectIndex, targetType);
    m_targets.SetDst(dest);
}

void Spell::SelectImplicitTargetDestTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType)
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
            float dist = spellEffectInfo.CalcRadius(nullptr);
            if (targetType.GetTarget() == TARGET_DEST_TARGET_RANDOM)
                dist *= float(rand_norm());

            Position pos = dest._position;
            target->MovePositionToFirstCollision(pos, dist, angle);

            dest.Relocate(pos);
            break;
        }
    }

    CallScriptDestinationTargetSelectHandlers(dest, spellEffectInfo.EffectIndex, targetType);
    m_targets.SetDst(dest);
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
            return;
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
        }
    }

    CallScriptDestinationTargetSelectHandlers(dest, spellEffectInfo.EffectIndex, targetType);
    m_targets.ModDst(dest);
}

void Spell::SelectImplicitCasterObjectTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, uint32 effMask)
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
        default:
            break;
    }

    CallScriptObjectTargetSelectHandlers(target, spellEffectInfo.EffectIndex, targetType);

    if (target)
    {
        if (Unit* unit = target->ToUnit())
            AddUnitTarget(unit, effMask, checkIfValid);
        else if (GameObject* go = target->ToGameObject())
            AddGOTarget(go, effMask);
    }
}

void Spell::SelectImplicitTargetObjectTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, uint32 effMask)
{
    ASSERT((m_targets.GetObjectTarget() || m_targets.GetItemTarget()) && "Spell::SelectImplicitTargetObjectTargets - no explicit object or item target available!");

    WorldObject* target = m_targets.GetObjectTarget();

    CallScriptObjectTargetSelectHandlers(target, spellEffectInfo.EffectIndex, targetType);

    if (target)
    {
        if (Unit* unit = target->ToUnit())
            AddUnitTarget(unit, effMask, true, false);
        else if (GameObject* gobj = target->ToGameObject())
            AddGOTarget(gobj, effMask);
        else if (Corpse* corpse = target->ToCorpse())
            AddCorpseTarget(corpse, effMask);

        SelectImplicitChainTargets(spellEffectInfo, targetType, target, effMask);
    }
    // Script hook can remove object target and we would wrongly land here
    else if (Item* item = m_targets.GetItemTarget())
        AddItemTarget(item, effMask);
}

void Spell::SelectImplicitChainTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, WorldObject* target, uint32 effMask)
{
    uint32 maxTargets = spellEffectInfo.ChainTarget;
    if (Player* modOwner = m_caster->GetSpellModOwner())
        modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_JUMP_TARGETS, maxTargets, this);

    if (maxTargets > 1)
    {
        // mark damage multipliers as used
        for (size_t k = spellEffectInfo.EffectIndex; k < m_spellInfo->GetEffects().size(); ++k)
            if (effMask & (1 << k))
                m_damageMultipliers[k] = 1.0f;
        m_applyMultiplierMask |= effMask;

        std::list<WorldObject*> targets;
        SearchChainTargets(targets, maxTargets - 1, target, targetType.GetObjectType(), targetType.GetCheckType()
            , spellEffectInfo.ImplicitTargetConditions, targetType.GetTarget() == TARGET_UNIT_TARGET_CHAINHEAL_ALLY);

        // Chain primary target is added earlier
        CallScriptObjectAreaTargetSelectHandlers(targets, spellEffectInfo.EffectIndex, targetType);

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

void Spell::SelectImplicitTrajTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType)
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
    Trinity::WorldObjectSpellTrajTargetCheck check(dist2d, &srcPos, m_caster, m_spellInfo, targetType.GetCheckType(), spellEffectInfo.ImplicitTargetConditions);
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
    if (SpellInfo const* triggerSpellInfo = sSpellMgr->GetSpellInfo(spellEffectInfo.TriggerSpell))
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
                if (!(creatureTarget->GetCreatureTemplate()->type_flags & CREATURE_TYPE_FLAG_COLLIDE_WITH_MISSILES))
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
        CallScriptDestinationTargetSelectHandlers(dest, spellEffectInfo.EffectIndex, targetType);
        m_targets.ModDst(dest);
    }
}

void Spell::SelectEffectTypeImplicitTargets(SpellEffectInfo const& spellEffectInfo)
{
    // special case for SPELL_EFFECT_SUMMON_RAF_FRIEND and SPELL_EFFECT_SUMMON_PLAYER, queue them on map for later execution
    switch (spellEffectInfo.Effect)
    {
        case SPELL_EFFECT_SUMMON_RAF_FRIEND:
        case SPELL_EFFECT_SUMMON_PLAYER:
            if (m_caster->GetTypeId() == TYPEID_PLAYER && m_caster->ToPlayer()->GetTarget())
            {
                WorldObject* target = ObjectAccessor::FindPlayer(m_caster->ToPlayer()->GetTarget());
                CallScriptObjectTargetSelectHandlers(target, spellEffectInfo.EffectIndex, SpellImplicitTargetInfo());

                // scripts may modify the target - recheck
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                {
                    // target is not stored in target map for those spells
                    // since we're completely skipping AddUnitTarget logic, we need to check immunity manually
                    // eg. aura 21546 makes target immune to summons
                    Player* player = target->ToPlayer();
                    if (player->IsImmunedToSpellEffect(m_spellInfo, spellEffectInfo, nullptr))
                        return;

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

    CallScriptObjectTargetSelectHandlers(target, spellEffectInfo.EffectIndex, SpellImplicitTargetInfo());

    if (target)
    {
        if (target->ToUnit())
            AddUnitTarget(target->ToUnit(), 1 << spellEffectInfo.EffectIndex, false);
        else if (target->ToGameObject())
            AddGOTarget(target->ToGameObject(), 1 << spellEffectInfo.EffectIndex);
        else if (target->ToCorpse())
            AddCorpseTarget(target->ToCorpse(), 1 << spellEffectInfo.EffectIndex);
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

    if (m_spellInfo->HasAttribute(SPELL_ATTR3_ONLY_TARGET_PLAYERS))
        retMask &= GRID_MAP_TYPE_MASK_CORPSE | GRID_MAP_TYPE_MASK_PLAYER;
    if (m_spellInfo->HasAttribute(SPELL_ATTR3_ONLY_TARGET_GHOSTS))
        retMask &= GRID_MAP_TYPE_MASK_PLAYER;

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

    float extraSearchRadius = range > 0.0f ? EXTRA_CELL_SEARCH_RADIUS : 0.0f;
    Trinity::WorldObjectSpellAreaTargetCheck check(range, position, m_caster, referer, m_spellInfo, selectionType, condList);
    Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellAreaTargetCheck> searcher(m_caster, targets, check, containerTypeMask);
    SearchTargets<Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellAreaTargetCheck> > (searcher, containerTypeMask, m_caster, position, range + extraSearchRadius);
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
                    if (deficit > maxHPDeficit && target->IsWithinDist(unit, jumpRadius) && target->IsWithinLOSInMap(unit, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
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
                    if ((!isBouncingFar || target->IsWithinDist(*itr, jumpRadius)) && target->IsWithinLOSInMap(*itr, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
                        foundItr = itr;
                }
                else if (target->GetDistanceOrder(*itr, *foundItr) && target->IsWithinLOSInMap(*itr, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
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
            // For other spells trigger procflags are set in Spell::TargetInfo::DoDamageAndTriggers
            // Because spell positivity is dependant on target
    }

    // Hunter trap spells - activation proc for Lock and Load, Entrapment and Misdirection
    if (m_spellInfo->SpellFamilyName == SPELLFAMILY_HUNTER &&
        (m_spellInfo->SpellFamilyFlags[0] & 0x18 ||         // Freezing and Frost Trap, Freezing Arrow
            m_spellInfo->Id == 57879 ||                     // Snake Trap - done this way to avoid double proc
            m_spellInfo->SpellFamilyFlags[2] & 0x00024000)) // Explosive and Immolation Trap
    {
        m_procAttacker |= PROC_FLAG_DONE_TRAP_ACTIVATION;

        // also fill up other flags (TargetInfo::DoDamageAndTriggers only fills up flag if both are not set)
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

            Unit::ProcSkillsAndAuras(caster, _victim, typeMaskActor, typeMaskActionTarget, spellTypeMask, spellPhaseMask, hitMask, nullptr, nullptr, nullptr);
            return true;
        }

    private:
        Unit* _victim;
        ObjectGuid _casterGuid;
};

void Spell::AddUnitTarget(Unit* target, uint32 effectMask, bool checkIfValid /*= true*/, bool implicit /*= true*/, Position const* losPosition /*= nullptr*/)
{
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
        if (!spellEffectInfo.IsEffect() || !CheckEffectTarget(target, spellEffectInfo, losPosition))
            effectMask &= ~(1 << spellEffectInfo.EffectIndex);

    // no effects left
    if (!effectMask)
        return;

    if (checkIfValid)
        if (m_spellInfo->CheckTarget(m_caster, target, implicit) != SPELL_CAST_OK) // skip stealth checks for AOE
            return;

    // Check for effect immune skip if immuned
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
        if (target->IsImmunedToSpellEffect(m_spellInfo, spellEffectInfo, m_caster))
            effectMask &= ~(1 << spellEffectInfo.EffectIndex);

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
            if (uint32(target->GetLevel() + 10) >= auraSpell->SpellLevel)
                ihit->ScaleAura = true;
        }
        return;
    }

    // This is new target calculate data for him

    // Get spell hit result on target
    TargetInfo targetInfo;
    targetInfo.TargetGUID = targetGUID;                         // Store target GUID
    targetInfo.EffectMask = effectMask;                         // Store all effects not immune
    targetInfo.IsAlive    = target->IsAlive();
    targetInfo.Damage     = 0;
    targetInfo.Healing    = 0;
    targetInfo.IsCrit     = false;
    targetInfo.ScaleAura  = false;
    if (m_auraScaleMask && targetInfo.EffectMask == m_auraScaleMask && m_caster != target)
    {
        SpellInfo const* auraSpell = m_spellInfo->GetFirstRankSpell();
        if (uint32(target->GetLevel() + 10) >= auraSpell->SpellLevel)
            targetInfo.ScaleAura = true;
    }

    // Calculate hit result
    WorldObject* caster = m_originalCaster ? m_originalCaster : m_caster;
    targetInfo.MissCondition = caster->SpellHitResult(target, m_spellInfo, m_canReflect && !(IsPositive() && m_caster->IsFriendlyTo(target)));

    // Spell have speed - need calculate incoming time
    // Incoming time is zero for self casts. At least I think so.
    if (m_spellInfo->Speed > 0.0f && m_caster != target)
    {
        // calculate spell incoming interval
        /// @todo this is a hack
        float dist = m_caster->GetDistance(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());

        if (dist < 5.0f)
            dist = 5.0f;
        targetInfo.TimeDelay = uint64(std::floor(dist / m_spellInfo->Speed * 1000.0f));

        // Calculate minimum incoming time
        if (!m_delayMoment || m_delayMoment > targetInfo.TimeDelay)
            m_delayMoment = targetInfo.TimeDelay;
    }
    else
        targetInfo.TimeDelay = 0ULL;

    // If target reflect spell back to caster
    if (targetInfo.MissCondition == SPELL_MISS_REFLECT)
    {
        // Shouldn't be able to reflect gameobject spells
        Unit* unitCaster = ASSERT_NOTNULL(m_caster->ToUnit());

        // Calculate reflected spell result on caster
        if (m_spellInfo->CheckTarget(target, unitCaster, implicit) == SPELL_CAST_OK)
            targetInfo.ReflectResult = unitCaster->SpellHitResult(unitCaster, m_spellInfo, false); // can't reflect twice
        else
            targetInfo.ReflectResult = SPELL_MISS_IMMUNE;

        // Proc spell reflect aura when missile hits the original target
        target->m_Events.AddEvent(new ProcReflectDelayed(target, m_originalCasterGUID), target->m_Events.CalculateTime(Milliseconds(targetInfo.TimeDelay)));

        // Increase time interval for reflected spells by 1.5
        targetInfo.TimeDelay += targetInfo.TimeDelay >> 1;
    }
    else
        targetInfo.ReflectResult = SPELL_MISS_NONE;

    // Add target to list
    m_UniqueTargetInfo.emplace_back(std::move(targetInfo));
}

void Spell::AddGOTarget(GameObject* go, uint32 effectMask)
{
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
    {
        if (!spellEffectInfo.IsEffect())
            effectMask &= ~(1 << spellEffectInfo.EffectIndex);
        else
        {
            switch (spellEffectInfo.Effect)
            {
                case SPELL_EFFECT_GAMEOBJECT_DAMAGE:
                case SPELL_EFFECT_GAMEOBJECT_REPAIR:
                case SPELL_EFFECT_GAMEOBJECT_SET_DESTRUCTION_STATE:
                    if (go->GetGoType() != GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING)
                        effectMask &= ~(1 << spellEffectInfo.EffectIndex);
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
        target.TimeDelay = uint64(std::floor(dist / m_spellInfo->Speed * 1000.0f));
        if (!m_delayMoment || m_delayMoment > target.TimeDelay)
            m_delayMoment = target.TimeDelay;
    }
    else
        target.TimeDelay = 0ULL;

    // Add target to list
    m_UniqueGOTargetInfo.emplace_back(std::move(target));
}

void Spell::AddItemTarget(Item* item, uint32 effectMask)
{
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
        if (!spellEffectInfo.IsEffect())
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

    // This is new target add data

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

    if (!effectMask)
        return;

    ObjectGuid targetGUID = corpse->GetGUID();

    // Lookup target in already in list
    for (CorpseTargetInfo ihit : m_UniqueCorpseTargetInfo)
    {
        if (targetGUID == ihit.TargetGUID)                 // Found in list
        {
            ihit.EffectMask |= effectMask;                 // Add only effect mask
            return;
        }
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

        target.TimeDelay = uint64(floor(dist / m_spellInfo->Speed * 1000.0f));

        if (!m_delayMoment || m_delayMoment > target.TimeDelay)
            m_delayMoment = target.TimeDelay;
    }
    else
        target.TimeDelay = 0LL;

    // Add target to list
    m_UniqueCorpseTargetInfo.push_back(target);
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

    if (spell->m_originalCaster && MissCondition != SPELL_MISS_EVADE && !spell->m_originalCaster->IsFriendlyTo(unit) && (!spell->m_spellInfo->IsPositive() || spell->m_spellInfo->HasEffect(SPELL_EFFECT_DISPEL)) && (spell->m_spellInfo->HasInitialAggro() || unit->IsEngaged()))
        unit->SetInCombatWith(spell->m_originalCaster);

    spell->CallScriptBeforeHitHandlers(MissCondition);

    _enablePVP = false; // need to check PvP state before spell effects, but act on it afterwards
    if (_spellHitTarget)
    {
        // if target is flagged for pvp also flag caster if a player
        // but respect current pvp rules (buffing/healing npcs flagged for pvp only flags you if they are in combat)
        if (unit->IsPvP() && (unit->IsInCombat() || unit->IsCharmedOwnedByPlayerOrPlayer()) && spell->m_caster->GetTypeId() == TYPEID_PLAYER)
            _enablePVP = true; // Decide on PvP flagging now, but act on it later.

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

void Spell::TargetInfo::DoTargetSpellHit(Spell* spell, SpellEffectInfo const& spellEffectInfo)
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
        spell->DoSpellEffectHit(_spellHitTarget, spellEffectInfo, *this);

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
        bool const canEffectTrigger = !spell->m_spellInfo->HasAttribute(SPELL_ATTR3_CANT_TRIGGER_PROC) && spell->unitTarget->CanProc() &&
            (spell->CanExecuteTriggersOnHit(EffectMask) || MissCondition == SPELL_MISS_IMMUNE || MissCondition == SPELL_MISS_IMMUNE2);

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

                    if (!spell->m_spellInfo->IsPositiveEffect(i))
                    {
                        positive = false;
                        break;
                    }
                }
            }

            switch (spell->m_spellInfo->DmgClass)
            {
                case SPELL_DAMAGE_CLASS_MAGIC:
                    if (positive)
                    {
                        procAttacker |= PROC_FLAG_DONE_SPELL_MAGIC_DMG_CLASS_POS;
                        procVictim |= PROC_FLAG_TAKEN_SPELL_MAGIC_DMG_CLASS_POS;
                    }
                    else
                    {
                        procAttacker |= PROC_FLAG_DONE_SPELL_MAGIC_DMG_CLASS_NEG;
                        procVictim |= PROC_FLAG_TAKEN_SPELL_MAGIC_DMG_CLASS_NEG;
                    }
                    break;
                case SPELL_DAMAGE_CLASS_NONE:
                    if (positive)
                    {
                        procAttacker |= PROC_FLAG_DONE_SPELL_NONE_DMG_CLASS_POS;
                        procVictim |= PROC_FLAG_TAKEN_SPELL_NONE_DMG_CLASS_POS;
                    }
                    else
                    {
                        procAttacker |= PROC_FLAG_DONE_SPELL_NONE_DMG_CLASS_NEG;
                        procVictim |= PROC_FLAG_TAKEN_SPELL_NONE_DMG_CLASS_NEG;
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
                addhealth = Unit::SpellCriticalHealingBonus(caster, spell->m_spellInfo, addhealth, nullptr);
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
                caster->SetLastDamagedTargetGuid(spell->unitTarget->GetGUID());

                // Add bonuses and fill damageInfo struct
                caster->CalculateSpellDamageTaken(&damageInfo, spell->m_damage, spell->m_spellInfo, spell->m_attackType, IsCrit, MissCondition == SPELL_MISS_BLOCK, spell);
                Unit::DealDamageMods(damageInfo.target, damageInfo.damage, &damageInfo.absorb);

                // Send log damage message to client
                caster->SendSpellNonMeleeDamageLog(&damageInfo);

                hitMask |= createProcHitMask(&damageInfo, MissCondition);
                procVictim |= PROC_FLAG_TAKEN_DAMAGE;

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
            if (MissCondition == SPELL_MISS_RESIST && spell->m_spellInfo->HasAttribute(SPELL_ATTR0_CU_PICKPOCKET) && spell->unitTarget->GetTypeId() == TYPEID_UNIT)
            {
                Unit* unitCaster = ASSERT_NOTNULL(spell->m_caster->ToUnit());
                unitCaster->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TALK);
                spell->unitTarget->ToCreature()->EngageWithTarget(unitCaster);
            }
        }

        // Do triggers for unit
        if (canEffectTrigger)
        {
            Unit::ProcSkillsAndAuras(caster, spell->unitTarget, procAttacker, procVictim, procSpellType, PROC_SPELL_PHASE_HIT, hitMask, spell, spellDamageInfo.get(), healInfo.get());

            // item spells (spell hit of non-damage spell may also activate items, for example seal of corruption hidden hit)
            if (caster->GetTypeId() == TYPEID_PLAYER && (procSpellType & (PROC_SPELL_TYPE_DAMAGE | PROC_SPELL_TYPE_NO_DMG_HEAL)))
            {
                if (spell->m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MELEE || spell->m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_RANGED)
                    if (!spell->m_spellInfo->HasAttribute(SPELL_ATTR0_STOP_ATTACK_TARGET) && !spell->m_spellInfo->HasAttribute(SPELL_ATTR4_CANT_TRIGGER_ITEM_SPELLS))
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
                unitCaster->AtTargetAttacked(unit, spell->m_spellInfo->HasInitialAggro());

            if (!unit->IsStandState())
                unit->SetStandState(UNIT_STAND_STATE_STAND);
        }

        // Check for SPELL_ATTR7_INTERRUPT_ONLY_NONPLAYER
        if (MissCondition == SPELL_MISS_NONE && spell->m_spellInfo->HasAttribute(SPELL_ATTR7_INTERRUPT_ONLY_NONPLAYER) && unit->GetTypeId() != TYPEID_PLAYER)
            caster->CastSpell(unit, SPELL_INTERRUPT_NONPLAYER, true);
    }

    if (_spellHitTarget)
    {
        //AI functions
        if (Creature* cHitTarget = _spellHitTarget->ToCreature())
            if (CreatureAI* hitTargetAI = cHitTarget->AI())
                hitTargetAI->SpellHit(spell->m_caster, spell->m_spellInfo);

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
                for (uint8 i = 0; i < spell->m_spellInfo->GetEffects().size(); ++i)
                    if ((effMask & (1 << i)) && aurApp->HasEffect(i))
                        effMask &= ~(1 << i);

                if (effMask)
                    _spellHitTarget->_ApplyAura(aurApp, effMask);
            }
        }

        // Needs to be called after dealing damage/healing to not remove breaking on damage auras
        spell->DoTriggersOnSpellHit(_spellHitTarget, EffectMask);

        if (_enablePVP)
            spell->m_caster->ToPlayer()->UpdatePvP(true);
    }

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

    if (Player* player = unit->ToPlayer())
    {
        player->StartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_SPELL_TARGET, m_spellInfo->Id);
        player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, m_spellInfo->Id, 0, m_caster);
        player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2, m_spellInfo->Id);
    }

    if (Player* player = m_caster->ToPlayer())
    {
        player->StartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_SPELL_CASTER, m_spellInfo->Id);
        player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL2, m_spellInfo->Id, 0, unit);
    }

    if (m_caster != unit)
    {
        // Recheck  UNIT_FLAG_NON_ATTACKABLE for delayed spells
        if (m_spellInfo->Speed > 0.0f && unit->HasUnitFlag(UNIT_FLAG_NON_ATTACKABLE) && unit->GetCharmerOrOwnerGUID() != m_caster->GetGUID())
            return SPELL_MISS_EVADE;

        if (m_caster->IsValidAttackTarget(unit, m_spellInfo))
            unit->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_HITBYSPELL);
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

            if (m_originalCaster && unit->IsInCombat() && m_spellInfo->HasInitialAggro())
            {
                if (m_originalCaster->HasUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED)) // only do explicit combat forwarding for PvP enabled units
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
            if (SpellInfo const* actualSpellInfo = m_spellInfo->GetAuraRankForLevel(unitTarget->GetLevel()))
                hitInfo.AuraSpellInfo = actualSpellInfo;

            for (SpellEffectInfo const& auraEffectInfo : hitInfo.AuraSpellInfo->GetEffects())
            {
                hitInfo.AuraBasePoints[auraEffectInfo.EffectIndex] = auraEffectInfo.BasePoints;
                if (m_spellInfo->GetEffect(auraEffectInfo.EffectIndex).Effect != auraEffectInfo.Effect)
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
            for (SpellEffectInfo const& auraSpellEffect : hitInfo.AuraSpellInfo->GetEffects())
            {
                // mod duration only for effects applying aura!
                if (hitInfo.EffectMask & (1 << auraSpellEffect.EffectIndex) &&
                    auraSpellEffect.IsUnitOwnedAuraEffect() &&
                    !hitInfo.AuraSpellInfo->IsPositiveEffect(auraSpellEffect.EffectIndex))
                {
                    hitInfo.Positive = false;
                    break;
                }
            }
        }

        hitInfo.AuraDuration = Aura::CalcMaxDuration(hitInfo.AuraSpellInfo, origCaster);

        // unit is immune to aura if it was diminished to 0 duration
        if (!hitInfo.Positive && !unit->ApplyDiminishingToDuration(hitInfo.AuraSpellInfo, triggered, hitInfo.AuraDuration, origCaster, diminishLevel))
            if (std::all_of(std::begin(hitInfo.AuraSpellInfo->GetEffects()), std::end(hitInfo.AuraSpellInfo->GetEffects()), [](SpellEffectInfo const& effInfo) { return !effInfo.IsEffect() || effInfo.Effect == SPELL_EFFECT_APPLY_AURA; }))
                return SPELL_MISS_IMMUNE;
    }

    return SPELL_MISS_NONE;
}

void Spell::DoSpellEffectHit(Unit* unit, SpellEffectInfo const& spellEffectInfo, TargetInfo& hitInfo)
{
    if (uint8 aura_effmask = Aura::BuildEffectMaskForOwner(m_spellInfo, 1 << spellEffectInfo.EffectIndex, unit))
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

                    hitInfo.AuraDuration = caster->ModSpellDuration(hitInfo.AuraSpellInfo, unit, hitInfo.AuraDuration, hitInfo.Positive, hitInfo.HitAura->GetEffectMask());

                    // Haste modifies duration of channeled spells
                    if (m_spellInfo->IsChanneled())
                        caster->ModSpellDurationTime(hitInfo.AuraSpellInfo, hitInfo.AuraDuration, this);
                    // and duration of auras affected by SPELL_AURA_PERIODIC_HASTE
                    else if (m_originalCaster && (m_originalCaster->HasAuraTypeWithAffectMask(SPELL_AURA_PERIODIC_HASTE, hitInfo.AuraSpellInfo) || m_spellInfo->HasAttribute(SPELL_ATTR5_HASTE_AFFECT_DURATION)))
                        hitInfo.AuraDuration = int32(hitInfo.AuraDuration * m_originalCaster->GetFloatValue(UNIT_MOD_CAST_SPEED));

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
    HandleEffects(unit, nullptr, nullptr, nullptr, spellEffectInfo, SPELL_EFFECT_HANDLE_HIT_TARGET);
    _spellAura = nullptr;
}

void Spell::DoTriggersOnSpellHit(Unit* unit, uint8 effMask)
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
                m_caster->CastSpell(unit, i->triggeredSpell->Id, true);
                TC_LOG_DEBUG("spells", "Spell {} triggered spell {} by SPELL_AURA_ADD_TARGET_TRIGGER aura", m_spellInfo->Id, i->triggeredSpell->Id);

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
                unit->CastSpell(unit, *i, m_caster->GetGUID());
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
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
        if (spellEffectInfo.IsEffect(SPELL_EFFECT_APPLY_AURA))
            channelAuraMask |= 1 << spellEffectInfo.EffectIndex;

    channelAuraMask &= channelTargetEffectMask;

    float range = 0;
    if (channelAuraMask)
    {
        range = m_spellInfo->GetMaxRange(IsPositive());
        if (Player* modOwner = m_caster->GetSpellModOwner())
            modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RANGE, range, this);

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
            for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
            {
                if (spellEffectInfo.IsEffect(SPELL_EFFECT_APPLY_AURA))
                {
                    // Change aura with ranks only if basepoints are taken from spellInfo and aura is positive
                    if (m_spellInfo->IsPositiveEffect(spellEffectInfo.EffectIndex))
                    {
                        m_auraScaleMask |= (1 << spellEffectInfo.EffectIndex);
                        if (m_spellValue->EffectBasePoints[spellEffectInfo.EffectIndex] != spellEffectInfo.BasePoints)
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
    m_caster->m_Events.AddEvent(_spellEvent, m_caster->m_Events.CalculateTime(1ms));

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

    uint32 param1 = 0, param2 = 0;
    SpellCastResult result = CheckCast(true, &param1, &param2);
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

        if (param1 || param2)
            SendCastResult(result, &param1, &param2);
        else
            SendCastResult(result);

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
            m_casttime = m_spellInfo->CalcCastTime(this);
        }
        else
            m_casttime = 0; // Set cast time to 0 if .cheat casttime is enabled.
    }
    else
        m_casttime = m_spellInfo->CalcCastTime(this);

    // don't allow channeled spells / spells with cast time to be cast while moving
    // exception are only channeled spells that have no casttime and SPELL_ATTR5_CAN_CHANNEL_WHEN_MOVING
    // (even if they are interrupted on moving, spells with almost immediate effect get to have their effect processed before movement interrupter kicks in)
    if ((m_spellInfo->IsChanneled() || m_casttime) && m_caster->GetTypeId() == TYPEID_PLAYER && !(m_caster->ToPlayer()->IsCharmed() && m_caster->ToPlayer()->GetCharmerGUID().IsCreature()) && m_caster->ToPlayer()->isMoving() && (m_spellInfo->InterruptFlags & SPELL_INTERRUPT_FLAG_MOVEMENT))
    {
        // 1. Has casttime, 2. Or doesn't have flag to allow movement during channel
        if (m_casttime || !m_spellInfo->IsMoveAllowedChannel())
        {
            SendCastResult(SPELL_FAILED_MOVING);
            finish(false);
            return SPELL_FAILED_MOVING;
        }
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

    // set timer base at cast time
    ReSetTimer();

    TC_LOG_DEBUG("spells", "Spell::prepare: spell id {} source {} caster {} customCastFlags {} mask {}", m_spellInfo->Id, m_caster->GetEntry(), m_originalCaster ? m_originalCaster->GetEntry() : -1, _triggeredCastFlags, m_targets.GetTargetMask());

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
            if (!(_triggeredCastFlags & TRIGGERED_IGNORE_AURA_INTERRUPT_FLAGS) && m_spellInfo->IsBreakingStealth())
            {
                unitCaster->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_CAST);
                for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
                {
                    if (spellEffectInfo.GetUsedTargetObjectType() == TARGET_OBJECT_TYPE_UNIT)
                    {
                        unitCaster->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_SPELL_ATTACK);
                        break;
                    }
                }
            }

            unitCaster->SetCurrentCastSpell(this);
        }
        SendSpellStart();

        if (!(_triggeredCastFlags & TRIGGERED_IGNORE_GCD))
            TriggerGlobalCooldown();

        // Call CreatureAI hook OnSpellStart
        if (Creature* caster = m_caster->ToCreature())
            if (caster->IsAIEnabled())
                caster->AI()->OnSpellStart(GetSpellInfo());

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
            for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
                if (spellEffectInfo.IsUnitOwnedAuraEffect())
                    aura_effmask |= 1 << spellEffectInfo.EffectIndex;

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
    // The spell focusing is making sure that we have a valid cast target guid when we need it so only check for a guid value here.
    if (Creature* creatureCaster = m_caster->ToCreature())
        if (!creatureCaster->GetTarget().IsEmpty() && !creatureCaster->HasUnitFlag(UNIT_FLAG_POSSESSED))
            if (WorldObject const* target = ObjectAccessor::GetUnit(*creatureCaster, creatureCaster->GetTarget()))
                creatureCaster->SetInFront(target);

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
        if (m_spellInfo->HasAttribute(SPELL_ATTR1_DISMISS_PET))
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

    // CAST SPELL
    SendSpellCooldown();

    HandleLaunchPhase();

    // we must send smsg_spell_go packet before m_castItem delete in TakeCastItem()...
    SendSpellGo();

    if (!m_spellInfo->IsChanneled())
        if (Creature* creatureCaster = m_caster->ToCreature())
            creatureCaster->ReleaseSpellFocus(this);

    // Okay, everything is prepared. Now we need to distinguish between immediate and evented delayed spells
    if (m_spellInfo->Speed > 0.0f && !m_spellInfo->IsChanneled())
    {
        // Remove used for cast item if need (it can be already NULL after TakeReagents call
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
                m_caster->CastSpell(m_targets.GetUnitTarget() ? m_targets.GetUnitTarget() : m_caster, id, true);
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
        if (m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MAGIC)
            procAttacker = IsPositive() ? PROC_FLAG_DONE_SPELL_MAGIC_DMG_CLASS_POS : PROC_FLAG_DONE_SPELL_MAGIC_DMG_CLASS_NEG;
        else
            procAttacker = IsPositive() ? PROC_FLAG_DONE_SPELL_NONE_DMG_CLASS_POS : PROC_FLAG_DONE_SPELL_NONE_DMG_CLASS_NEG;
    }

    uint32 hitMask = m_hitMask;
    if (!(hitMask & PROC_HIT_CRITICAL))
        hitMask |= PROC_HIT_NORMAL;

    Unit::ProcSkillsAndAuras(m_originalCaster, nullptr, procAttacker, PROC_FLAG_NONE, PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_CAST, hitMask, this, nullptr, nullptr);

    // Call CreatureAI hook OnSpellCast
    if (Creature* caster = m_originalCaster->ToCreature())
        if (caster->IsAIEnabled())
            caster->AI()->OnSpellCast(GetSpellInfo());
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
        if (duration > 0)
        {
            // First mod_duration then haste - see Missile Barrage
            // Apply duration mod
            if (Player* modOwner = m_caster->GetSpellModOwner())
                modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_DURATION, duration);

            // Apply haste mods
            m_caster->ModSpellDurationTime(m_spellInfo, duration, this);

            m_channeledDuration = duration;
            SendChannelStart(duration);
        }
        else if (duration == -1)
            SendChannelStart(duration);

        if (duration != 0)
        {
            m_spellState = SPELL_STATE_CASTING;
            // GameObjects shouldn't cast channeled spells
            ASSERT_NOTNULL(m_caster->ToUnit())->AddInterruptMask(m_spellInfo->ChannelInterruptFlags);
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
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
    {
        // don't do anything for empty effect
        if (!spellEffectInfo.IsEffect())
            continue;

        // call effect handlers to handle destination hit
        HandleEffects(nullptr, nullptr, nullptr, nullptr, spellEffectInfo, SPELL_EFFECT_HANDLE_HIT);
    }

    // process items
    DoProcessTargetContainer(m_UniqueItemInfo);
}

void Spell::_handle_finish_phase()
{
    if (Unit* unitCaster = m_caster->ToUnit())
    {
        // Take for real after all targets are processed
        if (m_needComboPoints)
            unitCaster->ClearComboPoints();

        // Real add combo points from effects
        if (m_comboTarget && m_comboPointGain)
        {
            // remove Premed-like effects unless they were caused by ourselves
            // (this Aura removes the already-added CP when it expires from duration - now that we've added CP, this shouldn't happen anymore!)
            if (!m_spellInfo->HasAura(SPELL_AURA_RETAIN_COMBO_POINTS))
                unitCaster->RemoveAurasByType(SPELL_AURA_RETAIN_COMBO_POINTS);
            unitCaster->AddComboPoints(m_comboTarget, m_comboPointGain);
        }

        if (m_spellInfo->HasEffect(SPELL_EFFECT_ADD_EXTRA_ATTACKS))
            unitCaster->SetLastExtraAttackSpell(m_spellInfo->Id);
    }

    // Handle procs on finish
    if (!m_originalCaster)
        return;

    uint32 procAttacker = m_procAttacker;
    if (!procAttacker)
    {
        if (m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MAGIC)
            procAttacker = IsPositive() ? PROC_FLAG_DONE_SPELL_MAGIC_DMG_CLASS_POS : PROC_FLAG_DONE_SPELL_MAGIC_DMG_CLASS_NEG;
        else
            procAttacker = IsPositive() ? PROC_FLAG_DONE_SPELL_NONE_DMG_CLASS_POS : PROC_FLAG_DONE_SPELL_NONE_DMG_CLASS_NEG;
    }

    Unit::ProcSkillsAndAuras(m_originalCaster, nullptr, procAttacker, PROC_FLAG_NONE, PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_FINISH, m_hitMask, this, nullptr, nullptr);
}

void Spell::SendSpellCooldown()
{
    if (m_caster->GetTypeId() == TYPEID_GAMEOBJECT)
        return;

    m_caster->ToUnit()->GetSpellHistory()->HandleCooldowns(m_spellInfo, m_CastItem, this);
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
        TC_LOG_DEBUG("spells", "Spell {} is cancelled due to removal of target.", m_spellInfo->Id);
        cancel();
        return;
    }

    // check if the player caster has moved before the spell finished
    if (m_caster->GetTypeId() == TYPEID_PLAYER && m_timer != 0 &&
        m_caster->ToPlayer()->isMoving() && m_spellInfo->InterruptFlags & SPELL_INTERRUPT_FLAG_MOVEMENT &&
        (!m_spellInfo->HasEffect(SPELL_EFFECT_STUCK) || !m_caster->ToPlayer()->HasUnitMovementFlag(MOVEMENTFLAG_FALLING_FAR)))
    {
        // don't cancel for melee, autorepeat, triggered and instant spells
        if (!m_spellInfo->IsNextMeleeSwingSpell() && !IsAutoRepeat() && !IsTriggered() && !(IsChannelActive() && m_spellInfo->IsMoveAllowedChannel()))
        {
            // if charmed by creature, trust the AI not to cheat and allow the cast to proceed
            // @todo this is a hack, "creature" movesplines don't differentiate turning/moving right now
            // however, checking what type of movement the spline is for every single spline would be really expensive
            if (!m_caster->ToPlayer()->GetCharmerGUID().IsCreature())
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
                    TC_LOG_DEBUG("spells", "Channeled spell {} is removed due to lack of targets", m_spellInfo->Id);
                    m_timer = 0;

                    // Also remove applied auras
                    for (TargetInfo const& target : m_UniqueTargetInfo)
                        if (Unit* unit = m_caster->GetGUID() == target.TargetGUID ? m_caster->ToUnit() : ObjectAccessor::GetUnit(*m_caster, target.TargetGUID))
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
            TC_LOG_DEBUG("spells", "Statue {} is unsummoned in spell {} finish", unitCaster->GetGUID().ToString(), m_spellInfo->Id);
            // Avoid infinite loops with setDeathState(JUST_DIED) being called over and over
            // It might make sense to do this check in Unit::setDeathState() and all overloaded functions
            if(unitCaster->getDeathState() != JUST_DIED)
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
            if ((*i)->IsAffectedOnSpell(m_spellInfo))
            {
                found = true;
                break;
            }
        }

        if (!found && !m_spellInfo->HasAttribute(SPELL_ATTR2_NOT_RESET_AUTO_ACTIONS))
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
    if (m_spellInfo->HasAttribute(SPELL_ATTR0_STOP_ATTACK_TARGET))
        unitCaster->AttackStop();
}

void Spell::WriteCastResultInfo(WorldPacket& data, Player* caster, SpellInfo const* spellInfo, uint8 castCount, SpellCastResult result, SpellCustomErrors customError, uint32* param1 /*= nullptr*/, uint32* param2 /*= nullptr*/)
{
    data << uint8(castCount);                               // single cast or multi 2.3 (0/1)
    data << uint32(spellInfo->Id);
    data << uint8(result);                                  // problem
    switch (result)
    {
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
                for (SpellEffectInfo const& spellEffectInfo : spellInfo->GetEffects())
                {
                    if (uint32 itemType = spellEffectInfo.ItemType)
                    {
                        item = itemType;
                        break;
                    }
                }

                ItemTemplate const* proto = sObjectMgr->GetItemTemplate(item);
                if (proto && proto->ItemLimitCategory)
                    data << uint32(proto->ItemLimitCategory);
            }
            break;
        }
        case SPELL_FAILED_CUSTOM_ERROR:
            data << uint32(customError);
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
        case SPELL_FAILED_PREVENTED_BY_MECHANIC:
            if (param1)
                data << uint32(*param1);
            else
                data << uint32(spellInfo->Mechanic);
            break;
        case SPELL_FAILED_NEED_EXOTIC_AMMO:
            if (param1)
                data << uint32(*param1);
            else
                data << uint32(spellInfo->EquippedItemSubClassMask);
            break;
        case SPELL_FAILED_NEED_MORE_ITEMS:
            if (param1 && param2)
            {
                data << uint32(*param1);
                data << uint32(*param2);
            }
            else
            {
                data << uint32(0); // Item entry
                data << uint32(0); // Count
            }
            break;
        case SPELL_FAILED_MIN_SKILL:
            if (param1 && param2)
            {
                data << uint32(*param1);
                data << uint32(*param2);
            }
            else
            {
                data << uint32(0); // SkillLine.dbc Id
                data << uint32(0); // Amount
            }
            break;
        case SPELL_FAILED_FISHING_TOO_LOW:
            if (param1)
                data << uint32(*param1);
            else
                data << uint32(0); // Skill level
            break;
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

    if (_triggeredCastFlags & TRIGGERED_DONT_REPORT_CAST_ERROR)
        result = SPELL_FAILED_DONT_REPORT;

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

    if (_triggeredCastFlags & TRIGGERED_DONT_REPORT_CAST_ERROR)
        result = SPELL_FAILED_DONT_REPORT;

    WorldPacket data(SMSG_PET_CAST_FAILED, 1 + 4 + 1);
    WriteCastResultInfo(data, player, m_spellInfo, m_cast_count, result, m_customError);

    player->SendDirectMessage(&data);
}

void Spell::SendMountResult(MountResult result)
{
    if (result == MountResult::Ok)
        return;

    if (m_caster->GetTypeId() != TYPEID_PLAYER)
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

    //TC_LOG_DEBUG("spells", "Sending SMSG_SPELL_START id={}", m_spellInfo->Id);

    uint32 castFlags = CAST_FLAG_UNKNOWN_2;
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

    if (m_spellInfo->HasAttribute(SPELL_ATTR0_REQ_AMMO) || m_spellInfo->HasAttribute(SPELL_ATTR0_CU_NEEDS_AMMO_DATA))
        castFlags |= CAST_FLAG_AMMO;
    if ((m_caster->GetTypeId() == TYPEID_PLAYER ||
        (m_caster->GetTypeId() == TYPEID_UNIT && m_caster->ToCreature()->IsPet()))
         && m_spellInfo->PowerType != POWER_HEALTH)
        castFlags |= CAST_FLAG_POWER_LEFT_SELF;

    if (m_spellInfo->RuneCostID && m_spellInfo->PowerType == POWER_RUNE)
        castFlags |= CAST_FLAG_NO_GCD; // not needed, but Blizzard sends it

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
    castData.CastTime = m_timer;

    m_targets.Write(castData.Target);

    if (castFlags & CAST_FLAG_POWER_LEFT_SELF)
        castData.RemainingPower = ASSERT_NOTNULL(m_caster->ToUnit())->GetPower(m_spellInfo->PowerType);

    if (castFlags & CAST_FLAG_AMMO)
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

    m_caster->SendMessageToSet(packet.Write(), true);
}

void Spell::SendSpellGo()
{
    // not send invisible spell casting
    if (!IsNeedSendToClient())
        return;

    uint32 castFlags = CAST_FLAG_UNKNOWN_9;

    // triggered spells with spell visual != 0
    if (((IsTriggered() && !m_spellInfo->IsAutoRepeatRangedSpell()) || m_triggeredByAuraSpell) && !m_fromClient)
        castFlags |= CAST_FLAG_PENDING;

    if (m_spellInfo->HasAttribute(SPELL_ATTR0_REQ_AMMO) || m_spellInfo->HasAttribute(SPELL_ATTR0_CU_NEEDS_AMMO_DATA))
        castFlags |= CAST_FLAG_AMMO; // arrows/bullets visual

    if ((m_caster->GetTypeId() == TYPEID_PLAYER ||
        (m_caster->GetTypeId() == TYPEID_UNIT && m_caster->ToCreature()->IsPet()))
        && m_spellInfo->PowerType != POWER_HEALTH)
        castFlags |= CAST_FLAG_POWER_LEFT_SELF;

    if ((m_caster->GetTypeId() == TYPEID_PLAYER)
        && (m_caster->ToPlayer()->GetClass() == CLASS_DEATH_KNIGHT)
        && m_spellInfo->RuneCostID
        && m_spellInfo->PowerType == POWER_RUNE
        && !(_triggeredCastFlags & TRIGGERED_IGNORE_POWER_AND_REAGENT_COST))
    {
        castFlags |= CAST_FLAG_NO_GCD; // not needed, but Blizzard sends it
        castFlags |= CAST_FLAG_RUNE_LIST; // rune cooldowns list
    }

    if (m_spellInfo->HasEffect(SPELL_EFFECT_ACTIVATE_RUNE))
        castFlags |= CAST_FLAG_RUNE_LIST; // rune cooldowns list

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
    castData.CastTime = GameTime::GetGameTimeMS();

    UpdateSpellCastDataTargets(castData);

    m_targets.Write(castData.Target);

    if (castFlags & CAST_FLAG_POWER_LEFT_SELF)
        castData.RemainingPower = ASSERT_NOTNULL(m_caster->ToUnit())->GetPower(m_spellInfo->PowerType);

    if (castFlags & CAST_FLAG_RUNE_LIST && !m_spellInfo->HasAura(SPELL_AURA_CONVERT_RUNE)) // rune cooldowns list
    {
        castData.RemainingRunes.emplace();

        /// @todo There is a crash caused by a spell with CAST_FLAG_RUNE_LIST cast by a creature
        // The creature is the mover of a player, so HandleCastSpellOpcode uses it as the caster
        if (Player* player = m_caster->ToPlayer())
        {
            uint8 runeMaskInitial = m_runesState;
            uint8 runeMaskAfterCast = player->GetRunesState();
            castData.RemainingRunes->Start = runeMaskInitial; // runes state before
            castData.RemainingRunes->Count = runeMaskAfterCast; // runes state after

            for (uint8 i = 0; i < MAX_RUNES; ++i)
            {
                uint8 mask = (1 << i);
                if ((mask & runeMaskInitial) && !(mask & runeMaskAfterCast))  // usable before and on cooldown now...
                {
                    // float casts ensure the division is performed on floats as we need float result
                    float baseCd = float(player->GetRuneBaseCooldown(i));
                    castData.RemainingRunes->Cooldowns.push_back(uint8((baseCd - float(player->GetRuneCooldown(i))) / baseCd * 255));
                }
            }
        }
    }

    if (castFlags & CAST_FLAG_ADJUST_MISSILE)
    {
        castData.MissileTrajectory.emplace();
        castData.MissileTrajectory->Pitch = m_targets.GetElevation();
        castData.MissileTrajectory->TravelTime = m_delayMoment;
    }

    if (castFlags & CAST_FLAG_AMMO)
    {
        castData.Ammo.emplace();
        UpdateSpellCastDataAmmo(*castData.Ammo);
    }

    // should be sent to self only
    if (castFlags & CAST_FLAG_POWER_LEFT_SELF && m_caster->IsPlayer())
    {
        m_caster->ToPlayer()->SendDirectMessage(packet.Write());

        packet.Clear();

        // update nearby players (remove flag)
        castData.CastFlags &= ~CAST_FLAG_POWER_LEFT_SELF;
        castData.RemainingPower = std::nullopt;
        m_caster->SendMessageToSet(packet.Write(), false);
    }
    else
        m_caster->SendMessageToSet(packet.Write(), true);
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
                else if (m_caster->ToPlayer()->HasAura(46699))      // Requires No Ammo
                {
                    ammoDisplayID = 5996;                   // normal arrow
                    ammoInventoryType = INVTYPE_AMMO;
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
                            default:
                                nonRangedAmmoDisplayID = itemEntry->DisplayInfoID;
                                nonRangedAmmoInventoryType = itemEntry->InventoryType;
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

    ammo.DisplayID = ammoDisplayID;
    ammo.InventoryType = ammoInventoryType;
}

/// Writes miss and hit targets for a SMSG_SPELL_GO packet
void Spell::UpdateSpellCastDataTargets(WorldPackets::Spells::SpellCastData& data)
{
    // This function also fill data for channeled spells:
    // m_needAliveTargetMask req for stop channelig if one target die
    for (TargetInfo& targetInfo : m_UniqueTargetInfo)
    {
        if (targetInfo.EffectMask == 0)                  // No effect apply - all immuned add state
            // possibly SPELL_MISS_IMMUNE2 for this??
            targetInfo.MissCondition = SPELL_MISS_IMMUNE2;

        if (targetInfo.MissCondition == SPELL_MISS_NONE || (targetInfo.MissCondition == SPELL_MISS_BLOCK && !m_spellInfo->HasAttribute(SPELL_ATTR3_COMPLETELY_BLOCKED))) // Add only hits and partial blocked
        {
            data.HitTargets->push_back(targetInfo.TargetGUID);

            m_channelTargetEffectMask |= targetInfo.EffectMask;
        }
        else // misses
        {
            // Only send blocks in spell_go packets if we know that the spell is not going to do anything to the target.
            // Spells that are partially blocked will send their block result in their according combat log packet.
            if (targetInfo.MissCondition == SPELL_MISS_BLOCK && !m_spellInfo->HasAttribute(SPELL_ATTR3_COMPLETELY_BLOCKED))
                continue;

            WorldPackets::Spells::SpellMissStatus missStatus;
            missStatus.TargetGUID = targetInfo.TargetGUID;
            missStatus.Reason = targetInfo.MissCondition;
            if (targetInfo.MissCondition == SPELL_MISS_REFLECT)
                missStatus.ReflectStatus = targetInfo.ReflectResult;

            data.MissStatus->push_back(missStatus);
        }
    }

    for (GOTargetInfo const& targetInfo : m_UniqueGOTargetInfo)
        data.HitTargets->push_back(targetInfo.TargetGUID); // Always hits

    for (CorpseTargetInfo const& targetInfo : m_UniqueCorpseTargetInfo)
        data.HitTargets->push_back(targetInfo.TargetGUID); // Always hits

    // Reset m_needAliveTargetMask for non channeled spell
    if (!m_spellInfo->IsChanneled())
        m_channelTargetEffectMask = 0;
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
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
    {
        if (!m_effectExecuteData[spellEffectInfo.EffectIndex])
            continue;

        data << uint32(spellEffectInfo.Effect);             // spell effect

        data.append(*m_effectExecuteData[spellEffectInfo.EffectIndex]);

        delete m_effectExecuteData[spellEffectInfo.EffectIndex];
        m_effectExecuteData[spellEffectInfo.EffectIndex] = nullptr;
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

void Spell::ExecuteLogEffectInterruptCast(uint8 effIndex, Unit* victim, uint32 spellId)
{
    InitEffectExecuteData(effIndex);
    *m_effectExecuteData[effIndex] << victim->GetPackGUID();
    *m_effectExecuteData[effIndex] << uint32(spellId);
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
    WorldPacket data(SMSG_SPELL_FAILURE, (8+4+1));
    data << m_caster->GetPackGUID();
    data << uint8(m_cast_count);
    data << uint32(m_spellInfo->Id);
    data << uint8(result);
    m_caster->SendMessageToSet(&data, true);

    data.Initialize(SMSG_SPELL_FAILED_OTHER, (8+4));
    data << m_caster->GetPackGUID();
    data << uint8(m_cast_count);
    data << uint32(m_spellInfo->Id);
    data << uint8(result);
    m_caster->SendMessageToSet(&data, true);
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
        unitCaster->SetChannelSpellId(0);
    }

    WorldPacket data(MSG_CHANNEL_UPDATE, 8+4);
    data << unitCaster->GetPackGUID();
    data << uint32(time);

    unitCaster->SendMessageToSet(&data, true);
}

void Spell::SendChannelStart(uint32 duration)
{
    // GameObjects don't channel
    Unit* unitCaster = m_caster->ToUnit();
    if (!unitCaster)
        return;

    ObjectGuid channelTarget = m_targets.HasDst() ? unitCaster->GetGUID() : m_targets.GetObjectTargetGUID();
    if (!channelTarget && !m_spellInfo->NeedsExplicitUnitTarget())
        if (m_UniqueTargetInfo.size() + m_UniqueGOTargetInfo.size() == 1)   // this is for TARGET_SELECT_CATEGORY_NEARBY
            channelTarget = !m_UniqueTargetInfo.empty() ? m_UniqueTargetInfo.front().TargetGUID : m_UniqueGOTargetInfo.front().TargetGUID;

    WorldPacket data(MSG_CHANNEL_START, (8+4+4));
    data << unitCaster->GetPackGUID();
    data << uint32(m_spellInfo->Id);
    data << uint32(duration);

    unitCaster->SendMessageToSet(&data, true);

    m_timer = duration;
    if (channelTarget)
    {
        unitCaster->SetChannelObjectGuid(channelTarget);

        if (Creature* creatureCaster = m_caster->ToCreature())
            if (!creatureCaster->HasSpellFocus(this))
                creatureCaster->SetSpellFocus(this, ObjectAccessor::GetWorldObject(*creatureCaster, channelTarget));
    }

    unitCaster->SetChannelSpellId(m_spellInfo->Id);
}

void Spell::SendResurrectRequest(Player* target)
{
    // get resurrector name for creature resurrections, otherwise packet will be not accepted
    // for player resurrections the name is looked up by guid
    std::string sentName;
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        sentName = m_caster->GetNameForLocaleIdx(target->GetSession()->GetSessionDbLocaleIndex());

    WorldPacket data(SMSG_RESURRECT_REQUEST, 8 + 4 + sentName.size() + 1 + 1 + 1);
    data << uint64(m_caster->GetGUID());
    data << uint32(sentName.size() + 1);
    data << sentName;
    data << uint8(m_caster->GetTypeId() == TYPEID_UNIT && m_caster->ToCreature()->IsSpiritHealer()); // "you'll be afflicted with resurrection sickness"
    // override delay sent with SMSG_CORPSE_RECLAIM_DELAY, set instant resurrection for spells with this attribute
    data << uint8(!m_spellInfo->HasAttribute(SPELL_ATTR3_IGNORE_RESURRECTION_TIMER));
    target->SendDirectMessage(&data);
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
        TC_LOG_ERROR("spells", "Cast item has no item prototype {}", m_CastItem->GetGUID().ToString());
        return;
    }

    bool expendable = false;
    bool withoutCharges = false;

    for (int i = 0; i < MAX_ITEM_PROTO_SPELLS; ++i)
    {
        if (proto->Spells[i].SpellId > 0)
        {
            // item has limited charges
            if (proto->Spells[i].SpellCharges)
            {
                if (proto->Spells[i].SpellCharges < 0)
                    expendable = true;

                int32 charges = m_CastItem->GetSpellCharges(i);

                // item has charges left for this slot
                if (charges && proto->Spells[i].SpellId == int32(m_spellInfo->Id))
                {
                    (charges > 0) ? --charges : ++charges;  // abs(charges) less at 1 after use
                    if (proto->Stackable == 1)
                        m_CastItem->SetSpellCharges(i, charges);
                    m_CastItem->SetState(ITEM_CHANGED, player);
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
    if (unitCaster->GetTypeId() == TYPEID_PLAYER)
    {
        if (powerType == POWER_RAGE || powerType == POWER_ENERGY || powerType == POWER_RUNE)
        {
            if (ObjectGuid targetGUID = m_targets.GetUnitTargetGUID())
            {
                auto ihit = std::find_if(std::begin(m_UniqueTargetInfo), std::end(m_UniqueTargetInfo), [&](TargetInfo const& targetInfo) { return targetInfo.TargetGUID == targetGUID && targetInfo.MissCondition != SPELL_MISS_NONE; });
                if (ihit != std::end(m_UniqueTargetInfo))
                {
                    hit = false;
                    //lower spell cost on fail (by talent aura)
                    if (Player* modOwner = unitCaster->ToPlayer()->GetSpellModOwner())
                        modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_SPELL_COST_REFUND_ON_FAIL, m_powerCost);
                }
            }
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
        unitCaster->ModifyHealth(-(int32)m_powerCost);
        return;
    }

    if (powerType >= MAX_POWERS)
    {
        TC_LOG_ERROR("spells", "Spell::TakePower: Unknown power type '{}'", powerType);
        return;
    }

    unitCaster->ModifyPower(powerType, -m_powerCost);

    // Set the five second timer
    if (powerType == POWER_MANA && m_powerCost > 0)
        unitCaster->SetLastManaUse(GameTime::GetGameTimeMS());
}

void Spell::TakeAmmo()
{
    // Only players use ammo
    Player* player = m_caster->ToPlayer();
    if (!player)
        return;

    // only ranged
    if (m_attackType != RANGED_ATTACK)
        return;

    // wands don't have ammo
    Item* item = player->GetWeaponForAttack(RANGED_ATTACK);
    if (!item || item->IsBroken() || item->GetTemplate()->SubClass == ITEM_SUBCLASS_WEAPON_WAND)
        return;

    if (item->GetTemplate()->InventoryType == INVTYPE_THROWN)
    {
        if (item->GetMaxStackCount() == 1)
        {
            // decrease durability for non-stackable throw weapon
            player->DurabilityPointLossForEquipSlot(EQUIPMENT_SLOT_RANGED);
        }
        else
        {
            // decrease items amount for stackable throw weapon
            uint32 count = 1;
            player->DestroyItemCount(item, count, true);
        }
    }
    else if (uint32 ammo = player->GetUInt32Value(PLAYER_AMMO_ID))
        player->DestroyItemCount(ammo, 1, true);
}

SpellCastResult Spell::CheckRuneCost(uint32 runeCostID) const
{
    if (m_spellInfo->PowerType != POWER_RUNE || !runeCostID)
        return SPELL_CAST_OK;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return SPELL_CAST_OK;

    if (player->GetClass() != CLASS_DEATH_KNIGHT)
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
            modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_COST, runeCost[i], const_cast<Spell*>(this));
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

void Spell::TakeRunePower(bool didHit)
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER || m_caster->ToPlayer()->GetClass() != CLASS_DEATH_KNIGHT)
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
            player->SetRuneCooldown(i, didHit ? player->GetRuneBaseCooldown(i) : uint32(RUNE_MISS_COOLDOWN), true);
            player->SetLastUsedRune(rune);
            runeCost[rune]--;
        }
    }

    // Find a Death rune where the base rune matches the one we need
    runeCost[RUNE_DEATH] = runeCost[RUNE_BLOOD] + runeCost[RUNE_UNHOLY] + runeCost[RUNE_FROST];
    if (runeCost[RUNE_DEATH] > 0)
    {
        for (uint32 i = 0; i < MAX_RUNES; ++i)
        {
            RuneType rune = player->GetCurrentRune(i);
            RuneType baseRune = player->GetBaseRune(i);
            if (!player->GetRuneCooldown(i) && rune == RUNE_DEATH && runeCost[baseRune] > 0)
            {
                player->SetRuneCooldown(i, didHit ? player->GetRuneBaseCooldown(i) : uint32(RUNE_MISS_COOLDOWN), true);
                player->SetLastUsedRune(rune);
                runeCost[baseRune]--;
                runeCost[rune]--;

                // keep Death Rune type if missed
                if (didHit)
                    player->RestoreBaseRune(i);

                if (runeCost[RUNE_DEATH] == 0)
                    break;
            }
        }
    }

    // Grab any Death rune
    if (runeCost[RUNE_DEATH] > 0)
    {
        for (uint32 i = 0; i < MAX_RUNES; ++i)
        {
            RuneType rune = player->GetCurrentRune(i);
            if (!player->GetRuneCooldown(i) && rune == RUNE_DEATH)
            {
                player->SetRuneCooldown(i, didHit ? player->GetRuneBaseCooldown(i) : uint32(RUNE_MISS_COOLDOWN), true);
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
        if (int32 rp = int32(runeCostData->RunicPower * sWorld->getRate(RATE_POWER_RUNICPOWER_INCOME)))
            player->ModifyPower(POWER_RUNIC_POWER, int32(rp));
}

void Spell::TakeReagents()
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    ItemTemplate const* castItemTemplate = m_CastItem ? m_CastItem->GetTemplate() : nullptr;

    // do not take reagents for these item casts
    if (castItemTemplate && castItemTemplate->HasFlag(ITEM_FLAG_NO_REAGENT_COST))
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
                int32 charges = ASSERT_NOTNULL(m_CastItem)->GetSpellCharges(s);
                if (castItemTemplate->Spells[s].SpellCharges < 0 && abs(charges) < 2)
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

    if (!m_spellInfo->HasInitialAggro())
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
    TC_LOG_DEBUG("spells", "Spell {}, added an additional {} threat for {} {} target(s)", m_spellInfo->Id, threat, IsPositive() ? "assisting" : "harming", uint32(m_UniqueTargetInfo.size()));
}

void Spell::HandleEffects(Unit* pUnitTarget, Item* pItemTarget, GameObject* pGoTarget, Corpse* pCorpseTarget, SpellEffectInfo const& spellEffectInfo, SpellEffectHandleMode mode)
{
    effectHandleMode = mode;
    unitTarget = pUnitTarget;
    itemTarget = pItemTarget;
    gameObjTarget = pGoTarget;
    m_corpseTarget = pCorpseTarget;
    destTarget = &m_destTargets[spellEffectInfo.EffectIndex]._position;
    effectInfo = &spellEffectInfo;

    // we do not need DamageMultiplier here.
    damage = CalculateDamage(spellEffectInfo);

    bool preventDefault = CallScriptEffectHandlers(spellEffectInfo.EffectIndex, mode);

    if (!preventDefault)
        (this->*SpellEffectHandlers[spellEffectInfo.Effect])();
}

SpellCastResult Spell::CheckCast(bool strict, uint32* param1 /*= nullptr*/, uint32* param2 /*= nullptr*/)
{
    // check death state
    if (m_caster->ToUnit() && !m_caster->ToUnit()->IsAlive() && !m_spellInfo->IsPassive() && !(m_spellInfo->HasAttribute(SPELL_ATTR0_CASTABLE_WHILE_DEAD) || (IsTriggered() && !m_triggeredByAuraSpell)))
        return SPELL_FAILED_CASTER_DEAD;

    // Prevent cheating in case the player has an immunity effect and tries to interact with a non-allowed gameobject. The error message is handled by the client so we don't report anything here
    if (m_caster->ToPlayer() && m_targets.GetGOTarget())
    {
        if (m_targets.GetGOTarget()->GetGOInfo()->CannotBeUsedUnderImmunity() && m_caster->ToUnit()->HasUnitFlag(UNIT_FLAG_IMMUNE))
            return SPELL_FAILED_DONT_REPORT;
    }

    // check cooldowns to prevent cheating
    if (!m_spellInfo->IsPassive())
    {
        if (m_caster->GetTypeId() == TYPEID_PLAYER)
        {
            //can cast triggered (by aura only?) spells while have this flag
            if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CASTER_AURASTATE) && m_caster->ToPlayer()->HasFlag(PLAYER_FLAGS, PLAYER_ALLOW_ONLY_ABILITY))
                return SPELL_FAILED_SPELL_IN_PROGRESS;

            // check if we are using a potion in combat for the 2nd+ time. Cooldown is added only after caster gets out of combat
            if (!IsIgnoringCooldowns() && m_caster->ToPlayer()->GetLastPotionId() && m_CastItem && (m_CastItem->IsPotion() || m_spellInfo->IsCooldownStartedOnEvent()))
                return SPELL_FAILED_NOT_READY;
        }

        if (m_caster->ToUnit() && !m_caster->ToUnit()->GetSpellHistory()->IsReady(m_spellInfo, m_castItemEntry, IsIgnoringCooldowns()))
        {
            if (m_triggeredByAuraSpell || m_spellInfo->IsCooldownStartedOnEvent())
                return SPELL_FAILED_DONT_REPORT;
            else
                return SPELL_FAILED_NOT_READY;
        }
    }

    if (m_spellInfo->HasAttribute(SPELL_ATTR7_IS_CHEAT_SPELL) && m_caster->IsUnit() && !m_caster->ToUnit()->HasUnitFlag2(UNIT_FLAG2_ALLOW_CHEAT_SPELLS))
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
            !m_caster->IsOutdoors())
            return SPELL_FAILED_ONLY_OUTDOORS;

        if (m_spellInfo->HasAttribute(SPELL_ATTR0_INDOORS_ONLY) &&
            m_caster->IsOutdoors())
            return SPELL_FAILED_ONLY_INDOORS;
    }

    if (Unit* unitCaster = m_caster->ToUnit())
    {
        // only check at first call, Stealth auras are already removed at second call
        // for now, ignore triggered spells
        if (strict && !(_triggeredCastFlags & TRIGGERED_IGNORE_SHAPESHIFT))
        {
            bool checkForm = true;
            // Ignore form req aura
            Unit::AuraEffectList const& ignore = unitCaster->GetAuraEffectsByType(SPELL_AURA_MOD_IGNORE_SHAPESHIFT);
            for (AuraEffect const* aurEff : ignore)
            {
                if (!aurEff->IsAffectedOnSpell(m_spellInfo))
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

        if (unitCaster->HasAuraTypeWithMiscvalue(SPELL_AURA_BLOCK_SPELL_FAMILY, m_spellInfo->SpellFamilyName))
            return SPELL_FAILED_SPELL_UNAVAILABLE;

        bool reqCombat = true;
        Unit::AuraEffectList const& stateAuras = unitCaster->GetAuraEffectsByType(SPELL_AURA_ABILITY_IGNORE_AURASTATE);
        for (Unit::AuraEffectList::const_iterator j = stateAuras.begin(); j != stateAuras.end(); ++j)
        {
            if ((*j)->IsAffectedOnSpell(m_spellInfo))
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

        // cancel autorepeat spells if cast start when moving
        // (not wand currently autorepeat cast delayed to moving stop anyway in spell update code)
        if (unitCaster->GetTypeId() == TYPEID_PLAYER && unitCaster->ToPlayer()->isMoving() && (!unitCaster->IsCharmed() || !unitCaster->GetCharmerGUID().IsCreature()))
        {
            // skip stuck spell to allow use it in falling case and apply spell limitations at movement
            if ((!unitCaster->HasUnitMovementFlag(MOVEMENTFLAG_FALLING_FAR) || !m_spellInfo->HasEffect(SPELL_EFFECT_STUCK)) &&
                (IsAutoRepeat() || (m_spellInfo->AuraInterruptFlags & AURA_INTERRUPT_FLAG_NOT_SEATED) != 0))
                return SPELL_FAILED_MOVING;
        }

        if (unitCaster->IsCharmed() && m_spellInfo->HasAttribute(SPELL_ATTR5_NOT_USABLE_WHILE_CHARMED))
            return SPELL_FAILED_CHARMED;

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

                if (!m_spellInfo->HasAttribute(SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS) && !m_spellInfo->HasAttribute(SPELL_ATTR5_SKIP_CHECKCAST_LOS_CHECK) && !DisableMgr::IsDisabledFor(DISABLE_TYPE_SPELL, m_spellInfo->Id, nullptr, SPELL_DISABLE_LOS) && !target->IsWithinLOSInMap(losTarget, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
                    return SPELL_FAILED_LINE_OF_SIGHT;
            }
        }
    }

    // Check for line of sight for spells with dest
    if (m_targets.HasDst())
    {
        float x, y, z;
        m_targets.GetDstPos()->GetPosition(x, y, z);

        if (!m_spellInfo->HasAttribute(SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS) && !m_spellInfo->HasAttribute(SPELL_ATTR5_SKIP_CHECKCAST_LOS_CHECK) && !DisableMgr::IsDisabledFor(DISABLE_TYPE_SPELL, m_spellInfo->Id, nullptr, SPELL_DISABLE_LOS) && !m_caster->IsWithinLOS(x, y, z, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
            return SPELL_FAILED_LINE_OF_SIGHT;
    }

    // check pet presence
    if (Unit* unitCaster = m_caster->ToUnit())
    {
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

    // Spell cast only in battleground
    if (m_spellInfo->HasAttribute(SPELL_ATTR3_BATTLEGROUND) && m_caster->GetTypeId() == TYPEID_PLAYER)
        if (!m_caster->ToPlayer()->InBattleground())
            return SPELL_FAILED_ONLY_BATTLEGROUNDS;

    // do not allow spells to be cast in arenas
    // - with greater than 10 min CD without SPELL_ATTR4_USABLE_IN_ARENA flag
    // - with SPELL_ATTR4_NOT_USABLE_IN_ARENA flag
    if (m_spellInfo->HasAttribute(SPELL_ATTR4_NOT_USABLE_IN_ARENA) ||
        (m_spellInfo->GetRecoveryTime() > 10 * MINUTE * IN_MILLISECONDS && !m_spellInfo->HasAttribute(SPELL_ATTR4_USABLE_IN_ARENA)))
        if (MapEntry const* mapEntry = sMapStore.LookupEntry(m_caster->GetMapId()))
            if (mapEntry->IsBattleArena())
                return SPELL_FAILED_NOT_IN_ARENA;

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
        if (m_caster->GetTypeId() == TYPEID_PLAYER && m_caster->ToPlayer()->IsMounted() && !m_spellInfo->IsPassive() && !m_spellInfo->HasAttribute(SPELL_ATTR0_CASTABLE_WHILE_MOUNTED))
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

    bool hasDispellableAura = false;
    bool hasNonDispelEffect = false;
    uint32 dispelMask = 0;
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
    {
        if (spellEffectInfo.Effect == SPELL_EFFECT_DISPEL)
        {
            if (spellEffectInfo.IsTargetingArea() || m_spellInfo->HasAttribute(SPELL_ATTR1_MELEE_COMBAT_START))
            {
                hasDispellableAura = true;
                break;
            }

            dispelMask |= SpellInfo::GetDispelMask(DispelType(spellEffectInfo.MiscValue));
        }
        else if (spellEffectInfo.IsEffect())
        {
            hasNonDispelEffect = true;
            break;
        }
    }

    if (!hasNonDispelEffect && !hasDispellableAura && dispelMask && !IsTriggered())
    {
        if (Unit* target = m_targets.GetUnitTarget())
        {
            if (Unit* unitCaster = m_caster->ToUnit())
            {
                // do not allow to cast on hostile targets in sanctuary
                if (!unitCaster->IsFriendlyTo(target))
                {
                    if (unitCaster->IsInSanctuary() || target->IsInSanctuary())
                    {
                        // fix for duels
                        Player* player = unitCaster->ToPlayer();
                        if (!player || !player->duel || target != player->duel->Opponent)
                            return SPELL_FAILED_NOTHING_TO_DISPEL;
                    }
                }

                DispelChargesList dispelList;
                target->GetDispellableAuraList(unitCaster, dispelMask, dispelList);
                if (dispelList.empty())
                    return SPELL_FAILED_NOTHING_TO_DISPEL;
            }
        }
    }

    uint8 approximateAuraEffectMask = 0;
    uint8 nonAuraEffectMask = 0;
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
    {
        // for effects of spells that have only one target
        switch (spellEffectInfo.Effect)
        {
            case SPELL_EFFECT_LEARN_SPELL:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_BAD_TARGETS;

                if (spellEffectInfo.TargetA.GetTarget() != TARGET_UNIT_PET)
                    break;

                Pet* pet = m_caster->ToPlayer()->GetPet();
                if (!pet)
                    return SPELL_FAILED_NO_PET;

                SpellInfo const* learn_spellproto = sSpellMgr->GetSpellInfo(spellEffectInfo.TriggerSpell);
                if (!learn_spellproto)
                    return SPELL_FAILED_NOT_KNOWN;

                if (m_spellInfo->SpellLevel > pet->GetLevel())
                    return SPELL_FAILED_LOWLEVEL;

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

                    SpellInfo const* learn_spellproto = sSpellMgr->GetSpellInfo(spellEffectInfo.TriggerSpell);

                    if (!learn_spellproto)
                        return SPELL_FAILED_NOT_KNOWN;

                    if (m_spellInfo->SpellLevel > pet->GetLevel())
                        return SPELL_FAILED_LOWLEVEL;
                }
                break;
            }
            case SPELL_EFFECT_APPLY_GLYPH:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_BAD_TARGETS;

                uint32 glyphId = spellEffectInfo.MiscValue;
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

                if (!pet->GetCurrentFoodBenefitLevel(foodItem->GetTemplate()->ItemLevel))
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
                        if (target != m_caster && target->GetPowerType() != Powers(spellEffectInfo.MiscValue))
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
                }
                break;
            }
            case SPELL_EFFECT_SKINNING:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER || !m_targets.GetUnitTarget() || m_targets.GetUnitTarget()->GetTypeId() != TYPEID_UNIT)
                    return SPELL_FAILED_BAD_TARGETS;

                if (!m_targets.GetUnitTarget()->HasUnitFlag(UNIT_FLAG_SKINNABLE))
                    return SPELL_FAILED_TARGET_UNSKINNABLE;

                Creature* creature = m_targets.GetUnitTarget()->ToCreature();
                if (!creature->IsCritter() && !creature->loot.isLooted())
                    return SPELL_FAILED_TARGET_NOT_LOOTED;

                uint32 skill = creature->GetCreatureTemplate()->GetRequiredLootSkill();

                int32 skillValue = m_caster->ToPlayer()->GetSkillValue(skill);
                int32 TargetLevel = m_targets.GetUnitTarget()->GetLevel();
                int32 ReqValue = (skillValue < 100 ? (TargetLevel-10) * 10 : TargetLevel * 5);
                if (ReqValue > skillValue)
                    return SPELL_FAILED_LOW_CASTLEVEL;

                break;
            }
            case SPELL_EFFECT_OPEN_LOCK:
            {
                if (spellEffectInfo.TargetA.GetTarget() != TARGET_GAMEOBJECT_TARGET &&
                    spellEffectInfo.TargetA.GetTarget() != TARGET_GAMEOBJECT_ITEM_TARGET)
                    break;

                if (m_caster->GetTypeId() != TYPEID_PLAYER  // only players can open locks, gather etc.
                    // we need a go target in case of TARGET_GAMEOBJECT_TARGET
                    || (spellEffectInfo.TargetA.GetTarget() == TARGET_GAMEOBJECT_TARGET && !m_targets.GetGOTarget()))
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
                if (spellEffectInfo.TargetA.GetTarget() == TARGET_GAMEOBJECT_ITEM_TARGET &&
                    !m_targets.GetGOTarget() &&
                    (!pTempItem || !pTempItem->GetTemplate()->LockID || !pTempItem->IsLocked()))
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
                    lockId = itm->GetTemplate()->LockID;

                SkillType skillId = SKILL_NONE;
                int32 reqSkillValue = 0;
                int32 skillValue = 0;

                // check lock compatibility
                SpellCastResult res = CanOpenLock(spellEffectInfo, lockId, skillId, reqSkillValue, skillValue);
                if (res != SPELL_CAST_OK)
                    return res;

                // chance for fail at lockpicking attempt
                // second check prevent fail at rechecks
                // herbalism and mining cannot fail as of patch 3.1.0
                if (skillId != SKILL_NONE && skillId != SKILL_HERBALISM && skillId != SKILL_MINING && (!m_selfContainer || ((*m_selfContainer) != this)))
                {
                    bool canFailAtMax = skillId == SKILL_LOCKPICKING;

                    // chance for failure in orange lockpick
                    if ((canFailAtMax || skillValue < sWorld->GetConfigMaxSkillValue()) && reqSkillValue > irand(skillValue - 25, skillValue + 37))
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

                SummonPropertiesEntry const* SummonProperties = sSummonPropertiesStore.LookupEntry(spellEffectInfo.MiscValueB);
                if (!SummonProperties)
                    break;

                switch (SummonProperties->Control)
                {
                    case SUMMON_CATEGORY_PET:
                        if (!m_spellInfo->HasAttribute(SPELL_ATTR1_DISMISS_PET) && unitCaster->GetPetGUID())
                            return SPELL_FAILED_ALREADY_HAVE_SUMMON;
                        [[fallthrough]]; // check both GetPetGUID() and GetCharmGUID for SUMMON_CATEGORY_PET
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
                    if (!m_spellInfo->HasAttribute(SPELL_ATTR1_DISMISS_PET) && m_targets.GetUnitTarget()->GetPetGUID())
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
                                pet->CastSpell(pet, 32752, pet->GetGUID());
                    }
                    else if (!m_spellInfo->HasAttribute(SPELL_ATTR1_DISMISS_PET))
                        return SPELL_FAILED_ALREADY_HAVE_SUMMON;
                }

                if (unitCaster->GetCharmedGUID())
                    return SPELL_FAILED_ALREADY_HAVE_CHARM;

                Player* playerCaster = unitCaster->ToPlayer();
                if (playerCaster && playerCaster->GetPetStable())
                {
                    std::pair<PetStable::PetInfo const*, PetSaveMode> info = Pet::GetLoadPetInfo(*playerCaster->GetPetStable(), spellEffectInfo.MiscValue, 0, false);
                    if (info.first)
                    {
                        if (info.first->Type == HUNTER_PET)
                        {
                            if (!info.first->Health)
                            {
                                playerCaster->SendTameFailure(PETTAME_DEAD);
                                return SPELL_FAILED_DONT_REPORT;
                            }

                            CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(info.first->CreatureId);
                            if (!creatureInfo || !creatureInfo->IsTameable(playerCaster->CanTameExoticPets()))
                            {
                                // if problem in exotic pet
                                if (creatureInfo && creatureInfo->IsTameable(true))
                                    playerCaster->SendTameFailure(PETTAME_CANTCONTROLEXOTIC);
                                else
                                    playerCaster->SendTameFailure(PETTAME_NOPETAVAILABLE);

                                return SPELL_FAILED_DONT_REPORT;
                            }
                        }
                    }
                    else if (!spellEffectInfo.MiscValue) // when miscvalue is present it is allowed to create new pets
                    {
                        playerCaster->SendTameFailure(PETTAME_NOPETAVAILABLE);
                        return SPELL_FAILED_DONT_REPORT;
                    }
                }

                break;
            }
            case SPELL_EFFECT_SUMMON_PLAYER:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_BAD_TARGETS;

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
                if (!m_targets.GetUnitTarget() || m_targets.GetUnitTarget() == m_caster)
                    return SPELL_FAILED_BAD_TARGETS;

                dispelMask = SpellInfo::GetDispelMask(DispelType(spellEffectInfo.MiscValue));
                bool hasStealableAura = false;
                Unit::VisibleAuraMap const& visibleAuras = m_targets.GetUnitTarget()->GetVisibleAuras();
                for (Unit::VisibleAuraMap::const_iterator itr = visibleAuras.begin(); itr != visibleAuras.end(); ++itr)
                {
                    if (!itr->second->IsPositive())
                        continue;

                    Aura const* aura = itr->second->GetBase();
                    if (!(aura->GetSpellInfo()->GetDispelMask() & dispelMask))
                        continue;

                    if (aura->IsPassive() || aura->GetSpellInfo()->HasAttribute(SPELL_ATTR4_NOT_STEALABLE))
                        continue;

                    hasStealableAura = true;
                    break;
                }

                if (!hasStealableAura)
                    return SPELL_FAILED_NOTHING_TO_STEAL;

                break;
            }
            case SPELL_EFFECT_LEAP_BACK:
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
                }
                break;
            }
            case SPELL_EFFECT_JUMP:
            case SPELL_EFFECT_JUMP_DEST:
            {
                Unit* unitCaster = m_caster->ToUnit();
                if (!unitCaster)
                    return SPELL_FAILED_BAD_TARGETS;

                if (unitCaster->HasUnitState(UNIT_STATE_ROOT))
                    return SPELL_FAILED_ROOTED;
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

        if (spellEffectInfo.IsAura())
            approximateAuraEffectMask |= 1 << spellEffectInfo.EffectIndex;
        else if (spellEffectInfo.IsEffect())
            nonAuraEffectMask |= 1 << spellEffectInfo.EffectIndex;
    }

    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
    {
        switch (spellEffectInfo.ApplyAuraName)
        {
            case SPELL_AURA_MOD_POSSESS_PET:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_NO_PET;

                Pet* pet = m_caster->ToPlayer()->GetPet();
                if (!pet)
                    return SPELL_FAILED_NO_PET;

                if (pet->GetCharmerGUID())
                    return SPELL_FAILED_ALREADY_HAVE_CHARM;
                break;
            }
            case SPELL_AURA_MOD_POSSESS:
            case SPELL_AURA_MOD_CHARM:
            case SPELL_AURA_AOE_CHARM:
            {
                Unit* unitCaster = (m_originalCaster ? m_originalCaster : m_caster->ToUnit());
                if (!unitCaster)
                    return SPELL_FAILED_BAD_TARGETS;

                if (unitCaster->GetCharmerGUID())
                    return SPELL_FAILED_CHARMED;

                if (spellEffectInfo.ApplyAuraName == SPELL_AURA_MOD_CHARM
                    || spellEffectInfo.ApplyAuraName == SPELL_AURA_MOD_POSSESS)
                {
                    if (!m_spellInfo->HasAttribute(SPELL_ATTR1_DISMISS_PET) && unitCaster->GetPetGUID())
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
                        return SPELL_FAILED_CANT_BE_CHARMED;

                    if (target->GetOwner() && target->GetOwner()->GetTypeId() == TYPEID_PLAYER)
                        return SPELL_FAILED_TARGET_IS_PLAYER_CONTROLLED;

                    int32 value = CalculateDamage(spellEffectInfo);
                    if (value && int32(target->GetLevel()) > value)
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

                // Ignore map check if spell have AreaId. AreaId already checked and this prevent special mount spells
                bool allowMount = !unitCaster->GetMap()->IsDungeon() || unitCaster->GetMap()->IsBattlegroundOrArena();
                InstanceTemplate const* it = sObjectMgr->GetInstanceTemplate(unitCaster->GetMapId());
                if (it)
                    allowMount = it->AllowMount;
                if (unitCaster->GetTypeId() == TYPEID_PLAYER && !allowMount && !m_spellInfo->AreaGroupId)
                    return SPELL_FAILED_NO_MOUNTS_ALLOWED;

                if (unitCaster->IsInDisallowedMountForm())
                {
                    SendMountResult(MountResult::Shapeshifted); // mount result gets sent before the cast result
                    return SPELL_FAILED_DONT_REPORT;
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
                    Battlefield* Bf = sBattlefieldMgr->GetBattlefieldToZoneId(m_originalCaster->GetZoneId());
                    if (AreaTableEntry const* area = sAreaTableStore.LookupEntry(m_originalCaster->GetAreaId()))
                        if (area->Flags & AREA_FLAG_NO_FLY_ZONE  || (Bf && !Bf->CanFlyIn()))
                            return SPELL_FAILED_NOT_HERE;
                }
                break;
            }
            case SPELL_AURA_PERIODIC_MANA_LEECH:
            {
                if (spellEffectInfo.IsTargetingArea())
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

        // check if target already has the same type, but more powerful aura
        if (!nonAuraEffectMask && (approximateAuraEffectMask & (1 << spellEffectInfo.EffectIndex)) && !m_spellInfo->IsTargetingArea())
            if (Unit* target = m_targets.GetUnitTarget())
                if (!target->IsHighestExclusiveAuraEffect(m_spellInfo, AuraType(spellEffectInfo.ApplyAuraName),
                    spellEffectInfo.CalcValue(m_caster, &m_spellValue->EffectBasePoints[spellEffectInfo.EffectIndex]), approximateAuraEffectMask, false))
                    return SPELL_FAILED_AURA_BOUNCED;
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

        // Item target guid contains trade slot until m_targets.UpdateTradeSlotItem() is called
        TradeSlots slot = TradeSlots(m_targets.GetItemTargetGUID().GetRawValue());
        if (slot != TRADE_SLOT_NONTRADED)
            return SPELL_FAILED_BAD_TARGETS;

        if (!IsTriggered())
            if (my_trade->GetSpell())
                return SPELL_FAILED_ITEM_ALREADY_ENCHANTED;
    }

    // check if caster has at least 1 combo point on target for spells that require combo points
    if (m_needComboPoints)
    {
        if (Unit* unitCaster = m_caster->ToUnit())
        {
            if (m_spellInfo->NeedsExplicitUnitTarget())
            {
                if (!unitCaster->GetComboPoints(m_targets.GetUnitTarget()))
                    return SPELL_FAILED_NO_COMBO_POINTS;
            }
            else
            {
                if (!unitCaster->GetComboPoints())
                    return SPELL_FAILED_NO_COMBO_POINTS;
            }
        }
    }

    // all ok
    return SPELL_CAST_OK;
}

SpellCastResult Spell::CheckPetCast(Unit* target)
{
    Unit* unitCaster = m_caster->ToUnit();
    if (unitCaster && unitCaster->HasUnitState(UNIT_STATE_CASTING) && !(_triggeredCastFlags & TRIGGERED_IGNORE_CAST_IN_PROGRESS))              //prevent spellcast interruption by another spellcast
        return SPELL_FAILED_SPELL_IN_PROGRESS;

    // dead owner (pets still alive when owners ressed?)
    if (Unit* owner = m_caster->GetCharmerOrOwner())
        if (!owner->IsAlive() && !owner->IsGhouled())
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
    m_powerCost = m_spellInfo->CalcPowerCost(m_caster, m_spellSchoolMask);
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

    // spells totally immuned to caster auras (wsg flag drop, give marks etc)
    if (m_spellInfo->HasAttribute(SPELL_ATTR6_IGNORE_CASTER_AURAS))
        return SPELL_CAST_OK;

    // these attributes only show the spell as usable on the client when it has related aura applied
    // still they need to be checked against certain mechanics

    // SPELL_ATTR5_USABLE_WHILE_STUNNED by default only MECHANIC_STUN (ie no sleep, knockout, freeze, etc.)
    bool usableWhileStunned = m_spellInfo->HasAttribute(SPELL_ATTR5_USABLE_WHILE_STUNNED);

    // SPELL_ATTR5_USABLE_WHILE_FEARED by default only fear (ie no horror)
    bool usableWhileFeared = m_spellInfo->HasAttribute(SPELL_ATTR5_USABLE_WHILE_FEARED);

    // SPELL_ATTR5_USABLE_WHILE_CONFUSED by default only disorient (ie no polymorph)
    bool usableWhileConfused = m_spellInfo->HasAttribute(SPELL_ATTR5_USABLE_WHILE_CONFUSED);

    // Glyph of Pain Suppression
    // there is no other way to handle it
    if (m_spellInfo->Id == 33206 && !unitCaster->HasAura(63248))
        usableWhileStunned = false;

    // Check whether the cast should be prevented by any state you might have.
    SpellCastResult result = SPELL_CAST_OK;

    // Get unit state
    uint32 const unitflag = unitCaster->GetUnitFlags();

    if (m_fromClient && unitCaster->IsCharmed() && unitCaster->IsPlayer() && !CheckSpellCancelsCharm(param1))
        result = SPELL_FAILED_CHARMED;

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
                    *param1 = aurEff->GetSpellEffectInfo().Mechanic;
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
        if (m_spellInfo->SpellCancelsAuraEffect(aurEff))
            continue;

        if (param1)
        {
            *param1 = aurEff->GetSpellEffectInfo().Mechanic;
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

int32 Spell::CalculateDamage(SpellEffectInfo const& spellEffectInfo) const
{
    return m_caster->CalculateSpellDamage(spellEffectInfo, m_spellValue->EffectBasePoints + spellEffectInfo.EffectIndex);
}

bool Spell::CanAutoCast(Unit* target)
{
    if (!target)
        return (CheckPetCast(target) == SPELL_CAST_OK);

    ObjectGuid targetguid = target->GetGUID();

    // check if target already has the same or a more powerful aura
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
    {
        if (!spellEffectInfo.IsAura())
            continue;

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

        if (minRange > 0.0f && m_caster->GetExactDistSq(target) < minRange)
            return SPELL_FAILED_OUT_OF_RANGE;

        if (m_caster->GetTypeId() == TYPEID_PLAYER &&
            (m_spellInfo->FacingCasterFlags & SPELL_FACING_FLAG_INFRONT) && !m_caster->HasInArc(static_cast<float>(M_PI), target))
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

    if (m_spellInfo->HasAttribute(SPELL_ATTR0_REQ_AMMO) && m_caster->GetTypeId() == TYPEID_PLAYER)
        if (Item* ranged = m_caster->ToPlayer()->GetWeaponForAttack(RANGED_ATTACK, true))
            maxRange *= ranged->GetTemplate()->RangedModRange * 0.01f;

    if (Player* modOwner = m_caster->GetSpellModOwner())
        modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RANGE, maxRange, const_cast<Spell*>(this));

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
        if (int32(unitCaster->GetHealth()) <= m_powerCost)
            return SPELL_FAILED_CASTER_AURASTATE;
        return SPELL_CAST_OK;
    }
    // Check valid power type
    if (m_spellInfo->PowerType >= MAX_POWERS)
    {
        TC_LOG_ERROR("spells", "Spell::CheckPower: Unknown power type '{}'", m_spellInfo->PowerType);
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
    Powers powerType = m_spellInfo->PowerType;
    if (int32(unitCaster->GetPower(powerType)) < m_powerCost)
        return SPELL_FAILED_NO_POWER;
    else
        return SPELL_CAST_OK;
}

SpellCastResult Spell::CheckItems(uint32* param1 /*= nullptr*/, uint32* param2 /*= nullptr*/) const
{
    Player* player = m_caster->ToPlayer();
    if (!player)
        return SPELL_CAST_OK;

    if (!m_CastItem)
    {
        if (m_castItemGUID)
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

        for (uint8 i = 0; i < MAX_ITEM_PROTO_SPELLS; ++i)
            if (proto->Spells[i].SpellCharges)
                if (m_CastItem->GetSpellCharges(i) == 0)
                    return SPELL_FAILED_NO_CHARGES_REMAIN;

        // consumable cast item checks
        if (proto->Class == ITEM_CLASS_CONSUMABLE && m_targets.GetUnitTarget())
        {
            // such items should only fail if there is no suitable effect at all - see Rejuvenation Potions for example
            SpellCastResult failReason = SPELL_CAST_OK;
            for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
            {
                // skip check, pet not required like checks, and for TARGET_UNIT_PET m_targets.GetUnitTarget() is not the real target but the caster
                if (spellEffectInfo.TargetA.GetTarget() == TARGET_UNIT_PET)
                    continue;

                if (spellEffectInfo.IsEffect(SPELL_EFFECT_HEAL))
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
                if (spellEffectInfo.IsEffect(SPELL_EFFECT_ENERGIZE))
                {
                    if (spellEffectInfo.MiscValue < 0 || spellEffectInfo.MiscValue >= int8(MAX_POWERS))
                    {
                        failReason = SPELL_FAILED_ALREADY_AT_FULL_POWER;
                        continue;
                    }

                    Powers power = Powers(spellEffectInfo.MiscValue);
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
    if (!(m_CastItem && m_CastItem->GetTemplate()->HasFlag(ITEM_FLAG_NO_REAGENT_COST)))
    {
        bool checkReagents = !(_triggeredCastFlags & TRIGGERED_IGNORE_POWER_AND_REAGENT_COST) && !player->CanNoReagentCast(m_spellInfo);
        // Not own traded item (in trader trade slot) requires reagents even if triggered spell
        if (!checkReagents)
            if (Item* targetItem = m_targets.GetItemTarget())
                if (targetItem->GetOwnerGUID() != player->GetGUID())
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
                    for (uint8 s = 0; s < MAX_ITEM_PROTO_SPELLS; ++s)
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
            return SPELL_FAILED_TOTEMS;                         //0x7C

        // Check items for TotemCategory  (items presence in inventory)
        uint32 TotemCategory = 2;
        for (uint8 i = 0; i < 2; ++i)
        {
            if (m_spellInfo->TotemCategory[i] != 0)
            {
                if (player->HasItemTotemCategory(m_spellInfo->TotemCategory[i]))
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
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
    {
        switch (spellEffectInfo.Effect)
        {
            case SPELL_EFFECT_CREATE_ITEM:
            case SPELL_EFFECT_CREATE_ITEM_2:
            {
                // m_targets.GetUnitTarget() means explicit cast, otherwise we dont check for possible equip error
                Unit* target = m_targets.GetUnitTarget() ? m_targets.GetUnitTarget() : player;
                if (target->GetTypeId() == TYPEID_PLAYER && !IsTriggered())
                {
                    // SPELL_EFFECT_CREATE_ITEM_2 differs from SPELL_EFFECT_CREATE_ITEM in that it picks the random item to create from a pool of potential items,
                    // so we need to make sure there is at least one free space in the player's inventory
                    if (spellEffectInfo.IsEffect(SPELL_EFFECT_CREATE_ITEM_2))
                        if (target->ToPlayer()->GetFreeInventorySpace() == 0)
                        {
                            player->SendEquipError(EQUIP_ERR_INVENTORY_FULL, nullptr, nullptr, spellEffectInfo.ItemType);
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
                            if (!itemTemplate->ItemLimitCategory)
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
                                else
                                    player->CastSpell(player, m_spellInfo->GetEffect(EFFECT_1).CalcValue(), false);        // move this to anywhere
                                return SPELL_FAILED_DONT_REPORT;
                            }
                        }
                    }
                }
                break;
            }
            case SPELL_EFFECT_ENCHANT_ITEM:
                if (spellEffectInfo.ItemType && m_targets.GetItemTarget()
                    && (m_targets.GetItemTarget()->IsWeaponVellum() || m_targets.GetItemTarget()->IsArmorVellum()))
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
                if (targetItem->GetTemplate()->ItemLevel < m_spellInfo->BaseLevel || (targetItem->GetTemplate()->RequiredLevel && targetItem->GetTemplate()->RequiredLevel < m_spellInfo->BaseLevel))
                    return SPELL_FAILED_LOWLEVEL;

                bool isItemUsable = false;
                for (uint8 e = 0; e < MAX_ITEM_PROTO_SPELLS; ++e)
                {
                    ItemTemplate const* proto = targetItem->GetTemplate();
                    if (proto->Spells[e].SpellId > 0 && (
                        proto->Spells[e].SpellTrigger == ITEM_SPELLTRIGGER_ON_USE ||
                        proto->Spells[e].SpellTrigger == ITEM_SPELLTRIGGER_ON_NO_DELAY_USE))
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
                                    if (targetItem->GetTemplate()->Socket[socket].Color)
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
                if (item->GetOwner() != player)
                {
                    uint32 enchant_id = spellEffectInfo.MiscValue;
                    SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
                    if (!pEnchant)
                        return SPELL_FAILED_ERROR;
                    if (pEnchant->Flags & ENCHANTMENT_CAN_SOULBOUND)
                        return SPELL_FAILED_NOT_TRADEABLE;
                }

                // Apply item level restriction if the enchanting spell has max level restrition set
                if (m_CastItem && m_spellInfo->MaxLevel > 0)
                {
                    if (item->GetTemplate()->ItemLevel < m_CastItem->GetTemplate()->RequiredLevel)
                        return SPELL_FAILED_LOWLEVEL;
                    if (item->GetTemplate()->ItemLevel > m_spellInfo->MaxLevel)
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

                uint32 item_quality = itemProto->Quality;
                // 2.0.x addon: Check player enchanting level against the item disenchanting requirements
                uint32 item_disenchantskilllevel = itemProto->RequiredDisenchantSkill;
                if (item_disenchantskilllevel == uint32(-1))
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;
                if (item_disenchantskilllevel > player->GetSkillValue(SKILL_ENCHANTING))
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
                uint32 item_prospectingskilllevel = item->GetTemplate()->RequiredSkillRank;
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
                if (!item->GetTemplate()->HasFlag(ITEM_FLAG_IS_MILLABLE))
                    return SPELL_FAILED_CANT_BE_MILLED;
                //prevent milling in trade slot
                if (item->GetOwnerGUID() != player->GetGUID())
                    return SPELL_FAILED_CANT_BE_MILLED;
                //Check for enough skill in inscription
                uint32 item_millingskilllevel = item->GetTemplate()->RequiredSkillRank;
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

                switch (item->GetTemplate()->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_THROWN:
                    {
                        uint32 const ammo = item->GetEntry();
                        if (!player->HasItemCount(ammo))
                            return SPELL_FAILED_NO_AMMO;
                        break;
                    }
                    case ITEM_SUBCLASS_WEAPON_GUN:
                    case ITEM_SUBCLASS_WEAPON_BOW:
                    case ITEM_SUBCLASS_WEAPON_CROSSBOW:
                    {
                        uint32 const ammo = player->GetUInt32Value(PLAYER_AMMO_ID);
                        if (!ammo)
                        {
                            // Requires No Ammo
                            if (player->HasAura(46699))
                                break;                      // skip other checks

                            return SPELL_FAILED_NO_AMMO;
                        }

                        ItemTemplate const* ammoProto = sObjectMgr->GetItemTemplate(ammo);
                        if (!ammoProto)
                            return SPELL_FAILED_NO_AMMO;

                        if (ammoProto->Class != ITEM_CLASS_PROJECTILE)
                            return SPELL_FAILED_NO_AMMO;

                        // check ammo ws. weapon compatibility
                        switch (item->GetTemplate()->SubClass)
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

                        if (!player->HasItemCount(ammo))
                        {
                            player->SetUInt32Value(PLAYER_AMMO_ID, 0);
                            return SPELL_FAILED_NO_AMMO;
                        }
                        break;
                    }
                    case ITEM_SUBCLASS_WEAPON_WAND:
                        break;
                    default:
                        break;
                }
                break;
            }
            case SPELL_EFFECT_CREATE_MANA_GEM:
            {
                 uint32 item_id = spellEffectInfo.ItemType;
                 ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(item_id);

                 if (!pProto)
                     return SPELL_FAILED_ITEM_AT_MAX_CHARGES;

                 if (Item* pitem = player->GetItemByEntry(item_id))
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
    Player* playerCaster = m_caster->ToPlayer();
    if (!playerCaster)
        return;

    // spells not losing casting time
    if (!(m_spellInfo->InterruptFlags & SPELL_INTERRUPT_FLAG_PUSH_BACK))
        return;

    if (IsDelayableNoMore())                                 // Spells may only be delayed twice
        return;

    //check pushback reduce
    int32 delaytime = 500;                                  // spellcasting delay is normally 500ms

    int32 delayReduce = 100;                                // must be initialized to 100 for percent modifiers
    playerCaster->ApplySpellMod(m_spellInfo->Id, SPELLMOD_NOT_LOSE_CASTING_TIME, delayReduce, this);
    delayReduce += playerCaster->GetTotalAuraModifier(SPELL_AURA_REDUCE_PUSHBACK) - 100;
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

    WorldPacket data(SMSG_SPELL_DELAYED, 8+4);
    data << playerCaster->GetPackGUID();
    data << uint32(delaytime);

    playerCaster->SendMessageToSet(&data, true);
}

void Spell::DelayedChannel()
{
    Player* playerCaster = m_caster->ToPlayer();
    if (!playerCaster)
        return;

    if (m_spellState != SPELL_STATE_CASTING)
        return;

    // spells not losing channeling time
    if (!(m_spellInfo->ChannelInterruptFlags & CHANNEL_FLAG_DELAY))
        return;

    if (IsDelayableNoMore())                                    // Spells may only be delayed twice
        return;

    //check pushback reduce
    // should be affected by modifiers, not take the dbc duration.
    int32 duration = ((m_channeledDuration > 0) ? m_channeledDuration : m_spellInfo->GetDuration());

    int32 delaytime = CalculatePct(duration, 25); // channeling delay is normally 25% of its time per hit

    int32 delayReduce = 100;                                    // must be initialized to 100 for percent modifiers
    playerCaster->ApplySpellMod(m_spellInfo->Id, SPELLMOD_NOT_LOSE_CASTING_TIME, delayReduce, this);
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
    if (DynamicObject* dynObj = playerCaster->GetDynObject(m_spellInfo->Id))
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
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
    {
        SpellDestination& dest = m_destTargets[spellEffectInfo.EffectIndex];
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

bool Spell::CheckEffectTarget(Unit const* target, SpellEffectInfo const& spellEffectInfo, Position const* losPosition) const
{
    switch (spellEffectInfo.ApplyAuraName)
    {
        case SPELL_AURA_MOD_POSSESS:
        case SPELL_AURA_MOD_CHARM:
        case SPELL_AURA_MOD_POSSESS_PET:
        case SPELL_AURA_AOE_CHARM:
            if (target->GetVehicleKit() && target->GetVehicleKit()->IsControllableVehicle())
                return false;
            if (target->IsMounted())
                return false;
            if (target->GetCharmerGUID())
                return false;
            if (int32 value = CalculateDamage(spellEffectInfo))
                if ((int32)target->GetLevel() > value)
                    return false;
            break;
        default:
            break;
    }

    // check for ignore LOS on the effect itself
    if (m_spellInfo->HasAttribute(SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS) || DisableMgr::IsDisabledFor(DISABLE_TYPE_SPELL, m_spellInfo->Id, nullptr, SPELL_DISABLE_LOS))
        return true;

    // check if gameobject ignores LOS
    if (GameObject const* gobCaster = m_caster->ToGameObject())
        if (gobCaster->GetGOInfo()->IsIgnoringLOSChecks())
            return true;

    // if spell is triggered, need to check for LOS disable on the aura triggering it and inherit that behaviour
    if (IsTriggered() && m_triggeredByAuraSpell && (m_triggeredByAuraSpell->HasAttribute(SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS) || DisableMgr::IsDisabledFor(DISABLE_TYPE_SPELL, m_triggeredByAuraSpell->Id, nullptr, SPELL_DISABLE_LOS)))
        return true;

    /// @todo shit below shouldn't be here, but it's temporary
    //Check targets for LOS visibility (except spells without range limitations)
    switch (spellEffectInfo.Effect)
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
                if (target->IsWithinLOSInMap(m_caster, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2) && target->HasUnitFlag(UNIT_FLAG_SKINNABLE))
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
            if (losPosition)
                return target->IsWithinLOS(losPosition->GetPositionX(), losPosition->GetPositionY(), losPosition->GetPositionZ(), LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2);
            else
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
    return ((_triggeredCastFlags & TRIGGERED_IGNORE_SET_FACING) || (m_spellInfo->IsChanneled() && !m_spellInfo->HasAttribute(SPELL_ATTR1_CHANNEL_TRACK_TARGET)));
}

bool Spell::IsProcDisabled() const
{
    return (_triggeredCastFlags & TRIGGERED_DISALLOW_PROC_EVENTS) != 0;
}

bool Spell::IsChannelActive() const
{
    return m_caster->IsUnit() && m_caster->ToUnit()->GetChannelSpellId() != 0;
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

bool Spell::IsPositive() const
{
    return m_spellInfo->IsPositive() && (!m_triggeredByAuraSpell || m_triggeredByAuraSpell->IsPositive());
}

bool Spell::IsNeedSendToClient() const
{
    return m_spellInfo->SpellVisual[0] || m_spellInfo->SpellVisual[1] || m_spellInfo->IsChanneled() ||
        m_spellInfo->Speed > 0.0f || (!m_triggeredByAuraSpell && !IsTriggered());
}

Unit* Spell::GetUnitCasterForEffectHandlers() const
{
    return m_originalCaster ? m_originalCaster : m_caster->ToUnit();
}

SpellEvent::SpellEvent(Spell* spell) : BasicEvent(), m_Spell(spell)
{
}

SpellEvent::~SpellEvent()
{
    if (m_Spell->getState() != SPELL_STATE_FINISHED)
        m_Spell->cancel();

    if (!m_Spell->IsDeletable())
    {
        TC_LOG_ERROR("spells", "~SpellEvent: {} {} tried to delete non-deletable spell {}. Was not deleted, causes memory leak.",
            (m_Spell->GetCaster()->GetTypeId() == TYPEID_PLAYER ? "Player" : "Creature"), m_Spell->GetCaster()->GetGUID().ToString(), m_Spell->m_spellInfo->Id);
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
                        m_Spell->GetCaster()->m_Events.AddEvent(this, Milliseconds(m_Spell->GetDelayStart() + n_offset), false);
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
                m_Spell->GetCaster()->m_Events.AddEvent(this, Milliseconds(e_time + m_Spell->GetDelayMoment()), false);
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
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
    {
        // don't do anything for empty effect
        if (!spellEffectInfo.IsEffect())
            continue;

        HandleEffects(nullptr, nullptr, nullptr, nullptr, spellEffectInfo, SPELL_EFFECT_HANDLE_LAUNCH);
    }

    PrepareTargetProcessing();

    // Take ammunition if the ranged attack requires ammunition
    if (Player* player = m_caster->ToPlayer())
    {
        bool usesAmmo = m_spellInfo->HasAttribute(SPELL_ATTR0_REQ_AMMO);
        if (player->HasAuraTypeWithAffectMask(SPELL_AURA_ABILITY_CONSUME_NO_AMMO, m_spellInfo))
            usesAmmo = false;

        // Do not consume ammo for the triggered AoE ticks of Volley (Hunter spell)
        if (IsTriggered() && m_spellInfo->SpellFamilyName == SPELLFAMILY_HUNTER && m_spellInfo->IsTargetingArea())
            usesAmmo = false;

        if (usesAmmo)
            TakeAmmo();
    }

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
            critChance = m_originalCaster->SpellCritChanceDone(m_spellInfo, m_spellSchoolMask, m_attackType);
        critChance = unit->SpellCritChanceTaken(m_originalCaster, m_spellInfo, m_spellSchoolMask, critChance, m_attackType);
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
        if (spellEffectInfo.IsTargetingArea() || spellEffectInfo.IsAreaAuraEffect() || spellEffectInfo.IsEffect(SPELL_EFFECT_PERSISTENT_AREA_AURA))
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

    if (m_applyMultiplierMask & (1 << spellEffectInfo.EffectIndex))
    {
        m_damage = int32(m_damage * m_damageMultipliers[spellEffectInfo.EffectIndex]);
        m_healing = int32(m_healing * m_damageMultipliers[spellEffectInfo.EffectIndex]);

        m_damageMultipliers[spellEffectInfo.EffectIndex] *= multiplier;
    }

    targetInfo.Damage += m_damage;
    targetInfo.Healing += m_healing;
}

SpellCastResult Spell::CanOpenLock(SpellEffectInfo const& spellEffectInfo, uint32 lockId, SkillType& skillId, int32& reqSkillValue, int32& skillValue)
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
                if (uint32(spellEffectInfo.MiscValue) != lockInfo->Index[j])
                    continue;

                skillId = SkillByLockType(LockType(lockInfo->Index[j]));

                if (skillId != SKILL_NONE)
                {
                    reqSkillValue = lockInfo->Skill[j];

                    // castitem check: rogue using skeleton keys. the skill values should not be added in this case.
                    skillValue = m_CastItem || m_caster->GetTypeId() != TYPEID_PLAYER ?
                        0 : m_caster->ToPlayer()->GetSkillValue(skillId);

                    // skill bonus provided by casting spell (mostly item spells)
                    // add the effect base points modifier from the spell cast (cheat lock / skeleton key etc.)
                    if (spellEffectInfo.TargetA.GetTarget() == TARGET_GAMEOBJECT_ITEM_TARGET || spellEffectInfo.TargetB.GetTarget() == TARGET_GAMEOBJECT_ITEM_TARGET)
                        skillValue += spellEffectInfo.CalcValue();

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
            m_spellValue->EffectBasePoints[0] = m_spellInfo->GetEffect(EFFECT_0).CalcBaseValue(value);
            break;
        case SPELLVALUE_BASE_POINT1:
            m_spellValue->EffectBasePoints[1] = m_spellInfo->GetEffect(EFFECT_1).CalcBaseValue(value);
            break;
        case SPELLVALUE_BASE_POINT2:
            m_spellValue->EffectBasePoints[2] = m_spellInfo->GetEffect(EFFECT_2).CalcBaseValue(value);
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
        case SPELLVALUE_CRIT_CHANCE:
            m_spellValue->CriticalChance = value;
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
        TC_LOG_DEBUG("spells", "Spell::LoadScripts: Script `{}` for spell `{}` is loaded now", (*itr)->_GetScriptName()->c_str(), m_spellInfo->Id);
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
        (*scritr)->_InitHit();
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

bool Spell::CanExecuteTriggersOnHit(uint8 effMask, SpellInfo const* triggeredByAura) const
{
    bool only_on_caster = (triggeredByAura && triggeredByAura->HasAttribute(SPELL_ATTR4_PROC_ONLY_ON_CASTER));
    // If triggeredByAura has SPELL_ATTR4_PROC_ONLY_ON_CASTER then it can only proc on a cast spell with TARGET_UNIT_CASTER
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
    {
        if ((effMask & (1 << spellEffectInfo.EffectIndex)) && (!only_on_caster || (spellEffectInfo.TargetA.GetTarget() == TARGET_UNIT_CASTER)))
            return true;
    }
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
        if (!aurEff->IsAffectedOnSpell(m_spellInfo))
            continue;

        SpellInfo const* auraSpellInfo = aurEff->GetSpellInfo();
        if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(aurEff->GetSpellEffectInfo().TriggerSpell))
        {
            // calculate the chance using spell base amount, because aura amount is not updated on combo-points change
            // this possibly needs fixing
            int32 auraBaseAmount = aurEff->GetBaseAmount();
            // proc chance is stored in effect amount
            int32 chance = unitCaster->CalculateSpellDamage(aurEff->GetSpellEffectInfo(), &auraBaseAmount);
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
        modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_GLOBAL_COOLDOWN, gcd, this);

    // Apply haste rating
    if (m_spellInfo->StartRecoveryCategory == 133 && m_spellInfo->StartRecoveryTime == 1500 &&
        m_spellInfo->DmgClass != SPELL_DAMAGE_CLASS_MELEE && m_spellInfo->DmgClass != SPELL_DAMAGE_CLASS_RANGED &&
        !m_spellInfo->HasAttribute(SPELL_ATTR0_REQ_AMMO) && !m_spellInfo->HasAttribute(SPELL_ATTR0_ABILITY))
    {
        gcd = int32(float(gcd) * m_caster->GetFloatValue(UNIT_MOD_CAST_SPEED));
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

std::string Spell::GetDebugInfo() const
{
    std::stringstream sstr;
    sstr << std::boolalpha
        << "Id: " << GetSpellInfo()->Id << " Name: '" << GetSpellInfo()->SpellName[sWorld->GetDefaultDbcLocale()] << "' OriginalCaster: " << m_originalCasterGUID.ToString()
        << " State: " << getState();
    return sstr.str();
}

Trinity::unique_weak_ptr<Spell> Spell::GetWeakPtr() const
{
    return _spellEvent->GetSpellWeakPtr();
}

void Spell::CallScriptOnResistAbsorbCalculateHandlers(DamageInfo const& damageInfo, uint32& resistAmount, int32& absorbAmount)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(SPELL_SCRIPT_HOOK_ON_RESIST_ABSORB_CALCULATION);
        auto hookItrEnd = (*scritr)->OnCalculateResistAbsorb.end(), hookItr = (*scritr)->OnCalculateResistAbsorb.begin();
        for (; hookItr != hookItrEnd; ++hookItr)
            hookItr->Call(*scritr, damageInfo, resistAmount, absorbAmount);

        (*scritr)->_FinishScriptCall();
    }
}

namespace Trinity
{

WorldObjectSpellTargetCheck::WorldObjectSpellTargetCheck(WorldObject* caster, WorldObject* referer, SpellInfo const* spellInfo,
            SpellTargetCheckTypes selectionType, ConditionContainer const* condList) : _caster(caster), _referer(referer), _spellInfo(spellInfo),
    _targetSelectionType(selectionType), _condSrcInfo(nullptr), _condList(condList)
{
    if (condList)
        _condSrcInfo = std::make_unique<ConditionSourceInfo>(nullptr, caster);
}

WorldObjectSpellTargetCheck::~WorldObjectSpellTargetCheck()
{
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

bool WorldObjectSpellAreaTargetCheck::operator()(WorldObject* target) const
{
    if (target->ToGameObject())
    {
        // isInRange including the dimension of the GO
        bool isInRange = target->ToGameObject()->IsInRange(_position->GetPositionX(), _position->GetPositionY(), _position->GetPositionZ(), _range);
        if (!isInRange)
            return false;
    }
    else
    {
        bool isInsideCylinder = target->IsWithinDist2d(_position, _range) && std::abs(target->GetPositionZ() - _position->GetPositionZ()) <= _range;
        if (!isInsideCylinder)
            return false;
    }

    return WorldObjectSpellTargetCheck::operator ()(target);
}

WorldObjectSpellConeTargetCheck::WorldObjectSpellConeTargetCheck(float coneAngle, float range, WorldObject* caster,
    SpellInfo const* spellInfo, SpellTargetCheckTypes selectionType, ConditionContainer const* condList)
    : WorldObjectSpellAreaTargetCheck(range, caster, caster, caster, spellInfo, selectionType, condList), _coneAngle(coneAngle) { }

bool WorldObjectSpellConeTargetCheck::operator()(WorldObject* target) const
{
    if (_spellInfo->HasAttribute(SPELL_ATTR0_CU_CONE_BACK))
    {
        if (!_caster->isInBack(target, _coneAngle))
            return false;
    }
    else if (_spellInfo->HasAttribute(SPELL_ATTR0_CU_CONE_LINE))
    {
        if (!_caster->HasInLine(target, target->GetCombatReach(), _caster->GetCombatReach()))
            return false;
    }
    else
    {
        if (!_caster->isInFront(target, _coneAngle))
            return false;
    }
    return WorldObjectSpellAreaTargetCheck::operator ()(target);
}

WorldObjectSpellTrajTargetCheck::WorldObjectSpellTrajTargetCheck(float range, Position const* position, WorldObject* caster, SpellInfo const* spellInfo, SpellTargetCheckTypes selectionType, ConditionContainer const* condList)
    : WorldObjectSpellTargetCheck(caster, caster, spellInfo, selectionType, condList), _range(range), _position(position) { }

bool WorldObjectSpellTrajTargetCheck::operator()(WorldObject* target) const
{
    // return all targets on missile trajectory (0 - size of a missile)
    if (!_caster->HasInLine(target, target->GetCombatReach(), TRAJECTORY_MISSILE_SIZE))
        return false;

    if (target->GetExactDist2d(_position) > _range)
        return false;

    return WorldObjectSpellTargetCheck::operator ()(target);
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

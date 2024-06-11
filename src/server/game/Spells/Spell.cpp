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
#include "AzeriteEmpoweredItem.h"
#include "Battlefield.h"
#include "BattlefieldMgr.h"
#include "Battleground.h"
#include "BattlePetMgr.h"
#include "CellImpl.h"
#include "CharmInfo.h"
#include "CollectionMgr.h"
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
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "PathGenerator.h"
#include "Pet.h"
#include "PhasingHandler.h"
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
#include "TraitPackets.h"
#include "UniqueTrackablePtr.h"
#include "Util.h"
#include "VMapFactory.h"
#include "Vehicle.h"
#include "VMapManager2.h"
#include "World.h"
#include "WorldSession.h"
#include <numeric>
#include <sstream>

extern NonDefaultConstructible<SpellEffectHandlerFn> SpellEffectHandlers[TOTAL_SPELL_EFFECTS];

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

        pos->Relocate(spellCastRequest.Target.SrcLocation->Location.Pos);
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

        pos->Relocate(spellCastRequest.Target.DstLocation->Location.Pos);
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

SpellValue::SpellValue(SpellInfo const* proto, WorldObject const* caster)
{
    memset(EffectBasePoints, 0, sizeof(EffectBasePoints));
    for (SpellEffectInfo const& spellEffectInfo : proto->GetEffects())
        EffectBasePoints[spellEffectInfo.EffectIndex] = spellEffectInfo.CalcBaseValue(caster, nullptr, 0, -1);

    CustomBasePointsMask = 0;
    MaxAffectedTargets = proto->MaxAffectedTargets;
    RadiusMod = 1.0f;
    AuraStackAmount = 1;
    CriticalChance = 0.0f;
    DurationMul = 1;
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
    m_delayStart = 0;
    m_delayMoment = 0;
    m_delayAtDamageCount = 0;

    m_applyMultiplierMask = 0;
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
                    m_spellSchoolMask = SpellSchoolMask(1 << pItem->GetTemplate()->GetDamageType());
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

    m_spellState = SPELL_STATE_NULL;
    _triggeredCastFlags = triggerFlags;

    if (info->HasAttribute(SPELL_ATTR2_DO_NOT_REPORT_SPELL_FAILURE))
        _triggeredCastFlags |= TRIGGERED_DONT_REPORT_CAST_ERROR;

    if (info->HasAttribute(SPELL_ATTR4_ALLOW_CAST_WHILE_CASTING))
        _triggeredCastFlags |= TRIGGERED_IGNORE_CAST_IN_PROGRESS;

    m_CastItem = nullptr;
    m_castItemGUID.Clear();
    m_castItemEntry = 0;
    m_castItemLevel = -1;
    m_castFlagsEx = 0;

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
    m_procSpellType = PROC_SPELL_TYPE_NONE;
    focusObject = nullptr;
    m_castId = ObjectGuid::Create<HighGuid::Cast>(SPELL_CAST_SOURCE_NORMAL, m_caster->GetMapId(), m_spellInfo->Id, m_caster->GetMap()->GenerateLowGuid<HighGuid::Cast>());
    m_originalCastId = originalCastId;
    memset(m_misc.Raw.Data, 0, sizeof(m_misc.Raw.Data));
    m_SpellVisual.SpellXSpellVisualID = caster->GetCastSpellXSpellVisualId(m_spellInfo);
    m_triggeredByAuraSpell  = nullptr;
    m_procChainLength = caster->IsUnit() ? caster->ToUnit()->GetProcChainLength() : 0;
    _spellAura = nullptr;
    _dynObjAura = nullptr;

    //Auto Shot & Shoot (wand)
    m_autoRepeat = m_spellInfo->IsAutoRepeatRangedSpell();

    m_runesState = 0;
    m_casttime = 0;                                         // setup to correct value in Spell::prepare, must not be used before.
    m_timer = 0;                                            // will set to castime in prepare
    m_channeledDuration = 0;                                // will be setup in Spell::handle_immediate
    m_launchHandled = false;
    m_immediateHandled = false;

    m_channelTargetEffectMask = 0;

    if (m_spellInfo->IsEmpowerSpell())
        m_empower = std::make_unique<EmpowerData>();

    // Determine if spell can be reflected back to the caster
    // Patch 1.2 notes: Spell Reflection no longer reflects abilities
    m_canReflect = caster->IsUnit()
        && ((m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MAGIC && !m_spellInfo->HasAttribute(SPELL_ATTR0_IS_ABILITY)) || m_spellInfo->HasAttribute(SPELL_ATTR7_ALLOW_SPELL_REFLECTION))
        && !m_spellInfo->HasAttribute(SPELL_ATTR1_NO_REFLECTION) && !m_spellInfo->HasAttribute(SPELL_ATTR0_NO_IMMUNITIES)
        && !m_spellInfo->IsPassive();

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

        SelectEffectImplicitTargets(spellEffectInfo, spellEffectInfo.TargetA, SpellTargetIndex::TargetA, processedAreaEffectsMask);
        SelectEffectImplicitTargets(spellEffectInfo, spellEffectInfo.TargetB, SpellTargetIndex::TargetB, processedAreaEffectsMask);

        // Select targets of effect based on effect type
        // those are used when no valid target could be added for spell effect based on spell target type
        // some spell effects use explicit target as a default target added to target map (like SPELL_EFFECT_LEARN_SPELL)
        // some spell effects add target to target map only when target type specified (like SPELL_EFFECT_WEAPON)
        // some spell effects don't add anything to target map (confirmed with sniffs) (like SPELL_EFFECT_DESTROY_ALL_TOTEMS)
        SelectEffectTypeImplicitTargets(spellEffectInfo);

        if (m_targets.HasDst())
            AddDestTarget(*m_targets.GetDst(), spellEffectInfo.EffectIndex);

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
                    finish(SPELL_FAILED_BAD_IMPLICIT_TARGETS);
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
                    finish(SPELL_FAILED_IMMUNE);
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
                finish(SPELL_FAILED_BAD_IMPLICIT_TARGETS);
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

    if (m_targets.HasDst())
    {
        if (m_spellInfo->HasAttribute(SPELL_ATTR8_REQUIRES_LOCATION_TO_BE_ON_LIQUID_SURFACE))
        {
            ZLiquidStatus status = m_caster->GetMap()->GetLiquidStatus(m_caster->GetPhaseShift(),
                m_targets.GetDstPos()->GetPositionX(), m_targets.GetDstPos()->GetPositionY(), m_targets.GetDstPos()->GetPositionZ());
            if (!(status & (LIQUID_MAP_WATER_WALK | LIQUID_MAP_IN_WATER)))
            {
                SendCastResult(SPELL_FAILED_NO_LIQUID);
                finish(SPELL_FAILED_NO_LIQUID);
                return;
            }
        }
    }

    if (uint64 dstDelay = CalculateDelayMomentForDst(m_spellInfo->LaunchDelay))
        m_delayMoment = dstDelay;
}

uint64 Spell::CalculateDelayMomentForDst(float launchDelay) const
{
    if (m_targets.HasDst())
    {
        if (m_targets.HasTraj())
        {
            float speed = m_targets.GetSpeedXY();
            if (speed > 0.0f)
                return uint64(std::floor((m_targets.GetDist2d() / speed + launchDelay) * 1000.0f));
        }
        else if (m_spellInfo->HasAttribute(SPELL_ATTR9_MISSILE_SPEED_IS_DELAY_IN_SEC))
            return uint64(std::floor((m_spellInfo->Speed + launchDelay) * 1000.0f));
        else if (m_spellInfo->Speed > 0.0f)
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
    UpdateDelayMomentForDst(CalculateDelayMomentForDst(0.0f));
}

void Spell::UpdateDelayMomentForDst(uint64 hitDelay)
{
    m_delayMoment = hitDelay;

    if (GetDelayStart())
        m_caster->m_Events.ModifyEventTime(_spellEvent, Milliseconds(GetDelayStart() + m_delayMoment));
}

void Spell::UpdateDelayMomentForUnitTarget(Unit* unit, uint64 hitDelay)
{
    auto itr = std::find_if(m_UniqueTargetInfo.begin(), m_UniqueTargetInfo.end(), [unit](Spell::TargetInfo const& targetInfo)
    {
        return targetInfo.TargetGUID == unit->GetGUID();
    });

    uint64 oldDelay = itr->TimeDelay;
    itr->TimeDelay = hitDelay;

    if (hitDelay && (!m_delayMoment || m_delayMoment > hitDelay))
        m_delayMoment = hitDelay;
    else if (m_delayMoment && oldDelay < hitDelay)
    {
        // if new hit delay is greater than old delay for this target we must check all other spell targets to see if m_delayMoment can be increased
        auto minDelayTargetItr = std::min_element(m_UniqueTargetInfo.begin(), m_UniqueTargetInfo.end(), [](Spell::TargetInfo const& itr, Spell::TargetInfo const& smallest)
        {
            return itr.TimeDelay && itr.TimeDelay < smallest.TimeDelay;
        });

        m_delayMoment = minDelayTargetItr->TimeDelay;
    }

    if (GetDelayStart())
        m_caster->m_Events.ModifyEventTime(_spellEvent, Milliseconds(GetDelayStart() + m_delayMoment));
}

void Spell::SelectEffectImplicitTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, SpellTargetIndex targetIndex, uint32& processedEffectMask)
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
                    spellEffectInfo.CalcRadius(m_caster, SpellTargetIndex::TargetA) == effects[j].CalcRadius(m_caster, SpellTargetIndex::TargetA) &&
                    spellEffectInfo.CalcRadius(m_caster, SpellTargetIndex::TargetB) == effects[j].CalcRadius(m_caster, SpellTargetIndex::TargetB) &&
                    spellEffectInfo.EffectAttributes.HasFlag(SpellEffectAttributes::PlayersOnly) == effects[j].EffectAttributes.HasFlag(SpellEffectAttributes::PlayersOnly) &&
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
            SelectImplicitNearbyTargets(spellEffectInfo, targetType, targetIndex, effectMask);
            break;
        case TARGET_SELECT_CATEGORY_CONE:
            SelectImplicitConeTargets(spellEffectInfo, targetType, targetIndex, effectMask);
            break;
        case TARGET_SELECT_CATEGORY_AREA:
            SelectImplicitAreaTargets(spellEffectInfo, targetType, targetIndex, effectMask);
            break;
        case TARGET_SELECT_CATEGORY_TRAJ:
            // just in case there is no dest, explanation in SelectImplicitDestDestTargets
            CheckDst();

            SelectImplicitTrajTargets(spellEffectInfo, targetType);
            break;
        case TARGET_SELECT_CATEGORY_LINE:
            SelectImplicitLineTargets(spellEffectInfo, targetType, targetIndex, effectMask);
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
                             SelectImplicitCasterDestTargets(spellEffectInfo, targetType, targetIndex);
                             break;
                         case TARGET_REFERENCE_TYPE_TARGET:
                             SelectImplicitTargetDestTargets(spellEffectInfo, targetType, targetIndex);
                             break;
                         case TARGET_REFERENCE_TYPE_DEST:
                             SelectImplicitDestDestTargets(spellEffectInfo, targetType, targetIndex);
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
        }
        default:
            ABORT_MSG("Spell::SelectImplicitChannelTargets: received not implemented target type");
            break;
    }
}

void Spell::SelectImplicitNearbyTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, SpellTargetIndex targetIndex, uint32 effMask)
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

    ConditionContainer* condList = spellEffectInfo.ImplicitTargetConditions.get();

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
                        finish(SPELL_FAILED_BAD_IMPLICIT_TARGETS);
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
                        finish(SPELL_FAILED_BAD_IMPLICIT_TARGETS);
                    }
                    return;
                }
                if (targetType.GetTarget() == TARGET_DEST_NEARBY_ENTRY_OR_DB)
                {
                    if (SpellTargetPosition const* st = sSpellMgr->GetSpellTargetPosition(m_spellInfo->Id, spellEffectInfo.EffectIndex))
                    {
                        SpellDestination dest(*m_caster);
                        if (st->target_mapId == m_caster->GetMapId() && m_caster->IsInDist(st->target_X, st->target_Y, st->target_Z, range))
                            dest = SpellDestination(st->target_X, st->target_Y, st->target_Z, st->target_Orientation);
                        else
                        {
                            float randomRadius = spellEffectInfo.CalcRadius(m_caster, targetIndex);
                            if (randomRadius > 0.0f)
                                MovePosition(dest._position, m_caster, randomRadius, targetType.CalcDirectionAngle());
                        }

                        CallScriptDestinationTargetSelectHandlers(dest, spellEffectInfo.EffectIndex, targetType);
                        m_targets.SetDst(dest);
                        return;
                    }
                }
                break;
            default:
                break;
        }
    }

    WorldObject* target = SearchNearbyTarget(spellEffectInfo, range, targetType.GetObjectType(), targetType.GetCheckType(), condList);
    float randomRadius = 0.0f;
    switch (targetType.GetTarget())
    {
        case TARGET_DEST_NEARBY_ENTRY_OR_DB:
            // if we are here then there was no db target
            if (!target)
            {
                target = m_caster;
                // radius is only meant to be randomized when using caster fallback
                randomRadius = spellEffectInfo.CalcRadius(m_caster, targetIndex);
            }
            break;
        default:
            break;
    }

    if (!target)
    {
        TC_LOG_DEBUG("spells", "Spell::SelectImplicitNearbyTargets: cannot find nearby target for spell ID {}, effect {}", m_spellInfo->Id, uint32(spellEffectInfo.EffectIndex));
        SendCastResult(SPELL_FAILED_BAD_IMPLICIT_TARGETS);
        finish(SPELL_FAILED_BAD_IMPLICIT_TARGETS);
        return;
    }

    CallScriptObjectTargetSelectHandlers(target, spellEffectInfo.EffectIndex, targetType);
    if (!target)
    {
        TC_LOG_DEBUG("spells", "Spell::SelectImplicitNearbyTargets: OnObjectTargetSelect script hook for spell Id {} set NULL target, effect {}", m_spellInfo->Id, uint32(spellEffectInfo.EffectIndex));
        SendCastResult(SPELL_FAILED_BAD_IMPLICIT_TARGETS);
        finish(SPELL_FAILED_BAD_IMPLICIT_TARGETS);
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
                finish(SPELL_FAILED_BAD_IMPLICIT_TARGETS);
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
                finish(SPELL_FAILED_BAD_IMPLICIT_TARGETS);
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
                finish(SPELL_FAILED_BAD_IMPLICIT_TARGETS);
                return;
            }
            break;
        case TARGET_OBJECT_TYPE_DEST:
        {
            SpellDestination dest(*target);
            if (randomRadius > 0.0f)
                MovePosition(dest._position, target, randomRadius, targetType.CalcDirectionAngle());

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

void Spell::SelectImplicitConeTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, SpellTargetIndex targetIndex, uint32 effMask)
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
    ConditionContainer* condList = spellEffectInfo.ImplicitTargetConditions.get();
    float radius = spellEffectInfo.CalcRadius(m_caster, targetIndex) * m_spellValue->RadiusMod;

    if (uint32 containerTypeMask = GetSearcherTypeMask(m_spellInfo, spellEffectInfo, objectType, condList))
    {
        float extraSearchRadius = radius > 0.0f ? EXTRA_CELL_SEARCH_RADIUS : 0.0f;
        Trinity::WorldObjectSpellConeTargetCheck check(coneSrc, DegToRad(coneAngle), m_spellInfo->Width ? m_spellInfo->Width : m_caster->GetCombatReach(), radius, m_caster, m_spellInfo, selectionType, condList, objectType);
        Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellConeTargetCheck> searcher(m_caster, targets, check, containerTypeMask);
        SearchTargets<Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellConeTargetCheck> >(searcher, containerTypeMask, m_caster, m_caster, radius + extraSearchRadius);

        CallScriptObjectAreaTargetSelectHandlers(targets, spellEffectInfo.EffectIndex, targetType);

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

void Spell::SelectImplicitAreaTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, SpellTargetIndex targetIndex, uint32 effMask)
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

    float radius = spellEffectInfo.CalcRadius(m_caster, targetIndex) * m_spellValue->RadiusMod;
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
                    SearchAreaTargets(targets, spellEffectInfo, radius, targetedUnit, referer, targetType.GetObjectType(), targetType.GetCheckType(),
                        spellEffectInfo.ImplicitTargetConditions.get(), Trinity::WorldObjectSpellAreaTargetSearchReason::Area);
            }
            break;
        case TARGET_UNIT_CASTER_AND_SUMMONS:
            targets.push_back(m_caster);
            SearchAreaTargets(targets, spellEffectInfo, radius, center, referer, targetType.GetObjectType(), targetType.GetCheckType(),
                spellEffectInfo.ImplicitTargetConditions.get(), Trinity::WorldObjectSpellAreaTargetSearchReason::Area);
            break;
        case TARGET_UNIT_AREA_THREAT_LIST:
            if (Unit* unit = m_caster->ToUnit())
                for (ThreatReference const* threatRef : unit->GetThreatManager().GetUnsortedThreatList())
                    if (Unit* threateningUnit = threatRef->GetVictim())
                        targets.push_back(threateningUnit);
            break;
        case TARGET_UNIT_AREA_TAP_LIST:
            if (Creature* creature = m_caster->ToCreature())
                for (ObjectGuid const& tapperGuid : creature->GetTapList())
                    if (Player* tapper = ObjectAccessor::GetPlayer(*m_caster, tapperGuid))
                        targets.push_back(tapper);
            break;
        default:
            SearchAreaTargets(targets, spellEffectInfo, radius, center, referer, targetType.GetObjectType(), targetType.GetCheckType(),
                spellEffectInfo.ImplicitTargetConditions.get(), Trinity::WorldObjectSpellAreaTargetSearchReason::Area);
            break;
    }

    if (targetType.GetObjectType() == TARGET_OBJECT_TYPE_UNIT_AND_DEST)
    {
        SpellDestination dest(*referer);
        if (m_spellInfo->HasAttribute(SPELL_ATTR4_USE_FACING_FROM_SPELL))
            dest._position.SetOrientation(spellEffectInfo.PositionFacing);

        CallScriptDestinationTargetSelectHandlers(dest, spellEffectInfo.EffectIndex, targetType);

        m_targets.ModDst(dest);
    }

    CallScriptObjectAreaTargetSelectHandlers(targets, spellEffectInfo.EffectIndex, targetType);

    if (targetType.GetTarget() == TARGET_UNIT_SRC_AREA_FURTHEST_ENEMY)
        targets.sort(Trinity::ObjectDistanceOrderPred(referer, false));

    if (!targets.empty())
    {
        // Other special target selection goes here
        if (uint32 maxTargets = m_spellValue->MaxAffectedTargets)
        {
            if (targetType.GetTarget() != TARGET_UNIT_SRC_AREA_FURTHEST_ENEMY)
                Trinity::Containers::RandomResize(targets, maxTargets);
            else if (targets.size() > maxTargets)
                targets.resize(maxTargets);
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

void Spell::SelectImplicitCasterDestTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, SpellTargetIndex targetIndex)
{
    SpellDestination dest(*m_caster);

    switch (targetType.GetTarget())
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
            float angle = rand_norm() * static_cast<float>(M_PI * 35.0f / 180.0f) - static_cast<float>(M_PI * 17.5f / 180.0f);
            m_caster->GetClosePoint(x, y, z, DEFAULT_PLAYER_BOUNDING_RADIUS, dist, angle);

            float ground = m_caster->GetMapHeight(x, y, z);
            float liquidLevel = VMAP_INVALID_HEIGHT_VALUE;
            LiquidData liquidData;
            if (m_caster->GetMap()->GetLiquidStatus(m_caster->GetPhaseShift(), x, y, z, {}, &liquidData, m_caster->GetCollisionHeight()))
                liquidLevel = liquidData.level;

            if (liquidLevel <= ground) // When there is no liquid Map::GetWaterOrGroundLevel returns ground level
            {
                SendCastResult(SPELL_FAILED_NOT_HERE);
                SendChannelUpdate(0, SPELL_FAILED_NOT_HERE);
                finish(SPELL_FAILED_NOT_HERE);
                return;
            }

            if (ground + 0.75 > liquidLevel)
            {
                SendCastResult(SPELL_FAILED_TOO_SHALLOW);
                SendChannelUpdate(0, SPELL_FAILED_TOO_SHALLOW);
                finish(SPELL_FAILED_TOO_SHALLOW);
                return;
            }

            dest = SpellDestination(x, y, liquidLevel, m_caster->GetOrientation());
            break;
        }
        case TARGET_DEST_CASTER_FRONT_LEAP:
        case TARGET_DEST_CASTER_MOVEMENT_DIRECTION:
        {
            Unit* unitCaster = m_caster->ToUnit();
            if (!unitCaster)
                break;

            float dist = spellEffectInfo.CalcRadius(unitCaster, targetIndex);
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

            MovePosition(pos, unitCaster, dist, angle);
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
            float dist = spellEffectInfo.CalcRadius(m_caster, targetIndex);
            float angle = targetType.CalcDirectionAngle();
            float objSize = m_caster->GetCombatReach();

            switch (targetType.GetTarget())
            {
                case TARGET_DEST_CASTER_SUMMON:
                    dist = PET_FOLLOW_DIST;
                    break;
                case TARGET_DEST_CASTER_RANDOM:
                    if (dist > objSize)
                        dist = objSize + (dist - objSize);
                    break;
                case TARGET_DEST_CASTER_FRONT_LEFT:
                case TARGET_DEST_CASTER_BACK_LEFT:
                case TARGET_DEST_CASTER_FRONT_RIGHT:
                case TARGET_DEST_CASTER_BACK_RIGHT:
                {
                    static float const DefaultTotemDistance = 3.0f;
                    if (!spellEffectInfo.HasRadius(targetIndex))
                        dist = DefaultTotemDistance;
                    break;
                }
                default:
                    break;
            }

            if (dist < objSize)
                dist = objSize;

            Position pos = dest._position;
            MovePosition(pos, m_caster, dist, angle);

            dest.Relocate(pos);
            break;
        }
    }

    if (m_spellInfo->HasAttribute(SPELL_ATTR4_USE_FACING_FROM_SPELL))
        dest._position.SetOrientation(spellEffectInfo.PositionFacing);

    CallScriptDestinationTargetSelectHandlers(dest, spellEffectInfo.EffectIndex, targetType);
    m_targets.SetDst(dest);
}

void Spell::SelectImplicitTargetDestTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, SpellTargetIndex targetIndex)
{
    ASSERT(m_targets.GetObjectTarget() && "Spell::SelectImplicitTargetDestTargets - no explicit object target available!");
    WorldObject* target = m_targets.GetObjectTarget();

    SpellDestination dest(*target);

    switch (targetType.GetTarget())
    {
        case TARGET_DEST_TARGET_ENEMY:
        case TARGET_DEST_TARGET_ANY:
        case TARGET_DEST_TARGET_ALLY:
            break;
        default:
        {
            float angle = targetType.CalcDirectionAngle();
            float dist = spellEffectInfo.CalcRadius(nullptr, targetIndex);

            Position pos = dest._position;
            MovePosition(pos, target, dist, angle);

            dest.Relocate(pos);
            break;
        }
    }

    if (m_spellInfo->HasAttribute(SPELL_ATTR4_USE_FACING_FROM_SPELL))
        dest._position.SetOrientation(spellEffectInfo.PositionFacing);

    CallScriptDestinationTargetSelectHandlers(dest, spellEffectInfo.EffectIndex, targetType);
    m_targets.SetDst(dest);
}

void Spell::SelectImplicitDestDestTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, SpellTargetIndex targetIndex)
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
        case TARGET_DEST_DEST_TARGET_TOWARDS_CASTER:
        {
            float dist = spellEffectInfo.CalcRadius(m_caster, targetIndex);
            Position pos = dest._position;
            float angle = pos.GetAbsoluteAngle(m_caster) - m_caster->GetOrientation();

            MovePosition(pos, m_caster, dist, angle);
            pos.SetOrientation(m_caster->GetAbsoluteAngle(dest._position));

            dest.Relocate(pos);
            break;
        }
        default:
        {
            float angle = targetType.CalcDirectionAngle();
            float dist = spellEffectInfo.CalcRadius(m_caster, targetIndex);

            Position pos = dest._position;
            MovePosition(pos, m_caster, dist, angle);

            dest.Relocate(pos);
            break;
        }
    }

    if (m_spellInfo->HasAttribute(SPELL_ATTR4_USE_FACING_FROM_SPELL))
        dest._position.SetOrientation(spellEffectInfo.PositionFacing);

    CallScriptDestinationTargetSelectHandlers(dest, spellEffectInfo.EffectIndex, targetType);
    m_targets.ModDst(dest);
}

void Spell::SelectImplicitCasterObjectTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType)
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

void Spell::SelectImplicitTargetObjectTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType)
{
    ASSERT((m_targets.GetObjectTarget() || m_targets.GetItemTarget()) && "Spell::SelectImplicitTargetObjectTargets - no explicit object or item target available!");

    WorldObject* target = m_targets.GetObjectTarget();

    CallScriptObjectTargetSelectHandlers(target, spellEffectInfo.EffectIndex, targetType);

    if (target)
    {
        if (Unit* unit = target->ToUnit())
            AddUnitTarget(unit, 1 << spellEffectInfo.EffectIndex, true, false);
        else if (GameObject* gobj = target->ToGameObject())
            AddGOTarget(gobj, 1 << spellEffectInfo.EffectIndex);
        else if (Corpse* corpse = target->ToCorpse())
            AddCorpseTarget(corpse, 1 << spellEffectInfo.EffectIndex);

        SelectImplicitChainTargets(spellEffectInfo, targetType, target, 1 << spellEffectInfo.EffectIndex);
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

    if (maxTargets > 1)
    {
        // mark damage multipliers as used
        for (size_t k = spellEffectInfo.EffectIndex; k < m_spellInfo->GetEffects().size(); ++k)
            if (effMask & (1 << k))
                m_damageMultipliers[k] = 1.0f;
        m_applyMultiplierMask |= effMask;

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
    Trinity::WorldObjectSpellTrajTargetCheck check(dist2d, &srcPos, m_caster, m_spellInfo, targetType.GetCheckType(), spellEffectInfo.ImplicitTargetConditions.get(), TARGET_OBJECT_TYPE_NONE);
    Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellTrajTargetCheck> searcher(m_caster, targets, check, GRID_MAP_TYPE_MASK_ALL);
    SearchTargets<Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellTrajTargetCheck> > (searcher, GRID_MAP_TYPE_MASK_ALL, m_caster, &srcPos, dist2d);
    if (targets.empty())
        return;

    targets.sort(Trinity::ObjectDistanceOrderPred(m_caster));

    float b = tangent(m_targets.GetPitch());
    float a = (srcToDestDelta - dist2d * b) / (dist2d * dist2d);
    if (a > -0.0001f)
        a = 0.f;

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

        if (Unit* unit = (*itr)->ToUnit())
        {
            if (unitCaster == *itr || unitCaster->IsOnVehicle(unit) || unit->GetVehicle())
                continue;

            if (Creature* creatureTarget = unit->ToCreature())
            {
                if (!(creatureTarget->GetCreatureDifficulty()->TypeFlags & CREATURE_TYPE_FLAG_COLLIDE_WITH_MISSILES))
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
        if (m_spellInfo->HasAttribute(SPELL_ATTR4_USE_FACING_FROM_SPELL))
            dest._position.SetOrientation(spellEffectInfo.PositionFacing);

        CallScriptDestinationTargetSelectHandlers(dest, spellEffectInfo.EffectIndex, targetType);
        m_targets.ModDst(dest);
    }
}

void Spell::SelectImplicitLineTargets(SpellEffectInfo const& spellEffectInfo, SpellImplicitTargetInfo const& targetType, SpellTargetIndex targetIndex, uint32 effMask)
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

    ConditionContainer* condList = spellEffectInfo.ImplicitTargetConditions.get();
    float radius = spellEffectInfo.CalcRadius(m_caster, targetIndex) * m_spellValue->RadiusMod;

    if (uint32 containerTypeMask = GetSearcherTypeMask(m_spellInfo, spellEffectInfo, objectType, condList))
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

uint32 Spell::GetSearcherTypeMask(SpellInfo const* spellInfo, SpellEffectInfo const& spellEffectInfo, SpellTargetObjectTypes objType, ConditionContainer const* condList)
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

    if (spellInfo->HasAttribute(SPELL_ATTR3_ONLY_ON_PLAYER) || spellEffectInfo.EffectAttributes.HasFlag(SpellEffectAttributes::PlayersOnly))
        retMask &= GRID_MAP_TYPE_MASK_CORPSE | GRID_MAP_TYPE_MASK_PLAYER;
    if (spellInfo->HasAttribute(SPELL_ATTR3_ONLY_ON_GHOSTS))
        retMask &= GRID_MAP_TYPE_MASK_PLAYER;
    if (spellInfo->HasAttribute(SPELL_ATTR5_NOT_ON_PLAYER))
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

template TC_GAME_API void Spell::SearchTargets<Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellAreaTargetCheck>>(Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellAreaTargetCheck>& searcher, uint32 containerMask, WorldObject* referer, Position const* pos, float radius);

WorldObject* Spell::SearchNearbyTarget(SpellEffectInfo const& spellEffectInfo, float range, SpellTargetObjectTypes objectType, SpellTargetCheckTypes selectionType, ConditionContainer const* condList)
{
    WorldObject* target = nullptr;
    uint32 containerTypeMask = GetSearcherTypeMask(m_spellInfo, spellEffectInfo, objectType, condList);
    if (!containerTypeMask)
        return nullptr;

    Trinity::WorldObjectSpellNearbyTargetCheck check(range, m_caster, m_spellInfo, selectionType, condList, objectType);
    Trinity::WorldObjectLastSearcher<Trinity::WorldObjectSpellNearbyTargetCheck> searcher(m_caster, target, check, containerTypeMask);
    searcher.i_phaseShift = &PhasingHandler::GetAlwaysVisiblePhaseShift();
    SearchTargets<Trinity::WorldObjectLastSearcher<Trinity::WorldObjectSpellNearbyTargetCheck>>(searcher, containerTypeMask, m_caster, m_caster, range);
    return target;
}

void Spell::SearchAreaTargets(std::list<WorldObject*>& targets, SpellEffectInfo const& spellEffectInfo, float range, Position const* position, WorldObject* referer,
    SpellTargetObjectTypes objectType, SpellTargetCheckTypes selectionType, ConditionContainer const* condList,
    Trinity::WorldObjectSpellAreaTargetSearchReason searchReason)
{
    uint32 containerTypeMask = GetSearcherTypeMask(m_spellInfo, spellEffectInfo, objectType, condList);
    if (!containerTypeMask)
        return;

    float extraSearchRadius = range > 0.0f ? EXTRA_CELL_SEARCH_RADIUS : 0.0f;
    Trinity::WorldObjectSpellAreaTargetCheck check(range, position, m_caster, referer, m_spellInfo, selectionType, condList, objectType, searchReason);
    Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellAreaTargetCheck> searcher(m_caster, targets, check, containerTypeMask);
    searcher.i_phaseShift = &PhasingHandler::GetAlwaysVisiblePhaseShift();
    SearchTargets<Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellAreaTargetCheck>>(searcher, containerTypeMask, m_caster, position, range + extraSearchRadius);
}

void Spell::SearchChainTargets(std::list<WorldObject*>& targets, uint32 chainTargets, WorldObject* target, SpellTargetObjectTypes objectType,
    SpellTargetCheckTypes selectType, SpellEffectInfo const& spellEffectInfo, bool isChainHeal)
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
        modOwner->ApplySpellMod(m_spellInfo, SpellModOp::ChainJumpDistance, jumpRadius, this);

    // max dist which spell can reach
    float searchRadius = [&]()
    {
        if (m_spellInfo->HasAttribute(SPELL_ATTR2_CHAIN_FROM_CASTER))
            return GetMinMaxRange(false).second;

        if (spellEffectInfo.EffectAttributes.HasFlag(SpellEffectAttributes::ChainFromInitialTarget))
            return jumpRadius;

        return jumpRadius * chainTargets;
    }();

    WorldObject* chainSource = m_spellInfo->HasAttribute(SPELL_ATTR2_CHAIN_FROM_CASTER) ? m_caster : target;
    std::list<WorldObject*> tempTargets;
    SearchAreaTargets(tempTargets, spellEffectInfo, searchRadius, chainSource, m_caster, objectType, selectType, spellEffectInfo.ImplicitTargetConditions.get(),
        Trinity::WorldObjectSpellAreaTargetSearchReason::Chain);
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
                    if ((deficit > maxHPDeficit || foundItr == tempTargets.end()) && chainSource->IsWithinDist(unit, jumpRadius) && IsWithinLOS(chainSource, unit, false, VMAP::ModelIgnoreFlags::M2))
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
                bool isBestDistanceMatch = foundItr != tempTargets.end() ? chainSource->GetDistanceOrder(*itr, *foundItr) : chainSource->IsWithinDist(*itr, jumpRadius);
                if (!isBestDistanceMatch)
                    continue;

                if (!IsWithinLOS(chainSource, *itr, false, VMAP::ModelIgnoreFlags::M2))
                    continue;

                if (spellEffectInfo.EffectAttributes.HasFlag(SpellEffectAttributes::EnforceLineOfSightToChainTargets) && !IsWithinLOS(m_caster, *itr, false, VMAP::ModelIgnoreFlags::M2))
                    continue;

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

            ProcFlags const typeMaskActor = PROC_FLAG_NONE;
            ProcFlags const typeMaskActionTarget = PROC_FLAG_TAKE_HARMFUL_SPELL | PROC_FLAG_TAKE_HARMFUL_ABILITY;
            ProcFlagsSpellType const spellTypeMask = PROC_SPELL_TYPE_DAMAGE | PROC_SPELL_TYPE_NO_DMG_HEAL;
            ProcFlagsSpellPhase const spellPhaseMask = PROC_SPELL_PHASE_NONE;
            ProcFlagsHit const hitMask = PROC_HIT_REFLECT;

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

    // Calculate hit result
    WorldObject* caster = m_originalCaster ? m_originalCaster : m_caster;
    targetInfo.MissCondition = caster->SpellHitResult(target, m_spellInfo, m_canReflect && !(IsPositive() && m_caster->IsFriendlyTo(target)));

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

        if (m_spellInfo->HasAttribute(SPELL_ATTR9_MISSILE_SPEED_IS_DELAY_IN_SEC))
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
        target->m_Events.AddEvent(new ProcReflectDelayed(target, m_originalCasterGUID), target->m_Events.CalculateTime(Milliseconds(targetInfo.TimeDelay)));

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
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
        if (!spellEffectInfo.IsEffect() || !CheckEffectTarget(go, spellEffectInfo))
            effectMask &= ~(1 << spellEffectInfo.EffectIndex);

    // no effects left
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
    if (static_cast<WorldObject*>(m_caster) != go)
    {
        float hitDelay = m_spellInfo->LaunchDelay;
        if (m_spellInfo->HasAttribute(SPELL_ATTR9_MISSILE_SPEED_IS_DELAY_IN_SEC))
            hitDelay += m_spellInfo->Speed;
        else if (m_spellInfo->Speed > 0.0f)
        {
            // calculate spell incoming interval
            float dist = std::max(m_caster->GetDistance(go->GetPositionX(), go->GetPositionY(), go->GetPositionZ()), 5.0f);
            hitDelay += dist / m_spellInfo->Speed;
        }

        target.TimeDelay = uint64(std::floor(hitDelay * 1000.0f));
    }
    else
        target.TimeDelay = 0ULL;

    // Calculate minimum incoming time
    if (target.TimeDelay && (!m_delayMoment || m_delayMoment > target.TimeDelay))
        m_delayMoment = target.TimeDelay;

    // Add target to list
    m_UniqueGOTargetInfo.emplace_back(std::move(target));
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

    // no effects left
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
    if (m_caster != corpse)
    {
        float hitDelay = m_spellInfo->LaunchDelay;
        if (m_spellInfo->HasAttribute(SPELL_ATTR9_MISSILE_SPEED_IS_DELAY_IN_SEC))
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

void Spell::AddDestTarget(SpellDestination const& dest, uint32 effIndex)
{
    m_destTargets[effIndex] = dest;
}

int32 Spell::GetUnitTargetIndexForEffect(ObjectGuid const& target, SpellEffIndex effect) const
{
    int32 index = 0;
    for (TargetInfo const& uniqueTargetInfo : m_UniqueTargetInfo)
    {
        if (uniqueTargetInfo.MissCondition == SPELL_MISS_NONE && uniqueTargetInfo.EffectMask & (1 << effect))
        {
            if (uniqueTargetInfo.TargetGUID == target)
                break;

            ++index;
        }
    }

    return index;
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

    if (spell->m_originalCaster && MissCondition != SPELL_MISS_EVADE && !spell->m_originalCaster->IsFriendlyTo(unit) && (!spell->m_spellInfo->IsPositive() || spell->m_spellInfo->HasEffect(SPELL_EFFECT_DISPEL)) && (spell->m_spellInfo->HasInitialAggro() || unit->IsEngaged()))
        unit->SetInCombatWith(spell->m_originalCaster);

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

    if (!spell->m_spellInfo->HasAttribute(SPELL_ATTR8_IGNORE_SANCTUARY) && spell->getState() == SPELL_STATE_DELAYED && !spell->IsPositive() && (GameTime::GetGameTimeMS() - TimeDelay) <= unit->m_lastSanctuaryTime)
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
        ProcFlagsInit procAttacker = spell->m_procAttacker;
        ProcFlagsInit procVictim = spell->m_procVictim;
        ProcFlagsSpellType procSpellType = PROC_SPELL_TYPE_NONE;
        ProcFlagsHit hitMask = PROC_HIT_NONE;

        // Spells with this flag cannot trigger if effect is cast on self
        bool const canEffectTrigger = spell->unitTarget->CanProc();

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
            SpellNonMeleeDamage damageInfo(caster, spell->unitTarget, spell->m_spellInfo, spell->m_SpellVisual, spell->m_spellSchoolMask, spell->m_castId);
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
                Unit::DealDamageMods(damageInfo.attacker, damageInfo.target, damageInfo.damage, &damageInfo.absorb);

                hitMask |= createProcHitMask(&damageInfo, MissCondition);
                procVictim |= PROC_FLAG_TAKE_ANY_DAMAGE;

                // sparring
                if (damageInfo.target != damageInfo.attacker)
                {
                    if (Creature* victimCreature = damageInfo.target->ToCreature())
                        damageInfo.damage = victimCreature->CalculateDamageForSparring(damageInfo.attacker, damageInfo.damage);
                }
                spell->m_damage = damageInfo.damage;

                caster->DealSpellDamage(&damageInfo, true);

                // Send log damage message to client
                caster->SendSpellNonMeleeDamageLog(&damageInfo);
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
        spell->m_procSpellType |= procSpellType;

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

        // Check for SPELL_ATTR7_INTERRUPT_ONLY_NONPLAYER
        if (MissCondition == SPELL_MISS_NONE && spell->m_spellInfo->HasAttribute(SPELL_ATTR7_CAN_CAUSE_INTERRUPT) && unit->GetTypeId() != TYPEID_PLAYER)
            caster->CastSpell(unit, SPELL_INTERRUPT_NONPLAYER, spell);
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
                uint32 effMask = EffectMask & aurApp->GetEffectsToApply();
                for (uint8 i = 0; i < spell->m_spellInfo->GetEffects().size(); ++i)
                    if ((effMask & (1 << i)) && aurApp->HasEffect(i))
                        effMask &= ~(1 << i);

                if (effMask)
                    _spellHitTarget->_ApplyAura(aurApp, effMask);

                if (aurApp->IsNeedClientUpdate() && aurApp->GetRemoveMode() == AURA_REMOVE_NONE)
                {
                    aurApp->ClientUpdate(false);
                    _spellHitTarget->RemoveVisibleAuraUpdate(aurApp);
                }
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

    if (Player* player = unit->ToPlayer())
    {
        player->FailCriteria(CriteriaFailEvent::BeSpellTarget, m_spellInfo->Id);
        player->StartCriteria(CriteriaStartEvent::BeSpellTarget, m_spellInfo->Id);
        player->UpdateCriteria(CriteriaType::BeSpellTarget, m_spellInfo->Id, 0, 0, m_caster);
    }

    if (Player* player = m_caster->ToPlayer())
        player->UpdateCriteria(CriteriaType::LandTargetedSpellOnTarget, m_spellInfo->Id, 0, 0, unit);

    if (m_caster != unit)
    {
        // Recheck  UNIT_FLAG_NON_ATTACKABLE for delayed spells
        if (m_spellInfo->HasHitDelay() && unit->HasUnitFlag(UNIT_FLAG_NON_ATTACKABLE) && unit->GetCharmerOrOwnerGUID() != m_caster->GetGUID())
            return SPELL_MISS_EVADE;

        if (m_caster->IsValidAttackTarget(unit, m_spellInfo))
            unit->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::HostileActionReceived);
        else if (m_caster->IsFriendlyTo(unit))
        {
            // for delayed spells ignore negative spells (after duel end) for friendly targets
            if (m_spellInfo->HasHitDelay() && unit->GetTypeId() == TYPEID_PLAYER && !IsPositive() && !m_caster->IsValidAssistTarget(unit, m_spellInfo))
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
                if (m_originalCaster->HasUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED))               // only do explicit combat forwarding for PvP enabled units
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
        for (SpellEffectInfo const& auraSpellEffect : m_spellInfo->GetEffects())
            hitInfo.AuraBasePoints[auraSpellEffect.EffectIndex] = (m_spellValue->CustomBasePointsMask & (1 << auraSpellEffect.EffectIndex))
            ? m_spellValue->EffectBasePoints[auraSpellEffect.EffectIndex]
            : auraSpellEffect.CalcBaseValue(m_originalCaster, unit, m_castItemEntry, m_castItemLevel);

        // Get Data Needed for Diminishing Returns, some effects may have multiple auras, so this must be done on spell hit, not aura add
        hitInfo.DRGroup = m_spellInfo->GetDiminishingReturnsGroupForSpell();

        DiminishingLevels diminishLevel = DIMINISHING_LEVEL_1;
        if (hitInfo.DRGroup)
        {
            diminishLevel = unit->GetDiminishing(hitInfo.DRGroup);
            DiminishingReturnsType type = m_spellInfo->GetDiminishingReturnsGroupType();
            // Increase Diminishing on unit, current informations for actually casts will use values above
            if (type == DRTYPE_ALL || (type == DRTYPE_PLAYER && unit->IsAffectedByDiminishingReturns()))
                unit->IncrDiminishing(m_spellInfo);
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

        hitInfo.AuraDuration = Aura::CalcMaxDuration(m_spellInfo, origCaster, &m_powerCost);

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

                        if (hitInfo.AuraDuration > 0)
                        {
                            hitInfo.AuraDuration *= m_spellValue->DurationMul;

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

                                // if there is no periodic effect
                                if (!hitInfo.AuraDuration)
                                    hitInfo.AuraDuration = int32(origDuration * m_originalCaster->m_unitData->ModCastingSpeed);
                            }
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
    HandleEffects(unit, nullptr, nullptr, nullptr, spellEffectInfo, SPELL_EFFECT_HANDLE_HIT_TARGET);
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
                m_caster->CastSpell(unit, i->triggeredSpell->Id, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                    .SetTriggeringSpell(this)
                    .SetCastDifficulty(i->triggeredSpell->Difficulty));
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

bool Spell::UpdateChanneledTargetList()
{
    // Not need check return true
    if (m_channelTargetEffectMask == 0)
        return true;

    uint32 channelTargetEffectMask = m_channelTargetEffectMask;
    uint32 channelAuraMask = 0;
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
        if (spellEffectInfo.IsEffect(SPELL_EFFECT_APPLY_AURA))
            channelAuraMask |= 1 << spellEffectInfo.EffectIndex;

    channelAuraMask &= channelTargetEffectMask;

    float range = 0;
    if (channelAuraMask)
    {
        range = m_spellInfo->GetMaxRange(IsPositive());
        if (Player* modOwner = m_caster->GetSpellModOwner())
            modOwner->ApplySpellMod(m_spellInfo, SpellModOp::Range, range, this);

        // add little tolerance level
        range += std::min(MAX_SPELL_RANGE_TOLERANCE, range*0.1f); // 10% but no more than MAX_SPELL_RANGE_TOLERANCE
    }

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
            finish(SPELL_FAILED_EQUIPPED_ITEM);
            return SPELL_FAILED_EQUIPPED_ITEM;
        }
    }

    InitExplicitTargets(targets);

    m_spellState = SPELL_STATE_PREPARING;

    if (triggeredByAura)
    {
        m_triggeredByAuraSpell = triggeredByAura->GetSpellInfo();
        m_castItemLevel = triggeredByAura->GetBase()->GetCastItemLevel();
    }

    // create and add update event for this spell
    _spellEvent = new SpellEvent(this);
    m_caster->m_Events.AddEvent(_spellEvent, m_caster->m_Events.CalculateTime(1ms));

    // check disables
    if (DisableMgr::IsDisabledFor(DISABLE_TYPE_SPELL, m_spellInfo->Id, m_caster))
    {
        SendCastResult(SPELL_FAILED_SPELL_UNAVAILABLE);
        finish(SPELL_FAILED_SPELL_UNAVAILABLE);
        return SPELL_FAILED_SPELL_UNAVAILABLE;
    }

    // Prevent casting at cast another spell (ServerSide check)
    if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CAST_IN_PROGRESS) && m_caster->ToUnit() && m_caster->ToUnit()->IsNonMeleeSpellCast(false, true, true, m_spellInfo->Id == 75) && !m_castId.IsEmpty())
    {
        SendCastResult(SPELL_FAILED_SPELL_IN_PROGRESS);
        finish(SPELL_FAILED_SPELL_IN_PROGRESS);
        return SPELL_FAILED_SPELL_IN_PROGRESS;
    }

    LoadScripts();

    // Fill cost data (do not use power for item casts)
    if (!m_CastItem)
        m_powerCost = m_spellInfo->CalcPowerCost(m_caster, m_spellSchoolMask, this);

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
            SendChannelUpdate(0, result);
            triggeredByAura->GetBase()->SetDuration(0);
        }

        if (param1 || param2)
            SendCastResult(result, &param1, &param2);
        else
            SendCastResult(result);

        // queue autorepeat spells for future repeating
        if (GetCurrentContainer() == CURRENT_AUTOREPEAT_SPELL && m_caster->IsUnit())
            m_caster->ToUnit()->SetCurrentCastSpell(this);

        finish(result);
        return result;
    }

    // Prepare data for triggers
    prepareDataForTriggerSystem();

    m_casttime = CallScriptCalcCastTimeHandlers(m_spellInfo->CalcCastTime(this));

    SpellCastResult movementResult = SPELL_CAST_OK;
    if (m_caster->IsUnit() && m_caster->ToUnit()->isMoving())
        movementResult = CheckMovement();

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

    if (movementResult != SPELL_CAST_OK)
    {
        if (m_caster->ToUnit()->IsControlledByPlayer() || !CanStopMovementForSpellCasting(m_caster->ToUnit()->GetMotionMaster()->GetCurrentMovementGeneratorType()))
        {
            SendCastResult(movementResult);
            finish(movementResult);
            return movementResult;
        }
        else
        {
            // Creatures (not controlled) give priority to spell casting over movement.
            // We assume that the casting is always valid and the current movement
            // is stopped immediately (because spells are updated before movement, so next Unit::Update would cancel the spell before stopping movement)
            // and future attempts are stopped by by Unit::IsMovementPreventedByCasting in movement generators to prevent casting interruption.
            m_caster->ToUnit()->StopMoving();
        }
    }

    CallScriptOnPrecastHandler();

    // set timer base at cast time
    ReSetTimer();

    TC_LOG_DEBUG("spells", "Spell::prepare: spell id {} source {} caster {} customCastFlags {} mask {}", m_spellInfo->Id, m_caster->GetEntry(), m_originalCaster ? m_originalCaster->GetEntry() : -1, _triggeredCastFlags, m_targets.GetTargetMask());

    if (m_spellInfo->HasAttribute(SPELL_ATTR12_START_COOLDOWN_ON_CAST_START))
        SendSpellCooldown();

    if (m_spellInfo->HasAttribute(SPELL_ATTR7_RESET_SWING_TIMER_AT_SPELL_START) && IsAutoActionResetSpell())
        ResetCombatTimers();

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

        if (Unit* unitCaster = m_caster->ToUnit())
        {
            // stealth must be removed at cast starting (at show channel bar)
            // skip triggered spell (item equip spell casting and other not explicit character casts/item uses)
            if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CAST_IN_PROGRESS) && !m_spellInfo->HasAttribute(SPELL_ATTR2_NOT_AN_ACTION))
                unitCaster->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::Action, m_spellInfo);

            // Do not register as current spell when requested to ignore cast in progress
            // We don't want to interrupt that other spell with cast time
            if (!willCastDirectly || !(_triggeredCastFlags & TRIGGERED_IGNORE_CAST_IN_PROGRESS))
                unitCaster->SetCurrentCastSpell(this);
        }
        SendSpellStart();

        if (!(_triggeredCastFlags & TRIGGERED_IGNORE_GCD))
            TriggerGlobalCooldown();

        // Call CreatureAI hook OnSpellStart
        if (Creature* caster = m_caster->ToCreature())
            if (caster->IsAIEnabled())
                caster->AI()->OnSpellStart(GetSpellInfo());

        if (willCastDirectly)
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

            SendChannelUpdate(0, SPELL_FAILED_INTERRUPTED);
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

    finish(SPELL_FAILED_INTERRUPTED);
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
        auto cleanupSpell = [this, modOwner](SpellCastResult res, int32* p1 = nullptr, int32* p2 = nullptr)
        {
            SendCastResult(res, p1, p2);
            SendInterrupted(0);

            if (modOwner)
                modOwner->SetSpellModTakingSpell(this, false);

            finish(res);
            SetExecutedCurrently(false);
        };

        int32 param1 = 0, param2 = 0;
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
            uint32 aura_effmask = 0;
            for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
                if (spellEffectInfo.IsUnitOwnedAuraEffect())
                    aura_effmask |= 1 << spellEffectInfo.EffectIndex;

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

    SelectSpellTargets();

    // Spell may be finished after target map check
    if (m_spellState == SPELL_STATE_FINISHED)
    {
        SendInterrupted(0);

        // cleanup after mod system
        // triggered spell pointer can be not removed in some cases
        if (m_caster->GetTypeId() == TYPEID_PLAYER)
            m_caster->ToPlayer()->SetSpellModTakingSpell(this, false);

        finish(SPELL_FAILED_INTERRUPTED);
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
            player->StartCriteria(CriteriaStartEvent::UseItem, m_CastItem->GetEntry());
            player->UpdateCriteria(CriteriaType::UseItem, m_CastItem->GetEntry());
        }

        player->FailCriteria(CriteriaFailEvent::CastSpell, m_spellInfo->Id);
        player->StartCriteria(CriteriaStartEvent::CastSpell, m_spellInfo->Id);
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
    }

    // CAST SPELL
    if (!m_spellInfo->HasAttribute(SPELL_ATTR12_START_COOLDOWN_ON_CAST_START))
        SendSpellCooldown();

    if (!m_spellInfo->LaunchDelay)
    {
        HandleLaunchPhase();
        m_launchHandled = true;
    }

    if (!m_spellInfo->HasAttribute(SPELL_ATTR7_RESET_SWING_TIMER_AT_SPELL_START) && IsAutoActionResetSpell())
        ResetCombatTimers();

    // we must send smsg_spell_go packet before m_castItem delete in TakeCastItem()...
    SendSpellGo();

    if (!m_spellInfo->IsChanneled())
        if (Creature* creatureCaster = m_caster->ToCreature())
            creatureCaster->ReleaseSpellFocus(this);

    // Okay, everything is prepared. Now we need to distinguish between immediate and evented delayed spells
    if (m_spellInfo->HasHitDelay() && !m_spellInfo->IsChanneled())
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

    if (m_scriptResult && !m_scriptWaitsForSpellHit)
        m_scriptResult->SetResult(SPELL_CAST_OK);

    CallScriptAfterCastHandlers();

    if (std::vector<int32> const* spell_triggered = sSpellMgr->GetSpellLinked(SPELL_LINK_CAST, m_spellInfo->Id))
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
        {
            m_originalCaster->GetSpellHistory()->ResetCooldown(m_spellInfo->Id, true);
            m_originalCaster->GetSpellHistory()->RestoreCharge(m_spellInfo->ChargeCategoryId);
        }
    }

    SetExecutedCurrently(false);

    if (!m_originalCaster)
        return;

    // Handle procs on cast
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

    procAttacker |= PROC_FLAG_2_CAST_SUCCESSFUL;

    ProcFlagsHit hitMask = m_hitMask;
    if (!(hitMask & PROC_HIT_CRITICAL))
        hitMask |= PROC_HIT_NORMAL;

    if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CAST_IN_PROGRESS) && !m_spellInfo->HasAttribute(SPELL_ATTR2_NOT_AN_ACTION))
        m_originalCaster->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags::ActionDelayed, m_spellInfo);

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
        if (duration > 0 || m_spellValue->Duration > 0)
        {
            if (!m_spellValue->Duration)
            {
                int32 originalDuration = duration;

                // First mod_duration then haste - see Missile Barrage
                // Apply duration mod
                if (Player* modOwner = m_caster->GetSpellModOwner())
                    modOwner->ApplySpellMod(m_spellInfo, SpellModOp::Duration, duration);

                duration *= m_spellValue->DurationMul;

                // Apply haste mods
                m_caster->ModSpellDurationTime(m_spellInfo, duration, this);

                if (IsEmpowerSpell())
                {
                    float ratio = float(duration) / float(originalDuration);
                    m_empower->StageDurations.resize(m_spellInfo->EmpowerStageThresholds.size());
                    Milliseconds totalExceptLastStage = 0ms;
                    for (std::size_t i = 0; i < m_empower->StageDurations.size() - 1; ++i)
                    {
                        m_empower->StageDurations[i] = Milliseconds(int64(m_spellInfo->EmpowerStageThresholds[i].count() * ratio));
                        totalExceptLastStage += m_empower->StageDurations[i];
                    }

                    m_empower->StageDurations.back() = Milliseconds(duration) - totalExceptLastStage;

                    if (Player const* playerCaster = m_caster->ToPlayer())
                        m_empower->MinHoldTime = Milliseconds(int64(m_empower->StageDurations[0].count() * playerCaster->GetEmpowerMinHoldStagePercent()));
                    else
                        m_empower->MinHoldTime = m_empower->StageDurations[0];

                    duration += SPELL_EMPOWER_HOLD_TIME_AT_MAX;
                }
            }
            else
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
    {
        m_hitMask = PROC_HIT_NORMAL;
        m_procSpellType = PROC_SPELL_TYPE_NO_DMG_HEAL;
    }
    else
        DoProcessTargetContainer(m_UniqueTargetInfo);

    DoProcessTargetContainer(m_UniqueGOTargetInfo);

    DoProcessTargetContainer(m_UniqueCorpseTargetInfo);

    FinishTargetProcessing();

    // spell is finished, perform some last features of the spell here
    _handle_finish_phase();

    // Remove used for cast item if need (it can be already NULL after TakeReagents call
    TakeCastItem();

    if (m_spellState != SPELL_STATE_CASTING)
        finish();                                           // successfully finish spell cast (not last in case autorepeat or channel spell)
}

uint64 Spell::handle_delayed(uint64 t_offset)
{
    if (!UpdatePointers())
    {
        // finish the spell if UpdatePointers() returned false, something wrong happened there
        finish(SPELL_FAILED_NO_VALID_TARGETS);
        return 0;
    }

    // when spell has a single missile we hit all targets (except caster) at the same time
    bool single_missile = m_targets.HasDst();
    bool ignoreTargetInfoTimeDelay = single_missile;
    uint64 next_time = 0;

    if (!m_launchHandled)
    {
        uint64 launchMoment = uint64(std::floor(m_spellInfo->LaunchDelay * 1000.0f));
        if (launchMoment > t_offset)
            return launchMoment;

        HandleLaunchPhase();
        m_launchHandled = true;
    }

    if (m_delayMoment > t_offset)
    {
        ignoreTargetInfoTimeDelay = false;
        next_time = m_delayMoment;
    }

    Player* modOwner = m_caster->GetSpellModOwner();
    if (modOwner)
        modOwner->SetSpellModTakingSpell(this, true);

    PrepareTargetProcessing();

    if (!m_immediateHandled && m_delayMoment <= t_offset)
    {
        _handle_immediate_phase();
        m_immediateHandled = true;
    }

    // now recheck units targeting correctness (need before any effects apply to prevent adding immunity at first effect not allow apply second spell effect and similar cases)
    {
        std::vector<TargetInfo> delayedTargets;
        m_UniqueTargetInfo.erase(std::remove_if(m_UniqueTargetInfo.begin(), m_UniqueTargetInfo.end(), [&](TargetInfo& target) -> bool
        {
            if (ignoreTargetInfoTimeDelay || target.TimeDelay <= t_offset)
            {
                target.TimeDelay = t_offset;
                delayedTargets.emplace_back(std::move(target));
                return true;
            }
            else if (!single_missile && (next_time == 0 || target.TimeDelay < next_time))
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
            if (ignoreTargetInfoTimeDelay || goTarget.TimeDelay <= t_offset)
            {
                goTarget.TimeDelay = t_offset;
                delayedGOTargets.emplace_back(std::move(goTarget));
                return true;
            }
            else if (!single_missile && (next_time == 0 || goTarget.TimeDelay < next_time))
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

        finish();                                           // successfully finish spell cast

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
        if (m_spellInfo->HasEffect(SPELL_EFFECT_ADD_EXTRA_ATTACKS))
            unitCaster->SetLastExtraAttackSpell(m_spellInfo->Id);

    // Handle procs on finish
    if (!m_originalCaster)
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

    Unit::ProcSkillsAndAuras(m_originalCaster, nullptr, procAttacker, PROC_FLAG_NONE, m_procSpellType, PROC_SPELL_PHASE_FINISH, m_hitMask, this, nullptr, nullptr);
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

    if (!m_targets.GetUnitTargetGUID().IsEmpty() && !m_targets.GetUnitTarget())
    {
        TC_LOG_DEBUG("spells", "Spell {} is cancelled due to removal of target.", m_spellInfo->Id);
        cancel();
        return;
    }

    // check if the unit caster has moved before the spell finished
    if (m_timer != 0 && m_caster->IsUnit() && m_caster->ToUnit()->isMoving() && CheckMovement() != SPELL_CAST_OK)
        cancel();

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

            if (IsEmpowerSpell())
            {
                auto getCompletedEmpowerStages = [&]() -> int32
                {
                    Milliseconds passed(m_channeledDuration - m_timer);
                    for (std::size_t i = 0; i < m_empower->StageDurations.size(); ++i)
                    {
                        passed -= m_empower->StageDurations[i];
                        if (passed < 0ms)
                            return i;
                    }

                    return m_empower->StageDurations.size();
                };

                int32 completedStages = getCompletedEmpowerStages();
                if (completedStages != m_empower->CompletedStages)
                {
                    WorldPackets::Spells::SpellEmpowerSetStage empowerSetStage;
                    empowerSetStage.CastID = m_castId;
                    empowerSetStage.CasterGUID = m_caster->GetGUID();
                    empowerSetStage.Stage = m_empower->CompletedStages;
                    m_caster->SendMessageToSet(empowerSetStage.Write(), true);

                    m_empower->CompletedStages = completedStages;
                    m_caster->ToUnit()->SetSpellEmpowerStage(completedStages);

                    CallScriptEmpowerStageCompletedHandlers(completedStages);
                }

                if (CanReleaseEmpowerSpell())
                {
                    m_empower->IsReleased = true;
                    m_timer = 0;
                    CallScriptEmpowerCompletedHandlers(m_empower->CompletedStages);
                }
            }

            if (m_timer == 0)
            {
                SendChannelUpdate(0, SPELL_CAST_OK);
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

void Spell::finish(SpellCastResult result)
{
    if (m_spellState == SPELL_STATE_FINISHED)
        return;
    m_spellState = SPELL_STATE_FINISHED;

    if (m_scriptResult && (m_scriptWaitsForSpellHit || result != SPELL_CAST_OK))
        m_scriptResult->SetResult(result);

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
                && charm->m_unitData->CreatedBySpell == int32(m_spellInfo->Id))
                ((Puppet*)charm)->UnSummon();
    }

    if (Creature* creatureCaster = unitCaster->ToCreature())
        creatureCaster->ReleaseSpellFocus(this);

    Unit::ProcSkillsAndAuras(unitCaster, nullptr, PROC_FLAG_CAST_ENDED, PROC_FLAG_NONE, PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_NONE, PROC_HIT_NONE, this, nullptr, nullptr);

    if (IsEmpowerSpell())
    {
        // Empower spells trigger gcd at the end of cast instead of at start
        if (SpellInfo const* gcd = sSpellMgr->GetSpellInfo(SPELL_EMPOWER_HARDCODED_GCD, DIFFICULTY_NONE))
            unitCaster->GetSpellHistory()->AddGlobalCooldown(gcd, Milliseconds(gcd->StartRecoveryTime));
    }

    if (result != SPELL_CAST_OK)
    {
        // on failure (or manual cancel) send TraitConfigCommitFailed to revert talent UI saved config selection
        if (m_caster->IsPlayer() && m_spellInfo->HasEffect(SPELL_EFFECT_CHANGE_ACTIVE_COMBAT_TRAIT_CONFIG))
            if (WorldPackets::Traits::TraitConfig const* traitConfig = std::any_cast<WorldPackets::Traits::TraitConfig>(&m_customArg))
                m_caster->ToPlayer()->SendDirectMessage(WorldPackets::Traits::TraitConfigCommitFailed(traitConfig->ID).Write());

        if (IsEmpowerSpell())
        {
            unitCaster->GetSpellHistory()->ResetCooldown(m_spellInfo->Id, true);
            RefundPower();
        }

        return;
    }

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

                    if (caster && !caster->HasItemCount(itemid, itemcount))
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
                    if (caster && !caster->HasCurrency(reagentsCurrency->CurrencyTypesID, reagentsCurrency->CurrencyCount))
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

void Spell::SendCastResult(SpellCastResult result, int32* param1 /*= nullptr*/, int32* param2 /*= nullptr*/) const
{
    if (result == SPELL_CAST_OK)
        return;

    Player const* receiver = m_caster->ToPlayer();
    if (m_spellInfo->HasAttribute(SPELL_ATTR7_REPORT_SPELL_FAILURE_TO_UNIT_TARGET))
        if (Player const* target = Object::ToPlayer(m_targets.GetUnitTarget()))
            receiver = target;

    if (!receiver)
        return;

    if (receiver->IsLoading())  // don't send cast results at loading time
        return;

    if (_triggeredCastFlags & TRIGGERED_DONT_REPORT_CAST_ERROR)
        result = SPELL_FAILED_DONT_REPORT;

    WorldPackets::Spells::CastFailed castFailed;
    castFailed.Visual = m_SpellVisual;
    FillSpellCastFailedArgs(castFailed, m_castId, m_spellInfo, result, m_customError, param1, param2, m_caster->ToPlayer());
    receiver->SendDirectMessage(castFailed.Write());
}

void Spell::SendPetCastResult(SpellCastResult result, int32* param1 /*= nullptr*/, int32* param2 /*= nullptr*/) const
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

void Spell::SendCastResult(Player* caster, SpellInfo const* spellInfo, SpellCastVisual spellVisual, ObjectGuid cast_count, SpellCastResult result, SpellCustomErrors customError /*= SPELL_CUSTOM_ERROR_NONE*/, int32* param1 /*= nullptr*/, int32* param2 /*= nullptr*/)
{
    if (result == SPELL_CAST_OK)
        return;

    WorldPackets::Spells::CastFailed packet;
    packet.Visual = spellVisual;
    FillSpellCastFailedArgs(packet, cast_count, spellInfo, result, customError, param1, param2, caster);
    caster->SendDirectMessage(packet.Write());
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

    TC_LOG_DEBUG("spells", "Sending SMSG_SPELL_START id={}", m_spellInfo->Id);

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

    if (m_spellInfo->HasAttribute(SPELL_ATTR8_HEAL_PREDICTION) && m_casttime && m_caster->IsUnit())
        castFlags |= CAST_FLAG_HEAL_PREDICTION;

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
    {
        for (SpellPowerCost const& cost : m_powerCost)
        {
            WorldPackets::Spells::SpellPowerData powerData;
            powerData.Type = cost.Power;
            powerData.Cost = ASSERT_NOTNULL(m_caster->ToUnit())->GetPower(cost.Power);
            castData.RemainingPower.push_back(powerData);
        }
    }

    if (castFlags & CAST_FLAG_RUNE_LIST) // rune cooldowns list
    {
        castData.RemainingRunes.emplace();

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
        castData.AmmoDisplayID = GetSpellCastDataAmmo();

    if (castFlags & CAST_FLAG_IMMUNITY)
    {
        castData.Immunities.School = schoolImmunityMask;
        castData.Immunities.Value = mechanicImmunityMask;
    }

    if (castFlags & CAST_FLAG_HEAL_PREDICTION)
        UpdateSpellHealPrediction(castData.Predict, false);

    m_caster->SendMessageToSet(packet.Write(), true);
}

void Spell::SendSpellGo()
{
    // not send invisible spell casting
    if (!IsNeedSendToClient())
        return;

    TC_LOG_DEBUG("spells", "Sending SMSG_SPELL_GO id={}", m_spellInfo->Id);

    uint32 castFlags = CAST_FLAG_UNKNOWN_9;

    // triggered spells with spell visual != 0
    if (((IsTriggered() && !m_spellInfo->IsAutoRepeatRangedSpell()) || m_triggeredByAuraSpell) && !m_fromClient)
        castFlags |= CAST_FLAG_PENDING;

    if (m_spellInfo->HasAttribute(SPELL_ATTR0_USES_RANGED_SLOT) || m_spellInfo->HasAttribute(SPELL_ATTR10_USES_RANGED_SLOT_COSMETIC_ONLY) || m_spellInfo->HasAttribute(SPELL_ATTR0_CU_NEEDS_AMMO_DATA))
        castFlags |= CAST_FLAG_PROJECTILE; // arrows/bullets visual

    if ((m_caster->GetTypeId() == TYPEID_PLAYER ||
        (m_caster->GetTypeId() == TYPEID_UNIT && m_caster->ToCreature()->IsPet()))
        && std::find_if(m_powerCost.begin(), m_powerCost.end(), [](SpellPowerCost const& cost) { return cost.Power != POWER_HEALTH; }) != m_powerCost.end())
        castFlags |= CAST_FLAG_POWER_LEFT_SELF;

    if ((m_caster->GetTypeId() == TYPEID_PLAYER)
        && (m_caster->ToPlayer()->GetClass() == CLASS_DEATH_KNIGHT)
        && HasPowerTypeCost(POWER_RUNES)
        && !(_triggeredCastFlags & TRIGGERED_IGNORE_POWER_AND_REAGENT_COST))
    {
        castFlags |= CAST_FLAG_NO_GCD; // not needed, but Blizzard sends it
        castFlags |= CAST_FLAG_RUNE_LIST; // rune cooldowns list
    }

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
    castData.Visual = m_SpellVisual;
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
            powerData.Cost = ASSERT_NOTNULL(m_caster->ToUnit())->GetPower(cost.Power);
            castData.RemainingPower.push_back(powerData);
        }
    }

    if (castFlags & CAST_FLAG_RUNE_LIST) // rune cooldowns list
    {
        castData.RemainingRunes.emplace();

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
        if (targetInfo.EffectMask == 0) // No effect apply - all immune add state
            // possibly SPELL_MISS_IMMUNE2 for this??
            targetInfo.MissCondition = SPELL_MISS_IMMUNE2;

        if (targetInfo.MissCondition == SPELL_MISS_NONE || (targetInfo.MissCondition == SPELL_MISS_BLOCK && !m_spellInfo->HasAttribute(SPELL_ATTR3_COMPLETELY_BLOCKED))) // Add only hits and partial blocked
        {
            data.HitTargets.push_back(targetInfo.TargetGUID);
            data.HitStatus.emplace_back(SPELL_MISS_NONE);

            m_channelTargetEffectMask |= targetInfo.EffectMask;
        }
        else // misses
        {
            data.MissTargets.push_back(targetInfo.TargetGUID);
            data.MissStatus.emplace_back(targetInfo.MissCondition, targetInfo.ReflectResult);
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

int32 Spell::GetSpellCastDataAmmo()
{
    uint32 ammoInventoryType = 0;
    uint32 ammoDisplayID = 0;

    if (Player const* playerCaster = m_caster->ToPlayer())
    {
        Item* pItem = playerCaster->GetWeaponForAttack(RANGED_ATTACK);
        if (pItem)
        {
            ammoInventoryType = pItem->GetTemplate()->GetInventoryType();
            if (ammoInventoryType == INVTYPE_THROWN)
                ammoDisplayID = pItem->GetDisplayId(playerCaster);
            else if (playerCaster->HasAura(46699))      // Requires No Ammo
            {
                ammoDisplayID = 5996;                   // normal arrow
                ammoInventoryType = INVTYPE_AMMO;
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

    return ammoDisplayID;
}

static std::pair<int32, SpellHealPredictionType> CalcPredictedHealing(SpellInfo const* spellInfo, Unit const* unitCaster, Unit* target, uint32 castItemEntry, int32 castItemLevel, Spell* spell, bool withPeriodic)
{
    int32 points = 0;
    SpellHealPredictionType type = SPELL_HEAL_PREDICTION_TARGET;
    for (SpellEffectInfo const& spellEffectInfo : spellInfo->GetEffects())
    {
        switch (spellEffectInfo.Effect)
        {
            case SPELL_EFFECT_HEAL:
            case SPELL_EFFECT_HEAL_PCT:
                points += unitCaster->SpellHealingBonusDone(target,
                    spellInfo, spellEffectInfo.CalcValue(unitCaster, nullptr, target, nullptr, castItemEntry, castItemLevel),
                    DIRECT_DAMAGE, spellEffectInfo, 1, spell);

                if (target != unitCaster && (spellEffectInfo.TargetA.GetTarget() == TARGET_UNIT_CASTER || spellEffectInfo.TargetB.GetTarget() == TARGET_UNIT_CASTER))
                    type = SPELL_HEAL_PREDICTION_TARGET_AND_CASTER;    // Binding Heal-like spells
                else if (spellEffectInfo.TargetA.GetCheckType() == TARGET_CHECK_PARTY || spellEffectInfo.TargetB.GetCheckType() == TARGET_CHECK_PARTY)
                    type = SPELL_HEAL_PREDICTION_TARGET_PARTY;         // Prayer of Healing (old party-wide targeting)
                break;
            default:
                break;
        }

        if (withPeriodic)
        {
            switch (spellEffectInfo.ApplyAuraName)
            {
                case SPELL_AURA_PERIODIC_HEAL:
                case SPELL_AURA_OBS_MOD_HEALTH:
                    points += unitCaster->SpellHealingBonusDone(target,
                        spellInfo, spellEffectInfo.CalcValue(unitCaster, nullptr, target, nullptr, castItemEntry, castItemLevel),
                        DIRECT_DAMAGE, spellEffectInfo, 1, spell) * spellInfo->GetMaxTicks();
                    break;
                case SPELL_AURA_PERIODIC_TRIGGER_SPELL:
                    if (SpellInfo const* triggered = sSpellMgr->GetSpellInfo(spellEffectInfo.TriggerSpell, spellInfo->Difficulty))
                        points += CalcPredictedHealing(triggered, unitCaster, target, castItemEntry, castItemLevel, nullptr, withPeriodic).first;
                    break;
                default:
                    break;
            }
        }
    }

    return { points, type };
}

void Spell::UpdateSpellHealPrediction(WorldPackets::Spells::SpellHealPrediction& healPrediction, bool withPeriodic)
{
    healPrediction.BeaconGUID = ObjectGuid::Empty;
    healPrediction.Points = 0;
    healPrediction.Type = SPELL_HEAL_PREDICTION_TARGET;

    Unit const* unitCaster = m_caster->ToUnit();

    if (Unit* target = m_targets.GetUnitTarget())
    {
        auto [points, type] = CalcPredictedHealing(m_spellInfo, unitCaster, target, m_castItemEntry, m_castItemLevel, this, withPeriodic);
        healPrediction.Points = points;
        healPrediction.Type = type;
    }

    static constexpr uint32 beaconSpellId = 53651;

    if (healPrediction.Type == SPELL_HEAL_PREDICTION_TARGET && unitCaster->HasAura(beaconSpellId, unitCaster->GetGUID()))
    {
        auto beacon = std::find_if(unitCaster->GetSingleCastAuras().begin(), unitCaster->GetSingleCastAuras().end(), [](Aura const* aura)
        {
            return aura->GetSpellInfo()->GetEffects().size() > EFFECT_1 && aura->GetSpellInfo()->GetEffect(EFFECT_1).TriggerSpell == beaconSpellId;
        });

        if (beacon != unitCaster->GetSingleCastAuras().end())
        {
            healPrediction.BeaconGUID = (*beacon)->GetOwner()->GetGUID();
            healPrediction.Type = SPELL_HEAL_PREDICTION_TARGET_AND_BEACON;
        }
    }
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

    m_caster->SendCombatLogMessage(&spellExecuteLog);

    _executeLogEffects.clear();
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

void Spell::ExecuteLogEffectTakeTargetPower(SpellEffectName effect, Unit* target, uint32 powerType, uint32 points, float amplitude)
{
    SpellLogEffectPowerDrainParams spellLogEffectPowerDrainParams;

    spellLogEffectPowerDrainParams.Victim = target->GetGUID();
    spellLogEffectPowerDrainParams.Points = points;
    spellLogEffectPowerDrainParams.PowerType = powerType;
    spellLogEffectPowerDrainParams.Amplitude = amplitude;

    GetExecuteLogEffectTargets(effect, &SpellLogEffect::PowerDrainTargets).push_back(spellLogEffectPowerDrainParams);
}

void Spell::ExecuteLogEffectExtraAttacks(SpellEffectName effect, Unit* victim, uint32 numAttacks)
{
    SpellLogEffectExtraAttacksParams spellLogEffectExtraAttacksParams;
    spellLogEffectExtraAttacksParams.Victim = victim->GetGUID();
    spellLogEffectExtraAttacksParams.NumAttacks = numAttacks;

    GetExecuteLogEffectTargets(effect, &SpellLogEffect::ExtraAttacksTargets).push_back(spellLogEffectExtraAttacksParams);
}

void Spell::SendSpellInterruptLog(Unit* victim, uint32 spellId)
{
    WorldPackets::CombatLog::SpellInterruptLog data;
    data.Caster = m_caster->GetGUID();
    data.Victim = victim->GetGUID();
    data.InterruptedSpellID = m_spellInfo->Id;
    data.SpellID = spellId;

    m_caster->SendMessageToSet(data.Write(), true);
}

void Spell::ExecuteLogEffectDurabilityDamage(SpellEffectName effect, Unit* victim, int32 itemId, int32 amount)
{
    SpellLogEffectDurabilityDamageParams spellLogEffectDurabilityDamageParams;
    spellLogEffectDurabilityDamageParams.Victim = victim->GetGUID();
    spellLogEffectDurabilityDamageParams.ItemID = itemId;
    spellLogEffectDurabilityDamageParams.Amount = amount;

    GetExecuteLogEffectTargets(effect, &SpellLogEffect::DurabilityDamageTargets).push_back(spellLogEffectDurabilityDamageParams);
}

void Spell::ExecuteLogEffectOpenLock(SpellEffectName effect, Object* obj)
{
    SpellLogEffectGenericVictimParams spellLogEffectGenericVictimParams;
    spellLogEffectGenericVictimParams.Victim = obj->GetGUID();

    GetExecuteLogEffectTargets(effect, &SpellLogEffect::GenericVictimTargets).push_back(spellLogEffectGenericVictimParams);
}

void Spell::ExecuteLogEffectCreateItem(SpellEffectName effect, uint32 entry)
{
    SpellLogEffectTradeSkillItemParams spellLogEffectTradeSkillItemParams;
    spellLogEffectTradeSkillItemParams.ItemID = entry;

    GetExecuteLogEffectTargets(effect, &SpellLogEffect::TradeSkillTargets).push_back(spellLogEffectTradeSkillItemParams);
}

void Spell::ExecuteLogEffectDestroyItem(SpellEffectName effect, uint32 entry)
{
    SpellLogEffectFeedPetParams spellLogEffectFeedPetParams;
    spellLogEffectFeedPetParams.ItemID = entry;

    GetExecuteLogEffectTargets(effect, &SpellLogEffect::FeedPetTargets).push_back(spellLogEffectFeedPetParams);
}

void Spell::ExecuteLogEffectSummonObject(SpellEffectName effect, WorldObject* obj)
{
    SpellLogEffectGenericVictimParams spellLogEffectGenericVictimParams;
    spellLogEffectGenericVictimParams.Victim = obj->GetGUID();

    GetExecuteLogEffectTargets(effect, &SpellLogEffect::GenericVictimTargets).push_back(spellLogEffectGenericVictimParams);
}

void Spell::ExecuteLogEffectUnsummonObject(SpellEffectName effect, WorldObject* obj)
{
    SpellLogEffectGenericVictimParams spellLogEffectGenericVictimParams;
    spellLogEffectGenericVictimParams.Victim = obj->GetGUID();

    GetExecuteLogEffectTargets(effect, &SpellLogEffect::GenericVictimTargets).push_back(spellLogEffectGenericVictimParams);
}

void Spell::ExecuteLogEffectResurrect(SpellEffectName effect, Unit* target)
{
    SpellLogEffectGenericVictimParams spellLogEffectGenericVictimParams;
    spellLogEffectGenericVictimParams.Victim = target->GetGUID();

    GetExecuteLogEffectTargets(effect, &SpellLogEffect::GenericVictimTargets).push_back(spellLogEffectGenericVictimParams);
}

void Spell::SendInterrupted(uint8 result)
{
    WorldPackets::Spells::SpellFailure failurePacket;
    failurePacket.CasterUnit = m_caster->GetGUID();
    failurePacket.CastID = m_castId;
    failurePacket.SpellID = m_spellInfo->Id;
    failurePacket.Visual = m_SpellVisual;
    failurePacket.Reason = result;
    m_caster->SendMessageToSet(failurePacket.Write(), true);

    WorldPackets::Spells::SpellFailedOther failedPacket;
    failedPacket.CasterUnit = m_caster->GetGUID();
    failedPacket.CastID = m_castId;
    failedPacket.SpellID = m_spellInfo->Id;
    failedPacket.Visual = m_SpellVisual;
    failedPacket.Reason = result;
    m_caster->SendMessageToSet(failedPacket.Write(), true);
}

void Spell::SendChannelUpdate(uint32 time, Optional<SpellCastResult> result)
{
    // GameObjects don't channel
    Unit* unitCaster = m_caster->ToUnit();
    if (!unitCaster)
        return;

    if (time == 0)
    {
        unitCaster->ClearChannelObjects();
        unitCaster->SetChannelSpellId(0);
        unitCaster->SetChannelVisual({});
        unitCaster->SetSpellEmpowerStage(-1);
    }

    if (IsEmpowerSpell())
    {
        WorldPackets::Spells::SpellEmpowerUpdate spellEmpowerUpdate;
        spellEmpowerUpdate.CastID = m_castId;
        spellEmpowerUpdate.CasterGUID = unitCaster->GetGUID();
        spellEmpowerUpdate.TimeRemaining = Milliseconds(time);
        if (time > 0)
            spellEmpowerUpdate.StageDurations.assign(m_empower->StageDurations.begin(), m_empower->StageDurations.end());
        else if (result && result != SPELL_CAST_OK)
            spellEmpowerUpdate.Status = 1;
        else
            spellEmpowerUpdate.Status = 4;

        unitCaster->SendMessageToSet(spellEmpowerUpdate.Write(), true);
    }
    else
    {
        WorldPackets::Spells::SpellChannelUpdate spellChannelUpdate;
        spellChannelUpdate.CasterGUID = unitCaster->GetGUID();
        spellChannelUpdate.TimeRemaining = time;
        unitCaster->SendMessageToSet(spellChannelUpdate.Write(), true);
    }
}

void Spell::SendChannelStart(uint32 duration)
{
    // GameObjects don't channel
    Unit* unitCaster = m_caster->ToUnit();
    if (!unitCaster)
        return;

    m_timer = duration;

    if (!m_UniqueTargetInfo.empty() || !m_UniqueGOTargetInfo.empty())
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

        for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
            if (spellEffectInfo.IsEffect(SPELL_EFFECT_APPLY_AURA) && (explicitTargetEffectMask & (1u << spellEffectInfo.EffectIndex)))
                channelAuraMask |= 1 << spellEffectInfo.EffectIndex;

        for (TargetInfo const& target : m_UniqueTargetInfo)
        {
            if (!(target.EffectMask & channelAuraMask))
                continue;

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

    auto setImmunitiesAndHealPrediction = [&](Optional<WorldPackets::Spells::SpellChannelStartInterruptImmunities>& interruptImmunities, Optional<WorldPackets::Spells::SpellTargetedHealPrediction>& healPrediction)
    {
        uint32 schoolImmunityMask = unitCaster->GetSchoolImmunityMask();
        uint32 mechanicImmunityMask = unitCaster->GetMechanicImmunityMask();

        if (schoolImmunityMask || mechanicImmunityMask)
        {
            interruptImmunities.emplace();
            interruptImmunities->SchoolImmunities = schoolImmunityMask;
            interruptImmunities->Immunities = mechanicImmunityMask;
        }

        if (m_spellInfo->HasAttribute(SPELL_ATTR8_HEAL_PREDICTION) && m_caster->IsUnit())
        {
            healPrediction.emplace();
            if (unitCaster->m_unitData->ChannelObjects.size() == 1 && unitCaster->m_unitData->ChannelObjects[0].IsUnit())
                healPrediction->TargetGUID = unitCaster->m_unitData->ChannelObjects[0];

            UpdateSpellHealPrediction(healPrediction->Predict, true);
        }
    };

    if (IsEmpowerSpell())
    {
        unitCaster->SetSpellEmpowerStage(0);

        WorldPackets::Spells::SpellEmpowerStart spellEmpowerStart;
        spellEmpowerStart.CastID = m_castId;
        spellEmpowerStart.CasterGUID = unitCaster->GetGUID();
        spellEmpowerStart.SpellID = m_spellInfo->Id;
        spellEmpowerStart.Visual = m_SpellVisual;
        spellEmpowerStart.EmpowerDuration = std::reduce(m_empower->StageDurations.begin(), m_empower->StageDurations.end());
        spellEmpowerStart.MinHoldTime = m_empower->MinHoldTime;
        spellEmpowerStart.HoldAtMaxTime = Milliseconds(SPELL_EMPOWER_HOLD_TIME_AT_MAX);
        spellEmpowerStart.Targets.assign(unitCaster->m_unitData->ChannelObjects.begin(), unitCaster->m_unitData->ChannelObjects.end());
        spellEmpowerStart.StageDurations.assign(m_empower->StageDurations.begin(), m_empower->StageDurations.end());
        setImmunitiesAndHealPrediction(spellEmpowerStart.InterruptImmunities, spellEmpowerStart.HealPrediction);

        unitCaster->SendMessageToSet(spellEmpowerStart.Write(), true);
    }
    else
    {
        WorldPackets::Spells::SpellChannelStart spellChannelStart;
        spellChannelStart.CasterGUID = unitCaster->GetGUID();
        spellChannelStart.SpellID = m_spellInfo->Id;
        spellChannelStart.Visual = m_SpellVisual;
        spellChannelStart.ChannelDuration = duration;
        setImmunitiesAndHealPrediction(spellChannelStart.InterruptImmunities, spellChannelStart.HealPrediction);

        unitCaster->SendMessageToSet(spellChannelStart.Write(), true);
    }
}

void Spell::SendResurrectRequest(Player* target)
{
    // get resurrector name for creature resurrections, otherwise packet will be not accepted
    // for player resurrections the name is looked up by guid
    std::string sentName;
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        sentName = m_caster->GetNameForLocaleIdx(target->GetSession()->GetSessionDbLocaleIndex());

    WorldPackets::Spells::ResurrectRequest resurrectRequest;
    resurrectRequest.ResurrectOffererGUID =  m_caster->GetGUID();
    resurrectRequest.ResurrectOffererVirtualRealmAddress = GetVirtualRealmAddress();
    resurrectRequest.Name = sentName;
    resurrectRequest.Sickness = m_caster->IsUnit() && m_caster->ToUnit()->IsSpiritHealer(); // "you'll be afflicted with resurrection sickness"
    resurrectRequest.UseTimer = !m_spellInfo->HasAttribute(SPELL_ATTR3_NO_RES_TIMER);
    if (Pet* pet = target->GetPet())
        if (CharmInfo* charmInfo = pet->GetCharmInfo())
            resurrectRequest.PetNumber = charmInfo->GetPetNumber();

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
        TC_LOG_ERROR("spells", "Cast item has no item prototype {}", m_CastItem->GetGUID().ToString());
        return;
    }

    bool expendable = false;
    bool withoutCharges = false;

    for (ItemEffectEntry const* itemEffect : m_CastItem->GetEffects())
    {
        if (itemEffect->LegacySlotIndex >= m_CastItem->m_itemData->SpellCharges.size())
            continue;

        // item has limited charges
        if (itemEffect->Charges)
        {
            if (itemEffect->Charges < 0)
                expendable = true;

            int32 charges = m_CastItem->GetSpellCharges(itemEffect->LegacySlotIndex);

            // item has charges left for this slot
            if (charges && itemEffect->SpellID == int32(m_spellInfo->Id))
            {
                (charges > 0) ? --charges : ++charges;  // abs(charges) less at 1 after use
                if (proto->GetMaxStackSize() == 1)
                    m_CastItem->SetSpellCharges(itemEffect->LegacySlotIndex, charges);
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

    bool hit = true;
    if (unitCaster->GetTypeId() == TYPEID_PLAYER)
    {
        if (m_spellInfo->HasAttribute(SPELL_ATTR1_DISCOUNT_POWER_ON_MISS))
        {
            ObjectGuid targetGUID = m_targets.GetUnitTargetGUID();
            if (!targetGUID.IsEmpty())
                hit = std::ranges::any_of(m_UniqueTargetInfo, [&](TargetInfo const& targetInfo) { return targetInfo.TargetGUID == targetGUID && targetInfo.MissCondition == SPELL_MISS_NONE; });
        }
    }

    for (SpellPowerCost& cost : m_powerCost)
    {
        if (!hit)
        {
            //lower spell cost on fail (by talent aura)
            if (Player* modOwner = unitCaster->GetSpellModOwner())
                modOwner->ApplySpellMod(m_spellInfo, SpellModOp::PowerCostOnMiss, cost.Amount);
        }

        if (cost.Power == POWER_RUNES)
        {
            TakeRunePower(hit);
            continue;
        }

        if (!cost.Amount)
            continue;

        // health as power used
        if (cost.Power == POWER_HEALTH)
        {
            unitCaster->ModifyHealth(-cost.Amount);
            continue;
        }

        unitCaster->ModifyPower(cost.Power, -cost.Amount);
    }
}

void Spell::RefundPower()
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

    for (SpellPowerCost& cost : m_powerCost)
    {
        if (cost.Power == POWER_RUNES)
        {
            RefundRunePower();
            continue;
        }

        if (!cost.Amount)
            continue;

        // health as power used
        if (cost.Power == POWER_HEALTH)
        {
            unitCaster->ModifyHealth(cost.Amount);
            continue;
        }

        unitCaster->ModifyPower(cost.Power, cost.Amount);
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
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER || m_caster->ToPlayer()->GetClass() != CLASS_DEATH_KNIGHT)
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

void Spell::RefundRunePower()
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER || m_caster->ToPlayer()->GetClass() != CLASS_DEATH_KNIGHT)
        return;

    Player* player = m_caster->ToPlayer();

    // restore old rune state
    for (int32 i = 0; i < player->GetMaxPower(POWER_RUNES); ++i)
        if (m_runesState & (1 << i))
            player->SetRuneCooldown(i, 0);
}

void Spell::TakeReagents()
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    // do not take reagents for these item casts
    if (m_CastItem && m_CastItem->GetTemplate()->HasFlag(ITEM_FLAG_NO_REAGENT_COST))
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
        if (m_CastItem && m_CastItem->GetEntry() == itemid)
        {
            for (ItemEffectEntry const* itemEffect : m_CastItem->GetEffects())
            {
                if (itemEffect->LegacySlotIndex >= m_CastItem->m_itemData->SpellCharges.size())
                    continue;

                // CastItem will be used up and does not count as reagent
                int32 charges = m_CastItem->GetSpellCharges(itemEffect->LegacySlotIndex);
                if (itemEffect->Charges < 0 && abs(charges) < 2)
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

    for (SpellReagentsCurrencyEntry const* reagentsCurrency : m_spellInfo->ReagentsCurrency)
        p_caster->RemoveCurrency(reagentsCurrency->CurrencyTypesID, reagentsCurrency->CurrencyCount, CurrencyDestroyReason::Spell);
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

    damage = CalculateDamage(spellEffectInfo, unitTarget, &variance);

    bool preventDefault = CallScriptEffectHandlers(spellEffectInfo.EffectIndex, mode);

    if (!preventDefault)
        (this->*SpellEffectHandlers[spellEffectInfo.Effect].Value)();
}

/*static*/ Spell const* Spell::ExtractSpellFromEvent(BasicEvent* event)
{
    if (SpellEvent* spellEvent = dynamic_cast<SpellEvent*>(event))
        return spellEvent->GetSpell();

    return nullptr;
}

SpellCastResult Spell::CheckCast(bool strict, int32* param1 /*= nullptr*/, int32* param2 /*= nullptr*/)
{
    // check death state
    if (m_caster->ToUnit() && !m_caster->ToUnit()->IsAlive() && !m_spellInfo->IsPassive() && !(m_spellInfo->HasAttribute(SPELL_ATTR0_ALLOW_CAST_WHILE_DEAD) || (IsTriggered() && !m_triggeredByAuraSpell)))
        return SPELL_FAILED_CASTER_DEAD;

    // Prevent cheating in case the player has an immunity effect and tries to interact with a non-allowed gameobject. The error message is handled by the client so we don't report anything here
    if (m_caster->ToPlayer() && m_targets.GetGOTarget())
    {
        if (m_targets.GetGOTarget()->GetGOInfo()->GetNoDamageImmune() && m_caster->ToUnit()->HasUnitFlag(UNIT_FLAG_IMMUNE))
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
                // These two auras check SpellFamilyName defined by db2 class data instead of current spell SpellFamilyName
                if (playerCaster->HasAuraType(SPELL_AURA_DISABLE_CASTING_EXCEPT_ABILITIES)
                    && !m_spellInfo->HasAttribute(SPELL_ATTR0_USES_RANGED_SLOT)
                    && !m_spellInfo->HasEffect(SPELL_EFFECT_ATTACK)
                    && !m_spellInfo->HasAttribute(SPELL_ATTR12_IGNORE_CASTING_DISABLED)
                    && !playerCaster->HasAuraTypeWithFamilyFlags(SPELL_AURA_DISABLE_CASTING_EXCEPT_ABILITIES, sChrClassesStore.AssertEntry(playerCaster->GetClass())->SpellClassSet, m_spellInfo->SpellFamilyFlags))
                        return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

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

            // check if we are using a potion in combat for the 2nd+ time. Cooldown is added only after caster gets out of combat
            if (!IsIgnoringCooldowns() && playerCaster->GetLastPotionId() && m_CastItem && (m_CastItem->IsPotion() || m_spellInfo->IsCooldownStartedOnEvent()))
                return SPELL_FAILED_NOT_READY;
        }

        if (!IsIgnoringCooldowns() && m_caster->ToUnit() && (!m_spellInfo->HasAttribute(SPELL_ATTR12_START_COOLDOWN_ON_CAST_START) || strict))
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

    if (m_spellInfo->HasAttribute(SPELL_ATTR7_DEBUG_SPELL) && m_caster->IsUnit() && !m_caster->ToUnit()->HasUnitFlag2(UNIT_FLAG2_ALLOW_CHEAT_SPELLS))
    {
        m_customError = SPELL_CUSTOM_ERROR_GM_ONLY;
        return SPELL_FAILED_CUSTOM_ERROR;
    }

    if (m_spellInfo->HasAttribute(SPELL_ATTR8_ONLY_PLAYERS_CAN_CAST_THIS_SPELL) && !m_caster->IsPlayer())
        return SPELL_FAILED_CASTER_AURASTATE;

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
            m_caster->IsOutdoors())
            return SPELL_FAILED_ONLY_INDOORS;
    }

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

            if (m_spellInfo->CasterAuraType && !unitCaster->HasAuraType(m_spellInfo->CasterAuraType))
                return SPELL_FAILED_CASTER_AURASTATE;
            if (m_spellInfo->ExcludeCasterAuraType && unitCaster->HasAuraType(m_spellInfo->ExcludeCasterAuraType))
                return SPELL_FAILED_CASTER_AURASTATE;

            if (unitCaster->IsInCombat() && !m_spellInfo->CanBeUsedInCombat(unitCaster))
                return SPELL_FAILED_AFFECTING_COMBAT;

            if (m_spellInfo->HasAttribute(SPELL_ATTR9_ONLY_WHEN_ILLEGALLY_MOUNTED))
            {
                bool hasInvalidMountAura = std::ranges::any_of(unitCaster->GetAuraEffectsByType(SPELL_AURA_MOUNTED), [unitCaster](AuraEffect const* mountEffect)
                {
                    uint32 mountType = mountEffect->GetSpellEffectInfo().MiscValueB;
                    if (MountEntry const* mountEntry = sDB2Manager.GetMount(mountEffect->GetId()))
                        mountType = mountEntry->MountTypeID;

                    MountCapabilityEntry const* mountCapability = unitCaster->GetMountCapability(mountType);
                    return !mountCapability || mountCapability->ID != uint32(mountEffect->GetAmount());
                });

                if (!hasInvalidMountAura)
                    return SPELL_FAILED_ONLY_MOUNTED;
            }
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

        // If it's not a melee spell, check if vision is obscured by SPELL_AURA_INTERFERE_TARGETTING
        if (m_spellInfo->DmgClass != SPELL_DAMAGE_CLASS_MELEE)
        {
            if (Unit const* unitCaster = m_caster->ToUnit())
            {
                for (AuraEffect const* auraEff : unitCaster->GetAuraEffectsByType(SPELL_AURA_INTERFERE_TARGETTING))
                    if (!unitCaster->IsFriendlyTo(auraEff->GetCaster()) && !target->HasAura(auraEff->GetId(), auraEff->GetCasterGUID()))
                        return SPELL_FAILED_VISION_OBSCURED;

                for (AuraEffect const* auraEff : target->GetAuraEffectsByType(SPELL_AURA_INTERFERE_TARGETTING))
                    if (!unitCaster->IsFriendlyTo(auraEff->GetCaster()) && (!target->HasAura(auraEff->GetId(), auraEff->GetCasterGUID()) || !unitCaster->HasAura(auraEff->GetId(), auraEff->GetCasterGUID())))
                        return SPELL_FAILED_VISION_OBSCURED;
            }
        }

        if (target != m_caster)
        {
            // Must be behind the target
            if ((m_spellInfo->HasAttribute(SPELL_ATTR0_CU_REQ_CASTER_BEHIND_TARGET)) && target->HasInArc(static_cast<float>(M_PI), m_caster))
                return SPELL_FAILED_NOT_BEHIND;

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

                if (!IsWithinLOS(losTarget, target, true, VMAP::ModelIgnoreFlags::M2))
                    return SPELL_FAILED_LINE_OF_SIGHT;
            }
        }
    }

    // Check for line of sight for spells with dest
    if (m_targets.HasDst())
        if (!IsWithinLOS(m_caster, *m_targets.GetDstPos(), VMAP::ModelIgnoreFlags::M2))
            return SPELL_FAILED_LINE_OF_SIGHT;

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
        if (!m_caster->IsUnit() || !m_caster->ToUnit()->HasAuraTypeWithMiscvalue(SPELL_AURA_PROVIDE_SPELL_FOCUS, m_spellInfo->RequiresSpellFocus))
        {
            focusObject = SearchSpellFocus();
            if (!focusObject)
                return SPELL_FAILED_REQUIRES_SPELL_FOCUS;
        }
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

    uint32 approximateAuraEffectMask = 0;
    uint32 nonAuraEffectMask = 0;
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
    {
        // for effects of spells that have only one target
        switch (spellEffectInfo.Effect)
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
                if (spellEffectInfo.TargetA.GetTarget() != TARGET_UNIT_PET)
                    break;

                Pet* pet = m_caster->ToPlayer()->GetPet();
                if (!pet)
                    return SPELL_FAILED_NO_PET;

                SpellInfo const* learn_spellproto = sSpellMgr->GetSpellInfo(spellEffectInfo.TriggerSpell, DIFFICULTY_NONE);
                if (!learn_spellproto)
                    return SPELL_FAILED_NOT_KNOWN;

                if (m_spellInfo->SpellLevel > pet->GetLevel())
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

                    SpellInfo const* learn_spellproto = sSpellMgr->GetSpellInfo(spellEffectInfo.TriggerSpell, DIFFICULTY_NONE);

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
                    return SPELL_FAILED_GLYPH_NO_SPEC;

                Player* caster = m_caster->ToPlayer();
                if (!caster->HasSpell(m_misc.SpellId))
                    return SPELL_FAILED_NOT_KNOWN;

                if (uint32 glyphId = spellEffectInfo.MiscValue)
                {
                    GlyphPropertiesEntry const* glyphProperties = sGlyphPropertiesStore.LookupEntry(glyphId);
                    if (!glyphProperties)
                        return SPELL_FAILED_INVALID_GLYPH;

                    std::vector<uint32> const* glyphBindableSpells = sDB2Manager.GetGlyphBindableSpells(glyphId);
                    if (!glyphBindableSpells)
                        return SPELL_FAILED_INVALID_GLYPH;

                    if (std::find(glyphBindableSpells->begin(), glyphBindableSpells->end(), m_misc.SpellId) == glyphBindableSpells->end())
                        return SPELL_FAILED_INVALID_GLYPH;

                    if (std::vector<ChrSpecialization> const* glyphRequiredSpecs = sDB2Manager.GetGlyphRequiredSpecs(glyphId))
                    {
                        if (caster->GetPrimarySpecialization() == ChrSpecialization::None)
                            return SPELL_FAILED_GLYPH_NO_SPEC;

                        if (std::find(glyphRequiredSpecs->begin(), glyphRequiredSpecs->end(), caster->GetPrimarySpecialization()) == glyphRequiredSpecs->end())
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

                if (foodItem->GetTemplate()->GetBaseItemLevel() + 30 <= pet->GetLevel())
                   return SPELL_FAILED_FOOD_LOWLEVEL;

                if (m_caster->ToPlayer()->IsInCombat() || pet->IsInCombat())
                    return SPELL_FAILED_AFFECTING_COMBAT;

                break;
            }
            case SPELL_EFFECT_CHARGE:
            {
                Unit* unitCaster = m_caster->ToUnit();
                if (!unitCaster)
                    return SPELL_FAILED_BAD_TARGETS;

                if (!(_triggeredCastFlags & TRIGGERED_IGNORE_CASTER_AURAS) && unitCaster->HasUnitState(UNIT_STATE_ROOT))
                    return SPELL_FAILED_ROOTED;

                if (GetSpellInfo()->NeedsExplicitUnitTarget())
                {
                    Unit* target = m_targets.GetUnitTarget();
                    if (!target)
                        return SPELL_FAILED_DONT_REPORT;

                    // first we must check to see if the target is in LoS. A path can usually be built but LoS matters for charge spells
                    if (!IsWithinLOS(unitCaster, target, true, VMAP::ModelIgnoreFlags::Nothing)) //Do full LoS/Path check. Don't exclude m2
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
                Loot* loot = creature->GetLootForPlayer(m_caster->ToPlayer());
                if (loot && (!loot->isLooted() || loot->loot_type == LOOT_SKINNING))
                    return SPELL_FAILED_TARGET_NOT_LOOTED;

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
                        pTempItem = pTrade->GetTraderData()->GetItem(TRADE_SLOT_NONTRADED);
                }
                else if (m_targets.GetTargetMask() & TARGET_FLAG_ITEM)
                    pTempItem = m_caster->ToPlayer()->GetItemByGuid(m_targets.GetItemTargetGUID());

                // we need a go target, or an openable item target in case of TARGET_GAMEOBJECT_ITEM_TARGET
                if (spellEffectInfo.TargetA.GetTarget() == TARGET_GAMEOBJECT_ITEM_TARGET &&
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

                    if (go->GetGOInfo()->GetNotInCombat() && m_caster->ToUnit()->IsInCombat())
                        return SPELL_FAILED_AFFECTING_COMBAT;
                }
                else if (Item* itm = m_targets.GetItemTarget())
                    lockId = itm->GetTemplate()->GetLockID();

                SkillType skillId = SKILL_NONE;
                int32 reqSkillValue = 0;
                int32 skillValue = 0;

                // check lock compatibility
                SpellCastResult res = CanOpenLock(spellEffectInfo, lockId, skillId, reqSkillValue, skillValue);
                if (res != SPELL_CAST_OK)
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

                PetStable const* petStable = playerCaster->GetPetStable();
                auto deadPetItr = std::find_if(petStable->ActivePets.begin(), petStable->ActivePets.end(), [](Optional<PetStable::PetInfo> const& petInfo)
                {
                    return petInfo && !petInfo->Health;
                });

                if (deadPetItr == petStable->ActivePets.end())
                    return SPELL_FAILED_BAD_TARGETS;

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
                        if (!m_spellInfo->HasAttribute(SPELL_ATTR1_DISMISS_PET_FIRST) && !unitCaster->GetPetGUID().IsEmpty())
                            return SPELL_FAILED_ALREADY_HAVE_SUMMON;
                        [[fallthrough]]; // check both GetPetGUID() and GetCharmGUID for SUMMON_CATEGORY_PET
                    case SUMMON_CATEGORY_PUPPET:
                        if (!unitCaster->GetCharmedGUID().IsEmpty())
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
                    if (!m_spellInfo->HasAttribute(SPELL_ATTR1_DISMISS_PET_FIRST) && !m_targets.GetUnitTarget()->GetPetGUID().IsEmpty())
                        return SPELL_FAILED_ALREADY_HAVE_SUMMON;
                }
                break;
            }
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
                                pet->CastSpell(pet, PET_SUMMONING_DISORIENTATION, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                                    .SetOriginalCaster(pet->GetGUID())
                                    .SetTriggeringSpell(this));
                    }
                    else if (!m_spellInfo->HasAttribute(SPELL_ATTR1_DISMISS_PET_FIRST))
                        return SPELL_FAILED_ALREADY_HAVE_SUMMON;
                }

                if (!unitCaster->GetCharmedGUID().IsEmpty())
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
                            CreatureDifficulty const* creatureDifficulty = creatureInfo->GetDifficulty(DIFFICULTY_NONE);
                            if (!creatureInfo || !creatureInfo->IsTameable(playerCaster->CanTameExoticPets(), creatureDifficulty))
                            {
                                // if problem in exotic pet
                                if (creatureInfo && creatureInfo->IsTameable(true, creatureDifficulty))
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

                Player* target = ObjectAccessor::FindPlayer(m_caster->ToPlayer()->GetTarget());
                if (!target || m_caster->ToPlayer() == target || (!target->IsInSameRaidWith(m_caster->ToPlayer()) && m_spellInfo->Id != 48955)) // refer-a-friend spell
                    return SPELL_FAILED_BAD_TARGETS;

                if (target->HasSummonPending())
                    return SPELL_FAILED_SUMMON_PENDING;

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
            {
                ChrSpecializationEntry const* spec = sChrSpecializationStore.LookupEntry(m_misc.SpecializationId);
                Player* player = m_caster->ToPlayer();
                if (!player)
                    return SPELL_FAILED_TARGET_NOT_PLAYER;

                if (!spec || (spec->ClassID != player->GetClass() && !spec->IsPetSpecialization()))
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
                break;
            }
            case SPELL_EFFECT_CREATE_HEIRLOOM_ITEM:
            {
                if (!m_caster->IsPlayer())
                    return SPELL_FAILED_BAD_TARGETS;

                if (!m_caster->ToPlayer()->GetSession()->GetCollectionMgr()->HasHeirloom(m_misc.Raw.Data[0]))
                    return SPELL_FAILED_BAD_TARGETS;

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

                if (Creature* creature = m_targets.GetUnitTarget()->ToCreature())
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
                                auto qualityItr = std::lower_bound(sBattlePetBreedQualityStore.begin(), sBattlePetBreedQualityStore.end(), spellEffectInfo.CalcBaseValue(m_caster, creature, m_castItemEntry, m_castItemLevel), [](BattlePetBreedQualityEntry const* a1, int32 selector)
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

                if (!pet->GetCharmerGUID().IsEmpty())
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

                if (!unitCaster->GetCharmerGUID().IsEmpty())
                    return SPELL_FAILED_CHARMED;

                if (spellEffectInfo.ApplyAuraName == SPELL_AURA_MOD_CHARM
                    || spellEffectInfo.ApplyAuraName == SPELL_AURA_MOD_POSSESS)
                {
                    if (!m_spellInfo->HasAttribute(SPELL_ATTR1_DISMISS_PET_FIRST) && !unitCaster->GetPetGUID().IsEmpty())
                        return SPELL_FAILED_ALREADY_HAVE_SUMMON;

                    if (!unitCaster->GetCharmedGUID().IsEmpty())
                        return SPELL_FAILED_ALREADY_HAVE_CHARM;
                }

                if (Unit* target = m_targets.GetUnitTarget())
                {
                    if (target->GetTypeId() == TYPEID_UNIT && target->IsVehicle())
                        return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

                    if (target->IsMounted())
                        return SPELL_FAILED_CANT_BE_CHARMED;

                    if (!target->GetCharmerGUID().IsEmpty())
                        return SPELL_FAILED_ALREADY_HAVE_CHARM;

                    if (target->GetOwner() && target->GetOwner()->GetTypeId() == TYPEID_PLAYER)
                        return SPELL_FAILED_TARGET_IS_PLAYER_CONTROLLED;

                    int32 value = CalculateDamage(spellEffectInfo, target);
                    if (value && int32(target->GetLevelForTarget(m_caster)) > value)
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
                    Battlefield* Bf = sBattlefieldMgr->GetBattlefieldToZoneId(m_originalCaster->GetMap(), m_originalCaster->GetZoneId());
                    if (Bf && !Bf->CanFlyIn())
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

        if (m_targets.GetItemTargetGUID() != ObjectGuid::TradeItem)
            return SPELL_FAILED_BAD_TARGETS;

        if (!IsTriggered())
            if (my_trade->GetSpell())
                return SPELL_FAILED_ITEM_ALREADY_ENCHANTED;
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
        if (unitCaster && unitCaster->GetCharmInfo() && unitCaster->GetSpellHistory()->HasGlobalCooldown(m_spellInfo))
            return SPELL_FAILED_NOT_READY;

    return CheckCast(true);
}

SpellCastResult Spell::CheckCasterAuras(int32* param1) const
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
    uint32 const unitflag = unitCaster->m_unitData->Flags;

    // this check should only be done when player does cast directly
    // (ie not when it's called from a script) Breaks for example PlayerAI when charmed
    /*
    if (!unitCaster->GetCharmerGUID().IsEmpty())
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
    else if (unitCaster->IsSilenced(m_spellSchoolMask) && m_spellInfo->PreventionType & SPELL_PREVENTION_TYPE_SILENCE && !CheckSpellCancelsSilence(param1))
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

    // Attr must make flag drop spell totally immune from all effects
    if (result != SPELL_CAST_OK)
        return (param1 && *param1) ? SPELL_FAILED_PREVENTED_BY_MECHANIC : result;

    return SPELL_CAST_OK;
}

bool Spell::CheckSpellCancelsAuraEffect(AuraType auraType, int32* param1) const
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
        if (m_spellInfo->SpellCancelsAuraEffect(aurEff))
            continue;

        if (param1)
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

bool Spell::CheckSpellCancelsPacify(int32* param1) const
{
    return CheckSpellCancelsAuraEffect(SPELL_AURA_MOD_PACIFY, param1) &&
        CheckSpellCancelsAuraEffect(SPELL_AURA_MOD_PACIFY_SILENCE, param1);
}

bool Spell::CheckSpellCancelsFear(int32* param1) const
{
    return CheckSpellCancelsAuraEffect(SPELL_AURA_MOD_FEAR, param1);
}

bool Spell::CheckSpellCancelsConfuse(int32* param1) const
{
    return CheckSpellCancelsAuraEffect(SPELL_AURA_MOD_CONFUSE, param1);
}

bool Spell::CheckSpellCancelsNoActions(int32* param1) const
{
    return CheckSpellCancelsAuraEffect(SPELL_AURA_MOD_NO_ACTIONS, param1);
}

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
                    if (abs(spellEffectInfo.CalcBaseValue(m_caster, target, 0, -1)) <= abs((*auraIt)->GetAmount()))
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

    auto [minRange, maxRange] = GetMinMaxRange(strict);

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

    if (m_spellInfo->HasAttribute(SPELL_ATTR0_USES_RANGED_SLOT) && m_caster->GetTypeId() == TYPEID_PLAYER)
        if (Item* ranged = m_caster->ToPlayer()->GetWeaponForAttack(RANGED_ATTACK, true))
            maxRange *= ranged->GetTemplate()->GetRangedModRange() * 0.01f;

    if (Player* modOwner = m_caster->GetSpellModOwner())
        modOwner->ApplySpellMod(m_spellInfo, SpellModOp::Range, maxRange, const_cast<Spell*>(this));

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

    for (SpellPowerCost const& cost : m_powerCost)
    {
        // health as power used - need check health amount
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

        //check rune cost only if a spell has PowerType == POWER_RUNES
        if (cost.Power == POWER_RUNES)
        {
            SpellCastResult failReason = CheckRuneCost();
            if (failReason != SPELL_CAST_OK)
                return failReason;
        }

        // Check power amount
        if (int32(unitCaster->GetPower(cost.Power)) < cost.Amount)
            return SPELL_FAILED_NO_POWER;
    }

    return SPELL_CAST_OK;
}

SpellCastResult Spell::CheckItems(int32* param1 /*= nullptr*/, int32* param2 /*= nullptr*/) const
{
    Player* player = m_caster->ToPlayer();
    if (!player)
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

        for (ItemEffectEntry const* itemEffect : m_CastItem->GetEffects())
            if (itemEffect->LegacySlotIndex < m_CastItem->m_itemData->SpellCharges.size() && itemEffect->Charges)
                if (m_CastItem->GetSpellCharges(itemEffect->LegacySlotIndex) == 0)
                    return SPELL_FAILED_NO_CHARGES_REMAIN;

        // consumable cast item checks
        if (proto->GetClass() == ITEM_CLASS_CONSUMABLE && m_targets.GetUnitTarget())
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

                    for (ItemEffectEntry const* itemEffect : m_CastItem->GetEffects())
                    {
                        if (itemEffect->LegacySlotIndex >= m_CastItem->m_itemData->SpellCharges.size())
                            continue;

                        // CastItem will be used up and does not count as reagent
                        int32 charges = m_CastItem->GetSpellCharges(itemEffect->LegacySlotIndex);
                        if (itemEffect->Charges < 0 && abs(charges) < 2)
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
                        if (target->ToPlayer()->GetFreeInventorySlotCount(ItemSearchLocation::Inventory) == 0)
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
                    uint32 enchant_id = spellEffectInfo.MiscValue;
                    SpellItemEnchantmentEntry const* enchantEntry = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
                    if (!enchantEntry)
                        return SPELL_FAILED_ERROR;
                    if (enchantEntry->GetFlags().HasFlag(SpellItemEnchantmentFlags::Soulbound))
                        return SPELL_FAILED_NOT_TRADEABLE;
                }

                // Apply item level restriction if the enchanting spell has max level restrition set
                if (m_CastItem && m_spellInfo->MaxLevel > 0)
                {
                    if (item->GetTemplate()->GetBaseItemLevel() < (uint32)m_CastItem->GetTemplate()->GetBaseRequiredLevel())
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
                Item const* item = m_targets.GetItemTarget();
                if (!item)
                    return SPELL_FAILED_CANT_BE_SALVAGED;

                // prevent disenchanting in trade slot
                if (item->GetOwnerGUID() != player->GetGUID())
                    return SPELL_FAILED_CANT_BE_SALVAGED;

                ItemTemplate const* itemProto = item->GetTemplate();
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
                    {
                        uint32 const ammo = item->GetEntry();
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
                Item const* item = m_targets.GetItemTarget();
                if (!item)
                    return SPELL_FAILED_AZERITE_EMPOWERED_ONLY;

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
        }

        if (m_spellInfo->HasAttribute(SPELL_ATTR3_REQUIRES_OFF_HAND_WEAPON))
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
    Unit* unitCaster = m_caster->ToUnit();
    if (!unitCaster)
        return;

    if (IsDelayableNoMore())                                 // Spells may only be delayed twice
        return;

    //check pushback reduce
    int32 delaytime = 500;                                  // spellcasting delay is normally 500ms

    int32 delayReduce = 100;                                // must be initialized to 100 for percent modifiers
    if (Player* player = unitCaster->GetSpellModOwner())
        player->ApplySpellMod(m_spellInfo, SpellModOp::ResistPushback, delayReduce, this);
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
    Unit* unitCaster = m_caster->ToUnit();
    if (!unitCaster)
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
    if (Player* player = unitCaster->GetSpellModOwner())
        player->ApplySpellMod(m_spellInfo, SpellModOp::ResistPushback, delayReduce, this);
    delayReduce += unitCaster->GetTotalAuraModifier(SPELL_AURA_REDUCE_PUSHBACK) - 100;
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
            if (Unit* unit = (unitCaster->GetGUID() == targetInfo.TargetGUID) ? unitCaster : ObjectAccessor::GetUnit(*unitCaster, targetInfo.TargetGUID))
                unit->DelayOwnedAuras(m_spellInfo->Id, m_originalCasterGUID, delaytime);

    // partially interrupt persistent area auras
    if (DynamicObject* dynObj = unitCaster->GetDynObject(m_spellInfo->Id))
        dynObj->Delay(delaytime);

    SendChannelUpdate(m_timer);
}

bool Spell::HasPowerTypeCost(Powers power) const
{
    return GetPowerTypeCostAmount(power).has_value();
}

Optional<int32> Spell::GetPowerTypeCostAmount(Powers power) const
{
    auto itr = std::find_if(m_powerCost.cbegin(), m_powerCost.cend(), [power](SpellPowerCost const& cost)
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
    else
    {
        m_originalCaster = ObjectAccessor::GetUnit(*m_caster, m_originalCasterGUID);
        if (m_originalCaster && !m_originalCaster->IsInWorld())
            m_originalCaster = nullptr;
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

Difficulty Spell::GetCastDifficulty() const
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
                if (IsWithinLOS(m_caster, target, true, VMAP::ModelIgnoreFlags::M2) && target->HasUnitFlag(UNIT_FLAG_SKINNABLE))
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

            if (!IsWithinLOS(m_caster, corpse, true, VMAP::ModelIgnoreFlags::M2))
                return false;

            break;
        }
        default:
        {
            if (!losPosition || m_spellInfo->HasAttribute(SPELL_ATTR5_ALWAYS_AOE_LINE_OF_SIGHT) || spellEffectInfo.EffectAttributes.HasFlag(SpellEffectAttributes::AlwaysAoeLineOfSight))
            {
                // Get GO cast coordinates if original caster -> GO
                WorldObject* caster = nullptr;
                if (m_originalCasterGUID.IsGameObject())
                    caster = m_caster->GetMap()->GetGameObject(m_originalCasterGUID);
                if (!caster)
                    caster = m_caster;

                if (target != m_caster && !IsWithinLOS(caster, target, true, VMAP::ModelIgnoreFlags::M2))
                    return false;
            }

            if (losPosition)
                if (!IsWithinLOS(target, *losPosition, VMAP::ModelIgnoreFlags::M2))
                    return false;
        }
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
    }

    return true;
}

bool Spell::CheckEffectTarget(Item const* /*target*/, SpellEffectInfo const& /*spellEffectInfo*/) const
{
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
    return ((_triggeredCastFlags & TRIGGERED_IGNORE_SET_FACING) || (m_spellInfo->IsChanneled() && !m_spellInfo->HasAttribute(SPELL_ATTR1_TRACK_TARGET_IN_CHANNEL)));
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
    if (IsTriggered() || m_spellInfo->HasAttribute(SPELL_ATTR2_DO_NOT_RESET_COMBAT_TIMERS))
        return false;

    if (!m_casttime && m_spellInfo->HasAttribute(SPELL_ATTR6_DOESNT_RESET_SWING_TIMER_IF_INSTANT))
        return false;

    return true;
}

bool Spell::IsPositive() const
{
    return m_spellInfo->IsPositive() && (!m_triggeredByAuraSpell || m_triggeredByAuraSpell->IsPositive());
}

void Spell::SetEmpowerReleasedByClient(bool release)
{
    m_empower->IsReleasedByClient = release;
}

bool Spell::CanReleaseEmpowerSpell() const
{
    if (m_empower->IsReleased)
        return false;

    if (!m_empower->IsReleasedByClient && m_timer)
        return false;

    Milliseconds passedTime(m_channeledDuration - m_timer);
    return passedTime >= m_empower->MinHoldTime;
}

bool Spell::IsNeedSendToClient() const
{
    return m_SpellVisual.SpellXSpellVisualID || m_SpellVisual.ScriptVisualID || m_spellInfo->IsChanneled() ||
        (m_spellInfo->HasAttribute(SPELL_ATTR8_AURA_POINTS_ON_CLIENT)) || m_spellInfo->HasHitDelay() || (!m_triggeredByAuraSpell && !IsTriggered()) ||
        m_spellInfo->HasAttribute(SPELL_ATTR7_ALWAYS_CAST_LOG);
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
                // handle effects on caster if the spell has travel time but also affects the caster in some way
                uint64 n_offset = m_Spell->handle_delayed(0);
                if (m_Spell->m_spellInfo->LaunchDelay)
                    ASSERT(n_offset == uint64(std::floor(m_Spell->m_spellInfo->LaunchDelay * 1000.0f)));
                else
                    ASSERT(n_offset == m_Spell->GetDelayMoment(), UI64FMTD " == " UI64FMTD, n_offset, m_Spell->GetDelayMoment());
                // re-plan the event for the delay moment
                m_Spell->GetCaster()->m_Events.AddEvent(this, Milliseconds(e_time + n_offset), false);
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
        bool isAoeTarget = spellEffectInfo.IsTargetingArea() || spellEffectInfo.IsAreaAuraEffect() || spellEffectInfo.IsEffect(SPELL_EFFECT_PERSISTENT_AREA_AURA);
        if (isAoeTarget || m_spellInfo->HasAttribute(SPELL_ATTR5_TREAT_AS_AREA_EFFECT) || m_spellInfo->HasAttribute(SPELL_ATTR7_TREAT_AS_NPC_AOE))
        {
            m_damage = unit->CalculateAOEAvoidance(m_damage, m_spellInfo->SchoolMask, !m_originalCaster->IsControlledByPlayer() || m_spellInfo->HasAttribute(SPELL_ATTR7_TREAT_AS_NPC_AOE));

            if (m_originalCaster->GetTypeId() == TYPEID_PLAYER)
            {
                int64 targetCount = !isAoeTarget && m_spellValue->ParentSpellTargetCount ? *m_spellValue->ParentSpellTargetCount : GetUnitTargetCountForEffect(spellEffectInfo.EffectIndex);
                int32 targetIndex = !isAoeTarget && m_spellValue->ParentSpellTargetIndex ? *m_spellValue->ParentSpellTargetIndex : GetUnitTargetIndexForEffect(targetInfo.TargetGUID, spellEffectInfo.EffectIndex);

                // sqrt target cap damage calculation
                if (m_spellInfo->SqrtDamageAndHealingDiminishing.MaxTargets
                    && targetCount > m_spellInfo->SqrtDamageAndHealingDiminishing.MaxTargets
                    && targetIndex >= m_spellInfo->SqrtDamageAndHealingDiminishing.NumNonDiminishedTargets)
                    m_damage = m_damage * std::sqrt(float(m_spellInfo->SqrtDamageAndHealingDiminishing.MaxTargets) / std::min(AOE_DAMAGE_TARGET_CAP, targetCount));

                // cap damage of player AOE
                if (targetCount > AOE_DAMAGE_TARGET_CAP)
                    m_damage = m_damage * AOE_DAMAGE_TARGET_CAP / targetCount;
            }
        }
    }

    if (m_originalCaster && m_healing > 0)
    {
        bool isAoeTarget = spellEffectInfo.IsTargetingArea() || spellEffectInfo.IsAreaAuraEffect() || spellEffectInfo.IsEffect(SPELL_EFFECT_PERSISTENT_AREA_AURA);
        if (isAoeTarget || m_spellInfo->HasAttribute(SPELL_ATTR5_TREAT_AS_AREA_EFFECT))
        {
            if (m_originalCaster->GetTypeId() == TYPEID_PLAYER)
            {
                int64 targetCount = !isAoeTarget && m_spellValue->ParentSpellTargetCount ? *m_spellValue->ParentSpellTargetCount : GetUnitTargetCountForEffect(spellEffectInfo.EffectIndex);
                int32 targetIndex = !isAoeTarget && m_spellValue->ParentSpellTargetIndex ? *m_spellValue->ParentSpellTargetIndex : GetUnitTargetIndexForEffect(targetInfo.TargetGUID, spellEffectInfo.EffectIndex);

                // sqrt target cap healing calculation
                if (m_spellInfo->SqrtDamageAndHealingDiminishing.MaxTargets
                    && targetCount > m_spellInfo->SqrtDamageAndHealingDiminishing.MaxTargets
                    && targetIndex >= m_spellInfo->SqrtDamageAndHealingDiminishing.NumNonDiminishedTargets)
                    m_healing = m_healing * std::sqrt(float(m_spellInfo->SqrtDamageAndHealingDiminishing.MaxTargets) / std::min(AOE_DAMAGE_TARGET_CAP, targetCount));
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

void Spell::ResetCombatTimers()
{
    Unit* unitCaster = m_caster->ToUnit();
    if (!unitCaster)
        return;

    unitCaster->resetAttackTimer(BASE_ATTACK);
    if (unitCaster->haveOffhandWeapon())
        unitCaster->resetAttackTimer(OFF_ATTACK);
    unitCaster->resetAttackTimer(RANGED_ATTACK);
}

SpellCastResult Spell::CanOpenLock(SpellEffectInfo const& effect, uint32 lockId, SkillType& skillId, int32& reqSkillValue, int32& skillValue)
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
                if (lockInfo->Index[j] && m_CastItem && int32(m_CastItem->GetEntry()) == lockInfo->Index[j])
                    return SPELL_CAST_OK;
                reqKey = true;
                break;
                // check key skill (only single first fit case can be)
            case LOCK_KEY_SKILL:
            {
                reqKey = true;

                // wrong locktype, skip
                if (effect.MiscValue != lockInfo->Index[j])
                    continue;

                skillId = SkillByLockType(LockType(lockInfo->Index[j]));

                if (skillId != SKILL_NONE || lockInfo->Index[j] == LOCKTYPE_LOCKPICKING)
                {
                    reqSkillValue = lockInfo->Skill[j];

                    // castitem check: rogue using skeleton keys. the skill values should not be added in this case.
                    skillValue = 0;
                    if (!m_CastItem && unitCaster->GetTypeId() == TYPEID_PLAYER)
                        skillValue = unitCaster->ToPlayer()->GetSkillValue(skillId);
                    else if (lockInfo->Index[j] == LOCKTYPE_LOCKPICKING)
                        skillValue = unitCaster->GetLevel() * 5;

                    // skill bonus provided by casting spell (mostly item spells)
                    // add the effect base points modifier from the spell cast (cheat lock / skeleton key etc.)
                    if (effect.TargetA.GetTarget() == TARGET_GAMEOBJECT_ITEM_TARGET || effect.TargetB.GetTarget() == TARGET_GAMEOBJECT_ITEM_TARGET)
                        skillValue += effect.CalcValue();

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

    if (reqKey)
        return SPELL_FAILED_BAD_TARGETS;

    return SPELL_CAST_OK;
}

void Spell::SetSpellValue(SpellValueMod mod, int32 value)
{
    if (mod < SPELLVALUE_BASE_POINT_END)
    {
        m_spellValue->EffectBasePoints[mod] = value;
        m_spellValue->CustomBasePointsMask |= 1 << mod;
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
        case SPELLVALUE_CRIT_CHANCE:
            m_spellValue->CriticalChance = value / 100.0f; // @todo ugly /100 remove when basepoints are double
            break;
        case SPELLVALUE_DURATION_PCT:
            m_spellValue->DurationMul = float(value) / 100.0f;
            break;
        case SPELLVALUE_DURATION:
            m_spellValue->Duration = value;
            break;
        case SPELLVALUE_PARENT_SPELL_TARGET_COUNT:
            m_spellValue->ParentSpellTargetCount = value;
            break;
        case SPELLVALUE_PARENT_SPELL_TARGET_INDEX:
            m_spellValue->ParentSpellTargetIndex = value;
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
    for (SpellScript* script : m_loadedScripts)
    {
        TC_LOG_DEBUG("spells", "Spell::LoadScripts: Script `{}` for spell `{}` is loaded now", script->GetScriptName(), m_spellInfo->Id);
        script->Register();
    }
}

void Spell::CallScriptOnPrecastHandler()
{
    for (SpellScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(SPELL_SCRIPT_HOOK_ON_PRECAST);
        script->OnPrecast();
        script->_FinishScriptCall();
    }
}

void Spell::CallScriptBeforeCastHandlers()
{
    for (SpellScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(SPELL_SCRIPT_HOOK_BEFORE_CAST);
        for (SpellScript::CastHandler const& beforeCast : script->BeforeCast)
            beforeCast.Call(script);

        script->_FinishScriptCall();
    }
}

void Spell::CallScriptOnCastHandlers()
{
    for (SpellScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(SPELL_SCRIPT_HOOK_ON_CAST);
        for (SpellScript::CastHandler const& onCast : script->OnCast)
            onCast.Call(script);

        script->_FinishScriptCall();
    }
}

void Spell::CallScriptAfterCastHandlers()
{
    for (SpellScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(SPELL_SCRIPT_HOOK_AFTER_CAST);
        for (SpellScript::CastHandler const& afterCast : script->AfterCast)
            afterCast.Call(script);

        script->_FinishScriptCall();
    }
}

SpellCastResult Spell::CallScriptCheckCastHandlers()
{
    SpellCastResult retVal = SPELL_CAST_OK;
    for (SpellScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(SPELL_SCRIPT_HOOK_CHECK_CAST);
        for (SpellScript::CheckCastHandler const& checkCast : script->OnCheckCast)
        {
            SpellCastResult tempResult = checkCast.Call(script);
            if (retVal == SPELL_CAST_OK)
                retVal = tempResult;
        }

        script->_FinishScriptCall();
    }
    return retVal;
}

int32 Spell::CallScriptCalcCastTimeHandlers(int32 castTime)
{
    for (SpellScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(SPELL_SCRIPT_HOOK_CALC_CAST_TIME);
        castTime = script->CalcCastTime(castTime);
        script->_FinishScriptCall();
    }
    return castTime;
}

bool Spell::CallScriptEffectHandlers(SpellEffIndex effIndex, SpellEffectHandleMode mode)
{
    // execute script effect handler hooks and check if effects was prevented
    bool preventDefault = false;
    for (SpellScript* script : m_loadedScripts)
    {
        script->_InitHit();

        Trinity::IteratorPair<HookList<SpellScript::EffectHandler>::iterator> effectHandlers;
        SpellScriptHookType hookType;
        switch (mode)
        {
            case SPELL_EFFECT_HANDLE_LAUNCH:
                effectHandlers = Trinity::Containers::MakeIteratorPair(script->OnEffectLaunch.begin(), script->OnEffectLaunch.end());
                hookType = SPELL_SCRIPT_HOOK_EFFECT_LAUNCH;
                break;
            case SPELL_EFFECT_HANDLE_LAUNCH_TARGET:
                effectHandlers = Trinity::Containers::MakeIteratorPair(script->OnEffectLaunchTarget.begin(), script->OnEffectLaunchTarget.end());
                hookType = SPELL_SCRIPT_HOOK_EFFECT_LAUNCH_TARGET;
                break;
            case SPELL_EFFECT_HANDLE_HIT:
                effectHandlers = Trinity::Containers::MakeIteratorPair(script->OnEffectHit.begin(), script->OnEffectHit.end());
                hookType = SPELL_SCRIPT_HOOK_EFFECT_HIT;
                break;
            case SPELL_EFFECT_HANDLE_HIT_TARGET:
                effectHandlers = Trinity::Containers::MakeIteratorPair(script->OnEffectHitTarget.begin(), script->OnEffectHitTarget.end());
                hookType = SPELL_SCRIPT_HOOK_EFFECT_HIT_TARGET;
                break;
            default:
                ABORT();
                return false;
        }
        script->_PrepareScriptCall(hookType);
        for (SpellScript::EffectHandler const& effectHandler : effectHandlers)
            // effect execution can be prevented
            if (!script->_IsEffectPrevented(effIndex) && effectHandler.IsEffectAffected(m_spellInfo, effIndex))
                effectHandler.Call(script, effIndex);

        if (!preventDefault)
            preventDefault = script->_IsDefaultEffectPrevented(effIndex);

        script->_FinishScriptCall();
    }
    return preventDefault;
}

void Spell::CallScriptSuccessfulDispel(SpellEffIndex effIndex)
{
    for (SpellScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(SPELL_SCRIPT_HOOK_EFFECT_SUCCESSFUL_DISPEL);
        for (SpellScript::EffectHandler const& onDispel : script->OnEffectSuccessfulDispel)
            onDispel.Call(script, effIndex);

        script->_FinishScriptCall();
    }
}

void Spell::CallScriptBeforeHitHandlers(SpellMissInfo missInfo)
{
    for (SpellScript* script : m_loadedScripts)
    {
        script->_InitHit();
        script->_PrepareScriptCall(SPELL_SCRIPT_HOOK_BEFORE_HIT);
        for (SpellScript::BeforeHitHandler const& beforeHit : script->BeforeHit)
            beforeHit.Call(script, missInfo);

        script->_FinishScriptCall();
    }
}

void Spell::CallScriptOnHitHandlers()
{
    for (SpellScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(SPELL_SCRIPT_HOOK_HIT);
        for (SpellScript::HitHandler const& onHit : script->OnHit)
            onHit.Call(script);

        script->_FinishScriptCall();
    }
}

void Spell::CallScriptAfterHitHandlers()
{
    for (SpellScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(SPELL_SCRIPT_HOOK_AFTER_HIT);
        for (SpellScript::HitHandler const& afterHit : script->AfterHit)
            afterHit.Call(script);

        script->_FinishScriptCall();
    }
}

void Spell::CallScriptCalcCritChanceHandlers(Unit const* victim, float& critChance)
{
    for (SpellScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(SPELL_SCRIPT_HOOK_CALC_CRIT_CHANCE);
        for (SpellScript::OnCalcCritChanceHandler const& calcCritChance : script->OnCalcCritChance)
            calcCritChance.Call(script, victim, critChance);

        script->_FinishScriptCall();
    }
}

void Spell::CallScriptCalcDamageHandlers(Unit* victim, int32& damage, int32& flatMod, float& pctMod)
{
    for (SpellScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(SPELL_SCRIPT_HOOK_CALC_DAMAGE);
        for (SpellScript::DamageAndHealingCalcHandler const& calcDamage : script->CalcDamage)
            calcDamage.Call(script, victim, damage, flatMod, pctMod);

        script->_FinishScriptCall();
    }
}

void Spell::CallScriptCalcHealingHandlers(Unit* victim, int32& healing, int32& flatMod, float& pctMod)
{
    for (SpellScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(SPELL_SCRIPT_HOOK_CALC_HEALING);
        for (SpellScript::DamageAndHealingCalcHandler const& calcHealing : script->CalcHealing)
            calcHealing.Call(script, victim, healing, flatMod, pctMod);

        script->_FinishScriptCall();
    }
}

void Spell::CallScriptObjectAreaTargetSelectHandlers(std::list<WorldObject*>& targets, SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType)
{
    for (SpellScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(SPELL_SCRIPT_HOOK_OBJECT_AREA_TARGET_SELECT);
        for (SpellScript::ObjectAreaTargetSelectHandler const& objectAreaTargetSelect : script->OnObjectAreaTargetSelect)
            if (objectAreaTargetSelect.IsEffectAffected(m_spellInfo, effIndex) && targetType.GetTarget() == objectAreaTargetSelect.GetTarget())
                objectAreaTargetSelect.Call(script, targets);

        script->_FinishScriptCall();
    }
}

void Spell::CallScriptObjectTargetSelectHandlers(WorldObject*& target, SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType)
{
    for (SpellScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(SPELL_SCRIPT_HOOK_OBJECT_TARGET_SELECT);
        for (SpellScript::ObjectTargetSelectHandler const& objectTargetSelect : script->OnObjectTargetSelect)
            if (objectTargetSelect.IsEffectAffected(m_spellInfo, effIndex) && targetType.GetTarget() == objectTargetSelect.GetTarget())
                objectTargetSelect.Call(script, target);

        script->_FinishScriptCall();
    }
}

void Spell::CallScriptDestinationTargetSelectHandlers(SpellDestination& target, SpellEffIndex effIndex, SpellImplicitTargetInfo const& targetType)
{
    for (SpellScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(SPELL_SCRIPT_HOOK_DESTINATION_TARGET_SELECT);
        for (SpellScript::DestinationTargetSelectHandler const& destinationTargetSelect : script->OnDestinationTargetSelect)
            if (destinationTargetSelect.IsEffectAffected(m_spellInfo, effIndex) && targetType.GetTarget() == destinationTargetSelect.GetTarget())
                destinationTargetSelect.Call(script, target);

        script->_FinishScriptCall();
    }
}

void Spell::CallScriptOnResistAbsorbCalculateHandlers(DamageInfo const& damageInfo, uint32& resistAmount, int32& absorbAmount)
{
    for (SpellScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(SPELL_SCRIPT_HOOK_ON_RESIST_ABSORB_CALCULATION);
        for (SpellScript::OnCalculateResistAbsorbHandler const& calculateResistAbsorb : script->OnCalculateResistAbsorb)
            calculateResistAbsorb.Call(script, damageInfo, resistAmount, absorbAmount);

        script->_FinishScriptCall();
    }
}

void Spell::CallScriptEmpowerStageCompletedHandlers(int32 completedStagesCount)
{
    for (SpellScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(SPELL_SCRIPT_HOOK_EMPOWER_STAGE_COMPLETED);
        for (SpellScript::EmpowerStageCompletedHandler const& empowerStageCompleted : script->OnEmpowerStageCompleted)
            empowerStageCompleted.Call(script, completedStagesCount);

        script->_FinishScriptCall();
    }
}

void Spell::CallScriptEmpowerCompletedHandlers(int32 completedStagesCount)
{
    for (SpellScript* script : m_loadedScripts)
    {
        script->_PrepareScriptCall(SPELL_SCRIPT_HOOK_EMPOWER_COMPLETED);
        for (SpellScript::EmpowerStageCompletedHandler const& empowerStageCompleted : script->OnEmpowerCompleted)
            empowerStageCompleted.Call(script, completedStagesCount);

        script->_FinishScriptCall();
    }
}

bool Spell::CheckScriptEffectImplicitTargets(uint32 effIndex, uint32 effIndexToCheck)
{
    // Skip if there are not any script
    if (m_loadedScripts.empty())
        return true;

    for (SpellScript* script : m_loadedScripts)
    {
        for (SpellScript::ObjectTargetSelectHandler const& objectTargetSelect : script->OnObjectTargetSelect)
            if ((objectTargetSelect.IsEffectAffected(m_spellInfo, effIndex) && !objectTargetSelect.IsEffectAffected(m_spellInfo, effIndexToCheck)) ||
                (!objectTargetSelect.IsEffectAffected(m_spellInfo, effIndex) && objectTargetSelect.IsEffectAffected(m_spellInfo, effIndexToCheck)))
                return false;

        for (SpellScript::ObjectAreaTargetSelectHandler const& objectAreaTargetSelect : script->OnObjectAreaTargetSelect)
            if ((objectAreaTargetSelect.IsEffectAffected(m_spellInfo, effIndex) && !objectAreaTargetSelect.IsEffectAffected(m_spellInfo, effIndexToCheck)) ||
                (!objectAreaTargetSelect.IsEffectAffected(m_spellInfo, effIndex) && objectAreaTargetSelect.IsEffectAffected(m_spellInfo, effIndexToCheck)))
                return false;
    }
    return true;
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

            // build trigger and add to the list
            m_hitTriggerSpells.emplace_back(spellInfo, aurEff->GetSpellInfo(), chance);
        }
    }
}

// Global cooldowns management
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

    Milliseconds gcd(m_spellInfo->StartRecoveryTime);
    if (gcd == 0ms || !m_spellInfo->StartRecoveryCategory)
        return;

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
        if (m_caster->ToPlayer()->GetCommandStatus(CHEAT_COOLDOWN))
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
        }
    }

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
        << "Id: " << GetSpellInfo()->Id << " Name: '" << (*GetSpellInfo()->SpellName)[sWorld->GetDefaultDbcLocale()] << "' OriginalCaster: " << m_originalCasterGUID.ToString()
        << " State: " << getState();
    return sstr.str();
}

Trinity::unique_weak_ptr<Spell> Spell::GetWeakPtr() const
{
    return _spellEvent->GetSpellWeakPtr();
}

bool Spell::IsWithinLOS(WorldObject const* source, WorldObject const* target, bool targetAsSourceLocation, VMAP::ModelIgnoreFlags ignoreFlags) const
{
    if (m_spellInfo->HasAttribute(SPELL_ATTR2_IGNORE_LINE_OF_SIGHT))
        return true;

    if (DisableMgr::IsDisabledFor(DISABLE_TYPE_SPELL, m_spellInfo->Id, nullptr, SPELL_DISABLE_LOS))
        return true;

    if (target->IsCreature() && target->ToCreature()->CanIgnoreLineOfSightWhenCastingOnMe())
        return true;

    WorldObject const* src = targetAsSourceLocation ? target : source;
    WorldObject const* dst = targetAsSourceLocation ? source : target;
    return src->IsWithinLOSInMap(dst, LINEOFSIGHT_ALL_CHECKS, ignoreFlags);
}

bool Spell::IsWithinLOS(WorldObject const* source, Position const& target, VMAP::ModelIgnoreFlags ignoreFlags) const
{
    if (m_spellInfo->HasAttribute(SPELL_ATTR2_IGNORE_LINE_OF_SIGHT))
        return true;

    if (DisableMgr::IsDisabledFor(DISABLE_TYPE_SPELL, m_spellInfo->Id, nullptr, SPELL_DISABLE_LOS))
        return true;

    return source->IsWithinLOS(target.GetPositionX(), target.GetPositionY(), target.GetPositionZ(), LINEOFSIGHT_ALL_CHECKS, ignoreFlags);
}

void Spell::MovePosition(Position& pos, WorldObject const* from, float dist, float angle) const
{
    if (m_spellInfo->HasAttribute(SPELL_ATTR9_FORCE_DEST_LOCATION))
        from->MovePosition(pos, dist, angle);
    else
        from->MovePositionToFirstCollision(pos, dist, angle);
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
            case TARGET_CHECK_SUMMONED:
                if (!unitTarget->IsSummon())
                    return false;
                if (unitTarget->ToTempSummon()->GetSummonerGUID() != _caster->GetGUID())
                    return false;
                break;
            default:
                break;
        }

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
    WorldObject* referer, SpellInfo const* spellInfo, SpellTargetCheckTypes selectionType, ConditionContainer const* condList, SpellTargetObjectTypes objectType,
    WorldObjectSpellAreaTargetSearchReason searchReason /*= Area*/)
    : WorldObjectSpellTargetCheck(caster, referer, spellInfo, selectionType, condList, objectType), _range(range), _position(position), _searchReason(searchReason) { }

bool WorldObjectSpellAreaTargetCheck::operator()(WorldObject* target) const
{
    if (GameObject* gameObjectTarget = target->ToGameObject())
    {
        // isInRange including the dimension of the GO
        bool isInRange = gameObjectTarget->IsInRange(_position->GetPositionX(), _position->GetPositionY(), _position->GetPositionZ(), _range);
        if (!isInRange)
            return false;
    }
    else
    {
        bool isInsideCylinder = target->IsWithinDist2d(_position, _range) && std::abs(target->GetPositionZ() - _position->GetPositionZ()) <= _range;
        if (!isInsideCylinder)
            return false;

        if (Unit* unitTarget = target->ToUnit())
        {
            switch (_searchReason)
            {
                case WorldObjectSpellAreaTargetSearchReason::Area:
                    if (!_spellInfo->HasAttribute(SPELL_ATTR8_CAN_HIT_AOE_UNTARGETABLE) && unitTarget->GetSpellOtherImmunityMask().HasFlag(SpellOtherImmunity::AoETarget))
                        return false;
                    break;
                case WorldObjectSpellAreaTargetSearchReason::Chain:
                    if (unitTarget->GetSpellOtherImmunityMask().HasFlag(SpellOtherImmunity::ChainTarget))
                        return false;
                    break;
                default:
                    break;
            }
        }
    }

    return WorldObjectSpellTargetCheck::operator ()(target);
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

void SelectRandomInjuredTargets(std::list<WorldObject*>& targets, size_t maxTargets, bool prioritizePlayers, Unit const* prioritizeGroupMembersOf /*= nullptr*/)
{
    if (targets.size() <= maxTargets)
        return;

    // Target priority states (bit indices)
    // higher value means lower selection priority
    // current list:
    // * injured player group members
    // * injured other players
    // * injured pets of group members
    // * injured other pets
    // * full health player group members
    // * full health other players
    // * full health pets of group members
    // * full health other pets
    enum
    {
        NOT_GROUPED,
        NOT_PLAYER,
        NOT_INJURED,
        END
    };

    std::array<std::ptrdiff_t, 1 << END> countsByPriority = {};
    std::vector<std::pair<WorldObject*, int32>> tempTargets;
    tempTargets.resize(targets.size());

    // categorize each target
    std::transform(targets.begin(), targets.end(), tempTargets.begin(), [&](WorldObject* target)
    {
        int32 negativePoints = 0;
        if (prioritizeGroupMembersOf && (!target->IsUnit() || target->ToUnit()->IsInRaidWith(prioritizeGroupMembersOf)))
            negativePoints |= 1 << NOT_GROUPED;

        if (prioritizePlayers && !target->IsPlayer() && (!target->IsCreature() || !target->ToCreature()->IsTreatedAsRaidUnit()))
            negativePoints |= 1 << NOT_PLAYER;

        if (!target->IsUnit() || target->ToUnit()->IsFullHealth())
            negativePoints |= 1 << NOT_INJURED;

        ++countsByPriority[negativePoints];
        return std::make_pair(target, negativePoints);
    });

    std::sort(tempTargets.begin(), tempTargets.end(), [](std::pair<WorldObject*, int32> const& left, std::pair<WorldObject*, int32> const& right)
    {
        return left.second < right.second;
    });

    std::size_t foundTargets = 0;
    for (std::ptrdiff_t countForPriority : countsByPriority)
    {
        if (foundTargets + countForPriority >= maxTargets)
        {
            // shuffle only the lower priority extras
            // example: our initial target list had 5 injured and 5 full health units and we want to select 7 targets
            //          we always want to select 5 injured and 2 random full health ones
            Containers::RandomShuffle(tempTargets.begin() + foundTargets, tempTargets.begin() + foundTargets + countForPriority);
            break;
        }

        foundTargets += countForPriority;
    }

    targets.resize(maxTargets);
    std::transform(tempTargets.begin(), tempTargets.begin() + maxTargets, targets.begin(), std::mem_fn(&std::pair<WorldObject*, int32>::first));
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

CastSpellExtraArgs::CastSpellExtraArgs() = default;
CastSpellExtraArgs::CastSpellExtraArgs(CastSpellExtraArgs const& other) = default;
CastSpellExtraArgs::CastSpellExtraArgs(CastSpellExtraArgs&& other) noexcept = default;
CastSpellExtraArgs& CastSpellExtraArgs::operator=(CastSpellExtraArgs const& other) = default;
CastSpellExtraArgs& CastSpellExtraArgs::operator=(CastSpellExtraArgs&& other) noexcept = default;
CastSpellExtraArgs::~CastSpellExtraArgs() = default;

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
}

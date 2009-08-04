/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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

#include "Common.h"
#include "Database/DatabaseEnv.h"
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
#include "Policies/SingletonImp.h"
#include "SharedDefines.h"
#include "LootMgr.h"
#include "VMapFactory.h"
#include "BattleGround.h"
#include "Util.h"
#include "TemporarySummon.h"
#include "Vehicle.h"

#define SPELL_CHANNEL_UPDATE_INTERVAL (1 * IN_MILISECONDS)

extern pEffect SpellEffects[TOTAL_SPELL_EFFECTS];

bool IsQuestTameSpell(uint32 spellId)
{
    SpellEntry const *spellproto = sSpellStore.LookupEntry(spellId);
    if (!spellproto) return false;

    return spellproto->Effect[0] == SPELL_EFFECT_THREAT
        && spellproto->Effect[1] == SPELL_EFFECT_APPLY_AURA && spellproto->EffectApplyAuraName[1] == SPELL_AURA_DUMMY;
}

class PrioritizeManaUnitWraper
{
    public:
        explicit PrioritizeManaUnitWraper(Unit* unit) : i_unit(unit)
        {
            uint32 maxmana = unit->GetMaxPower(POWER_MANA);
            i_percent = maxmana ? unit->GetPower(POWER_MANA) * 100 / maxmana : 101;
        }
        Unit* getUnit() const { return i_unit; }
        uint32 getPercent() const { return i_percent; }
    private:
        Unit* i_unit;
        uint32 i_percent;
};

struct PrioritizeMana
{
    int operator()( PrioritizeManaUnitWraper const& x, PrioritizeManaUnitWraper const& y ) const
    {
        return x.getPercent() < y.getPercent();
    }
};

typedef std::priority_queue<PrioritizeManaUnitWraper, std::vector<PrioritizeManaUnitWraper>, PrioritizeMana> PrioritizeManaUnitQueue;

class PrioritizeHealthUnitWraper
{
public:
    explicit PrioritizeHealthUnitWraper(Unit* unit) : i_unit(unit)
    {
        i_percent = unit->GetHealth() * 100 / unit->GetMaxHealth();
    }
    Unit* getUnit() const { return i_unit; }
    uint32 getPercent() const { return i_percent; }
private:
    Unit* i_unit;
    uint32 i_percent;
};

struct PrioritizeHealth
{
    int operator()( PrioritizeHealthUnitWraper const& x, PrioritizeHealthUnitWraper const& y ) const
    {
        return x.getPercent() < y.getPercent();
    }
};

typedef std::priority_queue<PrioritizeHealthUnitWraper, std::vector<PrioritizeHealthUnitWraper>, PrioritizeHealth> PrioritizeHealthUnitQueue;

SpellCastTargets::SpellCastTargets()
{
    m_unitTarget = NULL;
    m_itemTarget = NULL;
    m_GOTarget   = NULL;

    m_unitTargetGUID   = 0;
    m_GOTargetGUID     = 0;
    m_CorpseTargetGUID = 0;
    m_itemTargetGUID   = 0;
    m_itemTargetEntry  = 0;

    m_srcX = m_srcY = m_srcZ = m_destX = m_destY = m_destZ = 0;
    m_strTarget = "";
    m_targetMask = 0;
}

SpellCastTargets::~SpellCastTargets()
{
}

void SpellCastTargets::setUnitTarget(Unit *target)
{
    if (!target)
        return;

    m_unitTarget = target;
    m_unitTargetGUID = target->GetGUID();
    m_targetMask |= TARGET_FLAG_UNIT;
}

void SpellCastTargets::setSrc(float x, float y, float z)
{
    m_srcX = x;
    m_srcY = y;
    m_srcZ = z;
    m_targetMask |= TARGET_FLAG_SOURCE_LOCATION;
}

void SpellCastTargets::setSrc(WorldObject *target)
{
    if(!target)
        return;

    target->GetPosition(m_srcX, m_srcY, m_srcZ);
    m_targetMask |= TARGET_FLAG_SOURCE_LOCATION;
}

void SpellCastTargets::setDestination(float x, float y, float z, int32 mapId)
{
    m_destX = x;
    m_destY = y;
    m_destZ = z;
    m_targetMask |= TARGET_FLAG_DEST_LOCATION;
    if(mapId >= 0)
        m_mapId = mapId;
}

void SpellCastTargets::setDestination(WorldObject *target)
{
    if(!target)
        return;

    target->GetPosition(m_destX, m_destY, m_destZ);
    m_targetMask |= TARGET_FLAG_DEST_LOCATION;
}

/*void SpellCastTargets::setSource(float x, float y, float z)
{
    m_srcX = x;
    m_srcY = y;
    m_srcZ = z;
    m_targetMask |= TARGET_FLAG_SOURCE_LOCATION;
}*/

void SpellCastTargets::setGOTarget(GameObject *target)
{
    m_GOTarget = target;
    m_GOTargetGUID = target->GetGUID();
    //    m_targetMask |= TARGET_FLAG_OBJECT;
}

void SpellCastTargets::setItemTarget(Item* item)
{
    if(!item)
        return;

    m_itemTarget = item;
    m_itemTargetGUID = item->GetGUID();
    m_itemTargetEntry = item->GetEntry();
    m_targetMask |= TARGET_FLAG_ITEM;
}

void SpellCastTargets::setCorpseTarget(Corpse* corpse)
{
    m_CorpseTargetGUID = corpse->GetGUID();
}

void SpellCastTargets::Update(Unit* caster)
{
    m_GOTarget   = m_GOTargetGUID ? caster->GetMap()->GetGameObject(m_GOTargetGUID) : NULL;
    m_unitTarget = m_unitTargetGUID ?
        ( m_unitTargetGUID == caster->GetGUID() ? caster : ObjectAccessor::GetUnit(*caster, m_unitTargetGUID) ) :
    NULL;

    m_itemTarget = NULL;
    if(caster->GetTypeId() == TYPEID_PLAYER)
    {
        if(m_targetMask & TARGET_FLAG_ITEM)
            m_itemTarget = ((Player*)caster)->GetItemByGuid(m_itemTargetGUID);
        else if(m_targetMask & TARGET_FLAG_TRADE_ITEM)
        {
            // here it is not guid but slot
            Player* pTrader = ((Player*)caster)->GetTrader();
            if(pTrader && m_itemTargetGUID < TRADE_SLOT_COUNT)
                m_itemTarget = pTrader->GetItemByPos(pTrader->GetItemPosByTradeSlot(m_itemTargetGUID));
        }
        if(m_itemTarget)
            m_itemTargetEntry = m_itemTarget->GetEntry();
    }
}

bool SpellCastTargets::read ( WorldPacket * data, Unit *caster )
{
    if(data->rpos() + 4 > data->size())
        return false;

    //data->hexlike();

    *data >> m_targetMask;
    //sLog.outDebug("Spell read, target mask = %u", m_targetMask);

    if(m_targetMask == TARGET_FLAG_SELF)
        return true;

    // TARGET_FLAG_UNK2 is used for non-combat pets, maybe other?
    if( m_targetMask & ( TARGET_FLAG_UNIT | TARGET_FLAG_UNK2 ))
        if(!data->readPackGUID(m_unitTargetGUID))
            return false;

    if( m_targetMask & ( TARGET_FLAG_OBJECT ))
        if(!data->readPackGUID(m_GOTargetGUID))
            return false;

    if(( m_targetMask & ( TARGET_FLAG_ITEM | TARGET_FLAG_TRADE_ITEM )) && caster->GetTypeId() == TYPEID_PLAYER)
        if(!data->readPackGUID(m_itemTargetGUID))
            return false;

    if( m_targetMask & (TARGET_FLAG_CORPSE | TARGET_FLAG_PVP_CORPSE ) )
        if(!data->readPackGUID(m_CorpseTargetGUID))
            return false;

    if( m_targetMask & TARGET_FLAG_SOURCE_LOCATION )
    {
        if(data->rpos() + 4 + 4 + 4 > data->size())
            return false;

        *data >> m_srcX >> m_srcY >> m_srcZ;
        if(!Trinity::IsValidMapCoord(m_srcX, m_srcY, m_srcZ))
            return false;
    }

    if( m_targetMask & TARGET_FLAG_DEST_LOCATION )
    {
        if(data->rpos() + 1 + 4 + 4 + 4 > data->size())
            return false;

        if(!data->readPackGUID(m_unitTargetGUID))
            return false;

        *data >> m_destX >> m_destY >> m_destZ;
        if(!Trinity::IsValidMapCoord(m_destX, m_destY, m_destZ))
            return false;
    }

    if( m_targetMask & TARGET_FLAG_STRING )
    {
        if(data->rpos() + 1 > data->size())
            return false;

        *data >> m_strTarget;
    }

    // find real units/GOs
    Update(caster);
    return true;
}

void SpellCastTargets::write ( WorldPacket * data )
{
    *data << uint32(m_targetMask);
    //sLog.outDebug("Spell write, target mask = %u", m_targetMask);

    if( m_targetMask & ( TARGET_FLAG_UNIT | TARGET_FLAG_PVP_CORPSE | TARGET_FLAG_OBJECT | TARGET_FLAG_CORPSE | TARGET_FLAG_UNK2 ) )
    {
        if(m_targetMask & TARGET_FLAG_UNIT)
        {
            if(m_unitTarget)
                data->append(m_unitTarget->GetPackGUID());
            else
                *data << uint8(0);
        }
        else if( m_targetMask & TARGET_FLAG_OBJECT )
        {
            if(m_GOTarget)
                data->append(m_GOTarget->GetPackGUID());
            else
                *data << uint8(0);
        }
        else if( m_targetMask & ( TARGET_FLAG_CORPSE | TARGET_FLAG_PVP_CORPSE ) )
            data->appendPackGUID(m_CorpseTargetGUID);
        else
            *data << uint8(0);
    }

    if( m_targetMask & ( TARGET_FLAG_ITEM | TARGET_FLAG_TRADE_ITEM ) )
    {
        if(m_itemTarget)
            data->append(m_itemTarget->GetPackGUID());
        else
            *data << uint8(0);
    }

    if( m_targetMask & TARGET_FLAG_SOURCE_LOCATION )
        *data << m_srcX << m_srcY << m_srcZ;

    if( m_targetMask & TARGET_FLAG_DEST_LOCATION )
    {
        if(m_unitTarget)
            data->append(m_unitTarget->GetPackGUID());
        else
            *data << uint8(0);

        *data << m_destX << m_destY << m_destZ;
    }

    if( m_targetMask & TARGET_FLAG_STRING )
        *data << m_strTarget;
}

Spell::Spell( Unit* Caster, SpellEntry const *info, bool triggered, uint64 originalCasterGUID, Spell** triggeringContainer, bool skipCheck )
: m_spellInfo(info), m_spellValue(new SpellValue(m_spellInfo))
, m_caster(Caster)
{
    m_customAttr = spellmgr.GetSpellCustomAttr(m_spellInfo->Id);
    m_skipCheck = skipCheck;
    m_selfContainer = NULL;
    m_triggeringContainer = triggeringContainer;
    m_referencedFromCurrentSpell = false;
    m_executedCurrently = false;
    m_needComboPoints = NeedsComboPoints(m_spellInfo);
    m_comboPointGain = 0;
    m_delayStart = 0;
    m_delayAtDamageCount = 0;

    m_canTrigger=true;

    m_applyMultiplierMask = 0;
    m_effectMask = 0;
    m_auraScaleMask = 0;

    // Get data for type of attack
    switch (m_spellInfo->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_MELEE:
            if (m_spellInfo->AttributesEx3 & SPELL_ATTR_EX3_REQ_OFFHAND)
                m_attackType = OFF_ATTACK;
            else
                m_attackType = BASE_ATTACK;
            break;
        case SPELL_DAMAGE_CLASS_RANGED:
            m_attackType = IsRangedWeaponSpell(m_spellInfo) ? RANGED_ATTACK : BASE_ATTACK;
            break;
        default:
                                                            // Wands
            if (m_spellInfo->AttributesEx2 & SPELL_ATTR_EX2_AUTOREPEAT_FLAG)
                m_attackType = RANGED_ATTACK;
            else
                m_attackType = BASE_ATTACK;
            break;
    }

    m_spellSchoolMask = GetSpellSchoolMask(info);           // Can be override for some spell (wand shoot for example)

    if(m_attackType == RANGED_ATTACK)
    {
        // wand case
        if((m_caster->getClassMask() & CLASSMASK_WAND_USERS) != 0 && m_caster->GetTypeId() == TYPEID_PLAYER)
        {
            if(Item* pItem = ((Player*)m_caster)->GetWeaponForAttack(RANGED_ATTACK))
                m_spellSchoolMask = SpellSchoolMask(1 << pItem->GetProto()->Damage[0].DamageType);
        }
    }
    // Set health leech amount to zero
    m_healthLeech = 0;

    if(originalCasterGUID)
        m_originalCasterGUID = originalCasterGUID;
    else
        m_originalCasterGUID = m_caster->GetGUID();

    if(m_originalCasterGUID == m_caster->GetGUID())
        m_originalCaster = m_caster;
    else
    {
        m_originalCaster = ObjectAccessor::GetUnit(*m_caster, m_originalCasterGUID);
        if(m_originalCaster && !m_originalCaster->IsInWorld()) m_originalCaster = NULL;
    }

    for(int i=0; i <3; ++i)
        m_currentBasePoints[i] = m_spellValue->EffectBasePoints[i];

    m_spellState = SPELL_STATE_NULL;

    m_TriggerSpells.clear();
    m_IsTriggeredSpell = triggered;
    //m_AreaAura = false;
    m_CastItem = NULL;

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
    m_autoRepeat = IsAutoRepeatRangedSpell(m_spellInfo);

    m_runesState = 0;
    m_powerCost = 0;                                        // setup to correct value in Spell::prepare, don't must be used before.
    m_casttime = 0;                                         // setup to correct value in Spell::prepare, don't must be used before.
    m_timer = 0;                                            // will set to castime in prepare

    m_needAliveTargetMask = 0;

    // determine reflection
    m_canReflect = false;

    if(m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MAGIC && !IsAreaOfEffectSpell(m_spellInfo) && !(m_spellInfo->AttributesEx2 & SPELL_ATTR_EX2_CANT_REFLECTED))
    {
        for(int j = 0;j < 3; ++j)
        {
            if (m_spellInfo->Effect[j] == 0)
                continue;

            if(!IsPositiveTarget(m_spellInfo->EffectImplicitTargetA[j], m_spellInfo->EffectImplicitTargetB[j]))
                m_canReflect = true;
            else
                m_canReflect = (m_spellInfo->AttributesEx & SPELL_ATTR_EX_NEGATIVE) ? true : false;

            if(m_canReflect)
                continue;
            else
                break;
        }
    }

    CleanupTargetList();
}

Spell::~Spell()
{
    delete m_spellValue;
}

template<typename T>
WorldObject* Spell::FindCorpseUsing()
{
    // non-standard target selection
    float max_range = GetSpellMaxRange(m_spellInfo, false);

    CellPair p(MaNGOS::ComputeCellPair(m_caster->GetPositionX(), m_caster->GetPositionY()));
    Cell cell(p);
    cell.data.Part.reserved = ALL_DISTRICT;
    cell.SetNoCreate();

    WorldObject* result = NULL;

    T u_check(m_caster, max_range);
    MaNGOS::WorldObjectSearcher<T> searcher(m_caster, result, u_check);

    TypeContainerVisitor<MaNGOS::WorldObjectSearcher<T>, GridTypeMapContainer > grid_searcher(searcher);
    CellLock<GridReadGuard> cell_lock(cell, p);
    cell_lock->Visit(cell_lock, grid_searcher, *m_caster->GetMap());

    if (!result)
    {
        TypeContainerVisitor<MaNGOS::WorldObjectSearcher<T>, WorldTypeMapContainer > world_searcher(searcher);
        cell_lock->Visit(cell_lock, world_searcher, *m_caster->GetMap());
    }

    return result;
}

void Spell::FillTargetMap()
{
    for(uint32 i = 0; i < 3; ++i)
    {
        // not call for empty effect.
        // Also some spells use not used effect targets for store targets for dummy effect in triggered spells
        if(!m_spellInfo->Effect[i])
            continue;

        uint32 effectTargetType = spellmgr.EffectTargetType[m_spellInfo->Effect[i]];

        // is it possible that areaaura is not applied to caster?
        if(effectTargetType == SPELL_REQUIRE_NONE)
            continue;

        uint32 targetA = m_spellInfo->EffectImplicitTargetA[i];
        uint32 targetB = m_spellInfo->EffectImplicitTargetB[i];

        if(targetA)
            SetTargetMap(i, targetA);
        if(targetB) // In very rare case !A && B
            SetTargetMap(i, targetB);

        if(effectTargetType != SPELL_REQUIRE_UNIT)
        {
            if(effectTargetType == SPELL_REQUIRE_CASTER)
                AddUnitTarget(m_caster, i);
            else if(effectTargetType == SPELL_REQUIRE_ITEM)
            {
                if(m_targets.getItemTarget())
                    AddItemTarget(m_targets.getItemTarget(), i);
            }
            continue;
        }

        if(/*tmpUnitMap.empty() && */m_spellInfo->Targets & TARGET_FLAG_CASTER)
        {
            AddUnitTarget(m_caster, i);
            continue;
        }

        if(!targetA && !targetB)
        {
            if(!GetSpellMaxRangeForFriend(sSpellRangeStore.LookupEntry(m_spellInfo->rangeIndex)))
            {
                AddUnitTarget(m_caster, i);
                continue;
            }

            // add here custom effects that need default target.
            // FOR EVERY TARGET TYPE THERE IS A DIFFERENT FILL!!
            switch(m_spellInfo->Effect[i])
            {
                case SPELL_EFFECT_DUMMY:
                {
                    switch(m_spellInfo->Id)
                    {
                        case 20577:                         // Cannibalize
                        {
                            WorldObject* result = FindCorpseUsing<MaNGOS::CannibalizeObjectCheck> ();

                            if(result)
                            {
                                switch(result->GetTypeId())
                                {
                                    case TYPEID_UNIT:
                                    case TYPEID_PLAYER:
                                        AddUnitTarget((Unit*)result, i);
                                        break;
                                    case TYPEID_CORPSE:
                                        m_targets.setCorpseTarget((Corpse*)result);
                                        if(Player* owner = ObjectAccessor::FindPlayer(((Corpse*)result)->GetOwnerGUID()))
                                            AddUnitTarget(owner, i);
                                        break;
                                }
                            }
                            else
                            {
                                // clear cooldown at fail
                                if(m_caster->GetTypeId() == TYPEID_PLAYER)
                                    ((Player*)m_caster)->RemoveSpellCooldown(m_spellInfo->Id, true);
                                SendCastResult(SPELL_FAILED_NO_EDIBLE_CORPSES);
                                finish(false);
                            }
                            break;
                        }
                        default:
                            if(m_targets.getUnitTarget())
                                AddUnitTarget(m_targets.getUnitTarget(), i);
                            else
                                AddUnitTarget(m_caster, i);
                            break;
                    }
                    break;
                }
                case SPELL_EFFECT_RESURRECT:
                case SPELL_EFFECT_CREATE_ITEM:
                case SPELL_EFFECT_TRIGGER_SPELL:
                case SPELL_EFFECT_SKILL_STEP:
                case SPELL_EFFECT_PROFICIENCY:
                case SPELL_EFFECT_SUMMON_OBJECT_WILD:
                case SPELL_EFFECT_SELF_RESURRECT:
                case SPELL_EFFECT_REPUTATION:
                case SPELL_EFFECT_LEARN_SPELL:
                case SPELL_EFFECT_SEND_TAXI:
                    if(m_targets.getUnitTarget())
                        AddUnitTarget(m_targets.getUnitTarget(), i);
                    // Triggered spells have additional spell targets - cast them even if no explicit unit target is given (required for spell 50516 for example)
                    else if(m_spellInfo->Effect[i] == SPELL_EFFECT_TRIGGER_SPELL)
                        AddUnitTarget(m_caster, i);
                    break;
                case SPELL_EFFECT_SUMMON_PLAYER:
                    if(m_caster->GetTypeId()==TYPEID_PLAYER && ((Player*)m_caster)->GetSelection())
                    {
                        Player* target = objmgr.GetPlayer(((Player*)m_caster)->GetSelection());
                        if(target)
                            AddUnitTarget(target, i);
                    }
                    break;
                case SPELL_EFFECT_RESURRECT_NEW:
                    if(m_targets.getUnitTarget())
                        AddUnitTarget(m_targets.getUnitTarget(), i);
                    if(m_targets.getCorpseTargetGUID())
                    {
                        Corpse *corpse = ObjectAccessor::GetCorpse(*m_caster, m_targets.getCorpseTargetGUID());
                        if(corpse)
                        {
                            Player* owner = ObjectAccessor::FindPlayer(corpse->GetOwnerGUID());
                            if(owner)
                                AddUnitTarget(owner, i);
                        }
                    }
                    break;
                case SPELL_EFFECT_SUMMON_CHANGE_ITEM:
                case SPELL_EFFECT_ADD_FARSIGHT:
                case SPELL_EFFECT_APPLY_GLYPH:
                case SPELL_EFFECT_STUCK:
                case SPELL_EFFECT_FEED_PET:
                case SPELL_EFFECT_DESTROY_ALL_TOTEMS:
                case SPELL_EFFECT_KILL_CREDIT2: // only one spell: 42793
                    AddUnitTarget(m_caster, i);
                    break;
                case SPELL_EFFECT_LEARN_PET_SPELL:
                    if(Guardian* pet = m_caster->GetGuardianPet())
                        AddUnitTarget(pet, i);
                    break;
                /*case SPELL_EFFECT_ENCHANT_ITEM:
                case SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY:
                case SPELL_EFFECT_ENCHANT_ITEM_PRISMATIC:
                case SPELL_EFFECT_DISENCHANT:
                case SPELL_EFFECT_PROSPECTING:
                case SPELL_EFFECT_MILLING:
                    if(m_targets.getItemTarget())
                        AddItemTarget(m_targets.getItemTarget(), i);
                    break;*/
                case SPELL_EFFECT_APPLY_AURA:
                    switch(m_spellInfo->EffectApplyAuraName[i])
                    {
                        case SPELL_AURA_ADD_FLAT_MODIFIER:  // some spell mods auras have 0 target modes instead expected TARGET_UNIT_CASTER(1) (and present for other ranks for same spell for example)
                        case SPELL_AURA_ADD_PCT_MODIFIER:
                            AddUnitTarget(m_caster, i);
                            break;
                        default:                            // apply to target in other case
                            break;
                    }
                    break;
                case SPELL_EFFECT_APPLY_AREA_AURA_PARTY:
                                                            // AreaAura
                    if(m_spellInfo->Attributes == 0x9050000 || m_spellInfo->Attributes == 0x10000)
                        SetTargetMap(i, TARGET_UNIT_PARTY_TARGET);
                    break;
                case SPELL_EFFECT_SKIN_PLAYER_CORPSE:
                    if(m_targets.getUnitTarget())
                    {
                        AddUnitTarget(m_targets.getUnitTarget(), i);
                    }
                    else if (m_targets.getCorpseTargetGUID())
                    {
                        Corpse *corpse = ObjectAccessor::GetCorpse(*m_caster,m_targets.getCorpseTargetGUID());
                        if(corpse)
                        {
                            Player* owner = ObjectAccessor::FindPlayer(corpse->GetOwnerGUID());
                            if(owner)
                                AddUnitTarget(owner, i);
                        }
                    }
                    break;
                default:
                    AddUnitTarget(m_caster, i);
                    break;
            }
        }
        if(IsChanneledSpell(m_spellInfo))
        {
            uint8 mask = (1<<i);
            for(std::list<TargetInfo>::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
            {
                if(ihit->effectMask & mask)
                {
                    m_needAliveTargetMask |= mask;
                    break;
                }
            }
        }
        else if (m_auraScaleMask)
        {
            bool checkLvl = !m_UniqueTargetInfo.empty();
            for(std::list<TargetInfo>::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end();)
            {
                // remove targets which did not pass min level check
                if(m_auraScaleMask && ihit->effectMask == m_auraScaleMask)
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

    if(m_targets.m_targetMask & TARGET_FLAG_DEST_LOCATION)
    {
        if(m_spellInfo->speed > 0.0f && m_targets.HasDst())
        {
            float dist = m_caster->GetDistance(m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ);
            if (dist < 5.0f) dist = 5.0f;
            m_delayMoment = (uint64) floor(dist / m_spellInfo->speed * 1000.0f);
        }
    }
}

void Spell::prepareDataForTriggerSystem(AuraEffect * triggeredByAura)
{
    //==========================================================================================
    // Now fill data for trigger system, need know:
    // can spell trigger another or not ( m_canTrigger )
    // Create base triggers flags for Attacker and Victim ( m_procAttacker, m_procVictim and m_procEx)
    //==========================================================================================

    m_procVictim = m_procAttacker = 0;
    // Get data for type of attack and fill base info for trigger
    switch (m_spellInfo->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_MELEE:
            m_procAttacker = PROC_FLAG_SUCCESSFUL_MELEE_SPELL_HIT;
            m_procVictim   = PROC_FLAG_TAKEN_MELEE_SPELL_HIT;
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
                m_procAttacker = PROC_FLAG_SUCCESSFUL_RANGED_SPELL_HIT;
                m_procVictim   = PROC_FLAG_TAKEN_RANGED_SPELL_HIT;
            }
            break;
        default:
            if (m_spellInfo->EquippedItemClass == ITEM_CLASS_WEAPON && 
                m_spellInfo->EquippedItemSubClassMask & (1<<ITEM_SUBCLASS_WEAPON_WAND)
                && m_spellInfo->AttributesEx2 & SPELL_ATTR_EX2_AUTOREPEAT_FLAG) // Wands auto attack
            {
                m_procAttacker = PROC_FLAG_SUCCESSFUL_RANGED_HIT;
                m_procVictim   = PROC_FLAG_TAKEN_RANGED_HIT;
            }
            // For other spells trigger procflags are set in Spell::DoAllEffectOnTarget
            // Because spell positivity is dependant on target
    }
    m_procEx= PROC_EX_NONE;

    // Hunter traps spells (for Entrapment trigger)
    // Gives your Immolation Trap, Frost Trap, Explosive Trap, and Snake Trap ....
    if (m_spellInfo->SpellFamilyName == SPELLFAMILY_HUNTER && (m_spellInfo->SpellFamilyFlags[1] & 0x00002000 || m_spellInfo->SpellFamilyFlags[0] & 0x1C))
    {
        m_procAttacker |= PROC_FLAG_ON_TRAP_ACTIVATION;
        // Trigger only from spells originally casted by hunter(trap activation) to prevent multiple trigger from trap triggered spells
        if (m_originalCasterGUID != m_caster->GetGUID() && m_originalCasterGUID)
            return;
    }
    /*
        Effects which are result of aura proc from triggered spell cannot proc
        to prevent chain proc of these spells
    */
    if ((triggeredByAura && !triggeredByAura->GetParentAura()->GetTarget()->CanProc()))
    {
        m_canTrigger=false;
    }

    // Ranged autorepeat attack is set as triggered spell - ignore it
    if (!(m_procAttacker & PROC_FLAG_SUCCESSFUL_RANGED_HIT))
    {
        if (m_IsTriggeredSpell && 
            (m_spellInfo->AttributesEx2 & SPELL_ATTR_EX2_TRIGGERED_CAN_TRIGGER ||
            m_spellInfo->AttributesEx3 & SPELL_ATTR_EX3_TRIGGERED_CAN_TRIGGER_2))
            m_procEx |= PROC_EX_INTERNAL_CANT_PROC;
        else if (m_IsTriggeredSpell)
            m_procEx |= PROC_EX_INTERNAL_TRIGGERED;
    }
    // Totem casts require spellfamilymask defined in spell_proc_event to proc
    if (m_originalCaster && m_caster != m_originalCaster && m_caster->GetTypeId()==TYPEID_UNIT && ((Creature*)m_caster)->isTotem() && m_caster->IsControlledByPlayer())
    {
        m_procEx |= PROC_EX_INTERNAL_REQ_FAMILY;
    }
}

void Spell::CleanupTargetList()
{
    m_UniqueTargetInfo.clear();
    m_UniqueGOTargetInfo.clear();
    m_UniqueItemInfo.clear();
    m_delayMoment = 0;
}

void Spell::AddUnitTarget(Unit* pVictim, uint32 effIndex)
{
    if( m_spellInfo->Effect[effIndex] == 0 )
        return;

    if(!CheckTarget(pVictim, effIndex))
        return;

    // Check for effect immune skip if immuned
    bool immuned = pVictim->IsImmunedToSpellEffect(m_spellInfo, effIndex);

    uint64 targetGUID = pVictim->GetGUID();

    // Lookup target in already in list
    for(std::list<TargetInfo>::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
    {
        if (targetGUID == ihit->targetGUID)                 // Found in list
        {
            if (!immuned)
                ihit->effectMask |= 1 << effIndex;          // Add only effect mask if not immuned
            ihit->scaleAura = false;
            if (m_auraScaleMask && ihit->effectMask == m_auraScaleMask && m_caster != pVictim)
            {
                SpellEntry const * auraSpell = sSpellStore.LookupEntry(spellmgr.GetFirstSpellInChain(m_spellInfo->Id));
                if ((pVictim->getLevel() + 10) >= auraSpell->spellLevel)
                    ihit->scaleAura = true;
            }
            return;
        }
    }

    // This is new target calculate data for him

    // Get spell hit result on target
    TargetInfo target;
    target.targetGUID = targetGUID;                         // Store target GUID
    target.effectMask = immuned ? 0 : 1 << effIndex;        // Store index of effect if not immuned
    target.processed  = false;                              // Effects not apply on target
    target.alive      = pVictim->isAlive();
    target.damage     = 0;
    target.crit       = false;
    target.scaleAura  = false;
    if (m_auraScaleMask && target.effectMask == m_auraScaleMask && m_caster != pVictim)
    {
        SpellEntry const * auraSpell = sSpellStore.LookupEntry(spellmgr.GetFirstSpellInChain(m_spellInfo->Id));
        if ((pVictim->getLevel() + 10) >= auraSpell->spellLevel)
            target.scaleAura = true;
    }

    // Calculate hit result
    if(m_originalCaster)
    {
        target.missCondition = m_originalCaster->SpellHitResult(pVictim, m_spellInfo, m_canReflect);
        if(m_skipCheck && target.missCondition != SPELL_MISS_IMMUNE)
            target.missCondition = SPELL_MISS_NONE;
    }
    else
        target.missCondition = SPELL_MISS_EVADE; //SPELL_MISS_NONE;

    // Spell have speed - need calculate incoming time
    if (m_spellInfo->speed > 0.0f)
    {
        // calculate spell incoming interval
        // TODO: this is a hack
        float dist = m_caster->GetDistance(pVictim->GetPositionX(), pVictim->GetPositionY(), pVictim->GetPositionZ());

        if (dist < 5.0f) dist = 5.0f;
        target.timeDelay = (uint64) floor(dist / m_spellInfo->speed * 1000.0f);

        // Calculate minimum incoming time
        if (m_delayMoment == 0 || m_delayMoment>target.timeDelay)
            m_delayMoment = target.timeDelay;
    }
    else
        target.timeDelay = 0LL;

    // If target reflect spell back to caster
    if (target.missCondition == SPELL_MISS_REFLECT)
    {
        // Calculate reflected spell result on caster
        target.reflectResult =  m_caster->SpellHitResult(m_caster, m_spellInfo, m_canReflect);

        if (target.reflectResult == SPELL_MISS_REFLECT)     // Impossible reflect again, so simply deflect spell
            target.reflectResult = SPELL_MISS_PARRY;

        // Increase time interval for reflected spells by 1.5
        target.timeDelay += target.timeDelay >> 1;
    }
    else
        target.reflectResult = SPELL_MISS_NONE;

    // Add target to list
    m_UniqueTargetInfo.push_back(target);
}

void Spell::AddUnitTarget(uint64 unitGUID, uint32 effIndex)
{
    Unit* unit = m_caster->GetGUID() == unitGUID ? m_caster : ObjectAccessor::GetUnit(*m_caster, unitGUID);
    if (unit)
        AddUnitTarget(unit, effIndex);
}

void Spell::AddGOTarget(GameObject* pVictim, uint32 effIndex)
{
    if( m_spellInfo->Effect[effIndex] == 0 )
        return;

    uint64 targetGUID = pVictim->GetGUID();

    // Lookup target in already in list
    for(std::list<GOTargetInfo>::iterator ihit = m_UniqueGOTargetInfo.begin(); ihit != m_UniqueGOTargetInfo.end(); ++ihit)
    {
        if (targetGUID == ihit->targetGUID)                 // Found in list
        {
            ihit->effectMask |= 1 << effIndex;              // Add only effect mask
            return;
        }
    }

    // This is new target calculate data for him

    GOTargetInfo target;
    target.targetGUID = targetGUID;
    target.effectMask = 1 << effIndex;
    target.processed  = false;                              // Effects not apply on target

    // Spell have speed - need calculate incoming time
    if (m_spellInfo->speed > 0.0f)
    {
        // calculate spell incoming interval
        float dist = m_caster->GetDistance(pVictim->GetPositionX(), pVictim->GetPositionY(), pVictim->GetPositionZ());
        if (dist < 5.0f) dist = 5.0f;
        target.timeDelay = (uint64) floor(dist / m_spellInfo->speed * 1000.0f);
        if (m_delayMoment==0 || m_delayMoment>target.timeDelay)
            m_delayMoment = target.timeDelay;
    }
    else
        target.timeDelay = 0LL;

    // Add target to list
    m_UniqueGOTargetInfo.push_back(target);
}

void Spell::AddGOTarget(uint64 goGUID, uint32 effIndex)
{
    GameObject* go = m_caster->GetMap()->GetGameObject(goGUID);
    if (go)
        AddGOTarget(go, effIndex);
}

void Spell::AddItemTarget(Item* pitem, uint32 effIndex)
{
    if( m_spellInfo->Effect[effIndex] == 0 )
        return;

    // Lookup target in already in list
    for(std::list<ItemTargetInfo>::iterator ihit = m_UniqueItemInfo.begin(); ihit != m_UniqueItemInfo.end(); ++ihit)
    {
        if (pitem == ihit->item)                            // Found in list
        {
            ihit->effectMask |= 1<<effIndex;                // Add only effect mask
            return;
        }
    }

    // This is new target add data

    ItemTargetInfo target;
    target.item       = pitem;
    target.effectMask = 1 << effIndex;
    m_UniqueItemInfo.push_back(target);
}

void Spell::DoAllEffectOnTarget(TargetInfo *target)
{
    if (target->processed)                                  // Check target
        return;
    target->processed = true;                               // Target checked in apply effects procedure

    // Get mask of effects for target
    uint32 mask = target->effectMask;

    Unit* unit = m_caster->GetGUID()==target->targetGUID ? m_caster : ObjectAccessor::GetUnit(*m_caster,target->targetGUID);
    if (!unit)
        return;

    if(unit->isAlive() != target->alive)
        return;

    // Get original caster (if exist) and calculate damage/healing from him data
    Unit *caster = m_originalCaster ? m_originalCaster : m_caster;

    // Skip if m_originalCaster not avaiable
    if (!caster)
        return;

    SpellMissInfo missInfo = target->missCondition;

    // Need init unitTarget by default unit (can changed in code on reflect)
    // Or on missInfo!=SPELL_MISS_NONE unitTarget undefined (but need in trigger subsystem)
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
    bool canEffectTrigger = m_canTrigger && (m_spellInfo->AttributesEx4 & (SPELL_ATTR_EX4_CANT_PROC_FROM_SELFCAST) ? m_caster!=unitTarget : true);
    Unit * spellHitTarget = NULL;

    if (missInfo==SPELL_MISS_NONE)                          // In case spell hit target, do all effect on that target
        spellHitTarget = unit;
    else if (missInfo == SPELL_MISS_REFLECT)                // In case spell reflect from target, do all effect on caster (if hit)
    {
        if (target->reflectResult == SPELL_MISS_NONE)       // If reflected spell hit caster -> do all effect on him
            spellHitTarget = m_caster;
    }

    if(spellHitTarget)
    {
        SpellMissInfo missInfo = DoSpellHitOnUnit(spellHitTarget, mask, target->scaleAura);
        if(missInfo != SPELL_MISS_NONE)
        {
            if(missInfo != SPELL_MISS_MISS)
                m_caster->SendSpellMiss(unit, m_spellInfo->Id, missInfo);
            m_damage = 0;
            spellHitTarget = NULL;
        }
    }

    // Do not take combo points on dodge
    if (m_needComboPoints && m_targets.getUnitTargetGUID() == target->targetGUID)
        if( missInfo != SPELL_MISS_NONE && missInfo != SPELL_MISS_MISS)
            m_needComboPoints = false;

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
                if (mask & (1<<i) && !IsPositiveEffect(m_spellInfo->Id, i))
                {
                    positive = false;
                    break;
                }
        }
        switch(m_spellInfo->DmgClass)
        {
            case SPELL_DAMAGE_CLASS_MAGIC:
                if (positive)
                {
                    procAttacker |= PROC_FLAG_SUCCESSFUL_POSITIVE_MAGIC_SPELL;
                    procVictim   |= PROC_FLAG_TAKEN_POSITIVE_MAGIC_SPELL;
                }
                else
                {
                    procAttacker |= PROC_FLAG_SUCCESSFUL_NEGATIVE_MAGIC_SPELL;
                    procVictim   |= PROC_FLAG_TAKEN_NEGATIVE_MAGIC_SPELL;
                }
            break;
            case SPELL_DAMAGE_CLASS_NONE:
                if (positive)
                {
                    procAttacker |= PROC_FLAG_SUCCESSFUL_POSITIVE_SPELL_HIT;
                    procVictim   |= PROC_FLAG_TAKEN_POSITIVE_SPELL;
                }
                else
                {
                    procAttacker |= PROC_FLAG_SUCCESSFUL_NEGATIVE_SPELL_HIT;
                    procVictim   |= PROC_FLAG_TAKEN_NEGATIVE_SPELL_HIT;
                }
            break;
        }
    }
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

        if (m_spellAura)
            m_spellAura->SetProcDamage(addhealth);

        int32 gain = caster->DealHeal(unitTarget, addhealth, m_spellInfo, crit);
        unitTarget->getHostilRefManager().threatAssist(caster, float(gain) * 0.5f, m_spellInfo);
    }
    // Do damage and triggers
    else if (m_damage > 0)
    {
        // Fill base damage struct (unitTarget - is real spell target)
        SpellNonMeleeDamage damageInfo(caster, unitTarget, m_spellInfo->Id, m_spellSchoolMask);

        // Add bonuses and fill damageInfo struct
        caster->CalculateSpellDamageTaken(&damageInfo, m_damage, m_spellInfo, m_attackType,  target->crit);
        caster->DealDamageMods(damageInfo.target,damageInfo.damage,&damageInfo.absorb);

        // Send log damage message to client
        caster->SendSpellNonMeleeDamageLog(&damageInfo);

        procEx |= createProcExtendMask(&damageInfo, missInfo);
        procVictim |= PROC_FLAG_TAKEN_ANY_DAMAGE;

        // Do triggers for unit (reflect triggers passed on hit phase for correct drop charge)
        if (canEffectTrigger && missInfo != SPELL_MISS_REFLECT)
        {
            caster->ProcDamageAndSpell(unitTarget, procAttacker, procVictim, procEx, damageInfo.damage, m_attackType, m_spellInfo, m_triggeredByAuraSpell);
            if(caster->GetTypeId() == TYPEID_PLAYER && (m_spellInfo->Attributes & SPELL_ATTR_STOP_ATTACK_TARGET) == 0 &&
               (m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MELEE || m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_RANGED))
                ((Player *)caster)->CastItemCombatSpell(unitTarget, m_attackType, procVictim, procEx);
        }

        if (m_spellAura)
            m_spellAura->SetProcDamage(damageInfo.damage);
        caster->DealSpellDamage(&damageInfo, true);

        // Judgement of Blood
        if (m_spellInfo->SpellFamilyName == SPELLFAMILY_PALADIN && m_spellInfo->SpellFamilyFlags[1] & 0x00000008 && m_spellInfo->SpellIconID==153)
        {
            int32 damagePoint  = damageInfo.damage * 33 / 100;
            m_caster->CastCustomSpell(m_caster, 32220, &damagePoint, NULL, NULL, true);
        }
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
    }

    if( !m_caster->IsFriendlyTo(unit) && !IsPositiveSpell(m_spellInfo->Id))
    {
        m_caster->CombatStart(unit, !(m_spellInfo->AttributesEx3 & SPELL_ATTR_EX3_NO_INITIAL_AGGRO));

        if(m_customAttr & SPELL_ATTR_CU_AURA_CC)
        {
            if(!unit->IsStandState())
                unit->SetStandState(UNIT_STAND_STATE_STAND);
        }
    }

    if(spellHitTarget)
    {
        //AI functions
        if(spellHitTarget->GetTypeId() == TYPEID_UNIT)
        {
            if(((Creature*)spellHitTarget)->IsAIEnabled)
                ((Creature*)spellHitTarget)->AI()->SpellHit(m_caster, m_spellInfo);

            // cast at creature (or GO) quest objectives update at successful cast finished (+channel finished)
            // ignore pets or autorepeat/melee casts for speed (not exist quest for spells (hm... )
            if(m_originalCaster && m_originalCaster->IsControlledByPlayer() && !((Creature*)spellHitTarget)->isPet() && !IsAutoRepeat() && !IsNextMeleeSwingSpell() && !IsChannelActive() )
            {
                if ( Player* p = m_originalCaster->GetCharmerOrOwnerPlayerOrPlayerItself() )
                {
                    p->CastedCreatureOrGO(spellHitTarget->GetEntry(),spellHitTarget->GetGUID(),m_spellInfo->Id);
                }
            }
        }

        if(m_caster->GetTypeId() == TYPEID_UNIT && ((Creature*)m_caster)->IsAIEnabled)
            ((Creature*)m_caster)->AI()->SpellHitTarget(spellHitTarget, m_spellInfo);

        // Needs to be called after dealing damage/healing to not remove breaking on damage auras
        DoTriggersOnSpellHit(spellHitTarget);
    }
}

SpellMissInfo Spell::DoSpellHitOnUnit(Unit *unit, const uint32 effectMask, bool scaleAura)
{
    if(!unit || !effectMask)
        return SPELL_MISS_EVADE;

    // Recheck immune (only for delayed spells)
    if(m_spellInfo->speed && (unit->IsImmunedToDamage(m_spellInfo) || unit->IsImmunedToSpell(m_spellInfo)))
        return SPELL_MISS_IMMUNE;

    if (unit->GetTypeId() == TYPEID_PLAYER)
    {
        ((Player*)unit)->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, m_spellInfo->Id);
        ((Player*)unit)->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET2, m_spellInfo->Id);
    }

    if(m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        ((Player*)m_caster)->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL2, m_spellInfo->Id, 0, unit);
    }

    if( m_caster != unit )
    {
        // Recheck  UNIT_FLAG_NON_ATTACKABLE for delayed spells
        if (m_spellInfo->speed > 0.0f &&
            unit->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE) &&
            unit->GetCharmerOrOwnerGUID() != m_caster->GetGUID())
        {
            return SPELL_MISS_EVADE;
        }

        if( !m_caster->IsFriendlyTo(unit) )
        {
            // reset damage to 0 if target has Invisibility or Vanish aura (_only_ vanish, not stealth) and isn't visible for caster
            // I do not think this is a correct way to fix it. Sanctuary effect should make all delayed spells invalid
            // for delayed spells ignore not visible explicit target
            if(m_spellInfo->speed > 0.0f && unit == m_targets.getUnitTarget()
                && (unit->m_invisibilityMask || m_caster->m_invisibilityMask
                || unit->HasAuraTypeWithFamilyFlags(SPELL_AURA_MOD_STEALTH, SPELLFAMILY_ROGUE, SPELLFAMILYFLAG_ROGUE_VANISH))
                && !m_caster->canSeeOrDetect(unit, true))
            {
                // that was causing CombatLog errors
                // return SPELL_MISS_EVADE;
                return SPELL_MISS_MISS; // miss = do not send anything here
            }

            unit->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_HITBYSPELL);
            //TODO: This is a hack. But we do not know what types of stealth should be interrupted by CC
            if((m_customAttr & SPELL_ATTR_CU_AURA_CC) && unit->IsControlledByPlayer())
                unit->RemoveAurasByType(SPELL_AURA_MOD_STEALTH);
        }
        else
        {
            // for delayed spells ignore negative spells (after duel end) for friendly targets
            // TODO: this cause soul transfer bugged
            if(m_spellInfo->speed > 0.0f && unit->GetTypeId() == TYPEID_PLAYER && !IsPositiveSpell(m_spellInfo->Id))
            {
                return SPELL_MISS_EVADE;
            }

            // assisting case, healing and resurrection
            if(unit->hasUnitState(UNIT_STAT_ATTACK_PLAYER))
            {
                m_caster->SetContestedPvP();
                if(m_caster->GetTypeId() == TYPEID_PLAYER)
                    ((Player*)m_caster)->UpdatePvP(true);
            }
            if( unit->isInCombat() && !(m_spellInfo->AttributesEx3 & SPELL_ATTR_EX3_NO_INITIAL_AGGRO) )
            {
                m_caster->SetInCombatState(unit->GetCombatTimer() > 0, unit);
                unit->getHostilRefManager().threatAssist(m_caster, 0.0f);
            }
        }
    }

    // Get Data Needed for Diminishing Returns, some effects may have multiple auras, so this must be done on spell hit, not aura add
    if(m_diminishGroup = GetDiminishingReturnsGroupForSpell(m_spellInfo,m_triggeredByAuraSpell))
    {
        m_diminishLevel = unit->GetDiminishing(m_diminishGroup);
        DiminishingReturnsType type = GetDiminishingReturnsGroupType(m_diminishGroup);
        // Increase Diminishing on unit, current informations for actually casts will use values above
        if((type == DRTYPE_PLAYER && (unit->GetTypeId() == TYPEID_PLAYER || ((Creature*)unit)->isPet() || ((Creature*)unit)->isPossessedByPlayer())) || type == DRTYPE_ALL)
            unit->IncrDiminishing(m_diminishGroup);
    }

    uint8 aura_effmask = 0;
    for (uint8 i = 0; i < 3; ++i)
        if (effectMask & (1<<i) && (m_spellInfo->Effect[i] == SPELL_EFFECT_APPLY_AURA || IsAreaAuraEffect(m_spellInfo->Effect[i])))
            aura_effmask |= 1<<i;

    if (aura_effmask)
    {
        // Select rank for aura with level requirements only in specific cases
        // Unit has to be target only of aura effect, both caster and target have to be players, target has to be other than unit target
        SpellEntry const * aurSpellInfo = m_spellInfo;
        int32 basePoints[3];
        if (scaleAura)
        {
            aurSpellInfo = spellmgr.SelectAuraRankForPlayerLevel(m_spellInfo,unitTarget->getLevel());
            assert (aurSpellInfo);
            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            {
                basePoints[i] = aurSpellInfo->EffectBasePoints[i];
            }
        }
        else
        {
            for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            {
                basePoints[i] = m_currentBasePoints[i];
            }
        }

        Unit * caster = m_originalCaster ? m_originalCaster : m_caster;
        Aura * Aur = new Aura(aurSpellInfo, aura_effmask, basePoints, unit, m_caster, caster, m_CastItem);

        if (!Aur->IsAreaAura())
        {
            // Now Reduce spell duration using data received at spell hit
            int32 duration = Aur->GetAuraMaxDuration();
            int32 limitduration = GetDiminishingReturnsLimitDuration(m_diminishGroup,aurSpellInfo);
            unitTarget->ApplyDiminishingToDuration(m_diminishGroup, duration, caster, m_diminishLevel,limitduration);
            Aur->setDiminishGroup(m_diminishGroup);

            duration = caster->ModSpellDuration(aurSpellInfo, unit, duration, Aur->IsPositive());

            //mod duration of channeled aura by spell haste
            if (IsChanneledSpell(m_spellInfo))
                caster->ModSpellCastTime(aurSpellInfo, duration, this);

            if(duration != Aur->GetAuraMaxDuration())
            {
                Aur->SetAuraMaxDuration(duration);
                Aur->SetAuraDuration(duration);
            }

            // Prayer of Mending (jump animation), we need formal caster instead original for correct animation
            if( aurSpellInfo->SpellFamilyName == SPELLFAMILY_PRIEST)
            {
                if(aurSpellInfo->SpellFamilyFlags[1] & 0x000020)
                    m_caster->CastSpell(unit, 41637, true, NULL, NULL, m_originalCasterGUID);
            }
        }
        // Set aura only when successfully applied
        if (unit->AddAura(Aur, false))
            m_spellAura = Aur;
    }

    for(uint32 effectNumber = 0; effectNumber < 3; ++effectNumber)
    {
        if (effectMask & (1<<effectNumber))
            HandleEffects(unit,NULL,NULL,effectNumber);
    }

    return SPELL_MISS_NONE;
}

void Spell::DoTriggersOnSpellHit(Unit *unit)
{
    // Apply additional spell effects to target
    if (m_preCastSpell)
    {
        // Special spell id
        // TODO: Handle all of special spells in one place?
        if(m_preCastSpell==61988)
        {
            //Cast Forbearance
            m_caster->CastSpell(unit,25771, true, m_CastItem);
            // Cast Avenging Wrath Marker
            m_caster->CastSpell(unit,61987, true, m_CastItem);
        }
        else
            m_caster->CastSpell(unit,m_preCastSpell, true, m_CastItem);
    }

    // spells with this flag can trigger only if not selfcast (eviscerate for example)
    if (m_ChanceTriggerSpells.size() && (!((m_spellInfo->AttributesEx4 & SPELL_ATTR_EX4_CANT_PROC_FROM_SELFCAST) && unit==m_caster)))
    {
        int _duration=0;
        for(ChanceTriggerSpells::const_iterator i = m_ChanceTriggerSpells.begin(); i != m_ChanceTriggerSpells.end(); ++i)
        {
            // SPELL_AURA_ADD_TARGET_TRIGGER auras shouldn't trigger auras without duration
            // set duration equal to triggering spell
            if(roll_chance_i(i->second))
            {
                m_caster->CastSpell(unit, i->first, true);
                sLog.outDebug("Spell %d triggered spell %d by SPELL_AURA_ADD_TARGET_TRIGGER aura", m_spellInfo->Id, i->first->Id);
            }
            if (GetSpellDuration(i->first)==-1)
            {
                if (Aura * triggeredAur = unit->GetAura(i->first->Id, m_caster->GetGUID()))
                {
                    // get duration from aura-only once
                    if (!_duration)
                    {
                        Aura * aur = unit->GetAura(m_spellInfo->Id, m_caster->GetGUID());
                        _duration = aur ? aur->GetAuraDuration() : -1;
                    }
                    triggeredAur->SetAuraDuration(_duration);
                    triggeredAur->SetPermanent(false);
                }
            }
        }
    }

    if(m_customAttr & SPELL_ATTR_CU_LINK_HIT)
    {
        if(const std::vector<int32> *spell_triggered = spellmgr.GetSpellLinked(m_spellInfo->Id + SPELL_LINK_HIT))
            for(std::vector<int32>::const_iterator i = spell_triggered->begin(); i != spell_triggered->end(); ++i)
                if(*i < 0)
                    unit->RemoveAurasDueToSpell(-(*i));
                else
                    unit->CastSpell(unit, *i, true, 0, 0, m_caster->GetGUID());
    }
}

void Spell::DoAllEffectOnTarget(GOTargetInfo *target)
{
    if (target->processed)                                  // Check target
        return;
    target->processed = true;                               // Target checked in apply effects procedure

    uint32 effectMask = target->effectMask;
    if(!effectMask)
        return;

    GameObject* go = m_caster->GetMap()->GetGameObject(target->targetGUID);
    if(!go)
        return;

    for(uint32 effectNumber = 0; effectNumber < 3; ++effectNumber)
        if (effectMask & (1 << effectNumber))
            HandleEffects(NULL, NULL, go, effectNumber);

    // cast at creature (or GO) quest objectives update at successful cast finished (+channel finished)
    // ignore autorepeat/melee casts for speed (not exist quest for spells (hm... )
    if(m_originalCaster && m_originalCaster->IsControlledByPlayer() && !IsAutoRepeat() && !IsNextMeleeSwingSpell() && !IsChannelActive() )
    {
        if ( Player* p = m_originalCaster->GetCharmerOrOwnerPlayerOrPlayerItself() )
            p->CastedCreatureOrGO(go->GetEntry(),go->GetGUID(),m_spellInfo->Id);
    }
}

void Spell::DoAllEffectOnTarget(ItemTargetInfo *target)
{
    uint32 effectMask = target->effectMask;
    if(!target->item || !effectMask)
        return;

    for(uint32 effectNumber = 0; effectNumber < 3; ++effectNumber)
        if (effectMask & (1 << effectNumber))
            HandleEffects(NULL, target->item, NULL, effectNumber);
}

bool Spell::UpdateChanneledTargetList()
{
    // Not need check return true
    if (m_needAliveTargetMask == 0)
        return true;

    uint8 needAliveTargetMask = m_needAliveTargetMask;
    uint8 needAuraMask = 0;
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        if (m_spellInfo->Effect[i] == SPELL_EFFECT_APPLY_AURA)
            needAuraMask |= 1<<i;

    needAuraMask &= needAliveTargetMask;

    float range;
    if(needAuraMask)
    {
        range = GetSpellMaxRange(m_spellInfo, IsPositiveSpell(m_spellInfo->Id));
        if(Player * modOwner = m_caster->GetSpellModOwner())
            modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RANGE, range, this);
    }

    for(std::list<TargetInfo>::iterator ihit= m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
    {
        if( ihit->missCondition == SPELL_MISS_NONE && (needAliveTargetMask & ihit->effectMask) )
        {
            Unit *unit = m_caster->GetGUID() == ihit->targetGUID ? m_caster : ObjectAccessor::GetUnit(*m_caster, ihit->targetGUID);

            if (unit && unit->isAlive())
            {
                if (needAuraMask & ihit->effectMask)
                {
                    if(Aura * aur = unit->GetAura(m_spellInfo->Id, m_originalCasterGUID))
                    {
                        if (m_caster != unit && !m_caster->IsWithinDistInMap(unit,range))
                        {
                            ihit->effectMask &= ~aur->GetEffectMask();
                            unit->RemoveAura(aur);
                            continue;
                        }
                    }
                    else // aura is dispelled
                        continue;
                }

                needAliveTargetMask &= ~ihit->effectMask;   // remove from need alive mask effect that have alive target
            }
        }
    }

    // is all effects from m_needAliveTargetMask have alive targets
    return needAliveTargetMask == 0;
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
        /*if (Target == MainTarget)
            return 0;
        else*/ if (Target->GetTypeId() == TYPEID_PLAYER && MainTarget->GetTypeId() == TYPEID_PLAYER &&
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

// Helper for targets nearest to the spell target
// The spell target is always first unless there is a target at _completely_ the same position (unbelievable case)
struct TargetDistanceOrder : public std::binary_function<const Unit, const Unit, bool>
{
    const Unit* MainTarget;
    TargetDistanceOrder(const Unit* Target) : MainTarget(Target) {};
    // functor for operator ">"
    bool operator()(const Unit* _Left, const Unit* _Right) const
    {
        return MainTarget->GetDistanceOrder(_Left,_Right);
    }
};

void Spell::SearchChainTarget(std::list<Unit*> &TagUnitMap, float max_range, uint32 num, SpellTargets TargetType)
{
    Unit *cur = m_targets.getUnitTarget();
    if(!cur)
        return;

    // Get spell max affected targets
    /*uint32 unMaxTargets = m_spellInfo->MaxAffectedTargets;
    Unit::AuraList const& mod = m_caster->GetAurasByType(SPELL_AURA_MOD_MAX_AFFECTED_TARGETS);
    for(Unit::AuraList::const_iterator m = mod.begin(); m != mod.end(); ++m)
    {
        if (!(*m)->isAffectedOnSpell(m_spellInfo))
            continue;
        unMaxTargets+=(*m)->GetAmount();
    }*/

    //FIXME: This very like horrible hack and wrong for most spells
    if(m_spellInfo->DmgClass != SPELL_DAMAGE_CLASS_MELEE)
        max_range += num * CHAIN_SPELL_JUMP_RADIUS;

    std::list<Unit*> tempUnitMap;
    if(TargetType == SPELL_TARGETS_CHAINHEAL)
    {
        SearchAreaTarget(tempUnitMap, max_range, PUSH_CHAIN, SPELL_TARGETS_ALLY);
        tempUnitMap.sort(ChainHealingOrder(m_caster));
        //if(cur->GetHealth() == cur->GetMaxHealth() && tempUnitMap.size())
        //    cur = tempUnitMap.front();
    }
    else
        SearchAreaTarget(tempUnitMap, max_range, PUSH_CHAIN, TargetType);
    tempUnitMap.remove(cur);

    while(num)
    {
        TagUnitMap.push_back(cur);
        --num;

        if(tempUnitMap.empty())
            break;

        std::list<Unit*>::iterator next;

        if(TargetType == SPELL_TARGETS_CHAINHEAL)
        {
            next = tempUnitMap.begin();
            while(cur->GetDistance(*next) > CHAIN_SPELL_JUMP_RADIUS
                || !cur->IsWithinLOSInMap(*next))
            {
                ++next;
                if(next == tempUnitMap.end())
                    return;
            }
        }
        else
        {
            tempUnitMap.sort(TargetDistanceOrder(cur));
            next = tempUnitMap.begin();

            if(cur->GetDistance(*next) > CHAIN_SPELL_JUMP_RADIUS)
                break;
            while(m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MELEE
                && !m_caster->isInFrontInMap(*next, max_range)
                || !m_caster->canSeeOrDetect(*next, false)
                || !cur->IsWithinLOSInMap(*next))
            {
                ++next;
                if(next == tempUnitMap.end() || cur->GetDistance(*next) > CHAIN_SPELL_JUMP_RADIUS)
                    return;
            }
        }

        cur = *next;
        tempUnitMap.erase(next);
    }
}

void Spell::SearchAreaTarget(std::list<Unit*> &TagUnitMap, float radius, SpellNotifyPushType type, SpellTargets TargetType, uint32 entry)
{
    float x, y, z;
    switch(type)
    {
        case PUSH_DST_CENTER:
            CheckDst();
            x = m_targets.m_destX;
            y = m_targets.m_destY;
            z = m_targets.m_destZ;
            break;
        case PUSH_SRC_CENTER:
            CheckSrc();
            x = m_targets.m_srcX;
            y = m_targets.m_srcY;
            z = m_targets.m_srcZ;
            break;
        case PUSH_CHAIN:
        {
            Unit *target = m_targets.getUnitTarget();
            if(!target)
            {
                sLog.outError( "SPELL: cannot find unit target for spell ID %u\n", m_spellInfo->Id );
                return;
            }
            x = target->GetPositionX();
            y = target->GetPositionY();
            z = target->GetPositionZ();
            break;
        }
        default:
            x = m_caster->GetPositionX();
            y = m_caster->GetPositionY();
            z = m_caster->GetPositionZ();
            break;
    }

    Trinity::SpellNotifierCreatureAndPlayer notifier(*this, TagUnitMap, radius, type, TargetType, entry, x, y, z);
    if((m_spellInfo->AttributesEx3 & SPELL_ATTR_EX3_PLAYERS_ONLY)
        || TargetType == SPELL_TARGETS_ENTRY && !entry)
        m_caster->GetMap()->VisitWorld(x, y, radius, notifier);
    else
        m_caster->GetMap()->VisitAll(x, y, radius, notifier);

    if(m_customAttr & SPELL_ATTR_CU_EXCLUDE_SELF)
        TagUnitMap.remove(m_caster);
}

WorldObject* Spell::SearchNearbyTarget(float range, SpellTargets TargetType)
{
    switch(TargetType)
    {
        case SPELL_TARGETS_ENTRY:
        {
            SpellScriptTarget::const_iterator lower = spellmgr.GetBeginSpellScriptTarget(m_spellInfo->Id);
            SpellScriptTarget::const_iterator upper = spellmgr.GetEndSpellScriptTarget(m_spellInfo->Id);
            if(lower == upper)
            {
                sLog.outDebug("Spell (ID: %u) (caster Entry: %u) does not have record in `spell_script_target`", m_spellInfo->Id, m_caster->GetEntry());
                if(IsPositiveSpell(m_spellInfo->Id))
                    return SearchNearbyTarget(range, SPELL_TARGETS_ALLY);
                else
                    return SearchNearbyTarget(range, SPELL_TARGETS_ENEMY);
            }

            Creature* creatureScriptTarget = NULL;
            GameObject* goScriptTarget = NULL;

            for(SpellScriptTarget::const_iterator i_spellST = lower; i_spellST != upper; ++i_spellST)
            {
                switch(i_spellST->second.type)
                {
                    case SPELL_TARGET_TYPE_CONTROLLED:
                        for(Unit::ControlList::iterator itr = m_caster->m_Controlled.begin(); itr != m_caster->m_Controlled.end(); ++itr)
                            if ((*itr)->GetEntry() == i_spellST->second.targetEntry && (*itr)->IsWithinDistInMap(m_caster, range))
                            {
                                goScriptTarget = NULL;
                                range = m_caster->GetDistance(creatureScriptTarget);
                                creatureScriptTarget = ((Creature *)*itr);
                            }
                        break;
                    case SPELL_TARGET_TYPE_GAMEOBJECT:
                        if(i_spellST->second.targetEntry)
                        {
                            if(GameObject *go = m_caster->FindNearestGameObject(i_spellST->second.targetEntry, range))
                            {
                                // remember found target and range, next attempt will find more near target with another entry
                                goScriptTarget = go;
                                creatureScriptTarget = NULL;
                                range = m_caster->GetDistance(goScriptTarget);
                            }
                        }
                        else if( focusObject )          //Focus Object
                        {
                            float frange = m_caster->GetDistance(focusObject);
                            if(range >= frange)
                            {
                                creatureScriptTarget = NULL;
                                goScriptTarget = focusObject;
                                range = frange;
                            }
                        }
                        break;
                    case SPELL_TARGET_TYPE_CREATURE:
                        if(m_targets.getUnitTarget() && m_targets.getUnitTarget()->GetEntry() == i_spellST->second.targetEntry)
                            return m_targets.getUnitTarget();
                    case SPELL_TARGET_TYPE_DEAD:
                    default:
                        if(Creature *cre = m_caster->FindNearestCreature(i_spellST->second.targetEntry, range, i_spellST->second.type != SPELL_TARGET_TYPE_DEAD))
                        {
                            creatureScriptTarget = cre;
                            goScriptTarget = NULL;
                            range = m_caster->GetDistance(creatureScriptTarget);
                        }
                        break;
                }
            }

            if(creatureScriptTarget)
                return creatureScriptTarget;
            else
                return goScriptTarget;
        }
        default:
        case SPELL_TARGETS_ENEMY:
        {
            Unit *target = NULL;
            Trinity::AnyUnfriendlyUnitInObjectRangeCheck u_check(m_caster, m_caster, range);
            Trinity::UnitLastSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(m_caster, target, u_check);
            m_caster->VisitNearbyObject(range, searcher);
            return target;
        }
        case SPELL_TARGETS_ALLY:
        {
            Unit *target = NULL;
            Trinity::AnyFriendlyUnitInObjectRangeCheck u_check(m_caster, m_caster, range);
            Trinity::UnitLastSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(m_caster, target, u_check);
            m_caster->VisitNearbyObject(range, searcher);
            return target;
        }
    }
}

void Spell::SetTargetMap(uint32 i, uint32 cur)
{
    SpellNotifyPushType pushType = PUSH_NONE;
    Player *modOwner = NULL;
    if(m_originalCaster)
        modOwner = m_originalCaster->GetSpellModOwner();

    switch(spellmgr.SpellTargetType[cur])
    {
        case TARGET_TYPE_UNIT_CASTER:
        {
            switch(cur)
            {
                case TARGET_UNIT_CASTER:
                    AddUnitTarget(m_caster, i);
                    break;
                case TARGET_UNIT_CASTER_FISHING:
                {
                    //AddUnitTarget(m_caster, i);
                    float min_dis = GetSpellMinRange(m_spellInfo, true);
                    float max_dis = GetSpellMaxRange(m_spellInfo, true);
                    float dis = rand_norm() * (max_dis - min_dis) + min_dis;
                    float x, y, z;
                    m_caster->GetClosePoint(x, y, z, DEFAULT_WORLD_OBJECT_SIZE, dis);
                    m_targets.setDestination(x, y, z);
                    break;
                }
                case TARGET_UNIT_MASTER:
                    if(Unit* owner = m_caster->GetCharmerOrOwner())
                        AddUnitTarget(owner, i);
                    break;
                case TARGET_UNIT_PET:
                    if(Guardian* pet = m_caster->GetGuardianPet())
                        AddUnitTarget(pet, i);
                    break;
                case TARGET_UNIT_PARTY_CASTER:
                case TARGET_UNIT_RAID_CASTER:
                    pushType = PUSH_CASTER_CENTER;
                    break;
                case TARGET_UNIT_VEHICLE:
                    if(Vehicle *vehicle = m_caster->m_Vehicle)
                        AddUnitTarget(vehicle, i);
                    break;
                case TARGET_UNIT_PASSENGER:
                    if(m_caster->GetTypeId() == TYPEID_UNIT && ((Creature*)m_caster)->isVehicle())
                        if(Unit *unit = ((Vehicle*)m_caster)->GetPassenger(1)) // maybe not right
                            AddUnitTarget(unit, i);
                    break;
            }
            break;
        }

        case TARGET_TYPE_UNIT_TARGET:
        {
            Unit *target = m_targets.getUnitTarget();
            if(!target)
            {
                sLog.outError("SPELL: no unit target for spell ID %u", m_spellInfo->Id);
                break;
            }

            switch(cur)
            {
                case TARGET_UNIT_TARGET_ENEMY:
                    if(Unit *magnet = m_caster->SelectMagnetTarget(target, m_spellInfo))
                        if(magnet != target)
                            m_targets.setUnitTarget(magnet);
                    pushType = PUSH_CHAIN;
                    break;
                case TARGET_UNIT_TARGET_ANY:
                    if(!IsPositiveSpell(m_spellInfo->Id))
                        if(Unit *magnet = m_caster->SelectMagnetTarget(target, m_spellInfo))
                            if(magnet != target)
                                m_targets.setUnitTarget(magnet);
                    pushType = PUSH_CHAIN;
                    break;
                case TARGET_UNIT_CHAINHEAL:
                    pushType = PUSH_CHAIN;
                    break;
                case TARGET_UNIT_TARGET_ALLY:
                case TARGET_UNIT_TARGET_RAID:
                case TARGET_UNIT_TARGET_PARTY:
                case TARGET_UNIT_MINIPET:
                    AddUnitTarget(target, i);
                    break;
                case TARGET_UNIT_PARTY_TARGET:
                case TARGET_UNIT_CLASS_TARGET:
                    pushType = PUSH_CASTER_CENTER; // not real
                    break;
            }
            break;
        }

        case TARGET_TYPE_UNIT_NEARBY:
        {
            WorldObject *target = NULL;
            float range;

            switch(cur)
            {
                case TARGET_UNIT_NEARBY_ENEMY:
                    range = GetSpellMaxRange(m_spellInfo, false);
                    if(modOwner) modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RANGE, range, this);
                    target = SearchNearbyTarget(range, SPELL_TARGETS_ENEMY);
                    break;
                case TARGET_UNIT_NEARBY_ALLY:
                case TARGET_UNIT_NEARBY_ALLY_UNK:
                case TARGET_UNIT_NEARBY_RAID:
                    range = GetSpellMaxRange(m_spellInfo, true);
                    if(modOwner) modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RANGE, range, this);
                    target = SearchNearbyTarget(range, SPELL_TARGETS_ALLY);
                    break;
                case TARGET_UNIT_NEARBY_ENTRY:
                    range = GetSpellMaxRange(m_spellInfo, IsPositiveSpell(m_spellInfo->Id));
                    if(modOwner) modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RANGE, range, this);
                    target = SearchNearbyTarget(range, SPELL_TARGETS_ENTRY);
                    break;
            }

            if(!target)
                return;
            else if(target->GetTypeId() == TYPEID_GAMEOBJECT)
                AddGOTarget((GameObject*)target, i);
            else
            {
                pushType = PUSH_CHAIN;

                if(m_targets.getUnitTarget() != target)
                    m_targets.setUnitTarget((Unit*)target);
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
            if(m_customAttr & SPELL_ATTR_CU_CONE_BACK)
                pushType = PUSH_IN_BACK;
            else if(m_customAttr & SPELL_ATTR_CU_CONE_LINE)
                pushType = PUSH_IN_LINE;
            else
                pushType = PUSH_IN_FRONT;
            break;
           
        case TARGET_TYPE_DEST_CASTER: //4+8+2
        {
            if(cur == TARGET_SRC_CASTER)
            {
                m_targets.setSrc(m_caster);
                break;
            }
            else if(cur == TARGET_DST_CASTER)
            {
                m_targets.setDestination(m_caster);
                break;
            }

            float x, y, z, angle, dist;

            float objSize = m_caster->GetObjectSize();
            dist = GetSpellRadiusForFriend(sSpellRadiusStore.LookupEntry(m_spellInfo->EffectRadiusIndex[i]));
            if(dist < objSize)
                dist = objSize;
            else if(cur == TARGET_DEST_CASTER_RANDOM)
                dist = objSize + (dist - objSize) * rand_norm();

            switch(cur)
            {
                case TARGET_DEST_CASTER_FRONT_LEFT: angle = -M_PI/4;    break;
                case TARGET_DEST_CASTER_BACK_LEFT:  angle = -3*M_PI/4;  break;
                case TARGET_DEST_CASTER_BACK_RIGHT: angle = 3*M_PI/4;   break;
                case TARGET_DEST_CASTER_FRONT_RIGHT:angle = M_PI/4;     break;
                case TARGET_MINION:
                case TARGET_DEST_CASTER_FRONT_LEAP:
                case TARGET_DEST_CASTER_FRONT:      angle = 0.0f;       break;
                case TARGET_DEST_CASTER_BACK:       angle = M_PI;       break;
                case TARGET_DEST_CASTER_RIGHT:      angle = M_PI/2;     break;
                case TARGET_DEST_CASTER_LEFT:       angle = -M_PI/2;    break;
                default:                            angle = rand_norm()*2*M_PI; break;
            }

            m_caster->GetGroundPointAroundUnit(x, y, z, dist, angle);
            m_targets.setDestination(x, y, z);
            break;
        }

        case TARGET_TYPE_DEST_TARGET: //2+8+2
        {
            Unit *target = m_targets.getUnitTarget();
            if(!target)
            {
                sLog.outError("SPELL: no unit target for spell ID %u\n", m_spellInfo->Id);
                break;
            }

            if(cur == TARGET_DST_TARGET_ENEMY || cur == TARGET_DEST_TARGET_ANY)
            {
                m_targets.setDestination(target);
                break;
            }

            float x, y, z, angle, dist;

            float objSize = target->GetObjectSize();
            dist = target->GetSpellRadiusForTarget(target, sSpellRadiusStore.LookupEntry(m_spellInfo->EffectRadiusIndex[i]));
            if(dist < objSize)
                dist = objSize;
            else if(cur == TARGET_DEST_CASTER_RANDOM)
                dist = objSize + (dist - objSize) * rand_norm();

            switch(cur)
            {
                case TARGET_DEST_TARGET_FRONT:      angle = 0.0f;       break;
                case TARGET_DEST_TARGET_BACK:       angle = M_PI;       break;
                case TARGET_DEST_TARGET_RIGHT:      angle = M_PI/2;     break;
                case TARGET_DEST_TARGET_LEFT:       angle = -M_PI/2;    break;
                case TARGET_DEST_TARGET_FRONT_LEFT: angle = -M_PI/4;    break;
                case TARGET_DEST_TARGET_BACK_LEFT:  angle = -3*M_PI/4;  break;
                case TARGET_DEST_TARGET_BACK_RIGHT: angle = 3*M_PI/4;   break;
                case TARGET_DEST_TARGET_FRONT_RIGHT:angle = M_PI/4;     break;
                default:                            angle = rand_norm()*2*M_PI; break;
            }

            target->GetGroundPointAroundUnit(x, y, z, dist, angle);
            m_targets.setDestination(x, y, z);
            break;
        }

        case TARGET_TYPE_DEST_DEST: //5+8+1
        {
            if(!m_targets.HasDst())
            {
                sLog.outError("SPELL: no destination for spell ID %u\n", m_spellInfo->Id);
                break;
            }

            float angle;
            switch(cur)
            {
                case TARGET_DEST_DYNOBJ_ENEMY:
                case TARGET_DEST_DYNOBJ_ALLY:
                case TARGET_DEST_DYNOBJ_NONE:
                case TARGET_DEST_DEST:
                case TARGET_DEST_TRAJ:
                    return;
                case TARGET_DEST_DEST_FRONT:      angle = 0.0f;       break;
                case TARGET_DEST_DEST_BACK:       angle = M_PI;       break;
                case TARGET_DEST_DEST_RIGHT:      angle = M_PI/2;     break;
                case TARGET_DEST_DEST_LEFT:       angle = -M_PI/2;    break;
                case TARGET_DEST_DEST_FRONT_LEFT: angle = -M_PI/4;    break;
                case TARGET_DEST_DEST_BACK_LEFT:  angle = -3*M_PI/4;  break;
                case TARGET_DEST_DEST_BACK_RIGHT: angle = 3*M_PI/4;   break;
                case TARGET_DEST_DEST_FRONT_RIGHT:angle = M_PI/4;     break;
                default:                          angle = rand_norm()*2*M_PI; break;
            }

            float dist, x, y, z;
            dist = GetSpellRadiusForFriend(sSpellRadiusStore.LookupEntry(m_spellInfo->EffectRadiusIndex[i]));
            if (cur == TARGET_DEST_DEST_RANDOM)
                dist *= rand_norm();

            x = m_targets.m_destX;
            y = m_targets.m_destY;
            z = m_targets.m_destZ;
            m_caster->GetGroundPoint(x, y, z, dist, angle);
            m_targets.setDestination(x, y, z);
            break;
        }

        case TARGET_TYPE_DEST_SPECIAL:
        {
            switch(cur)
            {
                case TARGET_DST_DB:
                    if(SpellTargetPosition const* st = spellmgr.GetSpellTargetPosition(m_spellInfo->Id))
                    {
                        //TODO: fix this check
                        if(m_spellInfo->Effect[0] == SPELL_EFFECT_TELEPORT_UNITS
                            || m_spellInfo->Effect[1] == SPELL_EFFECT_TELEPORT_UNITS
                            || m_spellInfo->Effect[2] == SPELL_EFFECT_TELEPORT_UNITS)
                            m_targets.setDestination(st->target_X, st->target_Y, st->target_Z, (int32)st->target_mapId);
                        else if(st->target_mapId == m_caster->GetMapId())
                            m_targets.setDestination(st->target_X, st->target_Y, st->target_Z);
                    }
                    else
                    {
                        sLog.outDebug( "SPELL: unknown target coordinates for spell ID %u", m_spellInfo->Id );
                        Unit *target = NULL;
                        if(uint64 guid = m_caster->GetUInt64Value(UNIT_FIELD_TARGET))
                            target = ObjectAccessor::GetUnit(*m_caster, guid);
                        m_targets.setDestination(target ? target : m_caster);
                    }
                    break;
                case TARGET_DST_HOME:
                    if(m_caster->GetTypeId() == TYPEID_PLAYER)
                        m_targets.setDestination(((Player*)m_caster)->m_homebindX,((Player*)m_caster)->m_homebindY,((Player*)m_caster)->m_homebindZ, ((Player*)m_caster)->m_homebindMapId);
                    break;
                case TARGET_DST_NEARBY_ENTRY:
                {
                    float range = GetSpellMaxRange(m_spellInfo, IsPositiveSpell(m_spellInfo->Id));
                    if(modOwner) modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RANGE, range, this);

                    if(WorldObject *target = SearchNearbyTarget(range, SPELL_TARGETS_ENTRY))
                        m_targets.setDestination(target);
                    break;
                }
            }
            break;
        }

        case TARGET_TYPE_CHANNEL:
        {
            if(!m_originalCaster || !m_originalCaster->m_currentSpells[CURRENT_CHANNELED_SPELL])
            {
                sLog.outError( "SPELL: no current channeled spell for spell ID %u", m_spellInfo->Id );
                break;
            }

            switch(cur)
            {
                case TARGET_UNIT_CHANNEL:
                    if(Unit* target = m_originalCaster->m_currentSpells[CURRENT_CHANNELED_SPELL]->m_targets.getUnitTarget())
                        AddUnitTarget(target, i);
                    else
                        sLog.outError( "SPELL: cannot find channel spell target for spell ID %u", m_spellInfo->Id );
                    break;
                case TARGET_DEST_CHANNEL:
                    if(m_originalCaster->m_currentSpells[CURRENT_CHANNELED_SPELL]->m_targets.HasDst())
                        m_targets = m_originalCaster->m_currentSpells[CURRENT_CHANNELED_SPELL]->m_targets;
                    else if(Unit* target = m_originalCaster->m_currentSpells[CURRENT_CHANNELED_SPELL]->m_targets.getUnitTarget())
                        m_targets.setDestination(target);
                    else
                        sLog.outError( "SPELL: cannot find channel spell destination for spell ID %u", m_spellInfo->Id );
                    break;
            }
            break;
        }

        default:
        {
            switch(cur)
            {
                case TARGET_GAMEOBJECT:
                case TARGET_OBJECT_USE:
                    if(m_targets.getGOTarget())
                        AddGOTarget(m_targets.getGOTarget(), i);
                    break;
                case TARGET_GAMEOBJECT_ITEM:
                    if(m_targets.getGOTargetGUID())
                        AddGOTarget(m_targets.getGOTarget(), i);
                    else if(m_targets.getItemTarget())
                        AddItemTarget(m_targets.getItemTarget(), i);
                    break;
                default:
                    sLog.outError("Unhandled spell target %u", cur);
                    break;
            }
            break;
        }
    }

    if(pushType == PUSH_CHAIN) // Chain
    {
        Unit *target = m_targets.getUnitTarget();
        if(!target)
        {
            sLog.outError("SPELL: no chain unit target for spell ID %u", m_spellInfo->Id);
            return;
        }

        //Chain: 2, 6, 22, 25, 45, 77
        uint32 maxTargets = m_spellInfo->EffectChainTarget[i];
        if(modOwner)
            modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_JUMP_TARGETS, maxTargets, this);

        if(maxTargets > 1)
        {
            //otherwise, this multiplier is used for something else
            m_damageMultipliers[i] = 1.0f;
            m_applyMultiplierMask |= 1 << i;

            float range;
            std::list<Unit*> unitList;

            switch(cur)
            {
                case TARGET_UNIT_NEARBY_ENEMY:
                case TARGET_UNIT_TARGET_ENEMY:
                case TARGET_UNIT_NEARBY_ENTRY: // fix me
                    range = GetSpellMaxRange(m_spellInfo, false);
                    if(modOwner) modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RANGE, range, this);
                    SearchChainTarget(unitList, range, maxTargets, SPELL_TARGETS_ENEMY);
                    break;
                case TARGET_UNIT_CHAINHEAL:
                case TARGET_UNIT_NEARBY_ALLY:  // fix me
                case TARGET_UNIT_NEARBY_ALLY_UNK:
                case TARGET_UNIT_NEARBY_RAID:
                    range = GetSpellMaxRange(m_spellInfo, true);
                    if(modOwner) modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RANGE, range, this);
                    SearchChainTarget(unitList, range, maxTargets, SPELL_TARGETS_CHAINHEAL);
                    break;
            }
            
            for(std::list<Unit*>::iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
                AddUnitTarget(*itr, i);
        }
        else
            AddUnitTarget(target, i);
    }
    else if(pushType)
    {
        // Dummy, just for client
        if(spellmgr.EffectTargetType[m_spellInfo->Effect[i]] != SPELL_REQUIRE_UNIT)
            return;

        float radius;
        SpellTargets targetType;
        switch(cur)
        {
            case TARGET_UNIT_AREA_ENEMY_SRC:
            case TARGET_UNIT_AREA_ENEMY_DST:
            case TARGET_UNIT_CONE_ENEMY:
            case TARGET_UNIT_CONE_ENEMY_UNKNOWN:
            case TARGET_UNIT_AREA_PATH:
                radius = GetSpellRadius(m_spellInfo, i, false);
                targetType = SPELL_TARGETS_ENEMY;
                break;
            case TARGET_UNIT_AREA_ALLY_SRC:
            case TARGET_UNIT_AREA_ALLY_DST:
            case TARGET_UNIT_CONE_ALLY:
                radius = GetSpellRadius(m_spellInfo, i, true);
                targetType = SPELL_TARGETS_ALLY;
                break;
            case TARGET_UNIT_AREA_ENTRY_DST:
            case TARGET_UNIT_AREA_ENTRY_SRC:
            case TARGET_UNIT_CONE_ENTRY: // fix me
                radius = GetSpellRadius(m_spellInfo, i, IsPositiveSpell(m_spellInfo->Id));
                targetType = SPELL_TARGETS_ENTRY;
                break;
            default:
                radius = GetSpellRadius(m_spellInfo, i, true);
                targetType = SPELL_TARGETS_NONE;
                break;
        }

        if(modOwner)
            modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RADIUS, radius, this);
        radius *= m_spellValue->RadiusMod;

        std::list<Unit*> unitList;
        if(targetType == SPELL_TARGETS_ENTRY)
        {
            SpellScriptTarget::const_iterator lower = spellmgr.GetBeginSpellScriptTarget(m_spellInfo->Id);
            SpellScriptTarget::const_iterator upper = spellmgr.GetEndSpellScriptTarget(m_spellInfo->Id);
            if(lower == upper)
            {
                // Custom entries
                // TODO: move these to sql
                switch (m_spellInfo->Id)
                {
                    case 46584: // Raise Dead
                    {
                        m_targets.m_targetMask &= ~TARGET_FLAG_DEST_LOCATION;
                        WorldObject* result = FindCorpseUsing<MaNGOS::RaiseDeadObjectCheck> ();
                        if(result)
                        {
                            switch(result->GetTypeId())
                            {
                                case TYPEID_UNIT:
                                    m_targets.setDestination(result);
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
                        if (!(m_targets.getUnitTarget() && (m_targets.getUnitTarget()->GetEntry() == 26125 && m_targets.getUnitTarget()->GetOwnerGUID() == m_caster->GetGUID()
                            || (m_targets.getUnitTarget()->getDeathState() == CORPSE
                                && m_targets.getUnitTarget()->GetDisplayId() == m_targets.getUnitTarget()->GetNativeDisplayId() 
                                && m_targets.getUnitTarget()->GetTypeId()== TYPEID_UNIT
                                && !((Creature*)m_targets.getUnitTarget())->isDeadByDefault()
                                && !(m_targets.getUnitTarget()->GetCreatureTypeMask() & CREATURE_TYPEMASK_MECHANICAL_OR_ELEMENTAL))
                                && m_targets.getUnitTarget()->GetDisplayId() == m_targets.getUnitTarget()->GetNativeDisplayId())))
                        {
                            CleanupTargetList();

                            WorldObject* result = FindCorpseUsing <Trinity::ExplodeCorpseObjectCheck> ();

                            if(result)
                            {
                                switch(result->GetTypeId())
                                {
                                case TYPEID_UNIT:
                                case TYPEID_PLAYER:
                                    m_targets.setUnitTarget((Unit*)result);
                                    break;
                                }
                            }
                            else
                            {
                                if (m_caster->GetTypeId()==TYPEID_PLAYER)
                                    ((Player*)m_caster)->RemoveSpellCooldown(m_spellInfo->Id,true);
                                SendCastResult(SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW);
                                finish(false);
                            }
                        }
                        break;

                    default:
                        sLog.outDebug("Spell (ID: %u) (caster Entry: %u) does not have record in `spell_script_target`", m_spellInfo->Id, m_caster->GetEntry());

                        if(m_spellInfo->Effect[i] == SPELL_EFFECT_TELEPORT_UNITS)
                            SearchAreaTarget(unitList, radius, pushType, SPELL_TARGETS_ENTRY, 0);
                        else if(IsPositiveEffect(m_spellInfo->Id, i))
                            SearchAreaTarget(unitList, radius, pushType, SPELL_TARGETS_ALLY);
                        else
                            SearchAreaTarget(unitList, radius, pushType, SPELL_TARGETS_ENEMY);
                }
            }
            // let it be done in one check?
            else
            {
                for(SpellScriptTarget::const_iterator i_spellST = lower; i_spellST != upper; ++i_spellST)
                {
                    if(i_spellST->second.type == SPELL_TARGET_TYPE_CREATURE)
                        SearchAreaTarget(unitList, radius, pushType, SPELL_TARGETS_ENTRY, i_spellST->second.targetEntry);
                    else if (i_spellST->second.type == SPELL_TARGET_TYPE_CONTROLLED)
                    {
                        for(Unit::ControlList::iterator itr = m_caster->m_Controlled.begin(); itr != m_caster->m_Controlled.end(); ++itr)
                            if ((*itr)->GetEntry() == i_spellST->second.targetEntry && (*itr)->IsWithinDistInMap(m_caster, radius))
                                unitList.push_back(*itr);
                    }
                }
            }
        }
        else if(targetType)
            SearchAreaTarget(unitList, radius, pushType, targetType);
        else
        {
            switch(cur)
            {
                case TARGET_UNIT_AREA_PARTY_SRC:
                case TARGET_UNIT_AREA_PARTY_DST:
                    m_caster->GetPartyMemberInDist(unitList, radius); //fix me
                    break;
                case TARGET_OBJECT_AREA_SRC: // fix me
                case TARGET_OBJECT_AREA_DST:
                {
                    float x, y, z;
                    if(cur == TARGET_OBJECT_AREA_SRC)
                    {
                        if(m_targets.HasSrc())
                        {
                            x = m_targets.m_srcX;
                            y = m_targets.m_srcY;
                            z = m_targets.m_srcZ;
                        }
                        else
                            break;
                    }
                    else if(m_targets.HasDst())
                    {
                        x = m_targets.m_destX;
                        y = m_targets.m_destY;
                        z = m_targets.m_destZ;
                    }
                    else
                        break;

                    Trinity::GameObjectInRangeCheck check(x, y, z, radius + 50);
                    std::list<GameObject*> goList;
                    Trinity::GameObjectListSearcher<Trinity::GameObjectInRangeCheck> searcher(m_caster, goList, check);
                    m_caster->GetMap()->VisitGrid(x, y, radius, searcher);
                    for(std::list<GameObject*>::iterator itr = goList.begin(); itr != goList.end(); ++itr)
                        AddGOTarget(*itr, i);
                    break;
                }
                case TARGET_UNIT_PARTY_TARGET:
                    m_targets.getUnitTarget()->GetPartyMemberInDist(unitList, radius);
                    break;
                case TARGET_UNIT_PARTY_CASTER:
                    m_caster->GetPartyMemberInDist(unitList, radius);
                    break;
                case TARGET_UNIT_RAID_CASTER:
                    m_caster->GetRaidMember(unitList, radius);
                    break;
                case TARGET_UNIT_CLASS_TARGET:
                {
                    Player* targetPlayer = m_targets.getUnitTarget() && m_targets.getUnitTarget()->GetTypeId() == TYPEID_PLAYER
                        ? (Player*)m_targets.getUnitTarget() : NULL;

                    Group* pGroup = targetPlayer ? targetPlayer->GetGroup() : NULL;
                    if(pGroup)
                    {
                        for(GroupReference *itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
                        {
                            Player* Target = itr->getSource();

                            // IsHostileTo check duel and controlled by enemy
                            if( Target && targetPlayer->IsWithinDistInMap(Target, radius) &&
                                targetPlayer->getClass() == Target->getClass() &&
                                !m_caster->IsHostileTo(Target) )
                            {
                                AddUnitTarget(Target, i);
                            }
                        }
                    }
                    else if(m_targets.getUnitTarget())
                        AddUnitTarget(m_targets.getUnitTarget(), i);
                    break;
                }
            }
        }

        if(!unitList.empty())
        {
            if(uint32 maxTargets = m_spellValue->MaxAffectedTargets)
            {
                Unit::AuraEffectList const& Auras = m_caster->GetAurasByType(SPELL_AURA_MOD_MAX_AFFECTED_TARGETS);
                for(Unit::AuraEffectList::const_iterator j = Auras.begin();j != Auras.end(); ++j)
                    if((*j)->isAffectedOnSpell(m_spellInfo))
                        maxTargets += (*j)->GetAmount();

                if(m_spellInfo->Id == 5246) //Intimidating Shout
                    unitList.remove(m_targets.getUnitTarget());
                Trinity::RandomResizeList(unitList, m_spellValue->MaxAffectedTargets);
            }
            else
            {
                switch (m_spellInfo->Id)
                {
                    case 27285: // Seed of Corruption proc spell
                        unitList.remove(m_targets.getUnitTarget());
                        break;
                    case 55789: // Improved Icy Talons
                    case 59725: // Improved Spell Reflection - aoe aura
                        unitList.remove(m_caster);
                        break;
                    case 57699: //Replenishment (special target selection) 10 targets with lowest mana
                    {
                        typedef std::priority_queue<PrioritizeManaUnitWraper, std::vector<PrioritizeManaUnitWraper>, PrioritizeMana> TopMana;
                        TopMana manaUsers;
                        for (std::list<Unit*>::iterator itr = unitList.begin() ; itr != unitList.end();++itr)
                        {
                            if ((*itr)->getPowerType() == POWER_MANA)
                            {
                                PrioritizeManaUnitWraper  WTarget(*itr);
                                manaUsers.push(WTarget);
                            }
                        }

                        unitList.clear();
                        while(!manaUsers.empty() && unitList.size()<10)
                        {
                            unitList.push_back(manaUsers.top().getUnit());
                            manaUsers.pop();
                        }
                        break;
                    }
                    case 52759: // Ancestral Awakening
                    {
                        typedef std::priority_queue<PrioritizeHealthUnitWraper, std::vector<PrioritizeHealthUnitWraper>, PrioritizeHealth> TopHealth;
                        TopHealth healedMembers;
                        for (std::list<Unit*>::iterator itr = unitList.begin() ; itr != unitList.end();++itr)
                        {
                            PrioritizeHealthUnitWraper  WTarget(*itr);
                            healedMembers.push(WTarget);
                        }

                        unitList.clear();
                        while(!healedMembers.empty() && unitList.size()<1)
                        {
                            unitList.push_back(healedMembers.top().getUnit());
                            healedMembers.pop();
                        }
                        break;
                    }
                }
                if (m_spellInfo->EffectImplicitTargetA[i] == TARGET_DEST_TARGET_ANY
                    && m_spellInfo->EffectImplicitTargetB[i] == TARGET_UNIT_AREA_ALLY_DST)// Wild Growth, Circle of Healing, Glyph of holy light target special selection
                {
                    typedef std::priority_queue<PrioritizeHealthUnitWraper, std::vector<PrioritizeHealthUnitWraper>, PrioritizeHealth> TopHealth;
                    TopHealth healedMembers;
                    for (std::list<Unit*>::iterator itr = unitList.begin() ; itr != unitList.end();++itr)
                    {
                        if ((*itr)->IsInRaidWith(m_targets.getUnitTarget()))
                        {
                            PrioritizeHealthUnitWraper  WTarget(*itr);
                            healedMembers.push(WTarget);
                        }
                    }

                    unitList.clear();
                    while(!healedMembers.empty() && unitList.size()<5)
                    {
                        unitList.push_back(healedMembers.top().getUnit());
                        healedMembers.pop();
                    }
                }
                // Death Pact
                if (m_spellInfo->SpellFamilyName == SPELLFAMILY_DEATHKNIGHT && m_spellInfo->SpellFamilyFlags[0] & 0x00080000)
                {
                    Unit * unit_to_add = NULL;
                    for (std::list<Unit*>::iterator itr = unitList.begin() ; itr != unitList.end();++itr)
                    {
                        if ((*itr)->GetTypeId() == TYPEID_UNIT
                            && (*itr)->GetOwnerGUID() == m_caster->GetGUID()
                            && ((Creature*)(*itr))->GetCreatureInfo()->type == CREATURE_TYPE_UNDEAD)
                        {
                            unit_to_add = (*itr);
                            break;
                        }
                    }
                    if (unit_to_add)
                    {
                        unitList.clear();
                        unitList.push_back(unit_to_add);
                    }
                    // Pet not found - remove cooldown
                    else
                    {
                        if (modOwner->GetTypeId()==TYPEID_PLAYER)
                            modOwner->RemoveSpellCooldown(m_spellInfo->Id,true);
                        SendCastResult(SPELL_FAILED_NO_PET);
                        finish(false);
                    }
                }
            }
            for(std::list<Unit*>::iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
                AddUnitTarget(*itr, i);
        }
    }
}

void Spell::prepare(SpellCastTargets const* targets, AuraEffect* triggeredByAura)
{
    if(m_CastItem)
        m_castItemGUID = m_CastItem->GetGUID();
    else
        m_castItemGUID = 0;

    m_targets = *targets;

    if(!m_targets.getUnitTargetGUID() && m_spellInfo->Targets & TARGET_FLAG_UNIT)
    {
        Unit *target = NULL;
        if(m_caster->GetTypeId() == TYPEID_UNIT)
            target = m_caster->getVictim();
        else
            target = ObjectAccessor::GetUnit(*m_caster, ((Player*)m_caster)->GetSelection());

        if(target && IsValidSingleTargetSpell(target))
            m_targets.setUnitTarget(target);
        else
        {
            SendCastResult(SPELL_FAILED_BAD_TARGETS);
            finish(false);
            return;
        }
    }

    // Fill aura scaling information
    if (m_caster->IsControlledByPlayer() && !IsPassiveSpell(m_spellInfo->Id) && m_spellInfo->spellLevel && !IsChanneledSpell(m_spellInfo) && !m_IsTriggeredSpell)
    {
        for (uint8 i = 0; i< MAX_SPELL_EFFECTS; ++i)
        {
            if (m_spellInfo->Effect[i] == SPELL_EFFECT_APPLY_AURA)
            {
                // Change aura with ranks only if basepoints are taken from spellInfo and aura is positive
                if (IsPositiveEffect(m_spellInfo->Id, i))
                {
                    m_auraScaleMask |= (1<<i);
                    if (m_currentBasePoints[i] != m_spellInfo->EffectBasePoints[i])
                    {
                        m_auraScaleMask = 0;
                        break;
                    }
                }
            }
        }
    }

    m_spellState = SPELL_STATE_PREPARING;

    if(triggeredByAura)
        m_triggeredByAuraSpell  = triggeredByAura->GetSpellProto();

    // create and add update event for this spell
    SpellEvent* Event = new SpellEvent(this);
    m_caster->m_Events.AddEvent(Event, m_caster->m_Events.CalculateTime(1));

    //Prevent casting at cast another spell (ServerSide check)
    if(m_caster->IsNonMeleeSpellCasted(false, true, true) && m_cast_count)
    {
        SendCastResult(SPELL_FAILED_SPELL_IN_PROGRESS);
        finish(false);
        return;
    }

    if(m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        if(objmgr.IsPlayerSpellDisabled(m_spellInfo->Id))
        {
            SendCastResult(SPELL_FAILED_SPELL_UNAVAILABLE);
            finish(false);
            return;
        }
    }
    else if (m_caster->GetTypeId() == TYPEID_UNIT && ((Creature*)m_caster)->isPet())
    {
        if(objmgr.IsPetSpellDisabled(m_spellInfo->Id))
        {
            SendCastResult(SPELL_FAILED_SPELL_UNAVAILABLE);
            finish(false);
            return;
        }
    }
    else
    {
        if(objmgr.IsCreatureSpellDisabled(m_spellInfo->Id))
        {
            finish(false);
            return;
        }
    }

    if (m_caster->GetTypeId()==TYPEID_PLAYER)
        ((Player*)m_caster)->SetSpellModTakingSpell(this, true);
    // Fill cost data (not use power for item casts
    m_powerCost = m_CastItem ? 0 : CalculatePowerCost(m_spellInfo, m_caster, m_spellSchoolMask);
    if (m_caster->GetTypeId()==TYPEID_PLAYER)
        ((Player*)m_caster)->SetSpellModTakingSpell(this, false);

    SpellCastResult result = CheckCast(true);
    if(result != SPELL_CAST_OK && !IsAutoRepeat())          //always cast autorepeat dummy for triggering
    {
        if(triggeredByAura)
        {
            SendChannelUpdate(0);
            triggeredByAura->GetParentAura()->SetAuraDuration(0);
        }
        SendCastResult(result);

        finish(false);
        return;
    }

    // Prepare data for triggers
    prepareDataForTriggerSystem(triggeredByAura);

    // Set combo point requirement
    if (m_IsTriggeredSpell || m_CastItem || m_caster->GetTypeId()!=TYPEID_PLAYER)
        m_needComboPoints = false;

    // calculate cast time (calculated after first CheckCast check to prevent charge counting for first CheckCast fail)
    m_casttime = GetSpellCastTime(m_spellInfo, this);
    //m_caster->ModSpellCastTime(m_spellInfo, m_casttime, this);

    // set timer base at cast time
    ReSetTimer();

    sLog.outDebug("Spell::prepare: spell id %u source %u caster %d target %d triggered %u", m_spellInfo->Id, m_caster->GetEntry(), m_originalCaster ? m_originalCaster->GetEntry() : -1, m_targets.getUnitTarget() ? m_targets.getUnitTarget()->GetEntry() : -1, m_IsTriggeredSpell ? 1 : 0);

    //Containers for channeled spells have to be set
    //TODO:Apply this to all casted spells if needed
    // Why check duration? 29350: channelled triggers channelled
    if(m_IsTriggeredSpell && (!IsChanneledSpell(m_spellInfo) || !GetSpellMaxDuration(m_spellInfo)))
        cast(true);
    else
    {
        // stealth must be removed at cast starting (at show channel bar)
        // skip triggered spell (item equip spell casting and other not explicit character casts/item uses)
        if(!m_IsTriggeredSpell && isSpellBreakStealth(m_spellInfo) )
        {
            m_caster->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_CAST);
            for(uint32 i = 0; i < 3; ++i)
            {
                if(spellmgr.EffectTargetType[m_spellInfo->Effect[i]] == SPELL_REQUIRE_UNIT)
                {
                    m_caster->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_SPELL_ATTACK);
                    break;
                }
            }
        }

        m_caster->SetCurrentCastedSpell( this );
        m_selfContainer = &(m_caster->m_currentSpells[GetCurrentContainer()]);
        SendSpellStart();

        if(!m_casttime && !m_spellInfo->StartRecoveryTime
            && !m_castItemGUID     //item: first cast may destroy item and second cast causes crash
            && GetCurrentContainer() == CURRENT_GENERIC_SPELL)
            cast(true);
    }
}

void Spell::cancel()
{
    if(m_spellState == SPELL_STATE_FINISHED)
        return;

    SetReferencedFromCurrent(false);
    if(m_selfContainer && *m_selfContainer == this)
        *m_selfContainer = NULL;

    uint32 oldState = m_spellState;
    m_spellState = SPELL_STATE_FINISHED;

    m_autoRepeat = false;
    switch (oldState)
    {
        case SPELL_STATE_PREPARING:
        case SPELL_STATE_DELAYED:
        {
            SendInterrupted(0);
            SendCastResult(SPELL_FAILED_INTERRUPTED);
        } break;

        case SPELL_STATE_CASTING:
        {
            for(std::list<TargetInfo>::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
                if(ihit->missCondition == SPELL_MISS_NONE)
                    if(Unit* unit = m_caster->GetGUID() == ihit->targetGUID ? m_caster : ObjectAccessor::GetUnit(*m_caster, ihit->targetGUID))
                        if(unit->isAlive())
                            unit->RemoveAurasDueToSpell(m_spellInfo->Id, m_originalCasterGUID, AURA_REMOVE_BY_CANCEL);

            SendChannelUpdate(0);
            SendInterrupted(0);
            SendCastResult(SPELL_FAILED_INTERRUPTED);

            // spell is canceled-take mods and clear list
            if (m_caster->GetTypeId() == TYPEID_PLAYER)
                ((Player*)m_caster)->RemoveSpellMods(this);

            m_appliedMods.clear();
        } break;

        default:
        {
        } break;
    }

    m_caster->RemoveDynObject(m_spellInfo->Id);
    m_caster->RemoveGameObject(m_spellInfo->Id,true);

    //set state back so finish will be processed
    m_spellState = oldState;

    finish(false);
}

void Spell::cast(bool skipCheck)
{
    // update pointers base at GUIDs to prevent access to non-existed already object
    UpdatePointers();

    if(Unit *target = m_targets.getUnitTarget())
    {
        // three check: prepare, cast (m_casttime > 0), hit (delayed)
        if(m_casttime && target->isAlive() 
            && (target->m_invisibilityMask || m_caster->m_invisibilityMask
            || target->GetVisibility() == VISIBILITY_GROUP_STEALTH)
            && !target->IsFriendlyTo(m_caster) && !m_caster->canSeeOrDetect(target, true))
        {
            SendCastResult(SPELL_FAILED_BAD_TARGETS);
            SendInterrupted(0);
            finish(false);
            return;
        }
    }
    else
    {
        // cancel at lost main target unit
        if(m_targets.getUnitTargetGUID() && m_targets.getUnitTargetGUID() != m_caster->GetGUID())
        {
            cancel();
            return;
        }
    }

    SetExecutedCurrently(true);

    if(m_caster->GetTypeId() != TYPEID_PLAYER && m_targets.getUnitTarget() && m_targets.getUnitTarget() != m_caster)
        m_caster->SetInFront(m_targets.getUnitTarget());

    // Should this be done for original caster?
    if (m_caster->GetTypeId()==TYPEID_PLAYER)
    {
        // Set spell which will drop charges for triggered cast spells
        ((Player*)m_caster)->SetSpellModTakingSpell(this, true);
    }

    // triggered cast called from Spell::prepare where it was already checked
    if(!m_IsTriggeredSpell || !skipCheck)
    {
        SpellCastResult castResult = CheckCast(false);
        if(castResult != SPELL_CAST_OK)
        {
            SendCastResult(castResult);
            SendInterrupted(0);
            finish(false);
            SetExecutedCurrently(false);
            return;
        }
    }

    FillTargetMap();

    // Spell may be finished after target map check
    if(m_spellState == SPELL_STATE_FINISHED)
    {
        SendInterrupted(0);
        SetExecutedCurrently(false);
        return;
    }

    if(m_spellInfo->SpellFamilyName)
    {
        if (m_spellInfo->excludeCasterAuraSpell && !IsPositiveSpell(m_spellInfo->excludeCasterAuraSpell))
            m_preCastSpell = m_spellInfo->excludeCasterAuraSpell;
        else if (m_spellInfo->excludeTargetAuraSpell && !IsPositiveSpell(m_spellInfo->excludeTargetAuraSpell))
            m_preCastSpell = m_spellInfo->excludeTargetAuraSpell;
    }
    switch (m_spellInfo->SpellFamilyName)
    {
        case SPELLFAMILY_GENERIC:
        {
            if (m_spellInfo->Mechanic == MECHANIC_BANDAGE) // Bandages
                m_preCastSpell = 11196;                                // Recently Bandaged
            break;
        }
        case SPELLFAMILY_DRUID:
        {
            // Faerie Fire (Feral)
            if (m_spellInfo->SpellFamilyFlags[0] & 0x00000400)
            {
                // Trigger only if has correct shapeshift for triggered spell
                SpellEntry const * spellInfo = sSpellStore.LookupEntry(60089);
                if (GetErrorAtShapeshiftedCast(spellInfo, m_caster->m_form) == SPELL_CAST_OK)
                    m_preCastSpell = 60089;
            }
            break;
        }
    }
    // traded items have trade slot instead of guid in m_itemTargetGUID
    // set to real guid to be sent later to the client
    m_targets.updateTradeSlotItem();

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        if (!m_IsTriggeredSpell && m_CastItem)
            ((Player*)m_caster)->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_USE_ITEM, m_CastItem->GetEntry());

        ((Player*)m_caster)->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_CAST_SPELL, m_spellInfo->Id);
    }

    if(!m_IsTriggeredSpell)
    {
        // Powers have to be taken before SendSpellGo
        TakePower();
        TakeReagents();                                         // we must remove reagents before HandleEffects to allow place crafted item in same slot
    }

    // are there any spells need to be triggered after hit?
    // handle SPELL_AURA_ADD_TARGET_TRIGGER auras
    Unit::AuraEffectList const& targetTriggers = m_caster->GetAurasByType(SPELL_AURA_ADD_TARGET_TRIGGER);
    for(Unit::AuraEffectList::const_iterator i = targetTriggers.begin(); i != targetTriggers.end(); ++i)
    {
        if (!(*i)->isAffectedOnSpell(m_spellInfo))
            continue;
        SpellEntry const *auraSpellInfo = (*i)->GetSpellProto();
        uint32 auraSpellIdx = (*i)->GetEffIndex();
        if(SpellEntry const *spellInfo = sSpellStore.LookupEntry(auraSpellInfo->EffectTriggerSpell[auraSpellIdx]))
        {
            // Calculate chance at that moment (can be depend for example from combo points)
            int32 chance = m_caster->CalculateSpellDamage(auraSpellInfo, auraSpellIdx, (*i)->GetBasePoints(), NULL);
            m_ChanceTriggerSpells.push_back(std::make_pair(spellInfo, chance * (*i)->GetParentAura()->GetStackAmount()));
        }
    }

    if(m_customAttr & SPELL_ATTR_CU_DIRECT_DAMAGE)
        CalculateDamageDoneForAllTargets();

    // CAST SPELL
    SendSpellCooldown();
    //SendCastResult(castResult);
    SendSpellGo();                                          // we must send smsg_spell_go packet before m_castItem delete in TakeCastItem()...

    if(m_customAttr & SPELL_ATTR_CU_CHARGE)
    {
        for(uint32 i = 0; i < 3; ++i)
        {
            switch(m_spellInfo->Effect[i])
            {
                case SPELL_EFFECT_CHARGE:
                case SPELL_EFFECT_JUMP:
                case SPELL_EFFECT_JUMP2:
                case SPELL_EFFECT_138:
                    HandleEffects(NULL,NULL,NULL,i);
                    m_effectMask |= (1<<i);
                    break;
            }
        }
    }

    // Okay, everything is prepared. Now we need to distinguish between immediate and evented delayed spells
    if (m_spellInfo->speed > 0.0f && !IsChanneledSpell(m_spellInfo))
    {
        // Remove used for cast item if need (it can be already NULL after TakeReagents call
        // in case delayed spell remove item at cast delay start
        TakeCastItem();

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

    if(m_customAttr & SPELL_ATTR_CU_LINK_CAST)
    {
        if(const std::vector<int32> *spell_triggered = spellmgr.GetSpellLinked(m_spellInfo->Id))
            for(std::vector<int32>::const_iterator i = spell_triggered->begin(); i != spell_triggered->end(); ++i)
                if(*i < 0)
                    m_caster->RemoveAurasDueToSpell(-(*i));
                else
                    m_caster->CastSpell(m_targets.getUnitTarget() ? m_targets.getUnitTarget() : m_caster, *i, true);
    }

    if (m_caster->GetTypeId()==TYPEID_PLAYER)
        ((Player*)m_caster)->SetSpellModTakingSpell(this, false);

    SetExecutedCurrently(false);
}

void Spell::handle_immediate()
{
    // start channeling if applicable
    if(IsChanneledSpell(m_spellInfo))
    {
        int32 duration = GetSpellDuration(m_spellInfo);
        if (duration)
        {
            //apply haste mods
            m_caster->ModSpellCastTime(m_spellInfo, duration, this);
            // Apply duration mod
            if(Player* modOwner = m_caster->GetSpellModOwner())
                modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_DURATION, duration);
            m_spellState = SPELL_STATE_CASTING;
            m_caster->AddInterruptMask(m_spellInfo->ChannelInterruptFlags);
            SendChannelStart(duration);
        }
    }

    // process immediate effects (items, ground, etc.) also initialize some variables
    _handle_immediate_phase();

    for(std::list<TargetInfo>::iterator ihit= m_UniqueTargetInfo.begin();ihit != m_UniqueTargetInfo.end();++ihit)
        DoAllEffectOnTarget(&(*ihit));

    for(std::list<GOTargetInfo>::iterator ihit= m_UniqueGOTargetInfo.begin();ihit != m_UniqueGOTargetInfo.end();++ihit)
        DoAllEffectOnTarget(&(*ihit));

    // spell is finished, perform some last features of the spell here
    _handle_finish_phase();

    // Remove used for cast item if need (it can be already NULL after TakeReagents call
    TakeCastItem();

    if(m_spellState != SPELL_STATE_CASTING)
        finish(true);                                       // successfully finish spell cast (not last in case autorepeat or channel spell)
}

uint64 Spell::handle_delayed(uint64 t_offset)
{
    UpdatePointers();

    if (m_caster->GetTypeId()==TYPEID_PLAYER)
        ((Player*)m_caster)->SetSpellModTakingSpell(this, true);

    uint64 next_time = 0;

    if (!m_immediateHandled)
    {
        _handle_immediate_phase();
        m_immediateHandled = true;
    }

    bool single_missile = (m_targets.m_targetMask & TARGET_FLAG_DEST_LOCATION);

    // now recheck units targeting correctness (need before any effects apply to prevent adding immunity at first effect not allow apply second spell effect and similar cases)
    for(std::list<TargetInfo>::iterator ihit= m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end();++ihit)
    {
        if (ihit->processed == false)
        {
            if ( single_missile || ihit->timeDelay <= t_offset )
                DoAllEffectOnTarget(&(*ihit));
            else if( next_time == 0 || ihit->timeDelay < next_time )
                next_time = ihit->timeDelay;
        }
    }

    // now recheck gameobject targeting correctness
    for(std::list<GOTargetInfo>::iterator ighit= m_UniqueGOTargetInfo.begin(); ighit != m_UniqueGOTargetInfo.end();++ighit)
    {
        if (ighit->processed == false)
        {
            if ( single_missile || ighit->timeDelay <= t_offset )
                DoAllEffectOnTarget(&(*ighit));
            else if( next_time == 0 || ighit->timeDelay < next_time )
                next_time = ighit->timeDelay;
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
        if (m_caster->GetTypeId()==TYPEID_PLAYER)
            ((Player*)m_caster)->SetSpellModTakingSpell(this, false);

        // spell is unfinished, return next execution time
        return next_time;
    }
}

void Spell::_handle_immediate_phase()
{
    // handle some immediate features of the spell here
    HandleThreatSpells(m_spellInfo->Id);

    m_needSpellLog = IsNeedSendToClient();
    for(uint32 j = 0; j < 3; ++j)
    {
        if(m_spellInfo->Effect[j] == 0)
            continue;

        // apply Send Event effect to ground in case empty target lists
        if( m_spellInfo->Effect[j] == SPELL_EFFECT_SEND_EVENT && !HaveTargetsForEffect(j) )
        {
            HandleEffects(NULL, NULL, NULL, j);
            continue;
        }

        // Don't do spell log, if is school damage spell
        if(m_spellInfo->Effect[j] == SPELL_EFFECT_SCHOOL_DAMAGE || m_spellInfo->Effect[j] == 0)
            m_needSpellLog = false;
    }

    // initialize Diminishing Returns Data
    m_diminishLevel = DIMINISHING_LEVEL_1;
    m_diminishGroup = DIMINISHING_NONE;

    // process items
    for(std::list<ItemTargetInfo>::iterator ihit= m_UniqueItemInfo.begin();ihit != m_UniqueItemInfo.end();++ihit)
        DoAllEffectOnTarget(&(*ihit));

    if(!m_originalCaster)
        return;
    uint8 oldEffMask = m_effectMask;
    // process ground
    for(uint32 j = 0; j < 3; ++j)
    {
        if(spellmgr.EffectTargetType[m_spellInfo->Effect[j]] == SPELL_REQUIRE_DEST)
        {
            if(!m_targets.HasDst()) // FIXME: this will ignore dest set in effect
                m_targets.setDestination(m_caster);
            HandleEffects(m_originalCaster, NULL, NULL, j);
            m_effectMask |= (1<<j);
        }
        else if(spellmgr.EffectTargetType[m_spellInfo->Effect[j]] == SPELL_REQUIRE_NONE)
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
                if (m_effectMask & (1<<i) && !IsPositiveEffect(m_spellInfo->Id, i))
                {
                    positive = false;
                    break;
                }
            switch(m_spellInfo->DmgClass)
            {
                case SPELL_DAMAGE_CLASS_MAGIC:
                    if (positive)
                        procAttacker |= PROC_FLAG_SUCCESSFUL_POSITIVE_MAGIC_SPELL;
                    else
                        procAttacker |= PROC_FLAG_SUCCESSFUL_NEGATIVE_MAGIC_SPELL;
                break;
                case SPELL_DAMAGE_CLASS_NONE:
                    if (positive)
                        procAttacker |= PROC_FLAG_SUCCESSFUL_POSITIVE_SPELL_HIT;
                    else
                        procAttacker |= PROC_FLAG_SUCCESSFUL_NEGATIVE_SPELL_HIT;
                break;
            }
        }
        // Proc damage for spells which have only dest targets (2484 should proc 51486 for example)
        m_originalCaster->ProcDamageAndSpell(0, procAttacker, 0, m_procEx | PROC_EX_NORMAL_HIT, 0, BASE_ATTACK, m_spellInfo, m_triggeredByAuraSpell);
    }
}

void Spell::_handle_finish_phase()
{
    // Take for real after all targets are processed
    if (m_needComboPoints)
        ((Player*)m_caster)->ClearComboPoints();

    // Real add combo points from effects
    if (m_caster->GetTypeId()==TYPEID_PLAYER)
        ((Player*)m_caster)->GainSpellComboPoints(m_comboPointGain);

    // spell log
    if(m_needSpellLog)
        SendLogExecute();
}

void Spell::SendSpellCooldown()
{
    if(m_caster->GetTypeId() != TYPEID_PLAYER)
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
    if(m_spellInfo->Attributes & SPELL_ATTR_DISABLED_WHILE_ACTIVE || m_IsTriggeredSpell)
        return;

    _player->AddSpellAndCategoryCooldowns(m_spellInfo,m_CastItem ? m_CastItem->GetEntry() : 0, this);
}

void Spell::update(uint32 difftime)
{
    // update pointers based at it's GUIDs
    UpdatePointers();

    if(m_targets.getUnitTargetGUID() && !m_targets.getUnitTarget())
    {
        sLog.outDebug("Spell %u is cancelled due to removal of target.", m_spellInfo->Id);
        cancel();
        return;
    }

    // check if the player caster has moved before the spell finished
    if ((m_caster->GetTypeId() == TYPEID_PLAYER && m_timer != 0) &&
        m_caster->isMoving() && (m_spellInfo->InterruptFlags & SPELL_INTERRUPT_FLAG_MOVEMENT) &&
        (m_spellInfo->Effect[0] != SPELL_EFFECT_STUCK || !m_caster->HasUnitMovementFlag(MOVEMENTFLAG_FALLING)))
    {
        // don't cancel for melee, autorepeat, triggered and instant spells
        if(!IsNextMeleeSwingSpell() && !IsAutoRepeat() && !m_IsTriggeredSpell)
            cancel();
    }

    switch(m_spellState)
    {
        case SPELL_STATE_PREPARING:
        {
            if(m_timer)
            {
                if(difftime >= m_timer)
                    m_timer = 0;
                else
                    m_timer -= difftime;
            }

            if(m_timer == 0 && !IsNextMeleeSwingSpell() && !IsAutoRepeat())
                cast(m_spellInfo->CastingTimeIndex == 1);
        } break;
        case SPELL_STATE_CASTING:
        {
            if(m_timer > 0)
            {
                // check if there are alive targets left
                if (!UpdateChanneledTargetList())
                {
                    sLog.outDebug("Channeled spell %d is removed due to lack of targets", m_spellInfo->Id);
                    SendChannelUpdate(0);
                    finish();
                }

                if(difftime >= m_timer)
                    m_timer = 0;
                else
                    m_timer -= difftime;
            }

            if(m_timer == 0)
            {
                SendChannelUpdate(0);

                // channeled spell processed independently for quest targeting
                // cast at creature (or GO) quest objectives update at successful cast channel finished
                // ignore autorepeat/melee casts for speed (not exist quest for spells (hm... )
                if( !IsAutoRepeat() && !IsNextMeleeSwingSpell() )
                {
                    if ( Player* p = m_caster->GetCharmerOrOwnerPlayerOrPlayerItself() )
                    {
                        for(std::list<TargetInfo>::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
                        {
                            TargetInfo* target = &*ihit;
                            if(!IS_CREATURE_GUID(target->targetGUID))
                                continue;

                            Unit* unit = m_caster->GetGUID() == target->targetGUID ? m_caster : ObjectAccessor::GetUnit(*m_caster, target->targetGUID);
                            if (unit == NULL)
                                continue;

                            p->CastedCreatureOrGO(unit->GetEntry(), unit->GetGUID(), m_spellInfo->Id);
                        }

                        for(std::list<GOTargetInfo>::iterator ihit = m_UniqueGOTargetInfo.begin(); ihit != m_UniqueGOTargetInfo.end(); ++ihit)
                        {
                            GOTargetInfo* target = &*ihit;

                            GameObject* go = m_caster->GetMap()->GetGameObject(target->targetGUID);
                            if(!go)
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
    if(!m_caster)
        return;

    if(m_spellState == SPELL_STATE_FINISHED)
        return;
    m_spellState = SPELL_STATE_FINISHED;

    if(IsChanneledSpell(m_spellInfo))
        m_caster->UpdateInterruptMask();

    if(!m_caster->IsNonMeleeSpellCasted(false, false, true))
        m_caster->clearUnitState(UNIT_STAT_CASTING);

    // Unsummon summon as possessed creatures on spell cancel
    if(IsChanneledSpell(m_spellInfo) && m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        if(Unit *charm = m_caster->GetCharm())
            if(charm->GetTypeId() == TYPEID_UNIT
                && ((Creature*)charm)->HasSummonMask(SUMMON_MASK_PUPPET)
                && charm->GetUInt32Value(UNIT_CREATED_BY_SPELL) == m_spellInfo->Id)
                ((Puppet*)charm)->UnSummon();
    }

    if(!ok)
    {
        //restore spell mods
        if (m_caster->GetTypeId() == TYPEID_PLAYER)
        {
            ((Player*)m_caster)->RestoreSpellMods(this);
            // cleanup after mod system
            // triggered spell pointer can be not removed in some cases
            ((Player*)m_caster)->SetSpellModTakingSpell(this, false);
        }
        return;
    }

    if (m_caster->GetTypeId()==TYPEID_UNIT && ((Creature*)m_caster)->isSummon())
    {
        // Unsummon statue
        uint32 spell = m_caster->GetUInt32Value(UNIT_CREATED_BY_SPELL);
        SpellEntry const *spellInfo = sSpellStore.LookupEntry(spell );
        if (spellInfo && spellInfo->SpellIconID==2056)
        {
            sLog.outDebug("Statue %d is unsummoned in spell %d finish", m_caster->GetGUIDLow(), m_spellInfo->Id);
            m_caster->setDeathState(JUST_DIED);
            return;
        }
    }

    // Okay to remove extra attacks
    if(IsSpellHaveEffect(m_spellInfo, SPELL_EFFECT_ADD_EXTRA_ATTACKS))
        m_caster->m_extraAttacks = 0;

    // Heal caster for all health leech from all targets
    if (m_healthLeech)
        m_caster->DealHeal(m_caster, uint32(m_healthLeech), m_spellInfo);

    if (IsMeleeAttackResetSpell())
    {
        m_caster->resetAttackTimer(BASE_ATTACK);
        if(m_caster->haveOffhandWeapon())
            m_caster->resetAttackTimer(OFF_ATTACK);
        if(!(m_spellInfo->AttributesEx2 & SPELL_ATTR_EX2_NOT_RESET_AUTOSHOT))
            m_caster->resetAttackTimer(RANGED_ATTACK);
    }

    // potions disabled by client, send event "not in combat" if need
    if (m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        if (!m_triggeredByAuraSpell)
            ((Player*)m_caster)->UpdatePotionCooldown(this);

        // triggered spell pointer can be not set in some cases
        // this is needed for proper apply of triggered spell mods
        ((Player*)m_caster)->SetSpellModTakingSpell(this, true);
    }

    // call triggered spell only at successful cast (after clear combo points -> for add some if need)
    // I assume what he means is that some triggered spells may add combo points
    if(!m_TriggerSpells.empty())
        TriggerSpell();

    // Take mods after trigger spell (needed for 14177 to affect 48664)
    // mods are taken only on succesfull cast and independantly from targets of the spell
    if (m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        ((Player*)m_caster)->RemoveSpellMods(this);
        ((Player*)m_caster)->SetSpellModTakingSpell(this, false);
    }

    // Stop Attack for some spells
    if( m_spellInfo->Attributes & SPELL_ATTR_STOP_ATTACK_TARGET )
        m_caster->AttackStop();
}

void Spell::SendCastResult(SpellCastResult result)
{
    if(result == SPELL_CAST_OK)
        return;

    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    if(((Player*)m_caster)->GetSession()->PlayerLoading())  // don't send cast results at loading time
        return;

    SendCastResult((Player*)m_caster,m_spellInfo,m_cast_count,result);
}

void Spell::SendCastResult(Player* caster, SpellEntry const* spellInfo, uint8 cast_count, SpellCastResult result)
{
    if(result == SPELL_CAST_OK)
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
            switch(spellInfo->Id)
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
            if(spellInfo->Totem[0])
                data << uint32(spellInfo->Totem[0]);
            if(spellInfo->Totem[1])
                data << uint32(spellInfo->Totem[1]);
            break;
        case SPELL_FAILED_TOTEM_CATEGORY:
            if(spellInfo->TotemCategory[0])
                data << uint32(spellInfo->TotemCategory[0]);
            if(spellInfo->TotemCategory[1])
                data << uint32(spellInfo->TotemCategory[1]);
            break;
        case SPELL_FAILED_EQUIPPED_ITEM_CLASS:
            data << uint32(spellInfo->EquippedItemClass);
            data << uint32(spellInfo->EquippedItemSubClassMask);
            //data << uint32(spellInfo->EquippedItemInventoryTypeMask);
            break;
        default:
            break;
    }
    caster->GetSession()->SendPacket(&data);
}

void Spell::SendSpellStart()
{
    if(!IsNeedSendToClient())
        return;

    //sLog.outDebug("Sending SMSG_SPELL_START id=%u", m_spellInfo->Id);

    uint32 castFlags = CAST_FLAG_UNKNOWN1;
    if(m_spellInfo->Attributes & SPELL_ATTR_REQ_AMMO)
        castFlags |= CAST_FLAG_AMMO;
    if ((m_caster->GetTypeId() == TYPEID_PLAYER ||
        (m_caster->GetTypeId() == TYPEID_UNIT && ((Creature*)m_caster)->isPet()))
         && m_spellInfo->powerType != POWER_HEALTH )
        castFlags |= CAST_FLAG_POWER_LEFT_SELF;

    if(m_spellInfo->runeCostID)
        castFlags |= CAST_FLAG_UNKNOWN10;

    WorldPacket data(SMSG_SPELL_START, (8+8+4+4+2));
    if(m_CastItem)
        data.append(m_CastItem->GetPackGUID());
    else
        data.append(m_caster->GetPackGUID());

    data.append(m_caster->GetPackGUID());
    data << uint8(m_cast_count);                            // pending spell cast?
    data << uint32(m_spellInfo->Id);                        // spellId
    data << uint32(castFlags);                              // cast flags
    data << uint32(m_timer);                                // delay?

    m_targets.write(&data);

    if(castFlags & CAST_FLAG_POWER_LEFT_SELF)
        data << uint32(m_caster->GetPower((Powers)m_spellInfo->powerType));

    if ( castFlags & CAST_FLAG_AMMO )
        WriteAmmoToPacket(&data);

    m_caster->SendMessageToSet(&data, true);
}

void Spell::SendSpellGo()
{
    // not send invisible spell casting
    if(!IsNeedSendToClient())
        return;

    //sLog.outDebug("Sending SMSG_SPELL_GO id=%u", m_spellInfo->Id);

    uint32 castFlags = CAST_FLAG_UNKNOWN3;

    // triggered spells with spell visual != 0
    if((m_IsTriggeredSpell && !IsAutoRepeatRangedSpell(m_spellInfo)) || m_triggeredByAuraSpell)
        castFlags |= CAST_FLAG_UNKNOWN0; 

    if(m_spellInfo->Attributes & SPELL_ATTR_REQ_AMMO)
        castFlags |= CAST_FLAG_AMMO;                        // arrows/bullets visual
    if ((m_caster->GetTypeId() == TYPEID_PLAYER ||
        (m_caster->GetTypeId() == TYPEID_UNIT && ((Creature*)m_caster)->isPet()))
        && m_spellInfo->powerType != POWER_HEALTH )
        castFlags |= CAST_FLAG_POWER_LEFT_SELF; // should only be sent to self, but the current messaging doesn't make that possible

    if((m_caster->GetTypeId() == TYPEID_PLAYER) && (m_caster->getClass() == CLASS_DEATH_KNIGHT) && m_spellInfo->runeCostID)
    {
        castFlags |= CAST_FLAG_UNKNOWN10;                   // same as in SMSG_SPELL_START
        castFlags |= CAST_FLAG_UNKNOWN7;                    // rune cooldowns list
    }

    WorldPacket data(SMSG_SPELL_GO, 50);                    // guess size

    if(m_CastItem)
        data.append(m_CastItem->GetPackGUID());
    else
        data.append(m_caster->GetPackGUID());

    data.append(m_caster->GetPackGUID());
    data << uint8(m_cast_count);                            // pending spell cast?
    data << uint32(m_spellInfo->Id);                        // spellId
    data << uint32(castFlags);                              // cast flags
    data << uint32(getMSTime());                            // timestamp

    WriteSpellGoTargets(&data);

    m_targets.write(&data);

    if(castFlags & CAST_FLAG_POWER_LEFT_SELF)
        data << uint32(m_caster->GetPower((Powers)m_spellInfo->powerType));

    if ( castFlags & CAST_FLAG_UNKNOWN7 )                   // rune cooldowns list
    {
        uint8 v1 = m_runesState;
        uint8 v2 = ((Player*)m_caster)->GetRunesState();
        data << uint8(v1);                                  // runes state before
        data << uint8(v2);                                  // runes state after
        for(uint8 i = 0; i < MAX_RUNES; ++i)
        {
            uint8 m = (1 << i);
            if(m & v1)                                      // usable before...
                if(!(m & v2))                               // ...but on cooldown now...
                    data << uint8(0);                       // some unknown byte (time?)
        }
    }

    if ( castFlags & CAST_FLAG_UNKNOWN4 )                   // unknown wotlk
    {
        data << float(0);
        data << uint32(0);
    }

    if ( castFlags & CAST_FLAG_AMMO )
        WriteAmmoToPacket(&data);

    if ( castFlags & CAST_FLAG_UNKNOWN5 )                   // unknown wotlk
    {
        data << uint32(0);
        data << uint32(0);
    }

    if ( m_targets.m_targetMask & TARGET_FLAG_DEST_LOCATION )
    {
        data << uint8(0);
    }

    m_caster->SendMessageToSet(&data, true);
}

void Spell::WriteAmmoToPacket( WorldPacket * data )
{
    uint32 ammoInventoryType = 0;
    uint32 ammoDisplayID = 0;

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        Item *pItem = ((Player*)m_caster)->GetWeaponForAttack( RANGED_ATTACK );
        if(pItem)
        {
            ammoInventoryType = pItem->GetProto()->InventoryType;
            if( ammoInventoryType == INVTYPE_THROWN )
                ammoDisplayID = pItem->GetProto()->DisplayInfoID;
            else
            {
                uint32 ammoID = ((Player*)m_caster)->GetUInt32Value(PLAYER_AMMO_ID);
                if(ammoID)
                {
                    ItemPrototype const *pProto = objmgr.GetItemPrototype( ammoID );
                    if(pProto)
                    {
                        ammoDisplayID = pProto->DisplayInfoID;
                        ammoInventoryType = pProto->InventoryType;
                    }
                }
                else if(m_caster->GetDummyAura(46699))      // Requires No Ammo
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
            if(uint32 item_id = m_caster->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + i))
            {
                if(ItemEntry const * itemEntry = sItemStore.LookupEntry(item_id))
                {
                    if(itemEntry->Class==ITEM_CLASS_WEAPON)
                    {
                        switch(itemEntry->SubClass)
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

                        if(ammoDisplayID)
                            break;
                    }
                }
            }
        }
    }

    *data << uint32(ammoDisplayID);
    *data << uint32(ammoInventoryType);
}

void Spell::WriteSpellGoTargets( WorldPacket * data )
{
    // This function also fill data for channeled spells:
    // m_needAliveTargetMask req for stop channelig if one target die
    uint32 hit  = m_UniqueGOTargetInfo.size(); // Always hits on GO
    uint32 miss = 0;
    for(std::list<TargetInfo>::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
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
    for(std::list<TargetInfo>::const_iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
    {
        if ((*ihit).missCondition == SPELL_MISS_NONE)       // Add only hits
        {
            *data << uint64(ihit->targetGUID);
            m_needAliveTargetMask |=ihit->effectMask;
        }
    }

    for(std::list<GOTargetInfo>::const_iterator ighit = m_UniqueGOTargetInfo.begin(); ighit != m_UniqueGOTargetInfo.end(); ++ighit)
        *data << uint64(ighit->targetGUID);                 // Always hits

    *data << (uint8)miss;
    for(std::list<TargetInfo>::const_iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
    {
        if( ihit->missCondition != SPELL_MISS_NONE )        // Add only miss
        {
            *data << uint64(ihit->targetGUID);
            *data << uint8(ihit->missCondition);
            if( ihit->missCondition == SPELL_MISS_REFLECT )
                *data << uint8(ihit->reflectResult);
        }
    }
    // Reset m_needAliveTargetMask for non channeled spell
    if(!IsChanneledSpell(m_spellInfo))
        m_needAliveTargetMask = 0;
}

void Spell::SendLogExecute()
{
    Unit *target = m_targets.getUnitTarget() ? m_targets.getUnitTarget() : m_caster;

    WorldPacket data(SMSG_SPELLLOGEXECUTE, (8+4+4+4+4+8));

    if(m_caster->GetTypeId() == TYPEID_PLAYER)
        data.append(m_caster->GetPackGUID());
    else
        data.append(target->GetPackGUID());

    data << uint32(m_spellInfo->Id);
    uint32 count1 = 1;
    data << uint32(count1);                                 // count1 (effect count?)
    for(uint32 i = 0; i < count1; ++i)
    {
        data << uint32(m_spellInfo->Effect[0]);             // spell effect
        uint32 count2 = 1;
        data << uint32(count2);                             // count2 (target count?)
        for(uint32 j = 0; j < count2; ++j)
        {
            switch(m_spellInfo->Effect[0])
            {
                case SPELL_EFFECT_POWER_DRAIN:
                    if(Unit *unit = m_targets.getUnitTarget())
                        data.append(unit->GetPackGUID());
                    else
                        data << uint8(0);
                    data << uint32(0);
                    data << uint32(0);
                    data << float(0);
                    break;
                case SPELL_EFFECT_ADD_EXTRA_ATTACKS:
                    if(Unit *unit = m_targets.getUnitTarget())
                        data.append(unit->GetPackGUID());
                    else
                        data << uint8(0);
                    data << uint32(m_caster->m_extraAttacks); 
                    break;
                case SPELL_EFFECT_INTERRUPT_CAST:
                    if(Unit *unit = m_targets.getUnitTarget())
                        data.append(unit->GetPackGUID());
                    else
                        data << uint8(0);
                    data << uint32(0);                      // spellid
                    break;
                case SPELL_EFFECT_DURABILITY_DAMAGE:
                    if(Unit *unit = m_targets.getUnitTarget())
                        data.append(unit->GetPackGUID());
                    else
                        data << uint8(0);
                    data << uint32(0);
                    data << uint32(0);
                    break;
                case SPELL_EFFECT_OPEN_LOCK:
                    if(Item *item = m_targets.getItemTarget())
                        data.append(item->GetPackGUID());
                    else
                        data << uint8(0);
                    break;
                case SPELL_EFFECT_CREATE_ITEM:
                case SPELL_EFFECT_CREATE_ITEM_2:
                    data << uint32(m_spellInfo->EffectItemType[0]);
                    break;
                case SPELL_EFFECT_SUMMON:
                case SPELL_EFFECT_TRANS_DOOR:
                case SPELL_EFFECT_SUMMON_PET:
                case SPELL_EFFECT_SUMMON_OBJECT_WILD:
                case SPELL_EFFECT_CREATE_HOUSE:
                case SPELL_EFFECT_DUEL:
                case SPELL_EFFECT_SUMMON_OBJECT_SLOT1:
                case SPELL_EFFECT_SUMMON_OBJECT_SLOT2:
                case SPELL_EFFECT_SUMMON_OBJECT_SLOT3:
                case SPELL_EFFECT_SUMMON_OBJECT_SLOT4:
                    if(Unit *unit = m_targets.getUnitTarget())
                        data.append(unit->GetPackGUID());
                    else if(m_targets.getItemTargetGUID())
                        data.appendPackGUID(m_targets.getItemTargetGUID());
                    else if(GameObject *go = m_targets.getGOTarget())
                        data.append(go->GetPackGUID());
                    else
                        data << uint8(0);                   // guid
                    break;
                case SPELL_EFFECT_FEED_PET:
                    data << uint32(m_targets.getItemTargetEntry());
                    break;
                case SPELL_EFFECT_DISMISS_PET:
                    if(Unit *unit = m_targets.getUnitTarget())
                        data.append(unit->GetPackGUID());
                    else
                        data << uint8(0);
                    break;
                case SPELL_EFFECT_RESURRECT:
                case SPELL_EFFECT_RESURRECT_NEW:
                    if(Unit *unit = m_targets.getUnitTarget())
                        data.append(unit->GetPackGUID());
                    else
                        data << uint8(0);
                    break;
                default:
                    return;
            }
        }
    }

    m_caster->SendMessageToSet(&data, true);
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
    if(time == 0)
    {
        m_caster->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
        m_caster->SetUInt32Value(UNIT_CHANNEL_SPELL, 0);
    }

    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    WorldPacket data( MSG_CHANNEL_UPDATE, 8+4 );
    data.append(m_caster->GetPackGUID());
    data << uint32(time);

    ((Player*)m_caster)->GetSession()->SendPacket( &data );
}

void Spell::SendChannelStart(uint32 duration)
{
    WorldObject* target = NULL;

    // select first not resisted target from target list for _0_ effect
    if(!m_UniqueTargetInfo.empty())
    {
        for(std::list<TargetInfo>::const_iterator itr = m_UniqueTargetInfo.begin(); itr != m_UniqueTargetInfo.end(); ++itr)
        {
            if( (itr->effectMask & (1 << 0)) && itr->reflectResult == SPELL_MISS_NONE && itr->targetGUID != m_caster->GetGUID())
            {
                target = ObjectAccessor::GetUnit(*m_caster, itr->targetGUID);
                break;
            }
        }
    }
    else if(!m_UniqueGOTargetInfo.empty())
    {
        for(std::list<GOTargetInfo>::const_iterator itr = m_UniqueGOTargetInfo.begin(); itr != m_UniqueGOTargetInfo.end(); ++itr)
        {
            if(itr->effectMask & (1 << 0) )
            {
                target = m_caster->GetMap()->GetGameObject(itr->targetGUID);
                break;
            }
        }
    }

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        WorldPacket data( MSG_CHANNEL_START, (8+4+4) );
        data.append(m_caster->GetPackGUID());
        data << uint32(m_spellInfo->Id);
        data << uint32(duration);

        ((Player*)m_caster)->GetSession()->SendPacket( &data );
    }

    m_timer = duration;
    if(target)
        m_caster->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, target->GetGUID());
    m_caster->SetUInt32Value(UNIT_CHANNEL_SPELL, m_spellInfo->Id);
}

void Spell::SendResurrectRequest(Player* target)
{
    // Both players and NPCs can resurrect using spells - have a look at creature 28487 for example
    // However, the packet structure differs slightly

    const char* sentName = m_caster->GetTypeId() == TYPEID_PLAYER ? "" : m_caster->GetNameForLocaleIdx(target->GetSession()->GetSessionDbLocaleIndex());

    WorldPacket data(SMSG_RESURRECT_REQUEST, (8+4+strlen(sentName)+1+1+1));
    data << uint64(m_caster->GetGUID());
    data << uint32(strlen(sentName) + 1);

    data << sentName;
    data << uint8(0);

    data << uint8(m_caster->GetTypeId() == TYPEID_PLAYER ? 0 : 1);
    target->GetSession()->SendPacket(&data);
}

void Spell::SendPlaySpellVisual(uint32 SpellID)
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    WorldPacket data(SMSG_PLAY_SPELL_VISUAL, 8 + 4);
    data << uint64(m_caster->GetGUID());
    data << uint32(SpellID);                                // spell visual id?
    ((Player*)m_caster)->GetSession()->SendPacket(&data);
}

void Spell::TakeCastItem()
{
    if(!m_CastItem || m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    // not remove cast item at triggered spell (equipping, weapon damage, etc)
    if(m_IsTriggeredSpell)
        return;

    ItemPrototype const *proto = m_CastItem->GetProto();

    if(!proto)
    {
        // This code is to avoid a crash
        // I'm not sure, if this is really an error, but I guess every item needs a prototype
        sLog.outError("Cast item has no item prototype highId=%d, lowId=%d",m_CastItem->GetGUIDHigh(), m_CastItem->GetGUIDLow());
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
        ((Player*)m_caster)->DestroyItemCount(m_CastItem, count, true);

        // prevent crash at access to deleted m_targets.getItemTarget
        if(m_CastItem==m_targets.getItemTarget())
            m_targets.setItemTarget(NULL);

        m_CastItem = NULL;
    }
}

void Spell::TakePower()
{
    if(m_CastItem || m_triggeredByAuraSpell)
        return;

    bool hit = true;
    if(m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        if(m_spellInfo->powerType == POWER_RAGE || m_spellInfo->powerType == POWER_ENERGY)
            if(uint64 targetGUID = m_targets.getUnitTargetGUID())
                for(std::list<TargetInfo>::iterator ihit= m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
                    if(ihit->targetGUID == targetGUID)
                    {
                        if(ihit->missCondition != SPELL_MISS_NONE && ihit->missCondition != SPELL_MISS_MISS/* && ihit->targetGUID!=m_caster->GetGUID()*/)
                            hit = false;
                        if (ihit->missCondition != SPELL_MISS_NONE)
                        {
                            //lower spell cost on fail (by talent aura)
                            if(Player *modOwner = ((Player*)m_caster)->GetSpellModOwner())
                                modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_SPELL_COST_REFUND_ON_FAIL, m_powerCost);
                        }
                        break;
                    }
    }

    Powers powerType = Powers(m_spellInfo->powerType);

    if(powerType == POWER_RUNE)
    {
        TakeRunePower();
        return;
    }

    if (!m_powerCost)
        return;

    // health as power used
    if(m_spellInfo->powerType == POWER_HEALTH)
    {
        m_caster->ModifyHealth( -(int32)m_powerCost );
        return;
    }

    if(m_spellInfo->powerType >= MAX_POWERS)
    {
        sLog.outError("Spell::TakePower: Unknown power type '%d'", m_spellInfo->powerType);
        return;
    }

    if(hit)
        m_caster->ModifyPower(powerType, -m_powerCost);
    else
        m_caster->ModifyPower(powerType, -irand(0, m_powerCost/4));

    // Set the five second timer
    if (powerType == POWER_MANA && m_powerCost > 0)
        m_caster->SetLastManaUse(getMSTime());
}

void Spell::TakeAmmo()
{
    if(m_attackType == RANGED_ATTACK && m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        Item *pItem = ((Player*)m_caster)->GetWeaponForAttack( RANGED_ATTACK );

        // wands don't have ammo
        if(!pItem  || pItem->IsBroken() || pItem->GetProto()->SubClass==ITEM_SUBCLASS_WEAPON_WAND)
            return;

        if( pItem->GetProto()->InventoryType == INVTYPE_THROWN )
        {
            if(pItem->GetMaxStackCount()==1)
            {
                // decrease durability for non-stackable throw weapon
                ((Player*)m_caster)->DurabilityPointLossForEquipSlot(EQUIPMENT_SLOT_RANGED);
            }
            else
            {
                // decrease items amount for stackable throw weapon
                uint32 count = 1;
                ((Player*)m_caster)->DestroyItemCount( pItem, count, true);
            }
        }
        else if(uint32 ammo = ((Player*)m_caster)->GetUInt32Value(PLAYER_AMMO_ID))
            ((Player*)m_caster)->DestroyItemCount(ammo, 1, true);
    }
}

SpellCastResult Spell::CheckRuneCost(uint32 runeCostID)
{
    if(m_caster->GetTypeId() != TYPEID_PLAYER)
        return SPELL_CAST_OK;

    Player *plr = (Player*)m_caster;

    if(plr->getClass() != CLASS_DEATH_KNIGHT)
        return SPELL_CAST_OK;

    SpellRuneCostEntry const *src = sSpellRuneCostStore.LookupEntry(runeCostID);

    if(!src)
        return SPELL_CAST_OK;

    if(src->NoRuneCost())
        return SPELL_CAST_OK;

    int32 runeCost[NUM_RUNE_TYPES];                         // blood, frost, unholy, death

    for(uint32 i = 0; i < RUNE_DEATH; ++i)
        runeCost[i] = src->RuneCost[i];

    runeCost[RUNE_DEATH] = MAX_RUNES;                       // calculated later

    for(uint32 i = 0; i < MAX_RUNES; ++i)
    {
        uint8 rune = plr->GetCurrentRune(i);
        if((plr->GetRuneCooldown(i) == 0) && (runeCost[rune] > 0))
            runeCost[rune]--;
    }

    for(uint32 i = 0; i < RUNE_DEATH; ++i)
        if(runeCost[i] > 0)
            runeCost[RUNE_DEATH] += runeCost[i];

    if(runeCost[RUNE_DEATH] > MAX_RUNES)
        return SPELL_FAILED_NO_POWER;                       // not sure if result code is correct

    return SPELL_CAST_OK;
}

void Spell::TakeRunePower()
{
    if(m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    Player *plr = (Player*)m_caster;

    if(plr->getClass() != CLASS_DEATH_KNIGHT)
        return;

    SpellRuneCostEntry const *src = sSpellRuneCostStore.LookupEntry(m_spellInfo->runeCostID);

    if(!src || (src->NoRuneCost() && src->NoRunicPowerGain()))
        return;
    m_runesState = plr->GetRunesState();                    // store previous state

    int32 runeCost[NUM_RUNE_TYPES];                         // blood, frost, unholy, death

    for(uint32 i = 0; i < RUNE_DEATH; ++i)
    {
        runeCost[i] = src->RuneCost[i];
    }

    runeCost[RUNE_DEATH] = 0;                               // calculated later

    for(uint32 i = 0; i < MAX_RUNES; ++i)
    {
        uint8 rune = plr->GetCurrentRune(i);
        if((plr->GetRuneCooldown(i) == 0) && (runeCost[rune] > 0))
        {
            plr->SetRuneCooldown(i, RUNE_COOLDOWN);         // 5*2=10 sec
            runeCost[rune]--;
        }
    }

    runeCost[RUNE_DEATH] = runeCost[RUNE_BLOOD] + runeCost[RUNE_UNHOLY] + runeCost[RUNE_FROST];

    if(runeCost[RUNE_DEATH] > 0)
    {
        for(uint32 i = 0; i < MAX_RUNES; ++i)
        {
            uint8 rune = plr->GetCurrentRune(i);
            if((plr->GetRuneCooldown(i) == 0) && (rune == RUNE_DEATH))
            {
                plr->SetRuneCooldown(i, RUNE_COOLDOWN);     // 5*2=10 sec
                runeCost[rune]--;
                plr->ConvertRune(i, plr->GetBaseRune(i));
                if(runeCost[RUNE_DEATH] == 0)
                    break;
            }
        }
    }

    // you can gain some runic power when use runes
    float rp = src->runePowerGain;
    rp *= sWorld.getRate(RATE_POWER_RUNICPOWER_INCOME);
    plr->ModifyPower(POWER_RUNIC_POWER, (int32)rp);
}

void Spell::TakeReagents()
{
    if(m_IsTriggeredSpell)                                  // reagents used in triggered spell removed by original spell or don't must be removed.
        return;

    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    // do not take reagents for these item casts
    if (m_CastItem && m_CastItem->GetProto()->Flags & ITEM_FLAGS_TRIGGERED_CAST)
        return;

    Player* p_caster = (Player*)m_caster;
    if (p_caster->CanNoReagentCast(m_spellInfo))
        return;

    for(uint32 x = 0; x < 8; ++x)
    {
        if(m_spellInfo->Reagent[x] <= 0)
            continue;

        uint32 itemid = m_spellInfo->Reagent[x];
        uint32 itemcount = m_spellInfo->ReagentCount[x];

        // if CastItem is also spell reagent
        if (m_CastItem)
        {
            ItemPrototype const *proto = m_CastItem->GetProto();
            if( proto && proto->ItemId == itemid )
            {
                for(int s = 0; s < MAX_ITEM_PROTO_SPELLS; ++s)
                {
                    // CastItem will be used up and does not count as reagent
                    int32 charges = m_CastItem->GetSpellCharges(s);
                    if (proto->Spells[s].SpellCharges < 0 && abs(charges) < 2)
                    {
                        ++itemcount;
                        break;
                    }
                }

                m_CastItem = NULL;
            }
        }

        // if getItemTarget is also spell reagent
        if (m_targets.getItemTargetEntry() == itemid)
            m_targets.setItemTarget(NULL);

        p_caster->DestroyItemCount(itemid, itemcount, true);
    }
}

void Spell::HandleThreatSpells(uint32 spellId)
{
    if(!m_targets.getUnitTarget() || !spellId)
        return;

    if(!m_targets.getUnitTarget()->CanHaveThreatList())
        return;

    uint16 threat = spellmgr.GetSpellThreat(spellId);

    if(!threat)
        return;

    m_targets.getUnitTarget()->AddThreat(m_caster, float(threat));

    DEBUG_LOG("Spell %u, rank %u, added an additional %i threat", spellId, spellmgr.GetSpellRank(spellId), threat);
}

void Spell::HandleEffects(Unit *pUnitTarget,Item *pItemTarget,GameObject *pGOTarget,uint32 i)
{
    //effect has been handled, skip it
    if(m_effectMask & (1<<i))
        return;

    unitTarget = pUnitTarget;
    itemTarget = pItemTarget;
    gameObjTarget = pGOTarget;

    uint8 eff = m_spellInfo->Effect[i];

    sLog.outDebug( "Spell: %u Effect : %u", m_spellInfo->Id, eff);

    //we do not need DamageMultiplier here.
    damage = CalculateDamage(i, NULL);

    if(eff<TOTAL_SPELL_EFFECTS)
    {
        //sLog.outDebug( "WORLD: Spell FX %d < TOTAL_SPELL_EFFECTS ", eff);
        (this->*SpellEffects[eff])(i);
    }
}

void Spell::TriggerSpell()
{
    for(TriggerSpells::iterator si=m_TriggerSpells.begin(); si!=m_TriggerSpells.end(); ++si)
    {
        Spell* spell = new Spell(m_caster, (*si), true, m_originalCasterGUID, m_selfContainer, true);
        spell->prepare(&m_targets);                         // use original spell original targets
    }
}

SpellCastResult Spell::CheckCast(bool strict)
{
    // check cooldowns to prevent cheating
    if(m_caster->GetTypeId()==TYPEID_PLAYER)
    {
        //can cast triggered (by aura only?) spells while have this flag
        if (!m_IsTriggeredSpell && ((Player*)m_caster)->HasFlag(PLAYER_FLAGS, PLAYER_ALLOW_ONLY_ABILITY))
            return SPELL_FAILED_SPELL_IN_PROGRESS;

        if  (((Player*)m_caster)->HasSpellCooldown(m_spellInfo->Id))
        {
            if(m_triggeredByAuraSpell)
                return SPELL_FAILED_DONT_REPORT;
            else
                return SPELL_FAILED_NOT_READY;
        }
    }

    // only allow triggered spells if at an ended battleground
    if( !m_IsTriggeredSpell && m_caster->GetTypeId() == TYPEID_PLAYER)
        if(BattleGround * bg = ((Player*)m_caster)->GetBattleGround())
            if(bg->GetStatus() == STATUS_WAIT_LEAVE)
                return SPELL_FAILED_DONT_REPORT;

    // only check at first call, Stealth auras are already removed at second call
    // for now, ignore triggered spells
    if( strict && !m_IsTriggeredSpell)
    {
        bool checkForm = true;
        // Ignore form req aura
        Unit::AuraEffectList const& ignore = m_caster->GetAurasByType(SPELL_AURA_MOD_IGNORE_SHAPESHIFT);
        for(Unit::AuraEffectList::const_iterator i = ignore.begin(); i != ignore.end(); ++i)
        {
            if (!(*i)->isAffectedOnSpell(m_spellInfo))
                continue;
            checkForm = false;
            break;
        }
        if (checkForm)
        {
            // Cannot be used in this stance/form
            SpellCastResult shapeError = GetErrorAtShapeshiftedCast(m_spellInfo, m_caster->m_form);
            if(shapeError != SPELL_CAST_OK)
                return shapeError;

            if ((m_spellInfo->Attributes & SPELL_ATTR_ONLY_STEALTHED) && !(m_caster->HasStealthAura()))
                return SPELL_FAILED_ONLY_STEALTHED;
        }
    }

    bool reqCombat=true;
    Unit::AuraEffectList const& stateAuras = m_caster->GetAurasByType(SPELL_AURA_ABILITY_IGNORE_AURASTATE);
    for(Unit::AuraEffectList::const_iterator j = stateAuras.begin();j != stateAuras.end(); ++j)
    {
        if((*j)->isAffectedOnSpell(m_spellInfo))
        {
            if ((*j)->GetMiscValue()==1)
            {
                reqCombat=false;
                break;
            }
        }
    }

    // caster state requirements 
    // not for triggered spells (needed by execute)
    if (!m_IsTriggeredSpell)
    {
        if(m_spellInfo->CasterAuraState && !m_caster->HasAuraState(AuraState(m_spellInfo->CasterAuraState), m_spellInfo, m_caster))
            return SPELL_FAILED_CASTER_AURASTATE;
        if(m_spellInfo->CasterAuraStateNot && m_caster->HasAuraState(AuraState(m_spellInfo->CasterAuraStateNot), m_spellInfo, m_caster))
            return SPELL_FAILED_CASTER_AURASTATE;

        if(m_spellInfo->casterAuraSpell && !m_caster->HasAura(m_spellInfo->casterAuraSpell))
            return SPELL_FAILED_CASTER_AURASTATE;
        if(m_spellInfo->excludeCasterAuraSpell && m_caster->HasAura(m_spellInfo->excludeCasterAuraSpell))
            return SPELL_FAILED_CASTER_AURASTATE;

        if(reqCombat && m_caster->isInCombat() && IsNonCombatSpell(m_spellInfo))
            return SPELL_FAILED_AFFECTING_COMBAT;
    }

    // cancel autorepeat spells if cast start when moving
    // (not wand currently autorepeat cast delayed to moving stop anyway in spell update code)
    if( m_caster->GetTypeId()==TYPEID_PLAYER && ((Player*)m_caster)->isMoving() )
    {
        // skip stuck spell to allow use it in falling case and apply spell limitations at movement
        if( (!((Player*)m_caster)->m_movementInfo.HasMovementFlag(MOVEMENTFLAG_FALLING) || m_spellInfo->Effect[0] != SPELL_EFFECT_STUCK) &&
            (IsAutoRepeat() || (m_spellInfo->AuraInterruptFlags & AURA_INTERRUPT_FLAG_NOT_SEATED) != 0) )
            return SPELL_FAILED_MOVING;
    }

    if(Unit *target = m_targets.getUnitTarget())
    {
        // target state requirements (not allowed state), apply to self also
        if(!m_IsTriggeredSpell && m_spellInfo->TargetAuraStateNot && target->HasAuraState(AuraState(m_spellInfo->TargetAuraStateNot), m_spellInfo, m_caster))
            return SPELL_FAILED_TARGET_AURASTATE;

        if(m_spellInfo->targetAuraSpell && !target->HasAura(m_spellInfo->targetAuraSpell))
            return SPELL_FAILED_TARGET_AURASTATE;

        if(m_spellInfo->excludeTargetAuraSpell && target->HasAura(m_spellInfo->excludeTargetAuraSpell))
            return SPELL_FAILED_TARGET_AURASTATE;

        if(!m_IsTriggeredSpell && target == m_caster && m_spellInfo->AttributesEx & SPELL_ATTR_EX_CANT_TARGET_SELF)
            return SPELL_FAILED_BAD_TARGETS;

        bool non_caster_target = target != m_caster && !spellmgr.IsSpellWithCasterSourceTargetsOnly(m_spellInfo);

        if(non_caster_target)
        {
            // target state requirements (apply to non-self only), to allow cast affects to self like Dirty Deeds
            if(!m_IsTriggeredSpell && m_spellInfo->TargetAuraState && !target->HasAuraState(AuraState(m_spellInfo->TargetAuraState), m_spellInfo, m_caster))
                return SPELL_FAILED_TARGET_AURASTATE;

            // Not allow casting on flying player
            if (target->hasUnitState(UNIT_STAT_UNATTACKABLE))
                return SPELL_FAILED_BAD_TARGETS;

            if(!m_IsTriggeredSpell && VMAP::VMapFactory::checkSpellForLoS(m_spellInfo->Id) && !m_caster->IsWithinLOSInMap(target))
                return SPELL_FAILED_LINE_OF_SIGHT;

        }
        else if (m_caster->GetTypeId() == TYPEID_PLAYER)    // Target - is player caster
        {
            // Additional check for some spells
            // If 0 spell effect empty - client not send target data (need use selection)
            // TODO: check it on next client version
            if (m_targets.m_targetMask == TARGET_FLAG_SELF &&
                m_spellInfo->EffectImplicitTargetA[1] == TARGET_UNIT_TARGET_ENEMY)
            {
                if (target = m_caster->GetUnit(*m_caster, ((Player *)m_caster)->GetSelection()))
                    m_targets.setUnitTarget(target);
                else
                    return SPELL_FAILED_BAD_TARGETS;
            }
        }

        // check pet presents
        for(int j = 0; j < 3; ++j)
        {
            if(m_spellInfo->EffectImplicitTargetA[j] == TARGET_UNIT_PET)
            {
                target = m_caster->GetGuardianPet();
                if(!target)
                {
                    if(m_triggeredByAuraSpell)              // not report pet not existence for triggered spells
                        return SPELL_FAILED_DONT_REPORT;
                    else
                        return SPELL_FAILED_NO_PET;
                }
                break;
            }
        }

        //check creature type
        //ignore self casts (including area casts when caster selected as target)
        if(non_caster_target)
        {
            if(!CheckTargetCreatureType(target))
            {
                if(target->GetTypeId() == TYPEID_PLAYER)
                    return SPELL_FAILED_TARGET_IS_PLAYER;
                else
                    return SPELL_FAILED_BAD_TARGETS;
            }
        }

        // TODO: this check can be applied and for player to prevent cheating when IsPositiveSpell will return always correct result.
        // check target for pet/charmed casts (not self targeted), self targeted cast used for area effects and etc
        if(non_caster_target && m_caster->GetTypeId() == TYPEID_UNIT && m_caster->GetCharmerOrOwnerGUID())
        {
            // check correctness positive/negative cast target (pet cast real check and cheating check)
            if(IsPositiveSpell(m_spellInfo->Id))
            {
                                                     //dispel positivity is dependant on target, don't check it
                if(m_caster->IsHostileTo(target) && !IsDispel(m_spellInfo))
                    return SPELL_FAILED_BAD_TARGETS;
            }
            else
            {
                if(m_caster->IsFriendlyTo(target))
                    return SPELL_FAILED_BAD_TARGETS;
            }
        }

        if(IsPositiveSpell(m_spellInfo->Id))
            if(target->IsImmunedToSpell(m_spellInfo))
                return SPELL_FAILED_TARGET_AURASTATE;

        //Must be behind the target.
        if( m_spellInfo->AttributesEx2 == 0x100000 && (m_spellInfo->AttributesEx & 0x200) == 0x200 && target->HasInArc(M_PI, m_caster)
            //Exclusion for Pounce: Facing Limitation was removed in 2.0.1, but it still uses the same, old Ex-Flags
            && (!(m_spellInfo->SpellFamilyName == SPELLFAMILY_DRUID && m_spellInfo->SpellFamilyFlags.IsEqual(0x20000,0,0)))
            //Mutilate no longer requires you be behind the target as of patch 3.0.3
            && (!(m_spellInfo->SpellFamilyName == SPELLFAMILY_ROGUE && m_spellInfo->SpellFamilyFlags[1] & 0x200000)))
        {
            SendInterrupted(2);
            return SPELL_FAILED_NOT_BEHIND;
        }

        //Target must be facing you.
        if((m_spellInfo->Attributes == 0x150010) && !target->HasInArc(M_PI, m_caster) )
        {
            SendInterrupted(2);
            return SPELL_FAILED_NOT_INFRONT;
        }

        // check if target is in combat
        if (non_caster_target && (m_spellInfo->AttributesEx & SPELL_ATTR_EX_NOT_IN_COMBAT_TARGET) && target->isInCombat())
            return SPELL_FAILED_TARGET_AFFECTING_COMBAT;
    }

    // Spell casted only on battleground
    if((m_spellInfo->AttributesEx3 & SPELL_ATTR_EX3_BATTLEGROUND) &&  m_caster->GetTypeId() == TYPEID_PLAYER)
        if(!((Player*)m_caster)->InBattleGround())
            return SPELL_FAILED_ONLY_BATTLEGROUNDS;

    // do not allow spells to be cast in arenas
    // - with greater than 15 min CD without SPELL_ATTR_EX4_USABLE_IN_ARENA flag
    // - with SPELL_ATTR_EX4_NOT_USABLE_IN_ARENA flag
    if( (m_spellInfo->AttributesEx4 & SPELL_ATTR_EX4_NOT_USABLE_IN_ARENA) ||
        GetSpellRecoveryTime(m_spellInfo) > 15 * MINUTE * IN_MILISECONDS && !(m_spellInfo->AttributesEx4 & SPELL_ATTR_EX4_USABLE_IN_ARENA) )
        if(MapEntry const* mapEntry = sMapStore.LookupEntry(m_caster->GetMapId()))
            if(mapEntry->IsBattleArena())
                return SPELL_FAILED_NOT_IN_ARENA;

    // zone check
    if(m_caster->GetTypeId() == TYPEID_UNIT || !((Player*)m_caster)->isGameMaster())
    {
        uint32 zone, area;
        m_caster->GetZoneAndAreaId(zone,area);

        SpellCastResult locRes= spellmgr.GetSpellAllowedInLocationError(m_spellInfo,m_caster->GetMapId(),zone,area,
            m_caster->GetTypeId()==TYPEID_PLAYER ? ((Player*)m_caster) : NULL);
        if(locRes != SPELL_CAST_OK)
            return locRes;
    }

    // not let players cast spells at mount (and let do it to creatures)
    if( m_caster->IsMounted() && m_caster->GetTypeId()==TYPEID_PLAYER && !m_IsTriggeredSpell &&
        !IsPassiveSpell(m_spellInfo->Id) && !(m_spellInfo->Attributes & SPELL_ATTR_CASTABLE_WHILE_MOUNTED) )
    {
        if(m_caster->isInFlight())
            return SPELL_FAILED_NOT_FLYING;
        else
            return SPELL_FAILED_NOT_MOUNTED;
    }

    // always (except passive spells) check items (focus object can be required for any type casts)
    if(!IsPassiveSpell(m_spellInfo->Id))
    {
        SpellCastResult castResult = CheckItems();
        if(castResult != SPELL_CAST_OK)
            return castResult;
    }

    /*//ImpliciteTargetA-B = 38, If fact there is 0 Spell with  ImpliciteTargetB=38
    if(m_UniqueTargetInfo.empty())                          // skip second CheckCast apply (for delayed spells for example)
    {
        for(uint8 j = 0; j < 3; ++j)
        {
            if( m_spellInfo->EffectImplicitTargetA[j] == TARGET_UNIT_NEARBY_ENTRY ||
                m_spellInfo->EffectImplicitTargetB[j] == TARGET_UNIT_NEARBY_ENTRY && m_spellInfo->EffectImplicitTargetA[j] != TARGET_UNIT_CASTER ||
                m_spellInfo->EffectImplicitTargetA[j] == TARGET_DST_NEARBY_ENTRY ||
                m_spellInfo->EffectImplicitTargetB[j] == TARGET_DST_NEARBY_ENTRY )
            {
                SpellScriptTarget::const_iterator lower = spellmgr.GetBeginSpellScriptTarget(m_spellInfo->Id);
                SpellScriptTarget::const_iterator upper = spellmgr.GetEndSpellScriptTarget(m_spellInfo->Id);
                if(lower==upper)
                    sLog.outErrorDb("Spell (ID: %u) has effect EffectImplicitTargetA/EffectImplicitTargetB = TARGET_UNIT_NEARBY_ENTRY or TARGET_DST_NEARBY_ENTRY, but does not have record in `spell_script_target`",m_spellInfo->Id);

                SpellRangeEntry const* srange = sSpellRangeStore.LookupEntry(m_spellInfo->rangeIndex);
                float range = GetSpellMaxRange(srange);

                Creature* creatureScriptTarget = NULL;
                GameObject* goScriptTarget = NULL;

                for(SpellScriptTarget::const_iterator i_spellST = lower; i_spellST != upper; ++i_spellST)
                {
                    switch(i_spellST->second.type)
                    {
                        case SPELL_TARGET_TYPE_GAMEOBJECT:
                        {
                            GameObject* p_GameObject = NULL;

                            if(i_spellST->second.targetEntry)
                            {
                                CellPair p(MaNGOS::ComputeCellPair(m_caster->GetPositionX(), m_caster->GetPositionY()));
                                Cell cell(p);
                                cell.data.Part.reserved = ALL_DISTRICT;

                                MaNGOS::NearestGameObjectEntryInObjectRangeCheck go_check(*m_caster,i_spellST->second.targetEntry,range);
                                MaNGOS::GameObjectLastSearcher<MaNGOS::NearestGameObjectEntryInObjectRangeCheck> checker(m_caster, p_GameObject,go_check);

                                TypeContainerVisitor<MaNGOS::GameObjectLastSearcher<MaNGOS::NearestGameObjectEntryInObjectRangeCheck>, GridTypeMapContainer > object_checker(checker);
                                CellLock<GridReadGuard> cell_lock(cell, p);
                                cell_lock->Visit(cell_lock, object_checker, *m_caster->GetMap());

                                if(p_GameObject)
                                {
                                    // remember found target and range, next attempt will find more near target with another entry
                                    creatureScriptTarget = NULL;
                                    goScriptTarget = p_GameObject;
                                    range = go_check.GetLastRange();
                                }
                            }
                            else if( focusObject )          // Focus Object
                            {
                                float frange = m_caster->GetDistance(focusObject);
                                if(range >= frange)
                                {
                                    creatureScriptTarget = NULL;
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
                            Creature *p_Creature = NULL;

                            CellPair p(MaNGOS::ComputeCellPair(m_caster->GetPositionX(), m_caster->GetPositionY()));
                            Cell cell(p);
                            cell.data.Part.reserved = ALL_DISTRICT;
                            cell.SetNoCreate();             // Really don't know what is that???

                            MaNGOS::NearestCreatureEntryWithLiveStateInObjectRangeCheck u_check(*m_caster,i_spellST->second.targetEntry,i_spellST->second.type!=SPELL_TARGET_TYPE_DEAD,range);
                            MaNGOS::CreatureLastSearcher<MaNGOS::NearestCreatureEntryWithLiveStateInObjectRangeCheck> searcher(m_caster, p_Creature, u_check);

                            TypeContainerVisitor<MaNGOS::CreatureLastSearcher<MaNGOS::NearestCreatureEntryWithLiveStateInObjectRangeCheck>, GridTypeMapContainer >  grid_creature_searcher(searcher);

                            CellLock<GridReadGuard> cell_lock(cell, p);
                            cell_lock->Visit(cell_lock, grid_creature_searcher, *m_caster->GetMap());

                            if(p_Creature )
                            {
                                creatureScriptTarget = p_Creature;
                                goScriptTarget = NULL;
                                range = u_check.GetLastRange();
                            }
                            break;
                        }
                    }
                }

                if(creatureScriptTarget)
                {
                    // store coordinates for TARGET_DST_NEARBY_ENTRY
                    if (m_spellInfo->EffectImplicitTargetA[j] == TARGET_DST_NEARBY_ENTRY ||
                        m_spellInfo->EffectImplicitTargetB[j] == TARGET_DST_NEARBY_ENTRY )
                    {
                        m_targets.setDestination(creatureScriptTarget->GetPositionX(),creatureScriptTarget->GetPositionY(),creatureScriptTarget->GetPositionZ());

                        if(m_spellInfo->EffectImplicitTargetA[j] == TARGET_DST_NEARBY_ENTRY && m_spellInfo->EffectImplicitTargetB[j] == 0 && m_spellInfo->Effect[j]!=SPELL_EFFECT_PERSISTENT_AREA_AURA)
                            AddUnitTarget(creatureScriptTarget, j);
                    }
                    // store explicit target for TARGET_UNIT_NEARBY_ENTRY
                    else
                        AddUnitTarget(creatureScriptTarget, j);
                }
                else if(goScriptTarget)
                {
                    // store coordinates for TARGET_DST_NEARBY_ENTRY
                    if (m_spellInfo->EffectImplicitTargetA[j] == TARGET_DST_NEARBY_ENTRY ||
                        m_spellInfo->EffectImplicitTargetB[j] == TARGET_DST_NEARBY_ENTRY )
                    {
                        m_targets.setDestination(goScriptTarget->GetPositionX(),goScriptTarget->GetPositionY(),goScriptTarget->GetPositionZ());

                        if(m_spellInfo->EffectImplicitTargetA[j] == TARGET_DST_NEARBY_ENTRY && m_spellInfo->EffectImplicitTargetB[j] == 0 && m_spellInfo->Effect[j]!=SPELL_EFFECT_PERSISTENT_AREA_AURA)
                            AddGOTarget(goScriptTarget, j);
                    }
                    // store explicit target for TARGET_UNIT_NEARBY_ENTRY
                    else
                        AddGOTarget(goScriptTarget, j);
                }
                //Missing DB Entry or targets for this spellEffect.
                else
                {
                    // not report target not existence for triggered spells
                    if(m_triggeredByAuraSpell || m_IsTriggeredSpell)
                        return SPELL_FAILED_DONT_REPORT;
                    else
                        return SPELL_FAILED_BAD_TARGETS;
                }
            }
        }
    }*/

    if(!m_IsTriggeredSpell)
    {
        SpellCastResult castResult = CheckRange(strict);
        if(castResult != SPELL_CAST_OK)
            return castResult;

        castResult = CheckPower();
        if(castResult != SPELL_CAST_OK)
            return castResult;

        castResult = CheckCasterAuras();
        if(castResult != SPELL_CAST_OK)
            return castResult;
    }

    for (int i = 0; i < 3; i++)
    {
        // for effects of spells that have only one target
        switch(m_spellInfo->Effect[i])
        {
            case SPELL_EFFECT_DUMMY:
            {
                if (m_spellInfo->Id == 51582)          // Rocket Boots Engaged
                {
                    if(m_caster->IsInWater())
                        return SPELL_FAILED_ONLY_ABOVEWATER;
                }
                else if(m_spellInfo->SpellIconID == 156)    // Holy Shock
                {
                    // spell different for friends and enemies
                    // hart version required facing
                    if(m_targets.getUnitTarget() && !m_caster->IsFriendlyTo(m_targets.getUnitTarget()) && !m_caster->HasInArc( M_PI, m_targets.getUnitTarget() ))
                        return SPELL_FAILED_UNIT_NOT_INFRONT;
                }
                else if (m_spellInfo->SpellFamilyName == SPELLFAMILY_DEATHKNIGHT && m_spellInfo->SpellFamilyFlags[0] == 0x2000) // Death Coil (DeathKnight)
                {
                    Unit* target = m_targets.getUnitTarget();
                    if (!target || (target->IsFriendlyTo(m_caster) && target->GetCreatureType() != CREATURE_TYPE_UNDEAD))
                        return SPELL_FAILED_BAD_TARGETS;
                }
                else if (m_spellInfo->Id == 19938)          // Awaken Peon
                {
                    Unit *unit = m_targets.getUnitTarget();
                    if(!unit || !unit->HasAura(17743, 0))
                        return SPELL_FAILED_BAD_TARGETS;
                }
                else if (m_spellInfo->Id == 52264)          // Deliver Stolen Horse
                {
                    if(!m_caster->FindNearestCreature(28653,5))
                        return SPELL_FAILED_OUT_OF_RANGE;
                }
                break;
            }
            case SPELL_EFFECT_LEARN_SPELL:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_BAD_TARGETS;

                if(m_spellInfo->EffectImplicitTargetA[i] != TARGET_UNIT_PET)
                    break;

                Pet* pet = ((Player*)m_caster)->GetPet();

                if(!pet)
                    return SPELL_FAILED_NO_PET;

                SpellEntry const *learn_spellproto = sSpellStore.LookupEntry(m_spellInfo->EffectTriggerSpell[i]);

                if(!learn_spellproto)
                    return SPELL_FAILED_NOT_KNOWN;

                if(m_spellInfo->spellLevel > pet->getLevel())
                    return SPELL_FAILED_LOWLEVEL;

                break;
            }
            case SPELL_EFFECT_LEARN_PET_SPELL:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_BAD_TARGETS;

                Pet* pet = ((Player*)m_caster)->GetPet();
                if(!pet)
                    return SPELL_FAILED_NO_PET;

                SpellEntry const *learn_spellproto = sSpellStore.LookupEntry(m_spellInfo->EffectTriggerSpell[i]);

                if(!learn_spellproto)
                    return SPELL_FAILED_NOT_KNOWN;

                if(m_spellInfo->spellLevel > pet->getLevel())
                    return SPELL_FAILED_LOWLEVEL;

                break;
            }
            case SPELL_EFFECT_APPLY_GLYPH:
            {
                uint32 glyphId = m_spellInfo->EffectMiscValue[i];
                if(GlyphPropertiesEntry const *gp = sGlyphPropertiesStore.LookupEntry(glyphId))
                    if(m_caster->HasAura(gp->SpellId))
                        return SPELL_FAILED_UNIQUE_GLYPH;
                break;
            }
            case SPELL_EFFECT_FEED_PET:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_BAD_TARGETS;

                Item* foodItem = m_targets.getItemTarget();
                if(!foodItem)
                    return SPELL_FAILED_BAD_TARGETS;

                Pet* pet = ((Player*)m_caster)->GetPet();

                if(!pet)
                    return SPELL_FAILED_NO_PET;

                if(!pet->HaveInDiet(foodItem->GetProto()))
                    return SPELL_FAILED_WRONG_PET_FOOD;

                if(!pet->GetCurrentFoodBenefitLevel(foodItem->GetProto()->ItemLevel))
                    return SPELL_FAILED_FOOD_LOWLEVEL;

                if(m_caster->isInCombat() || pet->isInCombat())
                    return SPELL_FAILED_AFFECTING_COMBAT;

                break;
            }
            case SPELL_EFFECT_POWER_BURN:
            case SPELL_EFFECT_POWER_DRAIN:
            {
                // Can be area effect, Check only for players and not check if target - caster (spell can have multiply drain/burn effects)
                if(m_caster->GetTypeId() == TYPEID_PLAYER)
                    if(Unit* target = m_targets.getUnitTarget())
                        if(target != m_caster && target->getPowerType() != m_spellInfo->EffectMiscValue[i])
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
                if (m_caster->hasUnitState(UNIT_STAT_ROOT))
                    return SPELL_FAILED_ROOTED;
                break;
            }
            case SPELL_EFFECT_SKINNING:
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER || !m_targets.getUnitTarget() || m_targets.getUnitTarget()->GetTypeId() != TYPEID_UNIT)
                    return SPELL_FAILED_BAD_TARGETS;

                if( !(m_targets.getUnitTarget()->GetUInt32Value(UNIT_FIELD_FLAGS) & UNIT_FLAG_SKINNABLE) )
                    return SPELL_FAILED_TARGET_UNSKINNABLE;

                Creature* creature = (Creature*)m_targets.getUnitTarget();
                if ( creature->GetCreatureType() != CREATURE_TYPE_CRITTER && ( !creature->lootForBody || !creature->loot.empty() ) )
                {
                    return SPELL_FAILED_TARGET_NOT_LOOTED;
                }

                uint32 skill = creature->GetCreatureInfo()->GetRequiredLootSkill();

                int32 skillValue = ((Player*)m_caster)->GetSkillValue(skill);
                int32 TargetLevel = m_targets.getUnitTarget()->getLevel();
                int32 ReqValue = (skillValue < 100 ? (TargetLevel-10) * 10 : TargetLevel * 5);
                if (ReqValue > skillValue)
                    return SPELL_FAILED_LOW_CASTLEVEL;

                // chance for fail at orange skinning attempt
                if( (m_selfContainer && (*m_selfContainer) == this) &&
                    skillValue < sWorld.GetConfigMaxSkillValue() &&
                    (ReqValue < 0 ? 0 : ReqValue) > irand(skillValue - 25, skillValue + 37) )
                    return SPELL_FAILED_TRY_AGAIN;

                break;
            }
            case SPELL_EFFECT_OPEN_LOCK:
            {
                if( m_spellInfo->EffectImplicitTargetA[i] != TARGET_GAMEOBJECT &&
                    m_spellInfo->EffectImplicitTargetA[i] != TARGET_GAMEOBJECT_ITEM )
                    break;

                if( m_caster->GetTypeId() != TYPEID_PLAYER  // only players can open locks, gather etc.
                    // we need a go target in case of TARGET_GAMEOBJECT
                    || m_spellInfo->EffectImplicitTargetA[i] == TARGET_GAMEOBJECT && !m_targets.getGOTarget()
                    // we need a go target, or an openable item target in case of TARGET_GAMEOBJECT_ITEM
                    || m_spellInfo->EffectImplicitTargetA[i] == TARGET_GAMEOBJECT_ITEM && !m_targets.getGOTarget() &&
                    (!m_targets.getItemTarget() || !m_targets.getItemTarget()->GetProto()->LockID || m_targets.getItemTarget()->GetOwner() != m_caster ) )
                    return SPELL_FAILED_BAD_TARGETS;

                // In BattleGround players can use only flags and banners
                if( ((Player*)m_caster)->InBattleGround() &&
                    !((Player*)m_caster)->CanUseBattleGroundObject() )
                    return SPELL_FAILED_TRY_AGAIN;

                // get the lock entry
                uint32 lockId = 0;
                if (GameObject* go = m_targets.getGOTarget())
                {
                    lockId = go->GetGOInfo()->GetLockId();
                    if (!lockId)
                        return SPELL_FAILED_BAD_TARGETS;
                }
                else if(Item* itm = m_targets.getItemTarget())
                    lockId = itm->GetProto()->LockID;

                SkillType skillId = SKILL_NONE;
                int32 reqSkillValue = 0;
                int32 skillValue = 0;

                // check lock compatibility
                SpellCastResult res = CanOpenLock(i, lockId, skillId, reqSkillValue, skillValue);
                if(res != SPELL_CAST_OK)
                    return res;

                // chance for fail at orange mining/herb/LockPicking gathering attempt
                // second check prevent fail at rechecks
                if(skillId != SKILL_NONE && (!m_selfContainer || ((*m_selfContainer) != this)))
                {
                    bool canFailAtMax = skillId != SKILL_HERBALISM && skillId != SKILL_MINING;

                    // chance for failure in orange gather / lockpick (gathering skill can't fail at maxskill)
                    if((canFailAtMax || skillValue < sWorld.GetConfigMaxSkillValue()) && reqSkillValue > irand(skillValue - 25, skillValue + 37))
                        return SPELL_FAILED_TRY_AGAIN;
                }
                break;
            }
            case SPELL_EFFECT_SUMMON_DEAD_PET:
            {
                Creature *pet = m_caster->GetGuardianPet();
                if(!pet)
                    return SPELL_FAILED_NO_PET;

                if(pet->isAlive())
                    return SPELL_FAILED_ALREADY_HAVE_SUMMON;

                break;
            }
            // This is generic summon effect
            case SPELL_EFFECT_SUMMON:
            {
                SummonPropertiesEntry const *SummonProperties = sSummonPropertiesStore.LookupEntry(m_spellInfo->EffectMiscValueB[i]);
                if(!SummonProperties)
                    break;
                switch(SummonProperties->Category)
                {
                    case SUMMON_CATEGORY_PET:
                        if(m_caster->GetPetGUID())
                            return SPELL_FAILED_ALREADY_HAVE_SUMMON;
                    case SUMMON_CATEGORY_PUPPET:
                        if(m_caster->GetCharmGUID())
                            return SPELL_FAILED_ALREADY_HAVE_CHARM;
                        break;
                }
                break;
            }
            // Not used for summon?
            case SPELL_EFFECT_SUMMON_PHANTASM:
            {
                if(m_caster->GetPetGUID())
                    return SPELL_FAILED_ALREADY_HAVE_SUMMON;

                if(m_caster->GetCharmGUID())
                    return SPELL_FAILED_ALREADY_HAVE_CHARM;

                break;
            }
            case SPELL_EFFECT_SUMMON_PET:
            {
                if(m_caster->GetPetGUID())                  //let warlock do a replacement summon
                {
                    if (m_caster->GetTypeId()==TYPEID_PLAYER && m_caster->getClass()==CLASS_WARLOCK)
                    {
                        if (strict)                         //starting cast, trigger pet stun (cast by pet so it doesn't attack player)
                            if(Pet* pet = ((Player*)m_caster)->GetPet())
                                pet->CastSpell(pet, 32752, true, NULL, NULL, pet->GetGUID());
                    }
                    else
                        return SPELL_FAILED_ALREADY_HAVE_SUMMON;
                }

                if(m_caster->GetCharmGUID())
                    return SPELL_FAILED_ALREADY_HAVE_CHARM;

                break;
            }
            case SPELL_EFFECT_SUMMON_PLAYER:
            {
                if(m_caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_BAD_TARGETS;
                if(!((Player*)m_caster)->GetSelection())
                    return SPELL_FAILED_BAD_TARGETS;

                Player* target = objmgr.GetPlayer(((Player*)m_caster)->GetSelection());
                if( !target || ((Player*)m_caster) == target || !target->IsInSameRaidWith((Player*)m_caster) )
                    return SPELL_FAILED_BAD_TARGETS;

                // check if our map is dungeon
                if( sMapStore.LookupEntry(m_caster->GetMapId())->IsDungeon() )
                {
                    InstanceTemplate const* instance = ObjectMgr::GetInstanceTemplate(m_caster->GetMapId());
                    if(!instance)
                        return SPELL_FAILED_TARGET_NOT_IN_INSTANCE;
                    if(!target->Satisfy(objmgr.GetAccessRequirement(instance->access_id), m_caster->GetMapId()))
                        return SPELL_FAILED_BAD_TARGETS;
                }
                break;
            }
            case SPELL_EFFECT_LEAP:
            case SPELL_EFFECT_TELEPORT_UNITS_FACE_CASTER:
            {
              //Do not allow to cast it before BG starts.
                if(m_caster->GetTypeId()==TYPEID_PLAYER)
                    if(BattleGround const *bg = ((Player*)m_caster)->GetBattleGround())
                        if(bg->GetStatus() != STATUS_IN_PROGRESS)
                            return SPELL_FAILED_TRY_AGAIN;
                break;
            }
            case SPELL_EFFECT_STEAL_BENEFICIAL_BUFF:
            {
                if (m_targets.getUnitTarget() == m_caster)
                    return SPELL_FAILED_BAD_TARGETS;
                break;
            }
            default:break;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        switch(m_spellInfo->EffectApplyAuraName[i])
        {
            case SPELL_AURA_DUMMY:
            {
                //custom check
                switch(m_spellInfo->Id)
                {
                    case 61336:
                        if(m_caster->GetTypeId() != TYPEID_PLAYER || !((Player*)m_caster)->IsInFeralForm())
                            return SPELL_FAILED_ONLY_SHAPESHIFT;
                        break;
                    case 1515:
                    {
                        if (m_caster->GetTypeId() != TYPEID_PLAYER)
                            return SPELL_FAILED_BAD_TARGETS;

                        if (!m_targets.getUnitTarget() || m_targets.getUnitTarget()->GetTypeId() == TYPEID_PLAYER)
                            return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

                        Creature* target = (Creature*)m_targets.getUnitTarget();

                        if (target->getLevel() > m_caster->getLevel())
                            return SPELL_FAILED_HIGHLEVEL;

                        // use SMSG_PET_TAME_FAILURE?
                        if (!target->GetCreatureInfo()->isTameable (((Player*)m_caster)->CanTameExoticPets()))
                            return SPELL_FAILED_BAD_TARGETS;

                        if(m_caster->GetPetGUID())
                            return SPELL_FAILED_ALREADY_HAVE_SUMMON;

                        if(m_caster->GetCharmGUID())
                            return SPELL_FAILED_ALREADY_HAVE_CHARM;

                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case SPELL_AURA_MOD_POSSESS:
            case SPELL_AURA_MOD_CHARM:
            case SPELL_AURA_MOD_POSSESS_PET:
            case SPELL_AURA_AOE_CHARM:
            {
                if(m_caster->GetCharmerGUID())
                    return SPELL_FAILED_CHARMED;

                if(m_spellInfo->EffectApplyAuraName[i] == SPELL_AURA_MOD_CHARM
                    || m_spellInfo->EffectApplyAuraName[i] == SPELL_AURA_MOD_POSSESS)
                {
                    if(m_caster->GetPetGUID())
                        return SPELL_FAILED_ALREADY_HAVE_SUMMON;

                    if(m_caster->GetCharmGUID())
                        return SPELL_FAILED_ALREADY_HAVE_CHARM;
                }

                if(Unit *target = m_targets.getUnitTarget())
                {
                    if(target->GetTypeId() == TYPEID_UNIT && ((Creature*)target)->isVehicle())
                        return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

                    if(target->GetCharmerGUID())
                        return SPELL_FAILED_CHARMED;

                    int32 damage = CalculateDamage(i, target);
                    if(damage && int32(target->getLevel()) > damage)
                        return SPELL_FAILED_HIGHLEVEL;
                }

                break;
            }
            case SPELL_AURA_MOUNTED:
            {
                if (m_caster->IsInWater())
                    return SPELL_FAILED_ONLY_ABOVEWATER;

                if (m_caster->GetTypeId() == TYPEID_PLAYER && ((Player*)m_caster)->GetTransport())
                    return SPELL_FAILED_NO_MOUNTS_ALLOWED;

                // Ignore map check if spell have AreaId. AreaId already checked and this prevent special mount spells
                if (m_caster->GetTypeId() == TYPEID_PLAYER && !sMapStore.LookupEntry(m_caster->GetMapId())->IsMountAllowed() && !m_IsTriggeredSpell && !m_spellInfo->AreaGroupId)
                    return SPELL_FAILED_NO_MOUNTS_ALLOWED;

                ShapeshiftForm form = m_caster->m_form;
                if( form == FORM_CAT          || form == FORM_TREE      || form == FORM_TRAVEL   ||
                    form == FORM_AQUA         || form == FORM_BEAR      || form == FORM_DIREBEAR ||
                    form == FORM_CREATUREBEAR || form == FORM_GHOSTWOLF || form == FORM_FLIGHT   ||
                    form == FORM_FLIGHT_EPIC  || form == FORM_MOONKIN   || form == FORM_METAMORPHOSIS )
                    return SPELL_FAILED_NOT_SHAPESHIFT;

                break;
            }
            case SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS:
            {
                if(!m_targets.getUnitTarget())
                    return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

                // can be casted at non-friendly unit or own pet/charm
                if(m_caster->IsFriendlyTo(m_targets.getUnitTarget()))
                    return SPELL_FAILED_TARGET_FRIENDLY;

                break;
            }
            case SPELL_AURA_MOD_INCREASE_MOUNTED_FLIGHT_SPEED:
            case SPELL_AURA_FLY:
            {
                // not allow cast fly spells at old maps by players (all spells is self target)
                if(m_originalCaster && m_originalCaster->GetTypeId()==TYPEID_PLAYER)
                {
                    if( !((Player*)m_originalCaster)->IsAllowUseFlyMountsHere() )
                        return SPELL_FAILED_NOT_HERE;
                }
                break;
            }
            case SPELL_AURA_PERIODIC_MANA_LEECH:
            {
                if (!m_targets.getUnitTarget())
                    return SPELL_FAILED_BAD_IMPLICIT_TARGETS;

                if (m_caster->GetTypeId() != TYPEID_PLAYER || m_CastItem)
                    break;

                if(m_targets.getUnitTarget()->getPowerType() != POWER_MANA)
                    return SPELL_FAILED_BAD_TARGETS;

                break;
            }
            default:
                break;
        }
    }

    // all ok
    return SPELL_CAST_OK;
}

SpellCastResult Spell::CheckPetCast(Unit* target)
{
    if(!m_caster->isAlive() && !(m_spellInfo->Attributes & SPELL_ATTR_CASTABLE_WHILE_DEAD))
        return SPELL_FAILED_CASTER_DEAD;

    if(m_caster->hasUnitState(UNIT_STAT_CASTING) && !m_IsTriggeredSpell)              //prevent spellcast interruption by another spellcast
        return SPELL_FAILED_SPELL_IN_PROGRESS;
    if(m_caster->isInCombat() && IsNonCombatSpell(m_spellInfo))
        return SPELL_FAILED_AFFECTING_COMBAT;

                                                            //dead owner (pets still alive when owners ressed?)
        if(Unit *owner = m_caster->GetCharmerOrOwner())
            if(!owner->isAlive())
                return SPELL_FAILED_CASTER_DEAD;

        if(!target && m_targets.getUnitTarget())
            target = m_targets.getUnitTarget();

        for(uint32 i = 0; i < 3; ++i)
        {
            if(spellmgr.SpellTargetType[m_spellInfo->EffectImplicitTargetA[i]] == TARGET_TYPE_UNIT_TARGET
                || spellmgr.SpellTargetType[m_spellInfo->EffectImplicitTargetA[i]] == TARGET_TYPE_DEST_TARGET)
            {
                if(!target)
                    return SPELL_FAILED_BAD_IMPLICIT_TARGETS;
                m_targets.setUnitTarget(target);
                break;
            }
        }

        Unit* _target = m_targets.getUnitTarget();

        if(_target)                                         //for target dead/target not valid
        {
            if(!_target->isAlive())
                return SPELL_FAILED_BAD_TARGETS;

            if(!IsValidSingleTargetSpell(_target))
                return SPELL_FAILED_BAD_TARGETS;
        }
                                                            //cooldown
        if(((Creature*)m_caster)->HasSpellCooldown(m_spellInfo->Id))
            return SPELL_FAILED_NOT_READY;

    return CheckCast(true);
}

SpellCastResult Spell::CheckCasterAuras() const
{
    // spells totally immuned to caster auras ( wsg flag drop, give marks etc
    if(m_spellInfo->AttributesEx6& SPELL_ATTR_EX6_IGNORE_CASTER_AURAS)
        return SPELL_CAST_OK;

    uint8 school_immune = 0;
    uint32 mechanic_immune = 0;
    uint32 dispel_immune = 0;

    // Check if the spell grants school or mechanic immunity.
    // We use bitmasks so the loop is done only once and not on every aura check below.
    if ( m_spellInfo->AttributesEx & SPELL_ATTR_EX_DISPEL_AURAS_ON_IMMUNITY )
    {
        for(int i = 0; i < 3; ++i)
        {
            if(m_spellInfo->EffectApplyAuraName[i] == SPELL_AURA_SCHOOL_IMMUNITY)
                school_immune |= uint32(m_spellInfo->EffectMiscValue[i]);
            else if(m_spellInfo->EffectApplyAuraName[i] == SPELL_AURA_MECHANIC_IMMUNITY)
                mechanic_immune |= 1 << uint32(m_spellInfo->EffectMiscValue[i]);
            else if(m_spellInfo->EffectApplyAuraName[i] == SPELL_AURA_DISPEL_IMMUNITY)
                dispel_immune |= GetDispellMask(DispelType(m_spellInfo->EffectMiscValue[i]));
        }
        //immune movement impairment and loss of control
        if(m_spellInfo->Id==42292 || m_spellInfo->Id==59752)
            mechanic_immune = IMMUNE_TO_MOVEMENT_IMPAIRMENT_AND_LOSS_CONTROL_MASK;
    }

    // Check whether the cast should be prevented by any state you might have.
    SpellCastResult prevented_reason = SPELL_CAST_OK;
    // Have to check if there is a stun aura. Otherwise will have problems with ghost aura apply while logging out
    uint32 unitflag = m_caster->GetUInt32Value(UNIT_FIELD_FLAGS);     // Get unit state
    if(unitflag & UNIT_FLAG_STUNNED && !(m_spellInfo->AttributesEx5 & SPELL_ATTR_EX5_USABLE_WHILE_STUNNED))
        prevented_reason = SPELL_FAILED_STUNNED;
    else if(unitflag & UNIT_FLAG_CONFUSED && !(m_spellInfo->AttributesEx5 & SPELL_ATTR_EX5_USABLE_WHILE_CONFUSED))
        prevented_reason = SPELL_FAILED_CONFUSED;
    else if(unitflag & UNIT_FLAG_FLEEING && !(m_spellInfo->AttributesEx5 & SPELL_ATTR_EX5_USABLE_WHILE_FEARED))
        prevented_reason = SPELL_FAILED_FLEEING;
    else if(unitflag & UNIT_FLAG_SILENCED && m_spellInfo->PreventionType == SPELL_PREVENTION_TYPE_SILENCE)
        prevented_reason = SPELL_FAILED_SILENCED;
    else if(unitflag & UNIT_FLAG_PACIFIED && m_spellInfo->PreventionType == SPELL_PREVENTION_TYPE_PACIFY)
        prevented_reason = SPELL_FAILED_PACIFIED;

    // Attr must make flag drop spell totally immune from all effects
    if(prevented_reason != SPELL_CAST_OK)
    {
        if(school_immune || mechanic_immune || dispel_immune)
        {
            //Checking auras is needed now, because you are prevented by some state but the spell grants immunity.
            Unit::AuraMap const& auras = m_caster->GetAuras();
            for(Unit::AuraMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
            {
                if(itr->second)
                {
                    if( GetAllSpellMechanicMask(itr->second->GetSpellProto()) & mechanic_immune )
                        continue;
                    if( GetSpellSchoolMask(itr->second->GetSpellProto()) & school_immune )
                        continue;
                    if( (1<<(itr->second->GetSpellProto()->Dispel)) & dispel_immune)
                        continue;

                    //Make a second check for spell failed so the right SPELL_FAILED message is returned.
                    //That is needed when your casting is prevented by multiple states and you are only immune to some of them.
                    for (uint8 i=0;i<MAX_SPELL_EFFECTS;++i)
                    {
                        if (AuraEffect * part = itr->second->GetPartAura(i))
                        {
                            switch(part->GetAuraName())
                            {
                                case SPELL_AURA_MOD_STUN:
                                    if (!(m_spellInfo->AttributesEx5 & SPELL_ATTR_EX5_USABLE_WHILE_STUNNED))
                                        return SPELL_FAILED_STUNNED;
                                    break;
                                case SPELL_AURA_MOD_CONFUSE:
                                    if (!(m_spellInfo->AttributesEx5 & SPELL_ATTR_EX5_USABLE_WHILE_CONFUSED))
                                        return SPELL_FAILED_CONFUSED;
                                    break;
                                case SPELL_AURA_MOD_FEAR:
                                    if (!(m_spellInfo->AttributesEx5 & SPELL_ATTR_EX5_USABLE_WHILE_FEARED))
                                        return SPELL_FAILED_FLEEING;
                                    break;
                                case SPELL_AURA_MOD_SILENCE:
                                case SPELL_AURA_MOD_PACIFY:
                                case SPELL_AURA_MOD_PACIFY_SILENCE:
                                    if( m_spellInfo->PreventionType==SPELL_PREVENTION_TYPE_PACIFY)
                                        return SPELL_FAILED_PACIFIED;
                                    else if ( m_spellInfo->PreventionType==SPELL_PREVENTION_TYPE_SILENCE)
                                        return SPELL_FAILED_SILENCED;
                                    break;
                            }
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

    for(uint32 j = 0; j < 3; ++j)
    {
        if(m_spellInfo->Effect[j] == SPELL_EFFECT_APPLY_AURA)
        {
            if( m_spellInfo->StackAmount <= 1)
            {
                if( target->HasAuraEffect(m_spellInfo->Id, j) )
                    return false;
            }
            else
            {
                if( AuraEffect * aureff = target->GetAuraEffect(m_spellInfo->Id, j))
                    if (aureff->GetParentAura()->GetStackAmount() >= m_spellInfo->StackAmount)
                        return false;
            }
        }
        else if ( IsAreaAuraEffect( m_spellInfo->Effect[j] ))
        {
            if( target->HasAuraEffect(m_spellInfo->Id, j) )
                return false;
        }
    }

    SpellCastResult result = CheckPetCast(target);

    if(result == SPELL_CAST_OK || result == SPELL_FAILED_UNIT_NOT_INFRONT)
    {
        FillTargetMap();
        //check if among target units, our WANTED target is as well (->only self cast spells return false)
        for(std::list<TargetInfo>::iterator ihit= m_UniqueTargetInfo.begin();ihit != m_UniqueTargetInfo.end();++ihit)
            if( ihit->targetGUID == targetguid )
                return true;
    }
    return false;                                           //target invalid
}

SpellCastResult Spell::CheckRange(bool strict)
{
    //float range_mod;

    // self cast doesn't need range checking -- also for Starshards fix
    if (m_spellInfo->rangeIndex == 1)
        return SPELL_CAST_OK;

    // i do not know why we need this
    /*if (strict)                                             //add radius of caster
        range_mod = 1.25;
    else                                                    //add radius of caster and ~5 yds "give"
        range_mod = 6.25;*/

    SpellRangeEntry const* srange = sSpellRangeStore.LookupEntry(m_spellInfo->rangeIndex);

    Unit *target = m_targets.getUnitTarget();
    float max_range = m_caster->GetSpellMaxRangeForTarget(target, srange); // + range_mod;
    float min_range = m_caster->GetSpellMinRangeForTarget(target, srange);
    uint32 range_type = GetSpellRangeType(srange);

    if(Player* modOwner = m_caster->GetSpellModOwner())
        modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RANGE, max_range, this);

    if(target && target != m_caster)
    {
        if(range_type == SPELL_RANGE_MELEE)
        {
            // Because of lag, we can not check too strictly here.
            if(!m_caster->IsWithinMeleeRange(target, max_range/* - 2*MIN_MELEE_REACH*/))
                return SPELL_FAILED_OUT_OF_RANGE;
        }
        else if(!m_caster->IsWithinCombatRange(target, max_range))
            return SPELL_FAILED_OUT_OF_RANGE;               //0x5A;

        if(range_type == SPELL_RANGE_RANGED)
        {
            if(m_caster->IsWithinMeleeRange(target))
                return SPELL_FAILED_TOO_CLOSE;
        }
        else if(min_range && m_caster->IsWithinCombatRange(target, min_range)) // skip this check if min_range = 0
            return SPELL_FAILED_TOO_CLOSE;

        if( m_caster->GetTypeId() == TYPEID_PLAYER &&
            (m_spellInfo->FacingCasterFlags & SPELL_FACING_FLAG_INFRONT) && !m_caster->HasInArc( M_PI, target ) )
            return SPELL_FAILED_UNIT_NOT_INFRONT;
    }

    if(m_targets.m_targetMask == TARGET_FLAG_DEST_LOCATION && m_targets.m_destX != 0 && m_targets.m_destY != 0 && m_targets.m_destZ != 0)
    {
        if(!m_caster->IsWithinDist3d(m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ, max_range))
            return SPELL_FAILED_OUT_OF_RANGE;
        if(min_range && m_caster->IsWithinDist3d(m_targets.m_destX, m_targets.m_destY, m_targets.m_destZ, min_range))
            return SPELL_FAILED_TOO_CLOSE;
    }

    return SPELL_CAST_OK;
}

SpellCastResult Spell::CheckPower()
{
    // item cast not used power
    if(m_CastItem)
        return SPELL_CAST_OK;

    // health as power used - need check health amount
    if(m_spellInfo->powerType == POWER_HEALTH)
    {
        if(m_caster->GetHealth() <= m_powerCost)
            return SPELL_FAILED_CASTER_AURASTATE;
        return SPELL_CAST_OK;
    }
    // Check valid power type
    if( m_spellInfo->powerType >= MAX_POWERS )
    {
        sLog.outError("Spell::CheckPower: Unknown power type '%d'", m_spellInfo->powerType);
        return SPELL_FAILED_UNKNOWN;
    }

    SpellCastResult failReason = CheckRuneCost(m_spellInfo->runeCostID);
    if(failReason != SPELL_CAST_OK)
        return failReason;

    // Check power amount
    Powers powerType = Powers(m_spellInfo->powerType);
    if(m_caster->GetPower(powerType) < m_powerCost)
        return SPELL_FAILED_NO_POWER;
    else
        return SPELL_CAST_OK;
}

SpellCastResult Spell::CheckItems()
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return SPELL_CAST_OK;

    Player* p_caster = (Player*)m_caster;

    if(!m_CastItem)
    {
        if(m_castItemGUID)
            return SPELL_FAILED_ITEM_NOT_READY;
    }
    else
    {
        uint32 itemid = m_CastItem->GetEntry();
        if( !p_caster->HasItemCount(itemid, 1) )
            return SPELL_FAILED_ITEM_NOT_READY;

        ItemPrototype const *proto = m_CastItem->GetProto();
        if(!proto)
            return SPELL_FAILED_ITEM_NOT_READY;

        for (int i = 0; i < 5; ++i)
            if (proto->Spells[i].SpellCharges)
                if(m_CastItem->GetSpellCharges(i) == 0)
                    return SPELL_FAILED_NO_CHARGES_REMAIN;

        // consumable cast item checks
        if (proto->Class == ITEM_CLASS_CONSUMABLE && m_targets.getUnitTarget())
        {
            // such items should only fail if there is no suitable effect at all - see Rejuvenation Potions for example
            SpellCastResult failReason = SPELL_CAST_OK;
            for (int i = 0; i < 3; i++)
            {
                    // skip check, pet not required like checks, and for TARGET_UNIT_PET m_targets.getUnitTarget() is not the real target but the caster
                    if (m_spellInfo->EffectImplicitTargetA[i] == TARGET_UNIT_PET)
                    continue;

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
                if (m_spellInfo->Effect[i] == SPELL_EFFECT_ENERGIZE)
                {
                    if(m_spellInfo->EffectMiscValue[i] < 0 || m_spellInfo->EffectMiscValue[i] >= MAX_POWERS)
                    {
                        failReason = SPELL_FAILED_ALREADY_AT_FULL_POWER;
                        continue;
                    }

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
    }

    // check target item
    if(m_targets.getItemTargetGUID())
    {
        if(m_caster->GetTypeId() != TYPEID_PLAYER)
            return SPELL_FAILED_BAD_TARGETS;

        if(!m_targets.getItemTarget())
            return SPELL_FAILED_ITEM_GONE;

        if(!m_targets.getItemTarget()->IsFitToSpellRequirements(m_spellInfo))
            return SPELL_FAILED_EQUIPPED_ITEM_CLASS;
    }
    // if not item target then required item must be equipped
    else
    {
        if(m_caster->GetTypeId() == TYPEID_PLAYER && !((Player*)m_caster)->HasItemFitToSpellReqirements(m_spellInfo))
            return SPELL_FAILED_EQUIPPED_ITEM_CLASS;
    }

    // check spell focus object
    if(m_spellInfo->RequiresSpellFocus)
    {
        CellPair p(Trinity::ComputeCellPair(m_caster->GetPositionX(), m_caster->GetPositionY()));
        Cell cell(p);
        cell.data.Part.reserved = ALL_DISTRICT;

        GameObject* ok = NULL;
        MaNGOS::GameObjectFocusCheck go_check(m_caster,m_spellInfo->RequiresSpellFocus);
        MaNGOS::GameObjectSearcher<MaNGOS::GameObjectFocusCheck> checker(m_caster, ok, go_check);

        TypeContainerVisitor<Trinity::GameObjectSearcher<Trinity::GameObjectFocusCheck>, GridTypeMapContainer > object_checker(checker);
        CellLock<GridReadGuard> cell_lock(cell, p);
        cell_lock->Visit(cell_lock, object_checker, *m_caster->GetMap());

        if(!ok)
            return SPELL_FAILED_REQUIRES_SPELL_FOCUS;

        focusObject = ok;                                   // game object found in range
    }

    // do not take reagents for these item casts
    if (!(m_CastItem && m_CastItem->GetProto()->Flags & ITEM_FLAGS_TRIGGERED_CAST))
    {
        // check reagents (ignore triggered spells with reagents processed by original spell) and special reagent ignore case.
        if (!m_IsTriggeredSpell && !p_caster->CanNoReagentCast(m_spellInfo))
        {
            for(uint32 i=0;i<8;i++)
            {
                if(m_spellInfo->Reagent[i] <= 0)
                    continue;

                uint32 itemid    = m_spellInfo->Reagent[i];
                uint32 itemcount = m_spellInfo->ReagentCount[i];

                // if CastItem is also spell reagent
                if( m_CastItem && m_CastItem->GetEntry() == itemid )
                {
                    ItemPrototype const *proto = m_CastItem->GetProto();
                    if(!proto)
                        return SPELL_FAILED_ITEM_NOT_READY;
                    for(int s=0; s < MAX_ITEM_PROTO_SPELLS; ++s)
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
                if( !p_caster->HasItemCount(itemid,itemcount) )
                    return SPELL_FAILED_ITEM_NOT_READY;         //0x54
            }
        }

        // check totem-item requirements (items presence in inventory)
        uint32 totems = 2;
        for(int i = 0; i < 2 ; ++i)
        {
            if(m_spellInfo->Totem[i] != 0)
            {
                if( p_caster->HasItemCount(m_spellInfo->Totem[i],1) )
                {
                    totems -= 1;
                    continue;
                }
            }else
            totems -= 1;
        }
        if(totems != 0)
            return SPELL_FAILED_TOTEMS;                         //0x7C

        // Check items for TotemCategory  (items presence in inventory)
        uint32 TotemCategory = 2;
        for(int i= 0; i < 2; ++i)
        {
            if(m_spellInfo->TotemCategory[i] != 0)
            {
                if( p_caster->HasItemTotemCategory(m_spellInfo->TotemCategory[i]) )
                {
                    TotemCategory -= 1;
                    continue;
                }
            }
            else
                TotemCategory -= 1;
        }
        if(TotemCategory != 0)
            return SPELL_FAILED_TOTEM_CATEGORY;                 //0x7B
    }

    // special checks for spell effects
    for(int i = 0; i < 3; i++)
    {
        switch (m_spellInfo->Effect[i])
        {
            case SPELL_EFFECT_CREATE_ITEM:
            {
                if (!m_IsTriggeredSpell && m_spellInfo->EffectItemType[i])
                {
                    ItemPosCountVec dest;
                    uint8 msg = p_caster->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, m_spellInfo->EffectItemType[i], 1 );
                    if (msg != EQUIP_ERR_OK )
                    {
                        p_caster->SendEquipError( msg, NULL, NULL );
                        return SPELL_FAILED_DONT_REPORT;
                    }
                }
                break;
            }
            case SPELL_EFFECT_ENCHANT_ITEM:
                if(m_spellInfo->EffectItemType[i] && m_targets.getItemTarget() 
                    && (m_targets.getItemTarget()->IsWeaponVellum() || m_targets.getItemTarget()->IsArmorVellum()))
                {
                    // cannot enchant vellum for other player
                    if (m_targets.getItemTarget()->GetOwner()!=m_caster)
                        return SPELL_FAILED_NOT_TRADEABLE;
                    // do not allow to enchant vellum from scroll made by vellum-prevent exploit
                    if (m_CastItem && m_CastItem->GetProto()->Flags & ITEM_FLAGS_TRIGGERED_CAST)
                        return SPELL_FAILED_TOTEM_CATEGORY;
                    ItemPosCountVec dest;
                    uint8 msg = p_caster->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, m_spellInfo->EffectItemType[i], 1 );
                    if (msg != EQUIP_ERR_OK )
                    {
                        p_caster->SendEquipError( msg, NULL, NULL );
                        return SPELL_FAILED_DONT_REPORT;
                    }
                }
            case SPELL_EFFECT_ENCHANT_ITEM_PRISMATIC:
            {
                Item* targetItem = m_targets.getItemTarget();
                if(!targetItem)
                    return SPELL_FAILED_ITEM_NOT_FOUND;

                if( targetItem->GetProto()->ItemLevel < m_spellInfo->baseLevel )
                    return SPELL_FAILED_LOWLEVEL;
                // Not allow enchant in trade slot for some enchant type
                if( targetItem->GetOwner() != m_caster )
                {
                    uint32 enchant_id = m_spellInfo->EffectMiscValue[i];
                    SpellItemEnchantmentEntry const *pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
                    if(!pEnchant)
                        return SPELL_FAILED_ERROR;
                    if (pEnchant->slot & ENCHANTMENT_CAN_SOULBOUND)
                        return SPELL_FAILED_NOT_TRADEABLE;
                }
                break;
            }
            case SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY:
            {
                Item *item = m_targets.getItemTarget();
                if(!item)
                    return SPELL_FAILED_ITEM_NOT_FOUND;
                // Not allow enchant in trade slot for some enchant type
                if( item->GetOwner() != m_caster )
                {
                    uint32 enchant_id = m_spellInfo->EffectMiscValue[i];
                    SpellItemEnchantmentEntry const *pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
                    if(!pEnchant)
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
                if(!m_targets.getItemTarget())
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;

                // prevent disenchanting in trade slot
                if( m_targets.getItemTarget()->GetOwnerGUID() != m_caster->GetGUID() )
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;

                ItemPrototype const* itemProto = m_targets.getItemTarget()->GetProto();
                if(!itemProto)
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;

                uint32 item_quality = itemProto->Quality;
                // 2.0.x addon: Check player enchanting level against the item disenchanting requirements
                uint32 item_disenchantskilllevel = itemProto->RequiredDisenchantSkill;
                if (item_disenchantskilllevel == uint32(-1))
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;
                if (item_disenchantskilllevel > p_caster->GetSkillValue(SKILL_ENCHANTING))
                    return SPELL_FAILED_LOW_CASTLEVEL;
                if(item_quality > 4 || item_quality < 2)
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;
                if(itemProto->Class != ITEM_CLASS_WEAPON && itemProto->Class != ITEM_CLASS_ARMOR)
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;
                if (!itemProto->DisenchantID)
                    return SPELL_FAILED_CANT_BE_DISENCHANTED;
                break;
            }
            case SPELL_EFFECT_PROSPECTING:
            {
                if(!m_targets.getItemTarget())
                    return SPELL_FAILED_CANT_BE_PROSPECTED;
                //ensure item is a prospectable ore
                if(!(m_targets.getItemTarget()->GetProto()->BagFamily & BAG_FAMILY_MASK_MINING_SUPP) || m_targets.getItemTarget()->GetProto()->Class != ITEM_CLASS_TRADE_GOODS)
                    return SPELL_FAILED_CANT_BE_PROSPECTED;
                //prevent prospecting in trade slot
                if( m_targets.getItemTarget()->GetOwnerGUID() != m_caster->GetGUID() )
                    return SPELL_FAILED_CANT_BE_PROSPECTED;
                //Check for enough skill in jewelcrafting
                uint32 item_prospectingskilllevel = m_targets.getItemTarget()->GetProto()->RequiredSkillRank;
                if(item_prospectingskilllevel >p_caster->GetSkillValue(SKILL_JEWELCRAFTING))
                    return SPELL_FAILED_LOW_CASTLEVEL;
                //make sure the player has the required ores in inventory
                if(m_targets.getItemTarget()->GetCount() < 5)
                    return SPELL_FAILED_NEED_MORE_ITEMS;

                if(!LootTemplates_Prospecting.HaveLootFor(m_targets.getItemTargetEntry()))
                    return SPELL_FAILED_CANT_BE_PROSPECTED;

                break;
            }
            case SPELL_EFFECT_MILLING:
            {
                if(!m_targets.getItemTarget())
                    return SPELL_FAILED_CANT_BE_MILLED;
                //ensure item is a millable herb
                if(!(m_targets.getItemTarget()->GetProto()->BagFamily & BAG_FAMILY_MASK_HERBS) || m_targets.getItemTarget()->GetProto()->Class != ITEM_CLASS_TRADE_GOODS)
                    return SPELL_FAILED_CANT_BE_MILLED;
                //prevent milling in trade slot
                if( m_targets.getItemTarget()->GetOwnerGUID() != m_caster->GetGUID() )
                    return SPELL_FAILED_CANT_BE_MILLED;
                //Check for enough skill in inscription
                uint32 item_millingskilllevel = m_targets.getItemTarget()->GetProto()->RequiredSkillRank;
                if(item_millingskilllevel >p_caster->GetSkillValue(SKILL_INSCRIPTION))
                    return SPELL_FAILED_LOW_CASTLEVEL;
                //make sure the player has the required herbs in inventory
                if(m_targets.getItemTarget()->GetCount() < 5)
                    return SPELL_FAILED_NEED_MORE_ITEMS;

                if(!LootTemplates_Milling.HaveLootFor(m_targets.getItemTargetEntry()))
                    return SPELL_FAILED_CANT_BE_MILLED;

                break;
            }
            case SPELL_EFFECT_WEAPON_DAMAGE:
            case SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL:
            {
                if(m_caster->GetTypeId() != TYPEID_PLAYER) return SPELL_FAILED_TARGET_NOT_PLAYER;
                if( m_attackType != RANGED_ATTACK )
                    break;
                Item *pItem = ((Player*)m_caster)->GetWeaponForAttack(m_attackType);
                if(!pItem || pItem->IsBroken())
                    return SPELL_FAILED_EQUIPPED_ITEM;

                switch(pItem->GetProto()->SubClass)
                {
                    case ITEM_SUBCLASS_WEAPON_THROWN:
                    {
                        uint32 ammo = pItem->GetEntry();
                        if( !((Player*)m_caster)->HasItemCount( ammo, 1 ) )
                            return SPELL_FAILED_NO_AMMO;
                    };  break;
                    case ITEM_SUBCLASS_WEAPON_GUN:
                    case ITEM_SUBCLASS_WEAPON_BOW:
                    case ITEM_SUBCLASS_WEAPON_CROSSBOW:
                    {
                        uint32 ammo = ((Player*)m_caster)->GetUInt32Value(PLAYER_AMMO_ID);
                        if(!ammo)
                        {
                            // Requires No Ammo
                            if(m_caster->GetDummyAura(46699))
                                break;                      // skip other checks

                            return SPELL_FAILED_NO_AMMO;
                        }

                        ItemPrototype const *ammoProto = objmgr.GetItemPrototype( ammo );
                        if(!ammoProto)
                            return SPELL_FAILED_NO_AMMO;

                        if(ammoProto->Class != ITEM_CLASS_PROJECTILE)
                            return SPELL_FAILED_NO_AMMO;

                        // check ammo ws. weapon compatibility
                        switch(pItem->GetProto()->SubClass)
                        {
                            case ITEM_SUBCLASS_WEAPON_BOW:
                            case ITEM_SUBCLASS_WEAPON_CROSSBOW:
                                if(ammoProto->SubClass != ITEM_SUBCLASS_ARROW)
                                    return SPELL_FAILED_NO_AMMO;
                                break;
                            case ITEM_SUBCLASS_WEAPON_GUN:
                                if(ammoProto->SubClass != ITEM_SUBCLASS_BULLET)
                                    return SPELL_FAILED_NO_AMMO;
                                break;
                            default:
                                return SPELL_FAILED_NO_AMMO;
                        }

                        if( !((Player*)m_caster)->HasItemCount( ammo, 1 ) )
                            return SPELL_FAILED_NO_AMMO;
                    };  break;
                    case ITEM_SUBCLASS_WEAPON_WAND:
                        break;
                    default:
                        break;
                }
                break;
            }
            default:break;
        }
    }

    // check weapon presence in slots for main/offhand weapons
    if(m_spellInfo->EquippedItemClass >=0)
    {
        // main hand weapon required
        if(m_spellInfo->AttributesEx3 & SPELL_ATTR_EX3_MAIN_HAND)
        {
            Item* item = ((Player*)m_caster)->GetWeaponForAttack(BASE_ATTACK);

            // skip spell if no weapon in slot or broken
            if(!item || item->IsBroken() )
                return m_IsTriggeredSpell? SPELL_FAILED_DONT_REPORT : SPELL_FAILED_EQUIPPED_ITEM_CLASS;

            // skip spell if weapon not fit to triggered spell
            if(!item->IsFitToSpellRequirements(m_spellInfo))
                return m_IsTriggeredSpell? SPELL_FAILED_DONT_REPORT : SPELL_FAILED_EQUIPPED_ITEM_CLASS;
        }

        // offhand hand weapon required
        if(m_spellInfo->AttributesEx3 & SPELL_ATTR_EX3_REQ_OFFHAND)
        {
            Item* item = ((Player*)m_caster)->GetWeaponForAttack(OFF_ATTACK);

            // skip spell if no weapon in slot or broken
            if(!item || item->IsBroken() )
                return m_IsTriggeredSpell? SPELL_FAILED_DONT_REPORT : SPELL_FAILED_EQUIPPED_ITEM_CLASS;

            // skip spell if weapon not fit to triggered spell
            if(!item->IsFitToSpellRequirements(m_spellInfo))
                return m_IsTriggeredSpell? SPELL_FAILED_DONT_REPORT : SPELL_FAILED_EQUIPPED_ITEM_CLASS;
        }
    }

    return SPELL_CAST_OK;
}

void Spell::Delayed() // only called in DealDamage()
{
    if(!m_caster)// || m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    //if (m_spellState == SPELL_STATE_DELAYED)
    //    return;                                             // spell is active and can't be time-backed

    if(isDelayableNoMore())                                 // Spells may only be delayed twice
        return;

    // spells not loosing casting time ( slam, dynamites, bombs.. )
    //if(!(m_spellInfo->InterruptFlags & SPELL_INTERRUPT_FLAG_DAMAGE))
    //    return;

    //check pushback reduce
    int32 delaytime = 500;                                  // spellcasting delay is normally 500ms
    int32 delayReduce = 100;                                // must be initialized to 100 for percent modifiers
    ((Player*)m_caster)->ApplySpellMod(m_spellInfo->Id, SPELLMOD_NOT_LOSE_CASTING_TIME, delayReduce, this);
    delayReduce += m_caster->GetTotalAuraModifier(SPELL_AURA_REDUCE_PUSHBACK) - 100;
    if(delayReduce >= 100)
        return;

    delaytime = delaytime * (100 - delayReduce) / 100;

    if(int32(m_timer) + delaytime > m_casttime)
    {
        delaytime = m_casttime - m_timer;
        m_timer = m_casttime;
    }
    else
        m_timer += delaytime;

    sLog.outDetail("Spell %u partially interrupted for (%d) ms at damage", m_spellInfo->Id, delaytime);

    WorldPacket data(SMSG_SPELL_DELAYED, 8+4);
    data.append(m_caster->GetPackGUID());
    data << uint32(delaytime);

    m_caster->SendMessageToSet(&data, true);
}

void Spell::DelayedChannel()
{
    if(!m_caster || m_caster->GetTypeId() != TYPEID_PLAYER || getState() != SPELL_STATE_CASTING)
        return;

    if(isDelayableNoMore())                                 // Spells may only be delayed twice
        return;

    //check pushback reduce
    int32 delaytime = GetSpellDuration(m_spellInfo) * 25 / 100; // channeling delay is normally 25% of its time per hit
    int32 delayReduce = 100;                               // must be initialized to 100 for percent modifiers
    ((Player*)m_caster)->ApplySpellMod(m_spellInfo->Id, SPELLMOD_NOT_LOSE_CASTING_TIME, delayReduce, this);
    delayReduce += m_caster->GetTotalAuraModifier(SPELL_AURA_REDUCE_PUSHBACK) - 100;
    if(delayReduce >= 100)
        return;

    delaytime = delaytime * (100 - delayReduce) / 100;

    if(int32(m_timer) < delaytime)
    {
        delaytime = m_timer;
        m_timer = 0;
    }
    else
        m_timer -= delaytime;

    sLog.outDebug("Spell %u partially interrupted for %i ms, new duration: %u ms", m_spellInfo->Id, delaytime, m_timer);

    for(std::list<TargetInfo>::const_iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
    {
        if ((*ihit).missCondition == SPELL_MISS_NONE)
        {
            Unit* unit = m_caster->GetGUID() == ihit->targetGUID ? m_caster : ObjectAccessor::GetUnit(*m_caster, ihit->targetGUID);
            if (unit)
            {
                unit->DelayAura(m_spellInfo->Id, m_caster->GetGUID(), delaytime);
            }
        }
    }

    for(int j = 0; j < 3; ++j)
    {
        // partially interrupt persistent area auras
        DynamicObject* dynObj = m_caster->GetDynObject(m_spellInfo->Id, j);
        if(dynObj)
            dynObj->Delay(delaytime);
    }

    SendChannelUpdate(m_timer);
}

void Spell::UpdatePointers()
{
    if(m_originalCasterGUID==m_caster->GetGUID())
        m_originalCaster = m_caster;
    else
    {
        m_originalCaster = ObjectAccessor::GetUnit(*m_caster,m_originalCasterGUID);
        if(m_originalCaster && !m_originalCaster->IsInWorld()) m_originalCaster = NULL;
    }

    if(m_castItemGUID && m_caster->GetTypeId() == TYPEID_PLAYER)
        m_CastItem = ((Player*)m_caster)->GetItemByGuid(m_castItemGUID);

    m_targets.Update(m_caster);
}

bool Spell::CheckTargetCreatureType(Unit* target) const
{
    uint32 spellCreatureTargetMask = m_spellInfo->TargetCreatureType;

    // Curse of Doom or Exorcism
    // These spells cannot be cast on players, however there is no clientside check for them
    // so there is no attribute flag in dbcs which would mark these spells - we need to check them by spellfamily
    if(m_spellInfo->SpellFamilyName==SPELLFAMILY_WARLOCK && m_spellInfo->SpellFamilyFlags.IsEqual(0,0x02,0)
        || m_spellInfo->SpellFamilyName==SPELLFAMILY_PALADIN && m_spellInfo->SpellFamilyFlags.IsEqual(0,0x2,0))
    {
        // not allow cast at player
        if(target->GetTypeId()==TYPEID_PLAYER)
            return false;

        spellCreatureTargetMask = 0x7FF;
    }

    // Dismiss Pet and Taming Lesson skipped
    if(m_spellInfo->Id == 2641 || m_spellInfo->Id == 23356)
        spellCreatureTargetMask =  0;

    if (spellCreatureTargetMask)
    {
        uint32 TargetCreatureType = target->GetCreatureTypeMask();

        return !TargetCreatureType || (spellCreatureTargetMask & TargetCreatureType);
    }
    return true;
}

CurrentSpellTypes Spell::GetCurrentContainer()
{
    if (IsNextMeleeSwingSpell())
        return(CURRENT_MELEE_SPELL);
    else if (IsAutoRepeat())
        return(CURRENT_AUTOREPEAT_SPELL);
    else if (IsChanneledSpell(m_spellInfo))
        return(CURRENT_CHANNELED_SPELL);
    else
        return(CURRENT_GENERIC_SPELL);
}

bool Spell::CheckTarget(Unit* target, uint32 eff)
{
    // Check targets for creature type mask and remove not appropriate (skip explicit self target case, maybe need other explicit targets)
    if(m_spellInfo->EffectImplicitTargetA[eff] != TARGET_UNIT_CASTER)
    {
        if (!CheckTargetCreatureType(target))
            return false;
    }

    // Check Aura spell req (need for AoE spells)
    if(m_spellInfo->targetAuraSpell && !target->HasAura(m_spellInfo->targetAuraSpell))
        return false;
    if (m_spellInfo->excludeTargetAuraSpell && target->HasAura(m_spellInfo->excludeTargetAuraSpell))
        return false;

    // Check targets for not_selectable unit flag and remove
    // A player can cast spells on his pet (or other controlled unit) though in any state
    if (target != m_caster && target->GetCharmerOrOwnerGUID() != m_caster->GetGUID())
    {
        // any unattackable target skipped
        if (target->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            return false;

        // unselectable targets skipped in all cases except TARGET_UNIT_NEARBY_ENTRY targeting
        // in case TARGET_UNIT_NEARBY_ENTRY target selected by server always and can't be cheated
        /*if( target->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE) &&
            m_spellInfo->EffectImplicitTargetA[eff] != TARGET_UNIT_NEARBY_ENTRY &&
            m_spellInfo->EffectImplicitTargetB[eff] != TARGET_UNIT_NEARBY_ENTRY )
            return false;*/
    }

    //Check player targets and remove if in GM mode or GM invisibility (for not self casting case)
    if( target != m_caster && target->GetTypeId() == TYPEID_PLAYER)
    {
        if(((Player*)target)->GetVisibility() == VISIBILITY_OFF)
            return false;

        if(((Player*)target)->isGameMaster() && !IsPositiveSpell(m_spellInfo->Id))
            return false;
    }

    switch(m_spellInfo->EffectApplyAuraName[eff])
    {
        case SPELL_AURA_NONE:
        default:
            break;
        case SPELL_AURA_MOD_POSSESS:
        case SPELL_AURA_MOD_CHARM:
        case SPELL_AURA_MOD_POSSESS_PET:
        case SPELL_AURA_AOE_CHARM:
            if(target->GetTypeId() == TYPEID_UNIT && ((Creature*)target)->isVehicle())
                return false;
            if(target->GetCharmerGUID())
                return false;
            if(int32 damage = CalculateDamage(eff, target))
                if((int32)target->getLevel() > damage)
                    return false;
            break;
    }

    //Do not do further checks for triggered spells
    if(m_IsTriggeredSpell)
        return true;

    //Check targets for LOS visibility (except spells without range limitations )
    switch(m_spellInfo->Effect[eff])
    {
        case SPELL_EFFECT_SUMMON_PLAYER:                    // from anywhere
            break;
        case SPELL_EFFECT_DUMMY:
            if(m_spellInfo->Id != 20577)                    // Cannibalize
                break;
            //fall through
        case SPELL_EFFECT_RESURRECT_NEW:
            // player far away, maybe his corpse near?
            if(target != m_caster && !target->IsWithinLOSInMap(m_caster))
            {
                if(!m_targets.getCorpseTargetGUID())
                    return false;

                Corpse *corpse = ObjectAccessor::GetCorpse(*m_caster, m_targets.getCorpseTargetGUID());
                if(!corpse)
                    return false;

                if(target->GetGUID() != corpse->GetOwnerGUID())
                    return false;

                if(!corpse->IsWithinLOSInMap(m_caster))
                    return false;
            }

            // all ok by some way or another, skip normal check
            break;
        default:                                            // normal case
            // Get GO cast coordinates if original caster -> GO
            WorldObject *caster = NULL;
            if (IS_GAMEOBJECT_GUID(m_originalCasterGUID))
                caster = m_caster->GetMap()->GetGameObject(m_originalCasterGUID);
            if (!caster)
                caster = m_caster;
            if(target != m_caster && !target->IsWithinLOSInMap(caster))
                return false;
            break;
    }

    return true;
}

bool Spell::IsNeedSendToClient() const
{
    return m_spellInfo->SpellVisual[0] || m_spellInfo->SpellVisual[1] || IsChanneledSpell(m_spellInfo) ||
        m_spellInfo->speed > 0.0f || !m_triggeredByAuraSpell && !m_IsTriggeredSpell;
}

bool Spell::HaveTargetsForEffect( uint8 effect ) const
{
    for(std::list<TargetInfo>::const_iterator itr = m_UniqueTargetInfo.begin(); itr != m_UniqueTargetInfo.end(); ++itr)
        if(itr->effectMask & (1 << effect))
            return true;

    for(std::list<GOTargetInfo>::const_iterator itr = m_UniqueGOTargetInfo.begin(); itr != m_UniqueGOTargetInfo.end(); ++itr)
        if(itr->effectMask & (1 << effect))
            return true;

    for(std::list<ItemTargetInfo>::const_iterator itr = m_UniqueItemInfo.begin(); itr != m_UniqueItemInfo.end(); ++itr)
        if(itr->effectMask & (1 << effect))
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
        sLog.outError("~SpellEvent: %s %u tried to delete non-deletable spell %u. Was not deleted, causes memory leak.",
            (m_Spell->GetCaster()->GetTypeId() == TYPEID_PLAYER ? "Player" : "Creature"), m_Spell->GetCaster()->GetGUIDLow(), m_Spell->m_spellInfo->Id);
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

bool Spell::IsValidSingleTargetEffect(Unit const* target, Targets type) const
{
    switch(type)
    {
        case TARGET_UNIT_TARGET_ENEMY:
            return !m_caster->IsFriendlyTo(target);
        case TARGET_UNIT_TARGET_ALLY:
        case TARGET_UNIT_PARTY_TARGET:
            return m_caster->IsFriendlyTo(target);
        case TARGET_UNIT_TARGET_PARTY:
            return m_caster != target && m_caster->IsInPartyWith(target);
        case TARGET_UNIT_TARGET_RAID:
            return m_caster->IsInRaidWith(target);
    }
    return true;
}

bool Spell::IsValidSingleTargetSpell(Unit const* target) const
{
    for(int i = 0; i < 3; ++i)
    {
        if(!IsValidSingleTargetEffect(target, Targets(m_spellInfo->EffectImplicitTargetA[i])))
            return false;
        // Need to check B?
        //if(!IsValidSingleTargetEffect(m_spellInfo->EffectImplicitTargetB[i], target)
        //    return false;
    }
    return true;
}

void Spell::CalculateDamageDoneForAllTargets()
{
    float multiplier[3];
    for(int i = 0; i < 3; ++i)
    {
        if ( m_applyMultiplierMask & (1 << i) )
        {
            // Get multiplier
            multiplier[i] = m_spellInfo->DmgMultiplier[i];
            // Apply multiplier mods
            if(m_originalCaster)
                if(Player* modOwner = m_originalCaster->GetSpellModOwner())
                    modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_EFFECT_PAST_FIRST, multiplier[i], this);
        }
    }

    bool usesAmmo=true;
    Unit::AuraEffectList const& Auras = m_caster->GetAurasByType(SPELL_AURA_ABILITY_CONSUME_NO_AMMO);
    for(Unit::AuraEffectList::const_iterator j = Auras.begin();j != Auras.end(); ++j)
    {
        if((*j)->isAffectedOnSpell(m_spellInfo))
            usesAmmo=false;
    }

    for(std::list<TargetInfo>::iterator ihit= m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
    {
        TargetInfo &target = *ihit;

        uint32 mask = target.effectMask;
        if(!mask)
            continue;

        Unit* unit = m_caster->GetGUID()==target.targetGUID ? m_caster : ObjectAccessor::GetUnit(*m_caster, target.targetGUID);
        if (!unit) // || !unit->isAlive()) do we need to check alive here?
            continue;

        if (usesAmmo)
        {
            bool ammoTaken=false;
            for (uint8 i=0;i<3;i++)
            {
                if (!(mask & 1<<i))
                    continue;
                switch (m_spellInfo->Effect[i])
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

        if (target.missCondition==SPELL_MISS_NONE)                          // In case spell hit target, do all effect on that target
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

int32 Spell::CalculateDamageDone(Unit *unit, const uint32 effectMask, float *multiplier)
{
    int32 damageDone = 0;
    unitTarget = unit;
    for(uint32 i = 0; i < 3; ++i)
    {
        if (effectMask & (1<<i))
        {
            m_damage = 0;
            damage = CalculateDamage(i, NULL);

            switch(m_spellInfo->Effect[i])
            {
                case SPELL_EFFECT_SCHOOL_DAMAGE:
                    SpellDamageSchoolDmg(i);
                    break;
                case SPELL_EFFECT_WEAPON_DAMAGE:
                case SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL:
                case SPELL_EFFECT_NORMALIZED_WEAPON_DMG:
                case SPELL_EFFECT_WEAPON_PERCENT_DAMAGE:
                    SpellDamageWeaponDmg(i);
                    break;
                case SPELL_EFFECT_HEAL:
                    SpellDamageHeal(i);
                    break;
            }

            if(m_damage > 0)
            {
                if(IsAreaEffectTarget[m_spellInfo->EffectImplicitTargetA[i]] || IsAreaEffectTarget[m_spellInfo->EffectImplicitTargetB[i]])
                {
                    if(int32 reducedPct = unit->GetMaxNegativeAuraModifier(SPELL_AURA_MOD_AOE_DAMAGE_AVOIDANCE))
                        m_damage = m_damage * (100 + reducedPct) / 100;
                }
            }
            if(m_applyMultiplierMask & (1 << i))
            {
                m_damage *= m_damageMultipliers[i];
                m_damageMultipliers[i] *= multiplier[i];
            }

            damageDone += m_damage;
        }
    }

    return damageDone;
}

SpellCastResult Spell::CanOpenLock(uint32 effIndex, uint32 lockId, SkillType& skillId, int32& reqSkillValue, int32& skillValue)
{
    if(!lockId)                                             // possible case for GO and maybe for items.
        return SPELL_CAST_OK;

    // Get LockInfo
    LockEntry const *lockInfo = sLockStore.LookupEntry(lockId);

    if (!lockInfo)
        return SPELL_FAILED_BAD_TARGETS;

    bool reqKey = false;                                    // some locks not have reqs

    for(int j = 0; j < 8; ++j)
    {
        switch(lockInfo->Type[j])
        {
            // check key item (many fit cases can be)
            case LOCK_KEY_ITEM:
                if(lockInfo->Index[j] && m_CastItem && m_CastItem->GetEntry()==lockInfo->Index[j])
                    return SPELL_CAST_OK;
                reqKey = true;
                break;
                // check key skill (only single first fit case can be)
            case LOCK_KEY_SKILL:
            {
                reqKey = true;

                // wrong locktype, skip
                if(uint32(m_spellInfo->EffectMiscValue[effIndex]) != lockInfo->Index[j])
                    continue;

                skillId = SkillByLockType(LockType(lockInfo->Index[j]));

                if ( skillId != SKILL_NONE )
                {
                    // skill bonus provided by casting spell (mostly item spells)
                    // add the damage modifier from the spell casted (cheat lock / skeleton key etc.) (use m_currentBasePoints, CalculateDamage returns wrong value)
                    uint32 spellSkillBonus = uint32(m_currentBasePoints[effIndex]+1);
                    reqSkillValue = lockInfo->Skill[j];

                    // castitem check: rogue using skeleton keys. the skill values should not be added in this case.
                    skillValue = m_CastItem || m_caster->GetTypeId()!= TYPEID_PLAYER ?
                        0 : ((Player*)m_caster)->GetSkillValue(skillId);

                    skillValue += spellSkillBonus;

                    if (skillValue < reqSkillValue)
                        return SPELL_FAILED_LOW_CASTLEVEL;
                }

                return SPELL_CAST_OK;
            }
        }
    }

    if(reqKey)
        return SPELL_FAILED_BAD_TARGETS;

    return SPELL_CAST_OK;
}

void Spell::SetSpellValue(SpellValueMod mod, int32 value)
{
    switch(mod)
    {
        case SPELLVALUE_BASE_POINT0:
            m_spellValue->EffectBasePoints[0] = value - int32(m_spellInfo->EffectBaseDice[0]);
            m_currentBasePoints[0] = m_spellValue->EffectBasePoints[0]; //this should be removed in the future
            break;
        case SPELLVALUE_BASE_POINT1:
            m_spellValue->EffectBasePoints[1] = value - int32(m_spellInfo->EffectBaseDice[1]);
            m_currentBasePoints[1] = m_spellValue->EffectBasePoints[1];
            break;
        case SPELLVALUE_BASE_POINT2:
            m_spellValue->EffectBasePoints[2] = value - int32(m_spellInfo->EffectBaseDice[2]);
            m_currentBasePoints[2] = m_spellValue->EffectBasePoints[2];
            break;
        case SPELLVALUE_RADIUS_MOD:
            m_spellValue->RadiusMod = (float)value / 10000;
            break;
        case SPELLVALUE_MAX_TARGETS:
            m_spellValue->MaxAffectedTargets = (uint32)value;
            break;
    }
}

void Spell::FillRaidOrPartyTargets( UnitList &TagUnitMap, Unit* target, float radius, bool raid, bool withPets, bool withcaster )
{
    Player *pTarget = target->GetCharmerOrOwnerPlayerOrPlayerItself();
    Group *pGroup = pTarget ? pTarget->GetGroup() : NULL;

    if (pGroup)
    {
        uint8 subgroup = pTarget->GetSubGroup();

        for(GroupReference *itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            Player* Target = itr->getSource();

            // IsHostileTo check duel and controlled by enemy
            if (Target && (raid || subgroup==Target->GetSubGroup())
                && !m_caster->IsHostileTo(Target))
            {
                if (Target==m_caster && withcaster ||
                    Target!=m_caster && m_caster->IsWithinDistInMap(Target, radius))
                    TagUnitMap.push_back(Target);

                if (withPets)
                    if (Pet* pet = Target->GetPet())
                        if (pet==m_caster && withcaster ||
                            pet!=m_caster && m_caster->IsWithinDistInMap(pet, radius))
                            TagUnitMap.push_back(pet);
            }
        }
    }
    else
    {
        Unit* ownerOrSelf = pTarget ? pTarget : target->GetCharmerOrOwnerOrSelf();
        if (ownerOrSelf==m_caster && withcaster ||
            ownerOrSelf!=m_caster && m_caster->IsWithinDistInMap(ownerOrSelf, radius))
            TagUnitMap.push_back(ownerOrSelf);

        if (withPets)
            if (Guardian* pet = ownerOrSelf->GetGuardianPet())
                if (pet==m_caster && withcaster ||
                    pet!=m_caster && m_caster->IsWithinDistInMap(pet, radius))
                    TagUnitMap.push_back(pet);
    }
}

void Spell::FillRaidOrPartyManaPriorityTargets( UnitList &TagUnitMap, Unit* target, float radius, uint32 count, bool raid, bool withPets, bool withCaster )
{
    FillRaidOrPartyTargets(TagUnitMap,target,radius,raid,withPets,withCaster);

    PrioritizeManaUnitQueue manaUsers;
    for(UnitList::const_iterator itr = TagUnitMap.begin(); itr != TagUnitMap.end() && manaUsers.size() < count; ++itr)
        if ((*itr)->getPowerType() == POWER_MANA && !(*itr)->isDead())
            manaUsers.push(PrioritizeManaUnitWraper(*itr));

    TagUnitMap.clear();
    while(!manaUsers.empty())
    {
        TagUnitMap.push_back(manaUsers.top().getUnit());
        manaUsers.pop();
    }
}

void Spell::FillRaidOrPartyHealthPriorityTargets( UnitList &TagUnitMap, Unit* target, float radius, uint32 count, bool raid, bool withPets, bool withCaster )
{
    FillRaidOrPartyTargets(TagUnitMap,target,radius,raid,withPets,withCaster);

    PrioritizeHealthUnitQueue healthQueue;
    for(UnitList::const_iterator itr = TagUnitMap.begin(); itr != TagUnitMap.end() && healthQueue.size() < count; ++itr)
        if (!(*itr)->isDead())
            healthQueue.push(PrioritizeHealthUnitWraper(*itr));

    TagUnitMap.clear();
    while(!healthQueue.empty())
    {
        TagUnitMap.push_back(healthQueue.top().getUnit());
        healthQueue.pop();
    }
}

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

#include "CreatureAI.h"
#include "Spell.h"
#include "Creature.h"
#include "CreatureAIImpl.h"
#include "CreatureTextMgr.h"
#include "DB2Structure.h"
#include "Errors.h"
#include "Language.h"
#include "Log.h"
#include "Map.h"
#include "MapReference.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "SmartEnum.h"
#include "SpellHistory.h"
#include "TemporarySummon.h"
#include "Vehicle.h"
#include <queue>
#include "DBCStores.h"
#include "Totem.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "Group.h"

std::unordered_map<std::pair<uint32, Difficulty>, AISpellInfoType> UnitAI::AISpellInfo;
AISpellInfoType* GetAISpellInfo(uint32 spellId, Difficulty difficulty)
CreatureAI::CreatureAI(Creature* creature) : m_creature(creature), m_bUseAiAtControl(false), m_bMeleeAttack(true), m_bCombatMovement(true), m_uiCastingDelay(0), m_uLastAlertTime(0)
{
    SetSpellsList(creature->GetCreatureInfo()->spell_list_id);
}

CreatureAI::~CreatureAI()
{
}

CreatureAI::CreatureAI(Creature* creature, uint32 scriptId)
    : UnitAI(creature), me(creature), _boundary(nullptr),
      _negateBoundary(false), _scriptId(scriptId ? scriptId : creature->GetScriptId()), _isEngaged(false), _moveInLOSLocked(false)
void CreatureAI::JustRespawned()
{
    ASSERT(_scriptId, "A CreatureAI was initialized with an invalid scriptId!");
    // Reset spells template to default on respawn.
    SetSpellsList(m_creature->GetCreatureInfo()->spell_list_id);

    // Reset combat movement and melee attack.
    m_bCombatMovement = true;
    m_bMeleeAttack = true;
}

void CreatureAI::AttackedBy(Unit* attacker)
{
    if (!m_creature->GetVictim())
        AttackStart(attacker);
}

CanCastResult CreatureAI::CanCastSpell(Unit* pTarget, SpellEntry const* pSpell, bool isTriggered)
{
    if (!pTarget)
        return CAST_FAIL_OTHER;
    // If not triggered, we check
    if (!isTriggered)
    {
        // State does not allow
        if (m_creature->HasUnitState(UNIT_STAT_CAN_NOT_REACT_OR_LOST_CONTROL))
            return CAST_FAIL_STATE;

        if (pSpell->PreventionType == SPELL_PREVENTION_TYPE_SILENCE && (m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SILENCED) || m_creature->CheckLockout(pSpell->GetSpellSchoolMask())))
            return CAST_FAIL_STATE;

        if (pSpell->PreventionType == SPELL_PREVENTION_TYPE_PACIFY && m_creature->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED))
            return CAST_FAIL_STATE;

        // Check for power (also done by Spell::CheckCast())
        if (m_creature->GetPower((Powers)pSpell->powerType) < Spell::CalculatePowerCost(pSpell, m_creature))
            return CAST_FAIL_POWER;
    }

//void CreatureAI::DoZoneInCombat(Creature* creature /*= nullptr*/, float maxRangeToNearestTarget /* = 250.0f*/)
//{
//    if (!creature)
//        creature = me;
//
//    Map* map = creature->GetMap();
//    if (creature->CanHaveThreatList())                      //use IsDungeon instead of Instanceable, in case battlegrounds will be instantiated
//    {
//        if (!map->IsDungeon())                                  //use IsDungeon instead of Instanceable, in case battlegrounds will be instantiated
//        {
//            TC_LOG_ERROR("misc", "DoZoneInCombat call for map that isn't an instance (creature entry = %d)", creature->GetTypeId() == TYPEID_UNIT ? creature->ToCreature()->GetEntry() : 0);
//            return;
//        }
//
//        if (!creature->HasReactState(REACT_PASSIVE) && !creature->GetVictim())
//        {
//            if (Unit* nearTarget = creature->SelectNearestTarget(maxRangeToNearestTarget))
//                creature->AI()->AttackStart(nearTarget);
//            else if (creature->IsSummon())
//            {
//                //if (Unit* summoner = creature->ToTempSummon()->GetSummoner())
//                //{
//                //    Unit* target = summoner->getAttackerForHelper();
//                //    if (!target && !summoner->GetThreatManager().IsThreatListEmpty())
//                //        target = summoner->GetThreatManager().GetAnyTarget();
//                //    if (target && (creature->IsFriendlyTo(summoner) || creature->IsHostileTo(target)))
//                //        creature->AI()->AttackStart(target);
//                //}//tmp
//            }
//        }
//        // Intended duplicated check, the code above this should select a victim
//            // If it can't find a suitable attack target then we should error out.
//        if (!creature->HasReactState(REACT_PASSIVE) && !creature->GetVictim())
//        {
//            TC_LOG_ERROR("misc.dozoneincombat", "DoZoneInCombat called for creature that has empty threat list (creature entry = %u)", creature->GetEntry());
//            return;
//        }
//    }
//
//    Map::PlayerList const& playerList = map->GetPlayers();
//    if (playerList.isEmpty())
//        return;
//
//    for (Map::PlayerList::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
//        if (Player* player = itr->GetSource())
//            if (player->IsAlive())
//                creature->SetInCombatWith(player);
//}
    if (pSpell->Custom & SPELL_CUSTOM_BEHIND_TARGET && pTarget->HasInArc(m_creature))
        return CAST_FAIL_OTHER;

    // If the spell requires the target having a specific power type
    if (!pSpell->IsAreaOfEffectSpell() && !pSpell->IsTargetPowerTypeValid(pTarget->GetPowerType()))
        return CAST_FAIL_OTHER;

// Disable CreatureAI when charmed
void CreatureAI::OnCharmed(bool isNew)
{
    if (isNew && !me->IsCharmed() && !me->LastCharmerGUID.IsEmpty())
    // Mind control abilities can't be used with just 1 attacker or mob will reset.
    if ((m_creature->GetThreatManager().getThreatList().size() == 1) && pSpell->IsCharmSpell())
        return CAST_FAIL_OTHER;

    // If the unit is disarmed and the skill requires a weapon, it cannot be cast
    if (m_creature->HasWeapon() && !m_creature->CanUseEquippedWeapon(BASE_ATTACK))
    {
        for (uint32 effect : pSpell->Effect)
        {
            if (effect == SPELL_EFFECT_WEAPON_DAMAGE || effect == SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL)
                return CAST_FAIL_OTHER;
        }
    }

    if (pSpell->rangeIndex == SPELL_RANGE_IDX_SELF_ONLY)
        return CAST_OK;

    if (!(pSpell->AttributesEx2 & SPELL_ATTR_EX2_IGNORE_LOS) && !m_creature->IsWithinLOSInMap(pTarget))
        return CAST_FAIL_NOT_IN_LOS;

    if (SpellRangeEntry const* pSpellRange = sSpellRangeStore.LookupEntry(pSpell->rangeIndex))
    {
        if (!me->HasReactState(REACT_PASSIVE))
        if (pTarget != m_creature)
        {
            if (Unit* lastCharmer = ObjectAccessor::GetUnit(*me, me->LastCharmerGUID))
                me->EngageWithTarget(lastCharmer);
        }

        me->LastCharmerGUID.Clear();

        if (!me->IsInCombat())
            EnterEvadeMode(EvadeReason::NoHostiles);
    }

    UnitAI::OnCharmed(isNew);
}
            // pTarget is out of range of this spell (also done by Spell::CheckCast())
            float fDistance = m_creature->GetCombatDistance(pTarget);

            if (fDistance > pSpellRange->maxRange)
                return CAST_FAIL_TOO_FAR;

            float fMinRange = pSpellRange->minRange;

            if (fMinRange && fDistance < fMinRange)
                return CAST_FAIL_TOO_CLOSE;
        }

        return CAST_OK;
    }
    else
        return CAST_FAIL_OTHER;
}

void CreatureAI::DoZoneInCombat(Creature* creature /*= nullptr*/)
{
    if (!creature)
        creature = me;

    Map* map = creature->GetMap();
    if (!map->IsDungeon()) // use IsDungeon instead of Instanceable, in case battlegrounds will be instantiated
    {
        TC_LOG_ERROR("scripts.ai", "CreatureAI::DoZoneInCombat: call for map that isn't an instance ({})", creature->GetGUID().ToString());
        return;
    }
CanCastResult CreatureAI::DoCastSpellIfCan(Unit* pTarget, uint32 uiSpell, uint32 uiCastFlags, ObjectGuid uiOriginalCasterGUID)
{
    if (!pTarget)
        return CAST_FAIL_OTHER;

    if (!map->HavePlayers())
        return;

    for (MapReference const& ref : map->GetPlayers())
    Unit* pCaster = m_creature;

    // Allowed to cast only if not casting (unless we interrupt ourself) or if spell is triggered
    if (!pCaster->IsNonMeleeSpellCasted(false) || uiCastFlags & (CF_TRIGGERED | CF_INTERRUPT_PREVIOUS))
    {
        if (Player* player = ref.GetSource())
        if (SpellEntry const* pSpell = sSpellMgr.GetSpellEntry(uiSpell))
        {
            if (!player->IsAlive() || !CombatManager::CanBeginCombat(creature, player))
                continue;
            // If cast flag CF_AURA_NOT_PRESENT is active, check if target already has aura on them
            if (uiCastFlags & CF_AURA_NOT_PRESENT)
            {
                if (pTarget->HasAura(uiSpell))
                    return CAST_FAIL_TARGET_AURA;
            }

            creature->EngageWithTarget(player);

            for (Unit* pet : player->m_Controlled)
                creature->EngageWithTarget(pet);

            if (Unit* vehicle = player->GetVehicleBase())
                creature->EngageWithTarget(vehicle);
        }
    }
}
            // Check if cannot cast spell
            if (!(uiCastFlags & CF_FORCE_CAST))
            {
                CanCastResult castResult = CanCastSpell(pTarget, pSpell, uiCastFlags & CF_TRIGGERED);

                if (castResult != CAST_OK)
                    return castResult;
            }

            // Interrupt any previous spell
            if ((uiCastFlags & CF_INTERRUPT_PREVIOUS) && pCaster->IsNonMeleeSpellCasted(false))
                pCaster->InterruptNonMeleeSpells(false);

            if ((uiCastFlags & CF_MAIN_RANGED_SPELL) && pCaster->IsMoving())
                pCaster->StopMoving();

            pCaster->CastSpell(pTarget, pSpell, uiCastFlags & CF_TRIGGERED, nullptr, nullptr, uiOriginalCasterGUID);
            return CAST_OK;
        }

        sLog.outErrorDb("DoCastSpellIfCan by creature entry %u attempt to cast spell %u but spell does not exist.", m_creature->GetEntry(), uiSpell);
        return CAST_FAIL_OTHER;
    }

    return CAST_FAIL_IS_CASTING;
}

void CreatureAI::SetSpellsList(uint32 entry)
{
    if (_moveInLOSLocked == true)
        return;
    _moveInLOSLocked = true;
    MoveInLineOfSight(who);
    _moveInLOSLocked = false;
    if (entry == 0)
        m_CreatureSpells.clear();
    else if (CreatureSpellsList const* pSpellsTemplate = sObjectMgr.GetCreatureSpellsList(entry))
        SetSpellsList(pSpellsTemplate);
    else
        sLog.outError("CreatureAI: Attempt to set spells template of creature %u to non-existent entry %u.", m_creature->GetEntry(), entry);
}

void CreatureAI::SetSpellsList(CreatureSpellsList const* pSpellsList)
{
    m_CreatureSpells.clear();
    for (const auto& entry : *pSpellsList)
    {
        m_CreatureSpells.push_back(CreatureAISpellsEntry(entry));
    }
    m_CreatureSpells.shrink_to_fit();
    m_uiCastingDelay = 0;
}

// Creature spell lists should be updated every 1.2 seconds according to research.
// https://www.reddit.com/r/wowservers/comments/834nt5/felmyst_ai_system_research/
#define CREATURE_CASTING_DELAY 1200

void CreatureAI::UpdateSpellsList(uint32 const uiDiff)
{
    if (m_uiCastingDelay <= uiDiff)
    {
        uint32 const uiDesync = (uiDiff - m_uiCastingDelay);
        DoSpellsListCasts(CREATURE_CASTING_DELAY + uiDesync);
        m_uiCastingDelay = uiDesync < CREATURE_CASTING_DELAY ? CREATURE_CASTING_DELAY - uiDesync : 0;
    }
    else
        m_uiCastingDelay -= uiDiff;
}

void CreatureAI::OnOwnerCombatInteraction(Unit* target)
void CreatureAI::DoSpellsListCasts(uint32 const uiDiff)
{
    bool bDontCast = false;
    for (auto& spell : m_CreatureSpells)
    {
        if (spell.cooldown <= uiDiff)
        {
            // Cooldown has expired.
            spell.cooldown = 0;

            // Prevent casting multiple spells in the same update. Only update timers.
            if (!(spell.castFlags & (CF_TRIGGERED | CF_INTERRUPT_PREVIOUS)))
            {
                if (bDontCast || m_creature->IsNonMeleeSpellCasted(false))
                    continue;
            } 

            // Checked on startup.
            SpellEntry const* pSpellInfo = sSpellMgr.GetSpellEntry(spell.spellId);

            Unit* pTarget = ToUnit(GetTargetByType(m_creature, m_creature, m_creature->GetMap(), spell.castTarget, spell.targetParam1, spell.targetParam2, pSpellInfo));

            SpellCastResult result = m_creature->TryToCast(pTarget, pSpellInfo, spell.castFlags, spell.probability);
            
            switch (result)
            {
                case SPELL_CAST_OK:
                {
                    bDontCast = !(spell.castFlags & CF_TRIGGERED);
                    spell.cooldown = urand(spell.delayRepeatMin, spell.delayRepeatMax);

                    if (spell.castFlags & CF_MAIN_RANGED_SPELL)
                    {
                        if (m_creature->IsMoving())
                            m_creature->StopMoving();

                        SetCombatMovement(false);
                        SetMeleeAttack(false);
                    }

    // Send alert sound (if any) for this creature
    me->SendAIReaction(AI_REACTION_ALERT);

    // Face the unit (stealthed player) and set distracted state for 5 seconds
    me->GetMotionMaster()->MoveDistract(5 * IN_MILLISECONDS, me->GetAbsoluteAngle(who));
}

// adapted from logic in Spell:EffectSummonType before commit 8499434
static bool ShouldFollowOnSpawn(SummonPropertiesEntry const* properties)
{
    // Summons without SummonProperties are generally scripted summons that don't belong to any owner
    if (!properties)
        return false;

    switch (properties->Control)
    {
        case SUMMON_CATEGORY_PET:
            return true;
        case SUMMON_CATEGORY_WILD:
        case SUMMON_CATEGORY_ALLY:
        case SUMMON_CATEGORY_UNK:
            if (properties->GetFlags().HasFlag(SummonPropertiesFlags::JoinSummonerSpawnGroup))
                return true;
            switch (SummonTitle(properties->Title))
            {
                case SummonTitle::Pet:
                case SummonTitle::Guardian:
                case SummonTitle::Runeblade:
                case SummonTitle::Minion:
                case SummonTitle::Companion:
                    return true;
                default:
                    return false;
            }
        default:
            return false;
    }
}

void CreatureAI::JustAppeared()
{
    if (!IsEngaged())
    {
        if (TempSummon* summon = me->ToTempSummon())
        {
            // Only apply this to specific types of summons
            if (!summon->GetVehicle() && ShouldFollowOnSpawn(summon->m_Properties) && summon->CanFollowOwner())
            {
                if (Unit* owner = summon->GetCharmerOrOwner())
                {
                    summon->GetMotionMaster()->Clear();
                    summon->GetMotionMaster()->MoveFollow(owner, PET_FOLLOW_DIST, summon->GetFollowAngle());
                }
            }
        }
    }
}

void CreatureAI::JustEnteredCombat(Unit* who)
{
    if (!IsEngaged() && !me->CanHaveThreatList())
        EngagementStart(who);
                    // If there is a script for this spell, run it.
                    if (spell.scriptId)
                        m_creature->GetMap()->ScriptsStart(sCreatureSpellScripts, spell.scriptId, m_creature->GetObjectGuid(), pTarget->GetObjectGuid());
                    break;
                }
                case SPELL_FAILED_FLEEING:
                case SPELL_FAILED_SPELL_IN_PROGRESS:
                {
                    // Do nothing so it will try again on next update.
                    break;
                }
                case SPELL_FAILED_TRY_AGAIN:
                {
                    // Chance roll failed, so we reset cooldown.
                    spell.cooldown = urand(spell.delayRepeatMin, spell.delayRepeatMax);
                    if (spell.castFlags & CF_MAIN_RANGED_SPELL)
                    {
                        SetCombatMovement(true);
                        SetMeleeAttack(true);
                    }
                    break;
                }
                default:
                {
                    // other error
                    if (spell.castFlags & CF_MAIN_RANGED_SPELL)
                    {
                        SetCombatMovement(true);
                        SetMeleeAttack(true);
                    }
                    break;
                }
            }
        }
        else
            spell.cooldown -= uiDiff;
    }
}

void CreatureAI::ClearTargetIcon()
// Clears any group/raid icons this creature may have
{
    Map::PlayerList const& players = m_creature->GetMap()->GetPlayers();

    if (players.isEmpty())
        return;

    TC_LOG_DEBUG("scripts.ai", "CreatureAI::EnterEvadeMode: entering evade mode (why: {}) ({})", EnumUtils::ToConstant(why), me->GetGUID().ToString());
    std::set<Group*> instanceGroups;

    if (!me->GetVehicle()) // otherwise me will be in evade mode forever
    {
        if (Unit* owner = me->GetCharmerOrOwner())
        {
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MoveFollow(owner, PET_FOLLOW_DIST, me->GetFollowAngle());
        }
        else
        {
            // Required to prevent attacking creatures that are evading and cause them to reenter combat
            // Does not apply to MoveFollow
            me->AddUnitState(UNIT_STATE_EVADE);
            me->GetMotionMaster()->MoveTargetedHome();
    // Clear target icon for every unique group in instance
    for (const auto& player : players)
    {
        if (Group* pGroup = player.getSource()->GetGroup())
        {
            if (instanceGroups.find(pGroup) == instanceGroups.end())
            {
                instanceGroups.insert(pGroup);
                pGroup->ClearTargetIcon(m_creature->GetObjectGuid());
            }
        }
    }

    Reset();
}

void CreatureAI::SetGazeOn(Unit* target)
{
    if (m_creature->CanAttack(target))
    {
        AttackStart(target);
        m_creature->SetReactState(REACT_PASSIVE);
    }
}

bool CreatureAI::UpdateVictim()
{
    if (!IsEngaged())
    if (!m_creature->IsInCombat())
        return false;

    if (!me->IsAlive())
    if (m_creature->HasReactState(REACT_PASSIVE))
    {
        EngagementOver();
        return false;
        if (m_creature->GetVictim())
            return true;
        m_creature->SetReactState(REACT_AGGRESSIVE);
    }

    if (!me->HasReactState(REACT_PASSIVE))
    {
        if (Unit* victim = me->SelectVictim())
            if (victim != me->GetVictim())
                AttackStart(victim);

        return me->GetVictim() != nullptr;
    }
    else if (!me->IsInCombat())
    {
        EnterEvadeMode(EvadeReason::NoHostiles);
    if (m_creature->SelectHostileTarget())
        if (Unit* victim = m_creature->GetVictim())
            AttackStart(victim);
    return m_creature->GetVictim();
}

bool CreatureAI::UpdateVictim()
{
    if (!m_creature->IsInCombat())
        return false;
    }
    else if (me->GetVictim())
        me->AttackStop();

    return true;
}

void CreatureAI::EngagementStart(Unit* who)
{
    if (_isEngaged)
    if (!m_creature->HasReactState(REACT_PASSIVE))
    {
        TC_LOG_ERROR("scripts.ai", "CreatureAI::EngagementStart called even though creature is already engaged. Creature debug info:\n{}", me->GetDebugInfo());
        return;
    }
    _isEngaged = true;
        if (m_creature->SelectHostileTarget())
            if (Unit* victim = m_creature->GetVictim())
                AttackStart(victim);
        return m_creature->GetVictim();
    }

    me->AtEngage(who);
}

void CreatureAI::EngagementOver()
{
    if (!_isEngaged)
    if (m_creature->GetThreatManager().isThreatListEmpty())
    {
        TC_LOG_DEBUG("scripts.ai", "CreatureAI::EngagementOver called even though creature is not currently engaged. Creature debug info:\n{}", me->GetDebugInfo());
        return;
        EnterEvadeMode();
        return false;
    }
    _isEngaged = false;

    me->AtDisengage();
}


void CreatureAI::DoCast(Unit* victim, uint32 spellId, bool triggered)
{
    if (me->IsInEvadeMode())
        return false;

    if (!me->IsAlive())
    {
        EngagementOver();
        return false;
    }

    me->RemoveAurasOnEvade();

    me->CombatStop(true);
    me->SetTappedBy(nullptr);
    me->ResetPlayerDamageReq();
    me->SetLastDamagedTime(0);
    me->SetCannotReachTarget(false);
    me->DoNotReacquireSpellFocusTarget();
    me->SetTarget(ObjectGuid::Empty);
    me->GetSpellHistory()->ResetAllCooldowns();
    EngagementOver();
    if (!victim || (m_creature->IsNonMeleeSpellCasted(false) && !triggered))
        return;

    m_creature->CastSpell(victim, spellId, triggered);
}

void CreatureAI::DoCastAOE(uint32 spellId, bool triggered)
{
    if (!triggered && m_creature->IsNonMeleeSpellCasted(false))
        return;

    m_creature->CastSpell((Unit*)nullptr, spellId, triggered);
}

const uint32 BOUNDARY_VISUALIZE_CREATURE = 15425;
const float BOUNDARY_VISUALIZE_CREATURE_SCALE = 0.25f;
const int8 BOUNDARY_VISUALIZE_STEP_SIZE = 1;
const int32 BOUNDARY_VISUALIZE_FAILSAFE_LIMIT = 750;
const float BOUNDARY_VISUALIZE_SPAWN_HEIGHT = 5.0f;
int32 CreatureAI::VisualizeBoundary(Seconds duration, Unit* owner, bool fill) const
{
    typedef std::pair<int32, int32> coordinate;

    if (!owner)
        return -1;

    if (!_boundary || _boundary->empty())
        return LANG_CREATURE_MOVEMENT_NOT_BOUNDED;

    std::queue<coordinate> Q;
    std::unordered_set<coordinate> alreadyChecked;
    std::unordered_set<coordinate> outOfBounds;

    Position startPosition = owner->GetPosition();
    if (!IsInBoundary(&startPosition)) // fall back to creature position
    {
        startPosition = me->GetPosition();
        if (!IsInBoundary(&startPosition)) // fall back to creature home position
        {
            startPosition = me->GetHomePosition();
            if (!IsInBoundary(&startPosition))
                return LANG_CREATURE_NO_INTERIOR_POINT_FOUND;
bool CreatureAI::DoMeleeAttackIfReady()
{
    return m_bMeleeAttack ? m_creature->UpdateMeleeAttackingState() : false;
}

struct EnterEvadeModeHelper
{
    explicit EnterEvadeModeHelper(Unit* _source) : source(_source) {}
    void operator()(Unit* unit) const
    {
        if (unit->IsCreature() && unit->ToCreature()->IsTotem())
            ((Totem*)unit)->UnSummon();
        else
        {
            unit->GetMotionMaster()->Clear(false);
            // for a controlled unit this will result in a follow move
            unit->GetMotionMaster()->MoveTargetedHome();
            unit->DeleteThreatList();
            unit->CombatStop(true);
        }
    }
    Unit* source;
};

    bool boundsWarning = false;
    Q.push({ 0,0 });
    while (!Q.empty())
    {
        coordinate front = Q.front();
        bool hasOutOfBoundsNeighbor = false;
        for (coordinate const& off : std::list<coordinate>{ {1, 0}, {0, 1}, {-1, 0}, {0, -1} })
        {
            coordinate next(front.first + off.first, front.second + off.second);
            if (next.first > BOUNDARY_VISUALIZE_FAILSAFE_LIMIT || next.first < -BOUNDARY_VISUALIZE_FAILSAFE_LIMIT || next.second > BOUNDARY_VISUALIZE_FAILSAFE_LIMIT || next.second < -BOUNDARY_VISUALIZE_FAILSAFE_LIMIT)
            {
                boundsWarning = true;
                continue;
            }
            if (alreadyChecked.find(next) == alreadyChecked.end()) // never check a coordinate twice
            {
                Position nextPos(startPosition.GetPositionX() + next.first*BOUNDARY_VISUALIZE_STEP_SIZE, startPosition.GetPositionY() + next.second*BOUNDARY_VISUALIZE_STEP_SIZE, startPosition.GetPositionZ());
                if (IsInBoundary(&nextPos))
                    Q.push(next);
                else
                {
                    outOfBounds.insert(next);
                    hasOutOfBoundsNeighbor = true;
                }
                alreadyChecked.insert(next);
            }
            else if (outOfBounds.find(next) != outOfBounds.end())
                hasOutOfBoundsNeighbor = true;
        }
        if (fill || hasOutOfBoundsNeighbor)
        {
            if (TempSummon* point = owner->SummonCreature(BOUNDARY_VISUALIZE_CREATURE, Position(startPosition.GetPositionX() + front.first * BOUNDARY_VISUALIZE_STEP_SIZE, startPosition.GetPositionY() + front.second * BOUNDARY_VISUALIZE_STEP_SIZE, spawnZ), TEMPSUMMON_TIMED_DESPAWN, duration))
            {
                point->SetObjectScale(BOUNDARY_VISUALIZE_CREATURE_SCALE);
                point->SetUnitFlag(UNIT_FLAG_STUNNED);
                point->SetImmuneToAll(true);
                if (!hasOutOfBoundsNeighbor)
                    point->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
            }
        }

        Q.pop();
void CreatureAI::SetMeleeAttack(bool enabled)
{
    if (m_bMeleeAttack == enabled)
        return;

    m_bMeleeAttack = enabled;

    if (Unit* pVictim = m_creature->GetVictim())
    { 
        if (enabled)
        {
            m_creature->AddUnitState(UNIT_STAT_MELEE_ATTACKING);
            m_creature->SendMeleeAttackStart(pVictim);
        } 
        else
        {
            m_creature->ClearUnitState(UNIT_STAT_MELEE_ATTACKING);
            m_creature->SendMeleeAttackStop(pVictim);
        }
    }
}

bool CreatureAI::IsInBoundary(Position const* who) const
void CreatureAI::SetCombatMovement(bool enabled)
{
    if (m_bCombatMovement == enabled)
        return;

    m_bCombatMovement = enabled;

    return CreatureAI::IsInBounds(*_boundary, who) != _negateBoundary;
}

bool CreatureAI::IsInBounds(CreatureBoundary const& boundary, Position const* pos)
{
    for (AreaBoundary const* areaBoundary : boundary)
        if (!areaBoundary->IsWithinBoundary(pos))
            return false;

    return true;
    if (Unit* pVictim = m_creature->GetVictim())
    {
        if (!enabled && (m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() == CHASE_MOTION_TYPE))
        {
            m_creature->GetMotionMaster()->MovementExpired(false);
            m_creature->GetMotionMaster()->MoveIdle();
        }
        else if (enabled && (m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() == IDLE_MOTION_TYPE))
        {
            m_creature->GetMotionMaster()->MovementExpired(false);
            m_creature->GetMotionMaster()->MoveChase(pVictim);
        }  
    }
}

void CreatureAI::OnCombatStop()
{
    // Reset back to default spells template. This also resets timers.
    SetSpellsList(m_creature->GetCreatureInfo()->spell_list_id);

    // Reset combat movement and melee attack.
    m_bCombatMovement = true;
    m_bMeleeAttack = true;
}

void CreatureAI::EnterEvadeMode()
{
    if (IsInBoundary())
        return true;
    else
    if (!m_creature->IsAlive())
    {
        EnterEvadeMode(EvadeReason::Boundary);
        return false;
    }
}
        m_creature->CombatStop(true);
        m_creature->DeleteThreatList();
        return;
    }

Creature* CreatureAI::DoSummon(uint32 entry, Position const& pos, Milliseconds despawnTime, TempSummonType summonType)
{
    return me->SummonCreature(entry, pos, summonType, despawnTime);
}
    if (!m_creature->IsCharmed())
    {
        m_creature->RemoveAurasAtReset();

        // clear all movement generators except default
        m_creature->GetMotionMaster()->Clear(false);
        m_creature->GetMotionMaster()->MoveTargetedHome();
    }

Creature* CreatureAI::DoSummon(uint32 entry, WorldObject* obj, float radius, Milliseconds despawnTime, TempSummonType summonType)
{
    Position pos = obj->GetRandomNearPosition(radius);
    return me->SummonCreature(entry, pos, summonType, despawnTime);
    m_creature->DeleteThreatList();
    m_creature->CombatStop(true);
    m_creature->SetLootRecipient(nullptr);
    m_creature->CallForAllControlledUnits(EnterEvadeModeHelper(m_creature), CONTROLLED_PET | CONTROLLED_GUARDIANS | CONTROLLED_CHARM | CONTROLLED_TOTEMS);
}

Creature* CreatureAI::DoSummonFlyer(uint32 entry, WorldObject* obj, float flightZ, float radius, Milliseconds despawnTime, TempSummonType summonType)
// Distract creature, if player gets too close while stealthed/prowling
void CreatureAI::TriggerAlert(Unit const* who)
{
    // If there's no target, or target isn't a player do nothing
    if (!who || who->GetTypeId() != TYPEID_PLAYER)
        return;

    // If this unit isn't an NPC, is already distracted, is in combat, is confused, stunned or fleeing, do nothing
    if (m_creature->GetTypeId() != TYPEID_UNIT || m_creature->IsInCombat() || m_creature->HasUnitState(UNIT_STAT_NO_FREE_MOVE))
        return;

    // Only alert for hostiles!
    if (m_creature->IsCivilian() || m_creature->HasReactState(REACT_PASSIVE) || !m_creature->IsValidAttackTarget(who))
        return;

    // 10 sec cooldown for stealth warning
    if (WorldTimer::getMSTimeDiffToNow(m_uLastAlertTime) < 10000)
        return;

    // only alert if target is within line of sight
    if (!m_creature->IsWithinLOSInMap(who))
        return;

    // Send alert sound (if any) for this creature
    m_creature->SendAIReaction(AI_REACTION_ALERT);

    // Face the unit (stealthed player) and set distracted state for 5 seconds
    m_creature->StopMoving();
    m_creature->SetFacingTo(m_creature->GetAngle(who->GetPositionX(), who->GetPositionY()));
    m_creature->GetMotionMaster()->MoveDistract(5 * IN_MILLISECONDS);
    m_uLastAlertTime = WorldTimer::getMSTime();
}

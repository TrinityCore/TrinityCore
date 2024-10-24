#ifndef _BOT_GRIDNOTIFIERS_H
#define _BOT_GRIDNOTIFIERS_H

#include "bot_ai.h"
#include "botspell.h"
#include "Corpse.h"
#include "Creature.h"
#include "DBCStores.h"
#include "DynamicObject.h"
#include "GameObject.h"
#include "Group.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "Vehicle.h"
/*
Name: bot_GridNotifiers
%Complete: 99+
Comment: Custom grid notifiers for Bot system by Trickerer (onlysuffering@gmail.com)
Category: creature_cripts/custom/bots/grids
*/

extern bool _botPvP;

template<class Check>
struct Unit2LastSearcher
{
    Unit* &i_result1;
    Unit* &i_result2;
    Check& i_check;

    Unit2LastSearcher(Unit* &result1, Unit* &result2, Check& check)
        : i_result1(result1), i_result2(result2), i_check(check) { }

    void Visit(CreatureMapType &m)
    {
        for (CreatureMapType::iterator itr = m.begin(); itr != m.end(); ++itr)
        {
            switch ((uint32)i_check(itr->GetSource()))
            {
                case 1: i_result1 = itr->GetSource(); break;
                case 2: i_result2 = itr->GetSource(); break;
                default:                              break;
            }
        }
    }

    void Visit(PlayerMapType &m)
    {
        for (PlayerMapType::iterator itr = m.begin(); itr != m.end(); ++itr)
        {
            switch ((uint32)i_check(itr->GetSource()))
            {
                case 1: i_result1 = itr->GetSource(); break;
                case 2: i_result2 = itr->GetSource(); break;
                default:                              break;
            }
        }
    }

    template<class NOT_INTERESTED> void Visit(GridRefManager<NOT_INTERESTED> &) { }
};

class ImmunityShieldDispelTargetCheck
{
    public:
        explicit ImmunityShieldDispelTargetCheck(Unit const* unit, float dist, bot_ai const* m_ai) :
        me(unit), range(dist), ai(m_ai) { }
        bool operator()(Unit const* u)
        {
            if (!_botPvP && me->IsPvP() && u->IsControlledByPlayer())
                return false;
            if (!u->IsInCombat())
                return false;
            if (!u->InSamePhase(me))
                return false;
            if (!me->IsWithinDistInMap(u, range))
                return false;
            if (!u->isTargetableForAttack())
                return false;
            //if (ai->InDuel(u))
            //    return false;
            if (!ai->IsInBotParty(u->GetVictim()))
                return false;
            if (!u->HasAuraWithMechanic(1<<MECHANIC_IMMUNE_SHIELD))
                return false;

            if (!u->IsWithinLOSInMap(me, LINEOFSIGHT_ALL_CHECKS, VMAP::ModelIgnoreFlags::M2))
                return false;

            return true;
        }
    private:
        Unit const* me;
        float range;
        bot_ai const* ai;
        ImmunityShieldDispelTargetCheck(ImmunityShieldDispelTargetCheck const&);
};

class NearestHostileUnitCheck
{
    enum : uint32 {
        INVALID         = 0,
        VALID_PRIMARY   = 1,
        VALID_SECONDARY = 2
    };

    public:
        NearestHostileUnitCheck(NearestHostileUnitCheck const&) = delete;
        explicit NearestHostileUnitCheck(Unit const* unit, float dist, bool magic, bot_ai const* m_ai, bool targetCCed, bool withSecondary) :
        me(unit), m_range(dist), byspell(magic), ai(m_ai), AttackCCed(targetCCed), checkSecondary(withSecondary)
        { free = ai->IAmFree(); berserk = free && (ai->IsWanderer() || unit->GetFaction() == 14); }
        explicit NearestHostileUnitCheck(Unit const* unit, float dist, bool magic, bot_ai const* m_ai) :
        NearestHostileUnitCheck(unit, dist, magic, m_ai, true, false)
        {}
        uint32 operator()(Unit const* u)
        {
            if (u == me)
                return INVALID;
            if (!me->IsWithinDistInMap(u, m_range, !berserk))
                return INVALID;
            if (berserk && std::fabs(me->GetPositionZ() - u->GetPositionZ()) > (m_range * 0.25f + 5.0f))
                return INVALID;
            if (me->HasUnitState(UNIT_STATE_ROOT) && (ai->HasRole(BOT_ROLE_RANGED) == me->IsWithinDistInMap(u, 8.f)))
                return INVALID;
            if (!berserk && !u->IsInCombat())
                return INVALID;
            //if (ai->InDuel(u))
            //    return false;
            if (!AttackCCed && (u->HasUnitState(UNIT_STATE_CONFUSED | UNIT_STATE_STUNNED | UNIT_STATE_FLEEING | UNIT_STATE_DISTRACTED | UNIT_STATE_CONFUSED_MOVE | UNIT_STATE_FLEEING_MOVE)))
                return INVALID;//do not allow CCed units if checked
            //if (u->HasUnitState(UNIT_STATE_CASTING) && (u->GetTypeId() == TYPEID_PLAYER || u->IsPet()))
            //    for (uint8 i = 0; i != CURRENT_MAX_SPELL; ++i)
            //        if (Spell* spell = u->GetCurrentSpell(i))
            //            if (ai->IsInBotParty(spell->m_targets.GetUnitTarget()))
            //                return true;
            if (!berserk && !ai->IsInBotParty(u->GetVictim()))
                return INVALID;

            if (free && !berserk && u->IsControlledByPlayer() && !u->IsInCombat())
                return INVALID;

            if (!u->IsWithinLOSInMap(me, LINEOFSIGHT_ALL_CHECKS))
                return INVALID;

            uint32 res = VALID_PRIMARY;
            if (!ai->CanBotAttack(u, byspell))
            {
                if (checkSecondary && ai->CanBotAttack(u, byspell, checkSecondary))
                    res = VALID_SECONDARY;
                else
                    return INVALID;
            }

            m_range = me->GetDistance(u);   // use found unit range as new range limit for next check
            return res;
        }
    private:
        Unit const* me;
        float m_range;
        bool byspell;
        bot_ai const* ai;
        bool AttackCCed;
        bool checkSecondary;
        bool free;
        bool berserk;
};

class NearbyHostileVehicleTargetCheck
{
    public:
        explicit NearbyHostileVehicleTargetCheck(Unit const* unit, float dist, bot_ai const* m_ai) : veh(unit), m_range(dist), ai(m_ai) { }
        bool operator()(Unit const* u)
        {
            if (u == veh)
                return false;
            if (!veh->IsWithinDistInMap(u, m_range))
                return false;
            if (!u->IsInCombat())
                return false;
            if (!_botPvP && veh->IsPvP() && u->IsControlledByPlayer())
                return false;
            //if (!veh->IsValidAttackTarget(u))
            //    return false;
            //if (!u->isTargetableForAttack(false))
            //    return false;
            //if (ai->IsInBotParty(u))
            //    return false;
            if (!ai->IsInBotParty(u->GetVictim()))
                return false;
            if (u->GetReactionTo(veh) >= REP_NEUTRAL)
                return false;
            //if (!u->IsWithinLOSInMap(veh))
            //    return false;

            return true;
        }
    private:
        Unit const* veh;
        float m_range;
        bot_ai const* ai;
        NearbyHostileVehicleTargetCheck(NearbyHostileVehicleTargetCheck const&);
};

class HostileDispelTargetCheck
{
    public:
        explicit HostileDispelTargetCheck(Unit const* unit, float dist = 30, bool stealable = false, bot_ai const* m_ai = nullptr) :
        me(unit), m_range(dist), checksteal(stealable), ai(m_ai) { }
        bool operator()(Unit const* u) const
        {
            if (!_botPvP && me->IsPvP() && u->IsControlledByPlayer())
                return false;
            if (u->IsInCombat() &&
                u->InSamePhase(me) &&
                u->IsWithinDistInMap(me, m_range) &&
                u->isTargetableForAttack() &&
                //!ai->InDuel(u) &&
                (!ai->IsInBotParty(u) || ai->IsInHeroicOrRaid()) &&
                (ai->IsInBotParty(u->GetVictim()) || me->GetVictim() == u))
            {
                if (!checksteal && u->GetEntry() == 25744 && !u->GetOwnedAuras().empty()) // Sunwell - Dark Fiend
                    return true;

                if (checksteal)
                {
                    if (u->IsImmunedToSpell(sSpellMgr->GetSpellInfo(30449), me))
                        return false; //immune to steal
                }
                else if (ai->GetBotClass() == BOT_CLASS_SHAMAN)
                {
                    if (u->IsImmunedToSpell(sSpellMgr->GetSpellInfo(370), me))
                        return false; //immune to purge
                }
                //else if (ai->GetBotClass() == BOT_CLASS_PRIEST)
                //{
                //    if (me->GetLevel() < 70 && u->IsImmunedToSpell(sSpellMgr->GetSpellInfo(527), me))
                //        return false; //immune to dispel magic
                //}

                Unit::AuraApplicationMap const &AurApps = u->GetAppliedAuras();
                SpellInfo const* Info;
                uint32 id;
                for (Unit::AuraApplicationMap::const_iterator itr = AurApps.begin(); itr != AurApps.end(); ++itr)
                {
                    Info = itr->second->GetBase()->GetSpellInfo();
                    if (itr->second->IsPositive() && Info->Dispel == DISPEL_MAGIC &&
                        !(Info->Attributes & (SPELL_ATTR0_PASSIVE | SPELL_ATTR0_HIDDEN_CLIENTSIDE)) &&
                        !(checksteal && (Info->AttributesEx4 & SPELL_ATTR4_NOT_STEALABLE)))
                    {
                        id = Info->Id;
                        if (id != 20050 && id != 20052 && id != 20053 && //Vengeance
                            id != 50447 && id != 50448 && id != 50449) //Bloody Vengeance
                            return true;
                    }
                }

                //Unit::AuraMap const &Auras = u->GetOwnedAuras();
                //SpellInfo const* Info;
                //uint32 id;
                //for (Unit::AuraMap::const_iterator itr = Auras.begin(); itr != Auras.end(); ++itr)
                //{
                //    Aura* aura = itr->second;
                //    Info = aura->GetSpellInfo();
                //    if (Info->Dispel != DISPEL_MAGIC) continue;
                //    id = Info->Id;
                //    if (id == 20050 || id == 20052 || id == 20053 || //Vengeance
                //        id == 50447 || id == 50448 || id == 50449) //Bloody Vengeance
                //        continue;
                //    if (Info->Attributes & (SPELL_ATTR0_PASSIVE | SPELL_ATTR0_HIDDEN_CLIENTSIDE)) continue;
                //    //if (Info->AttributesEx & SPELL_ATTR1_DONT_DISPLAY_IN_AURA_BAR) continue;
                //    if (checksteal && (Info->AttributesEx4 & SPELL_ATTR4_NOT_STEALABLE)) continue;
                //    AuraApplication const* aurApp = aura->GetApplicationOfTarget(u->GetGUID());
                //    if (aurApp && aurApp->IsPositive())
                //        return true;
                //}
            }
            return false;
        }
    private:
        Unit const* me;
        float m_range;
        bool checksteal;
        bot_ai const* ai;
        HostileDispelTargetCheck(HostileDispelTargetCheck const&);
};

class AffectedTargetCheck
{
    public:
        explicit AffectedTargetCheck(ObjectGuid casterguid, float dist, uint32 spellId, Player const* groupCheck = 0, uint8 hostileCheckType = 0) :
        caster(casterguid), m_range(dist), spell(spellId), checker(groupCheck), needhostile(hostileCheckType) { }
        bool operator()(Unit const* u) const
        {
            if (!u->IsAlive())
                return false;
            if (caster && u->HasUnitFlag(UNIT_FLAG_UNINTERACTIBLE))
                return false;
            if (!checker->IsWithinDistInMap(u, m_range))
                return false;
            if (needhostile == 0 && !u->IsHostileTo(checker)) return false;
            //else if (needhostile == 1 && !(gr && gr->IsMember(u->GetGUID()) && u->GetTypeId() == TYPEID_PLAYER)) return false;
            //else if (needhostile == 2 && !(gr && gr->IsMember(u->GetGUID()))) return false;
            else if (needhostile == 3 && !u->IsFriendlyTo(checker)) return false;
            else if (needhostile == 4 && !(u->GetTypeId() == TYPEID_PLAYER && u->IsFriendlyTo(checker))) return false;

            //if (u->HasAura(spell, caster)
            //    return true;

            Unit::AuraApplicationMap const &Auras = u->GetAppliedAuras();
            for (Unit::AuraApplicationMap::const_iterator itr = Auras.begin(); itr != Auras.end(); ++itr)
            {
                AuraApplication const* auraApp = itr->second;
                if (itr->first == spell)
                    if (caster == 0 || auraApp->GetBase()->GetCasterGUID() == caster)
                        return true;
            }
            return false;
        }
    private:
        ObjectGuid const caster;
        float m_range;
        uint32 const spell;
        Player const* checker;
        uint8 needhostile;
        AffectedTargetCheck(AffectedTargetCheck const&);
};

class PolyUnitCheck
{
    public:
        explicit PolyUnitCheck(Unit const* unit, float dist) : me(unit), m_range(dist) {}
        bool operator()(Unit const* u) const
        {
            if (!_botPvP && me->IsPvP() && u->IsControlledByPlayer())
                return false;
            if (!me->GetVictim() || u == me->GetVictim())
                return false;
            if (!me->IsWithinDistInMap(u, m_range))
                return false;
            if (!u->IsInCombat() || !u->IsAlive() || !u->GetVictim())
                return false;
            if (u->GetCreatureType() != CREATURE_TYPE_HUMANOID &&
                u->GetCreatureType() != CREATURE_TYPE_BEAST)
                return false;
            if (me->GetDistance(u) < 6 || me->GetVictim()->GetDistance(u) < 5 ||
                (me->ToCreature()->GetBotClass() == BOT_CLASS_MAGE && u->GetHealthPct() < 70))
                return false;
            if (!u->InSamePhase(me))
                return false;
            if (!u->isTargetableForAttack())
                return false;
            if (!u->IsVisible() || u->IsTotem())
                return false;
            if (me->ToCreature()->GetBotClass() == BOT_CLASS_MAGE ? !u->getAttackers().empty() : u->getAttackers().size() > 1)
                return false;
            if (!u->IsHostileTo(me))
                return false;
            if (u->IsPolymorphed() ||
                u->IsFrozen() ||
                u->IsRooted() ||
                u->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE) ||
                u->HasAuraType(SPELL_AURA_MOD_PACIFY_SILENCE) ||
                u->HasAuraTypeWithFamilyFlags(SPELL_AURA_MOD_STUN, SPELLFAMILY_PALADIN, 0x4))
                return false;

            if (me->ToCreature()->GetBotClass() == BOT_CLASS_MAGE && !u->IsImmunedToSpell(sSpellMgr->GetSpellInfo(118), me))//Polymorph
                return true;
            if (me->ToCreature()->GetBotClass() == BOT_CLASS_SHAMAN && !u->IsImmunedToSpell(sSpellMgr->GetSpellInfo(51514), me))//Hex
                return true;

            return false;
        }
    private:
        Unit const* me;
        float m_range;
        PolyUnitCheck(PolyUnitCheck const&);
};

class FearUnitCheck
{
    public:
        explicit FearUnitCheck(Unit const* unit, float dist = 30) : me(unit), m_range(dist) {}
        bool operator()(Unit const* u) const
        {
            if (!_botPvP && me->IsPvP() && u->IsControlledByPlayer())
                return false;
            if (!u->IsAlive())
                return false;
            if (!u->IsInCombat())
                return false;
            if (!u->InSamePhase(me))
                return false;
            if (u->HasUnitState(UNIT_STATE_CONFUSED | UNIT_STATE_STUNNED | UNIT_STATE_FLEEING | UNIT_STATE_DISTRACTED | UNIT_STATE_CONFUSED_MOVE | UNIT_STATE_FLEEING_MOVE))
                return false;
            if (u->IsFeared())
                return false;
            if (!me->IsWithinDistInMap(u, m_range))
                return false;
            if (!u->IsVisible() || u->IsTotem())
                return false;
            if (u->GetCreatureType() == CREATURE_TYPE_UNDEAD)
                return false;
            if (u->GetCreatureType() != CREATURE_TYPE_BEAST &&
                me->ToCreature()->GetBotClass() == BOT_CLASS_HUNTER)
                return false;
            if (!u->isTargetableForAttack())
                return false;
            if (u->getAttackers().size() > 1 && u->GetVictim() != me)
                return false;
            //Unit::GetDiminishing() should be const but it isn't
            if (const_cast<Unit*>(u)->GetDiminishing(DIMINISHING_FEAR) > DIMINISHING_LEVEL_3)
                return false;
            if (u->GetReactionTo(me) > REP_NEUTRAL)
                return false;

            if (me->ToCreature()->GetBotClass() == BOT_CLASS_WARLOCK &&
                !u->IsImmunedToSpell(sSpellMgr->GetSpellInfo(5782), me))//fear rank1
                return true;
            if (me->ToCreature()->GetBotClass() == BOT_CLASS_HUNTER &&
                !u->IsImmunedToSpell(sSpellMgr->GetSpellInfo(1513), me))//scare beast rank1
                return true;

            return false;
        }
    private:
        Unit const* me;
        float m_range;
        FearUnitCheck(FearUnitCheck const&);
};

class StunUnitCheck
{
    public:
        explicit StunUnitCheck(Unit const* unit, float dist = 20) : me(unit), m_range(dist) {}
        bool operator()(Unit const* u) const
        {
            if (!_botPvP && me->IsPvP() && u->IsControlledByPlayer())
                return false;
            if (!u->IsAlive())
                return false;
            if (!u->IsInCombat())
                return false;
            if (!u->InSamePhase(me))
                return false;
            if (u->HasUnitState(UNIT_STATE_CONFUSED | UNIT_STATE_STUNNED | UNIT_STATE_FLEEING | UNIT_STATE_DISTRACTED | UNIT_STATE_CONFUSED_MOVE | UNIT_STATE_FLEEING_MOVE))
                return false;
            if (!me->IsWithinDistInMap(u, m_range))
                return false;
            if (!u->IsVisible() || u->IsTotem())
                return false;
            if (!u->isTargetableForAttack())
                return false;
            if (!u->getAttackers().empty())
                return false;
            if (me->ToCreature()->GetBotClass() != BOT_CLASS_DREADLORD && u->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE))
                return false;
            if (me->ToCreature()->GetBotClass() == BOT_CLASS_HUNTER && me->GetTarget() == u->GetGUID())//auto shot
                return false;
            if (u->GetReactionTo(me) > REP_NEUTRAL)
                return false;
            if (me->ToCreature()->GetBotClass() == BOT_CLASS_PALADIN &&
                !(u->GetCreatureType() == CREATURE_TYPE_HUMANOID ||
                u->GetCreatureType() == CREATURE_TYPE_DEMON ||
                u->GetCreatureType() == CREATURE_TYPE_DRAGONKIN ||
                u->GetCreatureType() == CREATURE_TYPE_GIANT ||
                u->GetCreatureType() == CREATURE_TYPE_UNDEAD))
                return false;
            if (me->ToCreature()->GetBotClass() == BOT_CLASS_DRUID &&
                !(u->GetCreatureType() == CREATURE_TYPE_BEAST ||
                u->GetCreatureType() == CREATURE_TYPE_DRAGONKIN))
                return false;
            if (me->ToCreature()->GetBotClass() == BOT_CLASS_PALADIN && me->GetDistance(u) < 10)//prevent break due to AOE damage
                return false;
            if (me->ToCreature()->GetBotClass() == BOT_CLASS_PALADIN &&
                !u->IsImmunedToSpell(sSpellMgr->GetSpellInfo(20066), me))//repentance
                return true;
            if (me->ToCreature()->GetBotClass() == BOT_CLASS_HUNTER &&
                !u->IsImmunedToSpell(sSpellMgr->GetSpellInfo(60210), me))//freezing arrow effect
                return true;
            if (me->ToCreature()->GetBotClass() == BOT_CLASS_HUNTER &&
                !u->IsImmunedToSpell(sSpellMgr->GetSpellInfo(19386), me))//wyvern sting rank 1
                return true;
            if (me->ToCreature()->GetBotClass() == BOT_CLASS_HUNTER &&
                !u->IsImmunedToSpell(sSpellMgr->GetSpellInfo(1991), me))//scatter shot
                return true;
            if (me->ToCreature()->GetBotClass() == BOT_CLASS_ROGUE &&
                !u->IsImmunedToSpell(sSpellMgr->GetSpellInfo(2094), me))//blind
                return true;
            if (me->ToCreature()->GetBotClass() == BOT_CLASS_WARLOCK &&
                u->GetCreatureType() == CREATURE_TYPE_HUMANOID &&
                (u->GetVictim() || u->IsControlledByPlayer()) &&
                !u->IsImmunedToSpell(sSpellMgr->GetSpellInfo(6358), me))//seduction
                return true;
            if (me->ToCreature()->GetBotClass() == BOT_CLASS_DREADLORD &&
                u->GetCreatureType() != CREATURE_TYPE_UNDEAD &&
                !u->IsImmunedToSpell(sSpellMgr->GetSpellInfo(SPELL_SLEEP), me))
                return true;

            return false;
        }
    private:
        Unit const* me;
        float m_range;
        StunUnitCheck(StunUnitCheck const&);
};

class UndeadCCUnitCheck
{
    public:
        explicit UndeadCCUnitCheck(Unit const* unit, float dist, bot_ai const* ai, uint32 spell, bool unattacked) :
        me(unit), m_range(dist), m_ai(ai), m_spellId(spell), _unattacked(unattacked) { }
        bool operator()(Unit const* u) const
        {
            if (!_botPvP && me->IsPvP() && u->IsControlledByPlayer())
                return false;
            if (!me->IsWithinDistInMap(u, m_range))
                return false;
            if (!u->InSamePhase(me))
                return false;
            if (!u->IsInCombat())
                return false;
            if (!u->IsAlive())
                return false;
            if (!u->isTargetableForAttack())
                return false;
            if (!u->IsVisible())
                return false;
            if (_unattacked && !u->getAttackers().empty())
                return false;
            if (u->HasUnitState(UNIT_STATE_CONFUSED | UNIT_STATE_STUNNED | UNIT_STATE_FLEEING | UNIT_STATE_DISTRACTED | UNIT_STATE_CONFUSED_MOVE | UNIT_STATE_FLEEING_MOVE))
                return false;
            if (me->ToCreature()->GetBotClass() == BOT_CLASS_PRIEST &&
                !(u->GetCreatureType() == CREATURE_TYPE_UNDEAD && !u->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE)))
                return false;
            if (me->ToCreature()->GetBotClass() == BOT_CLASS_PALADIN &&
                u->GetCreatureType() != CREATURE_TYPE_UNDEAD && u->GetCreatureType() != CREATURE_TYPE_DEMON)
                return false;
            if (me->ToCreature()->GetBotClass() == BOT_CLASS_WARLOCK &&
                ((u->GetCreatureType() != CREATURE_TYPE_DEMON && u->GetCreatureType() != CREATURE_TYPE_ELEMENTAL) ||
                m_ai->IsPointedAnyAttackTarget(u)))
                return false;
            if (u->GetVictim() && !m_ai->IsInBotParty(u->GetVictim()))
                return false;
            if (u->GetReactionTo(me) > REP_NEUTRAL)
                return false;
            if (u->IsImmunedToSpell(sSpellMgr->GetSpellInfo(m_spellId)->TryGetSpellInfoOverride(me), me))
                return false;
            if (m_ai->IsPointedNoDPSTarget(u) && bot_ai::IsDamagingSpell(sSpellMgr->GetSpellInfo(m_spellId)->TryGetSpellInfoOverride(me)))
                return false;

            return true;
        }
    private:
        Unit const* me;
        float m_range;
        bot_ai const* m_ai;
        uint32 m_spellId;
        bool _unattacked;
        UndeadCCUnitCheck(UndeadCCUnitCheck const&);
};

class RootUnitCheck
{
    public:
        explicit RootUnitCheck(Unit const* unit, float dist, bot_ai const* ai, uint32 spell = 0) :
        me(unit), m_range(dist), m_ai(ai), m_spellId(spell) { if (!spell) return; }
        bool operator()(Unit const* u) const
        {
            if (!_botPvP && me->IsPvP() && u->IsControlledByPlayer())
                return false;
            if (u == me->GetVictim())
                return false;
            if (!u->IsAlive())
                return false;
            if (!u->IsInCombat())
                return false;
            if (!me->IsWithinDistInMap(u, m_range))
                return false;
            if (me->GetDistance(u) < 8)
                return false;
            if (!u->InSamePhase(me))
                return false;
            if (!u->IsVisible())
                return false;
            if (!u->isTargetableForAttack(false))
                return false;
            if (u->IsFrozen() || u->IsRooted())
                return false;
            if (!u->getAttackers().empty())
                return false;
            if (u->GetVictim() && !m_ai->IsInBotParty(u->GetVictim()))
                return false;
            if (u->GetReactionTo(me) > REP_NEUTRAL)
                return false;
            if (u->IsPolymorphed() ||
                u->HasAuraType(SPELL_AURA_MOD_PACIFY_SILENCE)/*hex*/ ||
                u->HasAuraTypeWithFamilyFlags(SPELL_AURA_MOD_STUN, SPELLFAMILY_PALADIN, 0x4)/*repentance*/ ||
                u->HasAuraTypeWithFamilyFlags(SPELL_AURA_MOD_STUN, SPELLFAMILY_PRIEST, 0x40000000)/*shackle undead*/)
                return false;
            if (m_ai->IsPointedNoDPSTarget(u) && bot_ai::IsDamagingSpell(sSpellMgr->GetSpellInfo(m_spellId)->TryGetSpellInfoOverride(me)))
                return false;
            if (!u->IsImmunedToSpell(sSpellMgr->GetSpellInfo(m_spellId)->TryGetSpellInfoOverride(me), me))
                return true;

            return false;
        }
    private:
        Unit const* me;
        float m_range;
        bot_ai const* m_ai;
        uint32 m_spellId;
        RootUnitCheck(RootUnitCheck const&);
};

class CastingUnitCheck
{
    public:
        explicit CastingUnitCheck(Unit const* unit, float mindist = 0.f, float maxdist = 30, uint32 spell = 0, uint8 minHpPct = 0) :
        me(unit), min_range(mindist), max_range(maxdist), m_spell(spell), m_minHpPct(minHpPct) {}
        bool operator()(Unit const* u) const
        {
            if (!u->IsAlive())
                return false;
            if (!u->InSamePhase(me))
                return false;
            if (!u->IsVisible() || u->IsTotem())
                return false;
            if (!u->GetTarget() && !u->IsInCombat())
                return false;
            if (!_botPvP && me->IsPvP() && u->IsControlledByPlayer())
                return false;
            if (u->HealthBelowPct(m_minHpPct))
                return false;
            if (min_range > 0.1f && me->GetDistance(u) < min_range)
                return false;
            if (!u->isTargetableForAttack(false))
                return false;
            //if (!m_friend && u->HasUnitFlag(UNIT_FLAG_SILENCED))//prevent double silence
            //    return false;
            if (!u->IsNonMeleeSpellCast(false,false,true))
                return false;
            if (!me->IsWithinDistInMap(u, max_range))
                return false;
            if (u->GetReactionTo(me) >= REP_FRIENDLY)
                return false;
            if (m_spell)
            {
                if ((m_spell == 5782 || //fear (warlock)
                    m_spell == 64044 || //fear (priest)
                    m_spell == SPELL_SLEEP) &&
                    u->GetCreatureType() == CREATURE_TYPE_UNDEAD)
                    return false;
                if (m_spell == 10326 && //turn evil
                    !(u->GetCreatureType() == CREATURE_TYPE_UNDEAD ||
                    u->GetCreatureType() == CREATURE_TYPE_DEMON))
                    return false;
                if (m_spell == 20066 && //repentance
                    !(u->GetCreatureType() == CREATURE_TYPE_HUMANOID ||
                    u->GetCreatureType() == CREATURE_TYPE_DEMON ||
                    u->GetCreatureType() == CREATURE_TYPE_DRAGONKIN ||
                    u->GetCreatureType() == CREATURE_TYPE_GIANT ||
                    u->GetCreatureType() == CREATURE_TYPE_UNDEAD))
                    return false;
                if (m_spell == 2637 && //hibernate
                    !(u->GetCreatureType() == CREATURE_TYPE_BEAST ||
                    u->GetCreatureType() == CREATURE_TYPE_DRAGONKIN))
                    return false;
                if (m_spell == 9484 && //shackle undead (priest)
                    u->GetCreatureType() != CREATURE_TYPE_UNDEAD)
                    return false;

                SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(m_spell)->TryGetSpellInfoOverride(me);
                if (u->IsImmunedToSpell(spellInfo, me))
                    return false;

                if (me->GetTypeId() == TYPEID_UNIT && me->ToCreature()->GetBotAI() && me->ToCreature()->GetBotAI()->IsPointedNoDPSTarget(u) &&
                    bot_ai::IsDamagingSpell(spellInfo))
                    return false;

                if (!CastInterruptionCheck(u, spellInfo))
                    return false;
            }

            return true;
        }

        static bool CastInterruptionCheck(Unit const* u, SpellInfo const* spellInfo)
        {
            if (spellInfo->HasEffect(SPELL_EFFECT_INTERRUPT_CAST) && spellInfo->GetFirstRankSpell()->Id != 853) //hammer of justice
            {
                if (u->GetTypeId() == TYPEID_UNIT &&
                    (u->ToCreature()->GetCreatureTemplate()->MechanicImmuneMask & (1 << (MECHANIC_INTERRUPT - 1))))
                    return false;

                Spell* curSpell;
                for (uint8 i = CURRENT_FIRST_NON_MELEE_SPELL; i != CURRENT_AUTOREPEAT_SPELL; ++i)
                {
                    curSpell = u->GetCurrentSpell(i);
                    if (!curSpell)
                        continue;

                    //copied conditions from Spell::EffectInterruptCast
                    if (!((curSpell->getState() == SPELL_STATE_CASTING ||
                        (curSpell->getState() == SPELL_STATE_PREPARING && curSpell->GetCastTime() > 0.0f)) &&
                        curSpell->GetSpellInfo()->PreventionType == SPELL_PREVENTION_TYPE_SILENCE &&
                        ((i == CURRENT_GENERIC_SPELL && curSpell->GetSpellInfo()->InterruptFlags & SPELL_INTERRUPT_FLAG_INTERRUPT) ||
                        (i == CURRENT_CHANNELED_SPELL && curSpell->GetSpellInfo()->ChannelInterruptFlags & CHANNEL_INTERRUPT_FLAG_INTERRUPT))))
                        return false;
                }
            }
            bool silenceSpell = false;
            for (uint8 i = 0; i != MAX_SPELL_EFFECTS; ++i)
            {
                if (spellInfo->_effects[i].Effect == SPELL_EFFECT_APPLY_AURA &&
                    spellInfo->_effects[i].ApplyAuraName == SPELL_AURA_MOD_SILENCE)
                {
                    silenceSpell = true;
                    break;
                }
            }
            if (silenceSpell)
            {
                if (u->GetTypeId() == TYPEID_UNIT &&
                    (u->ToCreature()->GetCreatureTemplate()->MechanicImmuneMask & (1 << (MECHANIC_SILENCE - 1))))
                    return false;

                Spell* curSpell;
                for (uint8 i = CURRENT_FIRST_NON_MELEE_SPELL; i != CURRENT_AUTOREPEAT_SPELL; ++i)
                {
                    curSpell = u->GetCurrentSpell(i);
                    if (curSpell && curSpell->GetSpellInfo()->PreventionType != SPELL_PREVENTION_TYPE_SILENCE)
                        return false;
                }
            }

            return true; //do not check players and non-interrupt non-silence spells
        }

    private:
        Unit const* me;
        float min_range, max_range;
        uint32 m_spell;
        uint8 m_minHpPct;
        CastingUnitCheck(CastingUnitCheck const&);
};

class SecondEnemyCheck
{
    public:
        explicit SecondEnemyCheck(Unit const* unit, float dist, float splashdist, Unit const* currtarget, bot_ai const* m_ai) :
        me(unit), m_range(dist), m_splashrange(splashdist), mytar(currtarget), ai(m_ai) {}
        bool operator()(Unit const* u) const
        {
            if (!u->IsAlive())
                return false;
            if (!u->IsInCombat())
                return false;
            if (u == mytar)
                return false;//We need to find SECONDARY target
            if (u->isMoving() != mytar->isMoving())//only when both targets idle or both moving
                return false;
            if (!_botPvP && me->IsPvP() && u->IsControlledByPlayer())
                return false;
            if (!me->IsWithinDistInMap(u, m_range))//distance check
                return false;
            if (mytar->GetDistance(u) > m_splashrange)//not close enough to each other
                return false;

            if (ai->CanBotAttack(u))
                return true;

            return false;
        }
    private:
        Unit const* me;
        float m_range, m_splashrange;
        Unit const* mytar;
        bot_ai const* ai;
        SecondEnemyCheck(SecondEnemyCheck const&);
};

class TranquilTargetCheck
{
    public:
        explicit TranquilTargetCheck(Unit const* unit, float mindist, float maxdist, bot_ai const* m_ai) :
        me(unit), min_range(mindist), max_range(maxdist), ai(m_ai) { }
        bool operator()(Unit const* u) const
        {
            if (!_botPvP && me->IsPvP() && u->IsControlledByPlayer())
                return false;
            if (u != me->GetVictim() &&//check hunter_bot::hunter_botAI::CheckTranquil(uint32)
                u->IsWithinDistInMap(me, max_range) &&
                u->GetDistance(me) > min_range &&
                u->IsAlive() &&
                u->InSamePhase(me) &&
                u->IsInCombat() &&
                u->isTargetableForAttack(false) &&
                u->IsVisible() &&
                ai->IsInBotParty(u->GetVictim()) &&
                u->GetReactionTo(me) <= REP_NEUTRAL)
            {
                if (u->IsImmunedToSpell(sSpellMgr->GetSpellInfo(19801), me))
                    return false;//immune to tranquilizing shot
                Unit::AuraMap const &Auras = u->GetOwnedAuras();
                for (Unit::AuraMap::const_iterator itr = Auras.begin(); itr != Auras.end(); ++itr)
                {
                    SpellInfo const* Info = itr->second->GetSpellInfo();
                    if (Info->Dispel != DISPEL_MAGIC && Info->Dispel != DISPEL_ENRAGE) continue;
                    if (Info->Attributes & (SPELL_ATTR0_PASSIVE | SPELL_ATTR0_HIDDEN_CLIENTSIDE)) continue;
                    //if (Info->AttributesEx & SPELL_ATTR1_DONT_DISPLAY_IN_AURA_BAR) continue;
                    AuraApplication const* aurApp = itr->second->GetApplicationOfTarget(u->GetGUID());
                    if (aurApp && aurApp->IsPositive())
                    {
                        return true;
                    }
                }
            }

            return false;
        }
    private:
        Unit const* me;
        float min_range, max_range;
        bot_ai const* ai;
        TranquilTargetCheck(TranquilTargetCheck const&);
};

class NearbyHostileUnitCheck
{
    public:
        explicit NearbyHostileUnitCheck(Unit const* unit, float maxdist, bot_ai const* m_ai, uint8 CCoption, WorldObject const* source) :
        me(unit), max_range(maxdist), ai(m_ai), m_CCoption(CCoption), _source(source)
        {
            free = ai->IAmFree();
        }
        bool operator()(Unit const* u) const
        {
            if (u == me || u == _source)
                return false;
            if (/*!free && */!u->IsInCombat())
                return false;
            if (!u->InSamePhase(_source))
                return false;
            if ((m_CCoption & 1) && u->HasUnitState(UNIT_STATE_CONFUSED|UNIT_STATE_STUNNED|UNIT_STATE_FLEEING|UNIT_STATE_DISTRACTED|UNIT_STATE_CONFUSED_MOVE))
                return false;
            if ((m_CCoption & 2) && u->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE))
                return false;
            if (me->HasUnitState(UNIT_STATE_ROOT) && (ai->HasRole(BOT_ROLE_RANGED) == me->IsWithinDistInMap(u, 8.f)))
                return false;
            if (!_botPvP && me->IsPvP() && u->IsControlledByPlayer())
                return false;
            if (u->GetCreatureType() == CREATURE_TYPE_CRITTER)
                return false;
            if (!_source->IsWithinDistInMap(u, max_range))
                return false;
            if (!free && !ai->CanBotAttack(u))
                return false;
            //if (ai->InDuel(u))
            //    return false;

            if (!ai->IsInBotParty(u->GetVictim()))
                return false;

            if (free)
            {
                if (u->IsControlledByPlayer())
                    return false;
                if (!me->IsValidAttackTarget(u) || !u->isTargetableForAttack(false))
                    return false;
            }

            return true;
        }
    private:
        Unit const* me;
        float max_range;
        bot_ai const* ai;
        uint8 m_CCoption;
        bool free;
        WorldObject const* _source;
        NearbyHostileUnitCheck(NearbyHostileUnitCheck const&);
};

class NearbyHostileUnitInConeCheck
{
    public:
        explicit NearbyHostileUnitInConeCheck(Unit const* unit, float maxdist, bot_ai const* m_ai) :
        me(unit), max_range(maxdist), ai(m_ai), cone(float(M_PI)/2)
        {
            free = ai->IAmFree();
        }
        bool operator()(Unit const* u) const
        {
            if (u == me)
                return false;
            //if (me->HasUnitState(UNIT_STATE_ROOT) && (ai->HasRole(BOT_ROLE_RANGED) == me->IsWithinDistInMap(u, 8.f)))
            //    return false;
            if (/*!free && */!u->IsInCombat())
                return false;
            if (!u->InSamePhase(me))
                return false;
            if (u->HasUnitState(UNIT_STATE_CONFUSED|UNIT_STATE_STUNNED|UNIT_STATE_FLEEING|UNIT_STATE_DISTRACTED|UNIT_STATE_CONFUSED_MOVE))
                return false;
            if (!free && !ai->CanBotAttack(u))
                return false;
            if (!_botPvP && me->IsPvP() && u->IsControlledByPlayer())
                return false;
            if (!me->IsWithinDistInMap(u, max_range))
                return false;
            if (!me->HasInArc(cone, u))
                return false;
            //if (ai->InDuel(u))
            //    return false;

            if (!ai->IsInBotParty(u->GetVictim()))
                return false;

            if (free)
            {
                if (u->IsControlledByPlayer())
                    return false;
                if (!me->IsValidAttackTarget(u) || !u->isTargetableForAttack(false))
                    return false;
            }

            return true;
        }
    private:
        Unit const* me;
        float max_range;
        bot_ai const* ai;
        float cone;
        bool free;
        NearbyHostileUnitInConeCheck(NearbyHostileUnitInConeCheck const&);
};

class NearbyFriendlyUnitCheck
{
    public:
        explicit NearbyFriendlyUnitCheck(Unit const* unit, float maxdist, bot_ai const* m_ai) : me(unit), max_range(maxdist), ai(m_ai) { }
        bool operator()(Unit const* u) const
        {
            if (u == me)
                return false;
            //if (!u->IsInCombat())
            //    return false;
            if (!u->IsAlive())
                return false;
            if (u->HasUnitState(UNIT_STATE_ISOLATED))
                return false;
            //if (u->IsTotem() || u->IsSummon())
            //    return false;
            if (!u->InSamePhase(me))
                return false;
            if (!me->IsWithinDistInMap(u, max_range))
                return false;
            //if (ai->InDuel(u))
            //    return false;
            if (!ai->IsInBotParty(u))
                return false;
            if (!me->CanSeeOrDetect(u))
                return false;
            if (!me->IsValidAssistTarget(u))
                return false;

            return true;
        }
    private:
        Unit const* me;
        float max_range;
        bot_ai const* ai;
        NearbyFriendlyUnitCheck(NearbyFriendlyUnitCheck const&);
};

class FarTauntUnitCheck
{
    public:
        explicit FarTauntUnitCheck(Unit const* unit, float maxdist, bool ally, bot_ai const* m_ai) :
        me(unit), max_range(maxdist), targetAlly(ally), ai(m_ai) { }
        bool operator()(Unit const* u) const
        {
            if (u == me)
                return false;
            if (!u->IsAlive())
                return false;
            if (!u->IsInCombat())
                return false;
            if (!u->InSamePhase(me))
                return false;
            if (u->HasUnitState(UNIT_STATE_CONFUSED|UNIT_STATE_STUNNED|UNIT_STATE_FLEEING|UNIT_STATE_DISTRACTED|UNIT_STATE_CONFUSED_MOVE))
                return false;
            if (!u->GetVictim() || u->GetVictim() == me)
                return false;
            if (!u->CanHaveThreatList())
                return false;
            if (u->HasAuraType(SPELL_AURA_MOD_TAUNT))
                return false;
            if (!ai->IsInBotParty(u->GetVictim()))
                return false;
            if (ai->GetBotClass() == BOT_CLASS_WARRIOR && u->IsImmunedToSpell(sSpellMgr->GetSpellInfo(355), me))
                return false; //taunt
            else if (ai->GetBotClass() == BOT_CLASS_PALADIN && u->IsImmunedToSpell(sSpellMgr->GetSpellInfo(62124), me))
                return false; //HoR
            else if (ai->GetBotClass() == BOT_CLASS_DRUID && u->IsImmunedToSpell(sSpellMgr->GetSpellInfo(6795), me))
                return false; //Growl

            if (!me->IsValidAttackTarget(u) || !u->isTargetableForAttack(false))
                return false;

            if (me->GetDistance(targetAlly ? u->GetVictim() : u) > max_range)
                return false;

            if (ai->IsTank(u->GetVictim()))
            {
                if (!ai->IsTank(me))
                    return false;

                const bool isofftank = ai->IsOffTank(me);
                const bool vofftank = ai->IsOffTank(u->GetVictim());
                if (isofftank && (vofftank || !ai->IsPointedOffTankingTarget(u)))
                    return false;
                else if (!isofftank && vofftank && !ai->IsPointedTankingTarget(u))
                    return false;
            }

            return true;
        }
    private:
        const Unit* const me;
        const float max_range;
        const bool targetAlly;
        const bot_ai* const ai;
        FarTauntUnitCheck(FarTauntUnitCheck const&);
};

class ManaDrainUnitCheck
{
    public:
        explicit ManaDrainUnitCheck(Unit const* unit, float maxdist, bot_ai const* ai) : me(unit), max_range(maxdist), ai(ai)
        { maxPool = me->GetMaxPower(POWER_MANA) * 3 / 2; free = ai->IAmFree(); }
        bool operator()(Unit const* u)
        {
            if (!_botPvP && me->IsPvP() && u->IsControlledByPlayer())
                return false;
            if (u == me)
                return false;
            if (!u->IsAlive())
                return false;
            if (!u->IsInCombat())
                return false;
            if (!u->InSamePhase(me))
                return false;
            if (u->GetTypeId() == TYPEID_PLAYER && !u->HasUnitState(UNIT_STATE_CONFUSED|UNIT_STATE_STUNNED|UNIT_STATE_FLEEING|UNIT_STATE_DISTRACTED|UNIT_STATE_CONFUSED_MOVE))
                return false;
            //if (u->IsControlledByPlayer())
            //    return false;
            if (free)
            {
                if (!me->IsValidAttackTarget(u) || !u->isTargetableForAttack())
                    return false;
                if (ai->IsInBotParty(u))
                    return false;
            }
            //if (ai->InDuel(u))
            //    return false;
            if (u->GetPowerType() != POWER_MANA)
                return false;
            if (u->GetMaxPower(POWER_MANA) < maxPool)
                return false;
            if (u->GetPower(POWER_MANA)*10/(u->GetMaxPower(POWER_MANA)/10) < 15)
                return false;
            if (!me->HasInArc(float(M_PI)*0.5f, u))
                return false;
            if (me->GetDistance(u) > max_range)
                return false;

            maxPool = u->GetMaxPower(POWER_MANA);
            return true;
        }
    private:
        Unit const* me;
        float max_range;
        bot_ai const* ai;
        uint32 maxPool;
        bool free;
        ManaDrainUnitCheck(ManaDrainUnitCheck const&);
};

class NearbyRezTargetCheck
{
    public:
        explicit NearbyRezTargetCheck(Unit const* unit, float maxdist, bot_ai const* m_ai) : me(unit), max_range(maxdist), ai(m_ai) { }
        bool operator()(WorldObject const* u) const
        {
            if (u == me)
                return false;
            if (u->GetTypeId() != TYPEID_PLAYER && u->GetTypeId() != TYPEID_CORPSE)
                return false;
            if (!u->InSamePhase(me))
                return false;
            if (!me->IsWithinDistInMap(u, max_range))
                return false;
            if (!me->CanSeeOrDetect(u))
                return false;
            if (Player const* p = u->IsPlayer() ? u->ToPlayer() : ObjectAccessor::FindPlayer(u->ToCorpse()->GetOwnerGUID()))
            {
                if (p->IsAlive())
                    return false;
                if (p->IsResurrectRequested())
                    return false;
                if (p->GetUInt32Value(PLAYER_SELF_RES_SPELL))
                    return false;
                if (!ai->IsInBotParty(p))
                    return false;
            }
            else
                return false;

            return true;
        }
    private:
        Unit const* me;
        float max_range;
        bot_ai const* ai;
        NearbyRezTargetCheck(NearbyRezTargetCheck const&);
};

class NearestLockedGameObjectInRangeCheck
{
public:
    NearestLockedGameObjectInRangeCheck(WorldObject const* unit, float range) : _unit(unit), _range(range) { }
    bool operator()(GameObject* go)
    {
        if (go->GetGOInfo()->GetLockId() &&
            !go->HasFlag(GO_FLAG_IN_USE) &&
            //go->getLootState() == GO_READY &&
            _unit->IsWithinDistInMap(go, _range))
        {
            _range = _unit->GetExactDist(go);
            return true;
        }
        return false;
    }
private:
    WorldObject const* _unit;
    float _range;

    NearestLockedGameObjectInRangeCheck(NearestLockedGameObjectInRangeCheck const&);
};

class NearestVehicleWithEmptySeatInRangeCheck
{
public:
    NearestVehicleWithEmptySeatInRangeCheck(WorldObject const* unit, float range, Unit const* exveh) : _unit(unit), _range(range), _exveh(exveh)
    { ASSERT(_unit->isType(TYPEMASK_UNIT)); }
    bool operator()(Unit* u)
    {
        if (u->GetTypeId() == TYPEID_UNIT && u->IsVehicle() && u->IsAlive() && u != _exveh &&
            u->GetVehicleKit()->GetAvailableSeatCount() > 0 && _unit->IsWithinDistInMap(u, _range))
        {
            _range = _unit->GetExactDist(u);
            return true;
        }
        return false;
    }
private:
    WorldObject const* _unit;
    float _range;
    Unit const* _exveh; //only compare, may be NULL

    NearestVehicleWithEmptySeatInRangeCheck(NearestVehicleWithEmptySeatInRangeCheck const&);
};

//Professions
class NearbyObjectBySkillCheck
{
public:
    NearbyObjectBySkillCheck(WorldObject const* checker, float const range, uint32 skillMask) :
      _checker(checker), _range(range), _skillMask(skillMask) { ASSERT(_checker->GetTypeId() == TYPEID_PLAYER); }

    bool operator()(WorldObject const* ob)
    {
        if (!_checker->IsWithinDistInMap(ob, _range))
            return false;

        if (GameObject const* go = ob->ToGameObject())
        {
            if (/*go->getLootState() == GO_READY && */go->isSpawned() && go->GetGOInfo()->GetLockId() &&
                go->IsLootAllowedFor(_checker->ToPlayer()) && _checker->CanSeeOrDetect(go) && _checker->ToPlayer()->HaveAtClient(ob))
            {
                if (LockEntry const* lockInfo = sLockStore.LookupEntry(go->GetGOInfo()->GetLockId()))
                {
                    for (uint8 i = 0; i != MAX_LOCK_CASE; ++i)
                    {
                        if (lockInfo->Type[i] == LOCK_KEY_SKILL &&
                            CheckSkill(SkillByLockType(LockType(lockInfo->Index[i]))) &&
                            lockInfo->Skill[i] <= MaxSkillForLevel(_checker->ToUnit()->GetLevel()))
                            return true;
                    }
                }
            }
        }
        else if (Creature const* cre = ob->ToCreature())
        {
            if (cre->IsVisible() && cre->getDeathState() == CORPSE && cre->HasUnitFlag(UNIT_FLAG_SKINNABLE) && cre->loot.isLooted() &&
                cre->isTappedBy(_checker->ToPlayer()) && CheckSkill(cre->GetCreatureTemplate()->GetRequiredLootSkill()))
            {
                if (int32(cre->GetLevel() < 20 ? (cre->GetLevel() - 10) * 10 : cre->GetLevel() * 5) <= int32(MaxSkillForLevel(_checker->ToUnit()->GetLevel())))
                    return true;
            }
        }
        return false;
    }
private:
    WorldObject const* _checker;
    float const _range;
    uint32 const _skillMask;

    inline bool CheckSkill(SkillType const skill) const
    {
        switch (skill)
        {
            case SKILL_MINING:
                return (_skillMask & BOT_ROLE_GATHERING_MINING);
            case SKILL_HERBALISM:
                return (_skillMask & BOT_ROLE_GATHERING_HERBALISM);
            case SKILL_SKINNING:
                return (_skillMask & BOT_ROLE_GATHERING_SKINNING);
            case SKILL_ENGINEERING:
                return (_skillMask & BOT_ROLE_GATHERING_ENGINEERING);
            default:
                return false;
        }
    }

    inline uint32 MaxSkillForLevel(uint8 const level) const
    {
        return
            level <= 20 ? 150 :
            level <= 40 ? 225 :
            level <= 60 ? 300 :
            level <= 70 ? 375 : 450;

        //return level <= 60 ? level * 5 : 300 + (((level - 60) * 15) / 2);
    }

    NearbyObjectBySkillCheck(NearbyObjectBySkillCheck const&);
};

//Autolooting
class NearbyLootableCreatureCheck
{
public:
    NearbyLootableCreatureCheck(WorldObject* checker, float const range) : _checker(checker), _range(range)
    { ASSERT(_checker->GetTypeId() == TYPEID_PLAYER); }

    bool operator()(Unit const* unit)
    {
        if (Creature const* cre = unit->ToCreature())
            if (_checker->IsWithinDistInMap(cre, _range))
                return cre->IsVisible() && cre->getDeathState() == CORPSE &&
                    cre->HasDynamicFlag(UNIT_DYNFLAG_LOOTABLE) &&
                    _checker->ToPlayer()->isAllowedToLoot(cre);
        return false;
    }
private:
    WorldObject* _checker;
    float const _range;

    NearbyLootableCreatureCheck(NearbyLootableCreatureCheck const&);
};

//AoE caster dynobject
class NearbyHostileAoEDynobjectCheck
{
    public:
        explicit NearbyHostileAoEDynobjectCheck(Unit const* unit, float maxdist) : _me(unit), _range(maxdist) { }
        bool operator()(WorldObject const* u) const
        {
            DynamicObject const* dObj = u->ToDynObject();
            if (!dObj || !dObj->GetSpellId() || !dObj->GetCaster())
                return false;
            if (dObj->GetByteValue(DYNAMICOBJECT_BYTES, 0) != DYNAMIC_OBJECT_AREA_SPELL)
                return false;
            if (!dObj->InSamePhase(_me))
                return false;
            if (!dObj->GetRadius())
                return false;
            if (!dObj->IsWithinDistInMap(_me, _range))
                return false;
            if (!dObj->GetCaster()->IsValidAttackTarget(_me))
                return false;

            return true;
        }
    private:
        Unit const* _me;
        float _range;
        NearbyHostileAoEDynobjectCheck(NearbyHostileAoEDynobjectCheck const&);
};

namespace BOTAI_PRED
{
    class HealTargetExclude
    {
        public:
            bool operator()(Unit const* target)
            {
                return target->IsSummon() || target->IsTotem() || (target->GetHealthPct() > 90 && target->GetMaxHealth() - target->GetHealth() < 500);
            }
    };
    class BuffTargetExclude
    {
        public:
            bool operator()(Unit const* target)
            {
                return target->IsSummon() || target->IsTotem();
            }
    };
    class DrainTargetExclude
    {
        public:
            bool operator()(Unit const* target)
            {
                return target->IsTotem() || target->GetPowerType() != POWER_MANA || target->GetPower(POWER_MANA) < 1000;
            }
    };
    class UnitExclude
    {
        public:
            UnitExclude(Unit const* unit) { _unit = unit; }
            bool operator()(Unit const* target)
            {
                return target == _unit;
            }
        private:
            Unit const* _unit;
    };

    class AuraedTargetExclude
    {
        public:
            AuraedTargetExclude(uint32 spellId, uint8 minstacks = 0) : _spellId(spellId), _minstacks(minstacks) {}
            bool operator()(Unit const* target)
            {
                AuraApplication const* aurApp = target->GetAuraApplicationOfRankedSpell(_spellId);
                return aurApp && (!_minstacks || aurApp->GetBase()->GetStackAmount() >= _minstacks);
            }
        private:
            uint32 _spellId;
            uint8 _minstacks;
    };

    class AuraedTargetExcludeByCaster
    {
        public:
            AuraedTargetExcludeByCaster(uint32 spellId, ObjectGuid caster, uint8 minstacks = 0) :
                _spellId(spellId), _caster(caster), _minstacks(minstacks) {}
            bool operator()(Unit const* target)
            {
                AuraApplication const* aurApp = target->GetAuraApplicationOfRankedSpell(_spellId, _caster);
                return aurApp && (!_minstacks || aurApp->GetBase()->GetStackAmount() >= _minstacks);
            }
        private:
            uint32 _spellId;
            ObjectGuid _caster;
            uint8 _minstacks;
    };

    class HpPctAboveExclude
    {
        public:
        HpPctAboveExclude(float pct) : _pct(pct) {}
            bool operator()(Unit const* target)
            {
                return target->GetHealthPct() > _pct;
            }
        private:
            float _pct;
    };

    class UnitCombatStateExclude
    {
        public:
        UnitCombatStateExclude(bool combat) : _combat(combat) {}
            bool operator()(Unit const* target)
            {
                return target->IsInCombat() == _combat;
            }
        private:
            bool _combat;
    };

    class UnitLivingStateExclude
    {
        public:
        UnitLivingStateExclude(bool living) : _living(living) {}
            bool operator()(Unit const* target)
            {
                return target->IsAlive() == _living;
            }
        private:
            bool _living;
    };
};

#endif

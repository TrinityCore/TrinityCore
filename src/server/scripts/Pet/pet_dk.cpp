/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

/*
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "npc_pet_dk_".
 */

#include "ScriptMgr.h"
#include "CombatAI.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "ObjectAccessor.h"

enum DeathKnightSpells
{
    SPELL_DK_SUMMON_GARGOYLE_1          = 49206,
    SPELL_DK_SUMMON_GARGOYLE_2          = 50514,
    SPELL_DK_DISMISS_GARGOYLE           = 50515,
    SPELL_DK_SANCTUARY                  = 54661,

    // Dancing Rune Weapon
    SPELL_DK_DANCING_RUNE_WEAPON        = 49028,
    SPELL_COPY_WEAPON                   = 63416,
    SPELL_DK_RUNE_WEAPON_MARK           = 50474,
    SPELL_DK_DANCING_RUNE_WEAPON_VISUAL = 53160,
    SPELL_FAKE_AGGRO_RADIUS_8_YARD      = 49812,
    SPELL_AGGRO_8_YD_PBAE               = 49813
};

class npc_pet_dk_ebon_gargoyle : public CreatureScript
{
    public:
        npc_pet_dk_ebon_gargoyle() : CreatureScript("npc_pet_dk_ebon_gargoyle") { }

        struct npc_pet_dk_ebon_gargoyleAI : CasterAI
        {
            npc_pet_dk_ebon_gargoyleAI(Creature* creature) : CasterAI(creature) { }

            void InitializeAI() override
            {
                CasterAI::InitializeAI();
                ObjectGuid ownerGuid = me->GetOwnerGUID();
                if (!ownerGuid)
                    return;

                // Find victim of Summon Gargoyle spell
                std::list<Unit*> targets;
                Trinity::AnyUnfriendlyUnitInObjectRangeCheck u_check(me, me, 30.0f);
                Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(me, targets, u_check);
                Cell::VisitAllObjects(me, searcher, 30.0f);
                for (std::list<Unit*>::const_iterator iter = targets.begin(); iter != targets.end(); ++iter)
                    if ((*iter)->HasAura(SPELL_DK_SUMMON_GARGOYLE_1, ownerGuid))
                    {
                        me->Attack((*iter), false);
                        break;
                    }
            }

            void JustDied(Unit* /*killer*/) override
            {
                // Stop Feeding Gargoyle when it dies
                if (Unit* owner = me->GetOwner())
                    owner->RemoveAurasDueToSpell(SPELL_DK_SUMMON_GARGOYLE_2);
            }

            // Fly away when dismissed
            void SpellHit(Unit* source, SpellInfo const* spell) override
            {
                if (spell->Id != SPELL_DK_DISMISS_GARGOYLE || !me->IsAlive())
                    return;

                Unit* owner = me->GetOwner();
                if (!owner || owner != source)
                    return;

                // Stop Fighting
                me->ApplyModFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE, true);

                // Sanctuary
                me->CastSpell(me, SPELL_DK_SANCTUARY, true);
                me->SetReactState(REACT_PASSIVE);

                //! HACK: Creature's can't have MOVEMENTFLAG_FLYING
                // Fly Away
                me->SetCanFly(true);
                me->SetSpeedRate(MOVE_FLIGHT, 0.75f);
                me->SetSpeedRate(MOVE_RUN, 0.75f);
                float x = me->GetPositionX() + 20 * std::cos(me->GetOrientation());
                float y = me->GetPositionY() + 20 * std::sin(me->GetOrientation());
                float z = me->GetPositionZ() + 40;
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MovePoint(0, x, y, z);

                // Despawn as soon as possible
                me->DespawnOrUnsummon(Seconds(4));
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_pet_dk_ebon_gargoyleAI(creature);
        }
};

class npc_pet_dk_guardian : public CreatureScript
{
    public:
        npc_pet_dk_guardian() : CreatureScript("npc_pet_dk_guardian") { }

        struct npc_pet_dk_guardianAI : public AggressorAI
        {
            npc_pet_dk_guardianAI(Creature* creature) : AggressorAI(creature) { }

            bool CanAIAttack(Unit const* target) const override
            {
                if (!target)
                    return false;
                Unit* owner = me->GetOwner();
                if (owner && !target->IsInCombatWith(owner))
                    return false;
                return AggressorAI::CanAIAttack(target);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_pet_dk_guardianAI(creature);
        }
};

enum DancingRuneWeapon
{
    DATA_INITIAL_TARGET_GUID    = 1,

    EVENT_ENGAGE_VICTIM         = 1
};

struct npc_pet_dk_rune_weapon : public ScriptedAI
{
    npc_pet_dk_rune_weapon(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        // Prevent early victim engage
        me->SetReactState(REACT_PASSIVE);
        _events.ScheduleEvent(EVENT_ENGAGE_VICTIM, 1s);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        DoCast(summoner, SPELL_COPY_WEAPON, true);
        DoCast(summoner, SPELL_DK_RUNE_WEAPON_MARK, true);
        DoCast(me, SPELL_DK_DANCING_RUNE_WEAPON_VISUAL, true);
        DoCast(me, SPELL_FAKE_AGGRO_RADIUS_8_YARD, true);

        me->GetThreatManager().RegisterRedirectThreat(SPELL_DK_DANCING_RUNE_WEAPON, summoner->GetGUID(), 100);
    }

    void SetGUID(ObjectGuid const& guid, int32 id) override
    {
        if (id == DATA_INITIAL_TARGET_GUID)
        {
            _targetGUID = guid;
            if (Unit *target = ObjectAccessor::GetUnit(*me, _targetGUID))
                AttackStart(target);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (me->IsInCombat() && (!me->GetVictim() || !me->IsValidAttackTarget(me->GetVictim())))
            EnterEvadeMode(EVADE_REASON_NO_HOSTILES);

        _events.Update(diff);

        while (uint32 _eventId = _events.ExecuteEvent())
        {
            switch (_eventId)
            {
                case EVENT_ENGAGE_VICTIM:
                    me->SetReactState(REACT_AGGRESSIVE);
            }
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        if (me->IsInEvadeMode() || !me->IsAlive())
            return;

        Unit* owner = me->GetCharmerOrOwner();

        me->CombatStop(true);
        if (owner && !me->HasUnitState(UNIT_STATE_FOLLOW))
        {
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MoveFollow(owner, PET_FOLLOW_DIST, me->GetFollowAngle());
        }
    }

private:
    ObjectGuid _targetGUID;
    EventMap _events;
};

class spell_pet_dk_gargoyle_strike : public SpellScript
{
    PrepareSpellScript(spell_pet_dk_gargoyle_strike);

    void HandleDamageCalc(SpellEffIndex /*effIndex*/)
    {
        int32 damage = 60;
        if (Unit* caster = GetCaster())
        {
            if (caster->getLevel() >= 60)
                damage += (caster->getLevel() - 60) * 4;
        }

        SetHitDamage(damage);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_pet_dk_gargoyle_strike::HandleDamageCalc, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

void AddSC_deathknight_pet_scripts()
{
    new npc_pet_dk_ebon_gargoyle();
    new npc_pet_dk_guardian();
    RegisterCreatureAI(npc_pet_dk_rune_weapon);
    RegisterSpellScript(spell_pet_dk_gargoyle_strike);
}

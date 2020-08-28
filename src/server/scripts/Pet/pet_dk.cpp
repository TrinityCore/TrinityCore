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

enum DeathKnightSpells
{
    SPELL_DK_SUMMON_GARGOYLE_1      = 49206,
    SPELL_DK_SUMMON_GARGOYLE_2      = 50514,
    SPELL_DK_DISMISS_GARGOYLE       = 50515,
    SPELL_DK_SANCTUARY              = 54661
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
                ObjectGuid ownerGuid = me->GetOwnerOrCreatorGUID();
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
                me->GetMotionMaster()->Clear(false);
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

enum GhoulSpells
{
    // Dark Transformation
    SPELL_PET_DARK_TRANSFORMATION   = 63560,

    // Gnaw
    SPELL_PET_GNAW_DUMMY            = 47481,
    SPELL_PET_GNAW_DAMAGE           = 91800,
    SPELL_PET_MONSTROUS_BLOW        = 91797,

    // Leap
    SPELL_PET_LEAP_DUMMY            = 47482,
    SPELL_PET_LEAP_EFFECT           = 91809,
    SPELL_PET_SHAMBLING_RUSH        = 91802,

    // Claw
    SPELL_PET_CLAW_DUMMY            = 47468,
    SPELL_PET_CLAW_DAMAGE           = 91776,
    SPELL_PET_SWEEPING_CLAWS        = 91778,

    // Huddle
    SPELL_PET_HUDDLE_DUMMY          = 47484,
    SPELL_PET_HUDDLE_EFFECT         = 91838,
    SPELL_PET_PUTRID_BULWARK        = 91837,
};

class spell_pet_ghoul_dummy_ability : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_PET_DARK_TRANSFORMATION,
                SPELL_PET_GNAW_DUMMY,
                SPELL_PET_GNAW_DAMAGE,
                SPELL_PET_MONSTROUS_BLOW,
                SPELL_PET_LEAP_DUMMY,
                SPELL_PET_LEAP_EFFECT,
                SPELL_PET_SHAMBLING_RUSH,
                SPELL_PET_CLAW_DUMMY,
                SPELL_PET_CLAW_DAMAGE,
                SPELL_PET_SWEEPING_CLAWS,
                SPELL_PET_HUDDLE_DUMMY,
                SPELL_PET_HUDDLE_EFFECT,
                SPELL_PET_PUTRID_BULWARK
            });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            bool isTransformed = caster->HasAura(SPELL_PET_DARK_TRANSFORMATION);
            switch (GetSpellInfo()->Id)
            {
                case SPELL_PET_GNAW_DUMMY:
                    caster->CastSpell(GetHitUnit(), isTransformed ? SPELL_PET_MONSTROUS_BLOW : SPELL_PET_GNAW_DAMAGE, true);
                    break;
                case SPELL_PET_LEAP_DUMMY:
                    caster->CastSpell(GetHitUnit(), isTransformed ? SPELL_PET_SHAMBLING_RUSH : SPELL_PET_LEAP_EFFECT, true);
                    break;
                case SPELL_PET_CLAW_DUMMY:
                    caster->CastSpell(GetHitUnit(), isTransformed ? SPELL_PET_SWEEPING_CLAWS : SPELL_PET_CLAW_DAMAGE, true);
                    break;
                case SPELL_PET_HUDDLE_DUMMY:
                    caster->CastSpell(GetHitUnit(), isTransformed ? SPELL_PET_PUTRID_BULWARK : SPELL_PET_HUDDLE_EFFECT, true);
                    break;
                default:
                    break;
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_pet_ghoul_dummy_ability::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

enum ArmyOfTheDead
{
    SPELL_BIRTH                         = 7398,
    SPELL_PERIODIC_TAUNT                = 43264,
    SPELL_DEATH_KNIGHT_PET_SCALING_2    = 51996,
    SPELL_DEATH_KNIGHT_PET_SCALING_3    = 61697,
    SPELL_DEATH_KNIGHT_PET_SCALING_5    = 110474,

    EVENT_ALLOW_ATTACKS                 = 1,
    EVENT_LEAP,
    EVENT_CLAW
};

struct npc_pet_dk_army_of_the_dead_ghoul : public AggressorAI
{
    npc_pet_dk_army_of_the_dead_ghoul(Creature* creature) : AggressorAI(creature), _readyToAttack(false) { }


    void IsSummonedBy(Unit* summoner) override
    {
        DoCastSelf(SPELL_DEATH_KNIGHT_PET_SCALING_2);
        DoCastSelf(SPELL_DEATH_KNIGHT_PET_SCALING_3);
        DoCastSelf(SPELL_DEATH_KNIGHT_PET_SCALING_5);
        DoCastSelf(SPELL_BIRTH);
        me->AddUnitState(UNIT_STATE_ROOT);
        me->FollowTarget(summoner);
        _events.ScheduleEvent(EVENT_ALLOW_ATTACKS, 4s);
    }

    bool CanAIAttack(Unit const* target) const override
    {
        if (!target)
            return false;

        if (!_readyToAttack)
            return false;

        return AggressorAI::CanAIAttack(target);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && _readyToAttack)
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ALLOW_ATTACKS:
                    _readyToAttack = true;
                    me->ClearUnitState(UNIT_STATE_ROOT);
                    DoCastSelf(SPELL_PERIODIC_TAUNT);
                    _events.ScheduleEvent(EVENT_LEAP, 1ms);
                    _events.ScheduleEvent(EVENT_CLAW, 2s + 500ms);
                    break;
                case EVENT_LEAP:
                    DoCastVictim(SPELL_PET_LEAP_DUMMY, true);
                    break;
                case EVENT_CLAW:
                    DoCastVictim(SPELL_PET_CLAW_DUMMY, true);
                    _events.Repeat(7s, 8s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    EventMap _events;
    bool _readyToAttack;
};

void AddSC_deathknight_pet_scripts()
{
    new npc_pet_dk_ebon_gargoyle();
    new npc_pet_dk_guardian();
    RegisterCreatureAI(npc_pet_dk_army_of_the_dead_ghoul);
    RegisterSpellScript(spell_pet_ghoul_dummy_ability);
}

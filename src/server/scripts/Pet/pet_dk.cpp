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
    SPELL_DK_SUMMON_GARGOYLE_1  = 49206,
    SPELL_DK_SUMMON_GARGOYLE_2  = 50514,
    SPELL_DK_DISMISS_GARGOYLE   = 50515,
    SPELL_DK_SANCTUARY          = 54661,
    SPELL_DK_GARGOYLE_STRIKE    = 51963
};

enum DeathKnightEvents
{
    EVENT_INTERRUPT_OVER = 1
};

class npc_pet_dk_ebon_gargoyle : public CreatureScript
{
    public:
        npc_pet_dk_ebon_gargoyle() : CreatureScript("npc_pet_dk_ebon_gargoyle") { }

        struct npc_pet_dk_ebon_gargoyleAI : ScriptedAI
        {
            npc_pet_dk_ebon_gargoyleAI(Creature* creature) : ScriptedAI(creature) { }

            void InitializeAI() override
            {
                targetFound     = false;
                interrupted     = false;
                EnableSpellCast = false;
                despawnTimer    = 0   * IN_MILLISECONDS;
                spellCastTime   = urand(2, 3) * IN_MILLISECONDS;  
                initStatTimer   = 0.1 * IN_MILLISECONDS;                
            }

            void JustDied(Unit* /*killer*/) override
            {
                // Stop Feeding Gargoyle when it dies
                if (Unit* owner = me->GetOwner())
                    owner->RemoveAurasDueToSpell(SPELL_DK_SUMMON_GARGOYLE_2);
            }

            void IsInteruptSpell(SpellInfo const* spell)
            {
                if (spell->HasEffect(SPELL_EFFECT_INTERRUPT_CAST))
                {
                    interrupted = true;
                    events.ScheduleEvent(EVENT_INTERRUPT_OVER, 20s);
                }
            }

            bool CheckCast()
            {
                if (me->IsWithinMeleeRange(me->GetVictim()))
                    return roll_chance_i(40);
                else
                    return false;
            }

            // Fly away when dismissed
            void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
            {
                IsInteruptSpell(spellInfo);

                if (spellInfo->Id != SPELL_DK_DISMISS_GARGOYLE || !me->IsAlive())
                    return;

                Unit* owner = me->GetOwner();
                if (!owner || owner != caster)
                    return;

                // Stop Fighting
                me->ApplyModFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE, true);

                // Sanctuary
                DoCastSelf(SPELL_DK_SANCTUARY, true);
                me->SetReactState(REACT_PASSIVE);

                //! HACK: Creature's can't have MOVEMENTFLAG_FLYING
                // Fly Away
                me->AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_ASCENDING | MOVEMENTFLAG_FLYING);
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

            void UpdateAI(uint32 diff) override
            {
                events.Update(diff);

                if (despawnTimer > 0)
                {
                    if (despawnTimer > diff)
                        despawnTimer -= diff;
                    else
                        me->DespawnOrUnsummon();

                    return;
                }

                if (spellCastTime <= diff)
                {
                    if (!EnableSpellCast)
                        EnableSpellCast = true;
                }
                else 
                    spellCastTime -= diff;

                if (initStatTimer <= diff)
                {
                    if (Unit* owner = me->GetOwner())
                    {
                        me->SetMaxHealth(uint32(owner->GetMaxHealth() * 0.8f));
                        me->SetHealth(me->GetMaxHealth());
                    }
                    initStatTimer = 120 * IN_MILLISECONDS;
                }    
                else
                    initStatTimer -= diff;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_INTERRUPT_OVER:
                            interrupted = false;
                            break;
                        default:
                            break;
                    }
                }

                Unit* owner = me->GetOwner();
                if (!owner || owner->GetTypeId() != TYPEID_PLAYER)
                    return;

                if (Unit* ownerPet = owner->ToPlayer())
                    AttackStart(ownerPet->GetVictim() ? ownerPet->GetVictim() : NULL);
                else
                {
                    if (Player* player = me->GetOwner() ? me->GetOwner()->ToPlayer() : NULL)
                        if (Unit* target = player->GetSelectedUnit())
                            if (target->IsHostileTo(owner))
                                AttackStart(target);
                }

                if (!targetFound)
                {
                    // Find victim of Summon Gargoyle spell
                    std::list<Unit*> targets;
                    Trinity::AnyUnfriendlyUnitInObjectRangeCheck u_check(me, me, 30.0f);
                    Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(me, targets, u_check);
                    Cell::VisitAllObjects(me, searcher, 30.0f);
                    for (std::list<Unit*>::const_iterator iter = targets.begin(); iter != targets.end(); ++iter)
                        if ((*iter)->GetAura(SPELL_DK_SUMMON_GARGOYLE_1, owner->GetGUID()))
                        {
                            me->Attack((*iter), false);
                            targetFound = true;
                            break;
                        }

                    if (!targetFound)
                        return;
                }

                if (!UpdateVictim() || interrupted || !targetFound)
                    return;

                if (me->GetVictim()->HasBreakableByDamageCrowdControlAura(me))
                {
                    me->InterruptNonMeleeSpells(false);
                    return;
                }

                if (CheckCast())
                    DoMeleeAttackIfReady();
                else if (!me->HasUnitState(UNIT_STATE_CASTING) && EnableSpellCast)
                    DoCastVictim(SPELL_DK_GARGOYLE_STRIKE);
            }

        private:
            bool interrupted;
            bool targetFound;
            bool EnableSpellCast;
            uint32 despawnTimer;
            uint32 spellCastTime;
            uint32 initStatTimer;
            EventMap events;
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

class spell_pet_dk_gargoyle_strike : public SpellScript
{
    PrepareSpellScript(spell_pet_dk_gargoyle_strike);

    void HandleDamageCalc(SpellEffIndex /*effIndex*/)
    {
        int32 damage = 60;
        if (Unit* caster = GetCaster())
        {
            if (caster->GetLevel() >= 60)
                damage += (caster->GetLevel() - 60) * 4;
        }

        SetEffectValue(damage);
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_pet_dk_gargoyle_strike::HandleDamageCalc, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

void AddSC_deathknight_pet_scripts()
{
    new npc_pet_dk_ebon_gargoyle();
    new npc_pet_dk_guardian();
    RegisterSpellScript(spell_pet_dk_gargoyle_strike);
}

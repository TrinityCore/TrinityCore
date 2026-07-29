/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
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
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Creature.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "EventMap.h"
#include "MotionMaster.h"
#include "PassiveAI.h"
#include "SpellInfo.h"
#include "GridNotifiersImpl.h"
#include "Cell.h"

#include "Custom_Monk_Defines.h"

namespace Custom::Monk
{
    // Jade Serpent Statue - 60849
    struct npc_monk_jade_serpent_statue : public PassiveAI
    {
        npc_monk_jade_serpent_statue(Creature* creature) : PassiveAI(creature) { }

        void Reset() override
        {
            me->SetReactState(REACT_PASSIVE);
            _currentTargetGuid.Clear();
            _pendingTargetGuid.Clear();
            _events.Reset();
            _events.ScheduleEvent(Events::CHECK_OWNER_SPELL, 500ms);
            _events.ScheduleEvent(Events::FOLLOW_OWNER, 500ms);

            if (Unit* owner = me->GetOwner())
            {
                uint64 maxHealth = owner->GetMaxHealth() * 0.5f;
                me->SetMaxHealth(maxHealth);
                me->SetHealth(maxHealth);
            }
        }

        void SetGUID(ObjectGuid const& guid, int32 /*id*/) override
        {
            _pendingTargetGuid = guid;
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case Events::FOLLOW_OWNER:
                {
                    if (Unit* owner = me->GetOwner())
                        me->GetMotionMaster()->MoveFollow(owner, 10.0f, frand(0.0f, float(M_PI) * 2));

                    break;
                }
                case Events::CHECK_OWNER_SPELL:
                {
                    Unit* owner = me->GetOwner();
                    if (!owner || !owner->IsInWorld())
                    {
                        if (me->FindCurrentSpellBySpellId(Spells::SOOTHING_MIST_STATUE))
                            me->InterruptNonMeleeSpells(true, Spells::SOOTHING_MIST_STATUE);
                        _currentTargetGuid.Clear();
                        me->DespawnOrUnsummon();
                        break;
                    }

                    if (!owner->FindCurrentSpellBySpellId(Spells::SOOTHING_MIST_OWNER))
                    {
                        if (me->FindCurrentSpellBySpellId(Spells::SOOTHING_MIST_STATUE))
                            me->InterruptNonMeleeSpells(true, Spells::SOOTHING_MIST_STATUE);
                        _currentTargetGuid.Clear();
                        _pendingTargetGuid.Clear();
                        _events.ScheduleEvent(Events::CHECK_OWNER_SPELL, 500ms);
                        break;
                    }

                    ObjectGuid targetGuid = owner->IsPlayer() ? owner->GetTarget() : _pendingTargetGuid;
                    if (targetGuid.IsEmpty())
                    {
                        _events.ScheduleEvent(Events::CHECK_OWNER_SPELL, 500ms);
                        break;
                    }

                    Unit* target = ObjectAccessor::GetUnit(*me, targetGuid);
                    if (!target || !target->IsAlive())
                    {
                        if (me->FindCurrentSpellBySpellId(Spells::SOOTHING_MIST_STATUE))
                            me->InterruptNonMeleeSpells(true, Spells::SOOTHING_MIST_STATUE);
                        _currentTargetGuid.Clear();
                        _events.ScheduleEvent(Events::CHECK_OWNER_SPELL, 500ms);
                        break;
                    }

                    if (targetGuid != _currentTargetGuid)
                    {
                        if (me->FindCurrentSpellBySpellId(Spells::SOOTHING_MIST_STATUE))
                            me->InterruptNonMeleeSpells(true, Spells::SOOTHING_MIST_STATUE);
                        _currentTargetGuid = targetGuid;
                    }

                    if (!me->FindCurrentSpellBySpellId(Spells::SOOTHING_MIST_STATUE))
                    {
                        me->CastSpell(target, Spells::SOOTHING_MIST_STATUE, false);
                    }

                    _events.ScheduleEvent(Events::CHECK_OWNER_SPELL, 500ms);
                    break;
                }
                default:
                    break;
                }
            }
        }

        void OnChannelFinished(SpellInfo const* spellInfo) override
        {
            if (spellInfo && spellInfo->Id == Spells::SOOTHING_MIST_STATUE)
            {
                _currentTargetGuid.Clear();
                _pendingTargetGuid.Clear();
                me->GetMotionMaster()->Clear();
                if (Unit* owner = me->GetOwner())
                    me->GetMotionMaster()->MoveFollow(owner, 5.0f, frand(0.0f, float(M_PI) * 2));
            }
        }

        EventMap _events;
        ObjectGuid _currentTargetGuid;
        ObjectGuid _pendingTargetGuid;
    };

    // Black Ox Statue - 61146
    struct npc_monk_black_ox_statue : public PassiveAI
    {
        npc_monk_black_ox_statue(Creature* creature) : PassiveAI(creature) { }

        void Reset() override
        {
            me->CastSpell(me, Spells::BLACK_OX_STATUE_AURA, true);

            if (Unit* owner = me->GetOwner())
            {
                uint64 maxHealth = owner->GetMaxHealth() * 0.5f;
                me->SetMaxHealth(maxHealth);
                me->SetHealth(maxHealth);

                std::list<Unit*> targets;
                Trinity::AnyUnfriendlyUnitInObjectRangeCheck check(owner, owner, 10.0f);
                Trinity::UnitListSearcher searcher(owner, targets, check);
                Cell::VisitAllObjects(owner, searcher, 10.0f);
                for (Unit* target : targets)
                    me->CastSpell(target, Spells::PROVOKE, true);
            }
        }
    };
}

void AddSC_custom_monk_spell_npcs()
{
    using namespace Custom::Monk;

    RegisterCreatureAI(npc_monk_jade_serpent_statue);
    RegisterCreatureAI(npc_monk_black_ox_statue);
}

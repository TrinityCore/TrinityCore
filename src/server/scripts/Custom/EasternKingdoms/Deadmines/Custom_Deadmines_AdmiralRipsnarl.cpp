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

#include "CreatureAIImpl.h"
#include "DB2Stores.h"
#include "EventMap.h"
#include "Map.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "GridNotifiers.h"
#include "SpellInfo.h"
#include <list>

#include "Custom_Instance_Deadmines.h"

namespace Scripts::EasternKingdoms::Deadmines
{
    // 47714 - Ripsnarl Vapor
    struct npc_admiral_ripsnarl_vapor : public ScriptedAI
    {
        enum class VaporStage : uint8
        {
            Initial,
            Swirling,
            Condensing,
            Freezing
        };

        npc_admiral_ripsnarl_vapor(Creature* creature) : ScriptedAI(creature), _stage(VaporStage::Initial) { }

        void Reset() override
        {
            _events.Reset();
            _stage = VaporStage::Initial;
        }

        void IsSummonedBy(WorldObject* /*owner*/) override
        {
            if (IsHeroic())
                DoCast(me, Spells::Condensation, true);
        }

        void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
        {
            if (spellInfo->Id == Spells::CondenseStage1)
            {
                _stage = VaporStage::Swirling;
                _events.RescheduleEvent(Events::VaporSwirling, std::chrono::seconds(Ripsnarl::VaporStage1Delay));
            }
            else if (spellInfo->Id == Spells::CondenseStage2)
            {
                _stage = VaporStage::Condensing;
                _events.CancelEvent(Events::VaporSwirling);
                _events.RescheduleEvent(Events::VaporCondensing, std::chrono::seconds(Ripsnarl::VaporStage2Delay));
            }
            else if (spellInfo->Id == Spells::CondenseStage3)
            {
                _stage = VaporStage::Freezing;
                _events.CancelEvent(Events::VaporSwirling);
                _events.CancelEvent(Events::VaporCondensing);

                // Freezing Vapor does not properly remove previous auras
                // Transformation spell does not change properly if these 2 auras are not removed
                me->RemoveAura(92020);
                me->RemoveAura(92016);

                _events.RescheduleEvent(Events::VaporFreezing, std::chrono::seconds(Ripsnarl::VaporStage3Delay));
                _events.RescheduleEvent(Events::VaporCoalesce, std::chrono::seconds(Ripsnarl::VaporCoalesceDelay));
            }
        }

        void OnSpellCast(SpellInfo const* spell) override
        {
            if (spell->Id != Spells::Coalesce)
                return;

            if (InstanceScript* instance = me->GetInstanceScript())
            {
                uint32 coalesceCount = instance->GetData(Misc::RipsnarlVaporAchievement);
                if (coalesceCount < 3)
                {
                    ++coalesceCount;
                    instance->SetData(Misc::RipsnarlVaporAchievement, coalesceCount);

                    if (coalesceCount == 3)  // award exactly once, on the 3rd Coalesce
                    {
                        AchievementEntry const* achievement = sAchievementStore.LookupEntry(Achievements::ItsFrostDamage);
                        if (achievement)
                        {
                            instance->instance->DoOnPlayers([achievement](Player* player)
                                {
                                    if (!player->HasAchieved(achievement->ID))
                                        player->CompletedAchievement(achievement);
                                });
                        }
                    }
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case Events::VaporSwirling:
                        DoCastVictim(Spells::SwirlingVapor);
                        break;
                    case Events::VaporCondensing:
                        DoCastVictim(Spells::CondensingVapor);
                        break;
                    case Events::VaporFreezing:
                        DoCastVictim(Spells::FreezingVapor);
                        break;
                    case Events::VaporCoalesce:
                        if (_stage == VaporStage::Freezing)
                            DoCastSelf(Spells::Coalesce);
                        break;
                    default:
                        break;
                }
            }

            me->DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
        VaporStage _stage;
    };

    // 47626 - Admiral Ripsnarl
    struct boss_admiral_ripsnarl : public BossAI
    {
        boss_admiral_ripsnarl(Creature* creature) : BossAI(creature, DataTypes::BOSS_ADMIRAL_RIPSNARL), _summons(creature)
        {
            ApplyCrowdControlImmunities(creature);
            me->setActive(true);
        }

        void Reset() override
        {
            BossAI::Reset();
            _events.Reset();
            _summons.DespawnAll();

            _below75 = false;
            _below50 = false;
            _below25 = false;
            _below10 = false;
            _inFog = false;

            me->SetVisible(true);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_UNINTERACTIBLE | UNIT_FLAG_PACIFIED));
            me->SetReactState(REACT_AGGRESSIVE);
            SetFog(false);

            if (instance)
                instance->SetData(Misc::RipsnarlFogActive, 0);
        }

        void JustEngagedWith(Unit* who) override
        {
            BossAI::JustEngagedWith(who);
            Talk(Texts::RipsnarlAggro);
            DoZoneInCombat();

            DoCast(me, Spells::ThirstForBlood);
            if (instance)
                instance->DoRemoveAurasDueToSpellOnPlayers(Spells::RipsnarlAchievement);
            _events.ScheduleEvent(Events::RipsnarlSwipe, std::chrono::seconds(Ripsnarl::SwipeTimer));

            if (IsHeroic())
                _events.ScheduleEvent(Events::RipsnarlGoForThroat, std::chrono::seconds(Ripsnarl::GoForThroatTimer));
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
        {
            if (_inFog)
                return;

            if (!_below75 && me->HealthBelowPctDamaged(Ripsnarl::FogPhasePct75, damage))
            {
                _below75 = true;
                EnterFogPhase();
            }
            else if (!_below50 && me->HealthBelowPctDamaged(Ripsnarl::FogPhasePct50, damage))
            {
                _below50 = true;
                EnterFogPhase();
            }
            else if (!_below25 && me->HealthBelowPctDamaged(Ripsnarl::FogPhasePct25, damage))
            {
                _below25 = true;
                EnterFogPhase();
            }

            // Heroic: below 10% three additional Vapors form from the fog
            if (IsHeroic() && !_below10 && me->HealthBelowPctDamaged(Ripsnarl::HeroicVaporPhasePct, damage))
            {
                _below10 = true;
                Talk(Texts::RipsnarlAnnounceVapor);
                for (uint8 i = 0; i < 3; ++i)
                    me->SummonCreature(Creatures::Vapor, Positions::RipsnarlVaporFinalSpawn[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10s);
            }
        }

        void JustSummoned(Creature* summon) override
        {
            _summons.Summon(summon);

            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                summon->AI()->AttackStart(target);
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            _summons.Despawn(summon);
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim)
                Talk(Texts::RipsnarlKill);
        }

        void JustDied(Unit* killer) override
        {
            BossAI::JustDied(killer);

            _events.Reset();
            Talk(Texts::RipsnarlDeath);
            _summons.DespawnAll();
            SetFog(false);

            _inFog = false;
            me->SetVisible(true);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_UNINTERACTIBLE | UNIT_FLAG_PACIFIED));

            if (instance)
            {
                instance->SetData(Misc::RipsnarlFogActive, 0);
                instance->DoRemoveAurasDueToSpellOnPlayers(Spells::RipsnarlAchievement);
            }

            me->SummonCreature(Creatures::CaptainCookie, Positions::RipsnarlCaptainCookieSpawn, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 120s);
        }

        void UpdateAI(uint32 diff) override
        {
            // Update events before the UpdateVictim() check so timed events (e.g. the fog reveal)
            // still fire while the boss is in his victimless, non-attackable fog phase.
            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case Events::RipsnarlSwipe:
                        if (Unit* victim = me->GetVictim())
                            me->CastSpell(victim, Spells::Swipe);
                        _events.ScheduleEvent(Events::RipsnarlSwipe, std::chrono::seconds(Ripsnarl::SwipeTimer));
                        break;
                    case Events::RipsnarlGoForThroat:
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, false))
                        {
                            Talk(Texts::RipsnarlGoForThroat);
                            me->CastSpell(target, Spells::GoForTheThroat);
                        }
                        if (IsHeroic())
                            _events.ScheduleEvent(Events::RipsnarlGoForThroat, std::chrono::seconds(Ripsnarl::GoForThroatTimer));
                        break;
                    case Events::RipsnarlSummonVapor:
                        if (_inFog)
                        {
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, false))
                                me->CastSpell(target, Spells::SummonVapor);
                            _events.ScheduleEvent(Events::RipsnarlSummonVapor, std::chrono::seconds(Ripsnarl::SummonVaporTimer));
                        }
                        break;
                    case Events::RipsnarlReveal:
                        RevealFromFog();
                        break;
                }
            }

            if (!UpdateVictim())
                return;

            me->DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
        SummonList _summons;
        bool _below75 = false;
        bool _below50 = false;
        bool _below25 = false;
        bool _below10 = false;
        bool _inFog = false;

        void EnterFogPhase()
        {
            _inFog = true;

            me->AttackStop();
            me->SetReactState(REACT_PASSIVE);
            me->SetUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_UNINTERACTIBLE | UNIT_FLAG_PACIFIED));
            me->SetVisible(false);
            me->RemoveAurasDueToSpell(Spells::ThirstForBloodAura);

            _events.CancelEvent(Events::RipsnarlSwipe);
            _events.CancelEvent(Events::RipsnarlGoForThroat);

            Talk(Texts::RipsnarlFog);

            SetFog(true);
            if (instance)
                instance->SetData(Misc::RipsnarlFogActive, 1);

            _events.ScheduleEvent(Events::RipsnarlSummonVapor, std::chrono::seconds(Ripsnarl::SummonVaporTimer));
            _events.ScheduleEvent(Events::RipsnarlReveal, std::chrono::seconds(Ripsnarl::RevealTimer));
        }

        void RevealFromFog()
        {
            _inFog = false;

            _events.CancelEvent(Events::RipsnarlSummonVapor);

            SetFog(false);
            if (instance)
                instance->SetData(Misc::RipsnarlFogActive, 0);

            me->SetVisible(true);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_UNINTERACTIBLE | UNIT_FLAG_PACIFIED));
            me->SetReactState(REACT_AGGRESSIVE);

            // Go For the Throat on reveal: leap at a random enemy
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, false))
            {
                Talk(Texts::RipsnarlGoForThroat);
                AttackStart(target);
                me->CastSpell(target, Spells::GoForTheThroat);
            }

            DoCast(me, Spells::ThirstForBlood);
            _events.ScheduleEvent(Events::RipsnarlSwipe, std::chrono::seconds(Ripsnarl::SwipeTimer));

            if (IsHeroic())
                _events.ScheduleEvent(Events::RipsnarlGoForThroat, std::chrono::seconds(Ripsnarl::GoForThroatTimer));
        }

        void SetFog(bool apply)
        {
            ApplyFogToBunnies(Creatures::GeneralPurposeBunny, Spells::RipsnarlFogVisualSmall, apply);
            ApplyFogToBunnies(Creatures::GeneralPurposeBunnyJMF, Spells::RipsnarlFogVisualLarge, apply);
        }

        void ApplyFogToBunnies(uint32 bunnyEntry, uint32 fogSpell, bool apply)
        {
            std::list<Creature*> bunnies;
            me->GetCreatureListWithEntryInGrid(bunnies, bunnyEntry, Ripsnarl::FogBunnyRange);
            for (Creature* bunny : bunnies)
            {
                if (!bunny)
                    continue;

                if (apply)
                    bunny->CastSpell(bunny, fogSpell, true);
                else
                    bunny->RemoveAurasDueToSpell(fogSpell);
            }
        }
    };
}

void AddSC_custom_deadmines_admiral_ripsnarl()
{
    using namespace Scripts::EasternKingdoms::Deadmines;

    RegisterCreatureAI(boss_admiral_ripsnarl);
    RegisterCreatureAI(npc_admiral_ripsnarl_vapor);
}

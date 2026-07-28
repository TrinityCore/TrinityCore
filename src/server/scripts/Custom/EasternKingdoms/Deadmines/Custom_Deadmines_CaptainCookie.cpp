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

#include "AchievementMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "DB2Stores.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Containers.h"
#include "SpellAuras.h"
#include "SpellScript.h"

#include "Custom_Instance_Deadmines.h"

namespace Scripts::EasternKingdoms::Deadmines
{
    static constexpr uint32 ThrowFoodSpells[12] =
    {
        Spells::ThrowFood01,
        Spells::ThrowFood02,
        Spells::ThrowFood03,
        Spells::ThrowFood04,
        Spells::ThrowFood05,
        Spells::ThrowFood06,
        //Spells::ThrowFood07, This is the food spell with murloc handled separately now with its own roll chance
        Spells::ThrowFood08,
        Spells::ThrowFood09,
        Spells::ThrowFood10,
        Spells::ThrowFood11,
        Spells::ThrowFood12,
    };

    static constexpr uint32 POINT_MOVE = 1;

    struct boss_captain_cookie : public BossAI
    {
        boss_captain_cookie(Creature* creature) : BossAI(creature, DataTypes::BOSS_CAPTAIN_COOKIE)
        {
            ApplyCrowdControlImmunities(me);
        }

        void Reset() override
        {
            BossAI::Reset();

            if (InstanceScript* instance = me->GetInstanceScript())
                instance->SetData(Misc::CookieDietFailed, 0);
            if (Creature* cauldron = me->GetMap()->GetCreature(_cauldronGuid))
                cauldron->DespawnOrUnsummon();

            _events.Reset();
            _cauldronGuid.Clear();
            _murlocEnabled = false;
            _encounterStarted = false;

            me->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
            me->SetReactState(REACT_PASSIVE);

            if (!_isEvading)
            {
                DoCastSelf(Spells::WhoIsThat, true);
                Talk(Texts::CookieSpawnWarning);
            }
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (_encounterStarted)
                return;

            if (!who->IsPlayer())
                return;

            if (me->GetDistance(who) > 7.0f)
                return;

            CreatureAI::MoveInLineOfSight(who);

            _encounterStarted = true;

            JustEngagedWith(who);
        }

        void JustEngagedWith(Unit* who) override
        {
            BossAI::JustEngagedWith(who);

            me->RemoveAurasDueToSpell(Spells::WhoIsThat);
            me->SetHomePosition(me->GetPosition());
            me->AttackStop();
            me->SetReactState(REACT_PASSIVE);
            DoCastSelf(Spells::CookieAchievCredit, true);
            _events.RescheduleEvent(Events::CookieMoveToCauldron, 1s);
            _events.RescheduleEvent(Events::CookieEnableMurloc, 160s);
            DoZoneInCombat();
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
        {
            if (me->GetVehicle() && me->GetHealth() <= damage)
                me->ExitVehicle();
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE && id == POINT_MOVE)
            {
                DoCastSelf(Spells::CauldronSummon, true);
                me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);

                _events.RescheduleEvent(Events::CookieEnterCauldron, 500ms);
                _events.RescheduleEvent(Events::CookieThrowFood, 3s);
            }
        }

        void JustSummoned(Creature* summon) override
        {
            BossAI::JustSummoned(summon);

            if (summon->GetEntry() == Creatures::Cauldron)
            {
                _cauldronGuid = summon->GetGUID();
                summon->SetReactState(REACT_PASSIVE);
            }
        }

        void JustDied(Unit* killer) override
        {
            BossAI::JustDied(killer);

            if (Creature* cauldron = me->GetMap()->GetCreature(_cauldronGuid))
                cauldron->DespawnOrUnsummon(2s);

            if (InstanceScript* instance = me->GetInstanceScript())
                if (!instance->GetData(Misc::CookieDietFailed))
                    if (AchievementEntry const* achievement = sAchievementStore.LookupEntry(Achievements::ImOnADiet))
                        instance->instance->DoOnPlayers([achievement](Player* player)
                        {
                            if (!player->HasAchieved(achievement->ID))
                                player->CompletedAchievement(achievement);
                        });

            if (IsHeroic())
            {
                me->SummonCreature(Creatures::VanessaNote, Positions::VanessaNoteSpawn, TEMPSUMMON_MANUAL_DESPAWN);
                Talk(Texts::CookieHeroicNote);
            }
        }

        void EnterEvadeMode(EvadeReason why) override
        {
            if (me->GetVehicle())
            {
                Position homePos = me->GetHomePosition();
                me->ExitVehicle();
                me->SetHomePosition(homePos);
            }

            _isEvading = true;
            BossAI::EnterEvadeMode(why);

            _encounterStarted = false;
        }

        void JustReachedHome() override
        {
            BossAI::JustReachedHome();

            _isEvading = false;
            DoCastSelf(Spells::WhoIsThat, true);
            Talk(Texts::CookieSpawnWarning);
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case Events::CookieMoveToCauldron:
                {
                    if (Creature* cookieJumpBunny = me->GetMap()->GetCreatureBySpawnId(CreatureSpawns::CookieJumpCuldronBunny))
                        me->GetMotionMaster()->MovePoint(POINT_MOVE, cookieJumpBunny->GetPosition());
                    break;
                }
                case Events::CookieEnterCauldron:
                {
                    if (Creature* cauldron = me->GetMap()->GetCreature(_cauldronGuid))
                        me->EnterVehicle(cauldron, 0);

                    break;
                }
                case Events::CookieEnableMurloc:
                {
                    _murlocEnabled = true;
                    break;
                }
                case Events::CookieThrowFood:
                {
                    auto target = SelectTarget(SelectTargetMethod::Random, 0, 50.0f, false);

                    if (target && target->IsAlive())
                    {
                        if (_murlocEnabled && urand(1, 100) <= 5)
                            me->CastSpell(target, Spells::ThrowFoodWithMurloc, CastSpellExtraArgs{ TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE });
                        else
                            me->CastSpell(target, ThrowFoodSpells[urand(0, 11)], CastSpellExtraArgs{ TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE });
                    }
                    _events.RescheduleEvent(Events::CookieThrowFood, 3s);
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;
        }

        private:
            ObjectGuid _cauldronGuid;
            EventMap _events;
            bool _murlocEnabled = false;
            bool _encounterStarted = false;
            bool _isEvading = false;
    };

    class spell_captain_cookie_satiated : public SpellScript
    {
        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            if (Unit* target = GetHitUnit())
                target->RemoveAuraFromStack(Spells::Nauseated);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_captain_cookie_satiated::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    class spell_captain_cookie_nauseated : public SpellScript
    {
        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->RemoveAuraFromStack(Spells::Satiated);

            if (Aura* aura = caster->GetAura(Spells::Nauseated))
            {
                if (aura->GetStackAmount() > 1)
                {
                    caster->CastSpell(caster, Spells::CookieAchievRemove, true);
                    if (InstanceScript* instance = caster->GetInstanceScript())
                        instance->SetData(Misc::CookieDietFailed, 1);
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_captain_cookie_nauseated::HandleScript, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
        }
    };
}

void AddSC_custom_deadmines_captain_cookie()
{
    using namespace Scripts::EasternKingdoms::Deadmines;

    RegisterCreatureAI(boss_captain_cookie);
    RegisterSpellScript(spell_captain_cookie_satiated);
    RegisterSpellScript(spell_captain_cookie_nauseated);
}

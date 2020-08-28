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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "CreatureAIImpl.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "deadmines.h"

enum Spells
{
    // "Captain" Cookie
    SPELL_WHOS_THAT                                 = 89339,
    SPELL_COOKIES_HAT                               = 88873,
    SPELL_COOKIES_CAULDRON                          = 89250,
    SPELL_CAULDRON_FIRE                             = 89252,
    SPELL_COOKIE_ACHIEVEMENT_AURA                   = 95650,
    SPELL_THROW_FOOD_TARGETING_CORN                 = 89268,
    SPELL_THROW_FOOD_TARGETING_ROTTEN_CORN          = 89740,
    SPELL_THROW_FOOD_TARGETING_MELON                = 90561,
    SPELL_THROW_FOOD_TARGETING_ROTTEN_MELON         = 90582,
    SPELL_THROW_FOOD_TARGETING_STEAK                = 90562,
    SPELL_THROW_FOOD_TARGETING_ROTTEN_STEAK         = 90583,
    SPELL_THROW_FOOD_TARGETING_MYSTERY_MEAT         = 90563,
    SPELL_THROW_FOOD_TARGETING_ROTTEN_MYSTERY_MEAT  = 90584,
    SPELL_THROW_FOOD_TARGETING_LOAF                 = 90564,
    SPELL_THROW_FOOD_TARGETING_ROTTEN_LOAF          = 90585,
    SPELL_THROW_FOOD_TARGETING_BUN                  = 90565,
    SPELL_THROW_FOOD_TARGETING_ROTTEN_BUN           = 90586,

    // Player
    SPELL_NAUSEATED                                 = 89732,
    SPELL_NAUSEATED_HC                              = 92066

};

enum Events
{
    EVENT_MOVE_TO_SUMMON_POS = 1,
    EVENT_SUMMON_CAULDRON,
    EVENT_JUMP_INTO_CAULDRON,
    EVENT_CAULDRON_FIRE,
    EVENT_THROW_FOOD,
};

enum Points
{
    POINT_CAULDRON_SUMMON = 1
};

enum FoodTypes
{
    FOOD_CORN = 0,
    FOOD_MELON,
    FOOD_STEAK,
    FOOD_MYSTERY_MEAT,
    FOOD_LOAF,
    FOOD_BUN,
};

enum FoodStates
{
    FOOD_STATE_DELICIOUS = 0,
    FOOD_STATE_ROTTEN,
};

uint32 cornSpells[] =
{
    SPELL_THROW_FOOD_TARGETING_CORN,
    SPELL_THROW_FOOD_TARGETING_ROTTEN_CORN
};

uint32 melonSpells[] =
{
    SPELL_THROW_FOOD_TARGETING_MELON,
    SPELL_THROW_FOOD_TARGETING_ROTTEN_MELON
};

uint32 steakSpells[] =
{
    SPELL_THROW_FOOD_TARGETING_STEAK,
    SPELL_THROW_FOOD_TARGETING_ROTTEN_STEAK
};

uint32 mysteryMeatSpells[] =
{
    SPELL_THROW_FOOD_TARGETING_MYSTERY_MEAT,
    SPELL_THROW_FOOD_TARGETING_ROTTEN_MYSTERY_MEAT
};

uint32 loafSpells[] =
{
    SPELL_THROW_FOOD_TARGETING_MYSTERY_MEAT,
    SPELL_THROW_FOOD_TARGETING_ROTTEN_MYSTERY_MEAT
};

uint32 bunSpells[] =
{
    SPELL_THROW_FOOD_TARGETING_BUN,
    SPELL_THROW_FOOD_TARGETING_ROTTEN_BUN
};

Position const cookieIntroPos = { -66.23547f, -820.1689f, 40.98766f };

class boss_captain_cookie : public CreatureScript
{
    public:
        boss_captain_cookie() : CreatureScript("boss_captain_cookie") { }

        struct boss_captain_cookieAI : public BossAI
        {
            boss_captain_cookieAI(Creature* creature) : BossAI(creature, DATA_CAPTAIN_COOKIE)
            {
                Initialize();
            }

            void Initialize()
            {
                _foodState = FOOD_STATE_DELICIOUS;
                _foodType = RAND(FOOD_CORN, FOOD_BUN);
            }

            void Reset() override
            {
                _Reset();
                Initialize();
                DoCastSelf(SPELL_WHOS_THAT, true);
                DoCastSelf(SPELL_COOKIES_HAT, true);
            }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                me->RemoveAurasDueToSpell(SPELL_WHOS_THAT);
                me->AttackStop();
                me->SetReactState(REACT_PASSIVE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                events.ScheduleEvent(EVENT_MOVE_TO_SUMMON_POS, Milliseconds(1));
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _EnterEvadeMode();
                summons.DespawnAll();
                instance->SetBossState(DATA_CAPTAIN_COOKIE, FAIL);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                _DespawnAtEvade();
            }

            void MovementInform(uint32 type, uint32 point) override
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                switch (point)
                {
                    case POINT_CAULDRON_SUMMON:
                        DoCastAOE(SPELL_COOKIES_CAULDRON);
                        events.ScheduleEvent(EVENT_JUMP_INTO_CAULDRON, Seconds(1) + Milliseconds(500));
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MOVE_TO_SUMMON_POS:
                            me->GetMotionMaster()->MovePoint(POINT_CAULDRON_SUMMON, cookieIntroPos, false);
                            break;
                        case EVENT_JUMP_INTO_CAULDRON:
                            if (Creature* cauldron = me->FindNearestCreature(NPC_COOKIES_CAULDRON, 15.0f, true))
                            {
                                me->CastSpell(cauldron, VEHICLE_SPELL_RIDE_HARDCODED);
                                events.ScheduleEvent(EVENT_CAULDRON_FIRE, Seconds(2) + Milliseconds(400));
                            }
                            break;
                        case EVENT_CAULDRON_FIRE:
                            DoCastSelf(SPELL_CAULDRON_FIRE, true);
                            DoCastAOE(SPELL_COOKIE_ACHIEVEMENT_AURA, true);
                            events.ScheduleEvent(EVENT_THROW_FOOD, Milliseconds(1));
                            break;
                        case EVENT_THROW_FOOD:
                        {
                            switch (_foodType)
                            {
                                case FOOD_CORN:
                                    DoCastAOE(cornSpells[_foodState], true);
                                    break;
                                case FOOD_MELON:
                                    DoCastAOE(melonSpells[_foodState], true);
                                    break;
                                case FOOD_STEAK:
                                    DoCastAOE(steakSpells[_foodState], true);
                                    break;
                                case FOOD_MYSTERY_MEAT:
                                    DoCastAOE(mysteryMeatSpells[_foodState], true);
                                    break;
                                case FOOD_LOAF:
                                    DoCastAOE(loafSpells[_foodState], true);
                                    break;
                                case FOOD_BUN:
                                    DoCastAOE(bunSpells[_foodState], true);
                                    break;
                                default:
                                    break;
                            }

                            // Select food when rotten and delicious versions has been thrown
                            if (_foodState == FOOD_STATE_ROTTEN)
                            {
                                // Select next random food and make sure that we will
                                // never get the same food twice
                                uint8 oldFoodType = _foodType;
                                _foodType = RAND(FOOD_CORN, FOOD_BUN);
                                if (_foodType == oldFoodType)
                                    _foodType++;
                                if (_foodType > FOOD_BUN)
                                    _foodType = FOOD_CORN;
                            }

                            _foodState = _foodState == FOOD_STATE_DELICIOUS ? FOOD_STATE_ROTTEN : FOOD_STATE_DELICIOUS;
                            events.Repeat(Seconds(1) + Milliseconds(200), Seconds(2));
                            break;
                        }
                        default:
                            break;
                    }
                }
            }
        private:
            uint8 _foodState;
            uint8 _foodType;
        };

        CreatureAI* GetAI(Creature *creature) const override
        {
            return GetDeadminesAI<boss_captain_cookieAI>(creature);
        }
};

class spell_cookie_throw_food_targeting : public SpellScriptLoader
{
    public:
        spell_cookie_throw_food_targeting() : SpellScriptLoader("spell_cookie_throw_food_targeting") { }

        class spell_cookie_throw_food_targeting_SpellScript : public SpellScript
        {
            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                Trinity::Containers::RandomResize(targets, 1);
            }

            void HandleHit(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                    caster->CastSpell(GetHitUnit(), GetSpellInfo()->Effects[effIndex].BasePoints);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect.Register(&spell_cookie_throw_food_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget.Register(&spell_cookie_throw_food_targeting_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_cookie_throw_food_targeting_SpellScript();
        }
};

class spell_cookie_satiated : public SpellScriptLoader
{
    public:
        spell_cookie_satiated() : SpellScriptLoader("spell_cookie_satiated") { }

        class spell_cookie_satiated_SpellScript : public SpellScript
        {
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                    {
                        SPELL_NAUSEATED,
                        SPELL_NAUSEATED_HC
                    });
            }

            void HandleHit(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                    if (Aura* nauseatedAura = caster->GetAura(GetSpellInfo()->Effects[effIndex].BasePoints))
                        nauseatedAura->ModStackAmount(-1, AuraRemoveFlags::ByDefault | AuraRemoveFlags::DontResetPeriodicTimer);
            }

            void Register() override
            {
                OnEffectHitTarget.Register(&spell_cookie_satiated_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_cookie_satiated_SpellScript();
        }
};

void AddSC_boss_captain_cookie()
{
    new boss_captain_cookie();
    new spell_cookie_throw_food_targeting();
    new spell_cookie_satiated();
}

/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "eternal_palace.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "AreaTrigger.h"
#include "MoveSplineInit.h"
#include <G3D/Vector3.h>
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"

enum Spells
{
    SPELL_CHIMERIC_MARKS = 294726,
    SPELL_FOST_MARK = 294711,
    SPELL_TOXIC_BRAND = 294715,
    SPELL_FROST_MARK_MISSILE = 295284,
    SPELL_TOXIC_BRAND_MISSILE = 295285,
    SPELL_UNSTABLE_MIXTURE = 294847,

    SPELL_OVERFLOW = 295346,
    SPELL_OVERFLOWING_CHILL_AURA = 295348,
    SPELL_OVERFLOWING_CHILL_DAMAGE = 295415,
    SPELL_FROZEN_GROUND_AT = 300715,
    SPELL_FROZEN_GROUND_AURA = 300961,

    SPELL_OVERFLOWING_VENOM_AURA = 295421,
    SPELL_OVERFLOWING_VENOM_DAMAGE = 295417,
    SPELL_SEPTIC_GROUND_AT = 300719,
    SPELL_SEPTIC_GROUND_AURA = 300962,

    SPELL_CRUSHING_REVERBERATION_TANK = 295332,
    SPELL_CRUSHING_REVERBERATION_TANK_MARK = 304829,

    SPELL_FROSTVENOM_TIPPED = 300698,
    SPELL_SEPTIC_TAINT = 300705,
    SPELL_RIMEFROST = 300701,

    SPELL_OVERWHELMING_BARRAGE_CAST = 296551,
    SPELL_FROSTBOLT_MISSILE = 295621,
    SPELL_FROSTBOLT_AURA = 295704,

    SPELL_OVERWHELMING_BARRAGE_FROST = 295144,
    SPELL_OVERWHELMING_BARRAGE_TOXIC = 295159,

    SPELL_TOXICBOLT_MISSILE = 295622,
    SPELL_TOXICBOLT_AURA = 295705,

    SPELL_FROSTSHOCK_BOLTS = 295601,
    SPELL_TOXIC_BOLT_JAVELIN = 295607,
    SPELL_FROST_BOLT_JAVELIN = 295606,

    SPELL_INVERSION_CAST = 295791,
    SPELL_INVERSION_SICKNESS_VENOM = 300883,
    SPELL_INVERSION_SICKNESS_FROST = 300882,

    SPELL_FROZEN_BLOOD_BAR = 295795,
    SPELL_FROZEN_BAR_STUN = 295807,
    SPELL_FROZEN_BLOOD_ENERGIZE = 295800,
    SPELL_FROZEN_BLOOD_ENERGIZE_BURN = 295803,

    SPELL_VENOMOUS_BLOOD_ENERGIZE = 295804,
    SPELL_VENOMOUS_BLOOD_ENERGIZE_BURN = 295805,
    SPELL_VENOMOUS_BLOOD_BAR = 295796,
    SPELL_VENOMOUS_BLOOD_DELIRIOUS = 295850,
};

enum Events
{
    EVENT_CHIMERIC_MARKS = 1,
    EVENT_OVERFLOW,
    EVENT_INVERSION,
    EVENT_CRUSHING_REVERBERATION,
    EVENT_CHECK_ENERGY,
    EVENT_FROSTVENOM_TIPPED,
    EVENT_OVERWHELMING_BARRAGE,
    EVENT_FROSTSHOCK_BOLTS,

    EVENT_CAST_CHIMERIC_MARKS,
};

enum Timers
{
    TIMER_CAST_CHIMERIC_MARKS = 25 * IN_MILLISECONDS,
    TIMER_CHIMERIC_MARKS = 3 * IN_MILLISECONDS,
    TIMER_INVERSION = 35 * IN_MILLISECONDS,
    TIMER_CHECK_ENERGY = 4 * IN_MILLISECONDS,
    TIMER_OVERFLOW = 40 * IN_MILLISECONDS,
    TIMER_OVERWHELMING_BARRAGE = 1 * IN_MILLISECONDS,
    TIMER_FROSTSHOCK_BOLTS = 50 * IN_MILLISECONDS,
    TIMER_CRUSHING_REVERBERATION = 35 * IN_MILLISECONDS,
};

enum AreaTriggers
{
    AT_FROST = 16563,
    AT_TOXIC = 16564,
};

const Position centerPos = { 298.54f, 153.91f, 1449.97f }; //40y

struct noFrostauracheck : public std::unary_function<Unit*, bool >
{
    noFrostauracheck() {}

    bool operator() (const Unit* target)
    {
        return target && !target->HasAura(SPELL_FOST_MARK);
    }
};

struct checkGms : public std::unary_function<Unit*, bool>
{
    checkGms() {}

    bool operator() (const Player* target)
    {
        return target && !target->IsGameMaster();
    }
};

struct noToxicauracheck : public std::unary_function<Unit*, bool>
{
    noToxicauracheck() {}

    bool operator() (const Unit* target)
    {
        return target && !target->HasAura(SPELL_TOXIC_BRAND);
    }

};

struct tankSpecs : public std::unary_function<Unit*, bool>
{
    tankSpecs() {}

    bool operator() (const Unit* pTarget)
    {
        Player* player = const_cast<Player*>(pTarget->ToPlayer());
        uint32 specialization = player->GetSpecializationId();
        return ((player->getClass() == CLASS_DRUID && specialization == TALENT_SPEC_DRUID_BEAR)
            || (player->getClass() == CLASS_WARRIOR && specialization == TALENT_SPEC_WARRIOR_PROTECTION)
            || (player->getClass() == CLASS_PALADIN && specialization == TALENT_SPEC_PALADIN_PROTECTION)
            || (player->getClass() == CLASS_DEATH_KNIGHT && specialization == TALENT_SPEC_DEATHKNIGHT_BLOOD)
            || (player->getClass() == CLASS_DEMON_HUNTER && specialization == TALENT_SPEC_DEMON_HUNTER_VENGEANCE)
            || (player->getClass() == CLASS_MONK && specialization == TALENT_SPEC_MONK_BREWMASTER));
    }
};

struct healSpecs : public std::unary_function<Unit*, bool>
{
    healSpecs() {}

    bool operator() (const Unit* pTarget)
    {
        Player* player = const_cast<Player*>(pTarget->ToPlayer());
        uint32 specialization = player->GetSpecializationId();
        return ((player->getClass() == CLASS_PRIEST && specialization == TALENT_SPEC_PRIEST_DISCIPLINE)
            || (player->getClass() == CLASS_PRIEST && specialization == TALENT_SPEC_PRIEST_HOLY)
            || (player->getClass() == CLASS_DRUID && specialization == TALENT_SPEC_DRUID_RESTORATION)
            || (player->getClass() == CLASS_MONK && specialization == TALENT_SPEC_MONK_MISTWEAVER)
            || (player->getClass() == CLASS_PALADIN && specialization == TALENT_SPEC_PALADIN_HOLY)
            || (player->getClass() == CLASS_SHAMAN && specialization == TALENT_SPEC_SHAMAN_RESTORATION));
    }
};

struct dpsSpecs : public std::unary_function<Unit*, bool>
{
    dpsSpecs() {}

    bool operator() (const Unit* pTarget)
    {
        Player* player = const_cast<Player*>(pTarget->ToPlayer());
        uint32 specialization = player->GetSpecializationId();
        return ((player->getClass() == CLASS_PRIEST && specialization == TALENT_SPEC_PRIEST_SHADOW)
            || (player->getClass() == CLASS_DEATH_KNIGHT && specialization == TALENT_SPEC_DEATHKNIGHT_FROST)
            || (player->getClass() == CLASS_DEATH_KNIGHT && specialization == TALENT_SPEC_DEATHKNIGHT_UNHOLY)
            || (player->getClass() == CLASS_DRUID && specialization == TALENT_SPEC_DRUID_BALANCE)
            || (player->getClass() == CLASS_DRUID && specialization == TALENT_SPEC_DRUID_CAT)
            || (player->getClass() == CLASS_MONK && specialization == TALENT_SPEC_MONK_BATTLEDANCER)
            || (player->getClass() == CLASS_SHAMAN && specialization == TALENT_SPEC_SHAMAN_ELEMENTAL)
            || (player->getClass() == CLASS_DEMON_HUNTER && specialization == TALENT_SPEC_DEMON_HUNTER_HAVOC)
            || (player->getClass() == CLASS_HUNTER && specialization == TALENT_SPEC_HUNTER_BEASTMASTER)
            || (player->getClass() == CLASS_HUNTER && specialization == TALENT_SPEC_HUNTER_SURVIVAL)
            || (player->getClass() == CLASS_HUNTER && specialization == TALENT_SPEC_HUNTER_MARKSMAN)
            || (player->getClass() == CLASS_MAGE && specialization == TALENT_SPEC_MAGE_FIRE)
            || (player->getClass() == CLASS_MAGE && specialization == TALENT_SPEC_MAGE_ARCANE)
            || (player->getClass() == CLASS_MAGE && specialization == TALENT_SPEC_MAGE_FROST)
            || (player->getClass() == CLASS_ROGUE && specialization == TALENT_SPEC_ROGUE_COMBAT)
            || (player->getClass() == CLASS_ROGUE && specialization == TALENT_SPEC_ROGUE_ASSASSINATION)
            || (player->getClass() == CLASS_ROGUE && specialization == TALENT_SPEC_ROGUE_SUBTLETY)
            || (player->getClass() == CLASS_WARLOCK && specialization == TALENT_SPEC_WARLOCK_AFFLICTION)
            || (player->getClass() == CLASS_WARLOCK && specialization == TALENT_SPEC_WARLOCK_DEMONOLOGY)
            || (player->getClass() == CLASS_WARLOCK && specialization == TALENT_SPEC_WARLOCK_DESTRUCTION)
            || (player->getClass() == CLASS_WARRIOR && specialization == TALENT_SPEC_WARRIOR_ARMS)
            || (player->getClass() == CLASS_WARRIOR && specialization == TALENT_SPEC_WARRIOR_FURY)
            || (player->getClass() == CLASS_PALADIN && specialization == TALENT_SPEC_PALADIN_RETRIBUTION)
            || (player->getClass() == CLASS_SHAMAN && specialization == TALENT_SPEC_SHAMAN_ENHANCEMENT));
    }
};

// at visuals
// timers 
// barrage script

#define AGGRO_TEXT "For Queen Azshara!"
#define OVERFLOW_TEXT "My power cannot be contained!"
#define OVERWHELMING_BARRAGE_TEXT "Time to wash away the filth."
#define INVERSION_TEXT "Your tactics are pathetic!"
#define KILLED_TARGET_TEXT "Is that the best you can do?"
#define BOLT_TARGET_TEXT "Such an easy target!"
#define DEATH_TEXT "You... are all... fools..."

class bfa_boss_commander_sivara : public CreatureScript
{
public:
    bfa_boss_commander_sivara() : CreatureScript("bfa_boss_commander_sivara")
    {
    }

    struct bfa_boss_commander_sivara_AI : public BossAI
    {
        bfa_boss_commander_sivara_AI(Creature* creature) : BossAI(creature, DATA_COMMANDER_SIVARA)
        {
            instance = creature->GetInstanceScript();
            creature->SetPowerType(POWER_ENERGY);
            creature->SetMaxPower(POWER_ENERGY, 100);
            creature->SetPower(POWER_ENERGY, 0);
        }

        InstanceScript* instance;
        EventMap events;
        uint8 bolts;

        void Reset()
        {
            bolts = 0;
            events.Reset();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            me->RemoveAllAreaTriggers();
        }

        void SelectSoundAndText(Creature* me, uint32  selectedTextSound = 0)
        {
            if (!me)
                return;

            if (me)
            {
                switch (selectedTextSound)
                {
                case 1:
                    me->Yell(AGGRO_TEXT, LANG_UNIVERSAL, NULL);
                    break;
                case 2:
                    me->Yell(DEATH_TEXT, LANG_UNIVERSAL, NULL);
                    break;
                case 3:
                    me->Yell(KILLED_TARGET_TEXT, LANG_UNIVERSAL, NULL);
                    break;
                case 4:
                    me->Yell(OVERFLOW_TEXT, LANG_UNIVERSAL, NULL);
                    break;
                case 5:
                    me->Yell(OVERWHELMING_BARRAGE_TEXT, LANG_UNIVERSAL, NULL);
                    break;
                case 6:
                    me->Yell(INVERSION_TEXT, LANG_UNIVERSAL, NULL);
                    break;
                case 7:
                    me->Yell(BOLT_TARGET_TEXT, LANG_UNIVERSAL, NULL);
                    break;
                }
            }
        }

        void JustDied(Unit*)
        {
            SelectSoundAndText(me, 2);
            me->RemoveAllAreaTriggers();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        void KilledUnit(Unit* t)
        {
            SelectSoundAndText(me, 3);
        }

        void EnterEvadeMode(EvadeReason w)
        {
            _DespawnAtEvade(15);
        }

        void EnterCombat(Unit*)
        {
            SelectSoundAndText(me, 1);
            me->CastSpell(me, EVENT_FROSTVENOM_TIPPED, true);

            me->SetPower(POWER_ENERGY, 0);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

            if (me->GetMap()->IsMythic())
                events.ScheduleEvent(EVENT_CAST_CHIMERIC_MARKS, TIMER_CAST_CHIMERIC_MARKS);

            events.ScheduleEvent(EVENT_CHIMERIC_MARKS, TIMER_CHIMERIC_MARKS);
            events.ScheduleEvent(EVENT_OVERFLOW, TIMER_OVERFLOW);
            events.ScheduleEvent(EVENT_INVERSION, TIMER_INVERSION);
            events.ScheduleEvent(EVENT_CRUSHING_REVERBERATION, TIMER_CRUSHING_REVERBERATION);
            events.ScheduleEvent(EVENT_CHECK_ENERGY, TIMER_CHECK_ENERGY);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_FROSTSHOCK_BOLTS:
                {
                    ++bolts;

                    std::list<Player*> playerList;
                    me->GetPlayerListInGrid(playerList, 100.0f);
                    playerList.remove_if(tankSpecs());
                    if (!playerList.empty())
                    {
                        if (playerList.size() >= 1)
                            playerList.resize(1);

                        for (auto player : playerList)
                        {
                            SelectSoundAndText(me, 7);

                            if (player->HasAura(SPELL_FOST_MARK))
                            {
                                std::ostringstream str;
                                str << player->GetName(); " has been targeted for |cFFF00000|h[Toxic Javelin]|h|r!";
                                me->TextEmote(str.str().c_str(), 0, true);

                                me->CastSpell(player, SPELL_TOXIC_BOLT_JAVELIN);
                            }
                            else if (player->HasAura(SPELL_TOXIC_BRAND))
                            {
                                std::ostringstream str;
                                str << player->GetName();  " has been targeted for |cFFF00000|h[Frost Javelin]|h|r!";
                                me->TextEmote(str.str().c_str(), 0, true);

                                me->CastSpell(player, SPELL_FROST_BOLT_JAVELIN);
                            }
                        }
                    }

                    if (bolts >= 2)
                    {
                        events.ScheduleEvent(EVENT_FROSTSHOCK_BOLTS, TIMER_FROSTSHOCK_BOLTS);
                    }
                    else
                        events.ScheduleEvent(EVENT_FROSTSHOCK_BOLTS, 5 * IN_MILLISECONDS);
                    break;
                }
                case EVENT_CHIMERIC_MARKS:
                    me->CastSpell(me, SPELL_CHIMERIC_MARKS);
                    break;
                case EVENT_CAST_CHIMERIC_MARKS:
                    me->CastSpell(me, SPELL_CHIMERIC_MARKS);
                    events.ScheduleEvent(EVENT_CAST_CHIMERIC_MARKS, TIMER_CAST_CHIMERIC_MARKS);
                    break;
                case EVENT_INVERSION:
                    SelectSoundAndText(me, 6);
                    me->CastSpell(me, SPELL_INVERSION_CAST);
                    events.ScheduleEvent(EVENT_INVERSION, TIMER_INVERSION);
                    break;
                case EVENT_OVERFLOW:
                    SelectSoundAndText(me, 4);
                    me->CastSpell(me, SPELL_OVERFLOW);
                    events.ScheduleEvent(EVENT_OVERFLOW, TIMER_OVERFLOW);
                    break;
                case EVENT_CRUSHING_REVERBERATION:
                    if (Unit* target = me->GetVictim())
                    {
                        me->CastSpell(target, SPELL_CRUSHING_REVERBERATION_TANK);
                    }
                    events.ScheduleEvent(EVENT_CRUSHING_REVERBERATION, TIMER_CRUSHING_REVERBERATION);
                    break;
                case EVENT_OVERWHELMING_BARRAGE:
                    SelectSoundAndText(me, 5);
                    me->CastSpell(me, SPELL_OVERWHELMING_BARRAGE_CAST);
                    events.ScheduleEvent(EVENT_OVERWHELMING_BARRAGE, TIMER_OVERWHELMING_BARRAGE);
                    break;
                case EVENT_CHECK_ENERGY:
                {
                    if (me->GetPower(POWER_ENERGY) == 100)
                    {
                        events.ScheduleEvent(EVENT_OVERWHELMING_BARRAGE, TIMER_OVERWHELMING_BARRAGE);
                        me->SetPower(POWER_ENERGY, 0);
                    }

                    me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + urand(0, 3));
                    events.ScheduleEvent(EVENT_CHECK_ENERGY, TIMER_CHECK_ENERGY);
                    break;
                }
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_boss_commander_sivara_AI(creature);
    }
};

// 294726 chimeric marks
class bfa_spell_chimeric_marks : public SpellScriptLoader
{
public:
    bfa_spell_chimeric_marks() : SpellScriptLoader("bfa_spell_chimeric_marks") { }

    class bfa_spell_chimeric_marks_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_chimeric_marks_SpellScript);

        uint32 totalSizeList;

        bool Load() override
        {
            totalSizeList = 0;
            return true;
        }

        void SelectTanksToxic()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            std::list<Player*> tanksList;
            caster->GetPlayerListInGrid(tanksList, 70.0f);
            tanksList.remove_if(dpsSpecs());
            tanksList.remove_if(healSpecs());
            tanksList.remove_if(checkGms());
            tanksList.remove_if(noFrostauracheck());
            if (!tanksList.empty())
            {
                totalSizeList = tanksList.size();
                tanksList.resize(totalSizeList / 2);
                for (std::list<Player*>::const_iterator itr = tanksList.begin(); itr != tanksList.end(); ++itr)
                {
                    caster->CastSpell((*itr), SPELL_TOXIC_BRAND_MISSILE, true);
                }
            }

            caster->GetScheduler().Schedule(2s, [this](TaskContext /*context*/)
            {
                SelectTanksFrost();
            });
        }

        void SelectHealersToxic()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            std::list<Player*> healList;
            caster->GetPlayerListInGrid(healList, 70.0f);
            healList.remove_if(tankSpecs());
            healList.remove_if(checkGms());
            healList.remove_if(dpsSpecs());
            healList.remove_if(noFrostauracheck());
            if (!healList.empty())
            {
                totalSizeList = healList.size();
                healList.resize(totalSizeList / 2);

                for (std::list<Player*>::const_iterator itr = healList.begin(); itr != healList.end(); ++itr)
                {
                    caster->CastSpell((*itr), SPELL_TOXIC_BRAND_MISSILE, true);
                }
            }

            caster->GetScheduler().Schedule(2s, [this](TaskContext /*context*/)
            {
                SelectHealersFrost();
            });
        }

        void SelectDamagesToxic()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            std::list<Player*> dpsList;
            caster->GetPlayerListInGrid(dpsList, 70.0f);
            dpsList.remove_if(tankSpecs());
            dpsList.remove_if(healSpecs());
            dpsList.remove_if(checkGms());
            dpsList.remove_if(noFrostauracheck());
            if (!dpsList.empty())
            {
                totalSizeList = dpsList.size();
                dpsList.resize(totalSizeList / 2);

                for (std::list<Player*>::const_iterator itr = dpsList.begin(); itr != dpsList.end(); ++itr)
                {
                    caster->CastSpell((*itr), SPELL_TOXIC_BRAND_MISSILE, true);
                }
            }

            caster->GetScheduler().Schedule(2s, [this](TaskContext /*context*/)
            {
                SelectDamagesFrost();
            });
        }

        void SelectTanksFrost()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            std::list<Player*> tanksList;
            caster->GetPlayerListInGrid(tanksList, 70.0f);
            tanksList.remove_if(dpsSpecs());
            tanksList.remove_if(healSpecs());
            tanksList.remove_if(checkGms());
            tanksList.remove_if(noToxicauracheck());
            if (!tanksList.empty())
            {
                totalSizeList = tanksList.size();
                tanksList.resize(totalSizeList / 2);
                for (std::list<Player*>::const_iterator itr = tanksList.begin(); itr != tanksList.end(); ++itr)
                {
                    caster->CastSpell((*itr), SPELL_FROST_MARK_MISSILE, true);
                }
            }
        }

        void SelectHealersFrost()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            std::list<Player*> healList;
            caster->GetPlayerListInGrid(healList, 70.0f);
            healList.remove_if(tankSpecs());
            healList.remove_if(checkGms());
            healList.remove_if(dpsSpecs());
            healList.remove_if(noToxicauracheck());
            if (!healList.empty())
            {
                for (std::list<Player*>::const_iterator itr = healList.begin(); itr != healList.end(); ++itr)
                {
                    caster->CastSpell((*itr), SPELL_FROST_MARK_MISSILE, true);
                }
            }
        }

        void SelectDamagesFrost()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            std::list<Player*> dpsList;
            caster->GetPlayerListInGrid(dpsList, 70.0f);
            dpsList.remove_if(tankSpecs());
            dpsList.remove_if(healSpecs());
            dpsList.remove_if(checkGms());
            dpsList.remove_if(noToxicauracheck());
            if (!dpsList.empty())
            {
                for (std::list<Player*>::const_iterator itr = dpsList.begin(); itr != dpsList.end(); ++itr)
                {
                    caster->CastSpell((*itr), SPELL_FROST_MARK_MISSILE, true);
                }
            }
        }


        void HandleAfterCast(SpellEffIndex)
        {
            SelectDamagesToxic();
            SelectTanksToxic();
            SelectHealersToxic();
        }

        void Register()
        {
            OnEffectHit += SpellEffectFn(bfa_spell_chimeric_marks_SpellScript::HandleAfterCast, EFFECT_0, SPELL_EFFECT_DUMMY);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_chimeric_marks_SpellScript();
    }
};

// overflow 295346
class bfa_spell_overflow : public SpellScriptLoader
{
public:
    bfa_spell_overflow() : SpellScriptLoader("bfa_spell_overflow") { }

    class bfa_spell_overflow_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_overflow_SpellScript);

        void SelectFrostPlayers()
        {
            std::list<Player*> frostList;
            GetCaster()->GetPlayerListInGrid(frostList, 70.0f);
            frostList.remove_if(noFrostauracheck());
            frostList.remove_if(tankSpecs());
            if (frostList.size())
            {
                if (frostList.size() >= 2)
                    frostList.resize(2);


                for (auto player : frostList)
                {
                    if (Aura* frost = player->GetAura(SPELL_FOST_MARK))
                    {
                        if (frost->GetStackAmount() > 1)
                            frost->SetStackAmount(1);
                        player->CastSpell(player, SPELL_OVERFLOWING_CHILL_AURA, true);
                    }
                }
            }
        }

        void SelectToxicPlayers()
        {
            std::list<Player*> toxicList;
            GetCaster()->GetPlayerListInGrid(toxicList, 70.0f);
            toxicList.remove_if(noToxicauracheck());
            toxicList.remove_if(tankSpecs());
            if (toxicList.size())
            {
                if (toxicList.size() >= 2)
                    toxicList.resize(2);


                for (auto player : toxicList)
                {
                    if (Aura* toxic = player->GetAura(SPELL_TOXIC_BRAND))
                    {
                        if (toxic->GetStackAmount() > 1)
                            toxic->SetStackAmount(1);
                        player->CastSpell(player, SPELL_OVERFLOWING_VENOM_AURA, true);
                    }
                }
            }
        }

        void HandleAfterCast(SpellEffIndex index)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;
            SelectFrostPlayers();
            SelectToxicPlayers();

        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_overflow_SpellScript::HandleAfterCast, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_overflow_SpellScript();
    }
};

// 295415 overflowing chill \ 295417 overflowing venom damage split
class bfa_spell_overflowing_chill_venom_damage : public SpellScriptLoader
{
public:
    bfa_spell_overflowing_chill_venom_damage() : SpellScriptLoader("bfa_spell_overflowing_chill_venom_damage") { }

    class bfa_spell_overflowing_chill_venom_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_overflowing_chill_venom_damage_SpellScript);

        uint32 targetList;

        bool Load() override
        {
            targetList = 0;
            return true;
        }

        void CheckTargets(std::list<WorldObject*>& targets)
        {
            targetList = targets.size();
        }

        void RecalculateDamage(SpellEffIndex index)
        {
            SetHitDamage(GetHitDamage() / targetList);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_overflowing_chill_venom_damage_SpellScript::CheckTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(bfa_spell_overflowing_chill_venom_damage_SpellScript::RecalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }

    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_overflowing_chill_venom_damage_SpellScript();
    }
};


// 295348 overflowing chill / 295421 overflowing venom aura expire
class bfa_spell_overflowing_chill_venom_aura : public SpellScriptLoader
{
public:
    bfa_spell_overflowing_chill_venom_aura() : SpellScriptLoader("bfa_spell_overflowing_chill_venom_aura") { }

    class bfa_spell_overflowing_chill_venom_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_overflowing_chill_venom_aura_AuraScript);

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (caster->HasAura(SPELL_OVERFLOWING_CHILL_AURA))
            {
                caster->CastSpell(caster, SPELL_OVERFLOWING_CHILL_DAMAGE, true);
                caster->CastSpell(caster, SPELL_FROZEN_GROUND_AT, true);
            }
            else if (caster->HasAura(SPELL_OVERFLOWING_VENOM_AURA))
            {
                caster->CastSpell(caster, SPELL_OVERFLOWING_VENOM_DAMAGE, true);
                caster->CastSpell(caster, SPELL_SEPTIC_GROUND_AT, true);
            }
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_overflowing_chill_venom_aura_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
        }

    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_overflowing_chill_venom_aura_AuraScript();
    }
};

// 17105 septic ground
class bfa_at_septic_ground : public AreaTriggerEntityScript
{
public:
    bfa_at_septic_ground() : AreaTriggerEntityScript("bfa_at_septic_ground") { }

    struct bfa_at_septic_ground_AI : AreaTriggerAI
    {
        bfa_at_septic_ground_AI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitExit(Unit* unit) override
        {
            if (unit->HasAura(SPELL_SEPTIC_GROUND_AURA))
                unit->RemoveAura(SPELL_SEPTIC_GROUND_AURA);
        }

        void OnUnitEnter(Unit* unit) override
        {
            if (unit->IsPlayer() && !unit->ToPlayer()->IsGameMaster() && !unit->HasAura(SPELL_SEPTIC_GROUND_AURA))
            {
                unit->AddAura(SPELL_SEPTIC_GROUND_AURA, unit);
            }
        }

    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new bfa_at_septic_ground_AI(areatrigger);
    }
};

// 17104 frozen ground
class bfa_at_frozen_ground : public AreaTriggerEntityScript
{
public:
    bfa_at_frozen_ground() : AreaTriggerEntityScript("bfa_at_frozen_ground") { }

    struct bfa_at_frozen_ground_AI : AreaTriggerAI
    {
        bfa_at_frozen_ground_AI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitExit(Unit* unit) override
        {
            if (unit->HasAura(SPELL_FROZEN_GROUND_AURA))
                unit->RemoveAura(SPELL_FROZEN_GROUND_AURA);
        }

        void OnUnitEnter(Unit* unit) override
        {
            if (unit->IsPlayer() && !unit->ToPlayer()->IsGameMaster() && !unit->HasAura(SPELL_FROZEN_GROUND_AURA))
            {
                unit->AddAura(SPELL_FROZEN_GROUND_AURA, unit);
            }
        }

    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new bfa_at_frozen_ground_AI(areatrigger);
    }
};

// 300962 septic ground aura
class bfa_spell_septic_ground_aura : public SpellScriptLoader
{
public:
    bfa_spell_septic_ground_aura() : SpellScriptLoader("bfa_spell_septic_ground_aura") { }

    class bfa_spell_septic_ground_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_septic_ground_aura_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            Unit* target = GetTarget()->ToPlayer();
            if (!GetCaster() || !target)
                return;

            target->CastSpell(target, SPELL_TOXIC_BRAND, true);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_septic_ground_aura_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_septic_ground_aura_AuraScript;
    }
};

// 300961 frozen ground aura 
class bfa_spell_frozen_ground_aura : public SpellScriptLoader
{
public:
    bfa_spell_frozen_ground_aura() : SpellScriptLoader("bfa_spell_frozen_ground_aura") { }

    class bfa_spell_frozen_ground_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_frozen_ground_aura_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            Unit* target = GetTarget()->ToPlayer();
            if (!GetCaster() || !target)
                return;

            target->CastSpell(target, SPELL_FOST_MARK, true);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_frozen_ground_aura_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_frozen_ground_aura_AuraScript;
    }
};

// 300698 frostvenom tipped
class bfa_spell_frostvenom_tipped : public SpellScriptLoader
{
public:
    bfa_spell_frostvenom_tipped() : SpellScriptLoader("bfa_spell_frostvenom_tipped") { }

    class bfa_spell_frostvenom_tipped_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_frostvenom_tipped_AuraScript);

        void HandleOnProc(const AuraEffect* aurEff, ProcEventInfo& eventInfo)
        {
            Unit* caster = eventInfo.GetActor();
            Unit* target = eventInfo.GetActionTarget();
            if (!caster || !target)
                return;

            if (target->HasAura(SPELL_FOST_MARK))
                caster->CastSpell(target, SPELL_RIMEFROST, true);
            else if (target->HasAura(SPELL_TOXIC_BRAND))
                caster->CastSpell(target, SPELL_SEPTIC_TAINT, true);
        }

        void Register()
        {
            OnEffectProc += AuraEffectProcFn(bfa_spell_frostvenom_tipped_AuraScript::HandleOnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_frostvenom_tipped_AuraScript();
    }
};

// 300701 rimefrost
class bfa_spell_rimefrost_aura : public SpellScriptLoader
{
public:
    bfa_spell_rimefrost_aura() : SpellScriptLoader("bfa_spell_rimefrost_aura") { }

    class bfa_spell_rimefrost_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_rimefrost_aura_AuraScript);

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;
            caster->CastSpell(caster, SPELL_FROZEN_GROUND_AT, true);
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_rimefrost_aura_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
        }

    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_rimefrost_aura_AuraScript();
    }
};

// 300705 septic taint
class bfa_spell_septic_taint_aura : public SpellScriptLoader
{
public:
    bfa_spell_septic_taint_aura() : SpellScriptLoader("bfa_spell_septic_taint_aura") { }

    class bfa_spell_septic_taint_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_septic_taint_aura_AuraScript);

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;
            caster->CastSpell(caster, SPELL_SEPTIC_GROUND_AT, true);
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_septic_taint_aura_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
        }

    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_septic_taint_aura_AuraScript();
    }
};

// frost bolt javelin
class bfa_spell_frost_bolt_javelin : public SpellScriptLoader
{
public:
    bfa_spell_frost_bolt_javelin() : SpellScriptLoader("bfa_spell_frost_bolt_javelin") { }

    class bfa_spell_frost_bolt_javelin_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_frost_bolt_javelin_SpellScript);

        bool IsOnBeam(WorldObject* obj, Position source, Position destination, float heightDiff, float beamWidth, float beamLenght)
        {
            if (beamLenght < obj->GetExactDist2d(source.GetPositionX(), source.GetPositionY()))
                return false;

            if (obj->GetPositionZ() - heightDiff > std::max(source.GetPositionZ(), destination.GetPositionZ()) &&
                obj->GetPositionZ() + heightDiff < std::min(source.GetPositionZ(), destination.GetPositionZ()))
                return false;

            float angleSourceDest = source.GetAngle(&destination);
            float angleSourcePoint = source.GetAngle(obj);

            float angle = fabs(angleSourceDest - angleSourcePoint);
            return fabs(sin(angle)) * source.GetExactDist2d(obj->GetPositionX(), obj->GetPositionY()) < beamWidth;
        }

        void AfterCast(SpellEffIndex index)
        {
            Unit* caster = GetCaster();
            Unit* target = caster->GetVictim();
            if (!caster || !target)
                return;


            Unit* maintrigger = caster;
            Unit* triggerTarget = target;
            Unit* targetPlayer = NULL;

            if (!maintrigger || !triggerTarget)
                return;

            Map::PlayerList const& playerList = maintrigger->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    Position myPos = maintrigger->GetPosition();
                    Position triggerPos = triggerTarget->GetPosition();
                    if (IsOnBeam(player, myPos, triggerPos, 3.0f, 2.0f, maintrigger->GetExactDist2d(triggerTarget)) && maintrigger->isInFront(player))
                    {
                        maintrigger->CastSpell(player, SPELL_FROSTBOLT_MISSILE, true);
                    }
                }
        }

        void Register()
        {
            OnEffectLaunch += SpellEffectFn(bfa_spell_frost_bolt_javelin_SpellScript::AfterCast, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_frost_bolt_javelin_SpellScript();
    }
};

// toxic bolt javelin
class bfa_spell_toxic_bolt_javelin : public SpellScriptLoader
{
public:
    bfa_spell_toxic_bolt_javelin() : SpellScriptLoader("bfa_spell_toxic_bolt_javelin") { }

    class bfa_spell_toxic_bolt_javelin_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_toxic_bolt_javelin_SpellScript);

        bool IsOnBeam(WorldObject* obj, Position source, Position destination, float heightDiff, float beamWidth, float beamLenght)
        {
            if (beamLenght < obj->GetExactDist2d(source.GetPositionX(), source.GetPositionY()))
                return false;

            if (obj->GetPositionZ() - heightDiff > std::max(source.GetPositionZ(), destination.GetPositionZ()) &&
                obj->GetPositionZ() + heightDiff < std::min(source.GetPositionZ(), destination.GetPositionZ()))
                return false;

            float angleSourceDest = source.GetAngle(&destination);
            float angleSourcePoint = source.GetAngle(obj);

            float angle = fabs(angleSourceDest - angleSourcePoint);
            return fabs(sin(angle)) * source.GetExactDist2d(obj->GetPositionX(), obj->GetPositionY()) < beamWidth;
        }

        void AfterCast(SpellEffIndex index)
        {
            Unit* caster = GetCaster();
            Unit* target = caster->GetVictim();
            if (!caster || !target)
                return;


            Unit* maintrigger = caster;
            Unit* triggerTarget = target;
            Unit* targetPlayer = NULL;

            if (!maintrigger || !triggerTarget)
                return;

            Map::PlayerList const& playerList = maintrigger->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    Position myPos = maintrigger->GetPosition();
                    Position triggerPos = triggerTarget->GetPosition();
                    if (IsOnBeam(player, myPos, triggerPos, 3.0f, 2.0f, maintrigger->GetExactDist2d(triggerTarget)) && maintrigger->isInFront(player))
                    {
                        maintrigger->CastSpell(player, SPELL_TOXICBOLT_MISSILE, true);
                    }
                }
        }

        void Register()
        {
            OnEffectLaunch += SpellEffectFn(bfa_spell_toxic_bolt_javelin_SpellScript::AfterCast, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_toxic_bolt_javelin_SpellScript();
    }
};

// 295791 inversion
class bfa_spell_inversion : public SpellScriptLoader
{
public:
    bfa_spell_inversion() : SpellScriptLoader("bfa_spell_inversion") { }

    class bfa_spell_inversion_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_inversion_SpellScript);

        void HandleInversion(SpellEffIndex index)
        {
            std::list<Player*> frostList;
            std::list<Player*> toxicList;

            frostList.clear();
            toxicList.clear();
            Unit* caster = GetCaster();
            if (!caster)
                return;

            Map::PlayerList const& playerList = caster->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (!player->IsGameMaster())
                    {
                        if (player->HasAura(SPELL_FOST_MARK))
                            frostList.push_back(player);

                        if (player->HasAura(SPELL_TOXIC_BRAND))
                            toxicList.push_back(player);
                    }
                }

            if (frostList.size())
            {
                frostList.resize(frostList.size() / 3);

                if (!frostList.empty())
                {
                    for (auto player : frostList)
                    {
                        if (Aura* frost = player->GetAura(SPELL_FOST_MARK))
                        {
                            uint8 stacks = frost->GetStackAmount();
                            if (Aura* toxic = player->AddAura(SPELL_TOXIC_BRAND, player))
                            {
                                player->CastSpell(player, SPELL_INVERSION_SICKNESS_VENOM, true);
                                toxic->SetStackAmount(stacks);
                            }
                        }
                    }
                }
            }

            if (toxicList.size())
            {
                toxicList.resize(toxicList.size() / 3);

                if (!toxicList.empty())
                {
                    for (auto player : toxicList)
                    {
                        if (Aura* toxic = player->GetAura(SPELL_TOXIC_BRAND))
                        {
                            uint8 stacks = toxic->GetStackAmount();
                            if (Aura* frost = player->AddAura(SPELL_FOST_MARK, player))
                            {
                                player->CastSpell(player, SPELL_INVERSION_SICKNESS_FROST, true);
                                frost->SetStackAmount(stacks);
                            }
                        }
                    }
                }
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(bfa_spell_inversion_SpellScript::HandleInversion, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_inversion_SpellScript();
    }
};

// 300883 inversion sickness venom
class bfa_spell_inversion_sickness_venom : public SpellScriptLoader
{
public:
    bfa_spell_inversion_sickness_venom() : SpellScriptLoader("bfa_spell_inversion_sickness_venom") { }

    class bfa_spell_inversion_sickness_venom_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_inversion_sickness_venom_AuraScript);

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;


            std::list<Player*> playerList;
            caster->GetPlayerListInGrid(playerList, 3.0f);
            if (playerList.size())
            {
                for (auto player : playerList)
                {
                    caster->CastSpell(player, SPELL_TOXIC_BRAND, true);
                }
            }
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_inversion_sickness_venom_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_ROOT, AURA_EFFECT_HANDLE_REAL);
        }

    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_inversion_sickness_venom_AuraScript();
    }
};

// 300882 inversion sickness frost
class bfa_spell_inversion_sickness_frost : public SpellScriptLoader
{
public:
    bfa_spell_inversion_sickness_frost() : SpellScriptLoader("bfa_spell_inversion_sickness_frost") { }

    class bfa_spell_inversion_sickness_frost_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_inversion_sickness_frost_AuraScript);

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;


            std::list<Player*> playerList;
            caster->GetPlayerListInGrid(playerList, 3.0f);
            if (playerList.size())
            {
                for (auto player : playerList)
                {
                    caster->CastSpell(player, SPELL_FOST_MARK, true);
                }
            }
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_inversion_sickness_frost_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_ROOT, AURA_EFFECT_HANDLE_REAL);
        }

    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_inversion_sickness_frost_AuraScript();
    }
};

// 294711 frost mark
class bfa_spell_frost_mark : public SpellScriptLoader
{
public:
    bfa_spell_frost_mark() : SpellScriptLoader("bfa_spell_frost_mark") { }

    class bfa_spell_frost_mark_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_frost_mark_AuraScript);

        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget();
            if (!caster || !target)
                return;

            if (target->GetMap()->IsHeroic() || target->GetMap()->IsMythic())
            {
                caster->AddAura(SPELL_FROZEN_BLOOD_BAR, target);
            }
        }

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget();
            if (!caster || !target)
                return;

            if (target->HasAura(SPELL_FROZEN_BLOOD_BAR))
                target->RemoveAura(SPELL_FROZEN_BLOOD_BAR);
        }

        void OnPeriodic(AuraEffect const* aurEff)
        {
            Unit* newTarget = NULL;
            Player* caster = GetCaster()->ToPlayer();
            Unit* target = GetTarget()->ToPlayer();
            if (!caster || !target)
                return;

            std::list<Player*> playerList;
            target->GetPlayerListInGrid(playerList, 2.0f);
            if (playerList.size())
            {
                for (auto player : playerList)
                {
                    if (caster == newTarget)
                        continue;

                    player->CastSpell(player, SPELL_UNSTABLE_MIXTURE, true);
                    if (Aura* frost = target->GetAura(SPELL_FOST_MARK))
                        frost->SetStackAmount(1);
                    if (Aura* frostPlayer = player->GetAura(SPELL_FOST_MARK))
                        frostPlayer->SetStackAmount(1);
                    if (Aura* toxic = target->GetAura(SPELL_TOXIC_BRAND))
                        toxic->SetStackAmount(1);
                    if (Aura* toxicPlayer = player->GetAura(SPELL_TOXIC_BRAND))
                        toxicPlayer->SetStackAmount(1);
                }
            }

            if (!target->isMoving())
                target->CastSpell(target, SPELL_FROZEN_BLOOD_ENERGIZE, true);
            else if (target->isMoving())
                target->SetPower(POWER_ALTERNATE_POWER, target->GetPower(POWER_ALTERNATE_POWER) - 5);

            if (target->GetPower(POWER_ALTERNATE_POWER) == 100)
            {
                target->CastSpell(target, SPELL_FROZEN_BAR_STUN, true);
                target->SetPower(POWER_ALTERNATE_POWER, 0);
            }
        }



        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_frost_mark_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectApply += AuraEffectRemoveFn(bfa_spell_frost_mark_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_frost_mark_AuraScript::OnPeriodic, EFFECT_3, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }

    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_frost_mark_AuraScript();
    }
};

// 294715 toxic brand
class bfa_spell_toxic_brand : public SpellScriptLoader
{
public:
    bfa_spell_toxic_brand() : SpellScriptLoader("bfa_spell_toxic_brand") { }

    class bfa_spell_toxic_brand_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_toxic_brand_AuraScript);

        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget();
            if (!caster || !target)
                return;

            if (target->GetMap()->IsHeroic() || target->GetMap()->IsMythic())
            {
                caster->AddAura(SPELL_VENOMOUS_BLOOD_BAR, target);
            }
        }

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget();
            if (!caster || !target)
                return;

            if (target->HasAura(SPELL_VENOMOUS_BLOOD_BAR))
                target->RemoveAura(SPELL_VENOMOUS_BLOOD_BAR);
        }

        void OnPeriodic(AuraEffect const* aurEff)
        {
            Unit* newTarget = NULL;
            Player* caster = GetCaster()->ToPlayer();
            Unit* target = GetTarget()->ToPlayer();
            if (!caster || !target)
                return;

            std::list<Player*> playerList;
            target->GetPlayerListInGrid(playerList, 2.0f);
            if (playerList.size())
            {
                for (auto player : playerList)
                {
                    if (caster == newTarget)
                        continue;

                    player->CastSpell(player, SPELL_UNSTABLE_MIXTURE, true);
                    if (Aura* frost = target->GetAura(SPELL_FOST_MARK))
                        frost->SetStackAmount(1);
                    if (Aura* frostPlayer = player->GetAura(SPELL_FOST_MARK))
                        frostPlayer->SetStackAmount(1);
                    if (Aura* toxic = target->GetAura(SPELL_TOXIC_BRAND))
                        toxic->SetStackAmount(1);
                    if (Aura* toxicPlayer = player->GetAura(SPELL_TOXIC_BRAND))
                        toxicPlayer->SetStackAmount(1);
                }
            }

            if (target->isMoving())
                target->CastSpell(target, SPELL_FROZEN_BLOOD_ENERGIZE, true);
            else if (!target->isMoving())
                target->SetPower(POWER_ALTERNATE_POWER, target->GetPower(POWER_ALTERNATE_POWER) - 5);

            if (target->GetPower(POWER_ALTERNATE_POWER) == 100)
            {
                target->CastSpell(target, SPELL_VENOMOUS_BLOOD_DELIRIOUS, true);
                target->SetPower(POWER_ALTERNATE_POWER, 0);
            }
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(bfa_spell_toxic_brand_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectApply += AuraEffectRemoveFn(bfa_spell_toxic_brand_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_toxic_brand_AuraScript::OnPeriodic, EFFECT_3, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }

    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_toxic_brand_AuraScript();
    }
};

// 295332 crushing reverberation 
class bfa_spell_crushing_reverberation : public SpellScriptLoader
{
public:
    bfa_spell_crushing_reverberation() : SpellScriptLoader("bfa_spell_crushing_reverberation") { }

    class bfa_spell_crushing_reverberation_SpellScript : public SpellScript
    {
        PrepareSpellScript(bfa_spell_crushing_reverberation_SpellScript);

        uint32 targetList;

        bool Load() override
        {
            targetList = 0;
            return true;
        }

        void HandleAfterCast()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->CastSpell(caster, SPELL_CRUSHING_REVERBERATION_TANK_MARK, true);
        }

        void CheckTargets(std::list<WorldObject*>& targets)
        {
            targetList = targets.size();
        }

        void RecalculateDamage(SpellEffIndex index)
        {
            SetHitDamage(GetHitDamage() / targetList);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_crushing_reverberation_SpellScript::CheckTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(bfa_spell_crushing_reverberation_SpellScript::RecalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            AfterCast += SpellCastFn(bfa_spell_crushing_reverberation_SpellScript::HandleAfterCast);

        }
    };

    SpellScript* GetSpellScript() const
    {
        return new bfa_spell_crushing_reverberation_SpellScript();
    }
};

// 298122 overwhelming barrage
class bfa_spell_overwhelming_barrage : public SpellScriptLoader
{
public:
    bfa_spell_overwhelming_barrage() : SpellScriptLoader("bfa_spell_overwhelming_barrage") { }

    class bfa_spell_overwhelming_barrage_AuraScript : public AuraScript
    {
        PrepareAuraScript(bfa_spell_overwhelming_barrage_AuraScript);

        uint32 point;

        bool Load() override
        {
            point = 1;
            return true;

        }
        void OnPeriodic(AuraEffect const* aurEff)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget();
            if (!caster || !target)
                return;

            float x = caster->GetPositionX() + 5.0f * cos(point * M_PI / 5);
            float y = caster->GetPositionY() + 5.0f * sin(point * M_PI / 5);

            if (point > 8)
            {
                caster->CastSpell(x, y, caster->GetPositionZ() + 3.0f, SPELL_OVERWHELMING_BARRAGE_FROST, true);
            }
            else
                caster->CastSpell(x, y, caster->GetPositionZ() + 3.0f, SPELL_OVERWHELMING_BARRAGE_TOXIC, true);
            ++point;

        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_overwhelming_barrage_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new bfa_spell_overwhelming_barrage_AuraScript();
    }
};

// 16564,16563
class bfa_at_toxic_frost_bolts : public AreaTriggerEntityScript
{
public:
    bfa_at_toxic_frost_bolts() : AreaTriggerEntityScript("bfa_at_toxic_frost_bolts")
    {}

    struct bfa_at_toxic_frost_bolts_AI : public AreaTriggerAI
    {
        bfa_at_toxic_frost_bolts_AI(AreaTrigger* at) : AreaTriggerAI(at)
        {}

        void SetupSpline()
        {
            if (!at->GetCaster())
                return;

            std::vector<G3D::Vector3> points;
            float dist = 100.f;

            G3D::Vector3 src = { at->GetPositionX(), at->GetPositionY(), at->GetPositionZ() };
            G3D::Vector3 tgt;

            tgt.x = src.x + (dist * cosf(at->GetOrientation() * M_PI / 2));
            tgt.y = src.y + (dist * sinf(-at->GetOrientation() * M_PI / 2));
            tgt.z = src.z;

            float dx = (tgt.x - src.x);
            float dy = (tgt.y - src.y);
            float dz = (tgt.z - src.z);

            for (uint32 i = 0; i < 100; ++i)
            {
                switch (at->GetEntry())
                {
                case AT_FROST:
                    src.x += (dx / dist);
                    src.y += (dy / dist);
                    break;
                case AT_TOXIC:
                    src.x -= (dx / dist);
                    src.y -= (dy / dist);
                    break;
                }

                points.push_back(src);
            }

            at->InitSplines(points, 5000);
        }

        void OnInitialize() override
        {
            SetupSpline();
        }

        void OnUpdate(uint32 diff)
        {
            Map::PlayerList const& playerList = at->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (!player->IsGameMaster()) //gm check
                    {
                        if (player->GetDistance(at) <= 2.0f)
                        {
                            switch (at->GetEntry())
                            {
                            case AT_FROST:
                                player->CastSpell(player, SPELL_FOST_MARK, true);
                                break;
                            case AT_TOXIC:
                                player->CastSpell(player, SPELL_TOXIC_BRAND, true);
                                break;
                            }
                        }
                    }
                }
        }

    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new bfa_at_toxic_frost_bolts_AI(at);
    }
};

void AddSC_boss_commander_sivara()
{
    new bfa_boss_commander_sivara();
    new bfa_at_frozen_ground();
    new bfa_at_septic_ground();
    new bfa_at_toxic_frost_bolts();
    new bfa_spell_chimeric_marks();
    new bfa_spell_crushing_reverberation();
    new bfa_spell_frostvenom_tipped();
    new bfa_spell_frost_bolt_javelin();
    new bfa_spell_frost_mark();
    new bfa_spell_frozen_ground_aura();
    new bfa_spell_inversion();
    new bfa_spell_inversion_sickness_frost();
    new bfa_spell_inversion_sickness_venom();
    new bfa_spell_overflow();
    new bfa_spell_overflowing_chill_venom_aura();
    new bfa_spell_overflowing_chill_venom_damage();
    new bfa_spell_rimefrost_aura();
    new bfa_spell_septic_ground_aura();
    new bfa_spell_septic_taint_aura();
    new bfa_spell_toxic_bolt_javelin();
    new bfa_spell_toxic_brand();
    new bfa_spell_overwhelming_barrage();
}

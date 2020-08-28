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

#include "shadowfang_keep.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "CreatureAIImpl.h"
#include "Map.h"

enum Spells
{
    // Commander Springvale
    SPELL_MALEFIC_STRIKE                    = 93685,
    SPELL_UNHOLY_POWER                      = 93686,
    SPELL_UNHOLY_POWER_HC                   = 93735,
    SPELL_SHIELD_OF_THE_PERFIDIOUS_DUMMY    = 93716,
    SPELL_SHIELD_OF_THE_PERFIDIOUS          = 93693,
    SPELL_DESECRATION_DUMMY                 = 93688,
    SPELL_DESECRATION                       = 93687,
    SPELL_DESECRATION_ARM_AURA              = 67803,
    SPELL_WORD_OF_SHAME                     = 93852,

    // Wailing Guardsman
    SPELL_UNHOLY_EMPOWERMENT                = 93844,
    SPELL_SCREAMS_OF_THE_PAST               = 7074,
    SPELL_MORTAL_STRIKE                     = 91801,

    //Tormented Officer
    SPELL_FORSAKEN_ABILITY                  = 7054,
    SPELL_FORSAKEN_ABILITY_DAMAGE           = 7038,
    SPELL_FORSAKEN_ABILITY_ARMOR            = 7039,
    SPELL_FORSAKEN_ABILITY_HEAL             = 7041,
    SPELL_FORSAKEN_ABILITY_SPEED            = 7042,
    SPELL_FORSAKEN_ABILITY_HEALTH           = 7040,
    SPELL_SHIELD_WALL                       = 91463
};

enum Texts
{
    SAY_AGGRO   = 0,
    SAY_ADDS    = 1,
    SAY_SLAY    = 2,
    SAY_DEATH   = 3
};

enum Events
{
    // Commander Springvale
    EVENT_MALEFIC_STRIKE = 1,
    EVENT_SHIELD_OF_THE_PERFIDIOUS,
    EVENT_DESECRATION,
    EVENT_SUMMON_ADDS,
    EVENT_WORD_OF_SHAME,

    // Wailing Guardsman
    EVENT_UNHOLY_EMPOWERMENT,
    EVENT_SCREAMS_OF_THE_PAST,
    EVENT_MORTAL_STRIKE,

    // Tormented Officer
    EVENT_FORSAKEN_ABILITY
};

enum Actions
{
    ACTION_UNHOLY_POWER = 1,
    ACTION_TO_THE_GROUND
};

enum AchievementData
{
    DATA_TO_THE_GROUND = 1
};

// Heroic additional adds
Position const OfficerPos = {-229.681f, 2260.03f, 102.84f, 3.45575f};
Position const GuardsmanPos = {-228.33f, 2254.39f, 102.84f, 3.36848f};

// Encounter spawn positions
Position const SpawnPos[] =
{
    {-235.5069f, 2230.76f, 93.70721f, 0.0f}, // Wailing Guardsman
    {-266.2257f, 2270.207f, 96.51828f, 0.0f} // Tormented Officer
};

class boss_commander_springvale : public CreatureScript
{
public:
    boss_commander_springvale() : CreatureScript("boss_commander_springvale") { }

    struct boss_commander_springvaleAI : public BossAI
    {
        boss_commander_springvaleAI(Creature* creature) : BossAI(creature, DATA_COMMANDER_SPRINGVALE) { }

        void Reset() override
        {
            _Reset();
            _toTheGround = true;
            if (IsHeroic())
            {
                DoSummon(NPC_WAILING_GUARDSMAN, GuardsmanPos, 4000, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                DoSummon(NPC_TORMENTED_OFFICER, OfficerPos, 4000, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
            }
            /*
            else
            {
                // Fill this case with the path that Commander Springvale is walking in normal mode
            }
            */
        }

        void JustEngagedWith(Unit* who) override
        {
            BossAI::JustEngagedWith(who);
            Talk(SAY_AGGRO);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            events.ScheduleEvent(EVENT_MALEFIC_STRIKE, Seconds(5));
            events.ScheduleEvent(EVENT_DESECRATION, Seconds(9) + Milliseconds(500));
            if (IsHeroic())
                events.ScheduleEvent(EVENT_SUMMON_ADDS, Seconds(41));
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_WORD_OF_SHAME);
        }

        void KilledUnit(Unit* target) override
        {
            if (target->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            _EnterEvadeMode();
            summons.DespawnAll();
            instance->SetBossState(DATA_COMMANDER_SPRINGVALE, FAIL);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_WORD_OF_SHAME);
            _DespawnAtEvade();
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
            switch (summon->GetEntry())
            {
                case NPC_TORMENTED_OFFICER:
                case NPC_WAILING_GUARDSMAN:
                    if (me->IsInCombat())
                        summon->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), true);
                    break;
                case NPC_SHIELD_FOCUS:
                    me->StopMoving();
                    me->SetFacingToObject(summon);
                    DoCast(summon, SPELL_SHIELD_OF_THE_PERFIDIOUS);
                    break;
                default:
                    break;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_TO_THE_GROUND:
                    return _toTheGround;
                default:
                    break;
            }
            return 0;
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_UNHOLY_POWER:
                    if (IsHeroic())
                    {
                        switch (urand(0, 1))
                        {
                            case 0:
                                events.ScheduleEvent(EVENT_SHIELD_OF_THE_PERFIDIOUS, Seconds(1));
                                break;
                            case 1:
                                events.ScheduleEvent(EVENT_WORD_OF_SHAME, Seconds(1));
                                break;
                            default:
                                break;
                        }
                    }
                    else
                        events.ScheduleEvent(EVENT_SHIELD_OF_THE_PERFIDIOUS, Seconds(1));
                    break;
                case ACTION_TO_THE_GROUND:
                    _toTheGround = false;
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

            while(uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_MALEFIC_STRIKE:
                        if (!me->HasAura(SPELL_SHIELD_OF_THE_PERFIDIOUS))
                            DoCastVictim(SPELL_MALEFIC_STRIKE);
                        events.Repeat(Seconds(5), Seconds(6));
                        break;
                    case EVENT_SHIELD_OF_THE_PERFIDIOUS:
                        me->RemoveAurasDueToSpell(SPELL_UNHOLY_POWER);
                        me->RemoveAurasDueToSpell(SPELL_UNHOLY_POWER_HC);
                        DoCast(SPELL_SHIELD_OF_THE_PERFIDIOUS_DUMMY);
                        break;
                    case EVENT_DESECRATION:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            DoCast(target, SPELL_DESECRATION);
                        events.Repeat(Seconds(28));
                        break;
                    case EVENT_SUMMON_ADDS:
                        Talk(SAY_ADDS);
                        DoSummon(NPC_WAILING_GUARDSMAN, SpawnPos[0], 4000, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                        DoSummon(NPC_TORMENTED_OFFICER, SpawnPos[1], 4000, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                        events.Repeat(Seconds(41));
                        break;
                    case EVENT_WORD_OF_SHAME:
                        me->RemoveAurasDueToSpell(SPELL_UNHOLY_POWER);
                        me->RemoveAurasDueToSpell(SPELL_UNHOLY_POWER_HC);
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, true, -SPELL_WORD_OF_SHAME))
                            DoCast(target, SPELL_WORD_OF_SHAME, true);
                        else
                            events.ScheduleEvent(EVENT_SHIELD_OF_THE_PERFIDIOUS, Milliseconds(1));
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    private:
        bool _toTheGround;

    };
    CreatureAI* GetAI(Creature *creature) const override
    {
        return GetShadowfangKeepAI<boss_commander_springvaleAI>(creature);
    }
};

class npc_wailing_guardsman : public CreatureScript
{
public:
    npc_wailing_guardsman() :  CreatureScript("npc_wailing_guardsman") { }

    struct npc_wailing_guardsmanAI : public ScriptedAI
    {
        npc_wailing_guardsmanAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

        void JustEngagedWith(Unit* who) override
        {
            if (Creature* tormentedOfficer = me->FindNearestCreature(NPC_TORMENTED_OFFICER, 20.0f))
                tormentedOfficer->AI()->AttackStart(who);
            _events.ScheduleEvent(EVENT_MORTAL_STRIKE, Seconds(11));
            _events.ScheduleEvent(EVENT_SCREAMS_OF_THE_PAST, Seconds(14));
            _events.ScheduleEvent(EVENT_UNHOLY_EMPOWERMENT, Seconds(28), Seconds(30));
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_MORTAL_STRIKE:
                        DoCastVictim(SPELL_MORTAL_STRIKE);
                        _events.Repeat(Seconds(12));
                        break;
                    case EVENT_SCREAMS_OF_THE_PAST:
                        DoCastAOE(SPELL_SCREAMS_OF_THE_PAST);
                        break;
                    case EVENT_UNHOLY_EMPOWERMENT:
                        if (Creature* springvale = _instance->GetCreature(DATA_COMMANDER_SPRINGVALE))
                            DoCast(springvale, SPELL_UNHOLY_EMPOWERMENT);
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    private:
        InstanceScript* _instance;
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetShadowfangKeepAI<npc_wailing_guardsmanAI>(creature);
    }
};

class npc_tormented_officer : public CreatureScript
{
public:
    npc_tormented_officer() :  CreatureScript("npc_tormented_officer") { }

    struct npc_tormented_officerAI : public ScriptedAI
    {
        npc_tormented_officerAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

        void JustEngagedWith(Unit* who) override
        {
            if (Creature* wailingGuardsman = me->FindNearestCreature(NPC_WAILING_GUARDSMAN, 20.0f))
                wailingGuardsman->AI()->AttackStart(who);
            _shielded = false;
            _events.ScheduleEvent(EVENT_UNHOLY_EMPOWERMENT, Seconds(28), Seconds(30));
            _events.ScheduleEvent(EVENT_FORSAKEN_ABILITY, Seconds(17));
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (me->HealthBelowPctDamaged(20, damage) && !_shielded)
            {
                DoCast(me, SPELL_SHIELD_WALL);
                _shielded = true;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_FORSAKEN_ABILITY:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                            DoCast(target, SPELL_FORSAKEN_ABILITY);
                        break;
                    case EVENT_UNHOLY_EMPOWERMENT:
                        if (Creature* springvale = _instance->GetCreature(DATA_COMMANDER_SPRINGVALE))
                            DoCast(springvale, SPELL_UNHOLY_EMPOWERMENT);
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
        private:
            InstanceScript* _instance;
            EventMap _events;
            bool _shielded;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetShadowfangKeepAI<npc_tormented_officerAI>(creature);
    }
};

class spell_sfk_forsaken_ability : public SpellScriptLoader
{
    public:
        spell_sfk_forsaken_ability() : SpellScriptLoader("spell_sfk_forsaken_ability") { }

        class spell_sfk_forsaken_ability_AuraScript : public AuraScript
        {
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_FORSAKEN_ABILITY_DAMAGE,
                    SPELL_FORSAKEN_ABILITY_ARMOR,
                    SPELL_FORSAKEN_ABILITY_SPEED,
                    SPELL_FORSAKEN_ABILITY_HEAL,
                    SPELL_FORSAKEN_ABILITY_HEALTH
                });
            }

            void OnPeriodic(AuraEffect const* /*aurEff*/)
            {
                if (Unit* owner = GetOwner()->ToUnit())
                {
                    switch (RAND(0, 4))
                    {
                        case 0: // Damage
                            owner->CastSpell(owner, SPELL_FORSAKEN_ABILITY_DAMAGE, true);
                            break;
                        case 1: // Armor
                            owner->CastSpell(owner, SPELL_FORSAKEN_ABILITY_ARMOR, true);
                            break;
                        case 2: // Speed
                            owner->CastSpell(owner, SPELL_FORSAKEN_ABILITY_SPEED, true);
                            break;
                        case 3: // Heal
                            owner->CastSpell(owner, SPELL_FORSAKEN_ABILITY_HEAL, true);
                            break;
                        case 4: // Health
                            owner->CastSpell(owner, SPELL_FORSAKEN_ABILITY_HEALTH, true);
                            break;
                    }
                }
            }

            void Register() override
            {
                OnEffectPeriodic.Register(&spell_sfk_forsaken_ability_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sfk_forsaken_ability_AuraScript();
        }
};

class spell_sfk_unholy_power : public SpellScriptLoader
{
public:
    spell_sfk_unholy_power() : SpellScriptLoader("spell_sfk_unholy_power") { }

    class spell_sfk_unholy_power_SpellScript : public SpellScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
            {
                SPELL_UNHOLY_POWER_HC,
                SPELL_UNHOLY_POWER
            });
        }

        void HandleStacks()
        {
            if (Unit* target = GetHitUnit())
            {
                Aura* aura = nullptr;
                aura = target->GetAura(SPELL_UNHOLY_POWER_HC);
                if (!aura)
                    target->GetAura(SPELL_UNHOLY_POWER);

                if (aura)
                    if (aura->GetStackAmount() == 3)
                        if (target->GetTypeId() == TYPEID_UNIT && target->IsAIEnabled)
                            target->ToCreature()->AI()->DoAction(ACTION_UNHOLY_POWER);
            }
        }

        void Register() override
        {
            
            AfterHit.Register(&spell_sfk_unholy_power_SpellScript::HandleStacks);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sfk_unholy_power_SpellScript();
    }
};

class spell_sfk_unholy_empowerment : public SpellScriptLoader
{
public:
    spell_sfk_unholy_empowerment() : SpellScriptLoader("spell_sfk_unholy_empowerment") { }

    class spell_sfk_unholy_empowerment_SpellScript : public SpellScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
            {
                SPELL_UNHOLY_POWER_HC,
                SPELL_UNHOLY_POWER
            });

            return true;
        }

        void HandleStacks()
        {
            if (Unit* target = GetHitUnit())
            {
                Aura* aura = nullptr;
                aura = target->GetAura(SPELL_UNHOLY_POWER_HC);
                if (!aura)
                    target->GetAura(SPELL_UNHOLY_POWER);

                if (aura)
                    if (aura->GetStackAmount() == 3)
                        if (target->GetTypeId() == TYPEID_UNIT && target->IsAIEnabled)
                            target->ToCreature()->AI()->DoAction(ACTION_UNHOLY_POWER);

                if (target->GetTypeId() == TYPEID_UNIT && target->IsAIEnabled)
                    target->ToCreature()->AI()->DoAction(ACTION_TO_THE_GROUND);
            }
        }

        void Register() override
        {
            AfterHit.Register(&spell_sfk_unholy_empowerment_SpellScript::HandleStacks);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sfk_unholy_empowerment_SpellScript();
    }
};

class achievement_to_the_ground : public AchievementCriteriaScript
{
public:
    achievement_to_the_ground() : AchievementCriteriaScript("achievement_to_the_ground") { }

    bool OnCheck(Player* /*source*/, Unit* target)
    {
        if (!target)
            return false;

        if (target->GetMap()->IsHeroic())
            return target->GetAI()->GetData(DATA_TO_THE_GROUND);

        return false;
    }
};

void AddSC_boss_commander_springvale()
{
    new boss_commander_springvale();
    new npc_wailing_guardsman();
    new npc_tormented_officer();
    new spell_sfk_forsaken_ability();
    new spell_sfk_unholy_power();
    new spell_sfk_unholy_empowerment();
    new achievement_to_the_ground();
}

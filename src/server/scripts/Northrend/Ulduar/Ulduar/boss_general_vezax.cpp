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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "ulduar.h"

enum VezaxYells
{
    SAY_AGGRO                                    = 0,
    SAY_SLAY                                     = 1,
    SAY_SURGE_OF_DARKNESS                        = 2,
    SAY_DEATH                                    = 3,
    SAY_BERSERK                                  = 4,
    SAY_HARDMODE                                 = 5,
};

enum VezaxEmotes
{
    EMOTE_ANIMUS                                 = 6,
    EMOTE_BARRIER                                = 7,
    EMOTE_SURGE_OF_DARKNESS                      = 8,

    // Saronite Vapor
    EMOTE_VAPORS                                 = 0
};

enum VezaxSpells
{
    SPELL_AURA_OF_DESPAIR                        = 62692,
    SPELL_MARK_OF_THE_FACELESS                   = 63276,
    SPELL_MARK_OF_THE_FACELESS_DAMAGE            = 63278,
    SPELL_SARONITE_BARRIER                       = 63364,
    SPELL_SEARING_FLAMES                         = 62661,
    SPELL_SHADOW_CRASH                           = 62660,
    SPELL_SHADOW_CRASH_HIT                       = 62659,
    SPELL_SURGE_OF_DARKNESS                      = 62662,
    SPELL_SARONITE_VAPORS                        = 63323,
    SPELL_SARONITE_VAPORS_ENERGIZE               = 63337,
    SPELL_SARONITE_VAPORS_DAMAGE                 = 63338,
    SPELL_SUMMON_SARONITE_VAPORS                 = 63081,
    SPELL_BERSERK                                = 26662,

    SPELL_SUMMON_SARONITE_ANIMUS                 = 63145,
    SPELL_VISUAL_SARONITE_ANIMUS                 = 63319,
    SPELL_PROFOUND_OF_DARKNESS                   = 63420,

    SPELL_CORRUPTED_RAGE                         = 68415,
    SPELL_SHAMANTIC_RAGE                         = 30823,
};

enum VezaxActions
{
    ACTION_VAPORS_SPAWN,
    ACTION_VAPORS_DIE,
    ACTION_ANIMUS_DIE,
};

enum VezaxEvents
{
    // Vezax
    EVENT_SHADOW_CRASH                           = 1,
    EVENT_SEARING_FLAMES                         = 2,
    EVENT_SURGE_OF_DARKNESS                      = 3,
    EVENT_MARK_OF_THE_FACELESS                   = 4,
    EVENT_SARONITE_VAPORS                        = 5,
    EVENT_BERSERK                                = 6,

    // Saronite Animus
    EVENT_PROFOUND_OF_DARKNESS                   = 7,

    // Saronite Vapor
    EVENT_RANDOM_MOVE                            = 8,
};

enum Misc
{
    DATA_SMELL_SARONITE                          = 31813188,
    DATA_SHADOWDODGER                            = 29962997
};

class boss_general_vezax : public CreatureScript
{
    public:
        boss_general_vezax() : CreatureScript("boss_general_vezax") { }

        struct boss_general_vezaxAI : public BossAI
        {
            boss_general_vezaxAI(Creature* creature) : BossAI(creature, DATA_VEZAX)
            {
                Initialize();
            }

            void Initialize()
            {
                shadowDodger = true;
                smellSaronite = true;
                animusDead = false;
                vaporCount = 0;
            }

            bool shadowDodger;
            bool smellSaronite; // HardMode
            bool animusDead; // Check against getting a HardMode achievement before killing Saronite Animus
            uint8 vaporCount;

            void Reset() override
            {
                _Reset();

                Initialize();
            }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);

                Talk(SAY_AGGRO);
                DoCast(me, SPELL_AURA_OF_DESPAIR);
                CheckShamanisticRage();

                events.ScheduleEvent(EVENT_SHADOW_CRASH, 8s, 10s);
                events.ScheduleEvent(EVENT_SEARING_FLAMES, 12s);
                events.ScheduleEvent(EVENT_MARK_OF_THE_FACELESS, 35s, 40s);
                events.ScheduleEvent(EVENT_SARONITE_VAPORS, 30s);
                events.ScheduleEvent(EVENT_SURGE_OF_DARKNESS, 1min);
                events.ScheduleEvent(EVENT_BERSERK, 10min);
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
                        case EVENT_SHADOW_CRASH:
                        {
                            Unit* target = CheckPlayersInRange(RAID_MODE<uint8>(4, 9), 15.0f, 50.0f);
                            if (!target)
                                target = SelectTarget(SelectTargetMethod::Random, 0, 150.0f, true);
                            if (target)
                                DoCast(target, SPELL_SHADOW_CRASH);
                            events.ScheduleEvent(EVENT_SHADOW_CRASH, 8s, 12s);
                            break;
                        }
                        case EVENT_SEARING_FLAMES:
                            DoCastAOE(SPELL_SEARING_FLAMES);
                            events.ScheduleEvent(EVENT_SEARING_FLAMES, 14s, 17500ms);
                            break;
                        case EVENT_MARK_OF_THE_FACELESS:
                        {
                            Unit* target = CheckPlayersInRange(RAID_MODE<uint8>(4, 9), 15.0f, 50.0f);
                            if (!target)
                                target = SelectTarget(SelectTargetMethod::Random, 0, 150.0f, true);
                            if (target)
                                DoCast(target, SPELL_MARK_OF_THE_FACELESS);
                            events.ScheduleEvent(EVENT_MARK_OF_THE_FACELESS, 35s, 45s);
                            break;
                        }
                        case EVENT_SURGE_OF_DARKNESS:
                            Talk(EMOTE_SURGE_OF_DARKNESS);
                            Talk(SAY_SURGE_OF_DARKNESS);
                            DoCast(me, SPELL_SURGE_OF_DARKNESS);
                            events.ScheduleEvent(EVENT_SURGE_OF_DARKNESS, 50s, 70s);
                            break;
                        case EVENT_SARONITE_VAPORS:
                            DoCast(SPELL_SUMMON_SARONITE_VAPORS);
                            events.ScheduleEvent(EVENT_SARONITE_VAPORS, 30s, 35s);
                            if (++vaporCount == 6 && smellSaronite)
                            {
                                Talk(SAY_HARDMODE);
                                Talk(EMOTE_BARRIER);
                                summons.DespawnAll();
                                DoCast(me, SPELL_SARONITE_BARRIER);
                                DoCast(SPELL_SUMMON_SARONITE_ANIMUS);
                                me->AddLootMode(LOOT_MODE_HARD_MODE_1);
                                events.CancelEvent(EVENT_SARONITE_VAPORS);
                                events.CancelEvent(EVENT_SEARING_FLAMES);
                            }
                            break;
                        case EVENT_BERSERK:
                            Talk(SAY_BERSERK);
                            DoCast(me, SPELL_BERSERK);
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }

            void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
            {
                if (target->GetTypeId() == TYPEID_PLAYER && spellInfo->Id == SPELL_SHADOW_CRASH_HIT)
                    shadowDodger = false;
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_AURA_OF_DESPAIR, true, true);
            }

            void CheckShamanisticRage()
            {
                // If Shaman has Shamanistic Rage and use it during the fight, it will cast Corrupted Rage on him
                Map::PlayerList const& Players = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end(); ++itr)
                    if (Player* player = itr->GetSource())
                        if (player->HasSpell(SPELL_SHAMANTIC_RAGE))
                            player->CastSpell(player, SPELL_CORRUPTED_RAGE, false);
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_SHADOWDODGER:
                        return shadowDodger ? 1 : 0;
                    case DATA_SMELL_SARONITE:
                        return smellSaronite ? 1 : 0;
                }

                return 0;
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_VAPORS_DIE:
                        smellSaronite = false;
                        break;
                    case ACTION_ANIMUS_DIE:
                        me->RemoveAurasDueToSpell(SPELL_SARONITE_BARRIER);
                        events.ScheduleEvent(EVENT_SEARING_FLAMES, 7s, 12s);
                        animusDead = true;
                        break;
                }
            }

            /*  Player Range Check
                Purpose: If there are playersMin people within rangeMin, rangeMax: return a random players in that range.
                If not, return nullptr and allow other target selection
            */
            Unit* CheckPlayersInRange(uint8 playersMin, float rangeMin, float rangeMax)
            {
                std::list<Player*> PlayerList;
                Map::PlayerList const& Players = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end(); ++itr)
                {
                    if (Player* player = itr->GetSource())
                    {
                        float distance = player->GetDistance(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                        if (rangeMin > distance || distance > rangeMax)
                            continue;

                        PlayerList.push_back(player);
                    }
                }

                if (PlayerList.empty())
                    return nullptr;

                size_t size = PlayerList.size();
                if (size < playersMin)
                    return nullptr;

                return Trinity::Containers::SelectRandomContainerElement(PlayerList);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<boss_general_vezaxAI>(creature);
        }
};

class boss_saronite_animus : public CreatureScript
{
    public:
        boss_saronite_animus() : CreatureScript("npc_saronite_animus") { }

        struct boss_saronite_animusAI : public ScriptedAI
        {
            boss_saronite_animusAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = me->GetInstanceScript();
            }

            void Reset() override
            {
                DoCast(me, SPELL_VISUAL_SARONITE_ANIMUS);
                events.Reset();
                events.ScheduleEvent(EVENT_PROFOUND_OF_DARKNESS, 3s);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (Creature* vezax = instance->GetCreature(DATA_VEZAX))
                    vezax->AI()->DoAction(ACTION_ANIMUS_DIE);
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
                        case EVENT_PROFOUND_OF_DARKNESS:
                            DoCastAOE(SPELL_PROFOUND_OF_DARKNESS, true);
                            events.ScheduleEvent(EVENT_PROFOUND_OF_DARKNESS, 3s);
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* instance;
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<boss_saronite_animusAI>(creature);
        }
};

class npc_saronite_vapors : public CreatureScript
{
    public:
        npc_saronite_vapors() : CreatureScript("npc_saronite_vapors") { }

        struct npc_saronite_vaporsAI : public ScriptedAI
        {
            npc_saronite_vaporsAI(Creature* creature) : ScriptedAI(creature)
            {
                Talk(EMOTE_VAPORS);
                instance = me->GetInstanceScript();
                me->ApplySpellImmune(0, IMMUNITY_ID, 49560, true); // Death Grip jump effect
                me->SetReactState(REACT_PASSIVE);
            }

            void Reset() override
            {
                events.Reset();
                events.ScheduleEvent(EVENT_RANDOM_MOVE, 5s, 7500ms);
            }

            void UpdateAI(uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RANDOM_MOVE:
                            me->GetMotionMaster()->MoveRandom(30.0f);
                            events.ScheduleEvent(EVENT_RANDOM_MOVE, 5s, 7500ms);
                            break;
                        default:
                            break;
                    }
                }
            }

            void DamageTaken(Unit* /*who*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
            {
                // This can't be on JustDied. In 63322 dummy handler caster needs to be this NPC
                // if caster == target then damage mods will increase the damage taken
                if (damage >= me->GetHealth())
                {
                    damage = 0;
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_UNINTERACTIBLE);
                    me->SetControlled(true, UNIT_STATE_ROOT);
                    me->SetStandState(UNIT_STAND_STATE_DEAD);
                    me->SetHealth(me->GetMaxHealth());
                    me->RemoveAllAuras();
                    DoCast(me, SPELL_SARONITE_VAPORS);
                    me->DespawnOrUnsummon(30s);

                    if (Creature* vezax = instance->GetCreature(DATA_VEZAX))
                        vezax->AI()->DoAction(ACTION_VAPORS_DIE);
                }
            }

        private:
            InstanceScript* instance;
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<npc_saronite_vaporsAI>(creature);
        }
};

// 63276 - Mark of the Faceless
class spell_general_vezax_mark_of_the_faceless : public SpellScriptLoader
{
    public:
        spell_general_vezax_mark_of_the_faceless() : SpellScriptLoader("spell_general_vezax_mark_of_the_faceless") { }

        class spell_general_vezax_mark_of_the_faceless_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_general_vezax_mark_of_the_faceless_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_MARK_OF_THE_FACELESS_DAMAGE });
            }

            void HandleEffectPeriodic(AuraEffect const* aurEff)
            {
                if (Unit* caster = GetCaster())
                {
                    CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                    args.AddSpellMod(SPELLVALUE_BASE_POINT1, aurEff->GetAmount());
                    caster->CastSpell(GetTarget(), SPELL_MARK_OF_THE_FACELESS_DAMAGE, args);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_general_vezax_mark_of_the_faceless_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_general_vezax_mark_of_the_faceless_AuraScript();
        }
};

// 63278 - Mark of the Faceless
class spell_general_vezax_mark_of_the_faceless_leech : public SpellScriptLoader
{
    public:
        spell_general_vezax_mark_of_the_faceless_leech() : SpellScriptLoader("spell_general_vezax_mark_of_the_faceless_leech") { }

        class spell_general_vezax_mark_of_the_faceless_leech_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_general_vezax_mark_of_the_faceless_leech_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove(GetExplTargetWorldObject());

                if (targets.empty())
                    FinishCast(SPELL_FAILED_NO_VALID_TARGETS);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_general_vezax_mark_of_the_faceless_leech_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_general_vezax_mark_of_the_faceless_leech_SpellScript();
        }
};

// 63322 - Saronite Vapors
class spell_general_vezax_saronite_vapors : public SpellScriptLoader
{
    public:
        spell_general_vezax_saronite_vapors() : SpellScriptLoader("spell_general_vezax_saronite_vapors") { }

        class spell_general_vezax_saronite_vapors_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_general_vezax_saronite_vapors_AuraScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_SARONITE_VAPORS_ENERGIZE, SPELL_SARONITE_VAPORS_DAMAGE });
            }

            void HandleEffectApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                {
                    int32 mana = int32(aurEff->GetAmount() * std::pow(2.0f, GetStackAmount())); // mana restore - bp * 2^stackamount
                    CastSpellExtraArgs args1(TRIGGERED_FULL_MASK), args2(TRIGGERED_FULL_MASK);
                    args1.AddSpellBP0(mana);
                    args2.AddSpellBP0(mana * 2);
                    caster->CastSpell(GetTarget(), SPELL_SARONITE_VAPORS_ENERGIZE, args1);
                    caster->CastSpell(GetTarget(), SPELL_SARONITE_VAPORS_DAMAGE, args2);
                }
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_general_vezax_saronite_vapors_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_general_vezax_saronite_vapors_AuraScript();
        }
};

class achievement_shadowdodger : public AchievementCriteriaScript
{
    public:
        achievement_shadowdodger() : AchievementCriteriaScript("achievement_shadowdodger")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Vezax = target->ToCreature())
                if (Vezax->AI()->GetData(DATA_SHADOWDODGER))
                    return true;

            return false;
        }
};

class achievement_smell_saronite : public AchievementCriteriaScript
{
    public:
        achievement_smell_saronite() : AchievementCriteriaScript("achievement_smell_saronite")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Vezax = target->ToCreature())
                if (Vezax->AI()->GetData(DATA_SMELL_SARONITE))
                    return true;

            return false;
        }
};

void AddSC_boss_general_vezax()
{
    new boss_general_vezax();
    new boss_saronite_animus();
    new npc_saronite_vapors();
    new spell_general_vezax_mark_of_the_faceless();
    new spell_general_vezax_mark_of_the_faceless_leech();
    new spell_general_vezax_saronite_vapors();
    new achievement_shadowdodger();
    new achievement_smell_saronite();
}

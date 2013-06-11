/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "ulduar.h"
#include "Player.h"

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
    EMOTE_VAPORS                                 = 9
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

#define DATA_SMELL_SARONITE                      31813188
#define DATA_SHADOWDODGER                        29962997

class boss_general_vezax : public CreatureScript
{
    public:
        boss_general_vezax() : CreatureScript("boss_general_vezax") { }

        struct boss_general_vezaxAI : public BossAI
        {
            boss_general_vezaxAI(Creature* creature) : BossAI(creature, BOSS_VEZAX)
            {
            }

            bool shadowDodger;
            bool smellSaronite; // HardMode
            bool animusDead; // Check against getting a HardMode achievement before killing Saronite Animus
            uint8 vaporCount;

            void Reset()
            {
                _Reset();

                shadowDodger = true;
                smellSaronite = true;
                animusDead = false;
                vaporCount = 0;
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();

                Talk(SAY_AGGRO);
                DoCast(me, SPELL_AURA_OF_DESPAIR);
                CheckShamanisticRage();

                events.ScheduleEvent(EVENT_SHADOW_CRASH, urand(8000, 10000));
                events.ScheduleEvent(EVENT_SEARING_FLAMES, 12000);
                events.ScheduleEvent(EVENT_MARK_OF_THE_FACELESS, urand(35000, 40000));
                events.ScheduleEvent(EVENT_SARONITE_VAPORS, 30000);
                events.ScheduleEvent(EVENT_SURGE_OF_DARKNESS, 60000);
                events.ScheduleEvent(EVENT_BERSERK, 600000);
            }

            void UpdateAI(uint32 diff)
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
                                target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150.0f, true);
                            if (target)
                                DoCast(target, SPELL_SHADOW_CRASH);
                            events.ScheduleEvent(EVENT_SHADOW_CRASH, urand(8000, 12000));
                            break;
                        }
                        case EVENT_SEARING_FLAMES:
                            DoCastAOE(SPELL_SEARING_FLAMES);
                            events.ScheduleEvent(EVENT_SEARING_FLAMES, urand(14000, 17500));
                            break;
                        case EVENT_MARK_OF_THE_FACELESS:
                        {
                            Unit* target = CheckPlayersInRange(RAID_MODE<uint8>(4, 9), 15.0f, 50.0f);
                            if (!target)
                                target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150.0f, true);
                            if (target)
                                DoCast(target, SPELL_MARK_OF_THE_FACELESS);
                            events.ScheduleEvent(EVENT_MARK_OF_THE_FACELESS, urand(35000, 45000));
                            break;
                        }
                        case EVENT_SURGE_OF_DARKNESS:
                            Talk(EMOTE_SURGE_OF_DARKNESS);
                            Talk(SAY_SURGE_OF_DARKNESS);
                            DoCast(me, SPELL_SURGE_OF_DARKNESS);
                            events.ScheduleEvent(EVENT_SURGE_OF_DARKNESS, urand(50000, 70000));
                            break;
                        case EVENT_SARONITE_VAPORS:
                            DoCast(SPELL_SUMMON_SARONITE_VAPORS);
                            events.ScheduleEvent(EVENT_SARONITE_VAPORS, urand(30000, 35000));
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
                }

                DoMeleeAttackIfReady();
            }

            void SpellHitTarget(Unit* who, SpellInfo const* spell)
            {
                if (who && who->GetTypeId() == TYPEID_PLAYER && spell->Id == SPELL_SHADOW_CRASH_HIT)
                    shadowDodger = false;
            }

            void KilledUnit(Unit* who)
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                Talk(SAY_DEATH);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_AURA_OF_DESPAIR);
            }

            void CheckShamanisticRage()
            {
                Map* map = me->GetMap();
                if (map && map->IsDungeon())
                {
                    // If Shaman has Shamanistic Rage and use it during the fight, it will cast Corrupted Rage on him
                    Map::PlayerList const& Players = map->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = Players.begin(); itr != Players.end(); ++itr)
                        if (Player* player = itr->GetSource())
                            if (player->HasSpell(SPELL_SHAMANTIC_RAGE))
                                player->CastSpell(player, SPELL_CORRUPTED_RAGE, false);
                }
            }

            uint32 GetData(uint32 type) const
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

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_VAPORS_DIE:
                        smellSaronite = false;
                        break;
                    case ACTION_ANIMUS_DIE:
                        me->RemoveAurasDueToSpell(SPELL_SARONITE_BARRIER);
                        events.ScheduleEvent(EVENT_SEARING_FLAMES, urand(7000, 12000));
                        animusDead = true;
                        break;
                }
            }

            /*  Player Range Check
                Purpose: If there are playersMin people within rangeMin, rangeMax: return a random players in that range.
                If not, return NULL and allow other target selection
            */
            Unit* CheckPlayersInRange(uint8 playersMin, float rangeMin, float rangeMax)
            {
                Map* map = me->GetMap();
                if (map && map->IsDungeon())
                {
                    std::list<Player*> PlayerList;
                    Map::PlayerList const& Players = map->GetPlayers();
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
                        return NULL;

                    size_t size = PlayerList.size();
                    if (size < playersMin)
                        return NULL;

                    return Trinity::Containers::SelectRandomContainerElement(PlayerList);
                }

                return NULL;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
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

            void Reset()
            {
                DoCast(me, SPELL_VISUAL_SARONITE_ANIMUS);
                events.Reset();
                events.ScheduleEvent(EVENT_PROFOUND_OF_DARKNESS, 3000);
            }

            void JustDied(Unit* /*killer*/)
            {
                if (Creature* Vezax = me->GetCreature(*me, instance->GetData64(BOSS_VEZAX)))
                    Vezax->AI()->DoAction(ACTION_ANIMUS_DIE);
            }

            void UpdateAI(uint32 diff)
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
                            events.ScheduleEvent(EVENT_PROFOUND_OF_DARKNESS, 3000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* instance;
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_saronite_animusAI(creature);
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
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_ID, 49560, true); // Death Grip jump effect
                me->SetReactState(REACT_PASSIVE);
            }

            void Reset()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_RANDOM_MOVE, urand(5000, 7500));
            }

            void UpdateAI(uint32 diff)
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RANDOM_MOVE:
                            me->GetMotionMaster()->MoveRandom(30.0f);
                            events.ScheduleEvent(EVENT_RANDOM_MOVE, urand(5000, 7500));
                            break;
                        default:
                            break;
                    }
                }
            }

            void DamageTaken(Unit* /*who*/, uint32& damage)
            {
                // This can't be on JustDied. In 63322 dummy handler caster needs to be this NPC
                // if caster == target then damage mods will increase the damage taken
                if (damage >= me->GetHealth())
                {
                    damage = 0;
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_DISABLE_MOVE);
                    me->SetStandState(UNIT_STAND_STATE_DEAD);
                    me->SetHealth(me->GetMaxHealth());
                    me->RemoveAllAuras();
                    DoCast(me, SPELL_SARONITE_VAPORS);
                    me->DespawnOrUnsummon(30000);

                    if (Creature* Vezax = me->GetCreature(*me, instance->GetData64(BOSS_VEZAX)))
                        Vezax->AI()->DoAction(ACTION_VAPORS_DIE);
                }
            }

        private:
            InstanceScript* instance;
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_saronite_vaporsAI(creature);
        }
};

class spell_mark_of_the_faceless : public SpellScriptLoader
{
    public:
        spell_mark_of_the_faceless() : SpellScriptLoader("spell_mark_of_the_faceless") { }

        class spell_mark_of_the_faceless_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mark_of_the_faceless_AuraScript);

            void HandleEffectPeriodic(AuraEffect const* aurEff)
            {
                if (Unit* caster = GetCaster())
                    caster->CastCustomSpell(SPELL_MARK_OF_THE_FACELESS_DAMAGE, SPELLVALUE_BASE_POINT1, aurEff->GetAmount(), GetTarget(), true);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_mark_of_the_faceless_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_mark_of_the_faceless_AuraScript();
        }
};

class spell_general_vezax_saronite_vapors : public SpellScriptLoader
{
    public:
        spell_general_vezax_saronite_vapors() : SpellScriptLoader("spell_general_vezax_saronite_vapors") { }

        class spell_general_vezax_saronite_vapors_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_general_vezax_saronite_vapors_AuraScript);

            bool Validate(SpellInfo const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SARONITE_VAPORS_ENERGIZE) || !sSpellMgr->GetSpellInfo(SPELL_SARONITE_VAPORS_DAMAGE))
                    return false;
                return true;
            }

            void HandleEffectApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                {
                    int32 mana = int32(aurEff->GetAmount() * pow(2.0f, GetStackAmount())); // mana restore - bp * 2^stackamount
                    int32 damage = mana * 2;
                    caster->CastCustomSpell(GetTarget(), SPELL_SARONITE_VAPORS_ENERGIZE, &mana, NULL, NULL, true);
                    caster->CastCustomSpell(GetTarget(), SPELL_SARONITE_VAPORS_DAMAGE, &damage, NULL, NULL, true);
                }
            }

            void Register()
            {
                AfterEffectApply += AuraEffectApplyFn(spell_general_vezax_saronite_vapors_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const
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

        bool OnCheck(Player* /*player*/, Unit* target)
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

        bool OnCheck(Player* /*player*/, Unit* target)
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
    new spell_mark_of_the_faceless();
    new spell_general_vezax_saronite_vapors();
    new achievement_shadowdodger();
    new achievement_smell_saronite();
}

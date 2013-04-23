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
    SAY_AGGRO                                   = 0,
    SAY_SLAY                                    = 1,
    SAY_SURGE_OF_DARKNESS                       = 2,
    SAY_DEATH                                   = 3,
    SAY_BERSERK                                 = 4,
    SAY_HARDMODE                                = 5
};

enum VezaxEmotes
{
    EMOTE_ANIMUS                                = 6,
    EMOTE_BARRIER                               = 7,
    EMOTE_SURGE_OF_DARKNESS                     = 8
};

enum VezaxSpells
{
    SPELL_AURA_OF_DESPAIR                        = 62692,
    SPELL_AURA_OF_DESPAIR_EFFECT_DESPAIR         = 64848,
    SPELL_CORRUPTED_RAGE                         = 68415,
    SPELL_MARK_OF_THE_FACELESS                   = 63276,
    SPELL_MARK_OF_THE_FACELESS_DAMAGE            = 63278,
    SPELL_SARONITE_BARRIER                       = 63364,
    SPELL_SEARING_FLAMES                         = 62661,
    SPELL_SHADOW_CRASH                           = 62660,
    SPELL_SHADOW_CRASH_HIT                       = 62659,
    SPELL_SHADOW_CRASH_AURA                      = 63277, // Triggered Cloud
    SPELL_SURGE_OF_DARKNESS                      = 62662,
    SPELL_SUMMON_SARONITE_VAPORS                 = 63081,
    // Saronit Animus - Spawned after 6th Saronit Vapor
    SPELL_PROFOUND_DARKNESS                      = 63420,
    SPELL_SUMMON_SARONITE_ANIMUS                 = 63145,
    SPELL_VISUAL_SARONITE_ANIMUS                 = 63319,
    SPELL_PROFOUND_OF_DARKNESS                   = 63420,

    // Saronit Vapor
    SPELL_SARONITE_VAPORS                        = 63323,
    SPELL_SARONITE_VAPOR_AURA                    = 63322, // Unknown Aura Dummy needs Scripting ?

    // Player Shaman
    SPELL_SHAMANTIC_RAGE                         = 30823,

    // Enrage
    SPELL_BERSERK                                = 47008
};

enum NPCs
{
    NPC_GENERAL_VEZAX                            = 33271,
    NPC_SARONITE_VAPOR                           = 33488,
    NPC_SARONITE_ANIMUS                          = 33524
};

enum AchievData
{
    DATA_SMELL_OF_SARONITE,
    DATA_SHADOWDODGER
};

enum VezaxActions
{
    ACTION_VAPORS_DIE   // Only used since a saronite vapor does not _really_ die
};

/************************************************************************/
/*                          General Vezax                               */
/************************************************************************/

class boss_general_vezax : public CreatureScript
{
    private:
        enum MyEvents
        {
            EVENT_SHADOW_CRASH          = 1,
            EVENT_SEARING_FLAMES,
            EVENT_SURGE_OF_DARKNESS,
            EVENT_MARK_OF_THE_FACELESS,
            EVENT_SUMMON_SARONITE_VAPOR,
            EVENT_BERSERK
        };

    public:
        boss_general_vezax() : CreatureScript("boss_general_vezax") {}

        struct boss_general_vezaxAI : public BossAI
        {
            boss_general_vezaxAI(Creature* creature) : BossAI(creature, BOSS_VEZAX) {}

            void Reset()
            {
                _Reset();
                shadowDodger = true;
                notHardModed = true;
                vaporKilled = false;
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
                DoCast(me, SPELL_AURA_OF_DESPAIR);
                events.ScheduleEvent(EVENT_SHADOW_CRASH, urand(8*IN_MILLISECONDS, 10*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_SEARING_FLAMES, 12*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_MARK_OF_THE_FACELESS, urand(35*IN_MILLISECONDS, 40*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_SUMMON_SARONITE_VAPOR, 30*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SURGE_OF_DARKNESS, 1*MINUTE*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_BERSERK, 10*MINUTE*IN_MILLISECONDS);
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
                            if (Unit* target = CheckPlayersInRange(RAID_MODE(4, 9), 15.0f, 50.0f))
                                DoCast(target, SPELL_SHADOW_CRASH);
                            events.ScheduleEvent(EVENT_SHADOW_CRASH, urand(8*IN_MILLISECONDS, 12*IN_MILLISECONDS));
                            return;
                        case EVENT_SEARING_FLAMES:
                            DoCastAOE(SPELL_SEARING_FLAMES);
                            events.ScheduleEvent(EVENT_SEARING_FLAMES, urand(14*IN_MILLISECONDS, 17.5*IN_MILLISECONDS));
                            return;
                        case EVENT_MARK_OF_THE_FACELESS:
                            if (Unit* target = CheckPlayersInRange(RAID_MODE(4, 9), 15.0f, 50.0f))
                                DoCast(target, SPELL_MARK_OF_THE_FACELESS);
                            events.ScheduleEvent(EVENT_MARK_OF_THE_FACELESS, urand(35*IN_MILLISECONDS, 45*IN_MILLISECONDS));
                            return;
                        case EVENT_SURGE_OF_DARKNESS:
                            Talk(EMOTE_SURGE_OF_DARKNESS);
                            Talk(SAY_SURGE_OF_DARKNESS);
                            DoCast(me, SPELL_SURGE_OF_DARKNESS);
                            events.ScheduleEvent(EVENT_SURGE_OF_DARKNESS, urand(50*IN_MILLISECONDS, 70*IN_MILLISECONDS));
                            return;
                        case EVENT_SUMMON_SARONITE_VAPOR:
                            DoCast(me, SPELL_SUMMON_SARONITE_VAPORS, true);   // Spells summons 33488 in a random place in 40 meters
                            if (summons.size() >= 6) // summons include both vapors and saronite animus, but since the animus was not spawned yet...
                            {
                                events.CancelEvent(EVENT_SUMMON_SARONITE_VAPOR);    // Should always be cancelled after six vapors got spawned
                                if (!vaporKilled && notHardModed)                   // If animus was not spawned yet and no vapor got killed yet...
                                    DoCast(SPELL_SUMMON_SARONITE_ANIMUS);
                                events.CancelEvent(EVENT_SUMMON_SARONITE_VAPOR);
                            }
                            else
                                events.ScheduleEvent(EVENT_SUMMON_SARONITE_VAPOR, urand(30*IN_MILLISECONDS, 35*IN_MILLISECONDS));
                            return;
                        case EVENT_BERSERK:
                            Talk(SAY_BERSERK);
                            DoCast(me, SPELL_BERSERK);
                            return;
                        default:
                            return;
                    }
                }

                DoMeleeAttackIfReady();
            }

            void SpellHitTarget(Unit* who, SpellInfo const* spell)
            {
                if (who && who->GetTypeId() == TYPEID_PLAYER && spell->Id == SPELL_SHADOW_CRASH_HIT)
                    shadowDodger = false;
            }

            void JustSummoned(Creature* summoned)
            {
                summons.Summon(summoned);   // Placed here for the check below
                switch (summoned->GetEntry())
                {
                    case NPC_SARONITE_ANIMUS:
                        events.CancelEvent(EVENT_SEARING_FLAMES);
                        Talk(SAY_HARDMODE);
                        Talk(EMOTE_BARRIER);
                        me->InterruptNonMeleeSpells(false);
                        DoCast(SPELL_SARONITE_BARRIER);
                        me->AddLootMode(LOOT_MODE_HARD_MODE_1);
                        break;
                    default:
                        break;
                }
                DoZoneInCombat(summoned);
            }

            void SummonedCreatureDies(Creature* summon, Unit* /*killer*/)
            {
                switch (summon->GetEntry())
                {
                    case NPC_SARONITE_ANIMUS:
                        notHardModed = false;
                        me->RemoveAurasDueToSpell(SPELL_SARONITE_BARRIER);
                        events.ScheduleEvent(EVENT_SEARING_FLAMES, urand(7*IN_MILLISECONDS, 12*IN_MILLISECONDS));
                        break;
                    default:
                        break;
                }
                summons.Despawn(summon);
            }

            void KilledUnit(Unit* /*who*/)
            {
                if (!urand(0,5))
                    Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*who*/)
            {
                _JustDied();
                Talk(SAY_DEATH);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_AURA_OF_DESPAIR);
            }

            uint32 GetData(uint32 type) const
            {
                switch (type)
                {
                    case DATA_SHADOWDODGER:
                        return shadowDodger ? 1 : 0;
                    // Hardmode-condition: !notHardModed <=> Saronite Animus dead; vaporSummonedCount>=6 <=> Saronite Animus summoned; !vaporKilled <=> one or more vapors got killed
                    case DATA_SMELL_OF_SARONITE:
                        return summons.size()>=6 && !notHardModed && !vaporKilled ? 1 : 0;
                    default:
                        break;
                }
                return 0;
            }

            void DoAction(int32 action)
            {
                switch (action)
                {   
                    case ACTION_VAPORS_DIE:
                        vaporKilled = true;
                        break;
                    default:
                        break;
                }
            }

            /*  Player Range Check
                Purpose: If there are playersMin people within (rangeMin, rangeMax): return a random player in that range.
                If not, return a random target within 150.0f .
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
                        if (Player* player = itr->getSource())
                        {
                            float distance = player->GetDistance(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                            if (rangeMin > distance || distance > rangeMax)
                                continue;

                            PlayerList.push_back(player);
                        }
                    }

                    if (PlayerList.empty() || PlayerList.size()<playersMin)
                        return SelectTarget(SELECT_TARGET_RANDOM, 0, 150.0f, true);

                    return Trinity::Containers::SelectRandomContainerElement(PlayerList);
                }
                return 0;
            }

            private:
                bool animusSummoned;
                bool shadowDodger;
                bool notHardModed; // HardMode
                bool vaporKilled;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetUlduarAI<boss_general_vezaxAI>(creature);
        }
};

class boss_saronite_animus : public CreatureScript
{
    public:
        boss_saronite_animus() : CreatureScript("npc_saronite_animus") {}

        struct boss_saronite_animusAI : public ScriptedAI
        {
            boss_saronite_animusAI(Creature* creature) : ScriptedAI(creature) {}

            void InitializeAI()
            {
                instance = me->GetInstanceScript();
                Reset();
            }

            void Reset()
            {
                DoCast(me, SPELL_VISUAL_SARONITE_ANIMUS);
                profoundTimer = 3*IN_MILLISECONDS;
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (profoundTimer <= diff)
                {
                    DoCastAOE(SPELL_PROFOUND_OF_DARKNESS, true);
                    profoundTimer = RAID_MODE(7*IN_MILLISECONDS, 3*IN_MILLISECONDS);
                }
                else
                    profoundTimer -= diff;

                DoMeleeAttackIfReady();
            }

            private:
                InstanceScript* instance;
                uint32 profoundTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_saronite_animusAI(creature);
        }
};

class npc_saronite_vapors : public CreatureScript
{
    private:
        enum DeathGrip
        {
            SPELL_DEATH_GRIP = 49560
        };

        enum Emote
        {
            EMOTE_VAPORS    = 0
        };

    public:
        npc_saronite_vapors() : CreatureScript("npc_saronite_vapors") {}

        struct npc_saronite_vaporsAI : public ScriptedAI
        {
            npc_saronite_vaporsAI(Creature* creature) : ScriptedAI(creature) {}

            void InitializeAI()
            {
                Talk(EMOTE_VAPORS);
                instance = me->GetInstanceScript();
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_DEATH_GRIP, true); 
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true); 
                me->SetReactState(REACT_PASSIVE);
                Reset();
            }

            void Reset()
            {
                randomMoveTimer = urand(3*IN_MILLISECONDS, 4.5*IN_MILLISECONDS);
            }

            void UpdateAI(uint32 diff)
            {
                if (instance->GetBossState(BOSS_VEZAX) != IN_PROGRESS)
                    me->DisappearAndDie();
                    
                if (randomMoveTimer <= diff)
                {
                    me->GetMotionMaster()->MoveRandom(30.0f);
                    randomMoveTimer = urand(4*IN_MILLISECONDS, 5*IN_MILLISECONDS);
                }
                else
                    randomMoveTimer -= diff;
            }

            void DamageTaken(Unit* /*who*/, uint32& damage)
            {
                // This can't be on JustDied. In 63322 dummy handler caster needs to be this NPC
                // if caster == target then damage mods will increase the damage taken
                if (damage >= me->GetHealth())
                {
                    damage = 0;
                    me->SetReactState(REACT_PASSIVE);
                    me->GetMotionMaster()->Clear(false);
                    me->GetMotionMaster()->MoveIdle();
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_DISABLE_MOVE);
                    me->SetStandState(UNIT_STAND_STATE_DEAD);
                    me->SetHealth(me->GetMaxHealth());
                    me->RemoveAllAuras();
                    DoCast(me, SPELL_SARONITE_VAPORS);
                    me->DespawnOrUnsummon(30*IN_MILLISECONDS);

                    if (Creature* Vezax = me->GetCreature(*me, instance->GetData64(BOSS_VEZAX)))
                        Vezax->AI()->DoAction(ACTION_VAPORS_DIE);
                }
            }

            private:
                InstanceScript* instance;
                uint32 randomMoveTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_saronite_vaporsAI(creature);
        }
};

/************************************************************************/
/*                              Spells                                  */
/************************************************************************/

class spell_aura_of_despair_aura : public SpellScriptLoader // Spell 62692
{
public:
    spell_aura_of_despair_aura() : SpellScriptLoader("spell_aura_of_despair_aura") { }

    class spell_aura_of_despair_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_aura_of_despair_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/)
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_AURA_OF_DESPAIR_EFFECT_DESPAIR))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_CORRUPTED_RAGE))
                return false;
            return true;
        }

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* target = GetTarget()->ToPlayer();

            if (target->getClass() == CLASS_SHAMAN && target->HasSpell(SPELL_SHAMANTIC_RAGE))
                target->CastSpell(target, SPELL_CORRUPTED_RAGE, true);

            target->CastSpell(target, SPELL_AURA_OF_DESPAIR_EFFECT_DESPAIR, true);
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* target = GetTarget()->ToPlayer();

            target->RemoveAurasDueToSpell(SPELL_CORRUPTED_RAGE);
            target->RemoveAurasDueToSpell(SPELL_AURA_OF_DESPAIR_EFFECT_DESPAIR);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(spell_aura_of_despair_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PREVENT_REGENERATE_POWER, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_aura_of_despair_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PREVENT_REGENERATE_POWER, AURA_EFFECT_HANDLE_REAL);
        }

    };

    AuraScript* GetAuraScript() const
    {
        return new spell_aura_of_despair_AuraScript();
    }
};

class spell_mark_of_the_faceless : public SpellScriptLoader
{
    public:
        spell_mark_of_the_faceless() : SpellScriptLoader("spell_mark_of_the_faceless") {}

        class spell_mark_of_the_faceless_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mark_of_the_faceless_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MARK_OF_THE_FACELESS_DAMAGE))
                    return false;
                return true;
            }

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

class spell_mark_of_the_faceless_drain : public SpellScriptLoader // 63278
{
public:
    spell_mark_of_the_faceless_drain() : SpellScriptLoader("spell_mark_of_the_faceless_drain") {}

    class spell_mark_of_the_faceless_drain_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_mark_of_the_faceless_drain_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            targets.remove(GetExplTargetUnit()); // The target of this spell should _not_ be in this list
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mark_of_the_faceless_drain_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_mark_of_the_faceless_drain_SpellScript();
    }
};

enum SaroniteVaporsSpells
{
    SPELL_SARONITE_VAPORS_MANA = 63337,
    SPELL_SARONITE_VAPORS_DAMAGE = 63338
};

class spell_saronite_vapors : public SpellScriptLoader // 63278
{
public:
    spell_saronite_vapors() : SpellScriptLoader("spell_saronite_vapors") {}

    class spell_saronite_vapors_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_saronite_vapors_AuraScript);

        bool Validate(SpellInfo const* /*spell*/)
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_SARONITE_VAPORS_MANA) || !sSpellMgr->GetSpellInfo(SPELL_SARONITE_VAPORS_DAMAGE))
                return false;
            return true;
        }

        void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* target = GetTarget();
            Unit* caster = GetCaster();

            if (caster && target)
            {
                int32 damage = 50 << GetStackAmount();
                target->CastCustomSpell(target, SPELL_SARONITE_VAPORS_DAMAGE, &damage, 0, 0, true, 0, 0, caster->GetGUID());
                damage = damage >> 1;
                target->CastCustomSpell(target, SPELL_SARONITE_VAPORS_MANA, &damage, 0, 0, true);
            }
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(spell_saronite_vapors_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_saronite_vapors_AuraScript();
    }
};

/************************************************************************/
/*                          Achievements                                */
/************************************************************************/

class achievement_shadowdodger : public AchievementCriteriaScript
{
    public:
        achievement_shadowdodger(const char* name) : AchievementCriteriaScript(name) {}

        bool OnCheck(Player* /*player*/, Unit* target)
        {
            if (target)
                if (Creature* Vezax = target->ToCreature())
                    if (Vezax->AI()->GetData(DATA_SHADOWDODGER))
                        return true;

            return false;
        }
};

class achievement_i_love_the_smell_of_saronite_in_the_morning : public AchievementCriteriaScript
{
    public:
        achievement_i_love_the_smell_of_saronite_in_the_morning(const char* name) : AchievementCriteriaScript(name) {}

        bool OnCheck(Player* /*player*/, Unit* target)
        {
            if (target)
                if (Creature* Vezax = target->ToCreature())
                    if (Vezax->AI()->GetData(DATA_SMELL_OF_SARONITE))
                        return true;

            return false;
        }
};

void AddSC_boss_general_vezax()
{
    new boss_general_vezax();
    new boss_saronite_animus();
    new npc_saronite_vapors();

    new spell_aura_of_despair_aura();
    new spell_mark_of_the_faceless_drain();
    new spell_mark_of_the_faceless();
    new spell_saronite_vapors();

    new achievement_shadowdodger("achievement_shadowdodger");       // 10m 10173 (2996)
    new achievement_shadowdodger("achievement_shadowdodger_25");    // 25m 10306 (2997)
    new achievement_i_love_the_smell_of_saronite_in_the_morning("achievement_i_love_the_smell_of_saronite_in_the_morning");     // 10m 10451 (3181)
    new achievement_i_love_the_smell_of_saronite_in_the_morning("achievement_i_love_the_smell_of_saronite_in_the_morning_25");  // 25m 10462 (3188)
}

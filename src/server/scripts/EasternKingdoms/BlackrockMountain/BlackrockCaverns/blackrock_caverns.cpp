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
#include "blackrock_caverns.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

/*#####
# npc_fire_cyclone
#####*/

enum FireCyclone
{
    SPELL_FIRE_CYCLONE_AURA     = 74851,
    EVENT_FIRE_CYCLONE_AURA     = 1
};

class npc_fire_cyclone : public CreatureScript
{
    public: npc_fire_cyclone() : CreatureScript("npc_fire_cyclone") { }

        struct npc_fire_cycloneAI : public ScriptedAI
        {
            npc_fire_cycloneAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

            void Reset() override
            {
                _events.Reset();
                _events.ScheduleEvent(EVENT_FIRE_CYCLONE_AURA, 100);
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FIRE_CYCLONE_AURA:
                            DoCast(me, SPELL_FIRE_CYCLONE_AURA, true);
                            _events.ScheduleEvent(EVENT_FIRE_CYCLONE_AURA, 4000);
                            break;
                        default:
                            break;
                    }
                }
            }

            private:
                EventMap        _events;
                InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBlackrockCavernsAI<npc_fire_cycloneAI>(creature);
        }
};

/*#####
# npc_twilight_flame_caller
#####*/

enum TwilightFlameCaller
{
    SPELL_FIRE_CHANNELING_1     = 74911,
    SPELL_FIRE_CHANNELING_2     = 74912,
    SPELL_BLAST_WAVE            = 76473,
    SPELL_CALL_FLAMES           = 76325,
    NPC_FIRE_CYCLONE            = 40164,
    EVENT_CHANNEL               = 2,
    EVENT_BLAST_WAVE            = 3,
    EVENT_CALL_FLAMES           = 4
};

Position const SummonPos[6] =
{
    { 162.5990f, 1085.321f, 201.1190f, 0.0f },
    { 170.5469f, 1063.403f, 201.1409f, 0.0f },
    { 191.2326f, 1100.160f, 201.1071f, 0.0f },
    { 228.0816f, 1106.000f, 201.1292f, 0.0f },
    { 252.8351f, 1095.127f, 201.1436f, 0.0f },
    { 253.6476f, 1070.226f, 201.1344f, 0.0f }
};

class npc_twilight_flame_caller : public CreatureScript
{
public: npc_twilight_flame_caller() : CreatureScript("npc_twilight_flame_caller") { }

        struct npc_twilight_flame_callerAI : public ScriptedAI
        {
            npc_twilight_flame_callerAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _summons(me)
            {
                Initialize();
            }

            void Initialize()
            {
                _combatPhase = false;
            }

            void Reset() override
            {
                Initialize();
                _flamecaller1GUID.Clear();
                _flamecaller2GUID.Clear();

                if (me->GetPositionX() > 172 && me->GetPositionX() < 173 && me->GetPositionY() > 1086 && me->GetPositionY() < 1087)
                {
                    _flamecaller1GUID = me->GetGUID();
                    me->SummonCreature(NPC_FIRE_CYCLONE, SummonPos[0], TEMPSUMMON_CORPSE_DESPAWN, 0);
                    me->SummonCreature(NPC_FIRE_CYCLONE, SummonPos[1], TEMPSUMMON_CORPSE_DESPAWN, 0);
                    me->SummonCreature(NPC_FIRE_CYCLONE, SummonPos[2], TEMPSUMMON_CORPSE_DESPAWN, 0);
                }
                if (me->GetPositionX() > 247 && me->GetPositionX() < 248 && me->GetPositionY() > 1081 && me->GetPositionY() < 1082)
                {
                    _flamecaller2GUID = me->GetGUID();
                    me->SummonCreature(NPC_FIRE_CYCLONE, SummonPos[3], TEMPSUMMON_CORPSE_DESPAWN, 0);
                    me->SummonCreature(NPC_FIRE_CYCLONE, SummonPos[4], TEMPSUMMON_CORPSE_DESPAWN, 0);
                    me->SummonCreature(NPC_FIRE_CYCLONE, SummonPos[5], TEMPSUMMON_CORPSE_DESPAWN, 0);
                }

                _events.ScheduleEvent(EVENT_CHANNEL, 100);
            }

            void JustSummoned(Creature* summoned) override
            {
                _summons.Summon(summoned);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _summons.DespawnAll();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _events.Reset();
                _combatPhase = true;
                _events.ScheduleEvent(EVENT_BLAST_WAVE, urand(8000, 10000));
                _events.ScheduleEvent(EVENT_CALL_FLAMES,  urand(10000, 14000));
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                if (!_combatPhase)
                {
                    while (uint32 eventId = _events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_CHANNEL:
                                if (me->GetGUID() == _flamecaller1GUID)
                                    DoCast(me, SPELL_FIRE_CHANNELING_1);
                                if (me->GetGUID() == _flamecaller2GUID)
                                    DoCast(me, SPELL_FIRE_CHANNELING_2);
                                _events.ScheduleEvent(EVENT_CHANNEL, 12000);
                                break;
                            default:
                                break;
                        }
                    }
                    return;
                }

                if (!UpdateVictim())
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BLAST_WAVE:
                            DoCast(me, SPELL_BLAST_WAVE);
                            _events.ScheduleEvent(EVENT_BLAST_WAVE, 16000, 20000);
                            break;
                        case EVENT_CALL_FLAMES:
                            DoCast(me, SPELL_CALL_FLAMES);
                            _events.ScheduleEvent(EVENT_CALL_FLAMES, 12000, 15000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap        _events;
            InstanceScript* _instance;
            ObjectGuid      _flamecaller1GUID;
            ObjectGuid      _flamecaller2GUID;
            SummonList      _summons;
            bool            _combatPhase;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBlackrockCavernsAI<npc_twilight_flame_callerAI>(creature);
        }
};

/*#####
# npc_twilight_torturer
#####*/

enum TwilightTorturer
{
    SPELL_INFLICT_PAIN          = 75590,
    SPELL_RED_HOT_POKER         = 76478,
    SPELL_SHACKLES              = 76484,
    SPELL_WILD_BEATDOWN         = 76487,
    EVENT_INFLICT_PAIN_TT       = 5,
    EVENT_RED_HOT_POKER         = 6,
    EVENT_SHACKLES              = 7,
    EVENT_WILD_BEATDOWN         = 8
};

class npc_twilight_torturer : public CreatureScript
{
    public: npc_twilight_torturer() : CreatureScript("npc_twilight_torturer") { }

        struct npc_twilight_torturerAI : public ScriptedAI
        {
            npc_twilight_torturerAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript())
            {
                Initialize();
            }

            void Initialize()
            {
                _combatPhase = false;
            }

            void Reset() override
            {
                Initialize();
                if (!me->GetWaypointPath())
                    _events.ScheduleEvent(EVENT_INFLICT_PAIN_TT, urand(6000, 18000));
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _events.Reset();
                _combatPhase = true;
                _events.ScheduleEvent(EVENT_RED_HOT_POKER, 9000);
                _events.ScheduleEvent(EVENT_SHACKLES, 13000);
                _events.ScheduleEvent(EVENT_WILD_BEATDOWN, 17000);
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                if (!_combatPhase)
               {
                    while (uint32 eventId = _events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_INFLICT_PAIN_TT:
                                DoCast(me, SPELL_INFLICT_PAIN);
                                _events.ScheduleEvent(EVENT_INFLICT_PAIN_TT, urand(25000, 32000));
                                break;
                            default:
                                break;
                        }
                    }
                    return;
                }

                if (!UpdateVictim())
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RED_HOT_POKER:
                            DoCast(me, SPELL_RED_HOT_POKER);
                            _events.ScheduleEvent(EVENT_RED_HOT_POKER, 16000, 20000);
                            break;
                        case EVENT_SHACKLES:
                            DoCast(me, SPELL_SHACKLES);
                            _events.ScheduleEvent(EVENT_SHACKLES, 12000, 15000);
                            break;
                        case EVENT_WILD_BEATDOWN:
                            DoCast(me, SPELL_WILD_BEATDOWN);
                            _events.ScheduleEvent(EVENT_WILD_BEATDOWN, 12000, 15000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap        _events;
            InstanceScript* _instance;
            bool            _combatPhase;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBlackrockCavernsAI<npc_twilight_torturerAI>(creature);
        }
};

/*#####
# npc_twilight_sadist
#####*/

enum TwilightSadist
{
    SPELL_INFLICT_PAIN_1        = 76497,
    SPELL_HEAT_SEEKER_BLADE     = 76502,
    SPELL_SHORT_THROW           = 76572,
    SPELL_SINISTER_STRIKE       = 76500,
    EVENT_INFLICT_PAIN_TS       = 9,
    EVENT_HEAT_SEEKER_BLADE     = 10,
    EVENT_SHORT_THROW           = 11,
    EVENT_SINISTER_STRIKE       = 12
};

class npc_twilight_sadist : public CreatureScript
{
    public: npc_twilight_sadist() : CreatureScript("npc_twilight_sadist") { }

        struct npc_twilight_sadistAI : public ScriptedAI
        {
            npc_twilight_sadistAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

            void Reset() override
            {
                _combatPhase = false;
                if (!me->GetWaypointPath())
                    _events.ScheduleEvent(EVENT_INFLICT_PAIN_TS, urand(6000, 18000));
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _events.Reset();
                _combatPhase = true;
                _events.ScheduleEvent(EVENT_INFLICT_PAIN_TS, 9000);
                _events.ScheduleEvent(EVENT_HEAT_SEEKER_BLADE,  13000);
                _events.ScheduleEvent(EVENT_SHORT_THROW, 17000);
                _events.ScheduleEvent(EVENT_SINISTER_STRIKE, 17000);
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                if (!_combatPhase)
               {
                    while (uint32 eventId = _events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_INFLICT_PAIN_TS:
                                DoCast(me, SPELL_INFLICT_PAIN);
                                _events.ScheduleEvent(EVENT_INFLICT_PAIN_TS, urand(25000, 32000));
                                break;
                            default:
                                break;
                        }
                    }
                    return;
                }

                if (!UpdateVictim())
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RED_HOT_POKER:
                            DoCast(me, SPELL_RED_HOT_POKER);
                            _events.ScheduleEvent(EVENT_RED_HOT_POKER, 16000, 20000);
                            break;
                        case EVENT_SHACKLES:
                            DoCast(me, SPELL_SHACKLES);
                            _events.ScheduleEvent(EVENT_SHACKLES, 12000, 15000);
                            break;
                        case EVENT_WILD_BEATDOWN:
                            DoCast(me, SPELL_WILD_BEATDOWN);
                            _events.ScheduleEvent(EVENT_WILD_BEATDOWN, 12000, 15000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap        _events;
            InstanceScript* _instance;
            bool _combatPhase = false;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBlackrockCavernsAI<npc_twilight_sadistAI>(creature);
        }
};

/*#####
# npc_mad_prisoner
#####*/

enum MadPrisoner
{
    SPELL_HEAD_CRACK            = 77568,
    SPELL_INFECTED_WOUND        = 76512,
    SPELL_ENRAGE                = 8599,
    EVENT_HEAD_CRACK            = 13,
    EVENT_INFECTED_WOUND        = 14,
    EVENT_ENRAGE                = 15
};

class npc_mad_prisoner : public CreatureScript
{
    public: npc_mad_prisoner() : CreatureScript("npc_mad_prisoner") { }

        struct npc_mad_prisonerAI : public ScriptedAI
        {
            npc_mad_prisonerAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

            void Reset() override { }

            void EnterCombat(Unit* /*who*/) override
            {
                _events.Reset();
                _events.ScheduleEvent(EVENT_HEAD_CRACK, 9000);
                _events.ScheduleEvent(EVENT_INFECTED_WOUND,  13000);
                _events.ScheduleEvent(EVENT_ENRAGE, 17000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_HEAD_CRACK:
                            DoCast(me, SPELL_HEAD_CRACK);
                            _events.ScheduleEvent(EVENT_HEAD_CRACK, 16000, 20000);
                            break;
                        case EVENT_INFECTED_WOUND:
                            DoCast(me, SPELL_INFECTED_WOUND);
                            _events.ScheduleEvent(EVENT_INFECTED_WOUND, 12000, 15000);
                            break;
                        case EVENT_ENRAGE:
                            DoCast(me, SPELL_ENRAGE);
                            _events.ScheduleEvent(EVENT_ENRAGE, 12000, 15000);
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }

        private:
            EventMap        _events;
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBlackrockCavernsAI<npc_mad_prisonerAI>(creature);
        }
};

/*#####
# npc_crazed_mage
#####*/

enum CrazedMage
{
    EVENT_HEAD_CRACK2           = 16,
    EVENT_INFECTED_WOUND2       = 17,
    EVENT_ENRAGE2               = 18
};

class npc_crazed_mage : public CreatureScript
{
    public: npc_crazed_mage() : CreatureScript("npc_crazed_mage") { }

        struct npc_crazed_mageAI : public ScriptedAI
        {
            npc_crazed_mageAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

            void Reset() override { }

            void EnterCombat(Unit* /*who*/) override
            {
                _events.Reset();
                _events.ScheduleEvent(EVENT_HEAD_CRACK2, 9000);
                _events.ScheduleEvent(EVENT_INFECTED_WOUND2,  13000);
                _events.ScheduleEvent(EVENT_ENRAGE2, 17000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_HEAD_CRACK2:
                            DoCast(me, SPELL_HEAD_CRACK);
                            _events.ScheduleEvent(EVENT_HEAD_CRACK2, 16000, 20000);
                            break;
                        case EVENT_INFECTED_WOUND2:
                            DoCast(me, SPELL_INFECTED_WOUND);
                            _events.ScheduleEvent(EVENT_INFECTED_WOUND2, 12000, 15000);
                            break;
                        case EVENT_ENRAGE2:
                            DoCast(me, SPELL_ENRAGE);
                            _events.ScheduleEvent(EVENT_ENRAGE2, 12000, 15000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBlackrockCavernsAI<npc_crazed_mageAI>(creature);
        }
};

/*#####
# npc_raz_the_crazed
#####*/

enum RazTheCrazed
{
    SAY_SMASH                   = 0,
    SPELL_AGGRO_NEARBY_TARGETS  = 80196,
    SPELL_SHADOW_PRISON         = 79725,
    SPELL_LEAP_FROM_CAGE        = 79720,
    SPELL_FURIOUS_SWIPE         = 80206,
    SPELL_LEAP_FROM_BRIDGE      = 80273,
    TYPE_RAZ                    = 1,
    DATA_ROMOGG_DEAD            = 1,
    EVENT_AGGO_NEARBY_TARGETS   = 19,
    EVENT_START_FIRST_PATH      = 20,
    EVENT_FURIOUS_SWIPE         = 21
};

class npc_raz_the_crazed : public CreatureScript
{
    public: npc_raz_the_crazed() : CreatureScript("npc_raz_the_crazed") { }

        struct npc_raz_the_crazedAI : public ScriptedAI
        {
            npc_raz_the_crazedAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

            void Reset() override { }

            void EnterCombat(Unit* /*who*/) override
            {
                _events.Reset();
                _events.ScheduleEvent(SPELL_FURIOUS_SWIPE, 500);
            }

            void IsSummonedBy(Unit* summoner) override
            {
                if (summoner->GetEntry() == NPC_ROMOGG_BONECRUSHER)
                {
                    me->SetDisableGravity(true);
                    DoCast(me, SPELL_SHADOW_PRISON);
                    _events.ScheduleEvent(EVENT_AGGO_NEARBY_TARGETS, 1000);
                }
            }

            void SetData(uint32 id, uint32 data) override
            {
                if (id == TYPE_RAZ && data == DATA_ROMOGG_DEAD)
                {
                    me->RemoveAura(SPELL_SHADOW_PRISON);
                    me->SetDisableGravity(false);
                    DoCast(me, SPELL_LEAP_FROM_CAGE);
                    _events.ScheduleEvent(EVENT_START_FIRST_PATH, 3000);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_AGGO_NEARBY_TARGETS:
                            DoCast(me, SPELL_AGGRO_NEARBY_TARGETS);
                            _events.ScheduleEvent(EVENT_AGGO_NEARBY_TARGETS, 1500);
                            break;
                        case EVENT_START_FIRST_PATH:
                            Talk(SAY_SMASH);
                            break;
                        case EVENT_FURIOUS_SWIPE:
                            DoCastVictim(SPELL_FURIOUS_SWIPE, true);
                            _events.ScheduleEvent(SPELL_FURIOUS_SWIPE, 500);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBlackrockCavernsAI<npc_raz_the_crazedAI>(creature);
        }
};

/*#####
# npc_chains_of_woe
#####*/

enum ChainsOfWoe
{
    SPELL_CHAINS_OF_WOE_1       = 75437,
    SPELL_CHAINS_OF_WOE_2       = 75441,
    SPELL_CHAINS_OF_WOE_3       = 75464,
    SPELL_CHAINS_OF_WOE_4       = 82189,
    SPELL_CHAINS_OF_WOE_5       = 82192,
    MODEL_INVISIBLE             = 38330
};

class npc_chains_of_woe : public CreatureScript
{
    public: npc_chains_of_woe() : CreatureScript("npc_chains_of_woe") { }

        struct npc_chains_of_woeAI : public ScriptedAI
        {
            npc_chains_of_woeAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                me->SetDisplayId(MODEL_INVISIBLE);
                DoCast(me, SPELL_CHAINS_OF_WOE_1, true);
                DoCast(me, SPELL_CHAINS_OF_WOE_2, true);
            }

        private:
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBlackrockCavernsAI<npc_chains_of_woeAI>(creature);
        }
};

/*#####
# spell_chains_of_woe_1
#####*/

class spell_chains_of_woe_1 : public SpellScriptLoader
{
    public: spell_chains_of_woe_1() : SpellScriptLoader("spell_chains_of_woe_1") { }

        class spell_chains_of_woe_1_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_chains_of_woe_1_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_CHAINS_OF_WOE_1 });
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                if (GetHitUnit()->GetTypeId() == TYPEID_PLAYER)
                    GetHitUnit()->CastSpell(GetCaster(), SPELL_CHAINS_OF_WOE_3, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_chains_of_woe_1_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_chains_of_woe_1_SpellScript();
        }
};

/*#####
# spell_chains_of_woe_4
#####*/

class spell_chains_of_woe_4 : public SpellScriptLoader
{
    public: spell_chains_of_woe_4() : SpellScriptLoader("spell_chains_of_woe_4") { }

        class spell_chains_of_woe_4_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_chains_of_woe_4_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_CHAINS_OF_WOE_4 });
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                if (GetHitUnit()->GetTypeId() == TYPEID_PLAYER)
                    GetHitUnit()->CastSpell(GetHitUnit(), SPELL_CHAINS_OF_WOE_5, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_chains_of_woe_4_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_chains_of_woe_4_SpellScript();
        }
};

/*#####
# spell_nether_dragon_essence_1
#####*/

enum NetherDragonEssence
{
    SPELL_NETHER_DRAGON_ESSENCE_1 = 75649,
    SPELL_NETHER_DRAGON_ESSENCE_2 = 75650,
    SPELL_NETHER_DRAGON_ESSENCE_3 = 75653,
    SPELL_NETHER_DRAGON_ESSENCE_4 = 75654
};

class spell_nether_dragon_essence_1 : public SpellScriptLoader
{
    public: spell_nether_dragon_essence_1() : SpellScriptLoader("spell_nether_dragon_essence_1") { }

        class spell_nether_dragon_essence_1_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_nether_dragon_essence_1_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_NETHER_DRAGON_ESSENCE_2,
                    SPELL_NETHER_DRAGON_ESSENCE_3,
                    SPELL_NETHER_DRAGON_ESSENCE_4
                });
            }

            void HandleTriggerSpell(AuraEffect const* /*aurEff*/)
            {
                if (Unit* caster = GetCaster())
                    caster->CastSpell(caster, RAND(SPELL_NETHER_DRAGON_ESSENCE_2, SPELL_NETHER_DRAGON_ESSENCE_3, SPELL_NETHER_DRAGON_ESSENCE_4));
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_nether_dragon_essence_1_AuraScript::HandleTriggerSpell, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_nether_dragon_essence_1_AuraScript();
        }
};

/*#####
# spell_nether_dragon_essence_2
#####*/

class spell_nether_dragon_essence_2 : public SpellScriptLoader
{
    public:
        spell_nether_dragon_essence_2() : SpellScriptLoader("spell_nether_dragon_essence_2") { }

        class spell_nether_dragon_essence_2_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_nether_dragon_essence_2_SpellScript);

            void ModDestHeight(SpellDestination& dest)
            {
                Position offset = { frand(-35.0f, 35.0f), frand(-25.0f, 25.0f), 0.0f, 0.0f };

                switch (GetSpellInfo()->Id)
                {
                    case SPELL_NETHER_DRAGON_ESSENCE_2:
                        offset.m_positionZ = 25.0f;
                        break;
                    case SPELL_NETHER_DRAGON_ESSENCE_3:
                        offset.m_positionZ = 17.0f;
                        break;
                    case SPELL_NETHER_DRAGON_ESSENCE_4:
                        offset.m_positionZ = 33.0f;
                        break;
                }

                dest.RelocateOffset(offset);
            }

            void Register() override
            {
                OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_nether_dragon_essence_2_SpellScript::ModDestHeight, EFFECT_0, TARGET_DEST_CASTER_RANDOM);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_nether_dragon_essence_2_SpellScript();
        }
};

void AddSC_blackrock_caverns()
{
    // Creature Scripts
    new npc_fire_cyclone();
    new npc_twilight_flame_caller();
    new npc_twilight_torturer();
    new npc_twilight_sadist();
    new npc_mad_prisoner();
    new npc_crazed_mage();
    new npc_raz_the_crazed();
    new npc_chains_of_woe();
    // Spell Scripts
    new spell_chains_of_woe_1();
    new spell_chains_of_woe_4();
    new spell_nether_dragon_essence_1();
    new spell_nether_dragon_essence_2();
}

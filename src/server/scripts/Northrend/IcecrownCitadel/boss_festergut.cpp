/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
#include "SpellAuras.h"
#include "icecrown_citadel.h"

enum ScriptTexts
{
    SAY_STINKY_DEAD             = 0,
    SAY_AGGRO                   = 1,
    EMOTE_GAS_SPORE             = 2,
    EMOTE_WARN_GAS_SPORE        = 3,
    SAY_PUNGENT_BLIGHT          = 4,
    EMOTE_WARN_PUNGENT_BLIGHT   = 5,
    EMOTE_PUNGENT_BLIGHT        = 6,
    SAY_KILL                    = 7,
    SAY_BERSERK                 = 8,
    SAY_DEATH                   = 9,
};

enum Spells
{
    // Festergut
    SPELL_INHALE_BLIGHT         = 69165,
    SPELL_PUNGENT_BLIGHT        = 69195,
    SPELL_GASTRIC_BLOAT         = 72219, // 72214 is the proper way (with proc) but atm procs can't have cooldown for creatures
    SPELL_GASTRIC_EXPLOSION     = 72227,
    SPELL_GAS_SPORE             = 69278,
    SPELL_VILE_GAS              = 69240,
    SPELL_INOCULATED            = 69291,

    // Stinky
    SPELL_MORTAL_WOUND          = 71127,
    SPELL_DECIMATE              = 71123,
    SPELL_PLAGUE_STENCH         = 71805,
};

// Used for HasAura checks
#define PUNGENT_BLIGHT_HELPER RAID_MODE<uint32>(69195,71219,73031,73032)
#define INOCULATED_HELPER     RAID_MODE<uint32>(69291,72101,72102,72103)

static const uint32 gaseousBlight[3]        = {69157, 69162, 69164};
static const uint32 gaseousBlightVisual[3]  = {69126, 69152, 69154};

enum Events
{
    EVENT_BERSERK       = 1,
    EVENT_INHALE_BLIGHT = 2,
    EVENT_VILE_GAS      = 3,
    EVENT_GAS_SPORE     = 4,
    EVENT_GASTRIC_BLOAT = 5,

    EVENT_DECIMATE      = 6,
    EVENT_MORTAL_WOUND  = 7,
};

#define DATA_INOCULATED_STACK 69291

class boss_festergut : public CreatureScript
{
    public:
        boss_festergut() : CreatureScript("boss_festergut") { }

        struct boss_festergutAI : public BossAI
        {
            boss_festergutAI(Creature* creature) : BossAI(creature, DATA_FESTERGUT)
            {
                maxInoculatedStack = 0;
                inhaleCounter = 0;
                gasDummyGUID = 0;
            }

            void Reset()
            {
                _Reset();
                events.ScheduleEvent(EVENT_BERSERK, 300000);
                events.ScheduleEvent(EVENT_INHALE_BLIGHT, urand(25000, 30000));
                events.ScheduleEvent(EVENT_GAS_SPORE, urand(20000, 25000));
                events.ScheduleEvent(EVENT_GASTRIC_BLOAT, urand(12500, 15000));
                maxInoculatedStack = 0;
                inhaleCounter = 0;
                me->RemoveAurasDueToSpell(SPELL_BERSERK2);
                if (Creature* gasDummy = me->FindNearestCreature(NPC_GAS_DUMMY, 100.0f, true))
                {
                    gasDummyGUID = gasDummy->GetGUID();
                    for (uint8 i = 0; i < 3; ++i)
                    {
                        me->RemoveAurasDueToSpell(gaseousBlight[i]);
                        gasDummy->RemoveAurasDueToSpell(gaseousBlightVisual[i]);
                    }
                }
            }

            void EnterCombat(Unit* who)
            {
                if (!instance->CheckRequiredBosses(DATA_FESTERGUT, who->ToPlayer()))
                {
                    EnterEvadeMode();
                    instance->DoCastSpellOnPlayers(LIGHT_S_HAMMER_TELEPORT);
                    return;
                }

                me->setActive(true);
                Talk(SAY_AGGRO);
                if (Creature* gasDummy = me->FindNearestCreature(NPC_GAS_DUMMY, 100.0f, true))
                    gasDummyGUID = gasDummy->GetGUID();
                if (Creature* professor = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_PROFESSOR_PUTRICIDE)))
                    professor->AI()->DoAction(ACTION_FESTERGUT_COMBAT);
                DoZoneInCombat();
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                Talk(SAY_DEATH);
                if (Creature* professor = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_PROFESSOR_PUTRICIDE)))
                    professor->AI()->DoAction(ACTION_FESTERGUT_DEATH);

                _RemoveBlight();
            }

            void JustReachedHome()
            {
                _JustReachedHome();
                instance->SetBossState(DATA_FESTERGUT, FAIL);
            }

            void EnterEvadeMode()
            {
                ScriptedAI::EnterEvadeMode();
                if (Creature* professor = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_PROFESSOR_PUTRICIDE)))
                    professor->AI()->EnterEvadeMode();
            }

            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void MoveInLineOfSight(Unit* /*who*/)
            {
                // don't enter combat
            }

            void SpellHitTarget(Unit* target, SpellEntry const* spell)
            {
                if (spell->Id == PUNGENT_BLIGHT_HELPER)
                    target->RemoveAurasDueToSpell(INOCULATED_HELPER);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim() || !CheckInRoom())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_INHALE_BLIGHT:
                        {
                            _RemoveBlight();
                            if (inhaleCounter == 3)
                            {
                                Talk(EMOTE_WARN_PUNGENT_BLIGHT);
                                Talk(SAY_PUNGENT_BLIGHT);
                                DoCast(me, SPELL_PUNGENT_BLIGHT);
                                inhaleCounter = 0;
                                if (Creature* professor = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_PROFESSOR_PUTRICIDE)))
                                    professor->AI()->DoAction(ACTION_FESTERGUT_GAS);
                                events.RescheduleEvent(EVENT_GAS_SPORE, urand(20000, 25000));
                            }
                            else
                            {
                                DoCast(me, SPELL_INHALE_BLIGHT);
                                // just cast and dont bother with target, conditions will handle it
                                ++inhaleCounter;
                                if (inhaleCounter < 3)
                                    me->CastSpell(me, gaseousBlight[inhaleCounter], true, NULL, NULL, me->GetGUID());
                            }
                            events.ScheduleEvent(EVENT_INHALE_BLIGHT, urand(33500, 35000));
                            break;
                        }
                        case EVENT_VILE_GAS:
                        {
                            std::list<Unit*> targets;
                            uint32 minTargets = RAID_MODE<uint32>(3, 8, 3, 8);
                            SelectTargetList(targets, minTargets, SELECT_TARGET_RANDOM, -5.0f, true);
                            float minDist = 0.0f;
                            if (targets.size() >= minTargets)
                                minDist = -5.0f;

                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, minDist, true))
                                DoCast(target, SPELL_VILE_GAS);
                            events.ScheduleEvent(EVENT_VILE_GAS, urand(28000, 35000));
                            break;
                        }
                        case EVENT_GAS_SPORE:
                            Talk(EMOTE_WARN_GAS_SPORE);
                            Talk(EMOTE_GAS_SPORE);
                            me->CastCustomSpell(SPELL_GAS_SPORE, SPELLVALUE_MAX_TARGETS, RAID_MODE<int32>(2, 3, 2, 3), me);
                            events.ScheduleEvent(EVENT_GAS_SPORE, urand(40000, 45000));
                            events.RescheduleEvent(EVENT_VILE_GAS, urand(28000, 35000));
                            break;
                        case EVENT_GASTRIC_BLOAT:
                            DoCastVictim(SPELL_GASTRIC_BLOAT);
                            events.ScheduleEvent(EVENT_GASTRIC_BLOAT, urand(15000, 17500));
                            break;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK2);
                            Talk(SAY_BERSERK);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            void SetData(uint32 type, uint32 data)
            {
                if (type == DATA_INOCULATED_STACK && data > maxInoculatedStack)
                    maxInoculatedStack = data;
            }

            uint32 GetData(uint32 type)
            {
                if (type == DATA_INOCULATED_STACK)
                    return uint32(maxInoculatedStack);

                return 0;
            }

            void _RemoveBlight()
            {
                if (Creature* gasDummy = ObjectAccessor::GetCreature(*me, gasDummyGUID))
                    for (uint8 i = 0; i < 3; ++i)
                    {
                        me->RemoveAurasDueToSpell(gaseousBlight[i]);
                        gasDummy->RemoveAurasDueToSpell(gaseousBlightVisual[i]);
                    }
            }

        private:
            uint64 gasDummyGUID;
            uint32 maxInoculatedStack;
            uint32 inhaleCounter;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<boss_festergutAI>(creature);
        }
};

class npc_stinky_icc : public CreatureScript
{
    public:
        npc_stinky_icc() : CreatureScript("npc_stinky_icc") { }

        struct npc_stinky_iccAI : public ScriptedAI
        {
            npc_stinky_iccAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            void Reset()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_DECIMATE, urand(20000, 25000));
                events.ScheduleEvent(EVENT_MORTAL_WOUND, urand(3000, 7000));
                DoCast(me, SPELL_PLAGUE_STENCH);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DECIMATE:
                            DoCastVictim(SPELL_DECIMATE);
                            events.ScheduleEvent(EVENT_DECIMATE, urand(20000, 25000));
                            break;
                        case EVENT_MORTAL_WOUND:
                            DoCastVictim(SPELL_MORTAL_WOUND);
                            events.ScheduleEvent(EVENT_MORTAL_WOUND, urand(10000, 12500));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*who*/)
            {
                if (Creature* festergut = me->GetCreature(*me, instance->GetData64(DATA_FESTERGUT)))
                    if (festergut->isAlive())
                        festergut->AI()->Talk(SAY_STINKY_DEAD);
            }

        private:
            EventMap events;
            InstanceScript* instance;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<npc_stinky_iccAI>(creature);
        }
};

class spell_festergut_pungent_blight : public SpellScriptLoader
{
    public:
        spell_festergut_pungent_blight() : SpellScriptLoader("spell_festergut_pungent_blight") { }

        class spell_festergut_pungent_blight_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_festergut_pungent_blight_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                SpellEntry const* spellInfo = sSpellStore.LookupEntry(uint32(GetEffectValue()));
                if (!spellInfo || GetCaster()->GetTypeId() != TYPEID_UNIT)
                    return;

                // Get Inhaled Blight id for our difficulty
                spellInfo = sSpellMgr->GetSpellForDifficultyFromSpell(spellInfo, GetCaster());

                // ...and remove it
                GetCaster()->RemoveAurasDueToSpell(spellInfo->Id);
                GetCaster()->ToCreature()->AI()->Talk(EMOTE_PUNGENT_BLIGHT);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_festergut_pungent_blight_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_festergut_pungent_blight_SpellScript();
        }
};

class spell_festergut_gastric_bloat : public SpellScriptLoader
{
    public:
        spell_festergut_gastric_bloat() : SpellScriptLoader("spell_festergut_gastric_bloat") { }

        class spell_festergut_gastric_bloat_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_festergut_gastric_bloat_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Aura const* aura = GetHitUnit()->GetAura(GetSpellInfo()->Id);
                if (!(aura && aura->GetStackAmount() == 10))
                    return;

                SpellEntry const* spellInfo = sSpellStore.LookupEntry(SPELL_GASTRIC_EXPLOSION);
                if (!spellInfo)
                    return;

                // Get Gastric Explosion id for our difficulty
                spellInfo = sSpellMgr->GetSpellForDifficultyFromSpell(spellInfo, GetCaster());
                GetHitUnit()->RemoveAurasDueToSpell(GetSpellInfo()->Id);
                GetHitUnit()->CastSpell(GetHitUnit(), spellInfo, true);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_festergut_gastric_bloat_SpellScript::HandleScript, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_festergut_gastric_bloat_SpellScript();
        }
};

class spell_festergut_blighted_spores : public SpellScriptLoader
{
    public:
        spell_festergut_blighted_spores() : SpellScriptLoader("spell_festergut_blighted_spores") { }

        class spell_festergut_blighted_spores_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_festergut_blighted_spores_AuraScript);

            void ExtraEffect(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetCaster()->IsAIEnabled || GetCaster()->GetTypeId() != TYPEID_UNIT)
                    return;

                uint32 inoculateId = CAST_AI(ScriptedAI, GetCaster()->ToCreature()->AI())->INOCULATED_HELPER;
                uint32 currStack = 0;
                if (Aura const* inoculate = GetTarget()->GetAura(inoculateId))
                    currStack = inoculate->GetStackAmount();

                GetTarget()->CastSpell(GetTarget(), SPELL_INOCULATED, true);
                ++currStack;
                GetCaster()->ToCreature()->AI()->SetData(DATA_INOCULATED_STACK, currStack);
            }

            void Register()
            {
                OnEffectApply += AuraEffectApplyFn(spell_festergut_blighted_spores_AuraScript::ExtraEffect, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_festergut_blighted_spores_AuraScript();
        }
};

class spell_festergut_gaseous_blight : public SpellScriptLoader
{
    public:
        spell_festergut_gaseous_blight() : SpellScriptLoader("spell_festergut_gaseous_blight") { }

        class spell_festergut_gaseous_blight_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_festergut_gaseous_blight_SpellScript);

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_ORANGE_BLIGHT_RESIDUE))
                    return false;
                return true;
            }

            void ExtraEffect()
            {
                if (GetHitUnit()->HasAura(SPELL_ORANGE_BLIGHT_RESIDUE))
                    return;

                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_ORANGE_BLIGHT_RESIDUE, true);
            }

            void Register()
            {
                AfterHit += SpellHitFn(spell_festergut_gaseous_blight_SpellScript::ExtraEffect);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_festergut_gaseous_blight_SpellScript();
        }
};

class achievement_flu_shot_shortage : public AchievementCriteriaScript
{
    public:
        achievement_flu_shot_shortage() : AchievementCriteriaScript("achievement_flu_shot_shortage") { }

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (target && target->GetTypeId() == TYPEID_UNIT)
                return target->ToCreature()->AI()->GetData(DATA_INOCULATED_STACK) < 3;

            return false;
        }
};

void AddSC_boss_festergut()
{
    new boss_festergut();
    new npc_stinky_icc();
    new spell_festergut_pungent_blight();
    new spell_festergut_gastric_bloat();
    new spell_festergut_blighted_spores();
    new spell_festergut_gaseous_blight();
    new achievement_flu_shot_shortage();
}

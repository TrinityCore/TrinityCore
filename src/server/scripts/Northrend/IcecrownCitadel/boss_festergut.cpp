/*
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "ScriptPCH.h"
#include "icecrown_citadel.h"

enum eScriptTexts
{
    SAY_STINKY_DEAD             = -1631078,
    SAY_AGGRO                   = -1631079,
    EMOTE_GAS_SPORE             = -1631081,
    EMOTE_WARN_GAS_SPORE        = -1631082,
    SAY_PUNGENT_BLIGHT          = -1631083,
    EMOTE_WARN_PUNGENT_BLIGHT   = -1631084,
    EMOTE_PUNGENT_BLIGHT        = -1631085,
    SAY_KILL_1                  = -1631086,
    SAY_KILL_2                  = -1631087,
    SAY_BERSERK                 = -1631088,
    SAY_DEATH                   = -1631089
};

enum eSpells
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
    SPELL_PLAGUE_STENCH         = 71805
};

// Used for HasAura checks
#define PUNGENT_BLIGHT_HELPER RAID_MODE(69195,71219,73031,73032)
#define INOCULATED_HELPER     RAID_MODE(69291,72101,72102,72103)

static const uint32 gaseousBlight[3]        = {69157, 69162, 69164};
static const uint32 gaseousBlightVisual[3]  = {69126, 69152, 69154};

enum eEvents
{
    EVENT_BERSERK       = 1,
    EVENT_INHALE_BLIGHT = 2,
    EVENT_VILE_GAS      = 3,
    EVENT_GAS_SPORE     = 4,
    EVENT_GASTRIC_BLOAT = 5,

    EVENT_DECIMATE      = 6,
    EVENT_MORTAL_WOUND  = 7
};

#define DATA_INOCULATED_STACK 69291

class boss_festergut : public CreatureScript
{
    public:
        boss_festergut() : CreatureScript("boss_festergut") { }

        struct boss_festergutAI : public BossAI
        {
            boss_festergutAI(Creature* pCreature) : BossAI(pCreature, DATA_FESTERGUT)
            {
                ASSERT(instance);
                uiMaxInoculatedStack = 0;
                uiInhaleCounter = 0;
                gasDummyGUID = 0;
            }

            void Reset()
            {
                events.Reset();
                events.ScheduleEvent(EVENT_BERSERK, 300000);
                events.ScheduleEvent(EVENT_INHALE_BLIGHT, urand(25000, 30000));
                events.ScheduleEvent(EVENT_VILE_GAS, urand(30000, 32500));
                events.ScheduleEvent(EVENT_GAS_SPORE, urand(20000, 25000));
                events.ScheduleEvent(EVENT_GASTRIC_BLOAT, urand(12500, 15000));
                uiMaxInoculatedStack = 0;
                uiInhaleCounter = 0;
                me->RemoveAurasDueToSpell(SPELL_BERSERK2);
                if (Creature* gasDummy = GetClosestCreatureWithEntry(me, NPC_GAS_DUMMY, 100.0f, true))
                {
                    gasDummyGUID = gasDummy->GetGUID();
                    for (uint8 i = 0; i < 3; ++i)
                    {
                        gasDummy->RemoveAurasDueToSpell(gaseousBlight[i]);
                        gasDummy->RemoveAurasDueToSpell(gaseousBlightVisual[i]);
                    }
                }

                instance->SetBossState(DATA_FESTERGUT, NOT_STARTED);
            }

            void EnterCombat(Unit* /*who*/)
            {
                DoScriptText(SAY_AGGRO, me);
                if (Creature* gasDummy = GetClosestCreatureWithEntry(me, NPC_GAS_DUMMY, 100.0f, true))
                    gasDummyGUID = gasDummy->GetGUID();
                instance->SetBossState(DATA_FESTERGUT, IN_PROGRESS);
                if (Creature* professor = Unit::GetCreature(*me, instance->GetData64(DATA_PROFESSOR_PUTRICIDE)))
                    professor->AI()->DoAction(ACTION_FESTERGUT_COMBAT);

                DoZoneInCombat(me);
            }

            void JustDied(Unit* /*killer*/)
            {
                DoScriptText(SAY_DEATH, me);
                instance->SetBossState(DATA_FESTERGUT, DONE);
                if (Creature* professor = Unit::GetCreature(*me, instance->GetData64(DATA_PROFESSOR_PUTRICIDE)))
                    professor->AI()->DoAction(ACTION_FESTERGUT_DEATH);
            }

            void JustReachedHome()
            {
                instance->SetBossState(DATA_FESTERGUT, FAIL);
            }

            void EnterEvadeMode()
            {
                ScriptedAI::EnterEvadeMode();
                if (Creature* professor = Unit::GetCreature(*me, instance->GetData64(DATA_PROFESSOR_PUTRICIDE)))
                    professor->AI()->EnterEvadeMode();
            }

            void KilledUnit(Unit *victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    DoScriptText(RAND(SAY_KILL_1, SAY_KILL_2), me);
            }

            void MoveInLineOfSight(Unit* /*who*/)
            {
                // don't enter combat
            }

            void SpellHitTarget(Unit* target, const SpellEntry* spell)
            {
                if (spell->Id == PUNGENT_BLIGHT_HELPER)
                    target->RemoveAurasDueToSpell(INOCULATED_HELPER);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim() || !CheckInRoom())
                    return;

                events.Update(diff);

                if (me->hasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_INHALE_BLIGHT:
                        {
                            if (Creature* gasDummy = Unit::GetCreature(*me, gasDummyGUID))
                                for (uint8 i = 0; i < 3; ++i)
                                {
                                    gasDummy->RemoveAurasDueToSpell(gaseousBlight[i]);
                                    gasDummy->RemoveAurasDueToSpell(gaseousBlightVisual[i]);
                                }
                            if (uiInhaleCounter == 3)
                            {
                                DoScriptText(EMOTE_WARN_PUNGENT_BLIGHT, me);
                                DoScriptText(SAY_PUNGENT_BLIGHT, me);
                                DoCast(me, SPELL_PUNGENT_BLIGHT);
                                uiInhaleCounter = 0;
                                if (Creature* professor = Unit::GetCreature(*me, instance->GetData64(DATA_PROFESSOR_PUTRICIDE)))
                                    professor->AI()->DoAction(ACTION_FESTERGUT_GAS);
                            }
                            else
                            {
                                DoCast(me, SPELL_INHALE_BLIGHT);
                                // just cast and dont bother with target, conditions will handle it
                                ++uiInhaleCounter;
                                if (uiInhaleCounter < 3)
                                    me->CastSpell(me, gaseousBlight[uiInhaleCounter], true, NULL, NULL, me->GetGUID());
                            }
                            events.ScheduleEvent(EVENT_INHALE_BLIGHT, urand(33500, 35000));
                            return;
                        }
                        case EVENT_VILE_GAS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(target, SPELL_VILE_GAS);
                            events.ScheduleEvent(EVENT_VILE_GAS, urand(28000, 35000));
                            break;
                        case EVENT_GAS_SPORE:
                            DoScriptText(EMOTE_WARN_GAS_SPORE, me);
                            me->CastCustomSpell(SPELL_GAS_SPORE, SPELLVALUE_MAX_TARGETS, RAID_MODE<int32>(2,3,2,3), me);
                            DoScriptText(EMOTE_GAS_SPORE, me);
                            events.ScheduleEvent(EVENT_GAS_SPORE, urand(40000, 45000));
                        case EVENT_GASTRIC_BLOAT:
                            DoCastVictim(SPELL_GASTRIC_BLOAT);
                            events.ScheduleEvent(EVENT_GASTRIC_BLOAT, urand(15000, 17500));
                            break;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK2);
                            DoScriptText(SAY_BERSERK, me);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            void SetData(uint32 type, uint32 data)
            {
                if (type == DATA_INOCULATED_STACK && data > uiMaxInoculatedStack)
                    uiMaxInoculatedStack = data;
            }

            uint32 GetData(uint32 type)
            {
                if (type == DATA_INOCULATED_STACK)
                    return uint32(uiMaxInoculatedStack);

                return 0;
            }

        private:
            uint32 uiMaxInoculatedStack;
            uint8 uiInhaleCounter;
            uint64 gasDummyGUID;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new boss_festergutAI(pCreature);
        }
};

class npc_stinky_icc : public CreatureScript
{
    public:
        npc_stinky_icc() : CreatureScript("npc_stinky_icc") { }

        struct npc_stinky_iccAI : public ScriptedAI
        {
            npc_stinky_iccAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                pInstance = pCreature->GetInstanceScript();
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

                if (me->hasUnitState(UNIT_STAT_CASTING))
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
                uint64 festergutGUID = pInstance ? pInstance->GetData64(DATA_FESTERGUT) : 0;
                if (Creature *festergut = me->GetCreature(*me, festergutGUID))
                    DoScriptText(SAY_STINKY_DEAD, festergut);
            }

        private:
            EventMap events;
            InstanceScript* pInstance;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_stinky_iccAI(pCreature);
        }
};

class spell_festergut_pungent_blight : public SpellScriptLoader
{
    public:
        spell_festergut_pungent_blight() : SpellScriptLoader("spell_festergut_pungent_blight") { }

        class spell_festergut_pungent_blight_SpellScript : public SpellScript
        {
            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                SpellEntry const* spellInfo = sSpellStore.LookupEntry(GetEffectValue());
                if (!spellInfo)
                    return;

                // Get Inhaled Blight id for our difficulty
                spellInfo = sSpellMgr.GetSpellForDifficultyFromSpell(spellInfo, GetCaster());

                // ...and remove it
                GetCaster()->RemoveAurasDueToSpell(spellInfo->Id);
                DoScriptText(EMOTE_PUNGENT_BLIGHT, GetCaster());
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
            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Aura const* aura = GetHitUnit()->GetAura(GetSpellInfo()->Id);
                if (!(aura && aura->GetStackAmount() == 10))
                    return;

                //PreventHitAura();

                SpellEntry const* spellInfo = sSpellStore.LookupEntry(SPELL_GASTRIC_EXPLOSION);
                if (!spellInfo)
                    return;

                // Get Gastric Explosion id for our difficulty
                spellInfo = sSpellMgr.GetSpellForDifficultyFromSpell(spellInfo, GetCaster());
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
            void ExtraEffect(AuraEffect const* /*aurEff*/, AuraApplication const* aurApp, AuraEffectHandleModes /*mode*/)
            {
                if (!GetCaster()->IsAIEnabled || GetCaster()->GetTypeId() != TYPEID_UNIT)
                    return;

                uint32 inoculateId = CAST_AI(ScriptedAI, GetCaster()->ToCreature()->AI())->INOCULATED_HELPER;
                uint32 currStack = 0;
                if (Aura const* inoculate = aurApp->GetTarget()->GetAura(inoculateId))
                    currStack = inoculate->GetStackAmount();

                aurApp->GetTarget()->CastSpell(aurApp->GetTarget(), SPELL_INOCULATED, true);
                ++currStack;
                if (GetCaster())
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
    new achievement_flu_shot_shortage();
}

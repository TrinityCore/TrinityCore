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
#include "Player.h"
#include "naxxramas.h"

enum StalaggYells
{
    SAY_STAL_AGGRO          = 0,
    SAY_STAL_SLAY           = 1,
    SAY_STAL_DEATH          = 2
};

enum StalagSpells
{
    SPELL_POWERSURGE        = 28134,
    SPELL_MAGNETIC_PULL     = 28338
};

enum FeugenYells
{
    SAY_FEUG_AGGRO          = 0,
    SAY_FEUG_SLAY           = 1,
    SAY_FEUG_DEATH          = 2
};

enum FeugenSpells
{
    SPELL_STATICFIELD       = 28135
};

enum ThaddiusYells
{
    SAY_GREET               = 0,
    SAY_AGGRO               = 1,
    SAY_SLAY                = 2,
    SAY_ELECT               = 3,
    SAY_DEATH               = 4,
    EMOTE_SHIFT             = 5,
    SAY_SCREAM              = 6
};

enum ThaddiusSpells
{
    SPELL_THADIUS_SPAWN             = 28160,
    SPELL_THADIUS_LIGHTNING_VISUAL  = 28136,
    SPELL_POLARITY_SHIFT            = 28089,
    SPELL_BALL_LIGHTNING            = 28299,
    SPELL_CHAIN_LIGHTNING           = 28167,
    SPELL_BERSERK                   = 27680,
    SPELL_POSITIVE_CHARGE           = 28062,
    SPELL_POSITIVE_CHARGE_STACK     = 29659,
    SPELL_NEGATIVE_CHARGE           = 28085,
    SPELL_NEGATIVE_CHARGE_STACK     = 29660,
    SPELL_POSITIVE_POLARITY         = 28059,
    SPELL_NEGATIVE_POLARITY         = 28084
};

enum ThaddiusActions
{
    ACTION_FEUGEN_RESET     = 1,
    ACTION_FEUGEN_DIED      = 2,
    ACTION_STALAGG_RESET    = 3,
    ACTION_STALAGG_DIED     = 4,
    ACTION_INTRO            = 5
};

enum TeslaSpells
{
    SPELL_FEUGEN_CHAIN              = 28111,
    SPELL_STALAGG_CHAIN             = 28096,
    SPELL_FEUGEN_TESLA_PASSIVE      = 28109,
    SPELL_STALAGG_TESLA_PASSIVE     = 28097,
    SPELL_SHOCK_OVERLOAD            = 28159,
    SPELL_SHOCK                     = 28099
};

enum TeslaEmotes
{
    EMOTE_LOSING_LINK               = 1,
    EMOTE_TESLA_OVERLOAD            = 2
};

enum Events
{
    EVENT_NONE,
    EVENT_SHIFT,
    EVENT_CHAIN,
    EVENT_BERSERK
};

enum Achievement
{
    DATA_POLARITY_SWITCH    = 76047605
};

class boss_thaddius : public CreatureScript
{
    public:
        boss_thaddius() : CreatureScript("boss_thaddius") { }

        struct boss_thaddiusAI : public BossAI
        {
            boss_thaddiusAI(Creature* creature) : BossAI(creature, DATA_THADDIUS)
            {
                checkFeugenAlive = false;
                if (Creature* pFeugen = me->GetCreature(*me, instance->GetData64(DATA_FEUGEN)))
                    checkFeugenAlive = pFeugen->isAlive();

                checkStalaggAlive = false;
                if (Creature* pStalagg = me->GetCreature(*me, instance->GetData64(DATA_STALAGG)))
                    checkStalaggAlive = pStalagg->isAlive();

                if (!checkFeugenAlive && !checkStalaggAlive)
                {
                    me->RemoveAurasDueToSpell(SPELL_THADIUS_SPAWN);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED);
                }
                else
                {
                    me->CastSpell(me,SPELL_THADIUS_SPAWN,true);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED);
                }
            }

            void KilledUnit(Unit* /*victim*/)
            {
                TalkToMap(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                TalkToMap(SAY_DEATH);
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_FEUGEN_RESET:
                        checkFeugenAlive = true;
                        break;
                    case ACTION_FEUGEN_DIED:
                        checkFeugenAlive = false;
                        break;
                    case ACTION_STALAGG_RESET:
                        checkStalaggAlive = true;
                        break;
                    case ACTION_STALAGG_DIED:
                        checkStalaggAlive = false;
                        break;
                    case ACTION_INTRO:
                        if (!_introDone)
                        {
                            TalkToMap(SAY_GREET);
                            _introDone = true;
                        }
                        break;
                }

                if (!checkFeugenAlive && !checkStalaggAlive)
                {
                    me->RemoveAurasDueToSpell(SPELL_THADIUS_SPAWN);
                    me->CastSpell(me,SPELL_THADIUS_LIGHTNING_VISUAL,true);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED);
                }
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                TalkToMap(SAY_AGGRO);
                events.ScheduleEvent(EVENT_SHIFT, 30000);
                events.ScheduleEvent(EVENT_CHAIN, urand(10000, 20000));
                events.ScheduleEvent(EVENT_BERSERK, 360000);
            }

            void DamageTaken(Unit* /*pDoneBy*/, uint32 & /*uiDamage*/)
            {
                me->SetReactState(REACT_AGGRESSIVE);
            }

            void SetData(uint32 id, uint32 data)
            {
                if (id == DATA_POLARITY_SWITCH)
                    polaritySwitch = data ? true : false;
            }

            uint32 GetData(uint32 id) const
            {
                if (id != DATA_POLARITY_SWITCH)
                    return 0;

                return uint32(polaritySwitch);
            }

            void UpdateAI(uint32 diff)
            {
                if (checkFeugenAlive && checkStalaggAlive)
                    uiAddsTimer = 0;

                if (checkStalaggAlive != checkFeugenAlive)
                {
                    uiAddsTimer += diff;
                    if (uiAddsTimer > 5000)
                    {
                        if (!checkStalaggAlive)
                        {
                            if (instance)
                                if (Creature* pStalagg = me->GetCreature(*me, instance->GetData64(DATA_STALAGG)))
                                    pStalagg->Respawn();
                        }
                        else
                        {
                            if (instance)
                                if (Creature* pFeugen = me->GetCreature(*me, instance->GetData64(DATA_FEUGEN)))
                                    pFeugen->Respawn();
                        }
                    }
                }

                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SHIFT:
                            TalkToMap(EMOTE_SHIFT);
                            TalkToMap(SAY_ELECT);
                            DoCastAOE(SPELL_POLARITY_SHIFT);
                            events.ScheduleEvent(EVENT_SHIFT, 30000);
                            break;
                        case EVENT_CHAIN:
                            DoCast(me->getVictim(), SPELL_CHAIN_LIGHTNING);
                            events.ScheduleEvent(EVENT_CHAIN, urand(10000, 20000));
                            break;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK);
                            break;
                    }
                }

                    if (events.GetTimer() > 15000 && !me->IsWithinMeleeRange(me->getVictim()))
                        DoCast(me->getVictim(), SPELL_BALL_LIGHTNING);
                    else
                        DoMeleeAttackIfReady();
            }

        private:
            bool checkStalaggAlive;
            bool checkFeugenAlive;
            bool polaritySwitch;
            bool _introDone;
            uint32 uiAddsTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetNaxxramasAI<boss_thaddiusAI>(creature);
        }
};

class mob_stalagg : public CreatureScript
{
    public:
        mob_stalagg() : CreatureScript("mob_stalagg") { }

        struct mob_stalaggAI : public ScriptedAI
        {
            mob_stalaggAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
                IsChanneling = false;
            }

            void Reset()
            {
                if (instance)
                    if (Creature* pThaddius = me->GetCreature(*me, instance->GetData64(DATA_THADDIUS)))
                        if (pThaddius->AI())
                            pThaddius->AI()->DoAction(ACTION_STALAGG_RESET);
                powerSurgeTimer = urand(20000, 25000);
                magneticPullTimer = 20000;
                TeslaStalaggTimer=0;
                IsChanneling = false;
                if (GameObject* pTesla = instance->instance->GetGameObject(instance->GetData64(DATA_TESLA_STALAG)))
                    if (Creature* tesla = pTesla->FindNearestCreature(NPC_TESLA, 0.0f))
                    {
                        tesla->CastSpell(me,SPELL_STALAGG_CHAIN);
                        IsChanneling = true;
                        TeslaStalaggTimer = 0;
                    }
            }

            void EnterCombat(Unit* /*who*/)
            {
                TalkToMap(SAY_STAL_AGGRO);
            }

            void JustDied(Unit* /*killer*/)
            {
                TalkToMap(SAY_STAL_DEATH);
                if (instance)
                    if (Creature* pThaddius = me->GetCreature(*me, instance->GetData64(DATA_THADDIUS)))
                        if (pThaddius->AI())
                            pThaddius->AI()->DoAction(ACTION_STALAGG_DIED);
            }

            void KilledUnit(Unit* /*victim*/)
            {
                TalkToMap(SAY_STAL_SLAY);
            }

            void UpdateAI(uint32 uiDiff)
            {
                if (TeslaStalaggTimer <= uiDiff)
                {
                    if (!IsChanneling)
                    {
                        if (GameObject* pTesla = instance->instance->GetGameObject(instance->GetData64(DATA_TESLA_STALAG)))
                            if (Creature* tesla = pTesla->FindNearestCreature(NPC_TESLA, 0.0f))
                            {
                                tesla->CastSpell(me,SPELL_STALAGG_CHAIN);
                                IsChanneling = true;
                                TeslaStalaggTimer = 0;
                            }
                    }
                    else
                        TeslaStalaggTimer = 1;
                } 
                else 
                    TeslaStalaggTimer -= uiDiff;

                if (!UpdateVictim())
                    return;

                if (magneticPullTimer <= uiDiff)
                {
                    if (Creature* pFeugen = me->GetCreature(*me, instance->GetData64(DATA_FEUGEN)))
                    {
                        Unit* pStalaggVictim = me->getVictim();
                        Unit* pFeugenVictim = pFeugen->getVictim();

                        if (pFeugenVictim && pStalaggVictim)
                        {
                            pFeugen->getThreatManager().modifyThreatPercent(pFeugenVictim, -100);
                            pFeugenVictim->JumpTo(me, 0.3f);
                            me->getThreatManager().modifyThreatPercent(pStalaggVictim, -100);
                            pStalaggVictim->JumpTo(pFeugen, 0.3f);
                        }
                    }
                    magneticPullTimer = 20000;
                }
                else
                    magneticPullTimer -= uiDiff;

                if (powerSurgeTimer <= uiDiff)
                {
                    DoCast(me, SPELL_POWERSURGE);
                    powerSurgeTimer = urand(15000, 20000);
                }
                else
                    powerSurgeTimer -= uiDiff;

                DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* instance;
            uint32 powerSurgeTimer;
            uint32 magneticPullTimer;
            uint32 TeslaStalaggTimer;
            bool IsChanneling;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetNaxxramasAI<mob_stalaggAI>(creature);
        }
};

class mob_feugen : public CreatureScript
{
    public:
        mob_feugen() : CreatureScript("mob_feugen") { }

        struct mob_feugenAI : public ScriptedAI
        {
            mob_feugenAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
                IsChanneling = false;
            }

            void Reset()
            {
                if (instance)
                    if (Creature* pThaddius = me->GetCreature(*me, instance->GetData64(DATA_THADDIUS)))
                        pThaddius->AI()->DoAction(ACTION_FEUGEN_RESET);
                staticFieldTimer = 5000;
                TeslaFeugenTimer = 0;
                IsChanneling = false;
                if (GameObject* pTesla = instance->instance->GetGameObject(instance->GetData64(DATA_TESLA_FEUGEN)))
                    if (Creature* tesla = pTesla->FindNearestCreature(NPC_TESLA, 0.0f))
                    {
                        tesla->CastSpell(me,SPELL_FEUGEN_CHAIN);
                        IsChanneling = true;
                        TeslaFeugenTimer = 0;
                    }
            }

            void EnterCombat(Unit* /*who*/)
            {
                TalkToMap(SAY_FEUG_AGGRO);
            }

            void JustDied(Unit* /*killer*/)
            {
                TalkToMap(SAY_FEUG_DEATH);
                if (instance)
                    if (Creature* pThaddius = me->GetCreature(*me, instance->GetData64(DATA_THADDIUS)))
                        if (pThaddius->AI())
                            pThaddius->AI()->DoAction(ACTION_FEUGEN_DIED);
            }

            void KilledUnit(Unit* /*victim*/)
            {
                TalkToMap(SAY_FEUG_SLAY);
            }

            void UpdateAI(uint32 uiDiff)
            {
                if (TeslaFeugenTimer <= uiDiff)
                {
                    if (!IsChanneling)
                    {
                        if (GameObject* pTesla = instance->instance->GetGameObject(instance->GetData64(DATA_TESLA_FEUGEN)))
                            if (Creature* tesla = pTesla->FindNearestCreature(NPC_TESLA, 0.0f))
                            {
                                tesla->CastSpell(me,SPELL_FEUGEN_CHAIN);
                                IsChanneling = true;
                                TeslaFeugenTimer = 0;
                            }
                    }
                    else
                        TeslaFeugenTimer = 1;
                } 
                else 
                    TeslaFeugenTimer -= uiDiff;

                if (!UpdateVictim())
                    return;

                if (staticFieldTimer <= uiDiff)
                {
                    DoCast(me, SPELL_STATICFIELD);
                    staticFieldTimer = 5000;
                }
                else
                    staticFieldTimer -= uiDiff;

                DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* instance;
            uint32 TeslaFeugenTimer;
            uint32 staticFieldTimer;
            bool IsChanneling;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetNaxxramasAI<mob_feugenAI>(creature);
        }
};

class spell_thaddius_pos_neg_charge : public SpellScriptLoader
{
    public:
        spell_thaddius_pos_neg_charge() : SpellScriptLoader("spell_thaddius_pos_neg_charge") { }

        class spell_thaddius_pos_neg_charge_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_thaddius_pos_neg_charge_SpellScript);

            bool Validate(SpellInfo const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_POSITIVE_CHARGE))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_POSITIVE_CHARGE_STACK))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_NEGATIVE_CHARGE))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_NEGATIVE_CHARGE_STACK))
                    return false;
                return true;
            }

            bool Load()
            {
                return GetCaster()->GetTypeId() == TYPEID_UNIT;
            }

            void HandleTargets(std::list<WorldObject*>& targets)
            {
                uint8 count = 0;
                for (std::list<WorldObject*>::iterator ihit = targets.begin(); ihit != targets.end(); ++ihit)
                    if ((*ihit)->GetGUID() != GetCaster()->GetGUID())
                        if (Player* target = (*ihit)->ToPlayer())
                            if (target->HasAura(GetTriggeringSpell()->Id))
                                ++count;

                if (count)
                {
                    uint32 spellId = 0;

                    if (GetSpellInfo()->Id == SPELL_POSITIVE_CHARGE)
                        spellId = SPELL_POSITIVE_CHARGE_STACK;
                    else
                        spellId = SPELL_NEGATIVE_CHARGE_STACK;

                    GetCaster()->SetAuraStack(spellId, GetCaster(), count);
                }
            }

            void HandleDamage(SpellEffIndex /*effIndex*/)
            {
                if (!GetTriggeringSpell())
                    return;

                Unit* target = GetHitUnit();
                Unit* caster = GetCaster();

                if (target->HasAura(GetTriggeringSpell()->Id))
                    SetHitDamage(0);
                else
                {
                    if (target->GetTypeId() == TYPEID_PLAYER && caster->IsAIEnabled)
                        caster->ToCreature()->AI()->SetData(DATA_POLARITY_SWITCH, 1);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_thaddius_pos_neg_charge_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_thaddius_pos_neg_charge_SpellScript::HandleTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_thaddius_pos_neg_charge_SpellScript();
        }
};

class spell_thaddius_polarity_shift : public SpellScriptLoader
{
    public:
        spell_thaddius_polarity_shift() : SpellScriptLoader("spell_thaddius_polarity_shift") { }

        class spell_thaddius_polarity_shift_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_thaddius_polarity_shift_SpellScript);

            bool Validate(SpellInfo const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_POSITIVE_POLARITY) || !sSpellMgr->GetSpellInfo(SPELL_NEGATIVE_POLARITY))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /* effIndex */)
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetHitUnit())
                    target->CastSpell(target, roll_chance_i(50) ? SPELL_POSITIVE_POLARITY : SPELL_NEGATIVE_POLARITY, true, NULL, NULL, caster->GetGUID());
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_thaddius_polarity_shift_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_thaddius_polarity_shift_SpellScript();
        }
};

class achievement_polarity_switch : public AchievementCriteriaScript
{
    public:
        achievement_polarity_switch() : AchievementCriteriaScript("achievement_polarity_switch") { }

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            return target && target->GetAI()->GetData(DATA_POLARITY_SWITCH);
        }
};

class at_thaddius_intro : public AreaTriggerScript
{
    public:
        at_thaddius_intro() : AreaTriggerScript("at_thaddius_intro") { }

        bool OnTrigger(Player* player, const AreaTriggerEntry* /*at*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->GetBossState(DATA_THADDIUS) != DONE)
                    if (Creature* Thaddius = ObjectAccessor::GetCreature(*player, instance->GetData64(DATA_THADDIUS)))
                        Thaddius->AI()->DoAction(ACTION_INTRO);
            return true;
        }
};

void AddSC_boss_thaddius()
{
    new boss_thaddius();
    new mob_stalagg();
    new mob_feugen();
    new spell_thaddius_pos_neg_charge();
    new spell_thaddius_polarity_shift();
    new achievement_polarity_switch();
    new at_thaddius_intro();
}

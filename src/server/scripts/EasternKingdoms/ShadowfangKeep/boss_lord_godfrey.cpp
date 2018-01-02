/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

enum Texts
{
    SAY_AGGRO_ALLIANCE              = 0,
    SAY_AGGRO_HORDE                 = 1,
    SAY_SLAY                        = 2,
    SAY_ANNOUNCE_PISTOL_BARRAGE     = 3,
    SAY_DEATH                       = 4
};

enum Events
{
    // Lord Godfrey
    EVENT_CURSED_BULLETS = 1,
    EVENT_MORTAL_WOUND,
    EVENT_SUMMON_BLOODTHIRSTY_GHOULS,
    EVENT_PISTOL_BARRAGE,
    EVENT_PISTOL_BARRAGE_CAST,
    EVENT_APPLY_IMMUNITY,

    // Bloodthirsty Ghoul
    EVENT_ATTACK
};

enum Spells
{
    SPELL_CURSED_BULLETS                            = 93629,
    SPELL_CURSED_BULLETS_HC                         = 93761,
    SPELL_MORTAL_WOUND                              = 93675,
    SPELL_SUMMON_BLOODTHIRSTY_GHOULS_AURA           = 93707,
    SPELL_SUMMON_BLOODTHIRSTY_GHOULS_TRIGGERED_1    = 93709,
    SPELL_SUMMON_BLOODTHIRSTY_GHOULS_TRIGGERED_2    = 93714,

    SPELL_PISTOL_BARRAGE_FORCE_CAST                 = 96344,
    SPELL_PISTOL_BARRAGE_CAST                       = 93520,
    SPELL_BULLET_TIME_CREDIT                        = 95929,

    SPELL_PISTOL_BARRAGE_TRIGGER_1                  = 93566,
    SPELL_PISTOL_BARRAGE_TRIGGER_2                  = 93558
};

enum AchievementData
{
    DATA_BULLET_TIME = 1,
};

class boss_lord_godfrey : public CreatureScript
{
public:
    boss_lord_godfrey() : CreatureScript("boss_lord_godfrey") { }

    struct boss_lord_godfreyAI : public BossAI
    {
        boss_lord_godfreyAI(Creature* creature) : BossAI(creature, DATA_LORD_GODFREY)
        {
        }

        void Reset() override
        {
            _Reset();
            _killedGhoulCounter = 0;
            MakeInterruptable(false);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                Talk(SAY_AGGRO_ALLIANCE);
            else
                Talk(SAY_AGGRO_HORDE);

            _EnterCombat();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            events.ScheduleEvent(EVENT_CURSED_BULLETS, Seconds(10) + Milliseconds(800));
            events.ScheduleEvent(EVENT_MORTAL_WOUND, Seconds(3) + Milliseconds(500));
            events.ScheduleEvent(EVENT_SUMMON_BLOODTHIRSTY_GHOULS, Seconds(6));
            if (IsHeroic())
                events.ScheduleEvent(EVENT_PISTOL_BARRAGE, Seconds(12) + Milliseconds(500));
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            _JustDied();
        }

        void SummonedCreatureDies(Creature* summon, Unit* killer) override
        {
            switch (summon->GetEntry())
            {
                case NPC_BLOODTHIRSTY_GHOUL:
                    if (killer->GetEntry() == BOSS_LORD_GODFREY && IsHeroic())
                    {
                        DoCastAOE(SPELL_BULLET_TIME_CREDIT, true);
                        _killedGhoulCounter++;
                    }
                    break;
                default:
                    break;
            }
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
            me->SetReactState(REACT_AGGRESSIVE);
            instance->SetBossState(DATA_LORD_GODFREY, FAIL);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            _DespawnAtEvade();
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_BULLET_TIME:
                    return _killedGhoulCounter;;
                default:
                    break;
            }
            return 0;
        }

        void MakeInterruptable(bool apply)
        {
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_INTERRUPT, !apply);
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_INTERRUPT_CAST, !apply);
        }

        void OnSpellCastInterrupt(SpellInfo const* spell) override
        {
            switch (spell->Id)
            {
                case SPELL_CURSED_BULLETS:
                case SPELL_CURSED_BULLETS_HC:
                    events.CancelEvent(EVENT_APPLY_IMMUNITY);
                    MakeInterruptable(false);
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
                    case EVENT_CURSED_BULLETS:
                        MakeInterruptable(true);
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            DoCast(target, SPELL_CURSED_BULLETS);
                        events.ScheduleEvent(EVENT_CURSED_BULLETS, Seconds(12));
                        events.ScheduleEvent(EVENT_APPLY_IMMUNITY, Seconds(1) + Milliseconds(500));
                        break;
                    case EVENT_MORTAL_WOUND:
                        DoCastVictim(SPELL_MORTAL_WOUND);
                        events.Repeat(Seconds(6));
                        break;
                    case EVENT_SUMMON_BLOODTHIRSTY_GHOULS:
                        DoCastAOE(SPELL_SUMMON_BLOODTHIRSTY_GHOULS_AURA, true);
                        events.Repeat(Seconds(30));
                        break;
                    case EVENT_PISTOL_BARRAGE:
                        me->AttackStop();
                        me->SetReactState(REACT_PASSIVE);
                        DoCastAOE(SPELL_PISTOL_BARRAGE_FORCE_CAST);
                        events.ScheduleEvent(EVENT_PISTOL_BARRAGE_CAST, Milliseconds(500));
                        break;
                    case EVENT_PISTOL_BARRAGE_CAST:
                        if (Creature* target = me->FindNearestCreature(NPC_PISTOL_BARRAGE_DUMMY, 500.0f, true))
                        {
                            Talk(SAY_ANNOUNCE_PISTOL_BARRAGE);
                            me->SetFacingToObject(target);
                            DoCastAOE(SPELL_PISTOL_BARRAGE_CAST);
                        }
                        events.ScheduleEvent(EVENT_PISTOL_BARRAGE, Seconds(30) + Milliseconds(100));
                        break;
                    case EVENT_APPLY_IMMUNITY:
                        MakeInterruptable(false);
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        uint8 _killedGhoulCounter;
    };

    CreatureAI* GetAI(Creature *creature) const override
    {
        return GetShadowfangKeepAI<boss_lord_godfreyAI>(creature);
    }
};

class npc_sfk_bloodthirsty_ghoul : public CreatureScript
{
public:
    npc_sfk_bloodthirsty_ghoul() : CreatureScript("npc_sfk_bloodthirsty_ghoul") { }

    struct npc_sfk_bloodthirsty_ghoulAI : public ScriptedAI
    {
        npc_sfk_bloodthirsty_ghoulAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

        void IsSummonedBy(Unit* summoner) override
        {
            if (!summoner->IsInCombat())
                me->DespawnOrUnsummon();
            me->SetReactState(REACT_PASSIVE);

            me->HandleEmoteCommand(EMOTE_ONESHOT_EMERGE);
            DoZoneInCombat();
            _events.ScheduleEvent(EVENT_ATTACK, Seconds(4));
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->DespawnOrUnsummon(Seconds(5));
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ATTACK:
                        me->SetReactState(REACT_AGGRESSIVE);
                        if (Unit* target = me->SelectNearestPlayer(100.0f))
                            me->AI()->AttackStart(target);
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
        return GetShadowfangKeepAI<npc_sfk_bloodthirsty_ghoulAI>(creature);
    }
};

class spell_sfk_summon_bloodthirsty_ghouls : public SpellScriptLoader
{
public:
    spell_sfk_summon_bloodthirsty_ghouls() : SpellScriptLoader("spell_sfk_summon_bloodthirsty_ghouls") { }

    class spell_sfk_summon_bloodthirsty_ghouls_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sfk_summon_bloodthirsty_ghouls_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
            {
                SPELL_SUMMON_BLOODTHIRSTY_GHOULS_TRIGGERED_1,
                SPELL_SUMMON_BLOODTHIRSTY_GHOULS_TRIGGERED_2
            });
        }

        void OnPeriodic(AuraEffect const* /*aurEff*/)
        {
            switch (RAND(0, 1))
            {
                case 0:
                    GetCaster()->CastSpell((Unit*)NULL, SPELL_SUMMON_BLOODTHIRSTY_GHOULS_TRIGGERED_1, true);
                    break;
                case 1:
                    GetCaster()->CastSpell((Unit*)NULL, SPELL_SUMMON_BLOODTHIRSTY_GHOULS_TRIGGERED_2, true);
                    break;
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_sfk_summon_bloodthirsty_ghouls_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_sfk_summon_bloodthirsty_ghouls_AuraScript();
    }
};

class spell_sfk_pistol_barrage : public SpellScriptLoader
{
public:
    spell_sfk_pistol_barrage() : SpellScriptLoader("spell_sfk_pistol_barrage") { }

    class spell_sfk_pistol_barrage_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sfk_pistol_barrage_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
            {
                SPELL_PISTOL_BARRAGE_TRIGGER_1,
                SPELL_PISTOL_BARRAGE_TRIGGER_2
            });
        }

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
                caster->CastSpell(caster, SPELL_PISTOL_BARRAGE_TRIGGER_1, true);
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (caster->ToCreature())
                    caster->ToCreature()->SetReactState(REACT_AGGRESSIVE);
                caster->RemoveAurasDueToSpell(SPELL_PISTOL_BARRAGE_TRIGGER_1);
            }
        }

        void OnPeriodic(AuraEffect const* /*aurEff*/)
        {
            if (Unit* caster = GetCaster())
            {
                float ori = caster->GetOrientation() + frand(-0.5236f, 0.5236f);
                float posX = caster->GetPositionX() + cos(ori) * 60;
                float posY = caster->GetPositionY() + sin(ori) * 60;
                float posZ = caster->GetPositionZ();
                GetCaster()->CastSpell(posX, posY, posZ, SPELL_PISTOL_BARRAGE_TRIGGER_2, true);
            }
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_sfk_pistol_barrage_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_sfk_pistol_barrage_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_sfk_pistol_barrage_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_sfk_pistol_barrage_AuraScript();
    }
};

class spell_sfk_pistol_barrage_summon : public SpellScriptLoader
{
public:
    spell_sfk_pistol_barrage_summon() : SpellScriptLoader("spell_sfk_pistol_barrage_summon") { }

    class spell_sfk_pistol_barrage_summon_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sfk_pistol_barrage_summon_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            Trinity::Containers::RandomResize(targets, 1);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sfk_pistol_barrage_summon_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sfk_pistol_barrage_summon_SpellScript();
    }
};

class spell_sfk_cursed_bullets : public SpellScriptLoader
{
public:
    spell_sfk_cursed_bullets() : SpellScriptLoader("spell_sfk_cursed_bullets") { }

    class spell_sfk_cursed_bullets_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sfk_cursed_bullets_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            uint64 damage;
            damage = aurEff->GetBaseAmount() * aurEff->GetTickNumber();
            GetEffect(EFFECT_1)->ChangeAmount(damage);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_sfk_cursed_bullets_AuraScript::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sfk_cursed_bullets_AuraScript();
    }
};

class achievement_bullet_time : public AchievementCriteriaScript
{
public:
    achievement_bullet_time() : AchievementCriteriaScript("achievement_bullet_time") { }

    bool OnCheck(Player* /*source*/, Unit* target)
    {
        if (!target)
            return false;

        if (target->GetMap()->IsHeroic())
            return target->GetAI()->GetData(DATA_BULLET_TIME) >= 12;

        return false;
    }
};

void AddSC_boss_lord_godfrey()
{
    new boss_lord_godfrey();
    new npc_sfk_bloodthirsty_ghoul();
    new spell_sfk_summon_bloodthirsty_ghouls();
    new spell_sfk_pistol_barrage();
    new spell_sfk_pistol_barrage_summon();
    new spell_sfk_cursed_bullets();
    new achievement_bullet_time();
}

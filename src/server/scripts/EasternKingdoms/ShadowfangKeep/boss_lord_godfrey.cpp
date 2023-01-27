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

 /* ToDo
 * Find the correct Sound Yells
 * Find the correct Pistol Barrage Handling
 * Possible Pistol Barrage Visuals: 93566 | Triggered: 93564
 */

#include "ScriptMgr.h"
#include "shadowfang_keep.h"
#include "SpellMgr.h"

enum Spells
{
    SPELL_CURSED_BULLETS                   = 93629,
    SPELL_MORTAL_WOUND                     = 93675,
    SPELL_PISTOL_BARRAGE                   = 93520,
    SPELL_PISTOL_BARRAGE_DAMAGE            = 93564,
    SPELL_PISTOL_BARRAGE_TARGETS           = 96343,
    SPELL_SUMMON_GHOUL_CHANNELED           = 93707,
    SPELL_SUMMON_GHOUL_1                   = 93709,
    SPELL_SUMMON_GHOUL_2                   = 93714,

    // Only Heroic
    SPELL_CURSED_BULLETS_H                 = 93761,
    SPELL_MORTAL_WOUND_H                   = 93771
};

enum Events
{
   EVENT_CURSED_BULLETS                   = 1,
   EVENT_MORTAL_WOUND,
   EVENT_PISTOL_BARRAGE,
   EVENT_SUMMON_BLOODTHIRSTY_GHOULS,
};

enum eTexts
{
    SAY_AGGRO_A                          = 0,
    SAY_AGGRO_H                          = 1,
    SAY_DEATH                            = 2,
    SAY_KILLER_1                         = 3,
    SAY_KILLER_2                         = 4,
};

class boss_lord_godfrey : public CreatureScript
{
    struct boss_lord_godfreyAI : public BossAI
    {
        boss_lord_godfreyAI(Creature* creature) : BossAI(creature, DATA_LORD_GODFREY_EVENT) { }

        void Reset() override
        {
            _Reset();
            instance->HandleGameObject(instance->GetGuidData(GO_LORD_GODFREY_DOOR), true);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (me->SelectNearestPlayer(10.0f))
            {
                _EnterCombat();

                if (instance->GetData(TEAM_IN_INSTANCE) == TEAM_HORDE)
                    Talk(SAY_AGGRO_H);
                else
                    Talk(SAY_AGGRO_A);

                instance->HandleGameObject(instance->GetGuidData(GO_LORD_GODFREY_DOOR), false);

                events.ScheduleEvent(EVENT_SUMMON_BLOODTHIRSTY_GHOULS, 10000);
                events.ScheduleEvent(EVENT_MORTAL_WOUND, 25000);
                events.ScheduleEvent(EVENT_PISTOL_BARRAGE, 55000);
                events.ScheduleEvent(EVENT_CURSED_BULLETS, 15000);
            }
            else
                EnterEvadeMode();
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            Talk(SAY_DEATH);

            instance->HandleGameObject(instance->GetGuidData(GO_LORD_GODFREY_DOOR), true);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
             Talk(RAND(SAY_KILLER_1, SAY_KILLER_2));
        }

        void JustSummoned(Creature* summon) override
        {
            BossAI::JustSummoned(summon);
        }

        void UpdateAI(uint32 diff) override
        {
            if(!UpdateVictim())
                return;

            events.Update(diff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
               case EVENT_SUMMON_BLOODTHIRSTY_GHOULS:
                    DoCast(SPELL_SUMMON_GHOUL_CHANNELED);
                    events.ScheduleEvent(EVENT_SUMMON_BLOODTHIRSTY_GHOULS, 30000);
                    break;
               case EVENT_MORTAL_WOUND:
                    DoCast(DUNGEON_MODE(SPELL_MORTAL_WOUND,SPELL_MORTAL_WOUND_H));
                    events.ScheduleEvent(EVENT_MORTAL_WOUND, 25000);
                    break;
               case EVENT_PISTOL_BARRAGE:
                    DoCast(SPELL_PISTOL_BARRAGE_TARGETS);
                    DoCastVictim(SPELL_PISTOL_BARRAGE);
                    events.ScheduleEvent(EVENT_PISTOL_BARRAGE, 30000);
                    break;
               case EVENT_CURSED_BULLETS:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), DUNGEON_MODE(SPELL_CURSED_BULLETS,SPELL_CURSED_BULLETS_H), true);
                    events.ScheduleEvent(EVENT_CURSED_BULLETS, 20000);
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
public:
    boss_lord_godfrey() : CreatureScript("boss_lord_godfrey") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_lord_godfreyAI(creature);
    }
};

class spell_pistol_barrage_trigger : public SpellScriptLoader
{
public:
    spell_pistol_barrage_trigger() : SpellScriptLoader("spell_pistol_barrage_trigger") { }

    class spell_pistol_barrage_trigger_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pistol_barrage_trigger_SpellScript);

        void SpawnInAngle(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);
            uint32 entry = uint32(GetSpellInfo()->GetEffect(effIndex)->MiscValue);
            for(uint8 i = 0; i < 6; ++i)
            {
                float angle = -5 * M_PI / 24 + M_PI * i / 12;
                float x, y, z;
                GetCaster()->GetClosePoint(x, y, z, GetCaster()->GetObjectSize(), 30.0f, angle);
                GetCaster()->SummonCreature(entry, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN, 10000);
            }
        }

        void Register() override
        {
            OnEffectLaunch += SpellEffectFn(spell_pistol_barrage_trigger_SpellScript::SpawnInAngle, EFFECT_0, SPELL_EFFECT_SUMMON);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_pistol_barrage_trigger_SpellScript();
    }
};


class spell_pistol_barrage : public SpellScriptLoader
{
public:
    spell_pistol_barrage() : SpellScriptLoader("spell_pistol_barrage") { }

    class spell_pistol_barrage_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pistol_barrage_AuraScript);

        bool Validate(SpellInfo const* /*spell*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PISTOL_BARRAGE))
                return false;
            return true;
        }

        void OnPeriodic(AuraEffect const* /*aurEff*/)
        {
            if (Unit* caster = GetCaster())
                caster->CastSpell((Unit*)NULL, SPELL_PISTOL_BARRAGE_DAMAGE, true);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_pistol_barrage_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_pistol_barrage_AuraScript();
    }
};

class spell_godfrey_summon_ghouls : public SpellScriptLoader
{
public:
    spell_godfrey_summon_ghouls() : SpellScriptLoader("spell_godfrey_summon_ghouls") { }

    class spell_godfrey_summon_ghouls_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_godfrey_summon_ghouls_AuraScript);

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            GetCaster()->CastSpell(GetCaster(), RAND(SPELL_SUMMON_GHOUL_1, SPELL_SUMMON_GHOUL_2), true);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_godfrey_summon_ghouls_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_godfrey_summon_ghouls_AuraScript();
    }
};

void AddSC_boss_lord_godfrey()
{
    new boss_lord_godfrey();
    new spell_pistol_barrage_trigger();
    new spell_pistol_barrage();
    new spell_godfrey_summon_ghouls();
}

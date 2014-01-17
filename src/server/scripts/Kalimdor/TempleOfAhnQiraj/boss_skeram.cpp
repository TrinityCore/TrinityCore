/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "temple_of_ahnqiraj.h"

enum Yells
{
    SAY_AGGRO                   = 0,
    SAY_SLAY                    = 1,
    SAY_SPLIT                   = 2,
    SAY_DEATH                   = 3
};

enum Spells
{
    SPELL_ARCANE_EXPLOSION      = 26192,
    SPELL_EARTH_SHOCK           = 26194,
    SPELL_TRUE_FULFILLMENT      = 785,
    SPELL_INITIALIZE_IMAGE      = 3730,
    SPELL_SUMMON_IMAGES         = 747
};

enum Events
{
    EVENT_ARCANE_EXPLOSION      = 1,
    EVENT_FULLFILMENT           = 2,
    EVENT_BLINK                 = 3,
    EVENT_EARTH_SHOCK           = 4
};

uint32 const BlinkSpells[3] = { 4801, 8195, 20449 };

class boss_skeram : public CreatureScript
{
    public:
        boss_skeram() : CreatureScript("boss_skeram") { }

        struct boss_skeramAI : public BossAI
        {
            boss_skeramAI(Creature* creature) : BossAI(creature, DATA_SKERAM) { }

            void Reset() OVERRIDE
            {
                _flag = 0;
                _hpct = 75.0f;
                me->SetVisible(true);
            }

            void KilledUnit(Unit* /*victim*/) OVERRIDE
            {
                Talk(SAY_SLAY);
            }

            void EnterEvadeMode() OVERRIDE
            {
                ScriptedAI::EnterEvadeMode();
                if (me->IsSummon())
                    ((TempSummon*)me)->UnSummon();
            }

            void JustSummoned(Creature* creature) OVERRIDE
            {
                // Shift the boss and images (Get it? *Shift*?)
                uint8 rand = 0;
                if (_flag != 0)
                {
                    while (_flag & (1 << rand))
                        rand = urand(0, 2);
                    DoCast(me, BlinkSpells[rand]);
                    _flag |= (1 << rand);
                    _flag |= (1 << 7);
                }

                while (_flag & (1 << rand))
                    rand = urand(0, 2);
                creature->CastSpell(creature, BlinkSpells[rand]);
                _flag |= (1 << rand);

                if (_flag & (1 << 7))
                    _flag = 0;

                if (Unit* Target = SelectTarget(SELECT_TARGET_RANDOM))
                    creature->AI()->AttackStart(Target);

                float ImageHealthPct;

                if (me->GetHealthPct() < 25.0f)
                    ImageHealthPct = 0.50f;
                else if (me->GetHealthPct() < 50.0f)
                    ImageHealthPct = 0.20f;
                else
                    ImageHealthPct = 0.10f;

                creature->SetMaxHealth(me->GetMaxHealth() * ImageHealthPct);
                creature->SetHealth(creature->GetMaxHealth() * (me->GetHealthPct() / 100.0f));
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                if (!me->IsSummon())
                    Talk(SAY_DEATH);
                else
                    me->RemoveCorpse();
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                _EnterCombat();
                events.Reset();

                events.ScheduleEvent(EVENT_ARCANE_EXPLOSION, urand(6000, 12000));
                events.ScheduleEvent(EVENT_FULLFILMENT, 15000);
                events.ScheduleEvent(EVENT_BLINK, urand(30000, 45000));
                events.ScheduleEvent(EVENT_EARTH_SHOCK, 2000);

                Talk(SAY_AGGRO);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ARCANE_EXPLOSION:
                            DoCastAOE(SPELL_ARCANE_EXPLOSION, true);
                            events.ScheduleEvent(EVENT_ARCANE_EXPLOSION, urand(8000, 18000));
                            break;
                        case EVENT_FULLFILMENT:
                            /// @todo For some weird reason boss does not cast this
                            // Spell actually works, tested in duel
                            DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true), SPELL_TRUE_FULFILLMENT, true);
                            events.ScheduleEvent(EVENT_FULLFILMENT, urand(20000, 30000));
                            break;
                        case EVENT_BLINK:
                            DoCast(me, BlinkSpells[urand(0, 2)]);
                            DoResetThreat();
                            me->SetVisible(true);
                            events.ScheduleEvent(EVENT_BLINK, urand(10000, 30000));
                            break;
                        case EVENT_EARTH_SHOCK:
                            DoCastVictim(SPELL_EARTH_SHOCK);
                            events.ScheduleEvent(EVENT_EARTH_SHOCK, 2000);
                            break;
                    }
                }

                if (!me->IsSummon() && me->GetHealthPct() < _hpct)
                {
                    DoCast(me, SPELL_SUMMON_IMAGES);
                    Talk(SAY_SPLIT);
                    _hpct -= 25.0f;
                    me->SetVisible(false);
                    events.RescheduleEvent(EVENT_BLINK, 2000);
                }

                if (me->IsWithinMeleeRange(me->GetVictim()))
                {
                    events.RescheduleEvent(EVENT_EARTH_SHOCK, 2000);
                    DoMeleeAttackIfReady();
                }
            }

        private:
            float _hpct;
            uint8 _flag;
        };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_skeramAI(creature);
    }
};

class PlayerOrPetCheck
{
    public:
        bool operator()(WorldObject* object) const
        {
            if (object->GetTypeId() != TYPEID_PLAYER)
                if (!object->ToCreature()->IsPet())
                    return true;

            return false;
        }
};

class spell_skeram_arcane_explosion : public SpellScriptLoader
{
    public:
        spell_skeram_arcane_explosion() : SpellScriptLoader("spell_skeram_arcane_explosion") { }

        class spell_skeram_arcane_explosion_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_skeram_arcane_explosion_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(PlayerOrPetCheck());
            }

            void Register() OVERRIDE
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_skeram_arcane_explosion_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_skeram_arcane_explosion_SpellScript();
        }
};

void AddSC_boss_skeram()
{
    new boss_skeram();
    new spell_skeram_arcane_explosion();
}

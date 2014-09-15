/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "Player.h"

enum Say
{
    SAY_TELEPORT             = 0
};

enum Spells
{
    SPELL_MARK_OF_FROST      = 23182,
    SPELL_AURA_OF_FROST      = 23186,
    SPELL_MARK_OF_FROST_AURA = 23184,
    SPELL_MANA_STORM         = 21097,
    SPELL_CHILL              = 21098,
    SPELL_FROST_BREATH       = 21099,
    SPELL_REFLECT            = 22067,
    SPELL_CLEAVE             = 8255,     // Perhaps not right ID
    SPELL_ENRAGE             = 23537
};

enum Events
{
    EVENT_MARK_OF_FROST      = 1,
    EVENT_MANA_STORM,
    EVENT_CHILL,
    EVENT_BREATH,
    EVENT_TELEPORT,
    EVENT_REFLECT,
    EVENT_CLEAVE,
    EVENT_ENRAGE
};

class boss_azuregos : public CreatureScript
{
    public:
        boss_azuregos() : CreatureScript("boss_azuregos") { }

        struct boss_azuregosAI : public WorldBossAI
        {
            boss_azuregosAI(Creature* creature) : WorldBossAI(creature)
            {
                _enraged = false;
            }

            void Reset() override
            {
                _Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                DoCast(me, SPELL_MARK_OF_FROST_AURA, true);
                _enraged = false;

                events.ScheduleEvent(EVENT_MARK_OF_FROST, 35000);
                events.ScheduleEvent(EVENT_MANA_STORM, urand(5000, 17000));
                events.ScheduleEvent(EVENT_CHILL, urand(10000, 30000));
                events.ScheduleEvent(EVENT_BREATH, urand(2000, 8000));
                events.ScheduleEvent(EVENT_TELEPORT, 30000);
                events.ScheduleEvent(EVENT_REFLECT, urand(15000, 30000));
                events.ScheduleEvent(EVENT_CLEAVE, 7000);
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    who->CastSpell(who, SPELL_MARK_OF_FROST, true);
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
                        case EVENT_MANA_STORM:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                                DoCast(target, SPELL_MANA_STORM);
                            events.ScheduleEvent(EVENT_MANA_STORM, urand(7500, 12500));
                            break;
                        case EVENT_CHILL:
                            DoCastVictim(SPELL_CHILL);
                            events.ScheduleEvent(EVENT_CHILL, urand(13000, 25000));
                            break;
                        case EVENT_BREATH:
                            DoCastVictim(SPELL_FROST_BREATH);
                            events.ScheduleEvent(EVENT_BREATH, urand(10000, 15000));
                            break;
                        case EVENT_TELEPORT:
                        {
                            Talk(SAY_TELEPORT);
                            ThreatContainer::StorageType const& threatlist = me->getThreatManager().getThreatList();
                            for (ThreatContainer::StorageType::const_iterator i = threatlist.begin(); i != threatlist.end(); ++i)
                            {
                                if (Player* player = ObjectAccessor::GetPlayer(*me, (*i)->getUnitGuid()))
                                    DoTeleportPlayer(player, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()+3, player->GetOrientation());
                            }

                            DoResetThreat();
                            events.ScheduleEvent(EVENT_TELEPORT, 30000);
                            break;
                        }
                        case EVENT_REFLECT:
                            DoCast(me, SPELL_REFLECT);
                            events.ScheduleEvent(EVENT_REFLECT, urand(20000, 35000));
                            break;
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE);
                            events.ScheduleEvent(EVENT_CLEAVE, 7000);
                            break;
                        default:
                            break;
                    }
                }

                if (HealthBelowPct(26) && !_enraged)
                {
                    DoCast(me, SPELL_ENRAGE);
                    _enraged = true;
                }

                DoMeleeAttackIfReady();
            }

        private:
            bool _enraged;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_azuregosAI(creature);
        }
};

class MarkOfFrostTargetSelector
{
    public:
        MarkOfFrostTargetSelector() { }

        bool operator()(WorldObject* object) const
        {
            if (Unit* unit = object->ToUnit())
                return !(unit->HasAura(SPELL_MARK_OF_FROST) && !unit->HasAura(SPELL_AURA_OF_FROST));
            return true;
        }
};

class spell_mark_of_frost : public SpellScriptLoader
{
    public:
        spell_mark_of_frost() : SpellScriptLoader("spell_mark_of_frost") { }

        class spell_mark_of_frost_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mark_of_frost_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MARK_OF_FROST))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_AURA_OF_FROST))
                    return false;
                return true;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(MarkOfFrostTargetSelector());
            }

            void HandleEffect(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_AURA_OF_FROST, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mark_of_frost_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_mark_of_frost_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_mark_of_frost_SpellScript();
        }
};

void AddSC_boss_azuregos()
{
    new boss_azuregos();
    new spell_mark_of_frost();
}

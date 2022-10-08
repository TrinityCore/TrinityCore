/*
* Copyright (C) 2021 BfaCore Reforged
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
#include "AreaTriggerAI.h"

enum eSpells
{
    SPELL_FEL_GEYZER = 218823, // 22 sec + filter + script to geyzer (197376) + npc 109946 ?  197217
    SPELL_IMPISH_FLAMES = 218888, // 22 sec after spell above
    SPELL_GASEOUS_BREATH = 219255, // 31 sec + at + adds
    SPELL_MOTHERS_EMBRACE = 219045, // 65 sec + script for charm
    SPELL_REMOVE_CHARM = 227351, // reset or dead
};

// 109943
class boss_ana_muz : public CreatureScript
{
public:
    boss_ana_muz() : CreatureScript("boss_ana_muz") {}

    struct boss_ana_muzAI : public ScriptedAI
    {
        boss_ana_muzAI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            me->HasUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
        }

        EventMap events;
        SummonList summons;

        void Reset() override
        {
            events.Reset();
            //me->RemoveAllAreaObjects();
            summons.DespawnAll();
            DoCast(SPELL_REMOVE_CHARM);
        }

        void EnterCombat(Unit* unit) 
        {
            events.RescheduleEvent(1, 4000); // SPELL_FEL_GEYZER
            events.RescheduleEvent(3, 7000); // SPELL_GASEOUS_BREATH
            events.RescheduleEvent(4, 31000); // SPELL_MOTHERS_EMBRACE
        }

        void JustDied(Unit* who) override
        {
            summons.DespawnAll();
            DoCast(SPELL_REMOVE_CHARM);
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
        }


        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    DoCast(SPELL_FEL_GEYZER);
                    events.RescheduleEvent(1, 22000);
                    events.RescheduleEvent(2, 3000);
                    break;
                case 2:
                    DoCast(SPELL_IMPISH_FLAMES);
                    break;
                case 3:
                    DoCast(SPELL_GASEOUS_BREATH);
                    events.RescheduleEvent(3, 31000);
                    break;
                case 4:
                    DoCast(SPELL_MOTHERS_EMBRACE);
                    events.RescheduleEvent(4, 65000);
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_ana_muzAI(creature);
    }
};

// 219045
class spell_mothers_embrace : public SpellScriptLoader
{
public:
    spell_mothers_embrace() : SpellScriptLoader("spell_mothers_embrace") {}

    class spell_mothers_embrace_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_mothers_embrace_AuraScript);

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
           // if (!GetCaster() || !GetTarget() || GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL)
                return;
            if (GetCaster()->IsAlive() && GetTarget()->IsAlive())
                GetCaster()->CastSpell(GetTarget(), 219068, true);
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_mothers_embrace_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_mothers_embrace_AuraScript();
    }
};

void AddSC_boss_ana_mouz()
{
    new boss_ana_muz();
    new spell_mothers_embrace();
}

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
#include "ScriptedCreature.h"
#include "Player.h"
#include "ObjectMgr.h"
#include "ObjectAccessor.h"
#include "SpellInfo.h"
#include "AreaTriggerAI.h"

enum eSpells
{
    SPELL_MORE_MORE_MORE = 223715,
    // General
    SPELL_NIGHTSHIFTED_BOLTS = 223623,
    SPELL_RESONANCE = 223614,
    SPELL_NIGHTSTABLE_ENERGY = 223689,
};

class boss_withered_jim : public CreatureScript
{
public:
    boss_withered_jim() : CreatureScript("boss_withered_jim") {}

    struct boss_withered_jimAI : public ScriptedAI
    {
        boss_withered_jimAI(Creature* creature) : ScriptedAI(creature), summons(me), countclons(0)
        {
        }

        EventMap events;
        SummonList summons;
        uint8 countclons;

        void Reset() override
        {
            events.Reset();
           // me->RemoveAllAreaObjects();
            summons.DespawnAll();
            countclons = 0;
        }

        void EnterCombat(Unit* unit) 
        {
            events.RescheduleEvent(1, 18000);
            events.RescheduleEvent(2, 24000);
            events.RescheduleEvent(3, 22000);
            if (me->GetEntry() == 102075)
                events.RescheduleEvent(4, 30000);
            DoCast(223632); // AT
            DoCast(223599);
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
            DoZoneInCombat(me, 150.0f);
            if (summon->GetEntry() == 112350)
                summon->CastSpell(summon, 223599);
            if (summon->GetEntry() == 112342)
                summon->DespawnOrUnsummon(9000);
        }

        void JustDied(Unit* who) override
        {
            summons.DespawnAll();
        }

        void DamageTaken(Unit* /*attacker*/ attacker,  uint32& /*damage*/) override
        
        {
            if (attacker->GetTypeId() != TYPEID_PLAYER)
                return;

            if (attacker->GetPositionZ() >= 60.0f)
                me->Kill(attacker); //cheaters and others
        }


        void UpdateAI(uint32 diff) override
        {
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1:
                    DoCast(SPELL_NIGHTSHIFTED_BOLTS);
                    events.RescheduleEvent(1, urand(25000, 30000));
                    break;
                case 2:
                    DoCast(SPELL_RESONANCE);
                    events.RescheduleEvent(1, urand(24000, 30000));
                    break;
                case 3:
                    DoCast(SPELL_NIGHTSTABLE_ENERGY);
                    events.RescheduleEvent(1, urand(29000, 34000));
                    break;
                case 4:
                    ++countclons;
                    DoCast(SPELL_MORE_MORE_MORE);
                    if (countclons < 5)
                        events.RescheduleEvent(4, 30000);
                    events.RescheduleEvent(5, 1000);
                    break;
                case 5:
                    if (me->HasAura(SPELL_MORE_MORE_MORE))
                        events.RescheduleEvent(5, 1000);
                    else
                    {
                        if (auto add = me->SummonCreature(112350, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation()))
                            add->CastSpell(add, 223723);
                    }
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_withered_jimAI(creature);
    }
};

// 223614
class spell_resonance : public SpellScriptLoader
{
public:
    spell_resonance() : SpellScriptLoader("spell_resonance") {}

    class spell_resonance_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_resonance_AuraScript);

        void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();

            Unit* target = GetTarget();
            if (!target)
                return;
            target->CastSpell(target, 223616);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_resonance_AuraScript::OnProc, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_resonance_AuraScript();
    }
};

void AddSC_boss_withered_jim()
{
    new boss_withered_jim();
    new spell_resonance();
}

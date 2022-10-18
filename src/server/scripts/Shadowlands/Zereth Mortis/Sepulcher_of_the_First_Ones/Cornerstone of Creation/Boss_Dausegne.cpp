/*
 * Copyright 2021 FuzionCore Project
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

/* Script Data Start
SDName: 
SDAuthor: Frozen
SD%Complete: %
SDComment: still working on structure.
Script Data End */

enum Spells
{
    Spell_Collapsed_Barrier = 362432,
    Spell_Total_Dominion = 365418,
    Spell_Obliteration_Arc = 361513,
    Spell_Disintegration_Halo = 361751,
    Spell_Infused_Strikes = 361966,
    Spell_Inevitable_Dominion = 361722,
    Spell_Unleashed_Infusion = 361967,
    Spell_Encroaching_Dominion = 361214,
    Spell_Domination_Bolt = 363607,
    Spell_Siphoned_Barrier = 361651,
    Spell_Siphon_Reservoir = 361643,
    Spell_Staggering_Barrage = 360959,
};

enum Creatures
{
    Dausegne = 181224,
    Domination_Core = 181244,

};

struct Dausegne
{
    Dausegne(Creature* Creature) : BossAI(Creature, DATA_DAUSEGNE) { }

    void Reset() override
    {
        BossAI::Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        events.ScheduleEvent(Spell_Encroaching_Dominion, 0s);
        events.ScheduleEvent(Spell_Disintegration_Halo, 5s);
        events.ScheduleEvent(Spell_Total_Dominion, 5s);
        events.ScheduleEvent(Spell_Inevitable_Dominion, 0s);
        events.ScheduleEvent(Spell_Siphon_Reservoir, 3s);
        events.ScheduleEvent(Spell_Siphoned_Barrier, 30s);
        events.ScheduleEvent(Spell_Collapsed_Barrier, 10s);    
    };

    void OnSpellFinished(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
        case Spell_Encroaching_Dominion:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spell_Encroaching_Dominion, true);
            }
            break;
        case Spell_Disintegration_Halo:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spell_Disintegration_Halo, true);
            }
            break;
        case Spell_Total_Dominion:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spell_Total_Dominion, true);
            }
            break;
        case Spell_Inevitable_Dominion:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spell_Inevitable_Dominion, true);
            }
            break;
        case Spell_Siphon_Reservoir:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spell_Siphon_Reservoir, true);
            }
            break;
        case Spell_Siphoned_Barrier:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spell_Siphoned_Barrier, true);
            }
            break;
        case Spell_Collapsed_Barrier:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spell_Collapsed_Barrier, true);
            }
            break;                   
        }

struct Domination_Core
{
    Domination_Core(Creature* Creature) : BossAI(Creature, DATA_DOMINATION_CORE) { }

        void Reset() override
        {
           BossAI::Reset();
        }
    
        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            events.ScheduleEvent(Spell_Encroaching_Dominion, 0s);
            events.ScheduleEvent(Spell_Inevitable_Dominion, 0s);
            events.ScheduleEvent(Spell_Obliteration_Arc, 3s);
            events.ScheduleEvent(Spell_Infused_Strikes, 20s);
            events.ScheduleEvent(Spell_Unleashed_Infusion, 0s);
            events.ScheduleEvent(Spell_Domination_Bolt, 1.5s);
            events.ScheduleEvent(Spell_Staggering_Barrage, 0s);
        };

    void OnSpellFinished(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
        case Spell_Encroaching_Dominion:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spell_Encroaching_Dominion, true);
            }
            break;
        case Spell_Inevitable_Dominion:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spell_Inevitable_Dominion, true);
            }
            break;
        case Spell_Obliteration_Arc:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spell_Obliteration_Arc, true);
            }
            break;
        case Spell_Infused_Strikes:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spell_Infused_Strikes, true);
            }
            break;
        case Spell_Unleashed_Infusion:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spell_Unleashed_Infusion, true);
            }
            break;
        case Spell_Domination_Bolt:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spell_Domination_Bolt, true);
            }
            break;
        case Spell_Staggering_Barrage:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spell_Staggering_Barrage, true);
            }
            break;
        };                            
    };
};


void AddSC_Boss_Dausegne()
{
    RegisterCreatureAI(Dausegne);
    RegisterCreatureAI(Domination_Core)
    RegisterSpellScript(spell_explosive_contrivance);
    RegisterSpellScript(Spell_Collapsed_Barrier);
    RegisterSpellScript(Spell_Total_Dominion);
    RegisterSpellScript(Spell_Obliteration_Arc);
    RegisterSpellScript(Spell_Disintegration_Halo);
    RegisterSpellScript(Spell_Infused_Strikes);
    RegisterSpellScript(Spell_Inevitable_Dominion);
    RegisterSpellScript(Spell_Unleashed_Infusion);
    RegisterSpellScript(Spell_Encroaching_Dominion);
    RegisterSpellScript(Spell_Domination_Bolt);
    RegisterSpellScript(Spell_Siphoned_Barrier);
    RegisterSpellScript(Spell_Siphon_Reservoir);
    RegisterSpellScript(Spell_Staggering_Barrage);
}

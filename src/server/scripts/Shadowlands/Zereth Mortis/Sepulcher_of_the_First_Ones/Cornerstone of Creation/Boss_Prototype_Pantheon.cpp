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
    Spells_Berserk = 302547,
    Spells_Gloom_Bolt = 360259,
    Spells_Gloom_Bolt2 = 364240,
    Spells_Necrotic_Ritual = 360295,
    Spells_Reconstruction = 361300,
    Spells_Reconstruction2 = 361938,
    Spells_Shattered_Psyche = 344663,
    Spells_Runecarvers_Deathtouch = 360687,
    Spells_Necrosis = 360618,
    Spells_Bastions_Ward = 361067,
    Spells_Humbling_Strikes = 365272,
    Spells_Pinning_Volley = 361278,
    Spells_Windswept_Wings = 365041,
    Spells_Ascensions_Call = 361066,
    Spells_Anima_Bolt = 362383,
    Spells_Wild_Stampede = 361305,
    Spells_Animastorm = 366234,
    Spells_Withering_Seeds = 361568,
    Spells_Withering_Nova = 361579,
    Spells_Invigorating_Bloom = 365306,
    Spells_Burden_of_Sin = 361608,
    Spells_Hand_of_Destruction = 361788,
    Spells_Sinful_Projection = 364865,
    Spells_Wracking_Pain = 361689,
    Spells_Complete_Reconstruction = 366062,
};

enum Creatures
{
    Prototype_of_War = 181549,
    Prototype_of_Renewal = 181546,
    Prototype_of_Duty = 181551,
    Prototype_of_Absolution = 181548,
};

struct Prototype_of_War
{
    Prototype_of_War(Creature* Creature) : BossAI(Creature, DATA_PROTOTYPE_OF_WAR) { }

    void Reset() override
    {
        BossAI::Reset();
    };

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        events.ScheduleEvent(Spells_Gloom_Bolt, 16s);
        events.ScheduleEvent(Spells_Necrotic_Ritual, 3s);
        events.ScheduleEvent(Spells_Necrosis, 0s);
        events.ScheduleEvent(Spells_Runecarvers_Deathtouch, 30s);
        events.ScheduleEvent(Spells_Bastions_Ward, 6s);   
    };

    void OnSpellFinished(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
        case Spells_Gloom_Bolt:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spells_Gloom_Bolt, true);
            }
            break;
        case Spells_Necrotic_Ritual:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), SSpells_Necrotic_Ritual, true);
            }
            break;
        case Spells_Necrosis:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spells_Necrosis, true);
            }
            break;
        case Spells_Runecarvers_Deathtouch:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spells_Runecarvers_Deathtouch, true);
            }
            break;
        case Spells_Bastions_Ward:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spells_Bastions_Ward, true);
            }
            break;                   
        }
   }
};








struct Prototype_of_Duty
{
    Prototype_of_Duty(Creature* Creature) : BossAI(Creature, DATA_PROTOTYPE_OF_DUTY) { }

    void Reset() override
    {
        BossAI::Reset();
    };

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        events.ScheduleEvent(Spells_Humbling_Strikes, 10s);
        events.ScheduleEvent(Spells_Pinning_Volley, 10s);
        events.ScheduleEvent(Spells_Windswept_Wings, 0s);
        events.ScheduleEvent(Spells_Ascensions_Call, 0s);
        events.ScheduleEvent(Spells_Bastions_Ward, 6s);
        events.ScheduleEvent(Spells_Runecarvers_Deathtouch, 30s);   
    };

    void OnSpellFinished(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
        case Spells_Humbling_Strikes:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spells_Humbling_Strikes, true);
            }
            break;
        case Spells_Pinning_Volley:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spells_Pinning_Volley, true);
            }
            break;
        case Spells_Windswept_Wings:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spells_Windswept_Wings, true);
            }
            break;
        case Spells_Ascensions_Call:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spells_Ascensions_Call, true);
            }
            break;
        case Spells_Bastions_Ward:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spells_Bastions_Ward, true);
            }
            break;
        case Spells_Runecarvers_Deathtouch:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spells_Runecarvers_Deathtouch, true);
            }
            break;                       
        }
   }
};






struct Prototype_of_Renewal
{
    Prototype_of_Renewal(Creature* Creature) : BossAI(Creature, DATA_PROTOTYPE_OF_RENEWAL) { }

    void Reset() override
    {
        BossAI::Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        events.ScheduleEvent(Spells_Anima_Bolt, 16s);
        events.ScheduleEvent(Spells_Wild_Stampede, 0s);
        events.ScheduleEvent(Spells_Animastorm, 32s);
        events.ScheduleEvent(Spells_Withering_Seeds, 0s);
        events.ScheduleEvent(Spells_Withering_Nova, 16s);
        events.ScheduleEvent(Spells_Invigorating_Bloom, 30s);    
    };

    void OnSpellFinished(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
        case Spells_Anima_Bolt:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spells_Anima_Bolt, true);
            }
            break;
        case Spells_Wild_Stampede:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spells_Wild_Stampede, true);
            }
            break;
        case Spells_Animastorm:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spells_Animastorm, true);
            }
            break;
        case Spells_Withering_Seeds:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spells_Withering_Seeds, true);
            }
            break;
        case Spells_Withering_Nova:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spells_Withering_Nova, true);
            }
            break;
        case Spells_Invigorating_Bloom:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spells_Invigorating_Bloom, true);
            }
            break;                           
        };
   };
};





struct Prototype_of_Absolution
{
    Prototype_of_Absolution(Creature* Creature) : BossAI(Creature, DATA_PROTOTYPE_OF_ABSORTION) { }

    void Reset() override
    {
        BossAI::Reset();
    };

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        events.ScheduleEvent(Spells_Burden_of_Sin, 0s);  
        events.ScheduleEvent(Spells_Hand_of_Destruction, 0s);
        events.ScheduleEvent(Spells_Sinful_Projection, 0s);
        events.ScheduleEvent(Spells_Wracking_Pain, 40s);
        events.ScheduleEvent(Spells_Complete_Reconstruction, 0s);   
    };

    void OnSpellFinished(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
        case Spells_Burden_of_Sin:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spells_Burden_of_Sin, true);
            }
            break;
        case Spells_Hand_of_Destruction:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spells_Hand_of_Destruction, true);
            }
            break;
        case Spells_Sinful_Projection:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spells_Sinful_Projection, true);
            }
            break;
        case Spells_Wracking_Pain:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spells_Wracking_Pain, true);
            }
            break;
        case Spells_Complete_Reconstruction:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, /*100.0f*/);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), Spells_Complete_Reconstruction, true);
            }
            break;                   
        }
   }
};

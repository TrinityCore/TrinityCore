/*
* Copyright 2023 FuzionCore
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
#include "Player.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "SpellAuraEffects.h"
#include "halls_of_attonement.h"

enum Spells
{
    //High_Adjudicator_Aleez
	Spell_Bolt_of_Power = 323538,
	Spell_Volley_of_Power = 323552,
	Spell_Spectral_Procession = 323597,
    SPELL_Anima_Fountain = 329340,
    Spell_Vessel_of_Atonement = 165410,
    //
    // Ghastly Parishioner
	Spell_Haunting_Fixation = 323650,
	Spell_Ephemeral_Visage = 323741,
	Spell_Pulse_from_Beyond = 323852,
	
};

enum Creatures
{
	High_Adjudicator_Aleez = 165408,
    Ghastly_Parishioner = 165913,
};

enum Loot
{
	Breastplate of Otherworldly Influence = 178814,
	Gloves of Haunting Fixation = 178832,
};

struct High_Adjudicator_Aleez : public BossAI
{

    boss_High_Adjudicator_Aleez(Creature* c) : BossAI(c, DATA_BOSS_HIGH_ADJUDICATOR_ALEEZ) { }

    void Reset() override
    {
        BossAI::Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();


    }

    void OnSpellFinished(SpellInfo const* spellInfo) override
  
    {
        switch (spellInfo->Id)
        {
        case SPELL_BOLT_OF_POWER:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, 100.0f);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), SPELL_BOLT_OF_POWER, true);
            }
            break;
        }
    
        case SPELL_VOLLEY_OF_POWER:
        {
            std::list<AreaTrigger*> atList;
            me->GetAreaTriggerListWithSpellIDInRange(atList, SPELL_VOLLEY_OF_POWER, 100.0f);
            for (AreaTrigger* at : atList)
            {
                if (at->GetPositionZ() < -45.0f)
                {
                    at->GetCaster()->CastSpell(at->GetPosition(), SPELL_VOLLEY_OF_POWER, true);
                    at->Remove();
                }
            }
            break;

        case SPELL_Spectral_Procession:
        {
            std::list<AreaTrigger*> atList;
            me->GetAreaTriggerListWithSpellIDInRange(atList, SPELL_Spectral_Procession, 100.0f);
            for (AreaTrigger* at : atList)
            {
                if (at->GetPositionZ() < -45.0f)
                {
                    at->GetCaster()->CastSpell(at->GetPosition(), SPELL_Spectral_Procession, true);
                    at->Remove();
                }
            }
            break;
        
        case SPELL_Anima_Fountain:
        {
            std::list<AreaTrigger*> atList;
            me->GetAreaTriggerListWithSpellIDInRange(atList, SPELL_Anima_Fountain, 100.0f);
            for (AreaTrigger* at : atList)
            {
                if (at->GetPositionZ() < -45.0f)
                {
                    at->GetCaster()->CastSpell(at->GetPosition(), SPELL_Anima_Fountain, true);
                    at->Remove();
                }
            }
            break;

            case SPELL_Vessel_of_Atonement:
        {
            std::list<AreaTrigger*> atList;
            me->GetAreaTriggerListWithSpellIDInRange(atList, SPELL_Vessel_of_Atonement, 100.0f);
            for (AreaTrigger* at : atList)
            {
                if (at->GetPositionZ() < -45.0f)
                {
                    at->GetCaster()->CastSpell(at->GetPosition(), SPELL_Vessel_of_Atonement, true);
                    at->Remove();
                }
            }
            break;                 
        }    
    };

    void ExecuteEvent(uint32 eventId) override

        events.ScheduleEvent(SPELL_GLASS_SHARDS, 0s);
        events.ScheduleEvent(SPELL_REFRACTED_SINLIGHT 30s);
        events.ScheduleEvent(SPELL_CRUMBLING_SLAM, 1.5s);
        events.ScheduleEvent(SPELL_HEAVE_DEBRIS, 0s);
        events.ScheduleEvent(SPELL_SINLIGHT_VISIONS, 3s);
        events.ScheduleEvent(SPELL_LIGHT_OF_ATONEMENT, 8s);



        switch (eventId)
        {
        case SPELL_GLASS_SHARDS:
            me->CastSpell(nullptr, SPELL_GLASS_SHARDS, true);
            events.Repeat(20s, 25s); 
            break;
        
        case SPELL_REFRACTED_SINLIGHT:
            me->CastSpell(nullptr, SPELL_REFRACTED_SINLIGHT, true);
            events.Repeat(20s, 25s); 
            break;

        case SPELL_CRUMBLING_SLAM:
            me->CastSpell(nullptr, SPELL_CRUMBLING_SLAM, true);
            events.Repeat(20s, 25s); 
            break;
            
        case SPELL_HEAVE_DEBRIS:
            me->CastSpell(nullptr, SPELL_HEAVE_DEBRIS, true);
            events.Repeat(20s, 25s); 
            break;
            
        case SPELL_SINLIGHT_VISIONS:
            me->CastSpell(nullptr, SPELL_SINLIGHT_VISIONS, true);
            events.Repeat(20s, 25s); 
            break;
            
        case SPELL_LIGHT_OF_ATONEMENT:
            me->CastSpell(nullptr, SPELL_LIGHT_OF_ATONEMENT, true);
            events.Repeat(20s, 25s); 
            break;
        };
    };
};    

/*
struct Ghastly_Parishioner : public CreatureAI
{

    Ghastly_Parishioner(Creature* c) : CreatureAI(c, DATA_Ghastly_Parishioner) { }

    void Reset() override
    {
        BossAI::Reset();
    }

    void EnterCombat(Unit* /*who*///) override
    //{
      //  _EnterCombat();


    //};
/*
    void OnSpellFinished(SpellInfo const* spellInfo) override

    {
        switch (spellInfo->Id)
        {
        case Haunting_Fixation:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, 100.0f);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), SPELL_Haunting_Fixation, true);
            }
            break;
        }
    
        case SPELL_Ephemeral_Visage:
        {
            std::list<AreaTrigger*> atList;
            me->GetAreaTriggerListWithSpellIDInRange(atList, SPELL_Ephemeral_Visage, 100.0f);
            for (AreaTrigger* at : atList)
            {
                if (at->GetPositionZ() < -45.0f)
                {
                    at->GetCaster()->CastSpell(at->GetPosition(), SPELL_Ephemeral_Visage, true);
                    at->Remove();
                }
            }
            break;

        case SPELL_Pulse_from_Beyond:
        {
            std::list<AreaTrigger*> atList;
            me->GetAreaTriggerListWithSpellIDInRange(atList, SPELL_Pulse_from_Beyond, 100.0f);
            for (AreaTrigger* at : atList)
            {
                if (at->GetPositionZ() < -45.0f)
                {
                    at->GetCaster()->CastSpell(at->GetPosition(), SPELL_Pulse_from_Beyond, true);
                    at->Remove();
                }
            }
            break;   
        }    
    };

    void ExecuteEvent(uint32 eventId) override

        events.ScheduleEvent(SPELL_Haunting_Fixation, 0s);
        events.ScheduleEvent(SPELL_Ephemeral_Visage 30s);
        events.ScheduleEvent(SPELL_Pulse_from_Beyond, 1.5s);   
    
        switch (eventId)
        {
        case SPELL_Haunting_Fixation:
            me->CastSpell(nullptr, SPELL_Haunting_Fixation, true);
            events.Repeat(20s, 25s); 
            break;
        
        case SPELL_Ephemeral_Visage:
            me->CastSpell(nullptr, SPELL_Ephemeral_Visage, true);
            events.Repeat(20s, 25s); 
            break;

        case SPELL_Pulse_from_Beyond:
            me->CastSpell(nullptr, SPELL_Pulse_from_Beyond, true);
            events.Repeat(20s, 25s); 
            break;
        };
    };
};
*/
    void JustReachedHome() override
    {
        _JustReachedHome();
        me->RemoveAllAreaTriggers();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->RemoveAllAreaTriggers();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*who*/) override
    {
        _JustDied();
        me->RemoveAllAreaTriggers();
    };
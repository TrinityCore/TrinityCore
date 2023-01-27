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
	Spell_Stone_Shattering_Leap = 319592,
	Spell_Stone_Form = 319724,
	Spell_Stone_Call = 319733,
	Spell_Volatile_Transformation = 328125,
	Spell_Villainous_Bolt = 328322,
	Spell_Curse_of_Stone = 319603,
	Spell_Shattered = 344874,
	Spell_Blood_Torrent = 319702,
};

enum Creatures
{
	Undying_Stonefiend = 164363,
	Echelon = 156827,
};

enum Loot
{
	Deeper_Daggers = 183511,
	Demonic_Momentum = 182470,
	Hack_and_Slash = 181735,
	Layered_Mane = 183487,
	Shake_the_Foundations = 182127,
	Stinging_Strike = 183184,
	Pulsating_Stoneheart = 178825,
	Skyterrors_Stonehide_Leggings = 178819,
	Soaring_Decimators_Hauberk = 178815,
	Stonefiend_Shapers_Mitts = 178833,
	Stoneguardians_Morningstar = 178834,
	Wing_Commanders_Helmet = 178812,
	Memory_of_the_Deeptremor_Stone = 183349,
};

struct Echelon : public BossAI
}

    boss_Echelon(Creature* c) : BossAI(c, DATA_BOSS_ECHELON) { }

    void Reset() override
    {
        BossAI::Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        events.ScheduleEvent(SPELL_STONE_SHATTERING_LEAP, 0s);
        events.ScheduleEvent(SPELL_STONE_FORM, 30s);
        events.ScheduleEvent(SPELL_STONE_CAll, 1.5s);
        events.ScheduleEvent(SPELL_VOLATILE_TRANSFORMATION, 0s);
        events.ScheduleEvent(SPELL_VILLAINOUS_BOLT, 3s);
        events.ScheduleEvent(SPELL_CURSE_OF_STONE, 5s);
        events.ScheduleEvent(SPELL_SHATTERED, 8s);
        events.ScheduleEvent(SPELL_BLOOD_TORRENT, 125s);
    }

    void OnSpellFinished(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
        case SPELL_STONE_SHATTERING_LEAP:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, 100.0f);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), SPELL_STONE_SHATTERING_LEAP, true);
            }
            break;
        }
    
        case SPELL_STONE_FORM:
        {
            std::list<AreaTrigger*> atList;
            me->GetAreaTriggerListWithSpellIDInRange(atList, SPELL_STONE_FORM, 100.0f);
            for (AreaTrigger* at : atList)
            {
                if (at->GetPositionZ() < -45.0f)
                {
                    at->GetCaster()->CastSpell(at->GetPosition(), SPELL_STONE_FORM, true);
                    at->Remove();
                }
            }
            break;

        case SPELL_STONE_CAll:
        {
            std::list<AreaTrigger*> atList;
            me->GetAreaTriggerListWithSpellIDInRange(atList, SPELL_STONE_CAll, 100.0f);
            for (AreaTrigger* at : atList)
            {
                if (at->GetPositionZ() < -45.0f)
                {
                    at->GetCaster()->CastSpell(at->GetPosition(), SPELL_STONE_CAll, true);
                    at->Remove();
                }
            }
            break;
        
        case SPELL_VOLATILE_TRANSFORMATION:
        {
            std::list<AreaTrigger*> atList;
            me->GetAreaTriggerListWithSpellIDInRange(atList, SPELL_VOLATILE_TRANSFORMATION, 100.0f);
            for (AreaTrigger* at : atList)
            {
                if (at->GetPositionZ() < -45.0f)
                {
                    at->GetCaster()->CastSpell(at->GetPosition(), SPELL_VOLATILE_TRANSFORMATION, true);
                    at->Remove();
                }
            }
            break;

            case SPELL_VILLAINOUS_BOLT:
        {
            std::list<AreaTrigger*> atList;
            me->GetAreaTriggerListWithSpellIDInRange(atList, SPELL_VILLAINOUS_BOLT, 100.0f);
            for (AreaTrigger* at : atList)
            {
                if (at->GetPositionZ() < -45.0f)
                {
                    at->GetCaster()->CastSpell(at->GetPosition(), SPELL_VILLAINOUS_BOLT, true);
                    at->Remove();
                }
            }
            break;

        case SPELL_CURSE_OF_STONE:
        {
            std::list<AreaTrigger*> atList;
            me->GetAreaTriggerListWithSpellIDInRange(atList, SPELL_CURSE_OF_STONE, 100.0f);
            for (AreaTrigger* at : atList)
            {
                if (at->GetPositionZ() < -45.0f)
                {
                    at->GetCaster()->CastSpell(at->GetPosition(), SPELL_CURSE_OF_STONE, true);
                    at->Remove();
                }
            }
            break;
            
        case SPELL_SHATTERED:
        {
            std::list<AreaTrigger*> atList;
            me->GetAreaTriggerListWithSpellIDInRange(atList, SPELL_SHATTERED, 100.0f);
            for (AreaTrigger* at : atList)
            {
                if (at->GetPositionZ() < -45.0f)
                {
                    at->GetCaster()->CastSpell(at->GetPosition(), SPELL_SHATTERED, true);
                    at->Remove();
                }
            }
            break;
            
        case SPELL_BLOOD_TORRENT:
        {
            std::list<AreaTrigger*> atList;
            me->GetAreaTriggerListWithSpellIDInRange(atList, SPELL_BLOOD_TORRENT, 100.0f);
            for (AreaTrigger* at : atList)
            {
                if (at->GetPositionZ() < -45.0f)
                {
                    at->GetCaster()->CastSpell(at->GetPosition(), SPELL_BLOOD_TORRENT, true);
                    at->Remove();
                }
            }
            break;                   
        }    
    }

    void ExecuteEvent(uint32 eventId) override 

    {
        switch (eventId)
        {
        case SPELL_STONE_SHATTERING_LEAP:
            me->CastSpell(nullptr, SPELL_STONE_SHATTERING_LEAP, true);
            events.Repeat(20s, 25s); 
            break;
        
        case SPELL_STONE_FORM:
            me->CastSpell(nullptr, SPELL_STONE_FORM, true);
            events.Repeat(20s, 25s); 
            break;

        case SPELL_STONE_CAll:
            me->CastSpell(nullptr, SPELL_STONE_CAll, true);
            events.Repeat(20s, 25s); 
            break;
            
        case SPELL_VOLATILE_TRANSFORMATION:
            me->CastSpell(nullptr, SPELL_VOLATILE_TRANSFORMATION, true);
            events.Repeat(20s, 25s); 
            break;
            
        case SPELL_VILLAINOUS_BOLT:
            me->CastSpell(nullptr, SPELL_VILLAINOUS_BOLT, true);
            events.Repeat(20s, 25s); 
            break;
            
        case SPELL_CURSE_OF_STONE:
            me->CastSpell(nullptr, SPELL_CURSE_OF_STONE, true);
            events.Repeat(20s, 25s); 
            break;
            
        case SPELL_SHATTERED:
            me->CastSpell(nullptr, SPELL_SHATTERED, true);
            events.Repeat(20s, 25s); 
            break;
            
        case SPELL_BLOOD_TORRENT:
            me->CastSpell(nullptr, SPELL_BLOOD_TORRENT, true);
            events.Repeat(20s, 25s); 
            break;                        
        
        }
    }

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
    }
};



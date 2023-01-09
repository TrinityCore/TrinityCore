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
	Spell_Glass_Shards = 323001,
	Spell_Refracted_Sinlight = 322913,
	Spell_Crumbling_Slam = 322936,
	Spell_Heave_Debris = 322943,
	Spell_Sinlight_Visions = 322977,
	Spell_Glass_Shards = 323001,
	Spell_Light_of_Atonement = 339235,
};

enum Creatures
{
	Halkias = 165408,
};

enum Loot
{
	Sin_Stained_Pendant = 178827,
	Hood_of_Refracted_Shadows = 178817,
	Sinlight_Shroud = 178813,
	Halkiass_Towering_Pillars = 178818,
	Shardskin_Sabatons = 178830,
	Vengeful_Shock = 182681,
	Memory_of_a_Seismic_Reverberation = 183380,
	Memory_of_the_Crimson_Runes = 182629,
	Accelerated_Cold = 181848,
	Exaltation = 181845,
	Flame_Accretion = 181736,
	Tumbling_Technique = 181640,
	Synvir_Lockbox = 179311,
	Banewood_Dirk = 177806,
	Bubbling_Concoction = 177800,
	Gargoyle_Heartpiercer = 179329,
	Hopebreaker_Carbine = 177802,
	Inquisitor_Cudgel = 179333,
	Lithe_Rapier = 177809,
	Stone_Sentinel_Poleaxe = 179332,
	Stoneborn_Shield = 177799,
	Caged_Cudgel = 179319,
	Depraved_Ritualists_Kris = 183971,
	Dredhollow_Cudgel = 179323,
	Ritualist_Dagger = 177804,
	Stonebreaker_Mace = 177810,
	Wingblade_Staff = 179334,
	Depraved_Darkblades_Grips = 177775,
	Avowed_Tormenters_Leggings = 177771,
	Night_Guardian_Armplates = 177795,
	Redeemers_Mace = 177805,
	Depraved_Darkblades_Belt = 177778,
	Savage_Bonemauler_Bracers = 177787,
	Savage_Bonemauler_Gloves = 177782,
};

struct Halkias : public BossAI
}

    boss_Halkias(Creature* c) : BossAI(c, DATA_BOSS_Halkias) { }

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
        case SPELL_GLASS_SHARDS:
        {
            std::list<Player*> targetList;
            me->GetPlayerListInGrid(targetList, 100.0f);
            for (Player* targets : targetList)
            {
                me->CastSpell(targets->GetPosition(), SPELL_GLASS_SHARDS, true);
            }
            break;
        }
    
        case REFRACTED_SINLIGHT:
        {
            std::list<AreaTrigger*> atList;
            me->GetAreaTriggerListWithSpellIDInRange(atList, SPELL_REFRACTED_SINLIGHT, 100.0f);
            for (AreaTrigger* at : atList)
            {
                if (at->GetPositionZ() < -45.0f)
                {
                    at->GetCaster()->CastSpell(at->GetPosition(), REFRACTED_SINLIGHT, true);
                    at->Remove();
                }
            }
            break;

        case SPELL_CRUMBLING_SLAM:
        {
            std::list<AreaTrigger*> atList;
            me->GetAreaTriggerListWithSpellIDInRange(atList, SPELL_CRUMBLING_SLAM, 100.0f);
            for (AreaTrigger* at : atList)
            {
                if (at->GetPositionZ() < -45.0f)
                {
                    at->GetCaster()->CastSpell(at->GetPosition(), SPELL_CRUMBLING_SLAM, true);
                    at->Remove();
                }
            }
            break;
        
        case SPELL_HEAVE_DEBRIS:
        {
            std::list<AreaTrigger*> atList;
            me->GetAreaTriggerListWithSpellIDInRange(atList, SPELL_HEAVE_DEBRIS, 100.0f);
            for (AreaTrigger* at : atList)
            {
                if (at->GetPositionZ() < -45.0f)
                {
                    at->GetCaster()->CastSpell(at->GetPosition(), SPELL_HEAVE_DEBRIS, true);
                    at->Remove();
                }
            }
            break;

            case SPELL_SINLIGHT_VISIONS:
        {
            std::list<AreaTrigger*> atList;
            me->GetAreaTriggerListWithSpellIDInRange(atList, SPELL_SINLIGHT_VISIONS, 100.0f);
            for (AreaTrigger* at : atList)
            {
                if (at->GetPositionZ() < -45.0f)
                {
                    at->GetCaster()->CastSpell(at->GetPosition(), SPELL_SINLIGHT_VISIONS, true);
                    at->Remove();
                }
            }
            break;

        case SPELL_LIGHT_OF_ATONEMENT:
        {
            std::list<AreaTrigger*> atList;
            me->GetAreaTriggerListWithSpellIDInRange(atList, SPELL_LIGHT_OF_ATONEMENT, 100.0f);
            for (AreaTrigger* at : atList)
            {
                if (at->GetPositionZ() < -45.0f)
                {
                    at->GetCaster()->CastSpell(at->GetPosition(), SPELL_LIGHT_OF_ATONEMENT, true);
                    at->Remove();
                }
            }
            break;                  
        }    
    }

    void ExecuteEvent(uint32 eventId) override

        events.ScheduleEvent(SPELL_GLASS_SHARDS, 0s);
        events.ScheduleEvent(SPELL_REFRACTED_SINLIGHT 30s);
        events.ScheduleEvent(SPELL_CRUMBLING_SLAM, 1.5s);
        events.ScheduleEvent(SPELL_HEAVE_DEBRIS, 0s);
        events.ScheduleEvent(SPELL_SINLIGHT_VISIONS, 3s);
        events.ScheduleEvent(SPELL_LIGHT_OF_ATONEMENT, 8s);


    {
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

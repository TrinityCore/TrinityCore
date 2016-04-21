/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "heart_of_fear.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "ScriptedCreature.h"
#include "Vehicle.h"

// Encounter namespace
namespace GaralonEncounter
{
// Boss Garalon namespace
namespace BossGaralon
{

enum Spells
{
    // Furious Swipe
    SPELL_GARALON_FURIOUS_SWIPE             = 122735, // Need script ObjectAreaTargetSelect (TARGET_UNIT_AREA_PATH)

    // Crush
    /** Some precisions : during a Normal-Run encounter, Garalon casts this spell only when he detects
     *  a player bneath him <=> player inside the purple circle delimiting the Crush AOE. During a
     *  heroic-run, Garalon periodically casts the spell, and still check for players beneath him.
     */
    SPELL_GARALON_CRUSH_GROUND_DELIMITER    = 122082, // Visual purple circle on the ground + periodically trigger SPELL_GARALON_CRUSH_TRIGGER
    SPELL_GARALON_CRUSH_TRIGGER             = 117709, // Need to script the dummy effect (somewhat linked to SPELL_GARALON_CRUSH_AURA_DUMMY)
    SPELL_GARALON_CRUSH_AURA_DUMMY          = 124068, // Dummy aura linked with SPELL_GARALON_CRUSH_TRIGGER
    SPELL_GARALON_CRUSH                     = 122774, // Main damages spell ; maybe the effect dummy acts like some kind of searcher ?
    SPELL_GARALON_CRUSH_DUMMY               = 123848, // A spell with a dummy effect affecting the caster (we will use it like a searcher)

    // Pheromones
    /** Some precisions : there are many many spells here, and they have to be used in a specific
     *  order. Garalon casts the spell only once, two seconds after being engaged ; the boss choses
     *  the closest victim and casts the spell on it. After that, there are many effects. When the
     *  affected player comes close to an ally (5 yards), the affected player sends the aura to this ally ;
     *  it means that the affected target loses the aura, and the ally gets a new one.
     *
     *  Note : in Heroic-run, as Garalon gains the Damaged effect, he ignores the attack me and taunt effects
     */
    SPELL_GARALON_PHEROMONES_BEGIN          = 123808, // Casted by Garalon (2 seconds incantation) ; applies the auras on the players (need SpellScript)
    SPELL_GARALON_PHEROMONES_SWITCH         = 123100, // Casted every 2 second by the player having aura 122835 ; need SpellScript
    SPELL_GARALON_PHEROMONES                = 122835, // Damager and cie

    // Damaged(heroic Only)
    SPELL_GARALON_DAMAGED                   = 123818, // Remove the aura 123109 and changes Garalon's model ; also the boss starts using Melee Attacks

    // Legs system
    SPELL_GARALON_BROKEN_LEG                = 122786, // Damages Garalon + reduce movement speed (TARGET_UNIT_NEARBY_ENTRY)
    SPELL_GARALON_MEND_LEG                  = 123495, // Dummy effect restoring leg + trigger SPELL_GARALON_MEND_LEG_SCRIPT_EFFECT
    SPELL_GARALON_MEND_LEG_SCRIPT_EFFECT    = 123796, // Removes a stack of SPELL_GARALON_BROKEN_LEG
    
    // Weak Point
    SPELL_GARALON_WEAK_POINT_NORTH_WEST        = 123424,
    SPELL_GARALON_WEAK_POINT_SOUTH_WEST        = 123425,
    SPELL_GARALON_WEAK_POINT_NORTH_EAST        = 122757,
    SPELL_GARALON_WEAK_POINT_SOUTH_EAST        = 123427,

    // MIsc
    SPELL_GARALON_FURY                      = 122754, // When SPELL_GARALON_FURIOUS_STRIKE doesn't hit at least two targets
}; // enum Spells

enum Events
{
    EVENT_GARALON_FURIOUS_SWIPE = 1, // Set a random timer for this
    EVENT_GARALON_CRUSH_SEARCHER, // Cast the searcher (if in normal) ; schedule periodic in Heroic
    EVENT_GARALON_CRUSH_PERIODIC,
    EVENT_GARALON_PHEROMONES_FIRST, // First cast if pheromones, after two seconds
    EVENT_GARALON_MEND_LEG, // We will need to use another class to make the events reschedule itself if already scheduled when another leg is broken
    EVENT_GARALON_MEND_LEG_PREPARE, // Since EventProcessor is updated before UpdateAI is called, we need a helper to prevents canceling the EVENT_GARALON_MEND_LEG
}; // enum Events

enum Creatures
{
    MOB_GARALON_GARALONS_LEG = 62164, // There are four of them
}; // enum Creatures

enum Actions
{
    ACTION_GARALON_CRUSH_POSSIBLE = 1, // When SPELL_GARALON_PHEROMONES_DUMMY detects a player ;
    ACTION_GARALON_LEG_DAMAGED,
}; // enum Actions

enum Misc
{
    GARALON_DAMAGED_HEALTH_PERCENT     = 33, // Below this percent, Garalon is "Damaged"
    MAX_WEAK_POINT_SPELLS            = 4, // Max number of "Weak Points" spells
};

const uint32 weakPoints[MAX_WEAK_POINT_SPELLS] = {SPELL_GARALON_WEAK_POINT_NORTH_WEST, 
                                                    SPELL_GARALON_WEAK_POINT_SOUTH_WEST, 
                                                    SPELL_GARALON_WEAK_POINT_NORTH_EAST, 
                                                    SPELL_GARALON_WEAK_POINT_SOUTH_EAST};

} // end namespace BossGaralon

namespace GaralonAdds
{
enum Spells
{
    SPELL_PHEROMONE_TRAIL = 123106, // Periodically trigger 123120
};
} // end namespace GaralonAdds

/** Class used to set a delay before rescheduling an event
 */
class DelayedEventRescheduler : public BasicEvent
{
public:
    DelayedEventRescheduler(EventMap& source, uint32 eventId, uint32 rescheduleTimer):
        _source(&source), _eventId(eventId), _rescheduleTimer(rescheduleTimer)
    {

    }

    bool Execute(uint64 totalTime, uint32 updateTime)
    {
        if(!_source)
            return true;

        _source->ScheduleEvent(_eventId, _rescheduleTimer);
    }

private:
    EventMap* _source;
    uint32 _eventId;
    uint32 _rescheduleTimer;
};

typedef std::list<Creature*> CreatureList;
typedef CreatureList::iterator CreatureListIter;
typedef CreatureList::const_iterator CreatureListConstIter;

} // end namespace GaralonEncounter


using namespace GaralonEncounter;
using namespace GaralonEncounter::BossGaralon;

/** Class for the Garalon Boss during Garalon encounter in Heart of Fear
 */
class boss_garalon : public CreatureScript
{
public:
    boss_garalon() : CreatureScript("boss_garalon")
    {

    }

    class boss_garalon_AI : public ScriptedAI
    {
    public:        
        boss_garalon_AI(Creature* creature) :
            ScriptedAI(creature), _instance(creature->GetInstanceScript()), _under33Percent(false)
        {
            _events.Reset();
            _legs.clear();
        }

        void Reset()
        {
            if(_instance)
                _instance->SetBossState(DATA_GARALON, NOT_STARTED);
            
            for(uint8 i = 0 ; i < MAX_WEAK_POINT_SPELLS ; ++i)
                DoCast(weakPoints[i]);
            
            _events.Reset();
            _under33Percent = false;
        }

        void EnterCombat(Unit *aggro)
        {
            if(_instance)
                _instance->SetBossState(DATA_GARALON, IN_PROGRESS);

            _events.ScheduleEvent(EVENT_GARALON_FURIOUS_SWIPE, GenerateFuriousSwipeTimer());
            _events.ScheduleEvent(EVENT_GARALON_PHEROMONES_FIRST, 2000);
            _events.ScheduleEvent(EVENT_GARALON_CRUSH_SEARCHER, 1000);
            if(IsHeroic())
                _events.ScheduleEvent(EVENT_GARALON_CRUSH_PERIODIC, 5000);
        }

        void UpdateAI(uint32 diff)
        {
            if(!UpdateVictim())
                return;

            if(HealthBelowPct(33) && !_under33Percent)
            {
                DoCast(SPELL_GARALON_DAMAGED);
                _under33Percent = true;
            }

            _events.Update(diff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while(uint32 eventId = _events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_GARALON_FURIOUS_SWIPE:
                    DoCast(SPELL_GARALON_FURIOUS_SWIPE);
                    _events.ScheduleEvent(EVENT_GARALON_FURIOUS_SWIPE, GenerateFuriousSwipeTimer());
                    break;

                case EVENT_GARALON_PHEROMONES_FIRST:
                    DoCast(SPELL_GARALON_PHEROMONES_BEGIN);
                    break;

                case EVENT_GARALON_CRUSH_SEARCHER:
                    DoCast(SPELL_GARALON_CRUSH_DUMMY);
                    _events.ScheduleEvent(EVENT_GARALON_CRUSH_SEARCHER, 1000);
                    break;

                case EVENT_GARALON_CRUSH_PERIODIC:
                    DoCast(SPELL_GARALON_CRUSH);
                    _events.ScheduleEvent(EVENT_GARALON_CRUSH_PERIODIC, 5000);
                    break;

                case EVENT_GARALON_MEND_LEG_PREPARE :
                    _events.ScheduleEvent(EVENT_GARALON_MEND_LEG, 30000);
                    break;

                case EVENT_GARALON_MEND_LEG:
                    DoCast(SPELL_GARALON_MEND_LEG);
                    break;

                default:
                    break;
                } // end switch(eventId)
            } // end while(eventId)

            if(IsHeroic() && me->HasAura(SPELL_GARALON_DAMAGED))
                DoMeleeAttackIfReady();
        }

        void JustDied(Unit *killer)
        {
            if(_instance)
                _instance->SetBossState(DATA_GARALON, DONE);

            if(Vehicle* kit = me->GetVehicleKit())
            {
                for(SeatMap::iterator iter = kit->Seats.begin() ; iter != kit->Seats.end() ; ++iter)
                    if(Creature* leg = ObjectAccessor::GetCreature(*me, iter->second.Passenger.Guid))
                        leg->DisappearAndDie();

                kit->RemoveAllPassengers();
            }
        }

        void DoAction(int32 actionId)
        {
            switch(actionId)
            {
            case ACTION_GARALON_CRUSH_POSSIBLE: // SPELL_GARALON_CRUSH_DUMMY detected a target
                DoCastAOE(SPELL_GARALON_CRUSH);
                break;

            case ACTION_GARALON_LEG_DAMAGED:
                if(_events.GetNextEventTime(EVENT_GARALON_MEND_LEG) == 0)
                    _events.ScheduleEvent(EVENT_GARALON_MEND_LEG, 30000);
                else
                    me->m_Events.AddEvent(new GaralonEncounter::DelayedEventRescheduler(_events, EVENT_GARALON_MEND_LEG_PREPARE, 500),
                                          _events.GetNextEventTime(EVENT_GARALON_MEND_LEG));
                break;

            default:
                break;
            } // end switch(actionId)
        }

        void AddLeg(Creature* leg)
        {
            _legs.push_back(leg);
        }

        void RemoveLeg(Creature* leg)
        {
            _legs.remove(leg);
        }

        CreatureList const& GetDamagedLegs() const
        {
            return _legs;
        }

    private:
        EventMap _events;
        InstanceScript* _instance;
        CreatureList _legs;
        bool _under33Percent;

        //! Return a random timer for EVENT_GARALON_FURIOUS_SWIPE, based on the map difficulty
        uint32 GenerateFuriousSwipeTimer()
        {
            if(me->GetMap())
            {
                switch(me->GetMap()->GetDifficultyID())
                {
                case DIFFICULTY_10_N:
                    return urand(16000, 20000);

                case DIFFICULTY_25_N:
                    return urand(14000, 16000);

                case DIFFICULTY_10_HC:
                    return urand(12000, 14000);

                case DIFFICULTY_25_HC:
                    return urand(9000, 11000);

                default:
                    break;
                } // end switch(me->GetMap()->GetDifficulty())
            }
        } // GenerateFuriousSwipeTimer
    };

    CreatureAI* GetAI(Creature *creature) const
    {
        return new boss_garalon_AI(creature);
    }
};

typedef boss_garalon::boss_garalon_AI GaralonAI;

/** Returns a pointer to Garalon's AI, by dynmically downcasting a CreatureAI pointer to
 *    a GaralonAI pointer.
 */
static GaralonAI* GetGaralonAI(Creature* garalon)
{
    if(!garalon || garalon->GetEntry() != NPC_GARALON)
        return NULL;

    return dynamic_cast<GaralonAI*>(garalon->AI());
}

/** Class for the script of the mob "Garalon's leg" during the Garalon encounter
 *    in Heart of Fear. The players attack Garalon's leg to damage the boss easier.
 */
class mob_garalons_leg : public CreatureScript
{
public:
    mob_garalons_leg() : CreatureScript("mob_garalons_leg")
    {

    }

    class mob_garalons_leg_AI : public ScriptedAI
    {
    public:
        mob_garalons_leg_AI(Creature* creature) :
            ScriptedAI(creature), _instance(creature->GetInstanceScript()), _garalonAI(NULL) // Init the pointer to NULL so it won't point to something unpredictable
        {
            if(me->GetVehicle()
                    && me->GetVehicle()->GetBase()
                    && me->GetVehicle()->GetBase()->ToCreature())
                _garalonAI = GetGaralonAI(me->GetVehicle()->GetBase()->ToCreature()); // Now try to init correctly ; if this fails, the pointer is still null
        }

        void Reset()
        {

        }

        void JustDied(Unit *killer)
        {
            if(_garalonAI)
            {
                _garalonAI->DoAction(GaralonEncounter::BossGaralon::ACTION_GARALON_LEG_DAMAGED);
                _garalonAI->AddLeg(me);
            }
        }

    private:
        GaralonAI* _garalonAI;
        InstanceScript* _instance;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_garalons_leg_AI(creature);
    }
};

typedef std::list<WorldObject*> WorldObjectList;

/** Binary predicate used to filter targets in a WorldObjectList according to the
 *  position of the WorldObject (in or not in an arc of givent degrees in front of
 *  the caster).
 */
class InArcPredicate
{
public:
    InArcPredicate(WorldObject* source, float arc) : _source(source), _arc(arc)
    {

    }

    bool operator()(WorldObject* target)
    {
        return !(_source->HasInArc(_arc, target));
    }

private:
    WorldObject* _source;
    float _arc;
};

/** Binary predicate used to filter targets in a WorldObjectList according to the
 *  TypeID of the WorldObject.
 */
class TypeIdCheck
{
public:
    TypeIdCheck(TypeID type) : _type(type)
    {

    }

    bool operator()(WorldObject* target)
    {
        return target->GetTypeId() != _type;
    }

private:
    TypeID _type;
};


/** Class for the script of the spell Furious Swipe during Garalon encounter
 *  in Heart of Fear. Due to lack of target handling in case the target has
 *  a TARGET_SELECT_CATEGORY_AREA, there is a need to handle manually the
 *  target selection.
 */
class spell_garalon_furious_swipe_target_selector : public SpellScriptLoader
{
public:
    spell_garalon_furious_swipe_target_selector() : SpellScriptLoader("spell_garalon_furious_swipe")
    {

    }

    class spell_garalon_furious_swipe_target_selector_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_garalon_furious_swipe_target_selector_SpellScript);

        bool Validate(const SpellInfo *spellInfo)
        {
            return true;
        }

        bool Load()
        {
            return true;
        }

        void FilterTargets(WorldObjectList& targets)
        {
            targets.remove_if(InArcPredicate(GetCaster(), 170.0f * M_PI / 180.0f)); // Arbitrary value

            if(targets.size() < 2)
                if(GetCaster())
                    GetCaster()->CastSpell(GetCaster(), GaralonEncounter::BossGaralon::SPELL_GARALON_FURY, false);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_garalon_furious_swipe_target_selector_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_104);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_garalon_furious_swipe_target_selector_SpellScript();
    }
};

/** Class for the script of the SPELL_GARALON_CRUSH_DUMMY
 *  during the Garalon encounter in Heart of Fear. It is used as a searcher : if during
 *  the run of the handling function of the dummy effect, a player is found under Garalon
 *  (inside the purple circle) we order Garalon to cast SPELL_GARALON_CRUSH. Otherwise we return.
 */
class spell_garalon_crush_searcher : public SpellScriptLoader
{
public:
    spell_garalon_crush_searcher() : SpellScriptLoader("spell_garalon_crush_searcher")
    {

    }

    class spell_garalon_crush_searcher_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_garalon_crush_searcher_SpellScript);

        bool Validate(const SpellInfo* spellInfo)
        {
            return true;
        }

        bool Load()
        {
            return true;
        }

        void HandleDummy(SpellEffIndex effectIndex)
        {
            std::list<Player*> players;
            GetPlayerListInGrid(players, GetCaster(), 14.0f);

            if(!players.empty())
                if(GaralonAI* garalonAI = GetGaralonAI(GetCaster() ? GetCaster()->ToCreature() : NULL))
                    garalonAI->DoAction(GaralonEncounter::BossGaralon::ACTION_GARALON_CRUSH_POSSIBLE);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_garalon_crush_searcher_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_garalon_crush_searcher_SpellScript();
    }
};

/** Class for the script of the SPELL_GARALON_PHEROMONES_BEGIN during the Garalon encounter
 *  in Heart of Fear. The spell must target the closest player, and we cannot do that with
 *  the conditions table. So here comes an ObjectAreaTargetSelect handler.
 */
class spell_garalon_pheromones_first_target_selector : public SpellScriptLoader
{
public:
    spell_garalon_pheromones_first_target_selector() : SpellScriptLoader("spell_garalon_pheromones_first_target_selector")
    {

    }

    class spell_garalon_pheromones_first_target_selector_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_garalon_pheromones_first_target_selector_SpellScript);

        bool Validate(const SpellInfo *spellInfo)
        {
            return true;
        }

        bool Load()
        {
            return true;
        }

        void SelectTarget(WorldObjectList& targets)
        {
            targets.remove_if(TypeIdCheck(TYPEID_PLAYER));
            targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster()));
            targets.resize(1);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_garalon_pheromones_first_target_selector_SpellScript::SelectTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_garalon_pheromones_first_target_selector_SpellScript();
    }
};

/** Class for the script of the SPELL_GARALON_PHEROMONES_SWITCH during the Garalon encounter
 *  in Heart of Fear. The spell must target the closest ally, and we cannot do that with the
 *  conditions table. So here comes an ObjectAreaTargetSelect handler.
 */
class spell_garalon_pheromones_switch_target_selector : public SpellScriptLoader
{
public:
    spell_garalon_pheromones_switch_target_selector() : SpellScriptLoader("spell_garalon_pheromones_switch_target_selector")
    {

    }

    class spell_garalon_pheromones_switch_target_selector_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_garalon_pheromones_switch_target_selector_SpellScript);

        bool Validate(const SpellInfo *spellInfo)
        {
            return true;
        }

        bool Load()
        {
            return true;
        }

        void FilterTargets(WorldObjectList& targets)
        {
            targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster()));
            targets.resize(1);
        }

        void HandleOnHit()
        {
            if(Unit* hit = GetHitUnit())
            {
                if(Unit* caster = GetCaster())
                {
                    caster->RemoveAurasDueToSpell(GaralonEncounter::BossGaralon::SPELL_GARALON_PHEROMONES);
                    caster->RemoveAura(GaralonEncounter::BossGaralon::SPELL_GARALON_PHEROMONES);
                }
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_garalon_pheromones_switch_target_selector_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
            OnHit += SpellHitFn(spell_garalon_pheromones_switch_target_selector_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_garalon_pheromones_switch_target_selector_SpellScript();
    }
};

/** Class for the script of SPELL_GARALON_MEND_LEG during the Garalon encounter in Heart of Fear.
 *  The spell has an area of selection, but it must select specificly and we cannot do that with
 *  the conditions table. So here comes an ObjectAreaTargetSelect handler.
 */
class spell_garalon_mend_leg_target_selector : public SpellScriptLoader
{
public:
    spell_garalon_mend_leg_target_selector() : SpellScriptLoader("spell_garalon_mend_leg_target_selector")
    {

    }

    class spell_garalon_mend_leg_target_selector_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_garalon_mend_leg_target_selector_SpellScript);

        bool Validate(const SpellInfo *spellInfo)
        {
            return true;
        }

        bool Load()
        {
            return true;
        }

        void FilterTargets(WorldObjectList& targets)
        {
            if(GaralonAI* garalonAI = GetGaralonAI(GetCaster() ? GetCaster()->ToCreature() : NULL))
            {
                targets.clear();
                targets.push_back(garalonAI->GetDamagedLegs().front());
            }
        }

        void HandleDummy(SpellEffIndex effectIndex)
        {
            if(GetHitCreature())
            {
                GetHitCreature()->Respawn(true);
                if(GaralonAI* garalonAI = GetGaralonAI(GetCaster() ? GetCaster()->ToCreature() : NULL))
                    garalonAI->RemoveLeg(GetHitCreature());
            }
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_garalon_mend_leg_target_selector_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnEffectHitTarget += SpellEffectFn(spell_garalon_mend_leg_target_selector_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_garalon_mend_leg_target_selector_SpellScript();
    }
};

/** Class for the script of SPELL_MEND_LEG_SCRIPT_EFFECT during the Garalon encounter in Heart
 *  of Fear. The spell removes a stack of SPELL_GARALON_BORKEN_LEG on the caster.
 */
class spell_garalon_mend_leg_repair : public SpellScriptLoader
{
public:
    spell_garalon_mend_leg_repair() : SpellScriptLoader("spell_garalon_mend_leg_repair")
    {

    }

    class spell_garalon_mend_leg_repair_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_garalon_mend_leg_repair_SpellScript);

        bool Validate(const SpellInfo *spellInfo)
        {
            return true;
        }

        bool Load()
        {
            return true;
        }

        void HandleDummy(SpellEffIndex effectIndex)
        {
            if(GetCaster())
                if(Aura* brokenLeg = GetCaster()->GetAura(GaralonEncounter::BossGaralon::SPELL_GARALON_BROKEN_LEG))
                    brokenLeg->ModStackAmount(-1);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_garalon_mend_leg_repair_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_garalon_mend_leg_repair_SpellScript();
    }
};

void AddSC_boss_garalon()
{
    new boss_garalon();
    new mob_garalons_leg();
    new spell_garalon_furious_swipe_target_selector();
    new spell_garalon_crush_searcher();
    new spell_garalon_pheromones_first_target_selector();
    new spell_garalon_pheromones_switch_target_selector();
    new spell_garalon_mend_leg_target_selector();
    new spell_garalon_mend_leg_repair();
}

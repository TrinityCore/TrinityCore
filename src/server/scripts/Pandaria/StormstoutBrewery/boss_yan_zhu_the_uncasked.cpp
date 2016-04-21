#include "stormstout_brewery.h"

enum YanZhuCreatures {
    MOB_YEASTY_BREW_ALAMENTAL   = 66413, // Not the same as in Uncle Gao Event
    MOB_BUBBLE_SHIELD           = 59487, // Not the same as in Uncle Gao Event
    MOB_FIZZY_BUBBLE            = 59799, // Need a npc_spellclick_spells
    NPC_UNCLE_GAO               = 59074, // To end the instance with a little RP
    MOB_WALL_OF_SUDS            = 59512, // Stalker
    MOB_BLOATED_STALKER         = 59482, // Stalker
};

enum Events {
    /** Yan Zhu **/
    EVENT_YAN_ZHU_CHECK_FOR_PLAYERS = 1,
    EVENT_YAN_ZHU_BREW_BOLT         = 2,

    // Wheat
    EVENT_YAN_ZHU_BLOAT             = 3,
    EVENT_YAN_ZHU_BLACKOUT_BREW     = 4,

    // Ale
    EVENT_YAN_ZHU_BUBBLE_SHIELD     = 5,
    EVENT_YAN_ZHU_SUMMON_ALAMENTALS = 6,

    // Stout
    EVENT_YAN_ZHU_CARBONATION       = 7,
    EVENT_YAN_ZHU_WALL_OF_SUDS      = 8,

    EVENT_YAN_ZHU_CHECK_FOR_SUDSY   = 9,
    EVENT_YAN_ZHU_STOP_SEARCHING    = 10,

    /** Yeasty Brew Alamental **/
    EVENT_YEASTY_BREW_ALAMENTAL_FERMENT     = 11,
    EVENT_YEASTY_BREW_ALAMENTAL_BREW_BOLT   = 12,
};

enum YanZhuSpells {
    /** Yan Zhu **/
    SPELL_BREW_BOLT = 114548, // When nobody in melee range

    // Wheat
    SPELL_BLOAT                         = 106546, // Turns target into a vehicle ; we must put two npcs in the vehicle
    SPELL_BLOAT_TRIGGER_PERIODIC        = 106549, // The stalkers in the vehicle cast this on themselves
    SPELL_BLOAT_DAMAGES                 = 106560, // Inflicts damage ; we need to handle the targets carefully

    SPELL_BLACKOUT_BREW_STACK           = 106851, // When it reaches 10 stack, puts caster to sleep
    SPELL_BLACKOUT_DRUNK                = 106857, // When Blackout Brew reaches 10 stacks

    // Ale
    SPELL_BUBBLE_SHIELD                 = 106563, // Turns target into a vehicle ; we must put one npc in each seat,
                                                  // and each time a npc is killed, reduce the stack amount by one

    // Stout
    SPELL_CARBONATION_TRIGGER_PERIODIC  = 115003, // Periodic trigger spell
    SPELL_CARBONATION_DAMAGES           = 114386, // Damages of previous spell

    SPELL_WALL_OF_SUDS_TRIGGER_PERIODIC = 114467, // Maybe we can use the periodic to move the npc ?
    SPELL_WALL_OF_SUDS_DAMAGES          = 114466, // Damages of the previous spell ; handle target 130 carefully

    SPELL_SUDSY_PROC_TRIGGER_SPELL      = 114468, // We cannot use a spell_proc_event right here, so we will be forced to loop
                                                  // over the PlayerList to trigger the spell on the player who jump ; this will be
                                                  // expensive in memory / cpu I'm affraid
    SPELL_SUDSY                         = 114470, // This one makes the player jump

    /** Mechanic system **/

    // Stout
    SPELL_SUDSY_BREW                    = 114933,
    SPELL_FIZZY_BREW                    = 114934,

    // Wheat
    SPELL_BLOATING_BREW                 = 114929,
    SPELL_BLACKOUT_BREW                 = 114930,

    // Ale
    SPELL_BUBBLING_BREW                 = 114931,
    SPELL_YEASTY_BREW                   = 114932,

    /** Yeasty Brew Alamental **/
    SPELL_FERMENT                       = 114451, // Since 106859 doesn't work (don'y know why), this is the only solution
    SPELL_BREW_BOLT_MINOR               = 116155
};

namespace YanZhu {
    struct BloatTargetSelector : public std::unary_function<Unit*, bool> {
        explicit BloatTargetSelector(uint32 t = 0) : _t(t) { }

        bool operator()(Unit* target) const {
            if(target->HasAura(SPELL_BLOAT))
                return false ;

            if(target->GetTypeId() != TYPEID_PLAYER)
                return false ;

            return true ;
        }
        uint32 _t ;
    };

    class InlineCheckPredicate {
    public :
        InlineCheckPredicate(Creature* caster, uint32 spellId = 0) : _caster(caster), _spellId(spellId) {

        }

        bool operator()(WorldObject* target) {
            if(!target)
                return true ;

            if(_spellId == SPELL_WALL_OF_SUDS_DAMAGES)
                if(target->GetTypeId() != TYPEID_PLAYER)
                    return true ;
            
            float width = 3.0f ;
            switch(_spellId) {
                case SPELL_WALL_OF_SUDS_DAMAGES :
                    width = 3.0f ;
                    break ;
                    
                default :
                    break ;
            }
            
            if(!_caster->HasInLine(target, width))
                return true ;

            return false ;
        }

    private :
        Creature* _caster ;
        uint32 _spellId ;
    };
    
    class FermentTargetSelector {
    public :
        FermentTargetSelector() {
        
        }
        
        bool operator()(WorldObject* target) {
            // Target is a player : do not remove it
            if(target && target->GetTypeId() == TYPEID_PLAYER)
                return false ;
                
            // Didn't return, target is not player, so check entry
            if(target && target->GetEntry() == BOSS_YAN_ZHU)
                return false ;
            
            // Didn't return, wasn't YanZhu, check for friends
            if(target && target->GetEntry() == MOB_YEASTY_BREW_ALAMENTAL)
                return false ;
                
            // Didn't return, not a player, yan zhu or a friend, so it is bad target : remove it
            return true ;
        }
    };
    
    class WallOfSudsTargetSelector {
    public :
        WallOfSudsTargetSelector() {
        
        }
        
        bool operator()(WorldObject* target) {
            if(target && target->GetTypeId() != TYPEID_PLAYER)
                return true ;
                
            return false ;
        }
    };

    class IgnoreTargetPredicate {
    public :
        IgnoreTargetPredicate(Unit* ignore) : _ignore(ignore) {

        }

        bool operator()(WorldObject* target) {
            if(!target->ToUnit())
                return false ;

            if(target->ToUnit() == _ignore)
                return true ;

            return false;
        }

    private :
        Unit* _ignore;
    };

    class HeightCheckPredicate {
    public :
        HeightCheckPredicate(Unit* source, float diff) : _source(source), _difference(diff) {

        }

        bool operator()(WorldObject* target) {
            float diff = abs(_source->GetPositionZ() - target->GetPositionZ());
            if(diff < _difference)
                return false ;
            return true ;
        }

    private :
        Unit* _source ;
        float _difference ;
    };

    const Position wallOfSudsPositions[2][2] = {
        {
            {-673.752014f, 1193.162231f, 166.732635f, 3.423159f},
            {-664.642944f, 1148.553955f, 166.732635f, 1.811523f}
        }, 
        {
            {-744.290283f, 1179.231079f, 166.732635f, 4.968039f},
            {-732.704712f, 1131.331665f, 166.732635f, 0.225805f}
        }
    };

    const Position summonFizzyBubblePositions[8] = {
        {-718.938965f, 1171.644287f, 166.156494f, 0.0f},
        {-715.915100f, 1159.415649f, 166.156494f, 0.0f},
        {-712.300415f, 1147.217163f, 166.156494f, 0.0f},
        {-700.215149f, 1150.571167f, 166.156494f, 0.0f},
        {-687.963074f, 1154.350342f, 166.156494f, 0.0f},
        {-691.251221f, 1166.405884f, 166.156494f, 0.0f},
        {-694.422852f, 1178.316162f, 166.156494f, 0.0f},
        {-706.848511f, 1174.876831f, 166.156494f, 0.0f}
    };

    const Position summonYeastyBrewAlamentalsPositions[6] = {
        {-718.938965f, 1171.644287f, 166.156494f, 0.0f},
        {-715.915100f, 1159.415649f, 166.156494f, 0.0f},
        {-712.300415f, 1147.217163f, 166.156494f, 0.0f},
        {-687.963074f, 1154.350342f, 166.156494f, 0.0f},
        {-691.251221f, 1166.405884f, 166.156494f, 0.0f},
        {-694.422852f, 1178.316162f, 166.156494f, 0.0f}
    };
} // namespace YanZhu

class boss_yan_zhu_the_uncasked : public CreatureScript {
public :
    boss_yan_zhu_the_uncasked() : CreatureScript("boss_yan_zhu_the_uncasked") {

    }

    class boss_yan_zhu_the_uncasked_AI : public ScriptedAI {
    public :
        boss_yan_zhu_the_uncasked_AI(Creature* creature) : ScriptedAI(creature) {
            _instance = creature->GetInstanceScript();
            memset(&_brews, 0, sizeof(_brews));
        }

        /** ScriptedAI Functions **/
        void Reset() {
            if(_instance)
                _instance->SetData(INSTANCE_DATA_YAN_ZHU_STATUS, NOT_STARTED);
            _uncleGao = me->ToTempSummon()->GetSummoner()->ToCreature() ;
            _events.Reset();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            
            for(uint8 i = 0 ; i < 3 ; ++i)
                DoCast(me, _brews[i]);
        }

        void EnterCombat(Unit *aggro) {
            if(_instance) {
                _instance->SetData(INSTANCE_DATA_YAN_ZHU_STATUS, IN_PROGRESS);
                if(GameObject* entrance = _instance->GetGameObject(_instance->GetData64(INSTANCE_DATA64_YAN_ZHU_ENTRANCE_GUID)))
                    entrance->SetGoState(GO_STATE_READY);
            }

            // Stout
            if(me->HasAura(SPELL_SUDSY_BREW))
                _events.ScheduleEvent(EVENT_YAN_ZHU_WALL_OF_SUDS, IsHeroic() ? 20000 : 30000);
            else
                _events.ScheduleEvent(EVENT_YAN_ZHU_CARBONATION, IsHeroic() ? 20000 : 30000);

            // Wheat
            if(me->HasAura(SPELL_BLOATING_BREW))
                _events.ScheduleEvent(EVENT_YAN_ZHU_BLOAT, IsHeroic() ? 10000 : 15000);
            else
                _events.ScheduleEvent(EVENT_YAN_ZHU_BLACKOUT_BREW, IsHeroic() ? 10000 : 15000);

            // Ale
            if(me->HasAura(SPELL_BUBBLING_BREW))
                _events.ScheduleEvent(EVENT_YAN_ZHU_BUBBLE_SHIELD, IsHeroic() ? 15000 : 20000);
            else
                _events.ScheduleEvent(EVENT_YAN_ZHU_SUMMON_ALAMENTALS, IsHeroic() ? 15000 : 20000);

            // General
            _events.ScheduleEvent(EVENT_YAN_ZHU_CHECK_FOR_PLAYERS, 500);
            
            DoZoneInCombat();
        }

        void EnterEvadeMode() {
            if(_instance) {
                _instance->SetData(INSTANCE_DATA_YAN_ZHU_STATUS, FAIL);
                if(GameObject* entrance = _instance->GetGameObject(_instance->GetData64(INSTANCE_DATA64_YAN_ZHU_ENTRANCE_GUID)))
                    entrance->SetGoState(GO_STATE_ACTIVE);
            }
            
            // Remove alamentals when fight resets
            std::list<Creature*> alamentals;
            GetCreatureListWithEntryInGrid(alamentals, me, MOB_YEASTY_BREW_ALAMENTAL, 50000.0f);
            for(auto iter : alamentals)
                iter->DisappearAndDie();
            
            ScriptedAI::EnterEvadeMode();
        }

        void JustDied(Unit* killer) {
            if(_instance) {
                _instance->SetData(INSTANCE_DATA_YAN_ZHU_STATUS, DONE);
                if(GameObject* entrance = _instance->GetGameObject(_instance->GetData64(INSTANCE_DATA64_YAN_ZHU_ENTRANCE_GUID)))
                    entrance->SetGoState(GO_STATE_ACTIVE);
            }
            
            // Remove alamentals when boss dies
            std::list<Creature*> alamentals;
            GetCreatureListWithEntryInGrid(alamentals, me, MOB_YEASTY_BREW_ALAMENTAL, 50000.0f);
            for(auto iter : alamentals)
                iter->DisappearAndDie();
        }
        
        void SetData(uint32 index, uint32 data) {
            _brews[index] = data ;
        }

        void UpdateAI(uint32 diff) {
            if(!UpdateVictim())
                return ;

            _events.Update(diff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return ;

            while(uint32 eventId = _events.ExecuteEvent()) {
                switch(eventId) {
                case EVENT_YAN_ZHU_CHECK_FOR_PLAYERS :
                    DoCheckForPlayers();
                    break ;

                case EVENT_YAN_ZHU_BLACKOUT_BREW :
                    if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                        for(uint8 i = 0 ; i < 3 ; ++i) // Add three stack that way, better than something wierd in AuraScript handler
                            DoCast(target, SPELL_BLACKOUT_BREW_STACK, true);
                    _events.ScheduleEvent(EVENT_YAN_ZHU_BLACKOUT_BREW, IsHeroic() ? urand(8500, 10500) : urand(12000, 15000));
                    break ;

                case EVENT_YAN_ZHU_BLOAT : {
                    YanZhu::BloatTargetSelector selector ;
                    if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, selector))
                        DoCast(target, SPELL_BLOAT);
                    _events.ScheduleEvent(EVENT_YAN_ZHU_BLOAT, IsHeroic() ? urand(8500, 10500) : urand(12000, 15000));
                    break ;
                }

                case EVENT_YAN_ZHU_CARBONATION :
                    for(uint8 i = 0 ; i < 8 ; ++i) {
                        const Position summonPosition = YanZhu::summonFizzyBubblePositions[i];
                        me->SummonCreature(MOB_FIZZY_BUBBLE, summonPosition, TEMPSUMMON_TIMED_DESPAWN, 15000);
                    }
                    DoCast(me, SPELL_CARBONATION_TRIGGER_PERIODIC);
                    _events.ScheduleEvent(EVENT_YAN_ZHU_CARBONATION, IsHeroic() ? urand(25000, 30000) : urand(40000, 50000));
                    break ;

                case EVENT_YAN_ZHU_WALL_OF_SUDS : {
                    uint8 j = (uint8)urand(0, 1);
                    for(uint8 i = 0 ; i < 2 ; ++i) {
                        const Position summonPosition = YanZhu::wallOfSudsPositions[j][i];
                        if(Creature* summon = me->SummonCreature(MOB_WALL_OF_SUDS, summonPosition, TEMPSUMMON_TIMED_DESPAWN, 15000))
                            summon->CastSpell(summon, SPELL_WALL_OF_SUDS_TRIGGER_PERIODIC);
                    }
                    //DoCastToAllHostilePlayers(SPELL_SUDSY_PROC_TRIGGER_SPELL);
                    DoCastAOE(SPELL_SUDSY_PROC_TRIGGER_SPELL);
                    _events.ScheduleEvent(EVENT_YAN_ZHU_WALL_OF_SUDS, IsHeroic() ? urand(25000, 30000) : urand(40000, 50000));
                    _events.ScheduleEvent(EVENT_YAN_ZHU_CHECK_FOR_SUDSY, 500);
                    _events.ScheduleEvent(EVENT_YAN_ZHU_STOP_SEARCHING, 15000);
                    break ;
                }

                case EVENT_YAN_ZHU_BUBBLE_SHIELD :
                    if(me->HasAura(SPELL_BUBBLE_SHIELD)) {
                        _events.ScheduleEvent(EVENT_YAN_ZHU_BUBBLE_SHIELD, IsHeroic() ? urand(12000, 14000) : urand(13000, 16000));
                        break ;
                    }
                    DoCast(me, SPELL_BUBBLE_SHIELD);
                    if(Aura* aura = me->GetAura(SPELL_BUBBLE_SHIELD))
                        aura->ModStackAmount(7);
                    _events.ScheduleEvent(EVENT_YAN_ZHU_BUBBLE_SHIELD, IsHeroic() ? urand(12000, 14000) : urand(13000, 16000));
                    break ;

                case EVENT_YAN_ZHU_SUMMON_ALAMENTALS :
                    DoSummonYeastyBrewAlamentals();
                    break ;

                case EVENT_YAN_ZHU_BREW_BOLT :
                    if(Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                        DoCast(target, SPELL_BREW_BOLT);
                    _events.ScheduleEvent(EVENT_YAN_ZHU_BREW_BOLT, IsHeroic() ? 750 : 1000);
                    break ;

                case EVENT_YAN_ZHU_CHECK_FOR_SUDSY :
                    DoCheckForSudsy();
                    break ;

                case EVENT_YAN_ZHU_STOP_SEARCHING :
                    _events.CancelEvent(EVENT_YAN_ZHU_CHECK_FOR_SUDSY);
                    break ;

                default :
                    break ;
                }
            }

            DoMeleeAttackIfReady();
        }

        void SummonedCreatureDies(Creature *summoned, Unit *killer) {
            if(summoned->GetEntry() == MOB_BUBBLE_SHIELD) {
                if(Aura* bubbleShield = me->GetAura(SPELL_BUBBLE_SHIELD))
                    bubbleShield->ModStackAmount(-1);
            }
        }

        /** Non ScriptedAI functions **/

        void DoCheckForPlayers() {
            if(Map* map = me->GetMap()) {
                Map::PlayerList const& playerList = map->GetPlayers();

                if(playerList.isEmpty()) {
                    _events.ScheduleEvent(EVENT_YAN_ZHU_CHECK_FOR_PLAYERS, 500);
                    return  ;
                }

                for(Map::PlayerList::const_iterator iter = playerList.begin() ; iter != playerList.end() ; ++iter) {
                    if(Player* player = iter->GetSource()) {
                        float dist = me->GetExactDist2d(player);
                        if(dist <= 7.5f) {
                            _events.ScheduleEvent(EVENT_YAN_ZHU_CHECK_FOR_PLAYERS, 500);
                            _events.CancelEvent(EVENT_YAN_ZHU_BREW_BOLT);
                            return ;
                        }
                    }
                }

                // No player in melee range
                _events.ScheduleEvent(EVENT_YAN_ZHU_CHECK_FOR_PLAYERS, 500); // To stop casting brew bolts if a player comes in range
                _events.ScheduleEvent(EVENT_YAN_ZHU_BREW_BOLT, MIN_MAP_UPDATE_DELAY); // And to allow the boss to cast brew bolts while nobody in range
            }
        }

        void DoSummonYeastyBrewAlamentals() {
            uint32 index = urand(0, 2);
            uint32 secondIndex = urand(3, 5);

            Creature* first = me->SummonCreature(MOB_YEASTY_BREW_ALAMENTAL, YanZhu::summonYeastyBrewAlamentalsPositions[index], TEMPSUMMON_CORPSE_DESPAWN, 0);
            
            // According to players, YanZhu only summons one yeasty brew alamental
            // Creature* second = me->SummonCreature(MOB_YEASTY_BREW_ALAMENTAL, YanZhu::summonYeastyBrewAlamentalsPositions[secondIndex], TEMPSUMMON_CORPSE_DESPAWN, 0);

            _events.ScheduleEvent(EVENT_YAN_ZHU_SUMMON_ALAMENTALS, IsHeroic() ? urand(12000, 14000) : urand(13000, 16000));
        }

        void DoCheckForSudsy() {
            uint32 count = 0 ;

            if(Map* map = me->GetMap()) {
                Map::PlayerList const& playerList = map->GetPlayers();
                if(playerList.isEmpty()) {
                    _events.CancelEvent(EVENT_YAN_ZHU_STOP_SEARCHING);
                    return ;
                }

                for(Map::PlayerList::const_iterator iter = playerList.begin() ; iter != playerList.end() ; ++iter) {
                    if(Player* player = iter->GetSource()) {
                        if(player->GetPositionZ() > me->GetPositionZ() + 1.0f) { // Not perfect, maybe movementflags ?
                            if(Aura* sudsy = player->GetAura(SPELL_SUDSY_PROC_TRIGGER_SPELL)) {
                                SpellInfo const* sudsySI = sudsy->GetSpellInfo();
                                player->CastSpell(player, 114470, true);
                                sudsy->Remove();
                                ++count ;
                            }
                        }
                    }
                }
            }

            // 0 or 1 player had the aura left ; so know, it is useless to check again : if one player had the aura, know it hasn't it anymore
            // If zero player had the aura, nobody has it know
            if(count < 2)
                _events.CancelEvent(EVENT_YAN_ZHU_STOP_SEARCHING);
            else
                _events.ScheduleEvent(EVENT_YAN_ZHU_CHECK_FOR_SUDSY, 500);
        }

    private :
        /// Pointer to the instance script
        InstanceScript* _instance ;

        /// EventMap
        EventMap _events ;

        /// Pointer to the summoner
        Creature* _uncleGao ;
        
        /// Spells the boss will cast on itself
        uint32 _brews[3];
    };

    CreatureAI* GetAI(Creature* creature) const {
        return new boss_yan_zhu_the_uncasked_AI(creature);
    }
};

class mob_yeasty_brew_alamental_yan_zhu : public CreatureScript {
public :
    mob_yeasty_brew_alamental_yan_zhu() : CreatureScript("mob_yeasty_brew_alamental_yan_zhu") {

    }

    class mob_yeasty_brew_alamental_yan_zhu_AI : public ScriptedAI {
    public :
        mob_yeasty_brew_alamental_yan_zhu_AI(Creature* creature) : ScriptedAI(creature) {
            _instance = creature->GetInstanceScript();
        }

        void IsSummonedBy(Unit* summoner) {
            _events.Reset();

            // _events.ScheduleEvent(EVENT_YEASTY_BREW_ALAMENTAL_BREW_BOLT, 1000); // Don't know when this is casted
            _events.ScheduleEvent(EVENT_YEASTY_BREW_ALAMENTAL_FERMENT, MIN_MAP_UPDATE_DELAY);

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
        }

        void UpdateAI(uint32 diff) {
            _events.Update(diff);

            while(uint32 eventId = _events.ExecuteEvent()) {
                switch(eventId) {
                case EVENT_YEASTY_BREW_ALAMENTAL_FERMENT :
                    // sLog->outDebug(LOG_FILTER_NETWORKIO, "Casting ferment");
                    me->CastSpell(me, SPELL_FERMENT, false);
                    _events.ScheduleEvent(EVENT_YEASTY_BREW_ALAMENTAL_FERMENT, 1500); // Replace the periodic tick
                    break ;

                default :
                    break ;
                }
            }

            /// This is almost a do nothing AI, we only cast the spell (this is very easy since target 129 works)
        }

    private :
        /// EventMap
        EventMap _events ;

        /// Pointer to the instance script
        InstanceScript* _instance ;
    };

    CreatureAI* GetAI(Creature *creature) const {
        return new mob_yeasty_brew_alamental_yan_zhu_AI(creature);
    }
};

class npc_fizzy_bubble : public CreatureScript {
public :
    npc_fizzy_bubble() : CreatureScript("npc_fizzy_bubble") {

    }

    bool OnGossipHello(Player *player, Creature *creature) {
        if(!player || !creature)
            return false ;

        if(player->HasAura(114459))
            return false ;

        player->CastSpell(player, 114459, true);
        creature->Kill(creature);
        return false ;
    }

    class npc_fizzy_bubble_AI : public ScriptedAI {
    public :
        npc_fizzy_bubble_AI(Creature* creature) : ScriptedAI(creature) {

        }

        void Reset() {
            DoCast(me, 114458); // Make me visible
        }
    };

    CreatureAI* GetAI(Creature *creature) const {
        return new npc_fizzy_bubble_AI(creature);
    }
};

#define WALL_OF_SUDS_PROGRESS 1.0f

class spell_yanzhu_wall_of_suds : public SpellScriptLoader {
public :
    spell_yanzhu_wall_of_suds() : SpellScriptLoader("spell_yanzhu_wall_of_suds") {

    }

    class spell_yanzhu_wall_of_suds_AuraScript : public AuraScript {
        PrepareAuraScript(spell_yanzhu_wall_of_suds_AuraScript);

        bool Validate(const SpellInfo *spellInfo) {
            if(sSpellMgr->GetSpellInfo(SPELL_WALL_OF_SUDS_TRIGGER_PERIODIC) &&
                    sSpellMgr->GetSpellInfo(SPELL_WALL_OF_SUDS_DAMAGES))
                return true ;

            return false ;
        }

        bool Load() {
            _uiTick = 0 ;
            return (GetCaster() && GetCaster()->ToCreature());
        }

        void HandlePeriodicTick(AuraEffect const* auraEff) {
            // We have to move the creature, make sure pointers are not null
            if(!GetCaster())
                return ;

            if(!GetCaster()->ToCreature())
                return ; // Note : this cannot happen because of Load

            Creature* caster = GetCaster()->ToCreature() ;

            float x = caster->GetPositionX() + WALL_OF_SUDS_PROGRESS * cos(caster->GetOrientation());
            float y = caster->GetPositionY() + WALL_OF_SUDS_PROGRESS * sin(caster->GetOrientation());
            float z = caster->GetPositionZ() ;

            caster->GetMotionMaster()->MovePoint(_uiTick, x, y, z, true);
            ++_uiTick ;
        }

        void Register() {
           // OnEffectPeriodic += AuraEffectPeriodicFn(spell_yanzhu_wall_of_suds_AuraScript::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }

        uint32 _uiTick ;
    };

    AuraScript* GetAuraScript() const {
        return new spell_yanzhu_wall_of_suds_AuraScript();
    }
};

class spell_yanzhu_wall_of_suds_target_selector : public SpellScriptLoader {
public :
    spell_yanzhu_wall_of_suds_target_selector() : SpellScriptLoader("spell_yanzhu_wall_of_suds_target_selector") {

    }

    class spell_yanzhu_wall_of_suds_target_selector_SpellScript : public SpellScript {
        PrepareSpellScript(spell_yanzhu_wall_of_suds_target_selector_SpellScript);

        bool Validate(const SpellInfo *spellInfo) {
            return true ; // No need to check, because it is triggered by 114467, which we already checked
        }

        bool Load() {
            return true ; // Same comment as for Validate
        }

        void FilterTargets(std::list<WorldObject*>& targets) {
            if(!GetCaster() || !GetCaster()->ToCreature())
                return ;

            Creature* caster = GetCaster()->ToCreature();

            // Filters targets like the target 129
            targets.remove_if(YanZhu::WallOfSudsTargetSelector());
            targets.remove_if(YanZhu::InlineCheckPredicate(caster, GetSpellInfo()->Id));

            //! Since this is supposed to be executed in less than one tick of the world,
            //! players may not see the changing of orientation
        }

        void Register()
        {
            //OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_yanzhu_wall_of_suds_target_selector_SpellScript::FilterTargets, EFFECT_0, TARGET_ENEMY_IN_LINE);
            //OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_yanzhu_wall_of_suds_target_selector_SpellScript::FilterTargets, EFFECT_1, TARGET_ENEMY_IN_LINE);
        }
    };

    SpellScript* GetSpellScript() const {
        return new spell_yanzhu_wall_of_suds_target_selector_SpellScript();
    }
};

class spell_yanzhu_blackout_brew : public SpellScriptLoader {
public :
    spell_yanzhu_blackout_brew() : SpellScriptLoader("spell_yanzhu_blackout_brew") {

    }

    class spell_yanzhu_blackout_brew_AuraScript : public AuraScript {
        PrepareAuraScript(spell_yanzhu_blackout_brew_AuraScript);

        bool Validate(const SpellInfo *spellInfo) {
            if(sSpellMgr->GetSpellInfo(SPELL_BLACKOUT_BREW_STACK) &&
                    sSpellMgr->GetSpellInfo(SPELL_BLACKOUT_DRUNK))
                return true ;

            return false ;
        }

        bool Load() {
            return (GetCaster() && GetCaster()->ToCreature());
        }

        // Remove a stack each second if and only if owner is moving
        void HandleEffectPeriodic(AuraEffect const* auraEff) {
            if(!GetOwner() || GetOwner()->GetTypeId() != TYPEID_PLAYER)
                return ;

            Player* owner = GetOwner()->ToPlayer();

            if(owner->isMoving())
                if(Aura* blackoutBrew = owner->GetAura(SPELL_BLACKOUT_BREW_STACK))
                    if(blackoutBrew->GetStackAmount() > 1) // Otherwise the core lowers it to 255 stack, this is logic don't you think ?
                        blackoutBrew->SetStackAmount(blackoutBrew->GetStackAmount() - 1);
                    else // Standart remove
                        blackoutBrew->Remove();
        }

        void Register() {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_yanzhu_blackout_brew_AuraScript::HandleEffectPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const {
        return new spell_yanzhu_blackout_brew_AuraScript();
    }
    
    class spell_yanzhu_blackout_brew_SpellScript : public SpellScript {
        PrepareSpellScript(spell_yanzhu_blackout_brew_SpellScript);
        
        bool Validate(const SpellInfo* spellInfo) {
            return true ;
        }
        
        bool Load() {
            return true ;
        }
        
        void HandleEffectHitTarget(SpellEffIndex effIndex) {
            // sLog->outDebug(LOG_FILTER_NETWORKIO, "SPELLS : Blackout Brew : OnEffectHitTarget (EFFECT_1) Handler") ; // Because I never trust OnEffectHitTarget handlers
            if(GetHitUnit())
                if(Aura* brew = GetHitUnit()->GetAura(SPELL_BLACKOUT_BREW_STACK))
                    if(brew->GetStackAmount() == 9) { // Check is done right here, because script effect handlers are called before call to the handlers
                        // We could prevent the default effect, but it's a bit useless, since the aura cannot stack over 10
                        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_BLACKOUT_DRUNK, true) ;
                        brew->Remove() ; // Prevents the player from being commated again
                    }
        }
        
        void Register() {
            OnEffectHitTarget += SpellEffectFn(spell_yanzhu_blackout_brew_SpellScript::HandleEffectHitTarget, EFFECT_1, SPELL_EFFECT_APPLY_AURA); // Multi target spell, so HitTarget instead of Hit
        }
    };
    
    SpellScript* GetSpellScript() const {
        return new spell_yanzhu_blackout_brew_SpellScript(); 
    }
};

class spell_yanzhu_bloat : public SpellScriptLoader {
public :
    spell_yanzhu_bloat() : SpellScriptLoader("spell_yanzhu_bloat") {

    }

    class spell_yanzhu_bloat_AuraScript : public AuraScript {
        PrepareAuraScript(spell_yanzhu_bloat_AuraScript);

        bool Validate(const SpellInfo *spellInfo) {
            if(sSpellMgr->GetSpellInfo(SPELL_BLOAT) &&
                    sSpellMgr->GetSpellInfo(SPELL_BLOAT_TRIGGER_PERIODIC) &&
                    sSpellMgr->GetSpellInfo(SPELL_BLOAT_DAMAGES))
                return true ;

            return false ;
        }

        bool Load() {
            return (GetCaster() && GetCaster()->ToCreature());
        }

        void HandleAfterEffectApply(AuraEffect const* auraEff, AuraEffectHandleModes mode) {
            if(!GetOwner() || GetOwner()->GetTypeId() != TYPEID_PLAYER)
                return ;

            Player* owner = GetOwner()->ToPlayer();

            for(uint8 i = 0 ; i < 2 ; ++i) {
                if(Creature* creature = owner->SummonCreature(MOB_BLOATED_STALKER, owner->GetPositionX() + frand(0.0f, 3.0f),
                                                              owner->GetPositionY() + frand(0.0f, 4.0f), owner->GetPositionZ(),
                                                              0, TEMPSUMMON_TIMED_DESPAWN, 30000)) {
                    creature->EnterVehicle(owner);
                    creature->CastSpell(creature, SPELL_BLOAT_TRIGGER_PERIODIC);
                    if(i == 0)
                        creature->SetFacingTo(owner->GetOrientation() + M_PI / 2.0f);
                    else
                        creature->SetFacingTo(owner->GetOrientation() - M_PI / 2.0f) ;
                }
            }
        }

        void Register() {
            AfterEffectApply += AuraEffectApplyFn(spell_yanzhu_bloat_AuraScript::HandleAfterEffectApply, EFFECT_1, SPELL_AURA_SET_VEHICLE_ID, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const {
        return new spell_yanzhu_bloat_AuraScript();
    }
};

class spell_yanzhu_bloat_damage_target_selector : public SpellScriptLoader {
public :
    spell_yanzhu_bloat_damage_target_selector() : SpellScriptLoader("spell_yanzhu_bloat_damage_target_selector") {

    }

    class spell_yanzhu_bloat_damage_target_selector_SpellScript : public SpellScript {
        PrepareSpellScript(spell_yanzhu_bloat_damage_target_selector_SpellScript);

        bool Validate(const SpellInfo *spellInfo) {
            return true ;
        }

        bool Load() {
            return true ;
        }

        void FilterTargets(std::list<WorldObject*>& targets) {
            if(!GetCaster() || !GetCaster()->GetVehicle() || !GetCaster()->GetVehicle()->GetBase())
                return ;

            // Must not target the vehicle
            targets.remove_if(YanZhu::IgnoreTargetPredicate(GetCaster()->GetVehicle()->GetBase()));
        }

        void Register() {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_yanzhu_bloat_damage_target_selector_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENTRY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_yanzhu_bloat_damage_target_selector_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_CONE_ENTRY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_yanzhu_bloat_damage_target_selector_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_CONE_ENTRY);
        }

    };

    SpellScript* GetSpellScript() const {
        return new spell_yanzhu_bloat_damage_target_selector_SpellScript();
    }
};

class spell_yanzhu_ferment : public SpellScriptLoader {
public :
    spell_yanzhu_ferment() : SpellScriptLoader("spell_yanzhu_ferment") {

    }

    class spell_yanzhu_ferment_SpellScript : public SpellScript {
        PrepareSpellScript(spell_yanzhu_ferment_SpellScript);

        bool Validate(const SpellInfo *spellInfo) {
            return sSpellMgr->GetSpellInfo(SPELL_FERMENT);
        }

        bool Load() {
            return (GetCaster() && GetCaster()->ToCreature());
        }

        void FilterTargets(WorldObject*& target) {
            Creature* caster = GetCaster()->ToCreature();
            
            Creature* yanZhu = caster->FindNearestCreature(BOSS_YAN_ZHU, 500.0f, true);
            if(yanZhu) {
                std::list<Player*> players ;
                GetPlayerListInGrid(players, caster, 500.0f);
                
                for(auto iter : players) {
                    if(iter->IsInBetween(yanZhu, caster)) {
                        target = iter ;
                        return ;
                    }
                }
                
                target = yanZhu ;
                return ;
            }
            
            target = caster ;
        }

        void Register() {
            OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_yanzhu_ferment_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_TARGET_ANY);
            OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_yanzhu_ferment_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_TARGET_ANY);
            OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_yanzhu_ferment_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_TARGET_ANY);
        }
    };

    SpellScript* GetSpellScript() const {
        return new spell_yanzhu_ferment_SpellScript();
    }
};

class spell_yanzhu_bubble_shield : public SpellScriptLoader {
public :
    spell_yanzhu_bubble_shield() : SpellScriptLoader("spell_yanzhu_bubble_shield") {

    }

    class spell_yanzhu_bubble_shield_SpellScript : public SpellScript {
        PrepareSpellScript(spell_yanzhu_bubble_shield_SpellScript);

        bool Validate(const SpellInfo *spellInfo) {
            return true ;
        }

        bool Load() {
            return true ;
        }

        void HandleAfterCast() {
            if(!GetCaster())
                return ;

            Unit* caster = GetCaster();

            for(uint8 i = 0 ; i < 8 ; ++i) {
                if(Creature* bubble = caster->SummonCreature(MOB_BUBBLE_SHIELD, caster->GetPositionX() + frand(0.0f, 3.0f), caster->GetPositionY() + frand(0.0f, 3.0f),
                                                             caster->GetPositionZ() + 7, 0, TEMPSUMMON_CORPSE_DESPAWN)) {
                    bubble->EnterVehicle(caster);
                    bubble->SetReactState(REACT_PASSIVE);
                }
            }
        }

        void Register() {
            AfterCast += SpellCastFn(spell_yanzhu_bubble_shield_SpellScript::HandleAfterCast);
        }
    };

    SpellScript* GetSpellScript() const {
        return new spell_yanzhu_bubble_shield_SpellScript();
    }
};

class spell_yanzhu_carbonation_target_selector : public SpellScriptLoader {
public :
    spell_yanzhu_carbonation_target_selector() : SpellScriptLoader("spell_yanzhu_carbonation_target_selector") {

    }

    class spell_yanzhu_carbonation_target_selector_SpellScript : public SpellScript {
        PrepareSpellScript(spell_yanzhu_carbonation_target_selector_SpellScript);

        bool Validate(const SpellInfo *spellInfo) {
            return true ;
        }

        bool Load() {
            return true ;
        }

        void FilterTargets(std::list<WorldObject*>& targets) {
            targets.remove_if(YanZhu::HeightCheckPredicate(GetCaster(), 2.5f));
        }

        void Register() {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_yanzhu_carbonation_target_selector_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_yanzhu_carbonation_target_selector_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const {
        return new spell_yanzhu_carbonation_target_selector_SpellScript();
    }
};

// Achievement 6456 - Heroic: Stormstout Brewery
class achievement_heroic_stormstout_brewery : public AchievementCriteriaScript
{
public:
    achievement_heroic_stormstout_brewery() : AchievementCriteriaScript("achievement_heroic_stormstout_brewery")
    {
        
    }
    
    bool OnCheck(Player *source, Unit *target)
    {
        if(target && target->GetMap()->GetDifficultyID() == DIFFICULTY_HEROIC)
            return true;
            
        return false;
    }
};


void AddSC_boss_yan_zhu_the_uncasked() {
    new boss_yan_zhu_the_uncasked();

    new mob_yeasty_brew_alamental_yan_zhu();

    new npc_fizzy_bubble();

    new spell_yanzhu_wall_of_suds();
    new spell_yanzhu_wall_of_suds_target_selector();
    new spell_yanzhu_blackout_brew();
    new spell_yanzhu_bloat();
    new spell_yanzhu_bloat_damage_target_selector();
    new spell_yanzhu_ferment();
    new spell_yanzhu_bubble_shield();
    new spell_yanzhu_carbonation_target_selector();
    
    new achievement_heroic_stormstout_brewery();
}

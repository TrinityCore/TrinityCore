#include "stormstout_brewery.h"
#include "MoveSplineInit.h"
#include "MoveSpline.h"
#include "PointMovementGenerator.h"

// #define RETURN_if (condition) if (!condition) return;

enum HoptallusSpells
{
    SPELL_FURLWIND      = 112992,
    SPELL_CARROT_BREATH = 112944
};

enum Events
{
    EVENT_SUMMON_VIRMEN = 1,
    EVENT_FURLWIND      = 2,
    EVENT_CARROT_BREATH = 3,
    EVENT_RESET_SPEED   = 4,
    EVENT_RESET_STALKER    = 5
};

enum Talk
{
    TALK_AGGRO          = 1,
    TALK_KILLED_PLAYER  = 2,
    TALK_FURLWIND       = 3,
    TALK_CARROT_BREATH  = 4,
    TALK_JUST_DIED      = 5,
    TALK_SUMMON_VIRMEN  = 6
};

enum Misc
{
    GOB_GIANT_BARREL            = 211138,
    NPC_CARROT_COLLECTOR        = 200505,
    NPC_CARROT_BREATH_HELPER    = 200504,
    MOB_BOPPER                  = 59551,
    MOB_HOPPER                  = 59464,
    MOB_HOPPLING                = 60208,
    NPC_BIG_OL_HAMMER           = 59539
};

#define MAX_SUMMON_VIRMEN 5
static const Position summonVirmenPosition[MAX_SUMMON_VIRMEN] =
{
    {-728.146240f, 1249.065796f, 164.800262f, 0.291780f},
    {-724.845337f, 1254.960938f, 164.800262f, 0.291780f},
    {-721.216980f, 1249.473389f, 164.800262f, 0.291780f},
    {-728.308960f, 1260.730957f, 164.800262f, 0.291780f},
    {-718.083557f, 1243.474976f, 164.800262f, 0.291780f},
};

static const Position jumpVirmenPosition[MAX_SUMMON_VIRMEN] =
{
    {-702.496643f, 1248.231689f, 162.794922f, 1.271960f},
    {-706.126038f, 1266.666748f, 162.779785f, 0.039670f},
    {-699.487671f, 1275.684326f, 162.770660f, 4.822747f},
    {-690.849060f, 1244.437622f, 162.794586f, 1.847660f},
    {-696.724609f, 1256.291992f, 162.785858f, 6.239606f}
};

static const Position jumpPosition = {-695.928467f, 1261.399414f, 162.780762f, 0.291780f};

class boss_hoptallus : public CreatureScript
{
public :
    boss_hoptallus() : CreatureScript("boss_hoptallus")
    {

    }

    class boss_hoptallusAI : public ScriptedAI
    {
    public :
        boss_hoptallusAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            m_bCanSearch = true;
        }

        void Reset()
        {
            if (instance)
                instance->SetData(INSTANCE_DATA_HOPTALLUS_STATUS, NOT_STARTED);
            events.Reset();
            ClearZone();
            m_uiSearchTimer = 500;
        }

        void DoAction(int32 action)
        {
            if (action == 0)
            {
                if (GameObject* go = me->FindNearestGameObject(GOB_GIANT_BARREL, 50000.0f))
                    go->SetGoState(GO_STATE_ACTIVE);
                me->GetMotionMaster()->MoveJump(jumpPosition, 10.0f, 10.0f);
                me->SetHomePosition(jumpPosition); // So it will not return into the barrel
            }
        }

        void EnterCombat(Unit *aggro)
        {
            if (instance)
            {
                instance->SetData(INSTANCE_DATA_HOPTALLUS_STATUS, IN_PROGRESS);
                if (GameObject* door = ObjectAccessor::GetGameObject(*me, instance->GetObjectGuid(instance->GetData64(INSTANCE_DATA64_HOPTALLUS_ENTRANCE_GUID))))
                    door->SetGoState(GO_STATE_READY);
            }
            events.ScheduleEvent(EVENT_SUMMON_VIRMEN, IsHeroic() ? urand(10000, 11000) : urand(12000, 14000));
            events.ScheduleEvent(EVENT_FURLWIND, IsHeroic() ? 6000 : 8000);
            events.ScheduleEvent(EVENT_CARROT_BREATH, IsHeroic() ? 25000 : 35000);

            Talk(TALK_AGGRO);
            DoZoneInCombat();
        }

        void EnterEvadeMode()
        {
            if (instance)
            {
                instance->SetData(INSTANCE_DATA_HOPTALLUS_STATUS, FAIL);
                if (GameObject* door = ObjectAccessor::GetGameObject(*me,instance->GetObjectGuid(instance->GetData64(INSTANCE_DATA64_HOPTALLUS_ENTRANCE_GUID))))
                    door->SetGoState(GO_STATE_ACTIVE);
            }
            
            ClearZone();

            ScriptedAI::EnterEvadeMode();
        }

        void JustDied(Unit *killer)
        {
            if (instance)
            {
                instance->SetData(INSTANCE_DATA_HOPTALLUS_STATUS, DONE);
                if (GameObject* entrance = ObjectAccessor::GetGameObject(*me,instance->GetObjectGuid(instance->GetData64(INSTANCE_DATA64_HOPTALLUS_ENTRANCE_GUID))))
                    entrance->SetGoState(GO_STATE_ACTIVE);
                if (GameObject* exit = ObjectAccessor::GetGameObject(*me, instance->GetObjectGuid(instance->GetData64(INSTANCE_DATA64_HOPTALLUS_EXIT_GUID))))
                    exit->RemoveFromWorld();
            }
            
            ClearZone();

            if (Creature* collector = me->SummonCreature(NPC_CARROT_COLLECTOR, -702.496643f, 1248.231689f, 162.794922f, 1.271960f))
                collector->AI()->DoAction(1);

            Talk(TALK_JUST_DIED);
        }

        void KilledUnit(Unit *killed)
        {
            Talk(TALK_KILLED_PLAYER);
        }
        
        void SearchForPlayers() 
        {           
            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 25.0f);
            
            if (playerList.empty())
            {
                m_uiSearchTimer = 500;
                return;
            }
            else
            {
                DoAction(0);
                m_bCanSearch = false;
                return;
            }
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim()) 
            {
                if (!m_bCanSearch)
                    return;
                    
                if (m_uiSearchTimer <= diff)
                {
                    SearchForPlayers();
                }
                else
                {
                    m_uiSearchTimer -= diff;
                }
                return;
            }
            
            // Orientation is locked while turning, so update it right here to handle target selection correctly
            if (m_bCarrotBreath) 
                me->SetOrientation(me->GetOrientation() + 2 * M_PI / 15000.0f * diff);

            events.Update(diff);

            while(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_SUMMON_VIRMEN :
                    if (m_uiSummonTimes == 0) 
                    {
                        Talk(TALK_SUMMON_VIRMEN);
                        DoCast(me, 114367, true);
                    }
                    
                    SummonVirmens();
                    ++m_uiSummonTimes;
                    if (m_uiSummonTimes < 3)
                    {
                        events.ScheduleEvent(EVENT_SUMMON_VIRMEN, 1000);
                    }
                    else
                    {
                        events.ScheduleEvent(EVENT_SUMMON_VIRMEN, IsHeroic() ? 10000 : 15000);
                        m_uiSummonTimes = 0;
                    }
                    break;

                case EVENT_FURLWIND :
                    if (me->HasUnitState(UNIT_STATE_CASTING))
                    {
                        events.ScheduleEvent(EVENT_FURLWIND, 100);
                        break;
                    }
                    Talk(TALK_FURLWIND);
                    DoCastAOE(SPELL_FURLWIND);
                    events.ScheduleEvent(EVENT_FURLWIND, IsHeroic() ? urand(12000, 14000) : urand(14000, 17000));
                    events.ScheduleEvent(EVENT_RESET_SPEED, 10000);
                    break;

                case EVENT_CARROT_BREATH :
                    if (me->HasUnitState(UNIT_STATE_CASTING)) 
                    {
                        events.ScheduleEvent(EVENT_CARROT_BREATH, 100);
                        break;
                    }
                    m_bCarrotBreath = true;
                    DoCastAOE(SPELL_CARROT_BREATH);
                    Talk(TALK_CARROT_BREATH);
                    events.RescheduleEvent(EVENT_FURLWIND, 17000);
                    events.ScheduleEvent(EVENT_CARROT_BREATH, IsHeroic() ? 25000 : 35000);
                    break;
                
                case EVENT_RESET_SPEED :
                    me->SetSpeed(MOVE_RUN, 7.0f);
                    me->GetMotionMaster()->MoveChase(me->GetVictim());
                    break;
                    
                default :
                    break;
                }
            }
            
            DoMeleeAttackIfReady();
        }

        void SummonVirmens() const
        {
            /*for (uint8 i = 0; i < 5; ++i)
            {
                const Position posSummon = summonVirmenPosition[urand(0, MAX_SUMMON_VIRMEN - 1)],
                        posJump = jumpVirmenPosition[urand(0, MAX_SUMMON_VIRMEN - 1)];

                uint32 entry = RAND<uint32>(MOB_HOPPER, MOB_HOPPLING, MOB_BOPPER);

                if (Creature* summon = me->SummonCreature(entry, posSummon))
                    summon->GetMotionMaster()->MoveJump(posJump, 8.0f, 8.0f);
            }*/
        }

    private :
        // Helper function to remove all the creatures
        inline void ClearZone() const
        {
            RemoveAllCreaturesInGridByEntry(MOB_HOPPER);
            RemoveAllCreaturesInGridByEntry(MOB_HOPPLING);
            RemoveAllCreaturesInGridByEntry(MOB_BOPPER);
        }
        
        // Remove all creatures of given entry that are in grid
        void RemoveAllCreaturesInGridByEntry(uint32 const& entry) const
        {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, entry, 50000.0f);
            
            if (creatures.empty())
                return;
                
            for (auto iter : creatures)
                iter->DisappearAndDie();
        }
        
    private:
        EventMap        events;
        InstanceScript* instance;
        
        uint32          m_uiSearchTimer;
        uint8           m_uiSummonTimes;
        bool            m_bCanSearch;
        bool            m_bCarrotBreath;
    };

    CreatureAI* GetAI(Creature *creature) const
    {
        return new boss_hoptallusAI(creature);
    }
};

class mob_virmen : public CreatureScript
{
public :
    mob_virmen() : CreatureScript("mob_virmen")
    {

    }

    class mob_virmenAI : public ScriptedAI
    {
    public :
        mob_virmenAI(Creature* creature) : ScriptedAI(creature)
        {

        }

        void Reset()
        {
            m_uiCheckTimer = 500;
        }

        void JustDied(Unit *killer)
        {
            if (me->GetEntry() == MOB_BOPPER)
            {
                Creature * hammer = me->SummonCreature(NPC_BIG_OL_HAMMER, *me, TEMPSUMMON_TIMED_DESPAWN, 20000);
                if (hammer)
                    hammer->CastSpell(hammer, 114533, true); // Light !
            }
        }

        void UpdateAI(uint32 diff)
        {
            if (me->GetEntry() == MOB_HOPPER)
            {
                if (m_uiCheckTimer <= diff)
                {
                    if (!DoCheckPlayers())
                        m_uiCheckTimer = 500;
                }
                else
                    m_uiCheckTimer -= diff;
            }
        }

        bool DoCheckPlayers()
        {            
            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 1.0f);
            
            if (playerList.empty())
            {
                return false;
            }
            else
            {
                if (Player *player = playerList.front())
                    DoCast(player, 114291);
                
                return true;
            }
        }

    private :
        uint32 m_uiCheckTimer;
    };

    CreatureAI* GetAI(Creature *creature) const
    {
        return new mob_virmenAI(creature);
    }
};

class npc_big_ol_hammer : public CreatureScript
{
public :
    npc_big_ol_hammer() : CreatureScript("npc_big_ol_hammer")
    {

    }

    bool OnGossipHello(Player *p, Creature *me)
    {
        if (!p->HasAura(111662))
        {
            p->CastSpell(p, 111662, true); // Need to fix handler of the aura asap
            me->Kill(me);
            return false;
        }

        return false;
    }
};

class stalker_carrot_breath : public CreatureScript
{
public :
    stalker_carrot_breath() : CreatureScript("stalker_carrot_breath")
    {

    }

    class stalker_carrot_breathAI : public ScriptedAI
    {
    public :
        stalker_carrot_breathAI(Creature* creature) : ScriptedAI(creature)
        {
            // Init
            m_uiId = 0;
            m_uiWaitTimer = 0;
            x = y = z = 0.0f;
            
            p_master = me->ToTempSummon()->GetSummoner();
            p_instance = p_master->GetInstanceScript();
            
            me->SetFacingToObject(p_master);
            me->SetTarget(p_master->GetGUID());
            angle = me->GetOrientation();
            
            // Positions
            rayon = me->GetExactDist2d(p_master->GetPositionX(), p_master->GetPositionY());
            center.Relocate(p_master->GetPositionX(), p_master->GetPositionY(), p_master->GetPositionZ());
            
            // Speed
            me->SetSpeed(MOVE_RUN, (2 * M_PI * rayon / 15.0f), true);
            me->SetSpeed(MOVE_FLIGHT, (2 * M_PI * rayon / 15.f) , true);
        }
        
        void UpdateAI(uint32 uiDiff)
        {
            m_uiWaitTimer += uiDiff;
            if (m_uiWaitTimer <= 2000)
                return;
                
            angle -= (2 * M_PI / 15000.0f) * uiDiff;
            
            x = p_master->GetPositionX() + rayon * cos(angle);
            y = p_master->GetPositionY() + rayon * sin(angle);
            z = p_master->GetPositionZ();
            ++m_uiId;
            
            me->GetMotionMaster()->MovePoint(m_uiId, x, y, z);
        }

    private :

        /// Used in MotionMaster, id of the point
        uint32 m_uiId;

        /// Coordinates
        float x, y, z;

        /// Pointer to the master
        Unit* p_master;

        /// Pointer to InstanceScript in case
        InstanceScript* p_instance;

        /// Distance from the caster
        float rayon;

        /// Angle
        float angle;

        /// Position of the master
        Position center;
        
        /// Enable timer
        uint32 m_uiWaitTimer;
    };

    CreatureAI* GetAI(Creature *creature) const
    {
        return new stalker_carrot_breathAI(creature);
    }
};

typedef boss_hoptallus::boss_hoptallusAI HoptallusAI;

class spell_hoptallus_carrot_breath : public SpellScriptLoader
{
public :
    spell_hoptallus_carrot_breath() : SpellScriptLoader("spell_hoptallus_carrot_breath")
    {

    }

    class spell_hoptallus_carrot_breath_AuraScript : public AuraScript 
    {
        PrepareAuraScript(spell_hoptallus_carrot_breath_AuraScript);
        
        void HandleApply(AuraEffect const* auraEff, AuraEffectHandleModes mode) 
        {
            if (!GetCaster())
                return;
                
            Unit* caster = GetCaster();
            
            if (TempSummon* summon = caster->SummonCreature(NPC_CARROT_BREATH_HELPER, 
                                                            caster->GetPositionX() + 30 * cos(caster->GetOrientation()),
                                                            caster->GetPositionY() + 30 * sin(caster->GetOrientation()),
                                                            caster->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 15000))
                caster->CastSpell(summon, 74758, true);
        }
        
        void Register() 
        {
            OnEffectApply += AuraEffectApplyFn(spell_hoptallus_carrot_breath_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };
    
    AuraScript* GetAuraScript() const 
    {
        return new spell_hoptallus_carrot_breath_AuraScript();
    }
};

class spell_hoptallus_explosive_brew_target_selector : public SpellScriptLoader 
{
public :
    spell_hoptallus_explosive_brew_target_selector() : SpellScriptLoader("spell_hoptallus_explosive_brew_target_selector") 
    {
    
    }
    
    class spell_hoptallus_explosive_brew_target_selector_SpellScript : public SpellScript 
    {
        PrepareSpellScript(spell_hoptallus_explosive_brew_target_selector_SpellScript);
        
        void FilterTargets(std::list<WorldObject*>& targets) 
        {
            if (!GetCaster())
                return;
                
            targets.clear();
            
            std::list<Player*> playerList;
            GetCaster()->GetPlayerListInGrid(playerList, 10.0f);
            
            for (Player *player : playerList)
                targets.push_back(player);
        }
        
        void Register() 
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hoptallus_explosive_brew_target_selector_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hoptallus_explosive_brew_target_selector_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };
    
    SpellScript* GetSpellScript() const 
    {
        return new spell_hoptallus_explosive_brew_target_selector_SpellScript();
    }
};

class spell_hoptallus_smash : public SpellScriptLoader 
{
public :
    spell_hoptallus_smash() : SpellScriptLoader("spell_hoptallus_smash") 
    {
    
    }
    
    class spell_hoptallus_smash_SpellScript : public SpellScript 
    {
        PrepareSpellScript(spell_hoptallus_smash_SpellScript);
        
        void HandleCast() 
        {
            if (!GetCaster() ||!GetCaster()->ToPlayer())
                return;
                
            Player* caster = GetCaster()->ToPlayer();
            if (Aura* aura = caster->GetAura(111662)) 
            {
                aura->GetEffect(0)->SetAmount(aura->GetEffect(0)->GetAmount() + 1);
                if (aura->GetEffect(0)->GetAmount() == 3)
                    aura->Remove();
            }
        }
        
        void FilterTargets_Effect0(std::list<WorldObject*>& targets) 
        {
            if (!GetCaster())
                return;
                
            targets.clear();
            std::list<Creature*> creatureTargets;
            
            GetCreatureListWithEntryInGrid(creatureTargets, GetCaster(), MOB_HOPPER, 6.0f);
            GetCreatureListWithEntryInGrid(creatureTargets, GetCaster(), MOB_HOPPLING, 6.0f);
            
            for (Creature *creature : creatureTargets)
                targets.push_back(creature);
        }
        
        void FilterTargets_Effect1(std::list<WorldObject*>& targets) 
        {
            if (!GetCaster())
                return;
                
            targets.clear();
            std::list<Creature*> creatureTargets;
            
            GetCreatureListWithEntryInGrid(creatureTargets, GetCaster(), MOB_BOPPER, 6.0f);
            
            for (Creature* creature: creatureTargets)
                targets.push_back(creature);
        }
        
        void HandleEffectHitTarget_Effect0(SpellEffIndex effIndex)
        {
            if (Creature *creature = GetHitCreature())
                creature->DealDamage(creature, creature->GetHealth());
        }
        
        void HandleEffectHitTarget_Effect1(SpellEffIndex effIndex)
        {
            if (Creature *creature = GetHitCreature())
                creature->DealDamage(creature, creature->GetMaxHealth() / 2);
        }
        
        void Register() 
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hoptallus_smash_SpellScript::FilterTargets_Effect0, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hoptallus_smash_SpellScript::FilterTargets_Effect1, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
            
            OnEffectHitTarget += SpellEffectFn(spell_hoptallus_smash_SpellScript::HandleEffectHitTarget_Effect0, EFFECT_0, SPELL_EFFECT_KNOCK_BACK);
            OnEffectHitTarget += SpellEffectFn(spell_hoptallus_smash_SpellScript::HandleEffectHitTarget_Effect1, EFFECT_1, SPELL_EFFECT_KNOCK_BACK);
            
            OnCast += SpellCastFn(spell_hoptallus_smash_SpellScript::HandleCast);
        }
    };
    
    SpellScript* GetSpellScript() const 
    {
        return new spell_hoptallus_smash_SpellScript();
    }
};

class spell_hoptallus_carrot_breath_periodic : public SpellScriptLoader 
{
public :
    spell_hoptallus_carrot_breath_periodic() : SpellScriptLoader("spell_hoptallus_carrot_breath_periodic") 
    {
        
    }
    
    class spell_hoptallus_carrot_breath_periodic_SpellScript : public SpellScript 
    {
        PrepareSpellScript(spell_hoptallus_carrot_breath_periodic_SpellScript)
        
        void FilterTargets(std::list<WorldObject*>& targets) 
        {
            targets.remove_if([this](const WorldObject *target) -> bool { return (!GetCaster()->HasInArc(M_PI/3.0f, target)) ; });
        }
        
        void Register() 
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hoptallus_carrot_breath_periodic_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENTRY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hoptallus_carrot_breath_periodic_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_CONE_ENTRY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_hoptallus_carrot_breath_periodic_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_CONE_ENTRY);
        }
    };
    
    SpellScript* GetSpellScript() const 
    {
        return new spell_hoptallus_carrot_breath_periodic_SpellScript();
    }
};

class spell_hoptallus_furlwind : public SpellScriptLoader 
{
public :
    spell_hoptallus_furlwind() : SpellScriptLoader("spell_hoptallus_furlwind") 
    {

    }

    class spell_hoptallus_furlwind_SpellScript : public SpellScript 
    {
        PrepareSpellScript(spell_hoptallus_furlwind_SpellScript);

        Unit* victim;

        void HandleAfterCast() 
        {
            Unit* caster = GetCaster();
            if (!caster) return;

            victim = caster->GetVictim();
            float x, y, z;
            if (victim) 
            {
                victim->GetPosition(x, y, z);
                caster->SetSpeed(MOVE_RUN, caster->GetSpeedRate(MOVE_RUN) * 2.5f);
                caster->GetMotionMaster()->MovePoint(0, x, y, z);
            }
            else
                caster->GetMotionMaster()->MoveRandom();
        }

        void Register() 
        {
            AfterCast += SpellCastFn(spell_hoptallus_furlwind_SpellScript::HandleAfterCast);
        }
    };
    
    SpellScript* GetSpellScript() const 
    {
        return new spell_hoptallus_furlwind_SpellScript();
    }
};

void AddSC_boss_hoptallus()
{
    new boss_hoptallus();
    new mob_virmen();
    new stalker_carrot_breath();
    new npc_big_ol_hammer();
    new spell_hoptallus_carrot_breath();
    new spell_hoptallus_carrot_breath_periodic();
    new spell_hoptallus_furlwind();
    new spell_hoptallus_smash();
    new spell_hoptallus_explosive_brew_target_selector();
}

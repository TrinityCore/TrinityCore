/*
    http://uwow.biz
    BrokenShore
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CreatureTextMgr.h"
#include "GameObjectAI.h"
#include "QuestData.h"
#include "ObjectVisitors.hpp" 

// + Smart: 122105 120515 118444 119130
// 119133, 118412, 121232, 118966, 121146, 118969, 118945
class npc_broken_shore_misc : public CreatureScript
{
public:
    npc_broken_shore_misc() : CreatureScript("npc_broken_shore_misc") { }
    
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_broken_shore_miscAI(creature);
    }
    
    struct npc_broken_shore_miscAI : ScriptedAI
    {
        npc_broken_shore_miscAI(Creature* creature) : ScriptedAI(creature) 
        {
            instance = me->GetInstanceScript();
            justSawByPlayer = false;  // if player didn't saw this npc, then npc is 'freezing'
        }
        
        EventMap events;
        InstanceScript* instance;
        FunctionProcessor _functions;
        bool justSawByPlayer;
        
        void Reset() override
        {
            events.Reset();
        }
        
        void EnterCombat(Unit* who) override
        {
            switch(me->GetEntry())
            {
                case 119133:
                    events.RescheduleEvent(EVENT_1, 6000); // 226063
                    DoCast(225184);
                    break;
                case 118412:
                    events.RescheduleEvent(EVENT_2, 2500); // 183108
                    events.RescheduleEvent(EVENT_3, 18000); // 183075
                    break;
                case 121232:
                    events.RescheduleEvent(EVENT_4, 2300); // 182856
                    events.RescheduleEvent(EVENT_5, 14000); // 182854 (friendly)
                    DoCast(79833);
                    break;
                case 118966:
                    events.RescheduleEvent(EVENT_6, 4000); // 190330
                    events.RescheduleEvent(EVENT_7, 35000); // 189804
                    events.RescheduleEvent(EVENT_8, 11000); // 190332
                    events.RescheduleEvent(EVENT_9, 14000); // 190331
                    break;
                case 121146:
                    events.RescheduleEvent(EVENT_10, 3000); // 183555
                    events.RescheduleEvent(EVENT_11, 13000); // 183553
                    events.RescheduleEvent(EVENT_12, 15000); // 183549 (friendly)
                    break;
                case 118969:
                    events.RescheduleEvent(EVENT_13, 7000); // 222971
                    events.RescheduleEvent(EVENT_14, 27000); // 223061
                    events.RescheduleEvent(EVENT_15, 21000); // 223109
                    events.RescheduleEvent(EVENT_16, 31000); // 223903
                    break;
                case 118945:
                    events.RescheduleEvent(EVENT_17, 4000); // 183894
                    events.RescheduleEvent(EVENT_18, 9000); // 183897
                    events.RescheduleEvent(EVENT_19, 39000); // 183898
                    events.RescheduleEvent(EVENT_20, 31000); // 190010
                    break;
                case 118444:
                    events.RescheduleEvent(EVENT_21, 3000); // 183108
                    events.RescheduleEvent(EVENT_22, 20000); // 13730
                    break;
            }
        }
        
        void EnterEvadeMode() override
        {            
            if (instance->getScenarionStep() == 1)
            {
                if (!DoFindAnyProblem())
                    me->GetMotionMaster()->MovePoint(1, me->GetPositionX() + irand(-10, 10), me->GetPositionY() + 10.0f, me->GetPositionZ());
            }
        }
        
        void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType dmgType) override
        {
            damage /= (11-(me->GetHealthPct()/10));
        }
        
        void MovementInform(uint32 type, uint32 id) override
        {
            me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
            if (type == WAYPOINT_MOTION_TYPE)
            {
                if (instance->getScenarionStep() == 3) // kill some npc after maiev
                    DoFindAnyProblem();
            }
            else if (type == POINT_MOTION_TYPE)
            {
                if (id ==  1)
                {
                    EnterEvadeMode();
                }
            }
        }
    
        void MoveInLineOfSight(Unit* who) override
        {  
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (!justSawByPlayer)
            {
                if (me->GetEntry() == 119133)
                    if (me->IsWithinDistInMap(who, 40.0f))
                        instance->onScenarionNextStep(20); // custom
                    else
                        return;
                
                justSawByPlayer = true;
                
                switch(instance->getScenarionStep())
                {
                    case 0:
                    case 1:
                    {
                        if (!DoFindAnyProblem())
                            me->GetMotionMaster()->MovePoint(1, me->GetPositionX() + irand(-10, 10), me->GetPositionY() + 10.0f, me->GetPositionZ());
                    }
                }
            }
        }
    
        void UpdateAI(uint32 diff) override
        {            
            if (me->HasUnitState(UNIT_STATE_STUNNED)) // need for this
                return;
                
            _functions.Update(diff);
            
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:   
                        DoCast(226063);
                        events.RescheduleEvent(EVENT_1, 6000); // 226063
                        break;
                    case EVENT_2:
                        DoCast(183108);
                        events.RescheduleEvent(EVENT_2, 2500); // 183108
                        break;
                    case EVENT_3:
                        DoCast(183075);
                        events.RescheduleEvent(EVENT_3, 18000); // 183075
                        break;
                    case EVENT_4:
                        DoCast(182856);
                        events.RescheduleEvent(EVENT_4, 2300); // 182856
                        break;
                    case EVENT_5:
                        if (Unit* target = FindNearestFriendlyUnit())
                            me->CastSpell(target, 182854);
                        events.RescheduleEvent(EVENT_5, 14000); // 182854 (friendly)
                        break;
                    case EVENT_6:
                        DoCast(190330);
                        events.RescheduleEvent(EVENT_6, 4000); // 190330
                        break;
                    case EVENT_7:
                        DoCast(189804);
                        events.RescheduleEvent(EVENT_7, 35000); // 189804
                        break;
                    case EVENT_8:
                        DoCast(190332);
                        events.RescheduleEvent(EVENT_8, 11000); // 190332
                        break;
                    case EVENT_9:
                        DoCast(190331);
                        events.RescheduleEvent(EVENT_9, 14000); // 190331
                        break;
                    case EVENT_10:
                        DoCast(183555);
                        events.RescheduleEvent(EVENT_10, 3000); // 183555
                        break;
                    case EVENT_11:
                        DoCast(183553);
                        events.RescheduleEvent(EVENT_11, 13000); // 183553
                        break;
                    case EVENT_12:
                        if (Unit* target = FindNearestFriendlyUnit())
                            me->CastSpell(target, 183549);
                        events.RescheduleEvent(EVENT_12, 15000); // 183549 (friendly)
                        break;
                    case EVENT_13:
                        DoCast(222971);
                        events.RescheduleEvent(EVENT_13, 7000); // 222971
                        break;
                    case EVENT_14:
                        DoCast(223061);
                        events.RescheduleEvent(EVENT_14, 27000); // 223061
                        break;
                    case EVENT_15:
                        DoCast(223109);
                        events.RescheduleEvent(EVENT_15, 21000); // 223109
                        break;
                    case EVENT_16:
                        DoCast(223903);
                        events.RescheduleEvent(EVENT_16, 31000); // 223903
                        break;
                    case EVENT_17:
                        DoCast(183894);
                        events.RescheduleEvent(EVENT_17, 4000); // 183894
                        break;
                    case EVENT_18:
                        DoCast(183897);
                        events.RescheduleEvent(EVENT_18, 9000); // 183897
                        break;
                    case EVENT_19:
                        DoCast(183898);
                        events.RescheduleEvent(EVENT_19, 39000); // 183898
                        break;
                    case EVENT_20:
                        DoCast(190010);
                        events.RescheduleEvent(EVENT_20, 31000); // 190010
                        break;
                    case EVENT_21:
                        DoCast(183108);
                        events.RescheduleEvent(EVENT_21, 3000); // 183108
                        break;
                    case EVENT_22:
                        DoCast(13730);
                        events.RescheduleEvent(EVENT_22, 20000); // 13730
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
        
        // custom functions
        
        bool DoFindAnyProblem()  // try to find any mobs and start attack this
        {
            std::list<Creature*> trash;
            GetCreatureListWithEntryInGrid(trash, me, 118416, 40.0f);
            GetCreatureListWithEntryInGrid(trash, me, 118456, 40.0f);
            GetCreatureListWithEntryInGrid(trash, me, 118457, 40.0f);
            GetCreatureListWithEntryInGrid(trash, me, 118886, 40.0f);
            GetCreatureListWithEntryInGrid(trash, me, 118453, 40.0f);
            GetCreatureListWithEntryInGrid(trash, me, 118654, 40.0f);
            
            GetCreatureListWithEntryInGrid(trash, me, 120511, 40.0f);
            GetCreatureListWithEntryInGrid(trash, me, 118711, 40.0f);
            GetCreatureListWithEntryInGrid(trash, me, 118644, 40.0f);
            GetCreatureListWithEntryInGrid(trash, me, 118647, 40.0f);
            GetCreatureListWithEntryInGrid(trash, me, 118645, 40.0f);
            GetCreatureListWithEntryInGrid(trash, me, 118656, 40.0f);
            GetCreatureListWithEntryInGrid(trash, me, 118655, 40.0f);
            GetCreatureListWithEntryInGrid(trash, me, 118708, 40.0f);
            GetCreatureListWithEntryInGrid(trash, me, 118658, 40.0f);
            GetCreatureListWithEntryInGrid(trash, me, 118563, 40.0f); 
            GetCreatureListWithEntryInGrid(trash, me, 118659, 40.0f);
            GetCreatureListWithEntryInGrid(trash, me, 118646, 40.0f);
            GetCreatureListWithEntryInGrid(trash, me, 118650, 40.0f);
            GetCreatureListWithEntryInGrid(trash, me, 118648, 40.0f);
            GetCreatureListWithEntryInGrid(trash, me, 118652, 40.0f);
            GetCreatureListWithEntryInGrid(trash, me, 118653, 40.0f);
            for (std::list<Creature*>::iterator itr = trash.begin(); itr != trash.end(); ++itr)
            {
                if ((*itr)->isAlive())
                {
                    AttackStart((*itr));
                    return true;
                }
            }
            return false;
        }
        
        Unit* FindNearestFriendlyUnit() // for healers
        {
            Unit* unit = NULL;
            Trinity::AnyFriendlyUnitInObjectRangeCheck u_check(me, me, 20);
            Trinity::UnitLastSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(me, unit, u_check);
            Trinity::VisitNearbyObject(me, 20, searcher);
            return unit;
        }
        
    };
};


// 118517
class npc_arcane_raven : public CreatureScript
{
public:
    npc_arcane_raven() : CreatureScript("npc_arcane_raven") {}

    struct npc_arcane_ravenAI : ScriptedAI
    {
        npc_arcane_ravenAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            SetFlyMode(true);
            summoner->CastSpell(me, 52391, true); //Ride Veh
        }
        
        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            bool isPlayer = who->IsPlayer();
            me->AddDelayedEvent(4000, [this, isPlayer]() -> void
            {
                if (isPlayer)
                    me->GetMotionMaster()->MovePath(11322708, false);
                else
                    me->GetMotionMaster()->MovePath(11322708, false, irand(-15, 15), irand(-15, 15));
            });
        }
        
        void MovementInform(uint32 moveType, uint32 pointId) override
        {
            if (moveType != WAYPOINT_MOTION_TYPE)
                return;

            if (pointId == 20 && me->GetAnyOwner())
            {
                if (me->GetAnyOwner()->IsPlayer())
                {
                    me->GetAnyOwner()->CreateConversation(4828);
                    me->GetAnyOwner()->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 56460);
                    if (Creature* infernal = me->SummonCreature(118416, me->GetPositionX() + 5, me->GetPositionY() + 5, me->GetPositionZ()))
                    {
                        infernal->CastSpell(infernal, 205266);
                        if (Creature* mag = infernal->FindNearestCreature(118412, 30.0f, true))
                        {
                            mag->CastSpell(mag, 46604);
                            mag->AI()->Talk(0);
                        }
                        infernal->CastSpell(infernal, 239649);
                    }
                }
                me->DespawnOrUnsummon(500);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_arcane_ravenAI(creature);
    }
};

// 118558 120743
class npc_bs_legion_portal : public CreatureScript
{
public:
    npc_bs_legion_portal() : CreatureScript("npc_bs_legion_portal") { }
    
    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bs_legion_portalAI(creature);
    }
    
    struct npc_bs_legion_portalAI : ScriptedAI
    {
        npc_bs_legion_portalAI(Creature* creature) : ScriptedAI(creature) 
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
        }

        void MoveInLineOfSight(Unit* who) override {}
        
        void OnSpellClick(Unit* clicker) override
        {
            if (!clicker->IsPlayer())
                return;
            
            me->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
            if (me->GetEntry() == 118558)
            {
                clicker->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT, 56778);
                // me->DespawnOrUnsummon(10);
            }
            else if (me->GetEntry() == 120743)
            {
                clicker->ToPlayer()->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 57574);
                me->RemoveAura(144373);
            }
        }

        void UpdateAI(uint32 diff) override {}
    };
};

// 267955
class go_bs_demoic_gates : public GameObjectScript
{
public:
    go_bs_demoic_gates() : GameObjectScript("go_bs_demoic_gates") { }

    struct go_bs_demoic_gatesAI : public GameObjectAI
    {
        go_bs_demoic_gatesAI(GameObject* go) : GameObjectAI(go){}


        bool GossipHello(Player* player) override
        {
            if (InstanceScript* instance = go->GetInstanceScript())
            {
                if (instance->getScenarionStep() < 5)
                    return false;
            }
            else
                return false;
            
            Map::PlayerList const &PlList = player->GetMap()->GetPlayers();

            if (PlList.isEmpty())
                return false;
            
            for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
                if (Player* pPlayer = i->getSource())
                {
                    pPlayer->CastSpell(pPlayer, 236671);
                    pPlayer->UpdateAchievementCriteria(CRITERIA_TYPE_USE_GAMEOBJECT, 267955);
                }
            return true;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_bs_demoic_gatesAI(go);
    }
};

class player_scripts_for_start_assault : public PlayerScript
{
    public:
        player_scripts_for_start_assault() : PlayerScript("player_scripts_for_start_assault") 
        {
            checktimer = 1000;
        }
        uint32 checktimer;
        
        void OnUpdate(Player* player, uint32 diff) override
        {
            if (checktimer <= diff)
            {
                if (player)
                    if (player->getLevel() == 110)
                        if (player->GetQuestStatus(46730) == QUEST_STATUS_NONE)
                        {
                            Quest const* quest = sQuestDataStore->GetQuestTemplate(46730);
                            if (quest)
                                if (player->CanAddQuest(quest, true))
                                    player->AddQuest(quest, NULL);
                        }
                    
                if (player->GetQuestStatus(46730) != QUEST_STATUS_REWARDED)
                    checktimer = 1000;
            }
            else
                checktimer -= diff;
        }

};


void AddSC_AssaultBrokenShore()
{
    new npc_broken_shore_misc();
    new npc_arcane_raven();
    new npc_bs_legion_portal();
    new go_bs_demoic_gates();
    new player_scripts_for_start_assault();
};
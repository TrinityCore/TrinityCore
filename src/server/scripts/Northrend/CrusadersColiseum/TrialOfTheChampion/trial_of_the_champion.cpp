/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Script updated by Fiveofeight
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

#include "ScriptPCH.h"
#include "trial_of_the_champion.h"
#include "Vehicle.h"
#include "Player.h"

#define GOSSIP_START_EVENT1     "I'm ready to start challenge."
#define GOSSIP_START_EVENT2     "I'm ready for the next challenge."

#define ORIENTATION             4.714f

/*######
## npc_herald_toc5
######*/

const Position SpawnPosition = {746.843f, 695.68f, 412.339f, 4.70776f};

const Position SpawnPosition1 = {746.71f, 661.02f, 411.69f, 4.66995f};

	
enum Texts
{
    // Starts when you enter toc
    SAY_INTRO_HERALD_1          = 0, 
    SAY_INTRO_HERALD_2          = 17,
    SAY_INTRO_HERALD_3          = 10,
    SAY_INTRO_HERALD_4          = 10,
    SAY_INTRO_HERALD_5          = 11,
    SAY_INTRO_HERALD_6          = 11,
    SAY_INTRO_HERALD_7          = 18,

    // Announcing the fighters
    SAY_WARRIOR_ENTERS          = 1,
    SAY_WARRIOR_CHEER           = 2,
    SAY_MAGE_ENTERS             = 3,
    SAY_MAGE_CHEER              = 4,
    SAY_SHAMAN_ENTERS           = 5,
    SAY_SHAMAN_CHEER            = 6,
    SAY_HUNTER_ENTERS           = 7,
    SAY_HUNTER_CHEER            = 8,
    SAY_ROGUE_ENTERS            = 9,
    SAY_ROGUE_CHEER             = 10,

    // Argent Champion
    SAY_ARGENT_CHAMP_ENTERS     = 19,
    SAY_PALETRESS_INTRO_1       = 11,
    SAY_PALETRESS_INTRO_2       = 12,
    SAY_PALETRESS_INTRO_3       = 0,
    SAY_PALETRESS_INTRO_4       = 1,
    SAY_EADRIC_INTRO_1          = 13,
    SAY_EADRIC_INTRO_2          = 14,
    SAY_EADRIC_INTRO_3          = 0,

    // Black Knight
    SAY_INTRO_BLACK_KNIGHT_TIRION   = 21,
    SAY_HERALD_RAFTERS          = 15,
    SAY_OUTRO_1_TIRION          = 23,
    SAY_OUTRO_2_TIRION          = 24,
    SAY_OUTRO_3_ALLY            = 13,
    SAY_OUTRO_3_HORDE           = 12,
};

enum Gossip
{
    GOSSIP_NOT_MOUNTED_A  = 14757,
    GOSSIP_NOT_MOUNTED_H  = 15043,
};

enum Events
{
    EVENT_INTRO_1               = 0,
    EVENT_INTRO_2               = 1,
    EVENT_INTRO_3               = 2,
    EVENT_INTRO_4               = 3,
    EVENT_INTRO_5               = 4,
    EVENT_INTRO_6               = 5,
    EVENT_INTRO_7               = 6,
    EVENT_INTRO_8               = 7,
    EVENT_SUMMON_FACTION_2      = 8,
    EVENT_SUMMON_FACTION_3      = 9,
    EVENT_AGGRO_FACTION         = 10,
    EVENT_PALETRESS_1           = 11,
    EVENT_PALETRESS_2           = 12,
    EVENT_PALETRESS_3           = 13,
    EVENT_EADRIC_1              = 14,
    EVENT_EADRIC_2              = 15,
    EVENT_OUTRO_1               = 16,
    EVENT_OUTRO_2               = 17,
    EVENT_OUTRO_3               = 18,
};

enum Phases
{
    PHASE_INTRO                 = 1,
    PHASE_INPROGRESS            = 2,

    PHASE_INTRO_MASK            = 1 << PHASE_INTRO,
    PHASE_INPROGRESS_MASK       = 2 << PHASE_INPROGRESS,
};

enum Spells
{
    SPELL_FACE_BLACKKNIGHT                = 67482,
    SPELL_HERALD_ARGENT                   = 64787,
};

class npc_herald_toc5 : public CreatureScript
{
    public:
        npc_herald_toc5(): CreatureScript("npc_herald_toc5") {}

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF+1)
        {
            player->CLOSE_GOSSIP_MENU();
            CAST_AI(npc_herald_toc5::npc_herald_toc5AI, creature->AI())->StartEncounter();
        }

        return true;
    }
        
    bool OnGossipHello(Player* player, Creature* creature)
    {
        InstanceScript* instance = creature->GetInstanceScript();

        if (!player->GetVehicle() && instance->GetData(BOSS_GRAND_CHAMPIONS) == NOT_STARTED)
        {
            if (instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                player->SEND_GOSSIP_MENU(GOSSIP_NOT_MOUNTED_H, creature->GetGUID());
            else
                player->SEND_GOSSIP_MENU(GOSSIP_NOT_MOUNTED_A, creature->GetGUID());

            return true;
        }

        else
        {
            if (instance &&
                instance->GetData(BOSS_GRAND_CHAMPIONS) == DONE &&
                instance->GetData(BOSS_BLACK_KNIGHT) == DONE &&
                (instance->GetData(BOSS_ARGENT_CHALLENGE_E) == DONE ||
                instance->GetData(BOSS_ARGENT_CHALLENGE_P) == DONE))

                return false;

            if (instance &&
                instance->GetData(BOSS_GRAND_CHAMPIONS) == NOT_STARTED &&
                instance->GetData(BOSS_ARGENT_CHALLENGE_E) == NOT_STARTED &&
                instance->GetData(BOSS_ARGENT_CHALLENGE_P) == NOT_STARTED &&
                instance->GetData(BOSS_BLACK_KNIGHT) == NOT_STARTED)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_START_EVENT1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            else if (instance)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_START_EVENT2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
    
            player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
    
            return true;
        }
    }

    struct npc_herald_toc5AI : public ScriptedAI
    {
        npc_herald_toc5AI(Creature *creature) : ScriptedAI(creature)	
        {
            instance = creature->GetInstanceScript();

            _introDone = false;
            uiSummonTimes = 0;
            uiPosition = 0;
            uiLesserChampions = 0;

            uiFirstBoss = 0;
            uiSecondBoss = 0;
            uiThirdBoss = 0;

            ArgentChampion = 0;

            uiVehicle1GUID = 0;
            uiVehicle2GUID = 0;
            uiVehicle3GUID = 0;

            Champion1List.clear();
            Champion2List.clear();
            Champion3List.clear();
    	
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            SetGrandChampionsForEncounter();
            SetArgentChampion();
        }

        EventMap events;
        InstanceScript* instance;
        Creature* vehicle_black_knight;

        uint8 uiSummonTimes;
        uint8 uiPosition;
        uint8 uiLesserChampions;
        uint8 uiIntroPhase;

        uint32 ArgentChampion;
        uint32 uiFirstBoss;
        uint32 uiSecondBoss;
        uint32 uiThirdBoss;

        uint64 thrallGUID;	
        uint64 garroshGUID;	
        uint64 varianGUID;	
        uint64 proudmooreGUID;	
        uint64 tirionGUID;

        uint64 BlackKnightGUID;
        uint64 uiVehicle1GUID;
        uint64 uiVehicle2GUID;
        uint64 uiVehicle3GUID;
        uint64 GrandChampionBoss;

        std::list<uint64> Champion1List;
        std::list<uint64> Champion2List;
        std::list<uint64> Champion3List;

        bool _introDone;
    	
        void Reset()
        {
            _introDone = false;
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (!_introDone && me->IsWithinDistInMap(who, 75.0f))
            {
                _introDone = true;
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                
                events.SetPhase(PHASE_INTRO);
                events.ScheduleEvent(EVENT_INTRO_1, 10000, 0, PHASE_INTRO);

                if (Creature* Thrall = me->SummonCreature(NPC_THRALL, 685.569f, 615.103f, 435.396f, 6.23544f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000))
                {
                    thrallGUID = Thrall->GetGUID();
    			    Thrall->SetReactState(REACT_PASSIVE);	
                    Thrall->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
                if (Creature* Garrosh = me->SummonCreature(NPC_GARROSH, 685.7f, 621.134f, 435.396f, 6.259f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000))
                {
                    garroshGUID = Garrosh->GetGUID();
                    Garrosh->SetReactState(REACT_PASSIVE);	
                    Garrosh->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
                if (Creature* Varian = me->SummonCreature(NPC_VARIAN, 807.724f, 617.9f, 435.396f, 3.18416f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000))
                {
                    varianGUID = Varian->GetGUID();
                    Varian->SetReactState(REACT_PASSIVE);	
                    Varian->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
                if (Creature* Proudmoore = me->SummonCreature(NPC_JAINA_PROUDMOORE, 807.401f, 613.667f, 435.397f, 3.0585f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000))
                {
                    proudmooreGUID = Proudmoore->GetGUID();
                    Proudmoore->SetReactState(REACT_PASSIVE);	
                    Proudmoore->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
                if (Creature* Tirion = me->SummonCreature(NPC_HIGHLORD, 746.482f, 556.857f, 435.396f, 1.5898f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000))
                {
                    tirionGUID = Tirion->GetGUID();
                    Tirion->SetReactState(REACT_PASSIVE);	
                    Tirion->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
            }
        }

        void SetData(uint32 uiType, uint32 /*uiData*/)
        {
            switch (uiType)
            {
                case DATA_START:
                    if (GameObject* pGO = GameObject::GetGameObject(*me, instance->GetData64(DATA_MAIN_GATE)))
                        instance->HandleGameObject(pGO->GetGUID(),true);
			        if (GameObject* pGO = GameObject::GetGameObject(*me, instance->GetData64(DATA_MAIN_GATE1)))
                        instance->HandleGameObject(pGO->GetGUID(),false);			
                    DoSummonGrandChampion(uiFirstBoss);
    				
				    events.ScheduleEvent(EVENT_SUMMON_FACTION_2, 10000, 0, PHASE_INPROGRESS);
                    break;
                case DATA_IN_POSITION: //movement done.		
		            me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);			
                    me->GetMotionMaster()->MovePoint(1, 735.898f, 651.961f, 411.93f);
                    if (GameObject* pGO = GameObject::GetGameObject(*me, instance->GetData64(DATA_MAIN_GATE)))
                        instance->HandleGameObject(pGO->GetGUID(),false);
                    events.ScheduleEvent(EVENT_AGGRO_FACTION, 15000, 0, PHASE_INPROGRESS);
                    break;
                case DATA_LESSER_CHAMPIONS_DEFEATED:
                {
                    ++uiLesserChampions;
                    std::list<uint64> TempList;
                    if (uiLesserChampions == 3 || uiLesserChampions == 6)
                    {
                        switch(uiLesserChampions)
                        {
                            case 3:
                                TempList = Champion2List;
                                break;
                            case 6:
                                TempList = Champion3List;
                                break;
                        }

                        for(std::list<uint64>::const_iterator itr = TempList.begin(); itr != TempList.end(); ++itr)
                            if (Creature* summon = Unit::GetCreature(*me, *itr))
                                AggroAllPlayers(summon);
                    }else if (uiLesserChampions == 9)
                        StartGrandChampionsAttack();

                    break;
                }
            }
        }

        void StartGrandChampionsAttack()
        {
		    //qui se nn si sta attenti con i guid nn aggrano
            Creature* pGrandChampion1 = Unit::GetCreature(*me, uiVehicle1GUID);
            Creature* pGrandChampion2 = Unit::GetCreature(*me, uiVehicle2GUID);
            Creature* pGrandChampion3 = Unit::GetCreature(*me, uiVehicle3GUID);

            if (pGrandChampion1 && pGrandChampion2 && pGrandChampion3)
            {
                AggroAllPlayers(pGrandChampion1);
                AggroAllPlayers(pGrandChampion2);
                AggroAllPlayers(pGrandChampion3);
            }
        }

        void MovementInform(uint32 uiType, uint32 uiPointId)
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            if (uiPointId == 1)
            {
                me->SetOrientation(ORIENTATION);
                me->SendMovementFlagUpdate();
            }
        }

        void JustSummoned(Creature* summon)
        {
            if (instance && instance->GetData(BOSS_GRAND_CHAMPIONS) == NOT_STARTED)
            {
                summon->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
                summon->SetReactState(REACT_PASSIVE);
            }
        }

        void SummonedCreatureDespawn(Creature* summon)
        {
            switch(summon->GetEntry())
            {
                case VEHICLE_DARNASSIA_NIGHTSABER:
                case VEHICLE_EXODAR_ELEKK:
                case VEHICLE_STORMWIND_STEED:
                case VEHICLE_GNOMEREGAN_MECHANOSTRIDER:
                case VEHICLE_IRONFORGE_RAM:
                case VEHICLE_FORSAKE_WARHORSE:
                case VEHICLE_THUNDER_BLUFF_KODO:
                case VEHICLE_ORGRIMMAR_WOLF:
                case VEHICLE_SILVERMOON_HAWKSTRIDER:
                case VEHICLE_DARKSPEAR_RAPTOR:
                    me->AI()->SetData(DATA_LESSER_CHAMPIONS_DEFEATED,0);
                    break;
            }
        }
        
        void DoSummonGrandChampion(uint32 uiBoss)
        {
            ++uiSummonTimes;
            uint32 VEHICLE_TO_SUMMON1 = 0;
            uint32 VEHICLE_TO_SUMMON2 = 0;
            switch(uiBoss)
            {
                case 0:
                    Talk(SAY_WARRIOR_ENTERS);
                    Talk(SAY_WARRIOR_CHEER);
                    VEHICLE_TO_SUMMON1 = VEHICLE_MOKRA_SKILLCRUSHER_MOUNT;
                    VEHICLE_TO_SUMMON2 = VEHICLE_ORGRIMMAR_WOLF;
				    break;
                case 1:
                    Talk(SAY_MAGE_ENTERS);
                    Talk(SAY_MAGE_CHEER);
                    VEHICLE_TO_SUMMON1 = VEHICLE_ERESSEA_DAWNSINGER_MOUNT;
                    VEHICLE_TO_SUMMON2 = VEHICLE_SILVERMOON_HAWKSTRIDER;
				    break;
                case 2:
                    Talk(SAY_SHAMAN_ENTERS);
                    Talk(SAY_SHAMAN_CHEER);
                    VEHICLE_TO_SUMMON1 = VEHICLE_RUNOK_WILDMANE_MOUNT;
                    VEHICLE_TO_SUMMON2 = VEHICLE_THUNDER_BLUFF_KODO;
				    break;
                case 3:
                    Talk(SAY_HUNTER_ENTERS);
                    Talk(SAY_HUNTER_CHEER);
                    VEHICLE_TO_SUMMON1 = VEHICLE_ZUL_TORE_MOUNT;
                    VEHICLE_TO_SUMMON2 = VEHICLE_DARKSPEAR_RAPTOR;
			        break;
                case 4:
                    Talk(SAY_ROGUE_ENTERS);
                    Talk(SAY_ROGUE_CHEER);
                    VEHICLE_TO_SUMMON1 = VEHICLE_DEATHSTALKER_VESCERI_MOUNT;
                    VEHICLE_TO_SUMMON2 = VEHICLE_FORSAKE_WARHORSE;
                    break;
                default:
                    return;
            }

            if (Creature* pBoss = me->SummonCreature(VEHICLE_TO_SUMMON1,SpawnPosition))
            {
                switch(uiSummonTimes)
                {
                    case 1:
                    {
                        uiVehicle1GUID = pBoss->GetGUID();
                        uint64 uiGrandChampionBoss1 = 0;
                        if (Creature* pBoss = Unit::GetCreature(*me, uiVehicle1GUID))
                            if (Vehicle* pVehicle = pBoss->GetVehicleKit())
                                if (Unit* pUnit = pVehicle->GetPassenger(0))
                                    uiGrandChampionBoss1 = pUnit->GetGUID();
                        if (instance)
                        {
                            instance->SetData64(DATA_GRAND_CHAMPION_VEHICLE_1,uiVehicle1GUID);
                            instance->SetData64(DATA_GRAND_CHAMPION_1,uiGrandChampionBoss1);
                        }
                        pBoss->AI()->SetData(1,0);
                        break;
                    }
                    case 2:
                    {
                        uiVehicle2GUID = pBoss->GetGUID();
                        uint64 uiGrandChampionBoss2 = 0;
                        if (Creature* pBoss = Unit::GetCreature(*me, uiVehicle2GUID))
                            if (Vehicle* pVehicle = pBoss->GetVehicleKit())
                                if (Unit* pUnit = pVehicle->GetPassenger(0))
                                    uiGrandChampionBoss2 = pUnit->GetGUID();
                        if (instance)
                        {
                            instance->SetData64(DATA_GRAND_CHAMPION_VEHICLE_2,uiVehicle2GUID);
                            instance->SetData64(DATA_GRAND_CHAMPION_2,uiGrandChampionBoss2);
                        }
                        pBoss->AI()->SetData(2,0);
                        break;
                    }
                    case 3:					
                    {
                        uiVehicle3GUID = pBoss->GetGUID();
                        uint64 uiGrandChampionBoss3 = 0;
                        if (Creature* pBoss = Unit::GetCreature(*me, uiVehicle3GUID))
                            if (Vehicle* pVehicle = pBoss->GetVehicleKit())
                                if (Unit* pUnit = pVehicle->GetPassenger(0))
                                    uiGrandChampionBoss3 = pUnit->GetGUID();
                        if (instance)
                        {
                            instance->SetData64(DATA_GRAND_CHAMPION_VEHICLE_3,uiVehicle3GUID);
                            instance->SetData64(DATA_GRAND_CHAMPION_3,uiGrandChampionBoss3);
                        }
                        pBoss->AI()->SetData(3,0);
                        break;
                    }
                    default:
                        return;
                }

                for (uint8 i = 0; i < 3; ++i)
                {
                    if (Creature* pAdd = me->SummonCreature(VEHICLE_TO_SUMMON2,SpawnPosition,TEMPSUMMON_CORPSE_DESPAWN))
                    {			
                        switch(uiSummonTimes)
                        {
                            case 1:
                                Champion1List.push_back(pAdd->GetGUID());
                                break;
                            case 2:
                                Champion2List.push_back(pAdd->GetGUID());
                                break;
                            case 3:
                                Champion3List.push_back(pAdd->GetGUID());
                                break;
                        }

                        switch(i)
                        {
                            case 0:
                                pAdd->GetMotionMaster()->MoveFollow(pBoss,2.5f,M_PI);
                                break;
                            case 1:
                                pAdd->GetMotionMaster()->MoveFollow(pBoss,2.5f,M_PI / 2);
                                break;
                            case 2:
                                pAdd->GetMotionMaster()->MoveFollow(pBoss,2.5f,M_PI / 2 + M_PI);
                                break;
                        }
                    }

                }
            }
        }

        void DoStartArgentChampionEncounter()
        {
            if (Creature* tirion = Unit::GetCreature(*me, instance->GetData64(DATA_HIGHLORD)))
                tirion->AI()->Talk(SAY_ARGENT_CHAMP_ENTERS);

            if (ArgentChampion == NPC_PALETRESS)
                events.ScheduleEvent(EVENT_PALETRESS_1, 5000);
            else
                events.ScheduleEvent(EVENT_EADRIC_1, 5000);

            if (Creature* pBoss = me->SummonCreature(ArgentChampion,SpawnPosition))
            {
		        pBoss->GetMotionMaster()->MovePoint(1,746.71f,661.02f,411.69f);
                for (uint8 i = 0; i < 3; ++i)
                {
                    if (Creature* pTrash = me->SummonCreature(NPC_ARGENT_LIGHWIELDER,SpawnPosition))
                        pTrash->AI()->SetData(i,0);
                    if (Creature* pTrash = me->SummonCreature(NPC_ARGENT_MONK,SpawnPosition))
                        pTrash->AI()->SetData(i,0);
                    if (Creature* pTrash = me->SummonCreature(NPC_PRIESTESS,SpawnPosition))
                        pTrash->AI()->SetData(i,0);
                }
            }
        }

		void EnterCombat(Unit* /*who*/)
        {
		    me->SetReactState(REACT_PASSIVE);
            if (Creature* pGhoul = me->SummonCreature(NPC_RISEN_JAEREN,742.835f, 639.134f, 411.571f, 1.05731f))
            {
                pGhoul->setFaction(14);
            }
				    if (instance)
                instance->SetData(DATA_AGRO_DONE,DONE);
    		
        }
    	
        void SetGrandChampionsForEncounter()
        {
            uiFirstBoss = urand(0,4);

            while(uiSecondBoss == uiFirstBoss || uiThirdBoss == uiFirstBoss || uiThirdBoss == uiSecondBoss)
            {
                uiSecondBoss = urand(0,4);
                uiThirdBoss = urand(0,4);
            }
        }

        void SetArgentChampion()
        {
           uint8 uiTempBoss = urand(0,1);

           switch(uiTempBoss)
           {
                case 0:
                    ArgentChampion = NPC_EADRIC;
                    break;
                case 1:
                    ArgentChampion = NPC_PALETRESS;
                    break;
           }
        }

        void StartEncounter()
        {
            if (!instance)
                return;

            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                if (GameObject* pGO = GameObject::GetGameObject(*me, instance->GetData64(DATA_MAIN_GATE1)))
                        instance->HandleGameObject(pGO->GetGUID(),false);

            if (instance->GetData(BOSS_BLACK_KNIGHT) == NOT_STARTED)
            {
                if (instance->GetData(BOSS_ARGENT_CHALLENGE_E) == NOT_STARTED && instance->GetData(BOSS_ARGENT_CHALLENGE_P) == NOT_STARTED)
                {
                    if (instance->GetData(BOSS_GRAND_CHAMPIONS) == NOT_STARTED)
                        me->AI()->SetData(DATA_START,NOT_STARTED);

                    if (instance->GetData(BOSS_GRAND_CHAMPIONS) == DONE)
                        DoStartArgentChampionEncounter();
                }

               if (instance->GetData(BOSS_GRAND_CHAMPIONS) == DONE && (instance->GetData(BOSS_ARGENT_CHALLENGE_E) == DONE || instance->GetData(BOSS_ARGENT_CHALLENGE_P) == DONE))
                {
			        me->SummonCreature(VEHICLE_BLACK_KNIGHT, 801.369507f, 640.574280f, 469.314362f, 3.97124f);

    				me->RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
    				me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
    				me->SetReactState(REACT_AGGRESSIVE);
                    if (Creature* tirion = me->GetCreature(*me, tirionGUID))
                       tirion->AI()->Talk(SAY_INTRO_BLACK_KNIGHT_TIRION);

    				Talk(SAY_HERALD_RAFTERS);
		        }
            }
        }

        void AggroAllPlayers(Creature* pTemp)
        {
            Map::PlayerList const &PlList = me->GetMap()->GetPlayers();

            if(PlList.isEmpty())
                return;

            for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
            {
                if(Player* player = i->getSource())
                {
                    if(player->isGameMaster())
                        continue;

                    if(player->isAlive())
                    {
                        pTemp->SetHomePosition(me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),me->GetOrientation());
                        pTemp->RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE);
                        pTemp->SetReactState(REACT_AGGRESSIVE);
                        pTemp->SetInCombatWith(player);
                        player->SetInCombatWith(pTemp);
                        pTemp->AddThreat(player, 0.0f);
                    }
                }
            }
        }

        void DoAction(int32 const action)
        {
            switch (action)
            {
                case ACTION_OUTRO:
                    events.ScheduleEvent(EVENT_OUTRO_1, 4000);
                    break;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if(!(thrallGUID || garroshGUID || varianGUID || proudmooreGUID || tirionGUID))
                return;
                
            events.Update(diff);
                
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_INTRO_1:
                        instance->DoCastSpellOnPlayers(SPELL_HERALD_ARGENT);
                        Talk(SAY_INTRO_HERALD_1);
                        events.ScheduleEvent(EVENT_INTRO_2, 5000, 0, PHASE_INTRO);
                        break;
                    case EVENT_INTRO_2:
                        Talk(SAY_INTRO_HERALD_2);
                        events.ScheduleEvent(EVENT_INTRO_3, 13000, 0, PHASE_INTRO);
                        break;
                    case EVENT_INTRO_3:
                        if (instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                            if (Creature* thrall = me->GetCreature(*me, thrallGUID))
                                thrall->AI()->Talk(SAY_INTRO_HERALD_3);
                        else
                            if (Creature* varian = me->GetCreature(*me, varianGUID))
                                varian->AI()->Talk(SAY_INTRO_HERALD_3);
                                
                        events.ScheduleEvent(EVENT_INTRO_4, 4000, 0, PHASE_INTRO);
                        break;
                    case EVENT_INTRO_4:
                        if (instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                            if (Creature* garrosh = me->GetCreature(*me, garroshGUID))
                                garrosh->AI()->Talk(SAY_INTRO_HERALD_4);
                        else
                            if (Creature* proudmoore = me->GetCreature(*me, proudmooreGUID))
                                proudmoore->AI()->Talk(SAY_INTRO_HERALD_4);
                                
                        events.ScheduleEvent(EVENT_INTRO_5, 4000, 0, PHASE_INTRO);
                        break;
                    case EVENT_INTRO_5:
                        if (instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                            if (Creature* varian = me->GetCreature(*me, varianGUID))
                                varian->AI()->Talk(SAY_INTRO_HERALD_5);
                        else
                            if (Creature* garrosh = me->GetCreature(*me, garroshGUID))
                                garrosh->AI()->Talk(SAY_INTRO_HERALD_5);
                                
                        events.ScheduleEvent(EVENT_INTRO_6, 6000, 0, PHASE_INTRO);
                        break;
                    case EVENT_INTRO_6:
                        if (instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                            if (Creature* proudmoore = me->GetCreature(*me, proudmooreGUID))
                                proudmoore->AI()->Talk(SAY_INTRO_HERALD_6);
                        else
                            if (Creature* thrall = me->GetCreature(*me, thrallGUID))
                                thrall->AI()->Talk(SAY_INTRO_HERALD_6);
                                
                        events.ScheduleEvent(EVENT_INTRO_7, 6000, 0, PHASE_INTRO);
                        break;
                    case EVENT_INTRO_7:
                        if (Creature* tirion = me->GetCreature(*me, tirionGUID))
                            tirion->AI()->Talk(SAY_INTRO_HERALD_7);
                                
                        events.ScheduleEvent(EVENT_INTRO_8, 1000, 0, PHASE_INTRO);
                        break;
                    case EVENT_INTRO_8:
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        events.SetPhase(PHASE_INPROGRESS);
                        break;
                    case EVENT_SUMMON_FACTION_2:
                        DoSummonGrandChampion(uiSecondBoss);
                        events.ScheduleEvent(EVENT_SUMMON_FACTION_3, 10000, 0, PHASE_INPROGRESS);
                        break;
                    case EVENT_SUMMON_FACTION_3:
                        DoSummonGrandChampion(uiThirdBoss);
                        break;
                    case EVENT_AGGRO_FACTION:
                        if (!Champion1List.empty())
                        {
                            for(std::list<uint64>::const_iterator itr = Champion1List.begin(); itr != Champion1List.end(); ++itr)
                                if (Creature* summon = Unit::GetCreature(*me, *itr))
                                    AggroAllPlayers(summon);
                        }
                        break;
                    case EVENT_PALETRESS_1:
                        Talk(SAY_PALETRESS_INTRO_1);
                        Talk(SAY_PALETRESS_INTRO_2);
                        events.ScheduleEvent(EVENT_PALETRESS_2, 5000, 0, PHASE_INPROGRESS);
                        break;
                    case EVENT_PALETRESS_2:
                        if (Creature* argentchamp = Unit::GetCreature(*me, instance->GetData64(DATA_ARGENT_CHAMPION)))
                            argentchamp->AI()->Talk(SAY_PALETRESS_INTRO_3);

                        events.ScheduleEvent(EVENT_PALETRESS_3, 5000);
                    case EVENT_PALETRESS_3:
                        if (Creature* argentchamp = Unit::GetCreature(*me, instance->GetData64(DATA_ARGENT_CHAMPION)))
                            argentchamp->AI()->Talk(SAY_PALETRESS_INTRO_4);
                        break;
                    case EVENT_EADRIC_1:
                        Talk(SAY_EADRIC_INTRO_1);
                        Talk(SAY_EADRIC_INTRO_2);
                        events.ScheduleEvent(EVENT_EADRIC_2, 5000);
                        break;
                    case EVENT_EADRIC_2:
                        if (Creature* argentchamp = Unit::GetCreature(*me, instance->GetData64(DATA_ARGENT_CHAMPION)))
                            argentchamp->AI()->Talk(SAY_EADRIC_INTRO_3);
                        break;
                    case EVENT_OUTRO_1:
                        if (Creature* tirion = Unit::GetCreature(*me, instance->GetData64(DATA_HIGHLORD)))
                            tirion->AI()->Talk(SAY_OUTRO_1_TIRION);

                        events.ScheduleEvent(EVENT_OUTRO_2, 5000);
                        break;
                    case EVENT_OUTRO_2:
                        if (Creature* tirion = Unit::GetCreature(*me, instance->GetData64(DATA_HIGHLORD)))
                            tirion->AI()->Talk(SAY_OUTRO_2_TIRION);

                        events.ScheduleEvent(EVENT_OUTRO_3, 5000);
                        break;
                    case EVENT_OUTRO_3:
                        if (instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                            if (Creature* thrall = me->GetCreature(*me, thrallGUID))
                                thrall->AI()->Talk(SAY_OUTRO_3_HORDE);

                        else
                            if (Creature* varian = me->GetCreature(*me, varianGUID))
                                varian->AI()->Talk(SAY_OUTRO_3_ALLY);
                        break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_herald_toc5AI (creature);
    };
};

void AddSC_trial_of_the_champion()
{
    new npc_herald_toc5();
}

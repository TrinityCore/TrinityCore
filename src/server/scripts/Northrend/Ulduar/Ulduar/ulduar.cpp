/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "ScriptedEscortAI.h"
#include "ulduar.h"

// npc lore keeper
#define GOSSIP_ITEM_1  "Activate secondary defensive systems."
#define GOSSIP_ITEM_2  "Confirmed."


#define GOSSIP_ITEM_BRANN_1         "We are ready"
#define SAY_BRANN_1                 "Pentarus, you heard the man. Have your mages release the shield and let these brave souls through!"
#define SAY_PENTARUS_1              "Of course, Brann: We will have the shield down momentarily."
#define SAY_BRANN_2                 "Okay! Let's move out. Get into your machines; I'll speak to you from here via the radio."
#define SAY_PENTARUS_2              "Mages of the Kirin Tor, on Brann's Command, release the shield! Defend this platform and our allies with your lives! For Dalaran!"
#define SAY_BRANN_3                 "Our allies are ready. Bring down the shield and make way!"
#define SAY_BRANN_4                 "The iron dwarves have been seen emerging from the bunkers at the base of the pillars straight ahead of you. Destroy the bunkers and they will be forced to fall back."
#define SAY_BRANN_5                 "Watch out! Our air scouts report that the generators from the missile silos are coming online!"
#define SAY_BRANN_6                 "There are four generators powering the defense structures. If you sabotage the generators, the missile attacks will stop."

// Kirin Tor Battle-Mage and Hired Engineer mini event
#define KIRIN_TOR_BATTLE_MAGE_SAY_1 "Any luck?"
#define HIRED_ENGINEER_SAY_1        "Not a bit. For the life of me, I can't figure out how this thing works."
#define KIRIN_TOR_BATTLE_MAGE_SAY_2 "Keep at it. If our suspicions are right and this is a transporter, it could prove extremely useful in our assault."
#define HIRED_ENGINEER_SAY_2        "I know, I know... I haven't given up yet. Don't get your hopes up though, this technology is way beyond me."

enum Actions
{
    ACTION_START             = 1,
};

enum texts
{
    SAY_Event_1     = 0,
    SAY_Event_2     = 1,
    SAY_Event_3     = 2,
    SAY_Event_4     = 3,
    SAY_Event_5     = 4,
    SAY_Event_6     = 5,
    SAY_Event_7     = 6,
    SAY_Event_8     = 7,
    SAY_BRANN       = 8,
    SAY_BRANN2      = 9,
    SAY_DEACTIVATE  = 10,
    SAY_WHISPER     = 11,
};


enum Spells
{
    SPELL_TRANSITUS_SHIELD_BEAM = 48310,
};

enum NPCs
{
    NPC_TRANSITUS_SHIELD_DUMMY   = 27306,
    NPC_PENTARUS                 = 33624,
    NPC_INGENEER                 = 33626,
    NPC_BATTLE_MAGE              = 33662,
    NPC_TOR_MAGE                 = 33672,
};

class npc_ulduar_lorekeeper : public CreatureScript
{
    public:
        npc_ulduar_lorekeeper() : CreatureScript("npc_ulduar_lorekeeper") { }

        struct npc_ulduar_lorekeeperAI : public ScriptedAI
        {
            npc_ulduar_lorekeeperAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = me->GetInstanceScript();
                IntroStep = 0;
                Event = false;
                Greet = false;
            }
			
            void MoveInLineOfSight(Unit* who)
            {
                if (Greet)
                    return;
			
                if (me->IsWithinDistInMap(who, 10.0f) && who->GetTypeId() == TYPEID_PLAYER)
                {
                    IntroStep=1;
                    IntroTimer = 100;
                    Intro();
                    Greet=true;
                }
            }
			
            void Intro()
            {
                if(!IntroStep)
                    return;

                if (Event)
                    return;
					
                switch (IntroStep)
                {
                    case 1:
                        if (Creature* Dellorah = me->FindNearestCreature(NPC_DELORAH, 150.0f))
                            Dellorah->AI()->Talk(SAY_Event_1);
                        JumpIntro(10000);
                        break;
                    case 2:
                        Talk(SAY_Event_1);
                        JumpIntro(10000);
                        break;
                    case 3:
                        if (Creature* Dellorah = me->FindNearestCreature(NPC_DELORAH, 150.0f))
                            Dellorah->AI()->Talk(SAY_Event_2);
                        JumpIntro(10000);
                        break;
                    case 4:
                        Talk(SAY_Event_2);
                        JumpIntro(10000);
                        break;
                    case 5:
                        if (Creature* Dellorah = me->FindNearestCreature(NPC_DELORAH, 150.0f))
                            Dellorah->AI()->Talk(SAY_Event_3);
                        JumpIntro(10000);
                        break;
                    case 6:
                        Talk(SAY_Event_3);
                        JumpIntro(10000);
                        break;
                    case 7:
                        Talk(SAY_Event_4);
                        JumpIntro(10000);
                        break;
                    case 8:
                        if (Creature* Dellorah = me->FindNearestCreature(NPC_DELORAH, 150.0f))
                            Dellorah->AI()->Talk(SAY_Event_4);
                        JumpIntro(10000);
                        break;
                    case 9:
                        if (Creature* Rhydian = me->FindNearestCreature(NPC_RHYDIAN, 150.0f))
                        {
                            if (Creature* Dellorah = me->FindNearestCreature(NPC_DELORAH, 150.0f))
                            {
                                Dellorah->SetTarget(Rhydian->GetGUID());
                                Dellorah->AI()->Talk(SAY_Event_5);
                            }
                        }
                        JumpIntro(6000);
                        break;
                    case 10:
                        if (Creature* Rhydian = me->FindNearestCreature(NPC_RHYDIAN, 150.0f))
                        {
                            if (Creature* Brann = me->FindNearestCreature(NPC_BRANN_BRONZBEARD, 200.0f, true))
                            {
                                Rhydian->AI()->Talk(SAY_Event_7);
                                Rhydian->GetMotionMaster()->MovePoint(0, Brann->GetPositionX() - 4, Brann->GetPositionY(), Brann->GetPositionZ());
                            }
                        }
                        JumpIntro(500);
                        break;
                    case 11:
                        if (Creature* Nognnanon = me->FindNearestCreature(NPC_NORGANNON, 150.0f))
                        {
                            if (Creature* Dellorah = me->FindNearestCreature(NPC_DELORAH, 150.0f))
                            {
                                Dellorah->SetTarget(Nognnanon->GetGUID());
                                Dellorah->AI()->Talk(SAY_Event_6);
                            }
                        }
                        JumpIntro(10000);
                        break;
                    case 12:
                        Talk(SAY_Event_8);
                        if (Creature* Rhydian = me->FindNearestCreature(NPC_RHYDIAN, 200.0f))
                        {
                            if (Creature* Brann = me->FindNearestCreature(NPC_BRANN_BRONZBEARD, 200.0f, true))
                            {
                                Rhydian->SetTarget(Brann->GetGUID());
                                Rhydian->AI()->Talk(SAY_WHISPER);
                            }
                        }
                        JumpIntro(10000);
                        break;
                    case 13:
                        if (Creature* Rhydian = me->FindNearestCreature(NPC_RHYDIAN, 200.0f))
                        {
                            if (Creature* Dellorah = me->FindNearestCreature(NPC_DELORAH, 200.0f))
                                Rhydian->GetMotionMaster()->MovePoint(0, Dellorah->GetPositionX() - 2, Dellorah->GetPositionY(), Dellorah->GetPositionZ());
                        }
                        JumpIntro(10000);
                        break;
                    case 14:
                        if (Creature* Rhydian = me->FindNearestCreature(NPC_RHYDIAN, 200.0f))
                        {
                            if (Creature* Dellorah = me->FindNearestCreature(NPC_DELORAH, 200.0f))
                            {
                                Rhydian->GetMotionMaster()->MovePoint(0, Dellorah->GetPositionX() - 2, Dellorah->GetPositionY(), Dellorah->GetPositionZ());
                                Dellorah->AI()->Talk(SAY_Event_8);
                            }
                        }
                        Event = true;
                        break;
                    default:
                        break;
                }
            }

            void HardMode()
            {
                if(!HardStep)
                    return;
					
                Event = true;
					
                switch (HardStep)
                {
                    case 1:
                        if (Creature* Brann = me->FindNearestCreature(NPC_BRANN_BRONZBEARD, 200.0f, true))
                            Brann->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        if (Creature* Dellorah = me->FindNearestCreature(NPC_DELORAH, 150.0f))
                            Dellorah->AI()->Talk(SAY_BRANN);
                        JumpHard(4000);
                        break;
                    case 2:
                        if (Creature* Dellorah = me->FindNearestCreature(NPC_DELORAH, 200.0f, true))
                        {
                            if (Creature* Brann = me->FindNearestCreature(NPC_BRANN_BRONZBEARD, 200.0f, true))
                                Dellorah->GetMotionMaster()->MovePoint(0, Brann->GetPositionX() - 4, Brann->GetPositionY(), Brann->GetPositionZ());
                        }
                        JumpHard(12000);
                        break;
                    case 3:
                        if (Creature* Dellorah = me->FindNearestCreature(NPC_DELORAH, 200.0f, true))
                        {
                            if (Creature* Brann = me->FindNearestCreature(NPC_BRANN_BRONZBEARD, 200.0f, true))
                            {
                                Dellorah->SetTarget(Brann->GetGUID());
                                Dellorah->AI()->Talk(SAY_BRANN2);
                            }
                        }
                        JumpHard(5000);
                        break;
                    case 4:
                        if (Creature* Brann = me->FindNearestCreature(NPC_BRANN_BRONZBEARD, 200.0f, true))
                            Brann->AI()->DoAction(ACTION_START);
                        if (Creature* Dellorah = me->FindNearestCreature(NPC_DELORAH, 200.0f, true))
                        {
                            if (Creature* Keeper = me->FindNearestCreature(NPC_LOREKEEPER, 200.0f, true))
                            {
                                Dellorah->GetMotionMaster()->MovePoint(0, Keeper->GetPositionX() - 4, Keeper->GetPositionY(), Keeper->GetPositionZ());
                                Dellorah->SetTarget(Keeper->GetGUID());
                            }
                        }
                        JumpHard(5000);
                        break;
                    default:
                        break;
                }
            }
			
            void JumpIntro(uint32 TimeIntro)
            {
                IntroTimer = TimeIntro;
                IntroStep++;
            }

            void JumpHard(uint32 TimeHard)
            {
                HardTimer = TimeHard;
                HardStep++;
            }
			
            void UpdateAI(uint32 const diff)
            {
                if(IntroTimer < diff)
                   Intro();
                else
                   IntroTimer -= diff;
				   
                if(HardTimer < diff)
                   HardMode();
                else
                   HardTimer -= diff;
				
                return;
            }
			
        private:
            uint32 IntroTimer;
            uint32 IntroStep;
            bool Event;
            bool Greet;
            InstanceScript* instance;
        public:
            uint32 HardTimer;
            uint32 HardStep;
		
        };

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();

            InstanceScript* instance = creature->GetInstanceScript();
            if (!instance)
                return true;

            switch (action)
            {
                case GOSSIP_ACTION_INFO_DEF + 1:
                    if (player)
                    {
                        player->PrepareGossipMenu(creature);
                        instance->instance->LoadGrid(364, -16); // make sure leviathan is loaded

                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                        player->SEND_GOSSIP_MENU(32000, creature->GetGUID());
                    }
                    break;
                case GOSSIP_ACTION_INFO_DEF + 2:
                    if (player)
                        player->SEND_GOSSIP_MENU(32001, creature->GetGUID());
                    
                    creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

                    if (Creature* leviathan = instance->instance->GetCreature(instance->GetData64(BOSS_LEVIATHAN)))
                        leviathan->AI()->DoAction(ACTION_ACTIVATE_HARD_MODE);                   

                    CAST_AI(npc_ulduar_lorekeeperAI, creature->AI())->HardStep=1;
                    CAST_AI(npc_ulduar_lorekeeperAI, creature->AI())->HardTimer = 100;
                    CAST_AI(npc_ulduar_lorekeeperAI, creature->AI())->HardMode();
                    break;
            }

            return true;
        }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            InstanceScript* instance = creature->GetInstanceScript();
            if (instance && instance->GetData(BOSS_LEVIATHAN) != DONE && player)
            {
                player->PrepareGossipMenu(creature);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
            }
            return true;
        }
	
        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_ulduar_lorekeeperAI(creature);
        }
};

class npc_ulduar_warmage : public CreatureScript
{
public:
    npc_ulduar_warmage() : CreatureScript("npc_ulduar_warmage") { }

    struct npc_ulduar_warmageAI : public Scripted_NoMovementAI
    {
        npc_ulduar_warmageAI(Creature* creature) : Scripted_NoMovementAI(creature){}

        uint64 uiTargetGUID;

        void Reset()
        {
            uiTargetGUID = 0;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (me->IsNonMeleeSpellCasted(false))
                return;

            if (me->GetEntry() == NPC_ULDUAR_WARMAGE)
            {
                if (!uiTargetGUID)
                {
                    std::list<Creature*> orbList;
                    GetCreatureListWithEntryInGrid(orbList, me, NPC_TRANSITUS_SHIELD_DUMMY, 40.0f);
                    if (!orbList.empty())
                    {
                        for (std::list<Creature*>::const_iterator itr = orbList.begin(); itr != orbList.end(); ++itr)
                        {
                            if (Creature* pOrb = *itr)
                            {
                                if (pOrb->GetPositionY() < 1000)
                                {
                                    uiTargetGUID = pOrb->GetGUID();
                                    pOrb->SetDisplayId(11686); // make invisible
                                    pOrb->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);                
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                if (!uiTargetGUID)
                    if (Creature* pOrb = GetClosestCreatureWithEntry(me, NPC_TRANSITUS_SHIELD_DUMMY, 40.0f))
                    {
                        pOrb->SetDisplayId(11686); // make invisible
                        pOrb->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);                
                        uiTargetGUID = pOrb->GetGUID();
                    }
            }

            if (Creature* pOrb = me->GetCreature(*me, uiTargetGUID))
                DoCast(pOrb, SPELL_TRANSITUS_SHIELD_BEAM);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ulduar_warmageAI(creature);
    }
};

class npc_gauntlet_generator : public CreatureScript
{
public:
    npc_gauntlet_generator() : CreatureScript("npc_gauntlet_generator") { }

    struct npc_gauntlet_generatorAI : public ScriptedAI
    {
        npc_gauntlet_generatorAI(Creature* creature) : ScriptedAI(creature)
        {
            Step = 0;
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (me->IsWithinDistInMap(who, 100.0f) && who->GetTypeId() == TYPEID_PLAYER)
            {
                Step=1;
                StepTimer = 100;
                Event();
            }
        }

        void Event()        //summon 20 dwarfs each beacon
        {
            if (!Step)
                return;

            switch (Step)
            {
                case 1:
                    Spawn();
                    JumpIntro(1000);
                    break;
                case 2:
                    Spawn();
                    JumpIntro(1000);
                    break;
                case 3:
                    Spawn();
                    JumpIntro(1000);
                    break;
                case 4:
                    Spawn();
                    JumpIntro(1000);
                    break;
                case 5:
                    Spawn();
                    JumpIntro(1000);
                    break;
                case 6:
                    Spawn();
                    JumpIntro(1000);
                    break;
                case 7:
                    Spawn();
                    JumpIntro(1000);
                    break;
                case 8:
                    Spawn();
                    JumpIntro(1000);
                    break;
                case 9:
                    Spawn();
                    JumpIntro(1000);
                    break;
                case 10:
                    Spawn();
                    JumpIntro(1000);
                    break;
                case 11:
                    Spawn();
                    JumpIntro(1000);
                    break;
                case 12:
                    Spawn();
                    JumpIntro(1000);
                    break;
                case 13:
                    Spawn();
                    JumpIntro(1000);
                    break;
                case 14:
                    Spawn();
                    JumpIntro(1000);
                    break;
                case 15:
                    Spawn();
                    JumpIntro(1000);
                    break;
                case 16:
                    Spawn();
                    JumpIntro(1000);
                    break;
                case 17:
                    Spawn();
                    JumpIntro(1000);
                    break;
                case 18:
                    Spawn();
                    JumpIntro(1000);
                    break;
                case 19:
                    Spawn();
                    JumpIntro(1000);
                    break;
                case 20:
                    Spawn();
                    JumpIntro(1000);
                    break;
                default:
                    break;
            }
        }

        void Spawn()
        {
            DoCast(me, 63135);
        }

        void JumpIntro(uint32 Time)
        {
            StepTimer = Time;
            Step++;
        }
			
        void UpdateAI(uint32 const diff)
        {
            if(StepTimer < diff)
               Event();
            else
               StepTimer -= diff;
				
            return;
        }

    private:
        uint32 StepTimer;
        uint32 Step;

    };
    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_gauntlet_generatorAI(creature);
    }
};

class npc_bronzebeard_radio : public CreatureScript
{
public:
    npc_bronzebeard_radio() : CreatureScript("npc_bronzebeard_radio") { }

    struct npc_bronzebeard_radioAI : public ScriptedAI
    {
        npc_bronzebeard_radioAI(Creature* creature) : ScriptedAI(creature)
        {
            TowerOfFlames = false;
            TowerOfStorm = false;
            TowerOfFrost = false;
            TowerOfLife = false;
            RepairStation = false;
            me->SetDisplayId(11686); // make invisible
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        void MoveInLineOfSight(Unit* who)
        {
            // Tower of Flames
            if (!TowerOfFlames && me->IsWithinDistInMap(who, 500.0f) && who->GetTypeId() == TYPEID_PLAYER && me->FindNearestGameObject(GO_TOWER_OF_FLAMES, 150.0f))
            {
                TowerOfFlames = true;
                me->MonsterYell("This generator power Mimiron's gaze. In moments it can turn earth to ash, stone to magma! We can't let it reach full power!", 0, NULL);
                DoPlaySoundToSet(me, 15799);
            }
            // Tower of Storm
            else if (!TowerOfStorm && me->IsWithinDistInMap(who, 500.0f) && who->GetTypeId() == TYPEID_PLAYER && me->FindNearestGameObject(GO_TOWER_OF_STORMS, 150.0f))
            {   
                TowerOfStorm = true;
                me->MonsterYell("Ah, the tower of cromir, it is said that the power of Thorim has been used only once....and that it turned an entire continent to dust!", 0, NULL);
                DoPlaySoundToSet(me, 15801);
            }
            // Tower of Frost
            else if (!TowerOfFrost && me->IsWithinDistInMap(who, 500.0f) && who->GetTypeId() == TYPEID_PLAYER && me->FindNearestGameObject(GO_TOWER_OF_FROST, 150.0f))
            {   
                TowerOfFrost = true;
                me->MonsterYell("This tower powers the Hammer of Hodir. It's said to have the power to turn entire armies to ice.", 0, NULL);
                DoPlaySoundToSet(me, 15797);
            }
            // Tower of Life
            else if (!TowerOfLife && me->IsWithinDistInMap(who, 500.0f) && who->GetTypeId() == TYPEID_PLAYER && me->FindNearestGameObject(GO_TOWER_OF_LIFE, 150.0f))
            {   
                TowerOfLife = true;
                me->MonsterYell("You're approaching the tower of Freya, it contains the power to turn barren wastlands into jungles, teaming with life, overnight!", 0, NULL);
                DoPlaySoundToSet(me, 15798);
            }
            // Repair Station
            else if (!RepairStation && me->IsWithinDistInMap(who, 2.0f) && who->GetTypeId() == TYPEID_PLAYER && me->FindNearestGameObject(GO_REPAIR_STATION, 2.0f))
            {   
                RepairStation = true;
                me->MonsterYell("It appears you are near a repair station. Drive your vehicle on to the platform and it should be automatically repaired.", 0, NULL);
                DoPlaySoundToSet(me, 15803);
            }
        }      

    private:
        bool TowerOfFlames;
        bool TowerOfStorm;
        bool TowerOfFrost;
        bool TowerOfLife;
        bool RepairStation;

    };
    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_bronzebeard_radioAI(creature);
    }
};

class npc_brann_bronzebeard : public CreatureScript
{
public:
    npc_brann_bronzebeard() : CreatureScript("npc_brann_bronzebeard") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_brann_bronzebeardAI(creature);
    }

    struct npc_brann_bronzebeardAI : public ScriptedAI
    {
        npc_brann_bronzebeardAI(Creature* creature) : ScriptedAI(creature)
        {
            SteppingBrann = 0;
        }

        void EventBrann()
        {
            if (!SteppingBrann)
                return;

            switch (SteppingBrann)
            {
                case 1:
                    me->MonsterYell(SAY_BRANN_1, LANG_UNIVERSAL, 0);
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    JumpSteppingBrann(4000);
                    break;
                case 2:
                    if (Unit* pentarus = me->FindNearestCreature(33624, 20.0f))
                        pentarus->MonsterYell(SAY_PENTARUS_1, LANG_UNIVERSAL, 0);
                    JumpSteppingBrann(4000);
                    break;
                case 3:
                    me->MonsterSay(SAY_BRANN_2, LANG_UNIVERSAL, 0);
                    DoPlaySoundToSet(me, 15807);
                    JumpSteppingBrann(8000);
                    break;
                case 4:
                    if (Unit* pIngenieur = me->FindNearestCreature(33626, 50.0f))
                        pIngenieur->GetMotionMaster()->MovePoint(0, -777.336f,-45.084f,429.843f);
                    if (Unit* pBataille = me->FindNearestCreature(NPC_BATTLE_MAGE, 50.0f))
                    {
                        pBataille->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                        pBataille->SetSpeed(MOVE_WALK, 1, true);
                        pBataille->GetMotionMaster()->MovePoint(0, -682.470520f, -80.405426f, 427.573029f);
                        pBataille->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
                    }
                    if (Unit* pMage = me->FindNearestCreature(33672, 50.0f))
                    {
                        pMage->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                        pMage->SetSpeed(MOVE_WALK, 1, true);
                        pMage->GetMotionMaster()->MovePoint(0, -682.969788f, -75.015648f, 427.604187f);
                        pMage->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
                    }
                    if (Unit* pPentarus = me->FindNearestCreature(33624, 20.0f))
                    {
                        pPentarus->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                        pPentarus->SetSpeed(MOVE_WALK, 1, true);
                        pPentarus->GetMotionMaster()->MovePoint(0, -678.194580f, -77.385101f, 426.988464f);
                        pPentarus->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
                    }
                    me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                    me->SetSpeed(MOVE_WALK, 1, true);
                    me->GetMotionMaster()->MovePoint(0, -674.219055f, -45.745911f, 426.139160f);
                    JumpSteppingBrann(19000);
                    break;
                case 5:
                    if (Unit* pPentarus = me->FindNearestCreature(33624, 50.0f))
                        pPentarus->MonsterYell(SAY_PENTARUS_2, LANG_UNIVERSAL, 0);
                    JumpSteppingBrann(5000);
                    break;
                case 6:
                    me->MonsterYell(SAY_BRANN_3, LANG_UNIVERSAL, 0);
                    JumpSteppingBrann(4000);
                    break;
                case 7:
                    if (me->FindNearestGameObject(GO_CUPOLE, 250.0f))
                        me->FindNearestGameObject(GO_CUPOLE, 250.0f)->RemoveFromWorld();
                    
                    if (Creature* dummy = me->FindNearestCreature(NPC_TRANSITUS_SHIELD_DUMMY, 250.0f))
                        me->FindNearestCreature(NPC_TRANSITUS_SHIELD_DUMMY, 250.0f)->RemoveFromWorld();
                    JumpSteppingBrann(100);
                    break;
                case 8:
                    if (Creature* dummy = me->FindNearestCreature(NPC_TRANSITUS_SHIELD_DUMMY, 250.0f))
                        me->FindNearestCreature(NPC_TRANSITUS_SHIELD_DUMMY, 250.0f)->RemoveFromWorld();
                    JumpSteppingBrann(7900);
                    break;
                case 9:
                    me->MonsterSay(SAY_BRANN_4, LANG_UNIVERSAL, 0);
                    DoPlaySoundToSet(me, 15794);
                    JumpSteppingBrann(10000);
                    break;
                case 10:
                    me->MonsterSay(SAY_BRANN_5, LANG_UNIVERSAL, 0);
                    DoPlaySoundToSet(me, 15795);
                    JumpSteppingBrann(8000);
                    break;
                case 11:
                    me->MonsterSay(SAY_BRANN_6, LANG_UNIVERSAL, 0);
                    DoPlaySoundToSet(me, 15796);
                    JumpSteppingBrann(8000);
                    break;
                default:
                    break;
            }
        }

        void JumpSteppingBrann(uint32 Time)
        {
            StepTimer = Time;
            SteppingBrann++;
        }
		
        void DoAction(const int32 actionId)
        {
            switch(actionId)
            {
                case ACTION_START:
                    if (Creature* Keeper = me->FindNearestCreature(NPC_LOREKEEPER, 200.0f, true))
                        Keeper->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    SteppingBrann = 1;
                    EventBrann();                    
                    break;
                default:
                    break;
            }
        }

        void UpdateAI(uint32 const diff)
        {
            if(StepTimer < diff)
               EventBrann();
            else
               StepTimer -= diff;
				
            return;
        }

    private:

        uint32 StepTimer;
        uint32 SteppingBrann;
    };

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,GOSSIP_ITEM_BRANN_1,GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF);
        pPlayer->SEND_GOSSIP_MENU(100003, pCreature->GetGUID());
        
	    return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 uiSender, uint32 uiAction)
    {
        switch(uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF:
			    if (creature->AI())
                    creature->AI()->DoAction(ACTION_START);
                player->CLOSE_GOSSIP_MENU();
                break;
        }
        return true;
     }
};

class npc_ulduar_engineer : public CreatureScript
{
public:
    npc_ulduar_engineer() : CreatureScript("npc_ulduar_engineer") { }

    struct npc_ulduar_engineerAI : public Scripted_NoMovementAI
    {
        npc_ulduar_engineerAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
            Step = 0;
            Start = false;
        }
        
        void MoveInLineOfSight(Unit* who)
        {
            if (!Start && me->IsWithinDistInMap(who, 2.0f) && who->GetTypeId() == TYPEID_PLAYER && me->FindNearestGameObject(GO_TELEPORTER, 1.0f)) // Teleporter check to aviod multiple events in areas
            {
                Step=1;
                StepTimer = 100;
                Start = true;
                Event();
            }
        }

        void Event()
        {
            if (!Step)
                return;

            switch (Step)
            {
                case 1:
                    if (Unit* mage = me->FindNearestCreature(NPC_BATTLE_MAGE, 5.0f))
                        mage->MonsterSay(KIRIN_TOR_BATTLE_MAGE_SAY_1, LANG_UNIVERSAL, 0);
                    JumpIntro(3000);
                    break;
                case 2:
                    me->MonsterSay(HIRED_ENGINEER_SAY_1, LANG_UNIVERSAL, 0);
                    JumpIntro(4000);
                    break;
                case 3:
                    if (Unit* mage = me->FindNearestCreature(NPC_BATTLE_MAGE, 5.0f))
                        mage->MonsterSay(KIRIN_TOR_BATTLE_MAGE_SAY_2, LANG_UNIVERSAL, 0);
                    JumpIntro(7000);
                    break;
                case 4:
                    me->MonsterSay(HIRED_ENGINEER_SAY_2, LANG_UNIVERSAL, 0);
                    JumpIntro(1000);
                    break;
                default:
                    break;
            }
        }

        void JumpIntro(uint32 Time)
        {
            StepTimer = Time;
            Step++;
        }
			
        void UpdateAI(uint32 const diff)
        {
            if(StepTimer < diff)
               Event();
            else
               StepTimer -= diff;
				
            return;
        }

    private:
        uint32 StepTimer;
        uint32 Step;
        bool Start;

    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ulduar_engineerAI(creature);
    }
};

void AddSC_ulduar()
{
    new npc_gauntlet_generator();
    new npc_ulduar_lorekeeper();
    new npc_ulduar_warmage();
    new npc_bronzebeard_radio();
    new npc_brann_bronzebeard();
    new npc_ulduar_engineer();
}
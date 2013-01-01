/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "halls_of_stone.h"
#include "Player.h"

enum Texts
{
    SAY_KILL                            = 0,
    SAY_LOW_HEALTH                      = 1,
    SAY_DEATH                           = 2,
    SAY_PLAYER_DEATH                    = 3,
    SAY_ESCORT_START                    = 4,

    SAY_SPAWN_DWARF                     = 5,
    SAY_SPAWN_TROGG                     = 6,
    SAY_SPAWN_OOZE                      = 7,
    SAY_SPAWN_EARTHEN                   = 8,

    SAY_EVENT_INTRO_1                   = 9,
    SAY_EVENT_INTRO_2                   = 10,
    SAY_EVENT_A_1                       = 11,
    SAY_EVENT_A_3                       = 12,
    SAY_EVENT_B_1                       = 13,
    SAY_EVENT_B_3                       = 14,
    SAY_EVENT_C_1                       = 15,
    SAY_EVENT_C_3                       = 16,
    SAY_EVENT_D_1                       = 17,
    SAY_EVENT_D_3                       = 18,

    SAY_EVENT_END_01                    = 19,
    SAY_EVENT_END_02                    = 20,
    SAY_EVENT_END_04                    = 21,
    SAY_EVENT_END_06                    = 22,
    SAY_EVENT_END_08                    = 23,
    SAY_EVENT_END_10                    = 24,
    SAY_EVENT_END_12                    = 25,
    SAY_EVENT_END_14                    = 26,
    SAY_EVENT_END_16                    = 27,
    SAY_EVENT_END_18                    = 28,
    SAY_EVENT_END_20                    = 29,

    SAY_VICTORY_SJONNIR_1               = 30,
    SAY_VICTORY_SJONNIR_2               = 31,
    SAY_ENTRANCE_MEET                   = 32,

    SAY_EVENT_INTRO_3_ABED              = 0,
    SAY_EVENT_C_2_ABED                  = 1,
    SAY_EVENT_D_2_ABED                  = 2,
    SAY_EVENT_D_4_ABED                  = 3,
    SAY_EVENT_END_03_ABED               = 4,
    SAY_EVENT_END_05_ABED               = 5,
    SAY_EVENT_END_07_ABED               = 6,
    SAY_EVENT_END_21_ABED               = 7,

    SAY_EVENT_A_2_KADD                  = 0,
    SAY_EVENT_END_09_KADD               = 1,
    SAY_EVENT_END_11_KADD               = 2,
    SAY_EVENT_END_13_KADD               = 3,

    SAY_EVENT_B_2_MARN                  = 0,
    SAY_EVENT_END_15_MARN               = 1,
    SAY_EVENT_END_17_MARN               = 2,
    SAY_EVENT_END_19_MARN               = 3,

    TEXT_ID_START                       = 13100,
    TEXT_ID_PROGRESS                    = 13101
};

enum BrannCreatures
{
    CREATURE_TRIBUNAL_OF_THE_AGES       = 28234,
    CREATURE_BRANN_BRONZEBEARD          = 28070,
    CREATURE_DARK_MATTER_TARGET         = 28237,
    CREATURE_SEARING_GAZE_TARGET        = 28265,
    CREATURE_DARK_RUNE_PROTECTOR        = 27983,
    CREATURE_DARK_RUNE_STORMCALLER      = 27984,
    CREATURE_IRON_GOLEM_CUSTODIAN       = 27985,
};

enum Spells
{
    SPELL_STEALTH                       = 58506,
    //Kadrak
    SPELL_GLARE_OF_THE_TRIBUNAL         = 50988,
    H_SPELL_GLARE_OF_THE_TRIBUNAL       = 59868,
    //Marnak
    SPELL_DARK_MATTER                   = 51012,
    H_SPELL_DARK_MATTER                 = 59868,
    //Abedneum
    SPELL_SEARING_GAZE                  = 51136,
    H_SPELL_SEARING_GAZE                = 59867,

    SPELL_REWARD_ACHIEVEMENT            = 59046,
};

enum Quests
{
    QUEST_HALLS_OF_STONE                = 13207
};

#define GOSSIP_ITEM_START               "Brann, it would be our honor!"
#define GOSSIP_ITEM_PROGRESS            "Let's move Brann, enough of the history lessons!"
#define DATA_BRANN_SPARKLIN_NEWS        1

static Position SpawnLocations[]=
{
    {946.992f, 397.016f, 208.374f, 0.0f},
    {960.748f, 382.944f, 208.374f, 0.0f},
};

class mob_tribuna_controller : public CreatureScript
{
public:
    mob_tribuna_controller() : CreatureScript("mob_tribuna_controller") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_tribuna_controllerAI(creature);
    }

    struct mob_tribuna_controllerAI : public ScriptedAI
    {
        mob_tribuna_controllerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            SetCombatMovement(false);
        }

        InstanceScript* instance;

        uint32 uiKaddrakEncounterTimer;
        uint32 uiMarnakEncounterTimer;
        uint32 uiAbedneumEncounterTimer;

        bool bKaddrakActivated;
        bool bMarnakActivated;
        bool bAbedneumActivated;

        std::list<uint64> KaddrakGUIDList;

        void Reset()
        {
            uiKaddrakEncounterTimer = 1500;
            uiMarnakEncounterTimer = 10000;
            uiAbedneumEncounterTimer = 10000;

            bKaddrakActivated = false;
            bMarnakActivated = false;
            bAbedneumActivated = false;

            if (instance)
            {
                instance->HandleGameObject(instance->GetData64(DATA_GO_KADDRAK), false);
                instance->HandleGameObject(instance->GetData64(DATA_GO_MARNAK), false);
                instance->HandleGameObject(instance->GetData64(DATA_GO_ABEDNEUM), false);
                instance->HandleGameObject(instance->GetData64(DATA_GO_SKY_FLOOR), false);
            }

            KaddrakGUIDList.clear();
        }

        void UpdateFacesList()
        {
            /*GetCreatureListWithEntryInGrid(lKaddrakGUIDList, me, CREATURE_KADDRAK, 50.0f);
            if (!lKaddrakGUIDList.empty())
            {
                uint32 uiPositionCounter = 0;
                for (std::list<Creature*>::const_iterator itr = lKaddrakGUIDList.begin(); itr != lKaddrakGUIDList.end(); ++itr)
                {
                    if ((*itr)->isAlive())
                    {
                        if (uiPositionCounter == 0)
                        {
                            (*itr)->GetMap()->CreatureRelocation((*itr), 927.265f, 333.200f, 218.780f, (*itr)->GetOrientation());
                            (*itr)->SendMonsterMove(927.265f, 333.200f, 218.780f, 0, (*itr)->GetMovementFlags(), 1);
                        }
                        else
                        {
                            (*itr)->GetMap()->CreatureRelocation((*itr), 921.745f, 328.076f, 218.780f, (*itr)->GetOrientation());
                            (*itr)->SendMonsterMove(921.745f, 328.076f, 218.780f, 0, (*itr)->GetMovementFlags(), 1);
                        }
                    }
                    ++uiPositionCounter;
                }
            }*/
        }

        void UpdateAI(const uint32 diff)
        {
            if (bKaddrakActivated)
            {
                if (uiKaddrakEncounterTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        if (!KaddrakGUIDList.empty())
                            for (std::list<uint64>::const_iterator itr = KaddrakGUIDList.begin(); itr != KaddrakGUIDList.end(); ++itr)
                            {
                                if (Creature* pKaddrak = Unit::GetCreature(*me, *itr))
                                {
                                    if (pKaddrak->isAlive())
                                        pKaddrak->CastSpell(target, DUNGEON_MODE(SPELL_GLARE_OF_THE_TRIBUNAL, H_SPELL_GLARE_OF_THE_TRIBUNAL), true);
                                }
                            }
                    uiKaddrakEncounterTimer = 1500;
                } else uiKaddrakEncounterTimer -= diff;
            }
            if (bMarnakActivated)
            {
                if (uiMarnakEncounterTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    {
                        if (Creature* summon = me->SummonCreature(CREATURE_DARK_MATTER_TARGET, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                        {
                            summon->SetDisplayId(11686);
                            summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            summon->CastSpell(target, DUNGEON_MODE(SPELL_DARK_MATTER, H_SPELL_DARK_MATTER), true);
                        }
                    }
                    uiMarnakEncounterTimer = urand(30000, 31000);
                } else uiMarnakEncounterTimer -= diff;
            }
            if (bAbedneumActivated)
            {
                if (uiAbedneumEncounterTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    {
                        if (Creature* summon = me->SummonCreature(CREATURE_SEARING_GAZE_TARGET, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                        {
                            summon->SetDisplayId(11686);
                            summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            summon->CastSpell(target, DUNGEON_MODE(SPELL_SEARING_GAZE, H_SPELL_SEARING_GAZE), true);
                        }
                    }
                    uiAbedneumEncounterTimer = urand(30000, 31000);
                } else uiAbedneumEncounterTimer -= diff;
            }
        }
    };

};

class npc_brann_hos : public CreatureScript
{
public:
    npc_brann_hos() : CreatureScript("npc_brann_hos") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF+1 || action == GOSSIP_ACTION_INFO_DEF+2)
        {
            player->CLOSE_GOSSIP_MENU();
            CAST_AI(npc_brann_hos::npc_brann_hosAI, creature->AI())->StartWP();
        }

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_START, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        player->SEND_GOSSIP_MENU(TEXT_ID_START, creature->GetGUID());

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_brann_hosAI(creature);
    }

    struct npc_brann_hosAI : public npc_escortAI
    {
        npc_brann_hosAI(Creature* creature) : npc_escortAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        uint32 uiStep;
        uint32 uiPhaseTimer;

        uint64 uiControllerGUID;
        std::list<uint64> lDwarfGUIDList;

        InstanceScript* instance;

        bool bIsBattle;
        bool bIsLowHP;
        bool brannSparklinNews;

        void Reset()
        {
            if (!HasEscortState(STATE_ESCORT_ESCORTING))
            {
                bIsLowHP = false;
                bIsBattle = false;
                uiStep = 0;
                uiPhaseTimer = 0;
                uiControllerGUID = 0;
                brannSparklinNews = true;

                DespawnDwarf();

                if (instance)
                    instance->SetData(DATA_BRANN_EVENT, NOT_STARTED);
            }
        }

        void DespawnDwarf()
        {
            if (lDwarfGUIDList.empty())
                return;
            for (std::list<uint64>::const_iterator itr = lDwarfGUIDList.begin(); itr != lDwarfGUIDList.end(); ++itr)
            {
                Creature* temp = Unit::GetCreature(*me, instance ? (*itr) : 0);
                if (temp && temp->isAlive())
                    temp->DespawnOrUnsummon();
            }
            lDwarfGUIDList.clear();
        }

        void WaypointReached(uint32 waypointId)
        {
            switch (waypointId)
            {
                case 7:
                    if (Creature* creature = GetClosestCreatureWithEntry(me, CREATURE_TRIBUNAL_OF_THE_AGES, 100.0f))
                    {
                        if (!creature->isAlive())
                            creature->Respawn();
                        CAST_AI(mob_tribuna_controller::mob_tribuna_controllerAI, creature->AI())->UpdateFacesList();
                        uiControllerGUID = creature->GetGUID();
                    }
                    break;
                case 13:
                    Talk(SAY_EVENT_INTRO_1);
                    SetEscortPaused(true);
                    JumpToNextStep(20000);
                    break;
                case 17:
                    Talk(SAY_EVENT_INTRO_2);
                    if (instance)
                        instance->HandleGameObject(instance->GetData64(DATA_GO_TRIBUNAL_CONSOLE), true);
                    me->SetStandState(UNIT_STAND_STATE_KNEEL);
                    SetEscortPaused(true);
                    JumpToNextStep(8500);
                    break;
                case 18:
                    SetEscortPaused(true);
                    break;
            }
         }

         void SpawnDwarf(uint32 uiType)
         {
           switch (uiType)
           {
               case 1:
               {
                   uint32 uiSpawnNumber = DUNGEON_MODE(2, 3);
                   for (uint8 i = 0; i < uiSpawnNumber; ++i)
                       me->SummonCreature(CREATURE_DARK_RUNE_PROTECTOR, SpawnLocations[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
                   me->SummonCreature(CREATURE_DARK_RUNE_STORMCALLER, SpawnLocations[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
                   break;
               }
               case 2:
                   for (uint8 i = 0; i < 2; ++i)
                       me->SummonCreature(CREATURE_DARK_RUNE_STORMCALLER, SpawnLocations[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
                   break;
               case 3:
                   me->SummonCreature(CREATURE_IRON_GOLEM_CUSTODIAN, SpawnLocations[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
                   break;
           }
         }

        void JustSummoned(Creature* summoned)
        {
            lDwarfGUIDList.push_back(summoned->GetGUID());
            summoned->AddThreat(me, 0.0f);
            summoned->AI()->AttackStart(me);
        }

        void JumpToNextStep(uint32 uiTimer)
        {
          uiPhaseTimer = uiTimer;
          ++uiStep;
        }

        void StartWP()
        {
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            SetEscortPaused(false);
            uiStep = 1;
            Start();
        }

        void DamageTaken(Unit* /*done_by*/, uint32 & /*damage*/)
        {
            if (brannSparklinNews)
                brannSparklinNews = false;
        }

        uint32 GetData(uint32 type) const
        {
            if (type == DATA_BRANN_SPARKLIN_NEWS)
                return brannSparklinNews ? 1 : 0;

            return 0;
        }

        void UpdateEscortAI(const uint32 uiDiff)
        {
            if (uiPhaseTimer <= uiDiff)
            {
                switch (uiStep)
                {
                    case 1:
                        if (instance)
                        {
                            if (instance->GetData(DATA_BRANN_EVENT) != NOT_STARTED)
                                return;
                            instance->SetData(DATA_BRANN_EVENT, IN_PROGRESS);
                        }
                        bIsBattle = false;
                        Talk(SAY_ESCORT_START);
                        SetRun(true);
                        JumpToNextStep(0);
                        break;
                    case 3:
                        SetEscortPaused(false);
                        JumpToNextStep(0);
                        break;
                    case 5:
                        if (instance)
                            if (Creature* temp = (Unit::GetCreature(*me, instance->GetData64(DATA_ABEDNEUM))))
                                temp->AI()->Talk(SAY_EVENT_INTRO_3_ABED);
                            JumpToNextStep(8500);
                        break;
                    case 6:
                        Talk(SAY_EVENT_A_1);
                        JumpToNextStep(6500);
                        break;
                    case 7:
                        if (instance)
                            if (Creature* temp = Unit::GetCreature(*me, instance->GetData64(DATA_KADDRAK)))
                                temp->AI()->Talk(SAY_EVENT_A_2_KADD);
                            JumpToNextStep(12500);
                        break;
                    case 8:
                        Talk(SAY_EVENT_A_3);
                        if (instance)
                            instance->HandleGameObject(instance->GetData64(DATA_GO_KADDRAK), true);
                        if (Creature* temp = Unit::GetCreature(*me, uiControllerGUID))
                            CAST_AI(mob_tribuna_controller::mob_tribuna_controllerAI, temp->AI())->bKaddrakActivated = true;
                        JumpToNextStep(5000);
                        break;
                    case 9:
                        me->SetReactState(REACT_PASSIVE);
                        SpawnDwarf(1);
                        JumpToNextStep(20000);
                        break;
                    case 10:
                        Talk(SAY_EVENT_B_1);
                        JumpToNextStep(6000);
                        break;
                    case 11:
                        if (instance)
                            if (Creature* temp = Unit::GetCreature(*me, instance->GetData64(DATA_MARNAK)))
                                temp->AI()->Talk(SAY_EVENT_B_2_MARN);
                        SpawnDwarf(1);
                        JumpToNextStep(20000);
                        break;
                    case 12:
                        Talk(SAY_EVENT_B_3);
                        if (instance)
                            instance->HandleGameObject(instance->GetData64(DATA_GO_MARNAK), true);
                        if (Creature* temp = Unit::GetCreature(*me, uiControllerGUID))
                            CAST_AI(mob_tribuna_controller::mob_tribuna_controllerAI, temp->AI())->bMarnakActivated = true;
                        JumpToNextStep(10000);
                        break;
                    case 13:
                        SpawnDwarf(1);
                        JumpToNextStep(10000);
                        break;
                    case 14:
                        SpawnDwarf(2);
                        JumpToNextStep(20000);
                        break;
                    case 15:
                        Talk(SAY_EVENT_C_1);
                        SpawnDwarf(1);
                        JumpToNextStep(10000);
                        break;
                    case 16:
                        SpawnDwarf(2);
                        JumpToNextStep(20000);
                        break;
                    case 17:
                        if (instance)
                            if (Creature* temp = Unit::GetCreature(*me, instance->GetData64(DATA_ABEDNEUM)))
                                temp->AI()->Talk(SAY_EVENT_C_2_ABED);
                            SpawnDwarf(1);
                        JumpToNextStep(20000);
                        break;
                    case 18:
                        Talk(SAY_EVENT_C_3);
                        if (instance)
                            instance->HandleGameObject(instance->GetData64(DATA_GO_ABEDNEUM), true);
                        if (Creature* temp = Unit::GetCreature(*me, uiControllerGUID))
                            CAST_AI(mob_tribuna_controller::mob_tribuna_controllerAI, temp->AI())->bAbedneumActivated = true;
                        JumpToNextStep(5000);
                        break;
                    case 19:
                        SpawnDwarf(2);
                        JumpToNextStep(10000);
                        break;
                    case 20:
                        SpawnDwarf(1);
                        JumpToNextStep(15000);
                        break;
                    case 21:
                        Talk(SAY_EVENT_D_1);
                        SpawnDwarf(3);
                        JumpToNextStep(20000);
                        break;
                    case 22:
                        if (instance)
                            if (Creature* temp = Unit::GetCreature(*me, instance->GetData64(DATA_ABEDNEUM)))
                                temp->AI()->Talk(SAY_EVENT_D_2_ABED);
                        SpawnDwarf(1);
                        JumpToNextStep(5000);
                        break;
                    case 23:
                        SpawnDwarf(2);
                        JumpToNextStep(15000);
                        break;
                    case 24:
                        Talk(SAY_EVENT_D_3);
                        SpawnDwarf(3);
                        JumpToNextStep(5000);
                        break;
                    case 25:
                        SpawnDwarf(1);
                        JumpToNextStep(5000);
                        break;
                    case 26:
                        SpawnDwarf(2);
                        JumpToNextStep(10000);
                        break;
                    case 27:
                        if (instance)
                            if (Creature* temp = Unit::GetCreature(*me, instance->GetData64(DATA_ABEDNEUM)))
                                temp->AI()->Talk(SAY_EVENT_D_4_ABED);
                        SpawnDwarf(1);
                        JumpToNextStep(10000);
                        break;
                    case 28:
                        me->SetReactState(REACT_DEFENSIVE);
                        Talk(SAY_EVENT_END_01);
                        me->SetStandState(UNIT_STAND_STATE_STAND);
                        if (instance)
                            instance->HandleGameObject(instance->GetData64(DATA_GO_SKY_FLOOR), true);
                        if (Creature* temp = Unit::GetCreature(*me, uiControllerGUID))
                            temp->DealDamage(temp, temp->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                        bIsBattle = true;
                        SetEscortPaused(false);
                        JumpToNextStep(6500);
                        break;
                    case 29:
                        Talk(SAY_EVENT_END_02);
                        if (instance)
                            instance->SetData(DATA_BRANN_EVENT, DONE);
                        me->CastSpell(me, SPELL_REWARD_ACHIEVEMENT, true);
                        JumpToNextStep(5500);
                        break;
                    case 30:
                        if (instance)
                            if (Creature* temp = Unit::GetCreature(*me, instance->GetData64(DATA_ABEDNEUM)))
                                temp->AI()->Talk(SAY_EVENT_END_03_ABED);
                        JumpToNextStep(8500);
                        break;
                    case 31:
                        Talk(SAY_EVENT_END_04);
                        JumpToNextStep(11500);
                        break;
                    case 32:
                        if (instance)
                            if (Creature* temp = Unit::GetCreature(*me, instance->GetData64(DATA_ABEDNEUM)))
                                temp->AI()->Talk(SAY_EVENT_END_05_ABED);
                            JumpToNextStep(11500);
                        break;
                    case 33:
                        Talk(SAY_EVENT_END_06);
                        JumpToNextStep(4500);
                        break;
                    case 34:
                        if (instance)
                            if (Creature* temp = Unit::GetCreature(*me, instance->GetData64(DATA_ABEDNEUM)))
                                temp->AI()->Talk(SAY_EVENT_END_07_ABED);
                            JumpToNextStep(22500);
                        break;
                    case 35:
                        Talk(SAY_EVENT_END_08);
                        JumpToNextStep(7500);
                        break;
                    case 36:
                        if (instance)
                            if (Creature* temp = Unit::GetCreature(*me, instance->GetData64(DATA_KADDRAK)))
                                temp->AI()->Talk(SAY_EVENT_END_09_KADD);
                        JumpToNextStep(18500);
                        break;
                    case 37:
                        Talk(SAY_EVENT_END_10);
                        JumpToNextStep(5500);
                        break;
                    case 38:
                        if (instance)
                            if (Creature* temp = Unit::GetCreature(*me, instance->GetData64(DATA_KADDRAK)))
                                temp->AI()->Talk(SAY_EVENT_END_11_KADD);
                            JumpToNextStep(20500);
                        break;
                    case 39:
                        Talk(SAY_EVENT_END_12);
                        JumpToNextStep(2500);
                        break;
                    case 40:
                        if (instance)
                            if (Creature* temp = Unit::GetCreature(*me, instance->GetData64(DATA_KADDRAK)))
                                temp->AI()->Talk(SAY_EVENT_END_13_KADD);
                        JumpToNextStep(19500);
                        break;
                    case 41:
                        Talk(SAY_EVENT_END_14);
                        JumpToNextStep(10500);
                        break;
                    case 42:
                        if (instance)
                            if (Creature* temp = Unit::GetCreature(*me, instance->GetData64(DATA_MARNAK)))
                                temp->AI()->Talk(SAY_EVENT_END_15_MARN);
                            JumpToNextStep(6500);
                        break;
                    case 43:
                        Talk(SAY_EVENT_END_16);
                        JumpToNextStep(6500);
                        break;
                    case 44:
                        if (instance)
                            if (Creature* temp = Unit::GetCreature(*me, instance->GetData64(DATA_MARNAK)))
                                temp->AI()->Talk(SAY_EVENT_END_17_MARN);
                            JumpToNextStep(25500);
                        break;
                    case 45:
                        Talk(SAY_EVENT_END_18);
                        JumpToNextStep(23500);
                        break;
                    case 46:
                        if (instance)
                            if (Creature* temp = Unit::GetCreature(*me, instance->GetData64(DATA_MARNAK)))
                                temp->AI()->Talk(SAY_EVENT_END_19_MARN);
                            JumpToNextStep(3500);
                        break;
                    case 47:
                        Talk(SAY_EVENT_END_20);
                        JumpToNextStep(8500);
                        break;
                    case 48:
                        if (instance)
                            if (Creature* temp = Unit::GetCreature(*me, instance->GetData64(DATA_ABEDNEUM)))
                                temp->AI()->Talk(SAY_EVENT_END_21_ABED);
                            JumpToNextStep(5500);
                        break;
                    case 49:
                    {
                        if (instance)
                        {
                            instance->HandleGameObject(instance->GetData64(DATA_GO_KADDRAK), false);
                            instance->HandleGameObject(instance->GetData64(DATA_GO_MARNAK), false);
                            instance->HandleGameObject(instance->GetData64(DATA_GO_ABEDNEUM), false);
                            instance->HandleGameObject(instance->GetData64(DATA_GO_SKY_FLOOR), false);
                        }
                        Player* player = GetPlayerForEscort();
                        if (player)
                            player->GroupEventHappens(QUEST_HALLS_OF_STONE, me);
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        JumpToNextStep(180000);
                        break;
                    }
                    case 50:
                        SetEscortPaused(false);
                        break;
                }
            } else uiPhaseTimer -= uiDiff;

            if (!bIsLowHP && HealthBelowPct(30))
            {
                Talk(SAY_LOW_HEALTH);
                bIsLowHP = true;
            }
            else if (bIsLowHP && !HealthBelowPct(30))
                bIsLowHP = false;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

};

class achievement_brann_spankin_new : public AchievementCriteriaScript
{
    public:
        achievement_brann_spankin_new() : AchievementCriteriaScript("achievement_brann_spankin_new")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target)
        {
            if (!target)
                return false;

            if (Creature* Brann = target->ToCreature())
                if (Brann->AI()->GetData(DATA_BRANN_SPARKLIN_NEWS))
                    return true;

            return false;
        }
};

void AddSC_halls_of_stone()
{
    new npc_brann_hos();
    new mob_tribuna_controller();
    new achievement_brann_spankin_new();
}

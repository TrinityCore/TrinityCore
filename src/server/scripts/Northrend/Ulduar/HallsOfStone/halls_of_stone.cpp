/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedEscortAI.h"
#include "halls_of_stone.h"

enum Texts
{
    SAY_KILL_1                          = -1599016,
    SAY_KILL_2                          = -1599017,
    SAY_KILL_3                          = -1599018,
    SAY_LOW_HEALTH                      = -1599019,
    SAY_DEATH                           = -1599020,
    SAY_PLAYER_DEATH_1                  = -1599021,
    SAY_PLAYER_DEATH_2                  = -1599022,
    SAY_PLAYER_DEATH_3                  = -1599023,
    SAY_ESCORT_START                    = -1599024,

    SAY_SPAWN_DWARF                     = -1599025,
    SAY_SPAWN_TROGG                     = -1599026,
    SAY_SPAWN_OOZE                      = -1599027,
    SAY_SPAWN_EARTHEN                   = -1599028,

    SAY_EVENT_INTRO_1                   = -1599029,
    SAY_EVENT_INTRO_2                   = -1599030,
    SAY_EVENT_INTRO_3_ABED              = -1599031,

    SAY_EVENT_A_1                       = -1599032,
    SAY_EVENT_A_2_KADD                  = -1599033,
    SAY_EVENT_A_3                       = -1599034,

    SAY_EVENT_B_1                       = -1599035,
    SAY_EVENT_B_2_MARN                  = -1599036,
    SAY_EVENT_B_3                       = -1599037,

    SAY_EVENT_C_1                       = -1599038,
    SAY_EVENT_C_2_ABED                  = -1599039,
    SAY_EVENT_C_3                       = -1599040,

    SAY_EVENT_D_1                       = -1599041,
    SAY_EVENT_D_2_ABED                  = -1599042,
    SAY_EVENT_D_3                       = -1599043,
    SAY_EVENT_D_4_ABED                  = -1599044,

    SAY_EVENT_END_01                    = -1599045,
    SAY_EVENT_END_02                    = -1599046,
    SAY_EVENT_END_03_ABED               = -1599047,
    SAY_EVENT_END_04                    = -1599048,
    SAY_EVENT_END_05_ABED               = -1599049,
    SAY_EVENT_END_06                    = -1599050,
    SAY_EVENT_END_07_ABED               = -1599051,
    SAY_EVENT_END_08                    = -1599052,
    SAY_EVENT_END_09_KADD               = -1599053,
    SAY_EVENT_END_10                    = -1599054,
    SAY_EVENT_END_11_KADD               = -1599055,
    SAY_EVENT_END_12                    = -1599056,
    SAY_EVENT_END_13_KADD               = -1599057,
    SAY_EVENT_END_14                    = -1599058,
    SAY_EVENT_END_15_MARN               = -1599059,
    SAY_EVENT_END_16                    = -1599060,
    SAY_EVENT_END_17_MARN               = -1599061,
    SAY_EVENT_END_18                    = -1599062,
    SAY_EVENT_END_19_MARN               = -1599063,
    SAY_EVENT_END_20                    = -1599064,
    SAY_EVENT_END_21_ABED               = -1599065,

    SAY_VICTORY_SJONNIR_1               = -1599066,
    SAY_VICTORY_SJONNIR_2               = -1599067,

    SAY_ENTRANCE_MEET                   = -1599068,

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
    H_SPELL_SEARING_GAZE                = 59867
};

enum Quests
{
    QUEST_HALLS_OF_STONE                = 13207
};

enum Achievements
{
    ACHIEV_BRANN_SPANKIN_NEW            = 2154
};

#define GOSSIP_ITEM_START               "Brann, it would be our honor!"
#define GOSSIP_ITEM_PROGRESS            "Let's move Brann, enough of the history lessons!"

static Position SpawnLocations[]=
{
    {946.992f, 397.016f, 208.374f, 0.0f},
    {960.748f, 382.944f, 208.374f, 0.0f},
};

class mob_tribuna_controller : public CreatureScript
{
public:
    mob_tribuna_controller() : CreatureScript("mob_tribuna_controller") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_tribuna_controllerAI(pCreature);
    }

    struct mob_tribuna_controllerAI : public ScriptedAI
    {
        mob_tribuna_controllerAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
            SetCombatMovement(false);
        }

        InstanceScript* pInstance;

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

            if (pInstance)
            {
                pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_KADDRAK),false);
                pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_MARNAK),false);
                pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_ABEDNEUM),false);
                pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_SKY_FLOOR),false);
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
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        if (!KaddrakGUIDList.empty())
                            for (std::list<uint64>::const_iterator itr = KaddrakGUIDList.begin(); itr != KaddrakGUIDList.end(); ++itr)
                            {
                                if (Creature *pKaddrak = Unit::GetCreature(*me, *itr))
                                {
                                    if (pKaddrak->isAlive())
                                        pKaddrak->CastSpell(pTarget, DUNGEON_MODE(SPELL_GLARE_OF_THE_TRIBUNAL, H_SPELL_GLARE_OF_THE_TRIBUNAL), true);
                                }
                            }
                    uiKaddrakEncounterTimer = 1500;
                } else uiKaddrakEncounterTimer -= diff;
            }
            if (bMarnakActivated)
            {
                if (uiMarnakEncounterTimer <= diff)
                {
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    {
                        if (Creature* pSummon = me->SummonCreature(CREATURE_DARK_MATTER_TARGET, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                        {
                            pSummon->SetDisplayId(11686);
                            pSummon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            pSummon->CastSpell(pTarget, DUNGEON_MODE(SPELL_DARK_MATTER, H_SPELL_DARK_MATTER), true);
                        }
                    }
                    uiMarnakEncounterTimer = 30000 + rand()%1000;
                } else uiMarnakEncounterTimer -= diff;
            }
            if (bAbedneumActivated)
            {
                if (uiAbedneumEncounterTimer <= diff)
                {
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    {
                        if (Creature* pSummon = me->SummonCreature(CREATURE_SEARING_GAZE_TARGET, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 1000))
                        {
                            pSummon->SetDisplayId(11686);
                            pSummon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            pSummon->CastSpell(pTarget, DUNGEON_MODE(SPELL_SEARING_GAZE, H_SPELL_SEARING_GAZE), true);
                        }
                    }
                    uiAbedneumEncounterTimer = 30000 + rand()%1000;
                } else uiAbedneumEncounterTimer -= diff;
            }
        }
    };

};

class npc_brann_hos : public CreatureScript
{
public:
    npc_brann_hos() : CreatureScript("npc_brann_hos") { }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1 || uiAction == GOSSIP_ACTION_INFO_DEF+2)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            CAST_AI(npc_brann_hos::npc_brann_hosAI, pCreature->AI())->StartWP();
        }

        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_START, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->SEND_GOSSIP_MENU(TEXT_ID_START, pCreature->GetGUID());

        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_brann_hosAI(pCreature);
    }

    struct npc_brann_hosAI : public npc_escortAI
    {
        npc_brann_hosAI(Creature *c) : npc_escortAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        uint32 uiStep;
        uint32 uiPhaseTimer;

        uint64 uiControllerGUID;
        std::list<uint64> lDwarfGUIDList;

        InstanceScript* pInstance;

        bool bIsBattle;
        bool bIsLowHP;
        bool bHasBeenDamaged;

        void Reset()
        {
            if (!HasEscortState(STATE_ESCORT_ESCORTING))
            {
                bIsLowHP = false;
                bIsBattle = false;
                bHasBeenDamaged = false;
                uiStep = 0;
                uiPhaseTimer = 0;
                uiControllerGUID = 0;

                DespawnDwarf();

                if (pInstance)
                    pInstance->SetData(DATA_BRANN_EVENT, NOT_STARTED);
            }
        }

        void DespawnDwarf()
        {
            if (lDwarfGUIDList.empty())
                return;
            for (std::list<uint64>::const_iterator itr = lDwarfGUIDList.begin(); itr != lDwarfGUIDList.end(); ++itr)
            {
                Creature* pTemp = Unit::GetCreature(*me, pInstance ? (*itr) : 0);
                if (pTemp && pTemp->isAlive())
                    pTemp->DespawnOrUnsummon();
            }
            lDwarfGUIDList.clear();
        }

        void WaypointReached(uint32 uiPointId)
        {
            switch(uiPointId)
            {
                case 7:
                    if (Creature* pCreature = GetClosestCreatureWithEntry(me, CREATURE_TRIBUNAL_OF_THE_AGES, 100.0f))
                    {
                        if (!pCreature->isAlive())
                            pCreature->Respawn();
                        CAST_AI(mob_tribuna_controller::mob_tribuna_controllerAI, pCreature->AI())->UpdateFacesList();
                        uiControllerGUID = pCreature->GetGUID();
                    }
                    break;
                case 13:
                    DoScriptText(SAY_EVENT_INTRO_1, me);
                    SetEscortPaused(true);
                    JumpToNextStep(20000);
                    break;
                case 17:
                    DoScriptText(SAY_EVENT_INTRO_2, me);
                    if (pInstance)
                        pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_TRIBUNAL_CONSOLE),true);
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
           switch(uiType)
           {
               case 1:
               {
                   uint32 uiSpawnNumber = DUNGEON_MODE(2,3);
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

        void JustSummoned(Creature* pSummoned)
        {
            lDwarfGUIDList.push_back(pSummoned->GetGUID());
            pSummoned->AddThreat(me, 0.0f);
            pSummoned->AI()->AttackStart(me);
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
            if (!bHasBeenDamaged)
                bHasBeenDamaged = true;
        }

        void UpdateEscortAI(const uint32 uiDiff)
        {
            if (uiPhaseTimer <= uiDiff)
            {
                switch(uiStep)
                {
                    case 1:
                        if (pInstance)
                        {
                            if (pInstance->GetData(DATA_BRANN_EVENT) != NOT_STARTED)
                                return;
                            pInstance->SetData(DATA_BRANN_EVENT, IN_PROGRESS);
                        }
                        bIsBattle = false;
                        DoScriptText(SAY_ESCORT_START, me);
                        SetRun(true);
                        JumpToNextStep(0);
                        break;
                    case 3:
                        SetEscortPaused(false);
                        JumpToNextStep(0);
                        break;
                    case 5:
                        if (pInstance)
                            if (Creature* pTemp = (Unit::GetCreature(*me, pInstance->GetData64(DATA_ABEDNEUM))))
                                DoScriptText(SAY_EVENT_INTRO_3_ABED, pTemp);
                            JumpToNextStep(8500);
                        break;
                    case 6:
                        DoScriptText(SAY_EVENT_A_1, me);
                        JumpToNextStep(6500);
                        break;
                    case 7:
                        if (pInstance)
                            if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_KADDRAK)))
                                DoScriptText(SAY_EVENT_A_2_KADD, pTemp);
                            JumpToNextStep(12500);
                        break;
                    case 8:
                        DoScriptText(SAY_EVENT_A_3, me);
                        if (pInstance)
                            pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_KADDRAK),true);
                        if (Creature* pTemp = Unit::GetCreature(*me, uiControllerGUID))
                            CAST_AI(mob_tribuna_controller::mob_tribuna_controllerAI, pTemp->AI())->bKaddrakActivated = true;
                        JumpToNextStep(5000);
                        break;
                    case 9:
                        me->SetReactState(REACT_PASSIVE);
                        SpawnDwarf(1);
                        JumpToNextStep(20000);
                        break;
                    case 10:
                        DoScriptText(SAY_EVENT_B_1, me);
                        JumpToNextStep(6000);
                        break;
                    case 11:
                        if (pInstance)
                            if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_MARNAK)))
                                DoScriptText(SAY_EVENT_B_2_MARN, pTemp);
                        SpawnDwarf(1);
                        JumpToNextStep(20000);
                        break;
                    case 12:
                        DoScriptText(SAY_EVENT_B_3, me);
                        if (pInstance)
                            pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_MARNAK),true);
                        if (Creature* pTemp = Unit::GetCreature(*me, uiControllerGUID))
                            CAST_AI(mob_tribuna_controller::mob_tribuna_controllerAI, pTemp->AI())->bMarnakActivated = true;
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
                        DoScriptText(SAY_EVENT_C_1, me);
                        SpawnDwarf(1);
                        JumpToNextStep(10000);
                        break;
                    case 16:
                        SpawnDwarf(2);
                        JumpToNextStep(20000);
                        break;
                    case 17:
                        if (pInstance)
                            if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_ABEDNEUM)))
                                DoScriptText(SAY_EVENT_C_2_ABED, pTemp);
                            SpawnDwarf(1);
                        JumpToNextStep(20000);
                        break;
                    case 18:
                        DoScriptText(SAY_EVENT_C_3, me);
                        if (pInstance)
                            pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_ABEDNEUM),true);
                        if (Creature* pTemp = Unit::GetCreature(*me, uiControllerGUID))
                            CAST_AI(mob_tribuna_controller::mob_tribuna_controllerAI, pTemp->AI())->bAbedneumActivated = true;
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
                        DoScriptText(SAY_EVENT_D_1, me);
                        SpawnDwarf(3);
                        JumpToNextStep(20000);
                        break;
                    case 22:
                        if (pInstance)
                            if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_ABEDNEUM)))
                                DoScriptText(SAY_EVENT_D_2_ABED, pTemp);
                        SpawnDwarf(1);
                        JumpToNextStep(5000);
                        break;
                    case 23:
                        SpawnDwarf(2);
                        JumpToNextStep(15000);
                        break;
                    case 24:
                        DoScriptText(SAY_EVENT_D_3, me);
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
                        if (pInstance)
                            if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_ABEDNEUM)))
                                DoScriptText(SAY_EVENT_D_4_ABED, pTemp);
                        SpawnDwarf(1);
                        JumpToNextStep(10000);
                        break;
                    case 28:
                        me->SetReactState(REACT_DEFENSIVE);
                        DoScriptText(SAY_EVENT_END_01, me);
                        me->SetStandState(UNIT_STAND_STATE_STAND);
                        if (pInstance)
                            pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_SKY_FLOOR),true);
                        if (Creature* pTemp = Unit::GetCreature(*me, uiControllerGUID))
                            pTemp->DealDamage(pTemp, pTemp->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                        bIsBattle = true;
                        SetEscortPaused(false);
                        JumpToNextStep(6500);
                        break;
                    case 29:
                        DoScriptText(SAY_EVENT_END_02, me);
                        if (pInstance)
                        {
                            pInstance->SetData(DATA_BRANN_EVENT, DONE);

                            // Achievement criteria is with spell 59046 which does not exist.
                            // There is thus no way it can be given by casting the spell on the players.
                            pInstance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, 59046);

                            if (!bHasBeenDamaged)
                                pInstance->DoCompleteAchievement(ACHIEV_BRANN_SPANKIN_NEW);
                        }

                        JumpToNextStep(5500);
                        break;
                    case 30:
                        if (pInstance)
                            if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_ABEDNEUM)))
                                DoScriptText(SAY_EVENT_END_03_ABED, pTemp);
                        JumpToNextStep(8500);
                        break;
                    case 31:
                        DoScriptText(SAY_EVENT_END_04, me);
                        JumpToNextStep(11500);
                        break;
                    case 32:
                        if (pInstance)
                            if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_ABEDNEUM)))
                                DoScriptText(SAY_EVENT_END_05_ABED, pTemp);
                            JumpToNextStep(11500);
                        break;
                    case 33:
                        DoScriptText(SAY_EVENT_END_06, me);
                        JumpToNextStep(4500);
                        break;
                    case 34:
                        if (pInstance)
                            if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_ABEDNEUM)))
                                DoScriptText(SAY_EVENT_END_07_ABED, pTemp);
                            JumpToNextStep(22500);
                        break;
                    case 35:
                        DoScriptText(SAY_EVENT_END_08, me);
                        JumpToNextStep(7500);
                        break;
                    case 36:
                        if (pInstance)
                            if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_KADDRAK)))
                                DoScriptText(SAY_EVENT_END_09_KADD, pTemp);
                        JumpToNextStep(18500);
                        break;
                    case 37:
                        DoScriptText(SAY_EVENT_END_10, me);
                        JumpToNextStep(5500);
                        break;
                    case 38:
                        if (pInstance)
                            if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_KADDRAK)))
                                DoScriptText(SAY_EVENT_END_11_KADD, pTemp);
                            JumpToNextStep(20500);
                        break;
                    case 39:
                        DoScriptText(SAY_EVENT_END_12, me);
                        JumpToNextStep(2500);
                        break;
                    case 40:
                        if (pInstance)
                            if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_KADDRAK)))
                                DoScriptText(SAY_EVENT_END_13_KADD, pTemp);
                        JumpToNextStep(19500);
                        break;
                    case 41:
                        DoScriptText(SAY_EVENT_END_14, me);
                        JumpToNextStep(10500);
                        break;
                    case 42:
                        if (pInstance)
                            if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_MARNAK)))
                                DoScriptText(SAY_EVENT_END_15_MARN, pTemp);
                            JumpToNextStep(6500);
                        break;
                    case 43:
                        DoScriptText(SAY_EVENT_END_16, me);
                        JumpToNextStep(6500);
                        break;
                    case 44:
                        if (pInstance)
                            if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_MARNAK)))
                                DoScriptText(SAY_EVENT_END_17_MARN, pTemp);
                            JumpToNextStep(25500);
                        break;
                    case 45:
                        DoScriptText(SAY_EVENT_END_18, me);
                        JumpToNextStep(23500);
                        break;
                    case 46:
                        if (pInstance)
                            if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_MARNAK)))
                                DoScriptText(SAY_EVENT_END_19_MARN, pTemp);
                            JumpToNextStep(3500);
                        break;
                    case 47:
                        DoScriptText(SAY_EVENT_END_20, me);
                        JumpToNextStep(8500);
                        break;
                    case 48:
                        if (pInstance)
                            if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_ABEDNEUM)))
                                DoScriptText(SAY_EVENT_END_21_ABED, pTemp);
                            JumpToNextStep(5500);
                        break;
                    case 49:
                    {
                        if (pInstance)
                        {
                            pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_KADDRAK),false);
                            pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_MARNAK),false);
                            pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_ABEDNEUM),false);
                            pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_SKY_FLOOR),false);
                        }
                        Player* pPlayer = GetPlayerForEscort();
                        if (pPlayer)
                            pPlayer->GroupEventHappens(QUEST_HALLS_OF_STONE, me);
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
                DoScriptText(SAY_LOW_HEALTH, me);
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





void AddSC_halls_of_stone()
{
    new npc_brann_hos();
    new mob_tribuna_controller();
}

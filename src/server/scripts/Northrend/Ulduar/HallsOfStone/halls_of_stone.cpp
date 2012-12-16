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
    CREATURE_DARK_MATTER                = 28235,
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
    H_SPELL_GLARE_OF_THE_TRIBUNAL       = 59870,
    //Marnak
    SPELL_DARK_MATTER_VISUAL            = 51000,
    SPELL_DARK_MATTER_DUMMY             = 51001,
    SPELL_DARK_MATTER                   = 51012,
    H_SPELL_DARK_MATTER                 = 59868,
    //Abedneum
    SPELL_SEARING_GAZE_DUMMY            = 51136,
    SPELL_SEARING_GAZE                  = 51125,
    H_SPELL_SEARING_GAZE                = 59866,

	//DarkRuneProtector
	SPELL_CHARGE                        = 22120,
	SPELL_CLEAVE                        = 42724,

	//DarkRuneStormcaller
	SPELL_LIGHTNING_BOLT                = 12167,
	H_SPELL_LIGHTNING_BOLT              = 59863,
	SPELL_SHADOWWORD_PAIN               = 15654,
	H_SPELL_SHADOWWORD_PAIN             = 59864,

	//IronGolemGustodian
	SPELL_CRUSH_AMOR                    = 33661,
	SPELL_GROUND_SMASH                  = 12734,
	H_SPELL_GROUND_SMASH                = 59865
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
    {946.992f, 397.016f, 208.374f},
    {960.748f, 382.944f, 208.374f},
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
        mob_tribuna_controllerAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
            SetCombatMovement(false);
        }

        InstanceScript* pInstance;

        uint64 uiDarkMatterGUID;

        uint32 uiKaddrakEncounterTimer;
        uint32 uiMarnakEncounterTimer;
        uint32 uiAbedneumEncounterTimer;
        uint32 uiLoadingTimer;

        bool bKaddrakActivated;
        bool bMarnakActivated;
        bool bAbedneumActivated;
        bool bLoadingDarkMatter;

        std::list<uint64> KaddrakGUIDList;
        std::list<uint64> AbedneumGUIDList;
        std::list<uint64> MarnakGUIDList;

        void Reset()
        {
            uiKaddrakEncounterTimer = 1500;
            uiMarnakEncounterTimer = 10*IN_MILLISECONDS;
            uiAbedneumEncounterTimer = 10*IN_MILLISECONDS;
            uiLoadingTimer = 5*IN_MILLISECONDS;

            bKaddrakActivated = false;
            bMarnakActivated = false;
            bAbedneumActivated = false;
            bLoadingDarkMatter = false;

            uiDarkMatterGUID = 0;

            if (pInstance)
            {
                pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_KADDRAK), false);
                pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_MARNAK), false);
                pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_ABEDNEUM), false);
                pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_SKY_FLOOR), false);
            }

            KaddrakGUIDList.clear();
            AbedneumGUIDList.clear();
            MarnakGUIDList.clear();
        }

        void UpdateAI(uint32 const diff)
        {
            if (bKaddrakActivated)
            {
                if (uiKaddrakEncounterTimer <= diff)
                {
                    if (!KaddrakGUIDList.empty())
                        for (std::list<uint64>::const_iterator itr = KaddrakGUIDList.begin(); itr != KaddrakGUIDList.end(); ++itr)
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                if (Creature* kaddrak = Unit::GetCreature(*me, *itr))
                                    if (kaddrak->isAlive())
										if (target->GetTypeId() == TYPEID_PLAYER && target->isAlive() && target->IsVisible())
                                            kaddrak->CastSpell(target, DUNGEON_MODE(SPELL_GLARE_OF_THE_TRIBUNAL, H_SPELL_GLARE_OF_THE_TRIBUNAL), true);
                        }

                    uiKaddrakEncounterTimer = 3*IN_MILLISECONDS;
                } else uiKaddrakEncounterTimer -= diff;
            }

            if (bMarnakActivated)
            {
                if (uiMarnakEncounterTimer <= diff)
                {
                    if (!MarnakGUIDList.empty())
                        if (Creature* matter = me->SummonCreature(CREATURE_DARK_MATTER, 904.07f, 351.363f, 214.77f, 0, TEMPSUMMON_TIMED_DESPAWN, 20*IN_MILLISECONDS))
                        {
                            matter->SetDisplayId(17200);
                            matter->setFaction(16);
                            uiDarkMatterGUID = matter->GetGUID();

                            bLoadingDarkMatter = true;

                            for (std::list<uint64>::const_iterator itr = MarnakGUIDList.begin(); itr != MarnakGUIDList.end(); ++itr)
                            {
                                if (Creature* marnak = Unit::GetCreature(*me, *itr))
                                    if (marnak->isAlive())
                                        marnak->CastSpell(matter, SPELL_DARK_MATTER_DUMMY, true);
                            }
                        }

                    uiMarnakEncounterTimer = urand(20000, 25000);
                } else uiMarnakEncounterTimer -= diff;

                if (bLoadingDarkMatter && uiDarkMatterGUID)
                {
                    if (uiLoadingTimer <= diff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            if (Creature* matter = Unit::GetCreature(*me, uiDarkMatterGUID))
                            {
								if (target->GetTypeId() == TYPEID_PLAYER && target->isAlive() && target->IsVisible())
								{
                                    float x, y, z;
                                    target->GetPosition(x, y, z);

                                    me->SummonCreature(CREATURE_DARK_MATTER_TARGET, x, y, z, 0, TEMPSUMMON_TIMED_DESPAWN, 20*IN_MILLISECONDS);
                                    matter->GetMotionMaster()->MovePoint(0, x, y, z);
								}
                            }

                        bLoadingDarkMatter = false;
                        uiLoadingTimer = 5*IN_MILLISECONDS;
                    } else uiLoadingTimer -= diff;
                }
            }

            if (bAbedneumActivated)
            {
                if (uiAbedneumEncounterTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
						if (target->GetTypeId() == TYPEID_PLAYER && target->isAlive() && target->IsVisible())
						{
                            if (!AbedneumGUIDList.empty())
                                if (Creature* gaze = me->SummonCreature(CREATURE_SEARING_GAZE_TARGET, target->GetPositionX(), target->GetPositionY(),
                                    target->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 11*IN_MILLISECONDS))
                                {
                                    gaze->SetDisplayId(11686);
                                    gaze->setFaction(16);

                                    for (std::list<uint64>::const_iterator itr = AbedneumGUIDList.begin(); itr != AbedneumGUIDList.end(); ++itr)
                                    {
                                        if (Creature* abedneum = Unit::GetCreature(*me, *itr))
                                            if (abedneum->isAlive())
                                                abedneum->CastSpell(gaze, SPELL_SEARING_GAZE_DUMMY, true);
                                    }
                                }
						}

                    uiAbedneumEncounterTimer = urand(17500, 22500);
                } else uiAbedneumEncounterTimer -= diff;
            }
        }
    };

};

class npc_brann_hos : public CreatureScript
{
public:
    npc_brann_hos() : CreatureScript("npc_brann_hos") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_brann_hosAI(creature);
    }

    struct npc_brann_hosAI : public npc_escortAI
    {
        npc_brann_hosAI(Creature* c) : npc_escortAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        uint32 uiStep;
        uint32 uiPhaseTimer;

        uint64 uiControllerGUID;
        std::list<uint64> lSummonGUIDList;

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

                DespawnSummon();

                if (pInstance)
                    if (pInstance->GetData(DATA_BRANN_EVENT) != DONE) // dont reset if already done
                        pInstance->SetData(DATA_BRANN_EVENT, NOT_STARTED);
            }
        }

        void DespawnSummon()
        {
            if (lSummonGUIDList.empty() || !pInstance)
                return;

            for (std::list<uint64>::const_iterator itr = lSummonGUIDList.begin(); itr != lSummonGUIDList.end(); ++itr)
            {
                Creature* summon = Unit::GetCreature(*me, *itr);
                if (summon && summon->isAlive())
                {
                    if (pInstance->GetData(DATA_BRANN_EVENT) == DONE && (summon->GetEntry() == CREATURE_KADDRAK || summon->GetEntry() == CREATURE_MARNAK
                        || summon->GetEntry() == CREATURE_ABEDNEUM))
                        continue;

                    summon->DespawnOrUnsummon();
                }
            }
            lSummonGUIDList.clear();
        }

		void MoveInLineOfSight(Unit* who)
        {
			if (pInstance->GetData(DATA_BRANN_EVENT) == DONE)
			{
                if (who->GetTypeId() == TYPEID_PLAYER)
				{
				    if (Player* player = Unit::GetPlayer(*me, who->GetGUID()))
					{
                        if (me->IsWithinDistInMap(player, 30.0f) && (player->GetQuestStatus(QUEST_HALLS_OF_STONE) == QUEST_STATUS_INCOMPLETE))
						    player->CompleteQuest(QUEST_HALLS_OF_STONE);
					}
				}

			}
		}

        void WaypointReached(uint32 waypointId)
        {
            switch (waypointId)
            {
                case 7:
                    SpawnSummon(4);
                    break;
                case 13:
                    Talk(SAY_EVENT_INTRO_1);
                    SetEscortPaused(true);
                    JumpToNextStep(20000);
                    break;
                case 17:
                    Talk(SAY_EVENT_INTRO_2);
                    if (pInstance)
                        pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_TRIBUNAL_CONSOLE), true);
                    me->SetStandState(UNIT_STAND_STATE_KNEEL);
                    SetEscortPaused(true);
                    JumpToNextStep(8500);
                    break;
                case 18:
                    SetEscortPaused(true);
                    break;
            }
        }

        void SpawnSummon(uint32 uiType)
        {
            uint32 rnd = urand(0, 1);

            switch (uiType)
            {
                case 1:
                {
                    uint32 uiSpawnNumber = DUNGEON_MODE(2,3);
                    for (uint8 i = 0; i < uiSpawnNumber; ++i)
                        me->SummonCreature(CREATURE_DARK_RUNE_PROTECTOR, SpawnLocations[rnd], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
                    me->SummonCreature(CREATURE_DARK_RUNE_STORMCALLER, SpawnLocations[rnd], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
                    break;
                }
                case 2:
                    for (uint8 i = 0; i < 2; ++i)
                        me->SummonCreature(CREATURE_DARK_RUNE_STORMCALLER, SpawnLocations[rnd], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
                    break;
                case 3:
                    me->SummonCreature(CREATURE_IRON_GOLEM_CUSTODIAN, SpawnLocations[rnd], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
                    break;
                case 4:
                    if (Creature* creature = me->SummonCreature(CREATURE_TRIBUNAL_OF_THE_AGES, 910.126f, 345.795f, 237.928f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000))
                    {
                        uiControllerGUID = creature->GetGUID();
                        creature->SetVisible(false);
                    }
                    break;
                case 5:
                {
                    if (Creature* controller = Unit::GetCreature(*me, uiControllerGUID))
                    {
                        uint32 uiPositionCounter = 0;
                        for (uint8 i = 0; i < 2; ++i)
                        {
                            Creature* kaddrak = 0;

                            if (uiPositionCounter == 0)
                                kaddrak = me->SummonCreature(CREATURE_KADDRAK, 927.265f, 333.200f, 218.780f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
                            else
                                kaddrak = me->SummonCreature(CREATURE_KADDRAK, 921.745f, 328.076f, 218.780f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);

                            if (kaddrak)
                                CAST_AI(mob_tribuna_controller::mob_tribuna_controllerAI, controller->AI())->KaddrakGUIDList.push_back(kaddrak->GetGUID());

                            ++uiPositionCounter;
                        }

                        controller->AI()->DoZoneInCombat(controller, 100.0f);
                        CAST_AI(mob_tribuna_controller::mob_tribuna_controllerAI, controller->AI())->bKaddrakActivated = true;
                    }
                    break;
                }
                case 6:
                {
                    if (Creature* controller = Unit::GetCreature(*me, uiControllerGUID))
                    {
                        uint32 uiPositionCounter = 0;
                        for (uint8 i = 0; i < 2; ++i)
                        {
                            Creature* marnak = 0;

                            if (uiPositionCounter == 0)
                                marnak = me->SummonCreature(CREATURE_MARNAK, 891.309f, 359.382f, 217.422f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
                            else
                                marnak = me->SummonCreature(CREATURE_MARNAK, 895.834f, 363.436f, 217.422f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);

                            if (marnak)
                                CAST_AI(mob_tribuna_controller::mob_tribuna_controllerAI, controller->AI())->MarnakGUIDList.push_back(marnak->GetGUID());

                            ++uiPositionCounter;
                        }

                        controller->AI()->DoZoneInCombat(controller, 100.0f);
                        CAST_AI(mob_tribuna_controller::mob_tribuna_controllerAI, controller->AI())->bMarnakActivated = true;
                    }
                    break;
                }
                case 7:
                {
                    if (Creature* controller = Unit::GetCreature(*me, uiControllerGUID))
                    {
                        uint32 uiPositionCounter = 0;
                        for (uint8 i = 0; i < 2; ++i)
                        {
                            Creature* abedneum = 0;

                            if (uiPositionCounter == 0)
                                abedneum = me->SummonCreature(CREATURE_ABEDNEUM, 897.865f, 328.341f, 223.84f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);
                            else
                                abedneum = me->SummonCreature(CREATURE_ABEDNEUM, 893.012f, 332.804f, 223.545f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30000);

                            if (abedneum)
                                CAST_AI(mob_tribuna_controller::mob_tribuna_controllerAI, controller->AI())->AbedneumGUIDList.push_back(abedneum->GetGUID());

                            ++uiPositionCounter;
                        }

                        controller->AI()->DoZoneInCombat(controller, 100.0f);
                        CAST_AI(mob_tribuna_controller::mob_tribuna_controllerAI, controller->AI())->bAbedneumActivated = true;
                    }
                    break;
                }
            }
        }

        void JustSummoned(Creature* summoned)
        {
            lSummonGUIDList.push_back(summoned->GetGUID());

            switch (summoned->GetEntry())
            {
                case CREATURE_DARK_RUNE_PROTECTOR:
                case CREATURE_DARK_RUNE_STORMCALLER:
                case CREATURE_IRON_GOLEM_CUSTODIAN:
                    summoned->AddThreat(me, 1.0f);
                    summoned->AI()->AttackStart(me);
                    break;
            }
        }

        void JumpToNextStep(uint32 uiTimer)
        {
            uiPhaseTimer = uiTimer;
            ++uiStep;
        }

        void JustDied(Unit* /*victim*/)
        {
            me->Respawn();
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
                if (!pInstance)
                    return;

                switch (uiStep)
                {
                    case 1:
                        if (pInstance->GetData(DATA_BRANN_EVENT) != NOT_STARTED)
                            return;
                        pInstance->SetData(DATA_BRANN_EVENT, IN_PROGRESS);
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
                        if (Creature* pTemp = (Unit::GetCreature(*me, pInstance->GetData64(DATA_ABEDNEUM))))
                            pTemp->AI()->Talk(SAY_EVENT_INTRO_3_ABED);
                        JumpToNextStep(8500);
                        break;
                    case 6:
                        Talk(SAY_EVENT_A_1);
                        JumpToNextStep(6500);
                        break;
                    case 7:
                        if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_KADDRAK)))
                            pTemp->AI()->Talk(SAY_EVENT_A_2_KADD);
                        JumpToNextStep(12500);
                        break;
                    case 8:
                        Talk(SAY_EVENT_A_3);
                        SpawnSummon(5);
                        JumpToNextStep(5000);
                        break;
                    case 9:
                        me->SetReactState(REACT_PASSIVE);
                        SpawnSummon(1);
                        JumpToNextStep(20000);
                        break;
                    case 10:
                        Talk(SAY_EVENT_B_1);
                        JumpToNextStep(6000);
                        break;
                    case 11:
                        if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_MARNAK)))
                            pTemp->AI()->Talk(SAY_EVENT_B_2_MARN);
                        SpawnSummon(1);
                        JumpToNextStep(20000);
                        break;
                    case 12:
                        Talk(SAY_EVENT_B_3);
                        SpawnSummon(6);
                        JumpToNextStep(10000);
                        break;
                    case 13:
                        SpawnSummon(1);
                        JumpToNextStep(10000);
                        break;
                    case 14:
                        SpawnSummon(2);
                        JumpToNextStep(20000);
                        break;
                    case 15:
                        Talk(SAY_EVENT_C_1);
                        SpawnSummon(1);
                        JumpToNextStep(10000);
                        break;
                    case 16:
                        SpawnSummon(2);
                        JumpToNextStep(20000);
                        break;
                    case 17:
                        if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_ABEDNEUM)))
                            pTemp->AI()->Talk(SAY_EVENT_C_2_ABED);
                        SpawnSummon(1);
                        JumpToNextStep(20000);
                        break;
                    case 18:
                        Talk(SAY_EVENT_C_3);
                        SpawnSummon(7);
                        JumpToNextStep(5000);
                        break;
                    case 19:
                        SpawnSummon(2);
                        JumpToNextStep(10000);
                        break;
                    case 20:
                        SpawnSummon(1);
                        JumpToNextStep(15000);
                        break;
                    case 21:
                        Talk(SAY_EVENT_D_1);
                        SpawnSummon(3);
                        JumpToNextStep(20000);
                        break;
                    case 22:
                        if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_ABEDNEUM)))
                            Talk(SAY_EVENT_D_2_ABED);
                        SpawnSummon(1);
                        JumpToNextStep(5000);
                        break;
                    case 23:
                        SpawnSummon(2);
                        JumpToNextStep(15000);
                        break;
                    case 24:
                        Talk(SAY_EVENT_D_3);
                        SpawnSummon(3);
                        JumpToNextStep(5000);
                        break;
                    case 25:
                        SpawnSummon(1);
                        JumpToNextStep(5000);
                        break;
                    case 26:
                        SpawnSummon(2);
                        JumpToNextStep(10000);
                        break;
                    case 27:
                        if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_ABEDNEUM)))
                            pTemp->AI()->Talk(SAY_EVENT_D_4_ABED);
                        SpawnSummon(1);
                        JumpToNextStep(10000);
                        break;
                    case 28:
                        me->SetReactState(REACT_DEFENSIVE);
                        Talk(SAY_EVENT_END_01);
                        me->SetStandState(UNIT_STAND_STATE_STAND);
                        pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_SKY_FLOOR), true);
                        if (Creature* pTemp = Unit::GetCreature(*me, uiControllerGUID))
                            pTemp->DealDamage(pTemp, pTemp->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                        bIsBattle = true;
                        SetEscortPaused(false);
                        JumpToNextStep(6500);
                        break;
                    case 29:
                        Talk(SAY_EVENT_END_02);

                        pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_ABEDNEUM), true);
                        pInstance->SetData(DATA_BRANN_EVENT, DONE);
                        DespawnSummon();

						me->SummonGameObject(DUNGEON_MODE(GO_TRIBUNAL_CHEST, GO_TRIBUNAL_CHEST_HERO), 880.41f, 345.17f, 203.71f, 0, 0, 0, 0, 0, 90000000);

                        // Achievement criteria is with spell 59046 which does not exist.
                        // There is thus no way it can be given by casting the spell on the players.
                        pInstance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, 59046);

                        if (!bHasBeenDamaged && IsHeroic())
                            pInstance->DoCompleteAchievement(ACHIEV_BRANN_SPANKIN_NEW);

                        JumpToNextStep(5500);
                        break;
                    case 30:
                        if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_ABEDNEUM)))
                            pTemp->AI()->Talk(SAY_EVENT_END_03_ABED);
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        JumpToNextStep(8500);
                        break;
                    case 31:
                        Talk(SAY_EVENT_END_04);
                        JumpToNextStep(11500);
                        break;
                    case 32:
                        if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_ABEDNEUM)))
                            pTemp->AI()->Talk(SAY_EVENT_END_05_ABED);
                        JumpToNextStep(11500);
                        break;
                    case 33:
                        Talk(SAY_EVENT_END_06);
                        JumpToNextStep(4500);
                        break;
                    case 34:
                        if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_ABEDNEUM)))
                            pTemp->AI()->Talk(SAY_EVENT_END_07_ABED);
                        JumpToNextStep(22500);
                        break;
                    case 35:
                        Talk(SAY_EVENT_END_08);
                        JumpToNextStep(7500);
                        break;
                    case 36:
                        pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_KADDRAK), true);
                        if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_KADDRAK)))
                            pTemp->AI()->Talk(SAY_EVENT_END_09_KADD);
                        JumpToNextStep(18500);
                        break;
                    case 37:
                        Talk(SAY_EVENT_END_10);
                        JumpToNextStep(5500);
                        break;
                    case 38:
                        if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_KADDRAK)))
                            pTemp->AI()->Talk(SAY_EVENT_END_11_KADD);
                        JumpToNextStep(20500);
                        break;
                    case 39:
                        Talk(SAY_EVENT_END_12);
                        JumpToNextStep(2500);
                        break;
                    case 40:
                        if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_KADDRAK)))
                            pTemp->AI()->Talk(SAY_EVENT_END_13_KADD);
                        JumpToNextStep(19500);
                        break;
                    case 41:
                        Talk(SAY_EVENT_END_14);
                        JumpToNextStep(10500);
                        break;
                    case 42:
                        pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_MARNAK), true);
                        if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_MARNAK)))
                            pTemp->AI()->Talk(SAY_EVENT_END_15_MARN);
                        JumpToNextStep(6500);
                        break;
                    case 43:
                        Talk(SAY_EVENT_END_16);
                        JumpToNextStep(6500);
                        break;
                    case 44:
                        if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_MARNAK)))
                            pTemp->AI()->Talk(SAY_EVENT_END_17_MARN);
                        JumpToNextStep(25500);
                        break;
                    case 45:
                        Talk(SAY_EVENT_END_18);
                        JumpToNextStep(23500);
                        break;
                    case 46:
                        if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_MARNAK)))
                            pTemp->AI()->Talk(SAY_EVENT_END_19_MARN);
                        JumpToNextStep(3500);
                        break;
                    case 47:
                        DTalk(SAY_EVENT_END_20);
                        JumpToNextStep(8500);
                        break;
                    case 48:
                        if (Creature* pTemp = Unit::GetCreature(*me, pInstance->GetData64(DATA_ABEDNEUM)))
                            pTemp->AI()->Talk(SAY_EVENT_END_21_ABED);
                        JumpToNextStep(5500);
                        break;
                    case 49:
                    {
                        pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_KADDRAK), false);
                        pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_MARNAK), false);
                        pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_ABEDNEUM), false);
                        pInstance->HandleGameObject(pInstance->GetData64(DATA_GO_SKY_FLOOR), false);

                        Player* pPlayer = GetPlayerForEscort();
                        if (pPlayer)
                            pPlayer->GroupEventHappens(QUEST_HALLS_OF_STONE, me);

                        JumpToNextStep(10000); // (180000);
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

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                CAST_AI(npc_brann_hos::npc_brann_hosAI, pCreature->AI())->StartWP();
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                CAST_AI(npc_brann_hos::npc_brann_hosAI, pCreature->AI())->uiStep = 49;
                CAST_AI(npc_brann_hos::npc_brann_hosAI, pCreature->AI())->uiPhaseTimer = 1000;
                break;
        }

        pPlayer->CLOSE_GOSSIP_MENU();

        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        InstanceScript* pInstance = pCreature->GetInstanceScript();

        uint32 brann_event_data = pInstance->GetData(DATA_BRANN_EVENT);
        uint32 uiStepCount = CAST_AI(npc_brann_hos::npc_brann_hosAI, pCreature->AI())->uiStep;

        if (brann_event_data == NOT_STARTED && uiStepCount == 0)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_START, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        // skip history lessons
        if (uiStepCount > 29 && uiStepCount < 49)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_PROGRESS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

        pPlayer->SEND_GOSSIP_MENU(TEXT_ID_START, pCreature->GetGUID());

        return true;
    }

};

class mob_dark_matter : public CreatureScript
{
public:
    mob_dark_matter() : CreatureScript("mob_dark_matter") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_dark_matterAI(pCreature);
    }

    struct mob_dark_matterAI : public ScriptedAI
    {
        mob_dark_matterAI(Creature *pCreature) : ScriptedAI(pCreature) { }

        bool bAura;
        bool bCasted;
        uint32 uiCheckTimer;

        void Reset()
        {
            bAura = false;
            bCasted = false;
            uiCheckTimer = 5500;
            me->SetReactState(REACT_PASSIVE);
            me->SetSpeed(MOVE_FLIGHT, 0.7f, true);
        }

        void UpdateAI(const uint32 diff)
        {
            if (uiCheckTimer <= diff)
            {
                if (!bAura)
                {
                    me->RemoveAllAuras();
                    me->AddAura(SPELL_DARK_MATTER_VISUAL, me);
                    bAura = true;
                }

                if (bCasted)
                    me->DisappearAndDie();

                if (Creature* pTarget = me->FindNearestCreature(CREATURE_DARK_MATTER_TARGET, 1.0f, true))
                {
                    if (!bCasted) // prevent double cast
                        DoCast(DUNGEON_MODE(SPELL_DARK_MATTER, H_SPELL_DARK_MATTER));
                    bCasted = true;
                }

                uiCheckTimer = 1*IN_MILLISECONDS;
            }
            else uiCheckTimer -= diff;
        }
    };
};

class mob_searing_gaze : public CreatureScript
{
public:
    mob_searing_gaze() : CreatureScript("mob_searing_gaze") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_searing_gazeAI(pCreature);
    }

    struct mob_searing_gazeAI : public ScriptedAI
    {
        mob_searing_gazeAI(Creature *pCreature) : ScriptedAI(pCreature) { }

        uint32 uiCheckTimer;

        void Reset()
        {
            me->SetReactState(REACT_PASSIVE);
            uiCheckTimer = 1*IN_MILLISECONDS;
        }

        void UpdateAI(const uint32 diff)
        {
            if (uiCheckTimer <= diff)
            {
                DoCast(DUNGEON_MODE(SPELL_SEARING_GAZE, H_SPELL_SEARING_GAZE));
                uiCheckTimer = 1*IN_MILLISECONDS;
            } else uiCheckTimer -= diff;
        }
    };
};

enum eDarkRuneProtectorEvents
{
	EVENT_CLEAVE,
};

class mob_dark_rune_protector : public CreatureScript
{
public:
    mob_dark_rune_protector() : CreatureScript("mob_dark_rune_protector") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_dark_rune_protectorAI(pCreature);
    }

    struct mob_dark_rune_protectorAI : public ScriptedAI
    {
        mob_dark_rune_protectorAI(Creature *pCreature) : ScriptedAI(pCreature) { }

		bool charge;
		EventMap events;

		void Reset()
        {
			events.Reset();
			events.ScheduleEvent(EVENT_CLEAVE, 6000);

			charge = false;
		}

		void MoveInLineOfSight(Unit* who)
        {
            if (!who)
                return;

            if (me->IsWithinDistInMap(who, 20) && who->GetTypeId() == TYPEID_PLAYER && !charge)
            {
				DoCast(who, SPELL_CHARGE);
				charge = true;
			}
		}

		void UpdateAI(const uint32 diff)
        {
			Unit* target = me->SelectNearestPlayer(150.0f);
			AttackStart(target);

			me->SetWalk(false);
            me->SetSpeed(MOVE_RUN, me->GetSpeedRate(MOVE_RUN), true);

            if (!UpdateVictim())
                return;

			events.Update(diff);

			while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
				    case EVENT_CLEAVE:
						DoCast(me->getVictim(), SPELL_CLEAVE);
						events.ScheduleEvent(EVENT_CLEAVE, urand(12000, 17000));
						break;
				}
			}

			DoMeleeAttackIfReady();
		}
	};
};

enum eDarkRuneStormcallerEvents
{
	EVENT_LIGHTNING_BOLT,
	EVENT_SHADOWWORD_PAIN,
};

class mob_dark_rune_stormcaller : public CreatureScript
{
public:
    mob_dark_rune_stormcaller() : CreatureScript("mob_dark_rune_stormcaller") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_dark_rune_stormcallerAI(pCreature);
    }

    struct mob_dark_rune_stormcallerAI : public ScriptedAI
    {
        mob_dark_rune_stormcallerAI(Creature *pCreature) : ScriptedAI(pCreature) { }

		EventMap events;

		void Reset()
        {
			events.Reset();
			events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 6000);
			events.ScheduleEvent(EVENT_SHADOWWORD_PAIN, 10000);

		}


		void UpdateAI(const uint32 diff)
        {
			Unit* target = me->SelectNearestPlayer(150.0f);
			AttackStart(target);

			me->SetWalk(false);
            me->SetSpeed(MOVE_RUN, me->GetSpeedRate(MOVE_RUN), true);


            if (!UpdateVictim())
                return;

			events.Update(diff);

			while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
				    case EVENT_LIGHTNING_BOLT:
						DoCast(me->getVictim(), DUNGEON_MODE(SPELL_LIGHTNING_BOLT, H_SPELL_LIGHTNING_BOLT));
						events.ScheduleEvent(EVENT_LIGHTNING_BOLT, urand(10000, 15000));
						break;

					case EVENT_SHADOWWORD_PAIN:
						if(Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
							DoCast(pTarget, DUNGEON_MODE(SPELL_SHADOWWORD_PAIN, H_SPELL_SHADOWWORD_PAIN));
						events.ScheduleEvent(EVENT_SHADOWWORD_PAIN, urand(13000, 19000));
						break;
				}
			}

			DoMeleeAttackIfReady();
		}
	};
};

enum eIronGolemGustodianEvents
{
	EVENT_CRUSH_AMOR,
	EVENT_GROUND_SMASH,
};

class mob_iron_golem_gustodian : public CreatureScript
{
public:
    mob_iron_golem_gustodian() : CreatureScript("mob_iron_golem_gustodian") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_iron_golem_gustodianAI(pCreature);
    }

    struct mob_iron_golem_gustodianAI : public ScriptedAI
    {
        mob_iron_golem_gustodianAI(Creature *pCreature) : ScriptedAI(pCreature) { }

		EventMap events;

		void Reset()
        {
			events.Reset();
			events.ScheduleEvent(EVENT_CRUSH_AMOR, 5000);
			events.ScheduleEvent(EVENT_GROUND_SMASH, 8000);
		}

		void UpdateAI(const uint32 diff)
        {
			Unit* target = me->SelectNearestPlayer(150.0f);
			AttackStart(target);

			me->SetWalk(false);
            me->SetSpeed(MOVE_RUN, me->GetSpeedRate(MOVE_RUN), true);

            if (!UpdateVictim())
                return;

			events.Update(diff);

			while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
					case EVENT_CRUSH_AMOR:
						if(Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
							DoCast(pTarget, SPELL_CRUSH_AMOR);
						events.ScheduleEvent(EVENT_CRUSH_AMOR, urand(5000, 12000));
						break;

				    case EVENT_GROUND_SMASH:
						DoCast(me, DUNGEON_MODE(SPELL_GROUND_SMASH, H_SPELL_GROUND_SMASH));
						events.ScheduleEvent(EVENT_GROUND_SMASH, urand(13000, 17000));
						break;
				}
			}

			DoMeleeAttackIfReady();
		}
	};
};

void AddSC_halls_of_stone()
{
    new npc_brann_hos();
    new mob_tribuna_controller();
    new mob_dark_matter();
    new mob_searing_gaze();
	new mob_dark_rune_protector();
	new mob_dark_rune_stormcaller();
	new mob_iron_golem_gustodian();
}

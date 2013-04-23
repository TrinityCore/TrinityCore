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

/* ScriptData
SDName: Trial Of the Champion
SD%Complete:
SDComment:
SDCategory: trial_of_the_champion
EndScriptData */

/* ContentData
npc_announcer_toc5
EndContentData */

#include "ScriptPCH.h"
#include "trial_of_the_champion.h"
#include "Vehicle.h"
#include "Player.h"

#define GOSSIP_START_EVENT1     "I'm ready to start challenge."
#define GOSSIP_START_EVENT2     "I'm ready for the next challenge."

#define ORIENTATION             4.714f

/*######
## npc_announcer_toc5
######*/

const Position SpawnPosition  = {746.843f, 695.68f, 412.339f, 4.70776f};
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

enum IntroPhase
{
    IDLE,
    INTRO,
    FINISHED
};

enum Spells
{
    SPELL_FACE_BLACKKNIGHT                = 67482,
    SPELL_HERALD_ARGENT                   = 64787,
};

enum Creatures
{
    CREATURE_TRALL                        = 34994,
    CREATURE_GARROSH                      = 34995,
    CREATURE_KING                         = 34990,
    CREATURE_LADY                         = 34992,
};

class npc_anstart : public CreatureScript
{
    public:
        npc_anstart(): CreatureScript("npc_anstart") {}

    struct npc_anstartAI : public ScriptedAI
    {
        npc_anstartAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        }

        uint32 uiIntroTimer;
        uint8 uiIntroPhase;
        IntroPhase Phase;

        Creature* pTrall;
        Creature* pGarrosh;
        Creature* pKing;
        Creature* pLady;
        Creature* pHighlord;

        InstanceScript* pInstance;

        void Reset()
        {
            Phase = IDLE;
            uiIntroTimer = 0;
            uiIntroPhase = 0;
            pTrall = NULL;
            pGarrosh = NULL;
            pKing = NULL;
            pLady = NULL;
            pHighlord = NULL;
        }

        void MoveInLineOfSight(Unit* pWho)
        {
            if (!pWho)
                return;

            if (Phase == IDLE && me->IsWithinDistInMap(pWho, 100))
            {
                Phase = INTRO;
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                if (pTrall = me->SummonCreature(CREATURE_TRALL, 685.569f, 615.103f, 435.396f, 6.23544f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000))
                {
                    pTrall->SetReactState(REACT_PASSIVE);
                    pTrall->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
                if (pGarrosh = me->SummonCreature(CREATURE_GARROSH, 685.7f, 621.134f, 435.396f, 6.259f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000))
                {
                    pGarrosh->SetReactState(REACT_PASSIVE);
                    pGarrosh->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
                if (pKing = me->SummonCreature(CREATURE_KING, 807.724f, 617.9f, 435.396f, 3.18416f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000))
                {
                    pKing->SetReactState(REACT_PASSIVE);
                    pKing->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
                if (pLady = me->SummonCreature(CREATURE_LADY, 807.401f, 613.667f, 435.397f, 3.0585f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000))
                {
                    pLady->SetReactState(REACT_PASSIVE);
                    pLady->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
                if (pHighlord = me->SummonCreature(NPC_HIGHLORD, 746.482f, 556.857f, 435.396f, 1.5898f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000))
                {
                    pHighlord->SetReactState(REACT_PASSIVE);
                    pHighlord->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
            }
        }

        void AttackStart(Unit* who) {}

        void UpdateAI(const uint32 diff)
        {
            if (Phase != INTRO)
                return;

            if (uiIntroTimer <= diff)
            {
                if(!pTrall)
                    return;
                if(!pGarrosh)
                    return;
                if(!pKing)
                    return;
                if(!pLady)
                    return;
                if(!pHighlord)
                    return;

                switch (uiIntroPhase)
                {
                    case 0:
                        ++uiIntroPhase;
                        uiIntroTimer = 10000;
                        break;
                    case 1:
                        pInstance->DoCastSpellOnPlayers(SPELL_HERALD_ARGENT);
                        if (pInstance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                            Talk(SAY_INTRO_HERALD_1);
                        else
                            Talk(SAY_INTRO_HERALD_1);
                        ++uiIntroPhase;
                        uiIntroTimer = 5000;
                        break;
                    case 2:
                        pHighlord->AI()->Talk(SAY_INTRO_HERALD_2);
                        ++uiIntroPhase;
                        uiIntroTimer = 13000;
                        break;
                    case 3:
                        if (pInstance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                            pTrall->AI()->Talk(SAY_INTRO_HERALD_3);
                        else
                            pKing->AI()->Talk(SAY_INTRO_HERALD_3);
                        ++uiIntroPhase;
                        uiIntroTimer = 4000;
                        break;
                    case 4:
                        if (pInstance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                            pGarrosh->AI()->Talk(SAY_INTRO_HERALD_4);
                        else
                            pLady->AI()->Talk(SAY_INTRO_HERALD_4);
                        ++uiIntroPhase;
                        uiIntroTimer = 4000;
                        break;
                    case 5:
                        if (pInstance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                            pKing->AI()->Talk(SAY_INTRO_HERALD_5);
                        else
                            pGarrosh->AI()->Talk(SAY_INTRO_HERALD_5);
                        ++uiIntroPhase;
                        uiIntroTimer = 6000;
                        break;
                    case 6:
                        if (pInstance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                            pLady->AI()->Talk(SAY_INTRO_HERALD_6);
                        else
                            pTrall->AI()->Talk(SAY_INTRO_HERALD_6);
                        ++uiIntroPhase;
                        uiIntroTimer = 6000;
                        break;
                    case 7:
                        pHighlord->AI()->Talk(SAY_INTRO_HERALD_7);
                        ++uiIntroPhase;
                        uiIntroTimer = 1000;
                        break;
                    case 8:
                        if (Creature* pAnnouncertoc5 = me->SummonCreature(NPC_JAEREN, 746.626f, 618.54f, 411.09f, 4.63158f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 60000))
                        {
                            me->DisappearAndDie();
                            pAnnouncertoc5->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            pAnnouncertoc5->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                            pAnnouncertoc5->SetReactState(REACT_PASSIVE);
                            Phase = FINISHED;
                        }
                        else
                            Reset();
                        return;
                }
            }
            else
                uiIntroTimer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_anstartAI (creature);
    };
};

class npc_announcer_toc5 : public CreatureScript
{
    public:
        npc_announcer_toc5(): CreatureScript("npc_announcer_toc5") {}

    struct npc_announcer_toc5AI : public ScriptedAI
    {
        npc_announcer_toc5AI(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();

            uiSummonTimes = 0;
            uiPosition = 0;
            uiLesserChampions = 0;

            uiFirstBoss = 0;
            uiSecondBoss = 0;
            uiThirdBoss = 0;

            uiArgentChampion = 0;

            uiPhase = 0;
            uiTimer = 0;

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

        InstanceScript* pInstance;

        uint8 uiSummonTimes;
        uint8 uiPosition;
        uint8 uiLesserChampions;

        uint32 uiArgentChampion;
        uint32 uiFirstBoss;
        uint32 uiSecondBoss;
        uint32 uiThirdBoss;
        uint32 uiPhase;
        uint32 uiTimer;

        uint64 uiBlackKnightGUID;
        uint64 uiVehicle1GUID;
        uint64 uiVehicle2GUID;
        uint64 uiVehicle3GUID;
        uint64 uiGrandChampionBoss1;

        Creature* pVehicle_black_knight;

        std::list<uint64> Champion1List;
        std::list<uint64> Champion2List;
        std::list<uint64> Champion3List;

        bool firstEventStarted;
        bool secondEventStarted;
        bool thirdEventStarted;

        void NextStep(uint32 uiTimerStep,bool bNextStep = true,uint8 uiPhaseStep = 0)
        {
            uiTimer = uiTimerStep;
            if (bNextStep)
                ++uiPhase;
            else
                uiPhase = uiPhaseStep;
        }

        void SetData(uint32 uiType, uint32 /*uiData*/)
        {
            switch (uiType)
            {
                case DATA_START:
                    if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE)))
                        pInstance->HandleGameObject(pGO->GetGUID(), true);
                    if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE1)))
                        pInstance->HandleGameObject(pGO->GetGUID(), false);
                        DoSummonGrandChampion(uiFirstBoss);
                        NextStep(10000, false, 1);
                    break;
                case DATA_IN_POSITION: //movement done.
                    me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                    me->GetMotionMaster()->MovePoint(1, 735.898f, 651.961f, 411.93f);
                    if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE)))
                        pInstance->HandleGameObject(pGO->GetGUID(), false);
                    NextStep(20000, false, 3);
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
                    }
                    else
                        if (uiLesserChampions == 9)
                            StartGrandChampionsAttack();
                    break;
                }
            }
        }

        void StartGrandChampionsAttack()
        {
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

        void DoSummonGrandChampion(uint32 uiBoss)
        {
            ++uiSummonTimes;
            uint32 VEHICLE_TO_SUMMON1 = 0;
            uint32 VEHICLE_TO_SUMMON2 = 0;

            switch (uiBoss)
            {
                case 0:
                    if (pInstance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                    {
                        Talk(SAY_WARRIOR_ENTERS);
                        Talk(SAY_WARRIOR_CHEER);
                    }
                    else
                    {
                        Talk(SAY_WARRIOR_ENTERS);
                        Talk(SAY_WARRIOR_CHEER);
                    }
                        VEHICLE_TO_SUMMON1 = VEHICLE_MOKRA_SKILLCRUSHER_MOUNT;
                        VEHICLE_TO_SUMMON2 = VEHICLE_ORGRIMMAR_WOLF;
                    break;
                case 1:
                    if (pInstance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                    {
                        Talk(SAY_MAGE_ENTERS);
                        Talk(SAY_MAGE_CHEER);
                    }
                    else
                    {
                        Talk(SAY_MAGE_ENTERS);
                        Talk(SAY_MAGE_CHEER);
                    }
                        VEHICLE_TO_SUMMON1 = VEHICLE_ERESSEA_DAWNSINGER_MOUNT;
                        VEHICLE_TO_SUMMON2 = VEHICLE_SILVERMOON_HAWKSTRIDER;
                    break;
                case 2:
                    if (pInstance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                    {
                        Talk(SAY_SHAMAN_ENTERS);
                        Talk(SAY_SHAMAN_CHEER);
                    }
                    else
                    {
                        Talk(SAY_SHAMAN_ENTERS);
                        Talk(SAY_SHAMAN_CHEER);
                    }
                        VEHICLE_TO_SUMMON1 = VEHICLE_RUNOK_WILDMANE_MOUNT;
                        VEHICLE_TO_SUMMON2 = VEHICLE_THUNDER_BLUFF_KODO;
                    break;
                case 3:
                    if (pInstance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                    {
                        Talk(SAY_HUNTER_ENTERS);
                        Talk(SAY_HUNTER_CHEER);
                    }
                    else
                    {
                        Talk(SAY_HUNTER_ENTERS);
                        Talk(SAY_HUNTER_CHEER);
                    }
                        VEHICLE_TO_SUMMON1 = VEHICLE_ZUL_TORE_MOUNT;
                        VEHICLE_TO_SUMMON2 = VEHICLE_DARKSPEAR_RAPTOR;
                    break;
                case 4:
                    if (pInstance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                    {
                        Talk(SAY_ROGUE_ENTERS);
                        Talk(SAY_ROGUE_CHEER);
                    }
                    else
                    {
                        Talk(SAY_ROGUE_ENTERS);
                        Talk(SAY_ROGUE_CHEER);
                    }
                        VEHICLE_TO_SUMMON1 = VEHICLE_DEATHSTALKER_VESCERI_MOUNT;
                        VEHICLE_TO_SUMMON2 = VEHICLE_FORSAKE_WARHORSE;
                    break;
                default:
                    return;
            }

            if (Creature* pBoss = me->SummonCreature(VEHICLE_TO_SUMMON1, SpawnPosition))
            {
                switch (uiSummonTimes)
                {
                    case 1:
                    {
                        uiVehicle1GUID = pBoss->GetGUID();
                        uint64 uiGrandChampionBoss1 = 0;
                        if (Creature* pBoss = Unit::GetCreature(*me, uiVehicle1GUID))
                            if (Vehicle* pVehicle = pBoss->GetVehicleKit())
                                if (Unit* pUnit = pVehicle->GetPassenger(0))
                                    uiGrandChampionBoss1 = pUnit->GetGUID();
                        if (pInstance)
                        {
                            pInstance->SetData64(DATA_GRAND_CHAMPION_VEHICLE_1, uiVehicle1GUID);
                            pInstance->SetData64(DATA_GRAND_CHAMPION_1, uiGrandChampionBoss1);
                        }
                        pBoss->AI()->SetData(1, 0);
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
                        if (pInstance)
                        {
                            pInstance->SetData64(DATA_GRAND_CHAMPION_VEHICLE_2, uiVehicle2GUID);
                            pInstance->SetData64(DATA_GRAND_CHAMPION_2, uiGrandChampionBoss2);
                        }
                        pBoss->AI()->SetData(2, 0);
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
                        if (pInstance)
                        {
                            pInstance->SetData64(DATA_GRAND_CHAMPION_VEHICLE_3, uiVehicle3GUID);
                            pInstance->SetData64(DATA_GRAND_CHAMPION_3, uiGrandChampionBoss3);
                        }
                        pBoss->AI()->SetData(3, 0);
                        break;
                    }
                    default:
                        return;
                }

                for (uint8 i = 0; i < 3; ++i)
                {
                    if (Creature* pAdd = me->SummonCreature(VEHICLE_TO_SUMMON2, SpawnPosition, TEMPSUMMON_CORPSE_DESPAWN))
                    {
                        switch (uiSummonTimes)
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
                                pAdd->GetMotionMaster()->MoveFollow(pBoss, 2.5f, M_PI);
                                break;
                            case 1:
                                pAdd->GetMotionMaster()->MoveFollow(pBoss, 2.5f, M_PI / 2);
                                break;
                            case 2:
                                pAdd->GetMotionMaster()->MoveFollow(pBoss, 2.5f, M_PI / 2 + M_PI);
                                break;
                        }
                    }

                }
            }
        }

        void DoStartArgentChampionEncounter()
        {
            Talk(SAY_ARGENT_CHAMP_ENTERS);
            if (Creature* pBoss = me->SummonCreature(uiArgentChampion, SpawnPosition))
            {
                pBoss->GetMotionMaster()->MovePoint(1, 746.71f, 661.02f, 411.69f);
                for (uint8 i = 0; i < 3; ++i)
                {
                    if (Creature* pTrash = me->SummonCreature(NPC_ARGENT_LIGHWIELDER, SpawnPosition))
                        pTrash->AI()->SetData(i, 0);
                    if (Creature* pTrash = me->SummonCreature(NPC_ARGENT_MONK, SpawnPosition))
                        pTrash->AI()->SetData(i, 0);
                    if (Creature* pTrash = me->SummonCreature(NPC_PRIESTESS, SpawnPosition))
                        pTrash->AI()->SetData(i, 0);
                }
            }
        }

        void EnterCombat(Unit* pWho)
        {
            me->SetReactState(REACT_PASSIVE);
            if (Creature* pGhoul = me->SummonCreature(NPC_RISEN_JAEREN, 742.835f, 639.134f, 411.571f, 1.05731f))
            {
                pGhoul->setFaction(14);
            }
            if (pInstance)
                pInstance->SetData(DATA_AGRO_DONE, DONE);
        }

        void SetGrandChampionsForEncounter()
        {
            uiFirstBoss = urand(0, 4);

            while(uiSecondBoss == uiFirstBoss || uiThirdBoss == uiFirstBoss || uiThirdBoss == uiSecondBoss)
            {
                  uiSecondBoss = urand(0, 4);
                  uiThirdBoss = urand(0, 4);
            }
        }

        void SetArgentChampion()
        {
           uint8 uiTempBoss = urand(0, 1);

           switch (uiTempBoss)
           {
                case 0:
                    uiArgentChampion = NPC_EADRIC;
                    break;
                case 1:
                    uiArgentChampion = NPC_PALETRESS;
                    break;
           }
        }

        void StartEncounter()
        {
            if (!pInstance)
                return;

            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

            if (GameObject* pGO = GameObject::GetGameObject(*me, pInstance->GetData64(DATA_MAIN_GATE1)))
                pInstance->HandleGameObject(pGO->GetGUID(),false);

            if (pInstance->GetData(BOSS_BLACK_KNIGHT) == NOT_STARTED)
            {
                if (pInstance->GetData(BOSS_ARGENT_CHALLENGE_E) == NOT_STARTED && pInstance->GetData(BOSS_ARGENT_CHALLENGE_P) == NOT_STARTED)
                {
                    if (pInstance->GetData(BOSS_GRAND_CHAMPIONS) == NOT_STARTED)
                        me->AI()->SetData(DATA_START, NOT_STARTED);

                    if (pInstance->GetData(BOSS_GRAND_CHAMPIONS) == DONE)
                        DoStartArgentChampionEncounter();
                }

                if (pInstance->GetData(BOSS_GRAND_CHAMPIONS) == DONE && pInstance->GetData(BOSS_ARGENT_CHALLENGE_E) == DONE || pInstance->GetData(BOSS_ARGENT_CHALLENGE_P) == DONE)
                {
                   pVehicle_black_knight = me->SummonCreature(VEHICLE_BLACK_KNIGHT, 801.369507f, 640.574280f, 469.314362f, 3.97124f);
                   me->SetFacingToObject(pVehicle_black_knight);
                   me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                   me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                   me->SetReactState(REACT_AGGRESSIVE);
                   me->setFaction(2054);
                   Talk(SAY_INTRO_BLACK_KNIGHT_TIRION);
                }
            }
        }

        void AggroAllPlayers(Creature* pTemp)
        {
            Map::PlayerList const &PlList = me->GetMap()->GetPlayers();

            if (PlList.isEmpty())
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
                       pTemp->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                       pTemp->SetReactState(REACT_AGGRESSIVE);
                       pTemp->SetInCombatWith(player);
                       player->SetInCombatWith(pTemp);
                       pTemp->AddThreat(player, 0.0f);
                    }
                }
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            ScriptedAI::UpdateAI(uiDiff);

            if (uiTimer <= uiDiff)
            {
                switch (uiPhase)
                {
                    case 1:
                        DoSummonGrandChampion(uiSecondBoss);
                        NextStep(10000, true);
                        break;
                    case 2:
                        DoSummonGrandChampion(uiThirdBoss);
                        NextStep(0, false);
                        break;
                    case 3:
                        if (!Champion1List.empty())
                        {
                            for(std::list<uint64>::const_iterator itr = Champion1List.begin(); itr != Champion1List.end(); ++itr)
                                if (Creature* summon = Unit::GetCreature(*me, *itr))
                                    AggroAllPlayers(summon);
                            NextStep(0, false);
                        }
                        break;
                }
            }
            else
                uiTimer -= uiDiff;

            if (!UpdateVictim())
                return;
        }

        void JustSummoned(Creature* summon)
        {
            if (pInstance && pInstance->GetData(BOSS_GRAND_CHAMPIONS) == NOT_STARTED)
            {
                summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                summon->SetReactState(REACT_PASSIVE);
            }
        }

        void SummonedCreatureDespawn(Creature* summon)
        {
            switch (summon->GetEntry())
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
                    me->AI()->SetData(DATA_LESSER_CHAMPIONS_DEFEATED, 0);
                    break;
            }
        }
    };

    bool OnGossipHello(Player* player, Creature* creature)
    {
        InstanceScript* pInstance = creature->GetInstanceScript();

        if (pInstance &&
            pInstance->GetData(BOSS_GRAND_CHAMPIONS) == DONE &&
            pInstance->GetData(BOSS_BLACK_KNIGHT) == DONE &&
           (pInstance->GetData(BOSS_ARGENT_CHALLENGE_E) == DONE ||
            pInstance->GetData(BOSS_ARGENT_CHALLENGE_P) == DONE))

            return false;

        if (pInstance &&
            pInstance->GetData(BOSS_GRAND_CHAMPIONS) == NOT_STARTED &&
            pInstance->GetData(BOSS_ARGENT_CHALLENGE_E) == NOT_STARTED &&
            pInstance->GetData(BOSS_ARGENT_CHALLENGE_P) == NOT_STARTED &&
            pInstance->GetData(BOSS_BLACK_KNIGHT) == NOT_STARTED)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_START_EVENT1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        else
            if (pInstance)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_START_EVENT2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    };

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        {
            player->CLOSE_GOSSIP_MENU();
            CAST_AI(npc_announcer_toc5::npc_announcer_toc5AI, creature->AI())->StartEncounter();
        }

        return true;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_announcer_toc5AI(creature);
    };
};

void AddSC_trial_of_the_champion()
{
    new npc_anstart();
    new npc_announcer_toc5();
}

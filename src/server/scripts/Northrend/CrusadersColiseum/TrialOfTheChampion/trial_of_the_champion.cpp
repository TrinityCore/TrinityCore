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

/* ScriptData
SDName: Trial Of the Champion
SD%Complete: 90%
SDComment:
SDCategory: trial_of_the_champion
EndScriptData */

/* ContentData
npc_announcer_toc5
EndContentData */

#include "ScriptPCH.h"
#include "trial_of_the_champion.h"
#include "Vehicle.h"

#define GOSSIP_START_EVENT1     "I'm ready to start challenge." 
#define GOSSIP_START_EVENT2     "I'm ready for the next challenge." 
#define GOSSIP_START_EVENT3     "Let's face our last challenge." 

#define ORIENTATION             4.714f

/*######
## npc_announcer_toc5
######*/

const Position SpawnPosition = {746.565f, 665.056f, 411.756f, 4.77922f};
const Position GrandChampionSpawnPosition = {746.768f, 655.148f, 411.614f, 4.6842f};
const Position OutStadiumPosition = {747.03f, 687.483f, 412.373f, 1.53475f};
const Position AnnouncerPosition = {731.585f, 658.719f, 412.393f, 4.61586f};
const Position BlackKnightSpawnPosition = {796.404f, 643.282f, 466.518f, 2.33348f};
const Position FactionChampionPos[2][3] =
{
    {
        // Horde
        {724.854f, 640.344f, 411.829f, 5.60704f},
        {714.172f, 618.206f, 411.604f, 0.0f},
        {724.300f, 595.990f, 411.568f, 0.819248f},
    },
    {
        // Alliance
        {767.643f, 639.450f, 411.757f, 3.3663f},
        {779.169f, 618.351f, 411.607f, 3.06471f},
        {769.012f, 596.386f, 411.569f, 2.92883f},
    },
};
const Position ArgentSoldierPosition[3] =
{
    {746.875f, 650.358f, 411.569f, 4.77922f},
    {717.771f, 647.165f, 411.923f, 5.54734f},
    {775.734f, 644.413f, 411.919f, 3.79826f}
};

enum Says
{

    // Grand Champions
    SAY_TIRION_INTRO_CHAMPS_1  = 0,

    // Horde
    SAY_THRALL_INTRO_CHAMPS_H  = 0,
    SAY_GARROSH_INTRO_CHAMPS_H = 0,
    SAY_VARIAN_INTRO_CHAMPS_H  = 0,
    SAY_JAINA_INTRO_CHAMPS_H   = 0,
    // Alliance
    SAY_VARIAN_INTRO_CHAMPS_A  = 1,
    SAY_JAINA_INTRO_CHAMPS_A   = 1,
    SAY_GARROSH_INTRO_CHAMPS_A = 1,
    SAY_THRALL_INTRO_CHAMPS_A  = 1,

    SAY_TIRION_INTRO_CHAMPS_2  = 1,

    SAY_ANNOUNCER_NPC_MAGE     = 1,
    SAY_ANNOUNCER_NPC_SHAMAN   = 2,
    SAY_ANNOUNCER_NPC_HUNTER   = 3,
    SAY_ANNOUNCER_NPC_WARRIOR  = 4,
    SAY_ANNOUNCER_NPC_ROUGE    = 5,
    SAY_ANNOUNCER_INTRO_PLAYER = 0,
    SAY_ANNOUNCER_PLAYER       = -1999920,
    EMOTE_FACTION_CHEER        = -1999900,

    // Argent Challenge
    SAY_TIRION_INTRO_ARGENT_1  = 2,
    SAY_ANNOUNCER_EADRIC       = 11,
    SAY_ANNOUNCER_PALETRESS    = 12,
    SAY_EADRIC_INTRO           = 10,
    SAY_PALETRESS_INTRO_1      = 10,
    SAY_PALETRESS_INTRO_2      = 11,
    SAY_TIRION_INTRO_ARGENT_2  = 3,

    // Black Knight
    SAY_TIRION_INTRO_BK_1     = 4,
    SAY_ANNOUNCER_BK          = 13,
    SAY_BK_INTRO_1            = 10,
    SAY_TIRION_INTRO_BK_2     = 5,
    SAY_BK_INTRO_2            = 11,
    SAY_BK_INTRO_3            = 12,
    SAY_VARIAN_INTRO_BK       = 10,
    SAY_GARROSH_INTRO_BK      = 10,
};

enum GossipTexts
{
    GOSSIP_TEXT_NOT_MOUNTED_HORDE          = 15043,
    GOSSIP_TEXT_NOT_MOUNTED_ALLIANCE       = 14757,
    GOSSIP_TEXT_FACTION_CHAMPIONS_DEFEATED = 14737,
    GOSSIP_TEXT_ARGENT_CHAMPIONS_DEFEATED  = 14738,
};
class npc_announcer_toc5 : public CreatureScript
{
public:
    npc_announcer_toc5() : CreatureScript("npc_announcer_toc5") { }

    struct npc_announcer_toc5AI : public ScriptedAI
    {
        npc_announcer_toc5AI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        uint32 eventIds[EVENTS_MAX];

        uint32 bossEntry[3];
        uint64 bossGUID[3];
        uint64 addsGUID[3][3];
        uint64 stalkerGUID;
        std::set<int32> announceID;
        std::set<uint64> playersGUID;

        bool addsAttacking;
        uint8 defeatedCount;

        const Position* FactionChampionPosition()
        {
            if (instance->GetData(DATA_TEAM) == HORDE)
                return FactionChampionPos[1];
            else
                return FactionChampionPos[0];
        }

        void Reset()
        {
            events.Reset();
            for (uint8 i=0; i<EVENTS_MAX; i++)
                eventIds[i] = 0;

            for (uint8 i=0; i<3; i++)
            {
                bossEntry[i] = 0;
                bossGUID[i] = 0;
                for (uint8 j=0; j<3; j++)
                    addsGUID[i][j] = 0;
            }

            announceID.clear();
            playersGUID.clear();
            stalkerGUID = 0;
            defeatedCount = 0;
            addsAttacking = false;
        }

        void JustSummoned(Creature* summon)
        {
            summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            summon->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            summon->SetReactState(REACT_PASSIVE);
        }

        void SetData(uint32 type, uint32 data)
        {
            eventIds[type] = data;

            if (data == IN_PROGRESS)
            {
                events.ScheduleEvent(1, 0);
                if (type == EVENT_INTRO)
                {
                    Map::PlayerList const &PlList = me->GetMap()->GetPlayers();

                    if (!PlList.isEmpty())
                    {
                        for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
                        {
                            if (Player* player = i->getSource())
                            {
                                if (player->isGameMaster())
                                    continue;

                                playersGUID.insert(player->GetGUID());
                            }
                        }
                        for (uint8 i = 0; i<playersGUID.size(); i++)
                            announceID.insert(SAY_ANNOUNCER_PLAYER-i);
                    }

                    SetGrandChampionsForEncounter();
                }
            }
        }

        void SetGrandChampionsForEncounter()
        {
            if (instance->GetData(DATA_TEAM) == HORDE)
                bossEntry[0] = RAND(NPC_JACOB, NPC_LANA);
            else
                bossEntry[0] = RAND(NPC_MOKRA, NPC_VISCERI);

            while (bossEntry[1] == bossEntry[0] || bossEntry[2] == bossEntry[0] || bossEntry[2] == bossEntry[1])
            {
                if (instance->GetData(DATA_TEAM) == HORDE)
                {
                    bossEntry[1] = RAND(NPC_JACOB, NPC_AMBROSE, NPC_COLOSOS, NPC_JAELYNE, NPC_LANA);
                    bossEntry[2] = RAND(NPC_JACOB, NPC_AMBROSE, NPC_COLOSOS, NPC_JAELYNE, NPC_LANA);
                }else
                {
                    bossEntry[1] = RAND(NPC_MOKRA, NPC_ERESSEA, NPC_RUNOK, NPC_ZULTORE, NPC_VISCERI);
                    bossEntry[2] = RAND(NPC_MOKRA, NPC_ERESSEA, NPC_RUNOK, NPC_ZULTORE, NPC_VISCERI);
                }
            }
        }

        uint32 GetData(uint32 type)
        {
            return eventIds[type];
        }

        uint32 GetAddId(uint32 bossId)
        {
            switch(bossId)
            {
                // Alliance
                case NPC_JACOB:   return NPC_STORMWIND_CHAMPION;
                case NPC_AMBROSE: return NPC_GNOMEREGAN_CHAMPION;
                case NPC_COLOSOS: return NPC_EXODAR_CHAMPION;
                case NPC_JAELYNE: return NPC_DARNASSUS_CHAMPION;
                case NPC_LANA:    return NPC_IRONFORGE_CHAMPION;
                // Horde
                case NPC_MOKRA:   return NPC_ORGRIMMAR_CHAMPION;
                case NPC_ERESSEA: return NPC_SILVERMOON_CHAMPION;
                case NPC_RUNOK:   return NPC_THUNDER_BLUFF_CHAMPION;
                case NPC_ZULTORE: return NPC_SENJIN_CHAMPION;
                case NPC_VISCERI: return NPC_UNDERCITY_CHAMPION;
            }
            return 0;
        }

        void AnnounceChampion(Unit* champion)
        {
            if (champion->GetTypeId() ==  TYPEID_PLAYER)
            {
                if (!playersGUID.empty())
                {
                    if(Player* player = me->GetPlayer(*me, *playersGUID.begin()))
                    {
                        if (!announceID.empty())
                        {
                            int32 announce = SelectRandomContainerElement(announceID);
                            DoScriptText(announce, me, player);
                            announceID.erase(announce);
                        }
                        playersGUID.erase(*playersGUID.begin());
                        // Public emote
                        DoScriptText(EMOTE_FACTION_CHEER-player->getRace(), player);
                    }
                }
            }
            else
            {
                switch (champion->GetEntry())
                {
                    case NPC_MOKRA: // Warrior
                        Talk(SAY_ANNOUNCER_NPC_WARRIOR);
                        DoScriptText(EMOTE_FACTION_CHEER-RACE_ORC, champion);
                        break;
                    case NPC_JACOB:
                        Talk(SAY_ANNOUNCER_NPC_WARRIOR);
                        DoScriptText(EMOTE_FACTION_CHEER-RACE_HUMAN, champion);
                        break;
                    case NPC_ERESSEA: // Mage
                        Talk(SAY_ANNOUNCER_NPC_MAGE);
                        DoScriptText(EMOTE_FACTION_CHEER-RACE_BLOODELF, champion);
                        break;
                    case NPC_AMBROSE:
                        Talk(SAY_ANNOUNCER_NPC_MAGE);
                        DoScriptText(EMOTE_FACTION_CHEER-RACE_GNOME, champion);
                        break;
                    case NPC_RUNOK: // Saman
                        Talk(SAY_ANNOUNCER_NPC_SHAMAN);
                        DoScriptText(EMOTE_FACTION_CHEER-RACE_TAUREN, champion);
                        break;
                    case NPC_COLOSOS:
                        Talk(SAY_ANNOUNCER_NPC_SHAMAN);
                        DoScriptText(EMOTE_FACTION_CHEER-RACE_DRAENEI, champion);
                        break;
                    case NPC_JAELYNE: // Hunter
                        Talk(SAY_ANNOUNCER_NPC_HUNTER);
                        DoScriptText(EMOTE_FACTION_CHEER-RACE_NIGHTELF, champion);
                        break;
                    case NPC_ZULTORE:
                        Talk(SAY_ANNOUNCER_NPC_HUNTER);
                        DoScriptText(EMOTE_FACTION_CHEER-RACE_TROLL, champion);
                        break;
                    case NPC_VISCERI: // Rouge
                        Talk(SAY_ANNOUNCER_NPC_ROUGE);
                        DoScriptText(EMOTE_FACTION_CHEER-RACE_UNDEAD_PLAYER, champion);
                        break;
                    case NPC_LANA:
                        Talk(SAY_ANNOUNCER_NPC_ROUGE);
                        DoScriptText(EMOTE_FACTION_CHEER-RACE_DWARF, champion);
                        break;
                    case NPC_EADRIC:
                        Talk(SAY_ANNOUNCER_EADRIC);
                        DoScriptText(EMOTE_FACTION_CHEER, champion);
                        break;
                    case NPC_PALETRESS:
                        Talk(SAY_ANNOUNCER_PALETRESS);
                        DoScriptText(EMOTE_FACTION_CHEER, champion);
                        break;
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            events.Update(diff);

            if (GetData(EVENT_INTRO) == IN_PROGRESS)
            {
                switch(events.ExecuteEvent())
                {
                    case 1:
                        Talk(SAY_ANNOUNCER_INTRO_PLAYER);
                        events.ScheduleEvent(2, 7000);
                        break;
                    case 2:
                        if (!playersGUID.empty())
                        {
                            if (Player* player = me->GetMap()->GetPlayers().begin()->getSource())
                                AnnounceChampion(player);
                            events.ScheduleEvent(2, 8000);
                        } else
                            events.ScheduleEvent(3, 8000);

                        break;
                    case 3:
                        if (Creature* tirion = me->GetCreature(*me, instance->GetData64(DATA_TIRION)))
                            tirion->AI()->Talk(SAY_TIRION_INTRO_CHAMPS_1);

                        events.ScheduleEvent(4, 8000);
                        break;
                    case 4:
                        if (instance->GetData(DATA_TEAM) == HORDE)
                        {
                            if (Creature* thrall = me->GetCreature(*me, instance->GetData64(DATA_THRALL)))
                                thrall->AI()->Talk(SAY_THRALL_INTRO_CHAMPS_H);
                            events.ScheduleEvent(5, 5000);
                        } else
                        {
                            if (Creature* varian = me->GetCreature(*me, instance->GetData64(DATA_VARIAN)))
                                varian->AI()->Talk(SAY_VARIAN_INTRO_CHAMPS_A);
                            events.ScheduleEvent(5, 8000);
                        }
                        break;
                    case 5:
                        if (instance->GetData(DATA_TEAM) == HORDE)
                        {
                            if (Creature* garrosh = me->GetCreature(*me, instance->GetData64(DATA_GARROSH)))
                                garrosh->AI()->Talk(SAY_GARROSH_INTRO_CHAMPS_H);
                            events.ScheduleEvent(6, 8000);
                        } else
                        {
                            if (Creature* jaina = me->GetCreature(*me, instance->GetData64(DATA_JAINA)))
                                jaina->AI()->Talk(SAY_JAINA_INTRO_CHAMPS_A);
                            events.ScheduleEvent(6, 5000);
                        }
                        break;
                    case 6:
                        if (instance->GetData(DATA_TEAM) == HORDE)
                        {
                            if (Creature* varian = me->GetCreature(*me, instance->GetData64(DATA_VARIAN)))
                                varian->AI()->Talk(SAY_VARIAN_INTRO_CHAMPS_H);
                            events.ScheduleEvent(7, 8000);
                        } else
                        {
                            if (Creature* garrosh = me->GetCreature(*me, instance->GetData64(DATA_GARROSH)))
                                garrosh->AI()->Talk(SAY_GARROSH_INTRO_CHAMPS_A);
                            events.ScheduleEvent(7, 8000);
                        }
                        break;
                    case 7:
                        if (instance->GetData(DATA_TEAM) == HORDE)
                        {
                            if (Creature* jaina = me->GetCreature(*me, instance->GetData64(DATA_JAINA)))
                                jaina->AI()->Talk(SAY_JAINA_INTRO_CHAMPS_H);
                            events.ScheduleEvent(8, 5000);
                        } else
                        {
                            if (Creature* thrall = me->GetCreature(*me, instance->GetData64(DATA_THRALL)))
                                thrall->AI()->Talk(SAY_THRALL_INTRO_CHAMPS_A);
                            events.ScheduleEvent(8, 5000);
                        }
                        break;
                    case 8:
                        if (Creature* tirion = me->GetCreature(*me, instance->GetData64(DATA_TIRION)))
                            tirion->AI()->Talk(SAY_TIRION_INTRO_CHAMPS_2);

                        // Open door
                        if (GameObject* pGO = GameObject::GetGameObject(*me, instance->GetData64(DATA_MAIN_GATE)))
                            instance->HandleGameObject(pGO->GetGUID(), true);

                        events.ScheduleEvent(9, 7000);
                        break;
                    case 9:
                        // Summon invisible trigger for orientation prupouses only
                        if (Creature* stalker = me->SummonCreature(20562, me->GetPositionX() , me->GetPositionY(), me->GetPositionZ()))
                            stalkerGUID = stalker->GetGUID();

                        // Summon 1st Boss and adds and make them follow him
                        if (Creature* boss = me->SummonCreature(bossEntry[0], SpawnPosition))
                        {
                            bossGUID[0] = boss->GetGUID();
                            boss->SetTarget(stalkerGUID);
                            AnnounceChampion(boss->ToUnit());

                            for (uint8 i = 0; i < 3; ++i)
                            {
                                if (Creature* add = me->SummonCreature(GetAddId(boss->GetEntry()), SpawnPosition, TEMPSUMMON_MANUAL_DESPAWN))
                                {
                                    add->SetTarget(stalkerGUID);
                                    addsGUID[0][i] = add->GetGUID();
                                    switch(i)
                                    {
                                        case 0: add->GetMotionMaster()->MoveFollow(boss, 2.0f, M_PI); break;
                                        case 1: add->GetMotionMaster()->MoveFollow(boss, 2.0f, M_PI / 2); break;
                                        case 2: add->GetMotionMaster()->MoveFollow(boss, 2.0f, M_PI / 2 + M_PI); break;
                                    }
                                }
                            }
                        }
                        events.ScheduleEvent(10, 2000);
                        break;
                    case 10:
                        // Move first boss to the new position
                        if (Creature* boss1 = me->GetCreature(*me, bossGUID[0]))
                            boss1->GetMotionMaster()->MovePoint(0, FactionChampionPosition()[0]);

                        events.ScheduleEvent(11, 5000);
                        break;
                    case 11:
                        // Refresh the adds position
                        for (uint8 i=0; i<1; i++)
                        {
                            if (Creature* boss = me->GetCreature(*me, bossGUID[i]))
                            {
                                boss->SetFacingToObject(me);
                                for (uint8 j = 0; j<3; j++)
                                {
                                    if (Creature* add = me->GetCreature(*me, addsGUID[i][j]))
                                    {
                                        switch(j)
                                        {
                                            case 0: add->GetMotionMaster()->MoveFollow(boss, 2.0f, M_PI); break;
                                            case 1: add->GetMotionMaster()->MoveFollow(boss, 2.0f, M_PI / 2); break;
                                            case 2: add->GetMotionMaster()->MoveFollow(boss, 2.0f, M_PI / 2 + M_PI); break;
                                        }
                                    }
                                }
                            }
                        }
                        events.ScheduleEvent(12, 3000);
                        break;
                    case 12:
                        // Summon 2nd Boss and adds and make them follow him
                        if (Creature* boss = me->SummonCreature(bossEntry[1], SpawnPosition))
                        {
                            bossGUID[1] = boss->GetGUID();
                            boss->SetTarget(stalkerGUID);
                            AnnounceChampion(boss->ToUnit());

                            for (uint8 i = 0; i < 3; ++i)
                            {
                                if (Creature* add = me->SummonCreature(GetAddId(boss->GetEntry()), SpawnPosition, TEMPSUMMON_MANUAL_DESPAWN))
                                {
                                    add->SetTarget(stalkerGUID);
                                    addsGUID[1][i] = add->GetGUID();
                                    switch(i)
                                    {
                                        case 0: add->GetMotionMaster()->MoveFollow(boss, 2.0f, M_PI); break;
                                        case 1: add->GetMotionMaster()->MoveFollow(boss, 2.0f, M_PI / 2); break;
                                        case 2: add->GetMotionMaster()->MoveFollow(boss, 2.0f, M_PI / 2 + M_PI); break;
                                    }
                                }
                            }
                        }
                        events.ScheduleEvent(13, 5000);
                        break;
                    case 13:
                        // Move first boss to the new position
                        if (Creature* boss1 = me->GetCreature(*me, bossGUID[0]))
                            boss1->GetMotionMaster()->MovePoint(0, FactionChampionPosition()[1]);

                        // Move second boss to the new position
                        if (Creature* boss2 = me->GetCreature(*me, bossGUID[1]))
                            boss2->GetMotionMaster()->MovePoint(0, FactionChampionPosition()[0]);

                        events.ScheduleEvent(14, 5000);
                        break;
                    case 14:
                        // Refresh the adds position
                        for (uint8 i=0; i<2; i++)
                        {
                            if (Creature* boss = me->GetCreature(*me, bossGUID[i]))
                            {
                                boss->SetFacingToObject(me);
                                for (uint8 j = 0; j<3; j++)
                                {
                                    if (Creature* add = me->GetCreature(*me, addsGUID[i][j]))
                                    {
                                        switch(j)
                                        {
                                            case 0: add->GetMotionMaster()->MoveFollow(boss, 2.0f, M_PI); break;
                                            case 1: add->GetMotionMaster()->MoveFollow(boss, 2.0f, M_PI / 2); break;
                                            case 2: add->GetMotionMaster()->MoveFollow(boss, 2.0f, M_PI / 2 + M_PI); break;
                                        }
                                    }
                                }
                            }
                        }
                        events.ScheduleEvent(15, 4000);
                        break;
                    case 15:
                        // Summon 3rd Boss and adds and make them follow him
                        if (Creature* boss = me->SummonCreature(bossEntry[2], SpawnPosition))
                        {
                            bossGUID[2] = boss->GetGUID();
                            boss->SetTarget(stalkerGUID);
                            AnnounceChampion(boss->ToUnit());

                            for (uint8 i = 0; i < 3; ++i)
                            {
                                if (Creature* add = me->SummonCreature(GetAddId(boss->GetEntry()), SpawnPosition, TEMPSUMMON_MANUAL_DESPAWN))
                                {
                                    add->SetTarget(stalkerGUID);
                                    addsGUID[2][i] = add->GetGUID();
                                    switch(i)
                                    {
                                        case 0: add->GetMotionMaster()->MoveFollow(boss, 2.0f, M_PI); break;
                                        case 1: add->GetMotionMaster()->MoveFollow(boss, 2.0f, M_PI / 2); break;
                                        case 2: add->GetMotionMaster()->MoveFollow(boss, 2.0f, M_PI / 2 + M_PI); break;
                                    }
                                }
                            }
                        }
                        events.ScheduleEvent(16, 4000);
                        break;
                    case 16:
                        // Move first boss to the new position
                        if (Creature* boss1 = me->GetCreature(*me, bossGUID[0]))
                            boss1->GetMotionMaster()->MovePoint(0, FactionChampionPosition()[2]);

                        // Move second boss to the new position
                        if (Creature* boss2 = me->GetCreature(*me, bossGUID[1]))
                            boss2->GetMotionMaster()->MovePoint(0, FactionChampionPosition()[1]);

                        // Move third boss to the new position
                        if (Creature* boss2 = me->GetCreature(*me, bossGUID[2]))
                            boss2->GetMotionMaster()->MovePoint(0, FactionChampionPosition()[0]);

                        events.ScheduleEvent(17, 5000);
                        break;
                    case 17:
                        // Refresh the adds position
                        for (uint8 i=0; i<3; i++)
                        {
                            if (Creature* boss = me->GetCreature(*me, bossGUID[i]))
                            {
                                boss->SetFacingToObject(me);
                                for (uint8 j = 0; j<3; j++)
                                {
                                    if (Creature* add = me->GetCreature(*me, addsGUID[i][j]))
                                    {
                                        switch(j)
                                        {
                                            case 0: add->GetMotionMaster()->MoveFollow(boss, 2.0f, M_PI); break;
                                            case 1: add->GetMotionMaster()->MoveFollow(boss, 2.0f, M_PI / 2); break;
                                            case 2: add->GetMotionMaster()->MoveFollow(boss, 2.0f, M_PI / 2 + M_PI); break;
                                        }
                                    }
                                }
                            }
                        }
                        events.ScheduleEvent(18, 4000);
                        break;
                    case 18:
                        // Set home positions, in case of wipe, this avoids summons to go to the SpawnPos
                        for (uint8 i=0; i<3; i++)
                            if (Creature* boss = me->GetCreature(*me, bossGUID[i]))
                            {
                                boss->SetTarget(0);
                                boss->CastSpell(boss, SPELL_MOUNT_LANCE_STAND, true);
                                boss->SetHomePosition(boss->GetPositionX(), boss->GetPositionY(), boss->GetPositionZ(), boss->GetOrientation());
                            }

                        for (uint8 i=0; i<3; i++)
                            for (uint8 j=0; j<3; j++)
                                if (Creature* add = me->GetCreature(*me, addsGUID[i][j]))
                                {
                                    add->SetTarget(0);
                                    add->SetFacingToObject(me);
                                    add->CastSpell(add, SPELL_MOUNT_LANCE_STAND, true);
                                    add->SetHomePosition(add->GetPositionX(), add->GetPositionY(), add->GetPositionZ(), add->GetOrientation());
                                }

                        // Move to the door position
                        me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                        me->GetMotionMaster()->MovePoint(0, AnnouncerPosition);
                        me->SetTarget(stalkerGUID);
                        events.ScheduleEvent(19, 19000);
                        break;
                    case 19:
                        //Close Door
                        if (GameObject* pGO = GameObject::GetGameObject(*me, instance->GetData64(DATA_MAIN_GATE)))
                            instance->HandleGameObject(pGO->GetGUID(), false);

                        events.Reset();
                        SetData(EVENT_INTRO, DONE);
                        SetData(EVENT_WAVES, IN_PROGRESS);
                        break;
                }
            }

            if (GetData(EVENT_WAVES) == IN_PROGRESS)
            {
                switch(events.ExecuteEvent())
                {
                    case 1:
                        // Future texts?
                        events.ScheduleEvent(2, 3000);
                        break;
                    case 2:
                        // Start attack of first wave of adds
                        if (!addsAttacking)
                        {
                            for (uint8 i=0; i<3; i++)
                            {
                                if (Creature* add = me->GetCreature(*me, addsGUID[0][i]))
                                {
                                    add->RemoveAurasDueToSpell(SPELL_MOUNT_LANCE_STAND);
                                    add->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                    add->SetReactState(REACT_AGGRESSIVE);
                                    add->setFaction(16);
                                    AggroAllPlayers(add);
                                }
                            }
                            addsAttacking = true;
                            events.ScheduleEvent(2, 1000);
                        } else // Wait for the death of all of them
                        {
                            defeatedCount = 0;
                            for (uint8 i=0; i<3; i++)
                                if (Creature* add = me->GetCreature(*me, addsGUID[0][i]))
                                    if (add->isDead())
                                        defeatedCount++;

                            if (defeatedCount>=3)
                            {
                                defeatedCount = 0;
                                addsAttacking = false;
                                events.ScheduleEvent(3, 4000);
                            } else
                                events.ScheduleEvent(2, 1000);
                        }
                        break;
                    case 3:
                        // Despawn previous wave
                        for (uint8 i=0; i<3; i++)
                            if (Creature* add = me->GetCreature(*me, addsGUID[0][i]))
                                add->DespawnOrUnsummon();

                        // Start attack of second wave of adds
                        if (!addsAttacking)
                        {
                            for (uint8 i=0; i<3; i++)
                            {
                                if (Creature* add = me->GetCreature(*me, addsGUID[1][i]))
                                {
                                    add->RemoveAurasDueToSpell(SPELL_MOUNT_LANCE_STAND);
                                    add->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                    add->SetReactState(REACT_AGGRESSIVE);
                                    add->setFaction(16);
                                    AggroAllPlayers(add);
                                }
                            }
                            addsAttacking = true;
                            events.ScheduleEvent(3, 1000);
                        } else // Wait for the death of all of them
                        {
                            defeatedCount = 0;
                            for (uint8 i=0; i<3; i++)
                                if (Creature* add = me->GetCreature(*me, addsGUID[1][i]))
                                    if (add->isDead())
                                        defeatedCount++;

                            if (defeatedCount>=3)
                            {
                                defeatedCount = 0;
                                addsAttacking = false;
                                events.ScheduleEvent(4, 4000);
                            } else
                                events.ScheduleEvent(3, 1000);
                        }
                        break;
                    case 4:
                        // Despawn previous wave
                        for (uint8 i=0; i<3; i++)
                            if (Creature* add = me->GetCreature(*me, addsGUID[1][i]))
                                add->DespawnOrUnsummon();

                        // Start attack of third wave of adds
                        if (!addsAttacking)
                        {
                            for (uint8 i=0; i<3; i++)
                            {
                                if (Creature* add = me->GetCreature(*me, addsGUID[2][i]))
                                {
                                    add->RemoveAurasDueToSpell(SPELL_MOUNT_LANCE_STAND);
                                    add->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                    add->SetReactState(REACT_AGGRESSIVE);
                                    add->setFaction(16);
                                    AggroAllPlayers(add);
                                }
                            }
                            addsAttacking = true;
                            events.ScheduleEvent(4, 1000);
                        } else // Wait for the death of all of them
                        {
                            defeatedCount = 0;
                            for (uint8 i=0; i<3; i++)
                                if (Creature* add = me->GetCreature(*me, addsGUID[2][i]))
                                    if (add->isDead())
                                        defeatedCount++;

                            if (defeatedCount>=3)
                            {
                                defeatedCount = 0;
                                addsAttacking = false;
                                events.ScheduleEvent(5, 4000);
                            } else
                                events.ScheduleEvent(4, 1000);
                        }
                        break;
                    case 5:
                        // Despawn previous wave
                        for (uint8 i=0; i<3; i++)
                            if (Creature* add = me->GetCreature(*me, addsGUID[2][i]))
                                add->DespawnOrUnsummon();

                        // Start attack of wave of bosses
                        if (!addsAttacking)
                        {
                            for (uint8 i=0; i<3; i++)
                            {
                                if (Creature* add = me->GetCreature(*me, bossGUID[i]))
                                {
                                    add->RemoveAurasDueToSpell(SPELL_MOUNT_LANCE_STAND);
                                    add->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                    add->SetReactState(REACT_AGGRESSIVE);
                                    add->setFaction(16);
                                    AggroAllPlayers(add);
                                }
                            }
                            addsAttacking = true;
                            events.ScheduleEvent(5, 1000);
                        } else // Wait for the death of all of them
                        {
                            defeatedCount = 0;
                            for (uint8 i=0; i<3; i++)
                                if (Creature* add = me->GetCreature(*me, bossGUID[i]))
                                    if (add->AI()->GetData(DATA_CHAMPION_DEFEATED) == 1)
                                        defeatedCount++;

                            if (defeatedCount>=3)
                            {
                                defeatedCount = 0;
                                addsAttacking = false;
                                events.ScheduleEvent(6, 0);
                            } else
                                events.ScheduleEvent(5, 1000);
                        }
                        break;
                    case 6:
                        // Despawn boss wave
                        for (uint8 i=0; i<3; i++)
                            if (Creature* add = me->GetCreature(*me, bossGUID[i]))
                                add->DespawnOrUnsummon();

                        events.Reset();
                        SetData(EVENT_WAVES, DONE);
                        SetData(EVENT_CHAMPIONS, IN_PROGRESS);
                        instance->SetData(MINION_ENCOUNTER, DONE);
                        instance->SetData(BOSS_GRAND_CHAMPIONS, SPECIAL);
                        break;
                }
            }

            if (GetData(EVENT_CHAMPIONS) == IN_PROGRESS)
            {
                switch(events.ExecuteEvent())
                {
                    case 1:
                        AreAllPlayersMounted(true);
                        events.ScheduleEvent(2, 0);
                        break;
                    case 2:
                        for (uint8 i=0; i<3; i++)
                        {
                            if (Creature* boss = me->SummonCreature(bossEntry[i], GrandChampionSpawnPosition))
                            {
                                bossGUID[i] = boss->GetGUID();
                                boss->SetTarget(stalkerGUID);
                                // Save current boss entry to inst for achievement check
                                instance->SetData64(DATA_GRAND_CHAMPION_GUID, boss->GetGUID());
                                instance->SetData(DATA_GRAND_CHAMPION_ENTRY, boss->GetEntry());
                                // Prevent bosses from falling down the ground
                                boss->SetPosition(boss->GetPositionX(), boss->GetPositionY(), boss->GetPositionZ()+0.1f, boss->GetOrientation());
                                // Set positions
                                switch(i)
                                {
                                    case 1: boss->GetMotionMaster()->MoveFollow(me->GetCreature(*me, bossGUID[0]), 5.0f, (M_PI / 2) + 0.5f); break;
                                    case 2: boss->GetMotionMaster()->MoveFollow(me->GetCreature(*me, bossGUID[0]), 5.0f, (M_PI / 2 + M_PI) - 0.5f); break;
                                }
                            }
                        }
                        events.ScheduleEvent(3, 2000);
                        break;
                    case 3:
                        for (uint8 i=0; i<3; i++)
                            if (Creature* boss = me->GetCreature(*me, bossGUID[i]))
                            {
                                if (Creature* tirion = me->GetCreature(*me, instance->GetData64(DATA_TIRION)))
                                    boss->SetFacingToObject(tirion);
                                boss->SetHomePosition(boss->GetPositionX(), boss->GetPositionY(), boss->GetPositionZ() + 1.0f, boss->GetOrientation());
                                boss->SetReactState(REACT_AGGRESSIVE);
                                boss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
                            }
                        events.ScheduleEvent(4, 10000);
                        break;
                    case 4: // Wait for the death of all of them
                        if (instance->GetData(BOSS_GRAND_CHAMPIONS) == IN_PROGRESS)
                        {
                            for (uint8 i=0; i<3; i++)
                                if (Creature* boss = me->GetCreature(*me, bossGUID[i]))
                                    if (!boss->isInCombat())
                                        AggroAllPlayers(boss);
                        }

                        defeatedCount = 0;
                        for (uint8 i=0; i<3; i++)
                            if (Creature* boss = me->GetCreature(*me, bossGUID[i]))
                                if (boss->AI()->GetData(DATA_CHAMPION_DEFEATED) == 1)
                                    defeatedCount++;

                        if (defeatedCount>=3)
                        {
                            defeatedCount = 0;
                            addsAttacking = false;
                            events.ScheduleEvent(5, 0);
                        } else
                            events.ScheduleEvent(4, 1000);
                        break;
                    case 5:
                        for (uint8 i=0; i<3; i++)
                            if (Creature* boss = me->GetCreature(*me, bossGUID[i]))
                            {
                                boss->GetMotionMaster()->MovePoint(0, OutStadiumPosition);
                                boss->DespawnOrUnsummon(4000);
                            }
                        SetData(EVENT_CHAMPIONS, DONE);
                        instance->SetData(BOSS_GRAND_CHAMPIONS, DONE);
                        break;
                }
            }

            if (GetData(EVENT_INTRO_ARGENT) == IN_PROGRESS)
            {
                switch(events.ExecuteEvent())
                {
                    case 1:
                        if (Creature* tirion = me->GetCreature(*me, instance->GetData64(DATA_TIRION)))
                            tirion->AI()->Talk(SAY_TIRION_INTRO_ARGENT_1);
                        // Open door
                        if (GameObject* pGO = GameObject::GetGameObject(*me, instance->GetData64(DATA_MAIN_GATE)))
                            instance->HandleGameObject(pGO->GetGUID(), true);
                        events.ScheduleEvent(2, 2000);
                        break;
                    case 2:
                        // Summon 1st wave
                        // The main add will move, and the two other will only follow him
                        if (Creature* mainAdd = me->SummonCreature(NPC_ARGENT_LIGHWIELDER, SpawnPosition))
                        {
                            addsGUID[0][0] = mainAdd->GetGUID();
                            mainAdd->SetTarget(stalkerGUID);

                            for (uint8 i = 0; i < 2; ++i)
                            {
                                uint32 addEntry = 0;
                                switch(i)
                                {
                                    case 0: addEntry = NPC_ARGENT_MONK; break;
                                    case 1: addEntry = NPC_ARGENT_PRIESTESS; break;
                                }

                                if (Creature* add = me->SummonCreature(addEntry, SpawnPosition, TEMPSUMMON_MANUAL_DESPAWN))
                                {
                                    add->SetTarget(stalkerGUID);
                                    addsGUID[0][i+1] = add->GetGUID();
                                    switch(i)
                                    {
                                        case 0: add->GetMotionMaster()->MoveFollow(mainAdd, 1.0f, (M_PI / 2) + 0.5f); break;
                                        case 1: add->GetMotionMaster()->MoveFollow(mainAdd, 1.0f, (M_PI / 2 + M_PI) - 0.5f); break;
                                    }
                                }
                            }
                        }
                        events.ScheduleEvent(3, 2000);
                        break;
                    case 3:
                        // Move first wave to his position
                        if (Creature* mainAdd1 = me->GetCreature(*me, addsGUID[0][0]))
                            mainAdd1->GetMotionMaster()->MovePoint(0, ArgentSoldierPosition[0]);

                        events.ScheduleEvent(4, 3000);
                        break;
                    case 4:
                        // Refresh the adds position
                        for (uint8 i=0; i<1; i++)
                        {
                            if (Creature* mainAdd = me->GetCreature(*me, addsGUID[i][0]))
                            {
                                mainAdd->SetFacingToObject(me);
                                for (uint8 j = 0; j<3; j++)
                                {
                                    if (Creature* add = me->GetCreature(*me, addsGUID[i][j]))
                                    {
                                        switch(j)
                                        {
                                            case 1: add->GetMotionMaster()->MoveFollow(mainAdd, 1.0f, (M_PI / 2) + 0.5f); break;
                                            case 2: add->GetMotionMaster()->MoveFollow(mainAdd, 1.0f, (M_PI / 2 + M_PI) - 0.5f); break;
                                        }
                                    }
                                }
                            }
                        }
                        events.ScheduleEvent(5, 3000);
                        break;
                    case 5:
                        // Summon 2nd wave
                        if (Creature* mainAdd = me->SummonCreature(NPC_ARGENT_LIGHWIELDER, SpawnPosition))
                        {
                            addsGUID[1][0] = mainAdd->GetGUID();
                            mainAdd->SetTarget(stalkerGUID);

                            for (uint8 i = 0; i < 2; ++i)
                            {
                                uint32 addEntry = 0;
                                switch(i)
                                {
                                    case 0: addEntry = NPC_ARGENT_MONK; break;
                                    case 1: addEntry = NPC_ARGENT_PRIESTESS; break;
                                }

                                if (Creature* add = me->SummonCreature(addEntry, SpawnPosition, TEMPSUMMON_MANUAL_DESPAWN))
                                {
                                    add->SetTarget(stalkerGUID);
                                    addsGUID[1][i+1] = add->GetGUID();
                                    switch(i)
                                    {
                                        case 0: add->GetMotionMaster()->MoveFollow(mainAdd, 1.0f, (M_PI / 2) + 0.5f); break;
                                        case 1: add->GetMotionMaster()->MoveFollow(mainAdd, 1.0f, (M_PI / 2 + M_PI) - 0.5f); break;
                                    }
                                }
                            }
                        }
                        events.ScheduleEvent(6, 5000);
                        break;
                    case 6:
                        // Move first wave to the new position
                        if (Creature* mainAdd1 = me->GetCreature(*me, addsGUID[0][0]))
                            mainAdd1->GetMotionMaster()->MovePoint(0, ArgentSoldierPosition[1]);

                        // Move second wave to the new position
                        if (Creature* mainAdd2 = me->GetCreature(*me, addsGUID[1][0]))
                            mainAdd2->GetMotionMaster()->MovePoint(0, ArgentSoldierPosition[0]);

                        events.ScheduleEvent(7, 4000);
                        break;
                    case 7:
                        // Refresh the adds position
                        for (uint8 i=0; i<2; i++)
                        {
                            if (Creature* mainAdd = me->GetCreature(*me, addsGUID[i][0]))
                            {
                                mainAdd->SetFacingToObject(me);
                                for (uint8 j = 0; j<3; j++)
                                {
                                    if (Creature* add = me->GetCreature(*me, addsGUID[i][j]))
                                    {
                                        switch(j)
                                        {
                                            case 1: add->GetMotionMaster()->MoveFollow(mainAdd, 1.0f, (M_PI / 2) + 0.5f); break;
                                            case 2: add->GetMotionMaster()->MoveFollow(mainAdd, 1.0f, (M_PI / 2 + M_PI) - 0.5f); break;
                                        }
                                    }
                                }
                            }
                        }
                        events.ScheduleEvent(8, 4000);
                        break;
                    case 8:
                        // Summon 3rd wave
                        if (Creature* mainAdd = me->SummonCreature(NPC_ARGENT_LIGHWIELDER, SpawnPosition))
                        {
                            addsGUID[2][0] = mainAdd->GetGUID();
                            mainAdd->SetTarget(stalkerGUID);

                            for (uint8 i = 0; i < 2; ++i)
                            {
                                uint32 addEntry = 0;
                                switch(i)
                                {
                                    case 0: addEntry = NPC_ARGENT_MONK; break;
                                    case 1: addEntry = NPC_ARGENT_PRIESTESS; break;
                                }

                                if (Creature* add = me->SummonCreature(addEntry, SpawnPosition, TEMPSUMMON_MANUAL_DESPAWN))
                                {
                                    add->SetTarget(stalkerGUID);
                                    addsGUID[2][i+1] = add->GetGUID();
                                    switch(i)
                                    {
                                        case 0: add->GetMotionMaster()->MoveFollow(mainAdd, 1.0f, (M_PI / 2) + 0.5f); break;
                                        case 1: add->GetMotionMaster()->MoveFollow(mainAdd, 1.0f, (M_PI / 2 + M_PI) - 0.5f); break;
                                    }
                                }
                            }
                        }
                        events.ScheduleEvent(9, 4000);
                        break;
                    case 9:
                        // Move second wave to the new position
                        if (Creature* mainAdd2 = me->GetCreature(*me, addsGUID[1][0]))
                            mainAdd2->GetMotionMaster()->MovePoint(0, ArgentSoldierPosition[2]);

                        // Move third wave to the new position
                        if (Creature* mainAdd3 = me->GetCreature(*me, addsGUID[2][0]))
                            mainAdd3->GetMotionMaster()->MovePoint(0, ArgentSoldierPosition[0]);

                        events.ScheduleEvent(10, 4000);
                        break;
                    case 10:
                        // Refresh the adds position
                        for (uint8 i=0; i<3; i++)
                        {
                            if (Creature* mainAdd = me->GetCreature(*me, addsGUID[i][0]))
                            {
                                mainAdd->SetFacingToObject(me);
                                for (uint8 j = 0; j<3; j++)
                                {
                                    if (Creature* add = me->GetCreature(*me, addsGUID[i][j]))
                                    {
                                        switch(j)
                                        {
                                            case 1: add->GetMotionMaster()->MoveFollow(mainAdd, 1.0f, (M_PI / 2) + 0.5f); break;
                                            case 2: add->GetMotionMaster()->MoveFollow(mainAdd, 1.0f, (M_PI / 2 + M_PI) - 0.5f); break;
                                        }
                                    }
                                }
                            }
                        }
                        events.ScheduleEvent(11, 4000);
                        break;
                    case 11:
                        // Summon the boss
                        bool chance;
                        chance = urand(0, 1);
                        if (Creature* boss = me->SummonCreature(chance ? NPC_EADRIC : NPC_PALETRESS, SpawnPosition))
                        {
                            AnnounceChampion(boss);
                            bossGUID[0] = boss->GetGUID();
                        }
                        events.ScheduleEvent(12, 4000);
                        break;
                    case 12:
                        // Set home positions, in case of wipe, this avoids summons goin back to the SpawnPos
                        if (Creature* boss = me->GetCreature(*me, bossGUID[0]))
                        {
                            boss->SetHomePosition(boss->GetPositionX(), boss->GetPositionY(), boss->GetPositionZ(), boss->GetOrientation());
                            switch (boss->GetEntry())
                            {
                                case NPC_EADRIC: boss->AI()->Talk(SAY_EADRIC_INTRO); break;
                                case NPC_PALETRESS: boss->AI()->Talk(SAY_PALETRESS_INTRO_1); break;
                            }
                        }

                        for (uint8 i=0; i<3; i++)
                            for (uint8 j=0; j<3; j++)
                                if (Creature* add = me->GetCreature(*me, addsGUID[i][j]))
                                {
                                    add->SetFacingToObject(me);
                                    add->SetHomePosition(add->GetPositionX(), add->GetPositionY(), add->GetPositionZ(), add->GetOrientation());
                                }
                        events.ScheduleEvent(13, 4000);
                        break;
                    case 13:
                        // Set home positions, in case of wipe, this avoids summons goin back to the SpawnPos
                        if (Creature* boss = me->GetCreature(*me, bossGUID[0]))
                        {
                            switch (boss->GetEntry())
                            {
                                case NPC_PALETRESS: boss->AI()->Talk(SAY_PALETRESS_INTRO_2); break;
                            }
                        }
                        // Move to the door position
                        me->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                        me->GetMotionMaster()->MovePoint(0, AnnouncerPosition);
                        me->SetTarget(stalkerGUID);
                        events.ScheduleEvent(14, 19000);
                        break;
                    case 14:
                        //Close Door
                        if (GameObject* pGO = GameObject::GetGameObject(*me, instance->GetData64(DATA_MAIN_GATE)))
                            instance->HandleGameObject(pGO->GetGUID(), false);

                        if (Creature* tirion = me->GetCreature(*me, instance->GetData64(DATA_TIRION)))
                            tirion->AI()->Talk(SAY_TIRION_INTRO_ARGENT_2);

                        events.Reset();
                        SetData(EVENT_INTRO_ARGENT, DONE);
                        SetData(EVENT_WAVES_ARGENT, IN_PROGRESS);
                        break;
                }
            }

            if (GetData(EVENT_WAVES_ARGENT) == IN_PROGRESS)
            {
                switch(events.ExecuteEvent())
                {
                    case 1:
                        // Future texts?
                        events.ScheduleEvent(2, 3000);
                        break;
                    case 2:
                        // Start attack of first wave of adds
                        if (!addsAttacking)
                        {
                            for (uint8 j=0; j<3; j++)
                            {
                                for (uint8 i=0; i<3; i++)
                                {
                                    if (Creature* add = me->GetCreature(*me, addsGUID[j][i]))
                                    {
                                        add->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                        add->SetReactState(REACT_AGGRESSIVE);
                                        add->setFaction(16);
                                    }
                                }
                            }
                            addsAttacking = true;
                            events.ScheduleEvent(2, 1000);
                        } else // Wait for the death of all of them
                        {
                            defeatedCount = 0;

                            for (uint8 j=0; j<3; j++)
                                for (uint8 i=0; i<3; i++)
                                    if (Creature* add = me->GetCreature(*me, addsGUID[j][i]))
                                    {
                                        if (add->isDead())
                                            defeatedCount++;
                                    } else defeatedCount++;

                            if (defeatedCount>=9)
                            {
                                defeatedCount = 0;
                                addsAttacking = false;
                                instance->SetData(MINION_ENCOUNTER, DONE);
                                events.ScheduleEvent(3, 4000);
                            } else
                                events.ScheduleEvent(2, 1000);
                        }
                        break;
                    case 3:
                        // Despawn previous wave
                        for (uint8 j=0; j<3; j++)
                            for (uint8 i=0; i<3; i++)
                                if (Creature* add = me->GetCreature(*me, addsGUID[j][i]))
                                    add->DespawnOrUnsummon();

                        // Prepare the Argent Champion for the fight
                        if (!addsAttacking)
                        {
                            if (Creature* boss = me->GetCreature(*me, bossGUID[0]))
                            {
                                boss->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                                boss->GetMotionMaster()->MovePoint(0, ArgentSoldierPosition[0]);
                                boss->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                boss->SetReactState(REACT_AGGRESSIVE);
                                boss->setFaction(16);
                            }
                            addsAttacking = true;
                            events.ScheduleEvent(3, 1000);
                        } else // Wait for his/her death
                        {
                            if (Creature* boss = me->GetCreature(*me, bossGUID[0]))
                            {
                                if (boss->AI()->GetData(DATA_CHAMPION_DEFEATED) == 1)
                                    events.ScheduleEvent(4, 0);
                                else
                                    events.ScheduleEvent(3, 1000);
                            }
                        }
                        break;
                    case 4:
                        // Mark encounter as completed
                        events.Reset();
                        SetData(EVENT_WAVES_ARGENT, DONE);
                        if (Creature* boss = me->GetCreature(*me, bossGUID[0]))
                        {
                            if (boss->GetEntry() == NPC_EADRIC)
                                instance->SetData(BOSS_ARGENT_CHALLENGE_E, DONE);
                            else
                                instance->SetData(BOSS_ARGENT_CHALLENGE_P, DONE);
                        }
                        break;
                }
            }

            if (GetData(EVENT_BLACK_KNIGHT_INTRO) == IN_PROGRESS)
            {
                switch(events.ExecuteEvent())
                {
                    case 1:
                        if (Creature* tirion = me->GetCreature(*me, instance->GetData64(DATA_TIRION)))
                            tirion->AI()->Talk(SAY_TIRION_INTRO_BK_1);

                        events.ScheduleEvent(2, 3000);
                        break;
                    case 2:
                        if (Creature* mount = me->GetCreature(*me, instance->GetData64(DATA_BLACK_KNIGHT_GRYPHON)))
                        {
                            mount->SetPhaseMask(1, true);
                            if (Creature* knight = me->GetCreature(*me, instance->GetData64(DATA_BLACK_KNIGHT)))
                                knight->SetPhaseMask(1, true);
                            Talk(SAY_ANNOUNCER_BK);
                            mount->AI()->SetData(1, 0);
                            me->SetTarget(mount->GetGUID());
                        }
                        events.ScheduleEvent(3, 15000);
                        break;
                    case 3:
                        if (Creature* blackKinght = me->GetCreature(*me, instance->GetData64(DATA_BLACK_KNIGHT)))
                        {
                            if (blackKinght->GetVehicle())
                                events.ScheduleEvent(3, 2000);
                            else
                            {
                                blackKinght->SetTarget(me->GetGUID());
                                me->SetTarget(blackKinght->GetGUID());
                                events.ScheduleEvent(4, 2000);
                            }
                        }
                        break;
                    case 4:
                        if (Creature* blackKinght = me->GetCreature(*me, instance->GetData64(DATA_BLACK_KNIGHT)))
                        {
                            blackKinght->AI()->Talk(SAY_BK_INTRO_1);
                            blackKinght->AI()->DoCast(SPELL_DEATH_RESPITE_INTRO);
                        }
                        events.ScheduleEvent(5, 4000);
                        break;
                    case 5:
                        if (Creature* blackKinght = me->GetCreature(*me, instance->GetData64(DATA_BLACK_KNIGHT)))
                        {
                            blackKinght->AI()->DoCast(me, SPELL_DEATH_PUSH_INTRO);
                            blackKinght->SetTarget(0);
                        }
                        events.ScheduleEvent(6, 2000);
                        break;
                    case 6:
                        if (Creature* tirion = me->GetCreature(*me, instance->GetData64(DATA_TIRION)))
                        {
                            tirion->AI()->Talk(SAY_TIRION_INTRO_BK_2);
                            if (Creature* blackKinght = me->GetCreature(*me, instance->GetData64(DATA_BLACK_KNIGHT)))
                            {
                                DoCast(57626); // Feign death
                                blackKinght->SetTarget(tirion->GetGUID());
                            }
                        }
                        events.ScheduleEvent(7, 3000);
                        break;
                    case 7:
                        if (Creature* blackKinght = me->GetCreature(*me, instance->GetData64(DATA_BLACK_KNIGHT)))
                            blackKinght->AI()->Talk(SAY_BK_INTRO_2);
                        events.ScheduleEvent(8, 9000);
                        break;
                    case 8:
                        if (Creature* blackKinght = me->GetCreature(*me, instance->GetData64(DATA_BLACK_KNIGHT)))
                            blackKinght->AI()->Talk(SAY_BK_INTRO_3);
                        events.ScheduleEvent(9, 5000);
                        break;
                    case 9:
                        if (instance->GetData(DATA_TEAM) == HORDE)
                        {
                            if (Creature* garrosh = me->GetCreature(*me, instance->GetData64(DATA_GARROSH)))
                                garrosh->AI()->Talk(SAY_GARROSH_INTRO_BK);
                        } else
                        {
                            if (Creature* varian = me->GetCreature(*me, instance->GetData64(DATA_VARIAN)))
                                varian->AI()->Talk(SAY_VARIAN_INTRO_BK);
                        }

                        SetData(EVENT_BLACK_KNIGHT_INTRO, DONE);
                        events.Reset();
                        if (Creature* blackKinght = me->GetCreature(*me, instance->GetData64(DATA_BLACK_KNIGHT)))
                        {
                            blackKinght->SetHomePosition(blackKinght->GetPositionX(), blackKinght->GetPositionY(), blackKinght->GetPositionZ(), blackKinght->GetOrientation());
                            blackKinght->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            blackKinght->SetReactState(REACT_AGGRESSIVE);
                            blackKinght->Kill(me);
                        }
                        break;
                }
            }
        }

        /**
        Used for checking if players are mounted before starting gauntlet
        and teleporting and unmounting them after defeating the mounted waves.
        */
        bool AreAllPlayersMounted(bool dismountAndTeleport = false)
        {
            Map::PlayerList const &PlList = me->GetMap()->GetPlayers();

            if (PlList.isEmpty())
                return false;

            for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
                if (Player* player = i->getSource())
                {
                    if (player->isGameMaster())
                        continue;

                    if (player->isAlive())
                    {
                        if (Creature* mount = player->GetVehicleCreatureBase())
                        {
                            if (dismountAndTeleport)
                            {
                                player->ExitVehicle();
                                mount->DespawnOrUnsummon();
                            }
                        } else if (!dismountAndTeleport)
                            return false;

                        if (dismountAndTeleport)
                            player->NearTeleportTo(746.851f, 608.875f, 411.172f, 1.60308f);
                    }
                }

            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_announcer_toc5AI(creature);
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        InstanceScript* instance = creature->GetInstanceScript();
        uint32 gossipTextId = 0;

        if (player->isGameMaster())
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_START_EVENT1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_START_EVENT2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_START_EVENT3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            gossipTextId = player->GetGossipTextId(creature);
        }
        else if (instance->GetData(BOSS_GRAND_CHAMPIONS) != DONE)
        {
            if (CAST_AI(npc_announcer_toc5::npc_announcer_toc5AI, creature->AI())->AreAllPlayersMounted())
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_START_EVENT1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
            gossipTextId = creature->GetEntry() == NPC_JAEREN ? GOSSIP_TEXT_NOT_MOUNTED_HORDE : GOSSIP_TEXT_NOT_MOUNTED_ALLIANCE;
        }else if (instance->GetData(BOSS_ARGENT_CHALLENGE_E) != DONE && instance->GetData(BOSS_ARGENT_CHALLENGE_P) != DONE)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_START_EVENT2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            gossipTextId = GOSSIP_TEXT_FACTION_CHAMPIONS_DEFEATED;
        }
        else
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_START_EVENT3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            gossipTextId = GOSSIP_TEXT_ARGENT_CHAMPIONS_DEFEATED;
        }

        player->SEND_GOSSIP_MENU(gossipTextId, creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();

        // Remove chest (if any) before starting anything else
        if (InstanceScript* instance = creature->GetInstanceScript())
            if (GameObject* chest = GameObject::GetGameObject(*creature, instance->GetData64(DATA_CHEST)))
                chest->RemoveFromWorld();

        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF:
                if (creature->AI()->GetData(EVENT_INTRO) != IN_PROGRESS)
                {
                    creature->AI()->SetData(EVENT_INTRO, IN_PROGRESS);
                    creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    player->CLOSE_GOSSIP_MENU();
                }
                break;
            case GOSSIP_ACTION_INFO_DEF+1:
                if (creature->AI()->GetData(EVENT_INTRO_ARGENT) != IN_PROGRESS)
                {
                    creature->AI()->SetData(EVENT_INTRO_ARGENT, IN_PROGRESS);
                    creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    player->CLOSE_GOSSIP_MENU();
                }
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                if (creature->AI()->GetData(EVENT_BLACK_KNIGHT_INTRO) != IN_PROGRESS)
                {
                    creature->AI()->SetData(EVENT_BLACK_KNIGHT_INTRO, IN_PROGRESS);
                    creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    player->CLOSE_GOSSIP_MENU();
                }
                break;
        }

        return true;
    }
};

void AddSC_trial_of_the_champion()
{
    new npc_announcer_toc5();
}

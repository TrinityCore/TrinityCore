/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
SDName: Instance_Karazhan
SD%Complete: 70
SDComment: Instance Script for Karazhan to help in various encounters. @todo GameObject visibility for Opera event.
SDCategory: Karazhan
EndScriptData */

#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "karazhan.h"
#include "Containers.h"
#include "Map.h"

/*
0  - Attumen + Midnight (optional)
1  - Moroes
2  - Maiden of Virtue (optional)
3  - Hyakiss the Lurker /  Rokad the Ravager  / Shadikith the Glider
4  - Opera Event
5  - Curator
6  - Shade of Aran (optional)
7  - Terestian Illhoof (optional)
8  - Netherspite (optional)
9  - Chess Event
10 - Prince Malchezzar
11 - Nightbane
*/

enum TimedEvents
{
    EVENT_CHESS_RESET = 1,
    EVENT_CHESS_WIN
};

const Position OptionalSpawn[] =
{
    { -10960.981445f, -1940.138428f, 46.178097f, 4.12f  }, // Hyakiss the Lurker
    { -10945.769531f, -2040.153320f, 49.474438f, 0.077f }, // Shadikith the Glider
    { -10899.903320f, -2085.573730f, 49.474449f, 1.38f  }  // Rokad the Ravager
};

ObjectData const creatureData[] =
{
    { NPC_ECHO_OF_MEDIVH,          DATA_ECHO_OF_MEDIVH },
    { 0,                           0                   }
};

DoorData const doorData[] =
{
    { GO_GAMESMANS_HALL_EXIT_DOOR,          DATA_CHESS,        DOOR_TYPE_ROOM },
    { 0,                                    0,                 DOOR_TYPE_ROOM }  // END
};

struct ObjectDistanceOrder
{
    const Unit* Source;

    ObjectDistanceOrder(const Unit* source) : Source(source) {}

    bool operator()(const WorldObject* left, const WorldObject* right) const
    {
        return Source->GetDistanceOrder(left, right);
    }
};

class instance_karazhan : public InstanceMapScript
{
public:
    instance_karazhan() : InstanceMapScript(KZScriptName, 532) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_karazhan_InstanceMapScript(map);
    }

    struct instance_karazhan_InstanceMapScript : public InstanceScript
    {
        instance_karazhan_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadDoorData(doorData);
            LoadObjectData(creatureData, nullptr);

            // 1 - OZ, 2 - HOOD, 3 - RAJ, this never gets altered.
            OperaEvent = urand(EVENT_OZ, EVENT_RAJ);
            TeamInInstance = map->GetTeamInInstance();
            OzDeathCount = 0;
            OptionalBossCount = 0;
            AllianceStalkerCount = 0;
            HordeStalkerCount = 0;
            ChessEvent = 0;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            switch (creature->GetEntry())
            {
            case NPC_KILREK:
                KilrekGUID = creature->GetGUID();
                break;
            case NPC_TERESTIAN_ILLHOOF:
                TerestianGUID = creature->GetGUID();
                break;
            case NPC_MOROES:
                MoroesGUID = creature->GetGUID();
                break;
            case NPC_NIGHTBANE:
                NightbaneGUID = creature->GetGUID();
                break;
            case NPC_ECHO_OF_MEDIVH:
                EchoGUID = creature->GetGUID();
                break;
            case NPC_CHESS_VICTORY_CONTROLLER:
                ChessVictoryControllerGUID = creature->GetGUID();
                break;
            case NPC_HUMAN_CHARGER:
            case NPC_HUMAN_CLERIC:
            case NPC_HUMAN_CONJURER:
            case NPC_HUMAN_FOOTMAN:
            case NPC_CONJURED_WATER_ELEMENTAL:
            case NPC_KING_LLANE:
                ChessPiecesAllianceGUIDs.push_back(creature->GetGUID());
                break;
            case NPC_ORC_GRUNT:
            case NPC_ORC_NECROLYTE:
            case NPC_ORC_WARLOCK:
            case NPC_ORC_WOLF:
            case NPC_SUMMONED_DAEMON:
            case NPC_WARCHIEF_BLACKHAND:
                ChessPiecesHordeGUIDs.push_back(creature->GetGUID());
                break;
            case NPC_INVISIBLE_STALKER:
                if (creature->GetPositionY() < -1870.0f)
                    ChessHordeStalkerGUIDs.push_back(creature->GetGUID());
                else
                    ChessAllianceStalkerGUIDs.push_back(creature->GetGUID());
                break;
            case NPC_CHESS_STATUS_BAR:
                if (creature->GetPositionY() < -1870.0f)
                    HordeStatusGUID = creature->GetGUID();
                else
                    AllianceStatusGUID = creature->GetGUID();
                break;
            default:
                break;
            }
        }

        void OnUnitDeath(Unit* unit) override
        {
            Creature* creature = unit->ToCreature();
            if (!creature)
                return;

            switch (creature->GetEntry())
            {
            case NPC_COLDMIST_WIDOW:
            case NPC_COLDMIST_STALKER:
            case NPC_SHADOWBAT:
            case NPC_VAMPIRIC_SHADOWBAT:
            case NPC_GREATER_SHADOWBAT:
            case NPC_PHASE_HOUND:
            case NPC_DREADBEAST:
            case NPC_SHADOWBEAST:
                if (GetBossState(DATA_OPTIONAL_BOSS) == TO_BE_DECIDED)
                {
                    ++OptionalBossCount;
                    if (OptionalBossCount == OPTIONAL_BOSS_REQUIRED_DEATH_COUNT)
                    {
                        switch (urand(NPC_HYAKISS_THE_LURKER, NPC_ROKAD_THE_RAVAGER))
                        {
                        case NPC_HYAKISS_THE_LURKER:
                            instance->SummonCreature(NPC_HYAKISS_THE_LURKER, OptionalSpawn[0]);
                            break;
                        case NPC_SHADIKITH_THE_GLIDER:
                            instance->SummonCreature(NPC_SHADIKITH_THE_GLIDER, OptionalSpawn[1]);
                            break;
                        case NPC_ROKAD_THE_RAVAGER:
                            instance->SummonCreature(NPC_ROKAD_THE_RAVAGER, OptionalSpawn[2]);
                            break;
                        }
                    }
                }
                break;
            case NPC_HYAKISS_THE_LURKER:
            case NPC_SHADIKITH_THE_GLIDER:
            case NPC_ROKAD_THE_RAVAGER:
                SetBossState(DATA_OPTIONAL_BOSS, DONE);
                break;
            default:
                break;
            }
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
            case DATA_OPERA_OZ_DEATHCOUNT:
                switch (data)
                {
                case SPECIAL:
                    ++OzDeathCount;
                    break;
                case IN_PROGRESS:
                    OzDeathCount = 0;
                    break;
                }
                break;
                // It's used for friendly game
            case DATA_CHESS:
                switch (data)
                {
                case DONE:
                    if (Creature* controller = GetCreature(DATA_CHESS_VICTORY_CONTROLLER))
                        controller->CastSpell(controller, SPELL_VICTORY_VISUAL, true);
                    EndChessGame();
                    Events.ScheduleEvent(EVENT_CHESS_WIN, 1s);
                    break;
                case SPECIAL:
                    PrepareChessEvent();
                    break;
                default:
                    break;
                }
                ChessEvent = data;
                break;
            default:
                break;
            }
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            switch (type)
            {
            case DATA_OPERA_PERFORMANCE:
                if (state == DONE)
                {
                    HandleGameObject(StageDoorLeftGUID, true);
                    HandleGameObject(StageDoorRightGUID, true);
                    if (GameObject* sideEntrance = instance->GetGameObject(SideEntranceDoor))
                        sideEntrance->RemoveFlag(GO_FLAG_LOCKED);
                    UpdateEncounterStateForKilledCreature(16812, nullptr);
                }
                break;
            case DATA_CHESS:
                switch (state)
                {
                case DONE:
                {
                    // Loot are not handled for friendly games
                    if (GetBossState(DATA_CHESS) != SPECIAL)
                        DoRespawnGameObject(DustCoveredChest, 1_days);
                    SetData(DATA_CHESS, state);
                }
                break;
                case FAIL:
                    EndChessGame();
                    break;
                case IN_PROGRESS:
                    PrepareChessEvent();
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }

            return true;
        }

        void SetGuidData(uint32 type, ObjectGuid data) override
        {
            switch (type)
            {
            case DATA_ECHO_OF_MEDIVH:
                EchoGUID = data;
                break;
            case DATA_CHESS_TARGET:
                ChessTargetSearcherGUID = data;
                break;
            case DATA_CHESS_VICTORY_CONTROLLER:
                ChessVictoryControllerGUID = data;
                break;
            case DATA_CHESS_MOVE_TO_SIDES:
                MoveChessPieceToSides(data);
                break;
            default:
                break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
            case GO_STAGE_CURTAIN:
                CurtainGUID = go->GetGUID();
                break;
            case GO_STAGE_DOOR_LEFT:
                StageDoorLeftGUID = go->GetGUID();
                if (GetBossState(DATA_OPERA_PERFORMANCE) == DONE)
                    go->SetGoState(GO_STATE_ACTIVE);
                break;
            case GO_STAGE_DOOR_RIGHT:
                StageDoorRightGUID = go->GetGUID();
                if (GetBossState(DATA_OPERA_PERFORMANCE) == DONE)
                    go->SetGoState(GO_STATE_ACTIVE);
                break;
            case GO_PRIVATE_LIBRARY_DOOR:
                LibraryDoor = go->GetGUID();
                break;
            case GO_MASSIVE_DOOR:
                MassiveDoor = go->GetGUID();
                break;
            case GO_GAMESMANS_HALL_DOOR:
                GamesmansDoor = go->GetGUID();
                break;
            case GO_GAMESMANS_HALL_EXIT_DOOR:
                AddDoor(go, true);
                GamesmansExitDoor = go->GetGUID();
                break;
            case GO_NETHERSPACE_DOOR:
                NetherspaceDoor = go->GetGUID();
                break;
            case GO_MASTERS_TERRACE_DOOR:
                MastersTerraceDoor[0] = go->GetGUID();
                break;
            case GO_MASTERS_TERRACE_DOOR2:
                MastersTerraceDoor[1] = go->GetGUID();
                break;
            case GO_SIDE_ENTRANCE_DOOR:
                SideEntranceDoor = go->GetGUID();
                if (GetBossState(DATA_OPERA_PERFORMANCE) == DONE)
                    go->SetFlag(GO_FLAG_LOCKED);
                else
                    go->RemoveFlag(GO_FLAG_LOCKED);
                break;
            case GO_DUST_COVERED_CHEST:
                DustCoveredChest = go->GetGUID();
                break;
            case GO_BLACKENED_URN:
                BlackenedUrnGUID = go->GetGUID();
                break;
            }

            switch (OperaEvent)
            {
                /// @todo Set Object visibilities for Opera based on performance
            case EVENT_OZ:
                break;
            case EVENT_HOOD:
                break;
            case EVENT_RAJ:
                break;
            }
        }

        void OnGameObjectRemove(GameObject* go) override
        {
            switch (go->GetEntry())
            {
            case GO_GAMESMANS_HALL_EXIT_DOOR:
                AddDoor(go, false);
                break;
            default:
                break;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
            case DATA_OPERA_PERFORMANCE:
                return OperaEvent;
            case DATA_OPERA_OZ_DEATHCOUNT:
                return OzDeathCount;
            case DATA_TEAM_IN_INSTANCE:
                return TeamInInstance;
            case DATA_CHESS:
                return ChessEvent;
            }
            return 0;
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
            case DATA_KILREK:
                return KilrekGUID;
            case DATA_TERESTIAN:
                return TerestianGUID;
            case DATA_MOROES:
                return MoroesGUID;
            case DATA_NIGHTBANE:
                return NightbaneGUID;
            case DATA_GO_STAGEDOORLEFT:
                return StageDoorLeftGUID;
            case DATA_GO_STAGEDOORRIGHT:
                return StageDoorRightGUID;
            case DATA_GO_CURTAINS:
                return CurtainGUID;
            case DATA_GO_LIBRARY_DOOR:
                return LibraryDoor;
            case DATA_GO_MASSIVE_DOOR:
                return MassiveDoor;
            case DATA_GO_SIDE_ENTRANCE_DOOR:
                return SideEntranceDoor;
            case DATA_GO_GAME_DOOR:
                return GamesmansDoor;
            case DATA_GO_GAME_EXIT_DOOR:
                return GamesmansExitDoor;
            case DATA_GO_NETHER_DOOR:
                return NetherspaceDoor;
            case DATA_MASTERS_TERRACE_DOOR_1:
                return MastersTerraceDoor[0];
            case DATA_MASTERS_TERRACE_DOOR_2:
                return MastersTerraceDoor[1];
            case DATA_IMAGE_OF_MEDIVH:
                return ImageGUID;
            case DATA_ECHO_OF_MEDIVH:
                return EchoGUID;
            case DATA_GO_BLACKENED_URN:
                return BlackenedUrnGUID;
            case DATA_CHESS_VICTORY_CONTROLLER:
                return ChessVictoryControllerGUID;
            case DATA_CHESS_MOVEMENT_SQUARE:
                return GetChessMovementSquare();
            }

            return ObjectGuid::Empty;
        }

        void Update(uint32 diff) override
        {
            Events.Update(diff);

            while (uint32 eventId = Events.ExecuteEvent())
            {
                switch (eventId)
                {
                    // Respawn all chess pieces and side stalkers on the original position
                case EVENT_CHESS_RESET:
                {
                    for (GuidList::const_iterator itr = ChessPiecesAllianceGUIDs.begin(); itr != ChessPiecesAllianceGUIDs.end(); ++itr)
                    {
                        if (Creature* temp = instance->GetCreature(*itr))
                        {
                            ChessPiecesAllianceGUIDs.erase(itr);
                            temp->Respawn(true);
                            temp->RemoveCorpse();
                        }
                    }
                    for (GuidList::const_iterator itr = ChessPiecesHordeGUIDs.begin(); itr != ChessPiecesHordeGUIDs.end(); ++itr)
                    {
                        if (Creature* temp = instance->GetCreature(*itr))
                        {
                            ChessPiecesHordeGUIDs.erase(itr);
                            temp->Respawn(true);
                            temp->RemoveCorpse();
                        }
                    }
                    for (GuidVector::const_iterator itr = ChessAllianceStalkerGUIDs.begin(); itr != ChessAllianceStalkerGUIDs.end(); ++itr)
                        if (Creature* temp = instance->GetCreature(*itr))
                            temp->RemoveAllAuras();
                    for (GuidVector::const_iterator itr = ChessHordeStalkerGUIDs.begin(); itr != ChessHordeStalkerGUIDs.end(); ++itr)
                        if (Creature* temp = instance->GetCreature(*itr))
                            temp->RemoveAllAuras();

                    if (GetBossState(DATA_CHESS) == FAIL)
                        SetBossState(DATA_CHESS, NOT_STARTED);

                    Events.CancelEvent(EVENT_CHESS_WIN);
                }
                break;
                case EVENT_CHESS_WIN:
                {
                    if (Creature* creature = instance->GetCreature(ChessVictoryControllerGUID))
                        creature->CastSpell(creature, 39334 + urand(0, 1));
                    Events.ScheduleEvent(EVENT_CHESS_WIN, 700ms);
                }
                break;
                }
            }
        }

        void MoveChessPieceToSides(ObjectGuid guid)
        {
            if (Creature* creature = instance->GetCreature(guid))
            {
                bool isGameEnd;

                // Check if the creature is a King
                if (creature->GetEntry() == NPC_KING_LLANE || creature->GetEntry() == NPC_WARCHIEF_BLACKHAND)
                    isGameEnd = true;
                else
                    isGameEnd = false;

                uint32 spellId = GetSpellIdAndPlaySound(creature);
                uint32 faction = creature->GetFaction();

                // Assign proper faction variables based on the creature's faction
                GuidVector stalkers = faction == FACTION_ID_CHESS_ALLIANCE ? ChessAllianceStalkerGUIDs : ChessHordeStalkerGUIDs;
                uint8& count = faction == FACTION_ID_CHESS_ALLIANCE ? AllianceStalkerCount : HordeStalkerCount;

                if (stalkers.size() <= count)
                    return;

                // Handle stalker transformation
                if (Creature* stalker = instance->GetCreature(stalkers[count]))
                {
                    stalker->CastSpell(stalker, spellId, true); 
                    ++count;
                }

                // Handle emote if the game has ended
                if (isGameEnd)
                {
                    // Inverse factions
                    stalkers.clear();
                    stalkers = faction == FACTION_ID_CHESS_ALLIANCE ? ChessHordeStalkerGUIDs : ChessAllianceStalkerGUIDs;
                    for (GuidVector::const_iterator itr = stalkers.begin(); itr != stalkers.end(); ++itr)
                        if (Creature* stalker = instance->GetCreature(*itr))
                            stalker->HandleEmoteCommand(EMOTE_ONESHOT_APPLAUD);
                }
            }
        }

        void PrepareChessEvent()
        {
            // Initialize chess pieces to start position
            auto PrepareChessPiece = [this](GuidList& pieces)
                {
                    for (GuidList::const_iterator itr = pieces.begin(); itr != pieces.end(); ++itr)
                    {
                        if (Creature* chessPiece = instance->GetCreature(*itr))
                        {
                            // Find closest white or black square
                            Creature* square = GetClosestCreatureWithEntry(chessPiece, NPC_SQUARE_WHITE, 0.0f);
                            if (!square)
                                square = GetClosestCreatureWithEntry(chessPiece, NPC_SQUARE_BLACK, 0.0f);
                            if (!square)
                                continue;

                            chessPiece->AI()->Reset();
                            chessPiece->AI()->DoCastSelf(SPELL_CHESS_AI_ATTACK_TIMER);
                            square->AI()->DoCastSelf(SPELL_DISABLE_SQUARE, true);
                            square->AI()->DoCastSelf(SPELL_IS_SQUARE_USED, true);
                        }
                    }
                };

            // Prepare both Alliance and Horde chess pieces
            PrepareChessPiece(ChessPiecesAllianceGUIDs);
            PrepareChessPiece(ChessPiecesHordeGUIDs);

            // Add silence debuff to all players in the instance
            Map::PlayerList const& players = instance->GetPlayers();
            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
            {
                if (Player* player = itr->GetSource())
                    player->CastSpell(player, SPELL_GAME_IN_SESSION, true);
            }

            AllianceStalkerCount = 0;
            HordeStalkerCount = 0;

            // Sort stalkers depending on side
            auto SortStalkers = [this](GuidVector& stalkers, ObjectGuid statusGuid)
                {
                    std::list<Creature*> sortedStalkers;
                    for (GuidVector::const_iterator itr = stalkers.begin(); itr != stalkers.end(); ++itr)
                        if (Creature* temp = instance->GetCreature(*itr))
                            sortedStalkers.push_back(temp);

                    if (sortedStalkers.empty())
                        return;

                    Creature* status = instance->GetCreature(statusGuid);
                    if (!status)
                        return;

                    sortedStalkers.sort(ObjectDistanceOrder(status));
                    stalkers.clear();
                    for (std::list<Creature*>::const_iterator itr = sortedStalkers.begin(); itr != sortedStalkers.end(); ++itr)
                        stalkers.push_back((*itr)->GetGUID());
                };

            // Sort both Horde and Alliance stalkers
            SortStalkers(ChessHordeStalkerGUIDs, HordeStatusGUID);
            SortStalkers(ChessAllianceStalkerGUIDs, AllianceStatusGUID);
        }

        void EndChessGame()
        {
            if (Creature* medivh = GetCreature(DATA_ECHO_OF_MEDIVH))
            {
                medivh->CastSpell(medivh, SPELL_GAME_OVER, true);
                //medivh->CastSpell(medivh, SPELL_CLEAR_BOARD, true);
            }

            // Remove silence debuff from all players in the instance
            Map::PlayerList const& players = instance->GetPlayers();
            for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                if (Player* player = itr->GetSource())
                    player->RemoveAurasDueToSpell(SPELL_GAME_IN_SESSION);
            Events.ScheduleEvent(EVENT_CHESS_RESET, 40s);
        }

        ObjectGuid GetChessMovementSquare() const
        {
            if (Creature* searcher = instance->GetCreature(ChessTargetSearcherGUID))
            {
                float radius = 8.0f;

                // Some pieces have special movement distance
                switch (searcher->GetEntry())
                {
                case NPC_ORC_WOLF:
                case NPC_HUMAN_CHARGER:
                    radius = 15.0f;
                    break;
                case NPC_HUMAN_CONJURER:
                case NPC_ORC_WARLOCK:
                    radius = 20.0f;
                    break;
                }

                // Increase radius if the piece has a special aura
                if (searcher->HasAura(SPELL_HAND_OF_MEDIVH))
                    radius += 5.0f;

                std::list<Creature*> squaresList;

                // Get all available squares within the radius
                GetCreatureListWithEntryInGrid(squaresList, searcher, NPC_SQUARE_BLACK, radius);
                GetCreatureListWithEntryInGrid(squaresList, searcher, NPC_SQUARE_WHITE, radius);
                squaresList.remove_if([](Creature* square) { return square->HasAura(SPELL_IS_SQUARE_USED) || !square->IsAlive(); });
                if (squaresList.empty())
                    return ObjectGuid::Empty;

                // Get the list of enemies
                std::list<Creature*> enemies;
                GuidList tempSet = searcher->GetFaction() == FACTION_ID_CHESS_ALLIANCE ? ChessPiecesHordeGUIDs : ChessPiecesAllianceGUIDs;

                for (GuidList::const_iterator itr = tempSet.begin(); itr != tempSet.end(); ++itr)
                {
                    if (Creature* enemy = instance->GetCreature(*itr))
                        enemies.push_back(enemy);
                }

                if (enemies.empty())
                    return ObjectGuid::Empty;

                // Sort the enemies by distance and the squares by distance to the closest enemy
                enemies.sort(ObjectDistanceOrder(searcher));
                squaresList.sort(ObjectDistanceOrder(enemies.front()));

                return squaresList.front()->GetGUID();
            }
            return ObjectGuid::Empty;
        }

        uint32 GetSpellIdAndPlaySound(Creature* creature)
        {
            uint32 spellId = 0;

            Creature* medivh = instance->GetCreature(EchoGUID);
            if (!medivh)
                return 0;

            bool isAlliance = TeamInInstance == ALLIANCE;
            auto PlaySoundAndSetSpellId = [&](uint32 soundId, uint32 spellIdValue)
                {
                    medivh->PlayDirectSound(soundId);
                    spellId = spellIdValue;
                };

            // Determine spell ID and play sound based on creature entry
            switch (creature->GetEntry())
            {
            case NPC_HUMAN_FOOTMAN:
                PlaySoundAndSetSpellId((isAlliance ? SOUND_ID_LOSE_PAWN_PLAYER_1 : SOUND_ID_LOSE_PAWN_MEDIVH_1) + urand(0, 2), SPELL_TRANSFORM_FOOTMAN);
                break;
            case NPC_HUMAN_CONJURER:
                PlaySoundAndSetSpellId(isAlliance ? SOUND_ID_LOSE_QUEEN_PLAYER : SOUND_ID_LOSE_QUEEN_MEDIVH, SPELL_TRANSFORM_CONJURER);
                break;
            case NPC_CONJURED_WATER_ELEMENTAL:
                PlaySoundAndSetSpellId(isAlliance ? SOUND_ID_LOSE_ROOK_PLAYER : SOUND_ID_LOSE_ROOK_MEDIVH, SPELL_TRANSFORM_WATER_ELEM);
                break;
            case NPC_HUMAN_CHARGER:
                PlaySoundAndSetSpellId(isAlliance ? SOUND_ID_LOSE_KNIGHT_PLAYER : SOUND_ID_LOSE_KNIGHT_MEDIVH, SPELL_TRANSFORM_CHARGER);
                break;
            case NPC_HUMAN_CLERIC:
                PlaySoundAndSetSpellId(isAlliance ? SOUND_ID_LOSE_BISHOP_PLAYER : SOUND_ID_LOSE_BISHOP_MEDIVH, SPELL_TRANSFORM_CLERIC);
                break;
            case NPC_KING_LLANE:
                PlaySoundAndSetSpellId(isAlliance ? SOUND_ID_WIN_MEDIVH : SOUND_ID_WIN_PLAYER, SPELL_TRANSFORM_KING_LLANE);
                break;
            case NPC_ORC_GRUNT:
                PlaySoundAndSetSpellId((isAlliance ? SOUND_ID_LOSE_PAWN_MEDIVH_1 : SOUND_ID_LOSE_PAWN_PLAYER_1) + urand(0, 2), SPELL_TRANSFORM_GRUNT);
                break;
            case NPC_ORC_WARLOCK:
                PlaySoundAndSetSpellId(isAlliance ? SOUND_ID_LOSE_QUEEN_MEDIVH : SOUND_ID_LOSE_QUEEN_PLAYER, SPELL_TRANSFORM_WARLOCK);
                break;
            case NPC_SUMMONED_DAEMON:
                PlaySoundAndSetSpellId(isAlliance ? SOUND_ID_LOSE_ROOK_MEDIVH : SOUND_ID_LOSE_ROOK_PLAYER, SPELL_TRANSFORM_DEAMON);
                break;
            case NPC_ORC_WOLF:
                PlaySoundAndSetSpellId(isAlliance ? SOUND_ID_LOSE_KNIGHT_MEDIVH : SOUND_ID_LOSE_KNIGHT_PLAYER, SPELL_TRANSFORM_WOLF);
                break;
            case NPC_ORC_NECROLYTE:
                PlaySoundAndSetSpellId(isAlliance ? SOUND_ID_LOSE_BISHOP_MEDIVH : SOUND_ID_LOSE_BISHOP_PLAYER, SPELL_TRANSFORM_NECROLYTE);
                break;
            case NPC_WARCHIEF_BLACKHAND:
                PlaySoundAndSetSpellId(isAlliance ? SOUND_ID_WIN_PLAYER : SOUND_ID_WIN_MEDIVH, SPELL_TRANSFORM_BLACKHAND);
                break;
            default:
                break;
            }
            return spellId;
        }

        GuidList const& GetChessPieces(uint32 faction) const
        {
            return faction == FACTION_ID_CHESS_ALLIANCE ? ChessPiecesAllianceGUIDs : ChessPiecesHordeGUIDs;
        }

    protected:
        EventMap Events;
        Team TeamInInstance;
        uint32 OperaEvent;
        uint32 OzDeathCount;
        uint32 OptionalBossCount;
        ObjectGuid CurtainGUID;
        ObjectGuid StageDoorLeftGUID;
        ObjectGuid StageDoorRightGUID;
        ObjectGuid KilrekGUID;
        ObjectGuid TerestianGUID;
        ObjectGuid MoroesGUID;
        ObjectGuid NightbaneGUID;
        ObjectGuid LibraryDoor;                 // Door at Shade of Aran
        ObjectGuid MassiveDoor;                 // Door at Netherspite
        ObjectGuid SideEntranceDoor;            // Side Entrance
        ObjectGuid GamesmansDoor;               // Door before Chess
        ObjectGuid GamesmansExitDoor;           // Door after Chess
        ObjectGuid NetherspaceDoor;             // Door at Malchezaar
        ObjectGuid MastersTerraceDoor[2];
        ObjectGuid ImageGUID;
        ObjectGuid DustCoveredChest;
        ObjectGuid BlackenedUrnGUID;

        //chess
        uint8 ChessEvent;
        uint8 AllianceStalkerCount;
        uint8 HordeStalkerCount;
        ObjectGuid EchoGUID;
        ObjectGuid ChessTargetSearcherGUID;
        ObjectGuid ChessVictoryControllerGUID;
        ObjectGuid HordeStatusGUID;
        ObjectGuid AllianceStatusGUID;
        ObjectGuid SoundTargetGUID;
        GuidList ChessPiecesAllianceGUIDs;
        GuidList ChessPiecesHordeGUIDs;
        GuidVector ChessAllianceStalkerGUIDs;
        GuidVector ChessHordeStalkerGUIDs;
    };
};

GuidList const* GetChessPieces(InstanceScript const* scr, uint32 faction)
{
    if (auto* script = dynamic_cast<instance_karazhan::instance_karazhan_InstanceMapScript const*>(scr))
        return &script->GetChessPieces(faction);
    return nullptr;
}

void AddSC_instance_karazhan()
{
    new instance_karazhan();
}

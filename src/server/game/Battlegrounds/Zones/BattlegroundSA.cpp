/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "Battleground.h"
#include "BattlegroundSA.h"
#include "Language.h"
#include "Player.h"
#include "GameObject.h"
#include "ObjectMgr.h"
#include "WorldPacket.h"


BattlegroundSA::BattlegroundSA()
{
    m_StartMessageIds[BG_STARTING_EVENT_FIRST]  = LANG_BG_SA_START_TWO_MINUTES;
    m_StartMessageIds[BG_STARTING_EVENT_SECOND] = LANG_BG_SA_START_ONE_MINUTE;
    m_StartMessageIds[BG_STARTING_EVENT_THIRD]  = LANG_BG_SA_START_HALF_MINUTE;
    m_StartMessageIds[BG_STARTING_EVENT_FOURTH] = LANG_BG_SA_HAS_BEGUN;
    m_BgObjects.resize(BG_SA_MAXOBJ);
    m_BgCreatures.resize(BG_SA_MAXNPC + BG_SA_MAX_GY);
    TimerEnabled = false;
    UpdateWaitTimer = 0;
    SignaledRoundTwo = false;
    SignaledRoundTwoHalfMin = false;
    InitSecondRound = false;
}

BattlegroundSA::~BattlegroundSA()
{
}

void BattlegroundSA::Reset()
{
    TotalTime = 0;
    attackers = ((urand(0,1)) ? TEAM_ALLIANCE : TEAM_HORDE);
    for (uint8 i = 0; i <= 5; i++)
        GateStatus[i] = BG_SA_GATE_OK;
    ShipsStarted = false;
    status = BG_SA_WARMUP;
}

bool BattlegroundSA::SetupBattleground()
{
    return ResetObjs();
}

bool BattlegroundSA::ResetObjs()
{
    uint32 atF = BG_SA_Factions[attackers];
    uint32 defF = BG_SA_Factions[attackers ? TEAM_ALLIANCE : TEAM_HORDE];


    for (uint8 i = 0; i <BG_SA_MAXOBJ; i++)
        DelObject(i);

    for (uint8 i = 0; i < BG_SA_MAXNPC; i++)
        DelCreature(i);

    for (uint8 i = BG_SA_MAXNPC; i < BG_SA_MAXNPC + BG_SA_MAX_GY; i++)
        DelCreature(i);

    for (uint8 i = 0; i < 6; i++)
        GateStatus[i] = BG_SA_GATE_OK;

    for (uint8 i = 0; i < BG_SA_CENTRAL_FLAG; i++)
    {
        if (!AddObject(i,BG_SA_ObjEntries[i],
            BG_SA_ObjSpawnlocs[i][0],BG_SA_ObjSpawnlocs[i][1],
            BG_SA_ObjSpawnlocs[i][2],BG_SA_ObjSpawnlocs[i][3],
            0,0,0,0,RESPAWN_ONE_DAY))
        return false;
    }

    //Cannons and demolishers - NPCs are spawned
    //By capturing GYs.
    for (uint8 i = 0; i < BG_SA_NPC_SPARKLIGHT; i++)
    {
        if (!AddCreature(BG_SA_NpcEntries[i], i, (attackers == TEAM_ALLIANCE ? TEAM_HORDE : TEAM_ALLIANCE),
              BG_SA_NpcSpawnlocs[i][0],BG_SA_NpcSpawnlocs[i][1],
              BG_SA_NpcSpawnlocs[i][2],BG_SA_NpcSpawnlocs[i][3],600))
        return false;
    }

    OverrideGunFaction();
    DemolisherStartState(true);

    for (uint8 i = 0; i <= BG_SA_TITAN_RELIC; i++)
    {
        SpawnBGObject(i, RESPAWN_IMMEDIATELY);
        GetBGObject(i)->SetUInt32Value(GAMEOBJECT_FACTION, defF);
    }

    GetBGObject(BG_SA_TITAN_RELIC)->SetUInt32Value(GAMEOBJECT_FACTION, atF);
    GetBGObject(BG_SA_TITAN_RELIC)->Refresh();

    for (uint8 i = 0; i <= 5; i++)
        GateStatus[i] = BG_SA_GATE_OK;

    // MAD props for Kiper for discovering those values - 4 hours of his work.
    GetBGObject(BG_SA_BOAT_ONE)->UpdateRotationFields(1.0f, 0.0002f);
    GetBGObject(BG_SA_BOAT_TWO)->UpdateRotationFields(1.0f, 0.00001f);
    SpawnBGObject(BG_SA_BOAT_ONE, RESPAWN_IMMEDIATELY);
    SpawnBGObject(BG_SA_BOAT_TWO, RESPAWN_IMMEDIATELY);

    TotalTime = 0;
    ShipsStarted = false;

    //Graveyards!
    for (uint8 i = 0;i < BG_SA_MAX_GY; i++)
    {
        WorldSafeLocsEntry const *sg = NULL;
        sg = sWorldSafeLocsStore.LookupEntry(BG_SA_GYEntries[i]);

        if (!sg)
        {
            sLog.outError("SOTA: Can't find GY entry %u",BG_SA_GYEntries[i]);
            return false;
        }

        if (i == BG_SA_BEACH_GY)
        {
            GraveyardStatus[i] = attackers;
            AddSpiritGuide(i + BG_SA_MAXNPC, sg->x, sg->y, sg->z, BG_SA_GYOrientation[i], ((attackers == TEAM_HORDE)? HORDE : ALLIANCE));
        }
        else
        {
            GraveyardStatus[i] = ((attackers == TEAM_HORDE)? TEAM_ALLIANCE : TEAM_HORDE);
            if (!AddSpiritGuide(i + BG_SA_MAXNPC, sg->x, sg->y, sg->z, BG_SA_GYOrientation[i], ((attackers == TEAM_HORDE)? ALLIANCE : HORDE)))
                sLog.outError("SOTA: couldn't spawn GY: %u",i);
        }
    }

    //GY capture points
    for (uint8 i = BG_SA_CENTRAL_FLAG; i < BG_SA_PORTAL_DEFFENDER_BLUE; i++)
    {
        AddObject(i, (BG_SA_ObjEntries[i] - (attackers == TEAM_ALLIANCE ? 1:0)),
            BG_SA_ObjSpawnlocs[i][0], BG_SA_ObjSpawnlocs[i][1],
            BG_SA_ObjSpawnlocs[i][2], BG_SA_ObjSpawnlocs[i][3],
            0,0,0,0,RESPAWN_ONE_DAY);
        GetBGObject(i)->SetUInt32Value(GAMEOBJECT_FACTION, atF);
    }

    for (uint8 i = BG_SA_PORTAL_DEFFENDER_BLUE; i < BG_SA_BOMB; i++)
    {
        AddObject(i, BG_SA_ObjEntries[i],
            BG_SA_ObjSpawnlocs[i][0], BG_SA_ObjSpawnlocs[i][1],
            BG_SA_ObjSpawnlocs[i][2], BG_SA_ObjSpawnlocs[i][3],
            0,0,0,0,RESPAWN_ONE_DAY);
        GetBGObject(i)->SetUInt32Value(GAMEOBJECT_FACTION, defF);
    }

    for (uint8 i = BG_SA_BOMB; i < BG_SA_MAXOBJ; i++)
    {
        AddObject(i, BG_SA_ObjEntries[BG_SA_BOMB],
            BG_SA_ObjSpawnlocs[i][0], BG_SA_ObjSpawnlocs[i][1],
            BG_SA_ObjSpawnlocs[i][2], BG_SA_ObjSpawnlocs[i][3],
            0,0,0,0,RESPAWN_ONE_DAY);
        GetBGObject(i)->SetUInt32Value(GAMEOBJECT_FACTION, atF);
    }

    //Player may enter BEFORE we set up bG - lets update his worldstates anyway...
    UpdateWorldState(BG_SA_RIGHT_GY_HORDE , GraveyardStatus[BG_SA_RIGHT_CAPTURABLE_GY] == TEAM_HORDE?1:0);
    UpdateWorldState(BG_SA_LEFT_GY_HORDE , GraveyardStatus[BG_SA_LEFT_CAPTURABLE_GY] == TEAM_HORDE?1:0);
    UpdateWorldState(BG_SA_CENTER_GY_HORDE , GraveyardStatus[BG_SA_CENTRAL_CAPTURABLE_GY] == TEAM_HORDE?1:0);

    UpdateWorldState(BG_SA_RIGHT_GY_ALLIANCE , GraveyardStatus[BG_SA_RIGHT_CAPTURABLE_GY] == TEAM_ALLIANCE?1:0);
    UpdateWorldState(BG_SA_LEFT_GY_ALLIANCE , GraveyardStatus[BG_SA_LEFT_CAPTURABLE_GY] == TEAM_ALLIANCE?1:0);
    UpdateWorldState(BG_SA_CENTER_GY_ALLIANCE , GraveyardStatus[BG_SA_CENTRAL_CAPTURABLE_GY] == TEAM_ALLIANCE?1:0);

    if (attackers == TEAM_ALLIANCE)
    {
        UpdateWorldState(BG_SA_ALLY_ATTACKS, 1);
        UpdateWorldState(BG_SA_HORDE_ATTACKS, 0);

        UpdateWorldState(BG_SA_RIGHT_ATT_TOKEN_ALL, 1);
        UpdateWorldState(BG_SA_LEFT_ATT_TOKEN_ALL, 1);
        UpdateWorldState(BG_SA_RIGHT_ATT_TOKEN_HRD, 0);
        UpdateWorldState(BG_SA_LEFT_ATT_TOKEN_HRD, 0);

        UpdateWorldState(BG_SA_HORDE_DEFENCE_TOKEN,1);
        UpdateWorldState(BG_SA_ALLIANCE_DEFENCE_TOKEN,0);
    }
    else
    {
        UpdateWorldState(BG_SA_HORDE_ATTACKS, 1);
        UpdateWorldState(BG_SA_ALLY_ATTACKS, 0);

        UpdateWorldState(BG_SA_RIGHT_ATT_TOKEN_ALL, 0);
        UpdateWorldState(BG_SA_LEFT_ATT_TOKEN_ALL, 0);
        UpdateWorldState(BG_SA_RIGHT_ATT_TOKEN_HRD, 1);
        UpdateWorldState(BG_SA_LEFT_ATT_TOKEN_HRD, 1);

        UpdateWorldState(BG_SA_HORDE_DEFENCE_TOKEN,0);
        UpdateWorldState(BG_SA_ALLIANCE_DEFENCE_TOKEN,1);
    }

    UpdateWorldState(BG_SA_PURPLE_GATEWS, 1);
    UpdateWorldState(BG_SA_RED_GATEWS, 1);
    UpdateWorldState(BG_SA_BLUE_GATEWS, 1);
    UpdateWorldState(BG_SA_GREEN_GATEWS, 1);
    UpdateWorldState(BG_SA_YELLOW_GATEWS, 1);
    UpdateWorldState(BG_SA_ANCIENT_GATEWS, 1);

    TeleportPlayers();
    return true;
}

void BattlegroundSA::StartShips()
{
    if (ShipsStarted)
        return;

    DoorOpen(BG_SA_BOAT_ONE);
    DoorOpen(BG_SA_BOAT_TWO);

    for (int i = BG_SA_BOAT_ONE; i <= BG_SA_BOAT_TWO; i++)
    {
        for (BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end();itr++)
        {
            if (Player* p = sObjectMgr.GetPlayer(itr->first))
            {
                if (p->GetTeamId() != attackers)
                    continue;

                UpdateData data;
                WorldPacket pkt;
                GetBGObject(i)->BuildValuesUpdateBlockForPlayer(&data, p);
                data.BuildPacket(&pkt);
                p->GetSession()->SendPacket(&pkt);
            }
        }
    }
    ShipsStarted = true;
}

void BattlegroundSA::Update(uint32 diff)
{
    if (InitSecondRound)
    {
        if (UpdateWaitTimer < diff)
        {
            if (!SignaledRoundTwo)
            {
                SignaledRoundTwo = true;
                InitSecondRound = false;
                SendMessageToAll(LANG_BG_SA_ROUND_TWO_ONE_MINUTE, CHAT_MSG_BG_SYSTEM_NEUTRAL);
            }
        }else
        {
            UpdateWaitTimer -= diff;
            return;
        }
    }
    Battleground::Update(diff);
    TotalTime += diff;

    if (status == BG_SA_WARMUP )
    {
        BG_SA_ENDROUNDTIME = BG_SA_ROUNDLENGTH;
        if (TotalTime >= BG_SA_WARMUPLENGTH)
        {
            TotalTime = 0;
            ToggleTimer();
            DemolisherStartState(false);
            status = BG_SA_ROUND_ONE;
        }
        if (TotalTime >= BG_SA_BOAT_START)
            StartShips();
        return;
    }
    else if (status == BG_SA_SECOND_WARMUP)
    {
        if (RoundScores[0].time<BG_SA_ROUNDLENGTH)
            BG_SA_ENDROUNDTIME = RoundScores[0].time;
        else
            BG_SA_ENDROUNDTIME = BG_SA_ROUNDLENGTH;

        if (TotalTime >= 60000)
        {
            SendWarningToAll(LANG_BG_SA_HAS_BEGUN);
            TotalTime = 0;
            ToggleTimer();
            DemolisherStartState(false);
            status = BG_SA_ROUND_TWO;
        }
        if (TotalTime >= 30000)
        {
            if (!SignaledRoundTwoHalfMin)
            {
                SignaledRoundTwoHalfMin = true;
                SendMessageToAll(LANG_BG_SA_ROUND_TWO_START_HALF_MINUTE, CHAT_MSG_BG_SYSTEM_NEUTRAL);
            }
        }
        StartShips();
        return;
    }
    else if (GetStatus() == STATUS_IN_PROGRESS)
    {
        if (status == BG_SA_ROUND_ONE)
        {
            if (TotalTime >= BG_SA_ROUNDLENGTH)
            {
                RoundScores[0].winner = attackers;
                RoundScores[0].time = BG_SA_ROUNDLENGTH;
                TotalTime = 0;
                status = BG_SA_SECOND_WARMUP;
                attackers = (attackers == TEAM_ALLIANCE) ? TEAM_HORDE : TEAM_ALLIANCE;
                UpdateWaitTimer = 5000;
                SignaledRoundTwo = false;
                SignaledRoundTwoHalfMin = false;
                InitSecondRound = true;
                ToggleTimer();
                ResetObjs();
                return;
            }
        }
        else if (status == BG_SA_ROUND_TWO)
        {
            if (TotalTime >= BG_SA_ENDROUNDTIME)
            {
                RoundScores[1].time = BG_SA_ROUNDLENGTH;
                RoundScores[1].winner = (attackers == TEAM_ALLIANCE) ? TEAM_HORDE : TEAM_ALLIANCE;

                if (RoundScores[0].time == RoundScores[1].time)
                    EndBattleground(NULL);
                else if (RoundScores[0].time < RoundScores[1].time)
                    EndBattleground(RoundScores[0].winner == TEAM_ALLIANCE ? ALLIANCE : HORDE);
                else
                    EndBattleground(RoundScores[1].winner == TEAM_ALLIANCE ? ALLIANCE : HORDE);
                return;
            }
        }
        if (status == BG_SA_ROUND_ONE || status == BG_SA_ROUND_TWO)
        {
            SendTime();
            UpdateDemolisherSpawns();
        }
    }
}

void BattlegroundSA::StartingEventCloseDoors()
{
}

void BattlegroundSA::StartingEventOpenDoors()
{
}

void BattlegroundSA::FillInitialWorldStates(WorldPacket& data)
{
  uint32 ally_attacks = uint32(attackers == TEAM_ALLIANCE ? 1 : 0);
  uint32 horde_attacks = uint32(attackers == TEAM_HORDE ? 1 : 0);

  data << uint32(BG_SA_ANCIENT_GATEWS) << uint32(GateStatus[BG_SA_ANCIENT_GATE]);
  data << uint32(BG_SA_YELLOW_GATEWS) << uint32(GateStatus[BG_SA_YELLOW_GATE]);
  data << uint32(BG_SA_GREEN_GATEWS) << uint32(GateStatus[BG_SA_GREEN_GATE]);
  data << uint32(BG_SA_BLUE_GATEWS) << uint32(GateStatus[BG_SA_BLUE_GATE]);
  data << uint32(BG_SA_RED_GATEWS) << uint32(GateStatus[BG_SA_RED_GATE]);
  data << uint32(BG_SA_PURPLE_GATEWS) << uint32(GateStatus[BG_SA_PURPLE_GATE]);

  data << uint32(BG_SA_BONUS_TIMER) << uint32(0);

  data << uint32(BG_SA_HORDE_ATTACKS)<< horde_attacks;
  data << uint32(BG_SA_ALLY_ATTACKS) << ally_attacks;

  //Time will be sent on first update...
  data << uint32(BG_SA_ENABLE_TIMER) << ((TimerEnabled) ? uint32(1) : uint32(0));
  data << uint32(BG_SA_TIMER_MINS) << uint32(0);
  data << uint32(BG_SA_TIMER_SEC_TENS) << uint32(0);
  data << uint32(BG_SA_TIMER_SEC_DECS) << uint32(0);

  data << uint32(BG_SA_RIGHT_GY_HORDE) << uint32(GraveyardStatus[BG_SA_RIGHT_CAPTURABLE_GY] == TEAM_HORDE?1:0);
  data << uint32(BG_SA_LEFT_GY_HORDE) << uint32(GraveyardStatus[BG_SA_LEFT_CAPTURABLE_GY] == TEAM_HORDE?1:0);
  data << uint32(BG_SA_CENTER_GY_HORDE) << uint32(GraveyardStatus[BG_SA_CENTRAL_CAPTURABLE_GY] == TEAM_HORDE?1:0);

  data << uint32(BG_SA_RIGHT_GY_ALLIANCE) << uint32(GraveyardStatus[BG_SA_RIGHT_CAPTURABLE_GY] == TEAM_ALLIANCE?1:0);
  data << uint32(BG_SA_LEFT_GY_ALLIANCE) << uint32(GraveyardStatus[BG_SA_LEFT_CAPTURABLE_GY] == TEAM_ALLIANCE?1:0);
  data << uint32(BG_SA_CENTER_GY_ALLIANCE) << uint32(GraveyardStatus[BG_SA_CENTRAL_CAPTURABLE_GY] == TEAM_ALLIANCE?1:0);

  data << uint32(BG_SA_HORDE_DEFENCE_TOKEN) << ally_attacks;
  data << uint32(BG_SA_ALLIANCE_DEFENCE_TOKEN) << horde_attacks;

  data << uint32(BG_SA_LEFT_ATT_TOKEN_HRD) << horde_attacks;
  data << uint32(BG_SA_RIGHT_ATT_TOKEN_HRD) << horde_attacks;
  data << uint32(BG_SA_RIGHT_ATT_TOKEN_ALL) <<  ally_attacks;
  data << uint32(BG_SA_LEFT_ATT_TOKEN_ALL) <<  ally_attacks;
}

void BattlegroundSA::AddPlayer(Player *plr)
{
    Battleground::AddPlayer(plr);
    //create score and add it to map, default values are set in constructor
    BattlegroundSAScore* sc = new BattlegroundSAScore;

    if (!ShipsStarted)
    {
        if (plr->GetTeamId() == attackers)
        {
            plr->CastSpell(plr,12438,true);//Without this player falls before boat loads...

            if (urand(0,1))
                plr->TeleportTo(607, 2682.936f, -830.368f, 50.0f, 2.895f, 0);
            else
                plr->TeleportTo(607, 2577.003f, 980.261f, 50.0f, 0.807f, 0);

        }
        else
            plr->TeleportTo(607, 1209.7f, -65.16f, 70.1f, 0.0f, 0);
    }
    else
    {
        if (plr->GetTeamId() == attackers)
            plr->TeleportTo(607, 1600.381f, -106.263f, 8.8745f, 3.78f, 0);
        else
            plr->TeleportTo(607, 1209.7f, -65.16f, 70.1f, 0.0f, 0);
    }

    m_PlayerScores[plr->GetGUID()] = sc;
}

void BattlegroundSA::RemovePlayer(Player* /*plr*/,uint64 /*guid*/)
{
}

void BattlegroundSA::HandleAreaTrigger(Player * /*Source*/, uint32 /*Trigger*/)
{
    // this is wrong way to implement these things. On official it done by gameobject spell cast.
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;
}

void BattlegroundSA::UpdatePlayerScore(Player* Source, uint32 type, uint32 value, bool doAddHonor)
{
    BattlegroundScoreMap::iterator itr = m_PlayerScores.find(Source->GetGUID());
    if (itr == m_PlayerScores.end())                         // player not found...
        return;

    if (type == SCORE_DESTROYED_DEMOLISHER)
        ((BattlegroundSAScore*)itr->second)->demolishers_destroyed += value;
    else if (type == SCORE_DESTROYED_WALL)
        ((BattlegroundSAScore*)itr->second)->gates_destroyed += value;
    else
        Battleground::UpdatePlayerScore(Source,type,value, doAddHonor);
}

void BattlegroundSA::TeleportPlayers()
{
    for (BattlegroundPlayerMap::const_iterator itr = GetPlayers().begin(); itr != GetPlayers().end(); ++itr)
    {
        if (Player *plr = sObjectMgr.GetPlayer(itr->first))
        {
            // should remove spirit of redemption
            if (plr->HasAuraType(SPELL_AURA_SPIRIT_OF_REDEMPTION))
                plr->RemoveAurasByType(SPELL_AURA_MOD_SHAPESHIFT);

            if (!plr->isAlive())
            {
                plr->ResurrectPlayer(1.0f);
                plr->SpawnCorpseBones();
            }

            plr->SetFullHealth();
            plr->SetPower(POWER_MANA, plr->GetMaxPower(POWER_MANA));
            plr->CombatStopWithPets(true);

            if (plr->GetTeamId() == attackers)
            {
                plr->CastSpell(plr,12438,true);     //Without this player falls before boat loads...

                if (urand(0,1))
                    plr->TeleportTo(607, 2682.936f, -830.368f, 50.0f, 2.895f, 0);
                else
                    plr->TeleportTo(607, 2577.003f, 980.261f, 50.0f, 0.807f, 0);
            }
            else
                plr->TeleportTo(607, 1209.7f, -65.16f, 70.1f, 0.0f, 0);
        }
    }
}

void BattlegroundSA::EventPlayerDamagedGO(Player* /*plr*/, GameObject* go, uint8 hitType, uint32 destroyedEvent)
{
    if (!go || !go->GetGOInfo())
        return;

    switch(hitType)
    {
        case BG_OBJECT_DMG_HIT_TYPE_JUST_DAMAGED://under attack
            SendWarningToAll(LANG_BG_SA_IS_UNDER_ATTACK, go->GetGOInfo()->name);
            break;
        case BG_OBJECT_DMG_HIT_TYPE_DAMAGED:
            break;
        case BG_OBJECT_DMG_HIT_TYPE_JUST_HIGH_DAMAGED:
            {
                uint32 i = GetGateIDFromDestroyEventID(destroyedEvent);
                GateStatus[i] = BG_SA_GATE_DAMAGED;
                uint32 uws = GetWorldStateFromGateID(i);
                if (uws)
                    UpdateWorldState(uws, GateStatus[i]);
                break;
            }
        case BG_OBJECT_DMG_HIT_TYPE_HIGH_DAMAGED:
            break;
        case BG_OBJECT_DMG_HIT_TYPE_JUST_DESTROYED://handled at DestroyGate()
            if (destroyedEvent == 19837)
                SendWarningToAll(LANG_BG_SA_CHAMBER_BREACHED);
            else
                SendWarningToAll(LANG_BG_SA_WAS_DESTROYED, go->GetGOInfo()->name);
            break;
    }
}

void BattlegroundSA::HandleKillUnit(Creature* unit, Player* killer)
{
    if (!unit)
        return;

    if (unit->GetEntry() == 28781)  //Demolisher
        UpdatePlayerScore(killer, SCORE_DESTROYED_DEMOLISHER, 1);
}

/*
  You may ask what the fuck does it do?
  Prevents owner overwriting guns faction with own.
 */
void BattlegroundSA::OverrideGunFaction()
{
    if (!m_BgCreatures[0])
        return;

    for (uint8 i = BG_SA_GUN_1; i <= BG_SA_GUN_10;i++)
    {
        if (Creature* gun = GetBGCreature(i))
            gun->setFaction(BG_SA_Factions[attackers? TEAM_ALLIANCE : TEAM_HORDE]);
    }

    for (uint8 i = BG_SA_DEMOLISHER_1; i <= BG_SA_DEMOLISHER_4;i++)
    {
        if (Creature* dem = GetBGCreature(i))
            dem->setFaction(BG_SA_Factions[attackers]);
    }
}

void BattlegroundSA::DemolisherStartState(bool start)
{
    if (!m_BgCreatures[0])
        return;

    for (uint8 i = BG_SA_DEMOLISHER_1; i <= BG_SA_DEMOLISHER_4; i++)
    {
        if (Creature* dem = GetBGCreature(i))
        {
            if (start)
                dem->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            else
                dem->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
        }
    }
}

void BattlegroundSA::DestroyGate(Player* pl, GameObject* /*go*/, uint32 destroyedEvent)
{
    uint32 i = GetGateIDFromDestroyEventID(destroyedEvent);
    if (!GateStatus[i])
        return;

    if (GameObject* g = GetBGObject(i))
    {
        if (g->GetGOValue()->building.health == 0)
        {
            GateStatus[i] = BG_SA_GATE_DESTROYED;
            uint32 uws = GetWorldStateFromGateID(i);
            if (uws)
                UpdateWorldState(uws, GateStatus[i]);
            bool rewardHonor = true;
            switch(i)
            {
                case BG_SA_GREEN_GATE:
                    if (GateStatus[BG_SA_BLUE_GATE] == BG_SA_GATE_DESTROYED)
                        rewardHonor = false;
                    break;
                case BG_SA_BLUE_GATE:
                    if (GateStatus[BG_SA_GREEN_GATE] == BG_SA_GATE_DESTROYED)
                        rewardHonor = false;
                    break;
                case BG_SA_RED_GATE:
                    if (GateStatus[BG_SA_PURPLE_GATE] == BG_SA_GATE_DESTROYED)
                        rewardHonor = false;
                    break;
                case BG_SA_PURPLE_GATE:
                    if (GateStatus[BG_SA_RED_GATE] == BG_SA_GATE_DESTROYED)
                        rewardHonor = false;
                    break;
            }

            if (i < 5)
                DelObject(i+9);
            UpdatePlayerScore(pl,SCORE_DESTROYED_WALL, 1);
            if (rewardHonor)
                UpdatePlayerScore(pl,SCORE_BONUS_HONOR,(GetBonusHonorFromKill(1)));
        }
    }
}

WorldSafeLocsEntry const* BattlegroundSA::GetClosestGraveYard(Player* player)
{
    uint32 safeloc = 0;
    WorldSafeLocsEntry const* ret;
    WorldSafeLocsEntry const* closest;
    float dist, nearest;
    float x,y,z;

    player->GetPosition(x,y,z);

    if (player->GetTeamId() == attackers)
        safeloc = BG_SA_GYEntries[BG_SA_BEACH_GY];
    else
        safeloc = BG_SA_GYEntries[BG_SA_DEFENDER_LAST_GY];

    closest = sWorldSafeLocsStore.LookupEntry(safeloc);
    nearest = sqrt((closest->x - x)*(closest->x - x) + (closest->y - y)*(closest->y - y)+(closest->z - z)*(closest->z - z));

    for (uint8 i = BG_SA_RIGHT_CAPTURABLE_GY; i < BG_SA_MAX_GY; i++)
    {
        if (GraveyardStatus[i] != player->GetTeamId())
            continue;

        ret = sWorldSafeLocsStore.LookupEntry(BG_SA_GYEntries[i]);
        dist = sqrt((ret->x - x)*(ret->x - x) + (ret->y - y)*(ret->y - y)+(ret->z - z)*(ret->z - z));
        if (dist < nearest)
        {
            closest = ret;
            nearest = dist;
        }
    }

    return closest;
}

void BattlegroundSA::SendTime()
{
    uint32 end_of_round = (BG_SA_ENDROUNDTIME - TotalTime);
    UpdateWorldState(BG_SA_TIMER_MINS, end_of_round/60000);
    UpdateWorldState(BG_SA_TIMER_SEC_TENS, (end_of_round%60000)/10000);
    UpdateWorldState(BG_SA_TIMER_SEC_DECS, ((end_of_round%60000)%10000)/1000);
}

void BattlegroundSA::EventPlayerClickedOnFlag(Player *Source, GameObject* target_obj)
{
    switch(target_obj->GetEntry())
    {
        case 191307:
        case 191308:
            if (GateStatus[BG_SA_GREEN_GATE] == BG_SA_GATE_DESTROYED || GateStatus[BG_SA_BLUE_GATE] == BG_SA_GATE_DESTROYED)
                CaptureGraveyard(BG_SA_LEFT_CAPTURABLE_GY, Source);
            break;
        case 191305:
        case 191306:
            if (GateStatus[BG_SA_GREEN_GATE] == BG_SA_GATE_DESTROYED || GateStatus[BG_SA_BLUE_GATE] == BG_SA_GATE_DESTROYED)
                CaptureGraveyard(BG_SA_RIGHT_CAPTURABLE_GY, Source);
            break;
        case 191310:
        case 191309:
            if ((GateStatus[BG_SA_GREEN_GATE] == BG_SA_GATE_DESTROYED || GateStatus[BG_SA_BLUE_GATE] == BG_SA_GATE_DESTROYED) && (GateStatus[BG_SA_RED_GATE] == BG_SA_GATE_DESTROYED || GateStatus[BG_SA_PURPLE_GATE] == BG_SA_GATE_DESTROYED))
                CaptureGraveyard(BG_SA_CENTRAL_CAPTURABLE_GY, Source);
            break;
        default:
            return;
    };
}

void BattlegroundSA::CaptureGraveyard(BG_SA_Graveyards i, Player *Source)
{
    if (GraveyardStatus[i] == attackers)
        return;

    DelCreature(BG_SA_MAXNPC + i);
    GraveyardStatus[i] = Source->GetTeamId();
    WorldSafeLocsEntry const *sg = NULL;
    sg = sWorldSafeLocsStore.LookupEntry(BG_SA_GYEntries[i]);
    AddSpiritGuide(i + BG_SA_MAXNPC, sg->x, sg->y, sg->z, BG_SA_GYOrientation[i], (GraveyardStatus[i] == TEAM_ALLIANCE?  ALLIANCE : HORDE));
    uint32 npc = 0;
    uint32 flag = 0;

    switch(i)
    {
        case BG_SA_LEFT_CAPTURABLE_GY:
            flag = BG_SA_LEFT_FLAG;
            DelObject(flag);
            AddObject(flag,(BG_SA_ObjEntries[flag] - (Source->GetTeamId() == TEAM_ALLIANCE ? 0:1)),
            BG_SA_ObjSpawnlocs[flag][0],BG_SA_ObjSpawnlocs[flag][1],
            BG_SA_ObjSpawnlocs[flag][2],BG_SA_ObjSpawnlocs[flag][3],0,0,0,0,RESPAWN_ONE_DAY);

            npc = BG_SA_NPC_RIGSPARK;
            AddCreature(BG_SA_NpcEntries[npc], npc, attackers,
              BG_SA_NpcSpawnlocs[npc][0], BG_SA_NpcSpawnlocs[npc][1],
              BG_SA_NpcSpawnlocs[npc][2], BG_SA_NpcSpawnlocs[npc][3]);

            UpdateWorldState(BG_SA_LEFT_GY_ALLIANCE, (GraveyardStatus[i] == TEAM_ALLIANCE? 1:0));
            UpdateWorldState(BG_SA_LEFT_GY_HORDE, (GraveyardStatus[i] == TEAM_ALLIANCE? 0:1));
            if (Source->GetTeamId() == TEAM_ALLIANCE)
                SendWarningToAll(LANG_BG_SA_A_GY_WEST);
            else
                SendWarningToAll(LANG_BG_SA_H_GY_WEST);
            break;
        case BG_SA_RIGHT_CAPTURABLE_GY:
            flag = BG_SA_RIGHT_FLAG;
            DelObject(flag);
            AddObject(flag, (BG_SA_ObjEntries[flag] - (Source->GetTeamId() == TEAM_ALLIANCE ? 0:1)),
              BG_SA_ObjSpawnlocs[flag][0],BG_SA_ObjSpawnlocs[flag][1],
              BG_SA_ObjSpawnlocs[flag][2],BG_SA_ObjSpawnlocs[flag][3],0,0,0,0,RESPAWN_ONE_DAY);

            npc = BG_SA_NPC_SPARKLIGHT;
            AddCreature(BG_SA_NpcEntries[npc], npc, attackers,
              BG_SA_NpcSpawnlocs[npc][0], BG_SA_NpcSpawnlocs[npc][1],
              BG_SA_NpcSpawnlocs[npc][2], BG_SA_NpcSpawnlocs[npc][3]);

            UpdateWorldState(BG_SA_RIGHT_GY_ALLIANCE, (GraveyardStatus[i] == TEAM_ALLIANCE? 1:0));
            UpdateWorldState(BG_SA_RIGHT_GY_HORDE, (GraveyardStatus[i] == TEAM_ALLIANCE? 0:1));
            if (Source->GetTeamId() == TEAM_ALLIANCE)
                SendWarningToAll(LANG_BG_SA_A_GY_EAST);
            else
                SendWarningToAll(LANG_BG_SA_H_GY_EAST);
            break;
        case BG_SA_CENTRAL_CAPTURABLE_GY:
            flag = BG_SA_CENTRAL_FLAG;
            DelObject(flag);
            AddObject(flag, (BG_SA_ObjEntries[flag] - (Source->GetTeamId() == TEAM_ALLIANCE ? 0:1)),
              BG_SA_ObjSpawnlocs[flag][0],BG_SA_ObjSpawnlocs[flag][1],
              BG_SA_ObjSpawnlocs[flag][2],BG_SA_ObjSpawnlocs[flag][3],0,0,0,0,RESPAWN_ONE_DAY);

            UpdateWorldState(BG_SA_CENTER_GY_ALLIANCE, (GraveyardStatus[i] == TEAM_ALLIANCE? 1:0));
            UpdateWorldState(BG_SA_CENTER_GY_HORDE, (GraveyardStatus[i] == TEAM_ALLIANCE? 0:1));
            if (Source->GetTeamId() == TEAM_ALLIANCE)
                SendWarningToAll(LANG_BG_SA_A_GY_SOUTH);
            else
                SendWarningToAll(LANG_BG_SA_H_GY_SOUTH);
            break;
        default:
            ASSERT(0);
            break;
    };
}

void BattlegroundSA::EventPlayerUsedGO(Player* Source, GameObject* object)
{
    if (object->GetEntry() == BG_SA_ObjEntries[BG_SA_TITAN_RELIC] && GateStatus[BG_SA_ANCIENT_GATE] == BG_SA_GATE_DESTROYED)
    {
        if (Source->GetTeamId() == attackers)
        {
            if (Source->GetTeamId() == TEAM_ALLIANCE)
                SendMessageToAll(LANG_BG_SA_ALLIANCE_CAPTURED_RELIC, CHAT_MSG_BG_SYSTEM_NEUTRAL);
            else SendMessageToAll(LANG_BG_SA_HORDE_CAPTURED_RELIC, CHAT_MSG_BG_SYSTEM_NEUTRAL);

            if (status == BG_SA_ROUND_ONE)
            {
                RoundScores[0].winner = attackers;
                RoundScores[0].time = TotalTime;
                attackers = (attackers == TEAM_ALLIANCE) ? TEAM_HORDE : TEAM_ALLIANCE;
                status = BG_SA_SECOND_WARMUP;
                TotalTime = 0;
                ToggleTimer();
                SendWarningToAll(LANG_BG_SA_ROUND_ONE_END);
                UpdateWaitTimer = 5000;
                SignaledRoundTwo = false;
                SignaledRoundTwoHalfMin = false;
                InitSecondRound = true;
                ResetObjs();
            }
            else if (status == BG_SA_ROUND_TWO)
            {
                RoundScores[1].winner = attackers;
                RoundScores[1].time = TotalTime;ToggleTimer();
                if (RoundScores[0].time == RoundScores[1].time)
                    EndBattleground(NULL);
                else if (RoundScores[0].time < RoundScores[1].time)
                    EndBattleground(RoundScores[0].winner == TEAM_ALLIANCE ? ALLIANCE : HORDE);
                else
                    EndBattleground(RoundScores[1].winner == TEAM_ALLIANCE ? ALLIANCE : HORDE);
            }
        }
    }
}

void BattlegroundSA::ToggleTimer()
{
    TimerEnabled = !TimerEnabled;
    UpdateWorldState(BG_SA_ENABLE_TIMER, (TimerEnabled) ? 1 : 0);
}

void BattlegroundSA::EndBattleground(uint32 winner)
{
    //honor reward for winning
    if (winner == ALLIANCE)
        RewardHonorToTeam(GetBonusHonorFromKill(1), ALLIANCE);
    else if (winner == HORDE)
        RewardHonorToTeam(GetBonusHonorFromKill(1), HORDE);

    //complete map_end rewards (even if no team wins)
    RewardHonorToTeam(GetBonusHonorFromKill(2), ALLIANCE);
    RewardHonorToTeam(GetBonusHonorFromKill(2), HORDE);

    Battleground::EndBattleground(winner);
}

void BattlegroundSA::UpdateDemolisherSpawns()
{
    for (uint8 i = BG_SA_DEMOLISHER_1; i <= BG_SA_DEMOLISHER_4; i++)
    {
        if (m_BgCreatures[i])
        {
            if (Creature *Demolisher = GetBGCreature(i))
            {
                if (Demolisher->isDead())
                {
                    uint8 gy = (i >= BG_SA_DEMOLISHER_3 ? 3 : 2);
                    if (GraveyardStatus[gy] == attackers)
                        Demolisher->Relocate(BG_SA_NpcSpawnlocs[i + 11][0], BG_SA_NpcSpawnlocs[i + 11][1],
                          BG_SA_NpcSpawnlocs[i + 11][2], BG_SA_NpcSpawnlocs[i + 11][3]);
                    else
                        Demolisher->Relocate(BG_SA_NpcSpawnlocs[i][0], BG_SA_NpcSpawnlocs[i][1],
                          BG_SA_NpcSpawnlocs[i][2], BG_SA_NpcSpawnlocs[i][3]);

                    Demolisher->Respawn();
                }
            }
        }
    }
}



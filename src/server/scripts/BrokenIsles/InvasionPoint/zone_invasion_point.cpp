/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "Player.h"
#include "SpellMgr.h"
#include "Conversation.h"
#include "Chat.h"
#include "Log.h"
#include "LFGMgr.h"
#include "ScenarioMgr.h"
#include "Scenario.h"
/*
* invasion_point
*/
enum
{
    MAP_INVASION_POINT      = 1779,
    MAP_AGS                 = 1669,
    AREA_BOZI               = 9025, 
    AREA_AURINOR            = 9100, 
    AREA_SANGUA             = 9128, 
    AREA_REKINDLING         = 9126, 
    AREA_CEN_GAR            = 9126,
    AREA_VAL                = 9127,
    AREA_BONICH             = 9180, 
    AREA_NAIGTAL            = 9102,

    AREA_MATRON_FOLNUNA      = 9295,
    AREA_SOTANATHOR          = 9299,
    AREA_OCCULARUS           = 9298,
    AREA_INQUISITOR_METO     = 9297,
    AREA_PIT_LORD_VILEMUS    = 9296,
    AREA_MISTRESS_ALLURADEL  = 9300,

    NPC_FELFRENZY_BERSERKER     = 125785,
    NPC_FELFLAME_INVADER        = 125755,
    NPC_SHADOWSWORN_BETRAYER    = 125758,
    NPC_BLADESWORN_DISCIPLE     = 125788,
    NPC_CONQUERING_RIFTSTALKER  = 125199,
    NPC_FELFLAME_SUBJUGATOR     = 125197,
    NPC_DREAD_KNIGHT_ZAKGAL     = 125252,

    NPC_TEMPORAL_ANOMALY    = 125856,
    NPC_DURAEL              = 125525,
    NPC_INVASION_POINT      = 124884,
    NPC_DEMON_HUNTER        = 127108,

    ENTRY_AURINOR           = 125849, 
    ENTRY_SANGUA            = 125863, 
    ENTRY_CEN_GAR           = 126120, 
    ENTRY_VAL               = 126499, 
    ENTRY_BONICH            = 126547, 
    ENTRY_NAIGTAL           = 126593, 

    ENTRY_MATRON_FOLNUNA         = 127528,
    ENTRY_SOTANATHOR             = 127532, 
    ENTRY_OCCULARUS              = 127533, 
    ENTRY_INQUISITOR_METO        = 127535, 
    ENTRY_PIT_LORD_VILEMUS       = 127531, 
    ENTRY_MISTRESS_ALLURADEL     = 127536,  

    LFG_DUNGEON_CEN_GAR  = 1617,
    LFG_DUNGEON_NAIGTAL = 1618,
    LFG_DUNGEON_SANGUA = 1619,
    LFG_DUNGEON_AURINOR = 1620,
    LFG_DUNGEON_VAL = 1621,
    LFG_DUNGEON_BONICH = 1622,
    LFG_DUNGEON_MATRON_FOLNUNA = 1628,
    LFG_DUNGEON_PIT_LORD_VILEMUS = 1629,
    LFG_DUNGEON_SOTANATHOR = 1630,
    LFG_DUNGEON_OCCULARUS = 1631,
    LFG_DUNGEON_INQUISITOR_METO = 1632,
    LFG_DUNGEON_MISTRESS_ALLURADEL = 1633,
};


enum
{
    DATA_AKC = 0,
    DATA_STAGE_1,
    DATA_STAGE_2,
    DATA_STAGE_3,
    DATA_STAGE_4,
    DATA_STAGE_5,
    DATA_STAGE_6,
    DATA_STAGE_7,

    DATA_MAX_ENCOUNTERS,
};

struct InvasionPointData
{
    uint32 areaid,conversationid,scenarioid, scenariostep;
};
InvasionPointData const invasionpointData[] =
{
    { AREA_BOZI,                   0, 1379, 3410 }, //???:????
    { AREA_AURINOR,             5440, 1391, 3443 }, //???:???
    { AREA_SANGUA,              5788, 1394, 3452 }, //???:???
    { AREA_CEN_GAR,             5788, 1404, 3471 }, //???:??
    { AREA_VAL,                 5788, 1406, 3477 }, //???:??
    { AREA_BONICH,              5786, 1409, 3487 }, //???:??? 976
    { AREA_NAIGTAL,             5923, 1411, 3492 }, //???:????
    { AREA_MATRON_FOLNUNA,      5231, 1412, 3502 }, //?????:?????
    { AREA_SOTANATHOR,          5486, 1418, 3509 }, //?????:?????
    { AREA_OCCULARUS,           5893, 1419, 3511 }, //?????:?????
    { AREA_INQUISITOR_METO,     5797, 1420, 3513 }, //?????:?????
    { AREA_PIT_LORD_VILEMUS,       0, 1421, 3515 }, //?????:????????
    { AREA_MISTRESS_ALLURADEL,     0, 1422, 3517 }, //?????:???????
};

enum CriteriaTrees
{
    CRITERIA_TREE_AURINOR_DISRUPT_THE_LEGION_S_FORCES       = 60429,
    CRITERIA_TREE_AURINOR_DESTROY_THE_TEMPORAL_ANOMALIES    = 60431,
    CRITERIA_TREE_AURINOR_KILL_THE_LEGION_S_COMMANDER       = 60433,
};

enum ScenarioEvents
{
    SCENARIO_EVENT_AURINOR_DISRUPT_THE_LEGION_S_FORCES      = 59201,
    SCENARIO_EVENT_AURINOR_DESTROY_THE_TEMPORAL_ANOMALIES   = 59346,
    SCENARIO_EVENT_AURINOR_KILL_THE_LEGION_S_COMMANDER      = 59372,
};

struct instance_invasion_point : public InstanceScript
{
    instance_invasion_point(InstanceMap* map) : InstanceScript(map)
    {
        isLoaded = false;
        lastScenarioId = 0;
    }

    void LoadInvasionPointData(const InvasionPointData* data, uint32 p_area)
    {
        conversationEntry = 0;
        _ScenarioID = 0;
        _ScenarioStep = 0;

        while (data->areaid)
        {
            if (data->areaid == p_area)
            {
                conversationEntry = data->conversationid;
                _ScenarioID = data->scenarioid;
                _ScenarioStep = data->scenariostep;
                printf("LoadInvasionPointData Area = %u ,ScenarioID = %u, ScenarioStep = %u \n", p_area, _ScenarioID, _ScenarioStep);
            }
            ++data;
        }
    }

    void OnPlayerEnter(Player* player)
    {
        SetCheckPointPos(player->GetPosition());
        if (!isLoaded)
        {
            isLoaded = true;
            AddTimedDelayedOperation(2500, [this, player]() -> void
            {
                LoadInvasionPointData(invasionpointData, player->GetAreaId());

                if (conversationEntry > 0)
                    Conversation::CreateConversation(conversationEntry, player, *player, { player->GetGUID() });

                GetScenarioByID(player, _ScenarioID);
                lastScenarioId = _ScenarioID;
            });
        }
    }

    void OnCompletedCriteriaTree(CriteriaTree const* tree) override
    {
        switch (tree->ID)
        {
            //AURINOR
        case CRITERIA_TREE_AURINOR_DISRUPT_THE_LEGION_S_FORCES:
            SetData(DATA_STAGE_1, DONE);
            break;
        case CRITERIA_TREE_AURINOR_DESTROY_THE_TEMPORAL_ANOMALIES:
            SetData(DATA_STAGE_2, DONE);
            instance->SummonCreature(NPC_DURAEL, Position(-4066.815f, -4657.99f, 80.46f, 4.81f));
            break;
        case CRITERIA_TREE_AURINOR_KILL_THE_LEGION_S_COMMANDER:
            SetData(DATA_STAGE_3, DONE);
            instance->SummonCreature(NPC_INVASION_POINT, Position(-4066.815f, -4657.99f, 80.46f, 4.81f));
            instance->SummonCreature(NPC_DEMON_HUNTER, Position(-4073.0f, -4663.92f, 80.5863f, 3.76997f));
            instance->SummonCreature(NPC_DEMON_HUNTER, Position(-4064.05f, -4666.83f, 80.5863f, 5.02667f));
            instance->SummonCreature(NPC_DEMON_HUNTER, Position(-4058.52f, -4659.22f, 80.5863f));
            instance->SummonCreature(NPC_DEMON_HUNTER, Position(-4064.05f, -4651.61f, 80.5863f, 1.25652f));
            instance->SummonCreature(NPC_DEMON_HUNTER, Position(-4073.0f, -4654.52f, 80.5863f, 2.51322f)); 
            isLoaded = false;
            break;
        default:
            break;
        }
    }

    void OnUnitDeath(Unit* l_unit)
    {
        switch (l_unit->GetEntry())
        {
        case NPC_FELFRENZY_BERSERKER:
        case NPC_FELFLAME_INVADER:
        case NPC_SHADOWSWORN_BETRAYER:
        case NPC_BLADESWORN_DISCIPLE:
        case NPC_CONQUERING_RIFTSTALKER:
        case NPC_FELFLAME_SUBJUGATOR:
        case NPC_DREAD_KNIGHT_ZAKGAL:
            for (uint8 i = 0; i < 11; ++i)
            DoSendScenarioEvent(SCENARIO_EVENT_AURINOR_DISRUPT_THE_LEGION_S_FORCES);
            break;
        case NPC_DURAEL:
            DoSendScenarioEvent(SCENARIO_EVENT_AURINOR_KILL_THE_LEGION_S_COMMANDER);
            break;
        }
    }

    uint32 conversationEntry;
    uint32 _areaId;
    uint32 _ScenarioID;
    uint32 _ScenarioStep;
    bool isLoaded;
    uint32 lastScenarioId;
};

enum TSSpells
{
    SPELL_CAMERA_SHAKE  = 247165,
    SPELL_ENTER_RIFT    = 247069
};
class npc_invasion_point_transport : public CreatureScript
{
public:
    npc_invasion_point_transport() : CreatureScript("npc_invasion_point_transport") { }

    struct npc_invasion_point_transportAI : public ScriptedAI
    {
        npc_invasion_point_transportAI(Creature* creature) : ScriptedAI(creature)  {  }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!who || !who->IsInWorld())
                return;
            if (!who->ToPlayer() || who->ToPlayer()->IsBeingTeleported())
                return;
            
            if (me->IsWithinDistInMap(who, 5.0f))   // near me
            {
                me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                if (!who->HasAura(SPELL_CAMERA_SHAKE))
                    who->CastSpell(who, SPELL_CAMERA_SHAKE, true);
            }
            else if (me->GetDistance(who->GetPosition()) > 20.0f)
            {
                if (who->HasAura(SPELL_CAMERA_SHAKE))
                    who->CastSpell(who, SPELL_ENTER_RIFT, true);
            }
                               
        }

        void OnSpellClick(Unit* who, bool& /*result*/)
        {
            if (!who || !who->IsInWorld())
                return;
            if (!who->ToPlayer() || who->ToPlayer()->IsBeingTeleported())
                return;

            TeleTo(who);
        }

        void TeleTo(Unit* caster) 
        {
            if (!caster->ToPlayer())
                return;
            Player* player = caster->GetCharmerOrOwnerPlayerOrPlayerItself();

            if (!player ||  player->IsBeingTeleported()||player->IsInCombat()) //player->IsGameMaster() ||
                return;
            if (player->GetMapId() == MAP_INVASION_POINT)
            {
                switch (uint32 zoneID = player->GetZoneId())
                {
                    
                    case   AREA_AURINOR: //???:??? 
                        Teleport(player, MAP_AGS, -3360.526855f, 9072.964844f, -169.297348f, 4.630715f);
                        break;
                    case   AREA_SANGUA : //???:???
                        Teleport(player, MAP_AGS, 1821.763306f, 1054.987793f, 500.846313f, 1.178095f);
                        break;
                    case   AREA_CEN_GAR: //???:??
                        Teleport(player, MAP_AGS, -2763.675049f, 9221.212891f, -169.888443f, 4.802709f);
                        break;
                    case   AREA_VAL: //???:??
                        Teleport(player, MAP_AGS, 746.55481f, 2030.94812f, 389.840881f, 0.808971f);
                        break;
                    case   AREA_BONICH : //???:???
                        Teleport(player, MAP_AGS, -2229.262207f, 9372.748047f, -61.536499f, 4.432786f);
                        break;
                    case   AREA_NAIGTAL: //???:????
                        Teleport(player, MAP_AGS, 5778.810059f, 9256.361328f, -29.84708f, 2.364054f);
                        break;

                    case   AREA_MATRON_FOLNUNA: //?????:?????
                        Teleport(player, MAP_AGS, 2023.66272f, 1511.363403f, 408.588531f, 5.249556f);
                        break;
                    case   AREA_SOTANATHOR: //?????:?????
                        Teleport(player, MAP_AGS, 5525.2207f, 10081.260742f, -87.965446f, 0.938551f);
                        break;
                    case   AREA_OCCULARUS: //?????:?????
                        Teleport(player, MAP_AGS, -2922.463135f, 9385.199219f, -161.835892f, 2.387616f);
                        break;
                    case   AREA_INQUISITOR_METO: //?????:?????
                        Teleport(player, MAP_AGS, -3227.92749f, 9117.825195f, -164.370453f, 1.925f);
                        break;
                    case   AREA_PIT_LORD_VILEMUS : //?????:????????
                        Teleport(player, MAP_AGS, -2467.131104f, 9158.651367f, -158.561127f, 5.173422f);
                        break;
                    case   AREA_MISTRESS_ALLURADEL:  //?????:???????
                        Teleport(player, MAP_AGS, -2684.626465f, 8992.457031f, -137.700745f, 0.814413f);
                        break;
                }
            }
            else if(player->GetMapId() == MAP_AGS)
            {
                sLFGMgr->Clean();
                switch (uint32 entryID = me->GetEntry())
                {
                case   ENTRY_AURINOR:
                    sLFGMgr->JoinPersonalLfg(player, LFG_DUNGEON_AURINOR);
                    Teleport(player, MAP_INVASION_POINT, -4021.612305f, -4988.64502f, 128.886917f, 0.749271f);
                    break;
                case   ENTRY_SANGUA:
                    sLFGMgr->JoinPersonalLfg(player, LFG_DUNGEON_SANGUA);
                    Teleport(player, MAP_INVASION_POINT, -1399.284668f, 898.30896f, 90.495483f, 2.988442f);
                    break;
                case   ENTRY_CEN_GAR:
                    sLFGMgr->JoinPersonalLfg(player, LFG_DUNGEON_CEN_GAR);
                    Teleport(player, MAP_INVASION_POINT, 755.068237f, 721.636108f, 42.011993f, 3.318307f);
                    break;
                case   ENTRY_VAL:
                    sLFGMgr->JoinPersonalLfg(player, LFG_DUNGEON_VAL);
                    Teleport(player, MAP_INVASION_POINT, -4162.79834f, 653.500305f, 18.220989f, 5.713767f);
                    break;
                case   ENTRY_BONICH:
                    sLFGMgr->JoinPersonalLfg(player, LFG_DUNGEON_BONICH);
                    Teleport(player, MAP_INVASION_POINT, -3794.919434f, -8168.500977f, 9.968992f, 1.346958f);
                    break;
                case   ENTRY_NAIGTAL:
                    sLFGMgr->JoinPersonalLfg(player, LFG_DUNGEON_NAIGTAL);
                    Teleport(player, MAP_INVASION_POINT, -1759.375854f, -1418.573608f, 28.905785f, 4.119423f);
                    break;
                case   ENTRY_MATRON_FOLNUNA:
                    sLFGMgr->JoinPersonalLfg(player, LFG_DUNGEON_MATRON_FOLNUNA);
                    Teleport(player, MAP_INVASION_POINT, 4488.693359f, 6589.942871f, 42.011726f, 3.347366f);
                    break;
                case   ENTRY_SOTANATHOR:
                    sLFGMgr->JoinPersonalLfg(player, LFG_DUNGEON_SOTANATHOR);
                    Teleport(player, MAP_INVASION_POINT, -1394.851685f, 8359.411133f, 92.464943f, 2.615384f);
                    break;
                case   ENTRY_OCCULARUS:
                    sLFGMgr->JoinPersonalLfg(player, LFG_DUNGEON_OCCULARUS);
                    Teleport(player, MAP_INVASION_POINT, -10030.005859f, 2789.192383f, 18.917389f, 5.776608f);
                    break;
                case   ENTRY_INQUISITOR_METO:
                    sLFGMgr->JoinPersonalLfg(player, LFG_DUNGEON_INQUISITOR_METO);
                    Teleport(player, MAP_INVASION_POINT, 5705.858398f, -1421.4198f, 28.22085f, 4.186173f);
                    break;
                case   ENTRY_PIT_LORD_VILEMUS:
                    sLFGMgr->JoinPersonalLfg(player, LFG_DUNGEON_PIT_LORD_VILEMUS);
                    Teleport(player, MAP_INVASION_POINT, -1447.170044f, 8329.870117f, 83.507f, 2.58556f);
                    break;
                case   ENTRY_MISTRESS_ALLURADEL:
                    sLFGMgr->JoinPersonalLfg(player, LFG_DUNGEON_MISTRESS_ALLURADEL);
                    Teleport(player, MAP_INVASION_POINT, 5266.467285f, -9763.751953f, 9.773649f, 0.997414f);
                    break;
                
                }
            }

        }

        // Teleport Player
        void Teleport(Player * const player, const uint16 &map,
            const float &X, const float &Y, const float &Z, const float &orient)
        {
            
            player->GetScheduler().Schedule(Seconds(1), [player, map, X, Y, Z, orient](TaskContext /*context*/)
            {
                player->TeleportTo(map, X, Y, Z, orient);
            });
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_invasion_point_transportAI(creature);
    }

};


struct npc_temporal_anomaly_125856 : public ScriptedAI
{
    npc_temporal_anomaly_125856(Creature* creature) : ScriptedAI(creature) { instance = creature->GetInstanceScript(); }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (instance->GetData(DATA_STAGE_1) == DONE)
            {
                instance->DoSendScenarioEvent(SCENARIO_EVENT_AURINOR_DESTROY_THE_TEMPORAL_ANOMALIES);
                me->DespawnOrUnsummon();
            }
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Player* player = who->ToPlayer())
        {
            if (me->IsWithinDist(player, 15.0f, false))
            {
                if (!IsLock)
                {
                    IsLock = true;
                    me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                }
            }
        }
    }

    InstanceScript* instance;
};



void AddSC_instance_invasion_point()
{
    RegisterInstanceScript(instance_invasion_point, 1779);
    new npc_invasion_point_transport();

    RegisterCreatureAI(npc_temporal_anomaly_125856);
}

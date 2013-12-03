#include "ScriptMgr.h"
#include "GameObjectAI.h"
#include "GameObject.h"
#include "Player.h"
#include "Transport.h"
#include "TransportMgr.h"
#include "Common.h"
#include "ScriptedGossip.h"
#include "ScriptedCreature.h"
#include "../Northrend/IcecrownCitadel/icecrown_citadel.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "Path.h"
#include "Map.h"
#include "ScriptMgr.h"
#include "WorldPacket.h"

#ifdef __APPLE__
#include "UpdateData.h"
#include "WorldPacket.h"
#include "ObjectMgr.h"

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

#include "MapManager.h"
#include "Vehicle.h"
#include "Group.h"
#include "Object.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "ScriptedEscortAI.h"
#include "CreatureTextMgr.h"
#endif

//TO DO: ^ Remove unnecessary headers

const std::string MURADIN_BUTTON_TEXT = "My companinos are all accounted for, Muradin. Let's go!";

enum TextIds
{
	TEXT_MURADIN_MENU_TEXT = 15101
};

enum Spells
{
    SPELL_BURNING_PITCH_A = 71335,
    SPELL_BURNING_PITCH_H = 71339,
    SPELL_BURNING_PITCH_SIEGE_DMG_A = 70383,
    SPELL_BURNING_PITCH_SIEGE_DMG_H = 70374,
    SPELL_BURNING_PITCH_AOE_DAMAGE = 69660,
    
    SPELL_WOUNDING_STRIKE_10_NM = 69651,
    SPELL_WOUNDING_STRIKE_10_HM = 72570,
    SPELL_WOUNDING_STRIKE_25_NM = 72569,
    SPELL_WOUNDING_STRIKE_25_HM = 72571,
    
    SPELL_TELEPORT_VISUAL = 64446,
    SPELL_BLADESTORM = 69652,
    SPELL_BLADESTORM_TRIGGER = 69653,
    
    // Cannon
    SPELL_HEAT_DRAIN = 69470,
    SPELL_OVERHEAT = 69487, // Triggers spell #69488 every 0.25s. It should consume 10 Energy but does not.
    SPELL_CANNON_BLAST = 69399,
    SPELL_INCINERATING_BLAST = 69401,
    
    // Auras
    SPELL_HORDE = 70121,
    SPELL_ALLIANCE = 70120,
    
    // Achievement spell required target
    SPELL_ACHIEVEMENT = 72959,
    
    // Rampart of Skulls NPCs Spells
    // Kor'kron Primalist
    SPELL_WRATH = 69968,
    SPELL_HEALING_TOUCH = 69899,
    SPELL_REGROWTH = 69882,
    SPELL_REJUVENATION = 69898,
    
    SPELL_SUMMON_BATTLE_STANDART_A = 69810,
    SPELL_SUMMON_BATTLE_STANDART_H = 69811,
    
    // Kor'kron Defender
    SPELL_DEVASTATE = 69902,
    SPELL_THUNDERCLAP = 69965,
    SPELL_SUNDER_ARMOR = 57807,
    SPELL_SPELL_REFLECT = 69901,
    
    // Skybreaker Vindicator
    SPELL_AVENGERS_SHIELD = 69927,
    SPELL_CONCENTRATION = 69930,
    SPELL_HOLY_WRATH = 69934,
    
    // Frostwyrm
    SPELL_FROST_BREATH = 70116,
    SPELL_BLIZZARD = 70362,
    SPELL_FROST_CLEAVE = 70361,
    
    // Muradin Bronzebeard / High Overlord Saurfang
    SPELL_CLEAVE = 15284,
    SPELL_RENDING_THROW = 70309,
    SPELL_TASTE_OF_BLOOD = 69634,
    
    // Kor'kron Battle-mage & Skybreaker Sorcerer
    SPELL_BELOW_ZERO = 69705,
    SPELL_SHADOW_CHANNELING = 45104,
    
    // Experience spells
    SPELL_EXPERIENCED = 71188,
    SPELL_VETERAN = 71193,
    SPELL_ELITE = 71195,
    SPELL_DESPERATE_RESOLVE_10_NM = 69647,
    SPELL_DESPERATE_RESOLVE_10_HM = 72537,
    SPELL_DESPERATE_RESOLVE_25_NM = 72536,
    SPELL_DESPERATE_RESOLVE_25_HM = 72538,
    
    // Kor'kron Axethrower & Skybreaker Rifleman
    SPELL_HURL_AXE = 70161,
    SPELL_SHOOT = 70162,
    
    // Kor'kron Rocketeer & Skybreaker Mortar Soldier
    SPELL_ROCKET_ARTILLERY_MARKER = 71371,
    SPELL_ROCKET_ARTILLERY_TRIGGERED = 69679,
    SPELL_ROCKET_ARTILLERY_HORDE = 69678,
    SPELL_ROCKET_ARTILLERY_ALLIANCE = 70609,
    SPELL_EXPLOSION = 69680,
    
    // Ship Explsion
    SPELL_SHIP_EXPLOSION = 72137,
    
    // Remove Rocket Packs
    SPELL_REMOVE_ROCKET_PACK = 70713,
    
    // Achievements
    SPELL_ACHIEVEMENT_CHECK = 72959,
};

enum Transports
{
	TRANSPORT_SKYBREAKER = 21,
	TRANSPORT_ORGRIM = 22
};

enum Events
{
    EVENT_NULL,
    EVENT_INTRO_ALLIANCE_1, // Muradin Bronzebeard yells: Fire up the engines! We got a meetin' with destiny, lads!
    EVENT_INTRO_ALLIANCE_2, // Muradin Bronzebeard yells: Hold on to yer hats!
    EVENT_INTRO_ALLIANCE_3, // Muradin Bronzebeard yells: What in the world is that? Grab me spyglass, crewman!
    EVENT_INTRO_ALLIANCE_4, // Muradin Bronzebeard yells: By me own beard! HORDE SAILIN' IN FAST 'N HOT!
    EVENT_INTRO_ALLIANCE_5, // Muradin Bronzebeard yells: EVASIVE ACTION! MAN THE GUNS!
    EVENT_INTRO_ALLIANCE_6, // Muradin Bronzebeard yells: Cowardly dogs! Ye blindsided us!
    EVENT_INTRO_ALLIANCE_7, // High Overlord Saurfang yells: This is not your battle, dwarf. Back down or we will be forced to destroy your ship.
    EVENT_INTRO_ALLIANCE_8, // Muradin Bronzebeard yells: Not me battle? I dunnae who ye think ye are, mister, but I got a score to settle with Arthas and yer not gettin' in me way! FIRE ALL GUNS! FIRE! FIRE!
    
    EVENT_INTRO_HORDE_1, // High Overlord Saurfang yells: Rise up, sons and daughters of the Horde! Today we battle a hated enemy of the Horde! LOK'TAR OGAR! Kor'kron, take us out!
    EVENT_INTRO_HORDE_1_1, // Kor'kron, take us out!
    EVENT_INTRO_HORDE_2, // High Overlord Saurfang yells: What is that?! Something approaching in the distance!
    EVENT_INTRO_HORDE_3, // High Overlord Saurfang yells: ALLIANCE GUNSHIP! ALL HANDS ON DECK!
    EVENT_INTRO_HORDE_4, // Muradin Bronzebeard yells: Move yer jalopy or we'll blow it out of the sky, orc! The Horde's got no business here!
    EVENT_INTRO_HORDE_5, // High Overlord Saurfang yells: You will know our business soon! KOR'KRON, ANNIHILATE THEM!
    
    EVENT_OUTRO_ALLIANCE_1,
    EVENT_OUTRO_ALLIANCE_2,
    EVENT_OUTRO_ALLIANCE_3,
    
    EVENT_OUTRO_HORDE_1,
    EVENT_OUTRO_HORDE_2,
    EVENT_OUTRO_HORDE_3,
    
    //Fly
    EVENT_START_FLY,
    
    //Misc battle
    EVENT_WALK_MOBS,
    EVENT_SUMMON_PORTAL,
    EVENT_FREEZE_CANNON,
    EVENT_SHADOW_CHANNELING,
    EVENT_UNSUMMON_PORTAL,
    EVENT_BOARDING_GUNSHIP,
    EVENT_BOARDING_TALK,
    EVENT_BURNING_PITCH,
    EVENT_WOUNDING_STRIKE,
    EVENT_BLADE_STORM,
    EVENT_DONE,
    EVENT_FAIL,
    EVENT_RESTART_EVENT,
    EVENT_BOARDING_REAVERS_MARINE,
    EVENT_WIPE_CHECK,
    
    // Rampart of Skulls NPCs Events
    EVENT_WRATH,
    EVENT_HEAL,
    
    EVENT_SUNDER_ARMOR,
    EVENT_SPELL_REFLECT,
    EVENT_THUNDERCLAP,
    EVENT_DEVASTATE,
    
    EVENT_FROST_BREATH,
    EVENT_BLIZZARD,
    EVENT_CLEAVE,
    
    // Skybreaker Vindicator
    EVENT_AVENGERS_SHILED,
    EVENT_CONCENTRATION,
    EVENT_HOLY_WRATH,
    
    // First Squad Assisted
    EVENT_FIRST_SQUAD_ASSISTED_1,
    EVENT_FIRST_SQUAD_ASSISTED_2,
    
    // Second Squad Assisted
    EVENT_SECOND_SQUAD_ASSISTED_1,
    EVENT_SECOND_SQUAD_ASSISTED_2,
    EVENT_SECOND_SQUAD_ASSISTED_3,
    
    // Shared experience events
    EVENT_EXPERIENCED,
    EVENT_VETERAN,
    EVENT_ELITE,
    EVENT_ATACK_START,
    
    // Kor'kron Axethrower & Skybreaker Rifleman
    EVENT_HURL_AXE,
    EVENT_SHOOT,
    
    // Kor'kron Rocketeer & Skybreaker Mortar Soldier
    EVENT_ROCKET_ART,
    
    // Muradin Bronzebeard & High Overlord Saurfang
    EVENT_RENDING_THROW,
    EVENT_TASTE_OF_BLOOD,
    
    // Misc (used in various NPCs)
    EVENT_SPAWN_MAGE,
    EVENT_RESPAWN_AXES_RIFLEMEN,
    EVENT_RESPAWN_ROCKETEER,
};

enum Actions
{
    ACTION_START_FLIGHT             = 1,
    ACTION_BATTLE_EVENT = 2,
    ACTION_MAGE_DIE = 3,
    ACTION_ROCK_DIE = 4,
    ACTION_AXES_RIFL_DIE = 5,
    ACTION_DONE = 6,
    ACTION_FAIL = 7,
};

enum Texts
{
    // Kor'kron Primalist
    SAY_FIRST_SQUAD_RESCUED_HORDE_0 = 0,
    
    // Kor'kron Invoker
    SAY_FIRST_SQUAD_RESCUED_HORDE_1 = 0,
    
    // Kor'kron Defender
    SAY_SECOND_SQUAD_RESCUED_HORDE_0 = 0,
    SAY_SECOND_SQUAD_RESCUED_HORDE_1 = 1,
    SAY_FROSTWYRM_SUMMON_0 = 2,
    SAY_FROSTWYRM_SUMMON_1 = 3,
    
    // Skybreaker Vindicator
    SAY_FIRST_SQUAD_RESCUED_ALLIANCE_0 = 0,
    
    // Skybreaker Sorcerer
    SAY_FIRST_SQUAD_RESCUED_ALLIANCE_1 = 0,
    
    // Skybreaker Protector
    SAY_SECOND_SQUAD_RESCUED_ALLIANCE_0 = 0,
    SAY_SECOND_SQUAD_RESCUED_ALLIANCE_1 = 1,
    SAY_SECOND_SQUAD_RESCUED_ALLIANCE_2 = 2,
    
    // Kor'kron Invoker & Skybreaker Sorcerer
    SAY_SUMMON_BATTLE_STANDARD = 1,
    
    // Froswyrm
    SAY_FROSTWYRM_LAND_H_0 = 0,
    SAY_FROSTWYRM_LAND_A_1 = 1,
    
    // Muradin Bronzebeard
    SAY_INTRO_ALLIANCE_0 = 0,
    SAY_INTRO_ALLIANCE_1 = 1,
    SAY_INTRO_ALLIANCE_2 = 2,
    SAY_INTRO_ALLIANCE_3 = 3,
    SAY_INTRO_ALLIANCE_4 = 4,
    SAY_INTRO_ALLIANCE_5 = 5,
    SAY_INTRO_ALLIANCE_7 = 6,
    SAY_INTRO_HORDE_3 = 7,
    SAY_BOARDING_SKYBREAKER_1 = 8,
    SAY_BOARDING_ORGRIMS_HAMMER_0 = 9,
    SAY_NEW_RIFLEMEN_SPAWNED = 10,
    SAY_NEW_MORTAR_TEAM_SPAWNED = 11,
    SAY_NEW_MAGE_SPAWNED = 12,
    SAY_ALLIANCE_VICTORY = 13,
    SAY_ALLIANCE_DEFEAT = 14, // How will we handle that case ? Ie. the player loses
    
    // High Overlord Saurfang
    SAY_INTRO_HORDE_0 = 0,
    SAY_INTRO_HORDE_0_1 = 1,
    SAY_INTRO_HORDE_1 = 2,
    SAY_INTRO_HORDE_2 = 3,
    SAY_INTRO_HORDE_4 = 4,
    SAY_BOARDING_SKYBREAKER_0 = 5,
    SAY_BOARDING_ORGRIMS_HAMMER_1 = 6,
    SAY_NEW_AXETHROWER_SPAWNED = 7,
    SAY_NEW_ROCKETEERS_SPAWNED = 8,
    SAY_NEW_BATTLE_MAGE_SPAWNED = 9,
    SAY_HORDE_VICTORY = 10,
    SAY_HORDE_DEFEAT = 11,
    
    SAY_HIGH_OVERLORD_SAURFANG_NOT_VISUAL = 0,
    SAY_BOARDING_SKYBREAKER_SAURFANG = 1,
    SAY_MURADIN_BRONZEBEARD_NOT_VISUAL = 0,
    SAY_BOARDING_SKYBREAKER_MURADIN = 1,
};

//Find Unfriendy transport
Transport* CheckUnfriendlyShip(Creature* me, InstanceScript* instance, uint32 data)
{
    if(Creature* pCapitan = ObjectAccessor::GetCreature(*me, instance->GetData64(data)))
        return pCapitan->GetTransport();
    else
        return NULL;
}


void CreatePassenger(Transport* t, uint32 entry,  uint32 phaseMask, uint32 displayID /*= NULL*/, float x, float y, float z, float o, uint32 unit_flags = NULL, uint32 spawntimesec = NULL, uint32 currentwaypoint = NULL, uint8 movemenType = NULL, uint8 spawnMask = NULL, uint32 npcflag = NULL, uint32 dynamicflags = NULL)
{
    uint32 guid = sObjectMgr->GenerateLowGuid(HIGHGUID_UNIT);
    CreatureData& data = sObjectMgr->NewOrExistCreatureData(guid);
    data.id = entry;
    data.phaseMask = phaseMask;
    data.displayid = displayID;
    data.posX = x;
    data.posY = y;
    data.posZ = z;
    data.orientation = o;
    data.spawntimesecs = spawntimesec;
    data.currentwaypoint = currentwaypoint;
    data.movementType = movemenType;
    data.spawnMask = spawnMask;
    data.npcflag = npcflag;
    data.unit_flags = unit_flags;
    data.dynamicflags = dynamicflags;
    
    Creature* creature = t->CreateNPCPassenger(guid, &data);
    sObjectMgr->AddCreatureToGrid(guid, &data);
    creature->setActive(true);
}

void RelocateTransport(Transport* t)
{
    Map* map = t->GetMap();
    InstanceScript* instance = t->GetInstanceScript();
    
    if (!t || !instance)
        return;
    
    // Transoprt movemend on server-side is ugly hack, so we do sincronize positions
    switch (t->GetEntry())
    {
        case GO_ALLIANCE_GUNSHIP:
            if (instance->GetBossState(DATA_GUNSHIP_EVENT) != DONE)
                t->Relocate(-377.184021f, 2073.548584f, 445.753387f);
            else if (instance->GetBossState(DATA_GUNSHIP_EVENT) == DONE)
                t->Relocate(-583.942627f, 2212.364990f, 534.673889f);
            break;
        case GO_ALLIANCE_GUNSHIP_ENEMY:
            if (instance->GetBossState(DATA_GUNSHIP_EVENT) != DONE)
                t->Relocate(-384.878479f, 1989.831665f, 431.549438f);
            break;
        case GO_HORDE_GUNSHIP:
            if (instance->GetBossState(DATA_GUNSHIP_EVENT) != DONE)
                t->Relocate(-438.142365f, 2395.725830f, 436.781647f);
            else if (instance->GetBossState(DATA_GUNSHIP_EVENT) == DONE)
                t->Relocate(-583.942627f, 2212.364990f, 534.673889f);
            break;
        case GO_HORDE_GUNSHIP_ENEMY:
            if (instance->GetBossState(DATA_GUNSHIP_EVENT) != DONE)
                t->Relocate(-435.854156f, 2475.328125f, 449.364105f);
            break;
    }
    
    t->Update(0);
    //t->UpdatePassengerPositions();
}

void UpdateTransportMotionInMap(Transport* t)
{
    Map* map = t->GetMap();
    
    for (Map::PlayerList::const_iterator itr = map->GetPlayers().begin(); itr != map->GetPlayers().end(); ++itr)
    {
        if (Player* pPlayer = itr->GetSource())
        {
            UpdateData transData;
            t->BuildCreateUpdateBlockForPlayer(&transData, pPlayer);
            WorldPacket packet;
            transData.BuildPacket(&packet);
            pPlayer->SendDirectMessage(&packet);
        }
    }
}

void InitTransport(Transport* t)
{
    
	t->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_TRANSPORT);
	t->SetGoState(GO_STATE_ACTIVE);
	t->SetUInt32Value(GAMEOBJECT_DYNAMIC, 0x10830010);
	t->SetFloatValue(GAMEOBJECT_PARENTROTATION + 3, 1.0f);
    
	Map* map = t->GetMap();
	for(Map::PlayerList::const_iterator itr = map->GetPlayers().begin(); itr != map->GetPlayers().end(); ++itr)
	{
		if(Player* player = itr->GetSource())
		{
			UpdateData transData;
			t->BuildCreateUpdateBlockForPlayer(&transData, player);
            
			WorldPacket packet;
			transData.BuildPacket(&packet);
			player->SendDirectMessage(&packet);
		}
	}
};

void StopFlyShip(Transport* t)
{
    Map* map = t->GetMap();

    RelocateTransport(t);
    t->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
    t->SetGoState(GO_STATE_READY);
    
    for (Map::PlayerList::const_iterator itr = map->GetPlayers().begin(); itr != map->GetPlayers().end(); ++itr)
    {
        if (Player* pPlayer = itr->GetSource())
        {
            UpdateData transData;
            t->BuildCreateUpdateBlockForPlayer(&transData, pPlayer);
            WorldPacket packet;
            transData.BuildPacket(&packet);
            pPlayer->SendDirectMessage(&packet);
        }
    }
}

typedef std::list<Player*> TPlayerLists;

TPlayerLists GetPlayersInTheMaps(Map *pMap)
{
    TPlayerLists players;
    const Map::PlayerList &PlayerList = pMap->GetPlayers();
    if (!PlayerList.isEmpty())
        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            if (Player* player = i->GetSource())
                players.push_back(player);
    return players;
}

Player* SelectRandomPlayerFromLists(TPlayerLists &players)
{
    if (players.empty())
        return NULL;
    TPlayerLists::iterator it = players.begin();
    std::advance(it, urand(0, players.size()-1));
    return *it;
}

Player* SelectRandomPlayerInTheMaps(Map* pMap)
{
    TPlayerLists players = GetPlayersInTheMaps(pMap);
    return SelectRandomPlayerFromLists(players);
}

class GunshipStairs : public GameObjectScript
{
public:
	GunshipStairs() : GameObjectScript("icc_gunship_stairs") { }
    
	bool OnGossipHello(Player* player, GameObject* go)
	{
        player->Say("I clicked the stairs!", LANG_UNIVERSAL);
		if(player->GetTeamId() == 0)
		{
            player->Say("Alliance Gunship spawned from Stairs!", LANG_UNIVERSAL);
            
            Transport* gunshipAlliance;
            gunshipAlliance = sTransportMgr->CreateTransport(GO_ALLIANCE_GUNSHIP, 0, player->GetMap());
            
            
            //Multipurpose function, best used to update ship visibility, can also be used to start the event, if there are 2 transports active at the same time.
            /*Map* map = player->GetMap();
             for (Map::PlayerList::const_iterator itr = map->GetPlayers().begin(); itr != map->GetPlayers().end(); ++itr)
             map->SendInitTransports(player);*/
            
            
            
            TC_LOG_ERROR(LOG_FILTER_TRANSPORTS, "====== GUNSHIP SPAWNED! ======");
            
		}else{
            player->Say("Horde Gunship spawned from Stairs!", LANG_UNIVERSAL);
            
            
		}
        
		return true;
	}
};

class Gunship : public TransportScript
{
    
public:
	Gunship() : TransportScript("gunship_transport") { }

	void OnAddPassenger(Transport* transport, Player* player)
	{
		if(!transport || !player)
			return;
        
		switch(transport->GetEntry())
		{
            case GO_ALLIANCE_GUNSHIP:
                player->AddAura(SPELL_ALLIANCE, player);
                player->Say("Boarded Alliance ship!", LANG_UNIVERSAL);
                TC_LOG_ERROR(LOG_FILTER_TRANSPORTS, "====== GUNSHIP AURA ADDED! ======");
                break;
                
            case GO_ALLIANCE_GUNSHIP_ENEMY:
                player->AddAura(SPELL_HORDE, player);
                player->Say("Boarded enemy ship!", LANG_UNIVERSAL);
                TC_LOG_ERROR(LOG_FILTER_TRANSPORTS, "====== GUNSHIP AURA ADDED! ======");
                break;
                
            case GO_HORDE_GUNSHIP:
                player->AddAura(SPELL_HORDE, player);
                break;
                
            default:
                break;
		}
	}
    
    void OnRemovePassenger(Transport* /*transport*/, Player* player)
    {
        if (!player)
            return;
        player->RemoveAurasDueToSpell(SPELL_ALLIANCE);
        player->RemoveAurasDueToSpell(SPELL_HORDE);
    }
};

//Muradin Bronzebeard
class npc_muradin_gunship : public CreatureScript
{
public:
    npc_muradin_gunship() : CreatureScript("npc_muradin_gunship") { }
    
    bool OnGossipHello(Player* player, Creature* pCreature)
    {
        InstanceScript* pInstance = pCreature->GetInstanceScript();
        if (pInstance && pInstance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
        {            
            player->ADD_GOSSIP_ITEM(0, "My companions are all accounted for, Muradin. Let's go!", 631, 1001);
            player->SEND_GOSSIP_MENU(player->GetGossipTextId(pCreature), pCreature->GetGUID());
            return true;
        }
        return false;
    }
    
    bool OnGossipSelect(Player* player, Creature* pCreature, uint32 /*sender*/, uint32 action)
    {
        InstanceScript* instance = pCreature->GetInstanceScript();
        player->PlayerTalkClass->ClearMenus();
        player->CLOSE_GOSSIP_MENU();
        
        if (action == GOSSIP_ACTION_INFO_DEF+2)
            pCreature->MonsterSay("I'll wait for the raid leader", LANG_UNIVERSAL, player->GetGUID());
        
        if (action == 1001)
        {
            pCreature->AI()->DoAction(ACTION_START_FLIGHT);
            pCreature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }
        return true;
    }
    
    struct npc_muradin_gunshipAI : public ScriptedAI
    {
        npc_muradin_gunshipAI(Creature *creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript())
        {
            
        }
        
        void Reset()
        {
            if (_instance->GetBossState(DATA_GUNSHIP_EVENT) == IN_PROGRESS)
                return;
            me->SetReactState(REACT_PASSIVE);
            me->setFaction(1802);
            events.Reset();
            map = me->GetMap();
            me->AI()->DoAction(ACTION_START_FLIGHT);
            
            skybreaker = me->GetTransport();
            UpdateTransportMotionInMap(skybreaker);
            
            SummonCount = RAID_MODE(3, 5, 4, 6);
            count = 0;
            RocketerCount = RAID_MODE(2, 4, 2, 4);
            RiflCount = RAID_MODE(4, 6, 4, 6);
            RocketerDieCount = 0;
            RiflDieCount = 0;
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            EventScheduled = false;
        }
        
        void SendMusicToPlayers(uint32 musicId) const
        {
            WorldPacket data(SMSG_PLAY_MUSIC, 4);
            data << uint32(musicId);
            SendPacketToPlayers(&data);
        }
        
        // Send packet to all players
        void SendPacketToPlayers(WorldPacket const* data) const
        {
            Map::PlayerList const& players = me->GetMap()->GetPlayers();
            if (!players.isEmpty())
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    if (Player* player = itr->GetSource())
                        player->GetSession()->SendPacket(data);
        }
        
        bool CanAIAttack(Unit const* target) const
        {
            if (target->GetEntry() == NPC_GB_KORKRON_SERGANTE || target->GetEntry() == NPC_GB_KORKRON_REAVERS)
                return true;
            
            return false;
        }
        
        void DoAction(int32 action)
        {
            switch (action)
            {
                case ACTION_START_FLIGHT:
                    events.ScheduleEvent(EVENT_INTRO_ALLIANCE_1, 1000);
                    events.ScheduleEvent(EVENT_START_FLY, 2500);
                    events.ScheduleEvent(EVENT_INTRO_ALLIANCE_2, 7000);
                    events.ScheduleEvent(EVENT_INTRO_ALLIANCE_3, 28000);
                    events.ScheduleEvent(EVENT_INTRO_ALLIANCE_4, 35000);
                    events.ScheduleEvent(EVENT_INTRO_ALLIANCE_5, 40000);
                    events.ScheduleEvent(EVENT_INTRO_ALLIANCE_6, 47000);
                    events.ScheduleEvent(EVENT_INTRO_ALLIANCE_7, 53000);
                    events.ScheduleEvent(EVENT_INTRO_ALLIANCE_8, 58900);
                    break;
                case ACTION_BATTLE_EVENT:
                {
                    if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        events.ScheduleEvent(EVENT_WIPE_CHECK, 5000);
                    
                    Creature* pAllianceBoss = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_SKYBREAKER_BOSS));
                    Creature* pHordeBoss = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_ORGRIMMAR_HAMMER_BOSS));
                    
                    if (pHordeBoss && pAllianceBoss)
                    {
                        me->SetReactState(REACT_AGGRESSIVE);
                        pHordeBoss->SetInCombatWith(pAllianceBoss);
                        pAllianceBoss->SetInCombatWith(pHordeBoss);
                        pAllianceBoss->AddThreat(pHordeBoss, 0.0f);
                        pHordeBoss->AddThreat(pAllianceBoss, 0.0f);
                        _instance->SetBossState(DATA_GUNSHIP_EVENT, IN_PROGRESS);
                        events.ScheduleEvent(EVENT_SUMMON_PORTAL, 30000);
                        RelocateTransport(skybreaker);
                        RelocateTransport(CheckUnfriendlyShip(me,_instance, DATA_GB_HIGH_OVERLORD_SAURFANG));
                    }
                    else
                        me->AI()->DoAction(ACTION_FAIL);
                    break;
                }
                case ACTION_DONE:
                    if (Creature* pAllianceBoss = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_SKYBREAKER_BOSS)))
                    {
                        _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, pAllianceBoss);
                    }
                    if (Creature* pHordeBoss = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_ORGRIMMAR_HAMMER_BOSS)))
                    {
                        _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, pHordeBoss);
                    }
                    
                    me->SetReactState(REACT_PASSIVE);
                    _instance->SetBossState(DATA_GUNSHIP_EVENT, DONE);
                    _instance->DoCastSpellOnPlayers(SPELL_REMOVE_ROCKET_PACK);
                    Talk(SAY_ALLIANCE_VICTORY);
                    events.CancelEvent(EVENT_WIPE_CHECK);
                    events.ScheduleEvent(EVENT_OUTRO_ALLIANCE_1, 3500);
                    events.ScheduleEvent(EVENT_OUTRO_ALLIANCE_2, 23000);
                    events.ScheduleEvent(EVENT_OUTRO_ALLIANCE_3, 32000);
                    break;
                case ACTION_FAIL:
                    events.CancelEvent(EVENT_WIPE_CHECK);
                    Talk(SAY_ALLIANCE_DEFEAT);
                    if (Creature* pAllianceBoss = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_SKYBREAKER_BOSS)))
                    {
                        _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, pAllianceBoss);
                    }
                    if (Creature* pHordeBoss = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_ORGRIMMAR_HAMMER_BOSS)))
                    {
                        _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, pHordeBoss);
                    }
                    //StopFight(skybreaker, CheckUnfriendlyShip(me, _instance, DATA_GB_HIGH_OVERLORD_SAURFANG));
                    events.ScheduleEvent(EVENT_FAIL, 10000);
                    break;
                case ACTION_MAGE_DIE:
                    //Check, if there really is no mage
                    if(me->GetEntry() != NPC_GB_SKYBREAKER_SORCERERS){
                        if(_instance->GetBossState(DATA_GUNSHIP_EVENT) != DONE)
                            events.ScheduleEvent(EVENT_SPAWN_MAGE, 33000);
                    }
                    break;
                case ACTION_ROCK_DIE:
                    ++RocketerDieCount;
                    if(RocketerDieCount == RocketerCount)
                        if(_instance->GetBossState(DATA_GUNSHIP_EVENT) != DONE)
                            events.ScheduleEvent(EVENT_RESPAWN_ROCKETEER, 60000);
                    break;
                case ACTION_AXES_RIFL_DIE:
                    ++RiflDieCount;
                    if(RiflDieCount == RiflCount)
                        if(_instance->GetBossState(DATA_GUNSHIP_EVENT) != DONE)
                            events.ScheduleEvent(EVENT_RESPAWN_AXES_RIFLEMEN, 60000);
                    break;
            }
        }
        
        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
            if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE && me->GetHealthPct() < 2.0f )
            {
                damage = 0;
            }
            
            if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE && me->GetHealthPct() < 2.0f )
            {
                damage = 0;
                me->AI()->DoAction(ACTION_FAIL);
            }
        }
        
        void MovementInform(uint32 type, uint32 pointId)
        {
            if (type != POINT_MOTION_TYPE)
                return;
            
            if (pointId = 1)
                me->DespawnOrUnsummon(1000);
        }
        
        void UpdateAI(uint32 diff)
        {
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
            
            if (!HealthAbovePct(75))
            {
                me->SetHealth(me->GetMaxHealth() / 100 * 76); // find a better way to avoid the hardcore spell spam ....
                DoCast(me, SPELL_TASTE_OF_BLOOD);
            }
            
            if (UpdateVictim())
            {
                if (!EventScheduled)
                {
                    EventScheduled = true; // should temp fix the hardcore casting
                    events.ScheduleEvent(EVENT_RENDING_THROW, 3000);
                }
            }
            
            events.Update(diff);
            
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_INTRO_ALLIANCE_1:
                        Talk(SAY_INTRO_ALLIANCE_0);
                        break;
                    case EVENT_START_FLY:
                        InitTransport(skybreaker);
                        break;
                    case EVENT_INTRO_ALLIANCE_2:
                        Talk(SAY_INTRO_ALLIANCE_1);
                        break;
                    case EVENT_INTRO_ALLIANCE_3:
                        Talk(SAY_INTRO_ALLIANCE_2);
                        InitTransport(CheckUnfriendlyShip(me, _instance, DATA_GB_HIGH_OVERLORD_SAURFANG));
                        break;
                    case EVENT_INTRO_ALLIANCE_4:
                        Talk(SAY_INTRO_ALLIANCE_3);
                        break;
                    case EVENT_INTRO_ALLIANCE_5:
                        Talk(SAY_INTRO_ALLIANCE_4);
                        break;
                    case EVENT_INTRO_ALLIANCE_6:
                        Talk(SAY_INTRO_ALLIANCE_5);
                        SendMusicToPlayers(17289);
                        me->AI()->DoAction(ACTION_BATTLE_EVENT);
                        break;
                    case EVENT_INTRO_ALLIANCE_7:
                        if (Creature* pSaurfang = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HIGH_OVERLORD_SAURFANG_NOT_VISUAL)))
                        {
                            pSaurfang->AI()->Talk(SAY_HIGH_OVERLORD_SAURFANG_NOT_VISUAL);
                            pSaurfang->SetReactState(REACT_PASSIVE);
                            pSaurfang->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                        }
                        break;
                    case EVENT_INTRO_ALLIANCE_8:
                        Talk(SAY_INTRO_ALLIANCE_7);
                        break;
                    case EVENT_SUMMON_PORTAL:
                        if(_instance->GetBossState(DATA_GUNSHIP_EVENT) != DONE)
                        {
                            events.ScheduleEvent(EVENT_BOARDING_TALK, 10000);
                            events.ScheduleEvent(EVENT_BOARDING_GUNSHIP, 2500); // TODO: Fix the timers
                            CreatePassenger(skybreaker, NPC_GB_PORTAL,1, 30615, -15.51547f, -0.160213f, 28.87252f, 1.56211f);
                            CreatePassenger(skybreaker, NPC_GB_KORKRON_AXETHROWER, 1, 30739, -15.51547f, -0.160213f, 28.87252f, 1.56211f);
                            //CheckUnfriendlyShip(me, _instance, DATA_GB_HIGH_OVERLORD_SAURFANG)->AddNPCPassengerInInstance(NPC_GB_PORTAL, 47.55099f, -0.101778f, 37.61111f, 1.55138f);
                        }
                        break;
                    case EVENT_RENDING_THROW:
                        if (UpdateVictim())
                            if (me->GetVictim()->IsWithinDistInMap(me, 30.0f, false))
                            {
                                DoCastVictim(SPELL_RENDING_THROW);
                                EventScheduled = false;
                            }
                            else
                                events.CancelEvent(EVENT_RENDING_THROW);
                        break;
                    case EVENT_TASTE_OF_BLOOD:
                        DoCast(me, SPELL_TASTE_OF_BLOOD);
                        break;
                    case EVENT_BOARDING_TALK:
                        Talk(SAY_BOARDING_SKYBREAKER_1);
                        break;
                    case EVENT_BOARDING_GUNSHIP:
                        if(_instance->GetBossState(DATA_GUNSHIP_EVENT) != DONE){
                            if (Creature* pSaurfang = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HIGH_OVERLORD_SAURFANG_NOT_VISUAL)))
                            {
                                pSaurfang->AI()->Talk(SAY_BOARDING_SKYBREAKER_SAURFANG);
                            }
                            events.ScheduleEvent(EVENT_SUMMON_PORTAL, 90000);
                            events.ScheduleEvent(EVENT_BOARDING_REAVERS_MARINE, 3000);
                            count = 0;
                        }
                        break;
                    case EVENT_OUTRO_ALLIANCE_1:
                        _instance->DoCastSpellOnPlayers(SPELL_ACHIEVEMENT_CHECK);
                        InitTransport(skybreaker);
                        break;
                }
            }
            
            if (!me->GetCurrentSpell(CURRENT_MELEE_SPELL))
                DoCastVictim(SPELL_CLEAVE);
            
            DoMeleeAttackIfReady();
        }
        
    private:
        Transport* skybreaker;
        Player* plr;
        Map* map;
        uint32 SummonCount;
        EventMap events;
        InstanceScript* _instance;
        uint32 count;
        uint32 RocketerDieCount;
        uint32 RiflDieCount;
        uint32 RocketerCount;
        uint32 RiflCount;
        bool EventScheduled;
    };
    
    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_muradin_gunshipAI(pCreature);
    }
};

class npc_saurfang_gunship : public CreatureScript
{
public:
    npc_saurfang_gunship() : CreatureScript("npc_saurfang_gunship") { }
    
    bool OnGossipHello(Player* player, Creature* pCreature)
    {
        InstanceScript* pInstance = pCreature->GetInstanceScript();
        if (pInstance && pInstance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
        {
            if ((!player->GetGroup() || !player->GetGroup()->IsLeader(player->GetGUID())) && !player->IsGameMaster())
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "I'm not the raid leader...", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
                return true;
            }
            
            player->ADD_GOSSIP_ITEM(0, "My companions are all accounted for, Saurfang. Let's go!", 631, 1001);
            player->SEND_GOSSIP_MENU(player->GetGossipTextId(pCreature), pCreature->GetGUID());
            return true;
        }
        return false;
    }
    
    bool OnGossipSelect(Player* player, Creature* pCreature, uint32 /*sender*/, uint32 action)
    {
        InstanceScript* instance = pCreature->GetInstanceScript();
        player->PlayerTalkClass->ClearMenus();
        player->CLOSE_GOSSIP_MENU();
        
        if (action == GOSSIP_ACTION_INFO_DEF+2)
            pCreature->MonsterSay("I'll wait for the raid leader.", LANG_UNIVERSAL, player->GetGUID());
        
        if (action == 1001)
        {
            pCreature->AI()->DoAction(ACTION_START_FLIGHT);
            pCreature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }
        return true;
    }
    struct npc_saurfang_gunshipAI : public ScriptedAI
    {
        npc_saurfang_gunshipAI(Creature *creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript())
        {
        }
        
        void Reset()
        {
            if (_instance->GetBossState(DATA_GUNSHIP_EVENT) == IN_PROGRESS)
                return;
            me->SetReactState(REACT_PASSIVE);
            me->setFaction(1801);
            events.Reset();
            map = me->GetMap();
            orgrimmar = me->GetTransport();
            UpdateTransportMotionInMap(orgrimmar);
            RocketerDieCount = 0;
            AxesDieCount = 0;
            SummonCount = RAID_MODE(3, 5, 4, 6);
            count = 0;
            RocketerCount = RAID_MODE(2, 4, 2, 4);
            AxesCount = RAID_MODE(4, 6, 4, 6);
            EventScheduled = false;
        }
        
        void SendMusicToPlayers(uint32 musicId) const
        {
            WorldPacket data(SMSG_PLAY_MUSIC, 4);
            data << uint32(musicId);
            SendPacketToPlayers(&data);
        }
        
        // Send packet to all players
        void SendPacketToPlayers(WorldPacket const* data) const
        {
            Map::PlayerList const& players = me->GetMap()->GetPlayers();
            if (!players.isEmpty())
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    if (Player* player = itr->GetSource())
                        player->GetSession()->SendPacket(data);
        }
        
        bool CanAIAttack(Unit const* target) const
        {
            if (target->GetEntry() == NPC_GB_SKYBREAKER_SERGANTE || target->GetEntry() == NPC_GB_SKYBREAKER_MARINE)
                return true;
            
            return false;
        }
        
        void DoAction(int32 action)
        {
            switch (action)
            {
                case ACTION_START_FLIGHT:
                    events.ScheduleEvent(EVENT_INTRO_HORDE_1, 1000);
                    events.ScheduleEvent(EVENT_INTRO_HORDE_1_1, 11000);
                    events.ScheduleEvent(EVENT_START_FLY, 5000);
                    events.ScheduleEvent(EVENT_INTRO_HORDE_2, 32000);
                    events.ScheduleEvent(EVENT_INTRO_HORDE_3, 51000);
                    events.ScheduleEvent(EVENT_INTRO_HORDE_4, 57000);
                    events.ScheduleEvent(EVENT_INTRO_HORDE_5, 62000);
                    break;
                case ACTION_BATTLE_EVENT:
                {
                    if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                        events.ScheduleEvent(EVENT_WIPE_CHECK, 5000);
                    
                    Creature* pHordeBoss = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_ORGRIMMAR_HAMMER_BOSS));
                    Creature* pAllianceBoss = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_SKYBREAKER_BOSS));
                    
                    if (pHordeBoss && pAllianceBoss)
                    {
                        me->SetReactState(REACT_AGGRESSIVE);
                        pHordeBoss->SetInCombatWith(pAllianceBoss);
                        pAllianceBoss->SetInCombatWith(pHordeBoss);
                        pAllianceBoss->AddThreat(pHordeBoss, 0.0f);
                        pHordeBoss->AddThreat(pAllianceBoss, 0.0f);
                        _instance->SetBossState(DATA_GUNSHIP_EVENT, IN_PROGRESS);
                        events.ScheduleEvent(EVENT_SUMMON_PORTAL, 30000);
                        RelocateTransport(orgrimmar);
                        RelocateTransport(CheckUnfriendlyShip(me,_instance, DATA_GB_MURADIN_BRONZEBEARD));
                    }
                    else
                        me->AI()->DoAction(ACTION_FAIL);
                    break;
                }
                case ACTION_DONE:
                    if (Creature* pAllianceBoss = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_SKYBREAKER_BOSS)))
                    {
                        _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, pAllianceBoss);
                    }
                    if (Creature* pHordeBoss = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_ORGRIMMAR_HAMMER_BOSS)))
                    {
                        _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, pHordeBoss);
                    }
                    
                    me->SetReactState(REACT_PASSIVE);
                    _instance->SetBossState(DATA_GUNSHIP_EVENT, DONE);
                    _instance->DoCastSpellOnPlayers(SPELL_REMOVE_ROCKET_PACK);
                    Talk(SAY_HORDE_VICTORY);
                    //StartFlyShip(CheckUnfriendlyShip(me, _instance, DATA_GB_MURADIN_BRONZEBEARD));
                    //StopFight(orgrimmar,CheckUnfriendlyShip(me,_instance, DATA_GB_MURADIN_BRONZEBEARD));
                    events.CancelEvent(EVENT_WIPE_CHECK);
                    events.ScheduleEvent(EVENT_OUTRO_HORDE_1, 3500);
                    events.ScheduleEvent(EVENT_OUTRO_HORDE_2, 21000);
                    events.ScheduleEvent(EVENT_OUTRO_HORDE_3, 32000);
                    break;
                case ACTION_FAIL:
                    events.CancelEvent(EVENT_WIPE_CHECK);
                    Talk(SAY_HORDE_DEFEAT);
                    if (Creature* pHordeBoss = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_ORGRIMMAR_HAMMER_BOSS)))
                    {
                        _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, pHordeBoss);
                    }
                    if (Creature* pAllianceBoss = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_SKYBREAKER_BOSS)))
                    {
                        _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, pAllianceBoss);
                    }
                    //StopFight(orgrimmar,CheckUnfriendlyShip(me,_instance, DATA_GB_MURADIN_BRONZEBEARD));
                    events.ScheduleEvent(EVENT_FAIL, 10000);
                    break;
                case ACTION_MAGE_DIE:
                    //Check, if there really is no mage
                    if(me->GetEntry() != NPC_GB_KORKRON_BATTLE_MAGE){
                        events.ScheduleEvent(EVENT_SPAWN_MAGE, 60000);
                    }
                    break;
                case ACTION_ROCK_DIE:
                    ++RocketerDieCount;
                    if(RocketerDieCount == RocketerCount)
                        events.ScheduleEvent(EVENT_RESPAWN_ROCKETEER, 60000);
                    break;
                case ACTION_AXES_RIFL_DIE:
                    ++AxesDieCount;
                    if(AxesDieCount == AxesCount)
                        events.ScheduleEvent(EVENT_RESPAWN_AXES_RIFLEMEN, 60000);
                    break;
            }
        }
        
        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
            if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE && me->GetHealthPct() < 2.0f )
            {
                damage = 0;
            }
            
            if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE && me->GetHealthPct() < 2.0f )
            {
                damage = 0;
                me->AI()->DoAction(ACTION_FAIL);
            }
        }
        
        void MovementInform(uint32 type, uint32 pointId)
        {
            if (type != POINT_MOTION_TYPE)
                return;
            
            if (pointId = 1)
                me->DespawnOrUnsummon(1000);
        }
        
        void UpdateAI(uint32 diff)
        {
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
            
            if(_instance->GetBossState(DATA_GUNSHIP_EVENT) == IN_PROGRESS)
            {
                if (!HealthAbovePct(75))
                {
                    me->SetHealth(me->GetMaxHealth() / 100 * 76); // find a better way to avoid the hardcore spell spam ....
                    DoCast(me, SPELL_TASTE_OF_BLOOD);
                }
                
                if (UpdateVictim())
                {
                    if (!EventScheduled)
                    {
                        events.ScheduleEvent(EVENT_RENDING_THROW, 1500);
                        EventScheduled = true;
                    }
                }
            }
            
            events.Update(diff);
            
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_WIPE_CHECK:
                        //DoCheckFallingPlayer(me);
                        //if (DoWipeCheck(orgrimmar))
                            //events.ScheduleEvent(EVENT_WIPE_CHECK, 3000);
                        //else
                            //me->AI()->DoAction(ACTION_FAIL);
                        break;
                    case EVENT_INTRO_HORDE_1:
                        Talk(SAY_INTRO_HORDE_0);
                        InitTransport(orgrimmar);
                        break;
                    case EVENT_INTRO_HORDE_1_1:
                        Talk(SAY_INTRO_HORDE_0_1);
                        break;
                    case EVENT_START_FLY:
                        InitTransport(orgrimmar); // Try
                        break;
                    case EVENT_INTRO_HORDE_2:
                        //StopFlyShip(orgrimmar);
                        //StartFlyShip(CheckUnfriendlyShip(me, _instance, DATA_GB_MURADIN_BRONZEBEARD));
                        Talk(SAY_INTRO_HORDE_1);
                        break;
                    case EVENT_INTRO_HORDE_3:
                        //StopFlyShip(CheckUnfriendlyShip(me, _instance, DATA_GB_MURADIN_BRONZEBEARD));
                        Talk(SAY_INTRO_HORDE_2);
                        break;
                    case EVENT_INTRO_HORDE_4:
                        SendMusicToPlayers(17289);
                        me->AI()->DoAction(ACTION_BATTLE_EVENT);
                        if (Creature* pMuradin = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_MURADIN_BRONZEBEARD_NOT_VISUAL)))
                        {
                            pMuradin->AI()->Talk(SAY_MURADIN_BRONZEBEARD_NOT_VISUAL);
                            pMuradin->SetReactState(REACT_PASSIVE);
                            pMuradin->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                        }
                        break;
                    case EVENT_INTRO_HORDE_5:
                        Talk(SAY_INTRO_HORDE_4);
                        break;
                    case EVENT_SUMMON_PORTAL:
                        if(_instance->GetBossState(DATA_GUNSHIP_EVENT) != DONE){
                            //orgrimmar->AddNPCPassengerInInstance(NPC_GB_PORTAL, 15.03016f, -7.00016f, 37.70952f, 1.55138f);
                            //CheckUnfriendlyShip(me, _instance, DATA_MURADIN_BRONZEBEARD_NOT_VISUAL)->AddNPCPassengerInInstance(NPC_GB_PORTAL, 3.51547f, -0.160213f, 20.87252f, 3.05033f);
                            events.ScheduleEvent(EVENT_BOARDING_TALK, 10000);
                            events.ScheduleEvent(EVENT_BOARDING_GUNSHIP, 2500); // TODO: Fix the timers
                        }
                        break;
                    case EVENT_BOARDING_TALK:
                        Talk(SAY_BOARDING_ORGRIMS_HAMMER_1);
                        break;
                    case EVENT_BOARDING_GUNSHIP:
                        if(_instance->GetBossState(DATA_GUNSHIP_EVENT) != DONE){
                            count = 0;
                            if (Creature* pSaurfang = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_MURADIN_BRONZEBEARD_NOT_VISUAL)))
                            {
                                pSaurfang->AI()->Talk(SAY_BOARDING_SKYBREAKER_MURADIN);
                            }
                            /*if (Creature* Sergante = orgrimmar->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_SERGANTE, 15.03016f, -7.00016f, 37.70952f, 1.55138f))
                            {
                                Sergante->CastSpell(Sergante, SPELL_TELEPORT_VISUAL, true);
                            }*/
                            events.ScheduleEvent(EVENT_BOARDING_REAVERS_MARINE, 3000);
                            events.ScheduleEvent(EVENT_SUMMON_PORTAL, 90000);
                        }
                        break;
                    case EVENT_BOARDING_REAVERS_MARINE:
                        if(_instance->GetBossState(DATA_GUNSHIP_EVENT) != DONE){
                            if(count <= SummonCount)
                            {
                                /*if(Creature* Marine = orgrimmar->AddNPCPassengerInInstance(NPC_GB_SKYBREAKER_MARINE, 15.03016f, -7.00016f, 37.70952f, 1.55138f))
                                {
                                    Marine->CastSpell(Marine, SPELL_TELEPORT_VISUAL, true);
                                    count++;
                                    events.ScheduleEvent(EVENT_BOARDING_REAVERS_MARINE, 2500);
                                }*/
                            }
                        }
                        break;
                    case EVENT_OUTRO_HORDE_1:
                        //_instance->DoCompleteAchievement(RAID_MODE(IM_ON_A_BOAT_10,IM_ON_A_BOAT_25,IM_ON_A_BOAT_10,IM_ON_A_BOAT_25));
                        _instance->DoCastSpellOnPlayers(SPELL_ACHIEVEMENT_CHECK);
                        InitTransport(orgrimmar);
                        //StopFlyShip(CheckUnfriendlyShip(me,_instance,DATA_GB_MURADIN_BRONZEBEARD));
                        break;
                    case EVENT_OUTRO_HORDE_2:
                        //StopFlyShip(orgrimmar);
                        //me->SummonGameObject(RAID_MODE(GO_CAPITAN_CHEST_H_10N, GO_CAPITAN_CHEST_H_25N, GO_CAPITAN_CHEST_H_10H, GO_CAPITAN_CHEST_H_25H), -590.200022f, 2241.193115f, 539.588269f, 0, 0, 0, 0, 0, 100000);
                        me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
                        me->GetMotionMaster()->MovePoint(0, -590.700f, 2213.01f, 539.1f);
                        break;
                    case EVENT_OUTRO_HORDE_3:
                        me->GetMotionMaster()->MovePoint(1, -555.59f, 2213.01f, 539.28f);
                        break;
                    case EVENT_FAIL:
                        //TeleportPlayers(map, HORDE);
                        events.ScheduleEvent(EVENT_RESTART_EVENT, 2000);
                        _instance->SetBossState(DATA_GUNSHIP_EVENT, NOT_STARTED);
                        break;
                    case EVENT_RESTART_EVENT:
                        if(_instance->GetBossState(DATA_GUNSHIP_EVENT) != DONE){
                            _instance->SetBossState(DATA_GUNSHIP_EVENT, FAIL);
                            //RestartEvent(orgrimmar, CheckUnfriendlyShip(me,_instance,DATA_GB_MURADIN_BRONZEBEARD), map, HORDE);
                        }
                        break;
                    case EVENT_RENDING_THROW:
                        if (UpdateVictim())
                            if (me->GetVictim()->IsWithinDistInMap(me, 30.0f, false))
                            {
                                DoCastVictim(SPELL_RENDING_THROW);
                                EventScheduled = false;
                            }
                            else
                                events.CancelEvent(EVENT_RENDING_THROW);
                        break;
                    case EVENT_SPAWN_MAGE:
                        //Prevent from spawning multiple Mages
                        if(me->GetEntry() != NPC_GB_KORKRON_BATTLE_MAGE){
                            Talk(SAY_NEW_BATTLE_MAGE_SPAWNED);
                            //orgrimmar->AddNPCPassengerInInstance(NPC_GB_KORKRON_BATTLE_MAGE, 15.03016f, 0.00016f, 37.70952f, 1.55138f);
                        }
                        break;
                    /*case EVENT_RESPAWN_ROCKETEER:
                        Talk(SAY_NEW_ROCKETEERS_SPAWNED);
                        if(RocketerCount == 2)
                        {
                            orgrimmar->AddNPCPassengerInInstance(NPC_GB_KORKRON_ROCKETEER, -11.44849f, -25.71838f, 33.64343f, 1.49248f);
                            orgrimmar->AddNPCPassengerInInstance(NPC_GB_KORKRON_ROCKETEER, 12.30336f, -25.69653f, 35.32373f, 1.49248f);
                        }
                        if(RocketerCount == 4)
                        {
                            orgrimmar->AddNPCPassengerInInstance(NPC_GB_KORKRON_ROCKETEER, -11.44849f, -25.71838f, 33.64343f, 1.49248f);
                            orgrimmar->AddNPCPassengerInInstance(NPC_GB_KORKRON_ROCKETEER, 12.30336f, -25.69653f, 35.32373f, 1.49248f);
                            orgrimmar->AddNPCPassengerInInstance(NPC_GB_KORKRON_ROCKETEER, -3.44849f, -25.71838f, 34.21082f, 1.49248f);
                            orgrimmar->AddNPCPassengerInInstance(NPC_GB_KORKRON_ROCKETEER, 3.30336f, -25.69653f, 35.32373f, 1.49248f);
                        }
                        break;
                    case EVENT_RESPAWN_AXES_RIFLEMEN:
                        Talk(SAY_NEW_AXETHROWER_SPAWNED);
                        if(AxesCount == 4)
                        {
                            orgrimmar->AddNPCPassengerInInstance(NPC_GB_KORKRON_AXETHROWER, -3.170555f, 28.30652f, 34.21082f, 1.66527f);
                            orgrimmar->AddNPCPassengerInInstance(NPC_GB_KORKRON_AXETHROWER, -12.0928f, 27.65942f, 33.58557f, 1.66527f);
                            orgrimmar->AddNPCPassengerInInstance(NPC_GB_KORKRON_AXETHROWER, 14.92804f, 26.18018f, 35.47803f, 1.66527f);
                            orgrimmar->AddNPCPassengerInInstance(NPC_GB_KORKRON_AXETHROWER, 24.70331f, 25.36584f, 35.97845f, 1.66527f);
                        }
                        if(AxesCount == 6)
                        {
                            orgrimmar->AddNPCPassengerInInstance(NPC_GB_KORKRON_AXETHROWER, -3.170555f, 28.30652f, 34.21082f, 1.66527f);
                            orgrimmar->AddNPCPassengerInInstance(NPC_GB_KORKRON_AXETHROWER, -12.0928f, 27.65942f, 33.58557f, 1.66527f);
                            orgrimmar->AddNPCPassengerInInstance(NPC_GB_KORKRON_AXETHROWER, 14.92804f, 26.18018f, 35.47803f, 1.66527f);
                            orgrimmar->AddNPCPassengerInInstance(NPC_GB_KORKRON_AXETHROWER, 24.70331f, 25.36584f, 35.97845f, 1.66527f);
                            orgrimmar->AddNPCPassengerInInstance(NPC_GB_KORKRON_AXETHROWER, 19.92804f, 27.18018f, 35.47803f, 1.66527f);
                            orgrimmar->AddNPCPassengerInInstance(NPC_GB_KORKRON_AXETHROWER, -7.70331f, 28.36584f, 33.88557f, 1.66527f);
                        }
                        break;*/
                }
            }
            
            if (!me->GetCurrentSpell(CURRENT_MELEE_SPELL))
                DoCastVictim(SPELL_CLEAVE);
            
            DoMeleeAttackIfReady();
        }
        
        
    private:
        Transport* orgrimmar;
        uint32 RocketerDieCount;
        uint32 AxesDieCount;
        uint32 RocketerCount;
        uint32 AxesCount;
        uint32 SummonCount;
        uint32 count;
        bool EventScheduled;
        Map* map;
        EventMap events;
        InstanceScript* _instance;
    };
    
    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_saurfang_gunshipAI(pCreature);
    }
};

class npc_gunship_cannon : public CreatureScript
{
    
public:
	npc_gunship_cannon() : CreatureScript("npc_gunship_cannon" )  { }
    
	struct npc_gunship_cannonAI : public ScriptedAI
	{
		npc_gunship_cannonAI(Creature* creature) : ScriptedAI(creature) {}
        
		void Reset() OVERRIDE
		{
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            //DoCast(me, SPELL_HEAT_DRAIN, true);
            me->setActive(true);
			TC_LOG_ERROR(LOG_FILTER_WORLDSERVER, "AI Reset creature: %u", me->GetGUID());
		}
        
    private:
        //Transport* skybreaker;
        //Map* map;
        InstanceScript* instance;
        Player* plr;
        EventMap events;
        bool EventScheduled;
        
    };
    
    CreatureAI* GetAI(Creature* creature) const
	{
		return new npc_gunship_cannonAI(creature);
	}
    
};

class npc_zafod_boombox : public CreatureScript
{
    
public:
	npc_zafod_boombox() : CreatureScript("npc_zafod_boombox" )  { }
    
    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pPlayer->GetItemCount(49278, false) == 0)
            pPlayer->ADD_GOSSIP_ITEM(0, "Yeah, I'm sure that safety is your top priority. Give me a jetpack.", 631, 1);
        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        return true;
    }
    
    bool OnGossipSelect(Player* player, Creature* pCreature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        player->CLOSE_GOSSIP_MENU();
        if (action == 1)
        {
            // Seurity, this shouldn't happen. Maybe useless.
            uint32 curItemCount = player->GetItemCount(49278, false);
            if (curItemCount >= 1)
            {
                pCreature->MonsterWhisper("You already have my jetpack!", player->GetGUIDLow());
                return false;
            }
            
            ItemPosCountVec dest;
            uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, 49278, 1);
            if (msg == EQUIP_ERR_OK)
            {
                Item* item = player->StoreNewItem(dest, 49278, true);
                player->SendNewItem(item, 1, true, false);
            }
            else
            {
                pCreature->MonsterWhisper("You do not have empty space for my jet-pack!", player->GetGUIDLow());
                return false;
            }
        }
        
        return true;
    }
    
	struct npc_zafod_boomboxAI : public ScriptedAI
	{
		npc_zafod_boomboxAI(Creature* creature) : ScriptedAI(creature) {}
        
		void Reset() OVERRIDE
		{
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            me->setActive(true);
			TC_LOG_ERROR(LOG_FILTER_WORLDSERVER, "AI Reset creature: %u", me->GetGUID());
		}
        
    };
    
    CreatureAI* GetAI(Creature* creature) const
	{
		return new npc_zafod_boomboxAI(creature);
	}
    
};

class npc_high_cpt_bartlett : public CreatureScript
{
    
public:
	npc_high_cpt_bartlett() : CreatureScript("npc_high_cpt_bartlett" )  { }
    
	struct npc_high_cpt_bartlettAI : public ScriptedAI
	{
		npc_high_cpt_bartlettAI(Creature* creature) : ScriptedAI(creature) {}
        
		void Reset() OVERRIDE
		{
            me->setActive(true);
			TC_LOG_ERROR(LOG_FILTER_WORLDSERVER, "AI Reset creature: %u", me->GetGUID());
		}
        
    };
    
    CreatureAI* GetAI(Creature* creature) const
	{
		return new npc_high_cpt_bartlettAI(creature);
	}
    
};

class npc_skybreaker_deckhand : public CreatureScript
{
    
public:
	npc_skybreaker_deckhand() : CreatureScript("npc_skybreaker_deckhand" )  { }
    
	struct npc_skybreaker_deckhandAI : public ScriptedAI
	{
		npc_skybreaker_deckhandAI(Creature* creature) : ScriptedAI(creature) {}
        
		void Reset() OVERRIDE
		{
            me->setActive(true);
			TC_LOG_ERROR(LOG_FILTER_WORLDSERVER, "AI Reset creature: %u", me->GetGUID());
		}
        
    };
    
    CreatureAI* GetAI(Creature* creature) const
	{
		return new npc_skybreaker_deckhandAI(creature);
	}
    
};

class npc_korkron_axethrower_rifleman : public CreatureScript
{
public:
    npc_korkron_axethrower_rifleman() : CreatureScript("npc_korkron_axethrower_rifleman") { }
    
    struct npc_korkron_axethrower_riflemanAI : public ScriptedAI
    {
        npc_korkron_axethrower_riflemanAI(Creature *creature) : ScriptedAI(creature),_instance(creature->GetInstanceScript())
        {
            Reset();
        }
        
        void Reset()
        {
            ScriptedAI::Reset();
            DesperateResolve = RAID_MODE( SPELL_DESPERATE_RESOLVE_10_NM, SPELL_DESPERATE_RESOLVE_25_NM, SPELL_DESPERATE_RESOLVE_10_HM, SPELL_DESPERATE_RESOLVE_25_HM);
            desperated = false;
            me->RemoveAurasDueToSpell(SPELL_EXPERIENCED);
            me->RemoveAurasDueToSpell(SPELL_ELITE);
            me->RemoveAurasDueToSpell(SPELL_VETERAN);
            me->SetDisableGravity(true);
            events.ScheduleEvent(EVENT_EXPERIENCED, urand(19000, 21000)); // ~20 sec
            events.ScheduleEvent(EVENT_VETERAN, urand(39000, 41000)); // ~40 sec
            events.ScheduleEvent(EVENT_ELITE, urand(59000, 61000)); // ~60 sec
            attacktimer = urand(6000, 15000);
            if (me->GetEntry() == NPC_GB_SKYBREAKER_RIFLEMAN)
                SetEquipmentSlots(false, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE, 47267);
            else
                SetEquipmentSlots(false, 49691, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE);
        }
        
        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/)
        {
            if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE && me->GetHealthPct() < 20.0f && !desperated)
            {
                desperated = true;
                DoCast(me, DesperateResolve);
            }
        }
        
        void JustDied(Unit* killer)
        {
            if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
            {
                if (Creature* pSaurfangBoss = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_GB_HIGH_OVERLORD_SAURFANG)))
                    pSaurfangBoss->AI()->DoAction(ACTION_AXES_RIFL_DIE);
            }
            
            if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
            {
                if (Creature* pMuradin = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_GB_MURADIN_BRONZEBEARD)))
                    pMuradin->AI()->DoAction(ACTION_AXES_RIFL_DIE);
            }
        }
        
        void UpdateAI(uint32 diff)
        {
            if (_instance->GetBossState(DATA_GUNSHIP_EVENT) != IN_PROGRESS)
                return;
            
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
            
            //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE); // Dodato
            me->AI()->AttackStart(SelectRandomPlayerInTheMaps(me->GetMap()));
            
            if (!UpdateVictim())
                return;
            
            events.Update(diff);
            
            if (attacktimer <= diff)
            {
                if(me->GetEntry() == NPC_GB_KORKRON_AXETHROWER)
                    DoCast(me->GetVictim(), SPELL_HURL_AXE);
                else if(me->GetEntry() == NPC_GB_SKYBREAKER_RIFLEMAN)
                    DoCast(me->GetVictim(), SPELL_SHOOT);
                attacktimer = urand(6000, 15000);
            } else attacktimer -= diff;
            
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_EXPERIENCED:
                        DoCast(me, SPELL_EXPERIENCED);
                        break;
                    case EVENT_VETERAN:
                        me->RemoveAurasDueToSpell(SPELL_EXPERIENCED);
                        DoCast(me, SPELL_VETERAN);
                        break;
                    case EVENT_ELITE:
                        me->RemoveAurasDueToSpell(SPELL_VETERAN);
                        DoCast(me, SPELL_ELITE);
                        break;
                    default:
                        break;
                }
            }
        }
        
        uint32 DesperateResolve;
        uint32 attacktimer;
        
    private:
        EventMap events;
        bool desperated;
        InstanceScript* _instance;
    };
    
    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_korkron_axethrower_riflemanAI(pCreature);
    }
};



class npc_gunship_trigger : public CreatureScript
{
public:
    npc_gunship_trigger() : CreatureScript("npc_gunship_trigger") { }
    
    struct npc_gunship_triggerAI : public ScriptedAI
    {
        npc_gunship_triggerAI(Creature *creature) : ScriptedAI(creature),_instance(creature->GetInstanceScript())
        {
            
            Reset();
        }
        
        void Reset()
        {
            ScriptedAI::Reset();
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
        }
        
        void EnterCombat(Unit* /*who*/)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            SetCombatMovement(false);
        }
        
        void DamageTaken(Unit* attacker, uint32& damage)
        {
            damage = 0;
        }
        
        void UpdateAI(uint32 diff)
        {
            
        }
        
    private:
        EventMap events;
        InstanceScript* _instance;
    };
    
    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_gunship_triggerAI(pCreature);
    }
};


/*class spell_rocket_pack : public SpellScriptLoader
{
public:
    spell_rocket_pack() : SpellScriptLoader("spell_rocket_pack") { }
    
    class spell_rocket_packSpellScript : public SpellScript
    {
        // initialize script, this macro does compile time check for type of the function - prevents possible issues
        // if you have assigned wrong type of function to a hook you'll receive type conversion error during build
        // this line is required, otherwise you'll get XXXHandlerFunction - identifier not found errors
        PrepareSpellScript(spell_rocket_packSpellScript);
                
        void HandleBeforeCast()
        {
            // this hook is executed before anything about casting the spell is done
            // after this hook is executed all the machinery starts
            TC_LOG_INFO(LOG_FILTER_GENERAL, "Caster just finished preparing the spell (cast bar has expired)");
        }
        
        void HandleOnCast()
        {
            // cast is validated and spell targets are selected at this moment
            // this is a last place when the spell can be safely interrupted
            TC_LOG_INFO(LOG_FILTER_GENERAL, "Spell is about to do take reagents, power, launch missile, do visuals and instant spell effects");
            //Transport* gunshipAlliance = GetCaster()->GetTransport();
            //gunshipAlliance->UpdatePosition(GetCaster()->GetPositionX(), GetCaster()->GetPositionY(), GetCaster()->GetPositionZ(), GetCaster()->GetOrientation());
        }
        
        // register functions used in spell script - names of these functions do not matter
        void Register() OVERRIDE
        {
            // we're registering our functions here
            BeforeCast += SpellCastFn(spell_rocket_packSpellScript::HandleBeforeCast);
            OnCast += SpellCastFn(spell_rocket_packSpellScript::HandleOnCast);
           
        }
    };
    
    // function which creates SpellScript
    SpellScript* GetSpellScript() const OVERRIDE
    {
        return new spell_rocket_packSpellScript();
    }
};*/

void AddSC_icc_gunship_battle()
{
    new GunshipStairs();
    new Gunship();
    
    new npc_muradin_gunship();
    new npc_gunship_cannon();
    new npc_zafod_boombox();
    new npc_high_cpt_bartlett();
    new npc_skybreaker_deckhand();
    new npc_gunship_trigger();
    new npc_saurfang_gunship();
    new npc_korkron_axethrower_rifleman();
    //new spell_rocket_packSpellScript();
}
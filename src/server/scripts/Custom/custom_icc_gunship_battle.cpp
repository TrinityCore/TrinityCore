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
	SPELL_ALLIANCE = 70120,
	SPELL_HORDE = 70121
};

enum Transports
{
	TRANSPORT_SKYBREAKER = 21,
	TRANSPORT_ORGRIM = 22
};

enum Events
{
	EVENT_START_FLIGHT,
    EVENT_DUMMY
};

enum Actions
{
    ACTION_START_FLIGHT             = 1,
    ACTION_DUMMY             = 1
};


void InitTransport(Transport* t)
{
    
	t->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_TRANSPORT);
	t->SetGoState(GO_STATE_ACTIVE);
	//t->SetUInt32Value(GAMEOBJECT_DYNAMIC, 0x10830010);
	//t->SetFloatValue(GAMEOBJECT_PARENTROTATION + 3, 1.0f);
    
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
    
    //Doesn't seem to work... AreaTrigger time!
    /*void OnRelocate(Transport* transport, uint32 waypointId, uint32 mapId, float x, float y, float z)
    {
        transport->UpdatePosition(x, y, z, transport->GetOrientation());
    }*/
    
	void OnAddPassenger(Transport* transport, Player* player)
	{
		if(!transport || !player)
			return;
        
		switch(transport->GetEntry())
		{
            case GO_ALLIANCE_GUNSHIP:
                player->AddAura(SPELL_ALLIANCE, player);
                player->Say("Boarded Alliance ship!", LANG_UNIVERSAL);
                
                //This works as well
                transport->UpdatePosition(player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetOrientation());
                TC_LOG_ERROR(LOG_FILTER_TRANSPORTS, "====== GUNSHIP AURA ADDED! ======");
                break;
                
            case GO_ALLIANCE_GUNSHIP_ENEMY:
                player->AddAura(SPELL_ALLIANCE, player);
                player->Say("Boarded enemy ship!", LANG_UNIVERSAL);
                
                //This works as well
                transport->UpdatePosition(player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetOrientation());
                TC_LOG_ERROR(LOG_FILTER_TRANSPORTS, "====== GUNSHIP AURA ADDED! ======");
                break;
                
            case GO_HORDE_GUNSHIP:
                player->AddAura(SPELL_HORDE, player);
                break;
                
            default:
                break;
		}
	}
};

class npc_muradin_gunship : public CreatureScript
{
public:
	npc_muradin_gunship() : CreatureScript("npc_muradin_gunship" )  { }
    
	bool OnGossipHello(Player* plr, Creature* npc)
	{
		plr->PlayerTalkClass->GetGossipMenu().AddMenuItem(0, GOSSIP_ICON_CHAT, MURADIN_BUTTON_TEXT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1,"", 0);
		plr->PlayerTalkClass->SendGossipMenu(TEXT_MURADIN_MENU_TEXT, npc->GetGUID());
        
        //Fixes spells and attacks
        Transport* gunshipAlliance = plr->GetTransport();
        gunshipAlliance->UpdatePosition(plr->GetPositionX(), plr->GetPositionY(), plr->GetPositionZ(), plr->GetOrientation());
        
        /*Map* map = plr->GetMap();
         for (Map::PlayerList::const_iterator itr = map->GetPlayers().begin(); itr != map->GetPlayers().end(); ++itr)
         map->SendInitTransports(plr);*/
		return true;
	}
    
	bool OnGossipSelect(Player* plr, Creature* npc, uint32 sender, uint32 action)
	{
        plr->PlayerTalkClass->ClearMenus();
        
        if (action == GOSSIP_ACTION_INFO_DEF + 2)
            npc->MonsterSay("I'll wait for the raid leader", LANG_UNIVERSAL, plr->GetGUID());
        
        if (action == GOSSIP_ACTION_INFO_DEF + 1)
            plr->PlayerTalkClass->SendCloseGossip();
            npc->AI()->DoAction(ACTION_START_FLIGHT);
        
		return true;
	}
    
	struct npc_muradin_gunshipAI : public ScriptedAI
	{
		npc_muradin_gunshipAI(Creature* creature) : ScriptedAI(creature)
		{
            instance = creature->GetInstanceScript();
		}
        
		void Reset() OVERRIDE
		{
            if (instance->GetBossState(DATA_GUNSHIP_EVENT) == IN_PROGRESS)
                return;
			me->SetReactState(REACT_PASSIVE);
			me->setFaction(1802);
			me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            me->setActive(true);
            events.Reset();
            EventScheduled = false;
            
            Map* map = me->GetMap();
            for (Map::PlayerList::const_iterator itr = map->GetPlayers().begin(); itr != map->GetPlayers().end(); ++itr)
                map->SendInitTransports(plr = itr->GetSource());
            
			TC_LOG_ERROR(LOG_FILTER_WORLDSERVER, "AI Reset creature: %u", me->GetGUID());
		}
        
        
        // Timers are broken... i think.
        void DoAction(int32 action) OVERRIDE
        {
            switch (action)
            {
                case ACTION_START_FLIGHT:
                    me->MonsterSay("ACTION_START_FLIGHT!",LANG_UNIVERSAL, 0);
                    Map* map = plr->GetMap();
                    Transport* gunshipAlliance = plr->GetTransport();
                    uint64 guid = plr->GetInstanceScript()->GetData64(DATA_ENEMY_SHIP);
                    Transport* gunshipAllianceEnemy = NULL;
                    
                    if(guid)
                    {
                        gunshipAllianceEnemy = map->GetGameObject(guid)->ToTransport();
                        plr->Say("custom_icc_gunship_battle: guid is set ", LANG_UNIVERSAL);
                        
                        TC_LOG_ERROR(LOG_FILTER_TRANSPORTS, "custom_icc_gunship_battle: guid gunshipAllianceEnemy = %u", guid);
                    }else{
                        TC_LOG_ERROR(LOG_FILTER_TRANSPORTS, "custom_icc_gunship_battle: guid gunshipAllianceEnemy not set");
                        delete gunshipAllianceEnemy;
                    }
                    
                    if(gunshipAlliance)
                    {
                        plr->Say("custom_icc_gunship_battle: spawned gunshipAlliance", LANG_UNIVERSAL);
                        TC_LOG_ERROR(LOG_FILTER_TRANSPORTS, "custom_icc_gunship_battle: gunshipAlliance = spawned", guid);
                        
                        //Fixes spells and attacks
                        //gunshipAlliance->UpdatePosition(plr->GetPositionX(), plr->GetPositionY(), plr->GetPositionZ(), plr->GetOrientation());
                        InitTransport(gunshipAlliance);
                    }else{
                        delete gunshipAlliance;
                    }
                    
                    if(gunshipAllianceEnemy)
                    {
                        plr->Say("custiom_icc_gunship_battle: spawned gunshipAllianceEnemy", LANG_UNIVERSAL);
                        TC_LOG_ERROR(LOG_FILTER_TRANSPORTS, "custom_icc_gunship_battle: gunshipAllianceEnemy = spawned", guid);
                        InitTransport(gunshipAllianceEnemy);
                    }else{
                        delete gunshipAllianceEnemy;
                    }
                    events.ScheduleEvent(EVENT_START_FLIGHT, 5000);
                    break;
            }
        }
        
        
        //Further testing sugests this is the problem.
        void UpdateAI(uint32 uDiff) OVERRIDE
        {
            
            events.Update(uDiff);
            
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_START_FLIGHT:
                        me->MonsterSay("EVENT_START_FLIGHT",LANG_UNIVERSAL, 0);
                        Transport* skybreaker = me->GetTransport();
                        InitTransport(skybreaker);
                        break;
                }
            }
            
            DoMeleeAttackIfReady();
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
		return new npc_muradin_gunshipAI(creature);
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

class npc_gunship_trigger : public CreatureScript //gunship hull
{
    
public:
	npc_gunship_trigger() : CreatureScript("npc_gunship_trigger" )  { }
    
	struct npc_gunship_triggerAI : public ScriptedAI
	{
		npc_gunship_triggerAI(Creature* creature) : ScriptedAI(creature) {}
        
		void Reset() OVERRIDE
		{
            me->setActive(true);
			TC_LOG_ERROR(LOG_FILTER_WORLDSERVER, "AI Reset creature: %u", me->GetGUID());
		}
        
    };
    
    CreatureAI* GetAI(Creature* creature) const
	{
		return new npc_gunship_triggerAI(creature);
	}
    
};

class npc_saurfang_gunship: public CreatureScript //gunship hull
{
    
public:
	npc_saurfang_gunship() : CreatureScript("npc_overlord_saurfang_gunship" )  { }
    
	struct npc_saurfang_gunshipAI : public ScriptedAI
	{
		npc_saurfang_gunshipAI(Creature* creature) : ScriptedAI(creature) {}
        
		void Reset() OVERRIDE
		{
            me->setActive(true);
			TC_LOG_ERROR(LOG_FILTER_WORLDSERVER, "AI Reset creature: %u", me->GetGUID());
		}
        
    };
    
    CreatureAI* GetAI(Creature* creature) const
	{
		return new npc_saurfang_gunshipAI(creature);
	}
    
};

class spell_rocket_pack : public SpellScriptLoader
{
public:
    spell_rocket_pack() : SpellScriptLoader("spell_rocket_pack") { }
    
    class spell_rocket_pack_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rocket_pack_AuraScript);
        
        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            GetTarget()->CastSpell(GetTarget(), 68721, true);
        }
        
        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            GetTarget()->RemoveAurasDueToSpell(68721);
        }
        
        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(spell_rocket_pack_AuraScript::OnApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_rocket_pack_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };
    
    AuraScript* GetAuraScript() const
    {
        return new spell_rocket_pack_AuraScript();
    }
};

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
    new spell_rocket_pack();
}
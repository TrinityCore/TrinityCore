#include "Configuration/Config.h"
#include "Player.h"
#include "Creature.h"
#include "AccountMgr.h"
#include "ScriptedAI/ScriptedCreature.h"
#include "ScriptMgr.h"
#include "Define.h"
#include "GossipDef.h"
#include "Pet.h"
#include "Item.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "DatabaseEnv.h"
#include "World.h"
#include "WorldSession.h"
#include "Chat.h"
#include "Log.h"
#include "Creature.h"
#include "GameObject.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "TemporarySummon.h"
#include "LootMgr.h"
#include "Containers.h"
#include "DB2Stores.h"
#include "ItemTemplate.h"


uint32 SUMMON_CHEST;
uint32 KillAnnounce;
bool spawnchestIP;
uint32 chest_despawn;
std::vector<uint32> AreatoIgnore = { 1741/*Gurubashi*/, 2177 };

class PvPScript : public PlayerScript
{
public:
    PvPScript() : PlayerScript("PvPScript") {}

    void OnPlayerKilledByCreature(Creature* killer, Player* killed)
    {
        if (!sConfigMgr->GetBoolDefault("PvPChest", true))
            return;

        if (!killer->IsPet())
            return;


        std::string name = killer->GetOwner()->GetName();

        //if killer has same IP as death player do not drop loot as its cheating!
        if (spawnchestIP)
            if (Pet* pet = killer->ToPet())
                if (Player* owner = pet->GetOwner())
                {
                    if (owner->GetSession()->GetRemoteAddress() == killed->GetSession()->GetRemoteAddress())
                        return;

                    // Dont drop loot if killed is not worth honor for owner
                    if (!owner->isHonorOrXPTarget(killed))
                        return;
                }

        // if player has Ress sickness do not spawn chest
        if (killed->HasAura(15007))
            return;

        //Gurubashi Arena
        if (killed->GetMapId() == 0 && killed->GetZoneId() == 33)
            for (int i = 0; i < AreatoIgnore.size(); ++i)
                if (killed->GetAreaId() == AreatoIgnore[i])
                    return;


        // Dont drop chess if player is in battleground
        if (killed->GetMap()->IsBattlegroundOrArena())
            return;

        //Dont Drop chest if player is no worth XP
        if (!killed->isHonorOrXPTarget(killer->GetOwner()))
            return;

        // if target is killed and killer is pet
        if (!killed->IsAlive() && killer->IsPet())
        {
            //if (GameObject* go = killer->SummonGameObject(SUMMON_CHEST, killed->GetPositionX(), killed->GetPositionY(), killed->GetPositionZ(), killed->GetOrientation(), QuaternionData(0.0f, 0.0f, 0.0f, 0.0f), chest_despawn, false))
            if (GameObject* go = killer->SummonGameObject(SUMMON_CHEST, killed->GetPositionX(), killed->GetPositionY(), killed->GetPositionZ(), killed->GetOrientation(), QuaternionData(0.0f, 0.0f, 0.0f, 0.0f),Seconds(chest_despawn),GO_SUMMON_TIMED_OR_CORPSE_DESPAWN))
            {
                switch (KillAnnounce)
                {
                case 1: //Announce in chat handler
                    ChatHandler(killed->GetSession()).PSendSysMessage("You have been killed by player [%s] ", name.c_str());
                    break;
                case 2: //Announce in notifaction
                    killed->GetSession()->SendNotification("You have been slain by [%s]", name.c_str());
                    break;
                case 3: // Announe in Notifaction and chathandler
                    killed->GetSession()->SendNotification("You have been slain by [%s]", name.c_str());
                    ChatHandler(killed->GetSession()).PSendSysMessage("You have been killed by player [%s] ", name.c_str());
                    break;
                }

                killer->AddGameObject(go);
                go->SetOwnerGUID(ObjectGuid::Empty); //This is so killed players can also loot the chest

                for (int i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
                    if (Item* pItem = killed->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                    {
                        uint8 slot = pItem->GetSlot();
                        //LootStoreItem storeItem = LootStoreItem(pItem->GetEntry(), 100, LOOT_MODE_DEFAULT, 0, 1, 1, 0, 0, 0);
                        LootStoreItem storeItem = LootStoreItem(pItem->GetEntry(), 100, LOOT_MODE_DEFAULT, 0, 1, 1, 0, 0);
                        //go->loot.AddItem(storeItem);
                        killed->DestroyItem(INVENTORY_SLOT_BAG_0, slot, true);
                    }
            }
        }
    }

    void OnPVPKill(Player* killer, Player* killed)
    {
        if (!sConfigMgr->GetBoolDefault("PvPChest", true))
            return;

        std::string name = killer->GetName();

        //if killer has same IP as death player do not drop loot as its cheating!
        if (spawnchestIP)
            if (killer->GetSession()->GetRemoteAddress() == killed->GetSession()->GetRemoteAddress())
                return;

        // if player has Ress sickness do not spawn chest
        if (killed->HasAura(15007))
            return;

        // If player kills self do not drop loot
        if (killer->GetGUID() == killed->GetGUID())
            return;

        //Gurubashi Arena
        if (killed->GetMapId() == 0 && killed->GetZoneId() == 33)
            for (int i = 0; i < AreatoIgnore.size(); ++i)
                if (killed->GetAreaId() == AreatoIgnore[i])
                    return;

        // if killer not worth honnor do not drop loot
        if (!killer->isHonorOrXPTarget(killed))
            return;

        // Dont drop chess if player is in battleground
        if (killed->GetMap()->IsBattlegroundOrArena())
            return;

        if (!killed->IsAlive())
        {
            //if (GameObject* go = killer->SummonGameObject(SUMMON_CHEST, killed->GetPositionX(), killed->GetPositionY(), killed->GetPositionZ(), killed->GetOrientation(), QuaternionData(0.0f, 0.0f, 0.0f, 0.0f), chest_despawn, false))
            if (GameObject* go = killer->SummonGameObject(SUMMON_CHEST, killed->GetPositionX(), killed->GetPositionY(), killed->GetPositionZ(), killed->GetOrientation(), QuaternionData(0.0f, 0.0f, 0.0f, 0.0f), Seconds(chest_despawn),GO_SUMMON_TIMED_OR_CORPSE_DESPAWN))
            {
                switch (KillAnnounce)
                {
                case 1: //Announce in chat handler
                    ChatHandler(killed->GetSession()).PSendSysMessage("You have been killed by player [%s] ", name.c_str());
                    break;
                case 2: //Announce in notifaction
                    killed->GetSession()->SendNotification("You have been slain by [%s]", name.c_str());
                    break;
                case 3: // Announe in Notifaction and chathandler
                    killed->GetSession()->SendNotification("You have been slain by [%s]", name.c_str());
                    ChatHandler(killed->GetSession()).PSendSysMessage("You have been killed by player [%s] ", name.c_str());
                    break;
                }

                killer->AddGameObject(go);
                go->SetOwnerGUID(ObjectGuid::Empty); //This is so killed players can also loot the chest

                for (int i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
                    if (Item* pItem = killed->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                    {
                        uint8 slot = pItem->GetSlot();
                        //LootStoreItem storeItem = LootStoreItem(pItem->GetEntry(), 100, LOOT_MODE_DEFAULT, 0, 1, 1, 0, 0, 0);
                        LootStoreItem storeItem = LootStoreItem(pItem->GetEntry(), 100, LOOT_MODE_DEFAULT, 0, 1, 1, 0, 0);
                        //go->loot.AddItem(storeItem);
                        killed->DestroyItem(INVENTORY_SLOT_BAG_0, slot, true);
                    }
            }
        }
    }
};

void AddSC_PvPScripts()
{
    new PvPScript();
}

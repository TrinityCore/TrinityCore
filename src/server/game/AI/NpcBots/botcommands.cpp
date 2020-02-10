#include "bot_ai.h"
#include "botmgr.h"
#include "botdatamgr.h"
#include "Chat.h"
#include "CharacterCache.h"
#include "Language.h"
#include "Group.h"
#include "Map.h"
#include "MapManager.h"
#include "Player.h"
#include "RBAC.h"
#include "ScriptMgr.h"
/*
Name: script_bot_commands
%Complete: ???
Comment: Npc Bot related commands by Trickerer (onlysuffering@gmail.com)
Category: commandscripts/custom/
*/
//RBAC_PERM_GM_COMMANDS = 197
//RBAC_PERM_PLAYER_COMMANDS = 199
#define GM_COMMANDS rbac::RBACPermissions(197)
#define PLAYER_COMMANDS rbac::RBACPermissions(199)

class script_bot_commands : public CommandScript
{
private:
    struct BotInfo
    {
        public:
            BotInfo(uint32 Id, std::string Name, uint8 Race) : id(Id), name(Name), race(Race) {}
            uint32 id;
            std::string name;
            uint8 race;
        private:
            BotInfo() {}
            //BotInfo(BotInfo const&);
    };
    static bool sortbots(BotInfo const& p1, BotInfo const& p2)
    {
        return p1.id < p2.id;
    }

public:
    script_bot_commands() : CommandScript("script_bot_commands") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        //static std::vector<ChatCommand> npcbotToggleCommandTable =
        //{
        //    { "flags",      GM_COMMANDS,            false, &HandleNpcBotToggleFlagsCommand,         "" },
        //};

        static std::vector<ChatCommand> npcbotDebugCommandTable =
        {
            { "raid",       GM_COMMANDS,            false, &HandleNpcBotDebugRaidCommand,           "" },
            { "mount",      GM_COMMANDS,            false, &HandleNpcBotDebugMountCommand,          "" },
            { "spellvisual",GM_COMMANDS,            false, &HandleNpcBotDebugSpellVisualCommand,    "" },
            { "states",     GM_COMMANDS,            false, &HandleNpcBotDebugStatesCommand,         "" },
        };

        static std::vector<ChatCommand> npcbotSetCommandTable =
        {
            { "faction",    GM_COMMANDS,            false, &HandleNpcBotSetFactionCommand,          "" },
            { "owner",      GM_COMMANDS,            false, &HandleNpcBotSetOwnerCommand,            "" },
        };

        static std::vector<ChatCommand> npcbotCommandTable =
        {
            //{ "debug",      GM_COMMANDS,            false, nullptr,             "", npcbotDebugCommandTable },
            //{ "toggle",     GM_COMMANDS,            false, nullptr,             "", npcbotToggleCommandTable },
            { "set",        GM_COMMANDS,            false, nullptr,              "", npcbotSetCommandTable },
            { "add",        GM_COMMANDS,            false, &HandleNpcBotAddCommand,                 "" },
            { "remove",     GM_COMMANDS,            false, &HandleNpcBotRemoveCommand,              "" },
            { "spawn",      GM_COMMANDS,            false, &HandleNpcBotSpawnCommand,               "" },
            { "delete",     GM_COMMANDS,            false, &HandleNpcBotDeleteCommand,              "" },
            { "lookup",     GM_COMMANDS,            false, &HandleNpcBotLookupCommand,              "" },
            { "revive",     GM_COMMANDS,            false, &HandleNpcBotReviveCommand,              "" },
            { "reloadconfig",GM_COMMANDS,           true,  &HandleNpcBotReloadConfigCommand,        "" },
            { "command",    PLAYER_COMMANDS,        false, &HandleNpcBotCommandCommand,             "" },
            { "info",       PLAYER_COMMANDS,        false, &HandleNpcBotInfoCommand,                "" },
            { "hide",       PLAYER_COMMANDS,        false, &HandleNpcBotHideCommand,                "" },
            { "unhide",     PLAYER_COMMANDS,        false, &HandleNpcBotUnhideCommand,              "" },
            { "show",       PLAYER_COMMANDS,        false, &HandleNpcBotUnhideCommand,              "" },
            { "recall",     PLAYER_COMMANDS,        false, &HandleNpcBotRecallCommand,              "" },
            { "kill",       PLAYER_COMMANDS,        false, &HandleNpcBotKillCommand,                "" },
            { "suicide",    PLAYER_COMMANDS,        false, &HandleNpcBotKillCommand,                "" },
        };

        static std::vector<ChatCommand> commandTable =
        {
            { "npcbot",     PLAYER_COMMANDS,        false, nullptr,                   "", npcbotCommandTable },
        };
        return commandTable;
    }

    static bool HandleNpcBotDebugStatesCommand(ChatHandler* handler, const char* /*args*/)
    {
        Unit* target = handler->getSelectedUnit();
        if (!target)
        {
            handler->SendSysMessage("No target selected");
            return true;
        }

        uint8 const MAX_UNIT_STATES = 29;
        std::ostringstream ostr;
        ostr << "Listing states for " << target->GetName() << ":";
        for (uint8 i = 0; i != MAX_UNIT_STATES; ++i)
        {
            if (target->HasUnitState(1 << i))
                ostr << "\n    0x" << std::hex << (1 << i);
        }

        handler->SendSysMessage(ostr.str().c_str());
        return true;
    }

    static bool HandleNpcBotDebugRaidCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* owner = handler->GetSession()->GetPlayer();
        Group const* gr = owner->GetGroup();
        if (!owner->HaveBot() || !gr)
        {
            handler->SendSysMessage(".npcbot debug raid");
            handler->SendSysMessage("prints your raid bots info");
            return true;
        }
        if (!gr->isRaidGroup())
        {
            handler->SendSysMessage("only usable in raid");
            return true;
        }

        uint8 counter = 0;
        uint8* subBots = new uint8[MAX_RAID_SUBGROUPS];
        memset((void*)subBots, 0, (MAX_RAID_SUBGROUPS)*sizeof(uint8));
        std::ostringstream sstr;
        BotMap const* map = owner->GetBotMgr()->GetBotMap();
        for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
        {
            Creature* bot = itr->second;
            if (!bot || !gr->IsMember(itr->second->GetGUID()))
                continue;

            uint8 subGroup = gr->GetMemberGroup(itr->second->GetGUID());
            ++subBots[subGroup];
            sstr << uint32(++counter) << ": " << bot->GetGUID().GetCounter() << " " << bot->GetName()
                << " subgr: " << uint32(subGroup + 1) << "\n";
        }

        for (uint8 i = 0; i != MAX_RAID_SUBGROUPS; ++i)
            if (subBots[i] > 0)
                sstr << uint32(subBots[i]) << " bots in subgroup " << uint32(i + 1) << "\n";

        handler->SendSysMessage(sstr.str().c_str());
        delete[] subBots;
        return true;
    }

    static bool HandleNpcBotDebugMountCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        float speed = 1.f;
        uint32 num = 0;

        num = atoi((char*)args);
        if (!num)
            return false;

        Unit* target = handler->getSelectedUnit();
        if (!target)
        {
            handler->SendSysMessage("No target selected");
            return true;
        }

        target->Mount(num);
        return true;
    }

    static bool HandleNpcBotDebugSpellVisualCommand(ChatHandler* handler, const char* args)
    {
        Player* owner = handler->GetSession()->GetPlayer();
        Unit* target = owner->GetSelectedUnit();
        if (!target)
        {
            handler->SendSysMessage("No target selected");
            return true;
        }

        const std::string intStr = args;
        uint32 kit = (uint32)atoi((char*)args);

        target->SendPlaySpellVisual(kit);
        return true;
    }

    static bool HandleNpcBotHideCommand(ChatHandler* handler, const char* /*args*/)
    {
        // Hiding/unhiding bots should be allowed only out of combat
        // Currenly bots can teleport to master in combat
        // This creates potential for some serious trolls
        Player* owner = handler->GetSession()->GetPlayer();
        if (!owner->HaveBot())
        {
            handler->SendSysMessage(".npcbot hide");
            handler->SendSysMessage("Removes your owned npcbots from world temporarily");
            //handler->SendSysMessage("You have no bots!");
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (!owner->IsAlive())
        {
            handler->GetSession()->SendNotification("You are dead");
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (owner->GetBotMgr()->IsPartyInCombat())
        {
            handler->GetSession()->SendNotification(LANG_YOU_IN_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }

        owner->GetBotMgr()->SetBotsHidden(true);
        handler->SendSysMessage("Bots hidden");
        return true;
    }

    static bool HandleNpcBotUnhideCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* owner = handler->GetSession()->GetPlayer();
        if (!owner->HaveBot())
        {
            handler->SendSysMessage(".npcbot unhide | show");
            handler->SendSysMessage("Returns your temporarily hidden bots back");
            //handler->SendSysMessage("You have no bots!");
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (!owner->IsAlive())
        {
            handler->GetSession()->SendNotification("You are dead");
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (owner->GetBotMgr()->IsPartyInCombat())
        {
            handler->GetSession()->SendNotification(LANG_YOU_IN_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }

        owner->GetBotMgr()->SetBotsHidden(false);
        handler->SendSysMessage("Bots unhidden");
        return true;
    }

    static bool HandleNpcBotKillCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* owner = handler->GetSession()->GetPlayer();

        ObjectGuid guid = owner->GetTarget();
        if (!guid || !owner->HaveBot())
        {
            handler->SendSysMessage(".npcbot recall");
            handler->SendSysMessage("Makes your npcbot just drop dead. If you select yourself ALL your bots will die");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (guid == owner->GetGUID())
        {
            owner->GetBotMgr()->KillAllBots();
            return true;
        }
        if (Creature* bot = owner->GetBotMgr()->GetBot(guid))
        {
            owner->GetBotMgr()->KillBot(bot);
            return true;
        }

        handler->SendSysMessage("You must select one of your bots or yourself");
        handler->SetSentErrorMessage(true);
        return false;
    }

    static bool HandleNpcBotRecallCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* owner = handler->GetSession()->GetPlayer();

        ObjectGuid guid = owner->GetTarget();
        if (!guid || !owner->HaveBot())
        {
            handler->SendSysMessage(".npcbot recall");
            handler->SendSysMessage("Forces npcbots to move directly on your position. Select a npcbot you want to move or select yourself to move all bots");
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (owner->GetBotMgr()->IsPartyInCombat())
        {
            handler->GetSession()->SendNotification(LANG_YOU_IN_COMBAT);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (guid == owner->GetGUID())
        {
            owner->GetBotMgr()->RecallAllBots();
            return true;
        }
        if (Creature* bot = owner->GetBotMgr()->GetBot(guid))
        {
            owner->GetBotMgr()->RecallBot(bot);
            return true;
        }

        handler->SendSysMessage("You must select one of your bots or yourself");
        handler->SetSentErrorMessage(true);
        return false;
    }

    //static bool HandleNpcBotToggleFlagsCommand(ChatHandler* handler, const char* args)
    //{
    //    Player* chr = handler->GetSession()->GetPlayer();
    //    Unit* unit = chr->GetSelectedUnit();
    //    if (!unit || unit->GetTypeId() != TYPEID_UNIT || !*args)
    //    {
    //        handler->SendSysMessage(".npcbot toggle flags #flag");
    //        handler->SendSysMessage("This is a debug command");
    //        handler->SetSentErrorMessage(true);
    //        return false;
    //    }

    //    const std::string facStr = args;
    //    int32 flag = (int32)atoi((char*)args);

    //    uint32 setFlags = 0;

    //    switch (flag)
    //    {
    //        case 6:
    //            setFlags = UNIT_FLAG_UNK_6;
    //            break;
    //        case 14:
    //            setFlags = UNIT_FLAG_UNK_14;
    //            break;
    //        case 15:
    //            setFlags = UNIT_FLAG_UNK_15;
    //            break;
    //        case 16:
    //            setFlags = UNIT_FLAG_UNK_16;
    //            break;
    //        default:
    //            break;
    //    }

    //    if (!setFlags)
    //        return false;

    //    handler->PSendSysMessage("Toggling flag %u on %s", setFlags, unit->GetName().c_str());
    //    unit->ToggleFlag(UNIT_FIELD_FLAGS, setFlags);
    //    return true;
    //}

    static bool HandleNpcBotSetFactionCommand(ChatHandler* handler, const char* args)
    {
        Player* chr = handler->GetSession()->GetPlayer();
        Unit* ubot = chr->GetSelectedUnit();
        if (!ubot || !*args)
        {
            handler->SendSysMessage(".npcbot set faction #faction");
            handler->SendSysMessage("Sets faction for selected npcbot (saved in DB)");
            handler->SendSysMessage("Use 'a', 'h', 'm' or 'f' as argument to set faction to alliance, horde, monsters (hostile to all) or friends (friendly to all)");
            handler->SetSentErrorMessage(true);
            return false;
        }

        Creature* bot = ubot->ToCreature();
        if (!bot || !bot->IsNPCBot() || !bot->IsFreeBot())
        {
            handler->SendSysMessage("You must select uncontrolled npcbot");
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 factionId = 0;
        const std::string facStr = args;
        char const* factionChar = facStr.c_str();

        if (factionChar[0] == 'a')
            factionId = 1802; //Alliance
        else if (factionChar[0] == 'h')
            factionId = 1801; //Horde
        else if (factionChar[0] == 'm')
            factionId = 14; //Monsters
        else if (factionChar[0] == 'f')
            factionId = 35; //Friendly to all

        if (!factionId)
        {
            char* pfactionid = handler->extractKeyFromLink((char*)args, "Hfaction");
            factionId = atoi(pfactionid);
        }

        if (!sFactionTemplateStore.LookupEntry(factionId))
        {
            handler->PSendSysMessage(LANG_WRONG_FACTION, factionId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        BotDataMgr::UpdateNpcBotData(bot->GetEntry(), NPCBOT_UPDATE_FACTION, &factionId);
        bot->GetBotAI()->ReInitFaction();

        handler->PSendSysMessage("%s's faction set to %u", bot->GetName().c_str(), factionId);
        return true;
    }

    static bool HandleNpcBotSetOwnerCommand(ChatHandler* handler, const char* args)
    {
        Player* chr = handler->GetSession()->GetPlayer();
        Unit* ubot = chr->GetSelectedUnit();
        if (!ubot || !*args)
        {
            handler->SendSysMessage(".npcbot set owner #guid | #name");
            handler->SendSysMessage("Binds selected npcbot to new player owner using guid or name and updates owner in DB");
            handler->SetSentErrorMessage(true);
            return false;
        }

        Creature* bot = ubot->ToCreature();
        if (!bot || !bot->IsNPCBot())
        {
            handler->SendSysMessage("You must select a npcbot");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (bot->GetBotAI()->GetBotOwnerGuid())
        {
            handler->SendSysMessage("This npcbot already has owner");
            handler->SetSentErrorMessage(true);
            return false;
        }

        char* characterName_str = strtok((char*)args, " ");
        if (!characterName_str)
            return false;

        std::string characterName = characterName_str;
        uint32 guidlow = (uint32)atoi(characterName_str);

        bool found = true;
        if (guidlow)
            found = sCharacterCache->GetCharacterNameByGuid(ObjectGuid(HighGuid::Player, 0, guidlow), characterName);
        else
            guidlow = sCharacterCache->GetCharacterGuidByName(characterName);

        if (!guidlow || !found)
        {
            handler->SendSysMessage("Player not found");
            handler->SetSentErrorMessage(true);
            return false;
        }

        BotDataMgr::UpdateNpcBotData(bot->GetEntry(), NPCBOT_UPDATE_OWNER, &guidlow);
        bot->GetBotAI()->ReinitOwner();
        //bot->GetBotAI()->Reset();

        handler->PSendSysMessage("%s's new owner is %s (guidlow: %u)", bot->GetName().c_str(), characterName.c_str(), guidlow);
        return true;
    }

    static bool HandleNpcBotLookupCommand(ChatHandler* handler, const char* args)
    {
        //this is just a modified '.lookup creature' command
        if (!*args)
        {
            handler->SendSysMessage(".npcbot lookup #class");
            handler->SendSysMessage("Looks up npcbots by #class, and returns all matches with their creature ID's");
            handler->PSendSysMessage("BOT_CLASS_WARRIOR = %u", uint32(BOT_CLASS_WARRIOR));
            handler->PSendSysMessage("BOT_CLASS_PALADIN = %u", uint32(BOT_CLASS_PALADIN));
            handler->PSendSysMessage("BOT_CLASS_HUNTER = %u", uint32(BOT_CLASS_HUNTER));
            handler->PSendSysMessage("BOT_CLASS_ROGUE = %u", uint32(BOT_CLASS_ROGUE));
            handler->PSendSysMessage("BOT_CLASS_PRIEST = %u", uint32(BOT_CLASS_PRIEST));
            handler->PSendSysMessage("BOT_CLASS_DEATH_KNIGHT = %u", uint32(BOT_CLASS_DEATH_KNIGHT));
            handler->PSendSysMessage("BOT_CLASS_SHAMAN = %u", uint32(BOT_CLASS_SHAMAN));
            handler->PSendSysMessage("BOT_CLASS_MAGE = %u", uint32(BOT_CLASS_MAGE));
            handler->PSendSysMessage("BOT_CLASS_WARLOCK = %u", uint32(BOT_CLASS_WARLOCK));
            handler->PSendSysMessage("BOT_CLASS_DRUID = %u", uint32(BOT_CLASS_DRUID));
            handler->PSendSysMessage("BOT_CLASS_BLADEMASTER = %u", uint32(BOT_CLASS_BM));
            handler->PSendSysMessage("BOT_CLASS_SPHYNX = %u", uint32(BOT_CLASS_SPHYNX));
            handler->PSendSysMessage("BOT_CLASS_ARCHMAGE = %u", uint32(BOT_CLASS_ARCHMAGE));
            handler->PSendSysMessage("BOT_CLASS_DREADLORD = %u", uint32(BOT_CLASS_DREADLORD));
            handler->PSendSysMessage("BOT_CLASS_SPELLBREAKER = %u", uint32(BOT_CLASS_SPELLBREAKER));
            handler->PSendSysMessage("BOT_CLASS_DARK_RANGER = %u", uint32(BOT_CLASS_DARK_RANGER));
            handler->SetSentErrorMessage(true);
            return false;
        }

        char* classstr = strtok((char*)args, " ");
        uint8 botclass = BOT_CLASS_NONE;

        if (classstr)
            botclass = (uint8)atoi(classstr);

        if (botclass == BOT_CLASS_NONE || botclass >= BOT_CLASS_END)
        {
            handler->PSendSysMessage("Unknown bot class %u", uint32(botclass));
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage("Looking for bots of class %u...", uint32(botclass));

        uint8 localeIndex = handler->GetSessionDbLocaleIndex();
        CreatureTemplateContainer const& ctc = sObjectMgr->GetCreatureTemplates();
        typedef std::list<BotInfo> BotList;
        BotList botlist;
        for (CreatureTemplateContainer::const_iterator itr = ctc.begin(); itr != ctc.end(); ++itr)
        {
            uint32 id = itr->second.Entry;
            if (id < BOT_ENTRY_BEGIN || id > BOT_ENTRY_END)
                continue;

            if (id == BOT_ENTRY_MIRROR_IMAGE_BM)
                continue;
            //Blademaster disabled
            if (botclass == BOT_CLASS_BM)
                continue;

            //TC_LOG_ERROR("entities.unit", "NpcBotLookup: cur %u", id);

            NpcBotExtras const* _botExtras = BotDataMgr::SelectNpcBotExtras(id);
            if (!_botExtras)
                continue;

            //TC_LOG_ERROR("entities.unit", "NpcBotLookup: found extras...");

            if (_botExtras->bclass != botclass)
                continue;

            //TC_LOG_ERROR("entities.unit", "NpcBotLookup: class matches...");

            uint8 race = _botExtras->race;

            if (CreatureLocale const* creatureLocale = sObjectMgr->GetCreatureLocale(id))
            {
                if (creatureLocale->Name.size() > localeIndex && !creatureLocale->Name[localeIndex].empty())
                {
                    botlist.push_back(BotInfo(id, creatureLocale->Name[localeIndex], race));
                    continue;
                }
            }

            std::string name = itr->second.Name;
            if (name.empty())
                continue;

            //TC_LOG_ERROR("entities.unit", "NpcBotLookup: ading to list");

            botlist.push_back(BotInfo(id, name, race));
        }

        if (botlist.empty())
        {
            handler->SendSysMessage(LANG_COMMAND_NOCREATUREFOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        botlist.sort(&script_bot_commands::sortbots);

        for (BotList::const_iterator itr = botlist.begin(); itr != botlist.end(); ++itr)
        {
            uint32 id = itr->id;
            char const* name = itr->name.c_str();
            uint8 race = itr->race;

            //TODO:
            if (race >= MAX_RACES)
                race = RACE_NONE;

            char const* raceName;
            switch (race)
            {
                case RACE_HUMAN:        raceName = "Human";     break;
                case RACE_ORC:          raceName = "Orc";       break;
                case RACE_DWARF:        raceName = "Dwarf";     break;
                case RACE_NIGHTELF:     raceName = "Night Elf"; break;
                case RACE_UNDEAD_PLAYER:raceName = "Forsaken";  break;
                case RACE_TAUREN:       raceName = "Tauren";    break;
                case RACE_GNOME:        raceName = "Gnome";     break;
                case RACE_TROLL:        raceName = "Troll";     break;
                case RACE_BLOODELF:     raceName = "Blood Elf"; break;
                case RACE_DRAENEI:      raceName = "Draenei";   break;
                case RACE_NONE:         raceName = "No Race";   break;
                default:                raceName = "Unknown";   break;
            }

            handler->PSendSysMessage("%d - |cffffffff|Hcreature_entry:%d|h[%s]|h|r %s", id, id, name, raceName);
        }

        return true;
    }

    static bool HandleNpcBotDeleteCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* chr = handler->GetSession()->GetPlayer();
        Unit* ubot = chr->GetSelectedUnit();
        if (!ubot)
        {
            handler->SendSysMessage(".npcbot delete");
            handler->SendSysMessage("Deletes selected npcbot spawn from world and DB");
            handler->SetSentErrorMessage(true);
            return false;
        }

        Creature* bot = ubot->ToCreature();
        if (!bot || !bot->IsNPCBot())
        {
            handler->SendSysMessage("No npcbot selected");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (Player const* botowner = bot->GetBotOwner()->ToPlayer())
            botowner->GetBotMgr()->RemoveBot(bot->GetGUID(), BOT_REMOVE_DISMISS);

        uint32 id = bot->GetEntry();

        NpcBotData const* npcBotData = BotDataMgr::SelectNpcBotData(id);
        ASSERT(npcBotData);

        bool found = false;
        for (uint8 i = BOT_SLOT_MAINHAND; i != BOT_INVENTORY_SIZE; ++i)
        {
            if (npcBotData->equips[i])
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            handler->PSendSysMessage("%s still has eqipment assigned. Please remove equips before deleting bot!", bot->GetName().c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        bot->GetBotAI()->canUpdate = false;
        bot->CombatStop();
        bot->GetBotAI()->Reset();
        Creature::DeleteFromDB(bot->GetSpawnId());
        bot->AddObjectToRemoveList();

        BotDataMgr::UpdateNpcBotData(id, NPCBOT_UPDATE_ERASE);

        handler->SendSysMessage("Npcbot successfully deleted");
        return true;
    }

    static bool HandleNpcBotSpawnCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
        {
            handler->SendSysMessage(".npcbot spawn");
            handler->SendSysMessage("Adds new npcbot spawn of given entry in world. You can shift-link the npc");
            handler->SendSysMessage("Syntax: .npcbot spawn #entry");
            handler->SetSentErrorMessage(true);
            return false;
        }

        char* charID = handler->extractKeyFromLink((char*)args, "Hcreature_entry");
        if (!charID)
            return false;

        uint32 id = atoi(charID);

        CreatureTemplate const* creInfo = sObjectMgr->GetCreatureTemplate(id);

        if (!creInfo)
        {
            handler->PSendSysMessage("creature %u does not exist!", id);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!(creInfo->flags_extra & CREATURE_FLAG_EXTRA_NPCBOT))
        {
            handler->PSendSysMessage("creature %u is not a npcbot!", id);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (BotDataMgr::SelectNpcBotData(id))
        {
            handler->PSendSysMessage("Npcbot %u already exists in `characters_npcbot` table!", id);
            handler->SendSysMessage("If you want to move this bot to a new location use '.npc move' command");
            handler->SetSentErrorMessage(true);
            return false;
        }

        PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_CREATURE_BY_ID);
        //"SELECT guid FROM creature WHERE id = ?", CONNECTION_SYNCH
        stmt->setUInt32(0, id);
        PreparedQueryResult res2 = WorldDatabase.Query(stmt);
        if (res2)
        {
            handler->PSendSysMessage("Npcbot %u already exists in `creature` table!", id);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* chr = handler->GetSession()->GetPlayer();

        if (Transport* trans = chr->GetTransport())
        {
            handler->SendSysMessage("Cannot spawn bots on transport!");
            handler->SetSentErrorMessage(true);
            return false;
        }

        //float x = chr->GetPositionX();
        //float y = chr->GetPositionY();
        //float z = chr->GetPositionZ();
        //float o = chr->GetOrientation();
        Map* map = chr->GetMap();

        if (map->Instanceable())
        {
            handler->SendSysMessage("Cannot spawn bots in instances!");
            handler->SetSentErrorMessage(true);
            return false;
        }

        Creature* creature = new Creature();
        if (!creature->Create(map->GenerateLowGuid<HighGuid::Unit>(), map, chr->GetPhaseMaskForSpawn(), id, *chr))
        {
            delete creature;
            handler->SendSysMessage("Creature is not created!");
            handler->SetSentErrorMessage(true);
            return false;
        }

        NpcBotExtras const* _botExtras = BotDataMgr::SelectNpcBotExtras(id);

        uint16 roleMask = BOT_ROLE_DPS;

        uint8 m_class = _botExtras ? _botExtras->bclass : CLASS_WARRIOR;
        if (!bot_ai::IsMeleeClass(m_class))
            roleMask |= BOT_ROLE_RANGED;
        if (bot_ai::IsHealingClass(m_class))
            roleMask |= BOT_ROLE_HEAL;

        BotDataMgr::AddNpcBotData(id, roleMask, creature->GetCreatureTemplate()->faction);

        creature->SaveToDB(map->GetId(), (1 << map->GetSpawnMode()), chr->GetPhaseMaskForSpawn());

        uint32 db_guid = creature->GetSpawnId();
        if (!creature->LoadBotCreatureFromDB(db_guid, map))
        {
            handler->SendSysMessage("Cannot load npcbot from DB!");
            handler->SetSentErrorMessage(true);
            //return false;
            delete creature;
            return false;
        }

        sObjectMgr->AddCreatureToGrid(db_guid, sObjectMgr->GetCreatureData(db_guid));

        handler->SendSysMessage("Npcbot successfully spawned");
        return true;
    }

    static bool HandleNpcBotInfoCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* owner = handler->GetSession()->GetPlayer();
        if (!owner->GetTarget())
        {
            handler->SendSysMessage(".npcbot info");
            handler->SendSysMessage("Lists NpcBots count of each class owned by selected player. You can use this on self and your party members");
            handler->SetSentErrorMessage(true);
            return false;
        }
        Player* master = owner->GetSelectedPlayer();
        if (!master)
        {
            handler->SendSysMessage("No player selected");
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (handler->HasLowerSecurity(master, ObjectGuid::Empty))
        {
            handler->SendSysMessage("Invalid target");
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (!master->HaveBot())
        {
            handler->PSendSysMessage("%s has no NpcBots!", master->GetName().c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage("Listing NpcBots for %s", master->GetName().c_str());
        handler->PSendSysMessage("Owned NpcBots: %u", master->GetNpcBotsCount());
        for (uint8 i = BOT_CLASS_WARRIOR; i != BOT_CLASS_END; ++i)
        {
            uint8 count = 0;
            uint8 alivecount = 0;
            BotMap const* map = master->GetBotMgr()->GetBotMap();
            for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
            {
                if (Creature* cre = itr->second)
                {
                    if (cre->GetBotClass() == i)
                    {
                        ++count;
                        if (cre->IsAlive())
                            ++alivecount;
                    }
                }
            }
            if (count == 0)
                continue;

            char const* bclass;
            switch (i)
            {
                case BOT_CLASS_WARRIOR:         bclass = "Warriors";        break;
                case BOT_CLASS_PALADIN:         bclass = "Paladins";        break;
                case BOT_CLASS_MAGE:            bclass = "Mages";           break;
                case BOT_CLASS_PRIEST:          bclass = "Priests";         break;
                case BOT_CLASS_WARLOCK:         bclass = "Warlocks";        break;
                case BOT_CLASS_DRUID:           bclass = "Druids";          break;
                case BOT_CLASS_DEATH_KNIGHT:    bclass = "Death Knights";   break;
                case BOT_CLASS_ROGUE:           bclass = "Rogues";          break;
                case BOT_CLASS_SHAMAN:          bclass = "Shamans";         break;
                case BOT_CLASS_HUNTER:          bclass = "Hunters";         break;
                case BOT_CLASS_BM:              bclass = "Blademasters";    break;
                case BOT_CLASS_SPHYNX:          bclass = "Destroyers";      break;
                case BOT_CLASS_ARCHMAGE:        bclass = "Archmagi";        break;
                case BOT_CLASS_DREADLORD:       bclass = "Dreadlords";      break;
                case BOT_CLASS_SPELLBREAKER:    bclass = "Spell Breakers";  break;
                case BOT_CLASS_DARK_RANGER:     bclass = "Dark Rangers";    break;
                default:                        bclass = "Unknown Class";   break;
            }
            handler->PSendSysMessage("%s: %u (alive: %u)", bclass, count, alivecount);
        }
        return true;
    }

    static bool HandleNpcBotCommandCommand(ChatHandler* handler, const char* args)
    {
        Player* owner = handler->GetSession()->GetPlayer();
        if (!*args)
        {
            handler->SendSysMessage(".npcbot command #[ stand | follow ]");
            handler->SendSysMessage("Forces npcbots to either follow you or hold position");
            handler->SetSentErrorMessage(true);
            return false;
        }
        char* command = strtok((char*)args, " ");
        int8 state = -1;
        if (!strncmp(command, "s", 2) || !strncmp(command, "st", 3) || !strncmp(command, "stay", 5) ||
            !strncmp(command, "stop", 5) || !strncmp(command, "stand", 6))
            state = COMMAND_STAY;
        else if (!strncmp(command, "f", 2) || !strncmp(command, "follow", 7) || !strncmp(command, "fol", 4) || !strncmp(command, "fo", 3))
            state = COMMAND_FOLLOW;
        if (state >= 0 && owner->HaveBot())
        {
            owner->GetBotMgr()->SendBotCommandState(CommandStates(state));
            std::ostringstream msg;
            msg << "Bot command state set to '";
            switch (state)
            {
                case 0:  msg << "STAY";    break;
                case 1:  msg << "FOLLOW";  break;
                default: msg << "unknown"; break;
            }
            msg << "'";
            handler->SendSysMessage(msg.str().c_str());
            return true;
        }
        handler->SetSentErrorMessage(true);
        return false;
    }

    static bool HandleNpcBotRemoveCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* owner = handler->GetSession()->GetPlayer();
        Unit* u = owner->GetSelectedUnit();
        if (!u)
        {
            handler->SendSysMessage(".npcbot remove");
            handler->SendSysMessage("Frees selected npcbot from it's owner. Select player to remove all npcbots");
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* master = u->ToPlayer();
        if (master)
        {
            if (master->HaveBot())
            {
                master->RemoveAllBots(BOT_REMOVE_DISMISS);

                if (!master->HaveBot())
                {
                    handler->SendSysMessage("Npcbots were successfully removed");
                    handler->SetSentErrorMessage(true);
                    return true;
                }
                handler->SendSysMessage("Some npcbots were not removed!");
                handler->SetSentErrorMessage(true);
                return false;
            }
            handler->SendSysMessage("Npcbots are not found!");
            handler->SetSentErrorMessage(true);
            return false;
        }

        Creature* cre = u->ToCreature();
        if (cre && cre->IsNPCBot() && !cre->IsFreeBot())
        {
            master = cre->GetBotOwner();
            master->GetBotMgr()->RemoveBot(cre->GetGUID(), BOT_REMOVE_DISMISS);
            if (master->GetBotMgr()->GetBot(cre->GetGUID()) == nullptr)
            {
                handler->SendSysMessage("NpcBot successfully removed");
                handler->SetSentErrorMessage(true);
                return true;
            }
            handler->SendSysMessage("NpcBot was NOT removed for some stupid reason!");
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->SendSysMessage("You must select player or controlled npcbot");
        handler->SetSentErrorMessage(true);
        return false;
    }

    static bool HandleNpcBotReviveCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* owner = handler->GetSession()->GetPlayer();
        Unit* u = owner->GetSelectedUnit();
        if (!u)
        {
            handler->SendSysMessage(".npcbot revive");
            handler->SendSysMessage("Revives selected npcbot. If player is selected, revives all selected player's npcbots");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (Player* master = u->ToPlayer())
        {
            if (!master->HaveBot())
            {
                handler->PSendSysMessage("%s has no npcbots!", master->GetName().c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }

            master->GetBotMgr()->ReviveAllBots();
            handler->SendSysMessage("Npcbots revived");
            return true;
        }
        else if (Creature* bot = u->ToCreature())
        {
            if (bot->GetBotAI())
            {
                if (bot->IsAlive())
                {
                    handler->PSendSysMessage("%s is not dead", bot->GetName().c_str());
                    handler->SetSentErrorMessage(true);
                    return false;
                }

                BotMgr::ReviveBot(bot);
                handler->PSendSysMessage("%s revived", bot->GetName().c_str());
                return true;
            }
        }

        handler->SendSysMessage("You must select player or npcbot");
        handler->SetSentErrorMessage(true);
        return false;
    }

    static bool HandleNpcBotAddCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* owner = handler->GetSession()->GetPlayer();
        Unit* cre = owner->GetSelectedUnit();

        if (!cre || cre->GetTypeId() != TYPEID_UNIT)
        {
            handler->SendSysMessage(".npcbot add");
            handler->SendSysMessage("Allows to hire selected uncontrolled bot");
            handler->SetSentErrorMessage(true);
            return false;
        }

        Creature* bot = cre->ToCreature();
        if (!bot || !bot->IsNPCBot() || bot->GetBotAI()->GetBotOwnerGuid())
        {
            handler->SendSysMessage("You must select uncontrolled npcbot");
            handler->SetSentErrorMessage(true);
            return false;
        }

        BotMgr* mgr = owner->GetBotMgr();
        if (!mgr)
            mgr = new BotMgr(owner);

        if (mgr->AddBot(bot, false) == BOT_ADD_SUCCESS)
        {
            handler->PSendSysMessage("%s is now your npcbot", bot->GetName().c_str());
            return true;
        }

        handler->SendSysMessage("NpcBot is NOT added for some reason!");
        handler->SetSentErrorMessage(true);
        return false;
    }

    static bool HandleNpcBotReloadConfigCommand(ChatHandler* handler, const char* /*args*/)
    {
        TC_LOG_INFO("misc", "Re-Loading config settings...");
        sWorld->LoadConfigSettings(true);
        sMapMgr->InitializeVisibilityDistanceInfo();
        handler->SendGlobalGMSysMessage("World config settings reloaded.");
        BotMgr::ReloadConfig();
        handler->SendGlobalGMSysMessage("NpcBot config settings reloaded.");
        return true;
    }
};

void AddSC_script_bot_commands()
{
    new script_bot_commands();
}

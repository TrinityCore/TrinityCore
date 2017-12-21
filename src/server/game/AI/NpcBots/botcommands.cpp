#include "bot_ai.h"
#include "botmgr.h"
#include "Chat.h"
#include "RBAC.h"
#include "Group.h"
#include "Language.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellInfo.h"
/*
Name: script_bot_commands
%Complete: ???
Comment: Npcbot related commands
Category: commandscripts/custom/
*/
//RBAC_PERM_GM_COMMANDS = 197
#define GM_COMMANDS rbac::RBACPermissions(197)

class script_bot_commands : public CommandScript
{
private:
    typedef std::pair<uint32 /*id*/, std::string /*name*/> BotPair;
    static bool sortbots(BotPair p1, BotPair p2)
    {
        return p1.first < p2.first;
    }

public:
    script_bot_commands() : CommandScript("script_bot_commands") { }

    std::vector<ChatCommand> GetCommands() const
    {
        static std::vector<ChatCommand> npcbotSetCommandTable =
        {
            { "faction",    rbac::RBAC_PERM_COMMAND_NPCBOT_FACTION,                    false, &HandleNpcSetFactionCommand,             ""},
            { "owner",      rbac::RBAC_PERM_COMMAND_NPCBOT_OWNER,                      false, &HandleNpcSetOwnerCommand,               ""},
        };

        static std::vector<ChatCommand> npcbotCommandTable =
        {
            { "set",        rbac::RBAC_PERM_COMMAND_NPCBOT_SET,                        false, NULL,                                    "", npcbotSetCommandTable},
            { "add",        rbac::RBAC_PERM_COMMAND_NPCBOT_ADD,                        false, &HandleNpcBotAddCommand,                 ""},
            { "remove",     rbac::RBAC_PERM_COMMAND_NPCBOT_REMOVE,                     false, &HandleNpcBotRemoveCommand,              ""},
            { "spawn",      rbac::RBAC_PERM_COMMAND_NPCBOT_SPAWN,                      false, &HandleNpcBotSpawnCommand,               ""},
            { "delete",     rbac::RBAC_PERM_COMMAND_NPCBOT_DELETE,                     false, &HandleNpcBotDeleteCommand,              ""},
            { "lookup",     rbac::RBAC_PERM_COMMAND_NPCBOT_LOOKUP,                     false, &HandleNpcBotLookupCommand,              ""},
            { "revive",     rbac::RBAC_PERM_COMMAND_NPCBOT_REVIVE,                     false, &HandleNpcBotReviveCommand,              ""},
            { "cast",       rbac::RBAC_PERM_COMMAND_NPCBOT_CAST,                       false, &HandleNpcBotCastCustomSpell,            ""},
            { "info", 	    rbac::RBAC_PERM_COMMAND_NPCBOT_INFO,		       false, &HandleNpcBotInfoCommand,		       ""},
            { "reset",	    rbac::RBAC_PERM_COMMAND_NPCBOT_RESET,		       false, &HandleNpcBotResetCommand,	       ""},
            { "command",    rbac::RBAC_PERM_COMMAND_NPCBOT_COMMAND,		       false, &HandleNpcBotCommandCommand,	       ""},
            { "distance",   rbac::RBAC_PERM_COMMAND_NPCBOT_DISTANCE,		       false, &HandleNpcBotDistanceCommand,	       ""},
            { "attack",	    rbac::RBAC_PERM_COMMAND_NPCBOT_ATTACK,		       false, &HandleNpcBotAttackCommand,	       ""},
            { "withdraw",   rbac::RBAC_PERM_COMMAND_NPCBOT_WITHDRAW,		       false, &HandleNpcBotWithdrawCommand,	       ""},
            { "change",   rbac::RBAC_PERM_COMMAND_NPCBOT_CHANGE,		       false, &HandleNpcBotChangeCommand,	       ""},
            { "savemodel",   rbac::RBAC_PERM_COMMAND_NPCBOT_SAVEMODEL,		       false, &HandleNpcBotSaveModelCommand,	       ""},
        };

        static std::vector<ChatCommand> commandTable =
        {
            { "npcbot",     rbac::RBAC_PERM_COMMAND_NPCBOT,                            false, NULL,                      "", npcbotCommandTable},
        };
        return commandTable;
    }

    static bool HandleNpcBotCastCustomSpell(ChatHandler* handler, const char* /*args*/)
    {
        handler->SetSentErrorMessage(true);
        handler->SendSysMessage("This is a dev command. Do not use it.");

        //uint32 trig = SPELL_TRANSPARENCY_50; //transpar
        //SpellInfo* trigInfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(trig));

        //trigInfo->Dispel = DISPEL_NONE;
        //trigInfo->Mechanic = MECHANIC_NONE;
        //trigInfo->RangeEntry = sSpellRangeStore.LookupEntry(6); //6 - 100 yds

        //trigInfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(1); //1 - instant //3 - 0.5 sec
        //trigInfo->DurationEntry = sSpellDurationStore.LookupEntry(1); //1 - 10 sec //32 - 6 seconds
        //trigInfo->ManaCost = 0;
        //trigInfo->ManaCostPercentage = 0;
        //trigInfo->ManaCostPerlevel = 0;
        //trigInfo->Attributes |= (SPELL_ATTR0_NOT_SHAPESHIFT | SPELL_ATTR0_CASTABLE_WHILE_SITTING);
        //trigInfo->AttributesEx &= ~SPELL_ATTR1_CANT_TARGET_SELF;
        //trigInfo->AttributesEx |= (SPELL_ATTR1_NOT_BREAK_STEALTH);
        //trigInfo->AttributesEx2 |= SPELL_ATTR2_UNK22;
        //trigInfo->AttributesEx5 |= SPELL_ATTR5_HASTE_AFFECT_DURATION;
        //trigInfo->Targets = TARGET_FLAG_DEST_LOCATION;
        //trigInfo->AuraInterruptFlags =
        //    AURA_INTERRUPT_FLAG_SPELL_ATTACK | AURA_INTERRUPT_FLAG_MELEE_ATTACK |
        //    AURA_INTERRUPT_FLAG_NOT_ABOVEWATER | AURA_INTERRUPT_FLAG_MOUNT; //0x00003C07;vanish
        //trigInfo->ChannelInterruptFlags = 0x00007C3C; //31788
        //trigInfo->CasterAuraStateNot = 0;

        //trigInfo->Effects[0].Effect = SPELL_EFFECT_DUMMY;
        //trigInfo->Effects[0].BasePoints = 1;
        ////trigInfo->Effects[0].ValueMultiplier = 0.0f;
        //trigInfo->Effects[0].TargetA = SpellImplicitTargetInfo(TARGET_DEST_CHANNEL_TARGET);
        //trigInfo->Effects[0].TargetB = SpellImplicitTargetInfo(TARGET_UNIT_DEST_AREA_ENEMY);
        //trigInfo->Effects[0].ApplyAuraName = SPELL_AURA_NONE;
        //trigInfo->Effects[0].Amplitude = 0;
        //trigInfo->Effects[0].TriggerSpell = 0;
        //trigInfo->Effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_8_YARDS); //14


        uint32 spellId = SPELL_MIRROR_IMAGE_BM; //69936
        SpellInfo* sinfo = const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(spellId));

        //sinfo->SpellLevel = 0;
        //sinfo->MaxLevel = 80;
        //sinfo->Dispel = DISPEL_NONE;
        //sinfo->Mechanic = MECHANIC_NONE;
        sinfo->RangeEntry = sSpellRangeStore.LookupEntry(1); //1 - self only //6 - 100 yds
        //sinfo->Speed = 25.f;
        //sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(1); //1 - instant //3 - 0.5 sec
        sinfo->DurationEntry = sSpellDurationStore.LookupEntry(566); //566 - 0 sec //3 - 60 sec //1 - 10 sec //32 - 6 seconds
        sinfo->RecoveryTime = 3000;
        sinfo->PowerType = POWER_MANA;
        sinfo->ManaCost = 125;
        sinfo->ManaCostPercentage = 0;
        sinfo->ManaCostPerlevel = 0;
        //sinfo->DmgClass = SPELL_DAMAGE_CLASS_MELEE;
        //sinfo->PreventionType = SPELL_PREVENTION_TYPE_PACIFY;
        //sinfo->EquippedItemClass = ITEM_CLASS_WEAPON;
        //sinfo->EquippedItemSubClassMask = 0x0002A5F3;

        //sinfo->Attributes &= ~(SPELL_ATTR0_UNK11);
        sinfo->Attributes |= (SPELL_ATTR0_NOT_SHAPESHIFT/* | SPELL_ATTR0_CASTABLE_WHILE_SITTING | SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY*/);
        //sinfo->AttributesEx &= ~SPELL_ATTR1_UNK11;
        //sinfo->AttributesEx |= (SPELL_ATTR1_NOT_BREAK_STEALTH | SPELL_ATTR1_NO_THREAT);
        sinfo->AttributesEx2 &= ~(SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS);
        sinfo->AttributesEx3 |= SPELL_ATTR3_DONT_DISPLAY_RANGE;
        //sinfo->AttributesEx5 |= SPELL_ATTR5_HIDE_DURATION;
        //sinfo->AttributesEx7 &= ~SPELL_ATTR7_HAS_CHARGE_EFFECT;
        //sinfo->Targets |= TARGET_FLAG_DEST_LOCATION;
        //sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT_ENEMY;
        //sinfo->InterruptFlags = 0x0000000F; //15
        //sinfo->AuraInterruptFlags =
        //    AURA_INTERRUPT_FLAG_SPELL_ATTACK | AURA_INTERRUPT_FLAG_MELEE_ATTACK |
        //    AURA_INTERRUPT_FLAG_NOT_ABOVEWATER | AURA_INTERRUPT_FLAG_MOUNT; //0x00003C07;vanish
        //sinfo->ChannelInterruptFlags = 0x00007C3C; //31788
        //sinfo->CasterAuraStateNot = 0;

        sinfo->Effects[0].Effect = SPELL_EFFECT_DUMMY;
        //sinfo->Effects[0].BasePoints = 9999;
        //sinfo->Effects[0].ValueMultiplier = 0.0f;
        sinfo->Effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
        //sinfo->Effects[0].TargetB = SpellImplicitTargetInfo(0);
        sinfo->Effects[0].MiscValue = 0;
        sinfo->Effects[0].MiscValueB = 0;
        //sinfo->Effects[0].ApplyAuraName = SPELL_AURA_MOD_INVISIBILITY;
        //sinfo->Effects[0].Amplitude = 0;
        //sinfo->Effects[0].TriggerSpell = 0;
        sinfo->Effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_0_YARDS);

        //sinfo->Effects[1].Effect = SPELL_EFFECT_APPLY_AURA;
        //sinfo->Effects[1].BasePoints = 10;
        //sinfo->Effects[1].RealPointsPerLevel = 0.5f;
        //sinfo->Effects[1].ValueMultiplier = 1.0f;
        //sinfo->Effects[1].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
        //sinfo->Effects[1].TargetB = SpellImplicitTargetInfo(0);
        //sinfo->Effects[1].ApplyAuraName = SPELL_AURA_MOD_INCREASE_SPEED;
        //sinfo->Effects[1].Amplitude = 0;
        //sinfo->Effects[1].TriggerSpell = 0;
        //sinfo->Effects[1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_0_YARDS); //14

        //sinfo->Effects[2].Effect = SPELL_EFFECT_TRIGGER_SPELL;
        //sinfo->Effects[2].BasePoints = 0;
        //sinfo->Effects[2].ValueMultiplier = 0.0f;
        //sinfo->Effects[2].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
        //sinfo->Effects[2].TargetB = SpellImplicitTargetInfo(0);
        //sinfo->Effects[2].ApplyAuraName = SPELL_AURA_NONE;
        //sinfo->Effects[2].Amplitude = 0;
        //sinfo->Effects[2].TriggerSpell = trig;
        //sinfo->Effects[2].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_0_YARDS); //14


        return true;
    }

    static bool HandleNpcSetFactionCommand(ChatHandler* handler, const char* args)
    {
        Player* chr = handler->GetSession()->GetPlayer();
        Unit* ubot = chr->GetSelectedUnit();
        if (!ubot || !*args)
        {
            handler->SendSysMessage(".npcbot set faction #faction");
            handler->SendSysMessage("Sets faction for selected npcbot (saved in DB). Use 'a', 'h', 'm', 'f' as argument to set faction to alliance, horde, monster (hostile to all), or friend (friendly to all)");
            handler->SetSentErrorMessage(true);
            return false;
        }

        Creature* bot = ubot->ToCreature();
        if (!bot || !bot->GetIAmABot() || !bot->IsFreeBot())
        {
            handler->SendSysMessage("You must select uncontrolled npcbot.");
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
            factionId = 35; //thesawolf - friendly to all

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

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_NPCBOT_FACTION);
        //"UPDATE characters_npcbot SET faction = ? WHERE entry = ?", CONNECTION_SYNCH
        stmt->setUInt32(0, factionId);
        stmt->setUInt32(1, bot->GetEntry());
        CharacterDatabase.DirectExecute(stmt);

        handler->PSendSysMessage("%s's faction set to %u", bot->GetName().c_str(), factionId);
        bot->GetBotAI()->InitFaction();
        return true;
    }

    static bool HandleNpcSetOwnerCommand(ChatHandler* handler, const char* args)
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
        if (!bot || !bot->GetIAmABot() || bot->GetBotAI()->GetBotOwnerGuid())
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

        if (guidlow)
            sObjectMgr->GetPlayerNameByGUID(ObjectGuid(HighGuid::Player, guidlow), characterName);
        else
            guidlow = sObjectMgr->GetPlayerGUIDByName(characterName);

        if (!guidlow || !normalizePlayerName(characterName))
        {
            handler->PSendSysMessage("Player %s not found", characterName.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        bot->GetBotAI()->SetBotOwnerGUID(guidlow);

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_NPCBOT_OWNER);
        //"UPDATE characters_npcbot SET owner = ? WHERE entry = ?", CONNECTION_ASYNC
        stmt->setUInt32(0, guidlow);
        stmt->setUInt32(1, bot->GetEntry());
        CharacterDatabase.Execute(stmt);

        handler->PSendSysMessage("%s's new owner is %s (guidlow: %u)", bot->GetName().c_str(), characterName.c_str(), guidlow);
        return true;
    }

    static bool HandleNpcBotLookupCommand(ChatHandler* handler, const char* args)
    {
        //this is just a modified '.lookup creature' command
        if (!*args)
        {
            handler->SendSysMessage(".npcbot lookup #class");
            handler->SendSysMessage("Looks up npcbots by #class, and returns all matches with their creature ID's.");
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
            handler->PSendSysMessage("BOT_CLASS_BM = %u", uint32(BOT_CLASS_BM));
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
        CreatureTemplateContainer const* ctc = sObjectMgr->GetCreatureTemplates();
        typedef std::list<BotPair> BotList;
        BotList botlist;
        for (CreatureTemplateContainer::const_iterator itr = ctc->begin(); itr != ctc->end(); ++itr)
        {
            uint32 id = itr->second.Entry;
            if (id < BOT_ENTRY_BEGIN || id > BOT_ENTRY_END) continue;
            uint32 trainer_class = itr->second.trainer_class;
            if (trainer_class != botclass) continue;

            if (CreatureLocale const* creatureLocale = sObjectMgr->GetCreatureLocale(id))
            {
                if (creatureLocale->Name.size() > localeIndex && !creatureLocale->Name[localeIndex].empty())
                {
                    botlist.push_back(BotPair(id, creatureLocale->Name[localeIndex]));
                    continue;
                }
            }

            std::string name = itr->second.Name;
            if (name.empty())
                continue;

            botlist.push_back(BotPair(id, name));
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
            uint32 id = itr->first;
            char const* name = itr->second.c_str();
            handler->PSendSysMessage(LANG_CREATURE_ENTRY_LIST_CHAT, id, id, name);
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

        if (Player* botowner = bot->GetBotOwner()->ToPlayer())
            botowner->GetBotMgr()->RemoveBot(bot->GetGUID(), BOT_REMOVE_DISMISS);

        uint32 id = bot->GetEntry();

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_NPCBOT_EQUIP);
        //"SELECT equipMhEx, equipOhEx, equipRhEx, equipHead, equipShoulders, equipChest, equipWaist, equipLegs, equipFeet, equipWrist, equipHands, equipBack, equipBody, equipFinger1, equipFinger2, equipTrinket1, equipTrinket2, equipNeck
        //FROM characters_npcbot WHERE entry = ?", CONNECTION_SYNCH
        stmt->setUInt32(0, id);
        PreparedQueryResult res = CharacterDatabase.Query(stmt);
        ASSERT(res);

        Field* fields = res->Fetch();
        for (uint8 i = 0; i != BOT_INVENTORY_SIZE; ++i)
        {
            if (fields[i].GetUInt32())
            {
                handler->PSendSysMessage("%s still has eqipment assigned. Please remove equips before deleting bot!", bot->GetName().c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }
        }

        bot->CombatStop();
        bot->DeleteFromDB();
        bot->AddObjectToRemoveList();

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_NPCBOT);
        //"DELETE FROM characters_npcbot WHERE entry = ?", CONNECTION_ASYNC
        stmt->setUInt32(0, id);
        CharacterDatabase.Execute(stmt);

        handler->SendSysMessage("Npcbot successfully deleted.");
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

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_NPCBOT_OWNER);
        //"SELECT owner FROM character_npcbot WHERE entry = ?", CONNECTION_SYNCH
        stmt->setUInt32(0, id);
        PreparedQueryResult res1 = CharacterDatabase.Query(stmt);
        if (res1)
        {
            handler->PSendSysMessage("Npcbot %u already exists in `characters_npcbot` table!", id);
            handler->SendSysMessage("If you want to replace this bot to new location use '.npc move' command");
            handler->SetSentErrorMessage(true);
            return false;
        }

        stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_CREATURE_BY_ID);
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

        if (chr->GetTransport())
        {
            handler->SendSysMessage("Cannot spawn bots on transport!");
            handler->SetSentErrorMessage(true);
            return false;
        }

        float x = chr->GetPositionX();
        float y = chr->GetPositionY();
        float z = chr->GetPositionZ();
        float o = chr->GetOrientation();
        Map* map = chr->GetMap();

        if (map->Instanceable())
        {
            handler->SendSysMessage("Cannot spawn bots in instances!");
            handler->SetSentErrorMessage(true);
            return false;
        }

        Creature* creature = new Creature();
        if (!creature->Create(map->GenerateLowGuid<HighGuid::Unit>(), map, chr->GetPhaseMaskForSpawn(), id, Position(x, y, z, o)))
        {
            delete creature;
            return false;
        }

        uint8 roleMask = BOT_ROLE_DPS;

        uint8 m_class = creature->GetCreatureTemplate()->trainer_class;
        if (!(m_class == CLASS_WARRIOR || m_class == CLASS_ROGUE ||
            m_class == CLASS_PALADIN || m_class == CLASS_DEATH_KNIGHT ||
            m_class == CLASS_SHAMAN || m_class == BOT_CLASS_BM))
            roleMask |= BOT_ROLE_RANGED;
        if (m_class == CLASS_PRIEST || m_class == CLASS_DRUID ||
            m_class == CLASS_SHAMAN || m_class == CLASS_PALADIN)
            roleMask |= BOT_ROLE_HEAL;

        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_NPCBOT);
        //"INSERT INTO characters_npcbot (entry, roles) VALUES (?, ?)", CONNECTION_SYNCH
        stmt->setUInt32(0, id);
        stmt->setUInt8(1, roleMask);
        CharacterDatabase.DirectExecute(stmt);

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

        //thesawolf - autoset faction from spawner
        uint32 factionId = 0;        
        if(chr->GetTeam() == ALLIANCE)
            factionId = 1802; //alliance
        else if(chr->GetTeam() == HORDE)
            factionId = 1801; //horde
        else
            factionId = 35; //friendly to all
        
        creature->SetFaction(factionId);
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_NPCBOT_FACTION);
        //"UPDATE characters_npcbot SET faction = ? WHERE entry = ?", CONNECTION_SYNCH
        stmt->setUInt32(0, factionId);
        stmt->setUInt32(1, id);
        CharacterDatabase.DirectExecute(stmt);

        const_cast<CreatureTemplate*>(creature->GetCreatureTemplate())->faction = factionId;
            
        handler->SendSysMessage("Npcbot successfully spawned.");
        return true;
    }

    static bool HandleNpcBotJumpCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* player = handler->GetSession()->GetPlayer();
        ObjectGuid sel = player->GetTarget();
        if (!sel)
            return false;

        Creature* bot = ObjectAccessor::GetCreatureOrPetOrVehicle(*player, sel);
        if (!bot/* || (!bot->GetIAmABot() && !bot->GetIAmABotsPet())*/)
            return false;

        float speedZ = 10.0f;
        float dist = bot->GetExactDist2d(player->GetPositionX(), player->GetPositionY());
        float speedXY = dist;

        bot->StopMoving();
        bot->GetMotionMaster()->Clear();
        bot->GetMotionMaster()->MoveJump(*player, speedXY, speedZ);

        return true;
    }

    static bool HandleNpcBotSummonCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        char* guidLowstr = strtok((char*)args, " ");
        uint32 guidLow = 0;

        if (guidLowstr)
            guidLow = (uint32)atoi(guidLowstr);

        if (!guidLow)
            return false;

        QueryResult result = WorldDatabase.PQuery("SELECT id FROM creature WHERE guid = %u", guidLow);
        if (!result)
            return false;

        Field* field = result->Fetch();
        uint32 id = field[0].GetUInt32();

        Player* player = handler->GetSession()->GetPlayer();

        /*if (Creature* cre = ObjectAccessor::GetObjectInOrOutOfWorld(ObjectGuid(HIGHGUID_UNIT, id, guidLow), (Creature*)NULL))
        {
            if (cre->GetIAmABot() && !cre->GetBotAI()->GetBotOwnerGuid())
            {
                BotMgr::TeleportBot(cre, player->GetMap(), player);
                return true;
            }
        }*/

        return false;
    }

    static bool HandleNpcBotInfoCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* owner = handler->GetSession()->GetPlayer();
        if (!owner->GetTarget())
        {
            handler->PSendSysMessage(".npcbot info");
            handler->PSendSysMessage("Lists NpcBots count of each class owned by selected player. You can use this on self and your party members");
            handler->SetSentErrorMessage(true);
            return false;
        }
        Player* master = owner->GetSelectedPlayer();
        if (!master || (owner->GetGroup() ? !owner->GetGroup()->IsMember(master->GetGUID()) : master->GetGUID() != owner->GetGUID()))
        {
            handler->PSendSysMessage("You should select self or one of your party members.");
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
            if (i >= BOT_CLASS_EX_START)
            {
                ASSERT(count == 1);

                switch (i)
                {
                    //|cffe6cc80|hxxx|h|r
                    case BOT_CLASS_BM:              bclass = "|cff9d9d9d|hHas Blademaster!|h|r";    break;
                    default:                        bclass = "wtf";                                 break;
                }
                handler->PSendSysMessage("%s (alive: %s)", bclass, (alivecount ? "yes" : "no"));
            }
            else
            {
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
                    default:                        bclass = "Unknown Class";   break;
                }
                handler->PSendSysMessage("%s: %u (alive: %u)", bclass, count, alivecount);
            }
        }
        return true;
    }

    static bool HandleNpcBotDistanceCommand(ChatHandler* handler, const char* args)
    {
        Player* owner = handler->GetSession()->GetPlayer();
        if (!*args)
        {
            if (owner->HaveBot())
            {
                handler->PSendSysMessage("bot follow distance is %u", owner->GetBotFollowDist());
                handler->SetSentErrorMessage(true);
                return false;
            }
            handler->PSendSysMessage(".npcbot distance");
            handler->PSendSysMessage("Sets 'distance to target' at which bots will follow you");
            handler->PSendSysMessage("if set to 0, bots will not attack anything unless you point them");
            handler->PSendSysMessage("min: 0, max: 75");
            handler->SetSentErrorMessage(true);
            return false;
        }
        char* distance = strtok((char*)args, " ");
        int8 dist = -1;

        if (distance)
            dist = (int8)atoi(distance);

        if (dist >= 0 && dist <= 75)
        {
            owner->SetBotFollowDist(dist);
            if (!owner->IsInCombat() && owner->HaveBot())
                owner->GetBotMgr()->SendBotCommandState(COMMAND_FOLLOW);

            Group* gr = owner->GetGroup();
            if (gr && owner->GetMap()->Instanceable() && /*gr->isRaidGroup() &&*/ gr->IsLeader(owner->GetGUID()))
            {
                for (GroupReference* itr = gr->GetFirstMember(); itr != NULL; itr = itr->next())
                {
                    Player* pl = itr->GetSource();
                    if (pl && pl->IsInWorld() && pl->GetMap() == owner->GetMap())
                    {
                        pl->SetBotFollowDist(dist);
                        if (!pl->IsInCombat() && pl->HaveBot())
                            pl->GetBotMgr()->SendBotCommandState(COMMAND_FOLLOW);
                    }
                }
            }
            handler->PSendSysMessage("bot follow distance set to %u", dist);
            return true;
        }
        handler->SendSysMessage("follow distance should be between 0 and 75");
        handler->SetSentErrorMessage(true);
        return false;
    }

    static bool HandleNpcBotCommandCommand(ChatHandler* handler, const char* args)
    {
        Player* owner = handler->GetSession()->GetPlayer();
        if (!*args)
        {
            handler->PSendSysMessage(".npcbot command <command>");
            handler->PSendSysMessage("Forces npcbots to either follow you or hold position.");
            handler->SetSentErrorMessage(true);
            return false;
        }
        char* command = strtok((char*)args, " ");
        int8 state = -1;
        if (!strncmp(command, "s", 2) || !strncmp(command, "st", 3) || !strncmp(command, "stay", 5) || !strncmp(command, "stand", 6))
            state = COMMAND_STAY;
        else if (!strncmp(command, "f", 2) || !strncmp(command, "follow", 7) || !strncmp(command, "fol", 4) || !strncmp(command, "fo", 3))
            state = COMMAND_FOLLOW;
        if (state >= 0 && owner->HaveBot())
        {
            owner->GetBotMgr()->SendBotCommandState(CommandStates(state));
            return true;
        }
        handler->SetSentErrorMessage(true);
        return false;
    }

    //thesawolf - .npcbot attack (TARGET)
    static bool HandleNpcBotAttackCommand(ChatHandler* handler, const char* /*args*/)    
    {
        Player* owner = handler->GetSession()->GetPlayer();
        Unit* target = owner->GetSelectedUnit();
        //Unit* target = u->GetGUID();
        if (!target)
        {
            handler->PSendSysMessage(".npcbot attack (TARGET)");
            handler->PSendSysMessage("ERROR: You need to have a target!");
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (owner->HaveBot())
        {
            //owner->GetBotMgr()->SendBotCommandState(CommandStates(COMMAND_ABANDON));
            owner->GetBotMgr()->SendBotCommandState(CommandStates(COMMAND_ATTACK));
            return true;
        }
        else 
        {
            handler->PSendSysMessage("ERROR: You need to have a controlled bot!");
            handler->SetSentErrorMessage(true);
            return false;
        }        
        handler->SetSentErrorMessage(true);
        return false;
    }
    
    //thesawolf - .npcbot withdraw
    static bool HandleNpcBotWithdrawCommand(ChatHandler* handler, const char* /*args*/)    
    {
        Player* owner = handler->GetSession()->GetPlayer();
        if (owner->HaveBot())
        {
            /*
            if (me->GetVictim())
                me->AttackStop();
            else if (me->IsInCombat())
                Evade(true);
            */                
            //me->CombatStop();
            //SetBotCommandState(COMMAND_ABANDON);
            owner->GetBotMgr()->SendBotCommandState(CommandStates(COMMAND_ABANDON));
            owner->GetBotMgr()->SendBotCommandState(CommandStates(COMMAND_FOLLOW));
            return true;                
        }
        else 
        {
            handler->PSendSysMessage("ERROR: You need to have a controlled bot!");
            handler->SetSentErrorMessage(true);
            return false;
        }        
        handler->SetSentErrorMessage(true);
        return false;
    }

    //cosine - .npcbot change
    static bool HandleNpcBotChangeCommand(ChatHandler* handler, const char* /*args*/)    
    {
        Player* chr = handler->GetSession()->GetPlayer();
        Unit* ubot = chr->GetSelectedUnit();
        if (!ubot)
        {
            handler->SendSysMessage(".npcbot change");
            handler->SendSysMessage("Changes appearance of selected npcbot");
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
        uint32 model_count = 0;
        uint32 new_model_id = 0;
        QueryResult results = WorldDatabase.PQuery("select floor(rand()*count(*)) from creature_model_info where displayid_other_gender > 0 and gender = %u", ubot->getGender() == GENDER_FEMALE ? 1 : 0);
        do
        {
            Field* fields = results->Fetch();
            model_count = fields[0].GetUInt32();
        } while (results->NextRow());
        if (model_count > 0)
        {
            results = WorldDatabase.PQuery("select * from creature_model_info where displayid_other_GENDER > 0 AND gender = %u limit %u, 1",
                ubot->getGender() == GENDER_FEMALE ? 1 : 0, model_count);
            do
            {
                Field* fields = results->Fetch();
                new_model_id = fields[0].GetUInt32();
            } while (results->NextRow());
        }
        else
        {
            handler->SendSysMessage("No models found.");
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (new_model_id > 0 && new_model_id != 19461)
        {
            ubot->SetDisplayId(new_model_id);
            return true;
        }
        else
        {
            handler->SendSysMessage("Model not found.");
            handler->SetSentErrorMessage(true);
            return false;
        }
    }

    //cosine - .npcbot savemodel
    static bool HandleNpcBotSaveModelCommand(ChatHandler* handler, const char* /*args*/)    
    {
        Player* chr = handler->GetSession()->GetPlayer();
        Unit* ubot = chr->GetSelectedUnit();
        if (!ubot)
        {
            handler->SendSysMessage(".npcbot savemodel");
            handler->SendSysMessage("Permanently saves appearance of selected npcbot");
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
        uint32 currDisplayId = ubot->GetDisplayId();
        uint32 npcbot_entry = bot->GetEntry();
        https://web.archive.org/web/20041129090319/http://www.worldofwarcraft.com
        if (npcbot_entry <= 70235)
        {
            TC_LOG_INFO("entities.unit","Setting display id of %u for npcbot entry %u",currDisplayId,npcbot_entry);
            WorldDatabase.PExecute("update creature_template set modelid1 = %u, modelid3 = %u where entry = %u and entry between 70000 and 71000", currDisplayId, currDisplayId, npcbot_entry);
        }
        else
        {
            TC_LOG_INFO("entities.unit","Setting display id of %u for npcbot entry %u",currDisplayId,npcbot_entry);
            WorldDatabase.PExecute("update creature_template set modelid1 = %u, modelid2 = %u, modelid3 = %u, modelid4 = %u where entry = %u and entry between 70000 and 71000", currDisplayId, currDisplayId, currDisplayId, currDisplayId, npcbot_entry);
        }
    
        return true;
    }
    
    static bool HandleNpcBotRemoveCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* owner = handler->GetSession()->GetPlayer();
        Unit* u = owner->GetSelectedUnit();
        if (!u)
        {
            handler->PSendSysMessage(".npcbot remove");
            handler->PSendSysMessage("Frees selected npcbot from it's owner. Select player to remove all npcbots");
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
                    handler->PSendSysMessage("Npcbots were successfully removed");
                    handler->SetSentErrorMessage(true);
                    return true;
                }
                handler->PSendSysMessage("Some npcbots were not removed!");
                handler->SetSentErrorMessage(true);
                return false;
            }
            handler->PSendSysMessage("Npcbots are not found!");
            handler->SetSentErrorMessage(true);
            return false;
        }

        Creature* cre = u->ToCreature();
        if (cre && cre->GetIAmABot() && !cre->IsFreeBot())
        {
            master = cre->GetBotOwner();
            master->GetBotMgr()->RemoveBot(cre->GetGUID(), BOT_REMOVE_DISMISS);
            if (master->GetBotMgr()->GetBot(cre->GetGUID()) == NULL)
            {
                handler->PSendSysMessage("NpcBot successfully removed");
                handler->SetSentErrorMessage(true);
                return true;
            }
            handler->PSendSysMessage("NpcBot was NOT removed for some stupid reason!");
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage("You must select player or controlled npcbot");
        handler->SetSentErrorMessage(true);
        return false;
    }

    static bool HandleNpcBotResetCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* owner = handler->GetSession()->GetPlayer();
        Player* master = NULL;
        bool all = false;
        ObjectGuid guid = owner->GetTarget();
        if (!guid)
        {
            handler->PSendSysMessage(".npcbot reset");
            handler->PSendSysMessage("Reset selected npcbot, or all npcbots if used on self");
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (guid.IsPlayer())
        {
            master = owner;
            all = true;
        }
        else if (guid.IsCreature())
        {
            if (Creature* cre = ObjectAccessor::GetCreature(*owner, guid))
                master = cre->GetBotOwner();
        }
        if (master && master->GetGUID() == owner->GetGUID())
        {
            if (!master->HaveBot())
            {
                handler->PSendSysMessage("Npcbots are not found!");
                handler->SetSentErrorMessage(true);
                return false;
            }
            if (all)
                master->RemoveAllBots(BOT_REMOVE_DISMISS);
            else
                master->GetBotMgr()->RemoveBot(guid, BOT_REMOVE_DISMISS);
            handler->SetSentErrorMessage(true);
            return true;
        }
        handler->PSendSysMessage(".npcbot reset");
        handler->PSendSysMessage("Reset selected npcbot. Cannot be used in combat");
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
            handler->SendSysMessage("Npcbots revived.");
            return true;
        }
        else if (Creature* bot = u->ToCreature())
        {
            if (bot->GetBotAI())
            {
                BotMgr::ReviveBot(bot);
                handler->PSendSysMessage("%s revived.", bot->GetName().c_str());
                return true;
            }
        }

        handler->SendSysMessage("You must select player or npcbot.");
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
            handler->SendSysMessage("Allows to hire selected uncontrolled bot, bypassing price condition");
            handler->SetSentErrorMessage(true);
            return false;
        }

        Creature* bot = cre->ToCreature();
        if (!bot || !bot->GetIAmABot() || bot->GetBotAI()->GetBotOwnerGuid())
        {
            handler->SendSysMessage("You must select uncontrolled npcbot");
            handler->SetSentErrorMessage(true);
            return false;
        }

        BotMgr* mgr = owner->GetBotMgr();
        if (!mgr)
            mgr = new BotMgr(owner);

        if (mgr->AddBot(bot) == BOT_ADD_SUCCESS)
        {
            handler->PSendSysMessage("%s is now your npcbot", bot->GetName().c_str());
            return true;
        }

        handler->PSendSysMessage("NpcBot is NOT created for some reason!");
        handler->SetSentErrorMessage(true);
        return false;
    }
};

void AddSC_script_bot_commands()
{
    new script_bot_commands();
}

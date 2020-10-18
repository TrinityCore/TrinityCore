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
#include "SpellInfo.h"
#include "SpellMgr.h"
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

using namespace Trinity::ChatCommands;

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

    ChatCommandTable GetCommands() const override
    {
        //static std::vector<ChatCommand> npcbotToggleCommandTable =
        //{
        //    { "flags",      GM_COMMANDS,            false, &HandleNpcBotToggleFlagsCommand,         "" },
        //};

        static ChatCommandTable npcbotDebugCommandTable =
        {
            { "raid",       HandleNpcBotDebugRaidCommand,               GM_COMMANDS, Console::No  },
            { "mount",      HandleNpcBotDebugMountCommand,              GM_COMMANDS, Console::No  },
            { "spellvisual",HandleNpcBotDebugSpellVisualCommand,        GM_COMMANDS, Console::No  },
            { "states",     HandleNpcBotDebugStatesCommand,             GM_COMMANDS, Console::No  },
        };

        static ChatCommandTable npcbotSetCommandTable =
        {
            { "faction",    HandleNpcBotSetFactionCommand,              GM_COMMANDS, Console::No  },
            { "owner",      HandleNpcBotSetOwnerCommand,                GM_COMMANDS, Console::No  },
            { "spec",       HandleNpcBotSetSpecCommand,                 GM_COMMANDS, Console::No  },
        };

        static ChatCommandTable npcbotCommandCommandTable =
        {
            { "standstill", HandleNpcBotCommandStandstillCommand,   PLAYER_COMMANDS, Console::No  },
            { "stopfully",  HandleNpcBotCommandStopfullyCommand,    PLAYER_COMMANDS, Console::No  },
            { "follow",     HandleNpcBotCommandFollowCommand,       PLAYER_COMMANDS, Console::No  },
        };

        static ChatCommandTable npcbotAttackDistanceCommandTable =
        {
            { "short",      HandleNpcBotAttackDistanceShortCommand, PLAYER_COMMANDS, Console::No  },
            { "long",       HandleNpcBotAttackDistanceLongCommand,  PLAYER_COMMANDS, Console::No  },
            { "",           HandleNpcBotAttackDistanceExactCommand, PLAYER_COMMANDS, Console::No  },
        };

        static ChatCommandTable npcbotDistanceCommandTable =
        {
            { "attack",     npcbotAttackDistanceCommandTable                                      },
            { "",           HandleNpcBotFollowDistanceCommand,      PLAYER_COMMANDS, Console::No  },
        };

        static ChatCommandTable npcbotOrderCommandTable =
        {
            { "cast",       HandleNpcBotOrderCastCommand,           PLAYER_COMMANDS, Console::No  },
        };

        static ChatCommandTable npcbotCommandTable =
        {
            //{ "debug",      npcbotDebugCommandTable                                               },
            //{ "toggle",     npcbotToggleCommandTable                                              },
            { "set",        npcbotSetCommandTable },
            { "add",        HandleNpcBotAddCommand,                     GM_COMMANDS, Console::No  },
            { "remove",     HandleNpcBotRemoveCommand,                  GM_COMMANDS, Console::No  },
            { "spawn",      HandleNpcBotSpawnCommand,                   GM_COMMANDS, Console::No  },
            { "delete",     HandleNpcBotDeleteCommand,                  GM_COMMANDS, Console::No  },
            { "lookup",     HandleNpcBotLookupCommand,                  GM_COMMANDS, Console::No  },
            { "revive",     HandleNpcBotReviveCommand,                  GM_COMMANDS, Console::No  },
            { "reloadconfig",HandleNpcBotReloadConfigCommand,           GM_COMMANDS, Console::Yes },
            { "command",    npcbotCommandCommandTable                                             },
            { "info",       HandleNpcBotInfoCommand,                PLAYER_COMMANDS, Console::No  },
            { "hide",       HandleNpcBotHideCommand,                PLAYER_COMMANDS, Console::No  },
            { "unhide",     HandleNpcBotUnhideCommand,              PLAYER_COMMANDS, Console::No  },
            { "show",       HandleNpcBotUnhideCommand,              PLAYER_COMMANDS, Console::No  },
            { "recall",     HandleNpcBotRecallCommand,              PLAYER_COMMANDS, Console::No  },
            { "kill",       HandleNpcBotKillCommand,                PLAYER_COMMANDS, Console::No  },
            { "suicide",    HandleNpcBotKillCommand,                PLAYER_COMMANDS, Console::No  },
            { "distance",   npcbotDistanceCommandTable                                            },
            { "order",      npcbotOrderCommandTable                                               },
        };

        static ChatCommandTable commandTable =
        {
            { "npcbot",     npcbotCommandTable                                                    },
        };
        return commandTable;
    }

    static bool HandleNpcBotDebugStatesCommand(ChatHandler* handler, const char* /*args*/)
    {
        Unit* target = handler->getSelectedUnit();
        if (!target)
        {
            handler->SendSysMessage("未选择目标");
            return true;
        }

        uint8 const MAX_UNIT_STATES = 29;
        std::ostringstream ostr;
        ostr << "列出的状态 " << target->GetName() << ":";
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
            handler->SendSysMessage("显示你团队副本信息");
            return true;
        }
        if (!gr->isRaidGroup())
        {
            handler->SendSysMessage("仅在团队副本中可用");
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
                << " 小组: " << uint32(subGroup + 1) << "\n";
        }

        for (uint8 i = 0; i != MAX_RAID_SUBGROUPS; ++i)
            if (subBots[i] > 0)
                sstr << uint32(subBots[i]) << " 在小组 " << uint32(i + 1) << "\n";

        handler->SendSysMessage(sstr.str().c_str());
        delete[] subBots;
        return true;
    }

    static bool HandleNpcBotDebugMountCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
            return false;

        //float speed = 1.f;
        uint32 num = 0;

        num = atoi((char*)args);
        if (!num)
            return false;

        Unit* target = handler->getSelectedUnit();
        if (!target)
        {
            handler->SendSysMessage("未选择目标");
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
            handler->SendSysMessage("未选择目标");
            return true;
        }

        const std::string intStr = args;
        uint32 kit = (uint32)atoi((char*)args);

        target->SendPlaySpellVisual(kit);
        return true;
    }

    static bool HandleNpcBotOrderCastCommand(ChatHandler* handler, const char* args)
    {
        Player* owner = handler->GetSession()->GetPlayer();
        char* bot_name = !*args ? nullptr : strtok((char*)args, " ");
        char* spell_name = !*args ? nullptr : strtok(NULL, " ");
        char* target_token = !*args ? nullptr : strtok(NULL, " ");

        if (!owner->HaveBot() || !*args || !bot_name || !spell_name)
        {
            handler->SendSysMessage(".npcbot order cast #bot_name #spell_underscored_name #[target_token]");
            handler->SendSysMessage("命令机器人立即施放咒语");
            return true;
        }

        for (uint32 i = 0; i < strlen(spell_name); ++i)
            if (spell_name[i] == '_')
                spell_name[i] = ' ';

        Creature* bot = owner->GetBotMgr()->GetBotByName(bot_name);
        if (!bot || !bot->IsInWorld())
        {
            handler->PSendSysMessage("Bot %s 找不到！", bot_name);
            return true;
        }
        if (!bot->IsAlive())
        {
            handler->PSendSysMessage("%s 死了!", bot->GetName().c_str());
            return true;
        }

        uint32 basespell = 0;
        std::string sname = spell_name;
        std::wstring wname;
        if (Utf8toWStr(sname, wname))
        {
            wstrToLower(wname);
            bot_ai::BotSpellMap const& spellmap = bot->GetBotAI()->GetSpellMap();
            for (bot_ai::BotSpellMap::const_iterator itr = spellmap.begin(); itr != spellmap.end(); ++itr)
            {
                //we ignore enabled state since this is exactly what we want
                if (itr->second->spellId == 0) //not init'ed
                    continue;
                sname = sSpellMgr->GetSpellInfo(itr->first)->SpellName[handler->GetSessionDbcLocale()];
                std::wstring wcname;
                if (!Utf8toWStr(sname, wcname))
                    continue;
                wstrToLower(wcname);
                if (wcname == wname)
                {
                    basespell = itr->first;
                    break;
                }
            }
        }
        if (!basespell)
        {
            handler->PSendSysMessage("%s 没有咒语命名 '%s'!", bot->GetName().c_str(), spell_name);
            return true;
        }
        //we ignore GCD for now
        if (bot->GetBotAI()->GetSpellCooldown(basespell) > bot->GetBotAI()->GetLastDiff())
        {
            handler->PSendSysMessage("%s的 %s 还没准备好!", bot->GetName().c_str(), sSpellMgr->GetSpellInfo(basespell)->SpellName[handler->GetSessionDbcLocale()]);
            return true;
        }

        ObjectGuid target_guid;
        if (!target_token || !stricmp(target_token, "bot") || !stricmp(target_token, "self"))
            target_guid = bot->GetGUID();
        else if (!stricmp(target_token, "me") || !stricmp(target_token, "master"))
            target_guid = owner->GetGUID();
        else if (!stricmp(target_token, "target"))
            target_guid = bot->GetTarget();
        else if (!stricmp(target_token, "mytarget"))
            target_guid = owner->GetTarget();
        else
        {
            handler->PSendSysMessage("目标无效 token '%s'!", target_token);
            handler->SendSysMessage("有效目标 tokens:\n    '','bot','self', 'me','master', 'target', 'mytarget'");
            return true;
        }

        Unit* target = ObjectAccessor::GetUnit(*owner, target_guid);
        if (!target || !bot->FindMap() || target->FindMap() != bot->FindMap())
        {
            handler->PSendSysMessage("目标无效 '%s'!", target ? target->GetName().c_str() : "unknown");
            return true;
        }

        bot_ai::BotOrder* order = new bot_ai::BotOrder(BOT_ORDER_SPELLCAST);
        order->params.spellCastParams.baseSpell = basespell;
        order->params.spellCastParams.targetGuid = target_guid.GetRawValue();

        if (bot->GetBotAI()->AddOrder(order))
        {
            if (DEBUG_BOT_ORDERS)
                handler->PSendSysMessage("Order given: %s: %s on %s", bot->GetName().c_str(),
                    sSpellMgr->GetSpellInfo(basespell)->SpellName[handler->GetSessionDbcLocale()], target ? target->GetName().c_str() : "unknown");
        }
        else
        {
            if (DEBUG_BOT_ORDERS)
                handler->PSendSysMessage("Order failed: %s: %s on %s", bot->GetName().c_str(),
                    sSpellMgr->GetSpellInfo(basespell)->SpellName[handler->GetSessionDbcLocale()], target ? target->GetName().c_str() : "unknown");
        }

        return true;
    }

    static bool HandleNpcBotFollowDistanceCommand(ChatHandler* handler, const char* args)
    {
        Player* owner = handler->GetSession()->GetPlayer();
        char* dist_str = strtok((char*)args, " ");

        if (!owner->HaveBot() || !dist_str)
        {
            handler->SendSysMessage(".npcbot distance #[attack] #newdist");
            handler->SendSysMessage("设置机器人的跟随/攻击距离");
            return true;
        }

        uint8 newdist = (uint8)std::min<int32>(std::max<int32>(atoi(dist_str), 0), 100);
        owner->GetBotMgr()->SetBotFollowDist(newdist);

        handler->PSendSysMessage("机器人的跟随距离设置为 %u", uint32(newdist));
        return true;
    }

    static bool HandleNpcBotAttackDistanceShortCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* owner = handler->GetSession()->GetPlayer();
        if (!owner->HaveBot())
        {
            handler->SendSysMessage(".npcbot distance attack short");
            handler->SendSysMessage("设置机器人的攻击距离");
            return true;
        }

        owner->GetBotMgr()->SetBotAttackRangeMode(BOT_ATTACK_RANGE_SHORT);

        handler->SendSysMessage("机器人的攻击距离设置为“短”");
        return true;
    }

    static bool HandleNpcBotAttackDistanceLongCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* owner = handler->GetSession()->GetPlayer();
        if (!owner->HaveBot())
        {
            handler->SendSysMessage(".npcbot distance attack long");
            handler->SendSysMessage("设置机器人的攻击距离");
            return true;
        }

        owner->GetBotMgr()->SetBotAttackRangeMode(BOT_ATTACK_RANGE_LONG);

        handler->SendSysMessage("机器人的攻击距离设置为“长”");
        return true;
    }

    static bool HandleNpcBotAttackDistanceExactCommand(ChatHandler* handler, const char* args)
    {
        Player* owner = handler->GetSession()->GetPlayer();
        char* dist_str = strtok((char*)args, " ");

        if (!owner->HaveBot() || !dist_str)
        {
            handler->SendSysMessage(".npcbot distance attack #newdist");
            handler->SendSysMessage("设置机器人的攻击距离");
            return true;
        }

        uint8 newdist = (uint8)std::min<int32>(std::max<int32>(atoi(dist_str), 0), 50);
        owner->GetBotMgr()->SetBotAttackRangeMode(BOT_ATTACK_RANGE_EXACT, newdist);

        handler->PSendSysMessage("机器人的攻击距离设置为 %u", uint32(newdist));
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
            handler->SendSysMessage("暂时隐藏你所拥有的NpcBot");
            //handler->SendSysMessage("You have no bots!");
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (!owner->IsAlive())
        {
            handler->GetSession()->SendNotification("你已经死了");
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
        handler->SendSysMessage("Bots 暂时隐藏了");
        return true;
    }

    static bool HandleNpcBotUnhideCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* owner = handler->GetSession()->GetPlayer();
        if (!owner->HaveBot())
        {
            handler->SendSysMessage(".npcbot unhide | show");
            handler->SendSysMessage("取消隐藏你所拥有的NpcBot");
            //handler->SendSysMessage("You have no bots!");
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (!owner->IsAlive())
        {
            handler->GetSession()->SendNotification("你已经死了");
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
        handler->SendSysMessage("Bots 取消隐藏了");
        return true;
    }

    static bool HandleNpcBotKillCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* owner = handler->GetSession()->GetPlayer();

        ObjectGuid guid = owner->GetTarget();
        if (!guid || !owner->HaveBot())
        {
            handler->SendSysMessage(".npcbot recall");
            handler->SendSysMessage("杀掉你的npcbot。如果你选择你自己，你的所有NpcBot就会死");
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

        handler->SendSysMessage("你必须选择一个NpcBot或你自己");
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
            handler->SendSysMessage("强制要求NpcBot回到你身边，你必须选择一个NpcBot或你自己");
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

        handler->SendSysMessage("你必须选择一个NpcBot或你自己");
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
            handler->SendSysMessage("为选定的npcbot设置势力（保存在数据库中）");
            handler->SendSysMessage("参数使用：“a”=联盟、“h”=部落、“m”=怪物（敌视所有人）、“f”=朋友（对所有人友好）");
            handler->SetSentErrorMessage(true);
            return false;
        }

        Creature* bot = ubot->ToCreature();
        if (!bot || !bot->IsNPCBot() || !bot->IsFreeBot())
        {
            handler->SendSysMessage("必须选择一个未受控制的NpcBot");
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

        handler->PSendSysMessage("%s 的势力设置为 %u", bot->GetName().c_str(), factionId);
        return true;
    }

    static bool HandleNpcBotSetOwnerCommand(ChatHandler* handler, const char* args)
    {
        Player* chr = handler->GetSession()->GetPlayer();
        Unit* ubot = chr->GetSelectedUnit();
        if (!ubot || !*args)
        {
            handler->SendSysMessage(".npcbot set owner #guid | #name");
            handler->SendSysMessage("使用guid或name将所选NpcBot绑定到玩家，并更新数据库中的所有者");
            handler->SetSentErrorMessage(true);
            return false;
        }

        Creature* bot = ubot->ToCreature();
        if (!bot || !bot->IsNPCBot())
        {
            handler->SendSysMessage("必须选择一个NpcBot");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (bot->GetBotAI()->GetBotOwnerGuid())
        {
            handler->SendSysMessage("此npcbot已经拥有所有者");
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
            handler->SendSysMessage("未找到玩家");
            handler->SetSentErrorMessage(true);
            return false;
        }

        BotDataMgr::UpdateNpcBotData(bot->GetEntry(), NPCBOT_UPDATE_OWNER, &guidlow);
        bot->GetBotAI()->ReinitOwner();
        //bot->GetBotAI()->Reset();

        handler->PSendSysMessage("%s的新的所有者为 %s (guidlow: %u)", bot->GetName().c_str(), characterName.c_str(), guidlow);
        return true;
    }

    static bool HandleNpcBotSetSpecCommand(ChatHandler* handler, const char* args)
    {
        Player* chr = handler->GetSession()->GetPlayer();
        Unit* ubot = chr->GetSelectedUnit();
        if (!ubot || !*args)
        {
            handler->SendSysMessage(".npcbot set spec #specnumber");
            handler->SendSysMessage("更改所选npcbot的天赋");
            handler->SetSentErrorMessage(true);
            return false;
        }

        Creature* bot = ubot->ToCreature();
        if (!bot || !bot->IsNPCBot())
        {
            handler->SendSysMessage("你必需选择一个npcbot");
            handler->SetSentErrorMessage(true);
            return false;
        }

        char* specStr = strtok((char*)args, " ");
        if (!specStr)
            return false;

        uint8 spec = (uint8)atoi(specStr);
        if (spec < BOT_SPEC_BEGIN || spec > BOT_SPEC_END)
        {
            handler->SendSysMessage("天赋超出范围 (1 to 3)!");
            handler->SetSentErrorMessage(true);
            return false;
        }

        bot->GetBotAI()->SetSpec(spec);

        handler->PSendSysMessage("%s现在已经绑定给 %u", bot->GetName().c_str(), uint32(spec));
        return true;
    }

    static bool HandleNpcBotLookupCommand(ChatHandler* handler, const char* args)
    {
        //this is just a modified '.lookup creature' command
        if (!*args)
        {
            handler->SendSysMessage(".npcbot lookup #class");
            handler->SendSysMessage("按#class(职业)查找NpcBot，显示职业ID");
            handler->PSendSysMessage("战士 = %u", uint32(BOT_CLASS_WARRIOR));
            handler->PSendSysMessage("圣骑士 = %u", uint32(BOT_CLASS_PALADIN));
            handler->PSendSysMessage("猎人 = %u", uint32(BOT_CLASS_HUNTER));
            handler->PSendSysMessage("潜行者 = %u", uint32(BOT_CLASS_ROGUE));
            handler->PSendSysMessage("牧师 = %u", uint32(BOT_CLASS_PRIEST));
            handler->PSendSysMessage("死亡骑士 = %u", uint32(BOT_CLASS_DEATH_KNIGHT));
            handler->PSendSysMessage("萨满 = %u", uint32(BOT_CLASS_SHAMAN));
            handler->PSendSysMessage("法师 = %u", uint32(BOT_CLASS_MAGE));
            handler->PSendSysMessage("术士 = %u", uint32(BOT_CLASS_WARLOCK));
            handler->PSendSysMessage("德鲁伊 = %u", uint32(BOT_CLASS_DRUID));
            handler->PSendSysMessage("剑圣 = %u", uint32(BOT_CLASS_BM));
            handler->PSendSysMessage("黑曜石毁灭者 = %u", uint32(BOT_CLASS_SPHYNX));
            handler->PSendSysMessage("大魔导师 = %u", uint32(BOT_CLASS_ARCHMAGE));
            handler->PSendSysMessage("恐惧领主 = %u", uint32(BOT_CLASS_DREADLORD));
            handler->PSendSysMessage("破法者 = %u", uint32(BOT_CLASS_SPELLBREAKER));
            handler->PSendSysMessage("黑暗游侠 = %u", uint32(BOT_CLASS_DARK_RANGER));
            handler->SetSentErrorMessage(true);
            return false;
        }

        char* classstr = strtok((char*)args, " ");
        uint8 botclass = BOT_CLASS_NONE;

        if (classstr)
            botclass = (uint8)atoi(classstr);

        if (botclass == BOT_CLASS_NONE || botclass >= BOT_CLASS_END)
        {
            handler->PSendSysMessage("未知的职业类型 %u", uint32(botclass));
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage("寻找NpcBot职业ID: %u...", uint32(botclass));

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
            case RACE_HUMAN:        raceName = "人类";     break;
            case RACE_ORC:          raceName = "兽人";       break;
            case RACE_DWARF:        raceName = "矮人";     break;
            case RACE_NIGHTELF:     raceName = "暗夜精灵"; break;
            case RACE_UNDEAD_PLAYER:raceName = "亡灵";  break;
            case RACE_TAUREN:       raceName = "牛头人";    break;
            case RACE_GNOME:        raceName = "侏儒";     break;
            case RACE_TROLL:        raceName = "巨魔";     break;
            case RACE_BLOODELF:     raceName = "血精灵f"; break;
            case RACE_DRAENEI:      raceName = "德莱尼";   break;
            case RACE_NONE:         raceName = "没有种族";   break;
            default:                raceName = "未知";   break;
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
            handler->SendSysMessage("从数据库中删除选定的NpcBot");
            handler->SetSentErrorMessage(true);
            return false;
        }

        Creature* bot = ubot->ToCreature();
        if (!bot || !bot->IsNPCBot())
        {
            handler->SendSysMessage("没有NpcBot被选中");
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
            handler->PSendSysMessage("%s 分配了装备。删除之前请先移除装备!", bot->GetName().c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        bot->GetBotAI()->canUpdate = false;
        bot->CombatStop();
        bot->GetBotAI()->Reset();
        Creature::DeleteFromDB(bot->GetSpawnId());
        bot->AddObjectToRemoveList();

        BotDataMgr::UpdateNpcBotData(id, NPCBOT_UPDATE_ERASE);

        handler->SendSysMessage("成功删除NpcBot");
        return true;
    }

    static bool HandleNpcBotSpawnCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
        {
            handler->SendSysMessage(".npcbot spawn");
            handler->SendSysMessage("加一个NpcBot. 你也可以用链接的形式");
            handler->SendSysMessage("语法: .npcbot spawn #entry");
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
            handler->PSendSysMessage("creature %u 不存在!", id);
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
            handler->PSendSysMessage("Npcbot %u 已经存在于 `characters_npcbot` 表中!", id);
            handler->SendSysMessage("如果要将此机器人移动到新位置，你可以使用 '.npc move' 命令");
            handler->SetSentErrorMessage(true);
            return false;
        }

        WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_CREATURE_BY_ID);
        //"SELECT guid FROM creature WHERE id = ?", CONNECTION_SYNCH
        stmt->setUInt32(0, id);
        PreparedQueryResult res2 = WorldDatabase.Query(stmt);
        if (res2)
        {
            handler->PSendSysMessage("Npcbot %u 已经存在于 `creature` 表中!", id);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* chr = handler->GetSession()->GetPlayer();

        if (/*Transport* trans = */chr->GetTransport())
        {
            handler->SendSysMessage("无法在骑乘状态下召唤!");
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
            handler->SendSysMessage("无法在地下城中召唤!");
            handler->SetSentErrorMessage(true);
            return false;
        }

        Creature* creature = new Creature();
        if (!creature->Create(map->GenerateLowGuid<HighGuid::Unit>(), map, chr->GetPhaseMaskForSpawn(), id, *chr))
        {
            delete creature;
            handler->SendSysMessage("创建失败!");
            handler->SetSentErrorMessage(true);
            return false;
        }

        NpcBotExtras const* _botExtras = BotDataMgr::SelectNpcBotExtras(id);

        uint16 roleMask = BOT_ROLE_DPS;

        uint8 m_class = _botExtras ? _botExtras->bclass : uint8(CLASS_WARRIOR);
        if (!bot_ai::IsMeleeClass(m_class))
            roleMask |= BOT_ROLE_RANGED;
        if (bot_ai::IsHealingClass(m_class))
            roleMask |= BOT_ROLE_HEAL;

        uint8 spec = urand(1,3);
        switch (m_class)
        {
            case BOT_CLASS_WARRIOR:
            case BOT_CLASS_PALADIN:
            case BOT_CLASS_HUNTER:
            case BOT_CLASS_ROGUE:
            case BOT_CLASS_PRIEST:
            case BOT_CLASS_DEATH_KNIGHT:
            case BOT_CLASS_SHAMAN:
            case BOT_CLASS_MAGE:
            case BOT_CLASS_WARLOCK:
                spec += (m_class-1) * 3;
                break;
            case BOT_CLASS_DRUID:
                spec += (m_class-2) * 3;
                break;
            default:
                spec = uint8(BOT_SPEC_DEFAULT);
                break;
        }

        BotDataMgr::AddNpcBotData(id, roleMask, spec, creature->GetCreatureTemplate()->faction);

        creature->SaveToDB(map->GetId(), (1 << map->GetSpawnMode()), chr->GetPhaseMaskForSpawn());

        uint32 db_guid = creature->GetSpawnId();
        if (!creature->LoadBotCreatureFromDB(db_guid, map))
        {
            handler->SendSysMessage("无法从数据库加载npcbot!");
            handler->SetSentErrorMessage(true);
            //return false;
            delete creature;
            return false;
        }

        sObjectMgr->AddCreatureToGrid(db_guid, sObjectMgr->GetCreatureData(db_guid));

        handler->SendSysMessage("召唤NpcBot成功");
        return true;
    }

    static bool HandleNpcBotInfoCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* owner = handler->GetSession()->GetPlayer();
        if (!owner->GetTarget())
        {
            handler->SendSysMessage(".npcbot info");
            handler->SendSysMessage("统计所选玩家拥有的每个职业的NpcBot。你可以统计自己和你队员");
            handler->SetSentErrorMessage(true);
            return false;
        }
        Player* master = owner->GetSelectedPlayer();
        if (!master)
        {
            handler->SendSysMessage("没有玩家被选中");
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (handler->HasLowerSecurity(master, ObjectGuid::Empty))
        {
            handler->SendSysMessage("无效的目标");
            handler->SetSentErrorMessage(true);
            return false;
        }
        if (!master->HaveBot())
        {
            handler->PSendSysMessage("%s 没有NpcBots!", master->GetName().c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage("%s的NpcBot", master->GetName().c_str());
        handler->PSendSysMessage("拥有NpcBots: %u 个", master->GetNpcBotsCount());
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
            case BOT_CLASS_WARRIOR:         bclass = "战士";        break;
            case BOT_CLASS_PALADIN:         bclass = "圣骑士";        break;
            case BOT_CLASS_MAGE:            bclass = "法师";           break;
            case BOT_CLASS_PRIEST:          bclass = "牧师";         break;
            case BOT_CLASS_WARLOCK:         bclass = "术士";        break;
            case BOT_CLASS_DRUID:           bclass = "德鲁伊";          break;
            case BOT_CLASS_DEATH_KNIGHT:    bclass = "死亡骑士";   break;
            case BOT_CLASS_ROGUE:           bclass = "潜行者";          break;
            case BOT_CLASS_SHAMAN:          bclass = "萨满";         break;
            case BOT_CLASS_HUNTER:          bclass = "猎人";         break;
            case BOT_CLASS_BM:              bclass = "剑圣";    break;
            case BOT_CLASS_SPHYNX:          bclass = "黑曜石毁灭者";      break;
            case BOT_CLASS_ARCHMAGE:        bclass = "大魔导师";        break;
            case BOT_CLASS_DREADLORD:       bclass = "恐惧领主";      break;
            case BOT_CLASS_SPELLBREAKER:    bclass = "破法者";  break;
            case BOT_CLASS_DARK_RANGER:     bclass = "黑暗游侠";    break;
            default:                        bclass = "未知职业";   break;
            }
            handler->PSendSysMessage("%s: %u (alive: %u)", bclass, count, alivecount);
        }
        return true;
    }

    static bool HandleNpcBotCommandStandstillCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* owner = handler->GetSession()->GetPlayer();

        if (!owner->HaveBot())
        {
            handler->SendSysMessage(".npcbot command standstill");
            handler->SendSysMessage("强制您的npcbot停止所有移动并保持驻守");
            handler->SetSentErrorMessage(true);
            return false;
        }

        std::string msg;
        Unit* target = owner->GetSelectedUnit();
        if (target && owner->GetBotMgr()->GetBot(target->GetGUID()))
        {
            target->ToCreature()->GetBotAI()->SetBotCommandState(BOT_COMMAND_STAY);
            msg = target->GetName() + "的命令状态设置为 停留";
        }
        else
        {
            owner->GetBotMgr()->SendBotCommandState(BOT_COMMAND_STAY);
            msg = "所有机器人的命令状态设置为 停留";
        }

        handler->SendSysMessage(msg.c_str());
        return true;
    }

    static bool HandleNpcBotCommandStopfullyCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* owner = handler->GetSession()->GetPlayer();

        if (!owner->HaveBot())
        {
            handler->SendSysMessage(".npcbot command stopfully");
            handler->SendSysMessage("强制您的npcbots停止所有活动");
            handler->SetSentErrorMessage(true);
            return false;
        }

        std::string msg;
        Unit* target = owner->GetSelectedUnit();
        if (target && owner->GetBotMgr()->GetBot(target->GetGUID()))
        {
            target->ToCreature()->GetBotAI()->SetBotCommandState(BOT_COMMAND_FULLSTOP);
            msg = target->GetName() + "的命令状态设置为 全部停止";
        }
        else
        {
            owner->GetBotMgr()->SendBotCommandState(BOT_COMMAND_FULLSTOP);
            msg = "所有机器人的命令状态设置为 全部停止";
        }

        handler->SendSysMessage(msg.c_str());
        return true;
    }

    static bool HandleNpcBotCommandFollowCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* owner = handler->GetSession()->GetPlayer();

        if (!owner->HaveBot())
        {
            handler->SendSysMessage(".npcbot command follow");
            handler->SendSysMessage("让npcbot再次跟随你");
            handler->SetSentErrorMessage(true);
            return false;
        }

        std::string msg;
        Unit* target = owner->GetSelectedUnit();
        if (target && owner->GetBotMgr()->GetBot(target->GetGUID()))
        {
            target->ToCreature()->GetBotAI()->SetBotCommandState(BOT_COMMAND_FOLLOW);
            msg = target->GetName() + "的命令状态设置为 跟随";
        }
        else
        {
            owner->GetBotMgr()->SendBotCommandState(BOT_COMMAND_FOLLOW);
            msg = "所有机器人的命令状态设置为 跟随";
        }

        handler->SendSysMessage(msg.c_str());
        return true;
    }

    static bool HandleNpcBotRemoveCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player* owner = handler->GetSession()->GetPlayer();
        Unit* u = owner->GetSelectedUnit();
        if (!u)
        {
            handler->SendSysMessage(".npcbot remove");
            handler->SendSysMessage("移除选定的npcbot,选择玩家将移除所有npcbot");
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
                    handler->SendSysMessage("成功移除NpcBots");
                    handler->SetSentErrorMessage(true);
                    return true;
                }
                handler->SendSysMessage("部分NpcBots没有被移除!");
                handler->SetSentErrorMessage(true);
                return false;
            }
            handler->SendSysMessage("没有找到NpcBots!");
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
                handler->SendSysMessage("成功移除NpcBot");
                handler->SetSentErrorMessage(true);
                return true;
            }
            handler->SendSysMessage("因为一些原因，未能移除NpcBot!");
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->SendSysMessage("您必须选择玩家或一个受控的NpcBot");
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
            handler->SendSysMessage("复活选中的npcbot. 如果选中玩家,则复活玩家所有的npcbots");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (Player* master = u->ToPlayer())
        {
            if (!master->HaveBot())
            {
                handler->PSendSysMessage("%s 没有npcbots!", master->GetName().c_str());
                handler->SetSentErrorMessage(true);
                return false;
            }

            master->GetBotMgr()->ReviveAllBots();
            handler->SendSysMessage("Npcbots 复活了");
            return true;
        }
        else if (Creature* bot = u->ToCreature())
        {
            if (bot->GetBotAI())
            {
                if (bot->IsAlive())
                {
                    handler->PSendSysMessage("%s 没有死亡", bot->GetName().c_str());
                    handler->SetSentErrorMessage(true);
                    return false;
                }

                BotMgr::ReviveBot(bot, (bot->GetBotOwner() == owner) ? owner->ToUnit() : bot->ToUnit());
                handler->PSendSysMessage("%s 复活了", bot->GetName().c_str());
                return true;
            }
        }

        handler->SendSysMessage("必须选择玩家或npcbot");
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
            handler->SendSysMessage("允许雇佣选定的非受控NpcBot");
            handler->SetSentErrorMessage(true);
            return false;
        }

        Creature* bot = cre->ToCreature();
        if (!bot || !bot->IsNPCBot() || bot->GetBotAI()->GetBotOwnerGuid())
        {
            handler->SendSysMessage("必须选定一个非受控NpcBot");
            handler->SetSentErrorMessage(true);
            return false;
        }

        BotMgr* mgr = owner->GetBotMgr();
        if (!mgr)
            mgr = new BotMgr(owner);

        if (mgr->AddBot(bot, false) == BOT_ADD_SUCCESS)
        {
            handler->PSendSysMessage("%s 现在是你的NpcBot", bot->GetName().c_str());
            return true;
        }

        handler->SendSysMessage("由于某些原因未能添加NpcBot!");
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

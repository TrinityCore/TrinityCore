////From:http://www.mangoscn.com/forum.php?mod=viewthread&tid=46&extra=page%3D3
////积分系统GM命令
//Index: Chat.cpp
//===================================================================
//--- Chat.cpp        (revision 29)
//+++ Chat.cpp        (working copy)
//@@ -110,6 +110,7 @@
//         { "titles",      SEC_MODERATOR,     &ChatHandler::HandleModifyKnownTitlesCommand, "",  NULL },
//         { "mount",       SEC_MODERATOR,     &ChatHandler::HandleModifyMountCommand,       "",  NULL },
//         { "honor",       SEC_MODERATOR,     &ChatHandler::HandleModifyHonorCommand,       "",  NULL },
//+        { "integral",    SEC_MODERATOR,     &ChatHandler::HandleModifyIntegralCommand,    "",  NULL }, //设置积分系统GM命令
//
//         { NULL,          0, NULL,                                        "",   NULL }
//     };
//Index: Chat.h
//===================================================================
//--- Chat.h        (revision 29)
//+++ Chat.h        (working copy)
//@@ -131,6 +131,7 @@
//         bool HandleModifySpellCommand(const char* args);
//         bool HandleModifyTalentCommand (const char* args);
//         bool HandleModifyHonorCommand (const char* args);
//+                bool HandleModifyIntegralCommand(const char* args);
//
//         bool HandleReloadCommand(const char* args);
//         bool HandleReloadAllCommand(const char* args);
//Index: Language.h
//===================================================================
//--- Language.h        (revision 29)
//+++ Language.h        (working copy)
//@@ -306,6 +306,7 @@
//#define LANG_COMMAND_SPAWNDIST           "Spawn distance changed to: %i"
//#define LANG_COMMAND_SPAWNTIME           "Spawn time changed to: %i"
//#define LANG_COMMAND_MODIFY_HONOR        "The honor of %s was set to %u!"
//+#define LANG_COMMAND_MODIFY_INTEGRAL     "The Integral points of %s was set to %u!"
//
//#define LANG_YOUR_CHAT_DISABLED          "Your chat has been disabled for %u minutes."
//#define LANG_YOU_DISABLE_CHAT            "You have disabled %s's chat for %u minutes."
//Index: Level3.cpp
//===================================================================
//--- Level3.cpp        (revision 29)
//+++ Level3.cpp        (working copy)
//@@ -4606,3 +4606,33 @@
//
//     return true;
//}
//+//积分功能GM命令开始
//+bool ChatHandler::HandleModifyIntegralCommand(const char * args) {
//+    if (!*args)
//+        return false;
//+    Player *target = getSelectedPlayer();
//+    if(!target)
//+    {
//+        SendSysMessage(LANG_PLAYER_NOT_FOUND);
//+        return true;
//+    }
//+        uint32 guid = 0;  //定义设置的用户ID
//+
//+        uint32 amount = (uint32)atoi(args);   //从游戏里面获得输入的积分点数值
//+    if (amount < 0 || amount > 999999)
//+    {
//+        SendSysMessage(LANG_BAD_VALUE);
//+        return true;
//+    }
//+
//+        loginDatabase.PExecute("UPDATE `account` SET `jf` = '%u' WHERE `id` = '%u'",amount,guid);
//+        loginDatabase.CommitTransaction();
//+
//+    PSendSysMessage(LANG_COMMAND_MODIFY_INTEGRAL, target->GetName(), amount);
//+
//+    return true;
//+}//设置积分系统GM命令结束
//
//
//然后还要在数据库里面加入
//INSERT INTO `command` VALUES ('modify integral', '1', '语法: .modify integral $amount');

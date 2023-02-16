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

// This is where scripts' loading functions should be declared:


void AddSC_GOMove_commandscript();  //Rocher2-gomove_master
void AddSC_XpWeekend();             //周末双倍经验
void AddSC_solocraft();             //单人随机地下城查找器脚本
void AddSC_SpellCraft();            //单人随机地下城查找器脚本
void AddSC_LeechCraft();            //单人随机地下城查找器脚本
void AddSC_CombatRatingCraft();     //单人随机地下城查找器脚本
void AddSC_Hastecraft();            //单人随机地下城查找器脚本
void AddLfgSoloScripts();           //单人随机地下城查找器脚本
void AddSC_custom_npcs();           //自定义NPC-好像是暴风城的龙王加冕事件
void AddSC_custom_player_script();  //单人随机地下城查找器脚本
void AddSC_GuardianAngel();         //守护神
void AddSC_onlogin_announcer();      //玩家欢迎信息
void AddSC_Boss_Announcer();        //boss击杀公告
void AddSC_PvP_System();            //pvp击杀公告


//void AddSC_debug_lfg();             //单人进地下城尝试, OpenLCore,已经自己通过配置实现,停用
//void AddSC_double_xp();             //周六、周天双倍经验, OpenLCore,和现有XpWeekend重复,故而停用
//void AddSC_start_equipment();       //OpenLCore,出生送装备
//void AddSC_quest_conversation();     //任务对话?           ////这货启用,会使服务端启动不了,千万别启用,谨记!



// The name of this function should match:
// void Add${NameOfDirectory}Scripts()



void AddCustomScripts()
{
    AddSC_GOMove_commandscript();
    AddSC_XpWeekend();              //周末双倍经验
    AddSC_solocraft();              //单人随机地下城查找器脚本
    AddSC_SpellCraft();             //单人随机地下城查找器脚本
    AddSC_LeechCraft();             //单人随机地下城查找器脚本
    AddSC_CombatRatingCraft();      //单人随机地下城查找器脚本
    AddSC_Hastecraft();             //单人随机地下城查找器脚本
    AddLfgSoloScripts();            //单人随机地下城查找器脚本
    AddSC_custom_player_script(),    //单人随机地下城查找器脚本
    AddSC_custom_npcs();            //自定义NPC-好像是暴风城的龙王加冕事件
    AddSC_custom_player_script();   //单人随机地下城查找器脚本
    AddSC_GuardianAngel();           //守护神
    AddSC_onlogin_announcer();      //玩家欢迎信息
    AddSC_Boss_Announcer();        //boss击杀公告
    AddSC_PvP_System();            //pvp击杀公告

    //AddSC_PvP_System();            //pvp击杀公告
   //AddSC_debug_lfg();              //单人进地下城尝试, OpenLCore,已经自己通过配置实现,停用
   //AddSC_double_xp();             //周六、周天双倍经验, OpenLCore,和现有XpWeekend重复,故而停用
   //AddSC_start_equipment();      //OpenLCore,出生送装备
   //AddSC_quest_conversation();      //任务对话?       //这货启用,会使服务端启动不了,千万别启用,谨记!
}

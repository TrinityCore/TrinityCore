
-- UNIVERSAL TELEPORTER SCRIPT
INSERT INTO `gossip_menu` VALUES (GOSSIP-ID HERE, 0);

INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES('GOSSIP-ID HERE','0','4','Stormwind teleportation','1','1','0','0','0','0','Teleport to Stormwind?');

INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES('GOSSIP-ID HERE','1','4','Orgrimmar','1','1','0','0','0','0','Teleport to Orgrimmar?');

SET @ENTRY := NPC ENTRY HERE;
UPDATE `creature_template` SET `npcflag` = 1, `AIName` = 'SmartAI' WHERE `entry` = @ENTRY;
UPDATE `creature_template` SET `gossip_menu_id`='GOSSIP-ID HERE' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY, 0, 0, 0, 62, 0, 100, 0, GOSSIP-ID HERE, 0, 0, 0, 62, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, -8833, 629, 94, 4, "Teleport to Stormwind"),
(@ENTRY, 0, 1, 0, 62, 0, 100, 0, GOSSIP-ID HERE, 1, 0, 0, 62, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 1630, -4374, 32, 4, "Teleport to Orgrimmar");
 
/*
 *GOSSIP_ICON_CHAT = 0, //white chat bubble 
 *GOSSIP_ICON_VENDOR = 1, //brown bag 
 *GOSSIP_ICON_TAXI = 2, //flight 
 *GOSSIP_ICON_TRAINER = 3, //book 
 *GOSSIP_ICON_INTERACT_1 = 4, //interaction wheel 
 *GOSSIP_ICON_INTERACT_2 = 5, //interaction wheel 
 *GOSSIP_ICON_MONEY_BAG = 6, //brown bag with yellow dot 
 *GOSSIP_ICON_TALK = 7, //white chat bubble with black dots 
 *GOSSIP_ICON_TABARD = 8, //tabard 
 *GOSSIP_ICON_BATTLE = 9, //two swords 
 *GOSSIP_ICON_DOT = 10, //yellow dot
*/

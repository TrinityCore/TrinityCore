-- Quests 24563, 24535
SET @ENTRY := 37552;
SET @GOSSIP := 37552;
SET @MENUID := 0;

DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Thalorien Dawnseeker - On gossip option 0 select - Close gossip'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,85,70265,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Thalorien Dawnseeker - On gossip option 0 select - Player cast credit on self'),
(@ENTRY,0,2,1,62,0,100,0,@GOSSIP,@MENUID+1,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Thalorien Dawnseeker - On gossip option 1 select - Close gossip');
UPDATE `creature_template` SET `gossip_menu_id` = @GOSSIP, `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` = @ENTRY;
REPLACE INTO `gossip_menu_option` (`menu_id`, `id`, `option_text`, `option_id`, `npc_option_npcflag`) VALUES (@GOSSIP, @MENUID, 'Examine the remains.', '1', '1');
REPLACE INTO `gossip_menu_option` (`menu_id`, `id`, `option_text`, `option_id`, `npc_option_npcflag`) VALUES (@GOSSIP, @MENUID+1, 'Examine the remains.', '1', '1');

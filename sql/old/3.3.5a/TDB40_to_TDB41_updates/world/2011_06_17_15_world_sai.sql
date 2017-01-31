-- Handler Marnlek SAI
SET @ENTRY  := 40204;
SET @GOSSIP := 11345;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,@GOSSIP,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Handler Marnlek - On gossip option 0 select - Close gossip'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,74978,3,0,0,0,0,7,0,0,0,0,0,0,0, 'Handler Marnlek - On gossip option 0 select - Cast Echo Isles: Unlearned Spy Frog Taxi on player'),
(@ENTRY,0,2,3,62,0,100,0,@GOSSIP,1,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Handler Marnlek - On gossip option 1 select - Close gossip'),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,11,75421,3,0,0,0,0,7,0,0,0,0,0,0,0, 'Handler Marnlek - On gossip option 1 select - Cast Echo Isles: Unlearned Troll Recruit Taxi on player'),
(@ENTRY,0,4,5,62,0,100,0,@GOSSIP,2,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Handler Marnlek - On gossip option 2 select - Close gossip'),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,11,75422,3,0,0,0,0,7,0,0,0,0,0,0,0, 'Handler Marnlek - On gossip option 2 select - Cast Echo Isles: Unlearned Troll Battle Taxi on player');
-- Cleanup gossip
UPDATE `gossip_menu_option` SET `action_script_id`=0 WHERE `menu_id`=@GOSSIP;
DELETE FROM `gossip_scripts` WHERE `id` IN (1134500,1134501,1134502);

-- Fix Injured Stormwind Infantry for Quest "Fear no evil"
SET @ENTRY := 50047;
UPDATE `creature_template` SET `unit_flags`=49920 WHERE `entry`=@ENTRY;
UPDATE `smart_scripts` SET `link`=5 WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=4;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id` IN (5,6);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,5,0,61,0,100,512,0,0,0,0,18,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured Stormwind Infantry - On Spellhit - Add unit_flag not selectable"),
(@ENTRY,0,6,0,58,0,100,512,9,50047,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured Stormwind Infantry - On WP end - Despawn");
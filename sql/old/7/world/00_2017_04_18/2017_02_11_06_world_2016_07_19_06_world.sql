-- 
SET @Drak := 26919;

-- Insert missing creature text for NPC 26919 Drak'aguul
DELETE FROM `creature_text` WHERE `entry` = @Drak;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@Drak, 0, 0, 'Dey be stronger then I expect mon, attack dem!', 12, 0, 100, 0, 0, 0, 28896, 0, "Drak'aguul - Between 0-30% Health - Call For Help"),
(@Drak, 1, 0, 'Wait for me orders, I handle dis myself!',       12, 0, 100, 0, 0, 0, 28897, 0, "Drak'aguul - On Aggro - Order soldiers to wait");

UPDATE `smart_scripts` SET `link`= 3 WHERE `entryorguid`= @Drak AND `source_type`= 0 AND `id`= 0;

DELETE FROM `smart_scripts` WHERE `entryorguid`= @Drak AND `source_type`= 0 AND `id` IN (3,4);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Drak, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Drak'aguul - On Aggro - Say Line 1"),
(@Drak, 0, 4, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 10000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Drak'aguul - On Aggro - Say Line 2");

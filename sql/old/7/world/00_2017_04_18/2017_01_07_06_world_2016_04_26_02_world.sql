--
SET @ENTRY := 8035;
-- Apply taunt sound effect instead of the Avatar of Hakkar's aggro sound
UPDATE `creature_text` SET `sound`=3216 WHERE `entry` = @ENTRY AND `groupid` = 1 AND `id` = 0;
-- Apply UNIT_FLAG_DISABLE_MOVE, UNIT_FLAG_PACIFIED, and UNIT_FLAG_DISARMED
-- Extra OR's are for at-a-glance convenience
UPDATE `creature_template` SET `unit_flags`= `unit_flags` | 4 | 131072 | 2097152 WHERE `Entry`= @ENTRY;
-- Inserting an SAI event to make Dark Iron Land Mines not detonate prematurely.
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dark Iron Land Mine - Out of Combat - Say Line 0'),
(@ENTRY,0,1,0,1,0,100,3,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dark Iron Land Mine - Out of Combat - Say Line 1'),
(@ENTRY,0,2,0,1,0,100,3,10000,10000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dark Iron Land Mine - Out of Combat - Say Line 2'),
(@ENTRY,0,3,0,1,0,100,3,10000,10000,0,0,19,131072,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dark Iron Land Mine - Out of Combat - Remove Pacified Flag after 10s'),
(@ENTRY,0,4,0,9,0,100,3,0,8,0,0,11,4043,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dark Iron Land Mine - Within 0-8 Range - Cast \'Detonation\''),
(@ENTRY,0,5,0,9,0,100,3,0,8,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dark Iron Land Mine - Within 0-8 Range - Despawn Instant');

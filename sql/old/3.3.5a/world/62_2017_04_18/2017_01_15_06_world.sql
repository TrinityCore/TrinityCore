-- Eye of the Citadel -- http://wotlk.openwow.com/npc=21134
-- Warlord Morkh SAI
SET @ENTRY := 16964;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,9000,17000,17000,11,34080,1,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Morkh - In Combat - Cast 'Riposte Stance'"),
(@ENTRY,0,1,0,0,0,100,0,7000,7000,8000,8000,11,11978,1,0,0,0,0,2,0,0,0,0,0,0,0,"Warlord Morkh - In Combat - Cast 'Kick'"),
(@ENTRY,0,2,3,2,0,100,1,0,20,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Morkh - Between 0-20% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,3,0,61,0,100,0,0,20,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Morkh - Between 0-20% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,4,5,6,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Warlord Morkh - On Just Died - Store Targetlist"),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,10,86039,21134,0,0,0,0,0,"Warlord Morkh - On Just Died - Send Target 1"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,86039,21134,0,0,0,0,0,"Warlord Morkh - On Just Died - Set Data 1 1");

-- Eye of the Citadel SAI
SET @ENTRY := 21134;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Eye of the Citadel - On Data Set 1 1 - Run Script"),
(@ENTRY,0,1,0,25,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eye of the Citadel - On Reset - Set Visibility Off");

-- Actionlist SAI
SET @ENTRY := 2113400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,3000,3000,0,0,1,0,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Eye of the Citadel - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,47,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eye of the Citadel - On Script - Set Visibility On"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,1,1,4000,0,0,0,0,12,1,0,0,0,0,0,0,"Eye of the Citadel - On Script - Say Line 1"),
(@ENTRY,9,3,0,0,0,100,0,4000,4000,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0,"Eye of the Citadel - On Script - Say Line 2"),
(@ENTRY,9,4,0,0,0,100,0,3000,3000,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eye of the Citadel - On Script - Set Visibility Off");

DELETE FROM `creature_text` WHERE `entry`=21134;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`, `TextRange`) VALUES 
(21134, 0, 0, 'A deep, bone chilling voice echoes from the %s...', 16, 0, 100, 0, 0, 0, 18774, 'Eye of the Citadel', 0),
(21134, 1, 0, 'How dare you trifle with my playthings, $n!', 12, 0, 100, 0, 0, 0, 18775, 'Eye of the Citadel', 0),
(21134, 2, 0, 'The orcs in my citadel will drink your blood and dovour you!', 12, 0, 100, 0, 0, 0, 18776, 'Eye of the Citadel', 0);

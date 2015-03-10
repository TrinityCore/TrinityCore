-- Fel Portal Alarm SAI
SET @ENTRY := 23310;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,46907,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fel Portal Alarm - On Respawn - Cast 'Boss Fel Portal State' (No Repeat)"),
(@ENTRY,0,1,0,38,0,100,0,1,1,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fel Portal Alarm - On Data Set 1 1 - Increment Phase"),
(@ENTRY,0,2,3,1,32,100,0,1000,1000,0,0,12,25003,5,120000,0,0,0,1,0,0,0,0,0,0,0,"Fel Portal Alarm - Out of Combat - Summon Creature 'Emissary of Hate' (Phase 32)"),
(@ENTRY,0,3,0,61,32,100,0,1000,1000,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fel Portal Alarm - Out of Combat - Set Event Phase 0 (Phase 32)");

DELETE FROM `creature` WHERE `id`=25003;

-- Irespeaker SAI
SET @ENTRY := 24999;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1500,3000,10000,15000,11,35913,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irespeaker - In Combat - Cast 'Fel Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,13000,16000,20000,35000,11,18267,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irespeaker - In Combat - Cast 'Curse of Weakness'"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,33,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Irespeaker - On Just Died - Quest Credit 'Kanrethad's Quest' (No Repeat)"),
(@ENTRY,0,3,0,6,0,100,0,5000,5000,10000,10000,45,1,1,0,0,0,0,10,79450,23310,0,0,0,0,0,"Irespeaker - On Just Died - Set Data 1 1");

-- Unleashed Hellion SAI
SET @ENTRY := 25002;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,1,0,0,0,0,33,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Unleashed Hellion - On Just Died - Quest Credit 'Kanrethad's Quest' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,18000,35000,11,11876,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unleashed Hellion - In Combat - Cast 'War Stomp'"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,12600,16000,11,20754,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unleashed Hellion - In Combat - Cast 'Rain of Fire'"),
(@ENTRY,0,3,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,79450,23310,0,0,0,0,0,"Unleashed Hellion - On Just Died - Set Data 1 1");

-- Emissary of Hate SAI
SET @ENTRY := 25003;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,15000,20000,11,25003,0,0,0,0,0,2,0,0,0,0,0,0,0,"Emissary of Hate - In Combat - Cast 'Mortar'"),
(@ENTRY,0,1,0,0,0,100,0,8000,10000,15000,20000,11,38611,0,0,0,0,0,2,0,0,0,0,0,0,0,"Emissary of Hate - In Combat - Cast 'Flame Wave'"),
(@ENTRY,0,2,0,54,0,100,0,0,0,0,0,89,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Emissary of Hate - On Just Summoned - Start Random Movement");

-- SAI for Crusader Lamoof
SET @ENTRY := 28141;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`) VALUES (@ENTRY,7);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,1,8,0,100,0,50662,0,0,0,11,50673,4,0,0,0,0,7,0,0,0,0,0,0,0, 'Crusader Lamoof - On spell hit - cast Force Summon Crusader Lamoof'),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,11,50679,4,0,0,0,0,7,0,0,0,0,0,0,0, 'Crusader Lamoof - On spell hit - cast Lamoof Dying'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Lamoof - On spell hit - despawn');

-- SAI for Crusader Jonothan
SET @ENTRY := 28133;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`) VALUES (@ENTRY,7);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,1,8,0,100,0,50662,0,0,0,11,50663,4,0,0,0,0,7,0,0,0,0,0,0,0, 'Crusader Jonothan - On spell hit - cast Force Summon Crusader LeCraft'),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,11,50666,4,0,0,0,0,7,0,0,0,0,0,0,0, 'Crusader Jonothan - On spell hit - cast Jonothan Dying'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Jonothan - On spell hit - despawn');

-- SAI for Crusader Josephine
SET @ENTRY := 28143;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`) VALUES (@ENTRY,7);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,1,8,0,100,0,50662,0,0,0,11,50691,4,0,0,0,0,7,0,0,0,0,0,0,0, 'Crusader Josephine - On spell hit - cast Force Summon Crusader Josephine'),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,11,50693,4,0,0,0,0,7,0,0,0,0,0,0,0, 'Crusader Josephine - On spell hit - cast Josephine Dying'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crusader Josephine - On spell hit - despawn');

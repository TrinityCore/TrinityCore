-- DB/Quest: Into the Soulgrind

DELETE FROM `gameobject` WHERE  `guid`=27618;

DELETE FROM `event_scripts` WHERE `id`=14739;
INSERT INTO `event_scripts` VALUES (14739, 0, 10, 23019, 500000, 0, 3535.111, 5590.628, 0.3859383, 0.7853982);

DELETE FROM `creature_template_addon` WHERE `entry` IN (22912, 23019, 23037, 22910);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(22912, 0, 0x0, 0x1, ''), -- 22912 - 39916
(23019, 0, 0x0, 0x1, '39918'), -- 23019 - 39918
(23037, 0, 0x0, 0x1, '39936'), -- 23037 - 39936
(22910, 0, 0x0, 0x1, '39947'); -- 22910 - 39947

-- Skulloc Soulgrinder SAI
SET @ENTRY := 22910;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,18,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skulloc Soulgrinder - On Just Summoned - Set Flag Not Selectable"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skulloc Soulgrinder - On Just Summoned - Set Reactstate Passive"),
(@ENTRY,0,2,0,8,0,100,0,39920,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Skulloc Soulgrinder - On Spellhit 'Soulgrinder Ritual Visual ( beam)' - Run Script"),
(@ENTRY,0,3,4,6,0,100,0,0,0,0,0,18,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skulloc Soulgrinder - On Just Died - Set Flag Not Selectable"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,11,39909,2,0,0,0,0,1,0,0,0,0,0,0,0,"Skulloc Soulgrinder - On Just Died - Cast 'Skulloc: Summon Skulloc's Soul Chest'"),
(@ENTRY,0,5,0,0,0,100,0,30000,30000,50000,50000,11,39622,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skulloc Soulgrinder - In Combat - Cast 'Banish'"),
(@ENTRY,0,6,0,0,0,100,0,12000,12000,24000,30000,11,39621,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skulloc Soulgrinder - In Combat - Cast 'Corruption'"),
(@ENTRY,0,7,0,0,0,100,0,20000,20000,20000,20000,11,39620,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skulloc Soulgrinder - In Combat - Cast 'Summon Ogre Ghost'");

-- Actionlist SAI
SET @ENTRY := 2291000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,6000,6000,0,0,19,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skulloc Soulgrinder - On Script - Remove Flag Not Selectable"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skulloc Soulgrinder - On Script - Set Reactstate Aggressive"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,150,0,0,0,0,0,0,"Skulloc Soulgrinder - On Script - Start Attacking"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skulloc Soulgrinder - On Script - Say Line 0");

DELETE FROM `creature_text` WHERE `entry`=22910;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(22910, 0, 0, 'Argh!  I will shred your soul and grind it to dust!', 14, 0, 100, 0, 0, 0, 20726, 'Skulloc Soulgrinder');

-- The Soulgrinder SAI
SET @ENTRY := 23019;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,2,54,0,100,0,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"The Soulgrinder - On Just Summoned - Run Script"),
(@ENTRY,0,1,0,6,0,100,0,0,0,0,0,6,11000,0,0,0,0,0,17,0,50,0,0,0,0,0,"The Soulgrinder - On Just Died - Fail Quest 'Into the Soulgrinder'"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,102,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Soulgrinder - On Just Summoned - Set Health Regeneration Off"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,3,0,17612,0,0,0,0,1,0,0,0,0,0,0,0,"The Soulgrinder - On Just Summoned - Morph To Model 17612");

-- Actionlist SAI
SET @ENTRY := 2301900;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Soulgrinder - On Script - Set Reactstate Passive"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,11,39918,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Soulgrinder - On Script - Cast 'Soulgrinder Ritual Visual ( in progress)'"),
(@ENTRY,9,2,0,0,0,100,0,6000,6000,0,0,12,22912,3,120000,0,0,0,8,0,0,0,3525.13,5573.12,-1.62298,6.12611,"The Soulgrinder - On Script - Summon Creature 'Sundered Spirit'"),
(@ENTRY,9,3,0,0,0,100,0,6000,6000,0,0,12,22912,3,120000,0,0,0,8,0,0,0,3558.61,5543.98,-2.24089,0.994838,"The Soulgrinder - On Script - Summon Creature 'Sundered Spirit'"),
(@ENTRY,9,4,0,0,0,100,0,6000,6000,0,0,12,22912,3,120000,0,0,0,8,0,0,0,3535.11,5590.63,0.385938,0.785398,"The Soulgrinder - On Script - Summon Creature 'Sundered Spirit'"),
(@ENTRY,9,5,0,0,0,100,0,6000,6000,0,0,12,22912,3,120000,0,0,0,8,0,0,0,3557.25,5591.2,-2.99395,3.01942,"The Soulgrinder - On Script - Summon Creature 'Sundered Spirit'"),
(@ENTRY,9,6,0,0,0,100,0,6000,6000,0,0,12,22912,3,120000,0,0,0,8,0,0,0,3557.08,5612.43,-4.56236,1.51844,"The Soulgrinder - On Script - Summon Creature 'Sundered Spirit'"),
(@ENTRY,9,7,0,0,0,100,0,7000,7000,0,0,12,23037,3,500000,0,0,0,8,0,0,0,3491.22,5529.02,17.1434,6.19592,"The Soulgrinder - On Script - Summon Creature 'Soulgrinder Ritual Bunny'"),
(@ENTRY,9,8,0,0,0,100,0,6000,6000,0,0,12,22910,3,500000,0,0,0,8,0,0,0,3478.56,5550.74,7.8388,0.366519,"The Soulgrinder - On Script - Summon Creature 'Skulloc Soulgrinder'"),
(@ENTRY,9,9,0,0,0,100,0,6000,6000,0,0,12,22912,3,120000,0,0,0,8,0,0,0,3491.22,5529.02,17.1434,6.19592,"The Soulgrinder - On Script - Summon Creature 'Sundered Spirit'"),
(@ENTRY,9,10,0,0,0,100,0,6000,6000,0,0,12,22912,3,120000,0,0,0,8,0,0,0,3542.2,5608.06,-3.37805,0.15708,"The Soulgrinder - On Script - Summon Creature 'Sundered Spirit'"),
(@ENTRY,9,11,0,0,0,100,0,6000,6000,0,0,12,22912,3,120000,0,0,0,8,0,0,0,3542.22,5573.4,-2.64414,4.27606,"The Soulgrinder - On Script - Summon Creature 'Sundered Spirit'"),
(@ENTRY,9,12,0,0,0,100,0,6000,6000,0,0,12,22912,3,120000,0,0,0,8,0,0,0,3542.2,5608.06,-3.37805,0.15708,"The Soulgrinder - On Script - Summon Creature 'Sundered Spirit'"),
(@ENTRY,9,13,0,0,0,100,0,7000,7000,0,0,12,23037,3,500000,0,0,0,8,0,0,0,3466.883,5566.282,20.1,0.369,"The Soulgrinder - On Script - Summon Creature 'Soulgrinder Ritual Bunny'"),
(@ENTRY,9,14,0,0,0,100,0,6000,6000,0,0,12,22912,3,120000,0,0,0,8,0,0,0,3542.2,5608.06,-3.37805,0.15708,"The Soulgrinder - On Script - Summon Creature 'Sundered Spirit'"),
(@ENTRY,9,15,0,0,0,100,0,6000,6000,0,0,12,22912,3,120000,0,0,0,8,0,0,0,3542.22,5573.4,-2.64414,4.27606,"The Soulgrinder - On Script - Summon Creature 'Sundered Spirit'"),
(@ENTRY,9,16,0,0,0,100,0,6000,6000,0,0,12,22912,3,120000,0,0,0,8,0,0,0,3542.2,5608.06,-3.37805,0.15708,"The Soulgrinder - On Script - Summon Creature 'Sundered Spirit'"),
(@ENTRY,9,17,0,0,0,100,0,6000,6000,0,0,12,22912,3,120000,0,0,0,8,0,0,0,3542.22,5573.4,-2.64414,4.27606,"The Soulgrinder - On Script - Summon Creature 'Sundered Spirit'"),
(@ENTRY,9,18,0,0,0,100,0,6000,6000,0,0,12,22912,3,120000,0,0,0,8,0,0,0,3542.2,5608.06,-3.37805,0.15708,"The Soulgrinder - On Script - Summon Creature 'Sundered Spirit'"),
(@ENTRY,9,19,0,0,0,100,0,7000,7000,0,0,12,23037,3,500000,0,0,0,8,0,0,0,3515.02,5524.39,16.8927,3.56047,"The Soulgrinder - On Script - Summon Creature 'Soulgrinder Ritual Bunny'"),
(@ENTRY,9,20,0,0,0,100,0,6000,6000,0,0,12,22912,3,120000,0,0,0,8,0,0,0,3542.2,5608.06,-3.37805,0.15708,"The Soulgrinder - On Script - Summon Creature 'Sundered Spirit'"),
(@ENTRY,9,21,0,0,0,100,0,6000,6000,0,0,12,22912,3,120000,0,0,0,8,0,0,0,3542.22,5573.4,-2.64414,4.27606,"The Soulgrinder - On Script - Summon Creature 'Sundered Spirit'"),
(@ENTRY,9,22,0,0,0,100,0,6000,6000,0,0,12,22912,3,120000,0,0,0,8,0,0,0,3542.2,5608.06,-3.37805,0.15708,"The Soulgrinder - On Script - Summon Creature 'Sundered Spirit'"),
(@ENTRY,9,23,0,0,0,100,0,6000,6000,0,0,12,22912,3,120000,0,0,0,8,0,0,0,3542.22,5573.4,-2.64414,4.27606,"The Soulgrinder - On Script - Summon Creature 'Sundered Spirit'"),
(@ENTRY,9,24,0,0,0,100,0,6000,6000,0,0,12,22912,3,120000,0,0,0,8,0,0,0,3542.22,5573.4,-2.64414,4.27606,"The Soulgrinder - On Script - Summon Creature 'Sundered Spirit'"),
(@ENTRY,9,25,0,0,0,100,0,7000,7000,0,0,12,23037,3,500000,0,0,0,8,0,0,0,3468.82,5581.41,17.5205,0.0174533,"The Soulgrinder - On Script - Summon Creature 'Soulgrinder Ritual Bunny'"), -- X: 
(@ENTRY,9,26,0,0,0,100,0,6000,6000,0,0,12,22912,3,120000,0,0,0,8,0,0,0,3542.22,5573.4,-2.64414,4.27606,"The Soulgrinder - On Script - Summon Creature 'Sundered Spirit'"),
(@ENTRY,9,27,0,0,0,100,0,6000,6000,0,0,12,22912,3,120000,0,0,0,8,0,0,0,3542.2,5608.06,-3.37805,0.15708,"The Soulgrinder - On Script - Summon Creature 'Sundered Spirit'"),
(@ENTRY,9,28,0,0,0,100,0,6000,6000,0,0,12,22912,3,120000,0,0,0,8,0,0,0,3542.22,5573.4,-2.64414,4.27606,"The Soulgrinder - On Script - Summon Creature 'Sundered Spirit'"),
(@ENTRY,9,29,0,0,0,100,0,6000,6000,0,0,12,22912,3,120000,0,0,0,8,0,0,0,3542.2,5608.06,-3.37805,0.15708,"The Soulgrinder - On Script - Summon Creature 'Sundered Spirit'"),
(@ENTRY,9,30,0,0,0,100,0,6000,6000,0,0,12,22912,3,120000,0,0,0,8,0,0,0,3542.22,5573.4,-2.64414,4.27606,"The Soulgrinder - On Script - Summon Creature 'Sundered Spirit'"),
(@ENTRY,9,31,0,0,0,100,0,5000,5000,0,0,45,1,1,0,0,0,0,9,23037,0,100,0,0,0,0,"The Soulgrinder - On Script - Set Data 1 1"),
(@ENTRY,9,32,0,0,0,100,0,0,0,0,0,11,39920,0,0,0,0,0,19,22910,100,0,0,0,0,0,"The Soulgrinder - On Script - Cast 'Soulgrinder Ritual Visual ( beam)'"),
(@ENTRY,9,33,0,0,0,100,0,6000,6000,0,0,92,0,39920,1,0,0,0,1,0,0,0,0,0,0,0,"The Soulgrinder - On Script - Interrupt Spell 'Soulgrinder Ritual Visual ( beam)'");

-- Sundered Spirit SAI
SET @ENTRY := 22912;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,25,0,100,0,0,0,0,0,11,39916,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sundered Spirit - On Reset - Cast 'Soulgrinder Ghost Transform'"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,11,17321,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sundered Spirit - On Reset - Cast 'Spirit Spawn-in'"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Sundered Spirit - On Reset - Run Script");

-- Actionlist SAI
SET @ENTRY := 2291200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,49,0,0,0,0,0,0,19,23019,100,0,0,0,0,0,"On Script - Start Attacking");

-- Soulgrinder Ritual Bunny SAI
SET @ENTRY := 23037;
UPDATE `creature_template` SET `InhabitType`=4, `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2000,2000,0,0,11,39920,0,0,0,0,0,19,23019,100,0,0,0,0,0,"Soulgrinder Ritual Bunny - Out of Combat - Cast 'Soulgrinder Ritual Visual ( beam)'"),
(@ENTRY,0,1,0,38,0,100,0,1,1,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Soulgrinder Ritual Bunny - On Data Set 1 1 - Despawn Instant");

SET @GUID=12481;
DELETE FROM `creature` WHERE `guid`=@GUID; 
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `curhealth`, `spawndist`, `MovementType`) VALUES
(@GUID, 23037, 530, 1, 1, 3535.15, 5590.769,  0.177, 3.89, 180, 42, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` IN (@GUID);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(@GUID,0,0,0,1,0,'');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-@GUID,0,0,0,25,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Soulgrinder Ritual Bunny - On Reset  - react passif (dummy to overwrite the Entry SAI)");

-- Sundered Ghost SAI
SET @ENTRY := 24039;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,25,0,100,0,0,0,0,0,11,39916,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sundered Ghost - On Reset - Cast 'Soulgrinder Ghost Transform'"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,11,17321,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sundered Ghost - On Reset - Cast 'Spirit Spawn-in'"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Sundered Ghost - On Reset - Start Attacking");

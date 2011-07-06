-- Add missing Invisible Stalker (Floating)
SET @GUID := 85175; -- 2 Required
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+1; 
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`) VALUES
(@GUID,23033,571,1,1,0,0,3799.331,3428.748,92.80447,3.804818,120,0,0,1,0,0,0),
(@GUID+1,23033,571,1,1,0,0,3789.681,3434.306,92.37619,4.764749,120,0,0,1,0,0,0);
-- High Priest Talet-Kha Fixup
SET @ENTRY  := 26073; -- NPC entry
SET @SPELL1 := 45492; -- Shadow Nova
SET @SPELL2 := 11640; -- Renew         cast once below 45%
SET @SPELL3 := 15587; -- Mind Blast    cast below 45% after renew 
UPDATE `creature` SET `modelid`=0,`spawndist`=0,`MovementType`=0 WHERE `id`=@ENTRY;
DELETE FROM `creature_addon` WHERE `guid`=85240;
DELETE FROM `creature_template_addon` WHERE `entry`=26073;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`) VALUES (26073,1,1);
-- SAI for High Priest Talet-Kha
UPDATE `creature_template` SET `speed_run`=1,`faction_H`=21,`InhabitType`=7,`AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Talet-Kha - On spawn - Set React State civilian'),
(@ENTRY,0,1,2,1,0,100,1,1000,1000,1000,1000,70,0,0,0,0,0,0,10,85098,25422,0,0,0,0,0, 'High Priest Talet-Kha - OOC - Respawn Mystical Webbing'),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,85098,25422,0,0,0,0,0, 'High Priest Talet-Kha - OOC - Set data Mystical Webbing'),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,70,0,0,0,0,0,0,10,85118,25422,0,0,0,0,0, 'High Priest Talet-Kha - OOC - Respawn Mystical Webbing'),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,85118,25422,0,0,0,0,0, 'High Priest Talet-Kha - OOC - Set data Mystical Webbing'),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,85175,23033,0,0,0,0,0, 'High Priest Talet-Kha - OOC - Set data Invisible Stalker'),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,85176,23033,0,0,0,0,0, 'High Priest Talet-Kha - OOC - Set data Invisible Stalker'),
(@ENTRY,0,7,0,1,0,100,0,3000,3000,3000,3000,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Talet-Kha - OOC - Set phase 1'),
(@ENTRY,0,8,0,23,1,100,1,45497,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Talet-Kha - On Aura missing - Run Script (Phase 1)'),
(@ENTRY,0,9,10,2,1,100,0,0,45,0,0,11,11640,1,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Talet-Kha - Health 45% - Cast Renew on self'),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Talet-Kha - OOC - Set phase 2'),
(@ENTRY,0,11,0,0,2,100,0,1500,1500,1500,1500,11,15587,0,0,0,0,0,2,0,0,0,0,0,0,0, 'High Priest Talet-Kha - Combat - Cast Mind Blast on victim (Phase 2)'),
(@ENTRY*100,9,0,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Talet-Kha - script - Text 0'),
(@ENTRY*100,9,1,0,0,0,100,0,500,500,0,0,69,0,0,0,0,0,0,1,0,0,0,3788.444,3418.249,85.05618,0, 'High Priest Talet-Kha - script - Move to'),
(@ENTRY*100,9,2,0,0,0,100,0,500,500,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,1.1672, 'High Priest Talet-Kha - script - turn to'),
(@ENTRY*100,9,3,0,0,0,100,0,1500,1500,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Talet-Kha - script - Bytes1 set to 0'),
(@ENTRY*100,9,4,0,0,0,100,0,100,100,0,0,19,33555200,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Talet-Kha - script - Remove unitflags'),
(@ENTRY*100,9,5,0,0,0,100,0,100,100,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Talet-Kha - script - Set React State Hostile'),
(@ENTRY*100,9,6,0,0,0,100,0,100,100,0,0,11,@SPELL1,1,0,0,0,0,1,0,0,0,0,0,0,0, 'High Priest Talet-Kha - script - Aura self');
-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry` IN (26073);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(26073,0,0, 'Who disturbs my meditation?!',1,7,100,15,0,0, 'High Priest Talet-Kha');
-- SAI for Mystical Webbing
SET @ENTRY := 25422; -- NPC entry
SET @CHANNEL := 45497; -- Web Beam
SET @TARGET  := 26073; -- High Priest Talet-Kha
UPDATE `creature_template` SET `faction_H`=21,`AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (-85098,-85118);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-85098,0,0,0,11,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mystical Webbing - On spawn - Set React State civilian'),
(-85098,0,1,0,1,0,100,1,1000,1000,1000,1000,11,@CHANNEL,2,0,0,0,0,11,@TARGET,40,0,0,0,0,0, 'Mystical Webbing - On spawn & reset - Web Beam'),
(-85098,0,2,0,6,0,100,1,0,0,0,0,45,0,2,0,0,0,0,10,85176,23033,0,0,0,0,0, 'Mystical Webbing - On death - set data 0 2 Invisible Stalker'),
(-85098,0,3,4,38,0,100,0,0,1,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Invisible Stalker (Floating) - On dataset 0 1 - set data 0 0'),
(-85098,0,4,0,61,0,100,0,0,0,0,0,70,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Invisible Stalker (Floating) - On dataset 0 1 - reset AI'),
(-85118,0,0,0,11,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mystical Webbing - On spawn - Set React State civilian'),
(-85118,0,1,0,1,0,100,1,1000,1000,1000,1000,11,@CHANNEL,2,0,0,0,0,11,@TARGET,40,0,0,0,0,0, 'Mystical Webbing - On spawn & reset - Web Beam'),
(-85118,0,2,0,6,0,100,1,0,0,0,0,45,0,2,0,0,0,0,10,85175,23033,0,0,0,0,0, 'Mystical Webbing - On death - set data 0 2 Invisible Stalker'),
(-85118,0,3,4,38,0,100,0,0,1,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Invisible Stalker (Floating) - On dataset 0 1 - set data 0 0'),
(-85118,0,4,0,61,0,100,0,0,0,0,0,70,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Invisible Stalker (Floating) - On dataset 0 1 - reset AI');
-- SAI for Invisible Stalker (Floating)
SET @ENTRY := 23033; -- NPC entry
SET @CHANNEL := 45497; -- Web Beam
SET @TARGET  := 26073; -- High Priest Talet-Kha
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (-85175,-85176);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Invisible Stalker (Floating)
(-85175,0,0,0,38,0,100,0,0,1,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Invisible Stalker (Floating) - On dataset 0 1 - Set Phase 1'),
(-85175,0,1,0,38,0,100,0,0,2,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Invisible Stalker (Floating) - On dataset 0 2 - Set Phase 2'),
(-85175,0,2,3,1,1,100,0,0,0,0,0,11,@CHANNEL,2,0,0,0,0,11,@TARGET,40,0,0,0,0,0, 'Invisible Stalker (Floating) - OOC - Cast Web Beam on target (Phase 1)'),
(-85175,0,3,4,61,1,100,0,0,0,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Invisible Stalker (Floating) - OOC - Set data 0 0 (Phase 1)'),
(-85175,0,4,0,61,1,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Invisible Stalker (Floating) - OOC - Set Phase 0 (Phase 1)'),
(-85175,0,5,6,1,2,100,0,0,0,0,0,92,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Invisible Stalker (Floating) - OOC - Stop casting (Phase 2)'),
(-85175,0,6,0,61,2,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Invisible Stalker (Floating) - OOC - Set Phase 0 (Phase 2)'),
-- Invisible Stalker (Floating)
(-85176,0,0,0,38,0,100,0,0,1,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Invisible Stalker (Floating) - On dataset 0 1 - Set Phase 1'),
(-85176,0,1,0,38,0,100,0,0,2,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Invisible Stalker (Floating) - On dataset 0 2 - Set Phase 2'),
(-85176,0,2,3,1,1,100,0,0,0,0,0,11,@CHANNEL,2,0,0,0,0,11,@TARGET,40,0,0,0,0,0, 'Invisible Stalker (Floating) - OOC - Cast Web Beam on target (Phase 1)'),
(-85176,0,3,4,61,1,100,0,0,0,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Invisible Stalker (Floating) - OOC - Set data 0 0 (Phase 1)'),
(-85176,0,4,0,61,1,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Invisible Stalker (Floating) - OOC - Set Phase 0 (Phase 1)'),
(-85176,0,5,6,1,2,100,0,0,0,0,0,92,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Invisible Stalker (Floating) - OOC - Stop casting (Phase 2)'),
(-85176,0,6,0,61,2,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Invisible Stalker (Floating) - OOC - Set Phase 0 (Phase 2)');

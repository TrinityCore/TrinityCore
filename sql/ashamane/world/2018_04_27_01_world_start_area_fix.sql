-- Blood Elf start area fix
SET @GUID := 30000000;
DELETE FROM `creature` WHERE `id`=63332;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@GUID, 63332, 530, 0, 0, 1, 0, 0, 0, -1, 0, 1, 10384.8, -6408.31, 38.5308, 3.26302, 300, 0, 0, 24154, 0, 0, 0, 0, 0, 0, 0, '', 0);
DELETE FROM `gameobject` WHERE `id`=176767;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`,`isActive`,`ScriptName`,`VerifiedBuild`) VALUES
(165646, 176767, 0, 28, 2298, 1, 0, 0, 0, -1, 1262.98, -2563.07, 96.8451, 0.479964, 0, 0, 0.237685, 0.971342, 300, 255, 1, 0, '', 0);
UPDATE `creature_template` SET `InhabitType` = 1 WHERE `entry` = 15650;
DELETE FROM `creature_queststarter` WHERE `id`=15279 AND `quest`=10068;
SET @GUID := 30000002;
DELETE FROM `creature` WHERE `id`=27946;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@GUID+1, 27946, 530, 0, 0, 1, 0, 0, 0, -1, 0, 0, 8737.98, -6650.85, 70.4018, 5.61768, 300, 0, 0, 7880, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@GUID+2, 27946, 1, 405, 4803, 1, 0, 0, 0, -1, 29363, 0, -431.809, 2246.06, 93.0752, 3.97935, 300, 3, 0, 232470, 0, 1, 0, 0, 0, 0, 0, '', 0),
(@GUID+3, 27946, 0, 4, 5083, 1, 0, 0, 0, -1, 29363, 0, -12360.9, -3062.63, 90.8148, 1.16937, 300, 3, 0, 232470, 0, 1, 0, 0, 0, 0, 0, '', 0),
(@GUID+4, 27946, 530, 0, 0, 1, 0, 0, 0, -1, 0, 0, 9501.25, -6758.82, 17.0621, 4.68209, 300, 0, 0, 7880, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@GUID+5, 27946, 530, 3430, 3430, 1, 0, 0, 0, -1, 0, 0, 9379.6, -7169.83, 9.07374, 3.03163, 900, 0, 0, 232470, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@GUID+6, 27946, 530, 3430, 3430, 1, 0, 0, 0, -1, 0, 0, 9378.85, -7162.24, 8.88681, 3.16111, 900, 0, 0, 232470, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@GUID+7, 27946, 530, 0, 0, 1, 0, 0, 0, -1, 0, 0, 9509.63, -6764.39, 16.5905, 4.04356, 300, 0, 0, 7880, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@GUID+8, 27946, 530, 0, 0, 1, 0, 0, 0, -1, 0, 0, 8744.49, -6646.54, 70.6934, 4.73062, 300, 0, 0, 7880, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@GUID+9, 27946, 530, 3433, 3488, 1, 0, 0, 0, -1, 0, 0, 7599.98, -6778.44, 86.4116, 4.19394, 900, 0, 0, 232470, 0, 0, 0, 0, 0, 0, 0, '', 0),
(@GUID+10, 27946, 530, 3433, 3488, 1, 0, 0, 0, -1, 0, 0, 7592.39, -6776.33, 86.834, 4.83017, 900, 0, 0, 232470, 0, 0, 0, 0, 0, 0, 0, '', 0);

UPDATE `creature_template` SET `InhabitType` = 1 WHERE `entry` = 15649;
 UPDATE `creature_loot_template` SET `Chance` = '48' WHERE `Entry` = '15651' AND `Item` = '20772'; 
 UPDATE `creature_loot_template` SET `Chance` = '48' WHERE `Entry` = '15652' AND `Item` = '20772'; 
 UPDATE `creature_loot_template` SET `Chance` = '48' WHERE `Entry` = '44793' AND `Item` = '20772'; 
 UPDATE `creature_loot_template` SET `Chance` = '48' WHERE `Entry` = '35245' AND `Item` = '20772'; 

SET @ENTRY := 15651;
UPDATE `creature_template` SET `AIName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;

SET @GUID := 30000013;
DELETE FROM `creature` WHERE `id`=19456;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@GUID, 19456, 530, 0, 0, 1, 0, 0, 0, -1, 0, 0, 8203.91, -6325.88, 64.5093, 0.682694, 300, 0, 0, 308, 0, 0, 0, 0, 0, 0, 0, '', 0);
UPDATE `creature_template` SET `modelid2` = 0 WHERE `entry` = 78116;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 19456;
DELETE FROM `quest_objectives` WHERE `ID` = '289859'; 
-- Angershade SAI
SET @ENTRY := 15656;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angershade - At 30% HP - Say Line 0");
UPDATE `quest_objectives` SET `ObjectID` = '0' , `Amount` = '0' WHERE `ID` = '260310'; 
 UPDATE `smart_scripts` SET `event_flags` = '1' WHERE `entryorguid` = '3727' AND `source_type` = '0' AND `id` = '0' AND `link` = '1'; 
UPDATE `smart_scripts` SET `event_flags` = '1' WHERE `entryorguid` = '2464' AND `source_type` = '0' AND `id` = '3' AND `link` = '4'; 
 UPDATE `smart_scripts` SET `event_flags` = '1' WHERE `entryorguid` = '2249' AND `source_type` = '0' AND `id` = '0' AND `link` = '1'; 
 UPDATE `smart_scripts` SET `event_flags` = '1' WHERE `entryorguid` = '17086' AND `source_type` = '0' AND `id` = '0' AND `link` = '1'; 
UPDATE `smart_scripts` SET `event_flags` = '1' WHERE `entryorguid` = '15656' AND `source_type` = '0' AND `id` = '0' AND `link` = '1'; 
 UPDATE `smart_scripts` SET `event_flags` = '1' WHERE `entryorguid` = '2791' AND `source_type` = '0' AND `id` = '0' AND `link` = '1'; 
 UPDATE `smart_scripts` SET `event_flags` = '1' WHERE `entryorguid` = '2791' AND `source_type` = '0' AND `id` = '0' AND `link` = '1'; 
 SET @GUID := 30000014;
DELETE FROM `creature` WHERE `id`=15408;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@GUID, 15408, 530, 0, 0, 1, 0, 0, 0, -1, 0, 1, 8692.03, -7940.71, 153.137, 3.46282, 300, 0, 0, 236, 191, 0, 0, 0, 0, 0, 0, '', 0);
UPDATE `creature_template` SET `modelid2` = 0 WHERE `entry` = 78116;
DELETE FROM `quest_objectives` WHERE `ID` = '260060'; 
UPDATE `quest_objectives` SET `ObjectID` = '17086' , `Amount` = '5' WHERE `ID` = '260059'; 
SET @GUID := 30000015;
DELETE FROM `creature` WHERE `id`=16196;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(@GUID, 16196, 530, 0, 0, 1, 0, 0, 0, -1, 0, 0, 8117.47, -6900.95, 70.3464, 0.888286, 300, 0, 0, 308, 0, 0, 0, 0, 0, 0, 0, '', 0);
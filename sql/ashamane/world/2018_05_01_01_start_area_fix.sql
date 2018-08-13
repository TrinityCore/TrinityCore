--  Worgen start area fix

DELETE FROM `creature_addon` WHERE (`guid`=20556362);

UPDATE `creature_template` SET `KillCredit1` = 44175 WHERE `entry` = 35118;

DELETE FROM `creature` WHERE `id`=50371;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(20556528, 50371, 654, 4755, 4757, 1, 0, 170, 0, -1, 0, 0, -1755.07, 1418.04, 24.1141, 0.349066, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 25383),
(210115267, 50371, 654, 0, 0, 1, 0, 0, 0, -1, 0, 1, -1755.14, 1418.13, 23.962, 6.2479, 300, 0, 0, 392, 0, 0, 0, 0, 0, 0, 0, '', 0);

DELETE FROM `creature` WHERE `id`=39095;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(20556539, 39095, 654, 4755, 4757, 1, 0, 0, 0, -1, 0, 0, -1735.67, 1437.48, 52.3708, 1.93731, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 25383),
(20556527, 39095, 654, 4755, 4757, 1, 0, 0, 0, -1, 0, 0, -1669.83, 1435.02, 52.3705, 0.453786, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 25383),
(20556526, 39095, 654, 4755, 4757, 1, 0, 0, 0, -1, 0, 0, -1715.15, 1435.7, 21.752, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 25383),
(20556517, 39095, 654, 4755, 4757, 1, 0, 0, 0, -1, 0, 0, -1738.15, 1408.92, 21.752, 0.174533, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 25383),
(20556471, 39095, 654, 4755, 4757, 1, 0, 0, 0, -1, 0, 0, -1701.42, 1378.95, 23.0424, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 25383),
(20556467, 39095, 654, 4755, 0, 1, 0, 0, 0, -1, 0, 0, -1686.36, 1381.31, 52.3796, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 25383),
(20556294, 39095, 654, 4755, 4756, 1, 0, 169, 0, -1, 0, 0, -1396.68, 1445.74, 36.044, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 25383),
(20556270, 39095, 654, 4755, 4756, 1, 0, 169, 0, -1, 0, 0, -1404.51, 1435.07, 35.6393, 3.80482, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 25383);

DELETE FROM `creature` WHERE `id`=35124;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(20556537, 35124, 654, 4755, 4757, 1, 0, 0, 0, -1, 0, 0, -1678.51, 1438.79, 52.3704, 6.25315, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 25383);

DELETE FROM `creature` WHERE `id`=35077;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(20556540, 35077, 654, 4755, 4757, 1, 0, 0, 0, -1, 0, 0, -1679.73, 1442.12, 52.3705, 0.750492, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 25383);

DELETE FROM `creature` WHERE `id`=35123;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(20556536, 35123, 654, 4755, 4757, 1, 0, 0, 0, -1, 0, 0, -1682.8, 1441.26, 52.3705, 5.48033, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 25383);

DELETE FROM `creature` WHERE `id`=35081;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(20556541, 35081, 654, 4755, 4757, 1, 0, 0, 0, -1, 0, 0, -1682.17, 1439.67, 52.3705, 0.837758, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 25383);
UPDATE `creature_template` SET `unit_flags` = 33344 WHERE `entry` = 17429;
UPDATE `creature_template` SET `modelid1` = 15880, `modelid2` = 0 WHERE `entry` = 35374;
UPDATE `quest_objectives` SET `ObjectID` = '0' , `Amount` = '0' WHERE `ID` = '264587'; 
DELETE FROM `creature_addon` WHERE (`guid`=20556362);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (20556362, 0, 0, 65536, 1, 0, 49414);


DELETE FROM `creature` WHERE `id`=35906;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210115272, 35906, 654, 0, 0, 1, 0, 170, 0, -1, 0, 1, -1785.53, 1437.74, 20.2669, 6.02249, 300, 0, 0, 130, 115, 0, 0, 0, 0, 0, 0, '', 0),
(210115271, 35906, 654, 0, 0, 1, 0, 0, 0, -1, 0, 1, -1785.82, 1437.63, 20.2474, 6.19842, 300, 0, 0, 130, 115, 0, 0, 0, 0, 0, 0, '', 0);

UPDATE `creature_template` SET `gossip_menu_id` = 44427, `npcflag` = 1 WHERE `entry` = 44427;

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('44427','0','0','Lets Go!','0','1','1','29416');

SET @ENTRY := 44427;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,44427,0,0,0,62,654,0,0,0,0,0,7,0,0,0,-1542,1575,31,5,'Teleport on Quest Add');
UPDATE `quest_objectives` SET `Amount` = '10' WHERE `ID` = '264948'; 
UPDATE `quest_objectives` SET `Amount` = '10' WHERE `ID` = '267253'; 


DELETE FROM `creature` WHERE `id`=35566;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(20557372, 35566, 654, 4755, 4761, 1, 0, 172, 0, -1, 0, 0, -1619.7, 1498.03, 32.8829, 0.785398, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 25383),
(210115275, 35566, 654, 0, 0, 1, 0, 179, 0, -1, 0, 1, -1619.7, 1498.03, 32.8829, 0.785398, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 25383);

DELETE FROM `creature` WHERE `id`=36332;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(372321, 36332, 0, 4706, 5435, 1, 0, 0, 0, -1, 0, 0, -1654.41, 1649.29, 21.1448, 5.29588, 600, 0, 0, 186, 191, 0, 0, 0, 0, 0, 0, '', 0),
(372319, 36332, 0, 4706, 5436, 1, 0, 0, 0, -1, 0, 0, -2046.03, 966.051, 70.0846, 4.08109, 600, 0, 0, 186, 191, 0, 0, 0, 0, 0, 0, '', 0),
(210115279, 36332, 654, 0, 0, 1, 0, 0, 0, -1, 0, 1, -1821.26, 2292.92, 42.0995, 5.67486, 300, 0, 0, 474, 0, 0, 0, 0, 0, 0, 0, '', 0);

DELETE FROM `creature` WHERE `id`=36170;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210115281, 36170, 654, 0, 0, 1, 0, 0, 0, -1, 0, 1, -1822.02, 2294.99, 42.0956, 0.0584736, 300, 0, 0, 130, 0, 0, 0, 0, 0, 0, 0, '', 0);

DELETE FROM `creature` WHERE `id`=36331;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210115280, 36331, 654, 0, 0, 1, 0, 0, 0, -1, 0, 1, -1819.15, 2290.99, 42.2138, 2.41074, 300, 0, 0, 236, 191, 0, 0, 0, 0, 0, 0, '', 0);

SET @ENTRY := 36170;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,14313,0,0,0,62,0,0,0,0,0,0,7,0,0,0,-8827,627,95,0.8,'Teleport on Quest Add');
DELETE FROM `creature_queststarter` WHERE `id` = '36132' AND `quest` = '14320'; 
DELETE FROM `creature` WHERE `id`=36132;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210115282, 36132, 0, 0, 0, 1, 0, 0, 0, -1, 0, 1, -8827.74, 635.329, 94.5772, 4.30171, 300, 0, 0, 236, 191, 0, 0, 0, 0, 0, 0, '', 0);
UPDATE `quest_template` SET `RewardSpell` = 68996 WHERE `Id` = 14313;
REPLACE INTO `creature_queststarter` (`id`, `quest`) VALUES ('36132', '54'); 
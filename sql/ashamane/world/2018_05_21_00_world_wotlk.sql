UPDATE `creature_template` SET `unit_flags` = 64 WHERE `entry` = 18405;
UPDATE `creature_template` SET `unit_flags` = 64 WHERE `entry` = 17993;
UPDATE `creature_template` SET `unit_flags` = 64 WHERE `entry` = 19507;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 21303;
UPDATE `creature_template` SET `faction` = 22 WHERE `entry` = 19507;
UPDATE `creature_template` SET `InhabitType` = 3 WHERE `entry` = 65071;

DELETE FROM `gameobject` WHERE `id`=206294;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`,`isActive`,`ScriptName`,`VerifiedBuild`) VALUES
(20373549, 206294, 0, 0, 0, 1, 0, 0, 0, -1, -8341.77, 641.757, 95.8576, 3.79609, 0, 0, 0.94693, -0.321439, 120, 255, 1, 0, '', 22423);

DELETE FROM `creature` WHERE `id`=13018;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(180597, 13018, 369, 2257, 2257, 1, 0, 0, 0, -1, 12965, 0, -20.5294, 2456.57, -4.29719, 2.76091, 300, 0, 0, 247, 0, 0, 0, 0, 0, 0, 0, '', 0);

delete from  gameobject where id IN (176080,176081,176082,176083,176084,176085,176086);

REPLACE into `gameobject` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `ScriptName`,`VerifiedBuild`) values('218206','369','2257','2257','1','1','-45.4007','2512.15','6.9886','1.5708','0','0','1','0','120','0','1','0','0','0'),('218208','369','2257','2257','1','1','4.49883','-11.3475','7.01107','1.5708','0','0','1','0','120','0','1','0','0','0'),('218204','369','2257','2257','1','1','4.52807','8.43529','7.01107','1.5708','0','0','1','0','120','0','1','0','0','0'),('218203','369','2257','2257','1','1','4.58065','28.2097','7.01107','1.5708','0','0','1','0','120','0','1','0','0','0'),('218207','369','2257','2257','1','1','-45.3934','2472.93','6.9886','-1.5708','0','0','1','0','120','0','1','0','0','0'), ('218205','369','2257','2257','1','1','-45.4005','2492.79','6.9886','1.5708','0','0','1','0','120','0','1','0','0','0');

UPDATE `creature_template` SET `InhabitType` = 5 WHERE `entry` = 51383;

DELETE FROM `gameobject_template` WHERE entry=218203;
DELETE FROM `gameobject_template` WHERE entry=218204;
DELETE FROM `gameobject_template` WHERE entry=218205;
DELETE FROM `gameobject_template` WHERE entry=218206;
DELETE FROM `gameobject_template` WHERE entry=218207;
DELETE FROM `gameobject_template` WHERE entry=218208;
INSERT INTO `gameobject_template` (entry, type, displayId, name, VerifiedBuild) VALUES (218203, 11, 3831, 'Doodad_SubwayCar02', 22522);
INSERT INTO `gameobject_template` (entry, type, displayId, name, VerifiedBuild) VALUES (218204, 11, 3831, 'Doodad_SubwayCar09', 22522);
INSERT INTO `gameobject_template` (entry, type, displayId, name, VerifiedBuild) VALUES (218205, 11, 3831, 'Doodad_SubwayCar11', 22522);
INSERT INTO `gameobject_template` (entry, type, displayId, name, VerifiedBuild) VALUES (218206, 11, 3831, 'Doodad_SubwayCar12', 22522);
INSERT INTO `gameobject_template` (entry, type, displayId, name, VerifiedBuild) VALUES (218207, 11, 3831, 'Doodad_SubwayCar13', 22522);
INSERT INTO `gameobject_template` (entry, type, displayId, name, VerifiedBuild) VALUES (218208, 11, 3831, 'Doodad_SubwayCar01', 22522);
UPDATE `gameobject_template_addon` SET flags = 8 WHERE entry = 218203;
UPDATE `gameobject_template_addon` SET flags = 8 WHERE entry = 218204;
UPDATE `gameobject_template_addon` SET flags = 8 WHERE entry = 218205;
UPDATE `gameobject_template_addon` SET flags = 8 WHERE entry = 218206;
UPDATE `gameobject_template_addon` SET flags = 8 WHERE entry = 218207;
UPDATE `gameobject_template_addon` SET flags = 8 WHERE entry = 218208;
UPDATE `gameobject` SET PhaseId = 169 WHERE id = 218203;
UPDATE `gameobject` SET PhaseId = 169 WHERE id = 218204;
UPDATE `gameobject` SET PhaseId = 169 WHERE id = 218205;
UPDATE `gameobject` SET PhaseId = 169 WHERE id = 218206;
UPDATE `gameobject` SET PhaseId = 169 WHERE id = 218207;
UPDATE `gameobject` SET PhaseId = 169 WHERE id = 218208;
UPDATE `creature_template` SET `npcflag` = 81 WHERE `entry` = 26905;

UPDATE `gossip_menu_option` SET `OptionType` = '4' WHERE `MenuId` = '13045' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '4' WHERE `MenuId` = '13047' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '4' WHERE `MenuId` = '13046' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '8192' WHERE `MenuId` = '13046' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '8192' WHERE `MenuId` = '13045' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '8192' WHERE `MenuId` = '13047' AND `OptionIndex` = '0'; 


UPDATE `gossip_menu_option` SET `OptionType` = '5' WHERE `MenuId` = '4169' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '5' WHERE `MenuId` = '2741' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '5' WHERE `MenuId` = '8254' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionType` = '5' WHERE `MenuId` = '7512' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '5' WHERE `MenuId` = '10363' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '16' WHERE `MenuId` = '4169' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '16' WHERE `MenuId` = '2741' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '16' WHERE `MenuId` = '8254' AND `OptionIndex` = '1'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '16' WHERE `MenuId` = '7512' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '16' WHERE `MenuId` = '10363' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = '0' WHERE `MenuId` = '9985' AND `OptionIndex` = '0'; 
UPDATE `creature_template` SET `npcflag` = 81 WHERE `entry` = 26905;


DELETE FROM `creature_template_addon` WHERE (`entry`=23652);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (23652, 0, 0, 0, 1, 234, '');

UPDATE `gossip_menu_option` SET `OptionType` = '5' WHERE `MenuId` = '11767' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '5' WHERE `MenuId` = '12537' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '5' WHERE `MenuId` = '7817' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '5' WHERE `MenuId` = '12714' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '5' WHERE `MenuId` = '8540' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '5' WHERE `MenuId` = '11766' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '5' WHERE `MenuId` = '18379' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionType` = '5' WHERE `MenuId` = '4361' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '16' WHERE `MenuId` = '4361' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '16' WHERE `MenuId` = '11767' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '16' WHERE `MenuId` = '12537' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '16' WHERE `MenuId` = '7817' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '16' WHERE `MenuId` = '12714' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '16' WHERE `MenuId` = '8540' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '16' WHERE `MenuId` = '11766' AND `OptionIndex` = '0'; 
UPDATE `gossip_menu_option` SET `OptionNpcFlag` = '16' WHERE `MenuId` = '18379' AND `OptionIndex` = '0'; 

DELETE FROM `creature` WHERE `id`=23935;
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = 186572;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 24090;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (186572, 24090, 2409000);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(186572, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gnoll Cage - on gameobject state changed - store player'),
(186572, 1, 1, 2, 61, 0, 100, 0, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 24090, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - send player to Captured Mosshide'),
(186572, 1, 2, 0, 61, 0, 100, 0, 2, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 24090, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - set data 1 1 to Captured Mosshide within 5 yards'),
(24090, 0, 0, 0, 38, 0, 100, 1, 1, 1, 0, 0, 80, 2409000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - on data set 1 1 - run actionlist (2409000)'),
(2409000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 24124, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - actionlist - give quest credit (41410)'),
(2409000, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 46, 20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - actionlist - run forward 10 yards'),
(2409000, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - actionlist - despawn');
DELETE FROM `creature` WHERE `id`=24248;
DELETE FROM `creature` WHERE `id`=24327;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 24088;
REPLACE INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(186572, 1, 3, 4, 70, 0, 100, 0, 2, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gnoll Cage - on gameobject state changed - store player'),
(186572, 1, 4, 5, 61, 0, 100, 0, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 24088, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - send player to Captured Mosshide'),
(186572, 1, 5, 0, 61, 0, 100, 0, 2, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 24088, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - set data 1 1 to Captured Mosshide within 5 yards'),
(24088, 0, 0, 0, 38, 0, 100, 1, 1, 1, 0, 0, 80, 2408800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - on data set 1 1 - run actionlist (2408800)'),
(2408800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 24124, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - actionlist - give quest credit (41410)'),
(2408800, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 46, 20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - actionlist - run forward 10 yards'),
(2408800, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - actionlist - despawn');

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 24089;
REPLACE INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(186572, 1, 6, 7, 70, 0, 100, 0, 2, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gnoll Cage - on gameobject state changed - store player'),
(186572, 1, 7, 8, 61, 0, 100, 0, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 24089, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - send player to Captured Mosshide'),
(186572, 1, 8, 0, 61, 0, 100, 0, 2, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 24089, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - set data 1 1 to Captured Mosshide within 5 yards'),
(24089, 0, 0, 0, 38, 0, 100, 1, 1, 1, 0, 0, 80, 2408900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - on data set 1 1 - run actionlist (2408900)'),
(2408900, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 24124, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - actionlist - give quest credit (41410)'),
(2408900, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 46, 20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - actionlist - run forward 10 yards'),
(2408900, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - actionlist - despawn');

UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = 186569;
REPLACE INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(186569, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gnoll Cage - on gameobject state changed - store player'),
(186569, 1, 1, 2, 61, 0, 100, 0, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 24090, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - send player to Captured Mosshide'),
(186569, 1, 2, 0, 61, 0, 100, 0, 2, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 24090, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - set data 1 1 to Captured Mosshide within 5 yards'),
(186569, 1, 3, 4, 70, 0, 100, 0, 2, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gnoll Cage - on gameobject state changed - store player'),
(186569, 1, 4, 5, 61, 0, 100, 0, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 24088, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - send player to Captured Mosshide'),
(186569, 1, 5, 0, 61, 0, 100, 0, 2, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 24088, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - set data 1 1 to Captured Mosshide within 5 yards'),
(186569, 1, 6, 7, 70, 0, 100, 0, 2, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gnoll Cage - on gameobject state changed - store player'),
(186569, 1, 7, 8, 61, 0, 100, 0, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 24089, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - send player to Captured Mosshide'),
(186569, 1, 8, 0, 61, 0, 100, 0, 2, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 24089, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - set data 1 1 to Captured Mosshide within 5 yards');

DELETE FROM `creature_template_addon` WHERE (`entry`=26916);
DELETE FROM `creature_template_addon` WHERE (`entry`=24189);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (24189, 0, 0, 0, 1, 0, 84063);

DELETE FROM `creature_template_addon` WHERE (`entry`=24272);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (24272, 0, 0, 33554432 , 0, 0, '');
DELETE FROM `quest_objectives` WHERE `ID` = '259326'; 
DELETE FROM `gameobject` WHERE `id`=186640;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`,`isActive`,`ScriptName`,`VerifiedBuild`) VALUES
(51013358, 186640, 571, 0, 0, 1, 0, 0, 0, -1, 778.137, -4715.15, -96.1442, 2.81609, 0, 0, -0.986785, -0.162035, 300, 255, 1, 0, '', 0);


-- Thoralius the Wise SAI
SET @ENTRY := 23975;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,512,60000,120000,300000,300000,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thoralius the Wise - every 5 min Stand"),
(@ENTRY,0,1,0,61,0,100,512,0,0,0,0,53,0,23975,0,0,0,0,1,0,0,0,0,0,0,0,"Thoralius the Wise - Start WP"),
(@ENTRY,0,2,0,40,0,100,512,2,23975,0,0,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thoralius the Wise - Load script 1 at WP 2"),
(@ENTRY,0,3,0,40,0,100,512,4,23975,0,0,80,@ENTRY*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thoralius the Wise - Load script 2 at WP 4"),
(@ENTRY,0,4,0,40,0,100,512,7,23975,0,0,80,@ENTRY*100+02,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thoralius the Wise - Load script 3 at WP 7"),
(@ENTRY,0,5,0,40,0,100,512,8,23975,0,0,80,@ENTRY*100+03,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thoralius the Wise - Load script 4 at WP 8"),
(@ENTRY,0,6,0,19,0,100,0,11343,0,0,0,15,11343,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Quest Add'),
(@ENTRY,0,7,0,19,0,100,0,11344,0,0,0,15,11344,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Quest Add');


replace into `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) values('23791','3','1902','0','0','0','0','0','0','0','0','0');
DELETE FROM `creature_template_addon` WHERE (`entry`=23791);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (23791, 0, 0, 0, 257, 234, '');

DELETE FROM `quest_objectives` WHERE `ID` = '262803'; 
SET @ENTRY := 23791;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,500,500,500,500,17,173,0,0,0,0,0,1,0,0,0,0,0,0,0,'Play Emote on Spawn');
UPDATE `creature_template_addon` SET `bytes2` = '0' WHERE `entry` = '24084'; 
DELETE FROM `creature_template_addon` WHERE (`entry`=24078);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (24078, 0, 0, 0, 0, 233, '');
UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 23791;

UPDATE `quest_objectives` SET `ObjectID` = '24635' WHERE `ID` = '253750'; 
DELETE FROM `creature_addon` WHERE (`guid`=95229);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (95229, 0, 0, 0, 1, 234, '');
DELETE FROM `quest_objectives` WHERE `ID` = '253751'; 
DELETE FROM `quest_objectives` WHERE `ID` = '253752'; 
DELETE FROM `quest_objectives` WHERE `ID` = '253753'; 

DELETE FROM `creature_equip_template` WHERE `CreatureID` = '23791' AND `ID` = '3'; 
SET @ENTRY := 24634;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,11436,0,0,0,15,11436,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Quest Add');

DELETE FROM `creature_template_addon` WHERE (`entry`=11260);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (11260, 0, 0, 0, 460, 234, '');
UPDATE `creature` SET `position_x` = -61, `position_y` = 40 WHERE `guid` = 84765;
replace into `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) values('11260','1','1905','0','0','0','0','0','0','0','0','0');
DELETE FROM `gameobject_template_addon` WHERE `entry` = '183049'; 
DELETE FROM `gameobject` WHERE `id`=183049;
DELETE FROM `creature_template_addon` WHERE (`entry`=25271);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (25271, 0, 0, 0, 1, 234, '');
UPDATE `creature_loot_template` SET `Chance` = '100' , `QuestRequired` = '1' WHERE `Entry` = '17796' AND `Item` = '72574'; 
UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '417796' AND `Item` = '72574'; 
UPDATE `creature_template` SET `InhabitType` = 4 WHERE `entry` = 24747;


DELETE FROM `creature_template_addon` WHERE (`entry`=24717);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (24717, 0, 0, 0, 1, 415, '');

DELETE FROM `creature_template_addon` WHERE (`entry`=24720);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (24720, 0, 0, 0, 1, 415, '');


DELETE FROM `creature_template_addon` WHERE (`entry`=23672);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (23672, 0, 0, 0, 1, 233, '');
UPDATE `creature_template` SET `KillCredit1` = 24824 WHERE `entry` = 23675;
UPDATE `creature_template` SET `spell1` = 44550 WHERE `entry` = 24821;

SET @ENTRY := 24807;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,11495,0,0,0,15,11495,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Credit on Quest Add');
UPDATE `creature_template` SET `lootid` = 24746 WHERE `entry` = 24746;
UPDATE `creature_template` SET `InhabitType` = 1 WHERE `entry` = 24747;
REPLACE INTO `creature_loot_template` (`Entry`, `Item`, `QuestRequired`) VALUES ('24747', '34120', '1'); 
REPLACE INTO `creature_loot_template` (`Entry`, `Item`, `QuestRequired`) VALUES ('24746', '34112', '1'); 
-- Fjord Turkey SAI
SET @ENTRY := 24746;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,44323,0,0,0,11,44327,0,0,0,0,0,7,0,0,0,0,0,0,0,"Fjord Turkey - On Spellhit - Cast spell on invoker"),
(@ENTRY,0,1,0,61,0,100,512,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fjord Turkey - On Spellhit - Despawn"),
(@ENTRY,0,2,0,6,0,100,0,0,0,0,0,11,25281,0,0,0,0,0,7,0,0,0,0,0,0,0,"Fjord Turkey - Upon death - Cast Turkey Marker");

UPDATE `gameobject_template` SET `castBarCaption` = 'Using' WHERE `entry` = '186946'; 
UPDATE `gameobject_template` SET `Data1` = '186946' WHERE `entry` = '186946'; 



REPLACE INTO `gameobject_loot_template` (`Entry`, `Item`, `QuestRequired`) VALUES ('186946', '34123', '1'); 

DELETE FROM `creature` WHERE `id`=24747;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116543, 24747, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 352.115, -5528.36, 301.187, 5.69193, 300, 0, 0, 10542, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107275, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 725.879, -5882.41, 303.721, 6.24828, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107276, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 709.306, -5883.48, 301.644, 0.261799, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107277, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 553.903, -5566.76, 326.811, 2.73525, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107278, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 566.994, -5686.23, 290.647, 4.72984, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107279, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 566.489, -5680.66, 292.852, 0.628319, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107280, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 582.173, -5757.26, 323.832, 1.32786, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107281, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 538.064, -5784.21, 342.592, 1.20731, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107282, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 503.998, -5510.25, 288.385, 3.44478, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107283, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 596.367, -5486.36, 273.835, 3.04234, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107284, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 548.023, -5508.68, 275.543, 4.4855, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107285, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 541.425, -5511.69, 278.379, 5.35816, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107286, 24747, 571, 495, 3997, 1, 0, 0, 0, -1, 22633, 0, 452.216, -5891.98, 317.025, 3.12414, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107287, 24747, 571, 495, 3997, 1, 0, 0, 0, -1, 22633, 0, 449.902, -5896.84, 316.041, 4.13643, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107288, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 93.4665, -5569.04, 420.772, 3.19339, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107289, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 59.1263, -5495.61, 420.772, 0.537875, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107290, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 298.854, -5507.39, 350.305, 0.882603, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107291, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 329.072, -5498.99, 316.226, 6.0918, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107292, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 239.512, -5446.77, 362.65, 0.768782, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107293, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 202.173, -5433.29, 358.62, 3.263, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107294, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 385.522, -5979.44, 373.925, 4.02304, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107295, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 347.737, -5547.17, 312.564, 0.0349066, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107296, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 345.947, -5543.22, 313.035, 0.366519, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107297, 24747, 571, 495, 3996, 1, 0, 0, 0, -1, 22633, 0, 432.521, -5889.34, 353.488, 6.12611, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107298, 24747, 571, 495, 3996, 1, 0, 0, 0, -1, 22633, 0, 433.107, -5896.4, 353.488, 0.244346, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107299, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 518.172, -5743.9, 341.019, 1.51112, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116542, 24747, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 345.269, -5505, 299.637, 2.72391, 300, 0, 0, 10542, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107301, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 397.612, -5589.49, 333.874, 4.92467, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107302, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 577.757, -5957.19, 360.098, 5.34213, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107303, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 206.681, -5590.78, 347.655, 5.46288, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107304, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 208.878, -5584.89, 344.616, 0.959931, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107305, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 112.392, -5547.99, 391.403, 2.47837, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107306, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 126.66, -5547.28, 387.533, 5.25686, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107307, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 839.229, -5863.71, 285.414, 5.81195, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107308, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 835.653, -5866.74, 286.29, 5.25344, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107310, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 429.311, -5467.9, 299.273, 4.66925, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107311, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 445.304, -5404, 311.615, 5.29373, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107312, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 672.684, -5834.5, 310.472, 2.82993, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107313, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 761.145, -5818.98, 310.472, 4.08243, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107314, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 732.525, -5886.68, 304.926, 2.83538, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107315, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 786.373, -5902.5, 304.927, 3.34669, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107316, 24747, 571, 495, 3996, 1, 0, 0, 0, -1, 22633, 0, 429.259, -5897, 374.695, 0.0523599, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(107317, 24747, 571, 495, 495, 1, 0, 0, 0, -1, 22633, 0, 428.49, -5901.86, 374.447, 0.0349066, 300, 0, 0, 6986, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116563, 24747, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 512.42, -6102.74, 291.466, 1.71409, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116562, 24747, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 513.14, -6097.29, 291.953, 2.96288, 300, 0, 0, 10542, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116561, 24747, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 531.552, -6110.61, 249.646, 1.90651, 300, 0, 0, 10542, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116560, 24747, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 529.048, -6107.97, 250.599, 1.19966, 300, 0, 0, 11158, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116556, 24747, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 440.479, -6136.36, 172.065, 4.52583, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116557, 24747, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 528.752, -6129.68, 142.727, 0.194348, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116558, 24747, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 537.583, -6128.71, 142.48, 4.66326, 300, 0, 0, 11158, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116559, 24747, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 541.503, -6135.13, 140.947, 2.77831, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116552, 24747, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 396.36, -6113.53, 186.589, 2.09661, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116544, 24747, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 415.172, -5481.87, 289.873, 0.31666, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116545, 24747, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 415.05, -5458.19, 284.973, 1.96678, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116546, 24747, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 415.268, -5446.69, 283.609, 1.96678, 300, 0, 0, 11158, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116547, 24747, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 412.157, -5428.98, 281.538, 3.16609, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116550, 24747, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 391.92, -6103.68, 188.987, 4.91383, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116553, 24747, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 392.499, -6112.24, 184.759, 1.21696, 300, 0, 0, 11158, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116554, 24747, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 432.907, -6145.32, 165.226, 0.481031, 300, 0, 0, 11158, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116555, 24747, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 438.708, -6143.33, 167.884, 1.63557, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0);


REPLACE INTO `creature_loot_template` (`Entry`, `Item`, `QuestRequired`) VALUES ('24747', '34123', '1'); 
REPLACE into `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `AIName`, `ScriptName`, `VerifiedBuild`) values('186946','3','1867','Fjord Hawk Egg','Point','Using','','0.75','57','186946','0','1','0','0','0','0','0','0','0','0','0','1','21400','0','0','0','93','4','0','0','0','0','0','0','81040','0','0','0','55706','0','0','92','','','22566');



DELETE FROM `gameobject` WHERE `id`=186950;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`,`isActive`,`ScriptName`,`VerifiedBuild`) VALUES
(44136, 186950, 571, 495, 4005, 1, 0, 0, 0, -1, 1229.91, -6206.23, 231.837, 1.73452, 0, 0, 0.762559, 0.646918, 1500, 100, 1, 0, '', 0),
(51003390, 186950, 571, 0, 0, 1, 0, 0, 0, -1, 1198.59, -6174.12, 231.852, 0.775528, 0, 0, -0.378119, -0.925757, 300, 255, 1, 0, '', 0);


DELETE FROM `creature` WHERE `id`=32386;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(77289, 32386, 571, 495, 495, 1, 0, 0, 0, -1, 0, 0, 1091.68, -5756.49, 233.888, 5.71161, 28800, 0, 0, 13936, 0, 0, 0, 0, 0, 0, 0, '', 0);

UPDATE `creature_template` SET `npcflag` = 2177 WHERE `entry` = 24040;


replace  into `npc_vendor`(`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`,`OverrideGoldCost`,`type`,`BonusListIDs`,`PlayerConditionID`,`IgnoreFiltering`,`VerifiedBuild`) values (24040,1,34135,0,0,0,0,1,NULL,0,0,26141);


UPDATE `gossip_menu_option` SET `OptionType` = '3' , `OptionNpcFlag` = '128' WHERE `MenuId` = '8991' AND `OptionIndex` = '2'; 
DELETE FROM `quest_objectives` WHERE `ID` = '262473'; 



-- Walt SAI
SET @ENTRY := 24807;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,11495,0,0,0,15,11495,0,0,0,0,0,7,0,0,0,0,0,0,0,"Quest Credit on Quest Add"),
(@ENTRY,0,1,0,19,0,100,0,11485,0,0,0,15,11485,0,0,0,0,0,7,0,0,0,0,0,0,0,"Quest Credit on Quest Add"),
(@ENTRY,0,2,0,19,0,100,0,11491,0,0,0,15,11491,0,0,0,0,0,7,0,0,0,0,0,0,0,"Quest Credit on Quest Add");


DELETE FROM `creature_template_addon` WHERE (`entry`=23911);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (23911, 0, 0, 0, 1, 234, '');


DELETE FROM `creature_template_addon` WHERE (`entry`=23967);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (23967, 0, 0, 0, 1, 233, '');
UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '23691' AND `Item` = '33120'; 
UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '23690' AND `Item` = '33120'; 
UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '24791' AND `Item` = '33120'; 


REPLACE INTO `creature_loot_template` (`Entry`, `Item`, `QuestRequired`, `MaxCount`) VALUES ('23967', '33188', '1', '5'); 
REPLACE INTO `creature_loot_template` (`Entry`, `Item`, `QuestRequired`, `MaxCount`) VALUES ('23967', '33187', '1', '5'); 

REPLACE INTO `creature_loot_template` (`Entry`, `Item`, `QuestRequired`, `MaxCount`) VALUES ('23977', '33188', '1', '5'); 
REPLACE INTO `creature_loot_template` (`Entry`, `Item`, `QuestRequired`, `MaxCount`) VALUES ('23977', '33187', '1', '5'); 
UPDATE `creature_template` SET `unit_flags` = 4 WHERE `entry` = 23777;
SET @ENTRY := 203282;
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = 203282;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,42703,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"on Spell Hit - Despawn"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,50,186468,20000,1,0,0,0,1,0,0,0,0,0,0,0,"on Spell Hit - Summon ore"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,50,186466,20000,1,0,0,0,1,0,0,0,0,0,0,0,"on Spell Hit - Summon ore"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,50,186468,20000,1,0,0,0,1,0,0,0,0,0,0,0,"on Spell Hit - Summon ore"),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,50,186466,20000,1,0,0,0,1,0,0,0,0,0,0,0,"on Spell Hit - Summon ore"),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,50,186468,20000,1,0,0,0,1,0,0,0,0,0,0,0,"on Spell Hit - Summon ore"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,50,186466,20000,1,0,0,0,1,0,0,0,0,0,0,0,"on Spell Hit - Summon ore");


SET @ENTRY := 23777;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,0,0,6,0,100,1,0,0,0,0,12,23688,2,60000,0,0,0,0,1,0,0,0,0,0,0,'Cast Summon on Death');

UPDATE `creature_template` SET `unit_flags` = 139268 WHERE `entry` = 23777;


DELETE FROM `creature` WHERE `id`=23688;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116569, 23688, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1062.9, -3828.63, 163.83, 5.49683, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116584, 23688, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 922.917, -3928.97, 176.731, 4.73735, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116583, 23688, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 946.654, -3850.04, 173.701, 4.21663, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(117256, 23688, 571, 495, 4048, 1, 0, 0, 0, -1, 0, 0, 1052.95, -3748.2, 178.109, 1.39867, 600, 20, 0, 7984, 0, 1, 0, 0, 0, 0, 0, '', 0),
(117257, 23688, 571, 495, 4048, 1, 0, 0, 0, -1, 0, 0, 998.649, -3803.55, 202.221, 5.91469, 600, 20, 0, 7984, 0, 1, 0, 0, 0, 0, 0, '', 0),
(117258, 23688, 571, 495, 4048, 1, 0, 0, 0, -1, 0, 0, 1043.99, -3845.19, 176.842, 5.50629, 600, 20, 0, 7984, 0, 1, 0, 0, 0, 0, 0, '', 0),
(117259, 23688, 571, 495, 4048, 1, 0, 0, 0, -1, 0, 0, 1115.53, -3901.26, 168.698, 0.589697, 600, 20, 0, 7984, 0, 1, 0, 0, 0, 0, 0, '', 0),
(117260, 23688, 571, 495, 4048, 1, 0, 0, 0, -1, 0, 0, 1130.88, -3853.31, 164.554, 1.35546, 600, 20, 0, 7984, 0, 1, 0, 0, 0, 0, 0, '', 0),
(117261, 23688, 571, 495, 4048, 1, 0, 0, 0, -1, 0, 0, 1146.84, -3764, 160.683, 1.35546, 600, 20, 0, 7984, 0, 1, 0, 0, 0, 0, 0, '', 0),
(117262, 23688, 571, 495, 4048, 1, 0, 0, 0, -1, 0, 0, 1136.8, -3679.78, 169.211, 2.07803, 600, 20, 0, 7984, 0, 1, 0, 0, 0, 0, 0, '', 0),
(117263, 23688, 571, 495, 4048, 1, 0, 0, 0, -1, 0, 0, 1096.14, -3648.61, 183.079, 2.52963, 600, 20, 0, 7984, 0, 1, 0, 0, 0, 0, 0, '', 0),
(117264, 23688, 571, 495, 4048, 1, 0, 0, 0, -1, 0, 0, 1100.35, -3603.67, 181.216, 1.41829, 600, 20, 0, 7984, 0, 1, 0, 0, 0, 0, 0, '', 0),
(117265, 23688, 571, 495, 4048, 1, 0, 0, 0, -1, 0, 0, 1123.66, -3630.68, 178.215, 5.69479, 600, 20, 0, 7984, 0, 1, 0, 0, 0, 0, 0, '', 0),
(117266, 23688, 571, 495, 4048, 1, 0, 0, 0, -1, 0, 0, 1163.95, -3641.16, 173.663, 5.87543, 600, 20, 0, 7984, 0, 1, 0, 0, 0, 0, 0, '', 0),
(117267, 23688, 571, 495, 4048, 1, 0, 0, 0, -1, 0, 0, 1154.42, -3713.38, 174.212, 4.54025, 600, 20, 0, 7984, 0, 1, 0, 0, 0, 0, 0, '', 0),
(117268, 23688, 571, 495, 4048, 1, 0, 0, 0, -1, 0, 0, 1172.33, -3793.84, 158.343, 5.15678, 600, 20, 0, 7984, 0, 1, 0, 0, 0, 0, 0, '', 0),
(117269, 23688, 571, 495, 4048, 1, 0, 0, 0, -1, 0, 0, 1190.38, -3845.78, 154.364, 3.77056, 600, 20, 0, 7984, 0, 1, 0, 0, 0, 0, 0, '', 0),
(117270, 23688, 571, 495, 4048, 1, 0, 0, 0, -1, 0, 0, 1143.9, -3853.26, 172.136, 2.98123, 600, 20, 0, 7984, 0, 1, 0, 0, 0, 0, 0, '', 0),
(117271, 23688, 571, 495, 4048, 1, 0, 0, 0, -1, 0, 0, 1061.95, -3858.81, 186.304, 2.49428, 600, 20, 0, 7984, 0, 1, 0, 0, 0, 0, 0, '', 0),
(117272, 23688, 571, 495, 4048, 1, 0, 0, 0, -1, 0, 0, 993.836, -3778.22, 200.038, 2.10551, 600, 20, 0, 7984, 0, 1, 0, 0, 0, 0, 0, '', 0),
(117273, 23688, 571, 495, 4048, 1, 0, 0, 0, -1, 0, 0, 980.212, -3705.21, 199.391, 1.41829, 600, 20, 0, 7984, 0, 1, 0, 0, 0, 0, 0, '', 0),
(117274, 23688, 571, 495, 4048, 1, 0, 0, 0, -1, 0, 0, 1051.66, -3725.17, 197.736, 0.26768, 600, 20, 0, 7984, 0, 1, 0, 0, 0, 0, 0, '', 0),
(210116566, 23688, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 981.838, -3787.65, 173.382, 5.22822, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116588, 23688, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1035.21, -3945.22, 156.379, 0.00689614, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116589, 23688, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1044.05, -3924.52, 157.634, 1.79996, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116587, 23688, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1006.43, -3946.88, 158.26, 0.183611, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116581, 23688, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 978.922, -3793.66, 172.913, 4.78447, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116582, 23688, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 940.113, -3835.38, 174.328, 4.49937, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116579, 23688, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1015.35, -3821.43, 167.581, 1.71906, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116580, 23688, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1010.92, -3792.62, 169.414, 1.99238, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116576, 23688, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1064.19, -3939.34, 154.993, 5.41986, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116577, 23688, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1049.07, -3890.99, 156.912, 1.50622, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116578, 23688, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1049.41, -3878.97, 158.039, 0.420014, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116571, 23688, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1113.42, -3828.29, 153.326, 5.81492, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116572, 23688, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1128.67, -3829.08, 150.656, 4.61011, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116573, 23688, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1107.91, -3858.53, 153.497, 4.58341, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116574, 23688, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1087.14, -3883.01, 158.469, 3.40767, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116575, 23688, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1041.73, -3919.26, 158.118, 0.206388, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116570, 23688, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1077.41, -3829.61, 161.954, 0.966654, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116568, 23688, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1044.19, -3800.07, 163.988, 5.27299, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116586, 23688, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 964.41, -3959.41, 165.964, 5.67276, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116585, 23688, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 915.173, -3941.09, 176.538, 5.58794, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116567, 23688, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1031.14, -3804.67, 165.926, 0.226809, 300, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0);


SET @ENTRY := 23976;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,11218,0,0,0,28,31694,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Spell Remove on Quest Reward');
UPDATE `creature_template` SET `unit_flags` = 0, `InhabitType` = 4 WHERE `entry` = 23693;

UPDATE `creature_template` SET `InhabitType` = 5 WHERE `entry` = 23689;

DELETE FROM `creature` WHERE `id`=23689;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116594, 23689, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1097.24, -3599.03, 169.635, 5.03362, 300, 0, 0, 11544, 0, 0, 0, 0, 0, 0, 0, '', 0),
(121169, 23689, 571, 495, 4048, 1, 0, 0, 0, -1, 24717, 0, 1002.9, -3737.65, 218.465, 2.15875, 180, 20, 0, 8982, 0, 1, 0, 0, 0, 0, 0, '', 0),
(121168, 23689, 571, 495, 4048, 1, 0, 0, 0, -1, 24717, 0, 994.907, -3862.04, 237.903, 4.72455, 180, 20, 0, 8982, 0, 1, 0, 0, 0, 0, 0, '', 0),
(121170, 23689, 571, 495, 4048, 1, 0, 0, 0, -1, 24717, 0, 1033.41, -3931.71, 218.425, 3.71408, 180, 20, 0, 8982, 0, 1, 0, 0, 0, 0, 0, '', 0),
(121173, 23689, 571, 495, 4048, 1, 0, 0, 0, -1, 24717, 0, 1108.86, -3840.07, 199.16, 2.50974, 180, 20, 0, 8982, 0, 1, 0, 0, 0, 0, 0, '', 0),
(121172, 23689, 571, 495, 4048, 1, 0, 0, 0, -1, 24717, 0, 1222.22, -3616.05, 213.112, 5.28972, 180, 20, 0, 8982, 0, 1, 0, 0, 0, 0, 0, '', 0),
(121171, 23689, 571, 495, 4048, 1, 0, 0, 0, -1, 24717, 0, 1015.85, -3702.36, 221.788, 4.05576, 180, 20, 0, 8982, 0, 1, 0, 0, 0, 0, 0, '', 0),
(210116593, 23689, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1057.28, -3647.11, 167.975, 0.601621, 300, 0, 0, 11158, 0, 0, 0, 0, 0, 0, 0, '', 0);


SET @ENTRY := 23804;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,11573,0,0,0,28,31694,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Spell Remove on Quest Reward');
DELETE FROM `creature` WHERE `id`=24876;
DELETE FROM `creature` WHERE `id`=24874;
DELETE FROM `creature` WHERE `id`=24877;
DELETE FROM `creature` WHERE `id`=24880;
DELETE FROM `creature` WHERE `id`=24875;

DELETE FROM `creature` WHERE `id`=31806;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(127829, 31806, 571, 495, 3988, 1, 0, 0, 0, -1, 0, 0, 811.444, -2800.4, 17.7106, 6.03874, 300, 0, 0, 3524, 0, 0, 0, 0, 0, 0, 0, '', 0);


DELETE FROM `creature` WHERE `id`=24673;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116600, 24673, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 403.842, -3022.89, 73.8417, 2.52432, 300, 0, 0, 11158, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116599, 24673, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 436.674, -3042.46, 74.2212, 1.40512, 300, 0, 0, 11158, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116603, 24673, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 304.559, -3066.98, 35.7261, 0.766593, 300, 0, 0, 11544, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116601, 24673, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 357.561, -3018.5, 74.2794, 3.62466, 300, 0, 0, 11158, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116602, 24673, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 342.636, -3091.41, 55.0797, 3.14714, 300, 0, 0, 11544, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116598, 24673, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 418.223, -3094.6, 72.3554, 1.04227, 300, 0, 0, 11544, 0, 0, 0, 0, 0, 0, 0, '', 0),
(122277, 24673, 571, 495, 3987, 1, 0, 0, 0, -1, 10808, 0, 338.241, -3168.73, 25.7205, 5.74793, 300, 15, 0, 9291, 110, 1, 0, 0, 0, 0, 0, '', 0),
(122278, 24673, 571, 495, 3987, 1, 0, 0, 0, -1, 10808, 0, 881.289, -3167.13, 31.8964, 0.86809, 300, 15, 0, 9291, 110, 1, 0, 0, 0, 0, 0, '', 0),
(122279, 24673, 571, 495, 3987, 1, 0, 0, 0, -1, 10808, 0, 376.005, -3172.76, 26.8079, 1.48344, 300, 15, 0, 9291, 110, 1, 0, 0, 0, 0, 0, '', 0),
(122280, 24673, 571, 495, 3987, 1, 0, 0, 0, -1, 10808, 0, 515.937, -3040.78, 25.7229, 1.95931, 300, 15, 0, 9291, 110, 1, 0, 0, 0, 0, 0, '', 0),
(122281, 24673, 571, 495, 3987, 1, 0, 0, 0, -1, 0, 0, 569.094, -3002.6, 23.3999, 1.52251, 300, 15, 0, 9291, 110, 1, 0, 0, 0, 0, 0, '', 0),
(122282, 24673, 571, 495, 3987, 1, 0, 0, 0, -1, 10808, 0, 924.502, -3031.99, 53.2139, 2.38192, 300, 15, 0, 9291, 110, 1, 0, 0, 0, 0, 0, '', 0),
(122283, 24673, 571, 495, 3987, 1, 0, 0, 0, -1, 10808, 0, 895.605, -3128.96, 31.3006, 2.20919, 300, 15, 0, 9291, 110, 1, 0, 0, 0, 0, 0, '', 0),
(122284, 24673, 571, 495, 3987, 1, 0, 0, 0, -1, 10808, 0, 915.988, -3084.54, 38.6764, 5.47624, 300, 15, 0, 9291, 110, 1, 0, 0, 0, 0, 0, '', 0),
(122285, 24673, 571, 495, 3987, 1, 0, 0, 0, -1, 10808, 0, 876.359, -3043.78, 31.5499, 0.21691, 300, 15, 0, 9291, 110, 1, 0, 0, 0, 0, 0, '', 0),
(122286, 24673, 571, 495, 3987, 1, 0, 0, 0, -1, 10808, 0, 865.902, -3082.03, 29.4412, 1.44747, 300, 15, 0, 9291, 110, 1, 0, 0, 0, 0, 0, '', 0),
(122287, 24673, 571, 495, 3987, 1, 0, 0, 0, -1, 10808, 0, 968.072, -3014.68, 63.7141, 3.70914, 300, 15, 0, 9291, 110, 1, 0, 0, 0, 0, 0, '', 0),
(210116597, 24673, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 386.365, -3089.34, 71.2525, 4.90407, 300, 0, 0, 11158, 0, 0, 0, 0, 0, 0, 0, '', 0);


replace into `creature_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) values('24788','34116','0','100','1','1','0','1','1',NULL);

UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '24681' AND `Item` = '36776'; 
DELETE FROM `gameobject` WHERE `id`=187032;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`,`isActive`,`ScriptName`,`VerifiedBuild`) VALUES
(44150, 187032, 571, 495, 3989, 1, 0, 0, 0, -1, -128.347, -3439.77, -10.0083, 0.681698, 0, 0, 0.334287, 0.942471, 1500, 100, 1, 0, '', 0),
(51003425, 187032, 571, 0, 0, 1, 0, 0, 0, -1, -53.4037, -3328.71, 2.70577, 4.84154, 0, 0, -0.660004, 0.751262, 300, 255, 1, 0, '', 0);

DELETE FROM `creature` WHERE `id`=24910;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(116776, 24910, 571, 495, 3989, 1, 0, 0, 0, -1, 0, 0, 98.455, -3708.64, 1.14646, 0.136262, 600, 0, 0, 8982, 0, 0, 0, 0, 0, 0, 0, '', 0);

DELETE FROM `creature` WHERE `id`=25026;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(11303, 25026, 594, 0, 0, 1, 0, 0, 0, -1, 0, 1, -64.8012, -3731.33, 2.04348, 1.93969, 0, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(11293, 25026, 594, 0, 0, 1, 0, 0, 0, -1, 0, 1, 68.2488, -3685.92, 2.05058, 1.30168, 0, 0, 0, 11158, 0, 0, 0, 0, 0, 0, 0, '', 0),
(116774, 25026, 571, 495, 3989, 1, 0, 0, 0, -1, 0, 0, 125.518, -3698.68, 0.72143, 3.46636, 600, 0, 0, 8982, 0, 0, 0, 0, 0, 0, 0, '', 0),
(116773, 25026, 571, 495, 3989, 1, 0, 0, 0, -1, 0, 0, 125.808, -3704.07, 0.71005, 2.96763, 600, 0, 0, 8982, 0, 0, 0, 0, 0, 0, 0, '', 0),
(116772, 25026, 571, 495, 3989, 1, 0, 0, 0, -1, 0, 0, 124.726, -3707.39, 1.6308, 2.5553, 600, 0, 0, 8982, 0, 0, 0, 0, 0, 0, 0, '', 0),
(116771, 25026, 571, 495, 3989, 1, 0, 0, 0, -1, 0, 0, 123.108, -3696.06, 0.711278, 3.70198, 600, 0, 0, 8982, 0, 0, 0, 0, 0, 0, 0, '', 0),
(116775, 25026, 571, 495, 3989, 1, 0, 0, 0, -1, 0, 0, 127.14, -3701.11, 0.36822, 3.24252, 600, 0, 0, 8982, 0, 0, 0, 0, 0, 0, 0, '', 0),
(11301, 25026, 594, 0, 0, 1, 0, 0, 0, -1, 0, 1, -16.1875, -3701.25, 2.04348, 4.57405, 0, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(11299, 25026, 594, 0, 0, 1, 0, 0, 0, -1, 0, 1, 22.8759, -3694.15, 2.04348, 2.1771, 0, 0, 0, 11158, 0, 0, 0, 0, 0, 0, 0, '', 0),
(11297, 25026, 594, 0, 0, 1, 0, 0, 0, -1, 0, 1, 52.6562, -3688.98, 2.04348, 5.95878, 0, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(11295, 25026, 594, 0, 0, 1, 0, 0, 0, -1, 0, 1, 61.2905, -3693.36, 2.04348, 0.354329, 0, 0, 0, 10921, 0, 0, 0, 0, 0, 0, 0, '', 0),
(11307, 25026, 594, 0, 0, 1, 0, 0, 0, -1, 0, 1, -145.435, -3796.96, 2.42944, 4.98928, 0, 0, 0, 11158, 0, 0, 0, 0, 0, 0, 0, '', 0),
(11305, 25026, 594, 0, 0, 1, 0, 0, 0, -1, 0, 1, -109.306, -3760.6, 2.94964, 3.41939, 0, 0, 0, 11158, 0, 0, 0, 0, 0, 0, 0, '', 0),
(11600, 25026, 594, 0, 0, 1, 0, 0, 0, -1, 0, 1, 6.40259, -4075.53, 17.386, 4.69847, 0, 0, 0, 11158, 0, 0, 0, 0, 0, 0, 0, '', 0);

DELETE FROM `creature_template_addon` WHERE (`entry`=24642);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (24642, 0, 0, 3, 1, 0, 78677);
DELETE FROM `gameobject` WHERE `id`=187117;

DELETE FROM `gameobject` WHERE `id`=186408;
DELETE FROM `gameobject` WHERE `id`=186409;
DELETE FROM `gameobject` WHERE `id`=186410;
DELETE FROM `gameobject` WHERE `id`=186411;
DELETE FROM `gameobject` WHERE `id`=186412;
DELETE FROM `gameobject` WHERE `id`=186413;
UPDATE `creature` SET `spawndist` = 3, `MovementType` = 1 WHERE `id` IN (23688,23693,24681,24673,24676);


DELETE FROM `creature` WHERE `id`=24874;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116606, 24874, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, -18.0362, -4882.22, 302.555, 6.18815, 300, 0, 0, 11544, 0, 0, 0, 0, 0, 0, 0, '', 0);

DELETE FROM `creature` WHERE `id`=24876;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116607, 24876, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 17.9461, -4981.83, 309.781, 3.0497, 300, 0, 0, 11544, 0, 0, 0, 0, 0, 0, 0, '', 0);

DELETE FROM `creature` WHERE `id`=24877;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116608, 24877, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, -83.4448, -5017.96, 313.113, 1.64619, 300, 0, 0, 11544, 0, 0, 0, 0, 0, 0, 0, '', 0);

DELETE FROM `creature` WHERE `id`=24875;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116609, 24875, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, -105.809, -5143.98, 329.64, 2.27608, 300, 0, 0, 11544, 0, 0, 0, 0, 0, 0, 0, '', 0);


DELETE FROM `creature` WHERE `id`=24399;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(117314, 24399, 571, 495, 3999, 1, 0, 0, 0, -1, 0, 0, 2088.74, -3294.31, 100.979, 0.00535822, 600, 0, 0, 7181, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116612, 24399, 571, 0, 0, 1, 0, 0, 0, -1, 0, 1, 1959.36, -3259.55, 136.076, 6.03735, 300, 0, 0, 11543, 0, 0, 0, 0, 0, 0, 0, '', 0);

UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 24460;
DELETE FROM `creature_template_addon` WHERE (`entry`=24398);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (24398, 0, 0, 0, 1, 233, '');



UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '24014' AND `Item` = '34083'; 


UPDATE `creature` SET `spawndist` = 3, `MovementType` = 1 WHERE `id` IN (23959,24262,24026,24478);

UPDATE `creature_template` SET `unit_flags` = 393220 WHERE `entry` = 24210;



SET @ENTRY := 23921;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,42564,0,0,0,33,23921,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");


SET @ENTRY := 23922;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,42564,0,0,0,33,23922,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");

SET @ENTRY := 23923;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,42564,0,0,0,33,23923,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");

SET @ENTRY := 23924;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,42564,0,0,0,33,23924,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");

UPDATE `creature_template` SET `unit_flags` = 537002752, `unit_flags2` = 1 WHERE `entry` = 24280;


UPDATE `creature` SET `spawndist` = 0, `MovementType` = 0 WHERE `id` IN (24280);
DELETE FROM `creature_template_addon` WHERE (`entry`=24280);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (24280, 0, 0, 7, 1, 0, 29266);


SET @ENTRY := 24284;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,43386,0,0,0,33,24284,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");

SET @ENTRY := 24290;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,43403,0,0,0,33,24290,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");
UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 23666;

UPDATE `creature` SET `spawndist` = 3, `MovementType` = 1 WHERE `id` IN (23691);


SET @ENTRY := 24098;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,43057,0,0,0,33,24098,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");

SET @ENTRY := 24100;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,43057,0,0,0,33,24100,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");

SET @ENTRY := 24102;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,43057,0,0,0,33,24102,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");

-- Skorn Tower NW Bunny SAI
SET @ENTRY := 24087;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,49634,0,0,0,33,24087,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");

-- Skorn Tower NW Bunny SAI
SET @ENTRY := 24092;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,49634,0,0,0,33,24092,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");

-- Skorn Tower NW Bunny SAI
SET @ENTRY := 24093;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,49634,0,0,0,33,24093,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");

-- Skorn Tower NW Bunny SAI
SET @ENTRY := 24094;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,49634,0,0,0,33,24094,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");

UPDATE `creature_template` SET `InhabitType` = 5 WHERE `entry` = 23665;

UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = 186517;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 24035;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (186517, 24035, 2403500);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(186517, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gnoll Cage - on gameobject state changed - store player'),
(186517, 1, 1, 2, 61, 0, 100, 0, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 24035, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - send player to Captured Mosshide'),
(186517, 1, 2, 0, 61, 0, 100, 0, 2, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 24035, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - set data 1 1 to Captured Mosshide within 5 yards'),
(24035, 0, 0, 0, 38, 0, 100, 1, 1, 1, 0, 0, 80, 2403500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - on data set 1 1 - run actionlist (2403500)'),
(2403500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 24035, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - actionlist - give quest credit (41410)'),
(2403500, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 46, 20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - actionlist - run forward 10 yards'),
(2403500, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captured Mosshide - actionlist - despawn');

UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = 186494;
REPLACE INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(186494, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gnoll Cage - on gameobject state changed - store player'),
(186494, 1, 1, 2, 61, 0, 100, 0, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 24035, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - send player to Captured Mosshide'),
(186494, 1, 2, 0, 61, 0, 100, 0, 2, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 24035, 5, 0, 0, 0, 0, 0, 'Gnoll Cage - linked - set data 1 1 to Captured Mosshide within 5 yards');


SET @ENTRY := 24013;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,91,9,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove Bytes1 on Aggro'),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,90,9,0,0,0,0,0,1,0,0,0,0,0,0,0,'Add Bytes1 on Evade');

DELETE FROM `creature_template_addon` WHERE (`entry`=24013);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (24013, 0, 0, 9, 1, 0, '');


DELETE FROM `creature` WHERE `id`=24073;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(116976, 24073, 571, 495, 4006, 1, 0, 0, 0, -1, 0, 0, 2513.35, -3641.92, 161.052, 0.287001, 600, 0, 0, 9291, 0, 0, 0, 0, 0, 0, 0, '', 0),
(116975, 24073, 571, 495, 4006, 1, 0, 0, 0, -1, 0, 0, 2579.88, -3696.3, 161.441, 1.04476, 600, 0, 0, 9291, 0, 0, 0, 0, 0, 0, 0, '', 0),
(116974, 24073, 571, 495, 4006, 1, 0, 0, 0, -1, 0, 0, 2607.47, -3562.72, 161.397, 1.2364, 600, 0, 0, 9291, 0, 0, 0, 0, 0, 0, 0, '', 0),
(116973, 24073, 571, 495, 4006, 1, 0, 0, 0, -1, 0, 0, 2813.58, -3620.82, 161.404, 2.59215, 600, 0, 0, 9291, 0, 0, 0, 0, 0, 0, 0, '', 0),
(116972, 24073, 571, 495, 4006, 1, 0, 0, 0, -1, 0, 0, 2725.24, -3392.25, 159.691, 1.27268, 600, 0, 0, 9291, 0, 0, 0, 0, 0, 0, 0, '', 0),
(116971, 24073, 571, 495, 4006, 1, 0, 0, 0, -1, 0, 0, 2703.78, -3494.78, 161.4, 0.388944, 600, 0, 0, 9291, 0, 0, 0, 0, 0, 0, 0, '', 0),
(116970, 24073, 571, 495, 4006, 1, 0, 0, 0, -1, 0, 0, 2685.44, -3516.34, 161.354, 3.62636, 600, 0, 0, 9291, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116618, 24073, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 2580.88, -3665.32, 161.436, 3.50035, 300, 0, 0, 11544, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116619, 24073, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 2556.93, -3642.66, 162.862, 1.19128, 300, 0, 0, 11544, 0, 0, 0, 0, 0, 0, 0, '', 0);


DELETE FROM `creature` WHERE `id`=27959;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(116988, 27959, 571, 394, 4480, 1, 0, 0, 0, -1, 0, 0, 3213.87, -4460.42, 330.275, 3.65167, 600, 0, 0, 8982, 0, 0, 0, 0, 0, 0, 0, '', 0);


-- QUEST 11322 "The cleansing"
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=186649;
UPDATE `creature_template` SET `AIName`='SmartAI', `faction`=14 WHERE `entry`=27959;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27959,186649,2795900,18664900);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Frostblade Shrine script
(186649,1,0,0,64,0,100,0,0,0,0,0,80,18664900,0,2,0,0,0,1,0,0,0,0,0,0,0, 'On Frostblade Shrine use start script'),
(18664900,9,0,0,0,0,100,0,0,0,0,0,75,43351,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Cast Cleansing Soul on player'),
(18664900,9,1,0,0,0,100,0,10000,10000,0,0,85,50167,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Summon Inner Turmoil'),
-- Inner Turmoil script
(27959,0,0,1,54,0,100,0,0,0,0,0,85,50218,0,0,0,0,0,1,0,0,0,0,0,0,0,'On spawn copy the invoker'),
(27959,0,1,0,54,0,100,0,0,0,0,0,80,2795900,0,2,0,0,0,1,0,0,0,0,0,0,0,'Start script'),
(27959,0,2,0,2,0,100,0x01,0,50,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,'On 50% HP wisper text 2'),
(27959,0,3,4,6,0,100,0,0,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,'On death wisper text 3'),
(27959,0,4,5,61,0,100,0,0,0,0,0,75,50237,0,0,0,0,0,7,0,0,0,0,0,0,0,'Apply Slow Fall'),
(27959,0,5,6,61,0,100,0,0,0,0,0,28,50218,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Spell Remove'),
(27959,0,6,0,61,0,100,0,0,0,0,0,28,50167,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Spell Remove'),
(2795900,9,0,0,0,0,100,0,0,0,0,0,18,131072,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set unit_flags'),
(2795900,9,1,0,0,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Disable movement'),
(2795900,9,2,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Wisper text 0'),
(2795900,9,3,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Wisper text 1'),
(2795900,9,4,0,0,0,100,0,6000,6000,0,0,19,131072,0,0,0,0,0,1,0,0,0,0,0,0,0,'Remove unit_flags'),
(2795900,9,5,0,0,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Enable movement');

DELETE FROM `creature_text` WHERE `creatureid`=27959;
INSERT INTO `creature_text` (`creatureid`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextID`,`TextRange`,`comment`) VALUES
(27959,0,0,'You think that you can get rid of me through meditation?',15,0,100,1,0,0,0,0,'Inner Turmoil text 0'),
(27959,1,0,'Fool! I will destroy you and finally become that which has been building inside of you all of these years!',15,0,100,1,0,0,0,0,'Inner Turmoil text 1'),
(27959,2,0,'You cannot defeat me. I''m an inseparable part of you!',15,0,100,1,0,0,0,0,'Inner Turmoil text 50%'),
(27959,3,0,'NOOOOOOOoooooooooo!',15,0,100,1,0,0,0,0,'Inner Turmoil text death');

UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry`=27959; 
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=27959; 
UPDATE `creature` SET `phaseId`=0 WHERE `id`=27959; 
UPDATE `creature_addon` SET `auras`='' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=27959);

UPDATE `creature_template` SET `modelid1` = 15880 WHERE `entry` = 27959;

UPDATE `creature_template` SET `faction` = 22 WHERE `entry` = 27959;


DELETE FROM `creature_template_addon` WHERE (`entry`=23836);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (23836, 0, 0, 0, 1, 234, '');


SET @ENTRY := 24139;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,20,0,100,0,11406,0,0,0,28,50218,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Spell Remove on Quest Reward'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,28,50167,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Spell Remove on Quest Reward');

SET @ENTRY := 24273;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,20,0,100,0,11406,0,0,0,28,50218,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Spell Remove on Quest Reward'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,28,50167,0,0,0,0,0,7,0,0,0,0,0,0,0,'Quest Spell Remove on Quest Reward');
UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 24178;
UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '23740' AND `Item` = '33352'; 
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 24518;
UPDATE `creature_template` SET `InhabitType` = 5 WHERE `entry` = 24132;
UPDATE `creature_template` SET `faction` = 22 WHERE `entry` = 24518;
UPDATE `creature_template` SET `faction` = 22 WHERE `entry` = 24277;
DELETE FROM `creature` WHERE `id`=24518;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(308548, 24518, 571, 495, 495, 1, 0, 0, 0, -1, 22503, 0, 1626.69, -3809.94, 188.081, 6.03447, 300, 0, 0, 9291, 0, 0, 0, 0, 0, 0, 0, '', 0),
(210116622, 24518, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1556.2, -3906.92, 132.684, 1.84218, 300, 0, 0, 11544, 0, 0, 0, 0, 0, 0, 0, '', 0);


-- The Yeti Next Door (11284)
DELETE FROM conditions WHERE SourceTypeOrReferenceId IN(13, 17) AND SourceEntry=43209;
INSERT INTO conditions VALUES (17, 0, 43209, 0, 0, 29, 0, 24178, 10, 0, 0, 60, 0, '', 'Place Ram Meat can only be used Near npc');
INSERT INTO conditions VALUES (13, 1, 43209, 0, 0, 31, 0, 3, 24178, 0, 0, 0, 0, '', 'Target entry 24178');

SET @ENTRY := 24178;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,12734,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ground Smash'),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,41,8000,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Just Died - Despawn In 8000 ms'),
(@ENTRY,0,3,4,8,0,0,0,43209,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Spellhit Place Ram Meat - Remove Flags Immune To Players & Immune To NPCs'),
(@ENTRY,0,4,5,61,0,0,0,43209,0,0,0,28,6606,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Spellhit Place Ram Meat - Remove Aura Self Visual - Sleep Until Cancelled  (DND)'),
(@ENTRY,0,5,0,61,0,0,0,43209,0,0,0,91,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'On Spellhit Place Ram Meat - Remove Aura Self Visual - Sleep Until Cancelled  (DND)');

DELETE FROM `creature_text` WHERE `creatureid`=24178;
INSERT INTO `creature_text` (`creatureid`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextID`,`TextRange`,`comment`) VALUES
(24178,0,0,'Arrrrrhhhhhhhh!!!',1,0,100,1,0,0,0,0,'Inner Turmoil text 0');

UPDATE `creature_template` SET `unit_flags` = 33536 WHERE `entry` = 24178;

DELETE FROM `creature_template_addon` WHERE (`entry`=24178);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (24178, 0, 0, 3, 1, 0, 6606);



DELETE FROM `creature` WHERE `id`=24178;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(210116628, 24178, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 2637.74, -5052.9, 295.61, 1.49974, 300, 0, 0, 11544, 3231, 0, 0, 0, 0, 0, 0, '', 0);

-- http://ru.wowhead.com/quest=11329
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=186660;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (186660,18666000);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Frostblade Shrine script
(186660,1,0,0,64,0,100,0,0,0,0,0,80,18666000,0,2,0,0,0,1,0,0,0,0,0,0,0, 'On Go use start script'),
(18666000,9,0,0,0,0,100,0,0,0,0,0,12,24285,6,30000,0,0,0,1,0,0,0,0,0,0,0, 'Summon Северная рыба-шип');


-- http://www.wowhead.com/quest=11418/we-call-him-steelfeather
-- Steelfeather SAI
SET @ENTRY := 24514;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,49865,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Eye Peck on Aggro"),
(@ENTRY,0,1,0,9,0,100,0,0,5,9000,11000,11,18144,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cast Swoop on Close"),
(@ENTRY,0,2,1,8,0,100,0,43969,0,0,0,33,24515,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");


DELETE FROM `creature` WHERE `id`=24329;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(117440, 24329, 571, 495, 4061, 1, 0, 0, 0, -1, 0, 0, 2259.22, -5826.7, 236.97, 3.17556, 600, 5, 0, 10000, 3155, 1, 0, 0, 0, 0, 0, '', 0),
(210116631, 24329, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 2195, -5784.29, 225.071, 1.75211, 300, 0, 0, 22316, 3155, 0, 0, 0, 0, 0, 0, '', 0),
(210116632, 24329, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 2217.71, -5735.17, 226.579, 2.48882, 300, 0, 0, 22316, 3155, 0, 0, 0, 0, 0, 0, '', 0),
(210116633, 24329, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 2160.31, -5680.4, 223.721, 3.38454, 300, 0, 0, 22316, 3155, 0, 0, 0, 0, 0, 0, '', 0),
(210116634, 24329, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 2109.86, -5638.04, 221.626, 2.98634, 300, 0, 0, 22316, 3155, 0, 0, 0, 0, 0, 0, '', 0),
(210116635, 24329, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 2073.73, -5600.56, 219.629, 1.20035, 300, 0, 0, 22316, 3155, 0, 0, 0, 0, 0, 0, '', 0);


DELETE FROM `creature` WHERE `id`=24381;

UPDATE `creature_template` SET `gossip_menu_id` = 24381, `npcflag` = 1 WHERE `entry` = 24381;

REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId` ,`OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES('24381','0','0','Runes changing','0','1','1','29416');

SET @ENTRY := 24381;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,24381,0,0,0,33,24381,0,0,0,0,0,7,0,0,0,0,0,0,0,"Orgus - On Gossip - Kill Credit");
UPDATE `creature_template` SET `unit_flags` = 33280 WHERE `entry` = 24381;
UPDATE `creature_template` SET `faction` = 35 WHERE `entry` = 24381;

UPDATE `creature` SET `spawndist` = 3, `MovementType` = 1 WHERE `id` IN (24316,24329);


DELETE FROM `creature` WHERE `id`=24371;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(116967, 24371, 571, 495, 4066, 1, 0, 0, 0, -1, 0, 0, 2732.15, -5421.01, 410.783, 4.80685, 300, 0, 0, 18582, 3231, 0, 0, 0, 0, 0, 0, '', 0),
(210116638, 24371, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 2651.64, -5589.14, 353.29, 4.06235, 300, 0, 0, 23088, 3231, 0, 0, 0, 0, 0, 0, '', 0);



REPLACE INTO conditions VALUES (13, 1, 49859, 0, 0, 31, 0, 3, 24345, 0, 0, 0, 0, '', 'Target entry 24178');

UPDATE `creature_template` SET `unit_flags` = 33346 WHERE `entry` = 24345;

SET @ENTRY := 24345;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,49859,0,0,0,33,24345,0,0,0,0,0,7,0,0,0,0,0,0,0,"on Spell Hit - Give Credit");


UPDATE `creature_template` SET `minlevel` = 7, `maxlevel` = 7, `unit_flags` = 32768 WHERE `entry` = 24345;

UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '23989' AND `Item` = '33289'; 
UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '23990' AND `Item` = '33289'; 
UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '23991' AND `Item` = '33289'; 
UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '23992' AND `Item` = '33289'; 
UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '23993' AND `Item` = '33289'; 
UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '24013' AND `Item` = '33289'; 
UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '24014' AND `Item` = '33289'; 


UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '23989' AND `Item` = '33347'; 
UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '23990' AND `Item` = '33347'; 
UPDATE `creature_loot_template` SET `Chance` = '100' WHERE `Entry` = '23991' AND `Item` = '33347'; 


-- Wyrmcaller Vile SAI
SET @ENTRY := 24029;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cast bolt"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Frost Armor on Spawn"),
(@ENTRY,0,2,0,9,0,100,0,0,10,14000,18000,11,15532,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Frost Nova on Close"),
(@ENTRY,0,3,0,1,0,100,1,1000,1000,1000,1000,11,67734,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cast Aura on Spawn"),
(@ENTRY,0,4,0,6,0,100,1,0,0,0,0,12,24019,6,10000,0,0,0,0,1,0,0,0,0,0,0,'Cast Summon on Death');


UPDATE `creature_template` SET `HoverHeight` = 0 WHERE `entry` = 24019;

DELETE FROM `creature` WHERE `id`=24019;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`unit_flags2`,`unit_flags3`,`dynamicflags`,`ScriptName`,`VerifiedBuild`) VALUES
(130815, 24019, 571, 495, 4006, 1, 0, 0, 0, -1, 16033, 0, 2731.56, -3384.44, 330.092, 2.36498, 300, 5, 0, 18582, 0, 1, 0, 0, 0, 0, 0, '', 0),
(210116641, 24019, 571, 0, 0, 1, 0, 0, 0, -1, 0, 0, 2822.68, -3651.67, 243.436, 1.85438, 300, 0, 0, 23088, 0, 0, 0, 0, 0, 0, 0, '', 0);

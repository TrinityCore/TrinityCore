-- 
DELETE FROM `creature` WHERE `guid` IN (273379, 278282);
DELETE FROM `creature_template_addon` WHERE `entry`=50374;
UPDATE `creature` SET `position_x`=1704.6558, `position_y`=1698.945, `position_z`=134.2911, `orientation`=1.6375 WHERE `guid`=325069;
DELETE FROM `creature` WHERE `guid` IN (@GUID, @GUID+1);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(273379, 50373, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1695.84, 1688.49, 135.279, 6.15358, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0),
(278282, 50373, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1707.56, 1702.21, 133.969, 4.64955, 300, 0, 0, 42, 0, 0, 0, 0, 0, 0);
-- Aradne SAI
SET @ENTRY := 50372;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,53,0,50372,1,0,0,0,1,0,0,0,0,0,0,0,"Aradne - On Reset - Start Waypoint"),
(@ENTRY,0,1,0,40,0,100,0,2,50372,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Aradne - On Waypoint 2 Reached - Run Script"),
(@ENTRY,0,2,0,40,0,100,0,4,50372,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Aradne - On Waypoint 4 Reached - Run Script"),
(@ENTRY,0,3,0,40,0,100,0,18,50372,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Aradne - On Waypoint 18 Reached - Run Script"),
(@ENTRY,0,4,0,40,0,100,0,25,50372,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Aradne - On Waypoint 25 Reached - Run Script");
-- Actionlist SAI
SET @ENTRY := 5037200;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,54,7000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aradne - On Script - Pause Waypoint"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,11,93446,0,0,0,0,0,19,50373,5,0,0,0,0,0,"Aradne - On Script - Cast 'Raise Undead'"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aradne - On Script - Say Line 0"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,50373,10,0,0,0,0,0,"Aradne - On Script - Set Data 1 1");
-- Deathknell Grave Target SAI
SET @ENTRY := 50373;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,11,93447,2,0,0,0,0,1,0,0,0,0,0,0,0,"Deathknell Grave Target - On Data Set 1 1 - Cast '<Spell not found!>'"),
(@ENTRY,0,1,0,25,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathknell Grave Target - On Reset - Set Visibility Off");
DELETE FROM `creature_text` WHERE `entry`=50372;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(50372, 0, 0, 'You are returned to life. The Banshee Queen asks for your service.', 12, 0, 100, 0, 0, 0, 0, 0, 'Aradne'),
(50372, 0, 1, 'Rise from the grave and serve the Dark Lady!', 12, 0, 100, 0, 0, 0, 0, 0, 'Aradne'),
(50372, 0, 2, 'Waken, sleeper. Your new life awaits.', 12, 0, 100, 0, 0, 0, 0, 0, 'Aradne');
DELETE FROM `waypoints` WHERE `entry`=50372;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(50372, 1, 1698.53, 1687.82, 134.825, 'Aradne'),
(50372, 2, 1696.9, 1688.16, 135.093, 'Aradne'),
(50372, 3, 1696.82, 1680.22, 134.648, 'Aradne'),
(50372, 4, 1695.54, 1680.51, 134.857, 'Aradne'),
(50372, 5, 1694.45, 1675.17, 134.582, 'Aradne'),
(50372, 6, 1691.49, 1672.14, 134.725, 'Aradne'),
(50372, 7, 1686.68, 1671.13, 135.499, 'Aradne'),
(50372, 8, 1683.32, 1672.1, 136.382, 'Aradne'),
(50372, 9, 1676.21, 1673.95, 137.504, 'Aradne'),
(50372, 10, 1672.78, 1674.63, 138.265, 'Aradne'),
(50372, 11, 1671.65, 1680.4, 139.247, 'Aradne'),
(50372, 12, 1672.95, 1685.73, 139.639, 'Aradne'),
(50372, 13, 1673.6, 1688.58, 139.695, 'Aradne'),
(50372, 14, 1675.72, 1697.68, 140.331, 'Aradne'),
(50372, 15, 1682.36, 1695.94, 138.045, 'Aradne'),
(50372, 16, 1688.03, 1692.28, 137.092, 'Aradne'),
(50372, 17, 1686.76, 1686.93, 137.07, 'Aradne'),
(50372, 18, 1683.31, 1686.49, 137.777, 'Aradne'),
(50372, 19, 1688.84, 1685.97, 136.565, 'Aradne'),
(50372, 20, 1701.76, 1685.93, 134.241, 'Aradne'),
(50372, 21, 1701.76, 1685.93, 134.241, 'Aradne'),
(50372, 22, 1708.09, 1692.04, 133.826, 'Aradne'),
(50372, 23, 1707.34, 1696.12, 133.928, 'Aradne'),
(50372, 24, 1704.29, 1699.33, 134.399, 'Aradne'),
(50372, 25, 1707.4, 1700.54, 134.079, 'Aradne');
-- Risen Dead SAI
SET @ENTRY := 50374;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,87,@ENTRY*100+00,@ENTRY*100+01,@ENTRY*100+02,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Just Summoned - Run Random Script");
/* first random script */
-- Actionlist SAI
SET @ENTRY := 5037400;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Say Line 0"),
(@ENTRY,9,1,0,0,0,100,0,4000,4000,0,0,3,1501,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Morph To Creature Mindless Zombie"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Say Line 5"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,75,44427,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Add Aura 'Enrage'"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,53,1,5037400,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Start Waypoint"),
(@ENTRY,9,5,0,0,0,100,0,0,0,0,0,41,9000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Despawn In 9000 ms");
DELETE FROM `waypoints` WHERE `entry`=5037400;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(5037400, 1, 1695.182861, 1672.756714, 134.063858, 'Risen Dead'),
(5037400, 2, 1669.666260, 1661.953979, 140.546326, 'Risen Dead');
DELETE FROM `creature_text` WHERE `entry`=50372;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `TextRange`, `comment`, `BroadcastTextId`) VALUES
(50372, 0, 0, 'Rise from the grave and serve the Dark Lady!', 12, 0, 100, 1, 0, 0, 0, 'Aradne', 50118),
(50372, 0, 1, 'In the name of Sylvanas, the Banshee Queen, I bestow this gift upon you!', 12, 0, 100, 1, 0, 0, 0, 'Aradne', 50119),
(50372, 0, 2, 'Rise from death\'s slumber and join your brothers!', 12, 0, 100, 1, 0, 0, 0, 'Aradne', 50120),
(50372, 0, 3, 'Waken, sleeper. Your new life awaits.', 12, 0, 100, 1, 0, 0, 0, 'Aradne', 50121),
(50372, 0, 4, 'You are returned to life. The Banshee Queen asks for your service.', 12, 0, 100, 1, 0, 0, 0, 'Aradne', 50122);
DELETE FROM `creature_text` WHERE `entry`=50374;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `TextRange`, `comment`, `BroadcastTextId`) VALUES
(50374, 0, 0, 'I never asked for this! Leave me alone!', 12, 0, 100, 5, 0, 0, 0, 'Risen Dead', 50201),
(50374, 1, 0, 'What magic is this that turn back the hand of death?', 12, 0, 100, 6, 0, 0, 0, 'Risen Dead', 50197),
(50374, 1, 1, 'This is Lady Sylvanas\'s doing?', 12, 0, 100, 6, 0, 0, 0, 'Risen Dead', 50196),
(50374, 2, 0, 'If the Banshee Queen has offered me this chance, I will gladly serve.', 12, 0, 100, 1, 0, 0, 0, 'Risen Dead', 50200),
(50374, 2, 1, 'What use has the Dark Lady for me?', 12, 0, 100, 6, 0, 0, 0, 'Risen Dead', 50199),
(50374, 3, 0, 'What... what\'s happening to me? Why have you done this to me?', 12, 0, 100, 6, 0, 0, 0, 'Risen Dead', 50194),
(50374, 3, 1, 'I... I don\'t remember... Why have you done this?', 12, 0, 100, 6, 0, 0, 0, 'Risen Dead', 50198),
(50374, 4, 0, 'I should be dead and to death I will return!', 12, 0, 100, 5, 0, 0, 0, 'Risen Dead', 50195),
-- emotes
(50374, 5, 0, '%s enrages and transforms into a Mindless Zombie and runs away.', 16, 0, 100, 0, 0, 0, 0, 'Risen Dead', 0),
(50374, 6, 0, '%s commits suicide.', 16, 0, 100, 0, 0, 0, 0, 'Risen Dead', 0),
(50374, 7, 0, '%s walks off towards the barracks.', 16, 0, 100, 0, 0, 0, 0, 'Risen Dead', 0);
/* second randowm script */
-- Actionlist SAI
SET @ENTRY := 5037401;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Say Line 1"),
(@ENTRY,9,1,0,0,0,100,0,4000,4000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Say Line 2"),
(@ENTRY,9,2,0,0,0,100,0,2000,2000,0,0,53,0,5037401,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Start Waypoint"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Say Line 7"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,41,9000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Despawn In 9000 ms");
DELETE FROM `waypoints` WHERE `entry`=5037401;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(5037401, 1, 1696.713013, 1674.248047, 134.094315, 'Risen Dead'),
(5037401, 2, 1696.786987, 1660.868164, 130.983063, 'Risen Dead');
/* third random script */
-- Actionlist SAI
SET @ENTRY := 5037402;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Say Line 3"),
(@ENTRY,9,1,0,0,0,100,0,4000,4000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Say Line 4"),
(@ENTRY,9,2,0,0,0,100,0,3000,3000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Say Line 6"),
(@ENTRY,9,3,0,0,0,100,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Risen Dead - On Script - Kill Self");

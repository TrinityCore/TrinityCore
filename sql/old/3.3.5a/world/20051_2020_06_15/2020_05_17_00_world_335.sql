-- Searing Gorge Dark Iron Pillow spawns for quest http://www.wowhead.com/quest=7702 retail:28057
SET @OGUID := 21941;
SET @MOTHER   := 763;
SET @LASTGUID := 23;
SET @ACTIVE   := 8; -- Max number of active spawns
SET @TIMER    := 30; -- Respawn timer in seconds

-- Dark Iron Pillow spawns for Searing Gorge
DELETE FROM `gameobject` WHERE `id`=179828;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID AND @OGUID+@LASTGUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`,  `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 179828, 0, 1, 1, -6569.39, -1335.83, 210.199, 2.33874, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+1, 179828, 0, 1, 1, -6527.64, -1340.23, 212.095, 1.832595, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+2, 179828, 0, 1, 1, -6518.91, -1364.86, 210.541, 5.654869, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+3, 179828, 0, 1, 1, -6572.96, -1327.58, 212.095, 3.560473, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+4, 179828, 0, 1, 1, -6570.39, -1332.69, 212.095, 5.375615, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+5, 179828, 0, 1, 1, -6547.68, -1325.57, 212.376, 2.757613, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+6, 179828, 0, 1, 1, -6575.96, -1323.57, 210.144, 4.293513, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+7, 179828, 0, 1, 1, -6552.55, -1317.99, 212.64, 4.939284, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+8, 179828, 0, 1, 1, -6576.94, -1319.12, 210.249, 6.03884, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+9, 179828, 0, 1, 1, -6551.49, -1318.46, 210.419, 0.6981314, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+10, 179828, 0, 1, 1, -6528.67, -1339.02, 210.124, 2.670348, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+11, 179828, 0, 1, 1, -6543.81, -1358.71, 210.544, 3.752462, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+12, 179828, 0, 1, 1, -6554.68, -1351.74, 212.682, 2.146753, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+13, 179828, 0, 1, 1, -6562.07, -1344.44, 212.619, 1.256636, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+14, 179828, 0, 1, 1, -6554.33, -1313.8, 210.26, 5.288348, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+15, 179828, 0, 1, 1, -6543.61, -1329.85, 212.564, 5.393069, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+16, 179828, 0, 1, 1, -6544.77, -1329.61, 210.26, 5.305802, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+17, 179828, 0, 1, 1, -6551.14, -1354.85, 210.421, 4.363324, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+18, 179828, 0, 1, 1, -6550.27, -1321.75, 210.433, 5.445428, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+19, 179828, 0, 1, 1, -6518.33, -1342.21, 212.095, 4.991644, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+20, 179828, 0, 1, 1, -6558.36, -1347.93, 210.26, 3.351047, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+21, 179828, 0, 1, 1, -6531.65, -1337.63, 210.18, 4.398232, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+22, 179828, 0, 1, 1, -6508.78, -1365.26, 212.859, 0.6457717, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+23, 179828, 0, 1, 1, -6528.76, -1363.6, 212.657, 2.617989, 0, 0, 0, 1, @TIMER, 255, 1); -- Dark Iron Pillow

DELETE FROM `gameobject_addon` WHERE `guid` IN(6974,6976,6991,6995,7003,7005,7006,7009);
DELETE FROM `spawn_group` WHERE `groupId`=2 AND `spawnType`=1 AND `spawnId` IN (6974,6976,6991,6995,7003,7005,7006,7009);

-- Add mother pool to pool template
DELETE FROM `pool_template` WHERE `entry`=@MOTHER;
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(@MOTHER,@ACTIVE, 'Searing Gorge Dark Iron Pillow Mother pool');

-- Pool Dark Iron Pillow Spawnpoints
DELETE FROM `pool_members` WHERE `spawnId` BETWEEN @OGUID AND @OGUID+@LASTGUID;
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES 
(1,@OGUID+0,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(1,@OGUID+1,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(1,@OGUID+2,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(1,@OGUID+3,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(1,@OGUID+4,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(1,@OGUID+5,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(1,@OGUID+6,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(1,@OGUID+7,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(1,@OGUID+8,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(1,@OGUID+9,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(1,@OGUID+10,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(1,@OGUID+11,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(1,@OGUID+12,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(1,@OGUID+13,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(1,@OGUID+14,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(1,@OGUID+15,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(1,@OGUID+16,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(1,@OGUID+17,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(1,@OGUID+18,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(1,@OGUID+19,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(1,@OGUID+20,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(1,@OGUID+21,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(1,@OGUID+22,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(1,@OGUID+23,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry` IN (14635,14636);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE  `entry` IN (179828,179829);
DELETE FROM `smart_scripts` WHERE `entryorguid`IN (179828) AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN (17982800,17982801) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN (14635,14636) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 1463500 AND 1463519 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(14635, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 88, 1463500, 1463509, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sleepy Dark Iron  - On Just Spawned - Run Random Script'),
(14635, 0, 1, 0, 38, 0, 100, 1, 1, 1, 0, 0, 1, 0, 5000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sleepy Dark Iron  - On Data set - Say'),
(14635, 0, 2, 0, 52, 0, 100, 0, 0, 14635, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sleepy Dark Iron  - On text over - Say'),
(14636, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chambermaid Pillaclencher - On Just Spawned - Say'),
(14636, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 23408, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Chambermaid Pillaclencher - On Death - Cast Drop Pillow DND'),
(14636, 0, 2, 0, 9, 0, 100, 0, 0, 40, 3000, 15000, 11, 23416, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Chambermaid Pillaclencher - On Range - Cast Pillow Fight'),
(14636, 0, 3, 0, 0, 0, 100, 0, 5000, 9000, 15000, 18000, 11, 23417, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Chambermaid Pillaclencher - IC - Cast Smother'),
(179828, 1, 0, 0, 70, 1, 100, 0, 3, 0, 0, 0, 12, 14636, 8, 0, 0, 0, 0, 8, 0, 0, 0, -6539.3, -1347.27, 208.986, 2.60054, 'Dark Iron Pillow - On State Changed - Summon Chambermaid Pillaclencher'),
(179828, 1, 1, 2, 70, 2, 100, 0, 3, 0, 0, 0, 12, 14635, 8, 0, 0, 0, 0, 8, 0, 0, 0, -6577.97, -1289.04, 208.826, 2.60054, 'Dark Iron Pillow - On State Changed - Summon Sleepy Dark Iron Worker'),
(179828, 1, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 12, 14635, 8, 0, 0, 0, 0, 8, 0, 0, 0, -6580.84, -1290.89, 208.826, 2.44346, 'Dark Iron Pillow - On State Changed - Summon Sleepy Dark Iron Worker'),
(179828, 1, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 12, 14635, 8, 0, 0, 0, 0, 8, 0, 0, 0, -6575.2, -1287.64, 208.826, 4.53786, 'Dark Iron Pillow - On State Changed - Summon Sleepy Dark Iron Worker'),
(179828, 1, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 12, 14635, 8, 0, 0, 0, 0, 8, 0, 0, 0, -6573.95, -1291.89, 208.826, 0.0349066, 'Dark Iron Pillow - On State Changed - Summon Sleepy Dark Iron Worker'),
(179828, 1, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 12, 14635, 8, 0, 0, 0, 0, 8, 0, 0, 0, -6576.88, -1295.08, 208.826, 5.46288, 'Dark Iron Pillow - On State Changed - Summon Sleepy Dark Iron Worker'),
(179828, 1, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 12, 14635, 8, 0, 0, 0, 0, 8, 0, 0, 0, -6582.04, -1287.82, 208.826, 4.4855, 'Dark Iron Pillow - On State Changed - Summon Sleepy Dark Iron Worker'),
(179828, 1, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 12, 14635, 8, 0, 0, 0, 0, 8, 0, 0, 0, -6577.63, -1285.87, 208.826, 4.57276, 'Dark Iron Pillow - On State Changed - Summon Sleepy Dark Iron Worker'),
(179828, 1, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 12, 14635, 8, 0, 0, 0, 0, 8, 0, 0, 0, -6582.85, -1293.73, 208.826, 1.67552, 'Dark Iron Pillow - On State Changed - Summon Sleepy Dark Iron Worker'),
(179828, 1, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 12, 14635, 8, 0, 0, 0, 0, 8, 0, 0, 0, -6571.29, -1286.36, 208.826, 4.11898, 'Dark Iron Pillow - On State Changed - Summon Sleepy Dark Iron Worker'),
(179828, 1, 10, 11, 61, 0, 100, 0, 0, 0, 0, 0, 12, 14635, 8, 0, 0, 0, 0, 8, 0, 0, 0, -6580.44, -1285.85, 208.826, 4.45059, 'Dark Iron Pillow - On State Changed - Summon Sleepy Dark Iron Worker'),
(179828, 1, 11, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 14635, 0, 0, 0, 0, 0, 0, 'Dark Iron Pillow - On State Changed - Set data to Sleepy Dark Iron Worker'),
(179828, 1, 12, 0, 64, 0, 100, 0, 2, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Iron Pillow - On Gossip Hello - Set Phase 1'),
(179828, 1, 13, 0, 64, 0, 100, 0, 2, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dark Iron Pillow - On Gossip Hello - Set Phase 2'),
(1463500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, 1463500, 1, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Sleepy Dark Iron Worker - Script - Start WP'),
(1463501, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, 1463501, 1, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Sleepy Dark Iron Worker - Script - Start WP'),
(1463502, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, 1463502, 1, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Sleepy Dark Iron Worker - Script - Start WP'),
(1463503, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, 1463503, 1, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Sleepy Dark Iron Worker - Script - Start WP'),
(1463504, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, 1463504, 1, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Sleepy Dark Iron Worker - Script - Start WP'),
(1463505, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, 1463505, 1, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Sleepy Dark Iron Worker - Script - Start WP'),
(1463506, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, 1463506, 1, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Sleepy Dark Iron Worker - Script - Start WP'),
(1463507, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, 1463507, 1, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Sleepy Dark Iron Worker - Script - Start WP'),
(1463508, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, 1463508, 1, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Sleepy Dark Iron Worker - Script - Start WP'),
(1463509, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 0, 1463509, 1, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Sleepy Dark Iron Worker - Script - Start WP');

DELETE FROM `creature_text` WHERE `CreatureID`IN(14636,14635);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(14636, 0, 0, 'Thieves! Scallywags! Rapscallions! Come face me gigantic pillas!', 14, 0, 100, 0, 0, 0, 9810, 'Chambermaid Pillaclencher to Player'),
(14635, 0, 0, 'Our pillas! Someone has stolen our pillas!', 14, 0, 100, 0, 0, 0, 9799, 'Sleepy Dark Iron Worker to Player to Player'),
(14635, 1, 0, "We'll not let this act of madness go unpunished!", 14, 0, 100, 0, 0, 0, 9800, 'Sleepy Dark Iron Worker to Player to Player');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=179828 AND `SourceId`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 13, 179828, 1, 0, 2, 0, 18943, 19, 0, 0, 0, 0, '', 'Run SAI only if objective count of Kill em with sleep deprivation is 20 Pillows'),
(22, 13, 179828, 1, 0, 2, 0, 18943, 20, 0, 1, 0, 0, '', 'Run SAI only if objective count of Kill em with sleep deprivation is 20 Pillows'),
(22, 13, 179828, 1, 0, 29, 1, 14636, 100, 0, 1, 0, 0, '', 'Run SAI only if there is no Chambermaid Pillaclencher nearby'),
(22, 14, 179828, 1, 0, 2, 0, 18943, 11, 0, 0, 0, 0, '', 'Run SAI only if objective count of Kill em with sleep deprivation is 12 Pillows'),
(22, 14, 179828, 1, 0, 2, 0, 18943, 12, 0, 1, 0, 0, '', 'Run SAI only if objective count of Kill em with sleep deprivation is 12 Pillows'),
(22, 14, 179828, 1, 0, 29, 1, 14635, 100, 0, 1, 0, 0, '', 'Run SAI only if there is no Sleepy Dark Iron Worker nearby');

DELETE FROM `waypoints` WHERE `entry` BETWEEN 1463500 AND 1463509;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(1463500,1, -6571.01,-1310.01,208.70,'Dark Iron Worker'),
(1463500,2, -6565.90,-1330.04,208.83,'Dark Iron Worker'),
(1463500,3, -6554.73,-1341.21,208.93,'Dark Iron Worker'),
(1463500,4, -6527.23,-1350.97,209.94,'Dark Iron Worker'),
(1463500,5, -6499.62,-1352.41,210.86,'Dark Iron Worker'),
(1463500,6, -6477.65,-1353.51,212.10,'Dark Iron Worker'),
(1463500,7, -6497.14,-1352.41,210.86,'Dark Iron Worker'),
(1463500,8, -6521.47,-1347.69,209.94,'Dark Iron Worker'),
(1463500,9, -6551.05,-1343.47,208.93,'Dark Iron Worker'),
(1463500,10, -6565.92,-1328.37,208.83,'Dark Iron Worker'),
(1463501,1, -6568.69,-1306.02,208.70,'Dark Iron Worker'),
(1463501,2, -6560.79,-1322.42,208.83,'Dark Iron Worker'),
(1463501,3, -6553.94,-1341.82,208.93,'Dark Iron Worker'),
(1463501,4, -6526.74,-1351.10,209.94,'Dark Iron Worker'),
(1463501,5, -6498.66,-1347.99,210.86,'Dark Iron Worker'),
(1463501,6, -6480.37,-1352.99,212.10,'Dark Iron Worker'),
(1463501,7, -6497.48,-1350.84,210.86,'Dark Iron Worker'),
(1463501,8, -6523.57,-1350.01,209.94,'Dark Iron Worker'),
(1463501,9, -6551.08,-1340.64,208.93,'Dark Iron Worker'),
(1463501,10, -6564.98,-1329.96,208.83,'Dark Iron Worker'),
(1463502,1, -6566.57,-1311.09,208.70,'Dark Iron Worker'),
(1463502,2, -6565.01,-1323.49,208.83,'Dark Iron Worker'),
(1463502,3, -6554.39,-1334.81,208.93,'Dark Iron Worker'),
(1463502,4, -6519.73,-1349.07,209.94,'Dark Iron Worker'),
(1463502,5, -6495.62,-1346.78,210.86,'Dark Iron Worker'),
(1463502,6, -6476.91,-1346.77,212.10,'Dark Iron Worker'),
(1463502,7, -6494.62,-1352.22,210.86,'Dark Iron Worker'),
(1463502,8, -6525.72,-1355.94,209.94,'Dark Iron Worker'),
(1463502,9, -6555.21,-1343.24,208.93,'Dark Iron Worker'),
(1463502,10, -6556.97,-1326.98,208.83,'Dark Iron Worker'),
(1463503,1, -6570.05,-1306.44,208.70,'Dark Iron Worker'),
(1463503,2, -6565.88,-1325.34,208.83,'Dark Iron Worker'),
(1463503,3, -6546.48,-1337.35,208.93,'Dark Iron Worker'),
(1463503,4, -6523.84,-1349.33,209.94,'Dark Iron Worker'),
(1463503,5, -6490.75,-1351.55,210.86,'Dark Iron Worker'),
(1463503,6, -6479.97,-1353.76,212.10,'Dark Iron Worker'),
(1463503,7, -6491.59,-1354.88,210.86,'Dark Iron Worker'),
(1463503,8, -6519.30,-1352.83,209.94,'Dark Iron Worker'),
(1463503,9, -6545.53,-1339.51,208.93,'Dark Iron Worker'),
(1463503,10, -6563.64,-1327.15,208.83,'Dark Iron Worker'),
(1463504,1, -6569.32,-1303.39,208.70,'Dark Iron Worker'),
(1463504,2, -6559.30,-1327.23,208.83,'Dark Iron Worker'),
(1463504,3, -6550.54,-1343.35,208.93,'Dark Iron Worker'),
(1463504,4, -6526.89,-1355.23,209.94,'Dark Iron Worker'),
(1463504,5, -6497.63,-1351.14,210.86,'Dark Iron Worker'),
(1463504,6, -6477.18,-1348.72,212.10,'Dark Iron Worker'),
(1463504,7, -6492.91,-1348.36,210.86,'Dark Iron Worker'),
(1463504,8, -6523.31,-1354.16,209.94,'Dark Iron Worker'),
(1463504,9, -6553.10,-1339.00,208.93,'Dark Iron Worker'),
(1463504,10, -6557.23,-1328.21,208.83,'Dark Iron Worker'),
(1463505,1, -6564.52,-1308.97,208.70,'Dark Iron Worker'),
(1463505,2, -6560.33,-1328.83,208.83,'Dark Iron Worker'),
(1463505,3, -6550.13,-1338.94,208.93,'Dark Iron Worker'),
(1463505,4, -6520.88,-1347.87,209.94,'Dark Iron Worker'),
(1463505,5, -6492.72,-1355.62,210.86,'Dark Iron Worker'),
(1463505,6, -6478.00,-1347.03,212.10,'Dark Iron Worker'),
(1463505,7, -6498.29,-1351.96,210.86,'Dark Iron Worker'),
(1463505,8, -6525.09,-1353.60,209.94,'Dark Iron Worker'),
(1463505,9, -6549.43,-1334.96,208.93,'Dark Iron Worker'),
(1463505,10, -6564.78,-1322.71,208.83,'Dark Iron Worker'),
(1463506,1, -6569.81,-1302.34,208.70,'Dark Iron Worker'),
(1463506,2, -6566.72,-1324.22,208.83,'Dark Iron Worker'),
(1463506,3, -6552.36,-1342.93,208.93,'Dark Iron Worker'),
(1463506,4, -6528.49,-1349.84,209.94,'Dark Iron Worker'),
(1463506,5, -6492.48,-1353.18,210.86,'Dark Iron Worker'),
(1463506,6, -6481.95,-1350.36,212.10,'Dark Iron Worker'),
(1463506,7, -6499.13,-1353.06,210.86,'Dark Iron Worker'),
(1463506,8, -6527.13,-1355.97,209.94,'Dark Iron Worker'),
(1463506,9, -6548.80,-1335.09,208.93,'Dark Iron Worker'),
(1463506,10, -6560.04,-1325.01,208.83,'Dark Iron Worker'),
(1463507,1, -6567.03,-1309.58,208.70,'Dark Iron Worker'),
(1463507,2, -6559.00,-1328.47,208.83,'Dark Iron Worker'),
(1463507,3, -6551.75,-1338.33,208.93,'Dark Iron Worker'),
(1463507,4, -6522.69,-1353.94,209.94,'Dark Iron Worker'),
(1463507,5, -6493.91,-1353.89,210.86,'Dark Iron Worker'),
(1463507,6, -6481.68,-1351.74,212.10,'Dark Iron Worker'),
(1463507,7, -6491.77,-1352.91,210.86,'Dark Iron Worker'),
(1463507,8, -6526.63,-1349.93,209.94,'Dark Iron Worker'),
(1463507,9, -6546.77,-1337.66,208.93,'Dark Iron Worker'),
(1463507,10, -6566.42,-1325.94,208.83,'Dark Iron Worker'),
(1463508,1, -6566.35,-1310.61,208.70,'Dark Iron Worker'),
(1463508,2, -6558.86,-1329.27,208.83,'Dark Iron Worker'),
(1463508,3, -6552.16,-1335.98,208.93,'Dark Iron Worker'),
(1463508,4, -6520.94,-1348.59,209.94,'Dark Iron Worker'),
(1463508,5, -6491.11,-1355.25,210.86,'Dark Iron Worker'),
(1463508,6, -6484.48,-1350.91,212.10,'Dark Iron Worker'),
(1463508,7, -6491.73,-1352.03,210.86,'Dark Iron Worker'),
(1463508,8, -6520.12,-1347.55,209.94,'Dark Iron Worker'),
(1463508,9, -6546.50,-1337.46,208.93,'Dark Iron Worker'),
(1463508,10, -6563.04,-1329.60,208.83,'Dark Iron Worker'),
(1463509,1, -6569.60,-1301.85,208.70,'Dark Iron Worker'),
(1463509,2, -6562.01,-1327.36,208.83,'Dark Iron Worker'),
(1463509,3, -6545.53,-1341.85,208.93,'Dark Iron Worker'),
(1463509,4, -6523.89,-1353.44,209.94,'Dark Iron Worker'),
(1463509,5, -6498.20,-1351.68,210.86,'Dark Iron Worker'),
(1463509,6, -6478.66,-1350.74,212.10,'Dark Iron Worker'),
(1463509,7, -6496.03,-1355.80,210.86,'Dark Iron Worker'),
(1463509,8, -6521.96,-1349.44,209.94,'Dark Iron Worker'),
(1463509,9, -6553.02,-1340.34,208.93,'Dark Iron Worker'),
(1463509,10, -6559.26,-1325.82,208.83,'Dark Iron Worker');

SET @Guid := 29727;

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry`=4781;
UPDATE `gameobject_template` SET `AIName`= 'SmartGameObjectAI' WHERE`entry` =20920;
DELETE FROM `smart_scripts` WHERE `entryorguid` =20920 AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4781 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=478100 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4781,0,0,1,54,0,100,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,'Snufflenose Gopher - On Just Summoned - Say Line 0'),
(4781,0,1,0,61,0,100,0,0,0,0,0,29,1,0,0,0,0,0,23,0,0,0,0,0,0,0,'Snufflenose Gopher - On Just Summoned - Follow Summoner'),
(4781,0,2,3,38,0,100,0,1,1,10000,10000,29,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snufflenose Gopher - On Data Set - Stop Following Invoker'),
(4781,0,3,4,61,0,100,0,0,0,0,0,69,0,0,0,0,0,0,20,20920,0,0,0,0,0,0,'Snufflenose Gopher - On Data Set - Move to Blueleaf Tuber'),
(4781,0,4,5,61,0,100,0,0,0,0,0,80,478100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Snufflenose Gopher - On Data Set - Run Script'),
(4781,0,5,6,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,'Snufflenose Gopher - On Data Set - Say Line 1'),
(4781,0,6,0,61,0,100,0,0,0,0,0,8,0,0,0,0,0,0,23,0,0,0,0,0,0,0,'Snufflenose Gopher - On Data Set - Set Passive'),
(4781,0,7,0,8,0,100,0,8283,0,10000,10000,45,1,1,0,0,0,0,20,20920,40,0,0,0,0,0,'Snufflenose Gopher - On Spellhit (Snufflenose Command) - Set Data Blueleaf Tuber'),
(478100,9,0,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,23,0,0,0,0,0,0,0,'Snufflenose Gopher - Script - Say Line 2'),
(478100,9,1,0,0,0,100,0,0,0,0,0,104,0,0,0,0,0,0,20,20920,10,0,0,0,0,0,'Snufflenose Gopher - Script - Set Flags on Blueleaf Tuber'),
(478100,9,2,0,0,0,100,0,0,0,0,0,70,300,0,0,0,0,0,20,20920,10,0,0,0,0,0,'Snufflenose Gopher - Script - Respawn Blueleaf Tuber'),
(478100,9,3,0,0,0,100,0,5000,5000,0,0,29,1,0,0,0,0,0,23,0,0,0,0,0,0,0,'Snufflenose Gopher - Script - Follow Summoner'),
(478100,9,4,0,0,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snufflenose Gopher - Script - Set Hostile'),

(20920,1,0,0,11,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blueleaf Tuber - On Spawn - Set Phase 1'),
(20920,1,1,2,38,1,100,0,1,1,0,0,45,1,1,0,0,0,0,19,4781,0,0,0,0,0,0,'Blueleaf Tuber - On Data Set (Phase 1) - Set Data Snufflenose Gopher'),
(20920,1,2,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blueleaf Tuber - On Data Set (Phase 1) - Set Phase 2'),
(20920,1,3,0,1,0,100,0,300000,300000,300000,300000,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Blueleaf Tuber - OOC (Phase 2) - Set Phase 1');

DELETE FROM `creature_text` WHERE `entry`=4781;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(4781, 0, 0, '%s nervously crawls from the crate.', 16, 0, 100, 0, 0, 0, 1638, 0, 'Snufflenose Gopher'),
(4781, 1, 0, '%s wiggles his whiskers at $n.', 16, 0, 100, 0, 0, 0, 1591, 0, 'Snufflenose Gopher'),
(4781, 2, 0, '%s sniffs at the ground...', 16, 0, 100, 0, 0, 0, 1592, 0, 'Snufflenose Gopher');

DELETE FROM `gameobject` WHERE `id`=20919;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES 
(@Guid+0, 20919, 47, 0, 0, 1, 1, 2082.74, 1671.82, 61.2396, 3.66079, 0, 0, 0.966493, -0.256693, -43200, 100, 1, 0),
(@Guid+1, 20919, 47, 0, 0, 1, 1, 2159.43, 1687.49, 57.5433, 3.66079, 0, 0, 0.966493, -0.256693, -43200, 100, 1, 0),
(@Guid+2, 20919, 47, 0, 0, 1, 1, 2080.89, 1703.36, 56.6447, 0.553757, 0, 0, 0.273354, 0.961913, -43200, 100, 1, 0),
(@Guid+3, 20919, 47, 0, 0, 1, 1, 2055.28, 1767.7, 58.4559, 2.98378, 0, 0, 0.996889, 0.0788245, -43200, 100, 1, 0),
(@Guid+4, 20919, 47, 0, 0, 1, 1, 2196.64, 1827.96, 61.4706, 2.11277, 0, 0, 0.870583, 0.492022, -43200, 100, 1, 0),
(@Guid+5, 20919, 47, 0, 0, 1, 1, 2030.32, 1867.61, 56.2866, 5.6777, 0, 0, 0.298139, -0.954522, -43200, 100, 1, 0),
(@Guid+6, 20919, 47, 0, 0, 1, 1, 2091.33, 1861.73, 51.0341, 1.25355, 0, 0, 0.586536, 0.809923, -43200, 100, 1, 0),
(@Guid+7, 20919, 47, 0, 0, 1, 1, 2200.15, 1897.64, 71.3191, 2.6492, 0, 0, 0.969846, 0.243717, -43200, 100, 1, 0),
(@Guid+8, 20919, 47, 0, 0, 1, 1, 2075.75, 1742.04, 76.7184, 1.33994, 0, 0, 0.620962, 0.78384, -43200, 100, 1, 0),
(@Guid+9, 20919, 47, 0, 0, 1, 1, 2126, 1661.15, 82.4824, 0.0220437, 0, 0, 0.0110216, 0.999939, -43200, 100, 1, 0),
(@Guid+10, 20919, 47, 0, 0, 1, 1, 2207.92, 1596.91, 80.7375, 3.60582, 0, 0, 0.973182, -0.230035, -43200, 100, 1, 0),
(@Guid+11, 20919, 47, 0, 0, 1, 1, 2156.98, 1542.26, 72.849, 2.43086, 0, 0, 0.937519, 0.347934, -43200, 100, 1, 0),
(@Guid+12, 20919, 47, 0, 0, 1, 1, 2179.95, 1514.06, 69.0709, 0.778385, 0, 0, 0.379441, 0.925216, -43200, 100, 1, 0),
(@Guid+13, 20919, 47, 0, 0, 1, 1, 2000.85, 1533.93, 80.3971, 4.919, 0, 0, 0.630419, -0.776255, -43200, 100, 1, 0),
(@Guid+14, 20919, 47, 0, 0, 1, 1, 1991.49, 1608.53, 81.1601, 1.1004, 0, 0, 0.522858, 0.85242, -43200, 100, 1, 0);

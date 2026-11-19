--
-- Set Proper fation for Defias Raider
UPDATE `creature_template` SET `faction`=17 WHERE `entry`=6180;

UPDATE `creature_template` SET `ainame`='SmartAI', `scriptname`='' WHERE `entry`=6182;

DELETE FROM `smart_scripts` WHERE `entryorguid`=6180 AND `id` IN (3,4) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6180,0,3,0,6,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,6182,100,0,0,0,0,0,'Defias Raider - On Death Set Data 1 1'),
(6180,0,4,0,11,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,6182,100,0,0,0,0,0,'Defias Raider - On Respawn - Attack Start');

DELETE FROM `smart_scripts` WHERE `entryorguid`=6182 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6182,0,0,1,19,0,100,0,1651,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Daphne Stilwell - On Accepted Quest ''The Tome of Valor'' - Say Line 0'),
(6182,0,1,2,61,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Daphne Stilwell - Link With Previous - Store Target List'),
(6182,0,2,3,61,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Daphne Stilwell - Link With Previous - Remove npcflag ''Quest Giver'''),
(6182,0,3,4,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Daphne Stilwell - Link With Previous - Set Event Phase to 1'),
(6182,0,4,0,61,0,100,0,0,0,0,0,53,1,6182,0,0,0,2,1,0,0,0,0,0,0,0,'Daphne Stilwell - Link With Previous - Start WP Movement'),
(6182,0,5,0,40,0,100,0,5,6182,0,0,80,618200,2,0,0,0,0,1,0,0,0,0,0,0,0,'Daphne Stilwell - On WP 5 Reached - Call TAL 618200'),
(6182,0,6,0,40,0,100,0,8,6182,0,0,80,618201,2,0,0,0,0,1,0,0,0,0,0,0,0,'Daphne Stilwell - On WP 8 Reached - Call TAL 618201'),
(6182,0,7,8,38,2,100,0,1,1,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Daphne Stilwell - On Data Set 1 1(phase 2) - Remove Root'),
(6182,0,8,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Daphne Stilwell - Link With Previous - Say Line 1'),
(6182,0,9,0,40,2,100,0,9,6182,0,0,80,618202,0,0,0,0,0,1,0,0,0,0,0,0,0,'Daphne Stilwell - On WP 9 Reached - Call TAL 618202'),
(6182,0,10,11,38,4,100,0,1,1,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Daphne Stilwell - On Data Set 1 1(phase 3) - Remove Root'),
(6182,0,11,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Daphne Stilwell - Link With Previous - Say Line 2'),
(6182,0,12,0,40,0,100,0,10,6182,0,0,80,618203,0,0,0,0,0,1,0,0,0,0,0,0,0,'Daphne Stilwell - On WP 10 Reached - Call TAL 618203'),
(6182,0,13,14,38,8,100,0,1,1,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Daphne Stilwell - On Data Set 1 1(phase 4) - Remove Root'),
(6182,0,14,0,61,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Daphne Stilwell - Link With Previous - Say Line 3'),
(6182,0,15,0,40,8,100,0,11,6182,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Daphne Stilwell - On WP 11 Reached - Disable Run'),
(6182,0,16,0,40,8,100,0,12,6182,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Daphne Stilwell - On WP 12 Reached - Say Line 4'),
(6182,0,17,18,40,8,100,0,14,6182,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Daphne Stilwell - On WP 14 Reached - Pause WP'),
(6182,0,18,19,61,8,100,0,0,0,0,0,40,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Daphne Stilwell - Link With Previous - Set Sheath to 0'),
(6182,0,19,0,61,8,100,0,0,0,0,0,5,432,0,0,0,0,0,1,0,0,0,0,0,0,0,'Daphne Stilwell - Link With Previous - Play Emote'),
(6182,0,20,21,40,8,100,0,18,6182,0,0,15,1651,0,0,0,0,0,12,1,0,0,0,0,0,0,'Daphne Stilwell - On WP 18 Reached - Area Explored Or Event Happens'),
(6182,0,21,0,61,8,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Daphne Stilwell - Link With Previous - Add npcflag ''Quest Giver'''),
(6182,0,22,0,0,0,100,0,0,0,0,0,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Daphne Stilwell - In Combat - Cast spell ''Shoot'''),
(6182,0,23,24,11,0,100,0,0,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Daphne Stilwell - On Respawn - Remove Root'),
(6182,0,24,0,61,0,100,0,0,0,0,0,40,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Daphne Stilwell - Link With Previous - Set Sheath to 0'),
(6182,0,25,26,40,0,100,0,19,6182,0,0,55,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Daphne Stilwell - On WP 19 Reached - Stop WP'),
(6182,0,26,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Daphne Stilwell - Link With Previous - Evade');

DELETE FROM `smart_scripts` WHERE `entryorguid`IN (618200,618201,618202,618203) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(618200,9,0,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Action 0 - Set Root'),
(618200,9,1,0,0,0,100,0,0,0,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Action 1 - Pause WP'),
(618200,9,2,0,0,0,100,0,500,500,0,0,5,432,0,0,0,0,0,1,0,0,0,0,0,0,0,'Action 2 - Play Emote'),
(618200,9,3,0,0,0,100,0,2000,2000,0,0,71,0,0,0,0,2511,0,1,0,0,0,0,0,0,0,'Action 3 - Equip Ranged Weapon'),
(618200,9,4,0,0,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Action 4 - Set Sheath to 2'),
(618200,9,5,0,0,0,100,0,1000,1000,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Action 5 - Remove Root'),
(618201,9,0,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Action 0 - Set Root'),
(618201,9,1,0,0,0,100,0,0,0,0,0,107,0,1,0,0,0,0,0,0,0,0,0,0,0,0,'Action 1 - Summon Group 0'),
(618201,9,2,0,0,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Action 2 - Set Event Phase to 2'),
(618202,9,0,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Action 0 - Set Root'),
(618202,9,1,0,0,0,100,0,0,0,0,0,107,1,1,0,0,0,0,0,0,0,0,0,0,0,0,'Action 1 - Summon Group 1'),
(618202,9,2,0,0,0,100,0,0,0,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Action 2 - Set Event Phase to 3'),
(618203,9,0,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Action 0 - Set Root'),
(618203,9,1,0,0,0,100,0,0,0,0,0,107,2,1,0,0,0,0,0,0,0,0,0,0,0,0,'Action 1 - Summon Group 2'),
(618203,9,2,0,0,0,100,0,0,0,0,0,22,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Action 2 - Set Event Phase 4');

DELETE FROM `script_waypoint` WHERE `entry`=6182;
DELETE FROM `waypoints` WHERE `entry`=6182;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(6182,1,-11480.7,1545.09,49.8986,''),
(6182,2,-11466.8,1530.15,50.2636,''),
(6182,3,-11465.2,1528.34,50.9544,'enter hut'),
(6182,4,-11463,1525.24,50.9377,''),
(6182,5,-11461,1526.61,50.9377,'pick up rifle'),
(6182,6,-11463,1525.24,50.9377,''),
(6182,7,-11465.2,1528.34,50.9544,''),
(6182,8,-11468.4,1535.08,50.4009,'hold, prepare for wave1'),
(6182,9,-11468.4,1535.08,50.4009,'hold, prepare for wave2'),
(6182,10,-11468.4,1535.08,50.4009,'hold, prepare for wave3'),
(6182,11,-11467.9,1532.46,50.3489,'we are done'),
(6182,12,-11466.1,1529.86,50.2094,''),
(6182,13,-11463,1525.24,50.9377,''),
(6182,14,-11461,1526.61,50.9377,'deliver rifle'),
(6182,15,-11463,1525.24,50.9377,''),
(6182,16,-11465.2,1528.34,50.9544,''),
(6182,17,-11470.3,1537.28,50.3785,''),
(6182,18,-11475.6,1548.68,50.1844,'complete quest'),
(6182,19,-11482.3,1557.41,48.6245,'');

DELETE FROM `creature_summon_groups` WHERE `summonerid`=6182;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(6182,0,0,6180,-11450.836,1569.755,54.267,4.230,4,30000),
(6182,0,0,6180,-11449.697,1569.124,54.421,4.206,4,30000),
(6182,0,0,6180,-11448.237,1568.307,54.620,4.206,4,30000),
(6182,0,1,6180,-11450.836,1569.755,54.267,4.230,4,30000),
(6182,0,1,6180,-11449.697,1569.124,54.421,4.206,4,30000),
(6182,0,1,6180,-11448.237,1568.307,54.620,4.206,4,30000),
(6182,0,1,6180,-11448.037,1570.213,54.961,4.283,4,30000),
(6182,0,2,6180,-11450.836,1569.755,54.267,4.230,4,30000),
(6182,0,2,6180,-11449.697,1569.124,54.421,4.206,4,30000),
(6182,0,2,6180,-11448.237,1568.307,54.620,4.206,4,30000),
(6182,0,2,6180,-11448.037,1570.213,54.961,4.283,4,30000),
(6182,0,2,6180,-11449.018,1570.738,54.828,4.220,4,30000);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=4 AND `SourceEntry`=6180;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,4,6180,0,0,29,0,6180,100,0,1,0,0,'','Execute SAI if only there is no Defias Raider in vicinity');

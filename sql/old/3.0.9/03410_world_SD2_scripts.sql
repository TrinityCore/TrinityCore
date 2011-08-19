UPDATE `creature_template` SET `ScriptName` = 'npc_daphne_stilwell' WHERE `entry` = 6182;

DELETE FROM `script_waypoint` WHERE `entry` = 6182;
INSERT INTO `script_waypoint` VALUES
(6182, 0, -11480.684570, 1545.091187, 49.898571, 0, ''),
(6182, 1, -11466.825195, 1530.151733, 50.263611, 0, ''),
(6182, 2, -11465.213867, 1528.343750, 50.954369, 0, 'entrance hut'),
(6182, 3, -11462.990234, 1525.235596, 50.937702, 0, ''),
(6182, 4, -11461.000000, 1526.614014, 50.937702, 5000, 'pick up rifle'),
(6182, 5, -11462.990234, 1525.235596, 50.937702, 0, ''),
(6182, 6, -11465.213867, 1528.343750, 50.954369, 0, ''),
(6182, 7, -11468.353516, 1535.075562, 50.400948, 15000, 'hold, prepare for wave1'),
(6182, 8, -11468.353516, 1535.075562, 50.400948, 15000, 'hold, prepare for wave2'),
(6182, 9, -11468.353516, 1535.075562, 50.400948, 10000, 'hold, prepare for wave3'),
(6182, 10, -11467.898438, 1532.459595, 50.348885, 0, 'we are done'),
(6182, 11, -11466.064453, 1529.855225, 50.209351, 0, ''),
(6182, 12, -11462.990234, 1525.235596, 50.937702, 0, ''),
(6182, 13, -11461.000000, 1526.614014, 50.937702, 5000, 'deliver rifle'),
(6182, 14, -11462.990234, 1525.235596, 50.937702, 0, ''),
(6182, 15, -11465.213867, 1528.343750, 50.954369, 0, ''),
(6182, 16, -11470.260742, 1537.276733, 50.378487, 0, ''),
(6182, 17, -11475.581055, 1548.678833, 50.184380, 0, 'complete quest'),
(6182, 18, -11482.299805, 1557.410034, 48.624519, 0, '');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000406 AND -1000402;
INSERT INTO `script_texts` (`entry`, `content_default`, `sound`, `type`, `language`, `emote`, `comment`) VALUES
(-1000402, 'To the house! Stay close to me, no matter what! I have my gun and ammo there!', 0, 0, 7, 0, 'stilwell SAY_DS_START'),
(-1000403, 'We showed that one!', 0, 0, 7, 0, 'stilwell SAY_DS_DOWN_1'),
(-1000404, 'One more down!', 0, 0, 7, 0, 'stilwell SAY_DS_DOWN_2'),
(-1000405, 'We\'ve done it! We won!', 0, 0, 7, 0, 'stilwell SAY_DS_DOWN_3'),
(-1000406, 'Meet me down by the orchard--I just need to put my gun away.', 0, 0, 7, 0, 'stilwell SAY_DS_PROLOGUE');

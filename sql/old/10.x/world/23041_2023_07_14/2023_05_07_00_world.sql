-- New Race & Class combination
DELETE FROM `playercreateinfo` WHERE (`class`=10 AND `race` IN (9,22));
INSERT INTO `playercreateinfo` (`race`, `class`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
(9, 10, 648, -8423.8095703125, 1361.300048828125, 104.6709976196289062, 1.55428), -- Goblin
(22, 10, 654, -1451.530029296875, 1403.3499755859375, 35.55609893798828125, 0.333847); -- Worgen

DELETE FROM `playercreateinfo_action` WHERE (`race`=9 AND `class`=10 AND `button`=0) OR (`race`=22 AND `class`=10 AND `button`=0);
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(9, 10, 0, 100780, 0), -- Tiger Palm
(22, 10, 0, 100780, 0); -- Tiger Palm

-- NPE spawns
UPDATE `playercreateinfo` SET `npe_map` = 2175, `npe_position_x` = 11.1301, `npe_position_y` = -0.417182, `npe_position_z` = 5.18741, `npe_orientation` = 3.14843, `npe_transport_guid` = 29, `npe_intro_scene_id` = 2236 WHERE `race` = 22 AND `class` = 10;
UPDATE `playercreateinfo` SET `npe_map` = 2175, `npe_position_x` = -10.7291, `npe_position_y` = -7.14635, `npe_position_z` = 8.73113, `npe_orientation` = 1.56321, `npe_transport_guid` = 30, `npe_intro_scene_id` = 2486 WHERE `race` = 9 AND `class` = 10;

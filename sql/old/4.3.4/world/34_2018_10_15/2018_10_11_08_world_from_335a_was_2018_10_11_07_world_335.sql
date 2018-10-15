/*
-- 
DELETE FROM `creature` WHERE `guid` IN (87898,87899,87900);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`,`spawndist`, `MovementType`) VALUES
(87898, 3865, 33, 1, 1, 0, 0, -234.131, 2236.26, 79.8619, 0.296706, 7200, 0, 0),
(87899, 3865, 33, 1, 1, 0, 0, -223.612, 2245.72, 79.8583, 5.13127, 7200, 0, 0),
(87900, 3865, 33, 1, 1, 0, 0, -217.135, 2247.13, 79.8579, 4.88692, 7200, 0, 0);

DELETE FROM `pool_template` WHERE entry IN (493,494,495);
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(493, 1, 'Fel Steed/Shadow Charger 1'),
(494, 1, 'Fel Steed/Shadow Charger 2'),
(495, 1, 'Fel Steed/Shadow Charger 3');

DELETE FROM `pool_creature` WHERE `pool_entry` IN (493,494,495);
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(16440, 493, 0, 'Fel Steed/Shadow Charger 1'),
(87898, 493, 0, 'Fel Steed/Shadow Charger 1'),
(16441, 494, 0, 'Fel Steed/Shadow Charger 2'),
(87899, 494, 0, 'Fel Steed/Shadow Charger 2'),
(16442, 495, 0, 'Fel Steed/Shadow Charger 3'),
(87900, 495, 0, 'Fel Steed/Shadow Charger 3');
*/

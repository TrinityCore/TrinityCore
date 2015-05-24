--
DELETE FROM `pool_template` WHERE `entry` IN (11635, 11636, 11637, 11638);
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(11635, 1, 'Defenders at Bloodmyst Isle 1'),
(11636, 1, 'Defenders at Bloodmyst Isle 2'),
(11637, 1, 'Defenders at Bloodmyst Isle 3'),
(11638, 1, 'Defenders at Bloodmyst Isle 4');

DELETE FROM `pool_creature` WHERE `pool_entry` IN (11635, 11636, 11637, 11638);
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(63725, 11635, 0, 'Defenders at Bloodmyst Isle 1'),
(84397, 11635, 0, 'Defenders at Bloodmyst Isle 1'),
(63726, 11636, 0, 'Defenders at Bloodmyst Isle 2'),
(84395, 11636, 0, 'Defenders at Bloodmyst Isle 2'),
(63724, 11637, 0, 'Defenders at Bloodmyst Isle 3'),
(84396, 11637, 0, 'Defenders at Bloodmyst Isle 3'),
(63727, 11638, 0, 'Defenders at Bloodmyst Isle 4'),
(84428, 11638, 0, 'Defenders at Bloodmyst Isle 4');

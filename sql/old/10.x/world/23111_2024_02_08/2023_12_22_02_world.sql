DELETE FROM `instance_template` WHERE `map` IN (940, 939, 938);
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(940, 1, 'instance_hour_of_twilight'),
(939, 1, 'instance_well_of_eternity'),
(938, 1, 'instance_end_time');

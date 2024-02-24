DELETE FROM `instance_template` WHERE `map` IN (669, 671, 754);
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(669, 0, 'instance_blackwing_descent'),
(671, 0, 'instance_bastion_of_twilight'),
(754, 1, 'instance_throne_of_the_four_winds');

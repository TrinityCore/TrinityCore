-- ICC Quest pools (also deletes old pool data)
SET @pool := 5662;
DELETE FROM `pool_quest` WHERE `pool_entry` BETWEEN @pool+18 AND @pool+22;
INSERT INTO `pool_quest` (`entry`,`pool_entry`,`description`) VALUES
(24874,@pool+17, 'Blood Quickening (10)'),
(24869,@pool+17, 'Deprogramming (10)'),
(24873,@pool+17, 'Residue Rendezvous (10)'),
(24872,@pool+17, 'Respite for a Tormented Soul (10)'),
(24870,@pool+19, 'Securing the Ramparts HORDE (10)'),
(24871,@pool+19, 'Securing the Ramparts ALLY (10)'),
(24879,@pool+18, 'Blood Quickening (25)'),
(24875,@pool+18, 'Deprogramming (25)'),
(24878,@pool+18, 'Residue Rendezvous (25)'),
(24880,@pool+18, 'Respite for a Tormented Soul (25)'),
(24876,@pool+20, 'Securing the Ramparts ALLY (25)'),
(24877,@pool+20, 'Securing the Ramparts HORDE (25)');

DELETE FROM `pool_template` WHERE `entry` BETWEEN @pool+18 AND @pool+22;
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(@pool+17,1, 'ICC weeklies (10)'),
(@pool+18,1, 'ICC weeklies (25)'),
(@pool+19,2, 'Securing the Ramparts (10)'),
(@pool+20,2, 'Securing the Ramparts (25)');

DELETE FROM `pool_pool` WHERE `mother_pool` IN (@pool+17,@pool+18);
INSERT INTO `pool_pool` (`pool_id`,`mother_pool`,`chance`,`description`) VALUES
(@pool+19,@pool+17,0, 'Securing the Ramparts (10)'),
(@pool+20,@pool+18,0, 'Securing the Ramparts (25)');

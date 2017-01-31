-- ICC Quest pools
SET @pool := 5679;
DELETE FROM `pool_quest` WHERE `pool_entry` BETWEEN @pool AND @pool+11;
DELETE FROM `pool_template` WHERE `entry` BETWEEN @pool AND @pool+11;
DELETE FROM `pool_pool` WHERE `mother_pool` IN (@pool,@pool+1);

INSERT INTO `pool_quest` (`entry`,`pool_entry`,`description`) VALUES
(24874,@pool+02, 'Blood Quickening (10)'),
(24869,@pool+03, 'Deprogramming (10)'),
(24873,@pool+04, 'Residue Rendezvous (10)'),
(24872,@pool+05, 'Respite for a Tormented Soul (10)'),
(24870,@pool+06, 'Securing the Ramparts HORDE (10)'),
(24871,@pool+06, 'Securing the Ramparts ALLY (10)'),
(24879,@pool+07, 'Blood Quickening (25)'),
(24875,@pool+08, 'Deprogramming (25)'),
(24878,@pool+09, 'Residue Rendezvous (25)'),
(24880,@pool+10, 'Respite for a Tormented Soul (25)'),
(24876,@pool+11, 'Securing the Ramparts ALLY (25)'),
(24877,@pool+11, 'Securing the Ramparts HORDE (25)');

INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(@pool+00,1, 'General ICC 10man pool'),
(@pool+01,1, 'General ICC 25man pool'),
(@pool+02,1, 'Blood Quickening (10)'),
(@pool+03,1, 'Deprogramming (10)'),
(@pool+04,1, 'Residue Rendezvous (10)'),
(@pool+05,1, 'Respite for a Tormented Soul (10)'),
(@pool+06,2, 'Securing the Ramparts (10)'),
(@pool+07,1, 'Blood Quickening (25)'),
(@pool+08,1, 'Deprogramming (25)'),
(@pool+09,1, 'Residue Rendezvous (25)'),
(@pool+10,1, 'Respite for a Tormented Soul (25)'),
(@pool+11,2, 'Securing the Ramparts (25)');

INSERT INTO `pool_pool` (`pool_id`,`mother_pool`,`chance`,`description`) VALUES
(@pool+02,@pool+00,0, 'Blood Quickening (10)'),
(@pool+03,@pool+00,0, 'Deprogramming (10)'),
(@pool+04,@pool+00,0, 'Residue Rendezvous (10)'),
(@pool+05,@pool+00,0, 'Respite for a Tormented Soul (10)'),
(@pool+06,@pool+00,0, 'Securing the Ramparts (10)'),
(@pool+07,@pool+01,0, 'Blood Quickening (25)'),
(@pool+08,@pool+01,0, 'Deprogramming (25)'),
(@pool+09,@pool+01,0, 'Residue Rendezvous (25)'),
(@pool+10,@pool+01,0, 'Respite for a Tormented Soul (25)'),
(@pool+11,@pool+01,0, 'Securing the Ramparts (25)');

-- Battle Shout
DELETE FROM `spell_threat` WHERE `entry` IN (6673,5242,6192,11549,11550,11551,2048,47436);
INSERT INTO `spell_threat`(`entry`,`Threat`) VALUES
(6673,1), -- Rank 1
(5242,12), -- Rank 2
(6192,22), -- Rank 3
(11549,32), -- Rank 4
(11550,42), -- Rank 5
(11551,52), -- Rank 6 , Rank 7 already in tdb
(2048,69), -- Rank 8
(47436,78); -- Rank 9

-- Cleave
DELETE FROM `spell_threat` WHERE `entry` IN (47519,47520);
INSERT INTO `spell_threat`(`entry`,`Threat`) VALUES
(47519,175),  -- Rank 7
(47520,225);   -- Rank 8

-- Commanding Shout
DELETE FROM `spell_threat` WHERE `entry` IN (469,47439,47440);
INSERT INTO `spell_threat`(`entry`,`Threat`) VALUES
(469,68), -- Rank 1
(47439,77), -- Rank 2
(47440,80); -- Rank 3

-- Demoralizing Shout
DELETE FROM `spell_threat` WHERE `entry` IN (25202,25203,47437);
INSERT INTO `spell_threat`(`entry`,`Threat`) VALUES
(25202,49),   -- Rank 6
(25203,56),   -- Rank 7
(47437,63);   -- Rank 8

-- Devastate
DELETE FROM `spell_threat` WHERE `entry` IN (47497,47498);
INSERT INTO `spell_threat`(`entry`,`Threat`) VALUES
(47497,101),  -- Rank 4
(47498,101);   -- Rank 5

-- Heroic Strike
DELETE FROM `spell_threat` WHERE `entry` IN (47449,47450);
INSERT INTO `spell_threat`(`entry`,`Threat`) VALUES
(47449,233),  -- Rank 12
(47450,259);  -- Rank 13

-- Revenge
DELETE FROM `spell_threat` WHERE `entry` IN (57823);
INSERT INTO `spell_threat`(`entry`,`Threat`) VALUES
(57823,530);   -- Rank 9

-- Improved Revenge (Talented)
DELETE FROM `spell_threat` WHERE `entry` IN (12797,12799);
 INSERT INTO `spell_threat`(`entry`,`Threat`) VALUES
(12797,25),   -- Rank 1
(12799,25);    -- Rank 2

-- Shield Bash
DELETE FROM `spell_threat` WHERE `entry`=72;
INSERT INTO `spell_threat`(`entry`,`Threat`) VALUES
(72,36);

-- Shield Slam
DELETE FROM `spell_threat` WHERE `entry` IN (47487,47488);
INSERT INTO `spell_threat`(`entry`,`Threat`) VALUES
(47487,546),    -- Rank 7
(47488,770);     -- Rank 8

-- Sunder Armor (rank 7)
DELETE FROM `spell_threat` WHERE `entry`=47467;
INSERT INTO `spell_threat`(`entry`,`Threat`) VALUES
(47467,345);

-- Thunder Clap
DELETE FROM `spell_threat` WHERE `entry` IN (47501,47502);
INSERT INTO `spell_threat`(`entry`,`Threat`) VALUES
(47501,457), -- Rank 8
(47502,555);  -- Rank 9

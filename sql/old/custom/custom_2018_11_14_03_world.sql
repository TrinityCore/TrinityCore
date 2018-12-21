DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (45478, 45913, 45916, 45918, 45925, 45920, 45923, 45929, 45931, 45936, 45927);

-- Heroic Mode
-- The Vortex Pinnacle
INSERT INTO `creature_onkill_reward` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `IsTeamAward1`, `RewOnKillRepValue1`, `TeamDependent`) VALUES
(45478, 1162, 7, 0, 15, 0),
(45913, 1162, 7, 0, 15, 0),
(45916, 1162, 7, 0, 15, 0),
(45918, 1162, 7, 0, 15, 0),
(45925, 1162, 7, 0, 15, 0),
(45920, 1162, 7, 0, 15, 0),
(45923, 1162, 7, 0, 15, 0),
(45929, 1162, 7, 0, 15, 0),
(45931, 1162, 7, 0, 15, 0),
(45936, 1162, 7, 0, 15, 0),
(45927, 1162, 7, 0, 15, 0);

UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 250 WHERE `creature_id`= 43879;
UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 250 WHERE `creature_id`= 43874;
UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 250 WHERE `creature_id`= 43876;

-- Correct some wrong model id's for difficulty entries
UPDATE `creature_template` SET `modelid1`= 34771 WHERE `entry`= 45920;
UPDATE `creature_template` SET `modelid1`= 19673 WHERE `entry`= 45923;

-- Correct some inhabit types
UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry`= 47305;

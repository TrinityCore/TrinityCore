DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (45097, 49333, 44981, 49327, 44926, 49322, 44924, 49321, 44922, 49319, 44932, 49323, 45122, 49334, 44976, 49324, 44977, 49325, 44897, 49318, 44896, 49317, 44898, 49320, 45062, 49330, 44982, 44976, 49328, 44980, 49326);

-- Normal Mode (Elite)
-- The Lost City of the Tol'Vir
INSERT INTO `creature_onkill_reward` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `IsTeamAward1`, `RewOnKillRepValue1`, `TeamDependent`) VALUES
(45097, 1162, 7, 0, 10, 0),
(44981, 1162, 7, 0, 10, 0),
(44926, 1162, 7, 0, 10, 0),
(44924, 1162, 7, 0, 10, 0),
(44922, 1162, 7, 0, 10, 0),
(44932, 1162, 7, 0, 10, 0),
(45122, 1162, 7, 0, 10, 0),
(44976, 1162, 7, 0, 10, 0),
(44977, 1162, 7, 0, 10, 0),
(44897, 1162, 7, 0, 10, 0),
(44896, 1162, 7, 0, 10, 0),
(44898, 1162, 7, 0, 10, 0),
(45062, 1162, 7, 0, 10, 0),
(44982, 1162, 7, 0, 10, 0),
(44980, 1162, 7, 0, 10, 0);

UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 150 WHERE `creature_id`= 44577;
UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 150 WHERE `creature_id`= 43614;
UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 150 WHERE `creature_id`= 43612;
UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 150 WHERE `creature_id`= 44819;

-- Heroic Mode
-- The Lost City of the Tol'Vir
INSERT INTO `creature_onkill_reward` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `IsTeamAward1`, `RewOnKillRepValue1`, `TeamDependent`) VALUES
(49333, 1162, 7, 0, 15, 0),
(49327, 1162, 7, 0, 15, 0),
(49322, 1162, 7, 0, 15, 0),
(49321, 1162, 7, 0, 15, 0),
(49319, 1162, 7, 0, 15, 0),
(49323, 1162, 7, 0, 15, 0),
(49334, 1162, 7, 0, 15, 0),
(49324, 1162, 7, 0, 15, 0),
(49325, 1162, 7, 0, 15, 0),
(49318, 1162, 7, 0, 15, 0),
(49317, 1162, 7, 0, 15, 0),
(49320, 1162, 7, 0, 15, 0),
(49330, 1162, 7, 0, 15, 0),
(49328, 1162, 7, 0, 15, 0),
(49326, 1162, 7, 0, 15, 0);

UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 250 WHERE `creature_id`= 48932;
UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 250 WHERE `creature_id`= 49045;
UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 250 WHERE `creature_id`= 48951;
UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 250 WHERE `creature_id`= 51088;

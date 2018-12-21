DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (39709, 39981, 39979, 39986, 39983, 39988, 39991, 39994, 40018, 40020, 40022, 40024, 39666, 39680, 39699, 39701, 39705, 39995);

-- Heroic Mode
-- Blackrock Caverns
INSERT INTO `creature_onkill_reward` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `IsTeamAward1`, `RewOnKillRepValue1`, `TeamDependent`) VALUES
(39709, 1162, 7, 0, 15, 0),
(39981, 1162, 7, 0, 15, 0),
(39979, 1162, 7, 0, 15, 0),
(39986, 1162, 7, 0, 15, 0),
(39983, 1162, 7, 0, 15, 0),
(39988, 1162, 7, 0, 15, 0),
(39991, 1162, 7, 0, 15, 0),
(39994, 1162, 7, 0, 15, 0),
(40018, 1162, 7, 0, 15, 0),
(40020, 1162, 7, 0, 15, 0),
(40022, 1162, 7, 0, 15, 0),
(40024, 1162, 7, 0, 15, 0),
(39995, 1162, 7, 0, 15, 0),
(39666, 1162, 7, 0, 250, 0),
(39680, 1162, 7, 0, 250, 0),
(39699, 1162, 7, 0, 250, 0),
(39701, 1162, 7, 0, 250, 0),
(39705, 1162, 7, 0, 250, 0);

UPDATE `creature_onkill_reward` SET `CurrencyId1`= 395, `CurrencyCount1`= 7000 WHERE `creature_id` IN (39666, 39680, 39699, 39701, 39705);

-- Update difficulty entries
UPDATE `creature_template` SET `difficulty_entry_1`= 40024 WHERE `entry`= 40023;
UPDATE `creature_template` SET `minlevel`= 86, `maxlevel`= 86, `exp`= 3, `speed_walk`= 1.6, `speed_run`= 1.42857, `faction`= 16, `unit_flags`= 32832 WHERE `entry`= 40024;

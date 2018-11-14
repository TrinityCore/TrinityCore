DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (49085, 49090, 49087, 49086, 49091, 49092, 49102, 49078, 49077, 49074, 49080, 49064, 49082);

-- Heroic Mode
-- Throne of the Tides
INSERT INTO `creature_onkill_reward` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `IsTeamAward1`, `RewOnKillRepValue1`, `TeamDependent`) VALUES
(49085, 1162, 7, 0, 15, 0),
(49090, 1162, 7, 0, 15, 0),
(49087, 1162, 7, 0, 15, 0),
(49086, 1162, 7, 0, 15, 0),
(49091, 1162, 7, 0, 15, 0),
(49092, 1162, 7, 0, 15, 0),
(49102, 1162, 7, 0, 15, 0),
(49078, 1162, 7, 0, 15, 0),
(49077, 1162, 7, 0, 15, 0),
(49074, 1162, 7, 0, 15, 0),
(49080, 1162, 7, 0, 250, 0),
(49064, 1162, 7, 0, 250, 0),
(49082, 1162, 7, 0, 250, 0);

UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 250 WHERE `creature_id`= 49097;
UPDATE `creature_onkill_reward` SET `CurrencyId1`= 395, `CurrencyCount1`= 7000 WHERE `creature_id`= 49080;
UPDATE `creature_onkill_reward` SET `CurrencyId1`= 395, `CurrencyCount1`= 7000 WHERE `creature_id`= 49064;
UPDATE `creature_onkill_reward` SET `CurrencyId1`= 395, `CurrencyCount1`= 7000 WHERE `creature_id`= 49082;

-- Add difficulty entry to missing updated creatues
UPDATE `creature_template` SET `difficulty_entry_1`= 49092 WHERE `entry`= 40634;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 16, `speed_run`= 1, `unit_class`= 2, `unit_flags`= 32832 WHERE `entry`= 49092;

UPDATE `creature_template` SET `difficulty_entry_1`= 49102 WHERE `entry`= 40925;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 16, `speed_run`= 1.28968, `unit_flags`= 64 WHERE `entry`= 49102;

UPDATE `creature_template` SET `difficulty_entry_1`= 49078 WHERE `entry`= 40935;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 14 WHERE `entry`= 49078;

UPDATE `creature_template` SET `difficulty_entry_1`= 49077 WHERE `entry`= 40943;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `exp`= 3, `faction`= 14, `unit_class`= 2 WHERE `entry`= 49077;

UPDATE `creature_template` SET `difficulty_entry_1`= 49074 WHERE `entry`= 40936;
UPDATE `creature_template` SET `minlevel`= 86, `maxlevel`= 86, `exp`= 3, `faction`= 14, `speed_run`= 0.912699 WHERE `entry`= 49074;

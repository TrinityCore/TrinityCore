-- Zorbo the Advisor Reputation
DELETE FROM `creature_onkill_reputation` WHERE `creature_id` = 18413;
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `RewOnKillRepFaction2`, `MaxStanding1`, `IsTeamAward1`, `RewOnKillRepValue1`, `MaxStanding2`, `IsTeamAward2`, `RewOnKillRepValue2`, `TeamDependent`) VALUES
(18413, 978, 941, 7, 0, 10, 7, 0, 10, 1);

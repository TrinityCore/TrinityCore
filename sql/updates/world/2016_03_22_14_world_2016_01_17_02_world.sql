--
DELETE FROM `creature_onkill_reputation` WHERE `creature_id`=20477;
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `RewOnKillRepFaction2`, `MaxStanding1`, `IsTeamAward1`, `RewOnKillRepValue1`, `MaxStanding2`, `IsTeamAward2`, `RewOnKillRepValue2`, `TeamDependent`) VALUES 
(20477, 942, 0, 5, 0, 7, 0, 0, 0, 0);

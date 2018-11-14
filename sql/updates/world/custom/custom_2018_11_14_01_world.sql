DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (48141, 49309, 48139, 49307, 48140, 49308, 48143, 49310, 39440, 49286, 40787, 49301, 40311, 49295, 40310, 49294, 39801, 48895, 39800, 48894, 39803, 48896, 39802, 39373, 49285, 40170, 49293, 40106, 49292, 40033, 49291, 40715, 49300, 40668, 49299, 41374, 49305, 41371, 49304, 41364, 48892, 49303, 39587, 39731, 39732, 48710, 48715, 48776, 39370, 48815, 39378);

-- Normal Mode
-- Halls of Origination
INSERT INTO `creature_onkill_reward` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `IsTeamAward1`, `RewOnKillRepValue1`, `TeamDependent`) VALUES
(48141, 1162, 7, 0, 10, 0),
(48139, 1162, 7, 0, 10, 0),
(48140, 1162, 7, 0, 10, 0),
(48143, 1162, 7, 0, 10, 0),
(39440, 1162, 7, 0, 10, 0),
(40787, 1162, 7, 0, 10, 0),
(40311, 1162, 7, 0, 10, 0),
(40310, 1162, 7, 0, 10, 0),
(39801, 1162, 7, 0, 30, 0),
(39800, 1162, 7, 0, 30, 0),
(39803, 1162, 7, 0, 30, 0),
(39802, 1162, 7, 0, 30, 0),
(39373, 1162, 7, 0, 10, 0),
(40170, 1162, 7, 0, 10, 0),
(40106, 1162, 7, 0, 10, 0),
(40033, 1162, 7, 0, 10, 0),
(40715, 1162, 7, 0, 10, 0),
(40668, 1162, 7, 0, 10, 0),
(41374, 1162, 7, 0, 10, 0),
(41371, 1162, 7, 0, 10, 0),
(39370, 1162, 7, 0, 10, 0),
(39587, 1162, 7, 0, 150, 0),
(39731, 1162, 7, 0, 150, 0),
(39732, 1162, 7, 0, 150, 0),
(39378, 1162, 7, 0, 150, 0);

UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 150 WHERE `creature_id`= 39425;
UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 150 WHERE `creature_id`= 39428;
UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 150 WHERE `creature_id`= 39788;

-- Heroic Mode
-- Halls of Origination
INSERT INTO `creature_onkill_reward` (`creature_id`, `RewOnKillRepFaction1`, `MaxStanding1`, `IsTeamAward1`, `RewOnKillRepValue1`, `TeamDependent`) VALUES
(49309, 1162, 7, 0, 15, 0),
(49307, 1162, 7, 0, 15, 0),
(49308, 1162, 7, 0, 15, 0),
(49310, 1162, 7, 0, 15, 0),
(49286, 1162, 7, 0, 15, 0),
(49301, 1162, 7, 0, 15, 0),
(49295, 1162, 7, 0, 15, 0),
(49294, 1162, 7, 0, 15, 0),
(48895, 1162, 7, 0, 45, 0),
(48894, 1162, 7, 0, 45, 0),
(48896, 1162, 7, 0, 45, 0),
(48892, 1162, 7, 0, 45, 0),
(49285, 1162, 7, 0, 15, 0),
(49293, 1162, 7, 0, 15, 0),
(49292, 1162, 7, 0, 15, 0),
(49291, 1162, 7, 0, 15, 0),
(49300, 1162, 7, 0, 15, 0),
(49299, 1162, 7, 0, 15, 0),
(49305, 1162, 7, 0, 15, 0),
(49304, 1162, 7, 0, 15, 0),
(49303, 1162, 7, 0, 15, 0),
(48710, 1162, 7, 0, 250, 0),
(48715, 1162, 7, 0, 250, 0),
(48776, 1162, 7, 0, 250, 0),
(48815, 1162, 7, 0, 250, 0);

UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 250 WHERE `creature_id`= 49262;
UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 250 WHERE `creature_id`= 48714;
UPDATE `creature_onkill_reward` SET `RewOnKillRepFaction1`= 1162, `MaxStanding1`= 7, `RewOnKillRepValue1`= 250 WHERE `creature_id`= 48902;

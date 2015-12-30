-- Cenarion Circle Reputation
DELETE FROM `creature_onkill_reputation` WHERE `creature_id` IN (15335, 15727);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `RewOnKillRepFaction2`, `MaxStanding1`, `IsTeamAward1`, `RewOnKillRepValue1`, `MaxStanding2`, `IsTeamAward2`, `RewOnKillRepValue2`, `TeamDependent`) VALUES 
(15335, 609, 0, 7, 0, 6, 0, 0, 0, 0),
(15727, 609, 0, 7, 0, 1100, 0, 0, 0, 0);

DELETE FROM `creature_onkill_reputation` WHERE `creature_id` IN (15355, 15538, 15537, 15389, 15391, 15392, 15385, 15338, 15335, 15390, 15319, 15318, 15323, 15320, 15327, 15325, 15386, 15388, 15317, 15316, 15324, 15336);
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `RewOnKillRepFaction2`, `MaxStanding1`, `IsTeamAward1`, `RewOnKillRepValue1`, `MaxStanding2`, `IsTeamAward2`, `RewOnKillRepValue2`, `TeamDependent`) VALUES 
(15335, 609, 0, 7, 0, 10, 0, 0, 0, 0),
(15317, 609, 0, 7, 0, 10, 0, 0, 0, 0),
(15316, 609, 0, 7, 0, 10, 0, 0, 0, 0),
(15324, 609, 0, 7, 0, 10, 0, 0, 0, 0),
(15338, 609, 0, 7, 0, 10, 0, 0, 0, 0),
(15386, 609, 0, 7, 0, 10, 0, 0, 0, 0),
(15325, 609, 0, 7, 0, 10, 0, 0, 0, 0),
(15336, 609, 0, 7, 0, 10, 0, 0, 0, 0),
(15327, 609, 0, 7, 0, 10, 0, 0, 0, 0),
(15320, 609, 0, 7, 0, 10, 0, 0, 0, 0),
(15323, 609, 0, 7, 0, 10, 0, 0, 0, 0),
(15318, 609, 0, 7, 0, 10, 0, 0, 0, 0),
(15319, 609, 0, 7, 0, 10, 0, 0, 0, 0),
(15385, 609, 0, 7, 0, 10, 0, 0, 0, 0),
(15390, 609, 0, 7, 0, 10, 0, 0, 0, 0),
(15392, 609, 0, 7, 0, 10, 0, 0, 0, 0),
(15391, 609, 0, 7, 0, 10, 0, 0, 0, 0),
(15389, 609, 0, 7, 0, 10, 0, 0, 0, 0),
(15537, 609, 0, 7, 0, 10, 0, 0, 0, 0),
(15538, 609, 0, 7, 0, 10, 0, 0, 0, 0),
(15355, 609, 0, 7, 0, 10, 0, 0, 0, 0);

UPDATE `creature_onkill_reputation` SET `RewOnKillRepValue1`=11 WHERE  `creature_id` IN (15333, 15461, 15387, 15343);
UPDATE `creature_onkill_reputation` SET `RewOnKillRepFaction2`=609, `MaxStanding2`=7, `RewOnKillRepValue2`=73 WHERE  `creature_id` IN (15276, 15275);

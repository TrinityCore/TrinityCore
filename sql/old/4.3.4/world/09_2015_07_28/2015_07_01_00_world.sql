--
UPDATE `creature_template` SET `trainer_type`=2 WHERE `entry` IN (33996);
DELETE FROM `npc_trainer` WHERE `ID`=33996;
INSERT INTO `npc_trainer` (`ID`, `SpellID`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqLevel`) VALUES
(33996, 2373, 500, 182, 50, 0),
(33996, 3571, 5000, 182, 125, 10),
(33996, 11994, 50000, 182, 200, 25),
(33996, 2372, 10, 0, 0, 0);

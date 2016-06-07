--
DELETE FROM `npc_trainer` WHERE `SpellID` IN (14809, 14810, 17181);
INSERT INTO `npc_trainer` (`ID`, `SpellID`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqLevel`) VALUES
(201126, 14809, 2600, 333, 155, 0),
(201126, 14810, 3000, 333, 175, 0),
(201126, 17181, 10000, 333, 250, 0);

UPDATE `npc_trainer` SET `ID`=201009 WHERE `ID`=201124;
UPDATE `npc_trainer` SET `ID`=201011 WHERE `ID`=201126;
UPDATE `npc_trainer` SET `SpellID`=-201011 WHERE `SpellID`=-201126;

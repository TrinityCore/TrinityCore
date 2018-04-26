DELETE FROM `npc_trainer` WHERE `SpellID` IN (93321, 93375, 79682, 80388);
INSERT INTO `npc_trainer` (`ID`, `SpellID`, `MoneyCost`, `ReqLevel`) VALUES
(200003, 93321, 110, 10),
(200009, 93375, 680, 10);

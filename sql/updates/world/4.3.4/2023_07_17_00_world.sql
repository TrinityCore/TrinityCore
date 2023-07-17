DROP TABLE IF EXISTS `playercondition_dbc`;
CREATE TABLE `playercondition_dbc` (  
  `ID` INT UNSIGNED NOT NULL,
  `FailureDescription` VARCHAR(100) NOT NULL,
  PRIMARY KEY (`ID`) 
);

INSERT INTO `playercondition_dbc` (`ID`, `FailureDescription`) VALUES
(12251, 'Serverside/Non-DB2: Requires Stormwind - Revered'),
(12252, 'Serverside/Non-DB2: Requires Stormwind - Exalted');

UPDATE `npc_vendor` SET `PlayerConditionID`= 12252 WHERE `item` IN (64901, 64902, 64903);
UPDATE `npc_vendor` SET `PlayerConditionID`= 12251 WHERE `item`= 67531;

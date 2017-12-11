DELETE FROM `npc_vendor` WHERE `entry` = '69333';
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`, `type`, `PlayerConditionID`) VALUES
('69333', '19', '83080', '0', '0', '0', '1', '0'),
('69333', '18', '92070', '0', '0', '0', '1', '0');

UPDATE creature SET id = 1000000 WHERE id = 100000 AND guid != 20546780;

DELETE FROM gameobject WHERE guid IN (160905, 160907, 160926, 160924);

DELETE FROM conditions WHERE SourceTypeOrReferenceId = 13 AND SourceGroup = 1 AND SourceEntry = 89821;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES ('13', '1', '89821', '31', '3', '48269', 'Hercular - Dark Ranger'); 

DELETE FROM conditions WHERE SourceTypeOrReferenceId = 17 AND SourceEntry = 192348;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTarget`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES ('17', '0', '192348', 0, '27', '100', '3', 'Teleport to Dalaran Legion - Lvl 100 minimum'); 

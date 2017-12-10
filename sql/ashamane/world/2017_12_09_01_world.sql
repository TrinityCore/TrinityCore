DELETE FROM `npc_vendor` WHERE `entry` = '69333';
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`, `type`, `PlayerConditionID`) VALUES
('69333', '19', '83080', '0', '0', '0', '1', '0'),
('69333', '18', '92070', '0', '0', '0', '1', '0');

UPDATE creature SET id = 1000000 WHERE id = 100000 AND guid != 20546780;

DELETE FROM gameobject WHERE guid IN (160905, 160907, 160926, 160924);

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES ('13', '1', '89821', '31', '3', '48269', 'Hercular - Dark Ranger'); 

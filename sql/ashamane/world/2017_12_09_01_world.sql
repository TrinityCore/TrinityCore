DELETE FROM `npc_vendor` WHERE `entry` = '69333';
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`, `type`, `PlayerConditionID`) VALUES
('69333', '19', '83080', '0', '0', '0', '1', '0'),
('69333', '18', '92070', '0', '0', '0', '1', '0');

UPDATE creature SET id = 1000000 WHERE id = 100000 AND guid != 20546780;

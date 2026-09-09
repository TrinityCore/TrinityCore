-- 
DELETE FROM `graveyard_zone` WHERE `ID`=469 AND `GhostZone` IN (141,1657);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=27 AND `SourceEntry`=469 AND `SourceGroup` IN (141,1657);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=27 AND `SourceEntry`=91 AND `SourceGroup`=141;

DELETE FROM `graveyard_zone` WHERE `ID`=91 AND `GhostZone`=1657;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(91, 1657, 'Teldrassil, Dolanaar GY - Teldrassil');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=27 AND `SourceEntry`=91 AND `SourceGroup`=1657;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(27, 1657, 91, 0, 0, 6, 0, 67, 0, 0, '', 0, 0, 0, '', 'Graveyard - 91 - 1657 - Teldrassil, Dolanaar GY - Darnassus - Team Horde');

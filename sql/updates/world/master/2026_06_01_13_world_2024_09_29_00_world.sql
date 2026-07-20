-- Deletes Ratchet as Ally GY when dying in Thunder Bluff
DELETE FROM `graveyard_zone` WHERE `ID`= 249 AND `GhostZone`= 1638;
-- Adds Bloodhoof Village as Ally GY when dying in Thunder Bluff
DELETE FROM `graveyard_zone` WHERE `ID`= 89 AND `GhostZone`= 1638;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(89, 1638, 'Mulgore, Bloodhoof Village GY - Mulgore');

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(27, 1638, 89, 0, 0, 6, 0, 469, 0, 0, '', 0, 0, 0, '', 'Graveyard - 89 - 1638 - Mulgore, Bloodhoof Village GY - Mulgore - Team Alliance');

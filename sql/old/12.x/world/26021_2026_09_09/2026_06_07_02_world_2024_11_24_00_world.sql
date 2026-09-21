-- Add Gates of Ironforge graveyard for Ally when dying in Ironforge
DELETE FROM `graveyard_zone` WHERE `ID`=852 AND `GhostZone`=1537;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(852, 1537, 'Dun Morogh, Gates of Ironforge - Ironforge');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=27 AND `SourceGroup`=1537 AND `SourceEntry`=852;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `Comment`) VALUES
(27, 1537, 852, 6, 469, 'Graveyard - 189 - 1537 - Dun Morogh, Gates of Ironforge - Ironforge - Team Alliance');

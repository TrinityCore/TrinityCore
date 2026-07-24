-- Add Gates of Ironforge graveyard for Ally when dying in Ironforge
DELETE FROM `graveyard_zone` WHERE `ID`=852 AND `GhostZone`=1537;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Faction`, `Comment`) VALUES
(852, 1537, 469, 'Dun Morogh, Gates of Ironforge - Ironforge');

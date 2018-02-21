DELETE FROM `tact_key` WHERE `ID` IN (93, 94);

DELETE FROM `tact_key` WHERE `ID`=73; 
INSERT INTO `tact_key` (`ID`, `Key1`, `Key2`, `Key3`, `Key4`, `Key5`, `Key6`, `Key7`, `Key8`, `Key9`, `Key10`, `Key11`, `Key12`, `Key13`, `Key14`, `Key15`, `Key16`, `VerifiedBuild`) VALUES
(73, 123, 111, 163, 130, 225, 250, 209, 70, 92, 133, 30, 63, 71, 52, 161, 179, 24330);

UPDATE `tact_key` SET `VerifiedBuild`=24330 WHERE `ID` IN (67, 66, 58, 71, 75, 62, 60, 69, 74, 70, 61, 72, 59, 63, 64, 65);

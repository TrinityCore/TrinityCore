DELETE FROM `tact_key` WHERE `ID` IN (81, 93, 94);
INSERT INTO `tact_key` (`ID`, `Key1`, `Key2`, `Key3`, `Key4`, `Key5`, `Key6`, `Key7`, `Key8`, `Key9`, `Key10`, `Key11`, `Key12`, `Key13`, `Key14`, `Key15`, `Key16`, `VerifiedBuild`) VALUES
(93, 2, 153, 11, 18, 38, 12, 30, 159, 221, 115, 254, 71, 203, 171, 112, 36, 23911),
(94, 27, 120, 155, 135, 251, 60, 146, 56, 213, 40, 153, 123, 250, 180, 65, 134, 23911);

UPDATE `tact_key` SET `VerifiedBuild`=23911 WHERE `ID` IN (58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 69, 71, 72, 75, 70, 74);

DELETE FROM `class_expansion_requirement` WHERE `classID`= 12;
INSERT INTO `class_expansion_requirement` (`classID`, `expansion`) VALUES
(12, 6);

DELETE FROM `playercreateinfo` WHERE `class`= 12;
INSERT INTO `playercreateinfo` (`race`, `class`, `map`, `zone`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
(4, 12, 1481, 6383, 1180.64, 3284.96, 70.34837, 4.761345),
(10, 12, 1481, 6383, 1180.64, 3284.96, 70.34837, 4.761345);

DELETE FROM `playercreateinfo_action` WHERE `class`= 12;
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(4, 12, 0, 195072, 0),
(4, 12, 1, 162243, 0),
(4, 12, 2, 162794, 0),
(4, 12, 9, 58984, 0),
(4, 12, 10, 188501, 0),
(10, 12, 0, 195072, 0),
(10, 12, 1, 162243, 0),
(10, 12, 2, 162794, 0),
(10, 12, 9, 202719, 0),
(10, 12, 10, 188501, 0);

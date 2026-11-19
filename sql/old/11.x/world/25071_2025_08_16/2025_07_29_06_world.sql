-- Class Druid
DELETE FROM `playercreateinfo_action` WHERE (`race`=4 AND `class`=11 AND `button`=10) OR (`race`=6 AND `class`=11 AND `button`=10) OR (`race`=8 AND `class`=11 AND `button`=10) OR (`race`=22 AND `class`=11 AND `button`=10);
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(4, 11, 10, 1231411, 0), -- Recuperate
(6, 11, 10, 1231411, 0), -- Recuperate
(8, 11, 10, 1231411, 0), -- Recuperate
(22, 11, 10, 1231411, 0); -- Recuperate

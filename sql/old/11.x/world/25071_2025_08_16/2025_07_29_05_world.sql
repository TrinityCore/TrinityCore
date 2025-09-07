-- Class Paladin
DELETE FROM `playercreateinfo_action` WHERE (`race`=1 AND `class`=2 AND `button`=10) OR (`race`=3 AND `class`=2 AND `button`=10) OR (`race`=6 AND `class`=2 AND `button`=10) OR (`race`=10 AND `class`=2 AND `button`=10) OR (`race`=11 AND `class`=2 AND `button`=10);
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(1, 2, 10, 1231411, 0), -- Recuperate
(3, 2, 10, 1231411, 0), -- Recuperate
(6, 2, 10, 1231411, 0), -- Recuperate
(10, 2, 10, 1231411, 0), -- Recuperate
(11, 2, 10, 1231411, 0); -- Recuperate

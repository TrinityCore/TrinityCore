-- Class Warlock
DELETE FROM `playercreateinfo_action` WHERE (`race`=1 AND `class`=9 AND `button`=10) OR (`race`=2 AND `class`=9 AND `button`=10) OR (`race`=3 AND `class`=9 AND `button`=10) OR (`race`=4 AND `class`=9 AND `button`=10) OR (`race`=5 AND `class`=9 AND `button`=10) OR (`race`=6 AND `class`=9 AND `button`=10) OR (`race`=7 AND `class`=9 AND `button`=10) OR (`race`=8 AND `class`=9 AND `button`=10) OR (`race`=9 AND `class`=9 AND `button`=11) OR (`race`=10 AND `class`=9 AND `button`=10) OR (`race`=11 AND `class`=9 AND `button`=10) OR (`race`=22 AND `class`=9 AND `button`=10);
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(1, 9, 10, 1231411, 0), -- Recuperate
(2, 9, 10, 1231411, 0), -- Recuperate
(3, 9, 10, 1231411, 0), -- Recuperate
(4, 9, 10, 1231411, 0), -- Recuperate
(5, 9, 10, 1231411, 0), -- Recuperate
(6, 9, 10, 1231411, 0), -- Recuperate
(7, 9, 10, 1231411, 0), -- Recuperate
(8, 9, 10, 1231411, 0), -- Recuperate
(9, 9, 11, 1231411, 0), -- Recuperate
(10, 9, 10, 1231411, 0), -- Recuperate
(11, 9, 10, 1231411, 0), -- Recuperate
(22, 9, 10, 1231411, 0); -- Recuperate

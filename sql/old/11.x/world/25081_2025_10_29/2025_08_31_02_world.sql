-- Class Monk
DELETE FROM `playercreateinfo_action` WHERE (`race`=1 AND `class`=10 AND `button`=10) OR (`race`=2 AND `class`=10 AND `button`=10) OR (`race`=3 AND `class`=10 AND `button`=10) OR (`race`=4 AND `class`=10 AND `button`=10) OR (`race`=5 AND `class`=10 AND `button`=10) OR (`race`=6 AND `class`=10 AND `button`=10) OR (`race`=7 AND `class`=10 AND `button`=10) OR (`race`=8 AND `class`=10 AND `button`=10) OR (`race`=9 AND `class`=10 AND `button`=9) OR (`race`=10 AND `class`=10 AND `button`=10) OR (`race`=11 AND `class`=10 AND `button`=10) OR (`race`=22 AND `class`=10 AND `button`=9) OR (`race`=24 AND `class`=10 AND `button`=10);
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(1, 10, 10, 1231411, 0), -- Recuperate
(2, 10, 10, 1231411, 0), -- Recuperate
(3, 10, 10, 1231411, 0), -- Recuperate
(4, 10, 10, 1231411, 0), -- Recuperate
(5, 10, 10, 1231411, 0), -- Recuperate
(6, 10, 10, 1231411, 0), -- Recuperate
(7, 10, 10, 1231411, 0), -- Recuperate
(8, 10, 10, 1231411, 0), -- Recuperate
(9, 10, 9, 1231411, 0), -- Recuperate
(10, 10, 10, 1231411, 0), -- Recuperate
(11, 10, 10, 1231411, 0), -- Recuperate
(22, 10, 9, 1231411, 0), -- Recuperate
(24, 10, 10, 1231411, 0); -- Recuperate

-- Class Rogue
DELETE FROM `playercreateinfo_action` WHERE (`race`=1 AND `class`=4 AND `button`=10) OR (`race`=2 AND `class`=4 AND `button`=10) OR (`race`=3 AND `class`=4 AND `button`=10) OR (`race`=4 AND `class`=4 AND `button`=10) OR (`race`=5 AND `class`=4 AND `button`=10) OR (`race`=6 AND `class`=4 AND `button`=10) OR (`race`=7 AND `class`=4 AND `button`=10) OR (`race`=9 AND `class`=4 AND `button`=11) OR (`race`=11 AND `class`=4 AND `button`=10) OR (`race`=22 AND `class`=4 AND `button`=10) OR (`race`=24 AND `class`=4 AND `button`=10);
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(1, 4, 10, 1231411, 0), -- Recuperate
(2, 4, 10, 1231411, 0), -- Recuperate
(3, 4, 10, 1231411, 0), -- Recuperate
(4, 4, 10, 1231411, 0), -- Recuperate
(5, 4, 10, 1231411, 0), -- Recuperate
(6, 4, 10, 1231411, 0), -- Recuperate
(7, 4, 10, 1231411, 0), -- Recuperate
(9, 4, 11, 1231411, 0), -- Recuperate
(11, 4, 10, 1231411, 0), -- Recuperate
(22, 4, 10, 1231411, 0), -- Recuperate
(24, 4, 10, 1231411, 0); -- Recuperate

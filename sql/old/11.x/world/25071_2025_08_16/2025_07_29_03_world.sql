-- Class Shaman
DELETE FROM `playercreateinfo_action` WHERE (`race`=2 AND `class`=7 AND `button`=10) OR (`race`=3 AND `class`=7 AND `button`=10) OR (`race`=6 AND `class`=7 AND `button`=10) OR (`race`=8 AND `class`=7 AND `button`=10) OR (`race`=9 AND `class`=7 AND `button`=11) OR (`race`=11 AND `class`=7 AND `button`=10) OR (`race`=24 AND `class`=7 AND `button`=10) OR (`race`=28 AND `class`=7 AND `button`=7) OR (`race`=35 AND `class`=7 AND `button`=7) OR (`race`=36 AND `class`=7 AND `button`=7) OR (`race`=36 AND `class`=7 AND `button`=8);
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(2, 7, 10, 1231411, 0), -- Recuperate
(3, 7, 10, 1231411, 0), -- Recuperate
(6, 7, 10, 1231411, 0), -- Recuperate
(8, 7, 10, 1231411, 0), -- Recuperate
(9, 7, 11, 1231411, 0), -- Recuperate
(11, 7, 10, 1231411, 0), -- Recuperate
(24, 7, 10, 1231411, 0), -- Recuperate
(28, 7, 7, 2645, 0), -- Ghost Wolf
(35, 7, 7, 2645, 0), -- Ghost Wolf
(36, 7, 7, 2645, 0), -- Ghost Wolf
(36, 7, 8, 8004, 0); -- Healing Surge

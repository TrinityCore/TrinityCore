-- Add playercreateinfo data
DELETE FROM `playercreateinfo` WHERE (`race`=30 AND `class`=10);
INSERT INTO `playercreateinfo` (`race`, `class`, `map`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
(30, 10, 1860, 458.822998046875, 1449.6099853515625, 757.572998046875, 0.466425); -- Lightforged Draenei Monk

DELETE FROM `playercreateinfo_action` WHERE (`race`=30 AND `class`=10 AND `button`=8) OR (`race`=30 AND `class`=10 AND `button`=7) OR (`race`=30 AND `class`=10 AND `button`=6) OR (`race`=30 AND `class`=10 AND `button`=5) OR (`race`=30 AND `class`=10 AND `button`=4) OR (`race`=30 AND `class`=10 AND `button`=3) OR (`race`=30 AND `class`=10 AND `button`=2) OR (`race`=30 AND `class`=10 AND `button`=1) OR (`race`=30 AND `class`=10 AND `button`=0);
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(30, 10, 8, 119381, 0), -- Leg Sweep
(30, 10, 7, 116670, 0), -- Vivify
(30, 10, 6, 109132, 0), -- Roll
(30, 10, 5, 117952, 0), -- Crackling Jade Lightning
(30, 10, 4, 322109, 0), -- Touch of Death
(30, 10, 3, 101546, 0), -- Spinning Crane Kick
(30, 10, 2, 322101, 0), -- Expel Harm
(30, 10, 1, 100784, 0), -- Blackout Kick
(30, 10, 0, 100780, 0); -- Tiger Palm

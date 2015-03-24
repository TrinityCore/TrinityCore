DELETE FROM `playercreateinfo` WHERE (`race`=1 AND `class`=10) OR (`race`=2 AND `class`=10) OR (`race`=3 AND `class`=10) OR (`race`=4 AND `class`=10) OR (`race`=5 AND `class`=10) OR (`race`=6 AND `class`=10) OR (`race`=24 AND `class`=8) OR (`race`=24 AND `class`=10) OR (`race`=24 AND `class`=1) OR (`race`=7 AND `class`=10) OR (`race`=24 AND `class`=3) OR (`race`=24 AND `class`=4) OR (`race`=24 AND `class`=5) OR (`race`=24 AND `class`=7) OR (`race`=8 AND `class`=10) OR (`race`=10 AND `class`=10) OR (`race`=11 AND `class`=10);
INSERT INTO `playercreateinfo` (`race`, `class`, `map`, `position_x`, `position_y`, `position_z`) VALUES
(1, 10, 0, -8914.57, -133.909, 80.5378), -- Human - Monk
(2, 10, 1, -618.518, -4251.67, 38.718), -- Orc - Monk
(3, 10, 0, -6230.42, 330.232, 383.105), -- Dwarf - Monk
(4, 10, 1, 10311.3, 831.463, 1326.41), -- NightElf - Monk
(5, 10, 0, 1699.85, 1706.56, 135.928), -- Undead - Monk
(6, 10, 1, -2915.55, -257.347, 59.2693), -- Tauren - Monk
(24, 8, 860, 1466.09, 3465.98, 181.86), -- PandarenNeutral - Mage
(24, 10, 860, 1466.09, 3465.98, 181.86), -- PandarenNeutral - Monk
(24, 1, 860, 1466.09, 3465.98, 181.86), -- PandarenNeutral - Warrior
(7, 10, 0, -4983.42, 877.7, 274.31), -- Gnome - Monk
(24, 3, 860, 1466.09, 3465.98, 181.86), -- PandarenNeutral - Hunter
(24, 4, 860, 1466.09, 3465.98, 181.86), -- PandarenNeutral - Rogue
(24, 5, 860, 1466.09, 3465.98, 181.86), -- PandarenNeutral - Priest
(24, 7, 860, 1466.09, 3465.98, 181.86), -- PandarenNeutral - Shaman
(8, 10, 1, -1171.45, -5263.65, 0.847728), -- Troll - Monk
(10, 10, 530, 10349.6, -6357.29, 33.4026), -- BloodElf - Monk
(11, 10, 530, -3961.64, -13931.2, 100.615); -- Draenei - Monk

UPDATE `playercreateinfo` SET `position_x`=-6230.42, `position_y`=330.232, `position_z`=383.105 WHERE `race`=3 AND `class`=3; -- Dwarf - Hunter
UPDATE `playercreateinfo` SET `position_x`=-6230.42, `position_y`=330.232, `position_z`=383.105 WHERE `race`=3 AND `class`=2; -- Dwarf - Paladin
UPDATE `playercreateinfo` SET `position_x`=-6230.42, `position_y`=330.232, `position_z`=383.105 WHERE `race`=3 AND `class`=1; -- Dwarf - Warrior
UPDATE `playercreateinfo` SET `position_x`=-6230.42, `position_y`=330.232, `position_z`=383.105 WHERE `race`=3 AND `class`=7; -- Dwarf - Shaman
UPDATE `playercreateinfo` SET `position_x`=-6230.42, `position_y`=330.232, `position_z`=383.105 WHERE `race`=3 AND `class`=5; -- Dwarf - Priest
UPDATE `playercreateinfo` SET `position_x`=-6230.42, `position_y`=330.232, `position_z`=383.105 WHERE `race`=3 AND `class`=4; -- Dwarf - Rogue
UPDATE `playercreateinfo` SET `position_x`=-6230.42, `position_y`=330.232, `position_z`=383.105 WHERE `race`=3 AND `class`=9; -- Dwarf - Warlock
UPDATE `playercreateinfo` SET `position_x`=-6230.42, `position_y`=330.232, `position_z`=383.105 WHERE `race`=3 AND `class`=8; -- Dwarf - Mage
UPDATE `playercreateinfo` SET `position_y`=831.463, `position_z`=1326.57 WHERE `race`=4 AND `class`=4; -- NightElf - Rogue
UPDATE `playercreateinfo` SET `position_y`=831.463, `position_z`=1326.57 WHERE `race`=4 AND `class`=5; -- NightElf - Priest
UPDATE `playercreateinfo` SET `position_y`=831.463, `position_z`=1326.57 WHERE `race`=4 AND `class`=1; -- NightElf - Warrior
UPDATE `playercreateinfo` SET `position_y`=831.463, `position_z`=1326.57 WHERE `race`=4 AND `class`=3; -- NightElf - Hunter
UPDATE `playercreateinfo` SET `position_y`=831.463, `position_z`=1326.57 WHERE `race`=4 AND `class`=8; -- NightElf - Mage
UPDATE `playercreateinfo` SET `position_y`=831.463, `position_z`=1326.57 WHERE `race`=4 AND `class`=11; -- NightElf - Druid

-- By zone and orientation by Luhzinha 
UPDATE `playercreateinfo` SET `zone`=9,    `orientation`=5.13806 WHERE `race`=1  AND `class`=10; 
UPDATE `playercreateinfo` SET `zone`=14,   `orientation`=4.72222 WHERE `race`=2  AND `class`=10; 
UPDATE `playercreateinfo` SET `zone`=1,    `orientation`=6.17716 WHERE `race`=3  AND `class`=10; 
UPDATE `playercreateinfo` SET `zone`=141,  `orientation`=5.69632 WHERE `race`=4  AND `class`=10; 
UPDATE `playercreateinfo` SET `zone`=5692, `orientation`=4.88839 WHERE `race`=5  AND `class`=10; 
UPDATE `playercreateinfo` SET `zone`=221,  `orientation`=0.302378WHERE `race`=6  AND `class`=10; 
UPDATE `playercreateinfo` SET `zone`=5495, `orientation`=3.06393 WHERE `race`=7  AND `class`=10; 
UPDATE `playercreateinfo` SET `zone`=5691, `orientation`=5.78945 WHERE `race`=8  AND `class`=10; 
UPDATE `playercreateinfo` SET `zone`=3431, `orientation`=5.31605 WHERE `race`=10 AND `class`=10; 
UPDATE `playercreateinfo` SET `zone`=3526, `orientation`=2.08364 WHERE `race`=11 AND `class`=10; 
UPDATE `playercreateinfo` SET `zone`=5736, `orientation`=2.77359 WHERE `race`=24 AND `class`=1; 
UPDATE `playercreateinfo` SET `zone`=5736, `orientation`=2.77359 WHERE `race`=24 AND `class`=3; 
UPDATE `playercreateinfo` SET `zone`=5736, `orientation`=2.77359 WHERE `race`=24 AND `class`=4; 
UPDATE `playercreateinfo` SET `zone`=5736, `orientation`=2.77359 WHERE `race`=24 AND `class`=5; 
UPDATE `playercreateinfo` SET `zone`=5736, `orientation`=2.77359 WHERE `race`=24 AND `class`=7; 
UPDATE `playercreateinfo` SET `zone`=5736, `orientation`=2.77359 WHERE `race`=24 AND `class`=8; 
UPDATE `playercreateinfo` SET `zone`=5736, `orientation`=2.77359 WHERE `race`=24 AND `class`=10; 
UPDATE `playercreateinfo` SET `zone`=1519, `orientation`=0.67    WHERE `race`=25 AND `class`=1; 
UPDATE `playercreateinfo` SET `zone`=1519, `orientation`=0.67    WHERE `race`=25 AND `class`=3; 
UPDATE `playercreateinfo` SET `zone`=1519, `orientation`=0.67    WHERE `race`=25 AND `class`=4; 
UPDATE `playercreateinfo` SET `zone`=1519, `orientation`=0.67    WHERE `race`=25 AND `class`=5; 
UPDATE `playercreateinfo` SET `zone`=1519, `orientation`=0.67    WHERE `race`=25 AND `class`=7; 
UPDATE `playercreateinfo` SET `zone`=1519, `orientation`=0.67    WHERE `race`=25 AND `class`=8; 
UPDATE `playercreateinfo` SET `zone`=1519, `orientation`=0.67    WHERE `race`=25 AND `class`=10; 
UPDATE `playercreateinfo` SET `zone`=14,   `orientation`=0.13    WHERE `race`=26 AND `class`=1; 
UPDATE `playercreateinfo` SET `zone`=14,   `orientation`=0.13    WHERE `race`=26 AND `class`=3; 
UPDATE `playercreateinfo` SET `zone`=14,   `orientation`=0.13    WHERE `race`=26 AND `class`=4; 
UPDATE `playercreateinfo` SET `zone`=14,   `orientation`=0.13    WHERE `race`=26 AND `class`=5; 
UPDATE `playercreateinfo` SET `zone`=14,   `orientation`=0.13    WHERE `race`=26 AND `class`=7; 
UPDATE `playercreateinfo` SET `zone`=14,   `orientation`=0.13    WHERE `race`=26 AND `class`=8; 
UPDATE `playercreateinfo` SET `zone`=14,   `orientation`=0.13    WHERE `race`=26 AND `class`=10;

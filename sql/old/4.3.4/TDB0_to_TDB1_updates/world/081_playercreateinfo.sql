DELETE FROM `playercreateinfo` WHERE `race`=1 AND `class`=6;
DELETE FROM `playercreateinfo` WHERE `race`=2 AND `class`=8;
DELETE FROM `playercreateinfo` WHERE `race`=3 AND `class` IN (7,8,9);
DELETE FROM `playercreateinfo` WHERE `race`=4 AND `class`=8;
DELETE FROM `playercreateinfo` WHERE `race`=5 AND `class`=6;
DELETE FROM `playercreateinfo` WHERE `race`=6 AND `class`=6;
DELETE FROM `playercreateinfo` WHERE `race`=7 AND `class`=6;
DELETE FROM `playercreateinfo` WHERE `race`=8 AND `class`=6;
DELETE FROM `playercreateinfo` WHERE `race`=9 AND `class`=6;
DELETE FROM `playercreateinfo` WHERE `race`=10 AND `class`=1;
DELETE FROM `playercreateinfo` WHERE `race`=22 AND `class`=6;
INSERT INTO `playercreateinfo` (`race`, `class`, `map`, `zone`, `position_x`, `position_y`, `position_z`, `orientation`) VALUES
(1, 6, 609, 4298, 2358.17, -5663.21, 426.027, 3.65997), -- Human - Death Knight
(2, 8, 1, 14, -618.518, -4251.67, 38.718, 0), -- Orc - Mage
(3, 7, 0, 1, -6240.32, 331.033, 382.758, 6.17716), -- Dwarf - Shaman
(3, 8, 0, 1, -6240.32, 331.033, 382.758, 6.17716), -- Dwarf - Mage
(3, 9, 0, 1, -6240.32, 331.033, 382.758, 6.17716), -- Dwarf - Warlock
(4, 8, 1, 141, 10311.3, 832.463, 1326.41, 5.69632), -- Night Elf - Mage
(5, 6, 609, 4298, 2358.17, -5663.21, 426.027, 3.65997), -- Undead - Death Knight
(6, 6, 609, 4298, 2358.17, -5663.21, 426.027, 3.65997), -- Tauren - Death Knight
(7, 6, 609, 4298, 2358.17, -5663.21, 426.027, 3.65997), -- Gnome - Death Knight
(8, 6, 609, 4298, 2358.17, -5663.21, 426.027, 3.65997), -- Troll - Death Knight
(9, 6, 609, 4298, 2358.17, -5663.21, 426.027, 3.65997), -- Goblin - Death Knight
(10, 1, 530, 3431, 10349.6, -6357.29, 33.4026, 5.31605), -- Blood Elf - Warrior
(22, 6, 609, 4298, 2358.17, -5663.21, 426.027, 3.65997); -- Worgen - Death Knight

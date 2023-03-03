-- Warrior autoattack 0 button. it's empty.
DELETE FROM `playercreateinfo_action` WHERE (button = 0 OR button = 1 ) AND class = 1 AND class != 24;
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(1, 1, 0, 6603, 0),
(2, 1, 0, 6603, 0),
(3, 1, 0, 6603, 0),
(5, 1, 0, 6603, 0),
(6, 1, 0, 6603, 0),
(7, 1, 0, 6603, 0),
(8, 1, 0, 6603, 0),
(9, 1, 0, 6603, 0),
(11, 1, 0, 6603, 0),
(22, 1, 0, 6603, 0),
--
(1, 1, 1, 78, 0),
(2, 1, 1, 78, 0),
(3, 1, 1, 78, 0),
(5, 1, 1, 78, 0),
(6, 1, 1, 78, 0),
(7, 1, 1, 78, 0),
(8, 1, 1, 78, 0),
(9, 1, 1, 78, 0),
(11, 1, 1, 78, 0),
(22, 1, 1, 78, 0);

-- Pandaren1 - Warrior. From Snif.
DELETE FROM `playercreateinfo_action` WHERE race = 24 AND class = 1;
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(24, 1, 0, 88163, 0), -- 88163
(24, 1, 1, 78, 0), -- 78
(24, 1, 9, 107079, 0), -- 107079
(24, 1, 11, 77273, 128); -- 77273

-- pandaren hunter.
DELETE FROM `playercreateinfo_action` WHERE race = 24 AND class = 3;
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(24, 3, 0, 3044, 0),
(24, 3, 9, 107079, 0), -- 107079
(24, 3, 10, 9, 48),
(24, 3, 11, 982, 0),
(24, 3, 72, 6603, 0),
(24, 3, 74, 75, 0);

-- Pandaren - Rogue
DELETE FROM `playercreateinfo_action` WHERE race = 24 AND class = 4;
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(24, 4, 0, 6603, 0), -- 6603
(24, 4, 1, 1752, 0), -- 1752
(24, 4, 9, 107079, 0), -- 107079
(24, 4, 11, 77272, 128), -- 77272
(24, 4, 72, 1752, 0); -- 1752

-- Pandaren - Priest
DELETE FROM `playercreateinfo_action` WHERE race = 24 AND class = 5;
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(24, 5, 0, 585, 0), -- 585
(24, 5, 9, 107079, 0), -- 107079
(24, 5, 11, 77264, 128), -- 77264
(24, 5, 72, 585, 0); -- 585

-- Pandaren - Shaman. From Snif.
DELETE FROM `playercreateinfo_action` WHERE race = 24 AND class = 7;
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(24, 7, 0, 6603, 0), -- 6603
(24, 7, 1, 403, 0), -- 403
(24, 7, 9, 107079, 0), -- 107079
(24, 7, 11, 77272, 128), -- 77272
(24, 7, 72, 403, 0); -- 403

-- Pandaren - Mage
DELETE FROM `playercreateinfo_action` WHERE race = 24 AND class = 8;
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(24, 8, 0, 44614, 0), -- 44614
(24, 8, 9, 107079, 0), -- 107079
(24, 8, 11, 77264, 128), -- 77264
(24, 8, 72, 44614, 0); -- 44614

-- Gnome - Monk. From snif.
DELETE FROM `playercreateinfo_action` WHERE race = 7 AND class = 10;
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(7, 10, 72, 100780, 0), -- 100780
(7, 10, 81, 20589, 0); -- 20589

-- Fix all mages spell
UPDATE `playercreateinfo_action` SET `action` = 44614 WHERE `action` = 133;
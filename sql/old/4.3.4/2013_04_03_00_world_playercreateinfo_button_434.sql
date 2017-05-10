-- Fixes tauren druids not having wrath in their spell bar on character creation.
DELETE FROM `playercreateinfo_action` WHERE `race`=6 AND `class`=11 AND `action`=5176;
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(6, 11, 0, 5176, 0);

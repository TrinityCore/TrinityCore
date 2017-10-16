-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`= 1081700 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`= 10817 AND `source_type`=0 AND `id`>2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10817, 0, 3, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Duggan Wildhammer - On aggro - Say \'Line 9\''),
(10817, 0, 4, 0, 1, 0, 100, 0, 5000, 5000, 60000, 60000, 80, 1081700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Duggan Wildhammer - Update OOC - Action list'),
(1081700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Duggan Wildhammer - Action list - Say \'Line 0\''),
(1081700, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Duggan Wildhammer - Action list - Say \'Line 1\''),
(1081700, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Duggan Wildhammer - Action list - Say \'Line 2\''),
(1081700, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Duggan Wildhammer - Action list - Say \'Line 3\''),
(1081700, 9, 4, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Duggan Wildhammer - Action list - Say \'Line 4\''),
(1081700, 9, 5, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Duggan Wildhammer - Action list - Say \'Line 5\''),
(1081700, 9, 6, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Duggan Wildhammer - Action list - Say \'Line 6\''),
(1081700, 9, 7, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Duggan Wildhammer - Action list - Say \'Line 7\''),
(1081700, 9, 8, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Duggan Wildhammer - Action list - Say \'Line 8\'');

DELETE FROM `creature_text` WHERE `entry`= 10817;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(10817, 0, 0, 'Ooooooooh...', 12, 0, 100, 15, 0, 0, 50906, 0, 'Duggan Wildhammer - Line 0'),
(10817, 1, 0, 'To the plaguelands went old Duggan, ta\' send them Scourge back inta\' th\' groun\'.', 12, 0, 100, 1, 0, 0, 50907, 0, 'Duggan Wildhammer - Line 1'),
(10817, 2, 0, 'Where th\' scent of death is on th\' wind and everythin\' is mostly brown.', 12, 0, 100, 6, 0, 0, 50908, 0, 'Duggan Wildhammer - Line 2'),
(10817, 3, 0, 'An\' when he did arrive there, what\'d his dwarf eyes see?', 12, 0, 100, 25, 0, 0, 50909, 0, 'Duggan Wildhammer - Line 3'),
(10817, 4, 0, 'A hundred crates of barley there ta\' be makin\' inta\' mead!', 12, 0, 100, 5, 0, 0, 50910, 0, 'Duggan Wildhammer - Line 4'),
(10817, 5, 0, 'But tha\' mead was cursed with th\' plague o\' death, and now old Duggan, too.', 12, 0, 100, 18, 0, 0, 50911, 0, 'Duggan Wildhammer - Line 5'),
(10817, 6, 0, 'An\' surrounded by the Lich King\'s beasts, what could old Duggan do?', 12, 0, 100, 430, 0, 0, 50912, 0, 'Duggan Wildhammer - Line 6'),
(10817, 7, 0, 'But though I feel the plague within, my hopes \'ave not yet sunk.', 12, 0, 100, 274, 0, 0, 50913, 0, 'Duggan Wildhammer - Line 7'),
(10817, 8, 0, 'If\'n I\'m gonna be Scourge anyway, I might as well be drunk!', 12, 0, 100, 11, 0, 0, 50914, 0, 'Duggan Wildhammer - Line 8'),
(10817, 9, 0, 'Ah ken see very well through this haze, but I\'d know tha\' smell anywhere!  Die ye foul ogre!', 12, 0, 100, 0, 0, 0, 50905, 0, 'Duggan Wildhammer - Line 9');

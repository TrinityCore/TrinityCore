--
DELETE FROM `disables` WHERE `sourceType`=0 AND `entry` IN(50439,47405, 47316, 47149, 47117);
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0, 50439, 64, '', '', 'Ignore LOS on Script Cast Summon Image of Drakuru 05'),
(0, 47405, 64, '', '', 'Ignore LOS on Script Cast Summon Image of Drakuru 04'),
(0, 47316, 64, '', '', 'Ignore LOS on Script Cast Summon Image of Drakuru 03'),
(0, 47149, 64, '', '', 'Ignore LOS on Script Cast Summon Image of Drakuru 02'),
(0, 47117, 64, '', '', 'Ignore LOS on Script Cast Summon Image of Drakuru 01');

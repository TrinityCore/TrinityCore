--
DELETE FROM `spell_area` WHERE `spell` IN(46424);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(46424, 4119, 11896, 0, 0, 0, 2, 1, 10, 0),
(46424, 4035, 11896, 0, 0, 0, 2, 1, 10, 0),
(46424, 4146, 11896, 0, 0, 0, 2, 1, 10, 0),
(46424, 4116, 11896, 0, 0, 0, 2, 1, 10, 0),
(46424, 4117, 11896, 0, 0, 0, 2, 1, 10, 0),
(46424, 4037, 11896, 0, 0, 0, 2, 1, 10, 0);

DELETE FROM `spell_scripts` WHERE `id`=46550;
INSERT INTO `spell_scripts` (`id`, `effIndex`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(46550, 0, 0, 14, 46424, 0, 0, 0, 0, 0, 0);

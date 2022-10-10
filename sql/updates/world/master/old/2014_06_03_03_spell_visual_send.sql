CREATE TABLE `spell_visual_send` (
  `spell_id` int(11) NOT NULL,
  `visual` int(11) NOT NULL,
  `unk1` int(8) NOT NULL DEFAULT '0',
  `unk2` int(8) NOT NULL DEFAULT '0',
  `position` int(3) NOT NULL DEFAULT '0',
  `temp` int(11) NOT NULL DEFAULT '0',
  `comment` text,
  PRIMARY KEY (`spell_id`,`visual`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

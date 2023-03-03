CREATE TABLE `spell_pending_cast` (
  `spell_id` int(11) NOT NULL,
  `pending_id` int(11) NOT NULL,
  `option` tinyint(3) NOT NULL DEFAULT '0',
  `check` int(11) NOT NULL DEFAULT '0',
  `comment` text NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

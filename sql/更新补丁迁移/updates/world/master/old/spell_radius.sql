CREATE TABLE `spell_radius` (
  `spell_id` int(11) NOT NULL DEFAULT '0',
  `effectradius0` int(11) unsigned NOT NULL DEFAULT '0',
  `effectradius1` int(11) unsigned NOT NULL DEFAULT '0',
  `effectradius2` int(11) unsigned NOT NULL DEFAULT '0',
  `effectradius3` int(11) unsigned NOT NULL DEFAULT '0',
  `effectradius4` int(11) unsigned NOT NULL DEFAULT '0',
  `comments` text
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

SET NAMES utf8;

DROP TABLE IF EXISTS `jail`;
CREATE TABLE `jail` (
  `guid` int(11) unsigned NOT NULL COMMENT 'GUID des Knastbruders',
  `char` varchar(13) NOT NULL COMMENT 'Charname des Knastbruders',
  `release` int(11) unsigned NOT NULL COMMENT 'Entlassungszeit',
  `reason` varchar(255) NOT NULL COMMENT 'Grund für die Verhaftung',
  `times` int(11) unsigned NOT NULL COMMENT 'Anzahl der Inhaftierungen',
  `gmacc` int(11) unsigned NOT NULL COMMENT 'Verantwortlicher GM-Account',
  `gmchar` varchar(13) NOT NULL COMMENT 'Verantwortlicher GM-Char',
  `lasttime` int(11) unsigned NOT NULL COMMENT 'Letzte Inhaftierungszeit',
  `duration` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Dauer der Inhaftierung',
  `btimes` int(11) unsigned NOT NULL DEFAULT '0' COMMENT 'Anzahl der Bannungen durch das Jail.',
  PRIMARY KEY (`guid`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Jail Tabelle für UWoM-Server von WarHead.';

DROP TABLE IF EXISTS `jail_conf`;
CREATE TABLE `jail_conf` (
  `max_jails` int(11) unsigned NOT NULL default '3' COMMENT 'Anzahl von Inhaftierungen bei denen der Charrakter gelöscht, und/oder der Account gebannt wird.',
  `max_duration` int(11) unsigned NOT NULL default '720' COMMENT 'Maximale Inhaftierungszeit in Stunden. (Standard = 30 Tage)',
  `min_reason` int(11) unsigned NOT NULL default '40' COMMENT 'Minimum Zeichenlänge der Begründung.',
  `warn_player` tinyint(4) NOT NULL default '1' COMMENT 'Spieler bei jedem Login warnen, wenn die maximale Anzahl der Inhaftierungen fast erreicht ist!? (max_jails)',
  `ally_x` float NOT NULL default '-8673.43' COMMENT 'Allianz Jail X Koordinate',
  `ally_y` float NOT NULL default '631.795' COMMENT 'Allianz Jail Y Koordinate',
  `ally_z` float NOT NULL default '96.9406' COMMENT 'Allianz Jail Z Koordinate',
  `ally_o` float NOT NULL default '2.1785' COMMENT 'Allianz Jail Orientierung',
  `ally_m` int(11) unsigned NOT NULL default '0' COMMENT 'Allianz Jail Karte',
  `horde_x` float NOT NULL default '2179.85' COMMENT 'Horde Jail X Koordinate',
  `horde_y` float NOT NULL default '-4763.96' COMMENT 'Horde Jail Y Koordinate',
  `horde_z` float NOT NULL default '54.911' COMMENT 'Horde Jail Z Koordinate',
  `horde_o` float NOT NULL default '4.44216' COMMENT 'Horde Jail Orientierung',
  `horde_m` int(11) unsigned NOT NULL default '1' COMMENT 'Horde Jail Karte',
  `del_char` tinyint(4) NOT NULL default '0' COMMENT 'Charakter löschen, wenn die maximale Anzahl an Inhaftierungen errreicht ist?',
  `ban_acc` tinyint(4) NOT NULL default '1' COMMENT 'Account bannen, wenn die maximale Anzahl an Inhaftierungen errreicht ist?',
  `ban_duration` int(11) unsigned NOT NULL default '168' COMMENT 'Banndauer in Stunden, nachdem der Account wieder freigeschaltet wird (Standard = 7 Tage).',
  `radius` int(11) unsigned NOT NULL default '10' COMMENT 'Radius in Yards (3D), in dem sich der Knastbruder bewegen kann (0 = keine Bewegung möglich).',
  `enabled` tinyint(4) NOT NULL default '0' COMMENT 'Ein/ausschalten des Jails. Standardeinstellung ist aus.',
  `gm_acc` int(11) unsigned NOT NULL default '2019794' COMMENT 'Account der genutzt wird, um zu bannen.',
  `gm_char` varchar(13) NOT NULL default 'Robotron' COMMENT 'Charaktername der genutzt wird, um zu bannen.',
  PRIMARY KEY  (`max_jails`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Jail Konfigurations-Tabelle für UWoM-Server von WarHead.';

INSERT INTO `jail_conf` (`max_jails`,`max_duration`,`min_reason`,`warn_player`,`ally_x`,`ally_y`,`ally_z`,`ally_o`,`ally_m`,
`horde_x`,`horde_y`,`horde_z`,`horde_o`,`horde_m`,`del_char`,`ban_acc`,`ban_duration`,`radius`,`enabled`) VALUES
(3,672,30,1,31.7282,135.794,-40.0508,4.73516,35,2179.85,-4763.96,54.911,4.44216,1,0,1,168,15,1);

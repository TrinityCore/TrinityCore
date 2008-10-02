DROP TABLE IF EXISTS `npc_option`;
CREATE TABLE `npc_option` (
`id` int(11) unsigned NOT NULL default '0',
`gossip_id` int(11) unsigned NOT NULL default '0',
`npcflag` int(11) unsigned NOT NULL default '0',
`icon` int(11) unsigned NOT NULL default '0',
`action` int(11) unsigned NOT NULL default '0',
`option` text NOT NULL,
PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

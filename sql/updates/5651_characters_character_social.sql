alter table `character_social`
change `guid` `guid` int(11) unsigned NOT NULL DEFAULT '0' comment 'Character Global Unique Identifier' first,
change `friend` `friend` int(11) unsigned NOT NULL DEFAULT '0' comment 'Friend Global Unique Identifier' after `guid`,
change `flags` `flags` tinyint(1) unsigned NOT NULL DEFAULT '0' comment 'Friend flags' after `friend`,
change `name` `note` varchar(21) NOT NULL DEFAULT '' collate utf8_general_ci comment 'Friend Note' after `flags`;

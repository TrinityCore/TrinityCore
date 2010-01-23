DROP TABLE IF EXISTS `spell_stack_masks`;

CREATE TABLE `spell_stack_masks` (
  `id` int(32) unsigned NOT NULL default '0',
  `mask` int(64) unsigned NOT NULL default '0',
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

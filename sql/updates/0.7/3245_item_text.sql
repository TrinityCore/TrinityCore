DROP TABLE IF EXISTS `item_text`;
CREATE TABLE `item_text` (
  `id` int(11) NOT NULL default '0',
  `text` longtext,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Item System';

DROP TABLE IF EXISTS `areatrigger_city`;  
CREATE TABLE `areatrigger_city` (  
  `id` int(11) unsigned NOT NULL default '0' COMMENT 'Identifier',  
  `name` text,  
  PRIMARY KEY  (`id`)  
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Trigger System'; 

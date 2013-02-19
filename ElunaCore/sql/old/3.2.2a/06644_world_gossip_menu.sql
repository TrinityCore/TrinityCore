DROP TABLE IF EXISTS gossip_menu;
CREATE TABLE gossip_menu (
  entry smallint(6) unsigned NOT NULL default '0',
  text_id mediumint(8) unsigned NOT NULL default '0',
  cond_1 tinyint(3) unsigned NOT NULL default '0',
  cond_1_val_1 mediumint(8) unsigned NOT NULL default '0',
  cond_1_val_2 mediumint(8) unsigned NOT NULL default '0',
  cond_2 tinyint(3) unsigned NOT NULL default '0',
  cond_2_val_1 mediumint(8) unsigned NOT NULL default '0',
  cond_2_val_2 mediumint(8) unsigned NOT NULL default '0',
  PRIMARY KEY (entry, text_id)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

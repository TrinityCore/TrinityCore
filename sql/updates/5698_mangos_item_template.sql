ALTER TABLE item_template
  CHANGE COLUMN stackable stackable smallint(5) unsigned NOT NULL default '1';

ALTER TABLE item_template
  CHANGE COLUMN RequiredArenaRank CondExtendedCost int(10) unsigned NOT NULL default '0';

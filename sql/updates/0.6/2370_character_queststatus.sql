ALTER TABLE `character_queststatus` 
  CHANGE `rewarded` `rewarded` tinyint(1) unsigned NOT NULL default '0',
  CHANGE `explored` `explored` tinyint(1) unsigned NOT NULL default '0',
  ADD COLUMN `completed_once`  tinyint(1) unsigned NOT NULL default '0' AFTER `explored`;

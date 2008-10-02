ALTER TABLE `character_aura` 
  ADD `maxduration`   int(11) NOT NULL default '0' AFTER `amount`,
  ADD `remaincharges` int(11) NOT NULL default '0' AFTER `remaintime`;

UPDATE `character_aura` 
  SET `maxduration` = `remaintime`, `remaincharges` = -1;
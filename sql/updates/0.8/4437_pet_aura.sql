ALTER TABLE `pet_aura` 
  ADD `maxduration`   int(11) NOT NULL default '0' AFTER `amount`,
  ADD `remaincharges` int(11) NOT NULL default '0' AFTER `remaintime`;

UPDATE `pet_aura` 
  SET `maxduration` = `remaintime`, `remaincharges` = -1;

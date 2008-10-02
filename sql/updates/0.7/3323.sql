ALTER TABLE `character_pet` 
  ADD COLUMN `slot` tinyint(1) unsigned NOT NULL default '0',
  CHANGE COLUMN `id` `id` int(11) unsigned NOT NULL default '0';

UPDATE `character_pet`
  SET `slot` = 0 WHERE `current` = 1;

/* slot 3 =  for storing warlock and another not stabled pets */
UPDATE `character_pet`
  SET `slot` = 3 WHERE `current` = 0;

/* current = (`slot`==0) */
ALTER TABLE `character_pet` 
  DROP COLUMN `current`;

UPDATE `character_pet`, `character_stable`
  SET `character_pet`.`slot`     =`character_stable`.`slot`
  WHERE `character_pet`.`id`=`character_stable`.`petnumber` 
    AND `character_pet`.`owner`=`character_stable`.`owner` AND `character_pet`.`id`=`character_stable`.`petnumber`;

ALTER TABLE `character` 
  ADD COLUMN `stable_slots` tinyint(1) unsigned NOT NULL default '0';

UPDATE `character`, (
  SELECT `character_stable`.`owner` as `owner_slots`, MAX(`character_stable`.`slot`) as `slots` FROM `character_stable` GROUP BY `character_stable`.`owner`
  ) as `stable_slots`
  SET `character`.`stable_slots`= `stable_slots`.`slots`
  WHERE `character`.`guid` = `stable_slots`.`owner_slots`;


DROP TABLE IF EXISTS `character_stable`;

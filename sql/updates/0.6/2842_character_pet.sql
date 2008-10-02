ALTER TABLE `character_pet`
  ADD COLUMN `modelid` int(11) unsigned default '0' after `owner`;

UPDATE `character_pet`,`creature_template`
  SET `character_pet`.`modelid` = `creature_template`.`modelid_m` 
  WHERE `character_pet`.`modelid` = 0 AND `character_pet`.`entry` = `creature_template`.`entry`;

UPDATE `character_pet`,`creature_template`
  SET `character_pet`.`modelid` = `creature_template`.`modelid_f` 
  WHERE `character_pet`.`modelid` = 0 AND `character_pet`.`entry` = `creature_template`.`entry`;

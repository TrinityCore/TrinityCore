ALTER TABLE `character_aura` 
  ADD `caster_guid` bigint(20) unsigned NOT NULL default '0' COMMENT 'Full Global Unique Identifier' AFTER `guid`,
  ADD `amount`     int(11) NOT NULL default '0' AFTER `effect_index`;

UPDATE `character_aura` 
  SET `caster_guid` = `guid`;
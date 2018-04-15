ALTER TABLE `character_aura`
  ADD COLUMN `item_guid`  bigint(20) UNSIGNED NOT NULL DEFAULT '0' AFTER `caster_guid`,
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`guid`,`caster_guid`,`item_guid`,`spell`,`effect_mask`);

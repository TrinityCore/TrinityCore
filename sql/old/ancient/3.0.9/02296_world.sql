ALTER TABLE creature_template
  ADD COLUMN `VehicleId` mediumint(8) unsigned NOT NULL default '0' AFTER `PetSpellDataId`;

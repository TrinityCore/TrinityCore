ALTER TABLE `item_instance`
  ADD `battlePetSpeciesId` int(10) unsigned NOT NULL DEFAULT '0' AFTER `enchantIllusion`,
  ADD `battlePetBreedData` int(10) unsigned NOT NULL DEFAULT '0' AFTER `battlePetSpeciesId`,
  ADD `battlePetLevel` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `battlePetBreedData`,
  ADD `battlePetDisplayId` int(10) unsigned NOT NULL DEFAULT '0' AFTER `battlePetLevel`;

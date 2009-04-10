ALTER TABLE character_db_version CHANGE COLUMN required_7546_01_characters_uptime required_7644_01_characters_character_pet bit;

/* only hunter pets must be in stable */
UPDATE `character_pet`
  SET slot = 100 WHERE PetType <> 1 AND slot >= 1 AND slot <= 4;

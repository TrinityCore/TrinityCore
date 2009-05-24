ALTER TABLE character_db_version CHANGE COLUMN required_7884_05_characters_character_action required_7887_01_characters_character_pet bit;

ALTER TABLE `character_pet`
  DROP TeachSpelldata;

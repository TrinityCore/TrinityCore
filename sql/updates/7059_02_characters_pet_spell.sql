ALTER TABLE character_db_version CHANGE COLUMN required_7059_01_characters_character_spell required_7059_02_characters_pet_spell bit;

ALTER TABLE pet_spell
    DROP slot;

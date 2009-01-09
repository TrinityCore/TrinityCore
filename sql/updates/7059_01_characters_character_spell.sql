ALTER TABLE character_db_version CHANGE COLUMN required_7047_01_characters_character_spell required_7059_01_characters_character_spell bit;

ALTER TABLE character_spell
    DROP slot;

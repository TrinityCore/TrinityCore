ALTER TABLE character_db_version CHANGE COLUMN required_7884_03_characters_character_spell required_7884_04_characters_character_aura bit;

DELETE FROM character_aura WHERE spell = '28734';

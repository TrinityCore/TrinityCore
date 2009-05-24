ALTER TABLE character_db_version CHANGE COLUMN required_7884_04_characters_character_aura required_7884_05_characters_character_action bit;

DELETE FROM  character_action WHERE action = '28734' AND type = '0';
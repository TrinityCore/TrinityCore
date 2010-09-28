-- mangos rev 8397
-- ALTER TABLE character_db_version CHANGE COLUMN required_8339_02_characters_character_battleground_data required_8397_03_characters_character_spell bit;

UPDATE IGNORE character_spell SET spell=7386 WHERE spell IN (7405,8380,11596,11597,25225,47467);
UPDATE character_spell SET active=1 WHERE spell=7386;
DELETE FROM character_spell WHERE spell IN (7405,8380,11596,11597,25225,47467);

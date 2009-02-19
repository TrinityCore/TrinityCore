/*ALTER TABLE character_db_version CHANGE COLUMN required_6976_02_characters_character_db_version required_7047_01_characters_character_spell bit;*/

DELETE FROM `character_spell` WHERE `spell` IN ('28880', 59542, 59543, 59544, 59545, 59547, 59548);
INSERT INTO character_spell SELECT characters.guid as guid, 28880, 1, 0  FROM `characters` WHERE characters.race=11 AND characters.class = 1;
INSERT INTO character_spell SELECT characters.guid as guid, 59542, 1, 0  FROM `characters` WHERE characters.race=11 AND characters.class = 2;
INSERT INTO character_spell SELECT characters.guid as guid, 59543, 1, 0  FROM `characters` WHERE characters.race=11 AND characters.class = 3;
INSERT INTO character_spell SELECT characters.guid as guid, 59544, 1, 0  FROM `characters` WHERE characters.race=11 AND characters.class = 5;
INSERT INTO character_spell SELECT characters.guid as guid, 59545, 1, 0  FROM `characters` WHERE characters.race=11 AND characters.class = 6;
INSERT INTO character_spell SELECT characters.guid as guid, 59547, 1, 0  FROM `characters` WHERE characters.race=11 AND characters.class = 7;
INSERT INTO character_spell SELECT characters.guid as guid, 59548, 1, 0  FROM `characters` WHERE characters.race=11 AND characters.class = 8;
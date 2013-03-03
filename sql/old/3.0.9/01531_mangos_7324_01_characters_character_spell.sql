/*ALTER TABLE character_db_version CHANGE COLUMN required_7314_01_characters_guild_rank required_7324_01_characters_character_spell bit;*/

/* remove some deleted spells or ranks from characters */
/* Mana Tap no longer Blood Elf Racial */
DELETE FROM `character_spell` WHERE `spell` = '28734';
/* Hamstring is only one rank now, need to delete these zzOLDRank spells */
DELETE FROM `character_spell` WHERE `spell` IN ('7373', '7372', '25212');
/* Intercept is only one rank now, need to delete these zzOLDRank spells */
DELETE FROM `character_spell` WHERE `spell` IN ('20616', '20617', '25272', '25275');
/* Overpower is only one rank now, need to delete these zzOLDRank spells */
DELETE FROM `character_spell` WHERE `spell` IN ('7887', '11584', '11585');
/* Shield Bash is only one rank now, need to delete these zzOLDRank spells */
DELETE FROM `character_spell` WHERE `spell` IN ('1671', '1672', '29704');

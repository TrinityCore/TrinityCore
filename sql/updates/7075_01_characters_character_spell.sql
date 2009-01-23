ALTER TABLE character_db_version CHANGE COLUMN required_7067_03_characters_character_spell required_7075_01_characters_character_spell bit;

DELETE FROM character_spell WHERE `spell` IN (
 20580, /*old Shadowmeld*/
 20600, /*Perception*/
 21009, /*old Shadowmeld Passive and new Elusiveness (learned as racial passive)*/
 21184  /*old Seal of Righteousness*/
);


/*old Shadow Resistance, leaned as racial passive of race 5 */
DELETE FROM character_spell USING character_spell INNER JOIN characters ON character_spell.guid = characters.guid
WHERE character_spell.spell = 20579 AND characters.race <> 5;

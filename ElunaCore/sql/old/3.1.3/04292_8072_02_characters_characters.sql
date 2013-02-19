-- ALTER TABLE character_db_version CHANGE COLUMN required_8072_01_characters_characters required_8072_02_characters_characters bit;

UPDATE characters SET
gender = (CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(data, ' ', 23), ' ', -1) AS UNSIGNED) & 0xFF0000) >> 16,
level = CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(data, ' ', 54), ' ', -1) AS UNSIGNED),
xp = CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(data, ' ', 609), ' ', -1) AS UNSIGNED),
money = CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(data, ' ', 1145), ' ', -1) AS UNSIGNED),
playerBytes = CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(data, ' ', 154), ' ', -1) AS UNSIGNED),
playerBytes2 = CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(data, ' ', 155), ' ', -1) AS UNSIGNED),
playerFlags = CAST(SUBSTRING_INDEX(SUBSTRING_INDEX(data, ' ', 151), ' ', -1) AS UNSIGNED)
WHERE LENGTH(SUBSTRING_INDEX(data, ' ', 1294)) < LENGTH(data) && LENGTH(data) <= LENGTH(SUBSTRING_INDEX(data, ' ', 1295));

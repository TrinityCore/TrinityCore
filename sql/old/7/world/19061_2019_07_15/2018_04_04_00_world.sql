-- remove deprecated spells from new characters
DELETE FROM `playercreateinfo_cast_spell` WHERE `spell` IN (2457, 48266);

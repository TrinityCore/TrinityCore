DELETE FROM `character_spell` WHERE `spell` IN (31892, 53720);
DELETE FROM `character_spell_cooldown` WHERE `spell` IN (31892, 53720);
DELETE FROM `character_aura` WHERE `spell` IN (31892, 53720);
DELETE FROM `character_action` WHERE `action` IN (31892, 53720) AND `type`=0;
UPDATE characters SET data = REPLACE(data,' ',' ');
UPDATE characters SET data = CONCAT(TRIM(data),' ');
 
UPDATE `characters` SET `data` = CONCAT(
SUBSTRING_INDEX(`data`, ' ', 1167 + 1), ' ',
'0 0 ',
SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 1246 + 1), ' ', -1246 + 1168 - 1), ' ',
'0 0 0 ',
SUBSTRING_INDEX(SUBSTRING_INDEX(`data`, ' ', 1294 + 1), ' ', -1294 + 1247 - 1), ' ',
'0 '
)
WHERE length(SUBSTRING_INDEX(data, ' ', 1294)) < length(data) and length(SUBSTRING_INDEX(data, ' ', 1294+1)) >= length(data);
 
UPDATE characters SET data = REPLACE(data,' ',' ');
UPDATE characters SET data = CONCAT(TRIM(data),' ');

alter table `groups`
    add column `raiddifficulty` int(11) UNSIGNED DEFAULT '0' NOT NULL after `difficulty`;

ALTER TABLE `bugreport` CHANGE `type` `type` LONGTEXT NOT NULL;
ALTER TABLE `bugreport` CHANGE `content` `content` LONGTEXT NOT NULL;

DELETE FROM `character_spell` WHERE `spell` IN (31892, 53720);
DELETE FROM `character_spell_cooldown` WHERE `spell` IN (31892, 53720);
DELETE FROM `character_aura` WHERE `spell` IN (31892, 53720);
DELETE FROM `character_action` WHERE `action` IN (31892, 53720) AND `type`=0;
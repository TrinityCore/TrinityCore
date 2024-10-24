ALTER TABLE `custom_npc_tele_category` ALTER COLUMN `icon` SET DEFAULT 'inv_misc_shadowegg';
ALTER TABLE `custom_npc_tele_category` ALTER COLUMN `size` SET DEFAULT '30';
ALTER TABLE `custom_npc_tele_category` ALTER COLUMN `colour` SET DEFAULT '000000';

UPDATE `custom_npc_tele_category` set `icon`='inv_misc_shadowegg' where `icon` = '';
UPDATE `custom_npc_tele_category` SET `size`='30' WHERE `size` = '';
UPDATE `custom_npc_tele_category` SET `colour`='000000' WHERE `colour` = '';

ALTER TABLE `custom_npc_tele_destination` ALTER COLUMN `icon` SET DEFAULT 'inv_misc_shadowegg';
ALTER TABLE `custom_npc_tele_destination` ALTER COLUMN `size` SET DEFAULT '30';
ALTER TABLE `custom_npc_tele_destination` ALTER COLUMN `colour` SET DEFAULT '000000';

UPDATE `custom_npc_tele_destination` set `icon`='inv_misc_shadowegg' where `icon` = '';
UPDATE `custom_npc_tele_destination` SET `size`='30' WHERE `size` = '';
UPDATE `custom_npc_tele_destination` SET `colour`='000000' WHERE `colour` = '';

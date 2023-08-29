-- 
ALTER TABLE `creature` 
    MODIFY COLUMN `npcflag` bigint UNSIGNED NULL DEFAULT NULL AFTER `MovementType`,
    MODIFY COLUMN `unit_flags` int UNSIGNED NULL DEFAULT NULL AFTER `npcflag`,
    MODIFY COLUMN `unit_flags2` int UNSIGNED NULL DEFAULT NULL AFTER `unit_flags`,
    MODIFY COLUMN `unit_flags3` int UNSIGNED NULL DEFAULT NULL AFTER `unit_flags2`;

UPDATE `creature` SET `npcflag`=NULL WHERE `npcflag`=0;
UPDATE `creature` SET `unit_flags`=NULL WHERE `unit_flags`=0;
UPDATE `creature` SET `unit_flags2`=NULL WHERE `unit_flags2`=0;
UPDATE `creature` SET `unit_flags3`=NULL WHERE `unit_flags3`=0;

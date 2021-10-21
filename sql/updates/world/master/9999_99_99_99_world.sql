-- 
ALTER TABLE `creature_text`
    ADD COLUMN `SoundPlayType` TINYINT UNSIGNED NOT NULL DEFAULT '0' AFTER `Sound`;
    
UPDATE `creature_text` SET `SoundPlayType`=1 WHERE `CreatureID`=130986;

-- 
ALTER TABLE `warden_checks`
    MODIFY COLUMN `str` VARCHAR(170) DEFAULT NULL,
    MODIFY COLUMN `result` VARBINARY(24) DEFAULT NULL;

-- shift all warden checks down by 1 so we no longer have a gap at id 0
-- (left join is for reapply safety)
UPDATE `warden_checks` wc1
    LEFT JOIN `warden_checks` wc2 ON `wc2`.`id` = 0
    SET `wc1`.`id` = `wc1`.`id`-1
    WHERE `wc2`.`id` IS NULL;

DELETE FROM `warden_checks` WHERE `id` IN (786,787);
INSERT INTO `warden_checks` (`id`,`type`,`str`,`address`,`length`,`result`, `comment`) VALUES
(786, 243, NULL, 0x819210, 16, UNHEX('558BEC518305A013D40001A19C13D400'), 'FrameScript::Execute'),
(787, 243, NULL, 0x84F860, 15, UNHEX('558BEC8B4D108B450C83EC0883F903'), 'FrameScript::lua_loadbuffer');

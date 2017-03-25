-- 
ALTER TABLE `creature` ADD COLUMN `ScriptName` CHAR(64) NULL DEFAULT '' AFTER `dynamicflags`;
ALTER TABLE `gameobject` ADD COLUMN `ScriptName` CHAR(64) NULL DEFAULT '' AFTER `state`;
--

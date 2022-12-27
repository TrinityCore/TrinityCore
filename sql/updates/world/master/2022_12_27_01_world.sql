--
DELETE FROM `trinity_string` WHERE `entry`=5089;
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(5089,'Template StringID: %.*s\Spawn StringID: %.*s\nScript StringID: %.*s');

ALTER TABLE `creature` ADD `StringId` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL AFTER ScriptName;
  
ALTER TABLE `creature_template` ADD `StringId` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL AFTER ScriptName;

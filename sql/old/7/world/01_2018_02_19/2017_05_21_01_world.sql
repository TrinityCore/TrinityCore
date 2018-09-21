ALTER TABLE `creature`
  ADD `unit_flags2` INT(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `unit_flags`,
  ADD `unit_flags3` INT(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `unit_flags2`;

ALTER TABLE `creature_template`
  ADD `unit_flags3` INT(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `unit_flags2`;

DELETE FROM `trinity_string` WHERE `entry` IN (542, 5070, 5071, 5072);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(542, 'Dynamic Flags: %u'),
(5070, 'Unit Flags 2: %u'),
(5071, 'Unit Flags 3: %u'),
(5072, 'NPC Flags: %u');

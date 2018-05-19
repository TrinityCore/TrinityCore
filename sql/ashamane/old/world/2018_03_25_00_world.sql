ALTER TABLE `creature`
  ADD `phaseUseFlags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `spawnMask`,
  ADD `terrainSwapMap` int(11) NOT NULL DEFAULT '-1' AFTER `PhaseGroup`;

ALTER TABLE `gameobject`
  ADD `phaseUseFlags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `spawnMask`,
  ADD `terrainSwapMap` int(11) NOT NULL DEFAULT '-1' AFTER `PhaseGroup`;

DROP TABLE `terrain_phase_info`;

ALTER TABLE `transports` ADD `phaseUseFlags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `name`;

DELETE FROM `trinity_string` WHERE `entry` IN (101,178,179,180,181,182,183,184,185);
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
(101,'Map: %u (%s) Zone: %u (%s) Area: %u (%s)\nX: %f Y: %f Z: %f Orientation: %f'),
(178,'grid[%u,%u]cell[%u,%u] InstanceID: %u\n ZoneX: %f ZoneY: %f\nGroundZ: %f FloorZ: %f Have height data (Map: %u VMap: %u MMap: %u)'),
(179,'PhaseShift:\n* Flags %u, PersonalGuid: %s'),
(180,'* Phases: %s'),
(181,'* VisibleMapIds: %s'),
(182,'* UiWorldMapAreaSwaps: %s'),
(183,'Cosmetic'),
(184,'Personal');

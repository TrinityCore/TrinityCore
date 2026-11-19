ALTER TABLE `creature`
 ADD COLUMN `npcflag` int(10) unsigned NOT NULL DEFAULT '0' AFTER `MovementType`,
 ADD COLUMN `unit_flags` int(10) unsigned NOT NULL DEFAULT '0' AFTER `npcflag`,
 ADD COLUMN `dynamicflags` int(10) unsigned NOT NULL DEFAULT '0' AFTER `unit_flags`;

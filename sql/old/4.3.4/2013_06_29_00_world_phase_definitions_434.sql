ALTER TABLE `phase_definitions`
	CHANGE COLUMN `phaseId` `phaseId` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `phasemask`;

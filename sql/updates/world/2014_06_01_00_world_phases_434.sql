ALTER TABLE `creature`
    ADD `PhaseId` INT(10) DEFAULT '0' AFTER `phaseMask`,
    ADD `PhaseGroup` INT(10) DEFAULT '0' AFTER `PhaseId`;
ALTER TABLE `gameobject`
    ADD `PhaseId` INT(10) DEFAULT '0' AFTER `phaseMask`,
    ADD `PhaseGroup` INT(10) DEFAULT '0' AFTER `PhaseId`;

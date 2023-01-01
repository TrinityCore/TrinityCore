-- Add Name placeholder for phaseshift

DELETE FROM `trinity_string` WHERE `entry` = 179;
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(179, "PhaseShift:
* Flags %u, PersonalGuid: %s (%s)");

--
SET @CGUID := 45212;
DELETE FROM `creature` WHERE `guid` IN (@CGUID);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID, 30082, 571, 1, 4, 7271.656, -878.8148, 926.0092, 5.532694, 600, 0, 0);

DELETE FROM `spell_area` WHERE `spell`=55783 AND `area`=4432;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(55783, 4432, 12879, 12973, 0, 0, 2, 1, 66, 1);

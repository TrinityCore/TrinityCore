SET @CGUID:= 16806; -- 1 guid
SET @GGUID:= 1577; -- 2 guids

DELETE FROM `creature` WHERE `guid` = @CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(@CGUID, 16031, 329, 0, 0, 1, 1, 0, 0, 4044.78, -3333.68, 117.26, 4.153883, 7200, 0, 0, 4120, 0, 0, 0, 0, 0, '', 0);

DELETE FROM `gameobject` WHERE `guid` IN (@GGUID + 0, @GGUID + 1);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `ScriptName`, `VerifiedBuild`) VALUES
(@GGUID + 0, 181071, 329, 2017, 2017, 1, 1, 4044.34, -3334.217, 115.0604, 2.740162, -0, -0, 0.9799242, 0.1993704, 300, 255, 1, '', 0),
(@GGUID + 1, 181072, 329, 2017, 2017, 1, 1, 4039.52, -3331.85, 115.061, 1.169369, -0, -0, 0.5519361, 0.8338864, 300, 255, 1, '', 0);

DELETE FROM `spell_script_names` WHERE `ScriptName` = "spell_ysida_saved_credit";
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(31912, "spell_ysida_saved_credit");

UPDATE `creature_template` SET `npcflag` = `npcflag` & ~2, `AIName` = "" WHERE `entry` = 16031;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 16031;

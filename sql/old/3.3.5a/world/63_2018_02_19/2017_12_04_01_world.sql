-- Add two Draenei Artificers
DELETE FROM `creature` WHERE `guid` IN (82823,82841);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(82823, 17228, 530, 0, 0, 1, 1, 0, 1, -4191.44, -12464.07, 45.340, 3.7988, 300, 0, 0, 98, 115, 2, 0, 0, 0, 0),
(82841, 17228, 530, 0, 0, 1, 1, 0, 1, -4213.64, -12467.37, 45.464, 0.9833, 300, 0, 0, 98, 115, 0, 0, 0, 0, 0);

-- Move script of Draenei Artificer from ID to specific GUID
UPDATE `smart_scripts` SET `entryorguid`=-61962 WHERE `entryorguid`=17228 AND `source_type`=0;

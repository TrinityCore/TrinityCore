--
DELETE FROM `creature` WHERE `guid` IN (120831,120833,123124);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(120831, 32769, 571, 1, 1, 25753, 0, 7523.09, 1852.78, 491.641, 3.23212, 300, 0, 0, 12600, 3994, 0, 0, 0, 0, 0),
(120833, 32769, 571, 1, 1, 25753, 0, 7703.2, 1822.89, 469.378, 3.94286, 300, 0, 0, 12600, 3994, 0, 0, 0, 0, 0),
(123124, 32769, 571, 1, 1, 25753, 0, 7733.55, 1578.02, 469.378, 2.51066, 300, 0, 0, 12600, 3994, 0, 0, 0, 0, 0);

DELETE FROM pool_creature WHERE guid = 151994;

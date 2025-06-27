--
UPDATE `creature` SET `modelid`=0, `spawndist`=0, `MovementType`=0 WHERE `id`=30037;
UPDATE `creature` SET `orientation`=4.01702 WHERE `guid`=122274;
UPDATE `creature` SET `position_x`=8418.1152, `position_y`=3099.1055, `position_z`=588.1407, `orientation`=2.39233 WHERE `guid`=122282;
UPDATE `creature` SET `position_x`=8389.5381, `position_y`=3089.6367, `position_z`=588.1461, `orientation`=0.19321 WHERE `guid`=122277;
UPDATE `creature` SET `position_x`=8407.9512, `position_y`=3067.1392, `position_z`=588.1420, `orientation`=2.35367 WHERE `guid`=122280;
UPDATE `creature` SET `position_x`=8403.9629, `position_y`=3071.0413, `position_z`=588.1420, `orientation`=5.55800 WHERE `guid`=122272;
UPDATE `creature` SET `position_x`=8432.4512, `position_y`=3076.2439, `position_z`=588.1423, `orientation`=5.98605 WHERE `guid`=122276;
UPDATE `creature` SET `position_x`=8468.8838, `position_y`=3095.4836, `position_z`=588.1412, `orientation`=0.79457 WHERE `guid`=122275;
UPDATE `creature` SET `position_x`=8461.1221, `position_y`=3120.8025, `position_z`=588.1393, `orientation`=1.90437 WHERE `guid`=122281;
UPDATE `creature` SET `position_x`=8460.2520, `position_y`=3125.6013, `position_z`=588.1425, `orientation`=4.88889 WHERE `guid`=122271;
UPDATE `creature` SET `position_x`=8449.5693, `position_y`=3149.9019, `position_z`=588.1426, `orientation`=2.80751 WHERE `guid`=122273;
UPDATE `creature` SET `position_x`=8445.9375, `position_y`=3151.6152, `position_z`=588.1661, `orientation`=5.83915 WHERE `guid`=122284;
   
DELETE FROM `creature` WHERE `guid`=111259;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(111259, 30037, 571, 0, 0, 1, 1, 0, 1, 8412.42, 3161.56, 588.106, 0.757619, 300, 0, 0, 12175, 0, 0, 0, 0, 0, "", 0);

DELETE FROM `creature_addon` WHERE `guid` IN (122271, 122272, 122273, 122274, 122275, 122276, 122277, 122280, 122281, 122282, 122283, 122284, 122287, 122288, 122289, 122290, 122291, 122292, 122293);
DELETE FROM `creature_template_addon` WHERE `entry`=30037;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(30037, 0, 0, 0, 1, 333, 0, "");

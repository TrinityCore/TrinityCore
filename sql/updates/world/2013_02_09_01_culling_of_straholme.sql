/* Clean-up outside before we go in! */
SET @CGUID:= ???? -- Need

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+26;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 29865, 1, 1, 1, 0, 0, -8746.62, -4428.1, -201.354, 6.24828, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+1, 29865, 1, 1, 1, 0, 0, -8643.38, -4351.43, -208.111, 6.26573, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+2, 29865, 1, 1, 1, 0, 0, -8656.92, -4389.86, -207.436, 2.23402, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+3, 29865, 1, 1, 1, 0, 0, -8660.77, -4404.86, -207.4, 5.48033, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+4, 29865, 1, 1, 1, 0, 0, -8677.56, -4405.93, -206.679, 3.57792, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+5, 29865, 1, 1, 1, 0, 0, -8613.5, -4414.04, -209.149, 1.06465, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+6, 29866, 1, 1, 1, 0, 0, -8743.8, -4428.17, -201.36, 3.07178, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+7, 29866, 1, 1, 1, 0, 0, -8724.14, -4412.39, -203.747, 3.80482, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+8, 29866, 1, 1, 1, 0, 0, -8662.23, -4383.17, -206.934, 5.39307, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+9, 29866, 1, 1, 1, 0, 0, -8641.65, -4352.35, -208.204, 2.77507, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+10, 29866, 1, 1, 1, 0, 0, -8642.65, -4359.16, -208.243, 4.2586, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+11, 29866, 1, 1, 1, 0, 0, -8659.16, -4406.02, -207.438, 2.68781, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+12, 29866, 1, 1, 1, 0, 0, -8612.38, -4410.71, -209.356, 4.29351, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+13, 29867, 1, 1, 1, 0, 0, -8751.68, -4452.36, -199.699, 1.29154, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+14, 29867, 1, 1, 1, 0, 0, -8759.25, -4450.96, -200.123, 1.39626, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+15, 29867, 1, 1, 1, 0, 0, -8645.1, -4371.34, -208.185, 0.506145, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+16, 29867, 1, 1, 1, 0, 0, -8678.84, -4405.57, -206.534, 4.60767, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+17, 29867, 1, 1, 1, 0, 0, -8629.69, -4396.92, -208.617, 3.01942, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+18, 29867, 1, 1, 1, 0, 0, -8630.17, -4400.45, -208.464, 1.27409, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+19, 29868, 1, 1, 1, 0, 0, -8747.63, -4450.67, -199.451, 3.52556, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+20, 29868, 1, 1, 1, 0, 0, -8707.38, -4416.52, -205.047, 5.65487, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+21, 29868, 1, 1, 1, 0, 0, -8747.43, -4448.76, -199.175, 3.83972, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+22, 29868, 1, 1, 1, 0, 0, -8661.53, -4381.77, -206.93, 6.0912, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+23, 29868, 1, 1, 1, 0, 0, -8611.45, -4411.41, -209.398, 3.92699, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+24, 29868, 1, 1, 1, 0, 0, -8611.28, -4412.6, -209.366, 3.87463, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+25, 29868, 1, 1, 1, 0, 0, -8614.49, -4410.79, -209.182, 4.93928, 120, 0, 0, 1, 0, 0, 0, 0, 0),
(@CGUID+26, 29873, 1, 1, 1, 0, 0, -8706.65, -4417, -205.124, 2.70526, 120, 0, 0, 1, 0, 0, 0, 0, 0);


-- Doodad_InstancePortal_Purqq
DELETE FROM `gameobject` WHERE `guid`=17455 LIMIT 1;

-- Custodian of Time
DELETE FROM `creature` WHERE `guid` IN (24361, 23460);

-- Lordaeron Footman Specimen mounts (Swift Brown Steed)
DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+2, @CGUID+3, @CGUID+17);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID+2, 0, 14561, 0, 0, 0, '34712'),
(@CGUID+3, 0, 14561, 0, 0, 0, '34712'),
(@CGUID+17, 0, 14561, 0, 0, 0, '34712');

-- Stratholme Child Specimen, Stratholme Resident Specimen, Lordaeron Footman Specimen, Stratholme Citizen Specimen, Cat Specimen Aura fixes
DELETE FROM `creature_template_addon` WHERE `entry` IN (29868, 29866, 29867, 29865, 29873);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(29865, 0, 0, 0, 1, 0, '34712'),
(29866, 0, 0, 0, 1, 0, '34712'),
(29867, 0, 0, 0, 0, 0, '34712'),
(29868, 0, 0, 0, 1, 0, '34712'),
(29873, 0, 0, 0, 1, 0, '34712');


-- Culling of Stratholme entrance
DELETE FROM `areatrigger_teleport` WHERE `id`=5148 LIMIT 1;
INSERT INTO `areatrigger_teleport` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`, `name`) VALUES
(5148, 1, -8756.6, -4457.02, -200.481, 1.39626, 'CoT Stratholme - Exit Target');

-- Grain Crate Helper
UPDATE `creature_template` SET `ScriptName`="npc_grain_crate_helper_cos" WHERE `entry`=27827 LIMIT 1;

-- Creature Text: Arthas
-- Fixing typo
UPDATE `creature_text` SET `text`="Mal'Ganis appears to have more than Scourge in his arsenal. We should make haste.", `comment`="culling SAY_PHASE306" WHERE `sound`=14301 LIMIT 1;
-- Correcting order
UPDATE `creature_text` SET `groupid`=21, `comment`="culling SAY_PHASE310" WHERE `text`="One less obstacle to deal with." AND `entry`=26499 LIMIT 1;
UPDATE `creature_text` SET `groupid`=22  WHERE `text`="Let's move on." AND `sound`=14303 LIMIT 1;
UPDATE `creature_text` SET `groupid`=23  WHERE `text`="Watch your backs: they have us surrounded in this hall." AND `sound`=14304 LIMIT 1;


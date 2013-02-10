/* Clean-up outside before we go in! */
SET @CGUID:= ???? -- Need

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+26;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@GUID+0, 29868, 1, 1, 1, 0, 0, -8748.43, -4451.59, -199.662, 3.30822, 300, 0, 0, 3653, 0, 0, 0, 0, 0),
(@GUID+1, 29868, 1, 1, 1, 0, 0, -8748.54, -4450.09, -199.464, 3.2022, 300, 0, 0, 3531, 0, 0, 0, 0, 0),
(@GUID+2, 29867, 1, 1, 1, 0, 223, -8752.14, -4452.25, -199.773, 1.31981, 300, 0, 0, 12600, 0, 0, 0, 0, 0),
(@GUID+3, 29867, 1, 1, 1, 0, 223, -8758.88, -4450.55, -200.13, 1.19572, 300, 0, 0, 12600, 0, 0, 0, 0, 0),
(@GUID+4, 29866, 1, 1, 1, 0, 137, -8744.24, -4429.12, -201.256, 2.81882, 300, 0, 0, 3531, 0, 0, 0, 0, 0),
(@GUID+5, 29865, 1, 1, 1, 0, 156, -8747.09, -4428.11, -201.435, 5.94863, 300, 0, 0, 3531, 0, 0, 0, 0, 0),
(@GUID+6, 29866, 1, 1, 1, 0, 137, -8724.54, -4413.74, -203.767, 3.62588, 300, 0, 0, 3531, 0, 0, 0, 0, 0),
(@GUID+7, 29868, 1, 1, 1, 0, 0, -8706.49, -4416.54, -205.253, 5.47549, 300, 0, 0, 3531, 0, 0, 0, 0, 0),
(@GUID+8, 29873, 1, 1, 1, 0, 0, -8705.25, -4417.8, -205.359, 2.35353, 300, 0, 0, 0, 0, 0, 0, 0, 0),
(@GUID+9, 29867, 1, 1, 1, 0, 223, -8678.94, -4405.42, -206.604, 4.67847, 300, 0, 0, 12600, 0, 0, 0, 0, 0),
(@CGUID+10, 29865, 1, 1, 1, 0, 156, -8677.68, -4406.18, -206.761, 3.79995, 300, 0, 0, 3653, 0, 0, 0, 0, 0),
(@CGUID+11, 29865, 1, 1, 1, 0, 156, -8658.8, -4406.01, -207.526, 2.87632, 300, 0, 0, 3531, 0, 0, 0, 0, 0),
(@CGUID+12, 29866, 1, 1, 1, 0, 137, -8661.05, -4405.67, -207.493, 6.18285, 300, 0, 0, 3531, 0, 0, 0, 0, 0),
(@CGUID+13, 29865, 1, 1, 1, 0, 156, -8657.57, -4389.86, -207.489, 2.36738, 300, 0, 0, 3531, 0, 0, 0, 0, 0),
(@CGUID+14, 29866, 1, 1, 1, 0, 137, -8661.62, -4383.08, -207.057, 5.6582, 300, 0, 0, 3531, 0, 0, 0, 0, 0),
(@CGUID+15, 29868, 1, 1, 1, 0, 0, -8660.82, -4381.98, -207.073, 5.98022, 300, 0, 0, 3531, 0, 0, 0, 0, 0),
(@CGUID+16, 29867, 1, 1, 1, 0, 223, -8629.98, -4401.46, -208.522, 0.689765, 300, 0, 0, 12600, 0, 0, 0, 0, 0),
(@CGUID+17, 29867, 1, 1, 1, 0, 223, -8628.68, -4398.57, -208.695, 2.88103, 300, 0, 0, 12600, 0, 0, 0, 0, 0),
(@CGUID+18, 29867, 1, 1, 1, 0, 223, -8645.17, -4371.26, -208.266, 0.367751, 300, 0, 0, 12600, 0, 0, 0, 0, 0),
(@CGUID+19, 29866, 1, 1, 1, 0, 137, -8642.55, -4358.22, -208.326, 4.2916, 300, 0, 0, 3531, 0, 0, 0, 0, 0),
(@CGUID+20, 29866, 1, 1, 1, 0, 137, -8641.53, -4352.06, -208.29, 2.94779, 300, 0, 0, 3531, 0, 0, 0, 0, 0),
(@CGUID+21, 29865, 1, 1, 1, 0, 156, -8643.85, -4351.69, -208.181, 6.10744, 300, 0, 0, 3653, 0, 0, 0, 0, 0),
(@CGUID+22, 29865, 1, 1, 1, 0, 156, -8613.97, -4414.2, -209.195, 0.973981, 300, 0, 0, 3531, 0, 0, 0, 0, 0),
(@CGUID+23, 29866, 1, 1, 1, 0, 137, -8611.55, -4410.65, -209.502, 4.10772, 300, 0, 0, 3653, 0, 0, 0, 0, 0),
(@CGUID+24, 29868, 1, 1, 1, 0, 0, -8613.18, -4409.98, -209.398, 4.54754, 300, 0, 0, 3531, 0, 0, 0, 0, 0),
(@CGUID+25, 29868, 1, 1, 1, 0, 0, -8610.84, -4411.64, -209.52, 3.83283, 300, 0, 0, 3531, 0, 0, 0, 0, 0),
(@CGUID+26, 29868, 1, 1, 1, 0, 0, -8610.26, -4412.41, -209.533, 3.62863, 300, 0, 0, 3531, 0, 0, 0, 0, 0);

-- Doodad_InstancePortal_Purqq
DELETE FROM `gameobject` WHERE `guid`=17455 LIMIT 1;

-- Custodian of Time
DELETE FROM `creature` WHERE `guid` IN (24361, 23460);

-- Lordaeron Footman Specimen mounts (Swift Brown Steed)
DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+2, @CGUID+3, @CGUID+17);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID+2, 0, 14561, 0, 0, 0, ''),
(@CGUID+3, 0, 14561, 0, 0, 0, ''),
(@CGUID+17, 0, 14561, 0, 0, 0, '');

-- Stratholme Child Specimen, Stratholme Resident Specimen, Lordaeron Footman Specimen, Stratholme Citizen Specimen, Cat Specimen Aura fixes
DELETE FROM `creature_template_addon` WHERE `entry` IN (29868, 29866, 29867, 29865, 29873);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(29868, 0, 0, 0, 0, 0, '34712'),
(29866, 0, 0, 0, 0, 0, '34712'),
(29867, 0, 0, 0, 0, 0, '34712'),
(29865, 0, 0, 0, 0, 0, '34712'),
(29873, 0, 0, 0, 0, 0, '34712');

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


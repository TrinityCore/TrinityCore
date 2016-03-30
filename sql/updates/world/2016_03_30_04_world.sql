-- 
UPDATE `creature` SET `spawnMask`=3,`PhaseId`=0 WHERE `map`=33;
UPDATE `gameobject` SET `spawnMask`=3,`PhaseId`=0 WHERE `map`=33;

-- Baron Ashbury
UPDATE `creature_template` SET `difficulty_entry_1`=49708 WHERE `entry`=46962;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `exp`=3, `faction`=16, `speed_run`=1.42857, `BaseAttackTime`=1500, `unit_class`=2, `unit_flags`=32832, `VehicleId`=1422 WHERE `entry`=49708;

-- Baron Silverlaine

UPDATE `creature_template` SET `difficulty_entry_1`=49709 WHERE `entry`=3887;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `exp`=3, `faction`=16, `speed_run`=1.42857, `unit_flags`=32832, `DamageModifier`=1.7, `mechanic_immune_mask`=8388624 WHERE `entry`=49709;

-- Odo the Blindwatcher (Spawned by Baron Silverlaine)
UPDATE `creature_template` SET `difficulty_entry_1`=51086 WHERE `entry`=50857;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `exp`=3,`faction`=24 WHERE `entry`=51086;

-- Razorclaw the Butcher (Spawned by Baron Silverlaine)
UPDATE `creature_template` SET `difficulty_entry_1`=51034 WHERE `entry`=50869;
UPDATE `creature_template` SET `minlevel`=87,`maxlevel`=87,`exp`=3,`faction`=24 WHERE `entry`=51034;

-- Rethilgore (Spawned by Baron Silverlaine)
UPDATE `creature_template` SET `difficulty_entry_1`=50835 WHERE `entry`=50834;
UPDATE `creature_template` SET `minlevel`=87,`maxlevel`=87,`exp`=3,`faction`=16 WHERE `entry`=50835;

-- Worlf Master Nandos (Spawned by Baron Silverlaine)
UPDATE `creature_template` SET `difficulty_entry_1`=50852 WHERE `entry`=50851;
UPDATE `creature_template` SET `minlevel`=87,`maxlevel`=87,`exp`=3,`faction`=16 WHERE `entry`=50852;

-- Commander Springvale
UPDATE `creature_template` SET `difficulty_entry_1`=49710 WHERE `entry`=4278;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87, `exp`=3, `faction`=16, `speed_run`=1.42857, `unit_class`=2, `unit_flags`=32832, `MovementType`=1, `DamageModifier`=1.7,`mechanic_immune_mask`=8388624 WHERE `entry`=49710;

-- Tormented Officer (Spawned by Commander Springvale)
UPDATE `creature_template` SET `difficulty_entry_1`=50616, `AIName`='SmartAI' WHERE `entry`=50615;
UPDATE `creature_template` SET `minlevel`=85,`maxlevel`=85,`exp`=3,`faction`=16,`unit_flags`=32768,`HealthModifier`=4 WHERE `entry`=50616;

-- Wailing Guardsman (Spawned by Commander Springvale)
UPDATE `creature_template` SET `difficulty_entry_1`=50614, `AIName`='SmartAI' WHERE `entry`=50613;
UPDATE `creature_template` SET `minlevel`=85,`maxlevel`=85,`exp`=3,`faction`=24,`unit_flags`=32768 WHERE `entry`=50614;

-- Lord Warden
UPDATE `creature_template` SET `difficulty_entry_1`=49711 WHERE `entry`=46963;
UPDATE `creature_template` SET `minlevel`=87,`maxlevel`=87,`exp`=3,`faction`=16,`speed_run`=1.42857,`unit_class`=2,`unit_flags`=32832 WHERE `entry`=49711;

-- Lord Godfrey
UPDATE `creature_template` SET `difficulty_entry_1`=49712 WHERE `entry`=46964;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87,`exp`=3,`faction`=16,`speed_run`=1.42857,`unit_class`=2 WHERE `entry`=49712;

-- Bloodthirsty Ghoul (Spawned by Lord Godfrey)
UPDATE `creature_template` SET `difficulty_entry_1`=50562 WHERE `entry`=50561;
UPDATE `creature_template` SET `minlevel`=87,`maxlevel`=87,`exp`=3,`faction`=24,`HealthModifier`=0.206612 WHERE `entry`=50562;

-- Lupine Spectre
UPDATE `creature_template` SET `difficulty_entry_1`=50924 WHERE `entry`=50923;
UPDATE `creature_template` SET `minlevel`=87, `maxlevel`=87,`exp`=3,`unit_flags`=32768,`faction`=16,`speed_run`=1.42857,`unit_class`=1, `mechanic_immune_mask`=8388624, `DamageModifier`=35 WHERE `entry`=50924;

-- Haunting Spirit
UPDATE `creature_template` SET `difficulty_entry_1`=48963 WHERE `entry`=4958;
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85,`exp`=3,`unit_flags`=64,`faction`=16,`speed_run`=1.14286,`unit_class`=1, `mechanic_immune_mask`=8388624, `DamageModifier`=7 WHERE `entry`=48963;

UPDATE `creature` SET `MovementType`=1, `spawndist`=5 WHERE `id` IN (3875, 47134,47131);

-- Fel Steed - Shadow Charger
UPDATE `creature_template` SET `difficulty_entry_1`=48968 WHERE `entry`=3864;
UPDATE `creature_template` SET `difficulty_entry_1`=48967 WHERE `entry`=3865;
UPDATE `creature_template` SET `minlevel`=85,`maxlevel`=85,`exp`=3,`faction`=15,`speed_run`=1.28571,`unit_class`=1, `DamageModifier`=83.8 WHERE `entry`=48968;
UPDATE `creature_template` SET `minlevel`=85,`maxlevel`=85,`exp`=3,`faction`=15,`speed_run`=1.28571,`unit_class`=1, `DamageModifier`=45.3 WHERE `entry`=48967;
UPDATE `creature_template` SET `unit_flags`=67141696 WHERE `entry` IN (3865, 3864, 48968, 48967);

UPDATE `creature` SET `equipment_id`=1 WHERE `id` IN (3877,3873,50613,50615,4278, 47145, 47146, 47232, 51400, 47030, 47293, 47031, 47294);

UPDATE `creature` SET `position_z`=137.55 WHERE `guid`=371262;
UPDATE `gameobject` SET `state`=0 WHERE `id` IN (18900,18901,101811);

DELETE FROM `creature` WHERE `id` IN (50604);

DELETE FROM `creature` WHERE `guid` IN (370941, 371272, 375667);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(370941, 47138, 33, 0, 0, 3, 0, 0, 0, 0, -96.3948, 2148.41, 144.921, 0.964458, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(371272, 47138, 33, 0, 0, 3, 0, 0, 0, 0, -91.8943, 2129.37, 144.921, 3.82676, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(375667, 3872, 33, 0, 0, 1, 0, 0, 0, 0, -192.012, 2124.54, 97.3899, 4.29002, 3600, 0, 0, 0, 0, 0, 0, 0, 0, 0);

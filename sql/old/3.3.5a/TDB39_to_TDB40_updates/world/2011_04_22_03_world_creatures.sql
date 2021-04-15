-- Biohazard
DELETE FROM `creature` WHERE `id`=21789; -- Nakansi / Shadowmoon Valley
INSERT INTO creature (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`) VALUES
(152259,21789,530,1,1,0,0,-2741.8,2719.07,123.584,0.603481,600,0,0,34930,0,0,0);

-- Tome
DELETE FROM `gameobject` WHERE `id`=187987; -- South Point Station Valve
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(151895,187987,571,1,1,3791.704,4808.966,-11.5618,1.483528,0,0,0.6755896,0.7372779,0,0,0);

-- Nay
UPDATE `creature_template` SET /*`npcflag`=`npcflag`|16777216,*/`speed_walk`=2.8 WHERE `entry`=30123; -- Snorri needs spellclick data
-- UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216 WHERE `entry`=30272; -- Njorndar Proto-Drake needs spellclick data
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|32768,`speed_walk`=1.444444 WHERE `entry`=30500; -- Argent Skytalon
UPDATE `creature_template` SET `speed_walk`=1.444444 WHERE `entry`=31070; -- Argent Skytalon
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`speed_walk`=1.2 WHERE `entry`=32370; -- Refurbished Demolisher
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`unit_flags`=`unit_flags`|8,`speed_walk`=1.2,`vehicleid`=512 WHERE `entry`=31830; -- Refurbished Demolisher
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`speed_run`=1.3857142857143 WHERE `entry`=34125; -- Stabled Campaign Warhorse
UPDATE `creature_template` SET `baseattacktime`=2000,`unit_flags`=`unit_flags`|16400,`unit_class`=4,`speed_run`=1 WHERE `entry` IN (36839,35427); -- Horde Gunship Cannon, Horde Gunship Cannon (1)
UPDATE `creature_template` SET `baseattacktime`=2000,/*`npcflag`=`npcflag`|16777216,*/`speed_run`=1.1428571428571 WHERE `entry`=37945; -- Dream Portal needs spellclick data
UPDATE `creature_template` SET `exp`=2,`minlevel`=80,`maxlevel`=80,`baseattacktime`=2000,/*`npcflag`=`npcflag`|16777216,*/`speed_run`=1.1428571428571 WHERE `entry`=38186; -- Dream Portal (Pre-effect)  needs spellclick data

UPDATE `creature_model_info` SET `bounding_radius`=3,`combat_reach`=2.25,`gender`=2 WHERE `modelid`=25092; -- Refurbished Demolisher
UPDATE `creature_model_info` SET `bounding_radius`=0.248,`combat_reach`=4.8,`gender`=0 WHERE `modelid`=26772; -- Snorri
UPDATE `creature_model_info` SET `bounding_radius`=1.085,`combat_reach`=3.5,`gender`=2 WHERE `modelid`=27703; -- Geargrinder's Jumpbot
UPDATE `creature_model_info` SET `bounding_radius`=3,`combat_reach`=2.25,`gender`=2 WHERE `modelid`=25092; -- Refurbished Demolisher
UPDATE `creature_model_info` SET `bounding_radius`=1.9,`combat_reach`=0,`gender`=2 WHERE `modelid`=29489; -- Horde Gunship Cannon
UPDATE `creature_model_info` SET `bounding_radius`=0.5,`combat_reach`=1,`gender`=2 WHERE `modelid`=30844; -- Dream Portal
UPDATE `creature_model_info` SET `bounding_radius`=0.5,`combat_reach`=1,`gender`=2 WHERE `modelid`=30844; -- Dream Portal (Pre-effect)

DELETE FROM `creature_template_addon` WHERE `entry` IN (30123,30272,31070,31736,31770,32370,31830,36839,37945,38186);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(30123,0,0,1,0, '61208 0'), -- Snorri; Aura: Fjorn's Anvil - Quest Invisibility 3
(30272,0,0,1,0, NULL), -- Njorndar Proto-Drake
(31070,0,0,1,0, NULL), -- Argent Skytalon
(31736,0,0,1,0, NULL), -- Geargrinder's Jumpbot
(31770,0,0,1,0, NULL), -- Thunderbomb's Jumpbot
(32370,0,65536,1,0, '49414 0'), -- Refurbished Demolisher; Auras: Generic Quest Invisibility 1
(31830,0,0,1,0, NULL), -- Refurbished Demolisher
(36839,0,0,1,0, '69470 0 69470 1'), -- Horde Gunship Cannon; Aura: Heat Drain
(37945,0,0,1,0, NULL), -- Dream Portal
(38186,0,0,1,0, NULL); -- Dream Portal (Pre-effect)

UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=176966; -- Portcullis
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=176964; -- Portcullis
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=179117; -- Portcullis
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=179116; -- Portcullis
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=179115; -- Portcullis
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=179148; -- Lever
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=179365; -- Portcullis
UPDATE `gameobject_template_addon` SET `faction`=14 WHERE `entry`=179784; -- Suppression Device
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=179364; -- Portcullis

DELETE FROM `quest_details` WHERE `ID`=7783;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7783, 0, 0, 0, 0, 0, 0, 0, 0, 41031); -- The Lord of Blackrock

UPDATE `creature_template` SET `minlevel`=33, `maxlevel`=33 WHERE `entry`=11583; -- Nefarian
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `unit_flags`=33555200 WHERE `entry`=14311; -- Bronze Drakonid Spawner
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `speed_walk`=1, `speed_run`=1.142857193946838378 WHERE `entry`=14309; -- Red Drakonid Spawner
UPDATE `creature_template` SET `gossip_menu_id`=6045, `minlevel`=30, `maxlevel`=30 WHERE `entry`=10162; -- Lord Victor Nefarius
UPDATE `creature_template` SET `minlevel`=32, `maxlevel`=32 WHERE `entry`=12557; -- Grethok the Controller
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=14449; -- Blackwing Orb Trigger
UPDATE `creature_template` SET `minlevel`=33, `maxlevel`=33, `speed_walk`=1 WHERE `entry`=12435; -- Razorgore the Untamed
UPDATE `creature_template` SET `minlevel`=33, `maxlevel`=33 WHERE `entry`=12017; -- Broodlord Lashlayer
UPDATE `creature_template` SET `minlevel`=33, `maxlevel`=33 WHERE `entry`=11983; -- Firemaw
UPDATE `creature_template` SET `minlevel`=32, `maxlevel`=32, `speed_walk`=1 WHERE `entry`=12464; -- Death Talon Seether
UPDATE `creature_template` SET `minlevel`=33, `maxlevel`=33 WHERE `entry`=11981; -- Flamegor
UPDATE `creature_template` SET `gossip_menu_id`=6101, `minlevel`=33, `maxlevel`=33 WHERE `entry`=13020; -- Vaelastrasz the Corrupt
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=14459; -- Nefarian's Troops
UPDATE `creature_template` SET `minlevel`=31, `maxlevel`=31 WHERE `entry`=14456; -- Blackwing Guardsman
UPDATE `creature_template` SET `minlevel`=33, `maxlevel`=33 WHERE `entry`=14020; -- Chromaggus
UPDATE `creature_template` SET `minlevel`=31, `maxlevel`=31, `speed_walk`=1 WHERE `entry`=12465; -- Death Talon Wyrmkin
UPDATE `creature_template` SET `minlevel`=32, `maxlevel`=32, `speed_walk`=1 WHERE `entry`=12463; -- Death Talon Flamescale
UPDATE `creature_template` SET `minlevel`=33, `maxlevel`=33 WHERE `entry`=14601; -- Ebonroc
UPDATE `creature_template` SET `minlevel`=32, `maxlevel`=32 WHERE `entry`=12461; -- Death Talon Overseer
UPDATE `creature_template` SET `minlevel`=32, `maxlevel`=32 WHERE `entry`=12458; -- Blackwing Taskmaster
UPDATE `creature_template` SET `minlevel`=33, `maxlevel`=33 WHERE `entry`=12460; -- Death Talon Wyrmguard
UPDATE `creature_template` SET `minlevel`=31, `maxlevel`=31, `speed_walk`=1 WHERE `entry`=12468; -- Death Talon Hatcher
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=13976; -- Tortured Drake
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `speed_walk`=1 WHERE `entry`=14025; -- Corrupted Bronze Whelp
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `speed_walk`=1 WHERE `entry`=14022; -- Corrupted Red Whelp
UPDATE `creature_template` SET `minlevel`=32, `maxlevel`=32 WHERE `entry`=12457; -- Blackwing Spellbinder
UPDATE `creature_template` SET `minlevel`=31, `maxlevel`=31 WHERE `entry`=12459; -- Blackwing Warlock
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=16604; -- Blackwing Spell Marker
UPDATE `creature_template` SET `minlevel`=32, `maxlevel`=32 WHERE `entry`=12467; -- Death Talon Captain
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=14401; -- Master Elemental Shaper Krixix
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=13996; -- Blackwing Technician
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `speed_walk`=1 WHERE `entry`=14023; -- Corrupted Green Whelp
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `speed_walk`=1 WHERE `entry`=14024; -- Corrupted Blue Whelp

UPDATE `creature_model_info` SET `BoundingRadius`=0.458999991416931152, `CombatReach`=2.25, `VerifiedBuild`=41031 WHERE `DisplayID`=9472;
UPDATE `creature_model_info` SET `BoundingRadius`=5.203492164611816406, `VerifiedBuild`=41031 WHERE `DisplayID`=10115;
UPDATE `creature_model_info` SET `BoundingRadius`=3.659917831420898437, `VerifiedBuild`=41031 WHERE `DisplayID`=12893;
UPDATE `creature_model_info` SET `BoundingRadius`=0.446400016546249389, `CombatReach`=1.80000007152557373, `VerifiedBuild`=41031 WHERE `DisplayID`=12024;
UPDATE `creature_model_info` SET `BoundingRadius`=1.049999952316284179, `CombatReach`=12, `VerifiedBuild`=41031 WHERE `DisplayID`=14367;
UPDATE `creature_model_info` SET `BoundingRadius`=2.86570143699645996, `VerifiedBuild`=41031 WHERE `DisplayID`=12894;
UPDATE `creature_model_info` SET `BoundingRadius`=3.343318462371826171, `VerifiedBuild`=41031 WHERE `DisplayID`=12892;

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=9 AND `Entry` IN (11583,14311,14309,10162,12557,14449,12435,12017,11983,12464,11981,13020,14459,14456,14020,12465,12463,14601,12461,12999,12458,12460,12468,13976,14025,14022,12457,12459,16604,12467,14401,13996,14023,14024));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(11583, 9, 3, 3, 1005, 41031),
(14311, 9, 0, 0, 1005, 41031),
(14309, 9, 0, 0, 1005, 41031),
(10162, 9, 0, 0, 205, 41031),
(12557, 9, 2, 2, 1005, 41031),
(14449, 9, 0, 0, 1005, 41031),
(12435, 9, 3, 3, 1005, 41031),
(12017, 9, 3, 3, 1005, 41031),
(11983, 9, 3, 3, 1005, 41031),
(12464, 9, 2, 2, 1005, 41031),
(11981, 9, 3, 3, 1005, 41031),
(13020, 9, 3, 3, 1005, 41031),
(14459, 9, 0, 0, 1005, 41031),
(14456, 9, 1, 1, 1005, 41031),
(14020, 9, 3, 3, 1005, 41031),
(12465, 9, 1, 1, 1005, 41031),
(12463, 9, 2, 2, 1005, 41031),
(14601, 9, 3, 3, 1005, 41031),
(12461, 9, 2, 2, 1005, 41031),
(12999, 9, 0, 0, 328, 41031),
(12458, 9, 2, 2, 1005, 41031),
(12460, 9, 3, 3, 1005, 41031),
(12468, 9, 1, 1, 1005, 41031),
(13976, 9, 0, 0, 1005, 41031),
(14025, 9, 0, 0, 1005, 41031),
(14022, 9, 0, 0, 1005, 41031),
(12457, 9, 2, 2, 1005, 41031),
(12459, 9, 1, 1, 1005, 41031),
(16604, 9, 0, 0, 1005, 41031),
(12467, 9, 2, 2, 1005, 41031),
(14401, 9, 0, 0, 1005, 41031),
(13996, 9, 0, 0, 1005, 41031),
(14023, 9, 0, 0, 1005, 41031),
(14024, 9, 0, 0, 1005, 41031);

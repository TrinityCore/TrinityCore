-- Template updates
UPDATE `creature_template` SET `dynamicflags`=`dynamicflags`&~8 WHERE `entry`=33059; -- Wrecked Demolisher
UPDATE `creature_template` SET `exp`=0 WHERE `entry`=33666; -- Demolisher Engineer Blastwrench
UPDATE `creature_template` SET `dynamicflags`=`dynamicflags`&~8 WHERE `entry`=33063; -- Wrecked Siege Engine
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216 WHERE `entry`=33067; -- Salvaged Siege Turret
UPDATE `creature_template` SET `VehicleId`=387 WHERE `entry`=33113; -- Flame Leviathan
UPDATE `creature_template` SET `exp`=0 WHERE `entry`=33143; -- Overload Control Device
UPDATE `creature_template` SET `exp`=0,`npcflag`=`npcflag`|16777216,`unit_flags`=`unit_flags`|33571584 WHERE `entry`=33139; -- Flame Leviathan Turret
UPDATE `creature_template` SET `dynamicflags`=`dynamicflags`|12 WHERE `entry`=33216; -- Mechagnome Pilot
UPDATE `creature_template` SET `dynamicflags`=`dynamicflags`|12 WHERE `entry`=33572; -- Steelforged Defender
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33280 WHERE `entry`=33186; -- Razorscale
UPDATE `creature_template` SET `speed_run`=2.14286 WHERE `entry`=34120; -- Brann's Flying Machine
UPDATE `creature_template` SET `speed_walk`=1.6,`speed_run`=1.42857 WHERE `entry`=33118; -- Ignis the Furnace Master
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33554688 WHERE `entry`=33121; -- Iron Construct

-- Model data
UPDATE `creature_model_info` SET `bounding_radius`=5,`combat_reach`=1,`gender`=2 WHERE `modelid`=25870; -- Salvaged Chopper
UPDATE `creature_model_info` SET `bounding_radius`=0.6,`combat_reach`=1,`gender`=1 WHERE `modelid`=28787; -- Razorscale
UPDATE `creature_model_info` SET `bounding_radius`=0.62,`combat_reach`=1,`gender`=0 WHERE `modelid`=29185; -- Ignis the Furnace Master

-- Addon data
DELETE FROM `creature_template_addon` WHERE `entry` IN (33114,33142,33143,33139,33189,33216,33572,33090,33186,33287,33259,34120,
23033,34086,33118,33210,33121,34085,33816);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(33114,0,0,257,0, NULL), -- Flame Leviathan Seat
(33142,0,0,1,0, NULL), -- Leviathan Defense Turret
(33143,0,0,1,0, NULL), -- Overload Control Device
(33139,0,0,1,0, NULL), -- Flame Leviathan Turret
(33189,0,0,1,0, NULL), -- Liquid Pyrite
(33216,0,0,1,0, NULL), -- Mechagnome Pilot
(33572,0,0,1,0, NULL), -- Steelforged Defender
(33090,0,0,1,0, NULL),-- Pool of Tar
(33186,0,50331648,1,0, NULL), -- Razorscale
(33816,0,0,1,375, NULL), -- Expedition Defender
(33287,0,0,1,0, NULL), -- Expedition Engineer
(33259,0,0,1,375, NULL), -- Expedition Trapper
(34120,0,50331648,1,0, NULL), -- Brann's Flying Machine
(23033,0,0,1,0, NULL), -- Invisible Stalker (Floating)
(34086,0,33554432,1,0, NULL), -- Magma Rager
(33118,0,0,1,0, NULL), -- Ignis the Furnace Master
(33210,0,0,1,0, NULL), -- Expedition Commander
(33121,0,0,1,0, NULL), -- Iron Construct
(34085,0,0,1,0, NULL); -- Forge Construct

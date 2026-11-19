-- Template updates for creature 4075 (Rat)
UPDATE `creature_template` SET `faction_A`=31,`faction_H`=31,`baseattacktime`=2000,`speed_run`=0.85714 WHERE `entry`=4075; -- Rat
-- Model data 1141 (creature 4075 (Rat))
UPDATE `creature_model_info` SET `bounding_radius`=1,`combat_reach`=1,`gender`=2 WHERE `modelid`=1141; -- Rat
-- Addon data for creature 4075 (Rat)
DELETE FROM `creature_template_addon` WHERE `entry`=4075;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(4075,0,0,1,0, NULL); -- Rat

-- Template updates for creature 6368 (Cat)
UPDATE `creature_template` SET `faction_A`=188,`faction_H`=188,`baseattacktime`=2000,`speed_run`=0.85714 WHERE `entry`=6368; -- Cat
-- Model data 5585 (creature 6368 (Cat))
UPDATE `creature_model_info` SET `bounding_radius`=0.25,`combat_reach`=0.5,`gender`=2 WHERE `modelid`=5585; -- Cat
-- Addon data for creature 6368 (Cat)
DELETE FROM `creature_template_addon` WHERE `entry`=6368;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(6368,0,3,1,0, NULL); -- Cat

SET @EquiEntry = 1; -- (creature_equip_template.entry - need 1)
-- Template updates for creature 34850 (Prince Liam Greymane)
UPDATE `creature_template` SET `faction_A`=2163,`faction_H`=2163,`minlevel`=5,`maxlevel`=5,`baseattacktime`=2000,`npcflag`=`npcflag`|3,`unit_flags`=`unit_flags`|32768,`equipment_id`=@EquiEntry,`unit_class`=2,`speed_run`=1.38571 WHERE `entry`=34850; -- Prince Liam Greymane
-- Equipment of 34850 (Prince Liam Greymane)
DELETE FROM `creature_equip_template` WHERE `entry`=@EquiEntry;
INSERT INTO `creature_equip_template` (`entry`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(@EquiEntry,3364,0,0);
-- Model data 29463 (creature 34850 (Prince Liam Greymane))
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=29463; -- Prince Liam Greymane
-- Addon data for creature 34850 (Prince Liam Greymane)
DELETE FROM `creature_template_addon` WHERE `entry`=34850;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(34850,2410,0,1,0, NULL); -- Prince Liam Greymane

-- Template updates for creature 34851 (Panicked Citizen)
UPDATE `creature_template` SET `faction_A`=2163,`faction_H`=2163,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33024 WHERE `entry`=34851; -- Panicked Citizen
-- Model data 30217 (creature 34851 (Panicked Citizen))
UPDATE `creature_model_info` SET `bounding_radius`=0.208,`combat_reach`=1.5,`gender`=1 WHERE `modelid`=30217; -- Panicked Citizen
-- Addon data for creature 34851 (Panicked Citizen)
DELETE FROM `creature_template_addon` WHERE `entry`=34851;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(34851,0,0,1,0, NULL); -- Panicked Citizen

-- Template updates for creature 34863 (Lieutenant Walden)
UPDATE `creature_template` SET `faction_A`=2163,`faction_H`=2163,`minlevel`=3,`maxlevel`=3,`baseattacktime`=2000,`npcflag`=`npcflag`|2,`unit_flags`=`unit_flags`|537165824,`dynamicflags`=`dynamicflags`|32,`unit_class`=2 WHERE `entry`=34863; -- Lieutenant Walden
-- Model data 29476 (creature 34863 (Lieutenant Walden))
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=29476; -- Lieutenant Walden
-- Addon data for creature 34863 (Lieutenant Walden)
DELETE FROM `creature_template_addon` WHERE `entry`=34863;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(34863,0,0,1,0, NULL); -- Lieutenant Walden
 
SET @EquiEntry = 2; -- (creature_equip_template.entry - need 1)
-- Template updates for creature 34864 (Gilneas City Guard)
UPDATE `creature_template` SET `faction_A`=2163,`faction_H`=2163,`minlevel`=3,`maxlevel`=3,`baseattacktime`=2000,`unit_flags`=`unit_flags`|32768,`equipment_id`=@EquiEntry,`unit_class`=2,`speed_run`=1.38571 WHERE `entry`=34864; -- Gilneas City Guard
-- Equipment of 34864 (Gilneas City Guard)
DELETE FROM `creature_equip_template` WHERE `entry`=@EquiEntry;
INSERT INTO `creature_equip_template` (`entry`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(@EquiEntry,5305,0,0);
-- Model data 29467 (creature 34864 (Gilneas City Guard))
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=29467; -- Gilneas City Guard
-- Addon data for creature 34864 (Gilneas City Guard)
DELETE FROM `creature_template_addon` WHERE `entry`=34864;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(34864,0,0,1,0, NULL); -- Gilneas City Guard
 
-- Template updates for creature 34867 (Shadowy Figure)
UPDATE `creature_template` SET `baseattacktime`=2000,`unit_flags`=`unit_flags`|33587456,`unit_class`=2 WHERE `entry`=34867; -- Shadowy Figure
-- Model data 36770 (creature 34867 (Shadowy Figure))
UPDATE `creature_model_info` SET `bounding_radius`=0.347222,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=36770; -- Shadowy Figure
-- Addon data for creature 34867 (Shadowy Figure)
DELETE FROM `creature_template_addon` WHERE `entry`=34867;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(34867,0,8,1,0, NULL); -- Shadowy Figure

-- Template updates for creature 35006 (Gilneas Market Evacuation Credit)
UPDATE `creature_template` SET `faction_A`=114,`faction_H`=114,`minlevel`=60,`maxlevel`=60,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33555200 WHERE `entry`=35006; -- Gilneas Market Evacuation Credit
-- Model data 17612 (creature 35006 (Gilneas Market Evacuation Credit))
UPDATE `creature_model_info` SET `bounding_radius`=0.75,`combat_reach`=1.5,`gender`=2 WHERE `modelid`=17612; -- Gilneas Market Evacuation Credit
-- Addon data for creature 35006 (Gilneas Market Evacuation Credit)
DELETE FROM `creature_template_addon` WHERE `entry`=35006;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(35006,0,0,1,0, NULL); -- Gilneas Market Evacuation Credit

-- Template updates for creature 35010 (Gilneas Evacuation Facing Marker (Near))
UPDATE `creature_template` SET `faction_A`=114,`faction_H`=114,`minlevel`=60,`maxlevel`=60,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33555200 WHERE `entry`=35010; -- Gilneas Evacuation Facing Marker (Near)
-- Model data 17612 (creature 35010 (Gilneas Evacuation Facing Marker (Near)))
UPDATE `creature_model_info` SET `bounding_radius`=0.75,`combat_reach`=1.5,`gender`=2 WHERE `modelid`=17612; -- Gilneas Evacuation Facing Marker (Near)
-- Addon data for creature 35010 (Gilneas Evacuation Facing Marker (Near))
DELETE FROM `creature_template_addon` WHERE `entry`=35010;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(35010,0,0,1,0, NULL); -- Gilneas Evacuation Facing Marker (Near)

-- Template updates for creature 35011 (Gilneas Evacuation Facing Marker (Far))
UPDATE `creature_template` SET `faction_A`=114,`faction_H`=114,`minlevel`=60,`maxlevel`=60,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33555200 WHERE `entry`=35011; -- Gilneas Evacuation Facing Marker (Far)
-- Model data 17612 (creature 35011 (Gilneas Evacuation Facing Marker (Far)))
UPDATE `creature_model_info` SET `bounding_radius`=0.75,`combat_reach`=1.5,`gender`=2 WHERE `modelid`=17612; -- Gilneas Evacuation Facing Marker (Far)
-- Addon data for creature 35011 (Gilneas Evacuation Facing Marker (Far))
DELETE FROM `creature_template_addon` WHERE `entry`=35011;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(35011,0,0,1,0, NULL); -- Gilneas Evacuation Facing Marker (Far)

 
-- Template updates for creature 35317 (Rebel Cannon)
UPDATE `creature_template` SET `minlevel`=5,`maxlevel`=5,`baseattacktime`=2000,`unit_class`=2,`speed_run`=1 WHERE `entry`=35317; -- Rebel Cannon
-- Model data 29757 (creature 35317 (Rebel Cannon))
UPDATE `creature_model_info` SET `bounding_radius`=0.217,`combat_reach`=0.7,`gender`=2 WHERE `modelid`=29757; -- Rebel Cannon
-- Addon data for creature 35317 (Rebel Cannon)
DELETE FROM `creature_template_addon` WHERE `entry`=35317;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(35317,0,0,1,0, NULL); -- Rebel Cannon
 
-- Template updates for creature 35374 (Generic Trigger LAB - Multiphase)
UPDATE `creature_template` SET `minlevel`=60,`maxlevel`=60,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33554688 WHERE `entry`=35374; -- Generic Trigger LAB - Multiphase
-- Model data 11686 (creature 35374 (Generic Trigger LAB - Multiphase))
UPDATE `creature_model_info` SET `bounding_radius`=0.5,`combat_reach`=1,`gender`=2 WHERE `modelid`=11686; -- Generic Trigger LAB - Multiphase
-- Addon data for creature 35374 (Generic Trigger LAB - Multiphase)
DELETE FROM `creature_template_addon` WHERE `entry`=35374;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(35374,0,0,1,0, NULL); -- Generic Trigger LAB - Multiphase
 
 -- Template updates for creature 35830 (Gilneas Evacuation Facing Marker (First))
UPDATE `creature_template` SET `faction_A`=114,`faction_H`=114,`minlevel`=60,`maxlevel`=60,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33555200 WHERE `entry`=35830; -- Gilneas Evacuation Facing Marker (First)
-- Model data 17612 (creature 35830 (Gilneas Evacuation Facing Marker (First)))
UPDATE `creature_model_info` SET `bounding_radius`=0.75,`combat_reach`=1.5,`gender`=2 WHERE `modelid`=17612; -- Gilneas Evacuation Facing Marker (First)
-- Addon data for creature 35830 (Gilneas Evacuation Facing Marker (First))
DELETE FROM `creature_template_addon` WHERE `entry`=35830;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(35830,0,0,1,0, NULL); -- Gilneas Evacuation Facing Marker (First)
 
SET @EquiEntry = 3; -- (creature_equip_template.entry - need 1)
-- Template updates for creature 39095 (Slain Guard)
UPDATE `creature_template` SET `faction_A`=2163,`faction_H`=2163,`minlevel`=3,`maxlevel`=3,`baseattacktime`=2000,`unit_flags`=`unit_flags`|537166592,`dynamicflags`=`dynamicflags`|32,`equipment_id`=@EquiEntry,`unit_class`=2 WHERE `entry`=39095; -- Slain Guard
-- Equipment of 39095 (Slain Guard)
DELETE FROM `creature_equip_template` WHERE `entry`=@EquiEntry;
INSERT INTO `creature_equip_template` (`entry`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(@EquiEntry,5305,0,0);
-- Model data 29466 (creature 39095 (Slain Guard))
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=29466; -- Slain Guard
-- Addon data for creature 39095 (Slain Guard)
DELETE FROM `creature_template_addon` WHERE `entry`=39095;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(39095,0,0,1,0, NULL); -- Slain Guard
 
-- Template updates for creature 44086 (Panicked Citizen)
UPDATE `creature_template` SET `faction_A`=2163,`faction_H`=2163,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33024 WHERE `entry`=44086; -- Panicked Citizen
-- Model data 30217 (creature 44086 (Panicked Citizen))
UPDATE `creature_model_info` SET `bounding_radius`=0.208,`combat_reach`=1.5,`gender`=1 WHERE `modelid`=30217; -- Panicked Citizen
-- Addon data for creature 44086 (Panicked Citizen)
DELETE FROM `creature_template_addon` WHERE `entry`=44086;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(44086,0,0,1,0, NULL); -- Panicked Citizen

-- Template updates for creature 44105 (Slain Citizen)
UPDATE `creature_template` SET `faction_A`=2163,`faction_H`=2163,`baseattacktime`=2000,`unit_flags`=`unit_flags`|537166080,`dynamicflags`=`dynamicflags`|32 WHERE `entry`=44105; -- Slain Citizen
-- Model data 30216 (creature 44105 (Slain Citizen))
UPDATE `creature_model_info` SET `bounding_radius`=0.3213,`combat_reach`=1.575,`gender`=0 WHERE `modelid`=30216; -- Slain Citizen
-- Addon data for creature 44105 (Slain Citizen)
DELETE FROM `creature_template_addon` WHERE `entry`=44105;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(44105,0,0,1,0, NULL); -- Slain Citizen

-- Template updates for creature 44426 (Frightened Chicken)
UPDATE `creature_template` SET `faction_A`=31,`faction_H`=31,`baseattacktime`=2000,`speed_run`=0.85714 WHERE `entry`=44426; -- Frightened Chicken
-- Model data 304 (creature 44426 (Frightened Chicken))
UPDATE `creature_model_info` SET `bounding_radius`=0.145,`combat_reach`=1,`gender`=2 WHERE `modelid`=304; -- Frightened Chicken
-- Addon data for creature 44426 (Frightened Chicken)
DELETE FROM `creature_template_addon` WHERE `entry`=44426;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(44426,0,0,1,0, NULL); -- Frightened Chicken

-- Template updates for creature 50260 (Gilnean Crow)
UPDATE `creature_template` SET `faction_A`=2136,`faction_H`=2136,`baseattacktime`=2000 WHERE `entry`=50260; -- Gilnean Crow
-- Model data 36743 (creature 50260 (Gilnean Crow))
UPDATE `creature_model_info` SET `bounding_radius`=0.155,`combat_reach`=0,`gender`=2 WHERE `modelid`=36743; -- Gilnean Crow
-- Addon data for creature 50260 (Gilnean Crow)
DELETE FROM `creature_template_addon` WHERE `entry`=50260;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(50260,0,50331649,1,0, NULL); -- Gilnean Crow


UPDATE `creature_template` SET `faction_A`=35,`faction_H`=35,`baseattacktime`=2000,`npcflag`=0x1000000,`unit_flags`=0x4000,`speed_run`=1,`VehicleId`=510 WHERE `entry`=34944; -- Keep Cannon (faction is set by core script A: 1732, H: 1735)
UPDATE `creature_template` SET `faction_A`=35,`faction_H`=35,`baseattacktime`=2000,`npcflag`=0x1000000,`unit_flags`=0x4000,`unit_class`=4 WHERE `entry`=34793; -- Catapult (faction is set by core script A: 1732, H: 1735)
UPDATE `creature_template` SET `faction_A`=1732,`faction_H`=1732,`baseattacktime`=2000,`npcflag`=0x1000000,`unit_flags`=0x2004000,`speed_run`=1 WHERE `entry`=34929; -- Alliance Gunship Cannon (core script should remove unselectable flag)
UPDATE `creature_template` SET `faction_A`=1735,`faction_H`=1735,`baseattacktime`=2000,`npcflag`=0x1000000,`unit_flags`=0x2004000,`speed_run`=1 WHERE `entry`=34935; -- Horde Gunship Cannon
UPDATE `creature_template` SET `baseattacktime`=2000,`unit_flags`=0x4000,`speed_walk`=3.2 WHERE `entry`=35273; -- Glaive Thrower
UPDATE `creature_template` SET `baseattacktime`=2000,`npcflag`=0x1000000,`unit_flags`=0x4000,`speed_walk`=1.2,`speed_run`=0.98571 WHERE `entry`=34775; -- Demolisher
UPDATE `creature_template` SET `baseattacktime`=2000,`unit_flags`=16640,`unit_class`=4,`speed_walk`=1.2,`speed_run`=1 WHERE `entry`=34776; -- Siege Engine
UPDATE `creature_template` SET `baseattacktime`=2000,`npcflag`=0x1000000,`unit_flags`=0x2004000,`unit_class`=4,`speed_walk`=1.2,`VehicleId`=436 WHERE `entry`=36355; -- Siege Turret
UPDATE `creature_template` SET `baseattacktime`=2000,`unit_flags`=16640,`unit_class`=4 WHERE `entry`=35069; -- Siege Engine
UPDATE `creature_template` SET `faction_A`=1732,`faction_H`=1732,`exp`=0,`minlevel`=70,`maxlevel`=70,`baseattacktime`=2000,`npcflag`=0x1000000,`unit_flags`=0x4000,`speed_walk`=3.2 WHERE `entry`=34802; -- Glaive Thrower

UPDATE `creature_model_info` SET `bounding_radius`=0.31,`combat_reach`=0,`gender`=2 WHERE `modelid`=29488; -- Alliance Gunship Cannon
UPDATE `creature_model_info` SET `bounding_radius`=1.9,`combat_reach`=0,`gender`=2 WHERE `modelid`=29489; -- Horde Gunship Cannon
UPDATE `creature_model_info` SET `bounding_radius`=1,`combat_reach`=7.7,`gender`=2 WHERE `modelid`=25292; -- Siege Engine
UPDATE `creature_model_info` SET `bounding_radius`=0.305,`combat_reach`=5,`gender`=2 WHERE `modelid`=28106; -- Siege Turret
UPDATE `creature_model_info` SET `bounding_radius`=1,`combat_reach`=7.7,`gender`=2 WHERE `modelid`=26403; -- Siege Engine
UPDATE `creature_model_info` SET `bounding_radius`=0.381875,`combat_reach`=1.25,`gender`=2 WHERE `modelid`=29734; -- Glaive Thrower
UPDATE `creature_model_info` SET `bounding_radius`=0.381875,`combat_reach`=1.25,`gender`=2 WHERE `modelid`=29642; -- Glaive Thrower

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (34929,35273,34802,34775,34935,34793,36355,35069,34776);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES
(34929,43671,0,0,0,1,0,0,0), -- Alliance Gunship Cannon - Ride Vehicle
(35273,68503,0,0,0,1,0,0,0), -- Glaive Thrower - Ride Vehicle
(34802,68503,0,0,0,1,0,0,0), -- Glaive Thrower - Ride Vehicle
(34775,66245,0,0,0,1,0,0,0), -- Demolisher - Ride Vehicle
(34935,43671,0,0,0,1,0,0,0), -- Horde Gunship Cannon - Ride Vehicle
(34793,66245,0,0,0,1,0,0,0), -- Catapult - Ride Vehicle
(36355,46598,0,0,0,1,0,0,0), -- Siege Turret - Ride Vehicle Hardcoded
(35069,46598,0,0,0,1,0,0,0), -- Siege Engine - Ride Vehicle Hardcoded
(34776,46598,0,0,0,1,0,0,0); -- Siege Engine - Ride Vehicle Hardcoded

DELETE FROM `creature_template_addon` WHERE `entry` IN (34944,34793,34929,34775,34935,34776,36355,35069,35273,34802);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(34944,0,0,1,0, NULL), -- Keep Cannon
(34793,0,0,257,0, NULL), -- Catapult
(34929,0,0,1,0, NULL), -- Alliance Gunship Cannon
(34775,0,0,257,0, NULL), -- Demolisher
(34935,0,0,1,0, NULL), -- Horde Gunship Cannon
(34776,0,0,1,0, NULL), -- Siege Engine
(36355,0,0,257,0, NULL), -- Siege Turret
(35069,0,0,1,0, NULL), -- Siege Engine
(35273,0,0,257,0, NULL), -- Glaive Thrower
(34802,0,0,257,0, NULL); -- Glaive Thrower

UPDATE `creature_template` SET
`spell1`=66218, -- Launch
`spell2`=66296, -- Shadow Veil
`spell8`=68362 -- Driving Credit (SPELL_EFFECT_DUMMY)
WHERE `entry`=34793; -- Catapult (E9 87)

UPDATE `creature_template` SET
`spell1`=66518 -- Airship Cannon
WHERE `entry`=34929; -- Alliance Gunship Cannon (71 88)

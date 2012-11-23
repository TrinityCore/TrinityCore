-- delete custom templates
DELETE FROM `creature_template` WHERE `entry` IN (3678902,3678903,3712602,3712603,3712702,3712703,3713202,3713203,3713302,3713303,3713402,3713403,3812501,3812502,3812503);
DELETE FROM `creature_onkill_reputation` WHERE `creature_id` IN (3678902,3678903,3712602,3712603);
DELETE FROM `creature_loot_template` WHERE `entry` IN (3712602,3712603);

-- Spire Frostwyrm
UPDATE `creature` SET `spawnMask`=15 WHERE `id`=37528;

-- equip templates
SET @EQUIP := 2422;
DELETE FROM `creature_equip_template` WHERE `entry`=@EQUIP;
INSERT INTO `creature_equip_template` (`entry`,`equipentry1`,`equipentry2`,`equipentry3`) VALUES
(@EQUIP,39381,0,45872);

-- creature template updates
UPDATE `creature_template` SET `difficulty_entry_2`=0,`difficulty_entry_3`=0 WHERE `entry`=36789; -- Valithria Dreamwalker
UPDATE `creature_template` SET `difficulty_entry_2`=0,`difficulty_entry_3`=0 WHERE `entry`=37126; -- Sister Svalna
UPDATE `creature_template` SET `difficulty_entry_2`=0,`difficulty_entry_3`=0 WHERE `entry`=37127; -- Ymirjar Frostbinder
UPDATE `creature_template` SET `difficulty_entry_2`=0,`difficulty_entry_3`=0 WHERE `entry`=37132; -- Ymirjar Battle-Maiden
UPDATE `creature_template` SET `difficulty_entry_2`=0,`difficulty_entry_3`=0 WHERE `entry`=37133; -- Ymirjar Warlord
UPDATE `creature_template` SET `difficulty_entry_2`=0,`difficulty_entry_3`=0 WHERE `entry`=37134; -- Ymirjar Huntress
UPDATE `creature_template` SET `difficulty_entry_2`=0,`difficulty_entry_3`=0 WHERE `entry`=38125; -- Ymirjar Deathbringer
UPDATE `creature_template` SET `minlevel`=83,`maxlevel`=83,`unit_class`=1,`faction_A`=1665,`faction_H`=1665,`unit_flags`=0x20000000,`baseattacktime`=2000,`scale`=1,`RegenHealth`=0 WHERE `entry` IN (36789,38174); -- Valithria Dreamwalker
UPDATE `creature_template` SET `minlevel`=81,`maxlevel`=81,`unit_class`=2,`faction_A`=16,`faction_H`=16,`unit_flags`=0,`baseattacktime`=2000,`scale`=1 WHERE `entry` IN (37868,38167,38725,38735); -- Risen Archmage
UPDATE `creature_template` SET `minlevel`=60,`maxlevel`=60,`unit_class`=1,`faction_A`=14,`faction_H`=14,`unit_flags`=0x2000000,`baseattacktime`=2000,`scale`=1 WHERE `entry`=38752; -- Green Dragon Combat Trigger
UPDATE `creature_template` SET `minlevel`=82,`maxlevel`=82,`unit_class`=2,`faction_A`=2209,`faction_H`=2209,`unit_flags`=0x0040,`dynamicflags`=8,`baseattacktime`=2000,`equipment_id`=10084,`scale`=1,`speed_run`=2.285714,`speed_walk`=1.6,`InhabitType`=7 WHERE `entry` IN (37126,38258); -- Sister Svalna
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`unit_class`=8,`faction_A`=2209,`faction_H`=2209,`unit_flags`=0x8040,`dynamicflags`=8,`baseattacktime`=2000,`equipment_id`=93,`scale`=1 WHERE `entry` IN (37127,38126); -- Ymirjar Frostbinder
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`unit_class`=1,`faction_A`=2209,`faction_H`=2209,`unit_flags`=0x8040,`dynamicflags`=8,`baseattacktime`=2000,`equipment_id`=10128,`scale`=1,`speed_walk`=1.2 WHERE `entry` IN (37132,38132); -- Ymirjar Battle-Maiden
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`unit_class`=1,`faction_A`=2209,`faction_H`=2209,`unit_flags`=0x8040,`dynamicflags`=8,`baseattacktime`=2000,`equipment_id`=358,`scale`=1,`speed_run`=1.428571 WHERE `entry` IN (37133,38133); -- Ymirjar Warlord
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`unit_class`=2,`faction_A`=2209,`faction_H`=2209,`unit_flags`=0x8040,`dynamicflags`=8,`baseattacktime`=2000,`equipment_id`=@EQUIP,`scale`=1,`speed_run`=1.285714 WHERE `entry` IN (37134,38131); -- Ymirjar Huntress
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`unit_class`=2,`faction_A`=2209,`faction_H`=2209,`unit_flags`=0x8000,`dynamicflags`=8,`baseattacktime`=2000,`equipment_id`=93,`scale`=1 WHERE `entry` IN (38125,38130); -- Ymirjar Deathbringer
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`unit_class`=1,`faction_A`=2209,`faction_H`=2209,`baseattacktime`=2000,`scale`=1 WHERE `entry`=38154; -- Warhawk

-- model updates
UPDATE `creature_model_info` SET `bounding_radius`=2,`combat_reach`=20,`gender`=2 WHERE `modelid`=30318; -- Valithria Dreamwalker
UPDATE `creature_model_info` SET `bounding_radius`=1.5,`combat_reach`=2.25,`gender`=0 WHERE `modelid`=7919; -- Risen Archmage
UPDATE `creature_model_info` SET `bounding_radius`=0.93,`combat_reach`=12,`gender`=1 WHERE `modelid`=30521; -- Sister Svalna
UPDATE `creature_model_info` SET `bounding_radius`=0.403,`combat_reach`=1.3,`gender`=1 WHERE `modelid`=27548; -- Ymirjar Frostbinder
UPDATE `creature_model_info` SET `bounding_radius`=0.403,`gender`=1 WHERE `modelid`=27549; -- Ymirjar Battle-Maiden
UPDATE `creature_model_info` SET `bounding_radius`=0.465,`combat_reach`=1.5, `gender`=0 WHERE `modelid`=26623; -- Ymirjar Warlord
UPDATE `creature_model_info` SET `bounding_radius`=0.31,`combat_reach`=1,`gender`=1 WHERE `modelid`=25771; -- Ymirjar Warlord
UPDATE `creature_model_info` SET `bounding_radius`=0.403,`combat_reach`=1.3, `gender`=1 WHERE `modelid`=27548; -- Ymirjar Deathbringer

-- Gunship Armory (delete wrong spawn)
DELETE FROM `gameobject` WHERE `id`=202178;

-- Mode specific objects (instance portal) reused deleted guids
DELETE FROM `gameobject` WHERE `id` IN (202315,202316,202317,202318);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(150308,202318,631,5,1,82.1685,2211.82,33.0959,3.14159,0,0,1,0,6000,100,1),
(150310,202316,631,10,1,82.1685,2211.82,33.0959,3.14159,0,0,1,0,6000,100,1),
(150321,202317,631,5,1,82.1685,2211.82,33.0959,3.14159,0,0,1,0,6000,100,1),
(150326,202315,631,10,1,82.1685,2211.82,33.0959,3.14159,0,0,1,0,6000,100,1);

UPDATE `gameobject_template` SET `faction`=114,`flags`=0x00000020 WHERE entry IN (202181,202182,202183,201919,201920);
UPDATE `gameobject` SET `state`=0,animprogress=255 WHERE `id` IN (202181,202182,202183,201919,201920);
UPDATE `gameobject` SET `spawnMask`=15 WHERE `id` IN (201825,201583,201374,201911,201880,202211,201777,201772,201774,201771,201814,201816,202220,201811,201812,202079,202223,202235,202242,202243,202244,202245,202246);

SET @GUID := 137746;
DELETE FROM `creature` WHERE (`position_x` BETWEEN 4330 AND 4380) AND (`position_y` BETWEEN 2470 AND 2650) AND `position_z` > 350;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+37;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+00,36789,631,05,1,0,0,4203.65,2483.89,364.961,5.5152400,604800,0,0,06000003,0,0,0,0,0,0), -- Valithria Dreamwalker
(@GUID+01,36789,631,10,1,0,0,4203.65,2483.89,364.961,5.5152400,604800,0,0,17999997,0,0,0,0,0,0), -- Valithria Dreamwalker
(@GUID+02,37868,631,15,1,0,0,4222.86,2504.58,364.960,3.9095400,604800,0,0,0,0,0,0,0,0,0), -- Risen Archmage
(@GUID+03,37868,631,15,1,0,0,4223.40,2465.11,364.952,2.3911000,604800,0,0,0,0,0,0,0,0,0), -- Risen Archmage
(@GUID+04,37868,631,15,1,0,0,4230.44,2478.56,364.953,2.9321500,604800,0,0,0,0,0,0,0,0,0), -- Risen Archmage
(@GUID+05,37868,631,15,1,0,0,4230.53,2490.22,364.957,3.3684900,604800,0,0,0,0,0,0,0,0,0), -- Risen Archmage
(@GUID+06,38752,631,15,1,0,0,4203.89,2484.23,364.956,0.0000000,604800,0,0,0,0,0,0,0,0,0), -- Green Dragon Combat Trigger
(@GUID+07,37126,631,15,1,0,0,4356.71,2484.33,371.531,1.5708000,604800,0,0,0,0,0,0,0,0,0), -- Sister Svalna
(@GUID+08,37127,631,15,1,0,0,4346.72,2607.90,351.101,3.2342600,7200,0,0,0,0,0,0,0,0,0), -- Ymirjar Frostbinder
(@GUID+09,37127,631,15,1,0,0,4371.41,2570.52,351.101,0.0808906,7200,0,0,0,0,0,0,0,0,0), -- Ymirjar Frostbinder
(@GUID+10,37132,631,15,1,0,0,4349.24,2624.60,351.101,1.5592400,7200,0,0,0,0,0,0,0,0,0), -- Ymirjar Battle-Maiden
(@GUID+11,37132,631,15,1,0,0,4365.26,2624.06,351.101,1.6023200,7200,0,0,0,0,0,0,0,0,0), -- Ymirjar Battle-Maiden
(@GUID+12,37132,631,15,1,0,0,4347.20,2637.91,351.100,1.3406800,7200,0,0,0,0,0,0,0,0,0), -- Ymirjar Battle-Maiden
(@GUID+13,37132,631,15,1,0,0,4367.90,2638.14,351.100,1.7765700,7200,0,0,0,0,0,0,0,0,0), -- Ymirjar Battle-Maiden
(@GUID+14,37132,631,15,1,0,0,4345.88,2577.64,351.101,1.5299500,7200,0,0,0,0,0,0,0,0,0), -- Ymirjar Battle-Maiden
(@GUID+15,37132,631,15,1,0,0,4368.03,2578.97,351.101,1.6909600,7200,0,0,0,0,0,0,0,0,0), -- Ymirjar Battle-Maiden
(@GUID+16,37132,631,15,1,0,0,4369.26,2525.06,358.433,1.7891300,7200,0,0,0,0,0,0,0,0,0), -- Ymirjar Battle-Maiden
(@GUID+17,37132,631,15,1,0,0,4343.78,2525.43,358.433,1.2629100,7200,0,0,0,0,0,0,0,0,0), -- Ymirjar Battle-Maiden
(@GUID+18,37133,631,15,1,0,0,4366.83,2510.30,358.518,1.6231600,7200,0,0,0,0,0,0,0,0,0), -- Ymirjar Warlord
(@GUID+19,37133,631,15,1,0,0,4356.85,2636.39,351.101,1.5692200,7200,0,0,0,0,0,0,0,0,0), -- Ymirjar Warlord
(@GUID+20,37133,631,15,1,0,0,4346.98,2512.75,358.441,1.3571600,7200,0,0,0,0,0,0,0,0,0), -- Ymirjar Warlord
(@GUID+21,37133,631,15,1,0,0,4356.77,2524.27,358.433,1.5024600,7200,0,0,0,0,0,0,0,0,0), -- Ymirjar Warlord
(@GUID+22,37134,631,15,1,0,0,4351.66,2642.95,351.100,1.4035100,7200,0,0,0,0,0,0,0,0,0), -- Ymirjar Huntress
(@GUID+23,37134,631,15,1,0,0,4362.18,2642.97,351.100,1.5331000,7200,0,0,0,0,0,0,0,0,0), -- Ymirjar Huntress
(@GUID+24,37134,631,15,1,0,0,4363.48,2585.09,351.101,1.5849300,7200,0,0,0,0,0,0,0,0,0), -- Ymirjar Huntress
(@GUID+25,37134,631,15,1,0,0,4349.36,2584.54,351.101,1.6084900,7200,0,0,0,0,0,0,0,0,0), -- Ymirjar Huntress
(@GUID+26,37134,631,15,1,0,0,4350.65,2528.31,358.433,1.5299500,7200,0,0,0,0,0,0,0,0,0), -- Ymirjar Huntress
(@GUID+27,37134,631,15,1,0,0,4362.76,2527.67,358.433,1.4828200,7200,0,0,0,0,0,0,0,0,0), -- Ymirjar Huntress
(@GUID+28,38125,631,15,1,0,0,4369.75,2606.94,351.101,6.2462700,7200,0,0,0,0,0,0,0,0,0), -- Ymirjar Deathbringer
(@GUID+29,38125,631,15,1,0,0,4340.83,2572.01,351.101,3.1439400,7200,0,0,0,0,0,0,0,0,0), -- Ymirjar Deathbringer
(@GUID+30,38154,631,15,1,0,0,4360.11,2644.49,351.100,1.5880800,7200,0,0,0,0,0,0,0,0,0), -- Warhawk
(@GUID+31,38154,631,15,1,0,0,4355.22,2644.43,351.100,1.5841500,7200,0,0,0,0,0,0,0,0,0), -- Warhawk
(@GUID+32,38154,631,15,1,0,0,4359.36,2587.74,351.101,1.6477600,7200,0,0,0,0,0,0,0,0,0), -- Warhawk
(@GUID+33,38154,631,15,1,0,0,4354.53,2587.01,351.101,1.6438300,7200,0,0,0,0,0,0,0,0,0), -- Warhawk
(@GUID+34,38229,631,15,1,0,0,4358.06,2608.39,351.184,2.8626600,3600,5,0,0,0,0,1,0,0,0), -- Frozen Insect
(@GUID+35,38229,631,15,1,0,0,4351.09,2488.49,358.441,1.9373600,3600,5,0,0,0,0,1,0,0,0), -- Frozen Insect
(@GUID+36,38229,631,15,1,0,0,4356.68,2525.39,358.432,1.6956800,3600,5,0,0,0,0,1,0,0,0), -- Frozen Insect
(@GUID+37,38229,631,15,1,0,0,4352.72,2610.13,351.101,2.8266300,3600,5,0,0,0,0,1,0,0,0); -- Frozen Insect

-- creature addon
DELETE FROM `creature_addon` WHERE `guid` IN (131604,@GUID+7,@GUID+18,@GUID+19,@GUID+20,@GUID+21);
INSERT INTO `creature_addon` (`guid`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@GUID+07,0x3000000,0x0000001,0, '70203 0'), -- Sister Svalna
(@GUID+18,0x0000000,0x0000001,0, '71244 0'), -- Ymirjar Warlord
(@GUID+19,0x0000000,0x0000001,0, '71244 0'), -- Ymirjar Warlord
(@GUID+20,0x0000000,0x0000001,0, '71244 0'), -- Ymirjar Warlord
(@GUID+21,0x0000000,0x0000001,0, '71244 0'); -- Ymirjar Warlord

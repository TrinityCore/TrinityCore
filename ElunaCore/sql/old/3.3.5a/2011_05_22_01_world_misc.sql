/* Ruby Sanctum template updates */
SET @EquiEntry = 2466; -- (creature_equip_template.entry - need 7)

-- Template
UPDATE `creature_template` SET `exp`=2,`equipment_id`=@EquiEntry+0 WHERE `entry`=39746; -- General Zarithrian
UPDATE `creature_template` SET `exp`=2 WHERE `entry`=39747; -- Saviana Ragefire
UPDATE `creature_template` SET `exp`=2,`equipment_id`=@EquiEntry+1 WHERE `entry`=39751; -- Baltharus the Warborn
UPDATE `creature_template` SET `exp`=2,`minlevel`=80,`maxlevel`=80,`unit_flags`=`unit_flags`|0x2000000,`speed_run`=0.99206 WHERE `entry`=39794; -- Zarithrian Spawn Stalker
UPDATE `creature_template` SET `exp`=2,`baseattacktime`=2000,`unit_flags`=`unit_flags`|0x8000,`equipment_id`=@EquiEntry+2 WHERE `entry`=39814; -- Onyx Flamecaller (flying)
UPDATE `creature_template` SET `baseattacktime`=1500,`unit_flags`=`unit_flags`|0x8040 WHERE `entry`=39863; -- Halion
UPDATE `creature_template` SET `exp`=2,`baseattacktime`=2000,`unit_flags`=`unit_flags`|0x40,`equipment_id`=@EquiEntry+1 WHERE `entry`=39899; -- Baltharus the Warborn (clone)
UPDATE `creature_template` SET `exp`=2,`unit_flags`=`unit_flags`|0x2000000,`unit_class`=1 WHERE `entry`=40001; -- Combustion
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|0x2000000,`unit_class`=2 WHERE `entry`=40029; -- Meteor Strike
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|0x2000000,`unit_class`=2 WHERE `entry`=40041; -- Meteor Strike
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|0x2000000,`unit_class`=2 WHERE `entry`=40042; -- Meteor Strike
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|0x2000000,`unit_class`=2 WHERE `entry`=40043; -- Meteor Strike
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|0x2000000,`unit_class`=2 WHERE `entry`=40044; -- Meteor Strike
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|0x2000000,`unit_class`=2 WHERE `entry`=40055; -- Meteor Strike
UPDATE `creature_template` SET `exp`=2,`baseattacktime`=2000,`unit_flags`=`unit_flags`|0x2000100,`speed_run`=0.42857 WHERE `entry`=40081; -- Orb Carrier (vehicle)
UPDATE `creature_template` SET `exp`=2,`baseattacktime`=2000,`unit_flags`=`unit_flags`|0x2000000,`speed_run`=0.85714 WHERE `entry`=40083; -- Shadow Orb
UPDATE `creature_template` SET `baseattacktime`=2000,`unit_flags`=`unit_flags`|0x2000100,`speed_run`=0.78571 WHERE `entry`=40091; -- Orb Rotation Focus
UPDATE `creature_template` SET `exp`=2,`baseattacktime`=2000,`unit_flags`=`unit_flags`|0x2000000,`speed_run`=0.85714 WHERE `entry`=40100; -- Shadow Orb
UPDATE `creature_template` SET `exp`=2,`baseattacktime`=1500,`unit_flags`=`unit_flags`|0x88840,`dynamicflags`=`dynamicflags`|0xC WHERE `entry`=40142; -- Halion (P2)
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|0x2000100 WHERE `entry`=40146; -- Halion Controller
UPDATE `creature_template` SET `exp`=2,`baseattacktime`=2000,`unit_flags`=`unit_flags`|0x8040,`equipment_id`=@EquiEntry+3,`unit_class`=8 WHERE `entry`=40417; -- Charscale Invoker
UPDATE `creature_template` SET `exp`=2,`baseattacktime`=2000,`unit_flags`=`unit_flags`|0x8040,`equipment_id`=@EquiEntry+4 WHERE `entry`=40419; -- Charscale Assaulter
UPDATE `creature_template` SET `exp`=2,`baseattacktime`=1250,`unit_flags`=`unit_flags`|0x8040,`equipment_id`=@EquiEntry+5 WHERE `entry`=40421; -- Charscale Elite
UPDATE `creature_template` SET `exp`=2,`baseattacktime`=2000,`unit_flags`=`unit_flags`|0x8040,`equipment_id`=@EquiEntry+6 WHERE `entry`=40423; -- Charscale Commander
UPDATE `creature_template` SET `exp`=2,`unit_flags`=`unit_flags`|0x8000,`unit_class`=8 WHERE `entry`=40429; -- Sanctum Guardian Xerestrasza
UPDATE `creature_template` SET `exp`=2,`unit_flags`=`unit_flags`|0x22040300 WHERE `entry`=40626; -- Ruby Drakonid
UPDATE `creature_template` SET `exp`=2,`unit_flags`=`unit_flags`|0x22040300 WHERE `entry`=40627; -- Ruby Drake
UPDATE `creature_template` SET `exp`=2,`unit_flags`=`unit_flags`|0x22040300 WHERE `entry`=40628; -- Ruby Scalebane
UPDATE `creature_template` SET `exp`=2,`unit_flags`=`unit_flags`|0x22040300 WHERE `entry`=40870; -- Ruby Dragon

-- Equips
DELETE FROM `creature_equip_template` WHERE `entry` BETWEEN @EquiEntry AND @EquiEntry+6;
INSERT INTO `creature_equip_template` (`entry`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(@EquiEntry+0,43111,0,0),
(@EquiEntry+1,28365,0,0),
(@EquiEntry+2,19355,0,0),
(@EquiEntry+3,43114,0,0),
(@EquiEntry+4,5597,0,0),
(@EquiEntry+5,49737,49737,0),
(@EquiEntry+6,40608,0,0);

-- Model
UPDATE `creature_model_info` SET `bounding_radius`=1.75,`combat_reach`=1,`gender`=0 WHERE `modelid`=32179; -- General Zarithrian
UPDATE `creature_model_info` SET `bounding_radius`=2.625,`combat_reach`=5.25,`gender`=1 WHERE `modelid`=31577; -- Saviana Ragefire
UPDATE `creature_model_info` SET `bounding_radius`=3,`combat_reach`=9,`gender`=0 WHERE `modelid`=31761; -- Baltharus the Warborn
UPDATE `creature_model_info` SET `bounding_radius`=1.8,`combat_reach`=1,`gender`=2 WHERE `modelid`=31952; -- Halion
UPDATE `creature_model_info` SET `bounding_radius`=2,`combat_reach`=4,`gender`=2 WHERE `modelid`=16946; -- Combustion
UPDATE `creature_model_info` SET `bounding_radius`=1.5,`combat_reach`=5,`gender`=0 WHERE `modelid`=14308; -- Charscale Assaulter
UPDATE `creature_model_info` SET `bounding_radius`=0.67025,`combat_reach`=2.625,`gender`=1 WHERE `modelid`=31962; -- Sanctum Guardian Xerestrasza
UPDATE `creature_model_info` SET `bounding_radius`=1.875,`combat_reach`=6.25,`gender`=0 WHERE `modelid`=32105; -- Ruby Drakonid
UPDATE `creature_model_info` SET `bounding_radius`=3.75,`combat_reach`=4.375,`gender`=0 WHERE `modelid`=32104; -- Ruby Scalebane
UPDATE `creature_model_info` SET `bounding_radius`=1,`combat_reach`=1,`gender`=1 WHERE `modelid`=2718; -- Ruby Dragon

-- Addon
UPDATE `creature_template_addon` SET `bytes1`=0,`bytes2`=0x1,`mount`=0,`emote`=0,`auras`='29266' WHERE `entry`=40626; -- Ruby Drakonid (Permanent Feing Death)
UPDATE `creature_template_addon` SET `bytes1`=0,`bytes2`=0x1,`mount`=0,`emote`=0,`auras`='29266' WHERE `entry`=40627; -- Ruby Drake (Permanent Feing Death)
UPDATE `creature_template_addon` SET `bytes1`=0,`bytes2`=0x1,`mount`=0,`emote`=0,`auras`='29266' WHERE `entry`=40628; -- Ruby Scalebane (Permanent Feing Death)
UPDATE `creature_template_addon` SET `bytes1`=0,`bytes2`=0x1,`mount`=0,`emote`=0,`auras`='29266' WHERE `entry`=40870; -- Ruby Dragon (Permanent Feing Death)
DELETE FROM `creature_template_addon` WHERE `entry` IN (39746,39747,39751,39794,39814,39863,40001,40029,40041,40042,40043,40044,40055,40081,40083,40091,40100,40142,40146,40417,40419,40421,40423,40429);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(39746,0,0,0x1,0, NULL), -- General Zarithrian
(39747,0,0,0x1,0, NULL), -- Saviana Ragefire
(39751,0,0,0x1,0, NULL), -- Baltharus the Warborn
(39794,0,0,0x1,0, NULL), -- Zarithrian Spawn Stalker
(39814,0,0,0x1,0, NULL), -- Onyx Flamecaller
(39863,0,0,0x1,0, NULL), -- Halion
(40001,0,0,0x1,0, NULL), -- Combustion
(40029,0,0,0x1,0, NULL), -- Meteor Strike
(40041,0,0,0x1,0, NULL), -- Meteor Strike
(40042,0,0,0x1,0, NULL), -- Meteor Strike
(40043,0,0,0x1,0, NULL), -- Meteor Strike
(40044,0,0,0x1,0, NULL), -- Meteor Strike
(40055,0,0,0x1,0, NULL), -- Meteor Strike
(40081,0,0x3000000,0x1,0, NULL), -- Orb Carrier
(40083,0,0x2000000,0x1,0, NULL), -- Shadow Orb
(40091,0,0,0x1,0, NULL), -- Orb Rotation Focus
(40100,0,0x2000000,0x1,0, NULL), -- Shadow Orb
(40142,0,0,0x1,0, NULL), -- Halion
(40146,0,0,0x1,0, NULL), -- Halion Controller
(40417,0,0,0x1,0, NULL), -- Charscale Invoker
(40419,0,0,0x1,0, NULL), -- Charscale Assaulter
(40421,0,0,0x1,0, NULL), -- Charscale Elite
(40423,0,0,0x1,0, NULL), -- Charscale Commander
(40429,0,0,0x1,0, NULL); -- Sanctum Guardian Xerestrasza

-- GOs
UPDATE `gameobject_template` SET `flags`=`flags`|0x30 WHERE `entry`=203007; -- Ruby Sanctum Halion Flame Ring

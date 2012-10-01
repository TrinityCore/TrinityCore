-- 2012_09_30_00_world_spell_script_names.sql
DELETE FROM `spell_script_names` WHERE `spell_id` IN (74562,74567,74610,74641,74792,74795,74800,74805,74807,74808,74812,75396,74769,77844,77845,77846);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(74562, 'spell_halion_fiery_combustion'),
(74567, 'spell_halion_mark_of_combustion'),
(74610, 'spell_halion_damage_aoe_summon'),
(74641, 'spell_halion_meteor_strike_marker'),
(74792, 'spell_halion_soul_consumption'),
(74795, 'spell_halion_mark_of_consumption'),
(74800, 'spell_halion_damage_aoe_summon'),
(74805, 'spell_halion_summon_exit_portals'),
(74807, 'spell_halion_enter_twilight_realm'),
(74808, 'spell_halion_twilight_phasing'),
(74812, 'spell_halion_leave_twilight_realm'),
(75396, 'spell_halion_clear_debuffs'),
(74769, 'spell_halion_twilight_cutter'),
(77844, 'spell_halion_twilight_cutter'),
(77845, 'spell_halion_twilight_cutter'),
(77846, 'spell_halion_twilight_cutter');

-- 2012_09_30_01_world_spell_dbc.sql
DELETE FROM `spell_dbc` WHERE  `Id` IN (70507, 74810, 74805);
INSERT INTO `spell_dbc` (`Id`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `Stances`, `StancesNot`, `Targets`, `CastingTimeIndex`, `AuraInterruptFlags`, `ProcFlags`, `ProcChance`, `ProcCharges`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `Effect1`, `Effect2`, `Effect3`, `EffectDieSides1`, `EffectDieSides2`, `EffectDieSides3`, `EffectRealPointsPerLevel1`, `EffectRealPointsPerLevel2`, `EffectRealPointsPerLevel3`, `EffectBasePoints1`, `EffectBasePoints2`, `EffectBasePoints3`, `EffectMechanic1`, `EffectMechanic2`, `EffectMechanic3`, `EffectImplicitTargetA1`, `EffectImplicitTargetA2`, `EffectImplicitTargetA3`, `EffectImplicitTargetB1`, `EffectImplicitTargetB2`, `EffectImplicitTargetB3`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectRadiusIndex3`, `EffectApplyAuraName1`, `EffectApplyAuraName2`, `EffectApplyAuraName3`, `EffectAmplitude1`, `EffectAmplitude2`, `EffectAmplitude3`, `EffectMultipleValue1`, `EffectMultipleValue2`, `EffectMultipleValue3`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectMiscValue3`, `EffectMiscValueB1`, `EffectMiscValueB2`, `EffectMiscValueB3`, `EffectTriggerSpell1`, `EffectTriggerSpell2`, `EffectTriggerSpell3`, `EffectSpellClassMaskA1`, `EffectSpellClassMaskA2`, `EffectSpellClassMaskA3`, `EffectSpellClassMaskB1`, `EffectSpellClassMaskB2`, `EffectSpellClassMaskB3`, `EffectSpellClassMaskC1`, `EffectSpellClassMaskC2`, `EffectSpellClassMaskC3`, `MaxTargetLevel`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `MaxAffectedTargets`, `DmgClass`, `PreventionType`, `DmgMultiplier1`, `DmgMultiplier2`, `DmgMultiplier3`, `AreaGroupId`, `SchoolMask`, `Comment`) VALUES
(70507, 0, 0, 256, 1024, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 101, 0, 0, 0, 0, 21, 1, 99, -1, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 61, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, "Halion - Combustion & Consumption Scale Aura"),
(74805, 0, 0, 0, 0, 0, 262144, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, -1, 0, 0, 76, 76, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 202796, 202796, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Halion - Summon Twilight Portals"),
(74810, 0, 0, 256, 268435456, 4, 0, 0, 0, 16785408, 0, 0, 0, 0, 1, 0, 0, 101, 0, 0, 0, 0, 21, 13, 0, -1, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 25, 0, 0, 0, 0, 0, 22, 0, 0, 300, 0, 0, 0, 0, 0, 1, 0, 0, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,'Halion - Copy Damage');

-- 2012_09_30_02_world_misc_templates.sql

-- Twilight Portals
UPDATE `gameobject_template` SET `flags`=32, `faction`=35, `ScriptName`="go_twilight_portal" WHERE `entry` IN (202794, 202796);

UPDATE `creature_template` SET `mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=35,`faction_A`=14,`faction_H`=14,`exp`=2 WHERE `entry` IN (39863, 39864, 39944, 39945, 40142); -- Halion
UPDATE `creature_template` SET `ScriptName`= 'boss_halion',`flags_extra`=`flags_extra`|0x1 WHERE `entry`=39863; -- Halion
UPDATE `creature_template` SET `mindmg`=422,`maxdmg`=586,`attackpower`=642,`dmg_multiplier`=7.5 WHERE `entry` IN (40417, 40418, 40419, 40420, 40421, 40422, 40423, 40424); -- Trashs
UPDATE `creature_template` SET `RegenHealth`=0 WHERE entry IN (39863,40142,39864,39944,39945,40143,40144,40145);

-- Trahs respawn time
UPDATE `creature` SET `spawntimesecs`=604800 WHERE `id` IN (39751, 39746, 39747);
UPDATE `creature` SET `spawntimesecs`=1209600 WHERE `map`=724 AND `id` NOT IN (39751,39746,39747);

UPDATE `creature_template` SET `flags_extra`=130 WHERE `entry` IN (40041, 40042, 40043, 40044); -- 40041, 40042, 40043 & 40044 - Meteor Strike
UPDATE `creature_template` SET `flags_extra`=130 WHERE `entry`=40029; -- 40029 - Meteor Strike (Initial)
UPDATE `creature_template` SET `flags_extra`=130 WHERE `entry`=40055; -- 40055 - Meteor Strike

UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`exp`=2,`mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=35 WHERE `entry`=40143; -- 40143 - Halion (1) - The Twilight Destroyer
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`exp`=2,`mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=50 WHERE `entry`=40144; -- 40144 - Halion (2) - The Twilight Destroyer
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`exp`=2,`mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=85 WHERE `entry`=40145; -- 40145 - Halion (3) - The Twilight Destroyer

-- Orb rotation focus
UPDATE `creature_template` SET `modelid1`=11686, `modelid2`=169, `scale`=1, `unit_flags`=0x2000100 WHERE `entry`=40091;

UPDATE `creature_template` SET `InhabitType`=7,`modelid1`=11686,`modelid2`=169,`VehicleId`=718,`unit_flags`=0x2000100 WHERE `entry`=40081; -- 40081 - Orb Carrier 
UPDATE `creature_template` SET `InhabitType`=7,`modelid1`=11686,`modelid2`=169,`VehicleId`=718,`unit_flags`=0x2000100 WHERE `entry`=40470; -- 40470 - Orb Carrier (1)
UPDATE `creature_template` SET `InhabitType`=7,`modelid1`=11686,`modelid2`=169,`VehicleId`=746,`unit_flags`=0x2000100 WHERE `entry`=40471; -- 40471 - Orb Carrier (2)
UPDATE `creature_template` SET `InhabitType`=7,`modelid1`=11686,`modelid2`=169,`VehicleId`=746,`unit_flags`=0x2000100 WHERE `entry`=40472; -- 40472 - Orb Carrier (3)
UPDATE `creature_template` SET `scale`=1,`flags_extra`=130,`exp`=2,`baseattacktime`=2000,`unit_flags`=33554432 WHERE `entry` IN(40001, 40135); -- 40001 & 40135 - Combustion & Consumption

-- Shadow orbs
UPDATE `creature_template` SET `InhabitType`=7,`flags_extra`=2,`unit_flags`=33554432,`baseattacktime`=2000,`speed_walk`=2.4,`speed_run`=0.85714,`faction_A`=14,`faction_H`=14,`exp`=2,`maxlevel`=80,`minlevel`=80,`HoverHeight`=6.25, `ScriptName`= '' WHERE `entry` IN (40469, 40468, 40083, 40100);

UPDATE `creature_template` SET `speed_walk`=3.2,`speed_run`=1.71428573131561, `unit_flags`=0x40 WHERE `entry` IN (40683, 40681); -- Living Inferno & Living Ember

UPDATE `creature_template` SET `ScriptName`= 'boss_twilight_halion' WHERE `entry`=40142; -- Twilight Halion
UPDATE `creature_template` SET `ScriptName`= 'npc_orb_carrier' WHERE `entry`=40081; -- Orb carrier
UPDATE `creature_template` SET `ScriptName`= 'npc_combustion_consumption' WHERE `entry` IN(40001, 40135); -- Combustion & consumption
UPDATE `creature_template` SET `ScriptName`= 'npc_meteor_strike_initial' WHERE `entry`=40029;
UPDATE `creature_template` SET `ScriptName`= 'npc_meteor_strike' WHERE `entry` IN (40041, 40042, 40043, 40044);

UPDATE `creature_template` SET `speed_walk`=1.6,`speed_run`=1.42857146263123,`minlevel`=83,`maxlevel`=83,`faction_H`=14,`faction_A`=14,`unit_flags`=0x88840,`BaseAttackTime`=1800,`DynamicFlags`=0xC WHERE `entry`=40142; -- Twilight Halion
UPDATE `creature_template` SET `speed_walk`=1.6,`speed_run`=1.42857146263123,`minlevel`=83,`maxlevel`=83,`faction_H`=14,`faction_A`=14,`unit_flags`=0x8040,`BaseAttackTime`=1500 WHERE `entry`=39863; -- Material Halion
UPDATE `creature_template` SET `faction_H`=14,`faction_A`=14,`unit_flags`=0x2000000,`unit_class`=2 WHERE `entry`=40029; -- Meteor Strike
UPDATE `creature_template` SET `faction_H`=14,`faction_A`=14,`unit_flags`=0x2000000 WHERE `entry`=40001; -- Combustion
UPDATE `creature_template` SET `InhabitType`=0x4,`speed_walk`=1.2,`speed_run`=0.428571432828903,`VehicleId`=718,`minlevel`=80,`maxlevel`=80,`faction_H`=14,`faction_A`=14,`unit_flags`=0x2000100 WHERE `entry`=40081; -- Orb Carrier
UPDATE `creature_template` SET `speed_walk`=2.2,`speed_run`=0.785714268684387,`minlevel`=80,`maxlevel`=80,`faction_H`=14,`faction_A`=14,`unit_flags`=0x2000100 WHERE `entry`=40091; -- Orb Rotation Focus
UPDATE `creature_template` SET `flags_extra`=130,`ScriptName`= 'npc_halion_controller',`exp`=2,`speed_walk`=2.8,`speed_run`=1,`minlevel`=80,`maxlevel`=80,`faction_A`=14,`faction_H`=14,`unit_flags`=0x2000100 WHERE `entry`=40146; -- 40146 - Halion Controller

UPDATE `creature_model_info` SET `bounding_radius`=1, `combat_reach`=2 WHERE `modelid`=16946;
UPDATE `creature_model_info` SET `combat_reach`=18 WHERE `modelid`=31952; -- Halion
UPDATE `creature_model_info` SET `combat_reach`=12.25 WHERE `modelid`=32179; -- General Zarithrian

-- Halion, Combustion, Consumption, Shadow Orb, Rotation Focus, Controller
DELETE FROM `creature_template_addon` WHERE `entry` IN (40142, 40146, 40001, 40135, 40100, 40469, 40468, 40083, 39863, 40091);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(40142, 0, 0x0, 0x1, '75476'),
(40146, 0, 0x0, 0x1, ''),
(40001, 0, 0x0, 0x1, '74629'),
(40135, 0, 0x0, 0x1, '74803'),
(40469, 0, 0x2000000, 0x1, ''),
(40468, 0, 0x2000000, 0x1, ''),
(40083, 0, 0x2000000, 0x1, ''),
(40100, 0, 0x2000000, 0x1, ''),
(39863, 0, 0x0, 0x1, '78243'),
(40091, 0, 0x0, 0x1, '');

-- Vehicle accessory for Orb Carrier
DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (40081,40470,40471,40472);
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`) VALUES
(40081,40083,0,1, 'Orb Carrier',6,30000),
(40081,40100,1,1, 'Orb Carrier',6,30000),

(40470,40083,0,1, 'Orb Carrier',6,30000),
(40470,40100,1,1, 'Orb Carrier',6,30000),

(40471,40083,0,1, 'Orb Carrier',6,30000),
(40471,40100,1,1, 'Orb Carrier',6,30000),
(40471,40468,2,1, 'Orb Carrier',6,30000),
(40471,40469,3,1, 'Orb Carrier',6,30000),

(40472,40083,0,1, 'Orb Carrier',6,30000),
(40472,40100,1,1, 'Orb Carrier',6,30000),
(40472,40468,2,1, 'Orb Carrier',6,30000),
(40472,40469,3,1, 'Orb Carrier',6,30000);

-- Vehicle spellclicks
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (40081,40470,40471,40472);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(40081, 46598, 0, 1), -- Ride Vehicle Hardcoded
(40470, 46598, 0, 1),
(40471, 46598, 0, 1),
(40472, 46598, 0, 1);

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=74758;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=75509;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=75886;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,75886,0,0,31,0,3,40683,0,0,0, "", "Blazing Aura can only target Living Embers"),
(13,1,75886,0,0,31,0,3,40684,0,0,0, "", "Blazing Aura can only target Living Embers"),
(13,3,75509,0,0,31,0,3,40142,0,0,0, "", "Twilight Mending can only target Halion"),
(13,3,75509,0,0,31,0,3,39863,0,0,0, "", "Twilight Mending can only target Halion"),
(13,1,74758,0,0,31,0,3,40091,0,0,0, "", "Track Rotation can only target Orb Rotation Focus");

-- 2012_09_30_03_world_creature_text.sql
DELETE FROM `creature_text` WHERE `entry`=39863;
DELETE FROM `creature_text` WHERE `entry`=40142;
DELETE FROM `creature_text` WHERE `entry`=40146;
DELETE FROM `creature_text` WHERE `entry`=40083;
DELETE FROM `creature_text` WHERE `entry`=40146;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES 
(39863,0,0, 'Meddlesome insects! You are too late. The Ruby Sanctum is lost!',14,0,100,1,0,17499, 'Halion'),
(39863,1,0, 'Your world teeters on the brink of annihilation. You will ALL bear witness to the coming of a new age of DESTRUCTION!',14,0,100,0,0,17500, 'Halion'),
(39863,2,0, 'The heavens burn!',14,0,100,0,0,17505, 'Halion'),
(39863,3,0, 'You will find only suffering within the realm of twilight! Enter if you dare!',14,0,100,0,0,17507, 'Halion'),
(39863,4,0, 'Relish this victory, mortals, for it will be your last! This world will burn with the master''s return!',14,0,100,0,0,17503, 'Halion'),
(39863,5,0, 'Another "hero" falls.',14,0,100,0,0,17501, 'Halion'),
(39863,6,0, 'Not good enough.',14,0,100,0,0,17504, 'Halion'),
(39863,7,0, 'Your efforts force %s further out of the physical realm!',41,0,100,0,0,0, 'Halion'),
(39863,8,0, 'Your companions'' efforts force %s further into the physical realm!',41,0,100,0,0,0, 'Halion'),
(40142,0,0, 'Beware the shadow!',14,0,100,0,0,17506, 'Halion'),
(40142,1,0, 'I am the light and the darkness! Cower, mortals, before the herald of Deathwing!',14,0,100,0,0,17508, 'Halion'),
(40142,2,0, 'Your companions'' efforts force %s further into the twilight realm!',41,0,100,0,0,0, 'Halion'),
(40142,3,0, 'Your efforts force %s further out of the twilight realm!',41,0,100,0,0,0, 'Halion'),
(40083,0,0, 'The orbiting spheres pulse with dark energy!',41,0,100,0,0,0, 'Shadow Orb'),
(40146,0,0, 'Without pressure in both realms, %s begins to regenerate.',41,0,100,0,0,0, 'Halion Controller');

-- 2012_09_30_04_world_misc_spawns.sql
SET @GUID = 42639;  -- Requires one   (creature)
SET @OGUID = 5286; -- Requires three (gameobject)

DELETE FROM `gameobject` WHERE `id`=203624;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@OGUID,203624,724,15,0x20,3157.372,533.9948,72.8887,1.034892,0,0,0.4946623,0.8690853,120,0,0);

DELETE FROM `creature` WHERE `id` IN (40081,40091); -- ,40151);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID,40091,724,1,0x20,0,0,3113.711,533.5382,72.96869,1.936719,300,0,0,1,0,0,0,0,0),
(@GUID+1,40081,724,1,0x20,0,0,3153.75,533.1875,72.97205,0,300,0,0,1,0,0,0,0,0);

SET @PATH = @GUID * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3117.59,547.7952,72.96869,0,0,0,0,100,0),
(@PATH,2,3127.461,558.7396,72.96869,0,0,0,0,100,0),
(@PATH,3,3138.042,567.9514,72.98305,0,0,0,0,100,0),
(@PATH,4,3154.09,574.9636,72.98305,0,0,0,0,100,0),
(@PATH,5,3172.565,567.493,72.86058,0,0,0,0,100,0),
(@PATH,6,3181.981,555.8889,72.9127,0,0,0,0,100,0),
(@PATH,7,3189.923,533.3542,73.0377,0,0,0,0,100,0),
(@PATH,8,3182.315,513.4202,72.9771,0,0,0,0,100,0),
(@PATH,9,3177.168,504.3802,72.7271,0,0,0,0,100,0),
(@PATH,10,3167.878,496.8368,72.50312,0,0,0,0,100,0),
(@PATH,11,3152.238,490.4705,72.62009,0,0,0,0,100,0),
(@PATH,12,3138.174,499.3056,72.87009,0,0,0,0,100,0),
(@PATH,13,3126.83,506.0799,72.95515,0,0,0,0,100,0),
(@PATH,14,3120.68,515.3524,72.95515,0,0,0,0,100,0),
(@PATH,15,3113.711,533.5382,72.96869,0,0,0,0,100,0);

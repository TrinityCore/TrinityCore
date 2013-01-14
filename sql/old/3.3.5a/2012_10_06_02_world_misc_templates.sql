-- Twilight Portals
UPDATE `gameobject_template` SET `flags`=32, `faction`=35, `ScriptName`="go_twilight_portal" WHERE `entry` IN (202794, 202796);

UPDATE `creature_template` SET `mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=35,`faction_A`=14,`faction_H`=14,`exp`=2 WHERE `entry` IN (39863, 39864, 39944, 39945, 40142); -- Halion
UPDATE `creature_template` SET `ScriptName`= 'boss_halion',`flags_extra`=`flags_extra`|0x1 WHERE `entry`=39863; -- Halion
UPDATE `creature_template` SET `mindmg`=422,`maxdmg`=586,`attackpower`=642,`dmg_multiplier`=7.5 WHERE `entry` IN (40417, 40418, 40419, 40420, 40421, 40422, 40423, 40424); -- Trashs

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

UPDATE `creature_template` SET `ScriptName`="npc_living_ember" WHERE `entry`=40683;
UPDATE `creature_template` SET `ScriptName`="npc_living_inferno" WHERE `entry`=40681;

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
(13,1,75509,0,0,31,0,3,40142,0,0,0, "", "Twilight Mending can only target Halion"),
(13,2,75509,0,0,31,0,3,39863,0,0,0, "", "Twilight Mending can only target Halion"),
(13,1,74758,0,0,31,0,3,40091,0,0,0, "", "Track Rotation can only target Orb Rotation Focus");

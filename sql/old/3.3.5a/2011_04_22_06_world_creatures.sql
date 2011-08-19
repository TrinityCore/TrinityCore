SET @EquiEntry = 2439; -- Need 1 slot

-- Stormwind npcs
UPDATE `creature_template` SET `exp`=1,`minlevel`=65,`maxlevel`=65,`npcflag`=`npcflag`|4224,`unit_flags`=`unit_flags`|32768,`speed_run`=1.1428571428571 WHERE `entry`=34075; -- Captain Dirgehammer
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|32768,`speed_run`=1.1428571428571 WHERE `entry`=12778; -- Lieutenant Rachel Vaccar
UPDATE `creature_template` SET `minlevel`=75,`maxlevel`=75,`npcflag`=`npcflag`|4224,`unit_flags`=`unit_flags`|32768,`equipment_id`=@EquiEntry,`speed_run`=1.1428571428571 WHERE `entry`=34078; -- Lieutenant Tristia
UPDATE `creature_template` SET `exp`=1,`minlevel`=65,`maxlevel`=65,`npcflag`=`npcflag`|128,`unit_flags`=`unit_flags`|32768,`speed_run`=1.1428571428571 WHERE `entry`=34081; -- Captain O'Neal
UPDATE `creature_template` SET `faction_A`=123,`faction_H`=123,`exp`=2,`minlevel`=75,`maxlevel`=75,`baseattacktime`=2000,`npcflag`=`npcflag`|4224,`unit_flags`=`unit_flags`|32768,`equipment_id`=188,`speed_run`=1.1428571428571 WHERE `entry`=40607; -- Knight-Lieutenant T'Maire Sydes
UPDATE `creature_template` SET `baseattacktime`=2000,`speed_run`=2.8571428571429,`InhabitType`=5 WHERE `entry`=32180; -- Tempus Wyrm
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|33554432,`unit_class`=2,`speed_walk`=4,`speed_run`=2.8571428571429,`InhabitType`=7 WHERE `entry`=34381; -- [DND]Northrend Children's Week Trigger
UPDATE `creature_template` SET `speed_walk`=4,`speed_run`=2.8571428571429,`InhabitType`=5 WHERE `entry`=27925; -- Nozdormu
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|256,`speed_run`=2.8571428571429,`InhabitType`=5 WHERE `entry`=32185; -- Infinite Eradicator
UPDATE `creature_template` SET `faction_A`=2141,`faction_H`=2141,`exp`=2,`speed_run`=1.1428571428571 WHERE `entry`=32331; -- Past You  ???
UPDATE `creature_template` SET `faction_A`=2111,`faction_H`=2111,`unit_flags`=`unit_flags`|34816,`speed_run`=1.1428571428571 WHERE `entry`=27896; -- Infinite Assailant
UPDATE `creature_template` SET `faction_A`=2111,`faction_H`=2111,`unit_flags`=`unit_flags`|559104,`speed_run`=1.1428571428571 WHERE `entry`=27897; -- Infinite Destroyer
UPDATE `creature_template` SET `exp`=2,`speed_run`=1 WHERE `entry`=32327; -- Hourglass of Eternity
UPDATE `creature_template` SET `speed_walk`=1.2,`speed_run`=2 WHERE `entry`=26841; -- Reanimated Frost Wyrm
UPDATE `creature_template` SET `faction_A`=35,`faction_H`=35,`unit_flags`=`unit_flags`|33556488,`flags_extra`=`flags_extra`|128 WHERE `entry`=28306; -- Anti-Magic Zone

UPDATE `creature_model_info` SET `bounding_radius`=0.208,`combat_reach`=1.5,`gender`=1 WHERE `modelid`=31953; -- Knight-Lieutenant T'Maire Sydes
UPDATE `creature_model_info` SET `bounding_radius`=0.3,`combat_reach`=1,`gender`=0 WHERE `modelid`=27814; -- Infinite Eradicator
UPDATE `creature_model_info` SET `bounding_radius`=3.5,`combat_reach`=3,`gender`=2 WHERE `modelid`=24934; -- Nozdormu
UPDATE `creature_model_info` SET `bounding_radius`=0.5,`combat_reach`=1,`gender`=2 WHERE `modelid`=11686; -- [DND]Northrend Children's Week Trigger
UPDATE `creature_model_info` SET `bounding_radius`=0.3,`combat_reach`=1,`gender`=0 WHERE `modelid`=27813; -- Infinite Timebreaker
UPDATE `creature_model_info` SET `bounding_radius`=0.5,`combat_reach`=1,`gender`=2 WHERE `modelid`=11686; -- Past You
UPDATE `creature_model_info` SET `bounding_radius`=0.3,`combat_reach`=2.5,`gender`=0 WHERE `modelid`=20512; -- Infinite Destroyer
UPDATE `creature_model_info` SET `bounding_radius`=0.375,`combat_reach`=1.25,`gender`=0 WHERE `modelid`=19062; -- Infinite Assailant

UPDATE `creature_template_addon` SET `bytes1`=0,`bytes2`=256,`auras`= '5301 0' WHERE `entry`=12778; -- Lieutenant Rachel Vaccar
UPDATE `creature_template_addon` SET `bytes2`=258 WHERE `entry`=12780; -- Sergeant Major Skyshadow
UPDATE `creature_template_addon` SET `bytes1`=0,`bytes2`=256,`auras`= '5301 0' WHERE `entry`=19848; -- Harbinger Ennarth
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=12779; -- Archmage Gaiman

DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (31257,26426,32186,26841));
DELETE FROM `creature_template_addon` WHERE `entry` IN (34075,34081,40607,34078,28306);
DELETE FROM `creature_template_addon` WHERE `entry` IN (26426,27925,32186,32180,32185,32327,26841);
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`auras`) VALUES
(34075,0,257, '5301 0'), -- Captain Dirgehammer
(34081,0,257, NULL), -- Captain O'Neal
(40607,0,257, NULL), -- Knight-Lieutenant T'Maire Sydes
(34078,0,257, '5301 0'), -- Lieutenant Tristia
(26426,0,1, '47015 0'), -- Arctic Ram
(27925,50397184,1, '50013 0'),
(32186,50331648,1, '4368 0'), -- Infinite Timebreaker
(32180,50331648,1, '4368 0'), -- Tempus Wyrm
(32185,50331648,1, '4368 0'), -- Infinite Eradicator
(32327,0,1, '50057 0 50867 0'), -- Hourglass of Eternity
(26841,50331648,1, NULL), -- Reanimated Frost Wyrm
(28306,0,257, NULL); -- Anti-Magic Zone

DELETE FROM `creature_equip_template` WHERE `entry`=@EquiEntry;
INSERT INTO `creature_equip_template` (`entry`,`equipentry1`,`equipentry2`,`equipentry3`) VALUES
(@EquiEntry,34520,29638,0); -- Equipment of 34078 (Lieutenant Tristia)

-- 5302, triggered by 5301 is missing from spell_dbc. Data from 1.1.2 spell_dbc
DELETE FROM `spell_dbc` WHERE `Id`=5302;
INSERT INTO `spell_dbc` (`Id`,`Attributes`,`AttributesEx`,`CastingTimeIndex`,`ProcChance`,`DurationIndex`,`RangeIndex`,`EquippedItemClass`,`Effect1`,`EffectImplicitTargetA1`,`EffectApplyAuraName1`,`DmgMultiplier1`,`DmgMultiplier2`,`DmgMultiplier3`,`Comment`) VALUES
(5302,536871312,1024,1,101,28,1,-1,6,1,4,1,1,1, 'Defensive State - Follows a successful block,dodge or parry.');

-- Update info for spell 3617 found in earlier patches dbc
UPDATE `spell_dbc` SET `Attributes`=256,`CastingTimeIndex`=1,`ProcChance`=101,`SpellLevel`=45,`RangeIndex`=1,`Effect1`=1,`EffectDieSides1`=1,`EffectBasePoints1`=1,`EffectImplicitTargetA1`=1,`DmgMultiplier1`=1,`DmgMultiplier2`=1,`DmgMultiplier3`=1 WHERE `id`=3617;
-- Update info for spell 7056 found in earlier patches dbc
UPDATE `spell_dbc` SET `Attributes`=336,`CastingTimeIndex`=1,`ProcChance`=101,`DurationIndex`=21,`RangeIndex`=1,`Effect1`=6,`EffectImplicitTargetA1`=1,`EffectApplyAuraName1`=25,`DmgMultiplier2`=1,`DmgMultiplier2`=1,`DmgMultiplier3`=1,`Comment`= 'Pacified' WHERE `id`=7056;

-- Spawn Nozdormu (Remember to set guid)
DELETE FROM `creature` WHERE `id`=27925;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(152260,27925,571,1,1,0,0,4112.988,-417.6215,191.0509,1.727876,300,0,0,1,0,0,0,0,0,0);

-- Missing spell
DELETE FROM `spell_dbc` WHERE `id`=70507;
INSERT INTO `spell_dbc` (`Id`,`Attributes`,`AttributesEx`,`AttributesEx2`,`CastingTimeIndex`,`ProcChance`,`DurationIndex`,`RangeIndex`,`StackAmount`,`Effect1`,`EffectBasePoints1`,`EffectImplicitTargetA1`,`EffectApplyAuraName1`,`DmgMultiplier1`,`Comment`) VALUES
(70507,0x00000100,0x00000400,0x0,1,101,21,1,99,6,10,1,61,1, 'Halion - Combustion & Consumption Scale Aura');

-- Bosses respawn time
UPDATE `creature` SET `spawntimesecs`=604800 WHERE `id` IN (39751,39746,39747);
-- Trash mobs respawn time
UPDATE `creature` SET `spawntimesecs`=1209600 WHERE `map`=724 AND `id` NOT IN (39751,39746,39747);

-- Twilight Flame Ring
SET @OGUID = xx; -- Need 1 (Set by TDB team)
INSERT INTO `gameobject` (`guid`,`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID,203624,724,15,0x20,3154.99,535.637,72.887,3.14159,0,0,0,0,120,0,0); -- GO_TWILIGHT_FLAME_RING

-- Creature Templates updates
UPDATE `creature_template` SET `scale`=1,`flags_extra`=130,`exp`=2,`baseattacktime`=2000,`unit_flags`=33554432,`ScriptName`= 'npc_consumption' WHERE `entry`=40135; -- Consumption
UPDATE `creature_template` SET `scale`=1,`flags_extra`=130,`unit_flags`=33554432 ,`ScriptName`= 'npc_combustion' WHERE `entry`=40001; -- Combustion
UPDATE `creature_template` SET `scale`=1,`flags_extra`=130,`unit_flags`=33554432 WHERE `entry`=40091; -- Orb Rotation Focus
UPDATE `creature_model_info` SET `bounding_radius`=3.8,`combat_reach`=7.6,`gender`=2 WHERE `modelid`=16946;
UPDATE `creature_template` SET `ScriptName`= 'boss_halion',`flags_extra`=`flags_extra`|0x1,`exp`=2 WHERE `entry`=39863; -- Halion
UPDATE `creature_template` SET `ScriptName`= 'boss_twilight_halion',`exp`=2 WHERE `entry`=40142; -- Twilight Halion
UPDATE `creature_template` SET `flags_extra`=130,`ScriptName`= 'npc_halion_controller', `faction_A`=35,`faction_H`=35,`exp`=2 WHERE `entry`=40146; -- Halion Controller
UPDATE `creature_template` SET `flags_extra`=2,`unit_flags`=33554432,`baseattacktime`=2000,`speed_walk`=2.4,`speed_run`=0.85714,`faction_A`=14,`faction_H`=14,`exp`=2,`maxlevel`=80,`minlevel`=80, `ScriptName`= 'npc_shadow_orb' WHERE `entry` IN (40083, 40100, 40469, 40468);
UPDATE `creature_template` SET `ScriptName`= 'npc_meteor_strike_initial',`flags_extra`=130 WHERE `entry`=40029; -- Meteor Strike Initial
UPDATE `creature_template` SET `ScriptName`= 'npc_meteor_strike',`flags_extra`=130 WHERE `entry` IN (40041,40042,40043,40044); -- Meteor Strike
UPDATE `creature_template` SET `flags_extra`=130 WHERE `entry`=40055; -- Meteor Strike
UPDATE `creature_template` SET `difficulty_entry_1`=40143,`difficulty_entry_2`=40144,`difficulty_entry_3`=40145 WHERE `entry`=40142;
UPDATE `creature_template` SET `difficulty_entry_1`=40470,`difficulty_entry_2`=40471,`difficulty_entry_3`=40472 WHERE `entry`=40081;
UPDATE `creature_template` SET `mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=35,`faction_A`=14,`faction_H`=14 WHERE `entry` IN (39863,39864,39944,39945,40142,40143,40144,40145); -- Halion & Twilight Halion
UPDATE `creature_template` SET `mindmg`=422,`maxdmg`=586,`attackpower`=642,`dmg_multiplier`=7.5 WHERE `entry` IN (40417,40418,4049,40420,40421,40422,40423,40424); -- Trash mobs
UPDATE `creature_template` SET `mindmg`=509,`maxdmg`=683,`attackpower`=805,`dmg_multiplier`=35 WHERE `entry` IN (39751,39920,39747,39823,39746,39805); -- Miniboss
UPDATE `creature_template` SET `faction_A`=14, `faction_H`=14, `exp`=2 WHERE `entry` IN (40143,40144,40145);
UPDATE `creature_template` SET `VehicleId`=718 WHERE `entry` IN (40081,40470);
UPDATE `creature_template` SET `VehicleId`=746 WHERE `entry` IN (40471,40472);

DELETE FROM `creature_template_addon` WHERE `entry` IN (39863, 40142);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(40142,0,0,0,0,0, '75476 78243'), -- Twilight Halion: Twilight precision + Dusk Shroud
(39863,0,0,0,0,0, '78243'); -- Halion: Twilight Precision

-- This is INCORRECT and BREAKS TC STANDARDS by editing WDB field data10
-- Best would be to create the sniffed spell in the spell_dbc table.
UPDATE `gameobject_template` SET `data10`=74807,`flags`=`flags`|32 WHERE `entry` IN (202794, 202795);
UPDATE `gameobject_template` SET `ScriptName`="go_exit_twilight_realm",`flags`=`flags`|32 WHERE `entry`=202796;

-- Spell scripts
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_halion_meteor_strike_marker';
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_halion_fiery_combustion';
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_halion_soul_consumption';
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_halion_mark_of_combustion';
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_halion_mark_of_consumption';
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_halion_combustion_consumption_summon';
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_halion_leave_twilight_realm';
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_halion_enter_twilight_realm';
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_halion_twilight_cutter';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(74641, 'spell_halion_meteor_strike_marker'),
(74562, 'spell_halion_fiery_combustion'),
(74792, 'spell_halion_soul_consumption'),
(74567, 'spell_halion_mark_of_combustion'),
(74795, 'spell_halion_mark_of_consumption'),
(74610, 'spell_halion_combustion_consumption_summon'),
(74800, 'spell_halion_combustion_consumption_summon'),
(74812, 'spell_halion_leave_twilight_realm'),
(74807, 'spell_halion_enter_twilight_realm'),
(74769, 'spell_halion_twilight_cutter'),
(77844, 'spell_halion_twilight_cutter'),
(77845, 'spell_halion_twilight_cutter'),
(77846, 'spell_halion_twilight_cutter');

-- Texts
DELETE FROM `creature` WHERE `id`=40146;
DELETE FROM `creature_text` WHERE `entry`=39863;
DELETE FROM `creature_text` WHERE `entry`=40142;
DELETE FROM `creature_text` WHERE `entry`=40146;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES 
(39863,0,0, 'Meddlesome insects! You are too late. The Ruby Sanctum is lost!',14,0,100,1,0,17499, 'Halion'),
(39863,1,0, 'Your world teeters on the brink of annihilation. You will ALL bear witness to the coming of a new age of DESTRUCTION!',14,0,100,0,0,17500, 'Halion'),
(39863,2,0, 'The heavens burn!',14,0,100,0,0,17505, 'Halion'),
(39863,3,0, 'You will find only suffering within the realm of twilight! Enter if you dare!',14,0,100,0,0,17507, 'Halion'),
(39863,4,0, 'Relish this victory, mortals, for it will be your last! This world will burn with the master''s return!',14,0,100,0,0,17503, 'Halion'),
(39863,5,0, 'Another "hero" falls.',14,0,100,0,0,17501, 'Halion'),
(39863,6,0, 'Not good enough.',14,0,100,0,0,17504, 'Halion'),

(40142,0,0, 'Beware the shadow!',14,0,100,0,0,17506, 'Halion'),
(40142,1,0, 'I am the light and the darkness! Cower, mortals, before the herald of Deathwing!',14,0,100,0,0,17508, 'Halion'),

(40146,0,0, 'Your companion''s efforts have forced Halion further out of the Physical realm!',42,0,100,0,0,0, 'Halion'),
(40146,1,0, 'Your efforts have forced Halion further into the Physical realm!',42,0,100,0,0,0, 'Halion'),
(40146,2,0, 'Your companion''s efforts have forced Halion further out of the Twilight realm!',42,0,100,0,0,0, 'Halion'),
(40146,3,0, 'Your efforts have forced Halion further into the Twilight realm!',42,0,100,0,0,0, 'Halion'),
(40146,4,0, 'Without pressure in both realms, Halion begins to regenerate.',42,0,100,0,0,0, 'Halion'),
(40146,5,0, 'The orbiting spheres pulse with dark energy!',42,0,100,0,0,0, 'Halion');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=75509;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,75509,0,18,1,39863,0,0, '', 'Spell Twilight Mending only target Halion'),
(13,0,75509,0,18,1,40142,0,0, '', 'Spell Twilight Mending only target Twilight Halion');

-- Spawns
SET @GUID = XXX; -- Set by TDB team (Need 2)
DELETE FROM `creature` WHERE `id` IN (40081, 40091);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID  ,40091,724,1,20,0,0,3113.711,533.5382,72.96869,1.936719,300,0,0,1,0,0,0,0,0), -- Orb Rotation Focus
(@GUID+1,40081,724,1,20,0,0,3153.75,533.1875,72.97205,0,300,0,0,1,0,0,0,0,0); -- Orb Carrier

-- Pathing for Orb Rotation Focus
SET @PATH = @GUID * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3117.590,547.7952,72.96869,0,0,0,100,0),
(@PATH,2,3124.956,550.5857,72.46869,0,0,0,100,0),
(@PATH,3,3127.461,558.7396,72.96869,0,0,0,100,0),
(@PATH,4,3131.277,560.5203,72.47587,0,0,0,100,0),
(@PATH,5,3138.042,567.9514,72.98305,0,0,0,100,0),
(@PATH,6,3144.315,566.3213,72.47660,0,0,0,100,0),
(@PATH,7,3154.090,574.9636,72.98305,0,0,0,100,0),
(@PATH,8,3162.892,563.1807,72.42181,0,0,0,100,0),
(@PATH,9,3172.565,567.4930,72.86058,0,0,0,100,0),
(@PATH,10,3172.249,559.6212,72.66829,0,0,0,100,0),
(@PATH,11,3181.981,555.8889,72.91270,0,0,0,100,0),
(@PATH,12,3183.607,540.6851,72.70807,0,0,0,100,0),
(@PATH,13,3189.923,533.3542,73.03770,0,0,0,100,0),
(@PATH,14,3178.180,524.1400,72.47688,0,0,0,100,0),
(@PATH,15,3182.315,513.4202,72.97710,0,0,0,100,0),
(@PATH,16,3181.581,516.2794,72.37074,0,0,0,100,0),
(@PATH,17,3177.168,504.3802,72.72710,0,0,0,100,0),
(@PATH,18,3172.814,505.5709,72.23853,0,0,0,100,0),
(@PATH,19,3167.878,496.8368,72.50312,0,0,0,100,0),
(@PATH,20,3159.053,495.9921,72.39587,0,0,0,100,0),
(@PATH,21,3152.238,490.4705,72.62009,0,0,0,100,0),
(@PATH,22,3149.552,503.7675,72.45136,0,0,0,100,0),
(@PATH,23,3138.174,499.3056,72.87009,0,0,0,100,0),
(@PATH,24,3134.466,500.9524,72.34216,0,0,0,100,0),
(@PATH,25,3126.830,506.0799,72.95515,0,0,0,100,0),
(@PATH,26,3130.457,509.2586,72.41802,0,0,0,100,0),
(@PATH,27,3120.680,515.3524,72.95515,0,0,0,100,0),
(@PATH,28,3118.542,525.5302,72.46192,0,0,0,100,0),
(@PATH,29,3113.711,533.5382,72.96869,0,0,0,100,0);

-- Vehicle accessory for Orb Carrier
DELETE FROM `vehicle_template_accessory` WHERE `entry`=40081;
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

UPDATE `creature_template` SET `modelid1`=11686,`modelid2`=169 WHERE `entry`=40081;
UPDATE `creature_template` SET `InhabitType`=7 WHERE `entry` IN (40083,40081,40100);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=40081;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`cast_flags`) VALUES
(40081,46598,0,1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry`=74758;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`Comment`) VALUES
(13,74758,18,1,40091, 'Track Rotation can only target Orb Rotation Focus');

DELETE FROM `spell_dbc` WHERE `id`=70507;
INSERT INTO `spell_dbc` (`Id`,`Attributes`,`AttributesEx`,`AttributesEx2`,`CastingTimeIndex`,`ProcChance`,`DurationIndex`,`RangeIndex`,`StackAmount`,`Effect1`,`EffectBasePoints1`,`EffectImplicitTargetA1`,`EffectApplyAuraName1`,`DmgMultiplier1`,`Comment`) VALUES
(70507,0x00000100,0x00000400,0x0,1,101,21,1,99,6,10,1,61,1, 'Halion - Combustion & Consumption Scale Aura');

UPDATE `creature` SET `spawntimesecs`=604800 WHERE `id` IN (39751,39746,39747);
UPDATE `gameobject` SET `phaseMask`=`phaseMask`|0x20 WHERE `id`=203007; -- Ruby Sanctum Halion Flame Ring

UPDATE `creature_template` SET `scale`=1,`exp`=2,`baseattacktime`=2000,`unit_flags`=33554432,`ScriptName`= 'npc_consumption' WHERE `entry`=40135; -- Consumption
UPDATE `creature_template` SET `scale`=1,`flags_extra`=130,`unit_flags`=33554432 ,`ScriptName`= 'npc_combustion' WHERE `entry`=40001; -- Combustion
UPDATE `creature_template` SET `scale`=1,`flags_extra`=2,`unit_flags`=33554432 WHERE `entry`=40091; -- Orb Rotation Focus
UPDATE `creature_model_info` SET `bounding_radius`=3.8,`combat_reach`=7.6,`gender`=2 WHERE `modelid`=16946;
UPDATE `creature_template` SET `ScriptName`= 'boss_halion' WHERE `entry`=39863;
UPDATE `creature_template` SET `ScriptName`= 'boss_twilight_halion' WHERE `entry`=40142;
UPDATE `creature_template` SET `ScriptName`= 'npc_halion_controller' WHERE `entry`=40146;
UPDATE `creature_template` SET `flags_extra`=2,`unit_flags`=33554432,`baseattacktime`=2000,`speed_walk`=2.4,`speed_run`=0.85714,`faction_A`=14,`faction_H`=14,`exp`=2,`maxlevel`=80,`minlevel`=80, `ScriptName`= 'npc_shadow_orb' WHERE `entry` IN (40083, 40100, 40469, 40468);
UPDATE `creature_template` SET `ScriptName`= 'npc_meteor_strike_initial',`flags_extra`=130 WHERE `entry`=40029; -- Meteor Strike Initial
UPDATE `creature_template` SET `ScriptName`= 'npc_meteor_strike',`flags_extra`=130 WHERE `entry` IN (40041,40042,40043,40044); -- Meteor Strike
UPDATE `creature_template` SET `flags_extra`=130 WHERE `entry`=40055; -- Meteor Strike

DELETE FROM `creature_template_addon` WHERE `entry` IN (39863, 40142);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(40142,0,0,0,0,0, '75476 78243'),
(39863,0,0,0,0,0, '78243');

-- This is INCORRECT and BREAKS TC STANDARDS by editing WDB field data10
UPDATE gameobject_template SET data10=74807 WHERE entry IN (202794, 202795);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_halion_meteor_strike_marker';
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_halion_fiery_combustion';
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_halion_soul_consumption';
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_halion_mark_of_combustion';
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_halion_mark_of_consumption';
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_halion_combustion_consumption_summon';
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_halion_leave_twilight_realm';
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_halion_enter_twilight_realm';
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_halion_twilight_cutter_triggered';
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
(74769, 'spell_halion_twilight_cutter_triggered'),
(77844, 'spell_halion_twilight_cutter_triggered'),
(77845, 'spell_halion_twilight_cutter_triggered'),
(77846, 'spell_halion_twilight_cutter_triggered');

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
(40146,3,0, 'Your efforts have forced Halion further into the Twilight realm!',42,0,100,0,0,17506, 'Halion');
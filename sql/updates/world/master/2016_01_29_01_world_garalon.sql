delete from creature_model_info where modelid = 42368;
INSERT INTO `creature_model_info` (`modelid`, `bounding_radius`, `combat_reach`, `gender`, `modelid_other_gender`, `hostileId`) VALUES 
(42368, 10, 15, 2, 0, 0);

update creature_template set speed_walk = 1, speed_run = 0.4, vehicleId = 2257 where entry = 62164;
update creature_template set modelid1 = 42852, modelid2 = 0, modelid3 = 0, modelid3 = 0, modelid4 = 0, faction = 16, ScriptName = 'npc_garalons_leg', flags_extra = 536870912 where entry = 63053;
update creature_template set ScriptName = 'npc_garalon_crusher' where entry = 63191;
update creature_template set modelid1 = 11686, modelid2 = 0, modelid3 = 0, faction = 14, minlevel = 93, maxlevel = 93, unit_flags = 33554432, ScriptName = 'npc_pheromone_trail', flags_extra = 128 where entry = 63021;

update creature_template_addon set bytes1 = 0 where entry = 62164;

delete from creature_template_addon where entry = 63053;

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry in (128596,128599,128600,128601,122786,123495,123426,123109);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 128596, 0, 0, 31, 0, 3, 62164, 0, 0, 0, '', NULL),
(13, 1, 128599, 0, 0, 31, 0, 3, 62164, 0, 0, 0, '', NULL),
(13, 1, 128600, 0, 0, 31, 0, 3, 62164, 0, 0, 0, '', NULL),
(13, 1, 128601, 0, 0, 31, 0, 3, 62164, 0, 0, 0, '', NULL),
(13, 3, 122786, 0, 0, 31, 0, 3, 62164, 0, 0, 0, '', NULL),
(13, 3, 123109, 0, 0, 31, 0, 3, 62164, 0, 0, 0, '', NULL),
(13, 1, 123495, 0, 0, 31, 0, 3, 63053, 0, 0, 0, '', NULL),
(13, 1, 123426, 0, 0, 31, 0, 4, 0, 0, 0, 0, '', NULL);

delete from spell_target_filter where spellid in (123495,123808,123100);
INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `option`, `param1`, `param2`, `param3`, `aura`, `chance`, `effectMask`, `resizeType`, `count`, `maxcount`, `addcount`, `addcaster`, `comments`) VALUES 
(123495, 7, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, -1, 'Garalon - Mend Leg'),
(123808, 7, 4, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, -1, 'Garalon - Pheromones'),
(123100, 30, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, -1, 'Garalon - Pheromones friendly');

delete from spell_script_names where spell_id = 123100;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(123100, 'spell_garalon_pheromones_friendly');

delete from vehicle_template_accessory where EntryOrAura in (62164);
INSERT INTO `vehicle_template_accessory` (`EntryOrAura`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES 
(62164, 63053, 0, 1, 'Garalon\'s Leg 1', 6, 30000),
(62164, 63053, 1, 1, 'Garalon\'s Leg 2', 6, 30000),
(62164, 63053, 2, 1, 'Garalon\'s Leg 3', 6, 30000),
(62164, 63053, 3, 1, 'Garalon\'s Leg 4', 6, 30000),
(62164, 63191, 4, 1, 'Garalon Crusher', 6, 30000);

delete from npc_spellclick_spells where npc_entry = 62164;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(62164, 46598, 1, 0);


-- X: 18.76745 Y: 12.14194 Z: 0.4713488 O: 0.7853982
-- X: 18.80542 Y: -12.10082 Z: 0.5516242 O: 5.497787
-- X: -25.10569 Y: -19.08375 Z: 0.007220206 O: 3.926991
-- X: -25.43505 Y: 19.09333 Z: -0.06943779 O: 2.356194
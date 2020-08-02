-- Template Updates
UPDATE `creature_template` SET `flags_extra`= `flags_extra` | 512, `ScriptName`= 'boss_murozond' WHERE `entry`= 54432;
UPDATE `creature_template` SET `unit_flags`= 0x100, `ScriptName`= 'npc_murozond_mirror_image' WHERE `entry`= 54435;
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 54928;
UPDATE `creature_template` SET `flags_extra`= 2, `ScriptName`= 'npc_murozond_nozdormu' WHERE `entry`= 54751;

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (54432, 54751);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(54432, 0, 0, 'The \"End Time,\" I once called this place. I had not seen, by then; I did not know. You hope to... what? Stop me, here? Change the fate I worked so tirelessly to weave?', 14, 0, 100, 0, 0, 25934, 55981, 'Murozond to Infinite Suppressor'),
(54432, 1, 0, 'You crawl unwitting, like a blind, writhing worm, towards endless madness and despair. I have witnessed the true End Time. This? This is a blessing you simply cannot comprehend.', 14, 0, 100, 0, 0, 25935, 55982, 'Murozond to Infinite Warden'),
(54432, 2, 0, 'So be it.', 14, 0, 100, 0, 0, 25927, 55744, 'Murozond'),
(54432, 3, 0, 'The powers of the Hourglass do nothing to me!', 14, 0, 100, 0, 0, 25929, 53183, 'Murozond'),
(54432, 4, 0, 'To repeat the same action and expect different results is madness.', 14, 0, 100, 0, 0, 25930, 55750, 'Murozond'),
(54432, 5, 0, 'Another chance will make no difference. You will fail.', 14, 0, 100, 0, 0, 25931, 55751, 'Murozond'),
(54432, 6, 0, 'Again...? Is this your plot, your scheme?', 14, 0, 100, 0, 0, 25932, 55752, 'Murozond'),
(54432, 7, 0, 'The Hourglass\' power is exhausted. No more games, mortals. Relent, or perish.', 14, 0, 100, 0, 0, 25933, 55753, 'Murozond'),
(54432, 8, 0, 'You know not what you have done. Aman\'Thul... What I... have... seen...', 14, 0, 100, 0, 0, 25928, 55745, 'Murozond'),
(54751, 0, 0, 'Mortals! I cannot follow you any further - accept my blessing and use the Hourglass of Time to defeat Murozond!', 14, 0, 100, 0, 0, 25943, 53105, 'Nozdormu'),
(54751, 1, 0, 'At last it has come to pass. The moment of my demise. The loop is closed. My future self will cause no more harm.', 12, 0, 100, 0, 0, 25944, 55977, 'Nozdormu'),
(54751, 2, 0, 'Still, in time, I will... fall to madness. And you, heroes... will vanquish me. The cycle will repeat. So it goes.', 12, 0, 100, 0, 0, 25945, 55978, 'Nozdormu'),
(54751, 3, 0, 'What matters is that Azeroth did not fall; that we survived to fight another day.', 12, 0, 100, 0, 0, 25946, 55979, 'Nozdormu'),
(54751, 4, 0, 'All that matters... is this moment.', 12, 0, 100, 0, 0, 25947, 55980, 'Nozdormu');

UPDATE `creature_text` SET `TextRange`= 3 WHERE `CreatureID`= 54432 AND `GroupID` IN (0, 1);
UPDATE `creature_text` SET `TextRange`= 3 WHERE `CreatureID`= 54751;

-- Addons
UPDATE `creature_template_addon` SET `auras`= '69676' WHERE `entry`= 54435;

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry`= 108026 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 108026, 0, 0, 31, 0, 3, 54432, 0, 0, 0, '', 'Rewind Time - Target Murozond'),
(13, 1, 108026, 0, 1, 31, 0, 3, 54435, 0, 0, 0, '', 'Rewind Time - Target Mirror Image');

-- Spell Scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_murozond_rewind_time',
'spell_murozond_rewind_time_forcecast',
'spell_murozond_clone_master_health');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(108026, 'spell_murozond_rewind_time'),
(101590, 'spell_murozond_rewind_time_forcecast'),
(102571, 'spell_murozond_clone_master_health');

-- Serverside Spells
DELETE FROM `spell_dbc` WHERE `Id`= 108026;
INSERT INTO `spell_dbc` (`Id`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx9`, `Comment`) VALUES
(108026, 1, 21, 13, 0xA9800000, 0x00000420, 0x10084005, 0x00130000, 0x00800080, 0x00060008, 0x00003004, 0x00000010, '(Serverside/Non-DB2) Rewind Time');

DELETE FROM `spelleffect_dbc` WHERE `Id`= 160108;
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectMiscValue`, `EffectMiscValueB`, `EffectRadiusIndex`, `EffectRadiusMaxIndex`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `SpellID`, `EffectIndex`, `Comment`) VALUES
(160108, 77, 0, 0, 88, 88, 8, 0, 108026, 0, '');

-- Formation and Waypoints
-- Pathing for  Entry: 54923 'TDB FORMAT' 
SET @NPC := 341660;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= 4063.0295, `position_y`= -449.43057, `position_z`= 120.10308, `currentwaypoint`= 0 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 4052.1501, -435.24826, 118.60894, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 4055.0305, -409.7882, 118.952866, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 4062.9097, -392.6111, 118.7913, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 4080.8176, -374.02084, 118.7913, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 4098.397, -370.00522, 119.1663, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 4133.346, -363.35938, 119.08723, 0, 261, 0, 0, 100, 0),
(@PATH, 7, 4098.397, -370.00522, 119.1663, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 4080.8176, -374.02084, 118.7913, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 4062.9097, -392.6111, 118.7913, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 4055.0305, -409.7882, 118.952866, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 4052.1501, -435.24826, 118.60894, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 4063.0295, -449.43057, 120.10308, 0, 553, 0, 0, 100, 0);
-- 0x202090754035A2C000146700007EB660 .go xyz 4063.0295 -449.43057 120.10308

SET @LEADER := 341660;
DELETE FROM `creature_formations` WHERE `leaderGUID`= @LEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@LEADER, @LEADER, 0,  0,   515, 0, 0),
(@LEADER, 341662,  6,  270, 515, 6, 12),
(@LEADER, 341661,  6,  90,  515, 6, 12),
(@LEADER, 341659,  12, 90,  515, 6, 12);

SET @LEADER := 341673;
DELETE FROM `creature_formations` WHERE `leaderGUID`= @LEADER OR `memberGUID`= @LEADER;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@LEADER, 341673, 0, 0, 3, 0, 0),
(@LEADER, 341658, 0, 0, 3, 0, 0),
(@LEADER, 341656, 0, 0, 3, 0, 0),
(@LEADER, 341657, 0, 0, 3, 0, 0);

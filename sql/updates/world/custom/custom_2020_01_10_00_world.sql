DELETE FROM `creature_template_addon` WHERE `entry`= 50522;
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(50522, '59632');

UPDATE `creature_template` SET `AIName`= 'NullCreatureAI' WHERE `entry`= 50522;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_walden_conjure_mystery_toxin',
'spell_walden_toxic_coagulent',
'spell_walden_conjure_poisonous_mixture',
'spell_sfk_toxic_coagulant',
'spell_sfk_frost_shards',
'spell_walden_ice_shards',
'spell_sfk_conjure_poisonous_mixture',
'spell_walden_toxic_catalyst');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(93695, 'spell_walden_conjure_mystery_toxin'),
(93617, 'spell_walden_toxic_coagulent'),
(93697, 'spell_walden_conjure_poisonous_mixture'),
(93704, 'spell_walden_conjure_poisonous_mixture'),
(93543, 'spell_walden_ice_shards'),
(93689, 'spell_walden_toxic_catalyst');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (93599, 93594) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 93599, 0, 0, 31, 0, 3, 46963, 0, 0, 0, '', 'Toxic Coagulant - Target Lord Walden'),
(13, 1, 93594, 0, 0, 31, 0, 3, 46963, 0, 0, 0, '', 'Toxic Catalyst - Target Lord Walden');

SET @NPC := 371037;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -145.839, `position_y`= 2164.47, `position_z`= 128.5629 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -145.839, 2164.47, 128.5629, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -142.354, 2167.47, 128.4668, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -138.066, 2170.6, 128.5843, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -133.62, 2174.04, 128.9547, 0, 33, 0, 0, 100, 0),
(@PATH, 5, -133.62, 2174.04, 128.9547, 0.01745329, 53609, 0, 0, 100, 0),
(@PATH, 6, -142.083, 2174.31, 128.2636, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -142.877, 2176.71, 128.3198, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -142.814, 2180.68, 128.5607, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -141.84, 2183.98, 128.7254, 0, 47297, 0, 0, 100, 0),
(@PATH, 10, -143.854, 2179.6, 128.44, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -145.79, 2174.61, 128.1687, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -147.609, 2169.77, 128.2731, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -150.55, 2161.56, 128.6963, 0, 46308, 0, 0, 100, 0);
-- 0x20309404202DDCC000717400004B9BCD .go xyz -145.839 2164.47 128.5629

DELETE FROM `creature_text` WHERE `CreatureID`= 46963 AND `GroupID`= 3;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(46963, 3, 0, 'This library should prove to be useful to my own research.', 12, 0, 100, 0, 0, 0, 47595, 'Lord Walden'),
(46963, 3, 1, 'I must give Arugal some credit, his lines of research were quite novel.', 12, 0, 100, 0, 0, 0, 47593, 'Lord Walden'),
(46963, 3, 2, 'Missing pages, broken equipment, tainted samples! How does someone work in these conditions!', 12, 0, 100, 0, 0, 0, 47594, 'Lord Walden'),
(46963, 3, 3, 'These notes are horribly organized. I can\'t tell if Arugal was brilliant or simply an imbecile.', 12, 0, 100, 0, 0, 0, 47592, 'Lord Walden');

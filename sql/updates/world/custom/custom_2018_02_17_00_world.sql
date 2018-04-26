-- Template Updates
-- Helix Gearbreaker
UPDATE `creature_template` SET `scriptname`= 'boss_helix_gearbreaker', `flags_extra`= 0 WHERE `entry`= 47296;
UPDATE `creature_template` SET `flags_extra`= `flags_extra`|1, `DamageModifier`= 15 WHERE `entry`= 48940;
-- Lumbering Oaf
UPDATE `creature_template` SET `scriptname`= 'npc_helix_lumbering_oaf' WHERE `entry`= 47297;
UPDATE `creature_template` SET `minlevel`= 87, `maxlevel`= 87 WHERE `entry`= 48939;
-- Sticky Bomb
UPDATE `creature_template` SET `difficulty_entry_1`= 49134, `scriptname`= 'npc_helix_sticky_bomb' WHERE `entry`= 47314;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 14, `unit_flags`= 33554432 WHERE `entry`= 49134;
-- Helix' Crew
UPDATE `creature_template` SET `scriptname`= 'npc_helix_crew' WHERE `entry`= 49139;

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (47296, 47297, 49139);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES
-- Helix Gearbreaker
(47296, 0, 0, 'The mistress will pay me handsomely for your heads!', 14, 0, 100, 0, 0, 20849, 47474, 'Helix Gearbreaker - Aggro'),
(47296, 1, 0, 'Bombs away!', 14, 0, 100, 0, 0, 20847, 47475, 'Helix Gearbreaker - Bomb'),
(47296, 2, 0, 'Ready Oafie? Throw!', 14, 0, 100, 0, 0, 20848, 47476, 'Helix Gearbreaker - Throw Helix'),
(47296, 3, 0, 'Helix attaches a bomb to $n''s chest!', 41, 0, 100, 0, 0, 0, 47544, 'Helix Gearbreaker - Announce Bomb'),
(47296, 4, 0, 'I didn''t need him! Not when I''ve got YOU oafs!', 14, 0, 100, 0, 0, 20846, 47573, 'Helix Gearbreaker - Oaf Death'),
(47296, 5, 0, 'Only ten copper? You''re not even worth killing!', 14, 0, 100, 0, 0, 20845, 47574, 'Helix Gearbreaker - Slay'),
(47296, 6, 0, 'The scales...have...tipped...', 14, 0, 100, 0, 0, 20844, 47575, 'Helix Gearbreaker - Death'),
(47297, 0, 1, 'No...NO!', 14, 0, 100, 0, 0, 20854, 47480, 'Lumbering Oaf to Helix Gearbreaker'),
(47297, 1, 2, 'OAF SMASH!!', 14, 0, 100, 0, 0, 0, 48117, 'Lumbering Oaf to Helix Gearbreaker'),
(49139, 0, 0, 'Blowin'' em'' to bits, boss!', 12, 0, 100, 0, 0, 0, 49191, 'Helix Crew - Throw Bomb');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_helix_throw_bomb_targeting',
'spell_helix_sticky_bomb_periodic_trigger',
'spell_helix_explode',
'spell_helix_oaf_grab_targeting',
'spell_helix_force_player_to_ride_oaf',
'spell_helix_oaf_smash',
'spell_helix_ride_face_targeting',
'spell_helix_ride_vehicle',
'spell_helix_ride_face_timer_aura',
'spell_helix_chest_bomb_emote',
'spell_helix_chest_bomb');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(88268, 'spell_helix_throw_bomb_targeting'),
(88329, 'spell_helix_sticky_bomb_periodic_trigger'),
(88321, 'spell_helix_explode'),
(91567, 'spell_helix_explode'),
(88974, 'spell_helix_explode'),
(91566, 'spell_helix_explode'),
(88289, 'spell_helix_oaf_grab_targeting'),
(88278, 'spell_helix_force_player_to_ride_oaf'),
(88300, 'spell_helix_oaf_smash'),
(91568, 'spell_helix_oaf_smash'),
(88349, 'spell_helix_ride_face_targeting'),
(88360, 'spell_helix_ride_vehicle'),
(88351, 'spell_helix_ride_face_timer_aura'),
(91572, 'spell_helix_chest_bomb_emote'),
(88352, 'spell_helix_chest_bomb');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry`= 88295 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 88295, 0, 0, 31, 0, 3, 45979, 0, 0, 0, '', 'Charge - Target General Purpose Bunny'),
(13, 1, 88295, 0, 0, 35, 0, 1, 20, 3, 0, 0, '', 'Charge - Target Distance Must be Higher than 15 yards');

-- Loot
UPDATE `creature_template` SET  `lootid`= 47296 WHERE `entry`= 47296;
UPDATE `creature_template` SET `lootid`= 48940 WHERE `entry`= 48940;
DELETE FROM `creature_loot_template` WHERE `Entry` IN (47296, 48940);
INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(47296, 5199, 0, 1, 1, 1, 1),
(47296, 5191, 0, 1, 1, 1, 1),
(47296, 5200, 0, 1, 1, 1, 1),
(47296, 5443, 0, 1, 1, 1, 1);

INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
(48940, 63473, 0, 1, 1, 1, 1),
(48940, 63475, 0, 1, 1, 1, 1),
(48940, 63476, 0, 1, 1, 1, 1),
(48940, 63474, 0, 1, 1, 1, 1),
(48940, 65164, 0, 1, 1, 1, 1);

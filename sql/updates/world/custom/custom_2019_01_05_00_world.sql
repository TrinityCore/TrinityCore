UPDATE `creature_template` SET `exp`= 3 WHERE `entry`= 49067;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`= 93757;

DELETE FROM `spell_group` WHERE `id` IN (1125, 1126, 1127, 1128, 1129, 1130, 1131, 1132, 1133, 1134, 1135, 1136, 1137, 1138, 1139);
INSERT INTO `spell_group` (`id`, `spell_id`) VALUES
-- Armor
(1125, 465),
(1125, 8072),
-- Attack Power
(1126, 53137),
(1126, 19506),
(1126, 79101),
(1126, 79102),
(1126, 93744),
(1126, 30802),
-- Attack Speed
(1127, 53290),
(1127, 55610),
(1127, 8515),
-- Critical Strike Chance
(1128, 24932),
(1128, 29801),
(1128, 51466),
(1128, 51698),
(1128, 24604),
(1128, 90309),
-- Damage
(1129, 75447),
(1129, 82930),
(1129, 63531),
-- Damage Reduction
(1130, 16177),
(1130, 16236),
(1130, 14893),
(1130, 15357),
-- Major Haste
(1131, 80353),
(1131, 2825),
(1131, 32182),
-- Mana
(1132, 79057),
(1132, 79058),
(1132, 54424),
-- Mana Regeneration
(1133, 79101),
(1133, 79102),
(1133, 93744),
(1133, 5677),
(1133, 54424),
-- Spell Power
(1134, 77747),
(1134, 53646),
(1134, 79057),
(1134, 79058),
(1134, 52109),
-- Spell Pushback
(1135, 19746),
(1135, 87717),
-- Stats All
(1136, 79060),
(1136, 79061),
(1136, 79062),
(1136, 79063),
(1136, 90363),
-- Stats Agility / Strength
(1137, 57330),
(1137, 79891),
(1137, 8076),
(1137, 6673),
(1137, 93435),
-- Stats Stamina
(1138, 79105),
(1138, 79104),
(1138, 469),
(1138, 6307),
(1138, 90364);

DELETE FROM `spell_group_stack_rules` WHERE `group_id` IN (1125, 1126, 1127, 1128, 1129, 1130, 1131, 1132, 1133, 1134, 1135, 1136, 1137, 1138, 1139);
INSERT INTO `spell_group_stack_rules` (`group_id`, `stack_rule`) VALUES
(1125, 4),
(1126, 4),
(1127, 4),
(1128, 4),
(1129, 4),
(1130, 4),
(1131, 4),
(1132, 4),
(1133, 4),
(1134, 4),
(1135, 4),
(1136, 4),
(1137, 4),
(1138, 4);

-- Creature Darkwood Broodmother 46507 SAI
SET @ENTRY := 46507;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 4000, 5000, 7000, 8000, 11, 79607, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 4000 and 5000 ms (and later repeats every 7000 and 8000 ms) - Self: Cast spell 79607 on Victim // "),
(@ENTRY, 0, 1, 0, 0, 0, 100, 1, 10000, 11000, 0, 0, 11, 77517, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 10000 and 11000 ms (and later repeats every 0 and 0 ms) - Self: Cast spell 77517 on Victim // "),
(@ENTRY, 0, 2, 3, 2, 0, 100, 1, 0, 30, 0, 0, 11, 18501, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When health between 0% and 30% (check every 0 - 0 ms) - Self: Cast spell 18501 on Self // "),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Talk 0 // ");

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_steal_essence_visual',
'spell_whirling_winds_movement',
'spell_ethereal_pet_aura',
'spell_dk_crit',
'spell_ethereal_pet_aura_remove',
'spell_ethereal_pet_onsummon');

UPDATE `creature_template` SET `ScriptName`= '' WHERE `entry`= 2768;

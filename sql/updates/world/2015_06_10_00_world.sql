-- Skadi the ruthless, full rework
-- CREATURE
UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=26893;
UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=30775;
UPDATE `creature_template` SET `ScriptName`='npc_grauf' WHERE  `entry`=26893;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=23472;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=19871;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=28351;
DELETE FROM `creature_text` WHERE entry IN (26893,23472,19871) AND `groupid` = 0 AND `id` = 0;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES (26893, 0, 0, '%s takes a deep breath!', 41, 0, 100, 0, 0, 0, 'Grauf - Emote', 20774);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES (23472, 0, 0, 'Skadi the Ruthless is within range of the harpoon launchers!', 41, 0, 100, 0, 0, 0, 'Skadi Emote', 27809);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES (19871, 0, 0, 'Skadi the Ruthless is within range of the harpoon launchers!', 41, 0, 100, 0, 0, 0, 'Skadi Emote', 27809);

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (47593,47594,47563,51368) and `SourceTypeOrReferenceId` = 13 and `SourceGroup` = 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES (13, 1, 47593, 31, 3, 28351);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES (13, 1, 47594, 31, 3, 28351);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES (13, 1, 47563, 31, 3, 28351);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES (13, 1, 51368, 31, 3, 26893);

-- Smartscripts
DELETE FROM `smart_scripts` where `entryorguid` IN (28351,-126150,-126127);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES (28351, 0, 0, 0, 8, 0, 100, 0, 47594, 0, 0, 0, 11, 47579, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flame Breath Trigger - Cast Freezing Trap AoE');
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES (28351, 0, 1, 0, 8, 0, 100, 0, 47574, 0, 0, 0, 11, 47579, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flame Breath Trigger - Cast Freezing Trap AoE');
INSERT INTO `smart_scripts` (`entryorguid`, `event_type`, `action_type`, `target_type`, `comment`) VALUES (-126150, 38, 1, 1, 'Skadi Trigger - Emote');
INSERT INTO `smart_scripts` (`entryorguid`, `event_type`, `action_type`, `target_type`, `comment`) VALUES (-126127, 38, 1, 1, 'Skadi Trigger - Emote');
UPDATE `smart_scripts` SET `target_type`=17, `target_param1`=5, `target_param2`=30 WHERE `entryorguid`= 26692 AND `source_type`=0 AND `id`= 1 AND `link`= 0;
UPDATE `smart_scripts` SET `target_type`=17, `target_param1`=5, `target_param2`=30 WHERE `entryorguid`= 26692 AND `source_type`=0 AND `id`= 0 AND `link`= 0;

-- Spell stuff
DELETE FROM `spelldifficulty_dbc` WHERE  `id` IN (50225,50258,59334,47579,49089,49084,49091);
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`) VALUES (49091, 49091, 59249),(49084, 49084, 59246),(49089, 49089, 59246),(50255, 50255, 59331),(50258, 50258, 59334),(50228, 50228, 59322),(47579, 47579, 60020 );
DELETE FROM `spell_script_names` where `spell_id` IN (50255,59331);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (50255, 'spell_skadi_poisoned_spear'),(59331, 'spell_skadi_poisoned_spear'),(47594, 'spell_freezing_cloud_area_right'),(47574, 'spell_freezing_cloud_area_left');
DELETE FROM `spell_target_position` where `id` = 61790;
INSERT INTO `spell_target_position` (`id`, `effIndex`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`, `VerifiedBuild`) VALUES (61790, 0, 575, 342.887, -507.782, 104.471, 3.13678, 1);
DELETE from `spell_linked_spell` WHERE `spell_trigger` IN (47563,47593);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (47563, 47574, 0, 'Freezin Trap - Left');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (47593, 47594, 0, 'Freezin Trap - Right');

-- Achievement stuff
DELETE FROM `disables` WHERE  `sourceType`=4 AND `entry`=7595;
DELETE FROM `achievement_criteria_data` where `criteria_id` = 7595 and `type` = 11;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `ScriptName`) VALUES (7595, 11, 'achievement_girl_love_to_skadi');
UPDATE `gameobject_template` SET `data10`=0 WHERE `entry`=192175;
UPDATE `gameobject_template` SET `data10`=0 WHERE `entry`=192176;
UPDATE `gameobject_template` SET `data10`=0 WHERE `entry`=192177;


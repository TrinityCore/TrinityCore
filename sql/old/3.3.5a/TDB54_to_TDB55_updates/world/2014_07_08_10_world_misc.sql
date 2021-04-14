--
DELETE FROM `creature_addon` WHERE `guid` IN(124405,124406);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(124405, 0, 0, 0x10000, 0x1, 0, '27622'),
(124406, 0, 0, 0x10000, 0x1, 0, '27622');

-- Instructor Hroegar
DELETE FROM `creature_template_addon` WHERE `entry`=29915;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(29915,0,0,1,0, '56058');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(-124405,-124406);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-124406, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 5000, 5000, 11, 55796, 2, 0, 0, 0, 0, 19, 30056, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny (scale x0.01) - On Respawn - Cast Get the Key: Vaelens Chains - Left Hand'),
(-124405, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 5000, 5000, 11, 54112, 2, 0, 0, 0, 0, 19, 30056, 0, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny (scale x0.01) - On Respawn - Cast Get the Key: Vaelens Chains - Right Hand');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE  `entry`IN(30056,29915);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(30056,29915);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(30056, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 27622, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Vaelen the Flayed - On Reset - Cast Get the Key: Vaelens Invisibility & See Invisibility');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN(55796,54112);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 55796, 0, 0, 31, 0, 3, 30056, 0, 0, 0, 0, '', ''),
(13, 1, 54112, 0, 0, 31, 0, 3, 30056, 0, 0, 0, 0, '', '');

DELETE FROM `spell_area` WHERE `spell`IN(27105,56057) AND `area` IN(4492,4497);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(27105, 4492, 0, 12951, 0, 0, 2, 1, 64, 11), -- Ufrang's Hall: See Vaelen's Invisibility
(56057, 4497, 0, 12949, 0, 0, 2, 1, 64, 11); -- Savage Ledge: See Instructor Hroegar's Invisibility

DELETE FROM `creature_loot_template` WHERE `entry`=29915 AND `item`=41843;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES 
(29915, 41843, -100, 1, 0, 1, 1); -- Key to Vaelen's Chains

DELETE FROM `spell_area` WHERE `spell`= 59073 AND `area` IN (4756, 4755, 4757, 4714);
INSERT INTO `spell_area` (`spell`, `area`, `gender`, `quest_start`, `quest_start_status`, `autocast`, `quest_end`, `quest_end_status`) VALUES
(59073, 4756, 2, 14078, 64, 1, 14159, 1|2|8|32),
(59073, 4755, 2, 14099, 2|64, 1, 14159, 1|2|8|32),
(59073, 4757, 2, 14099, 2|64, 1, 14159, 1|2|8|32),
(59073, 4714, 2, 14099, 2|64, 1, 14159, 1|2|8|32);

DELETE FROM `spell_area` WHERE `spell`= 49416 AND `area`= 4756;
INSERT INTO `spell_area` (`spell`, `area`, `gender`, `quest_start`, `quest_start_status`, `autocast`, `quest_end`, `quest_end_status`) VALUES
(49416, 4756, 2, 14078, 64, 1, 14099, 1|8|32);

-- Generic NPC phasing fixups
UPDATE `creature` SET `phaseId`= 0, `phaseGroup`= 371 WHERE `id` IN (39095, 34863);

-- Generic trigger bunny (multiphase)
UPDATE `creature` SET `phaseId`= 0, `phaseGroup`= 372 WHERE `id` IN (35374, 35830, 35010, 35011) AND `map`= 654 AND `areaId`= 4756;

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (68087, 68070, 80281) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO conditions (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 68087, 0, 0, 31, 0, 3, 35374, 0, 0, 0, '', 'Just Citizen'),
(13, 1, 80281, 0, 0, 31, 0, 3, 35374, 0, 0, 0, '', 'Summon Citizen and Worgen'),
(13, 3, 68070, 0, 0, 31, 0, 3, 35374, 0, 0, 0, '', 'Summon Citizen and Worgen');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_q14098_knocking_67869');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(67869, 'spell_q14098_knocking_67869');

DELETE FROM `smart_scripts` WHERE `entryorguid`= 34981;
UPDATE `creature_template` SET `AIName`= '', `ScriptName`= 'npc_frightened_citizen' WHERE `entry` IN (34981, 35836);

-- Rampaging Worgen fixups
UPDATE `creature_template` SET `flags_extra` = `flags_extra` | 2 WHERE `entry`= 34884;

-- Merchant Square Quest Chain
DELETE FROM `quest_template_addon` WHERE `ID` IN (14093, 14098, 14099, 14094);
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`) VALUES
(14093, 14091, 0, -14093),
(14098, 14091, 0, -14093),
(14094, 14091, 0, -14093),
(14099, 14093, 0, 0); -- Royal Orders

-- Remove questgiver entry from rampaging worgens
DELETE FROM `creature_queststarter` WHERE `id`= 34884;

DELETE FROM `creature_text` WHERE `CreatureID` IN (34981, 35836, 34913);
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
-- Frightened Citizen
(34981, 0, 0, 'What in the world?  Let''s get out of here!', 12, 0, 100, 1, 0, 0, 35235, 'Frightened Citizen to Player'),
(34981, 0, 1, 'Let''s go!', 12, 0, 100, 1, 0, 0, 35236, 'Frightened Citizen to Player'),
(34981, 0, 2, 'No time to waste!', 12, 0, 100, 1, 0, 0, 35237, 'Frightened Citizen to Player'),
(34981, 0, 3, 'Worgen!  Worgen everywhere!', 12, 0, 100, 1, 0, 0, 35238, 'Frightened Citizen to Player'),
(34981, 0, 4, 'Flee!  They''re everywhere!', 12, 0, 100, 1, 0, 0, 35240, 'Frightened Citizen to Player'),
(34981, 0, 5, 'This place isn''t safe.  Let''s leave!', 12, 0, 100, 1, 0, 0, 35239, 'Frightened Citizen to Player'),
(34981, 0, 6, 'Protect me, please!', 12, 0, 100, 1, 0, 0, 35234, 'Frightened Citizen to Player'),
(35836, 0, 0, 'It''s coming right for me!!', 12, 0, 100, 1, 0, 0, 36037, 'Frightened Citizen to Player'),
(35836, 0, 1, 'Help me, please!', 12, 0, 100, 1, 0, 0, 36038, 'Frightened Citizen to Player'),
(35836, 0, 2, 'There''s one after me!', 12, 0, 100, 1, 0, 0, 36039, 'Frightened Citizen to Player'),
(35836, 0, 3, 'Help!', 12, 0, 100, 1, 0, 0, 36040, 'Frightened Citizen to Player'),
(35836, 0, 4, 'I don''t want to die!', 12, 0, 100, 1, 0, 0, 36041, 'Frightened Citizen to Player'),
-- Liam Greyman Phase 170
(34913, 0, 0, 'Stand your ground, men!', 14, 0, 100, 0, 0, 19617, 35166, 'Prince Liam Greymane'),
(34913, 0, 1, 'Defeat these foul beasts!', 14, 0, 100, 0, 0, 19618, 35167, 'Prince Liam Greymane'),
(34913, 0, 2, 'Protect the civilians!', 14, 0, 100, 0, 0, 19619, 35168, 'Prince Liam Greymane'),
(34913, 0, 3, 'Push them back!', 14, 0, 100, 0, 0, 19620, 35169, 'Prince Liam Greymane'),
(34913, 0, 4, 'Take heart, men!  We must protect our city!', 14, 0, 100, 0, 0, 19621, 35170, 'Prince Liam Greymane');

-- Creature Prince Liam Greymane 34913 SAI
SET @ENTRY := 34913;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On aggro - None: Talk 0 // ");

UPDATE `gameobject_template_addon` SET `flags`= 4 WHERE `entry`= 195306;

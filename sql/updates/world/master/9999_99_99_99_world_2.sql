-- Questline corrections
-- 27399/the-battle-is-won-the-war-goes-on (H), 27442/the-war-has-many-fronts (H), 27722/warchiefs-command-deepholm (H)
UPDATE `quest_template_addon` SET `PrevQuestID` = 0, `NextQuestID` = 0, `ExclusiveGroup` = 27399 WHERE `ID` = 27399;
UPDATE `quest_template_addon` SET `PrevQuestID` = 0, `NextQuestID` = 0, `ExclusiveGroup` = 27399 WHERE `ID` = 27442;
UPDATE `quest_template_addon` SET `PrevQuestID` = 0, `NextQuestID` = 0, `ExclusiveGroup` = 27399 WHERE `ID` = 27722;
-- 27398/the-battle-is-won-the-war-goes-on (A), 27443/the-war-has-many-fronts (A), 27727/heros-call-deepholm (A)
UPDATE `quest_template_addon` SET `PrevQuestID` = 0, `NextQuestID` = 0, `ExclusiveGroup` = 27398 WHERE `ID` = 27398;
UPDATE `quest_template_addon` SET `PrevQuestID` = 0, `NextQuestID` = 0, `ExclusiveGroup` = 27398 WHERE `ID` = 27443;
UPDATE `quest_template_addon` SET `PrevQuestID` = 0, `NextQuestID` = 0, `ExclusiveGroup` = 27398 WHERE `ID` = 27727;
-- 27203/the-maelstrom (A/H) has no quest requirements (PrevQuestID = 0).
UPDATE `quest_template_addon` SET `PrevQuestID` = 0, `NextQuestID` = 27123 WHERE `ID` = 27203;
-- 27123/deepholm-realm-of-earth (A/H)
UPDATE `quest_template_addon` SET `PrevQuestID` = 27203, `NextQuestID` = 26245, `ExclusiveGroup` = 0 WHERE `ID` = 27123;
-- 26245/gunship-down (A/H)
-- 26246/captains-log
-- 26247/diplomacy-first

-- Quest Invisibility (18-1000)
-- Portal to the Maelstrom object (Quest 27203 - Quest 27123)
DELETE FROM `spell_area` WHERE `area` IN (5428, 5429) AND `spell` = 84481;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(84481, 5428, 27203, 27123, 0, 0, 2, 1, 74, 11), -- Stormwind
(84481, 5429, 27203, 27123, 0, 0, 2, 1, 74, 11); -- Orgrimmar

-- To-do: Set up quest_end fields (notes: 43397/seer-kormo, 42573/earthcaller-yevaa, 43405/mariahn-the-soulcleanser (aura 83323))
-- Generic Quest Invisibility 12
-- visibility 20 aura: 83323
-- see visibility 20 aura: 83322
DELETE FROM `spell_area` WHERE `spell` = 83322 AND `area` IN (5395, 5291, 5335, 5303);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(83322, 5395, 0, 0, 0, 0, 2, 1, 0, 0),
(83322, 5291, 0, 0, 0, 0, 2, 1, 0, 0),
(83322, 5335, 0, 0, 0, 0, 2, 1, 0, 0),
(83322, 5303, 0, 0, 0, 0, 2, 1, 0, 0);

-- To-do: Set up quest_end fields
-- Quest Invisibility 16
-- invisibility 24: 84667
-- see invisibility 24: 84117
DELETE FROM `spell_area` WHERE `spell` = 84117 AND `area` IN (5395, 5291, 5335, 5303);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(84117, 5395, 0, 0, 0, 0, 2, 1, 0, 0),
(84117, 5291, 0, 0, 0, 0, 2, 1, 0, 0),
(84117, 5335, 0, 0, 0, 0, 2, 1, 0, 0),
(84117, 5303, 0, 0, 0, 0, 2, 1, 0, 0);

-- To-do: Set up quest_end fields
-- Generic Quest Invisibility 19
-- invisibility 27: 84957
-- see invisibility 27: 84955
DELETE FROM `spell_area` WHERE `spell` = 84955 AND `quest_start` = 0 AND `area` IN (5395, 5291, 5335, 5303);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(84955, 5395, 0, 0, 0, 0, 2, 1, 0, 0),
(84955, 5291, 0, 0, 0, 0, 2, 1, 0, 0),
(84955, 5335, 0, 0, 0, 0, 2, 1, 0, 0),
(84955, 5303, 0, 0, 0, 0, 2, 1, 0, 0);

-- SPELL: 84464/Portal to the Maelstrom
-- SPELL: 84073/Deepholm Intro Teleport
DELETE FROM `spell_target_position` WHERE `ID` IN (84464, 84073);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(84464, 0, 730, 854.924, 1080.96, -12.5196, 0),
(84073, 1, 646, 1040.91, 544.689, 681.86, 0);

-- NPC: 45005/Wyvern (spellclick flag)
UPDATE `creature_template` SET `npcflag` = 16777216 WHERE `entry` = 45005;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (45005, 45004, 45024);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(45005, 84071, 1, 0), -- 84071/Stormbeak
(45004, 46598, 0, 0), -- 46598/Ride Vehicle Hardcoded
(45024, 46598, 0, 0); -- 46598/Ride Vehicle Hardcoded

-- QUEST: 27123/deepholm-realm-of-earth quest (A/H)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 18 AND `SourceGroup` = 45005 OR `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (84364, 84365);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18, 45005, 84071, 0, 0, 9, 0, 27123, 0, 0, 0, 0, 0, '', 'Required quest active for spellclick'),
(13, 0, 84364, 0, 0, 31, 0, 3, 43718, 0, 0, 0, 0, '', 'Camera 1 targets Generic Trigger LAB (Gigantic AOI)'),
(13, 0, 84365, 0, 0, 31, 0, 3, 43718, 0, 0, 0, 0, '', 'Camera 2 targets Generic Trigger LAB (Gigantic AOI)');
 
-- NPC: 43718/Generic Trigger LAB (Gigantic AOI)
-- NPC: 45004/wyvern
-- NPC: 45024/wyvern
UPDATE `creature_template` SET `InhabitType` = 7 WHERE `entry` = 43718;
UPDATE `creature_template` SET `InhabitType` = 4, `speed_run` = 2.42857, `VehicleId` = 1071, `ScriptName` = 'npc_deepholm_intro_wyvern' WHERE `entry` = 45004;
UPDATE `creature_template` SET `InhabitType` = 4, `speed_run` = 2.42857, `VehicleId` = 1073, `ScriptName` = 'npc_deepholm_intro_wyvern' WHERE `entry` = 45024;

-- NPC: 45028/aggra
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 45028;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (45028, 4502800);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(45028, 0, 0, 1, 8, 0, 100, 0, 96122, 0, 0, 0, '', 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Aggra - Hit by Spell - Store Action Invoker'),
(45028, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 80, 4502800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aggra - Link - Run Script'),
(4502800, 9, 0, 0, 0, 0, 100, 0,  3000,  3000, 0, 0, '', 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aggra - Actionlist - Say Line 0'),
(4502800, 9, 1, 0, 0, 0, 100, 0,  9000,  9000, 0, 0, '', 1, 1, 0, 1, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Aggra - Actionlist - Say Line 1'),
(4502800, 9, 2, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, '', 1, 2, 0, 1, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Aggra - Actionlist - Say Line 2'),
(4502800, 9, 3, 0, 0, 0, 100, 0,  9000,  9000, 0, 0, '', 1, 3, 0, 1, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Aggra - Actionlist - Say Line 3'),
(4502800, 9, 4, 0, 0, 0, 100, 0,     0,     0, 0, 0, '', 11, 86971, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Aggra - Actionlist - Cast pre-forcecast spell');

-- NPC: 45027/aggra
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 45027;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (45027, 4502700);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(45027, 0, 0, 1, 8, 0, 100, 0, 96122, 0, 0, 0, '', 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Aggra - Hit by Spell - Store Action Invoker'),
(45027, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 80, 4502700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aggra - Link - Run Script'),
(4502700, 9, 0, 0, 0, 0, 100, 0, 2500,  2500,  0, 0, '', 1, 0, 0, 1, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Aggra - Actionlist - Say Line 0'),
(4502700, 9, 1, 0, 0, 0, 100, 0, 4500,  4500,  0, 0, '', 1, 1, 0, 1, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Aggra - Actionlist - Say Line 1'),
(4502700, 9, 2, 0, 0, 0, 100, 0, 7000,  7000,  0, 0, '', 1, 2, 0, 1, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Aggra - Actionlist - Say Line 2'),
(4502700, 9, 3, 0, 0, 0, 100, 0, 13000, 13000, 0, 0, '', 1, 3, 0, 1, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Aggra - Actionlist - Say Line 3'),
-- (4502700, 9, 4, 0, 0, 0, 100, 0, 6000,  6000,  0, 0, '', 90, 257, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aggra - Actionlist - Set Bytes 2 to 257'),
(4502700, 9, 4, 0, 0, 0, 100, 0, 8000,  8000,  0, 0, '', 1, 4, 0, 1, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Aggra - Actionlist - Say Line 4'),
(4502700, 9, 5, 0, 0, 0, 100, 0, 9500,  9500,  0, 0, '', 1, 5, 0, 1, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Aggra - Actionlist - Say Line 5'),
-- (4502700, 9, 7, 0, 0, 0, 100, 0, 3000,  3000,  0, 0, '', 90, 2305, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aggra - Actionlist - Set Bytes 2 to 2305'),
(4502700, 9, 6, 0, 0, 0, 100, 0, 5000,  5000,  0, 0, '', 1, 6, 0, 1, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Aggra - Actionlist - Say Line 6');

DELETE FROM `creature_text` WHERE `CreatureID` IN (45027, 45028);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(45028, 0, 0, 'I hope you have a strong stomach.  Travelling through the breach is not for the weak.', 12, 0, 100, 4, 0, 22606, 45169, 0, 'Aggra'),
(45028, 1, 0, 'We''re at the center of the Maelstrom, the rift between Deepholm and our world.  Watch as it threatens to tear our world apart!', 12, 0, 100, 4, 0, 22607, 45170, 0, 'Aggra'),
(45028, 2, 0, 'Let us hope Thrall and the others can contain it while you''re inside.', 12, 0, 100, 4, 0, 22608, 45171, 0, 'Aggra'),
(45028, 3, 0, 'This is it!  Brace yourself!', 14, 0, 100, 4, 0, 22609, 45172, 0, 'Aggra'),
(45027, 0, 0, 'You made it!  Good!', 12, 0, 100, 4, 0, 22610, 45175, 0, 'Aggra'),
(45027, 1, 0, 'This is the Temple of Earth.  It''s the most important structure in Deepholm.', 12, 0, 100, 0, 0, 22611, 45176, 0, 'Aggra'),
(45027, 2, 0, 'There was once a Titan-made stone inside.  It was known as the World Pillar.  The name was literal.  It bore the weight of all the elemental and magnetic forces in Deepholm.', 12, 0, 100, 0, 0, 22612, 45180, 0, 'Aggra'),
(45027, 3, 0, 'It was shattered when Deathwing broke through the dome above and created the rift between the two worlds.  All of Deepholm is going to collapse into Azeroth if we do not put the World Pillar back together.', 12, 0, 100, 0, 0, 22613, 45182, 0, 'Aggra'),
(45027, 4, 0, 'The first fragment was going to be delivered to us by a Horde gunship known as the Storm''s Fury.  It never made it here.', 12, 0, 100, 0, 0, 22614, 45186, 0, 'Aggra'),
(45027, 5, 0, 'We''ve taken control of the temple and we''re containing as much of the damage as we can.  Go inside and speak to Maruut; he''s in charge.', 12, 0, 100, 0, 0, 22615, 45187, 0, 'Aggra'),
(45027, 6, 0, 'We are all counting on you.', 12, 0, 100, 0, 0, 22616, 45191, 0, 'Aggra');

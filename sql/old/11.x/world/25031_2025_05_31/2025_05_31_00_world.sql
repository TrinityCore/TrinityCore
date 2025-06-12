-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 120922;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(120922, 0, 0, 'I hope this works.', 12, 0, 100, 669, 0, 112099, 129993, 0, 'Lady Jaina Proudmoore to Player');

-- Scene
DELETE FROM `scene_template` WHERE `SceneId`=1954;
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(1954, 27, 2103, 0);

UPDATE `scene_template` SET `ScriptName` = 'scene_boralus_jainas_procession' WHERE `SceneId` = 1954;

-- Spelltarget pos.
DELETE FROM `spell_target_position` WHERE (`ID`=241526 AND `EffectIndex`=0 AND `OrderIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `OrderIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(241526, 0, 0, 1643, 132.720001220703125, -2710.1298828125, 28.73999977111816406, 60822); -- Spell: 241526 (Teleport to Tol Dagor) Effect 0: 252 (SPELL_EFFECT_TELEPORT_UNITS)

-- SpellArea
DELETE FROM `spell_area` WHERE `area` = 8568 AND `spell` = 281429;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(281429, 8568, 46728, 51341, 0, 0, 2, 0x03, 74, 11);

-- Condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 10832 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 10832, 0, 0, 0, 47, 0, 46728, 2|8|64, 0, 0, 'Apply Phase 10832 if Quest 46728 is in progress | complete | rewarded'),
(26, 10832, 0, 0, 0, 47, 0, 51341, 64, 0, 1, 'Apply Phase 10832 if Quest 51341 is not rewarded');

-- SpellScript names
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_boralus_teleport_off_ship', 'spell_boralus_teleport_to_tol_dagor');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(281460, 'spell_boralus_teleport_off_ship'),
(241526, 'spell_boralus_teleport_to_tol_dagor');

-- Quest
DELETE FROM `quest_details` WHERE `ID`=51341;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(51341, 669, 0, 0, 0, 0, 0, 0, 0, 60822); -- Daughter of the Sea

DELETE FROM `creature_queststarter` WHERE (`id`=120922 AND `quest`=51341);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(120922, 51341, 60822); -- Daughter of the Sea offered by Lady Jaina Proudmoore

DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` = 335474;
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(335474, NULL, 241526, NULL, 1, 0);

DELETE FROM `quest_template_addon` WHERE `ID` = 51341;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(51341, 0, 0, 0, 46728, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Daughter of the Sea

-- Lady Jaina Proudmoore smart ai
SET @ENTRY := 120922;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 51341, 0, 0, 0, 0, 80, 12092200, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Daughter of the Sea (51341) - Self: Start timed action list id #Lady Jaina Proudmoore #0 (12092200) (update out of combat)', '');

-- Timed list 12092200 smart ai
SET @ENTRY := 12092200;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 149, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Become personal clone for Last action invoker for 0 seconds (manual despawn)', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Owner/Summoner: Talk 0 to invoker', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 85, 281460, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Cast spell 281460 on self', '');

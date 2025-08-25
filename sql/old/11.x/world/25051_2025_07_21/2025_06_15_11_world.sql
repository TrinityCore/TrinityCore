-- Template
UPDATE `creature_template` SET `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=101061; -- Archdruid Hamuul Runetotem

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 101061;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(101061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- 101061 (Archdruid Hamuul Runetotem)

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=642, `StaticFlags1`=0x30000000, `StaticFlags3`=0x40000, `VerifiedBuild`=61265 WHERE (`Entry`=101061 AND `DifficultyID`=0); -- 101061 (Archdruid Hamuul Runetotem) - CanSwim, Floating - AllowInteractionWhileInCombat

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`CreatureID`=101061 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(101061, 1, 63052, 0, 0, 0, 0, 0, 0, 0, 0, 61265); -- Archdruid Hamuul Runetotem

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 101061;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(101061, 0, 0, 'Greetings, $n. It is fortunate I found you. Your presence is requested at Moonglade.', 12, 0, 100, 1, 0, 62105, 103448, 0, 'Archdruid Hamuul Runetotem to Player'),
(101061, 1, 0, 'I\'ll meet you there as soon as you conclude your business in Dalaran.', 12, 0, 100, 0, 0, 62106, 103449, 0, 'Archdruid Hamuul Runetotem to Player');

-- Spelltarget
DELETE FROM `spell_target_position` WHERE (`ID`=311897 AND `EffectIndex`=0 AND `OrderIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `OrderIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(311897, 0, 0, 1, 7897.7998046875, -2499.699951171875, 489.29998779296875, 61265); -- Spell: 311897 (Hearth to Moonglade) Effect 0: 252 (SPELL_EFFECT_TELEPORT_UNITS)

-- Quest
DELETE FROM `creature_queststarter` WHERE (`id`=101064 AND `quest` IN (41106,40643)) OR (`id`=101061 AND `quest`=40643);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(101064, 41106, 61265), -- Call of the Wilds offered by Archdruid Hamuul Runetotem
(101064, 40643, 61265), -- A Summons From Moonglade offered by Archdruid Hamuul Runetotem
(101061, 40643, 61265); -- A Summons From Moonglade offered by Archdruid Hamuul Runetotem

DELETE FROM `quest_request_items` WHERE `ID`=41106;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(41106, 0, 0, 0, 0, 'This ritual must succeed, $n.', 61265); -- Call of the Wilds

DELETE FROM `quest_template_addon` WHERE `ID` = 41106;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(41106, 0, 0, 0, 40643, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

DELETE FROM `ui_map_quest_line` WHERE (`UIMapId`=627 AND `QuestLineId`=5638);
INSERT INTO `ui_map_quest_line` (`UIMapId`, `QuestLineId`, `VerifiedBuild`) VALUES
(627, 5638, 61265);

-- Archdruid Hamuul Runetotem smart ai
SET @ENTRY := 101061;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 80, 10106100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Start timed action list id #Archdruid Hamuul Runetotem #0 (10106100) (update out of combat)', ''),
(@ENTRY, 0, 1, 0, 19, 0, 100, 0, 40643, 0, 0, 0, 0, 80, 10106101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest A Summons From Moonglade (40643) - Self: Start timed action list id #Archdruid Hamuul Runetotem #1 (10106101) (update out of combat)', '');

-- Timed list 10106100 smart ai
SET @ENTRY := 10106100;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 36, 53854, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Update template as if it was creature Stormcrow (53854)', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 36, 101061, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Update template as if it was creature Archdruid Hamuul Runetotem (101061)', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Enable gravity', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 29, 0, 180, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Follow Owner/Summoner by distance 0, angle 180', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 137, 20514, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays SpellVisual with SpellVisualKitId: 20514, KitType: 0 for 0 ms', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Owner/Summoner: Talk 0 to invoker', '');

-- Timed list 10106101 smart ai
SET @ENTRY := 10106101;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Follow None by distance 0, angle 0', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Talk 1 to invoker', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 85, 199287, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Cast spell 199287 on self', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 11 seconds - Self: Despawn instantly', '');

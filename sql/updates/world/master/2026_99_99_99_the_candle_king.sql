-- Instance
DELETE FROM `instance_template` WHERE `map`=2651;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(2651, 0, 'instance_darkflame_cleft');

-- Areatriggers
DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (29999, 29904, 29906));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(29999, 0, 33619, 0, 4, 0, 0, 0, 0, -1, 0, 82, NULL, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 'at_the_candle_king_cursed_wax', 59679), -- Spell: 421648 (Cursed Wax)
(29904, 0, 33535, 0, 6, 0, 69049, 0, 0, -1, 0, 0, NULL, 60000, 0, 0, 6, 6, 0, 0, 0, 0, 0, 0, 'at_the_candle_king_molten_wax', 59679), -- Spell: 420691 (Molten Wax)
(29906, 0, 33535, 0, 6, 0, 69050, 0, 0, -1, 0, 0, NULL, 45000, 0, 0, 1.5, 1.5, 0, 0, 0, 0, 0, 0, 'at_the_candle_king_molten_wax', 59679); -- Spell: 420963 (Molten Wax)

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (33535, 33619));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `VerifiedBuild`) VALUES
(33535, 0, 59679),
(33619, 0, 59679);

-- Custom AT
DELETE FROM `areatrigger` WHERE `SpawnId`=888888;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES
(888888, 888888, 1, 2651, '1,2,8,23', 119.2231, -154.7091, 73.8308, 3.152349, 0, 0, 0, '', 'Darkflame Cleft - The Candle King encounter - Candlelight', 66192);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=888888 AND `IsCustom`=1;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `SpeedIsTime`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(888888, 1, 888888, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 0, 1, 30, 50, 5, 30, 50, 5, 0, 0, 'at_the_candle_king_candlelight', 0);

DELETE FROM `areatrigger_template` WHERE `Id`=888888 AND `IsCustom`=1;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(888888, 1, 1, 0, 0, 0);

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (421153, 421156, 420919);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 421153, 0, 0, 51, 0, 5, 209603, 0, '', 0, 0, 0, '', 'Spell \'Candleburn\' can only hit \'Wax Statue\''),
(13, 1, 421156, 0, 0, 51, 0, 5, 209791, 0, '', 0, 0, 0, '', 'Spell \'Candleburn\' can only hit \'Wax Chunk\''),
(13, 1, 420919, 0, 0, 51, 0, 6, 0, 0, '', 0, 0, 0, '', 'Spell \'Eerie Molds\' can only hit player');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_the_candle_king_throw_darkflame_selector', 'spell_the_candle_king_throw_darkflame_missile', 'spell_the_candle_king_eerie_molds_clone_summoner', 'spell_the_candle_king_eerie_molds_selector', 'spell_the_candle_king_cursed_wax', 'spell_the_candle_king_darkflame_pickaxe_selector',
'spell_the_candle_king_darkflame_pickaxe_cast');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(420677, 'spell_the_candle_king_eerie_molds_clone_summoner'),
(420659, 'spell_the_candle_king_eerie_molds_selector'),
(422079, 'spell_the_candle_king_cursed_wax'),
(421274, 'spell_the_candle_king_darkflame_pickaxe_selector'),
(421277, 'spell_the_candle_king_darkflame_pickaxe_cast'),
(420696, 'spell_the_candle_king_throw_darkflame_selector'),
(421250, 'spell_the_candle_king_throw_darkflame_missile');

-- Creature
DELETE FROM `creature_template_addon` WHERE `entry` IN (209791, 209603);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(209791, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 209791 (Wax Chunk)
(209603, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- 209603 (Wax Statue)

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=23 AND `Entry` IN (208745, 209791, 209603));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(208745, 23, 2, 2, 1279, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 59679), -- 208745 (The Candle King) - CanSwim
(209791, 23, 0, 0, 1279, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 59679), -- 209791 (Wax Chunk) - 
(209603, 23, 0, 0, 1279, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 59679); -- 209603 (Wax Statue) - 

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=209791 AND `DifficultyID`=0); -- Wax Chunk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10 WHERE (`Entry`=209603 AND `DifficultyID`=0); -- Wax Statue

UPDATE `creature_template` SET `ScriptName` = 'boss_the_candle_king' WHERE `entry`=208745; 
UPDATE `creature_template` SET `faction`=35, `speed_walk`=0.400000005960464477, `speed_run`=0.142857149243354797, `BaseAttackTime`=1500, `unit_flags`=0x2000300, `unit_flags3`=0x1080001, `AIName`='SmartAI' WHERE `entry`=209791; -- Wax Chunk
UPDATE `creature_template` SET `faction`=35, `speed_walk`=0.400000005960464477, `speed_run`=0.142857149243354797, `BaseAttackTime`=1500, `unit_flags`=0x2000300, `unit_flags3`=0x1080001, `AIName`='SmartAI' WHERE `entry`=209603; -- Wax Statue

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`=208745; 
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(208745, 0, 0, 'You. No. Take. CANDLE!', 14, 0, 100, 0, 0, 247825, 262503, 0, 'The Candle King'),
(208745, 1, 0, 'I mold you now!', 14, 0, 33, 0, 0, 247831, 262509, 0, 'The Candle King'),
(208745, 1, 1, 'I make you candle!', 14, 0, 33, 0, 0, 247829, 262507, 0, 'The Candle King'),
(208745, 1, 2, 'Wax and ruin!', 14, 0, 33, 0, 0, 247830, 262508, 0, 'The Candle King'),
(208745, 2, 0, '|TInterface\\Icons\\INV_Shadowflames_Wave:20|t%s targets you with |cFFFF0000|Hspell:421282|h[Darkflame Pickaxe]|h|r!', 42, 0, 100, 0, 0, 0, 0, 0, 'The Candle King'), -- Unknown broadcast_text
(208745, 3, 0, 'This why I king and you dead.', 14, 0, 33, 0, 0, 247832, 262510	, 0, 'The Candle King'),
(208745, 4, 0, 'You die!', 14, 0, 33, 0, 0, 247826, 262504, 0, 'The Candle King'),
(208745, 4, 1, 'Snuffed out!', 14, 0, 33, 0, 0, 247827, 262505	 , 0, 'The Candle King'),
(208745, 4, 2, 'Weaklings!', 14, 0, 33, 0, 0, 247828, 262506, 0, 'The Candle King'),
(208745, 5, 0, 'But I... the king...', 14, 0, 100, 0, 0, 28232, 262511, 0, 'The Candle King');

-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (209603, 209791) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(209603, 0, 0, 1, '', 11, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 420677, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Wax Statue - On Respawn - Cast \'Eerie Molds\''),
(209603, 0, 1, 2, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 420918, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Wax Statue - On Linked - Cast \'Eerie Molds\''),
(209603, 0, 2, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 426011, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Wax Statue - On Linked - Cast \'Eerie Molds\''),
(209603, 0, 3, 0, '8,23', 11, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 421648, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Wax Statue (Difficulties Mythic and M+) - On Respawn - Cast \'Cursed Wax\''),
(209603, 0, 4, 5, '', 8, 0, 100, 0, 421153, 0, 0, 0, 0, '', 28, 420918, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Wax Statue - On Spellhit - Remove Aura \'Eerie Molds\''),
(209603, 0, 5, 6, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 420959, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Wax Statue - On Linked - Cast \'Molten Wax\''),
(209603, 0, 6, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 420691, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Wax Statue - On Linked - Cast \'Molten Wax\''),
(209603, 0, 7, 0, '8,23', 8, 0, 100, 0, 421153, 0, 0, 0, 0, '', 28, 421648, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Wax Statue (Difficulties Mythic and M+) - On Spellhit - Remove Aura \'Cursed Wax\''),
(209603, 0, 8, 9, '', 8, 0, 100, 0, 421283, 0, 0, 0, 0, '', 11, 420939, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Wax Statue - On Spellhit - Cast \'Rupture\''),
(209603, 0, 9, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 41, 1000, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Wax Statue - On Linked - Despawn after 1 second'),
(209791, 0, 0, 0, '', 11, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 420932, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Wax Chunk - On Respawn - Cast \'Wax Chunk\''),
(209791, 0, 1, 2, '', 8, 0, 100, 0, 421156, 0, 0, 0, 0, '', 11, 420963, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Wax Chunk - On Spellhit - Cast \'Molten Wax\''),
(209791, 0, 2, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 420959, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Wax Chunk - On Linked - Cast \'Molten Wax\'');

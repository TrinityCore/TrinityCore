-- Creature
DELETE FROM `creature_template_difficulty` WHERE (`Entry`=97916 AND `DifficultyID` IN (23, 2));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(97916, 23, 2, 2, 629, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 63906), -- 97916 (Quake) - 
(97916, 2, 2, 2, 628, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 64154); -- 97916 (Quake) - 

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=2, `CreatureDifficultyID`=98421, `TypeFlags`=0x400, `TypeFlags2`=128 WHERE (`Entry`=97916 AND `DifficultyID`=23); -- Quake
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=63906 WHERE (`Entry`=91797 AND `DifficultyID`=0); -- 91797 (King Deepbeard) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `VerifiedBuild`=64154 WHERE (`Entry`=91797 AND `DifficultyID`=0); -- 91797 (King Deepbeard) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `VerifiedBuild`=64154 WHERE (`Entry`=91797 AND `DifficultyID`=2); -- 91797 (King Deepbeard) - CanSwim

UPDATE `creature_template` SET `faction`=14, `speed_walk`=1.60000002384185791, `speed_run`=0.571428596973419189, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags3`=0x80001, `AIName`='SmartAI' WHERE `entry`=97916; -- Quake
UPDATE `creature_template` SET `ScriptName`='boss_king_deepbeard' WHERE `entry`=91797;

-- Instance
DELETE FROM `instance_template` WHERE `map`=1456;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(1456, 0, 'instance_eye_of_azshara');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_king_deepbeard_ground_slam', 'spell_king_deepbeard_gaseous_bubbles');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(193093, 'spell_king_deepbeard_ground_slam'),
(193018, 'spell_king_deepbeard_gaseous_bubbles');

-- Areatrigger
DELETE FROM `areatrigger_template` WHERE `Id`= 9683;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `VerifiedBuild`) VALUES
(9683, 0, 62438);

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` = 4968);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`,  `VerifiedBuild`) VALUES
(4968, 0, 9683, 0, 6, 0, 0, 0, 0, -1, 0, 0, NULL, 20000, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 'at_king_deepbeard_call_the_seas', 63906); -- Spell: 193054 (Call the Seas)

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=193051;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 193051, 0, 0, 51, 0, 5, 97844, 0, '', 0, 0, 0, '', 'Spell \'Call the Seas\' can only hit \'Call the Seas\'');

-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=97916 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(97916, 0, 0, 1, '', 11, 0, 100, 0, 0, 0, 0, 0, 0, '', 8, 0, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Quake - On Respawn - Set ReactState - React Passive'),
(97916, 0, 1, 2, '', 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 193175, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Quake - On Respawn - Cast \'Quake\''),
(97916, 0, 2, 0, '', 61, 0, 100, 1, 0, 0, 0, 0, 0, '', 11, 193159, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Quake - On Respawn - Cast \'Quake\''),
(97916, 0, 3, 0, '8,23', 11, 0, 100, 0, 0, 0, 0, 0, 0, '', 11, 193167, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Quake (Difficulties Mythic and M+) - On Respawn - Cast \'Aftershock\'');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`=91797;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(91797, 0, 0, 'You killed my son! Your punishment is death!', 14, 0, 50, 0, 0, 54317, 102316, 0, 'King Deepbeard to Player'),
(91797, 0, 1, 'You weaklings will drown beneath these waves!', 14, 0, 50, 0, 0, 54316, 102315, 0, 'King Deepbeard to Player'),
(91797, 1, 0, 'How long can you hold your breath, I wonder?', 14, 0, 100, 0, 0, 54312, 102305, 0, 'King Deepbeard'),
(91797, 2, 0, 'Before the crashing waves come the quake!', 14, 0, 33, 0, 0, 54314, 102307, 0, 'King Deepbeard'),
(91797, 2, 1, 'Pity you cannot survive without air!', 14, 0, 33, 0, 0, 54313, 102306, 0, 'King Deepbeard'),
(91797, 2, 2, 'The earth trembles before the rising tide!', 14, 0, 33, 0, 0, 54315, 102308, 0, 'King Deepbeard'),
(91797, 3, 0, '|TInterface\\Icons\\spell_frost_summonwaterelemental:20|t%s begins to cast |cFFFF0000|Hspell:193051|h[Call the Seas]|h|r!', 41, 0, 100, 0, 0, 54164, 99824, 0, 'King Deepbeard'),
(91797, 4, 0, 'The ocean will sweep you away!', 14, 0, 50, 0, 0, 54164, 102302, 0, 'King Deepbeard'),
(91797, 4, 1, 'Seas! Obey my command!', 14, 0, 50, 0, 0, 54310, 102303, 0, 'King Deepbeard'),
(91797, 5, 0, '%s goes into a frenzy!', 16, 0, 100, 0, 0, 54311, 38630, 0, 'King Deepbeard'),
(91797, 6, 0, 'BUURRRP', 14, 0, 100, 0, 0, 54311, 102304, 0, 'King Deepbeard'),
(91797, 7, 0, 'I failed... but my Queen will NOT.', 14, 0, 25, 0, 0, 54319, 102312, 0, 'King Deepbeard to Player'),
(91797, 7, 1, 'You haven\'t won. She is almost here...', 14, 0, 25, 0, 0, 54318, 102311, 0, 'King Deepbeard to Player'),
(91797, 7, 2, 'The oceans rest... but the wind still rises against you.', 14, 0, 25, 0, 0, 54320, 102309, 0, 'King Deepbeard to Player'),
(91797, 7, 3, 'Gaaah... The winds will finish you, intruders.', 14, 0, 25, 0, 0, 54322, 102310, 0, 'King Deepbeard to Player'),
(91797, 8, 0, 'Blood repays blood.', 14, 0, 50, 0, 0, 54329, 102314, 0, 'King Deepbeard'),
(91797, 8, 1, 'Justice for the son you murdered!', 14, 0, 50, 0, 0, 54326, 102313, 0, 'King Deepbeard'),
(91797, 9, 0, 'This was as inevitable as the tides, fools.', 14, 0, 100, 0, 0, 54332, 102317, 0, 'King Deepbeard');

-- Stratholme - Baron Rivendare - Set position for each Raise Dead spell (1-6)
DELETE FROM `spell_target_position` WHERE `ID` BETWEEN 17475 AND 17480;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES 
(17475, 0, 329, 4017.403809, -3339.703369, 115.057655, 5.487860, 0),
(17476, 0, 329, 4013.189209, -3351.808350, 115.052254, 0.134280, 0),
(17477, 0, 329, 4017.738037, -3363.478016, 115.057274, 0.723313, 0),
(17478, 0, 329, 4048.877197, -3363.223633, 115.054253, 3.627735, 0),
(17479, 0, 329, 4051.777588, -3350.893311, 115.055351, 3.066176, 0),
(17480, 0, 329, 4048.375977, -3339.966309, 115.055222, 2.457497, 0);

-- Stratholme - Baron Rivendare - Kill Skeleton (if alive) and Heal himself
DELETE FROM `conditions` WHERE `SourceEntry` = 17471;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `Comment`) VALUES 
(13, 1, 17471, 0, 0, 29, 1, 11197, 50, 1, 0, 0, 0, 'Stratholme - Baron Rivendare - Kill Skeleton (if alive) and Heal himself');

-- Stratholme - Baron Rivendare - Adding Unholy Aura to Baron Rivendare
DELETE FROM `creature_template_addon` WHERE `entry` = 10440;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(10440, 0, 0, 0, 0, 0, 17467);

-- Stratholme - Baron Rivendare - Unholy Aura does not trigger combat (Aura and Trigger of Aura)
SET @SPELL_ATTR0_CU_NO_INITIAL_THREAT = 16;
DELETE FROM `spell_custom_attr` WHERE `entry` IN (17466, 17467);
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(17466, @SPELL_ATTR0_CU_NO_INITIAL_THREAT),
(17467, @SPELL_ATTR0_CU_NO_INITIAL_THREAT);

-- Stratholme - Baron Rivendare - Add missing emotes
DELETE FROM `creature_text` WHERE `CreatureID` IN (10440);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(10440, 0, 0, '%s raises an undead servant back to life!', 14, 0, 0, 0, 0, 0, 0, 0, 'Baron Rivendare - EMOTE_RAISE_DEAD'),
(10440, 1, 0, '%s attempts to cast Death Pact on his servants!', 14, 0, 0, 0, 0, 0, 0, 0, 'Baron Rivendare - EMOTE_DEATH_PACT');

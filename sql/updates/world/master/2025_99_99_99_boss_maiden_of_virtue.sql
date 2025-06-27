UPDATE `creature_template` SET `ScriptName`='boss_rtk_maiden_of_virtue' WHERE `entry`=113971;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_maiden_of_virtue_rtk_sacred_ground', 'spell_maiden_of_virtue_rtk_holy_bulwark');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(227793, 'spell_maiden_of_virtue_rtk_sacred_ground'),
(227817, 'spell_maiden_of_virtue_rtk_holy_bulwark');

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` = 8812);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(8812, 0, 12880, 0, 2, 0, 2537, 0, 0, -1, 0, 86, 0, 180000, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 'at_maiden_of_virtue_rtk_sacred_ground', 61609); -- Spell: 227789 (Sacred Ground)

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` = 12880);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(12880, 0, 0, 61609);

DELETE FROM `creature_text` WHERE `CreatureID` = 113971;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(113971, 0, 0, 'And so begins your purification!', 14, 0, 100, 0, 0, 77786, 123837, 0, 'Maiden of Virtue'),
(113971, 0, 1, 'The stench of corruption is upon you!', 14, 0, 100, 0, 0, 77787, 123840, 0, 'Maiden of Virtue'),
(113971, 1, 0, 'The lesson is complete.', 14, 0, 100, 0, 0, 77788, 123843, 0, 'Maiden of Virtue'),
(113971, 1, 1, 'A pure mind is an orderly mind.', 14, 0, 100, 0, 0, 77789, 123844, 0, 'Maiden of Virtue'),
(113971, 2, 0, 'Purified!', 14, 0, 100, 0, 0, 77784, 123827, 0, 'Maiden of Virtue'),
(113971, 2, 1, 'A teachable moment.', 14, 0, 100, 0, 0, 77785, 123830, 0, 'Maiden of Virtue'),
(113971, 3, 0, 'All shall be sanctified!', 14, 0, 100, 0, 0, 77775, 123772, 0, 'Maiden of Virtue'),
(113971, 4, 0, '|TInterface\\Icons\\Spell_Holy_InnerFire:20|t%s is casting |cFFFF0000|Hspell:227789|h[Sacred Ground]|h|r at you!', 42, 0, 100, 0, 0, 0, 123100, 0, 'Maiden of Virtue'),
(113971, 5, 0, 'The righteous have nothing to fear!', 14, 0, 100, 0, 0, 77778, 123775, 0, 'Maiden of Virtue'),
(113971, 5, 1, 'Step into the light, mortals!', 14, 0, 100, 0, 0, 77779, 123807, 0, 'Maiden of Virtue'),
(113971, 6, 0, 'By fire be cleansed!', 14, 0, 100, 0, 0, 77777, 123774, 0, 'Maiden of Virtue'),
(113971, 7, 0, '|TInterface\\Icons\\Spell_Holy_PrayerOfHealing:20|t%s is casting |cFFFF0000|Hspell:227508|h[Mass Repentance]|h|r!', 41, 0, 100, 0, 0, 0, 123101, 0, 'Maiden of Virtue'),
(113971, 8, 0, 'Hold, mortals! Open your hearts to virtue!', 14, 0, 100, 0, 0, 77780, 123808, 0, 'Maiden of Virtue'),
(113971, 9, 0, 'Renounce your greed and perversion!', 14, 0, 100, 0, 0, 77781, 123811, 0, 'Maiden of Virtue'),
(113971, 10, 0, 'Repent... or DIE!', 14, 0, 100, 0, 0, 77782, 123814, 0, 'Maiden of Virtue'),
(113971, 11, 0, 'I will... never... relent...', 14, 0, 100, 0, 0, 77790, 123845, 0, 'Maiden of Virtue'),
(113971, 11, 1, 'You are all... as corrupt... as the Guardian...', 14, 0, 100, 0, 0, 77791, 123846, 0, 'Maiden of Virtue');

DELETE FROM `instance_template` WHERE `map`=1651;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(1651, 0, 'instance_return_to_karazhan');

DELETE FROM `instance_template` WHERE `map`=2236;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(2236, 0, 'instance_darkmaul_citadel');

DELETE FROM `areatrigger_template` WHERE (`Id`=22171 AND `IsCustom`=0);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(22171, 0, 0, 49570);

DELETE FROM `areatrigger_create_properties` WHERE (`Id`=18034 AND `IsCustom`=0);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `SpeedIsTime`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(18034, 0, 22171, 0, 0, 0, 0, 13613, 0, -1, 0, 0, NULL, 6000, 6, 1, 4, 3, 3, 6, 6, 0.300000011920928955, 0.300000011920928955, 0, 0, 'at_tunk_seismic_slam', 49570); -- Spell: 308455 (Seismic Slam)

UPDATE `creature_template` SET `ScriptName`='boss_tunk' WHERE `entry`=157300;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN('spell_tunk_seismic_slam_selector', 'spell_tunk_interrupting_shout');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(308454, 'spell_tunk_seismic_slam_selector'),
(321240, 'spell_tunk_interrupting_shout');

DELETE FROM `creature_text` WHERE `CreatureID`=157300;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(157300, 0, 0, '|TINTERFACE\\ICONS\\Ability_Earthen_Pillar.blp:20|t Avoid Tunk\'s |cFFFF0404|Hspell:308463|h[Seismic Slam]|h|r by moving to the left or right!', 42, 0, 100, 0, 0, 0, 0, 0, 'Tunk to Player'), -- Missing BroadcastTextId
(157300, 1, 0, '|TINTERFACE\\ICONS\\WARRIOR_DISRUPTINGSHOUT.BLP:20|t Some spells can interrupt your casting. Stop casting to avoid being interrupted by |cFFFF0404|Hspell:321240|h[Interrupting Shout]|h|r!', 42, 0, 100, 0, 0, 0, 0, 0, 'Tunk to Player'); -- Missing BroadcastTextId

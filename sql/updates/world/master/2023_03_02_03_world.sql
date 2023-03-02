-- Leymor
DELETE FROM `creature_text` WHERE `CreatureID` = 186644;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(186644, 0, 0, 'Leymor awakens as the stasis ritual is interrupted.', 41, 0, 100, 0, 0, 0, 0, 0, 'Leymor to Player');

UPDATE `creature_template` SET `unit_flags` = `unit_flags` & ~ (0x100 | 0x200), `AIName` = '', `ScriptName` = 'boss_leymor' WHERE `entry` = 186644;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_arcane_tender' WHERE `entry` = 191164;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_volatile_sapling' WHERE `entry` = 196559;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_ley_line_sprouts', `flags_extra` = 128 WHERE `entry` = 190509;

UPDATE `creature_template_addon` SET `auras` = '' WHERE `entry` = 186644;

DELETE FROM `instance_template` WHERE `map` = 2515;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(2515, 0, 'instance_azure_vault');

DELETE FROM `creature_template_addon` WHERE `entry` = 190509;

DELETE FROM `areatrigger_template` WHERE (`IsServerSide`=0 AND `Id` IN (29766, 29888, 29793));
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `VerifiedBuild`) VALUES
(29766, 0, 0, 6, 5, 5, 0, 0, 0, 0, 0, 0, 47213),
(29888, 0, 0, 2, 4, 4, 0, 0, 0, 0, 0, 0, 47213),
(29793, 0, 0, 0, 100, 100, 0, 0, 0, 0, 0, 0, 47213);

DELETE FROM `areatrigger_create_properties` WHERE `Id` IN (25356, 25515, 25390);
INSERT INTO `areatrigger_create_properties` (`Id`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(25356, 29766, 0, 33927, 0, 0, -1, 0, 352, 0, 300000, 0, 5, 5, 0, 0, 0, 0, 0, 0, 47213), -- SpellId : 374161
(25515, 29888, 0, 34322, 0, 0, -1, 0, 352, 0, 15000, 0, 4, 4, 0, 0, 0, 0, 0, 0, 47213), -- SpellId : 375647
(25390, 29793, 0, 0, 0, 0, -1, 0, 0, 0, 750, 0, 100, 100, 0, 0, 0, 0, 0, 0, 47213); -- SpellId : 375749

UPDATE `areatrigger_create_properties` SET `ScriptName` = 'at_leymor_arcane_eruption' WHERE `Id` = 25390;

DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId` IN (29766, 29888) AND `IsServerSide` = 0;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsServerSide`, `ActionType`, `ActionParam`, `TargetType`) VALUES 
(29766, 0, 0, 374523, 2),
(29888, 0, 0, 375649, 2);

DELETE FROM `spell_script_names` WHERE `spell_id` IN (374364, 375652, 375732, 374567, 374720, 375591, 386660);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(374364, 'spell_ley_line_sprouts'),
(375652, 'spell_wild_eruption'),
(375732, 'spell_stasis_ritual'),
(374567, 'spell_explosive_brand'),
(374720, 'spell_consuming_stomp'),
(375591, 'spell_sappy_burst'),
(386660, 'spell_erupting_fissure');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13 AND `SourceGroup` = 1 AND `SourceEntry` = 375738) OR (`SourceTypeOrReferenceId` = 13 AND `SourceGroup` = 1 AND `SourceEntry` = 375732) OR (`SourceTypeOrReferenceId` = 13 AND `SourceGroup` = 1 AND `SourceEntry` = 375652) OR (`SourceTypeOrReferenceId` = 13 AND `SourceGroup` = 2 AND `SourceEntry` = 374570) OR (`SourceTypeOrReferenceId` = 13 AND `SourceGroup` = 1 AND `SourceEntry` = 374720) OR (`SourceTypeOrReferenceId` = 13 AND `SourceGroup` = 1 AND `SourceEntry` = 394154);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 375738, 0, 0, 31, 0, 3, 186644, 0, 0, 0, 0, '', 'Spell 375738 can only hit Leymor'),
(13, 1, 375732, 0, 0, 31, 0, 3, 186644, 0, 0, 0, 0, '', 'Spell 375732 can only hit Leymor'),
(13, 1, 375652, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Spell 375652 can only hit Player'),
(13, 2, 374570, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Spell 374570 can only hit Player'),
(13, 2, 374570, 0, 1, 31, 0, 3, 190509, 0, 0, 0, 0, '', 'Spell 374570 can only hit Ley-Line Sprouts'),
(13, 1, 374720, 0, 0, 31, 0, 3, 190509, 0, 0, 0, 0, '', 'Spell 374720 can only hit Ley-Line Sprouts'),
(13, 1, 394154, 0, 0, 31, 0, 3, 190509, 0, 0, 0, 0, '', 'Spell 394154 can only hit Ley-Line Sprouts');

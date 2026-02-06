DELETE FROM `areatrigger_create_properties` WHERE `Id` IN (18264,26752,26753) AND `IsCustom`=0;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(18264, 0, 22375, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 1000, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 'at_dh_elysian_decree', 63834), -- Spell: 306830 (Elysian Decree)
(26752, 0, 30889, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 1000, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 'areatrigger_dh_sigil_of_spite', 63834), -- Spell: 390163 (Sigil of Spite)
(26753, 0, 30889, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 1000, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 'areatrigger_dh_sigil_of_spite', 63834); -- Spell: 389858 (Sigil of Spite)

DELETE FROM `areatrigger_template` WHERE `Id` IN (22375,30889) AND `IsCustom`=0;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `VerifiedBuild`) VALUES
(22375, 0, 63834),
(30889, 0, 63834);

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dh_repeat_decree_conduit';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dh_elysian_decree';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dh_sigil_of_spite';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(307046, 'spell_dh_repeat_decree_conduit'),
(389860, 'spell_dh_repeat_decree_conduit'),
(307046, 'spell_dh_elysian_decree'),
(389860, 'spell_dh_sigil_of_spite');

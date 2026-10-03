DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_hun_bleak_powder';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_hun_bleak_powder_areatrigger_summon';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(467911, 'spell_hun_bleak_powder'),
(467912, 'spell_hun_bleak_powder_areatrigger_summon');

DELETE FROM `areatrigger_template` WHERE (`Id`=37291 AND `IsCustom`=0);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `VerifiedBuild`) VALUES
(37291, 0, 69933);

DELETE FROM `areatrigger_create_properties` WHERE (`Id`=35089 AND `IsCustom`=0);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `PositionalSoundKitId`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `Roll`, `Pitch`, `Yaw`, `TargetRoll`, `TargetPitch`, `TargetYaw`, `ScriptName`, `VerifiedBuild`) VALUES
(35089, 0, 37291, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 500, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL, 'at_hun_bleak_powder', 69933); -- Spell: 467912 (Bleak Powder)

DELETE FROM `areatrigger_create_properties_polygon_vertex` WHERE (`AreaTriggerCreatePropertiesId`=35089 AND `IsCustom`=0 AND `Idx`=0) OR (`AreaTriggerCreatePropertiesId`=35089 AND `IsCustom`=0 AND `Idx`=1) OR (`AreaTriggerCreatePropertiesId`=35089 AND `IsCustom`=0 AND `Idx`=2) OR (`AreaTriggerCreatePropertiesId`=35089 AND `IsCustom`=0 AND `Idx`=3);
INSERT INTO `areatrigger_create_properties_polygon_vertex` (`AreaTriggerCreatePropertiesId`, `IsCustom`, `Idx`, `VerticeX`, `VerticeY`, `VerticeTargetX`, `VerticeTargetY`, `VerifiedBuild`) VALUES
(35089, 0, 0, -4.4, 5, NULL, NULL, 69933), -- Spell: 467912 (Bleak Powder)
(35089, 0, 1, -4.4, -5, NULL, NULL, 69933), -- Spell: 467912 (Bleak Powder)
(35089, 0, 2, 12, -12, NULL, NULL, 69933), -- Spell: 467912 (Bleak Powder)
(35089, 0, 3, 12, 12, NULL, NULL, 69933); -- Spell: 467912 (Bleak Powder)

DELETE FROM `spell_proc` WHERE `SpellId` IN (467911);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(467911,0x00,9,0x00000000,0x00000000,0x08000000,0x00000000,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0,0,0,0); -- Bleak Powder

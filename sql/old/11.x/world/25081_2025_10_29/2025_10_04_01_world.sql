SET @AREATRIGGERID := 172;

-- Creature
UPDATE `creature_template` SET `ScriptName`='boss_shade_of_medivh' WHERE `entry`=114350;
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x40080000, `ScriptName`='boss_shade_of_medivh_guardians_image' WHERE `entry`=114675; -- Guardian's Image
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x30000100, `VerifiedBuild`=63003 WHERE (`Entry`=114675 AND `DifficultyID`=23); -- 114675 (Guardian's Image) - Sessile, CanSwim, Floating

DELETE FROM `creature_template_movement` WHERE `CreatureId`=114675;
INSERT INTO `creature_template_movement` (`CreatureId`, `HoverInitiallyEnabled`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(114675, 1, 0, 0, NULL);

-- Areatriggers
DELETE FROM `areatrigger_template` WHERE (`IsCustom` IN (0,1) AND `Id` IN (12878, 12916, @AREATRIGGERID+0, @AREATRIGGERID+1));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(12916, 0, 0, 0, 512, 59570),
(12878, 0, 0, 0, 0, 45745),
(@AREATRIGGERID+0, 1, 0, 0, 0, 0),
(@AREATRIGGERID+1, 1, 0, 0, 0, 0);

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (8809, 8848, 8851, 8879));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(8851, 0, 12916, 0, 0, 2618, 0, 0, 0, -1, 0, 0, NULL, 20000, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 'at_shade_of_medivh_flame_wreath', 45745), -- Spell: 228257 (Flame Wreath)
(8809, 0, @AREATRIGGERID+0, 1, 0, 0, 0, 0, 0, -1, 0, 89, NULL, 20000, 0, 4, 40, 40, 1, 1, 0.300000011920928955, 0.300000011920928955, 0, 0, 'at_shade_of_medivh_ceaseless_winter_jump_check', 45745), -- SpellForVisuals: 227779 (Ceaseless Winter)
(8848, 0, 12878, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 20000, 0, 4, 40, 40, 15, 15, 0.300000011920928955, 0.300000011920928955, 0, 0, 'at_shade_of_medivh_ceaseless_winter', 45745), -- SpellForVisuals: 227779 (Ceaseless Winter)
(8879, 0, @AREATRIGGERID+1, 1, 0, 0, 0, 2319, 0, -1, 0, 89, NULL, 20000, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, '', 45745); -- Spell: 228588 (Ceaseless Winter)

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` = 114350;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(114350, 0, 0, 'This is who I am. I was tainted from birth, polluted from before my conception, a bad seed grown to bear bitter fruit.', 14, 0, 100, 0, 0, 77556, 123824, 0, 'Shade of Medivh'),
(114350, 1, 0, 'You\'re just like the others, aren\'t you?', 14, 0, 50, 0, 0, 77558, 123832, 0, 'Shade of Medivh to Player'),
(114350, 1, 1, 'Hello, champions. I\'ve been expecting you.', 14, 0, 50, 0, 0, 77552, 123831, 0, 'Shade of Medivh to Player'),
(114350, 2, 0, '|TInterface\\Icons\\spell_mage_infernoblast:20|tYou are targeted by |cFFF00000|Hspell:227615|h[Inferno Bolt]|h|r!', 42, 0, 100, 0, 0, 77558, 123231, 0, 'Shade of Medivh to Player'),
(114350, 3, 0, 'The inherent nature of fire...', 14, 0, 50, 0, 0, 77561, 123812, 0, 'Shade of Medivh'),
(114350, 3, 1, 'Burn... just like that dragon!', 14, 0, 50, 0, 0, 77570, 123813, 0, 'Shade of Medivh'),
(114350, 4, 0, '|TINTERFACE\\ICONS\\SPELL_SHAMAN_IMPROVEDFIRENOVA:20|tShade of Medivh begins to cast |cFFF00000|Hspell:228269|h[Flame Wreath]|h|r!', 41, 0, 100, 0, 0, 77550, 123526, 0, 'Shade of Medivh'),
(114350, 5, 0, 'It burns, burns, burns!', 14, 0, 50, 0, 0, 77550, 123819, 0, 'Shade of Medivh'),
(114350, 5, 1, 'I suggest staying put.', 14, 0, 50, 0, 0, 77566	, 123820, 0, 'Shade of Medivh'),
(114350, 6, 0, 'Winter is here!', 14, 0, 50, 0, 0, 77572, 123821, 0, 'Shade of Medivh'),
(114350, 6, 1, 'Keep still. Let it end.', 14, 0, 50, 0, 0, 77555, 123822, 0, 'Shade of Medivh to Player'),
(114350, 7, 0, 'So many pieces of me...', 14, 0, 50, 0, 0, 77565, 123817, 0, 'Shade of Medivh'),
(114350, 7, 1, 'Carrion for the birds...', 14, 0, 50, 0, 0, 77562, 123818, 0, 'Shade of Medivh'),
(114350, 8, 0, 'A memory, frozen in time!', 14, 0, 100, 0, 0, 77560, 123809, 0, 'Shade of Medivh to Player'),
(114350, 8, 1, 'The tower needed a new decoration.', 14, 0, 100, 0, 0, 77571, 123810, 0, 'Shade of Medivh to Player'),
(114350, 9, 0, 'A basic spell... but effective.', 14, 0, 100, 0, 0, 77549, 123816, 0, 'Shade of Medivh to Player'),
(114350, 10, 0, 'Just. Gets. Easier.', 14, 0, 33, 0, 0, 77551, 123826, 0, 'Shade of Medivh to Player'),
(114350, 10, 1, 'A fitting end for a thief!', 14, 0, 33, 0, 0, 77554, 123829, 0, 'Shade of Medivh to Player'),
(114350, 10, 2, 'All goes as planned.', 14, 0, 33, 0, 0, 77557, 123828, 0, 'Shade of Medivh to Player'),
(114350, 11, 0, 'You grow weaker... I grow stronger!', 14, 0, 100, 0, 0, 77564, 123815, 0, 'Shade of Medivh to Player'),
(114350, 12, 0, 'Once you get used to it, you can kill friends as easily as anyone else.', 14, 0, 50, 0, 0, 77573, 123834, 0, 'Shade of Medivh to Player'),
(114350, 12, 1, 'You have no idea what it\'s like to do the things I\'ve done. Harsh things. Necessary things.', 14, 0, 50, 0, 0, 77559, 123835, 0, 'Shade of Medivh to Player'),
(114350, 13, 0, 'So... it comes... to this...', 14, 0, 33, 0, 0, 77567, 123838, 0, 'Shade of Medivh to Player'),
(114350, 13, 1, 'Atiesh... will be... splintered...', 14, 0, 3, 0, 0, 77569, 123839, 0, 'Shade of Medivh to Player'),
(114350, 13, 2, 'I fought it... for as long as... I could...', 14, 0, 33, 0, 0, 77563, 123836, 0, 'Shade of Medivh to Player'),
(114350, 14, 0, 'My staff... a relic, yes, but MINE!', 14, 0, 100, 0, 0, 77568, 123833, 0, 'Shade of Medivh to Player');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=228558;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 228558, 0, 0, 51, 0, 5, 114350, 0, '', 0, 0, 0, '', 'Spell \'Reform Visual\' can only hit \'Shade of Medivh\'');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_shade_of_medivh_arcane_bolt_selector', 'spell_shade_of_medivh_basic_primer', 'spell_shade_of_medivh_ceaseless_winter_periodic', 'spell_shade_of_medivh_flame_wreath_selector', 'spell_shade_of_medivh_guardians_image', 'spell_shade_of_medivh_inferno_bolt_marker', 'spell_shade_of_medivh_mana_regen', 'spell_shade_of_medivh_piercing_missiles', 'spell_shade_of_medivh_signature_primer', 'spell_shade_of_medivh_vo_controller', 'spell_shade_of_medivh_vo_controller_cast');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(228992, 'spell_shade_of_medivh_arcane_bolt_selector'),
(227599, 'spell_shade_of_medivh_basic_primer'),
(228237, 'spell_shade_of_medivh_signature_primer'),
(228222, 'spell_shade_of_medivh_ceaseless_winter_periodic'),
(228269, 'spell_shade_of_medivh_flame_wreath_selector'),
(228334, 'spell_shade_of_medivh_guardians_image'),
(228249, 'spell_shade_of_medivh_inferno_bolt_marker'),
(228582, 'spell_shade_of_medivh_mana_regen'),
(227628, 'spell_shade_of_medivh_piercing_missiles'),
(232314, 'spell_shade_of_medivh_vo_controller'),
(227592, 'spell_shade_of_medivh_vo_controller_cast'),
(227615, 'spell_shade_of_medivh_vo_controller_cast');

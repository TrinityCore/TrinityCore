UPDATE `creature_template` SET `faction`=16, `speed_run`=0.285714298486709594, `BaseAttackTime`=2000, `unit_flags`=33554496, `unit_flags2`=2048, `unit_flags3`=524288 WHERE `entry`=136436; -- Burning Soul
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=32800, `unit_flags3`=524288 WHERE `entry`=136330; -- Soul Thorns
UPDATE `creature_template` SET `ScriptName` = 'npc_matron_bryndle' WHERE `entry`=135329;
UPDATE `creature_template` SET `ScriptName` = 'boss_soulbound_goliath' WHERE `entry`=131667;

DELETE FROM `creature_template_addon` WHERE `entry` IN (136436, 136330);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(136436, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '272668'), -- 136436 (Burning Soul) - Burning Fists
(136330, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '267912'); -- 136330 (Soul Thorns) - Soul Thorns

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=265779;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 265779 , 0, 0, 51, 0, 5, 131667, 0, '', 0, 0, 0, '', 'Spell \'Goliath Drain Flavor\' can only hit \'Soulbound Goliath\'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=265743;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 265743, 0, 0, 51, 0, 5, 131667, 0, '', 0, 0, 0, '', 'Spell \'Goliath Drain Flavor\' can only hit \'Soulbound Goliath\'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=265778;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 265778, 0, 0, 51, 0, 5, 135312, 0, '', 0, 0, 0, '', 'Spell \'Goliath Drain Flavor\' can only hit \'Goliath Drain Target Male\''),
(13, 1, 265778, 0, 1, 51, 0, 5, 135313, 0, '', 0, 0, 0, '', 'Spell \'Goliath Drain Flavor\' can only hit \'Goliath Drain Target Heavy\''),
(13, 1, 265778, 0, 2, 51, 0, 5, 135315, 0, '', 0, 0, 0, '', 'Spell \'Goliath Drain Flavor\' can only hit \'Goliath Drain Target Female\'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=265741 ;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 265741, 0, 0, 51, 0, 5, 135312, 0, '', 0, 0, 0, '', 'Spell \'Goliath Drain Flavor\' can only hit \'Goliath Drain Target Male\''),
(13, 1, 265741, 0, 1, 51, 0, 5, 135313, 0, '', 0, 0, 0, '', 'Spell \'Goliath Drain Flavor\' can only hit \'Goliath Drain Target Heavy\''),
(13, 1, 265741, 0, 2, 51, 0, 5, 135315, 0, '', 0, 0, 0, '', 'Spell \'Goliath Drain Flavor\' can only hit \'Goliath Drain Target Female\'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=260570;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 2, 260570, 0, 0, 51, 0, 6, 0, 0, '', 0, 0, 0, '', 'Spell 260570 can only hit Player');

-- Spells
DELETE FROM `spell_script_names` WHERE `spell_id`=265778;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(265778, 'spell_waycrest_manor_goliath_drain_flavor_selector');

DELETE FROM `spell_script_names` WHERE `spell_id`=265741;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(265741, 'spell_waycrest_manor_drain_goliath_essence');

DELETE FROM `spell_script_names` WHERE `spell_id`=265759;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(265759, 'spell_waycrest_manor_splinter_spike_selector');

DELETE FROM `spell_script_names` WHERE `spell_id`=260564;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(260564, 'spell_waycrest_manor_wildfire');

DELETE FROM `spell_script_names` WHERE `spell_id`=261580;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(261580, 'spell_soulbound_goliath_soul_harvest');

DELETE FROM `spell_script_names` WHERE `spell_id`=260551;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(260551, 'spell_soulbound_goliath_soul_thorns_selector');

DELETE FROM `spell_script_names` WHERE `spell_id`=260541;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(260541, 'spell_soulbound_goliath_burning_brush');

-- Areatrigger
DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` = 17041);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(17041, 0, 0, 55261);

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` = 12353);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(12353, 0, 17041, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 15000, 0, 4, 4, 0, 0, 0, 0, 0, 0, 'at_waycrest_manor_wildfire', 55261); -- Spell: 260570 (Wildfire)

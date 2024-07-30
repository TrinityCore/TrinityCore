UPDATE `creature_template` SET `faction`=16, `speed_run`=0.285714298486709594, `BaseAttackTime`=2000, `unit_flags`=33554496, `unit_flags2`=2048, `unit_flags3`=524288 WHERE `entry`=136436; -- Burning Soul
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=32800, `unit_flags3`=524288, `AIName`='SmartAI' WHERE `entry`=136330; -- Soul Thorns
UPDATE `creature_template` SET `ScriptName` = 'npc_matron_bryndle' WHERE `entry`=135329;
UPDATE `creature_template` SET `ScriptName` = 'boss_soulbound_goliath' WHERE `entry`=131667;

DELETE FROM `creature_template_addon` WHERE `entry` = 136436;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(136436, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '272668 272666'); -- 136436 (Burning Soul) - Burning Fists

-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=136330 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(136330, 0, 0, 0, '', 54, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 267912, 2, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Soul Thorn - On Just Created - Self: Cast Spell 267912'),
(136330, 0, 1, 0, '', 6, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 267911, 2, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Soul Thorn - On Died - Self: Cast Spell 267911');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=265779;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 265779 , 0, 0, 51, 0, 5, 131667, 0, '', 0, 0, 0, '', 'Spell \'Goliath Drain Flavor\' can only hit \'Soulbound Goliath\'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=265743;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 265743, 0, 0, 51, 0, 5, 131667, 0, '', 0, 0, 0, '', 'Spell \'Goliath Drain Flavor\' can only hit \'Soulbound Goliath\'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=278792 ;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 278792, 0, 0, 51, 0, 5, 136330, 0, '', 0, 0, 0, '', 'Spell \'Kill Soul Thorn\' can only hit \'Soul Thorn\'');

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
DELETE FROM `spell_script_names` WHERE `spell_id` IN (265778, 265741, 265759, 260564, 261580, 260551, 267907, 260541, 267911);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(265778, 'spell_waycrest_manor_goliath_drain_flavor_selector'),
(265741, 'spell_waycrest_manor_drain_goliath_essence'),
(265759, 'spell_waycrest_manor_splinter_spike_selector'),
(260564, 'spell_waycrest_manor_wildfire'),
(261580, 'spell_soulbound_goliath_soul_harvest'),
(260551, 'spell_soulbound_goliath_soul_thorns_selector'),
(267907, 'spell_soulbound_goliath_soul_thorns_damage'),
(260541, 'spell_soulbound_goliath_burning_brush'),
(267911, 'spell_soulbound_goliath_soul_thorns_remove_stun');

-- Areatrigger
DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` = 17041);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(17041, 0, 0, 55261);

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` = 12353);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(12353, 0, 17041, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 15000, 0, 4, 4, 0, 0, 0, 0, 0, 0, 'at_waycrest_manor_wildfire', 55261); -- Spell: 260570 (Wildfire)

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`=131667;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(131667, 0, 0, 'Flee! There is no hope!', 14, 0, 50, 0, 0, 97529, 145085, 0, 'Soulbound Goliath to Player'),
(131667, 0, 1, 'Beware our torment!', 14, 0, 50, 0, 0, 97527, 145080, 0, 'Soulbound Goliath to Player'),
(131667, 1, 0, 'Together... for eternity.', 14, 0, 33, 0, 0, 97528, 145084, 0, 'Soulbound Goliath'),
(131667, 1, 1, 'There is no escape.', 14, 0, 33, 0, 0, 97530, 145089, 0, 'Soulbound Goliath'),
(131667, 1, 2, 'One of us.', 14, 0, 33, 0, 0, 97531, 145090, 0, 'Soulbound Goliath'),
(131667, 2, 0, 'Beware the thorns!', 14, 0, 50, 0, 0, 97536, 145098, 0, 'Soulbound Goliath'),
(131667, 2, 1, 'The thorns seek your soul!', 14, 0, 50, 0, 0, 97538, 145130, 0, 'Soulbound Goliath'),
(131667, 3, 0, 'Yes! Release us!', 14, 0, 50, 0, 0, 97535, 145094, 0, 'Soulbound Goliath to Soulbound Goliath'),
(131667, 3, 1, 'Fire will be its undoing!', 14, 0, 50, 0, 0, 97535, 145094, 0, 'Soulbound Goliath to Soulbound Goliath'),
(131667, 4, 0, 'Finally... free...', 14, 0, 33, 0, 0, 97533, 145092, 0, 'Soulbound Goliath to Player'),
(131667, 4, 1, 'You have... released us...', 14, 0, 33, 0, 0, 97534, 145093, 0, 'Soulbound Goliath to Player'),
(131667, 4, 2, 'Thank... you...', 14, 0, 33, 0, 0, 97532, 145091, 0, 'Soulbound Goliath to Player'),
(131667, 5, 0, '|TInterface\\Icons\\Ability_Earthen_Pillar.blp:20|t$n is trapped in |cFFF00000|Hspell:260551|h[Soul Thorns]|h|r!', 41, 0, 100, 0, 0, 0, 162151, 0, 'Soulbound Goliath to Player'),
(131667, 6, 0, '|TInterface\\ICONS\\ABILITY_DEATHKNIGHT_SOULREAPER:20|t Soulbound Goliath\'s damage increases with each stack of |cFFFF0404|Hspell:260512|h[Soul Harvest]|h|r!', 42, 0, 100, 0, 0, 0, 156331, 0, 'Soulbound Goliath to Player');

UPDATE `creature_template` SET `unit_flags`=`unit_flags` & ~0x00000100 WHERE `entry`=136330; -- remove UNIT_FLAG_IMMUNE_TO_PC

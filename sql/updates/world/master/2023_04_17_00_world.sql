-- Elder Leaxa
DELETE FROM `instance_template` WHERE `map` = 1841;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(1841, 0, 'instance_underrot');

DELETE FROM `instance_encounters` WHERE `entry` IN (2111, 2112, 2118, 2123);
INSERT INTO `instance_encounters` (`entry`, `creditType`, `creditEntry`, `lastEncounterDungeon`, `comment`) VALUES
(2111, 0, 131318, 0, 'Elder Leaxa'),
(2112, 0, 131817, 0, 'Cragmaw the Infested'),
(2118, 0, 131383, 0, 'Sporecaller Zancha'),
(2123, 0, 133007, 0, 'Unbound Abomination');

UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'boss_elder_leaxa' WHERE `entry` = 131318;
UPDATE `creature_template` SET `faction` = 14, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2099200, `unit_flags3`=17301505, `flags_extra` = 0x00000080 | 0x20000000 , `AIName` = '', `ScriptName` = 'npc_blood_wave_stalker' WHERE `entry`=132398; -- Blood Wave Stalker
UPDATE `creature_template` SET `faction`= 16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200, `unit_flags3`=524288, `AIName` = '', `ScriptName` = 'npc_blood_effigy' WHERE `entry`=134701; -- Blood Effigy

DELETE FROM `creature_template_addon` WHERE `entry` IN (134701, 132398);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(134701, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '272385'), -- 134701 (Blood Effigy) - Blood Mirror
(132398, 0, 0, 0, 0, 0, 1, 0, 0, 12224, 0, 0, 3, ''); -- 132398 (Blood Wave Stalker) - Creeping Rot

DELETE FROM `creature_template_movement` WHERE `CreatureID` = 132398;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(132398, 1, 0, 1, 0, 0, 0, NULL);

-- AreaTrigger
DELETE FROM `areatrigger_template` WHERE `IsServerSide`=0 AND `Id` = 17135;
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `VerifiedBuild`) VALUES
(17135, 0, 4, 4, 2.5, 2.5, 20, 20, 0.300000011920928955, 0.300000011920928955, 0, 0, 28153);

DELETE FROM `areatrigger_create_properties` WHERE `Id` = 12454;
INSERT INTO `areatrigger_create_properties` (`Id`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(12454, 17135, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 4, 2.5, 2.5, 20, 20, 0.300000011920928955, 0.300000011920928955, 0, 0, 28153); -- SpellId : 261496

DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId` = 17135 AND `IsServerSide` = 0;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsServerSide`, `ActionType`, `ActionParam`, `TargetType`) VALUES 
(17135, 0, 1, 261498, 2);

DELETE FROM `creature_text` WHERE `CreatureID` = 131318;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(131318, 0, 0, 'For de glory of G\'huun!', 14, 0, 100, 0, 0, 101028, 148173, 0, 'Elder Leaxa to Player'),
(131318, 1, 0, 'G\'huun\'s power take you!', 14, 0, 100, 0, 0, 101027, 148180, 0, 'Elder Leaxa'),
(131318, 2, 0, 'Rot and wither!', 14, 0, 100, 0, 0, 101026, 148211, 0, 'Elder Leaxa to Player'),
(131318, 3, 0, 'G\'huun be everywhere!', 14, 0, 100, 0, 0, 101025, 148212, 0, 'Elder Leaxa'),
(131318, 4, 0, '|TINTERFACE\\ICONS\\INV_TikiMan2_Bloodtroll.blp:20|t Elder Leaxa begins to cast |cFFF00000|Hspell:264603|h[Blood Mirror]|h|r!', 41, 0, 100, 0, 0, 101025, 157334, 0, 'Elder Leaxa'),
(131318, 5, 0, 'My power grows!', 14, 0, 100, 0, 0, 101031, 95739, 0, 'Elder Leaxa to Player');

-- SpellScripts
DELETE FROM `spell_script_names` WHERE `spell_id` IN (260879, 264747, 264757, 260889, 261496, 261498, 264603);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(260879, 'spell_taint_of_ghuun'),
(264747, 'spell_sanguine_feast_selector'),
(264757, 'spell_taint_of_ghuun'),
(260889, 'spell_creeping_rot_selector'),
(261496, 'spell_creeping_rot_aura'),
(261498, 'spell_taint_of_ghuun'),
(264603, 'spell_blood_mirror_selector');

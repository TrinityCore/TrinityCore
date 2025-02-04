DELETE FROM `creature` WHERE `guid` IN (7000217, 7000212, 7000196);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=0x10000000, `VerifiedBuild`=58773 WHERE (`Entry`=122965 AND `DifficultyID`=0); -- 122965 (Vol'kaal) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=502, `StaticFlags1`=0x20000100, `VerifiedBuild`=58773 WHERE (`Entry`=125977 AND `DifficultyID`=0); -- 125977 (Reanimation Totem) - Sessile, Floating - CannotTurn
UPDATE `creature_template` SET `unit_flags2`=0x0, `unit_flags3`=0x40000000, `ScriptName`='npc_volkaal_reanimation_totem' WHERE `entry`=125977; -- Reanimation Totem
UPDATE `creature_template` SET `unit_flags2`=0x800, `ScriptName`='boss_volkaal' WHERE `entry`=122965; -- Vol'kaal
UPDATE `creature_template_addon` SET `emote`=64, `auras`='250192' WHERE `entry`=122965; -- 122965 (Vol'kaal) - Bad Voodoo

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` = 250229;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 250229, 0, 0, 51, 0, 5, 125977, 0, '', 0, 0, 0, '', 'Spell \'Soul Anchor\' can only hit \'Reanimation Totem\'');

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` = 11243);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES
(11243, 0, 16029, 0, 2, 0, 3477, 0, 0, -1, 0, 209, NULL, 60000, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 'at_volkaal_rapid_decay', 53989); -- Spell: 250696 (Rapid Decay)

DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` = 16029);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(16029, 0, 0, 53989);

DELETE FROM `spell_script_names` WHERE `spell_id` IN (250372, 250368, 250241, 250229, 259531, 250708, 250258);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(250372, 'spell_volkaal_lingering_nausea'),
(250368, 'spell_volkaal_noxious_stench'),
(250241, 'spell_volkaal_rapid_decay'),
(259531, 'spell_volkaal_reanimate'),
(250229, 'spell_volkaal_soul_anchor'),
(250708, 'spell_volkaal_toxic_leap_selector'),
(250258, 'spell_volkaal_toxic_leap');

DELETE FROM `creature_text` WHERE `CreatureID`=122965;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(122965, 0, 0, 'You?! I tear you apart!', 14, 0, 100, 0, 0, 97344, 140446, 0, 'Vol\'kaal - Enter Combat'),
(122965, 1, 0, 'You die with me!', 14, 0, 100, 0, 0, 97349, 140453, 0, 'Vol\'kaal - Decay'),
(122965, 2, 0, 'Master gonna build me again...', 14, 0, 100, 0, 0, 97345, 140457, 0, 'Vol\'kaal - Death'),
(122965, 3, 0, 'You be in pieces.', 14, 0, 100, 0, 0, 97346, 140454, 0, 'Vol\'kaal - Slay'),
(122965, 3, 1, 'Flesh for master!', 14, 0, 100, 0, 0, 97347, 140455, 0, 'Vol\'kaal - Slay'),
(122965, 4, 0, 'Master take your parts. Make me stronger!', 14, 0, 100, 0, 0, 97348, 140456, 0, 'Vol\'kaal - Evade');

DELETE FROM `creature_summon_groups` WHERE `summonerId`=122965;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`, `Comment`) VALUES
(122965, 0, 0, 125977, -636.189, 2316.12, 709.963, 3.1168, 8, 0, 'Vol\'kaal - Group 0 - Reanimation Totem'),
(122965, 0, 0, 125977, -591.24, 2292.44, 709.968, 3.1168, 8, 0, 'Vol\'kaal - Group 0 - Reanimation Totem'),
(122965, 0, 0, 125977, -636.028, 2269.22, 709.974, 3.1168, 8, 0, 'Vol\'kaal - Group 0 - Reanimation Totem');

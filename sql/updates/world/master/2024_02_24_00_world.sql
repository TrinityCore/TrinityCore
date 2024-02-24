SET @OGUID := 9003864;

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 378473, 2570, 13769, 13806, '0', 0, 0, 5739.970703125, -3023.970458984375, 251.0890045166015625, 3.194002151489257812, 0, 0, -0.99965667724609375, 0.026201646775007247, 120, 255, 1, 53212), -- Starting Room Collision (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+1, 378473, 2570, 13769, 13806, '0', 0, 0, 5754.30029296875, -3056.350830078125, 251.0890045166015625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 53212), -- Starting Room Collision (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+2, 378473, 2570, 13769, 13806, '0', 0, 0, 5818.52978515625, -3054.560791015625, 251.279998779296875, 5.480334281921386718, 0, 0, -0.39073085784912109, 0.920504987239837646, 120, 255, 1, 53212), -- Starting Room Collision (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+3, 378473, 2570, 13769, 13806, '0', 0, 0, 5787.44970703125, -3069.34033203125, 251.08502197265625, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 53212); -- Starting Room Collision (Area: The War Creche - Difficulty: 0) CreateObject1

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 32 AND `SourceGroup` = 378473 AND `SourceEntry` = 8);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES 
(32, 8, 378473, 0, 0, 48, 0, 421735, 0, 1, 1, 'Spawn of gameobject with entry 378473 requires Quest 64864 objective 421735 complete');

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (187223 /*187223 (Kodethi) - Stasis*/, 181494 /*181494 (Dervishian) - Stasis*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(181494, 0, 0, 0, 0, 0, 1, 0, 0, 23987, 0, 0, 0, '382137'), -- 181494 (Dervishian) - Stasis
(187223, 0, 0, 0, 0, 0, 1, 0, 0, 23987, 0, 0, 0, '382137'); -- 187223 (Kodethi) - Stasis

DELETE FROM `quest_template_addon` WHERE `ID` = 64864;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(64864, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 'quest_awaken_dracthyr');

DELETE FROM `gameobject_template_addon` WHERE `entry`=378473;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(378473, 114, 0, 0, 0); -- Starting Room Collision

-- SpellScript names
DELETE FROM `spell_script_names` WHERE `spell_id` IN (369730, 370111, 369744);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(369730, 'spell_dracthyr_summon_dervishian'),
(370111, 'spell_dracthyr_summon_dervishian'),
(369744, 'spell_dracthyr_login');

-- SpellArea
DELETE FROM `spell_area` WHERE `spell` IN (369731, 370112) AND `area` = 13806;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(369731, 13806, 64864, 0, 0, 0, 2, 3, 2|8, 0),
(370112, 13806, 64864, 0, 0, 0, 2, 3, 2|8, 0);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceEntry` IN (369730, 370111));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES 
(17, 0, 369730, 0, 0, 6, 0, 469, 0, 0, 0, 'Allow spellcast if caster is Team Alliance'),
(17, 0, 370111, 0, 0, 6, 0, 67, 0, 0, 0, 'Allow spellcast if caster is Team Horde');

-- AreaTrigger
DELETE FROM `areatrigger_template` WHERE `IsCustom`=0 AND `Id` = 30308;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(30308, 0, 0, 53212);

DELETE FROM `areatrigger_create_properties` WHERE `IsCustom`=0 AND `Id` = 26052;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(26052, 0, 30308, 0, 4, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 53212); -- Spell: 382137 (Stasis)

UPDATE `areatrigger_create_properties` SET `ScriptName` = 'at_dracthyr_stasis_feedback' WHERE `Id` = 26052 AND `IsCustom` = 0;

SET @CONDREFID := 40001;
SET @ATID := 99;
SET @ATPROPERTIESID := 89;
SET @ATSPAWNID := 102;

-- Areatrigger templates
DELETE FROM `areatrigger_template` WHERE `Id`=@ATID+0 AND `IsCustom`=1;
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `ActionSetId`, `ActionSetFlags`, `VerifiedBuild`) VALUES
(@ATID+0, 1, 1, 0, 0, 0);

DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId`=@ATID+0 AND `IsCustom`=1;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsCustom`, `ActionType`, `ActionParam`, `TargetType`) VALUES
(@ATID+0, 1, 0, 130412, 0);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=@ATPROPERTIESID+0 AND `IsCustom`=1;
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(@ATPROPERTIESID+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 0, 20, 20, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `areatrigger` WHERE `SpawnId`=@ATSPAWNID+0;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `Comment`, `VerifiedBuild`) VALUES
(@ATSPAWNID+0, @ATPROPERTIESID+0, 1, 1, '0', 1663.346, -4353.692, 26.3505, 0, 1, 0, 0, 'Orgrimmar - Grommash Hold - Art of War Movie Aura Trigger', 0);

-- Spells
UPDATE `spell_target_position` SET `VerifiedBuild`=56819 WHERE (`ID`=130409 AND `EffectIndex`=2);

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_art_of_war_movie_aura';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(130412, 'spell_art_of_war_movie_aura');

UPDATE `quest_template_addon` SET `SourceSpellID`=175293 WHERE `ID` IN (29611,29612);

-- Smart scripts
DELETE FROM `areatrigger_scripts` WHERE `entry`=8463;
INSERT INTO `areatrigger_scripts` VALUES
(8463, 'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid`=8463 AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8463,2,0,0,'',46,0,100,0,0,0,0,0,0,'',134,130412,0,0,0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Areatrigger 8463 - On trigger - Invoker casts ''Art of War Movie Aura''');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=30 AND `SourceEntry`=8463;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=28 AND `SourceGroup`=@ATID+0 AND `SourceEntry`=1;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=-@CONDREFID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(30,0,8463,0,0,6,0,67,0,0,'',0,0,0,'',' Areatrigger 8190 triggers if player is Horde'),
(30,0,8463,0,0,-@CONDREFID,0,0,0,0,'',0,0,0,'','Areatrigger 8190 triggers if condition reference 40001 is fulfilled'),
(28,@ATID+0,1,0,0,6,0,67,0,0,'',0,0,0,'',' Areatrigger 97 triggers if player is Horde'),
(28,@ATID+0,1,0,0,-@CONDREFID,0,0,0,0,'',0,0,0,'','Areatrigger 97 triggers if condition reference 40001 is fulfilled'),
(-@CONDREFID,0,0,0,0,47,0,29611,8,0,'',0,0,0,'','Apply condition reference if quest 29611 is taken'),
(-@CONDREFID,0,0,0,1,47,0,29612,8,0,'',0,0,0,'','Apply condition reference if quest 29612 is taken'),
(-@CONDREFID,0,0,0,2,47,0,49538,8,0,'',0,0,0,'','Apply condition reference if quest 49538 is taken'),
(-@CONDREFID,0,0,0,3,47,0,49852,8,0,'',0,0,0,'','Apply condition reference if quest 49852 is taken'),
(-@CONDREFID,0,0,0,4,47,0,60126,8,0,'',0,0,0,'','Apply condition reference if quest 60126 is taken');

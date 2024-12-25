SET @CONDREFID := 40004;

-- Spells
DELETE FROM `spell_target_position` WHERE (`EffectIndex`=2 AND `ID`=130805);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(130805, 2, 0, -8450.73046875, 343.7130126953125, 135.9799957275390625, 57534); -- Spell: 130805 (MoP: Alliance Intro Movie PLAY) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_the_kings_command_movie_aura');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(130804, 'spell_the_kings_command_movie_aura');

-- Smart scripts
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=1750;

DELETE FROM `smart_scripts` WHERE `entryorguid`=1750 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1750,0,0,0,'',19,0,100,0,29547,0,0,0,0,'',134,130804,0x2,(0x20 | 0x40000),0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Grand Admiral Jes-Tereth - On quest ''The King''s Command'' taken - Invoker casts ''The King''s Command Movie Aura''');

DELETE FROM `areatrigger_scripts` WHERE `entry` IN (7045, 7046);
INSERT INTO `areatrigger_scripts` VALUES
(7045, 'SmartTrigger'),
(7046, 'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (7045, 7046) AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7045,2,0,0,'',46,0,100,0,0,0,0,0,0,'',134,130804,0x2,(0x20 | 0x40000),0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Areatrigger 7045 - On trigger - Invoker casts ''The King''s Command Movie Aura'''),
(7046,2,0,0,'',46,0,100,0,0,0,0,0,0,'',134,130804,0x2,(0x20 | 0x40000),0,0,0,0,NULL,7,0,0,0,0,NULL,0,0,0,0,'Areatrigger 7046 - On trigger - Invoker casts ''The King''s Command Movie Aura''');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=30 AND `SourceEntry` IN (7045, 7046);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=-@CONDREFID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(30,0,7045,0,0,6,0,469,0,0,'',0,0,0,'','Areatrigger 7045 triggers if player is Alliance'),
(30,0,7045,0,0,-@CONDREFID,0,0,0,0,'',0,0,0,'','Areatrigger 7045 triggers if condition reference 40004 is fulfilled'),
(30,0,7046,0,0,6,0,469,0,0,'',0,0,0,'','Areatrigger 7046 triggers if player is Alliance'),
(30,0,7046,0,0,-@CONDREFID,0,0,0,0,'',0,0,0,'','Areatrigger 7046 triggers if condition reference 40004 is fulfilled'),
(-@CONDREFID,0,0,0,0,47,0,29547,8,0,'',0,0,0,'','Apply condition reference if quest 29547 is taken'),
(-@CONDREFID,0,0,0,1,47,0,49556,8,0,'',0,0,0,'','Apply condition reference if quest 49556 is taken'),
(-@CONDREFID,0,0,0,2,47,0,49866,8,0,'',0,0,0,'','Apply condition reference if quest 49866 is taken'),
(-@CONDREFID,0,0,0,3,47,0,60125,8,0,'',0,0,0,'','Apply condition reference if quest 60125 is taken');

UPDATE `conditions` SET `Comment`='Areatrigger 8463 triggers if player is Horde' WHERE `SourceTypeOrReferenceId`=30 AND `SourceEntry`=8463 AND `ConditionTypeOrReference`=6;
UPDATE `conditions` SET `Comment`='Areatrigger 8463 triggers if condition reference 40001 is fulfilled' WHERE `SourceTypeOrReferenceId`=30 AND `SourceEntry`=8463 AND `ConditionTypeOrReference`=-40001;

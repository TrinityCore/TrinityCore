--
SET @RUNESEEKINGPICK :=  43666; 
SET @RUNEDSTONEGIANT :=  24329;
SET @NPC_REWARD      :=  24329; 

DELETE FROM `conditions` WHERE `SourceEntry`=@RUNESEEKINGPICK AND `SourceTypeOrReferenceId`=17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,@RUNESEEKINGPICK,0,0,36,1,0,0,0,1,0,'', 'Runeseeking Pick can target only a corpse'),
(17,0,@RUNESEEKINGPICK,0,0,31,1,3,@RUNEDSTONEGIANT,0,0,0,'', 'Runeseeking Pick can target only RUNEDSTONEGIANT');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` = @RUNEDSTONEGIANT; 

DELETE FROM `smart_scripts` WHERE `entryorguid` = @RUNEDSTONEGIANT AND `source_type`=0; 
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, 
`event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, 
`action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@RUNEDSTONEGIANT,0,0,1,8,0,100,1,@RUNESEEKINGPICK,0,0,0,80,@NPC_REWARD*100+1,2,0,0,0,0,16,0,0,0,0,0,0,0, 'Runed Stone Giant- Script - Give Quest Credit'),
(@RUNEDSTONEGIANT,0,1,0,61,0,100,1,0,0,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Runed Stone Giant - Despawn after 2 seconds');

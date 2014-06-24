--
SET @GRICKSBONESAW     :=43286;
SET @DERANGEDEXPLORER  :=23967;

DELETE FROM `conditions` WHERE `SourceEntry`=@GRICKSBONESAW AND `SourceTypeOrReferenceId`=17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,@GRICKSBONESAW ,0,0,36,1,0,0,0,1,0,'', 'Gricks Bonesaw can target only a corpse'),
(17,0,@GRICKSBONESAW ,0,0,31,1,3,@DERANGEDEXPLORER,0,0,0,'', 'Gricks Bonesaw can target only Deranged Explorer');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` = @DERANGEDEXPLORER; 
DELETE FROM `smart_scripts` WHERE `entryorguid` = @DERANGEDEXPLORER AND `source_type`=0; 
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@DERANGEDEXPLORER,0,0,1,8,0,100,1,@GRICKSBONESAW,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Deranged Explorer - On Spellhit Despawn after 1 second');

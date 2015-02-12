--
SET @Tetard   :=38937;
SET @Crispin  :=38978;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Crispin;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Tetard;

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Crispin AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Crispin*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Tetard AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Tetard*100 AND `source_type` = 9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Crispin, 0, 0, 0, 19, 0, 100, 0, 24999, 0, 0, 0, 75, 73134, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Nain - On quest rewarded - action list'),
(@Tetard, 0, 0, 0, 23, 0, 100, 0, 73133, 3, 9999, 9999, 37, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tetard - has aura x3 - Die'),
(@Tetard, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 33, @Tetard, 0, 0, 0, 0, 0, 21, 15, 0, 0, 0, 0, 0, 0, 'Tetard - on death - KillCredit'),
(@Crispin, 0, 1, 0, 20, 0, 100, 0, 24999, 0, 0, 0, 28, 73134, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Nain - On quest rewarded - action list');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=73133;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,73133,0,0,31,0,3,@Tetard,0,0,0,0,'','Only Tetard are affected by the spell.');

-- Mojo
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=24480;
DELETE FROM `smart_scripts` WHERE `entryorguid`=24480 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(24480,0,0,1,22,0,100,0,58,15000,15000,0,1,0,1,0,0,0,0,7,0,0,0,0,0,0,0,'Mojo - On Emote Received - Say Line 0'),
(24480,0,1,2,61,0,100,0,0,0,0,0,11,43906,0,0,0,0,0,7,0,0,0,0,0,0,0,'Mojo - Linked Event - Cast \'Feeling Froggy\''),
(24480,0,2,0,61,0,100,0,0,0,0,0,11,43919,0,0,0,0,0,1,0,0,0,0,0,0,0,'Mojo - Linked Event - Cast \'Feeling Froggy\'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=24480 AND `SourceGroup`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,24480,0,0,33,0,1,2,0,0,0,0,'','SAI triggers only if player in raid or party');

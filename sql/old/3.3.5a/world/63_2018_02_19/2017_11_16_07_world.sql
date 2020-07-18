UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=25201;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI', `ScriptName`='' WHERE `entry`=187373;

UPDATE `gameobject` SET `spawntimesecs`=2 WHERE  `id`=187373;
UPDATE `creature` SET `spawntimesecs`=120 WHERE  `id`=25201;

DELETE FROM `smart_scripts` WHERE `entryorguid` =187373 and `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` =25201 and `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` =18737300 and `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(187373, 1, 0 ,1,70, 0, 100, 0, 2, 0, 0,0,64,1,0,0,0,0,0,7,0,0,0,0, 0, 0, 0, 'Cage - On State Changed - Store Targetlist'),
(187373, 1, 1 ,0,61, 0, 100, 0, 0, 0, 0,0,80,18737300,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Cage - On State Changed - Run Script'),
(25201, 0, 0 ,1,38, 0, 100, 0, 1, 1, 0,0,33,25201,0,0,0,0,0,12,1,0,0,0, 0, 0, 0, 'Winterfin Tadpole - Linked with Previous Event - Kill Credit'),
(25201, 0, 1 ,2,61, 0, 100, 0, 0, 0, 0,0,29,0,0,0,0,0,0,12,1,0,0,0, 0, 0, 0, 'Winterfin Tadpole - Linked with Previous Event - Move Foward'),
(25201, 0, 2 ,3,61, 0, 100, 0, 0, 0, 0,0,48,1,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Winterfin Tadpole - Linked with Previous Event - Set Active'),
(25201, 0, 3 ,4,61, 0, 100, 0, 0, 0, 0,0,1,0,0,0,0,0,0,12,1,0,0,0, 0, 0, 0, 'Winterfin Tadpole - Linked with Previous Event - Say'),
(25201, 0, 4 ,0,61, 0, 100, 0, 0, 0, 0,0,41,60000,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Winterfin Tadpole - Linked with Previous Event - Despawn after 2 seconds'),
(25201, 0, 5 ,0,11, 0, 100, 0, 0, 0, 0,0,70,0,0,0,0,0,0,20,187373,0,0,0, 0, 0, 0, 'Winterfin Tadpole - On Respawn - Respawn Cage'),
(18737300, 9, 0 ,0, 0, 0, 100, 0, 0, 0, 0,0,100,1,0,0,0,0,0,9,25201,0,5,0, 0, 0, 0, 'Cage - Script - Send Targetlist'),
(18737300, 9, 1 ,0, 0, 0, 100, 0, 0, 0, 0,0,45,1,1,0,0,0,0,9,25201,0,5,0, 0, 0, 0, 'Cage - Script - Set Data');

DELETE FROM `creature_text` WHERE `CreatureID`=25201;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(25201, 0, 0, '$G Da-da : Ma-ma;?', 12, 0, 100, 0, 0, 0, 24446, 0, 'Winterfin Tadpole'),
(25201, 0, 1, 'Alurglgl.', 12, 0, 100, 0, 0, 0, 24447, 0, 'Winterfin Tadpole'),
(25201, 0, 2, 'Me go home?', 12, 0, 100, 0, 0, 0, 24448, 0, 'Winterfin Tadpole'),
(25201, 0, 3, 'Play!', 12, 0, 100, 0, 0, 0, 24449, 0, 'Winterfin Tadpole'),
(25201, 0, 4, 'You not $g da-da : ma-ma;!', 12, 0, 100, 0, 0, 0, 24457, 0, 'Winterfin Tadpole');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`IN(25201,187373);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 25201, 0, 0, 36, 1, 0, 0, 0, 0, 0, '','Only execute SAI if alive'),
(22, 1, 187373, 1, 0, 9, 0, 11560, 0, 0, 0, 0, '', 'Only run SAI if Player has Oh Noes, the Tadpoles taken but not complete');

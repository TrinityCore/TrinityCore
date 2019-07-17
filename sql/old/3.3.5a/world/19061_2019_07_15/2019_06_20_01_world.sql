-- 
UPDATE `spell_dbc` SET `DurationIndex`=39 WHERE `id` IN (33122);
UPDATE `creature_template` SET `flags_extra`= `flags_extra`|128, `ScriptName`="" WHERE `entry` IN (18840, 18841, 18842, 18843);
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (4368,4369,4372,4371);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(4368,'SmartTrigger'),(4369,'SmartTrigger'),(4372,'SmartTrigger'),(4371,'SmartTrigger');
UPDATE `creature_template` SET `AIName`="SmartAI",`unit_flags`= `unit_flags`|768 WHERE `entry` IN (18904);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18904) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (4368,4369,4372,4371) AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18904,0,0,0,54,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Vision of the Forgotten - On Just summoned - Say text"),
(4368,2,0,1,46,0,100,0,4368,0,0,0,85,33122,0,0,0,0,0,7,0,0,0,0,0,0,0,"Area Trigger 4368 - On Trigger - Self cast Serverside - A Vision of the Forgotten"),
(4368,2,1,0,61,0,100,0,0,0,0,0,33,18843,0,0,0,0,0,7,0,0,0,0,0,0,0,"Area Trigger 4368 - On Trigger - Kill credit"),
(4369,2,0,1,46,0,100,0,4369,0,0,0,85,33122,0,0,0,0,0,7,0,0,0,0,0,0,0,"Area Trigger 4368 - On Trigger - Self cast Serverside - A Vision of the Forgotten"),
(4369,2,1,0,61,0,100,0,0,0,0,0,33,18840,0,0,0,0,0,7,0,0,0,0,0,0,0,"Area Trigger 4368 - On Trigger - Kill credit"),
(4372,2,0,1,46,0,100,0,4372,0,0,0,85,33122,0,0,0,0,0,7,0,0,0,0,0,0,0,"Area Trigger 4368 - On Trigger - Self cast Serverside - A Vision of the Forgotten"),
(4372,2,1,0,61,0,100,0,0,0,0,0,33,18842,0,0,0,0,0,7,0,0,0,0,0,0,0,"Area Trigger 4368 - On Trigger - Kill credit"),
(4371,2,0,1,46,0,100,0,4371,0,0,0,85,33122,0,0,0,0,0,7,0,0,0,0,0,0,0,"Area Trigger 4368 - On Trigger - Self cast Serverside - A Vision of the Forgotten"),
(4371,2,1,0,61,0,100,0,0,0,0,0,33,18841,0,0,0,0,0,7,0,0,0,0,0,0,0,"Area Trigger 4368 - On Trigger - Kill credit");

DELETE FROM `creature_text` WHERE `CreatureID`=18904;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(18904,0,0,"Turn back, mortal... This is not your battle.",15,0,100,0,0,0,16007,0,"Vision of the Forgotten"),
(18904,0,1,"You cannot stop them...",15,0,100,0,0,0,16008,0,"Vision of the Forgotten"),
(18904,0,2,"We are infinite... eternal.",15,0,100,0,0,0,16009,0,"Vision of the Forgotten"),
(18904,0,3,"They lack control... Oshu'gun calls to them...",15,0,100,0,0,0,16010,0,"Vision of the Forgotten"),
(18904,0,4,"It is a beacon. A remnant of a forgotten era.",15,0,100,0,0,0,16011,0,"Vision of the Forgotten");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (4368,4369,4372,4371) AND `SourceId`=2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 4369, 2, 0, 48, 0, 10085, 0, 0, 0, 0, 0, "", "Run SAI only if objective 1 is not complete"),
(22, 1, 4371, 2, 0, 48, 0, 10085, 1, 0, 0, 0, 0, "", "Run SAI only if objective 2 is not complete"),
(22, 1, 4372, 2, 0, 48, 0, 10085, 2, 0, 0, 0, 0, "", "Run SAI only if objective 3 is not complete"),
(22, 1, 4368, 2, 0, 48, 0, 10085, 3, 0, 0, 0, 0, "", "Run SAI only if objective 4 is not complete");

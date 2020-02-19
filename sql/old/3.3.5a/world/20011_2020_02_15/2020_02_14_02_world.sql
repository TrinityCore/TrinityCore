-- 
-- 
UPDATE `creature_text` SET `Text`="STOP!", `BroadcastTextId`=24666 WHERE `CreatureID` IN (25416) AND `GroupID`=1;
UPDATE `creature_text` SET `Probability`=100, `comment`="Churn" WHERE `CreatureID` IN (25418);
UPDATE `creature_text` SET `Probability`=100, `comment`="Simmer" WHERE `CreatureID` IN (25416);
DELETE FROM `creature_text` WHERE `CreatureID` = 25418 AND `GroupID`=3;
DELETE FROM `creature_text` WHERE `CreatureID` = 25416 AND `GroupID`=0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`, `BroadcastTextId`) VALUES 
(25418, 3, 0, "I will crush you under the weight of my waves!", 12, 0, 100, 0, 0, 0, 'Churn', 24679),
(25418, 3, 1, "You dare come into my pool?!", 12, 0, 100, 0, 0, 0, 'Churn', 24680),
(25418, 3, 2, "Your death will not be pleasant!", 12, 0, 100, 0, 0, 0, 'Churn', 24681),
(25418, 3, 3, "Your corpse will feed my fish.", 12, 0, 100, 0, 0, 0, 'Churn', 24682),
(25416, 0, 0, "Who dares?!", 12, 0, 100, 0, 0, 0, 'Simmer', 24675),
(25416, 0, 1, "I will turn your bones to ash!", 12, 0, 100, 0, 0, 0, 'Simmer', 24676),
(25416, 0, 2, "You will be consumed!", 12, 0, 100, 0, 0, 0, 'Simmer', 24677),
(25416, 0, 3, "There is no escape from my rise!", 12, 0, 100, 0, 0, 0, 'Simmer', 24678);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25416,25418) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2541600,2541800) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25416, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Simmer - On Aggro - Say Line 0"),
(25416, 0, 1, 0, 11, 0, 100, 512, 0, 0, 0, 0, 0, 42, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Simmer - On Respawn - Set Invincibility Hp 5%"),
(25416, 0, 2, 0, 0, 0, 100, 0, 2300, 5300, 8000, 9900, 0, 11, 50207, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Simmer - In Combat - Cast Boiling Blood"),
(25416, 0, 3, 0, 2, 0, 100, 1, 0, 1, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Simmer - Between 0-5% Health - Set Eevent phase 1"),
(25416, 0, 4, 0, 32, 1, 100, 1, 1, 100000, 0, 0, 0, 80, 2541600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Simmer - Damaged - Action list"),
(2541600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Simmer - Action list - Stop Attack"),
(2541600, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 18, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Simmer - Action list - Set unitflag"),
(2541600, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Simmer - Action list - Disable combat movement"),
(2541600, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Simmer - Action list - Say Line 2"),
(2541600, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 85, 45599, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, "Simmer - Action list - Invoker Cast 'Boiling Point: Simmer Kill Credit' (No Repeat)"),
(2541600, 9, 5, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 1, 2, 0, 1, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Simmer - Action list - Say Line 3"),
(2541600, 9, 6, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 0, 1, 3, 0, 1, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Simmer - Action list - Say Line 1 (No Repeat)"),
(2541600, 9, 7, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Simmer - Action list - Despawn"),
(25416, 0, 5, 0, 32, 1, 100, 1, 1, 100000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Simmer - Between 0-5% Health - Despawn"),
(25416, 0, 6, 0, 7, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Simmer - On Evade - Set event phase 0"),
(25418, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 1, 3, 0, 1, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Churn - On Aggro - Say text"),
(25418, 0, 1, 0, 11, 0, 100, 512, 0, 0, 0, 0, 0, 42, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Churn - On Aggro - Set Invincibility Hp 1% (No Repeat)"),
(25418, 0, 2, 0, 0, 0, 100, 0, 2300, 5300, 8000, 9900, 0, 11, 50206, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Churn - In Combat - Cast 'Scalding Steam' (No Repeat)"),
(25418, 0, 3, 0, 2, 0, 100, 1, 0, 1, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Churn - Between 0-1% Health - Set Eevent phase 1"),
(25418, 0, 4, 0, 32, 1, 100, 1, 1, 100000, 0, 0, 0, 80, 2541800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Churn - Damaged - Action list"),
(2541800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Churn - Action list - Stop Attack"),
(2541800, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 18, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Churn - Action list - Set unitflag"),
(2541800, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Churn - Action list - Disable combat movement"),
(2541800, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 2, 0, 1, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Churn - Action list - Say Line 0 (No Repeat)"),
(2541800, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 85, 45598, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, "Churn - Between Action list - Invoker Cast 'Boiling Point: Churn Kill Credit' (No Repeat)"),
(2541800, 9, 5, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Churn - Action list - Say Line 1 (No Repeat)"),
(2541800, 9, 6, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Churn - Action list - Say Line 2 (No Repeat)"),
(2541800, 9, 7, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Churn - Action list - Despawn"),
(25418, 0, 5, 0, 32, 1, 100, 1, 1, 100000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Churn - Between 0-1% Health - Despawn"),
(25418, 0, 6, 0, 7, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Churn - On Evade - Set event phase 0");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (25416,25418);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,5,25416,0,47,11627,10,0,0,0,'','Execute the SAI only if the quest is Taken or complete'),
(22,5,25418,0,47,11627,10,0,0,0,'','Execute the SAI only if the quest is Taken or complete'),
(22,6,25416,0,47,11627,10,0,1,0,'','Execute the SAI only if the quest is not Taken or complete'),
(22,6,25418,0,47,11627,10,0,1,0,'','Execute the SAI only if the quest is not Taken or complete');

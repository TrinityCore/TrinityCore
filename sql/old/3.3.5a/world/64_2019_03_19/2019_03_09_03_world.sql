-- 
UPDATE `smart_scripts` SET `event_param1`=25730, `action_param1`=0 WHERE `entryorguid` IN (30884) AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `event_param1`=0, `event_param2`=0 WHERE `entryorguid` IN (3088400) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3088400) AND `source_type`=9 AND `id` IN (3,4);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3088400,9,3,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,10,0,0,0,0,0,0,0,'Slumbering Mjordin - On Script - Attack'),
(3088400,9,4,0,0,0,50,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Slumbering Mjordin - On Script - Say text');

DELETE FROM `conditions` WHERE SourceTypeOrReferenceId=15 AND SourceGroup=10008;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 10008, 0, 0, 0, 9, 0, 13133, 0, 0, 0, 0, 0, '', 'Slumbering Mjordin - Show gossip option if player has quest Find the Ancient Hero');

DELETE FROM `creature_text` WHERE `CreatureID` = 30718;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`, `BroadcastTextId`) VALUES 
(30718, 0, 0, "I will take pleasure in gutting you!", 12, 0, 100, 0, 0, 0, 'Slumbering Mjordin', 30498),
(30718, 0, 1, "I will feed you to the dogs!", 12, 0, 100, 0, 0, 0, 'Slumbering Mjordin', 30499),
(30718, 0, 2, "Your entrails will make a fine necklace.", 12, 0, 100, 0, 0, 0, 'Slumbering Mjordin', 30500),
(30718, 0, 3, "Die,, maggot!", 12, 0, 100, 0, 0, 0, 'Slumbering Mjordin', 30501),
(30718, 0, 4, "You come to die!", 12, 0, 100, 0, 0, 0, 'Slumbering Mjordin', 30502),
(30718, 0, 5, "I spit on you!", 12, 0, 100, 0, 0, 0, 'Slumbering Mjordin', 30503),
(30718, 0, 6, "Sniveling pig!", 12, 0, 100, 0, 0, 0, 'Slumbering Mjordin', 30504),
(30718, 0, 7, "Ugglin oo bjorr!", 12, 0, 100, 0, 0, 0, 'Slumbering Mjordin', 30505),
(30718, 0, 8, "Haraak foln!", 12, 0, 100, 0, 0, 0, 'Slumbering Mjordin', 30506),
(30718, 0, 9, "You come to die!", 12, 0, 100, 0, 0, 0, 'Slumbering Mjordin', 30507),
(30718, 0, 10, "I'll eat your heart!", 12, 0, 100, 0, 0, 0, 'Slumbering Mjordin', 30508);

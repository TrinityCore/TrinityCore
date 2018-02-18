-- Quest "Hilary's Necklace" --> Completion Event
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=8962;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8962 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=896200 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8962,0,0,0,20,0,100,0,3741,0,0,0,80,896200,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hilary - On Quest \'Hilary\'s Necklace\' Finished - Run Script"),
(896200,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,19,8963,0,0,0,0,0,0,"Hilary - On Script - Say Line 0 (Effsee)"),
(896200,9,1,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hilary - On Script - Say Line 0");
DELETE FROM `creature_text` WHERE `CreatureID` IN (8962,8963);
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(8962, 0, 0, "I know how to speak kitty, and Effsee said thank you.", 12, 0, 100, 18, 0, 0, 4628, "Hilary"),
(8963, 0, 0, "Meow!", 12, 0, 100, 0, 0, 0, 4627, "Effsee");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup` IN (1621);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 1621, 2273, 0, 0, 8, 0, 3741, 0, 0, 1, 0, 0, "", "Show gossip text 2273 if quest 'Hilary's Necklace' is NOT rewarded"),
(14, 1621, 2274, 0, 0, 8, 0, 3741, 0, 0, 0, 0, 0, "", "Show gossip text 2274 if quest 'Hilary's Necklace' is rewarded");

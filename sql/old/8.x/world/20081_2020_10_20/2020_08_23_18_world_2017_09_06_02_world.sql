-- Shellene
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14497;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14497;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14497,0,0,0,1,0,100,0,1000,15000,150000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shellene - Out of Combat - Say Line 0");
DELETE FROM `creature_text` WHERE `CreatureID`=14497;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(14497,0,0,"It's so sad for you poor children.",12,7,100,0,0,0,9689,0,"Shellene"),
(14497,0,1,"Now children stop that!  I mean it!",12,7,100,0,0,0,9690,0,"Shellene"),
(14497,0,2,"All will be well children.  The Light shall see to that!",12,7,100,0,0,0,9691,0,"Shellene"),
(14497,0,3,"I believe you children are our future...",12,7,100,0,0,0,9692,0,"Shellene");

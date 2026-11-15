-- Gubber Blump, add missing gossip menu text.
DELETE FROM `gossip_menu` WHERE `MenuID`=2562 AND `TextID`=3253;
INSERT INTO `gossip_menu` (`MenuID`,`TextID`,`VerifiedBuild`) VALUES
(2562,3253,0);

-- Gubber Blump script.
DELETE FROM `smart_scripts` WHERE `entryorguid`=10216 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1021600,1021601) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(10216,0,0,0,62,0,100,0,2562,1,0,0,0,80,1021600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gubber Blump - On Gossip Option 1 Select - Run Script"),
(10216,0,1,0,62,0,100,0,2562,1,0,0,0,80,1021601,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gubber Blump - On Gossip Option 1 Select - Run Script"),
(10216,0,2,0,62,0,100,0,2562,2,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Gubber Blump - On Gossip Option 2 Selected - Say Line 1"),

-- Timed List 1
(1021600,9,0,0,0,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Gubber Blump - On Script - Close gossip"),
(1021600,9,1,0,0,0,100,0,0,0,0,0,0,85,7733,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Gubber Blump - On Script - Cast spell 'Apprentice Fishing'"),
(1021600,9,2,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Gubber Blump - On Script - Set Orientation Invoker"),
(1021600,9,3,0,0,0,100,0,0,0,0,0,0,5,469,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gubber Blump - On Script - Play Emote"),
(1021600,9,4,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gubber Blump - On Script - Say Line 0"),
(1021600,9,5,0,0,0,100,0,4000,4000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gubber Blump - On Script - Set Orientation Home Position"),

-- Timed List 2
(1021601,9,0,0,0,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Gubber Blump - On Script - Close gossip"),
(1021601,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Gubber Blump - On Script - Set Orientation Invoker"),
(1021601,9,2,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gubber Blump - On Script - Say Line 0"),
(1021601,9,3,0,0,0,100,0,4000,4000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gubber Blump - On Script - Set Orientation Home Position");

-- Gubber Blump, conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=2562 AND `SourceEntry` IN (3234,3253);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=2562 AND `SourceEntry` IN (1,2);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`IN (1,2) AND `SourceEntry`=10216;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,2562,3234,0,0,47,0,1138,10,0,1,0,0,"","Show gossip dialog text 3234 if Quest 'Fruit of the Sea' is NOT in progress or completed"),
(14,2562,3253,0,0,47,0,1138,10,0,0,0,0,"","Show gossip dialog text 3253 if Quest 'Fruit of the Sea' is in progress or completed"),

(15,2562,2,0,0,7,0,356,1,0,0,0,0,"","Show gossip option 2 if player has fishing profession"),
(15,2562,1,0,0,47,0,1141,74,0,0,0,0,"","Show gossip option 1 if player has quest 'The Family and the Fishing Pole' in progress, completed or rewarded"),

(22,1,10216,0,0,7,0,356,1,0,1,0,0,"","Smart Event 0 for creature Gubber Blumps execute if player do not have fishing skill"),
(22,2,10216,0,0,7,0,356,1,0,0,0,0,"","Smart Event 1 for creature Gubber Blumps execute if player have fishing skill");

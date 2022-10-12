-- Beetix Ficklespragg & Noggle Ficklespragg
DELETE FROM `gossip_menu` WHERE `MenuID`=6544 AND `TextID`=7752;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(6544,7752,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 14 AND `SourceGroup`= 6544;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,6544,7753,0,0,8,0,8278,0,0,1,0,0,"","Show Gossip Menu Text 7753 if Quest 'Noggle's Last Hope' is NOT rewarded"),
(14,6544,7752,0,0,8,0,8278,0,0,0,0,0,"","Show Gossip Menu Text 7752 if Quest 'Noggle's Last Hope' is rewarded");

DELETE FROM `creature_text` WHERE `CreatureID` IN (15189, 15190);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15189,0,0,"You were always the troublemaker in the family, Noggle.  Always!",12,0,100,0,0,0,10751,0,"Beetix Ficklespragg"),
(15190,0,0,"Yes!  I'm cured!  I'm cure... whoa, got up too fast!",12,0,100,0,0,0,10675,0,"Noggle Ficklespragg"),
(15190,1,0,"Thanks for finding my reagents!  *yawn*  That poison's made me... a bit tired...",12,0,100,0,0,0,10676,0,"Noggle Ficklespragg"),
(15190,2,0,"Wha... where am I?  So... weak..",12,0,100,0,0,0,10672,0,"Noggle Ficklespragg");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (15189, 15190);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (15189, 15190) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1519000, 1519001, 1519002) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15189,0,0,0,1,0,100,0,1000,15000,150000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Beetix Ficklespragg - Out of Combat - Say Line 0"),
(15189,0,1,0,20,0,100,0,8277,0,0,0,45,1,1,0,0,0,0,19,15190,0,0,0,0,0,0,"Beetix Ficklespragg - On Quest 'Deadly Desert Venom' Finished - Set Data 1"),
(15189,0,2,0,20,0,100,0,8278,0,0,0,45,2,2,0,0,0,0,19,15190,0,0,0,0,0,0,"Beetix Ficklespragg - On Quest 'Noggle's Last Hope' Finished - Set Data 2"),
(15190,0,0,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noggle Ficklespragg - On Reset - Set Event Phase 1"),
(15190,0,1,0,38,1,100,0,1,1,0,0,80,1519000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noggle Ficklespragg - On Data 1 Set - Run Script 1 (Phase 1)"),
(15190,0,2,0,38,1,100,0,2,2,0,0,80,1519001,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noggle Ficklespragg - On Data 2 Set - Run Script 2 (Phase 1)"),
(15190,0,3,0,20,1,100,0,8282,0,0,0,80,1519002,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noggle Ficklespragg - On Quest 'Noggle's Lost Satchel' Finished - Run Script 3 (Phase 1)"),
(1519000,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noggle Ficklespragg - On Script 1 - Set Event Phase 0"),
(1519000,9,1,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noggle Ficklespragg - On Script 1 - Say Line 2"),
(1519000,9,2,0,0,0,100,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noggle Ficklespragg - On Script 1 - Remove Flag Standstate Dead"),
(1519000,9,3,0,0,0,100,0,0,0,0,0,17,64,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noggle Ficklespragg - On Script 1 - Set Emote State Stun"),
(1519000,9,4,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noggle Ficklespragg - On Script 1 - Set Emote State None"),
(1519000,9,5,0,0,0,100,0,0,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noggle Ficklespragg - On Script 1 - Set Flag Standstate Dead"),
(1519000,9,6,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noggle Ficklespragg - On Script 1 - Set Event Phase 1"),
(1519001,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noggle Ficklespragg - On Script 2 - Set Event Phase 0"),
(1519001,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noggle Ficklespragg - On Script 2 - Say Line 0"),
(1519001,9,2,0,0,0,100,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noggle Ficklespragg - On Script 2 - Remove Flag Standstate Dead"),
(1519001,9,3,0,0,0,100,0,0,0,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noggle Ficklespragg - On Script 2 - Play Emote Cheer"),
(1519001,9,4,0,0,0,100,0,10000,10000,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noggle Ficklespragg - On Script 2 - Set Flag Standstate Dead"),
(1519001,9,5,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noggle Ficklespragg - On Script 2 - Set Event Phase 1"),
(1519002,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noggle Ficklespragg - On Script 3 - Set Event Phase 0"),
(1519002,9,1,0,0,0,100,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noggle Ficklespragg - On Script 3 - Remove Flag Standstate Dead"),
(1519002,9,2,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noggle Ficklespragg - On Script 1 - Say Line 3"),
(1519002,9,3,0,0,0,100,0,0,0,0,0,90,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noggle Ficklespragg - On Script 3 - Set Flag Standstate Sit"),
(1519002,9,4,0,0,0,100,0,10000,10000,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noggle Ficklespragg - On Script 3 - Remove Flag Standstate Sit"),
(1519002,9,5,0,0,0,100,0,1000,1000,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noggle Ficklespragg - On Script 3 - Set Flag Standstate Dead"),
(1519002,9,6,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Noggle Ficklespragg - On Script 3 - Set Event Phase 1");

UPDATE `smart_scripts` SET `event_param3`=6000,`event_param4`=8000, `action_param2`=0 WHERE `entryorguid`=11319 AND `source_type`=0 AND `id`=0;

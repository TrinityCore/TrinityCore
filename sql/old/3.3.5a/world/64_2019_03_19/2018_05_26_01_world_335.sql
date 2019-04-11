-- Old Town Thug
DELETE FROM `creature_text` WHERE `CreatureID` IN (4969,38867);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4969,0,0,"Yeah, okay, boss. No problem.",12,0,100,0,0,0,1715,0,"Old Town Thug"),
(38867,0,0,"All right, boss. You sure though? Just seems like a waste of good practice.",12,0,100,0,0,0,1716,0,"Old Town Thug"),
(38867,1,0,"%s cracks his knuckles.",16,0,100,0,0,0,1717,0,"Old Town Thug");

UPDATE `smart_scripts` SET `event_param1`=18000, `event_param2`=18000 WHERE `entryorguid`=496900 AND `source_type`=9 AND `id`=2;

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=38867;
DELETE FROM `smart_scripts` WHERE `entryorguid`=38867 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(38867,0,0,1,54,0,100,0,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Old Town Thug - Just Summoned - Set Invinciblity"),
(38867,0,1,0,61,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,30,0,0,0,0,0,0,"Old Town Thug - Just Summoned - Start Attacking"),
(38867,0,2,0,38,0,100,1,1,1,0,0,0,80,496900,2,0,0,0,0,1,0,0,0,0,0,0,0,"Old Town Thug - On Data Set - Run Script");

-- Dashel Stonefist
UPDATE `smart_scripts` SET `action_param1`=38867 WHERE `entryorguid`=496100 AND `source_type`=9 AND `id`=4;
DELETE FROM `smart_scripts` WHERE `entryorguid`=496101 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(496101,9,0,0,0,0,100,0,0,0,0,0,0,15,1447,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dashel Stonefist - On Script - Quest Credit 'The Missing Diplomat'"),
(496101,9,1,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,11,4969,30,0,0,0,0,0,"Dashel Stonefist - On Script - Set Data to Old Town Thug"),
(496101,9,2,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,11,38867,30,0,0,0,0,0,"Dashel Stonefist - On Script - Set Data to Old Town Thug"),
(496101,9,3,0,0,0,100,0,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dashel Stonefist - On Script - Evade"),
(496101,9,4,0,0,0,100,0,0,0,0,0,0,2,84,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dashel Stonefist - On Script - Set Faction 84"),
(496101,9,5,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dashel Stonefist - On Script - Say Line 1"),
(496101,9,6,0,0,0,100,0,6000,6000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dashel Stonefist - On Script - Say Line 2"),
(496101,9,7,0,0,0,100,0,0,0,0,0,0,42,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dashel Stonefist - On Script - Set Invincibility Off"),
(496101,9,8,0,0,0,100,0,4000,4000,0,0,0,1,0,0,0,0,0,0,19,4969,0,0,0,0,0,0,"Dashel Stonefist - On Script - Say Line 0 (Old Town Thug)"),
(496101,9,9,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,19,38867,0,0,0,0,0,0,"Dashel Stonefist - On Script - Say Line 0 (Old Town Thug)"),
(496101,9,10,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,19,38867,0,0,0,0,0,0,"Dashel Stonefist - On Script - Say Line 1 (Old Town Thug)");

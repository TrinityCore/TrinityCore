-- Quest "Rot Hide Origins"
DELETE FROM `creature_text` WHERE `CreatureID`=1498 AND `GroupID`>0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1498,1,0,"%s chants words of power...",16,0,100,0,0,0,513,0,"Bethor Iceshard"),
(1498,2,0,"No!  It can't be...",12,0,100,0,0,0,514,0,"Bethor Iceshard"),
(1498,3,0,"Incredible!  I know he who wrought these enchantments...",12,0,100,1,0,0,515,0,"Bethor Iceshard"),
(1498,3,1,"This is unforseen.  The being who enchanted this is known to me...",12,0,100,1,0,0,516,0,"Bethor Iceshard");

DELETE FROM `smart_scripts` WHERE `entryorguid`=1498 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=149801 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1498,0,1,0,20,0,100,0,444,0,0,0,80,149801,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bethor Iceshard - On Quest 'Rot Hide Origins' Finished - Run Script"),
(149801,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bethor Iceshard - On Script - Remove Npc Flag Questgiver"),
(149801,9,1,0,0,0,100,0,2000,2000,0,0,11,1848,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bethor Iceshard - On Script - Cast Divining Chant"),
(149801,9,2,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bethor Iceshard - On Script - Say Line 1"),
(149801,9,3,0,0,0,100,0,3000,3000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bethor Iceshard - On Script - Say Line 2"),
(149801,9,4,0,0,0,100,0,3000,3000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bethor Iceshard - On Script - Say Line 3"),
(149801,9,5,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bethor Iceshard - On Script - Add Npc Flag Questgiver");

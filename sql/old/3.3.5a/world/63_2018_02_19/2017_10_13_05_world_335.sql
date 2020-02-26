-- Quest "Neeru Fireblade" --> Completion Event
DELETE FROM `smart_scripts` WHERE `entryorguid`=3216 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=321600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3216,0,1,0,20,0,100,0,829,0,0,0,80,321600,2,0,0,0,0,1,0,0,0,0,0,0,0,"Neeru Fireblade - On Quest 'Neeru Fireblade' Finished - Run Script"),
(321600,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Neeru Fireblade - On Script - Remove Npc Flag Questgiver+Gossip"),
(321600,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Neeru Fireblade - On Script - Say Line 0"),
(321600,9,2,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Neeru Fireblade - On Script - Say Line 1"),
(321600,9,3,0,0,0,100,0,3000,3000,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Neeru Fireblade - On Script - Add Npc Flag Questgiver+Gossip");

DELETE FROM `creature_text` WHERE `CreatureID`=3216;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3216,0,0,"%s inspects the Searing Collar...",16,0,100,0,0,0,990,0,"Neeru Fireblade"),
(3216,1,0,"Interesting, very interesting.  You found this in Durotar, $n?",12,1,100,1,0,0,991,0,"Neeru Fireblade"),
(3216,1,1,"The collar is indeed infused with demonic power, $n.  This bodes ill for our people.",12,1,100,1,0,0,992,0,"Neeru Fireblade"),
(3216,1,2,"Hm...it is good that you brought this to me, $n.",12,1,100,1,0,0,993,0,"Neeru Fireblade"),
(3216,1,3,"A dangerous device this is, $n.  I am glad you brought it to my attention.",12,1,100,1,0,0,994,0,"Neeru Fireblade");

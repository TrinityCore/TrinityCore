-- Caretaker Caice
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2307;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2307 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2307,0,0,0,1,0,100,0,1000,15000,90000,120000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caretaker Caice - Out of Combat - Say Line 0");
DELETE FROM `creature_text` WHERE `CreatureID`=2307;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2307,0,0,"Your undeath is not the end of your life, but the beginning. It is up to you to decide where your fate lies now.",12,33,100,0,0,0,583,0,"Caretaker Caice"),
(2307,0,1,"You are free of His control. And while you will be judged by lesser beings, at least you have chances that the Scourge do not!",12,33,100,0,0,0,584,0,"Caretaker Caice"),
(2307,0,2,"Terror, darkness, power? The Forsaken crave not these things; the Forsaken ARE these things.",12,33,100,0,0,0,585,0,"Caretaker Caice"),
(2307,0,3,"My bones are weak, my eyes see only darkness, and my body feels only pain; but these things are good because my will is my own.",12,33,100,0,0,0,586,0,"Caretaker Caice");

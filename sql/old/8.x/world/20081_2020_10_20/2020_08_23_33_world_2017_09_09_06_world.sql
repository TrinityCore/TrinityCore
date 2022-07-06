-- Completion event for quest 'Stromgarde Badges'
DELETE FROM `creature_text` WHERE `CreatureID`=2700;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2700,0,0,"%s begins to search through the badges of fallen Stromgarde defenders...",16,0,100,0,0,0,873,0,"Captain Nials"),
(2700,1,0,"Privates Marcus, Tremane, Osgood, Lampret...",12,7,100,0,0,0,874,0,"Captain Nials"),
(2700,1,1,"Privates Fontane, MacDugal, Wilcott...",12,7,100,0,0,0,875,0,"Captain Nials"),
(2700,1,2,"Privates Theoric, Kitrin, Blythe, Agmond...",12,7,100,0,0,0,876,0,"Captain Nials"),
(2700,1,3,"Privates Horus, Tilling, Rockwell...",12,7,100,0,0,0,877,0,"Captain Nials"),
(2700,2,0,"...Sampson, Yorick, Chamley...",12,7,100,0,0,0,878,0,"Captain Nials"),
(2700,2,1,"Clemens, Bartholemew, Enderman, Wyles...",12,7,100,0,0,0,879,0,"Captain Nials"),
(2700,2,2,"Tormil, Gamlor, Shefferd, Cowry...",12,7,100,0,0,0,880,0,"Captain Nials"),
(2700,2,3,"Martens, Reblock, Adinay, Nikeson...",12,7,100,0,0,0,881,0,"Captain Nials"),
(2700,3,0,"%s sighs...",16,0,100,0,0,0,882,0,"Captain Nials"),
(2700,4,0,"So many lost.  And so many more we must lose before this battle ends.",12,0,100,1,0,0,883,0,"Captain Nials"),
(2700,5,0,"Thank you for these badges, $n.  I will send news to the families of the deceased.",12,0,100,1,0,0,884,0,"Captain Nials");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2700 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=270000 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2700,0,0,0,20,0,100,0,26095,0,0,0,80,270000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Captain Nials - On Quest \'Stromgarde Badges\' Finished - Run Script'),
(270000,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Nials - On Script - Remove Npc Flag Questgiver+Gossip"),
(270000,9,1,0,0,0,100,0,1000,1000,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Nials - On Script - Set Emote State 69"),
(270000,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Nials - On Script - Say Line 0"),
(270000,9,3,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Nials - On Script - Say Line 1"),
(270000,9,4,0,0,0,100,0,4500,4500,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Nials - On Script - Say Line 2"),
(270000,9,5,0,0,0,100,0,3000,3000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Nials - On Script - Set Emote State 0"),
(270000,9,6,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Nials - On Script - Say Line 3"),
(270000,9,7,0,0,0,100,0,1000,1000,0,0,1,4,0,0,0,0,0,7,0,0,0,0,0,0,0,"Captain Nials - On Script - Say Line 4"),
(270000,9,8,0,0,0,100,0,5000,5000,0,0,1,5,0,0,0,0,0,7,0,0,0,0,0,0,0,"Captain Nials - On Script - Say Line 5"),
(270000,9,9,0,0,0,100,0,3000,3000,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Nials - On Script - Add Npc Flag Questgiver+Gossip");

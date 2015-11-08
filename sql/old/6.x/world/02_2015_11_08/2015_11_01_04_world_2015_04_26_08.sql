--
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=8506;
DELETE FROM `smart_scripts` WHERE `entryorguid`=8506 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8506, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0,0,'Eranikus the Chained - Just summoned - Talk');

DELETE FROM `creature_text` WHERE `entry` IN (8506);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(8506, 0, 0, 'My eyes! It burns... it burns...', 15, 0, 100, 0, 0, 0, 4438, 0, 'Eranikus the Chained'),
(8506, 0, 1, 'Torture me no more! Release me, mortal! The Swamp of Sorrows... mortal... please...', 15, 0, 100, 0, 0, 0, 4439, 0, 'Eranikus the Chained'),
(8506, 0, 2, 'Foolish mortal, I will rend your soul in two once I am released!', 15, 0, 100, 0, 0, 0, 4440, 0, 'Eranikus the Chained'),
(8506, 0, 3, 'You are an agent of their wicked god, fool. I will see you destroyed!', 15, 0, 100, 0, 0, 0, 4441, 0, 'Eranikus the Chained'),
(8506, 0, 4, 'My soul is not a trinket! Mortal, you must release me from these chains!', 15, 0, 100, 0, 0, 0, 4442, 0, 'Eranikus the Chained'),
(8506, 0, 5, 'It hurts so much... Itharius, my old friend... Please help me...', 15, 0, 100, 0, 0, 0, 4443, 0, 'Eranikus the Chained'),
(8506, 0, 6, 'Will the nightmare ever end?! I cannot force myself awake!', 15, 0, 100, 0, 0, 0, 4444, 0, 'Eranikus the Chained'),
(8506, 0, 7, 'My charge to watch the temple has failed... my corrupted soul knows no peace...', 15, 0, 100, 0, 0, 0, 4445, 0, 'Eranikus the Chained'); 

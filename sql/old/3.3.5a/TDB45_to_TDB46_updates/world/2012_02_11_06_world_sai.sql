SET @NPC = 3301;
-- reduce spawn time to ten sec
UPDATE `quest_end_scripts` SET `datalong2`=10000 WHERE `id`=231;
-- Add text for Morgan Ladimore
DELETE FROM `creature_text` WHERE `entry`=@NPC;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(@NPC, 1, 0, 'My sword Archeus served me well in life, but as at last my spirit may pass from the unhappy existence, I need it no longer.', 12, 0, 100, 0, 0, 0, 'Morgan Ladimore - A Daughter''s Love'),
(@NPC, 2, 0, 'I shall cling to the love of my daugter and hope that I will find forgiveness under the Light for my sins.', 12, 0, 100, 0, 0, 0, 'Morgan Ladimore - A Daughter''s Love');
-- Add SAI to Morgan Ladimore for on spawn
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@NPC;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC,0,0,0,1,0,100,1,0,0,0,0,18,514,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Morgan Ladimore - On summon - make passive non-attackable'),
(@NPC,0,1,0,1,0,100,1,4000,4000,0,0,84,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Morgan Ladimore - 4 sec - say first'),
(@NPC,0,2,0,1,0,100,1,7000,7000,0,0,84,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Morgan Ladimore - 7 sec - say second'),
(@NPC,0,3,4,1,0,100,1,9000,9000,0,0,90,8,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Morgan Ladimore - 9 sec - Set bytes1 kneel');

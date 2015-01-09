UPDATE `smart_scripts` SET `event_flags`=1 WHERE  `entryorguid`=23580 AND `source_type`=0 AND `id`=0 AND `link`=1;

-- Deep in the bowels of the Underhalls - 13042
SET @OSTERKILGR         := 30409; -- Apprentice Osterkilgr
SET @SPELL_BLAST        := 60290; -- Blast Wave
SET @SPELL_FIREBALL     := 14034; -- Fireball
SET @QUEST              := 13042; -- Deep in the Bowels of the Underhalls
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@OSTERKILGR;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@OSTERKILGR;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@OSTERKILGR;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) 
VALUES
(@OSTERKILGR,0,0,0,0,0,100,0,5000,7000,5000,7000,11,@SPELL_BLAST,0,0,0,0,0,5,0,0,0,0,0,0,0,'Apprentice Osterkilgr - In Combat - cast Blast Wave'),
(@OSTERKILGR,0,1,0,0,0,100,0,1000,2000,1000,2000,11,@SPELL_FIREBALL,0,0,0,0,0,5,0,0,0,0,0,0,0,'Apprentice Osterkilgr - In Combat - cast Fireball'),
(@OSTERKILGR,0,2,0,2,0,100,1,40,80,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Apprentice Osterkilgr - @80%HP - say text 0'),
(@OSTERKILGR,0,3,4,2,0,100,1,0,40,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Apprentice Osterkilgr - @40%HP - say text 1'),
(@OSTERKILGR,0,4,0,61,0,100,0,0,0,0,0,33,30412,0,0,0,0,0,7,0,0,0,0,0,0,0,'Apprentice Osterkilgr - At 40% HP - give kill credit');
DELETE FROM `creature_ai_texts` WHERE `entry` IN (-10020,-10021);
DELETE FROM `creature_text` WHERE `entry`=@OSTERKILGR;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@OSTERKILGR,0,0,'You''ve come for the doctor''s plans! You''ll only find death!',12,0,0,0,0,0,'Apprentice Osterkilgr - Say 0'),
(@OSTERKILGR,1,0,'The doctor entrusted me with the plans to Nergeld, our flesh giant amalgamation made entirely of vargul! It will be the most powerful creation of its kind and a whole legion of them will be created to destroy your pitiful forces!',12,0,0,0,0,0,'Apprentice Osterkilgr - Say 1');

-- 
-- Convert quest_end_scripts to SAI
DELETE FROM `creature_text` WHERE `entry`=836;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(836,0,1, 'There''s nothing like some scalding mornbrew on a chilly Dun Morogh day to get things started right!',12,7,100,  1,0,0,'Durnan Furcutter after quest'),
(836,1,1, 'Oooooo hot hot hot! If that won''t put spring in your step, I don''t know what will!'                ,12,7,100,400,0,0,'Durnan Furcutter after quest');
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=836;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (51708,2289,2688,2933,142343,175926,175925);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (51708,2289,2688,2933,142343,175926,175925) AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (293300,14234300,83600,17592600,17592500) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=836 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Eliza's Grave Dirt for Digging Through the Dirt (1s delay is needed?)
(51708,1,0,0,20,1,100,0,254,0,0,0,12, 314,1,300000,0,1,0,8,0,0,0,-10267  , 52.52,42.54,2.5,'Eliza Grave Dirt - On Quest Complete - Spawn Eliza'),
-- Ruined Lifeboat for Enticing Negolash Spawndata is from sniff! ( 3s delay is required?)
(2289 ,1,0,0,20,1,100,0,619,0,0,0,12,1494,1,300000,0,1,0,8,0,0,0,-14621.93,148.1328,0.7201138,0.9944053,'Ruined Lifeboat - On Quest Complete - Spawn Negolash'),
-- Keystone for Breaking the Keystone, spawndata is from sniff! (1s delay is needed?)
(2688 ,1,0,0,20,1,100,0,652,0,0,0,12,2763,1, 60000,0,1,0,8,0,0,0,-1517.452,-2181.302,17.31267,2.722714,'Keystone - On Quest Complete - Spawn Thenan'),
-- Seal of the Earth for Seal of the Earth (2x)
(2933,1,0,0,20,0,100,0, 779,0,0,0,80,293300,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Seal of the Earth - On quest "Seal of the Earth" Rewarded - call script'),
(2933,1,1,0,20,0,100,0, 795,0,0,0,80,293300,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Seal of the Earth - On quest "Seal of the Earth" Rewarded - call script'),
(293300,9,0,0,1,0,100,0,2000,2000,0,0,12,2759,1,300000,0,1,0,8,0,0,0,-6703,-4094,264.235,2.830, 'Seal of the Earth - After 2 seconds - Summon Hematus'),
(293300,9,1,0,1,0,100,0,2000,2000,0,0,12,2757,1,300000,0,1,0,8,0,0,0,-6718,-4125,264.235,2.683, 'Seal of the Earth - After 2 seconds - Summon Blacklash'),
-- Uldum Pedestal for Seeing What Happens (2x)
(142343,1,0,0,20,0,100,0,2946,0,0,0,80,14234300,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Uldum Pedestal - On quest "Seeing What Happens" Rewarded - call script'),
(142343,1,1,0,20,0,100,0,2966,0,0,0,80,14234300,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Uldum Pedestal - On quest "Seeing What Happens" Rewarded - call script'),
(14234300,9,0,0,1,0,100,0,2000,2000,0,0,12,7918,1,300000,0,0,0,8,0,0,0,-9619,-2815,11.21,0.43, 'Uldum Pedestal - After 2 seconds - Stone Watcher of Norgannon'),
-- Durnan Furcuttor for Scalding Mornbrew Delivery
(836,0,0,0,20,0,100,0,2946,0,0,0,80,83600,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Durnan Furcutter - On quest "Scalding Mornbrew Delivery" Rewarded - call script'),
-- Script for Dance/talk part
(83600,9,0,1,1,0,100,0,2000,2000,0,0,1,0, 2000,0,0,0,0,7,0,0,0,0,0,0,0,'Durnan Furcutter - After 2s - Say line1'),
(83600,9,1,2,1,0,100,0,   0,   0,0,0,5,7,    0,0,0,0,0,7,0,0,0,0,0,0,0,'Durnan Furcutter - After 4s - EmoteEat'),
(83600,9,2,3,1,0,100,0,4000,4000,0,0,1,0,12000,0,0,0,0,7,0,0,0,0,0,0,0,'Durnan Furcutter - After 8s - Say line2'),
(83600,9,3,0,1,0,100,0,   0,   0,0,0,5,0,    0,0,0,0,0,7,0,0,0,0,0,0,0,'Durnan Furcutter - After 20s - StopDance'),
-- Mrs. Dalson's Diary for Mrs.Dalson's Diary
(175926,1,1,0,20,0,100,0,5058,0,0,0,80,17592600,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Mrs. Dalson''s Diary - On quest "Mrs. Dalson''s Diary" Rewarded - call script'),
(17592600,9,0,0, 1,0,100,0,2000,2000,0,0,12,10816,1,300000,0,1,0,8,0,0,0,1926.55,-1627.94,60.42,2.24, 'Mrs. Dalson''s Diary - After 2 seconds - Summon Wandering Skeleton'),
-- Outhouse for Locked Away
(175925,1,1,0,20,0,100,0,5059,0,0,0,80,17592500,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Outhouse - On quest "Locked Away" Rewarded - call script'),
(17592500,9,0,0, 1,0,100,0,2000,2000,0,0,12,10836,1,300000,0,1,0,8,0,0,0,1943.38,-1654.68,59.69,6.19, 'Outhouse - After 2 seconds - Summon Farmer Dalson');

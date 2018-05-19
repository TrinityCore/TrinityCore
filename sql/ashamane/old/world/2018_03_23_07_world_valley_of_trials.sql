-- Valley of Trails - Emotes
-- Den Grunt - Waypoints
-- Huklah SAI
SET @ENTRY := 3160;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,5000,10000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Huklah - Out of Combat - Play Emote 1");

-- Rarc SAI
SET @ENTRY := 3161;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,5000,10000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rarc - Out of Combat - Play Emote 1");

-- Kzan Thornslash SAI
SET @ENTRY := 3159;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,5000,10000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kzan Thornslash - Out of Combat - Play Emote 1");

-- Zureetha Fargaze SAI
SET @ENTRY := 3145;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,5000,10000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zureetha Fargaze - Out of Combat - Play Emote 1");

-- Foreman Thazz'ril SAI
SET @ENTRY := 11378;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,5000,10000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foreman Thazz'ril - Out of Combat - Play Emote 1");

-- Hraug SAI
SET @ENTRY := 12776;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,5000,10000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hraug - Out of Combat - Play Emote 1");

-- Nartok SAI
SET @ENTRY := 3156;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,5000,10000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nartok - Out of Combat - Play Emote 1");

-- Gornek SAI
SET @ENTRY := 3143;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,5000,10000,5,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gornek - Out of Combat - Play Emote 7");

-- Pathing for one grunt in cave
SET @NPC := 251496;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-592.4183,`position_y`=-4144.538,`position_z`=42.11545 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-592.4183,-4144.538,42.11545,0,0,0,0,100,0),
(@PATH,2,-594.1683,-4146.038,42.36545,0,0,0,0,100,0),
(@PATH,3,-595.1683,-4147.788,42.86545,0,0,0,0,100,0),
(@PATH,4,-595.4252,-4148.025,42.76385,0,0,0,0,100,0),
(@PATH,5,-597.1752,-4150.275,43.01385,0,0,0,0,100,0),
(@PATH,6,-598.1752,-4150.775,43.26385,0,0,0,0,100,0),
(@PATH,7,-600.1752,-4152.525,43.26385,0,0,0,0,100,0),
(@PATH,8,-602.345,-4154.116,43.25286,0,0,0,0,100,0),
(@PATH,9,-604.345,-4155.866,43.50286,0,0,0,0,100,0),
(@PATH,10,-604.7183,-4156.001,43.54986,0,0,0,0,100,0),
(@PATH,11,-606.2183,-4157.501,43.04986,0,0,0,0,100,0),
(@PATH,12,-605.9683,-4160.751,43.04986,0,0,0,0,100,0),
(@PATH,13,-606.0277,-4160.863,43.04424,0,0,0,0,100,0),
(@PATH,14,-605.7777,-4162.613,42.54424,0,0,0,0,100,0),
(@PATH,15,-605.7777,-4163.863,42.29424,0,0,0,0,100,0),
(@PATH,16,-605.0752,-4169.27,41.48709,0,0,0,0,100,0),
(@PATH,17,-604.8252,-4171.77,41.48709,0,0,0,0,100,0),
(@PATH,18,-604.4944,-4171.907,41.24754,0,0,0,0,100,0),
(@PATH,19,-604.4944,-4174.407,41.24754,0,0,0,0,100,0),
(@PATH,20,-604.2444,-4175.657,41.49754,0,0,0,0,100,0),
(@PATH,21,-604.3888,-4174.307,41.29676,0,0,0,0,100,0),
(@PATH,22,-604.6388,-4172.807,41.29676,0,0,0,0,100,0),
(@PATH,23,-604.8888,-4169.557,41.29676,0,0,0,0,100,0),
(@PATH,24,-605.2297,-4169.213,41.4446,0,0,0,0,100,0),
(@PATH,25,-605.2297,-4168.963,41.6946,0,0,0,0,100,0),
(@PATH,26,-605.4797,-4163.713,42.1946,0,0,0,0,100,0),
(@PATH,27,-605.8757,-4163.593,42.36644,0,0,0,0,100,0),
(@PATH,28,-605.8757,-4162.343,42.61644,0,0,0,0,100,0),
(@PATH,29,-606.1257,-4160.843,43.11644,0,0,0,0,100,0),
(@PATH,30,-606.3243,-4157.373,43.03017,0,0,0,0,100,0),
(@PATH,31,-604.3243,-4156.123,43.53017,0,0,0,0,100,0),
(@PATH,32,-604.3931,-4155.768,43.53776,0,0,0,0,100,0),
(@PATH,33,-602.1431,-4153.768,43.28776,0,0,0,0,100,0),
(@PATH,34,-600.8931,-4153.018,43.28776,0,0,0,0,100,0),
(@PATH,35,-598.1431,-4151.018,43.28776,0,0,0,0,100,0),
(@PATH,36,-597.8702,-4150.589,43.08055,0,0,0,0,100,0),
(@PATH,37,-596.8702,-4150.089,43.08055,0,0,0,0,100,0),
(@PATH,38,-595.6202,-4149.339,42.83055,0,0,0,0,100,0),
(@PATH,39,-593.8702,-4146.589,42.33055,0,0,0,0,100,0),
(@PATH,40,-593.4512,-4146.553,42.31656,0,0,0,0,100,0),
(@PATH,41,-592.7012,-4144.803,42.06656,0,0,0,0,100,0),
(@PATH,42,-592.2012,-4140.803,42.06656,0,0,0,0,100,0),
(@PATH,43,-591.4512,-4135.553,42.06656,0,0,0,0,100,0),
(@PATH,44,-590.9252,-4134.109,42.22979,0,0,0,0,100,0),
(@PATH,45,-589.9252,-4131.359,42.47979,0,0,0,0,100,0),
(@PATH,46,-589.6752,-4130.109,42.72979,0,0,0,0,100,0),
(@PATH,47,-588.9252,-4128.109,43.22979,0,0,0,0,100,0),
(@PATH,48,-588.726,-4127.853,43.16886,0,0,0,0,100,0),
(@PATH,49,-588.226,-4126.603,43.41886,0,0,0,0,100,0),
(@PATH,50,-587.976,-4125.603,43.41886,0,0,0,0,100,0),
(@PATH,51,-586.6942,-4122.214,43.93642,0,0,0,0,100,0),
(@PATH,52,-587.6942,-4118.464,43.93642,0,0,0,0,100,0),
(@PATH,53,-587.8058,-4118.299,44.03777,0,0,0,0,100,0),
(@PATH,54,-588.3058,-4116.049,44.03777,0,0,0,0,100,0),
(@PATH,55,-589.3058,-4115.049,44.28777,0,0,0,0,100,0),
(@PATH,56,-592.0012,-4112.077,44.46067,0,0,0,0,100,0),
(@PATH,57,-595.5012,-4110.827,43.96067,0,0,0,0,100,0),
(@PATH,58,-595.5062,-4110.993,43.98151,0,0,0,0,100,0),
(@PATH,59,-592.7562,-4111.743,44.48151,0,0,0,0,100,0),
(@PATH,60,-592.4868,-4112.001,44.43573,0,0,0,0,100,0),
(@PATH,61,-591.7368,-4112.251,44.43573,0,0,0,0,100,0),
(@PATH,62,-589.2368,-4114.751,44.18573,0,0,0,0,100,0),
(@PATH,63,-589.0537,-4114.994,44.22446,0,0,0,0,100,0),
(@PATH,64,-588.3037,-4116.244,44.22446,0,0,0,0,100,0),
(@PATH,65,-587.8037,-4118.494,43.97446,0,0,0,0,100,0),
(@PATH,66,-587.0537,-4121.494,44.22446,0,0,0,0,100,0),
(@PATH,67,-586.8948,-4121.602,44.06555,0,0,0,0,100,0),
(@PATH,68,-586.6448,-4122.352,44.06555,0,0,0,0,100,0),
(@PATH,69,-587.8948,-4125.352,43.56555,0,0,0,0,100,0),
(@PATH,70,-587.9706,-4125.508,43.57565,0,0,0,0,100,0),
(@PATH,71,-588.4706,-4126.758,43.32565,0,0,0,0,100,0),
(@PATH,72,-588.9706,-4128.008,43.32565,0,0,0,0,100,0),
(@PATH,73,-589.2206,-4129.258,42.82565,0,0,0,0,100,0),
(@PATH,74,-589.9706,-4131.008,42.57565,0,0,0,0,100,0),
(@PATH,75,-590.3362,-4131.271,42.41715,0,0,0,0,100,0),
(@PATH,76,-591.0862,-4133.271,42.16715,0,0,0,0,100,0),
(@PATH,77,-591.3362,-4135.771,41.91715,0,0,0,0,100,0),
(@PATH,78,-591.8362,-4140.521,42.16715,0,0,0,0,100,0),
(@PATH,79,-592.481,-4144.521,42.06772,0,0,0,0,100,0);

-- Quest Related Stuff
-- added missing incompleted quest text
DELETE FROM `quest_request_items` WHERE `ID` IN (25172, 25126, 25127, 3087, 25129, 25131, 25132, 25135, 25135, 25136, 37446, 25139);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnCompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(25172, 0, 0, 'Quickly, $n.  Dispatch of these humans in our valley.', 20574), -- 25172
(25126, 0, 0, 'I hope you haven''t returned to try and convince me that you have completed your task, $n? No, of course not. I would think better of you.', 20574), -- 25126
(25127, 0, 0, 'The carapace of a scorpid isn''t so thick that the strength of a determined warrior will be deterred. Strike strongly and without doubt, and the scorpids should prove easy prey.', 20574), -- 25127
(3087, 2, 0, 'Many come to me with the desire to be a hunter, but few follow through. It''s easy to underestimate our job. Being a hunter is far more than just aiming and shooting.', 20574), -- 3087
(25129, 0, 0, 'Ahhh... my father always said I would never amount to much, and here, lying beneath a tree as life seeps away, I''m afraid it looks like he was right.$b$bAt least I wish to die knowing that my last enemy in life lays dead.', 20574), -- 25129
(25131, 1, 0, 'To prove yourself against the Burning Blade, you must first defeat these vile familiars.  Return to me when you have done this.', 20574), -- 25131
(25132, 0, 0, 'Is your task complete, $n?', 20574), -- 25132
(25135, 0, 0, 'Have you entered the Burning Blade Coven, $n?  Did you find my pick?', 20574), -- 25135
(25136, 6, 0, 'Have you finished collecting cactus apples?', 20574), -- 25136
(37446, 5, 0, 'No good lazy...$B$B Eh?  Do you have my blackjack?  Did you catch any peons sleeping on the job?!', 20574), -- 37446
(25139, 2, 0, 'Whenever you''re ready, we''ll move forward.', 20574); -- 25139

-- added missing quest complete details
DELETE FROM `quest_details` WHERE `ID` IN (25172, 25127, 25128, 3087, 25130, 25131, 25132, 25133, 25135, 25136, 37446, 25139);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(25172, 0, 0, 0, 0, 0, 0, 0, 0, 20574), -- 25172
(25127, 0, 0, 0, 0, 0, 0, 0, 0, 20574), -- 25127
(25128, 1, 0, 0, 0, 0, 0, 0, 0, 20574), -- 25128
(3087, 1, 1, 0, 0, 0, 0, 0, 0, 20574), -- 3087
(25130, 0, 0, 0, 0, 0, 0, 0, 0, 20574), -- 25130
(25131, 1, 0, 0, 0, 0, 0, 0, 0, 20574), -- 25131
(25132, 1, 0, 0, 0, 0, 0, 0, 0, 20574), -- 25132
(25133, 0, 0, 0, 0, 0, 0, 0, 0, 20574), -- 25133
(25135, 1, 0, 0, 0, 0, 0, 0, 0, 20574), -- 25135
(25136, 5, 1, 1, 1, 0, 0, 0, 0, 20574), -- 25136
(37446, 5, 0, 0, 0, 0, 0, 0, 0, 20574), -- 37446
(25139, 1, 1, 0, 0, 0, 0, 0, 0, 20574); -- 25139

-- added missing completion quest_text
DELETE FROM `quest_offer_reward` WHERE `ID` IN (25172, 25152, 25126, 25127, 25128, 3087, 25129, 25130, 25131, 25132, 25135, 25136, 37446, 25139);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(25172, 0, 0, 0, 0, 0, 0, 0, 0, 'Executed with quickness and discretion.  A job well done.', 20574), -- 25172
(25152, 6, 1, 1, 4, 0, 0, 0, 0, 'Another one of Kaltunk''s recruits, hm?$b$bA sorry state of affairs we find ourselves in if this is the best the Horde can produce. No matter. By the time we think you''re ready to leave the Valley, you''ll be a proud warrior of the Horde.', 20574), -- 25152
(25126, 11, 0, 0, 0, 2000, 0, 0, 0, 'Hmmm, not bad, $n. But don''t let it get to your head...you''ll fight tougher than boars in your career.$b$bNonetheless, you''ve proven yourself well, and your next trial will be against a considerably more dangerous opponent, so you''ll need some extra protection.', 20574), -- 25126
(25127, 0, 0, 0, 0, 0, 0, 0, 0, 'There is an important lesson that you must take away from fighting scorpids. The smallest or largest of opponents can still send you to your doom. In fierce combat, any number of things can prove your downfall.$b$bI have no more to teach you, $n. You have done well, and I will watch your progress with interest.', 20574), -- 25127
(25128, 0, 0, 0, 0, 0, 0, 0, 0, '<Hana''zua groans in pain.>', 20574), -- 25128
(3087, 1, 1, 0, 0, 0, 0, 0, 0, 'As a hunter, my skill rivals the arcane powers of the mages, the martial prowess of the warriors, or even the blessed acts of our beloved shaman. To be a hunter requires focus and dedication. Let us continue.', 20574), -- 3087
(25129, 0, 0, 0, 0, 0, 0, 0, 0, 'My blow was not enough to kill him, but looking at the damage I inflicted gives me some small measure of pride. That small measure will be all I have to sustain myself if I die, and in that light, the short list of my life''s accomplishments fills me with anger.', 20574), -- 25129
(25130, 0, 0, 0, 0, 0, 0, 0, 0, 'From your description of the beast, I believe you must be speaking of Sarkoth! It is no wonder that Hana''zua was overtaken by it. Aid will be dispatched to him immediately, trouble yourself no more with Hana''zua''s plight.$b$bHowever, I must say, I am most impressed to hear that you brought Sarkoth to death. It is a feat to be proud of, $n. And that you would fight for a stranger''s honor, while other tasks occupied your time, your own honor is heightened.', 20574), -- 25130
(25131, 1, 0, 0, 0, 0, 0, 0, 0, 'You have done well, $n.$B$BAlthough the Vile Familiars were merely pets of the darker powers within the Burning Blade, your success against them foretells greater deeds ahead.', 20574), -- 25131
(25132, 2, 0, 0, 0, 0, 0, 0, 0, 'You retrieved it!  Well done!$B$BYour efforts within the Burning Blade Coven are key in rooting out this cult in the Valley of Trials.  But I fear they have further aims in our land.$B$BWe have not seen the end of them.', 20574), -- 25132
(25135, 1, 0, 0, 0, 0, 0, 0, 0, 'Great, you got it!  Thanks a lot, $n.  This is my favorite pick!  Now if my peons ever finish chopping down these trees, maybe we can find a nice cave to mine!', 20574), -- 25135
(25136, 1, 1, 4, 0, 0, 0, 0, 0, 'Wonderful, $n! As promised, here is your cactus apple surprise plus a little something extra.', 20574), -- 25136
(37446, 1, 0, 0, 0, 0, 0, 0, 0, 'Good, good.  Maybe they''ll think twice before slacking next time!  Thanks for the help!', 20574), -- 37446
(25139, 1, 1, 0, 0, 0, 0, 0, 0, 'You learn quickly.', 20574); -- 25139

-- added and updated quest chains
DELETE FROM `quest_template_addon` WHERE `ID` IN (25132, 25135, 25167, 25135);
INSERT INTO `quest_template_addon` (`ID`, `PrevQuestID`, `NextQuestId`) VALUES
(25132, 25131, 25133),
(25135, 25134, 0),
(25167, 25133, 25168);

UPDATE `quest_template_addon` SET `PrevQuestID`=25126 WHERE  `ID`=25136;
UPDATE `quest_template_addon` SET `PrevQuestID`=25126 WHERE  `ID`=3088;
UPDATE `quest_template_addon` SET `NextQuestID`=25167 WHERE  `ID`=25133;
UPDATE `quest_template_addon` SET `NextQuestID`=25171 WHERE  `ID`=25168;

-- lazy peons should not start a quest
DELETE FROM `creature_queststarter` WHERE  `id`=10556;

-- monk class quest should be only take-able by monk players
DELETE FROM `quest_template_addon` WHERE `ID` IN (31156, 31157);
INSERT INTO `quest_template_addon` (`ID`, `AllowableClasses`, `PrevQuestID`, `NextQuestId`) VALUES
(31156, 10, 0, 31157),
(31157, 10, 31156, 0);

-- Your Place In The World
DELETE FROM `quest_template_addon` WHERE `ID`=25152;
INSERT INTO `quest_template_addon` (`ID`, `NextQuestID`, `SpecialFlags`) VALUES
(25152, 25126, 4);

-- Vile Familiar AI (removed flee effect because they no longer flee anymore)
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=1;

-- Yarrog Baneshadow SAI
SET @ENTRY = 3183;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,75965,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yarrog Baneshadow  - On link - Cast 'Shadow Channelling' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,3400,4700,11,35913,64,0,0,0,0,2,0,0,0,0,0,0,0,"Yarrog Baneshadow - In Combat - Cast 'Fel Fireball'"),
(@ENTRY,0,2,0,0,0,100,0,0,0,20000,25000,11,37628,2,0,0,0,0,2,0,0,0,0,0,0,0,"Yarrog Baneshadow - In Combat - Cast 'Fel Immolate'");

-- Creature spawns, waypoints AND updates
-- Spawn Gato - Monk Trainer
SET @CGUID = 452573;
DELETE FROM `creature` WHERE `guid`=@CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID, 63296, 1, 1, 0, -618.5833, -4209.587, 38.21728, 2.294008, 120, 0, 0); -- 63296 (Area: 363) (Auras: 118348 - 118348)

DELETE FROM `creature_template_addon` WHERE `entry` = 63296;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES (63296, 1, '118348');

-- Pathing for Lo'Shall Entry: 39224 'TDB FORMAT' (thanks @Kittnz) 
SET @NPC := 253228;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-729.145,`position_y`=-4150.031,`position_z`=30.34825 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-729.145,-4150.031,30.34825,0,0,0,0,100,0), -- 16:03:33
(@PATH,2,-722.7031,-4142.439,30.31937,0,0,0,0,100,0), -- 16:03:38
(@PATH,3,-712.9484,-4138.673,30.14915,0,0,0,0,100,0), -- 16:03:42
(@PATH,4,-702.9331,-4125.341,30.50701,0,0,0,0,100,0), -- 16:03:49
(@PATH,5,-695.1557,-4127.668,30.47903,0,0,0,0,100,0), -- 16:03:51
(@PATH,6,-691.7387,-4135.948,30.40836,0,0,0,0,100,0), -- 16:03:55
(@PATH,7,-690.13,-4143.896,30.34492,0,0,0,0,100,0), -- 16:03:59
(@PATH,8,-697.8231,-4152.111,30.31937,0,0,0,0,100,0), -- 16:04:04
(@PATH,9,-704.145,-4161.166,30.31937,0,0,0,0,100,0), -- 16:04:08
(@PATH,10,-714.231,-4165.488,30.33477,0,0,0,0,100,0), -- 16:04:12
(@PATH,11,-713.0794,-4190.552,30.3491,0,0,0,0,100,0), -- 16:04:23
(@PATH,12,-718.9116,-4198.529,30.29597,0,0,0,0,100,0), -- 16:04:27
(@PATH,13,-729.1097,-4195.161,30.05437,0,0,0,0,100,0), -- 16:04:32
(@PATH,14,-744.1416,-4194.716,30.34408,0,0,0,0,100,0), -- 16:04:38
(@PATH,15,-752.9818,-4184.209,30.1584,0,0,0,0,100,0), -- 16:04:42
(@PATH,16,-754.4515,-4167.96,30.39671,0,0,0,0,100,0), -- 16:04:50
(@PATH,17,-748.1555,-4159.223,30.1748,0,0,0,0,100,0), -- 16:04:53
(@PATH,18,-739.053,-4149.636,30.383,0,0,0,0,100,0); -- 16:04:59

-- Quests and quest givers removed in patch 7.0.3
-- Orc starting area (Valley of Trials)

-- These NPCs are no longer quest givers as of patch 7.0.3:
UPDATE `creature_template` SET `npcflag` = `npcflag`& ~2 WHERE `entry` IN
(3153,  -- Frang <Warrior Trainer>
 3155,  -- Rwag <Rogue Trainer>
 3156,  -- Nartok <Warlock Trainer>
 3157,  -- Shikrik <Shaman Trainer>
 3707,  -- Ken'jai <Priest Trainer>
39206,  -- Acrypha <Mage Trainer>
39214); -- Karranisha <Hunter Trainer>

-- Gornek (3143) no longer offers these class quests:
DELETE FROM `creature_queststarter` WHERE `id`= 3143 AND `quest` IN
(2383,  -- Quest:Simple Parchment
 3087,  -- Quest:Etched Parchment
 3088,  -- Quest:Encrypted Parchment
 3089,  -- Quest:Rune-Inscribed Parchment
 3090,  -- Quest:Tainted Parchment
25138); -- Quest:Glyphic Parchment

DELETE FROM `creature_queststarter` WHERE `id` = 3153 AND `quest`= 25147; -- Frang <Warrior Trainer>, Quest:Charge
DELETE FROM `creature_queststarter` WHERE `id` = 3155 AND `quest`= 25141; -- Rwag <Rogue Trainer>, Quest:Eviscerate
DELETE FROM `creature_queststarter` WHERE `id` = 3156 AND `quest`= 25145; -- Nartok <Warlock Trainer>, Quest:Corruption
DELETE FROM `creature_queststarter` WHERE `id` = 3157 AND `quest`= 25143; -- Shikrik <Shaman Trainer>, Quest:Primal Strike
DELETE FROM `creature_queststarter` WHERE `id`= 39206 AND `quest`= 25149; -- Acrypha <Mage Trainer>, Quest:Frost Nova
DELETE FROM `creature_queststarter` WHERE `id`= 39214 AND `quest`= 25139; -- Karranisha <Hunter Trainer>, Quest:Steady Shot

DELETE FROM `creature_questender` WHERE `id` = 3153 AND `quest` IN (2383,3065,25147,25148); -- Simple Parchment,Simple Tablet,Charge,Hone Your Holler
DELETE FROM `creature_questender` WHERE `id` = 3155 AND `quest` IN (3083,3088,25141,25142); -- Encrypted Tablet,Encrypted Parchment,Eviscerate,Into the Shadows
DELETE FROM `creature_questender` WHERE `id` = 3156 AND `quest` IN (3090, 25145, 25146);    -- Tainted Parchment, Corruption, A Demonic Fire
DELETE FROM `creature_questender` WHERE `id` = 3157 AND `quest` IN (3084,3089,25143,25144); -- Rune-Inscribed Tablet,Rune-Inscribed Parchment,Primal Strike,Rock Meets Flesh
DELETE FROM `creature_questender` WHERE `id` = 3707 AND `quest` = 3085;                     -- Ken'jai <Priest Trainer>, Quest:Hallowed Tablet
DELETE FROM `creature_questender` WHERE `id`= 39206 AND `quest` IN (25138, 25149, 25150);   -- Glyphic Parchment, Frost Nova, Empowered Minds
DELETE FROM `creature_questender` WHERE `id`= 39214 AND `quest` IN (3082,3087,25139,25140); -- Etched Tablet,Etched Parchment,Steady Shot,Swine Hunting

DELETE FROM `disables` WHERE `sourceType`= 1 AND `entry` IN (2383,3065,3082,3083,3084,3085,3087,3088,3089,3090,25138,25139,25140,25141,25142,25143,25144,25145,25146,25147,25148,25149,25150);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,  2383, 0, '', '', 'Obsolete quest: Simple Parchment'),
(1,  3065, 0, '', '', 'Obsolete quest: Simple Tablet'),
(1,  3082, 0, '', '', 'Obsolete quest: Etched Tablet'),
(1,  3083, 0, '', '', 'Obsolete quest: Encrypted Tablet'),
(1,  3084, 0, '', '', 'Obsolete quest: Rune-Inscribed Tablet'),
(1,  3085, 0, '', '', 'Obsolete quest: Hallowed Tablet'),
(1,  3087, 0, '', '', 'Obsolete quest: Etched Parchment'),
(1,  3088, 0, '', '', 'Obsolete quest: Encrypted Parchment'),
(1,  3089, 0, '', '', 'Obsolete quest: Rune-Inscribed Parchment'),
(1,  3090, 0, '', '', 'Obsolete quest: Tainted Parchment'),
(1, 25138, 0, '', '', 'Obsolete quest: Glyphic Parchment'),
(1, 25139, 0, '', '', 'Obsolete quest: Steady Shot'),
(1, 25140, 0, '', '', 'Obsolete quest: Swine Hunting'),
(1, 25141, 0, '', '', 'Obsolete quest: Eviscerate'),
(1, 25142, 0, '', '', 'Obsolete quest: Into the Shadows'),
(1, 25143, 0, '', '', 'Obsolete quest: Primal Strike'),
(1, 25144, 0, '', '', 'Obsolete quest: Rock Meets Flesh'),
(1, 25145, 0, '', '', 'Obsolete quest: Corruption'),
(1, 25146, 0, '', '', 'Obsolete quest: A Demonic Fire'),
(1, 25147, 0, '', '', 'Obsolete quest: Charge'),
(1, 25148, 0, '', '', 'Obsolete quest: Hone Your Holler'),
(1, 25149, 0, '', '', 'Obsolete quest: Frost Nova'),
(1, 25150, 0, '', '', 'Obsolete quest: Empowered Minds');

-- Fix Valley of Trials Quests
-- Quest Starters
DELETE FROM `creature_queststarter` WHERE `id`=3143 AND `quest`IN (25126,25127,25172);
DELETE FROM `creature_queststarter` WHERE `id`=3145 AND `quest`IN (25131,25132,25133);
DELETE FROM `creature_queststarter` WHERE `id`=3287 AND `quest`IN (25129,25130);
DELETE FROM `creature_queststarter` WHERE `id`=5887 AND `quest`IN (25128);
DELETE FROM `creature_queststarter` WHERE `id`=9796 AND `quest`IN (25136);
DELETE FROM `creature_queststarter` WHERE `id`=10176 AND `quest`IN (25152);
DELETE FROM `creature_queststarter` WHERE `id`=11378 AND `quest`IN (37446,25135,25134);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(3143, 25126),
(3143, 25127),
(3143, 25172),
(3145, 25131),
(3145, 25132),
(3145, 25133),
(3287, 25129),
(3287, 25130),
(5887, 25128),
(9796, 25136),
(10176, 25152),
(11378, 37446),
(11378, 25135);
-- Quest Enders
DELETE FROM `creature_questender` WHERE `id`=3143 AND `quest` IN (787,788,789,804,4641,25126,25127,25130,25152,25172);
DELETE FROM `creature_questender` WHERE `id`=3145 AND `quest` IN (792,794,1499,25131,25132);
DELETE FROM `creature_questender` WHERE `id`=3287 AND `quest` IN (790,25128,25129);
DELETE FROM `creature_questender` WHERE `id`=5887 AND `quest` IN (1463,1516,1518);
DELETE FROM `creature_questender` WHERE `id`=9796 AND `quest` IN (4402,25136);
DELETE FROM `creature_questender` WHERE `id`=11378 AND `quest` IN (5441,6394,25134,25135,37446);
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(3143, 25126),
(3143, 25127),
(3143, 25130),
(3143, 25152),
(3143, 25172),
(3145, 25131),
(3145, 25132),
(3287, 25128),
(3287, 25129),
(9796, 25136),
(11378, 25135),
(11378, 37446);
-- Quest_Template_Addon Fixs
DELETE FROM `quest_template_addon` WHERE `ID` IN (25126, 25127, 25128, 25129, 25130, 25131, 25133, 25135, 25136, 25172, 37446);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`) VALUES
(25126, 0, 0, 0, 25152, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(25127, 0, 0, 0, 25172, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(25128, 0, 0, 0, 37446, 25129, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(25129, 0, 0, 0, 25128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(25130, 0, 0, 0, 25129, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(25131, 0, 0, 0, 25127, 25132, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(25133, 0, 0, 0, 25132, 25167, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(25135, 0, 0, 0, 25131, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(25136, 0, 0, 0, 25126, 37446, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(25172, 0, 0, 0, 25126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(37446, 0, 0, 0, 25136, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

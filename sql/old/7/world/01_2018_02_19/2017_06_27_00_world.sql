-- 
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
SET @NPC := 308574;
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

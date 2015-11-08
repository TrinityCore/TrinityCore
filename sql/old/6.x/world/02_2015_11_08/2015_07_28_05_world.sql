-- 
-- DB/SAI: Update Kezan
-- Ace SAI
SET @ENTRY := 35207;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Ace - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- Ace SAI
SET @ENTRY := 37709;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Ace - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- Assistant Greely SAI
SET @ENTRY := 48496;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,60,0,100,0,10000,10000,365000,365000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Assistant Greely - On Update - Say Line 0"),
(@ENTRY,0,1,0,60,0,100,0,20000,20000,375000,375000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Assistant Greely - On Update - Say Line 1"),
(@ENTRY,0,2,0,60,0,100,0,27000,27000,382000,382000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Assistant Greely - On Update - Say Line 2"),
(@ENTRY,0,3,0,60,0,100,0,35000,35000,390000,390000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Assistant Greely - On Update - Say Line 3"),
(@ENTRY,0,4,0,60,0,100,0,55000,55000,410000,410000,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Assistant Greely - On Update - Say Line 4"),
(@ENTRY,0,5,0,60,0,100,0,95000,95000,450000,450000,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Assistant Greely - On Update - Say Line 5"),
(@ENTRY,0,6,0,60,0,100,0,100000,100000,455000,455000,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Assistant Greely - On Update - Say Line 6"),
(@ENTRY,0,7,0,60,0,100,0,155000,155000,510000,510000,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Assistant Greely - On Update - Say Line 7"),
(@ENTRY,0,8,0,60,0,100,0,175000,175000,530000,530000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Assistant Greely - On Update - Say Line 8"),
(@ENTRY,0,9,0,60,0,100,0,195000,195000,550000,550000,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Assistant Greely - On Update - Say Line 9"),
(@ENTRY,0,10,0,60,0,100,0,220000,220000,575000,575000,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Assistant Greely - On Update - Say Line 10"),
(@ENTRY,0,11,0,60,0,100,0,245000,245000,600000,600000,1,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Assistant Greely - On Update - Say Line 11"),
(@ENTRY,0,12,0,60,0,100,0,250000,250000,605000,605000,1,12,0,0,0,0,0,1,0,0,0,0,0,0,0,"Assistant Greely - On Update - Say Line 12"),
(@ENTRY,0,13,0,60,0,100,0,260000,260000,615000,615000,1,13,0,0,0,0,0,1,0,0,0,0,0,0,0,"Assistant Greely - On Update - Say Line 13"),
(@ENTRY,0,14,0,60,0,100,0,280000,280000,635000,635000,1,14,0,0,0,0,0,1,0,0,0,0,0,0,0,"Assistant Greely - On Update - Say Line 14"),
(@ENTRY,0,15,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Assistant Greely - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- NPC talk text insert
SET @ENTRY := 48496;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'You don\'t have to yell, Hobart, I\'m standing right here. Sheesh!',12,0,100,6,0,0, 'say Text',49102),
(@ENTRY,1,0, 'There. One Micro Mechachicken. I\'ll never understand how you come up with these names.',12,0,100,1,0,0, 'say Text',49103),
(@ENTRY,2,0, 'Greely sighs and rolls her eyes.',16,0,100,0,0,0, 'say Text',49105),
(@ENTRY,3,0, 'Yes, Doctor Grapplehammer.',12,0,100,1,0,0, 'say Text',49106),
(@ENTRY,4,0, 'The assistant shakes her head.',16,0,100,0,0,0, 'say Text',49109),
(@ENTRY,5,0, 'Greely coughs.',16,0,100,0,0,0, 'say Text',49113),
(@ENTRY,6,0, 'Um, Hobart, you\'re at the controls.',12,0,100,1,0,0, 'say Text',49114),
(@ENTRY,7,0, 'Ya think? Hobart, the Micro Mechachicken is destabilizing. It\'s expanding!',12,0,100,1,0,0, 'say Text',49121),
(@ENTRY,8,0, 'It\'s the one on the far right! Hurry, Hobart! It\'s going to eggsplode!',14,0,100,5,0,0, 'say Text',49123),
(@ENTRY,9,0, 'WHAT?!!!',14,0,100,5,0,0, 'say Text',49126),
(@ENTRY,10,0, 'We\'re still alive, Doctor Grapplehammer, despite your best efforts.',12,0,100,1,0,0, 'say Text',49128),
(@ENTRY,11,0, 'Is that egg on your face?',12,0,100,1,0,0, 'say Text',49131),
(@ENTRY,12,0, 'Hobart\'s jaw hits the ground.',16,0,100,0,0,0, 'say Text',0),
(@ENTRY,13,0, 'Now what\'s this about you \'always loved me\', Grapplehammer?',12,0,100,1,0,0, 'say Text',49132),
(@ENTRY,14,0, 'We can both agree on that, doctor.',12,0,100,1,0,0, 'say Text',49134);
-- Brett "Coins" McQuid SAI
SET @ENTRY := 37762;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Brett Coins McQuid - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- Bruno Flameretardant SAI
SET @ENTRY := 34835;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bruno Flameretardant - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,2,2,0,100,1,0,20,0,0,33,34835,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bruno Flameretardant - Between 0-20% Health - Quest Credit '' (No Repeat)"),
(@ENTRY,0,2,3,61,0,100,1,0,20,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bruno Flameretardant - Between 0-20% Health - Set Faction 35 (No Repeat)"),
(@ENTRY,0,3,4,61,0,100,1,0,20,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bruno Flameretardant - Between 0-20% Health - Say Line 1 (No Repeat)"),
(@ENTRY,0,4,0,61,0,100,1,0,20,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bruno Flameretardant - Between 0-20% Health - Stop Attacking (No Repeat)"),
(@ENTRY,0,5,0,1,0,100,1,5000,5000,0,0,2,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bruno Flameretardant - Out of Combat - Set Faction 7 (No Repeat)"),
(@ENTRY,0,6,0,25,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bruno Flameretardant - On Reset - Start Attacking");
-- NPC talk text insert
SET @ENTRY := 34835;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I was just comin'' to see you. Honest!',12,0,100,0,0,0, 'say Text on Aggro',48863),
(@ENTRY,1,0, 'Darn, you got me!',12,0,100,0,0,0, 'say Text on Beat',35127);
-- Brute Enforcer SAI
SET @ENTRY := 35304;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,500,1000,0,0,11,76136,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brute Enforcer - Out of Combat - Cast 'Acidic Sweat' (No Repeat)"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Brute Enforcer - On Gossip Hello - Play Random Emote (1, 3, 5, 6)"),
(@ENTRY,0,2,0,1,0,100,0,10000,20000,40000,50000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brute Enforcer - Out of Combat - Say Line 0");
-- NPC talk text insert
SET @ENTRY := 35304;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Trolls disent certain truck,chef!',12,0,50,5,0,0, 'say Text'),
(@ENTRY,0,1, 'Songs Trolls not make the Goblin nice work!',12,0,50,5,0,0, 'say Text'),
(@ENTRY,0,2, 'You you tape us the songs Trolls!',12,0,50,5,0,0, 'say Text'),
(@ENTRY,0,3, 'It monitors Trolls very well!',12,0,50,5,0,0, 'say Text');
-- Candy Cane SAI
SET @ENTRY := 35053;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Candy Cane - On Gossip Hello - Play Random Emote (1, 3, 5, 6)"),
(@ENTRY,0,1,0,19,0,100,0,26712,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Candy Cane - On Quest '' Taken - Say Line 0"),
(@ENTRY,0,2,3,19,0,100,0,14113,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Candy Cane - On Quest '' Taken - Say Line 1"),
(@ENTRY,0,3,4,61,0,100,0,14113,0,0,0,11,66908,0,0,0,0,0,7,0,0,0,0,0,0,0,"Candy Cane - On Quest '' Taken - Cast 'Awesome Party Ensemble'"),
(@ENTRY,0,4,0,61,0,100,0,14113,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Candy Cane - On Quest '' Taken - Say Line 2");
-- NPC talk text insert
SET @ENTRY := 35053;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Make sure you pull plenty of moolah out of the bank. I don\'t want you buying any of that cheap clothing you usually like to wear. This party\'s important!',12,0,100,1,0,0, 'say Text',49023),
(@ENTRY,1,0, 'You\'re the most handsome boyfriend a girl could hope for. Knock\'em dead, honey!',12,0,100,1,0,0, 'say Text',49012),
(@ENTRY,2,0, 'You are dresed Impress! Use your new powers below to make your party guests happy!',41,0,100,0,0,0, 'say Text',35444);
-- Chip Endale SAI
SET @ENTRY := 35054;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,26711,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chip Endale - On Quest '' Taken - Say Line 0"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Chip Endale - On Gossip Hello - Play Random Emote (1, 3, 5, 6)"),
(@ENTRY,0,2,0,20,0,100,0,14110,0,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chip Endale - On Quest '' Finished - Play Emote 4"),
(@ENTRY,0,3,0,19,0,100,0,14153,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chip Endale - On Quest '' Taken - Say Line 1");
-- NPC talk text insert
SET @ENTRY := 35054;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Make sure you pull plenty of moolah out of the bank. I don''t want you buying any of that cheap clothing you usually like to wear. This party''s important!',12,0,100,1,0,0, 'say Text',49023),
(@ENTRY,1,0, 'Look at you! I''m the luckiest boyfriend on the island!!!',42,0,100,1,0,0, 'say Text',49013);
-- Claims Adjuster SAI
SET @ENTRY := 37602;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Claims Adjuster - On Gossip Hello - Play Random Emote (1, 3, 5, 6)"),
(@ENTRY,0,1,2,20,0,100,0,14125,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Claims Adjuster - On Quest '' Finished - Say Line 0"),
(@ENTRY,0,2,0,61,0,100,0,14125,0,0,0,28,68480,0,0,0,0,0,7,0,0,0,0,0,0,0,"Claims Adjuster - On Quest '' Finished - Remove Aura 'Phase - Quest Zone-Specific 05'");
-- NPC talk text insert
SET @ENTRY := 37602;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Still an unfortunate accident of fire-fireworks-lit flammable-gas - Lectriquea?',14,0,100,0,0,0, 'say Text');
-- Coach Crosscheck SAI
SET @ENTRY := 37106;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,24567,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coach Crosscheck - On Quest '' Finished - Say Line 0"),
(@ENTRY,0,1,0,19,0,100,0,24488,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coach Crosscheck - On Quest '' Taken - Say Line 1"),
(@ENTRY,0,2,0,19,0,100,0,24520,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coach Crosscheck - On Quest '' Taken - Say Line 2"),
(@ENTRY,0,3,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Coach Crosscheck - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- NPC talk text insert
SET @ENTRY := 37106;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'You gotta hurry,kid. We gotta get you into the game. But first, we gotta get the parts for that shredder!',12,0,100,1,0,0, 'say Text',49025),
(@ENTRY,1,0, 'Get into that shredder and win the game. The Bilgewater Cartel\'s counting on you!',12,0,100,1,0,0, 'say Text',49026),
(@ENTRY,2,0, 'You got the juice,kid. That\'s for sure! Too bad that dragon had to come and ruin everything. No matter. You made us proud. Now get back to headquarters.',12,0,100,1,0,0, 'say Text',49027);
-- Evol Fingers SAI
SET @ENTRY := 34696;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,3000,5000,0,0,11,11939,0,0,0,0,0,1,0,0,0,0,0,0,0,"Evol Fingers - Out of Combat - Cast 'Summon Imp' (No Repeat)"),
(@ENTRY,0,1,0,1,0,100,0,10000,10000,20000,20000,11,69607,0,0,0,0,0,19,34689,100,0,0,0,0,0,"Evol Fingers - Out of Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Evol Fingers - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- FBoK Bank Teller SAI
SET @ENTRY := 35120;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,26712,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"FBoK Bank Teller - On Quest '' Finished - Say Line 0"),
(@ENTRY,0,1,0,20,0,100,0,26711,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"FBoK Bank Teller - On Quest '' Finished - Say Line 0"),
(@ENTRY,0,2,0,1,0,100,0,15000,60000,15000,60000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"FBoK Bank Teller - Out of Combat - Say Line 1"),
(@ENTRY,0,3,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"FBoK Bank Teller - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- NPC talk text insert
SET @ENTRY := 35120;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'You people cool your heels! $N is here. He\'s gonna be the next Trade Prince!',12,0,100,1,0,0, 'say Text',49024),
(@ENTRY,1,0, 'Next!',12,0,100,1,0,0, 'say Text',24357);
-- Fizz Lighter SAI
SET @ENTRY := 34689;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,5000,5000,15000,15000,11,69608,0,0,0,0,0,19,34696,100,0,0,0,0,0,"Fizz Lighter - Out of Combat - Cast 'Fireball'"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Fizz Lighter - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- Foreman Dampwick SAI
SET @ENTRY := 34872;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,14138,0,0,0,1,0,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Foreman Dampwick - On Quest '' Finished - Say Line 0"),
(@ENTRY,0,1,2,52,0,100,0,0,34872,0,0,11,87226,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foreman Dampwick - On Text 0 Over - Cast 'Cosmetic - Rocket Barrage (Goblin Racial)'"),
(@ENTRY,0,2,3,52,0,100,0,0,34872,0,0,1,1,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Foreman Dampwick - On Text 0 Over - Say Line 1"),
(@ENTRY,0,3,0,52,0,100,0,1,0,0,0,1,2,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Foreman Dampwick - On Text 1 Over - Say Line 2"),
(@ENTRY,0,4,0,19,0,100,0,25473,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foreman Dampwick - On Quest '' Taken - Say Line 3"),
(@ENTRY,0,5,0,19,0,100,0,14124,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foreman Dampwick - On Quest '' Taken - Say Line 4"),
(@ENTRY,0,6,0,1,0,100,0,45000,245000,45000,245000,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foreman Dampwick - Out of Combat - Say Line 5"),
(@ENTRY,0,7,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Foreman Dampwick - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- NPC talk text insert
SET @ENTRY := 34872;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'It is always pleasant to receive a gift from the hand of the second in person. I\'m going to the baller immediately!',12,0,100,1,0,0, 'say Text'),
(@ENTRY,1,0, 'OUCH!',14,0,100,34,0,0, 'say Text'),
(@ENTRY,2,0, 'Okay, okay! I understand the message!',12,0,100,1,0,0, 'say Text'),
(@ENTRY,3,0, 'Chief, tell Chipie I\'ll kick him if  Kaja\'Cola  will get more later then that production has resumed.',12,0,100,1,0,0, 'say Text'),
(@ENTRY,4,0, 'I can\'t to believe the nerve of those trolls. Rebelling after all that I\'ve done for them!',12,0,100,1,0,0, 'say Text'),
(@ENTRY,5,0, 'Useless! You are simply useless! I fear that we are all obligate to throw you into the Maelstrom!',14,0,50,22,0,0, 'say Text'),
(@ENTRY,5,1, 'You want us go bash bad trolls?',12,0,50,0,0,0, 'say Text');
-- Frankie Gearslipper SAI
SET @ENTRY := 34876;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frankie Gearslipper - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,2,2,0,100,1,0,20,0,0,33,34876,0,0,0,0,0,7,0,0,0,0,0,0,0,"Frankie Gearslipper - Between 0-20% Health - Quest Credit '' (No Repeat)"),
(@ENTRY,0,2,3,61,0,100,1,0,20,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frankie Gearslipper - Between 0-20% Health - Set Faction 35 (No Repeat)"),
(@ENTRY,0,3,4,61,0,100,1,0,20,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frankie Gearslipper - Between 0-20% Health - Say Line 1 (No Repeat)"),
(@ENTRY,0,4,0,61,0,100,1,0,20,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frankie Gearslipper - Between 0-20% Health - Stop Attacking (No Repeat)"),
(@ENTRY,0,5,0,1,0,100,1,5000,5000,0,0,2,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frankie Gearslipper - Out of Combat - Set Faction 7 (No Repeat)"),
(@ENTRY,0,6,0,25,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frankie Gearslipper - On Reset - Start Attacking"),
(@ENTRY,0,7,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Frankie Gearslipper - On Gossip Hello - Play Random Emote (1, 3, 5, 6)"),
(@ENTRY,0,8,0,0,0,100,0,2000,3000,7000,9000,11,75775,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frankie Gearslipper - In Combat - Cast 'Throw Gears'");
-- NPC talk text insert
SET @ENTRY := 34876;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Oh no, you didn\'t!',12,0,100,1,0,0, 'say Text',0),
(@ENTRY,1,0, 'What? Fine, fine... I''ll pay my protection moolah to your goons!',12,0,100,1,0,0, 'say Text',35129);
-- Gappy Silvertooth SAI
SET @ENTRY := 35126;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,3,0,0,0,56,47045,1,0,0,0,0,7,0,0,0,0,0,0,0,"Gappy Silvertooth - On Gossip Option 0 Selected - Add Item '' 1 Time"),
(@ENTRY,0,1,0,61,0,100,0,3,0,0,0,72,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Gappy Silvertooth - On Gossip Option 0 Selected - Close Gossip"),
(@ENTRY,0,2,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Gappy Silvertooth - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- Gobber SAI
SET @ENTRY := 37710;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Gobber - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- Gobber SAI
SET @ENTRY := 35209;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Gobber - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- Goblin Supermodel SAI
SET @ENTRY := 37054;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,51733,2,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Supermodel - Out of Combat - Cast 'Shadow Channelling' (No Repeat)");
-- Goblin Supermodel SAI
SET @ENTRY := 37057;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,51733,2,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Supermodel - Out of Combat - Cast 'Shadow Channelling' (No Repeat)");
-- Goblin Supermodel SAI
SET @ENTRY := 37056;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,11,51733,2,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Supermodel - Out of Combat - Cast 'Shadow Channelling' (No Repeat)");
-- Hired Looter SAI
SET @ENTRY := 35234;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,11000,7800,21300,11,6257,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hired Looter - In Combat - Cast 'Torch Toss'");
-- Hobart Grapplehammer SAI
SET @ENTRY := 48494;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,60,0,100,0,5000,5000,360000,360000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobart Grapplehammer - On Update - Say Line 0"),
(@ENTRY,0,1,0,60,0,100,0,25000,25000,380000,380000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobart Grapplehammer - On Update - Say Line 1"),
(@ENTRY,0,2,0,60,0,100,0,50000,50000,405000,405000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobart Grapplehammer - On Update - Say Line 2"),
(@ENTRY,0,3,0,60,0,100,0,60000,60000,415000,415000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobart Grapplehammer - On Update - Say Line 3"),
(@ENTRY,0,4,0,60,0,100,0,75000,75000,430000,430000,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobart Grapplehammer - On Update - Say Line 4"),
(@ENTRY,0,5,0,60,0,100,0,85000,85000,440000,440000,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobart Grapplehammer - On Update - Say Line 5"),
(@ENTRY,0,6,0,60,0,100,0,90000,90000,445000,445000,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobart Grapplehammer - On Update - Say Line 6"),
(@ENTRY,0,7,0,60,0,100,0,110000,110000,465000,465000,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobart Grapplehammer - On Update - Say Line 7"),
(@ENTRY,0,8,0,60,0,100,0,115000,115000,470000,470000,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobart Grapplehammer - On Update - Say Line 8"),
(@ENTRY,0,9,0,60,0,100,0,120000,120000,475000,475000,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobart Grapplehammer - On Update - Say Line 9"),
(@ENTRY,0,10,0,60,0,100,0,125000,125000,480000,480000,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobart Grapplehammer - On Update - Say Line 10"),
(@ENTRY,0,11,0,60,0,100,0,135000,135000,490000,490000,1,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobart Grapplehammer - On Update - Say Line 11"),
(@ENTRY,0,12,0,60,0,100,0,140000,140000,495000,495000,1,12,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobart Grapplehammer - On Update - Say Line 12"),
(@ENTRY,0,13,0,60,0,100,0,145000,145000,500000,500000,1,13,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobart Grapplehammer - On Update - Say Line 13"),
(@ENTRY,0,14,0,60,0,100,0,165000,165000,520000,520000,1,14,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobart Grapplehammer - On Update - Say Line 14"),
(@ENTRY,0,15,0,60,0,100,0,185000,185000,540000,540000,1,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobart Grapplehammer - On Update - Say Line 15"),
(@ENTRY,0,16,0,60,0,100,0,195000,195000,550000,550000,1,16,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobart Grapplehammer - On Update - Say Line 16"),
(@ENTRY,0,17,0,60,0,100,0,200000,200000,555000,555000,1,17,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobart Grapplehammer - On Update - Say Line 17"),
(@ENTRY,0,18,0,60,0,100,0,210000,210000,565000,565000,1,18,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobart Grapplehammer - On Update - Say Line 18"),
(@ENTRY,0,19,0,60,0,100,0,230000,230000,585000,585000,1,19,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobart Grapplehammer - On Update - Say Line 19"),
(@ENTRY,0,20,0,60,0,100,0,235000,235000,590000,590000,1,20,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobart Grapplehammer - On Update - Say Line 20"),
(@ENTRY,0,21,0,60,0,100,0,270000,270000,625000,625000,1,21,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hobart Grapplehammer - On Update - Say Line 21"),
(@ENTRY,0,22,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Hobart Grapplehammer - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- NPC talk text insert
SET @ENTRY := 48494;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Prepare the Micro Mechachicken!',14,0,100,1,0,0, 'say Text',49101),
(@ENTRY,1,0, 'There\'s a great deal that you do not understand, my dear Greely. That is why you are the assistant and I... I am Hobart Grapplehammer!',12,0,100,1,0,0, 'say Text',49103),
(@ENTRY,2,0, 'Excellent. Now back away from the Ultra Concave Fissionable Testing Platform. Slowly, if you please.',12,0,100,1,0,0, 'say Text',49107),
(@ENTRY,3,0, 'Thank you. Now behold as I stabilize the highly unstable miniaturization process.',12,0,100,1,0,0, 'say Text',49108),
(@ENTRY,4,0, 'I am going to end the horrible problem of food storage cutting into the profits of the Bilgewater Cartel!',12,0,100,1,0,0, 'say Text',49110),
(@ENTRY,5,0, 'I\'ll soon be revered as the greatest goblin tinker of all times! Besides, that negligence case involving the creation of the gilgoblins will never stick.',12,0,100,1,0,0, 'say Text',49111),
(@ENTRY,6,0, 'Flip the switch!',12,0,100,1,0,0, 'say Text',49112),
(@ENTRY,7,0, 'Quite right, Greely. You passed today\'s pop quiz.',12,0,100,1,0,0, 'say Text',49115),
(@ENTRY,8,0, 'I am now flipping the switch!',12,0,100,1,0,0, 'say Text',49116),
(@ENTRY,9,0, 'Greely, can you feel it? My moment of success is at hand!',12,0,100,1,0,0, 'say Text',49117),
(@ENTRY,10,0, 'Grocery store owners everywhere will owe me a percentage of their profits!',12,0,100,1,0,0, 'say Text',49118),
(@ENTRY,11,0, 'I\'m flipping the second switch!',12,0,100,1,0,0, 'say Text',49119),
(@ENTRY,12,0, 'The micro mechachicken begins to grow and Greely starts sneaking away from the machine.',16,0,100,0,0,0, 'say Text',0),
(@ENTRY,13,0, 'Wait... something\'s wrong!',12,0,100,0,0,0, 'say Text',49120),
(@ENTRY,14,0, 'I know... I know! Where\'s the override? The override?!',14,0,100,0,0,0, 'say Text',49122),
(@ENTRY,15,0, 'Here goes nothing, I always loved you, Greely!',14,0,100,0,0,0, 'say Text',49124),
(@ENTRY,16,0, 'Flipping the override switch now!',14,0,100,0,0,0, 'say Text',49125),
(@ENTRY,17,0, 'The micro mechachicken quickly shrinks back to normal.',16,0,100,0,0,0, 'say Text',0),
(@ENTRY,18,0, 'Are we still alive?',12,0,100,0,0,0, 'say Text',49127),
(@ENTRY,19,0, 'Well of course we are, my dear Greely. And look there. The Micro Mechachicken\'s stabilization appears to be a complete success!',12,0,100,1,0,0, 'say Text',49129),
(@ENTRY,20,0, 'The micro mechachicken explodes.',16,0,100,0,0,0, 'say Text',0),
(@ENTRY,21,0, 'I haven\'t the foggiest notion what you\'re talking about, Miss Greely.',12,0,100,1,0,0, 'say Text',49133);
-- Izzy SAI
SET @ENTRY := 37708;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Izzy - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- Izzy SAI
SET @ENTRY := 35210;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Izzy - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- Jack the Hammer SAI
SET @ENTRY := 34877;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jack the Hammer - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,2,2,0,100,1,0,20,0,0,33,34877,0,0,0,0,0,7,0,0,0,0,0,0,0,"Jack the Hammer - Between 0-20% Health - Quest Credit '' (No Repeat)"),
(@ENTRY,0,2,3,61,0,100,1,0,20,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jack the Hammer - Between 0-20% Health - Set Faction 35 (No Repeat)"),
(@ENTRY,0,3,4,61,0,100,1,0,20,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jack the Hammer - Between 0-20% Health - Say Line 1 (No Repeat)"),
(@ENTRY,0,4,0,61,0,100,1,0,20,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jack the Hammer - Between 0-20% Health - Stop Attacking (No Repeat)"),
(@ENTRY,0,5,0,1,0,100,1,5000,5000,0,0,2,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jack the Hammer - Out of Combat - Set Faction 7 (No Repeat)"),
(@ENTRY,0,6,0,25,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jack the Hammer - On Reset - Start Attacking"),
(@ENTRY,0,7,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Jack the Hammer - On Gossip Hello - Play Random Emote (1, 3, 5, 6)"),
(@ENTRY,0,8,0,0,0,100,0,5000,7700,12300,16700,11,75986,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jack the Hammer - In Combat - Cast 'Knockback'"),
(@ENTRY,0,9,0,1,0,100,1,500,1000,0,0,11,76136,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jack the Hammer - Out of Combat - Cast 'Acidic Sweat' (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 34877;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '< Jack reported something about the hammer, which would be its armead you think. >',12,0,100,0,0,0, 'say Text on Aggro',48865),
(@ENTRY,1,0, '%s grunts and gives up, clearly beaten.',16,0,100,0,0,0, 'say Text on Beat',35132);
-- Kaja'Cola Balloon SAI
SET @ENTRY := 37804;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,30000,120000,30000,120000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kaja'Cola Balloon - Out of Combat - Say Line 0");
-- NPC talk text insert
SET @ENTRY := 37804;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Kaja\'Cola! Poissard the Weasel advise you to drink, or else ... !',14,0,50,0,0,0, 'say Text'),
(@ENTRY,0,1, '\"Lift it challenge the Goa\" to drink Kaja\'Cola!',14,0,50,0,0,0, 'say Text'),
(@ENTRY,0,2, 'Drink Kaja\'Cola!',14,0,50,0,0,0, 'say Text'),
(@ENTRY,0,3, 'Kaja\'Cola is proud to sponsor the Bilgewater Buccaneers!',14,0,50,0,0,0, 'say Text'),
(@ENTRY,0,4, 'Kaja\'Cola! When your hacks take the upper hand!',14,0,50,0,0,0, 'say Text'),
(@ENTRY,0,5, 'New k \' Cola! Still one hundred percent of ideas are more!',14,0,50,0,0,0, 'say Text');
-- Keensnout Potbelly SAI
SET @ENTRY := 35613;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,3385,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keensnout Potbelly - On Aggro - Cast 'Boar Charge' (No Repeat)");
-- Kezan Citizen SAI
SET @ENTRY := 35075;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Kezan Citizen - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- Kezan Citizen SAI
SET @ENTRY := 35063;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,60,0,100,0,1000,5000,1000,25000,89,20,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kezan Citizen - On Update - Start Random Movement");
-- Kezan Partygoer SAI
SET @ENTRY := 35201;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,60,0,100,0,1000,9000,10000,40000,5,18,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kezan Partygoer - On Update - Play Emote 18"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Kezan Partygoer - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- Kezan Partygoer SAI
SET @ENTRY := 35186;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,75046,0,15000,15000,5,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kezan Partygoer - On Spellhit 'Dance' - Play Emote 10"),
(@ENTRY,0,1,0,61,0,100,0,75046,0,15000,15000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kezan Partygoer - On Spellhit 'Dance' - Say Line 0"),
(@ENTRY,0,2,3,8,0,100,0,75044,0,15000,15000,5,17,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kezan Partygoer - On Spellhit 'Bucket' - Play Emote 17"),
(@ENTRY,0,3,0,61,0,100,0,75044,0,15000,15000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kezan Partygoer - On Spellhit 'Bucket' - Say Line 1"),
(@ENTRY,0,4,5,8,0,100,0,75042,0,12000,12000,5,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kezan Partygoer - On Spellhit 'Bubbly' - Play Emote 7"),
(@ENTRY,0,5,0,61,0,100,0,75042,0,12000,12000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kezan Partygoer - On Spellhit 'Bubbly' - Say Line 2"),
(@ENTRY,0,6,7,8,0,100,0,75048,0,12000,12000,5,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kezan Partygoer - On Spellhit 'Fireworks' - Play Emote 7"),
(@ENTRY,0,7,0,61,0,100,0,75048,0,12000,12000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kezan Partygoer - On Spellhit 'Fireworks' - Say Line 3"),
(@ENTRY,0,8,9,8,0,100,0,75050,0,10000,10000,5,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kezan Partygoer - On Spellhit 'Hors D'oeuvres' - Play Emote 7"),
(@ENTRY,0,9,0,61,0,100,0,75050,0,10000,10000,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kezan Partygoer - On Spellhit 'Hors D'oeuvres' - Say Line 4"),
(@ENTRY,0,10,0,1,0,60,0,2000,8000,10000,20000,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kezan Partygoer - Out of Combat - Say Line 5"),
(@ENTRY,0,11,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Kezan Partygoer - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- NPC talk text insert
SET @ENTRY := 37804;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'This party lacks a bit of brilliant',12,0,100,10,0,0, 'say Text'),
(@ENTRY,1,0, 'Thanks !',12,0,100,17,0,0, 'say Text'),
(@ENTRY,2,0, 'Passport delicious! And these are just the out-of A \"work?',12,0,100,7,0,0, 'say Text'),
(@ENTRY,3,0, 'Wouhaya, Fireworks! Again, again!',12,0,50,400,0,0, 'say Text'),
(@ENTRY,3,1, 'Woahhh! I have never seen anything as generally follows. Yet! Yet!',12,0,50,401,0,0, 'say Text'),
(@ENTRY,4,0, 'This white Pa wine and sparkling is delicious. Where have you found?',12,0,50,17,0,0, 'say Text'),
(@ENTRY,4,1, 'Thank you. I was soon offcourse. Yum yum!',12,0,50,7,0,0, 'say Text'),
(@ENTRY,5,0, 'I need a bucket!',12,0,50,1,0,0, 'say Text'),
(@ENTRY,5,1, 'I am hungry! But where is the food good blood?',14,0,50,6,0,0, 'say Text'),
(@ENTRY,5,2, 'If only I had someone with whom dance.',12,0,50,5,0,0, 'say Text'),
(@ENTRY,5,3, 'I love Fireworks! It is necessary that its repeats in the eardrum and it we have blouisse the view.',12,0,50,5,0,0, 'say Text'),
(@ENTRY,5,4, 'I love Fireworks!',12,0,50,5,0,0, 'say Text'),
(@ENTRY,5,5, 'Ah the love! Made go to your buttock Wouhaya Boniface!',12,0,50,21,0,0, 'say Text');
-- Kezan Partygoer SAI
SET @ENTRY := 35185;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,60,0,100,0,1000,5000,5000,25000,89,24,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kezan Partygoer - On Update - Start Random Movement"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Kezan Partygoer - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- Kezan Socialite SAI
SET @ENTRY := 48949;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Kezan Socialite - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- KTC Waiter SAI
SET @ENTRY := 48719;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"KTC Waiter - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- KTC Waitress SAI
SET @ENTRY := 48806;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"KTC Waitress - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- KTC Waitress SAI
SET @ENTRY := 48721;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,500,500,500,12,48340,7,0,0,0,0,1,0,0,0,0,0,0,0,"KTC Waitress - Out of Combat - Summon Creature 'Drink Tray'"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"KTC Waitress - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- Maxx Avalanche SAI
SET @ENTRY := 34695;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,78273,0,0,0,0,0,1,0,0,0,0,0,0,0,"Maxx Avalanche - Out of Combat - Cast 'Flametongue Weapon'"),
(@ENTRY,0,1,0,1,0,100,0,10000,20000,50000,60000,11,69626,0,0,0,0,0,19,34689,200,0,0,0,0,0,"Maxx Avalanche - Out of Combat - Cast 'Lightning Bolt'"),
(@ENTRY,0,2,0,1,0,100,0,10000,60000,300000,450000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Maxx Avalanche - Out of Combat - Say Line 0");
-- NPC talk text insert
SET @ENTRY := 34695;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Would one of you hurry up and finish off the other? Some of us are trying to make some moolah here!',12,0,100,1,0,0, 'say Text',36779);
-- Megs Dreadshredder SAI
SET @ENTRY := 34874;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,2,19,0,100,0,14071,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Megs Dreadshredder - On Quest '' Taken - Say Line 0"),
(@ENTRY,0,2,3,61,0,100,0,14071,0,0,0,11,91551,0,0,0,0,0,7,0,0,0,0,0,0,0,"Megs Dreadshredder - On Quest '' Taken - Cast 'Keys to the Hot Rod'"),
(@ENTRY,0,3,0,61,0,100,0,14071,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Megs Dreadshredder - On Quest '' Taken - Say Line 1"),
(@ENTRY,0,4,0,20,0,100,0,14071,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Megs Dreadshredder - On Quest '' Finished - Say Line 2"),
(@ENTRY,0,5,0,19,0,100,0,14121,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,"Megs Dreadshredder - On Quest '' Taken - Say Line 3"),
(@ENTRY,0,6,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Megs Dreadshredder - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- NPC talk text insert
SET @ENTRY := 34874;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Ooh, I think you\'re gonna like this,boss!',12,0,100,1,0,0, 'say Text',49019),
(@ENTRY,1,0, 'Use the Keys to the Hot Rod |TInterface\Icons\inv_misc_key_12.blp:32|t to get into your car. Pick up your friends, Izzy, Ace, and Gobber.',41,0,100,1,0,0, 'say Text',48504),
(@ENTRY,2,0, 'Here they are! Okay, you three make sure that you help him out today. He\'s got a lot of stuff to take care of before the party!',12,0,100,1,0,0, 'say Text',49020),
(@ENTRY,3,0, 'Use your Hot Rod |TInterface\Icons\inv_misc_key_12.blp:32|t to run over Hired Looters and get their loot.',41,0,100,1,0,0, 'say Text',48844);
-- Missa Spekkies SAI
SET @ENTRY := 35130;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,3,0,0,0,56,47047,1,0,0,0,0,7,0,0,0,0,0,0,0,"Missa Spekkies - On Gossip Option 0 Selected - Add Item '' 1 Time"),
(@ENTRY,0,1,0,61,0,100,0,3,0,0,0,72,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Missa Spekkies - On Gossip Option 0 Selected - Close Gossip"),
(@ENTRY,0,2,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Missa Spekkies - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- Neill Penny SAI
SET @ENTRY := 51411;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Neill Penny - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- Pirate Party Crasher SAI
SET @ENTRY := 35200;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8900,11000,17800,11,75361,0,0,0,0,0,2,0,0,0,0,0,0,0,"Pirate Party Crasher - In Combat - Cast 'Swashbuckling Slice'"),
(@ENTRY,0,1,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pirate Party Crasher - On Aggro - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 35200;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'We be here courtesy o\' the trade prince.',12,0,50,0,0,0, 'on Aggro Text',35450),
(@ENTRY,0,1, 'Let\'s have a dance!',12,0,50,0,0,0, 'on Aggro Text',35449),
(@ENTRY,0,2, 'Who be in charge here?',12,0,50,0,0,0, 'on Aggro Text',35454);
-- Rebellious Troll SAI
SET @ENTRY := 35294;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,80,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rebellious Troll - On Aggro - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 35294;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I not gonna take it anymore,mon!',12,0,50,0,0,0, 'on Aggro Text',49041),
(@ENTRY,0,1, 'Kezan for da trolls!',12,0,50,0,0,0, 'on Aggro Text',49042),
(@ENTRY,0,2, 'Ya got some nerve,mon!',12,0,50,0,0,0, 'on Aggro Text',49039),
(@ENTRY,0,3, 'Maybe I take dem bombs from ya an\' we see who go boom!',12,0,50,0,0,0, 'on Aggro Text',49044);
-- Sally "Salvager" Sandscrew SAI
SET @ENTRY := 37761;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Sally Salvager Sandscrew - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- Sassy Hardwrench SAI
SET @ENTRY := 34668;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Sassy Hardwrench - On Gossip Hello - Play Random Emote (1, 3, 5, 6)"),
(@ENTRY,0,1,0,19,0,100,0,14138,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sassy Hardwrench - On Quest '' Taken - Say Line 0"),
(@ENTRY,0,2,0,20,0,100,0,25473,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sassy Hardwrench - On Quest '' Finished - Say Line 1"),
(@ENTRY,0,3,0,19,0,100,0,14070,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sassy Hardwrench - On Quest '' Taken - Say Line 2"),
(@ENTRY,0,4,0,20,0,100,0,14070,0,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sassy Hardwrench - On Quest '' Finished - Play Emote 4"),
(@ENTRY,0,5,0,19,0,100,0,14115,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sassy Hardwrench - On Quest '' Taken - Say Line 3"),
(@ENTRY,0,6,0,20,0,100,0,14115,0,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sassy Hardwrench - On Quest '' Finished - Play Emote 4"),
(@ENTRY,0,7,0,19,0,100,0,14116,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sassy Hardwrench - On Quest '' Taken - Say Line 4"),
(@ENTRY,0,8,0,19,0,100,0,14122,0,0,0,1,5,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sassy Hardwrench - On Quest '' Taken - Say Line 5"),
(@ENTRY,0,9,13,20,0,100,0,14113,0,0,0,28,66908,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sassy Hardwrench - On Quest '' Finished - Remove Aura 'Awesome Party Ensemble'"),
(@ENTRY,0,10,0,20,0,100,0,14153,0,0,0,28,59073,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sassy Hardwrench - On Quest '' Finished - Remove Aura 'Phase - Quest Zone-Specific 01'"),
(@ENTRY,0,11,0,20,0,100,0,14122,0,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sassy Hardwrench - On Quest '' Finished - Play Emote 4"),
(@ENTRY,0,12,0,20,0,100,0,14125,0,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sassy Hardwrench - On Quest '' Finished - Play Emote 4"),
(@ENTRY,0,13,0,61,0,100,0,14113,0,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sassy Hardwrench - On Quest '' Finished - Play Emote 4"),
(@ENTRY,0,14,0,20,0,100,0,24520,0,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sassy Hardwrench - On Quest '' Finished - Play Emote 4"),
(@ENTRY,0,15,0,19,0,100,0,14125,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sassy Hardwrench - On Quest '' Taken - Say Line 6"),
(@ENTRY,0,16,0,19,0,100,0,14126,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sassy Hardwrench - On Quest '' Taken - Say Line 7");
-- NPC talk text insert
SET @ENTRY := 34668;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Haha! that should be a blast!',12,0,100,25,0,0, 'say Text',43954),
(@ENTRY,1,0, 'He\'ll get me more later? How are we supposed to get you promoted to Trade Prince without our number one product on the shelves?',12,0,100,1,0,0, 'say Text',49018),
(@ENTRY,2,0, 'Ace,Izzy,Gobber,you three make sure you tag a long with $N and help him take care of those dead beats!',12,0,100,1,0,0, 'say Text',49021),
(@ENTRY,3,0, 'Go get \'em,boss!',12,0,100,1,0,0, 'say Text',37318),
(@ENTRY,4,0, 'You better get upstairs pronto, boss. Trade Prince Gallywix is waiting for you.',12,0,100,1,0,0, 'say Text',49015),
(@ENTRY,5,0, '$N, you have to hurry and break your moolah out of the bank!',12,0,100,1,0,0, 'say Text',49016),
(@ENTRY,6,0, 'I can\'t stand to watch. So many good memories. So much profit.',12,0,100,1,0,0, 'say Text',49071),
(@ENTRY,7,0, 'The Trade Prince\'s yacht is about to set sail. Everyone, get to the dock! Hand over the keys, boss. I\'m driving. Just let me know when you\'re ready to go.',12,0,100,1,0,0, 'say Text',40278);
-- Sister Goldskimmer SAI
SET @ENTRY := 34692;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,10,0,100,0,1,8,5000,6000,11,74973,32,0,0,0,0,17,0,8,0,0,0,0,0,"Sister Goldskimmer - Within 1-8 Range Out of Combat LoS - Cast 'Power Word: Fortitude'"),
(@ENTRY,0,1,0,61,0,100,0,1,8,5000,6000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sister Goldskimmer - Within 1-8 Range Out of Combat LoS - Say Line 0"),
(@ENTRY,0,2,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Sister Goldskimmer - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- NPC talk text insert
SET @ENTRY := 34692;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'It\'s not much, but it just might keep your green skin intact.',12,0,50,1,0,0, 'say Text',36727),
(@ENTRY,0,1, 'Just wanted to let you know that we\'re all counting on you!',12,0,50,1,0,0, 'say Text',36728),
(@ENTRY,0,2, 'Light be with you... for the very low price of a one silver tithe!',12,0,50,1,0,0, 'say Text',36722);
-- Slinky Sharpshiv SAI
SET @ENTRY := 34693;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,60,0,100,0,1000,1000,500000,500000,11,1784,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slinky Sharpshiv - On Update - Cast 'Stealth'"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Slinky Sharpshiv - On Gossip Hello - Play Random Emote (1, 3, 5, 6)"),
(@ENTRY,0,2,0,20,0,100,0,14123,0,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slinky Sharpshiv - On Quest '' Finished - Play Emote 4"),
(@ENTRY,0,3,0,19,0,100,0,14115,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slinky Sharpshiv - On Quest '' Taken - Say Line 0"),
(@ENTRY,0,4,0,60,0,100,0,5000,5000,510000,510000,28,1784,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slinky Sharpshiv - On Update - Remove Aura 'Stealth'"),
(@ENTRY,0,5,0,19,0,100,0,14010,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slinky Sharpshiv - On Quest '' Taken - Say Line 1"),
(@ENTRY,0,6,0,20,0,100,0,14010,0,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slinky Sharpshiv - On Quest '' Finished - Play Emote 4");
SET @ENTRY := 34693;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'I\'ll address the CAP so that it activates automatically when you\'re at the villa. Do just well warning avoid pigs!',12,0,100,1,0,0, 'say Text'),
(@ENTRY,1,0, 'All what you have to do is let me show you how was a Visca cooperation. Then, head to one of the models to lead training on which Bamm is going to pull, start a pernicious attack and finish it with a Visca cooperation.',12,0,100,1,0,0, 'say Text');
-- Sudsy Magee SAI
SET @ENTRY := 34878;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sudsy Magee - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,2,2,0,100,1,0,20,0,0,33,34878,0,0,0,0,0,7,0,0,0,0,0,0,0,"Sudsy Magee - Between 0-20% Health - Quest Credit '' (No Repeat)"),
(@ENTRY,0,2,3,61,0,100,1,0,20,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sudsy Magee - Between 0-20% Health - Set Faction 35 (No Repeat)"),
(@ENTRY,0,3,4,61,0,100,1,0,20,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sudsy Magee - Between 0-20% Health - Say Line 1 (No Repeat)"),
(@ENTRY,0,4,0,61,0,100,1,0,20,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sudsy Magee - Between 0-20% Health - Stop Attacking (No Repeat)"),
(@ENTRY,0,5,0,1,0,100,1,5000,5000,0,0,2,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sudsy Magee - Out of Combat - Set Faction 7 (No Repeat)"),
(@ENTRY,0,6,0,25,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sudsy Magee - On Reset - Start Attacking"),
(@ENTRY,0,7,0,0,0,100,0,0,0,3400,4700,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sudsy Magee - In Combat - Cast 'Frostbolt'"),
(@ENTRY,0,8,0,0,0,100,0,9800,11000,17600,25400,11,75761,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sudsy Magee - In Combat - Cast 'Bubble Blast'");
-- NPC talk text insert
SET @ENTRY := 34878;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I\'m tryin\' to run a business here!',12,0,100,0,0,0, 'say Text on Aggro',48864),
(@ENTRY,1,0, 'Not the face, not the face!',12,0,100,1,0,0, 'say Text on Beat',35136);
-- Szabo SAI
SET @ENTRY := 35128;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,3,0,0,0,56,47046,1,0,0,0,0,7,0,0,0,0,0,0,0,"Szabo - On Gossip Option 0 Selected - Add Item '' 1 Time"),
(@ENTRY,0,1,0,61,0,100,0,3,0,0,0,72,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Szabo - On Gossip Option 0 Selected - Close Gossip"),
(@ENTRY,0,2,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Szabo - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- Tunneling Worm SAI
SET @ENTRY := 34865;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,7700,13200,16700,11,32738,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tunneling Worm - In Combat - Cast 'Bore'");
-- Villa Mook SAI
SET @ENTRY := 35623;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,500,1000,0,0,11,76136,0,0,0,0,0,1,0,0,0,0,0,0,0,"Villa Mook - Out of Combat - Cast 'Acidic Sweat' (No Repeat)");
-- Villa Mook SAI
SET @ENTRY := 49218;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,500,1000,0,0,11,76136,0,0,0,0,0,1,0,0,0,0,0,0,0,"Villa Mook - Out of Combat - Cast 'Acidic Sweat' (No Repeat)");
-- Villa Mook SAI
SET @ENTRY := 35609;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,500,1000,0,0,11,76136,0,0,0,0,0,1,0,0,0,0,0,0,0,"Villa Mook - Out of Combat - Cast 'Acidic Sweat' (No Repeat)"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Villa Mook - On Aggro - Cast 'Battle Shout' (No Repeat)");
-- Villa Mook SAI
SET @ENTRY := 37683;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,500,1000,0,0,11,76136,0,0,0,0,0,1,0,0,0,0,0,0,0,"Villa Mook - Out of Combat - Cast 'Acidic Sweat' (No Repeat)");
-- Vinny Slapchop SAI
SET @ENTRY := 37500;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,60,0,100,0,15000,60000,30000,350000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vinny Slapchop - On Update - Say Line 0"),
(@ENTRY,0,1,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,"Vinny Slapchop - On Gossip Hello - Play Random Emote (1, 3, 5, 6)");
-- NPC talk text insert
SET @ENTRY := 37500;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Volcano rocks - new low price! You\'re gonna love my rocks.',14,0,50,1,0,0, 'say Text',37100),
(@ENTRY,0,1, 'Volcano rocks for sale! Hot off the mountain! You want \'em, I got \'em!',14,0,50,1,0,0, 'say Text',37099),
(@ENTRY,0,2, 'Take home a piece of the Cataclysm! Volcano rocks for sale - hot, Hot, HOT!',14,0,50,1,0,0, 'say Text',37102),
(@ENTRY,0,3, 'Get your volcano rocks here! ...Great for cats!',14,0,50,1,0,0, 'say Text',37101),
(@ENTRY,0,4, 'Volcano rocks. Million and one uses. Lava, java, sauna, banana....',14,0,50,1,0,0, 'say Text',37104),
(@ENTRY,0,5, 'Papers to weigh? Doors to stop? Windows to break? bam, Bam, BAM! Volcano rocks.',14,0,50,1,0,0, 'say Text',37103),
(@ENTRY,0,6, 'Volcano rocks! Limited time offer! Papers of authenticity and everything!',14,0,50,1,0,0, 'say Text',37106);
-- Warrior-Matic NX-01 SAI
SET @ENTRY := 34697;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,14013,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warrior-Matic NX-01 - On Quest '' Taken - Say Line 3");
-- NPC talk text insert
SET @ENTRY := 34697;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Insert your coins inside the Warrior NX-01, who\'s learn you. Then use the technique on one of the models to lead training.',12,0,100,0,0,0, 'say Text');

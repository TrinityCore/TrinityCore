-- Balos Jacken SAI
SET @ENTRY := 5089;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,20,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Balos Jacken - Between 0-20% Health - Say Line 0"),
(@ENTRY,0,1,0,2,0,100,1,0,20,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Balos Jacken - Between 0-20% Health - Evade"),
(@ENTRY,0,2,0,2,0,100,1,0,20,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Balos Jacken - Between 0-20% Health - Increment Event Phase"),
(@ENTRY,0,3,4,21,2,100,1,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Balos Jacken - On Just Reached Home - Set Faction 35 (Phase 2)"),
(@ENTRY,0,4,0,61,2,100,1,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Balos Jacken - On Just Reached Home - Increment Event Phase (Phase 2)"),
(@ENTRY,0,5,0,1,0,100,0,120000,120000,120000,120000,2,54,0,0,0,0,0,1,0,0,0,0,0,0,0,"Balos Jacken - Out Of Combat - Set Faction 54"),
(@ENTRY,0,6,0,1,0,100,0,120000,120000,120000,120000,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Balos Jacken - Out Of Combat - Set Event Phase 0");

-- Texts for Balos Jacken
SET @ENTRY := 5089;
DELETE FROM creature_ai_texts WHERE entry IN (-775);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Alright! We Surrender... Just put your weapons down, I'll cooperate",12,0,100,0,0,0,"Balos Jacken");

-- Cerellean Whiteclaw SAI
SET @ENTRY := 3644;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,17,0,100,0,3843,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cerellean Whiteclaw - On Summoned Unit - run script'),
(@ENTRY,0,1,0,1,0,100,0,15000,15000,15000,15000,5,18,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cerellean Whiteclaw - Out Of Combat - Emote Cry"),
(@ENTRY*100,9,0,0,0,0,100,0,100,100,0,0,90,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cerellean Whiteclaw - Script - Set Standstate Stand Up"),
(@ENTRY*100,9,1,0,0,0,100,0,100,100,0,0,5,18,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cerellean Whiteclaw - Script - Emote Cry"),
(@ENTRY*100,9,2,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cerellean Whiteclaw - Script - Say Line 0"),
(@ENTRY*100,9,3,0,0,0,100,0,8000,8000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cerellean Whiteclaw - Script - Say Line 1"),
(@ENTRY*100,9,4,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cerellean Whiteclaw - Script - Say Line 2"),
(@ENTRY*100,9,5,0,0,0,100,0,15000,15000,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cerellean Whiteclaw - Script - Set Standstate Kneel"),
(@ENTRY*100,9,6,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cerellean Whiteclaw - Script - Say Line 3"),
(@ENTRY*100,9,7,0,0,0,100,0,15000,15000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cerellean Whiteclaw - Script - Say Line 4");

-- Texts for Cerellean Whiteclaw
SET @ENTRY := 3644;
DELETE FROM creature_ai_texts WHERE entry BETWEEN -665 AND -661;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Anaya...? Do my eyes deceive me? Is it really you?",12,0,100,1,0,0,"Cerellean Whiteclaw"),
(@ENTRY,1,0,"That fates should be so cruel as to permit us only this after a thousand years apart...",16,0,100,1,0,0,"Cerellean Whiteclaw"),
(@ENTRY,2,0,"Do you hate me, my love? That I was forced to destroy your living form, that your spirit be released from unhappy bondage.",16,0,100,1,0,0,"Cerellean Whiteclaw"),
(@ENTRY,3,0,"No! Anaya... Anaya! Don't leave me! Please...",12,0,100,5,0,0,"Cerellean Whiteclaw"),
(@ENTRY,4,0,"How, my love? How will I find the strength to face the ages of the world without you by my side...",12,0,100,5,0,0,"Cerellean Whiteclaw");

-- Anaya SAI
SET @ENTRY := 3843;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,10000,10000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anaya - Out Of Combat - Say Line 0"),
(@ENTRY,0,1,0,1,0,100,1,25000,25000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anaya - Out Of Combat - Say Line 1"),
(@ENTRY,0,2,0,1,0,100,1,30000,30000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anaya - Out Of Combat - Say Line 2"),
(@ENTRY,0,3,0,1,0,100,1,40000,40000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anaya - Out Of Combat - Say Line 3"),
(@ENTRY,0,4,0,1,0,100,1,44000,44000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anaya - Out Of Combat - Say Line 4");

-- Texts for Anaya
SET @ENTRY := 3843;
DELETE FROM creature_ai_texts WHERE entry BETWEEN -670 AND -666;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"The ages have been cruel to you and I, my love, but be assured, it is, and at long last we are reunited.",12,0,100,1,0,0,"Anaya"),
(@ENTRY,1,0,"Let it not trouble your heart, beloved. You have freed me from slavery, and for that I love you all the more.",12,0,100,1,0,0,"Anaya"),
(@ENTRY,2,0,"Sadly, even this must be cut short... The ties that bind me to this world weaken, and pull me away...",12,0,100,1,0,0,"Anaya"),
(@ENTRY,3,0,"Farewell, Cerellean, until we are joined once again...",12,0,100,1,0,0,"Anaya"),
(@ENTRY,4,0,"%s's soft voice trails away into the mists, \"Know that I love you always...\"",16,0,100,0,0,0,"Anaya");

-- Velinde Starsong SAI
SET @ENTRY := 3946;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Velinde Starsong - On Respawn - Set Standstate Kneel"),
(@ENTRY,0,1,0,1,0,100,1,5000,5000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Velinde Starsong - Out Of Combat - Say Line 0"),
(@ENTRY,0,2,0,1,0,100,1,10000,10000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Velinde Starsong - Out Of Combat - Say Line 1"),
(@ENTRY,0,3,0,1,0,100,1,15000,15000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Velinde Starsong - Out Of Combat - Say Line 2");

-- Texts for Velinde Starsong
SET @ENTRY := 3946;
DELETE FROM creature_ai_texts WHERE entry BETWEEN -660 AND -658;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"The numbers of my companions dwindles, goddess, and my own power shall soon be insufficient to hold back the demons of Felwood.",12,0,100,1,0,0,"Velinde Starsong"),
(@ENTRY,1,0,"Goddess, grant me the power to overcome my enemies! Hear me, please, my need is desperate and my cause is just!",12,0,100,1,0,0,"Velinde Starsong"),
(@ENTRY,2,0,"What... what is this? Could this be the answer to my prayers? Elune has granted me a weapon--this scythe--to defeat the demons.",12,0,100,1,0,0,"Velinde Starsong");

-- Sargath SAI
SET @ENTRY := 4509;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sargath - Out Of Combat - Say Line 0"),
(@ENTRY,0,1,0,1,0,100,1,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sargath - Out Of Combat - Say Line 1"),
(@ENTRY,0,2,0,1,0,100,1,10000,10000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sargath - Out Of Combat - Say Line 2"),
(@ENTRY,0,3,0,1,0,100,1,15000,15000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sargath - Out Of Combat - Say Line 3"),
(@ENTRY,0,4,0,1,0,100,1,20000,20000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sargath - Out Of Combat - Say Line 4"),
(@ENTRY,0,5,0,1,0,100,1,28000,28000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sargath - Out Of Combat - Say Line 5");

-- Texts for Sargath
SET @ENTRY := 4509;
DELETE FROM creature_ai_texts WHERE entry BETWEEN -147 AND -142;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"In the throes of the Sundering, Ameth'Aran was at the whim of the terror that gripped the land. There was little hope for survival.",12,0,100,1,0,0,"Sargath"),
(@ENTRY,1,0,"Athrikus came to us. He told us that he could save us from harm. He cast a spell upon us to protect us from harm.",12,0,100,1,0,0,"Sargath"),
(@ENTRY,2,0,"When the shaking stopped, his true motives were revealed. We were trapped, and he was slowly draining our powers.",12,0,100,1,0,0,"Sargath"),
(@ENTRY,3,0,"There were hundreds imprisoned by his spell. Now only a few remain in their prisons. He would speak to us sometimes.",12,0,100,1,0,0,"Sargath"),
(@ENTRY,4,0,"He worried that his power weakened, that soon even we last of his precious soulgems would fade and die.",12,0,100,1,0,0,"Sargath"),
(@ENTRY,5,0,"His lieutenant, Ilkurd Magthrull possesses a tome which might indicate the location of the remaining soulgems.",12,0,100,1,0,0,"Sargath");

-- Wilfred Fizzlebang SAI
SET @ENTRY := 35476;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,140000,180000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wilfred Fizzlebang - OOC - run script'),
(@ENTRY*100,0,0,0,0,0,100,0,0,0,0,0,28,45104,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wilfred Fizzlebang - Script - Remove Aura 45104"),
(@ENTRY*100,0,1,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wilfred Fizzlebang - Script - Say Line 0"),
(@ENTRY*100,0,2,0,0,0,100,0,3000,3000,0,0,5,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wilfred Fizzlebang - Script - Emote Exclamation"),
(@ENTRY*100,0,3,0,0,0,100,0,4000,4000,0,0,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wilfred Fizzlebang - Script - Emote Laugh"),
(@ENTRY*100,0,4,0,0,0,100,0,6000,6000,0,0,11,45104,2,0,0,0,0,1,0,0,0,0,0,0,0,"Wilfred Fizzlebang - Script - Cast 45104");

-- Texts for Wilfred Fizzlebang
SET @ENTRY := 35476;
DELETE FROM creature_ai_texts WHERE entry IN (-10000, -10019);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Of course I was the one Chosen to summon a demon for the competitors. I am %s, master summoner! Demons quail before the mere thought of being under my will!",12,0,100,1,0,0,"Wilfred Fizzlebang"),
(@ENTRY,0,1,"Soon all the world will know the name of Wilfred!",12,0,100,1,0,0,"Wilfred Fizzlebang");

-- Quest 12544 "The Bones of Nozronn"
-- Remove kill credit for quest 12544 from event scripts
DELETE FROM `event_scripts` WHERE `id`=18481 AND `command`=8;

-- Voice of Nozronn SAI
SET @ENTRY := 28256;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,80,@ENTRY*100,0,0,0,0,0,7,0,0,0,0,0,0,0,'Voice of Nozronn - On Respawn - run script'),
(@ENTRY*100,9,0,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Voice of Nozronn - Script - Say Line 0"),
(@ENTRY*100,9,1,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Voice of Nozronn - Script - Say Line 1"),
(@ENTRY*100,9,2,0,0,0,100,0,5000,5000,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Voice of Nozronn - Script - Say Line 2"),
(@ENTRY*100,9,3,0,0,0,100,0,5000,5000,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,"Voice of Nozronn - Script - Say Line 3"),
(@ENTRY*100,9,4,0,0,0,100,0,5000,5000,0,0,1,4,0,0,0,0,0,7,0,0,0,0,0,0,0,"Voice of Nozronn - Script - Say Line 4"),
(@ENTRY*100,9,5,0,0,0,100,0,5000,5000,0,0,33,28256,0,0,0,0,0,7,0,0,0,0,0,0,0,"Voice of Nozronn - Script - Give Kill Credit");

-- Texts for Voice of Nozronn
SET @ENTRY := 28256;
DELETE FROM creature_ai_texts WHERE entry BETWEEN -10018 AND -10015;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"So the oracle has decided to aid you, outlander. Very well, I will offer you what I know.",12,0,100,0,0,0,"Voice of Nozronn"),
(@ENTRY,1,0,"Your companion seeks the shardhorn patriarch Farunn, who holds himself aloof from his brothers.",12,0,100,0,0,0,"Voice of Nozronn"),
(@ENTRY,2,0,"Farunn walks the lands north of what your people call the Bittertide Falls. You will find him alone, but you will see her requires no defenders.",12,0,100,0,0,0,"Voice of Nozronn"),
(@ENTRY,3,0,"Return to your companion. Tell him to go forth and claim his prize in Farunn.",12,0,100,0,0,0,"Voice of Nozronn"),
(@ENTRY,4,0,"Once he has done so, tell him to leave this land in peace. He does not belong here.",12,0,100,0,0,0,"Voice of Nozronn");

-- Delgren the Purifier SAI
SET @ENTRY := 3663;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Delgren the Purifier - Between 0-15% Health - Flee For Assist");

-- Wrathtail Wave Rider SAI
SET @ENTRY := 3713;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Wrathtail Wave Rider - Between 0-15% Health - Flee For Assist");

-- Skittering Crustacean SAI
SET @ENTRY := 4821;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Skittering Crustacean - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Snapping Crustacean SAI
SET @ENTRY := 4822;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Snapping Crustacean - Between 0-15% Health - Flee For Assist (Normal Dungeon)");

-- Therysil SAI
SET @ENTRY := 3585;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Therysil - Between 0-15% Health - Flee For Assist");

-- Bloodfeather Harpy SAI
SET @ENTRY := 2015;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,70,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bloodfeather Harpy - On Aggro - Say Line 0");

-- Bloodfeather Rogue SAI
SET @ENTRY := 2017;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bloodfeather Rogue - On Aggro - Say Line 0");

-- Verog the Dervish SAI
SET @ENTRY := 3395;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Verog the Dervish - On Respawn - Say Line 0");

-- Pilot Wizzlecrank SAI
SET @ENTRY := 3451;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,6000,6000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pilot Wizzlecrank - Out Of Combat - Say Line 0"),
(@ENTRY,0,1,0,1,0,100,1,12000,12000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pilot Wizzlecrank - Out Of Combat - Say Line 1");

-- Bogling SAI
SET @ENTRY := 3569;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,60,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bogling - On Aggro - Say Line 0");

-- Mosshoof Courser SAI
SET @ENTRY := 8761;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshoof Courser - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshoof Courser - Between 0-30% Health - Say Line 0");

-- Sandfury Zealot SAI
SET @ENTRY := 8877;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,3,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Zealot - Between 0-30% Health - Cast 8599 (Normal Dungeon)"),
(@ENTRY,0,1,0,2,0,100,3,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sandfury Zealot - Between 0-30% Health - Say Line 0 (Normal Dungeon)");

-- Texts for Bloodfeather Harpy
SET @ENTRY := 2015;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"You will be easy prey, $c.",14,0,100,0,0,0,"Bloodfeather Harpy");

-- Texts for Bloodfeather Rogue
SET @ENTRY := 2017;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"A fine trophy your head will make, $r.",12,0,100,0,0,0,"Bloodfeather Rogue"),
(@ENTRY,0,1,"My talons will shred your puny body, $r.",12,0,100,0,0,0,"Bloodfeather Rogue"),
(@ENTRY,0,2,"You will be easy prey, $c.",14,0,100,0,0,0,"Bloodfeather Rogue");

-- Texts for Verog the Dervish
SET @ENTRY := 3395;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"I am summoned! Intruders, come to my tent and face your death!",14,0,100,0,0,0,"Verog the Dervish");

-- Texts for Pilot Wizzlecrank
SET @ENTRY := 3451;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Looks like you'll have to go ahead to Ratchet and tell Sputtervalve that I've wrecked the shredder.",12,0,100,0,0,0,"Pilot Wizzlecrank"),
(@ENTRY,1,0,"I'll stay behind and guard the wreck. Hurry! Hopefully no one will notice the smoke...",12,0,100,0,0,0,"Pilot Wizzlecrank");

-- Texts for Bogling
SET @ENTRY := 3569;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"KILL!!!",12,0,100,0,0,0,"Bogling");

-- Texts for Mosshoof Courser
SET @ENTRY := 8761;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Mosshoof Courser");

-- Texts for Sandfury Zealot
SET @ENTRY := 8877;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Sandfury Zealot");

-- Kvaldir Berserker SAI
SET @ENTRY := 34947;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,8000,11000,11,38557,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kvaldir Berserker - In Combat - Cast 38557"),
(@ENTRY,0,1,0,9,0,100,0,0,5,5000,7000,11,43410,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kvaldir Berserker - Between 0-5 Range - Cast 43410"),
(@ENTRY,0,2,0,2,0,100,0,0,30,40000,40000,11,3019,1,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Berserker - Between 0-30% Health - Cast 3019");

-- Drottinn Hrothgar SAI
SET @ENTRY := 34980;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,11,66625,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drottinn Hrothgar - Out Of Combat - Cast 66625"),
(@ENTRY,0,1,0,1,0,100,1,1500,1500,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drottinn Hrothgar - Out Of Combat - Say Line 0"),
(@ENTRY,0,2,0,9,0,100,0,0,5,5000,7000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drottinn Hrothgar - Between 0-5 Range - Cast 15496"),
(@ENTRY,0,3,0,0,0,100,0,12000,16000,15000,21000,11,67038,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drottinn Hrothgar - In Combat - Cast 67038");

-- Texts for Drottinn Hrothgar
SET @ENTRY := 34980;
DELETE FROM creature_ai_texts WHERE entry IN (-796);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"You dare to challenge Drottin Hrothgar, king of the seas?",14,0,100,0,0,0,"Drottinn Hrothgar");

-- Ornolf the Scarred SAI
SET @ENTRY := 35012;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,8000,11000,11,38557,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ornolf the Scarred - In Combat - Cast 38557"),
(@ENTRY,0,1,0,9,0,100,0,0,5,5000,7000,11,43410,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ornolf the Scarred - Between 0-5 Range - Cast 43410"),
(@ENTRY,0,2,0,0,0,100,0,8000,11000,8000,11000,11,67037,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ornolf the Scarred - In Combat - Cast 67037"),
(@ENTRY,0,3,0,2,0,100,0,0,30,40000,40000,11,3019,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ornolf the Scarred - Between 0-30% Health - Cast 3019");

-- Kvaldir Reaver SAI
SET @ENTRY := 34838;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,12000,15000,11,49922,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kvaldir Reaver - In Combat - Cast 49922");

-- Kvaldir Mist Binder SAI
SET @ENTRY := 34839;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,45658,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kvaldir Mist Binder - Out Of Combat - Cast 45658 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,12000,17000,11,49816,0,0,0,0,0,5,0,0,0,0,0,0,0,"Kvaldir Mist Binder - In Combat - Cast 49816");

-- Frigid Abomination SAI
SET @ENTRY := 33704;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,7000,10000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frigid Abomination - Between 0-5 Range - Cast 40504");

-- Orabus the Helmsman SAI
SET @ENTRY := 32576;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orabus the Helmsman - On Respawn - Say Line 0"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orabus the Helmsman - On Aggro - Say Line 1");

-- Texts for Orabus the Helmsman
SET @ENTRY := 32576;
DELETE FROM creature_ai_texts WHERE entry BETWEEN -348 AND -347;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"The Helmsman comes for you!",14,0,100,0,0,0,"Orabus the Helmsman"),
(@ENTRY,1,0,"Now you face Orabus, fool!",14,0,100,0,0,0,"Orabus the Helmsman");

-- Surveyor Hansen SAI
SET @ENTRY := 32599;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,20,9000,14000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Surveyor Hansen - Between 0-20 Range - Cast 12024"),
(@ENTRY,0,1,0,9,0,100,0,0,5,5000,8000,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,"Surveyor Hansen - Between 0-5 Range - Cast 14516");

-- Vyragosa SAI
SET @ENTRY := 32630;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,35,7000,9000,11,47425,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vyragosa - Between 0-35 Range - Cast 47425"),
(@ENTRY,0,1,0,9,0,100,0,0,5,3000,6000,11,51857,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vyragosa - Between 0-5 Range - Cast 51857");

-- Smoldering Skeleton SAI
SET @ENTRY := 33016;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,51437,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smoldering Skeleton - On Aggro - Cast 51437");

-- Smoldering Construct SAI
SET @ENTRY := 33017;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,9000,14000,17000,11,51439,0,0,0,0,0,1,0,0,0,0,0,0,0,"Smoldering Construct - In Combat - Cast 51439");

-- Aotona SAI
SET @ENTRY := 32481;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,12000,15000,11,49865,0,0,0,0,0,2,0,0,0,0,0,0,0,"Aotona - In Combat - Cast 49865"),
(@ENTRY,0,1,0,0,0,100,0,9000,13000,10000,15000,11,51144,1,0,0,0,0,1,0,0,0,0,0,0,0,"Aotona - In Combat - Cast 51144");

-- King Krush SAI
SET @ENTRY := 32485;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,8,25,12000,16000,11,36140,0,0,0,0,0,2,0,0,0,0,0,0,0,"King Krush - Between 8-25 Range - Cast 36140"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,6000,9000,11,48137,0,0,0,0,0,2,0,0,0,0,0,0,0,"King Krush - In Combat - Cast 48137"),
(@ENTRY,0,2,0,0,0,100,0,12000,15000,22000,23000,11,36629,1,0,0,0,0,1,0,0,0,0,0,0,0,"King Krush - In Combat - Cast 36629");

-- Time-Lost Proto Drake SAI
SET @ENTRY := 32491;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,6000,12000,15000,11,51020,0,0,0,0,0,2,0,0,0,0,0,0,0,"Time-Lost Proto Drake - In Combat - Cast 51020"),
(@ENTRY,0,1,0,1,0,100,0,9000,12000,20000,25000,11,61084,1,0,0,0,0,1,0,0,0,0,0,0,0,"Time-Lost Proto Drake - Out Of Combat - Cast 61084");

-- Dirkee SAI
SET @ENTRY := 32500;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,9000,14000,11,61110,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dirkee - In Combat - Cast 61110"),
(@ENTRY,0,1,0,0,0,100,0,9000,13000,15000,19000,11,61103,0,0,0,0,0,5,0,0,0,0,0,0,0,"Dirkee - In Combat - Cast 61103");

-- Loque'nahak SAI
SET @ENTRY := 32517;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,12000,15000,11,61184,0,0,0,0,0,2,0,0,0,0,0,0,0,"Loque'nahak - In Combat - Cast 61184");

-- Warmage Yurias SAI
SET @ENTRY := 32375;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmage Yurias - Out Of Combat - Cast 12544");

-- Crazed Indu'le Survivor SAI
SET @ENTRY := 32409;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,8000,10000,15000,11,39171,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crazed Indu'le Survivor - In Combat - Cast 39171"),
(@ENTRY,0,1,0,2,0,100,0,0,30,15000,20000,11,48139,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crazed Indu'le Survivor - Between 0-30% Health - Cast 48139");

-- Scarlet Highlord Daion SAI
SET @ENTRY := 32417;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,7000,10000,11,48280,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Highlord Daion - In Combat - Cast 48280"),
(@ENTRY,0,1,0,2,0,100,0,0,50,15000,19000,11,35949,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Highlord Daion - Between 0-50% Health - Cast 35949");

-- Grocklar SAI
SET @ENTRY := 32422;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,49676,1,0,0,0,0,1,0,0,0,0,0,0,0,"Grocklar - On Aggro - Cast 49676 (Not found in DBCs!)"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,12000,15000,11,49675,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grocklar - In Combat - Cast 49675");

-- Seething Hate SAI
SET @ENTRY := 32429;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,52342,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seething Hate - On Aggro - Cast 52342");

-- Azure Manabeast SAI
SET @ENTRY := 31404;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,12000,20000,11,59105,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Manabeast - In Combat - Cast 59105");

-- Ancient Sentinel SAI
SET @ENTRY := 31797;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,8000,9000,13000,11,12612,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ancient Sentinel - In Combat - Cast 12612"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,15000,18000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ancient Sentinel - In Combat - Cast 5568");

-- Tempus Wyrm SAI
SET @ENTRY := 32180;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,9000,10000,17000,11,60076,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tempus Wyrm - In Combat - Cast 60076");

-- Infinite Eradicator SAI
SET @ENTRY := 32185;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,20000,28000,11,31458,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Eradicator - In Combat - Cast 31458"),
(@ENTRY,0,1,0,0,0,100,0,3000,7000,12000,16000,11,31475,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Eradicator - In Combat - Cast 31475"),
(@ENTRY,0,2,0,0,0,100,0,10000,13000,20000,25000,11,52657,1,0,0,0,0,5,0,0,0,0,0,0,0,"Infinite Eradicator - In Combat - Cast 52657");

-- Infinite Timebreaker SAI
SET @ENTRY := 32186;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,12000,14000,23000,11,60074,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Timebreaker - In Combat - Cast 60074"),
(@ENTRY,0,1,0,2,0,100,0,0,30,10000,14000,11,60075,1,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Timebreaker - Between 0-30% Health - Cast 60075");

-- Grove Walker SAI
SET @ENTRY := 31228;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,1000,600000,600000,11,35361,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grove Walker - In Combat - Cast 35361"),
(@ENTRY,0,1,0,14,0,100,0,7000,40,18000,30000,11,15981,1,0,0,0,0,7,0,0,0,0,0,0,0,"Grove Walker - On Friendly Unit At 7000 Health Within 40 Range - Cast 15981");

-- Ancient Watcher SAI
SET @ENTRY := 31229;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,10000,25000,35000,11,33844,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ancient Watcher - In Combat - Cast 33844"),
(@ENTRY,0,1,0,0,0,100,0,3000,8000,18000,24000,11,51944,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ancient Watcher - In Combat - Cast 51944");

-- Lost Shandaral Spirit SAI
SET @ENTRY := 31231;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,12000,20000,26000,11,15798,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lost Shandaral Spirit - In Combat - Cast 15798"),
(@ENTRY,0,1,0,14,0,100,0,7000,40,35000,45000,11,16561,1,0,0,0,0,7,0,0,0,0,0,0,0,"Lost Shandaral Spirit - On Friendly Unit At 7000 Health Within 40 Range - Cast 16561");

-- Sinewy Wolf SAI
SET @ENTRY := 31233;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,36589,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sinewy Wolf - On Aggro - Cast 36589"),
(@ENTRY,0,1,0,0,0,100,0,4000,8000,6000,9000,11,32919,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sinewy Wolf - In Combat - Cast 32919"),
(@ENTRY,0,2,0,0,0,100,0,12000,16000,19000,29000,11,59008,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sinewy Wolf - In Combat - Cast 59008");

-- Dappled Stag SAI
SET @ENTRY := 31236;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,7000,12000,11,59110,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dappled Stag - In Combat - Cast 59110");

-- Crystal Wyrm SAI
SET @ENTRY := 31393;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,10000,18000,26000,11,47425,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crystal Wyrm - In Combat - Cast 47425"),
(@ENTRY,0,1,0,0,0,100,0,3000,7000,20000,30000,11,59110,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crystal Wyrm - In Combat - Cast 59110");

-- Azure Manashaper SAI
SET @ENTRY := 31401;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,15000,25000,15000,25000,11,10833,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Manashaper - In Combat - Cast 10833"),
(@ENTRY,0,1,0,0,0,100,0,2000,6000,14000,20000,11,25603,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Manashaper - In Combat - Cast 25603");

-- Dispirited Ent SAI
SET @ENTRY := 31041;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,1000,600000,600000,11,35361,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dispirited Ent - In Combat - Cast 35361"),
(@ENTRY,0,1,0,14,0,100,0,7000,40,18000,30000,11,15981,1,0,0,0,0,7,0,0,0,0,0,0,0,"Dispirited Ent - On Friendly Unit At 7000 Health Within 40 Range - Cast 15981");

-- Mechanical Greeter RY7R SAI
SET @ENTRY := 31057;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,7,1,10,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mechanical Greeter RY7R - On LOS Out Of Combat - Say Line 0 (Dungeon Only)");

-- Texts for Mechanical Greeter RY7R
SET @ENTRY := 31057;
DELETE FROM creature_ai_texts WHERE entry IN (-883);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Hello. Master Fras Siabi is not in at this time. Please come back tomorrow to Fras Siabi's Premium Tobacco! Beep!",12,0,100,0,0,0,"Mechanical Greeter RY7R");

-- Shandaral Spirit Wolf SAI
SET @ENTRY := 31123;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,6000,8000,13000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shandaral Spirit Wolf - In Combat - Cast 3604");

-- Baelok SAI
SET @ENTRY := 31159;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,9000,13000,11,61094,0,0,0,0,0,2,0,0,0,0,0,0,0,"Baelok - In Combat - Cast 61094"),
(@ENTRY,0,1,0,0,0,100,0,15000,20000,18000,25000,11,61090,0,0,0,0,0,2,0,0,0,0,0,0,0,"Baelok - In Combat - Cast 61090"),
(@ENTRY,0,2,0,0,0,100,0,10000,13000,35000,45000,11,61086,1,0,0,0,0,1,0,0,0,0,0,0,0,"Baelok - In Combat - Cast 61086");

-- Rokir SAI
SET @ENTRY := 31160;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,60000,90000,11,61088,1,0,0,0,0,1,0,0,0,0,0,0,0,"Rokir - In Combat - Cast 61088"),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,19000,11,61109,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rokir - Between 0-5 Range - Cast 61109"),
(@ENTRY,0,2,0,0,0,100,0,8000,13000,16000,21000,11,61112,1,0,0,0,0,5,0,0,0,0,0,0,0,"Rokir - In Combat - Cast 61112");

-- Magistrate Barthilas SAI
SET @ENTRY := 30994;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,6,20000,20000,240000,240000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Barthilas - Out Of Combat - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,1,0,1,0,100,6,27000,27000,247000,247000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magistrate Barthilas - Out Of Combat - Say Line 1 (Dungeon Only)");

-- Texts for Magistrate Barthilas
SET @ENTRY := 30994;
DELETE FROM creature_ai_texts WHERE entry BETWEEN -882 AND -877;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"No remedy seems to work - the entire city has sickened...",12,0,100,0,0,0,"Magistrate Barthilas"),
(@ENTRY,0,1,"The soldiers are spreading panic with rumors of bad food. Neighbors are accusing one another of poison. The city will fall into bedlam!",12,0,100,0,0,0,"Magistrate Barthilas"),
(@ENTRY,0,2,"Everyone is falling ill - this is an epidemic!",12,0,100,0,0,0,"Magistrate Barthilas"),
(@ENTRY,1,0,"I pray the illness I'm feeling is due to stress ulcers...",12,0,100,0,0,0,"Magistrate Barthilas"),
(@ENTRY,1,1,"How can I possibly help the city in such a widespread crisis?",12,0,100,0,0,0,"Magistrate Barthilas"),
(@ENTRY,1,2,"I'm at a loss. What can one simple man do in the face of disaster?",12,0,100,0,0,0,"Magistrate Barthilas");

-- Baelok SAI
SET @ENTRY := 30953;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,9000,13000,11,61094,0,0,0,0,0,2,0,0,0,0,0,0,0,"Baelok - In Combat - Cast 61094"),
(@ENTRY,0,1,0,0,0,100,0,15000,20000,18000,25000,11,61090,0,0,0,0,0,2,0,0,0,0,0,0,0,"Baelok - In Combat - Cast 61090"),
(@ENTRY,0,2,0,0,0,100,0,10000,13000,35000,45000,11,61086,1,0,0,0,0,1,0,0,0,0,0,0,0,"Baelok - In Combat - Cast 61086"),
(@ENTRY,0,3,0,6,0,100,1,0,0,0,0,33,31159,0,0,0,0,0,7,0,0,0,0,0,0,0,"Baelok - On Death - Quest Credit");

-- Rokir SAI
SET @ENTRY := 30954;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,60000,90000,11,61088,1,0,0,0,0,1,0,0,0,0,0,0,0,"Rokir - In Combat - Cast 61088"),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,19000,11,61109,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rokir - Between 0-5 Range - Cast 61109"),
(@ENTRY,0,2,0,0,0,100,0,8000,13000,16000,21000,11,61112,1,0,0,0,0,5,0,0,0,0,0,0,0,"Rokir - In Combat - Cast 61112"),
(@ENTRY,0,3,0,6,0,100,1,0,0,0,0,33,31160,0,0,0,0,0,7,0,0,0,0,0,0,0,"Rokir - On Death - Quest Credit");

-- Shandaral Warrior Spirit SAI
SET @ENTRY := 30865;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,6000,9000,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shandaral Warrior Spirit - Between 0-5 Range - Cast 57846"),
(@ENTRY,0,1,0,13,0,100,1,9000,12000,0,0,11,38233,1,0,0,0,0,7,0,0,0,0,0,0,0,"Shandaral Warrior Spirit - On Target Casting - Cast 38233");

-- Unbound Ancient SAI
SET @ENTRY := 30861;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,5000,15000,20000,11,33844,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Ancient - In Combat - Cast 33844"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,9000,12000,11,51944,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Ancient - In Combat - Cast 51944");

-- Unbound Ent SAI
SET @ENTRY := 30862;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,35361,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Ent - On Aggro - Cast 35361"),
(@ENTRY,0,1,0,0,0,100,0,6000,16000,22000,30000,11,58624,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Ent - In Combat - Cast 58624");

-- Shandaral Druid Spirit SAI
SET @ENTRY := 30863;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,12000,20000,26000,11,15798,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shandaral Druid Spirit - In Combat - Cast 15798"),
(@ENTRY,0,1,0,14,0,100,0,7000,40,35000,45000,11,16561,1,0,0,0,0,7,0,0,0,0,0,0,0,"Shandaral Druid Spirit - On Friendly Unit At 7000 Health Within 40 Range - Cast 16561");

-- Ice Steppe Bull SAI
SET @ENTRY := 30445;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,55193,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ice Steppe Bull - On Aggro - Cast 55193"),
(@ENTRY,0,1,0,9,0,100,0,0,5,5000,7000,11,51944,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ice Steppe Bull - Between 0-5 Range - Cast 51944");

-- Romping Rhino SAI
SET @ENTRY := 30447;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9000,9000,13000,11,57468,0,0,0,0,0,1,0,0,0,0,0,0,0,"Romping Rhino - In Combat - Cast 57468");

-- Plains Mammoth SAI
SET @ENTRY := 30448;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,5000,8000,11,50410,0,0,0,0,0,2,0,0,0,0,0,0,0,"Plains Mammoth - Between 0-5 Range - Cast 50410");

-- Wailing Winds SAI
SET @ENTRY := 30450;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,8,30,12000,16000,11,57488,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wailing Winds - Between 8-30 Range - Cast 57488");

-- The North Wind SAI
SET @ENTRY := 30474;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,15000,23000,26000,11,61662,0,0,0,0,0,5,0,0,0,0,0,0,0,"The North Wind - In Combat - Cast 61662"),
(@ENTRY,0,1,0,0,0,100,0,6000,13000,15000,23000,11,56861,0,0,0,0,0,5,0,0,0,0,0,0,0,"The North Wind - In Combat - Cast 56861"),
(@ENTRY,0,2,0,9,0,100,0,0,5,8000,11000,11,61663,0,0,0,0,0,2,0,0,0,0,0,0,0,"The North Wind - Between 0-5 Range - Cast 61663");

-- Image of the North Wind SAI
SET @ENTRY := 30550;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,12000,16000,11,57322,0,0,0,0,0,2,0,0,0,0,0,0,0,"Image of the North Wind - In Combat - Cast 57322");

-- Seething Revenant SAI
SET @ENTRY := 30387;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,56620,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seething Revenant - Out Of Combat - Cast 56620");

-- Forgotten One SAI
SET @ENTRY := 30414;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,7000,11000,17000,20000,11,60833,0,0,0,0,0,5,0,0,0,0,0,0,0,"Forgotten One - In Combat - Cast 60833 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,4000,7000,17000,20000,11,60848,0,0,0,0,0,5,0,0,0,0,0,0,0,"Forgotten One - In Combat - Cast 60848 (Heroic Dungeon)"),
(@ENTRY,0,2,0,9,0,100,2,0,5,16000,19000,11,60845,1,0,0,0,0,1,0,0,0,0,0,0,0,"Forgotten One - Between 0-5 Range - Cast 60845 (Normal Dungeon)"),
(@ENTRY,0,3,0,9,0,100,4,0,5,16000,19000,11,60851,1,0,0,0,0,1,0,0,0,0,0,0,0,"Forgotten One - Between 0-5 Range - Cast 60851 (Heroic Dungeon)"),
(@ENTRY,0,4,0,0,0,100,6,9000,12000,18000,21000,11,34322,1,0,0,0,0,1,0,0,0,0,0,0,0,"Forgotten One - In Combat - Cast 34322 (Dungeon Only)");

-- Eisenfaust SAI
SET @ENTRY := 30341;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,8000,9000,14000,11,56490,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eisenfaust - In Combat - Cast 56490");

-- Duronn the Runewrought SAI
SET @ENTRY := 30353;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,7000,11000,17000,11,56490,0,0,0,0,0,2,0,0,0,0,0,0,0,"Duronn the Runewrought - In Combat - Cast 56490"),
(@ENTRY,0,1,0,2,0,100,0,0,10,20000,30000,11,61315,1,0,0,0,0,1,0,0,0,0,0,0,0,"Duronn the Runewrought - Between 0-10% Health - Cast 61315");

-- Savage Cave Beast SAI
SET @ENTRY := 30329;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,7000,9000,12000,11,30471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Savage Cave Beast - In Combat - Cast 30471 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,2,9000,12000,17000,20000,11,56867,1,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Cave Beast - In Combat - Cast 56867 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,4,9000,12000,17000,20000,11,59116,1,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Cave Beast - In Combat - Cast 59116 (Heroic Dungeon)"),
(@ENTRY,0,3,0,2,0,100,6,0,30,12000,15000,11,48193,1,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Cave Beast - Between 0-30% Health - Cast 48193 (Dungeon Only)");

-- Ahn'kahar Swarmer SAI
SET @ENTRY := 30338;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,1000,1000,35000,45000,11,56354,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ahn'kahar Swarmer - In Combat - Cast 56354 (Dungeon Only)");

-- Plundering Geist SAI
SET @ENTRY := 30287;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,2,0,50,9000,12000,11,56715,0,0,0,0,0,2,0,0,0,0,0,0,0,"Plundering Geist - Between 0-50% Health - Cast 56715 (Normal Dungeon)"),
(@ENTRY,0,1,0,2,0,100,4,0,75,6000,8000,11,59114,0,0,0,0,0,2,0,0,0,0,0,0,0,"Plundering Geist - Between 0-75% Health - Cast 59114 (Heroic Dungeon)");

-- Iron Colossus SAI
SET @ENTRY := 30300;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,16000,20000,28000,11,61673,0,0,0,0,0,2,0,0,0,0,0,0,0,"Iron Colossus - In Combat - Cast 61673");

-- Deep Crawler SAI
SET @ENTRY := 30279;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,7000,9000,12000,11,56580,0,0,0,0,0,5,0,0,0,0,0,0,0,"Deep Crawler - In Combat - Cast 56580 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,4000,7000,9000,12000,11,59108,0,0,0,0,0,5,0,0,0,0,0,0,0,"Deep Crawler - In Combat - Cast 59108 (Heroic Dungeon)"),
(@ENTRY,0,2,0,12,0,100,2,0,20,14000,17000,11,56581,33,0,0,0,0,7,0,0,0,0,0,0,0,"Deep Crawler - On Target Between 0-20% Health - Cast 56581 (Normal Dungeon)"),
(@ENTRY,0,3,0,12,0,100,4,0,20,14000,17000,11,59109,33,0,0,0,0,7,0,0,0,0,0,0,0,"Deep Crawler - On Target Between 0-20% Health - Cast 59109 (Heroic Dungeon)");

-- Plague Walker SAI
SET @ENTRY := 30283;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,2,0,0,0,0,11,56709,1,0,0,0,0,1,0,0,0,0,0,0,0,"Plague Walker - On Respawn - Cast 56709 (Normal Dungeon)"),
(@ENTRY,0,1,0,11,0,100,4,0,0,0,0,11,61459,1,0,0,0,0,1,0,0,0,0,0,0,0,"Plague Walker - On Respawn - Cast 61459 (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,6,7000,11000,120000,130000,11,56707,0,0,0,0,0,2,0,0,0,0,0,0,0,"Plague Walker - In Combat - Cast 56707 (Dungeon Only)");

-- Bonegrinder SAI
SET @ENTRY := 30284;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,7000,18000,22000,11,56736,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonegrinder - In Combat - Cast 56736 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,4000,7000,18000,22000,11,59107,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonegrinder - In Combat - Cast 59107 (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,6,11000,14000,22000,25000,11,56737,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bonegrinder - In Combat - Cast 56737 (Dungeon Only)"),
(@ENTRY,0,3,0,0,0,100,6,20000,23000,24000,27000,11,19134,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonegrinder - In Combat - Cast 19134 (Dungeon Only)"),
(@ENTRY,0,4,0,2,0,100,6,0,30,120000,130000,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonegrinder - Between 0-30% Health - Cast 8599 (Dungeon Only)");

-- Skymaster Baeric SAI
SET @ENTRY := 30269;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,35917,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skymaster Baeric - On Aggro - Cast 35917");

-- Ahn'kahar Web Winder SAI
SET @ENTRY := 30276;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,40,14000,19000,11,56640,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ahn'kahar Web Winder - Between 0-40 Range - Cast 56640 (Normal Dungeon)"),
(@ENTRY,0,1,0,9,0,100,4,0,40,14000,19000,11,59106,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ahn'kahar Web Winder - Between 0-40 Range - Cast 59106 (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,6,5000,9000,16000,21000,11,56632,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ahn'kahar Web Winder - In Combat - Cast 56632 (Dungeon Only)");

-- Ahn'kahar Slasher SAI
SET @ENTRY := 30277;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,7000,14000,17000,11,42746,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ahn'kahar Slasher - In Combat - Cast 42746 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,9000,12000,15000,18000,11,56643,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ahn'kahar Slasher - In Combat - Cast 56643 (Dungeon Only)"),
(@ENTRY,0,2,0,2,0,100,2,0,30,8000,10000,11,56646,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ahn'kahar Slasher - Between 0-30% Health - Cast 56646 (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,4,0,30,8000,10000,11,32714,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ahn'kahar Slasher - Between 0-30% Health - Cast 32714 (Heroic Dungeon)");

-- Alanura Firecloud SAI
SET @ENTRY := 30239;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,35917,0,0,0,0,0,1,0,0,0,0,0,0,0,"Alanura Firecloud - On Aggro - Cast 35917");

-- Marisalira SAI
SET @ENTRY := 30254;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,35917,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marisalira - On Aggro - Cast 35917");

-- Yorg Stormheart SAI
SET @ENTRY := 30182;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,4000,30000,38000,11,19135,1,0,0,0,0,1,0,0,0,0,0,0,0,"Yorg Stormheart - In Combat - Cast 19135"),
(@ENTRY,0,1,0,0,0,100,0,6000,12000,15000,19000,11,15548,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yorg Stormheart - In Combat - Cast 15548");

-- Scion of Storm SAI
SET @ENTRY := 30184;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,13000,9000,16000,11,57480,0,0,0,0,0,5,0,0,0,0,0,0,0,"Scion of Storm - In Combat - Cast 57480"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,50215,7,0,0,0,0,7,0,0,0,0,0,0,0,"Scion of Storm - On Death - Cast 50215");

-- Gimorak SAI
SET @ENTRY := 30167;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,5,35,25000,28000,11,54487,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gimorak - Between 5-35 Range - Cast 54487"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12000,16000,11,50046,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gimorak - Between 0-5 Range - Cast 50046"),
(@ENTRY,0,2,0,0,0,100,0,9000,12000,17000,20000,11,32019,0,0,0,0,0,5,0,0,0,0,0,0,0,"Gimorak - In Combat - Cast 32019");

-- Twilight Apostle SAI
SET @ENTRY := 30179;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,2,0,0,0,0,11,12550,1,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Apostle - On Respawn - Cast 12550 (Normal Dungeon)"),
(@ENTRY,0,1,0,11,0,100,4,0,0,0,0,11,61570,1,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Apostle - On Respawn - Cast 61570 (Heroic Dungeon)"),
(@ENTRY,0,2,0,14,0,100,6,10000,40,14000,17000,11,11986,1,0,0,0,0,7,0,0,0,0,0,0,0,"Twilight Apostle - On Friendly Unit At 10000 Health Within 40 Range - Cast 11986 (Dungeon Only)"),
(@ENTRY,0,3,0,2,0,100,6,0,30,12000,15000,11,28902,1,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Apostle - Between 0-30% Health - Cast 28902 (Dungeon Only)"),
(@ENTRY,0,4,0,2,0,100,7,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Twilight Apostle - Between 0-15% Health - Flee For Assist (Dungeon Only)");

-- Bruor Ironbane SAI
SET @ENTRY := 30152;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,30,120000,130000,11,56330,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bruor Ironbane - Between 0-30% Health - Cast 56330");

-- Brittle Revenant SAI
SET @ENTRY := 30160;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,6000,12000,15000,11,50731,0,0,0,0,0,2,0,0,0,0,0,0,0,"Brittle Revenant - In Combat - Cast 50731"),
(@ENTRY,0,1,0,13,0,100,0,16000,20000,0,0,11,11972,1,0,0,0,0,7,0,0,0,0,0,0,0,"Brittle Revenant - On Target Casting - Cast 11972");

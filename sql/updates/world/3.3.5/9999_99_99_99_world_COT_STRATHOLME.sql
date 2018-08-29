-- Caverns of Time: Stratholme rework
SET @DAY = 86400;
SET @CGUID = 700300; -- creature GUIDs (4 creature);
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+00 AND @CGUID+03;

-- Move additional Chromie spawns to DB
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`movementtype`) VALUES
(@CGUID+00, 27915, 595, 3, 1, 1813.298, 1283.578, 142.3258, 3.878161, @DAY, 0, 0);

-- Chromie AI
UPDATE `creature_template` SET `ScriptName`="npc_chromie_start" WHERE `entry`=26527;
UPDATE `creature_template` SET `ScriptName`="npc_chromie_middle" WHERE `entry`=27915;
-- Chromie whispers
DELETE FROM `creature_text` WHERE `creatureid`=27915 AND `groupid`=1;
INSERT INTO `creature_text` (`creatureid`,`groupid`,`id`,`text`,`type`,`probability`,`BroadcastTextId`,`TextRange`,`emote`,`comment`) VALUES
(27915, 1, 0, "Come over here time traveller, we need to talk!", 15, 100, 29167, 0, 70, "Chromie - WHISPER_COME_TALK"),
(27915, 1, 1, "Quick, over here!", 15, 100, 29169, 0, 70, "Chromie - WHISPER_COME_TALK"),
(27915, 1, 2, "We meet again, time traveller!", 15, 100, 29168, 0, 70, "Chromie - WHISPER_COME_TALK");

-- Corruptor of Time
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry`=60422;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
(13, 1, 60422, 31, 0, 3, 32281, "Corruption of Time - Implicitly target Guardian of Time");

-- Starting inn RP fluff
DELETE FROM `areatrigger_scripts` WHERE `entry`=5291;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES (5291,"at_stratholme_inn_stairs_cot");
UPDATE `creature` SET `movementtype`=0,`spawndist`=0 WHERE `id`=30571;
UPDATE `creature_addon` SET `bytes1`=0 WHERE `guid` IN (SELECT guid FROM `creature` WHERE `id`=30571);
UPDATE `creature_template` SET `ScriptName`="",`AIName`="SmartAI" WHERE `entry`=30571;
UPDATE `creature_template` SET `ScriptName`="npc_hearthsinger_forresten_cot",`AIName`="" WHERE `entry`=30551;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30571 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`action_type`,`action_param1`,`action_param2`,`target_type`,`target_param1`,`target_param2`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30571, 0, 0, 1, 72, 100, 1, 100,  0, 17,  0, 0,  1,     0,   0,        0,        0,        0,        0, "Michael Belfast - On Action 100 - Set Emote State None (No Repeat)"),
(30571, 0, 1, 2, 61, 100, 1,   0,  0, 59,  0, 0,  0,     0,   0,        0,        0,        0,        0, "Michael Belfast - On Action 100 - Set Run (false) (No Repeat)"),
(30571, 0, 2, 0, 61, 100, 1,   0,  0, 69, 42, 0,  8,     0,   0, 1554.371, 587.4865, 99.77525, 1.107272, "Michael Belfast - On Action 100 - Move Position (ID 42) (No Repeat)"),
(30571, 0, 3, 0, 34, 100, 1,   8, 42, 45,  1, 1, 11, 30551, 100,        0,        0,        0,        0, "Michael Belfast - On Movement Inform (ID 42) - Set Data 1-1 on Hearthsinger Forresten (within 100yd) (No Repeat)");
DELETE FROM `creature_text` WHERE `creatureid` IN (30551,30552,30553,30561,30571,31017);
INSERT INTO `creature_text` (`creatureid`,`groupid`,`id`,`text`,`type`,`probability`,`BroadcastTextId`,`emote`,`comment`) VALUES
(30571, 0, 0, "What were you doing in my cellar? There's a food scare going on, and the last thing I need is strangers rummaging around in my goods! Shoo!", 12, 100, 31323, 5, "Michael Belfast - SAY_CELLAR"),
(30571, 0, 1, "Hey! Stop rooting around in my cellar! Clear out!", 12, 100, 31322, 5, "Michael Belfast - SAY_CELLAR"),
(30551, 0, 0, "This whole situation seems a bit paranoid, don't you think?", 12, 100, 31324, 1, "Hearthsinger Forresten - LINE_FORREST_1"),
(30553, 0, 0, "Orders are orders. If the Prince says jump...", 12, 100, 31325, 1, "Footman James - LINE_JAMES_1"),
(30552, 0, 0, "It's a strange order, you can't deny. Suspicious food? Under that definition, you should arrest Belfast!", 12, 100, 31326, 1, "Fras Siabi - LINE_FRAS_1"),
(30571, 1, 0, "I HEARD THAT! No more ale for you! Not a drop!", 12, 100, 31327, 22, "Michael Belfast - LINE_BELFAST_1"),
(31017, 0, 0, "Enough, Michael. Business is hurting enough with this scare as it is. We can use every copper.", 12, 100, 32560, 1, "Mal Corricks - LINE_MAL_1"),
(30561, 0, 0, "The soldiers are doing important work. The safety of the people is more important, Mal, if you're interested in your customers living to spend another day.", 12, 100, 32571, 1, "Gryan Stoutmantle - LINE_GRYAN_1"),
(31017, 1, 0, "%s grudgingly nods.", 16, 100, 32569, 273, "Mal Corricks - LINE_MAL_2"),
(31017, 2, 0, "I can't argue with that.", 12, 100, 32570, 1, "Mal Corricks - LINE_MAL_3"),
(30553, 1, 0, "Don't worry too much. By the time I went off duty, we hadn't found a scrap of befouled grain here.", 12, 100, 32572, 1, "Footman James - LINE_JAMES_2"),
(30551, 1, 0, "Thank the Light for that.", 12, 100, 32573, 1, "Hearthsinger Forresten - LINE_FORREST_2"),
(30552, 1, 0, "%s nods.", 16, 100, 32574, 273, "Fras Siabi - LINE_FRAS_2");

-- Fix a random typo in AI name for Grain Crate Helper
UPDATE `creature_template` SET `ScriptName`="npc_crate_helper_cot" WHERE `entry`=27827;

-- Arcane Disruption: Require active grain crate within 8yd, and implicitly target the helper for that crate
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (13,17) AND `SourceEntry`=49590;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ErrorType`, `Comment`) VALUES
(13, 1, 49590, 31, 0, 3,  27827,  0, "Arcane Disruption - Implicitly target Grain Crate Helper"),
(17, 0, 49590, 30, 0, 190094, 8, 11, "Arcane Disruption - Must be within 8yd of Suspicious Grain Crate"),
(17, 0, 49590, 29, 0,  27827, 8, 11, "Arcane Disruption - Must be within 8yd of Grain Crate Helper");

-- Make Suspicious Grain Crate and Grain Crate Helper never respawn
UPDATE `creature` SET `spawntimesecs`=@DAY WHERE `id`=27827;
UPDATE `gameobject` SET `spawntimesecs`=@DAY WHERE `id`=190094;

-- Grain Crate reaction fluff
UPDATE `creature` SET `movementtype`=0,`spawndist`=0 WHERE `id` IN (27884,27885,27891,27892,27907);
-- Event #1:
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_jena_anderson" WHERE `entry`=27885;
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_martha_goslin" WHERE `entry`=27884;
UPDATE `creature` SET `position_x`=1635.827,`position_y`=723.0861,`position_z`=113.6452,`orientation`=3.089233 WHERE `id`=27884;
DELETE FROM `creature_text` WHERE `creatureid` IN (27884,27885);
INSERT INTO `creature_text` (`creatureid`,`groupid`,`text`,`type`,`probability`,`emote`,`BroadcastTextId`,`comment`) VALUES
(27884,0,"Oh hello, Jena. Of course you can borrow some grain. Help yourself.",12,100,1,27232,"LINE_MARTHA1"),
(27884,1,"Oh, my.",12,100,1,27235,"LINE_MARTHA2"),
(27885,0,"Let's see, we had chicken last night.",12,100,0,27219,"LINE_JENA1"),
(27885,1,"I've got plenty of cured bacon, but he had some for breakfast.",12,100,0,27220,"LINE_JENA2"),
(27885,2,"I need to make something healthy for him, he's still not recovered from that illness from last week.",12,100,0,27221,"LINE_JENA3"),
(27885,3,"Strawberries! Oh wait, they're not in season.",12,100,0,27222,"LINE_JENA4"),
(27885,4,"Ah, I'll make him some fresh bread! I need to get some flour from Martha!",12,100,0,27223,"LINE_JENA5"),
(27885,5,"Martha, I'm out of flour for bread. You wouldn't happen to have any grain from that recent shipment, would you?",12,100,6,27224,"LINE_JENA6"),
(27885,6,"Thanks, Martha! I owe you one.",12,100,1,27229,"LINE_JENA7"),
(27885,7,"Oh, dear.",12,100,0,27230,"LINE_JENA8"),
(27885,8,"Martha, something's wrong with this grain! Some of the Prince's soldiers were looking for this. I'm going to go look for one.",12,100,5,27231,"LINE_JENA9");
-- Event #2:
UPDATE `creature` SET `position_x`=1670.256, `position_y`=872.8734, `position_z`=120.0351, `orientation`=0.418879 WHERE `id`=27907;
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_bartleby_battson" WHERE `entry`=27907;
DELETE FROM `creature_text` WHERE `creatureid`=27907;
INSERT INTO `creature_text` (`creatureid`,`groupid`,`id`,`text`,`type`,`probability`,`emote`,`BroadcastTextId`,`comment`) VALUES
(27907,0,0,"I'm going to lose my on time bonus because of this!",12,10,0,27255,"LINE_BARTLEBY_IDLE 1"),
(27907,0,1,"I wasn't even supposed to be here today!",12,10,0,27256,"LINE_BARTLEBY_IDLE 2"),
(27907,1,0,"Well, guess I should load everything back into the cart.",12,100,0,27257,"LINE_BARTLEBY1"),
(27907,2,0,"Oh, come on! My cart broke, my horse lost a shoe, and now the cargo goes bad!",12,100,5,27258,"LINE_BARTLEBY2"),
(27907,3,0,"I guess I'll go find the authorities. If I'm lucky they'll tell me it's the plague and that we're all going to die.",12,100,0,27259,"LINE_BARTLEBY3");
-- Event #3:
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_malcolm_moore" WHERE `entry`=27891;
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_stratholme_rp_dummy" WHERE `entry`=27892;
DELETE FROM `creature_text` WHERE `creatureid` IN (27891,27892);
INSERT INTO `creature_text` (`creatureid`,`groupid`,`text`,`type`,`probability`,`emote`,`BroadcastTextId`,`comment`) VALUES
(27891,0,"Looks like a storm's coming in, Scruffy...",12,100,0,27236,"LINE_MALCOLM1"),
(27892,0,"%s begins to growl...",16,100,0,27237,"LINE_SCRUFFY1"),
(27891,1,"What's wrong, pal?",12,100,1,27238,"LINE_MALCOLM2"),
(27891,2,"What did you find, boy?",12,100,16,27240,"LINE_MALCOLM3"),
(27891,3,"This is no good, Scruffy. Stay here and guard the house, I need to go find a soldier.",12,100,0,27241,"LINE_MALCOLM4");
-- Event #4:
UPDATE `creature` SET `position_x`=1563.337, `position_y`=671.6413, `position_z`=102.1412, `orientation`=4.2586040 WHERE `id`=27876;
UPDATE `creature` SET `position_x`=1561.571, `position_y`=670.3199, `position_z`=102.1444, `orientation`=0.5759587 WHERE `id`=27877;
UPDATE `creature_template` SET `AIName`="", `ScriptName`="npc_sergeant_morigan" WHERE `entry`=27877;
DELETE FROM `creature_text` WHERE `creatureid` IN (27876,27877);
INSERT INTO `creature_text` (`creatureid`,`groupid`,`id`,`text`,`type`,`probability`,`emote`,`BroadcastTextId`,`comment`) VALUES
(27876,0,0,"No, Sergeant.",12,100,274,27198,"LINE_PERELLI_NO #1"),
(27876,0,1,"No, sir.",12,100,274,27199,"LINE_PERELLI_NO #2"),
(27876,0,2,"Nope.",12,100,274,27200,"LINE_PERELLI_NO #3"),
(27876,1,0,"Yes, sir.",12,100,1,27201,"LINE_PERELLI_YES #1"),
(27876,1,1,"Yes, Sergeant Morigan.",12,100,1,27202,"LINE_PERELLI_YES #2"),
(27876,1,2,"Absolutely.",12,100,1,27203,"LINE_PERELLI_YES #3"),
(27876,2,0,"What are you talking about, Sergeant!",12,100,5,27208,"LINE_PERELLI1"),
(27876,3,0,"You have to believe me, I'm innocent!",12,100,20,27213,"LINE_PERELLI2"),
(27877,0,0,"Mr. Perelli, have you seen any suspicious activity by men wearing dark robes in the last few weeks?",12,100,6,27190,"LINE_SERGEANT_ASK_NO #1"),
(27877,0,1,"Mr. Perelli, have you seen any signs of the undead? Any information you can provide would be appreciated by Prince Arthas.",12,100,1,27191,"LINE_SERGEANT_ASK_NO #2"),
(27877,0,2,"Mr. Perelli, I know you travel around quite a bit hawking your goods. Surely you've heard rumors or information about the Scourge?",12,100,1,27192,"LINE_SERGEANT_ASK_NO #3"),
(27877,0,3,"Do you plan on leaving the area soon if we have further questions?",12,100,1,27193,"LINE_SERGEANT_ASK_NO #4"),
(27877,1,0,"Mr. Perelli, have these goods been under your supervision at all times?",12,100,6,27194,"LINE_SERGEANT_ASK_YES #1"),
(27877,1,1,"You wouldn't happen to have any canned turtle soup from Hillsbrad, would you?",12,100,1,27195,"LINE_SERGEANT_ASK_YES #2"),
(27877,1,2,"Mr. Perelli, if you happen across any signs of Scourge activity or shady dealings in your travels, let the nearest Lordaeron soldier know.",12,100,1,27197,"LINE_SERGEANT_ASK_YES #3"),
(27877,2,0,"You don't mind me checking out your merchandise for signs of tampering, do you?",12,100,1,27205,"LINE_SERGEANT_START"),
(27877,3,0,"Wait, what is this? You've been holding out on me, Perelli!",12,100,0,27206,"LINE_SERGEANT1"),
(27877,4,0,"I'm confiscating this suspicious grain, Perelli. We were looking for signs of tampered food, and it would be in your best interest to stay put while Prince Arthas checks this out.",12,100,1,27210,"LINE_SERGEANT2"),
(27877,5,0,"We'll see about that, Perelli. We'll see about that.",12,100,25,27216,"LINE_SERGEANT3");
-- Event #5:
UPDATE `creature` SET `position_x`=1588.942, `position_y`=597.9799, `position_z`=99.37262, `orientation`=2.80998 WHERE `id`=27903;
UPDATE `creature_template` SET `AIName`="", `ScriptName`="npc_roger_owens" WHERE `entry`=27903;
DELETE FROM `creature_text` WHERE `creatureid`=27903;
INSERT INTO `creature_text` (`creatureid`,`groupid`,`text`,`type`,`probability`,`emote`,`BroadcastTextId`,`comment`) VALUES
(27903,0,"Ok, enough work for now. Time for refreshments and a little conversation in the inn.",12,100,1,27247,"LINE_ROGER1"),
(27903,1,"Wait, what's that smell?",12,100,1,27248,"LINE_ROGER2"),
(27903,2,"Can't be me, I took a bath 3 days ago!",12,100,5,27249,"LINE_ROGER3"),
(27903,3,"Oh, close call. It's just the grain here.",12,100,5,27250,"LINE_ROGER4"),
(27903,4,"Wait a second. Grain isn't supposed to smell like THAT! I better go find a guard.",12,100,0,27252,"LINE_ROGER5");

-- Arthas AI
UPDATE `creature_template` SET `ScriptName`="npc_arthas_stratholme",`AIName`="" WHERE `entry`=26499;
UPDATE `creature_template` SET `unit_flags`=0x8000, `unit_flags2`=0x800 WHERE `entry` IN (26499,31210);
DELETE FROM `creature` WHERE `id`=26499;

-- Missing Arthas lines
DELETE FROM `creature_text` WHERE `creatureid`=26499 AND `groupid`>38;
INSERT INTO `creature_text` (`creatureid`,`groupid`,`id`,`text`,`type`,`probability`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(26499,39,0,"I can't afford to spare you.",12,100,31355,0,"Arthas SAY_AGGRO_ZOMBIE"),
(26499,40,0,"All officers should check in with me when their squads are ready. We'll enter Stratholme on my order.",12,100,27517,3,"Arthas RP1_LINE_ARTHAS11");

-- Dummy spell scripts
DELETE FROM `spell_script_names` WHERE `spell_id`=50773;
INSERT INTO `spell_script_names` (`spell_id`,`scriptname`) VALUES (50773,"spell_stratholme_crusader_strike");

-- Arthas/Uther RP data
UPDATE `creature_template` SET `ScriptName`="npc_stratholme_rp_dummy",`AIName`="" WHERE `entry` IN (26528,26497);
UPDATE `creature_text` SET `TextRange`=3 WHERE `creatureid` IN (26499,26528,26497,26529,26530,26532,26533,32273);
UPDATE `creature_text` SET `emote`=396 WHERE
	(`creatureid` = 26499 AND `groupid` IN (0,3,5)) OR
	(`creatureid` = 26528 AND `groupid`=3) OR
	(`creatureid` = 26497 AND `groupid` IN (0,1));
UPDATE `creature_text` SET `emote`=1 WHERE `creatureid`=26499 AND `groupid`=7;
UPDATE `creature_text` SET `emote`=5 WHERE
	(`creatureid` = 26499 AND `groupid` IN (2,4)) OR
	(`creatureid` = 26528 AND `groupid` IN (1,4));
UPDATE `creature_text` SET `emote`=6 WHERE `creatureid`=26528 AND `groupid`=2;
UPDATE `creature_text` SET `emote`=397 WHERE
	(`creatureid` = 26528 AND `groupid` IN (0,5));

-- Arthas/Mal'ganis RP data
DELETE FROM `creature_text` WHERE `creatureid` IN (28167,28169);
INSERT INTO `creature_text` (`creatureid`,`groupid`,`text`,`type`,`probability`,`BroadcastTextId`,`TextRange`,`emote`,`comment`) VALUES
(28167, 0, "Prince Arthas, may the light be praised! Many people in the town have begun to fall seriously ill, can you help us?", 12, 100, 27547, 0, 1, "RP2_LINE_CITIZEN1"),
(28167, 1, "What? This can't be!", 12, 100, 27549, 0, 274, "RP2_LINE_CITIZEN2"),
(28169, 0, "Oh, no...", 12, 100, 27552, 0, 0, "RP2_LINE_RESIDENT1");
UPDATE `creature_text` SET `emote`=1 WHERE
	(`creatureid` = 26499 AND `groupid` IN (12,14)) OR
	(`creatureid` = 26533 AND `groupid`=0);
UPDATE `creature_text` SET `emote`=397 WHERE
	(`creatureid` = 26499 AND `groupid`=13);
	
-- Town Hall/Gauntlet RP data
UPDATE `creature_text` SET `emote`=1 WHERE
	(`creatureid`=26499 AND `groupid` IN (16,19,22,38)) OR
	(`creatureid`=28340 AND `groupid`=1);
UPDATE `creature_text` SET `emote`=5 WHERE
	(`creatureid`=26499 AND `groupid`=36);
UPDATE `creature_text` SET `emote`=396 WHERE
	(`creatureid`=26499 AND `groupid` IN (21,24,25,26,27,31,32,33,34));
UPDATE `creature_text` SET `emote`=432 WHERE
	(`creatureid`=26499 AND `groupid` IN (29));
	
-- spawn group data
DELETE FROM `spawn_group` WHERE `groupId` BETWEEN 52 and 56;
-- middle chromie
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES (52, 0, 700300);
-- crate helpers
INSERT INTO `spawn_group` SELECT 53 as `groupId`, 0 as `spawnType`, `guid` as `spawnId` FROM `creature` WHERE `id`=27827;
-- Blanket apply a spawn group to all "live stratholme" mobs that prevents them respawning after the purge begins
UPDATE `creature_template` SET `ScriptName`="",`AIName`="", `flags_extra`=(`flags_extra`|2) WHERE `entry` IN (28167,31126,31019,28169,31127,31023,31020,31018,31028);
UPDATE `creature_template` SET `ScriptName`="",`AIName`="SmartAI" WHERE `entry` IN (31057,30570,31027,31021,30994);
INSERT INTO `spawn_group` SELECT 56 as `groupId`, 0 as `spawnType`, `guid` as `spawnId` FROM `creature` WHERE `id` IN (28167,28169,30570,30994,31018,31019,31020,31021,31023,31027,31028,31057,31126,31127);
-- Do the same for undead stratholme mobs
UPDATE `creature_template` SET `ScriptName`="",`AIName`="SmartAI" WHERE `entry` IN (28249,27729,28200,27734,27731,28199,27736,28201);
INSERT INTO `spawn_group` SELECT 55 as `groupId`, 0 as `spawnType`, `guid` as `spawnId` FROM `creature` WHERE `id` IN (27729,27731,27734,27736,27737,28199,28200,28201,28249);
-- Gauntlet trash gets its own spawn group...
UPDATE `spawn_group` sg LEFT JOIN `creature` c on sg.`spawnId`=c.`guid` SET sg.`groupId`=54 WHERE (sg.`groupId`=55) AND (c.`position_x` BETWEEN 2028.0 AND 2372.0) AND (c.`position_y` BETWEEN 1115.0 AND 1355.0);

-- City fluff
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (30570,31027,31021) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`event_type`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`action_type`,`target_type`,`comment`) VALUES
(30570,0,0,10,100,7,1,10,1,1,"Emery Neill - Within 1-10 Range Out of Combat LoS - Say Line 0"),
(31027,0,0,10,100,7,1,10,1,1,"Leeka Turner - Within 1-10 Range Out of Combat LoS - Say Line 0"),
(31021,0,0,10,100,7,1,10,1,1,"Sophie Aaren - Within 1-10 Range Out of Combat LoS - Say Line 0");

DELETE FROM `creature_text` WHERE `creatureid` IN (30570,31027,31021);
INSERT INTO `creature_text` (`creatureid`,`groupid`,`id`,`text`,`type`,`probability`,`BroadcastTextId`,`emote`,`comment`) VALUES
(30570,0,0,"The Stone Crow's closed today, sorry. There are too many health concerns, and I'm not about to have Ed under fire for supposedly making people sick.",12,100,31724,1,"Emery Neill TALK_FLUFF 1"),
(30570,0,1,"I hate to disappoint people, but the Stone Crow's closed. If the kids from the orphanage were evacuated, I don't see why we should be open, either.",12,100,31729,1,"Emery Neill TALK_FLUFF 2"),
(31027,0,0,"Look, I'll sell you shields today, but no maces. The last thing I want is for some innocent to get brained by one of my weapons.",12,100,31721,1,"Leeka Turner TALK_FLUFF 1"),
(31027,0,1,"I don't know how much longer I'll be open today with all the commotion outside. If you need something repaired, I'll take a quick look.",12,100,31722,1,"Leeka Turner TALK_FLUFF 2"),
(31027,0,2,"I hope you're not coming in here fixing for a fight. There are too many angry people on the streets today.",12,100,31720,1,"Leeka Turner TALK_FLUFF 3"),
(31021,0,0,"What's the commotion outside?",12,100,31730,1,"Sophie Aaren TALK_FLUFF 1"),
(31021,0,1,"Is something going on? I hear angry voices.",12,100,31731,1,"Sophie Aaren TALK_FLUFF 2"),
(31021,0,2,"Everything's been so strange lately...",12,100,31732,1,"Sophie Aaren TALK_FLUFF 3");

-- SmartAI fixes for wave creatures
UPDATE `smart_scripts` SET `event_param3`=3100, `event_param4`=3400 WHERE `entryorguid`=28200 AND `source_type`=0 AND `id` IN (0,1);

-- Lordaeron Crier yells
DELETE FROM `creature_text` WHERE `creatureid` = 27913;
INSERT INTO `creature_text` (`creatureid`,`groupid`,`text`,`type`,`probability`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(27913, 0, "All soldiers of Lordaeron should immediately report to the entrance of Stratholme, and await further orders from Prince Arthas.", 14, 100, 27263, 3, "Lordaeron Crier CALL_TO_GATES"),
(27913, 1, "Scourge forces have been spotted near the King's Square fountain!", 14, 100, 27642, 3, "Lordaeron Crier KINGS_SQUARE"),
(27913, 2, "Scourge forces have been spotted near the Market Row Gate!", 14, 100, 27643, 3, "Lordaeron Crier MARKET_ROW"),
(27913, 3, "Scourge forces have been spotted near the Festival Lane Gate!", 14, 100, 27644, 3, "Lordaeron Crier FESTIVAL_LANE"),
(27913, 4, "Scourge forces have been spotted near the Elder's Square Gate!", 14, 100, 27645, 3, "Lordaeron Crier ELDERS_SQUARE"),
(27913, 5, "Scourge forces have been spotted near the Town Hall!", 14, 100, 27646, 3, "Lordaeron Crier TOWN_HALL");

-- Clean up some incorrect spawns in wave area
DELETE FROM `creature` WHERE `guid` BETWEEN 143949 AND 143952;

-- Get rid of the colossal mess that is Risen Zombie SmartAI
UPDATE `creature_template` SET `ScriptName`="npc_stratholme_fluff_undead",`AIName`="" WHERE `entry` = 27737;
DELETE FROM `smart_scripts` WHERE -`entryorguid` IN (SELECT `guid` FROM `creature` WHERE `id`=27737 AND `map`=595);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND -`SourceEntry` IN (SELECT `guid` FROM `creature` WHERE `id`=27737 AND `map`=595);

-- Town Hall infinite spawns
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`movementtype`) VALUES
(@CGUID+01, 28340, 595, 3, 1, 2398.715, 1207.334, 134.1223, 5.270895, @DAY, 0, 0),
(@CGUID+02, 28340, 595, 3, 1, 2401.265, 1202.789, 134.1039, 1.466077, @DAY, 0, 0),
(@CGUID+03, 28341, 595, 3, 1, 2402.654, 1205.786, 134.1223, 2.897247, @DAY, 0, 0);
UPDATE `creature_template` SET `unit_flags`=(`unit_flags`|0x100|0x200) WHERE `entry` IN (27742,27743,27744,31202,31203,31206,26532,31215,26533);

-- Town Hall RP event
DELETE FROM `creature_text` WHERE `creatureid`=28340;
INSERT INTO `creature_text` (`creatureid`,`groupid`,`text`,`type`,`probability`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(28340, 0, "Ah, you've finally arrived Prince Arthas. You're here just in the nick of time.", 12, 100, 27811, 3, "Stratholme Citizen (Disguised Infinite) RP3_LINE_CITIZEN1"),
(28340, 1, "There's no need for you to understand, Arthas. All you need to do is die.", 12, 100, 27815, 3, "Stratholme Citizen (Disguised Infinite) RP3_LINE_CITIZEN2");

-- Difficulty data for trash mobs
DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (52660,52657,52635,52634);
INSERT INTO `spelldifficulty_dbc` (`id`,`spellid0`,`spellid1`) VALUES
(52660,52660,58817),
(52657,52657,58816),
(52635,52635,58820),
(52634,52634,58813);

-- SAI fixes for Town Hall trash
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (28340,28341) AND `source_type`=0 AND `event_flags`=4;
UPDATE `smart_scripts` SET `id`=CEIL(`id`/2)+1 WHERE `entryorguid`=28340 AND `source_type`=0 AND `event_flags`=2;
UPDATE `smart_scripts` SET `id`=CEIL(`id`/2) WHERE `entryorguid`=28341 AND `source_type`=0 AND `event_flags`=2;
UPDATE `smart_scripts` SET `event_flags`=`event_flags`|4 WHERE `entryorguid` IN (28340,28341) AND `source_type`=0;
UPDATE `smart_scripts` SET `event_param3`=500, `event_param4`=750 WHERE `entryorguid`=28340 AND `source_type`=0 AND `id`=3;
DELETE FROM `conditions` WHERE `sourcetypeorreferenceid`=22 AND `sourceentry`=28340 AND `sourceid`=0;
INSERT INTO `conditions` (`sourcetypeorreferenceid`,`sourcegroup`,`sourceentry`,`sourceid`,`conditiontypeorreference`,`conditiontarget`,`conditionvalue1`,`conditionvalue2`,`comment`) VALUES
(22,4,28340,0,31,1,3,27743,"Stratholme Citizen - Only execute SAI if entry is 27743 (Infinite Agent)");

-- Chromie #3 data
DELETE FROM `creature_template_addon` WHERE `entry`=30997;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`) VALUES
(30997,50331648);
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=30997;
DELETE FROM `creature_template_movement` WHERE `creatureid`=30997;
INSERT INTO `creature_template_movement` (`creatureid`,`ground`,`flight`) VALUES (30997,1,2);
DELETE FROM `creature_text` WHERE `creatureid`=30997;
INSERT INTO `creature_text` (`creatureid`,`groupid`,`text`,`type`,`probability`,`BroadcastTextId`,`comment`) VALUES
(30997,0,"Why, hello again!",12,100,32022,"Chromie #3 RP5_LINE_CHROMIE0");

-- Meathook
DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (52696,52666);
INSERT INTO `spelldifficulty_dbc` (`id`,`spellid0`,`spellid1`) VALUES
(52696,52696,58823),
(52666,52666,58824);

-- Salramm the Fleshcrafter
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_salramm_steal_flesh';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(52708,'spell_salramm_steal_flesh');
DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (52480,57725);
INSERT INTO `spelldifficulty_dbc` (`id`,`spellid0`,`spellid1`) VALUES
(52480,52480,58825),
(57725,57725,58827);

-- Chrono-Lord Epoch
DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (52737,52771);
INSERT INTO `spelldifficulty_dbc` (`id`,`spellid0`,`spellid1`) VALUES
(52737,52737,58829),
(52771,52771,58830);

-- Mal'ganis
DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (52720,52722,52721);
INSERT INTO `spelldifficulty_dbc` (`id`,`spellid0`,`spellid1`) VALUES
(52720,52720,58852),
(52722,52722,58850),
(52721,52721,58849);

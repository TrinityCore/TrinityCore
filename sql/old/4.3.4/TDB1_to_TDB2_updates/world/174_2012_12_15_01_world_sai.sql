-- ---------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 8644: EAI->SAI - Urom adds
-- Convert EAI -> SAI and not sure, if I even changed something, but I checked and stuff were working correct (as of mechanics).
SET @P_Murloc             := 27649;
SET @P_Cloudscraper       := 27645;
SET @P_Mammoth            := 27642;
SET @P_Wolf               := 27644;
SET @P_Air                := 27650;
SET @P_Water              := 27653;
SET @P_Fire               := 27651;
SET @P_Ogre               := 27647;
SET @P_Naga               := 27648;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@P_Murloc,@P_Cloudscraper,@P_Mammoth,@P_Wolf,@P_Air,@P_Water,@P_Fire,@P_Ogre,@P_Naga);
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (@P_Murloc,@P_Cloudscraper,@P_Mammoth,@P_Wolf,@P_Air,@P_Water,@P_Fire,@P_Ogre,@P_Naga);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@P_Murloc,@P_Cloudscraper,@P_Mammoth,@P_Wolf,@P_Air,@P_Water,@P_Fire,@P_Ogre,@P_Naga);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@P_Murloc,0,0,0,0,0,100,0,1000,3000,13000,16000,11,54074,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Phantasmal Murloc - IC - Cast poison'),
(@P_Naga,0,0,0,0,0,100,2,9000,12000,13000,16000,11,50732,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Phantasmal Naga - IC /Normal/ - Cast Water Tomb'),
(@P_Naga,0,1,0,0,0,100,4,9000,12000,13000,16000,11,59261,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Phantasmal Naga - IC /Heroic/ - Cast Water Tomb'),
(@P_Naga,0,2,0,0,0,100,2,1000,3000,9000,12000,11,49711,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Phantasmal Naga - IC /Normal/ - Cast Water Tomb'),
(@P_Naga,0,3,0,0,0,100,4,1000,3000,9000,12000,11,59260,0,0,0,0,0,5,0,0,0,0,0,0,0, 'Phantasmal Naga - IC /Heroic/ - Cast Water Tomb'),
(@P_Ogre,0,0,0,2,0,100,0,30,30,20000,24000,11,50730,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Phantasmal Ogre - On 30% - Cast Bloodlust at 30% HP'),
(@P_Ogre,0,1,0,0,0,100,0,3000,7000,9000,12000,11,50731,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Phantasmal Ogre - IC - Cast Mace Smash'),
(@P_Cloudscraper,0,0,0,0,0,100,4,3000,5000,4000,6000,11,59223,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Phantasmal Cloudscraper - IC /Heroic/ - Cast Chain Lightning'),
(@P_Cloudscraper,0,1,0,0,0,100,2,3000,7000,9000,12000,11,59220,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Phantasmal Cloudscraper - IC /Normal/ - Cast Chain Lightning'),
(@P_Cloudscraper,0,2,0,0,0,100,2,7000,10000,12000,15000,11,15588,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Phantasmal Cloudscraper - IC /Normal/ - Cast Thunderclap'),
(@P_Cloudscraper,0,3,0,0,0,100,4,7000,10000,12000,15000,11,59217,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Phantasmal Cloudscraper - IC /Heroic/ - Cast Thunderclap'),
(@P_Mammoth,0,0,0,9,0,100,0,8,25,2000,2500,11,32323,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Phantasmal Mammoth - IC - Cast Charge'),
(@P_Mammoth,0,1,0,0,0,100,0,4000,7000,12000,15000,11,59274,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Phantasmal Mammoth - IC - Cast Trample'),
(@P_Wolf,0,0,0,0,0,100,2,10000,13000,18000,24000,11,50728,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Phantasmal Wolf - IC /Normal/ - Cast Furious Howl'),
(@P_Wolf,0,1,0,0,0,100,4,10000,13000,18000,24000,11,59274,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Phantasmal Wolf - IC /Heroic/ - Cast Furious Howl'),
(@P_Wolf,0,2,0,0,0,100,2,4000,9000,9000,12000,11,50729,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Phantasmal Wolf - IC /Normal/ - Cast Carnivorous Bite'),
(@P_Wolf,0,3,0,0,0,100,4,4000,9000,9000,12000,11,59269,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Phantasmal Wolf - IC /Heroic/ - Cast Carnivorous Bite'),
(@P_Air,0,0,0,4,0,100,5,0,0,0,0,11,20545,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Phantasmal Air - On aggro /Heroic/ - Cast Lightning Shield'),
(@P_Air,0,1,0,4,0,100,3,0,0,0,0,11,25020,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Phantasmal Air - On aggro /Normal/ - Cast Lightning Shield'),
(@P_Fire,0,0,0,0,0,100,2,3000,8000,5000,9000,11,50744,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Phantasmal Fire - IC /Normla/ - Cast Blaze'),
(@P_Fire,0,1,0,0,0,100,4,3000,8000,5000,9000,11,59225,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Phantasmal Fire - IC /Heroic/ - Cast Blaze'),
(@P_Water,0,0,1,54,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Phantasmal Water - On spawn - Disable combat movement'),
(@P_Water,0,1,0,61,0,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Phantasmal Water - Linked with previous event - Set phase 0'),
(@P_Water,0,2,0,7,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Phantasmal Water - On Evade - Set phase 0'),
(@P_Water,0,3,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Phantasmal Water - On In Range /0-5/ - Allow combat movement'),
(@P_Water,0,4,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Phantasmal Water - On In Range /5-15/ - Disable combat movement'),
(@P_Water,0,5,0,9,1,100,0,30,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Phantasmal Water - On In Range /30-80/ - Allow combat movement'),
(@P_Water,0,6,7,3,1,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Phantasmal Water - On mana pct below 7% - Allow combat movement'),
(@P_Water,0,7,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Phantasmal Water - Linked with previous event - Increment phase by 1'),
(@P_Water,0,8,0,3,2,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0, 'Phantasmal Water - On mana pct above 15% - Decrement phase by 1'),
(@P_Water,0,9,10,4,0,100,3,0,0,0,0,11,37924,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Phantasmal Water - On aggro - Cast Water Bolt Volley'),
(@P_Water,0,10,0,61,0,100,3,0,0,0,0,23,1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Phantasmal Water - IC /Heroic/ - Increment phase by 1'),
(@P_Water,0,11,12,4,0,100,5,0,0,0,0,11,59266,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Phantasmal Water - On aggro - Cast Water Bolt Volley'),
(@P_Water,0,12,0,61,0,100,5,0,0,0,0,23,1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Phantasmal Water - IC /Heroic/ - Increment phase by 1'),
(@P_Water,0,13,0,9,1,100,2,0,35,3400,4800,11,37924,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Phantasmal Water - In range - Cast Water Bolt Volley'),
(@P_Water,0,14,0,9,1,100,4,0,35,3400,4800,11,59266,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Phantasmal Water - In range - Cast Water Bolt Volley');
-- ---------------------------------------------------------------------------------------------------------------------------------------------------
-- Fix quest: Whelps of the Wyrmcult http://www.wowhead.com/quest=10747
-- TO DO: Find why movement of the whelps is not prevented even, if unit flags are set from sniff values and contain disable move flag (not quest breaking by any means, most likely core handling bug somewhere).
-- ID indexes
SET @Blackwhelp :=         21387;
SET @CreateItem :=         38178;
SET @BlackwhelpNet :=      38177;
SET @Script := @Blackwhelp * 100;
-- Add SAI support for Wyrmcult Blackwhelp
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Blackwhelp;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@Blackwhelp;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Blackwhelp AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Script AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Blackwhelp,0,0,1,54,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Wyrmcult Blackwhelp - On spawn - Disable combat movement'),
(@Blackwhelp,0,1,0,61,0,100,1,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Wyrmcult Blackwhelp - Linked with previous event - Set phase 0'),
(@Blackwhelp,0,2,0,7,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Wyrmcult Blackwhelp - On Evade - Set phase 0'),
(@Blackwhelp,0,3,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Wyrmcult Blackwhelp - On In Range /0-5/ - Allow combat movement'),
(@Blackwhelp,0,4,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Wyrmcult Blackwhelp - On In Range /5-15/ - Disable combat movement'),
(@Blackwhelp,0,5,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Wyrmcult Blackwhelp - On In Range /35-80/ - Allow combat movement'),
(@Blackwhelp,0,6,7,3,1,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Wyrmcult Blackwhelp - On mana pct below 7% - Allow combat movement'),
(@Blackwhelp,0,7,0,61,1,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Wyrmcult Blackwhelp - Linked with previous event - Increment phase by 1'),
(@Blackwhelp,0,8,0,3,2,100,1,7,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0, 'Wyrmcult Blackwhelp - On mana pct above 7% - Decrement phase by 1'),
(@Blackwhelp,0,9,10,4,0,100,1,0,0,0,0,11,19816,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Wyrmcult Blackwhelp - On aggro - Cast Fireball'),
(@Blackwhelp,0,10,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Wyrmcult Blackwhelp - Linked with previous event - Increment phase by 1'),
(@Blackwhelp,0,11,0,5,1,100,0,0,40,3500,5200,11,19816,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Wyrmcult Blackwhelp - In range - Cast Fire Ball'),
(@Blackwhelp,0,12,0,8,0,100,1,@BlackwhelpNet,0,0,0,80,@Script,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Wyrmcult Blackwhelp - On spellhit by net - Start actionlist'),
(@Script,9,0,0,0,0,100,0,0,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Wyrmcult Blackwhelp - Action 1 - SET UNIT FIELD BYTES 1'),
(@Script,9,1,0,0,0,100,0,0,0,0,0,18,663552,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Wyrmcult Blackwhelp - Action 2 - Set unit flags'),
(@Script,9,2,0,0,0,100,0,5000,5000,0,0,11,38178,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Wyrmcult Blackwhelp - Action 3 - Cast credit spell to invoker'),
(@Script,9,3,0,0,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Wyrmcult Blackwhelp - Action 4 - Set unseen'),
(@Script,9,4,0,0,0,100,0,0,0,0,0,19,663552,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Wyrmcult Blackwhelp - Action 5 - Remove unit flags'),
(@Script,9,5,0,0,0,100,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Wyrmcult Blackwhelp - Action 6 - Remove unit field bytes 1'),
(@Script,9,6,0,0,0,100,0,0,0,0,0,41,100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Wyrmcult Blackwhelp - Action 7 - Despawn after 100 ms');
-- This is not directly related to the quest, but was on my way and it improves the experience of the quest
-- Insert missing go that is spawned by another go with a spell and can't be sniffed in order to cast spell that summon whelp (the difference in models is correct, also this double trap makes a lot of sense based on the video for the quest, on top of that there is delay set)
DELETE FROM `gameobject_template` WHERE `entry`=184839;
INSERT INTO `gameobject_template` (`entry`,`type`,`displayId`,`name`,`IconName`,`castBarCaption`,`unk1`,`faction`,`flags`,`size`,`questItem1`,`questItem2`,`questItem3`,`questItem4`,`questItem5`,`questItem6`,`data0`,`data1`,`data2`,`data3`,`data4`,`data5`,`data6`,`data7`,`data8`,`data9`,`data10`,`data11`,`data12`,`data13`,`data14`,`data15`,`data16`,`data17`,`data18`,`data19`,`data20`,`data21`,`data22`,`data23`,`AIName`,`ScriptName`,`WDBVerified`) VALUES
(184839,6,477, 'Wyrmcult Egg Spawner','','','',1827,0,1,0,0,0,0,0,0,0,0,5,36903,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'','',-1);
-- ---------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 4942: Galen's Escape
-- Remove Galen Goodward's immunity to NPC
UPDATE `creature_template` SET `unit_flags`=256 WHERE `entry`=5391;

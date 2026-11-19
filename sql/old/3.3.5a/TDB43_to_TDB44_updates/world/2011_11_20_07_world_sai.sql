-- [Q] [A/H] Ring of Blood
-- Gurghthock SAI
SET @ENTRY_GURTHOCK := 18471;
SET @ENTRY_BROKENTOE := 18398;
SET @ENTRY_TWIN := 18399;
SET @ENTRY_ROKDAR := 18400;
SET @ENTRY_SKRAGATH := 18401;
SET @ENTRY_WARMAUL := 18402;
SET @ENTRY_MOGOR := 18069;
SET @QUEST_BROKENTOE := 9962;
SET @QUEST_BLUE_BROTHERS := 9967;
SET @QUEST_ROKDAR := 9970;
SET @QUEST_SKRAGATH := 9972;
SET @QUEST_WARMAUL := 9973;
SET @QUEST_MOGOR := 9977;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY_GURTHOCK;
UPDATE `quest_template` SET `StartScript`=0,`CompleteScript`=0,`SpecialFlags`=2 WHERE `entry` IN (@QUEST_BROKENTOE,@QUEST_BLUE_BROTHERS,@QUEST_ROKDAR,@QUEST_SKRAGATH,@QUEST_WARMAUL,@QUEST_MOGOR);
DELETE FROM `quest_start_scripts` WHERE `id` IN (@QUEST_BROKENTOE,@QUEST_BLUE_BROTHERS,@QUEST_ROKDAR,@QUEST_SKRAGATH,@QUEST_WARMAUL,@QUEST_MOGOR);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY_GURTHOCK,@ENTRY_GURTHOCK*100+0,@ENTRY_GURTHOCK*100+1,@ENTRY_GURTHOCK*100+2,@ENTRY_GURTHOCK*100+3,@ENTRY_GURTHOCK*100+4);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY_GURTHOCK,0,0,1,19,0,100,0,@QUEST_BROKENTOE,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurghthock - On Quest Accept - Say Line 0"),
(@ENTRY_GURTHOCK,0,1,0,61,0,100,0,0,0,0,0,80,@ENTRY_GURTHOCK*100+0,0,2,0,0,0,1,0,0,0,0,0,0,0,"Gurghthock - On Quest Accept - Run Script"),
(@ENTRY_GURTHOCK,0,2,3,19,0,100,0,@QUEST_BLUE_BROTHERS,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurghthock - On Quest Accept - Say Line 0"),
(@ENTRY_GURTHOCK,0,3,0,61,0,100,0,0,0,0,0,80,@ENTRY_GURTHOCK*100+1,0,2,0,0,0,1,0,0,0,0,0,0,0,"Gurghthock - On Quest Accept - Run Script"),
(@ENTRY_GURTHOCK,0,4,5,19,0,100,0,@QUEST_ROKDAR,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurghthock - On Quest Accept - Say Line 0"),
(@ENTRY_GURTHOCK,0,5,0,61,0,100,0,0,0,0,0,80,@ENTRY_GURTHOCK*100+2,0,2,0,0,0,1,0,0,0,0,0,0,0,"Gurghthock - On Quest Accept - Run Script"),
(@ENTRY_GURTHOCK,0,6,7,19,0,100,0,@QUEST_SKRAGATH,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurghthock - On Quest Accept - Say Line 0"),
(@ENTRY_GURTHOCK,0,7,0,61,0,100,0,0,0,0,0,80,@ENTRY_GURTHOCK*100+3,0,2,0,0,0,1,0,0,0,0,0,0,0,"Gurghthock - On Quest Accept - Run Script"),
(@ENTRY_GURTHOCK,0,8,9,19,0,100,0,@QUEST_WARMAUL,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurghthock - On Quest Accept - Say Line 0"),
(@ENTRY_GURTHOCK,0,9,0,61,0,100,0,0,0,0,0,80,@ENTRY_GURTHOCK*100+4,0,2,0,0,0,1,0,0,0,0,0,0,0,"Gurghthock - On Quest Accept - Run Script"),
(@ENTRY_GURTHOCK*100+0,9,0,0,0,0,100,0,13000,13000,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurgthock - On Script - Say Line 1"),
(@ENTRY_GURTHOCK*100+0,9,1,0,0,0,100,0,5000,5000,0,0,12,@ENTRY_BROKENTOE,1,120000,0,0,0,8,0,0,0,-704.669,7871.08,45.0387,1.59531,"Gurghthock - On Script - Summon Brokentoe"),
(@ENTRY_GURTHOCK*100+1,9,0,0,0,0,100,0,13000,13000,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurgthock - On Script - Say Line 3"),
(@ENTRY_GURTHOCK*100+1,9,1,0,0,0,100,0,5000,5000,0,0,12,@ENTRY_TWIN,1,120000,0,0,0,8,0,0,0,-717.852356,7877.326660,45.547367,1.599185,"Gurghthock - On Script - Summon Murkblood Twin"),
(@ENTRY_GURTHOCK*100+1,9,2,0,0,0,100,0,0,0,0,0,12,@ENTRY_TWIN,1,120000,0,0,0,8,0,0,0,-695.944275,7880.357910,47.097507,2.084561,"Gurghthock - On Script - Summon Murkblood Twin"),
(@ENTRY_GURTHOCK*100+2,9,0,0,0,0,100,0,13000,13000,0,0,1,5,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurgthock - On Script - Say Line 5"),
(@ENTRY_GURTHOCK*100+2,9,1,0,0,0,100,0,5000,5000,0,0,12,@ENTRY_ROKDAR,1,120000,0,0,0,8,0,0,0,-704.669,7871.08,45.0387,1.59531,"Gurghthock - On Script - Summon Rokdar the Sundered Lord"),
(@ENTRY_GURTHOCK*100+3,9,0,0,0,0,100,0,13000,13000,0,0,1,7,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurgthock - On Script - Say Line 7"),
(@ENTRY_GURTHOCK*100+3,9,1,0,0,0,100,0,5000,5000,0,0,12,@ENTRY_SKRAGATH,1,120000,0,0,0,8,0,0,0,-704.669,7871.08,45.0387,1.59531,"Gurghthock - On Script - Summon Skra'gath"),
(@ENTRY_GURTHOCK*100+4,9,0,0,0,0,100,0,13000,13000,0,0,1,9,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurgthock - On Script - Say Line 9"),
(@ENTRY_GURTHOCK*100+4,9,1,0,0,0,100,0,5000,5000,0,0,12,@ENTRY_WARMAUL,1,120000,0,0,0,8,0,0,0,-704.669,7871.08,45.0387,1.59531,"Gurghthock - On Script - Summon Warmaul Champion"),
(@ENTRY_GURTHOCK,0,10,11,19,0,100,0,@QUEST_MOGOR,0,0,0,1,11,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurghthock - On Quest Accept - Say Line 11"),
(@ENTRY_GURTHOCK,0,11,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,@ENTRY_MOGOR,0,0,0,0,0,0,"Gurghthock - On Quest Accept - Set Data Mogor"),
(@ENTRY_GURTHOCK,0,12,0,38,0,100,0,10,10,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurghthock - On Data Set - Say Line 2"), -- Brokentoe's death
(@ENTRY_GURTHOCK,0,13,0,38,0,100,0,11,11,0,0,1,4,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurghthock - On Data Set - Say Line 4"), -- Murkblood Twins death
(@ENTRY_GURTHOCK,0,14,15,38,0,100,0,12,12,0,0,1,6,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurghthock - On Data Set - Say Line 6"), -- Rokdar the Sundered Lord's death
(@ENTRY_GURTHOCK,0,15,0,61,0,100,0,0,0,0,0,45,12,12,0,0,0,0,19,18069,0,0,0,0,0,0,"Gurghthock - On Data Set - Set Data Mogor"), -- Rokdar the Sundered Lord's death
(@ENTRY_GURTHOCK,0,16,17,38,0,100,0,13,13,0,0,1,8,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurghthock - On Data Set - Say Line 8"), -- Skra'gath's death
(@ENTRY_GURTHOCK,0,17,0,61,0,100,0,0,0,0,0,45,13,13,0,0,0,0,19,18069,0,0,0,0,0,0,"Gurghthock - On Data Set - Set Data Mogor"), -- Skra'gath's death
(@ENTRY_GURTHOCK,0,18,19,38,0,100,0,14,14,0,0,1,10,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gurghthock - On Data Set - Say Line 10"), -- Warmaul Champion's death
(@ENTRY_GURTHOCK,0,19,0,61,0,100,0,0,0,0,0,45,14,14,0,0,0,0,19,18069,0,0,0,0,0,0,"Gurghthock - On Data Set - Set Data Mogor"); -- Warmaul Champion's death
-- Text
DELETE FROM `db_script_string` WHERE `entry` IN (2000000001,2000000002,2000000003,2000000102,2000000103,2000000104);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY_GURTHOCK;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY_GURTHOCK,0,0,"Get in the Ring of Blood, $N. The fight is about to start!",12,0,100,0,0,0,"Gurgthock"),
(@ENTRY_GURTHOCK,1,0,"The battle is about to begin! $N versus the ferocious clefthoof, Brokentoe!",14,0,100,0,0,0,"Gurgthock"),
(@ENTRY_GURTHOCK,2,0,"$N has defeated Brokentoe!",14,0,100,0,0,0,"Gurgthock"),
(@ENTRY_GURTHOCK,3,0,"The battle is about to begin! The unmerciful Murkblood twins versus $N!",14,0,100,0,0,0,"Gurgthock"),
(@ENTRY_GURTHOCK,4,0,"Unbelievable! $N has defeated the Murkblood Twins!",14,0,100,0,0,0,"Gurgthock"),
(@ENTRY_GURTHOCK,5,0,"Hailing from the mountains of Blade's Edge comes Rokdar the Sundered Lord! $N is in for the fight of $g his:her; life.",14,0,100,0,0,0,"Gurgthock"),
(@ENTRY_GURTHOCK,6,0,"$N is victorious once more!",14,0,100,0,0,0,"Gurgthock"),
(@ENTRY_GURTHOCK,7,0,"From parts unkown: Skra'gath! Can $N possibly survive the onslaught of void energies?",14,0,100,0,0,0,"Gurgthock"),
(@ENTRY_GURTHOCK,8,0,"$N is victorious once more!",14,0,100,0,0,0,"Gurgthock"),
(@ENTRY_GURTHOCK,9,0,"This is the moment we've all been waiting for! The Warmaul champion is about to make $g his:her; first showing at the Ring of Blood in weeks! Will $N go down in defeat as easily as the champion's other opponents? We shall see...",14,0,100,0,0,0,"Gurgthock"),
(@ENTRY_GURTHOCK,10,0,"$N is victorious once more!",14,0,100,0,0,0,"Gurgthock"),
(@ENTRY_GURTHOCK,11,0,"Mogor has challenged you. You have to accept! Get in the ring if you are ready to fight.",12,0,100,0,0,0,"Gurgthock");
-- Mogor SAI
SET @ENTRY := 18069;
SET @QUEST := 9977;
SET @SPELL_CHAIN_LIGHTNING := 16033;
SET @SPELL_FLAME_SHOCK := 39529;
SET @SPELL_HEALING_WAVE := 15982;
SET @SPELL_FRENZY := 28747;
SET @SPELL_REVIVE_SELF := 32343;
UPDATE `creature_template` SET `AIName`="SmartAI",`faction_A`=35,`faction_H`=35 WHERE `entry`=@ENTRY;
DELETE FROM `creature` WHERE `id`=@ENTRY;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(1022681,@ENTRY,530,1,1,0,0,-714.823,7931.65,58.8672,4.3693,300,0,0,60720,29330,0,0,0,0);
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100,@ENTRY*100+1);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,3500,3500,11,@SPELL_CHAIN_LIGHTNING,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mogor - In Combat - Cast Chain Lightning"),
(@ENTRY,0,1,0,0,0,100,0,4000,4000,11000,13000,11,@SPELL_FLAME_SHOCK,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mogor - In Combat - Cast Flame Shock"),
(@ENTRY,0,2,0,2,0,100,1,0,60,0,0,11,@SPELL_HEALING_WAVE,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mogor - At 60% HP - Cast Healing Wave"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,@SPELL_FRENZY,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mogor - At 30% HP - Cast Frenzy"),
(@ENTRY,0,4,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Mogor - At 30% HP - Say Line 0"),
(@ENTRY,0,5,0,6,0,100,1,0,0,0,0,80,@ENTRY*100+1,0,2,0,0,0,1,0,0,0,0,0,0,0,"Mogor - On Death - Run Script"),
(@ENTRY*100+1,9,0,0,0,0,100,0,2000,2000,0,0,11,@SPELL_REVIVE_SELF,2,0,0,0,0,1,0,0,0,0,0,0,0,"Mogor - On Script - Cast Revive Self"),
(@ENTRY*100+1,9,1,0,0,0,100,0,1000,1000,0,0,70,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mogor - On Script - Revive Self"),
(@ENTRY*100+1,9,2,0,0,0,100,0,1000,1000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mogor - On Script - Say Line 5"),
(@ENTRY*100+1,9,3,0,0,0,100,0,500,500,0,0,49,0,0,0,0,0,0,21,0,0,0,0,0,0,0,"Mogor - On Script - Attack Closest Player"),
(@ENTRY,0,6,0,38,0,100,0,12,12,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mogor - On Data Set - Say Line 1"), -- Rokdar the Sundered Lord's death
(@ENTRY,0,7,0,38,0,100,0,13,13,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mogor - On Data Set - Say Line 2"), -- Skra'gath's death
(@ENTRY,0,8,0,38,0,100,0,14,14,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mogor - On Data Set - Say Line 6"), -- Warmaul Champion's death
(@ENTRY,0,9,10,38,0,100,0,1,1,0,0,53,0,@ENTRY,0,0,0,0,1,0,0,0,0,0,0,0,"Mogor - On Data Set - Start WP"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mogor - On Data Set - Say Line 3"),
(@ENTRY,0,11,12,40,0,100,0,4,@ENTRY,0,0,54,100000,0,2,0,0,0,1,0,0,0,0,0,0,0,"Mogor - At WP 4 - Pause Path"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Mogor - At WP 4 - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mogor - On Script - Say Line 4"),
(@ENTRY*100,9,1,0,0,0,100,0,5000,5000,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mogor - On Script - Set Faction Aggressive"),
(@ENTRY*100,9,2,0,0,0,100,0,9,9,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mogor - On Script - Set React State Aggressive"),
(@ENTRY,0,13,0,21,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mogor - Reached Home - Set Faction Friendly"); -- To prevent issues =)
-- Waypoints
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,-715.036621,7922.948730,59.506184,"Mogor"),
(@ENTRY,2,-720.282532,7916.268066,57.146416,"Mogor"),
(@ENTRY,3,-724.706299,7909.140137,51.817696,"Mogor"),
(@ENTRY,4,-717.016479,7896.937500,48.460430,"Mogor");
-- Texts
DELETE FROM `db_script_string` WHERE `entry` IN (2000000001,2000000002,2000000003);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Mogor"),
(@ENTRY,1,0,"Dat was poop! Mogor could put up much better fight den dat!",14,0,100,0,0,0,"Mogor"),
(@ENTRY,2,0,"Mogor not impressed! Skra'gath wuz made of da air and shadow! Soft like da squishy orcies!",14,0,100,0,0,0,"Mogor"),
(@ENTRY,3,0,"Now you face da true champion! I give you chance to run away little one. Run away now before Mogor decim... destyor... Run away before Mogor KILL!",14,0,100,0,0,0,"Mogor"),
(@ENTRY,4,0,"No more chances! Now you pay da ogre!",14,0,100,15,0,0,"Mogor"), -- ONESHOT_ROAR
(@ENTRY,5,0,"No more nice ogre! You hurt Mogor!",14,0,100,0,0,0,"Mogor"),
(@ENTRY,6,0,"WUT!? UNPOSSIBLE!! You fight Mogor now! Mogor destroy!",14,0,100,0,0,0,"Mogor");
-- Brokentoe SAI
SET @ENTRY := 18398;
SET @QUEST := 9962;
SET @SPELL_HOOF_STOMP := 32023;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,9000,11000,11,@SPELL_HOOF_STOMP,0,0,0,0,0,2,0,0,0,0,0,0,0,"Brokentoe - In Combat - Cast Hoof Stomp"),
(@ENTRY,0,1,2,6,0,100,1,0,0,0,0,15,@QUEST,0,0,0,0,0,24,0,0,0,0,0,0,0,"Brokentoe - On Death - Give Quest Credit"),
(@ENTRY,0,2,0,61,0,100,1,0,0,0,0,45,10,10,0,0,0,0,19,18471,0,0,0,0,0,0,"Brokentoe - On Death - Set Data Gurghthock");
-- Murkblood Twin SAI
SET @ENTRY := 18399;
SET @QUEST := 9967;
SET @SPELL_EVISCERATE := 15691;
SET @SPELL_MUTILATE := 32319;
SET @SPELL_SINISTER_STRIKE := 14873;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Murkblood Twin - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,1000,1000,2000,2000,11,@SPELL_SINISTER_STRIKE,1,0,0,0,0,2,0,0,0,0,0,0,0,"Murkblood Twin - In Combat - Cast Sinister Strike"),
(@ENTRY,0,2,0,0,0,100,0,5000,6000,11000,12000,11,@SPELL_EVISCERATE,1,0,0,0,0,2,0,0,0,0,0,0,0,"Murkblood Twin - In Combat - Cast Eviscerate"),
(@ENTRY,0,3,0,0,0,100,0,8000,9000,15000,16000,11,@SPELL_MUTILATE,1,0,0,0,0,2,0,0,0,0,0,0,0,"Murkblood Twin - In Combat - Cast Gouge"),
(@ENTRY,0,4,5,6,0,100,1,0,0,0,0,15,@QUEST,0,0,0,0,0,24,0,0,0,0,0,0,0,"Murkblood Twin - On Death - Give Quest Credit"),
(@ENTRY,0,5,0,61,0,100,1,0,0,0,0,45,11,11,0,0,0,0,19,18471,0,0,0,0,0,0,"Murkblood Twin - On Death - Set Data Gurghthock");
-- Texts
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Blue brothers reign supreme!",12,0,100,0,0,0,"Murkblood Twin");
-- Rokdar the Sundered Lord SAI
SET @ENTRY := 18400;
SET @QUEST := 9970;
SET @SPELL_WAR_STOMP := 16727;
SET @SPELL_PUNCTURE := 15976;
SET @SPELL_KNOCK_AWAY := 31389;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Rokdar the Sundered Lord - Out of Combat - Say Line"),
(@ENTRY,0,1,0,0,0,100,0,1000,1000,9000,11000,11,@SPELL_WAR_STOMP,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rokdar the Sundered Lord - In Combat - Cast War Stomp"),
(@ENTRY,0,2,0,31,0,100,0,@SPELL_KNOCK_AWAY,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rokdar the Sundered Lord - On Target Spellhit War Stomp - Say Line"),
(@ENTRY,0,3,0,0,0,100,0,6000,6000,12000,12000,11,@SPELL_KNOCK_AWAY,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rokdar the Sundered Lord - In Combat - Cast Knock Away"),
(@ENTRY,0,4,0,0,0,100,0,20000,20000,25000,25000,11,@SPELL_PUNCTURE,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rokdar the Sundered Lord - In Combat - Cast Puncture"),
(@ENTRY,0,5,6,6,0,100,1,0,0,0,0,15,@QUEST,0,0,0,0,0,24,0,0,0,0,0,0,0,"Rokdar the Sundered Lord - On Death - Give Quest Credit"),
(@ENTRY,0,6,0,61,0,100,1,0,0,0,0,45,12,12,0,0,0,0,19,18471,0,0,0,0,0,0,"Rokdar the Sundered Lord - On Death - Set Data Gurghthock");
-- Texts
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"ROKDAR SMASH PUNY %t!",14,0,100,0,0,0,"Rokdar the Sundered Lord");
-- Skra'gath SAI
SET @ENTRY := 18401;
SET @QUEST := 9972;
SET @SPELL_DRAINING_TOUCH := 29299;
SET @SPELL_SHADOW_BURST := 32324;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,11,@SPELL_DRAINING_TOUCH,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skra'gath - Out of Combat - Cast Draining Touch"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Skra'gath - On Aggro - Say Line"),
(@ENTRY,0,2,0,0,0,100,0,6000,6000,12000,12000,11,@SPELL_SHADOW_BURST,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skra'gath - In Combat - Cast Shadow Burst"),
(@ENTRY,0,3,4,6,0,100,1,0,0,0,0,15,@QUEST,0,0,0,0,0,24,0,0,0,0,0,0,0,"Skra'gath - On Death - Give Quest Credit"),
(@ENTRY,0,4,0,61,0,100,1,0,0,0,0,45,13,13,0,0,0,0,19,18471,0,0,0,0,0,0,"Skra'gath - On Death - Set Data Gurgthock");
-- Texts
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Closer... Come closer... See what the void brings!",14,0,100,0,0,0,"Skra'gath");
-- Warmaul Champion SAI
SET @ENTRY := 18402;
SET @QUEST := 9973;
SET @SPELL_BATTLE_SHOUT := 31403;
SET @SPELL_CHARGE := 32323;
SET @SPELL_MORTAL_STRIKE := 15708;
SET @SPELL_SUNDERING_CLEAVE := 17963;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Warmaul Champion - On Aggro - Say Line"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,11,@SPELL_BATTLE_SHOUT,1,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Champion - On Aggro - Cast Battle Shout"),
(@ENTRY,0,2,0,9,0,100,1,5,30,1500,2000,11,@SPELL_CHARGE,1,0,0,0,0,2,0,0,0,0,0,0,0,"Warmaul Champion - On Player Range - Cast Charge"),
(@ENTRY,0,3,0,0,0,100,0,3000,4000,6000,7000,11,@SPELL_MORTAL_STRIKE,1,0,0,0,0,2,0,0,0,0,0,0,0,"Warmaul Champion - In Combat - Cast Mortal Strike"),
(@ENTRY,0,4,0,0,0,100,0,1000,1000,9000,11000,11,@SPELL_SUNDERING_CLEAVE,1,0,0,0,0,2,0,0,0,0,0,0,0,"Warmaul Champion - In Combat - Cast Sundering Cleave"),
(@ENTRY,0,4,5,6,0,100,1,0,0,0,0,15,@QUEST,0,0,0,0,0,24,0,0,0,0,0,0,0,"Warmaul Champion - On Death - Give Quest Credit"),
(@ENTRY,0,5,0,61,0,100,1,0,0,0,0,45,14,14,0,0,0,0,19,18471,0,0,0,0,0,0,"Warmaul Champion - On Death - Set Data Gurgthock");
-- Text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Piece by piece I will tear this challenger apart... PIECE BY PIECE!",14,0,100,0,0,0,"Warmaul Champion");

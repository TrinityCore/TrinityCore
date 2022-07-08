-- Prospector Remtravel
DELETE FROM `creature_text` WHERE `CreatureID`=2917;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2917,0,0,"Ok, $n, let's go find where I left that mysterious fossil. Follow me!",12,7,100,0,0,0,925,0,"remtravel SAY_REM_START"),
(2917,1,0,"Something tells me this $n wants the mysterious fossil too. Help!",12,7,100,0,0,0,941,0,"remtravel SAY_REM_AGGRO"),
(2917,1,1,"Oh my! What's this? Help!",12,7,100,0,0,0,938,0,"remtravel SAY_REM_AGGRO"),
(2917,1,2,"Looks like we've uncovered this $n. Now help me kill it!",12,7,100,0,0,0,939,0,"remtravel SAY_REM_AGGRO"),
(2917,1,3,"Help me! This $n won't get off of me!",12,7,100,0,0,0,940,0,"remtravel SAY_REM_AGGRO"),
(2917,1,4,"$n! Help!",12,7,100,0,0,0,942,0,"remtravel SAY_REM_AGGRO"),
(2917,1,5,"Can you get this $n off me?",12,7,100,0,0,0,943,0,"remtravel SAY_REM_AGGRO"),
(2917,2,0,"Now where did I put that mysterious fossil? Ah, maybe up there...",12,7,100,0,0,0,926,0,"remtravel SAY_REM_RAMP1_1"),
(2917,3,0,"Hrm, nothing up here.",12,7,100,0,0,0,927,0,"remtravel SAY_REM_RAMP1_2"),
(2917,4,0,"No mysterious fossil here... Ah, but my copy of Green Hills of Stranglethorn.  What a good book!",12,7,100,0,0,0,928,0,"remtravel SAY_REM_BOOK"),
(2917,5,0,"I bet you I left it in the tent!",12,7,100,0,0,0,929,0,"remtravel SAY_REM_TENT1_1"),
(2917,6,0,"Oh wait, that's Hollee's tent... and it's empty.",12,7,100,0,0,0,930,0,"remtravel SAY_REM_TENT1_2"),
(2917,7,0,"Interesting... I hadn't noticed this earlier...",12,7,100,0,0,0,931,0,"remtravel SAY_REM_MOSS"),
(2917,8,0,"%s inspects the ancient, mossy stone.",16,0,100,0,0,0,932,0,"remtravel EMOTE_REM_MOSS"),
(2917,9,0,"Oh wait! I'm supposed to be looking for that mysterious fossil!",12,7,100,0,0,0,933,0,"remtravel SAY_REM_MOSS_PROGRESS"),
(2917,10,0,"Nope, didn't leave the fossil back here!",12,7,100,0,0,0,935,0,"remtravel SAY_REM_PROGRESS"),
(2917,11,0,"Ah, I remember now! I gave the mysterious fossil to Hollee! Check with her.",12,7,100,0,0,0,936,0,"remtravel SAY_REM_REMEMBER"),
(2917,12,0,"%s goes back to work, oblivious to everything around him.",16,0,100,0,0,0,937,0,"remtravel EMOTE_REM_END");

-- Gravelflint Scout
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2158;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2158 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2158,0,0,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Gravelflint Scout - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Gravelflint Bonesnapper
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2159;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2159 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2159,0,0,0,0,0,100,0,3000,6000,8000,12000,0,11,3148,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gravelflint Bonesnapper - In Combat - Cast 'Head Crack'"),
(2159,0,1,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Gravelflint Bonesnapper - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Gravelflint Geomancer
UPDATE `creature_template` SET `AIName`="SmartAI", `unit_class`=8 WHERE `entry`=2160;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2160 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2160,0,0,0,23,0,100,0,12544,0,3000,5000,0,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gravelflint Geomancer - On Has No Aura 'Frost Armor' - Cast 'Frost Armor'"),
(2160,0,1,0,0,0,100,0,0,0,3000,5000,0,11,19816,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gravelflint Geomancer - In Combat - Cast 'Fireball'"),
(2160,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Gravelflint Geomancer - Between 0-15% Health - Flee For Assist (No Repeat)");

--
DELETE FROM `areatrigger_scripts` WHERE `entry`IN(5685,5684);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES 
(5684, 'SmartTrigger'),
(5685, 'SmartTrigger');

DELETE FROM `creature_text` WHERE `CreatureID`=37781 AND `GroupID`=2;
DELETE FROM `creature_text` WHERE `CreatureID`=37764 AND `GroupID`=2;
DELETE FROM `creature_text` WHERE `CreatureID`=37764 AND `GroupID`=3;
DELETE FROM `creature_text` WHERE `CreatureID`=37763 AND `GroupID`=5;
DELETE FROM `creature_text` WHERE `CreatureID`=37763 AND `GroupID`=6;
DELETE FROM `creature_text` WHERE `CreatureID`=37763 AND `GroupID`=7;
DELETE FROM `creature_text` WHERE `CreatureID`=37765 AND `GroupID`=3;
DELETE FROM `creature_text` WHERE `CreatureID`=37765 AND `GroupID`=4;
DELETE FROM `creature_text` WHERE `CreatureID`=37763 AND `GroupID`=8;
DELETE FROM `creature_text` WHERE `CreatureID`IN(38052,38047);

INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(38052, 0, 0, "My brothers and sisters, words cannot describe what I felt upon seeing the Sunwell rekindled.", 12, 0, 100, 1, 0, 0, 37809, 0, 'Lady Liadrin'),
(38052, 1, 0, "In that moment, the Light revealed to me the truth of the terrible things I had done.", 12, 0, 100, 1, 0, 0, 37811, 0, 'Lady Liadrin'),
(38052, 2, 0, "Our people had walked a dark path and mine was among the darkest of them all.", 12, 0, 100, 1, 0, 0, 37813, 0, 'Lady Liadrin'),
(38052, 3, 0, "But the Light showed me that I was not lost. It helped me to find the strength to survive in spite of all that had happened and all the evil I had wrought.", 12, 0, 100, 1, 0, 0, 37814, 0, 'Lady Liadrin'),
(38052, 4, 0, "It is a strength that we sin'dorei all share. It is a strength we will need to free ourselves of the addiction ravaging our people.", 12, 0, 100, 1, 0, 0, 37815, 0, 'Lady Liadrin'),
(38052, 5, 0, "It will be the most difficult battle we have ever faced, but our resolve and the power of the Sunwell will sustain us until we have been restored to our greatness.", 12, 0, 100, 1, 0, 0, 37816, 0, 'Lady Liadrin'),
(38047, 0, 0, "Well said, my lady. We sin'dorei will be free and we shall be great again!", 12, 0, 100, 1, 0, 0, 37817, 0, 'Blood Elf Pilgrim'),
(37781, 2, 0, "Can that really be Quel'Delar?", 12, 0, 100, 1, 0, 0, 37441, 0, 'Sunwell Honor Guard'),
(37764, 2, 0, "It is indeed Quel'Delar. I had not thought I'd live to see the day when Thalorien Dawnseeker's legendary sword would be restored to us.", 12, 0, 100, 1, 0, 0, 37449, 0, 'Lor themar Theron'),
(37764, 3, 0, "You are a hero and an inspiration to the sin'dorei, $n, a symbol of our endurance in the face of tragedy and treachery.", 12, 0, 100, 1, 0, 0, 37450, 0, 'Lor themar Theron'),
(37763, 5, 0, "The regent speaks truly, $n. Thalorien's sacrifice could not prevent the fall of this very Sunwell.", 12, 0, 100, 1, 0, 0, 37451, 0, 'Grand Magister Rommat'),
(37763, 6, 0, "When you found the sword, it was broken and abandoned, much like Silvermoon after Kael'thas's betrayal.", 12, 0, 100, 1, 0, 0, 37452, 0, 'Grand Magister Rommat'),
(37763, 7, 0, "Let Quel'Delar be a sign that we will never give up, that we will face any enemy without fear.", 12, 0, 100, 1, 0, 0, 37453, 0, 'Grand Magister Rommat'),
(37765, 3, 0, "Quel'Delar is not held in high esteem by the sin'dorei alone. It holds a place in the heart of all children of Silvermoon.", 12, 0, 100, 1, 0, 0, 37454, 0, 'Captain Auric Sunchaser'),
(37765, 4, 0, "This blade has been returned to us for a reason, my lords. Now is the time to rally behind the bearer of Quel'Delar and avenge the destruction of Silvermoon and the Sunwell.", 12, 0, 100, 1, 0, 0, 37455, 0, 'Captain Auric Sunchaser'),
(37763, 8, 0, "Reclaim the sword, $n, and bear it through that portal to Dalaran. Archmage Aethas Sunreaver will be waiting to congratulate you.", 12, 0, 100, 1, 0, 0, 37456, 0, 'Grand Magister Rommat');


DELETE FROM `smart_scripts` WHERE `entryorguid`IN(5684,5685) AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(5684, 2, 0, 1, 46, 0, 100, 0, 5684, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'On Trigger - Store Target List'),
(5684, 2, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 10, 123012, 38056, 0, 0, 0, 0, 0, 0, 'On Trigger - Send Target List to Chamberlain Galiros'),
(5684, 2, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 123012, 38056, 0, 0, 0, 0, 0, 0, 'On Trigger - Set Data on Chamberlain Galiros'),
(5685, 2, 0, 1, 46, 0, 100, 0, 5685, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'On Trigger - Store Target List'),
(5685, 2, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 10, 123012, 38056, 0, 0, 0, 0, 0, 0, 'On Trigger - Send Target List to Chamberlain Galiros'),
(5685, 2, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 123012, 38056, 0, 0, 0, 0, 0, 0, 'On Trigger - Set Data on Chamberlain Galiros');

DELETE FROM `spell_area` WHERE `spell`=70193 AND `area`IN(4094,4075);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(70193, 4094, 24522, 24535, 0, 0, 2, 1, 74, 11),
(70193, 4094, 24562, 24563, 0, 0, 2, 1, 74, 11),
(70193, 4094, 24553, 24553, 0, 0, 2, 1, 74, 11),
(70193, 4094, 24564, 24564, 0, 0, 2, 1, 74, 11),
(70193, 4094, 24594, 24594, 0, 0, 2, 1, 74, 11),
(70193, 4094, 24595, 24595, 0, 0, 2, 1, 74, 11),
(70193, 4094, 24596, 24596, 0, 0, 2, 1, 74, 11),
(70193, 4094, 24598, 24598, 0, 0, 2, 1, 74, 11),
(70193, 4075, 24553, 24553, 0, 0, 2, 1, 74, 11),
(70193, 4075, 24564, 24564, 0, 0, 2, 1, 74, 11),
(70193, 4075, 24594, 24594, 0, 0, 2, 1, 74, 11),
(70193, 4075, 24595, 24595, 0, 0, 2, 1, 74, 11),
(70193, 4075, 24596, 24596, 0, 0, 2, 1, 74, 11),
(70193, 4075, 24598, 24598, 0, 0, 2, 1, 74, 11);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=70466;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 70466, 0, 0, 31, 0, 3, 37745, 0, 0, 0, 0, '', 'Sunwell Light Ray targets Quel delar');


DELETE FROM `gameobject` WHERE `guid`=9897;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `ScriptName`, `VerifiedBuild`) VALUES 
(9897, 201796, 580, 0, 0, 1, 2048, 1698.92, 628.188, 27.6144, 0.334681, -0, -0, -0.166561, -0.986031, 300, 255, 1, '', 0);

DELETE FROM `event_scripts` WHERE `id`IN(22833,22854);
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES 
(22833, 0, 10, 37745, 1800000, 0, 0, 0, 0, 0), -- Blood Elf
(22833, 1, 10, 39691, 1800000, 0, 0, 0, 0, 0), -- Blood Elf
(22854, 0, 10, 37745, 1800000, 0, 0, 0, 0, 0), -- Non Blood Elf
(22854, 1, 10, 39692, 1800000, 0, 0, 0, 0, 0); -- Non Blood Elf

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`IN(37745,37746,37763,37764,37765,38056,37781,37527,37523,39691,39692,38052,38047);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(37745,37746,37763,37764,37765,38056,37781,-122985,-122777,-122953,37527,37523,39691,39692,38052,38047,-122624) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(3774500,3774501,3776500,3776400,3805200) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-122624,0,0,0,11,0,100,0,0,0,0,0,1,0,12000,0,0,0,0,19,38052,0,0,0,0,0,0,"Lady Liadrin - On Spawn - Say Line 0"),
(-122624,0,1,0,52,0,100,0,0,38052,0,0,1,1,12000,0,0,0,0,19,38052,0,0,0,0,0,0,"Lady Liadrin - On Text Over - Say Line 1"),
(-122624,0,2,0,52,0,100,0,1,38052,0,0,1,2,12000,0,0,0,0,19,38052,0,0,0,0,0,0,"Lady Liadrin - On Text Over - Say Line 2"),
(-122624,0,3,0,52,0,100,0,2,38052,0,0,1,3,12000,0,0,0,0,19,38052,0,0,0,0,0,0,"Lady Liadrin - On Text Over - Say Line 3"),
(-122624,0,4,0,52,0,100,0,3,38052,0,0,1,4,12000,0,0,0,0,19,38052,0,0,0,0,0,0,"Lady Liadrin - On Text Over - Say Line 4"),
(-122624,0,5,0,52,0,100,0,4,38052,0,0,1,5,8000,0,0,0,0,19,38052,0,0,0,0,0,0,"Lady Liadrin - On Text Over - Say Line 5"),
(-122624,0,6,0,52,0,100,0,5,38052,0,0,1,0,240000,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Liadrin - On Text Over - Say Line 5"),
(-122624,0,7,0,52,0,100,0,0,38047,0,0,1,0,12000,0,0,0,0,19,38052,0,0,0,0,0,0,"Lady Liadrin - On Text Over - Say Line 0"),
(39691,0,0,0,54,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,37745,0,0,0,0,0,0,"Bunny Set Data"),
(39692,0,0,0,54,0,100,0,0,0,0,0,45,2,2,0,0,0,0,19,37745,0,0,0,0,0,0,"Bunny Set Data"),
(37523,0,0,1,62,0,100,0,10963,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Warden of the Sunwell - On Gossip Option selected - close gossip'"),
(37523,0,1,0,61,0,100,0,0,0,0,0,134,70746,0,0,0,0,0,7,0,0,0,0,0,0,0,"Warden of the Sunwell - On Gossip Option selected - Invoker cast 70746'"),
(37763,0,0,0,38,0,100,0,1,1,0,0,53,0,37763,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Magister Rommath - Data Set - Start WP'"),
(37763,0,1,0,38,0,100,0,2,2,0,0,11,70540,0,0,0,0,0,12,1,0,0,0,0,0,0,"Grand Magister Rommath - Data Set - Cast spell 70540 at player"),
(37763,0,2,0,38,0,100,0,3,3,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,"Grand Magister Rommath - Data Set - Say Line 4"),
(37763,0,3,0,38,0,100,0,8,8,0,0,53,0,3776300,0,0,0,0,1,0,0,0,0,0,0,0,"Grand Magister Rommath - Data Set - Start WP'"),
(37763,0,4,0,38,0,100,0,2,2,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lor'themar Theron - Data Set - Say Line 0'"),
(37763,0,5,0,38,0,100,0,8,2,0,0,1,5,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lor'themar Theron - Data Set - Say Line 5'"),
(37763,0,6,0,38,0,100,0,8,3,0,0,1,8,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lor'themar Theron - Data Set - Say Line 5'"),
(37763,0,7,0,38,0,100,0,8,4,0,0,53,0,3776300,0,0,0,0,1,0,0,0,0,0,0,0,"Lor'themar Theron - Data Set - Say Line 5'"),
(37764,0,0,0,38,0,100,0,1,1,0,0,53,0,37764,0,0,0,0,1,0,0,0,0,0,0,0,"Lor'themar Theron - Data Set - Start WP'"),
(37764,0,2,0,38,0,100,0,3,3,0,0,71,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lor'themar Theron - Data Set - Set Equipment"),
(37764,0,3,5,38,0,100,0,4,4,0,0,11,70493,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lor'themar Theron - Data Set - Cast spell 70493"),
(37764,0,4,0,38,0,100,0,6,6,900000,900000,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lor'themar Theron - Data Set - Say Line 0'"),
(37764,0,5,0,61,0,100,0,4,4,0,0,80,3776400,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lor'themar Theron - Data Set - Run Script"),
(37764,0,6,0,40,0,100,0,4,37764,4,0,69,0,0,0,0,0,0,19,37745,0,0,0,0,0,0,"Lor'themar Theron - On WP4 Reached - Move to Quel delar"),
(37764,0,7,0,38,0,100,0,9,9,0,0,53,0,3776400,0,0,0,0,1,0,0,0,0,0,0,0,"Lor'themar Theron - Data Set - Start WP"),
(37764,0,8,0,38,0,100,0,8,1,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lor'themar Theron - Data Set  3- Say Line"),
(37764,0,9,0,38,0,100,0,8,4,0,0,53,0,3776400,0,0,0,0,1,0,0,0,0,0,0,0,"Lor'themar Theron - Data Set - Say Line 5'"),
(37781,0,0,1,38,0,100,0,2,2,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunwell Honor Guard - Data Set - Turn Run On'"),
(37781,0,1,0,61,0,100,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,1650.221, 606.6376, 30.59028,0,"Sunwell Honor Guard - Data Set - Move to Position'"),
(-122985,0,2,3,38,0,100,0,3,3,0,0,17,333,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunwell Honor Guard - Data Set - Set Emotestate 333'"),
(-122985,0,3,0,61,0,100,0,0,0,0,0,69,0,0,0,0,0,0,12,1,0,0,-5, -5, 0,0,"Sunwell Honor Guard - Data Set - Follow'"),
(-122985,0,4,0,38,0,100,0,4,4,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunwell Honor Guard - Data Set - Set Emotestate 333'"),
(-122985,0,5,0,38,0,100,0,5,5,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunwell Honor Guard - Data Set - Play Emote One Shot Salute'"),
(-122985,0,6,0,38,0,100,0,6,6,0,0,24,0,2,0,0,0,0,1,0,0,0,0, 0, 0,0,"Sunwell Honor Guard - Data Set - Stop Follow'"),
(-122985,0,7,0,38,0,100,0,7,7,0,0,66,0,2,0,0,0,0,12,1,0,0,0, 0, 0,0,"Sunwell Honor Guard - Data Set - Face Player'"),
(-122777,0,2,3,38,0,100,0,3,3,0,0,17,333,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunwell Honor Guard - Data Set - Set Emotestate 333'"),
(-122777,0,3,0,61,0,100,0,0,0,0,0,69,0,0,0,0,0,0,12,1,0,0,-5, 0, 0,0,"Sunwell Honor Guard - Data Set - Follow'"),
(-122777,0,4,0,38,0,100,0,4,4,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunwell Honor Guard - Data Set - Set Emotestate 333'"),
(-122777,0,5,0,38,0,100,0,5,5,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunwell Honor Guard - Data Set - Play Emote One Shot Salute'"),
(-122777,0,6,0,38,0,100,0,6,6,0,0,24,0,0,0,0,0,0,1,0,0,0,0, 0, 0,0,"Sunwell Honor Guard - Data Set - Stop Follow'"),
(-122777,0,7,0,38,0,100,0,7,7,0,0,66,0,2,0,0,0,0,12,1,0,0,0, 0, 0,0,"Sunwell Honor Guard - Data Set - Face Player'"),
(-122953,0,2,3,38,0,100,0,3,3,0,0,17,333,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunwell Honor Guard - Data Set - Set Emotestate 333'"),
(-122953,0,3,0,61,0,100,0,0,0,0,0,69,0,0,0,0,0,0,12,1,0,0,0, -5, 0,0,"Sunwell Honor Guard - Data Set - Follow'"),
(-122953,0,4,0,38,0,100,0,4,4,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunwell Honor Guard - Data Set - Set Emotestate 333'"),
(-122953,0,5,0,38,0,100,0,5,5,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunwell Honor Guard - Data Set - Play Emote One Shot Salute'"),
(-122953,0,6,0,38,0,100,0,6,6,0,0,24,0,0,0,0,0,0,12,1,0,0,-5, -5, 0,0,"Sunwell Honor Guard - Data Set - Stop Follow'"),
(-122953,0,7,0,38,0,100,0,7,7,0,0,66,0,2,0,0,0,0,12,1,0,0,0, 0, 0,0,"Sunwell Honor Guard - Data Set - Face Player'"),
(37765,0,0,0,38,0,100,0,1,1,0,0,53,0,37765,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Auric Sunchaser - Data Set - Start WP'"),
(37765,0,1,0,38,0,100,0,8,8,0,0,80,3776500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Auric Sunchaser - Data Set - Run Script"),
(37765,0,2,0,38,0,100,0,8,4,0,0,53,0,3776500,0,0,0,0,1,0,0,0,0,0,0,0,"Lor'themar Theron - Data Set - Say Line 5'"),
(38056,0,0,0,38,0,100,1,1,1,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Chamberlain Galiros - Data Set - Say Line 0 (No Repeat'"),
(37745,0,0,1,38,0,100,0,2,2,0,0,64,1,0,0,0,0,0,23,0,0,0,0,0,0,0,"Quel'Delar - On Just Summoned - Store Target'"),
(37745,0,1,2,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,37763,0,0,0,0,0,0,"Quel'Delar - On Just Summoned - Send Target'"),
(37745,0,2,3,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,37764,0,0,0,0,0,0,"Quel'Delar - On Just Summoned - Send Target'"),
(37745,0,3,4,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,37765,0,0,0,0,0,0,"Quel'Delar - On Just Summoned - Send Target'"),
(37745,0,4,0,61,0,100,0,0,0,0,0,80,3774500,2,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'Delar - On Just Summoned - Run Script'"),
(37745,0,5,6,38,0,100,0,1,1,0,0,64,1,0,0,0,0,0,23,0,0,0,0,0,0,0,"Quel'Delar - On Just Summoned - Store Target'"),
(37745,0,6,7,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,37763,0,0,0,0,0,0,"Quel'Delar - On Just Summoned - Send Target'"),
(37745,0,7,8,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,37764,0,0,0,0,0,0,"Quel'Delar - On Just Summoned - Send Target'"),
(37745,0,8,9,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,37765,0,0,0,0,0,0,"Quel'Delar - On Just Summoned - Send Target'"),
(37745,0,9,10,61,0,100,0,0,0,0,0,80,3774501,2,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'Delar - On Just Summoned - Run Script'"),
(37745,0,10,0,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,9,37781,0,200,0,0,0,0,"Quel Delar On spawn - Send Target"), -- 23:17:10.900
(37746,0,1,0,38,0,100,0,2,2,0,0,11,70466,0,0,0,0,0,19,37745,0,0,0,0,0,0,"Sunwell Caster Bunny - On Data Set 2 2 - Cast Sunwell Light Ray'"),
(3774500,9,0,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 1 1 to Sunwell Caster Bunny"), -- 23:16:34.326
(3774500,9,1,0,0,0,100,0,2000,2000,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:36.338
(3774500,9,2,0,0,0,100,0,1000,1000,0,0,45,1,1,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:37.744
(3774500,9,3,0,0,0,100,0,1000,1000,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:38.304
(3774500,9,4,0,0,0,100,0,1000,1000,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:40.316 
(3774500,9,5,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:40.722 
(3774500,9,6,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:41.533 
(3774500,9,7,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:42.328 
(3774500,9,8,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,37763,0,0,0,0,0,0,"Quel'Delar - Script - Set Data 1 1 to Grand Magister Rommath"), -- 23:16:42.328 
(3774500,9,9,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,37764,0,0,0,0,0,0,"Quel'Delar - Script - Set Data 1 1 to Lor'themar Theron"), -- 23:16:42.328 
(3774500,9,10,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,37765,0,0,0,0,0,0,"Quel'Delar - Script - Set Data 1 1 to Captain Auric Sunchaser"), -- 23:16:42.328 
(3774500,9,11,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:42.734 
(3774500,9,12,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:43.514 
(3774500,9,13,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:44.325 
(3774500,9,14,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:44.731 
(3774500,9,15,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:45.526 
(3774500,9,16,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:46.338 
(3774500,9,17,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:46.743 
(3774500,9,18,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:47.523 
(3774500,9,19,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:48.334 
(3774500,9,20,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:48.740 
(3774500,9,21,0,0,0,100,0,400,400,0,0,1,0,0,0,0,0,0,19,37763,0,0,0,0,0,0,"Quel'Delar - Script - Say Line 0"), -- 23:16:49.177 
(3774500,9,22,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:49.536 
(3774500,9,23,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:50.331 
(3774500,9,24,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:50.721 
(3774500,9,25,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:51.548 
(3774500,9,26,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:52.344 
(3774500,9,27,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:52.749 
(3774500,9,28,0,0,0,100,0,500,500,0,0,45,2,2,0,0,0,0,19,37764,0,0,0,0,0,0,"Quel'Delar - Script - Say Line 0"), -- 23:16:53.264 
(3774500,9,29,0,0,0,100,0,300,300,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:53.545 
(3774500,9,30,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:54.325 
(3774500,9,31,0,0,0,100,0,1200,1200,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:55.526 
(3774500,9,32,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:54.731 
(3774500,9,33,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:56.322 
(3774500,9,34,0,0,0,100,0,1200,1200,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:57.523 
(3774500,9,35,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:58.319 
(3774500,9,36,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:58.740 
(3774500,9,37,0,0,0,100,0,0,0,0,0,45,3,3,0,0,0,0,19,37764,0,0,0,0,0,0,"Quel'Delar - Script - Virtual Item Slot 0 (0)"), -- 23:16:58.740 
(3774500,9,38,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:59.535 
(3774500,9,39,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:00.315 
(3774500,9,40,0,0,0,100,0,200,200,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:00.581  
(3774500,9,41,0,0,0,100,0,1000,1000,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:01.517  
(3774500,9,42,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:02.312  
(3774500,9,43,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:02.718  
(3774500,9,44,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:03.513  
(3774500,9,45,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:04.325   
(3774500,9,46,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:04.715  
(3774500,9,47,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:05.510  
(3774500,9,48,0,0,0,100,0,400,400,0,0,45,4,4,0,0,0,0,19,37764,0,0,0,0,0,0,"Quel'Delar - Script - Cast Spell 70493 (Self)"), -- 23:17:05.900 
(3774500,9,49,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:06.321  
(3774500,9,50,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:06.727   
(3774500,9,51,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:07.523   
(3774500,9,52,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:08.318   
(3774500,9,53,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:08.739  
(3774500,9,54,0,0,0,100,0,100,100,0,0,1,0,9,0,0,0,0,10,122983,37781,0,0,0,0,0,"Quel'Delar - Script - Say Line 0"), -- text 23:17:08.864  
(3774500,9,55,0,0,0,100,0,700,700,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:09.535  
(3774500,9,56,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:10.315  
(3774500,9,57,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:10.721  
(3774500,9,58,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:11.516  
(3774500,9,59,0,0,0,100,0,500,500,0,0,45,2,2,0,0,0,0,19,37763,0,0,0,0,0,0,"Quel'Delar - Script - Cast 70540 at player"), -- 23:17:12.078 
(3774500,9,60,0,0,0,100,0,15,15,0,0,1,1,0,0,0,0,0,19,37763,0,0,0,0,0,0,"Quel'Delar - Script - Say Line 1"), -- 23:17:12.093 
(3774500,9,61,0,0,0,100,0,385,385,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:12.312  
(3774500,9,62,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:12.733  
(3774500,9,63,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:13.544  
(3774500,9,64,0,0,0,100,0,600,600,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:14.121  
(3774500,9,65,0,0,0,100,0,600,600,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:14.761
(3774500,9,66,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:15.338  
(3774500,9,67,0,0,0,100,0,800,800,0,0,1,1,0,0,0,0,0,19,37781,0,0,0,0,0,0,"Quel'Delar - Script - Say Line 1"), -- 23:17:16.103  
(3774500,9,68,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:16.118  
(3774500,9,69,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:16.539  
(3774500,9,70,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:17.335  
(3774500,9,71,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:18.146  
(3774500,9,72,0,0,0,100,0,400,400,0,0,1,0,0,0,0,0,0,19,37765,0,0,0,0,0,0,"Quel'Delar - Script - Say Line 0"), -- 23:17:18.536  
(3774500,9,73,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:18.536  
(3774500,9,74,0,0,0,100,0,1000,1000,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:19.535  
(3774500,9,75,0,0,0,100,0,600,600,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:20.127
(3774500,9,76,0,0,0,100,0,600,600,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:20.736
(3774500,9,77,0,0,0,100,0,600,600,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:21.344
(3774500,9,78,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:22.124  
(3774500,9,79,0,0,0,100,0,600,600,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:22.717
(3774500,9,80,0,0,0,100,0,600,600,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:23.341
(3774500,9,81,0,0,0,100,0,1000,1000,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:24.308  
(3774500,9,82,0,0,0,100,0,200,200,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:24.542  
(3774500,9,83,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,19,37765,0,0,0,0,0,0,"Quel'Delar - Script - Say Line 1"), -- 23:17:24.542  
(3774500,9,84,0,0,0,100,0,1000,1000,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:25.525  
(3774500,9,85,0,0,0,100,0,600,600,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:26.149
(3774500,9,86,0,0,0,100,0,600,600,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:26.742
(3774500,9,87,0,0,0,100,0,600,600,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:27.366
(3774500,9,88,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:28.162  
(3774500,9,89,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:28.567  
(3774500,9,90,0,0,0,100,0,1000,1000,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:29.503  
(3774500,9,91,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:30.330  
(3774500,9,92,0,0,0,100,0,200,200,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:30.580  
(3774500,9,93,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:31.391  
(3774500,9,94,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:32.124  
(3774500,9,95,0,0,0,100,0,600,600,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:32.732
(3774500,9,96,0,0,0,100,0,600,600,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:33.388
(3774500,9,97,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:34.183  
(3774500,9,98,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:34.589  
(3774500,9,99,0,0,0,100,0,500,500,0,0,1,2,0,0,0,0,0,19,37763,0,0,0,0,0,0,"Quel'Delar - Script - Say Line 2"), -- 23:17:35.041 
(3774500,9,100,0,0,0,100,0,500,500,0,0,1,3,0,0,0,0,0,19,37763,0,0,0,0,0,0,"Quel'Delar - Script - Say Line 3"), -- 23:17:35.041 
(3774500,9,101,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:35.416  
(3774500,9,102,0,0,0,100,0,900,900,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:36.336  
(3774500,9,103,0,0,0,100,0,300,300,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:36.648  
(3774500,9,104,0,0,0,100,0,900,900,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:37.537   
(3774500,9,105,0,0,0,100,0,700,700,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:38.255   
(3774500,9,106,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:38.629  
(3774500,9,107,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:39.440  
(3774500,9,108,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:40.236  
(3774500,9,109,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:40.626  
(3774500,9,110,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:41.437  
(3774500,9,111,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:42.248  
(3774500,9,112,0,0,0,100,0,500,500,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:42.732  
(3774500,9,113,0,0,0,100,0,900,900,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:43.403  
(3774500,9,114,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:44.245  
(3774500,9,115,0,0,0,100,0,500,500,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:44.729  
(3774500,9,116,0,0,0,100,0,900,900,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:45.462  
(3774500,9,117,0,0,0,100,0,400,400,0,0,45,3,3,0,0,0,0,19,37763,0,0,0,0,0,0,"Quel'Delar - Script - Say Line 4"), -- 23:17:45.883 
(3774500,9,118,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:46.258  
(3774500,9,119,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:46.663  
(3774500,9,120,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:47.459  
(3774500,9,121,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:48.270  
(3774500,9,122,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:48.676  
(3774500,9,123,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:49.487  
(3774500,9,124,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:50.282  
(3774500,9,125,0,0,0,100,0,500,500,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:50.735  
(3774500,9,126,0,0,0,100,0,900,900,0,0,50,201794,900,0,0,0,0,1,0,0,0,0,0,0,0.0,"Quel'Delar - Script - Spawn GO"), -- 23:17:51.484  
(3774500,9,127,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:51.484  
(3774500,9,128,0,0,0,100,0,400,400,0,0,45,8,8,0,0,0,0,19,37763,0,0,0,0,0,0,"Quel'Delar - Script - Set Data 8 8"),  
(3774500,9,129,0,0,0,100,0,400,400,0,0,45,8,8,0,0,0,0,19,37764,0,0,0,0,0,0,"Quel'Delar - Script - Set Data 8 8"),  
(3774500,9,130,0,0,0,100,0,400,400,0,0,45,8,8,0,0,0,0,19,37765,0,0,0,0,0,0,"Quel'Delar - Script - Set Data 8 8"),  
(3774500,9,131,0,0,0,100,0,800,800,0,0,44,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'Delar - Script - Despawn"), -- 23:17:52.279  
(3774501,9,0,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 1 1 to Sunwell Caster Bunny"), -- 23:16:34.326
(3774501,9,1,0,0,0,100,0,2000,2000,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:36.338
(3774501,9,2,0,0,0,100,0,1000,1000,0,0,45,1,1,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:37.744
(3774501,9,3,0,0,0,100,0,1000,1000,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:38.304
(3774501,9,4,0,0,0,100,0,1000,1000,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:40.316 
(3774501,9,5,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:40.722 
(3774501,9,6,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:41.533 
(3774501,9,7,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:42.328 
(3774501,9,8,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,37763,0,0,0,0,0,0,"Quel'Delar - Script - Set Data 1 1 to Grand Magister Rommath"), -- 23:16:42.328 
(3774501,9,9,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,37764,0,0,0,0,0,0,"Quel'Delar - Script - Set Data 1 1 to Lor'themar Theron"), -- 23:16:42.328 
(3774501,9,10,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,37765,0,0,0,0,0,0,"Quel'Delar - Script - Set Data 1 1 to Captain Auric Sunchaser"), -- 23:16:42.328 
(3774501,9,11,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:42.734 
(3774501,9,12,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:43.514 
(3774501,9,13,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:44.325 
(3774501,9,14,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:44.731 
(3774501,9,15,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:45.526 
(3774501,9,16,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:46.338 
(3774501,9,17,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:46.743 
(3774501,9,18,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:47.523 
(3774501,9,19,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:48.334 
(3774501,9,20,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:48.740 
(3774501,9,21,0,0,0,100,0,400,400,0,0,1,2,0,0,0,0,0,19,37781,0,0,0,0,0,0,"Quel'Delar - Script - Say Line 2"), -- 23:16:49.177 
(3774501,9,22,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:49.536 
(3774501,9,23,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:50.331 
(3774501,9,24,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:50.721 
(3774501,9,25,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:51.548 
(3774501,9,26,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:52.344 
(3774501,9,27,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:52.749 
(3774501,9,28,0,0,0,100,0,500,500,0,0,1,0,0,0,0,0,0,19,37764,0,0,0,0,0,0,"Quel'Delar - Script - Say Line 0"), -- 23:16:53.264 
(3774501,9,29,0,0,0,100,0,300,300,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:53.545 
(3774501,9,30,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:54.325 
(3774501,9,31,0,0,0,100,0,1200,1200,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:55.526 
(3774501,9,32,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:54.731 
(3774501,9,33,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:56.322 
(3774501,9,34,0,0,0,100,0,1200,1200,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:57.523 
(3774501,9,35,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:58.319 
(3774501,9,36,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:58.740 
(3774501,9,37,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:16:59.535 
(3774501,9,38,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:00.315 
(3774501,9,39,0,0,0,100,0,200,200,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:00.581  
(3774501,9,40,0,0,0,100,0,1000,1000,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:01.517  
(3774501,9,41,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:02.312  
(3774501,9,42,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:02.718  
(3774501,9,43,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:03.513  
(3774501,9,44,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:04.325   
(3774501,9,45,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:04.715  
(3774501,9,46,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:05.510  
(3774501,9,47,0,0,0,100,0,400,400,0,0,1,0,0,0,0,0,0,19,37763,0,0,0,0,0,0,"Quel'Delar - Script - Say Line 0"), -- 23:17:05.900 
(3774501,9,48,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:06.321  
(3774501,9,49,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:06.727   
(3774501,9,50,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:07.523   
(3774501,9,51,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:08.318   
(3774501,9,52,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:08.739  
(3774501,9,53,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:09.535  
(3774501,9,54,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:10.315  
(3774501,9,55,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:10.721  
(3774501,9,56,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:11.516  
(3774501,9,57,0,0,0,100,0,515,515,0,0,1,2,0,0,0,0,0,19,37764,0,0,0,0,0,0,"Quel'Delar - Script - Say Line 2"), -- 23:17:12.093 
(3774501,9,58,0,0,0,100,0,385,385,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:12.312  
(3774501,9,59,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:12.733  
(3774501,9,60,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:13.544  
(3774501,9,61,0,0,0,100,0,600,600,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:14.121  
(3774501,9,62,0,0,0,100,0,600,600,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:14.761
(3774501,9,63,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:15.338  
(3774501,9,64,0,0,0,100,0,800,800,0,0,45,8,1,0,0,0,0,19,37764,0,0,0,0,0,0,"Quel'Delar - Script - Say Line 1"), -- 23:17:16.103  
(3774501,9,65,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:16.118  
(3774501,9,66,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:16.539  
(3774501,9,67,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:17.335  
(3774501,9,68,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:18.146  
(3774501,9,69,0,0,0,100,0,400,400,0,0,45,8,2,0,0,0,0,19,37763,0,0,0,0,0,0,"Quel'Delar - Script - Say Line 0"), -- 23:17:18.536  
(3774501,9,70,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:18.536  
(3774501,9,71,0,0,0,100,0,1000,1000,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:19.535  
(3774501,9,72,0,0,0,100,0,600,600,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:20.127
(3774501,9,73,0,0,0,100,0,600,600,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:20.736
(3774501,9,74,0,0,0,100,0,600,600,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:21.344
(3774501,9,75,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:22.124  
(3774501,9,76,0,0,0,100,0,600,600,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:22.717
(3774501,9,77,0,0,0,100,0,600,600,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:23.341
(3774501,9,78,0,0,0,100,0,1000,1000,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:24.308  
(3774501,9,79,0,0,0,100,0,200,200,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:24.542  
(3774501,9,80,0,0,0,100,0,1000,1000,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:25.525  
(3774501,9,81,0,0,0,100,0,600,600,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:26.149
(3774501,9,82,0,0,0,100,0,600,600,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:26.742
(3774501,9,83,0,0,0,100,0,600,600,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:27.366
(3774501,9,84,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:28.162  
(3774501,9,85,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:28.567  
(3774501,9,86,0,0,0,100,0,1000,1000,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:29.503  
(3774501,9,87,0,0,0,100,0,0,0,0,0,1,6,0,0,0,0,0,19,37763,0,0,0,0,0,0,"Quel'Delar - Script - Say Line 6"), -- 23:17:24.542  
(3774501,9,88,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:30.330  
(3774501,9,89,0,0,0,100,0,200,200,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:30.580  
(3774501,9,90,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:31.391  
(3774501,9,91,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:32.124  
(3774501,9,92,0,0,0,100,0,600,600,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:32.732
(3774501,9,93,0,0,0,100,0,600,600,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:33.388
(3774501,9,94,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:34.183  
(3774501,9,95,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:34.589  
(3774501,9,96,0,0,0,100,0,500,500,0,0,1,7,0,0,0,0,0,19,37763,0,0,0,0,0,0,"Quel'Delar - Script - Say Line 3"), -- 23:17:35.041 
(3774501,9,97,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:35.416  
(3774501,9,98,0,0,0,100,0,900,900,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:36.336  
(3774501,9,99,0,0,0,100,0,300,300,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:36.648  
(3774501,9,100,0,0,0,100,0,900,900,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:37.537   
(3774501,9,101,0,0,0,100,0,700,700,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:38.255   
(3774501,9,102,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:38.629  
(3774501,9,103,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:39.440  
(3774501,9,104,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,19,37765,0,0,0,0,0,0,"Quel'Delar - Script - Say Line 3"), -- 23:17:39.440  
(3774501,9,105,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:40.236  
(3774501,9,106,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:40.626  
(3774501,9,107,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:41.437  
(3774501,9,108,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:42.248  
(3774501,9,109,0,0,0,100,0,500,500,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:42.732  
(3774501,9,110,0,0,0,100,0,900,900,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:43.403  
(3774501,9,111,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:44.245  
(3774501,9,112,0,0,0,100,0,500,500,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:44.729  
(3774501,9,113,0,0,0,100,0,900,900,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:45.462  
(3774501,9,114,0,0,0,100,0,400,400,0,0,1,4,0,0,0,0,0,19,37765,0,0,0,0,0,0,"Quel'Delar - Script - Say Line 4"), -- 23:17:45.883 
(3774501,9,115,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:46.258  
(3774501,9,116,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:46.663  
(3774501,9,117,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:47.459  
(3774501,9,118,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:48.270  
(3774501,9,119,0,0,0,100,0,400,400,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:48.676  
(3774501,9,120,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:49.487  
(3774501,9,121,0,0,0,100,0,800,800,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:50.282  
(3774501,9,122,0,0,0,100,0,500,500,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:50.735 
(3774501,9,123,0,0,0,100,0,0,0,0,0,45,8,3,0,0,0,0,19,37763,0,0,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:45.462  
(3774501,9,124,0,0,0,100,0,900,900,0,0,50,201794,900,0,0,0,0,1,0,0,0,0,0,0,0.0,"Quel'Delar - Script - Spawn GO"), -- 23:17:51.484  
(3774501,9,125,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,9,37746,0,200,0,0,0,0,"Quel'Delar - Script - Set Data 2 2 to Sunwell Caster Bunny"), -- 23:17:51.484  
(3774501,9,126,0,0,0,100,0,400,400,0,0,45,8,4,0,0,0,0,19,37763,0,0,0,0,0,0,"Quel'Delar - Script - Set Data 8 8"),  
(3774501,9,127,0,0,0,100,0,0,0,0,0,45,8,4,0,0,0,0,19,37764,0,0,0,0,0,0,"Quel'Delar - Script - Set Data 8 8"),  
(3774501,9,128,0,0,0,100,0,0,0,0,0,45,8,4,0,0,0,0,19,37765,0,0,0,0,0,0,"Quel'Delar - Script - Set Data 8 8"),  
(3774501,9,129,0,0,0,100,0,800,800,0,0,44,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'Delar - Script - Despawn"), -- 23:17:52.279  
(3776400,9,0,0,0,0,100,0,0,0,0,0,100,1,0,0,0,0,0,9,37781,0,200,0,0,0,0,"Lor'themar Theron - Script - Send Target"), -- 23:17:10.900
(3776400,9,1,0,0,0,100,0,5000,5000,0,0,45,2,2,0,0,0,0,10,122983,37781,0,0,0,0,0,"Lor'themar Theron - Script - Set Data"), -- 23:17:10.900
(3776400,9,2,0,0,0,100,0,0,0,0,0,45,3,3,0,0,0,0,10,122985,37781,0,0,0,0,0,"Lor'themar Theron - Script - Set Data"),
(3776400,9,3,0,0,0,100,0,0,0,0,0,45,3,3,0,0,0,0,10,122777,37781,0,0,0,0,0,"Lor'themar Theron - Script - Set Data"),
(3776400,9,4,0,0,0,100,0,0,0,0,0,45,3,3,0,0,0,0,10,122953,37781,0,0,0,0,0,"Lor'themar Theron - Script - Set Data"),
(3776400,9,5,0,0,0,100,0,0,5000,0,0,45,7,7,0,0,0,0,9,37781,0,200,0,0,0,0,"Lor'themar Theron - Script - Set Data"),
(3776400,9,6,0,0,0,100,0,0,5000,0,0,45,7,7,0,0,0,0,9,37781,0,200,0,0,0,0,"Lor'themar Theron - Script - Set Data"),
(3776400,9,7,0,0,0,100,0,20000,20000,0,0,45,4,4,0,0,0,0,10,122985,37781,0,0,0,0,0,"Lor'themar Theron - Script - Set Data"), -- 23:17:40.236
(3776400,9,8,0,0,0,100,0,0,0,0,0,45,4,4,0,0,0,0,10,122777,37781,0,0,0,0,0,"Lor'themar Theron - Script - Set Data"),
(3776400,9,9,0,0,0,100,0,0,0,0,0,45,4,4,0,0,0,0,10,122953,37781,0,0,0,0,0,"Lor'themar Theron - Script - Set Data"),
(3776400,9,10,0,0,0,100,0,1200,1200,0,0,45,5,5,0,0,0,0,10,122985,37781,0,0,0,0,0,"Lor'themar Theron - Script - Set Data"), -- 23:17:41.437
(3776400,9,11,0,0,0,100,0,0,0,0,0,45,5,5,0,0,0,0,10,122777,37781,0,0,0,0,0,"Lor'themar Theron - Script - Set Data"),
(3776400,9,12,0,0,0,100,0,0,0,0,0,45,5,5,0,0,0,0,10,122953,37781,0,0,0,0,0,"Lor'themar Theron - Script - Set Data"),
(3776400,9,13,0,0,0,100,0,2400,2400,0,0,45,6,6,0,0,0,0,10,122985,37781,0,0,0,0,0,"Lor'themar Theron - Script - Set Data"), -- 23:17:43.840
(3776400,9,14,0,0,0,100,0,0,0,0,0,45,6,6,0,0,0,0,10,122777,37781,0,0,0,0,0,"Lor'themar Theron - Script - Set Data"),
(3776400,9,15,0,0,0,100,0,0,0,0,0,45,6,6,0,0,0,0,10,122953,37781,0,0,0,0,0,"Lor'themar Theron - Script - Set Data"),
(3776500,9,0,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.026548,"Lor themar Theron - Script - Set Orientation"), -- 23:17:55.696  
(3776500,9,1,0,0,0,100,0,0,0,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lor themar Theron - Script - Play Emote"), -- 23:17:55.696  
(3776500,9,2,0,0,0,100,0,200,200,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,"Lor themar Theron - Script - Say Line 2"), -- 23:17:55.899  
(3776500,9,3,0,0,0,100,0,3500,3500,0,0,53,0,3776500,0,0,0,0,1,0,0,0,0,0,0,0,"Lor themar Theron - Script - Start WP"), -- 23:17:59.533  
(3776500,9,4,0,0,0,100,0,3000,3000,0,0,45,9,9,0,0,0,0,19,37763,0,0,0,0,0,0,"Lor themar Theron - Script - Despawn"),   
(3776500,9,5,0,0,0,100,0,0,0,0,0,45,9,9,0,0,0,0,19,37764,0,0,0,0,0,0,"Lor themar Theron - Script - Despawn");   

DELETE FROM `waypoints` WHERE `entry`IN(37763,3776300,37764,3776400,37765,3776500);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `orientation`, `point_comment`) VALUES 
(37763, 1, 1673.819, 625.1953, 28.09187, 0, 'Grand Magister Rommath'),
(37763, 2, 1673.958, 623.1528, 28.05021, 0, 'Grand Magister Rommath'),
(37763, 3, 1679.743, 619.6858, 28.2967, 0, 'Grand Magister Rommath'),
(3776300, 1, 1671.679, 631.2379, 28.05021, 3.996804, 'Grand Magister Rommath (Path 2)'),
(37764, 1, 1666.816, 627.8906, 28.09187, 0, 'Lor themar Theron'),
(37764, 2, 1668, 624.0313, 28.05021, 0, 'Lor themar Theron'),
(37764, 3, 1671.337, 618.75, 28.05021, 0, 'Lor themar Theron'),
(37764, 4, 1675.3, 616.118, 28.05021, 0, 'Lor themar Theron'),
(3776400, 1, 1665.13, 632.75, 28.1335, 5.02655, 'Lor themar Theron (Path 2)'),
(37765, 1, 1698.027, 604.7214, 28.15574, 0, 'Captain Auric Sunchaser'),
(37765, 2, 1695.984, 604.6389, 28.32832, 0, 'Captain Auric Sunchaser'),
(37765, 3, 1692.92, 604.7227, 28.02385, 0, 'Captain Auric Sunchaser'),
(37765, 4, 1690.852, 604.7344, 28.11132, 0, 'Captain Auric Sunchaser'),
(37765, 5, 1687.391, 608.5347, 28.52988, 1.553343, 'Captain Auric Sunchaser'),
(3776500, 1, 1700.569, 604.8038, 28.39968, 0, 'Captain Auric Sunchaser (Path 2)');


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`IN(14,15) AND `SourceGroup`=10963;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 10963, 15239, 0, 0, 9, 0, 24553, 0, 0, 1, 0, 0, '', 'Warden of the Sunwell display different gossip if player is not on quest'),
(14, 10963, 15239, 0, 0, 9, 0, 24564, 0, 0, 1, 0, 0, '', 'Warden of the Sunwell display different gossip if player is not on quest'),
(14, 10963, 15239, 0, 0, 9, 0, 24594, 0, 0, 1, 0, 0, '', 'Warden of the Sunwell display different gossip if player is not on quest'),
(14, 10963, 15239, 0, 0, 9, 0, 24595, 0, 0, 1, 0, 0, '', 'Warden of the Sunwell display different gossip if player is not on quest'),
(14, 10963, 15239, 0, 0, 9, 0, 24596, 0, 0, 1, 0, 0, '', 'Warden of the Sunwell display different gossip if player is not on quest'),
(14, 10963, 15239, 0, 0, 9, 0, 24598, 0, 0, 1, 0, 0, '', 'Warden of the Sunwell display different gossip if player is not on quest'),
(14, 10963, 15240, 0, 0, 9, 0, 24553, 0, 0, 0, 0, 0, '', 'Warden of the Sunwell display different gossip if player is on quest'),
(14, 10963, 15240, 0, 1, 9, 0, 24564, 0, 0, 0, 0, 0, '', 'Warden of the Sunwell display different gossip if player is on quest'),
(14, 10963, 15240, 0, 2, 9, 0, 24594, 0, 0, 0, 0, 0, '', 'Warden of the Sunwell display different gossip if player is on quest'),
(14, 10963, 15240, 0, 3, 9, 0, 24595, 0, 0, 0, 0, 0, '', 'Warden of the Sunwell display different gossip if player is on quest'),
(14, 10963, 15240, 0, 4, 9, 0, 24596, 0, 0, 0, 0, 0, '', 'Warden of the Sunwell display different gossip if player is on quest'),
(14, 10963, 15240, 0, 5, 9, 0, 24598, 0, 0, 0, 0, 0, '', 'Warden of the Sunwell display different gossip if player is on quest'),
(15, 10963, 0, 0, 0, 9, 0, 24553, 0, 0, 0, 0, 0, '', 'Warden of the Sunwell display different gossip if player is on quest'),
(15, 10963, 0, 0, 1, 9, 0, 24564, 0, 0, 0, 0, 0, '', 'Warden of the Sunwell display different gossip if player is on quest'),
(15, 10963, 0, 0, 2, 9, 0, 24594, 0, 0, 0, 0, 0, '', 'Warden of the Sunwell display different gossip if player is on quest'),
(15, 10963, 0, 0, 3, 9, 0, 24595, 0, 0, 0, 0, 0, '', 'Warden of the Sunwell display different gossip if player is on quest'),
(15, 10963, 0, 0, 4, 9, 0, 24596, 0, 0, 0, 0, 0, '', 'Warden of the Sunwell display different gossip if player is on quest'),
(15, 10963, 0, 0, 5, 9, 0, 24598, 0, 0, 0, 0, 0, '', 'Warden of the Sunwell display different gossip if player is on quest');

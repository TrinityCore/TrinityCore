UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry` IN(23842,24284);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(23842,24284) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(23844) AND `source_type`=0 AND `id`=0;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(2428400,2428401,2384200) AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23842,0,0,0,38,0,30,0,1,1,0,0,80,2384200,2,0,0,0,0,1,0,0,0,0,0,0,0,'Westguard Defender - On Data Set - Run Script'),
(23842,0,1,0,0,0,100,0,5000,15000,20000,40000,11,48147,0,0,0,0,0,1,0,0,0,0,0,0,0,'Westguard Defender - IC - Cast Crazed'),
(23842,0,2,0,0,0,100,1,500,500,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,'Westguard Defender - IC - Cast Defensive'),
(23842,0,3,0,0,0,100,0,1000,3000,10400,10400,11,3639,0,0,0,0,0,1,0,0,0,0,0,0,0,'Westguard Defender - IC - Cast Improved Blocking'),
(23842,0,4,0,0,0,100,0,2000,5000,10000,21000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,'Westguard Defender - IC - Cast ShieldBash'),
(23842,0,5,0,0,0,100,0,0,5000,1000,6000,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,'Westguard Defender - IC - Cast Shoot'),
(24284,0,0,0,8,0,100,0,43386,0,0,0,80,2428400,2,0,0,0,0,1,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - On Spell Hit (Peppys Special Mix) - Run Script'),
(24284,0,1,2,40,0,100,0,1,24284,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - On Reached WP1 - Say Line 0'),
(24284,0,2,0,61,0,100,0,0,0,0,0,54,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - On Reached WP1 - Pause WP'),
(24284,0,3,4,40,0,100,0,9,24284,0,0,11,43401,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - On Reached WP9 - Cast Cosmetic - Blood Explosion Green - Large'),
(24284,0,4,5,61,0,100,0,0,0,0,0,3,0,1145,0,0,0,0,1,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - On Reached WP9 - Change displayid to 1145'),
(24284,0,5,0,61,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - On Reached WP9 - Set Phase 2'),
(24284,0,6,0,1,2,100,1,4000,4000,0,0,80,2428401,2,0,0,0,0,1,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - OOC (Phase 2) - Run Script'),
(2384200,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,19,24288,0,0,0,0,0,0,'Westguard Defender - Script - Face Target'), -- 19:36:43.046
(2384200,9,1,0,0,0,100,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Westguard Defender - Script - Set Bytes 1'), -- 19:36:43.046
(2384200,9,2,0,0,0,100,0,1000,1000,0,0,11,43391,0,0,0,0,0,1,0,0,0,0,0,0,0,'Westguard Defender - Script - Cast Vomit'), -- 19:36:44.231
(2384200,9,3,0,0,0,100,0,9000,9000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Westguard Defender - Script - Set Bytes 1'), -- 19:36:53.872
(2384200,9,4,0,0,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Westguard Defender - Script - Evade'), 
(2428401,9,0,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,10,99027,23842,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script 2 - Say'), 
(2428401,9,1,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,10,99023,23842,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script 2 - Say'), 
(2428401,9,2,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,10,99012,23842,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script 2 - Say'), 
(2428401,9,3,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,10,99010,23842,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script 2 - Say'), 
(2428401,9,4,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,10,99024,23842,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script 2 - Say'), 
(2428401,9,5,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,10,99026,23842,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script 2 - Say'), 
(2428401,9,6,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,9,23842,0,80,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script 2 - Set Data'), 
(2428401,9,7,0,0,0,100,0,1000,1000,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script 2 - Cast Suicide, No Blood, No Logging'), 
(2428400,9,0,0,0,0,100,0,0,0,0,0,5,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script - Play Emote (OneShotEat)'), -- 19:36:18.195
(2428400,9,1,0,0,0,100,0,0,0,0,0,71,0,0,2200,0,0,0,1,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script - Equip item 2200 to Slot 1'), -- 19:36:18.195
(2428400,9,2,0,0,0,100,0,2800,2800,0,0,11,21862,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script - Cast Radiation'), -- 19:36:20.925
(2428400,9,3,0,0,0,100,0,0,0,0,0,33,24284,0,0,0,0,0,7,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script - Give Quest Credit'),
(2428400,9,4,0,0,0,100,0,0,0,0,0,71,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script - UnEquip item'), -- 19:36:20.925
(2428400,9,5,0,0,0,100,0,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script - Remove Bytes 1'), -- 19:36:20.925
(2428400,9,6,0,0,0,100,0,3200,3200,0,0,4,9110,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script - Play Sound 9110'), -- 19:36:23.421
(2428400,9,7,0,0,0,100,0,0,0,0,0,5,53,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script - Play Emote OneShotBattleRoar'), -- 19:36:23.421
(2428400,9,8,0,0,0,100,0,1200,1200,0,0,53,0,24284,0,0,0,0,1,0,0,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script - Start WP'), -- 19:36:24.622
(2428400,9,9,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,10,99027,23842,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script - Say'), -- 19:36:24.622
(2428400,9,10,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,10,99023,23842,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script - Say'), -- 19:36:24.622
(2428400,9,11,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,10,99012,23842,0,0,0,0,0,'Dragonflayer Vrykul Prisoner - Script - Say'); -- 19:36:24.622


DELETE FROM `waypoints` WHERE `entry`=24284;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(24284, 1, 1366.673, -3179.636, 153.576, 'Dragonflayer Vrykul Prisoner'),
(24284, 2, 1367.06, -3177.925, 153.576, 'Dragonflayer Vrykul Prisoner'),
(24284, 3, 1368.679, -3181.09, 153.576, 'Dragonflayer Vrykul Prisoner'),
(24284, 4, 1367.308, -3179.079, 153.576, 'Dragonflayer Vrykul Prisoner'),
(24284, 5, 1366.374, -3179.791, 153.576, 'Dragonflayer Vrykul Prisoner'),
(24284, 6, 1365.373, -3179.188, 153.576, 'Dragonflayer Vrykul Prisoner'),
(24284, 7, 1365.733, -3179.677, 153.576, 'Dragonflayer Vrykul Prisoner'),
(24284, 8, 1366.468, -3176.728, 153.576, 'Dragonflayer Vrykul Prisoner'),
(24284, 9, 1365.269, -3181.054, 153.576, 'Dragonflayer Vrykul Prisoner');

DELETE FROM `creature_text` WHERE `entry`IN(24284,23842);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(24284, 0, 0, 'The vrykul clutches at his throat as he begins to gag and thrash about.', 16, 0, 100, 53, 0, 0, 23087, 'Dragonflayer Vrykul Prisoner to Player'),
(23842, 0, 0, 'Uh...?', 12, 7, 100, 1, 0, 0, 23103, 'Westguard Defender to Player'),
(23842, 0, 1, 'Interesting.', 12, 7, 100, 1, 0, 0, 23107, 'Westguard Defender to Player'),
(23842, 0, 2, 'Yikes.', 12, 7, 100, 0, 0, 0, 23104, 'Westguard Defender to Player'),
(23842, 0, 3, 'Is he okay?', 12, 7, 100, 0, 0, 0, 23105, 'Westguard Defender to Player'),
(23842, 0, 4, 'Captain''s not gonna like this.', 12, 7, 100, 0, 0, 0, 23106, 'Westguard Defender to Player'),
(23842, 0, 5, 'Whoa.', 12, 7, 100, 0, 0, 0, 23108, 'Westguard Defender to Player'),
(23842, 1, 0, 'I didn''t know they could do that.', 12, 7, 100, 1, 0, 0, 23096, 'Westguard Defender to Player'),
(23842, 1, 1, 'That''s... special.', 12, 7, 100, 1, 0, 0, 23097, 'Westguard Defender to Player'),
(23842, 1, 2, 'Heh, cool!', 12, 7, 100, 1, 0, 0, 23094, 'Westguard Defender to Player'),
(23842, 1, 3, 'That''s the new Forsaken plague?', 12, 7, 100, 1, 0, 0, 23098, 'Westguard Defender to Player'),
(23842, 1, 4, 'What kind of sicko are you?', 12, 7, 100, 1, 0, 0, 23095, 'Westguard Defender to Player'),
(23842, 1, 5, 'Oh, sick!', 12, 7, 100, 1, 0, 0, 23091, 'Westguard Defender to Player'),
(23842, 1, 6, 'I feel ill.', 12, 7, 100, 1, 0, 0, 23093, 'Westguard Defender to Player'),
(23842, 1, 7, 'That did NOT just happen!', 12, 7, 100, 1, 0, 0, 23092, 'Westguard Defender to Player');


-- Fix Quest 27926 "Eastern Hospitality" 

-- Aspiring Starlet SAI
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (47189);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (47189,-266589) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47189,0,0,0,62,0,100,0,12222,0,0,0,0,85,87939,0,0,0,0,0,7,0,0,0,0,0,0,0,"Aspiring Starlet - Gossip Option Select - Self Cast 'Starlet Kill Credit'"),
(47189,0,1,0,1,0,100,0,2000,15000,8000,15000,0,10,6,11,273,274,396,0,1,0,0,0,0,0,0,0,"Aspiring Starlet - OOC - Play random emote OneShotQuestion, OneShotLaugh, OneShotYes, OneShotNo, OneShotTalkNoSheathe"),
(-266589,0,0,0,62,0,100,0,12222,0,0,0,0,85,87939,0,0,0,0,0,7,0,0,0,0,0,0,0,"Aspiring Starlet - Gossip Option Select - Self Cast 'Starlet Kill Credit'");

-- Refined Gentleman SAI
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (47185);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (47185) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47185,0,0,0,62,0,100,0,12215,0,0,0,0,85,87936,0,0,0,0,0,7,0,0,0,0,0,0,0,"Refined Gentleman - Gossip Option Select - Self Cast 'Gentleman Kill Credit'"),
(47185,0,1,0,1,0,100,0,2000,15000,8000,15000,0,5,92,0,0,0,0,0,1,0,0,0,0,0,0,0,"Refined Gentleman - OOC - Play emote OneShotEatNoSheathe");

-- Budding Artist SAI
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (47187);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (47187,-266595) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47187,0,0,0,62,0,100,0,12218,0,0,0,0,85,87938,0,0,0,0,0,7,0,0,0,0,0,0,0,"Budding Artist - Gossip Option Select - Self Cast 'Artist Kill Credit'"),
(47187,0,1,0,1,0,100,0,2000,15000,8000,15000,0,10,6,11,273,274,396,0,1,0,0,0,0,0,0,0,"Budding Artist - OOC - Play random emote OneShotQuestion, OneShotLaugh, OneShotYes, OneShotNo, OneShotTalkNoSheathe"),
(-266595,0,0,0,62,0,100,0,12218,0,0,0,0,85,87938,0,0,0,0,0,7,0,0,0,0,0,0,0,"Budding Artist - Gossip Option Select - Self Cast 'Artist Kill Credit'");

-- Ambassador Laurent SAI
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (47176);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (47176) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47176,0,0,0,62,0,100,0,12210,0,0,0,0,85,87924,0,0,0,0,0,7,0,0,0,0,0,0,0,"Budding6,11,273,274,396 Artist - Gossip Option Select - Self Cast 'Ambassador Kill Credit'");

-- Privileged Socialite SAI
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (47472);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-266582,-266604) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-266582,0,0,0,1,0,100,0,2000,15000,8000,15000,0,10,6,11,273,274,396,0,1,0,0,0,0,0,0,0,"Privileged Socialite - OOC - Play random emote OneShotQuestion, OneShotLaugh, OneShotYes, OneShotNo, OneShotTalkNoSheathe"),
(-266604,0,0,0,1,0,100,0,2000,15000,8000,15000,0,10,6,11,273,274,396,0,1,0,0,0,0,0,0,0,"Privileged Socialite - OOC - Play random emote OneShotQuestion, OneShotLaugh, OneShotYes, OneShotNo, OneShotTalkNoSheathe");

-- Pretentious Businessman SAI
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (47514);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-266579,-266607) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-266579,0,0,0,1,0,100,0,2000,15000,8000,15000,0,10,6,11,273,274,396,0,1,0,0,0,0,0,0,0,"Pretentious Businessman - OOC - Play random emote OneShotQuestion, OneShotLaugh, OneShotYes, OneShotNo, OneShotTalkNoSheathe"),
(-266607,0,0,0,1,0,100,0,2000,15000,8000,15000,0,10,6,11,273,274,396,0,1,0,0,0,0,0,0,0,"Pretentious Businessman - OOC - Play random emote OneShotQuestion, OneShotLaugh, OneShotYes, OneShotNo, OneShotTalkNoSheathe");

-- Prolific Writer SAI
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (47461);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-266580) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-266580,0,0,0,1,0,100,0,2000,15000,8000,15000,0,10,6,11,273,274,396,0,1,0,0,0,0,0,0,0,"Prolific Writer - OOC - Play random emote OneShotQuestion, OneShotLaugh, OneShotYes, OneShotNo, OneShotTalkNoSheathe");

-- Fix Gossip
UPDATE `gossip_menu_option` SET `OptionType`=1, `OptionNpcFlag`=1 WHERE `MenuID` IN (12220,12221,12222); -- Aspiring Starlet
UPDATE `gossip_menu_option` SET `OptionType`=1, `OptionNpcFlag`=1 WHERE `MenuID` IN (12214,12215); -- Refined Gentleman
UPDATE `gossip_menu_option` SET `OptionType`=1, `OptionNpcFlag`=1 WHERE `MenuID` IN (12217,12218); -- Budding Artist
UPDATE `gossip_menu_option` SET `OptionType`=1, `OptionNpcFlag`=1 WHERE `MenuID` IN (12210,12211); --  Ambassador Laurent
UPDATE `creature_template` SET `gossip_menu_id`=12217 WHERE `entry` IN (47187); --  Budding Artist
UPDATE `creature_template` SET `gossip_menu_id`=12211 WHERE `entry` IN (47176); --  Ambassador Laurent

-- Condition for source Gossip menu option condition type Queststate
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (12220,12214,12217,12211) AND `SourceEntry`=0 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 12220, 0, 0, 0, 9, 0, 27926, 0, 0, 0, 0, 0, '', 'Show gossip menu 12220 option id 0 if quest Eastern Hospitality is taken'),
(15, 12214, 0, 0, 0, 9, 0, 27926, 0, 0, 0, 0, 0, '', 'Show gossip menu 12214 option id 0 if quest Eastern Hospitality is taken'),
(15, 12217, 0, 0, 0, 9, 0, 27926, 0, 0, 0, 0, 0, '', 'Show gossip menu 12217 option id 0 if quest Eastern Hospitality is taken'),
(15, 12211, 0, 0, 0, 9, 0, 27926, 0, 0, 0, 0, 0, '', 'Show gossip menu 12211 option id 0 if quest Eastern Hospitality is taken');

-- Condition for source Gossip menu condition type Quest not taken "text 17291 will show after quest is taken"
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=12300 AND `SourceEntry`=17292 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 12300, 17292, 0, 0, 14, 0, 27926, 0, 0, 0, 0, 0, '', 'Show gossip menu 12300 text id 17292 if quest Eastern Hospitality has not been taken.');

-- Misc fixes for general area

-- Fix wait time for Prolific Writer path 
UPDATE `waypoint_data` SET `delay`=4000 WHERE `id`=2666060 AND `point` IN (2,4);
UPDATE `waypoint_data` SET `delay`=4000 WHERE `id`=2665840 AND `point` IN (3,5);
-- Fix movement for Gobbies
UPDATE `creature` SET `spawndist`=10,`MovementType`=1,`position_x`=-10677.148,`position_y`=949.892,`position_z`=25.32065 WHERE `guid`=266568;
-- Pathing for Commander Schnottz Entry: 47159 Fix wait times and order
UPDATE `creature` SET `position_x`=-10676.4,`position_y`=927.597,`position_z`=26.30432,`orientation`=0.1806  WHERE `guid`=250021;
DELETE FROM `waypoint_data` WHERE `id`=2500210;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(2500210,1,-10676.4,927.597,26.30432,0,0,0,0,100,0),
(2500210,2,-10675.04,927.8924,26.33434,0.1047198,4000,0,0,100,0),
(2500210,3,-10682.8,926.523,26.23682,0,4000,0,0,100,0);

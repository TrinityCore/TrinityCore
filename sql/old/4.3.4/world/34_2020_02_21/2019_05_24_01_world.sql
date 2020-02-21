-- Fix Quest 28002 "Crisis Management"

-- Privileged Socialite SAI
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (47519);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (47519) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47519,0,0,0,1,0,100,0,8000,16000,8000,16000,0,5,18,0,0,0,0,0,1,0,0,0,0,0,0,0,"Privileged Socialite - OOC - Play emote OneShotCry"),
(47519,0,1,0,62,0,100,0,12290,0,0,0,0,85,88617,0,0,0,0,0,7,0,0,0,0,0,0,0,"Privileged Socialite - Gossip Option Select - Self Cast 'Kill Credit'");

-- Fix Privileged Socialite Gossip
UPDATE `creature_template` SET `gossip_menu_id`=12288 WHERE `entry`=47519;
UPDATE `gossip_menu_option` SET `OptionType`=1, `OptionNpcFlag`=1 WHERE `MenuID` IN (12288,12289,12290);
UPDATE `gossip_menu_option` SET `ActionMenuID`=12289 WHERE `MenuID`=12288;
UPDATE `gossip_menu_option` SET `ActionMenuID`=12290 WHERE `MenuID`=12289;
UPDATE `gossip_menu_option` SET `ActionMenuID`=12291 WHERE `MenuID`=12290;

-- Prolific Writer SAI
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (47516);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (47516) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47516,0,0,0,62,0,100,0,12286,0,0,0,0,85,88618,0,0,0,0,0,7,0,0,0,0,0,0,0,"Prolific Writer - Gossip Option Select - Self Cast 'Kill Credit'");

-- Fix Prolific Writer Gossip
UPDATE `creature_template` SET `gossip_menu_id`=12284 WHERE `entry`=47516;
UPDATE `gossip_menu_option` SET `OptionType`=1, `OptionNpcFlag`=1 WHERE `MenuID` IN (12284,12285,12286);
UPDATE `gossip_menu_option` SET `ActionMenuID`=12285 WHERE `MenuID`=12284;
UPDATE `gossip_menu_option` SET `ActionMenuID`=12286 WHERE `MenuID`=12285;
UPDATE `gossip_menu_option` SET `ActionMenuID`=12287 WHERE `MenuID`=12286;

-- Budding Artist SAI
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (47707);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (47707) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47707,0,0,0,62,0,100,0,12318,0,0,0,0,85,88818,0,0,0,0,0,7,0,0,0,0,0,0,0,"Budding Artist - Gossip Option Select - Self Cast 'Artist Kill Credit'");

-- Fix Budding Artist Gossip
UPDATE `creature_template` SET `gossip_menu_id`=12317 WHERE `entry`=47707;
UPDATE `gossip_menu_option` SET `OptionType`=1, `OptionNpcFlag`=1 WHERE `MenuID` IN (12317,12318);
UPDATE `gossip_menu_option` SET `ActionMenuID`=12318 WHERE `MenuID`=12317;
UPDATE `gossip_menu_option` SET `ActionMenuID`=12319 WHERE `MenuID`=12318;

-- Pretentious Businessman SAI
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (47520);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (47520) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47520,0,0,0,62,0,100,0,12315,0,0,0,0,85,88817,0,0,0,0,0,7,0,0,0,0,0,0,0,"Pretentious Businessman - Gossip Option Select - Self Cast 'Artist Kill Credit'");

-- Fix Pretentious Businessman Gossip
UPDATE `creature_template` SET `gossip_menu_id`=12314 WHERE `entry`=47520;
UPDATE `gossip_menu_option` SET `OptionType`=1, `OptionNpcFlag`=1 WHERE `MenuID` IN (12314,12315);
UPDATE `gossip_menu_option` SET `ActionMenuID`=12315 WHERE `MenuID`=12314;
UPDATE `gossip_menu_option` SET `ActionMenuID`=12316 WHERE `MenuID`=12315;

-- Condition for source Gossip menu option condition type Queststate
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (12288,12284,12317,12314) AND `SourceEntry`=0 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 12288, 0, 0, 0, 9, 0, 28002, 0, 0, 0, 0, 0, '', 'Show gossip menu 12288 option id 0 if quest Crisis Management is taken'),
(15, 12284, 0, 0, 0, 9, 0, 28002, 0, 0, 0, 0, 0, '', 'Show gossip menu 12284 option id 0 if quest Crisis Management is taken'),
(15, 12317, 0, 0, 0, 9, 0, 28002, 0, 0, 0, 0, 0, '', 'Show gossip menu 12317 option id 0 if quest Crisis Management is taken'),
(15, 12314, 0, 0, 0, 9, 0, 28002, 0, 0, 0, 0, 0, '', 'Show gossip menu 12314 option id 0 if quest Crisis Management is taken');

-- Add quest reward text
DELETE FROM `quest_offer_reward` WHERE `ID`=28002;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`,`Emote2`,`RewardText`) VALUES
(28002, 396, 0, 'Hmm, still a bit frazzled, are they?$b$bWell, you know what they say. Time heals all wounds.$b$bExcept for those of the ambassador, of course...');

-- Add missing gossip
DELETE FROM `gossip_menu` WHERE `MenuID`=12300 AND `TextID`=17304;
INSERT INTO `gossip_menu` (`MenuID`,`TextID`) VALUES (12300,17304);

-- Condition for source Gossip menu condition type Quest not taken "text 17291 will show after quest is taken"
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=12300 AND `SourceEntry` IN (17292,17291,17304) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 12300, 17292, 0, 0, 14, 0, 27926, 0, 0, 1, 0, 0, '', 'Show gossip menu 12300 text id 17292 if quest Eastern Hospitality has not been taken.'),
(14, 12300, 17291, 0, 0, 14, 0, 27969, 0, 0, 1, 0, 0, '', 'Show gossip menu 12300 text id 17291 if quest Make Yourself Useful has not been taken.'),
(14, 12300, 17304, 0, 0,  8, 0, 27969, 0, 0, 0, 0, 0, '', 'Show gossip menu 12300 text id 17304 if quest Make Yourself Useful has been rewarded.');

-- Fix various Gossip
UPDATE `creature_template` SET `gossip_menu_id`=12313 WHERE `entry`=47703;
UPDATE `creature_template` SET `gossip_menu_id`=12312 WHERE `entry`=47701;
UPDATE `creature_template` SET `gossip_menu_id`=12320, npcflag=1 WHERE `entry`=47708;

-- Crisis Management Quest reward script

-- Schnottz's Bodyguard SAI
SET @ENTRY := 47364;
UPDATE `creature_template` SET `AIName`="SmartAI", `unit_flags`=768 WHERE `entry` IN (@ENTRY);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (473640) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (4736400) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,0,53,1,473640,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz's Bodyguard - Just Summoned - Load Path 473640"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,0,80,4736400,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz's Bodyguard - End Of Path - Run Script 4736400"),
(@ENTRY,0,2,0,58,0,100,0,8,473641,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz's Bodyguard - End Of Path - Despawn"),
(4736400,9,0,0,0,0,100,0,2500,2500,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,"Schnottz's Bodyguard - Script - Say 0"),
(4736400,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.4363323,"Schnottz's Bodyguard - Script - TurnTo"),
(4736400,9,2,0,0,0,100,0,3000,3000,0,0,0,11,88355,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz's Bodyguard - Script - Cast 'Master Ping Ve'vah 01'"),
(4736400,9,3,0,0,0,100,0,3000,3000,0,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,"Schnottz's Bodyguard - Script - Say 1"),
(4736400,9,4,0,0,0,100,0,4000,4000,0,0,0,1,2,0,0,0,0,0,23,0,0,0,0,0,0,0,"Schnottz's Bodyguard - Script - Say 2"),
(4736400,9,5,0,0,0,100,0,5000,5000,0,0,0,11,88364,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz's Bodyguard - Script - Cast 'Master Ping Ve'vah 02'"),
(4736400,9,6,0,0,0,100,0,2000,2000,0,0,0,1,3,0,0,0,0,0,23,0,0,0,0,0,0,0,"Schnottz's Bodyguard - Script - Say 3"),
(4736400,9,7,0,0,0,100,0,3000,3000,0,0,0,53,1,473641,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz's Bodyguard - Script - Load Path 473641");

DELETE FROM `waypoints` WHERE `entry` IN (473640,473641);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(473640,1,-10695.9,927.208,26.64933, 'Schnottz''s Bodyguard'),
(473641,1,-10697.05,924.3,26.76258, 'Schnottz''s Bodyguard'),
(473641,2,-10699.05,915.05,26.76258, 'Schnottz''s Bodyguard'),
(473641,3,-10698.3,914.05,26.76258, 'Schnottz''s Bodyguard'),
(473641,4,-10698.05,913.8,26.76258, 'Schnottz''s Bodyguard'),
(473641,5,-10697.55,910.55,25.51258, 'Schnottz''s Bodyguard'),
(473641,6,-10697.55,908.55,25.26258, 'Schnottz''s Bodyguard'),
(473641,7,-10695.55,900.3,25.26258, 'Schnottz''s Bodyguard'),
(473641,8,-10695.2,897.892,24.87584, 'Schnottz''s Bodyguard');

DELETE FROM `creature_text` WHERE `CreatureID`=47364;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(47364, 0, 0, 'Hide your vives! Hide your children! Zhey''re killink everyvone up in he''ah!', 14, 0, 100, 397, 0, 0, 47558, 'Schnottz''s Bodyguard'),
(47364, 1, 0, 'Zhe shtatues! Zhey''re aliiive!', 14, 0, 100, 397, 0, 0, 47552, 'Schnottz''s Bodyguard'),
(47364, 2, 0, 'Zhey''re runnink around killink everyzhink! Shtompink! Like zhis!!', 14, 0, 100, 388, 0, 0, 47559, 'Schnottz''s Bodyguard'),
(47364, 3, 0, 'Off course, sir! At Vonce!', 14, 0, 100, 113, 0, 0, 47560, 'Schnottz''s Bodyguard');

-- Belloc Brightblade SAI
SET @ENTRY := 47670;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (@ENTRY);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (4767000) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,88358,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Belloc Brightblade - On Spell Hit - Say 0"),
(@ENTRY,0,1,0,8,0,100,0,88365,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Belloc Brightblade - On Spell Hit - Say 1");

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (88355,88364);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(88355,88358,1, 'Master Ping Ve''vah 01 triggers Ping Ve''vah'),
(88364,88365,1, 'Master Ping Ve''vah 02 triggers Ping Ve''vah 02');

DELETE FROM `creature_text` WHERE `CreatureID`=47670;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(47670, 0, 0, 'What are you talking about, goblin?! Speak!!', 14, 0, 100, 5, 0, 0, 47553, 'Belloc Brightblade'),
(47670, 1, 0, 'What are you waiting for? Get out there and stop them!', 14, 0, 100, 5, 0, 0, 47562, 'Belloc Brightblade');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry` IN (88358,88365) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 88358, 0, 0, 31, 0, 3, 47670, 0, 0, 0, 0, '', 'Spell Ping Ve''vah will hit Belloc Brightblade'),
(13, 1, 88365, 0, 0, 31, 0, 3, 47670, 0, 0, 0, 0, '', 'Spell Ping Ve''vah 02 will hit Belloc Brightblade');

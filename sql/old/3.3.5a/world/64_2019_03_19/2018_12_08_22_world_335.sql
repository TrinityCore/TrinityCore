-- Add some missing spawns
SET @GUID  := 93734;  -- Innocuous Townsman
SET @GUID1 := 93762; -- [DND] Stink Bomb Target
SET @GUID2 := 93763; -- [DND] Stink Bomb Target
SET @GUID3 := 93764; -- [DND] Stink Bomb Target
SET @GUID4 := 93913; -- [DND] Stink Bomb Target
SET @GUID5 := 93976; -- [DND] Stink Bomb Target
SET @GUID6 := 94122; -- Traveling Orphan
SET @GUID7 := 94167; -- Traveling Orphan
SET @GUID8 := 94168; -- Traveling Orphan
SET @GUID9 := 94178; -- Traveling Orphan

DELETE FROM `creature` WHERE `guid` IN (@GUID, @GUID1, @GUID2, @GUID3, @GUID4, @GUID5, @GUID6, @GUID7, @GUID8, @GUID9);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID,34565,0,0,0,1,1,0,0,-859.048,-561.08,11.6928,4.65681,600,0,0,42,0,0,0,0,0,"",0),
(@GUID1,34562,0,0,0,1,1,0,0,-863.817,-536.655,8.65531,4.65681,300,0,0,1,0,0,0,0,0,"",0),
(@GUID2,34562,0,0,0,1,1,0,0,-842.176,-531.514,11.5863,4.65681,300,0,0,1,0,0,0,0,0,"",0),
(@GUID3,34562,0,0,0,1,1,0,0,-837.929,-515.898,11.9974,4.65681,300,0,0,1,0,0,0,0,0,"",0),
(@GUID4,34562,0,0,0,1,1,0,0,-821.754,-533.471,14.9848,4.65681,300,0,0,1,0,0,0,0,0,"",0),
(@GUID5,34562,0,0,0,1,1,0,0,-800.886,-527.838,16.4666,4.65681,300,0,0,1,0,0,0,0,0,"",0),
(@GUID6,23971,1,0,0,1,1,0,0,356.938,-4739.97,9.74088,4.39618,300,0,0,42,0,0,0,0,0,"",0),
(@GUID7,23971,1,0,0,1,1,0,0,358.325,-4741.16,9.68917,3.57544,300,0,0,71,0,0,0,0,0,"",0),
(@GUID8,23971,1,0,0,1,1,0,0,355.094,-4740.15,9.83298,5.26763,300,0,0,42,0,0,0,0,0,"",0),
(@GUID9,23971,1,0,0,1,1,0,0,358.327,-4742.84,9.64674,3.05708,300,0,0,55,0,0,0,0,0,"",0);

DELETE FROM `game_event_creature` WHERE `guid` IN (@GUID, @GUID1, @GUID2, @GUID3, @GUID4, @GUID5, @GUID6, @GUID7, @GUID8, @GUID9);
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(12,@GUID),
(12,@GUID1),
(12,@GUID2),
(12,@GUID3),
(12,@GUID4),
(12,@GUID5),
(12,@GUID6),
(12,@GUID7),
(12,@GUID8),
(12,@GUID9);

-- Innocuous Townsman
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=34565;
DELETE FROM `smart_scripts` WHERE `entryorguid`=34565 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3456500,3456501) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(34565,0,0,0,11,0,100,0,0,0,0,0,0,80,3456500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Innocuous Townsman - On Spawn - Run Script"),
(34565,0,1,0,11,0,100,0,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Innocuous Townsman - On Spawn - Set Active On"),
(34565,0,2,0,40,0,100,0,3,34565,0,0,0,80,3456501,0,0,0,0,0,1,0,0,0,0,0,0,0,"Innocuous Townsman - On Waypoint 3 Reached - Run Script"),
(34565,0,3,0,40,0,100,0,16,34565,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Innocuous Townsman - On Waypoint 16 Reached - Despawn"),
(3456500,9,0,0,0,0,100,0,5000,5000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Innocuous Townsman - On Script - Say Line 0"),
(3456500,9,1,0,0,0,100,0,6000,6000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Innocuous Townsman - On Script - Say Line 1"),
(3456500,9,2,0,0,0,100,0,8000,8000,0,0,0,53,1,34565,0,0,0,0,1,0,0,0,0,0,0,0,"Innocuous Townsman - On Script - Start Waypoint"),
(3456501,9,0,0,0,0,100,0,0,0,0,0,0,36,34561,0,0,0,0,0,1,0,0,0,0,0,0,0,"Innocuous Townsman - On Script - Update Template To 'Forsaken Prankster'"),
(3456501,9,1,0,0,0,100,0,500,500,0,0,0,11,65653,0,0,0,0,0,10,@GUID1,0,0,0,0,0,0,"Innocuous Townsman - On Script - Cast 'Stink Bomb Missile'"),
(3456501,9,2,0,0,0,100,0,1500,1500,0,0,0,11,65653,0,0,0,0,0,10,@GUID2,0,0,0,0,0,0,"Innocuous Townsman - On Script - Cast 'Stink Bomb Missile'"),
(3456501,9,3,0,0,0,100,0,1500,1500,0,0,0,11,65653,0,0,0,0,0,10,@GUID3,0,0,0,0,0,0,"Innocuous Townsman - On Script - Cast 'Stink Bomb Missile'"),
(3456501,9,4,0,0,0,100,0,1500,1500,0,0,0,11,65653,0,0,0,0,0,10,@GUID4,0,0,0,0,0,0,"Innocuous Townsman - On Script - Cast 'Stink Bomb Missile'"),
(3456501,9,5,0,0,0,100,0,2000,2000,0,0,0,11,65653,0,0,0,0,0,10,@GUID5,0,0,0,0,0,0,"Innocuous Townsman - On Script - Cast 'Stink Bomb Missile'");

DELETE FROM `creature_text` WHERE `CreatureID`=34565;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(34565,0,0,"Mmmm... There's nothing like good, home-cooked human food.",12,0,100,1,0,0,34782,0,"Innocuous Townsman"),
(34565,1,0,"I lied. Your miserable food stinks, but not as much as this town is going to stink!",12,0,100,11,0,0,34785,0,"Innocuous Townsman");

DELETE FROM `waypoints` WHERE `entry`=34565;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(34565,1,-856.403,-556.971,11.6916,""),
(34565,2,-849.485,-556.458,11.6761,""),
(34565,3,-849.281,-546.345,11.1077,""),
(34565,4,-857.277,-538.122,9.41379,""),
(34565,5,-856.051,-531.245,9.82966,""),
(34565,6,-834.079,-521.891,11.8369,""),
(34565,7,-819.108,-522.562,13.8261,""),
(34565,8,-777.843,-543.874,18.0778,""),
(34565,9,-727.653,-548.472,20.2261,""),
(34565,10,-690.424,-570.772,24.721,""),
(34565,11,-660.324,-558.618,25.6138,""),
(34565,12,-628.487,-565.115,27.7081,""),
(34565,13,-601.935,-575.539,31.3834,""),
(34565,14,-571.293,-570.342,32.7863,""),
(34565,15,-526.728,-558.687,39.0175,""),
(34565,16,-441.357,-582.82,53.3314,"");

-- Add gossip text for Sergeant Hartman
UPDATE `creature_template` SET `npcflag`=131, `gossip_menu_id`=6538 WHERE `entry`=15199;

DELETE FROM `gossip_menu` WHERE `MenuID`=6538;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(6538,7741,0);

-- Add aggro texts for some NPCs in Southshore
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2711,9978,2382,3543,2379,2378,3540,2383,2380,3541,2381) AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2711,0,1,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phin Odelic - On Aggro - Say Line 0"),
(9978,0,1,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wesley - On Aggro - Say Line 0"),
(2382,0,1,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darren Malvew - On Aggro - Say Line 0"),
(3543,0,1,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Robert Aebischer - On Aggro - Say Line 0"),
(2379,0,1,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caretaker Smithers - On Aggro - Say Line 0"),
(2378,0,1,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kundric Zanden - On Aggro - Say Line 0"),
(3540,0,1,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hal McAllister - On Aggro - Say Line 0"),
(2383,0,1,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lindea Rabonne - On Aggro - Say Line 0"),
(2380,0,1,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nandar Branson - On Aggro - Say Line 0"),
(3541,0,1,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sarah Raycroft - On Aggro - Say Line 0"),
(2381,0,1,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Micha Yance - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` IN (2711,9978,2382,3543,2379,2378,3540,2383,2380,3541,2381);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2711,0,0,"Guards! Help me!",12,7,100,0,0,0,4566,0,"Phin Odelic"),
(9978,0,0,"Guards! Help me!",12,7,100,0,0,0,4566,0,"Wesley"),
(2382,0,0,"Guards! Help me!",12,7,100,0,0,0,4566,0,"Darren Malvew"),
(3543,0,0,"Guards! Help me!",12,7,100,0,0,0,4566,0,"Robert Aebischer"),
(2379,0,0,"Guards! Help me!",12,7,100,0,0,0,4566,0,"Caretaker Smithers"),
(2378,0,0,"Guards! Help me!",12,7,100,0,0,0,4566,0,"Kundric Zanden"),
(3540,0,0,"Guards! Help me!",12,7,100,0,0,0,4566,0,"Hal McAllister"),
(2383,0,0,"Guards! Help me!",12,7,100,0,0,0,4566,0,"Lindea Rabonne"),
(2380,0,0,"Guards! Help me!",12,7,100,0,0,0,4566,0,"Nandar Branson"),
(3541,0,0,"Guards! Help me!",12,7,100,0,0,0,4566,0,"Sarah Raycroft"),
(2381,0,0,"Guards! Help me!",12,7,100,0,0,0,4566,0,"Micha Yance");

-- Add some quest emotes
DELETE FROM `quest_details` WHERE `ID` IN (11357,11131,12135,12139,1657,8322);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(11357,1,0,0,0,0,0,0,0,0), -- Quest "Masked Orphan Matron"
(11131,5,0,0,0,0,0,0,0,0), -- Quest "Stop the Fires!"
(12135,5,0,0,0,0,0,0,0,0), -- Quest "Let the Fires Come!"
(12139,5,0,0,0,0,0,0,0,0), -- Quest "Let the Fires Come!"
(1657,5,1,0,0,0,0,0,0,0), -- Quest "Stinking Up Southshore"
(8322,1,1,0,0,0,0,0,0,0); -- Quest "Rotten Eggs"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=11 WHERE `ID`=1657; -- Quest "Stinking Up Southshore"
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=12135; -- Quest "Let the Fires Come!"
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=12139; -- Quest "Let the Fires Come!"
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=8373; -- Quest "The Power of Pine"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=1658; -- Quest "Crashing the Wickerman Festival"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=66 WHERE `ID`=1657; -- Quest "Stinking Up Southshore"
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=11 WHERE `ID`=8409; -- Quest "Ruined Kegs"

-- Add gossip option for Costumed Orphan Matron & Masked Orphan Matron
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (8763,9470);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(8763,0,0,"Who is the Headless Horseman?",22620,1,1,8880,0,0,0,"",0,0),
(9470,0,0,"Who is the Headless Horseman?",22620,1,1,8880,0,0,0,"",0,0);

-- Add OOC texts for Touring Orphan & Traveling Orphan
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (23712,23971);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23712,23971) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23712,0,0,0,1,0,100,0,1000,120000,180000,300000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Touring Orphan - Out of Combat - Say Line 0"),
(23971,0,0,0,1,0,100,0,1000,120000,180000,300000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Traveling Orphan - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` IN (23712,23971);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23712,0,0,"What's happening?",12,7,100,18,0,0,22177,0,"Touring Orphan"),
(23712,0,1,"I want to go back to the orphanage!",12,7,100,18,0,0,22344,0,"Touring Orphan"),
(23712,0,2,"Matron!  Is that bad man going to eat us?",12,7,100,18,0,0,22345,0,"Touring Orphan"),
(23712,0,3,"If my dad were alive, he would put out the fires!",12,7,100,18,0,0,22346,0,"Touring Orphan"),
(23712,0,4,"If my mom were alive, she would put out the fires!",12,7,100,18,0,0,22347,0,"Touring Orphan"),
(23971,0,0,"What's happening?",12,1,100,18,0,0,22533,0,"Traveling Orphan"),
(23971,0,1,"I want to go back to the orphanage!",12,1,100,18,0,0,22534,0,"Traveling Orphan"),
(23971,0,2,"Matron!  Is that bad man going to eat us?",12,1,100,18,0,0,22535,0,"Traveling Orphan"),
(23971,0,3,"If my dad were alive, he would put out the fires!",12,1,100,18,0,0,22536,0,"Traveling Orphan"),
(23971,0,4,"If my mom were alive, she would put out the fires!",12,1,100,18,0,0,22537,0,"Traveling Orphan");

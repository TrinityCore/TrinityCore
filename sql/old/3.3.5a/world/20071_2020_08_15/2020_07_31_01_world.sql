-- Kristen Dipswitch
UPDATE `creature` SET `spawntimesecs`=1800 WHERE `guid`=65624;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=18294;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18294 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1829400,1829401) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18294,0,0,0,11,0,100,0,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kristen Dipswitch - On Respawn - Remove NPC Flags 'Questgiver' & 'Gossip'"),
(18294,0,1,0,11,0,100,0,0,0,0,0,0,53,1,18294,0,0,0,1,1,0,0,0,0,0,0,0,"Kristen Dipswitch - On Respawn - Start Waypoint"),
(18294,0,2,0,40,0,100,0,19,18294,0,0,0,80,1829400,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kristen Dipswitch - On Point 19 Reached - Run Script"),
(18294,0,3,0,0,0,100,1,1000,1000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kristen Dipswitch - In Combat - Say Line 1 (No Repeat)"),
(18294,0,4,0,6,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,18297,0,0,0,0,0,0,"Kristen Dipswitch - On Just Died - Set Data 1-1"),
(18294,0,5,0,38,0,100,0,1,2,0,0,0,80,1829401,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kristen Dipswitch - On Data 1-2 Set - Run Script"),
(18294,0,6,0,11,0,100,0,0,0,0,0,0,43,0,14375,0,0,0,0,1,0,0,0,0,0,0,0,"Kristen Dipswitch - On Respawn - Mount to Model 14375"),
(18294,0,7,0,11,0,100,0,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kristen Dipswitch - On Respawn - Set Active On"),
(1829400,9,0,0,0,0,100,0,0,0,0,0,0,12,18297,8,0,0,0,0,8,0,0,0,-1463.63,6363.4,36.9237,0,"Kristen Dipswitch - On Script - Summon Creature 'Gankly Rottenfist'"),
(1829400,9,1,0,0,0,100,0,2000,2000,0,0,0,43,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kristen Dipswitch - On Script - Dismount"),
(1829400,9,2,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.97859,"Kristen Dipswitch - On Script - Set Orientation"),
(1829400,9,3,0,0,0,100,0,1000,1000,0,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kristen Dipswitch - On Script - Set Faction 250"),
(1829400,9,4,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kristen Dipswitch - On Script - Say Line 0"),
(1829401,9,0,0,0,0,100,0,2000,2000,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kristen Dipswitch - On Script - Set Faction 35"),
(1829401,9,1,0,0,0,100,0,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kristen Dipswitch - On Script - Add NPC Flags 'Questgiver' & 'Gossip'"),
(1829401,9,2,0,0,0,100,0,300000,300000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kristen Dipswitch - On Script - Despawn");

UPDATE `creature_template_addon` SET `mount`=0 WHERE `entry`=18294;

-- Gankly Rottenfist
DELETE FROM `creature` WHERE `id`=18297; -- Gankly Rottenfist should only spawn as part of this event
UPDATE `creature_template` SET `AIName`="SmartAI", `unit_flags`=768 WHERE `entry`=18297;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18297 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1829700,1829701) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18297,0,0,1,54,0,100,0,0,0,0,0,0,11,32199,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gankly Rottenfist - Just Summoned - Cast 'Stealth'"),
(18297,0,1,0,61,0,100,0,0,0,0,0,0,53,0,18297,0,0,0,2,1,0,0,0,0,0,0,0,"Gankly Rottenfist - Just Summoned - Start Waypoint"),
(18297,0,2,0,40,0,100,0,10,18297,0,0,0,80,1829700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gankly Rottenfist - On Point 11 Reached - Run Script"),
(18297,0,3,0,38,0,100,0,1,1,0,0,0,80,1829701,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gankly Rottenfist - On Data 1-1 Set - Run Script"),
(18297,0,4,0,6,0,100,0,0,0,0,0,0,45,1,2,0,0,0,0,19,18294,0,0,0,0,0,0,"Gankly Rottenfist - On Just Died - Set Data 1-2"),
(18297,0,5,0,0,0,100,0,5000,7000,11000,13000,0,11,30981,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gankly Rottenfist - In Combat - Cast 'Crippling Poison'"),
(18297,0,6,0,0,0,100,0,9000,11000,15000,17000,0,11,41176,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gankly Rottenfist - In Combat - Cast 'Shadowstep'"),
(18297,0,7,0,0,0,100,0,3000,5000,9000,11000,0,11,15581,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gankly Rottenfist - In Combat - Cast 'Sinister Strike'"),
(1829700,9,0,0,0,0,100,0,500,500,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.42229,"Gankly Rottenfist - On Script - Set Orientation"),
(1829700,9,1,0,0,0,100,0,500,500,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gankly Rottenfist - On Script - Say Line 0"),
(1829700,9,2,0,0,0,100,0,2000,2000,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gankly Rottenfist - On Script - Remove Unit Flags 'Immune To PC' & 'Immune To NPC'"),
(1829700,9,3,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,19,18294,0,0,0,0,0,0,"Gankly Rottenfist - On Script - Start Attacking"),
(1829701,9,0,0,0,0,100,0,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gankly Rottenfist - On Script - Add Unit Flag 'Immune To PC'"),
(1829701,9,1,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gankly Rottenfist - On Script - Set React State 'Passive'"),
(1829701,9,2,0,0,0,100,0,2000,2000,0,0,0,28,32199,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gankly Rottenfist - On Script - Remove Aura 'Stealth'"),
(1829701,9,3,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gankly Rottenfist - On Script - Say Line 1"),
(1829701,9,4,0,0,0,100,0,5000,5000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.13852,"Gankly Rottenfist - On Script - Set Orientation 3,13852"),
(1829701,9,5,0,0,0,100,0,500,500,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gankly Rottenfist - On Script - Say Line 2"),
(1829701,9,6,0,0,0,100,0,5000,5000,0,0,0,1,0,0,0,0,0,0,19,18218,0,0,0,0,0,0,"Gankly Rottenfist - On Script - Say Line 0 (Harold Lane)"),
(1829701,9,7,0,0,0,100,0,5000,5000,0,0,0,45,1,3,0,0,0,0,19,18200,0,0,0,0,0,0,"Gankly Rottenfist - On Script - Set Data 1-3 to Shado 'Fitz' Farstrider"),
(1829701,9,8,0,0,0,100,0,0,0,0,0,0,45,1,3,0,0,0,0,19,18180,0,0,0,0,0,0,"Gankly Rottenfist - On Script - Set Data 1-3 to Hemet Nesingwary");

UPDATE `creature_template_addon` SET `auras`="" WHERE `entry`=18297;

-- Shado 'Fitz' Farstrider & Hemet Nesingwary
UPDATE `creature_template` SET `AIName`="SmartAI", `flags_extra`=0, `unit_flags`=0 WHERE `entry` IN (18200,18180);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18200,18180) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1820000,1818000) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18200,0,0,0,38,0,100,0,1,3,0,0,0,80,1820000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shado 'Fitz' Farstrider - On Data 1-3 Set - Run Script"),
(18180,0,0,0,38,0,100,0,1,3,0,0,0,80,1820000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hemet Nesingwary - On Data 1-3 Set - Run Script"),
(18200,0,1,0,38,0,100,0,2,1,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.4323,"Shado 'Fitz' Farstrider - On Data 2-1 Set - Set Orientation"),
(18200,0,2,3,38,0,100,0,2,2,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shado 'Fitz' Farstrider - On Data 2-2 Set - Say Line 0"),
(18200,0,3,0,61,0,100,0,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shado 'Fitz' Farstrider - On Data 2-2 Set - Set Sheath 'Melee'"),
(18180,0,1,0,11,0,100,0,0,0,0,0,0,53,0,18180,1,0,0,2,1,0,0,0,0,0,0,0,"Hemet Nesingwary - On Respawn - Start Waypoint"),
(18180,0,2,3,40,0,100,0,1,18180,0,0,0,54,1800000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hemet Nesingwary - On Point 1 Reached - Pause Waypoint"),
(18180,0,3,0,61,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,6.230825,"Hemet Nesingwary - On Point 1 Reached - Set Orientation"),
(18180,0,4,5,40,0,100,0,2,18180,0,0,0,54,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hemet Nesingwary - On Point 2 Reached - Pause Waypoint"),
(18180,0,5,6,61,0,100,0,0,0,0,0,0,107,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hemet Nesingwary - On Point 2 Reached - Summon Group"),
(18180,0,6,7,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hemet Nesingwary - On Point 2 Reached - Say Line 0"),
(18180,0,7,8,61,0,100,0,0,0,0,0,0,2,495,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hemet Nesingwary - On Point 2 Reached - Set Faction 495"),
(18180,0,8,0,61,0,100,0,0,0,0,0,0,2,495,0,0,0,0,0,19,18200,0,0,0,0,0,0,"Hemet Nesingwary - On Point 2 Reached - Set Faction 495 (Shado 'Fitz' Farstride)"),
(18180,0,9,10,40,0,100,0,3,18180,0,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hemet Nesingwary - On Point 3 Reached - Pause Waypoint"),
(18180,0,10,11,61,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.953772,"Hemet Nesingwary - On Point 3 Reached - Set Orientation"),
(18180,0,11,0,61,0,100,0,0,0,0,0,0,80,1818000,2,0,0,0,0,1,0,0,0,0,0,0,0,"Hemet Nesingwary - On Point 3 Reached - Run Script"),
(18180,0,12,0,4,0,100,0,0,0,0,0,0,11,32168,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hemet Nesingwary - On Aggro - Cast 'Shoot'"),
(18180,0,13,0,0,0,100,0,1000,1000,2000,2000,0,11,32168,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hemet Nesingwary - In Combat - Cast 'Shoot'"),
(18180,0,14,15,40,0,100,0,4,18180,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hemet Nesingwary - On Point 4 Reached - Set Faction 35"),
(18180,0,15,0,61,0,100,0,0,0,0,0,0,2,35,0,0,0,0,0,19,18200,0,0,0,0,0,0,"Hemet Nesingwary - On Point 4 Reached - Set Faction 35 (Shado 'Fitz' Farstride)"),
(18180,0,16,0,11,0,100,0,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hemet Nesingwary - On Respawn - Set Active On"),
(1820000,9,0,0,0,0,100,0,0,0,0,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shado 'Fitz' Farstrider - On Script - Set Faction 250"),
(1820000,9,1,0,0,0,100,0,0,0,0,0,0,11,32190,0,0,0,0,0,19,18297,0,0,0,0,0,0,"Shado 'Fitz' Farstrider - On Script - Cast 'Shoot'"),
(1820000,9,2,0,0,0,100,0,3000,3000,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shado 'Fitz' Farstrider - On Script - Set Faction 35"),
(1818000,9,0,0,0,0,100,0,7000,7000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hemet Nesingwary - On Script - Say Line 1"),
(1818000,9,1,0,0,0,100,0,0,0,0,0,0,45,2,1,0,0,0,0,19,18200,0,0,0,0,0,0,"Hemet Nesingwary - On Script - Set Data 2-1 to Shado 'Fitz' Farstrider"),
(1818000,9,2,0,0,0,100,0,1000,1000,0,0,0,45,2,2,0,0,0,0,19,18200,0,0,0,0,0,0,"Hemet Nesingwary - On Script - Set Data 2-1 to Shado 'Fitz' Farstrider"),
(1818000,9,3,0,0,0,100,0,0,0,1000,1000,0,49,0,0,0,0,0,0,19,17130,50,0,0,0,0,0,"Hemet Nesingwary - On Script - Start Attacking"),
(1818000,9,4,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,19,18218,0,0,0,0,0,0,"Hemet Nesingwary - On Script - Say Line 1 (Harold Lane)"),
(1818000,9,5,0,0,0,100,0,7000,7000,0,0,0,1,2,0,0,0,0,0,19,18218,0,0,0,0,0,0,"Hemet Nesingwary - On Script - Say Line 2 (Harold Lane)"),
(1818000,9,6,0,0,0,100,0,7000,7000,0,0,0,1,3,0,0,0,0,0,19,18218,0,0,0,0,0,0,"Hemet Nesingwary - On Script - Say Line 3 (Harold Lane)"),
(1818000,9,7,0,0,0,100,0,8000,8000,0,0,0,1,4,0,0,0,0,0,19,18218,0,0,0,0,0,0,"Hemet Nesingwary - On Script - Say Line 4 (Harold Lane)");

DELETE FROM `creature_summon_groups` WHERE `summonerId`=18180;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(18180,0,1,17130,-1404.007,6327.922,39.87714,5.099442,6,30000),
(18180,0,1,17130,-1414.938,6305.905,42.40896,2.952087,6,30000),
(18180,0,1,17130,-1416.502,6317.921,40.0441,0.466735,6,30000);

-- Talbuk Stag
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=17130;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17130 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1713000 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17130,0,0,0,0,0,100,0,6000,9000,15000,18000,0,11,32019,0,0,0,0,0,2,0,0,0,0,0,0,0,"Talbuk Stag - In Combat - Cast 'Gore'"),
(17130,0,1,0,54,0,100,0,0,0,0,0,0,80,1713000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talbuk Stag - Just Summoned - Run Script"),
(1713000,9,0,0,0,0,100,0,0,0,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talbuk Stag - On Script - Set Faction 14"),
(1713000,9,1,0,0,0,100,0,0,0,0,0,0,89,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talbuk Stag - On Script - Start Random Movement"),
(1713000,9,2,0,0,0,100,0,0,0,0,0,0,117,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talbuk Stag - On Script - Disable Evade"),
(1713000,9,3,0,0,0,100,0,10000,10000,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,"Talbuk Stag - On Script - Start Attacking");

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (18294,18297,18218,18180,18200);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(18294,0,0,"Hi, Harold.  I have your skins!",12,0,100,3,0,0,15102,0,"Kristen Dipswitch"),
(18294,1,0,"Ack!  Somebody help me!",12,0,100,0,0,0,15104,0,"Kristen Dipswitch"),
(18297,0,0,"I'll be taking those skins, tiny.",12,0,100,0,0,0,15111,0,"Gankly Rottenfist"),
(18297,1,0,"%s rifles through Kristen's stuff and grabs her bundle of skins.",16,0,100,16,0,0,15109,0,"Gankly Rottenfist"),
(18297,2,0,"Here are my skins, Harold.  Now give me the reward!",12,0,100,1,0,0,15110,0,"Gankly Rottenfist"),
(18218,0,0,"Uh... sure thing, Gankly.  Just...<cough>... wait right there.  <Cough>  Guys?",12,0,100,0,0,0,15112,0,"Harold Lane"),
(18218,1,0,"What's going on?!",12,0,100,0,0,0,15090,0,"Harold Lane"),
(18218,2,0,"Um... guys?",12,0,100,0,0,0,15093,0,"Harold Lane"),
(18218,3,0,"Hemet?  Fitz?",12,0,100,0,0,0,15094,0,"Harold Lane"),
(18218,4,0,"Oh good, I was beginning to worry.",12,0,100,0,0,0,15095,0,"Harold Lane"),
(18180,0,0,"Uh oh, those stags don't look pleased with us!",12,0,100,0,0,0,15088,0,"Hemet Nesingwary"),
(18180,1,0,"Look out, Fitz, they're coming right for us!",12,0,100,0,0,0,15089,0,"Hemet Nesingwary"),
(18200,0,0,"%s smiles and sheathes his rifle.",16,0,100,0,0,0,15091,0,"Shado 'Fitz' Farstrider");

-- Waypoints
DELETE FROM `waypoints` WHERE `entry` IN (18294,18297,18180);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(18294,1,-1249.43,6236.27,52.6698,"Kristen Dipswitch"),
(18294,2,-1252.89,6238.29,52.0455,"Kristen Dipswitch"),
(18294,3,-1256.35,6240.3,51.4205,"Kristen Dipswitch"),
(18294,4,-1260.68,6242.81,50.7955,"Kristen Dipswitch"),
(18294,5,-1265.87,6245.83,50.1705,"Kristen Dipswitch"),
(18294,6,-1270.19,6248.35,49.5503,"Kristen Dipswitch"),
(18294,7,-1274.61,6258,48.6878,"Kristen Dipswitch"),
(18294,8,-1279.68,6269.1,48.1845,"Kristen Dipswitch"),
(18294,9,-1284.75,6280.2,47.6812,"Kristen Dipswitch"),
(18294,10,-1285.32,6281.5,47.6299,"Kristen Dipswitch"),
(18294,11,-1293,6287.91,47.0562,"Kristen Dipswitch"),
(18294,12,-1305.28,6298.16,46.4802,"Kristen Dipswitch"),
(18294,13,-1310.65,6302.65,45.8879,"Kristen Dipswitch"),
(18294,14,-1318.33,6309.05,45.2629,"Kristen Dipswitch"),
(18294,15,-1320.36,6310.72,45.0323,"Kristen Dipswitch"),
(18294,16,-1355.68,6335.35,43.3028,"Kristen Dipswitch"),
(18294,17,-1386.62,6357.33,40.5069,"Kristen Dipswitch"),
(18294,18,-1423.46,6354.5,37.7959,"Kristen Dipswitch"),
(18294,19,-1452.59,6351.94,37.2739,"Kristen Dipswitch"),
(18297,1,-1463.63,6363.4,36.9237,"Gankly Rottenfist"),
(18297,2,-1461.74,6366.47,36.445,"Gankly Rottenfist"),
(18297,3,-1458.92,6368.42,36.0956,"Gankly Rottenfist"),
(18297,4,-1455.34,6367.12,36.2761,"Gankly Rottenfist"),
(18297,5,-1452.8,6364.54,36.6589,"Gankly Rottenfist"),
(18297,6,-1450.19,6361.55,36.9106,"Gankly Rottenfist"),
(18297,7,-1448.18,6358.95,37.1489,"Gankly Rottenfist"),
(18297,8,-1447.03,6354.99,37.3989,"Gankly Rottenfist"),
(18297,9,-1448.83,6352.42,37.3518,"Gankly Rottenfist"),
(18297,10,-1451.46,6352.27,37.2739,"Gankly Rottenfist"),
(18180,1,-1461.778,6344.301,37.27388,"Hemet Nesingwary"),
(18180,2,-1461.778,6344.301,37.27388,"Hemet Nesingwary"),
(18180,3,-1459.696,6341.464,37.24043,"Hemet Nesingwary"),
(18180,4,-1461.778,6344.301,37.27388,"Hemet Nesingwary");

DELETE FROM `gossip_menu` WHERE `MenuID`=7629 AND `TextID`=9293;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7629,9293,0);

DELETE FROM `npc_text` WHERE `ID`=9293;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `EmoteDelay0_0`, `Emote0_0`, `EmoteDelay0_1`, `Emote0_1`, `EmoteDelay0_2`, `Emote0_2`, `text1_0`, `text1_1`, `BroadcastTextID1`, `lang1`, `Probability1`, `EmoteDelay1_0`, `Emote1_0`, `EmoteDelay1_1`, `Emote1_1`, `EmoteDelay1_2`, `Emote1_2`, `text2_0`, `text2_1`, `BroadcastTextID2`, `lang2`, `Probability2`, `EmoteDelay2_0`, `Emote2_0`, `EmoteDelay2_1`, `Emote2_1`, `EmoteDelay2_2`, `Emote2_2`, `text3_0`, `text3_1`, `BroadcastTextID3`, `lang3`, `Probability3`, `EmoteDelay3_0`, `Emote3_0`, `EmoteDelay3_1`, `Emote3_1`, `EmoteDelay3_2`, `Emote3_2`, `text4_0`, `text4_1`, `BroadcastTextID4`, `lang4`, `Probability4`, `EmoteDelay4_0`, `Emote4_0`, `EmoteDelay4_1`, `Emote4_1`, `EmoteDelay4_2`, `Emote4_2`, `text5_0`, `text5_1`, `BroadcastTextID5`, `lang5`, `Probability5`, `EmoteDelay5_0`, `Emote5_0`, `EmoteDelay5_1`, `Emote5_1`, `EmoteDelay5_2`, `Emote5_2`, `text6_0`, `text6_1`, `BroadcastTextID6`, `lang6`, `Probability6`, `EmoteDelay6_0`, `Emote6_0`, `EmoteDelay6_1`, `Emote6_1`, `EmoteDelay6_2`, `Emote6_2`, `text7_0`, `text7_1`, `BroadcastTextID7`, `lang7`, `Probability7`, `EmoteDelay7_0`, `Emote7_0`, `EmoteDelay7_1`, `Emote7_1`, `EmoteDelay7_2`, `Emote7_2`, `VerifiedBuild`) VALUES
(9293,"","Hey!  Didn't I give you a bundle of skins before?$B$BEither way, I'm glad to be saved from the ruthless clutches of that evil Gankly Rottenfist!",15140,0,1,0,6,0,1,0,0,"","",0,0,0,0,0,0,0,0,0,"","",0,0,0,0,0,0,0,0,0,"","",0,0,0,0,0,0,0,0,0,"","",0,0,0,0,0,0,0,0,0,"","",0,0,0,0,0,0,0,0,0,"","",0,0,0,0,0,0,0,0,0,"","",0,0,0,0,0,0,0,0,0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7629;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7629,9293,0,0,8,0,9897,0,0,0,0,0,"","Show gossip text 9293 if quest 'I'm Saved' is rewarded");

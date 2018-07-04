-- Coldridge Citizen SAI
SET @GUID := 305665;
SET @ENTRY := 37218;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-6069.182,`position_y`=382.8663,`position_z`=393.6012 WHERE `guid`=@GUID;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@GUID) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100,@ENTRY*100+1) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-@GUID,0,0,0,11,0,100,0,0,0,0,0,53,0,@ENTRY,1,0,0,0,1,0,0,0,0,0,0,0,"Coldridge Citizen - On Spawn - Start WP"),
(-@GUID,0,1,2,40,0,100,0,6,@ENTRY,0,0,54,20000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldridge Citizen - On Reached WP6 - Pause WP"),
(-@GUID,0,2,0,61,0,100,0,0,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldridge Citizen - On Reached WP6 - Run Script 1"),
(-@GUID,0,3,4,40,0,100,0,12,@ENTRY,0,0,54,200000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldridge Citizen - On Reached WP12 - Pause WP"),
(-@GUID,0,4,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldridge Citizen - On Reached WP12 - Run Script 2"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.570796,"Coldridge Citizen - Script - Turn to"),
(@ENTRY*100,9,1,0,0,0,100,0,1000,1000,0,0,17,418,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldridge Citizen - Script - Set Emotstate"),
(@ENTRY*100,9,2,0,0,0,100,0,18000,18000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldridge Citizen - Script - Set Emotstate"),
(@ENTRY*100+1,9,0,0,0,0,100,0,1000,1000,0,0,90,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldridge Citizen - Script - Set bytes1 sleep"),
(@ENTRY*100+1,9,1,0,0,0,100,0,198000,198000,0,0,91,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coldridge Citizen - Script - Remove bytes1 sleep");
-- Coldridge Citizen path
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,-6069.182,382.8663,393.6012, 'Coldridge Citizen'),
(@ENTRY,2,-6074.912,385.8993,393.6029, 'Coldridge Citizen'),
(@ENTRY,3,-6081.568,392.5121,393.5983, 'Coldridge Citizen'),
(@ENTRY,4,-6088.535,399.2757,395.5213, 'Coldridge Citizen'),
(@ENTRY,5,-6097.424,403.1667,395.5372, 'Coldridge Citizen'),
(@ENTRY,6,-6097.424,403.1667,395.5372, 'Coldridge Citizen'),
(@ENTRY,7,-6088.427,399.5216,395.5428, 'Coldridge Citizen'),
(@ENTRY,8,-6081.364,393.1143,393.8759, 'Coldridge Citizen'),
(@ENTRY,9,-6074.948,386.1493,393.603, 'Coldridge Citizen'),
(@ENTRY,10,-6071.469,385.2639,393.6025, 'Coldridge Citizen'),
(@ENTRY,11,-6067.965,380.7674,393.5997, 'Coldridge Citizen'),
(@ENTRY,12,-6066.971,370.8108,393.5969, 'Coldridge Citizen'),
(@ENTRY,13,-6069.182,382.8663,393.6012, 'Coldridge Citizen');

-- Jona Ironstock SAI
SET @ENTRY := 37087;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,30000,60000,150000,150000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jona Ironstock - OOC - Say 0");
-- Jona Ironstock text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'Get ta work, boys!', 12, 7, 100, 22, 0, 0, 36970, 'Jona Ironstock'),
(@ENTRY, 0, 1, 'Don''t fret, we''ll be outta here soon.', 12, 7, 100, 22, 0, 0, 36971, 'Jona Ironstock'),
(@ENTRY, 0, 2, 'Let''s keep this fire going, dwarves!', 12, 7, 100, 22, 0, 0, 36972, 'Jona Ironstock'),
(@ENTRY, 0, 3, 'What''s Joren doin'' out there, anyhow?', 12, 7, 100, 6, 0, 0, 36973, 'Jona Ironstock');

-- Teo Hammerstorm SAI
SET @ENTRY := 37115;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,30000,30000,120000,120000,11,78159,0,0,0,0,0,1,0,0,0,0,0,0,0,"Teo Hammerstorm - OOC - Cast 'Windfury Totem'"),
(@ENTRY,0,1,0,1,0,100,0,60000,60000,120000,120000,11,79429,0,0,0,0,0,1,0,0,0,0,0,0,0,"Teo Hammerstorm - OOC - Cast 'Elemental Resistance Totem'"),
(@ENTRY,0,2,0,1,0,100,0,90000,90000,120000,120000,11,79431,0,0,0,0,0,1,0,0,0,0,0,0,0,"Teo Hammerstorm - OOC - Cast 'Flametongue Totem'");

-- Frostmane Troll Whelp SAI
SET @ENTRY := 706;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,25,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostmane Troll Whelp - On Aggro - Say 0 (No Repeat)");

-- Frostmane Novice SAI
SET @ENTRY := 946;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,25,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostmane Novice - On Aggro - Say 0 (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3000,4000,11,6949,64,0,0,0,0,2,0,0,0,0,0,0,0,"Frostmane Novice - In Combat - Cast 'Weak Frostbolt'");
DELETE FROM `creature_text` WHERE `entry` IN (@ENTRY);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'You be dead soon!', 12, 14, 100, 0, 0, 0, 10434, 'Frostmane Novice'),
(@ENTRY, 0, 1, 'Killing you be easy.', 12, 14, 100, 0, 0, 0, 1909, 'Frostmane Novice'),
(@ENTRY, 0, 2, 'I gonna make you into mojo!', 12, 14, 100, 0, 0, 0, 10435, 'Frostmane Novice'),
(@ENTRY, 0, 3, 'My weapon be thirsty!', 12, 14, 100, 0, 0, 0, 1908, 'Frostmane Novice');

-- Frostmane Blade SAI
SET @ENTRY := 37507;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,25,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostmane Blade - On Aggro - Say 0 (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,5,20000,30000,11,70133,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostmane Blade - Range 5 yards - Cast 'Poisoned Blade'");
DELETE FROM `creature_text` WHERE `entry` IN (@ENTRY);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'You be dead soon!', 12, 0, 100, 0, 0, 0, 10434, 'Frostmane Blade'),
(@ENTRY, 0, 1, 'Killing you be easy.', 12, 0, 100, 0, 0, 0, 1909, 'Frostmane Blade'),
(@ENTRY, 0, 2, 'I gonna make you into mojo!', 12, 0, 100, 0, 0, 0, 10435, 'Frostmane Blade'),
(@ENTRY, 0, 3, 'My weapon be thirsty!', 12, 0, 100, 0, 0, 0, 1908, 'Frostmane Blade');

-- Rockjaw Scavenger SAI
SET @ENTRY := 37105;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,69897,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rockjaw Scavenger - On Aggro - Cast 'Throw Priceless Artifact' (No Repeat)");

-- Rockjaw Goon SAI
SET @ENTRY := 37073;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,9,0,100,0,0,5,11000,13000,11,69851,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rockjaw Goon - Range 5 yards - Cast 'Club'"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rockjaw Goon - In Combat - Say 0");
-- Rockjaw Goon text
DELETE FROM `creature_text` WHERE `entry` IN (@ENTRY);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'You break our cave, I break your skull!', 12, 0, 100, 0, 0, 0, 36904, 'Rockjaw Goon'),
(@ENTRY, 0, 1, 'Why you break our home?!', 12, 0, 100, 0, 0, 0, 36903, 'Rockjaw Goon'),
(@ENTRY, 0, 2, 'Trogg cave all gone!  You pay for this!!', 12, 0, 100, 0, 0, 0, 36905, 'Rockjaw Goon');

-- Wayward Fire Elemental SAI
SET @ENTRY := 37112;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,60000,60000,120000,120000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wayward Fire Elemental - OOC - Say 0"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wayward Fire Elemental - On Aggro - Say 1 (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,4000,6000,18000,12000,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wayward Fire Elemental - In Combat - Cast 'Fireball'");
-- Wayward Fire Elemental text
DELETE FROM `creature_text` WHERE `entry` IN (@ENTRY);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'I am from the elemental plane!', 14, 12, 100, 0, 0, 0, 36949, 'Wayward Fire Elemental'),
(@ENTRY, 1, 0, 'I AM FROM THE ELEMENTAL PLANE!', 12, 12, 100, 0, 0, 0, 37019, 'Wayward Fire Elemental');

-- Grik'nir the Cold SAI
SET @ENTRY := 808;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,15000,11,79895,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grik'nir the Cold - In Combat - Cast 'Frost Strike'"),
(@ENTRY,0,1,2,4,0,100,1,0,0,0,0,11,6957,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grik'nir the Cold - On Aggro - Cast 'Frostmane Strength' (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,1,0,0,0,0,2,0,0,0,0,0,0,0,"Grik'nir the Cold - On Aggro - Say 0 (No Repeat)");
-- Grik'nir the Cold text
DELETE FROM `creature_text` WHERE `entry` IN (@ENTRY);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(808, 0, 0, 'First da fire, and now da $r!  You gonna die!', 12, 0, 100, 6, 0, 0, 36953, 'Grik''nir the Cold to Player');
-- Grik'nir the Cold
DELETE FROM `creature_template_addon` WHERE `entry` IN (808);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(808,0,0,0,1,0, '80631');

-- Various npcs surrounding Grik'nir the Cold
DELETE FROM `creature_addon` WHERE `guid` IN (305931,305935,305937,305939,305940,305941,305943,305945,305950);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(305939,0,0,0,1,27, ''),(305931,0,0,0,1,333, ''),(305935,0,0,0,1,333, ''),(305937,0,0,0,1,333, ''),(305943,0,0,0,1,333, ''),
(305945,0,0,0,1,333, ''),(305950,0,0,0,1,333, ''),(305940,0,0,7,1,0, ''),(305941,0,0,7,1,0, '');

UPDATE `creature` SET `unit_flags`=33587456 WHERE `guid` IN (305940,305941);
UPDATE `creature` SET `spawndist`=3,`MovementType`=1 WHERE `guid` IN (305947,305885,305880,305932,305929,305912);
UPDATE `creature` SET `spawndist`=4,`MovementType`=1 WHERE `guid` IN (305946,305898,305899);
UPDATE `creature` SET `spawndist`=5,`MovementType`=1 WHERE `guid` IN (305927,305933,305944,305953,305925,305923,305921,305913,305914,305915,305916,305897,305911,305890,305883,305926);
UPDATE `creature` SET `spawndist`=4,`MovementType`=1,`position_x`=-6475.569,`position_y`=390.3424,`position_z`=382.6454 WHERE `guid`=305934;
UPDATE `creature` SET `spawndist`=4,`MovementType`=1,`position_x`=-6494.345,`position_y`=393.2654,`position_z`=384.607 WHERE `guid`=305929;

-- Joren Ironstock SAI
SET @ENTRY := 37081;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Joren Ironstock - On Spawn - Prevent Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,70014,0,0,0,0,0,2,0,0,0,0,0,0,0,"Joren Ironstock - On Aggro - Cast 'Shoot'"),
(@ENTRY,0,2,0,61,0,20,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Joren Ironstock - On Aggro - Say 0");
DELETE FROM `creature_text` WHERE `entry` IN (@ENTRY);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'Get back, ye filthy beast!', 12, 0, 100, 0, 0, 0, 37007, 'Joren Ironstock'),
(@ENTRY, 0, 1, 'Eat dwarven lead!', 12, 0, 100, 0, 0, 0, 37008, 'Joren Ironstock'),
(@ENTRY, 0, 2, 'For Ironforge!', 12, 0, 100, 0, 0, 0, 37009, 'Joren Ironstock');

-- Add random movement to Coldridge Citizen
UPDATE `creature` SET `spawndist`=4,`MovementType`=1 WHERE `guid` IN (305748,305746,305736,305726,305662,305727,305725,305737,305734);

-- Remove bad spawns
DELETE FROM `creature` WHERE `guid` IN (305598,305599,305601,305602,305603,305604,305605,305607,305620,305636,305637,305638,305639,305640,305641,305642,305644,305645,305646,305647,305648);
DELETE FROM `creature` WHERE `guid` IN (305656,305657,305658,305659,305666,305670,305702,305942,305928);
DELETE FROM `creature_addon` WHERE `guid` IN (305598,305599,305601,305602,305603,305604,305605,305607,305620,305636,305637,305638,305639,305640,305641,305642,305644,305645,305646,305647,305648);
DELETE FROM `creature_addon` WHERE `guid` IN (305656,305657,305658,305659,305666,305670,305702,305942,305928);

-- Wounded Coldridge Mountaineer
SET @ENTRY := 37080;
DELETE FROM `creature_template_addon` WHERE `entry` IN (@ENTRY);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@ENTRY,0,0,8,1,0, '');
-- Wounded Coldridge Mountaineer text
DELETE FROM `creature_text` WHERE `entry` IN (@ENTRY);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'Thanks!  I can make it from here.', 12, 0, 100, 1, 0, 0, 36982, 'Wounded Coldridge Mountaineer'),
(@ENTRY, 0, 1, 'Yer a lifesaver!  For Ironforge!', 12, 0, 100, 1, 0, 0, 36983, 'Wounded Coldridge Mountaineer'),
(@ENTRY, 0, 2, 'Ahh, much better.  I owe ya one.', 12, 0, 100, 1, 0, 0, 36984, 'Wounded Coldridge Mountaineer');

-- Soothsayer Shi'kala SAI
SET @ENTRY := 37108;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,69995,0,30000,30000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Soothsayer Shi'kala - On Spellhit - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Soothsayer Shi'kala - Script - Say 0"),
(@ENTRY*100,9,1,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Soothsayer Shi'kala - Script - Say 1"),
(@ENTRY*100,9,2,0,0,0,100,0,6000,6000,0,0,11,70007,0,0,0,0,0,1,0,0,0,0,0,0,0,"Soothsayer Shi'kala - Script - Cast 'Soothsayer Kill Credit SE'"),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Soothsayer Shi'kala - Script - Say 2");
-- Soothsayer Shi'kala text
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'Da spirits be angry with us.', 12, 0, 100, 396, 0, 0, 36962, 'Soothsayer Shi''kala'),
(@ENTRY, 1, 0, 'I don'' know why the spirits be rejectin'' us so.', 12, 0, 100, 396, 0, 0, 36958, 'Soothsayer Shi''kala'),
(@ENTRY, 2, 0, 'Don'' worry, child.  Grik''nir gonna help us get through this.', 12, 0, 100, 396, 0, 0, 36959, 'Soothsayer Shi''kala');
-- Soothsayer Rikkari SAI
SET @ENTRY := 37173;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,69995,0,30000,30000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Soothsayer Rikkari - On Spellhit - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Soothsayer Rikkari - Script - Say 0"),
(@ENTRY*100,9,1,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Soothsayer Rikkari - Script - Say 1"),
(@ENTRY*100,9,2,0,0,0,100,0,6000,6000,0,0,11,70008,0,0,0,0,0,1,0,0,0,0,0,0,0,"Soothsayer Rikkari - Script - Cast 'Soothsayer Kill Credit SW'"),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Soothsayer Rikkari - Script - Say 2");
-- Soothsayer Rikkari
DELETE FROM `creature_text` WHERE `entry` IN (@ENTRY);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'What we gon'' do now, you ask?  We wait.', 12, 0, 100, 396, 0, 0, 36957, 'Soothsayer Rikkari'),
(@ENTRY, 1, 0, 'Grik''nir says he gon'' talk to the elemental, get it to fight on our side.', 12, 0, 100, 396, 0, 0, 36960, 'Soothsayer Rikkari'),
(@ENTRY, 2, 0, 'Soon enough we take over dis valley.  Soon enough.', 12, 0, 100, 396, 0, 0, 36961, 'Soothsayer Rikkari');
-- Soothsayer Mirim'koa SAI
SET @ENTRY := 37174;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,69995,0,30000,30000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Soothsayer Mirim'koa - On Spellhit - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Soothsayer Mirim'koa - Script - Say 0"),
(@ENTRY*100,9,1,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Soothsayer Mirim'koa - Script - Say 1"),
(@ENTRY*100,9,2,0,0,0,100,0,6000,6000,0,0,11,70009,0,0,0,0,0,1,0,0,0,0,0,0,0,"Soothsayer Mirim'koa - Script - Cast 'Soothsayer Kill Credit W'"),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Soothsayer Mirim'koa - Script - Say 2");
-- Soothsayer Mirim'koa
SET @ENTRY := 37174;
DELETE FROM `creature_text` WHERE `entry` IN (@ENTRY);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'Our land be a land of ice an'' snow.', 12, 0, 100, 396, 0, 0, 36963, 'Soothsayer Mirim''koa'),
(@ENTRY, 1, 0, 'But beneath the earth, child, there always be fire.', 12, 0, 100, 396, 0, 0, 36964, 'Soothsayer Mirim''koa'),
(@ENTRY, 2, 0, 'De spirit come from deep down to talk with Grik''nir.', 12, 0, 100, 396, 0, 0, 36965, 'Soothsayer Mirim''koa');
-- Frostmane Troll Whelps should kneel in front of Soothsayers
DELETE FROM `creature_addon` WHERE `guid` IN (305835,305836,305860,305862,305901,305902);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(305835,0,0,8,1,0, ''),(305836,0,0,8,1,0, ''),(305860,0,0,8,1,0, ''),(305862,0,0,8,1,0, ''),(305901,0,0,8,1,0, ''),(305902,0,0,8,1,0, '');
-- Player should have Trolling for Information: Troll Trigger Aura in Coldridge Valley if quest Trolling for Information is active
DELETE FROM `spell_area` WHERE `spell` IN (69991);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(69991,132,24489,24489,0,0,2,1,10,64);

-- Add spell click for Milo's Gyro
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=37198;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(37198, 70036, 0, 0);
-- Add missing VehicleId for Milo's Gyro
UPDATE `creature_template` SET `VehicleId`=581,`InhabitType`=4 WHERE `entry`=37198;

DELETE FROM `spell_script_names` WHERE `spell_id`=76143;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (76143, 'spell_low_health');
UPDATE `creature_template` SET `npcflag`=0,`unit_flags`=33288,`speed_run`=2.85714,`VehicleId`=581,`InhabitType`=4,`ScriptName`= 'npc_milos_gyro' WHERE `entry`=37198;
UPDATE `creature_template` SET `AIName`="", `ScriptName`= 'npc_wounded_coldridge_mountaineer' WHERE `entry`=37080;
UPDATE `creature_template` SET `unit_flags`=33555200,`InhabitType`=4 WHERE `entry`=37518;
UPDATE `creature_template` SET `HealthModifierExtra`=2 WHERE `entry` IN (37113,37169,37198,37518);

-- Hands Springsprocket SAI
SET @ENTRY := 6782;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,20,0,100,0,24490,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Hands Springsprocket - On Quest Reward - Say 0"),
(@ENTRY,0,1,0,19,0,100,0,24491,0,0,0,11,70047,0,0,0,0,0,7,0,0,0,0,0,0,0,"Hands Springsprocket - On Quest Accept - Cast 'Follow That Gyro-Copter - Quest Start'");
-- Hands Springsprocket text 
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, 'Alright, so you''re just going to head through this tunnel and whaaaaa....?', 12, 0, 100, 397, 0, 0, 37003, 'Hands Springsprocket');

-- Milo Geartwinge text
SET @ENTRY := 37518;
DELETE FROM `creature_text` WHERE `entry` IN (@ENTRY);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, '<Static>$bIs this thing on?  Hello?', 12, 7, 100, 0, 0, 0, 37115, 'Milo Geartwinge'),
(@ENTRY, 1, 0, 'Ahh, there you are.  Hello!  I figured that, while you''re flying to Kharanos, I''d give you some data about what''s going on outside of Coldridge Valley.', 12, 7, 100, 0, 0, 0, 37117, 'Milo Geartwinge'),
(@ENTRY, 2, 0, 'It seems you Coldridge folks are dreadfully under-informed about the events of the last few days.', 12, 7, 100, 0, 0, 0, 37118, 'Milo Geartwinge'),
(@ENTRY, 3, 0, 'If you thought you had problems with trolls in Coldridge, wait ''til you get to Kharanos!  That big cataclysm got the trolls all stirred up out here.', 12, 7, 100, 0, 0, 0, 37119, 'Milo Geartwinge'),
(@ENTRY, 4, 0, 'And if you''ll look to your left, you''ll see that the gnomes have retaken Gnomeregan.  Hooray for us!', 12, 7, 100, 0, 0, 0, 43112, 'Milo Geartwinge'),
(@ENTRY, 5, 0, 'There''s plenty else going on out here, too.  We''ve opened up the path to the airport, there''s rumors of Dark Irons in the east... oh, and I think something weird is going on with that dwarf king, Magni.  Might want to check it out.', 12, 7, 100, 0, 0, 0, 43113, 'Milo Geartwinge'),
(@ENTRY, 6, 0, 'And here we are!  Welcome to Kharanos!  Watch your step on the way out.', 12, 7, 100, 0, 0, 0, 43115, 'Milo Geartwinge');

-- Felix Whindlebolt
UPDATE `creature` SET `spawndist`=4,`MovementType`=1 WHERE `id`=8416;
UPDATE `creature_template` SET `npcflag`=643 WHERE `entry`=8416;
DELETE FROM `npc_vendor` WHERE `entry`=8416;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `VerifiedBuild`) VALUES
(8416, 1, 4540, 0, 0, 1, 23877),
(8416, 2, 159, 0, 0, 1, 23877),
(8416, 3, 4496, 0, 0, 1, 23877);

-- **** QUEST LINKING ****

-- Quest Linking
DELETE FROM `quest_template_addon` WHERE `ID` IN (24471,24474,24477,182,3361,24489,24491);
INSERT INTO `quest_template_addon` (`ID`,`AllowableClasses`,`PrevQuestID`,`SpecialFlags`) VALUES 
(24471,0,24469,0),(24474,0,24473,0),(24477,0,24473,0),(182,0,24487,0),(3361,0,24487,0),(24489,0,24487,0),(24491,0,24490,0);

-- Condition for source Quest accept condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=24473 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 24473, 0, 1, 8, 0, 24470, 0, 0, 0, 0, 0, '', 'Show quest Lockdown in Anvilmar if quest Give ''em What-For has been rewarded.'),
(19, 0, 24473, 0, 1, 8, 0, 24471, 0, 0, 0, 0, 0, '', 'Show quest Lockdown in Anvilmar if quest Aid for the Wounded has been rewarded.');

-- Condition for source Quest accept condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=24487 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 24487, 0, 1, 8, 0, 24475, 0, 0, 0, 0, 0, '', 'Show quest Whitebeard Needs Ye if quest All the Other Stuff has been rewarded.'),
(19, 0, 24487, 0, 1, 8, 0, 24486, 0, 0, 0, 0, 0, '', 'Show quest Whitebeard Needs Ye if quest Make Hay While the Sun Shines has been rewarded.');

-- Condition for source Quest accept condition type Quest rewarded "May be only 182 needed?"
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=218 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 218, 0, 1, 8, 0, 182, 0, 0, 0, 0, 0, '', 'Show quest Ice and Fire if quest The troll menace has been rewarded.'),
(19, 0, 218, 0, 1, 8, 0, 24489, 0, 0, 0, 0, 0, '', 'Show quest Ice and Fire if quest Trolling for information has been rewarded.');

-- Condition for source Quest accept condition type Quest taken, completed, or rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=24493 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 24493, 0, 1, 9, 0, 24492, 0, 0, 0, 0, 0, '', 'Show quest Don''t forget about us if quest Pack your bags has been taken.');

-- **** LOOT ****

-- Ragged Timber Wolf
UPDATE `creature` SET `spawndist`=10,`MovementType`=1 WHERE `id`=704;
DELETE FROM `creature_loot_template` WHERE `Entry`=704;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(704,1,11111,0.1,0,1,0,1,1, 'Reference Small Pouch'),
(704,62328,0,50,0,1,1,1,2, 'Shed Fur'),
(704,3300,0,50,0,1,1,1,1, 'Rabbit''s Foot');

-- Ragged Young Wolf
UPDATE `creature` SET `spawndist`=10,`MovementType`=1 WHERE `id`=705;
DELETE FROM `creature_loot_template` WHERE `Entry`=705;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(705,1,11111,0.1,0,1,0,1,1, 'Reference Small Pouch'),
(705,49748,0,100,1,1,1,1,1, 'Ragged Wolf Hide'),
(705,62328,0,50,0,1,2,1,2, 'Shed Fur'),
(705,3300,0,50,0,1,2,1,1, 'Rabbit''s Foot');

-- Frostmane Troll Whelp
UPDATE `creature` SET `spawndist`=6,`MovementType`=1 WHERE `guid` IN (305827,305843,305844,305845,305848,305849,305853,305864,305865,305868,305869,305871,305872,305894,305900,305903,305904,305905,305906,305909,305918);
DELETE FROM `creature_loot_template` WHERE `Entry`=706;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(706,1,11111,0.1,0,1,0,1,1, 'Reference Small Pouch'),
(706,2108,0,0.1,0,1,1,1,1, 'Frostmane Whelp Vest'),
(706,159,0,5,0,1,2,1,1, 'Refreshing Spring Water'),
(706,117,0,5,0,1,2,1,1, 'Tough Jerky');

-- Small Crag Boar
UPDATE `creature` SET `spawndist`=10,`MovementType`=1 WHERE `id`=708;
DELETE FROM `creature_loot_template` WHERE `Entry`=708;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(708,1,11111,0.1,0,1,0,1,1, 'Reference Small Pouch'),
(708,49747,0,100,1,1,1,1,1, 'Boar Haunch'),
(708,117,0,100,0,1,2,1,2, 'Tough Jerky'),
(708,771,0,5,0,1,3,1,1, 'Chipped Boar Tusk');

-- Rockjaw Invader
UPDATE `creature_template` SET `lootid`=0, `mingold`=1, `maxgold`=4 WHERE `entry`=37070;
DELETE FROM `creature_loot_template` WHERE `Entry`=37070;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(37070,1,11111,0.1,0,1,0,1,1, 'Reference Small Pouch'),
(37070,117,0,5,0,1,1,1,1, 'Tough Jerky');

-- Rockjaw Goon
UPDATE `creature` SET `spawndist`=6,`MovementType`=1 WHERE `id`=37073;
UPDATE `creature_template` SET `mingold`=1, `maxgold`=4 WHERE `entry`=37073;
DELETE FROM `creature_loot_template` WHERE `Entry`=37073;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(37073,1,11111,0.1,0,1,0,1,1, 'Reference Small Pouch'),
(37073,159,0,5,0,1,1,1,1, 'Refreshing Spring Water'),
(37073,117,0,5,0,1,1,1,1, 'Tough Jerky');

-- Rockjaw Scavenger
UPDATE `creature` SET `spawndist`=6,`MovementType`=1 WHERE `id`=37105;
UPDATE `creature_template` SET `mingold`=1, `maxgold`=8 WHERE `entry`=37105;
DELETE FROM `creature_loot_template` WHERE `Entry`=37105;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(37105,1,11111,0.1,0,1,0,1,1, 'Reference Small Pouch'),
(37105,49751,0,100,1,1,1,1,1, 'Priceless Rockjaw Artifact'),
(37105,117,0,5,0,1,2,1,1, 'Tough Jerky'),
(37105,2787,0,5,0,1,2,1,1, 'Trogg Dagger');

-- Frostmane Blade
UPDATE `creature_template` SET `mingold`=1, `maxgold`=5 WHERE `entry`=37507;
DELETE FROM `creature_loot_template` WHERE `Entry`=37507;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(37507,1,11111,0.1,0,1,0,1,1, 'Reference Small Pouch'),
(37507,159,0,5,0,1,1,1,2, 'Refreshing Spring Water');

-- Frostmane Novice
UPDATE `creature_template` SET `mingold`=1, `maxgold`=5 WHERE `entry`=946;
DELETE FROM `creature_loot_template` WHERE `Entry`=946;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(946,1,11111,0.1,0,1,0,1,1, 'Reference Small Pouch'),
(946,159,0,5,0,1,1,1,2, 'Refreshing Spring Water');

-- Grik'nir the Cold
UPDATE `creature_template` SET `lootid`=0, `mingold`=1, `maxgold`=6 WHERE `entry`=808;
DELETE FROM `creature_loot_template` WHERE `Entry`=808;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(808,1,11111,0.1,0,1,0,1,1, 'Reference Small Pouch');

-- Wayward Fire Elemental
UPDATE `creature_template` SET `mingold`=1, `maxgold`=4 WHERE `entry`=37112;
DELETE FROM `creature_loot_template` WHERE `Entry`=37112;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(37112,1,11111,0.1,0,1,0,1,1, 'Reference Small Pouch'),
(37112,42185,0,90,0,1,1,1,2, 'Inert Elemental Speck'),
(37112,55983,0,10,0,1,1,1,2, 'Inert Elemental Scintilla');

-- Rockjaw Raider
UPDATE `creature` SET `spawndist`=6,`MovementType`=1 WHERE `id`=1718;
UPDATE `creature_template` SET `mingold`=1, `maxgold`=5 WHERE `entry`=1718;
DELETE FROM `creature_loot_template` WHERE `Entry`=1718;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(1718,1,11111,0.1,0,1,0,1,1, 'Reference Small Pouch'),
(1718,2054,0,5,0,1,1,1,1, 'Trogg Hand Axe');

-- ***** PATHING *****
 
-- Pathing for Coldridge Mountaineer Entry: 853
SET @NPC := 305723;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-6176.249,`position_y`=371.8652,`position_z`=398.7436 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-6176.249,371.8652,398.7436,0,0,0,0,100,0),
(@PATH,2,-6168.106,383.9464,398.9707,0,0,0,0,100,0),
(@PATH,3,-6155.566,384.3036,395.5428,0,0,0,0,100,0),
(@PATH,4,-6130.428,383.7834,395.5438,0,0,0,0,100,0),
(@PATH,5,-6129.713,375.0988,395.5455,0,0,0,0,100,0),
(@PATH,6,-6129.713,375.0988,395.5455,0,0,0,0,100,0),
(@PATH,7,-6117.872,375.6216,395.5437,0,0,0,0,100,0),
(@PATH,8,-6104.917,375.0586,395.5427,0,0,0,0,100,0),
(@PATH,9,-6099.723,375.8936,395.5427,0,0,0,0,100,0),
(@PATH,10,-6099.202,377.1399,395.5427,0,0,0,0,100,0),
(@PATH,11,-6093.32,374.9961,395.5426,0,0,0,0,100,0),
(@PATH,12,-6087.973,379.6734,395.5426,0,0,0,0,100,0),
(@PATH,13,-6088.8,388.0612,395.5426,0,0,0,0,100,0),
(@PATH,14,-6094.015,395.5215,395.5421,0,0,0,0,100,0),
(@PATH,15,-6101.135,395.0081,395.5426,0,0,0,0,100,0),
(@PATH,16,-6115.752,393.5254,395.5427,0,0,0,0,100,0),
(@PATH,17,-6127.311,392.8422,395.5428,0,0,0,0,100,0),
(@PATH,18,-6130.358,383.4592,395.5439,0,0,0,0,100,0),
(@PATH,19,-6155.236,383.9091,395.5427,0,0,0,0,100,0),
(@PATH,20,-6166.908,383.7658,399.1538,0,0,0,0,100,0),
(@PATH,21,-6174.323,376.1232,398.3491,0,0,0,0,100,0),
(@PATH,22,-6176.717,370.4969,398.7719,0,0,0,0,100,0),
(@PATH,23,-6178.788,365.7165,398.6329,0,0,0,0,100,0),
(@PATH,24,-6178.788,365.7165,398.6329,3.01942,10000,0,0,100,0);

-- Pathing for Coldridge Mountaineer Entry: 853
SET @NPC := 305747;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-6111.192,`position_y`=398.8487,`position_z`=395.5427 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-6111.192,398.8487,395.5427,0,0,0,0,100,0),
(@PATH,2,-6111.192,398.8487,395.5427,0.8552117,35000,0,0,100,0),
(@PATH,3,-6109.585,390.3089,395.5427,0,0,0,0,100,0),
(@PATH,4,-6108.307,376.9665,395.5429,0,0,0,0,100,0),
(@PATH,5,-6098.929,372.7513,395.5417,0,0,0,0,100,0),
(@PATH,6,-6089.93,366.9319,395.5423,0,0,0,0,100,0),
(@PATH,7,-6081.341,376.9561,393.5983,0,0,0,0,100,0),
(@PATH,8,-6080.26,383.4846,393.5993,0,0,0,0,100,0),
(@PATH,9,-6075.878,384.1705,393.602,0,0,0,0,100,0),
(@PATH,10,-6065.815,383.7609,393.5985,0,10000,0,0,100,0),
(@PATH,11,-6077.331,384.5051,393.6012,0,0,0,0,100,0),
(@PATH,12,-6081.07,393.0945,393.5982,0,0,0,0,100,0),
(@PATH,13,-6089.555,400.583,395.5425,0,0,0,0,100,0),
(@PATH,14,-6094.961,397.0799,395.5412,0,0,0,0,100,0),
(@PATH,15,-6104.308,396.5705,395.5427,0,0,0,0,100,0),
(@PATH,16,-6108.483,398.1342,395.5427,0,0,0,0,100,0);

-- Pathing for Coldridge Mountaineer Entry: 853
SET @NPC := 305619;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-6236.734,`position_y`=321.1015,`position_z`=382.7533 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-6236.734,321.1015,382.7533,0,0,0,0,100,0),
(@PATH,2,-6248.776,318.549,382.7938,0,0,0,0,100,0),
(@PATH,3,-6255.72,310.0686,383.2325,0,0,0,0,100,0),
(@PATH,4,-6254.481,290.2085,383.7552,0,0,0,0,100,0),
(@PATH,5,-6253.693,267.7241,385.8227,0,0,0,0,100,0),
(@PATH,6,-6258.855,243.109,392.0644,0,0,0,0,100,0),
(@PATH,7,-6266.325,224.8653,399.2339,0,0,0,0,100,0),
(@PATH,8,-6264.504,208.3608,406.2283,0,0,0,0,100,0),
(@PATH,9,-6264.217,191.1372,412.7482,0,0,0,0,100,0),
(@PATH,10,-6253.904,175.2252,419.1656,0,0,0,0,100,0),
(@PATH,11,-6237.221,160.9762,426.1903,0,0,0,0,100,0),
(@PATH,12,-6253.904,175.2252,419.1656,0,0,0,0,100,0),
(@PATH,13,-6264.217,191.1372,412.7482,0,0,0,0,100,0),
(@PATH,14,-6264.516,208.1367,406.4981,0,0,0,0,100,0),
(@PATH,15,-6266.325,224.8653,399.2339,0,0,0,0,100,0),
(@PATH,16,-6258.855,243.109,392.0644,0,0,0,0,100,0),
(@PATH,17,-6253.693,267.7241,385.8227,0,0,0,0,100,0),
(@PATH,18,-6254.481,290.2085,383.7552,0,0,0,0,100,0),
(@PATH,19,-6255.72,310.0686,383.2325,0,0,0,0,100,0),
(@PATH,20,-6248.776,318.549,382.7938,0,0,0,0,100,0);

-- Pathing for Coldridge Mountaineer Entry: 853
SET @NPC := 305714;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-6199.655,`position_y`=378.7022,`position_z`=390.2959 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,257,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-6199.655,378.7022,390.2959,0,0,0,0,100,0),
(@PATH,2,-6184.346,382.7531,394.6538,0,0,0,0,100,0),
(@PATH,3,-6181.535,384.817,395.6377,0.05235988,8000,0,0,100,0),
(@PATH,4,-6187.376,381.0375,393.6505,0,0,0,0,100,0),
(@PATH,5,-6210.335,374.3992,387.833,0,0,0,0,100,0),
(@PATH,6,-6221.236,358.7942,385.0003,0,0,0,0,100,0),
(@PATH,7,-6225.12,345.3553,383.6516,0,6000,0,0,100,0),
(@PATH,8,-6218.737,364.0237,385.6419,0,0,0,0,100,0),
(@PATH,9,-6213.269,372.9998,387.2403,0,0,0,0,100,0);

-- Fix some positions for Coldridge Mountaineer Entry: 853
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-6213.199,`position_y`=333.5783,`position_z`=383.9143,`orientation`=3.304624 WHERE `guid`=305625;

-- Pathing for Sten Stoutarm Entry: 658
SET @NPC := 305672;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-6240.077,`position_y`=347.3854,`position_z`=383.8769 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-6240.077,347.3854,383.8769,0,0,0,0,100,0),
(@PATH,2,-6243.069,345.6754,383.3976,0,0,0,0,100,0),
(@PATH,3,-6229.55,346.6632,383.6837,0,0,0,0,100,0);

-- Pathing for Rockjaw Goon Entry: 37073
SET @NPC := 305957;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-6270.788,`position_y`=450.4896,`position_z`=386.2929 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-6270.788,450.4896,386.2929,0,0,1,0,100,0),
(@PATH,2,-6287.556,449.6597,385.9057,0,0,1,0,100,0),
(@PATH,3,-6303.198,447.1094,385.8286,0,0,1,0,100,0),
(@PATH,4,-6318.872,438.5104,381.3597,0,0,1,0,100,0),
(@PATH,5,-6329.821,426.8299,379.619,0,0,1,0,100,0),
(@PATH,6,-6342.58,416.6111,377.8814,0,0,1,0,100,0),
(@PATH,7,-6361.229,401.8993,375.9354,0,0,1,0,100,0),
(@PATH,8,-6364.457,384.5451,379.4248,0,0,1,0,100,0),
(@PATH,9,-6363.353,364.7639,378.5156,0,0,1,0,100,0),
(@PATH,10,-6359.606,346.5,379.5487,0,0,1,0,100,0),
(@PATH,11,-6366.278,339.2188,384.7966,0,0,1,0,100,0),
(@PATH,12,-6372.587,335.2361,386.0209,0,0,1,0,100,0),
(@PATH,13,-6379.397,320.7899,386.0924,0,0,1,0,100,0),
(@PATH,14,-6384.077,300.4236,386.9188,0,0,1,0,100,0),
(@PATH,15,-6384.462,281.2691,389.7853,0,0,1,0,100,0),
(@PATH,16,-6384.077,300.4236,386.9188,0,0,1,0,100,0),
(@PATH,17,-6379.397,320.7899,386.0924,0,0,1,0,100,0),
(@PATH,18,-6372.587,335.2361,386.0209,0,0,1,0,100,0),
(@PATH,19,-6366.278,339.2188,384.7966,0,0,1,0,100,0),
(@PATH,20,-6359.606,346.5,379.5487,0,0,1,0,100,0),
(@PATH,21,-6363.353,364.7639,378.5156,0,0,1,0,100,0),
(@PATH,22,-6364.457,384.5451,379.4248,0,0,1,0,100,0),
(@PATH,23,-6361.229,401.8993,375.9354,0,0,1,0,100,0),
(@PATH,24,-6342.58,416.6111,377.8814,0,0,1,0,100,0),
(@PATH,25,-6329.821,426.8299,379.619,0,0,1,0,100,0),
(@PATH,26,-6318.872,438.5104,381.3597,0,0,1,0,100,0),
(@PATH,27,-6303.198,447.1094,385.8286,0,0,1,0,100,0),
(@PATH,28,-6287.556,449.6597,385.9057,0,0,1,0,100,0);

-- Pathing for Rockjaw Scavenger Entry: 37105
SET @NPC := 305765;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-6228.103,`position_y`=492.9219,`position_z`=386.2135 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-6228.103,492.9219,386.2135,0,0,0,0,100,0),
(@PATH,2,-6236.009,489.033,386.3325,0,0,0,0,100,0),
(@PATH,3,-6250.165,489.3854,386.6602,0,0,0,0,100,0),
(@PATH,4,-6262.401,495.342,386.532,0,0,0,0,100,0),
(@PATH,5,-6278.573,502.7031,386.2361,0,0,0,0,100,0),
(@PATH,6,-6287.948,496.2431,386.4848,0,0,0,0,100,0),
(@PATH,7,-6292.592,483.9479,386.1232,0,0,0,0,100,0),
(@PATH,8,-6286.639,472.2726,386.1232,0,0,0,0,100,0),
(@PATH,9,-6276.42,462.9496,386.0429,0,0,0,0,100,0),
(@PATH,10,-6253.809,462.2917,385.9406,0,0,0,0,100,0),
(@PATH,11,-6244.913,480.0208,386.6752,0,0,0,0,100,0),
(@PATH,12,-6243.293,495.9514,387.2115,0,0,0,0,100,0),
(@PATH,13,-6253.682,506.2517,386.2361,0,0,0,0,100,0),
(@PATH,14,-6268.397,537.2813,386.2361,0,0,0,0,100,0),
(@PATH,15,-6257.287,545.0729,386.2361,0,0,0,0,100,0),
(@PATH,16,-6236.635,538.7257,386.2361,0,0,0,0,100,0),
(@PATH,17,-6231.096,529.3212,386.3161,0,0,0,0,100,0),
(@PATH,18,-6219.79,507.2483,386.1911,0,0,0,0,100,0);

-- Pathing for Wayward Fire Elemental Entry: 37112
SET @NPC := 305952;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-6490.104,`position_y`=327.4583,`position_z`=368.9209 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-6490.104,327.4583,368.9209,0,0,0,0,100,0),
(@PATH,2,-6492.639,323.1545,368.9242,0,0,0,0,100,0),
(@PATH,3,-6501.009,322.6146,368.3976,0,0,0,0,100,0),
(@PATH,4,-6504.955,326.5087,367.9143,0,0,0,0,100,0),
(@PATH,5,-6505.262,331.2865,367.9337,0,0,0,0,100,0),
(@PATH,6,-6506.288,335.0955,368.5313,0,0,0,0,100,0),
(@PATH,7,-6503.399,337.2014,368.2807,0,0,0,0,100,0),
(@PATH,8,-6498.719,336.8004,368.103,0,0,0,0,100,0),
(@PATH,9,-6492.865,339.0395,368.3209,0,0,0,0,100,0),
(@PATH,10,-6484.156,338.507,369.1332,0,0,0,0,100,0),
(@PATH,11,-6485.476,331.3507,369.1438,0,0,0,0,100,0);

-- Pathing for Frostmane Blade Entry: 37507
SET @NPC := 305919;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-6525.925,`position_y`=362.679,`position_z`=388.3134 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-6525.925,362.679,388.3134,0,0,0,0,100,0),
(@PATH,2,-6525.925,362.679,388.3134,5.061455,60000,0,0,100,0),
(@PATH,3,-6539.408,366.641,384.7058,0,0,0,0,100,0),
(@PATH,4,-6539.408,366.641,384.7058,4.24115,120000,0,0,100,0);

-- Pathing for Frostmane Blade Entry: 37507
SET @NPC := 305882;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-6517.343,`position_y`=324.8754,`position_z`=373.6173 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-6517.343,324.8754,373.6173,0,0,0,0,100,0),
(@PATH,2,-6508.921,309.0279,371.1073,0,0,0,0,100,0),
(@PATH,3,-6498.93,302.8571,370.0655,0,0,0,0,100,0),
(@PATH,4,-6489.044,308.3578,371.6581,0,0,0,0,100,0),
(@PATH,5,-6477.571,329.3181,374.7681,0,0,0,0,100,0),
(@PATH,6,-6473.479,350.6166,378.0409,0,0,0,0,100,0),
(@PATH,7,-6465.14,362.1947,377.9243,0,0,0,0,100,0),
(@PATH,8,-6472.385,386.2589,381.7826,0,0,0,0,100,0),
(@PATH,9,-6465.14,362.1947,377.9243,0,0,0,0,100,0),
(@PATH,10,-6473.479,350.6166,378.0409,0,0,0,0,100,0),
(@PATH,11,-6477.571,329.3181,374.7681,0,0,0,0,100,0),
(@PATH,12,-6489.044,308.3578,371.6581,0,0,0,0,100,0),
(@PATH,13,-6498.93,302.8571,370.0655,0,0,0,0,100,0),
(@PATH,14,-6508.75,308.9225,371.0417,0,0,0,0,100,0);

-- Pathing for Frostmane Blade Entry: 37507
SET @NPC := 305889;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-6541.569,`position_y`=377.3424,`position_z`=381.6454 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-6541.569,377.3424,381.6454,0,0,0,0,100,0),
(@PATH,2,-6539.766,386.7738,381.7602,0,0,0,0,100,0),
(@PATH,3,-6528.167,402.9709,382.6694,0,0,0,0,100,0),
(@PATH,4,-6524.86,419.7674,386.1845,0,0,0,0,100,0),
(@PATH,5,-6535.516,427.4556,386.1728,0,0,0,0,100,0),
(@PATH,6,-6565.096,405.5444,386.5844,0,0,0,0,100,0),
(@PATH,7,-6579.694,405.9558,388.2099,0,0,0,0,100,0),
(@PATH,8,-6601.643,392.6048,388.606,0,0,0,0,100,0),
(@PATH,9,-6601.643,392.6048,388.606,3.141593,50000,0,0,100,0),
(@PATH,10,-6570.963,410.183,387.1868,0,0,0,0,100,0),
(@PATH,11,-6560.317,409.9302,386.0698,0,0,0,0,100,0),
(@PATH,12,-6538.356,423.8044,385.929,0,0,0,0,100,0),
(@PATH,13,-6526.583,423.2707,386.4318,0,0,0,0,100,0),
(@PATH,14,-6528.167,402.9709,382.6694,0,0,0,0,100,0),
(@PATH,15,-6539.631,386.9624,381.7784,0,0,0,0,100,0),
(@PATH,16,-6541.569,377.3424,381.6454,0,0,0,0,100,0),
(@PATH,17,-6526.955,380.4408,382.7512,0,0,0,0,100,0),
(@PATH,18,-6512.76,382.5737,384.9301,0,0,0,0,100,0),
(@PATH,19,-6499.151,391.222,385.1525,0,0,0,0,100,0),
(@PATH,20,-6512.76,382.5737,384.9301,0,0,0,0,100,0),
(@PATH,21,-6526.955,380.4408,382.7512,0,0,0,0,100,0);

-- Pathing for Coldridge Citizen Entry: 37218
SET @NPC := 305653;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-6061.054,`position_y`=370.4045,`position_z`=393.5967 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-6061.054,370.4045,393.5967,0,0,0,0,100,0),
(@PATH,2,-6057.432,370.1476,393.5966,0,0,0,0,100,0),
(@PATH,3,-6052.295,370.1024,395.2629,0,0,0,0,100,0),
(@PATH,4,-6052.057,373.2813,395.2629,0,0,0,0,100,0),
(@PATH,5,-6052.272,378.2083,398.7954,0,0,0,0,100,0),
(@PATH,6,-6052.104,380.9879,398.8738,0,0,0,0,100,0),
(@PATH,7,-6052.057,373.2813,395.2629,0,0,0,0,100,0),
(@PATH,8,-6052.295,370.1024,395.2629,0,0,0,0,100,0),
(@PATH,9,-6057.432,370.1476,393.5966,0,0,0,0,100,0),
(@PATH,10,-6061.054,370.4045,393.5967,0,0,0,0,100,0),
(@PATH,11,-6061.035,372.8733,393.597,0,0,0,0,100,0),
(@PATH,12,-6061.66,393.1667,392.7605,0,0,0,0,100,0),
(@PATH,13,-6068.019,393.3681,392.7611,0,0,0,0,100,0),
(@PATH,14,-6067.913,390.6806,392.7626,0,0,0,0,100,0),
(@PATH,15,-6068.399,383.9653,393.6007,0,0,0,0,100,0),
(@PATH,16,-6079.957,383.8281,393.5995,0,0,0,0,100,0),
(@PATH,17,-6081.077,392.5538,393.5983,0,0,0,0,100,0),
(@PATH,18,-6088.329,399.7439,395.5298,0,0,0,0,100,0),
(@PATH,19,-6096.2,397.6076,395.5403,0,0,0,0,100,0),
(@PATH,20,-6091.116,392.2813,395.5427,0,0,0,0,100,0),
(@PATH,21,-6087.005,383.4844,395.5427,0,0,0,0,100,0),
(@PATH,22,-6090.012,377.3542,395.5426,0,0,0,0,100,0),
(@PATH,23,-6097.508,368.951,395.5391,0,0,0,0,100,0),
(@PATH,24,-6110.118,372.7865,395.5429,0,0,0,0,100,0),
(@PATH,25,-6120.653,375.1858,395.5436,0,0,0,0,100,0),
(@PATH,26,-6129.929,375.7483,395.5455,0,0,0,0,100,0),
(@PATH,27,-6130.132,383.7552,395.5438,0,0,0,0,100,0),
(@PATH,28,-6140.628,384.1701,395.5427,0,0,0,0,100,0),
(@PATH,29,-6130.132,383.7552,395.5438,0,0,0,0,100,0),
(@PATH,30,-6129.929,375.7483,395.5455,0,0,0,0,100,0),
(@PATH,31,-6120.653,375.1858,395.5436,0,0,0,0,100,0),
(@PATH,32,-6110.118,372.7865,395.5429,0,0,0,0,100,0),
(@PATH,33,-6097.653,368.7882,395.5394,0,0,0,0,100,0),
(@PATH,34,-6090.012,377.3542,395.5426,0,0,0,0,100,0),
(@PATH,35,-6087.005,383.4844,395.5427,0,0,0,0,100,0),
(@PATH,36,-6091.116,392.2813,395.5427,0,0,0,0,100,0),
(@PATH,37,-6096.2,397.6076,395.5403,0,0,0,0,100,0),
(@PATH,38,-6088.337,399.7517,395.5428,0,0,0,0,100,0),
(@PATH,39,-6081.077,392.5538,393.5983,0,0,0,0,100,0),
(@PATH,40,-6079.957,383.8281,393.5995,0,0,0,0,100,0),
(@PATH,41,-6068.558,383.9634,393.6003,0,0,0,0,100,0),
(@PATH,42,-6067.813,389.4774,393.5965,0,0,0,0,100,0),
(@PATH,43,-6068.019,393.3681,392.7611,0,0,0,0,100,0),
(@PATH,44,-6061.66,393.1667,392.7605,0,0,0,0,100,0),
(@PATH,45,-6061.182,373.7422,392.7637,0,0,0,0,100,0);

-- Pathing for Coldridge Citizen Entry: 37218
SET @NPC := 305663;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-6095.628,`position_y`=368.9601,`position_z`=395.5391 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-6095.628,368.9601,395.5391,0,0,0,0,100,0),
(@PATH,2,-6098.979,365.1076,395.5388,0,0,0,0,100,0),
(@PATH,3,-6102.101,363.6146,395.5403,0,20000,0,0,100,0),
(@PATH,4,-6097.103,366.309,395.5379,0,0,0,0,100,0),
(@PATH,5,-6088.288,368.6076,395.5083,0,0,0,0,100,0),
(@PATH,6,-6081.212,374.7552,393.9032,0,0,0,0,100,0),
(@PATH,7,-6075.092,382.6823,393.6022,0,0,0,0,100,0),
(@PATH,8,-6070.757,382.8212,393.6023,0,0,0,0,100,0),
(@PATH,9,-6066.912,389.3264,393.5973,0,0,0,0,100,0),
(@PATH,10,-6067.55,394.507,392.7603,0,0,0,0,100,0),
(@PATH,11,-6067.019,399.5486,392.7575,0,0,0,0,100,0),
(@PATH,12,-6064.043,399.7361,392.7574,0,0,0,0,100,0),
(@PATH,13,-6058.082,398.151,392.7577,0,5000,0,0,100,0),
(@PATH,14,-6057.72,398.269,392.7576,0,0,0,0,100,0),
(@PATH,15,-6064.63,399.9566,392.7573,0,0,0,0,100,0),
(@PATH,16,-6067.635,399.6285,392.7575,0,0,0,0,100,0),
(@PATH,17,-6067.972,393.3299,392.7611,0,0,0,0,100,0),
(@PATH,18,-6067.628,390.5486,392.7626,0,0,0,0,100,0),
(@PATH,19,-6067.795,389.5,393.5964,0,0,0,0,100,0),
(@PATH,20,-6070.247,385.4531,393.6023,0,0,0,0,100,0),
(@PATH,21,-6072.054,382.9757,393.5993,0,0,0,0,100,0),
(@PATH,22,-6074.472,382.8073,393.6026,0,0,0,0,100,0),
(@PATH,23,-6076.022,385.9809,393.6023,0,0,0,0,100,0),
(@PATH,24,-6077.537,385.8871,393.6013,0,0,0,0,100,0),
(@PATH,25,-6078.624,381.4531,393.5999,0,0,0,0,100,0),
(@PATH,26,-6077.719,378.4479,393.5998,0,0,0,0,100,0),
(@PATH,27,-6080.438,375.6858,393.5983,0,0,0,0,100,0),
(@PATH,28,-6088.111,368.9462,395.461,0,0,0,0,100,0),
(@PATH,29,-6095.628,368.9601,395.5391,0,0,0,0,100,0);

-- Pathing for Jona Ironstock Entry: 37087
SET @NPC := 305738;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-6097.097,`position_y`=394.3993,`position_z`=395.5413 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-6097.097,394.3993,395.5413,0,0,0,0,100,0),
(@PATH,2,-6101.299,393.5573,395.5432,0,0,0,0,100,0),
(@PATH,3,-6105.891,389.401,395.5427,0,0,0,0,100,0),
(@PATH,4,-6107.838,384.8837,395.5426,0,0,0,0,100,0),
(@PATH,5,-6106.488,378.3854,395.5428,0,0,0,0,100,0),
(@PATH,6,-6103.127,374.6597,395.5427,0,0,0,0,100,0),
(@PATH,7,-6097.207,372.309,395.5406,0,0,0,0,100,0),
(@PATH,8,-6091.91,375.0504,395.5425,0,0,0,0,100,0),
(@PATH,9,-6087.655,378.9861,395.5426,0,0,0,0,100,0),
(@PATH,10,-6087.113,384.0518,395.5427,0,0,0,0,100,0),
(@PATH,11,-6088.327,388.9271,395.5426,0,0,0,0,100,0),
(@PATH,12,-6091.981,392.0174,395.5427,0,0,0,0,100,0);

DELETE FROM `creature_template_addon` WHERE `entry`=37177;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (37177,0,0,0,257,375, '');

UPDATE `creature` SET `spawndist`=5,`MovementType`=1,`position_x`=-6241.177,`position_y`=338.2954,`position_z`=382.8228,`orientation`=2.951381 WHERE `guid`=305623;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-6218.82,`position_y`=322.102,`position_z`=383.3183,`orientation`=2.242454 WHERE `guid`=305624;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-6283.09,`position_y`=318.9844,`position_z`=376.5987,`orientation`=2.890162 WHERE `guid`=305628;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-6306.274,`position_y`=324.5938,`position_z`=378.0281,`orientation`=2.897247 WHERE `guid`=305632;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-6281.86,`position_y`=358.5567,`position_z`=379.8781,`orientation`=2.701885 WHERE `guid`=305677;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-6297.262,`position_y`=370.6962,`position_z`=379.3469,`orientation`=2.897247 WHERE `guid`=305678;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-6293.564,`position_y`=346.1424,`position_z`=376.8027,`orientation`=2.897247 WHERE `guid`=305679;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-6277.412,`position_y`=372.2431,`position_z`=382.2664,`orientation`=2.443461 WHERE `guid`=305697;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-6277.691,`position_y`=388.842,`position_z`=381.0859,`orientation`=2.897247 WHERE `guid`=305698;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-6257.236,`position_y`=368.9566,`position_z`=384.1455,`orientation`=2.918881 WHERE `guid`=305700;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-6255.87,`position_y`=390.8611,`position_z`=383.2173,`orientation`=3.384588 WHERE `guid`=305707;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-6281.389,`position_y`=398.2118,`position_z`=381.787,`orientation`=2.897247 WHERE `guid`=305708;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-6234.465,`position_y`=413.2674,`position_z`=386.8777,`orientation`=2.897247 WHERE `guid`=305716;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0,`position_x`=-6263.208,`position_y`=416.4167,`position_z`=385.5544,`orientation`=2.897247 WHERE `guid`=305676;

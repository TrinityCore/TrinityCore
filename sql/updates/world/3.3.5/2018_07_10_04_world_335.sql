-- Stonesplinter Trogg
UPDATE `smart_scripts` SET `event_chance`=15 WHERE `entryorguid` IN (1161,1162,1172,1202,1163,1166,1197,1167,1165,1393,1174,1175,1177,1173,1169,1178,1181) AND `source_type`=0 AND `id`=0;

-- Forest Lurker
DELETE FROM `smart_scripts` WHERE `entryorguid`=1195 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1195,0,0,0,25,0,100,0,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forest Lurker - On Reset - Cast 'Poison Proc'");

-- Cliff Lurker
DELETE FROM `smart_scripts` WHERE `entryorguid`=1184 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1184,0,0,0,25,0,100,0,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cliff Lurker - On Reset - Cast 'Poison Proc'");

-- Wood Lurker
DELETE FROM `smart_scripts` WHERE `entryorguid`=1185 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1185,0,0,0,25,0,100,0,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wood Lurker - On Reset - Cast 'Poison Proc'");

-- Mountain Boar
UPDATE `smart_scripts` SET `event_chance`=100 WHERE `entryorguid` IN (1190,1191,1192,1119) AND `source_type`=0 AND `id`=0;

-- Tunnel Rat Kobold
DELETE FROM `creature_text` WHERE `CreatureID` IN (1172,1202,1174,1175,1177,1173,1169) AND `GroupID`=0 AND `ID`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1172,0,2,"You no take candle!",12,0,100,0,0,0,1868,0,"Tunnel Rat Vermin"),
(1202,0,2,"You no take candle!",12,0,100,0,0,0,1868,0,"Tunnel Rat Kobold"),
(1174,0,2,"You no take candle!",12,0,100,0,0,0,1868,0,"Tunnel Rat Geomancer"),
(1175,0,2,"You no take candle!",12,0,100,0,0,0,1868,0,"Tunnel Rat Digger"),
(1177,0,2,"You no take candle!",12,0,100,0,0,0,1868,0,"Tunnel Rat Surveyor"),
(1173,0,2,"You no take candle!",12,0,100,0,0,0,1868,0,"Tunnel Rat Scout"),
(1169,0,2,"Never cross a Dark Iron, $C.",12,0,100,0,0,0,1934,0,"Dark Iron Insurgent");

-- Tunnel Rat Kobold
DELETE FROM `creature_text` WHERE `CreatureID`=1202 AND `GroupID`=2; -- Remove wrong texts

DELETE FROM `smart_scripts` WHERE `entryorguid`=1202 AND `source_type`=0 AND `id` IN (1,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1202,0,1,0,25,0,100,0,0,0,0,0,0,11,8876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Kobold - On Reset - Cast 'Thrash'");

-- Tunnel Rat Forager
DELETE FROM `smart_scripts` WHERE `entryorguid`=1176 AND `source_type`=0 AND `ID` IN (0,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1176,0,0,0,0,0,100,0,5000,9000,17000,21000,0,11,7365,2,0,0,0,0,2,0,0,0,0,0,0,0,"Tunnel Rat Forager - In Combat - Cast 'Bottle of Poison'"),
(1176,0,2,0,4,0,15,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Forager - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1176;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1176,0,0,"Yip! Me kill!",12,0,100,0,0,0,1920,0,"Tunnel Rat Forager"),
(1176,0,1,"Me no run from $C like you!",12,0,100,0,0,0,1921,0,"Tunnel Rat Forager"),
(1176,0,2,"You no take candle!",12,0,100,0,0,0,1868,0,"Tunnel Rat Forager");

-- Stonesplinter Skullthumper
DELETE FROM `smart_scripts` WHERE `entryorguid`=1163 AND `source_type`=0 AND `ID`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1163,0,1,0,0,0,100,0,5000,9000,10000,14000,0,11,1776,2,0,0,0,0,2,0,0,0,0,0,0,0,"Stonesplinter Skullthumper - In Combat - Cast 'Gouge'");

-- Stonesplinter Seer
UPDATE `smart_scripts` SET `event_param3`=3000, `event_param4`=5000 WHERE `entryorguid`=1166 AND `source_type`=0 AND `id`=1;

-- Stonesplinter Shaman
DELETE FROM `smart_scripts` WHERE `entryorguid`=1197 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1197,0,1,0,14,0,100,0,160,20,18000,35000,0,11,547,0,0,0,0,0,7,0,0,0,0,0,0,0,"Stonesplinter Shaman - Friendly At 160 Health - Cast 'Healing Wave'");

-- Stonesplinter Bonesnapper
DELETE FROM `smart_scripts` WHERE `entryorguid`=1164 AND `source_type`=0 AND `id` IN (0,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1164,0,0,0,0,0,100,0,5000,7000,15000,19000,0,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonesplinter Bonesnapper - In Combat - Cast 'Strike'"),
(1164,0,2,0,4,0,15,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rockjaw Backbreaker - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1164;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1164,0,0,"Crush!",12,0,100,0,0,0,1913,0,"Stonesplinter Bonesnapper"),
(1164,0,1,"Kill!",12,0,100,0,0,0,1914,0,"Stonesplinter Bonesnapper"),
(1164,0,2,"Destroy!",12,0,100,0,0,0,1915,0,"Stonesplinter Bonesnapper");

-- Grawmug
DELETE FROM `smart_scripts` WHERE `entryorguid`=1205 AND `source_type`=0 AND `id` IN (0,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1205,0,0,0,0,0,100,0,3000,5000,8000,12000,0,11,3229,0,0,0,0,0,9,0,0,30,0,0,0,0,"Grawmug - In Combat - Cast 'Quick Bloodlust'"),
(1205,0,2,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grawmug - On Aggro - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=1205;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1205,0,0,"A $C called $n? You'll make a fine breakfast!",12,0,100,0,0,0,444,0,"Grawmug"),
(1205,0,1,"Weak $C! You are no match for the Stonesplinter Tribe!",12,0,100,0,0,0,443,0,"Grawmug"),
(1205,0,2,"The only good $R is a dead $R!",12,0,100,0,0,0,447,0,"Grawmug"),
(1205,0,3,"The Stonesplinter Tribe shall see to your doom!",12,0,100,0,0,0,445,0,"Grawmug"),
(1205,0,4,"Die, $R!  These lands belong to the Stonesplinter Tribe!",12,0,100,0,0,0,446,0,"Grawmug"),
(1205,0,5,"The Loch belongs to the Stonesplinter Tribe now, $n!  Now die!",12,0,100,0,0,0,448,0,"Grawmug");

-- Gnasher
DELETE FROM `smart_scripts` WHERE `entryorguid`=1206 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1206,0,0,0,25,0,100,0,0,0,0,0,0,11,3394,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gnasher - On Reset - Cast 'Consume Flesh'");

-- Brawler
DELETE FROM `smart_scripts` WHERE `entryorguid`=1207 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1207,0,0,0,0,0,100,0,5000,7000,8000,11000,0,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Brawler - In Combat - Cast 'Backhand'");

-- Stonesplinter Digger
DELETE FROM `smart_scripts` WHERE `entryorguid`=1167 AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1167,0,1,0,4,0,100,0,0,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Digger - On Aggro - Cast 'Defensive Stance'"),
(1167,0,2,0,0,0,100,0,5000,8000,10000,16000,0,11,7386,2,0,0,0,0,2,0,0,0,0,0,0,0,"Stonesplinter Digger - In Combat - Cast 'Sunder Armor'");

-- Stonesplinter Geomancer
DELETE FROM `smart_scripts` WHERE `entryorguid`=1165 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1165,0,1,0,0,0,100,0,1000,3000,13000,17000,0,11,4979,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonesplinter Geomancer - In Combat - Cast 'Quick Flame Ward'");

-- Loch Crocolisk
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1693;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1693 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1693,0,0,0,25,0,100,0,0,0,0,0,0,11,12787,0,0,0,0,0,1,0,0,0,0,0,0,0,"Loch Crocolisk - On Reset - Cast 'Thrash'");

-- Young Threshadon
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1224;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1224 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1224,0,0,0,25,0,100,0,0,0,0,0,0,11,3417,0,0,0,0,0,1,0,0,0,0,0,0,0,"Young Threshadon - On Reset - Cast 'Thrash'");

-- Tunnel Rat Geomancer
DELETE FROM `smart_scripts` WHERE `entryorguid`=1174 AND `source_type`=0 AND `id` IN (1,2,3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1174,0,1,0,4,0,100,0,0,0,0,0,0,11,134,2,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Geomancer - On Aggro - Cast 'Fire Shield'"),
(1174,0,2,0,0,0,100,0,1000,3000,9000,11000,0,11,4979,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Geomancer - In Combat - Cast 'Quick Flame Ward'"),
(1174,0,3,0,0,0,100,0,4000,7000,10000,15000,0,11,2136,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tunnel Rat Geomancer - In Combat - Cast 'Fire Blast'");

-- Tunnel Rat Digger
DELETE FROM `smart_scripts` WHERE `entryorguid`=1175 AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1175,0,1,0,4,0,100,0,0,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunnel Rat Digger - On Aggro - Cast 'Defensive Stance'"),
(1175,0,2,0,0,0,100,0,5000,8000,14000,18000,0,11,7386,2,0,0,0,0,2,0,0,0,0,0,0,0,"Tunnel Rat Digger - In Combat - Cast 'Sunder Armor'");

-- Grizlak
DELETE FROM `smart_scripts` WHERE `entryorguid`=1425 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1425,0,0,0,14,0,100,0,150,40,20000,25000,0,11,6074,0,0,0,0,0,7,0,0,0,0,0,0,0,"Grizlak - Friendly At 150 Health - Cast 'Renew'");

-- Lord Condar
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14268;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14268 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(14268,0,0,0,25,0,100,0,0,0,0,0,0,11,4317,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Condar - On Reset - Cast 'Eye Peck'");

-- Shanda the Spinner
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=14266;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14266 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14266,0,0,0,25,0,100,0,0,0,0,0,0,11,13299,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shanda the Spinner - On Reset - Cast 'Poison Proc'"),
(14266,0,1,0,9,0,100,0,0,30,9000,12000,0,11,12023,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shanda the Spinner - Within 0-30 Range - Cast 'Web'");

-- Emogg the Crusher
DELETE FROM `smart_scripts` WHERE `entryorguid`=14267 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`,`event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14267,0,0,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Emogg the Crusher - On Aggro - Say Line 0"),
(14267,0,1,0,0,0,100,0,8000,11000,22000,28000,0,11,19482,2,0,0,0,0,1,0,0,0,0,0,0,0,"Emogg the Crusher - In Combat - Cast 'War Stomp'"),
(14267,0,2,0,2,0,100,1,0,30,0,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Emogg the Crusher - Between 0-30% Health - Cast Enrage (No Repeat)"),
(14267,0,3,0,2,0,100,1,0,30,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Emogg the Crusher - Between 0-30% Health - Say Line 1 (No Repeat)");

DELETE FROM `creature_text` WHERE `CreatureID`=14267 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(14267,1,0,"%s becomes enraged!",16,0,100,0,0,0,10677,0,"Rage Scar Yeti");

-- Large Loch Crocolisk
DELETE FROM `smart_scripts` WHERE `entryorguid`=2476 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2476,0,0,0,25,0,100,0,0,0,0,0,0,11,12787,0,0,0,0,0,1,0,0,0,0,0,0,0,"Large Loch Crocolisk - On Reset - Cast 'Thrash'"),
(2476,0,1,0,0,0,100,0,6000,8000,12000,16000,0,11,3427,0,0,0,0,0,2,0,0,0,0,0,0,0,"Large Loch Crocolisk - In Combat - Cast 'Infected Wound'");

-- Mo'grosh Ogre
DELETE FROM `smart_scripts` WHERE `entryorguid`=1178 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1178,0,1,0,25,0,100,0,0,0,0,0,0,11,7095,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Ogre - On Reset - Cast 'Knockdown Proc'");

-- Stormscale Myrmidon
DELETE FROM `smart_scripts` WHERE `entryorguid`=2181 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2181,0,0,0,25,0,100,0,0,0,0,0,0,11,7095,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormscale Myrmidon - On Reset - Cast 'Knockdown Proc'");

-- Mo'grosh Enforcer
DELETE FROM `smart_scripts` WHERE `entryorguid`=1179 AND `source_type`=0 AND `ID`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1179,0,0,0,4,0,15,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Enforcer - On Aggro - Say Line 0");

-- Mo'grosh Brute
DELETE FROM `smart_scripts` WHERE `entryorguid`=1180 AND `source_type`=0 AND `ID`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1180,0,0,0,4,0,15,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mo'grosh Brute - On Aggro - Say Line 0");

-- Mo'grosh Shaman
DELETE FROM `smart_scripts` WHERE `entryorguid`=1181 AND `source_type`=0 AND `ID` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1181,0,1,0,0,0,100,0,0,0,3000,5000,0,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mo'grosh Shaman - On Reset - Cast 'Lightning Bolt'"),
(1181,0,2,0,0,0,100,0,1000,5000,8000,13000,0,11,3229,0,0,0,0,0,9,0,0,30,0,0,0,0,"Mo'grosh Shaman - In Combat - Cast 'Quick Bloodlust'");

-- Mo'grosh Mystic
DELETE FROM `smart_scripts` WHERE `entryorguid`=1183 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1183,0,2,0,14,0,100,0,200,40,25000,30000,0,11,547,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mo'grosh Mystic - Friendly At 200 Health - Cast 'Healing Wave'");

-- Chok'sul
DELETE FROM `creature_text` WHERE `CreatureID`=1210 AND `GroupID`=0 AND `ID`=3;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1210,0,3,"Me smash you!",12,7,100,0,0,0,1930,0,"Chok'sul");

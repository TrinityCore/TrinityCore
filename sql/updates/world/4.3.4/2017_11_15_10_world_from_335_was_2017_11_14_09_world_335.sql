/*
-- Quest "Forsaken Aid"
-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`=4046 AND `GroupID` IN (2,3);
DELETE FROM `creature_text` WHERE `CreatureID` IN (4068,3419) AND `GroupID`=0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4046,2,0,"%s summons a messenger...",16,0,100,0,0,0,1420,0,"Magatha Grimtotem"),
(4046,3,0,"Go, my servant.  Send word of Stonetalon to Apothecary Zamah.",12,0,100,25,0,0,1419,0,"Magatha Grimtotem"),
(4068,0,0,"%s gives message to Apothecary Zamah.",16,0,100,0,0,0,1412,0,"Serpent Messenger"),
(3419,0,0,"%s smiles.",16,0,100,11,0,0,1418,0,"Apothecary Zamah");

-- Magatha Grimtotem
DELETE FROM `smart_scripts` WHERE `entryorguid`=4046 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=404601 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4046,0,1,0,19,0,100,0,1064,0,0,0,80,404601,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magatha Grimtotem - On Quest 'Forsaken Aid' Taken - Run Script"),
(404601,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magatha Grimtotem - On Script - Remove Npc Flag Questgiver"),
(404601,9,1,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magatha Grimtotem - On Script - Say Line 2"),
(404601,9,2,0,0,0,100,0,0,0,0,0,11,6657,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magatha Grimtotem - On Script - Cast Summon Serpent Messenger"),
(404601,9,3,0,0,0,100,0,0,0,0,0,12,4068,8,0,0,0,0,8,0,0,0,-1067.22,-213.737,160.473,5.25037,"Magatha Grimtotem - On Script - Summon Creature 'Serpent Messenger'"),
(404601,9,4,0,0,0,100,0,2000,2000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magatha Grimtotem - On Script - Say Line 3"),
(404601,9,5,0,0,0,100,0,5000,5000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magatha Grimtotem - On Script - Add Npc Flag Questgiver");

-- Serpent Messenger
UPDATE `creature_template` SET `AIName`="SmartAI", `InhabitType`=4 WHERE `entry`=4068;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4068 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=406800 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4068,0,0,0,54,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Serpent Messenger - On Just Summoned - Set Active On"),
(4068,0,1,0,1,0,100,1,7000,7000,0,0,53,1,4068,0,0,0,0,1,0,0,0,0,0,0,0,"Serpent Messenger - Out of Combat - Start Waypoint (No Repeat)"),
(4068,0,2,0,40,0,100,0,36,4068,0,0,80,406800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Serpent Messenger - On Waypoint 36 Reached - Run Script"),
(406800,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Serpent Messenger - On Script - Say Line 0"),
(406800,9,1,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,19,3419,0,0,0,0,0,0,"Serpent Messenger - On Script - Say Line 0 (Apothecary Zamah)"),
(406800,9,2,0,0,0,100,0,8000,8000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Serpent Messenger - On Script - Despawn");

-- Waypoint
DELETE FROM `waypoints` WHERE `entry`=4068;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(4068,1,-1067.22,-213.737,160.473,""),
(4068,2,-1062.56,-221.981,160.294,""),
(4068,3,-1054.61,-221.248,161.894,""),
(4068,4,-1054.61,-221.248,161.894,""),
(4068,5,-1037.05,-191.12,158.949,""),
(4068,6,-1053.12,-173.969,163.214,""),
(4068,7,-1064.46,-140.953,161.368,""),
(4068,8,-1079.25,-97.1617,156.371,""),
(4068,9,-1085.39,-64.6974,164.416,""),
(4068,10,-1083.91,-26.7695,159.369,""),
(4068,11,-1084.44,-9.29896,158.034,""),
(4068,12,-1109.66,7.02863,154.732,""),
(4068,13,-1132.07,31.5715,158.157,""),
(4068,14,-1129.02,47.1316,154.19,""),
(4068,15,-1095.17,63.5461,150.752,""),
(4068,16,-1086.83,113.827,144.557,""),
(4068,17,-1113.2,129.364,140.268,""),
(4068,18,-1146.35,119.028,141.776,""),
(4068,19,-1169.85,118.638,141.101,""),
(4068,20,-1206.75,117.618,139.861,""),
(4068,21,-1211.53,129.623,135.559,""),
(4068,22,-1192.52,144.921,136.995,""),
(4068,23,-1175.37,157.22,146.484,""),
(4068,24,-1155.67,169.875,146.074,""),
(4068,25,-1127.05,179.696,131.79,""),
(4068,26,-1096.04,189.663,118.055,""),
(4068,27,-1061.46,191.502,109.917,""),
(4068,28,-1056.64,215.227,113.473,""),
(4068,29,-1046.91,223.356,114.831,""),
(4068,30,-1035.35,218.46,112.371,""),
(4068,31,-1027.93,217.483,114.236,""),
(4068,32,-1023.41,229.152,108.92,""),
(4068,33,-1016.34,236.136,109.243,""),
(4068,34,-1013.08,246.142,108.77,""),
(4068,35,-1006.87,255.833,113.284,""),
(4068,36,-997.047,275.161,112.343,"");
*/

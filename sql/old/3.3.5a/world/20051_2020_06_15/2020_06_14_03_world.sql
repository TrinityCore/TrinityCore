-- Ranger Lilatha SAI (Source: CMaNGOS & nHRPUGtQ23s)
SET @ID := 16295;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "", `gossip_menu_id`=7197, `npcflag`=3 WHERE `entry` = @ID;
DELETE FROM `gossip_menu` WHERE `MenuID`=7197;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7197, 8478, 0);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,1,11,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Respawn - Set Flag Standstate Kneel"),
(@ID,0,1,0,61,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Link - Set Event Phase 1"),
(@ID,0,2,0,19,0,100,0,9212,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Quest 'Escape from the Catacombs' Taken - Run Script"),
(@ID,0,3,0,40,0,100,0,6,0,0,0,0,80,@ID*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Waypoint 6 Reached - Run Script"),
(@ID,0,4,0,40,0,100,0,12,0,0,0,0,80,@ID*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Waypoint 12 Reached - Run Script"),
(@ID,0,5,0,40,0,100,0,20,0,0,0,0,80,@ID*100+3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Waypoint 20 Reached - Run Script"),
(@ID,0,6,0,40,0,100,0,25,0,0,0,0,80,@ID*100+4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Waypoint 25 Reached - Run Script"),
(@ID,0,7,0,40,0,100,0,31,0,0,0,0,80,@ID*100+5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Waypoint 31 Reached - Run Script"),
-- Seems like a rare case or should be tested in retail
-- Or I wasn't able to find more info about it because the AT is huge and the say range is small
-- so player simply can't see the text in 90% of cases
(@ID,0,8,0,38,1,100,0,0,1,60000,60000,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Data Set 0 1 - Say Line 6 (Phase 1)"),
(@ID,0,9,0,6,0,100,0,0,0,0,0,0,6,9212,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Ranger Lilatha - On Death - Fail Quest 'Escape from the Catacombs'");

-- Actionlist SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+5 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Store Targetlist"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Set Event Phase 0"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Remove NPC Flags Gossip & Questgiver"),
(@ID*100+0,9,3,0,0,0,100,0,0,0,0,0,0,2,1603,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Set Faction 1603"),
(@ID*100+0,9,4,0,0,0,100,0,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Remove Flags Immune To Players & Immune To NPC's"),
(@ID*100+0,9,5,0,0,0,100,0,2000,2000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Remove Flag Standstate Kneel"),
(@ID*100+0,9,6,0,0,0,100,0,0,0,0,0,0,9,0,0,0,0,0,0,20,181152,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Activate Closest Gameobject (Cage)"),
(@ID*100+0,9,7,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Say Line 0"),
(@ID*100+0,9,8,0,0,0,100,0,2000,2000,0,0,0,53,0,16295,0,0,0,2,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Start Waypoint"),

(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Pause Waypoint"),
(@ID*100+1,9,1,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Say Line 1"),

(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Pause Waypoint"),
(@ID*100+2,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,4.762841,"Ranger Lilatha - On Script - Set Orientation"),
(@ID*100+2,9,2,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Say Line 2"),

(@ID*100+3,9,0,0,0,0,100,0,0,0,0,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Pause Waypoint"),
(@ID*100+3,9,1,0,0,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Say Line 3"),
(@ID*100+3,9,2,0,0,0,100,0,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Set Run On"),
(@ID*100+3,9,3,0,0,0,100,0,0,0,0,0,0,107,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Summon Group 0"),

(@ID*100+4,9,0,0,0,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Set Run Off"),

(@ID*100+5,9,0,0,0,0,100,0,0,0,0,0,0,54,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Pause Waypoint"),
(@ID*100+5,9,1,0,0,0,100,0,0,0,0,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Say Line 4"),
(@ID*100+5,9,2,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Set Orientation Stored Target 1"),
(@ID*100+5,9,3,0,0,0,100,0,5000,5000,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Say Line 5"),
(@ID*100+5,9,4,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,19,16220,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Set Orientation Closest Creature (Captain Helios)"),
(@ID*100+5,9,5,0,0,0,100,0,0,0,0,0,0,15,9212,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Quest Credit 'Escape from the Catacombs'"),
(@ID*100+5,9,6,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,19,16220,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Say Line 0 (Captain Helios)"),
(@ID*100+5,9,7,0,0,0,100,0,3000,3000,0,0,0,1,1,0,0,0,0,0,19,16220,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Say Line 1 (Captain Helios)"),
(@ID*100+5,9,8,0,0,0,100,0,8000,8000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Despawn (0)");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 4071 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4071,2,0,0,46,0,100,0,4071,0,0,0,0,45,0,1,0,0,0,0,10,82071,16295,0,0,0,0,0,0,"Areatrigger - On Trigger - Set Data 0 1 (Ranger Lilatha)");

DELETE FROM `areatrigger_scripts` WHERE `entry` = 4071;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(4071,"SmartTrigger");

UPDATE `creature_text` SET `BroadcastTextId` = 12393, `Language` = 1 WHERE `CreatureID` = 16295 AND `GroupID` = 0;
UPDATE `creature_text` SET `comment` = "Ranger Lilatha" WHERE `CreatureID` = 16295;
DELETE FROM `creature_text` WHERE `CreatureID` = 16295 AND `GroupID` = 6;
DELETE FROM `creature_text` WHERE `CreatureID` = 16220;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,6,0,"Hey!  Could you come over and get me out of this cage?",12,1,100,0,0,0,13382,0,"Ranger Lilatha"),
(@ID,6,1,"HELP!!!",12,1,100,0,0,0,13383,0,"Ranger Lilatha"),
(@ID,6,2,"Get me out of here and I guarantee there'll be a reward in it for you!",12,1,100,0,0,0,13384,0,"Ranger Lilatha"),
(@ID,6,3,"Quick, kill all of these trolls and then let me out of this thing!",12,1,100,0,0,0,13385,0,"Ranger Lilatha"),
(@ID,6,4,"If you let me out I promise that you won't regret it!",12,1,100,0,0,0,13386,0,"Ranger Lilatha"),
(@ID,6,5,"If you don't mind hurrying it up?  I think they're getting ready to sacrifice me!",12,1,100,0,0,0,13387,0,"Ranger Lilatha"),
(16220,0,0,"%s nods in relief to Ranger Lilatha and her escort.",16,0,100,0,0,0,12192,0,"Captain Helios"),
(16220,1,0,"Lilatha, get someone to look at those injuries. Thank you for bringing her back safely.",12,1,100,0,0,0,12193,0,"Captain Helios");

DELETE FROM `creature_summon_groups` WHERE `summonerId` = @ID;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(@ID,0,0,16342,7627.083984,-7532.538086,152.128616,1.082733,6,60000),
(@ID,0,0,16343,7620.432129,-7532.550293,152.454865,0.827478,6,60000);

UPDATE `creature_template_addon` SET `bytes1` = 0 WHERE `entry` = 16295;

DELETE FROM `script_waypoint` WHERE `entry` = 16295;
DELETE FROM `waypoints` WHERE `entry` = 16295;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(16295,1,7545.07,-7359.87,162.354,"Ranger Lilatha"),
(16295,2,7550.05,-7362.24,162.236,"Ranger Lilatha"),
(16295,3,7566.98,-7364.32,161.739,"Ranger Lilatha"),
(16295,4,7578.83,-7361.68,161.739,"Ranger Lilatha"),
(16295,5,7590.97,-7359.05,162.258,"Ranger Lilatha"),
(16295,6,7598.35,-7362.82,162.257,"Ranger Lilatha"),
(16295,7,7605.86,-7380.42,161.937,"Ranger Lilatha"),
(16295,8,7605.30,-7387.38,157.254,"Ranger Lilatha"),
(16295,9,7606.13,-7393.89,156.942,"Ranger Lilatha"),
(16295,10,7615.21,-7400.19,157.143,"Ranger Lilatha"),
(16295,11,7618.96,-7402.65,158.202,"Ranger Lilatha"),
(16295,12,7636.85,-7401.76,162.145,"Ranger Lilatha"),
(16295,13,7637.06,-7404.94,162.207,"Ranger Lilatha"),
(16295,14,7636.91,-7412.59,162.366,"Ranger Lilatha"),
(16295,15,7637.61,-7425.59,162.631,"Ranger Lilatha"),
(16295,16,7637.82,-7459.06,163.303,"Ranger Lilatha"),
(16295,17,7638.86,-7470.90,162.517,"Ranger Lilatha"),
(16295,18,7641.40,-7488.22,157.381,"Ranger Lilatha"),
(16295,19,7634.46,-7505.45,154.682,"Ranger Lilatha"),
(16295,20,7631.91,-7516.95,153.597,"Ranger Lilatha"),
(16295,21,7622.23,-7537.04,151.587,"Ranger Lilatha"),
(16295,22,7610.92,-7550.67,149.639,"Ranger Lilatha"),
(16295,23,7598.23,-7562.55,145.954,"Ranger Lilatha"),
(16295,24,7588.51,-7577.76,148.294,"Ranger Lilatha"),
(16295,25,7567.34,-7608.46,146.006,"Ranger Lilatha"),
(16295,26,7562.55,-7617.42,148.098,"Ranger Lilatha"),
(16295,27,7561.51,-7645.06,151.245,"Ranger Lilatha"),
(16295,28,7563.34,-7654.65,151.227,"Ranger Lilatha"),
(16295,29,7565.53,-7658.30,151.249,"Ranger Lilatha"),
(16295,30,7579.12,-7662.21,151.652,"Ranger Lilatha"),
(16295,31,7603.77,-7667.00,153.998,"Ranger Lilatha");

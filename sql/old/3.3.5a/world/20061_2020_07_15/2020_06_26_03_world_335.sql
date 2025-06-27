-- Galen Goodward SAI (Source: https://www.youtube.com/watch?v=57_CgmmO-hI & https://www.youtube.com/watch?v=Uxvm_uQvQhQ)
SET @ID := 5391;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,11,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Galen Goodward - On Respawn - Set Event Phase 1"),
(@ID,0,1,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Galen Goodward - On Aggro - Say Line 0"),
(@ID,0,2,0,19,0,100,0,1393,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Galen Goodward - On Quest 'Galen's Escape' Taken - Run Script"),

(@ID,0,3,0,40,0,100,0,1,0,0,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Galen Goodward - On Waypoint 1 Reached - Pause Waypoint"),

(@ID,0,4,5,40,0,100,0,21,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Galen Goodward - On Waypoint 21 Reached - Set Run On"),
(@ID,0,5,6,61,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Galen Goodward - On Link - Set Orientation Stored Target"),
(@ID,0,6,7,61,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Galen Goodward - On Link - Say Line 3"),
(@ID,0,7,8,61,0,100,0,0,0,0,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Galen Goodward - On Link - Say Line 4"),
(@ID,0,8,9,61,0,100,0,0,0,0,0,0,1,5,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Galen Goodward - On Link - Say Line 5"),
(@ID,0,9,0,61,0,100,0,0,0,0,0,0,15,1393,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Galen Goodward - On Link - Quest Credit 'Galen's Escape'"),

(@ID,0,10,0,40,0,100,0,22,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Galen Goodward - On Waypoint 22 Reached - Despawn (0)"),

(@ID,0,11,0,38,1,100,0,0,1,60000,60000,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Galen Goodward - On Data Set 0 1 - Say Line 1 (Phase 1)"),
(@ID,0,12,0,6,0,100,0,0,0,0,0,0,6,1393,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Galen Goodward - On Death - Fail Quest 'Galen's Escape'");

-- Actionlist SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Galen Goodward - On Script - Store Targetlist"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Galen Goodward - On Script - Set Event Phase 0"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Galen Goodward - On Script - Remove NPC Flag Questgiver"),
(@ID*100+0,9,3,0,0,0,100,0,0,0,0,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Galen Goodward - On Script - Set Faction 250"),
(@ID*100+0,9,4,0,0,0,100,0,0,0,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Galen Goodward - On Script - Remove Flags Immune To Players"),
(@ID*100+0,9,5,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Galen Goodward - On Script - Say Line 2"),
(@ID*100+0,9,6,0,0,0,100,0,3000,3000,0,0,0,9,0,0,0,0,0,0,20,37118,0,0,0,0,0,0,0,"Galen Goodward - On Script - Activate Closest Gameobject 'Galen's Cage'"),
(@ID*100+0,9,7,0,0,0,100,0,0,0,0,0,0,53,0,5391,0,0,0,2,1,0,0,0,0,0,0,0,0,"Galen Goodward - On Script - Start Waypoint");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 2387 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2387,2,0,0,46,0,100,0,2387,0,0,0,0,45,0,1,0,0,0,0,19,5391,20,0,0,0,0,0,0,"Areatrigger (Swamp of Sorrows) - On Trigger - Set Data 0 1 (Galen Goodward)");

DELETE FROM `areatrigger_scripts` WHERE `entry` = 2387;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(2387,"SmartTrigger");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"Look out!  The $n attacks!",12,0,100,0,0,0,1628,0,"Galen Goodward"),
(@ID,0,1,"Help! I'm under attack!",12,0,100,0,0,0,1629,0,"Galen Goodward"),
(@ID,0,2,"Help!  The beast is on me!",12,0,100,0,0,0,1630,0,"Galen Goodward"),
(@ID,1,0,"I'm glad you're here!  Because I need your help!!",12,0,100,0,0,0,1631,0,"Galen Goodward"),
(@ID,1,1,"Help!  Please, you must help me!",12,0,100,0,0,0,7124,0,"Galen Goodward"),
(@ID,2,0,"Let us leave this place.",12,0,100,0,0,0,1854,0,"Galen Goodward"),
(@ID,3,0,"Thank you, $n.  I will remember you always.  You can find my strongbox in my camp, north of Stonard.",12,0,100,0,0,0,1855,0,"Galen Goodward"),
(@ID,4,0,"%s whispers to $n the secret to opening his strongbox.",16,0,100,0,0,0,2076,0,"Galen Goodward"),
(@ID,5,0,"%s disappears into the swamp.",16,0,100,0,0,0,1856,0,"Galen Goodward");

DELETE FROM `script_waypoint` WHERE `entry` = 5391;
DELETE FROM `waypoints` WHERE `entry` = 5391;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(5391,1,-9901.12,-3727.29,22.11,"Galen Goodward"),
(5391,2,-9909.27,-3727.81,23.25,"Galen Goodward"),
(5391,3,-9935.25,-3729.02,22.11,"Galen Goodward"),
(5391,4,-9945.83,-3719.34,21.68,"Galen Goodward"),
(5391,5,-9963.41,-3710.18,21.71,"Galen Goodward"),
(5391,6,-9972.75,-3690.13,21.68,"Galen Goodward"),
(5391,7,-9989.7,-3669.67,21.67,"Galen Goodward"),
(5391,8,-9989.21,-3647.76,23,"Galen Goodward"),
(5391,9,-9992.27,-3633.74,21.67,"Galen Goodward"),
(5391,10,-10002.3,-3611.67,22.26,"Galen Goodward"),
(5391,11,-9999.25,-3586.33,21.85,"Galen Goodward"),
(5391,12,-10006.5,-3571.99,21.67,"Galen Goodward"),
(5391,13,-10014.3,-3545.24,21.67,"Galen Goodward"),
(5391,14,-10018.9,-3525.03,21.68,"Galen Goodward"),
(5391,15,-10030.2,-3514.77,21.67,"Galen Goodward"),
(5391,16,-10045.1,-3501.49,21.67,"Galen Goodward"),
(5391,17,-10052.9,-3479.13,21.67,"Galen Goodward"),
(5391,18,-10060.7,-3460.31,21.67,"Galen Goodward"),
(5391,19,-10074.7,-3436.85,20.97,"Galen Goodward"),
(5391,20,-10074.7,-3436.85,20.97,"Galen Goodward"),
(5391,21,-10072.9,-3408.92,20.43,"Galen Goodward"),
(5391,22,-10108,-3406.05,22.06,"Galen Goodward");

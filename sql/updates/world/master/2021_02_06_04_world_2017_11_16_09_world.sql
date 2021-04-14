-- 
-- Quest "Chieftain Oomooroo"
-- Stillpine the Younger
DELETE FROM `creature_text` WHERE `CreatureID`=17445;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17445,0,0,"Stillpine raiders, the time to strike is at hand! Charge!",14,0,100,0,0,0,14038,0,"Stillpine the Younger");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=17445;
DELETE FROM `smart_scripts` WHERE `entryorguid`=17445 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1744500 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17445,0,0,0,20,0,100,0,9573,0,0,0,80,1744500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine the Younger - On Quest 'Chieftain Oomooroo' Finished - Run Script"),
(1744500,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine the Younger - On Script - Say Line 0"),
(1744500,9,1,0,0,0,100,0,2000,2000,0,0,12,17495,6,30000,0,0,0,8,0,0,0,-3367.84,-12424.6,26.1425,1.85513,"Stillpine the Younger - On Script - Summon Creature 'Stillpine Raider'"),
(1744500,9,2,0,0,0,100,0,0,0,0,0,12,17495,6,30000,0,0,0,8,0,0,0,-3363.8,-12428.6,27.3273,1.98472,"Stillpine the Younger - On Script - Summon Creature 'Stillpine Raider'"),
(1744500,9,3,0,0,0,100,0,0,0,0,0,12,17495,6,30000,0,0,0,8,0,0,0,-3364.07,-12432.9,27.338,1.9965,"Stillpine the Younger - On Script - Summon Creature 'Stillpine Raider'"),
(1744500,9,4,0,0,0,100,0,0,0,0,0,12,17495,6,30000,0,0,0,8,0,0,0,-3360.59,-12433.1,28.084,2.08289,"Stillpine the Younger - On Script - Summon Creature 'Stillpine Raider'"),
(1744500,9,5,0,0,0,100,0,0,0,0,0,12,17495,6,30000,0,0,0,8,0,0,0,-3356.08,-12434.3,29.6136,2.49915,"Stillpine the Younger - On Script - Summon Creature 'Stillpine Raider'"),
(1744500,9,6,0,0,0,100,0,0,0,0,0,12,17495,6,30000,0,0,0,8,0,0,0,-3357.16,-12430.5,28.9967,2.46774,"Stillpine the Younger - On Script - Summon Creature 'Stillpine Raider'"),
(1744500,9,7,0,0,0,100,0,0,0,0,0,12,17495,6,30000,0,0,0,8,0,0,0,-3355.98,-12438.2,29.8503,2.46224,"Stillpine the Younger - On Script - Summon Creature 'Stillpine Raider'"),
(1744500,9,8,0,0,0,100,0,0,0,0,0,12,17495,6,30000,0,0,0,8,0,0,0,-3350.3,-12437.5,32.3999,2.41119,"Stillpine the Younger - On Script - Summon Creature 'Stillpine Raider'"),
(1744500,9,9,0,0,0,100,0,0,0,0,0,12,17495,6,30000,0,0,0,8,0,0,0,-3348.27,-12442.5,34.3653,2.58005,"Stillpine the Younger - On Script - Summon Creature 'Stillpine Raider'"),
(1744500,9,10,0,0,0,100,0,0,0,0,0,12,17495,6,30000,0,0,0,8,0,0,0,-3344.08,-12441.7,36.8811,2.36014,"Stillpine the Younger - On Script - Summon Creature 'Stillpine Raider'");

-- Stillpine Raider
DELETE FROM `smart_scripts` WHERE `entryorguid`=17495 AND `source_type`=0 AND `id`>0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1749500 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17495,0,1,0,54,0,100,0,0,0,0,0,53,1,17495,0,0,0,2,1,0,0,0,0,0,0,0,"Stillpine Raider - On Just Summoned - Start Waypoint"),
(17495,0,2,0,54,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Raider - On Just Summoned - Set Active On"),
(17495,0,3,0,40,0,100,0,21,17495,0,0,89,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Raider - On Waypoint 20 Reached - Start Random Movement"),
(17495,0,4,0,40,0,100,0,21,17495,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stillpine Raider - On Waypoint 20 Reached - Despawn in 10000 ms");

DELETE FROM `waypoints` WHERE `entry`=17495;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(17495,1,-3374.06,-12411.8,22.0504,""),
(17495,2,-3404.94,-12368.4,17.7868,""),
(17495,3,-3377.49,-12350.4,22.4495,""),
(17495,4,-3328.89,-12346,22.9951,""),
(17495,5,-3305.27,-12346.2,24.0911,""),
(17495,6,-3278.58,-12347.7,19.2297,""),
(17495,7,-3259.37,-12359.1,13.5547,""),
(17495,8,-3248.81,-12373.3,10.5433,""),
(17495,9,-3239.23,-12391.4,10.4531,""),
(17495,10,-3237.35,-12418.7,14.692,""),
(17495,11,-3234.66,-12427.5,16.3937,""),
(17495,12,-3225.87,-12435.1,19.1127,""),
(17495,13,-3202.85,-12463.4,14.6165,""),
(17495,14,-3190.47,-12461.7,13.2373,""),
(17495,15,-3182.54,-12456.9,13.0909,""),
(17495,16,-3177.36,-12452.2,13.0143,""),
(17495,17,-3172.53,-12443.2,12.1312,""),
(17495,18,-3158.44,-12436.1,12.0219,""),
(17495,19,-3143.65,-12438.1,10.1409,""),
(17495,20,-3097.4,-12464.2,3.13821,""),
(17495,21,-3079.57,-12477.1,0.0367675,"");

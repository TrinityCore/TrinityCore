/*
-- Talen
DELETE FROM `creature_text` WHERE `CreatureID`=3846;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3846,0,0,"This statuette must hold a hidden compartment....",12,7,100,1,0,0,0,0,"Talen"),
(3846,1,0,"%s searches the ancient statuette.",16,0,100,0,0,0,0,0,"Talen"),
(3846,2,0,"It's locked!  NO!!",12,7,100,15,0,0,0,0,"Talen"),
(3846,3,0,"$n, I am in need of your help once again.",12,7,100,1,0,0,1355,0,"Talen");

DELETE FROM `smart_scripts` WHERE `entryorguid`=3846 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=384600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3846,0,1,0,20,0,100,0,1007,0,0,0,80,384600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talen - On Quest 'The Ancient Statuette' Finished - Run Script"),
(384600,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talen - On Script - Remove Npc Flag Questgiver"),
(384600,9,1,0,0,0,100,0,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talen - On Script - Remove Flag Standstate 'Sit Down'"),
(384600,9,2,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,6.16678,"Talen - On Script - Set Orientation"),
(384600,9,3,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talen - On Script - Say Line 0"),
(384600,9,4,0,0,0,100,0,4000,4000,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talen - On Script - Set Flag Standstate 'Kneel'"),
(384600,9,5,0,0,0,100,0,1000,1000,0,0,50,18603,12,0,0,0,0,8,0,0,0,3471.69,846.893,5.39909,4.67058,"Talen - On Script - Summon Gameobject 'Ancient Statuette'"),
(384600,9,6,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talen - On Script - Say Line 1"),
(384600,9,7,0,0,0,100,0,8000,8000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talen - On Script - Say Line 2"),
(384600,9,8,0,0,0,100,0,4000,4000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talen - On Script - Remove Flag Standstate 'Kneel'"),
(384600,9,9,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talen - On Script - Set Orientation"),
(384600,9,10,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talen - On Script - Say Line 3"),
(384600,9,11,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talen - On Script - Add Npc Flag Questgiver"),
(384600,9,12,0,0,0,100,0,20000,20000,0,0,90,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talen - On Script - Set Flag Standstate Sit Down");

UPDATE `creature_template` SET `npcflag`=2, `gossip_menu_id`=0 WHERE `entry`=3846; -- Fix NPC flag and remove gossip
*/

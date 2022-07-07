-- Elder Torntusk
UPDATE `creature_template` SET `gossip_menu_id`=6102, `AIName`="SmartAI" WHERE `entry`=14757;

DELETE FROM `gossip_menu` WHERE `MenuID`=6102;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(6102,7257,0);

DELETE FROM `creature_text` WHERE `CreatureID`=14757;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(14757,0,0,"Finally, I am free! I come home soon, my dear!",12,0,100,4,0,0,10013,0,"Elder Torntusk");

DELETE FROM `smart_scripts` WHERE `entryorguid`=14757 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1475700 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14757,0,0,0,20,0,100,0,7846,0,0,0,80,1475700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Torntusk - On Quest 'Recover the Key!' Finished - Run Script"),
(1475700,9,0,0,0,0,100,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Torntusk - On Script - Remove Flag Standstate 'Dead'"),
(1475700,9,1,0,0,0,100,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Torntusk - On Script - Remove Npc Flag 'Gossip'"),
(1475700,9,2,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Torntusk - On Script - Say Line 0"),
(1475700,9,3,0,0,0,100,0,60000,60000,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Torntusk - On Script - Set Flag Standstate 'Dead'"),
(1475700,9,4,0,0,0,100,0,0,0,0,0,82,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Torntusk - On Script - Add Npc Flag 'Gossip'");

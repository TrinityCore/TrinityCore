-- Raschal the Courier
UPDATE `creature_text` SET `Emote`=1 WHERE `CreatureID`=9546 AND `GroupID`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=954600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(954600,9,0,0,0,0,100,0,0,0,0,0,0,17,64,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Raschal the Courier - On Script - Set Emote State 'Stun'"),
(954600,9,1,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Raschal the Courier - On Script - Say Line 0"),
(954600,9,2,0,0,0,100,0,5500,5500,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Raschal the Courier - On Script - Set Emote State 'None'"),
(954600,9,3,0,0,0,100,0,500,500,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Raschal the Courier - On Script - Say Line 1"),
(954600,9,4,0,0,0,100,0,5000,5000,0,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Raschal the Courier - On Script - Play Emote 'Bow'"),
(954600,9,5,0,0,0,100,0,2000,2000,0,0,0,15,4265,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Raschal the Courier - On Script - Quest Credit 'Freed from the Hive'"),
(954600,9,6,0,0,0,100,0,3000,3000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Raschal the Courier - On Script - Despawn Instant");

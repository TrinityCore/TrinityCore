-- Quest "The Emitter"
DELETE FROM `smart_scripts` WHERE `entryorguid`=1707100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1707100,9,0,0,0,0,100,0,0,0,0,0,9,0,0,0,0,0,0,20,181286,0,0,0,0,0,0,"Technician Zhanaa - On Script - Activate Gameobject"),
(1707100,9,1,0,0,0,100,0,0,0,0,0,12,16550,1,39000,0,0,0,8,0,0,0,-4187.71,-13738.7,75.6549,1.85005,"Technician Zhanaa - On Script - Summon Creature 'Image of Technician Dyvuun'"),
(1707100,9,2,0,0,0,100,0,0,0,0,0,64,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Technician Zhanaa - On Script - Store Targetlist"),
(1707100,9,3,0,0,0,100,0,1000,1000,0,0,100,2,0,0,0,0,0,19,16550,10,0,0,0,0,0,"Technician Zhanaa - On Script - Send Target 2"),
(1707100,9,4,0,0,0,100,0,1000,1000,0,0,45,0,1,0,0,0,0,19,16550,10,0,0,0,0,0,"Technician Zhanaa - On Script - Set Data 0 1"),
(1707100,9,5,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,19,16550,10,0,0,0,0,0,"Technician Zhanaa - On Script - Set Orientation Closest Creature 'Image of Technician Dyvuun'"),
(1707100,9,6,0,0,0,100,0,2000,2000,0,0,5,70,0,0,0,0,0,1,0,0,0,0,0,0,0,"Technician Zhanaa - On Script - Play Emote 70"),
(1707100,9,7,0,0,0,100,0,19000,19000,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Technician Zhanaa - On Script - Set Run Off"),
(1707100,9,8,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,-4186.67,-13736.3,74.4813,0,"Technician Zhanaa - On Script - Move to Position"),
(1707100,9,9,0,0,0,100,0,3000,3000,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0,"Technician Zhanaa - On Script - Set Emote State 133"),
(1707100,9,11,0,0,0,100,0,16000,16000,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Technician Zhanaa - On Script - Set Orientation Invoker"),
(1707100,9,12,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Technician Zhanaa - On Script - Say Line 0"),
(1707100,9,13,0,0,0,100,0,29000,29000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Technician Zhanaa - On Script - Set Emote State 0"),
(1707100,9,14,0,0,0,100,0,1000,1000,0,0,69,0,0,0,0,0,0,8,0,0,0,-4184.55,-13733.1,74.1389,0,"Technician Zhanaa - On Script - Move to Position"),
(1707100,9,15,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.91986,"Technician Zhanaa - On Script - Set Orientation");

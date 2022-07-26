--
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 8444;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 8444 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8444,0,0,0,4,0,100,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Trade Master Kovic - On Aggro - Say Line 0"),
(8444,0,1,0,0,0,100,0,0,0,3400,4800,0,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Trade Master Kovic - In Combat CMC - Cast 'Fireball'"),
(8444,0,2,0,0,0,100,0,5000,10000,15000,25000,0,11,11436,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Trade Master Kovic - In Combat - Cast 'Slow'"),
(8444,0,3,0,0,0,100,0,10000,15000,20000,30000,0,11,11990,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Trade Master Kovic - In Combat - Cast 'Rain of Fire'");

DELETE FROM `creature_text` WHERE `CreatureID` = 8444;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(8444,0,0,"There'll be a new trade risin' up round your carcass, $n. We'll call it 'flesh-craftin.'",12,0,100,0,0,0,4421,0,"Trade Master Kovic");

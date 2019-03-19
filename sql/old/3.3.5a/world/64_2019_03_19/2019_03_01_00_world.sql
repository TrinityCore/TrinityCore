-- 
DELETE FROM `creature_template_addon` WHERE `entry` IN(33007);
DELETE FROM `creature_text` WHERE `CreatureID` IN (29319,29327);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(29319,0,0,"It's an angry male!",42,0,100,0,0,473,33191,0,'Icepaw Bear'),
(29319,1,0,"It's a female.",42,0,100,0,0,473,33192,0,'Icepaw Bear'),
(29327,0,0,"It's an angry male!",42,0,100,0,0,643,33191,0,'Frost Leopard'),
(29327,1,0,"It's a female.",42,0,100,0,0,643,33192,0,'Frost Leopard');
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2931900,2932700,2931901,2931902,2931903,2932701,2932702,2932703) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29319,29327) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(29319, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 8000, 11000, 0, 11, 54632, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Icepaw Bear - In Combat - Cast 'Claws of Ice' (No Repeat) (Dungeon)"),
(29319, 0, 1, 0, 8, 0, 100, 513, 62105, 0, 0, 0, 0, 80, 2931900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Icepaw Bear - On Spellhit 'To'kini's Blowgun' - Run Script (No Repeat) (Dungeon)"),
(29319, 0, 2, 0, 62, 0, 100, 512, 10274, 0, 0, 0, 0, 88, 2931901, 2931902, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Icepaw Bear - On Gossip Option 0 Selected - Run Random Script (No Repeat) (Dungeon)"),
(29327, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 8000, 11000, 0, 11, 54668, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Frost Leopard - In Combat - Cast 'Rake' (No Repeat) (Dungeon)"),
(29327, 0, 1, 0, 8, 0, 100, 513, 62105, 0, 0, 0, 0, 80, 2932700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Frost Leopard - On Spellhit 'To'kini's Blowgun' - Run Script (No Repeat) (Dungeon)"),
(29327, 0, 2, 0, 62, 0, 100, 512, 10273, 0, 0, 0, 0, 88, 2932701, 2932702, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Frost Leopard - On Gossip Option 0 Selected - Run Random Script (No Repeat) (Dungeon)"),
(2931900,9,0,0,0,0,100,0,0,0,0,0,0,2,190,0,0,0,0,0,1,0,0,0,0,0,0,0,'Icepaw Bear - On Script - Set Faction 190'), 
(2931900,9,1,0,0,0,100,0,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Icepaw Bear - On Script - Set Flag Immune to PC'),
(2931900,9,2,0,0,0,100,0,0,0,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Icepaw Bear - On Script - MoveIdle'), 
(2931900,9,3,0,0,0,100,0,2000,2000,0,0,0,11,62248,2,0,0,0,0,1,0,0,0,0,0,0,0,'Icepaw Bear - On Script - Cast \'Sleeping Sleep\''),
(2931900,9,4,0,0,0,100,0,60000,60000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Icepaw Bear - On Script - Despawn'),
(2932700,9,0,0,0,0,100,0,0,0,0,0,0,2,190,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frost Leopard - On Script - Set Faction 190'),
(2932700,9,1,0,0,0,100,0,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frost Leopard - On Script - Set Flag Immune to PC'), 
(2932700,9,2,0,0,0,100,0,0,0,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frost Leopard - On Script - MoveIdle'),
(2932700,9,3,0,0,0,100,0,2000,2000,0,0,0,11,62248,2,0,0,0,0,1,0,0,0,0,0,0,0,'Frost Leopard - On Script - Cast \'Sleeping Sleep\''), 
(2932700,9,4,0,0,0,100,0,60000,60000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frost Leopard - On Script - Despawn'),
(2931901,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Icepaw Bear - On Script - Say Line 0'), 
(2931901,9,1,0,0,0,100,0,0,0,0,0,0,28,62248,0,0,0,0,0,1,0,0,0,0,0,0,0,'Icepaw Bear - On Script - Remove Sleep'),
(2931901,9,2,0,0,0,100,0,0,0,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Icepaw Bear - On Script - Remove Immune to PC'), 
(2931901,9,3,0,0,0,100,0,0,0,0,0,0,2,1990,0,0,0,0,0,1,0,0,0,0,0,0,0,'Icepaw Bear - On Script - Set Faction 1990'),
(2931901,9,4,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Icepaw Bear - On Script - AttackStart'), 
(2931901,9,5,0,0,0,100,0,180000,180000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Icepaw Bear - On Script - Despawn'),
(2931902,9,0,0,0,0,100,0,0,0,0,0,0,11,62118,2,0,0,0,0,7,0,0,0,0,0,0,0,'Icepaw Bear - On Script - Cast \'Tails Up: Force Bear Summon\''),
(2931902,9,1,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Icepaw Bear - On Script - Say Line 1'), 
(2931902,9,2,0,0,0,100,0,0,0,0,0,0,33,33006,0,0,0,0,0,7,0,0,0,0,0,0,0,'Icepaw Bear - On Script - Quest Credit \'Tails Up\''),
(2931902,9,3,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Icepaw Bear - On Script - Despawn'), 
(2932701,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Frost Leopard - On Script - Say Line 0'), 
(2932701,9,1,0,0,0,100,0,0,0,0,0,0,28,62248,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frost Leopard - On Script - Remove Sleep'),
(2932701,9,2,0,0,0,100,0,0,0,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frost Leopard - On Script - Remove Immune to PC'), 
(2932701,9,3,0,0,0,100,0,0,0,0,0,0,2,1990,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frost Leopard - On Script - Set Faction 1990'),
(2932701,9,4,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Frost Leopard - On Script - AttackStart'), 
(2932701,9,5,0,0,0,100,0,180000,180000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frost Leopard - On Script - Despawn'),
(2932702,9,0,0,0,0,100,0,0,0,0,0,0,11,62117,2,0,0,0,0,7,0,0,0,0,0,0,0,'Frost Leopard - On Script - Cast \'Tails Up: Force Leopard Summon\''),
(2932702,9,1,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Frost Leopard - On Script - Say Line 1'), 
(2932702,9,2,0,0,0,100,0,0,0,0,0,0,33,33006,0,0,0,0,0,7,0,0,0,0,0,0,0,'Frost Leopard - On Script - Quest Credit \'Tails Up\''),
(2932702,9,3,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Frost Leopard - On Script - Despawn');

UPDATE `creature_template` SET `unit_flags`=776, `AIName`='SmartAI' WHERE `entry` IN (33010,33011);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (33010,33011) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(33011,0,0,0,54,0,100,0,0,0,0,0,0,29,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Female Icepaw Bear - Just Summoned - Set Follow'),
(33010,0,0,0,54,0,100,0,0,0,0,0,0,29,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Female Frost Leopard - Just Summoned - Set Follow');

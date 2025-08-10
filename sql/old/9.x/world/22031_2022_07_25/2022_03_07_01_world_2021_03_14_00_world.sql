--
UPDATE `creature_model_info` SET `BoundingRadius` = 2, `CombatReach` = 2 WHERE `DisplayID` = 15102;
UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 28151;
UPDATE `creature_template_addon` SET `bytes2` = 1, `emote` = 27, `auras` = "28126" WHERE `entry` = 28068;

DELETE FROM `creature_text` WHERE `CreatureID` = 28068;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(28068,0,0,"Drink deep my brothers!",14,0,100,0,0,0,27507,0,"Prophet of Sseratus"),
(28068,0,1,"The mojo of Sseratus is ours. Now all will be crushed under the might of the Drakkari!",14,0,100,0,0,0,27508,0,"Prophet of Sseratus"),
(28068,0,2,"They dare attack us? The fools! Do they not know we are now all-powerful?!",14,0,100,0,0,0,27509,0,"Prophet of Sseratus"),
(28068,0,3,"Kill these invaders who dare to defile our altar!",14,0,100,0,0,0,27510,0,"Prophet of Sseratus"),
(28068,0,4,"Finish them and then we will move south to kill their brethren!",14,0,100,0,0,0,27511,0,"Prophet of Sseratus"),
(28068,0,5,"With the power of the wild gods burning in our veins, none, not even the Lich King, can stand in our way!",14,0,100,0,0,0,27512,0,"Prophet of Sseratus"),
(28068,0,6,"I see you, insect! Come closer.",14,0,100,0,0,0,27513,0,"Prophet of Sseratus"),
(28068,0,7,"I will destroy the Argent Crusade! I will crush the Scourge!",14,0,100,0,0,0,27514,0,"Prophet of Sseratus"),

(28068,1,0,"Mmm, more mojo.",14,0,100,35,0,4496,27531,0,"Prophet of Sseratus"),
(28068,2,0,"NOOOOOOOOooooooo.........!",14,0,100,0,0,0,27532,0,"Prophet of Sseratus");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 28068 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2806800 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- I'm not sure if muddled can say too or not. It will throw errors so just ignore them
(28068,0,0,0,1,0,100,0,65000,95000,65000,95000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prophet of Sseratus - Out of Combat - Say Line 0"),
(28068,0,1,0,0,0,100,0,6000,10000,10000,15000,0,11,48287,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Prophet of Sseratus - In Combat - Cast 'Powerful Bite'"),
(28068,0,2,0,0,0,100,0,1000,4000,10000,10000,0,11,54483,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prophet of Sseratus - In Combat - Cast 'Vigor of Sseratus'"),
(28068,0,3,0,8,0,100,1,50706,0,0,0,0,80,2806800,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prophet of Sseratus - On Spellhit 'Modified Mojo' - Run Script (No Repeat)"),
-- Looks ugly in game to be honest
(2806800,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prophet of Sseratus - On Script - Set Reactstate Passive"),
(2806800,9,1,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Prophet of Sseratus - On Script - Start Attack Invoker"),
(2806800,9,2,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prophet of Sseratus - On Script - Say Line 1"),
(2806800,9,3,0,0,0,100,0,0,0,0,0,0,71,0,1,3699,0,0,0,1,0,0,0,0,0,0,0,0,"Prophet of Sseratus - On Script - Change Equipment"),
(2806800,9,4,0,0,0,100,0,3000,3000,0,0,0,11,41339,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prophet of Sseratus - On Script - Cast 'Cosmetic - Legion Ring Purple Lightning (Self)'"),
(2806800,9,5,0,0,0,100,0,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prophet of Sseratus - On Script - Set Reactstate Aggressive"),
(2806800,9,6,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prophet of Sseratus - On Script - Say Line 2"),
(2806800,9,7,0,0,0,100,0,0,0,0,0,0,71,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prophet of Sseratus - On Script - Change Equipment"),
(2806800,9,8,0,0,0,100,0,0,0,0,0,0,36,28151,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Prophet of Sseratus - On Script - Update Template To 'Muddled Prophet of Sseratus'");

-- https://www.wowhead.com/npc=28068/prophet-of-sseratus#comments:id=2010448
-- Probably correct since new creature was available in less than one minute in sniff(CreateObject1 only)
UPDATE `creature` SET `spawntimesecs` = 30 WHERE `id` = 28068;

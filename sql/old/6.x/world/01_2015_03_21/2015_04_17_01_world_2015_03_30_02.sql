SET @Triggger:=34146;
SET @Triggger1:=34150;
SET @Triggger2:=34151;
SET @Jormungar:=34137; 

DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (34146, 34151, 34150);
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`)VALUES
(34146,34137,0,0,'Snow Mound',8,0),
(34146,34137,1,0,'Snow Mound',8,0),
(34146,34137,2,0,'Snow Mound',8,0),
(34146,34137,3,0,'Snow Mound',8,0),
(34151,34137,0,0,'Snow Mound',8,0),
(34151,34137,1,0,'Snow Mound',8,0),
(34151,34137,2,0,'Snow Mound',8,0),
(34151,34137,3,0,'Snow Mound',8,0),
(34151,34137,4,0,'Snow Mound',8,0),
(34151,34137,5,0,'Snow Mound',8,0),
(34151,34137,6,0,'Snow Mound',8,0),
(34151,34137,7,0,'Snow Mound',8,0),
(34150,34137,0,0,'Snow Mound',8,0),
(34150,34137,1,0,'Snow Mound',8,0),
(34150,34137,2,0,'Snow Mound',8,0),
(34150,34137,3,0,'Snow Mound',8,0),
(34150,34137,4,0,'Snow Mound',8,0),
(34150,34137,5,0,'Snow Mound',8,0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (34146, 34151, 34150);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(34146, 43671, 1, 0),
(34151, 43671, 1, 0),
(34150, 43671, 1, 0);

UPDATE `creature_template` SET `flags_extra`= 2, `AIName`='SmartAI' WHERE `entry` IN (34146, 34150, 34151, 34137);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (34146,34150,34151,34137) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (34146*100,34150*100,34151*100) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (34146*100+1,34150*100+1,34151*100+1, @Jormungar*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(34146,0,0,0,10,0,100,1,0,15,1000,1000,80,34146*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Snow Mound - LOS - Action list'),
(34150,0,0,0,10,0,100,1,0,15,1000,1000,80,34150*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Snow Mound - LOS - Action list'),
(34151,0,0,0,10,0,100,1,0,15,1000,1000,80,34151*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Snow Mound - LOS - Action list'),
(34146*100,9,0,0,0,0,100,0,1000,1000,0,0,11,64629,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snow Mound - Action list - Eject Passenger'),
(34146*100,9,1,0,0,0,100,0,4000,4000,0,0,11,64630,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snow Mound - Action list - Eject Passenger'),
(34146*100,9,2,0,0,0,100,0,4000,4000,0,0,11,64631,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snow Mound - Action list - Eject Passenger'),
(34146*100,9,3,0,0,0,100,0,4000,4000,0,0,11,64632,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snow Mound - Action list - Eject Passenger'),
(34146*100,9,4,0,0,0,100,0,2000,2000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snow Mound - Action list - Despawn'),
(34150*100,9,0,0,0,0,100,0,1000,1000,0,0,11,64629,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snow Mound - Action list - Eject Passenger'),
(34150*100,9,1,0,0,0,100,0,4000,4000,0,0,11,64630,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snow Mound - Action list - Eject Passenger'),
(34150*100,9,2,0,0,0,100,0,4000,4000,0,0,11,64631,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snow Mound - Action list - Eject Passenger'),
(34150*100,9,3,0,0,0,100,0,4000,4000,0,0,11,64632,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snow Mound - Action list - Eject Passenger'),
(34150*100,9,4,0,0,0,100,0,4000,4000,0,0,11,64633,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snow Mound - Action list - Eject Passenger'),
(34150*100,9,5,0,0,0,100,0,4000,4000,0,0,11,64634,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snow Mound - Action list - Eject Passenger'),
(34150*100,9,6,0,0,0,100,0,2000,2000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snow Mound - Action list - Despawn'),
(34151*100,9,0,0,0,0,100,0,1000,1000,0,0,11,64629,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snow Mound - Action list - Eject Passenger'),
(34151*100,9,1,0,0,0,100,0,4000,4000,0,0,11,64630,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snow Mound - Action list - Eject Passenger'),
(34151*100,9,2,0,0,0,100,0,4000,4000,0,0,11,64631,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snow Mound - Action list - Eject Passenger'),
(34151*100,9,3,0,0,0,100,0,4000,4000,0,0,11,64632,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snow Mound - Action list - Eject Passenger'),
(34151*100,9,4,0,0,0,100,0,4000,4000,0,0,11,64633,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snow Mound - Action list - Eject Passenger'),
(34151*100,9,5,0,0,0,100,0,4000,4000,0,0,11,64634,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snow Mound - Action list - Eject Passenger'),
(34151*100,9,6,0,0,0,100,0,4000,4000,0,0,11,64635,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snow Mound - Action list - Eject Passenger'),
(34151*100,9,7,0,0,0,100,0,4000,4000,0,0,11,64636,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snow Mound - Action list - Eject Passenger'),
(34151*100,9,8,0,0,0,100,0,2000,2000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snow Mound - Action list - Despawn'),
(@Jormungar,0,0,0,0,0,100,0,2000,5000,7000,9000,11,64638,0,0,0,0,0,2,0,0,0,0,0,0,0,'Winter Jormungar - IC - Acidic Bite'),
(@Jormungar,0,1,0,23,0,100,1,43671,0,0,0,80,@Jormungar*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Winter Jormungar - On aura remove - Action list'),
(@Jormungar*100,9,1,0,0,0,100,0,1000,1000,0,0,49,0,0,0,0,0,0,21,70,0,0,0,0,0,0,'Winter Jormungar - Action list - Start attack');

DELETE FROM `creature_template_addon` WHERE `entry` IN (34146, 34150, 34151);
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`, `emote`, `auras`) VALUES
(@Triggger,0,4097,0,"64615"),
(@Triggger1,0,4097,0,"64615"),
(@Triggger2,0,4097,0,"64615");

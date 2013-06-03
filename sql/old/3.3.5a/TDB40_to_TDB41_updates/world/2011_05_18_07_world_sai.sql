-- Quest 12291 "The Forgotten Tale"
-- SAI for Forgotten Knight, Forgotten Rifleman, Forgotten Peasant, Forgotten Footman, Orik, & Forgotten Soul
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN (27224,27225,27226,27229,27220,27347,27465);
DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (27224,27225,27226,27229,27220,27347,27465);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (27224,27225,27226,27229,27220,27347,27465);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Forgotten Knight
(27224,0,0,1,62,0,100,0,9544,0,0,0,11,48831,3,0,0,0,0,7,0,0,0,0,0,0,0, 'Forgotten Knight - On gossip option select quest credit'),
(27224,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Forgotten Knight - Close Gossip'),
(27224,0,2,0,23,0,100,0,48143,0,0,0,11,48143,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Knight - Add Forgotten Aura if missing'),
(27224,0,3,4,4,0,100,0,0,0,0,0,11,38556,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Forgotten Knight - Cast Throw on Aggro'),
(27224,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Knight - Set Phase 1 on Aggro'),
(27224,0,5,6,0,1,100,0,5,35,2300,3900,11,38556,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Forgotten Knight - Cast Throw (Phase 1)'),
(27224,0,6,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Knight - Set Ranged Weapon Model (Phase 1)'),
(27224,0,7,8,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Knight - Start Combat Movement at 25 Yards (Phase 1)'),
(27224,0,8,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Forgotten Knight - Start Melee at 25 Yards (Phase 1)'),
(27224,0,9,10,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Knight - Start Combat Movement Below 5 Yards (Phase 1)'),
(27224,0,10,11,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Knight - Set Ranged Weapon Model Below 5 Yards (Phase 1)'),
(27224,0,11,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Forgotten Knight - Start Melee Below 5 Yards (Phase 1)'),
(27224,0,12,13,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Knight - Prevent Combat Movement at 15 Yards (Phase 1)'),
(27224,0,13,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Forgotten Knight - Prevent Melee at 15 Yards (Phase 1)'),
(27224,0,14,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Knight - Set Melee Weapon Model on Evade'),
-- Forgotten Rifleman
(27225,0,0,1,62,0,100,0,9543,0,0,0,11,48830,3,0,0,0,0,7,0,0,0,0,0,0,0, 'Forgotten Rifleman - On gossip option select quest credit'),
(27225,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Forgotten Rifleman - Close Gossip'),
(27225,0,2,3,11,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Rifleman - Prevent Combat Movement on Spawn'),
(27225,0,3,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Rifleman - Prevent Melee on Spawn'),
(27225,0,4,0,23,0,100,0,48143,0,0,0,11,48143,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Rifleman - Add Forgotten Aura if missing'),
(27225,0,5,6,4,0,100,0,0,0,0,0,11,15547,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Forgotten Rifleman - Cast Shoot on Aggro'),
(27225,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Rifleman - Set Phase 1 on Aggro'),
(27225,0,7,8,0,1,100,0,5,30,2300,3900,11,15547,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Forgotten Rifleman - Cast Shoot (Phase 1)'),
(27225,0,8,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Rifleman - Set Ranged Weapon Model (Phase 1)'),
(27225,0,9,0,0,1,100,0,9000,12000,9000,14000,11,17174,1,1,0,0,0,2,0,0,0,0,0,0,0, 'Forgotten Rifleman - Cast Concussive Shot (Phase 1)'),
(27225,0,10,11,9,1,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Rifleman - Start Combat Movement at 25 Yards (Phase 1)'),
(27225,0,11,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Forgotten Rifleman - Start Melee at 25 Yards (Phase 1)'),
(27225,0,12,13,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Rifleman - Start Combat Movement Below 5 Yards (Phase 1)'),
(27225,0,13,14,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Rifleman - Set Ranged Weapon Model Below 5 Yards (Phase 1)'),
(27225,0,14,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Forgotten Rifleman - Start Melee Below 5 Yards (Phase 1)'),
(27225,0,15,16,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Rifleman - Prevent Combat Movement at 15 Yards (Phase 1)'),
(27225,0,16,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Forgotten Rifleman - Prevent Melee at 15 Yards (Phase 1)'),
(27225,0,17,0,2,1,100,0,0,15,0,0,23,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Rifleman - Set Phase 2 at 15% HP'),
(27225,0,18,19,2,2,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Rifleman - Start Combat Movement at 15% HP (Phase 2)'),
(27225,0,19,20,61,2,100,0,0,0,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Rifleman - Flee at 15% HP (Phase 2)'),
(27225,0,20,21,61,2,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Rifleman - Say text0 at 15% HP (Phase 2)'),
(27225,0,21,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Rifleman - set phase 1 at 15% HP (Phase 2)'),
(27225,0,22,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Knight - Set Melee Weapon Model on Evade'),
-- Forgotten Peasant
(27226,0,0,1,62,0,100,0,9541,0,0,0,11,48829,3,0,0,0,0,7,0,0,0,0,0,0,0, 'Forgotten Peasant - On gossip option select quest credit'),
(27226,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Forgotten Peasant - Close Gossip'),
(27226,0,2,0,23,0,100,0,48143,0,0,0,11,48143,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Peasant - Add Forgotten Aura if missing'),
(27226,0,3,0,0,0,100,0,0,5,7000,10000,11,51601,1,0,0,0,0,2,0,0,0,0,0,0,0, 'Forgotten Peasant - Cast Bonk'),
-- Forgotten Footman
(27229,0,0,1,62,0,100,0,9545,0,0,0,11,48832,3,0,0,0,0,7,0,0,0,0,0,0,0, 'Forgotten Footman - On gossip option select quest credit'),
(27229,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Forgotten Footman - Close Gossip'),
(27229,0,2,0,23,0,100,0,48143,0,0,0,11,48143,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Footman - Add Forgotten Aura if missing'),
(27229,0,3,0,0,0,100,0,3000,7000,9000,12000,11,32587,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Forgotten Footman - Cast Shield Block'),
-- Forgotten Captain
(27220,0,0,0,23,0,100,0,48143,0,0,0,11,48143,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Captain - Add Forgotten Aura if missing'),
(27220,0,1,0,0,0,100,0,6000,9000,8000,12000,11,51591,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Forgotten Captain - Cast Stormhammer'),
-- Orik
(27347,0,0,1,62,0,100,0,9542,0,0,0,11,48828,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Orik - On gossip option select create Murkweed Elixir'),
(27347,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Orik - Close Gossip'),
-- Forgotten Soul
(27465,0,0,0,11,0,100,0,0,0,0,0,11,29266,3,0,0,0,0,1,0,0,0,0,0,0,0, 'Forgotten Soul - On aura self');

-- Assign Gossip_id's to creatures
UPDATE `creature_template` SET `gossip_menu_id`=9544 WHERE `entry`=27224; -- Forgotten Knight
UPDATE `creature_template` SET `gossip_menu_id`=9543 WHERE `entry`=27225; -- Forgotten Rifleman
UPDATE `creature_template` SET `gossip_menu_id`=9541 WHERE `entry`=27226; -- Forgotten Peasant
UPDATE `creature_template` SET `gossip_menu_id`=9545 WHERE `entry`=27229; -- Forgotten Footman
UPDATE `creature_template` SET `gossip_menu_id`=9542 WHERE `entry`=27347; -- Orik
-- Add gossip menu items
DELETE FROM `gossip_menu` WHERE `entry`=9544  AND `text_id`=12859;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9544,12859);
DELETE FROM `gossip_menu` WHERE `entry`=9543  AND `text_id`=12858;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9543,12858);
DELETE FROM `gossip_menu` WHERE `entry`=9541  AND `text_id`=12856;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9541,12856);
DELETE FROM `gossip_menu` WHERE `entry`=9545  AND `text_id`=12860;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9545,12860);
DELETE FROM `gossip_menu` WHERE `entry`=9542  AND `text_id`=12857;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (9542,12857);

-- Gossip Options
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9544,9543,9541,9545,9542);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9544,0,0,'I must be going now, soldier. Stay vigilant!',1,1,0,0,0,0,0,''), -- Forgotten Knight
(9543,0,0,'I''m sure Arthas will be back any day now, soldier. Keep your chin up!',1,1,0,0,0,0,0,''), -- Forgotten Rifleman
(9541,0,0,'Sorry to have bothered you, friend. Carry on!',1,1,0,0,0,0,0,''), -- Forgotten Peasant
(9545,0,0,'I''m sure everything will work out, footman.',1,1,0,0,0,0,0,''), -- Forgotten Footman
(9542,0,0,'Orik, I need another Murkweed Elixir.',1,1,0,0,0,0,0,''); -- Orik

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (9544,9543,9541,9545,9542);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9544,0,0,9,12291,0,0,0,'','Show gossip option 0 if player has Quest 12291 "The Forgotten Tale"'),
(15,9543,0,0,9,12291,0,0,0,'','Show gossip option 0 if player has Quest 12291 "The Forgotten Tale"'),
(15,9541,0,0,9,12291,0,0,0,'','Show gossip option 0 if player has Quest 12291 "The Forgotten Tale"'),
(15,9545,0,0,9,12291,0,0,0,'','Show gossip option 0 if player has Quest 12291 "The Forgotten Tale"'),
(15,9542,0,0,9,12291,0,0,0,'','Show gossip option 0 if player has Quest 12291 "The Forgotten Tale"');

-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry` IN (27225);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(27225,0,0, '%s attempts to run away in fear!',2,0,100,0,0,0, 'Forgotten Rifleman');

-- Add spell linking
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (48810,-48809,48143,-48143);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(48810,48809,0,'Cast Binding Life when cast Death''s Door'),
(-48809,-48143,0,'Removing Binding Life removes Forgotten Aura'),
(48143,48357,0,'Aura Wintergarde Invisibility Type B when aura Forgotten Aura'),
(-48143,-48357,0,'Removing Binding Forgotten Aura removes Aura Wintergarde Invisibility Type B');

-- Add See Wintergarde Invisibility Type B Spell to areas in Dragonblight
DELETE FROM `spell_area` WHERE `spell`=48358;
INSERT INTO `spell_area` (`spell`,`area`,`racemask`,`gender`,`autocast`) VALUES
(48358,4151,0,2,1),(48358,4152,0,2,1),(48358,4153,0,2,1),(48358,4154,0,2,1),
(48358,4155,0,2,1),(48358,4156,0,2,1),(48358,4157,0,2,1),(48358,4158,0,2,1),
(48358,4160,0,2,1),(48358,4161,0,2,1),(48358,4162,0,2,1),(48358,4163,0,2,1),
(48358,4164,0,2,1),(48358,4165,0,2,1),(48358,4166,0,2,1),(48358,4167,0,2,1),
(48358,4168,0,2,1),(48358,4169,0,2,1),(48358,4170,0,2,1),(48358,4171,0,2,1),
(48358,4172,0,2,1),(48358,4173,0,2,1),(48358,4174,0,2,1),(48358,4175,0,2,1),
(48358,4176,0,2,1),(48358,4177,0,2,1),(48358,4178,0,2,1),(48358,4179,0,2,1),
(48358,4180,0,2,1),(48358,4181,0,2,1),(48358,4182,0,2,1),(48358,4183,0,2,1),
(48358,4184,0,2,1),(48358,4185,0,2,1),(48358,4186,0,2,1),(48358,4187,0,2,1),
(48358,4188,0,2,1),(48358,4189,0,2,1),(48358,4190,0,2,1),(48358,4191,0,2,1),
(48358,4192,0,2,1),(48358,4193,0,2,1),(48358,4194,0,2,1),(48358,4195,0,2,1),
(48358,4198,0,2,1),(48358,4123,0,2,1),(48358,4124,0,2,1),(48358,4125,0,2,1),
(48358,4127,0,2,1),(48358,4130,0,2,1),(48358,4132,0,2,1),(48358,4133,0,2,1),
(48358,4134,0,2,1),(48358,4141,0,2,1),(48358,4143,0,2,1),(48358,4146,0,2,1),
(48358,4396,0,2,1),(48358,4414,0,2,1),(48358,4478,0,2,1);

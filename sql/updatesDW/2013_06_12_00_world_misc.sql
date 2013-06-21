DELETE FROM gossip_menu WHERE entry=11135;
INSERT INTO `gossip_menu` VALUES ('11135', '15487');
DELETE FROM gossip_menu_option WHERE menu_id=11135;
INSERT INTO `gossip_menu_option` VALUES ('11135', '0', '0', 'I\'m here to rescue you.', '0', '0', '0', '0', '0', '0', '');
-- http://www.wowhead.com/npc=1753
DELETE FROM creature WHERE guid=7238585;
INSERT INTO `creature` VALUES ('7238585', '1753', '0', '0', '0', '1', '1', '0', '1', '2901.64', '383.492', '31.1771', '2.67998', '300', '0', '0', '156', '0', '0', '0', '0', '0');
-- http://www.wowhead.com/npc=39002
DELETE FROM creature WHERE guid=31034;
DELETE FROM creature WHERE guid=7239064;
DELETE FROM `creature_template` WHERE `entry`=39002 LIMIT 1;
INSERT INTO `creature_template` ( `entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES ( 39002, 0, 0, 0, 0, 0, 24556, 0, 0, 0, "Scarlet Lieutenant Gebler", "", "", 0, 15, 15, 0, 14, 14, 0, 1.0, 1.14286, 1.0, 0, 41, 56, 0, 103, 1.0, 2000, 2000, 1, 0, 0, 0, 0, 0, 0, 0, 41.8, 55.1, 103, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "SmartAI", 0, 3, 2.0, 0.0, 1.0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, "", "13623");
UPDATE `creature_template` SET `gossip_menu_id` = 11135, `AIName` = '' WHERE `entry` = 38999;
UPDATE `gossip_menu_option` SET `option_id`='1', `npc_option_npcflag`='1' WHERE (`menu_id`='11135') AND (`id`='0');
UPDATE `gossip_menu_option` SET `action_menu_id`='11134' WHERE (`menu_id`='11135') AND (`id`='0');
UPDATE `gossip_menu_option` SET `option_id`='1', `npc_option_npcflag`='1', `action_menu_id`='11136' WHERE (`menu_id`='11134') AND (`id`='0');
UPDATE `gossip_menu_option` SET `option_id`='1', `npc_option_npcflag`='1' WHERE (`menu_id`='11136') AND (`id`='0');
-- Lilian Voss
SET @ENTRY := 38999;
SET @SOURCETYPE := 0;
 DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,1,62,0,100,0,11136,0,0,0,80,3899900,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"call event on gossip select 11136"),
(@ENTRY,@SOURCETYPE,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"close gossip");
 -- Lilian Voss
SET @ENTRY := 3899900;
SET @SOURCETYPE := 9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Talk 0"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,2000,2000,2000,2000,12,39002,7,0,0,0,0,8,0,0,0,2446.84,1597.22,67.73,5.38,"Summon lieutenant"),
(@ENTRY,@SOURCETYPE,2,0,0,0,100,0,13000,13000,13000,13000,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 1"),
(@ENTRY,@SOURCETYPE,3,0,0,0,100,0,8000,8000,8000,8000,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 2"),
(@ENTRY,@SOURCETYPE,4,0,0,0,100,0,12000,12000,12000,12000,11,73304,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"cast 73304 on self and jump on lieutenant to kill him"),
(@ENTRY,@SOURCETYPE,5,0,0,0,100,0,1500,1500,1500,1500,11,46598,0,0,0,0,0,19,39002,20,0,0.0,0.0,0.0,0.0,"Jump on lieutenant"),
(@ENTRY,@SOURCETYPE,6,0,0,0,100,0,2500,2500,2500,2500,97,10,10,0,0,0,0,8,0,0,0,2442.93,1600.72,72.15,1.94,"Jump back"),
(@ENTRY,@SOURCETYPE,7,0,0,0,100,0,1000,1000,1000,1000,1,3,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 3"),
(@ENTRY,@SOURCETYPE,8,0,0,0,100,0,4000,4000,4000,4000,1,4,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 4"),
(@ENTRY,@SOURCETYPE,9,0,0,0,100,0,0,0,0,0,33,38999,0,0,0,0,0,17,0,50,0,0.0,0.0,0.0,0.0,"Give credit to player"),
(@ENTRY,@SOURCETYPE,10,0,0,0,100,0,1000,1000,1000,1000,41,1000,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Force despawn");
 DELETE FROM waypoints WHERE entry=3900200;
INSERT INTO waypoints(entry, pointid, position_x, position_y, position_z)  VALUES
(3900200, 1, 2441.31, 1598.17, 72.1557);
-- Scarlet Lieutenant Gebler
SET @ENTRY := 39002;
SET @SOURCETYPE := 0;
 DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,54,0,100,0,0,0,0,0,80,3900200,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"On summonet call time action"),
(@ENTRY,@SOURCETYPE,1,2,8,0,100,0,46598,0,0,0,11,73304,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"cast 73304 on self when lilian jump on him"),
(@ENTRY,@SOURCETYPE,2,0,61,0,100,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"die");
 -- Scarlet Lieutenant Gebler
SET @ENTRY := 3900200;
SET @SOURCETYPE := 9;
 DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,0,0,100,0,0,0,0,0,53,0,3900200,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Do wp 3900200"),
(@ENTRY,@SOURCETYPE,1,0,0,0,100,0,10000,10000,10000,10000,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 0"),
(@ENTRY,@SOURCETYPE,2,0,0,0,100,0,8000,8000,8000,8000,1,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 1"),
(@ENTRY,@SOURCETYPE,3,0,0,0,100,0,6000,6000,6000,6000,1,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 2"),
(@ENTRY,@SOURCETYPE,4,0,0,0,100,0,5000,5000,5000,5000,1,3,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"talk 3");
 DELETE FROM creature_text WHERE entry in (38999,39002);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(38999, 0, 0, 'Yes, my... wait, be quiet! I hear the lieutenant approaching.', 12, 0, 100, 0, 0, 0, 'Lilian Voss'),
(38999, 1, 0, 'Gebler, you came! What did he say?', 12, 0, 100, 0, 0, 0, 'Lilian Voss'),
(38999, 2, 0, 'What? NO! This can''t be! Gebler, you know me... we were friends once!', 12, 0, 100, 0, 0, 0, 'Lilian Voss'),
(38999, 3, 0, 'Gebler, father, why would you...', 12, 0, 100, 0, 0, 0, 'Lilian Voss'),
(38999, 4, 0, 'The world of the living may have turned its back on me, but I''m no damned Scourge. Just go.', 12, 0, 100, 0, 0, 0, 'Lilian Voss'),
(39002, 0, 0, 'The time has come, my little captive... word has come back from your father.', 12, 0, 100, 0, 0, 0, 'Scharlachroter Leutnant Gebler'),
(39002, 1, 0, 'High Priest Voss denounces you as a daughter. He''s ordered that you be executed immediately.', 12, 0, 100, 0, 0, 0, 'Scharlachroter Leutnant Gebler'),
(39002, 2, 0, 'The High Priest sends his regrets. He head hoped that one day you would be a powerful weapon against our enemies.', 12, 0, 100, 0, 0, 0, 'Scharlachroter Leutnant Gebler'),
(39002, 3, 0, 'Unfortunately, you were too dangerous in life, and you''re far too dangerous in undeath. I will enjoy killing you, you Scourged witch...', 12, 0, 100, 0, 0, 0, 'Scharlachroter Leutnant Gebler');
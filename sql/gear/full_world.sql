INSERT INTO creature_template (entry, modelid1, name, subname, IconName, gossip_menu_id, minlevel, maxlevel, Health_mod, Mana_mod, Armor_mod, faction_A, faction_H, npcflag, speed_walk, speed_run, scale, rank, dmg_multiplier, unit_class, unit_flags, type, type_flags, InhabitType, RegenHealth, flags_extra, ScriptName) VALUES 
('190001', '15998', "Warpweaver", "Transmogrifier", 'Speak', '50000', 71, 71, 1.56, 1.56, 1.56, 35, 35, 3, 1, 1.14286, 1.25, 1, 1, 1, 2, 7, 138936390, 3, 1, 2, 'npc_transmogrify'); 

INSERT INTO locales_creature VALUES ('190001', '', '', '', '', '', '', '', 'Искажающий пространство', null, null, null, null, null, null, null, 'Трансмогрификатор');

INSERT INTO `gossip_menu` VALUES (51000, 51000);

INSERT INTO npc_text (ID, text0_0, em0_1) VALUES
(51000, 'Put in the first slot of bag item, that you want to transmogrify. In the second slot, put item with perfect display.', 0);

INSERT INTO locales_npc_text VALUES ('51000', null, null, null, null, null, null, null, 'Положите в первый слот рюкзака предмет, который вы хотите исказить. Во второй слот предмет, модель которого будет использована для трансмогрификации.', null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null, null);

UPDATE `gameobject_template` SET `flags` = '36' WHERE `entry` IN (192642,192643);
DELETE FROM disables WHERE sourceType = 3 AND entry IN (10,11);


DELETE FROM `command` WHERE `name` = 'spectate';        
INSERT INTO `command` (`name`, `security`, `help`) VALUES ('spectate', 0, 'Syntax: .spectate $subcommand.\nUse .help sppectate');
DELETE FROM `command` WHERE `name` = 'spectatefrom';    
INSERT INTO `command` (`name`, `security`, `help`) VALUES ('spectate view', 0, 'Syntax: .spectate view #player\nAllow player to spectate arena from anotherplayer.');
DELETE FROM `command` WHERE `name` = 'spectate leav';   
INSERT INTO `command` (`name`, `security`, `help`) VALUES ('spectate leave', 0, 'Syntax: .spectate leave\nDisable spectator mode.');
DELETE FROM `command` WHERE `name` = 'spectate player'; 
INSERT INTO `command` (`name`, `security`, `help`) VALUES ('spectate player', 0, 'Syntax: .spectate player #player\nAllow to spectate player.');
DELETE FROM `command` WHERE `name` = 'spectate reset';  
INSERT INTO `command` (`name`, `security`, `help`) VALUES ('spectate reset', 0, 'Syntax: .spectate reset\nSend addon data.');

UPDATE `gameobject_template` SET `flags` = 36 WHERE entry IN (185918, 185917, 183970, 183971, 183972, 183973, 183977, 183979, 183978, 183980);

DELETE FROM creature_template WHERE entry = '190000'; 
INSERT INTO creature_template (entry, modelid1, name, subname, IconName, gossip_menu_id, minlevel, maxlevel, Health_mod, Mana_mod, Armor_mod, faction_A, faction_H, npcflag, speed_walk, speed_run, scale, rank, dmg_multiplier, unit_class, unit_flags, type, type_flags, InhabitType, RegenHealth, flags_extra, ScriptName) VALUES 
('190000', '29348', "Arena Spectator", "Use addon!", 'Speak', '50000', 71, 71, 1.56, 1.56, 1.56, 35, 35, 3, 1, 1.14286, 1.25, 1, 1, 1, 2, 7, 138936390, 3, 1, 2, 'npc_arena_spectator'); 

-- Anticheat
REPLACE INTO `command` (`name`,`security`,`help`) VALUES ('anticheat global', '2', 'Syntax: .anticheat 
global returns the total amount reports and the average. (top three players)'), ('anticheat player', '2', 
'Syntax: .anticheat player $name returns the players''s total amount of warnings, the average and the 
amount of each cheat type.'), ('anticheat handle', '2', 'Syntax: .anticheat handle [on|off] Turn on/off the 
AntiCheat-Detection .'),
('anticheat delete', '2', 'Syntax: .anticheat delete [deleteall|$name] Deletes the report records of all the players or deletes all the reports of player $name.');

-- fix mobs aggro for keldelar quest npc
UPDATE `quest_template` SET `SourceSpellId` = '70974' WHERE `Id` =20439;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 31885;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 31886;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 31557;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 32419;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 32420;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 32253;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 32415;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 32412;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 32251;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 32252;
UPDATE `quest_template` SET `SourceSpellId` = '70972' WHERE `Id` =24451;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 35507;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 31580;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 31579;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 35494;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 37942;
UPDATE `creature_template` SET `flags_extra` = '2' WHERE `entry` = 33964;  

-- fix 12856 (Cold Hearted)
-- captive proto-drake
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=29708;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`)
VALUES (29708,55028,1,0);
-- freed proto-drake
DELETE FROM `creature_template_addon` WHERE `entry`=29709;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(29709,0,50331648,257,0, NULL);
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|16777216, `ScriptName`='' WHERE `entry`=29708;
UPDATE `creature_template` SET `InhabitType`=7 WHERE `entry`=29709;

-- hack quest "An End To All Things..."
UPDATE `quest_template` SET Method = 0 WHERE `Id` = 12779;

-- Argent Tournament quests fixes start
-- npc_lake_frog
UPDATE `creature_template` SET `ScriptName` = 'npc_lake_frog' WHERE `entry` IN (33211,33224);
SET @GOSSIP := 33220;
SET @MENUID := 0;
DELETE FROM `creature_ai_scripts` WHERE `creature_id` = 33220;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 33220;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(33220,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Maiden of Ashwood Lake - On gossip option 0 select - Close gossip'),
(33220,0,1,0,61,0,100,0,0,0,0,0,85,62554,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Maiden of Ashwood Lake - On gossip option 0 select - Player cast Summon Ashwood Brand on self');
UPDATE `creature_template` SET `gossip_menu_id` = @GOSSIP, `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` = 33220;
REPLACE INTO `gossip_menu_option` (`menu_id`, `id`, `option_text`, `option_id`, `npc_option_npcflag`) VALUES (@GOSSIP, @MENUID, 'Do you know, where I can find Ashwood Brand Sword?', '1', '1');

-- fix The Black Knight's Orders quest
UPDATE `creature_template` SET `VehicleId` = 369, `InhabitType` = 7 WHERE `entry` = 33519;
SET @ENTRY :=33519;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,27,0,100,0,0,0,0,0,53,0,@ENTRY,0,13663,0,0,1,0,0,0,0,0,0,0,'Black Knight''s Gryphon - On Passenger - Start WP movement'),
(@ENTRY,0,1,0,40,0,100,0,40,@ENTRY,0,0,33,33519,0,0,0,0,0,7,0,0,0,0,0,0,0,'Black Knight''s Gryphon - Quest Credit'),
(@ENTRY,0,2,0,40,0,100,0,43,@ENTRY,0,0,11,50630,0,0,0,0,0,7,0,0,0,0,0,0,0,'Black Knight''s Gryphon - Dismount Spell'),
(@ENTRY,0,3,0,40,0,100,0,44,@ENTRY,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Black Knight''s Gryphon - Despawn');
DELETE FROM `waypoints` WHERE `entry`=33519;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(33519,1,8521.271,569.596,552.8375,'Black Knight''s Gryphon'),
(33519,2,8517.864,579.1095,553.2125,'Black Knight''s Gryphon'),
(33519,3,8513.146,594.6724,551.2125,'Black Knight''s Gryphon'),
(33519,4,8505.263,606.5569,550.4177,'Black Knight''s Gryphon'),
(33519,5,8503.017,628.4188,547.4177,'Black Knight''s Gryphon'),
(33519,6,8480.271,652.7083,547.4177,'Black Knight''s Gryphon'),
(33519,7,8459.121,686.1427,547.4177,'Black Knight''s Gryphon'),
(33519,8,8436.802,713.8687,547.3428,'Black Knight''s Gryphon'),
(33519,9,8405.380,740.0045,547.4177,'Black Knight''s Gryphon'),
(33519,10,8386.139,770.6009,547.5881,'Black Knight''s Gryphon'),
(33519,11,8374.297,802.2525,547.9304,'Black Knight''s Gryphon'),
(33519,12,8374.271,847.0363,548.0427,'Black Knight''s Gryphon'),
(33519,13,8385.988,868.9881,548.0491,'Black Knight''s Gryphon'),
(33519,14,8413.027,867.8573,547.2991,'Black Knight''s Gryphon'),
(33519,15,8452.552,869.0339,547.2991,'Black Knight''s Gryphon'),
(33519,16,8473.058,875.2012,547.2955,'Black Knight''s Gryphon'),
(33519,17,8472.278,912.3134,547.4169,'Black Knight''s Gryphon'),
(33519,18,8479.666,954.1650,547.3298,'Black Knight''s Gryphon'),
(33519,19,8477.349,1001.368,547.3372,'Black Knight''s Gryphon'),
(33519,20,8484.538,1025.797,547.4622,'Black Knight''s Gryphon'),
(33519,21,8525.363,1029.284,547.4177,'Black Knight''s Gryphon'),
(33519,22,8532.808,1052.904,548.1677,'Black Knight''s Gryphon'),
(33519,23,8537.356,1077.927,554.5791,'Black Knight''s Gryphon'),
(33519,24,8540.528,1083.379,569.6827,'Black Knight''s Gryphon'),
(33519,25,8563.641,1140.965,569.6827,'Black Knight''s Gryphon'),
(33519,26,8594.897,1205.458,569.6827,'Black Knight''s Gryphon'),
(33519,27,8617.104,1257.399,566.1833,'Black Knight''s Gryphon'),
(33519,28,8648.496,1329.349,558.0187,'Black Knight''s Gryphon'),
(33519,29,8667.723,1388.411,546.188,'Black Knight''s Gryphon'),
(33519,30,8699.145,1474.898,528.2197,'Black Knight''s Gryphon'),
(33519,31,8726.869,1546.006,501.7741,'Black Knight''s Gryphon'),
(33519,32,8739.058,1592.157,478.5511,'Black Knight''s Gryphon'),
(33519,33,8750.799,1636.771,455.0797,'Black Knight''s Gryphon'),
(33519,34,8760.006,1669.482,423.2208,'Black Knight''s Gryphon'),
(33519,35,8783.31,1701.852,375.8872,'Black Knight''s Gryphon'),
(33519,36,8817.336,1735.731,343.3323,'Black Knight''s Gryphon'),
(33519,37,8882.32,1789.754,301.5807,'Black Knight''s Gryphon'),
(33519,38,8958.597,1841.807,259.9141,'Black Knight''s Gryphon'),
(33519,39,9045.891 ,1908.076,233.4143,'Black Knight''s Gryphon'),
(33519,40,9107.177,1964.594,215.9704,'Black Knight''s Gryphon'),
(33519,41,9134.763,2036.925,175.1925,'Black Knight''s Gryphon'),
(33519,42,9128.608,2089.091,141.3593,'Black Knight''s Gryphon'),
(33519,43,9093.364,2128.384,99.38685,'Black Knight''s Gryphon'),
(33519,44,9050.709,2123.656,60.24802,'Black Knight''s Gryphon');

-- The Valiant's Challenge
UPDATE `creature_template` SET `ScriptName` = 'npc_squire_danny' WHERE `entry` = 33518;
UPDATE `creature_template` SET `KillCredit1` = 33708 WHERE `entry` = 33707;
UPDATE `creature_template` SET `ScriptName` = 'npc_argent_champion' WHERE `entry` = 33707;
DELETE FROM `creature_template_addon` WHERE `entry` = 33707;
INSERT INTO `creature_template_addon` (`entry`, `mount`) VALUES ('33707', '14337');
-- Argent Tournament quests fixes end

-- Battered Hilt quest chains fixes start
-- Quests 20438,24556
DELETE FROM gameobject WHERE id=201384;
SET @ENTRY := 36856;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,62,0,100,0,10854,1,0,0,50,201384,60,0,0,0,0,8,0,0,0,5802.22,691.556,657.949,3.50801,"Script for http://wowhead.com/quest=20438"),
(@ENTRY,@SOURCETYPE,1,0,62,0,100,0,10854,0,0,0,50,201384,60,0,0,0,0,8,0,0,0,5802.22,691.556,657.949,3.50801,"Script for http://wowhead.com/quest=24556");
-- Quest 20439
SET @ENTRY := 36670;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,@SOURCETYPE,0,0,62,0,100,0,10857,1,0,0,56,49698,1,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Script for http://wowhead.com/quest=20439");
-- Quests 24563, 24535
SET @ENTRY := 37552;
SET @GOSSIP := 37552;
SET @MENUID := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,62,0,100,0,@GOSSIP,@MENUID,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Thalorien Dawnseeker - On gossip option 0 select - Close gossip'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,85,70265,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Thalorien Dawnseeker - On gossip option 0 select - Player cast credit on self'),
(@ENTRY,0,2,1,62,0,100,0,@GOSSIP,@MENUID+1,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Thalorien Dawnseeker - On gossip option 1 select - Close gossip');
UPDATE `creature_template` SET `gossip_menu_id` = @GOSSIP, `AIName`= 'SmartAI',`ScriptName`= '' WHERE `entry` = @ENTRY;
REPLACE INTO `gossip_menu_option` (`menu_id`, `id`, `option_text`, `option_id`, `npc_option_npcflag`) VALUES (@GOSSIP, @MENUID, 'Examine the remains.', '1', '1');
REPLACE INTO `gossip_menu_option` (`menu_id`, `id`, `option_text`, `option_id`, `npc_option_npcflag`) VALUES (@GOSSIP, @MENUID+1, 'Examine the remains.', '1', '1');
-- Quest 24553
SET @ENTRY := 37523;
SET @SOURCETYPE := 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=@SOURCETYPE;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY LIMIT 1;
INSERT INTO `smart_scripts`  (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`)  VALUES 
(@ENTRY,@SOURCETYPE,0,0,62,0,100,0,37523,0,0,0,11,70746,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Script for http://ru.wowhead.com/npc=37523"),
(@ENTRY,@SOURCETYPE,1,0,62,0,100,0,37523,1,0,0,11,70746,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Script for http://ru.wowhead.com/npc=37523"),
(@ENTRY,@SOURCETYPE,2,0,62,0,100,0,37523,2,0,0,11,70746,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Script for http://ru.wowhead.com/npc=37523"),
(@ENTRY,@SOURCETYPE,3,0,62,0,100,0,37523,3,0,0,11,70746,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Script for http://ru.wowhead.com/npc=37523"),
(@ENTRY,@SOURCETYPE,4,0,62,0,100,0,37523,4,0,0,11,70746,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Script for http://ru.wowhead.com/npc=37523"),
(@ENTRY,@SOURCETYPE,5,0,62,0,100,0,37523,5,0,0,11,70746,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Script for http://ru.wowhead.com/npc=37523");

-- ICC weapons procs
-- (71845) Item - Icecrown 25 Normal Caster Weapon Proc 
DELETE FROM `spell_proc_event` WHERE `entry` IN (71845); 
INSERT INTO `spell_proc_event` VALUES (71845, 0x01, 0x00, 0x00000000, 0x00000000, 0x00000000, 0x00010000, 0x00000000, 0, 2, 40); 
-- (71845) Item - Icecrown 25 Normal Caster Weapon Proc 
DELETE FROM `spell_proc_event` WHERE `entry` IN (71845); 
INSERT INTO `spell_proc_event` VALUES (71845, 0x01, 0x00, 0x00000000, 0x00000000, 0x00000000, 0x00010000, 0x00000000, 0, 2, 45);
-- (71865) Item - Icecrown 25 Normal Healer Weapon Proc 
DELETE FROM `spell_proc_event` WHERE `entry` IN (71865); 
INSERT INTO `spell_proc_event` VALUES (71865, 0x01, 0x0A, 0x00000000, 0x00000000, 0x00000000, 0x00044000, 0x00000018, 0, 1, 0); 
-- (71868) Item - Icecrown 25 Heroic Healer Weapon Proc 
DELETE FROM `spell_proc_event` WHERE `entry` IN (71868); 
INSERT INTO `spell_proc_event` VALUES (71868, 0x01, 0x0A, 0x00000000, 0x00000000, 0x00000000, 0x00044000, 0x00000018, 0, 1, 0); 

-- Fizzcrank Recon Pilot
DELETE FROM `creature_ai_scripts` WHERE creature_id = 25841;
UPDATE `creature_template` SET IconName = 'Speak', npcflag = 1, gossip_menu_id = 0, AIName = '', ScriptName = 'npc_recon_pilot', unit_flags = 0x00000000, flags_extra = 2, dynamicflags = 36  WHERE entry = 25841;
DELETE FROM `creature_template_addon` WHERE entry = 25841;
INSERT INTO `creature_template_addon` VALUES (25841, 0, 0, 7, 0, 65, '');

-- Open Halls of Reflection without quest
UPDATE `access_requirement` set `quest_done_A`=0, `quest_done_H`=0 where `mapId` = 668;

-- Item - Hunter T10 Survival 2P Bonus
DELETE FROM `spell_proc_event` WHERE `entry` = 70727;
INSERT INTO `spell_proc_event` VALUES (70727, 0, 9, 0, 0, 0, 64, 0, 0, 5, 0); 
-- Item - Hunter T10 Survival 4P Bonus
DELETE FROM `spell_proc_event` WHERE `entry` = 70730;
INSERT INTO `spell_proc_event` VALUES (70730, 0, 9, 16384, 4096, 0, 262144, 0, 0, 5, 0);  

-- set visible intendants of The Sons of Hodir and Knights of the Ebon Blade
UPDATE `creature` SET phaseMask=65535 WHERE `id` in (32538,32540);

-- [Dungeon Finder] Fix Drak'Tharon Keep reward for DF
UPDATE `instance_encounters` SET `creditType` = '0', `creditEntry` = '26632' WHERE `entry` IN ('376', '375');
-- [Dungeon Finder] Fix reward for Utgarde Keep.
UPDATE `instance_encounters` SET `creditEntry` = '23980' WHERE `entry` IN ('575', '576');
-- [Dungeon Finder] Fix CoS reward
UPDATE `instance_encounters` SET `creditType`=0, `creditEntry`=26533 WHERE `entry` IN (296, 300);

-- fix for YTDB after "guards don't evade..." commit
UPDATE `creature_template` SET `Unit_flags` = 36864 WHERE `entry` = 3296;

-- another fix for YTDB for unit_flags 
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 16844;
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 16857;
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 16968;
UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 25760;
UPDATE `creature_template` SET `Unit_flags` = 36864 WHERE `entry` = 3296;
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 26076;
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 26073;

-- fix flag for Sunreaver Agent NPC.
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 36776;

-- fix flag for Silver Covenant Agent
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 36774; 

-- DB/Achievements: Fix achievement "Lonely?"
UPDATE `gameobject_template` SET `data10`=45123 WHERE `entry`=187267;

-- Dangerous Love achievement
-- Alliance
UPDATE quest_template SET prevQuestId = 0 where ExclusiveGroup = 24638;
-- Horde
UPDATE quest_template SET prevQuestId = 0 where ExclusiveGroup = 24658;
-- Alliance
UPDATE quest_template SET prevQuestId = 24576 where ExclusiveGroup = 24638;
-- Horde
UPDATE quest_template SET prevQuestId = 24657 where ExclusiveGroup = 24658;

-- Cinderglacier
UPDATE `spell_proc_event` SET `SpellFamilyName` = '15', `SpellFamilyMask0` = 0x42002, `SpellFamilyMask1` = 0x6, `SpellFamilyMask2` = 0x80 WHERE `entry` = 53386;


-- Fixed shaman's talent Elemental Focus
UPDATE `spell_proc_event` SET `SpellFamilyMask0` = `SpellFamilyMask0` &~ 192 WHERE `entry` = 16164;

-- Fixed spell Anti-Magic Zone
UPDATE `creature_template` SET `modelid1` = 11686, `unit_flags` = 33554432 WHERE `modelid1` = 4590 AND `entry` = 28306;

-- Fix Druid Enrage spell
DELETE FROM `spell_ranks` WHERE `first_spell_id` = 1178;
INSERT INTO `spell_ranks` VALUES 
(1178,1178,1),
(1178,9635,2);

-- Fixed warlock's talent Empowered Imp
UPDATE `spell_proc_event` set `procFlags` = 0x00010004 WHERE `entry` = 54278;

-- Fixed talent Scent of Blood for death knights
DELETE FROM `spell_proc_event` WHERE `entry` IN (49004,49508,49509);
INSERT INTO `spell_proc_event` (`entry`,`procEx`) VALUES
(49004,0x00000033),
(49508,0x00000033),
(49509,0x00000033);

-- Fixed paladin's talent Blessing of Sanctuary
DELETE FROM `spell_dbc` WHERE `id` = 20912;
INSERT INTO `spell_dbc` (`Id`,`CastingTimeIndex`,`DurationIndex`,`RangeIndex`,`Effect1`,`EffectBasePoints1`,`EffectImplicitTargetA1`,`EffectApplyAuraName1`,`EffectMiscValue1`,`SpellFamilyName`,`Comment`) VALUES
(20912,1,21,1,6,-3,1,87,127,10,'Blessing of Sanctuary Helper (SERVERSIDE)');
-- Blessing of Sanctuary vs Vigilance
UPDATE `spell_group` SET `spell_id` = 68066 WHERE `id` = 1091 and `spell_id` = 47930;
UPDATE `spell_group` SET `spell_id` = 20912 WHERE `id` = 1092 and `spell_id` = 20911;

-- Fixed mage's talent Hot Streak
UPDATE `spell_proc_event` SET `SpellFamilyMask1`=`SpellFamilyMask1`|0x00010000 WHERE `entry` IN (44445,44446,44448);

-- Fix drop for Damaged Necklace item (43297)
DELETE FROM `creature_loot_template` WHERE `item` = 43297;
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(25801, 43297, 0.027, 1, 0, 1, 1),
(26828, 43297, 0.1, 1, 0, 1, 1),
(26862, 43297, 0.1, 1, 0, 1, 1),
(26943, 43297, 0.1, 1, 0, 1, 1),
(27105, 43297, 0.0898, 1, 0, 1, 1),
(27210, 43297, 0.033, 1, 0, 1, 1),
(27860, 43297, 0.0802, 1, 0, 1, 1),
(28022, 43297, 0.024, 1, 0, 1, 1),
(28026, 43297, 0.0167, 1, 0, 1, 1),
(28035, 43297, 0.0197, 1, 0, 1, 1),
(28036, 43297, 0.0138, 1, 0, 1, 1),
(28068, 43297, 0.0493, 1, 0, 1, 1),
(28080, 43297, 0.0341, 1, 0, 1, 1),
(28081, 43297, 0.0194, 1, 0, 1, 1),
(28101, 43297, 0.0366, 1, 0, 1, 1),
(28108, 43297, 0.0161, 1, 0, 1, 1),
(28123, 43297, 0.0201, 1, 0, 1, 1),
(28124, 43297, 0.0127, 1, 0, 1, 1),
(28158, 43297, 0.0142, 1, 0, 1, 1),
(28186, 43297, 0.0456, 1, 0, 1, 1),
(28255, 43297, 0.0392, 1, 0, 1, 1),
(28257, 43297, 0.0272, 1, 0, 1, 1),
(28303, 43297, 0.014, 1, 0, 1, 1),
(28373, 43297, 0.0249, 1, 0, 1, 1),
(28388, 43297, 0.0176, 1, 0, 1, 1),
(28402, 43297, 0.0118, 1, 0, 1, 1),
(28403, 43297, 0.0113, 1, 0, 1, 1),
(28412, 43297, 0.0282, 1, 0, 1, 1),
(28417, 43297, 0.0109, 1, 0, 1, 1),
(28418, 43297, 0.01, 1, 0, 1, 1),
(28443, 43297, 0.0433, 1, 0, 1, 1),
(28465, 43297, 0.0254, 1, 0, 1, 1),
(28494, 43297, 0.0383, 1, 0, 1, 1),
(28504, 43297, 0.0117, 1, 0, 1, 1),
(28538, 43297, 0.0171, 1, 0, 1, 1),
(28565, 43297, 0.0127, 1, 0, 1, 1),
(28575, 43297, 0.0159, 1, 0, 1, 1),
(28600, 43297, 0.022, 1, 0, 1, 1),
(28641, 43297, 0.0176, 1, 0, 1, 1),
(28659, 43297, 0.0471, 1, 0, 1, 1),
(28747, 43297, 0.0079, 1, 0, 1, 1),
(28748, 43297, 0.0192, 1, 0, 1, 1),
(28802, 43297, 0.0259, 1, 0, 1, 1),
(28861, 43297, 0.1, 1, 0, 1, 1),
(28917, 43297, 0.02, 1, 0, 1, 1),
(29323, 43297, 0.0066, 1, 0, 1, 1),
(29329, 43297, 0.0098, 1, 0, 1, 1),
(29330, 43297, 0.016, 1, 0, 1, 1),
(29333, 43297, 0.0107, 1, 0, 1, 1),
(29338, 43297, 0.0191, 1, 0, 1, 1),
(29369, 43297, 0.0263, 1, 0, 1, 1),
(29370, 43297, 0.0107, 1, 0, 1, 1),
(29374, 43297, 0.0345, 1, 0, 1, 1),
(29377, 43297, 0.0074, 1, 0, 1, 1),
(29404, 43297, 0.0239, 1, 0, 1, 1),
(29407, 43297, 0.0083, 1, 0, 1, 1),
(29413, 43297, 0.0193, 1, 0, 1, 1),
(29426, 43297, 0.0135, 1, 0, 1, 1),
(29427, 43297, 0.0348, 1, 0, 1, 1),
(29449, 43297, 0.0136, 1, 0, 1, 1),
(29451, 43297, 0.0161, 1, 0, 1, 1),
(29518, 43297, 0.0159, 1, 0, 1, 1),
(29553, 43297, -2, 1, 0, 1, 1),
(29554, 43297, 0.0098, 1, 0, 1, 1),
(29569, 43297, 0.0121, 1, 0, 1, 1),
(29622, 43297, 0.0244, 1, 0, 1, 1),
(29623, 43297, 0.0232, 1, 0, 1, 1),
(29652, 43297, 0.0127, 1, 0, 1, 1),
(29654, 43297, 0.013, 1, 0, 1, 1),
(29656, 43297, 0.0049, 1, 0, 1, 1),
(29695, 43297, 0.0162, 1, 0, 1, 1),
(29696, 43297, 0.0353, 1, 0, 1, 1),
(29699, 43297, 0.0254, 1, 0, 1, 1),
(29719, 43297, 0.0298, 1, 0, 1, 1),
(29792, 43297, 0.0106, 1, 0, 1, 1),
(29793, 43297, 0.0183, 1, 0, 1, 1),
(29843, 43297, 0.0203, 1, 0, 1, 1),
(29875, 43297, 0.0153, 1, 0, 1, 1),
(29880, 43297, 0.0084, 1, 0, 1, 1),
(29974, 43297, -2, 1, 0, 1, 1),
(30037, 43297, 0.0137, 1, 0, 1, 1),
(30135, 43297, -2, 1, 0, 1, 1),
(30144, 43297, -2, 1, 0, 1, 1),
(30146, 43297, 0.0136, 1, 0, 1, 1),
(30204, 43297, 0.014, 1, 0, 1, 1),
(30205, 43297, 0.0106, 1, 0, 1, 1),
(30208, 43297, 0.0094, 1, 0, 1, 1),
(30222, 43297, -2, 1, 0, 1, 1),
(30243, 43297, 0.0103, 1, 0, 1, 1),
(30250, 43297, 0.013, 1, 0, 1, 1),
(30409, 43297, 0.0171, 1, 0, 1, 1),
(30541, 43297, 0.0278, 1, 0, 1, 1),
(30543, 43297, 0.0104, 1, 0, 1, 1),
(30597, 43297, 0.015, 1, 0, 1, 1),
(30632, 43297, 0.0138, 1, 0, 1, 1),
(30687, 43297, 0.0088, 1, 0, 1, 1),
(30696, 43297, 0.0168, 1, 0, 1, 1),
(30698, 43297, -2, 1, 0, 1, 1),
(30701, 43297, 0.011, 1, 0, 1, 1),
(30725, 43297, 0.0085, 1, 0, 1, 1),
(30751, 43297, 0.0101, 1, 0, 1, 1),
(30831, 43297, 0.0427, 1, 0, 1, 1),
(30856, 43297, 0.0325, 1, 0, 1, 1),
(30860, 43297, 0.012, 1, 0, 1, 1),
(30863, 43297, 0.0149, 1, 0, 1, 1),
(30864, 43297, 0.0261, 1, 0, 1, 1),
(30894, 43297, 0.0496, 1, 0, 1, 1),
(30921, 43297, -1, 1, 0, 1, 1),
(30922, 43297, 0.0142, 1, 0, 1, 1),
(30951, 43297, 0.0555, 1, 0, 1, 1),
(30958, 43297, 0.0362, 1, 0, 1, 1),
(31037, 43297, 0.0397, 1, 0, 1, 1),
(31039, 43297, 0.0367, 1, 0, 1, 1),
(31043, 43297, 0.0284, 1, 0, 1, 1),
(31140, 43297, 0.0113, 1, 0, 1, 1),
(31145, 43297, 0.0222, 1, 0, 1, 1),
(31150, 43297, 0.0454, 1, 0, 1, 1),
(31152, 43297, 0.0186, 1, 0, 1, 1),
(31155, 43297, 0.0129, 1, 0, 1, 1),
(31226, 43297, 0.0545, 1, 0, 1, 1),
(31231, 43297, 0.0185, 1, 0, 1, 1),
(31258, 43297, 0.0091, 1, 0, 1, 1),
(31262, 43297, 0.0124, 1, 0, 1, 1),
(31267, 43297, 0.0094, 1, 0, 1, 1),
(31326, 43297, 0.2, 1, 0, 1, 1),
(31396, 43297, 0.0085, 1, 0, 1, 1),
(31399, 43297, 0.0249, 1, 0, 1, 1),
(31413, 43297, -2, 1, 0, 1, 1),
(31691, 43297, 0.0187, 1, 0, 1, 1),
(31693, 43297, 0.0196, 1, 0, 1, 1),
(31718, 43297, 0.0097, 1, 0, 1, 1),
(31731, 43297, 0.0081, 1, 0, 1, 1),
(31738, 43297, 0.0184, 1, 0, 1, 1),
(31746, 43297, 0.0103, 1, 0, 1, 1),
(31783, 43297, 0.0188, 1, 0, 1, 1),
(31843, 43297, 0.034, 1, 0, 1, 1),
(31847, 43297, 0.0126, 1, 0, 1, 1),
(32149, 43297, 0.0103, 1, 0, 1, 1),
(32164, 43297, 0.0414, 1, 0, 1, 1),
(32181, 43297, 0.0154, 1, 0, 1, 1),
(32236, 43297, 0.0232, 1, 0, 1, 1),
(32238, 43297, 0.008, 1, 0, 1, 1),
(32257, 43297, 0.0168, 1, 0, 1, 1),
(32259, 43297, 0.0096, 1, 0, 1, 1),
(32263, 43297, 0.0472, 1, 0, 1, 1),
(32279, 43297, 0.0353, 1, 0, 1, 1),
(32289, 43297, -1, 1, 0, 1, 1),
(32290, 43297, -1, 1, 0, 1, 1),
(32297, 43297, -1, 1, 0, 1, 1),
(32300, 43297, 0.1, 1, 0, 1, 1),
(16167, 43297, 0.3, 1, 0, 1, 1),
(16154, 43297, 0.1, 1, 0, 1, 1),
(16215, 43297, 0.1, 1, 0, 1, 1),
(30284, 43297, 0.1, 1, 0, 1, 1),
(27732, 43297, 0.1177, 1, 0, 1, 1),
(15980, 43297, 0.1118, 1, 0, 1, 1),
(16168, 43297, 0.0935, 1, 0, 1, 1),
(16194, 43297, 0.0836, 1, 0, 1, 1),
(28837, 43297, 0.0824, 1, 0, 1, 1),
(16034, 43297, 0.0813, 1, 0, 1, 1),
(30453, 43297, 0.0804, 1, 0, 1, 1),
(16145, 43297, 0.0729, 1, 0, 1, 1),
(30682, 43297, 0.0729, 1, 0, 1, 1),
(16297, 43297, 0.0725, 1, 0, 1, 1),
(30680, 43297, 0.0688, 1, 0, 1, 1),
(27966, 43297, 0.0676, 1, 0, 1, 1),
(28965, 43297, 0.0675, 1, 0, 1, 1),
(16216, 43297, 0.065, 1, 0, 1, 1),
(16037, 43297, 0.064, 1, 0, 1, 1),
(16146, 43297, 0.0624, 1, 0, 1, 1),
(27639, 43297, 0.0617, 1, 0, 1, 1),
(26555, 43297, 0.0584, 1, 0, 1, 1),
(27729, 43297, 0.0584, 1, 0, 1, 1),
(16021, 43297, 0.0583, 1, 0, 1, 1),
(29931, 43297, 0.0581, 1, 0, 1, 1),
(26553, 43297, 0.0562, 1, 0, 1, 1),
(16022, 43297, 0.0561, 1, 0, 1, 1),
(29822, 43297, 0.0548, 1, 0, 1, 1),
(29829, 43297, 0.0546, 1, 0, 1, 1),
(28249, 43297, 0.0531, 1, 0, 1, 1),
(28579, 43297, 0.0522, 1, 0, 1, 1),
(27969, 43297, 0.0521, 1, 0, 1, 1),
(27962, 43297, 0.0515, 1, 0, 1, 1),
(27963, 43297, 0.0513, 1, 0, 1, 1),
(27965, 43297, 0.0496, 1, 0, 1, 1),
(26670, 43297, 0.0496, 1, 0, 1, 1),
(16018, 43297, 0.0489, 1, 0, 1, 1),
(29836, 43297, 0.0485, 1, 0, 1, 1),
(26734, 43297, 0.0477, 1, 0, 1, 1),
(26735, 43297, 0.0476, 1, 0, 1, 1),
(26637, 43297, 0.0473, 1, 0, 1, 1),
(26550, 43297, 0.0468, 1, 0, 1, 1),
(29832, 43297, 0.0458, 1, 0, 1, 1),
(29335, 43297, 0.0457, 1, 0, 1, 1),
(30319, 43297, 0.0446, 1, 0, 1, 1),
(29819, 43297, 0.0446, 1, 0, 1, 1),
(29874, 43297, 0.0443, 1, 0, 1, 1),
(30893, 43297, 0.0442, 1, 0, 1, 1),
(30287, 43297, 0.044, 1, 0, 1, 1),
(30660, 43297, 0.0423, 1, 0, 1, 1),
(26554, 43297, 0.0419, 1, 0, 1, 1),
(16017, 43297, 0.0418, 1, 0, 1, 1),
(26669, 43297, 0.0416, 1, 0, 1, 1),
(28578, 43297, 0.0416, 1, 0, 1, 1),
(16036, 43297, 0.041, 1, 0, 1, 1),
(16244, 43297, 0.0406, 1, 0, 1, 1),
(30278, 43297, 0.0402, 1, 0, 1, 1),
(15981, 43297, 0.0391, 1, 0, 1, 1),
(28582, 43297, 0.0389, 1, 0, 1, 1),
(26803, 43297, 0.0388, 1, 0, 1, 1),
(30668, 43297, 0.038, 1, 0, 1, 1),
(28581, 43297, 0.0376, 1, 0, 1, 1),
(30667, 43297, 0.0374, 1, 0, 1, 1),
(23961, 43297, 0.0365, 1, 0, 1, 1),
(30695, 43297, 0.0364, 1, 0, 1, 1),
(27743, 43297, 0.0361, 1, 0, 1, 1),
(26635, 43297, 0.0361, 1, 0, 1, 1),
(16165, 43297, 0.1, 1, 0, 1, 1),
(30286, 43297, 0.0358, 1, 0, 1, 1),
(26830, 43297, 0.0344, 1, 0, 1, 1),
(16164, 43297, 0.0338, 1, 0, 1, 1),
(26696, 43297, 0.0337, 1, 0, 1, 1),
(28838, 43297, 0.0328, 1, 0, 1, 1),
(26626, 43297, 0.0318, 1, 0, 1, 1),
(26621, 43297, 0.0317, 1, 0, 1, 1),
(26636, 43297, 0.0317, 1, 0, 1, 1),
(30414, 43297, 0.0309, 1, 0, 1, 1),
(26728, 43297, 0.0306, 1, 0, 1, 1),
(16163, 43297, 0.0306, 1, 0, 1, 1),
(26729, 43297, 0.0303, 1, 0, 1, 1),
(27960, 43297, 0.0302, 1, 0, 1, 1),
(29820, 43297, 0.0301, 1, 0, 1, 1),
(26722, 43297, 0.0298, 1, 0, 1, 1),
(27736, 43297, 0.0297, 1, 0, 1, 1),
(27633, 43297, 0.0292, 1, 0, 1, 1),
(28836, 43297, 0.0286, 1, 0, 1, 1),
(27871, 43297, 0.0284, 1, 0, 1, 1),
(26716, 43297, 0.0281, 1, 0, 1, 1),
(24069, 43297, 0.028, 1, 0, 1, 1),
(26799, 43297, 0.0272, 1, 0, 1, 1),
(30681, 43297, 0.0265, 1, 0, 1, 1),
(24080, 43297, 0.0262, 1, 0, 1, 1),
(27742, 43297, 0.026, 1, 0, 1, 1),
(30666, 43297, 0.0257, 1, 0, 1, 1),
(24082, 43297, 0.0255, 1, 0, 1, 1),
(27734, 43297, 0.0251, 1, 0, 1, 1),
(30283, 43297, 0.0243, 1, 0, 1, 1),
(26623, 43297, 0.0242, 1, 0, 1, 1),
(28199, 43297, 0.0241, 1, 0, 1, 1),
(16243, 43297, 0.024, 1, 0, 1, 1),
(30285, 43297, 0.0236, 1, 0, 1, 1),
(27640, 43297, 0.0235, 1, 0, 1, 1),
(26641, 43297, 0.023, 1, 0, 1, 1),
(26805, 43297, 0.0223, 1, 0, 1, 1),
(28580, 43297, 0.0223, 1, 0, 1, 1),
(26694, 43297, 0.0217, 1, 0, 1, 1),
(30892, 43297, 0.0215, 1, 0, 1, 1),
(30111, 43297, 0.021, 1, 0, 1, 1),
(32191, 43297, 0.0209, 1, 0, 1, 1),
(16029, 43297, 0.0203, 1, 0, 1, 1),
(29838, 43297, 0.02, 1, 0, 1, 1),
(23960, 43297, 0.0195, 1, 0, 1, 1),
(26727, 43297, 0.0188, 1, 0, 1, 1),
(30277, 43297, 0.0182, 1, 0, 1, 1),
(24078, 43297, 0.0181, 1, 0, 1, 1),
(30179, 43297, 0.0181, 1, 0, 1, 1),
(24085, 43297, 0.0178, 1, 0, 1, 1),
(27635, 43297, 0.0167, 1, 0, 1, 1),
(24071, 43297, 0.0167, 1, 0, 1, 1),
(31015, 43297, -2, 1, 0, 1, 1),
(33537, 43297, 0.0417, 1, 0, 1, 1),
(34196, 43297, 0.1, 1, 0, 1, 1),
(34190, 43297, 0.1, 1, 0, 1, 1),
(34015, 43297, 0.2049, 1, 0, 1, 1),
(34137, 43297, 0.1319, 1, 0, 1, 1),
(34069, 43297, 0.3, 1, 0, 1, 1),
(26926, 43297, 0.0423, 1, 0, 1, 1),
(28442, 43297, 0.042, 1, 0, 1, 1),
(29409, 43297, 0.0311, 1, 0, 1, 1),
(29614, 43297, 0.0297, 1, 0, 1, 1),
(30829, 43297, 0.0325, 1, 0, 1, 1),
(31137, 43297, 0.2, 1, 0, 1, 1),
(31159, 43297, 0.0626, 1, 0, 1, 1),
(31411, 43297, 0.0252, 1, 0, 1, 1),
(32250, 43297, 0.024, 1, 0, 1, 1),
(32285, 43297, 0.0308, 1, 0, 1, 1),
(33430, 43297, 0.1, 1, 0, 1, 1),
(33355, 43297, 0.1, 1, 0, 1, 1),
(34135, 43297, 0.1, 1, 0, 1, 1),
(33527, 43297, 0.1, 1, 0, 1, 1),
(33354, 43297, 0.1, 1, 0, 1, 1),
(34267, 43297, 0.1, 1, 0, 1, 1),
(34085, 43297, 0.1, 1, 0, 1, 1),
(29834, 43297, 0.1, 1, 0, 1, 1),
(33528, 43297, 0.1, 1, 0, 1, 1),
(16020, 43297, 0.0292, 1, 0, 1, 1),
(16025, 43297, 0.0338, 1, 0, 1, 1),
(16193, 43297, 0.0305, 1, 0, 1, 1),
(26624, 43297, 0.0342, 1, 0, 1, 1),
(26800, 43297, 0.0306, 1, 0, 1, 1),
(26801, 43297, 0.0238, 1, 0, 1, 1),
(27744, 43297, 0.0259, 1, 0, 1, 1),
(28732, 43297, 0.0507, 1, 0, 1, 1),
(28734, 43297, 0.0563, 1, 0, 1, 1),
(28920, 43297, 0.0508, 1, 0, 1, 1),
(29450, 43297, 0.0278, 1, 0, 1, 1),
(29503, 43297, 0.0428, 1, 0, 1, 1),
(29920, 43297, 0.0431, 1, 0, 1, 1),
(30071, 43297, 0.0482, 1, 0, 1, 1),
(32353, 43297, 0.0684, 1, 0, 1, 1),
(33431, 43297, 0.0681, 1, 0, 1, 1),
(33525, 43297, 0.1174, 1, 0, 1, 1),
(33699, 43297, 0.0241, 1, 0, 1, 1),
(33722, 43297, 0.0245, 1, 0, 1, 1),
(33754, 43297, 0.0309, 1, 0, 1, 1),
(33755, 43297, 0.0317, 1, 0, 1, 1),
(33818, 43297, 0.0633, 1, 0, 1, 1),
(33819, 43297, 0.0313, 1, 0, 1, 1),
(33822, 43297, 0.0809, 1, 0, 1, 1),
(33823, 43297, 0.2285, 1, 0, 1, 1),
(34086, 43297, 0.0482, 1, 0, 1, 1),
(34197, 43297, 0.0947, 1, 0, 1, 1),
(34198, 43297, 0.0553, 1, 0, 1, 1),
(34199, 43297, 0.0505, 1, 0, 1, 1),
(34269, 43297, 0.097, 1, 0, 1, 1),
(34271, 43297, 0.086, 1, 0, 1, 1),
(34273, 43297, 0.0354, 1, 0, 1, 1),
(34728, 43297, 0.0097, 1, 0, 1, 1),
(34734, 43297, 0.0163, 1, 0, 1, 1),
(34838, 43297, 0.0167, 1, 0, 1, 1),
(35305, 43297, 0.0233, 1, 0, 1, 1),
(35307, 43297, 0.0789, 1, 0, 1, 1),
(35309, 43297, 0.054, 1, 0, 1, 1),
(36829, 43297, 0.8, 1, 0, 1, 1),
(38090, 43297, 1.6949, 1, 0, 1, 1);

-- Mutated Abomination abilities
UPDATE `creature_template` SET `spell1` = 70360, `spell2` = 70539, `spell3` = 70542, `spell4` = 0, `spell5` = 0, `spell6` = 71516, `spell7` = 0, `spell8` = 0 WHERE `entry` IN (37672, 38605, 38786, 38787);
UPDATE `creature_template` SET `spell1` = 72527, `spell2` = 72457, `spell3` = 70542, `spell4` = 0, `spell5` = 0, `spell6` = 71516, `spell7` = 0, `spell8` = 0 WHERE `entry` IN (38285, 38788, 38789, 38790);

-- Fix achievement Ribbon Pole Dance
-- Serverside Spells
DELETE FROM `spell_dbc` WHERE `Id` IN (29710,58934);
INSERT INTO `spell_dbc` (`Id`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `Stances`, `StancesNot`, `Targets`, `CastingTimeIndex`, `AuraInterruptFlags`, `ProcFlags`, `ProcChance`, `ProcCharges`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `Effect1`, `Effect2`, `Effect3`, `EffectDieSides1`, `EffectDieSides2`, `EffectDieSides3`, `EffectRealPointsPerLevel1`, `EffectRealPointsPerLevel2`, `EffectRealPointsPerLevel3`, `EffectBasePoints1`, `EffectBasePoints2`, `EffectBasePoints3`, `EffectMechanic1`, `EffectMechanic2`, `EffectMechanic3`, `EffectImplicitTargetA1`, `EffectImplicitTargetA2`, `EffectImplicitTargetA3`, `EffectImplicitTargetB1`, `EffectImplicitTargetB2`, `EffectImplicitTargetB3`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectRadiusIndex3`, `EffectApplyAuraName1`, `EffectApplyAuraName2`, `EffectApplyAuraName3`, `EffectAmplitude1`, `EffectAmplitude2`, `EffectAmplitude3`, `EffectMultipleValue1`, `EffectMultipleValue2`, `EffectMultipleValue3`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectMiscValue3`, `EffectMiscValueB1`, `EffectMiscValueB2`, `EffectMiscValueB3`, `EffectTriggerSpell1`, `EffectTriggerSpell2`, `EffectTriggerSpell3`, `EffectSpellClassMaskA1`, `EffectSpellClassMaskA2`, `EffectSpellClassMaskA3`, `EffectSpellClassMaskB1`, `EffectSpellClassMaskB2`, `EffectSpellClassMaskB3`, `EffectSpellClassMaskC1`, `EffectSpellClassMaskC2`, `EffectSpellClassMaskC3`, `MaxTargetLevel`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `MaxAffectedTargets`, `DmgClass`, `PreventionType`, `DmgMultiplier1`, `DmgMultiplier2`, `DmgMultiplier3`, `AreaGroupId`, `SchoolMask`, `Comment`) VALUES
('29710','0','0','256','0','0','0','0','0','0','0','0','1','0','0','101','0','0','0','0','0','1','0','-1','0','0','140','0','0','0','0','0','0','0','0','0','0','0','0','0','0','25','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','29531','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','1','1','0','1','Ribbon Pole - Force Cast Ribbon Pole Channel'),
('58934','0','0','536870912','0','0','0','0','0','0','0','0','1','0','0','101','0','0','0','0','0','1','0','-1','0','0','3','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','0','0','28','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','Burning Hot Pole Dance credit marker');
-- Link Dancer Check Aura and Visual to Ribbon Pole Channel
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (29531,45390);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(29531,45390,0, 'Ribbon Pole - Dancer Check Aura'),
(45390,45406,2, 'Ribbon Pole - Periodic Visual');

-- Scripts/UtgardePinnacle: Fixed harpoon
DELETE FROM `conditions` WHERE `SourceEntry` = 56578 AND `ConditionValue2` = 26693;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, 56578, 0, 0, 31, 0, 3, 26693, 0, 0, 0, '', NULL);

-- Fixed spells 71871 & 71873
DELETE FROM `spell_proc_event` WHERE `entry` IN (71871); 
DELETE FROM `spell_proc_event` WHERE `entry` IN (71873); 

-- prevent bagouse +300spd for players from this mob http://www.wowhead.com/npc=26828
DELETE FROM `disables` WHERE `sourceType`=0 and `entry` = 51804;
INSERT INTO `disables` (`sourceType` , `entry` , `flags` , `comment`) VALUES 
('0', '51804', '8', 'Power Siphon'); 

-- Fix Achievement: Bros. Before Ho Ho Ho's(1685) (20.12.2011)
UPDATE item_template SET Flags=0x40 WHERE entry=21519;
UPDATE creature_template SET unit_flags=unit_flags&~0x100, type_flags=type_flags|0x4000000 WHERE entry IN (739,927,1182,1351,1444,5484,5489,5661,8140,12336,26044);
UPDATE creature SET spawntimesecs=20 WHERE id IN (739,927,1182,1351,1444,5484,5489,5661,8140,12336,26044);

-- Fix Ogre Pinata item (http://www.wowhead.com/item=46780)
-- Ogre Pinata NPC (http://www.wowhead.com/npc=34632) correct data
UPDATE `creature_template` SET `exp`=2, `faction_A`=7, `faction_H`=7, `mindmg`=420, `maxdmg`=630, `attackpower`=157, `dmg_multiplier`=1.4, `rangeattacktime`=2000, `minrangedmg`=336, `maxrangedmg`=504, `rangedattackpower`=126 WHERE `entry`=34632;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=34632;
-- Ogre Pinata NPC (http://www.wowhead.com/npc=34632) SAI
DELETE FROM `creature_ai_scripts` WHERE `creature_id` = 34632;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=34632 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(34632, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 65788, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Ogre Pinata - Summon Pie of Candy');

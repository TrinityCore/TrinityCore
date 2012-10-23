/* World_Script.sql INSC. Myendras
 * Myendras SQL script
 * Last Update: Saqirmdev
 * Thanks: Phailure, Saqirmdev
 */ 

-- Variables
SET @QUEST := 10722;
SET @ENTRY := 22019;
SET @SPELL1:= 37704; -- Whirlwind
SET @SPELL2:= 8599; -- Enrage

-- Add SmartAI for Kolphis Darkscale
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY; 
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,8439,0,0,0,15,@QUEST,0,0,0,0,0,7,0,0,0,0,0,0,0,'Kolphis Darkscale - On Gossip Select - Quest Credit'),
(@ENTRY,0,1,0,0,0,50,0,3000,3000,8000,8000,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0,'Kolphis Darkscale - Combat - Whirlwind'),
(@ENTRY,0,2,3,2,0,100,1,0,25,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kolphis Darkscale - On Health level - Emote when below 25% HP'),
(@ENTRY,0,3,0,61,0,100,1,0,0,0,0,11,@SPELL2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Kolphis Darkscale - On Health level - Cast Enrage when below 25% HP');

-- add missing text to Kolphis Darkscale from sniff
DELETE FROM `npc_text` WHERE `ID`=10540;
INSERT INTO `npc_text` (`ID`,`prob0`,`text0_0`,`text0_1`,`WDBVerified`) VALUES
(10540,1,"Begone, overseer!  We've already spoken.$B$BStop dragging your feet and execute your orders at Ruuan Weald!",'',1);

-- Kolphis Darkscale emote
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'%s becomes enraged!',16,0,100,0,0,0,'Kolphis Darkscale');

-- Gossip menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=8436 AND `text_id`=10540;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8436,10540);

-- Add gossip_menu conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=8436;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15,8436,0,0,0,9,0,@QUEST,0,0,0,0,'','Kolphis Darkscale - Show Gossip Option 0 - If on Quest Meeting at the Blackwing Coven'),
(14,8436,10540,0,0,28,0,@QUEST,0,0,0,0,'','Kolphis Darkscale - Show Gossip Menu - If Quest Meeting at the Blackwing Coven is Completed');

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



INSERT INTO `gossip_menu` VALUES (51000, 51000);
INSERT INTO npc_text (ID, text0_0, em0_1) VALUES
(51000, 'Put in the first slot of bag item, that you want to transmogrify. In the second slot, put item with perfect display.', 0);

DELETE FROM creature_template WHERE entry = '190001'; 
INSERT INTO creature_template (entry, modelid1, name, subname, IconName, gossip_menu_id, minlevel, maxlevel, Health_mod, Mana_mod, Armor_mod, faction_A, faction_H, npcflag, speed_walk, speed_run, scale, rank, dmg_multiplier, unit_class, unit_flags, type, type_flags, InhabitType, RegenHealth, flags_extra, ScriptName) VALUES 
('190001', '15998', "Transmogrify Master", "", 'Speak', '50000', 71, 71, 1.56, 1.56, 1.56, 35, 35, 3, 1, 1.14286, 1.25, 1, 1, 1, 2, 7, 138936390, 3, 1, 2, 'npc_transmogrify'); 

?»?-- Spellscript and conditions for spells of quest Gordunni Cobalt
DELETE FROM `spell_script_names` WHERE `spell_id`=19395;
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES
(19395,'spell_gordunni_trap');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=11757;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`Comment`) VALUES
(13,1,11757,31,5,144050,'Digging for Cobalt targets Gordunni Trap');


UPDATE `creature` SET `spawnMask`=15 WHERE `id` IN(40091, 40081);

DELETE FROM `creature_template_addon` WHERE `entry` IN(39863, 40142);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,2,75886,0,0,31,0,3,40683,0,0,0, '', 'Blazing Aura can only target Living Embers');

UPDATE `creature_template` SET `baseattacktime` = 2000 WHERE `entry` = 36612; -- Lord Marrowgar 10 NH, Damage scaling via baseattacktime
UPDATE `creature_template` SET `baseattacktime` = 1500 WHERE `entry` = 37957; -- Lord Marrowgar 25 NH, Damage scaling via baseattacktime
UPDATE `creature_template` SET `baseattacktime` = 1500 WHERE `entry` = 37958; -- Lord Marrowgar 10 HC, Damage scaling via baseattacktime
UPDATE `creature_template` SET `dmg_multiplier` = 20 WHERE `entry` = 36855; -- Lady Deathwhisper 10 NH
UPDATE `creature_template` SET `dmg_multiplier` = 13 WHERE `entry` IN (38625, 38628, 38634, 38632); -- Lady Deathwhisper adds 10HC
UPDATE `creature_template` SET `dmg_multiplier` = 13 WHERE `entry` IN (38394, 38393, 38395, 38396); -- Lady Deathwhisper adds 25NH
UPDATE `creature_template` SET `dmg_multiplier` = 75 WHERE `entry` = 38494; -- Rotting Frost Giant, 25 modes
UPDATE `creature_template` SET `dmg_multiplier` = 70 WHERE `entry` = 38582; -- Deathbringer Saurfang 10 HC
UPDATE `creature_template` SET `dmg_multiplier` = 45 WHERE `entry` = 37813; -- Deathbringer Saurfang 10 NH
UPDATE `creature_template` SET `dmg_multiplier` = 15 WHERE `entry` = 38508; -- Blood Beasts 10 NH
UPDATE `creature_template` SET `dmg_multiplier` = 25 WHERE `entry` = 38596; -- Blood Beasts 25 NH
UPDATE `creature_template` SET `dmg_multiplier` = 25 WHERE `entry` = 38597; -- Blood Beasts 10 HC
UPDATE `creature_template` SET `dmg_multiplier` = 50 WHERE `entry` = 38585; -- Professor Putricide 10 HC
UPDATE `creature_template` SET `dmg_multiplier` = 50 WHERE `entry` = 38431; -- Professor Putricide 25 NH
UPDATE `creature_template` SET `dmg_multiplier` = 50 WHERE `entry` IN (38784, 38769, 38771); -- Blood Prince Council 10 HC
UPDATE `creature_template` SET `dmg_multiplier` = 50 WHERE `entry` IN (38401, 38399, 38400); -- Blood Prince Council 25 NH
UPDATE `creature_template` SET `dmg_multiplier` = 50 WHERE `entry` = 38435; -- Blood-Queen Lana'thel 10 HC
UPDATE `creature_template` SET `dmg_multiplier` = 50 WHERE `entry` = 38434; -- Blood-Queen Lana'thel 25 NH
UPDATE `creature_template` SET `dmg_multiplier` = 13 WHERE `entry` = 38721; -- Blazing Skeleton 10 HC
UPDATE `creature_template` SET `dmg_multiplier` = 13 WHERE `entry` = 38169; -- Blazing Skeleton 25 NH
UPDATE `creature_template` SET `dmg_multiplier` = 13 WHERE `entry` = 38723; -- Blistering Zombie 10 HC
UPDATE `creature_template` SET `dmg_multiplier` = 13 WHERE `entry` = 38170; -- Blistering Zombie 25 NH
UPDATE `creature_template` SET `dmg_multiplier` = 13 WHERE `entry` = 38724; -- Gluttonous Abomination 10 HC
UPDATE `creature_template` SET `dmg_multiplier` = 13 WHERE `entry` = 38166; -- Gluttonous Abomination 25 NH
UPDATE `creature_template` SET `dmg_multiplier` = 13 WHERE `entry` = 38725; -- Risen Archmage 10 HC
UPDATE `creature_template` SET `dmg_multiplier` = 13 WHERE `entry` = 38167; -- Risen Archmage 25 NH
UPDATE `creature_template` SET `dmg_multiplier` = 13 WHERE `entry` = 38726; -- Rot Worm 10 HC
UPDATE `creature_template` SET `dmg_multiplier` = 13 WHERE `entry` = 38168; -- Rot Worm 25 NH
UPDATE `creature_template` SET `dmg_multiplier` = 13 WHERE `entry` = 38727; -- Suppresser 10 HC
UPDATE `creature_template` SET `dmg_multiplier` = 13 WHERE `entry` = 38171; -- Suppresser 25 NH
UPDATE `creature_template` SET `dmg_multiplier` = 50 WHERE `entry` = 38266; -- Sindragosa 10 HC
UPDATE `creature_template` SET `dmg_multiplier` = 50 WHERE `entry` = 38265; -- Sindragosa 25 NH

-- Rotting Frost Giant, spawns gunship chest
UPDATE `gameobject_template` SET `flags` = 50 WHERE `entry` IN (201872, 201874, 201873, 201875, 202177, 202180, 202178, 202179);
DELETE FROM `gameobject` WHERE `id` IN (201872, 201874, 201873, 201875, 202177, 202180, 202178, 202179);
INSERT INTO `gameobject` (id, map, spawnMask, phaseMask, position_x, position_y, position_z, orientation, rotation0, rotation1, rotation2, rotation3, spawntimesecs, animprogress, state) VALUES
(201875, 631, 8, 1, -209.678, 2211.54, 199.97, 3.13972, 0, 0, 1, 0.000936107, 604800, 0, 1),
(201874, 631, 2, 1, -209.678, 2211.54, 199.97, 3.13972, 0, 0, 1, 0.000936107, 604800, 0, 1),
(201872, 631, 1, 1, -209.678, 2211.54, 199.97, 3.13972, 0, 0, 1, 0.000936107, 604800, 0, 1),
(201873, 631, 4, 1, -209.678, 2211.54, 199.97, 3.13972, 0, 0, 1, 0.000936107, 604800, 0, 1);
UPDATE `creature` SET `spawnMask` = 15, `position_x` = -257.36, `position_y` = 2212.27, `position_z` = 199.98, `orientation` = 3.1397 WHERE `id` = 38490;
UPDATE `creature_template` SET `minlevel` = 83, `maxlevel` = 83, `faction_A` = 16, `faction_H` = 16, `speed_run` = 1.3, `baseattacktime` = 2000, `unit_flags` = 33280, `lootid` = 0, `InhabitType` = 3, `mechanic_immune_mask` = 617298815 WHERE `entry` IN (38490, 38494);
UPDATE `creature_template` SET `difficulty_entry_1` = 38494 WHERE `entry` = 38490;

-- Loot stuff
DELETE FROM `creature_loot_template` WHERE `entry` = 38490; -- Loot template for Rotting Frost Giant, no longer used
DELETE FROM `reference_loot_template` WHERE `item` IN (52025, 52026, 52027) AND `entry` = 34279; -- Use one reference for normal Marks of Sanctification and one for heroic ones
UPDATE `gameobject_loot_template` SET `maxcount` = 1 WHERE `entry` = 28058 AND `item` = 2 AND `mincountOrRef` = -34278; -- Deathbringer Saurfang 10 HC, only drop one normal Mark of Sanctification
UPDATE `gameobject_loot_template` SET `maxcount` = 1 WHERE `entry` = 28088 AND `item` = 2 AND `mincountOrRef` = -34279; -- Deathbringer Saurfang, 25 HC, drop one heroic Mark of Sanctification
DELETE FROM `gameobject_loot_template` WHERE `item` = 3 AND `entry` = 28088;
INSERT INTO `gameobject_loot_template` (entry, item, ChanceOrQuestChance, lootmode, groupid, mincountOrRef, maxcount) VALUES
(28088, 3, 100, 1, 0, -34278, 2); -- Deathbringer Saurfang, 25 HC, drop two normal Marks of Sanctification
UPDATE `creature_loot_template` SET `maxcount` = 1 WHERE `entry` = 38586 AND `item` = 1 AND `mincountOrRef` = -34279; -- Professor Putricide, 25 HC, drop one heroic Mark of Sanctification
DELETE FROM `creature_loot_template` WHERE `item` = 2 AND `entry` = 38586;
INSERT INTO `creature_loot_template` (entry, item, ChanceOrQuestChance, lootmode, groupid, mincountOrRef, maxcount) VALUES
(38586, 2, 100, 1, 0, -34278, 2); -- Professor Putricide, 25 HC, drop two normal Marks of Sanctification
UPDATE `creature_loot_template` SET `maxcount` = 1 WHERE `entry` = 38436 AND `item` = 2 AND `mincountOrRef` = -34279; -- Blood-Queen Lana'thel, 25 HC, drop one heroic Mark of Sanctification
DELETE FROM `creature_loot_template` WHERE `item` = 3 AND `entry` = 38436;
INSERT INTO `creature_loot_template` (entry, item, ChanceOrQuestChance, lootmode, groupid, mincountOrRef, maxcount) VALUES
(38436, 3, 100, 1, 0, -34278, 2); -- Blood-Queen Lana'thel, 25 HC, drop two normal Marks of Sanctification
UPDATE `creature_loot_template` SET `maxcount` = 1 WHERE `entry` = 38267 AND `item` = 2 AND `mincountOrRef` = -34279; -- Sindragosa, 25 HC, drop one heroic Mark of Sanctification
DELETE FROM `creature_loot_template` WHERE `item` = 3 AND `entry` = 38267;
INSERT INTO `creature_loot_template` (entry, item, ChanceOrQuestChance, lootmode, groupid, mincountOrRef, maxcount) VALUES
(38267, 3, 100, 1, 0, -34278, 2); -- Sindragosa, 25 HC, drop two normal Marks of Sanctification
UPDATE `creature_loot_template` SET `maxcount` = 1 WHERE `entry` = 39168 AND `item` = 2 AND `mincountOrRef` = -34279; -- The Lich King, 25 HC, drop one heroic Mark of Sanctification
DELETE FROM `creature_loot_template` WHERE `item` = 3 AND `entry` = 39168;
INSERT INTO `creature_loot_template` (entry, item, ChanceOrQuestChance, lootmode, groupid, mincountOrRef, maxcount) VALUES
(39168, 3, 100, 1, 0, -34278, 2); -- The Lich King, 25 HC, drop two normal Marks of Sanctification
UPDATE `creature_loot_template` SET `maxcount` = 2 WHERE `entry` = 38784 AND `item` = 1 AND `mincountOrRef` = -34259; -- Blood Prince Council, 10 HC, should only drop 2 equip items
UPDATE `gameobject_loot_template` SET `maxcount` = 2 WHERE `entry` = 28064 AND `item` = 1 AND `mincountOrRef` = -34265; -- Valithria should drop 2 equip items in 10 HC

-- Lady Deathwisper
UPDATE `creature_template` SET `baseattacktime` = 2000, `mingold` = 837154, `maxgold` = 900000, `rank` = 3 WHERE `entry` IN (36855, 38106, 38296, 38297);

-- Cult Fanatic, Cult Adherent, Deformed Fanatic, Empowered Adherent
UPDATE `creature_template` SET `mechanic_immune_mask` = 8388624 WHERE `entry` IN (37890, 38393, 38628, 38629, 37949, 38394, 38625, 38626, 38135, 38395, 38634, 38635, 38136, 38396, 38632, 38633);

-- Deathbringer Saurfang should not add Scent of Blood aura to adds, damage increase will fail in that case
DELETE FROM `conditions` WHERE `SourceEntry` = 72771 AND `SourceTypeOrReferenceId` = 17;
INSERT INTO `conditions` (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorTextId, ScriptName, Comment) VALUES
(17, 0, 72771, 0, 0, 31, 0, 3, 38508, 0, 0, 0, '', 'Deathbringer Saurfang - Scent of Blood disabled for Saurfang, adds will use AddAura');

-- Rotface
UPDATE `creature_template` SET `mechanic_immune_mask` = 650854271, `speed_walk` = 0.888888, `speed_run` =  1.5873 WHERE `entry` IN (36627, 38390, 38549, 38550);

-- Festergut
UPDATE `creature_template` SET `speed_walk` = 0.888888, `speed_run` = 1.5873 WHERE `entry` IN (36626, 37504, 37505, 37506);

-- Volatile Ooze
UPDATE `creature_Template` SET `mechanic_immune_mask` = 650854271 WHERE `entry` IN (37697, 38604, 38758, 38759);

-- Gas Cloud
UPDATE `creature_Template` SET `mechanic_immune_mask` = 650854271 WHERE `entry` IN (37562, 38602, 38760, 38761);

-- Kinetic Bomb
UPDATE `creature_template` SET `dmg_multiplier` = 7.5, `mechanic_immune_mask` = 650854271 WHERE `entry` IN (38454, 38775, 38776, 38777);

UPDATE `creature_template` SET `rangeattacktime` = 0, `rangedattackpower` = 135 WHERE `entry` IN (37955, 38434, 38435, 38436);

-- ICC Buff
DELETE FROM `disables` WHERE `entry` = 73824 AND `sourceType` = 0;
DELETE FROM `conditions` WHERE `SourceEntry` IN (73816, 73818, 73819, 73820, 73821, 73822, 73762, 73824, 73825, 73826, 73827, 73828) AND `SourceTypeOrReferenceId` = 17;
INSERT INTO `conditions` (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorTextId, ScriptName, Comment) VALUES
-- (17, 0, 73816, 0, 0, 19, 0, 1, 0, 0, 0, 0, '', 'ICC Buff - Horde 5, just allow specified modes'),
(17, 0, 73818, 0, 0, 19, 0, 1, 0, 0, 0, 0, '', 'ICC Buff - Horde 10, just allow specified modes'),
-- (17, 0, 73819, 0, 0, 19, 0, 1, 0, 0, 0, 0, '', 'ICC Buff - Horde 15, just allow specified modes'),
-- (17, 0, 73820, 0, 0, 19, 0, 1, 0, 0, 0, 0, '', 'ICC Buff - Horde 20, just allow specified modes'),
-- (17, 0, 73821, 0, 0, 19, 0, 1, 0, 0, 0, 0, '', 'ICC Buff - Horde 25, just allow specified modes'),
-- (17, 0, 73822, 0, 0, 19, 0, 1, 0, 0, 0, 0, '', 'ICC Buff - Horde 30, just allow specified modes'),
-- (17, 0, 73762, 0, 0, 19, 0, 1, 0, 0, 0, 0, '', 'ICC Buff - Alliance 5, just allow specified modes'),
(17, 0, 73824, 0, 0, 19, 0, 1, 0, 0, 0, 0, '', 'ICC Buff - Alliance 10, just allow specified modes');
-- (17, 0, 73825, 0, 0, 19, 0, 1, 0, 0, 0, 0, '', 'ICC Buff - Alliance 15, just allow specified modes'),
-- (17, 0, 73826, 0, 0, 19, 0, 1, 0, 0, 0, 0, '', 'ICC Buff - Alliance 20, just allow specified modes'),
-- (17, 0, 73827, 0, 0, 19, 0, 1, 0, 0, 0, 0, '', 'ICC Buff - Alliance 25, just allow specified modes'),
-- (17, 0, 73828, 0, 0, 19, 0, 1, 0, 0, 0, 0, '', 'ICC Buff - Alliance 30, just allow specified modes');
DELETE FROM `spell_area` WHERE `spell` IN (73824, 73818) AND `area` = 4812;
INSERT INTO `spell_area` (spell, area, quest_start, quest_start_active, quest_end, aura_spell, racemask, gender, autocast) VALUES
-- (73816, 4812, 0, 0, 0, 0, 690, 2, 1), -- Horde, 5
(73818, 4812, 0, 0, 0, 0, 690, 2, 1), -- Horde, 10
-- (73819, 4812, 0, 0, 0, 0, 690, 2, 1), -- Horde, 15
-- (73820, 4812, 0, 0, 0, 0, 690, 2, 1), -- Horde, 20
-- (73821, 4812, 0, 0, 0, 0, 690, 2, 1), -- Horde, 25
-- (73822, 4812, 0, 0, 0, 0, 690, 2, 1), -- Horde, 30
-- (73762, 4812, 0, 0, 0, 0, 1101, 2, 1), -- Alliance, 5
(73824, 4812, 0, 0, 0, 0, 1101, 2, 1); -- Alliance, 10
-- (73825, 4812, 0, 0, 0, 0, 1101, 2, 1), -- Alliance, 15
-- (73826, 4812, 0, 0, 0, 0, 1101, 2, 1), -- Alliance, 20
-- (73827, 4812, 0, 0, 0, 0, 1101, 2, 1), -- Alliance, 25
-- (73828, 4812, 0, 0, 0, 0, 1101, 2, 1); -- Alliance, 30
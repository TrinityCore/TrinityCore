-- HP update
UPDATE `creature_template` SET `HealthModifierExtra`=2 WHERE `entry`=7086;
UPDATE `creature_template` SET `HealthModifierExtra`=2 WHERE `entry`=7097;
UPDATE `creature_template` SET `HealthModifierExtra`=2 WHERE `entry`=7105;
UPDATE `creature_template` SET `HealthModifierExtra`=2 WHERE `entry`=7106;
UPDATE `creature_template` SET `HealthModifierExtra`=2.5 WHERE `entry`=7109;
UPDATE `creature_template` SET `unit_class`=1, `HealthModifierExtra`=2 WHERE `entry`=7110;
UPDATE `creature_template` SET `HealthModifierExtra`=2 WHERE `entry`=7153;
UPDATE `creature_template` SET `HealthModifierExtra`=2 WHERE `entry`=7154;
UPDATE `creature_template` SET `HealthModifierExtra`=2 WHERE `entry`=7155;
UPDATE `creature_template` SET `HealthModifierExtra`=2 WHERE `entry`=8956;
UPDATE `creature_template` SET `HealthModifierExtra`=2 WHERE `entry`=8959;
UPDATE `creature_template` SET `HealthModifierExtra`=2 WHERE `entry`=9454;
UPDATE `creature_template` SET `HealthModifierExtra`=2.5 WHERE `entry`=10920;
UPDATE `creature_template` SET `HealthModifierExtra`=2.5 WHERE `entry`=10921;
UPDATE `creature_template` SET `HealthModifierExtra`=2.5 WHERE `entry`=10923;
UPDATE `creature_template` SET `HealthModifierExtra`=2 WHERE `entry`=10924;
UPDATE `creature_template` SET `HealthModifierExtra`=2 WHERE `entry`=11554;
UPDATE `creature_template` SET `HealthModifierExtra`=2 WHERE `entry`=14339;
UPDATE `creature_template` SET `HealthModifierExtra`=2 WHERE `entry`=47369;
UPDATE `creature_template` SET `HealthModifierExtra`=2 WHERE `entry`=47392;
UPDATE `creature_template` SET `HealthModifierExtra`=2 WHERE `entry`=47398;
UPDATE `creature_template` SET `HealthModifierExtra`=2 WHERE `entry`=48344;
UPDATE `creature_template` SET `HealthModifierExtra`=2 WHERE `entry`=48607;
UPDATE `creature_template` SET `HealthModifierExtra`=2 WHERE `entry`=48608;
UPDATE `creature_template` SET `unit_class`=2, `HealthModifierExtra`=2.5 WHERE `entry`=47439;

DELETE FROM `spell_area` WHERE `spell`=49416;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(49416,2481,28000,0,0,0,2,1,64,0);

-- Add spell target condition for Slash of Tichondrius
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=88697;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 88697, 0, 1, 31, 5, 206625, 0, 0, '', 'Slash of Tichondrius targets Jadefire Barrier');

-- Remove extra Felwood Spawns
DELETE FROM `gameobject` WHERE `guid` IN (204692,218995,206425);

UPDATE `quest_template` SET `SpecialFlags` = 1 WHERE `Id` IN (28396);
UPDATE `quest_template` SET `SpecialFlags`=1, `PrevQuestId`=27995 WHERE `Id` IN (28396);
UPDATE `quest_template` SET `PrevQuestId`=28100, `NextQuestId`=0, `ExclusiveGroup`=27989 WHERE `Id` IN (27989,27994);
UPDATE `quest_template` SET `PrevQuestId`=27989, `NextQuestId`=0, `ExclusiveGroup`=0 WHERE `Id` IN (27995);
UPDATE `quest_template` SET `ExclusiveGroup`=27989 WHERE `Id` IN (27994);
UPDATE `quest_template` SET `PrevQuestId`=28150 WHERE `Id` IN (28000);
UPDATE `quest_template` SET `PrevQuestId`=28049 WHERE `Id` IN (28044);
UPDATE `quest_template` SET `PrevQuestId`=28044 WHERE `Id` IN (28113);
UPDATE `quest_template` SET `PrevQuestId`=28044 WHERE `Id` IN (28102);
UPDATE `quest_template` SET `PrevQuestId`=28102 WHERE `Id` IN (28152);
UPDATE `quest_template` SET `PrevQuestId`=28113 WHERE `Id` IN (28288);
UPDATE `quest_template` SET `PrevQuestId`=28116 WHERE `Id` IN (28119);

UPDATE `quest_template` SET `PrevQuestId`=28119 WHERE `Id` IN (28126);
UPDATE `quest_template` SET `PrevQuestId`=28119 WHERE `Id` IN (28128);
UPDATE `quest_template` SET `PrevQuestId`=28119 WHERE `Id` IN (28129);

DELETE FROM `gossip_menu_option` WHERE (`menu_id`=3622 AND `id`=0) OR (`menu_id`=12412 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `box_coded`, `box_money`, `box_text`) VALUES
(3622, 0, 0, 'How can I prove myself to the Timbermaw furbolg?',7136, 1, 1, 3621, 0, 0, ''), -- 11554
(12412, 0, 0, 'Step through the portal and return to Wildheart Point.',48490, 1, 1, 0, 0, 0, ''); -- 206831

DELETE FROM creature_queststarter WHERE `quest` IN (28129,28131,28153,28155);
INSERT INTO creature_queststarter VALUES (51664,28129),(51664,28131),(51664,28153),(51664,28155);
DELETE FROM creature_questender WHERE `quest` IN (28129,28131,28153);

UPDATE `quest_template` SET `PrevQuestId`=28129 WHERE `Id` IN (28131);
UPDATE `quest_template` SET `PrevQuestId`=28131 WHERE `Id` IN (28153);
UPDATE `quest_template` SET `PrevQuestId`=28153 WHERE `Id` IN (28155);
UPDATE `quest_template` SET `PrevQuestId`=28129 WHERE `Id` IN (28305);
UPDATE `quest_template` SET `PrevQuestId`=0 WHERE `Id` IN (28116);

-- Portal to Wildheart Point SAI
SET @ENTRY := 206831;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,62,0,100,0,12412,0,0,0,62,1,0,0,0,0,0,7,0,0,0,4733.729,-874.0224,343.6666,0.574912,"Portal to Wildheart Point - On gossip option select - teleport player");

UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=47747;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=47747;
INSERT INTO `npc_spellclick_spells` VALUES (47747,89960,1,1);

UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=48457;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=48457;
INSERT INTO `npc_spellclick_spells` VALUES (48457,90102,1,1);

DELETE FROM `spell_target_position` WHERE `id`=89755;
INSERT INTO `spell_target_position` (`id`,`effIndex`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`,`VerifiedBuild`) VALUES 
(89755, 0, 1, 4329.33, -745.155, 284.449, 1.998802, 18414);

-- Add missing loot
DELETE FROM `creature_loot_template` WHERE `entry`=9879 AND `item`=63522;
DELETE FROM `creature_loot_template` WHERE `entry`=48344 AND `item`=63687;
DELETE FROM `creature_loot_template` WHERE `entry` IN (8959,8956) AND `item`=63088;
DELETE FROM `creature_loot_template` WHERE `entry`=7136 AND `item`=63123;
DELETE FROM `creature_loot_template` WHERE `entry`=47398 AND `item`=62919;
DELETE FROM `creature_loot_template` WHERE `entry`=7086 AND `item`=62918;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(9879,63522,-100,1,0,1,1), -- Add missing quest item to Entropic Horror for quest Collecting Corruption
(48344,63687,-100,1,0,1,1), -- Add missing quest item to Kroshius for quest The Core of Kroshius
(8959,63088,-100,1,0,1,1), -- Add missing quest item to Felpaw Wolf for quest Culling the Corrupted
(8956,63088,-100,1,0,1,1), -- Add missing quest item to Angerclaw Bear for quest Culling the Corrupted
(7136,63123,-25,1,0,1,1), -- Add missing quest item to Infernal Sentry for quest Fel To Pieces
(47398,62919,-100,1,0,1,1), -- Add missing quest item to Vorlus <The Voidwatcher> for quest Touch the Untouchable
(7086,62918,-100,1,0,1,1); -- Add missing quest item to Cursed Ooze for quest See the Invisible

UPDATE `creature_template` SET `lootid`=47398 WHERE `entry`=47398;

-- Impsy SAI
SET @ENTRY := 47339;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,88354,0,0,0,11,88330,0,0,0,0,0,7,0,0,0,0,0,0,0,"Impsy - On spell hit - Cast Enchanted Imp Sack"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,33,47365,0,0,0,0,0,7,0,0,0,0,0,0,0,"Impsy - On spell hit - Give Killcredit"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Impsy - On spell hit - Despawn"),
(@ENTRY,0,3,4,2,0,100,1,0,10,0,0,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,"Impsy - hp%10 - Say 1"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,2,0,0,0,0,0,0,0,"Impsy - OOC - Say 2"),
(@ENTRY,0,5,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Impsy - ON Aggro - Say 0");

DELETE FROM `creature_text` WHERE `entry`=47339;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(47339, 0, 0, 'Go away, kid, you''re botherin'' me!', 12, 0, 100, 0, 0, 0, 'Impsy'),
(47339, 1, 0, 'Right in the face! Ow ow ow...', 14, 0, 100, 0, 0, 0, 'Impsy'),
(47339, 2, 0, 'Catch Impsy in the sack!', 41, 0, 100, 0, 0, 0, 'Impsy');

-- Add spell target condition for Enchanted Imp Sack
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=88354;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 88354, 0, 1, 31, 3, 47339, 0, 0, '', 'Enchanted Imp Sack targets Impsy');

-- Arcanist Delaris SAI
SET @ENTRY := 47341;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,20,0,100,0,28000,0,0,0,28,88330,0,0,0,0,0,7,0,0,0,0,0,0,0,"Arcanist Delaris - On quest reward - remove aura Enchanted Imp Sack"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,11,47366,5,0,0,0,0,0,"Arcanist Delaris - On quest reward - Impsy say text");

DELETE FROM `creature_text` WHERE `entry`=47366;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(47366, 0, 0, 'I''ll talk, I''ll talk! Anything! Just keep that perfumed bag away from me!', 12, 0, 100, 0, 0, 0, 0, 'Impsy');

-- Rainbow! SAI
SET @ENTRY := 48212;
UPDATE `creature_template` SET `AIName`="SmartAI", `flags_extra`=128 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,11,88509,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcanist Delaris - On quest reward - remove aura Enchanted Imp Sack");

-- Add spell target condition for Terrifying Rainbow
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=89620;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 89620, 0, 1, 31, 3, 47369, 0, 0, '', 'Terrifying Rainbow targets Jadefire Imp'),
(13, 2, 89620, 0, 1, 31, 3, 47369, 0, 0, '', 'Terrifying Rainbow targets Jadefire Imp');

-- Jadefire Imp SAI
SET @ENTRY := 47369;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jadefire Imp - On spellhit - do text emote"),
(@ENTRY,0,1,2,61,0,100,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jadefire Imp - On spellhit - yell text"),
(@ENTRY,0,2,3,61,0,100,1,89620,0,0,0,33,48227,0,0,0,0,0,17,0,10,0,0,0,0,0,"Jadefire Imp - On spellhit - give quest credit to player range"),
(@ENTRY,0,3,0,61,0,100,1,0,0,0,0,41,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jadefire Imp - On spellhit - despawn");

DELETE FROM `creature_text` WHERE `entry`=47369;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(47369, 0, 0, '%s flees in terror!', 16, 0, 100, 0, 0, 0, 0, 'Jadefire Imp to Rainbow! - Channeller'),
(47369, 0, 1, '%s screams at the top of its lungs!', 16, 0, 100, 0, 0, 0, 0, 'Jadefire Imp to Rainbow! - Channeller'),
(47369, 0, 2, '%s starts sobbing uncontrollably!', 16, 0, 100, 0, 0, 0, 0, 'Jadefire Imp to Rainbow! - Channeller'),
(47369, 1, 0, 'The colors! Nooooooooooooooo!', 14, 0, 100, 0, 0, 0, 0, 'Jadefire Imp to Rainbow! - Channeller'),
(47369, 1, 1, 'AAAAAAAAAAAAHHH!!', 14, 0, 100, 0, 0, 0, 0, 'Jadefire Imp to Rainbow! - Channeller'),
(47369, 1, 2, 'It burns! IT BURNS!', 14, 0, 100, 0, 0, 0, 0, 'Jadefire Imp to Rainbow! - Channeller'),
(47369, 1, 3, 'It''s so intense!', 14, 0, 100, 0, 0, 0, 0, 'Jadefire Imp to Rainbow! - Channeller'),
(47369, 1, 4, 'It''s too much!', 14, 0, 100, 0, 0, 0, 0, 'Jadefire Imp to Rainbow! - Channeller'),
(47369, 1, 5, 'Get it away!', 14, 0, 100, 0, 0, 0, 0, 'Jadefire Imp to Rainbow! - Channeller'),
(47369, 1, 6, 'Make it stop! MAKE IT STOP!', 14, 0, 100, 0, 0, 0, 0, 'Jadefire Imp to Rainbow! - Channeller');

DELETE FROM `creature_text` WHERE `entry`=47308;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(47308, 0, 0, 'BEES! Jump in water to get them off!', 42, 0, 100, 0, 0, 0, 0, 'Felwood Honey Bunny');

-- Xavathras SAI
SET @ENTRY := 47398;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Xavathras - Aggro - Say 0"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,25000,25000,11,13445,0,0,0,0,0,2,0,0,0,0,0,0,0,"Xavathras - Combat - Cast Rend");

DELETE FROM `creature_text` WHERE `entry`=9454;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(9454, 0, 0, 'Face me, $r, and know the legion''s wrath!', 12, 0, 100, 0, 0, 0, 0, 'Xavathras');

SET @CGUID := 359907;
DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+1220);
INSERT INTO `creature_addon` (`guid`,`bytes1`,`bytes2`,`auras`) VALUES
(@CGUID+1220,65537,1, '49414');
DELETE FROM `creature_template_addon` WHERE `entry`=47556;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`auras`) VALUES (47556,1,1, '');

DELETE FROM `spell_script_names` WHERE `spell_id`=88665;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (88665, 'spell_ruumbos_silly_dance');

-- Ruumbo SAI
SET @ENTRY := 206585;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,19,0,100,0,27995,0,0,0,85,88665,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ruumbo - On quest accept - player cast Ruumbo's Silly Dance");

-- Drizle SAI
SET @ENTRY := 47556;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,63,0,100,0,0,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drizle - Just Created - Run Script"),
(@ENTRY,0,1,0,1,0,100,1,1000,1000,1000,1000,11,90106,0,0,0,0,0,19,37162,10,0,0,0,0,0,"Drizle - OOC - Cast 'Chain'"),
(@ENTRY*100,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Drizle - Script - Say 0"),
(@ENTRY*100,9,1,0,0,0,100,0,8000,8000,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Drizle - Script - Say 1"),
(@ENTRY*100,9,2,0,0,0,100,0,7000,7000,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Drizle - Script - Say 2"),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,33,47555,0,0,0,0,0,17,0,10,0,0,0,0,0,"Drizle - Script - Kill Credit"),
(@ENTRY*100,9,4,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,3811.03,-1250.44,217.4166,0,"Drizle - Script - move to");

-- Ferli SAI
SET @ENTRY := 47558;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,63,0,100,0,0,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ferli - Just Created - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,5000,5000,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ferli - Script - Say 0"),
(@ENTRY*100,9,1,0,0,0,100,0,10000,10000,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ferli - Script - Say 1"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,3782.17,-1378.65,203.0396,0,"Ferli - Script - move to");

DELETE FROM `creature_text` WHERE `entry` IN (47556,47558);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(47556, 0, 0, 'Hee hee... hee hee hee... ha ha ha!', 12, 0, 100, 0, 0, 0, 0, 'Drizle'),
(47556, 1, 0, 'Don''t call me dummy, dummy!', 12, 0, 100, 0, 0, 0, 0, 'Drizle'),
(47556, 2, 0, 'Run!', 12, 0, 100, 0, 0, 0, 0, 'Drizle'),
(47558, 0, 0, 'Shh! They can hear you, dummy!', 12, 0, 100, 0, 0, 0, 0, 'Ferli'),
(47558, 1, 0, 'Ow! Now they can see us!', 12, 0, 100, 0, 0, 0, 0, 'Ferli');

--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-113551, -113550);
UPDATE `smart_scripts` SET `event_type`=1, `event_flags`=1 WHERE `entryorguid` IN (-88704, -88703, -88702, -88701) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `target_param1`=113551, `target_param2`=26298 WHERE `entryorguid` IN (-113549) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `target_param1`=113550, `target_param2`=26298 WHERE `entryorguid` IN (-113548) AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-113551, -113478) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-113551, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 10, 113549, 26298, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny - on respawn - set data'),
(-113478, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 10, 61994, 26298, 0, 0, 0, 0, 0, 'ELM General Purpose Bunny - on respawn - set data');
DELETE FROM `creature_template_addon` WHERE `entry`=26298;
DELETE FROM `creature_addon` WHERE `guid` IN (88704, 88703, 88702, 88701);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(88704,0,0,0,1,0,'52485 51666'),
(88703,0,0,0,1,0,'52485 51666'),
(88702,0,0,0,1,0,'52485 51666'),
(88701,0,0,0,1,0,'52485 51666');
UPDATE `creature` SET `position_x`=6831.778,`position_y`=-4534.357, `position_z`=444.178,`orientation`=0.127 WHERE `guid`=113550;
UPDATE `creature` SET `position_x`=6829.298,`position_y`=-4515.533, `position_z`=444.178,`orientation`=4.679 WHERE `guid`=113551;
UPDATE `conditions` SET `ConditionValue2`=26298 WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry` IN (52834, 52833, 52837, 52838) AND `ConditionTypeOrReference`=31;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry` IN (52834, 52833, 52837, 52838) AND `ConditionTypeOrReference`=35;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,52833,0,0,35,0,1,5,3,0,0,'','Spell Akali''s Chains - Right Rear Paw target distance must be 5y or more'),
(13,1,52834,0,0,35,0,1,5,3,0,0,'','Spell Akali''s Chains - Right Rear Paw target distance must be 5y or more'),
(13,1,52837,0,0,35,0,1,5,3,0,0,'','Spell Akali''s Chains - Right Rear Paw target distance must be 5y or more'),
(13,1,52838,0,0,35,0,1,5,3,0,0,'','Spell Akali''s Chains - Right Rear Paw target distance must be 5y or more');
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (69, 299);
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (69, 299);
UPDATE `creature_template_addon` SET `auras`='71764' WHERE `entry` IN (69, 299);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (677) AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(677, 0, 2, 0, 0, 0, 100, 1, 8000, 8000, 8000, 8000, 11, 7979, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,'Venture Co. Tinkerer - IC - Cast Compact Harvest Reaper (no repeat)');
UPDATE `smart_scripts` SET `event_type`=25, `event_flags`=0, `comment`='Mosh''Ogg Spellcrafter - On Reset - Cast Frost Armor (No Repeat)' WHERE `entryorguid` IN (710) AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (853) AND `source_type`=0;
UPDATE `creature_template_addon` SET `auras`='18950' WHERE `entry` IN (853); 
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (853);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1642) AND `source_type`=0;
UPDATE `creature_template_addon` SET `auras`='18950' WHERE `entry` IN (1642); 
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (1642);
UPDATE `smart_scripts` SET `event_type`=25, `event_flags`=0, `comment`='Foreman Bonds - On Reset - Cast Devotion Aura' WHERE `entryorguid` IN (2305) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `event_flags`=0, `comment`='Dun Garok Mountaineer - On Reset - Cast Devotion Aura' WHERE `entryorguid` IN (2344) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `event_flags`=0, `comment`='Shadowy Assassin - On Reset - Cast Stealth' WHERE `entryorguid` IN (2434) AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2522) AND `source_type`=0;
UPDATE `creature_template_addon` SET `auras`='30831 12787' WHERE `entry` IN (2522); 
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (2522);
UPDATE `smart_scripts` SET `event_type`=25, `event_flags`=0, `comment`='Unseen - On Reset - Cast Unseen' WHERE `entryorguid` IN (3094) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `action_type`=75, `comment`="Saltspittle Puddlejumper - On Reset - Add aura 'Battle Stance' (No Repeat)" WHERE `entryorguid` IN (3737) AND `source_type`=0 AND `id`=0;
UPDATE `creature_template_addon` SET `auras`="7164" WHERE `entry`=3739;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Foulweald Warrior - On Reset - Cast 'Corrupted Strength Passive' (No Repeat)" WHERE `entryorguid` IN (3743) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Foulweald Den Watcher - On Reset - Cast 'Corrupted Stamina Passive' (No Repeat)" WHERE `entryorguid` IN (3746) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Foulweald Shaman - On Reset - Cast 'Corrupted Intellect Passive' (No Repeat)" WHERE `entryorguid` IN (3748) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Foulweald Ursa - On Reset - Cast 'Corrupted Strength Passive' (No Repeat)" WHERE `entryorguid` IN (3749) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Foulweald Totemic - On Reset - Cast 'Corrupted Intellect Passive' (No Repeat)" WHERE `entryorguid` IN (3750) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Felmusk Shadowstalker - On Reset - Cast 'Sneak' (No Repeat)" WHERE `entryorguid` IN (3763) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Forsaken Assassin - On Reset - Cast 'Sneak' (No Repeat)" WHERE `entryorguid` IN (3807) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Forsaken Intruder - On Reset - Cast 'Sneak' (No Repeat)" WHERE `entryorguid` IN (3804) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Forsaken Infiltrator - On Reset - Cast 'Sneak' (No Repeat)" WHERE `entryorguid` IN (3806) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `action_type`=75, `comment`="Wildthorn Lurker - On Reset - Add aura Hide" WHERE `entryorguid` IN (3821) AND `source_type`=0 AND `id`=0;
UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `id`=3821;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Thistlefur Totemic - On Respawn - Cast 'Coat of Thistlefur'" WHERE `entryorguid` IN (3922) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Thistlefur Den Watcher - On Reset - Cast 'Coat of Thistlefur'" WHERE `entryorguid` IN (3923) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Thistlefur Shaman - On Reset - Cast 'Coat of Thistlefur'" WHERE `entryorguid` IN (3924) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Thistlefur Avenger - On Reset - Cast 'Coat of Thistlefur'" WHERE `entryorguid` IN (3925) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=4, `event_param3`=0, `event_param4`=0, `comment`="Uthil Mooncall - On aggro - Cast 'Bear Form'" WHERE `entryorguid` IN (3941) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Son of Cenarius - On Reset - Cast Summon Treant Ally (Self)" WHERE `entryorguid` IN (4057) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Highperch Wyvern - On Reset - Cast 'Poison Proc' (No Repeat)" WHERE `entryorguid` IN (4107) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Highperch Consort - On Reset - Cast 'Poison Proc' (No Repeat)" WHERE `entryorguid` IN (4109) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Highperch Patriarch - On Reset - Cast 'Poison Proc' (No Repeat)" WHERE `entryorguid` IN (4110) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Venomous Cloud Serpent - On Reset - Cast 'Deadly Poison' (Phase 1) (No Repeat)" WHERE `entryorguid` IN (4118) AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (4196) AND `source_type`=0;
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (4196);
UPDATE `creature_template_addon` SET `auras`='6590' WHERE `entry` IN (4196); 
UPDATE `creature_template_addon` SET `auras`='7165' WHERE `entry` IN (4420); 
UPDATE `creature_template_addon` SET `auras`='7165' WHERE `entry` IN (4436);
UPDATE `smart_scripts` SET `event_type`=25, `action_type`=75, `comment`="Captain Flat Tusk - On Reset - Add aura 'Battle Stance' (No Repeat)" WHERE `entryorguid` IN (5824) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Henze Faulk - On Reset - Cast 'Permanent Feign Death'" WHERE `entryorguid` IN (6172) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Narm Faulk - On Reset - Cast 'Permanent Feign Death'" WHERE `entryorguid` IN (6177) AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6508) AND `source_type`=0;       
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (6508);
UPDATE `creature_template_addon` SET `auras`='14108' WHERE `entry` IN (6508); 
UPDATE `creature_template_addon` SET `auras`='14111' WHERE `entry` IN (6509, 6510, 6511, 6512); 
UPDATE `smart_scripts` SET `target_type`=1 WHERE `entryorguid` IN (6517) AND `source_type`=0 AND `id`=0;
UPDATE `creature_template_addon` SET `auras`='14178' WHERE `entry` IN (6517, 6518, 6519, 6527); 
UPDATE `creature_template_addon` SET `auras`='6408' WHERE `entry` IN (6886); 
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Stitched Golem - On Reset - Cast 'Disease Cloud' (No Repeat)" WHERE `entryorguid` IN (8545) AND `source_type`=0 AND `id`=0;
UPDATE `creature_template_addon` SET `auras`='3417' WHERE `entry` IN (9164, 9167); 
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Blazerunner - On Reset - Cast 'Blazerunner's Aura'" WHERE `entryorguid` IN (9376) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Azurous - On Reset - Cast 'Damage Immunity: Arcane'" WHERE `entryorguid` IN (10202) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Spellmaw - On Reset - Cast 'Damage Immunity: Arcane' (No Repeat)" WHERE `entryorguid` IN (10662) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Manaclaw - On Reset - Cast 'Damage Immunity: Arcane' (No Repeat)" WHERE `entryorguid` IN (10663) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Scryer - On Reset - Cast 'Damage Immunity: Arcane' (No Repeat)" WHERE `entryorguid` IN (10664) AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (11286, 11281, 11280, 11279, 11278, 11277) AND `source_type`=0;       
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (11286, 11281, 11280, 11279, 11278, 11277);
UPDATE `creature_template_addon` SET `auras`='17622' WHERE `entry` IN (11286, 11281, 11280, 11279, 11278, 11277); 
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Wildspawn Shadowstalker - On Reset - Cast 'Sneak'" WHERE `entryorguid` IN (11456) AND `source_type`=0 AND `id`=0;
UPDATE `creature_template_addon` SET `auras`='16577' WHERE `entry` IN (11885);
UPDATE `creature_template_addon` SET `auras`='18950' WHERE `entry` IN (12160); 
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Shadowglen Sentinel - On Respawn - Cast 'Invisibility and Stealth Detection' (No Repeat)" WHERE `entryorguid` IN (12160) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Enraged Foulweald - On Reset - Cast 'Corrupted Strength Passive' (No Repeat)" WHERE `entryorguid` IN (12921) AND `source_type`=0 AND `id`=0;
UPDATE `creature_template_addon` SET `auras`='21337' WHERE `entry` IN (13142); 
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid` IN (14363, 14365, 14367, 14438, 14439, 14376, 14423, 14404, 14375, 14377, 14402, 14403) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Huntress Skymane - On Respawn - Cast 'Invisibility and Stealth Detection'" WHERE `entryorguid` IN (14378) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid` IN (14484, 14485) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Eris Havenfire - On Reset - Cast Ancestor Invisibility" WHERE `entryorguid` IN (14494) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid` IN (16226, 16232) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid` IN (16424) AND `source_type`=0 AND `id`=0;
UPDATE `creature_template_addon` SET `auras`='29152' WHERE `entry` IN (16517, 16537, 16922);
UPDATE `smart_scripts` SET `event_type`=25 WHERE `action_param1` IN (18950);
UPDATE `creature_template_addon` SET `auras`='32900' WHERE `entry` IN (16805);
UPDATE `creature_template_addon` SET `auras`='33908' WHERE `entry` IN (16863); 
UPDATE `smart_scripts` SET `event_type`=25 WHERE `action_param1` IN (33900);
UPDATE `creature_template_addon` SET `auras`='32737' WHERE `entry` IN (16954);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17048, 17049) AND `source_type`=0;       
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (17048, 17049);
UPDATE `creature_template_addon` SET `auras`='29402' WHERE `entry` IN (17048, 17049);
UPDATE `creature_template_addon` SET `auras`='12550' WHERE `entry` IN (17160); 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (17478) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(17478, 0, 0, 0, 0, 0, 100, 6, 1000, 1000, 3000, 4000, 11, 12471, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Bleeding Hollow Scryer - IC - Cast Shadow Bolt'),
(17478, 0, 1, 0, 0, 0, 100, 6, 5000, 10000, 10000, 15000, 11, 30615, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Bleeding Hollow Scryer - IC - Cast Fear'),
(17478, 0, 2, 0, 25, 0, 100, 6, 0, 0, 0, 0, 11, 31059, 0, 0, 0, 0, 0, 19, 17281, 20, 0, 0, 0, 0, 0, 'Bleeding Hollow Scryer - On Reset - Cast Hellfire Channeling');
UPDATE `smart_scripts` SET `event_type`=25, `action_type`=75, `comment`= "Blood Elf Bandit - On Reset - Add aura 'Shadowstalker Stealth'" WHERE `entryorguid` IN (17591) AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18139, 18140, 18358, 18382, 17856, 17857, 17866, 17923, 17924, 17925) AND `source_type`=0;       
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (18139, 18140, 18358, 18382, 17856, 17857, 17866, 17923, 17924, 17925);
UPDATE `creature_template_addon` SET `auras`='35230' WHERE `entry` IN (18139, 18140, 18358, 18382, 17856, 17857, 17866, 17923, 17924, 17925);
UPDATE `smart_scripts` SET `link`=0, `event_type`=25, `action_type`=75 WHERE `entryorguid`=23090 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18152) AND `source_type`=0;
UPDATE `creature_template_addon` SET `auras`='24983' WHERE `entry` IN (18152); 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18297) AND `source_type`=0;       
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (18297);
UPDATE `creature_template_addon` SET `auras`='32199' WHERE `entry` IN (18297); 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18424) AND `source_type`=0;       
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (18424);
UPDATE `creature_template_addon` SET `auras`='32423' WHERE `entry` IN (18424); 
UPDATE `creature_template_addon` SET `auras`='32423' WHERE `entry` IN (18437);
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid` IN (18482) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Unliving Soldier - On Reset - Cast 'Protection Aura' (Phase 1) (No Repeat) (Dungeon)" WHERE `entryorguid` IN (18498) AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18560) AND `source_type`=0;       
UPDATE `creature_template` SET `InhabitType`=4, `AIName` = '', `flags_extra`=130 WHERE `entry` IN (18560);
UPDATE `creature_template` SET  `InhabitType`=4, `AIName` = 'SmartAI', `flags_extra`=130 WHERE `entry` IN (18563);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18563) AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18563, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 11, 32573, 0, 0, 0, 0, 0, 19, 18560, 20, 0, 0, 0, 0, 0,'Justin''s Bunny Channeler - On reset - Cast Justin''s Zappy Channel');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (32573);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,32573,0,0, 31,0,3,18560,0,0,0,'','Justin''s Zappy Channel effectt only on 18560');
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18564, 18581) AND `source_type`=0 AND `id`=0;  
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` IN (18564, 18581);
UPDATE `creature_template_addon` SET `auras`='32610' WHERE `entry` IN (18564);
UPDATE `creature_template_addon` SET `auras`='32609' WHERE `entry` IN (18581); 
UPDATE `creature_template` SET `InhabitType`=4, `AIName` = '' WHERE `entry` IN (18759);
UPDATE `creature_template_addon` SET `auras`='32840' WHERE `entry` IN (18759);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18781) AND `source_type`=0 AND `id`=0;  
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` IN (18781);
UPDATE `creature_template_addon` SET `auras`='32951' WHERE `entry` IN (18781);
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Wrath Priestess - On Reset - Cast 'Summon Fel Imp' (No Repeat)" WHERE `entryorguid` IN (18859) AND `source_type`=0 AND `id`=0;
DELETE FROM `creature` WHERE `id`=21135;
UPDATE `creature_template_addon` SET `auras`='32942' WHERE `entry` IN (18884);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19027, 19030) AND `source_type`=0 AND `id`=0;  
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` IN (19027, 19030);
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='34664' WHERE `entry` IN (19027, 19030);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19224) AND `source_type`=0 AND `id`=0;  
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` IN (19224);
UPDATE `creature_template_addon` SET `auras`='33569' WHERE `entry` IN (19224);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19607, 21956) AND `source_type`=0 AND `id`=0;  
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` IN (19607, 21956);
UPDATE `creature_template_addon` SET `auras`='37691' WHERE `entry` IN (19607, 21956);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19719) AND `source_type`=0 AND `id`=0;  
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` IN (19719);
UPDATE `creature_template_addon` SET `auras`='32648' WHERE `entry` IN (19719);
UPDATE `creature_template_addon` SET `auras`='24313' WHERE `entry` IN (19847);
UPDATE `creature_template_addon` SET `auras`='35848' WHERE `entry` IN (19926);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21663, 21453, 19985, 19945) AND `source_type`=0 AND `id`=0;  
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` IN (21663, 21453, 19985, 19945);
UPDATE `creature_template_addon` SET `auras`='12550' WHERE `entry` IN (30179, 19985, 19945, 21663, 21453);
DELETE FROM `creature_template_addon` WHERE `entry` IN (29690, 29733);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(29690, 1, '12550'),
(29733, 1, '12550');
UPDATE `creature_addon` SET `auras`='12550' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN(21453, 19985));
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20086, 20114) AND `source_type`=0 AND `id`=0;  
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` IN (20086, 20114);
UPDATE `creature_template_addon` SET `auras`='34840' WHERE `entry` IN (20086);
UPDATE `creature_template_addon` SET `auras`='34858' WHERE `entry` IN (20114);
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (26688, 21976, 22073, 22380, 28466, 34810, 20769, 26579); 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19421) AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20134) AND `source_type`=0 AND `id`=14;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20139) AND `source_type`=0 AND `id`=15;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18855) AND `source_type`=0 AND `id`=14;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20248) AND `source_type`=0 AND `id`=5;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20248, 0, 5, 0, 1, 0, 50, 0, 10000, 20000, 15000, 30000, 11, 34397, 0, 0, 0, 0, 0, 19, 19421, 30, 0, 0, 0, 0, 0,'20248 - Ooc - Cast Red Beam'),
(18855, 0, 14, 0, 1, 0, 50, 0, 10000, 20000, 15000, 30000, 11, 34397, 0, 0, 0, 0, 0, 19, 19421, 30, 0, 0, 0, 0, 0,'18855 - Ooc - Cast Red Beam'),
(20139, 0, 15, 0, 1, 0, 50, 0, 10000, 20000, 15000, 30000, 11, 34397, 0, 0, 0, 0, 0, 19, 19421, 30, 0, 0, 0, 0, 0,'20139 - Ooc - Cast Red Beam'),
(20134, 0, 14, 0, 1, 0, 50, 0, 10000, 20000, 15000, 30000, 11, 34397, 0, 0, 0, 0, 0, 19, 19421, 30, 0, 0, 0, 0, 0,'20134 - Ooc - Cast Red Beam');
UPDATE `conditions` SET `ConditionValue2`=19421 WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=34397;
UPDATE `creature` SET `position_x`=-3692.053, `position_y`=2685.259, `position_z`=108.866, `Orientation`=3.696 WHERE `guid`=74614;
UPDATE `smart_scripts` SET `event_type`=23, `event_param1`=37539, `event_flags`=0, `comment`="Socrethar - Has aura - Cast 'Nether Protection' (Phase 1) (No Repeat)" WHERE `entryorguid` IN (20132) AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20154) AND `source_type`=0 AND `id`=0;
UPDATE `creature_template_addon` SET `auras`='24313' WHERE `entry` IN (20154);
UPDATE `creature_template_addon` SET `auras`='8279' WHERE `entry` IN (22282, 21941, 20330);
UPDATE `creature_addon` SET `auras`='8279' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN(22282, 21941, 20330));
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20451) AND `source_type`=0 AND `id`=0;       
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (20451);
UPDATE `creature_template_addon` SET `auras`='16592' WHERE `entry` IN (20451);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20483) AND `source_type`=0;       
UPDATE `creature_template_addon` SET `auras`='28126' WHERE `entry` IN (20483);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20483, 0, 0, 0, 0, 0, 100, 0, 10000, 15000, 25000, 30000, 11, 36146, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,'Naberius - IC - Cast Chains of Naberius'),
(20483, 0, 1, 0, 0, 0, 100, 0, 1000, 4000, 4000, 4000, 11, 15497, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,'Naberius - IC - Cast Frostbolt'),
(20483, 0, 2, 0, 0, 0, 100, 0, 2000, 5000, 10000, 12000, 11, 36148, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,'Naberius - IC - Cast Chill Nova');
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20501) AND `source_type`=0 AND id=2;       
UPDATE `creature_template_addon` SET `auras`='35242' WHERE `entry` IN (20501);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20520) AND `source_type`=0 AND id=0;       
UPDATE `creature_template_addon` SET `auras`='32566' WHERE `entry` IN (20520);
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (20668);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20668) AND `source_type`=0 AND id=0;       
UPDATE `creature_template_addon` SET `auras`='37816' WHERE `entry` IN (20668);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20673) AND `source_type`=0 AND id=0;       
UPDATE `creature_template_addon` SET `auras`='19514' WHERE `entry` IN (20673);
UPDATE `creature_addon` SET `auras`='19514' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN(20673));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(20673, 0, 0, 0, 0, 0, 100, 0, 2000, 5000, 4000, 6000, 11, 36594, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,'Swiftwing Shredder - IC - Cast Lightning Breath');
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20806) AND `source_type`=0 AND id=0;       
UPDATE `creature_template_addon` SET `auras`='35242' WHERE `entry` IN (20806);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20825) AND `source_type`=0 AND `id`=0;       
UPDATE `creature_template_addon` SET `auras`='32567' WHERE `entry` IN (20825);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20845) AND `source_type`=0 AND `id`=0;       
UPDATE `creature_template_addon` SET `auras`='33345' WHERE `entry` IN (20845);
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (20880);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20880) AND `source_type`=0 AND `id`=0;       
UPDATE `creature_template_addon` SET `auras`='27987' WHERE `entry` IN (20880);
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (20879);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20879) AND `source_type`=0; 
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (20882);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20882) AND `source_type`=0 AND `id`=0;       
UPDATE `creature_template_addon` SET `auras`='16380' WHERE `entry` IN (20882);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (20899) AND `source_type`=0 AND `id`=0;       
UPDATE `creature_template_addon` SET `auras`='35242' WHERE `entry` IN (20899);
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (21073);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21073) AND `source_type`=0 AND `id`=0;       
UPDATE `creature_template_addon` SET `auras`='36113' WHERE `entry` IN (21073);
UPDATE `smart_scripts` SET `event_type`=25, `comment`="Dormant Infernal - On Reset - Cast 'Stationary Infernal Ball'" WHERE `entryorguid` IN (21080) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `target_type`=19, `target_param1`=18793, `target_param2`=10 WHERE `entryorguid`=21159 AND `source_type`=0 AND `id`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (36220);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,36220,0,0, 31,0,3,18793,0,0,0,'','Containment Beam only on 18793');
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`=21170 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21181) AND `source_type`=0 AND `id`=13;       
UPDATE `creature_template_addon` SET `auras`='17327' WHERE `entry` IN (21198, 21200, 21870, 21814, 21324);
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (21814, 21870);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21814, 21870) AND `source_type`=0 AND `id`=0;     
UPDATE `smart_scripts` SET `event_phase_mask`=0 WHERE `entryorguid`=21200 AND `source_type`=0 AND `id`=4;
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`=21316 AND `source_type`=0 AND `id`=0;
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (21337);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21337) AND `source_type`=0 AND `id`=0;
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (21349);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21349) AND `source_type`=0 AND `id`=0;     
UPDATE `creature_template_addon` SET `auras`='36575' WHERE `entry` IN (21349);
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (21404);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21404) AND `source_type`=0 AND `id`=0;     
UPDATE `creature_template_addon` SET `auras`='16245' WHERE `entry` IN (21404);
UPDATE `creature_addon` SET `auras`='16245' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN(21404));
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (21414);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21414) AND `source_type`=0 AND `id`=0;     
UPDATE `creature_template_addon` SET `auras`='36728' WHERE `entry` IN (21414);
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (21450);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21450) AND `source_type`=0 AND `id`=0;     
UPDATE `creature_template_addon` SET `auras`='36978' WHERE `entry` IN (21450);
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (21651);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21651) AND `source_type`=0 AND `id`=0;     
UPDATE `creature_template_addon` SET `auras`='37411' WHERE `entry` IN (21651);
UPDATE `creature_addon` SET `auras`='37411' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN(21651));
UPDATE `smart_scripts` SET `event_type`=54 WHERE `entryorguid` IN (21735) AND `source_type`=0 AND `id`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (36384);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,36384,0,0, 31,0,3,21211,0,0,0,'','Skartax Purple Beam only on 21211');
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (21737, 21757);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21737, 21757) AND `source_type`=0 AND `id`=0;     
UPDATE `creature_template_addon` SET `auras`='37248' WHERE `entry` IN (21737, 21757);
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (21761);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21761) AND `source_type`=0 AND `id`=0;     
UPDATE `creature_template_addon` SET `auras`='36716' WHERE `entry` IN (21761);
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (21787, 23067, 23068, 21763, 23066);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21787, 23067, 23068, 21763, 23066) AND `source_type`=0 AND `id`=0;     
UPDATE `creature_template_addon` SET `auras`='37411' WHERE `entry` IN (21787, 23067, 23068, 21763);
UPDATE `creature_addon` SET `auras`='37411' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (21787, 23067, 23068, 21763));
UPDATE `creature_template_addon` SET `auras`="37411 11919" WHERE `entry` IN (23066);
UPDATE `creature_addon` SET `auras`="37411 11919" WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (23066));
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (21788);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21788) AND `source_type`=0 AND `id`=0;     
UPDATE `creature_template_addon` SET `auras`='37467' WHERE `entry` IN (21788);
UPDATE `creature_template_addon` SET `auras`='22578' WHERE `entry` IN (21837);
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (21935, 21942, 21944);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21935, 21942, 21944) AND `source_type`=0 AND `id`=0;     
UPDATE `creature_template_addon` SET `auras`='33356' WHERE `entry` IN (21935, 21942, 21944);
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (21950, 21951);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21950, 21951) AND `source_type`=0 AND `id`=0;     
UPDATE `creature_template_addon` SET `auras`='22650' WHERE `entry` IN (21950, 21951);
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (22060);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (22060) AND `source_type`=0 AND `id`=0;     
UPDATE `creature_template_addon` SET `auras`='34189' WHERE `entry` IN (22060);
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (22093);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (22093) AND `source_type`=0 AND `id`=0;     
UPDATE `creature_template_addon` SET `auras`='37119' WHERE `entry` IN (22093);
UPDATE `smart_scripts` SET `target_type`=1 WHERE `entryorguid` IN (22018) AND `source_type`=0 AND `id`=2;
UPDATE `creature` SET `position_x`=-3584.313,`position_y`=1854.726, `position_z`=47.24,`orientation`=2.478 WHERE `guid`=84940;
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (22438, 22439, 22094, 22437, 22440);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (22438, 22439, 22094, 22437, 22440) AND `source_type`=0 AND `id`=0;     
UPDATE `creature_template_addon` SET `auras`='37119' WHERE `entry` IN (22438, 22439, 22094, 22437, 22440);
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (22214);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (22214) AND `source_type`=0 AND `id`=0;
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (22221, 22289);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (22221, 22289) AND `source_type`=0 AND `id`=0;     
UPDATE `creature_template_addon` SET `auras`='39102' WHERE `entry` IN (22221, 22289);
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (22242);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (22242) AND `source_type`=0;     
UPDATE `creature_template_addon` SET `auras`="38857 38860" WHERE `entry` IN (22242);
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (22389);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (22389) AND `source_type`=0;     
UPDATE `creature_template_addon` SET `auras`="16245" WHERE `entry` IN (22389);
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (23326);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23326) AND `source_type`=0;
UPDATE `creature_addon` SET `auras`='32732' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (23326));
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (23557);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23557) AND `source_type`=0;     
UPDATE `creature_template_addon` SET `auras`="42472" WHERE `entry` IN (23557);
UPDATE `creature_addon` SET `auras`='42472' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (23557));
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23564) AND `source_type`=0 AND `id`=12;     
UPDATE `creature_template_addon` SET `auras`="21862" WHERE `entry` IN (23564);
UPDATE `creature_addon` SET `auras`='21862' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (23564));
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24199) AND `source_type`=0 AND `id`=10;     
UPDATE `creature_template_addon` SET `auras`="21862" WHERE `entry` IN (24199);
UPDATE `creature_addon` SET `auras`='21862' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (24198));
DELETE FROM `creature_template_addon` WHERE `entry` IN (24198);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(24198, 1, '21862');
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (23583);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23583) AND `source_type`=0 AND `id`=0;     
UPDATE `creature_template_addon` SET `auras`="42175" WHERE `entry` IN (23583);
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (23698);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23698) AND `source_type`=0 AND `id`=0;
UPDATE `creature_addon` SET `auras`='43905' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (23698));
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`=23730 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24078) AND `source_type`=0 AND `id`=4;     
UPDATE `creature_template_addon` SET `auras`="43929" WHERE `entry` IN (24078);
UPDATE `creature_addon` SET `auras`='43929' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (24078));
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`=24335 AND `source_type`=0 AND `id`=0;
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (24345);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24345) AND `source_type`=0 AND `id`=0;  
UPDATE `creature_addon` SET `auras`='43312' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (24345));
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (24438);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24438) AND `source_type`=0 AND `id`=0;  
DELETE FROM `creature_template_addon` WHERE `entry` IN (24438);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(24438, 1, '43890');
DELETE FROM `creature_template_addon` WHERE `entry` IN (24464);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(24464, 1, '43874');
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (24567);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24567) AND `source_type`=0 AND `id`=0;  
DELETE FROM `creature_template_addon` WHERE `entry` IN (24567);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(24567, 1, '8876');
UPDATE `creature_addon` SET `auras`='36151' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (24601));
DELETE FROM `creature_template_addon` WHERE `entry` IN (24601);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(24601, 1, '36151');
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (24677);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24677) AND `source_type`=0 AND `id`=0;  
DELETE FROM `creature_template_addon` WHERE `entry` IN (24677);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(24677, 1, '44366');
UPDATE `smart_scripts` SET `event_type`=25, target_type=19, target_param1=25670, target_param2=25, target_param3=0 WHERE `entryorguid`=24957 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`=25001 AND `source_type`=0 AND `id`=0;
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (25355);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25355) AND `source_type`=0 AND `id`=0;  
DELETE FROM `creature_template_addon` WHERE `entry` IN (25355);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(25355, 1, '50637');
DELETE FROM `creature_template_addon` WHERE `entry` IN (25851, 25599, 25597, 25595, 25837,25592,25509, 25508, 25506, 25486, 25485, 25483,25867, 25824, 25373, 25593, 25371, 25370, 25369, 25368, 25367, 25798, 25363, 25799);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(25851, 4097, '45769'), (25599, 4097, '45769'), (25597, 4097, '45769'), (25595, 4097, '45769'), (25837, 4097, '45769'), (25592, 4097, '45769'), (25867, 4097, '45769'), (25824, 4097, '45769'),  (25373, 4097, '45769'), (25593, 4097, '45769'), (25367, 4097, '45769'), (25798, 4097, '45769'), (25509, 4097, '45769'), (25508, 4097, '45769'), (25506, 4097, '45769'), (25486, 4097, '45769'), (25485, 4097, '45769'), (25483, 4097, '45769'), (25371, 4097, '45769'), (25370, 4097, '45769'), (25369, 4097, '45769'), (25368, 4097, '45769'), (25363, 4097, '45769'), (25799, 4097, '45769');
UPDATE `creature_addon` SET `auras`='45769' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (25851, 25599, 25597, 25595, 25837,25592,25509, 25508, 25506, 25486, 25485, 25483,25867, 25824, 25373, 25593, 25371, 25370, 25369, 25368, 25367, 25798, 25363, 25799));
UPDATE `creature_template_addon` SET `auras`="45658" WHERE `entry` IN (34839, 25613, 25479);
UPDATE `creature_addon` SET `auras`='45658' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (34839, 25613, 25479));
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (34839, 25613, 25479) AND `source_type`=0;       
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(34839, 0, 0, 0, 0, 0, 100, 0, 2000, 3000, 9000, 11000, 11, 49816, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,"Kvaldir Mist Binder - In Combat - Cast 'Mist of Strangulation'"),
(25613, 0, 0, 0, 0, 0, 100, 0, 2000, 3000, 9000, 11000, 11, 49816, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,"Skadir Mistweaver - In Combat - Cast 'Mist of Strangulation'"),
(25479, 0, 0, 0, 0, 0, 100, 0, 2000, 3000, 9000, 11000, 11, 49816, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,"Kvaldir Mistweaver - In Combat - Cast 'Mist of Strangulation'");
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (25484);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25484) AND `source_type`=0 AND `id`=0;  
UPDATE `creature_template_addon` SET `auras`="34189" WHERE `entry` IN (25484);
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`=25584 AND `source_type`=0 AND `id`=5;
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`=25651 AND `source_type`=0 AND `id`=0;
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (25668);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25668) AND `source_type`=0 AND `id`=0;  
DELETE FROM `creature_template_addon` WHERE `entry` IN (25668);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(25668, 1, '46695');
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (25679);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25679) AND `source_type`=0 AND `id`=0;  
DELETE FROM `creature_template_addon` WHERE `entry` IN (25679);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(25679, 1, '36151');
UPDATE `creature_addon` SET `auras`='36151' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (25679));
DELETE FROM `creature_template_addon` WHERE `entry` IN (25791);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(25791, 1, '45948');
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (25817, 25748, 25750);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25817, 25748, 25750) AND `source_type`=0 AND `id`=0;  
DELETE FROM `creature_template_addon` WHERE `entry` IN (25817, 25748, 25750);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(25817, 1, '45948'),
(25748, 1, '45948'),
(25750, 1, '45948');
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`=25955 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`=26167 AND `source_type`=0 AND `id`=0;
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (26169);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26169) AND `source_type`=0 AND `id`=0;
UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `id`=25762;
UPDATE `creature_template` SET `InhabitType`=4 WHERE `Entry`=25762;
DELETE FROM `creature` WHERE `guid` IN (111130, 111128, 111131, 111129, 111127, 111132, 111133, 111136, 111134, 111135, 111138, 111139, 111142, 111141, 111076, 111074, 111079, 111078, 111077, 111081, 111083, 111080, 111082, 111084, 111094);
DELETE FROM `vehicle_template_accessory` WHERE `entry` = 25762;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(25762,25760,0,1,'Kvaldir Raider',8,0),
(25762,25760,1,1,'Kvaldir Raider',8,0),
(25762,25760,2,1,'Kvaldir Raider',8,0),
(25762,25760,3,1,'Kvaldir Raider',8,0),
(25762,25760,4,1,'Kvaldir Raider',8,0),
(25762,25760,5,1,'Kvaldir Raider',8,0),
(25762,25760,6,1,'Kvaldir Raider',8,0);
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (26197);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26197) AND `source_type`=0 AND `id`=0;  
DELETE FROM `creature_template_addon` WHERE `entry` IN (26197);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(26197, 1, '15088');
UPDATE `creature_addon` SET `auras`='15088' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (26197));
DELETE FROM `creature_template_addon` WHERE `entry` IN (26343);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(26343, 1, '32423');
DELETE FROM `creature_template_addon` WHERE `entry` IN (26417);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(26417, 1, '47329');
UPDATE `creature_addon` SET `auras`='47329' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (26417));
DELETE FROM `creature_template_addon` WHERE `entry` IN (26467);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(26467, 1, "47677");
UPDATE `creature_addon` SET `auras`="47677" WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (26467));
DELETE FROM `smart_scripts` WHERE `entryorguid`=26467 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26467, 0, 0, 0, 0, 0, 100, 0, 2000, 3000, 12000, 15000, 11, 51879, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,"Jormungar Tunneler - IC - Cast 'Corrode Flesh'"),
(26467,0,1,0,0,0,100,0,4000,6000,19000,21000,11,32738,0,0,0,0,0,2,0,0,0,0,0,0,0,'Jormungar Tunneler  - In Combat - Cast Bore');
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (26511);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26511) AND `source_type`=0 AND `id`=0;  
DELETE FROM `creature_template_addon` WHERE `entry` IN (26511);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(26511, 1, "8876");
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26543) AND `source_type`=0 AND `id`>0; 
UPDATE `creature_template_addon` SET `auras`="43167 47119" WHERE `entry` IN (26543);
UPDATE `creature_template` SET `faction`=1985 WHERE `entry`=26816;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26787) AND `source_type`=0 AND `id`>0;
UPDATE `creature_template_addon` SET `auras`="43167 47119" WHERE `entry` IN (26787);
UPDATE `smart_scripts` SET `event_type`=1, `event_flags`=1, `target_type`=19, `target_param1`=27292, `target_param2`=50, `action_param3`=0, `action_param2`=64, `comment`="Flamebringer's Chain - OOC no repeat- Cast 'Flamebringer's Chain'" WHERE `entryorguid`=27297 AND `source_type`=0 AND `id`=0;
DELETE FROM `creature_template_addon` WHERE `entry` IN (27500);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(27500, 257, "15088");
UPDATE `creature_addon` SET `auras`="15088" WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (27500));
UPDATE `creature_addon` SET `auras`="49343" WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (27693));
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`=27736 AND `source_type`=0;
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (28158);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (28158) AND `source_type`=0;  
DELETE FROM `creature_template_addon` WHERE `entry` IN (28158);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(28158, 1, "54450 45857");
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`=28161 AND `source_type`=0 AND `id`=2 AND `link`=3 ;
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (28440);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (28440) AND `source_type`=0;  
DELETE FROM `creature_template_addon` WHERE `entry` IN (28440);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(28440, 1, "51583");
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`=28504 AND `source_type`=0 AND `id`=0 ;
DELETE FROM `creature_template_addon` WHERE `entry` IN (28521);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(28521, 1, "51868 61438");
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (28557) AND `source_type`=0 AND `id`=1;
UPDATE `creature_template_addon` SET `auras`="48356" WHERE `entry` IN (28557);
UPDATE `smart_scripts` SET `event_type`=23, `event_param1`=48356 WHERE `entryorguid`=28608 AND `source_type`=0 AND `id`=0 ;
UPDATE `smart_scripts` SET `event_type`=23, `event_param1`=48356 WHERE `entryorguid`IN (28936, 28609, 28611) AND `source_type`=0 AND `id`=3 ;
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`IN (28752) AND `source_type`=0 AND `id` IN (0, 15) ;
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`IN (28754) AND `source_type`=0 AND `id` IN (0) ;
UPDATE `creature_template_addon` SET `auras`="54582 54262 54263" WHERE `entry` IN (28779);
DELETE FROM `smart_scripts` WHERE `entryorguid`=28779 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28779, 0, 0, 0, 0, 0, 100, 0, 2000, 3000, 9000, 11000, 11, 54580, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,"Blood of Mam'toth - IC - Cast 'Coagulate'");
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`IN (28854) AND `source_type`=0 AND `id` IN (0);
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`IN (29344) AND `source_type`=0 AND `id` IN (0) ;
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (29648);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29648) AND `source_type`=0 AND `id`=0;  
DELETE FROM `creature_template_addon` WHERE `entry` IN (29648);
UPDATE `creature_addon` SET `auras`="57764" WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (29648));
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`IN (29821) AND `source_type`=0 AND `id` IN (0) ;
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (29848);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29848) AND `source_type`=0 AND `id`=0; 
UPDATE `creature_template_addon` SET `auras`="55474" WHERE `entry` IN (29848);
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (29953);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29953) AND `source_type`=0 AND `id`=0; 
UPDATE `creature_addon` SET `auras`="55587" WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (29953));
UPDATE `creature_template_addon` SET `auras`="55587" WHERE `entry` IN (29953);
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (30228);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (30228) AND `source_type`=0 AND `id`=0;
UPDATE `creature_template_addon` SET `auras`="56682" WHERE `entry` IN (30228);
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`IN (30279) AND `source_type`=0 AND `id` IN (0) ;
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`IN (30283) AND `source_type`=0 AND `id` IN (0, 1) ;
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (30617, 30627);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (30617, 30627) AND `source_type`=0 AND `id`=0;  
DELETE FROM `creature_template_addon` WHERE `entry` IN (30617, 30627);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(30617, 1, "41408"),
(30627, 1, "41408");
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`IN (30632) AND `source_type`=0 AND `id` IN (0);
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (30947);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (30947) AND `source_type`=0 AND `id`=0;  
DELETE FROM `creature_template_addon` WHERE `entry` IN (30947);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(30947, 1, "58540");
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`IN (31900) AND `source_type`=0 AND `id` IN (0);
UPDATE `creature_template` SET  `AIName` = '' WHERE `entry` IN (33361, 33403, 33379, 33373, 33372);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (33361, 33403, 33379, 33373, 33372) AND `source_type`=0 AND `id`=0;  
DELETE FROM `creature_template_addon` WHERE `entry` IN (33361, 33403, 33379, 33373, 33372);
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES 
(33361, 1, "63433"),
(33403, 1, "63436"),
(33379, 1, "63403"),
(33373, 1, "63430"),
(33372, 1, "63399");
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`IN (33429) AND `source_type`=0 AND `id` IN (6);
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`IN (34127) AND `source_type`=0 AND `id` IN (5, 8);

DELETE FROM `gossip_menu` WHERE `entry`=8713;
INSERT INTO `gossip_menu` (`entry`, `text_id`, `VerifiedBuild`) VALUES
(8713, 10960, 0),
(8713, 10835, 0);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=8713 AND `id`=1;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(8713, 1, 0, 'We\'re ready to face Illidan.', 20903, 1, 1, 0, 0, 0, 0, '', 0, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN(14,15) AND `SourceGroup`=8713;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 8713, 10960, 0, 0, 13, 0, 10, 1, 0, 0, 0, 0, '', 'Show Gossip if Akama is in Intro State'),
(14, 8713, 10835, 0, 0, 13, 0, 10, 2, 0, 0, 0, 0, '', 'Show Gossip if Akama is in Waiting Fight State'),
(15, 8713, 0, 0, 0, 13, 0, 10, 1, 0, 0, 0, 0, '', 'Show Option if Akama in Intro State'),
(15, 8713, 1, 0, 0, 13, 0, 10, 2, 0, 0, 0, 0, '', 'Show Option if Akama is in Waiting Fight State');

-- Illidan Group Summon
DELETE FROM `creature` WHERE `guid`=12776;
DELETE FROM `creature_summon_groups` WHERE `summonerId`=22917;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(22917,0,1,23089,748.5206,236.6311,353.0794,2.373648,8,0); -- Akama

-- Akama Group Summon
DELETE FROM `creature_summon_groups` WHERE `summonerId`=23089;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(23089,0,1,23410,751.4565,311.0107,312.19,0,8,0), -- Spirit of Undalo
(23089,0,1,23411,751.6437,297.2233,312.2083,0,8,0); -- Spirit of Olum

UPDATE `creature_template` SET `scale`=1 WHERE `entry`=23412; -- Door Trigger
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=2, `unit_flags2`=2099200, `flags_extra`=`flags_extra` | 512 WHERE `entry`=22917; -- Illidan Stormrage
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry`=23336; -- Flame Crash
UPDATE `creature_template` SET `speed_walk`=0.35, `speed_run`=0.992063, `flags_extra`=128, `ScriptName`='npc_illidan_db_target' WHERE `entry`=23070;
UPDATE `creature_template` SET `speed_walk`=1.6, `speed_run`=0.571429 WHERE `entry`=23375; -- Shadow Demon
UPDATE `creature_template` SET `ScriptName`='npc_maiev' WHERE `entry`=23197;

UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=185916;
UPDATE `gameobject_template` SET `ScriptName`='' WHERE `entry`=185916;

-- Blaze SAI
SET @ENTRY := 23259;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,1,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blaze - On Reset - Set Reactstate Passive (No Repeat)"),
(@ENTRY,0,1,0,25,0,100,0,0,0,0,0,11,40610,2,0,0,0,0,1,0,0,0,0,0,0,0,"Blaze - On Reset - Cast 'Blaze'"),
(@ENTRY,0,3,0,25,0,100,0,0,0,0,0,11,40031,2,0,0,0,0,1,0,0,0,0,0,0,0,"Blaze - On Reset - Cast 'Birth - No Visual (Instant Spawn)'");

-- Cage Trap Trigger - 1 SAI
SET @ENTRY := 23292;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,3,0,0,0,0,11,40704,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cage Trap Trigger - 1 - On Just Summoned - Cast 'Caged' (No Repeat) (Normal Dungeon)");

-- Cage Trap Trigger - 2 SAI
SET @ENTRY := 23293;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,3,0,0,0,0,11,40707,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cage Trap Trigger - 2 - On Just Summoned - Cast 'Caged' (No Repeat) (Normal Dungeon)");

-- Cage Trap Trigger - 3 SAI
SET @ENTRY := 23294;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,3,0,0,0,0,11,40708,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cage Trap Trigger - 3 - On Just Summoned - Cast 'Caged' (No Repeat) (Normal Dungeon)");

-- Cage Trap Trigger - 4 SAI
SET @ENTRY := 23295;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,3,0,0,0,0,11,40709,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cage Trap Trigger - 4 - On Just Summoned - Cast 'Caged' (No Repeat) (Normal Dungeon)");

-- Cage Trap Trigger - 5 SAI
SET @ENTRY := 23296;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,3,0,0,0,0,11,40710,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cage Trap Trigger - 5 - On Just Summoned - Cast 'Caged' (No Repeat) (Normal Dungeon)");

-- Cage Trap Trigger - 6 SAI
SET @ENTRY := 23297;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,3,0,0,0,0,11,40711,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cage Trap Trigger - 6 - On Just Summoned - Cast 'Caged' (No Repeat) (Normal Dungeon)");

-- Cage Trap Trigger - 7 SAI
SET @ENTRY := 23298;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,3,0,0,0,0,11,40712,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cage Trap Trigger - 7 - On Just Summoned - Cast 'Caged' (No Repeat) (Normal Dungeon)");

-- Cage Trap Trigger - 8 SAI
SET @ENTRY := 23299;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,3,0,0,0,0,11,40713,2,0,0,0,0,1,0,0,0,0,0,0,0,"Cage Trap Trigger - 8 - On Just Summoned - Cast 'Caged' (No Repeat) (Normal Dungeon)");

DELETE FROM `creature_addon` WHERE `guid`=52484; -- Illidan
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(52484, 0, 0, 256, 0, 0, '39656 43689');

DELETE FROM `creature_template_addon` WHERE `entry` IN(23069,23336,23498);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(23069, 0, 0, 256, 0, 0, 40029),
(23336, 0, 0, 256, 0, 0, 40836),
(23498, 0, 0, 16908544, 0, 0, '34429 41913');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN(-41914,-41917); -- Remove Parasitic hack

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_illidan_akama_teleport',
'spell_illidan_akama_door_channel',
'spell_illidan_draw_soul',
'spell_illidan_parasitic_shadowfiend',
'spell_illidan_throw_warglaive',
'spell_illidan_tear_of_azzinoth_channel',
'spell_illidan_flame_blast',
'spell_illidan_return_glaives',
'spell_illidan_agonizing_flames',
'spell_illidan_demon_transform1',
'spell_illidan_demon_transform2',
'spell_illidan_flame_burst',
'spell_illidan_find_target',
'spell_illidan_eye_blast',
'spell_illidan_cage_trap',
'spell_illidan_caged',
'spell_maiev_down',
'spell_illidan_cage_teleport',
'spell_illidan_despawn_akama');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(41077,'spell_illidan_akama_teleport'),
(41268,'spell_illidan_akama_door_channel'),
(40904,'spell_illidan_draw_soul'),
(41917,'spell_illidan_parasitic_shadowfiend'),
(41914,'spell_illidan_parasitic_shadowfiend'),
(39635,'spell_illidan_throw_warglaive'),
(39849,'spell_illidan_throw_warglaive'),
(39857,'spell_illidan_tear_of_azzinoth_channel'),
(40631,'spell_illidan_flame_blast'),
(39873,'spell_illidan_return_glaives'),
(40834,'spell_illidan_agonizing_flames'),
(40511,'spell_illidan_demon_transform1'),
(40398,'spell_illidan_demon_transform2'),
(41126,'spell_illidan_flame_burst'),
(41081,'spell_illidan_find_target'),
(39908,'spell_illidan_eye_blast'),
(40761,'spell_illidan_cage_trap'),
(40760,'spell_illidan_caged'),
(40409,'spell_maiev_down'),
(40693,'spell_illidan_cage_teleport'),
(41242,'spell_illidan_despawn_akama');

DELETE FROM `creature_text` WHERE entry IN(23089,23410,23411); -- Akama and Minions
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23089, 0, 0, 'This door is all that stands between us and the Betrayer.  Stand aside, friends.', 12, 0, 100, 1, 0, 0, 21563, 0, 'SAY_AKAMA_DOOR'),
(23089, 1, 0, 'I cannot do this alone...', 12, 0, 100, 274, 0, 0, 21548, 0, 'SAY_AKAMA_ALONE'),
(23089, 2, 0, 'I thank you for your aid, brothers.  Our people will be redeemed!', 12, 0, 100, 66, 0, 0, 21554, 0, 'SAY_AKAMA_SALUTE'),
(23089, 3, 0, 'Be wary, friends. The Betrayer meditates in the court just beyond.', 12, 0, 100, 0, 0, 11388, 21555, 0, 'SAY_AKAMA_BETRAYER'),
(23089, 4, 0, 'We\'ve come to end your reign, Illidan. My people, and all of Outland, shall be free!', 14, 0, 100, 25, 0, 11389, 20893, 0, 'SAY_AKAMA_FREE'),
(23089, 5, 0, 'The time has come! The moment is at hand!', 14, 0, 100, 22, 0, 11380, 20894, 0, 'SAY_AKAMA_TIME_HAS_COME'),
(23089, 6, 0, 'I will deal with these mongrels! Strike now, friends! Strike at the Betrayer!', 14, 0, 100, 22, 0, 11390, 21250, 0, 'SAY_AKAMA_MINIONS'),
(23089, 7, 0, 'The Light will bless these dismal halls once again.... I swear it.', 14, 0, 100, 1, 0, 11387, 21514, 0, 'SAY_AKAMA_LIGHT'),
(23089, 8, 0, 'Let us finish what we\'ve started.  I will lead you to Illidan\'s abode once you\'ve recovered your strength.', 12, 0, 100, 1, 0, 0, 21520, 0, 'SAY_AKAMA_FINISH'),
--  AKAMA MINIONS
(23410, 0, 0, 'You are not alone, Akama.', 12, 0, 100, 0, 0, 0, 21545, 0, 'SAY_SPIRIT_ALONE'), -- Spirit of Udalo
(23411, 0, 0, 'Your people will always be with you!', 12, 0, 100, 0, 0, 0, 21546, 0, 'SAY_SPIRIT_ALONE'); -- Spirit of Olum

DELETE FROM `creature_text` WHERE entry=22917 AND `groupid` IN(8,9,10,11,12,13,14); -- Illidan
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(22917, 8, 0, 'Akama. Your duplicity is hardly surprising. I should have slaughtered you and your malformed brethren long ago.', 14, 0, 100, 6, 0, 11463, 20867, 0, 'Illidan SAY_ILLIDAN_DUPLICITY'),
(22917, 9, 0, 'Boldly said. But I remain... unconvinced.', 14, 0, 100, 6, 0, 11464, 20868, 0, 'Illidan SAY_ILLIDAN_UNCONVINCED'),
(22917, 10, 0, 'You are not prepared!', 14, 0, 100, 406, 0, 11466, 20884, 0, 'Illidan SAY_ILLIDAN_PREPARED'),
(22917, 11, 0, 'Is this it, mortals? Is this all the fury you can muster?', 14, 0, 100, 0, 0, 11476, 21068, 0, 'Illidan SAY_ILLIDAN_SHADOW_PRISON'),
(22917, 12, 0, 'Maiev... How is it even possible?', 14, 0, 100, 1, 0, 11477, 21069, 0, 'Illidan SAY_ILLIDAN_CONFRONT_MAIEV'),
(22917, 13, 0, 'Feel the hatred of ten thousand years!', 14, 0, 100, 0, 0, 11470, 21501, 0, 'Illidan SAY_ILLIDAN_FRENZY'),
(22917, 14, 0, 'You have won... Maiev. But the huntress... is nothing without the hunt. You... are nothing... without me.', 14, 0, 100, 0, 0, 11478, 21506, 0, 'Illidan SAY_ILLIDAN_DEFEATED');

DELETE FROM `creature_text` WHERE entry=23197 AND ((`groupid` IN(1,2,3,4,5,6,7)) OR (`groupid`=0 AND id=2)); -- Maiev
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23197, 1, 0, 'Their fury pales before mine, Illidan. We have some unsettled business between us.', 14, 0, 100, 6, 0, 11491, 21070, 0, 'Maiev Shadowsong SAY_MAIEV_SHADOWSONG_APPEAR'),
(23197, 2, 0, 'My long hunt is finally over. Today, Justice will be done!', 14, 0, 100, 5, 0, 11492, 21071, 0, 'Maiev Shadowsong SAY_MAIEV_SHADOWSONG_JUSTICE'),
(23197, 3, 0, 'There shall be no prison for you this time!', 14, 0, 100, 0, 0, 11495, 22208, 0, 'Maiev Shadowsong SAY_MAIEV_SHADOWSONG_TRAP'),
(23197, 4, 0, '%s falls to the floor.', 16, 0, 100, 0, 0, 0, 21317, 0, 'Maiev Shadowsong SAY_MAIEV_SHADOWSONG_DOWN'),
(23197, 5, 0, 'It is finished. You are beaten.', 14, 0, 100, 0, 0, 11496, 21507, 0, 'Maiev Shadowsong SAY_MAIEV_SHADOWSONG_FINISHED'),
(23197, 6, 0, 'He\'s right. I feel nothing... I am... nothing.', 14, 0, 100, 0, 0, 11497, 21508, 0, 'Maiev Shadowsong SAY_MAIEV_SHADOWSONG_OUTRO'),
(23197, 7, 0, 'Farewell, champions.', 14, 0, 100, 0, 0, 11498, 21509, 0, 'Maiev Shadowsong SAY_MAIEV_SHADOWSONG_FAREWELL');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`IN(40704,40707,40708,40709,40710,40711,40712,40713); -- Caged (Visual)
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,40704,0,0,31,0,3,23296,0,0,0,0,'','Effect_0 hits Cage Trap Trigger - 5'),
(13,1,40707,0,0,31,0,3,23297,0,0,0,0,'','Effect_0 hits Cage Trap Trigger - 6'),
(13,1,40708,0,0,31,0,3,23298,0,0,0,0,'','Effect_0 hits Cage Trap Trigger - 7'),
(13,1,40709,0,0,31,0,3,23299,0,0,0,0,'','Effect_0 hits Cage Trap Trigger - 8'),
(13,1,40710,0,0,31,0,3,23292,0,0,0,0,'','Effect_0 hits Cage Trap Trigger - 1'),
(13,1,40711,0,0,31,0,3,23293,0,0,0,0,'','Effect_0 hits Cage Trap Trigger - 2'),
(13,1,40712,0,0,31,0,3,23294,0,0,0,0,'','Effect_0 hits Cage Trap Trigger - 3'),
(13,1,40713,0,0,31,0,3,23295,0,0,0,0,'','Effect_0 hits Cage Trap Trigger - 4');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`IN(39849,39635); -- Throw Glaive
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,39849,0,0,31,0,3,23448,52503,0,0,0,'','Effect_0 hits Glaive Target'),
(13,1,39635,0,0,31,0,3,23448,52502,0,0,0,'','Effect_0 hits Glaive Target');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=39873; -- Return Glaive
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,39873,0,0,31,0,3,22917,0,0,0,0,'','Effect_0 hits Illidan Stormrage');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=40761; -- Cage Trap
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,40761,0,0,31,0,3,22917,0,0,0,0,'','Effect_0 hits Illidan Stormrage');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=40693; -- Cage Trap Teleport
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,40693,0,0,31,0,3,23197,0,0,0,0,'','Effect_0 hits Maiev Shadowsong');

DELETE FROM `script_spline_chain_meta` WHERE `entry`=23089 AND `chainId`=1;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(23089, 1, 0, 3297, 2391),
(23089, 1, 1, 2744, 0);
DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=23089 AND `chainId`=1;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(23089, 1, 0, 0, 609.77200, 308.45600, 271.82600),
(23089, 1, 0, 1, 610.93130, 308.29240, 272.00720),
(23089, 1, 0, 2, 625.68130, 307.04240, 271.75720),
(23089, 1, 0, 3, 628.43130, 307.04240, 271.75720),
(23089, 1, 0, 4, 630.18130, 307.04240, 271.75720),
(23089, 1, 0, 5, 631.68130, 306.79240, 271.75720),
(23089, 1, 0, 6, 642.59050, 305.62870, 271.68840),
(23089, 1, 1, 0, 633.37040, 306.42300, 271.66000),
(23089, 1, 1, 1, 642.81750, 305.84460, 271.93120),
(23089, 1, 1, 2, 660.76460, 305.76630, 271.70240);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=23089 AND `chainId`=2;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(23089, 2, 0, 5077, 3297),
(23089, 2, 1, 5259, 3656),
(23089, 2, 2, 4364, 3640),
(23089, 2, 3, 3825, 2422),
(23089, 2, 4, 3466, 2422),
(23089, 2, 5, 2911, 1235),
(23089, 2, 6, 2798, 1203),
(23089, 2, 7, 2172, 0);
DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=23089 AND `chainId`=2;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(23089, 2, 0, 0, 660.76460, 305.76630, 271.70240),
(23089, 2, 0, 1, 664.95350, 321.87480, 271.94820),
(23089, 2, 0, 2, 665.70350, 324.87480, 271.94820),
(23089, 2, 0, 3, 673.14240, 354.98330, 271.69400),
(23089, 2, 1, 0, 668.70380, 337.33420, 271.68930),
(23089, 2, 1, 1, 673.44130, 355.17200, 271.79190),
(23089, 2, 1, 2, 680.94130, 363.17200, 271.79190),
(23089, 2, 1, 3, 681.94130, 363.92200, 271.79190),
(23089, 2, 1, 4, 691.69130, 374.67200, 271.79190),
(23089, 2, 1, 5, 694.19130, 377.42200, 271.79190),
(23089, 2, 1, 6, 696.67880, 380.00980, 271.89450),
(23089, 2, 2, 0, 685.40080, 368.01770, 271.67940),
(23089, 2, 2, 1, 691.88500, 374.69560, 272.08730),
(23089, 2, 2, 2, 694.38500, 377.19560, 272.08730),
(23089, 2, 2, 3, 696.88500, 379.94560, 272.33730),
(23089, 2, 2, 4, 699.38500, 379.44560, 272.33730),
(23089, 2, 2, 5, 704.13500, 378.44560, 274.58730),
(23089, 2, 2, 6, 714.88500, 375.94560, 277.83730),
(23089, 2, 2, 7, 719.63500, 374.69560, 280.08730),
(23089, 2, 2, 8, 721.36930, 374.37350, 280.99510),
(23089, 2, 3, 0, 715.07500, 375.81030, 277.75200),
(23089, 2, 3, 1, 719.93350, 374.65850, 280.34520),
(23089, 2, 3, 2, 721.68350, 374.40850, 281.34520),
(23089, 2, 3, 3, 725.93350, 368.15850, 284.84520),
(23089, 2, 3, 4, 728.18350, 364.65850, 287.84520),
(23089, 2, 3, 5, 732.68350, 358.65850, 291.84520),
(23089, 2, 3, 6, 736.79190, 352.50670, 296.43850),
(23089, 2, 4, 0, 729.85970, 362.33540, 289.17460),
(23089, 2, 4, 1, 732.96180, 358.54080, 292.23680),
(23089, 2, 4, 2, 736.96180, 352.54080, 296.73680),
(23089, 2, 4, 3, 737.71180, 350.79080, 297.73680),
(23089, 2, 4, 4, 741.71180, 344.04080, 301.73680),
(23089, 2, 4, 5, 745.56390, 336.74620, 306.29910),
(23089, 2, 5, 0, 741.17650, 344.62910, 301.12160),
(23089, 2, 5, 1, 741.90870, 343.92740, 301.90360),
(23089, 2, 5, 2, 745.65870, 336.67740, 306.40360),
(23089, 2, 5, 3, 747.65870, 326.42740, 309.40360),
(23089, 2, 5, 4, 749.14090, 319.22560, 311.68560),
(23089, 2, 6, 0, 745.88320, 335.18240, 306.71790),
(23089, 2, 6, 1, 747.93570, 326.16000, 309.39880),
(23089, 2, 6, 2, 749.18570, 319.41000, 311.89880),
(23089, 2, 6, 3, 749.43570, 318.41000, 312.39880),
(23089, 2, 6, 4, 751.48830, 308.63760, 312.07980),
(23089, 2, 7, 0, 748.24830, 323.59770, 310.07210),
(23089, 2, 7, 1, 749.51420, 319.24910, 311.87080),
(23089, 2, 7, 2, 749.76420, 317.99910, 312.37080),
(23089, 2, 7, 3, 751.76420, 308.99910, 312.37080),
(23089, 2, 7, 4, 755.51420, 304.99910, 312.37080),
(23089, 2, 7, 5, 755.78010, 304.40060, 312.16960);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=23089 AND `chainId`=3;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(23089, 3, 0, 4686, 3640),
(23089, 3, 1, 3261, 2453),
(23089, 3, 2, 3415, 2438),
(23089, 3, 3, 4631, 3641),
(23089, 3, 4, 2627, 0);
DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=23089 AND `chainId`=3;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(23089, 3, 0, 0, 755.78010, 304.40060, 312.16960),
(23089, 3, 0, 1, 759.85900, 303.60590, 312.72120),
(23089, 3, 0, 2, 770.35900, 301.10590, 312.72120),
(23089, 3, 0, 3, 779.60900, 299.10590, 319.97120),
(23089, 3, 0, 4, 781.35900, 298.60590, 319.97120),
(23089, 3, 0, 5, 786.35900, 297.60590, 319.97120),
(23089, 3, 0, 6, 787.35900, 297.35590, 319.97120),
(23089, 3, 0, 7, 798.93790, 294.31120, 319.77270),
(23089, 3, 1, 0, 788.57950, 296.73280, 319.76110),
(23089, 3, 1, 1, 799.06010, 294.20360, 320.06920),
(23089, 3, 1, 2, 798.56010, 289.20360, 320.31920),
(23089, 3, 1, 3, 797.54060, 276.17450, 330.37730),
(23089, 3, 2, 0, 798.04160, 282.67720, 325.05990),
(23089, 3, 2, 1, 797.59280, 276.20070, 330.76180),
(23089, 3, 2, 2, 795.34280, 262.95070, 341.51180),
(23089, 3, 2, 3, 794.59280, 258.70070, 341.51180),
(23089, 3, 2, 4, 793.64410, 254.72420, 341.46370),
(23089, 3, 3, 0, 795.28610, 263.76330, 340.53130),
(23089, 3, 3, 1, 795.05350, 262.63820, 341.82590),
(23089, 3, 3, 2, 794.30350, 258.38820, 341.82590),
(23089, 3, 3, 3, 793.55350, 254.63820, 341.82590),
(23089, 3, 3, 4, 792.55350, 254.13820, 341.82590),
(23089, 3, 3, 5, 787.80350, 251.38820, 341.82590),
(23089, 3, 3, 6, 783.55350, 249.13820, 341.82590),
(23089, 3, 3, 7, 773.05350, 242.88820, 349.07590),
(23089, 3, 3, 8, 766.30350, 238.88820, 353.82590),
(23089, 3, 3, 9, 764.82070, 238.01300, 353.62060),
(23089, 3, 4, 0, 772.12710, 242.24910, 349.37410),
(23089, 3, 4, 1, 766.03170, 239.02710, 353.95420),
(23089, 3, 4, 2, 764.78170, 238.27710, 353.70420),
(23089, 3, 4, 3, 760.28170, 237.77710, 353.45420),
(23089, 3, 4, 4, 750.28170, 236.27710, 353.20420),
(23089, 3, 4, 5, 748.43620, 235.80510, 353.03430);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=23089 AND `chainId`=4;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(23089, 4, 0, 6925, 0);
DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=23089 AND `chainId`=4;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(23089, 4, 0, 0, 748.43620, 235.80510, 353.03430),
(23089, 4, 0, 1, 747.83060, 249.37560, 353.26520),
(23089, 4, 0, 2, 747.58060, 252.87560, 353.26520),
(23089, 4, 0, 3, 747.33060, 257.37560, 353.26520),
(23089, 4, 0, 4, 747.33060, 260.87560, 353.26520),
(23089, 4, 0, 5, 746.83060, 277.12560, 353.26520),
(23089, 4, 0, 6, 746.08060, 293.12560, 353.26520),
(23089, 4, 0, 7, 745.58060, 302.87560, 353.26520),
(23089, 4, 0, 8, 745.22500, 304.94600, 352.99600);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=23089 AND `chainId`=5;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(23089, 5, 0, 5893, 0);
DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=23089 AND `chainId`=5;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(23089, 5, 0, 0, 745.22500, 304.94600, 352.99600),
(23089, 5, 0, 1, 744.74730, 320.38350, 353.25160),
(23089, 5, 0, 2, 744.49730, 331.88350, 353.25160),
(23089, 5, 0, 3, 744.49730, 348.38350, 353.25160),
(23089, 5, 0, 4, 744.24730, 349.63350, 353.25160),
(23089, 5, 0, 5, 744.24730, 352.13350, 353.25160),
(23089, 5, 0, 6, 743.99730, 362.63350, 353.25160),
(23089, 5, 0, 7, 743.76950, 363.82110, 353.00730);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=23089 AND `chainId`=6;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(23089, 6, 0, 9319, 0);
DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=23089 AND `chainId`=6;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(23089, 6, 0, 0, 752.27710, 369.94010, 353.15840),
(23089, 6, 0, 1, 753.94520, 368.68850, 353.20910),
(23089, 6, 0, 2, 762.69520, 361.68850, 353.70910),
(23089, 6, 0, 3, 763.94520, 360.68850, 353.95910),
(23089, 6, 0, 4, 764.94520, 359.68850, 352.95910),
(23089, 6, 0, 5, 780.19520, 347.18850, 341.70910),
(23089, 6, 0, 6, 780.44520, 346.68850, 341.70910),
(23089, 6, 0, 7, 792.19520, 320.18850, 320.20910),
(23089, 6, 0, 8, 794.69520, 314.93850, 320.20910),
(23089, 6, 0, 9, 796.19520, 311.43850, 320.20910),
(23089, 6, 0, 10, 799.11330, 304.43700, 319.75990);

DELETE FROM `script_spline_chain_meta` WHERE `entry`=23089 AND `chainId`=7;
INSERT INTO `script_spline_chain_meta` (`entry`,`chainId`,`splineId`,`expectedDuration`,`msUntilNext`) VALUES
(23089, 7, 0, 4704, 0);
DELETE FROM `script_spline_chain_waypoints` WHERE `entry`=23089 AND `chainId`=7;
INSERT INTO `script_spline_chain_waypoints` (`entry`,`chainId`,`splineId`,`wpId`,`x`,`y`,`z`) VALUES
(23089, 7, 0, 0, 753.04650, 369.30210, 353.12700),
(23089, 7, 0, 1, 751.76920, 369.24790, 353.31160),
(23089, 7, 0, 2, 739.51920, 368.74790, 353.06160),
(23089, 7, 0, 3, 723.26920, 367.99790, 353.06160),
(23089, 7, 0, 4, 722.76920, 367.49790, 353.06160),
(23089, 7, 0, 5, 715.76920, 369.49790, 353.06160),
(23089, 7, 0, 6, 714.51920, 368.24790, 353.06160);

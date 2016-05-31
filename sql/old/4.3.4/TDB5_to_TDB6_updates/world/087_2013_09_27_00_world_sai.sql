-- The Storm King's Vengeance (12919)
-- http://www.youtube.com/watch?v=hq9lmWNkXGA&feature=related
SET @GYMER                  := 29884; -- Gymer <King of Storm Giants>
SET @CAGED_GYMER            := 29647; -- Gymer
SET @ALGAR                  := 29872; -- Algar the Chosen
SET @NAVARIUS               := 29821; -- Prince Navarius
SET @THRYM                  := 29895; -- Thrym <The Hope Ender>
SET @NAVARIUS_CREDIT        := 55660; -- Navarius Kill Credit
SET @ALGAR_CREDIT           := 55661; -- Algar Kill Credit
SET @THYRM_CREDIT           := 55662; -- Thrym Kill Credit
SET @GUID                   := 4223;  -- Note: Kirkhammett sucks ...
-- Used in spell script
/*
SET @GRABBED                := 55424;
SET @EXPLOSION              := 55569;
SET @STORM_COULD            := 29939;
SET @HEALING_WINDS          := 55549;
*/

DELETE FROM `spell_script_names` WHERE `spell_id` IN (55516,55421);
INSERT INTO `spell_script_names` (`spell_id` ,`ScriptName`) VALUES
(55516, 'spell_q12919_gymers_grab'),
(55421, 'spell_q12919_gymers_throw');

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE entry IN (@CAGED_GYMER,@GYMER,@ALGAR,@NAVARIUS,@THRYM,29889,29893,29894,29890,29891,29887);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(@CAGED_GYMER*100,@CAGED_GYMER);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@CAGED_GYMER,0,0,1,62,0,100,0,9852,2,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Gymer - On Gossip Option Select -  Close Gossip'),
(@CAGED_GYMER,0,1,2,61,0,100,0,0,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gymer - On Link -  Say'),
(@CAGED_GYMER,0,2,0,61,0,100,0,0,0,0,0,80,@CAGED_GYMER*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Gymer - On Link - Start Timed Script'),
(@CAGED_GYMER*100,9,0,0,0,0,100,0,1500,1500,0,0,12,@GYMER,2,600000,0,0,0,7,0,0,0,0,0,0,0,'Gymer - On Script - Summon Gymer '),
(@CAGED_GYMER*100,9,1,0,0,0,100,0,1500,1500,0,0,85,55430,0,0,0,0,0,7,0,0,0,0,0,0,0,'Gymer - On Script - Cast Gymer''s Buddy Invoker'),
--
(@CAGED_GYMER,0,4,0,1,0,100,0,10000,20000,30000,40000,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,'Gymer - OOC - Say Random');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=9852;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 9852, 13639, 0, 0, 14, 0, 12919, 0, 0, 0, 0, 0, '', 'Show text if player doesn''t have quest rewarded'),
(14, 9852, 13640, 0, 0, 9, 0, 12919, 0, 0, 0, 0, 0, '', 'Show text if player has quest rewarded'),
(15, 9852, 0, 0, 0, 9, 0, 12919, 0, 0, 0, 0, 0, '', 'Show gossip option if player is on quest'),
(15, 9852, 1, 0, 0, 9, 0, 12919, 0, 0, 0, 0, 0, '', 'Show gossip option if player is on quest'),
(15, 9852, 2, 0, 0, 9, 0, 12919, 0, 0, 0, 0, 0, '', 'Show gossip option if player is on quest');

-- Gymer's Buddy
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= 29884;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(29884, 55430, 1, 0);

-- Gymer Summon Pos
DELETE FROM `spell_target_position` WHERE `id` = 55431;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
(55431, 571, 5799.29, -1597.31, 237.17, 2.14);

DELETE FROM `gossip_menu` WHERE (`entry`=9852 AND `text_id`=13639) OR (`entry`=9852 AND `text_id`=13640) OR (`entry`=9855 AND `text_id`=13647) OR (`entry`=9860 AND `text_id`=13656);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(9852, 13639), -- 29647
(9852, 13640), -- 29647
(9855, 13647), -- 29647
(9860, 13656); -- 29647

DELETE FROM `gossip_menu_option` WHERE (`menu_id`=9852 AND `id`=0) OR (`menu_id`=9852 AND `id`=1) OR (`menu_id`=9852 AND `id`=2);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES 
(9852, 0, 0, 'Gymer, where are Algar, Navarius and Thrym?', 1, 3, 9855, 0, 0, 0, ''),
(9852, 1, 0, 'Gymer, what do I need to know? I''ve never ridden on a giant.', 1, 3, 9860, 0, 0, 0, ''),
(9852, 2, 0, 'I''m ready, Gymer. Let''s go!', 1, 3, 0, 0, 0, 0, '');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@GYMER,@ALGAR,@NAVARIUS,@THRYM,@THRYM*100,29889,29893,29894,29890,29891,29887) AND `source_type` IN (0,9);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GYMER,0,0,1,27,0,100,1,0,0,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gymer - On Passenger boarded - Say'),
(@GYMER,0,1,0,61,0,100,0,0,0,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gymer - On Link - Say'),
(@GYMER,0,2,0,28,0,100,1,0,0,0,0,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gymer - On Passenger Removed - Say'),
(@GYMER,0,3,0,54,0,100,1,0,0,0,0,11,55461,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gymer - On Spawn - Cast Storm Aura'),
(@GYMER,0,4,0,54,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gymer - On Spawn - Cast Storm Aura'),
(@GYMER,0,5,0,54,0,100,0,0,0,0,0,44,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Gymer - On Spawn - Set Phase'),
(@GYMER,0,6,0,73,0,100,0,0,0,0,0,11,46598,0,0,0,0,0,7,0,0,0,0,0,0,0,'Gymer - On Link - Cast Summon Gymer Force cast'),
-- Algar the Chosen
(@ALGAR,0,0,0,0,0,100,0,6000,10000,16000,23000,11,42729,0,0,0,0,0,1,0,0,0,0,0,0,0,'Algar the Chosen - IC - Cast Dreadful Roar'),
(@ALGAR,0,1,0,6,0,100,0,0,0,0,0,11,@ALGER_CREDIT,2,0,0,0,0,7,0,0,0,0,0,0,0,'Algar the Chosen - On Death - Cast criteria credit'),
-- Prince Navarius
(@NAVARIUS,0,0,0,11,0,100,1,0,0,0,0,11,55706,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Navarius - Cast Sinister Shield- On Spawn'),
(@NAVARIUS,0,1,0,0,0,100,0,7000,16000,15000,19000,11,51009,1,0,0,0,0,2,0,0,0,0,0,0,0,'Prince Navarius - IC - Cast Soul Deflection'),
(@NAVARIUS,0,2,0,0,0,100,0,9000,15000,18000,21000,11,51016,1,0,0,0,0,2,0,0,0,0,0,0,0,'Prince Navarius - IC - Cast Vampiric Bolt'),
(@NAVARIUS,0,3,0,0,0,100,0,16000,28000,26000,34000,11,50992,1,0,0,0,0,2,0,0,0,0,0,0,0,'Prince Navarius - IC -Cast Soul Blast'),
(@NAVARIUS,0,4,5,6,0,100,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Navarius - On Death  - Say 1'),
(@NAVARIUS,0,5,6,61,0,100,0,0,0,0,0,12,@THRYM,1,120000,0,0,0,8,0,0,0,5611.733, -2302.771, 289.4654, 1.745329,'Prince Navarius - On Link  - Spawn Thrym'),
(@NAVARIUS,0,6,0,61,0,100,0,0,0,0,0,11,@NAVARIUS_CREDIT,2,0,0,0,0,7,0,0,0,0,0,0,0,'Prince Navarius - On Link - Cast criteria credit'),
(@NAVARIUS,0,7,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Prince Navarius - On Aggro  - Say 0'),
-- Thrym 
(@THRYM,0,0,4,11,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thrym - On spawn - Yell'),
(@THRYM,0,1,0,0,0,100,0,8000,16000,15000,21000,11,28167,0,0,0,0,0,5,0,0,0,0,0,0,0,'Thrym - IC - Cast Chain Lightning'),
(@THRYM,0,2,0,0,0,100,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thrym - IC - Yell'),
(@THRYM,0,3,0,6,0,100,0,0,0,0,0,11,@THRYM_CREDIT,2,0,0,0,0,7,0,0,0,0,0,0,0,'Thrym - On Death - Cast criteria credit'),
(@THRYM,0,4,0,11,0,100,0,0,0,0,0,97,40,30,0,0,0,0,1,0,0,0,5555.583, -2223.97, 235.967,0,'Thrym - On Script - Jump to pos'),
(@THRYM,0,5,0,61,0,100,1,0,0,0,0,80,@THRYM*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thrym - On spawn - Yell'),
(@THRYM*100,9,0,0,61,0,100,0,3000,3000,3000,3000,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Thrym - On spawn - Yell'),
-- Vargul Plaguehound
(29889,0,0,0,0,0,100,0,6000,10000,16000,23000,11,50047,0,0,0,0,0,2,0,0,0,0,0,0,0,'Vargul Plaguehound - IC - Cast Broken Bone'),
(29889,0,1,0,0,0,100,0,2000,15000,26000,33000,11,50046,0,0,0,0,0,2,0,0,0,0,0,0,0,'Vargul Plaguehound - IC - Cast Gnaw Bone'),
-- Banshee Soulclaimer 
(29893,0,0,0,0,0,100,0,4000,7000,9000,12000,11,28993,0,0,0,0,0,2,0,0,0,0,0,0,0,'Banshee Soulclaimer - IC - Cast Banshee''s Wail'),
-- Vargul Plaguetalon
(29894,0,0,0,0,0,100,0,3000,9000,14000,21000,11,55079,0,0,0,0,0,2,0,0,0,0,0,0,0,'Vargul Plaguetalon - IC - Cast Swoop'),
-- Vargul Deathwaker
(29890,0,0,0,0,0,100,0,3000,13000,19000,26000,11,56038,0,0,0,0,0,2,0,0,0,0,0,0,0,'Vargul Deathwaker - IC - Cast Plaguebolt'),
-- Vargul Runelord 
(29891,0,0,0,0,0,100,0,3000,13000,19000,26000,11,56036,0,0,0,0,0,2,0,0,0,0,0,0,0,'Vargul Runelord - IC - Cast Rune of Destruction'),
-- Vargul Doombringer
(29887,0,0,0,0,0,100,0,2000,20000,30000,40000,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,'Vargul Doombringer - IC - Say Random');


UPDATE `creature_model_info` SET `bounding_radius`=10,`combat_reach`=12,`gender`=0 WHERE `modelid`=26656; -- Gymer
-- Caged Gymer
UPDATE `creature_template` SET  `gossip_menu_id`=9852, `speed_walk`=2, `speed_run`=1.42857146263123, `minlevel`=77, `maxlevel`=77, `unit_flags`=0x8000, `modelid1`=26656, `npcflag`=0x3 WHERE `entry`=29647;
-- Gymer <King of Storm Giants>
UPDATE `creature_template` SET  `IconName`='vehichleCursor', `speed_walk`=4, `speed_run`=4, `spell1`=55426,`spell2`=55429,`spell3`=55516,`spell4`=55421,`VehicleId`=205, `minlevel`=80, `maxlevel`=80, `faction_A`=1629, `faction_H`=1629, `unit_flags`=0x8, `modelid1`=26656, `unit_class`=4 WHERE `entry`=29884;
-- Vargul Runelord
UPDATE `creature_template` SET `faction_A`=1885, `faction_H`=1885, `speed_walk`=1.071429, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=29891;
-- Vargul Slayer
UPDATE `creature_template` SET `faction_A`=1885, `faction_H`=1885, `speed_walk`=1.428571, `speed_run`=2, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=29892;
-- Vargul Plaguetalon
UPDATE `creature_template` SET `faction_A`=1885, `faction_H`=1885, `speed_walk`=2.285714, `speed_run`=2, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=29894; 
-- Vargul Deathwaker
UPDATE `creature_template` SET `faction_A`=1885, `faction_H`=1885, `speed_walk`=1.071429, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=29890;
-- Vargul Blighthound
UPDATE `creature_template` SET `faction_A`=1885, `faction_H`=1885, `speed_walk`=1.428571, `speed_run`=1.6, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=29889;
-- Banshee Soulclaimer
UPDATE `creature_template` SET `faction_A`=1885, `faction_H`=1885, `speed_walk`=1.142857, `speed_run`=1, `InhabitType`=5, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=29893;
-- Storm Cloud
UPDATE `creature_template` SET `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0, `ScriptName`='npc_storm_cloud' WHERE `entry`=29939;
-- Reanimated Corpse
UPDATE `creature_template` SET `faction_A`=1885, `faction_H`=1885, `speed_walk`=1.142857, `speed_run`=0.777776, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=29897;
-- Vargul Doombringer
UPDATE `creature_template` SET `faction_A`=1885, `faction_H`=1885, `speed_walk`=1.071429, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=29887;
 -- Prince Navarius
UPDATE `creature_template` SET `faction_A`=1885, `faction_H`=1885, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=32832, `dynamicflags`=0 WHERE `entry`=29821;
 -- Acolyte of Pain
UPDATE `creature_template` SET `faction_A`=1885, `faction_H`=1885, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=29935;
 -- Acolyte of Agony
UPDATE `creature_template` SET `maxlevel`=75, `faction_A`=1885, `faction_H`=1885, `speed_walk`=1.142857, `speed_run`=1, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=29934;
 -- Algar the Chosen
UPDATE `creature_template` SET `faction_A`=2068, `faction_H`=2068, `speed_walk`=1.385714, `speed_run`=4, `rangeattacktime`=2000, `unit_flags`=32832, `dynamicflags`=0 WHERE `entry`=29872;
 -- Thrym
UPDATE `creature_template` SET `faction_A`=974, `faction_H`=974, `speed_walk`=3.571429, `speed_run`=4, `rangeattacktime`=2000, `unit_flags`=64, `dynamicflags`=0 WHERE `entry`=29895;

DELETE FROM `creature_text` WHERE `entry`IN (@THRYM,@GYMER,@CAGED_GYMER,@NAVARIUS,29887);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- Thrym
(29895, 0, 0, 'MASTER! NO!', 14, 0, 100, 53, 0, 0, 'Thrym to Gymer'),
(29895, 1, 1, 'THRYM CRUSH!', 14, 0, 100, 25, 0, 0, 'Thrym to Gymer'),
-- Gymer
(29884, 1, 0, 'Taste Gymer''s size 600!', 14, 0, 100, 0, 0, 0, 'Gymer to Reanimated Corpse'),
(29884, 1, 1, 'I will crush you under foot!', 14, 0, 100, 0, 0, 0, 'Gymer to Reanimated Corpse'),
(29884, 1, 2, 'STORMS GRANT ME POWER!', 14, 0, 100, 0, 0, 0, 'Gymer'),
(29884, 1, 3, 'Tiny creatures, I trample you!', 14, 0, 100, 0, 0, 0, 'Gymer to Reanimated Corpse'),
(29884, 1, 4, 'I''ll wipe you off of my boots later!', 14, 0, 100, 0, 0, 0, 'Gymer to Reanimated Corpse'),
(29884, 1, 5, 'AAARRRRRRGGGGGGHHHHHHH!! SUCH POWER!', 14, 0, 100, 0, 0, 0, 'Gymer'),
(29884, 1, 6, 'LIGHTNING GUIDE MY FURY!', 14, 0, 100, 0, 0, 0, 'Gymer'),
(29884, 1, 7, 'THE LIGHTNING COURSES THROUGH ME!', 14, 0, 100, 0, 0, 0, 'Gymer'),
(29884, 8, 8, 'Prince Navarius is on the other side of the Dead Fields to the east.', 42, 0, 100, 0, 0, 0, 'Gymer'),
(29884, 9, 9, 'Algar the Chosen is at the Reliquary of Pain to the northeast.', 42, 0, 100, 0, 0, 0, 'Gymer'),
(29884, 10, 10, 'Farewell, friend. May we meet again under better circumstances. I''ll never forget what you did for me!', 12, 0, 100, 0, 0, 0, 'Gymer'),
-- Caged Gymer random ooc text
(29647, 1, 0, 'My brothers will come for me and then you will see what true power is!', 12, 0, 100, 1, 0, 0, 'Gymer to Vargul Runelord'),
(29647, 1, 1, 'I will crush you all!', 12, 0, 100, 1, 0, 0, 'Gymer to Vargul Deathwaker'),
(29647, 1, 2, 'Ugly little monsters, pray I don''t get out!', 12, 0, 100, 1, 0, 0, 'Gymer to Vargul Slayer'),
(29647, 1, 3, 'Your torture only adds to my rage!', 12, 0, 100, 1, 0, 0, 'Gymer to Vargul Slayer'),
(29647, 1, 4, 'Ugly little monsters, pray I don''t get out!', 12, 0, 100, 1, 0, 0, 'Gymer to Vargul Runelord'),
(29647, 1, 5, 'Wretched beasts!', 12, 0, 100, 1, 0, 0, 'Gymer to Vargul Slayer'),
(29647, 1, 6, 'I will devour you whole!', 12, 0, 100, 1, 0, 0, 'Gymer to Vargul Runelord'),
(29647, 7, 7, 'FREE!!! Soon you will feel the wrath of the storm king!', 14, 0, 100, 53, 0, 0, 'Gymer'),
(29647, 1, 8, 'Wretched beasts!', 12, 0, 100, 1, 0, 0, 'Gymer to Vargul Runelord'),
(29647, 1, 9, 'Ugly little monsters, pray I don''t get out!', 12, 0, 100, 1, 0, 0, 'Gymer to Vargul Deathwaker'),
(29647, 1, 10, 'Your torture only adds to my rage!', 12, 0, 100, 1, 0, 0, 'Gymer to Vargul Runelord'),
-- Prince Navarius
(29821, 0, 0, 'Oh, you freed him, did you? No matter, his death and reconstruction will only be slightly delayed.', 14, 0, 100, 0, 0, 0, 'Prince Navarius to Gymer'),
(29821, 1, 1, 'Thrym... Av... Avenge me...', 14, 0, 100, 0, 0, 0, 'Prince Navarius to Gymer'),
-- Vargul Doombringer
(29887, 1, 0, 'I''ll eat your heart!', 12, 0, 100, 0, 0, 13537, 'Vargul Doombringer to Gymer'),
(29887, 1, 1, 'Sniveling pig!', 12, 0, 100, 0, 0, 13539, 'Vargul Doombringer to Gymer'),
(29887, 1, 2, 'I will feed you to the dogs!', 12, 0, 100, 0, 0, 13534, 'Vargul Doombringer to Gymer'),
(29887, 1, 3, 'Die, maggot!', 12, 0, 100, 0, 0, 13536, 'Vargul Doombringer to Gymer'),
(29887, 1, 4, 'Ugglin oo bjorr!', 12, 0, 100, 0, 0, 13540, 'Vargul Doombringer to Gymer'),
(29887, 1, 5, 'I''ll eat your heart!', 12, 0, 100, 0, 0, 13540, 'Vargul Doombringer to Gymer'),
(29887, 1, 6, 'I spit on you!', 12, 0, 100, 0, 0, 13538, 'Vargul Doombringer to Gymer'),
(29887, 1, 7, 'Your entrails will make a fine necklace.', 12, 0, 100, 0, 0, 13535, 'Vargul Doombringer to Gymer');

DELETE FROM `creature_equip_template` WHERE `entry` IN (29891,29892,29890,29887,29872);
INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(29891, 40605, 0, 0),       -- Vargul Runelord
(29892, 40609, 40609, 0),   -- Vargul Slayer
(29890, 40606, 0, 0),       -- Vargul Deathwaker
(29887, 34818, 0, 0),       -- Vargul Doombringer
(29872, 34820, 0, 0);       -- Algar the Chosen

DELETE FROM `creature_template_addon` WHERE `entry` IN (29452,29449,29646,29451,29453,29450,29939,29890,29887,29664,29872,29895,29884);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(29452, 0, 0x0, 0x1, ''),               	-- Vargul Blighthound
(29449, 0, 0x0, 0x1, ''),               	-- Vargul Deathwaker
(29646, 0, 0x3000000, 0x1, ''),         	-- Banshee Soulclaimer
(29451, 0, 0x0, 0x1, '56035'),          	-- Vargul Slayer - Diminish Soul
(29453, 0, 0x3000000, 0x1, ''),         	-- Vargul Plaguetalon
(29450, 0, 0x0, 0x1, '54512'),          	-- Vargul Runelord - Plague Shield
(29939, 0, 0x2000000, 0x1, ''),    			-- Storm Cloud 
(29664, 0, 0x0, 0x1, '54942'),          	-- Ragemane - Cosmetic Orange Cloud
(29890, 0, 0x0, 0x1, ''),          			-- Vargul Deathwaker 
(29887, 0, 0x0, 0x1, ''),          			-- Vargul Doombringer
(29872, 26645, 0x3000000, 0x1, ''),     	-- Algar the Chosen + mount
(29895, 0, 0x0, 0x1, ''),               	-- Thrym
(29884, 0, 0, 257, ''); 						-- Gymer

-- Condition for passenger removal, only needs to execute if passenger is player.
DELETE FROM `conditions` WHERE `SourceEntry`=29884;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(22, 3, 29884, 0, 0, 32, 0, 16, 0, 0, 0, 0, 0, '', 'Execute event only if type is player');

-- Conditions for Throw Explosion
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 13 AND `SourceEntry`=55571;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 55571, 0, 1, 31, 0, 3, 29887, 0, 0, 0, 0, '', 'Throw only hits 29887'),
(13, 1, 55571, 0, 2, 31, 0, 3, 29889, 0, 0, 0, 0, '', 'Throw only hits 29989'),
(13, 1, 55571, 0, 3, 31, 0, 3, 29890, 0, 0, 0, 0, '', 'Throw only hits 29890'),
(13, 1, 55571, 0, 4, 31, 0, 3, 29891, 0, 0, 0, 0, '', 'Throw only hits 29891'),
(13, 1, 55571, 0, 5, 31, 0, 3, 29892, 0, 0, 0, 0, '', 'Throw only hits 29892'),
(13, 1, 55571, 0, 6, 31, 0, 3, 29893, 0, 0, 0, 0, '', 'Throw only hits 29893'),
(13, 1, 55571, 0, 7, 31, 0, 3, 29894, 0, 0, 0, 0, '', 'Throw only hits 29894'),
(13, 1, 55571, 0, 8, 31, 0, 3, 29897, 0, 0, 0, 0, '', 'Throw only hits 29897'),
(13, 1, 55571, 0, 9, 31, 0, 3, 29934, 0, 0, 0, 0, '', 'Throw only hits 29934'),
(13, 1, 55571, 0, 10, 31, 0, 3, 29935, 0, 0, 0, 0, '', 'Throw only hits 29935');

-- Conditions for Gymer's Grab
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 13 AND `SourceEntry`=55516;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 55516, 0, 1, 31, 0, 3, 29887, 0, 0, 0, 0, '', 'Gymer''s Grab only hits29887'),
(13, 1, 55516, 0, 2, 31, 0, 3, 29889, 0, 0, 0, 0, '', 'Gymer''s Grab only hits 29989'),
(13, 1, 55516, 0, 3, 31, 0, 3, 29890, 0, 0, 0, 0, '', 'Gymer''s Grab only hits 29890'),
(13, 1, 55516, 0, 4, 31, 0, 3, 29891, 0, 0, 0, 0, '', 'Gymer''s Grab only hits 29891'),
(13, 1, 55516, 0, 5, 31, 0, 3, 29892, 0, 0, 0, 0, '', 'Gymer''s Grab only hits 29892'),
(13, 1, 55516, 0, 6, 31, 0, 3, 29893, 0, 0, 0, 0, '', 'Gymer''s Grab only hits 29893'),
(13, 1, 55516, 0, 7, 31, 0, 3, 29894, 0, 0, 0, 0, '', 'Gymer''s Grab only hits 29894'),
(13, 1, 55516, 0, 8, 31, 0, 3, 29897, 0, 0, 0, 0, '', 'Gymer''s Grab only hits 29897'),
(13, 1, 55516, 0, 9, 31, 0, 3, 29934, 0, 0, 0, 0, '', 'Gymer''s Grab only hits 29934'),
(13, 1, 55516, 0, 10, 31, 0, 3, 29939, 0, 0, 0, 0, '', 'Gymer''s Grab only hits 29935');

-- 209 Spawns in phase 256; that's the phase the player goes in when Gymer's vehicle spell is cast on him.
DELETE FROM `creature` WHERE phasemask=256 AND id IN (29821,29872,29887,29889,29890,29891,29892,29893,29894,29895,29897,29934,29935,29939);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(@GUID    , 29821, 571, 1, 256, 0, 0, 5543.87, -2221.51, 235.402, 0.62832, 600, 0, 0, 88008, 54645, 0, 0, 0, 0),
(@GUID+1  , 29872, 571, 1, 256, 0, 0, 6234.94, -2034.97, 234.052, 1.44615, 600, 0, 0, 176550, 3809, 1, 0, 0, 0),
(@GUID+2  , 29887, 571, 1, 256, 0, 0, 6193.72, -1980.32, 231.695, 2.38464, 300, 10, 0, 34137, 0, 1, 0, 0, 0),
(@GUID+3  , 29887, 571, 1, 256, 0, 0, 6204.54, -1968.83, 233.226, 2.37286, 300, 10, 0, 34137, 0, 1, 0, 0, 0),
(@GUID+4  , 29887, 571, 1, 256, 0, 0, 6133.42, -2001.64, 231.773, 2.49538, 300, 10, 0, 34137, 0, 1, 0, 0, 0),
(@GUID+5  , 29887, 571, 1, 256, 0, 0, 6145.06, -1986.18, 231.879, 2.49931, 300, 10, 0, 34137, 0, 1, 0, 0, 0),
(@GUID+6  , 29887, 571, 1, 256, 0, 0, 6153.54, -1974.82, 231.927, 2.49931, 300, 10, 0, 34137, 0, 1, 0, 0, 0),
(@GUID+7  , 29887, 571, 1, 256, 0, 0, 6161.59, -1964.07, 233.557, 2.49145, 300, 10, 0, 34137, 0, 1, 0, 0, 0),
(@GUID+8  , 29887, 571, 1, 256, 0, 0, 6135.05, -1977.74, 232.608, 2.56214, 300, 10, 0, 34137, 0, 1, 0, 0, 0),
(@GUID+9  , 29889, 571, 1, 256, 0, 0, 5674.37, -1468.56, 234.446, 4.52842, 600, 10, 0, 10282, 0, 1, 0, 0, 0),
(@GUID+10 , 29889, 571, 1, 256, 0, 0, 5586.2, -1480.24, 229.789, 3.65192, 600, 10, 0, 10282, 0, 1, 0, 0, 0),
(@GUID+11 , 29889, 571, 1, 256, 0, 0, 5820.47, -1406.84, 232.627, 2.12275, 600, 10, 0, 10282, 0, 1, 0, 0, 0),
(@GUID+12 , 29889, 571, 1, 256, 0, 0, 5751.21, -1573.51, 229.397, 4.99966, 600, 10, 0, 10282, 0, 1, 0, 0, 0),
(@GUID+13 , 29889, 571, 1, 256, 0, 0, 5786.81, -1626.29, 235.068, 1.75989, 600, 10, 0, 10282, 0, 1, 0, 0, 0),
(@GUID+14 , 29889, 571, 1, 256, 0, 0, 5722.32, -1609.86, 235.452, 3.01653, 600, 10, 0, 10282, 0, 1, 0, 0, 0),
(@GUID+15 , 29889, 571, 1, 256, 0, 0, 5655.16, -1554.06, 229.985, 3.86084, 600, 10, 0, 10282, 0, 1, 0, 0, 0),
(@GUID+16 , 29890, 571, 1, 256, 0, 0, 5781.15, -1338.38, 231.596, 5.94606, 600, 10, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+17 , 29890, 571, 1, 256, 0, 0, 5826.03, -1513.24, 229.113, 5.01536, 600, 10, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+18 , 29890, 571, 1, 256, 0, 0, 5636.28, -1549.44, 229.052, 3.26393, 600, 10, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+19 , 29890, 571, 1, 256, 0, 0, 5682.03, -1341.61, 231.087, 2.83117, 600, 10, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+20 , 29891, 571, 1, 256, 0, 0, 5685.83, -1450.21, 233.333, 4.78681, 600, 10, 0, 8508, 7981, 1, 0, 0, 0),
(@GUID+21 , 29891, 571, 1, 256, 0, 0, 5732.31, -1566.44, 230.02, 4.73184, 600, 10, 0, 8508, 7981, 1, 0, 0, 0),
(@GUID+22 , 29891, 571, 1, 256, 0, 0, 5769.41, -1604.24, 234.079, 0.137435, 600, 0, 0, 8508, 7981, 1, 0, 0, 0),
(@GUID+23 , 29891, 571, 1, 256, 0, 0, 5745.56, -1634.73, 236.355, 5.56829, 600, 10, 0, 8508, 7981, 1, 0, 0, 0),
(@GUID+24 , 29892, 571, 1, 256, 0, 0, 5738.29, -1312.05, 232.462, 4.10745, 600, 10, 0, 10635, 0, 1, 0, 0, 0),
(@GUID+25 , 29892, 571, 1, 256, 0, 0, 5565.59, -1317.36, 235.014, 5.94056, 600, 10, 0, 10635, 0, 1, 0, 0, 0),
(@GUID+26 , 29892, 571, 1, 256, 0, 0, 5606.09, -1331.94, 234.324, 1.26352, 600, 10, 0, 10635, 0, 1, 0, 0, 0),
(@GUID+27 , 29893, 571, 1, 256, 0, 0, 5853.59, -1697.84, 244.965, 2.67236, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+28 , 29893, 571, 1, 256, 0, 0, 5695.74, -2009.43, 244.807, 0.124677, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+29 , 29893, 571, 1, 256, 0, 0, 5572.47, -1652.34, 253.619, 4.17072, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+30 , 29893, 571, 1, 256, 0, 0, 5696.37, -1678.93, 251.9, 4.39571, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+31 , 29893, 571, 1, 256, 0, 0, 5631.35, -1681.11, 250.731, 1.85807, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+32 , 29893, 571, 1, 256, 0, 0, 5704.06, -1720.49, 251.043, 2.9409, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+33 , 29893, 571, 1, 256, 0, 0, 5778.87, -1719.28, 245.041, 3.77237, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+34 , 29893, 571, 1, 256, 0, 0, 5915.15, -1649.44, 240.979, 1.88691, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+35 , 29893, 571, 1, 256, 0, 0, 5569.31, -2202.47, 237.294, 4.03964, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+36 , 29893, 571, 1, 256, 0, 0, 5897.1, -1919.8, 247.544, 3.42085, 300, 5, 0, 10635, 3561, 0, 1, 0, 0),
(@GUID+37 , 29893, 571, 1, 256, 0, 0, 5689.67, -2208.27, 247.099, 0.162255, 300, 5, 0, 10635, 3561, 1, 0, 0, 0), 
(@GUID+38 , 29893, 571, 1, 256, 0, 0, 5713.66, -2105.41, 249.516, 5.98828, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+39 , 29893, 571, 1, 256, 0, 0, 5702.55, -1917.11, 253.197, 3.79182, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+40 , 29893, 571, 1, 256, 0, 0, 5690.33, -2185.8, 242.179, 2.57271, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+41 , 29893, 571, 1, 256, 0, 0, 5740.76, -1773.32, 245.511, 2.31348, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+42 , 29893, 571, 1, 256, 0, 0, 5614.24, -2037.16, 250.149, 1.40832, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+43 , 29893, 571, 1, 256, 0, 0, 5575.29, -2000.67, 248.223, 6.19776, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+44 , 29893, 571, 1, 256, 0, 0, 5677.27, -1851.13, 251.113, 3.90297, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+45 , 29893, 571, 1, 256, 0, 0, 5577.02, -2066.85, 250.604, 1.07166, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+46 , 29893, 571, 1, 256, 0, 0, 5571, -2199.84, 237.131, 2.6764, 300, 0, 5, 10635, 3561, 1, 0, 0, 0),
(@GUID+47 , 29893, 571, 1, 256, 0, 0, 5720.52, -2249.46, 248.994, 2.89725, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+48 , 29893, 571, 1, 256, 0, 0, 5572.56, -2191.33, 237.752, 4.12593, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+49 , 29893, 571, 1, 256, 0, 0, 5753.41, -1810.86, 250.933, 5.99866, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+50 , 29893, 571, 1, 256, 0, 0, 5618.3, -1752.46, 247.552, 1.09956, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+51 , 29893, 571, 1, 256, 0, 0, 5859.25, -1685.61, 245.065, 3.36587, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+52 , 29893, 571, 1, 256, 0, 0, 5775.25, -1814.98, 250.933, 5.39307, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+53 , 29893, 571, 1, 256, 0, 0, 5743.85, -1852.16, 254.482, 1.90241, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+54 , 29893, 571, 1, 256, 0, 0, 5587.08, -2148.03, 245.513, 6.16101, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+55 , 29893, 571, 1, 256, 0, 0, 5523.55, -2117.92, 247.714, 1.53589, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+56 , 29893, 571, 1, 256, 0, 0, 5565.29, -2073.18, 250.604, 2.82743, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+57 , 29893, 571, 1, 256, 0, 0, 5677.37, -2149.39, 246.073, 3.49066, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+58 , 29893, 571, 1, 256, 0, 0, 5648.6, -2249.16, 244.455, 4.83456, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+59 , 29893, 571, 1, 256, 0, 0, 5567.93, -1993.53, 248.223, 1.74533, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+60 , 29893, 571, 1, 256, 0, 0, 5675.13, -2209.69, 247.099, 3.05433, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+61 , 29893, 571, 1, 256, 0, 0, 5698.65, -2027.66, 249.799, 5.37561, 300, 5, 0, 10635, 3561, 1, 0, 0, 0),
(@GUID+62 , 29894, 571, 1, 256, 0, 0, 5665, -1415.25, 246.314, 5.39472, 600, 20, 0, 10282, 0, 1, 0, 0, 0),
(@GUID+63 , 29894, 571, 1, 256, 0, 0, 5752.15, -1436.29, 258.409, 5.41043, 600, 20, 0, 10282, 0, 1, 0, 0, 0),
(@GUID+64 , 29894, 571, 1, 256, 0, 0, 5761.66, -1565.35, 253.843, 5.16774, 600, 20, 0, 10282, 0, 1, 0, 0, 0),
(@GUID+65 , 29894, 571, 1, 256, 0, 0, 5506.99, -2078.6, 240.758, 3.26877, 600, 0, 0, 10282, 0, 1, 0, 0, 0),
(@GUID+66 , 29897, 571, 1, 256, 0, 0, 5800.41, -1949.86, 237.777, 0.0841148, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+67 , 29897, 571, 1, 256, 0, 0, 5809.66, -1961.18, 237.623, 2.90301, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+68 , 29897, 571, 1, 256, 0, 0, 5787.87, -1945.98, 237.981, 2.64831, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+69 , 29897, 571, 1, 256, 0, 0, 5849.52, -1938.72, 238.759, 2.37365, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+70 , 29897, 571, 1, 256, 0, 0, 5851.52, -1936.72, 238.759, 0, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+71 , 29897, 571, 1, 256, 0, 0, 5874.93, -1958.73, 237.907, 5.48033, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+72 , 29897, 571, 1, 256, 0, 0, 5876.93, -1956.73, 237.907, 0, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+73 , 29897, 571, 1, 256, 0, 0, 5784.08, -2089.96, 248.134, 4.30029, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+74 , 29897, 571, 1, 256, 0, 0, 5781.4, -2100.23, 248.13, 2.21899, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+75 , 29897, 571, 1, 256, 0, 0, 5806.27, -2085.21, 248.853, 1.87123, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+76 , 29897, 571, 1, 256, 0, 0, 5681.57, -1835.14, 239.37, 1.60886, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+77 , 29897, 571, 1, 256, 0, 0, 5676.56, -1831.26, 238.047, 3.34263, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+78 , 29897, 571, 1, 256, 0, 0, 5684.2, -1865.81, 245.472, 6.17889, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+79 , 29897, 571, 1, 256, 0, 0, 5757.26, -2150.57, 239.183, 1.30925, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+80 , 29897, 571, 1, 256, 0, 0, 5755.93, -2143.23, 239.517, 0.826811, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+81 , 29897, 571, 1, 256, 0, 0, 5758.19, -2165.01, 236.708, 0.435639, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+82 , 29897, 571, 1, 256, 0, 0, 5740.36, -1981.64, 239.12, 5.9877, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+83 , 29897, 571, 1, 256, 0, 0, 5744.67, -1988.91, 237.913, 2.8217, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+84 , 29897, 571, 1, 256, 0, 0, 5610.19, -1785.61, 237.507, 3.07515, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+85 , 29897, 571, 1, 256, 0, 0, 5618.3, -1764.02, 238.151, 1.66464, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+86 , 29897, 571, 1, 256, 0, 0, 5689.57, -1791.99, 242.42, 0.379977, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+87 , 29897, 571, 1, 256, 0, 0, 5695.83, -1804.17, 243.797, 5.64564, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+88 , 29897, 571, 1, 256, 0, 0, 5700.72, -1802.74, 243.412, 0.951114, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+89 , 29897, 571, 1, 256, 0, 0, 5817.31, -1985.64, 235.536, 0.737231, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+90 , 29897, 571, 1, 256, 0, 0, 5772.95, -1971.71, 238.367, 5.41063, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+91 , 29897, 571, 1, 256, 0, 0, 5781.42, -2002.12, 235.408, 4.67777, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+92 , 29897, 571, 1, 256, 0, 0, 5505.86, -1980.04, 245.708, 4.13413, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+93 , 29897, 571, 1, 256, 0, 0, 5715.38, -1850.36, 244.283, 5.24594, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+94 , 29897, 571, 1, 256, 0, 0, 5720.33, -1854.51, 244.441, 4.60288, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+95 , 29897, 571, 1, 256, 0, 0, 5707.95, -1840.12, 243.55, 3.37615, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+96 , 29897, 571, 1, 256, 0, 0, 5745.64, -2214.74, 237.548, 0.0771936, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+97 , 29897, 571, 1, 256, 0, 0, 5747.11, -2186.19, 235.212, 1.23232, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+98 , 29897, 571, 1, 256, 0, 0, 5753.6, -1818.86, 242.801, 5.70552, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+99 , 29897, 571, 1, 256, 0, 0, 5708.97, -1818.38, 242.586, 0.27079, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+100, 29897, 571, 1, 256, 0, 0, 5775.08, -1818.34, 241.528, 3.04571, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+101, 29897, 571, 1, 256, 0, 0, 5699.57, -1814.88, 243.044, 2.8075, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+102, 29897, 571, 1, 256, 0, 0, 5722.35, -1809.84, 242.035, 5.9219, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+103, 29897, 571, 1, 256, 0, 0, 5672.66, -1752.98, 242.189, 0.176776, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+104, 29897, 571, 1, 256, 0, 0, 5749.24, -1916.05, 236.765, 1.57848, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+105, 29897, 571, 1, 256, 0, 0, 5770.94, -1947.83, 238.676, 3.24534, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+106, 29897, 571, 1, 256, 0, 0, 5760.04, -1930.67, 236.939, 2.48637, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+107, 29897, 571, 1, 256, 0, 0, 5718.87, -1725.81, 241.258, 2.40457, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+108, 29897, 571, 1, 256, 0, 0, 5704.41, -1761.31, 238.276, 1.08268, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+109, 29897, 571, 1, 256, 0, 0, 5692.77, -1742.78, 241.834, 0.59012, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+110, 29897, 571, 1, 256, 0, 0, 5811.15, -1806.3, 239.144, 3.31613, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+111, 29897, 571, 1, 256, 0, 0, 5812.15, -1805.3, 239.144, 0, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+112, 29897, 571, 1, 256, 0, 0, 5813.15, -1804.3, 239.144, 0, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+113, 29897, 571, 1, 256, 0, 0, 5741.6, -1938.87, 239.001, 5.39812, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+114, 29897, 571, 1, 256, 0, 0, 5771.44, -1953.53, 238.606, 0.393825, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+115, 29897, 571, 1, 256, 0, 0, 5743.02, -1972.59, 238.874, 2.11055, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+116, 29897, 571, 1, 256, 0, 0, 5703.15, -1794.12, 242.065, 3.34446, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+117, 29897, 571, 1, 256, 0, 0, 5746.18, -1782.44, 235.463, 0.797146, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+118, 29897, 571, 1, 256, 0, 0, 5619.11, -1717.61, 238.613, 3.22571, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+119, 29897, 571, 1, 256, 0, 0, 5548.48, -2014.94, 241.625, 6.14212, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+120, 29897, 571, 1, 256, 0, 0, 5574.68, -2047.1, 241.07, 3.84426, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+121, 29897, 571, 1, 256, 0, 0, 5581.1, -2026.65, 240.496, 2.87268, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+122, 29897, 571, 1, 256, 0, 0, 5579.34, -2052.01, 242.07, 6.14826, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+123, 29897, 571, 1, 256, 0, 0, 5636.66, -2065.46, 239.827, 3.88282, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+124, 29897, 571, 1, 256, 0, 0, 5624.29, -2040.4, 242.369, 2.36517, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+125, 29897, 571, 1, 256, 0, 0, 5637.19, -2045.61, 240.353, 2.54655, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+126, 29897, 571, 1, 256, 0, 0, 5616.15, -2050.24, 240.595, 0.793553, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+127, 29897, 571, 1, 256, 0, 0, 5609.08, -2065.27, 240.629, 3.25117, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+128, 29897, 571, 1, 256, 0, 0, 5608.1, -2066.92, 240.892, 6.16573, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+129, 29897, 571, 1, 256, 0, 0, 5678.65, -2105.46, 235.457, 1.91448, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+130, 29897, 571, 1, 256, 0, 0, 5679.89, -2099.35, 235.438, 5.22669, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+131, 29897, 571, 1, 256, 0, 0, 5672.36, -2099.72, 236.885, 1.76984, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+132, 29897, 571, 1, 256, 0, 0, 5735.15, -1916.51, 238.14, 2.53114, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+133, 29897, 571, 1, 256, 0, 0, 5767.14, -1922.78, 236.386, 5.84969, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+134, 29897, 571, 1, 256, 0, 0, 5774.57, -1924.63, 236.931, 2.64557, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+135, 29897, 571, 1, 256, 0, 0, 5817.63, -1736.84, 234.032, 1.06323, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+136, 29897, 571, 1, 256, 0, 0, 5808.32, -1768.02, 237.835, 2.35965, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+137, 29897, 571, 1, 256, 0, 0, 5781.59, -1770.5, 237.636, 1.57177, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+138, 29897, 571, 1, 256, 0, 0, 5776.26, -1770.25, 237.259, 0.302035, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+139, 29897, 571, 1, 256, 0, 0, 5789.37, -1769.62, 237.983, 5.76186, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+140, 29897, 571, 1, 256, 0, 0, 5644.87, -1849.57, 238.036, 6.24801, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+141, 29897, 571, 1, 256, 0, 0, 5698.37, -1935.3, 244.483, 4.06009, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+142, 29897, 571, 1, 256, 0, 0, 5702.1, -1939.35, 245.179, 2.22602, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+143, 29897, 571, 1, 256, 0, 0, 5708.07, -1941.57, 245.273, 5.95941, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+144, 29897, 571, 1, 256, 0, 0, 5617.93, -1927.98, 238.178, 1.42268, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+145, 29897, 571, 1, 256, 0, 0, 5665.75, -1960.17, 246.384, 3.74366, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+146, 29897, 571, 1, 256, 0, 0, 5618.41, -1918.89, 236.543, 5.94885, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+147, 29897, 571, 1, 256, 0, 0, 5640.05, -1896.65, 237.268, 2.27912, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+148, 29897, 571, 1, 256, 0, 0, 5646.57, -2073.42, 239.16, 4.57035, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+149, 29897, 571, 1, 256, 0, 0, 5648.18, -2044.24, 240.082, 2.20481, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+150, 29897, 571, 1, 256, 0, 0, 5651.94, -2049.16, 239.93, 1.42876, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+151, 29897, 571, 1, 256, 0, 0, 5682.93, -1925.03, 240.591, 6.18927, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+152, 29897, 571, 1, 256, 0, 0, 5666.15, -1926.56, 236.313, 3.40826, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+153, 29897, 571, 1, 256, 0, 0, 5680.71, -1919.09, 240.538, 6.25585, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+154, 29897, 571, 1, 256, 0, 0, 5635.86, -1918.02, 236.563, 2.58564, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+155, 29897, 571, 1, 256, 0, 0, 5630.83, -1923.23, 236.676, 5.98849, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+156, 29897, 571, 1, 256, 0, 0, 5622.87, -1988.8, 242.277, 5.95495, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+157, 29897, 571, 1, 256, 0, 0, 5624.85, -1887.39, 238.361, 3.35814, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+158, 29897, 571, 1, 256, 0, 0, 5631.73, -1946.06, 240.503, 2.14675, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+159, 29897, 571, 1, 256, 0, 0, 5641.32, -1940.9, 237.796, 0, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+160, 29897, 571, 1, 256, 0, 0, 5642.32, -1939.9, 237.796, 0, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+161, 29897, 571, 1, 256, 0, 0, 5611.14, -1791.48, 237.011, 1.11064, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+162, 29897, 571, 1, 256, 0, 0, 5620.56, -1791.42, 235.489, 4.90098, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+163, 29897, 571, 1, 256, 0, 0, 5648.79, -1756.16, 238.444, 3.77298, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+164, 29897, 571, 1, 256, 0, 0, 5610.22, -1747.1, 238.102, 4.15958, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+165, 29897, 571, 1, 256, 0, 0, 5612.51, -1738.41, 237.053, 1.85177, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+166, 29897, 571, 1, 256, 0, 0, 5755, -1817.13, 242.671, 0, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+167, 29897, 571, 1, 256, 0, 0, 5756, -1816.13, 242.671, 0, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+168, 29897, 571, 1, 256, 0, 0, 5776.57, -1793.26, 236.417, 1.48353, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+169, 29897, 571, 1, 256, 0, 0, 5777.57, -1792.26, 236.417, 0, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+170, 29897, 571, 1, 256, 0, 0, 5778.57, -1791.26, 236.417, 0, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+171, 29897, 571, 1, 256, 0, 0, 5801.6, -1765.91, 238.43, 2.58309, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+172, 29897, 571, 1, 256, 0, 0, 5802.6, -1764.91, 238.43, 0, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+173, 29897, 571, 1, 256, 0, 0, 5803.6, -1763.91, 238.43, 0, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+174, 29897, 571, 1, 256, 0, 0, 5785.24, -1852.96, 237.379, 6.26573, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+175, 29897, 571, 1, 256, 0, 0, 5787.24, -1850.96, 237.379, 0, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+176, 29897, 571, 1, 256, 0, 0, 5742.22, -1871.72, 244.595, 5.06145, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+177, 29897, 571, 1, 256, 0, 0, 5744.22, -1869.72, 244.595, 0, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+178, 29897, 571, 1, 256, 0, 0, 5697.92, -2029.47, 240.357, 5.14872, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+179, 29897, 571, 1, 256, 0, 0, 5823.94, -1876.77, 235.48, 0, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+180, 29897, 571, 1, 256, 0, 0, 5824.94, -1875.77, 235.48, 0, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+181, 29897, 571, 1, 256, 0, 0, 5682.56, -1792.18, 241.997, 0.0174533, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+182, 29897, 571, 1, 256, 0, 0, 5683.56, -1791.18, 241.997, 0, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+183, 29897, 571, 1, 256, 0, 0, 5684.56, -1790.18, 241.997, 0, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+184, 29897, 571, 1, 256, 0, 0, 5761.16, -1965.01, 237.3, 0.628319, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+185, 29897, 571, 1, 256, 0, 0, 5762.16, -1964.01, 237.3, 0, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+186, 29897, 571, 1, 256, 0, 0, 5763.16, -1963.01, 237.3, 0, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+187, 29897, 571, 1, 256, 0, 0, 5852.36, -1944.45, 239.13, 2.12984, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+188, 29897, 571, 1, 256, 0, 0, 5602.24, -2077.07, 242.888, 5.5676, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+189, 29897, 571, 1, 256, 0, 0, 5603.24, -2076.07, 242.888, 0, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+190, 29897, 571, 1, 256, 0, 0, 5604.24, -2075.07, 242.888, 0, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+191, 29897, 571, 1, 256, 0, 0, 5606.16, -2054.38, 240.52, 0.733038, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+192, 29897, 571, 1, 256, 0, 0, 5608.16, -2052.38, 240.52, 0, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+193, 29897, 571, 1, 256, 0, 0, 5739.8, -1806.04, 240.445, 2.14916, 120, 0, 0, 10635, 3561, 0, 0, 0, 0),
(@GUID+194, 29934, 571, 1, 256, 0, 0, 5536.93, -2222.53, 235.536, 0.942478, 300, 0, 0, 106350, 17805, 0, 0, 0, 0),
(@GUID+195, 29935, 571, 1, 256, 0, 0, 5545.14, -2227.4, 236.246, 0.907571, 300, 0, 0, 106350, 17805, 0, 0, 0, 0),
(@GUID+196, 29939, 571, 1, 256, 0, 0, 5715.978, -1471.326, 233.7377, 5.707227, 120, 0, 0, 0, 1, 0, 0, 0, 0), 
(@GUID+197, 29939, 571, 1, 256, 0, 0, 5546.167, -1869.288, 238.3516, 2.426008, 120, 0, 0, 0, 1, 0, 0, 0, 0), 
(@GUID+198, 29939, 571, 1, 256, 0, 0, 5645.932, -1925.377, 236.6502, 4.118977, 120, 0, 0, 0, 1, 0, 0, 0, 0),
(@GUID+199, 29939, 571, 1, 256, 0, 0, 5587.249, -1965.734, 242.4379, 4.420742, 120, 0, 0, 0, 1, 0, 0, 0, 0), 
(@GUID+200, 29939, 571, 1, 256, 0, 0, 5505.981, -2078.141, 240.9521, 2.356194, 120, 0, 0, 0, 1, 0, 0, 0, 0),
(@GUID+201, 29939, 571, 1, 256, 0, 0, 5521.792, -2245.884, 236.2022, 3.036873, 120, 0, 0, 0, 1, 0, 0, 0, 0),
(@GUID+202, 29939, 571, 1, 256, 0, 0, 5793.679, -2095.737, 249.0007, 5.235988, 120, 0, 0, 0, 1, 0, 0, 0, 0),
(@GUID+203, 29939, 571, 1, 256, 0, 0, 6175.099, -2017.251, 245.3769, 1.099557, 120, 0, 0, 0, 1, 0, 0, 0, 0),
(@GUID+204, 29939, 571, 1, 256, 0, 0, 6210.14, -2071.388, 235.3288, 0.4347768, 120, 0, 0, 0, 1, 0, 0, 0, 0),
(@GUID+205, 29939, 571, 1, 256, 0, 0, 5505.981, -2078.141, 240.9521, 2.356194, 120, 0, 0, 0, 1, 0, 0, 0, 0),
(@GUID+206, 29939, 571, 1, 256, 0, 0, 5645.932, -1925.377, 236.6502, 4.118977, 120, 0, 0, 0, 1, 0, 0, 0, 0), 
(@GUID+207, 29939, 571, 1, 256, 0, 0, 5521.792, -2245.884, 236.2022, 3.036873, 120, 0, 0, 0, 1, 0, 0, 0, 0), 
(@GUID+208, 29939, 571, 1, 256, 0, 0, 5645.932, -1925.377, 236.6502, 4.118977, 120, 0, 0, 0, 1, 0, 0, 0, 0),
(@GUID+209, 29939, 571, 1, 256, 0, 0, 5521.792, -2245.884, 236.2022, 3.036873, 120, 0, 0, 0, 1, 0, 0, 0, 0);

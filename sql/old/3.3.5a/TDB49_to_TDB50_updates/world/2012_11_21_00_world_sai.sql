SET @GOGUID := 380; -- need 1 set by TDB
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=66 WHERE `item`=38303 AND `entry`=26620;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=67 WHERE `item`=38303 AND `entry`=26639;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=15 WHERE `item`=38303 AND `entry`=27431;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=47110;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9615 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,47110,0,0,31,0,3,26498,0,0,0,'','Spell Summon Drakuru''s Image targets Drakuru''s Bunny 01'),
(13,1,47110,0,1,31,0,3,26559,0,0,0,'','Spell Summon Drakuru''s Image targets Drakuru''s Bunny 02'),
(13,1,47110,0,2,31,0,3,26700,0,0,0,'','Spell Summon Drakuru''s Image targets Drakuru''s Bunny 03'),
(13,1,47110,0,3,31,0,3,26789,0,0,0,'','Spell Summon Drakuru''s Image targets Drakuru''s Bunny 04'),
(13,1,47110,0,4,31,0,3,28015,0,0,0,'','Spell Summon Drakuru''s Image targets Drakuru''s Bunny 05'),
(15,9615,1,0,0,8,0,11990,0,0,0,0,'','Drakuru - Show gossip option if player has rewarded quest 11990'),
(15,9615,1,0,0,8,0,12238,0,0,1,0,'','Drakuru - Show gossip option if player has not rewarded quest 12238'),
(15,9615,1,0,0,2,0,35797,1,1,1,0,'','Drakuru - Show gossip option if player has not item Drakuru''s Elixir');
DELETE FROM `smart_scripts` WHERE `entryorguid`=26423 AND `source_type`=0 AND `id` IN (2,3);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26498,26559,26700,26789) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26423,0,2,3,62,0,100,0,9615,1,0,0,85,50021,0,0,0,0,0,7,0,0,0,0,0,0,0,'Drakuru - On gossip option select - Invoker spellcast Replace Drakuru''s Elixir'),
(26423,0,3,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Drakuru - On gossip option select - Close gossip'),
(26498,0,0,0,8,0,100,0,47110,0,0,0,11,47117,0,0,0,0,0,7,0,0,0,0,0,0,0,'Drakuru''s Bunny 01 - On spellhit - Spellcast Script Cast Summon Image of Drakuru'),
(26559,0,0,0,8,0,100,0,47110,0,0,0,11,47149,0,0,0,0,0,7,0,0,0,0,0,0,0,'Drakuru''s Bunny 02 - On spellhit - Spellcast Script Cast Summon Image of Drakuru 02'),
(26700,0,0,0,8,0,100,0,47110,0,0,0,11,47316,0,0,0,0,0,7,0,0,0,0,0,0,0,'Drakuru''s Bunny 03 - On spellhit - Spellcast Script Cast Summon Image of Drakuru 03'),
(26789,0,0,0,8,0,100,0,47110,0,0,0,11,47405,0,0,0,0,0,7,0,0,0,0,0,0,0,'Drakuru''s Bunny 04 - On spellhit - Spellcast Script Cast Summon Image of Drakuru 04');
DELETE FROM `creature` WHERE `guid` IN (43494,43496,43498,43501); -- double spawned
DELETE FROM `gameobject` WHERE `guid`=364; -- double spawned
-- Creature Template update from sniff
UPDATE `creature_template` SET `faction_A`=14, `faction_H`=14, `speed_walk`=2, `speed_run`=0.992062, `unit_flags`=768, `equipment_id`=2481 WHERE `entry`=28498;
UPDATE `creature_template` SET `gossip_menu_id`=9707, `faction_A`=190, `faction_H`=190, `speed_walk`=2, `npcflag`=`npcflag`|1, `unit_flags`=33024 WHERE `entry`=28016;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (28015,28016,28492,28498);
-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=9707 AND `text_id`=13265;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(9707,13265);
DELETE FROM `creature_equip_template` WHERE `entry`=2481;
INSERT INTO `creature_equip_template` (`entry`,`itemEntry1`,`itemEntry2`,`itemEntry3`) VALUES
(2481,33475,0,0);
UPDATE `creature_model_info` SET `bounding_radius`=2.5, `combat_reach`=2.5 WHERE `modelid`=28122;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=51825;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,51825,0,0,31,0,3,28016,0,0,0,'','Spell Arthas Scourge Drakuru targets Drakuru');
-- Creature text insert from sniff
DELETE FROM `creature_text` WHERE `entry` IN (28016,28498);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(28016,0,0,'Ahh,  Back in Drak''Tharon at last!',12,0,100,71,0,14006,'Drakuru'),
(28016,1,0,'Drakuru casts his gaze down on Drak''Tharon Keep.',16,0,100,0,0,0,'Drakuru'),
(28016,2,0,'Ya done well, mon....',12,0,100,0,0,14007,'Drakuru'),
(28016,3,0,'Ya surpassed my greatest hopes.',12,0,100,0,0,14008,'Drakuru'),
(28016,4,0,'For your efforts, you be gettin'' da greatest of rewards....',12,0,100,0,0,14009,'Drakuru'),
(28016,5,0,'Revelation!',12,0,100,5,0,14010,'Drakuru'),
(28016,6,0,'Be still, friend, and behold da truth of things!',12,0,100,0,0,14011,'Drakuru'),
(28016,7,0,'Master, my mission be complete.',12,0,100,0,0,14012,'Drakuru'),
(28016,8,0,'With da help of these mortals, dis region been cleansed of all who oppose us.',12,0,100,0,0,14013,'Drakuru'),
(28016,9,0,'As you wish, master.',12,0,100,396,0,14014,'Drakuru'),
(28016,10,0,'Forgive my deception, mon. It all been for your own good.',12,0,100,396,0,14015,'Drakuru'),
(28016,11,0,'Ya needed ta prove yer worthiness....',12,0,100,396,0,14016,'Drakuru'),
(28016,12,0,'I be needin'' worthy underlings in Zul''Drak, mon. Ones ready to wield real power.',12,0,100,396,0,14017,'Drakuru'),
(28016,13,0,'You see for yourself now. Da Lich King be generous to dem who obey.',12,0,100,396,0,14018,'Drakuru'),
(28016,14,0,'Follow dis path, mon, and soon you be tastin'' immortality!',12,0,100,396,0,14019,'Drakuru'),
(28498,0,0,'You have done well, Drakuru.',12,0,100,396,0,14749,'The Lich King'),
(28498,1,0,'Your betrayal of the Drakkari Empire has borne me a new army.',12,0,100,396,0,14750,'The Lich King'),
(28498,2,0,'Your army....',12,0,100,0,0,14751,'The Lich King'),
(28498,3,0,'Arise, and accept my gift.',12,0,100,396,0,14752,'The Lich King'),
(28498,4,0,'I charge you now with the cleansing of Zul''Drak, Drakuru.',12,0,100,397,0,14753,'The Lich King'),
(28498,5,0,'Fail me and it shall be your undoing...',12,0,100,396,0,14754,'The Lich King'),
(28498,6,0,'Succeed, and even greater power shall be yours!',12,0,100,396,0,14755,'The Lich King');
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (28015,28016,28498,-127497,-127496,-127495,-127493) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (28492*100,28016*100,28016*100+1,28498*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28015,0,0,0,8,0,100,0,47110,0,0,0,11,50439,0,0,0,0,0,7,0,0,0,0,0,0,0,'Drakuru''s Bunny 05 - On spellhit - Spellcast Script Cast Summon Image of Drakuru 05'),
(28016,0,0,0,54,0,100,0,0,0,0,0,80,28016*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,'Drakuru - On update - Run script'),
(28016,0,1,2,40,0,100,0,1,0,0,0,54,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drakuru - On WP 1 - Pause movement 2 seconds'),
(28016,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,'Drakuru - On WP 1 - Say line'),
(28016,0,3,4,40,0,100,0,5,0,0,0,54,8000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drakuru - On WP 5 - Pause movement 8 seconds'),
(28016,0,4,5,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,'Drakuru - On WP 5 - Say line'),
(28016,0,5,0,61,0,100,0,0,0,0,0,80,28016*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Drakuru - On WP 5 - Run script'),
(28016,0,6,7,40,0,100,0,8,0,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drakuru - On WP 8 - Pause movement 4 seconds'),
(28016,0,7,8,61,0,100,0,0,0,0,0,1,3,0,0,0,0,0,23,0,0,0,0,0,0,0,'Drakuru - On WP 8 - Say line'),
(28016,0,8,0,61,0,100,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drakuru - On WP 8 - Set unit_field_bytes1'),
(28016,0,9,10,40,0,100,0,9,0,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drakuru - On WP 9 - Pause movement 4 seconds'),
(28016,0,10,0,61,0,100,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drakuru - On WP 9 - Set unit_field_bytes1'),
(28016,0,11,12,40,0,100,0,10,0,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drakuru - On WP 10 - Pause movement 3 seconds'),
(28016,0,12,13,61,0,100,0,0,0,0,0,1,4,0,0,0,0,0,23,0,0,0,0,0,0,0,'Drakuru - On WP 10 - Say line'),
(28016,0,13,0,61,0,100,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drakuru - On WP 10 - Set unit_field_bytes1'),
(28016,0,14,15,40,0,100,0,12,0,0,0,55,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drakuru - On WP 12 - Stop movement'),
(28016,0,15,16,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.694936,'Drakuru - On WP 12 - Set orientation'),
(28016,0,16,0,61,0,100,0,0,0,0,0,1,5,0,0,0,0,0,23,0,0,0,0,0,0,0,'Drakuru - On WP 12 - Say line'),
(28016,0,18,0,8,0,100,0,51825,0,0,0,11,51834,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drakuru - On spellhit Arthas Scourge Drakuru - Spellcast Drakuru Transform'),
(28498,0,0,0,54,0,100,0,0,0,0,0,53,0,28498,0,0,0,0,1,0,0,0,0,0,0,0,'The Lich King - Just summoned - Start WP movement'),
(28498,0,1,2,40,0,100,0,2,0,0,0,54,83000,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Lich King - On WP 2 - Pause movement 83 seconds'),
(28498,0,2,0,61,0,100,0,0,0,0,0,80,28498*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'The Lich King - On WP 2 - Run script'),
(28498,0,3,4,40,0,100,0,3,0,0,0,45,0,2,0,0,0,0,10,127495,0,0,0,0,0,0,'The Lich King - On WP 3 - Despawn'),
(28498,0,4,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Lich King - On WP 3 - Despawn'),
(-127497,0,0,1,38,0,100,0,0,1,0,0,11,51802,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drak''Tharon - Drakuru Event Invisman 00 - On data 0 1 - Spellcast Red Lightning Bolt'),
(-127497,0,1,0,61,0,100,0,0,0,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drak''Tharon - Drakuru Event Invisman 00 - On data 0 1 - Set data 0 0'),
(-127496,0,0,1,38,0,100,0,0,1,0,0,11,51802,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drak''Tharon - Drakuru Event Invisman 00 - On data 0 1 - Spellcast Red Lightning Bolt'),
(-127496,0,1,0,61,0,100,0,0,0,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drak''Tharon - Drakuru Event Invisman 00 - On data 0 1 - Set data 0 0'),
(-127493,0,0,1,38,0,100,0,0,1,0,0,11,51802,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drak''Tharon - Drakuru Event Invisman 00 - On data 0 1 - Spellcast Red Lightning Bolt'),
(-127493,0,1,0,61,0,100,0,0,0,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drak''Tharon - Drakuru Event Invisman 00 - On data 0 1 - Set data 0 0'),
(-127495,0,0,0,38,0,100,0,0,1,0,0,11,51807,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drak''Tharon - Drakuru Event Invisman 00 - On data 0 1 - Spellcast Arthas Portal'),
(-127495,0,1,2,38,0,100,0,0,2,0,0,80,28492*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Drak''Tharon - Drakuru Event Invisman 00 - On data 0 2 set - Start script'),
(-127495,0,2,0,61,0,100,0,0,0,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drak''Tharon - Drakuru Event Invisman 00 - On data 0 2 set - Set data 0 0'),
(28016*100,9,0,0,0,0,100,0,6000,6000,0,0,5,21,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drakuru script - Play emote applaud'),
(28016*100,9,1,0,0,0,100,0,2000,2000,0,0,1,2,0,0,0,0,0,23,0,0,0,0,0,0,0,'Drakuru script - Say line'),
(28016*100,9,2,0,0,0,100,0,6500,6500,0,0,50,190597,22.5,0,0,0,0,8,0,0,0,-241.5434,-675.4514,132.2164,-1.029743,'Drakuru script - Summon gameobject'),
(28016*100,9,3,0,0,0,100,0,6000,6000,0,0,50,190596,15.5,0,0,0,0,8,0,0,0,-235.8484,-680.4561,131.885,-2.792518,'Drakuru script - Summon gameobject'),
(28016*100,9,4,0,0,0,100,0,5000,5000,0,0,50,190595,11,0,0,0,0,8,0,0,0,-233.977,-673.1368,132.0999,0.7853968,'Drakuru script - Summon gameobject'),
(28016*100,9,5,0,0,0,100,0,6000,6000,0,0,11,51795,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drakuru script - Spellcast Shadow Channelling (10 sec)'),
(28016*100,9,6,0,0,0,100,0,5000,5000,0,0,45,0,1,0,0,0,0,10,127497,0,0,0,0,0,0,'Drakuru script - Set data 0 1'),
(28016*100,9,7,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,127496,0,0,0,0,0,0,'Drakuru script - Set data 0 1'),
(28016*100,9,8,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,127493,0,0,0,0,0,0,'Drakuru script - Set data 0 1'),
(28016*100,9,9,0,0,0,100,0,4000,4000,0,0,45,0,1,0,0,0,0,10,127495,0,0,0,0,0,0,'Drakuru script - Set data 0 1'),
(28016*100,9,10,0,0,0,100,0,1000,1000,0,0,1,6,0,0,0,0,0,23,0,0,0,0,0,0,0,'Drakuru script - Say line'),
(28016*100,9,11,0,0,0,100,0,5000,5000,0,0,12,28498,8,0,0,0,0,8,0,0,0,-237.1671,-702.1379,128.8857,1.570796,'Drakuru script - Summon Lich King'),
(28016*100,9,12,0,0,0,100,0,4000,4000,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drakuru script - Set unit_field_bytes1'),
(28016*100,9,13,0,0,0,100,0,2000,2000,0,0,1,7,0,0,0,0,0,23,0,0,0,0,0,0,0,'Drakuru script - Say line'),
(28016*100,9,14,0,0,0,100,0,6000,6000,0,0,1,8,0,0,0,0,0,23,0,0,0,0,0,0,0,'Drakuru script - Say line'),
(28016*100,9,15,0,0,0,100,0,33000,33000,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drakuru script - Remove unit_field_bytes1'),
(28016*100,9,16,0,0,0,100,0,6000,6000,0,0,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drakuru script - Play emote roar'),
(28016*100,9,17,0,0,0,100,0,0,0,0,0,4,3326,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drakuru script - Play sound roar'),
(28016*100,9,18,0,0,0,100,0,12000,12000,0,0,1,9,0,0,0,0,0,23,0,0,0,0,0,0,0,'Drakuru script - Say line'),
(28016*100,9,19,0,0,0,100,0,27000,27000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.70526,'Drakuru script - Set orientation'),
(28016*100,9,20,0,0,0,100,0,7000,7000,0,0,1,10,0,0,0,0,0,23,0,0,0,0,0,0,0,'Drakuru script - Say line'),
(28016*100,9,21,0,0,0,100,0,8000,8000,0,0,1,11,0,0,0,0,0,23,0,0,0,0,0,0,0,'Drakuru script - Say line'),
(28016*100,9,22,0,0,0,100,0,8000,8000,0,0,1,12,0,0,0,0,0,23,0,0,0,0,0,0,0,'Drakuru script - Say line'),
(28016*100,9,23,0,0,0,100,0,11000,11000,0,0,1,13,0,0,0,0,0,23,0,0,0,0,0,0,0,'Drakuru script - Say line'),
(28016*100,9,24,0,0,0,100,0,7000,7000,0,0,1,14,0,0,0,0,0,23,0,0,0,0,0,0,0,'Drakuru script - Say line'),
(28016*100,9,25,0,0,0,100,0,0,0,0,0,81,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drakuru script - Set npcflag'),
(28016*100+1,9,0,0,0,0,100,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drakuru script - Remove npcflag'),
(28016*100+1,9,1,0,0,0,100,0,3000,3000,0,0,53,0,28016,0,0,0,0,1,0,0,0,0,0,0,0,'Drakuru script - Start WP movement'),
(28492*100,9,0,0,0,0,100,0,5000,5000,0,0,28,51807,0,0,0,0,0,1,0,0,0,0,0,0,0,'Drak''Tharon - Drakuru Event Invisman 00 script - Remove aura Arthas Portal'),
(28498*100,9,0,0,0,0,100,0,15000,15000,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,'The Lich King script - Say line'),
(28498*100,9,1,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,'The Lich King script - Say line'),
(28498*100,9,2,0,0,0,100,0,10000,10000,0,0,1,2,0,0,0,0,0,23,0,0,0,0,0,0,0,'The Lich King script - Say line'),
(28498*100,9,3,0,0,0,100,0,6000,6000,0,0,1,3,0,0,0,0,0,23,0,0,0,0,0,0,0,'The Lich King script - Say line'),
(28498*100,9,4,0,0,0,100,0,5000,5000,0,0,11,51825,0,0,0,0,0,9,28016,0,10,0,0,0,0,'The Lich King script - Spellcast Arthas Scourge Drakuru'),
(28498*100,9,5,0,0,0,100,0,8000,8000,0,0,1,4,0,0,0,0,0,23,0,0,0,0,0,0,0,'The Lich King script - Say line'),
(28498*100,9,6,0,0,0,100,0,16000,16000,0,0,1,5,0,0,0,0,0,23,0,0,0,0,0,0,0,'The Lich King script - Say line'),
(28498*100,9,7,0,0,0,100,0,6000,6000,0,0,1,6,0,0,0,0,0,23,0,0,0,0,0,0,0,'The Lich King script - Say line');
DELETE FROM `creature_template_addon` WHERE `entry` IN (28016,28498);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(28016,0,0,0,1,0,''),
(28498,0,0,0,1,0,'');
DELETE FROM `spell_scripts` WHERE `id`=50439;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(50439,0,0,15,50440,2,0,0,0,0,0); -- Script Cast Summon Image of Drakuru - Spellcast Envision Drakuru
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=50440;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(50440,50446,1,'On Envision Drakuru - Spellcast Summon Drakuru');
DELETE FROM `waypoints` WHERE `entry` IN (28016,28498);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(28016, 1,-240.1569,-630.3474,116.4973,'pause and text'),
(28016, 2,-237.9522,-652.9613,131.131,''),
(28016, 3,-252.4211,-663.5404,131.2025,''),
(28016, 4,-261.2747,-667.5787,131.1916,''),
(28016, 5,-264.9144,-667.5964,131.1769,'pause and text'),
(28016, 6,-258.2646,-669.388,131.1983,''),
(28016, 7,-248.6646,-674.2229,132.1737,''),
(28016, 8,-243.7752,-674.9374,131.8365,'pause'),
(28016, 9,-236.3793,-678.6719,131.8578,'pause'),
(28016,10,-235.4743,-674.3039,131.8569,'pause'),
(28016,11,-234.869,-674.1355,131.8544,''),
(28016,12,-237.0977,-676.1853,131.8683,''),
(28498,1,-237.4704,-689.8357,129.5296,''),
(28498,2,-237.2737,-686.5334,132.1735,'pause'),
(28498,3,-237.0624,-700.3822,130.4357,'');
DELETE FROM `gameobject` WHERE `guid`=@GOGUID;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@GOGUID,300188,600,3,1,-236.766,-614.774,116.487,1.5708,0,0,0,1,180,0,1);

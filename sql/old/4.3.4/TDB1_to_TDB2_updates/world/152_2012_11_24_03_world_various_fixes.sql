-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 1421: Morridune is hostile for Alliance.
-- Morridune data from sniffs
-- Same values
-- UPDATE `creature_template` SET `gossip_menu_id`=321, `faction_A`=80, `faction_H`=80, `npcflag`=1, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=6729; 
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 1426: Attack on Camp Narache
UPDATE `quest_template` SET `OfferRewardText`='This is quite alarming indeed! But with this information we can call on our brethren from Bloodhoof Village to help thwart the attack. You have saved the lives of many $r, $N.', `RequestItemsText`='You have a look of concern about you,$N. What news do you bring?',`RequiredRaces`=690 WHERE `Id`=24857;
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 1518: Eramas Brightblaze's attack type
-- Set proper damage school type for Eramas Brightblaze
UPDATE `creature_template` SET `dmgschool`=0 WHERE `entry` IN (24554,25550);
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 1520: Banish the Demons
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (19973,22327,22201,22195,22204,22392,20557,22291,23322);
UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry` IN (19973,22327,22201,22195,22204,22392,20557,22291,23322);
UPDATE `creature_template` SET `flags_extra`=130, `unit_flags`=33554432 WHERE `entry` IN (23322,23327);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19973,22327,22201,22195,22204,22392,20557,22291,23322);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19973,0,0,0,8,0,100,1,40825,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spell hit - Set phase 1'),
(19973,0,1,0,6,1,100,0,0,0,0,0,33,23327,0,0,0,0,0,16,0,0,0,0,0,0,0, 'On death in phase 1 - give quest credit'),
(20557,0,0,0,8,0,100,1,40825,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spell hit - Set phase 1'),
(20557,0,1,0,6,1,100,0,0,0,0,0,33,23327,0,0,0,0,0,16,0,0,0,0,0,0,0, 'On death in phase 1 - give quest credit'),
(20557,0,2,0,4,0,100,0,0,0,0,0,11,22911,0,0,0,0,0,2,0,0,0,0,0,0,0, 'On aggro - cast charge'),
(20557,0,3,0,0,0,100,0,5000,11000,20000,27000,11,36406,0,0,0,0,0,2,0,0,0,0,0,0,0,'In combat - cast breath'),
(22195,0,0,0,8,0,100,1,40825,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spell hit - Set phase 1'),
(22195,0,1,0,6,1,100,0,0,0,0,0,33,23327,0,0,0,0,0,16,0,0,0,0,0,0,0, 'On death in phase 1 - give quest credit'),
(22195,0,2,0,0,0,75,0,2500,7500,14000,18000,11,34017,0,0,0,0,0,2,0,0,0,0,0,0,0, 'In combat - cast rain of chaos'),
(22195,0,3,0,0,0,100,0,10100,14100,122000,130000,11,11980,0,0,0,0,0,5,0,0,0,0,0,0,0, 'In combat - cast curse of weakness'),
(22201,0,0,0,8,0,100,1,40825,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spell hit - Set phase 1'),
(22201,0,1,0,6,1,100,0,0,0,0,0,33,23327,0,0,0,0,0,16,0,0,0,0,0,0,0, 'On death in phase 1 - give quest credit'),
(22204,0,0,0,8,0,100,1,40825,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spell hit - Set phase 1'),
(22204,0,1,0,6,1,100,0,0,0,0,0,33,23327,0,0,0,0,0,16,0,0,0,0,0,0,0, 'On death in phase 1 - give quest credit'),
(22291,0,0,0,8,0,100,1,40825,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spell hit - Set phase 1'),
(22291,0,1,0,6,1,100,0,0,0,0,0,33,23327,0,0,0,0,0,16,0,0,0,0,0,0,0, 'On death in phase 1 - give quest credit'),
(22291,0,2,0,0,0,100,0,6300,12800,6300,12800,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0, 'In combat - cast mortal strike'),
(22327,0,0,0,8,0,100,1,40825,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spell hit - Set phase 1'),
(22327,0,1,0,6,1,100,0,0,0,0,0,33,23327,0,0,0,0,0,16,0,0,0,0,0,0,0, 'On death in phase 1 - give quest credit'),
(22392,0,0,0,8,0,100,1,40825,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spell hit - Set phase 1'),
(22392,0,1,0,6,1,100,0,0,0,0,0,33,23327,0,0,0,0,0,16,0,0,0,0,0,0,0, 'On death in phase 1 - give quest credit'),
(23322,0,0,1,54,0,100,0,0,0,0,0,11,40849,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spawn - cast portal'),
(23322,0,1,0,61,0,100,0,0,0,0,0,11,40857,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Link with 0 - cast aura');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 1843: Old Crystalbark
-- UPDATE `creature_template` SET `faction_A`=16,`faction_H`=16 WHERE `entry`=32357;
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 1881: The Honored Dead
SET @GUARD := 25342;
SET @WORKER := 25343;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=45474 AND `ConditionTypeOrReference`=36;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@GUARD,@WORKER) AND `id` IN (2,3);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUARD,0,2,3,8,0,100,0,45474,0,0,0,33,@GUARD,0,0,0,0,0,7,0,0,0,0,0,0,0,'Dead Caravan Guard - On Spellhit - Give Quest Credit'),
(@GUARD,0,3,0,61,0,100,0,0,0,0,0,41,500,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dead Caravan Guard - On Spellhit - Despawn'),
(@WORKER,0,2,3,8,0,100,0,45474,0,0,0,33,@GUARD,0,0,0,0,0,7,0,0,0,0,0,0,0,'Dead Caravan Worker - On Spellhit - Give Quest Credit'),
(@WORKER,0,3,0,61,0,100,0,0,0,0,0,41,500,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dead Caravan Worker - On Spellhit - Despawn');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 2075: Bring Down Those Shields
UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry`=24464;
DELETE FROM `smart_scripts` WHERE `entryorguid` =24464 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24464,0,1,0,8,0,100,0,50133,0,0,0,28,43874,3,0,0,0,0,1,0,0,0,0,0,0,0,'Scourging Crystal - On Spellhit Scourging Crystal Controller - Remove Scourge Mur''gul Camp: Force Shield Arcane Purple x3 on self');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 2077 
SET @OGUID := 198; -- 4.x guid
DELETE FROM gameobject WHERE id IN (190284,190283,186814,186813);
INSERT INTO gameobject (guid,id,map,spawnMask,phaseMask,position_x,position_y,position_z,orientation,rotation0,rotation1,rotation2,rotation3,spawntimesecs,animprogress,state) VALUES
(@OGUID,190284,571,1,1,1595.69,-3905.33,79.7439,0.610864,0,0,0,0,5,0,1),
(@OGUID+1,190283,571,1,1,1597.4,-3903.79,79.702,0,0,0,0,0,60,100,1),
(@OGUID+2,186814,571,1,1,1597.4,-3903.79,79.702,0,0,0,0,0,60,100,1),
(@OGUID+3,186813,571,1,1,1596.3,-3904.79,79.5351,-2.67035,0,0,0,0,5,0,1);
-- SmartAI for nest and creature
UPDATE creature_template SET AIName='SmartAI' WHERE entry=24518;
UPDATE gameobject_template SET AIName='SmartGameObjectAI' WHERE `entry` IN (186814,190283);
DELETE FROM `smart_scripts` WHERE `entryorguid`=24518 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (186814,190283) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Talonshrike
(24518,0,0,0,38,0,100,0,0,1,0,0,69,0,0,0,0,0,0,8,0,0,0,1597.4,-3903.79,79.702,0.0,'Talonshrike - On notification  - fly to nest'),
(24518,0,1,0,0,0,100,0,5000,5000,10000,12000,11,49865,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,' Talonshrike - In Combat - 5 seconds - Cast Eye Peck'),
(24518,0,2,0,0,0,100,0,3000,3000,5000,7000,11,32909,0,0,0,0,0,2,0,0,0,0.0,0.0,0.0,0.0,' Talonshrike - In Combat - 3 seonds - Cast Talon Strike'),
-- Talonshrike's Egg
(186814,1,0,0,70,0,100,0,2,0,0,0,45,0,1,0,0,0,0,11,24518,500,0,0.0,0.0,0.0,0.0,'Talonshrikes Egg - On use - Notify Talonshrike'),
(190283,1,0,0,70,0,100,0,2,0,0,0,45,0,1,0,0,0,0,11,24518,500,0,0.0,0.0,0.0,0.0,'Talonshrikes Egg - On use - Notify Talonshrike');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 2324: Battered Hilt
SET @HC5MANREF=35073;
-- Update loot ids for(Ymirjar Deathbringer,Ymirjar Flamebearer,Ymirjar Skycaller,Ymirjar Wrathbringer,Stonespine Gargoyle) - Same as other ICC 5man hc trash
UPDATE `creature_template` SET `lootid`=100001 WHERE `entry` IN (37641,37642,37643,37644,37622);
DELETE FROM `creature_loot_template` WHERE `entry` IN (37641,37642,37643,37644,37622);
-- Add new ref to ICC 5man hc Trash Ref (0.08 percent is average of values on wowhead 4.16/52)
DELETE FROM `reference_loot_template` WHERE `entry`=@HC5MANREF AND `item` IN(50379,50380);
INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(@HC5MANREF,50379,0.08,1,0,1,1), -- Alliance Battered Hilt
(@HC5MANREF,50380,0.08,1,0,1,1); -- Horde Battered Hilt
-- Conditions for Batterd hilt drop
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=10 AND `SourceGroup`=@HC5MANREF;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(10,@HC5MANREF,50379,0,0,6,0,469,0,0,0,0, '', 'Battered Hilt Must Be Alliance'),
(10,@HC5MANREF,50380,0,0,6,0,67, 0,0,0,0, '', 'Battered Hilt Must Be Horde');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 4363: Crashin' Thrashin' Racer
UPDATE `creature_template` SET `spell1`=49297 WHERE `entry` IN (27664,40281);
UPDATE `creature_template_addon` SET `auras`='49384' WHERE `entry`=27664;
UPDATE `creature_template_addon` SET `auras`='75110' WHERE `entry`=40281;
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 5320: Fields of Grief
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=375;
DELETE FROM `smart_scripts` WHERE `entryorguid`=375 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(375,1,0,0,70,0,100,0,2,0,0,0,70,120,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Tirisfal Pumpkin - On Use - Respawn/restock after 120s');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 8408: ICC Trash Mobs Damage
-- Mobs before Sindragosa
UPDATE `creature_template` SET `mindmg`=422, `maxdmg`=586, `attackpower`=642, `dmg_multiplier`=10 WHERE `entry`=37532;
UPDATE `creature_template` SET `mindmg`=422, `maxdmg`=586, `attackpower`=642, `dmg_multiplier`=25 WHERE `entry`=37531;
UPDATE `creature_template` SET `mindmg`=422, `maxdmg`=586, `attackpower`=642, `dmg_multiplier`=20 WHERE `entry`=38151;
UPDATE `creature_template` SET `mindmg`=422, `maxdmg`=586, `attackpower`=642, `dmg_multiplier`=50 WHERE `entry`=38139;
-- Mobs before Dreamwalker
UPDATE `creature_template` SET `dmg_multiplier`=25 WHERE `entry` IN (37133,37134,38125,37132);
UPDATE `creature_template` SET `dmg_multiplier`=50 WHERE `entry` IN (38130,38131,38132,38133);
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 8401: Anatoly will talk
SET @SASHA := 26935;
SET @ANATOLY := 26971;
SET @HORSE := 27626;
SET @TATJANA := 27627;
SET @SPELL_SHOOT := 48815;
SET @SPELL_DART := 49134;
SET @SPELL_PING := 49135;
SET @SPELL_MOUNT_HORSE := 49138;
DELETE FROM `creature` WHERE `guid` IN (118152,118160);
DELETE FROM `creature_text` WHERE `entry` IN (@SASHA,@ANATOLY);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@SASHA,0,0,'I''m old enough to shoot beasts like you right between the eyes... at twice this distance.',12,0,100,0,0,0,'Sasha'),
(@SASHA,1,0,'Don''t you dare talk about my father, monster. He was twice the man you''ll ever be.',12,0,100,0,0,0,'Sasha'),
(@SASHA,2,0,'I''d rather be dead than be one of you! You think you''re still human? You''re... animals!',12,0,100,0,0,0,'Sasha'),
(@SASHA,3,0,'Surprise, you scum!  You''re going to tell me where my sister is or I''ll put a bucketful of truesilver bullets through your wife''s heart.',12,0,100,0,0,0,'Sasha'),
(@SASHA,4,0,'Where is Anya?',12,0,100,0,0,0,'Sasha'),
(@SASHA,5,0,'There is one last thing.  I need to know where Arugal is.',12,0,100,0,0,0,'Sasha'),
(@ANATOLY,0,0,'How old are you, lass?',12,0,100,0,0,0,'Anatoly'),
(@ANATOLY,1,0,'You won''t get away with this, you know? You''re just a kid.',12,0,100,0,0,0,'Anatoly'),
(@ANATOLY,2,0,'Your father was weak, Sasha... he didn''t have the guts to do what had to be done.',12,0,100,0,0,0,'Anatoly'),
(@ANATOLY,3,0,'We''ll all end up serving the Lich King, kid. Better this way than becoming a rotten corpse.',12,0,100,0,0,0,'Anatoly'),
(@ANATOLY,4,0,'Stop!  Do not shoot!  Do not hurt Tatjana!',12,0,100,0,0,0,'Anatoly'),
(@ANATOLY,5,0,'The brat''s held prisoner in the wolf den on the other side of the mountain.  She was to be taken to Arugal.  Are we free to go now?',12,0,100,0,0,0,'Anatoly'),
(@ANATOLY,6,0,'Forgive me, Tatjana... ',12,0,100,0,0,0,'Anatoly'),
(@ANATOLY,7,0,'Nothing you can do can compare to what Arugal can do to us!  I will tear you apart myself!',12,0,100,0,0,0,'Anatoly');
DELETE FROM `vehicle_template_accessory` WHERE `entry`=@HORSE;
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`) VALUES
(@HORSE,@TATJANA,0,0,'Tatjana''s Horse',8,30000);
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=@HORSE;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(@HORSE,@SPELL_MOUNT_HORSE,1,0);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (@SPELL_DART,@SPELL_PING);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=@SPELL_SHOOT;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,@SPELL_SHOOT,0,0,31,0,3,@ANATOLY,0,0,0,'','Spell Shoot targets Anatoly'),
(13,1,@SPELL_DART,0,0,31,0,3,@TATJANA,0,0,0,'','Spell Tranquilizer Dart targets Tatjana'),
(13,1,@SPELL_PING,0,0,31,0,3,@HORSE,0,0,0,'','Spell Tatjana Ping effect0 targets Tatjana''s Horse');
UPDATE `creature` SET `spawntimesecs`=60 WHERE `id`=@ANATOLY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@SASHA,@ANATOLY,@TATJANA);
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@TATJANA;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@HORSE;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@SASHA,@ANATOLY,@HORSE,@TATJANA) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@SASHA*100,@ANATOLY*100,@ANATOLY*100+1,@ANATOLY*100+2,@ANATOLY*100+3,@ANATOLY*100+4,@HORSE*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@SASHA,0,0,3,38,1,100,0,0,1,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sasha - On data set 0 1 (phase 1) - Say line'),
(@SASHA,0,1,3,38,1,100,0,0,2,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sasha - On data set 0 2 (phase 1) - Say line'),
(@SASHA,0,2,3,38,1,100,0,0,3,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sasha - On data set 0 3 (phase 1) - Say line'),
(@SASHA,0,3,0,61,1,100,0,0,0,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - Linked with events 0,1,2 (phase 1) - Set data 0 0'),
(@SASHA,0,4,5,38,0,100,0,0,4,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - On data set 0 4 - Set event phase 0'),
(@SASHA,0,5,0,61,0,100,0,0,0,0,0,80,@SASHA*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - On data set 0 4 - Run script'),
(@SASHA,0,6,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - On reset - Set event phase 1'),
(@ANATOLY,0,0,0,1,1,100,0,10000,20000,45000,60000,87,@ANATOLY*100+1,@ANATOLY*100+2,@ANATOLY*100+3,@ANATOLY*100+4,0,0,1,0,0,0,0,0,0,0,'Anatoly - On update OOC (phase 1) - Run random script'),
(@ANATOLY,0,1,2,38,0,100,0,0,1,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly - On data set 0 1 - Set event phase 0'),
(@ANATOLY,0,2,3,61,0,100,0,0,1,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly - On data set 0 1 - Set run'),
(@ANATOLY,0,3,0,61,0,100,0,0,0,0,0,69,1,0,0,0,0,0,8,0,0,0,4057.442,-4140.824,211.1911,0,'Anatoly - On data set 0 1 - Move to position'),
(@ANATOLY,0,4,5,34,0,100,0,0,1,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly - On movement inform - Set unit_field_bytes1 (kneel)'),
(@ANATOLY,0,5,0,61,0,100,0,0,0,0,0,80,@ANATOLY*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly - On movement inform - Run script'),
(@ANATOLY,0,6,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly - On reset - Set event phase 1'),
(@HORSE,0,0,0,11,0,100,0,0,0,0,0,28,@SPELL_MOUNT_HORSE,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tatjana''s Horse - On spawn - Remove aura Mount Tatjana''s Horse'),
(@HORSE,0,1,2,8,0,100,0,@SPELL_PING,0,0,0,2,1812,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tatjana''s Horse - On spellhit Tatjana Ping - Set faction'),
(@HORSE,0,2,3,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tatjana''s Horse - On spellhit Tatjana Ping - Stop autoattack'),
(@HORSE,0,3,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tatjana''s Horse - On spellhit Tatjana Ping - Set eventphase 1'),
(@HORSE,0,4,0,8,1,100,0,@SPELL_MOUNT_HORSE,0,0,0,80,@HORSE*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Tatjana''s Horse - On spellhit Mount Tatjana''s Horse (phase 1) - Run script'),
(@HORSE,0,5,6,40,0,100,0,19,0,0,0,28,@SPELL_MOUNT_HORSE,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tatjana''s Horse - On WP 19 reached - Remove aura Mount Tatjana''s Horse'),
(@HORSE,0,6,7,61,0,100,0,0,0,0,0,15,12330,0,0,0,0,0,21,2,0,0,0,0,0,0,'Tatjana''s Horse - On WP 19 reached - Quest credit'),
(@HORSE,0,7,8,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,9,@ANATOLY,0,30,0,0,0,0,'Tatjana''s Horse - On WP 19 reached - Set data 0 1'),
(@HORSE,0,8,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tatjana''s Horse - On WP 19 reached - Despawn'),
(@TATJANA,0,0,0,11,0,100,0,0,0,0,0,11,43671,0,0,0,0,0,9,@HORSE,0,5,0,0,0,0,'Tatjana - On respawn - Spellcast Ride Vehicle'),
(@TATJANA,0,1,2,8,0,100,0,@SPELL_DART,0,0,0,11,@SPELL_PING,2,0,0,0,0,1,0,0,0,0,0,0,0,'Tatjana - On spellhit Tranquilizer Dart - Spellcast Tatjana Ping'),
(@TATJANA,0,2,3,61,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tatjana - On spellhit Tranquilizer Dart - Set faction'),
(@TATJANA,0,3,0,61,0,100,0,0,0,0,0,18,33024,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tatjana - On spellhit Tranquilizer Dart - Set unit_flags'),
(@TATJANA,0,4,0,0,0,100,0,2000,6000,9000,12000,11,32009,0,0,0,0,0,2,0,0,0,0,0,0,0,'Tatjana - On update IC - Spellcast Cutdown'),
(@TATJANA,0,5,0,38,0,100,0,0,1,0,0,41,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tatjana - On data set 0 1 - Despawn after 15 seconds'),
(@SASHA*100,9,0,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sasha script - Say line'),
(@SASHA*100,9,1,0,0,0,100,0,17000,17000,0,0,1,4,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sasha script - Say line'),
(@SASHA*100,9,2,0,0,0,100,0,16700,16700,0,0,1,5,0,0,0,0,0,7,0,0,0,0,0,0,0,'Sasha script - Say line'),
(@SASHA*100,9,3,0,0,0,100,0,10700,10700,0,0,11,@SPELL_SHOOT,0,0,0,0,0,9,@ANATOLY,0,30,0,0,0,0,'Sasha script - Say line'),
(@SASHA*100,9,4,0,0,0,100,0,60000,60000,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha script - Set event phase 1'),
(@SASHA*100,9,5,0,0,0,100,0,0,0,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha script - Set data 0 0'),
(@ANATOLY*100,9,0,0,0,0,100,0,2400,2400,0,0,45,0,4,0,0,0,0,9,@SASHA,0,30,0,0,0,0,'Anatoly script 0 - Set data 0 4'),
(@ANATOLY*100,9,1,0,0,0,100,0,5000,5000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly script 0 - Say line'),
(@ANATOLY*100,9,2,0,0,0,100,0,16800,16800,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly script 0 - Say line'),
(@ANATOLY*100,9,3,0,0,0,100,0,16800,16800,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly script 0 - Say line'),
(@ANATOLY*100,9,4,0,0,0,100,0,5000,5000,0,0,11,47457,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly script 0 - Spellcast Worgen Transform - Male'),
(@ANATOLY*100,9,5,0,0,0,100,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly script 0 - Reset unit_field_bytes1'),
(@ANATOLY*100,9,6,0,0,0,100,0,500,500,0,0,5,53,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly script 0 - Play emote'),
(@ANATOLY*100,9,7,0,0,0,100,0,150,150,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly script 0 - Say line'),
(@ANATOLY*100,9,8,0,0,0,100,0,0,0,0,0,45,0,1,0,0,0,0,9,@TATJANA,0,10,0,0,0,0,'Anatoly script 0 - Set data 0 1'),
(@ANATOLY*100,9,9,0,0,0,100,0,1200,1200,0,0,69,0,0,0,0,0,0,8,0,0,0,4069.991,-4130.805,211.464,0,'Anatoly script 0 - Move to position'),
(@ANATOLY*100,9,10,0,0,0,100,0,15000,15000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly script 0 - Despawn'),
(@ANATOLY*100+1,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly script 1 - Say line'),
(@ANATOLY*100+1,9,1,0,0,0,100,0,2000,2000,0,0,45,0,1,0,0,0,0,9,@SASHA,0,20,0,0,0,0,'Anatoly script 1 - Set data 0 1'),
(@ANATOLY*100+2,9,0,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly script 2 - Say line'),
(@ANATOLY*100+2,9,1,0,0,0,100,0,3500,3500,0,0,45,0,1,0,0,0,0,9,@SASHA,0,20,0,0,0,0,'Anatoly script 2 - Set data 0 1'),
(@ANATOLY*100+3,9,0,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly script 3 - Say line'),
(@ANATOLY*100+3,9,1,0,0,0,100,0,5000,5000,0,0,45,0,2,0,0,0,0,9,@SASHA,0,20,0,0,0,0,'Anatoly script 3 - Set data 0 1'),
(@ANATOLY*100+4,9,0,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anatoly script 4 - Say line'),
(@ANATOLY*100+4,9,1,0,0,0,100,0,5000,5000,0,0,45,0,3,0,0,0,0,9,@SASHA,0,20,0,0,0,0,'Anatoly script 4 - Set data 0 1'),
(@HORSE*100,9,0,0,0,0,100,0,500,500,0,0,53,1,@HORSE,0,0,0,0,1,0,0,0,0,0,0,0,'Tatjana''s Horse script - Start WP movement');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 8405: A Sister's Pledge and Hour Of The Worg
SET @SASHA := 26935;
SET @ANYA := 27646;
SET @CAGE := 189977;
DELETE FROM `creature_text` WHERE `entry`=@SASHA AND `groupid` IN (6,7,8);
DELETE FROM `creature_text` WHERE `entry`=@ANYA;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@SASHA,6,0,'Anya!!  You''re all right!',12,0,100,0,0,0,'Sasha'),
(@SASHA,7,0,'Badmoon?  You mean Bloodmoon?',12,0,100,0,0,0,'Sasha'),
(@SASHA,8,0,'Don''t worry, sister... no one can hurt you now.',12,0,100,0,0,0,'Sasha'),
(@ANYA,0,0,'You won''t eat me, will you?',12,0,100,0,0,0,'Anya'),
(@ANYA,1,0,'Sister!  The mean men were going to take me to Badmoon Isle.  They wanted to turn me into one of them.',12,0,100,0,0,0,'Anya'),
(@ANYA,2,0,'That''s what I said!  Badmoon!  Sasha... don''t ever leave me again!  First they took papa, then they took you... I don''t want to be alone with them!',12,0,100,0,0,0,'Anya');

-- DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (@ANYA,@SASHA);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`IN(@ANYA,@SASHA);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=189977;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@SASHA,@ANYA) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@CAGE AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@CAGE*100,@SASHA*100+1,@ANYA*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Anya
(@ANYA,0,0,1,20,0,100,0,12411,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Anya - On quest A Sister''s Pledge rewarded - Say line'),
(@ANYA,0,1,2,61,0,100,0,0,0,0,0,9,0,0,0,0,0,0,13,189977,0,5,0,0,0,0,'Anya - On quest Anatoly will talk rewarded - Activate GO'),
(@ANYA,0,2,3,61,0,100,0,0,0,0,0,12,@SASHA,3,120000,0,0,0,8,0,0,0,4001.751,-4555.144,196.4673,1.719485,'Anya - On quest Anatoly will talk rewarded - Summon Sasha'),
(@ANYA,0,3,0,61,0,100,0,0,0,0,0,80,@ANYA*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Anya - On quest Anatoly will talk rewarded - Run script'),
-- Sasha
(@SASHA,0,7,0,54,0,100,0,0,0,0,0,53,1,@SASHA,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - Just summoned - Start WP movement'),
(@SASHA,0,8,9,40,0,100,0,4,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - On WP 4 reached - Set unit_field_bytes1 (kneel)'),
(@SASHA,0,9,0,61,0,100,0,0,0,0,0,80,@SASHA*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - On WP 4 reached - Run script'),
-- Cage
(@CAGE,1,0,0,70,0,100,0,0,0,0,0,80,@CAGE*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cage - On GO activated - Run script'),
-- CageScripts
(@CAGE*100,9,0,0,0,0,100,0,10000,10000,0,0,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cage script - Reset GO'),
-- SashaScripts
(@SASHA*100+1,9,0,0,0,0,100,0,1000,1000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - On WP 4 reached - Say line'),
(@SASHA*100+1,9,1,0,0,0,100,0,16800,16800,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - On WP 4 reached - Say line'),
(@SASHA*100+1,9,2,0,0,0,100,0,16900,16900,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'Sasha - On WP 4 reached - Say line'),
-- AnyaScripts
(@ANYA*100,9,0,0,0,0,100,0,1700,1700,0,0,69,0,0,0,0,0,0,8,0,0,0,3996.337,-4516.717,196.3168,0,'Anya script - Move to position'),
(@ANYA*100,9,1,0,0,0,100,0,13300,13300,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,'Anya script - Say line'),
(@ANYA*100,9,2,0,0,0,100,0,16800,16800,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,'Anya script - Say line'),
(@ANYA*100,9,3,0,0,0,100,0,88000,88000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Anya script - Despawn');
DELETE FROM `waypoints` WHERE `entry`=26935;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(26935,1,4002.467,-4556.807,196.4988,''),
(26935,2,4001.879,-4555.998,196.4988,''),
(26935,3,3997.248,-4525.081,195.3569,''),
(26935,4,3996.828,-4519.888,195.6831,'');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 8404: An Experienced Guide 
-- Spawn Drom Frostgrip (29751)
-- 4.x guid
DELETE FROM `creature` WHERE `id`=29751;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(309,29751,571,1,1,26497,0,6951.327,46.35645,795.0692,2.670354,300,0,0,0,0,0,2,537165888,8);
DELETE FROM `creature_template_addon` WHERE `entry`=29751;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES
(29751,1,'51329');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 8382: Agmar's Hammer missing gossips
UPDATE `creature_template` SET `gossip_menu_id`=9493 WHERE `entry`=25257; -- Saurfang the Younger
UPDATE `creature_template` SET `gossip_menu_id`=9317 WHERE `entry`=26181; -- Emissary Brighthoof <Tauren Emissary>
UPDATE `creature_template` SET `gossip_menu_id`=9318 WHERE `entry`=26485; -- Orphan Matron Twinbreeze
UPDATE `creature_template` SET `gossip_menu_id`=9437 WHERE `entry`=26504; -- Soar Hawkfury <Stable Master>
UPDATE `creature_template` SET `gossip_menu_id`=9661 WHERE `entry`=26505; -- Doctor Sintar Malefious <Grand Apothecary>
UPDATE `creature_template` SET `gossip_menu_id`=9459 WHERE `entry`=26564; -- Borus Ironbender <Blacksmithing Trainer>
UPDATE `creature_template` SET `gossip_menu_id`=9456, `AIName`='SmartAI' WHERE `entry`=26581; -- Koltira Deathweaver
UPDATE `creature_template` SET `gossip_menu_id`=9432 WHERE `entry`=26618; -- Captain Gort <Kor'kron Guard Captain>
UPDATE `creature_template` SET `gossip_menu_id`=9433 WHERE `entry`=26854; -- Earthwarden Grife
UPDATE `creature_template` SET `gossip_menu_id`=9434 WHERE `entry`=26859; -- Rokhan
UPDATE `creature_template` SET `gossip_menu_id`=9465 WHERE `entry`=26979; -- Kontokanis
UPDATE `creature_template` SET `gossip_menu_id`=9487 WHERE `entry`=27267; -- Quartermaster Bartlett <Blacksmithing Supplies>
UPDATE `creature_template` SET `gossip_menu_id`=9501 WHERE `entry`=27350; -- Agent Skully <Onslaught Caretaker>
UPDATE `creature_template` SET `gossip_menu_id`=9507 WHERE `entry`=27376; -- Deathguard Schneider
UPDATE `creature_template` SET `gossip_menu_id`=9508 WHERE `entry`=27378; -- Senior Scrivener Barriga
UPDATE `creature_template` SET `gossip_menu_id`=9509 WHERE `entry`=27379; -- Engineer Burke
UPDATE `creature_template` SET `gossip_menu_id`=9510 WHERE `entry`=27381; -- Chancellor Amai
UPDATE `creature_template` SET `gossip_menu_id`=9598 WHERE `entry`=27804; -- Golluck Rockfist <Horde Ambassador>
UPDATE `creature_template` SET `gossip_menu_id`=9607, `AIName`='SmartAI' WHERE `entry`=27846; -- Junior Apothecary Lawrence
UPDATE `creature_template` SET `gossip_menu_id`=9821 WHERE `entry`=28057; -- Garmin Herzog <Stable Master>
UPDATE `creature_template` SET `gossip_menu_id`=9950 WHERE `entry`=30373; -- Elder Skywarden
UPDATE `creature_template` SET `gossip_menu_id`=10207 WHERE `entry`=32599; -- Surveyor Hansen
DELETE FROM `gossip_menu` WHERE `entry`=9317 AND `text_id`=12627;
DELETE FROM `gossip_menu` WHERE `entry`=9318 AND `text_id`=12628;
DELETE FROM `gossip_menu` WHERE `entry`=9432 AND `text_id`=12698;
DELETE FROM `gossip_menu` WHERE `entry`=9433 AND `text_id`=12699;
DELETE FROM `gossip_menu` WHERE `entry`=9434 AND `text_id`=12701;
DELETE FROM `gossip_menu` WHERE `entry`=9437 AND `text_id`=12703;
DELETE FROM `gossip_menu` WHERE `entry`=9456 AND `text_id`=12715;
DELETE FROM `gossip_menu` WHERE `entry`=9459 AND `text_id`=12718;
DELETE FROM `gossip_menu` WHERE `entry`=9465 AND `text_id`=12725;
DELETE FROM `gossip_menu` WHERE `entry`=9487 AND `text_id`=12759;
DELETE FROM `gossip_menu` WHERE `entry`=9493 AND `text_id`=12777;
DELETE FROM `gossip_menu` WHERE `entry`=9501 AND `text_id`=12795;
DELETE FROM `gossip_menu` WHERE `entry`=9507 AND `text_id`=12804;
DELETE FROM `gossip_menu` WHERE `entry`=9508 AND `text_id`=12805;
DELETE FROM `gossip_menu` WHERE `entry`=9509 AND `text_id`=12806;
DELETE FROM `gossip_menu` WHERE `entry`=9510 AND `text_id`=12808;
DELETE FROM `gossip_menu` WHERE `entry`=9598 AND `text_id`=12954;
DELETE FROM `gossip_menu` WHERE `entry`=9606 AND `text_id`=12978;
DELETE FROM `gossip_menu` WHERE `entry`=9607 AND `text_id`=12977;
DELETE FROM `gossip_menu` WHERE `entry`=9661 AND `text_id`=13089;
DELETE FROM `gossip_menu` WHERE `entry`=9950 AND `text_id`=7935;
DELETE FROM `gossip_menu` WHERE `entry`=10207 AND `text_id`=14177;
DELETE FROM `gossip_menu` WHERE `entry`=21054; -- existing value not from sniff
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(9317,12627),
(9318,12628),
(9432,12698),
(9433,12699),
(9434,12701),
(9437,12703),
(9456,12715),
(9459,12718),
(9465,12725),
(9487,12759),
(9493,12777),
(9501,12795),
(9507,12804),
(9508,12805),
(9509,12806),
(9510,12808),
(9598,12954),
(9606,12978),
(9607,12977),
(9661,13089),
(9950,7935),
(10207,14177);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9437,9456,9459,9487,9607) AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9437,0,0,'I wish to make use of the stables.',14,4194304,0,0,0,0,''),
(9456,0,0,'I should return to the world of shades, Koltira. Send me back.',1,1,0,0,0,0,''),
(9459,0,3,'Train me.',5,16,0,0,0,0,''),
(9487,0,1,'Let me browse your goods.',5,16,0,0,0,0,''),
(9607,0,0,'All right, I''ll take this mixture of yours.',1,1,9606,0,0,0,'');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9456;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,9456,0,0,0,9,0,12132,0,0,0,0,'','Koltira Deathweaver show gossip option if player has quest 12132'),
(15,9456,0,0,0,1,47740,0,0,1,0,0,'','Koltira Deathweaver show gossip option if player has not aura World of Shadows');
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26581,27846) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26581,0,1,0,62,0,100,0,9456,0,0,0,11,47740,0,0,0,0,0,7,0,0,0,0,0,0,0,'Koltira Deathweaver - On gossip option select - Spellcast World of Shadows'),
(26581,0,0,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Koltira Deathweaver - On gossip option select - Close gossip'),
(27846,0,0,0,62,0,100,0,9607,0,0,0,85,49747,0,0,0,0,0,7,0,0,0,0,0,0,0,'Junior Apothecary Lawrence - On gossip option select - Invoker spellcast Create Experimental Mixture');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 8032: Destroying the Altars
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=57853;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,57853,0,0,31,0,3,30742,0,0,0,'',"Master Summoner's Staff spell implicit target First Summoning Altar"),
(13,1,57853,0,1,31,0,3,30744,0,0,0,'',"Master Summoner's Staff spell implicit target Second Summoning Altar"),
(13,1,57853,0,2,31,0,3,30745,0,0,0,'',"Master Summoner's Staff spell implicit target Third Summoning Altar"),
(13,1,57853,0,3,31,0,3,30950,0,0,0,'',"Master Summoner's Staff spell implicit target Fourth Summoning Altar");
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7996: Set Required races for some Argent Tournament quests
UPDATE `quest_template` SET `RequiredClasses`=32 WHERE `Id` IN(13812,13788,13863,13864,13814,13793,13813,13791,13795); -- Death Knight Only
UPDATE `quest_template` SET `RequiredClasses`=1503 WHERE `Id` IN(13809,13682,13862,13861,13811,13790,13810,13789,13794); -- non Death Knight
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7969: Pyroblast Cinnamon Ball (37582), G.N.E.R.D.S. (37583), Soothing Spearmint Candy (37584) & Chewy Fel Taffy (37585) duration fix
-- UPDATE `item_template` SET `flagsCustom` = 1 WHERE `entry` IN (37582,37583,37584,37585);
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7964: Hyperspeed Acceleration
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=54758;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(17,0,54758,0,0,7,0,202,375,0,0,0,'','Hyperspeed Acceleration requires 375 Engineering skill');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7824: Missing Brewfest Vendors
-- Horde Vendor (Blix Fixwidget <Token Redeemer>) http://www.old.wowhead.com/npc=24495
DELETE FROM `npc_vendor` WHERE `entry` = 24495 AND `item` IN (37737,46707,33863,33862);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`) VALUES 
(24495,0,37737,0,0,2397), -- "Brew of the Month" Club Membership Form (Horde) (200 Brewfest Tokens) http://www.old.wowhead.com/item=37737
(24495,0,46707,0,0,2275), -- Pint-Sized Pink Pachyderm (100 Brewfest Tokens) http://www.old.wowhead.com/item=46707
(24495,0,33863,0,0,2276), -- Brewfest Dress (200 Brewfest Tokens) http://www.old.wowhead.com/item=33863
(24495,0,33862,0,0,2276); -- Brewfest Regalia (200 Brewfest Tokens) http://www.old.wowhead.com/item=33862
-- Alliance Vendor (Belbi Quikswitch <Token Redeemer>) http://www.old.wowhead.com/npc=23710
DELETE FROM `npc_vendor` WHERE `entry` = 23710 AND `item` IN (46707,32233);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`) VALUES 
(23710,0,46707,0,0,2275), -- Pint-Sized Pink Pachyderm (100 Brewfest Tokens) http://www.old.wowhead.com/item=46707
(23710,0,32233,0,0,0); -- Wolpertinger's Tankard http://www.old.wowhead.com/item=32233
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7823: This One Time, When I Was Drunk... Alliance quest giver fix
-- UPDATE `gameobject_questrelation` SET `id`=189989 WHERE `quest`=12020;
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7416: Twilight of the Dawn Runner 
UPDATE `smart_scripts` SET `event_type`=62, `event_param1`=7371, `comment`='Ithania - On gossip select - run timed action list' WHERE (`entryorguid`=17119 AND `source_type`=0 AND `id`=0);
UPDATE `creature_template` SET `gossip_menu_id` = 7371 WHERE `entry` = 17119;
DELETE FROM `gossip_menu` WHERE `entry`=7371 AND `text_id`=8808;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES(7371,8808);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=7371 AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(7371,0,0,'Balandar sent me to get you out of here and pick up his cargo. He is waiting for you in the Brackenwall.',1,1,0,0,0,0,NULL);
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7301: 
DELETE FROM game_graveyard_zone WHERE ghost_zone = 719;
INSERT INTO game_graveyard_zone (id, ghost_zone, faction) VALUES
(469, 719, 0);
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7219: The Ashenvale Hunt
UPDATE `creature_template` SET `gossip_menu_id`=4346 WHERE `entry`=12696;
DELETE FROM `gossip_menu` WHERE `entry`=4346 AND `text_id`=5529;
DELETE FROM `gossip_menu` WHERE `entry`=4381 AND `text_id`=5593;
DELETE FROM `gossip_menu` WHERE `entry`=4382 AND `text_id`=5595;
DELETE FROM `gossip_menu` WHERE `entry`=4383 AND `text_id`=5594;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(4346,5529),
(4381,5593),
(4382,5595),
(4383,5594);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=4346 AND `id` IN (0,1,2);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(4346,0,0,"What can you tell to me about the bear - Ursangous?",1,1,4381,0,0,0,NULL),
(4346,1,0,"What can you tell to me about the nightsaber cat - Shadumbra?",1,1,4383,0,0,0,NULL),
(4346,2,0,"What can you tell to me about the hippogryph - Sharptalon?",1,1,4382,0,0,0,NULL);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=4346;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=247;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,4346,0,0,0,8,0,6383,0,0,0,0,'',"Show gossip only if The Ashenvale Hunt (6383) quest is rewarded"),
(15,4346,0,0,0,8,0,23,0,0,1,0,'',"Show gossip only if Ursangous's Paw (23) quest is not rewarded"),
(15,4346,1,0,0,8,0,6383,0,0,0,0,'',"Show gossip only if The Ashenvale Hunt (6383) quest is rewarded"),
(15,4346,1,0,0,8,0,24,0,0,1,0,'',"Show gossip only if Shadumbra's Head (24) quest is not rewarded"),
(15,4346,2,0,0,8,0,6383,0,0,0,0,'',"Show gossip only if The Ashenvale Hunt (6383) quest is rewarded"),
(15,4346,2,0,0,8,0,2,0,0,1,0,'',"Show gossip only if Sharptalon's Claw (2) quest is not rewarded"),
-- Quest The Hunt Completed (247) should only be available once Sharptalon's Claw (2), Ursangous's Paw (23) and Shadumbra's Head (24) quests are rewarded.
(19,0,247,0,1,8,0,2,0,0,0,0,'',"Show quest only if Sharptalon's Claw (2) quest is rewarded AND"),
(19,0,247,0,1,8,0,23,0,0,0,0,'',"Show quest only if Ursangous's Paw (23) quest is rewarded AND"),
(19,0,247,0,1,8,0,24,0,0,0,0,'',"Show quest only if Shadumbra's Head (24) quest is rewarded AND");
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7079: Corporal Thund Splithoof
DELETE FROM `gossip_menu_option` WHERE (`menu_id`=840 AND `id`=2);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(840, 2, 0, 'Hero, I have urgent business with Corporal Splithoof.', 1, 3, 0, 0, 0, 0, ''); -- 7572
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7155: Aleric Hawkins
-- DELETE FROM `creature` WHERE `id`=36517;
-- INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
-- (310,36517,0,1,1,0,0,1283,338.9167,-59.9998,0.2443461,120,0,0,1,0,0,0,0,0);
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 7011: Inactive Fel Reaver
-- DELETE FROM `creature_ai_scripts` WHERE (`creature_id`=22293);
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 22293;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=22293 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(22293,0,0,0,11,0,100,1,0,0,0,0,11,38757,0,0,0,0,0,1,0,0,0,0,0,0,0,'Inactive Fel Reaver Cast - Fel Reaver Freeze on Self');
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 6959: There Is No Hope
-- UPDATE `quest_template` SET `Flags`=262282,`RewardItemId1`=28168,`RewardItemCount1`=1,`RewardChoiceItemId1`=28173,`RewardChoiceItemId2`=28169,`RewardChoiceItemId3`=28172,`RewardChoiceItemId4`=28175,`RewardChoiceItemCount1`=1,`RewardChoiceItemCount2`=1,`RewardChoiceItemCount3`=1,`RewardChoiceItemCount4`=1 WHERE `Id`=10172;
-- ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 6212: Merciful Freedom
-- UPDATE `gameobject_template` SET AIName='SmartGameObjectAI', data2=0, ScriptName='' WHERE `entry` BETWEEN 187854 AND 187868;
-- UPDATE `gameobject_template` SET AIName='SmartGameObjectAI', data2=0, ScriptName='' WHERE `entry` BETWEEN 187870 AND 187874;
SET @Scourge_Cage :=187854;

DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 187854 AND 187868;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 187870 AND 187874;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18785400,18785500,18785600,18785700,18785800,18785900,18786000,18786100,18786200,18786300,18786400,18786500,18786600,18786700,18786800,18787000,18787100,18787200,18787300,18787400);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- 187854
(@Scourge_Cage,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage,1,2,0,61,0,100,0,0,0,0,0,80,@Scourge_Cage*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
(@Scourge_Cage*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187855
(@Scourge_Cage+1,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+1,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+1,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+1)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+1)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187856
(@Scourge_Cage+2,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+2,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+2,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+2)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+2)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187857
(@Scourge_Cage+3,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+3,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+3,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+3)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+3)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187858
(@Scourge_Cage+4,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+4,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+4,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+4)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+4)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187859
(@Scourge_Cage+5,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+5,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+5,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+5)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+5)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187860
(@Scourge_Cage+6,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+6,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+6,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+6)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+6)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187861 
(@Scourge_Cage+7,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+7,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+7,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+7)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+7)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187862
(@Scourge_Cage+8,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+8,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+8,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+8)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+8)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187863
(@Scourge_Cage+9,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+9,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+9,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+9)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+9)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187864
(@Scourge_Cage+10,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+10,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+10,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+10)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+10)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187865
(@Scourge_Cage+11,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+11,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+11,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+11)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+11)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187866
(@Scourge_Cage+12,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+12,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+12,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+12)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+12)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187867
(@Scourge_Cage+13,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+13,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+13,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+13)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+13)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187868
(@Scourge_Cage+14,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+14,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+14,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+14)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+14)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187870
(@Scourge_Cage+16,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+16,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+16,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+16)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+16)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187871
(@Scourge_Cage+17,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+17,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+17,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+17)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+17)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187872
(@Scourge_Cage+18,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+18,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+18,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+18)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+18)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187873
(@Scourge_Cage+19,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+19,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+19,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+19)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+19)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject'),
-- 187874
(@Scourge_Cage+20,1,0,1,70,0,100,0,2,0,0,0,33,25610,0,0,0,0,0,7,0,0,0,0,0,0,0,'Scourge Cage - Activated - Credit'),
(@Scourge_Cage+20,1,1,2,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,25610,5,0,0,0,0,0,'Scourge Cage - Linked - Set Data To Scourge Prisoner'),
(@Scourge_Cage+20,1,2,0,61,0,100,0,0,0,0,0,80,(@Scourge_Cage+20)*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Linked - Run Script'),
((@Scourge_Cage+20)*100,9,0,0,0,0,100,0,65000,65000,65000,65000,32,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Cage - Script - Reset GameObject');
UPDATE `creature` SET spawntimesecs=0 WHERE id IN(25610);
UPDATE `creature_template` SET AIName='SmartAI', ScriptName='', unit_flags=768 WHERE entry IN(25610);
DELETE FROM `smart_scripts` WHERE entryorguid IN(25610);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25610,0,0,0,10,0,100,0,1,15,15000,30000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Prisoner - Range - Say 0'),
(25610,0,1,0,38,0,100,0,1,1,0,0,1,1,5000,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Prisoner - Data Set - Say 1'),
(25610,0,2,3,52,0,100,0,1,25610,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Prisoner - Data Set - Unseen'),
(25610,0,3,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Scourge Prisoner - Linked - Desapwn');
DELETE FROM `conditions` WHERE SourceTypeOrReferenceId=22 AND SourceEntry=25610;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 25610, 0, 0, 9, 0, 11676, 0, 0, 1, 0, '', 'SAI - Help Text Only if Player in Range Have No Quest');
DELETE FROM `creature_text` WHERE entry IN(25610);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(25610, 0, 0, "Don't let them turn me into one of those aberrations!", 12, 0, 100, 1, 0, 0, 'Scourge Prisoner'),
(25610, 0, 1, "Kill me... Kill me now!", 12, 0, 100, 1, 0, 0, 'Scourge Prisoner'),
(25610, 0, 2, "Somebody please... Help...", 12, 0, 100, 1, 0, 0, 'Scourge Prisoner'),
(25610, 0, 3, "Don't let them turn me into one of those aberrations!", 12, 0, 100, 1, 0, 0, 'Scourge Prisoner'),
(25610, 1, 0, "Freedom at last! I must return to Warsong Hold at once!", 12, 0, 100, 1, 0, 0, 'Scourge Prisoner'),
(25610, 1, 1, "I am forever indebted to you, friend.", 12, 0, 100, 1, 0, 0, 'Scourge Prisoner'),
(25610, 1, 2, "Thank you, friend.", 12, 0, 100, 1, 0, 0, 'Scourge Prisoner'),
(25610, 1, 3, "You have my thanks, stranger.", 12, 0, 100, 1, 0, 0, 'Scourge Prisoner');
-- STARTUP FIXES:
DELETE FROM `creature_addon` WHERE `guid`=113585;
UPDATE `creature` SET `spawndist`=0 WHERE `guid`=109406;

-- Scripted Npc Infiltrator Marksen (Zombie Form 7293) From Sniff author expecto Closes #6910
UPDATE creature_template SET AIName = 'SmartAI', `spell1` = 7293 WHERE entry = 5416;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=5416 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(5416, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 10000, 12000, 11, 7293, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infiltrator Marksen - Cast Zombie Form');

-- Wildlord Antelarion (22127) gossip fix by nelegalno
-- Thanks to @Aokromes for the sniff and @malcrom for all the help
-- Closes #4444 and #5985

UPDATE `creature_template` SET `gossip_menu_id`=8523 WHERE `entry`=22127;

-- Gossip insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=8523;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8523,10657);

-- Gossip option sfiffed by Aokromes
DELETE FROM `gossip_menu_option` WHERE `menu_id`=8523;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(8523,0,0,"The Felsworn Gas Mask was destroyed, do you have another one?",1,1,0,0,0,0,'');

-- Gossip option conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=15 AND `SourceGroup`=8523);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
-- Felsworn Gas Mask quest taken
(15,8523,0,0,0,2,0,31366,1,0,1,0,'',"Show gossip only if player doesnt have Felsworn Gas Mask"),
(15,8523,0,0,0,9,0,10819,0,0,0,0,'',"Show gossip if Felsworn Gas Mask quest taken"),
-- Felsworn Gas Mask quest rewarded and You're Fired! quest not rewarded
(15,8523,0,0,1,2,0,31366,1,0,1,0,'',"Show gossip only if player doesnt have Felsworn Gas Mask"),
(15,8523,0,0,1,8,0,10819,0,0,0,0,'',"Show gossip if Felsworn Gas Mask quest rewarded"),
(15,8523,0,0,1,8,0,10821,0,0,1,0,'',"Hide gossip when You're Fired! quest rewarded");

-- Spell conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=17 AND `SourceEntry`=38448);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,38448,0,0,3,0,31366,0,0,0,0,'',"Felsworn Gas Mask spell only if the mask is equiped");

-- SAI for Wildlord Antelarion
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=22127;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=22127 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(22127,0,0,1,62,0,100,0,8523,0,0,0,11,39101,0,0,0,0,0,7,0,0,0,0,0,0,0,"Wildlord Antelarion - On Gossip option select - Cast Create Felsword Gas Mask"),
(22127,0,1,2,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Wildlord Antelarion - On Gossip option select - Close Gossip"),
(22127,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wildlord Antelarion - On Gossip option select - Say 0");

-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry` IN (22127) AND `groupid` IN (0);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(22127,0,0,"It's a good thing I was able to make duplicates of the Felsworn Gas Mask.",12,0,100,1,0,0,"Wildlord Antelarion");

-- A Plague Upon Thee (5902, 5904) quest fix by Svannon and nelegalno Closes #7700

DELETE FROM `gossip_menu_option` WHERE `menu_id`=4362;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(4362,0,0,'Put the barrel of termites on this box.',1,1,0,0,0,0,''),
(4362,1,0,'Put the barrel of termites on this box.',1,1,0,0,0,0,'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=4362;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,4362,0,0,0,28,0,5902,0,0,0,0,'','Only Show Gossip if A Plauge Upon Thee 2 is done (Horde)'),
(15,4362,1,0,1,28,0,5904,0,0,0,0,'','Only Show Gossip if A Plauge Upon Thee 2 is done (Ally)'),
-- Allows you to pickup quest if server crashes
(15,4362,0,0,2, 8,0,5902,0,0,0,0,'','Only Show Gossip if A Plauge Upon Thee 2 is rewarded (Horde)'),
(15,4362,0,0,2,28,0,6390,0,0,1,0,'','Only Show Gossip if A Plauge Upon Thee 3 is not taken (Horde)'),
(15,4362,0,0,2, 8,0,6390,0,0,1,0,'','Only Show Gossip if A Plauge Upon Thee 3 is not rewarded (Horde)'),
(15,4362,1,0,3, 8,0,5904,0,0,0,0,'','Only Show Gossip if A Plauge Upon Thee 2 is rewarded (Ally)'),
(15,4362,1,0,3,28,0,6389,0,0,1,0,'','Only Show Gossip if A Plauge Upon Thee 3 is not taken (Ally)'),
(15,4362,1,0,3, 8,0,6389,0,0,1,0,'','Only Show Gossip if A Plauge Upon Thee 3 is not rewarded (Ally)');

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=177490;
DELETE FROM `smart_scripts` WHERE `entryorguid`=177490 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(177490,1,0,1,62,0,100,0,4362,0,0,0,50,177491,60000,0,0,0,0,8,0,0,0,2449.614014,-1662.360352,104.370209,104.370209,'Temp Spawn Termite Barrel'),
(177490,1,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Close Gossip'),
(177490,1,2,1,62,0,100,0,4362,1,0,0,50,177491,60000,0,0,0,0,8,0,0,0,2449.614014,-1662.360352,104.370209,104.370209,'Temp Spawn Termite Barrel');


-- Sanguine Hibiscus spawns by aokromes Closes #6985
SET @OGUID = 2569; -- Set by TDB (4.x)
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+12;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 183385, 546, 3, 1, 80.50446, -70.98401, -2.75813, -1.518436, 0, 0, 0, 1, 7200, 255, 1), -- 183385 (Area: 0)
(@OGUID+1, 183385, 546, 3, 1, 144.8807, -69.80858, 27.43485, 0.9948372, 0, 0, 0, 1, 7200, 255, 1), -- 183385 (Area: 0)
(@OGUID+2, 183385, 546, 3, 1, 52.38583, -188.3249, -4.27433, -2.478367, 0, 0, 0, 1, 7200, 255, 1), -- 183385 (Area: 0)
(@OGUID+3, 183385, 546, 3, 1, 57.51215, -228.6515, -4.474028, -1.919862, 0, 0, 0, 1, 7200, 255, 1), -- 183385 (Area: 0)
(@OGUID+4, 183385, 546, 3, 1, 1.739941, -246.5631, -4.533222, -1.099556, 0, 0, 0, 1, 7200, 255, 1), -- 183385 (Area: 0)
(@OGUID+5, 183385, 546, 3, 1, -98.4295, -312.3992, -3.895051, -1.204277, 0, 0, 0, 1, 7200, 255, 1), -- 183385 (Area: 0)
(@OGUID+6, 183385, 546, 3, 1, -151.6738, -308.3728, -4.809014, 1.658062, 0, 0, 0, 1, 7200, 255, 1), -- 183385 (Area: 0)
(@OGUID+7, 183385, 546, 3, 1, 22.0234, -339.9811, 29.18158, 1.239183, 0, 0, 0, 1, 7200, 255, 1), -- 183385 (Area: 0)
(@OGUID+8, 183385, 546, 3, 1, 74.19567, -402.8985, 33.69212, 1.745327, 0, 0, 0, 1, 7200, 255, 1), -- 183385 (Area: 0)
(@OGUID+9, 183385, 546, 3, 1, 105.351, -295.466, 32.22884, -2.094393, 0, 0, 0, 1, 7200, 255, 1), -- 183385 (Area: 0)
(@OGUID+10, 183385, 546, 3, 1, 257.2508, -263.9068, 24.64264, -2.007128, 0, 0, 0, 1, 7200, 255, 1), -- 183385 (Area: 0)
(@OGUID+11, 183385, 546, 3, 1, 246.2179, -232.5182, 25.95434, 1.466076, 0, 0, 0, 1, 7200, 255, 1), -- 183385 (Area: 0)
(@OGUID+12, 183385, 546, 3, 1, 295.0749, -124.0022, 29.71378, 0.1745321, 0, 0, 0, 1, 7200, 255, 1); -- 183385 (Area: 0)

-- fix loot of Savage Cave Beast Closes #7874
DELETE FROM `creature_loot_template` WHERE `entry` = 31470;
INSERT INTO `creature_loot_template` 
SELECT 31470, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount` FROM `creature_loot_template` WHERE `entry` = 30329;

-- partially revert commit 0deaa521bcae3ab9004529473aceadee134f3a68 author Elron103 Closes #7580
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN (9713,9926,11087,11115,11116,11353,11518,12186,12187,12494,12845,13807,14185,14186,14187,24808,24809,24810,24811,25238);

-- Add conditions for spell In the Maws of Old the God author trista Closes #1664
SET @ThrowFragments := 64184; -- The spell "In the Maws of Old the God" that you throw at Yogg-Saron while he is casting Deafening Roar.
SET @DeafeningRoar :=  64189; -- The scream that Yogg-Saron makes in 3rd phase of 25 man with 0-3 Guardians alive.
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=@ThrowFragments;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,@ThrowFragments,0,0,1,0,@DeafeningRoar,1,0,0,0,'','In the Maws of the Old God can be casted only under the effect of Deafening Roar'),
(17,0,@ThrowFragments,0,0,31,1,3,33288,0,0,0,'','In the Maws of the Old God can target only Yogg-Saron');

-- Fixes Equip Display on King Varian Wrynn author warriorpoetex Closes #6646
-- UPDATE `creature_equip_template` SET `itemEntry1`=45899, `itemEntry2`=0 WHERE `entry`=1643; 4.x - Already corrected
-- Template updates for creature 29611 (King Varian Wrynn)
-- Model data 28127 (creature 29611 (King Varian Wrynn))
-- UPDATE `creature_model_info` SET `bounding_radius`=0.3875,`combat_reach`=1.25,`gender`=0 WHERE `modelid`=28127; -- King Varian Wrynn, 4.x - Already corrected
-- Addon data for creature 29611 (King Varian Wrynn)
-- DELETE FROM `creature_template_addon` WHERE `entry`=29611;
-- INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
-- (29611,0,0,257,0, NULL); -- King Varian Wrynn, 4.x - Already corrected

-- fix Crashin' Thrashin' Racer author nelegalno Closes #4363
UPDATE `creature_template` SET `spell1` = 49297 WHERE `entry` IN (27664,40281);

-- Gossip sent from League of Arathor Emissary 14991 if player too low for Arathi Basin author malcorm and pitcrawler Closes #6874
-- Gossip sent from Donal Osgood <Arathi Basin Battlemaster> 857 if player too low for Arathi Basin
-- Gossip for Huntress Kima, Eldrin, Herbalist Pomeroy, Lisbeth Schneider, Warg Deepwater, Donald Rabonne, Gremlock Pilsnor, Apprentice Kryten, Bulrug, Ranshalla, Jaron Stoneshaper, Aurora Skycaller, Spirit of the Vale, Farseer Nobundo, Temper

UPDATE `creature_template` SET `gossip_menu_id`=7377 WHERE `entry`=17204;
UPDATE `creature_template` SET `gossip_menu_id`=6471 WHERE `entry`=857;
UPDATE `creature_template` SET `gossip_menu_id`=7695 WHERE `entry`=18416;
UPDATE `creature_template` SET `gossip_menu_id`=4261 WHERE `entry`=1103;
UPDATE `creature_template` SET `gossip_menu_id`=7691 WHERE `entry`=1218;
UPDATE `creature_template` SET `gossip_menu_id`=685 WHERE `entry`=1299;
UPDATE `creature_template` SET `gossip_menu_id`=5665 WHERE `entry`=1683;
UPDATE `creature_template` SET `gossip_menu_id`=5665 WHERE `entry`=2367;
UPDATE `creature_template` SET `gossip_menu_id`=5853 WHERE `entry`=1699;
UPDATE `creature_template` SET `gossip_menu_id`=2601 WHERE `entry`=2788;
UPDATE `creature_template` SET `gossip_menu_id`=9821 WHERE `entry`=10054;
UPDATE `creature_template` SET `gossip_menu_id`=3131 WHERE `entry`=10300;
UPDATE `creature_template` SET `gossip_menu_id`=3761 WHERE `entry`=10301;
UPDATE `creature_template` SET `gossip_menu_id`=4743 WHERE `entry`=10304;
UPDATE `creature_template` SET `gossip_menu_id`=7376 WHERE `entry`=17087;
UPDATE `creature_template` SET `gossip_menu_id`=7378 WHERE `entry`=17205;

DELETE FROM `gossip_menu` WHERE `entry`=6504 AND `text_id`=7699;
DELETE FROM `gossip_menu` WHERE `entry`=6471 AND `text_id`=7642;
DELETE FROM `gossip_menu` WHERE `entry`=7695 AND `text_id`=9389;
DELETE FROM `gossip_menu` WHERE `entry`=4261 AND `text_id`=5413;
DELETE FROM `gossip_menu` WHERE `entry`=7691 AND `text_id`=9385;
DELETE FROM `gossip_menu` WHERE `entry`=685 AND `text_id`=1235;
DELETE FROM `gossip_menu` WHERE `entry`=5853 AND `text_id`=7016;
DELETE FROM `gossip_menu` WHERE `entry`=2601 AND `text_id` IN (3293,3294);
DELETE FROM `gossip_menu` WHERE `entry`=7376 AND `text_id` IN (8826,8827);
DELETE FROM `gossip_menu` WHERE `entry`=7377 AND `text_id` IN (8828,8829);
DELETE FROM `gossip_menu` WHERE `entry`=7378 AND `text_id`=8832;

INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES 
(2601,3293),
(2601,3294),
(6504,7699),
(6471,7642),
(7695,9389),
(4261,5413),
(7691,9385),
(685,1235),
(5853,7016),
(7376,8826),
(7376,8827),
(7377,8828),
(7377,8829),
(7378,8832);

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (4261,6471) AND `id` = 0;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=4743 AND `id` IN (0,1);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(4261,0,3, 'Train me.',5,16,0,0,0,0, ''),
(6471,0,9, 'I would like to go to the battleground.',12,1048576,0,0,0,0, ''),
(4743,0,0, 'Where can I get Enchanted Thorium?',1,1,0,0,0,0, ''),
(4743,1,0, 'Where can I find Crystal Restore?',1,1,0,0,0,0, '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=3131 AND `SourceEntry`=4788;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=4743 AND `SourceEntry` IN (5816,5817);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7376 AND `SourceEntry`=8827;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=4743 AND `SourceEntry` IN (0,1);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=4743 AND `SourceEntry` IN (5816,5817,5795);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=6471 AND `SourceEntry`=7642;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=6504 AND `SourceEntry`=7699;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=6471 AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=5665 AND `SourceEntry` IN (6960,6961);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=5853 AND `SourceEntry`=7021;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,6471,7642,0,0,27,0,20,2,0,0,0,'','Donal Osgood <Arathi Basin Battlemaster> - Show different gossip if player level is below 20'),
(14,6504,7699,0,0,27,0,20,2,0,0,0,'','League of Arathor Emissary - Show different gossip if player level is below 20'),
(15,6471,0,0,0,27,0,20,3,0,0,0,'','Donal Osgood <Arathi Basin Battlemaster> - Show gossip option only if player level is at least 20'),
(14,5665,6960,0,0,7,0,356,225,0,0,0,'','Show different gossip if player has fishing skill 225'),
(14,5665,6961,0,0,7,0,356,225,0,1,0,'','Show gossip if player has not fishing skill 225'),
(14,5853,7021,0,0,7,0,185,1,0,0,0,'','Show different gossip if player has cooking profession'),
(14,3131,4788,0,0,8,0,979,0,0,0,0,'','Show different gossip if player has completed quest 979'),
(14,4743,5816,0,0,28,0,5245,0,0,0,0,'','Show different gossip if player has quest 5245 objectives complete'),
(14,4743,5817,0,0,8,0,5245,0,0,0,0,'','Show different gossip if player has completed quest 5245'),
(14,4743,5795,0,0,8,0,5247,0,0,0,0,'','Show different gossip if player has completed quest 5247'),
(14,7376,8827,0,0,8,0,9450,0,0,1,0,'','Show different gossip if player has not completed quest 9450'),
(15,4743,0,0,0,9,0,5247,0,0,0,0,'','Show gossip option only if player has taken quest 5247 but not complete'),
(15,4743,1,0,0,9,0,5247,0,0,0,0,'','Show gossip option only if player has taken quest 5247 but not complete');


-- Flesh Eating Worms should not have loot author exodius Closes #7144
UPDATE `creature_template` SET `lootid`=0 WHERE `entry`=2462;
-- Remove loot template for Entry 2462.
-- Flesh Eating Worms should not have loot and ID is not related to any other creature
DELETE FROM `creature_loot_template` WHERE `entry`=2462 and `item` IN (785,2450,2452,2453,2772,2835,2838,3369);

-- Wailing Winds (30450) loot fix by nelegalno Closes #6382
DELETE FROM `creature_loot_template` WHERE (`entry`=30450);
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
(30450, 26001, 3, 1, 1, -26001, 1),
(30450, 26002, 3, 1, 1, -26002, 1),
(30450, 26012, 1, 1, 1, -26012, 1),
(30450, 26013, 1, 1, 1, -26013, 1),
(30450, 26014, 1, 1, 1, -26014, 1),
(30450, 26015, 1, 1, 1, -26015, 1),
(30450, 45912, 0.1, 1, 0, 1, 1),
(30450, 39512, 80, 1, 0, 1, 1),
(30450, 37702, 25, 1, 0, 1, 2),
(30450, 39513, 20, 1, 0, 1, 1);

-- Daio the Decrepit (14463) gossip fix by nelegalno Closes #7376
UPDATE `creature_template` SET `gossip_menu_id` = 5824 WHERE `entry` = 14463;
DELETE FROM `gossip_menu` WHERE `entry`=5824 AND `text_id`=6995;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (5824,6995);

-- Set pickpocketloot data for Skeletal Reavers author trista Closes #7366
SET @SREAVER := 32467;
UPDATE `creature_template` SET `pickpocketloot`=`entry` WHERE `entry`=@SREAVER; 
DELETE FROM `pickpocketing_loot_template` WHERE `entry`=@SREAVER;   
INSERT INTO `pickpocketing_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES 
(@SREAVER,35947,0.7,1,0,1,1), -- Sparkling Frostcap 
(@SREAVER,33447,0.7,1,0,1,1), -- Runic Healing Potion   
(@SREAVER,38269,1.4,1,0,1,1), -- Soggy Handkerchief
(@SREAVER,43575,1.6,1,0,1,1); -- Reinforced Junkbox

-- Bone Gryphon (29414) NPC needed for No Fly Zone (12815) quest by Vincent-Michael Closes #7355
SET @ENTRY := 29414; -- Bone Gryphon

UPDATE `creature_template` SET `spell5`=0, `InhabitType` = 5 WHERE `entry` = @ENTRY;
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@ENTRY,0,0,0x3000000,0x1,0,'54422 54476');

-- Remove hardcored old model at creature for Rull Snowhoof author aokromes Closes #7261
-- UPDATE `creature` SET `modelid`=0 WHERE `guid`=32333; 4.x removed


-- 4.x - That npc no longer sells these items
-- Fix NPC Lhara, from Darkmoon Faire author Mick3y16 Closes #6998
-- Fixes Artic Fur (90 minutes)
-- UPDATE `npc_vendor` SET `incrtime`=9000 WHERE `entry`=14846 AND `item`=44128;
-- Fixes the LK Gems (60 minutes)
-- UPDATE `npc_vendor` SET `incrtime`=3600 WHERE `entry`=14846 AND `ExtendedCost`=2484;
-- Fixes the BC Gems (60 minutes)
-- UPDATE `npc_vendor` SET `incrtime`=3600 WHERE `entry`=14846 AND `item` IN (23441,23440,23439,23438,23437,23436);
-- Fixes Black Lotus (30 minutes)
-- UPDATE `npc_vendor` SET `incrtime`=1800 WHERE `entry`=14846 AND `item`=13468;
-- Fixes The Rest (15 minutes)
-- UPDATE `npc_vendor` SET `incrtime`=900 WHERE `entry`=14846 AND `item` IN (36906,36905,36904,36903,36901,33568,25708,36907,36908,38425,37921,37705,37704,37703,37702,37701,37700,25707,21887,22572,22573,22574,22575,22576,22577,22578,4304,8170,2319,4234);

-- The Masters Terrace (9645) quest fix by nelegalno Closes #6855
UPDATE `creature_template` SET `InhabitType` = 4 WHERE `entry` = 17652;

DELETE FROM `event_scripts` WHERE `id`=10951;
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(10951,0,10,17651,300000,0,-11161,-1923.2,91.4737,2.89811);

-- Zeppelin: <The Purple Princess> author malcom Closes #6664
UPDATE `creature_transport` SET `emote`=173 WHERE `transport_entry`=176495 AND `npc_entry`=25101; -- Crewman Cutpipe
UPDATE `creature_transport` SET `emote`=133 WHERE `transport_entry`=176495 AND `npc_entry`=25102; -- Crewman Spinshaft
UPDATE `creature_transport` SET `emote`=173 WHERE `transport_entry`=176495 AND `npc_entry`=25103; -- Crewman Boltshine
UPDATE `creature_model_info` SET `modelid_other_gender`=0 WHERE `modelid`=4083; -- Watcher Umjin should only have a male model
UPDATE `creature_model_info` SET `modelid_other_gender`=0 WHERE `modelid`=4084; -- Watcher Du'una should only have a female model
DELETE FROM `creature_template_addon` WHERE `entry`=25107;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(25107,0,0,3,1,0, ''); -- STATE_SLEEP
-- Zeppelin: <Iron Eagle>
UPDATE `creature_model_info` SET `modelid_other_gender`=0 WHERE `modelid`=4259; -- Grunt Umgor should only have a male model
UPDATE `creature_transport` SET `TransOffsetX`=-10.3057, `TransOffsetY`=-12.10524, `TransOffsetZ`=-16.96907, `TransOffsetO`=5.927236 WHERE `transport_entry`=175080 AND`npc_entry`=24926; -- Chief Officer Brassbolt
UPDATE `creature_transport` SET `emote`=133 WHERE `transport_entry`=175080 AND `npc_entry`=24931; -- Crewman Fastwrench
DELETE FROM `creature_transport` WHERE `transport_entry`=175080 AND `npc_entry` IN (24927,24929,24930);
INSERT INTO `creature_transport` (`guid`,`transport_entry`,`npc_entry`,`TransOffsetX`,`TransOffsetY`,`TransOffsetZ`,`TransOffsetO`,`emote`) VALUES
(3,175080,24927,-1.874165,-7.847112,-23.68718,3.385939,0), -- Navigator Sparksizzle
(4,175080,24929,9.083008,-4.964111,-23.59211,1.594056,133), -- Crewman Crosswire
(5,175080,24930,-17.0083,-7.874878,-15.18782,3.141593,133); -- Crewman Gazzlegear
-- Zeppelin: <The Cloudkisser>
-- Deleting some NPCs that are double spawned out of the zeppelin. They are already spawned by `creature_transport` table
DELETE FROM `creature` WHERE `guid` IN (
116702, -- Crewman Coilspan
116703, -- Crewman Coilspan
117715, -- Deathguard Hicks
117750 ); -- Sky-Captain Cryoflight
UPDATE `creature_transport` SET `npc_entry`=31715 WHERE `guid`=3 AND `transport_entry`=181689; -- Deathguard Hicks
UPDATE `creature_transport` SET `emote`=133 WHERE `transport_entry`=181689 AND `npc_entry`=31704; -- Crewman Spinwheel
UPDATE `creature_transport` SET `emote`=133 WHERE `transport_entry`=181689 AND `npc_entry`=31705; -- Crewman Coilspan
UPDATE `creature_transport` SET `emote`=133, `TransOffsetO`=4.64346 WHERE `transport_entry`=181689 AND`npc_entry`=31706; -- Crewman Stembolt
DELETE FROM `creature_transport` WHERE `transport_entry`=181689 AND `npc_entry`=25075; -- Zeppelin Controls
INSERT INTO `creature_transport` (`guid`,`transport_entry`,`npc_entry`,`TransOffsetX`,`TransOffsetY`,`TransOffsetZ`,`TransOffsetO`,`emote`) VALUES
(7,181689,25075,4.362147,-2.254167,-23.59002,4.712389,0); -- Zeppelin Controls
UPDATE `creature_template` SET `exp`=2 WHERE `entry`=31708; -- Deathguard Barth
-- Zeppelin: <The Mighty Wind>
UPDATE `creature_model_info` SET `gender`=0, `modelid_other_gender`=0 WHERE `modelid`=4601; -- Grunt Gritch should only have a male model
UPDATE `creature_model_info` SET `gender`=1, `modelid_other_gender`=0 WHERE `modelid`=4602; -- Grunt Grikee should only have a female model
UPDATE `creature_transport` SET `TransOffsetO`=1.16964 WHERE `transport_entry`=186238 AND `npc_entry`=31726; -- Grunt Gritch orientation
UPDATE `creature_transport` SET `TransOffsetO`=5.47991 WHERE `transport_entry`=186238 AND `npc_entry`=31727; -- Grunt Grikee orientation
UPDATE `creature_transport` SET `emote`=133 WHERE `transport_entry`=186238 AND `npc_entry`=31720; -- Crewman Shubbscoop
UPDATE `creature_transport` SET `emote`=133 WHERE `transport_entry`=186238 AND `npc_entry`=31723; -- Crewman Barrowswizzle
UPDATE `creature_transport` SET `emote`=133 WHERE `transport_entry`=186238 AND `npc_entry`=31724; -- Crewman Paltertop
-- Zeppelin: <The Thundercaller>
UPDATE `creature_transport` SET `emote`=133 WHERE `transport_entry`=164871 AND `npc_entry`=25071; -- Crewman Rusthammer
UPDATE `creature_transport` SET `emote`=133 WHERE `transport_entry`=164871 AND `npc_entry`=25072; -- Crewman Quickfix
UPDATE `creature_transport` SET `emote`=133 WHERE `transport_entry`=164871 AND `npc_entry`=25074; -- Crewman Sparkfly
DELETE FROM `creature_transport` WHERE `transport_entry`=164871 AND `npc_entry`=25077; -- Sky-Captain Cloudkicker
INSERT INTO `creature_transport` (`guid`,`transport_entry`,`npc_entry`,`TransOffsetX`,`TransOffsetY`,`TransOffsetZ`,`TransOffsetO`,`emote`) VALUES
(18,164871,25077,-19.68856,-8.170582,-14.37648,3.176499,0); -- Sky-Captain Cloudkicker
-- Zeppelin: <The Zephyr>
UPDATE `creature_transport` SET `emote`=173 WHERE `transport_entry`=190549 AND `npc_entry`=34719; 

-- Fix flight masters around the Dark Portal in Outland (16.11.2011) by SignFinder ( https://github.com/TrinityCore/TrinityCore/issues/2596#issuecomment-4450115 ) Closes #6401

-- Vlagga Freyfeather SAI
SET @NPC := 18930;
SET @GOSSIP_VLAGGA := 7938;
SET @SPELL_STAIR_OF_DESTINY_THRALLMAR := 34924;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id` =@NPC; 4.x
UPDATE `creature_template` SET `AIName`= "SmartAI" WHERE `entry` =@NPC;
DELETE FROM `smart_scripts` WHERE `entryorguid` =@NPC;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC,0,0,0,62,0,100,0,@GOSSIP_VLAGGA,1,0,0,11,@SPELL_STAIR_OF_DESTINY_THRALLMAR,2,0,0,0,0,7,0,0,0,0,0,0,0,"Vlagga Freyfeather - On Gossip Select - Cast Stair of Destiny to Thrallmar"),
(@NPC,0,1,2,4,0,100,0,0,0,0,0,12,9297,4,30000,0,0,0,1,0,0,0,0,0,0,0,"Vlagga Freyfeather - On Aggro - Summon Enraged Wyvern"),
(@NPC,0,2,3,61,0,100,0,0,0,0,0,12,9297,4,30000,0,0,0,1,0,0,0,0,0,0,0,"Vlagga Freyfeather - On Aggro - Summon Enraged Wyvern"),
(@NPC,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vlagga Freyfeather - On Aggro - Say Line 0");

-- Amish Wildhammer SAI
SET @NPC := 18931;
SET @GOSSIP_AMISH := 7939;
SET @SPELL_STAIR_OF_DESTINY_HONOR_HOLD := 34907;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id` =@NPC; 4.x
UPDATE `creature_template` SET `AIName`= "SmartAI" WHERE `entry` =@NPC;
DELETE FROM `smart_scripts` WHERE `entryorguid` =@NPC;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC,0,0,0,62,0,100,0,@GOSSIP_AMISH,1,0,0,11,@SPELL_STAIR_OF_DESTINY_HONOR_HOLD,2,0,0,0,0,7,0,0,0,0,0,0,0,"Amish Wildhammer - On Gossip Select - Cast Stair of Destiny to Honor Hold"),
(@NPC,0,1,2,4,0,100,0,0,0,0,0,12,9526,4,30000,0,0,0,1,0,0,0,0,0,0,0,"Amish Wildhammer - On Aggro - Summon Enraged Gryphon"),
(@NPC,0,2,3,61,0,100,0,0,0,0,0,12,9526,4,30000,0,0,0,1,0,0,0,0,0,0,0,"Amish Wildhammer - On Aggro - Summon Enraged Gryphon"),
(@NPC,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amish Wildhammer - On Aggro - Say Line 0");

-- Gossip inserts
DELETE FROM `gossip_menu` WHERE `entry`=@GOSSIP_AMISH;
DELETE FROM `npc_text` WHERE `ID` IN (9935,9991);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (@GOSSIP_AMISH,10052);
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (@GOSSIP_AMISH,@GOSSIP_VLAGGA);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP_AMISH,0,2,"Show me where I can fly.",4,8192,0,0,0,0,''),
(@GOSSIP_AMISH,1,2,"Send me to Honor Hold!",4,8192,0,0,0,0,''),
(@GOSSIP_VLAGGA,0,2,"Show me where I can fly.",4,8192,0,0,0,0,''),
(@GOSSIP_VLAGGA,1,2,"Send me to Thrallmar!",4,8192,0,0,0,0,'');

-- Gossip conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (@GOSSIP_AMISH,@GOSSIP_VLAGGA);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@GOSSIP_AMISH,0,0,0,8,10140,0,0,0,'',"Show gossip option 0 if player has rewarded quest Journey to Honor Hold"),
(15,@GOSSIP_AMISH,1,0,0,28,10140,0,0,0,'',"Show gossip option 1 if player has complete quest Journey to Honor Hold"),
(15,@GOSSIP_VLAGGA,0,0,0,8,10289,0,0,0,'',"Show gossip option 0 if player has rewarded quest Journey to Thrallmar"),
(15,@GOSSIP_VLAGGA,1,0,0,28,10289,0,0,0,'',"Show gossip option 1 if player has complete quest Journey to Thrallmar");

-- fix dedication of honor movie playback. author trista and vincent-michael. Closes 	#5754
SET @MEMORIAL := 202443;
SET @Script := 20244300;
UPDATE `gameobject_template` SET AIName = 'SmartGameObjectAI' WHERE entry = @MEMORIAL;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@MEMORIAL);
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@Script;
INSERT INTO `smart_scripts` VALUES
(@MEMORIAL,1,0,0,62,0,100,0,11431,0,0,0,80,@Script,0,0,0,0,0,1,0,0,0,0,0,0,0,'Memorial - On gossip select - Run Script'),
(@Script,9,0,0,0,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Actionlist - On action 0 - Close gossip'),
(@Script,9,1,0,0,0,100,0,0,0,0,0,68,16,0,0,0,0,0,7,0,0,0,0,0,0,0,'Actionlist - On action 1 - Startmovie');
-- SET @OGUID := 342; 4.x - Already added (guid 80)

-- DELETE FROM `gameobject` WHERE `id`=@MEMORIAL;
-- INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
-- (@OGUID,@MEMORIAL,571,1,1,5804.526,638.5417,647.6481,2.460913,0,0,0,1,120,255,1); -- Dedication of Honor

-- Add immune to interrupt for hodir & ignis AUTHOR gecko32 Closes #5617
UPDATE `creature_template` SET `mechanic_immune_mask` = `mechanic_immune_mask`|1|2|4|8|16|64|256|512|1024|2048|4096|8192|65536|131072|524288|4194304|8388608|33554432|67108864|536870912 WHERE `entry` IN (32845,32846,33118,33190);

-- Leader of the Deranged ID: 11240 - adds spawn and SAI author trista Closes #5556
SET @GUID := 46; -- 4.x
SET @ID := 24048;
SET @Dynamite := 7978;
-- Add spawn
DELETE FROM `creature` WHERE `id`=@ID;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `MovementType`) VALUES
(@GUID, @ID, 571, 1, 3, 1742.082764, -3339.336426, 79.993713, 2.515936, 120, 20, 0, 1);
-- Add simple SAI for Squeeg Idolhunter
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ID;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ID;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,1,0,0,0,100,0,2000,6000,12000,15000,11,@Dynamite,0,0,0,0,0,2,0,0,0,0,0,0,0,'Combat - Throw Dynamite');

-- Gnomish Army Knife Resurrection (54732) is restricted to Grand Master Engineers (51306) author mweinelt Closes #5415
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` = 54732 LIMIT 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 54732, 0, 0, 25, 0, 51306, 0, 0, 0, 0, '', 'Only Grand-Masters in Engineering can use the Gnomish Army Knife to resurrect players.');

-- Add Pint-Sized Pink Pachyderm to Brewfest vendors author Exodius Closes #4907
SET @PINT := 46707; -- Pint-Sized Pink Pachyderm
DELETE FROM `npc_vendor` WHERE `item`=@PINT;
INSERT INTO `npc_vendor` (`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`) VALUES
(23710,0,@PINT,0,0,2275), -- Vendor Belbi Quikswitch
(24495,0,@PINT,0,0,2275), -- Vendor Blix Fixwidget
(27478,0,@PINT,0,0,2275), -- Vendor Larkin Thunderbrew
(27489,0,@PINT,0,0,2275); -- Vendor Rayma

-- Kalu'ak Fishing Derby start time fix ( http://old.wowhead.com/event=424 ) author neglanalgo Closes #4743 Closes #4717
UPDATE `game_event` SET `start_time` = '2012-01-07 14:00:00' WHERE `eventEntry` = 64;
UPDATE `game_event` SET `start_time` = '2012-01-07 13:00:00' WHERE `eventEntry` = 63;

-- Stranglethorn Fishing Extravaganza start time fix ( http://old.wowhead.com/event=301 )
UPDATE `game_event` SET `start_time` = '2012-01-01 14:00:00' WHERE `eventEntry` IN (15, 62);
UPDATE `game_event` SET `start_time` = '2012-01-01 00:00:00', `length` = 1440 WHERE `eventEntry` = 14; -- Grinkle and Barrus should appear before the event starts (1440=24h, currently set to 27h from event start)

-- [QUEST] All Along The Watchtowers author valcorb and kaelima Closes #4637
-- SET @GUID := 5282;
SET @ENTRY := 300030;
SET @NEWENTRY := 176095;
UPDATE `gameobject_template` SET `entry`=@NEWENTRY WHERE `entry`=@ENTRY;
-- 4.x - removed
-- DELETE FROM `gameobject` WHERE `id` IN (@ENTRY,@NEWENTRY) OR `guid` BETWEEN @GUID+0 AND @GUID+3;
-- INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
-- (@GUID  ,@NEWENTRY,0,1,1,1308.24 ,-1303.41 ,64.3047 ,4.15194,0,0,0.875091,-0.483959,300,0,1),
-- (@GUID+1,@NEWENTRY,0,1,1,1473.977,-1409.814,67.76421,5.60571,0,0,0.332297,-0.943175,300,0,1),
-- (@GUID+2,@NEWENTRY,0,1,1,1560.28 ,-1485.03 ,68.3929 ,1.36456,0,0,0.630563, 0.776138,300,0,1),
-- (@GUID+3,@NEWENTRY,0,1,1,1327.56 ,-1581.53 ,61.7238 ,3.42781,0,0,0.989778,-0.14262 ,300,0,1);

-- [NPC] Fix behaviour of Scarlet Peasant author Valcorb Closes #3925
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=28557;
DELETE FROM `smart_scripts` WHERE `entryorguid`=28557 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`)
VALUES
(28557, 0, 0, 0, 2, 0, 20, 1, 0, 20, 1, 1, 1, 0, 10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'At 0-20% hp- say text'),
(28557, 0, 1, 0, 2, 0, 20, 1, 0, 20, 1, 1, 1, 1, 10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'At 0-20% hp- say text'),
(28557, 0, 2, 0, 2, 0, 20, 1, 0, 20, 1, 1, 1, 2, 10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'At 0-20% hp- say text'),
(28557, 0, 3, 0, 2, 0, 20, 1, 0, 20, 1, 1, 1, 3, 10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'At 0-20% hp- say text'),
(28557, 0, 4, 0, 2, 0, 20, 1, 0, 20, 1, 1, 1, 4, 10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'At 0-20% hp- say text');

DELETE FROM `creature_text` WHERE `entry`=28557 AND `probability`=100;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`)
VALUES
(28557, 0, 0, 'Ungh! I ... I think I pooped...', 12, 0, 100, 0, 0, 0, 'Scarlet Peasant'),
(28557, 0, 1, 'I... I have a sick grandmother at home... I--I''m all she''s got.', 12, 0, 100, 0, 0, 0, 'Scarlet Peasant'),
(28557, 0, 2, 'I picked the wrong week to quit drinkin''!', 12, 0, 100, 0, 0, 0, 'Scarlet Peasant'),
(28557, 0, 3, 'I''ve got five kids lady, they''ll die without me!', 12, 0, 100, 0, 0, 0, 'Scarlet Peasant'),
(28557, 0, 4, 'You don''t have to do this! Nobody has to die!', 12, 0, 100, 0, 0, 0, 'Scarlet Peasant');

-- Cast Terrified! when Citizen of New Avalon enters combat author Valcorb Closes #3734
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (28941,28942);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (28941, 28942);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28941, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 52716, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Citizen of New Avalon 1 - if enter combat - fear'),
(28942, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 52716, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Citizen of New Avalon 2 - if enter combat - fear');

-- Credit fix for stinking up southshore 1657 author Norfik Closes #3552
DELETE FROM `event_scripts` WHERE `id`=9417;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(9417, 3, 8, 15415, 0, 0, 0, 0, 0, 0);

-- Alexstrasza and Korialstrasz author vlomax Closes #7746
SET @PHASE := 2;
SET @GGUID := 87978; -- 4.x
-- Plants & flames
DELETE FROM `gameobject` WHERE `id` BETWEEN 193196 AND 193198 OR `id` BETWEEN 193220 AND 193386 OR `id` BETWEEN 193388 AND 193393 OR `id` BETWEEN 193396 AND 193399 OR `guid` BETWEEN @GGUID AND @GGUID+181;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@GGUID+0,193196, 571, 1, @PHASE, 4840.929, 1494.97, 209.6041, 2.103119, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+1,193197, 571, 1, @PHASE, 4875.424, 1486.991, 209.5768, 2.120576, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+2,193198, 571, 1, @PHASE, 4875.969, 1487.23, 209.6242, 5.707228, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+3,193220, 571, 1, @PHASE, 4901.706, 1501.568, 214.8973, 0.0005237369, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+4,193221, 571, 1, @PHASE, 4899.952, 1499.167, 214.9082, 5.41925, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+5,193223, 571, 1, @PHASE, 4867.679, 1501.424, 209.7898, 0.969179, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+6,193225, 571, 1, @PHASE, 4869.894, 1498.136, 209.9754, 2.077466, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+7,193229, 571, 1, @PHASE, 4899.046, 1500.026, 213.7757, 4.281601, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+8,193222, 571, 1, @PHASE, 4867.967, 1505.212, 209.1965, 1.82941, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+9,193224, 571, 1, @PHASE, 4867.233, 1510.344, 210.8179, 2.48454, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+10,193228, 571, 1, @PHASE, 4867.919, 1513.521, 211.374, 4.224219, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+11,193227, 571, 1, @PHASE, 4872.966, 1514.59, 212.3312, 4.885982, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+12,193226, 571, 1, @PHASE, 4868.827, 1515.047, 210.5834, 1.567609, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+13,193230, 571, 1, @PHASE, 4875.33, 1483.97, 209.321, 1.099933, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+14,193231, 571, 1, @PHASE, 4875.167, 1482.726, 209.5813, 3.899255, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+15,193232, 571, 1, @PHASE, 4873.677, 1479.37, 209.2619, 6.044956, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+16,193233, 571, 1, @PHASE, 4878.027, 1483.453, 209.3674, 3.726801, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+17,193234, 571, 1, @PHASE, 4874.569, 1482.123, 209.5809, 5.821372, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+18,193235, 571, 1, @PHASE, 4874.725, 1480.063, 209.5809, 3.477762, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+19,193236, 571, 1, @PHASE, 4877.155, 1482.281, 209.5077, 6.219547, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+20,193237, 571, 1, @PHASE, 4879.968, 1484.747, 209.8505, 4.501981, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+21,193238, 571, 1, @PHASE, 4876.323, 1484.97, 208.3138, 2.230834, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+22,193239, 571, 1, @PHASE, 4877.1, 1484.656, 209.1863, 2.269449, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+23,193240, 571, 1, @PHASE, 4871.932, 1485.224, 209.3937, 1.457871, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+24,193241, 571, 1, @PHASE, 4868.574, 1498.977, 210.52, 0.1396255, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+25,193242, 571, 1, @PHASE, 4868.924, 1496.627, 210.149, 3.220151, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+26,193243, 571, 1, @PHASE, 4866.884, 1497.613, 209.2193, 5.581869, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+27,193244, 571, 1, @PHASE, 4870.409, 1485.929, 208.8148, 2.012669, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+28,193245, 571, 1, @PHASE, 4873.674, 1463.747, 209.9446, 1.692968, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+29,193246, 571, 1, @PHASE, 4867.43, 1463.248, 208.1823, 3.382769, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+30,193247, 571, 1, @PHASE, 4870.533, 1463.094, 209.2539, 2.985031, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+31,193248, 571, 1, @PHASE, 4872.965, 1463.778, 208.817, 0.3284273, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+32,193249, 571, 1, @PHASE, 4866.135, 1454.382, 209.254, 2.906489, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+33,193250, 571, 1, @PHASE, 4863.497, 1511.99, 211.0073, 5.427976, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+34,193251, 571, 1, @PHASE, 4862.127, 1509.542, 210.2737, 4.765272, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+35,193252, 571, 1, @PHASE, 4865.178, 1507.217, 210.3379, 5.044526, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+36,193253, 571, 1, @PHASE, 4853.508, 1504.255, 209.7053, 1.998924, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+37,193254, 571, 1, @PHASE, 4849.161, 1504.778, 210.4205, 4.066619, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+38,193255, 571, 1, @PHASE, 4835.896, 1488.719, 209.5815, 3.416903, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+39,193256, 571, 1, @PHASE, 4841.354, 1482.227, 209.5805, 1.850049, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+40,193257, 571, 1, @PHASE, 4841.196, 1489.903, 209.5813, 5.725396, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+41,193258, 571, 1, @PHASE, 4840.608, 1484.361, 209.5813, 2.016231, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+42,193259, 571, 1, @PHASE, 4839.124, 1486.542, 209.2619, 1.978337, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+43,193260, 571, 1, @PHASE, 4843.821, 1489.113, 209.283, 5.184155, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+44,193261, 571, 1, @PHASE, 4842.286, 1483.191, 209.5809, 0.3759405, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+45,193262, 571, 1, @PHASE, 4845.386, 1486.806, 209.4725, 1.254085, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+46,193263, 571, 1, @PHASE, 4835.046, 1490.908, 209.2909, 1.831047, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+47,193264, 571, 1, @PHASE, 4838.369, 1493.165, 209.3897, 2.568887, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+48,193265, 571, 1, @PHASE, 4842.897, 1491.009, 209.5809, 5.959332, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+49,193266, 571, 1, @PHASE, 4844.97, 1489.892, 209.3359, 3.932379, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+50,193267, 571, 1, @PHASE, 4847.749, 1488.823, 209.301, 5.789437, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+51,193268, 571, 1, @PHASE, 4841.975, 1486.234, 209.4944, 5.791942, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+52,193269, 571, 1, @PHASE, 4844.339, 1484.116, 209.4908, 3.889533, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+53,193270, 571, 1, @PHASE, 4840.96, 1481.422, 209.4966, 4.98909, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+54,193271, 571, 1, @PHASE, 4844.502, 1486.135, 209.3802, 1.443149, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+55,193272, 571, 1, @PHASE, 4836.853, 1488.425, 209.4966, 3.060501, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+56,193273, 571, 1, @PHASE, 4844.616, 1493.514, 209.3608, 3.11481, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+57,193274, 571, 1, @PHASE, 4847.851, 1486.434, 209.3608, 1.151302, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+58,193275, 571, 1, @PHASE, 4841.349, 1488.082, 208.3138, 3.749274, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+59,193276, 571, 1, @PHASE, 4842.697, 1487.741, 209.3854, 3.587177, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+60,193277, 571, 1, @PHASE, 4847.485, 1488.835, 207.9903, 0.485505, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+61,193278, 571, 1, @PHASE, 4856.974, 1498.668, 210.0112, 5.593781, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+62,193279, 571, 1, @PHASE, 4860.162, 1499.833, 209.4969, 5.515764, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+63,193280, 571, 1, @PHASE, 4862.285, 1462.604, 209.3651, 4.037887, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+64,193281, 571, 1, @PHASE, 4862.758, 1457.965, 209.9445, 0.4537852, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+65,193282, 571, 1, @PHASE, 4859.121, 1463.345, 209.3854, 5.777565, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+66,193283, 571, 1, @PHASE, 4861.292, 1455.554, 209.3854, 5.742657, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+67,193284, 571, 1, @PHASE, 4865.374, 1460.495, 209.1164, 0.3146807, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+68,193285, 571, 1, @PHASE, 4865.479, 1453.684, 209.7114, 5.969027, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+69,193286, 571, 1, @PHASE, 4840.913, 1402.094, 192.9591, 5.131985, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+70,193287, 571, 1, @PHASE, 4837.317, 1400.465, 192.6397, 1.384923, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+71,193288, 571, 1, @PHASE, 4842.942, 1402.059, 192.9587, 5.365919, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+72,193289, 571, 1, @PHASE, 4836.487, 1403.299, 192.8744, 2.467085, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+73,193290, 571, 1, @PHASE, 4840.022, 1400.498, 191.6916, 3.15663, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+74,193291, 571, 1, @PHASE, 4854.309, 1417.488, 193.4538, 2.059487, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+75,193292, 571, 1, @PHASE, 4848.659, 1414.785, 191.6916, 3.749274, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+76,193293, 571, 1, @PHASE, 4852.316, 1415.811, 192.7632, 2.889032, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+77,193394, 571, 1, @PHASE, 4822.109, 1385.169, 190.8455, 0.5934095, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+78,193294, 571, 1, @PHASE, 4856.42, 1416.295, 192.7632, 1.702218, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+79,193395, 571, 1, @PHASE, 4770.155, 1370.927, 176.3797, 2.809977, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+80,193295, 571, 1, @PHASE, 4838.964, 1398.37, 192.9591, 1.928963, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+81,193296, 571, 1, @PHASE, 4842.648, 1399.972, 192.6608, 4.590742, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+82,193297, 571, 1, @PHASE, 4842.655, 1397.182, 192.8535, 0.6606718, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+83,193298, 571, 1, @PHASE, 4844.037, 1399.976, 192.7137, 3.338978, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+84,193299, 571, 1, @PHASE, 4844.027, 1397.335, 192.6788, 4.733513, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+85,193300, 571, 1, @PHASE, 4839.507, 1398.616, 192.8744, 5.198529, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+86,193301, 571, 1, @PHASE, 4840.949, 1399.462, 192.7632, 2.993751, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+87,193302, 571, 1, @PHASE, 4844.576, 1399.304, 191.3681, 5.878576, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+88,193303, 571, 1, @PHASE, 4819.022, 1437.061, 195.9568, 0.7853968, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+89,193304, 571, 1, @PHASE, 4814.786, 1441.675, 193.9325, 2.475178, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+90,193305, 571, 1, @PHASE, 4816.835, 1438.477, 195.4229, 1.614948, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+91,193306, 571, 1, @PHASE, 4818.494, 1434.955, 194.9861, 6.227641, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+92,193307, 571, 1, @PHASE, 4804.619, 1464.389, 193.2142, 0.8726636, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+93,193308, 571, 1, @PHASE, 4802.317, 1465.608, 192.5236, 1.702218, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+94,193309, 571, 1, @PHASE, 4838.382, 1400.665, 192.9736, 0.165805, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+95,193310, 571, 1, @PHASE, 4804.275, 1462.243, 192.1949, 0.03171997, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+96,193311, 571, 1, @PHASE, 4818.627, 1432.585, 195.6188, 0.7931821, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+97,193312, 571, 1, @PHASE, 4818.935, 1434.288, 194.9375, 6.100451, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+98,193313, 571, 1, @PHASE, 4802.595, 1414.417, 193.2174, 5.02655, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+99,193314, 571, 1, @PHASE, 4808.629, 1416.099, 191.6722, 0.4331469, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+100,193315, 571, 1, @PHASE, 4805.602, 1422.391, 192.5222, 3.915716, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+101,193316, 571, 1, @PHASE, 4806.971, 1413.819, 192.5371, 0.8470061, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+102,193317, 571, 1, @PHASE, 4800.958, 1415.844, 192.1961, 4.185608, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+103,193318, 571, 1, @PHASE, 4814.53, 1421.677, 193.837, 4.031712, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+104,193319, 571, 1, @PHASE, 4818.464, 1416.958, 192.3035, 0.1713461, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+105,193320, 571, 1, @PHASE, 4816.804, 1417.587, 192.5431, 2.827954, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+106,193321, 571, 1, @PHASE, 4813.185, 1424.823, 193.4423, 2.793048, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+107,193322, 571, 1, @PHASE, 4810.121, 1419.193, 193.3252, 3.648265, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+108,193323, 571, 1, @PHASE, 4807.363, 1428.156, 193.9222, 3.0194, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+109,193324, 571, 1, @PHASE, 4806.887, 1426.839, 192.9712, 0.3234065, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+110,193325, 571, 1, @PHASE, 4822.01, 1384.936, 193.2164, 4.05789, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+111,193326, 571, 1, @PHASE, 4821.838, 1389.484, 192.8276, 1.342961, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+112,193327, 571, 1, @PHASE, 4826.813, 1380.915, 191.5601, 5.747677, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+113,193328, 571, 1, @PHASE, 4824.364, 1383.818, 192.6317, 4.887444, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+114,193329, 571, 1, @PHASE, 4822.135, 1389.366, 192.6317, 3.831524, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+115,193330, 571, 1, @PHASE, 4823.995, 1380.991, 192.6317, 6.161535, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+116,193331, 571, 1, @PHASE, 4822.26, 1387.094, 192.1949, 3.21697, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+117,193332, 571, 1, @PHASE, 4799.996, 1468.615, 191.452, 2.562449, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+118,193333, 571, 1, @PHASE, 4792.137, 1470.661, 193.0653, 6.161014, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+119,193334, 571, 1, @PHASE, 4794.401, 1474.757, 192.7633, 4.957259, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+120,193335, 571, 1, @PHASE, 4790.183, 1467.854, 192.762, 4.922352, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+121,193336, 571, 1, @PHASE, 4796.58, 1468.24, 192.1685, 5.777565, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+122,193337, 571, 1, @PHASE, 4784.452, 1470.938, 192.9553, 4.127707, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+123,193338, 571, 1, @PHASE, 4784.479, 1470.891, 192.5763, 0.9255483, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+124,193339, 571, 1, @PHASE, 4772.658, 1434.781, 193.2318, 3.691376, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+125,193340, 571, 1, @PHASE, 4774.897, 1439.738, 192.737, 3.725339, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+126,193341, 571, 1, @PHASE, 4775.096, 1434.278, 192.5412, 4.040963, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+127,193342, 571, 1, @PHASE, 4796.264, 1462.712, 192.9666, 6.045015, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+128,193343, 571, 1, @PHASE, 4790.44, 1461.151, 192.981, 5.148722, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+129,193344, 571, 1, @PHASE, 4791.811, 1461.446, 192.6317, 2.452708, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+130,193345, 571, 1, @PHASE, 4796.167, 1458.012, 192.8273, 4.96452, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+131,193346, 571, 1, @PHASE, 4778.761, 1431.167, 191.4696, 5.21535, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+132,193347, 571, 1, @PHASE, 4772.64, 1435.917, 192.8096, 5.940294, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+133,193348, 571, 1, @PHASE, 4774.135, 1431.061, 192.5412, 5.821197, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+134,193349, 571, 1, @PHASE, 4772.312, 1368.96, 179.3861, 0.8115751, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+135,193350, 571, 1, @PHASE, 4768.762, 1368.182, 178.913, 1.444671, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+136,193351, 571, 1, @PHASE, 4768.806, 1368.814, 178.492, 0.1401508, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+137,193352, 571, 1, @PHASE, 4773.032, 1368.717, 178.4498, 6.18401, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+138,193353, 571, 1, @PHASE, 4769.212, 1371.894, 177.5704, 3.96744, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+139,193354, 571, 1, @PHASE, 4753.28, 1340.752, 168.824, 5.942847, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+140,193355, 571, 1, @PHASE, 4755.793, 1348.842, 171.9237, 2.460914, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+141,193356, 571, 1, @PHASE, 4748.543, 1338.941, 166.3824, 5.994266, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+142,193357, 571, 1, @PHASE, 4755.62, 1346.563, 169.7958, 1.349443, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+143,193358, 571, 1, @PHASE, 4753.616, 1343.335, 168.9523, 0.4892147, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+144,193359, 571, 1, @PHASE, 4756.417, 1343.859, 170.2456, 1.763303, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+145,193360, 571, 1, @PHASE, 4751.151, 1340.321, 166.6075, 5.101904, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+146,193361, 571, 1, @PHASE, 4734.48, 1318.531, 157.1364, 1.850571, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+147,193362, 571, 1, @PHASE, 4729.611, 1321.644, 157.5598, 3.769916, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+148,193363, 571, 1, @PHASE, 4730.31, 1318.991, 155.5435, 4.299054, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+149,193364, 571, 1, @PHASE, 4730.522, 1317.274, 156.2261, 2.566151, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+150,193365, 571, 1, @PHASE, 4845.421, 1487.394, 209.5798, 3.621566, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+151,193366, 571, 1, @PHASE, 4873.986, 1482.95, 209.5806, 2.321287, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+152,193367, 571, 1, @PHASE, 4877.768, 1484.813, 209.6253, 0.9861118, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+153,193368, 571, 1, @PHASE, 4843.112, 1399.606, 192.9736, 4.04044, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+154,193369, 571, 1, @PHASE, 4733.987, 1316.142, 156.3821, 4.214973, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+155,193370, 571, 1, @PHASE, 4771.53, 1370.231, 177.6764, 3.473215, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+156,193371, 571, 1, @PHASE, 4747.052, 1371.73, 174.6061, 3.272515, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+157,193372, 571, 1, @PHASE, 4745.647, 1372.851, 180.6194, 0.2879769, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+158,193373, 571, 1, @PHASE, 4748.801, 1370.48, 177.2103, 1.125736, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+159,193374, 571, 1, @PHASE, 4739.766, 1375.458, 175.0408, 5.899213, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+160,193375, 571, 1, @PHASE, 4747.372, 1376.691, 177.1419, 4.241152, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+161,193376, 571, 1, @PHASE, 4729.662, 1338.746, 165.7118, 1.483528, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+162,193377, 571, 1, @PHASE, 4724.683, 1339.089, 165.6361, 0.9512024, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+163,193378, 571, 1, @PHASE, 4722.371, 1315.175, 153.0163, 4.712391, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+164,193379, 571, 1, @PHASE, 4722.186, 1312.745, 151.8177, 2.207837, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+165,193380, 571, 1, @PHASE, 4721.955, 1313.016, 155.3777, 4.267334, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+166,193381, 571, 1, @PHASE, 4828.909, 1364.957, 187.7651, 3.141593, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+167,193382, 571, 1, @PHASE, 4767.654, 1414.143, 182.9588, 3.141593, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+168,193383, 571, 1, @PHASE, 4885.875, 1446.399, 197.2411, 3.141593, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+169,193384, 571, 1, @PHASE, 4967.423, 1382.576, 280.6783, 3.141593, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+170,193385, 571, 1, @PHASE, 4819.641, 1494.38, 197.8983, 3.141593, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+171,193386, 571, 1, @PHASE, 4760.751, 1331.356, 166.7298, 1.483529, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+172,193388, 571, 1, @PHASE, 4841.913, 1491.074, 209.5806, 5.026549, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+173,193389, 571, 1, @PHASE, 4854.66, 1501.157, 209.4814, 2.347464, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+174,193390, 571, 1, @PHASE, 4867.81, 1503.073, 209.8845, 4.398232, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+175,193391, 571, 1, @PHASE, 4806.318, 1418.541, 192.7293, 3.996809, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+176,193392, 571, 1, @PHASE, 4809.103, 1418.015, 192.8921, 1.754055, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+177,193393, 571, 1, @PHASE, 4866.126, 1504.92, 209.6104, 3.586657, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+178,193396, 571, 1, @PHASE, 4794.685, 1457.065, 192.5883, 2.644167, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+179,193397, 571, 1, @PHASE, 4733.944, 1315.556, 156.3676, 5.009097, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+180,193398, 571, 1, @PHASE, 4848.95, 1412.977, 192.9511, 4.468044, 0, 0, 0, 1, 120, 255, 1),
(@GGUID+181,193399, 571, 1, @PHASE, 4859.428, 1457.759, 209.3438, 3.168109, 0, 0, 0, 1, 120, 255, 1);

-- Corpses
SET @DGUID := 218221; -- 4.x
DELETE FROM `creature` WHERE `id` IN (31285,31291,31292,31293,31294,31295,31296,31297,31298,31299,31308,31309,31333,31334) OR `guid` BETWEEN @DGUID+0 AND @DGUID+106;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@DGUID+0, 31285, 571, 1, @PHASE, 4810.068, 1433.69, 195.6479, 5.305801, 120, 0, 0),
(@DGUID+1, 31285, 571, 1, @PHASE, 4806.54, 1410.767, 193.0403, 2.216568, 120, 0, 0),
(@DGUID+2, 31285, 571, 1, @PHASE, 4777.13, 1381.836, 183.996, 4.852015, 120, 0, 0),
(@DGUID+3, 31285, 571, 1, @PHASE, 4789.429, 1353.953, 179.1624, 0.3490658, 120, 0, 0),
(@DGUID+4, 31285, 571, 1, @PHASE, 4763.894, 1359.176, 177.5973, 0.1570796, 120, 0, 0),
(@DGUID+5, 31285, 571, 1, @PHASE, 4774.729, 1312.329, 165.0715, 5.5676, 120, 0, 0),
(@DGUID+6, 31285, 571, 1, @PHASE, 4756.614, 1313.47, 163.9544, 2.949606, 120, 0, 0),
(@DGUID+7, 31291, 571, 1, @PHASE, 4978.657, 1384.775, 284.3949, 2.076942, 120, 0, 0),
(@DGUID+8, 31291, 571, 1, @PHASE, 4984.935, 1394.382, 284.4201, 2.548181, 120, 0, 0),
(@DGUID+9, 31291, 571, 1, @PHASE, 5000.523, 1401.637, 284.4431, 2.094395, 120, 0, 0),
(@DGUID+10, 31291, 571, 1, @PHASE, 4990.958, 1400.277, 284.4431, 2.216568, 120, 0, 0),
(@DGUID+11, 31292, 571, 1, @PHASE, 4877.27, 1396.353, 196.93, 0.3316126, 120, 0, 0),
(@DGUID+12, 31292, 571, 1, @PHASE, 4891.048, 1415.103, 203.7862, 3.403392, 120, 0, 0),
(@DGUID+13, 31292, 571, 1, @PHASE, 4854.961, 1403.068, 193.1462, 2.792527, 120, 0, 0),
(@DGUID+14, 31292, 571, 1, @PHASE, 4806.509, 1352.567, 177.8115, 4.520403, 120, 0, 0),
(@DGUID+15, 31292, 571, 1, @PHASE, 4903.382, 1452.207, 211.9405, 4.223697, 120, 0, 0),
(@DGUID+16, 31292, 571, 1, @PHASE, 4869.447, 1468.438, 209.6567, 4.660029, 120, 0, 0),
(@DGUID+17, 31292, 571, 1, @PHASE, 4865.569, 1475.438, 209.6567, 3.438299, 120, 0, 0),
(@DGUID+18, 31292, 571, 1, @PHASE, 4850.112, 1476.327, 209.6567, 0.08726646, 120, 0, 0),
(@DGUID+19, 31292, 571, 1, @PHASE, 4908.861, 1484.187, 216.1365, 5.707227, 120, 0, 0),
(@DGUID+20, 31292, 571, 1, @PHASE, 4814.862, 1428.201, 195.6479, 4.363323, 120, 0, 0),
(@DGUID+21, 31292, 571, 1, @PHASE, 4881.099, 1509.474, 212.8491, 3.595378, 120, 0, 0),
(@DGUID+22, 31292, 571, 1, @PHASE, 4804.274, 1418.215, 193.1435, 2.932153, 120, 0, 0),
(@DGUID+23, 31292, 571, 1, @PHASE, 4806.403, 1468.882, 193.0345, 3.263766, 120, 0, 0),
(@DGUID+24, 31292, 571, 1, @PHASE, 4907.143, 1523.7, 219.6291, 0.08726646, 120, 0, 0),
(@DGUID+25, 31292, 571, 1, @PHASE, 4786.057, 1420.029, 193.0345, 5.288348, 120, 0, 0),
(@DGUID+26, 31292, 571, 1, @PHASE, 4833.672, 1526.136, 214.1294, 0.06981317, 120, 0, 0),
(@DGUID+27, 31292, 571, 1, @PHASE, 4917.417, 1531.887, 222.61, 6.178465, 120, 0, 0),
(@DGUID+28, 31292, 571, 1, @PHASE, 4761.258, 1368.303, 178.9943, 1.466077, 120, 0, 0),
(@DGUID+29, 31292, 571, 1, @PHASE, 4783.711, 1333.142, 172.5176, 0.8377581, 120, 0, 0),
(@DGUID+30, 31293, 571, 1, @PHASE, 4806.841, 1393.394, 193.0345, 3.735005, 120, 0, 0),
(@DGUID+31, 31293, 571, 1, @PHASE, 4841.265, 1541.912, 219.3147, 1.064651, 120, 0, 0),
(@DGUID+32, 31293, 571, 1, @PHASE, 4837.178, 1389.151, 193.0345, 4.590216, 120, 0, 0),
(@DGUID+33, 31293, 571, 1, @PHASE, 4859.151, 1419.09, 193.0345, 2.670354, 120, 0, 0),
(@DGUID+34, 31293, 571, 1, @PHASE, 4823.465, 1391.159, 193.0345, 5.201081, 120, 0, 0),
(@DGUID+35, 31293, 571, 1, @PHASE, 4856.67, 1389.393, 193.8499, 4.502949, 120, 0, 0),
(@DGUID+36, 31293, 571, 1, @PHASE, 4876.147, 1402.939, 196.7943, 2.775074, 120, 0, 0),
(@DGUID+37, 31293, 571, 1, @PHASE, 4873.234, 1453.22, 209.6567, 4.764749, 120, 0, 0),
(@DGUID+38, 31293, 571, 1, @PHASE, 4824.768, 1425.156, 195.6479, 4.939282, 120, 0, 0),
(@DGUID+39, 31293, 571, 1, @PHASE, 4846.874, 1446.988, 207.1275, 0.6981317, 120, 0, 0),
(@DGUID+40, 31293, 571, 1, @PHASE, 4830.034, 1436.004, 197.6899, 0.5235988, 120, 0, 0),
(@DGUID+41, 31293, 571, 1, @PHASE, 4857.192, 1462.829, 209.6567, 2.75762, 120, 0, 0),
(@DGUID+42, 31293, 571, 1, @PHASE, 4782.909, 1344.619, 174.218, 5.044002, 120, 0, 0),
(@DGUID+43, 31293, 571, 1, @PHASE, 4828.281, 1450.926, 202.2973, 1.012291, 120, 0, 0),
(@DGUID+44, 31293, 571, 1, @PHASE, 4786.116, 1405.732, 193.179, 5.794493, 120, 0, 0),
(@DGUID+45, 31293, 571, 1, @PHASE, 4779.775, 1390.742, 187.9587, 4.886922, 120, 0, 0),
(@DGUID+46, 31293, 571, 1, @PHASE, 4792.564, 1435.472, 193.046, 1.658063, 120, 0, 0),
(@DGUID+47, 31293, 571, 1, @PHASE, 4916.556, 1487.116, 220.1032, 5.305801, 120, 0, 0),
(@DGUID+48, 31293, 571, 1, @PHASE, 4922.137, 1497.21, 221.5407, 4.380776, 120, 0, 0),
(@DGUID+49, 31293, 571, 1, @PHASE, 4748.541, 1397.654, 180.7619, 5.550147, 120, 0, 0),
(@DGUID+50, 31293, 571, 1, @PHASE, 4828.431, 1497.15, 209.6567, 5.375614, 120, 0, 0),
(@DGUID+51, 31293, 571, 1, @PHASE, 4749.81, 1411.689, 182.592, 3.298672, 120, 0, 0),
(@DGUID+52, 31293, 571, 1, @PHASE, 4738.797, 1371.466, 175.4915, 2.373648, 120, 0, 0),
(@DGUID+53, 31293, 571, 1, @PHASE, 4886.754, 1523.797, 215.9392, 5.358161, 120, 0, 0),
(@DGUID+54, 31293, 571, 1, @PHASE, 4837.775, 1520.019, 212.4781, 0.6806784, 120, 0, 0),
(@DGUID+55, 31293, 571, 1, @PHASE, 4824.301, 1523.997, 213.3131, 2.827433, 120, 0, 0),
(@DGUID+56, 31294, 571, 1, @PHASE, 4830.872, 1392.478, 193.0345, 2.687807, 120, 0, 0),
(@DGUID+57, 31294, 571, 1, @PHASE, 4828.948, 1409.091, 193.2837, 1.064651, 120, 0, 0),
(@DGUID+58, 31294, 571, 1, @PHASE, 4815.367, 1395.433, 193.0345, 5.532694, 120, 0, 0),
(@DGUID+59, 31294, 571, 1, @PHASE, 4794.247, 1394.424, 193.1791, 6.038839, 120, 0, 0),
(@DGUID+60, 31294, 571, 1, @PHASE, 4802.3, 1399.704, 193.0345, 3.351032, 120, 0, 0),
(@DGUID+61, 31294, 571, 1, @PHASE, 4830.452, 1444.031, 200.6221, 5.410521, 120, 0, 0),
(@DGUID+62, 31294, 571, 1, @PHASE, 4768.52, 1380.417, 180.6092, 3.717551, 120, 0, 0),
(@DGUID+63, 31294, 571, 1, @PHASE, 4768.484, 1329.129, 170.6705, 0.2443461, 120, 0, 0),
(@DGUID+64, 31294, 571, 1, @PHASE, 4793.612, 1318.202, 166.5614, 0.8901179, 120, 0, 0),
(@DGUID+65, 31294, 571, 1, @PHASE, 4744.752, 1339.035, 165.5099, 5.218534, 120, 0, 0),
(@DGUID+66, 31295, 571, 1, @PHASE, 4849.039, 1415.038, 193.0345, 4.468043, 120, 0, 0),
(@DGUID+67, 31295, 571, 1, @PHASE, 4817.007, 1407.061, 193.0441, 3.036873, 120, 0, 0),
(@DGUID+68, 31295, 571, 1, @PHASE, 4865.909, 1465.047, 209.6567, 3.752458, 120, 0, 0),
(@DGUID+69, 31295, 571, 1, @PHASE, 4851.484, 1458.09, 209.8327, 2.775074, 120, 0, 0),
(@DGUID+70, 31295, 571, 1, @PHASE, 4795.949, 1342.791, 173.9115, 1.867502, 120, 0, 0),
(@DGUID+71, 31295, 571, 1, @PHASE, 4737.459, 1326.971, 160.5632, 3.001966, 120, 0, 0),
(@DGUID+72, 31296, 571, 1, @PHASE, 4852.959, 1470.127, 209.6567, 0.08726646, 120, 0, 0),
(@DGUID+73, 31296, 571, 1, @PHASE, 4817.938, 1436.592, 195.6479, 4.555309, 120, 0, 0),
(@DGUID+74, 31296, 571, 1, @PHASE, 4728.732, 1359.011, 170.9604, 3.403392, 120, 0, 0),
(@DGUID+75, 31297, 571, 1, @PHASE, 4797.594, 1448.583, 193.0345, 3.525565, 120, 0, 0),
(@DGUID+76, 31297, 571, 1, @PHASE, 4795.805, 1415.629, 193.0345, 1.134464, 120, 0, 0),
(@DGUID+77, 31297, 571, 1, @PHASE, 4769.275, 1367.561, 178.9943, 5.934119, 120, 0, 0),
(@DGUID+78, 31297, 571, 1, @PHASE, 4759.774, 1375.651, 178.9943, 5.044002, 120, 0, 0),
(@DGUID+79, 31297, 571, 1, @PHASE, 4741.744, 1377.741, 176.0065, 4.729842, 120, 0, 0),
(@DGUID+80, 31297, 571, 1, @PHASE, 4747.381, 1362.794, 174.5987, 0.8028514, 120, 0, 0),
(@DGUID+81, 31297, 571, 1, @PHASE, 4713.244, 1322.761, 157.8859, 0.3665192, 120, 0, 0),
(@DGUID+82, 31298, 571, 1, @PHASE, 4843.441, 1461.766, 209.8327, 0.3665192, 120, 0, 0),
(@DGUID+83, 31298, 571, 1, @PHASE, 4834.151, 1451.847, 204.5755, 3.054326, 120, 0, 0),
(@DGUID+84, 31298, 571, 1, @PHASE, 4842.909, 1472.404, 209.6567, 2.129302, 120, 0, 0),
(@DGUID+85, 31298, 571, 1, @PHASE, 4786.143, 1428.748, 193.0345, 3.490659, 120, 0, 0),
(@DGUID+86, 31298, 571, 1, @PHASE, 4776.408, 1372.417, 180.5029, 5.72468, 120, 0, 0),
(@DGUID+87, 31298, 571, 1, @PHASE, 4738.453, 1334.156, 163.0611, 1.43117, 120, 0, 0),
(@DGUID+88, 31298, 571, 1, @PHASE, 4718.738, 1328.104, 159.9639, 5.410521, 120, 0, 0),
(@DGUID+89, 31328, 571, 1, @PHASE, 4740.34, 1311.947, 157.4052, 3.352981, 120, 0, 0),
(@DGUID+90, 31299, 571, 1, @PHASE, 4809.043, 1403.146, 193.0345, 1.780236, 120, 0, 0),
(@DGUID+91, 31299, 571, 1, @PHASE, 4794.851, 1401.514, 193.1791, 4.223697, 120, 0, 0),
(@DGUID+92, 31299, 571, 1, @PHASE, 4787.426, 1445.673, 193.0345, 2.9147, 120, 0, 0),
(@DGUID+93, 31299, 571, 1, @PHASE, 4768.885, 1388.273, 183.4424, 1.466077, 120, 0, 0),
(@DGUID+94, 31299, 571, 1, @PHASE, 4752.259, 1347.163, 170.3656, 4.677482, 120, 0, 0),
(@DGUID+95, 31308, 571, 1, @PHASE, 4869.767, 1529.764, 217.0381, 1.727876, 120, 0, 0),
(@DGUID+96, 31308, 571, 1, @PHASE, 4792.602, 1459.009, 193.0345, 4.904375, 120, 0, 0),
(@DGUID+97, 31308, 571, 1, @PHASE, 4781.22, 1443.945, 193.0345, 3.996804, 120, 0, 0),
(@DGUID+98, 31308, 571, 1, @PHASE, 4862.371, 1561.015, 224.5057, 0.1047198, 120, 0, 0),
(@DGUID+99, 31308, 571, 1, @PHASE, 4883.59, 1474.877, 209.6595, 1.117011, 120, 0, 0),
(@DGUID+100, 31309, 571, 1, @PHASE, 4836.271, 1413.927, 193.3568, 0.6108652, 120, 0, 0),
(@DGUID+101, 31309, 571, 1, @PHASE, 4901.72, 1508.318, 216.3484, 5.934119, 120, 0, 0),
(@DGUID+102, 31309, 571, 1, @PHASE, 4936.82, 1491.539, 226.006, 0.715585, 120, 0, 0),
(@DGUID+103, 31309, 571, 1, @PHASE, 4862.213, 1552.967, 223.6236, 4.764749, 120, 0, 0),
(@DGUID+104, 31309, 571, 1, @PHASE, 4894.372, 1462.795, 209.8621, 5.689773, 120, 0, 0),
(@DGUID+105, 31333, 571, 1, @PHASE, 4855.18, 1472.166, 209.6567, 0.9075712, 120, 0, 0),
(@DGUID+106, 31334, 571, 1, @PHASE, 4885.178, 1456.164, 209.715, 1.832596, 120, 0, 0);

-- Apply "permanent feign death" to the corpses
SET @DEAD := 29266;
DELETE FROM `creature_template_addon` WHERE `entry` IN (31285,31291,31292,31293,31294,31295,31296,31297,31298,31299,31308,31309);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(31285, @DEAD),(31291, @DEAD),(31292, @DEAD),(31293, @DEAD),
(31294, @DEAD),(31295, @DEAD),(31296, @DEAD),(31297, @DEAD),
(31298, @DEAD),(31299, @DEAD),(31308, @DEAD),(31309, @DEAD);

-- spawn Dark Ranger Marrah author vincent-michael Closes #7681
SET @CGUID:= 56; -- 4.x
SET @ENTRY:= 24137; -- Dark Ranger Marrah

DELETE FROM `creature` WHERE `id` = @ENTRY;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID, @ENTRY, 574, 3, 1, 183.8515, -76.50119, 15.84287, 3.455082, 7200, 0, 0);

DELETE FROM `creature_template_addon` WHERE `entry` = @ENTRY;
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(@ENTRY, 0, 0x20000, 0x1, '34189');

-- fix spawn for A dip in the moonwell Closes #7292
UPDATE `gameobject` SET `id` =  181825 WHERE `guid` = 16880;

-- 4.x removed
-- Add Loose Soil spawn for quest 299 "Uncovering the Past" author warriotpoetex Closes #6742
-- SET @GUID := 344;
-- DELETE FROM `gameobject` WHERE `guid`=@GUID;
-- INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
-- (@GUID,331,0,1,1,-3563.83,-1767.35,79.1001,4.26498,0,0,0.846355,-0.53262,300,0,1);

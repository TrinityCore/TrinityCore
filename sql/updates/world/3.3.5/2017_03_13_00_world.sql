SET @CGUID := 146562;
SET @OGUID := 9743;

UPDATE `creature_template` SET `unit_flags`=33280, `ScriptName`='boss_apothecary_hummel', `mechanic_immune_mask`=617297791 WHERE `entry`=36296;
UPDATE `creature_template` SET `unit_flags`=33280, `ScriptName`='npc_apothecary_baxter', `mechanic_immune_mask`=617297791 WHERE  `entry`=36565;
UPDATE `creature_template` SET `unit_flags`=33280, `ScriptName`='npc_apothecary_frye', `mechanic_immune_mask`=617297791 WHERE  `entry`=36272;
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE  `entry` IN(36710,36530);
UPDATE `gameobject_loot_template` SET `QuestRequired`=0 WHERE `Entry`=28677 and`Item`=49352;
UPDATE `gameobject_loot_template` SET `QuestRequired`=0 WHERE `Entry`=28678 and`Item`=49351;
UPDATE `gameobject_template` SET `size`=2 WHERE `entry` IN(202947,202948);
UPDATE `creature_model_info` SET `BoundingRadius`=0.4596, `CombatReach`=1.8 WHERE `DisplayID`=31167;
UPDATE `creature_model_info` SET `BoundingRadius`=0.4596, `CombatReach`=1.8 WHERE `DisplayID`=31166;

DELETE FROM `creature_loot_template` WHERE `Entry`=36296 AND `Item`=50250;
DELETE FROM `item_loot_template` WHERE `Entry`=54537;
INSERT INTO `item_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(54537, 1, 50010, 20, 0, 1, 0, 1, 1, NULL), -- Necklaces
(54537, 49927, 0, 100, 0, 1, 0, 5, 10, NULL), -- Love Token
(54537, 49715, 0, 6, 0, 1, 0, 1, 1, NULL), -- Forever-Lovely Rose
(54537, 50446, 0, 6, 0, 1, 0, 1, 1, NULL), -- Toxic Wasteling
(54537, 50741, 0, 6, 0, 1, 0, 1, 1, NULL), -- Vile Fumigator's Mask
(54537, 50471, 0, 1.1, 0, 1, 0, 1, 1, NULL), -- The Heartbreaker
(54537, 50250, 0, 0.03, 0, 1, 0, 1, 1, NULL); -- Big Love Rocket

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN(10847);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(10847, 0, 0, "Begin the battle.", 36652, 1, 1, 0, 0, 0, 0, '', 0, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN(68644,68614,68798);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,68644,0,0,31,0,3,36530,0,0,0,0,'','Spell [DND] Valentine Boss Validate Area targets [DND] Valentine Boss - Vial Bunny'),
(13,1,68614 ,0,0,31,0,3,36530,0,0,0,0,'','Spell Concentrated Irresistible Cologne Spill targets [DND] Valentine Boss - Vial Bunny'),
(13,1,68798,0,0,31,0,3,36530,0,0,0,0,'','Spell Concentrated Alluring Perfume Spill targets [DND] Valentine Boss - Vial Bunny');

DELETE FROM `creature_template_addon` WHERE `entry` IN (36565,36272,36296,36710);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(36565, 0, 0, 0, 1, 0, '68946 71869'), -- 36565 (Apothecary Baxter) - Irresistible Cologne
(36272, 0, 0, 0, 1, 0, 68704), -- 36272 (Apothecary Frye) - Lingering Fumes
(36296, 0, 0, 0, 1, 0, '68589 71856'), -- 36296 (Apothecary Hummel) - Alluring Perfume
(36710, 0, 0, 0, 1, 0, 69216);

DELETE FROM `creature_summon_groups` WHERE `summonerId`=36296;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(36296, 0, 1, 36565, -210.3594, 2214.606, 79.84758, 1.047198, 8, 0),
(36296, 0, 1, 36272, -205.1962, 2214.549, 79.84695, 2.408554, 8, 0);

DELETE FROM `creature_text` WHERE `entry` IN (36296,36272,36565);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(36296,0,0,"Did they bother to tell you who I am and why I am doing this?",12,0,100,6,0,0,38586,3,'SAY_INTRO_0'),
(36296,1,0,"...or are they just using you like they do everybody else?",12,0,100,396,0,0,38600,3,'SAY_INTRO_1'),
(36296,2,0,"But what does it matter.  It is time for this to end.",12,0,100,397,0,0,38591,3,'SAY_INTRO_2'),
(36296,3,0,"Baxter! Get in here and help! NOW!",12,0,100,0,0,0,38592,3,'SAY_CALL_BAXTER'),
(36296,4,0,"It is time, Frye!  Attack!",12,0,100,0,0,0,38593,3,'SAY_CALL_FRYE'),
(36296,5,0,"...please don't think less of me.",12,0,100,0,0,0,38597,3,'SAY_HUMMEL_DEATH'),
(36272,0,0,"Great. We're not gutless, we're incompetent.",12,0,100,0,0,0,38596,3,'SAY_FRYE_DEATH'),
(36565,0,0,"It has been the greatest honor of my life to serve with you, Hummel.",12,0,100,0,0,0,38595,3,'SAY_BAXTER_DEATH');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_apothecary_validate_area',
'spell_apothecary_throw_perfume',
'spell_apothecary_throw_cologne',
'spell_apothecary_perfume_spill',
'spell_apothecary_cologne_spill',
'spell_apothecary_lingering_fumes');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(68644,'spell_apothecary_validate_area'),
(68966,'spell_apothecary_throw_perfume'),
(69038,'spell_apothecary_throw_cologne'),
(68798,'spell_apothecary_perfume_spill'),
(68614,'spell_apothecary_cologne_spill'),
(68965,'spell_apothecary_lingering_fumes');

DELETE FROM `creature` WHERE `guid` IN(208794,208793,208792);
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+62;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+1, 36530, 33, 0, 0, 1, 1, 0, 0, -217.8004, 2183.503, 79.8493, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+2, 36530, 33, 0, 0, 1, 1, 0, 0, -215.434, 2198.861, 79.84796, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep) (Auras: )
(@CGUID+3, 36530, 33, 0, 0, 1, 1, 0, 0, -195.1233, 2163.059, 79.83028, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+4, 36530, 33, 0, 0, 1, 1, 0, 0, -211.0278, 2163.484, 79.84879, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+5, 36530, 33, 0, 0, 1, 1, 0, 0, -221.6858, 2179.219, 79.84988, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+6, 36530, 33, 0, 0, 1, 1, 0, 0, -219.0313, 2161.661, 79.84821, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+7, 36530, 33, 0, 0, 1, 1, 0, 0, -225.2396, 2164.177, 79.84788, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+8, 36530, 33, 0, 0, 1, 1, 0, 0, -222.7795, 2172.851, 79.8497, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+9, 36530, 33, 0, 0, 1, 1, 0, 0, -222.434, 2209.076, 79.84451, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+10, 36530, 33, 0, 0, 1, 1, 0, 0, -202.6493, 2180.49, 79.84853, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+11, 36530, 33, 0, 0, 1, 1, 0, 0, -207.9149, 2195.281, 79.84778, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep) (Auras: )
(@CGUID+12, 36530, 33, 0, 0, 1, 1, 0, 0, -205.6806, 2189.316, 79.84862, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+13, 36530, 33, 0, 0, 1, 1, 0, 0, -227.2309, 2177.594, 79.85047, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+14, 36530, 33, 0, 0, 1, 1, 0, 0, -202.9149, 2198.993, 79.84741, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+15, 36530, 33, 0, 0, 1, 1, 0, 0, -202.809, 2168.38, 79.82594, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+16, 36530, 33, 0, 0, 1, 1, 0, 0, -220.2379, 2166.99, 79.8491, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+17, 36530, 33, 0, 0, 1, 1, 0, 0, -210.7292, 2184.273, 79.84919, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+18, 36530, 33, 0, 0, 1, 1, 0, 0, -229.8142, 2170.894, 79.84966, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+19, 36530, 33, 0, 0, 1, 1, 0, 0, -212.1701, 2203.293, 79.84724, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+20, 36530, 33, 0, 0, 1, 1, 0, 0, -220.1649, 2190.29, 79.84927, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+21, 36530, 33, 0, 0, 1, 1, 0, 0, -233.4618, 2165.745, 79.84706, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+22, 36530, 33, 0, 0, 1, 1, 0, 0, -213.8142, 2168.231, 79.85005, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+23, 36530, 33, 0, 0, 1, 1, 0, 0, -204.2274, 2162.326, 79.84865, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+24, 36530, 33, 0, 0, 1, 1, 0, 0, -220.4219, 2203.752, 79.84645, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+25, 36530, 33, 0, 0, 1, 1, 0, 0, -213.8663, 2158.241, 79.84741, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+26, 36530, 33, 0, 0, 1, 1, 0, 0, -222.0538, 2196.368, 79.84769, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+27, 36530, 33, 0, 0, 1, 1, 0, 0, -224.3004, 2186.681, 79.85001, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+28, 36530, 33, 0, 0, 1, 1, 0, 0, -216.4531, 2175.7, 79.84973, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+29, 36530, 33, 0, 0, 1, 1, 0, 0, -210.349, 2178.34, 79.85, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+30, 36530, 33, 0, 0, 1, 1, 0, 0, -196.5052, 2155.45, 79.84718, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+31, 36530, 33, 0, 0, 1, 1, 0, 0, -203.6528, 2155.238, 79.84705, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+32, 36530, 33, 0, 0, 1, 1, 0, 0, -205.2465, 2204.854, 79.84711, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep) (Auras: )
(@CGUID+33, 36530, 33, 0, 0, 1, 1, 0, 0, -199.9063, 2211.925, 79.84727, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+34, 36530, 33, 0, 0, 1, 1, 0, 0, -207.3108, 2212.943, 79.84712, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep) (Auras: )
(@CGUID+35, 36530, 33, 0, 0, 1, 1, 0, 0, -227.6285, 2191.568, 79.84564, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+36, 36530, 33, 0, 0, 1, 1, 0, 0, -230.8125, 2185.498, 79.84583, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+37, 36530, 33, 0, 0, 1, 1, 0, 0, -225.7795, 2202.889, 79.84396, 4.520403, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+38, 36530, 33, 0, 0, 1, 1, 0, 0, -197.2604, 2196.29, 79.84711, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+39, 36530, 33, 0, 0, 1, 1, 0, 0, -220.6354, 2222.007, 79.84279, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+40, 36885, 33, 0, 0, 1, 1, 0, 0, -226.0851, 2192.799, 79.84625, 3.193953, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Crown Apothecary (Area: Shadowfang Keep)
(@CGUID+41, 36530, 33, 0, 0, 1, 1, 0, 0, -213.9931, 2209.849, 79.84778, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+42, 36530, 33, 0, 0, 1, 1, 0, 0, -212.4826, 2216.82, 79.84779, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep) (Auras: )
(@CGUID+43, 36530, 33, 0, 0, 1, 1, 0, 0, -218.3698, 2217.609, 79.84506, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+44, 36530, 33, 0, 0, 1, 1, 0, 0, -197.842, 2203.837, 79.84732, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+45, 36530, 33, 0, 0, 1, 1, 0, 0, -209.6354, 2172.125, 79.84968, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+46, 36530, 33, 0, 0, 1, 1, 0, 0, -210.8316, 2223.722, 79.84461, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+47, 36885, 33, 0, 0, 1, 1, 0, 0, -199.8646, 2191.736, 79.84777, 1.117011, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Crown Apothecary (Area: Shadowfang Keep)
(@CGUID+48, 36530, 33, 0, 0, 1, 1, 0, 0, -216.9497, 2225.153, 79.8432, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+49, 36530, 33, 0, 0, 1, 1, 0, 0, -198.4549, 2224.262, 79.84032, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+50, 36530, 33, 0, 0, 1, 1, 0, 0, -205.0052, 2219.215, 79.84557, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep) (Auras: )
(@CGUID+51, 36530, 33, 0, 0, 1, 1, 0, 0, -182.7292, 2214.054, 79.81828, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+52, 36530, 33, 0, 0, 1, 1, 0, 0, -197.1701, 2217.747, 79.84375, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep) (Auras: )
(@CGUID+53, 36530, 33, 0, 0, 1, 1, 0, 0, -191.8281, 2222.58, 79.84315, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+54, 36530, 33, 0, 0, 1, 1, 0, 0, -192.2569, 2210.776, 79.84515, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+55, 36530, 33, 0, 0, 1, 1, 0, 0, -189.0816, 2216.911, 79.84314, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+56, 23033, 33, 0, 0, 1, 1, 0, 0, -224.4688, 2209.684, 80.92682, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Invisible Stalker (Floating) (Area: Shadowfang Keep) (Auras: 57718 - Harpoon Loot Sparkles)
(@CGUID+57, 23033, 33, 0, 0, 1, 1, 0, 0, -224.3663, 2212.083, 80.92657, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Invisible Stalker (Floating) (Area: Shadowfang Keep) (Auras: 57718 - Harpoon Loot Sparkles)
(@CGUID+58, 36530, 33, 0, 0, 1, 1, 0, 0, -204.5729, 2226.901, 79.84293, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+59, 36885, 33, 0, 0, 1, 1, 0, 0, -218.0156, 2216.691, 79.84538, 1.989675, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Crown Apothecary (Area: Shadowfang Keep)
(@CGUID+60, 36530, 33, 0, 0, 1, 1, 0, 0, -182.5885, 2219.731, 79.83677, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- [DND] Valentine Boss - Vial Bunny (Area: Shadowfang Keep)
(@CGUID+61, 36296, 33, 0, 0, 1, 1, 0, 0, -208.0903, 2217.389, 79.84693, 4.817109, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Apothecary Hummel (Area: Shadowfang Keep) (Auras: 68589 - Alluring Perfume)
(@CGUID+62, 36885, 33, 0, 0, 1, 1, 0, 0, -225.9896, 2235.528, 79.8619, 5.183628, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 23420); -- Crown Apothecary (Area: Shadowfang Keep)

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+94;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 201906, 33, 0, 0, 1, 1, -201.7951, 2162.818, 79.76379, 2.042035, 0, 0, 0.8526402, 0.5224986, 7200, 255, 1, 23420), -- Rocket Delivery System (Area: Shadowfang Keep)
(@OGUID+1, 201289, 33, 0, 0, 1, 1, -203.3629, 2178.462, 79.76537, 0, 0, 0, 0, 1, 7200, 255, 1, 23420), -- Duskwood Table (Area: Shadowfang Keep)
(@OGUID+2, 202105, 33, 0, 0, 1, 1, -227.7379, 2168.457, 79.76581, 4.049168, 0, 0, -0.8987932, 0.4383728, 7200, 255, 1, 23420), -- Plague Wagon Empty (Area: Shadowfang Keep)
(@OGUID+3, 200300, 33, 0, 0, 1, 1, -228.7326, 2192.905, 79.76138, 4.468043, 0, 0, -0.7880106, 0.6156617, 7200, 255, 1, 23420), -- Generic Cage Top (Area: Shadowfang Keep)
(@OGUID+4, 200300, 33, 0, 0, 1, 1, -228.1163, 2194.755, 82.49375, 4.81711, 0, 0, -0.6691303, 0.743145, 7200, 255, 1, 23420), -- Generic Cage Top (Area: Shadowfang Keep)
(@OGUID+5, 200332, 33, 0, 0, 1, 1, -228.8524, 2192.884, 79.76133, 4.468043, 0, 0, -0.7880106, 0.6156617, 7200, 255, 1, 23420), -- Generic Cage Bottom (Area: Shadowfang Keep)
(@OGUID+6, 200332, 33, 0, 0, 1, 1, -228.2222, 2194.695, 82.49368, 4.834563, 0, 0, -0.6626196, 0.7489561, 7200, 255, 1, 23420), -- Generic Cage Bottom (Area: Shadowfang Keep)
(@OGUID+7, 200337, 33, 0, 0, 1, 1, -218.9306, 2221.089, 80.72054, 0, 0, 0, 0, 1, 7200, 255, 1, 23420), -- Forsaken Plague Barrel (Area: Shadowfang Keep)
(@OGUID+8, 200338, 33, 0, 0, 1, 1, -195.7413, 2204.79, 81.76898, 0, 0, 0, 0, 1, 7200, 255, 1, 23420), -- Forsaken Plague Barrel Empty (Area: Shadowfang Keep)
(@OGUID+9, 202948, 33, 0, 0, 1, 1, -224.0781, 2211.082, 81.02744, 0, 0, 0, 0, 1, 7200, 255, 1, 23420), -- Perfume Neutralizer (Area: Shadowfang Keep)
(@OGUID+10, 200337, 33, 0, 0, 1, 1, -215.6319, 2219.208, 79.76243, 0, 0, 0, 0, 1, 7200, 255, 1, 23420), -- Forsaken Plague Barrel (Area: Shadowfang Keep)
(@OGUID+11, 200338, 33, 0, 0, 1, 1, -195.2205, 2204.566, 80.72088, 0, 0, 0, 0, 1, 7200, 255, 1, 23420), -- Forsaken Plague Barrel Empty (Area: Shadowfang Keep)
(@OGUID+12, 181018, 33, 0, 0, 1, 1, -159.2257, 2167.594, 132.2321, 0.4014249, 0, 0, 0.1993675, 0.9799248, 7200, 255, 1, 23420), -- Hanging, Tall/Thin, Medium - Val (Area: Shadowfang Keep)
(@OGUID+13, 200332, 33, 0, 0, 1, 1, -227.8316, 2197.056, 79.7609, 4.485497, 0, 0, -0.782608, 0.6225148, 7200, 255, 1, 23420), -- Generic Cage Bottom (Area: Shadowfang Keep)
(@OGUID+14, 202948, 33, 0, 0, 1, 1, -224.0781, 2211.082, 81.02744, 0, 0, 0, 0, 1, 5, 255, 1, 23420), -- Perfume Neutralizer (Area: Shadowfang Keep)
(@OGUID+15, 202948, 33, 0, 0, 1, 1, -224.3629, 2211.849, 81.03157, 0, 0, 0, 0, 1, 5, 255, 1, 23420), -- Perfume Neutralizer (Area: Shadowfang Keep)
(@OGUID+16, 202947, 33, 0, 0, 1, 1, -224.7431, 2209.16, 81.01423, 0, 0, 0, 0, 1, 5, 255, 1, 23420), -- Cologne Neutralizer (Area: Shadowfang Keep)
(@OGUID+17, 202948, 33, 0, 0, 1, 1, -224.0781, 2211.082, 81.02744, 0, 0, 0, 0, 1, 5, 255, 1, 23420), -- Perfume Neutralizer (Area: Shadowfang Keep)
(@OGUID+18, 202947, 33, 0, 0, 1, 1, -224.6076, 2210.144, 81.01418, 0, 0, 0, 0, 1, 5, 255, 1, 23420), -- Cologne Neutralizer (Area: Shadowfang Keep)
(@OGUID+19, 202948, 33, 0, 0, 1, 1, -224.0781, 2211.082, 81.02744, 0, 0, 0, 0, 1, 5, 255, 1, 23420), -- Perfume Neutralizer (Area: Shadowfang Keep)
(@OGUID+20, 200334, 33, 0, 0, 1, 1, -203.4306, 2178.222, 81.05308, 0, 0, 0, 0, 1, 7200, 255, 1, 23420), -- Holiday - Valentine - Shadowfang Keep - Chemistry Set 03 (Area: Shadowfang Keep)
(@OGUID+21, 181018, 33, 0, 0, 1, 1, -140.8611, 2160.24, 131.9547, 1.867502, 0, 0, 0.8038568, 0.5948228, 7200, 255, 1, 23420), -- Hanging, Tall/Thin, Medium - Val (Area: Shadowfang Keep)
(@OGUID+22, 201906, 33, 0, 0, 1, 1, -201.8177, 2165.144, 80.67925, 1.378809, 0, 0, 0.6360779, 0.7716249, 7200, 255, 1, 23420), -- Rocket Delivery System (Area: Shadowfang Keep)
(@OGUID+23, 200300, 33, 0, 0, 1, 1, -227.7118, 2197.076, 79.76096, 4.468043, 0, 0, -0.7880106, 0.6156617, 7200, 255, 1, 23420), -- Generic Cage Top (Area: Shadowfang Keep)
(@OGUID+24, 201906, 33, 0, 0, 1, 1, -201.0556, 2165.413, 80.67633, 0.6806767, 0, 0, 0.333806, 0.9426418, 7200, 255, 1, 23420), -- Rocket Delivery System (Area: Shadowfang Keep)
(@OGUID+25, 202947, 33, 0, 0, 1, 1, -224.7431, 2209.16, 81.01423, 0, 0, 0, 0, 1, 5, 255, 1, 23420), -- Cologne Neutralizer (Area: Shadowfang Keep)
(@OGUID+26, 202948, 33, 0, 0, 1, 1, -224.3629, 2211.849, 81.03157, 0, 0, 0, 0, 1, 5, 255, 1, 23420), -- Perfume Neutralizer (Area: Shadowfang Keep)
(@OGUID+27, 202947, 33, 0, 0, 1, 1, -224.1024, 2209.566, 81.01447, 0, 0, 0, 0, 1, 5, 255, 1, 23420), -- Cologne Neutralizer (Area: Shadowfang Keep)
(@OGUID+28, 201906, 33, 0, 0, 1, 1, -199.1372, 2165.321, 80.66892, 2.042035, 0, 0, 0.8526402, 0.5224986, 7200, 255, 1, 23420), -- Rocket Delivery System (Area: Shadowfang Keep)
(@OGUID+29, 200337, 33, 0, 0, 1, 1, -223.2101, 2215.07, 80.9929, 0, 0, 0, 0, 1, 7200, 255, 1, 23420), -- Forsaken Plague Barrel (Area: Shadowfang Keep)
(@OGUID+30, 202948, 33, 0, 0, 1, 1, -224.8333, 2210.943, 81.057, 0, 0, 0, 0, 1, 5, 255, 1, 23420), -- Perfume Neutralizer (Area: Shadowfang Keep)
(@OGUID+31, 200338, 33, 0, 0, 1, 1, -196.9358, 2191.941, 79.75, 0, 0, 0, 0, 1, 7200, 255, 1, 23420), -- Forsaken Plague Barrel Empty (Area: Shadowfang Keep)
(@OGUID+32, 181060, 33, 0, 0, 1, 1, -266.908, 2297.325, 77.52528, 5.916668, 0, 0, -0.1822348, 0.983255, 7200, 255, 1, 23420), -- Standing, Interior, Small - Val (Area: Shadowfang Keep)
(@OGUID+33, 181018, 33, 0, 0, 1, 1, -260.8195, 2304.193, 82.19453, 4.380776, 0, 0, -0.8141155, 0.580703, 7200, 255, 1, 23420), -- Hanging, Tall/Thin, Medium - Val (Area: Shadowfang Keep)
(@OGUID+34, 201906, 33, 0, 0, 1, 1, -199.8524, 2164.865, 80.67292, 3.089183, 0, 0, 0.9996567, 0.02620165, 7200, 255, 1, 23420), -- Rocket Delivery System (Area: Shadowfang Keep)
(@OGUID+35, 202948, 33, 0, 0, 1, 1, -224.0781, 2211.082, 81.02744, 0, 0, 0, 0, 1, 5, 255, 1, 23420), -- Perfume Neutralizer (Area: Shadowfang Keep)
(@OGUID+36, 202947, 33, 0, 0, 1, 1, -224.6076, 2210.144, 81.01418, 0, 0, 0, 0, 1, 5, 255, 1, 23420), -- Cologne Neutralizer (Area: Shadowfang Keep)
(@OGUID+37, 200336, 33, 0, 0, 1, 1, -196.0365, 2203.82, 79.76387, 1.239183, 0, 0, 0.5807028, 0.8141156, 7200, 255, 1, 23420), -- Forsaken Wagon (Area: Shadowfang Keep)
(@OGUID+38, 200337, 33, 0, 0, 1, 1, -218.1319, 2218.642, 80.7216, 0, 0, 0, 0, 1, 7200, 255, 1, 23420), -- Forsaken Plague Barrel (Area: Shadowfang Keep)
(@OGUID+39, 200338, 33, 0, 0, 1, 1, -196.0087, 2204.844, 80.7224, 0, 0, 0, 0, 1, 7200, 255, 1, 23420), -- Forsaken Plague Barrel Empty (Area: Shadowfang Keep)
(@OGUID+40, 200338, 33, 0, 0, 1, 1, -196.8646, 2192.993, 79.75895, 0, 0, 0, 0, 1, 7200, 255, 1, 23420), -- Forsaken Plague Barrel Empty (Area: Shadowfang Keep)
(@OGUID+41, 201906, 33, 0, 0, 1, 1, -199.467, 2166.151, 80.66539, 0.1745321, 0, 0, 0.08715534, 0.9961947, 7200, 255, 1, 23420), -- Rocket Delivery System (Area: Shadowfang Keep)
(@OGUID+42, 200337, 33, 0, 0, 1, 1, -217.4688, 2219.5, 80.72163, 0, 0, 0, 0, 1, 7200, 255, 1, 23420), -- Forsaken Plague Barrel (Area: Shadowfang Keep)
(@OGUID+43, 201906, 33, 0, 0, 1, 1, -200.3385, 2165.795, 80.67102, 5.637414, 0, 0, -0.3173046, 0.9483237, 7200, 255, 1, 23420), -- Rocket Delivery System (Area: Shadowfang Keep)
(@OGUID+44, 200338, 33, 0, 0, 1, 1, -196.7326, 2202.128, 80.57761, 0, 0, 0, 0, 1, 7200, 255, 1, 23420), -- Forsaken Plague Barrel Empty (Area: Shadowfang Keep)
(@OGUID+45, 181060, 33, 0, 0, 1, 1, -251.6024, 2289.042, 76.31879, 4.24115, 0, 0, -0.8526402, 0.5224986, 7200, 255, 1, 23420), -- Standing, Interior, Small - Val (Area: Shadowfang Keep)
(@OGUID+46, 201906, 33, 0, 0, 1, 1, -200.5243, 2164.542, 80.67728, 0.1745321, 0, 0, 0.08715534, 0.9961947, 7200, 255, 1, 23420), -- Rocket Delivery System (Area: Shadowfang Keep)
(@OGUID+47, 200338, 33, 0, 0, 1, 1, -198.3958, 2201.861, 79.76396, 0, 0, 0, 0, 1, 7200, 255, 1, 23420), -- Forsaken Plague Barrel Empty (Area: Shadowfang Keep)
(@OGUID+48, 202947, 33, 0, 0, 1, 1, -224.6076, 2210.144, 81.01418, 0, 0, 0, 0, 1, 5, 255, 1, 23420), -- Cologne Neutralizer (Area: Shadowfang Keep)
(@OGUID+49, 202948, 33, 0, 0, 1, 1, -224.0781, 2211.082, 81.02744, 0, 0, 0, 0, 1, 5, 255, 1, 23420), -- Perfume Neutralizer (Area: Shadowfang Keep)
(@OGUID+50, 201289, 33, 0, 0, 1, 1, -224.6476, 2210.903, 79.75954, 6.108654, 0, 0, -0.08715534, 0.9961947, 7200, 255, 1, 23420), -- Duskwood Table (Area: Shadowfang Keep)
(@OGUID+51, 201289, 33, 0, 0, 1, 1, -223.4531, 2215.885, 79.75977, 6.056293, 0, 0, -0.113203, 0.9935719, 7200, 255, 1, 23420), -- Duskwood Table (Area: Shadowfang Keep)
(@OGUID+52, 200337, 33, 0, 0, 1, 1, -218.7031, 2219.253, 80.72117, 0, 0, 0, 0, 1, 7200, 255, 1, 23420), -- Forsaken Plague Barrel (Area: Shadowfang Keep)
(@OGUID+53, 201906, 33, 0, 0, 1, 1, -200.9115, 2162.441, 79.7639, 2.042035, 0, 0, 0.8526402, 0.5224986, 7200, 255, 1, 23420), -- Rocket Delivery System (Area: Shadowfang Keep)
(@OGUID+54, 200336, 33, 0, 0, 1, 1, -218.6736, 2220.03, 79.76088, 2.321287, 0, 0, 0.9170599, 0.3987495, 7200, 255, 1, 23420), -- Forsaken Wagon (Area: Shadowfang Keep)
(@OGUID+55, 202947, 33, 0, 0, 1, 1, -225.3524, 2209.576, 81.01386, 0, 0, 0, 0, 1, 5, 255, 1, 23420), -- Cologne Neutralizer (Area: Shadowfang Keep)
(@OGUID+56, 200335, 33, 0, 0, 1, 1, -196.5556, 2195.776, 79.76373, 0, 0, 0, 0, 1, 7200, 255, 1, 23420), -- Holiday - Valentine - Shadowfang Keep - Chemistry Set 04 (Area: Shadowfang Keep)
(@OGUID+57, 202948, 33, 0, 0, 1, 1, -225.1597, 2211.516, 81.02943, 0, 0, 0, 0, 1, 7200, 255, 1, 23420), -- Perfume Neutralizer (Area: Shadowfang Keep)
(@OGUID+58, 190678, 33, 0, 0, 1, 1, -222.5504, 2206.359, 81.06857, 0, 0, 0, 0, 1, 7200, 255, 1, 23420), -- Apothecary Vials and Bottles (Area: Shadowfang Keep)
(@OGUID+59, 201289, 33, 0, 0, 1, 1, -222.8229, 2206.047, 79.7614, 0.383971, 0, 0, 0.1908083, 0.9816273, 7200, 255, 1, 23420), -- Duskwood Table (Area: Shadowfang Keep)
(@OGUID+60, 200336, 33, 0, 0, 1, 1, -200.2153, 2165.316, 79.74786, 0.4537851, 0, 0, 0.2249508, 0.9743701, 7200, 255, 1, 23420), -- Forsaken Wagon (Area: Shadowfang Keep)
(@OGUID+61, 202947, 33, 0, 0, 1, 1, -225.2222, 2210.189, 81.01381, 0, 0, 0, 0, 1, 5, 255, 1, 23420), -- Cologne Neutralizer (Area: Shadowfang Keep)
(@OGUID+62, 200337, 33, 0, 0, 1, 1, -219.0417, 2219.865, 80.72085, 0, 0, 0, 0, 1, 7200, 255, 1, 23420), -- Forsaken Plague Barrel (Area: Shadowfang Keep)
(@OGUID+64, 200337, 33, 0, 0, 1, 1, -219.5017, 2219.882, 81.85169, 0, 0, 0, 0, 1, 7200, 255, 1, 23420), -- Forsaken Plague Barrel (Area: Shadowfang Keep)
(@OGUID+65, 202948, 33, 0, 0, 1, 1, -223.7014, 2212.127, 81.05749, 0, 0, 0, 0, 1, 5, 255, 1, 23420), -- Perfume Neutralizer (Area: Shadowfang Keep)
(@OGUID+66, 200338, 33, 0, 0, 1, 1, -197.9375, 2192.507, 79.76409, 0, 0, 0, 0, 1, 7200, 255, 1, 23420), -- Forsaken Plague Barrel Empty (Area: Shadowfang Keep)
(@OGUID+67, 200333, 33, 0, 0, 1, 1, -194.8038, 2199.302, 79.76308, 3.281239, 0, 0, -0.9975634, 0.06976615, 7200, 255, 1, 23420), -- Holiday - Valentine - Shadowfang Keep - Chemistry Set 02 (Area: Shadowfang Keep)
(@OGUID+68, 200337, 33, 0, 0, 1, 1, -218.3299, 2220.42, 80.72099, 0, 0, 0, 0, 1, 7200, 255, 1, 23420), -- Forsaken Plague Barrel (Area: Shadowfang Keep)
(@OGUID+70, 200337, 33, 0, 0, 1, 1, -219.6823, 2220.344, 80.72044, 0, 0, 0, 0, 1, 7200, 255, 1, 23420), -- Forsaken Plague Barrel (Area: Shadowfang Keep)
(@OGUID+71, 181018, 33, 0, 0, 1, 1, -233.5365, 2268.826, 82.17297, 1.117009, 0, 0, 0.5299187, 0.8480484, 7200, 255, 1, 23420), -- Hanging, Tall/Thin, Medium - Val (Area: Shadowfang Keep)
(@OGUID+72, 181018, 33, 0, 0, 1, 1, -151.8785, 2185.76, 132.1955, 5.044002, 0, 0, -0.5807028, 0.8141156, 7200, 255, 1, 23420), -- Hanging, Tall/Thin, Medium - Val (Area: Shadowfang Keep)
(@OGUID+73, 181018, 33, 0, 0, 1, 1, -245.5087, 2273.543, 82.16793, 1.134463, 0, 0, 0.5372992, 0.8433917, 7200, 255, 1, 23420), -- Hanging, Tall/Thin, Medium - Val (Area: Shadowfang Keep)
(@OGUID+74, 181018, 33, 0, 0, 1, 1, -275.0781, 2302.974, 82.48224, 5.829401, 0, 0, -0.2249508, 0.9743701, 7200, 255, 1, 23420), -- Hanging, Tall/Thin, Medium - Val (Area: Shadowfang Keep)
(@OGUID+75, 181018, 33, 0, 0, 1, 1, -257.375, 2278.217, 82.14223, 1.291542, 0, 0, 0.6018143, 0.7986361, 7200, 255, 1, 23420), -- Hanging, Tall/Thin, Medium - Val (Area: Shadowfang Keep)
(@OGUID+76, 181018, 33, 0, 0, 1, 1, -133.6927, 2178.62, 132.1656, 3.403396, 0, 0, -0.9914446, 0.1305283, 7200, 255, 1, 23420), -- Hanging, Tall/Thin, Medium - Val (Area: Shadowfang Keep)
(@OGUID+77, 181060, 33, 0, 0, 1, 1, -245.2118, 2284.845, 76.36433, 4.24115, 0, 0, -0.8526402, 0.5224986, 7200, 255, 1, 23420), -- Standing, Interior, Small - Val (Area: Shadowfang Keep)
(@OGUID+78, 181019, 33, 0, 0, 1, 1, -244.9879, 2285.457, 76.32001, 5.916668, 0, 0, -0.1822348, 0.983255, 7200, 255, 1, 23420), -- Standing, Interior, Medium - Val (Area: Shadowfang Keep)
(@OGUID+79, 181060, 33, 0, 0, 1, 1, -237.1285, 2281.804, 76.31394, 4.24115, 0, 0, -0.8526402, 0.5224986, 7200, 255, 1, 23420), -- Standing, Interior, Small - Val (Area: Shadowfang Keep)
(@OGUID+80, 181019, 33, 0, 0, 1, 1, -236.8455, 2282.424, 76.27265, 0.6283169, 0, 0, 0.3090162, 0.9510568, 7200, 255, 1, 23420), -- Standing, Interior, Medium - Val (Area: Shadowfang Keep)
(@OGUID+81, 181060, 33, 0, 0, 1, 1, -244.6962, 2286.151, 76.26979, 4.24115, 0, 0, -0.8526402, 0.5224986, 7200, 255, 1, 23420), -- Standing, Interior, Small - Val (Area: Shadowfang Keep)
(@OGUID+82, 181060, 33, 0, 0, 1, 1, -236.6094, 2283.007, 76.26243, 4.24115, 0, 0, -0.8526402, 0.5224986, 7200, 255, 1, 23420), -- Standing, Interior, Small - Val (Area: Shadowfang Keep)
(@OGUID+83, 181060, 33, 0, 0, 1, 1, -252.1007, 2287.615, 76.33432, 4.433136, 0, 0, -0.7986355, 0.601815, 7200, 255, 1, 23420), -- Standing, Interior, Small - Val (Area: Shadowfang Keep)
(@OGUID+84, 181018, 33, 0, 0, 1, 1, -269.25, 2282.983, 82.28855, 1.239183, 0, 0, 0.5807028, 0.8141156, 7200, 255, 1, 23420), -- Hanging, Tall/Thin, Medium - Val (Area: Shadowfang Keep)
(@OGUID+85, 202948, 33, 0, 0, 1, 1, -224.3629, 2211.849, 81.03157, 0, 0, 0, 0, 1, 5, 255, 1, 23420), -- Perfume Neutralizer (Area: Shadowfang Keep)
(@OGUID+86, 181060, 33, 0, 0, 1, 1, -268.9601, 2291.799, 77.44312, 5.899214, 0, 0, -0.1908083, 0.9816273, 7200, 255, 1, 23420), -- Standing, Interior, Small - Val (Area: Shadowfang Keep)
(@OGUID+87, 202948, 33, 0, 0, 1, 1, -224.3629, 2211.849, 81.03157, 0, 0, 0, 0, 1, 5, 255, 1, 23420), -- Perfume Neutralizer (Area: Shadowfang Keep)
(@OGUID+88, 181018, 33, 0, 0, 1, 1, -237.1163, 2294.856, 82.21571, 4.380776, 0, 0, -0.8141155, 0.580703, 7200, 255, 1, 23420), -- Hanging, Tall/Thin, Medium - Val (Area: Shadowfang Keep)
(@OGUID+89, 181018, 33, 0, 0, 1, 1, -278.7431, 2293.672, 82.41619, 5.899214, 0, 0, -0.1908083, 0.9816273, 7200, 255, 1, 23420), -- Hanging, Tall/Thin, Medium - Val (Area: Shadowfang Keep)
(@OGUID+90, 202947, 33, 0, 0, 1, 1, -224.7431, 2209.16, 81.01423, 0, 0, 0, 0, 1, 5, 255, 1, 23420), -- Cologne Neutralizer (Area: Shadowfang Keep)
(@OGUID+91, 181019, 33, 0, 0, 1, 1, -251.8576, 2288.427, 76.32627, 0.6283169, 0, 0, 0.3090162, 0.9510568, 7200, 255, 1, 23420), -- Standing, Interior, Medium - Val (Area: Shadowfang Keep)
(@OGUID+92, 181018, 33, 0, 0, 1, 1, -225.1146, 2290.128, 82.15984, 4.380776, 0, 0, -0.8141155, 0.580703, 7200, 255, 1, 23420), -- Hanging, Tall/Thin, Medium - Val (Area: Shadowfang Keep)
(@OGUID+93, 181018, 33, 0, 0, 1, 1, -248.9913, 2299.535, 82.2632, 4.380776, 0, 0, -0.8141155, 0.580703, 7200, 255, 1, 23420), -- Hanging, Tall/Thin, Medium - Val (Area: Shadowfang Keep)
(@OGUID+94, 181019, 33, 0, 0, 1, 1, -268.6615, 2295.618, 77.50943, 0.6283169, 0, 0, 0.3090162, 0.9510568, 7200, 255, 1, 23420); -- Standing, Interior, Medium - Val (Area: Shadowfang Keep)

DELETE FROM `game_event_creature` WHERE `guid` IN(208792,208793,208794);
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+62 AND `eventEntry`=8;
INSERT INTO `game_event_creature` SELECT 8, creature.guid FROM `creature` WHERE creature.guid BETWEEN @CGUID+0 AND @CGUID+14;

DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+94 AND `eventEntry`=8;
INSERT INTO `game_event_gameobject` SELECT 8, creature.guid FROM `creature` WHERE creature.guid BETWEEN @CGUID+0 AND @CGUID+14;

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+56,@CGUID+57);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID+56, 0, 0, 0, 1, 0, 57718), -- 23033 (Invisible Stalker (Floating))
(@CGUID+57, 0, 0, 0, 1, 0, 57718); -- 23033 (Invisible Stalker (Floating))

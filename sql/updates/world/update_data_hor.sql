-- Thanks to @Xanvial <-PRO <-DEV for teach me how to codestyle sql!

SET @CGUID := 209183;  -- set by dev

-- Delete mistake/unused creature and rebuild data
DELETE FROM `creature` WHERE `id` IN (38112, 38113, 36723);
DELETE FROM `creature` WHERE `guid` IN (@CGUID+0, @CGUID+1, @CGUID+2);    -- Lich King and Uther
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@CGUID+0, 38112, 668, 3, 1, 0, 1, 5338.22, 1978.67, 709.319, 2.25591, 300, 0, 0, 377468, 0, 0, 0, 0, 0),
(@CGUID+1, 38113, 668, 3, 1, 0, 1, 5278.55, 2035.78, 709.32, 5.53337, 300, 0, 0, 539240, 0, 0, 0, 0, 0),
(@CGUID+2, 36723, 668, 3, 1, 0, 1, 5413.99, 2116.61, 707.694, 3.90288, 300, 0, 0, 315000, 0, 0, 0, 0, 0);

-- Update unit flags for creature error fix "has empty threat list"  - Instance Normal and Heroic
UPDATE `creature_template` SET `unit_flags`= 576 WHERE `entry` IN (38112, 38113, 38172, 38173, 38175, 38176, 38177, 38599, 38603, 38524, 38525, 38563, 38544, 38564);

-- update faction for heroic mode
UPDATE `creature_template` SET `faction_A` = 16 WHERE `entry` = 37720;
UPDATE `creature_template` SET `faction_H` = 16 WHERE `entry` = 37720;
UPDATE `creature_template` SET `faction_A` = 1771 WHERE `entry` IN (37550, 37551, 37549);
UPDATE `creature_template` SET `faction_H` = 1771 WHERE `entry` IN (37550, 37551, 37549);

-- New NPC for Loralen and Koreln Hor part1
DELETE FROM `creature_template` WHERE `entry` IN (37796, 37598);
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES
(37598,0,0,0,0,0,30685,0,0,0,'Archmage Koreln','Kirin Tor','',0,80,80,2,1770,1770,2,1.00,1.14,1.00,1,346.00,499.00,0,287,13.00,0,0,8,32832,2048,8,0,0,0,0,0,315.00,468.00,69,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'',0,3,1.00,10.00,30.00,1.00,0,0,0,0,0,0,0,0,1,0,0,'',12340),
(37796,0,0,0,0,0,30687,0,0,0,'Dark Ranger Loralen','','',0,80,80,2,1770,1770,2,1.00,1.14,1.00,1,422.00,586.00,0,642,13.00,0,0,1,32832,2048,8,0,0,0,0,0,345.00,509.00,103,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'',0,3,1.00,10.00,20.00,1.00,0,0,0,0,0,0,0,0,1,0,0,'',12340);

DELETE FROM `creature` WHERE `guid` IN (202293, 202294);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(202294,37796,668,3,1,30687,1,5430.863281,2134.548584,707.695068,3.873826,86400,0.00,0,75600,0,0,0,0,0),
(202293,37779,668,3,1,30687,1,5232.69,1931.52,707.77,0.82,86400,0.00,0,75600,0,0,0,0,0);

-- Update NPC's ScriptName
UPDATE `creature_template` SET `AIName`='', `Scriptname`='npc_the_lich_king_hor' WHERE `entry`=36954;
UPDATE `creature_template` SET `AIName`='', `Scriptname`='npc_jaina_and_sylvana_hor_part2' WHERE `entry` IN (36955, 37554);
UPDATE `creature_template` SET `AIName`='', `Scriptname`='npc_raging_gnoul' WHERE `entry`=36940;
UPDATE `creature_template` SET `AIName`='', `Scriptname`='npc_risen_witch_doctor' WHERE `entry`=36941;
UPDATE `creature_template` SET `AIName`='', `Scriptname`='npc_abon' WHERE `entry`=37069;
UPDATE `creature_template` SET `AIName`='', `Scriptname`='npc_spiritual_reflection' WHERE `entry`=37107;
UPDATE `creature_template` SET `AIName`='', `Scriptname`='npc_frostsworn_general' WHERE `entry`=36723;
UPDATE `creature_template` SET `AIName`='', `Scriptname`='npc_jaina_and_sylvanas_hor' WHERE `entry`=37223;
UPDATE `creature_template` SET `AIName`='', `Scriptname`='npc_jaina_and_sylvanas_hor' WHERE `entry`=37221;

-- Delete Says And Rebuild
DELETE FROM `creature_text` WHERE `entry` = 36723;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(36723,0,0,"You are not worthy to face the Lich King!",12,0,100,0,0,16921,"HOR"),
(36723,1,0,"Master, I have failed...!",12,0,100,0,0,16922,"HOR");

-- AreaTrigger to restart waves after wipe.
DELETE FROM `areatrigger_scripts` WHERE `entry` = 5697;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) 
VALUES('5697','at_hor_waves_restarter');

-- Insert missing GameObjects
SET @GOGUID := 164235; -- SET BY DEV
SET @CENTRY := 300247; -- SET BY DEV

DELETE FROM `gameobject_template` WHERE `entry` IN (@CENTRY+0, @CENTRY+1, @CENTRY+2, @CENTRY+3, @CENTRY+4, @CENTRY+5);
DELETE FROM `gameobject` WHERE `guid` IN (@GOGUID+0, @GOGUID+1, @GOGUID+2, @GOGUID+3, @GOGUID+4, @GOGUID+5, @GOGUID+6);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `WDBVerified`) VALUES
(@CENTRY+0,'0','9214','Ice Wall HOR1','','','','1375','1','2.5','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','','1'),
(@CENTRY+1,'0','9214','Ice Wall HOR2','','','','1375','1','2.5','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','','1'),
(@CENTRY+2,'0','9214','Ice Wall HOR3','','','','1375','1','2.5','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','','1'),
(@CENTRY+3,'0','9214','Ice Wall HOR4','','','','1375','1','2.5','0','0','0','0','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','','1'),
(@CENTRY+4,'14','8253','Orgrim''s Hammer HOR','','','','0','1','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','','1'),
(@CENTRY+5,'14','9150','The Skybreaker HOR','','','','0','1','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','','1');

INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@GOGUID+0,@CENTRY+4,'668','3','1','5247.09','1581.11','763.511','5.86166','0','0','0.209207','-0.977871','300','0','1'),
(@GOGUID+1,@CENTRY+3,'668','3','1','5323.61','1755.85','770.305','0.784186','0','0','0.382124','0.924111','604800','100','0'),
(@GOGUID+2,@CENTRY+2,'668','3','1','5434.27','1881.12','751.303','0.923328','0','0','0.445439','0.895312','604800','100','0'),
(@GOGUID+3,@CENTRY+1,'668','3','1','5494.3','1978.27','736.689','1.0885','0','0','0.517777','0.855516','604800','100','0'),
(@GOGUID+4,@CENTRY+0,'668','3','1','5540.39','2086.48','731.066','1.00057','0','0','0.479677','0.877445','604800','100','0'),
(@GOGUID+5,'202079','668','3','1','5248.58','1574.22','795.209','0','0','0','0','1','604800','100','1'),
(@GOGUID+6,@CENTRY+5,'668','3','1','5245.17','1586.39','773.623','5.86166','0','0','0.209207','-0.977871','300','0','1');

-- Update GameObjects Flags
UPDATE `gameobject_template` SET `flags` = 1 WHERE `entry` = 201596;
UPDATE `gameobject_template` SET `flags` = 1 WHERE `entry` = 201709;
UPDATE `gameobject_template` SET `flags` = 1 WHERE `entry` = 202211;

-- Way points Sylvanas
DELETE FROM `script_waypoint` WHERE `entry` = 37554;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES
('37554','0','5587.68','2228.59','733.011','0','WP1'),
('37554','1','5600.71','2209.06','731.618','0','WP2'),
('37554','2','5606.42','2193.03','731.129','0','WP3'),
('37554','3','5598.56','2167.81','730.918','0','WP4 - Summon IceWall 01'),
('37554','4','5556.44','2099.83','731.827','0','WP5 - Spell Channel'),
('37554','5','5543.5','2071.23','731.702','0','WP6'),
('37554','6','5528.97','2036.12','731.407','0','WP7'),
('37554','7','5512.04','1996.7','735.122','0','WP8'),
('37554','8','5504.49','1988.79','735.886','0','WP9 - Spell Channel'),
('37554','9','5489.65','1966.39','737.653','0','WP10'),
('37554','10','5475.52','1943.18','741.146','0','WP11'),
('37554','11','5466.93','1926.05','743.536','0','WP12'),
('37554','12','5445.16','1894.95','748.757','0','WP13 - Spell Channel'),
('37554','13','5425.91','1869.71','753.237','0','WP14'),
('37554','14','5405.12','1833.94','757.486','0','WP15'),
('37554','15','5370.32','1799.38','761.007','0','WP16'),
('37554','16','5335.42','1766.95','767.635','0','WP17 - Spell Channel'),
('37554','17','5311.44','1739.39','774.165','0','WP18'),
('37554','18','5283.59','1703.76','784.176','0','WP19'),
('37554','19','5260.4','1677.78','784.301','3000','WP20'),
('37554','20','5262.44','1680.41','784.294','0','WP21'),
('37554','21','5260.4','1677.78','784.301','0','WP22');

-- Says Sylvanas HOR Part2
DELETE FROM `creature_text` WHERE `entry` = 37554;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(37554,5,0,'There''s an opening up ahead. GO NOW!',14,0,100,0,0,17059,'SAY_SYLVANA_ESCAPE_01'),
(37554,6,0,'We''re almost there! Don''t give up!',14,0,100,0,0,17060,'SAY_SYLVANA_ESCAPE_02'),
(37554,7,0,'BLASTED DEAD END! So this is how it ends. Prepare yourselves, heroes, for today we make our final stand!',14,0,100,0,0,17061,'SAY_SYLVANA_TRAP'),
(37554,4,0,'You won''t impede our escape, fiend. Keep the undead off me while I bring this barrier down!',14,0,100,0,0,17032,'SAY_SYLVANA_WALL_04'),
(37554,3,0,'I grow tired of these games, Arthas! Your walls can''t stop me!',14,0,100,0,0,17031,'SAY_SYLVANA_WALL_03'),
(37554,2,0,'Another barrier? Stand strong, champions! I will bring the wall down!',14,0,100,0,0,17030,'SAY_SYLVANA_WALL_02'),
(37554,1,0,'No wall can hold the Banshee Queen! Keep the undead at bay, heroes! I will tear this barrier down!',14,0,100,0,0,17029,'SAY_SYLVANA_WALL_01'),
(37554,0,0,'He''s too powerful! Heroes, quickly, come to me! We must leave this place immediately! I will do what I can do hold him in place while we flee.',14,0,100,0,0,17058,'SAY_SYLVANA_AGGRO'),
(37554,8,0,'We are safe For now. His strenght has increased ten  forms since our last battle. It will take a mighty army to destroy the lich king. An army greater that even the horde can''t rouse.',14,0,100,0,0,17062,'SAY_SYLVANA_FINAL_1');

-- Way points Jaina
DELETE FROM `script_waypoint` WHERE `entry` = 36955;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES
('36955','0','5587.68','2228.59','733.011','0','WP1'),
('36955','1','5600.71','2209.06','731.618','0','WP2'),
('36955','2','5606.42','2193.03','731.129','0','WP3'),
('36955','3','5598.56','2167.81','730.918','0','WP4 - Summon IceWall 01'),
('36955','4','5556.44','2099.83','731.827','0','WP5 - Spell Channel'),
('36955','5','5543.5','2071.23','731.702','0','WP6'),
('36955','6','5528.97','2036.12','731.407','0','WP7'),
('36955','7','5512.04','1996.7','735.122','0','WP8'),
('36955','8','5504.49','1988.79','735.886','0','WP9 - Spell Channel'),
('36955','9','5489.65','1966.39','737.653','0','WP10'),
('36955','10','5475.52','1943.18','741.146','0','WP11'),
('36955','11','5466.93','1926.05','743.536','0','WP12'),
('36955','12','5445.16','1894.95','748.757','0','WP13 - Spell Channel'),
('36955','13','5425.91','1869.71','753.237','0','WP14'),
('36955','14','5405.12','1833.94','757.486','0','WP15'),
('36955','15','5370.32','1799.38','761.007','0','WP16'),
('36955','16','5335.42','1766.95','767.635','0','WP17 - Spell Channel'),
('36955','17','5311.44','1739.39','774.165','0','WP18'),
('36955','18','5283.59','1703.76','784.176','0','WP19'),
('36955','19','5260.4','1677.78','784.301','3000','WP20'),
('36955','20','5262.44','1680.41','784.294','0','WP21'),
('36955','21','5260.4','1677.78','784.301','0','WP22');

-- Says Jaina HOR Part2
DELETE FROM `creature_text` WHERE `entry` = 36955;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(36955,7,0,'It... It''s a dead end. We have no choice but to fight. Steel yourself heroes, for this is our last stand!',14,0,100,0,0,16647,'SAY_JAINA_TRAP'),
(36955,6,0,'We''re almost there... Don''t give up!',14,0,100,0,0,16646,'SAY_JAINA_ESCAPE_02'),
(36955,5,0,'There''s an opening up ahead. GO NOW!',14,0,100,0,0,16645,'SAY_JAINA_ESCAPE_01'),
(36955,4,0,'Your barriers can''t hold us back much longer, monster. I will shatter them all!',14,0,100,0,0,16610,'SAY_JAINA_WALL_04'),
(36955,3,0,'This playing with us. I''ll Show what happens to ice when meeting with fire!',14,0,100,0,0,16609,'SAY_JAINA_WALL_03'),
(36955,2,0,'Another ice wall! Keep the undead from interrupting my incantation so that I may bring this wall down!',14,0,100,0,0,16608,'SAY_JAINA_WALL_02'),
(36955,1,0,'I will destroy this barrier. You must hold the undead back!',14,0,100,0,0,16607,'SAY_JAINA_WALL_01'),
(36955,0,0,'He is too powerful, we must leave this place at once! My magic will hold him in place for only a short time! Come quickly, heroes!',14,0,100,0,0,16644,'SAY_JAINA_AGGRO'),
(36955,8,0,'Forgive me heroes... I should to listen to Uther. I... I had to see for my self, to look into his eyes one last time. I... I am sorry!',14,0,100,0,0,16648,'SAY_JAINA_FINAL_1'),
(36955,9,0,'We now know what must to be done. I''ll deliver this news to King Varian and High Lord Fordring.',14,0,100,0,0,16649,'SAY_JAINA_FINAL_2');

-- Update equiment to Jaina HOR Part2
DELETE FROM `creature_equip_template` WHERE `entry` = 36955;
INSERT INTO `creature_equip_template` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
('36955','1','2177','12869','0');

-- Way points Lich King
DELETE FROM `script_waypoint` WHERE `entry` = 36954;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES
('36954','1','5577.19','2236','733.012','0','HoR WP LichKing'),
('36954','2','5580.57','2232.22','733.012','0','HoR WP LichKing'),
('36954','3','5586.67','2225.54','733.012','0','HoR WP LichKing'),
('36954','4','5590.45','2221.41','733.012','0','HoR WP LichKing'),
('36954','5','5595.75','2215.62','732.101','0','HoR WP LichKing'),
('36954','6','5601.21','2206.49','731.54','0','HoR WP LichKing'),
('36954','7','5605.01','2197.9','731.667','0','HoR WP LichKing'),
('36954','8','5606.55','2191.39','730.977','0','HoR WP LichKing'),
('36954','9','5604.68','2186.11','730.998','0','HoR WP LichKing'),
('36954','10','5602.26','2179.9','730.967','0','HoR WP LichKing'),
('36954','11','5600.06','2174.38','730.924','0','HoR WP LichKing'),
('36954','12','5597.29','2166.81','730.924','0','HoR WP LichKing'),
('36954','13','5596.25','2160.36','730.931','0','HoR WP LichKing'),
('36954','14','5591.79','2152.87','731.008','0','HoR WP LichKing'),
('36954','15','5585.47','2146.63','731.109','0','HoR WP LichKing'),
('36954','16','5579.1','2140.34','731.18','0','HoR WP LichKing'),
('36954','17','5572.56','2134.21','731.092','0','HoR WP LichKing'),
('36954','18','5564.08','2126.53','730.816','0','HoR WP LichKing'),
('36954','19','5559.04','2117.64','730.812','0','HoR WP LichKing'),
('36954','20','5555.77','2111.88','730.995','0','HoR WP LichKing'),
('36954','21','5550.82','2103.14','731.123','0','HoR WP LichKing'),
('36954','22','5546.02','2094.68','731.16','0','HoR WP LichKing'),
('36954','23','5541.53','2084.42','730.999','0','HoR WP LichKing'),
('36954','24','5537.5','2075.18','730.901','0','HoR WP LichKing'),
('36954','25','5533.76','2063.84','730.87','0','HoR WP LichKing'),
('36954','26','5530.97','2052.98','730.981','0','HoR WP LichKing'),
('36954','27','5526.75','2041.73','731.193','0','HoR WP LichKing'),
('36954','28','5522.88','2031.65','731.7','0','HoR WP LichKing'),
('36954','29','5521.01','2023.02','732.396','0','HoR WP LichKing'),
('36954','30','5516.55','2015.36','733.12','0','HoR WP LichKing'),
('36954','31','5513.06','2007.33','733.99','0','HoR WP LichKing'),
('36954','32','5510.43','1997.9','735.016','0','HoR WP LichKing'),
('36954','33','5504.53','1990.39','735.748','0','HoR WP LichKing'),
('36954','34','5499.34','1983.78','736.29','0','HoR WP LichKing'),
('36954','35','5493.11','1975.86','736.852','0','HoR WP LichKing'),
('36954','36','5487.58','1968.81','737.394','0','HoR WP LichKing'),
('36954','37','5483.12','1961.78','738.06','0','HoR WP LichKing'),
('36954','38','5478.33','1954.2','739.343','0','HoR WP LichKing'),
('36954','39','5475.2','1945.84','740.697','0','HoR WP LichKing'),
('36954','40','5472.15','1938.02','741.884','0','HoR WP LichKing'),
('36954','41','5469.26','1931.34','742.813','0','HoR WP LichKing'),
('36954','42','5464.23','1922.25','744.055','0','HoR WP LichKing'),
('36954','43','5458.43','1912.96','745.229','0','HoR WP LichKing'),
('36954','44','5452.26','1902.95','747.091','0','HoR WP LichKing'),
('36954','45','5442.44','1892.51','749.208','0','HoR WP LichKing'),
('36954','46','5435.67','1879.7','751.776','0','HoR WP LichKing'),
('36954','47','5429.03','1870.73','753.151','0','HoR WP LichKing'),
('36954','48','5423.72','1862.16','754.263','0','HoR WP LichKing'),
('36954','49','5417.21','1851.7','755.507','0','HoR WP LichKing'),
('36954','50','5408.94','1838.38','757.002','0','HoR WP LichKing'),
('36954','51','5398.8','1829.61','757.742','0','HoR WP LichKing'),
('36954','52','5388.47','1817.95','759.285','0','HoR WP LichKing'),
('36954','53','5378.23','1808.5','760.316','0','HoR WP LichKing'),
('36954','54','5368.5','1801.35','760.845','0','HoR WP LichKing'),
('36954','55','5360.86','1793.16','762.271','0','HoR WP LichKing'),
('36954','56','5353.62','1785.4','763.868','0','HoR WP LichKing'),
('36954','57','5344.78','1776.09','765.759','0','HoR WP LichKing'),
('36954','58','5336.38','1768.67','767.324','0','HoR WP LichKing'),
('36954','59','5327.56','1760.12','769.332','0','HoR WP LichKing'),
('36954','60','5319.62','1750.7','771.487','0','HoR WP LichKing'),
('36954','61','5313.12','1742.99','773.424','0','HoR WP LichKing'),
('36954','62','5305.41','1735.79','775.473','0','HoR WP LichKing'),
('36954','63','5298.93','1728.16','777.573','0','HoR WP LichKing'),
('36954','64','5292.54','1720.37','779.862','0','HoR WP LichKing'),
('36954','65','5287.11','1713.96','781.667','0','HoR WP LichKing'),
('36954','66','5280.14','1705.21','784.65','0','HoR WP LichKing'),
('36954','67','5277.98','1701.28','785.224','0','HoR WP LichKing');

-- Says Lich King HOR Part2
DELETE FROM `creature_text` WHERE `entry` = 36954;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(36954,4,0,'Another dead end.',14,0,100,0,0,17219,'SAY_LICH_KING_WALL_03'),
(36954,5,0,'How long can you fight it?',14,0,100,0,0,17220,'SAY_LICH_KING_WALL_04'),
(36954,3,0,'Succumb to the chill of the grave.',14,0,100,0,0,17218,'SAY_LICH_KING_WALL_02'),
(36954,1,0,'I will not make the same mistake again, Sylvanas. This time there will be no escape. You will all serve me in death!',14,0,100,0,0,17213,'SAY_LICH_KING_AGGRO_H'),
(36954,0,0,'Your allies have arrived, Jaina, just as you promised. You will all become powerful agents of the Scourge.',14,0,100,0,0,17212,'SAY_LICH_KING_AGGRO_A'),
(36954,9,0,'Nowhere to run! You''re mine now...',14,0,100,0,0,17223,'SAY_LICH_KING_END_DUN'),
(36954,2,0,'There is no escape!',14,0,100,0,0,17217,'SAY_LICH_KING_WALL_01'),
(36954,10,0,'All is lost!',14,0,100,0,0,17215,'SAY_LICH_KING_WIN'),
(36954,7,0,'Minions sees them. Bring their corpses back to me!',14,0,100,0,0,17222,'SAY_LICH_KING_ABON'),
(36954,8,0,'Rise minions, do not left them us!',14,0,100,0,0,17216,'SAY_LICH_KING_GNOUL'),
(36954,6,0,'Death''s cold embrace awaits.',14,0,100,0,0,17221,'SAY_LICH_KING_WINTER');

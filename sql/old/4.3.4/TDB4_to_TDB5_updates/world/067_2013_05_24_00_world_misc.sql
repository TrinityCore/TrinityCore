-- Halls Of Reflexion WIP

DELETE FROM `creature` WHERE `guid` IN (202308,202294,202301,202293);
-- extra spawned Uther -- 202294
-- extra LK spawn -- 202301
-- Loralen -- 202293
-- Lady Jaina Proudmoore -- 202308
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(202308,38112,668,3,1,0,0,5276.583,2037.45,709.4025,5.532694,604800,0,0,0,0,0,0,0,0),
(202294,38113,668,3,1,0,0,5342.232,1975.696,709.4025,2.391101,604800,0,0,0,0,0,0,0,0),
(202301,36723,668,3,2,0,0,5415.538,2117.842,707.7781,3.944444,604800,0,0,0,0,0,0,0,0);
-- Lady Jaina Proudmoore
UPDATE `creature_template` SET `ScriptName`='npc_jaina_or_sylvanas_hor' WHERE `entry`=37221;
-- Lady Sylvanas Windrunner
UPDATE `creature_template` SET `ScriptName`='npc_jaina_or_sylvanas_hor' WHERE `entry`=37223;
-- Frostmourne Altar Bunny (Quel'Delar)
UPDATE `creature_template` SET `InhabitType`=4,`flags_extra`=128 WHERE `entry`=37704;
-- Frostsworn General
UPDATE `creature_template` SET `ScriptName`='npc_frostworn_general' WHERE `entry`=36723;
UPDATE `creature_template` SET `faction_A`=16,`faction_H`=16 WHERE `entry`=37720; -- for hc
-- Spiritual Reflection
UPDATE `creature_template` SET /*`modelid1`=57,*/`ScriptName`='npc_spiritual_reflection' WHERE `entry`=37068;
-- Falric and Marwyn bind players to instance on heroic
UPDATE `creature_template` SET `flags_extra`=1 WHERE `entry` IN (38599,38603);

DELETE FROM `areatrigger_scripts` WHERE `entry` IN (5697,5632);
INSERT INTO `areatrigger_scripts` VALUES
-- AreaTrigger for waves restarter
(5697,'at_hor_waves_restarter'),
-- AreaTrigger for intro start
(5632,'at_hor_intro_start');

DELETE FROM `creature_text` WHERE (`entry`=37226 AND `groupid` IN (3,4)) OR `entry`=36723 OR `entry`=36954 OR `entry`=36955 OR `entry`=37554 OR `entry`=30344 OR `entry`=30824;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
-- The Lich King (at start)
(37226,3,0,'Foolish girl. You seek that, which I killed long ago. He is nearly a ghost now. A fate ago in my mind.',14,0,100,0,0,17229,'Lich King SAY_LK_JAINA_INTRO_END'),
(37226,4,0,'I will not make the same mistake again. This time there will be no escape. You fail to serve me in undead. Now, all that remains for you is oblivion!',14,0,100,0,0,17228,'Lich King SAY_LK_SYLVANAS_INTRO_END'),
-- Frostsworn General
(36723,0,0,'You are not worthy to face the Lich King!',14,0,100,0,0,16921,'general SAY_AGGRO'),
(36723,1,0,'Master, I have failed...',14,0,100,0,0,16922,'general SAY_DEATH'),
-- The Lich King (at chase event)
(36954,0,0,'Your allies have arrived, Jaina, just as you promised. You will all become powerful agents of the Scourge.',14,0,100,0,0,17212, 'Lich King SAY_LICH_KING_AGGRO_A'),
(36954,1,0,'I will not make the same mistake again, Sylvanas. This time there will be no escape. You will all serve me in death!',14,0,100,0,0,17213,'Lich King SAY_LICH_KING_AGGRO_H'),
(36954,2,0,'Succumb to the chill of the grave.',14,0,100,0,0,17218,'Lich King SAY_LICH_KING_WALL_02'),
(36954,3,0,'Another dead end.',14,0,100,0,0,17219,'Lich King SAY_LICH_KING_WALL_03'),
(36954,4,0,'How long can you fight it?',14,0,100,0,0,17220,'Lich King SAY_LICH_KING_WALL_04'),
(36954,5,0,'There is no escape!', 14,0,100,0,0,17217,'Lich King SAY_LICH_KING_WALL_01'),
(36954,6,0,'Rise minions, do not left them us!',14,0,100,0,0,17216,'Lich King SAY_LICH_KING_GNOUL'),
(36954,7,0,'Minions sees them. Bring their corpses back to me!',14,0,100,0,0,17222,'Lich King SAY_LICH_KING_ABON'),
(36954,8,0,'Death''s cold embrace awaits.',14,0,100,0,0,17221,'Lich King SAY_LICH_KING_WINTER'),
(36954,9,0,'Nowhere to run! You''re mine now...',14,0,100,0,0,17223,'Lich King SAY_LICH_KING_END_DUN'),
(36954,10,0,'All is lost!',14,0,100,0,0,17215,'Lich King SAY_LICH_KING_WIN'),
-- Lady Jaina Proudmoore (at chase event)
(36955,0,0,'He is too powerful, we must leave this place at once! My magic will hold him in place for only a short time! Come quickly, heroes!',14,0,100,1,0,16644,'Jaina SAY_JAINA_AGGRO'),
(36955,1,0,'I will destroy this barrier. You must hold the undead back!',14,0,100,0,0,16607,'Jaina SAY_JAINA_WALL_01'),
(36955,2,0,'Another ice wall! Keep the undead from interrupting my incantation so that I may bring this wall down!',14,0,100,0,0,16608,'Jaina SAY_JAINA_WALL_02'),
(36955,3,0,'He is toying with us! I will show him what happens to ice when it meets fire!',14,0,100,0,0,16609,'Jaina SAY_JAINA_WALL_03'),
(36955,4,0,'Your barriers can''t hold us back much longer, monster. I will shatter them all!',14,0,100,0,0,16610,'Jaina SAY_JAINA_WALL_04'),
(36955,5,0,'There''s an opening up ahead. GO NOW!', 14,0,100,1,0,16645,'Jaina SAY_JAINA_ESCAPE_01'),
(36955,6,0,'We''re almost there... Don''t give up!',14,0,100,0,0,16646,'Jaina SAY_JAINA_ESCAPE_02'),
(36955,7,0,'It... It''s a dead end. We have no choice but to fight. Steel yourself heroes, for this is our last stand!',14,0,100,1,0,16647,'Jaina SAY_JAINA_TRAP'),
(36955,8,0,'Forgive me heroes, I should have listened to Uther. I ... I had to see for myself, to look into his eyes one last time ... I am sorry.',14,0,100,1,0,16648,'Jaina SAY_JAINA_FINAL_2'),
(36955,9,0,'We now know what must be done. I will deliver this news to King Varian and Highlord Fordring.',14,0,100,1,0,16649,'Jaina SAY_JAINA_FINAL_3'),
-- Lady Sylvanas Windrunner (at chase event)
(37554,0,0,'He''s too powerful! Heroes, quickly, come to me! We must leave this place immediately! I will do what I can do hold him in place while we flee.',14,0,100,0,0,17058,'Sylvanas SAY_SYLVANA_AGGRO'),
(37554,1,0,'No wall can hold the Banshee Queen! Keep the undead at bay, heroes! I will tear this barrier down!',14,0,100,0,0,17029,'Sylvanas SAY_SYLVANA_WALL_01'),
(37554,2,0,'Another barrier? Stand strong, champions! I will bring the wall down!',14,0,100,0,0,17030,'Sylvanas SAY_SYLVANA_WALL_02'),
(37554,3,0,'I grow tired of these games, Arthas! Your walls can\'t stop me!',14,0,100,0,0,17031,'Sylvanas SAY_SYLVANA_WALL_03'),
(37554,4,0,'You won''t impede our escape, fiend. Keep the undead off me while I bring this barrier down!',14,0,100,0,0,17032,'Sylvanas SAY_SYLVANA_WALL_04'),
(37554,5,0,'There''s an opening up ahead. GO NOW!',14,0,100,1,0,17059,'Sylvanas SAY_SYLVANA_ESCAPE_01'),
(37554,6,0,'We''re almost there! Don''t give up!',14,0,100,0,0,17060,'Sylvanas SAY_SYLVANA_ESCAPE_02'),
(37554,7,0,'BLASTED DEAD END! So this is how it ends. Prepare yourselves, heroes, for today we make our final stand!',14,0,100,5,0,17061,'Sylvanas SAY_SYLVANA_TRAP'),
(37554,8,0,'We are safe... for now. His strength has increased tenfold since our last battle. It will take a mighty army to destroy the Lich King. An army greater than even the Horde can rouse.',14,0,100,1,0,17062,'Sylvanas SAY_SYLVANA_FINAL_2'),
-- High Captain Justin Bartlett
(30344,0,0,'Fire, fire!',14,0,100,0,0,16721,'Bartlett SAY_BARTLETT_FIRE'),
(30344,1,0,'Quickly, climb aboard! We mustn''t tarry here. There''s no telling when this whole mountainside will collapse!',14,0,100,0,0,16722,'Bartlett SAY_BARTLETT_FINAL_1'),
-- Sky-Reaver Korm Blackscar
(30824,0,0,'FIRE! FIRE!',14,0,100,0,0,0,'Korm SAY_KORM_FIRE'),
(30824,1,0,'Quickly, climb aboard! We mustn''t tarry here. There''s no telling when this whole mountainside will collapse!',14,0,100,0,0,0,'Korm SAY_KORM_FINAL_1');

/*
# 3+4+4+5 +4+4+5+5 = 16+18
# if 1st boss is dead and we wipe counter starts at wave 6
SET @CGUID  := 400000;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+33;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
-- pos 1
(@CGUID+4, 38177, 668, 3, 1, 5277.365, 1993.229, 707.7781, 0.4014257, 7200, 0, 0),
(@CGUID+31, 38172, 668, 3, 1, 5280.513, 1997.842, 707.7781, 0.296706, 7200, 0, 0),
(@CGUID+5, 38175, 668, 3, 1, 5275.479, 2001.135, 707.7781, 0.1745329, 7200, 0, 0),
(@CGUID+19, 38172, 668, 3, 1, 5279.649, 2004.656, 707.7781, 0.06981317, 7200, 0, 0),
(@CGUID+10, 38172, 668, 3, 1, 5275.076, 2008.724, 707.7781, 6.213372, 7200, 0, 0),
(@CGUID+25, 38176, 668, 3, 1, 5280.632, 2012.156, 707.7781, 6.056293, 7200, 0, 0),
(@CGUID+15, 38175, 668, 3, 1, 5277.739, 2016.882, 707.7781, 5.969026, 7200, 0, 0),
(@CGUID+29, 38176, 668, 3, 1, 5282.897, 2019.597, 707.7781, 5.88176, 7200, 0, 0),
-- pos 2
(@CGUID+1, 38172, 668, 3, 1, 5295.885, 2040.342, 707.7781, 5.078908, 7200, 0, 0),
(@CGUID+33, 38176, 668, 3, 1, 5299.25, 2035.998, 707.7781, 5.026548, 7200, 0, 0),
(@CGUID+6, 38172, 668, 3, 1, 5302.448, 2042.222, 707.7781, 4.904375, 7200, 0, 0),
(@CGUID+20, 38173, 668, 3, 1, 5306.057, 2037.002, 707.7781, 4.817109, 7200, 0, 0),
(@CGUID+0, 38175, 668, 3, 1, 5309.577, 2042.668, 707.7781, 4.694936, 7200, 0, 0),
(@CGUID+23, 38175, 668, 3, 1, 5312.752, 2037.122, 707.7781, 4.590216, 7200, 0, 0),
(@CGUID+11, 38173, 668, 3, 1, 5316.701, 2041.55, 707.7781, 4.502949, 7200, 0, 0),
(@CGUID+30, 38177, 668, 3, 1, 5318.704, 2036.108, 707.7781, 4.223697, 7200, 0, 0),
(@CGUID+16, 38173, 668, 3, 1, 5322.964, 2040.288, 707.7781, 4.34587, 7200, 0, 0),
-- pos 3
(@CGUID+28, 38173, 668, 3, 1, 5336.599, 2017.278, 707.7781, 3.473205, 7200, 0, 0),
(@CGUID+17, 38176, 668, 3, 1, 5343.467, 2015.951, 707.7781, 3.490659, 7200, 0, 0),
(@CGUID+32, 38173, 668, 3, 1, 5337.833, 2010.057, 707.7781, 3.228859, 7200, 0, 0),
(@CGUID+12, 38173, 668, 3, 1, 5344.15, 2007.168, 707.7781, 3.159046, 7200, 0, 0),
(@CGUID+21, 38176, 668, 3, 1, 5337.865, 2003.403, 707.7781, 2.984513, 7200, 0, 0),
(@CGUID+7, 38177, 668, 3, 1, 5343.293, 1999.384, 707.7781, 2.9147, 7200, 0, 0),
(@CGUID+24, 38173, 668, 3, 1, 5335.724, 1996.859, 707.7781, 2.740167, 7200, 0, 0),
(@CGUID+2, 38173, 668, 3, 1, 5340.836, 1992.458, 707.7781, 2.75762, 7200, 0, 0),
-- pos 4
(@CGUID+3, 38176, 668, 3, 1, 5325.072, 1977.597, 707.7781, 2.076942, 7200, 0, 0),
(@CGUID+8, 38176, 668, 3, 1, 5295.635, 1973.757, 707.7781, 1.186824, 7200, 0, 0),
(@CGUID+9, 38177, 668, 3, 1, 5311.031, 1972.229, 707.7781, 1.64061, 7200, 0, 0),
(@CGUID+13, 38176, 668, 3, 1, 5319.158, 1973.998, 707.7781, 1.919862, 7200, 0, 0),
(@CGUID+14, 38177, 668, 3, 1, 5302.247, 1972.415, 707.7781, 1.37881, 7200, 0, 0),
(@CGUID+18, 38172, 668, 3, 1, 5313.82, 1978.146, 707.7781, 1.745329, 7200, 0, 0),
(@CGUID+22, 38177, 668, 3, 1, 5299.434, 1979.009, 707.7781, 1.239184, 7200, 0, 0),
(@CGUID+26, 38172, 668, 3, 1, 5320.369, 1980.125, 707.7781, 2.007129, 7200, 0, 0),
(@CGUID+27, 38172, 668, 3, 1, 5306.572, 1977.474, 707.7781, 1.500983, 7200, 0, 0);
*/

/*
-- Uther the Lightbringer missing emotes
UPDATE `creature_text` SET `emote`=5 WHERE `entry`=37225 AND `groupid` IN (0,4,8,15) AND `id`=0;
UPDATE `creature_text` SET `emote`=1 WHERE `entry`=37225 AND `groupid` IN (1,2,3,5,6,7,9,10,11,12,13,14) AND `id`=0;
-- Falric missing emotes
UPDATE `creature_text` SET `emote`=2 WHERE `entry`=38112 AND `groupid`=5 AND `id`=0;
-- Marwyn missing emotes
UPDATE `creature_text` SET `emote`=2 WHERE `entry`=38113 AND `groupid`=4 AND `id`=0;
UPDATE `creature_text` SET `emote`=397 WHERE `entry`=38113 AND `groupid`=0 AND `id`=0;

-- Falric and Marwyn bind players to instance on heroic
UPDATE `creature_template` SET `flags_extra`=1 WHERE `entry` IN (38599,38603);
-- Frostsworn General
UPDATE `creature_template` SET `ScriptName`='npc_frostworn_general' WHERE `entry`=36723;
UPDATE `creature_template` SET `faction_A`=16,`faction_H`=16 WHERE `entry`=37720; -- for hc
-- Spiritual Reflection
-- UPDATE `creature_template` SET `modelid1`=57 WHERE `entry`=37068;
UPDATE `creature_template` SET `ScriptName`='npc_spiritual_reflection' WHERE `entry`=37068;
-- The Lich King (at chase event)
UPDATE `creature_template` SET `ScriptName`='boss_lich_king_hor' WHERE `entry`=36954;
-- Lady Jaina Proudmoore (at chase event)
UPDATE `creature_template` SET `faction_A`=1770,`faction_H`=1770,`unit_flags`=64|256|32768,`ScriptName`='npc_jaina_and_sylvana_hor_part2' WHERE `entry`=36955;
-- Lady Sylvanas Windrunner (at chase event)
UPDATE `creature_template` SET `ScriptName`='npc_jaina_and_sylvana_hor_part2' WHERE `entry`=37554;
-- High Captain Justin Bartlett
#UPDATE `creature_template` SET `npcflag`=3 WHERE `entry`=30344;
-- Sky-Reaver Korm Blackscar
#UPDATE `creature_template` SET `npcflag`=3 WHERE `entry`=30824;
-- Raging Ghoul
UPDATE `creature_template` SET `AIName`='',`Scriptname`='npc_raging_ghoul' WHERE `entry`=36940;
-- Risen Witch Doctor
UPDATE `creature_template` SET `AIName`='',`Scriptname`='npc_risen_witch_doctor' WHERE `entry`=36941;
-- Lumbering Abomination
UPDATE `creature_template` SET `AIName`='',`Scriptname`='npc_lumbering_abomination' WHERE `entry`=37069;
-- Frostmourne Altar Bunny (Quel''Delar)
UPDATE `creature_template` SET `InhabitType`=4,`flags_extra`=128 WHERE `entry`=37704;

DELETE FROM `conditions` WHERE `SourceEntry`=70063 AND `SourceTypeOrReferenceId`=13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,70063,0,0,32,0,144,0,0,0,0,'','Fury of Frostmourne - target players');

-- AreaTrigger for waves restarter
DELETE FROM `areatrigger_scripts` WHERE `entry`=5697;
INSERT INTO `areatrigger_scripts` VALUES
(5697,'at_hor_waves_restarter');

SET @GUID_CREATURE := 400000;
DELETE FROM `creature` WHERE `map`=668 AND `guid` BETWEEN @GUID_CREATURE+0 AND @GUID_CREATURE+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@GUID_CREATURE+0,37704,668,3,1,0,0,5309.135,2006.21,715.7825,3.961897,604800,0,0,0,0,0,0,0,0),
(@GUID_CREATURE+1,38112,668,3,1,0,0,5276.583,2037.45,709.4025,5.532694,604800,0,0,0,0,0,0,0,0),
(@GUID_CREATURE+2,38113,668,3,1,0,0,5342.232,1975.696,709.4025,2.391101,604800,0,0,0,0,0,0,0,0),
(@GUID_CREATURE+3,36723,668,3,1,0,0,5415.538,2117.842,707.7781,3.944444,604800,0,0,0,0,0,0,0,0);

DELETE FROM `script_waypoint` WHERE `entry` IN(36955,36954,37554);
INSERT INTO `script_waypoint` VALUES
-- Jaina
(36955,0,5587.682,2228.586,733.011,0,'WP1'),
(36955,1,5600.715,2209.058,731.618,0,'WP2'),
(36955,2,5606.417,2193.029,731.129,0,'WP3'),
(36955,3,5598.562,2167.806,730.918,0,'WP4 - Summon IceWall 01'),
(36955,4,5556.436,2099.827,731.827,0,'WP5 - Spell Channel'),
(36955,5,5543.498,2071.234,731.702,0,'WP6'),
(36955,6,5528.969,2036.121,731.407,0,'WP7'),
(36955,7,5512.045,1996.702,735.122,0,'WP8'),
(36955,8,5504.490,1988.789,735.886,0,'WP9 - Spell Channel'),
(36955,9,5489.645,1966.389,737.653,0,'WP10'),
(36955,10,5475.517,1943.176,741.146,0,'WP11'),
(36955,11,5466.930,1926.049,743.536,0,'WP12'),
(36955,12,5445.157,1894.955,748.757,0,'WP13 - Spell Channel'),
(36955,13,5425.907,1869.708,753.237,0,'WP14'),
(36955,14,5405.118,1833.937,757.486,0,'WP15'),
(36955,15,5370.324,1799.375,761.007,0,'WP16'),
(36955,16,5335.422,1766.951,767.635,0,'WP17 - Spell Channel'),
(36955,17,5311.438,1739.390,774.165,0,'WP18'),
(36955,18,5283.589,1703.755,784.176,0,'WP19'),
(36955,19,5260.400,1677.775,784.301,3000,'WP20'),
(36955,20,5262.439,1680.410,784.294,0,'WP21'),
(36955,21,5260.400,1677.775,784.301,0,'WP22'),
-- Sylvana
(37554,0,5587.682,2228.586,733.011,0,'WP1'),
(37554,1,5600.715,2209.058,731.618,0,'WP2'),
(37554,2,5606.417,2193.029,731.129,0,'WP3'),
(37554,3,5598.562,2167.806,730.918,0,'WP4 - Summon IceWall 01'),
(37554,4,5556.436,2099.827,731.827,0,'WP5 - Spell Channel'),
(37554,5,5543.498,2071.234,731.702,0,'WP6'),
(37554,6,5528.969,2036.121,731.407,0,'WP7'),
(37554,7,5512.045,1996.702,735.122,0,'WP8'),
(37554,8,5504.490,1988.789,735.886,0,'WP9 - Spell Channel'),
(37554,9,5489.645,1966.389,737.653,0,'WP10'),
(37554,10,5475.517,1943.176,741.146,0,'WP11'),
(37554,11,5466.930,1926.049,743.536,0,'WP12'),
(37554,12,5445.157,1894.955,748.757,0,'WP13 - Spell Channel'),
(37554,13,5425.907,1869.708,753.237,0,'WP14'),
(37554,14,5405.118,1833.937,757.486,0,'WP15'),
(37554,15,5370.324,1799.375,761.007,0,'WP16'),
(37554,16,5335.422,1766.951,767.635,0,'WP17 - Spell Channel'),
(37554,17,5311.438,1739.390,774.165,0,'WP18'),
(37554,18,5283.589,1703.755,784.176,0,'WP19'),
(37554,19,5260.400,1677.775,784.301,3000,'WP20'),
(37554,20,5262.439,1680.410,784.294,0,'WP21'),
(37554,21,5260.400,1677.775,784.301,0,'WP22'),
-- Lich King
(36954,1,5577.19,2236,733.012,0,'HoR WP LichKing'),
(36954,2,5580.57,2232.22,733.012,0,'HoR WP LichKing'),
(36954,3,5586.67,2225.54,733.012,0,'HoR WP LichKing'),
(36954,4,5590.45,2221.41,733.012,0,'HoR WP LichKing'),
(36954,5,5595.75,2215.62,732.101,0,'HoR WP LichKing'),
(36954,6,5601.21,2206.49,731.54,0,'HoR WP LichKing'),
(36954,7,5605.01,2197.9,731.667,0,'HoR WP LichKing'),
(36954,8,5606.55,2191.39,730.977,0,'HoR WP LichKing'),
(36954,9,5604.68,2186.11,730.998,0,'HoR WP LichKing'),
(36954,10,5602.26,2179.9,730.967,0,'HoR WP LichKing'),
(36954,11,5600.06,2174.38,730.924,0,'HoR WP LichKing'),
(36954,12,5597.29,2166.81,730.924,0,'HoR WP LichKing'),
(36954,13,5596.25,2160.36,730.931,0,'HoR WP LichKing'),
(36954,14,5591.79,2152.87,731.008,0,'HoR WP LichKing'),
(36954,15,5585.47,2146.63,731.109,0,'HoR WP LichKing'),
(36954,16,5579.1,2140.34,731.18,0,'HoR WP LichKing'),
(36954,17,5572.56,2134.21,731.092,0,'HoR WP LichKing'),
(36954,18,5564.08,2126.53,730.816,0,'HoR WP LichKing'),
(36954,19,5559.04,2117.64,730.812,0,'HoR WP LichKing'),
(36954,20,5555.77,2111.88,730.995,0,'HoR WP LichKing'),
(36954,21,5550.82,2103.14,731.123,0,'HoR WP LichKing'),
(36954,22,5546.02,2094.68,731.16,0,'HoR WP LichKing'),
(36954,23,5541.53,2084.42,730.999,0,'HoR WP LichKing'),
(36954,24,5537.5,2075.18,730.901,0,'HoR WP LichKing'),
(36954,25,5533.76,2063.84,730.87,0,'HoR WP LichKing'),
(36954,26,5530.97,2052.98,730.981,0,'HoR WP LichKing'),
(36954,27,5526.75,2041.73,731.193,0,'HoR WP LichKing'),
(36954,28,5522.88,2031.65,731.7,0,'HoR WP LichKing'),
(36954,29,5521.01,2023.02,732.396,0,'HoR WP LichKing'),
(36954,30,5516.55,2015.36,733.12,0,'HoR WP LichKing'),
(36954,31,5513.06,2007.33,733.99,0,'HoR WP LichKing'),
(36954,32,5510.43,1997.9,735.016,0,'HoR WP LichKing'),
(36954,33,5504.53,1990.39,735.748,0,'HoR WP LichKing'),
(36954,34,5499.34,1983.78,736.29,0,'HoR WP LichKing'),
(36954,35,5493.11,1975.86,736.852,0,'HoR WP LichKing'),
(36954,36,5487.58,1968.81,737.394,0,'HoR WP LichKing'),
(36954,37,5483.12,1961.78,738.06,0,'HoR WP LichKing'),
(36954,38,5478.33,1954.2,739.343,0,'HoR WP LichKing'),
(36954,39,5475.2,1945.84,740.697,0,'HoR WP LichKing'),
(36954,40,5472.15,1938.02,741.884,0,'HoR WP LichKing'),
(36954,41,5469.26,1931.34,742.813,0,'HoR WP LichKing'),
(36954,42,5464.23,1922.25,744.055,0,'HoR WP LichKing'),
(36954,43,5458.43,1912.96,745.229,0,'HoR WP LichKing'),
(36954,44,5452.26,1902.95,747.091,0,'HoR WP LichKing'),
(36954,45,5442.44,1892.51,749.208,0,'HoR WP LichKing'),
(36954,46,5435.67,1879.7,751.776,0,'HoR WP LichKing'),
(36954,47,5429.03,1870.73,753.151,0,'HoR WP LichKing'),
(36954,48,5423.72,1862.16,754.263,0,'HoR WP LichKing'),
(36954,49,5417.21,1851.7,755.507,0,'HoR WP LichKing'),
(36954,50,5408.94,1838.38,757.002,0,'HoR WP LichKing'),
(36954,51,5398.8,1829.61,757.742,0,'HoR WP LichKing'),
(36954,52,5388.47,1817.95,759.285,0,'HoR WP LichKing'),
(36954,53,5378.23,1808.5,760.316,0,'HoR WP LichKing'),
(36954,54,5368.5,1801.35,760.845,0,'HoR WP LichKing'),
(36954,55,5360.86,1793.16,762.271,0,'HoR WP LichKing'),
(36954,56,5353.62,1785.4,763.868,0,'HoR WP LichKing'),
(36954,57,5344.78,1776.09,765.759,0,'HoR WP LichKing'),
(36954,58,5336.38,1768.67,767.324,0,'HoR WP LichKing'),
(36954,59,5327.56,1760.12,769.332,0,'HoR WP LichKing'),
(36954,60,5319.62,1750.7,771.487,0,'HoR WP LichKing'),
(36954,61,5313.12,1742.99,773.424,0,'HoR WP LichKing'),
(36954,62,5305.41,1735.79,775.473,0,'HoR WP LichKing'),
(36954,63,5298.93,1728.16,777.573,0,'HoR WP LichKing'),
(36954,64,5292.54,1720.37,779.862,0,'HoR WP LichKing'),
(36954,65,5287.11,1713.96,781.667,0,'HoR WP LichKing'),
(36954,66,5280.14,1705.21,784.65,0,'HoR WP LichKing'),
(36954,67,5277.98,1701.28,785.224,0,'HoR WP LichKing');
*/
-- Halls of Reflexion WIP

DELETE FROM script_waypoint WHERE entry=11856;
INSERT INTO script_waypoint VALUES
(11856, 0, 113.91, -350.13, 4.55, 0, ''),
(11856, 1, 109.54, -350.08, 3.74, 0, ''),
(11856, 2, 106.95, -353.40, 3.60, 0, ''),
(11856, 3, 100.28, -338.89, 2.97, 0, ''),
(11856, 4, 110.11, -320.26, 3.47, 0, ''),
(11856, 5, 109.78, -287.80, 5.30, 0, ''),
(11856, 6, 105.02, -269.71, 4.71, 0, ''),
(11856, 7, 86.71, -251.81, 5.34, 0, ''),
(11856, 8, 64.10, -246.38, 5.91, 0, ''),
(11856, 9, -2.55, -243.58, 6.3, 0, ''),
(11856, 10, -27.78, -267.53, -1.08, 0, ''),
(11856, 11, -31.27, -283.54, -4.36, 0, ''),
(11856, 12, -28.96, -322.44, -9.19, 0, ''),
(11856, 13, -35.63, -360.03, -16.59, 0, ''),
(11856, 14, -58.30, -412.26, -30.60, 0, ''),
(11856, 15, -58.88, -474.17, -44.54, 0, ''),
(11856, 16, -45.92, -496.57, -46.26, 5000, 'AMBUSH'),
(11856, 17, -40.25, -510.07, -46.05, 0, ''),
(11856, 18, -38.88, -520.72, -46.06, 5000, 'END');

DELETE FROM script_waypoint WHERE entry=28912;
INSERT INTO script_waypoint VALUES
(28912, 0, 1653.518, -6038.374, 127.585, 0, 'Jump off'),
(28912, 1, 1653.978, -6034.614, 127.585, 5000, 'To Box'),
(28912, 2, 1653.854, -6034.726, 127.585, 500, 'Equip'),
(28912, 3, 1652.297, -6035.671, 127.585, 3000, 'Recover'),
(28912, 4, 1639.762, -6046.343, 127.948, 0, 'Escape'),
(28912, 5, 1640.963, -6028.119, 134.740, 0, ''),
(28912, 6, 1625.805, -6029.197, 134.740, 0, ''),
(28912, 7, 1626.845, -6015.085, 134.740, 0, ''),
(28912, 8, 1649.150, -6016.975, 133.240, 0, ''),
(28912, 9, 1653.063, -5974.844, 132.652, 5000, 'Mount'),
(28912, 10, 1654.747, -5926.424, 121.191, 0, 'Disappear');

UPDATE creature_template SET ScriptName='npc_koltira_deathweaver' WHERE entry=28912;

DELETE FROM `script_texts` WHERE `entry` between -1609098 AND -1609089;
INSERT INTO `script_texts` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES
(-1609089, 'I\'ll need to get my runeblade and armor... Just need a little more time.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,0,0,0,399,'koltira SAY_BREAKOUT1'),
(-1609090, 'I\'m still weak, but I think I can get an anti-magic barrier up. Stay inside it or you\'ll be destroyed by their spells.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,0,0,0,0,'koltira SAY_BREAKOUT2'),
(-1609091, 'Maintaining this barrier will require all of my concentration. Kill them all!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,0,0,0,16,'koltira SAY_BREAKOUT3'),
(-1609092, 'There are more coming. Defend yourself! Don\'t fall out of the anti-magic field! They\'ll tear you apart without its protection!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,0,0,0,0,'koltira SAY_BREAKOUT4'),
(-1609093, 'I can\'t keep barrier up much longer... Where is that coward?', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,0,0,0,0,'koltira SAY_BREAKOUT5'),
(-1609094, 'The High Inquisitor comes! Be ready, death knight! Do not let him draw you out of the protective bounds of my anti-magic field! Kill him and take his head!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,0,0,0,0,'koltira SAY_BREAKOUT6'),
(-1609095, 'Stay in the anti-magic field! Make them come to you!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,0,0,0,0,'koltira SAY_BREAKOUT7'),
(-1609096, 'The death of the High Inquisitor of New Avalon will not go unnoticed. You need to get out of here at once! Go, before more of them show up. I\'ll be fine on my own.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,0,0,0,0,'koltira SAY_BREAKOUT8'),
(-1609097, 'I\'ll draw their fire, you make your escape behind me.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,0,0,0,0,'koltira SAY_BREAKOUT9'),
(-1609098, 'Your High Inquisitor is nothing more than a pile of meat, Crusaders! There are none beyond the grasp of the Scourge!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,0,1,0,0,'koltira SAY_BREAKOUT10');

-- Kurenai Captive
UPDATE `creature_template` SET `ScriptName`='npc_kurenai_captive' WHERE `entry`=18209;
DELETE FROM `creature_template_addon` WHERE `entry`=18209;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (18209,0,0,8,0,0,''); -- Kneel
DELETE FROM `script_waypoint` WHERE `entry`=18209;
INSERT INTO `script_waypoint` (`entry`,`pointid`,`location_x`,`location_y`,`location_z`,`waittime`,`point_comment`) VALUES
(18209,1,-1518.593872,8469.956055,-4.101756,0,''),
(18209,2,-1511.784546,8480.531250,-4.033919,0,''),
(18209,3,-1513.447754,8509.764698,-0.109888,0,''),
(18209,4,-1498.857788,8508.805664,0.844676,0,''),
(18209,5,-1454.215088,8495.808594,4.912439,0,''),
(18209,6,-1437.483521,8504.165039,6.879123,0,''),
(18209,7,-1382.29,8539.87,11.139,7500,''),
(18209,8,-1361.22,8521.44,11.144,0,''),
(18209,9,-1324.8,8510.69,13.05,0,''),
(18209,10,-1312.08,8492.71,14.235,0,'');

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000482 AND -1000488;
DELETE FROM `creature_text` WHERE `entry` IN (18209,18210);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
-- Maghar Captive
(18210,0,0,"Look out!",12,0,100,0,0,0,"Maghar Captive"),
(18210,1,0,"Don't let them escape! Kill the strong one first!",12,0,100,0,0,0,"Maghar Captive"),
(18210,2,0,"More of them are coming! Watch out!",12,0,100,0,0,0,"Maghar Captive"),
(18210,3,0,"Where do you think you're going? Kill them all!",12,0,100,0,0,0,"Maghar Captive"),
(18210,4,0,"Ride the lightning, filth!",12,0,100,0,0,0,"Maghar Captive"),
(18210,5,0,"FROST SHOCK!",14,0,100,0,0,0,"Maghar Captive"),
(18210,6,0,"It is best that we split up now, in case they send more after us. Hopefully one of us will make it back to Garrosh. Farewell, stranger.",12,0,100,0,0,0,"Maghar Captive"),
-- Kurenai Captive
(18209,0,0,"Look out!",12,0,100,0,0,0,"Kurenai Captive"),
(18209,1,0,"Don't let them escape! Kill the strong one first!",12,0,100,0,0,0,"Kurenai Captive"),
(18209,2,0,"More of them are coming! Watch out!",12,0,100,0,0,0,"Kurenai Captive"),
(18209,3,0,"Where do you think you're going? Kill them all!",12,0,100,0,0,0,"Kurenai Captive"),
(18209,4,0,"Ride the lightning, filth!",12,0,100,0,0,0,"Kurenai Captive"),
(18209,5,0,"FROST SHOCK!",14,0,100,0,0,0,"Kurenai Captive"),
(18209,6,0,"Up ahead is the road to Telaar. We will split up when we reach the fork as they will surely send more Murkblood after us. Hopefully one of us makes it back to Telaar alive.",14,0,100,0,0,0,"Kurenai Captive");

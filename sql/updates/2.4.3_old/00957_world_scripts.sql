-- Liquid Fire
UPDATE `gameobject_template` SET `data2`='5',`data11`='1' WHERE `entry` IN ('180125','182533');

-- Scripts & Stats
UPDATE `creature_template` SET `ScriptName`='boss_vazruden_the_herald' WHERE `entry` = '17307';
UPDATE `creature_template` SET `ScriptName`='boss_vazruden',`heroic_entry`='18434' WHERE `entry` = '17537';
UPDATE `creature_template` SET `ScriptName`='boss_nazan' WHERE `entry` = '17536';
UPDATE `creature_template` SET `ScriptName`='mob_hellfire_sentry' WHERE `entry` = '17517';
UPDATE `creature_template` SET `equipment_id`='2183',`mechanic_immune_mask`='805306367' WHERE `entry` = '18434';

-- Reinforced Fel Iron Chest
DELETE FROM `gameobject` WHERE `id` IN ('185168','185169');

-- Script Texts
DELETE FROM `script_texts` WHERE `entry` BETWEEN '-1543025' AND '-1543017';
INSERT INTO `script_texts` (`entry`,`content_default`,`sound`,`type`,`language`,`comment`) VALUES
('-1543017','You have faced many challenges, pity they were all in vain. Soon your people will kneel to my lord!',10292,1,0,'vazruden SAY_INTRO'),
('-1543018','Is there no one left to test me?',10293,1,0,'vazruden SAY_WIPE'),
('-1543019','Your time is running out!',10294,1,0,'vazruden SAY_AGGRO_1'),
('-1543020','You are nothing, I answer a higher call!',10295,1,0,'vazruden SAY_AGGRO_2'),
('-1543021','The Dark Lord laughs at you!',10296,1,0,'vazruden SAY_AGGRO_3'),
('-1543022','It is over. Finished!',10297,1,0,'vazruden SAY_KILL_1'),
('-1543023','Your days are done!',10298,1,0,'vazruden SAY_KILL_2'),
('-1543024','My lord will be the end you all...',10299,1,0,'vazruden SAY_DIE'),
('-1543025','descends from the sky',0,3,0,'vazruden EMOTE');

-- Waypoint Movement
DELETE FROM `waypoint_data` WHERE `id` = '2081';
INSERT INTO `waypoint_data`(`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES
('2081','1','-1412.2','1784','112'),
('2081','2','-1447.9','1760.9','112'),
('2081','3','-1454.2','1729.3','112'),
('2081','4','-1430','1705','112'),
('2081','5','-1393.5','1705.5','112'),
('2081','6','-1369.8','1724.5','112'),
('2081','7','-1377','1760','112');

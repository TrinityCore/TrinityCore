DELETE FROM `creature_text` WHERE `entry`=2768;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(2768,0,0,'Ok, $N. Follow me to the cave where I''ll attempt to harness the power of the rune stone into these goggles.',12,0,100,0,0,0,'Professor Phizzlethorpe - SAY_PROGRESS_1'),
(2768,1,0,'I discovered this cave on our first day here. I believe the energy in the stone can be used to our advantage.',12,0,100,0,0,0,'Professor Phizzlethorpe - SAY_PROGRESS_2'),
(2768,2,0,'I''ll begin drawing energy from the stone. Your job, $N, is to defend me. This place is cursed... trust me.',12,0,100,0,0,0,'Professor Phizzlethorpe - SAY_PROGRESS_3'),
(2768,3,0,'%s begins tinkering with the goggles before the stone.',16,0,100,0,0,0,'Professor Phizzlethorpe - EMOTE_PROGRESS_4'),
(2768,4,0,'Help!!! Get these things off me so I can get my work done!',12,0,100,0,0,0,'Professor Phizzlethorpe - SAY_AGGRO'),
(2768,5,0,'Almost done! Just a little longer!',12,0,100,0,0,0,'Professor Phizzlethorpe - SAY_PROGRESS_5'),
(2768,6,0,'I''ve done it! I have harnessed the power of the stone into the goggles! Let''s get out of here!',12,0,100,0,0,0,'Professor Phizzlethorpe - SAY_PROGRESS_6'),
(2768,7,0,'Phew! Glad to be back from that creepy cave.',12,0,100,0,0,0,'Professor Phizzlethorpe - SAY_PROGRESS_7'),
(2768,8,0,'%s hands one glowing goggles over to Doctor Draxlegauge.',16,0,100,0,0,0,'Professor Phizzlethorpe - EMOTE_PROGRESS_8'),
(2768,9,0,'Doctor Draxlegauge will give you further instructions, $N. Many thanks for your help!',12,0,100,0,0,0,'Professor Phizzlethorpe - SAY_PROGRESS_9');

DELETE FROM `script_waypoint` WHERE `entry`=2768;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `waittime`, `point_comment`) VALUES
(2768,1,-2072.32,-2089.59,9.14603,0,''),
(2768,2,-2078.18,-2096.31,10.8916,0,''),
(2768,3,-2079.21,-2105.22,13.3174,0,''),
(2768,4,-2074.81,-2108.72,14.1485,0,''),
(2768,5,-2076,-2116.21,16.3934,0,''),
(2768,6,-2073.31,-2123.92,18.6202,4000,''),
(2768,7,-2064.41,-2133.33,21.5776,0,''),
(2768,8,-2044.08,-2153.12,20.121,18000,''),
(2768,9,-2044.08,-2153.12,20.121,3000,''),
(2768,10,-2044.08,-2153.12,20.121,0,''),
(2768,11,-2044.08,-2153.12,20.121,14000,''),
(2768,12,-2063.89,-2133.33,21.5648,0,''),
(2768,13,-2075,-2121.98,17.8443,0,''),
(2768,14,-2074.83,-2108.53,14.1036,0,''),
(2768,15,-2079.59,-2091.61,9.80862,0,''),
(2768,16,-2071.29,-2086.44,8.5181,0,''),
(2768,17,-2066.46,-2085.97,8.9241,7000,'');

DELETE FROM `creature_questrelation` WHERE `id`=2768 AND `quest`=26050;
INSERT INTO `creature_questrelation` (`id`, `quest`)
VALUES (2768, 26050);

UPDATE `creature_template` SET `ScriptName`='npc_professor_phizzlethorpe' WHERE `entry`=2768;
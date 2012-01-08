-- Remove old script text for arathi_highlands.cpp
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000264 AND -1000273;
-- Add new creature_text for Professor Phizzlethorpe <Blackwater Raiders>
DELETE FROM `creature_text` WHERE `entry` IN (2768);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
-- SAY_PROGRESS_1
(2768,0,0, 'Ok, $N. Follow me to the cave where I''ll attempt to harness the power of the rune stone into these goggles.',12,0,100,0,0,0, 'Professor Phizzlethorpe'),
-- SAY_PROGRESS_2
(2768,1,0, 'I discovered this cave on our first day here. I believe the energy in the stone can be used to our advantage.',12,0,100,0,0,0, 'Professor Phizzlethorpe'),
-- SAY_PROGRESS_3
(2768,2,0, 'I''ll begin drawing energy from the stone. Your job, $N, is to defend me. This place is cursed... trust me.',12,0,100,0,0,0, 'Professor Phizzlethorpe'),
-- EMOTE_PROGRESS_4
(2768,3,0, '%s begins tinkering with the goggles before the stone.',16,0,100,0,0,0, 'Professor Phizzlethorpe'),
-- SAY_AGGRO
(2768,4,0, 'Help!!! Get these things off me so I can get my work done!',12,0,100,0,0,0, 'Professor Phizzlethorpe'),
-- SAY_PROGRESS_5
(2768,5,0, 'Almost done! Just a little longer!',12,0,100,0,0,0, 'Professor Phizzlethorpe'),
-- SAY_PROGRESS_6
(2768,6,0, 'I''ve done it! I have harnessed the power of the stone into the goggles! Let''s get out of here!',12,0,100,0,0,0, 'Professor Phizzlethorpe'),
-- SAY_PROGRESS_7
(2768,7,0, 'Phew! Glad to be back from that creepy cave.',12,0,100,0,0,0, 'Professor Phizzlethorpe'),
-- EMOTE_PROGRESS_8
(2768,8,0, '%s hands one glowing goggles over to Doctor Draxlegauge.',16,0,100,0,0,0, 'Professor Phizzlethorpe'),
-- SAY_PROGRESS_9
(2768,9,0, 'Doctor Draxlegauge will give you further instructions, $N. Many thanks for your help!',12,0,100,0,0,0, 'Professor Phizzlethorpe');

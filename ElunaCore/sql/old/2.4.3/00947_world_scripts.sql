DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000244 and -1000235;
INSERT INTO `script_texts` (entry, content_default, type, emote, comment) VALUES
(-1000235, 'Ok, $N. Follow me to the cave where I\'ll attempt to harness the power of the rune stone into these goggles.', 0, 1, 'phizzlethorpe - SAY_PROGRESS_1'),
(-1000236, 'I discovered this cave on our first day here. I believe the energy in the stone can be used to our advantage.', 0, 1, 'phizzlethorpe - SAY_PROGRESS_2'),
(-1000237, 'I\'ll begin drawing energy from the stone. Your job, $N, is to defend me. This place is cursed... trust me.', 0, 1, 'phizzlethorpe - SAY_PROGRESS_3'),
(-1000238, 'begins tinkering with the goggles before the stone.', 2, 0, 'phizzlethorpe - EMOTE_PROGRESS_4'),
(-1000239, 'Help!!! Get these things off me so I can get my work done!', 0, 0, 'SAY_AGGRO'),
(-1000240, 'Almost done! Just a little longer!', 0, 1, 'phizzlethorpe - SAY_PROGRESS_5'),
(-1000241, 'I\'ve done it! I have harnessed the power of the stone into the goggles! Let\'s get out of here!', 0, 1, 'phizzlethorpe - SAY_PROGRESS_6'),
(-1000242, 'Phew! Glad to be back from that creepy cave.', 0, 1, 'phizzlethorpe - SAY_PROGRESS_7'),
(-1000243, 'hands one glowing goggles over to Doctor Draxlegauge.', 2, 0, 'phizzlethorpe - EMOTE_PROGRESS_8'),
(-1000244, 'Doctor Draxlegauge will give you further instructions, $N. Many thanks for your help!', 0, 1, 'phizzlethorpe - SAY_PROGRESS_9');

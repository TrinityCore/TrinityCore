DELETE FROM `script_texts` WHERE `entry` BETWEEN -1000365 and -1000350;
INSERT INTO `script_texts` (entry, content_default, type, comment) VALUES
(-1000350, 'Who dares awaken Aquementas?', 1, 'mob_aquementas - AGGRO_YELL_AQUE'),

(-1000351, 'I give up! Please don\'t kill me!', 0, 'mob_unkor_the_ruthless - SAY_SUBMIT'),

(-1000352, 'I choose the third option: KILLING YOU!', 0, 'npc_floon - SAY_FLOON_ATTACK'),

(-1000353, 'Ok let\'s get out of here!', 0, 'npc_isla_starmane - SAY_PROGRESS_1'),
(-1000354, 'You sure you\'re ready? Take a moment.', 0, 'npc_isla_starmane - SAY_PROGRESS_2'),
(-1000355, 'Alright, let\'s do this!', 0, 'npc_isla_starmane - SAY_PROGRESS_3'),
(-1000356, 'Ok, I think I can make it on my own from here. Thank you so much for breaking me out of there!', 0, 'npc_isla_starmane - SAY_PROGRESS_4'),

(-1000357, 'Belore...', 0, 'npc_lady_sylvanas_windrunner - SAY_LAMENT_END'),
(-1000358, 'kneels down and pick up the amulet.', 2, 'npc_lady_sylvanas_windrunner - EMOTE_LAMENT_END'),

(-1000359, 'You have my blessing', 0, 'npcs_ashyen_and_keleth - GOSSIP_REWARD_BLESS'),

(-1000360, 'Is the way clear? Let\'s get out while we can, $N.', 0, 'npc_kayra_longmane - SAY_PROGRESS_1'),
(-1000361, 'Looks like we won\'t get away so easy. Get ready!', 0, 'npc_kayra_longmane - SAY_PROGRESS_2'),
(-1000362, 'Let\'s keep moving. We\'re not safe here!', 0, 'npc_kayra_longmane - SAY_PROGRESS_3'),
(-1000363, 'Look out, $N! Enemies ahead!', 0, 'npc_kayra_longmane - SAY_PROGRESS_4'),
(-1000364, 'We\'re almost to the refuge! Let\'s go.', 0, 'npc_kayra_longmane - SAY_PROGRESS_5'),
(-1000365, 'I can see my fellow druids from here. Thank you, $N. I\'m sure Ysiel will reward you for your actions!', 0, 'npc_kayra_longmane - SAY_PROGRESS_6');

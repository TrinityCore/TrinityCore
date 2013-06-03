DELETE FROM `script_texts` WHERE `npc_entry`=27654 AND `entry` BETWEEN -1578016 AND -1578005;
INSERT INTO `script_texts` (`npc_entry`, `entry`, `content_default`, `sound`, `type`, `comment`) VALUES
(27654, -1578005, 'The prisoners shall not go free! The word of Malygos is law!', 13594, 1, 'SAY_AGGRO'),
(27654, -1578006, 'A fitting punishment!', 13602, 1, 'SAY_KILL_1'),
(27654, -1578007, 'Sentence: executed!', 13603, 1, 'SAY_KILL_2'),
(27654, -1578008, 'Another casualty of war!', 13604, 1, 'SAY_KILL_3'),
(27654, -1578009, 'The war... goes on.', 13605, 1, 'SAY_DEATH'),
(27654, -1578010, 'It is too late to run!', 13598, 1, 'SAY_PULL_1'),
(27654, -1578011, 'Gather ''round....', 13599, 1, 'SAY_PULL_2'),
(27654, -1578012, 'None shall escape!', 13600, 1,  'SAY_PULL_3'),
(27654, -1578013, 'I condemn you to death!', 13601, 1, 'SAY_PULL_4'),
(27654, -1578014, 'Tremble, worms!', 13595, 1,  'SAY_STOMP_1'),
(27654, -1578015, 'I will crush you!', 13596, 1, 'SAY_STOMP_2'),
(27654, -1578016, 'Can you fly?', 13597, 1, 'SAY_STOMP_3');

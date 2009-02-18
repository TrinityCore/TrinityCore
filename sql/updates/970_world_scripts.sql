DELETE FROM script_texts WHERE entry BETWEEN -1000401 AND -1000396;
INSERT INTO script_texts (entry, content_default, type, language, comment) VALUES
(-1000396, 'Muahahahaha! You fool! You\'ve released me from my banishment in the interstices between space and time!', 0, 0, 'mobs_nether_drake - SAY_NIHIL_1'),
(-1000397, 'All of Draenor shall quick beneath my feet! I will destroy this world and reshape it in my image!', 0, 0, 'mobs_nether_drake - SAY_NIHIL_2'),
(-1000398, 'Where shall I begin? I cannot bother myself with a worm such as yourself. There is a world to be conquered!', 0, 0, 'mobs_nether_Drake - SAY_NIHIL_3'),
(-1000399, 'No doubt the fools that banished me are long dead. I shall take wing survey my demense. Pray to whatever gods you hold dear that we do not meet again.', 0, 0, 'mobs_nether_drake - SAY_NIHIL_4'),
(-1000400, 'NOOOOooooooo!', 1, 0, 'mobs_nether_drake - SAY_NIHIL_INTERRUPT'),

(-1000401, 'Good $N, you are under the spell\'s influence. I must analyze it quickly, then we can talk.', 0, 7, 'npc_daranelle - SAY_DARANELLE');


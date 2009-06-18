DELETE FROM script_texts WHERE entry BETWEEN -1000279 and -1000267;
INSERT INTO script_texts (entry, content_default, type, comment) VALUES
(-1000267, 'Ready when you are, warrior.', 1, 'flathead - SAY_BIG_WILL_READY'),
(-1000268, 'The Affray has begun, get ready to fight!', 1, 'flathead - SAY_TWIGGY_FLATHEAD_BEGIN'),
(-1000269, 'You! Enter the fray!', 1, 'flathead - SAY_TWIGGY_FLATHEAD_FRAY'),
(-1000270, 'Challenger is down!', 1, 'flathead - SAY_TWIGGY_FLATHEAD_DOWN'),
(-1000271, 'The Affray is over.', 1, 'flathead - SAY_TWIGGY_FLATHEAD_OVER'),

(-1000272, 'Alright, alright I think I can figure out how to operate this thing...', 0, 'shredder - SAY_PROGRESS_1'),
(-1000273, 'Arrrgh! This isn\'t right!', 0, 'shredder - SAY_PROGRESS_2'),
(-1000274, 'Okay, I think I\'ve got it, now. Follow me, $N!', 0, 'shredder - SAY_PROGRESS_3'),
(-1000275, 'There\'s the stolen shredder! Stop it or Lugwizzle will have our hides!', 1, 'shredder - SAY_MERCENARY_4'),
(-1000276, 'Looks like we\'re out of woods, eh? Wonder what this does...', 0, 'shredder - SAY_PROGRESS_5'),
(-1000277, 'Come on, don\'t break down on me now!', 0, 'shredder - SAY_PROGRESS_6'),
(-1000278, 'That was a close one! Well, let\'s get going, it\'s still a ways to Ratchet!', 0, 'shredder - SAY_PROGRESS_7'),
(-1000279, 'Hmm... I don\'t think this blinking red light is a good thing...', 0, 'shredder - SAY_PROGRESS_8');

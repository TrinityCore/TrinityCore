DELETE FROM script_texts WHERE entry BETWEEN -1000266 and -1000248;
INSERT INTO script_texts (entry, content_default, type, emote, comment) VALUES
(-1000248, 'The last thing I remember is the ship falling and us getting into the pods. I\'ll go see how I can help. Thank you!', 0, 0, 'draenei survivor - HEAL1'),
(-1000249, '$C, Where am I? Who are you? Oh no! What happened to the ship?.', 0, 0, 'draenei survivor - HEAL2'),
(-1000250, '$C You saved me! I owe you a debt that I can never repay. I\'ll go see if I can help the others.', 0, 0, 'draenei survivor - HEAL3'),
(-1000251, 'Ugh... what is this place? Is that all that\'s left of the ship over there?', 0, 0, 'draenei survivor - HEAL4'),
(-1000252, 'Oh, the pain...', 0, 0, 'draenei survivor - HELP1'),
(-1000253, 'Everything hurts, Please make it stop...', 0, 0, 'draenei survivor - HELP2'),
(-1000254, 'Ughhh... I hurt. Can you help me?', 0, 0, 'draenei survivor - HELP3'),
(-1000255, 'I don\'t know if I can make it, please help me...', 0, 0, 'draenei survivor - HELP4'),

(-1000256, 'Yes Master, all goes along as planned.', 0, 1, 'overgrind - SAY_TEXT'),
(-1000257, 'puts the shell to his ear.', 2, 0, 'overgrind - SAY_EMOTE'),
(-1000258, 'Now I cut you!', 1, 0, 'overgrind - YELL_ATTACK'),

(-1000259, 'What\'s the big idea, Spark?', 0, 0, 'geezle - GEEZLE_SAY_1'),
(-1000260, 'What\'s the big idea? You nearly blew my cover, idiot! I told you to put the compass and navigation maps somewhere safe - not out in the open for any fool to discover.', 0, 0, 'geezle - SPARK_SAY_2'),
(-1000261, 'The Master has gone to great lengths to secure information about the whereabouts of the Exodar. You could have blown the entire operation, including the cover of our spy on the inside.', 0, 0, 'geezle - SPARK_SAY_3'),
(-1000262, 'Relax, Spark! I have it all under control. We\'ll strip mine the Exodar right out from under \'em - making both you and I very, very rich in the process.', 0, 0, 'geezle - GEEZLE_SAY_4'),
(-1000263, 'Relax? Do you know what Kael\'thas does to those that fail him, Geezle? Eternal suffering and pain... Do NOT screw this up, fool.', 0, 0, 'geezle - SPARK_SAY_5'),
(-1000264, 'Our Bloodmyst scouts have located our contact. The fool, Velen, will soon leave himself open and defenseless -- long enough for us to strike! Now get out of my sight before I vaporize you...', 0, 0, 'geezle - SPARK_SAY_6'),
(-1000265, 'Yes, sir. It won\'t happen again...', 0, 0, 'geezle - GEEZLE_SAY_7'),
(-1000266, 'picks up the naga flag.', 2, 0, 'geezle - EMOTE_SPARK');

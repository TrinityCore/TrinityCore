DELETE FROM script_texts where entry BETWEEN -1000285 and -1000280;
INSERT INTO script_texts (entry, content_default, type, language, comment) VALUES
(-1000280, 'Thank you, dear Paladin, you just saved my life.', 0, 7, 'faulk - SAY_HEAL'),

(-1000281, 'Very well. Let\'s see what you have to show me, $N.', 0, 0, 'anvilvard - SAY_PR_1'),
(-1000282, 'What manner of trick is this, $R? If you seek to ambush me, I warn you I will not go down quietly!', 0, 0, 'anvilvard - SAY_PR_2'),
(-1000283, 'releases the last of its energies into the nerarby runestone, succesfully reactivating it.', 2, 0, 'crystal - EMOTE'),

(-1000284, 'Deployment sucessful. Trespassers will be neutralized.', 0, 0, 'sentry - SAY_CONVERTED_1'),
(-1000285, 'Objective acquired. Initiating security routines.', 0, 0, 'sentry - SAY_CONVERTED_1');

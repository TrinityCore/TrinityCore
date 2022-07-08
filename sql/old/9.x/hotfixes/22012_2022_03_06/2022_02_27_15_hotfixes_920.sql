-- 
DELETE FROM `broadcast_text` WHERE `ID` IN (214210, 214209, 205045, 205043, 205042, 205041, 205040, 205039, 205004, 205003, 205002, 204999, 204998, 204997, 204996, 204995, 202222, 201299);
INSERT INTO `broadcast_text` (`Text`, `Text1`, `ID`, `LanguageID`, `ConditionID`, `EmotesID`, `Flags`, `ChatBubbleDurationMs`, `VoiceOverPriorityID`, `SoundKitID1`, `SoundKitID2`, `EmoteID1`, `EmoteID2`, `EmoteID3`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `VerifiedBuild`) VALUES
('You have preserved this place for now. But, we must remain vigilant.', '', 214210, 0, 0, 669, 0, 0, 0, 188523, 0, 0, 0, 0, 0, 0, 0, 42488),
('The devourers have decimated this area. Destroy the fissures and protect its natural state.', '', 214209, 0, 0, 669, 0, 0, 0, 188522, 0, 0, 0, 0, 0, 0, 0, 42488),
('Where are the bodies buried?', 'Where are the bodies buried?', 205045, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 42488),
('Let them come. I am ready to fight.', 'Let them come. I am ready to fight.', 205043, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 42488),
('I grow tired of waiting. Where are the enemies?', 'I grow tired of waiting. Where are the enemies?', 205042, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 42488),
('Found a cake. Ate it too. Tasted gross.', 'Found a cake. Ate it too. Tasted gross.\n\nMight\'ve been a dredger.', 205041, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 42488),
('Bring me something worth fighting.', 'Bring me something worth fighting.', 205040, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 42488),
('I was promised bloodshed.', 'I was promised bloodshed.', 205039, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 42488),
('Good to be back in Revendreth. Always respected the venthyr and their stoneborn.', 'Good to be back in Revendreth. Always respected the venthyr and their stoneborn.', 205004, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 42488),
('Bet I could take on two... maybe three of those big dredgers you got.', 'Bet I could take on two... maybe three of those big dredgers you got.', 205003, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 42488),
('Where\'s the fight club? You have a fight club, right?', 'Where\'s the fight club? You have a fight club, right?', 205002, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 42488),
('Too much talking here, not enough fighting.', 'Too much talking here, not enough fighting.', 204999, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 42488),
('You spot any trouble, come running to me.', 'You spot any trouble, come running to me.', 204998, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 42488),
('When the fighting starts, I\'ll be there.', 'When the fighting starts, I\'ll be there.', 204997, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 42488),
('You need something killed?', 'You need something killed?', 204996, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 42488),
('I am not accustomed to taking orders from venthyr.', 'I am not accustomed to taking orders from venthyr.', 204995, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 42488),
('Gotta say, it\'s nice havin\' dredgers wait on ME for a change.\n\n<Rendle smiles proudly and sticks out his chest.>\n\nYeah, ol\' Rendle\'s finally movin\' up in this mucky-muck world.', '', 202222, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 42488),
('We have activated the stoneborn reserves for today\'s court.\n\nRest easy. Any intrusion will be dealt with.', '', 201299, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 42488);

UPDATE `broadcast_text` SET `VerifiedBuild`=42488 WHERE `ID` IN (212565, 212553, 212382, 206713, 205797, 205360, 205028, 205027, 205026, 205025, 205024, 205023, 205022, 205021, 204703, 204701, 204698, 204695, 204694, 204673, 204672, 204588, 204587, 204349, 204346, 204163, 204152, 204113, 204111, 203881, 203199, 203198, 203197, 203196, 203193, 203192, 202632, 202380, 202379, 202378, 202377, 202236, 202233, 202227, 202224, 202209, 202202, 201777, 201564, 201563, 201562, 201561, 201560, 201559, 200909, 200773, 200701, 200700, 200699, 200698, 200697, 200696, 200373, 198811, 198224, 198203, 198202, 197734, 197733, 197676, 197675, 197674, 197673, 197487, 197366, 197139, 197138, 193455, 193293, 193292, 189194, 189181);

DELETE FROM `broadcast_text` WHERE `ID` IN (204434, 201449, 201448, 201447, 201445, 200948, 200941, 200539, 200538, 200533, 200277, 199883);
INSERT INTO `broadcast_text` (`Text`, `Text1`, `ID`, `LanguageID`, `ConditionID`, `EmotesID`, `Flags`, `ChatBubbleDurationMs`, `VoiceOverPriorityID`, `SoundKitID1`, `SoundKitID2`, `EmoteID1`, `EmoteID2`, `EmoteID3`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `VerifiedBuild`) VALUES
('What majestic creatures you have discovered in the realm of Ardenweald!\n\nIn another life, I might have enjoyed it there...', 'What majestic creatures you have discovered in the realm of Ardenweald!\n\nIn another life, I might have enjoyed it there...', 204434, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 42488),
('They even collect flowers. Just like me!', '', 201449, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42488),
('Two brothers travel across worlds to save a princess.', '', 201448, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42488),
('It\'s my favorite!', '', 201447, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42488),
('Oh, I didn\'t see you there!\n\nI really like this book.', '', 201445, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 42488),
('I am thoroughly enjoying your court, Maw Walker. As I expected to.\n\nPlease pass along my congratulations to the Prince.\n\nIf you would excuse me, this spectacular music has me considering a trip to the dance floor.', 'I am thoroughly enjoying your court, Maw Walker. As I expected to.\n\nPlease pass along my congratulations to the Prince.\n\nIf you would excuse me, this spectacular music has me considering a trip to the dance floor.', 200948, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 42488),
('Sincerest apologies, my dear $gsir:madam;. It was far too presumptuous of me to ask.', '', 200941, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42488),
('LONGBEARD BOXTY\n\nNote from Stewart: This recipe from different aspirant. Also from Longbeard family in mortal life. She say many generations refine recipe before her. I do not change it.\n\nIngredients:\n5 Starchy potatos\n1 cup Flour, more as needed\n1 Egg\n2 tbsp Salted butter\n1 keg Dwarven stout (for drinking)\n\nPreparation:\n<The dredgers drew illegible doodles here.>', '', 200539, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42488),
('LONGBEARD STEW\n\nNote from Stewart: Recipe from aspirant in Bastion. In life, aspirant great dwarven chef. Gave me recipe when pass trials. Let go of past. His favorite recipe.\n\nIngredients:\n2 lbs Beef chuck\n6 oz Bacon, diced\n16 oz Rich, creamy dwarven stout\n1 cup Beef broth\n1/4 cup Tomato paste\n2 tbsp Worcester family sauce\n3 tbsp White flour\n2 Leeks, chopped\n3 Carrots, chopped\n1 Parsnip, chopped\n1 tsp Thyme\n1 tsp Rosemary\n1.5 tsp Salt\n1/4 tsp Black pepper\n2 Menethil Bay leaves\n\nPreparation:\n<The dredgers haven\'t transcribed this yet.>', '', 200538, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42488),
('STEWART\'S COLLECTED RECIPES\n\n(Transcribed by a series of semi-literate dredgers.)\n\nTable of Contents:', '', 200533, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42488),
('Don\'t worry, I\'m only hitting the nobles. Thems that can afford it.', '', 200277, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 42488),
('Oh, we don\'t mind. \n\nMy friends and I let ourselves in when we got here. I assumed the waiting outside plan was more for your... other guests.\n\nDon\'t worry, we\'ll stay out of the way!\n\nHey, while I have you... uh, where do you store your fireworks?', '', 199883, 0, 0, 0, 0, 0, 0, 0, 0, 35, 0, 0, 0, 0, 0, 42488);


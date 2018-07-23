/*

		LightForge Drains Area Beta
		clean design for Ashamane
                go xyz 458.823 1449.61 757.573 1860 
		race 30

*/

DELETE FROM `broadcast_text` WHERE `ID` IN (144772, 143583, 143590, 143586, 143585, 143584, 144924, 144925, 141912, 141914, 141916, 141913, 141915, 142628, 136300, 144923, 144770, 144921, 135889, 136247, 9701, 16966, 49490, 30361, 144908, 144864);
INSERT INTO broadcast_text (ID, Text, Text1, EmoteID1, EmoteID2, EmoteID3, EmoteDelay1, EmoteDelay2, EmoteDelay3, EmotesID, LanguageID, Flags, ConditionID, SoundEntriesID1, SoundEntriesID2, VerifiedBuild) VALUES
(143583, 'Welcome, friend $p. I am King Anduin Wrynn. As a new member of the Alliance, I wished to greet you personally.', '', 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 94909, 0, 26972),
(143590, 'Safe travels, $p. May the Light be with you always.', '', 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 94914, 0, 26972),
(143586, 'I look forward to hearing of your progress. Something tells me we will speak again soon.', '', 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 94913, 0, 26972),
(143585, 'These are troubled times for Azeroth. In the days to come, you will face many trials... fight many foes. Know that you are never alone against the darkness, for the Alliance stands with you.', '', 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 94912, 0, 26972),
(143584, 'The Lightforged may be a recent addition to our ranks, but I know the draenei well. I am confident you will embody the dedication and courage of the Army of the Light.', '', 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 94910, 0, 26972),
(144924, '', '<Fareeya greets you with a warm smile.>$B$BYou have done well in passing the trials, $c. But I feel your tale is just beginning.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(144925, '', 'Always carry with you what it means to be pledged to the Light.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(141912, '', 'For thousands of years, the Lightforged fought demons in the Twisting Nether. The Xenedar was the only home we knew.', 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 93696, 26972),
(141914, '', 'But we must not grow complacent. One war ends, the next begins. Such is the life of a soldier.', 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 93698, 26972),
(141916, '', 'And always walk in the Light, $p.', 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 93700, 26972),
(141913, '', 'Now, for the first time in ages, we can walk beneath a sky not befouled by the Legion''s madness... and feel the earth under our hooves again.', 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 93697, 26972),
(141915, '', 'Your duty begins in Stormwind. Explore this world of Azeroth. Get to know the people and places we have sworn to defend.', 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 93699, 26972),
(142628, 'I suppse you are wondering what I am doing here.$b$bSuffice it to say that I have been given a new prime directive. Apparently standing watch over the Conservatory was not an efficient use of my time.$b$b<Sigh> Tenure no longer means what it once did.$b$bDo you require something? As you can see, I am quite busy.', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(136300, 'This place is full of magic and mystery.', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(144923, 'If it is Maela you''re looking for, she is assisting on the front lines.$B$BStormwind is home to various competent tailors that can teach you a thing or two.', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(144770, 'I am fresh out of materials for the moment. My apologies.', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(144772, 'It is good to rest once in a while.$B$BEspecially after a profitable venture!', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(144921, '', 'Light take this table! I may never be able to use this workshop again.$B$BThe taint of those beast hides from Argus lingers, no matter how many times I scrub the surface.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(135889, 'I can assist you, $c, with any repairs your equipment may need.', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(136247, '', 'Greetings.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(9701, 'I can train you in First Aid techniques.', 'I can train you in First Aid techniques.', 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 26972),
(16966, 'Please, sit and make yourself comfortable.', 'Please, sit and make yourself comfortable.', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 26972),
(49490, 'Sorry, I have to set a broken leg on a baby dragon. Can you come back in a few minutes?', 'Sorry, I have to set a broken leg on a baby dragon. Can you come back in a few minutes?', 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 26972),
(30361, 'Greetings, $c. I can assist you in recovering lost companions.', 'Greetings, $c. I can assist you in recovering lost companions.', 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 26972),
(144908, 'The Vindicaar awaits its next voyage.\n\nAs do I.', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(144864, 'Light be with you.', 'Light be with you.', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972);

-- INSERT INTO THE HOTFIX DATABASE --
DELETE FROM `broadcast_text` WHERE `ID` IN (147222, 147231, 147229, 147228, 147223, 147224, 147226, 147233);
INSERT INTO `broadcast_text` (`ID`, `Text`, `Text1`, `VerifiedBuild`) VALUES
(147222, '', 'The Alliance needs strength. Unity. The king''s plan to bring in fresh blood is a good one.\n\nBut I can''t help thinking of my own Dark Iron clan. Of the fractures that divide us.', 26972),
(147231, '', '<Tyrande says nothing. Her brow is furrowed, as if deep in thought.>', 26972),
(147229, '', 'It seems like only yesterday that those of us who follow the way of the Tushui pledged to fight for the Alliance. \n\nThough I have great respect for King Anduin, I must confess that I found his father a more capable sparring partner.\n\nPlease do not tell him this.\n\n<Aysa bows.>', 26972),
(147228, 'The young king reminds me so much of his father. More than he realizes, I think.\n\nHe''s the right person to lead this effort and bring new faces into the Alliance.', '', 26972),
(147223, '', 'One day Silvermoon will stand again on the side of the Alliance. I know it.', 26972),
(147224, 'Much about Azeroth has changed in the years I was absent. But the Alliance remains an ideal worth fighting for.\n\nI will do everything in my power to make it stronger.', '', 26972),
(147226, 'The campaign on Argus was costly, but necessary. Now we must focus on defending our own lands.\n\nWe cannot sit idle while those Horde monsters build their forces.', '', 26972),
(147233, 'I have spent too long depending on visions to guide me.\n\nIt is time we forge our own fate. Part of that is finding new allies to stand beside us.', '', 26972);

DELETE FROM `broadcast_text` WHERE `ID` IN (147196, 147197, 147191, 147188, 2821, 51896, 147187, 147183, 119781, 121068, 113782, 119560, 117517, 119782, 121092, 136017, 113802, 127762, 120099);
INSERT INTO `broadcast_text` (`ID`, `Text`, `Text1`, `LanguageID`, `SoundEntriesID1`, `SoundEntriesID2`, `ConditionID`, `VerifiedBuild`) VALUES
(147196, '', 'What can I do for you?', 0, 0, 0, 0, 26972),
(147197, 'Aye, I have a moment. What do ye want?', '', 0, 0, 0, 0, 26972),
(147191, 'We have learned much from our fight against the Legion. In truth, these warframes are the culmination of many years of research.$B$BIf you wish, I can train you to craft similar devices.', '', 0, 0, 0, 0, 26972),
(147188, 'These machines are fantastic! How could they operate with no anomalies or chance of failure?$B$BOh, excuse me. Did you need something?', '', 0, 0, 0, 0, 26972),
(2821, 'Welcome to my Inn, weary traveler. What can I do for you?', 'Welcome to my Inn, weary traveler. What can I do for you?', 7, 0, 0, 0, 26972), 
(51896, 'I can teach the art of cooking.\n\nAre you looking to learn?', 'I can teach the art of cooking.\n\nAre you looking to learn?', 0, 0, 0, 0, 26972), 
(147187, 'I will admit, it took some time to grow accustomed to our transformation. At first, my usual dexterity felt... impeded.$B$BHowever, I can guarantee the techniques themselves have in no way been affected.', '', 0, 0, 0, 0, 26972),
(147183, 'I''ve spent enough time with clumsy fingers here that I''ve picked up a thing or two about treating injuries. Perhaps I can offer you some training?', '', 0, 0, 0, 0, 26972),
(119781, '', 'Search deep for your inner strength.', 0, 0, 0, 68596, 26972), 
(121068, '', 'Embrace the shadows.', 0, 0, 0, 70261, 26972), 
(113782, 'I will hide in shadows no longer.', '', 0, 0, 62785, 0, 26972), 
(119560, '', 'May the Light guide your way.', 0, 0, 0, 68284, 26972), 
(117517, 'The shadows guide me.', '', 0, 0, 68478, 0, 26972), 
(119782, '', 'We stand together.', 0, 0, 0, 68597, 26972), 
(121092, 'I am Light incarnate.', '', 0, 0, 72109, 0, 26972), 
(136017, 'Sound effect for troops', '', 0, 0, 90065, 0, 26972), 
(113802, '', 'I stand ready to help.', 0, 0, 0, 62813, 26972), 
(127762, '', 'This should be interesting...', 0, 0, 0, 80734, 26972), 
(120099, 'Sound effect for troops', 'Sound effect for troops', 0, 0, 68943, 68943, 26972); 

--
DELETE FROM `creature_text` WHERE `entry` IN(46753, 45871, 45872, 21252, 45870);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(46753, 1, 0, 'The Conclave of Wind has dissipated. Your honorable conduct and determination have earned you the right to face me in battle, mortals. I await your assault on my platform! Come!', 14, 0, 100, 0, 0, 0, 50553, 'Al''Akir to Rohash'),
(46753, 2, 0, 'Your challenge is accepted, mortals! Know that you face Al''Akir, Elemental Lord of Air! You have no hope of defeating me!', 14, 0, 100, 0, 0, 0, 50565, 'Al''Akir to Player'),
(46753, 3, 0, 'Your futile persistance angers me!', 14, 0, 100, 0, 0, 0, 50584, 'Al''Akir to 0'),
(46753, 4, 0, 'Storms! I summon you to my side!', 14, 0, 100, 0, 0, 0, 50587, 'Al''Akir to 0'),
(46753, 5, 0, 'Enough! I will no longer be contained!', 14, 0, 100, 0, 0, 0, 50585, 'Al''Akir to 0'),
(46753, 6, 0, 'After every storm, comes the calm...', 14, 0, 100, 0, 0, 0, 50580, 'Al''Akir to Xuen'),
(45871, 1, 0, 'You throw away your honor and flee as cowards? Then die!', 14, 0, 100, 0, 0, 0, 50592, 'Nezir to 0'),
(45871, 2, 0, 'Brothers, beware! These mortals are dangerous. I must pause and gather my strength.', 14, 0, 100, 0, 0, 0, 50595, 'Nezir to 0'),
(45871, 3, 0, '%s begins to gather strength from the remaining Wind Lord!', 41, 0, 100, 0, 0, 0, 48593, 'Nezir to 0'),
(45872, 1, 0, 'Why do you flee, mortals? There is nowhere you can run or hide here!', 14, 0, 100, 0, 0, 0, 50606, 'Rohash to 0'),
(45872, 2, 0, 'The power of our winds, UNLEASHED!', 14, 0, 100, 0, 0, 0, 50594, 'Rohash to 0'),
(21252, 1, 0, 'The Conclave of Wind is nearing full strength!', 41, 0, 100, 0, 0, 0, 48590, 'World Trigger (Not Immune PC) to Player'),
(45870, 1, 0, 'It shall be I that earns the favor of our lord by casting out the intruders. My calmest wind shall still prove too much for them!', 14, 0, 100, 0, 0, 0, 50596, 'Anshal to Player'),
(45870, 2, 0, 'My power grows feeble, brothers. I shamefully must rely on you for a time.', 14, 0, 100, 0, 0, 0, 50601, 'Anshal to 0'),
(45870, 3, 0, '%s begins to gather strength from the remaining Wind Lords!', 41, 0, 100, 0, 0, 0, 48593, 'Anshal to 0');

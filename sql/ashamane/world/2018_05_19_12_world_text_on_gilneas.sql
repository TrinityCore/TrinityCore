-- Text for Krennan Aranas, Marcus, King Genn Greymane, Panicked Citizen
DELETE FROM creature_text WHERE CreatureID in (38553,37803,35550,44086);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES 
('38553', '0', '0', 'It\'s time to join the fray, $N!  With you on our side the scales will surely tip in our favor!', '14', '0', '100', '0', '0', '0', '38513', 'Krennan Says'),
('37803', '0', '0', 'Bloody Forsaken! They\'ll pay for what they\'ve done!', '12', '7', '100', '0', '0', '0', '0', ''),
('37803', '1', '0', 'This is our land -- they\'re not going to take it away without a fight!', '12', '7', '100', '0', '0', '0', '0', ''),
('35550', '0', '0', 'Fire!', '14', '0', '100', '0', '0', '19710', '36091', 'General King Greymane at Barricades'),
('35550', '0', '1', 'Hold the barricades! Do not give them an inch!', '14', '0', '100', '0', '0', '19709', '36090', 'General King Greymane at Barricades'),
('35550', '0', '2', 'Keep them back!', '14', '0', '100', '0', '0', '19712', '36092', 'General King Greymane at Barricades'),
('44086', '0', '0', 'The... They promised that we would have security...', '12', '0', '33', '0', '0', '0', '0', 'Panicked Citizen Random Saying'),
('44086', '1', '1', 'It means we go from here! The screams are stronger every night.', '12', '0', '33', '0', '0', '0', '0', 'Panicked Citizen Random Saying'),
('44086', '2', '2', 'Why are the doors closed data?', '12', '0', '33', '0', '0', '0', '0', 'Panicked Citizen Random Saying');

-- Ttext for Bloodfang Stalker, Prince Liam Greymane, Lord Darius Crowley, Lord Godfrey,King Genn Greymane
DELETE FROM creature_text WHERE CreatureID in (35229,35906,35552,35911,35551);
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
('35229', '1', '0', '%s becomes enraged!', '16', '0', '100', '0', '0', '0', '7798', 'combat Enrage'),
('35906', '0', '0', 'We\'ve got Aranas!  Fire at will!', '14', '0', '100', '0', '0', '19634', '36099', 'Lord Godfrey'),
('35552', '0', '0', 'We need to keep the worgen\'s attention in the city, Genn.  It\'s the only shot we have for the survivors to make it to Duskhaven.', '12', '0', '100', '0', '0', '19507', '36103', 'Lord Darius Crowley'),
('35552', '1', '0', 'Not a chance, boy.  Gilneas is going to need its king\'s undivided attention.  Can\'t have your father wondering whether his child is alive or not.', '12', '0', '100', '0', '0', '19508', '36104', 'Lord Darius Crowley'),
('35552', '2', '0', 'My men and I will hole up inside the Light\'s Dawn Cathedral.  I\'ve already given the order and the cannons are on their way.  Lead our people well, Genn.', '12', '0', '100', '0', '0', '19509', '36105', 'Lord Darius Crowley'),
('35911', '0', '0', 'If we can make it past the gates into Duskhaven we\'ll be safe.  The eastern mountains are virtually impassable.', '12', '0', '100', '0', '0', '19719', '36107', 'King Genn Greymane'),
('35911', '1', '0', 'We were fools to take up arms against each other, Darius.  The worgen would\'ve never stood a chance.', '12', '0', '100', '0', '0', '19720', '36108', 'King Genn Greymane'),
('35551', '0', '0', 'I\'ll stay behind with the Royal Guard, father.  It is my duty to Gilneas.', '12', '0', '100', '0', '0', '19622', '36106', 'Prince Liam Greymane');







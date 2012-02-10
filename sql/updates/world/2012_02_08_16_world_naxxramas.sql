/* NAXXRAMAS */

-- Anub'Rekhan
DELETE FROM `creature_text` WHERE `entry` = 15956;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(15956, 0, 0, 'Ahh... welcome to my parlor.', 14, 0, 0, 0, 0, 8788, 'Anub\'Rekhan SAY_GREET'),
(15956, 0, 4, 'Closer now... tasty morsels. I\'ve been too long without food. Without blood to drink.', 14, 0, 0, 0, 0, 8793, 'Anub\'Rekhan SAY_GREET'),
(15956, 0, 1, 'I hear little hearts beating. Yesss... beating faster now. Soon the beating will stop.', 14, 0, 0, 0, 0, 8790, 'Anub\'Rekhan SAY_GREET'),
(15956, 0, 2, 'Where to go? What to do? So many choices that all end in pain, end in death.', 14, 0, 0, 0, 0, 8791, 'Anub\'Rekhan SAY_GREET'),
(15956, 0, 3, 'Which one shall I eat first? So difficult to choose. They all smell so delicious...', 14, 0, 0, 0, 0, 8792, 'Anub\'Rekhan SAY_GREET'),
(15956, 1, 0, 'Just a little taste...', 14, 0, 0, 0, 0, 8785, 'Anub\'Rekhan SAY_AGGRO'),
(15956, 1, 1, 'There is no way out.', 14, 0, 0, 0, 0, 8786, 'Anub\'Rekhan SAY_AGGRO'),
(15956, 1, 2, 'Yes, run! It makes the blood pump faster!', 14, 0, 0, 0, 0, 8787, 'Anub\'Rekhan SAY_AGGRO'),
(15956, 2, 0, 'Shhh... it will all be over soon.', 14, 0, 0, 0, 0, 8789, 'Anub\'Rekhan SAY_SLAY'),
(15956, 3, 0, 'Anub\'Rekhan begins to unleash an insect swarm!', 41, 0, 0, 0, 0, 0, 'Anub\'Rekhan EMOTE_LOCUST_SWARM'),
(15956, 4, 0, ' A Crypt Guard joins the fight!', 41, 0, 0, 0, 0, 0, 'Anub\'Rekhan EMOTE_CRYPT_GUARD'),
(15956, 5, 0, 'Corpse Scarabs appears from a Crypt Guard\'s corpse!', 41, 0, 0, 0, 0, 0, 'Anub\'Rekhan EMOTE_CORPSE_SCARAB');

-- Grand Widow Faerlina
DELETE FROM `creature_text` WHERE `entry` = 15953;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(15953, 0, 0, 'Your old lives, your mortal desires, mean nothing. You are acolytes of the master now, and you will serve the cause without question! The greatest glory is to die in the master\'s service!', 14, 0, 0, 0, 0, 0, 'Faerlina SAY_GREET'),
(15953, 1, 0, 'Slay them in the master\'s name!', 14, 0, 0, 0, 0, 0, 'Faerlina SAY_AGGRO'),
(15953, 2, 1, 'Kneel before me, worm!', 14, 0, 0, 0, 0, 0, 'Faerlina SAY_ENRAGE'),
(15953, 2, 2, 'Run while you still can!', 14, 0, 0, 0, 0, 0, 'Faerlina SAY_ENRAGE'),
(15953, 2, 0, 'You cannot hide from me!', 14, 0, 0, 0, 0, 0, 'Faerlina SAY_ENRAGE'),
(15953, 3, 1, 'Pathetic wretch!', 14, 0, 0, 0, 0, 0, 'Faerlina SAY_SLAY'),
(15953, 3, 0, 'You have failed!', 14, 0, 0, 0, 0, 0, 'Faerlina SAY_SLAY'),
(15953, 4, 0, 'The master... will avenge me!', 14, 0, 0, 0, 0, 0, 'Faerlina SAY_DEATH');

-- Maexxna
DELETE FROM `creature_text` WHERE `entry` = 15952;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(15952, 0, 0, 'Maexxna spins her web into a coccon!', 41, 0, 0, 0, 0, 0, 'Maexxna EMOTE_WRAP'),
(15952, 1, 0, 'Spiderlings appear on the web!', 41, 0, 0, 0, 0, 0, 'Maexxna EMOTE_SPIDERLING');

-- Noth
DELETE FROM `creature_text` WHERE `entry` = 15954;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(15954, 0, 2, 'Die, trespasser!', 14, 0, 0, 0, 0, 8847, 'Noth SAY_AGGRO'),
(15954, 0, 0, 'Glory to the master!', 14, 0, 0, 0, 0, 8845, 'Noth SAY_AGGRO'),
(15954, 0, 1, 'Your life is forfeit.', 14, 0, 0, 0, 0, 8846, 'Noth SAY_AGGRO'),
(15954, 1, 0, 'Rise, my soldiers! Rise and fight once more!', 14, 0, 0, 0, 0, 8851, 'Noth SAY_SUMMON'),
(15954, 2, 1, 'Breathe no more.', 14, 0, 0, 0, 0, 8850, 'Noth SAY_SLAY'),
(15954, 2, 0, 'My task is done!', 14, 0, 0, 0, 0, 8849, 'Noth SAY_SLAY'),
(15954, 3, 0, 'I will serve the master... in death.', 14, 0, 0, 0, 0, 8848, 'Noth SAY_DEATH'),
(15954, 4, 0, 'Noth the Plaguebringer summons forth Skeletal Warrios!', 41, 0, 0, 0, 0, 0, 'Noth EMOTE_SUMMON'),
(15954, 5, 0, 'Noth the Plaguebringer teleports to the balcony above!', 41, 0, 0, 0, 0, 0, 'Noth EMOTE_BALCONY'),
(15954, 6, 0, 'Noth the Plaguebringer raises more skeletons!', 41, 0, 0, 0, 0, 0, 'Noth EMOTE_SKELETON'),
(15954, 7, 0, 'Noth the Plaguebringer teleports back into the battle!', 41, 0, 0, 0, 0, 0, 'Noth EMOTE_TELEPORT');

-- Heigan the Unclean
DELETE FROM `creature_text` WHERE `entry` = 15936;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(15936, 0, 1, 'I see you...', 14, 0, 0, 0, 0, 8826, 'Heigan SAY_AGGRO');
(15936, 0, 0, 'You are mine now.', 14, 0, 0, 0, 0, 8825, 'Heigan SAY_AGGRO');
(15936, 0, 2, 'You... are next.', 14, 0, 0, 0, 8827, 0, 'Heigan SAY_AGGRO');
(15936, 1, 0, 'Close your eyes. Sleep.', 14, 0, 0, 0, 0, 8829, 'Heigan SAY_KILL');
(15936, 2, 0, 'The end is upon you.', 14, 0, 0, 0, 0, 8833, 'Heigan SAY_PHASE');
(15936, 3, 0, 'Heigan the Unclean teleports and begins to channel  a spell!', 41, 0, 0, 0, 0, 0, 'Heigan EMOTE_TELEPORT');
(15936, 4, 0, 'Heigan the Unclean rushes to attack once more!', 41, 0, 0, 0, 0, 0, 'Heigan EMOTE_TELEPORT');
(15936, 5, 0, '%s takes his last breath.', 16, 0, 0, 0, 0, 0, 'Heigan SAY_DEATH');


-- Instructor Razuvious
DELETE FROM `creature_text` WHERE `entry` = 16061;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(16061, 0, 0, 'Do as I taught you!', 14, 0, 0, 0, 0, 8855, 'Razuvious SAY_AGGRO'),
(16061, 0, 1, 'Show them no mercy!', 14, 0, 0, 0, 0, 8856, 'Razuvious SAY_AGGRO'),
(16061, 0, 3, 'Sweep the leg! Do you have a problem with that?', 14, 0, 0, 0, 0, 8861, 'Razuvious SAY_AGGRO'),
(16061, 0, 2, 'The time for practice is over! Show me what you\'ve learned!', 14, 0, 0, 0, 0, 8859, 'Razuvious SAY_AGGRO'),
(16061, 1, 0, 'Hah hah, I\'m just getting warmed up!', 14, 0, 0, 0, 0, 8852, 'Razuvious SAY_COMMND'),
(16061, 1, 2, 'Show me what you\'ve got!', 14, 0, 0, 0, 0, 8854, 'Razuvious SAY_COMMND'),
(16061, 1, 1, 'Stand and fight!', 14, 0, 0, 0, 0, 8853, 'Razuvious SAY_COMMND'),
(16061, 1, 4, 'You disappoint me, students!', 14, 0, 0, 0, 0, 8858, 'Razuvious SAY_COMMND'),
(16061, 1, 3, 'You should\'ve stayed home!', 14, 0, 0, 0, 0, 8861, 'Razuvious SAY_COMMND'),
(16061, 2, 0, 'An honorable... death...', 14, 0, 0, 0, 0, 8860, 'Razuvious SAY_DEATH');

-- Gothik the Harvester
DELETE FROM `creature_text` WHERE `entry` = 16060;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(16060, 0, 0, 'Foolishly you have sought your own demise. Brazenly you have disregarded powers beyond your understanding. You have fought hard to invade the realm of the harvester. Now there is only one way out - to walk the lonely path of the damned.', 14, 0, 0, 0, 0, 8807, 'Gothik SAY_SPEECH'),
(16060, 1, 0, 'Death is the only escape.', 14, 0, 0, 0, 0, 8806, 'Gothik SAY_KILL'),
(16060, 2, 0, 'I... am... undone!', 14, 0, 0, 0, 0, 8805, 'Gothik SAY_DEATH'),
(16060, 3, 0, 'I have waited long enough! Now, you face the harvester of souls!', 14, 0, 0, 0, 0, 8808, 'Gothik SAY_TELEPORT');

-- Thane Korth'azz
DELETE FROM `creature_text` WHERE `entry` = 16064;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(16064, 0, 0, 'Come out and fight, ye wee ninny!', 14, 0, 0, 0, 0, 8899, 'Korthazz SAY_AGGRO'),
(16064, 1, 0, 'What a bloody waste this is!', 14, 0, 0, 0, 0, 8900, 'Korthazz SAY_DEATH'),
(16064, 2, 0, 'Next time, bring more friends!', 14, 0, 0, 0, 0, 8901, 'Korthazz SAY_KILL'),
(16064, 3, 0, 'I like my meat extra crispy!', 14, 0, 0, 0, 0, 8902, 'Korthazz SAY_SPECIAL'),
(16064, 4, 1, 'I\'m gonna enjoy killin\' these slack-jawed daffodils!', 14, 0, 0, 0, 0, 8905, 'Korthazz SAY_TAUNT'),
(16064, 4, 0, 'To arms, ye roustabouts! We\'ve got company!', 14, 0, 0, 0, 0, 8903, 'Korthazz SAY_TAUNT'),
(16064, 5, 0, 'I heard about enough of yer sniveling. Shut yer fly trap \'afore I shut it for ye!', 14, 0, 0, 0, 0, 8904, 'Korthazz SAY_HORSEMEN_6');

-- Thane Korth'azz
DELETE FROM `creature_text` WHERE `entry` = 16065;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(16065, 0, 0, 'Defend yourself!', 14, 0, 0, 0, 0, 8892, 'Blaumeux SAY_AGGRO'),
(16065, 1, 0, 'Tou... ché!', 14, 0, 0, 0, 0, 8893, 'Blaumeux SAY_DEATH'),
(16065, 2, 0, 'Who\'s next?', 14, 0, 0, 0, 0, 8894, 'Blaumeux SAY_KILL'),
(16065, 3, 0, 'Your life is mine!', 14, 0, 0, 0, 0, 8895, 'Blaumeux SAY_SPECIAL'),
(16065, 4, 0, 'The first kill goes to me! Anyone care to wager?', 14, 0, 0, 0, 0, 8898, 'Blaumeux SAY_TAUNT'),
(16065, 5, 0, 'Come, Zeliek, do not drive them out. Not before we\'ve had our fun.', 14, 0, 0, 0, 0, 8896, 'Blaumeux SAY_HORSEMEN_2'),
(16065, 6, 0, 'I do hope they stay alive long enough for me to... introduce myself.', 14, 0, 0, 0, 0, 8897, 'Blaumeux SAY_HORSEMEN_4');

-- Baron Rivendare
DELETE FROM `creature_text` WHERE `entry` = 30549;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(30549, 0, 2, 'Be still!', 14, 0, 0, 0, 0, 14573, 'Rivendare SAY_AGGRO'),
(30549, 0, 1, 'None shall pass!', 14, 0, 0, 0, 0, 14572, 'Rivendare SAY_AGGRO'),
(30549, 0, 0, 'You seek death?', 14, 0, 0, 0, 0, 14571, 'Rivendare SAY_AGGRO'),
(30549, 1, 0, 'I...am...released! Perhaps it\'s not too late to — noo! I need...more time...', 14, 0, 0, 0, 0, 14580, 'Rivendare SAY_DEATH'),
(30549, 2, 1, 'The master\'s will is done.', 14, 0, 0, 0, 0, 14575, 'Rivendare SAY_KILL'),
(30549, 2, 0, 'You will find no peace in death.', 14, 0, 0, 0, 0, 14574, 'Rivendare SAY_KILL'),
(30549, 3, 0, 'Bow to the might of the Highlord!', 14, 0, 0, 0, 0, 14576, 'Rivendare SAY_SPECIAL'),
(30549, 4, 0, 'Life is meaningless. It is in death that we are truly tested.', 14, 0, 0, 0, 0, 14579, 'Rivendare SAY_TAUNT'),
(30549, 5, 0, 'Enough prattling. Let them come! We shall grind their bones to dust.', 14, 0, 0, 0, 0, 14577, 'Rivendare SAY_HORSEMEN_3'),
(30549, 6, 0, 'Conserve your anger! Harness your rage! You will all have outlets for your frustration soon enough.', 14, 0, 0, 0, 0, 14578, 'Rivendare SAY_HORSEMEN_7');

-- Sir Zeliek
DELETE FROM `creature_text` WHERE `entry` = 16063;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(16063, 0, 0, 'Flee, before it\'s too late!', 14, 0, 0, 0, 0, 8913, 'Zeliek SAY_AGGRO'),
(16063, 1, 0, 'It is... as it should be.', 14, 0, 0, 0, 0, 8914, 'Zeliek SAY_DEATH'),
(16063, 2, 0, 'Forgive me!', 14, 0, 0, 0, 0, 8915, 'Zeliek SAY_KILL'),
(16063, 3, 0, 'I- I have no choice but to obey!', 14, 0, 0, 0, 0, 8916, 'Zeliek SAY_SPECIAL'),
(16063, 4, 0, 'Do not continue! Turn back while there\'s still time!', 14, 0, 0, 0, 0, 8919, 'Zeliek SAY_TAUNT'),
(16063, 5, 0, 'Invaders, cease this foolish venture at once! Turn away while you still can!', 14, 0, 0, 0, 0, 8917, 'Zeliek SAY_HORSEMEN_1'),
(16063, 6, 0, 'Perhaps they will come to their senses, and run away as fast as they can!', 14, 0, 0, 0, 0, 8918, 'Zeliek SAY_HORSEMEN_5');

-- Patchwerk
DELETE FROM `creature_text` WHERE `entry` = 16028;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(16028, 0, 1, 'Kel\'Thuzad make Patchwerk his avatar of war!', 14, 0, 0, 0, 0, 8910, 'Patchwerk SAY_AGGRO'),
(16028, 0, 0, 'Patchwerk want to play.', 14, 0, 0, 0, 0, 8909, 'Patchwerk SAY_AGGRO'),
(16028, 1, 0, 'No more play?', 14, 0, 0, 0, 0, 8912, 'Patchwerk SAY_KILL'),
(16028, 2, 0, 'What happened to... Patch...', 14, 0, 0, 0, 0, 8911, 'Patchwerk SAY_DEATH'),
(16028, 3, 0, '%s goes into a berserker rage!', 16, 0, 0, 0, 0, 0, 'Patchwerk EMOTE_BERSERK'),
(16028, 4, 0, 'Patchwerk becomes enraged!', 41, 0, 0, 0, 0, 0, 'Patchwerk EMOTE_ENRAGE');

-- Grobbulus
DELETE FROM `creature_text` WHERE `entry` = 15931;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(15931, 0, 0, 'Grobbulus sprays slime across the room!', 41, 0, 0, 0, 0, 0, 'Grobbulus EMOTE_SPRAY');

-- Gluth
DELETE FROM `creature_text` WHERE `entry` = 15932;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(15932, 0, 0, 'Gluth becomes enraged!', 41, 0, 0, 0, 0, 0, 'Gluth EMOTE_ENRAGE'),
(15932, 1, 0, 'Gluth decimates all nearby flesh!', 41, 0, 0, 0, 0, 0, 'Gluth EMOTE_DECIMATE'),
(15932, 2, 0, '%s spots a nearby zombie to devour!', 41, 0, 0, 0, 0, 0, 'Gluth EMOTE_NEARBY');

-- Thaddius
DELETE FROM `creature_text` WHERE `entry` = 15928;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(15928, 0, 0, 'You are too late... I... must... OBEY!', 14, 0, 0, 0, 0, 8872, 'Thaddius SAY_GREET'),
(15928, 1, 1, 'BREAK YOU!', 14, 0, 0, 0, 0, 8869, 'Thaddius SAY_AGGRO'),
(15928, 1, 0, 'EAT YOUR BONES!', 14, 0, 0, 0, 0, 8868, 'Thaddius SAY_AGGRO'),
(15928, 1, 2, 'KILL!', 14, 0, 0, 0, 0, 8867, 'Thaddius SAY_AGGRO'),
(15928, 2, 0, 'Thank... you...', 14, 0, 0, 0, 0, 8870, 'Thaddius SAY_DEATH'),
(15928, 3, 0, 'Now you feel pain!', 14, 0, 0, 0, 0, 8871, 'Thaddius SAY_ELECT'),
(15928, 4, 0, 'You die now!', 14, 0, 0, 0, 0, 8877, 'Thaddius SAY_KILL'),
(15928, 5, 0, 'The polarity has shifted!', 41, 0, 0, 0, 0, 0, 'Thaddis EMOTE_SHIFT');

-- Stalagg
DELETE FROM `creature_text` WHERE `entry` = 15929;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(15929, 0, 0, 'Stalagg crush you!', 14, 0, 0, 0, 0, 8864, 'Stalagg SAY_AGGRO'),
(15929, 1, 0, 'Stalagg kill!', 14, 0, 0, 0, 0, 8866, 'Stalagg SAY_KILL'),
(15929, 2, 0, 'Master save me...', 14, 0, 0, 0, 0, 8865, 'Stalagg SAY_DEATH');

-- Feugen
DELETE FROM `creature_text` WHERE `entry` = 15930;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(15930, 0, 0, 'Feed you to master!', 14, 0, 0, 0, 0, 8802, 'Feugen SAY_AGGRO'),
(15930, 1, 0, 'Feugen make master happy!', 14, 0, 0, 0, 0, 8804, 'Feugen SAY_KILL'),
(15930, 2, 0, 'No... more... Feugen...', 14, 0, 0, 0, 0, 8803, 'Feugen SAY_DEATH');

-- Sapphiron
DELETE FROM `creature_text` WHERE `entry` = 15989;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(15989, 0, 0, 'Sapphiron takes a deep breath.', 41, 0, 0, 0, 0, 0, 'Sapphiron EMOTE_BREATH'),
(15989, 1, 0, '%s enrages!', 16, 0, 0, 0, 0, 0, 'Sapphiron EMOTE_ENRAGE'),
(15989, 2, 0, 'Sapphiron lifts off into the air!', 41, 0, 0, 0, 0, 0, 'Sapphiron EMOTE_AIR'),
(15989, 3, 0, 'Sapphiron resmues his attacks!', 41, 0, 0, 0, 0, 0, 'Sapphiron EMOTE_LAND');

-- Kel'Thuzad
DELETE FROM `creature_text` WHERE `entry` = 15990;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(15990, 0, 0, 'Minions, servants, soldiers of the cold dark, obey the call of Kel\'Thuzad!', 14, 0, 0, 0, 0, 14471, 'Kelthuzad SAY_SUMMON'),
(15990, 1, 0, 'Pray for mercy!', 14, 0, 0, 0, 0, 14475, 'Kelthuzad SAY_AGGRO'),
(15990, 1, 1, 'Scream your dying breath!', 14, 0, 0, 0, 0, 14476, 'Kelthuzad SAY_AGGRO'),
(15990, 1, 2, 'The end is upon you!', 14, 0, 0, 0, 0, 14477, 'Kelthuzad SAY_AGGRO'),
(15990, 2, 1, '%s cackles maniacally!', 16, 0, 0, 0, 0, 14479, 'Kelthuzad SAY_KILL'),
(15990, 2, 0, 'The dark void awaits you!', 14, 0, 0, 0, 0, 14478, 'Kelthuzad SAY_KILL'),
(15990, 3, 0, 'AAAAGHHH!... Do not rejoice... your victory is a hollow one... for I shall return with powers beyond your imagining!', 14, 0, 0, 0, 0, 14480, 'Kelthuzad SAY_DEATH'),
(15990, 4, 0, 'There will be no escape!', 14, 0, 0, 0, 0, 14473, 'Kelthuzad SAY_CHAIN'),
(15990, 4, 1, 'Your soul, is bound to me now!', 14, 0, 0, 0, 0, 14472, 'Kelthuzad SAY_CHAIN'),
(15990, 5, 0, 'I will freeze the blood in your veins!', 14, 0, 0, 0, 0, 14474, 'Kelthuzad SAY_FROST_BLAST'),
(15990, 6, 2, 'Enough! I grow tired of these distractions! ', 14, 0, 0, 0, 0, 14483, 'Kelthuzad SAY_SPECIAL'),
(15990, 6, 1, 'Fools, you have spread your powers too thin. Be free, my minions!', 14, 0, 0, 0, 0, 14482, 'Kelthuzad SAY_SPECIAL'),
(15990, 6, 0, 'Your petty magics are no challenge to the might of the Scourge! ', 14, 0, 0, 0, 0, 14481, 'Kelthuzad SAY_SPECIAL'),
(15990, 7, 0, 'Master! I require aid! ', 14, 0, 0, 0, 0, 14470, 'Kelthuzad SAY_AID'),
(15990, 8, 0, 'Kel\'Thuzad strikes.', 41, 0, 0, 0, 0, 0, 'Kelthuzad EMOTE_ATTACK'),
(15990, 9, 0, 'A Guardian of Icecrown enters the fight.', 41, 0, 0, 0, 0, 0, 'Kelthuzad EMOTE_GUARDIAN'),
(15990, 10, 0, 'No!!! A curse upon you, interlopers! The armies of the Lich King will hunt you down. You will not escape your fate...', 14, 0, 0, 0, 0, 14484, 'Kelthuzad SAY_CAT_DIE'),
(15990, 11, 2, 'Fools, you think yourselves triumphant? You have only taken one step closer to the abyss! ', 14, 0, 0, 0, 0, 14464, 'Kelthuzad SAY_TAUNT'),
(15990, 11, 3, 'I grow tired of these games. Proceed, and I will banish your souls to oblivion!', 14, 0, 0, 0, 0, 14465, 'Kelthuzad SAY_TAUNT'),
(15990, 11, 0, 'Who dares violate the sanctity of my domain? Be warned, all who trespass here are doomed.', 14, 0, 0, 0, 0, 14463, 'Kelthuzad SAY_TAUNT'),
(15990, 11, 1, 'You have no idea what horrors lie ahead. You have seen nothing! The frozen heart of Naxxramas awaits you!', 14, 0, 0, 0, 0, 14466, 'Kelthuzad SAY_TAUNT'),
(15990, 12, 0, 'Your forces are nearly marshalled to strike back against your enemies, my liege.', 14, 0, 0, 0, 0, 14467, 'Kelthuzad SAY_SAPP_DIALOG1'),
(15990, 13, 0, 'Yes, Master. The time of their ultimate demise grows close...What is this?', 14, 0, 0, 0, 0, 14468, 'Kelthuzad SAY_SAPP_DIALOG3'),
(15990, 14, 0, 'As you command, Master!', 14, 0, 0, 0, 0, 14469, 'Kelthuzad SAY_SAPP_DIALOG5');

-- Lich king
DELETE FROM `creature_text` WHERE `entry` = 16980;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(16980, 0, 0, 'Intruders have breached the inner sanctum. Hasten the destruction of the green dragon! Leave only bones and sinew for the reanimation!', 14, 0, 0, 0, 0, 17251, 'The Lich King - SAY_LICH_KING_INTRO'),
(16980, 1, 0, 'Soon we will eradicate the Alliance and Horde, then the rest of Azeroth will fall before the might of my army.', 14, 0, 0, 0, 0, 14768, 'The Lich King SAY_SAPP_DIALOG2_LICH'),
(16980, 2, 0, 'Invaders...here?! DESTROY them, Kel\'Thuzad! Naxxramas must not fall!', 14, 0, 0, 0, 0, 14769, 'The Lich King SAY_SAPP_DIALOG4_LICH'),
(16980, 3, 0, 'Very well... warriors of the frozen wastes, rise up! I command you to fight, kill, and die for your master. Let none survive...', 14, 0, 0, 0, 0, 8824, 'The Lich King SAY_ANSWER');

-- Portals
DELETE FROM `gameobject_template` WHERE `entry` IN (181575,181576,181577,181578);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `WDBVerified`) VALUES
(181575, 10, 6787, 'Naxxramas Portal', '', '', '', 0, 33, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28444, 1, 129, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 'go_naxxramas_portal', 12340),
(181578, 10, 6790, 'Naxxramas Portal', '', '', '', 0, 33, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28444, 1, 129, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 'go_naxxramas_portal', 11159),
(181576, 10, 6788, 'Naxxramas Portal', '', '', '', 0, 33, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28444, 1, 129, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 'go_naxxramas_portal', 12340),
(181577, 10, 6789, 'Naxxramas Portal', '', '', '', 0, 33, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28444, 1, 129, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 'go_naxxramas_portal', 12340);

-- Portal spawn
SET @GUID := xxxx; -- SET BY TRINITY
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@GUID, 181575, 533, 3, 1, 3551.17, -3870.71, 296.645, 6.22971, 0, 0, 0.026733, -0.999643, 300, 0, 1),
(@GUID+1, 181576, 533, 3, 1, 3537.55, -2935.77, 302.593, 2.55691, 0, 0, 0.957572, 0.288195, 300, 0, 1),
(@GUID+2, 181577, 533, 3, 1, 2910.22, -4025.31, 273.596, 3.03422, 0, 0, 0.998559, 0.0536602, 300, 0, 1),
(@GUID+3, 181578, 533, 3, 1, 2489.34, -2919.75, 241.277, 2.23655, 0, 0, 0.899347, 0.437235, 300, 0, 1);

-- Achievement
INSERT INTO achievement_criteria_data (criteria_id, type, value1, value2, ScriptName) VALUES
(7567, 11, 0, 0, 'achievement_the_hundred_club'),
(7568, 11, 0, 0, 'achievement_the_hundred_club');

-- Creature spawn
SET @GUID2 := xxxx; -- SET BY TRINITY
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@GUID2, 16980, 533, 1, 1, 0, 0, 3446.51, -5251.26, 197.478, 3.25858, 300, 0, 0, 4120, 0, 0, 0, 0, 0);

/* NAXXRAMAS */
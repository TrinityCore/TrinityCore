-- NAXXRAMAS -- 
-- Creature texts

-- Anub'Rekhan
DELETE FROM `creature_text` WHERE `entry` = 15956;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(15956, 0, 0, 'Just a little taste...', 14, 0, 100, 0, 0, 8785, 'anubrekhan SAY_AGGRO1'),
(15956, 0, 1, 'There is no way out.', 14, 0, 100, 0, 0, 8786, 'anubrekhan SAY_AGGRO2'),
(15956, 0, 2, 'Yes, run! It makes the blood pump faster!', 14, 0, 100, 0, 0, 8787, 'anubrekhan SAY_AGGRO3'),
(15956, 1, 0, 'Ahh... welcome to my parlor.', 14, 0, 100, 0, 0, 8788, 'anubrekhan SAY_GREET1'),
(15956, 1, 1, 'I hear little hearts beating. Yes... beating faster now... soon the beating will stop.', 14, 0, 100, 0, 0, 8790, 'anubrekhan SAY_GREET2'),
(15956, 1, 2, 'Where to go? What to do? So many choices that all end in pain, end in death.', 14, 0, 100, 0, 0, 8791, 'anubrekhan SAY_GREET3'),
(15956, 1, 3, 'Which one shall I eat first? So difficult to choose. They all smell so delicious...', 14, 0, 100, 0, 0, 8792, 'anubrekhan SAY_GREET4'),
(15956, 1, 4, 'Closer now. Tasty morsels. I\'ve been too long without food, without blood to drink.', 14, 0, 100, 0, 0, 8793, 'anubrekhan SAY_GREET5'),
(15956, 2, 0, 'Shhh... it will all be over soon.', 14, 0, 100, 0, 0, 8789, 'anubrekhan SAY_SLAY'),
(15956, 3, 0, 'Anub\'Rekhan begins to unleash an insect swarm!', 41, 0, 0, 0, 0, 0, 'anubrekhan EMOTE_LOCUST_SWARM'),
(15956, 4, 0, ' A Crypt Guard joins the fight!', 41, 0, 0, 0, 0, 0, 'anubrekhan EMOTE_CRYPT_GUARD'),
(15956, 5, 0, 'Corpse Scarabs appears from a Crypt Guard\'s corpse!', 41, 0, 0, 0, 0, 0, 'anubrekhan EMOTE_CORPSE_SCARAB');

-- Grand Widow Faerlina
DELETE FROM `creature_text` WHERE `entry` = 15953;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(15953, 0, 0, 'Your old lives, your mortal desires mean nothing... you are acolytes of the master now, and you will serve the cause without question! The greatest glory is to die in the master\'s service!', 14, 0, 100, 0, 0, 8799, 'faerlina SAY_GREET'),
(15953, 1, 1, 'You cannot hide from me!', 14, 0, 100, 0, 0, 8795, 'faerlina SAY_AGGRO1'),
(15953, 1, 2, 'Kneel before me, worm!', 14, 0, 100, 0, 0, 8796, 'faerlina SAY_AGGRO2'),
(15953, 1, 3, 'Run while you still can!', 14, 0, 100, 0, 0, 8797, 'faerlina SAY_AGGRO3'),
(15953, 1, 4, 'Slay them in the master\'s name!', 14, 0, 100, 0, 0, 8794, 'faerlina SAY_AGGRO4'),
(15953, 2, 0, 'You have failed!', 14, 0, 100, 0, 0, 8800, 'faerlina SAY_SLAY1'),
(15953, 2, 1, 'Pathetic wretch!', 14, 0, 100, 0, 0, 8801, 'faerlina SAY_SLAY2'),
(15953, 3, 0, 'The master will avenge me!!', 14, 0, 100, 0, 0, 8798, 'faerlina SAY_DEATH'),
(15953, 4, 0, 'Slay them in the master\'s name!', 14, 0, 100, 0, 0, 8794, 'faerlina SAY_ENRAGE');


-- Four Horsemen
-- Thane Korth'azz
DELETE FROM `creature_text` WHERE `entry` = 16064;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(16064, 0, 0, 'Come out and fight, ye wee ninny!', 14, 0, 100, 0, 0, 8899, 'korthazz SAY_KORT_AGGRO'),
(16064, 1, 0, 'To arms, ye roustabouts! We\'ve got company!', 14, 0, 100, 0, 0, 8903, 'korthazz SAY_KORT_TAUNT1'),
(16064, 2, 0, 'I like my meat extra crispy!', 14, 0, 100, 0, 0, 8902, 'korthazz SAY_KORT_SPECIAl'),
(16064, 3, 0, 'Next time, bring more friends!', 14, 0, 100, 0, 0, 8901, 'korthazz SAY_KORT_SLAY'),
(16064, 4, 0, 'What a bloody waste this is!', 14, 0, 100, 0, 0, 8900, 'korthazz SAY_KORT_DEATH'),
(16064, 5, 0, 'I heard about enough of yer sniveling. Shut yer fly trap \'afore I shut it for ye!', 14, 0, 0, 0, 0, 8904, 'Korthazz SAY_HORSEMEN_6'),
(16064, 6, 0, 'I\'m gonna enjoy killin\' these slack-jawed daffodils!', 14, 0, 100, 0, 0, 8905, 'korthazz SAY_KORT_TAUNT3');

-- Lady Blaumeux
DELETE FROM `creature_text` WHERE `entry` = 16065;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(16065, 0, 0, 'Defend youself!', 14, 0, 100, 0, 0, 8892, 'blaumeux SAY_BLAU_AGGRO'),
(16065, 1, 0, 'The first kill goes to me! Anyone care to wager?', 14, 0, 100, 0, 0, 8898, 'blaumeux SAY_BLAU_TAUNT3'),
(16065, 2, 0, 'Your life is mine!', 14, 0, 100, 0, 0, 8895, 'blaumeux SAY_BLAU_SPECIAL'),
(16065, 3, 0, 'Who\'s next?', 14, 0, 100, 0, 0, 8894, 'blaumeux SAY_BLAU_SLAY'),
(16065, 4, 0, 'Tou... che!', 14, 0, 100, 0, 0, 8893, 'blaumeux SAY_BLAU_DEATH'),
(16065, 5, 0, 'Come, Zeliek, do not drive them out. Not before we\'ve had our fun.', 14, 0, 0, 0, 0, 8896, 'Blaumeux SAY_HORSEMEN_2'),
(16065, 6, 0, 'I do hope they stay alive long enough for me to... introduce myself.', 14, 0, 0, 0, 0, 8897, 'Blaumeux SAY_HORSEMEN_4');

-- Baron Rivendare
DELETE FROM `creature_text` WHERE `entry` = 30549;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(30549, 0, 0, 'You seek death?', 14, 0, 100, 0, 0, 14571, 'rivendare SAY_RIVE_AGGRO1'),
(30549, 0, 1, 'None shall pass!', 14, 0, 100, 0, 0, 14572, 'rivendare SAY_RIVE_AGGRO2'),
(30549, 0, 2, 'Be still!', 14, 0, 100, 0, 0, 14573, 'rivendare SAY_RIVE_AGGRO3'),
(30549, 1, 2, 'Life is meaningless. It is in death that we are truly tested.', 14, 0, 100, 0, 0, 14579, 'rivendare SAY_RIVE_TAUNT3'),
(30549, 2, 0, 'Bow to the might of the scourge!', 14, 0, 100, 0, 0, 14576, 'rivendare SAY_RIVE_SPECIAL'),
(30549, 3, 0, 'You will find no peace in death.', 14, 0, 100, 0, 0, 14574, 'rivendare SAY_RIVE_SLAY1'),
(30549, 3, 1, 'The master\'s will is done.', 14, 0, 100, 0, 0, 14575, 'rivendare SAY_RIVE_SLAY2'),
(30549, 4, 0, 'Death... will not stop me...', 14, 0, 100, 0, 0, 14580, 'rivendare SAY_RIVE_DEATH'),
(30549, 5, 0, 'Enough prattling. Let them come! We shall grind their bones to dust.', 14, 0, 0, 0, 0, 14577, 'Rivendare SAY_HORSEMEN_3'),
(30549, 6, 0, 'Conserve your anger! Harness your rage! You will all have outlets for your frustration soon enough.', 14, 0, 0, 0, 0, 14578, 'Rivendare SAY_HORSEMEN_7');

-- Sir Zeliek
DELETE FROM `creature_text` WHERE `entry` = 16063;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(16063, 0, 0, 'Do not continue! Turn back while there\'s still time!', 14, 0, 100, 0, 0, 8919, 'zeliek SAY_ZELI_TAUNT3'),
(16063, 1, 0, 'Flee, before it\'s too late!', 14, 0, 100, 0, 0, 8913, 'zeliek SAY_ZELI_AGGRO'),
(16063, 2, 0, 'I- I have no choice but to obey!', 14, 0, 100, 0, 0, 8916, 'zeliek SAY_ZELI_SPECIAL'),
(16063, 3, 0, 'Forgive me!', 14, 0, 100, 0, 0, 8915, 'zeliek SAY_ZELI_SLAY'),
(16063, 4, 0, 'It is... as it should be.', 14, 0, 100, 0, 0, 8914, 'zeliek SAY_ZELI_DEATH'),
(16063, 5, 0, 'Invaders, cease this foolish venture at once! Turn away while you still can!', 14, 0, 0, 0, 0, 8917, 'Zeliek SAY_HORSEMEN_1'),
(16063, 6, 0, 'Perhaps they will come to their senses, and run away as fast as they can!', 14, 0, 0, 0, 0, 8918, 'Zeliek SAY_HORSEMEN_5');

-- Gluth
DELETE FROM `creature_text` WHERE `entry` = 15932;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(15932, 0, 0, 'Gluth becomes enraged!', 41, 0, 0, 0, 0, 0, 'Gluth EMOTE_ENRAGE'),
(15932, 1, 0, 'Gluth decimates all nearby flesh!', 41, 0, 0, 0, 0, 0, 'Gluth EMOTE_DECIMATE'),
(15932, 2, 0, '%s spots a nearby zombie to devour!', 41, 0, 0, 0, 0, 0, 'Gluth EMOTE_NEARBY');

-- Gothik the Harvester
DELETE FROM `creature_text` WHERE `entry` = 16060;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(16060, 0, 0, 'Foolishly you have sought your own demise. Brazenly you have disregarded powers beyond your understanding. You have fought hard to invade the realm of the harvester. Now there is only one way out - to walk the lonely path of the damned.', 14, 0, 100, 0, 0, 8807, 'gothik SAY_SPEECH'),
(16060, 1, 0, 'Death is the only escape.', 14, 0, 100, 0, 0, 8806, 'gothik SAY_KILL'),
(16060, 2, 0, 'I... am... undone!', 14, 0, 100, 0, 0, 8805, 'gothik SAY_DEATH'),
(16060, 3, 0, 'I have waited long enough! Now, you face the harvester of souls!', 14, 0, 100, 0, 0, 8808, 'gothik SAY_TELEPORT');

-- Grobbulus
DELETE FROM `creature_text` WHERE `entry` = 15931;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(15931, 0, 0, 'Grobbulus sprays slime across the room!', 41, 0, 0, 0, 0, 0, 'Grobbulus EMOTE_SPRAY');

-- Heigan the Unclean
DELETE FROM `creature_text` WHERE `entry` = 15936;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(15936, 0, 1, 'I see you...', 14, 0, 0, 0, 0, 8826, 'Heigan SAY_AGGRO'),
(15936, 0, 0, 'You are mine now.', 14, 0, 0, 0, 0, 8825, 'Heigan SAY_AGGRO'),
(15936, 0, 2, 'You... are next.', 14, 0, 0, 0, 8827, 0, 'Heigan SAY_AGGRO'),
(15936, 1, 0, 'Close your eyes. Sleep.', 14, 0, 0, 0, 0, 8829, 'Heigan SAY_KILL'),
(15936, 2, 0, 'The end is upon you.', 14, 0, 0, 0, 0, 8833, 'Heigan SAY_PHASE'),
(15936, 3, 0, 'Heigan the Unclean teleports and begins to channel  a spell!', 41, 0, 0, 0, 0, 0, 'Heigan EMOTE_TELEPORT'),
(15936, 4, 0, 'Heigan the Unclean rushes to attack once more!', 41, 0, 0, 0, 0, 0, 'Heigan EMOTE_TELEPORT'),
(15936, 5, 0, '%s takes his last breath.', 16, 0, 0, 0, 0, 0, 'Heigan SAY_DEATH');

-- Kel'Thuzad
DELETE FROM `creature_text` WHERE `entry` = 15990;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(15990, 0, 0, 'No!!! A curse upon you, interlopers! The armies of the Lich King will hunt you down. You will not escape your fate...', 14, 0, 100, 0, 0, 14484, 'kelthuzad SAY_CAT_DIED'),
(15990, 1, 0, 'Who dares violate the sanctity of my domain? Be warned, all who trespass here are doomed.', 14, 0, 100, 0, 0, 14463, 'kelthuzad SAY_TAUNT1'),
(15990, 2, 0, 'Fools! You think yourselves triumphant? You have only taken one step closer to the abyss!', 14, 0, 100, 0, 0, 14464, 'kelthuzad SAY_TAUNT2'),
(15990, 3, 0, 'I grow tired of these games. Proceed, and I will banish your souls to oblivion!', 14, 0, 100, 0, 0, 14465, 'kelthuzad SAY_TAUNT3'),
(15990, 4, 0, 'You have no idea what horrors lie ahead. You have seen nothing! The frozen heart of Naxxramas awaits you!', 14, 0, 100, 0, 0, 14466, 'kelthuzad SAY_TAUNT4'),
(15990, 5, 0, 'Your forces are nearly marshaled to strike back against your enemies, my liege.', 14, 0, 100, 0, 0, 14467, 'kelthuzad SAY_SAPP_DIALOG1'),
(15990, 6, 0, 'Yes, master. The time of their ultimate demise draws close.... What is this?', 14, 0, 100, 0, 0, 14468, 'kelthuzad SAY_SAPP_DIALOG3'),
(15990, 7, 0, 'As you command, master!', 14, 0, 100, 0, 0, 14469, 'kelthuzad SAY_SAPP_DIALOG5'),
(15990, 8, 0, 'Pray for mercy!', 14, 0, 100, 0, 0, 14475, 'kelthuzad SAY_AGGRO1'),
(15990, 8, 1, 'Scream your dying breath!', 14, 0, 100, 0, 0, 14476, 'kelthuzad SAY_AGGRO2'),
(15990, 8, 2, 'The end is upon you!', 14, 0, 100, 0, 0, 14477, 'kelthuzad SAY_AGGRO3'),
(15990, 9, 0, 'The dark void awaits you!', 14, 0, 100, 0, 0, 14478, 'kelthuzad SAY_SLAY1'),
(15990, 9, 1, '%s cackles maniacally.', 16, 0, 100, 0, 0, 14479, 'kelthuzad SAY_SLAY2'),
(15990, 10, 0, 'Agghhhh! Do... not... rejoice! Your victory is a hollow one, for I shall return with powers beyond your imagining!', 14, 0, 100, 0, 0, 14480, 'kelthuzad SAY_DEATH'),
(15990, 11, 0, 'Your soul is bound to me, now!', 14, 0, 100, 0, 0, 14472, 'kelthuzad SAY_CHAIN1'),
(15990, 11, 1, 'There will be no escape!', 14, 0, 100, 0, 0, 14473, 'kelthuzad SAY_CHAIN2'),
(15990, 12, 0, 'I will freeze the blood in your veins!', 14, 0, 100, 0, 0, 14474, 'kelthuzad SAY_FROST_BLAST'),
(15990, 13, 0, 'Master, I require aid!', 14, 0, 100, 0, 0, 14470, 'kelthuzad SAY_REQUEST_AID'),
(15990, 14, 0, 'Minions, servants, soldiers of the cold dark! Obey the call of Kel\'Thuzad!', 14, 0, 100, 0, 0, 14471, 'kelthuzad SAY_SUMMON_MINIONS'),
(15990, 15, 0, 'Your petty magics are no challenge to the might of the Scourge! ', 14, 0, 100, 0, 0, 14481, 'kelthuzad SAY_SPECIAL1_MANA_DET'),
(15990, 15, 1, 'Enough! I grow tired of these distractions! ', 14, 0, 100, 0, 0, 14483, 'kelthuzad SAY_SPECIAL3_MANA_DET'),
(15990, 15, 2, 'Fools, you have spread your powers too thin. Be free, my minions!', 14, 0, 100, 0, 0, 14482, 'kelthuzad SAY_SPECIAL2_DISPELL'),
(15990, 16, 0, 'Kel\'Thuzad strikes.', 41, 0, 0, 0, 0, 0, 'Kelthuzad EMOTE_ATTACK'),
(15990, 17, 0, 'A Guardian of Icecrown enters the fight.', 41, 0, 0, 0, 0, 0, 'Kelthuzad EMOTE_GUARDIAN');

-- Loatheb
DELETE FROM `creature_text` WHERE `entry` = 16011;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(16011, 0, 0, 'An aura of necrotic energy blocks all healing!', 41, 0, 100, 0, 0, 0, 'Loatheb_AURA_APPLIED'),
(16011, 1, 0, 'The aura fades away, allowing for healing once more!', 41, 0, 100, 0, 0, 0, 'Loatheb_AURA_REMOVED'),
(16011, 2, 0, 'The aura\'s power begins to wane!', 41, 0, 100, 0, 0, 0, 'Loatheb_AURA_FADING');

-- Maexxna
DELETE FROM `creature_text` WHERE `entry` = 15952;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(15952, 0, 0, 'Maexxna spins her web into a coccon!', 41, 0, 0, 0, 0, 0, 'Maexxna EMOTE_WRAP'),
(15952, 1, 0, 'Spiderlings appear on the web!', 41, 0, 0, 0, 0, 0, 'Maexxna EMOTE_SPIDERLING');

-- Noth
DELETE FROM `creature_text` WHERE `entry` = 15954;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(15954, 0, 0, 'Glory to the master!', 14, 0, 100, 0, 0, 8845, 'noth SAY_AGGRO1'),
(15954, 0, 1, 'Your life is forfeit!', 14, 0, 100, 0, 0, 8846, 'noth SAY_AGGRO2'),
(15954, 0, 2, 'Die, trespasser!', 14, 0, 100, 0, 0, 8847, 'noth SAY_AGGRO3'),
(15954, 1, 0, 'Rise, my soldiers! Rise and fight once more!', 14, 0, 100, 0, 0, 8851, 'noth SAY_SUMMON'),
(15954, 2, 0, 'My task is done!', 14, 0, 100, 0, 0, 8849, 'noth SAY_SLAY1'),
(15954, 2, 1, 'Breathe no more!', 14, 0, 100, 0, 0, 8850, 'noth SAY_SLAY2'),
(15954, 3, 0, 'I will serve the master... in... death!', 14, 0, 100, 0, 0, 8848, 'noth SAY_DEATH'),
(15954, 4, 0, 'Noth the Plaguebringer summons forth Skeletal Warrios!', 41, 0, 0, 0, 0, 0, 'noth EMOTE_SUMMON'),
(15954, 5, 0, 'Noth the Plaguebringer teleports to the balcony above!', 41, 0, 0, 0, 0, 0, 'noth EMOTE_BALCONY'),
(15954, 6, 0, 'Noth the Plaguebringer raises more skeletons!', 41, 0, 0, 0, 0, 0, 'noth EMOTE_SKELETON'),
(15954, 7, 0, 'Noth the Plaguebringer teleports back into the battle!', 41, 0, 0, 0, 0, 0, 'noth EMOTE_TELEPORT'),
(15954, 8, 0, 'Noth the Plaguebringer blinks away!', 41, 0, 0, 0, 0, 0, 'noth EMOTE_BLINK');

-- Patchwerk
DELETE FROM `creature_text` WHERE `entry` = 16028;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(16028, 0, 1, 'Kel\'Thuzad make Patchwerk his avatar of war!', 14, 0, 0, 0, 0, 8910, 'Patchwerk SAY_AGGRO'),
(16028, 0, 0, 'Patchwerk want to play.', 14, 0, 0, 0, 0, 8909, 'Patchwerk SAY_AGGRO'),
(16028, 1, 0, 'No more play?', 14, 0, 0, 0, 0, 8912, 'Patchwerk SAY_KILL'),
(16028, 2, 0, 'What happened to... Patch...', 14, 0, 0, 0, 0, 8911, 'Patchwerk SAY_DEATH'),
(16028, 3, 0, '%s goes into a berserker rage!', 16, 0, 0, 0, 0, 0, 'Patchwerk EMOTE_BERSERK'),
(16028, 4, 0, 'Patchwerk becomes enraged!', 41, 0, 0, 0, 0, 0, 'Patchwerk EMOTE_ENRAGE');

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

-- Sapphiron
DELETE FROM `creature_text` WHERE `entry` = 15989;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(15989, 0, 0, 'Sapphiron lifts off into the air!', 41, 0, 0, 0, 0, 0, 'Sapphiron EMOTE_AIR'),
(15989, 1, 0, 'Sapphiron resmues his attacks!', 41, 0, 0, 0, 0, 0, 'Sapphiron EMOTE_LAND'),
(15989, 2, 0, 'Sapphiron takes a deep breath.', 41, 0, 0, 0, 0, 0, 'Sapphiron EMOTE_BREATH'),
(15989, 3, 0, '%s enrages!', 16, 0, 0, 0, 0, 0, 'Sapphiron EMOTE_ENRAGE');

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

-- Lich king
DELETE FROM `creature_text` WHERE `entry` = 28765;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(28765, 1, 0, 'Soon we will eradicate the Alliance and Horde, then the rest of Azeroth will fall before the might of my army.', 14, 0, 0, 0, 0, 14768, 'The Lich King SAY_SAPP_DIALOG2_LICH'),
(28765, 2, 0, 'Very well... warriors of the frozen wastes, rise up! I command you to fight, kill, and die for your master. Let none survive...', 14, 0, 0, 0, 0, 8824, 'The Lich King SAY_ANSWER'),
(28765, 3, 0, 'Invaders...here?! DESTROY them, Kel\'Thuzad! Naxxramas must not fall!', 14, 0, 0, 0, 0, 14769, 'The Lich King SAY_SAPP_DIALOG4_LICH');

-- Teleports template
DELETE FROM `gameobject_template` WHERE `entry` IN (181575,181576,181577,181578);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `WDBVerified`) VALUES
(181575, 10, 6787, 'Naxxramas Portal', '', '', '', 0, 32, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28444, 1, 129, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 12340),
(181578, 10, 6790, 'Naxxramas Portal', '', '', '', 0, 32, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28444, 1, 129, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 12340),
(181576, 10, 6788, 'Naxxramas Portal', '', '', '', 0, 32, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28444, 1, 129, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 12340),
(181577, 10, 6789, 'Naxxramas Portal', '', '', '', 0, 32, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28444, 1, 129, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 12340);

-- Orbs template
DELETE FROM `gameobject_template` WHERE `entry` IN (202277,202278);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `WDBVerified`) VALUES
(202278, 10, 7800, 'Orb of Naxxramas', '', '', '', 0, 32, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 72617, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 12340),
(202277, 10, 7800, 'Orb of Naxxramas', '', '', '', 0, 32, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 72613, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 12340);

-- Scriptnames
UPDATE `gameobject_template` SET `ScriptName`='go_naxxramas_portal' WHERE `entry` IN (181575,181576,181577,181578);
UPDATE `gameobject_template` SET `ScriptName`='go_orb_of_naxxramas' WHERE `entry` IN (202277,202278);

-- Disable movement for Eye Stalkers
UPDATE `creature_template` SET `unit_flags`=4 WHERE `entry`=16236;

-- Delete areatrigger teleport non blizz data
DELETE FROM `areatrigger_teleport` WHERE  `id`=4156;

-- Add areatrigger scripts
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (4113,4115,4117,4119);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(4115, 'at_faerlina_intro'),
(4117, 'at_millitary_quarter'),
(4113, 'at_thaddius_intro'),
(4119, 'at_anubrekhan_intro');

-- Spawn Orb of Naxxramas
DELETE FROM `gameobject` WHERE `guid` IN (191946,191945);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(191946, 202277, 533, 3, 1, 3495.97, -5357.84, 144.964, 0.541051, 0, 0, 0.267238, 0.963631, 7200, 255, 1),
(191945, 202278, 533, 3, 1, 2997.68, -3437.8, 304.2, 1.15192, 0, 0, 0.544639, 0.838671, 7200, 255, 1);

-- Spawn teleports
DELETE FROM `gameobject` WHERE `guid` IN (30006,30007,30008,30009);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(30009, 181575, 533, 3, 1, 3465.18, -3940.4, 308.79, 2.44, 0, 0, 0.939099, 0.343646, 604800, 100, 1),
(30006, 181576, 533, 3, 1, 3539.02, -2936.82, 302.48, 3.14, 0, 0, 1, 0.000796274, 604800, 100, 1),
(30007, 181577, 533, 3, 1, 2909, -4025.02, 273.48, 3.14, 0, 0, 1, 0.000796274, 604800, 100, 1),
(30008, 181578, 533, 3, 1, 2493.02, -2921.78, 241.19, 3.14, 0, 0, 1, 0.000796274, 604800, 100, 1);

-- Add target for Naxxramas spells
DELETE FROM `spell_target_position` WHERE `id` IN (29273,29231,29216,29247,29248,29249,29237,29217,29224,29225,29227,29238,29255,29257,29258,29262,29267,29226,29239,29256,29268,30211,28025,28026,72613,28444,72617,54862,29240);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES
(29273, 533, 3498.28, -5349.9, 144.968, 1.31324),
(29231, 533, 2684.8, -3502.52, 261.31, 0),
(29216, 533, 2631.37, -3529.68, 274.04, 0),
(29247, 533, 2648.83, -3467.3, 262.399, 5.46297),
(29248, 533, 2704.13, -3462.44, 262.403, 4.31236),
(29249, 533, 2722.42, -3514.74, 262.467, 3.09084),
(29237, 533, 2648.83, -3467.3, 262.399, 5.46297),
(29217, 533, 2642.34, -3485.28, 262.273, 6.17666),
(29224, 533, 2646.55, -3471.47, 262.413, 5.43839),
(29225, 533, 2651.09, -3464.07, 262.112, 5.45017),
(29227, 533, 2663.92, -3464.7, 262.574, 5.15958),
(29238, 533, 2684.95, -3457.55, 262.578, 4.62159),
(29255, 533, 2704.22, -3461.86, 262.546, 4.37027),
(29257, 533, 2724.82, -3466.21, 262.622, 3.85584),
(29258, 533, 2722.03, -3514.3, 262.354, 2.84269),
(29262, 533, 2726.13, -3534.64, 262.31, 2.60314),
(29267, 533, 2711.72, -3458.56, 262.384, 4.02864),
(29226, 533, 2722.29, -3514.68, 262.431, 2.87018),
(29239, 533, 2706.78, -3461.59, 262.517, 4.00358),
(29256, 533, 2669.42, -3463.75, 262.63, 5.07774),
(29268, 533, 2646.93, -3470.95, 262.427, 5.51363),
(30211, 533, 2793.86, -3707.38, 276.64, 2.32),
(28025, 533, 2692.65, -3321.06, 267.684, 4.70454),
(28026, 533, 2705.95, -3412.45, 267.688, 2.19126),
(72613, 533, 3004.58, -3392.53, 298, 5.796),
(28444, 533, 3005.46, -3433.96, 304.195, 3.593),
(72617, 533, 3497.45, -5354.67, 144.975, 1.321),
(54862, 533, 2704.22, -3461.86, 262.546, 4.37027),
(29240, 533, 2704.22, -3461.86, 262.546, 4.37027);

-- Spawn Tesla objects
DELETE FROM `gameobject` WHERE `guid` IN (30010,30011);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(30010, 181477, 533, 3, 1, 3527.94, -2952.26, 318.9, 3.14, 0, 0, 1, 0.000796274, 604800, 100, 1),
(30011, 181478, 533, 3, 1, 3487.32, -2911.38, 318.9, 3.14, 0, 0, 1, 0.000796274, 604800, 100, 1);

-- Spawn Tesla triggers
DELETE FROM `creature` WHERE `guid` IN (300000,300001);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(300000, 16218, 533, 3, 1, 0, 0, 3487.76, -2911.2, 319.406, 3.90954, 300, 0, 0, 17010, 0, 0, 0, 0, 0),
(300001, 16218, 533, 3, 1, 0, 0, 3527.81, -2952.38, 319.326, 3.90954, 300, 0, 0, 17010, 0, 0, 0, 0, 0);

-- Set fly for Tesla triggers
UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=16218;

-- Add conditions for Stalagg's and Feugen's chain
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (28111,28096);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13, 7, 28111, 0, 0, 31, 0, 3, 15930, 0, 0, 0, '', ''),
(13, 7, 28096, 0, 0, 31, 0, 3, 15929, 0, 0, 0, '', '');

-- Add spell difficulties
DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (28783,28785,28796,28794,28798,28732,28371,28374,29317,28157,29998,28478,28479,29865,29204,29484,28741,28776,54123,29213,29212,41926,29107,28134,28135,28167);
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`) VALUES
-- Anub'Rekhan
(28783, 28783, 56090),
(28785, 28785, 54021),
-- Grand Widow Faerlina
(28796, 28796, 54098),
(28794, 28794, 54099),
(28798, 28798, 54100),
(28732, 28732, 54097),
-- Gluth
(28371, 28371, 54427),
(28374, 28374, 54426),
-- Gothik the Harvester
(29317, 29317, 56405),
-- Grobbulus
(28157, 28157, 54364),
-- Heigan the Unclean
(29998, 29998, 55011),
-- Kel'Thuzad
(28478, 28478, 55802),
(28479, 28479, 55807),
-- Loatheb
(29865, 29865, 55053),
(29204, 29204, 55052),
-- Maexxna
(29484, 29484, 54125),	
(28741, 28741, 54122),
(28776, 28776, 54121),
(54123, 54123, 54124),
-- Noth the Plaguebringer
(29213, 29213, 54835),
(29212, 29212, 54814),
-- Patchwerk
(41926, 41926, 59192),
-- Instructor Razuvious
(29107, 29107, 55543),
-- Stalagg
(28134, 28134, 54529),
-- Feugen
(28135, 28135, 54528),
-- Thaddius
(28167, 28167, 54531);
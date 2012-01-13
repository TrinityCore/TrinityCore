-- Remove old script text for npc_millhouse_manastorm
DELETE FROM `script_texts` WHERE `entry` IN (-1552010, -1552022);

-- Add new creature_text for Millhouse ManaStorm
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(20977, 0, 0, 'Where in Bonzo\'\'s brass buttons am I? And who are-- yaaghh, that\'\'s one mother of a headache!', 0, 0, 100, 0, 0, 0, 'Millhouse Manastorm'),
(20977, 1, 0, '"Lowly"? I don\'\'t care who you are friend, no one refers to the mighty Millhouse Manastorm as "Lowly"! I have no idea what goes on here, but I will gladly join your fight against this impudent imbecile! Prepare to defend yourself, cretin!', 0, 0, 100, 0, 0, 0, 'Millhouse Manastorm'),
(20977, 2, 0, 'I just need to get some things ready first. You guys go ahead and get started. I need to summon up some water...', 0, 0, 100, 0, 0, 0, 'Millhouse Manastorm'),
(20977, 3, 0, 'Fantastic! Next, some protective spells. Yes! Now we\'\'re cookin\'\'', 0, 0, 100, 0, 0, 0, 'Millhouse Manastorm'),
(20977, 4, 0, 'And of course i\'\'ll need some mana. You guys are gonna love this, just wait.', 0, 0, 100, 0, 0, 0, 'Millhouse Manastorm'),
(20977, 5, 0, 'Aaalllriiiight!! Who ordered up an extra large can of whoop-ass?', 0, 0, 100, 0, 0, 0, 'Millhouse Manastorm'),
(20977, 6, 0, 'I didn\'\'t even break a sweat on that one.', 0, 0, 100, 0, 0, 0, 'Millhouse Manastorm'),
(20977, 6, 1, 'You guys, feel free to jump in anytime.', 0, 0, 100, 0, 0, 0, 'Millhouse Manastorm'),
(20977, 7, 0, 'I\'\'m gonna light you up, sweet cheeks!', 0, 0, 100, 0, 0, 0, 'Millhouse Manastorm'),
(20977, 8, 0, 'Ice, ice, baby!', 0, 0, 100, 0, 0, 0, 'Millhouse Manastorm'),
(20977, 9, 0, 'Heal me! Oh, for the love of all that is holy, HEAL me! I\'\'m dying!', 0, 0, 100, 0, 0, 0, 'Millhouse Manastorm'),
(20977, 10, 0, 'You\'\'ll be hearing from my lawyer...', 0, 0, 100, 0, 0, 0, 'Millhouse Manastorm'),
(20977, 11, 0, 'Who\'\'s bad? Who\'\'s bad? That\'\'s right: we bad!', 0, 0, 100, 0, 0, 0, 'Millhouse Manastorm');

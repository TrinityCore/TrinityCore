DELETE FROM `spell_area` WHERE `spell` IN (66927, 66928, 66908);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`,`quest_start_status`) VALUES
(66927,4765,14153,14153,0,0,1,1,8),
(66928,4765,14113,14113,0,0,0,1,8),
(66908,4765,14153,14153,0,0,2,1,8),
(66908,4765,14113,14113,0,0,2,1,8);

DELETE FROM `creature_text` WHERE `entry` = 35186;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`comment`, `BroadcastTextID`) VALUES
(35186, 0, 0, "If only I had someone to dance with.", 12, 0, 100, "Kezan Partygoer", 40224),
(35186, 1, 0, "Ugh... I need a bucket!", 12, 0, 100, "Kezan Partygoer", 40223),
(35186, 2, 0, "I could really use a refill on my drink here.", 12, 0, 100, "Kezan Partygoer", 40222),
(35186, 3, 0, "I love fireworks!", 12, 0, 100, "Kezan Partygoer", 40225),
(35186, 4, 0, "This is delicious! Are there more hors d'oeuvres?", 12, 0, 100, "Kezan Partygoer", 40226),
(35186, 5, 0, "A fresh glass of bubbly. Just what the doctor ordered, $n.", 12, 0, 100, "Kezan Partygoer", 35417),
(35186, 5, 1, "Thanks for the refill, $g sir : ma'am;!", 12, 0, 100, "Kezan Partygoer", 35418),
(35186, 5, 2, "This sparkling white wine is delicious! Wherever did you get it?", 12, 0, 100, "Kezan Partygoer", 35419),
(35186, 5, 3, "I think this one will have to be my last. I'm driving home after the party.", 12, 0, 100, "Kezan Partygoer", 35420),
(35186, 5, 4, "Thanksh!", 12, 0, 100, "Kezan Partygoer", 35421),
(35186, 6, 0, "I feel much better now...hic!", 12, 0, 100, "Kezan Partygoer", 35422),
(35186, 6, 1, "Oh, my head hurtsh.", 12, 0, 100, "Kezan Partygoer", 35423),
(35186, 6, 2, "Shorry about your shoes.", 12, 0, 100, "Kezan Partygoer", 35424),
(35186, 7, 0, "A disco ball?! Groovy!", 12, 0, 100, "Kezan Partygoer", 35425),
(35186, 7, 1, "How do you like my moves, $n?", 12, 0, 100, "Kezan Partygoer", 35426),
(35186, 7, 2, "We should totally have a pants-off dance-off!", 12, 0, 100, "Kezan Partygoer", 35427),
(35186, 7, 3, "Shake it like a goblinoid picture!", 12, 0, 100, "Kezan Partygoer", 35428),
(35186, 8, 0, "Wow! That sure beats this puny, little sparkler!", 12, 0, 100, "Kezan Partygoer", 35429),
(35186, 8, 1, "You really stop at no expense, $n! Amazing!", 12, 0, 100, "Kezan Partygoer", 35430),
(35186, 8, 2, "Best... Party... Evar!", 12, 0, 100, "Kezan Partygoer", 35431),
(35186, 8, 3, "Woo hoo, fireworks! More, more!", 12, 0, 100, "Kezan Partygoer", 35432),
(35186, 9, 0, "Thanks. I was almost out. So hungry!", 12, 0, 100, "Kezan Partygoer", 35433),
(35186, 9, 1, "These are the most delicious hors d'oeurves I have ever tasted. You must share your recipe, $n!", 12, 0, 100, "Kezan Partygoer", 35434),
(35186, 9, 2, "Finger licking good!", 12, 0, 100, "Kezan Partygoer", 35435),
(35186, 9, 3, "Nom, nom, nom!", 12, 0, 100, "Kezan Partygoer", 35436);

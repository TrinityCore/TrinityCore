DELETE FROM `scene_template` WHERE `SceneId` IN (2634, 2499, 2420, 2423, 2421, 2402, 2379, 2380, 2422, 2341, 2338, 2418, 2334);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(2634, 26, 2972, 0),
(2499, 17, 2908, 0),
(2420, 16, 2822, 0),
(2423, 16, 2825, 0),
(2421, 16, 2823, 0),
(2402, 16, 2809, 0),
(2379, 17, 2775, 0),
(2380, 16, 2773, 0),
(2422, 16, 2824, 0),
(2341, 17, 2933, 0),
(2338, 16, 2712, 0),
(2418, 16, 2932, 0),
(2334, 16, 2708, 0);

DELETE FROM `quest_offer_reward` WHERE `ID` IN (55991 /*An End to Beginnings*/, 55992 /*Dungeon: Darkmaul Citadel*/, 55990 /*Controlling their Stones*/, 55989 /*Catapult Destruction*/, 55988 /*Like Ogres to the Slaughter*/, 55981 /*Right Beneath Their Eyes*/, 56344 /*To Darkmaul Citadel*/, 56839 /*Killclaw the Terrible*/, 60168 /*The Art of Taming*/, 59356 /*Hunting the Stalker*/, 59355 /*A Hunter's Trap*/, 55882 /*Message to Base*/, 55881 /*Purge the Totems*/, 55764 /*Harpy Culling*/, 55763 /*The Rescue of Meredy Huntswell*/, 55196 /*The Harpy Problem*/, 54933 /*Freeing the Light*/, 55639 /*Who Lurks in the Pit*/, 55965 /*Westward Bound*/, 55194 /*Stocking Up on Supplies*/, 55879 /*Ride of the Scientifically Enhanced Boar*/, 56034 /*Re-sizing the Situation*/, 55193 /*The Scout-o-Matic 5000*/, 55186 /*Down with the Quilboar*/, 55184 /*Forbidden Quilboar Necromancy*/, 59342 /*Taming the Wilds*/, 55173 /*Northbound*/, 55174 /*Cooking Meat*/, 54952 /*Finding the Lost Expedition*/, 54951 /*Emergency First Aid*/, 55122 /*Murloc Mania*/, 58208 /*Brace for Impact*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(55991, 0, 0, 0, 0, 0, 0, 0, 0, 'It\'s good to be back in Stormwind. \n\nI must report our mission\'s success to the king, but I have an idea for what you can do in the meantime...', 41488), -- An End to Beginnings
(55992, 0, 0, 0, 0, 0, 0, 0, 0, 'It seems things are finally looking up for us. I think it\'s time we returned to Stormwind.', 41488), -- Dungeon: Darkmaul Citadel
(55990, 5, 0, 0, 0, 0, 0, 0, 0, 'Thank you for saving me, but we have no time to lose. The ogres will not stop until they have raised the dragon!', 41488), -- Controlling their Stones
(55989, 273, 0, 0, 0, 0, 0, 0, 0, 'Great work! I\'ll have tae tell Lindie that his bombs worked perfectly.', 41488), -- Catapult Destruction
(55988, 4, 0, 0, 0, 0, 0, 0, 0, 'This should buy us enough time to stop the ritual!', 41488), -- Like Ogres to the Slaughter
(55981, 669, 0, 0, 0, 0, 0, 0, 0, 'We\'re close to stopping all of this. We just need to push a little further.', 41488), -- Right Beneath Their Eyes
(56344, 669, 0, 0, 0, 0, 0, 0, 0, 'All right, $n. I hope you\'re a good actor, because you\'re about to play to a very tough crowd.', 41488), -- To Darkmaul Citadel
(56839, 0, 0, 0, 0, 0, 0, 0, 0, '<You find a cache of treasure, just like the ogres\' sign mentioned!>', 41488), -- Killclaw the Terrible
(60168, 0, 0, 0, 0, 0, 0, 0, 0, 'Excellent work, $n. There\'s nothing left for me to teach you.\n\nGather as many wild beasts as you\'d like. Just make sure not to lose focus on the ogres who are trying to kill us.', 41488), -- The Art of Taming
(59356, 0, 0, 0, 0, 0, 0, 0, 0, 'Thank you for the help, $n. I have one last lesson to impart--calling a different companion to your side.\n\nThere are plenty of wild beasts on this island. See which ones you can tame.', 41488), -- Hunting the Stalker
(59355, 0, 0, 0, 0, 0, 0, 0, 0, 'With a little work, this can become a trap you can use. \n\nPart of being a hunter means making use of what your surroundings provide.', 41488), -- A Hunter's Trap
(55882, 669, 0, 0, 0, 0, 0, 0, 0, 'I\'m relieved you rescued Meredy. That\'s one more life saved and one fewer sacrificed.\n\nAnd I\'m glad to see you helped Henry get back to his old self.\n\nWe\'ll work with Meredy to figure out a plan of action.', 41488), -- Message to Base
(55881, 1, 0, 0, 0, 0, 0, 0, 0, 'The foul magic in this area is dissipating. I think we\'re safe for now.', 41488), -- Purge the Totems
(55764, 273, 0, 0, 0, 0, 0, 0, 0, 'That should keep our camp safe for now. We must hurry and stop whatever these ogres have planned.', 41488), -- Harpy Culling
(55763, 5, 0, 0, 0, 0, 0, 0, 0, 'Ye rescued me from a grim fate! Bein\' a practicin\' mage, I always figured one of me own spells would do me in, not a harpy!', 41488), -- The Rescue of Meredy Huntswell
(55196, 25, 0, 0, 0, 0, 0, 0, 0, 'It seems the harpies are up to no good. We\'ll need your help with this.', 41488), -- The Harpy Problem
(54933, 0, 0, 0, 0, 0, 0, 0, 0, 'You have my thanks, $n. I must leave this world, but I wish you luck. \n\nTake my blessing. May it aid you against these monsters.', 41488), -- Freeing the Light
(55639, 669, 0, 0, 0, 0, 0, 0, 0, 'Ralia Dreamchaser is a druid of the Cenarion Circle, an order dedicated to protecting the wilds of Azeroth.\n\nThank you for rescuing her. Her aid is sure to be of use against the ogres.', 41488), -- Who Lurks in the Pit
(55965, 6, 0, 0, 0, 0, 0, 0, 0, 'A giant pit of spiders right on our doorstep! Aren\'t we the lucky ones?', 41488), -- Westward Bound
(55194, 669, 0, 0, 0, 0, 0, 0, 0, 'All stocked up? That\'s great.\n\nPrivate Cole and Quartermaster Richter also found this bag in the nearby ruins. They thought you might make good use of it.', 41488), -- Stocking Up on Supplies
(55879, 66, 0, 0, 0, 0, 0, 0, 0, 'Thank you, stranger. I thought I was going to be punished for failing to save my friends.\n\nI\'m relieved that I was mistaken.', 41488), -- Ride of the Scientifically Enhanced Boar
(56034, 669, 0, 0, 0, 0, 0, 0, 0, 'I never thought I\'d be so relieved to be face to face with a giant, scientifically enhanced boar.\n\nLet\'s go save my son.', 41488), -- Re-sizing the Situation
(55193, 4, 0, 0, 0, 0, 0, 0, 0, 'There\'s no problem a little re-sizing can\'t fix! Let\'s find something to stomp those undead flat!', 41488), -- The Scout-o-Matic 5000
(55186, 4, 0, 0, 0, 0, 0, 0, 0, 'Thanks for saving my life! They said this would be a run of the mill, uneventful expedition.\n\nIt definitely was NOT! And I couldn\'t be happier!', 41488), -- Down with the Quilboar
(55184, 1, 0, 0, 0, 0, 0, 0, 0, 'Good work. I hope those quilboar learn that necromancy is not a path to power.', 41488), -- Forbidden Quilboar Necromancy
(59342, 0, 0, 0, 0, 0, 0, 0, 0, 'You\'ve got a loyal companion by your side. Take good care of them, and they\'ll take care of you.', 41488), -- Taming the Wilds
(55173, 0, 0, 0, 0, 0, 0, 0, 0, 'I\'ve got some good news and some very, very bad news.', 41488), -- Northbound
(55174, 0, 0, 0, 0, 0, 0, 0, 0, '<Alaria quickly eats the meat that you cooked.>\n\nBy the Light... I feel so much better.\n\nYou need to keep moving... quilboar have kidnapped the expedition, including Captain Garrick\'s son!', 41488), -- Cooking Meat
(54952, 0, 0, 0, 0, 0, 0, 0, 0, 'The others... taken... \n\nNeed... food...', 41488), -- Finding the Lost Expedition
(54951, 0, 0, 0, 0, 0, 0, 0, 0, 'We\'re ready to move. Let\'s find that missing expedition.', 41488), -- Emergency First Aid
(55122, 0, 0, 0, 0, 0, 0, 0, 0, 'Excellent work. Let\'s get the survivors back on their feet.', 41488), -- Murloc Mania
(58208, 669, 0, 0, 0, 0, 0, 0, 0, 'This ship may not make it to the island.\n\nHold on to something sturdy and stick with your fellow recruits. We\'ll get through this.', 41488); -- Brace for Impact

UPDATE `quest_offer_reward` SET `VerifiedBuild`=41488 WHERE `ID` IN (58209, 56775);

DELETE FROM `quest_poi` WHERE (`QuestID`=55989 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=55989 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=55989 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=59355 AND `BlobIndex`=1 AND `Idx1`=5) OR (`QuestID`=59355 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=59355 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=59355 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=59355 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=59355 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=54933 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=54933 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=54933 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=54933 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=54933 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=55879 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=55879 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=55879 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=55879 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=55879 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=55186 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=55186 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=55186 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(55989, 0, 2, 32, 0, 0, 2175, 1409, 0, 2, 0, 0, 0, 0, 0, 41488), -- Catapult Destruction
(55989, 0, 1, 0, 389991, 326651, 2175, 1409, 0, 0, 0, 0, 0, 0, 0, 41488), -- Catapult Destruction
(55989, 0, 0, -1, 0, 0, 2175, 1409, 0, 2, 0, 0, 0, 0, 0, 41488), -- Catapult Destruction
(59355, 1, 5, 32, 0, 0, 2175, 1409, 0, 0, 0, 0, 0, 1825086, 0, 41488), -- A Hunter's Trap
(59355, 0, 4, 32, 0, 0, 2175, 1409, 0, 0, 0, 0, 0, 1820131, 0, 41488), -- A Hunter's Trap
(59355, 0, 3, 2, 396413, 175980, 2175, 1409, 0, 0, 0, 0, 0, 1922440, 0, 41488), -- A Hunter's Trap
(59355, 0, 2, 1, 396412, 175981, 2175, 1409, 0, 0, 0, 0, 0, 1922439, 0, 41488), -- A Hunter's Trap
(59355, 0, 1, 0, 396411, 175979, 2175, 1409, 0, 0, 0, 0, 0, 1825379, 0, 41488), -- A Hunter's Trap
(59355, 0, 0, -1, 0, 0, 2175, 1409, 0, 0, 0, 0, 0, 1825086, 0, 41488), -- A Hunter's Trap
(54933, 0, 4, 3, 390025, 326719, 2175, 1409, 0, 0, 0, 0, 0, 1794183, 0, 41488), -- Freeing the Light
(54933, 0, 3, 2, 390024, 326718, 2175, 1409, 0, 0, 0, 0, 0, 1794182, 0, 41488), -- Freeing the Light
(54933, 0, 2, 1, 390023, 326717, 2175, 1409, 0, 0, 0, 0, 0, 1794181, 0, 41488), -- Freeing the Light
(54933, 0, 1, 0, 390022, 326716, 2175, 1409, 0, 0, 0, 0, 0, 1794179, 0, 41488), -- Freeing the Light
(54933, 0, 0, -1, 0, 0, 2175, 1409, 0, 0, 0, 0, 0, 1827148, 0, 41488), -- Freeing the Light
(55879, 0, 4, 32, 0, 0, 2175, 1409, 0, 2, 0, 0, 0, 0, 0, 41488), -- Ride of the Scientifically Enhanced Boar
(55879, 0, 3, 2, 395073, 162817, 2175, 1409, 0, 0, 0, 0, 0, 1886678, 0, 41488), -- Ride of the Scientifically Enhanced Boar
(55879, 1, 2, 0, 389796, 156595, 2175, 1409, 0, 2, 0, 72677, 0, 0, 0, 41488), -- Ride of the Scientifically Enhanced Boar
(55879, 0, 1, 0, 389796, 156595, 2175, 1409, 0, 2, 0, 72676, 0, 0, 0, 41488), -- Ride of the Scientifically Enhanced Boar
(55879, 0, 0, -1, 0, 0, 2175, 1409, 0, 2, 0, 0, 0, 0, 0, 41488), -- Ride of the Scientifically Enhanced Boar
(55186, 0, 2, 32, 0, 0, 2175, 1409, 0, 2, 0, 0, 0, 0, 0, 41488), -- Down with the Quilboar
(55186, 0, 1, 0, 388852, 151091, 2175, 1409, 0, 0, 0, 0, 0, 1731928, 0, 41488), -- Down with the Quilboar
(55186, 0, 0, -1, 0, 0, 2175, 1409, 0, 2, 0, 0, 0, 0, 0, 41488); -- Down with the Quilboar

UPDATE `quest_poi` SET `VerifiedBuild`=41488 WHERE (`QuestID`=59583 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=59583 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=55991 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=55991 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=55991 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=55992 AND `BlobIndex`=1 AND `Idx1`=6) OR (`QuestID`=55992 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=55992 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=55992 AND `BlobIndex`=1 AND `Idx1`=3) OR (`QuestID`=55992 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=55992 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=55992 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=55988 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=55988 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=55988 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=55990 AND `BlobIndex`=0 AND `Idx1`=7) OR (`QuestID`=55990 AND `BlobIndex`=0 AND `Idx1`=6) OR (`QuestID`=55990 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=55990 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=55990 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=55990 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=55990 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=55990 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=55981 AND `BlobIndex`=0 AND `Idx1`=7) OR (`QuestID`=55981 AND `BlobIndex`=0 AND `Idx1`=6) OR (`QuestID`=55981 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=55981 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=55981 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=55981 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=55981 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=55981 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=56839 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=56839 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=56839 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=56344 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=56344 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=60168 AND `BlobIndex`=1 AND `Idx1`=3) OR (`QuestID`=60168 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=60168 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=60168 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=59356 AND `BlobIndex`=1 AND `Idx1`=3) OR (`QuestID`=59356 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=59356 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=59356 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=55882 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=55882 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=55764 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=55764 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=55764 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=55881 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=55881 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=55881 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=55763 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=55763 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=55763 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=55639 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=55639 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=55639 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=55639 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=55639 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=55196 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=55196 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=55196 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=55965 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=55965 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=55194 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=55194 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=55194 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=55194 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=56034 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=56034 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=56034 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=55193 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=55193 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=55193 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=55184 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=55184 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=55184 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=59342 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=59342 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=59342 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=59342 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=55173 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=55173 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=55174 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=55174 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=55174 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=55174 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=55174 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=54952 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=54952 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=54952 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=54951 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=54951 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=54951 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=54951 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=54951 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=55122 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=55122 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=55122 AND `BlobIndex`=0 AND `Idx1`=0);

DELETE FROM `quest_poi_points` WHERE (`QuestID`=55989 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=55989 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=55989 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=55989 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=55989 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=55989 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55989 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=59355 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=59355 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=59355 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=59355 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=59355 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=59355 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=54933 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=54933 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=54933 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=54933 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=54933 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=55879 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=55879 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=55879 AND `Idx1`=2 AND `Idx2`=11) OR (`QuestID`=55879 AND `Idx1`=2 AND `Idx2`=10) OR (`QuestID`=55879 AND `Idx1`=2 AND `Idx2`=9) OR (`QuestID`=55879 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=55879 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=55879 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=55879 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=55879 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=55879 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=55879 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=55879 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=55879 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=55879 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55879 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=55186 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=55186 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55186 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(55989, 2, 0, 705, -1874, 165, 41488), -- Catapult Destruction
(55989, 1, 4, 536, -2086, 0, 41488), -- Catapult Destruction
(55989, 1, 3, 490, -2052, 0, 41488), -- Catapult Destruction
(55989, 1, 2, 441, -2004, 0, 41488), -- Catapult Destruction
(55989, 1, 1, 464, -1997, 0, 41488), -- Catapult Destruction
(55989, 1, 0, 611, -2118, 0, 41488), -- Catapult Destruction
(55989, 0, 0, 707, -1877, 187, 41488), -- Catapult Destruction
(59355, 5, 0, 182, -2284, 90, 41488), -- A Hunter's Trap
(59355, 4, 0, 99, -2421, 90, 41488), -- A Hunter's Trap
(59355, 3, 0, 269, -2271, 81, 41488), -- A Hunter's Trap
(59355, 2, 0, 237, -2285, 81, 41488), -- A Hunter's Trap
(59355, 1, 0, 182, -2287, 0, 41488), -- A Hunter's Trap
(59355, 0, 0, 182, -2284, 82, 41488), -- A Hunter's Trap
(54933, 4, 0, 280, -2474, 0, 41488), -- Freeing the Light
(54933, 3, 0, 291, -2514, 0, 41488), -- Freeing the Light
(54933, 2, 0, 325, -2497, 0, 41488), -- Freeing the Light
(54933, 1, 0, 314, -2460, 0, 41488), -- Freeing the Light
(54933, 0, 0, 299, -2486, 115, 41488), -- Freeing the Light
(55879, 4, 0, 99, -2424, 165, 41488), -- Ride of the Scientifically Enhanced Boar
(55879, 3, 0, 244, -2243, 84, 41488), -- Ride of the Scientifically Enhanced Boar
(55879, 2, 11, 207, -2349, 0, 41488), -- Ride of the Scientifically Enhanced Boar
(55879, 2, 10, 179, -2316, 0, 41488), -- Ride of the Scientifically Enhanced Boar
(55879, 2, 9, 183, -2274, 0, 41488), -- Ride of the Scientifically Enhanced Boar
(55879, 2, 8, 192, -2248, 0, 41488), -- Ride of the Scientifically Enhanced Boar
(55879, 2, 7, 219, -2215, 0, 41488), -- Ride of the Scientifically Enhanced Boar
(55879, 2, 6, 249, -2218, 0, 41488), -- Ride of the Scientifically Enhanced Boar
(55879, 2, 5, 275, -2245, 0, 41488), -- Ride of the Scientifically Enhanced Boar
(55879, 2, 4, 287, -2271, 0, 41488), -- Ride of the Scientifically Enhanced Boar
(55879, 2, 3, 287, -2295, 0, 41488), -- Ride of the Scientifically Enhanced Boar
(55879, 2, 2, 269, -2325, 0, 41488), -- Ride of the Scientifically Enhanced Boar
(55879, 2, 1, 249, -2346, 0, 41488), -- Ride of the Scientifically Enhanced Boar
(55879, 2, 0, 231, -2352, 90, 41488), -- Ride of the Scientifically Enhanced Boar
(55879, 1, 0, 116, -2424, 90, 41488), -- Ride of the Scientifically Enhanced Boar
(55879, 0, 0, 228, -2294, 81, 41488), -- Ride of the Scientifically Enhanced Boar
(55186, 2, 0, -138, -2639, 90, 41488), -- Down with the Quilboar
(55186, 1, 0, 18, -2509, 73, 41488), -- Down with the Quilboar
(55186, 0, 0, 105, -2415, 90, 41488); -- Down with the Quilboar

UPDATE `quest_poi_points` SET `VerifiedBuild`=41488 WHERE (`QuestID`=59583 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=59583 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=55991 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=55991 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55991 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=55992 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=55992 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=55992 AND `Idx1`=4 AND `Idx2`=11) OR (`QuestID`=55992 AND `Idx1`=4 AND `Idx2`=10) OR (`QuestID`=55992 AND `Idx1`=4 AND `Idx2`=9) OR (`QuestID`=55992 AND `Idx1`=4 AND `Idx2`=8) OR (`QuestID`=55992 AND `Idx1`=4 AND `Idx2`=7) OR (`QuestID`=55992 AND `Idx1`=4 AND `Idx2`=6) OR (`QuestID`=55992 AND `Idx1`=4 AND `Idx2`=5) OR (`QuestID`=55992 AND `Idx1`=4 AND `Idx2`=4) OR (`QuestID`=55992 AND `Idx1`=4 AND `Idx2`=3) OR (`QuestID`=55992 AND `Idx1`=4 AND `Idx2`=2) OR (`QuestID`=55992 AND `Idx1`=4 AND `Idx2`=1) OR (`QuestID`=55992 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=55992 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=55992 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=55992 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55992 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=55988 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=55988 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=55988 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=55988 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=55988 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=55988 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=55988 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=55988 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55988 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=55990 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=55990 AND `Idx1`=6 AND `Idx2`=2) OR (`QuestID`=55990 AND `Idx1`=6 AND `Idx2`=1) OR (`QuestID`=55990 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=55990 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=55990 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=55990 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=55990 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=55990 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55990 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=55981 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=55981 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=55981 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=55981 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=55981 AND `Idx1`=3 AND `Idx2`=7) OR (`QuestID`=55981 AND `Idx1`=3 AND `Idx2`=6) OR (`QuestID`=55981 AND `Idx1`=3 AND `Idx2`=5) OR (`QuestID`=55981 AND `Idx1`=3 AND `Idx2`=4) OR (`QuestID`=55981 AND `Idx1`=3 AND `Idx2`=3) OR (`QuestID`=55981 AND `Idx1`=3 AND `Idx2`=2) OR (`QuestID`=55981 AND `Idx1`=3 AND `Idx2`=1) OR (`QuestID`=55981 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=55981 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=55981 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55981 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=56839 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=56839 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=56839 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=56344 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=56344 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=60168 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=60168 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=60168 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=60168 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=59356 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=59356 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=59356 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=59356 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=59356 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=59356 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=59356 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=59356 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=59356 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=59356 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=59356 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=59356 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=59356 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=59356 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=59356 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=55882 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55882 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=55764 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=55764 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=55764 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=55764 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=55764 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55764 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=55881 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=55881 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=55881 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=55881 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=55881 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55881 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=55763 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=55763 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55763 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=55639 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=55639 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=55639 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=55639 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=55639 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=55639 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=55639 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=55639 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55639 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=55196 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=55196 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55196 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=55965 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55965 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=55194 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=55194 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=55194 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55194 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=56034 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=56034 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=56034 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=56034 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=56034 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=56034 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=56034 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=56034 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=56034 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=56034 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=56034 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=56034 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=56034 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=56034 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=55193 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=55193 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55193 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=55184 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=55184 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=55184 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=55184 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=55184 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=55184 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=55184 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=55184 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=55184 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55184 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=59342 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=59342 AND `Idx1`=2 AND `Idx2`=11) OR (`QuestID`=59342 AND `Idx1`=2 AND `Idx2`=10) OR (`QuestID`=59342 AND `Idx1`=2 AND `Idx2`=9) OR (`QuestID`=59342 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=59342 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=59342 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=59342 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=59342 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=59342 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=59342 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=59342 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=59342 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=59342 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=59342 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=55173 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55173 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=55174 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=55174 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=55174 AND `Idx1`=2 AND `Idx2`=11) OR (`QuestID`=55174 AND `Idx1`=2 AND `Idx2`=10) OR (`QuestID`=55174 AND `Idx1`=2 AND `Idx2`=9) OR (`QuestID`=55174 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=55174 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=55174 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=55174 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=55174 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=55174 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=55174 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=55174 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=55174 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=55174 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55174 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=54952 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=54952 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=54952 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=54952 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=54952 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=54952 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=54952 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=54952 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=54952 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=54952 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=54951 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=54951 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=54951 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=54951 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=54951 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=55122 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=55122 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=55122 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=55122 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=55122 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=55122 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=55122 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=55122 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55122 AND `Idx1`=0 AND `Idx2`=0);

DELETE FROM `quest_details` WHERE `ID` IN (59583 /*Welcome to Stormwind*/, 55991 /*An End to Beginnings*/, 55992 /*Dungeon: Darkmaul Citadel*/, 55988 /*Like Ogres to the Slaughter*/, 55989 /*Catapult Destruction*/, 55990 /*Controlling their Stones*/, 55981 /*Right Beneath Their Eyes*/, 56839 /*Killclaw the Terrible*/, 56344 /*To Darkmaul Citadel*/, 60168 /*The Art of Taming*/, 59356 /*Hunting the Stalker*/, 59355 /*A Hunter's Trap*/, 55882 /*Message to Base*/, 55764 /*Harpy Culling*/, 55881 /*Purge the Totems*/, 55763 /*The Rescue of Meredy Huntswell*/, 54933 /*Freeing the Light*/, 55639 /*Who Lurks in the Pit*/, 55196 /*The Harpy Problem*/, 55965 /*Westward Bound*/, 55194 /*Stocking Up on Supplies*/, 55879 /*Ride of the Scientifically Enhanced Boar*/, 56034 /*Re-sizing the Situation*/, 55193 /*The Scout-o-Matic 5000*/, 55184 /*Forbidden Quilboar Necromancy*/, 55186 /*Down with the Quilboar*/, 59342 /*Taming the Wilds*/, 55173 /*Northbound*/, 55174 /*Cooking Meat*/, 54952 /*Finding the Lost Expedition*/, 54951 /*Emergency First Aid*/, 55122 /*Murloc Mania*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(59583, 0, 0, 0, 0, 0, 0, 0, 0, 41488), -- Welcome to Stormwind
(55991, 0, 0, 0, 0, 0, 0, 0, 0, 41488), -- An End to Beginnings
(55992, 1, 6, 25, 5, 0, 0, 0, 0, 41488), -- Dungeon: Darkmaul Citadel
(55988, 5, 6, 25, 1, 0, 0, 0, 0, 41488), -- Like Ogres to the Slaughter
(55989, 5, 1, 25, 11, 0, 0, 0, 0, 41488), -- Catapult Destruction
(55990, 0, 0, 0, 0, 0, 0, 0, 0, 41488), -- Controlling their Stones
(55981, 0, 0, 0, 0, 0, 0, 0, 0, 41488), -- Right Beneath Their Eyes
(56839, 0, 0, 0, 0, 0, 0, 0, 0, 41488), -- Killclaw the Terrible
(56344, 669, 669, 0, 0, 0, 0, 0, 0, 41488), -- To Darkmaul Citadel
(60168, 0, 0, 0, 0, 0, 0, 0, 0, 41488), -- The Art of Taming
(59356, 0, 0, 0, 0, 0, 0, 0, 0, 41488), -- Hunting the Stalker
(59355, 0, 0, 0, 0, 0, 0, 0, 0, 41488), -- A Hunter's Trap
(55882, 4, 273, 1, 0, 0, 0, 0, 0, 41488), -- Message to Base
(55764, 1, 5, 274, 25, 0, 0, 0, 0, 41488), -- Harpy Culling
(55881, 1, 6, 1, 0, 0, 0, 0, 0, 41488), -- Purge the Totems
(55763, 5, 1, 25, 0, 0, 0, 0, 0, 41488), -- The Rescue of Meredy Huntswell
(54933, 0, 0, 0, 0, 0, 0, 0, 0, 41488), -- Freeing the Light
(55639, 1, 25, 6, 274, 0, 0, 0, 0, 41488), -- Who Lurks in the Pit
(55196, 66, 1, 6, 0, 0, 0, 0, 0, 41488), -- The Harpy Problem
(55965, 1, 25, 0, 0, 0, 0, 0, 0, 41488), -- Westward Bound
(55194, 669, 0, 0, 0, 0, 0, 0, 0, 41488), -- Stocking Up on Supplies
(55879, 0, 0, 0, 0, 0, 0, 0, 0, 41488), -- Ride of the Scientifically Enhanced Boar
(56034, 6, 274, 1, 4, 0, 0, 0, 0, 41488), -- Re-sizing the Situation
(55193, 25, 4, 11, 1, 0, 0, 0, 0, 41488), -- The Scout-o-Matic 5000
(55184, 0, 0, 0, 0, 0, 0, 0, 0, 41488), -- Forbidden Quilboar Necromancy
(55186, 0, 0, 0, 0, 0, 0, 0, 0, 41488), -- Down with the Quilboar
(59342, 0, 0, 0, 0, 0, 0, 0, 0, 41488), -- Taming the Wilds
(55173, 1, 6, 25, 0, 0, 0, 0, 0, 41488), -- Northbound
(55174, 669, 0, 669, 0, 0, 0, 0, 0, 41488), -- Cooking Meat
(54952, 0, 0, 0, 0, 0, 0, 0, 0, 41488), -- Finding the Lost Expedition
(54951, 0, 0, 0, 0, 0, 0, 0, 0, 41488), -- Emergency First Aid
(55122, 0, 0, 0, 0, 0, 0, 0, 0, 41488); -- Murloc Mania

UPDATE `quest_details` SET `VerifiedBuild`=41488 WHERE `ID` IN (58208, 58209, 56775);

DELETE FROM `spell_target_position` WHERE (`EffectIndex`=0 AND `ID` IN (327496,319030,312548,305891)) OR (`EffectIndex`=4 AND `ID`=305425);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(327496, 0, 0, -9058, 438.899993896484375, 93.09999847412109375, 41488), -- Spell: 327496 (Bind) Efffect: 11 (SPELL_EFFECT_BIND)
(319030, 0, 2175, 721.70001220703125, -1838.4000244140625, 186.5, 41488), -- Spell: 319030 (Teleport (DNT)) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(312548, 0, 2175, 108.8000030517578125, -2271.300048828125, 97.09999847412109375, 41488), -- Spell: 312548 (Teleport (DNT)) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(305891, 0, 2175, 229.0800018310546875, -2296.739990234375, 80.90000152587890625, 41488), -- Spell: 305891 (Teleport (DNT)) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(305425, 4, 2175, -462.399993896484375, -2619.800048828125, 0.400000005960464477, 41488); -- Spell: 305425 (Ship Crash (DNT)) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

DELETE FROM `creature_template_addon` WHERE `entry` IN (140146 /*140146 (Stormwind Infantry Captain)*/, 140022 /*140022 (Stormwind Infantry)*/, 154155 /*154155 (Alliance Gryphon)*/, 168255 /*168255 (Alliance Gryphon)*/, 163963 /*163963 (Brunston Hammersmith)*/, 165198 /*165198 (InvisBunny) - Necrotic Storm (Cosmetic 01)*/, 156814 /*156814 (Gor'groth) - Summon Ghouls*/, 156501 /*156501 (Ravnyr) - Awaken (DNT)*/, 161350 /*161350 (Captain Garrick) - Threat 5000%*/, 157328 /*157328 (Darkmaul Channeler) - Dark Ritual*/, 156828 /*156828 (Shadowy Orb) - Arcane Lock*/, 156821 /*156821 (Darkmaul Shadowcaller) - Mod Scale 90-110%, Arcane Channel*/, 153583 /*153583 (Jugnug) - Cosmetic - Sleep Zzz*/, 153581 /*153581 (Grunk) - Cosmetic - Sleep Zzz*/, 153582 /*153582 (Wug) - Enrage*/, 156954 /*156954 (Captain Kelra) - Necrotic Ritual (DNT)*/, 153580 /*153580 (Gor'groth) - Lightning Dissolve Out*/, 154103 /*154103 (Ogre Chef) - Cosmetic - Chef's Hat visual for Ogres*/, 153238 /*153238 (Tamed Boar) - Permanent Feign Death (Stun, Untrackable, Immune)*/, 153239 /*153239 (Ogre Brute) - Cosmetic - Sleep Zzz*/, 153242 /*153242 (Ogre Shadowcaster)*/, 155733 /*155733 (Hidden Treasure Chest)*/, 161006 /*161006 (Ogre Shadowcaster) - Permanent Feign Death (Stun, Untrackable, Immune)*/, 171997 /*171997 (Woodlands Watcher)*/, 163533 /*163533 (Hjalmar the Undying) - Permanent Feign Death (Stun, Untrackable, Immune)*/, 152571 /*152571 (Harpy Snatcher)*/, 152843 /*152843 (Harpy Boltcaller)*/, 153964 /*153964 (Bloodbeak)*/, 153211 /*153211 (Meredy Huntswell) - Necrotic Ritual (DNT)*/, 163069 /*163069 (Yorah) - Permanent Feign Death (Stun, Untrackable, Immune)*/, 160451 /*160451 (Hrun the Exiled) - Fire Burst*/, 156902 /*156902 (Ralia Dreamchaser) - Necrotic Ritual (DNT)*/, 160433 /*160433 (Barrow Spiderling) - Venomous Fangs*/, 156900 /*156900 (Hrun the Exiled) - Final Sacrifice*/, 160394 /*160394 (Barrow Spider) - Venomous Fangs*/, 153266 /*153266 (Killclaw the Terrible) - Old Wounds (DNT)*/, 157114 /*157114 (Lightspawn) - Bound (DNT)*/, 156799 /*156799 (Henry Garrick) - Necrotic Ritual (DNT), Necrotic Ritual*/, 156518 /*156518 (Scout-o-Matic 5000)*/, 156532 /*156532 (Zombie Servant)*/, 165727 /*165727 (Plains Doe)*/, 154268 /*154268 (Hungry Vulture)*/, 165730 /*165730 (Plains Stag)*/, 150237 /*150237 (Quilboar Warrior) - Quilboar Sleep (DNT)*/, 150238 /*150238 (Quilboar Geomancer) - Necrotic Burst*/, 165713 /*165713 (Scurrying Rat) - Ride Vehicle*/, 156662 /*156662 (Captain Garrick)*/, 154301 /*154301 (Lindie Springstock) - Necrotic Ritual (DNT)*/, 154327 /*154327 (Austin Huxworth)*/, 164827 /*164827 (Sharpbeak Hawk)*/, 156607 /*156607 (Alaria) - Starving*/, 161133 /*161133 (Coastal Albatross)*/, 156622 /*156622 (Quartermaster Richter)*/, 156610 /*156610 (Austin Huxworth)*/, 156609 /*156609 (Bjorn Stouthands)*/, 156612 /*156612 (Kee-La)*/, 156626 /*156626 (Captain Garrick) - Kneel*/, 149917 /*149917 (Private Cole)*/, 155125 /*155125 (InvisBunny) - Open Sea (DNT)*/, 157043 /*157043 (Kee-La)*/, 157046 /*157046 (Austin Huxworth)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(140146, 0, 28912, 0, 1, 0, 0, 0, 0, ''), -- 140146 (Stormwind Infantry Captain)
(140022, 0, 0, 0, 1, 0, 15998, 0, 0, ''), -- 140022 (Stormwind Infantry)
(154155, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 154155 (Alliance Gryphon)
(168255, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 168255 (Alliance Gryphon)
(163963, 0, 85523, 0, 1, 0, 0, 0, 0, ''), -- 163963 (Brunston Hammersmith)
(165198, 0, 0, 0, 1, 0, 0, 0, 0, '321806'), -- 165198 (InvisBunny) - Necrotic Storm (Cosmetic 01)
(156814, 0, 0, 0, 1, 0, 0, 0, 0, '306097'), -- 156814 (Gor'groth) - Summon Ghouls
(156501, 0, 0, 0, 1, 0, 11415, 0, 0, '318318'), -- 156501 (Ravnyr) - Awaken (DNT)
(161350, 0, 0, 0, 1, 0, 0, 0, 0, '222584'), -- 161350 (Captain Garrick) - Threat 5000%
(157328, 0, 0, 0, 1, 0, 0, 0, 0, '306457'), -- 157328 (Darkmaul Channeler) - Dark Ritual
(156828, 0, 0, 50331648, 1, 0, 0, 0, 0, '305885'), -- 156828 (Shadowy Orb) - Arcane Lock
(156821, 0, 0, 0, 1, 0, 0, 0, 0, '214567 305886'), -- 156821 (Darkmaul Shadowcaller) - Mod Scale 90-110%, Arcane Channel
(153583, 0, 0, 0, 1, 0, 0, 0, 0, '145953'), -- 153583 (Jugnug) - Cosmetic - Sleep Zzz
(153581, 0, 0, 0, 1, 0, 0, 0, 0, '246849'), -- 153581 (Grunk) - Cosmetic - Sleep Zzz
(153582, 0, 0, 0, 1, 0, 0, 0, 0, '321820'), -- 153582 (Wug) - Enrage
(156954, 0, 0, 0, 1, 0, 0, 0, 0, '305513'), -- 156954 (Captain Kelra) - Necrotic Ritual (DNT)
(153580, 0, 0, 0, 1, 0, 0, 0, 0, '283844'), -- 153580 (Gor'groth) - Lightning Dissolve Out
(154103, 0, 0, 8, 1, 0, 0, 0, 0, '299441'), -- 154103 (Ogre Chef) - Cosmetic - Chef's Hat visual for Ogres
(153238, 0, 0, 262144, 1, 0, 0, 0, 0, '145363'), -- 153238 (Tamed Boar) - Permanent Feign Death (Stun, Untrackable, Immune)
(153239, 0, 0, 0, 1, 0, 0, 0, 0, '145953'), -- 153239 (Ogre Brute) - Cosmetic - Sleep Zzz
(153242, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 153242 (Ogre Shadowcaster)
(155733, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 155733 (Hidden Treasure Chest)
(161006, 0, 0, 262144, 1, 0, 0, 0, 0, '145363'), -- 161006 (Ogre Shadowcaster) - Permanent Feign Death (Stun, Untrackable, Immune)
(171997, 0, 0, 50331649, 1, 0, 0, 0, 0, ''), -- 171997 (Woodlands Watcher)
(163533, 0, 0, 262144, 1, 0, 0, 0, 0, '145363'), -- 163533 (Hjalmar the Undying) - Permanent Feign Death (Stun, Untrackable, Immune)
(152571, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 152571 (Harpy Snatcher)
(152843, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 152843 (Harpy Boltcaller)
(153964, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 153964 (Bloodbeak)
(153211, 0, 0, 0, 1, 0, 0, 0, 0, '305513'), -- 153211 (Meredy Huntswell) - Necrotic Ritual (DNT)
(163069, 0, 0, 262144, 1, 0, 0, 0, 0, '145363'), -- 163069 (Yorah) - Permanent Feign Death (Stun, Untrackable, Immune)
(160451, 0, 0, 0, 1, 0, 0, 0, 0, '298902'), -- 160451 (Hrun the Exiled) - Fire Burst
(156902, 0, 0, 0, 1, 0, 0, 0, 0, '305513'), -- 156902 (Ralia Dreamchaser) - Necrotic Ritual (DNT)
(160433, 0, 0, 0, 1, 0, 0, 0, 0, '316915'), -- 160433 (Barrow Spiderling) - Venomous Fangs
(156900, 0, 0, 0, 1, 0, 0, 0, 0, '322352'), -- 156900 (Hrun the Exiled) - Final Sacrifice
(160394, 0, 0, 0, 1, 0, 0, 0, 0, '316915'), -- 160394 (Barrow Spider) - Venomous Fangs
(153266, 0, 0, 0, 1, 0, 0, 0, 0, '313373'), -- 153266 (Killclaw the Terrible) - Old Wounds (DNT)
(157114, 0, 0, 0, 1, 0, 0, 0, 0, '319104'), -- 157114 (Lightspawn) - Bound (DNT)
(156799, 0, 0, 0, 1, 0, 0, 0, 0, '305513 325408'), -- 156799 (Henry Garrick) - Necrotic Ritual (DNT), Necrotic Ritual
(156518, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 156518 (Scout-o-Matic 5000)
(156532, 0, 0, 0, 1, 0, 18607, 0, 0, ''), -- 156532 (Zombie Servant)
(165727, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 165727 (Plains Doe)
(154268, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 154268 (Hungry Vulture)
(165730, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 165730 (Plains Stag)
(150237, 0, 0, 0, 1, 0, 0, 0, 0, '313265'), -- 150237 (Quilboar Warrior) - Quilboar Sleep (DNT)
(150238, 0, 0, 0, 1, 0, 0, 0, 0, '313261'), -- 150238 (Quilboar Geomancer) - Necrotic Burst
(165713, 0, 0, 0, 1, 0, 0, 0, 0, '52391'), -- 165713 (Scurrying Rat) - Ride Vehicle
(156662, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 156662 (Captain Garrick)
(154301, 0, 0, 0, 1, 0, 0, 0, 0, '305513'), -- 154301 (Lindie Springstock) - Necrotic Ritual (DNT)
(154327, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 154327 (Austin Huxworth)
(164827, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 164827 (Sharpbeak Hawk)
(156607, 0, 0, 0, 1, 0, 0, 0, 0, '313662'), -- 156607 (Alaria) - Starving
(161133, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 161133 (Coastal Albatross)
(156622, 0, 0, 3, 1, 0, 0, 0, 0, ''), -- 156622 (Quartermaster Richter)
(156610, 0, 0, 3, 1, 0, 0, 0, 0, ''), -- 156610 (Austin Huxworth)
(156609, 0, 0, 3, 1, 0, 0, 0, 0, ''), -- 156609 (Bjorn Stouthands)
(156612, 0, 0, 3, 1, 0, 0, 0, 0, ''), -- 156612 (Kee-La)
(156626, 0, 0, 0, 1, 0, 0, 0, 0, '313220'), -- 156626 (Captain Garrick) - Kneel
(149917, 0, 0, 3, 1, 0, 0, 0, 0, ''), -- 149917 (Private Cole)
(155125, 0, 0, 0, 1, 0, 0, 0, 0, '305351'), -- 155125 (InvisBunny) - Open Sea (DNT)
(157043, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 157043 (Kee-La)
(157046, 0, 0, 8, 1, 0, 0, 0, 0, ''); -- 157046 (Austin Huxworth)

UPDATE `creature_template_scaling` SET `VerifiedBuild`=41488 WHERE (`DifficultyID`=0 AND `Entry` IN (17804,61080,154169,140146,4959,51348,68,32520,111190,140022,154155,163963,168255,156814,156501,157300,168738,168740,161350,157328,161504,156828,156821,156825,156965,174525,153583,153581,153582,156961,156960,156954,161306,154103,154146,153580,154147,154145,153238,153239,153242,156942,156944,156943,156941,164927,155733,172026,161006,163040,171997,172027,163533,163039,156887,156886,156885,156882,156986,155197,155199,169162,155192,153211,152843,152998,163069,164025,157104,164026,164022,156859,155572,156860,152571,172028,172029,162954,153964,156932,156929,160451,156902,156900,156891,89715,160394,160433,153266,156808,174977,161666,150245,165758,156833,168382,156807,162817,156595,154300,156803,156801,156800,156804,157114,156799,156518,157091,156532,154268,165711,165730,149899,165727,149915,165757,156716,151091,156676,155371,165713,150238,165712,156662,154301,164826,150237,154327,175031,164827,156651,156607,151089,154170,151088,167761,161131,161133,161265,161130,156622,156610,156609,156612,156626,149917,150229,161228,150228,161224,157070,155125,167345,160664,154867,156403,156280,156345,157049,157043,157042,157046,157044,167886,160737,174971)) OR (`DifficultyID`=150 AND `Entry` IN (156913,166262,165198));

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (96136, 97267, 98013, 97213, 92821, 97229, 92822, 91782, 91775, 92825, 91776, 91853, 96778, 91854, 91851, 91777, 91778, 91779, 84585, 89266, 88787, 91781, 91780, 95204, 92795, 92831, 97228, 95075, 91010, 99445, 92751, 91998, 91996, 99207, 95210);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(96136, 0.208000004291534423, 1.5, 0, 41488),
(97267, 0.310000002384185791, 1, 0, 41488),
(98013, 11.64418411254882812, 12, 0, 41488),
(97213, 3.041802883148193359, 6.299999713897705078, 0, 41488),
(92821, 2.144748926162719726, 3.75, 0, 41488),
(97229, 0.305999994277954101, 1.5, 0, 41488),
(92822, 2.144748926162719726, 3.75, 0, 41488),
(91782, 1.71579897403717041, 3, 0, 41488),
(91775, 1.71579897403717041, 3, 0, 41488),
(92825, 1, 1.5, 0, 41488),
(91776, 1.71579897403717041, 3, 0, 41488),
(91853, 1.973168730735778808, 3.449999809265136718, 0, 41488),
(96778, 2.69066929817199707, 5.25, 0, 41488),
(91854, 1.973168730735778808, 3.449999809265136718, 0, 41488),
(91851, 1.973168730735778808, 3.449999809265136718, 0, 41488),
(91777, 1.71579897403717041, 3, 0, 41488),
(91778, 1.71579897403717041, 3, 0, 41488),
(91779, 1.71579897403717041, 3, 0, 41488),
(84585, 0.882957339286804199, 0, 0, 41488),
(89266, 0.426489889621734619, 1, 0, 41488),
(88787, 0.426489889621734619, 1, 0, 41488),
(91781, 1.71579897403717041, 3, 0, 41488),
(91780, 1.71579897403717041, 3, 0, 41488),
(95204, 0.729166150093078613, 3.149999856948852539, 0, 41488),
(92795, 0.347000002861022949, 1.5, 0, 41488),
(92831, 1.71579897403717041, 3, 0, 41488),
(97228, 0.347000002861022949, 1.5, 0, 41488),
(95075, 1, 1.5, 0, 41488),
(91010, 0.305999994277954101, 1.5, 0, 41488),
(99445, 0.208000004291534423, 1.5, 0, 41488),
(92751, 0.305999994277954101, 1.5, 0, 41488),
(91998, 0.305999994277954101, 1.5, 0, 41488),
(91996, 1, 1.5, 0, 41488),
(99207, 1, 1.5, 0, 41488),
(95210, 0.347222000360488891, 1.5, 0, 41488);

UPDATE `creature_model_info` SET `VerifiedBuild`=41488 WHERE `DisplayID` IN (17250, 328, 4626, 99389, 99391, 4469, 37311, 5446, 3167, 21342, 87372, 87371, 1065, 137, 987, 80910, 87544, 64330, 1141, 64328, 95920, 63605, 70179, 70178, 63597, 64922, 61764, 1157, 1088, 97258, 78851, 87594, 95022, 70162, 95765, 23681, 92693, 1197, 1198, 92691, 10824, 71224, 70722, 79614, 70440, 70446, 70448, 70451, 1072, 4658, 86424, 34007, 4959, 36357, 81105, 81106, 1963, 52696, 6106, 43225, 26566, 43226, 40122, 78151, 77902, 96541, 66292, 87603, 1762, 31, 75380, 3619, 983, 75371, 70861, 94939, 87221, 92690, 46929, 22661, 91997, 92804, 91995, 89870, 64062);
UPDATE `creature_model_info` SET `BoundingRadius`=2.161906719207763671, `CombatReach`=3.779999971389770507, `VerifiedBuild`=41488 WHERE `DisplayID`=58433;
UPDATE `creature_model_info` SET `BoundingRadius`=2.144748687744140625, `CombatReach`=3.75, `VerifiedBuild`=41488 WHERE `DisplayID` IN (86404, 56491);
UPDATE `creature_model_info` SET `BoundingRadius`=2.104584932327270507, `CombatReach`=1.346938848495483398, `VerifiedBuild`=41488 WHERE `DisplayID`=52656;
UPDATE `creature_model_info` SET `BoundingRadius`=0.426489889621734619, `CombatReach`=1, `VerifiedBuild`=41488 WHERE `DisplayID`=88786;
UPDATE `creature_model_info` SET `BoundingRadius`=1.156236171722412109, `CombatReach`=0.699999988079071044, `VerifiedBuild`=41488 WHERE `DisplayID`=73350;
UPDATE `creature_model_info` SET `BoundingRadius`=0.928183615207672119, `CombatReach`=0.655102074146270751, `VerifiedBuild`=41488 WHERE `DisplayID`=283;
UPDATE `creature_model_info` SET `BoundingRadius`=0.277218431234359741, `CombatReach`=0.649999976158142089, `VerifiedBuild`=41488 WHERE `DisplayID`=2177;
UPDATE `creature_model_info` SET `BoundingRadius`=1.866102457046508789, `CombatReach`=1.5, `VerifiedBuild`=41488 WHERE `DisplayID`=77903;
UPDATE `creature_model_info` SET `BoundingRadius`=0.310000002384185791, `VerifiedBuild`=41488 WHERE `DisplayID`=40123;
UPDATE `creature_model_info` SET `BoundingRadius`=0.334899783134460449, `CombatReach`=0.4375, `VerifiedBuild`=41488 WHERE `DisplayID`=75374;
UPDATE `creature_model_info` SET `BoundingRadius`=0.579470038414001464, `VerifiedBuild`=41488 WHERE `DisplayID`=86629;

DELETE FROM `npc_vendor` WHERE (`entry`=156800 AND `item`=168100 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=156800 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(156800, 2, 168100, 0, 0, 1, 0, 0, 41488), -- Alliance Tabard
(156800, 1, 117, 0, 0, 1, 0, 0, 41488); -- Tough Jerky

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (154169,163963,156814,157300,161350,156821,156825,153583,153581,153582,156961,153239,156941,163533,156986,156891,161666,156807,154300,156662,156651,156626));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(154169, 1, 163887, 0, 0, 163891, 0, 0, 0, 0, 0), -- Captain Garrick
(163963, 1, 122385, 0, 0, 0, 0, 0, 0, 0, 0), -- Brunston Hammersmith
(156814, 1, 176578, 0, 0, 0, 0, 0, 0, 0, 0), -- Gor'groth
(157300, 1, 178162, 0, 0, 0, 0, 0, 0, 0, 0), -- Tunk
(161350, 1, 163887, 0, 0, 163891, 0, 0, 0, 0, 0), -- Captain Garrick
(156821, 1, 110890, 0, 0, 0, 0, 0, 0, 0, 0), -- Darkmaul Shadowcaller
(156825, 1, 107419, 0, 0, 0, 0, 0, 0, 0, 0), -- Darkmaul Centurion
(153583, 1, 107418, 0, 0, 0, 0, 0, 0, 0, 0), -- Jugnug
(153581, 1, 105909, 0, 0, 0, 0, 0, 0, 0, 0), -- Grunk
(153582, 1, 112804, 0, 0, 112804, 0, 0, 0, 0, 0), -- Wug
(156961, 1, 163887, 0, 0, 163891, 0, 0, 0, 0, 0), -- Captain Garrick
(153239, 1, 107407, 0, 0, 0, 0, 0, 0, 0, 0), -- Ogre Brute
(156941, 1, 163887, 0, 0, 163891, 0, 0, 0, 0, 0), -- Captain Garrick
(163533, 1, 170712, 0, 0, 165276, 0, 0, 0, 0, 0), -- Hjalmar the Undying
(156986, 1, 164292, 0, 0, 0, 0, 0, 0, 0, 0), -- Ogre Taskmaster
(156891, 1, 0, 0, 0, 0, 0, 0, 167225, 0, 0), -- Bjorn Stouthands
(161666, 1, 0, 0, 0, 0, 0, 0, 110178, 0, 0), -- Austin Huxworth
(156807, 1, 163887, 0, 0, 163891, 0, 0, 0, 0, 0), -- Captain Garrick
(154300, 1, 0, 0, 0, 0, 0, 0, 167225, 0, 0), -- Bjorn Stouthands
(156662, 1, 163887, 0, 0, 163891, 0, 0, 0, 0, 0), -- Captain Garrick
(156651, 1, 163887, 0, 0, 163891, 0, 0, 0, 0, 0), -- Captain Garrick
(156626, 1, 163887, 0, 0, 163891, 0, 0, 0, 0, 0); -- Captain Garrick

DELETE FROM `gossip_menu` WHERE (`MenuId`=25162 AND `TextId`=39683) OR (`MenuId`=25193 AND `TextId`=39723) OR (`MenuId`=24550 AND `TextId`=37957) OR (`MenuId`=24886 AND `TextId`=13557) OR (`MenuId`=25321 AND `TextId`=39934) OR (`MenuId`=24887 AND `TextId`=39219) OR (`MenuId`=24543 AND `TextId`=38528) OR (`MenuId`=24885 AND `TextId`=41368) OR (`MenuId`=24240 AND `TextId`=38540);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(25162, 39683, 41488), -- 154169 (Captain Garrick)
(25193, 39723, 41488), -- 161350 (Captain Garrick)
(24550, 37957, 41488), -- 156943 (Meredy Huntswell)
(24886, 13557, 41488), -- 161666 (Austin Huxworth)
(25321, 39934, 41488), -- 156886 (Meredy Huntswell)
(24887, 39219, 41488), -- 153211 (Meredy Huntswell)
(24543, 38528, 41488), -- 156859 (Henry Garrick)
(24885, 41368, 41488), -- 156800 (Quartermaster Richter)
(24240, 38540, 41488); -- 154327 (Austin Huxworth)

DELETE FROM `gossip_menu_option` WHERE (`OptionIndex`=0 AND `MenuId` IN (25162,25193,24550,24886,24887,24885)) OR (`OptionIndex`=2 AND `MenuId`=24886) OR (`OptionIndex`=1 AND `MenuId`=25321);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(25162, 0, 0, 'I know my way around Stormwind. <Skip the city tour and choose a Timewalking Campaign.>', 0, 41488),
(25193, 0, 0, 'Let\'s get out of the citadel and figure out how to get back home.', 0, 41488),
(24550, 0, 0, 'I\'m ready, transform me into an ogre and I\'ll sneak into their citadel.', 0, 41488),
(24886, 0, 12, 'I\'d like to stable my pet here.', 30181, 41488),
(24886, 2, 0, 'I\'m ready to tame my pet, call them out.', 0, 41488),
(25321, 1, 0, 'Meredy, do you have an ice mote I could use?', 0, 41488),
(24887, 0, 0, 'I\'ll fight the harpies that come. Can you use your magic to break free?', 0, 41488),
(24885, 0, 1, 'Let me browse your goods.', 128, 41488); -- OptionBroadcastTextID: 2823 - 7509 - 8097
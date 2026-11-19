-- 
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

DELETE FROM `quest_request_items` WHERE `ID` IN (55174 /*Cooking Meat*/, 59355 /*A Hunter's Trap*/, 55122 /*Murloc Mania*/, 55990 /*Controlling their Stones*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(55174, 0, 0, 0, 0, 'Please... I need... some food...', 0), -- Cooking Meat
(59355, 0, 0, 0, 0, 'Did you get the supplies needed? Meredy should have the ice mote, while the other two should be nearby.', 0), -- A Hunter's Trap
(55122, 0, 0, 0, 0, 'Did you recover the first aid kits? Don\'t take the murlocs lightly.', 0), -- Murloc Mania
(55990, 0, 0, 0, 0, 'So, these were the stones used to bind me? The ogres clearly were concerned about you thwarting their plans.', 0); -- Controlling their Stones

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

DELETE FROM `spell_target_position` WHERE (`EffectIndex`=0 AND `ID` IN (319030,312548,305891)) OR (`EffectIndex`=4 AND `ID`=305425);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(319030, 0, 2175, 721.70001220703125, -1838.4000244140625, 186.5, 41488), -- Spell: 319030 (Teleport (DNT)) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(312548, 0, 2175, 108.8000030517578125, -2271.300048828125, 97.09999847412109375, 41488), -- Spell: 312548 (Teleport (DNT)) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(305891, 0, 2175, 229.0800018310546875, -2296.739990234375, 80.90000152587890625, 41488), -- Spell: 305891 (Teleport (DNT)) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(305425, 4, 2175, -462.399993896484375, -2619.800048828125, 0.400000005960464477, 41488); -- Spell: 305425 (Ship Crash (DNT)) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

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
(24885, 0, 1, 'Let me browse your goods.', 2823, 41488); -- OptionBroadcastTextID: 2823 - 7509 - 8097

UPDATE `quest_template` SET `VerifiedBuild`=41488 WHERE `ID` IN (59583, 55991, 55879, 55193, 53436, 62631, 56139, 63823, 55901, 63543, 56141, 63824, 63822, 46736, 46735, 46277);
UPDATE `quest_template` SET `RewardMoney`=1720, `VerifiedBuild`=41488 WHERE `ID`=55988; -- Like Ogres to the Slaughter
UPDATE `quest_template` SET `RewardMoney`=1720, `VerifiedBuild`=41488 WHERE `ID`=55989; -- Catapult Destruction
UPDATE `quest_template` SET `RewardMoney`=1720, `VerifiedBuild`=41488 WHERE `ID`=55990; -- Controlling their Stones
UPDATE `quest_template` SET `RewardMoney`=1470, `VerifiedBuild`=41488 WHERE `ID`=55981; -- Right Beneath Their Eyes
UPDATE `quest_template` SET `RewardMoney`=4410, `RewardBonusMoney`=120, `VerifiedBuild`=41488 WHERE `ID`=56839; -- Killclaw the Terrible
UPDATE `quest_template` SET `RewardMoney`=735, `RewardBonusMoney`=30, `VerifiedBuild`=41488 WHERE `ID`=56344; -- To Darkmaul Citadel
UPDATE `quest_template` SET `RewardMoney`=1470, `VerifiedBuild`=41488 WHERE `ID`=60168; -- The Art of Taming
UPDATE `quest_template` SET `RewardMoney`=1470, `VerifiedBuild`=41488 WHERE `ID`=59356; -- Hunting the Stalker
UPDATE `quest_template` SET `RewardMoney`=1015, `RewardBonusMoney`=60, `VerifiedBuild`=41488 WHERE `ID`=59355; -- A Hunter's Trap
UPDATE `quest_template` SET `RewardMoney`=510, `VerifiedBuild`=41488 WHERE `ID`=55882; -- Message to Base
UPDATE `quest_template` SET `RewardMoney`=1015, `RewardBonusMoney`=60, `VerifiedBuild`=41488 WHERE `ID`=55764; -- Harpy Culling
UPDATE `quest_template` SET `RewardMoney`=1015, `RewardBonusMoney`=60, `VerifiedBuild`=41488 WHERE `ID`=55881; -- Purge the Totems
UPDATE `quest_template` SET `RewardMoney`=1015, `RewardBonusMoney`=60, `VerifiedBuild`=41488 WHERE `ID`=55763; -- The Rescue of Meredy Huntswell
UPDATE `quest_template` SET `RewardMoney`=80, `VerifiedBuild`=41488 WHERE `ID`=54933; -- Freeing the Light
UPDATE `quest_template` SET `RewardMoney`=1600, `RewardBonusMoney`=60, `VerifiedBuild`=41488 WHERE `ID`=55639; -- Who Lurks in the Pit
UPDATE `quest_template` SET `RewardMoney`=400, `VerifiedBuild`=41488 WHERE `ID`=55196; -- The Harpy Problem
UPDATE `quest_template` SET `RewardMoney`=400, `VerifiedBuild`=41488 WHERE `ID`=55965; -- Westward Bound
UPDATE `quest_template` SET `RewardMoney`=600, `RewardBonusMoney`=30, `VerifiedBuild`=41488 WHERE `ID`=55194; -- Stocking Up on Supplies
UPDATE `quest_template` SET `RewardMoney`=360, `RewardBonusMoney`=30, `VerifiedBuild`=41488 WHERE `ID`=55184; -- Forbidden Quilboar Necromancy
UPDATE `quest_template` SET `RewardMoney`=360, `RewardBonusMoney`=30, `VerifiedBuild`=41488 WHERE `ID`=55186; -- Down with the Quilboar
UPDATE `quest_template` SET `RewardMoney`=180, `VerifiedBuild`=41488 WHERE `ID`=55173; -- Northbound
UPDATE `quest_template` SET `RewardMoney`=360, `RewardBonusMoney`=30, `VerifiedBuild`=41488 WHERE `ID`=55174; -- Cooking Meat
UPDATE `quest_template` SET `RewardMoney`=100, `VerifiedBuild`=41488 WHERE `ID`=54952; -- Finding the Lost Expedition
UPDATE `quest_template` SET `RewardMoney`=120, `RewardBonusMoney`=30, `VerifiedBuild`=41488 WHERE `ID`=55122; -- Murloc Mania
UPDATE `quest_template` SET `RewardMoney`=30, `VerifiedBuild`=41488 WHERE `ID`=58208; -- Brace for Impact
UPDATE `quest_template` SET `RewardMoney`=55, `RewardBonusMoney`=0, `VerifiedBuild`=41488 WHERE `ID`=58209; -- Stand Your Ground
UPDATE `quest_template` SET `RewardMoney`=55, `RewardBonusMoney`=30, `VerifiedBuild`=41488 WHERE `ID`=28767; -- Beating Them Back!
UPDATE `quest_template` SET `RewardMoney`=55, `RewardBonusMoney`=0, `VerifiedBuild`=41488 WHERE `ID`=56775; -- Warming Up
UPDATE `quest_template` SET `RewardMoney`=55, `RewardBonusMoney`=0, `VerifiedBuild`=41488 WHERE `ID`=59342; -- Taming the Wilds
UPDATE `quest_template` SET `RewardMoney`=4060, `RewardBonusMoney`=210, `VerifiedBuild`=41488 WHERE `ID`=55992; -- Dungeon: Darkmaul Citadel
UPDATE `quest_template` SET `RewardMoney`=40, `RewardBonusMoney`=0, `VerifiedBuild`=41488 WHERE `ID`=56034; -- Re-sizing the Situation
UPDATE `quest_template` SET `RewardMoney`=55, `RewardBonusMoney`=0, `VerifiedBuild`=41488 WHERE `ID`=54951; -- Emergency First Aid

UPDATE `quest_objectives` SET `VerifiedBuild`=41488 WHERE `ID` IN (389997, 389990, 389991, 394292, 394291, 389996, 389995, 389994, 389970, 389973, 389972, 389971, 390205, 390204, 390131, 391409, 397753, 397752, 397751, 396417, 396413, 396412, 396411, 389603, 389809, 389775, 390025, 390024, 390023, 390022, 393740, 391940, 391939, 396763, 388875, 395073, 396499, 389796, 391875, 388849, 388852, 394179, 396789, 391866, 390721, 393824, 254418, 341370, 391353, 396359, 396360, 395924, 394065, 394461, 390101, 391859, 391858, 388448, 408081, 390315, 420312, 420311, 420310, 420308, 420309, 420428, 420427, 420307, 420298, 419883, 419882, 390377, 390376, 389986, 389887, 390148, 390135, 389886, 419452, 419666, 419665, 419617, 419746, 419447, 419729, 390322, 420138, 420122, 419902, 420876, 419901, 419899, 419900, 419898, 420677, 420676, 420028, 420027, 420026, 420025, 420024, 420032, 420022, 420021, 419998, 419913, 419997, 289536, 289535, 289167);

UPDATE `quest_visual_effect` SET `VerifiedBuild`=41488 WHERE (`Index`=0 AND `ID` IN (389996,389995,389994,389971,390131,391409,397753,397752,396411,389775,393740,391940,391939,396763,388875,395073,388852,396789,391353,396359,396360,395924,394065,390101,420311,420310,420308,420309,420428,420427,420307,419882,419452,419729,419902,419900,419898,420676,420032,420021,419913,419997)) OR (`Index`=6 AND `ID`=397752) OR (`Index`=5 AND `ID`=397752) OR (`Index`=4 AND `ID` IN (397752,396359)) OR (`Index`=3 AND `ID` IN (397752,396359,420032)) OR (`Index`=2 AND `ID` IN (397752,396789,396359,420032)) OR (`Index`=1 AND `ID` IN (397752,396789,396359,394065,420311,420310,420308,420309,420427,420032));

UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=41488 WHERE (`Idx`=0 AND `QuestID` IN (59356,59355,54933));

UPDATE `creature_template` SET `VerifiedBuild`=41488 WHERE `entry` IN (154146, 154147, 172026, 154155, 172027, 172028, 172029, 154169, 156403, 154170, 165352, 68, 168738, 168740, 155371, 160964, 154268, 32520, 156518, 153168, 156526, 156532, 154300, 154301, 161006, 154327, 153211, 153238, 153239, 167761, 153242, 156595, 149899, 156607, 156609, 156610, 156612, 153266, 149915, 149917, 156622, 156626, 156651, 174525, 156660, 161130, 156662, 161131, 161133, 151088, 151089, 156676, 151091, 155572, 167886, 156716, 155607, 89715, 156736, 156749, 161224, 161228, 165711, 165712, 140022, 165713, 156781, 165727, 165730, 161265, 156799, 156800, 156801, 156803, 156804, 156807, 156808, 165757, 165758, 163533, 156833, 161306, 155733, 156859, 156860, 18357, 18359, 18360, 18362, 4959, 169162, 161350, 156882, 18375, 18376, 156885, 156886, 156887, 156891, 156900, 140146, 156902, 18406, 153565, 153566, 156929, 150228, 153580, 150229, 156932, 153581, 153582, 153583, 150237, 150238, 156941, 156942, 156943, 156944, 156947, 150245, 156948, 156954, 156960, 156961, 156965, 156986, 111190, 164826, 164827, 161504, 152571, 157042, 160394, 157043, 157044, 157046, 157049, 157051, 157070, 160433, 174955, 168255, 157091, 174971, 160451, 154867, 157104, 174977, 164927, 157114, 61080, 175031, 164986, 164989, 164990, 161666, 168382, 162817, 163963, 167345, 160656, 32206, 152843, 160664, 153964, 164022, 164025, 164026, 165150, 155125, 162954, 165198, 156267, 160737, 156280, 155192, 17804, 155197, 155199, 32335, 163039, 154103, 163040, 156345, 51348, 152998, 171997, 163069, 154145);
UPDATE `creature_template` SET `CreatureDifficultyID`=186220, `VerifiedBuild`=41488 WHERE `entry`=156501; -- Ravnyr
UPDATE `creature_template` SET `CreatureDifficultyID`=186219, `VerifiedBuild`=41488 WHERE `entry`=156814; -- Gor'groth
UPDATE `creature_template` SET `CreatureDifficultyID`=186222, `VerifiedBuild`=41488 WHERE `entry`=156821; -- Darkmaul Shadowcaller
UPDATE `creature_template` SET `CreatureDifficultyID`=186221, `VerifiedBuild`=41488 WHERE `entry`=156825; -- Darkmaul Centurion
UPDATE `creature_template` SET `CreatureDifficultyID`=186223, `VerifiedBuild`=41488 WHERE `entry`=156828; -- Shadowy Orb
UPDATE `creature_template` SET `CreatureDifficultyID`=186225, `VerifiedBuild`=41488 WHERE `entry`=156913; -- Decaying Corpse
UPDATE `creature_template` SET `CreatureDifficultyID`=186224, `VerifiedBuild`=41488 WHERE `entry`=157300; -- Tunk
UPDATE `creature_template` SET `CreatureDifficultyID`=186954, `VerifiedBuild`=41488 WHERE `entry`=166262; -- Decaying Corpse
UPDATE `creature_template` SET `CreatureDifficultyID`=186217, `VerifiedBuild`=41488 WHERE `entry`=157328; -- Darkmaul Channeler

UPDATE `creature_template_model` SET `VerifiedBuild`=41488 WHERE (`Idx`=1 AND `CreatureID` IN (61080,111190,32520,140146,51348,68,140022,156913,166262,165198,156828,156825,168738,156821,161306,153239,153242,164927,172026,161006,163040,171997,172027,163039,169162,152998,164025,164026,164022,157104,172029,155572,162954,160451,160964,160433,160394,174977,165758,168382,156532,165711,165727,165713,150238,150237,164827,167761,161131,161133,161228,150229,150228,161224,157070,160656,155125,167886,156403,174971)) OR (`Idx`=0 AND `CreatureID` IN (61080,17804,111190,32520,154169,140146,51348,4959,68,140022,168255,163963,154155,156913,166262,165198,161350,157328,156828,156501,157300,168740,161504,156825,168738,156814,156821,156965,174525,153583,153581,153582,156961,156960,161306,156954,154103,154146,153580,154147,154145,153238,153239,153242,156948,156947,153566,153565,156944,156943,156942,156941,164927,155733,172026,161006,163040,171997,172027,164990,164989,164986,163533,163039,156887,156886,156885,156882,156986,155197,169162,155192,153211,152843,152998,164025,163069,164026,164022,157104,172029,172028,156860,156859,155572,152571,162954,155199,156932,153964,156929,165352,160451,156902,160964,156900,156891,89715,160433,160394,153266,156808,174977,150245,165758,161666,168382,156833,156807,162817,165150,156267,156781,156595,156736,156749,174955,156804,156803,156801,156800,154300,157114,156526,156799,156518,157091,156532,154268,165711,165730,165727,149899,149915,165757,156716,156676,155371,165713,151091,150238,165712,156662,154301,164826,150237,154327,156660,175031,164827,156651,156607,153168,151089,154170,151088,167761,161131,161133,161265,161130,156610,156609,149917,161228,156626,150229,156622,150228,161224,156612,157070,155607,157051,160656,32335,32206,18362,18376,18406,18359,18357,18375,18360,167345,157042,156280,157043,155125,167886,160664,156345,157049,154867,157046,156403,157044,160737,174971)) OR (`Idx`=3 AND `CreatureID` IN (68,153239,153242,161006,160964,156532,164827,167886)) OR (`Idx`=2 AND `CreatureID` IN (68,156913,166262,168738,156821,153239,153242,172026,161006,171997,160964,160433,160394,156532,165711,165727,164827,161133,167886));

UPDATE `creature_questitem` SET `VerifiedBuild`=41488 WHERE (`Idx`=0 AND `CreatureEntry` IN (153583,153581,153582,150238,150237,161131,161133,161130,150229,150228));

DELETE FROM `gameobject_template` WHERE `entry` IN (336441 /*Doodad_6DU_HighmaulRaid_Door_ThroneRoom001*/, 334502 /*TEMP DOOR*/, 334578 /*Shadowy Door*/, 336442 /*6DU_HighmaulRaid_Door02*/, 327407 /*Precious Ogre Stash*/, 339643 /*Darkmaul Door*/, 339865 /*Ogre Runestone*/, 326651 /*Catapult*/, 346113 /*Druid Stone*/, 341951 /*Withering Hemlock*/, 330627 /*Danger Sign*/, 346278 /*Rusted Chains*/, 346277 /*Old Spring*/, 329919 /*Stolen Supplies*/, 326718 /*Ritual Pedestal*/, 339568 /*Thick Cocoon*/, 327146 /*Harpy Totem*/, 339769 /*Campfire*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(336441, 0, 17297, 'Doodad_6DU_HighmaulRaid_Door_ThroneRoom001', '', '', '', 0.701409876346588134, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41488), -- Doodad_6DU_HighmaulRaid_Door_ThroneRoom001
(334502, 0, 61459, 'TEMP DOOR', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41488), -- TEMP DOOR
(334578, 0, 61459, 'Shadowy Door', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41488), -- Shadowy Door
(336442, 0, 28699, '6DU_HighmaulRaid_Door02', '', '', '', 0.999999880790710449, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1038, 41488), -- 6DU_HighmaulRaid_Door02
(327407, 3, 259, 'Precious Ogre Stash', '', 'Opening', '', 1.5, 57, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 683, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3656, 97513, 0, 0, 0, 0, 683, 41488), -- Precious Ogre Stash
(339643, 5, 17297, 'Darkmaul Door', 'questinteract', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41488), -- Darkmaul Door
(339865, 10, 59825, 'Ogre Runestone', 'questinteract', 'Disabling', '', 0.200000002980232238, 3155, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40509, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 956, 41488), -- Ogre Runestone
(326651, 10, 14627, 'Catapult', 'questinteract', 'Placing', '', 1, 2173, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 35196, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 956, 41488), -- Catapult
(346113, 10, 33468, 'Druid Stone', 'questinteract', 'Placing', '', 1.60000002384185791, 3194, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 35196, 0, 0, 0, 0, 0, 1, 0, 79561, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 741, 41488), -- Druid Stone
(341951, 3, 47462, 'Withering Hemlock', 'questinteract', 'Retrieving', '', 1, 1691, 0, 1, 0, 0, 0, 0, 0, 58917, 0, 0, 0, 0, 0, 23645, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100778, 1, 0, 0, 0, 741, 41488), -- Withering Hemlock
(330627, 2, 14626, 'Danger Sign', '', '', '', 1, 0, 23167, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 741, 41488), -- Danger Sign
(346278, 3, 26682, 'Rusted Chains', 'questinteract', 'Retrieving', '', 1, 1691, 0, 1, 0, 0, 0, 0, 0, 59355, 0, 0, 0, 0, 0, 23645, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101445, 1, 0, 0, 0, 741, 41488), -- Rusted Chains
(346277, 3, 6681, 'Old Spring', 'questinteract', 'Retrieving', '', 0.5, 1691, 0, 1, 0, 0, 0, 0, 0, 59355, 0, 0, 0, 0, 0, 23645, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 101444, 1, 0, 0, 0, 741, 41488), -- Old Spring
(329919, 3, 49250, 'Stolen Supplies', '', 'Opening', '', 1.5, 57, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 683, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3753, 97514, 0, 0, 0, 0, 683, 41488), -- Stolen Supplies
(326718, 10, 56588, 'Ritual Pedestal', 'questinteract', 'Placing', '', 0.25, 3184, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 301471, 0, 0, 0, 35196, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 955, 41488), -- Ritual Pedestal
(339568, 10, 10461, 'Thick Cocoon', 'questinteract', 'Freeing', '', 1, 3196, 0, 0, 1, 0, 0, 0, 0, 0, 0, 313324, 0, 0, 0, 46504, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 955, 41488), -- Thick Cocoon
(327146, 10, 30315, 'Harpy Totem', 'questinteract', 'Burning', '', 1, 2160, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 155781, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 955, 41488), -- Harpy Totem
(339769, 3, 39107, 'Campfire', 'questinteract', 'Cooking', '', 1, 43, 0, 1, 0, 0, 0, 0, 364418, 0, 0, 0, 0, 0, 0, 184789, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99778, 1, 0, 0, 0, 741, 41488); -- Campfire

UPDATE `gameobject_template` SET `VerifiedBuild`=41488 WHERE `entry` IN (259008, 197144, 190536, 197141, 252247, 326719, 326717, 326716, 342131, 342365, 342366, 329918, 349948, 349947, 339770, 335718, 333479);

DELETE FROM `gameobject_questitem` WHERE (`Idx`=0 AND `GameObjectEntry` IN (341951,346278,346277,339769));
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(341951, 0, 174916, 41488), -- Withering Hemlock
(346278, 0, 175981, 41488), -- Rusted Chains
(346277, 0, 175980, 41488), -- Old Spring
(339769, 0, 174074, 41488); -- Campfire

UPDATE `gameobject_questitem` SET `VerifiedBuild`=41488 WHERE (`GameObjectEntry`=342366 AND `Idx`=0);

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (334502 /*TEMP DOOR*/, 336442 /*6DU_HighmaulRaid_Door02*/, 336441 /*Doodad_6DU_HighmaulRaid_Door_ThroneRoom001*/, 334578 /*Shadowy Door*/, 327407 /*Precious Ogre Stash*/, 339643 /*Darkmaul Door*/, 339865 /*Ogre Runestone*/, 326651 /*Catapult*/, 346113 /*Druid Stone*/, 341951 /*Withering Hemlock*/, 330627 /*Danger Sign*/, 346278 /*Rusted Chains*/, 346277 /*Old Spring*/, 329919 /*Stolen Supplies*/, 326718 /*Ritual Pedestal*/, 326719 /*Ritual Pedestal*/, 326717 /*Ritual Pedestal*/, 326716 /*Ritual Pedestal*/, 339568 /*Thick Cocoon*/, 342365 /*Campfire*/, 342366 /*Veil Blossom*/, 327146 /*Harpy Totem*/, 329918 /*Quilboar Treasures*/, 339770 /*Abandoned Treasure Chest*/, 339769 /*Campfire*/, 335718 /*Doodad_6DU_HighmaulRaid_Door_ThroneRoom001*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(334502, 0, 48, 0, 0), -- TEMP DOOR
(336442, 0, 48, 0, 0), -- 6DU_HighmaulRaid_Door02
(336441, 0, 32, 0, 0), -- Doodad_6DU_HighmaulRaid_Door_ThroneRoom001
(334578, 1375, 48, 0, 0), -- Shadowy Door
(327407, 0, 2113536, 2437, 0), -- Precious Ogre Stash
(339643, 1375, 0, 0, 0), -- Darkmaul Door
(339865, 0, 262144, 0, 0), -- Ogre Runestone
(326651, 0, 262176, 0, 0), -- Catapult
(346113, 0, 262144, 0, 0), -- Druid Stone
(341951, 0, 2113540, 0, 7912), -- Withering Hemlock
(330627, 0, 4, 0, 0), -- Danger Sign
(346278, 0, 2113540, 0, 3737), -- Rusted Chains
(346277, 0, 2113540, 0, 3737), -- Old Spring
(329919, 0, 2113536, 2437, 0), -- Stolen Supplies
(326718, 35, 262144, 0, 0), -- Ritual Pedestal
(326719, 35, 262144, 0, 0), -- Ritual Pedestal
(326717, 35, 262144, 0, 0), -- Ritual Pedestal
(326716, 35, 262144, 0, 0), -- Ritual Pedestal
(339568, 0, 262145, 0, 0), -- Thick Cocoon
(342365, 0, 262144, 0, 0), -- Campfire
(342366, 0, 4, 0, 3737), -- Veil Blossom
(327146, 35, 262176, 0, 17848), -- Harpy Totem
(329918, 0, 2113536, 2437, 0), -- Quilboar Treasures
(339770, 0, 2113536, 2437, 0), -- Abandoned Treasure Chest
(339769, 0, 2113540, 0, 0), -- Campfire
(335718, 0, 32, 0, 0); -- Doodad_6DU_HighmaulRaid_Door_ThroneRoom001

DELETE FROM `npc_text` WHERE `ID` IN (39683 /*39683*/, 39723 /*39723*/, 37957 /*37957*/, 39934 /*39934*/, 39219 /*39219*/, 38528 /*38528*/, 41368 /*41368*/, 38540 /*38540*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(39683, 1, 0, 0, 0, 0, 0, 0, 0, 187746, 0, 0, 0, 0, 0, 0, 0, 41488), -- 39683
(39723, 1, 0, 0, 0, 0, 0, 0, 0, 188023, 0, 0, 0, 0, 0, 0, 0, 41488), -- 39723
(37957, 1, 0, 0, 0, 0, 0, 0, 0, 175131, 0, 0, 0, 0, 0, 0, 0, 41488), -- 37957
(39934, 1, 0, 0, 0, 0, 0, 0, 0, 191017, 0, 0, 0, 0, 0, 0, 0, 41488), -- 39934
(39219, 1, 0, 0, 0, 0, 0, 0, 0, 184681, 0, 0, 0, 0, 0, 0, 0, 41488), -- 39219
(38528, 1, 0, 0, 0, 0, 0, 0, 0, 178847, 0, 0, 0, 0, 0, 0, 0, 41488), -- 38528
(41368, 1, 1, 1, 0, 0, 0, 0, 0, 201865, 201864, 201863, 0, 0, 0, 0, 0, 41488), -- 41368
(38540, 1, 0, 0, 0, 0, 0, 0, 0, 178946, 0, 0, 0, 0, 0, 0, 0, 41488); -- 38540

UPDATE `npc_text` SET `VerifiedBuild`=41488 WHERE `ID`=13557;

-- 
UPDATE `page_text` SET `Text`='That the Sironas entity had plans for Saruan...\n\n<The writing stops abruptly and a long line scrolls off the page. This draenei died while making the entry.>\n', `VerifiedBuild`=26124 WHERE `ID`=2940; -- 2940
UPDATE `page_text` SET `Text`='After what seemed an eternity, the Vindicator lost consciousness. The torture was too much, even for him. The cruel one - Matis as I found out he was called - attempted to wake Saruan by splashing contagion laced water across his ravaged body. But Saruan did not wake.\n', `VerifiedBuild`=26124 WHERE `ID`=2938; -- 2938
UPDATE `page_text` SET `Text`='I watched as they beat him without mercy. Their ruthless lieutenant acted as if such cruelty was an act of normalcy. Through the savage beatings, I could feel myself breaking.$B$BAs I watched Vindicator Saruan take their blows, I began to weep. Not out of fear... I wept out of sadness. To see a draenei of the Triumvirate treated in such a manner. If only I could have broken free of my bonds. If only...\n', `VerifiedBuild`=26124 WHERE `ID`=2937; -- 2937

DELETE FROM `npc_text` WHERE `ID` IN (9153 /*9153*/, 9148 /*9148*/, 9155 /*9155*/, 9158 /*9158*/, 9151 /*9151*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(9153, 1, 0, 0, 0, 0, 0, 0, 0, 14680, 0, 0, 0, 0, 0, 0, 0, 26124), -- 9153
(9148, 1, 0, 0, 0, 0, 0, 0, 0, 14674, 0, 0, 0, 0, 0, 0, 0, 26124), -- 9148
(9155, 1, 0, 0, 0, 0, 0, 0, 0, 14682, 0, 0, 0, 0, 0, 0, 0, 26124), -- 9155
(9158, 1, 0, 0, 0, 0, 0, 0, 0, 14685, 0, 0, 0, 0, 0, 0, 0, 26124), -- 9158
(9151, 1, 0, 0, 0, 0, 0, 0, 0, 14677, 0, 0, 0, 0, 0, 0, 0, 26124); -- 9151

UPDATE `npc_text` SET `BroadcastTextId2`=14721, `VerifiedBuild`=26124 WHERE `ID`=9172; -- 9172
UPDATE `page_text` SET `Text`='Contact our spy and prepare for a full scale assault upon the draenei. Kill them all and recover my vessel. You are the only link I have on Azeroth that is able to repair the damage the brutes inflicted upon the Exodar.\n\nDo not fail me, gnome. Should your lust for riches interfere with my orders, you will spend eternity in prayer. You''ll pray for death to come and release you from the tortures I''ll unleash should you falter.\n\n-King Sunstrider\n', `VerifiedBuild`=26124 WHERE `ID`=2920; -- 2920
UPDATE `page_text` SET `Text`='Servant,\n \nSeveral years worth of planning has been lost. The draenei and their pitiful leader have escaped the Master''s grasp once again! What''s more, they have stolen MY vessel and crashed it upon Azeroth! \n\nWhile it is true that the Master''s eredar agent has failed, she was able to transmit the Exodar''s location to us. Fortuitously, her identity is still a mystery to the draenei. We may still be able to use her for our purposes.\n', `VerifiedBuild`=26124 WHERE `ID`=2919; -- 2919

DELETE FROM `npc_text` WHERE `ID`=20143;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(20143, 1, 0, 0, 0, 0, 0, 0, 0, 62803, 0, 0, 0, 0, 0, 0, 0, 26124); -- 20143

UPDATE `npc_text` SET `BroadcastTextId0`=14757, `VerifiedBuild`=26124 WHERE `ID`=9179; -- 9179
UPDATE `npc_text` SET `BroadcastTextId0`=13644, `VerifiedBuild`=26124 WHERE `ID`=8850; -- 8850

UPDATE `page_text` SET `Text`='Day 15\nOur dedication has paid off.  We are the first camp to finish the construction of a wind stone.  If the other fools had stayed with us we would''ve completed the task in less than a week!  \n\nTomorrow we shall begin the rituals involved in summoning Baron Kazum himself.  He demanded to be the first to test the system and we couldn''t contradict him as he''s quick to anger.  \n\nI expect he will be most pleased with us.', `VerifiedBuild`=26124 WHERE `ID`=2809; -- 2809
UPDATE `page_text` SET `Text`='Day 2\nThe location of the wind stone has been a subject of great debate.  Not even the wisest among us can determine with great certainty where the place mentioned in the old prophecy actually refers to.\n\nI''ve stayed with the original northern group and time will undoubtedly prove us right.  The argument that the energy lines intersect at detrimental angles at this location are foolish and naive. \n\nAlready we are gathering the necessary building materials at great speed.  ', `VerifiedBuild`=26124 WHERE `ID`=2808; -- 2808
UPDATE `page_text` SET `Text`='Day 1\nOur pilgrimage is over.  We''ve finally reached Silithus, where we''re to establish contact.  We have come from many places to collaborate in what is to be a monumental undertaking.\n\nThere is a tremendous sense of excitement in the air.  Tomorrow we shall devote all our energy to building that which will allow communication with THEM.  \n\nTomorrow we shall construct a wind stone!', `VerifiedBuild`=26124 WHERE `ID`=2807; -- 2807

DELETE FROM `npc_text` WHERE `ID`=33093;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(33093, 1, 0, 0, 0, 0, 0, 0, 0, 138522, 0, 0, 0, 0, 0, 0, 0, 26124); -- 33093

DELETE FROM `npc_text` WHERE `ID`=30907;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(30907, 1, 0, 0, 0, 0, 0, 0, 0, 124670, 0, 0, 0, 0, 0, 0, 0, 26124); -- 30907

UPDATE `npc_text` SET `BroadcastTextId0`=38398, `VerifiedBuild`=26124 WHERE `ID`=15347; -- 15347

DELETE FROM `page_text` WHERE `ID` IN (3705 /*3705*/, 3704 /*3704*/, 3703 /*3703*/, 3702 /*3702*/, 3701 /*3701*/, 3607 /*3607*/, 3606 /*3606*/);
INSERT INTO `page_text` (`ID`, `Text`, `NextPageID`, `PlayerConditionID`, `Flags`, `VerifiedBuild`) VALUES
(3705, 'DELICIOUS JOURNAL I MUST EAT IT\n\n<The rest of the pages are missing>', 0, 0, 0, 26124), -- 3705
(3704, 'THE others let me JOIN them finally they showed me the ARTIFACT for a really long time til I felt the tingles they say MEATFACE knows everything he is the SMARTEST I hope with his help we can LIBERATE this lost beach from the OTHER EVIL GOBLINS that came in their FLYING MACHINES to KILL US they lied they said WE''RE FROM GADGET-ZAN TO SAVE YOU but we were not fooled we took their stuff ha ha ha', 3705, 0, 0, 26124), -- 3704
(3703, 'The guys who found that artifact are acting a little FUNNY! Nothing too bad for a goblin mind you. And they''ve only stabbed one or TWO people.\n\nI guess it''s not that bad! Everyone around here is feeling a LITTLE funny anyway ha ha ha.\nThat brute they keep with them sure TALKS a lot, though.', 3704, 0, 0, 26124), -- 3703
(3702, 'We found something amazing! An old busted-up machine thing. One of the smartypants antique collectors that survived the crash said it looked like it might be a Titan thingy.\n\nWhatever it is, I bet it''s valuable. The guys that found it said their heads hurt after digging it up and it''s leaking some kinda glowy light but WHATEVER!', 3703, 0, 0, 26124), -- 3702
(3701, 'We''ve landed! Well, more like crashed. The boats tore themselves open overnight while the "captain" had a rag tied to the wheel.\n\nWe all woke up face-down in the sand on this mysterious desert beach! Nobody has any idea where we are, but we''ll have to make do in this exotic and highly uncharted territory.\n\nDid I say we all woke up? That may have been an exaggeration.', 3702, 0, 0, 26124), -- 3701
(3607, 'We''ve been on the ocean for what seems like forever. I don''t think anyone knows where we are.\n\nOur supplies are dwindling, and we used up half our water trying to run the pump for the makeshift desalinator. We tried throwing a few people overboard to gain speed, but we kept all their gold so it didn''t help that much.\n\nIt was kinda fun, though.', 3701, 0, 0, 26124), -- 3607
(3606, 'We barely escaped from Kezan with our lives! The volcano took everything...my house, my car, my pet boar, my pet boar''s house, my pet boar''s car...\n\nBut at least we got safely onto the ships! We''ll sail straight for Durotar, sucker a few orcs after we get onto dry land again, and be rolling in money again within a week!', 3607, 0, 0, 26124); -- 3606

DELETE FROM `npc_text` WHERE `ID` IN (17234 /*17234*/, 16827 /*16827*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(17234, 1, 0, 0, 0, 0, 0, 0, 0, 47627, 0, 0, 0, 0, 0, 0, 0, 25996), -- 17234
(16827, 1, 0, 0, 0, 0, 0, 0, 0, 45517, 0, 0, 0, 0, 0, 0, 0, 25996); -- 16827

DELETE FROM `npc_text` WHERE `ID` IN (15589 /*15589*/, 15588 /*15588*/, 15564 /*15564*/, 15547 /*15547*/, 15590 /*15590*/, 21208 /*21208*/, 15587 /*15587*/, 15552 /*15552*/, 15586 /*15586*/, 15539 /*15539*/, 15530 /*15530*/, 15515 /*15515*/, 15518 /*15518*/, 15514 /*15514*/, 15519 /*15519*/, 15496 /*15496*/, 15522 /*15522*/, 15521 /*15521*/, 15520 /*15520*/, 15495 /*15495*/, 15517 /*15517*/, 15482 /*15482*/, 15483 /*15483*/, 15459 /*15459*/, 15480 /*15480*/, 15479 /*15479*/, 15478 /*15478*/, 15477 /*15477*/, 15476 /*15476*/, 15475 /*15475*/, 15474 /*15474*/, 15473 /*15473*/, 15471 /*15471*/, 15481 /*15481*/, 15455 /*15455*/, 15409 /*15409*/, 15411 /*15411*/, 15398 /*15398*/, 15397 /*15397*/, 15393 /*15393*/, 15594 /*15594*/, 15314 /*15314*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(15589, 1, 0, 0, 0, 0, 0, 0, 0, 39346, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15589
(15588, 1, 0, 0, 0, 0, 0, 0, 0, 39345, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15588
(15564, 1, 0, 0, 0, 0, 0, 0, 0, 39253, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15564
(15547, 1, 0, 0, 0, 0, 0, 0, 0, 39209, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15547
(15590, 1, 0, 0, 0, 0, 0, 0, 0, 39347, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15590
(21208, 1, 0, 0, 0, 0, 0, 0, 0, 67609, 0, 0, 0, 0, 0, 0, 0, 25996), -- 21208
(15587, 1, 0, 0, 0, 0, 0, 0, 0, 39344, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15587
(15552, 1, 0, 0, 0, 0, 0, 0, 0, 39218, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15552
(15586, 1, 0, 0, 0, 0, 0, 0, 0, 39343, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15586
(15539, 1, 0, 0, 0, 0, 0, 0, 0, 39192, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15539
(15530, 1, 0, 0, 0, 0, 0, 0, 0, 39170, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15530
(15515, 1, 0, 0, 0, 0, 0, 0, 0, 39117, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15515
(15518, 1, 0, 0, 0, 0, 0, 0, 0, 39121, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15518
(15514, 1, 0, 0, 0, 0, 0, 0, 0, 39115, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15514
(15519, 1, 0, 0, 0, 0, 0, 0, 0, 39122, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15519
(15496, 1, 0, 0, 0, 0, 0, 0, 0, 39040, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15496
(15522, 1, 0, 0, 0, 0, 0, 0, 0, 39128, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15522
(15521, 1, 0, 0, 0, 0, 0, 0, 0, 39126, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15521
(15520, 1, 0, 0, 0, 0, 0, 0, 0, 39124, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15520
(15495, 1, 0, 0, 0, 0, 0, 0, 0, 39041, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15495
(15517, 1, 0, 0, 0, 0, 0, 0, 0, 39120, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15517
(15482, 1, 0, 0, 0, 0, 0, 0, 0, 38962, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15482
(15483, 1, 0, 0, 0, 0, 0, 0, 0, 38963, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15483
(15459, 1, 0, 0, 0, 0, 0, 0, 0, 38841, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15459
(15480, 1, 0, 0, 0, 0, 0, 0, 0, 38936, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15480
(15479, 1, 0, 0, 0, 0, 0, 0, 0, 38935, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15479
(15478, 1, 0, 0, 0, 0, 0, 0, 0, 38934, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15478
(15477, 1, 0, 0, 0, 0, 0, 0, 0, 38933, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15477
(15476, 1, 0, 0, 0, 0, 0, 0, 0, 38932, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15476
(15475, 1, 0, 0, 0, 0, 0, 0, 0, 38931, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15475
(15474, 1, 0, 0, 0, 0, 0, 0, 0, 38930, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15474
(15473, 1, 0, 0, 0, 0, 0, 0, 0, 38929, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15473
(15471, 1, 0, 0, 0, 0, 0, 0, 0, 38927, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15471
(15481, 1, 0, 0, 0, 0, 0, 0, 0, 38961, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15481
(15455, 1, 0, 0, 0, 0, 0, 0, 0, 38827, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15455
(15409, 1, 0, 0, 0, 0, 0, 0, 0, 38643, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15409
(15411, 1, 0, 0, 0, 0, 0, 0, 0, 38650, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15411
(15398, 1, 0, 0, 0, 0, 0, 0, 0, 38585, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15398
(15397, 1, 0, 0, 0, 0, 0, 0, 0, 38580, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15397
(15393, 1, 0, 0, 0, 0, 0, 0, 0, 38573, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15393
(15594, 1, 0, 0, 0, 0, 0, 0, 0, 39359, 0, 0, 0, 0, 0, 0, 0, 25996), -- 15594
(15314, 1, 0, 0, 0, 0, 0, 0, 0, 38308, 0, 0, 0, 0, 0, 0, 0, 25996); -- 15314

DELETE FROM `npc_text` WHERE `ID`=21180;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(21180, 1, 0, 0, 0, 0, 0, 0, 0, 67480, 0, 0, 0, 0, 0, 0, 0, 25996); -- 21180

DELETE FROM `npc_text` WHERE `ID`=17839;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(17839, 1, 1, 1, 1, 1, 0, 0, 0, 50755, 51339, 51340, 51342, 51343, 0, 0, 0, 25996); -- 17839

UPDATE `page_text` SET `Text`='\nThe reports of the night elves assisting the draenei are true.  They''re attempting to setup a new base of operations at Forest Song to the north near Satyrnaar.  We should confer on combining our forces for an attack before the next full moon of this pathetic world.  If we crush them now they will never gain a toehold on our doorstep!\n\nRegards,\n\nGorgannon\n\np.s. - Stop using up all of the blood ink on love letters to my lashers!  Night elf virgins are in short supply these days.', `VerifiedBuild`=25996 WHERE `ID`=2910; -- 2910
UPDATE `page_text` SET `Text`='\nDiathorus,\n\nI trust that this letter will eventually make its way to you.  These demons are mindless.  All they think about is their nails, their whips, or goring something with their head spikes.  And I dare not use one of the infernals lest it be burned to ashes!\n\nSadly, I long for the days when we could use the orcs.  At least they had half a brain and could follow orders.  Perhaps there is an opportunity to take some new thralls from nearby?', `VerifiedBuild`=25996 WHERE `ID`=2909; -- 2909
UPDATE `page_text` SET `Text`='In his fury, Sargeras shattered the prisons he''d created and set the loathsome demons free. These cunning creatures bowed before the dark Titan''s vast rage and offered to serve him in whatever malicious ways they could. Seeking a way to lead and control his vast demonic army, Sargeras recruited (and subsequently corrupted) the ancient and intelligent race of the Eredar. From within their ranks, Sargeras picked two champions to command his demonic army of destruction.', `VerifiedBuild`=25996 WHERE `ID`=1782; -- 1782
UPDATE `page_text` SET `Text`='While his confusion and misery deepened, Sargeras was forced to contend with a particularly insidious group intent on disrupting the Titans'' order: the Nathrezim. This dark race of vampiric demons (also known as dreadlords) conquered a number of populated worlds by possessing their inhabitants and turning them to the shadow.', `VerifiedBuild`=25996 WHERE `ID`=1776; -- 1776
UPDATE `page_text` SET `Text`='Although Sargeras'' nearly limitless powers made short work of the shambling demons he found throughout the Great Dark, he was greatly troubled by the creatures'' corruption and all-consuming evil. Incapable of fathoming such depravity, the great Titan began to slip into a brooding depression. Despite his growing unease, Sargeras rid the universe of demonic entities by trapping them within a corner of the Twisting Nether.', `VerifiedBuild`=25996 WHERE `ID`=1775; -- 1775
UPDATE `page_text` SET `Text`='Over time, demonic entities made their way into the Titans'' worlds from the Twisting Nether, and the Pantheon elected its greatest warrior, Sargeras, to act as its first line of defense. A noble giant of molten bronze, Sargeras carried out his duties for countless millennia, seeking out and destroying these demons wherever he could find them.', `NextPageID`=1775, `VerifiedBuild`=25996 WHERE `ID`=1773; -- 1773

DELETE FROM `npc_text` WHERE `ID`=21179;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(21179, 1, 0, 0, 0, 0, 0, 0, 0, 67478, 0, 0, 0, 0, 0, 0, 0, 25996); -- 21179

UPDATE `npc_text` SET `BroadcastTextId0`=33548, `VerifiedBuild`=25996 WHERE `ID`=14347; -- 14347

DELETE FROM `page_text` WHERE `ID`=3561;
INSERT INTO `page_text` (`ID`, `Text`, `NextPageID`, `PlayerConditionID`, `Flags`, `VerifiedBuild`) VALUES
(3561, '<The Apothecary''s notes are scribbled in a cramped hand, with complex alchemic formulas interspersed among childlike doodles of skulls and lightning bolts. Squinting, you can make out parts of a recent passage:>\n\n...most magnificent corruption, embedding itself deep within living tissue. Extremely contagious when <several words are smudged> via food chain. Today''s tests confirm it is only partially biological in origin. Foulhoof, my <illegible> companion, preoccupied with vengeance and blind to the more ''constructive'' applications of his <a greenish ichor stains the remainder of the paragraph.> Research progresses slowly. Hope my companions at Althalaxx fare better.  ', 0, 0, 0, 25996); -- 3561

DELETE FROM `npc_text` WHERE `ID` IN (14470 /*14470*/, 14468 /*14468*/, 14294 /*14294*/, 14292 /*14292*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(14470, 1, 0, 0, 0, 0, 0, 0, 0, 34224, 0, 0, 0, 0, 0, 0, 0, 25996), -- 14470
(14468, 1, 0, 0, 0, 0, 0, 0, 0, 34215, 0, 0, 0, 0, 0, 0, 0, 25996), -- 14468
(14294, 1, 0, 0, 0, 0, 0, 0, 0, 33160, 0, 0, 0, 0, 0, 0, 0, 25996), -- 14294
(14292, 1, 0, 0, 0, 0, 0, 0, 0, 33158, 0, 0, 0, 0, 0, 0, 0, 25996); -- 14292

UPDATE `npc_text` SET `BroadcastTextId0`=34095, `VerifiedBuild`=25996 WHERE `ID`=14454; -- 14454
UPDATE `npc_text` SET `BroadcastTextId0`=33410, `VerifiedBuild`=25996 WHERE `ID`=14327; -- 14327

DELETE FROM `npc_text` WHERE `ID` IN (14980 /*14980*/, 14978 /*14978*/, 14979 /*14979*/, 14973 /*14973*/, 14968 /*14968*/, 14795 /*14795*/, 14739 /*14739*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(14980, 1, 0, 0, 0, 0, 0, 0, 0, 36443, 0, 0, 0, 0, 0, 0, 0, 25996), -- 14980
(14978, 1, 0, 0, 0, 0, 0, 0, 0, 36441, 0, 0, 0, 0, 0, 0, 0, 25996), -- 14978
(14979, 1, 0, 0, 0, 0, 0, 0, 0, 36442, 0, 0, 0, 0, 0, 0, 0, 25996), -- 14979
(14973, 1, 0, 0, 0, 0, 0, 0, 0, 36413, 0, 0, 0, 0, 0, 0, 0, 25996), -- 14973
(14968, 1, 0, 0, 0, 0, 0, 0, 0, 36403, 0, 0, 0, 0, 0, 0, 0, 25996), -- 14968
(14795, 1, 0, 0, 0, 0, 0, 0, 0, 35962, 0, 0, 0, 0, 0, 0, 0, 25996), -- 14795
(14739, 1, 0, 0, 0, 0, 0, 0, 0, 35563, 0, 0, 0, 0, 0, 0, 0, 25996); -- 14739

DELETE FROM `npc_text` WHERE `ID`=15836;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(15836, 1, 0, 0, 0, 0, 0, 0, 0, 40311, 0, 0, 0, 0, 0, 0, 0, 25996); -- 15836

DELETE FROM `npc_text` WHERE `ID`=27173;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(27173, 1, 0, 0, 0, 0, 0, 0, 0, 98275, 0, 0, 0, 0, 0, 0, 0, 25996); -- 27173

UPDATE `npc_text` SET `BroadcastTextId0`=4719, `VerifiedBuild`=25996 WHERE `ID`=2433; -- 2433

UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=3033; -- 3033
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=579; -- 579
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=548; -- 548
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=507; -- 507
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=9125; -- 9125
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=9121; -- 9121
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18299; -- 18299
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=11243; -- 11243
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=11245; -- 11245
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=11126; -- 11126
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=11281; -- 11281
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15841; -- 15841
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=11365; -- 11365
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=21215; -- 21215
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=12334; -- 12334
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=11311; -- 11311
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=3590; -- 3590
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=11309; -- 11309
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=11403; -- 11403
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=11469; -- 11469
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=11432; -- 11432
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=11264; -- 11264
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=4837; -- 4837
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18072; -- 18072
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18074; -- 18074
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18071; -- 18071
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15111; -- 15111
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18076; -- 18076
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=11457; -- 11457
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=1058; -- 1058
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=1794; -- 1794
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=4991; -- 4991
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=6415; -- 6415
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=3977; -- 3977
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=16569; -- 16569
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=11426; -- 11426
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=11376; -- 11376
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=5579; -- 5579
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=11224; -- 11224
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=5571; -- 5571
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=4859; -- 4859
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18070; -- 18070
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=16705; -- 16705
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18050; -- 18050
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=5049; -- 5049
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=11424; -- 11424
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18108; -- 18108
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18107; -- 18107
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18106; -- 18106
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18105; -- 18105
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18104; -- 18104
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18103; -- 18103
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18102; -- 18102
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18101; -- 18101
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18100; -- 18100
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18099; -- 18099
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18098; -- 18098
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18097; -- 18097
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18096; -- 18096
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18095; -- 18095
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18094; -- 18094
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18093; -- 18093
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18091; -- 18091
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18090; -- 18090
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18089; -- 18089
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18088; -- 18088
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18087; -- 18087
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17774; -- 17774
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18086; -- 18086
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=11492; -- 11492
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=11136; -- 11136
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=3157; -- 3157
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=6333; -- 6333
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18064; -- 18064
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18063; -- 18063
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=12929; -- 12929
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=18067; -- 18067
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=12933; -- 12933
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14128; -- 14128
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=5218; -- 5218
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=5104; -- 5104
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=16585; -- 16585
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15771; -- 15771
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15845; -- 15845
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15821; -- 15821
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15835; -- 15835
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15828; -- 15828
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=21183; -- 21183
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=2639; -- 2639
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=7116; -- 7116
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15834; -- 15834
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15816; -- 15816
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15808; -- 15808
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15719; -- 15719
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15761; -- 15761
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15838; -- 15838
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14792; -- 14792
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=6335; -- 6335
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14943; -- 14943
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=6353; -- 6353
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14897; -- 14897
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=21185; -- 21185
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14942; -- 14942
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14873; -- 14873
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=4449; -- 4449
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14849; -- 14849
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14834; -- 14834
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14801; -- 14801
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=6334; -- 6334
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14469; -- 14469
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14510; -- 14510
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14447; -- 14447
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14505; -- 14505
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14298; -- 14298
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14291; -- 14291
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14300; -- 14300
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14290; -- 14290
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14293; -- 14293
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14299; -- 14299
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14296; -- 14296
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14295; -- 14295
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14297; -- 14297
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=4437; -- 4437
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=4794; -- 4794
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=5725; -- 5725
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=5473; -- 5473
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14508; -- 14508
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=9384; -- 9384
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17861; -- 17861
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=10654; -- 10654
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=5722; -- 5722
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17616; -- 17616
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=20326; -- 20326
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=10652; -- 10652
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=5121; -- 5121
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17859; -- 17859
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17519; -- 17519
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14526; -- 14526
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14511; -- 14511
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14518; -- 14518
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14531; -- 14531
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14529; -- 14529
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=16615; -- 16615
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14548; -- 14548
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14517; -- 14517
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14547; -- 14547
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14509; -- 14509
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14259; -- 14259
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14264; -- 14264
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14276; -- 14276
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14274; -- 14274
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14275; -- 14275
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14260; -- 14260
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14304; -- 14304
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=1238; -- 1238
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=7016; -- 7016
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=1242; -- 1242
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=7027; -- 7027
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=1220; -- 1220
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14506; -- 14506
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14525; -- 14525
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14524; -- 14524
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14541; -- 14541
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=2211; -- 2211
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=1802; -- 1802
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=1801; -- 1801
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=1800; -- 1800
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=1799; -- 1799
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=1798; -- 1798
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=1797; -- 1797
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=1796; -- 1796
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=1795; -- 1795
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=2067; -- 2067
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=2066; -- 2066
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=2065; -- 2065
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=2064; -- 2064
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=2071; -- 2071
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=2070; -- 2070
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=2069; -- 2069
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=2068; -- 2068
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=1786; -- 1786
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=1785; -- 1785
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=1784; -- 1784
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=1783; -- 1783
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=1781; -- 1781
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=1780; -- 1780
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=1779; -- 1779
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=1778; -- 1778
UPDATE `page_text` SET `VerifiedBuild`=25996 WHERE `ID`=1777; -- 1777
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=8876; -- 8876
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=8874; -- 8874
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=9986; -- 9986
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=8875; -- 8875
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=8873; -- 8873
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=8838; -- 8838
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=8939; -- 8939
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=16363; -- 16363
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=9983; -- 9983
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=7725; -- 7725
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14577; -- 14577
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14576; -- 14576
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14575; -- 14575
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14557; -- 14557
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=3233; -- 3233
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15946; -- 15946
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14572; -- 14572
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=838; -- 838
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14571; -- 14571
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14556; -- 14556
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14538; -- 14538
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14520; -- 14520
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14521; -- 14521
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14523; -- 14523
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=6553; -- 6553
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=5360; -- 5360
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14351; -- 14351
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14339; -- 14339
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14315; -- 14315
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14316; -- 14316
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17482; -- 17482
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=4401; -- 4401
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=4399; -- 4399
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=8124; -- 8124
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=8123; -- 8123
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17483; -- 17483
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17484; -- 17484
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=4993; -- 4993
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17426; -- 17426
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17452; -- 17452
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17433; -- 17433
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17430; -- 17430
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17477; -- 17477
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17357; -- 17357
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=21219; -- 21219
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17843; -- 17843
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17837; -- 17837
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=3807; -- 3807
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=11714; -- 11714
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17197; -- 17197
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=3874; -- 3874
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=4394; -- 4394
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=4393; -- 4393
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=3854; -- 3854
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17665; -- 17665
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17587; -- 17587
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17586; -- 17586
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17666; -- 17666
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=6534; -- 6534
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=4573; -- 4573
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=3673; -- 3673
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=825; -- 825
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=7243; -- 7243
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=7247; -- 7247
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=7245; -- 7245
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=7935; -- 7935
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17712; -- 17712
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=7249; -- 7249
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=8143; -- 8143
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=9964; -- 9964
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=8538; -- 8538
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=7956; -- 7956
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=3375; -- 3375
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=4634; -- 4634
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=4396; -- 4396
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=4395; -- 4395
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=16051; -- 16051
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=16058; -- 16058
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=16057; -- 16057
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=16056; -- 16056
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=16094; -- 16094
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=820; -- 820
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=16089; -- 16089
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=14126; -- 14126
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=16072; -- 16072
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15978; -- 15978
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15979; -- 15979
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15970; -- 15970
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=824; -- 824
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15991; -- 15991
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15995; -- 15995
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15962; -- 15962
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15966; -- 15966
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=8802; -- 8802
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=5474; -- 5474
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=1793; -- 1793
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15317; -- 15317
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15528; -- 15528
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15541; -- 15541
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15535; -- 15535
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15525; -- 15525
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15536; -- 15536
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15501; -- 15501
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15289; -- 15289
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15293; -- 15293
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15205; -- 15205
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15303; -- 15303
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15331; -- 15331
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15330; -- 15330
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15329; -- 15329
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15328; -- 15328
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15327; -- 15327
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15288; -- 15288
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15593; -- 15593
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=16567; -- 16567
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15315; -- 15315
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17348; -- 17348
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17278; -- 17278
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17280; -- 17280
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17279; -- 17279
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17319; -- 17319
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17328; -- 17328
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17275; -- 17275
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=21220; -- 21220
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=16812; -- 16812
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17221; -- 17221
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15981; -- 15981
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=16004; -- 16004
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15898; -- 15898
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15915; -- 15915
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=17214; -- 17214
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15932; -- 15932
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15918; -- 15918
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15887; -- 15887
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15867; -- 15867
UPDATE `npc_text` SET `VerifiedBuild`=25996 WHERE `ID`=15893; -- 15893
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=10062; -- 10062
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=1471; -- 1471
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9124; -- 9124
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=1934; -- 1934
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=2954; -- 2954
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=5177; -- 5177
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=5798; -- 5798
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=2138; -- 2138
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8335; -- 8335
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7251; -- 7251
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=3566; -- 3566
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8539; -- 8539
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9964; -- 9964
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=17749; -- 17749
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7902; -- 7902
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15883; -- 15883
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15394; -- 15394
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=16644; -- 16644
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15504; -- 15504
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9978; -- 9978
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9414; -- 9414
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9954; -- 9954
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9953; -- 9953
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9951; -- 9951
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=10237; -- 10237
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7742; -- 7742
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=16688; -- 16688
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15466; -- 15466
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=1759; -- 1759
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=1758; -- 1758
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15911; -- 15911
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15561; -- 15561
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15444; -- 15444
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15532; -- 15532
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=16424; -- 16424
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15385; -- 15385
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15559; -- 15559
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=17789; -- 17789
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7935; -- 7935
UPDATE `page_text` SET `VerifiedBuild`=26124 WHERE `ID`=3601; -- 3601
UPDATE `page_text` SET `VerifiedBuild`=26124 WHERE `ID`=3600; -- 3600
UPDATE `page_text` SET `VerifiedBuild`=26124 WHERE `ID`=3599; -- 3599
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7778; -- 7778
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15345; -- 15345
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15349; -- 15349
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15350; -- 15350
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15351; -- 15351
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15348; -- 15348
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15376; -- 15376
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15375; -- 15375
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15374; -- 15374
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15373; -- 15373
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15372; -- 15372
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15371; -- 15371
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15370; -- 15370
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15346; -- 15346
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=2812; -- 2812
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15639; -- 15639
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15324; -- 15324
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15325; -- 15325
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=2734; -- 2734
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=2813; -- 2813
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=3094; -- 3094
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15294; -- 15294
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15333; -- 15333
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15332; -- 15332
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15291; -- 15291
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15270; -- 15270
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15269; -- 15269
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15268; -- 15268
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15267; -- 15267
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15266; -- 15266
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15278; -- 15278
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15277; -- 15277
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=11714; -- 11714
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=2817; -- 2817
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=17736; -- 17736
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=3546; -- 3546
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=3096; -- 3096
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=3095; -- 3095
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9774; -- 9774
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=2821; -- 2821
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=2811; -- 2811
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=2810; -- 2810
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=15353; -- 15353
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=2816; -- 2816
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=1250; -- 1250
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=1238; -- 1238
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7017; -- 7017
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=1234; -- 1234
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=5561; -- 5561
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7817; -- 7817
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7748; -- 7748
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7770; -- 7770
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8065; -- 8065
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7768; -- 7768
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7767; -- 7767
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7766; -- 7766
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7765; -- 7765
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7764; -- 7764
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7763; -- 7763
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7762; -- 7762
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7761; -- 7761
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7760; -- 7760
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7759; -- 7759
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7758; -- 7758
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7757; -- 7757
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7756; -- 7756
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7755; -- 7755
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7752; -- 7752
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7736; -- 7736
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7735; -- 7735
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7816; -- 7816
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8212; -- 8212
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7874; -- 7874
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=6870; -- 6870
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=6869; -- 6869
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=6868; -- 6868
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=6867; -- 6867
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=6844; -- 6844
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=6843; -- 6843
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=6842; -- 6842
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=6812; -- 6812
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7732; -- 7732
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7728; -- 7728
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7839; -- 7839
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7779; -- 7779
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7734; -- 7734
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7731; -- 7731
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7730; -- 7730
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8114; -- 8114
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7753; -- 7753
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8280; -- 8280
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7727; -- 7727
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7729; -- 7729
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8960; -- 8960
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7782; -- 7782
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7733; -- 7733
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7804; -- 7804
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7803; -- 7803
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7802; -- 7802
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7801; -- 7801
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=6155; -- 6155
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=10239; -- 10239
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9194; -- 9194
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8869; -- 8869
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8865; -- 8865
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8868; -- 8868
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8863; -- 8863
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8978; -- 8978
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=10652; -- 10652
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8849; -- 8849
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8864; -- 8864
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8861; -- 8861
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8867; -- 8867
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8990; -- 8990
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8997; -- 8997
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8996; -- 8996
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8993; -- 8993
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8994; -- 8994
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8991; -- 8991
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8992; -- 8992
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8973; -- 8973
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8972; -- 8972
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8806; -- 8806
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9384; -- 9384
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=1853; -- 1853
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8840; -- 8840
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8844; -- 8844
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=7026; -- 7026
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8838; -- 8838
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=17138; -- 17138
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=17137; -- 17137
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=17136; -- 17136
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=17135; -- 17135
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=17134; -- 17134
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=17133; -- 17133
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=17132; -- 17132
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=17131; -- 17131
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=17127; -- 17127
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=17130; -- 17130
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=17129; -- 17129
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=17128; -- 17128
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=17126; -- 17126
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=17125; -- 17125
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=20326; -- 20326
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8823; -- 8823
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=5839; -- 5839
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8793; -- 8793
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8662; -- 8662
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8825; -- 8825
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8776; -- 8776
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8780; -- 8780
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8616; -- 8616
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8775; -- 8775
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8768; -- 8768
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=10008; -- 10008
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=10012; -- 10012
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9052; -- 9052
UPDATE `page_text` SET `VerifiedBuild`=26124 WHERE `ID`=2939; -- 2939
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=538; -- 538
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9107; -- 9107
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9076; -- 9076
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9097; -- 9097
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9163; -- 9163
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9045; -- 9045
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9123; -- 9123
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9591; -- 9591
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9143; -- 9143
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9142; -- 9142
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=10352; -- 10352
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9060; -- 9060
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9059; -- 9059
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9058; -- 9058
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9057; -- 9057
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9056; -- 9056
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9054; -- 9054
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9032; -- 9032
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9031; -- 9031
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9030; -- 9030
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9028; -- 9028
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9141; -- 9141
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9140; -- 9140
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9139; -- 9139
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9138; -- 9138
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9137; -- 9137
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9136; -- 9136
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9145; -- 9145
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9162; -- 9162
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9033; -- 9033
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9082; -- 9082
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9081; -- 9081
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9080; -- 9080
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9079; -- 9079
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9022; -- 9022
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9134; -- 9134
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8589; -- 8589
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8588; -- 8588
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9029; -- 9029
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9586; -- 9586
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9044; -- 9044
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9077; -- 9077
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9117; -- 9117
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9025; -- 9025
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9584; -- 9584
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9036; -- 9036
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9246; -- 9246
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9206; -- 9206
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9042; -- 9042
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8592; -- 8592
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8785; -- 8785
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8584; -- 8584
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9034; -- 9034
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=13584; -- 13584
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=8586; -- 8586
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9043; -- 9043
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9051; -- 9051
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9038; -- 9038
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9040; -- 9040
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9039; -- 9039
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=10258; -- 10258
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9041; -- 9041
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=9037; -- 9037

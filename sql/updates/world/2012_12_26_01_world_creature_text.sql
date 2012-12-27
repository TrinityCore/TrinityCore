-- NPC talk text convert from creature_ai_text
DELETE FROM `creature_ai_texts` WHERE entry BETWEEN -21 AND -17;
DELETE FROM `creature_text` WHERE `entry` IN (17975);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(17975,0,0, 'What are you doing? These specimens are very delicate!',14,0,100,0,0,11144, 'High Botanist Freywinn - Aggro Say'),
(17975,1,0, 'Your lifecycle is now concluded!',14,0,100,0,0,11145, 'High Botanist Freywinn - Kill Plant as Bloodelf Say'),
(17975,1,1, 'You will feed the worms.',14,0,100,0,0,11146, 'High Botanist Freywinn - Shapeshifting Say'),
(17975,2,0, 'Endorel aluminor!',14,0,100,0,0,11147, 'High Botanist Freywinn - Shapeshifting Say'),
(17975,3,0, 'Nature bends to my will!',14,0,100,0,0,11148, 'High Botanist Freywinn - Summoning Plants Say'),
(17975,4,0, 'The specimens... must be... preserved.',14,0,100,0,0,11149, 'High Botanist Freywinn - Death Say'),
(17975,5,0, '...thorny vines...mumble...ouch!',12,0,100,0,0,0, 'High Botanist Freywinn - OOC Random Say'),
(17975,5,1, '...mumble mumble...',12,0,100,0,0,0, 'High Botanist Freywinn - OOC Random Say'),
(17975,5,2, '...mumble...Petals of Fire...mumble...',12,0,100,0,0,0, 'High Botanist Freywinn - OOC Random Say'),
(17975,5,3, '...with the right mixture, perhaps...',12,0,100,0,0,0, 'High Botanist Freywinn - OOC Random Say');

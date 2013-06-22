-- Add texts for Alchemist Finklestein
DELETE FROM `creature_text` WHERE `entry`=28205;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
-- Events 1,2,3
(28205,0,0,'Quickly, get me some...',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,0,1,'I think it needs...',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,0,2,'Find me some...',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,0,3,'It simply must have some...',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,0,4,'We need some...',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,0,5,'It simply must have some...',42,0,100,0,0,0,'Alchemist Finklestein'),
-- Event 4
(28205,1,0,'I think it''s time for...',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,1,1,'Next, we''ll need...',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,1,2,'Tastes like it needs more....',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,1,3,'Alright, now find me some...',42,0,100,0,0,0,'Alchemist Finklestein'),
-- Event 5
(28205,2,0,'Coming along nicely, but still needs...',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,2,1,'Before it thickens, we must add...',42,0,100,0,0,0,'Alchemist Finklestein'),
-- Event 6
(28205,3,0,'Before it boils over, I need...',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,3,1,'It''s thickening! Quickly, get some...',42,0,100,0,0,0,'Alchemist Finklestein'),
-- Fail
(28205,4,0,'You''re too late. I must start again from the beginning....',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,4,1,'No! The serum is ruined!',42,0,100,0,0,0,'Alchemist Finklestein'),
-- Item request
(28205,5,0,'Knotroot!',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,6,0,'Pickled Eagle Egg!',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,7,0,'Speckled Guano!',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,8,0,'Withered Batwing!',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,9,0,'Seasoned Slider Cider!',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,10,0,'Pulverized Gargoyle Teeth!',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,11,0,'Muddy Mire Maggot!',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,12,0,'Spiky Spider Egg!',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,13,0,'Hairy Herring Head!',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,14,0,'Putrid Pirate Perspiration!',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,15,0,'Icecrown Bottled Water!',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,16,0,'Wasp''s Wings!',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,17,0,'Prismatic Mojo!',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,18,0,'Raptor Claw!',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,19,0,'Amberseed!',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,20,0,'Shrunken Dragon''s Claw!',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,21,0,'Chilled Serpent Mucus!',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,22,0,'Crystallized Hogsnot!',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,23,0,'Crushed Basilisk Crystals!',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,24,0,'Trollbane!',42,0,100,0,0,0,'Alchemist Finklestein'),
(28205,25,0,'Frozen Spider Ichor!',42,0,100,0,0,0,'Alchemist Finklestein');

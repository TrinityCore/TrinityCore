-- Remove old script text for boss_vanndar.cpp "Not sure if the text actually exist"
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1810018 AND -1810008;
-- Add new creature_text for Vanndar Stormpike
DELETE FROM `creature_text` WHERE `entry`=11948;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
-- Aggro
(11948,0,0, 'Soldiers of Stormpike, your General is under attack! I require aid! Come! Come! Slay these mangy Frostwolf dogs.',14,0,100,0,0,0, 'Vanndar Stormpike'),
-- Reset
(11948,1,0, 'You''ll never get me out of me bunker, heathens!',14,0,100,0,0,0, 'Vanndar Stormpike'),
(11948,1,1, 'Why don''t ya try again without yer cheap tactics, pansies! Or are you too chicken?',14,0,100,0,0,0, 'Vanndar Stormpike'),
-- Combat
(11948,2,0, 'I will tell you this much...Alterac Valley will be ours.',14,0,100,0,0,0, 'Vanndar Stormpike'),
(11948,2,1, 'Your attacks are weak! Go practice on some rabbits and come back when you''re stronger.',14,0,100,0,0,0, 'Vanndar Stormpike'),
(11948,2,2, 'We will not be swayed from our mission!',14,0,100,0,0,0, 'Vanndar Stormpike'),
(11948,2,3, 'It''ll take more than you rabble to bring me down!',14,0,100,0,0,0, 'Vanndar Stormpike'),
(11948,2,4, 'We, the Alliance, will prevail!',14,0,100,0,0,0, 'Vanndar Stormpike'),
(11948,2,5, 'The Stormpike clan bows to no one, especially the horde!',14,0,100,0,0,0, 'Vanndar Stormpike'),
(11948,2,6, 'Is that the best you can do?',14,0,100,0,0,0, 'Vanndar Stormpike'),
-- Said with a spell cast (Alliance players receive 10/20/30% damage/size increases, gained by turning in [Polished Armor Scraps]
(11948,3,0, 'Take no prisoners! Drive these heathens from our lands!',14,0,100,0,0,0, 'Vanndar Stormpike');

-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry`=39368;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(39368,0,0, 'All right, you twisted mess of broken gears, let''s get to work!',12,0,100,1,0,0, 'Drill Sergeant Steamcrank'),
(39368,1,0, 'I am going to teach you all what it takes to be a proper soldier!',12,0,100,5,0,0, 'Drill Sergeant Steamcrank'),
(39368,2,0, 'The first thing you need to learn is proper discipline.',12,0,100,1,0,0, 'Drill Sergeant Steamcrank'),
(39368,3,0, 'Show me that discipline with a proper salute when I say so!',12,0,100,5,0,0, 'Drill Sergeant Steamcrank'),
(39368,4,0, 'Okay, recruits, salute!',12,0,100,66,0,0, 'Drill Sergeant Steamcrank'),
(39368,5,0, 'Nice job!',12,0,100,273,0,0, 'Drill Sergeant Steamcrank'),
(39368,6,0, 'When you go into combat, it is important that you know how to intimidate the enemy with a deafening battle roar!',12,0,100,396,0,0, 'Drill Sergeant Steamcrank'),
(39368,7,0, 'When I give the signal,let loose your greatest roar!',12,0,100,1,0,0, 'Drill Sergeant Steamcrank'),
(39368,8,0, 'Let me hear that battle roar!',12,0,100,5,0,0, 'Drill Sergeant Steamcrank'),
(39368,9,0, 'Wow, nice and scary!',12,0,100,0,0,0, 'Drill Sergeant Steamcrank'),
(39368,10,0, 'Remember though, a key factor in winning any battle is positive reinforcement.',12,0,100,5,0,0, 'Drill Sergeant Steamcrank'),
(39368,11,0, 'Reward your fellow soldiers in battle with a resounding cheer.  Now, cheer at me when I tell you to!',12,0,100,1,0,0, 'Drill Sergeant Steamcrank'),
(39368,12,0, 'Everyone, cheer!',12,0,100,0,0,0, 'Drill Sergeant Steamcrank'),
(39368,13,0, 'Fantastic!',12,0,100,273,0,0, 'Drill Sergeant Steamcrank'),
(39368,14,0, 'However, the most important part of battle is how you celebrate a good hard earned victory!',12,0,100,396,0,0, 'Drill Sergeant Steamcrank'),
(39368,15,0, 'Show me your best victory dance when I give the signal!',12,0,100,5,0,0, 'Drill Sergeant Steamcrank'),
(39368,16,0, 'Now, dance!',12,0,100,0,0,0, 'Drill Sergeant Steamcrank'),
(39368,17,0, 'Superb!',12,0,100,273,0,0, 'Drill Sergeant Steamcrank'),
(39368,18,0, 'You might be the best set of recruits I''ve ever seen!  Let''s go through all of that again!',12,0,100,396,0,0, 'Drill Sergeant Steamcrank');

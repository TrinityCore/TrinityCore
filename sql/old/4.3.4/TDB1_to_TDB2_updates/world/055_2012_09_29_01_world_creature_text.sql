-- Mimiron
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1603259 AND -1603240;
DELETE FROM `creature_text` WHERE `entry`=33350;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(33350,0,0, 'Oh, my! I wasn''t expecting company! The workshop is such a mess! How embarrassing!',14,0,100,0,0,15611, 'Mimiron SAY_AGGRO'),
(33350,1,0, 'Now why would you go and do something like that? Didn''t you see the sign that said ''DO NOT PUSH THIS BUTTON!''? How will we finish testing with the self-destruct mechanism active?',14,0,100,0,0,15629, 'Mimiron SAY_HARDMODE_ON'),
(33350,2,0, 'We haven''t much time, friends! You''re going to help me test out my latest and greatest creation. Now, before you change your minds, remember, that you kind of owe it to me after the mess you made with the XT-002.',14,0,100,0,0,15612, 'Mimiron SAY_MKII_ACTIVATE'),
(33350,3,0, 'MEDIC!',14,0,100,0,0,15613, 'Mimiron SAY_MKII_SLAY_1'),
(33350,3,1, 'I can fix that... or, maybe not! Sheesh, what a mess...',14,0,100,0,0,15614, 'Mimiron SAY_MKII_SLAY_2'),
(33350,4,0, 'WONDERFUL! Positively marvelous results! Hull integrity at 98.9 percent! Barely a dent! Moving right along.',14,0,100,0,0,15615, 'Mimiron SAY_MKII_DEATH'),
(33350,5,0, 'Behold the VX-001 Anti-personnel Assault Cannon! You might want to take cover.',14,0,100,0,0,15616, 'Mimiron SAY_VX001_ACTIVATE'),
(33350,6,0, 'Fascinating. I think they call that a "clean kill".',14,0,100,0,0,15617, 'Mimiron SAY_VX001_SLAY_1'),
(33350,6,1, 'Note to self: Cannon highly effective against flesh.',14,0,100,0,0,15618, 'Mimiron SAY_VX001_SLAY_2'),
(33350,7,0, 'Thank you, friends! Your efforts have yielded some fantastic data! Now, where did I put- oh, there it is!',14,0,100,0,0,15619, 'Mimiron SAY_VX001_DEATH'),
(33350,8,0, 'Isn''t it beautiful? I call it the magnificent aerial command unit!',14,0,100,0,0,15620, 'Mimiron SAY_AERIAL_ACTIVATE'),
(33350,9,0, 'Outplayed!',14,0,100,0,0,15621, 'Mimiron SAY_AERIAL_SLAY_1'),
(33350,9,1, 'You can do better than that!',14,0,100,0,0,15622, 'Mimiron SAY_AERIAL_SLAY_2'),
(33350,10,0, 'Preliminary testing phase complete. Now comes the true test!!',14,0,100,0,0,15623, 'Mimiron SAY_AERIAL_DEATH'),
(33350,11,0, 'Gaze upon its magnificence! Bask in its glorious, um, glory! I present you... V-07-TR-0N!',14,0,100,0,0,15624, 'Mimiron SAY_V07TRON_ACTIVATE'),
(33350,12,0, 'Prognosis: Negative!',14,0,100,0,0,15625, 'Mimiron SAY_V07TRON_SLAY_1'),
(33350,12,1, 'You''re not going to get up from that one, friend.',14,0,100,0,0,15626, 'Mimiron SAY_V07TRON_SLAY_2'),
(33350,13,0, 'It would appear that I''ve made a slight miscalculation. I allowed my mind to be corrupted by the fiend in the prison, overriding my primary directive. All systems seem to be functional now. Clear.',14,0,100,0,0,15627, 'Mimiron SAY_V07TRON_DEATH'),
(33350,14,0, 'Oh, my! It would seem that we are out of time, my friends!',14,0,100,0,0,15628, 'Mimiron SAY_BERSERK'),
(33350,15,0, 'Combat matrix enhanced. Behold wonderous rapidity!',14,0,100,0,0,15630, 'Mimiron SAY_YS_HELP');

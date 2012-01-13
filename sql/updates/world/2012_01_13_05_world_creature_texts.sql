-- Remove old script text for npc_warden_mellichar
DELETE FROM `script_texts` WHERE `entry` IN (-1552023, -1552030);

-- Add new creature_text for Warden Mellichar
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(20904, 0, 0, 'I knew the prince would be angry but, I... I have not been myself. I had to let them out! The great one speaks to me, you see. Wait--outsiders. Kael\'thas did not send you! Good... I\'ll just tell the prince you released the prisoners!', 0, 0, 100, 0, 0, 0, 'Warden Mellichar'),
(20904, 1, 0, 'The naaru kept some of the most dangerous beings in existence here in these cells. Let me introduce you to another...', 0, 0, 100, 0, 0, 0, 'Warden Mellichar'),
(20904, 2, 0, 'Yes, yes... another! Your will is mine!', 0, 0, 100, 0, 0, 0, 'Warden Mellichar'),
(20904, 3, 0, 'Behold another terrifying creature of incomprehensible power!', 0, 0, 100, 0, 0, 0, 'Warden Mellichar'),
(20904, 4, 0, 'What is this? A lowly gnome? I will do better, O\'great one.', 0, 0, 100, 0, 0, 0, 'Warden Mellichar'),
(20904, 5, 0, 'Anarchy! Bedlam! Oh, you are so wise! Yes, I see it now, of course!', 0, 0, 100, 0, 0, 0, 'Warden Mellichar'),
(20904, 6, 0, 'One final cell remains. Yes, O\'great one, right away!', 0, 0, 100, 0, 0, 0, 'Warden Mellichar'),
(20904, 7, 0, 'Welcome, O\'great one. I am your humble servant.', 0, 0, 100, 0, 0, 0, 'Warden Mellichar');


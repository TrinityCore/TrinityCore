DELETE FROM `creature_text` WHERE `entry` IN (26666,27221,27227);
DELETE FROM `creature_text` WHERE `entry` =26484 and `groupid`>1;

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(27227, 0, 0, 'Where... where am I?', 12, 0, 100, 0, 0, 0, 'Prospector Rokar',26240),
(27227, 1, 0, 'Wait a minute here! You promised to spare me if I helped you. I held up my end o'' the bargain!', 12, 0, 100, 5, 0, 0, 'Prospector Rokar',26874),
(27227, 2, 0, 'By the Light, Brann''s alive? I''d never help you capture him!', 12, 0, 100, 1, 0, 0, 'Prospector Rokar',26879),
(26666, 0, 0, 'Stay your blade, Chieftain. He may yet have value to us.', 12, 0, 100, 1, 0, 0, 'Scout Vor''takh',26875),
(26666, 1, 0, 'Remember the dwarven journal that was discovered? Well, this dwarf could be exactly what we need to track down Brann Bronzebeard and capture him.', 12, 0, 100, 1, 0, 0, 'Scout Vor''takh',26878),
(26666, 2, 0, 'You will if you wish to keep your head attached to your shoulders.', 12, 0, 100, 1, 0, 0, 'Scout Vor''takh',26880),
(26666, 3, 0, 'Does that satisfy you, Tormak?', 12, 0, 100, 6, 0, 0, 'Scout Vor''takh',26881),
(27221, 0, 0, 'Let''s see if this works.', 12, 0, 100, 1, 0, 0, 'Tormak the Scarred',26239),
(27221, 1, 0, 'You are among the Taunka of Camp Oneqwah, dwarf.', 12, 0, 100, 1, 0, 0, 'Tormak the Scarred',26251),
(27221, 2, 0, 'If you agree to help us against our mutual enemy, you will come to no harm here.', 12, 0, 100, 1, 0, 0, 'Tormak the Scarred',26252),
(27221, 3, 0, 'Think about it, prospector, but make up your mind swiftly. We must act soon.', 12, 0, 100, 25, 0, 0, 'Tormak the Scarred',26253),
(27221, 4, 0, 'I''ll admit, dwarf, I was pleasantly surprised to see your plan succeed.', 12, 0, 100, 1, 0, 0, 'Tormak the Scarred',26871),
(27221, 5, 0, 'We can''t just let you return to your companions and we can''t take you with us...', 12, 0, 100, 1, 0, 0, 'Tormak the Scarred',26873),
(27221, 6, 0, 'He will live so long as he proves useful. I''d be careful if I was you, dwarf.', 12, 0, 100, 273, 0, 0, 'Tormak the Scarred',26882),
(26484, 2, 0, 'By the Light, you killed Limpy Joe and took the meat! How did you know where to find us?', 12, 0, 100, 5, 0, 0, 'Hugh Glass',26639),
(26484, 3, 0, 'Well, if you''ve come to kill me, too, can you at least wait until I''ve fed Griselda? Poor girl hasn''t eaten in days.', 12, 0, 100, 20, 0, 0, 'Hugh Glass',26642),
(26484, 4, 0, 'Here, girl. I''ve got one last meal for you before Limpy Joe''s killer does us in!', 12, 0, 100, 22, 0, 0, 'Hugh Glass',26643),
(26484, 5, 0, 'How could you kill poor, defenseless old Joe? And why did you bring the meat back?', 12, 0, 100, 6, 0, 0, 'Hugh Glass',26645),
(26484, 6, 0, 'You''re an enigma, that''s what you are... And let me tell you, enigmas and I don''t get along....', 12, 0, 100, 1, 0, 0, 'Hugh Glass',26646),
(26484, 7, 0, 'I think you''d best leave before Griselda decides she''s in the mood for dessert.', 12, 0, 100, 25, 0, 0, 'Hugh Glass',26647),
(26484, 8, 0, 'Wake up, Griselda. Here, girl.', 12, 0, 100, 0, 0, 0, 'Hugh Glass',25700),
(26484, 9, 0, 'They''ll never find us here, will they? We won''t let them get us like they got Limpy Joe and Flannel McGee!', 12, 0, 100, 5, 0, 0, 'Hugh Glass',25701),
(26484, 9, 1, 'No, we escaped from those monsters! They''re nothing like us, Griselda.', 12, 0, 100, 1, 0, 0, 'Hugh Glass',25702),
(26484, 9, 2, 'We''re hunters, you and I. No wolfmen here, no ma''am.', 12, 0, 100, 274, 0, 0, 'Hugh Glass',25703),
(26484, 9, 3, 'Keep an eye out for them, girl! Don''t let them get us!', 12, 0, 100, 25, 0, 0, 'Hugh Glass',25704);

UPDATE `creature_text` SET `emote`=396 WHERE  `entry`=26604;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (26666,27221);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26666,27221) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` =26484 AND `source_type`=0 and `id`IN(1,2);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2722100,2722101,2648401) AND `source_type`=9;
UPDATE `smart_scripts` SET `event_type`=20, `event_param1`=12484, `event_param2`=0, `event_param3`=0, `event_param4`=0, `comment`='Mack Fearsen - On Quest Complete (Scourgekabob)  - Say Line 0' WHERE  `entryorguid`=26604 AND `source_type`=0 AND `id`=2 AND `link`=0;

INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27221, 0, 0, 0, 20, 0, 100, 0, 12195, 0, 0, 0, 80, 2722100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tormak the Scarred - On Quest Reward (The Unexpected Guest) - Run Script'),
(27221, 0, 1, 0, 20, 0, 100, 0, 12199, 0, 0, 0, 80, 2722101, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tormak the Scarred - On Quest Reward (Bringing Down The Iron Thane) - Run Script 2'),
(26666, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 53, 0, 26666, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scout Vor''takh - On Data Set 1 1 - Start WP'),
(26666, 0, 1, 0, 40, 0, 100, 0, 6, 26666, 0, 0, 54, 32000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scout Vor''takh - On On reached wp6 - Pause WP'),
(26666, 0, 2, 0, 40, 0, 100, 0, 7, 26666, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.55531, 'Scout Vor''takh - On On reached wp7 - Set Orientation'),
(26484, 0, 1, 0, 20, 0, 100, 0, 12279, 0, 0, 0, 80, 2648401, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hugh Glass - On Quest reward (A Bear of an Appetite) - Run Script'),
(26484, 0, 2, 0, 1, 0, 100, 0, 15000, 60000, 90000, 120000, 1, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hugh Glass - OOC - Say'),
(2722100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 27227, 0, 0, 0, 0, 0, 0, 'Tormak the Scarred - Script - Set Orientation'),
(2722100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tormak the Scarred - Script - Set NPC Flags'),
(2722100, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tormak the Scarred - Script - Say Line 1'),
(2722100, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 27227, 0, 0, 0, 0, 0, 0, 'Tormak the Scarred - Script - Say Line 1 on Prospector Rokar'),
(2722100, 9, 4, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tormak the Scarred - Script - Say Line 2'),
(2722100, 9, 5, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tormak the Scarred - Script - Say Line 3'),
(2722100, 9, 6, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tormak the Scarred - Script - Say Line 4'),
(2722100, 9, 7, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 81, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tormak the Scarred - Script - Set NPC Flags'),
(2722100, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.80998, 'Tormak the Scarred - Script - Set Orientation'),
(2722101, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 27227, 0, 0, 0, 0, 0, 0, 'Tormak the Scarred - Script 2 - Set Orientation'),
(2722101, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tormak the Scarred - Script 2 - Set NPC Flags'),
(2722101, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tormak the Scarred - Script 2 - Say Line 5'),
(2722101, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tormak the Scarred - Script 2 - Say Line 6'),
(2722101, 9, 4, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 27227, 0, 0, 0, 0, 0, 0, 'Tormak the Scarred - Script 2 - Say Line 2 on Prospector Rokar'),
(2722101, 9, 5, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 26666, 0, 0, 0, 0, 0, 0, 'Tormak the Scarred - Script 2 - Set Data 1 1 on Scout Vor''takh'),
(2722101, 9, 6, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 26666, 0, 0, 0, 0, 0, 0, 'Tormak the Scarred - Script - Say Line 1 on Scout Vor''takh'),
(2722101, 9, 7, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 26666, 0, 0, 0, 0, 0, 0, 'Tormak the Scarred - Script - Say Line 2 on Scout Vor''takh'),
(2722101, 9, 8, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 27227, 0, 0, 0, 0, 0, 0, 'Tormak the Scarred - Script 2 - Say Line 3 on Prospector Rokar'),
(2722101, 9, 9, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 26666, 0, 0, 0, 0, 0, 0, 'Tormak the Scarred - Script - Say Line 3 on Scout Vor''takh'),
(2722101, 9, 10, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 26666, 0, 0, 0, 0, 0, 0, 'Tormak the Scarred - Script 2 - Say Line 3 on Scout Vor''takh'),
(2722101, 9, 11, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tormak the Scarred - Script 2 - Say Line 7'),
(2722101, 9, 12, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 81, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tormak the Scarred - Script 2 - Set NPC Flags'),
(2722101, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.80998, 'Tormak the Scarred - Script 2 - Set Orientation'),
(2648401, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hugh Glass - Script 2 - Set NPC Flags'),
(2648401, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hugh Glass - Script 2 - Say Line 3'),
(2648401, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hugh Glass - Script 2 - Say Line 4'),
(2648401, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hugh Glass - Script 2 - Say Line 4'),
(2648401, 9, 4, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hugh Glass - Script 2 - Say Line 4'),
(2648401, 9, 5, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hugh Glass - Script 2 - Say Line 4'),
(2648401, 9, 6, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hugh Glass - Script 2 - Say Line 4'),
(2648401, 9, 7, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hugh Glass - Script 2 - Say Line 4'),
(2648401, 9, 8, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 81, 643, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hugh Glass - Script 2 - Set NPC Flags');

DELETE FROM `waypoints` WHERE `entry` =26666;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(26666, 1,3849.295, -4532.052, 209.5975, 'Scout Vor''takh'),
(26666, 2,3850.295, -4531.552, 209.5975, 'Scout Vor''takh'),
(26666, 3,3851.545, -4530.302, 210.3475, 'Scout Vor''takh'),
(26666, 4,3851.795, -4530.052, 210.3475, 'Scout Vor''takh'),
(26666, 5,3853.545, -4529.802, 209.5975, 'Scout Vor''takh'),
(26666, 6,3855.295, -4529.802, 209.5975, 'Scout Vor''takh'),
(26666, 7,3848.19, -4531.66, 209.344, 'Scout Vor''takh');


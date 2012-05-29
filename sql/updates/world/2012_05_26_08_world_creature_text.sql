-- Creature_text for npc_eye_of_acherus
DELETE FROM `creature_text` WHERE `entry`=28511;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(28511,1,0, 'The eye of Acherus moves toward it\s target.',14,0,100,0,0,0, 'Q12641 - EMOTE_EYE_OF_ACHERUS_START'),
(28511,2,0, 'The eye of Acherus subject of your control.',14,0,100,0,0,0, 'Q12641 - EMOTE_EYE_OF_ACHERUS_END');
-- Gnomeregan/Blastmaster Emi Shortfuse's event
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1090028 AND -1090000;
DELETE FROM `creature_text` WHERE `entry` IN (7361,7998);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- Emi Shortfuse
(7998,0,0, 'With your help, I can evaluate these tunnels.',12,0,100,0,0,0, 'SAY_BLASTMASTER_0'),
(7998,1,0, 'Let''s see if we can find out where these Troggs are coming from... and put a stop to the invasion!',12,0,100,0,0,0, 'SAY_BLASTMASTER_1'),
(7998,2,0, 'Such devastation... what horrible mess...',12,0,100,0,0,0, 'SAY_BLASTMASTER_2'),
(7998,3,0, 'It''s quiet here...',12,0,100,0,0,0, 'SAY_BLASTMASTER_3'),
(7998,4,0, '...too quiet.',12,0,100,0,0,0, 'SAY_BLASTMASTER_4'),
(7998,5,0, 'Look! Over there at the tunnel wall!',12,0,100,0,0,0, 'SAY_BLASTMASTER_5'),
(7998,6,0, 'Trogg incrusion! Defend me while I blast the hole closed!',12,0,100,0,0,0, 'SAY_BLASTMASTER_6'),
(7998,7,0, 'I don''t think one charge is going to cut it. Keep fending them off!',12,0,100,0,0,0, 'SAY_BLASTMASTER_7'),
(7998,8,0, 'The charges are set. Get back before they blow!',12,0,100,0,0,0, 'SAY_BLASTMASTER_8'),
(7998,9,0, 'Incoming blast in 10 seconds!',14,0,100,0,0,0, 'SAY_BLASTMASTER_9'),
(7998,10,0, 'Incoming blast in 5 seconds. Clear the tunnel!',14,0,100,0,0,0, 'SAY_BLASTMASTER_10'),
(7998,11,0, 'FIRE IN THE HOLE!',14,0,100,0,0,0, 'SAY_BLASTMASTER_11'),
(7998,12,0, 'Well done! Without your help I would have never been able to thwart that wave of troggs.',12,0,100,0,0,0, 'SAY_BLASTMASTER_12'),
(7998,13,0, 'Did you hear something?',12,0,100,0,0,0, 'SAY_BLASTMASTER_13'),
(7998,14,0, 'I heard something over there.',12,0,100,0,0,0, 'SAY_BLASTMASTER_14'),
(7998,15,0, 'More troggs! Ward them off as I prepare the explosives!',12,0,100,0,0,0, 'SAY_BLASTMASTER_15'),
(7998,16,0, 'The final charge is set. Stand back!',12,0,100,0,0,0, 'SAY_BLASTMASTER_16'),
(7998,17,0, '10 seconds to blast! Stand back!!!',14,0,100,0,0,0, 'SAY_BLASTMASTER_17'),
(7998,18,0, '5 seconds until detonation!!',14,0,100,0,0,0, 'SAY_BLASTMASTER_18'),
(7998,19,0, 'Superb! Because of your help, my people stand a chance of re-taking our belowed city. Three cheers to you!',12,0,100,0,0,0, 'SAY_BLASTMASTER_19'),
-- Grubbis
(7361,0,0, 'We come from below! You can never stop us!',14,0,100,0,0,0, 'SAY_GRUBBIS');

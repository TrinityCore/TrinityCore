-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry`=30452 AND `groupid` IN (6,7);
DELETE FROM `creature_text` WHERE `entry`=30449 AND `groupid` IN (6,7);
DELETE FROM `creature_text` WHERE `entry`=30451 AND `groupid` IN (6,7);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(30452,6,0, '%s begins to open a Twilight Portal!',41,0,100,0,0,0, 'Tenebron WHISPER_OPEN_PORTAL'),
(30452,7,0, 'Tenebron begins to hatch eggs in the Twilight!',41,0,100,0,0,0, 'Tenebron WHISPER_OPENED_PORTAL'),
(30449,6,0, '%s begins to open a Twilight Portal!',41,0,100,0,0,0, 'Vesperon WHISPER_OPEN_PORTAL'),
(30449,7,0, 'A Vesperon Disciple appears in the Twilight!',41,0,100,0,0,0, 'Vesperon - WHISPER_OPENED_PORTAL'),
(30451,6,0, '%s begins to open a Twilight Portal!',41,0,100,0,0,0, 'Shadron WHISPER_OPEN_PORTAL'),
(30451,7,0, 'A Shadron Disciple appears in the Twilight!',41,0,100,0,0,0, 'Shadron - WHISPER_OPENED_PORTAL');

UPDATE `creature_text` SET `text`= 'Right. Let''s see if we can finish this keystone.' WHERE `entry`=31810 AND `groupid`=0;
UPDATE `creature_text` SET `text`= 'We... are superior! How could this... be?' WHERE `entry`=30451 AND `groupid`=2;
UPDATE `creature_text` SET `text`= 'You have no place here! Your place... is among the departed!' WHERE `entry`=30452 AND `groupid`=2;
UPDATE `creature_text` SET `text`= 'To darkness I condemn you.' WHERE `entry`=30452 AND `groupid`=3;
UPDATE `creature_text` SET `text`= 'Tenebron begins to hatch eggs in the Twilight!' WHERE `entry`=30452 AND `groupid`=6;
UPDATE `creature_text` SET `text`= 'I am no mere dragon. You will find that I am much, much more.' WHERE `entry`=30452 AND `groupid`=5 AND `id`=1;
UPDATE `creature_text` SET `text`= 'You pose no threat, lesser beings! Give me your worst!' WHERE `entry`=30449 AND `groupid`=6;
UPDATE `creature_text` SET `text`= 'I still have some... fight... in me-e-e...' WHERE `entry`=30449 AND `groupid`=2;
UPDATE `creature_text` SET `text`= 'Such is the price... of failure....' WHERE `entry`=28860 AND `groupid`=6;
UPDATE `creature_text` SET `text`= 'I should not... have held back...' WHERE `entry`=30452 AND `groupid`=2;

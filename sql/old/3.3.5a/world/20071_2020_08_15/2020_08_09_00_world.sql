--
UPDATE `creature_text` SET `comment` = "Sophie Aaren" WHERE `CreatureID` = 31021;
UPDATE `creature_text` SET `comment` = "The Lich King" WHERE `CreatureID` = 31301;
UPDATE `creature_text` SET `comment` = "Margrave Dhakar" WHERE `CreatureID` = 31306;
UPDATE `creature_text` SET `comment` = "Alexstrasza the Life-Binder" WHERE `CreatureID` = 32295;

-- http://web.archive.org/web/20120114020841/http://www.wowhead.com/npc=31091
-- Commander Dardosh uses Alliance version of text with Common language
UPDATE `creature_text` SET `Text` = "Slay them all, $n!", `Language` = 1, `BroadcastTextId` = 33109 WHERE `CreatureID` = 31091 AND `GroupID` = 3 AND `ID` = 0;

UPDATE `creature_text` SET `Language` = 1, `BroadcastTextId` = 32232 WHERE `CreatureID` = 31427 AND `GroupID` = 0 AND `ID` = 0;
UPDATE `creature_text` SET `Language` = 1, `BroadcastTextId` = 32238 WHERE `CreatureID` = 31427 AND `GroupID` = 1 AND `ID` = 0;
UPDATE `creature_text` SET `BroadcastTextId` = 32912 WHERE `CreatureID` = 32588 AND `GroupID` = 0 AND `ID` = 0;
UPDATE `creature_text` SET `BroadcastTextId` = 34316 WHERE `CreatureID` = 32857 AND `GroupID` = 1 AND `ID` = 1;
UPDATE `creature_text` SET `BroadcastTextId` = 34240 WHERE `CreatureID` = 32865 AND `GroupID` = 4 AND `ID` = 1;
UPDATE `creature_text` SET `BroadcastTextId` = 34326 WHERE `CreatureID` = 32867 AND `GroupID` = 4 AND `ID` = 0;
UPDATE `creature_text` SET `BroadcastTextId` = 34106 WHERE `CreatureID` = 32906 AND `GroupID` = 2 AND `ID` = 0;

DELETE FROM `creature_text` WHERE `CreatureID` IN (31033,31254,32149,32236,32451,32638,32639);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
-- http://web.archive.org/web/20120319210644/http://www.wowhead.com/npc=31033
-- Moved emote at bottom because it seems incorrect or language must be set to 0
(31033,0,0,"We couldn't have done it without you, $g sir:ma'am;.",12,0,100,66,0,0,31384,0,"Crusader of Virtue"),
(31033,0,1,"There goes the hero of the Vanguard!",12,0,100,66,0,0,31385,0,"Crusader of Virtue"),
(31033,0,2,"You honor us with your presence, $n.",12,0,100,66,0,0,31386,0,"Crusader of Virtue"),
(31033,0,3,"With your steadfast determination, we cannot fail!",12,0,100,66,0,0,31387,0,"Crusader of Virtue"),
(31033,0,4,"Thank you, $n. From the bottom of my heart. Thank you.",12,0,100,66,0,0,31388,0,"Crusader of Virtue"),
(31033,0,5,"Call on me anytime, $n.",12,0,100,66,0,0,31389,0,"Crusader of Virtue"),
(31033,0,6,"We will battle along side you until the bitter end, $g sir:ma'am;!",12,0,100,66,0,0,31390,0,"Crusader of Virtue"),
(31033,0,7,"Hero, I am honored.",12,0,100,66,0,0,31391,0,"Crusader of Virtue"),
(31033,0,8,"%s cheers at you.",12,1,100,71,0,0,25275,0,"Crusader of Virtue"),
-- http://web.archive.org/web/20140815000000*/www.wowhead.com/npc=31254
(31254,0,0,"Has Prince Arthas turned against us?",12,0,10,0,0,0,32025,0,"Lordaeron Footsoldier"),
(31254,0,1,"Stand your ground, men!",12,0,10,0,0,0,32026,0,"Lordaeron Footsoldier"),
(31254,0,2,"The undead are upon us!",12,0,10,0,0,0,32027,0,"Lordaeron Footsoldier"),
(31254,0,3,"We make our stand here!",12,0,10,0,0,0,32028,0,"Lordaeron Footsoldier"),
(31254,0,4,"The rumors were true!  The prince has gone mad!",12,0,10,0,0,0,32029,0,"Lordaeron Footsoldier"),
-- Reordering
(32149,0,0,"At last... now I can rest.",12,0,100,1,0,0,35291,0,"Fallen Hero's Spirit"),
(32149,0,1,"My nightmare, is it finally over?",12,0,100,1,0,0,35292,0,"Fallen Hero's Spirit"),
(32149,0,2,"It was awful... I dreamt I was fighting against my friends.",12,0,100,1,0,0,35293,0,"Fallen Hero's Spirit"),
(32149,0,3,"I can't hear the screams anymore. Is this the end?",12,0,100,1,0,0,35294,0,"Fallen Hero's Spirit"),
(32149,0,4,"I'm so tired. Just let me rest for a moment.",12,0,100,1,0,0,35295,0,"Fallen Hero's Spirit"),
-- http://web.archive.org/web/20130728102135/www.wowhead.com/npc=32236
(32236,0,0,"What?!",12,0,100,0,0,0,32630,0,"Dark Subjugator"),
(32236,0,1,"Wait a minute, I didn't activate my...?",12,0,100,0,0,0,32631,0,"Dark Subjugator"),
(32236,0,2,"I feel funny all of a sudden.  Er?!",12,0,100,0,0,0,32632,0,"Dark Subjugator"),
(32236,0,3,"Okay, who's the joker that threw an orb at me?",12,0,100,0,0,0,32633,0,"Dark Subjugator"),
(32236,1,0,"NOOOOOO!",12,0,100,0,0,0,32634,0,"Dark Subjugator"),
(32236,1,1,"Not a sentry!",12,0,100,0,0,0,32635,0,"Dark Subjugator"),
(32236,1,2,"You've got it all wrong. I'm a subjugator!",12,0,100,0,0,0,32636,0,"Dark Subjugator"),
(32236,1,3,"It was an accident. I was framed. Don't drop me!",12,0,100,0,0,0,32637,0,"Dark Subjugator"),
-- Reordering
(32451,0,0,"Sometimes it's nice to get away from the sanctum and get some fresh air.",12,0,100,1,0,0,33067,0,"Dalaran Citizen"),
(32451,0,1,"Luckily, the Lich King's grasp has not reached Dalaran yet.",12,0,100,1,0,0,33068,0,"Dalaran Citizen"),
(32451,0,2,"She said to meet her right here... maybe I'm in the wrong place?",12,0,100,1,0,0,33069,0,"Dalaran Citizen"),
-- Reordering
(32638,0,0,"Thanks, buddy! Thanks for nothing!",12,0,100,0,0,0,33014,0,"Hakmud of Argus"),
(32638,0,1,"Why do you treat Hakmud like this, buddy?",12,0,100,0,0,0,33015,0,"Hakmud of Argus"),
(32638,0,2,"What is Hakmud supposed to do now, buddy?",12,0,100,0,0,0,33016,0,"Hakmud of Argus"),
(32638,0,3,"Hakmud cannot work under these conditions! Goodbye!",12,0,100,0,0,0,33017,0,"Hakmud of Argus"),
(32638,0,4,"I thought we were friend, buddy! You leave Hakmud stranded?",12,0,100,0,0,0,33018,0,"Hakmud of Argus"),
-- Reordering
(32639,0,0,"Nobody loves Gnimo...",12,0,100,0,0,0,33019,0,"Gnimo"),
(32639,0,1,"Goodbye! You were Gnimo's best friend ever!",12,0,100,0,0,0,33020,0,"Gnimo"),
(32639,0,2,"Time for Gnimo to shut down.",12,0,100,0,0,0,33021,0,"Gnimo");

-- Remove recently added mismatches
UPDATE `creature_text` a LEFT JOIN `broadcast_text` b ON a.`BroadcastTextId` = b.`ID` SET a.`Text` = b.`Text` WHERE b.`Text1` = '' AND a.`Text` != b.`Text`;

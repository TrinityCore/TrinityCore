--
DELETE FROM `creature_text` WHERE `CreatureID` = 23035;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23035,0,0,"No! How can this be?",14,0,100,0,0,0,20797,0,"Anzu SAY_INTRO_1"),
(23035,1,0,"Pain will be the price for your insolence! You cannot stop me from claiming the Emerald Dream as my own!",14,0,100,0,0,0,20799,0,"Anzu SAY_INTRO_2"),
(23035,2,0,"Awaken, my children and assist your master!",14,0,100,0,0,0,20991,0,"Anzu SAY_SUMMON"),
(23035,3,0,"Yes... cast your precious little spells, ak-a-ak!",15,0,100,0,0,0,21012,0,"Anzu SAY_BOMB"),
(23035,3,1,"Your magics shall be your undoing... ak-a-ak...",15,0,100,0,0,0,21015,0,"Anzu SAY_BOMB"),
(23035,3,2,"Your powers... ak-ak... turn against you...",15,0,100,0,0,0,21016,0,"Anzu SAY_BOMB"),
(23035,3,3,"Your spells... ke-kaw... are weak magics... easy to turn against you...",15,0,100,0,0,0,21017,0,"Anzu SAY_BOMB");

-- 3.3.5 only
UPDATE `creature_template` SET `unit_flags` = `unit_flags` |512|256 WHERE `entry` = 23035;

-- Ignore pathfinding, otherwise creatures will be not engaged and remain in the sky
UPDATE `creature_template` SET `flags_extra` = `flags_extra` |0x20000000 WHERE `entry` = 23132;

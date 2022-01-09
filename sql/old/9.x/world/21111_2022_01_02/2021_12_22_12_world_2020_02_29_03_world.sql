-- 
DELETE FROM `creature_text` WHERE `CreatureID` IN (24321,24322,24323);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(24321, 0, 0, "%s motions for silence.", 41, 0, 100, 397, 0, 0, 23130, 0, "King Ymiron emote"),
(24321, 1, 0, "Vrykul, your king implores you to listen!", 14, 0, 100, 22, 0, 0, 23134, 0, "King Ymiron yell"),
(24321, 2, 0, "The gods have abandoned us!", 14, 0, 100, 1, 0, 0, 23135, 0, "King Ymiron yell"),
(24321, 3, 0, "The crowd gasps in horror.", 16, 0, 100, 53, 0, 0, 23136, 0, "King Ymiron emote"),
(24321, 4, 0, "Even now, in our darkest hour, they mock us!", 14, 0, 100, 22, 0, 0, 23137, 0, "King Ymiron yell"),
(24321, 5, 0, "Where are the titans in our time of greatest need? Our women birth abberations - disfigured runts unable to even stand on their own! Weak and ugly... Useless...", 14, 0, 100, 22, 0, 0, 23138, 0, "King Ymiron yell"),
(24321, 6, 0, "Ymiron has toiled. Long have I sat upon my throne and thought hard of our plight. There is only one answer... one reason...", 14, 0, 100, 22, 0, 0, 23139, 0, "King Ymiron yell"),
(24321, 7, 0, "For who but the titans themselves could bestow such a curse? What could have such power?", 14, 0, 100, 1, 0, 0, 23140, 0, "King Ymiron yell"),
(24321, 8, 0, "And the answer is nothing... For it is the titans that have cursed us!", 14, 0, 100, 53, 0, 0, 23141, 0, "King Ymiron yell"),
(24321, 9, 0, "The crowd clamours.", 16, 0, 100, 0, 0, 0, 23142, 0, "King Ymiron"),
(24321, 10, 0, "On this day all Vrykul will shed their old beliefs! We denounce our old gods! All Vrykul will pledge their allegiance to Ymiron! Ymiron will protect our noble race!", 14, 0, 100, 53, 0, 0, 23143, 0, "King Ymiron yell"),
(24321, 11, 0, "The crowd cheers.", 16, 0, 100, 0, 0, 0, 23144, 0, "King Ymiron"),
(24321, 12, 0, "And now my first decree upon the Vrykul! All malformed infants born of Vrykul mother and father are to be destroyed upon birth! Our blood must remain pure always! Those found in violation of Ymiron's decree will be taken to Gjalerbron for execution!", 14, 0, 100, 1, 0, 0, 23145, 0, "King Ymiron yell"),
(24323, 0, 0, "The king is going to speak!", 12, 0, 100, 1, 0, 0, 23132, 0, "Ancient Citizen of Nifflevar"),
(24323, 1, 0, "Silence!", 12, 0, 100, 1, 0, 0, 23133, 0, "Ancient Citizen of Nifflevar"),
(24323, 2, 0, "Shhh!", 12, 0, 100, 1, 0, 0, 23131, 0, "Ancient Citizen of Nifflevar"),
(24323, 3, 0, "Let him speak! Be silent!", 12, 0, 100, 1, 0, 0, 23124, 0, "Ancient Citizen of Nifflevar"),
(24322, 4, 0, "Show them mercy, my king! They are of our flesh and blood!", 12, 0, 100, 53, 0, 0, 23128, 0, "Ancient Citizen of Nifflevar"),
(24322, 4, 1, "All hail our glorious king, Ymiron!", 12, 0, 100, 53, 0, 0, 23123, 0, "Ancient Citizen of Nifflevar"),
(24322, 4, 2, "Show the abberations no mercy, Ymiron!", 12, 0, 100, 1, 0, 0, 23125, 0, "Ancient Citizen of Nifflevar"),
(24322, 4, 3, "They weaken us! Our strength is dilluted by their very existence! Destroy them all!", 12, 0, 100, 113, 0, 0, 23129, 0, "Ancient Citizen of Nifflevar"),
(24322, 4, 4, "Vrykul must remain pure!", 12, 0, 100, 113, 0, 0, 23127, 0, "Ancient Citizen of Nifflevar");

DELETE FROM `smart_scripts` WHERE `entryorguid`=24321 AND `source_type`=0 AND `id` IN (1,2);
DELETE FROM `smart_scripts` WHERE `entryorguid`=2432100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(24321, 0, 1, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "King Ymiron - On Respawn - Set even phase 1"),
(24321, 0, 2, 0, 1, 1, 100, 0, 10000, 10000, 10000, 15000, 0, 1, 4, 0, 0, 0, 0, 0, 11, 24322, 40, 1, 0, 0, 0, 0, 0, "King Ymiron  - Ooc' - SAY line 4 for Ancient Citizen of Nifflevar"),
(2432100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "King Ymiron - On Script - Set even phase 2"),
(2432100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "King Ymiron - On Script - Say Line 0"),
(2432100, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 11, 24323, 40, 1, 0, 0, 0, 0, 0, "King Ymiron - On Script - Say Line 0"),
(2432100, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 11, 24323, 40, 1, 0, 0, 0, 0, 0, "King Ymiron - On Script - Say Line 1"),
(2432100, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 11, 24323, 40, 1, 0, 0, 0, 0, 0, "King Ymiron - On Script - Say Line 2"),
(2432100, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 11, 24323, 40, 1, 0, 0, 0, 0, 0, "King Ymiron - On Script - Say Line 3"),
(2432100, 9, 6, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "King Ymiron - On Script - Say Line 1"),
(2432100, 9, 7, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "King Ymiron - On Script - Say Line 2"),
(2432100, 9, 8, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "King Ymiron - On Script - Say Line 3"),
(2432100, 9, 9, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "King Ymiron - On Script - Say Line 4"),
(2432100, 9, 10, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "King Ymiron - On Script - Play Emote 1"),
(2432100, 9, 11, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "King Ymiron - On Script - Say Line 5"),
(2432100, 9, 12, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "King Ymiron - On Script - Play Emote 1"),
(2432100, 9, 13, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "King Ymiron - On Script - Say Line 6"),
(2432100, 9, 14, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "King Ymiron - On Script - Play Emote 6"),
(2432100, 9, 15, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "King Ymiron - On Script - Say Line 7"),
(2432100, 9, 16, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 1, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "King Ymiron - On Script - Say Line 8"),
(2432100, 9, 17, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 1, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "King Ymiron - On Script - Say Line 9"),
(2432100, 9, 18, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "King Ymiron - On Script - Play Emote 53"),
(2432100, 9, 19, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 0, 1, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "King Ymiron - On Script - Say Line 10"),
(2432100, 9, 20, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "King Ymiron - On Script - Play Emote 53"),
(2432100, 9, 21, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 1, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "King Ymiron - On Script - Say Line 11"),
(2432100, 9, 22, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 1, 12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "King Ymiron - On Script - Say Line 12"),
(2432100, 9, 23, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 43468, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "King Ymiron - On Script - Cast 'Secrets of Nifflevar'"),
(2432100, 9, 24, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "King Ymiron - On Script - Set even phase 2");

UPDATE `creature` SET `equipment_id`=-1 WHERE `id` IN (24323,24322,23954,25617,25728,29016);
DELETE FROM `creature_equip_template` WHERE `CreatureID` IN (24323,24322,23954,25617,25728,29016);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`) VALUES
(24323, 7, 34818, 0, 0), -- 24323
(24322, 7, 34820, 0, 0), -- 24322
(24323, 6, 34819, 33212, 0), -- 24323
(24323, 5, 34816, 0, 0), -- 24323
(24322, 6, 34816, 0, 0), -- 24322
(24322, 5, 34817, 0, 0), -- 24322
(24322, 4, 34818, 0, 0), -- 24322
(24322, 3, 34819, 33212, 0), -- 24322
(24322, 2, 34819, 0, 0), -- 24322
(24323, 4, 34819, 0, 0), -- 24323
(24323, 3, 34820, 0, 0), -- 24323
(24322, 1, 34821, 0, 0), -- 24322
(24323, 2, 34821, 0, 0), -- 24323
(24323, 1, 34817, 0, 0), -- 24323
(23954, 1, 33178, 0, 0),
(23954, 2, 33177, 0, 0),
(25617, 1, 1485, 0, 0),
(25617, 2, 33318, 2081, 0),
(25728, 1, 38296, 0, 0),
(25728, 2, 38297, 0, 0),
(29016, 1, 1903, 0, 0),
(29016, 2, 31824, 0, 0),
(29016, 3, 1911, 0, 0);

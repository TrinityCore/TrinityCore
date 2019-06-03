UPDATE `creature_template` SET `ScriptName`="npc_drostan" WHERE `entry`=28857;

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=28328;
DELETE FROM `smart_scripts` WHERE `entryorguid`=28328 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28328, 0, 0, 0, 19, 0, 100, 0, 12592, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Drostan - On Quest 'The Great Hunter's Challenge' accepted - Talk 1");

DELETE FROM `creature_text` WHERE `CreatureID`=28328 AND `GroupID`=1;
DELETE FROM `creature_text` WHERE `CreatureID`=28857;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(28328, 1, 0, "Remember, $n, this is no sprint. The true test of a hunter tests his endurance over the course of a long expedition.", 12, 0, 100, 0, 0, 0, 29924, 0, "Drostan"),
(28857, 2, 0, "Yer gonna have to shoot faster than that! I've already got 11 kills!", 12, 0, 100, 5, 0, 0, 28983, 0, "Drostan"),
(28857, 2, 1, "That's number 10! How many've you got?", 12, 0, 100, 5, 0, 0, 28984, 0, "Drostan"),
(28857, 2, 2, "Number 9! I could do this with my eyes closed!", 12, 0, 100, 5, 0, 0, 28985, 0, "Drostan"),
(28857, 2, 3, "11! It's gonna take a bigger effort than that to beat ol' Drostan!", 12, 0, 100, 5, 0, 0, 28986, 0, "Drostan"),
(28857, 3, 0, "I'm up to 15. Top that!", 12, 0, 100, 5, 0, 0, 29080, 0, "Drostan"),
(28857, 3, 1, "That's my 16th and I'm still going easy on ya!", 12, 0, 100, 5, 0, 0, 29081, 0, "Drostan"),
(28857, 3, 2, "You're going to have to pick it up, or this isn't going to be much of a competition.", 12, 0, 100, 5, 0, 0, 29082, 0, "Drostan"),
(28857, 3, 3, "Ha! 16! How many've you got? 10, maybe 11 if you're lucky?", 12, 0, 100, 5, 0, 0, 29083, 0, "Drostan"),
(28857, 4, 0, "That's my 25th kill. How far behind are you now?", 12, 0, 100, 5, 0, 0, 29084, 0, "Drostan"),
(28857, 4, 1, "26th! Are you going to start killing, or what?", 12, 0, 100, 5, 0, 0, 29091, 0, "Drostan"),
(28857, 4, 2, "My mother could hunt faster than you, $n.", 12, 0, 100, 5, 0, 0, 29092, 0, "Drostan"),
(28857, 4, 3, "Kill number 26 and I'm still just warming up.", 12, 0, 100, 5, 0, 0, 29093, 0, "Drostan"),
(28857, 5, 0, "Well, now that I've got a nice lead, I think I'll enjoy a little nap.", 12, 0, 100, 5, 0, 0, 29096, 0, "Drostan"),
(28857, 6, 0, "Well, that was a relaxing nap. How's the game hunting going over there?", 12, 0, 100, 5, 0, 0, 29097, 0, "Drostan"),
(28857, 7, 0, "I've got a nice lead, yet. Think I'll do some fishin'.", 12, 0, 100, 5, 0, 0, 29101, 0, "Drostan"),
(28857, 8, 0, "Well, now we've got a competition on our hands.", 12, 0, 100, 5, 0, 0, 29112, 0, "Drostan"),
(28857, 8, 1, "Just got number 41! How's that for skill?", 12, 0, 100, 5, 0, 0, 29116, 0, "Drostan"),
(28857, 8, 2, "41! Two-thirds of the way there. Better step it up!", 12, 0, 100, 5, 0, 0, 29117, 0, "Drostan"),
(28857, 8, 3, "Hey! I was just lining up a shot on that one. Kill stealer!", 12, 0, 100, 5, 0, 0, 29118, 0, "Drostan"),
(28857, 9, 0, "Argh, just now getting number 48. This is getting tough.", 12, 0, 100, 5, 0, 0, 29119, 0, "Drostan"),
(28857, 9, 1, "Someone's been killing all the game out from under me. Hard-won number 48, here.", 12, 0, 100, 5, 0, 0, 29120, 0, "Drostan"),
(28857, 9, 2, "Number 48. Startin' to slow down a bit, now.", 12, 0, 100, 5, 0, 0, 29121, 0, "Drostan"),
(28857, 9, 3, "Gotta go elsewhere to find some more game. Was hoping to be beyond 48 by now.", 12, 0, 100, 5, 0, 0, 29122, 0, "Drostan"),
(28857, 10, 0, "Ha, 54! In the home stretch now!", 12, 0, 100, 5, 0, 0, 29123, 0, "Drostan"),
(28857, 10, 1, "Number 54! No way I'm gonna let you beat me!", 12, 0, 100, 5, 0, 0, 29124, 0, "Drostan"),
(28857, 10, 2, "54! Surely an insurmountable lead!", 12, 0, 100, 5, 0, 0, 29125, 0, "Drostan"),
(28857, 10, 3, "That was 54! Soon you'll be congratulating me!", 12, 0, 100, 5, 0, 0, 29126, 0, "Drostan");

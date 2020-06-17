-- 
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1476;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1476;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1476, 0, 0, 0, 1, 0, 100, 0, 5000, 30000, 300000, 600000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Hargin Mundar - Out Of Combat - Talk"),
(1476, 0, 1, 2, 1, 0, 100, 0, 35000, 45000, 300000, 600000, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Hargin Mundar - Out Of Combat - Talk"),
(1476, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 41995, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Hargin Mundar - Out Of Combat - Cast Vomit");

DELETE FROM `creature_text` WHERE `CreatureId`=1476;
INSERT INTO `creature_text` (`CreatureId`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1476, 0, 0, "Stormy seas out there.  The sea spirits must be restless....hic!", 12, 6, 100, 0, 0, 0, 318, 0, "Hargin Mundar"),
(1476, 0, 1, "I saw a Sea Giant once.  It's not something I would care to see again.  Burp!", 12, 6, 100, 0, 0, 0, 319, 0, "Hargin Mundar"),
(1476, 0, 2, "I'd go out and clear out some of those gnolls, but this leg has seen better days and I am afraid I'd just wind up dead.", 12, 6, 100, 0, 0, 0, 320, 0, "Hargin Mundar"),
(1476, 0, 3, "Watch your step out there.  Many an adventure seeker has not returned from the marsh.  hic!", 12, 6, 100, 0, 0, 0, 321, 0, "Hargin Mundar"),
(1476, 1, 0, "Huuup...Huuup...Bleeeeehh!", 12, 0, 100, 0, 0, 0, 397, 0, "Hargin Mundar");


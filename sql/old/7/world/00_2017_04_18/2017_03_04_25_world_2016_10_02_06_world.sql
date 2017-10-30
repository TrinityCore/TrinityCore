--
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (2338, 2339);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2338, 2339);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2338, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Twilight Disciple - On Aggro - Talk 0"),
(2338, 0, 1, 0, 2, 0, 100, 1, 0, 90, 0, 0, 11, 6074, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Twilight Disciple - Between 0-90% health - Cast 'Renew'"),
(2338, 0, 2, 0, 2, 0, 100, 1, 0, 30, 0, 0, 11, 2054, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Twilight Disciple - Between 0-30% health - Cast 'Heal'"),
(2338, 0, 3, 0, 6, 0, 30, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Twilight Disciple - On Death - Talk 1"),

(2339, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Twilight Thug - On Aggro - Talk 0"),
(2339, 0, 1, 0, 0, 0, 100, 0, 2000, 12000, 35000, 45000, 11, 6713, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Twilight Thug - In Combat - Cast 'Disarm'"),
(2339, 0, 2, 0, 6, 0, 30, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Twilight Thug - On Death - Talk 1");

DELETE FROM `creature_text` WHERE `entry` IN (2338, 2339);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2338, 0, 0, "You will never defeat us!", 12, 0, 100, 0, 0, 0, 825, 0, "Twilight Disciple"),
(2338, 0, 1, "Intruders!  Slay them!", 12, 0, 100, 0, 0, 0, 833, 0, "Twilight Disciple"),
(2338, 0, 2, "For our Masters!", 12, 0, 100, 0, 0, 0, 834, 0, "Twilight Disciple"),
(2338, 0, 3, "Masters,  I pledge this $r to you!", 12, 0, 100, 0, 0, 0, 835, 0, "Twilight Disciple"),
(2338, 0, 4, "Carnage!  May I spill blood in His name!", 12, 0, 100, 0, 0, 0, 836, 0, "Twilight Disciple"),
(2338, 0, 5, "Embrace the end!", 12, 0, 100, 0, 0, 0, 837, 0, "Twilight Disciple"),
(2338, 0, 6, "Battle!  I can smell your fear,  $c!", 12, 0, 100, 0, 0, 0, 838, 0, "Twilight Disciple"),
(2338, 0, 7, "Death comes!  Rejoice!", 12, 0, 100, 0, 0, 0, 839, 0, "Twilight Disciple"),
(2338, 0, 8, "Intruders!  Good,  I was getting bored...", 12, 0, 100, 0, 0, 0, 840, 0, "Twilight Disciple"),
(2338, 1, 0, "My death matters little... the Hammer will still fall!", 12, 0, 10, 0, 0, 0, 826, 0, "Twilight Disciple"),
(2338, 1, 1, "My life for my masters.  Rejoice!", 12, 0, 10, 0, 0, 0, 827, 0, "Twilight Disciple"),
(2338, 1, 2, "Curse you!", 12, 0, 10, 0, 0, 0, 828, 0, "Twilight Disciple"),
(2338, 1, 3, "Glory and blood for the Old Gods!", 12, 0, 10, 0, 0, 0, 829, 0, "Twilight Disciple"),
(2338, 1, 4, "My lords!  I come to thee!", 12, 0, 10, 0, 0, 0, 830, 0, "Twilight Disciple"),
(2338, 1, 5, "Your victory here only speeds your doom!", 12, 0, 10, 0, 0, 0, 831, 0, "Twilight Disciple"),
(2338, 1, 6, "Mommy!", 12, 0, 40, 0, 0, 0, 832, 0, "Twilight Disciple"),
(2339, 0, 0, "You will never defeat us!", 12, 0, 100, 0, 0, 0, 825, 0, "Twilight Thug"),
(2339, 0, 1, "Intruders!  Slay them!", 12, 0, 100, 0, 0, 0, 833, 0, "Twilight Thug"),
(2339, 0, 2, "For our Masters!", 12, 0, 100, 0, 0, 0, 834, 0, "Twilight Thug"),
(2339, 0, 3, "Masters,  I pledge this $r to you!", 12, 0, 100, 0, 0, 0, 835, 0, "Twilight Thug"),
(2339, 0, 4, "Carnage!  May I spill blood in His name!", 12, 0, 100, 0, 0, 0, 836, 0, "Twilight Thug"),
(2339, 0, 5, "Embrace the end!", 12, 0, 100, 0, 0, 0, 837, 0, "Twilight Thug"),
(2339, 0, 6, "Battle!  I can smell your fear,  $c!", 12, 0, 100, 0, 0, 0, 838, 0, "Twilight Thug"),
(2339, 0, 7, "Death comes!  Rejoice!", 12, 0, 100, 0, 0, 0, 839, 0, "Twilight Thug"),
(2339, 0, 8, "Intruders!  Good,  I was getting bored...", 12, 0, 100, 0, 0, 0, 840, 0, "Twilight Thug"),
(2339, 1, 0, "My death matters little... the Hammer will still fall!", 12, 0, 10, 0, 0, 0, 826, 0, "Twilight Thug"),
(2339, 1, 1, "My life for my masters.  Rejoice!", 12, 0, 10, 0, 0, 0, 827, 0, "Twilight Thug"),
(2339, 1, 2, "Curse you!", 12, 0, 10, 0, 0, 0, 828, 0, "Twilight Thug"),
(2339, 1, 3, "Glory and blood for the Old Gods!", 12, 0, 10, 0, 0, 0, 829, 0, "Twilight Thug"),
(2339, 1, 4, "My lords!  I come to thee!", 12, 0, 10, 0, 0, 0, 830, 0, "Twilight Thug"),
(2339, 1, 5, "Your victory here only speeds your doom!", 12, 0, 10, 0, 0, 0, 831, 0, "Twilight Thug"),
(2339, 1, 6, "Mommy!", 12, 0, 40, 0, 0, 0, 832, 0, "Twilight Thug");

DELETE FROM `spell_area` WHERE `spell` = 145389;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_start_active`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`) VALUES (145389, 6757, 0, 0, 0, 0, 0, 2, 1);

DELETE FROM `creature_text` WHERE `entry` = 72970;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES (72970, 0, 0, 'The eons have awakened me.', 14, 0, 100, 0, 0, 0, 'Golganarr spawn');

DELETE FROM `creature_text` WHERE `entry` = 73461;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES (73461, 0, 0, '"Though blood floods the ground, the mountain is unmoved." - Niuzao', 41, 0, 100, 0, 0, 0, 'Niuzao blessing');
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES (73461, 1, 0, '"The truth shines brightest in clouded times." - Yu`lon', 41, 0, 100, 0, 0, 0, 'Yu`lon blessing');
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES (73461, 2, 0, '"Hope`s fire grows when the flames come together." - Chi-Ji', 41, 0, 100, 0, 0, 0, 'Chi-Ji blessing');
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES (73461, 3, 0, '"Strength and power are as different as sun and moon." - Xuen', 41, 0, 100, 0, 0, 0, 'Xuen blessing');
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES (73461, 4, 0, '"The shrine was corrupted by Ordos!"', 41, 0, 100, 0, 0, 0, 'Ordos corruption');

DELETE FROM `creature_text` WHERE `entry` = 71952;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES (71952, 0, 0, 'Then let us begin!', 14, 0, 100, 0, 0, 38024, 'Chi-Ji Aggro');
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES (71952, 1, 0, 'Believe in one another, and let others carry hope for you.', 14, 0, 100, 0, 0, 38028, 'Chi-Ji Beacon of Hope');
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES (71952, 2, 0, 'Without hope, there is no brightness in the future.', 14, 0, 100, 0, 0, 38029, 'Chi-Ji Crane Rush');
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES (71952, 2, 1, 'Create the destiny you seek.', 14, 0, 100, 0, 0, 38030, 'Chi-Ji Crane Rush');
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES (71952, 3, 0, 'Do not give up on yourself!', 14, 0, 100, 0, 0, 38027, 'Chi-Ji Kill Player');
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES (71952, 4, 0, 'Your hope shines brightly, and even more brightly when you work together to overcome. It will ever light your way, in even the darkest of places.', 14, 0, 100, 0, 0, 38025, 'Chi-Ji Defeated');

DELETE FROM `creature_text` WHERE `entry` = 73303;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES (73303, 0, 0, 'You have walked the trial of hope, and learned of the path of the red crane. May it guide your footsteps through time.', 14, 0, 100, 0, 0, 38042, 'Chi-Ji Defeated');

DELETE FROM `creature_text` WHERE `entry` = 73666;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES (73666, 0, 0, 'Your challenge has been answered, outsider. Ordon, claim this area in the name of the Burning God!', 14, 0, 100, 0, 0, 0, 'Archiereus of Flame Aggro');

DELETE FROM `creature_text` WHERE `entry` = 73174;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES (73174, 0, 0, 'Your challenge has been answered, outsider. Ordon, claim this area in the name of the Burning God!', 14, 0, 100, 0, 0, 0, 'Archiereus of Flame Aggro');

DELETE FROM `spell_script_names` WHERE `spell_id` = 144385;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (144385, 'spell_timeless_isle_crane_wings');

DELETE FROM `spell_script_names` WHERE `spell_id` = 147997;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (147997, 'spell_timeless_isle_crane_wings');

DELETE FROM `spell_script_names` WHERE `spell_id` = 147703;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (147703, 'spell_timeless_isle_crane_wings');

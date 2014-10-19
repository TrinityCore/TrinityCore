DELETE FROM `creature_text` WHERE `entry` IN (24068, 23954, 23980);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(24068, 0, 0, 'Ingvar! Your pathetic failure will serve as a warning to all... you are damned! Arise and carry out the master''s will!', 14, 0, 100, 0, 0, 13754, 'Annhylde the Caller to Ingvar the Plunderer'),

(23954, 0, 0, 'I''ll paint my face with your blood!', 14, 0, 100, 0, 0, 13207, 'Ingvar the Plunderer - SAY_AGGRO_1'),
(23954, 1, 0, 'Mjul orm agn gjor!', 14, 0, 100, 0, 0, 13212, 'Ingvar the Plunderer - SAY_SLAY_1'),
(23954, 2, 0, 'My life for the... death god!', 14, 0, 100, 0, 0, 13213, 'Ingvar the Plunderer - SAY_DEATH_1'),

(23954, 3, 0, 'I return! A second chance to carve your skull!', 14, 0, 100, 0, 0, 13209, 'Ingvar the Plunderer - SAY_AGGRO_2'),
(23954, 4, 0, 'I am a warrior born!', 14, 0, 100, 0, 0, 13214, 'Ingvar the Plunderer - SAY_SLAY_2'),
(23954, 5, 0, 'No! I can do... better! I can...', 14, 0, 100, 0, 0, 13211, 'Ingvar the Plunderer - SAY_DEATH_2');

UPDATE `creature_template` SET `lootid`=`entry` WHERE entry IN (23954, 31673);
UPDATE `creature_template` SET `lootid`=0 WHERE entry IN (23980, 31674);

UPDATE `creature_loot_template` SET `entry`=23954 WHERE `entry`=23980;
UPDATE `creature_loot_template` SET `entry`=31673 WHERE `entry`=31674;

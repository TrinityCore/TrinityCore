-- Grand Magus Telestra
UPDATE `creature_template` SET `ScriptName`='boss_magus_telestra' WHERE `entry`=26731;

-- Anomalus
UPDATE `creature_template` SET `ScriptName`='boss_anomalus' WHERE `entry`=26763;
UPDATE `creature_template` SET `ScriptName`='mob_chaotic_rift' WHERE `entry`=26918;

-- Ormorok the Tree-Shaper
UPDATE `creature_template` SET `ScriptName`='boss_ormorok' WHERE `entry`=26794;
UPDATE `creature_template` SET `ScriptName`='mob_crystal_spike' WHERE `entry`=27099;
UPDATE `creature_template` SET `ScriptName`='mob_crystalline_tangler' WHERE `entry`=32665;

-- Keristrasza
UPDATE `creature_template` SET `ScriptName`='boss_keristrasza' WHERE `entry`=26723;

-- Instance script
UPDATE `instance_template` SET `script`='instance_nexus' WHERE `map`=576;

UPDATE `creature_template` SET `AIName` = 'EventAI' WHERE entry IN  (26796, 26798, 26929, 26928, 26930);
DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (26796, 26798, 26929, 26928, 26930);
INSERT INTO `creature_ai_scripts` VALUES
-- Commander Stoutbeard
( 2679600, 26796, 4, 0, 100, 4, 0, 0, 0, 0, 28, 0, 47543, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Commander Stoutbeard - crystal prison remove'),
( 2679601, 26796, 4, 0, 100, 4, 0, 0, 0, 0, 11, 31403, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Commander Stoutbeard - cast battle shout'),
( 2679602, 26796, 0, 0, 100, 5, 3000, 3000, 11000, 15000, 11, 60067, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Commander Stoutbeard - cast charge'),
( 2679603, 26796, 0, 0, 100, 5, 6000, 8000, 19500, 25000, 11, 38618, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Commander Stoutbeard - cast whirlwind'),
( 2679604, 26796, 0, 0, 100, 5, 13000, 13000, 45000, 55000, 11, 19134, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Commander Stoutbeard - cast Frightening Shout'),
-- Commander Kolurg
( 2679800, 26798, 4, 0, 100, 4, 0, 0, 0, 0, 28, 0, 47543, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Commander Kolurg - crystal prison remove'),
( 2679801, 26798, 4, 0, 100, 4, 0, 0, 0, 0, 11, 31403, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Commander Kolurg - cast battle shout'),
( 2679802, 26798, 0, 0, 100, 5, 3000, 3000, 11000, 15000, 11, 60067, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Commander Kolurg - cast charge'),
( 2679803, 26798, 0, 0, 100, 5, 6000, 8000, 19500, 25000, 11, 38618, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Commander Kolurg - cast whirlwind'),
( 2679804, 26798, 0, 0, 100, 5, 13000, 13000, 45000, 55000, 11, 19134, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Commander Kolurg - cast Frightening Shout'),
-- Grand Magus Telestra Clone (Arcane)
( 2692901, 26929, 0, 0, 100, 7, 6000, 8000, 10000, 12000, 11, 47731, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Grand Magus Telestra arcane - cast pollymorph critter'),
( 2692902, 26929, 0, 0, 100, 7, 15000, 16000, 15000, 16000, 11, 47736, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Grand Magus Telestra arcane - cast time stop'),
-- Grand Magus Telestra Clone (Fire)
( 2692801, 26928, 0, 0, 100, 3, 3000, 3000, 8000, 9000, 11, 47721, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Grand magus Telestra fire - cast fire blast N'),
( 2692802, 26928, 0, 0, 100, 5, 3000, 3000, 8000, 9000, 11, 56939, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Grand magus Telestra fire - cast fire blast H'),
( 2692803, 26928, 0, 0, 100, 3, 9000, 9000, 9500, 11500, 11, 47723, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Grand magus Telestra fire - cast scorge N'),
( 2692804, 26928, 0, 0, 100, 5, 9000, 9000, 9500, 11500, 11, 56938, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Grand magus Telestra fire - cast scorge H'),
-- Grand Magus Telestra Clone (Frost)
( 2693001, 26930, 0, 0, 100, 3, 3000, 3000, 8000, 9000, 11, 47729, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Grand Magus Telestra frost - cast ice bard N'),
( 2693002, 26930, 0, 0, 100, 5, 3000, 3000, 8000, 9000, 11, 56937, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Grand Magus Telestra frost - cast ice bard H'),
( 2693003, 26930, 0, 0, 100, 3, 9000, 9000, 15000, 16000, 11, 47727, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Grand Magus Telestra frost - cast blizzard N'),
( 2693004, 26930, 0, 0, 100, 5, 9000, 9000, 15000, 16000, 11, 56936, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Grand Magus Telestra frost - cast blizzard H');

-- Grand Magus Telestra
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1576005 AND -1576000;
INSERT INTO `script_texts` (`entry`, `content_default`, `sound`, `type`, `language`, `emote`, `comment`) VALUES
(-1576000,'You know what they say about curiosity.',13319,1,0,0,'grand magus telestra SAY_AGGRO'),
(-1576001,'Death becomes you!',13324,1,0,0,'grand magus telestra SAY_KILL'),
(-1576002,'Damn the... luck.',13320,1,0,0,'grand magus telestra SAY_DEATH'),
(-1576003,'Now to finish the job!',13323,1,0,0,'grand magus telestra SAY_MERGE'),
(-1576004,'There\'s plenty of me to go around.',13321,1,0,0,'grand magus telestra SAY_SPLIT_1'),
(-1576005,'I\'ll give you more than you can handle.',13322,1,0,0,'grand magus telestra SAY_SPLIT_2');

-- Anomalus
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1576013 AND -1576010;
INSERT INTO `script_texts` (`entry`, `content_default`, `sound`, `type`, `language`, `emote`, `comment`) VALUES
(-1576010,'Chaos beckons.',13186,1,0,0,'anomalus SAY_AGGRO'),
(-1576011,'Of course.',13187,1,0,0,'anomalus SAY_DEATH'),
(-1576012,'Reality... unwoven.',13188,1,0,0,'anomalus SAY_RIFT'),
(-1576013,'Indestructible.',13189,1,0,0,'anomalus SAY_SHIELD');

-- Ormorok the Tree-Shaper
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1576024 AND -1576020;
INSERT INTO `script_texts` (`entry`, `content_default`, `sound`, `type`, `language`, `emote`, `comment`) VALUES
(-1576020,'Noo!',13328,1,0,0,'ormorok SAY_AGGRO'),
(-1576021,'Aaggh!',13330,1,0,0,'ormorok SAY_DEATH'),
(-1576022,'Back!',13331,1,0,0,'ormorok SAY_REFLECT'),
(-1576023,'Bleed!',13332,1,0,0,'ormorok SAY_CRYSTAL_SPIKES'),
(-1576024,'Aaggh! Kill!',13329,1,0,0,'ormorok SAY_KILL');

-- Keristrasza
DELETE FROM `script_texts` WHERE `entry` BETWEEN -1576044 AND -1576040;
INSERT INTO `script_texts` (`entry`, `content_default`, `sound`, `type`, `language`, `emote`, `comment`) VALUES
(-1576040,'Preserve? Why? There\'s no truth in it. No no no... only in the taking! I see that now!',13450,1,0,0,'keristrasza SAY_AGGRO'),
(-1576041,'Now we\'ve come to the truth!',13453,1,0,0,'keristrasza SAY_SLAY'),
(-1576042,'Finish it! FINISH IT! Kill me, or I swear by the Dragonqueen you\'ll never see daylight again!',13452,1,0,0,'keristrasza SAY_ENRAGE'),
(-1576043,'Dragonqueen... Life-Binder... preserve... me.',13454,1,0,0,'keristrasza SAY_DEATH'),
(-1576044,'Stay. Enjoy your final moments.',13451,1,0,0,'keristrasza SAY_CRYSTAL_NOVA');

UPDATE `transports` SET `period`=255895 WHERE `entry`=164871;
UPDATE `transports` SET `period`=244531 WHERE `entry`=175080;
UPDATE `transports` SET `period`=599143 WHERE `entry`=190549;
UPDATE `transports` SET `period`=231236 WHERE `entry`=20808;
UPDATE `transports` SET `period`=230016 WHERE `entry`=176231;
UPDATE `transports` SET `period`=235783 WHERE `entry`=176310;
UPDATE `transports` SET `period`=238658 WHERE `entry`=181646;
UPDATE `transports` SET `period`=298829 WHERE `entry`=186238;
UPDATE `transports` SET `period`=319210 WHERE `entry`=176495;
UPDATE `transports` SET `period`=446334 WHERE `entry`=181688;
UPDATE `transports` SET `period`=214579 WHERE `entry`=181689;
UPDATE `transports` SET `period`=484348 WHERE `entry`=186371;
UPDATE `transports` SET `period`=307953 WHERE `entry`=187038;
UPDATE `transports` SET `period`=445220 WHERE `entry`=187568;
UPDATE `transports` SET `period`=502354 WHERE `entry`=188511;
UPDATE `transports` SET `period`=271979 WHERE `entry`=190536;
UPDATE `transports` SET `period`=1431158 WHERE `entry`=192241;
UPDATE `transports` SET `period`=1051388 WHERE `entry`=192242;
UPDATE `transports` SET `period`=599143 WHERE `entry`=190549;



DELETE FROM `transports` WHERE `guid` IN (23, 24, 25, 26, 27, 28);
INSERT INTO `transports` (`guid`, `entry`, `name`, `period`, `ScriptName`) VALUES
(23, 203466, 'Ship to Vashj''ir - (Horde)', 327895, ''),
(24, 203626, 'The Spear of Durotar', 534650, ''),
(25, 197195, 'Ship to Vashj''ir - (Alliance)', 317922, ''),
(26, 207227, 'Krazzworks Attack Zeppelin', 71606, ''),
(27, 204018, 'Deepholm - Alliance Gunship', 178136, ''),
(28, 203428, 'Worgen area - Orc Gunship', 316236, '');


UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=203428; -- Orc Gunship
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=204018; -- Alliance Gunship
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=164871; -- Zeppelin (The Thundercaller)
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=20808; -- Ship (The Maiden's Fancy)
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=175080; -- Zeppelin (The Iron Eagle)
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=176231; -- Ship (The Lady Mehley)
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=176310; -- Ship (The Bravery)
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=181646; -- Ship, Night Elf (Elune's Blessing)
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=186238; -- Zeppelin, Horde (The Mighty Wind)
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=190549; -- The Zephyr
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=197195; -- Ship to Vashj'ir
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=203466; -- Ship to Vashj'ir
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=203626; -- The Spear of Durotar
UPDATE `gameobject_template` SET `flags`=40 WHERE `entry`=207227; -- Krazzworks Attack Zeppelin

UPDATE `creature_template` SET `ScriptName` = 'npc_nightmare_suppressor' WHERE `entry`=8497;
UPDATE `creature_template` SET `ScriptName` = 'npc_hakkari_bloodkeeper'  WHERE `entry`=8438;
UPDATE `creature_template` SET `ScriptName` = 'boss_avatar_of_hakkar'    WHERE `entry`=8443;

DELETE FROM `creature_text` WHERE `CreatureID` IN (8497, 8440, 8443);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(8497, 0, 0, 'Stop!  Infidels!', 14, 0, 100, 0, 0, 0, 4532, 0, 'Nightmare Suppressor'),
(8497, 0, 1, 'You must not summon our god!', 14, 0, 100, 0, 0, 0, 4530, 0, 'Nightmare Suppressor'),
(8497, 0, 2, 'No!  We cannot allow you to summon Hakkar!', 14, 0, 100, 0, 0, 0, 4529, 0, 'Nightmare Suppressor'),
(8497, 0, 3, 'No!  You must not do this!', 14, 0, 100, 0, 0, 0, 4531, 0, 'Nightmare Suppressor'),
(8440, 0, 0, 'I DRAW CLOSER TO THIS WORLD!', 14, 0, 100, 0, 0, 0, 4543, 0, 'Shade of Hakkar'),
(8440, 1, 0, 'I TASTE THE BLOOD OF LIFE!', 14, 0, 100, 0, 0, 0, 6252, 0, 'Shade of Hakkar'),
(8440, 2, 0, 'I AM NEAR!', 14, 0, 100, 0, 0, 0, 6253, 0, 'Shade of Hakkar'),
(8440, 3, 0, 'HAKKAR LIVES!', 14, 0, 100, 0, 0, 0, 6254, 0, 'Shade of Hakkar'),
(8443, 0, 0, 'I AM HERE!', 14, 0, 100, 0, 0, 0, 4545, 0, 'Avatar of Hakkar'),
(8443, 1, 0, 'DIE, MORTALS!', 14, 0, 100, 0, 0, 0, 4546, 0, 'Avatar of Hakkar');
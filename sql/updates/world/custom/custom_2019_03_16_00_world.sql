UPDATE `creature_template` SET `ScriptName`= 'npc_zulaman_amanishi_guardian' WHERE `entry`= 23597;
UPDATE `creature_template_addon` SET `mount`= 29261 WHERE `entry`= 52924; -- 52924 (Vol'jin)

DELETE FROM `creature_text` WHERE `CreatureID` IN (52924, 23597);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
-- Vol'jin
(52924, 0, 0, 'Follow me, $c. It be takin'' da both of us to open these gates.', 14, 0, 100, 1, 0, 0, 51504, 'Vol\'jin - Intro 1'),
(52924, 1, 0, 'Da ritual to open da gates be requirin'' both of us to hit da gong together.', 14, 0, 100, 1, 0, 0, 51506, 'Vol\'jin - Intro 2'),
(52924, 2, 0, 'Hear me, Zandalari schemers... Da Darkspears and our allies will deny you rulership of da Amani!', 14, 0, 100, 25, 0, 0, 51517, 'Vol\'jin - Intro 3'),
(52924, 3, 0, 'Da Amani know we''re here. Now is da time to attack!', 14, 0, 100, 5, 0, 0, 51519, 'Vol\'jin - Intro 4'),
(52924, 4, 0, 'Perhaps we''re not ready yet. Speak to me again when you be wantin'' to open da gates.', 14, 0, 100, 1, 0, 0, 51508, 'Vol\'jin - Fail Intro'),
(52924, 5, 0, 'Hear me, Rastakhan! Wherever ya and your Zandalari be schemin'' to rule da troll people, ya be findin'' da Darkspear and our allies standin'' against ya!', 12, 0, 100, 1, 0, 0, 51658, 'Vol\'jin - Daakara Death'),
-- Amani Guardian
(23597, 0, 0, 'More intruders! Sound da alarm!', 14, 0, 100, 25, 0, 12104, 23252, 'Amani''Shi Guardian - Intro'),
(23597, 1, 0, '%s goes into a frenzy!', 16, 0, 100, 0, 0, 0, 36719, 'Amani''Shi Guardian - Enrage');

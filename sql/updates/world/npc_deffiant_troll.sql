-- http://www.wowhead.com/quest=14069
UPDATE `creature_template` SET `ScriptName` = 'npc_defiant_troll' WHERE `entry` = 34830;

DELETE FROM `creature_text` WHERE `entry` = 34830;
INSERT INTO `creature_text`(`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(34830, 0, 0, 'Oops, break''s over.', 14, 0, 100, 0, 0, 0, 'defiant troll says'),
(34830, 1, 0, 'Don''t tase me, mon!', 14, 0, 100, 0, 0, 0, 'defiant troll says'),
(34830, 2, 0, 'I report you to HR!', 14, 0, 100, 0, 0, 0, 'defiant troll says'),
(34830, 3, 0, 'Work was bettah in da Undermine!', 14, 0, 100, 0, 0, 0, 'defiant troll says'),
(34830, 4, 0, 'I''m going. I''m going!', 14, 0, 100, 0, 0, 0, 'defiant troll says'),
(34830, 5, 0, 'Sorry, mon. It won''t happen again.', 14, 0, 100, 0, 0, 0, 'defiant troll says'),
(34830, 6, 0, 'What I doin'' wrong? Don''t I get a lunch and two breaks a day, mon?', 14, 0, 100, 0, 0, 0, 'defiant troll says'),
(34830, 7, 0, 'Ouch! Dat hurt!', 14, 0, 100, 0, 0, 0, 'defiant troll says');

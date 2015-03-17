DELETE FROM creature_text WHERE entry=16287 AND groupid=0;
DELETE FROM creature_text WHERE entry=10181 AND groupid=2;
INSERT INTO creature_text (entry, groupid, id, text, type, language, probability, emote, duration, sound, BroadcastTextId, TextRange, comment) VALUES
(16287, 0, 0, 'That could have gone better. $n, come here, please. I have something I need you to take care of for me.', 15, 0, 100, 0, 0, 0, 12157, 0, 'Ambassador Sunsorrow'),
(10181, 2, 0, '%s looks down at the discarded necklace. In her sadness, the lady incants a glamour, which beckons forth Highborne spirits. The chamber resonates with their ancient song about the Sin''dorei...', 16, 0, 100, 0, 0, 0, 19197, 0, 'npc_lady_sylvanas_windrunner');
UPDATE `creature_template` SET `ScriptName`='npc_ambassador_sunsorrow' WHERE `entry`='16287';

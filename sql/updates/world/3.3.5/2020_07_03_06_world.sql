--
UPDATE `creature` SET `spawntimesecs` = 300 WHERE `spawntimesecs` = 540 AND `id` NOT IN (1061,5186);
UPDATE `creature` SET `spawntimesecs` = 300 WHERE `spawntimesecs` = 550 AND `id` NOT IN (5760,4686,4687);
UPDATE `creature` SET `spawntimesecs` = 300 WHERE `spawntimesecs` = 644;
UPDATE `creature` SET `spawntimesecs` = 300 WHERE `spawntimesecs` = 180 AND `id` NOT IN (18558,23188) AND `id` < 23689;
-- Grik'nir the Cold
UPDATE `creature` SET `spawntimesecs` = 100 WHERE `id` = 808; -- https://www.wowhead.com/npc=808/griknir-the-cold#comments:id=148734
-- Old Icebeard
UPDATE `creature` SET `spawntimesecs` = 90 WHERE `id` = 1271; -- https://www.wowhead.com/npc=1271/old-icebeard#comments:id=551613
-- Mangeclaw
UPDATE `creature` SET `spawntimesecs` = 60 WHERE `id` = 1961; -- Wowhead
-- Lakka
UPDATE `creature` SET `spawntimesecs` = 86400 WHERE `id` = 18956;

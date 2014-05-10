-- set FISH_JUNK_GROUP = 11799;
-- set FISH_JUNK_LOOTMODE = 32768;
DELETE FROM fishing_loot_template WHERE `item`=11799;
INSERT INTO fishing_loot_template
(`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`)
VALUES
('1','11799','100','32768','1','-11799','1');

DELETE FROM reference_loot_template WHERE `entry` = '11799';
INSERT INTO reference_loot_template 
(`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`)
VALUES
('11799','45190','15','32768','1','1','1'), -- [Driftwood]
('11799','45191','2','32768','1','1','1'), -- [Water Snail]
('11799','45194','15','32768','1','1','1'), -- [Tangled Fishing Line]
('11799','45195','5','32768','1','1','1'), -- [Empty Rum Bottle]
('11799','45196','15','32768','1','1','1'), -- [Tattered Cloth]
('11799','45197','5','32768','1','1','1'), -- [Tree Branch]
('11799','45198','15','32768','1','1','1'), -- [Weeds]
('11799','45199','5','32768','1','1','1'), -- [Old Boot]
('11799','45200','15','32768','1','1','1'), -- [Sickly Fish]
('11799','45201','3','32768','1','1','1'), -- [Rock]
('11799','45202','5','32768','1','1','1'); -- [Water Snail]
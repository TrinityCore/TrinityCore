-- Wowhead provides pretty accurate value of gold
-- To view gold value copy link with view-source:
-- Like view-source:http://web.archive.org/web/20100415040537/http://www.wowhead.com/npc=19622
-- Press ctrl+f and type word 'money' without apostrophes
-- Result [money=3000000] means 300 gold

-- To find video, simply type 'BossName solo 2010' in youtube search

-- Tempest Keep
-- Void Reaver 2010 https://youtu.be/AERrV4sUOrY?t=630 2011 https://youtu.be/Gtbcj6m6yD0?t=287
-- view-source:http://web.archive.org/web/20100421015449/www.wowhead.com/npc=19516
UPDATE `creature_template` SET `mingold` = 250*100*100, `maxgold` = 250*100*100 WHERE `entry` = 19516;
-- High Astromancer Solarian 2011 https://youtu.be/O8FdbGzGqbE?t=459
-- view-source:http://web.archive.org/web/20100411225831/http://www.wowhead.com/npc=18805
UPDATE `creature_template` SET `mingold` = 250*100*100, `maxgold` = 250*100*100 WHERE `entry` = 18805;
-- Al'ar 2010 https://youtu.be/arZolhOwzEA?t=391
-- view-source:http://web.archive.org/web/20100413015919/http://www.wowhead.com/npc=19514
UPDATE `creature_template` SET `mingold` = 250*100*100, `maxgold` = 250*100*100 WHERE `entry` = 19514;
-- Kael'thas Sunstrider 2011 https://youtu.be/RhPLvODP6cA?t=464
-- view-source:http://web.archive.org/web/20100415040537/http://www.wowhead.com/npc=19622
UPDATE `creature_template` SET `mingold` = 300*100*100, `maxgold` = 300*100*100 WHERE `entry` = 19622;

-- SSC
UPDATE `creature_template` SET `mingold` = 250*100*100, `maxgold` = 250*100*100 WHERE `entry` IN (21213,21214,21215,21216,21217);
UPDATE `creature_template` SET `mingold` = 300*100*100, `maxgold` = 300*100*100 WHERE `entry` = 21212;
-- Hyjal
UPDATE `creature_template` SET `mingold` = 250*100*100, `maxgold` = 250*100*100 WHERE `entry` IN (17767,17808,17888,17842);
UPDATE `creature_template` SET `mingold` = 300*100*100, `maxgold` = 300*100*100 WHERE `entry` = 17968;

-- Magtheridon's Lair
-- 2010 https://youtu.be/SLklH5tFom8?t=185
-- 2010 https://youtu.be/dypC8EcQ0dU?t=376
-- 2010 https://youtu.be/QjuVBYEbz_Y?t=664
-- 2011 https://youtu.be/GDTWnvniPNQ?t=257
-- view-source:http://web.archive.org/web/20100415195930/http://www.wowhead.com/npc=17257
-- 481 - 519, let's make it 480 - 520
UPDATE `creature_template` SET `mingold` = 480*100*100, `maxgold` = 520*100*100 WHERE `entry` = 17257;

-- Gruul's Lair
-- High King Maulgar
-- 2011 https://youtu.be/thb2Y-Y9xTU?t=256 250?
-- 2011 https://youtu.be/X9JlvxQrQYA?t=207 250
-- 2009 https://youtu.be/10XD5ERfbbg?t=202 62.50 * 4 = 250
-- But 237 2010 in view-source:http://web.archive.org/web/20100412012636/www.wowhead.com/npc=18831
-- And 224 2011 in view-source:http://web.archive.org/web/20110624011818/www.wowhead.com/npc=18831
-- And 250 2011 in view-source:http://web.archive.org/web/20111127022216/www.wowhead.com/npc=18831
-- Wowhead value is incomplete or they changed value to ~220-240 in 2010 from 250 and changed it back to 250 in 2011
-- Pretty unrealistic
UPDATE `creature_template` SET `mingold` = 250*100*100, `maxgold` = 250*100*100 WHERE `entry` = 18831;

-- Gruul the Dragonkiller
-- 2010 https://youtu.be/MnyHbTZlOWo?t=409 250
-- 2010 https://youtu.be/hSUBxKGDec0?t=399 125 * 2, there were 4 people in instance but two of them were not near when gold was looted
-- But 238 in view-source:http://web.archive.org/web/20100412000138/http://www.wowhead.com/npc=19044 2010
-- And 221 in view-source:http://web.archive.org/web/20110624030625/http://www.wowhead.com/npc=19044 2011
-- Let's trust videos in this case and not Wowhead
UPDATE `creature_template` SET `mingold` = 250*100*100, `maxgold` = 250*100*100 WHERE `entry` = 19044;

-- Black Temple
UPDATE `creature_template` SET `mingold` = 250*100*100, `maxgold` = 250*100*100 WHERE `entry` IN (22887,22898,22841,22871,22948,23420,22947);
UPDATE `creature_template` SET `mingold` = 625000, `maxgold` = 625000 WHERE `entry` IN (22949,22950,22951,22952);
UPDATE `creature_template` SET `mingold` = 300*100*100, `maxgold` = 300*100*100 WHERE `entry` = 22917;

-- Sunwell Plateau
UPDATE `creature_template` SET `mingold` = 250*100*100, `maxgold` = 250*100*100 WHERE `entry` IN (24892,24882,25038,25840);
UPDATE `creature_template` SET `mingold` = 350*100*100, `maxgold` = 350*100*100 WHERE `entry` IN (25165,25166);
UPDATE `creature_template` SET `mingold` = 500*100*100, `maxgold` = 500*100*100 WHERE `entry` = 25315;

-- Karazhan
-- Same as in Zul'Aman 34 - 42, Zul'Aman requires no changes
UPDATE `creature_template` SET `mingold` = 34*100*100, `maxgold` = 42*100*100 WHERE `entry` IN (
15550, -- 38 view-source:http://web.archive.org/web/20100415005602/http://www.wowhead.com/npc=15687
15687, -- 38 view-source:http://web.archive.org/web/20100411225751/http://www.wowhead.com/npc=15687
16457, -- 38 view-source:http://web.archive.org/web/20100413185955/http://www.wowhead.com/npc=16457
18168, -- 38 view-source:http://web.archive.org/web/20100417044512/http://www.wowhead.com/npc=18168
-- Current values seems accurate
-- 17521,
-- 17533,
-- 17534,
15691, -- 38 view-source:http://web.archive.org/web/20100418104151/http://www.wowhead.com/npc=15691
15688, -- 38 view-source:http://web.archive.org/web/20100428233317/http://www.wowhead.com/npc=15688
16524, -- 38 view-source:http://web.archive.org/web/20100417044422/http://www.wowhead.com/npc=16524
15689, -- 38 view-source:http://web.archive.org/web/20100415000855/http://www.wowhead.com/npc=15689
17225, -- 38 view-source:http://web.archive.org/web/20100417003930/http://www.wowhead.com/npc=17225
15690); -- 38 view-source:http://web.archive.org/web/20100414162246/http://www.wowhead.com/npc=15690

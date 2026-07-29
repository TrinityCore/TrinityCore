-- Hillsbrad Foothills Fixes

-- NPC: 2628 Dalaran Worker
-- NPC: 47010 Indigos

-- Difficulty Fixes
DELETE FROM `creature_template_difficulty` WHERE Entry IN (47010,2628) AND `DifficultyID` = 0;
UPDATE `creature_template_difficulty` SET `DifficultyID` = 0 WHERE Entry IN (47010,2628) AND `DifficultyID` = 1;

UPDATE creature_template_difficulty SET StaticFlags1 = StaticFlags1 | 0x20000000 WHERE Entry IN (47010) AND DifficultyID = 0;

-- Creature Addons
DELETE FROM creature_addon WHERE guid IN (324620,324624,324625,324626,324627,324629,324657,324660,324661,324671,324688,
324689,324726,324727,324740,324743,324744,324749,324761,324768,324809,324810,324818,324819,324824,324828);
INSERT INTO creature_addon (guid, emote) VALUES (324624, 728);
INSERT INTO creature_addon (guid, emote) VALUES (324627, 728);
INSERT INTO creature_addon (guid, emote) VALUES (324727, 728);
INSERT INTO creature_addon (guid, emote) VALUES (324818, 728);
INSERT INTO creature_addon (guid, emote) VALUES (324660, 69);
INSERT INTO creature_addon (guid, emote) VALUES (324743, 69);
INSERT INTO creature_addon (guid, emote) VALUES (324625, 69);
INSERT INTO creature_addon (guid, emote) VALUES (324629, 69);
INSERT INTO creature_addon (guid, emote) VALUES (324689, 69);
INSERT INTO creature_addon (guid, emote) VALUES (324809, 69);
INSERT INTO creature_addon (guid, emote) VALUES (324824, 69);
INSERT INTO creature_addon (guid, emote) VALUES (324671, 1043);
INSERT INTO creature_addon (guid, emote) VALUES (324744, 1043);
INSERT INTO creature_addon (guid, emote) VALUES (324749, 1043);
INSERT INTO creature_addon (guid, emote) VALUES (324740, 1043);
INSERT INTO creature_addon (guid, emote) VALUES (324657, 1043);
INSERT INTO creature_addon (guid, emote) VALUES (324661, 1043);
INSERT INTO creature_addon (guid, emote) VALUES (324626, 1043);
INSERT INTO creature_addon (guid, emote) VALUES (324620, 1043);
INSERT INTO creature_addon (guid, emote) VALUES (324726, 1043);
INSERT INTO creature_addon (guid, emote) VALUES (324688, 1043);
INSERT INTO creature_addon (guid, emote) VALUES (324761, 1043);
INSERT INTO creature_addon (guid, emote) VALUES (324819, 1043);
INSERT INTO creature_addon (guid, emote) VALUES (324810, 1043);
INSERT INTO creature_addon (guid, emote) VALUES (324828, 1043);
INSERT INTO creature_addon (guid, emote) VALUES (324768, 1043);

-- Creature Fixes
UPDATE creature
SET MovementType = 1,
    wander_distance = 8
WHERE id IN (
    2356,
    2350,
    45728,
    49116,
    2375,
    2374,
    48483,
    48484,
    2287,
    2256,
    2417,
    2251,
    2254,
    2255
);

UPDATE creature
SET MovementType = 1,
    wander_distance = 8
WHERE guid IN (
    324748,
    324670,
    324663,
    324623,
    324631,
    324753,
    324769,
    324823,
    324767,
    324762
);

-- Loch Modan Fixes

-- Creature Position fixes
UPDATE creature SET position_x = -5726.2583, position_y = -3819.0159, position_z = 362.77994, orientation = 3.1380577 WHERE guid = 287642;

-- Creature Spawn fixes
UPDATE creature SET MovementType = 1, wander_distance = 8
WHERE id IN (
    44188,44628,44576,44616,1165,1167,44184,1693,
    44620,45402,44176,44627,1186,1195,1176,1177,
    2516,44162,44161,1172,1173,2098,44758,44760,14267,44638
);
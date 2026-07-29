-- Arathi Highlands Fixes

-- NPC: 229951 Captain Roderick Brewston
-- NPC: 229969 Luma Noss <Food & Drink>
-- NPC: 229964 Amy Hardy <Tailoring Supplies>
-- NPC: 231301 Balinda Darkstone <Blacksmith>

-- Template Fixes
UPDATE creature_template SET faction = 2959 WHERE entry = 229951;
UPDATE creature_template SET faction = 2959 WHERE entry = 229969;
UPDATE creature_template SET faction = 2959 WHERE entry = 229964;
UPDATE creature_template SET faction = 2959 WHERE entry = 231301;

-- Creature Spawn fixes
UPDATE creature
SET MovementType = 1,
    wander_distance = 8
WHERE id IN (
    142343,
    142342,
    142334,
    142338,
    141724,
    141726,
    141947,
    141946,
    141727,
    142005,
    44116,
    142340
);

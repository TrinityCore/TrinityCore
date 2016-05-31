-- Fixed HP & Mana
UPDATE `creature_template` SET `exp`=3 WHERE `entry` IN (42188, 42333, 42428, 42691, 42692, 42695, 42696, 42789, 42808, 42810, 42845, 43214, 43357, 43391, 43430, 43438, 43537, 43662, 49857, 49859, 49929, 50048);

-- Set trigger flag
UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry` IN (40350, 43357);

-- Stonecore - Normal & Heroic
UPDATE `creature` SET `spawnMask`=3 WHERE `map`=725;
UPDATE `gameobject` SET `spawnMask`=3 WHERE `map`=725;

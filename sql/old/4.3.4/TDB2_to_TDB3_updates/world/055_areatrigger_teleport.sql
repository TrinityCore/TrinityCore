-- The Oculus (exit) & Socrethar's Seat To Mainland
DELETE FROM `areatrigger_teleport` WHERE `id` IN (5001, 4523);

-- Fixed two swapped triggers & corrected small error in "x" position (was -561.35)
UPDATE `areatrigger_teleport` SET `target_position_x`=-561.351 WHERE `id`=6354; -- Twilight Bastion - Entrance Target
UPDATE `areatrigger_teleport` SET `name`='Icecrown Dungeon - Halls of Reflection - Entrance Target', `target_map`=668, `target_position_x`=5239.46, `target_position_y`=1932.99, `target_position_z`=707.695, `target_orientation`=0.785398 WHERE `id`=5683; -- WSL 3932
UPDATE `areatrigger_teleport` SET `name`='Icecrown Dungeon - Pit of Saron - Entrance Target', `target_map`=658, `target_position_x`=432.568, `target_position_y`=212.344, `target_position_z`=528.709, `target_orientation`=0 WHERE `id`=5688; -- WSL 3933

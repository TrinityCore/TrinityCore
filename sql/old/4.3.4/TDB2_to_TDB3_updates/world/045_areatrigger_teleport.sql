DELETE FROM `areatrigger_teleport` WHERE `id` IN (6322, 6210, 6211);
INSERT INTO `areatrigger_teleport` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`, `name`) VALUES
(6322, 0, -6519.82, -4608.52, 28.4842, 4.36332, 'Badlands 4.x - Dock Teleport Target'),
(6210, 0, 3392.41, -3406.85, 142.246, 4.71239, 'Stratholme - Front Right Exit Target'),
(6211, 0, 3393.17, -3352.15, 142.246, 1.5708, 'Stratholme - Front Left Exit Target');

UPDATE `areatrigger_teleport` SET `name`='Blackrock Depths Entrance Target', `target_position_x`=456.929, `target_position_y`=34.0923, `target_position_z`=-68.0896, `target_orientation`=4.71239 WHERE `id`=1466; -- WSL 3643
UPDATE `areatrigger_teleport` SET `name`='Blackrock Spire Entrance Target', `target_position_x`=78.3534, `target_position_y`=-226.841, `target_position_z`=49.7662, `target_orientation`=4.71239 WHERE `id`=1468; -- WSL 3644
UPDATE `areatrigger_teleport` SET `name`='Blackrock Spire Exit Target', `target_position_x`=-7524.65, `target_position_y`=-1229.13, `target_position_z`=285.731, `target_orientation`=2.0944 WHERE `id`=1470; -- WSL 3645
UPDATE `areatrigger_teleport` SET `name`='Blackrock Depths Exit Target', `target_position_x`=-7178.41, `target_position_y`=-922.152, `target_position_z`=166.092, `target_orientation`=2.00713 WHERE `id`=1472; -- WSL 3646
UPDATE `areatrigger_teleport` SET `name`='Stormwind - Tram Entrance Target 001', `target_position_x`=67.7607, `target_position_y`=2490.98, `target_position_z`=-4.29649, `target_orientation`=3.14159 WHERE `id`=2173; -- WSL 3650
UPDATE `areatrigger_teleport` SET `name`='Ironforge - Tram Entrance Target 001', `target_position_x`=69.2277, `target_position_y`=10.3932, `target_position_z`=-4.29665, `target_orientation`=3.14159 WHERE `id`=2175; -- WSL 3651
UPDATE `areatrigger_teleport` SET `name`='Ironforge - Tram Exit Target 001', `target_position_x`=-4839.51, `target_position_y`=-1317.74, `target_position_z`=501.868, `target_orientation`=1.48353 WHERE `id`=2166; -- WSL 3648
UPDATE `areatrigger_teleport` SET `name`='Stormwind - Tram Exit Target 001', `target_position_x`=-8359.27, `target_position_y`=517.585, `target_position_z`=84.4087, `target_orientation`=2.35619 WHERE `id`=2171; -- WSL 3649
UPDATE `areatrigger_teleport` SET `name`='Deadmines Entrance Target' WHERE `id`=78; -- WSL 3598
UPDATE `areatrigger_teleport` SET `name`='Deadmines Exit Front Target', `target_position_x`=-11208, `target_position_y`=1676.41, `target_position_z`=24.5716, `target_orientation`=4.71239 WHERE `id`=119; -- WSL 3601
UPDATE `areatrigger_teleport` SET `name`='Deadmines Rear Exit Target', `target_position_x`=-11341, `target_position_y`=1576.55, `target_position_z`=93.7284, `target_orientation`=3.03687 WHERE `id`=121; -- WSL 4292
UPDATE `areatrigger_teleport` SET `name`='Badlands 4.x - Cliff Teleport Target' WHERE `id`=6321; -- WSL 3964
UPDATE `areatrigger_teleport` SET `name`='Vashj''ir - Throne of Tides Exit Target', `target_position_x`=-5592.83, `target_position_y`=5408.36, `target_position_z`=-1798.57, `target_orientation`=2.44346 WHERE `id`=6197; -- WSL 3960
UPDATE `areatrigger_teleport` SET `name`='Throne of Tides - Entrance Target' WHERE `id`=6201; -- WSL 3961
UPDATE `areatrigger_teleport` SET `name`='Blackrock Caverns - Exit Target (in Eastern Kingdoms)', `target_position_x`=-7571.14, `target_position_y`=-1324.96, `target_position_z`=245.538, `target_orientation`=1.67552 WHERE `id`=6011; -- WSL 3953
UPDATE `areatrigger_teleport` SET `name`='Blackrock Caverns - Entrance Target' WHERE `id`=6108; -- WSL 3955
UPDATE `areatrigger_teleport` SET `name`='Deepholm - Stonecore Exit Target', `target_position_x`=1023.72, `target_position_y`=644.747, `target_position_z`=156.672, `target_orientation`=1.74533 WHERE `id`=6194; -- WSL 3958
UPDATE `areatrigger_teleport` SET `name`='Stonecore - Entrance Target' WHERE `id`=6196; -- WSL 3959
UPDATE `areatrigger_teleport` SET `name`='Stratholme - Back Entrance Target 001', `target_position_x`=3590.87, `target_position_y`=-3643.22, `target_position_z`=138.491, `target_orientation`=5.49779 WHERE `id`=2214; -- WSL 3652
UPDATE `areatrigger_teleport` SET `name`='Stratholme - Front Right Entrance Target 001', `target_position_x`=3393.27, `target_position_y`=-3392, `target_position_z`=143.151, `target_orientation`=1.5708 WHERE `id`=2216; -- WSL 3653
UPDATE `areatrigger_teleport` SET `name`='Stratholme - Front Left Entrance Target 001', `target_position_x`=3393, `target_position_y`=-3366.9, `target_position_z`=142.836, `target_orientation`=4.71239 WHERE `id`=2217; -- WSL 3654
UPDATE `areatrigger_teleport` SET `name`='Stratholme - Back Exit Target 001', `target_position_x`=3233.06, `target_position_y`=-4048.3, `target_position_z`=108.442, `target_orientation`=2.00713 WHERE `id`=2221; -- WSL 3655

UPDATE `game_tele` SET `position_x`=-6712.909, `position_y`=-3350.911, `position_z`=241.2541, `orientation`=1.010482 WHERE `id`=72; -- Badlands
UPDATE `game_tele` SET `position_x`=-5172.035, `position_y`=-2952.925, `position_z`=336.9935, `orientation`=6.208088 WHERE `id`=568; -- Loch Modan
UPDATE `game_tele` SET `position_x`=-4080.598, `position_y`=-3463.158, `position_z`=273.2756, `orientation`=0.690672 WHERE `id`=442; -- Grim Batol
UPDATE `game_tele` SET `position_x`=-9477.038, `position_y`=-3353.416, `position_z`=27.4190, `orientation`=1.657923 WHERE `id`=949; -- Stonewatch Falls
UPDATE `game_tele` SET `position_z`=138.2763 WHERE `id`=945; -- Stonetalon Mountains



-- Undo some things from previous Sync
UPDATE `creature_template` SET `name`='Zhaagrym' WHERE `entry`=36301; -- Good name
UPDATE `creature_template` SET `faction_A`=1885, `faction_H`=1885 WHERE `entry`=30884; -- Good faction
DELETE FROM `gameobject` WHERE `guid`=76;

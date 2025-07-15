-- Lower the spawn point height for trigger "Pools of Arlithrien Moonwell" (19551) to just under the ground.
UPDATE `gameobject` SET `position_z`=1298.41640 WHERE `guid`=50359 AND `id`=19551;

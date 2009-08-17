UPDATE `creature_template` SET `ScriptName`='mob_scarlet_courier' WHERE `entry`='29076';

UPDATE `creature_template` SET `ScriptName`='npc_koltira_deathweaver' WHERE `entry`='28912';
UPDATE `creature_template` SET `ScriptName`='mob_high_inquisitor_valroth' WHERE `entry`='29001';


DELETE FROM script_waypoint WHERE entry=28912;
INSERT INTO script_waypoint VALUES
   (28912, 0, 1653.518, -6038.374, 127.585, 1000, 'Jump off'),
   (28912, 1, 1653.978, -6034.614, 127.585, 5000, 'To Box'),
   (28912, 2, 1653.854, -6034.726, 127.585, 0, 'Equip'),
   (28912, 3, 1652.297, -6035.671, 127.585, 1000, 'Recover'),
   (28912, 4, 1639.762, -6046.343, 127.948, 0, 'Escape'),
   (28912, 5, 1640.963, -6028.119, 134.740, 0, ''),
   (28912, 6, 1625.805, -6029.197, 134.740, 0, ''),
   (28912, 7, 1626.845, -6015.085, 134.740, 0, ''),
   (28912, 8, 1649.150, -6016.975, 133.240, 0, ''),
   (28912, 9, 1653.063, -5974.844, 132.652, 5000, 'Mount'),
   (28912, 10, 1654.747, -5926.424, 121.191, 0, 'Disappear');
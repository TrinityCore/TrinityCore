UPDATE `gossip_menu_option` SET `action_poi_id`=0 WHERE `menu_id`=3356;
DELETE FROM gossip_menu WHERE entry IN (12417,12429,15145);

UPDATE `creature_text` SET `sound`=0 WHERE entry=19220 AND `groupid`=1 AND `id`=1;
UPDATE `creature_text` SET `sound`=0 WHERE entry=30243 AND `groupid`=0 AND `id`=8;

UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `unit_flags`=4096 WHERE `entry`=13099;
UPDATE `creature_template` SET `exp`=1, `speed_walk`=1, `RangeAttackTime`=2000 WHERE `entry`=22741;
UPDATE `creature_template` SET `exp`=2, `speed_walk`=1, `RangeAttackTime`=2000 WHERE `entry`=32012;
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `exp`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=4096, `MovementType`=1, `flags_extra`=2 WHERE `entry`=37331;

UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `unit_flags`=4096 WHERE `entry`=13179;
UPDATE `creature_template` SET `exp`=1, `speed_walk`=1, `RangeAttackTime`=2000 WHERE `entry`=22721;
UPDATE `creature_template` SET `exp`=2, `speed_walk`=1, `RangeAttackTime`=2000 WHERE `entry`=31828;
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `exp`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=4096, `MovementType`=1, `flags_extra`=2 WHERE `entry`=37479;

UPDATE `creature_template` SET `minlevel`=55, `maxlevel`=55, `unit_flags`=4096 WHERE `entry`=13284;
UPDATE `creature_template` SET `exp`=1, `speed_walk`=1, `RangeAttackTime`=2000 WHERE `entry`=22678;
UPDATE `creature_template` SET `exp`=2, `speed_walk`=1, `RangeAttackTime`=2000 WHERE `entry`=31989;
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `exp`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=4096, `MovementType`=1, `flags_extra`=2 WHERE `entry`=37308;

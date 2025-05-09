-- King Mukla (Area: -Jaguero Isle- - Difficulty: 0)
UPDATE `creature` SET `position_x`=-14721.4853515625, `position_y`=-389.7718505859375, `position_z`=8.1319427490234375, `orientation`=3.83042454719543457, `wander_distance`=30, `MovementType`=1, `VerifiedBuild`=60141 WHERE `guid`=823 and `id`=1559;
UPDATE `creature_template_addon` SET `PvpFlags`=0 WHERE `entry`=1559;
UPDATE `creature_template` SET `speed_walk`=4/2.5, `speed_run`=7.5/7 WHERE `entry`=1559;

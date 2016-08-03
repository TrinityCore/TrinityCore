-- Garhal (Examples To Be Made quest target): Add CREATURE_FLAG_EXTRA_NO_PLAYER_DAMAGE_REQ, spawn time = 60 seconds; closes #16084
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|2097152 WHERE `entry`=30147;
UPDATE `creature` SET `spawntimesecs`=60 WHERE `guid`=114369;

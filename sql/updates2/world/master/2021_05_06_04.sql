UPDATE `creature_template` SET unit_flags=0, unit_flags2=2048, unit_flags3=0, type_flags2=0, InhabitType=8 WHERE entry IN (160737);
DELETE FROM `creature_template_addon` WHERE entry IN (160737);
UPDATE `creature_template` SET `KillCredit1`='155607' WHERE  `entry`=160664;

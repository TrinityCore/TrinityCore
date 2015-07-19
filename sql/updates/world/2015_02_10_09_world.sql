--
UPDATE `creature_template` SET `unit_class`=4 WHERE  `entry`=32535;
UPDATE `creature_template_addon` SET`auras`="" WHERE`entry` IN (26608, 31306); -- vehicle auras appear only when the npc ride a vehicle or when he's mounted
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=35427;

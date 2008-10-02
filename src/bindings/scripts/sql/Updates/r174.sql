-- multikill creatures
UPDATE `creature_template` SET `ScriptName` = 'mobs_dragonmaw_orc' WHERE `entry` IN (21717, 21718, 21719, 21720, 22331);
UPDATE `creature_template` SET `ScriptName` = 'mobs_shadowmoon_valley_wildlife' WHERE `entry` IN (21878, 21879);
UPDATE `creature_template` SET `ScriptName` = 'mobs_gordunni_ogre' WHERE `entry` IN (22143, 22144, 22148, 23022);
-- vendor
UPDATE `creature_template` SET `ScriptName` = 'npc_drake_dealer_hurlunk' WHERE `entry` = 23489;
UPDATE `creature_template` SET `ScriptName` = 'npc_rivern_frostwind' WHERE `entry` = 10618;


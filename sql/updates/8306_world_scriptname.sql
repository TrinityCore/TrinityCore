--
-- Update basic NPC guards to use a common AI - gossip now handled in database
--
-- guard_azuremyst -> guard_generic
UPDATE `creature_template` SET `ScriptName` = 'guard_generic' WHERE `entry` IN (18038);
-- guard_bluffwatcher -> guard_generic
UPDATE `creature_template` SET `ScriptName` = 'guard_generic' WHERE `entry` IN (3084);
-- guard_contested -> guard_generic
UPDATE `creature_template` SET `ScriptName` = 'guard_generic' WHERE `entry` IN (3502,4624,9460,11190,15184);
-- guard_darnassus -> guard_generic
UPDATE `creature_template` SET `ScriptName` = 'guard_generic' WHERE `entry` IN (4262);
-- guard_dunmorogh -> guard_generic
UPDATE `creature_template` SET `ScriptName` = 'guard_generic' WHERE `entry` IN (727,13076);
-- guard_durotar -> guard_generic
UPDATE `creature_template` SET `ScriptName` = 'guard_generic' WHERE `entry` IN (5953);
-- guard_elwynnforest -> guard_generic
UPDATE `creature_template` SET `ScriptName` = 'guard_generic' WHERE `entry` IN (1423);
-- guard_eversong -> guard_generic
UPDATE `creature_template` SET `ScriptName` = 'guard_generic' WHERE `entry` IN (16221);
-- guard_exodar -> guard_generic
UPDATE `creature_template` SET `ScriptName` = 'guard_generic' WHERE `entry` IN (16733);
-- guard_ironforge -> guard_generic
UPDATE `creature_template` SET `ScriptName` = 'guard_generic' WHERE `entry` IN (5595);
-- guard_mulgore -> guard_generic
UPDATE `creature_template` SET `ScriptName` = 'guard_generic' WHERE `entry` IN (3212,3215,3217,3218,3219,3220,3221,3222,3223,3224);
-- guard_shattrath -> guard_generic
UPDATE `creature_template` SET `ScriptName` = 'guard_generic' WHERE `entry` IN (19687);
-- guard_silvermoon -> guard_generic
UPDATE `creature_template` SET `ScriptName` = 'guard_generic' WHERE `entry` IN (16222);
-- guard_teldrassil -> guard_generic
UPDATE `creature_template` SET `ScriptName` = 'guard_generic' WHERE `entry` IN (3571);
-- guard_tirisfal -> guard_generic
UPDATE `creature_template` SET `ScriptName` = 'guard_generic' WHERE `entry` IN (1735,1738,1742,1743,1744,1745,1746,2209,2210,5725);
-- guard_undercity -> guard_generic
UPDATE `creature_template` SET `ScriptName` = 'guard_generic' WHERE `entry` IN (5624);
--
-- Update (remove) scripts from NPCs that had gossip - gossip now handled in database (AI removed)
--
-- NPC Surristrasz
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` IN (24795);
-- NPC Tiare
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` IN (30051);
-- NPC Fizzcrank Fullthrottle
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` IN (25590);

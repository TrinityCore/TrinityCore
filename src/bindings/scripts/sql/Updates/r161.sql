-- shadow labyrinth
UPDATE `instance_template` SET `script` = 'instance_shadow_labyrinth' WHERE `map`= 555;
UPDATE `creature_template` SET `ScriptName` = 'boss_murmur' WHERE `entry` = 18708;
UPDATE `creature_template` SET `ScriptName` = 'boss_ambassador_hellmaw' WHERE `entry` = 18731;
UPDATE `creature_template` SET `ScriptName` = 'boss_grandmaster_vorpil' WHERE `entry` = 18732;
UPDATE `creature_template` SET `ScriptName` = 'boss_blackheart_the_inciter' WHERE `entry` = 18667;

-- fathomlord karathress
UPDATE `creature_template` SET `ScriptName` = 'boss_fathomlord_karathress' WHERE `entry`=21214;
UPDATE `creature_template` SET `ScriptName` = 'boss_fathomguard_sharkkis' WHERE `entry`=21966;
UPDATE `creature_template` SET `ScriptName` = 'boss_fathomguard_tidalvess' WHERE `entry`=21965;
UPDATE `creature_template` SET `ScriptName` = 'boss_fathomguard_caribdis' WHERE `entry`=21964;

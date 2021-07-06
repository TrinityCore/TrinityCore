UPDATE `creature_template` SET `ScriptName`= 'npc_sfk_worgen_spirit' WHERE `entry` IN (50851, 50857, 50869, 50834);
UPDATE `creature_template_addon` SET `auras`= '93853 7486' WHERE `entry` IN (50869, 51034);
UPDATE `creature_template` SET `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry` IN (50852, 51086, 51034, 50835);
UPDATE `creature_template` SET `DamageModifier`= 5, `BaseVariance`= 0.5 WHERE `entry`= 50924;

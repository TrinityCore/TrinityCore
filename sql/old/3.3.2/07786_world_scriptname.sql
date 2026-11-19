-- Alterac Valley
-- ScriptName update to bosses, marshals and warmasters
UPDATE `creature_template` SET `ScriptName`= 'boss_drekthar' WHERE `entry`=11946;
UPDATE `creature_template` SET `ScriptName`= 'boss_vanndar' WHERE `entry`=11948;
UPDATE `creature_template` SET `ScriptName`= 'boss_balinda' WHERE `entry`=11949;
UPDATE `creature_template` SET `ScriptName`= 'mob_water_elemental' WHERE `entry`=25040;
UPDATE `creature_template` SET `ScriptName`= 'boss_galvangar' WHERE `entry`=11947;
UPDATE `creature_template` SET `ScriptName`= 'mob_av_marshal_or_warmaster' WHERE `entry` IN (14762,14763,14764,14765,14772,14773,14776,14777);

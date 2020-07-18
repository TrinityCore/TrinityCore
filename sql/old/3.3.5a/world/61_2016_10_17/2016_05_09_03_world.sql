SET @MODIFIER := 50;
UPDATE `creature_template` SET `mechanic_immune_mask`=617299839, `DamageModifier`=@MODIFIER WHERE `entry` IN (35403,35405);
UPDATE `creature_template` SET `mechanic_immune_mask`=617299839, `ScriptName`='boss_ioc_horde_alliance' WHERE `entry` IN (34922,34924);

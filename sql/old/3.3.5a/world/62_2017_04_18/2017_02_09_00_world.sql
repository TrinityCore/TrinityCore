-- Phantom Mammoth 
DELETE FROM `creature` WHERE `guid`=127005; -- shouldn't stand all the time
UPDATE `creature_template` SET `flags_extra` = `flags_extra`&0x2 WHERE `entry`=29748; -- set visible to players
-- Mojo Frenzy
DELETE FROM `spell_script_names` WHERE `ScriptName` = "spell_moorabi_mojo_frenzy";
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(55163, "spell_moorabi_mojo_frenzy");

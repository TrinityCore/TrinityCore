-- Update Flags - they use no_uninteractable feign death but have uninteractable - so we set them in DB
UPDATE `creature` SET `unit_flags2` = 0x02000000 WHERE `guid` IN (651611,651612,651613,651614,651615,651616,651617,651618,651619);

-- Update ScriptName
UPDATE `spell_script_names` SET `ScriptName` = 'spell_gen_feign_death_all_flags_no_uninteractible' WHERE `spell_id` = 29266;

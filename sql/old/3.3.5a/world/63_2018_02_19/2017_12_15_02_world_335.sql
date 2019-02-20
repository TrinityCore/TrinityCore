DELETE FROM `spell_ranks` WHERE `first_spell_id`=60096;
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_bullet_controller','spell_tar_blaze','spell_overload_circuit','spell_razorscale_fuse_armor','spell_mage_mirror_image','spell_dru_frenzied_regeneration','spell_rog_overkill','spell_rog_master_of_subtlety','spell_hun_explosive_shot','spell_hun_feeding_frenzy','spell_sha_astral_shift_visual_dummy','spell_dk_hysteria');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(66149, 'spell_bullet_controller'),
(68396, 'spell_bullet_controller'),
(62292, 'spell_tar_blaze'),
(62399, 'spell_overload_circuit'),
(64821, 'spell_razorscale_fuse_armor'),
(55342, 'spell_mage_mirror_image'),
(22842, 'spell_dru_frenzied_regeneration'),
(31666, 'spell_rog_master_of_subtlety'),
(58428, 'spell_rog_overkill'),
(-53301,'spell_hun_explosive_shot'),
(-53511,'spell_hun_feeding_frenzy'),
(52179, 'spell_sha_astral_shift_visual_dummy'),
(49016, 'spell_dk_hysteria');

DELETE FROM spell_script_names WHERE scriptname IN ("spell_pal_art_of_war",
                                                    "spell_pal_divine_hammer",
                                                    "spell_pal_divine_intervention",
                                                    "spell_pal_execute_sentence",
                                                    "spell_pal_holy_wrath",
                                                    "spell_pal_judgment_of_light",
                                                    "spell_pal_judgment_of_light_proc",
                                                    "spell_pal_zeal",
                                                    "spell_pal_proc_from_holy_power_consumption",
                                                    "spell_pal_inquisition",
                                                    "spell_pal_righteous_verdict",
                                                    "spell_pal_wake_of_ashes",
                                                    "spell_pal_fervent_martyr",
                                                    "spell_pal_awakening"
                                                    );
INSERT INTO spell_script_names VALUES
(267344, "spell_pal_art_of_war"),
(271580, "spell_pal_proc_from_holy_power_consumption"),
(85804, "spell_pal_proc_from_holy_power_consumption"),
(84963, "spell_pal_inquisition"),
(267610, "spell_pal_righteous_verdict"),
(205290, "spell_pal_wake_of_ashes"),
(248033, "spell_pal_awakening");

DELETE FROM `spell_proc` WHERE `SpellId` IN (267610, 269569, 281178);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask2`, `SpellFamilyMask3`, `SpellPhaseMask`) VALUES
(267610, 10, 8192, 0,           2),
(269569, 10, 2,    0,           2),
(281178, 10, 0,    1073741824,  2);

UPDATE creature_template SET scriptname = "npc_pet_warlock_darkglare" WHERE entry = 103673;

DELETE FROM spell_script_names WHERE scriptname IN ("spell_warl_summon_darkglare",
                                                    "spell_warl_grimoire_of_service_aura",
                                                    "spell_warl_soul_harvest",
                                                    "spell_warl_demonic_empowerment"
                                                    "spell_warl_demonwrath",
                                                    "spell_warl_demonwrath_periodic"
                                                    );
INSERT INTO spell_script_names VALUES
(205180, "spell_warl_summon_darkglare");

-- Eat Slime Puddle
REPLACE INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
('13', '70346', '18', '1', '37672', 'Mutated Abomination - Eat Slime Puddle'),
('13', '72456', '18', '1', '38285', 'Mutated Abomination - Eat Slime Puddle'),
('13', '72868', '18', '1', '37672', 'Mutated Abomination - Eat Slime Puddle'),
('13', '72869', '18', '1', '38285', 'Mutated Abomination - Eat Slime Puddle');

UPDATE `creature_template` SET `AIName` = 'PassiveAI', `flags_extra` = 2 WHERE `entry` IN (38309, 38308);
UPDATE `creature_template` SET `unit_flags` = 33554688 WHERE `entry` IN (36678, 38431, 38585, 38586);
DELETE FROM `creature_template_addon` WHERE `entry` IN (37133, 38133, 37127, 37134, 37132, 38125, 38126, 38131, 38132, 38133, 38130, 37122, 37123, 37124, 37125, 38298, 38299, 38303, 38304);


/* AREA TRIGGERS */
REPLACE INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES 
(5604, 'at_sindragosa_lair'),
(5698, 'at_icc_saurfang_portal'),
(5649, 'at_icc_shutdown_traps'),
(5729, 'at_icc_start_blood_quickening'),
(5616,'at_icc_start_frostwing_gauntlet'),
(5617,'at_icc_start_frostwing_gauntlet'),
(5618,'at_icc_start_frostwing_gauntlet');

/* SCRIP NAMES */
UPDATE `instance_template` SET `script`='instance_icecrown_citadel' WHERE `map`=631;
UPDATE `gameobject_template` SET `ScriptName`='icecrown_citadel_teleport' WHERE `entry` IN (202223,202235,202242,202243,202244,202245,202246);
UPDATE `creature_template` SET `ScriptName`='npc_highlord_tirion_fordring_lh' WHERE `entry`=37119;
UPDATE `creature_template` SET `ScriptName`='boss_lord_marrowgar' WHERE `entry`=36612;
UPDATE `creature_template` SET `ScriptName`='npc_coldflame' WHERE `entry`=36672;
UPDATE `creature_template` SET `ScriptName`='npc_bone_spike' WHERE `entry` IN (36619,38711,38712);
UPDATE `creature_template` SET `ScriptName`='boss_lady_deathwhisper' WHERE `entry`=36855;
UPDATE `creature_template` SET `ScriptName`='npc_cult_fanatic' WHERE `entry` IN (37890,38009,38135);
UPDATE `creature_template` SET `ScriptName`='npc_cult_adherent' WHERE `entry` IN(37949,38010,38136);
UPDATE `creature_template` SET `ScriptName`='npc_vengeful_shade' WHERE `entry`=38222;
UPDATE `creature_template` SET `ScriptName`='npc_darnavan' WHERE `entry` IN (38472,38485);
UPDATE `creature_template` SET `ScriptName`='npc_rotting_frost_giant' WHERE `entry` IN (38490,38494);
UPDATE `creature_template` SET `ScriptName`='boss_deathbringer_saurfang' WHERE `entry`=37813;
UPDATE `creature_template` SET `ScriptName`='npc_high_overlord_saurfang_icc' WHERE `entry`=37187;
UPDATE `creature_template` SET `ScriptName`='npc_muradin_bronzebeard_icc' WHERE `entry`=37200;
UPDATE `creature_template` SET `ScriptName`='npc_saurfang_event' WHERE `entry` IN (37920,37830);
UPDATE `creature_template` SET `ScriptName`='npc_frost_freeze_trap' WHERE `entry`=37744;
UPDATE `creature_template` SET `ScriptName`='npc_alchemist_adrianna' WHERE `entry`=38501;
UPDATE `creature_template` SET `ScriptName`='boss_festergut' WHERE `entry`=36626;
UPDATE `creature_template` SET `ScriptName`='npc_stinky_icc' WHERE `entry`=37025;
UPDATE `creature_template` SET `ScriptName`='boss_rotface' WHERE `entry`=36627;
UPDATE `creature_template` SET `ScriptName`='npc_little_ooze' WHERE `entry`=36897;
UPDATE `creature_template` SET `ScriptName`='npc_big_ooze' WHERE `entry`=36899;
UPDATE `creature_template` SET `ScriptName`='npc_precious_icc' WHERE `entry`=37217;
UPDATE `creature_template` SET `ScriptName`='boss_professor_putricide' WHERE `entry`=36678;
UPDATE `creature_template` SET `ScriptName`='npc_volatile_ooze' WHERE `entry`=37697;
UPDATE `creature_template` SET `ScriptName`='boss_blood_council_controller' WHERE `entry`=38008;
UPDATE `creature_template` SET `ScriptName`='boss_prince_keleseth_icc' WHERE `entry`=37972;
UPDATE `creature_template` SET `ScriptName`='boss_prince_taldaram_icc' WHERE `entry`=37973;
UPDATE `creature_template` SET `ScriptName`='boss_prince_valanar_icc' WHERE `entry`=37970;
UPDATE `creature_template` SET `ScriptName`='npc_blood_queen_lana_thel' WHERE `entry`=38004;
UPDATE `creature_template` SET `ScriptName`='npc_kinetic_bomb' WHERE `entry`=38454;
UPDATE `creature_template` SET `ScriptName`='npc_dark_nucleus' WHERE `entry`=38369;
UPDATE `creature_template` SET `ScriptName`='npc_ball_of_flame' WHERE `entry` IN (38332,38451);
UPDATE `creature_template` SET `ScriptName`='boss_blood_queen_lana_thel' WHERE `entry`=37955;
UPDATE `creature_template` SET `ScriptName`='boss_sister_svalna' WHERE `entry`=37126;
UPDATE `creature_template` SET `ScriptName`='npc_crok_scourgebane' WHERE `entry`=37129;
UPDATE `creature_template` SET `ScriptName`='npc_captain_arnath' WHERE `entry`=37122;
UPDATE `creature_template` SET `ScriptName`='npc_captain_brandon' WHERE `entry`=37123;
UPDATE `creature_template` SET `ScriptName`='npc_captain_grondel' WHERE `entry`=37124;
UPDATE `creature_template` SET `ScriptName`='npc_captain_rupert' WHERE `entry`=37125;
UPDATE `creature_template` SET `ScriptName`='npc_frostwing_vrykul' WHERE `entry` IN (37132,38125,37127,37134,37133);
UPDATE `creature_template` SET `ScriptName`='npc_impaling_spear' WHERE `entry`=38248;
UPDATE `creature_template` SET `ScriptName`='boss_valithria_dreamwalker' WHERE `entry`=36789;
UPDATE `creature_template` SET `ScriptName`='npc_green_dragon_combat_trigger' WHERE `entry`=38752;
UPDATE `creature_template` SET `ScriptName`='npc_the_lich_king_controller' WHERE `entry`=16980;
UPDATE `creature_template` SET `ScriptName`='npc_risen_archmage' WHERE `entry`=37868;
UPDATE `creature_template` SET `ScriptName`='npc_blazing_skeleton' WHERE `entry`=36791;
UPDATE `creature_template` SET `ScriptName`='npc_suppresser' WHERE `entry`=37863;
UPDATE `creature_template` SET `ScriptName`='npc_blistering_zombie' WHERE `entry`=37934;
UPDATE `creature_template` SET `ScriptName`='npc_gluttonous_abomination' WHERE `entry`=37886;
UPDATE `creature_template` SET `ScriptName`='npc_dream_portal' WHERE `entry` IN (37945,38430);
UPDATE `creature_template` SET `ScriptName`='npc_dream_cloud' WHERE `entry` IN (37985,38421);
UPDATE `creature_template` SET `ScriptName`='boss_sindragosa' WHERE `entry`=36853;
UPDATE `creature_template` SET `ScriptName`='npc_ice_tomb' WHERE `entry`=36980;
UPDATE `creature_template` SET `ScriptName`='npc_spinestalker' WHERE `entry`=37534;
UPDATE `creature_template` SET `ScriptName`='npc_rimefang_icc' WHERE `entry`=37533;
UPDATE `creature_template` SET `ScriptName`='npc_sindragosa_trash' WHERE `entry` IN (37531,37532);

REPLACE INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
( 69057, 'spell_marrowgar_bone_spike_graveyard'),
( 70826, 'spell_marrowgar_bone_spike_graveyard'),
( 72088, 'spell_marrowgar_bone_spike_graveyard'),
( 72089, 'spell_marrowgar_bone_spike_graveyard'),
( 69140, 'spell_marrowgar_coldflame'),
( 72705, 'spell_marrowgar_coldflame'),
( 69146, 'spell_marrowgar_coldflame_damage'),
( 70823, 'spell_marrowgar_coldflame_damage'),
( 70824, 'spell_marrowgar_coldflame_damage'),
( 70825, 'spell_marrowgar_coldflame_damage'),
( 69075, 'spell_marrowgar_bone_storm'),
( 70834, 'spell_marrowgar_bone_storm'),
( 70835, 'spell_marrowgar_bone_storm'),
( 70836, 'spell_marrowgar_bone_storm'),
( 70842, 'spell_deathwhisper_mana_barrier'),
( 70903, 'spell_cultist_dark_martyrdom'),
( 72498, 'spell_cultist_dark_martyrdom'),
( 72499, 'spell_cultist_dark_martyrdom'),
( 72500, 'spell_cultist_dark_martyrdom'),
( 71236, 'spell_cultist_dark_martyrdom'),
( 72495, 'spell_cultist_dark_martyrdom'),
( 72496, 'spell_cultist_dark_martyrdom'),
( 72497, 'spell_cultist_dark_martyrdom'),
( 72864, 'spell_frost_giant_death_plague'),
( 72202, 'spell_deathbringer_blood_link'),
( 72178, 'spell_deathbringer_blood_link_aura'),
( 72371, 'spell_deathbringer_blood_power'),
( 72409, 'spell_deathbringer_rune_of_blood'),
( 72447, 'spell_deathbringer_rune_of_blood'),
( 72448, 'spell_deathbringer_rune_of_blood'),
( 72449, 'spell_deathbringer_rune_of_blood'),
( 72380, 'spell_deathbringer_blood_nova'),
( 72438, 'spell_deathbringer_blood_nova'),
( 72439, 'spell_deathbringer_blood_nova'),
( 72440, 'spell_deathbringer_blood_nova'),
( 72378, 'spell_deathbringer_blood_nova_targeting'),
( 73058, 'spell_deathbringer_blood_nova_targeting'),
( 72255, 'spell_deathbringer_mark_of_the_fallen_champion'),
( 72444, 'spell_deathbringer_mark_of_the_fallen_champion'),
( 72445, 'spell_deathbringer_mark_of_the_fallen_champion'),
( 72446, 'spell_deathbringer_mark_of_the_fallen_champion'),
( 72155, 'spell_icc_harvest_blight_specimen'),
( 72162, 'spell_icc_harvest_blight_specimen'),
( 71123, 'spell_stinky_precious_decimate'),
( 73032, 'spell_festergut_pungent_blight'),
( 73031, 'spell_festergut_pungent_blight'),
( 71219, 'spell_festergut_pungent_blight'),
( 69195, 'spell_festergut_pungent_blight'),
( 72219, 'spell_festergut_gastric_bloat'),
( 72551, 'spell_festergut_gastric_bloat'),
( 72552, 'spell_festergut_gastric_bloat'),
( 72553, 'spell_festergut_gastric_bloat'),
( 69290, 'spell_festergut_blighted_spores'),
( 71222, 'spell_festergut_blighted_spores'),
( 73033, 'spell_festergut_blighted_spores'),
( 73034, 'spell_festergut_blighted_spores'),
( 69159, 'spell_festergut_gaseous_blight'),
( 70135, 'spell_festergut_gaseous_blight'),
( 70136, 'spell_festergut_gaseous_blight'),
( 70137, 'spell_festergut_gaseous_blight'),
( 69161, 'spell_festergut_gaseous_blight'),
( 70138, 'spell_festergut_gaseous_blight'),
( 70139, 'spell_festergut_gaseous_blight'),
( 70140, 'spell_festergut_gaseous_blight'),
( 69163, 'spell_festergut_gaseous_blight'),
( 70468, 'spell_festergut_gaseous_blight'),
( 70469, 'spell_festergut_gaseous_blight'),
( 70470, 'spell_festergut_gaseous_blight'),
( 69782, 'spell_rotface_ooze_flood'),
( 69796, 'spell_rotface_ooze_flood'),
( 69798, 'spell_rotface_ooze_flood'),
( 69801, 'spell_rotface_ooze_flood'),
( 69538, 'spell_rotface_little_ooze_combine'),
( 69553, 'spell_rotface_large_ooze_combine'),
( 69610, 'spell_rotface_large_ooze_buff_combine'),
( 69839, 'spell_rotface_unstable_ooze_explosion_init'),
( 69832, 'spell_rotface_unstable_ooze_explosion'),
( 71441, 'spell_rotface_unstable_ooze_explosion_suicide'),
( 69507, 'spell_rotface_slime_spray'),
( 71213, 'spell_rotface_slime_spray'),
( 73189, 'spell_rotface_slime_spray'),
( 73190, 'spell_rotface_slime_spray'),
( 70701, 'spell_putricide_expunged_gas'),
( 70343, 'spell_putricide_slime_puddle'),
( 70351, 'spell_putricide_unstable_experiment'),
( 71966, 'spell_putricide_unstable_experiment'),
( 71967, 'spell_putricide_unstable_experiment'),
( 71968, 'spell_putricide_unstable_experiment'),
( 71412, 'spell_putricide_ooze_summon'),
( 71415, 'spell_putricide_ooze_summon'),
( 70672, 'spell_putricide_gaseous_bloat'),
( 72455, 'spell_putricide_gaseous_bloat'),
( 72832, 'spell_putricide_gaseous_bloat'),
( 72833, 'spell_putricide_gaseous_bloat'),
( 70447, 'spell_putricide_ooze_channel'),
( 72836, 'spell_putricide_ooze_channel'),
( 72837, 'spell_putricide_ooze_channel'),
( 72838, 'spell_putricide_ooze_channel'),
( 70672, 'spell_putricide_ooze_channel'),
( 72455, 'spell_putricide_ooze_channel'),
( 72832, 'spell_putricide_ooze_channel'),
( 72833, 'spell_putricide_ooze_channel'),
( 70459, 'spell_putricide_ooze_eruption_searcher'),
( 71255, 'spell_putricide_choking_gas_bomb'),
( 70920, 'spell_putricide_unbound_plague'),
( 70360, 'spell_putricide_eat_ooze'),
( 72527, 'spell_putricide_eat_ooze'),
( 72451, 'spell_putricide_mutated_plague'),
( 72463, 'spell_putricide_mutated_plague'),
( 72671, 'spell_putricide_mutated_plague'),
( 72672, 'spell_putricide_mutated_plague'),
( 70308, 'spell_putricide_mutation_init'),
( 70311, 'spell_putricide_mutated_transformation'),
( 71503, 'spell_putricide_mutated_transformation'),
( 70405, 'spell_putricide_mutated_transformation_dismiss'),
( 72508, 'spell_putricide_mutated_transformation_dismiss'),
( 72509, 'spell_putricide_mutated_transformation_dismiss'),
( 72510, 'spell_putricide_mutated_transformation_dismiss'),
( 70402, 'spell_putricide_mutated_transformation_dmg'),
( 72511, 'spell_putricide_mutated_transformation_dmg'),
( 72512, 'spell_putricide_mutated_transformation_dmg'),
( 72513, 'spell_putricide_mutated_transformation_dmg'),
( 70539, 'spell_putricide_regurgitated_ooze'),
( 72457, 'spell_putricide_regurgitated_ooze'),
( 72875, 'spell_putricide_regurgitated_ooze'),
( 72876, 'spell_putricide_regurgitated_ooze'),
( 71598, 'spell_creature_permanent_feign_death'),
( 71806, 'spell_taldaram_glittering_sparks'),
( 71718, 'spell_taldaram_summon_flame_ball'),
( 72040, 'spell_taldaram_summon_flame_ball'),
( 55891, 'spell_taldaram_flame_ball_visual'),
( 55947, 'spell_taldaram_flame_ball_visual'),
( 71756, 'spell_taldaram_ball_of_inferno_flame'),
( 72782, 'spell_taldaram_ball_of_inferno_flame'),
( 72783, 'spell_taldaram_ball_of_inferno_flame'),
( 72784, 'spell_taldaram_ball_of_inferno_flame'),
( 72080, 'spell_valanar_kinetic_bomb'),
( 72087, 'spell_valanar_kinetic_bomb_knockback'),
( 72054, 'spell_valanar_kinetic_bomb_absorb'),
( 73001, 'spell_blood_council_shadow_prison'),
( 72999, 'spell_blood_council_shadow_prison_damage'),
( 70877, 'spell_blood_queen_frenzied_bloodthirst'),
( 71474, 'spell_blood_queen_frenzied_bloodthirst'),
( 70946, 'spell_blood_queen_vampiric_bite'),
( 71475, 'spell_blood_queen_vampiric_bite'),
( 71476, 'spell_blood_queen_vampiric_bite'),
( 71477, 'spell_blood_queen_vampiric_bite'),
( 71899, 'spell_blood_queen_bloodbolt'),
( 71900, 'spell_blood_queen_bloodbolt'),
( 71901, 'spell_blood_queen_bloodbolt'),
( 71902, 'spell_blood_queen_bloodbolt'),
( 71390, 'spell_blood_queen_pact_of_the_darkfallen'),
( 71340, 'spell_blood_queen_pact_of_the_darkfallen_dmg'),
( 71341, 'spell_blood_queen_pact_of_the_darkfallen_dmg_target'),
( 70078, 'spell_svalna_caress_of_death'),
( 70053, 'spell_svalna_revive_champion'),
( 71462, 'spell_svalna_remove_spear'),
( 71085, 'spell_dreamwalker_mana_void'),
( 70915, 'spell_dreamwalker_decay_periodic_timer'),
( 70912, 'spell_dreamwalker_decay_periodic_timer'),
( 70916, 'spell_dreamwalker_decay_periodic_timer'),
( 70913, 'spell_dreamwalker_decay_periodic_timer'),
( 70921, 'spell_dreamwalker_summoner'),
( 70912, 'spell_dreamwalker_summon_suppresser'),
( 71032, 'spell_dreamwalker_summoner'),
( 71078, 'spell_dreamwalker_summoner'),
( 70933, 'spell_dreamwalker_summoner'),
( 72224, 'spell_dreamwalker_summon_dream_portal'),
( 72480, 'spell_dreamwalker_summon_nightmare_portal'),
( 71970, 'spell_dreamwalker_nightmare_cloud'),
( 72868, 'spell_putricide_slime_puddle_aura'),
( 72869, 'spell_putricide_slime_puddle_aura'),
( 71357, 'spell_frostwarden_handler_order_whelp'),
( 71350, 'spell_frostwarden_handler_focus_fire'),
( 71376, 'spell_rimefang_icy_blast'),
( 70598, 'spell_sindragosa_s_fury'),
( 69762, 'spell_sindragosa_unchained_magic'),
( 69766, 'spell_sindragosa_instability'),
( 70126, 'spell_sindragosa_frost_beacon'),
( 69712, 'spell_sindragosa_ice_tomb'),
( 69675, 'spell_sindragosa_ice_tomb_dummy'),
( 70157, 'spell_sindragosa_ice_tomb_trap'),
( 69845, 'spell_sindragosa_collision_filter'),
( 71053, 'spell_sindragosa_collision_filter'),
( 71054, 'spell_sindragosa_collision_filter'),
( 71055, 'spell_sindragosa_collision_filter'),
( 70127, 'spell_sindragosa_collision_filter'),
( 72528, 'spell_sindragosa_collision_filter'),
( 72529, 'spell_sindragosa_collision_filter'),
( 72530, 'spell_sindragosa_collision_filter'),
( 70117, 'spell_sindragosa_collision_filter'),
( 70117, 'spell_sindragosa_icy_grip'),
( 70733, 'spell_icc_stoneform'),
( 70546, 'spell_icc_sprit_alarm'),
( 70536, 'spell_icc_sprit_alarm'),
( 70545, 'spell_icc_sprit_alarm'),
( 70547, 'spell_icc_sprit_alarm');

DELETE FROM `creature_text` WHERE `entry` IN (16980,36789,37491,37493,37494,37495);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(16980,0,0,'Intruders have breached the inner sanctum. Hasten the destruction of the green dragon! Leave only bones and sinew for the reanimation!',14,0,0,0,0,17251,'The Lich King - SAY_LICH_KING_INTRO'),
(36789,0,0,'Heroes, lend me your aid. I... I cannot hold them off much longer. You must heal my wounds!',14,0,0,0,0,17064,'Valithria Dreamwalker - SAY_VALITHRIA_ENTER_COMBAT'),
(36789,1,0,'I have opened a portal into the Dream. Your salvation lies within, heroes...',14,0,0,0,0,17068,'Valithria Dreamwalker - SAY_VALITHRIA_DREAM_PORTAL'),
(36789,2,0,'My strength is returning! Press on, heroes!',14,0,0,0,0,17070,'Valithria Dreamwalker - SAY_VALITHRIA_75_PERCENT'),
(36789,3,0,'I will not last much longer!',14,0,0,0,0,17069,'Valithria Dreamwalker - SAY_VALITHRIA_25_PERCENT'),
(36789,4,0,'Forgive me for what I do! I... cannot... stop... ONLY NIGHTMARES REMAIN!',14,0,0,0,0,17072,'Valithria Dreamwalker - SAY_VALITHRIA_DEATH'),
(36789,5,0,'A tragic loss...',14,0,0,0,0,17066,'Valithria Dreamwalker - SAY_VALITHRIA_PLAYER_DEATH'),
(36789,6,0,'FAILURES!',14,0,0,0,0,17067,'Valithria Dreamwalker - SAY_VALITHRIA_BERSERK'),
(36789,7,0,'I am renewed! Ysera grants me the favor to lay these foul creatures to rest!',14,0,0,0,0,17071,'Valithria Dreamwalker - SAY_VALITHRIA_SUCCESS'),
(37491,1,0, 'You miserable fools never did manage to select a decent bat wing.',1,0,0,0,0,16587, 'Captain Arnath - SAY_ARNATH_RESURRECTED'),
(37491,2,0, 'THAT was for bringing me spoiled spider ichor!',1,0,0,0,0,16588, 'Captain Arnath - SAY_ARNATH_KILL'),
(37491,3,0, 'Don''t... let Finklestein use me... for his potions...',1,0,0,0,0,16589, 'Captain Arnath - SAY_ARNATH_SECOND_DEATH'),
(37493,1,0, 'What? This strength...? All of the pain is gone! You... must join me in the eternal embrace of death!',1,0,0,0,0,16811, 'Captain Brandon - SAY_BRANDON_RESURRECTED'),
(37493,2,0, 'It doesn''t hurt anymore, does it?',1,0,0,0,0,16812, 'Captain Brandon - SAY_BRANDON_KILL'),
(37493,3,0, 'I''m sorry...',1,0,0,0,0,16813, 'Captain Brandon - SAY_BRANDON_SECOND_DEATH'),
(37494,1,0, 'No! Why was I denied a death by flame? You must all BURN!',1,0,0,0,0,16845, 'Captain Grondel - SAY_GRONDEL_RESURRECTED'),
(37494,2,0, 'Can you feel the burn?',1,0,0,0,0,16846, 'Captain Grondel - SAY_GRONDEL_KILL'),
(37494,3,0, 'What... have I done? No!',1,0,0,0,0,16847, 'Captain Grondel - SAY_GRONDEL_SECOND_DEATH'),
(37495,1,0, 'There is no escaping the Lich King''s will. Prepare for an explosive encounter!',1,0,0,0,0,16999, 'Captain Rupert - SAY_RUPERT_RESURRECTED'),
(37495,2,0, 'So that''s what happens when you stand too close to a bomb!',1,0,0,0,0,17000, 'Captain Rupert - SAY_RUPERT_KILL'),
(37495,3,0, 'What an... explosive ending!',1,0,0,0,0,17001, 'Captain Rupert - SAY_RUPERT_SECOND_DEATH');

DELETE FROM `creature_text` WHERE `entry`=36853;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(36853,0,0, 'You are fools to have come to this place! The icy winds of Northrend will consume your souls!',1,0,0,0,0,17007, 'Sindragosa - SAY_AGGRO'),
(36853,1,0, 'Suffer, mortals, as your pathetic magic betrays you!',1,0,0,0,0,17014, 'Sindragosa - SAY_UNCHAINED_MAGIC'),
(36853,2,0, '%s prepares to unleash a wave of blistering cold!',3,0,0,0,0,0, 'Sindragosa - EMOTE_WARN_BLISTERING_COLD'),
(36853,3,0, 'Can you feel the cold hand of death upon your heart?',1,0,0,0,0,17013, 'Sindragosa - SAY_BLISTERING_COLD'),
(36853,4,0, 'Aaah! It burns! What sorcery is this?!',1,0,0,0,0,17015, 'Sindragosa - SAY_RESPITE_FOR_A_TORMENTED_SOUL'),
(36853,5,0, 'Your incursion ends here! None shall survive!',1,0,0,0,0,17012, 'Sindragosa - SAY_AIR_PHASE'),
(36853,6,0, 'Now feel my master''s limitless power and despair!',1,0,0,0,0,17016, 'Sindragosa - SAY_PHASE_2'),
(36853,7,0, '%s fires a frozen orb towards $N!',3,0,0,0,0,0, 'Sindragosa - EMOTE_WARN_FROZEN_ORB'),
(36853,8,0, 'Perish!',1,0,0,0,0,17008, 'Sindragosa - SAY_KILL 1'),
(36853,8,1, 'A flaw of mortality...',1,0,0,0,0,17009, 'Sindragosa - SAY_KILL 2'),
(36853,9,0, 'Enough! I tire of these games!',1,0,0,0,0,17011, 'Sindragosa - SAY_BERSERK'),
(36853,10,0, 'Free...at last...',1,0,0,0,0,17010, 'Sindragosa - SAY_DEATH');

-- Teleports
DELETE FROM `npc_text` WHERE `id` BETWEEN 800000 AND 800006;
INSERT INTO `npc_text` (`id`, `text0_0`) VALUES
(800000, 'Teleport to the Light\'s Hammer'),
(800001, 'Teleport to the Oratory of the Damned.'), 
(800002, 'Teleport to the Rampart of Skulls.'),
(800003, 'Teleport to the Deathbringer\'s Rise.'),
(800004, 'Teleport to the Upper Spire.'),
(800005, 'Teleport to the Sindragosa\'s Lair'),
(800006, 'Teleport to The Frozen Throne');
DELETE FROM `locales_npc_text` WHERE `entry` BETWEEN 800000 AND 800006;
INSERT INTO `locales_npc_text` (`entry`, `Text0_0_loc8`) VALUES
(800000, 'Молот света'),
(800001, 'Молельня проклятых'),
(800002, 'Черепной вал'),
(800003, 'Подъем смертоносного'),
(800004, 'Шпиль'),
(800005, 'Логово Королевы Льда'),
(800006, 'Ледяной трон');

-- [10468] ICC texts (Shauren)
DELETE FROM `creature_text` WHERE `entry` IN (36612,36626,36627,36678,36855,37187,37188,37200,37813,37879,37970,37972,37973,38004);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`sound`,`language`,`probability`,`emote`,`duration`,`comment`) VALUES
(36612,0,0,'This is the beginning AND the end, mortals. None may enter the master''s sanctum!',1,16950,0,0,0,0,'Lord Marrowgar - SAY_ENTER_ZONE'),
(36612,1,0,'The Scourge will wash over this world as a swarm of death and destruction!',1,16941,0,0,0,0,'Lord Marrowgar - SAY_AGGRO'),
(36612,2,0,'BONE STORM!',1,16946,0,0,0,0,'Lord Marrowgar - SAY_BONE_STORM'),
(36612,3,0,'Bound by bone!',1,16947,0,0,0,0,'Lord Marrowgar - SAY_BONESPIKE_1'),
(36612,3,1,'Stick Around!',1,16948,0,0,0,0,'Lord Marrowgar - SAY_BONESPIKE_2'),
(36612,3,2,'The only escape is death!',1,16949,0,0,0,0,'Lord Marrowgar - SAY_BONESPIKE_3'),
(36612,4,0,'More bones for the offering!',1,16942,0,0,0,0,'Lord Marrowgar - SAY_KILL_1'),
(36612,4,1,'Languish in damnation!',1,16943,0,0,0,0,'Lord Marrowgar - SAY_KILL_2'),
(36612,5,0,'I see... only darkness...',1,16944,0,0,0,0,'Lord Marrowgar - SAY_DEATH'),
(36612,6,0,'THE MASTER''S RAGE COURSES THROUGH ME!',1,16945,0,0,0,0,'Lord Marrowgar - SAY_BERSERK'),
(36612,7,0,'Lord Marrowgar creates a whirling storm of bone!',3,0,0,0,0,0,'Lord Marrowgar - SAY_BONE_STORM_EMOTE'),
(36626,0,0,'NOOOO! You kill Stinky! You pay!',1,16907,0,0,0,0,'Festergut - SAY_STINKY_DEAD'),
(36626,1,0,'Fun time!',1,16901,0,0,0,0,'Festergut - SAY_AGGRO'),
(36626,2,0,'%s farts.',2,16911,0,0,0,0,'Festergut - EMOTE_GAS_SPORE'),
(36626,3,0,'%s releases Gas Spores!',3,0,0,0,0,0,'Festergut - EMOTE_WARN_GAS_SPORE'),
(36626,4,0,'Gyah! Uhhh, I not feel so good...',1,16906,0,0,0,0,'Festergut - SAY_PUNGENT_BLIGHT'),
(36626,5,0,'%s begins to cast |cFFFF7F00Pungent Blight!|r',3,0,0,0,0,0,'Festergut - EMOTE_WARN_PUNGENT_BLIGHT'),
(36626,6,0,'%s vomits.',2,0,0,0,0,0,'Festergut - EMOTE_PUNGENT_BLIGHT'),
(36626,7,0,'Daddy, I did it!',1,16902,0,0,0,0,'Festergut - SAY_KILL_1'),
(36626,7,1,'Dead, dead, dead!',1,16903,0,0,0,0,'Festergut - SAY_KILL_2'),
(36626,8,0,'Fun time over!',1,16905,0,0,0,0,'Festergut - SAY_BERSERK'),
(36626,9,0,'Da ... Ddy...',1,16904,0,0,0,0,'Festergut - SAY_DEATH'),
(36627,0,0,'What? Precious? Noooooooooo!!!',1,16993,0,0,0,0,'Rotface - SAY_PRECIOUS_DIES'),
(36627,1,0,'WEEEEEE!',1,16986,0,0,0,0,'Rotface - SAY_AGGRO'),
(36627,2,0,'%s begins to cast Slime Spray!',3,0,0,0,0,0,'Rotface - EMOTE_SLIME_SPRAY'),
(36627,3,0,'Icky sticky.',1,16991,0,0,0,0,'Rotface - SAY_SLIME_SPRAY'),
(36627,4,0,'|TInterfaceIconsspell_shadow_unstableaffliction_2.blp:16|t%s begins to cast |cFFFF0000Unstable Ooze Explosion!|r',3,0,0,0,0,0,'Rotface - EMOTE_UNSTABLE_EXPLOSION'),
(36627,5,0,'I think I made an angry poo-poo. It gonna blow!',1,16992,0,0,0,0,'Rotface - SAY_UNSTABLE_EXPLOSION'),
(36627,6,0,'Daddy make toys out of you!',1,16988,0,0,0,0,'Rotface - SAY_KILL_1'),
(36627,6,1,'I brokes-ded it...',1,16987,0,0,0,0,'Rotface - SAY_KILL_2'),
(36627,7,0,'Sleepy Time!',1,16990,0,0,0,0,'Rotface - SAY_BERSERK'),
(36627,8,0,'Bad news daddy...',1,16989,0,0,0,0,'Rotface - SAY_DEATH'),
(36678,0,0,'Just an ordinary gas cloud. But watch out, because that''s no ordinary gas cloud!',1,17119,0,0,432,0,'Professor Putricide - SAY_GASEOUS_BLIGHT'),
(36678,1,0,'Oh, Festergut. You were always my favorite. Next to Rotface. The good news is you left behind so much gas, I can practically taste it!',1,17124,0,0,0,0,'Professor Putricide - SAY_FESTERGUT_DEATH'),
(36678,2,0,'Great news, everyone! The slime is flowing again!',1,17126,0,0,1,0,'Professor Putricide - SAY_ROTFACE_OOZE_FLOOD1'),
(36678,2,1,'Good news, everyone! I''ve fixed the poison slime pipes!',1,17123,0,0,1,0,'Professor Putricide - SAY_ROTFACE_OOZE_FLOOD2'),
(36678,3,0,'Terrible news, everyone, Rotface is dead! But great news everyone, he left behind plenty of ooze for me to use! Whaa...? I''m a poet, and I didn''t know it? Astounding!',1,17146,0,0,0,0,'Professor Putricide - SAY_ROTFACE_DEATH'),
(36678,4,0,'Good news, everyone! I think I perfected a plague that will destroy all life on Azeroth!',1,17114,0,0,0,0,'Professor Putricide - SAY_AGGRO'),
(36678,5,0,'%s begins to cast Unstable Experiment!',3,0,0,0,0,0,'Professor Putricide - EMOTE_UNSTABLE_EXPERIMENT'),
(36678,6,0,'Two oozes, one room! So many delightful possibilities...',1,17122,0,0,0,0,'Professor Putricide - SAY_PHASE_TRANSITION_HEROIC'),
(36678,7,0,'Hmm. I don''t feel a thing. Whaa...? Where''d those come from?',1,17120,0,0,15,0,'Professor Putricide - SAY_TRANSFORM_1'),
(36678,8,0,'Tastes like... Cherry! Oh! Excuse me!',1,17121,0,0,15,0,'Professor Putricide - SAY_TRANSFORM_2'),
(36678,9,0,'|TInterfaceIconsinv_misc_herb_evergreenmoss.blp:16|t%s cast |cFF00FF00Malleable Goo!|r',3,0,0,0,0,0,'Professor Putricide - EMOTE_MALLEABLE_GOO'),
(36678,10,0,'%s cast |cFFFF7F00Choking Gas Bomb!|r',3,0,0,0,0,0,'Professor Putricide - EMOTE_CHOKING_GAS_BOMB'),
(36678,11,0,'Hmm... Interesting...',1,17115,0,0,0,0,'Professor Putricide - SAY_KILL_1'),
(36678,11,1,'That was unexpected!',1,17116,0,0,0,0,'Professor Putricide - SAY_KILL_2'),
(36678,12,0,'Great news, everyone!',1,17118,0,0,0,0,'Professor Putricide - SAY_BERSERK'),
(36678,13,0,'Bad news, everyone! I don''t think I''m going to make it.',1,17117,0,0,0,0,'Professor Putricide - SAY_DEATH'),
(36855,0,0,'You have found your way here, because you are among the few gifted with true vision in a world cursed with blindness.',1,17272,0,0,0,0,'Lady Deathwhisper - SAY_INTRO_1'),
(36855,1,0,'You can see through the fog that hangs over this world like a shroud, and grasp where true power lies.',1,17273,0,0,0,0,'Lady Deathwhisper - SAY_INTRO_2'),
(36855,2,0,'Fix your eyes upon your crude hands: the sinew, the soft meat, the dark blood coursing within.',1,16878,0,0,0,0,'Lady Deathwhisper - SAY_INTRO_3'),
(36855,3,0,'It is a weakness; a crippling flaw.... A joke played by the Creators upon their own creations.',1,17268,0,0,0,0,'Lady Deathwhisper - SAY_INTRO_4'),
(36855,4,0,'The sooner you come to accept your condition as a defect, the sooner you will find yourselves in a position to transcend it.',1,17269,0,0,0,0,'Lady Deathwhisper - SAY_INTRO_5'),
(36855,5,0,'Through our Master, all things are possible. His power is without limit, and his will unbending.',1,17270,0,0,0,0,'Lady Deathwhisper - SAY_INTRO_6'),
(36855,6,0,'Those who oppose him will be destroyed utterly, and those who serve -- who serve wholly, unquestioningly, with utter devotion of mind and soul -- elevated to heights beyond your ken.',1,17271,0,0,0,0,'Lady Deathwhisper - SAY_INTRO_7'),
(36855,7,0,'What is this disturbance?! You dare trespass upon this hallowed ground? This shall be your final resting place.',1,16868,0,0,0,0,'Lady Deathwhisper - SAY_AGGRO'),
(36855,8,0,'Enough! I see I must take matters into my own hands!',1,16877,0,0,0,0,'Lady Deathwhisper - SAY_PHASE_2'),
(36855,9,0,'%s''s Mana Barrier shimmers and fades away!',3,0,0,0,0,0,'Lady Deathwhisper - SAY_PHASE_2_EMOTE'),
(36855,10,0,'You are weak, powerless to resist my will!',1,16876,0,0,0,0,'Lady Deathwhisper - SAY_DOMINATE_MIND'),
(36855,11,0,'Take this blessing and show these intruders a taste of our master''s power.',1,16873,0,0,0,0,'Lady Deathwhisper - SAY_DARK_EMPOWERMENT'),
(36855,12,0,'I release you from the curse of flesh!',1,16874,0,0,0,0,'Lady Deathwhisper - SAY_DARK_TRANSFORMATION'),
(36855,13,0,'Arise and exult in your pure form!',1,16875,0,0,0,0,'Lady Deathwhisper - SAY_ANIMATE_DEAD'),
(36855,14,0,'Do you yet grasp of the futility of your actions?',1,16869,0,0,0,0,'Lady Deathwhisper - SAY_KILL_1'),
(36855,14,1,'Embrace the darkness... Darkness eternal!',1,16870,0,0,0,0,'Lady Deathwhisper - SAY_KILL_2'),
(36855,15,0,'This charade has gone on long enough.',1,16872,0,0,0,0,'Lady Deathwhisper - SAY_BERSERK'),
(36855,16,0,'All part of the masters plan! Your end is... inevitable!',1,16871,0,0,0,0,'Lady Deathwhisper - SAY_DEATH'),
(37187,0,0,'Kor''kron, move out! Champions, watch your backs. The Scourge have been...',1,17103,0,0,22,0,'High Overlord Saurfang - SAY_INTRO_HORDE_1'),
(37187,1,0,'My boy died at the Wrath Gate. I am here only to collect his body.',0,17097,0,0,397,0,'High Overlord Saurfang - SAY_INTRO_HORDE_3'),
(37187,2,0,'We named him Dranosh. It means \"Heart of Draenor\" in orcish. I would not let the warlocks take him. My boy would be safe, hidden away by the elders of Garadar.',0,17098,0,0,1,0,'High Overlord Saurfang - SAY_INTRO_HORDE_5'),
(37187,3,0,'I made a promise to his mother before she died; that I would cross the Dark Portal alone - whether I lived or died, my son would be safe. Untainted...',0,17099,0,0,1,0,'High Overlord Saurfang - SAY_INTRO_HORDE_6'),
(37187,4,0,'Today, I fulfill that promise.',0,17100,0,0,397,0,'High Overlord Saurfang - SAY_INTRO_HORDE_7'),
(37187,5,0,'High Overlord Saurfang charges!',2,17104,0,0,53,0,'High Overlord Saurfang - SAY_INTRO_HORDE_8'),
(37187,6,0,'Behind you lies the body of my only son. Nothing will keep me from him.',0,17094,0,0,0,0,'High Overlord Saurfang - SAY_OUTRO_ALLIANCE_8'),
(37187,7,0,'High Overlord Saurfang walks over to his son and kneels before his son''s body.',2,0,0,0,0,0,'High Overlord Saurfang - SAY_OUTRO_ALLIANCE_12'),
(37187,8,0,'[Orcish] No''ku kil zil''nok ha tar.',0,17096,0,0,0,0,'High Overlord Saurfang - SAY_OUTRO_ALLIANCE_13'),
(37187,9,0,'Higher Overlord Saurfang picks up the body of his son and walks over towards Varian',2,0,0,0,0,0,'High Overlord Saurfang - SAY_OUTRO_ALLIANCE_14'),
(37187,10,0,'I will not forget this... kindness. I thank you, Highness',0,17095,0,0,0,0,'High Overlord Saurfang - SAY_OUTRO_ALLIANCE_15'),
(37187,11,0,'%s coughs.',2,17105,0,0,0,0,'High Overlord Saurfang - SAY_OUTRO_HORDE_1'),
(37187,12,0,'%s weeps over the corpse of his son.',2,17106,0,0,15,0,'High Overlord Saurfang - SAY_OUTRO_HORDE_2'),
(37187,13,0,'You will have a proper ceremony in Nagrand next to the pyres of your mother and ancestors.',0,17101,0,0,0,0,'High Overlord Saurfang - SAY_OUTRO_HORDE_3'),
(37187,14,0,'Honor, young heroes... no matter how dire the battle... Never forsake it!',0,17102,0,0,0,0,'High Overlord Saurfang - SAY_OUTRO_HORDE_4'),
(37188,0,0,'%s cries.',2,16651,0,0,18,0,'Lady Jaina Proudmoore - SAY_OUTRO_ALLIANCE_17'),
(37188,1,0,'It was nothing, your majesty. Just... I''m proud of my king.',0,16652,0,0,0,0,'Lady Jaina Proudmoore - SAY_OUTRO_ALLIANCE_19'),
(37200,0,0,'Let''s get a move on then! Move ou...',1,16974,0,0,0,0,'Muradin Bronzebeard - SAY_INTRO_ALLIANCE_1'),
(37200,1,0,'A lone orc against the might of the Alliance???',1,16970,0,0,0,0,'Muradin Bronzebeard - SAY_INTRO_ALLIANCE_4'),
(37200,2,0,'Charge!!!',1,16971,0,0,0,0,'Muradin Bronzebeard - SAY_INTRO_ALLIANCE_5'),
(37200,3,0,'%s gasps for air.',2,16975,0,0,0,0,'Muradin Bronzebeard - SAY_OUTRO_ALLIANCE_1'),
(37200,4,0,'That was Saurfang''s boy - the Horde commander at the Wrath Gate. Such a tragic end...',0,16976,0,0,0,0,'Muradin Bronzebeard - SAY_OUTRO_ALLIANCE_2'),
(37200,5,0,'What in the... There, in the distance!',0,16977,0,0,0,0,'Muradin Bronzebeard - SAY_OUTRO_ALLIANCE_3'),
(37200,6,0,'A Horde Zeppelin flies up to the rise.',2,0,0,0,0,0,'Muradin Bronzebeard - SAY_OUTRO_ALLIANCE_4'),
(37200,7,0,'Soldiers, fall in! Looks like the Horde are comin'' to take another shot!',1,16978,0,0,0,0,'Muradin Bronzebeard - SAY_OUTRO_ALLIANCE_5'),
(37200,8,0,'The Zeppelin docks, and High Overlord Saurfang hops out, confronting the Alliance soldiers and Muradin',2,0,0,0,0,0,'Muradin Bronzebeard - SAY_OUTRO_ALLIANCE_6'),
(37200,9,0,'Don''t force me hand, orc. We can''t let ye pass.',0,16972,0,0,0,0,'Muradin Bronzebeard - SAY_OUTRO_ALLIANCE_7'),
(37200,10,0,'I... I can''t do it. Get back on yer ship and we''ll spare yer life.',0,16973,0,0,0,0,'Muradin Bronzebeard - SAY_OUTRO_ALLIANCE_9'),
(37200,11,0,'A mage portal from Stormwind appears between the two and Varian Wrynn and Jaina Proudmoore emerge.',2,0,0,0,0,0,'Muradin Bronzebeard - SAY_OUTRO_ALLIANCE_10'),
(37200,12,0,'Right away, yer majesty!',0,16979,0,0,0,0,'Muradin Bronzebeard - SAY_OUTRO_ALLIANCE_21'),
(37813,0,0,'For every Horde soldier that you killed -- for every Alliance dog that fell, the Lich King''s armies grew. Even now the val''kyr work to raise your fallen as Scourge.',1,16701,0,0,0,0,'Deathbringer Saurfang - SAY_INTRO_ALLIANCE_2'),
(37813,1,0,'Things are about to get much worse. Come, taste the power that the Lich King has bestowed upon me!',1,16702,0,0,0,0,'Deathbringer Saurfang - SAY_INTRO_ALLIANCE_3'),
(37813,2,0,'Dwarves...',1,16703,0,0,0,0,'Deathbringer Saurfang - SAY_INTRO_ALLIANCE_6'),
(37813,3,0,'%s immobilizes Muradin and his guards.',2,0,0,0,0,0,'Deathbringer Saurfang - SAY_INTRO_ALLIANCE_7'),
(37813,4,0,'Join me, father. Join me and we will crush this world in the name of the Scourge -- for the glory of the Lich King!',1,16704,0,0,0,0,'Deathbringer Saurfang - SAY_INTRO_HORDE_2'),
(37813,5,0,'Stubborn and old. What chance do you have? I am stronger, and more powerful than you ever were.',1,16705,0,0,5,0,'Deathbringer Saurfang - SAY_INTRO_HORDE_4'),
(37813,6,0,'Pathetic old orc. Come then heroes. Come and face the might of the Scourge!',1,16706,0,0,15,0,'Deathbringer Saurfang - SAY_INTRO_HORDE_9'),
(37813,7,0,'BY THE MIGHT OF THE LICH KING!',1,16694,0,0,0,0,'Deathbringer Saurfang - SAY_AGGRO'),
(37813,8,0,'The ground runs red with your blood!',1,16699,0,0,0,0,'Deathbringer Saurfang - SAY_MARK_OF_THE_FALLEN_CHAMPION'),
(37813,9,0,'Feast, my minions!',1,16700,0,0,0,0,'Deathbringer Saurfang - SAY_BLOOD_BEASTS'),
(37813,10,0,'You are nothing!',1,16695,0,0,0,0,'Deathbringer Saurfang - SAY_KILL_1'),
(37813,10,1,'Your soul will find no redemption here!',1,16696,0,0,0,0,'Deathbringer Saurfang - SAY_KILL_2'),
(37813,11,0,'%s goes into frenzy!',3,0,0,0,0,0,'Deathbringer Saurfang - SAY_FRENZY'),
(37813,12,0,'I have become...DEATH!',1,16698,0,0,0,0,'Deathbringer Saurfang - SAY_BERSERK'),
(37813,13,0,'I... Am... Released.',1,16697,0,0,0,0,'Deathbringer Saurfang - SAY_DEATH'),
(37879,0,0,'Stand down, Muradin. Let a grieving father pass.',0,16690,0,0,0,0,'King Varian Wrynn - SAY_OUTRO_ALLIANCE_11'),
(37879,1,0,'I... I was not at the Wrath Gate, but the soldiers who survived told me much of what happened. Your son fought with honor. He died a hero''s death. He deserves a hero''s burial.',0,16691,0,0,0,0,'King Varian Wrynn - SAY_OUTRO_ALLIANCE_16'),
(37879,2,0,'Jaina? Why are you crying?',0,16692,0,0,0,0,'King Varian Wrynn - SAY_OUTRO_ALLIANCE_18'),
(37879,3,0,'Bah! Muradin, secure the deck and prepare our soldiers for an assault on the upper citadel. I''ll send out another regiment from Stormwind.',0,16693,0,0,0,0,'King Varian Wrynn - SAY_OUTRO_ALLIANCE_20'),
(37970,0,0,'Naxxanar was merely a setback! With the power of the orb, Valanar will have his vengeance!',1,16685,0,0,0,0,'Prince Valanar - SAY_VALANAR_INVOCATION'),
(37970,1,0,'Invocation of Blood jumps to Prince Valanar!',3,0,0,0,0,0,'Prince Valanar - EMOTE_VALANAR_INVOCATION'),
(37970,2,0,'My cup runneth over.',1,16686,0,0,0,0,'Prince Valanar - SAY_VALANAR_SPECIAL'),
(37970,3,0,'%s begins casting Empowered Schock Vortex!',3,0,0,0,0,0,'Prince Valanar - EMOTE_VALANAR_SHOCK_VORTEX'),
(37970,4,0,'Dinner... is served.',1,16681,0,0,0,0,'Prince Valanar - SAY_VALANAR_KILL_1'),
(37970,4,1,'Do you see NOW the power of the Darkfallen?',1,16682,0,0,0,0,'Prince Valanar - SAY_VALANAR_KILL_2'),
(37970,5,0,'BOW DOWN BEFORE THE SAN''LAYN!',1,16684,0,0,0,0,'Prince Valanar - SAY_VALANAR_BERSERK'),
(37970,6,0,'...why...?',1,16683,0,0,0,0,'Prince Valanar - SAY_VALANAR_DEATH'),
(37972,0,0,'Such wondrous power! The Darkfallen Orb has made me INVINCIBLE!',1,16727,0,0,0,0,'Prince Keleseth - SAY_KELESETH_INVOCATION'),
(37972,1,0,'Invocation of Blood jumps to Prince Keleseth!',3,0,0,0,0,0,'Prince Keleseth - EMOTE_KELESETH_INVOCATION'),
(37972,2,0,'Blood will flow!',1,16728,0,0,0,0,'Prince Keleseth - SAY_KELESETH_SPECIAL'),
(37972,3,0,'Were you ever a threat?',1,16723,0,0,0,0,'Prince Keleseth - SAY_KELESETH_KILL_1'),
(37972,3,1,'Truth is found in death.',1,16724,0,0,0,0,'Prince Keleseth - SAY_KELESETH_KILL_2'),
(37972,4,0,'%s cackles maniacally!',2,16726,0,0,0,0,'Prince Keleseth - EMOTE_KELESETH_BERSERK'),
(37972,5,0,'My queen... they come...',1,16725,0,0,0,0,'Prince Keleseth - SAY_KELESETH_DEATH'),
(37973,0,0,'Tremble before Taldaram, mortals, for the power of the orb flows through me!',1,16857,0,0,0,0,'Prince Taldaram - SAY_TALDARAM_INVOCATION'),
(37973,1,0,'Invocation of Blood jumps to Prince Taldaram!',3,0,0,0,0,0,'Prince Taldaram - EMOTE_TALDARAM_INVOCATION'),
(37973,2,0,'Delight in the pain!',1,16858,0,0,0,0,'Prince Taldaram - SAY_TALDARAM_SPECIAL'),
(37973,3,0,'Inferno Flames speed toward $N!',3,0,0,0,0,0,'Prince Taldaram - EMOTE_TALDARAM_FLAME'),
(37973,4,0,'Worm food.',1,16853,0,0,0,0,'Prince Taldaram - SAY_TALDARAM_KILL_1'),
(37973,4,1,'Beg for mercy!',1,16854,0,0,0,0,'Prince Taldaram - SAY_TALDARAM_KILL_2'),
(37973,5,0,'%s laughs.',2,16856,0,0,0,0,'Prince Taldaram - EMOTE_TALDARAM_BERSERK'),
(37973,6,0,'%s gurgles and dies.',2,16855,0,0,0,0,'Prince Taldaram - EMOTE_TALDARAM_DEATH'),
(38004,0,0,'Foolish mortals. You thought us defeated so easily? The San''layn are the Lich King''s immortal soldiers! Now you shall face their might combined!',1,16795,0,0,1,0,'Blood-Queen Lana''thel - SAY_INTRO_1'),
(38004,1,0,'Rise up, brothers, and destroy our enemies.',1,16796,0,0,0,0,'Blood-Queen Lana''thel - SAY_INTRO_2');

DELETE FROM `creature_template_addon` WHERE (`entry`=37122);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (37122, 0, 0, 0, 1, 0, '');
DELETE FROM `creature_template_addon` WHERE (`entry`=37123);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (37123, 0, 0, 0, 0, 0, '');
DELETE FROM `creature_template_addon` WHERE (`entry`=37124);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (37124, 0, 0, 0, 0, 0, '');
DELETE FROM `creature_template_addon` WHERE (`entry`=37125);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (37125, 0, 0, 0, 0, 0, '');
DELETE FROM `creature_template_addon` WHERE (`entry`=37133);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (37133, 0, 0, 0, 0, 0, 71244);
DELETE FROM `creature_template_addon` WHERE (`entry`=37134);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (37134, 0, 0, 0, 0, 0, '');
DELETE FROM `creature_addon` WHERE (`guid`=83235);

DELETE FROM `creature_template_addon` WHERE `entry` IN (36789,38174,37934,37950,38068,37918,37907,38168,38726,38736,37945,38430,38186,38429,37985,38421);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(36789,0,0x0000000,1,0,'72724 70904'),
(38174,0,0x0000000,1,0,'72724 70904'),
(37934,0,0x0000000,1,0,'70749'),
(37950,0,0x3000000,1,0,''),
(38068,0,0x0000000,1,0,'71085'),
(37918,0,0x0000000,1,0,'70715'),
(37907,0,0x0000000,1,0,'72962'),
(38168,0,0x0000000,1,0,'72962'),
(38726,0,0x0000000,1,0,'72962'),
(38736,0,0x0000000,1,0,'72962'),
(37945,0,0x0000000,1,0,'70763'), -- Dream Portal
(38430,0,0x0000000,1,0,'71994'), -- Nightmare Portal
(38186,0,0x0000000,1,0,'71304'), -- Dream Portal (Pre-effect)
(38429,0,0x0000000,1,0,'71986'), -- Nightmare Portal (Pre-effect)
(37985,0,0x3000000,1,0,'70876'), -- Dream Cloud
(38421,0,0x3000000,1,0,'71939 71970'); -- Nightmre Cloud

UPDATE `creature_template` SET `minlevel`=83,`maxlevel`=83,`exp`=2,`unit_class`=1,`faction_A`=1665,`faction_H`=1665,`unit_flags`=`unit_flags`|33554432,`baseattacktime`=2000,`scale`=1,`InhabitType`=7 WHERE `entry`=37950; -- Valithria Dreamwalker
UPDATE `creature_template` SET `minlevel`=60,`maxlevel`=60,`unit_class`=1,`faction_A`=14,`faction_H`=14,`unit_flags`=`unit_flags`|33554432,`baseattacktime`=2000,`flags_extra`=`flags_extra`|128 WHERE `entry`=38068; -- Mana Void
UPDATE `creature_template` SET `minlevel`=60,`maxlevel`=60,`unit_class`=1,`faction_A`=14,`faction_H`=14,`unit_flags`=`unit_flags`|33554432,`baseattacktime`=2000,`flags_extra`=`flags_extra`|128 WHERE `entry`=37918; -- Column of Frost
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`exp`=2,`unit_class`=1,`faction_A`=35,`faction_H`=35,`npcflag`=`npcflag`|16777216 WHERE `entry` IN (37945,38430); -- Dream Portal and Nightmare Portal
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`faction_A`=35,`faction_H`=35,`unit_flags`=`unit_flags`|33554432,`npcflag`=`npcflag`|16777216,`baseattacktime`=2000 WHERE `entry`=38186; -- Dream Portal (Pre-effect)
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`faction_A`=35,`faction_H`=35,`unit_flags`=`unit_flags`|33554432,`npcflag`=`npcflag`|16777216,`baseattacktime`=2000 WHERE `entry`=38429; -- Nightmare Portal (Pre-effect)
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`exp`=2,`unit_class`=1,`faction_A`=2022,`faction_H`=2022,`unit_flags`=`unit_flags`|33554432,`baseattacktime`=2000,`InhabitType`=7,`flags_extra`=`flags_extra`|128 WHERE `entry`=37985; -- Dream Cloud
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`exp`=2,`unit_class`=1,`faction_A`=2022,`faction_H`=2022,`unit_flags`=`unit_flags`|33554432,`baseattacktime`=2000,`InhabitType`=7,`flags_extra`=`flags_extra`|128 WHERE `entry`=38421; -- Nightmare Cloud
UPDATE `creature_template` SET `minlevel`=83,`maxlevel`=83,`exp`=2,`unit_class`=1,`faction_A`=35,`faction_H`=35,`npcflag`=`npcflag`|3,`baseattacktime`=2000,`scale`=1 WHERE `entry`=38589; -- Valithria Dreamwalker (questgiver)

SET @GUID := 200200;
UPDATE `creature` SET `phaseMask`=`phaseMask`|4 WHERE `id`=36789;
-- Add The Lich King and Green Dragon Combat Trigger to all encounter phases, fixes evading when all players enter portals
UPDATE `creature` SET `phaseMask`=`phaseMask`|16 WHERE `id` IN (16980, 38752);

DELETE FROM `creature` WHERE `id` IN (37950,37985,38421) OR `guid` BETWEEN @GUID+00 AND @GUID+27 OR `guid` IN (200230, 200231);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(200230,37950,631,15,20,0,0,4202.847,2484.917,383.8368,0.00000,604800,0,0,0,0,0,0,0,0), -- Valithria Dreamwalker (dream phase)
(200231,22515,631,10,1,0,0,4166.170,2411.520,364.9520,1.57080,120,0,0,0,0,0,0,0,0), -- World Trigger
-- Dream Cloud
(@GUID+00,37985,631,3,16,0,0,4155.51,2478.76,382.494,4.97053,30,10,0,0,0,1,0,0,0),
(@GUID+01,37985,631,3,16,0,0,4158.75,2494.08,384.334,2.31129,30,10,0,0,0,1,0,0,0),
(@GUID+02,37985,631,3,16,0,0,4172.57,2464.47,385.368,3.72021,30,10,0,0,0,1,0,0,0),
(@GUID+03,37985,631,3,16,0,0,4173.67,2504.13,386.174,2.67313,30,10,0,0,0,1,0,0,0),
(@GUID+04,37985,631,3,16,0,0,4181.62,2514.91,386.374,2.65209,30,10,0,0,0,1,0,0,0),
(@GUID+05,37985,631,3,16,0,0,4186.72,2450.97,388.373,4.95968,30,10,0,0,0,1,0,0,0),
(@GUID+06,37985,631,3,16,0,0,4200.96,2456.00,387.128,3.58291,30,10,0,0,0,1,0,0,0),
(@GUID+07,37985,631,3,16,0,0,4202.23,2508.00,383.985,2.09137,30,10,0,0,0,1,0,0,0),
(@GUID+08,37985,631,3,16,0,0,4220.35,2515.16,388.649,2.34469,30,10,0,0,0,1,0,0,0),
(@GUID+09,37985,631,3,16,0,0,4222.26,2455.20,385.568,0.00000,30,10,0,0,0,1,0,0,0),
(@GUID+10,37985,631,3,16,0,0,4231.61,2464.44,389.011,0.00000,30,10,0,0,0,1,0,0,0),
(@GUID+11,37985,631,3,16,0,0,4236.75,2500.62,383.373,5.97527,30,10,0,0,0,1,0,0,0),
(@GUID+12,37985,631,3,16,0,0,4243.29,2476.89,386.076,0.00000,30,10,0,0,0,1,0,0,0),
(@GUID+13,37985,631,3,16,0,0,4244.83,2493.18,387.677,4.29139,30,10,0,0,0,1,0,0,0),
-- Nightmare Cloud
(@GUID+14,38421,631,12,20,0,0,4155.51,2478.76,382.494,4.97053,30,10,0,0,0,1,0,0,0),
(@GUID+15,38421,631,12,20,0,0,4158.75,2494.08,384.334,2.31129,30,10,0,0,0,1,0,0,0),
(@GUID+16,38421,631,12,20,0,0,4172.57,2464.47,385.368,3.72021,30,10,0,0,0,1,0,0,0),
(@GUID+17,38421,631,12,20,0,0,4181.62,2514.91,386.374,2.65209,30,10,0,0,0,1,0,0,0),
(@GUID+18,38421,631,12,20,0,0,4200.96,2456.00,387.128,3.58291,30,10,0,0,0,1,0,0,0),
(@GUID+19,38421,631,12,20,0,0,4202.23,2508.00,383.985,2.09137,30,10,0,0,0,1,0,0,0),
(@GUID+20,38421,631,12,20,0,0,4220.35,2515.16,388.649,2.34469,30,10,0,0,0,1,0,0,0),
(@GUID+21,38421,631,12,20,0,0,4222.26,2455.20,385.568,0.00000,30,10,0,0,0,1,0,0,0),
(@GUID+22,38421,631,12,20,0,0,4236.75,2500.62,383.373,5.97527,30,10,0,0,0,1,0,0,0),
(@GUID+23,38421,631,12,20,0,0,4243.29,2476.89,386.076,0.00000,30,10,0,0,0,1,0,0,0);

-- GUIDs for YTDB!!!
DELETE FROM `linked_respawn` WHERE `guid`=111453 AND `linkType`=0;
INSERT INTO `linked_respawn` (`guid`,`linkedGuid`,`linkType`) VALUES
(111453,10718,0); -- The Lich King link to Green Dragon Combat Trigger

UPDATE `creature` SET `spawntimesecs` = 604800 WHERE `id` IN (37534, 37533, 16980, 38752);

-- Mutated Abomination abilities
UPDATE `creature_template` SET `spell1` = 70360, `spell2` = 70539, `spell3` = 70542, `spell4` = 0, `spell5` = 0, `spell6` = 71516, `spell7` = 0, `spell8` = 0 WHERE `entry` IN (37672, 38605, 38786, 38787);
UPDATE `creature_template` SET `spell1` = 72527, `spell2` = 72457, `spell3` = 70542, `spell4` = 0, `spell5` = 0, `spell6` = 71516, `spell7` = 0, `spell8` = 0 WHERE `entry` IN (38285, 38788, 38789, 38790);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (37945,38430,38186,38429);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES
(37945,70766,0,0,0,3,0,0,0), -- Dream Portal
(38430,70766,0,0,0,3,0,0,0), -- Nightmare Portal
(38186,70766,0,0,0,3,0,0,0), -- Dream Portal (Pre-effect)
(38429,70766,0,0,0,3,0,0,0); -- Nightmare Portal (Pre-effect)

-- Update creature_text to use proper text values
UPDATE `creature_text` SET `type`=12 WHERE `type`=0;
UPDATE `creature_text` SET `type`=14 WHERE `type`=1;
UPDATE `creature_text` SET `type`=16 WHERE `type`=2;
UPDATE `creature_text` SET `type`=41 WHERE `type`=3;
UPDATE `creature_text` SET `type`=15 WHERE `type`=4;
UPDATE `creature_text` SET `type`=42 WHERE `type`=5;


/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software licensed under GPL version 2
* Please see the included DOCS/LICENSE.TXT for more information */

#include "precompiled.h"

//custom

//examples
extern void AddSC_example_creature();
extern void AddSC_example_escort();
extern void AddSC_example_gossip_codebox();
extern void AddSC_example_misc();

//world
extern void AddSC_areatrigger_scripts();
extern void AddSC_boss_emeriss();
extern void AddSC_boss_taerar();
extern void AddSC_boss_ysondre();
extern void AddSC_generic_creature();
extern void AddSC_go_scripts();
extern void AddSC_guards();
extern void AddSC_item_scripts();
extern void AddSC_npc_professions();
extern void AddSC_npcs_special();
extern void AddSC_npc_taxi();

//eastern kingdoms
extern void AddSC_blackrock_depths();               //Blackrock Depths
extern void AddSC_boss_ambassador_flamelash();
extern void AddSC_boss_anubshiah();
extern void AddSC_boss_draganthaurissan();
extern void AddSC_boss_general_angerforge();
extern void AddSC_boss_gorosh_the_dervish();
extern void AddSC_boss_grizzle();
extern void AddSC_boss_high_interrogator_gerstahn();
extern void AddSC_boss_magmus();
extern void AddSC_boss_moira_bronzebeard();
extern void AddSC_boss_tomb_of_seven();
extern void AddSC_instance_blackrock_depths();
extern void AddSC_boss_drakkisath();                //Blackrock Spire
extern void AddSC_boss_halycon();
extern void AddSC_boss_highlordomokk();
extern void AddSC_boss_mothersmolderweb();
extern void AddSC_boss_overlordwyrmthalak();
extern void AddSC_boss_shadowvosh();
extern void AddSC_boss_thebeast();
extern void AddSC_boss_warmastervoone();
extern void AddSC_boss_quatermasterzigris();
extern void AddSC_boss_pyroguard_emberseer();
extern void AddSC_boss_gyth();
extern void AddSC_boss_rend_blackhand();
extern void AddSC_boss_razorgore();                 //Blackwing lair
extern void AddSC_boss_vael();
extern void AddSC_boss_broodlord();
extern void AddSC_boss_firemaw();
extern void AddSC_boss_ebonroc();
extern void AddSC_boss_flamegor();
extern void AddSC_boss_chromaggus();
extern void AddSC_boss_nefarian();
extern void AddSC_boss_victor_nefarius();
extern void AddSC_instance_deadmines();             //Deadmines
extern void AddSC_boss_attumen();                   //Karazhan
extern void AddSC_boss_curator();
extern void AddSC_boss_maiden_of_virtue();
extern void AddSC_boss_shade_of_aran();
extern void AddSC_boss_malchezaar();
extern void AddSC_boss_terestian_illhoof();
extern void AddSC_boss_moroes();
extern void AddSC_bosses_opera();
extern void AddSC_boss_netherspite();
extern void AddSC_instance_karazhan();
extern void AddSC_karazhan();
extern void AddSC_boss_nightbane();
extern void AddSC_boss_felblood_kaelthas();         // Magister's Terrace
extern void AddSC_boss_selin_fireheart();
extern void AddSC_boss_vexallus();
extern void AddSC_boss_priestess_delrissa();
extern void AddSC_instance_magisters_terrace();
extern void AddSC_magisters_terrace();
extern void AddSC_boss_lucifron();                  //Molten core
extern void AddSC_boss_magmadar();
extern void AddSC_boss_gehennas();
extern void AddSC_boss_garr();
extern void AddSC_boss_baron_geddon();
extern void AddSC_boss_shazzrah();
extern void AddSC_boss_golemagg();
extern void AddSC_boss_sulfuron();
extern void AddSC_boss_majordomo();
extern void AddSC_boss_ragnaros();
extern void AddSC_instance_molten_core();
extern void AddSC_molten_core();
extern void AddSC_the_scarlet_enclave();            //Scarlet Enclave
extern void AddSC_the_scarlet_enclave_c1();
extern void AddSC_the_scarlet_enclave_c2();
extern void AddSC_the_scarlet_enclave_c5();
extern void AddSC_boss_arcanist_doan();             //Scarlet Monastery
extern void AddSC_boss_azshir_the_sleepless();
extern void AddSC_boss_bloodmage_thalnos();
extern void AddSC_boss_headless_horseman();
extern void AddSC_boss_herod();
extern void AddSC_boss_high_inquisitor_fairbanks();
extern void AddSC_boss_houndmaster_loksey();
extern void AddSC_boss_interrogator_vishas();
extern void AddSC_boss_scorn();
extern void AddSC_instance_scarlet_monastery();
extern void AddSC_boss_mograine_and_whitemane();
extern void AddSC_boss_darkmaster_gandling();       //Scholomance
extern void AddSC_boss_death_knight_darkreaver();
extern void AddSC_boss_theolenkrastinov();
extern void AddSC_boss_illuciabarov();
extern void AddSC_boss_instructormalicia();
extern void AddSC_boss_jandicebarov();
extern void AddSC_boss_kormok();
extern void AddSC_boss_lordalexeibarov();
extern void AddSC_boss_lorekeeperpolkelt();
extern void AddSC_boss_rasfrost();
extern void AddSC_boss_theravenian();
extern void AddSC_boss_vectus();
extern void AddSC_instance_scholomance();
extern void AddSC_shadowfang_keep();                //Shadowfang keep
extern void AddSC_instance_shadowfang_keep();
extern void AddSC_boss_magistrate_barthilas();      //Stratholme
extern void AddSC_boss_maleki_the_pallid();
extern void AddSC_boss_nerubenkan();
extern void AddSC_boss_cannon_master_willey();
extern void AddSC_boss_baroness_anastari();
extern void AddSC_boss_ramstein_the_gorger();
extern void AddSC_boss_timmy_the_cruel();
extern void AddSC_boss_postmaster_malown();
extern void AddSC_boss_baron_rivendare();
extern void AddSC_boss_dathrohan_balnazzar();
extern void AddSC_boss_order_of_silver_hand();
extern void AddSC_instance_stratholme();
extern void AddSC_stratholme();
extern void AddSC_instance_sunwell_plateau();       //Sunwell Plateau
extern void AddSC_boss_kalecgos();
extern void AddSC_boss_brutallus();
extern void AddSC_boss_felmyst();
extern void AddSC_boss_eredar_twins();
extern void AddSC_boss_muru();
extern void AddSC_boss_kiljaeden();
extern void AddSC_sunwell_plateau();
extern void AddSC_boss_archaedas();                 //Uldaman
extern void AddSC_boss_ironaya();
extern void AddSC_uldaman();
extern void AddSC_instance_uldaman();
extern void AddSC_boss_akilzon();                   //Zul'Aman
extern void AddSC_boss_halazzi();
extern void AddSC_boss_hex_lord_malacrass();
extern void AddSC_boss_janalai();
extern void AddSC_boss_nalorakk();
extern void AddSC_boss_zuljin();
extern void AddSC_instance_zulaman();
extern void AddSC_zulaman();
extern void AddSC_boss_jeklik();                    //Zul'Gurub
extern void AddSC_boss_venoxis();
extern void AddSC_boss_marli();
extern void AddSC_boss_mandokir();
extern void AddSC_boss_gahzranka();
extern void AddSC_boss_thekal();
extern void AddSC_boss_arlokk();
extern void AddSC_boss_jindo();
extern void AddSC_boss_hakkar();
extern void AddSC_boss_grilek();
extern void AddSC_boss_hazzarah();
extern void AddSC_boss_renataki();
extern void AddSC_boss_wushoolay();
extern void AddSC_instance_zulgurub();

//extern void AddSC_alterac_mountains();
extern void AddSC_arathi_highlands();
extern void AddSC_blasted_lands();
extern void AddSC_boss_kruul();
extern void AddSC_burning_steppes();
extern void AddSC_dun_morogh();
extern void AddSC_eastern_plaguelands();
extern void AddSC_elwynn_forest();
extern void AddSC_eversong_woods();
extern void AddSC_ghostlands();
extern void AddSC_hinterlands();
extern void AddSC_ironforge();
extern void AddSC_isle_of_queldanas();
extern void AddSC_loch_modan();
extern void AddSC_searing_gorge();
extern void AddSC_silvermoon_city();
extern void AddSC_silverpine_forest();
extern void AddSC_stormwind_city();
extern void AddSC_stranglethorn_vale();
extern void AddSC_tirisfal_glades();
extern void AddSC_undercity();
extern void AddSC_western_plaguelands();
extern void AddSC_westfall();
extern void AddSC_wetlands();

//kalimdor
extern void AddSC_instance_blackfathom_deeps();     //Blackfathom Depths
extern void AddSC_hyjal();                          //CoT Battle for Mt. Hyjal
extern void AddSC_boss_archimonde();
extern void AddSC_instance_mount_hyjal();
extern void AddSC_hyjal_trash();
extern void AddSC_boss_rage_winterchill();
extern void AddSC_boss_anetheron();
extern void AddSC_boss_kazrogal();
extern void AddSC_boss_azgalor();
extern void AddSC_boss_captain_skarloc();           //CoT Old Hillsbrad
extern void AddSC_boss_epoch_hunter();
extern void AddSC_boss_lieutenant_drake();
extern void AddSC_instance_old_hillsbrad();
extern void AddSC_old_hillsbrad();
extern void AddSC_boss_aeonus();                    //CoT The Dark Portal
extern void AddSC_boss_chrono_lord_deja();
extern void AddSC_boss_temporus();
extern void AddSC_dark_portal();
extern void AddSC_instance_dark_portal();
extern void AddSC_boss_celebras_the_cursed();       //Maraudon
extern void AddSC_boss_landslide();
extern void AddSC_boss_noxxion();
extern void AddSC_boss_ptheradras();
extern void AddSC_boss_onyxia();                    //Onyxia's Lair
extern void AddSC_boss_amnennar_the_coldbringer();  //Razorfen Downs
extern void AddSC_razorfen_downs();
extern void AddSC_razorfen_kraul();                 //Razorfen Kraul
extern void AddSC_boss_cthun();                     //Temple of ahn'qiraj
extern void AddSC_boss_fankriss();
extern void AddSC_boss_huhuran();
extern void AddSC_bug_trio();
extern void AddSC_boss_sartura();
extern void AddSC_boss_skeram();
extern void AddSC_boss_twinemperors();
extern void AddSC_mob_anubisath_sentinel();
extern void AddSC_instance_temple_of_ahnqiraj();
extern void AddSC_wailing_caverns();                //Wailing caverns
extern void AddSC_instance_wailing_caverns();
extern void AddSC_zulfarrak();                      //Zul'Farrak

extern void AddSC_ashenvale();
extern void AddSC_azshara();
extern void AddSC_azuremyst_isle();
extern void AddSC_bloodmyst_isle();
extern void AddSC_boss_azuregos();
extern void AddSC_darkshore();
extern void AddSC_desolace();
extern void AddSC_dustwallow_marsh();
extern void AddSC_felwood();
extern void AddSC_feralas();
extern void AddSC_moonglade();
extern void AddSC_mulgore();
extern void AddSC_orgrimmar();
extern void AddSC_silithus();
extern void AddSC_stonetalon_mountains();
extern void AddSC_tanaris();
extern void AddSC_teldrassil();
extern void AddSC_the_barrens();
extern void AddSC_thousand_needles();
extern void AddSC_thunder_bluff();
extern void AddSC_ungoro_crater();
extern void AddSC_winterspring();

//northrend
extern void AddSC_instance_ahnkahet();          //Azjol-Nerub Ahn'kahet
extern void AddSC_boss_elder_nadox();
extern void AddSC_boss_anubrekhan();            //Naxxramas
extern void AddSC_boss_maexxna();
extern void AddSC_boss_patchwerk();
extern void AddSC_boss_grobbulus();
extern void AddSC_boss_razuvious();
extern void AddSC_boss_kelthuzad();
extern void AddSC_boss_loatheb();
extern void AddSC_boss_noth();
extern void AddSC_boss_gluth();
extern void AddSC_boss_sapphiron();
extern void AddSC_boss_four_horsemen();
extern void AddSC_boss_faerlina();
extern void AddSC_boss_heigan();
extern void AddSC_boss_gothik();
extern void AddSC_boss_thaddius();
extern void AddSC_instance_naxxramas();
extern void AddSC_boss_magus_telestra();        //The Nexus Nexus
extern void AddSC_boss_anomalus();
extern void AddSC_boss_ormorok();
extern void AddSC_boss_keristrasza();
extern void AddSC_instance_nexus();
extern void AddSC_boss_sartharion();            //Obsidian Sanctum
extern void AddSC_instance_obsidian_sanctum();
extern void AddSC_boss_bjarngrim();             //Ulduar Halls of Lightning
extern void AddSC_boss_loken();
extern void AddSC_instance_halls_of_lightning();
extern void AddSC_boss_auriaya();               //Ulduar Ulduar
extern void AddSC_boss_flame_leviathan();
extern void AddSC_boss_ignis();
extern void AddSC_boss_razorscale();
extern void AddSC_boss_xt002();
extern void AddSC_boss_assembly_of_iron();
extern void AddSC_instance_ulduar();
extern void AddSC_boss_keleseth();              //Utgarde Keep
extern void AddSC_boss_skarvald_dalronn();
extern void AddSC_boss_ingvar_the_plunderer();
extern void AddSC_instance_utgarde_keep();
extern void AddSC_utgarde_keep();
extern void AddSC_boss_archavon();              //Vault of Archavon
extern void AddSC_boss_emalon();
extern void AddSC_instance_archavon();

extern void AddSC_borean_tundra();
extern void AddSC_dragonblight();
extern void AddSC_grizzly_hills();
extern void AddSC_icecrown();
extern void AddSC_sholazar_basin();
extern void AddSC_storm_peaks();
extern void AddSC_wintergrasp();
extern void AddSC_zuldrak();

//outland
extern void AddSC_boss_exarch_maladaar();           //Auchindoun Auchenai Crypts
extern void AddSC_boss_shirrak_the_dead_watcher();
extern void AddSC_boss_nexusprince_shaffar();       //Auchindoun Mana Tombs
extern void AddSC_boss_pandemonius();
extern void AddSC_boss_darkweaver_syth();           //Auchindoun Sekketh Halls
extern void AddSC_boss_talon_king_ikiss();
extern void AddSC_instance_sethekk_halls();
extern void AddSC_instance_shadow_labyrinth();      //Auchindoun Shadow Labyrinth
extern void AddSC_boss_ambassador_hellmaw();
extern void AddSC_boss_blackheart_the_inciter();
extern void AddSC_boss_grandmaster_vorpil();
extern void AddSC_boss_murmur();
extern void AddSC_black_temple();                   //Black Temple
extern void AddSC_boss_illidan();
extern void AddSC_boss_shade_of_akama();
extern void AddSC_boss_supremus();
extern void AddSC_boss_gurtogg_bloodboil();
extern void AddSC_boss_mother_shahraz();
extern void AddSC_boss_reliquary_of_souls();
extern void AddSC_boss_teron_gorefiend();
extern void AddSC_boss_najentus();
extern void AddSC_boss_illidari_council();
extern void AddSC_instance_black_temple();
extern void AddSC_boss_fathomlord_karathress();     //CR Serpent Shrine Cavern
extern void AddSC_boss_hydross_the_unstable();
extern void AddSC_boss_lady_vashj();
extern void AddSC_boss_leotheras_the_blind();
extern void AddSC_boss_morogrim_tidewalker();
extern void AddSC_instance_serpentshrine_cavern();
extern void AddSC_boss_the_lurker_below();
extern void AddSC_boss_hydromancer_thespia();       //CR Steam Vault
extern void AddSC_boss_mekgineer_steamrigger();
extern void AddSC_boss_warlord_kalithresh();
extern void AddSC_instance_steam_vault();
extern void AddSC_boss_hungarfen();                 //CR Underbog
extern void AddSC_boss_the_black_stalker();
extern void AddSC_boss_gruul();                     //Gruul's Lair
extern void AddSC_boss_high_king_maulgar();
extern void AddSC_instance_gruuls_lair();
extern void AddSC_boss_broggok();                   //HC Blood Furnace
extern void AddSC_boss_kelidan_the_breaker();
extern void AddSC_boss_the_maker();
extern void AddSC_instance_blood_furnace();
extern void AddSC_boss_magtheridon();               //HC Magtheridon's Lair
extern void AddSC_instance_magtheridons_lair();
extern void AddSC_boss_grand_warlock_nethekurse();  //HC Shattered Halls
extern void AddSC_boss_warbringer_omrogg();
extern void AddSC_boss_warchief_kargath_bladefist();
extern void AddSC_instance_shattered_halls();
extern void AddSC_boss_watchkeeper_gargolmar();     //HC Ramparts
extern void AddSC_boss_omor_the_unscarred();
extern void AddSC_boss_vazruden_the_herald();
extern void AddSC_instance_ramparts();
extern void AddSC_arcatraz();                       //TK Arcatraz
extern void AddSC_boss_harbinger_skyriss();
extern void AddSC_instance_arcatraz();
extern void AddSC_boss_high_botanist_freywinn();    //TK Botanica
extern void AddSC_boss_laj();
extern void AddSC_boss_warp_splinter();
extern void AddSC_boss_alar();                      //TK The Eye
extern void AddSC_boss_kaelthas();
extern void AddSC_boss_void_reaver();
extern void AddSC_boss_high_astromancer_solarian();
extern void AddSC_instance_the_eye();
extern void AddSC_the_eye();
extern void AddSC_boss_gatewatcher_iron_hand();     //TK The Mechanar
extern void AddSC_boss_nethermancer_sepethrea();
extern void AddSC_boss_pathaleon_the_calculator();
extern void AddSC_instance_mechanar();

extern void AddSC_blades_edge_mountains();
extern void AddSC_boss_doomlordkazzak();
extern void AddSC_boss_doomwalker();
extern void AddSC_hellfire_peninsula();
extern void AddSC_nagrand();
extern void AddSC_netherstorm();
extern void AddSC_shadowmoon_valley();
extern void AddSC_shattrath_city();
extern void AddSC_terokkar_forest();
extern void AddSC_zangarmarsh();

void AddScripts()
{
    //custom

    //examples
    AddSC_example_creature();
    AddSC_example_escort();
    AddSC_example_gossip_codebox();
    AddSC_example_misc();

    //world
    AddSC_areatrigger_scripts();
    AddSC_boss_emeriss();
    AddSC_boss_taerar();
    AddSC_boss_ysondre();
    AddSC_generic_creature();
    AddSC_go_scripts();
    AddSC_guards();
    AddSC_item_scripts();
    AddSC_npc_professions();
    AddSC_npcs_special();
    AddSC_npc_taxi();

    //eastern kingdoms
    AddSC_blackrock_depths();               //Blackrock Depths
    AddSC_boss_ambassador_flamelash();
    AddSC_boss_anubshiah();
    AddSC_boss_draganthaurissan();
    AddSC_boss_general_angerforge();
    AddSC_boss_gorosh_the_dervish();
    AddSC_boss_grizzle();
    AddSC_boss_high_interrogator_gerstahn();
    AddSC_boss_magmus();
    AddSC_boss_moira_bronzebeard();
    AddSC_boss_tomb_of_seven();
    AddSC_instance_blackrock_depths();
    AddSC_boss_drakkisath();                //Blackrock Spire
    AddSC_boss_halycon();
    AddSC_boss_highlordomokk();
    AddSC_boss_mothersmolderweb();
    AddSC_boss_overlordwyrmthalak();
    AddSC_boss_shadowvosh();
    AddSC_boss_thebeast();
    AddSC_boss_warmastervoone();
    AddSC_boss_quatermasterzigris();
    AddSC_boss_pyroguard_emberseer();
    AddSC_boss_gyth();
    AddSC_boss_rend_blackhand();
    AddSC_boss_razorgore();                 //Blackwing lair
    AddSC_boss_vael();
    AddSC_boss_broodlord();
    AddSC_boss_firemaw();
    AddSC_boss_ebonroc();
    AddSC_boss_flamegor();
    AddSC_boss_chromaggus();
    AddSC_boss_nefarian();
    AddSC_boss_victor_nefarius();
    AddSC_instance_deadmines();             //Deadmines
    AddSC_boss_attumen();                   //Karazhan
    AddSC_boss_curator();
    AddSC_boss_maiden_of_virtue();
    AddSC_boss_shade_of_aran();
    AddSC_boss_malchezaar();
    AddSC_boss_terestian_illhoof();
    AddSC_boss_moroes();
    AddSC_bosses_opera();
    AddSC_boss_netherspite();
    AddSC_instance_karazhan();
    AddSC_karazhan();
    AddSC_boss_nightbane();
    AddSC_boss_felblood_kaelthas();         // Magister's Terrace
    AddSC_boss_selin_fireheart();
    AddSC_boss_vexallus();
    AddSC_boss_priestess_delrissa();
    AddSC_instance_magisters_terrace();
    AddSC_magisters_terrace();
    AddSC_boss_lucifron();                  //Molten core
    AddSC_boss_magmadar();
    AddSC_boss_gehennas();
    AddSC_boss_garr();
    AddSC_boss_baron_geddon();
    AddSC_boss_shazzrah();
    AddSC_boss_golemagg();
    AddSC_boss_sulfuron();
    AddSC_boss_majordomo();
    AddSC_boss_ragnaros();
    AddSC_instance_molten_core();
    AddSC_molten_core();
    AddSC_the_scarlet_enclave();            //Scarlet Enclave
    AddSC_the_scarlet_enclave_c1();
    AddSC_the_scarlet_enclave_c2();
    AddSC_the_scarlet_enclave_c5();
    AddSC_boss_arcanist_doan();             //Scarlet Monastery
    AddSC_boss_azshir_the_sleepless();
    AddSC_boss_bloodmage_thalnos();
    AddSC_boss_headless_horseman();
    AddSC_boss_herod();
    AddSC_boss_high_inquisitor_fairbanks();
    AddSC_boss_houndmaster_loksey();
    AddSC_boss_interrogator_vishas();
    AddSC_boss_scorn();
    AddSC_instance_scarlet_monastery();
    AddSC_boss_mograine_and_whitemane();
    AddSC_boss_darkmaster_gandling();       //Scholomance
    AddSC_boss_death_knight_darkreaver();
    AddSC_boss_theolenkrastinov();
    AddSC_boss_illuciabarov();
    AddSC_boss_instructormalicia();
    AddSC_boss_jandicebarov();
    AddSC_boss_kormok();
    AddSC_boss_lordalexeibarov();
    AddSC_boss_lorekeeperpolkelt();
    AddSC_boss_rasfrost();
    AddSC_boss_theravenian();
    AddSC_boss_vectus();
    AddSC_instance_scholomance();
    AddSC_shadowfang_keep();                //Shadowfang keep
    AddSC_instance_shadowfang_keep();
    AddSC_boss_magistrate_barthilas();      //Stratholme
    AddSC_boss_maleki_the_pallid();
    AddSC_boss_nerubenkan();
    AddSC_boss_cannon_master_willey();
    AddSC_boss_baroness_anastari();
    AddSC_boss_ramstein_the_gorger();
    AddSC_boss_timmy_the_cruel();
    AddSC_boss_postmaster_malown();
    AddSC_boss_baron_rivendare();
    AddSC_boss_dathrohan_balnazzar();
    AddSC_boss_order_of_silver_hand();
    AddSC_instance_stratholme();
    AddSC_stratholme();
    AddSC_instance_sunwell_plateau();       //Sunwell Plateau
    AddSC_boss_kalecgos();
    AddSC_boss_brutallus();
    AddSC_boss_felmyst();
    AddSC_boss_eredar_twins();
    AddSC_boss_muru();
    AddSC_boss_kiljaeden();
    AddSC_sunwell_plateau();
    AddSC_boss_archaedas();                 //Uldaman
    AddSC_boss_ironaya();
    AddSC_uldaman();
    AddSC_instance_uldaman();
    AddSC_boss_akilzon();                   //Zul'Aman
    AddSC_boss_halazzi();
    AddSC_boss_hex_lord_malacrass();
    AddSC_boss_janalai();
    AddSC_boss_nalorakk();
    AddSC_boss_zuljin();
    AddSC_instance_zulaman();
    AddSC_zulaman();
    AddSC_boss_jeklik();                    //Zul'Gurub
    AddSC_boss_venoxis();
    AddSC_boss_marli();
    AddSC_boss_mandokir();
    AddSC_boss_gahzranka();
    AddSC_boss_thekal();
    AddSC_boss_arlokk();
    AddSC_boss_jindo();
    AddSC_boss_hakkar();
    AddSC_boss_grilek();
    AddSC_boss_hazzarah();
    AddSC_boss_renataki();
    AddSC_boss_wushoolay();
    AddSC_instance_zulgurub();

    //AddSC_alterac_mountains();
    AddSC_arathi_highlands();
    AddSC_blasted_lands();
    AddSC_boss_kruul();
    AddSC_burning_steppes();
    AddSC_dun_morogh();
    AddSC_eastern_plaguelands();
    AddSC_elwynn_forest();
    AddSC_eversong_woods();
    AddSC_ghostlands();
    AddSC_hinterlands();
    AddSC_ironforge();
    AddSC_isle_of_queldanas();
    AddSC_loch_modan();
    AddSC_searing_gorge();
    AddSC_silvermoon_city();
    AddSC_silverpine_forest();
    AddSC_stormwind_city();
    AddSC_stranglethorn_vale();
    AddSC_tirisfal_glades();
    AddSC_undercity();
    AddSC_western_plaguelands();
    AddSC_westfall();
    AddSC_wetlands();

    //kalimdor
    AddSC_instance_blackfathom_deeps();     //Blackfathom Depths
    AddSC_hyjal();                          //CoT Battle for Mt. Hyjal
    AddSC_boss_archimonde();
    AddSC_instance_mount_hyjal();
    AddSC_hyjal_trash();
    AddSC_boss_rage_winterchill();
    AddSC_boss_anetheron();
    AddSC_boss_kazrogal();
    AddSC_boss_azgalor();
    AddSC_boss_captain_skarloc();           //CoT Old Hillsbrad
    AddSC_boss_epoch_hunter();
    AddSC_boss_lieutenant_drake();
    AddSC_instance_old_hillsbrad();
    AddSC_old_hillsbrad();
    AddSC_boss_aeonus();                    //CoT The Dark Portal
    AddSC_boss_chrono_lord_deja();
    AddSC_boss_temporus();
    AddSC_dark_portal();
    AddSC_instance_dark_portal();
    AddSC_boss_celebras_the_cursed();       //Maraudon
    AddSC_boss_landslide();
    AddSC_boss_noxxion();
    AddSC_boss_ptheradras();
    AddSC_boss_onyxia();                    //Onyxia's Lair
    AddSC_boss_amnennar_the_coldbringer();  //Razorfen Downs
    AddSC_razorfen_downs();
    AddSC_razorfen_kraul();                 //Razorfen Kraul
    AddSC_boss_cthun();                     //Temple of ahn'qiraj
    AddSC_boss_fankriss();
    AddSC_boss_huhuran();
    AddSC_bug_trio();
    AddSC_boss_sartura();
    AddSC_boss_skeram();
    AddSC_boss_twinemperors();
    AddSC_mob_anubisath_sentinel();
    AddSC_instance_temple_of_ahnqiraj();
    AddSC_wailing_caverns();                //Wailing caverns
    AddSC_instance_wailing_caverns();
    AddSC_zulfarrak();                      //Zul'Farrak

    AddSC_ashenvale();
    AddSC_azshara();
    AddSC_azuremyst_isle();
    AddSC_bloodmyst_isle();
    AddSC_boss_azuregos();
    AddSC_darkshore();
    AddSC_desolace();
    AddSC_dustwallow_marsh();
    AddSC_felwood();
    AddSC_feralas();
    AddSC_moonglade();
    AddSC_mulgore();
    AddSC_orgrimmar();
    AddSC_silithus();
    AddSC_stonetalon_mountains();
    AddSC_tanaris();
    AddSC_teldrassil();
    AddSC_the_barrens();
    AddSC_thousand_needles();
    AddSC_thunder_bluff();
    AddSC_ungoro_crater();
    AddSC_winterspring();

    //northrend
    AddSC_instance_ahnkahet();          //Azjol-Nerub Ahn'kahet
    AddSC_boss_elder_nadox();
    AddSC_boss_anubrekhan();            //Naxxramas
    AddSC_boss_maexxna();
    AddSC_boss_patchwerk();
    AddSC_boss_grobbulus();
    AddSC_boss_razuvious();
    AddSC_boss_kelthuzad();
    AddSC_boss_loatheb();
    AddSC_boss_noth();
    AddSC_boss_gluth();
    AddSC_boss_sapphiron();
    AddSC_boss_four_horsemen();
    AddSC_boss_faerlina();
    AddSC_boss_heigan();
    AddSC_boss_gothik();
    AddSC_boss_thaddius();
    AddSC_instance_naxxramas();
    AddSC_boss_magus_telestra();        //The Nexus Nexus
    AddSC_boss_anomalus();
    AddSC_boss_ormorok();
    AddSC_boss_keristrasza();
    AddSC_instance_nexus();
    AddSC_boss_sartharion();            //Obsidian Sanctum
    AddSC_instance_obsidian_sanctum();
    AddSC_boss_bjarngrim();             //Ulduar Halls of Lightning
    AddSC_boss_loken();
    AddSC_instance_halls_of_lightning();
    AddSC_boss_auriaya();               //Ulduar Ulduar
    AddSC_boss_flame_leviathan();
    AddSC_boss_ignis();
    AddSC_boss_razorscale();
    AddSC_boss_xt002();
    AddSC_boss_assembly_of_iron();
    AddSC_instance_ulduar();
    AddSC_boss_keleseth();              //Utgarde Keep
    AddSC_boss_skarvald_dalronn();
    AddSC_boss_ingvar_the_plunderer();
    AddSC_instance_utgarde_keep();
    AddSC_utgarde_keep();
    AddSC_boss_archavon();              //Vault of Archavon
    AddSC_boss_emalon();
    AddSC_instance_archavon();

    AddSC_borean_tundra();
    AddSC_dragonblight();
    AddSC_grizzly_hills();
    AddSC_icecrown();
    AddSC_sholazar_basin();
    AddSC_storm_peaks();
    AddSC_wintergrasp();
    AddSC_zuldrak();

    //outland
    AddSC_boss_exarch_maladaar();           //Auchindoun Auchenai Crypts
    AddSC_boss_shirrak_the_dead_watcher();
    AddSC_boss_nexusprince_shaffar();       //Auchindoun Mana Tombs
    AddSC_boss_pandemonius();
    AddSC_boss_darkweaver_syth();           //Auchindoun Sekketh Halls
    AddSC_boss_talon_king_ikiss();
    AddSC_instance_sethekk_halls();
    AddSC_instance_shadow_labyrinth();      //Auchindoun Shadow Labyrinth
    AddSC_boss_ambassador_hellmaw();
    AddSC_boss_blackheart_the_inciter();
    AddSC_boss_grandmaster_vorpil();
    AddSC_boss_murmur();
    AddSC_black_temple();                   //Black Temple
    AddSC_boss_illidan();
    AddSC_boss_shade_of_akama();
    AddSC_boss_supremus();
    AddSC_boss_gurtogg_bloodboil();
    AddSC_boss_mother_shahraz();
    AddSC_boss_reliquary_of_souls();
    AddSC_boss_teron_gorefiend();
    AddSC_boss_najentus();
    AddSC_boss_illidari_council();
    AddSC_instance_black_temple();
    AddSC_boss_fathomlord_karathress();     //CR Serpent Shrine Cavern
    AddSC_boss_hydross_the_unstable();
    AddSC_boss_lady_vashj();
    AddSC_boss_leotheras_the_blind();
    AddSC_boss_morogrim_tidewalker();
    AddSC_instance_serpentshrine_cavern();
    AddSC_boss_the_lurker_below();
    AddSC_boss_hydromancer_thespia();       //CR Steam Vault
    AddSC_boss_mekgineer_steamrigger();
    AddSC_boss_warlord_kalithresh();
    AddSC_instance_steam_vault();
    AddSC_boss_hungarfen();                 //CR Underbog
    AddSC_boss_the_black_stalker();
    AddSC_boss_gruul();                     //Gruul's Lair
    AddSC_boss_high_king_maulgar();
    AddSC_instance_gruuls_lair();
    AddSC_boss_broggok();                   //HC Blood Furnace
    AddSC_boss_kelidan_the_breaker();
    AddSC_boss_the_maker();
    AddSC_instance_blood_furnace();
    AddSC_boss_magtheridon();               //HC Magtheridon's Lair
    AddSC_instance_magtheridons_lair();
    AddSC_boss_grand_warlock_nethekurse();  //HC Shattered Halls
    AddSC_boss_warbringer_omrogg();
    AddSC_boss_warchief_kargath_bladefist();
    AddSC_instance_shattered_halls();
    AddSC_boss_watchkeeper_gargolmar();     //HC Ramparts
    AddSC_boss_omor_the_unscarred();
    AddSC_boss_vazruden_the_herald();
    AddSC_instance_ramparts();
    AddSC_arcatraz();                       //TK Arcatraz
    AddSC_boss_harbinger_skyriss();
    AddSC_instance_arcatraz();
    AddSC_boss_high_botanist_freywinn();    //TK Botanica
    AddSC_boss_laj();
    AddSC_boss_warp_splinter();
    AddSC_boss_alar();                      //TK The Eye
    AddSC_boss_kaelthas();
    AddSC_boss_void_reaver();
    AddSC_boss_high_astromancer_solarian();
    AddSC_instance_the_eye();
    AddSC_the_eye();
    AddSC_boss_gatewatcher_iron_hand();     //TK The Mechanar
    AddSC_boss_nethermancer_sepethrea();
    AddSC_boss_pathaleon_the_calculator();
    AddSC_instance_mechanar();

    AddSC_blades_edge_mountains();
    AddSC_boss_doomlordkazzak();
    AddSC_boss_doomwalker();
    AddSC_hellfire_peninsula();
    AddSC_nagrand();
    AddSC_netherstorm();
    AddSC_shadowmoon_valley();
    AddSC_shattrath_city();
    AddSC_terokkar_forest();
    AddSC_zangarmarsh();
}

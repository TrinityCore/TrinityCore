--
SET @CGUID = 87530; -- creature GUIDs (14 creatures)

SET @IMMUNEMASK = (1|2|4|16|32|64|128|256|512|2048|4096|8192|65536|131072|524288|4194304|8388608|67108864|536870912);
-- Correct immunity mask (all bosses)
UPDATE `creature_template` SET `mechanic_immune_mask` = @IMMUNEMASK WHERE `entry` IN (28684,31612);
UPDATE `creature_template` SET `mechanic_immune_mask` = (@IMMUNEMASK|33554432) WHERE `entry` IN (28921,29120,31611,31610);

-- ------------------------- --
-- Krik'thir the Gatewatcher --
-- ------------------------- --
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (52438,52449,52343);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`Comment`) VALUES
(13,1,52438,0,0,31,0,3,22515,0,0,"Summon Skittering Swarmer - Target World Trigger"),
(13,1,52449,0,0,31,0,3,22515,0,0,"Summon Skittering Infector - Target World Trigger"),
(13,1,52343,0,0,31,0,3,28729,0,0,"Krik'thir Subboss Aggro Trigger - Target Watcher Narjil"),
(13,1,52343,0,1,31,0,3,28730,0,0,"Krik'thir Subboss Aggro Trigger - Target Watcher Garsha"),
(13,1,52343,0,2,31,0,3,28731,0,0,"Krik'thir Subboss Aggro Trigger - Target Watcher Silthik");

-- Remove static spawn for Krik'thir's pets
DELETE FROM `creature` WHERE `guid` IN (127234,127232,127227,127226,127231,127226,127225,127228,127233,127236);
DELETE FROM `creature_addon` WHERE `guid` IN (127234,127232,127227,127226,127231,127226,127225,127228,127233,127236);
DELETE FROM `linked_respawn` WHERE `guid` IN (127234,127232,127227,127226,127231,127226,127225,127228,127233,127236);
-- And replace it with creature_summon_groups which allows us to easily respawn them on demand
DELETE FROM `creature_summon_groups` WHERE `summonerId`=28684 AND `summonerType`=0;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(28684,0,1,28729,511.8097,666.4934,776.2781,0.9773844,6,45000),
(28684,0,1,28732,506.5164,664.3796,776.9759,0.9250245,6,30000),
(28684,0,1,28733,506.1783,669.9266,776.3057,0.8552113,6,30000),
(28684,0,2,28730,526.6636,663.6053,775.8052,1.239184 ,6,45000),
(28684,0,2,28732,531.0308,658.1731,776.2396,1.343904 ,6,30000),
(28684,0,2,28734,521.8148,659.4708,776.3131,1.186824 ,6,30000),
(28684,0,3,28731,543.8261,665.1234,776.2453,1.553343 ,6,45000),
(28684,0,3,28734,550.0461,668.131 ,776.2789,1.658063 ,6,30000),
(28684,0,3,28733,549.6929,662.0067,776.9927,1.64061  ,6,30000);

-- Small minions are now owned by the World Triggers in the room, so they need AI to aggro properly
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_skittering_swarmer" WHERE `entry`=28735;
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_skittering_infector" WHERE `entry`=28736;

-- Krik'thir: Subboss Aggro Trigger
DELETE FROM `spell_script_names` WHERE `scriptname` = "spell_gatewatcher_subboss_trigger";
INSERT INTO `spell_script_names` (`spell_id`,`scriptname`) VALUES (52343,"spell_gatewatcher_subboss_trigger");

-- Anub'ar Skirmisher: Fixtate
DELETE FROM `spell_script_names` WHERE `scriptname` = "spell_anub_ar_skirmisher_fixtate";
INSERT INTO `spell_script_names` (`spell_id`,`scriptname`) VALUES (52536,"spell_anub_ar_skirmisher_fixtate");

-- Watchers: Web Wrap 
DELETE FROM `spell_script_names` WHERE `scriptname` = "spell_gatewatcher_web_wrap";
INSERT INTO `spell_script_names` (`spell_id`,`scriptname`) VALUES (52086,"spell_gatewatcher_web_wrap");
UPDATE `creature_template` SET `AIName`='',`ScriptName`="npc_gatewatcher_web_wrap" WHERE `entry`=28619;

-- -------- --
-- Hadronox --
-- -------- --
UPDATE `creature` SET `position_x`=515.5848,`position_y`=544.2007,`position_z`=673.6272,`orientation`=5.740286 WHERE `map`=601 AND `id`=28921;
-- Remove existing world trigger spawns
DELETE FROM `creature` WHERE `guid` BETWEEN 127376 AND 127378;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN 127376 AND 127378;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
-- And re-spawn them
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`movementtype`) VALUES
(@CGUID+00,23472,601,3,1,530.495 ,597.0955,777.2634,5.986479 ,0,0,0),
(@CGUID+01,23472,601,3,1,530.6029,596.997 ,777.2633,5.427974 ,0,0,0),
(@CGUID+02,23472,601,3,1,530.7466,596.745 ,777.2631,2.303835 ,0,0,0),
(@CGUID+03,23472,601,3,1,583.0908,617.371 ,771.5508,0.6457718,0,0,0),
(@CGUID+04,23472,601,3,1,480.0325,615.5892,773.3531,4.101524 ,0,0,0),
(@CGUID+05,23472,601,3,1,581.4475,608.8407,739.4051,1.727876 ,0,0,0);
INSERT INTO `creature_addon` (`guid`,`auras`) VALUES
(@CGUID+03,"53035 53036 53037"),
(@CGUID+04,"53035 53036 53037"),
(@CGUID+05,"53035 53036 53037");
-- Crusher groups are now spawn groups on Hadronox
DELETE FROM `creature` WHERE `guid` IN (127379,127380,127402);
DELETE FROM `creature_addon` WHERE `guid` IN (127379,127380,127402);
DELETE FROM `linked_respawn` WHERE `guid` IN (127379,127380,127402);
DELETE FROM `creature_summon_groups` WHERE `summonerId`=28921 AND `summonerType`=0;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(28921,0,1,28922,529.6913,547.1257,731.9155,4.79965 ,6,45000),
(28921,0,1,29117,539.2076,549.7539,732.8668,4.55531 ,6,30000),
(28921,0,1,29118,520.3911,548.7895,732.0118,5.0091  ,6,30000),
(28921,0,2,28922,493.4772,603.3438,760.5628,5.440244,6,45000),
(28921,0,2,29117,490.4421,604.335 ,763.1821,5.625595,6,30000),
(28921,0,2,29119,488.8254,609.2819,767.5876,5.590288,6,30000),
(28921,0,3,28922,566.9789,602.5711,759.6418,3.885966,6,45000),
(28921,0,3,29118,569.348 ,604.9987,763.2137,4.179827,6,30000),
(28921,0,3,29119,572.4737,607.4109,767.1777,3.944169,6,30000);
-- Periodic spawn triggers: Spell scripts
DELETE FROM `spell_script_names` WHERE `scriptname` IN ("spell_hadronox_periodic_summon_champion","spell_hadronox_periodic_summon_crypt_fiend","spell_hadronox_periodic_summon_necromancer");
INSERT INTO `spell_script_names` (`spell_id`,`scriptname`) VALUES
(53035,"spell_hadronox_periodic_summon_champion"),
(53037,"spell_hadronox_periodic_summon_crypt_fiend"),
(53036,"spell_hadronox_periodic_summon_necromancer");
-- Assign custom AI to the Anub'ar foes
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (29062,29063,29064,29096,29097,29098);
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_anub_ar_champion" WHERE `entry` IN (29062,29096);
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_anub_ar_crypt_fiend" WHERE `entry` IN (29063,29097);
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_anub_ar_necromancer" WHERE `entry` IN (29064,29098);
-- And crusher pack creatures
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (28922,29117,29118,29119);
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_anub_ar_crusher" WHERE `entry` = 28922;
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_anub_ar_crusher_champion" WHERE `entry` = 29117;
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_anub_ar_crusher_crypt_fiend" WHERE `entry` = 29118;
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_anub_ar_crusher_necromancer" WHERE `entry` = 29119;
-- Hadronox: Leeching Poison
DELETE FROM `spell_script_names` WHERE `scriptname` = "spell_hadronox_leeching_poison";
INSERT INTO `spell_script_names` (`spell_id`,`scriptname`) VALUES (53030,"spell_hadronox_leeching_poison"),(59417,"spell_hadronox_leeching_poison");
-- Hadronox: Web Side Doors / Web Front Doors
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (53177,53185);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionTarget`,`ElseGroup`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`Comment`) VALUES
(13,1,53177,31,0,0,3,23472,@CGUID+3,"Web Front Door - Target Large AOI World Trigger Top Door 1"),
(13,1,53177,31,0,1,3,23472,@CGUID+4,"Web Front Door - Target Large AOI World Trigger Top Door 2"),
(13,1,53185,31,0,0,3,23472,@CGUID+5,"Web Side Door - Target Large AOI World Trigger Side Door");
DELETE FROM `spell_script_names` WHERE `scriptname`="spell_hadronox_web_doors";
INSERT INTO `spell_script_names` (`spell_id`,`scriptname`) VALUES
(53177,"spell_hadronox_web_doors"),
(53185,"spell_hadronox_web_doors");
-- Spell difficulty data
DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (53406,57731,53318);
INSERT INTO `spelldifficulty_dbc` (`id`,`spellid0`,`spellid1`) VALUES
(53406,53406,59420), -- Hadronox - Web Grab
(53318,53318,59346); -- Crusher - Smash
-- Creature texts
DELETE FROM `creature_text` WHERE `entry` IN (28921,28922);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`probability`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(28921,1,0,"%s moves up the tunnel!",41,100,0,29852,3,"Hadronox HADRONOX_EMOTE_MOVE"),
(28922,1,0,"The gate has been breached! Quickly, divert forces to deal with these invaders!",14,100,13941,29473,3,"Anub'ar Crusher CRUSHER_SAY_AGGRO"),
(28922,2,0,"%s goes into a frenzy!",41,100,0,10645,3,"Anub'ar Crusher CRUSHER_EMOTE_FRENZY");
-- Achievement: Hadronox Denied
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=4244;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`ScriptName`) VALUES
(4244,11,"achievement_hadronox_denied");
DELETE FROM `disables` WHERE `sourceType`=4 AND `entry`=4244;

-- --------- --
-- Anub'arak --
-- --------- --
-- Pound
DELETE FROM `spell_script_names` WHERE `scriptname`="spell_anubarak_pound";
INSERT INTO `spell_script_names` (`spell_id`,`scriptname`) VALUES
(53472,"spell_anubarak_pound"),
(59433,"spell_anubarak_pound");
-- Summon Carrion Beetles
DELETE FROM `spell_script_names` WHERE `scriptname`="spell_anubarak_carrion_beetles";
INSERT INTO `spell_script_names` (`spell_id`,`scriptname`) VALUES
(53520,"spell_anubarak_carrion_beetles");
-- New pet AI
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (29213,29214,29216,29217,29184);
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_anubarak_anub_ar_darter" WHERE `entry` = 29213;
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_anubarak_anub_ar_assassin" WHERE `entry` = 29214;
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_anubarak_anub_ar_guardian" WHERE `entry` = 29216;
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_anubarak_anub_ar_venomancer" WHERE `entry` = 29217;
-- Impale
UPDATE `creature_template` SET `AIName`="",`ScriptName`="npc_anubarak_impale_target" WHERE `entry`=29184;
-- World triggers for Assassin spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+06 AND @CGUID+13;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`movementtype`) VALUES
(@CGUID+06,22515,601,3,1,478.7393,252.8498,250.5435,0.05235988,0,0,0),
(@CGUID+07,22515,601,3,1,621.319 ,268.4819,250.5435,3.333579  ,0,0,0),
(@CGUID+08,22515,601,3,1,622.9042,252.945 ,250.5435,3.124139  ,0,0,0),
(@CGUID+09,22515,601,3,1,478.1486,269.0094,250.5435,6.126106  ,0,0,0),
(@CGUID+10,22515,601,3,1,478.5473,297.0447,250.5435,5.7944933 ,0,0,0),
(@CGUID+11,22515,601,3,1,478.2909,224.8265,250.2346,0.4014257 ,0,0,0),
(@CGUID+12,22515,601,3,1,620.6218,298.2625,250.5435,3.700098  ,0,0,0),
(@CGUID+13,22515,601,3,1,620.7037,224.5618,250.2321,2.530727  ,0,0,0);
-- Guardian spawn trigger
DELETE FROM `creature_summon_groups` WHERE `summonerId`=29120 AND `summonerType`=0;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(29120,0,1,22515,549.6223,352.0468,240.899,3.455752,8,0);
-- Targeting info for Assassin spawns
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=53609;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionTarget`,`ElseGroup`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`Comment`) VALUES
(13,1,53609,31,0,0,3,22515,@CGUID+06,"Summon Anub'ar Assassin - Target World Trigger"),
(13,1,53609,31,0,1,3,22515,@CGUID+07,"Summon Anub'ar Assassin - Target World Trigger"),
(13,1,53609,31,0,2,3,22515,@CGUID+08,"Summon Anub'ar Assassin - Target World Trigger"),
(13,1,53609,31,0,3,3,22515,@CGUID+09,"Summon Anub'ar Assassin - Target World Trigger"),
(13,1,53609,31,0,4,3,22515,@CGUID+10,"Summon Anub'ar Assassin - Target World Trigger"),
(13,1,53609,31,0,5,3,22515,@CGUID+11,"Summon Anub'ar Assassin - Target World Trigger"),
(13,1,53609,31,0,6,3,22515,@CGUID+12,"Summon Anub'ar Assassin - Target World Trigger"),
(13,1,53609,31,0,7,3,22515,@CGUID+13,"Summon Anub'ar Assassin - Target World Trigger");
-- Difficulty data
DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (53454,53472,53509);
INSERT INTO `spelldifficulty_dbc` (`id`,`spellid0`,`spellid1`) VALUES
(53454,53454,59446), -- Anub'arak: Impale
(53472,53472,59433), -- Anub'arak: Pound (Stun)
(53509,53509,59432); -- Anub'arak: Pound (Damage)
